# SWF Version-Specific Semantics Plan
<!-- TESTS: swf6_case_insensitive, swf6_string_as_bool, swf4_actions_coercion_order, swf5_to_6_cross_call, swf6_to_5_cross_call -->

Last updated: 2026-02-24

## Status: NOT STARTED — 0/5 tests passing

### Target Tests

| Test | SWF Ver | Match | Expected | Issue |
|------|---------|-------|----------|-------|
| swf6_case_insensitive | 6 | 28/44 | 44 | Case-insensitive property lookup with Unicode not implemented |
| swf6_string_as_bool | 6 | 0/15 | 15 | SWF6 string-to-boolean coercion wrong |
| swf4_actions_coercion_order | 4 | 9/158 | 158 | SWF4 operators not calling valueOf/toString on operands |
| swf5_to_6_cross_call | 5 | 8/29 | 29 | Cross-version loadMovie with different semantics |
| swf6_to_5_cross_call | 6 | 10/29 | 29 | Cross-version loadMovie with different semantics |

### Already passing
- `divide_swf4` — PASS
- `swf4_function_calls` — PASS
- `swf7_case_sensitive` — PASS

---

## Phase 1: SWF6 Case-Insensitive Property Lookup (swf6_case_insensitive)

### The Problem

In SWF6 (and below), property names are case-insensitive. Flash uses Unicode case folding:
- `this.FOO` should find property `foo` (and vice versa)
- `this['ä']` should find property `Ä`
- `_LeVeL0` should resolve to `_level0`
- `clip` and `CLIP` and `Clip` are the same variable

### Current State (28/44 lines match)

Simple ASCII case-insensitive lookups partially work. Failures are:
1. `this['FOO']` → `undefined` instead of finding `foo` (bracket access with uppercase)
2. Unicode case folding (`ä` ↔ `Ä`, `ӥ` ↔ `Ӥ`, `ǳ` ↔ `Ǳ`)
3. `_LeVeL0` → `undefined` (special variables not case-folded)
4. Enumeration order of case-insensitive properties

### What's Needed

1. **Property lookup functions** (`getProperty`, `getPropertyWithPrototype`, `findPropertyStruct`) need case-insensitive string comparison when `g_swf_version <= 6`
2. **Variable resolution** (`getVariable`, `actionGetVariable`) needs case-insensitive matching
3. **Unicode case tables** — we already have `unicode_case_tables.h` with 713+683 entries. Need to use these in property comparisons.
4. **Special variables** (`_level0`, `_root`, `_global`) need case-insensitive matching

### Implementation

Add a case-insensitive comparison function:
```c
static int strcasecmp_swf(const char* a, u32 alen, const char* b, u32 blen) {
    if (g_swf_version > 6) return (alen == blen && strncmp(a, b, alen) == 0);
    // Use unicode_case_tables.h for case folding
    // Compare case-folded versions character by character
}
```

Then use it in all property lookup hot paths.

### Estimated Impact
- swf6_case_insensitive: +~12 lines (28→~40/44)
- May improve other SWF6 tests that use case-insensitive lookups

---

## Phase 2: SWF6 String-to-Boolean Coercion (swf6_string_as_bool)

### The Problem

SWF6 has different string-to-boolean rules than SWF7+:
- **SWF7+**: Empty string = false, non-empty = true
- **SWF6**: String converted to number first. `"0"` = false, `"1"` = true, `""` = false, `"abc"` = false (NaN = false)

### Current State (0/15 lines match)

Expected output shows numeric strings being evaluated as booleans:
```
10       ← "10" as boolean context should trace "10" (truthy)
0x10     ← "0x10" as boolean (truthy)
0x-10    ← "0x-10" as boolean (truthy? or false?)
```

The test likely evaluates various string values in `if()` conditions with trace output.

### What's Needed

In `evaluateCondition()` or the boolean conversion path, when `g_swf_version <= 6`:
```c
if (g_swf_version <= 6 && type == ACTION_STACK_VALUE_STRING) {
    // Convert string to number first, then to boolean
    double num = parseStringToNumber(str);
    return !isnan(num) && num != 0.0;
}
```

### Estimated Impact
- swf6_string_as_bool: potentially all 15 lines

---

## Phase 3: SWF4 Operator Coercion Order (swf4_actions_coercion_order)

### The Problem

SWF4 binary operators (`add`, `subtract`, `multiply`, etc.) should call `valueOf()` and `toString()` on their operands in left-to-right order. Currently these return NaN because objects aren't being coerced.

### Current State (9/158 lines match)

Most lines show `NaN` instead of coerced values. The test creates objects with custom valueOf/toString and checks that operators call them in the right order.

### What's Needed

In the SWF4 arithmetic operators (`actionAdd`, `actionSubtract`, `actionMultiply`, `actionDivide`, `actionLessThan`, `actionEquals`), add valueOf/toString coercion before numeric conversion:
```c
// For objects on the stack, call valueOf() before converting to number
if (val.type == ACTION_STACK_VALUE_OBJECT) {
    val = invokeValueOf(app_context, (ASObject*)val.data.numeric_value);
}
```

### Estimated Impact
- swf4_actions_coercion_order: significant improvement (9→~100+/158)
- Complex implementation — many SWF4 operators to update

---

## Phase 4: Cross-Version Function Calls (BLOCKED on loadMovie)

### The Problem

`swf5_to_6_cross_call` and `swf6_to_5_cross_call` load child SWFs with different version numbers. Functions defined in the child SWF should execute with the child's SWF version semantics (case sensitivity, `this` binding, closure behavior).

### Current State

Both tests have `child.swf` files that need to be loaded via loadMovie. The child's functions should execute with the child's `g_swf_version`, not the parent's.

### Blocker

This requires:
1. **loadMovie child SWF support** — loading `child.swf` into a clip
2. **Per-function SWF version tracking** — each ASFunction needs to remember which SWF version it was defined in
3. **Version switching on call** — when calling a function from a different version, temporarily switch `g_swf_version`

The loadMovie infrastructure for child SWFs exists (verify_output.py handles multi-SWF compilation), but per-function version tracking is not implemented.

### Estimated Impact
- swf5_to_6_cross_call: requires loadMovie + version tracking
- swf6_to_5_cross_call: same

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
