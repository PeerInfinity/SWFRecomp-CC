#ifndef AVM2_ERROR_H
#define AVM2_ERROR_H

// Typed exceptions: Throw + exception-table dispatch (plan §4.4). Runtime
// dispatch uses setjmp/longjmp (the AVM1 g_exception_state precedent, but
// implemented here in src/avm2/ — action.c is never touched).
//
// Every emitted method body whose exception table has an active entry
// pushes an Avm2TryFrame in its prologue; avm2_throw walks the frame stack
// looking for a covering, type-matching handler (Ruffle activation.rs
// handle_err: op_index in [from_op, to_op), typed match by is_of_type,
// type 0 = catch-all) and longjmps to it. avm2_main installs a catch-all
// frame around each top-level entry (script init, root construction,
// frame scripts) so uncaught errors abort that entry only, matching
// Flash/Ruffle (the movie keeps running).

#include <setjmp.h>

#include <avm2/avm2_abc.h>
#include <avm2/avm2_value.h>

typedef struct Avm2Class Avm2Class;
typedef struct Avm2CallFrame Avm2CallFrame;

typedef struct Avm2TryFrame
{
	struct Avm2TryFrame* prev;
	jmp_buf jb;
	// Body frames: the method's exception table + defining file.
	const Avm2AbcException* excs;
	uint32_t exc_count;
	Avm2AbcFileRt* file;
	uint32_t op_index;        // updated by the body before each op
	uint8_t catch_all;        // top-level frame: catches everything
	// A catch-all the RUNTIME installs to handle the error itself (the loaded
	// SWF's root constructor renders its own trace). Ruffle only routes an
	// error to Avm2::uncaught_error where the player loop discards it, so a
	// silent frame must not also go through print_uncaught — otherwise
	// loader_error_in_root_ctor's traced line appears twice.
	uint8_t silent;
	uint32_t saved_call_depth;  // debug call stack unwound to here on catch
	// Set by dispatch before the longjmp:
	Avm2Value exc;
	uint32_t handler_target;  // op index to resume at
} Avm2TryFrame;

// Native C-stack guard. avmplus bounds AS3 recursion by the real machine
// stack (AvmCore::stackLimit / interpreter.cpp's stackAvailable check), not by
// a frame count, and reports exhaustion as a catchable Error #1023 "Stack
// overflow occurred." — infinitely recursive scripts are expected to survive
// as a caught exception (ecma3/Exceptions/bug127913). avm2_stack_guard_init
// records the startup stack address and budget; avm2_stack_check throws when
// an invocation would run past it.
void avm2_stack_guard_init(Avm2Context* ctx);
void avm2_stack_check(Avm2Context* ctx);

// Debug call stack (avm2_class.c pushes/pops around every invocation).
void avm2_callstack_push(Avm2Context* ctx, const Avm2MethodRef* m, Avm2Class* bound_class);
void avm2_callstack_pop(Avm2Context* ctx);
// FP-style frame name ("Test()", "test_fla::MainTimeline/frame1()",
// "global/flash.utils::getDefinitionByName()", "Function/<anonymous>()").
void avm2_callstack_frame_name(Avm2Context* ctx, const Avm2CallFrame* f,
                               char* buf, int size);

void avm2_try_push_frame(Avm2Context* ctx, Avm2TryFrame* tf,
                         const Avm2AbcException* excs, uint32_t exc_count,
                         Avm2AbcFileRt* file);
void avm2_try_push_catch_all(Avm2Context* ctx, Avm2TryFrame* tf);
// As above, but the caller reports the error itself (see `silent`).
void avm2_try_push_catch_all_silent(Avm2Context* ctx, Avm2TryFrame* tf);
void avm2_try_pop_frame(Avm2TryFrame* tf);

// Throw a value: longjmp to the innermost matching handler; if only the
// top-level catch-all matches, it logs to stderr and resumes there. Aborts
// the process if no frame is installed at all.
_Noreturn void avm2_throw(Avm2Context* ctx, Avm2Value value);

// Render a thrown value the way the debug player traces an uncaught one
// (toString() + the construction-time "\n\tat X()" tail).
const Avm2String* avm2_error_stack_string(Avm2Context* ctx, Avm2Value v);

// Construct an Error-family instance (does not throw).
Avm2Value avm2_error_new(Avm2Context* ctx, Avm2Class* error_class, const char* message);
// printf-style construct + throw. `error_class` NULL = plain Error.
_Noreturn void avm2_throw_error(Avm2Context* ctx, Avm2Class* error_class,
                                const char* fmt, ...);

// Common error constructors (exact FP strings ported from Ruffle error.rs).
_Noreturn void avm2_throw_null_or_undefined(Avm2Context* ctx, Avm2Value v,
                                            const char* name, uint32_t name_len);
_Noreturn void avm2_throw_1006(Avm2Context* ctx, const char* name, uint32_t name_len);
_Noreturn void avm2_throw_1069(Avm2Context* ctx, const char* name, uint32_t name_len,
                               Avm2Class* cls);
_Noreturn void avm2_throw_1065(Avm2Context* ctx, const char* name, uint32_t name_len);

#endif // AVM2_ERROR_H
