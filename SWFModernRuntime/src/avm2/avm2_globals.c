// Stage-2 builtin stubs + the definition domain (avm2-support-plan §4.5).
//
// Builtins are constructible with correct super links and register through
// the same vtable mechanism as SWF-defined classes (playerglobal-shaped
// binding surface); they have NO display-list behavior — the root
// MovieClip stub only stores addFrameScript closures for the tick loop.
//
// The domain mirrors Ruffle's Domain: FindPropStrict's last resort maps a
// definition name to the globals object defining it, running the defining
// script's initializer lazily on first touch (this is what makes
// hello_world's "Hello world!" fire from frame 1's `new Test()`).
// Builtins are seeded first, so parent-domain (playerglobal) definitions
// win over movie definitions, matching avmplus precedence.

#include <stdio.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

// ---------------------------------------------------------------------------
// Domain
// ---------------------------------------------------------------------------

void avm2_domain_add(Avm2Context* ctx, const Avm2PropKey* key,
                     Avm2AbcFileRt* file, uint32_t script_index)
{
	Avm2Domain* d = &ctx->domain;
	if (d->count == d->cap)
	{
		uint32_t new_cap = d->cap == 0 ? 16 : d->cap * 2;
		Avm2DomainEntry* grown = avm2_alloc(ctx, new_cap * sizeof(Avm2DomainEntry));
		if (d->count > 0)
		{
			memcpy(grown, d->entries, d->count * sizeof(Avm2DomainEntry));
		}
		d->entries = grown;
		d->cap = new_cap;
	}
	Avm2DomainEntry* e = &d->entries[d->count++];
	e->key = *key;
	e->file = file;
	e->script_index = script_index;
}

void avm2_script_ensure_init(Avm2AbcFileRt* file, uint32_t script_index)
{
	if (file->script_init_state[script_index] != AVM2_SCRIPT_UNINITIALIZED)
	{
		return;
	}
	file->script_init_state[script_index] = AVM2_SCRIPT_INITIALIZING;

	const Avm2AbcScriptData* sd = &file->data->scripts[script_index];
	const Avm2AbcMethodData* init = &file->data->methods[sd->init_method];
	Avm2MethodRef ref = { init->fn, file, init->debug_name };
	avm2_call_method_ref(file->ctx, &ref, NULL, NULL,
	                     avm2_object_value(file->script_globals[script_index]),
	                     NULL, 0);

	file->script_init_state[script_index] = AVM2_SCRIPT_INITIALIZED;
}

Avm2Object* avm2_domain_find(Avm2Context* ctx, const Avm2PropKey* key)
{
	for (uint32_t i = 0; i < ctx->domain.count; i++)
	{
		Avm2DomainEntry* e = &ctx->domain.entries[i];
		if (!avm2_propkey_matches(&e->key, key)) continue;
		if (e->file == NULL)
		{
			return ctx->builtin_globals;
		}
		avm2_script_ensure_init(e->file, e->script_index);
		return e->file->script_globals[e->script_index];
	}
	return NULL;
}

// ---------------------------------------------------------------------------
// Native methods
// ---------------------------------------------------------------------------

static Avm2Value native_trace(Avm2Activation* act)
{
	// Ruffle globals/toplevel.rs trace: join args with " ", newline-terminate.
	for (uint32_t i = 0; i < act->argc; i++)
	{
		if (i > 0) fputc(' ', stdout);
		const Avm2String* s = avm2_coerce_to_string(act->ctx, act->args[i]);
		fwrite(s->utf8, 1, s->len, stdout);
	}
	fputc('\n', stdout);
	return avm2_undefined();
}

static Avm2Value native_addFrameScript(Avm2Activation* act)
{
	if (act->this_val.kind != AVM2_VALUE_OBJECT || act->this_val.u.obj == NULL
	    || act->this_val.u.obj->native_ext == NULL)
	{
		avm2_fatal("addFrameScript on a non-MovieClip receiver");
	}
	Avm2MovieClipExt* ext = act->this_val.u.obj->native_ext;

	// Arguments are (frameIndex, closure) pairs; frame indices are 0-based.
	for (uint32_t i = 0; i + 1 < act->argc; i += 2)
	{
		int32_t frame = avm2_coerce_to_i32(act->args[i]);
		if (frame < 0) continue;
		if ((uint32_t) frame >= ext->frame_script_cap)
		{
			uint32_t new_cap = (uint32_t) frame + 8;
			Avm2Value* grown = avm2_alloc(act->ctx, new_cap * sizeof(Avm2Value));
			for (uint32_t j = 0; j < new_cap; j++)
			{
				grown[j] = (j < ext->frame_script_cap) ? ext->frame_scripts[j]
				                                       : avm2_undefined();
			}
			ext->frame_scripts = grown;
			ext->frame_script_cap = new_cap;
		}
		ext->frame_scripts[frame] = act->args[i + 1];
	}
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// Builtin classes
// ---------------------------------------------------------------------------

static Avm2PropKey builtin_key(const char* ns, const char* name)
{
	Avm2PropKey k;
	k.name = name;
	k.name_len = (uint32_t) strlen(name);
	k.ns_kind = 0x16;  // package
	k.ns_uri = ns;
	k.ns_len = (uint32_t) strlen(ns);
	return k;
}

static Avm2Class* builtin_class(Avm2Context* ctx, const char* ns, const char* name,
                                Avm2Class* super)
{
	Avm2Class* cls = avm2_alloc(ctx, sizeof(Avm2Class));
	memset(cls, 0, sizeof(Avm2Class));
	cls->name = builtin_key(ns, name);
	cls->super_class = super;
	cls->instance_init.fn = NULL;    // no-op stub constructor
	cls->instance_init.file = NULL;
	cls->instance_init.debug_name = name;
	if (super != NULL)
	{
		cls->ivtable.slot_count = super->ivtable.slot_count;
		for (uint32_t i = 0; i < super->ivtable.count; i++)
		{
			avm2_vtable_append(ctx, &cls->ivtable, &super->ivtable.entries[i]);
		}
		cls->native_ext_size = super->native_ext_size;
		cls->native_init = super->native_init;
	}

	Avm2Object* cobj = avm2_object_alloc(ctx, AVM2_OBJ_CLASS, 1);
	cobj->class_ref = cls;
	cobj->cls = ctx->builtins.class_class;  // NULL while bootstrapping Object/Class
	cls->class_object = cobj;

	// Expose on the builtin globals object + in the domain.
	avm2_object_set_dynamic(ctx, ctx->builtin_globals, name,
	                        (uint32_t) strlen(name), avm2_object_value(cobj));
	avm2_domain_add(ctx, &cls->name, NULL, 0);
	return cls;
}

static void builtin_add_method(Avm2Context* ctx, Avm2Class* cls, const char* name,
                               Avm2MethodFn fn)
{
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = builtin_key("", name);
	e.kind = AVM2_PROP_METHOD;
	e.method.fn = fn;
	e.method.file = NULL;
	e.method.debug_name = name;
	e.defining_class = cls;
	e.method_scope = NULL;
	avm2_vtable_append(ctx, &cls->ivtable, &e);
}

void avm2_globals_init(Avm2Context* ctx)
{
	ctx->builtin_globals = avm2_object_alloc(ctx, AVM2_OBJ_SCRIPT, 0);

	Avm2Builtins* b = &ctx->builtins;
	b->object_class = builtin_class(ctx, "", "Object", NULL);
	b->class_class = builtin_class(ctx, "", "Class", b->object_class);
	b->function_class = builtin_class(ctx, "", "Function", b->object_class);
	// Bootstrap fixup: Object/Class class objects were made before Class existed.
	b->object_class->class_object->cls = b->class_class;
	b->class_class->class_object->cls = b->class_class;
	ctx->builtin_globals->cls = b->object_class;

	// The display chain hello_world's script init walks (stubs: correct
	// super links, constructible, no display behavior).
	Avm2Class* event_dispatcher =
		builtin_class(ctx, "flash.events", "EventDispatcher", b->object_class);
	Avm2Class* display_object =
		builtin_class(ctx, "flash.display", "DisplayObject", event_dispatcher);
	Avm2Class* interactive_object =
		builtin_class(ctx, "flash.display", "InteractiveObject", display_object);
	Avm2Class* doc =
		builtin_class(ctx, "flash.display", "DisplayObjectContainer", interactive_object);
	Avm2Class* sprite = builtin_class(ctx, "flash.display", "Sprite", doc);
	Avm2Class* movieclip = builtin_class(ctx, "flash.display", "MovieClip", sprite);
	movieclip->native_ext_size = sizeof(Avm2MovieClipExt);
	builtin_add_method(ctx, movieclip, "addFrameScript", native_addFrameScript);
	b->movieclip_class = movieclip;

	// Toplevel trace(): a function object on the builtin globals.
	{
		Avm2Object* fnobj = avm2_object_alloc(ctx, AVM2_OBJ_FUNCTION, 0);
		fnobj->cls = b->function_class;
		fnobj->fn_method.fn = native_trace;
		fnobj->fn_method.file = NULL;
		fnobj->fn_method.debug_name = "trace";
		fnobj->fn_receiver = avm2_object_value(ctx->builtin_globals);
		avm2_object_set_dynamic(ctx, ctx->builtin_globals, "trace", 5,
		                        avm2_object_value(fnobj));
		Avm2PropKey trace_key = builtin_key("", "trace");
		avm2_domain_add(ctx, &trace_key, NULL, 0);
	}
}
