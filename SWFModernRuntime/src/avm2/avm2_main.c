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
// swf_core.c is not referenced from here and never references this file;
// the shared wasm_wrappers/main.c picks runSWF_avm2 over swfStart only
// under -DSWF_AVM2 (defined by verify_output.py for avm2 tests).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <memory/heap.h>

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

static Avm2Context g_avm2_ctx;

void* avm2_alloc(Avm2Context* ctx, uint32_t size)
{
	void* p = heap_alloc(ctx->app, size);
	if (p == NULL)
	{
		avm2_fatal("out of memory allocating %u bytes", size);
	}
	return p;
}

// GC participant registered with the object.c mark-sweep aggregator (see
// g_avm2_gc_mark_roots there). Stage-2 inventory: every AVM2 allocation
// (classes, vtables, globals, the root instance, closures, scope chains,
// domain entries) is reachable for the whole run AND is invisible to the
// collector's census (only ASObject/ASArray enroll in g_mt_obj_head /
// g_mt_arr_head), so there is nothing to mark: AVM2 objects are immortal
// by construction and hold no edges into collectable AVM1 objects.
// Stage 3 TODO: enroll AVM2 objects in their own census + mark scope/
// globals/frame-script roots here once avm2 code can create garbage.
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
		globals->cls = ctx->builtins.object_class;
		Avm2ScopeChain* script_scope =
			avm2_scope_capture(ctx, NULL, &globals, 1);
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

static void construct_root(Avm2Context* ctx, const char* class_name)
{
	Avm2PropKey key;
	Avm2Object* globals = find_root_class_globals(ctx, class_name, &key);
	if (globals == NULL)
	{
		avm2_fatal("SymbolClass root class '%s' is not defined", class_name);
	}
	const Avm2PropEntry* entry = avm2_vtable_find(globals->vtable, &key);
	Avm2Value cls_val;
	if (entry != NULL && entry->kind == AVM2_PROP_SLOT)
	{
		cls_val = globals->slots[entry->slot_index];
	}
	else
	{
		Avm2Value* dyn = avm2_object_find_dynamic(globals, key.name, key.name_len);
		if (dyn == NULL)
		{
			avm2_fatal("SymbolClass root class '%s' resolved a globals object "
			           "without the class slot", class_name);
		}
		cls_val = *dyn;
	}
	if (cls_val.kind != AVM2_VALUE_OBJECT || cls_val.u.obj == NULL
	    || cls_val.u.obj->kind != AVM2_OBJ_CLASS)
	{
		avm2_fatal("SymbolClass root binding '%s' is not a class", class_name);
	}
	Avm2Value root = avm2_class_construct(ctx, cls_val.u.obj->class_ref, NULL, 0);
	ctx->root = root.u.obj;
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
	// all other scripts stay lazy (Ruffle movie_clip.rs:4246-4255).
	for (uint32_t i = 0; i < ctx->file_count; i++)
	{
		if (ctx->files[i]->data->script_count > 0)
		{
			avm2_script_ensure_init(ctx->files[i],
			                        ctx->files[i]->data->script_count - 1);
		}
	}

	// Step 4: construct the root class instance (its constructor typically
	// calls addFrameScript on itself).
	if (root_class != NULL)
	{
		construct_root(ctx, root_class);
	}

	// Step 5: tick loop, mirroring swf_core.c's MAX_FRAMES cadence.
#ifdef MAX_FRAMES
	const size_t max_ticks = MAX_FRAMES;
#else
	const size_t max_ticks = 10000;
#endif
	for (size_t tick = 0; tick < max_ticks; tick++)
	{
		// Stage-5 TODO: real timeline (playhead advance, enterFrame /
		// frameConstructed broadcasts, non-root frame scripts). Stage 2
		// runs the root's frame-0 script once, on the first tick — the
		// single-frame-movie behavior hello_world needs.
		if (tick == 0 && ctx->root != NULL && ctx->root->native_ext != NULL)
		{
			Avm2MovieClipExt* ext = ctx->root->native_ext;
			if (ext->frame_script_cap > 0
			    && ext->frame_scripts[0].kind == AVM2_VALUE_OBJECT)
			{
				avm2_call_function_obj(ctx, ext->frame_scripts[0].u.obj, NULL, 0);
			}
		}
	}

	fflush(stdout);
}
