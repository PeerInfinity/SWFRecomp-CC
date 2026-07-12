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

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

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
	return p;
}

// GC participant registered with the object.c mark-sweep aggregator (see
// g_avm2_gc_mark_roots there). Inventory: every AVM2 allocation (classes,
// vtables, globals, instances, closures, scope chains, strings, arrays,
// domain entries) is reachable for the whole run AND is invisible to the
// collector's census (only ASObject/ASArray enroll in g_mt_obj_head /
// g_mt_arr_head), so there is nothing to mark: AVM2 objects are immortal
// by construction and hold no edges into collectable AVM1 objects.
// Tranche-1 runs are short (MAX_FRAMES-bounded), so immortality is
// correct, just wasteful; enroll a real census if anything OOMs.
static void avm2GcMarkRoots(void)
{
}

extern void (*g_avm2_gc_mark_roots)(void);

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
	g_avm2_gc_mark_roots = avm2GcMarkRoots;

	avm2_globals_init(ctx);

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

	// Step 5: tick loop (Ruffle frame_lifecycle.rs phase order), mirroring
	// swf_core.c's MAX_FRAMES cadence.
#ifdef MAX_FRAMES
	const size_t max_ticks = MAX_FRAMES;
#else
	const size_t max_ticks = 10000;
#endif
	for (size_t tick = 0; tick < max_ticks; tick++)
	{
		Avm2TryFrame top;
		avm2_try_push_catch_all(ctx, &top);
		if (setjmp(top.jb) == 0)
		{
			avm2_display_run_tick(ctx);
		}
		avm2_try_pop_frame(&top);
	}

	fflush(stdout);
}
