# SWF Version-Specific Semantics Plan
<!-- TESTS: swf6_case_insensitive, swf6_string_as_bool, swf4_actions_coercion_order, swf5_to_6_cross_call, swf6_to_5_cross_call -->

Last updated: 2026-03-11

## Status: IN PROGRESS — 3/5 tests passing (Phases 1+2+3 complete)

### Target Tests

| Test | SWF Ver | Match | Expected | Status |
|------|---------|-------|----------|--------|
| swf6_case_insensitive | 6 | 43/43 | 43 | **PASS** (Phase 1 complete) |
| swf6_string_as_bool | 6 | 15/15 | 15 | **PASS** (Phase 2 complete) |
| swf4_actions_coercion_order | 8 | 158/158 | 158 | **PASS** (Phase 3 complete) |
| swf5_to_6_cross_call | 5 | 25/29 | 29 | Phase 4 — caller-version closure decision done (23→25/29). Remaining: version-gated MC props, objectCallToString context |
| swf6_to_5_cross_call | 6 | 16/29 | 29 | Phase 4 — unchanged. Remaining: child SWF init context, version-gated MC props, objectCallToString |

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

## Phase 4: Cross-Version Function Calls (BLOCKED on per-function version tracking)

### The Problem

`swf5_to_6_cross_call` and `swf6_to_5_cross_call` load child SWFs with different version numbers. Functions defined in the child SWF should execute with the child's SWF version semantics (case sensitivity, `this` binding, closure behavior).

### Current State

Both tests have `child.swf` files that are loaded via loadMovie. The multi-SWF loading infrastructure is fully implemented and working (31/35 core loadMovie tests pass). The child's functions should execute with the child's `g_swf_version`, not the parent's.

Current test results (2026-03-12): swf5_to_6_cross_call 25/29, swf6_to_5_cross_call 16/29. Caller-version closure decision fixed (commit 19e968ed). Remaining failures: version-gated MC prototype properties (getDepth invisible in SWF5), child SWF init context (g_current_context = root instead of clip), objectCallToString missing context switch.

### Blocker (Partially Resolved)

This requires:
1. ~~**loadMovie child SWF support**~~ — **DONE** (multi-SWF infrastructure fully working)
2. ~~**Per-function SWF version tracking**~~ — **DONE**. `ASFunction.swf_version` field exists, set at definition time. `switchToFunctionVersion()`/`restoreFunctionVersion()` helpers save/restore `g_swf_version`, `g_active_global`, and `g_active_movie_idx` around calls.
3. ~~**Version switching on call**~~ — **DONE** for onEnterFrame dispatch (b5df5477) AND direct call paths (19e968ed). Caller-version closure decision: `_cf_caller_ver`/`_om2_caller_ver`/`_om1_caller_ver` saved before `switchToFunctionVersion`, used for scope chain save/restore and base_clip context switch.
4. **Version-gated MC prototype properties** — **BLOCKED**. `getDepth` (and other SWF6+ methods) should be invisible when executing in SWF5 context. Requires per-property version tags on MC prototype.
5. **Child SWF init context** — **BLOCKED**. Child SWF init scripts run with `g_current_context = root` instead of the loaded-into clip MC. Affects `this` binding and `_target` in child-defined functions.
6. **objectCallToString context switch** — **BLOCKED**. Implicit toString/valueOf calls don't call `switchToFunctionVersion` or switch `g_current_context` to `func->base_clip`.

### Estimated Impact
- swf5_to_6_cross_call: 25/29. Remaining 4 lines blocked on items 4+6 above
- swf6_to_5_cross_call: 16/29. Remaining 13 lines blocked on items 4+5+6 above

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
