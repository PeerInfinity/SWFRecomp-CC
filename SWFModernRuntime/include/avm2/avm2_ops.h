#ifndef AVM2_OPS_H
#define AVM2_OPS_H

// Opcode helpers called by the generated C in RecompiledABC/. One function
// per non-trivial IR op the Stage-2 emitter supports; trivial ops
// (GetLocal, Pop, PushInt, ...) are emitted inline. See
// SWFRecomp/src/abc/abc_emit.cpp for the emission patterns.

#include <avm2/avm2_abc.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_value.h>

// Locals setup: loc[0] = this, loc[1..] = args padded with undefined.
void avm2_setup_locals(Avm2Value* loc, uint32_t num_locals, const Avm2Activation* act);

// PushScope: coerce to object (aborts on null/undefined — TypeError 1009/
// 1010 parity is a Stage 3 concern) and return the scope entry.
Avm2Object* avm2_op_pushscope(Avm2Activation* act, Avm2Value v);

// FindPropStrict: local scope top→bottom, captured outer chain top→bottom,
// then the defining file's domain (lazy script init). Aborts with
// ReferenceError 1065 text if unresolved.
Avm2Object* avm2_op_findpropstrict(Avm2Activation* act, Avm2Object* const* lscope,
                                   uint32_t scope_n, uint32_t mn_idx);

Avm2Value avm2_op_getproperty_static(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx);
void avm2_op_initproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx, Avm2Value val);

Avm2Value avm2_op_callproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                               const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_constructprop(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                const Avm2Value* args, uint32_t argc);
void avm2_op_constructsuper(Avm2Activation* act, Avm2Value recv,
                            const Avm2Value* args, uint32_t argc);

Avm2Value avm2_op_newclass(Avm2Activation* act, uint32_t class_idx, Avm2Value base,
                           Avm2Object* const* lscope, uint32_t scope_n);

// Honest failure paths: print a clear diagnostic to stderr and exit
// non-zero so unsupported avm2 tests fail as runtime_error, not silently.
_Noreturn void avm2_unimplemented_op(Avm2Activation* act, const char* op_name, uint32_t op_index);
_Noreturn void avm2_verify_error_body(Avm2Activation* act, const char* message);
_Noreturn void avm2_fatal(const char* fmt, ...);

#endif // AVM2_OPS_H
