#ifndef AVM2_OPS_H
#define AVM2_OPS_H

// Opcode helpers called by the generated C in RecompiledABC/. One function
// per non-trivial IR op; trivial ops (GetLocal, Pop, Dup, PushInt, ...)
// are emitted inline. See SWFRecomp/src/abc/abc_emit.cpp for the emission
// patterns. Semantics ported from Ruffle core/src/avm2/activation.rs.
//
// Binary operators are helpers (not inline expressions) so operand
// coercion side effects (valueOf/toString) run in ECMA order.

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_value.h>

// Locals setup: loc[0] = this, loc[1..] = args coerced to the declared
// param types, missing trailing args filled from optional defaults, plus
// the `arguments`/rest array per method flags. Throws ArgumentError 1063
// on arg-count mismatch (Ruffle parameters.rs).
void avm2_setup_locals(Avm2Value* loc, uint32_t num_locals, Avm2Activation* act,
                       uint32_t method_index);

// ReturnValue coercion to the method's declared return type.
Avm2Value avm2_op_coerce_return(Avm2Activation* act, uint32_t method_index, Avm2Value v);

// PushScope/PushWith entry: null/undefined throws TypeError 1009/1010.
Avm2Object* avm2_op_pushscope(Avm2Activation* act, Avm2Value v);

// FindPropStrict/FindProperty: local scope top→bottom (with-scopes match
// any property, plain scopes declared traits only, the bottom global scope
// also matches dynamics), captured outer chain top→bottom, then the
// defining file's domain (lazy script init). strict: throw ReferenceError
// 1065 if unresolved; non-strict: return the global scope.
Avm2Object* avm2_op_findproperty(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                 uint32_t scope_n, uint32_t mn_idx, int strict);
Avm2Object* avm2_op_findproperty_dyn(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                     uint32_t scope_n, uint32_t mn_idx, Avm2Value name,
                                     int strict);
// FindDef: domain lookup only.
Avm2Object* avm2_op_finddef(Avm2Activation* act, uint32_t mn_idx);

// Per-call-site domain inline cache for static-multiname FindProperty /
// FindPropStrict (the getlex-global type-specialization lever). Caches only the
// DOMAIN resolution (stable per ctx: the domain is append-only with stable
// object identity). The generated C declares one (block-scoped, zero-init =
// empty) per find site and threads its address in. See avm2_op_findpropstrict_ic
// in avm2_ops.c for the full soundness argument.
typedef struct Avm2FindCache
{
	Avm2Context* ctx;   // domain identity this entry was resolved against
	Avm2Object* obj;    // cached domain-resolved def object (NULL = empty)
	// Scope-walk HIT cache (avm2_op_findpropstrict_ic): populated only when
	// the hit landed on the OUTER chain with a with-free checked prefix and
	// scope_n <= 1. Outer chains are allocated once and never freed, so the
	// chain-identity guard cannot alias; the same chain ⟹ the same entry
	// objects ⟹ the same trait-based misses above the hit.
	const Avm2ScopeChain* outer; // outer-chain identity guard
	const Avm2VTable* l_vt0;     // lscope[0] vtable guard (NULL ⟺ cached scope_n==0)
	Avm2Object* scope_obj;       // cached outer-chain hit object
	uint32_t l_n;                // scope_n at populate time (0 or 1)
	// scope_kind: 0 = no scope cache, 1 = OUTER-chain hit (replay returns
	// scope_obj), 2 = hit at lscope[0] with scope_n==1 (replay returns the
	// CURRENT activation's lscope[0].obj — the hit entry is the very first
	// thing the walk examines, so vtable identity alone determines the hit;
	// no prefix assumptions at all).
	uint32_t scope_kind;
} Avm2FindCache;

// Inline-cached FindProperty/FindPropStrict. Identical semantics to
// avm2_op_findproperty; `scope_stable` (recompiler proved the method with-free)
// additionally allows a cached domain hit to skip the scope walk.
Avm2Object* avm2_op_findpropstrict_ic(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                      uint32_t scope_n, uint32_t mn_idx, int strict,
                                      int scope_stable, Avm2FindCache* ic);
// GetGlobalScope: outer chain bottom, else local scope bottom.
Avm2Object* avm2_op_getglobalscope(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                   uint32_t scope_n);
Avm2Object* avm2_op_getouterscope(Avm2Activation* act, uint32_t index);

// Per-call-site monomorphic inline cache for GetPropertyStatic. The generated
// C declares one (block-scoped `static`) per getproperty call site and threads
// its address in; a repeat call whose receiver has the same vtable identity
// (and unchanged entry count) replays the resolved vtable entry directly,
// skipping multiname matching. Zero-initialized (vt == NULL) = empty; only
// plain-object receivers whose PRIMARY vtable find hit are ever cached, and a
// matching vt is byte-identical to the full resolve path (the vtable pointer
// alone determines not-null/not-xmlish/not-vector). See avm2_class.c's vtable
// name index for the miss-path accelerator this sits on top of.
typedef struct Avm2InlineCache
{
	const Avm2VTable* vt;    // receiver vtable this entry was resolved against
	uint32_t vt_count;       // vt->count at resolve time (guards realloc/growth)
	uint32_t entry_index;    // index into vt->entries (stable across realloc)
} Avm2InlineCache;

// Property access. *_dyn variants take the lazy runtime name.
Avm2Value avm2_op_getproperty_static(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx);
// Inline-cached variant: identical semantics, threads a per-call-site cache.
Avm2Value avm2_op_getproperty_static_ic(Avm2Activation* act, Avm2Value recv,
                                        uint32_t mn_idx, Avm2InlineCache* ic);
// Compile-time slot-bound read (recompiler's type-specialization pass): the
// recompiler proved the receiver is `this` — an instance of a sealed ABC class
// whose full superclass chain to Object is ABC-defined — and the accessed name
// resolves to a SLOT/CONST trait at compile-time slot index `slot` (numbered
// identically to avm2_class.c's ivtable assignment). `this` is never null in a
// verified instance method and slots aren't shadowable on a sealed class, so the
// read is a bare `slots[slot]` load — no null check, no vtable fetch, no
// multiname match, no resolved_get dispatch. `mn_idx` is carried only for the
// verify build. Build with -DAVM2_SLOT_VERIFY to cross-check `slot` against the
// full runtime resolve on every call and abort on any mismatch (validates the
// compile-time numbering); the default build is the pure inline load below.
#ifdef AVM2_SLOT_VERIFY
Avm2Value avm2_op_getproperty_slot(Avm2Activation* act, Avm2Value recv,
                                   uint32_t slot, uint32_t mn_idx);
#else
static inline Avm2Value avm2_op_getproperty_slot(Avm2Activation* act, Avm2Value recv,
                                                 uint32_t slot, uint32_t mn_idx)
{
	(void) act; (void) mn_idx;
	return recv.u.obj->slots[slot];
}
#endif
// Compile-time-resolved FindProperty/FindPropStrict (recompiler find→this
// lever): the recompiler proved the scope walk at this site always hits
// `this` — the enclosing instance method has the canonical GetLocal0+PushScope
// preamble as its only scope ops (no with, no activation, no active
// exceptions, no branch into the preamble), local 0 is never rewritten, and
// the multiname statically matches a declared instance trait of the enclosing
// class (ns-set aware, mirroring avm2_mn_match). Every runtime receiver (the
// class or any subclass) declares that trait, and plain-scope probes match
// declared traits only (scope_defines_mn), so the walk's FIRST probe
// (lscope[0] == this) always hits. The op is an identity move of loc[0];
// build -DAVM2_FIND_VERIFY to cross-check against the full resolve.
#ifdef AVM2_FIND_VERIFY
Avm2Value avm2_op_findprop_this(Avm2Activation* act, Avm2Value thisv,
                                const Avm2ScopeEntry* lscope, uint32_t scope_n,
                                uint32_t mn_idx);
#else
static inline Avm2Value avm2_op_findprop_this(Avm2Activation* act, Avm2Value thisv,
                                              const Avm2ScopeEntry* lscope,
                                              uint32_t scope_n, uint32_t mn_idx)
{
	(void) act; (void) lscope; (void) scope_n; (void) mn_idx;
	return thisv;
}
#endif
// `interp`: body is a class/script initializer — avmplus's interpreter
// takes the index fast path regardless of the ns set
// (class_init_interpreter_mode / array_access_interpreter).
Avm2Value avm2_op_getproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                  Avm2Value name, int interp);
void avm2_op_setproperty_static(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                Avm2Value value);
// Inline-cached SetPropertyStatic: identical semantics, threads a per-call-site
// cache. Same monomorphic-vtable design as getproperty (only plain-object
// receivers whose primary vtable find hits are cached — the resolved slot/setter
// entry is stable, so a matching vt replays it byte-identically).
void avm2_op_setproperty_static_ic(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                   Avm2Value value, Avm2InlineCache* ic);
void avm2_op_setproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                             Avm2Value name, Avm2Value value, int interp);
void avm2_op_initproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx, Avm2Value val);
Avm2Value avm2_op_deleteproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx);
Avm2Value avm2_op_deleteproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                     Avm2Value name);

// Lazy-namespace (RTQName/RTQNameL) property ops: `ns_val` is the popped
// Namespace VALUE; the *_l variants also pop the runtime name (a QName
// object name overrides the popped namespace, per Ruffle
// fill_with_runtime_params).
Avm2Value avm2_op_pushnamespace(Avm2Activation* act, uint32_t ns_idx);
Avm2Value avm2_op_getproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                   Avm2Value ns_val);
Avm2Value avm2_op_getproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                     Avm2Value ns_val, Avm2Value name_val);
void avm2_op_setproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                              Avm2Value ns_val, Avm2Value value);
void avm2_op_setproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                Avm2Value ns_val, Avm2Value name_val, Avm2Value value);
Avm2Value avm2_op_deleteproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                      Avm2Value ns_val);
Avm2Value avm2_op_deleteproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                        Avm2Value ns_val, Avm2Value name_val);
Avm2Value avm2_op_callproperty_rtns(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                    Avm2Value ns_val, const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_callproperty_rtns_l(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                      Avm2Value ns_val, Avm2Value name_val,
                                      const Avm2Value* args, uint32_t argc);
Avm2Object* avm2_op_findproperty_rtns(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                      uint32_t scope_n, uint32_t mn_idx, Avm2Value ns_val,
                                      int strict);
Avm2Object* avm2_op_findproperty_rtns_l(Avm2Activation* act, const Avm2ScopeEntry* lscope,
                                        uint32_t scope_n, uint32_t mn_idx, Avm2Value ns_val,
                                        Avm2Value name_val, int strict);

// Slots (IR indices are 0-based; runtime slot arrays are 1-based).
Avm2Value avm2_op_getslot(Avm2Activation* act, Avm2Value obj, uint32_t index0);
void avm2_op_setslot(Avm2Activation* act, Avm2Value obj, uint32_t index0, Avm2Value value);

// Calls. `opts` bit 1 = lex (receiver is null for the callee).
Avm2Value avm2_op_callproperty(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                               const Avm2Value* args, uint32_t argc);
// Inline-cached CallProperty/CallPropVoid (static multiname): identical
// semantics, threads a per-call-site cache. A repeat call whose receiver has the
// same vtable identity replays the resolved method/property entry, skipping the
// multiname match. Only plain-object receivers whose primary vtable find hit are
// cached (xmlish + no_index excluded), so a matching vt is byte-identical.
Avm2Value avm2_op_callproperty_ic(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                  const Avm2Value* args, uint32_t argc, Avm2InlineCache* ic);
Avm2Value avm2_op_callproperty_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                   Avm2Value name, const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_callproplex(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                              const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_call(Avm2Activation* act, Avm2Value func, Avm2Value recv,
                       const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_callstatic(Avm2Activation* act, uint32_t method_index, Avm2Value recv,
                             const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_callsuper(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                            const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_getsuper(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx);
void avm2_op_setsuper(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx, Avm2Value value);

// Construction.
Avm2Value avm2_op_construct(Avm2Activation* act, Avm2Value ctor,
                            const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_constructprop(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                const Avm2Value* args, uint32_t argc);
Avm2Value avm2_op_constructprop_dyn(Avm2Activation* act, Avm2Value recv, uint32_t mn_idx,
                                    Avm2Value name, const Avm2Value* args, uint32_t argc);
void avm2_op_constructsuper(Avm2Activation* act, Avm2Value recv,
                            const Avm2Value* args, uint32_t argc);

// ApplyType (Vector.<T>): pop type args, produce the parameterized class.
Avm2Value avm2_op_applytype(Avm2Activation* act, Avm2Value base,
                            const Avm2Value* params, uint32_t num_params);

// Object model.
Avm2Value avm2_op_newclass(Avm2Activation* act, uint32_t class_idx, Avm2Value base,
                           const Avm2ScopeEntry* lscope, uint32_t scope_n);
Avm2Value avm2_op_newfunction(Avm2Activation* act, uint32_t method_index,
                              const Avm2ScopeEntry* lscope, uint32_t scope_n);
Avm2Value avm2_op_newactivation(Avm2Activation* act, uint32_t method_index);
Avm2Value avm2_op_newcatch(Avm2Activation* act, uint32_t method_index, uint32_t exc_index);
Avm2Value avm2_op_newobject(Avm2Activation* act, const Avm2Value* name_value_pairs,
                            uint32_t num_pairs);
Avm2Value avm2_op_newarray(Avm2Activation* act, const Avm2Value* values, uint32_t n);

// Operators (value pairs; ECMA evaluation order preserved by the caller
// having already materialized both operands).
Avm2Value avm2_op_add(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_subtract(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_multiply(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_divide(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_modulo(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_negate(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_increment(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_decrement(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_add_i(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_subtract_i(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_multiply_i(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_negate_i(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_increment_i(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_decrement_i(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_bitand(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_bitor(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_bitxor(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_bitnot(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_lshift(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_rshift(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_urshift(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_equals(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_strictequals(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_lessthan(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_lessequals(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_greaterthan(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_greaterequals(Avm2Activation* act, Avm2Value a, Avm2Value b);
Avm2Value avm2_op_not(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_typeof(Avm2Activation* act, Avm2Value a);
Avm2Value avm2_op_in(Avm2Activation* act, Avm2Value name, Avm2Value obj);
Avm2Value avm2_op_instanceof(Avm2Activation* act, Avm2Value value, Avm2Value type);
Avm2Value avm2_op_istype(Avm2Activation* act, Avm2Value value, uint32_t mn_idx);
Avm2Value avm2_op_astype(Avm2Activation* act, Avm2Value value, uint32_t mn_idx);
Avm2Value avm2_op_istypelate(Avm2Activation* act, Avm2Value value, Avm2Value type);
Avm2Value avm2_op_astypelate(Avm2Activation* act, Avm2Value value, Avm2Value type);

// Coercions.
Avm2Value avm2_op_coerce(Avm2Activation* act, Avm2Value v, uint32_t mn_idx);
Avm2Value avm2_op_coerce_s(Avm2Activation* act, Avm2Value v);   // null/undef → null
Avm2Value avm2_op_convert_s(Avm2Activation* act, Avm2Value v);  // always string
Avm2Value avm2_op_coerce_o(Avm2Activation* act, Avm2Value v);   // undef → null
Avm2Value avm2_op_convert_o(Avm2Activation* act, Avm2Value v);  // null check

// -------------------------------------------------------------------------
// Coerce-elision verify hooks (Step 4, compile-time type specialization).
// The recompiler proves, via forward abstract-interpretation over the ABC,
// that a coerce_* site's operand already has the target static type, so the
// coercion is a value no-op and can be dropped. At every such elided site the
// emitter emits one of these hooks in place of the real coerce:
//   * normal build   — a `static inline` identity the optimizer removes,
//                       so the coercion truly disappears (the perf win).
//   * -DAVM2_COERCE_VERIFY — a real function that runs the ACTUAL coercion and
//                       aborts if it would have changed the value, then returns
//                       the ORIGINAL value (so output stays identical to the
//                       elided build). This proves every elision is sound
//                       across the whole test suite, exactly like
//                       -DAVM2_SLOT_VERIFY does for slot specialization.
#ifdef AVM2_COERCE_VERIFY
Avm2Value avm2_coerce_verify_return(Avm2Activation* act, uint32_t method_index, Avm2Value v);
Avm2Value avm2_coerce_verify_mn(Avm2Activation* act, Avm2Value v, uint32_t mn_idx);
Avm2Value avm2_coerce_verify_d(Avm2Activation* act, Avm2Value v);
Avm2Value avm2_coerce_verify_i(Avm2Activation* act, Avm2Value v);
Avm2Value avm2_coerce_verify_u(Avm2Activation* act, Avm2Value v);
Avm2Value avm2_coerce_verify_b(Avm2Activation* act, Avm2Value v);
Avm2Value avm2_coerce_verify_s(Avm2Activation* act, Avm2Value v);
#else
static inline Avm2Value avm2_coerce_verify_return(Avm2Activation* act, uint32_t method_index, Avm2Value v)
{ (void) act; (void) method_index; return v; }
static inline Avm2Value avm2_coerce_verify_mn(Avm2Activation* act, Avm2Value v, uint32_t mn_idx)
{ (void) act; (void) mn_idx; return v; }
static inline Avm2Value avm2_coerce_verify_d(Avm2Activation* act, Avm2Value v) { (void) act; return v; }
static inline Avm2Value avm2_coerce_verify_i(Avm2Activation* act, Avm2Value v) { (void) act; return v; }
static inline Avm2Value avm2_coerce_verify_u(Avm2Activation* act, Avm2Value v) { (void) act; return v; }
static inline Avm2Value avm2_coerce_verify_b(Avm2Activation* act, Avm2Value v) { (void) act; return v; }
static inline Avm2Value avm2_coerce_verify_s(Avm2Activation* act, Avm2Value v) { (void) act; return v; }
#endif
// E4X ops (GetDescendants / CheckFilter / Dxns / DxnsLate).
Avm2Value avm2_op_getdescendants(Avm2Activation* act, Avm2Value v, uint32_t mn_idx);
Avm2Value avm2_op_getdescendants_dyn(Avm2Activation* act, Avm2Value v, uint32_t mn_idx,
                                     Avm2Value name_val);
Avm2Value avm2_op_getdescendants_rtns(Avm2Activation* act, Avm2Value v, uint32_t mn_idx,
                                       Avm2Value ns_val);
Avm2Value avm2_op_getdescendants_rtns_l(Avm2Activation* act, Avm2Value v, uint32_t mn_idx,
                                        Avm2Value ns_val, Avm2Value name_val);
Avm2Value avm2_op_checkfilter(Avm2Activation* act, Avm2Value v);
void avm2_op_dxns(Avm2Activation* act, uint32_t str_idx);
void avm2_op_dxnslate(Avm2Activation* act, Avm2Value v);
Avm2Value avm2_op_esc_xattr(Avm2Activation* act, Avm2Value v);  // XML attr escape
Avm2Value avm2_op_esc_xelem(Avm2Activation* act, Avm2Value v);  // XML elem escape

// Enumeration.
Avm2Value avm2_op_hasnext2(Avm2Activation* act, Avm2Value* obj_reg, Avm2Value* idx_reg);
Avm2Value avm2_op_hasnext(Avm2Activation* act, Avm2Value obj, Avm2Value idx);
Avm2Value avm2_op_nextname(Avm2Activation* act, Avm2Value obj, Avm2Value idx);
Avm2Value avm2_op_nextvalue(Avm2Activation* act, Avm2Value obj, Avm2Value idx);

// Throw.
_Noreturn void avm2_op_throw(Avm2Activation* act, Avm2Value v);

// Honest failure paths: print a clear diagnostic to stderr and exit
// non-zero so unsupported avm2 tests fail as runtime_error, not silently.
_Noreturn void avm2_unimplemented_op(Avm2Activation* act, const char* op_name, uint32_t op_index);
// VerifyError bodies throw a catchable VerifyError (verify_* tests).
_Noreturn void avm2_verify_error_body(Avm2Activation* act, const char* message);
_Noreturn void avm2_fatal(const char* fmt, ...);

#endif // AVM2_OPS_H
