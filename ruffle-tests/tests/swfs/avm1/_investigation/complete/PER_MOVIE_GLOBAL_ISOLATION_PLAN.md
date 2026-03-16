# Per-Movie `_global` Isolation Plan

## Status: COMPLETE

**Score**: `global_swf5_6_7_8_9` — **1145/1145 PASS**

### What was resolved:
- **SWF5 `_global` restriction**: Direct `GetVariable("_global")` returns undefined for SWF5. (Implemented)
- **Object constructor display**: `[type Function]` now correctly displayed for function values in string concatenation. Fixed `objectCallValueOf` and `objectCallToString` to not look up inherited Object.prototype methods on function own_props. (Implemented)
- **Two-group `_global` model**: Confirmed CORRECT. `global_swf6_7_8` test expects `g7 === g8: true`, proving SWF7+ share `_global`. `g_global_legacy` (SWF ≤6) and `g_global_modern` (SWF 7+) is the right architecture.
- **Per-version-group Function.prototype**: Each version group (SWF≤6, SWF7+) now has its own `Function.prototype` object. User-defined functions get virtual `__proto__` via `getFunctionProto()` in `actionGetMember`. Built-in constructors (both primary and secondary groups) get `own_props` with `__proto__` pointing to the group-appropriate `Function.prototype`. All 72 `__proto__` identity diffs resolved.

### Implementation details (Function.prototype):
- `g_function_proto_legacy` / `g_function_proto_modern` globals in action.c
- `getFunctionProto(version)` helper returns the appropriate Function.prototype
- `ensureGlobalInit`: creates primary Function.prototype, sets `__proto__` on all `g_ctors[].own_props`
- `ensureSecondaryGlobalInit`: creates secondary Function.prototype
- `createConstructorCopy`: allocates `own_props` with `__proto__` → secondary Function.prototype
- Secondary extra constructors (String/Number/Boolean/Function/Error) also get `own_props` with secondary Function.prototype
- `actionGetMember` FUNCTION path: virtual `__proto__` fallback returns `getFunctionProto(func->swf_version)` for functions without own_props (uses `g_swf_version` for built-ins with swf_version=0)
- `g_object_constructor.own_props.__proto__` set to Function.prototype instead of Object.prototype

### Why per-movie `_global` was WRONG:
The original plan proposed per-movie `_global` objects (one per loaded SWF). Implementation revealed this breaks `global_swf6_7_8` which expects `g7 === g8: true` — SWF7+ movies share the same `_global`. The two-group model (legacy/modern) is correct for `_global` itself.

### Key learning:
- The `_global` object is shared within version groups (SWF ≤6, SWF 7+)
- `Function.prototype` is per-version-group (not per-movie — confirmed by Ruffle source code at `core/src/avm1/runtime.rs` using two `GlobalEnv` instances)
- child9.swf in the test is actually SWF version 5 (not 9), so grouping is: {child5(v5), child6(v6), child9(v5)} = legacy, {child7(v7), child8(v8)} = modern

### Comprehensive Ruffle source confirmation (2026-03-10):
Full investigation of `~/CC/ruffle/core/src/avm1/runtime.rs` confirmed: Ruffle has NO per-movie `_global` isolation for AVM1. The `Avm1` struct has exactly two `GlobalEnv` instances (case-sensitive/case-insensitive), shared across ALL loaded SWFs. All constructors, prototypes, and singletons (Math, Key, Mouse, Stage) are shared. Cross-movie `instanceof` returns TRUE (shared prototype chain). The LOADMOVIE_MULTI_SWF_PLAN Phase 6 was cancelled as a result — it was the documented "biggest blocker" but was never needed.

---

## Correction Record

**Original plan**: Per-movie `_global` with `MovieGlobalEntry` registry, `createMovieGlobal()` factory, etc.

**Attempt**: Implementation began, `movie_global_idx` field added to ASFunction, `switchToFunctionVersion` updated with 3-param signature. Discovered `global_swf6_7_8` regression. REVERTED all per-movie `_global` infrastructure. Kept the two-group model.

**Final solution**: Per-version-group Function.prototype (two objects total, not per-movie). Resolves all 72 diffs without requiring per-movie infrastructure.
