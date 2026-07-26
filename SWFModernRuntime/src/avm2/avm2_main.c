// runSWF_avm2() — AVM2 entry point, mirroring swf_core.c::runSWF's tick
// cadence and MAX_FRAMES exit condition, with the AVM2 load ordering from
// avm2-support-plan §4.4 (Ruffle movie_clip.rs:4246-4255):
//
//   1. load ALL ABC files (register scripts/classes; run NO script inits)
//   2. process ALL SymbolClass bindings
//   3. eager-init each ABC's LAST script (the main/root script)
//   4. construct the SymbolClass char-0 (root) class instance
//   5. per-tick: run registered frame scripts
//
// Each top-level entry (script init, root construction, frame script) runs
// under a catch-all try frame: an uncaught AVM2 error aborts that entry
// only (logged to stderr) and the movie keeps running, matching
// Flash/Ruffle.
//
// swf_core.c is not referenced from here and never references this file;
// the shared wasm_wrappers/main.c picks runSWF_avm2 over swfStart only
// under -DSWF_AVM2 (defined by verify_output.py for avm2 tests).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <memory/heap.h>

#include <audio/audio.h>

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_gc.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

#if defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)
#include <emscripten.h>
#include <libswf/swf.h>   // full SWFAppContext (ctx->app->fps) for the browser loop
// Reuse swf.c's in-browser perf HUD (published to window.__swfPerf, read by
// demo.html's HUD + the Windows perf probe). swf.c is linked in every AVM2
// graphics build (it owns the RenderContext* the render walk drives), so the
// symbol is available; the AVM2 loop just feeds it AVM2 frame timings. Returns
// nonzero when the "Uncapped" benchmark toggle is on (skip the pacing sleep).
extern int swf_perf_report(double elapsed_ms, double budget_ms, double present_ms,
                           int live_obj, int live_arr);
extern int avm2_render_present(Avm2Context* ctx);
#endif

static Avm2Context g_avm2_ctx;

Avm2Context* avm2_get_context(void)
{
	return &g_avm2_ctx;
}

void* avm2_alloc(Avm2Context* ctx, uint32_t size)
{
	// o1heap refuses zero-size requests; empty tables (an ABC with no
	// classes) are legal and want a unique non-NULL pointer.
	void* p = heap_alloc(ctx->app, size > 0 ? size : 1);
	if (p == NULL)
	{
		avm2_fatal("out of memory allocating %u bytes", size);
	}
	avm2_gc_note_alloc(size > 0 ? size : 1);
	return p;
}

// Mark a class's structural roots: its class object + prototype object, and
// the objects captured in its scope chains. The class/instance scope chains
// (cls->scope / cls->iscope) and each method's captured method_scope are
// referenced by every method activation's `outer` chain but are otherwise
// invisible to the collector — a scope entry object that is neither a rooted
// global nor a pinned class object (e.g. a with-scope object or a nested
// capture) would be swept, and the next scope walk (scope_defines_mn) would
// dereference a freed vtable. Trace them.
static void mark_class_roots(Avm2Class* cls)
{
	if (cls == NULL) return;
	avm2_gc_mark_object(cls->class_object);
	avm2_gc_mark_object(cls->prototype_obj);
	avm2_gc_mark_scope(cls->scope);
	avm2_gc_mark_scope(cls->iscope);
	for (uint32_t i = 0; i < cls->ivtable.count; i++)
	{
		avm2_gc_mark_scope(cls->ivtable.entries[i].method_scope);
	}
	for (uint32_t i = 0; i < cls->ivtable.meta_cap; i++)
	{
		if (cls->ivtable.metas != NULL && cls->ivtable.metas[i].used)
			avm2_gc_mark_scope(cls->ivtable.metas[i].method_scope);
	}
}

// AVM2 GC root marker for this module (avm2_gc.c invokes it each cycle).
// Roots: the context singletons (root/stage/builtin globals), every script's
// globals object, and every realized class's structural roots (class object,
// prototype, scope chains — see mark_class_roots). Classes are kept immortal —
// the win is in per-frame instances, not the structural class/vtable/prototype
// world (see avm2_gc.h). The builtins struct is entirely Avm2Class* fields, so
// it walks as an array.
void avm2_gc_mark_roots_main(Avm2Context* ctx)
{
	avm2_gc_mark_object(ctx->root);
	avm2_gc_mark_object(ctx->stage);
	avm2_gc_mark_object(ctx->builtin_globals);
	// Default XML namespace: DxnsLate can leave a heap string here.
	avm2_gc_mark_string(ctx->dxns);

	Avm2Class** b = (Avm2Class**) &ctx->builtins;
	uint32_t nb = (uint32_t) (sizeof(Avm2Builtins) / sizeof(Avm2Class*));
	for (uint32_t i = 0; i < nb; i++) mark_class_roots(b[i]);

	for (uint32_t f = 0; f < ctx->file_count; f++)
	{
		Avm2AbcFileRt* file = ctx->files[f];
		if (file == NULL) continue;
		if (file->script_globals != NULL)
		{
			for (uint32_t s = 0; s < file->data->script_count; s++)
			{
				avm2_gc_mark_object(file->script_globals[s]);
			}
		}
		if (file->classes != NULL)
		{
			for (uint32_t c = 0; c < file->data->class_count; c++)
			{
				mark_class_roots(file->classes[c]);
			}
		}
	}
}

// ---------------------------------------------------------------------------
// ABC load (step 1)
// ---------------------------------------------------------------------------

static Avm2AbcFileRt* avm2_abc_load(Avm2Context* ctx, const Avm2AbcFileData* data)
{
	Avm2AbcFileRt* file = avm2_alloc(ctx, sizeof(Avm2AbcFileRt));
	memset(file, 0, sizeof(Avm2AbcFileRt));
	file->data = data;
	file->ctx = ctx;
	file->script_globals = avm2_alloc(ctx, data->script_count * sizeof(Avm2Object*));
	file->script_init_state = avm2_alloc(ctx, data->script_count);
	memset(file->script_init_state, AVM2_SCRIPT_UNINITIALIZED, data->script_count);
	file->classes = avm2_alloc(ctx, data->class_count * sizeof(Avm2Class*));
	memset(file->classes, 0, data->class_count * sizeof(Avm2Class*));
#ifndef SWF_NO_CLASS_MEMO
	file->coerce_class_memo =
		avm2_alloc(ctx, data->multiname_count * sizeof(Avm2Class*));
	memset(file->coerce_class_memo, 0,
	       data->multiname_count * sizeof(Avm2Class*));
#endif

	for (uint32_t si = 0; si < data->script_count; si++)
	{
		const Avm2AbcScriptData* sd = &data->scripts[si];

		// Script globals: a ScriptObject whose declared traits come from
		// the script's trait table. Script-level methods capture a scope
		// chain of just [globals].
		Avm2Object* globals = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);
		globals->cls = ctx->builtins.global_class;
		globals->proto = ctx->builtins.object_class->prototype_obj;
		Avm2ScopeEntry scope_entry = { globals, 0 };
		Avm2ScopeChain* script_scope =
			avm2_scope_capture(ctx, NULL, &scope_entry, 1);
		Avm2VTable* vt = avm2_alloc(ctx, sizeof(Avm2VTable));
		memset(vt, 0, sizeof(Avm2VTable));
		avm2_vtable_add_traits(ctx, vt, file, sd->traits, sd->trait_count,
		                       NULL, script_scope);
		globals->vtable = vt;
		globals->slot_count = vt->slot_count + 1;
		if (globals->slot_count > 0)
		{
			globals->slots = avm2_alloc(ctx, globals->slot_count * sizeof(Avm2Value));
			for (uint32_t i = 0; i < globals->slot_count; i++)
			{
				globals->slots[i] = avm2_undefined();
			}
			avm2_slots_init_defaults(ctx, globals, vt);
		}
		file->script_globals[si] = globals;

		// Register every script trait name in the domain so FindPropStrict
		// from other scripts can trigger this script's lazy init.
		for (uint32_t ti = 0; ti < sd->trait_count; ti++)
		{
			Avm2PropKey key;
			if (avm2_propkey_from_qname(data, sd->traits[ti].name_mn, &key))
			{
				avm2_domain_add(ctx, &key, file, si);
			}
		}
	}
	return file;
}

// ---------------------------------------------------------------------------
// Root binding (steps 2 + 4)
// ---------------------------------------------------------------------------

// SymbolClass names are dotted ("test_fla.MainTimeline"): package = text
// before the last '.', local name after (Ruffle parses the same way).
static Avm2Object* find_root_class_globals(Avm2Context* ctx, const char* dotted,
                                           Avm2PropKey* out_key)
{
	const char* last_dot = strrchr(dotted, '.');
	Avm2PropKey key;
	key.ns_kind = 0x16;
	if (last_dot != NULL)
	{
		key.ns_uri = dotted;
		key.ns_len = (uint32_t) (last_dot - dotted);
		key.name = last_dot + 1;
	}
	else
	{
		key.ns_uri = "";
		key.ns_len = 0;
		key.name = dotted;
	}
	key.name_len = (uint32_t) strlen(key.name);
	*out_key = key;
	return avm2_domain_find(ctx, &key);
}

// ---------------------------------------------------------------------------
// Entry
// ---------------------------------------------------------------------------

void runSWF_avm2(SWFAppContext* app_context)
{
	printf("=== SWF Execution Started (AVM2, NO_GRAPHICS mode) ===\n");

	if (!heap_init(app_context, 0))
	{
		fprintf(stderr, "Failed to initialize heap allocator\n");
		return;
	}

	Avm2Context* ctx = &g_avm2_ctx;
	memset(ctx, 0, sizeof(*ctx));
	ctx->app = app_context;
	ctx->swf_version = avm2_generated_swf_version;
	// Snapshot the C stack here, before any script can run: everything below
	// this point is measured against it (avm2_stack_check → Error #1023).
	avm2_stack_guard_init(ctx);

	avm2_globals_init(ctx);

#ifndef NO_GRAPHICS
	// Real audio output: in the browser create the Web Audio sink FIRST —
	// before renderer init AND before any script runs — while the user
	// gesture (the demo's click handler called runSWF) is still active;
	// renderer_init's emscripten_sleep would consume it (same ordering rule
	// as swf.c, see the web-audio notes). Then register every embedded
	// DefineSound payload with the shared mixer so Sound.play() from ANY
	// entry point (script init, root ctor, frame script) finds its asset.
	// Native graphics builds register too (exercises the bridge in CI) but
	// stay silent: nothing pulls audio_mix outside the browser.
#if defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)
	if (app_context->audio_ctx == NULL) audio_init(app_context);
	audio_output_init(app_context);
#endif
	avm2_media_register_sounds(ctx);
#endif

	// Step 1: load all ABC files — no script inits yet.
	ctx->file_count = avm2_generated_abc_file_count;
	ctx->files = avm2_alloc(ctx, ctx->file_count * sizeof(Avm2AbcFileRt*));
	for (uint32_t i = 0; i < ctx->file_count; i++)
	{
		ctx->files[i] = avm2_abc_load(ctx, avm2_generated_abc_files[i]);
	}

	// Step 2: SymbolClass bindings were recorded by the recompiler; the
	// root binding (char 0) is consumed in step 4. Non-root bindings are
	// Stage 5 (timeline instantiation).
	const char* root_class = NULL;
	for (uint32_t i = 0; i < avm2_generated_symbol_class_count; i++)
	{
		if (avm2_generated_symbol_classes[i].char_id == 0)
		{
			root_class = avm2_generated_symbol_classes[i].class_name;
		}
	}

	// Step 3: eager-init each ABC's LAST script (the main/root script);
	// all other scripts stay lazy (Ruffle movie_clip.rs:4246-4255). An
	// uncaught error aborts that script only.
	for (uint32_t i = 0; i < ctx->file_count; i++)
	{
		if (ctx->files[i]->data->script_count > 0)
		{
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				avm2_script_ensure_init(ctx->files[i],
				                        ctx->files[i]->data->script_count - 1);
			}
			avm2_try_pop_frame(&top);
		}
	}

	// Step 4: build the display tree (stage + root). The root's class
	// constructor runs during the first tick's Construct phase, matching
	// Ruffle's frame lifecycle.
	if (root_class != NULL)
	{
		Avm2TryFrame top;
		avm2_try_push_catch_all(ctx, &top);
		if (setjmp(top.jb) == 0)
		{
			avm2_display_build_stage(ctx, root_class);
		}
		avm2_try_pop_frame(&top);
	}
	else
	{
		// No char-0 binding: bindings whose characters ARE placed on a
		// timeline now construct through real timeline instantiation
		// (build_stage below). Bindings to never-placed characters keep
		// the pre-display construct-once behavior (the single-frame
		// test-movie pattern several Stage-2 baseline tests rely on).
		// Best-effort: a binding whose defining script aborted is skipped.
		for (uint32_t i = 0; i < avm2_generated_symbol_class_count; i++)
		{
			const char* cname = avm2_generated_symbol_classes[i].class_name;
			if (cname == NULL) continue;
			uint16_t cid = avm2_generated_symbol_classes[i].char_id;
			int placed = 0;
			for (uint32_t t = 0; t < avm2_generated_timeline_count && !placed; t++)
			{
				const Avm2TimelineData* tl = &avm2_generated_timelines[t];
				uint32_t nops = tl->frame_op_starts[tl->frame_count];
				for (uint32_t o = 0; o < nops; o++)
				{
					if ((tl->ops[o].flags & 1 /* HAS_CHAR */)
					    && tl->ops[o].char_id == cid)
					{
						placed = 1;
						break;
					}
				}
			}
			for (uint32_t b = 0; b < avm2_generated_button_count && !placed; b++)
			{
				for (uint32_t r = 0; r < avm2_generated_buttons[b].record_count; r++)
				{
					if (avm2_generated_buttons[b].records[r].char_id == cid)
					{
						placed = 1;
						break;
					}
				}
			}
			if (placed) continue;
			Avm2PropKey key;
			Avm2Object* globals = find_root_class_globals(ctx, cname, &key);
			if (globals == NULL) continue;
			const Avm2PropEntry* entry = avm2_vtable_find(globals->vtable, &key);
			Avm2Value cls_val = avm2_undefined();
			if (entry != NULL && entry->kind == AVM2_PROP_SLOT)
			{
				cls_val = globals->slots[entry->slot_index];
			}
			else
			{
				Avm2Value* dyn = avm2_object_find_dynamic(globals, key.name,
				                                          key.name_len);
				if (dyn != NULL) cls_val = *dyn;
			}
			if (cls_val.kind != AVM2_VALUE_OBJECT || cls_val.u.obj == NULL
			    || cls_val.u.obj->kind != AVM2_OBJ_CLASS)
			{
				continue;
			}
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				Avm2Value root = avm2_class_construct(
					ctx, cls_val.u.obj->class_ref, NULL, 0);
				ctx->root = root.u.obj;
			}
			avm2_try_pop_frame(&top);
		}
		{
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				avm2_display_build_stage(ctx, NULL);
			}
			avm2_try_pop_frame(&top);
		}
	}

	// GPU-free CPU-composite frame dump (avm2_display.c) — env-gated, compiled
	// in every build. Declared unconditionally (the tick loop calls it always).
	extern void avm2_cpu_dump_frame(Avm2Context* ctx, int frame_index);

	// Stage 9 / Stage 13a: minimal AVM2 render path. In graphics builds the
	// WebGPU backend is linked but runSWF_avm2 never drove it; set it up now
	// (after heap_init + build_stage). Two sinks share avm2_render_init: the
	// OFFSCREEN_RENDER PNG-capture path (native test mode) and the browser
	// canvas swapchain (Stage 13a). NO_GRAPHICS builds skip this entirely.
#if defined(OFFSCREEN_RENDER) || (defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS))
	extern void avm2_render_init(Avm2Context* ctx);
	{
		Avm2TryFrame top;
		avm2_try_push_catch_all(ctx, &top);
		if (setjmp(top.jb) == 0)
		{
			avm2_render_init(ctx);
		}
		avm2_try_pop_frame(&top);
	}
#endif
#ifdef OFFSCREEN_RENDER
	extern void avm2_render_frame(Avm2Context* ctx);
	extern void avm2_render_finish(Avm2Context* ctx);
#endif

	// Stage-11 GC soak (AVM2_GC_SOAK=<ticks>): drive synthetic per-frame
	// garbage on the fully-constructed context and log live-object N. Runs in
	// place of the normal tick loop; stderr only, stdout untouched.
	{
		const char* soak = getenv("AVM2_GC_SOAK");
		if (soak != NULL)
		{
			avm2_gc_soak(ctx, (uint64_t) strtoull(soak, NULL, 10));
			fflush(stdout);
			return;
		}
	}

#if defined(__EMSCRIPTEN__) && !defined(NO_GRAPHICS) && !defined(OFFSCREEN_RENDER)
	// Stage 13a — browser loop shape. A browser cannot run a blocking batch
	// loop (it starves the event loop and never paints); instead run an
	// unbounded while(1) that yields to the event loop each frame via
	// emscripten_sleep (ASYNCIFY), mirroring swf.c's wall-clock pacing. GC still
	// runs at the top of each tick (VM quiescent — the Stage-11 invariant is
	// loop-shape independent). No MAX_FRAMES bound: the demo plays until the tab
	// closes. Perf timings feed swf.c's __swfPerf HUD (steady-state filtering,
	// Uncapped toggle) so the Windows real-GPU A/B reads the same global as the
	// AVM1 demos.
	{
		double fps = ctx->app->fps > 0 ? (double) ctx->app->fps : 30.0;
		double frame_budget_ms = 1000.0 / fps;
		double next_due_ms = 0.0;   // 0 = not yet anchored (set on the first frame)
		while (1)
		{
			double frame_start = emscripten_get_now();

			// Collect between ticks (VM quiescent). No-op under AVM2_GC=0.
			avm2_gc_maybe_collect(ctx);

			double present_ms = 0.0;
			Avm2TryFrame top;
			avm2_try_push_catch_all(ctx, &top);
			if (setjmp(top.jb) == 0)
			{
				avm2_display_run_tick(ctx);
				avm2_media_poll(ctx);   // Event.SOUND_COMPLETE for drained channels
				double present_start = emscripten_get_now();
				int close = avm2_render_present(ctx);
				present_ms = emscripten_get_now() - present_start;
				if (close)
				{
					avm2_try_pop_frame(&top);
					break;   // window closed
				}
			}
			avm2_try_pop_frame(&top);

			double now_ms = emscripten_get_now();
			double elapsed = now_ms - frame_start;
			// Real AVM2 GC census in the HUD's two live-count slots (the AVM1
			// loop passes objects+arrays; AVM2 has no array census, so slot 2
			// carries live strings). Previously literal 0,0 — which silently
			// made every browser-side AVM2 memory gate assert 0 == 0.
			int uncapped = swf_perf_report(elapsed, frame_budget_ms, present_ms,
			                               (int)avm2_gc_live_objects(),
			                               (int)avm2_gc_live_strings());
			if (next_due_ms == 0.0) next_due_ms = frame_start;   // anchor
			next_due_ms += frame_budget_ms;
			if (uncapped)
			{
				emscripten_sleep(0);
				next_due_ms = now_ms;   // don't bank credit while uncapped
			}
			else
			{
				double remain_ms = next_due_ms - now_ms;
				if (remain_ms > 0.0)
				{
					emscripten_sleep((unsigned) (remain_ms + 0.5));
				}
				else
				{
					emscripten_sleep(0);
					// >1 frame behind (heavy frame / backgrounded tab): resync
					// so we don't burst a catch-up storm.
					if (remain_ms < -frame_budget_ms) next_due_ms = now_ms;
				}
			}
		}
		fflush(stdout);
		return;
	}
#endif

	// Step 5: tick loop (Ruffle frame_lifecycle.rs phase order), mirroring
	// swf_core.c's MAX_FRAMES cadence.
#ifdef MAX_FRAMES
	size_t max_ticks = MAX_FRAMES;
#else
	size_t max_ticks = 10000;
#endif
	// AVM2_MAX_TICKS runtime override — drive a bring-up game arbitrarily deep
	// (past the built-in num_frames) without a full rebuild (MAX_FRAMES is a
	// -D on every TU, so bumping it busts ccache for the whole AVM2 build).
	{
		const char* mt = getenv("AVM2_MAX_TICKS");
		if (mt != NULL && mt[0] != '\0')
		{
			long v = strtol(mt, NULL, 10);
			if (v > 0) max_ticks = (size_t) v;
		}
	}
	// Worst-single-tick transient tracking (AVM2_HEAP_STATS report). The arena
	// floor is set by the largest transient a single tick allocates before the
	// next between-tick collection, not by steady live — see heap.h.
	size_t worst_boot_gross = 0;      // tick 0 (PlayState/boot construction)
	size_t worst_play_gross = 0;      // any later tick
	size_t worst_play_tick  = 0;
	for (size_t tick = 0; tick < max_ticks; tick++)
	{
		// Collect between ticks (VM quiescent — no method body on the C
		// stack, so the live set is exactly the persistent root graph).
		// Deterministic byte-watermark cadence; no-op under AVM2_GC=0.
		avm2_gc_maybe_collect(ctx);

		// Rebase the resettable high-water at the post-collect boundary so
		// heap_peak_since_mark − tick_base isolates THIS tick's gross transient.
		size_t tick_base = heap_allocated_bytes(ctx->app);
		heap_tick_mark(ctx->app);

		Avm2TryFrame top;
		avm2_try_push_catch_all(ctx, &top);
		if (setjmp(top.jb) == 0)
		{
			avm2_display_run_tick(ctx);
			// SOUND_COMPLETE poll: no-op in NO_GRAPHICS; in native graphics
			// nothing drains a channel (no sink), so this never fires in the
			// trace harness — trace-inert by construction.
			avm2_media_poll(ctx);
#ifdef OFFSCREEN_RENDER
			// Render the display tree the tick just built (Bitmap blit path).
			avm2_render_frame(ctx);
#endif
			// GPU-free CPU-composite dump (env-gated AVM2_CPU_DUMP); compiled
			// in every build, no-op when the env var is unset.
			avm2_cpu_dump_frame(ctx, (int) tick);
		}
		avm2_try_pop_frame(&top);

		size_t tick_peak = heap_peak_since_mark_bytes(ctx->app);
		size_t gross = (tick_peak > tick_base) ? (tick_peak - tick_base) : 0;
		if (tick == 0)
		{
			if (gross > worst_boot_gross) worst_boot_gross = gross;
		}
		else if (gross > worst_play_gross)
		{
			worst_play_gross = gross;
			worst_play_tick  = tick;
		}
	}

#ifdef OFFSCREEN_RENDER
	{
		Avm2TryFrame top;
		avm2_try_push_catch_all(ctx, &top);
		if (setjmp(top.jb) == 0)
		{
			avm2_render_finish(ctx);
		}
		avm2_try_pop_frame(&top);
	}
#endif

	// AVM2_HEAP_STATS=1: end-of-run o1heap diagnostics (peak_allocated is
	// cumulative) so arena sizing — e.g. the wasm32 heap for games whose boot
	// creates GBs of transient string garbage — is measured, not guessed.
	if (getenv("AVM2_HEAP_STATS") != NULL)
	{
		heap_stats(ctx->app);
		// Worst-single-tick gross transient (peak allocated within one tick,
		// minus live at its start). This — not steady live — is what the arena
		// must hold, because the GC only reclaims between ticks.
		printf("Worst boot-tick gross:     %zu MB (%zu bytes, tick 0)\n",
			worst_boot_gross / (1024 * 1024), worst_boot_gross);
		printf("Worst gameplay-tick gross: %zu MB (%zu bytes, tick %zu)\n",
			worst_play_gross / (1024 * 1024), worst_play_gross, worst_play_tick);
		printf("Live at exit:              %zu MB (%zu bytes)\n\n",
			heap_allocated_bytes(ctx->app) / (1024 * 1024),
			heap_allocated_bytes(ctx->app));
	}

	fflush(stdout);
}
