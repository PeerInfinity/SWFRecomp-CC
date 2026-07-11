// Typed exceptions (avm2_error.h): try-frame stack, throw dispatch, and
// the Error class family. Dispatch semantics per Ruffle activation.rs
// handle_err; error message strings per Ruffle error.rs (exact FP text —
// many tests assert them).

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

// ---------------------------------------------------------------------------
// Debug call stack
// ---------------------------------------------------------------------------

void avm2_callstack_push(Avm2Context* ctx, const Avm2MethodRef* m, Avm2Class* bound_class)
{
	if (ctx->call_depth == ctx->call_cap)
	{
		uint32_t new_cap = ctx->call_cap == 0 ? 64 : ctx->call_cap * 2;
		Avm2CallFrame* grown = avm2_alloc(ctx, new_cap * sizeof(Avm2CallFrame));
		if (ctx->call_depth > 0)
		{
			memcpy(grown, ctx->call_frames, ctx->call_depth * sizeof(Avm2CallFrame));
		}
		ctx->call_frames = grown;
		ctx->call_cap = new_cap;
	}
	ctx->call_frames[ctx->call_depth].method = *m;
	ctx->call_frames[ctx->call_depth].bound_class = bound_class;
	ctx->call_depth++;
}

void avm2_callstack_pop(Avm2Context* ctx)
{
	if (ctx->call_depth > 0) ctx->call_depth--;
}

// Class name with "::"-qualified package for stack frames.
static int qname_colons(const Avm2Class* cls, char* buf, int size)
{
	if (cls->name.ns_len > 0)
	{
		return snprintf(buf, size, "%.*s::%.*s",
		                (int) cls->name.ns_len, cls->name.ns_uri,
		                (int) cls->name.name_len, cls->name.name);
	}
	return snprintf(buf, size, "%.*s", (int) cls->name.name_len, cls->name.name);
}

void avm2_callstack_frame_name(Avm2Context* ctx, const Avm2CallFrame* f,
                               char* buf, int size)
{
	(void) ctx;
	const Avm2MethodRef* m = &f->method;
	if (f->bound_class != NULL)
	{
		char cq[128];
		qname_colons(f->bound_class, cq, sizeof(cq));
		int is_iinit = f->bound_class->instance_init.fn == m->fn
		               && f->bound_class->instance_init.file == m->file
		               && f->bound_class->instance_init.method_index == m->method_index;
		if (is_iinit)
		{
			snprintf(buf, size, "%s()", cq);
		}
		else
		{
			// mxmlc debug names are qualified ("test_fla:MainTimeline/
			// test_fla:frame1"); keep only the final segment.
			const char* dn = (m->debug_name != NULL && m->debug_name[0] != '\0')
				? m->debug_name : "<anonymous>";
			const char* slash = strrchr(dn, '/');
			if (slash != NULL) dn = slash + 1;
			const char* colon = strrchr(dn, ':');
			if (colon != NULL) dn = colon + 1;
			snprintf(buf, size, "%s/%s()", cq, dn);
		}
		return;
	}
	if (m->file == NULL)
	{
		// Native: debug_name is prebuilt (globals register the full
		// "global/ns::name" form).
		snprintf(buf, size, "%s()", m->debug_name != NULL ? m->debug_name : "<native>");
		return;
	}
	const Avm2AbcMethodData* md = &m->file->data->methods[m->method_index];
	if (md->is_function)
	{
		snprintf(buf, size, "Function/%s()",
		         (m->debug_name != NULL && m->debug_name[0] != '\0')
		         ? m->debug_name : "<anonymous>");
		return;
	}
	if (m->debug_name != NULL && m->debug_name[0] != '\0')
	{
		snprintf(buf, size, "global/%s()", m->debug_name);
		return;
	}
	snprintf(buf, size, "global$init()");
}

// Is `cls` in the Error family (its constructor frames are excluded from
// stack snapshots)?
static int class_is_error_family(Avm2Context* ctx, Avm2Class* cls)
{
	for (Avm2Class* c = cls; c != NULL; c = c->super_class)
	{
		if (c == ctx->builtins.error_class) return 1;
	}
	return 0;
}

// Snapshot "\n\tat X()" lines for the current stack (innermost first),
// skipping the error-constructor frames on top.
static const Avm2String* callstack_snapshot(Avm2Context* ctx)
{
	char buf[4096];
	uint32_t n = 0;
	int64_t top = (int64_t) ctx->call_depth - 1;
	while (top >= 0)
	{
		Avm2CallFrame* f = &ctx->call_frames[top];
		int is_error_ctor = f->bound_class != NULL
			&& class_is_error_family(ctx, f->bound_class)
			&& f->bound_class->instance_init.fn == f->method.fn;
		if (!is_error_ctor) break;
		top--;
	}
	for (int64_t i = top; i >= 0 && n + 200 < sizeof(buf); i--)
	{
		char name[176];
		avm2_callstack_frame_name(ctx, &ctx->call_frames[i], name, sizeof(name));
		n += (uint32_t) snprintf(buf + n, sizeof(buf) - n, "\n\tat %s", name);
	}
	return avm2_string_new(ctx, buf, n);
}

// ---------------------------------------------------------------------------
// Try frames
// ---------------------------------------------------------------------------

void avm2_try_push_frame(Avm2Context* ctx, Avm2TryFrame* tf,
                         const Avm2AbcException* excs, uint32_t exc_count,
                         Avm2AbcFileRt* file)
{
	memset(tf, 0, sizeof(*tf));
	tf->excs = excs;
	tf->exc_count = exc_count;
	tf->file = file;
	tf->saved_call_depth = ctx->call_depth;
	tf->prev = ctx->try_top;
	ctx->try_top = tf;
}

void avm2_try_push_catch_all(Avm2Context* ctx, Avm2TryFrame* tf)
{
	memset(tf, 0, sizeof(*tf));
	tf->catch_all = 1;
	tf->saved_call_depth = ctx->call_depth;
	tf->prev = ctx->try_top;
	ctx->try_top = tf;
}

void avm2_try_pop_frame(Avm2TryFrame* tf)
{
	// Frames above tf (from callees that longjmp'd past their pop) are
	// dropped along with it.
	avm2_get_context()->try_top = tf->prev;
}

static void print_uncaught(Avm2Context* ctx, Avm2Value v)
{
	// Diagnostics only (stderr): uncaught errors don't produce trace output.
	const Avm2String* s = avm2_coerce_to_string(ctx, v);
	fflush(stdout);
	fprintf(stderr, "AVM2 uncaught error: %.*s\n", (int) s->len, s->utf8);
}

_Noreturn void avm2_throw(Avm2Context* ctx, Avm2Value value)
{
	for (Avm2TryFrame* tf = ctx->try_top; tf != NULL; tf = tf->prev)
	{
		if (tf->catch_all)
		{
			print_uncaught(ctx, value);
			ctx->try_top = tf;  // drop frames above
			ctx->call_depth = tf->saved_call_depth;
			tf->exc = value;
			longjmp(tf->jb, 1);
		}
		for (uint32_t i = 0; i < tf->exc_count; i++)
		{
			const Avm2AbcException* e = &tf->excs[i];
			if (!e->active) continue;
			if (tf->op_index < e->from_op || tf->op_index >= e->to_op) continue;
			if (e->type_mn != 0)
			{
				Avm2Class* cls = avm2_class_for_mn(ctx, tf->file, e->type_mn);
				if (cls == NULL) continue;
				if (!avm2_value_is_of_type(ctx, value, cls)) continue;
			}
			ctx->try_top = tf;  // keep this frame installed (nested catches)
			ctx->call_depth = tf->saved_call_depth;
			tf->exc = value;
			tf->handler_target = e->target_op;
			longjmp(tf->jb, 1);
		}
	}
	// No frame at all (shouldn't happen: avm2_main installs a catch-all).
	print_uncaught(ctx, value);
	exit(1);
}

// ---------------------------------------------------------------------------
// Error construction
// ---------------------------------------------------------------------------

Avm2Value avm2_error_new(Avm2Context* ctx, Avm2Class* error_class, const char* message)
{
	if (error_class == NULL) error_class = ctx->builtins.error_class;
	Avm2Value args[2];
	args[0] = avm2_string(avm2_string_from_literal(ctx, message));
	// Runtime error messages carry their FP code as "Error #NNNN: ..." —
	// surface it as errorID (Ruffle constructs errors with the code).
	int32_t code = 0;
	const char* hash = strchr(message, '#');
	if (hash != NULL)
	{
		code = (int32_t) strtol(hash + 1, NULL, 10);
	}
	args[1] = avm2_integer(code);
	return avm2_class_construct(ctx, error_class, args, 2);
}

_Noreturn void avm2_throw_error(Avm2Context* ctx, Avm2Class* error_class,
                                const char* fmt, ...)
{
	char buf[512];
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);
	avm2_throw(ctx, avm2_error_new(ctx, error_class, buf));
}

_Noreturn void avm2_throw_null_or_undefined(Avm2Context* ctx, Avm2Value v,
                                            const char* name, uint32_t name_len)
{
	const char* base = (v.kind == AVM2_VALUE_UNDEFINED)
		? "Error #1010: A term is undefined and has no properties."
		: "Error #1009: Cannot access a property or method of a null object reference.";
	if (name != NULL && name_len > 0)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "%s (accessing field: %.*s)", base, (int) name_len, name);
	}
	avm2_throw_error(ctx, ctx->builtins.type_error_class, "%s", base);
}

_Noreturn void avm2_throw_1006(Avm2Context* ctx, const char* name, uint32_t name_len)
{
	(void) name; (void) name_len;
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #1006: value is not a function.");
}

_Noreturn void avm2_throw_1069(Avm2Context* ctx, const char* name, uint32_t name_len,
                               Avm2Class* cls)
{
	char cn[160];
	avm2_class_qname_buf(cls, cn, sizeof(cn));
	avm2_throw_error(ctx, ctx->builtins.reference_error_class,
	                 "Error #1069: Property %.*s not found on %s and there is "
	                 "no default value.", (int) name_len, name, cn);
}

_Noreturn void avm2_throw_1065(Avm2Context* ctx, const char* name, uint32_t name_len)
{
	avm2_throw_error(ctx, ctx->builtins.reference_error_class,
	                 "Error #1065: Variable %.*s is not defined.",
	                 (int) name_len, name);
}

// ---------------------------------------------------------------------------
// Error classes
// ---------------------------------------------------------------------------

// name/message are instance SLOTS (Ruffle Error.as `public var name` /
// `public var message`): direct reads see them, but prototype-CHAIN reads
// don't (only dynamic props delegate — error_prototype).
enum
{
	ERROR_SLOT_NAME = 1,
	ERROR_SLOT_MESSAGE = 2,
};

// Error constructor body: this.message = args[0] (default ""), this.name =
// <constructing class>.prototype.name, errorID = args[1] (dont-enum
// dynamic — the getter reads it back).
static Avm2Value error_init(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = act->this_val.u.obj;
	Avm2Value msg = (act->argc > 0)
		? avm2_string(avm2_coerce_to_string(ctx, act->args[0]))
		: avm2_string(avm2_string_from_literal(ctx, ""));
	// this.name = prototype.name (Ruffle Error.as). The defining class's
	// prototype carries it: dynamic on subclass prototypes, a slot on
	// Error.prototype itself.
	Avm2Value name = avm2_string(avm2_string_from_literal(ctx, "Error"));
	if (act->bound_class != NULL && act->bound_class->prototype_obj != NULL)
	{
		Avm2Value pn = avm2_get_public_property(
			ctx, avm2_object_value(act->bound_class->prototype_obj), "name", 4, NULL);
		if (pn.kind != AVM2_VALUE_UNDEFINED) name = pn;
	}
	if (self->slot_count > ERROR_SLOT_MESSAGE)
	{
		self->slots[ERROR_SLOT_NAME] = name;
		self->slots[ERROR_SLOT_MESSAGE] = msg;
	}
	Avm2Value eid = (act->argc > 1)
		? avm2_integer(avm2_coerce_to_i32(ctx, act->args[1]))
		: avm2_integer(0);
	Avm2DynProp* p = avm2_object_set_dynamic(ctx, self, "errorID", 7, eid);
	p->dont_enum = 1;
	// FP debug player snapshots the call stack at construction.
	p = avm2_object_set_dynamic(ctx, self, "__stacktrace_tail", 17,
	                            avm2_string(callstack_snapshot(ctx)));
	p->dont_enum = 1;
	return avm2_undefined();
}

// Error.prototype.toString: "" message → name, else "name: message".
static Avm2Value error_proto_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Value name = avm2_get_public_property(ctx, act->this_val, "name", 4, NULL);
	Avm2Value msg = avm2_get_public_property(ctx, act->this_val, "message", 7, NULL);
	const Avm2String* name_s = avm2_coerce_to_string(ctx, name);
	const Avm2String* msg_s = avm2_coerce_to_string(ctx, msg);
	if (msg_s->len == 0)
	{
		return avm2_string(name_s);
	}
	const Avm2String* sep = avm2_string_from_literal(ctx, ": ");
	return avm2_string(avm2_string_concat(ctx, avm2_string_concat(ctx, name_s, sep), msg_s));
}

static Avm2Value error_get_error_id(Avm2Activation* act)
{
	// Read the dynamic slot directly (the vtable getter would recurse).
	if (act->this_val.kind == AVM2_VALUE_OBJECT)
	{
		Avm2Value* v = avm2_object_find_dynamic(act->this_val.u.obj, "errorID", 7);
		if (v != NULL) return *v;
	}
	return avm2_integer(0);
}

static Avm2Value error_get_stack_trace(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	if (act->this_val.kind != AVM2_VALUE_OBJECT) return avm2_null();
	Avm2Value* tail = avm2_object_find_dynamic(act->this_val.u.obj,
	                                           "__stacktrace_tail", 17);
	if (tail == NULL) return avm2_null();
	// First line is the error's toString().
	Avm2Value head = error_proto_to_string(act);
	return avm2_string(avm2_string_concat(ctx, head.u.str, tail->u.str));
}

// Error(...) call = new Error(...) (Ruffle globals/error.rs call handler).
static Avm2Value error_call(Avm2Context* ctx, Avm2Class* cls,
                            const Avm2Value* args, uint32_t argc)
{
	return avm2_class_construct(ctx, cls, args, argc);
}

static void error_add_slot(Avm2Context* ctx, Avm2Class* cls, const char* name,
                           uint32_t slot_id)
{
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = avm2_public_key(name, (uint32_t) strlen(name));
	e.kind = AVM2_PROP_SLOT;
	e.slot_index = slot_id;
	e.defining_class = cls;
	avm2_vtable_append(ctx, &cls->ivtable, &e);
	if (slot_id > cls->ivtable.slot_count) cls->ivtable.slot_count = slot_id;
}

static Avm2Class* make_error_class(Avm2Context* ctx, const char* name, Avm2Class* super)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "", name, super);
	cls->native_call = error_call;
	// Every error class runs the Error constructor body (subclass SWF
	// constructors reach it via constructsuper).
	cls->instance_init.fn = error_init;
	cls->instance_init.debug_name = name;
	if (super == ctx->builtins.object_class)
	{
		error_add_slot(ctx, cls, "name", ERROR_SLOT_NAME);
		error_add_slot(ctx, cls, "message", ERROR_SLOT_MESSAGE);
		avm2_builtin_add_method(ctx, cls, "getStackTrace", error_get_stack_trace);
		avm2_builtin_add_getter(ctx, cls, "errorID", error_get_error_id);

		// Error.prototype is itself an ERROR instance (avmplus
		// initCustomPrototype): name/message land in its slots (invisible
		// to prototype-CHAIN reads), toString stays dynamic (delegated).
		Avm2Object* proto = cls->prototype_obj;
		proto->cls = cls;
		proto->vtable = &cls->ivtable;
		proto->slot_count = cls->ivtable.slot_count + 1;
		proto->slots = avm2_alloc(ctx, proto->slot_count * sizeof(Avm2Value));
		for (uint32_t i = 0; i < proto->slot_count; i++)
		{
			proto->slots[i] = avm2_undefined();
		}
		proto->slots[ERROR_SLOT_NAME] =
			avm2_string(avm2_string_from_literal(ctx, "Error"));
		proto->slots[ERROR_SLOT_MESSAGE] =
			avm2_string(avm2_string_from_literal(ctx, "Error"));
		avm2_proto_add_function(ctx, proto, "toString", error_proto_to_string);
	}
	else
	{
		// Subclass prototypes are plain objects carrying only a dynamic
		// `name`; toString delegates to Error.prototype's (identity matters:
		// TypeError.prototype.toString === Error.prototype.toString).
		avm2_object_set_dynamic(ctx, cls->prototype_obj, "name", 4,
			avm2_string(avm2_string_from_literal(ctx, name)))->dont_enum = 1;
	}
	return cls;
}

void avm2_register_error(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;
	b->error_class = make_error_class(ctx, "Error", b->object_class);
	b->type_error_class = make_error_class(ctx, "TypeError", b->error_class);
	b->reference_error_class = make_error_class(ctx, "ReferenceError", b->error_class);
	b->argument_error_class = make_error_class(ctx, "ArgumentError", b->error_class);
	b->range_error_class = make_error_class(ctx, "RangeError", b->error_class);
	b->verify_error_class = make_error_class(ctx, "VerifyError", b->error_class);
	b->eval_error_class = make_error_class(ctx, "EvalError", b->error_class);
	b->security_error_class = make_error_class(ctx, "SecurityError", b->error_class);
	b->definition_error_class = make_error_class(ctx, "DefinitionError", b->error_class);
	b->uri_error_class = make_error_class(ctx, "URIError", b->error_class);
	b->syntax_error_class = make_error_class(ctx, "SyntaxError", b->error_class);
	b->uninitialized_error_class = make_error_class(ctx, "UninitializedError", b->error_class);

	// flash.errors family (playerglobal AS3 classes extending Error).
	{
		static const char* const names[7] = {
			"IOError", "EOFError", "MemoryError", "IllegalOperationError",
			"InvalidSWFError", "ScriptTimeoutError", "StackOverflowError",
		};
		Avm2Class* made[7];
		for (int i = 0; i < 7; i++)
		{
			Avm2Class* cls = avm2_builtin_class(ctx, "flash.errors", names[i],
			                                    b->error_class);
			cls->native_call = error_call;
			cls->instance_init.fn = error_init;
			cls->instance_init.debug_name = names[i];
			avm2_object_set_dynamic(ctx, cls->prototype_obj, "name", 4,
				avm2_string(avm2_string_from_literal(ctx, names[i])))->dont_enum = 1;
			made[i] = cls;
		}
		b->io_error_class = made[0];
		b->memory_error_class = made[2];
		b->illegal_operation_error_class = made[3];
	}
	{
		// DRMManagerError uniquely sets NO prototype.name (Ruffle
		// DRMManagerError.as note; error_prototype asserts undefined).
		Avm2Class* cls = avm2_builtin_class(ctx, "flash.errors", "DRMManagerError",
		                                    b->error_class);
		cls->native_call = error_call;
		cls->instance_init.fn = error_init;
		cls->instance_init.debug_name = "DRMManagerError";
	}
}
