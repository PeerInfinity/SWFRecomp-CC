# SWF Version-Specific Semantics Plan
<!-- TESTS: swf6_case_insensitive, swf6_string_as_bool, swf4_actions_coercion_order, swf5_to_6_cross_call, swf6_to_5_cross_call -->

Last updated: 2026-03-12

## Status: IN PROGRESS — 4/5 tests passing (Phases 1+2+3 complete, Phase 4 partial)

### Target Tests

| Test | SWF Ver | Match | Expected | Status |
|------|---------|-------|----------|--------|
| swf6_case_insensitive | 6 | 43/43 | 43 | **PASS** (Phase 1 complete) |
| swf6_string_as_bool | 6 | 15/15 | 15 | **PASS** (Phase 2 complete) |
| swf4_actions_coercion_order | 8 | 158/158 | 158 | **PASS** (Phase 3 complete) |
| swf5_to_6_cross_call | 5 | **29/29** | 29 | **PASS** ✅ (Phase 4 — SWF5 non-closure version isolation + this OBJECT type + objectCallToString context + getDepth version gate) |
| swf6_to_5_cross_call | 6 | 20/29 | 29 | Phase 4 partial — improved from 16/29 via objectCallToString context fix. Remaining: child SWF init context, reverse-direction version issues |

### Already passing
- `divide_swf4` — PASS
- `swf4_function_calls` — PASS
- `swf7_case_sensitive` — PASS

---

## Phase 1: SWF6 Case-Insensitive Property Lookup (swf6_case_insensitive) — COMPLETE

Implemented in commit c1f23ada. Changes:
- `prop_name_match()` in object.c: Unicode case-insensitive property lookup using unicode_case_tables.h
- `swf_name_match()` exposed for tag_stubs.c MC name matching
- variables.c: fold keys to lowercase for SWF <= 6 hashmap lookups
- tag_stubs.c: case-insensitive display list name matching
- `g_this_stack`: per-call-frame this binding stack (Ruffle Activation.this architecture)
  - GetVariable("this") checks g_this_stack before scope chain/variable table
  - SetVariable("this") mutates g_this_stack entry
  - Type 2 functions: only push to g_this_stack when !preload_this && !suppress_this

---

## Phase 2: SWF6 String-to-Boolean Coercion (swf6_string_as_bool) — COMPLETE

Implemented in commit 3d615d20. Fixed `stringVarToDouble`:
- Hex: strip "0x" prefix before strtol (was parsing full "0x-10" which stopped at '-')
- Octal: check ALL remaining chars are 0-7 before classifying ("010.5" → decimal, not octal)

---

## Phase 3: SWF4 Operator Coercion Order (swf4_actions_coercion_order) — COMPLETE

Implemented across multiple changes. Key fixes:

1. **Root MC dynamic_props fallback**: `actionGetVariable` now checks `root_movieclip.dynamic_props` after variable table lookup, so objects stored via `SetMember` on `_root` are found.

2. **valueOf closure support**: `convertFloat()`'s valueOf invocation now saves/restores captured scope chains, enabling closures defined inside `with` blocks or DefineFunction2 to access their captured variables.

3. **toString closure support**: `objectCallToString()` now saves/restores captured scope chains (same pattern as valueOf fix).

4. **`[type Object]` fallback**: When `toString()` returns a non-string (e.g. a number), `convertString()` now uses `[type Object]` instead of `[object Object]`, matching Ruffle/Flash behavior.

5. **Multiply operand order**: Fixed to coerce left operand (b) before right operand (a), matching Flash's left-to-right coercion order.

6. **SetTarget "Target not found" trace**: Added trace message when target resolution fails, matching Flash/Ruffle format.

7. **GetProperty target not found**: Returns `undefined` instead of default property value when target MC doesn't exist.

8. **SetProperty value coercion**: Added per-property-index coercion on the value argument (valueOf for numeric properties, toString for string properties like `_name`/`_quality`).

9. **CloneSprite/RemoveSprite toString**: Added `convertString` calls for proper toString coercion on object arguments.

10. **StartDrag constrain check**: Changed from `!= 0` to `== 1` to match Ruffle's `coerce_to_i32 == 1` behavior.

11. **Call/GotoFrame2/WaitForFrame2 toString**: Added object→string coercion for frame identifier arguments.

12. **GetURL2**: Already called `convertString` — now works correctly with closure-aware toString.

---

## Phase 4: Cross-Version Function Calls (PARTIALLY COMPLETE)

### The Problem

`swf5_to_6_cross_call` and `swf6_to_5_cross_call` load child SWFs with different version numbers. Functions defined in the child SWF should execute with the child's SWF version semantics (case sensitivity, `this` binding, closure behavior).

### Current State

Both tests have `child.swf` files that are loaded via loadMovie. The multi-SWF loading infrastructure is fully implemented and working (31/35 core loadMovie tests pass).

**swf5_to_6_cross_call: 29/29 PASS** ✅ (commit 2f40f9f9 + 3724101d). Four fixes:
1. SWF5 non-closure version isolation: `actionCallFunction` gates `switchToFunctionVersion` on `_cf_caller_ver >= 6`. SWF5 callers don't switch to called function's version.
2. SWF5 non-closure `this` type: For standalone DefineFunction2 calls from SWF5 calling SWF6+ functions, pass `global_object` as `this_obj` so preload_this stores as OBJECT type (typeof="object"), not MOVIECLIP.
3. `objectCallToString` closure context: Added `switchToFunctionVersion` + `actionSetCurrentContext(func->base_clip)` in the toString invocation path.
4. `getDepth` version gate: Added `g_swf_version < 6` check in MovieClip.prototype "last resort" lookup in `actionGetVariable`.

**swf6_to_5_cross_call: 20/29** (improved from 16/29 via objectCallToString fix). Remaining 9 diffs are the reverse direction (SWF6 calling SWF5 function). Issues:
- Child SWF init context: child defines function `f` with `g_current_context = root` instead of target clip, so `base_clip` points to root instead of clip MC.
- `this` binding: SWF6 closure call to SWF5-defined function — unclear whether to use SWF5 or SWF6 semantics for `this`.
- `_target`/`foo`/`getDepth`: flow from incorrect `base_clip`.

### Implementation Checklist

1. ~~**loadMovie child SWF support**~~ — **DONE**
2. ~~**Per-function SWF version tracking**~~ — **DONE**
3. ~~**Version switching on call**~~ — **DONE**
4. ~~**Version-gated MC prototype properties**~~ — **DONE** (getDepth gated in GetVariable last-resort path)
5. **Child SWF init context** — **BLOCKED**. Child SWF init scripts run with `g_current_context = root` instead of the loaded-into clip MC. Affects `base_clip` of functions defined in child SWF.
6. ~~**objectCallToString context switch**~~ — **DONE**. `switchToFunctionVersion` + `actionSetCurrentContext(func->base_clip)` in objectCallToString.
7. ~~**SWF5 non-closure version isolation**~~ — **DONE**. `actionCallFunction` only calls `switchToFunctionVersion` when `_cf_caller_ver >= 6`.
8. ~~**SWF5 non-closure this type**~~ — **DONE**. Pass `global_object` as `this_obj` for SWF5 callers calling SWF6+ DefineFunction2 standalone.

### Estimated Impact
- swf5_to_6_cross_call: **29/29 PASS** ✅
- swf6_to_5_cross_call: 20/29. Remaining 9 lines blocked on item 5 (child SWF init context)

---

## Recommended Work Order

1. **Phase 2** (swf6_string_as_bool) — smallest, most self-contained change
2. **Phase 1** (swf6_case_insensitive) — medium effort, significant impact
3. **Phase 3** (swf4_actions_coercion_order) — larger effort, many operators
4. **Phase 4** (cross-version calls) — blocked on loadMovie + per-function version tracking

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | Property lookup case folding, string-to-boolean coercion, SWF4 operator coercion |
| `SWFModernRuntime/src/actionmodern/object.c` | `getProperty`, `setProperty` case-insensitive variants |
| `SWFModernRuntime/src/actionmodern/variables.c` | `getVariable` case-insensitive matching |
| `SWFModernRuntime/include/actionmodern/unicode_case_tables.h` | Already exists — use in comparisons |
