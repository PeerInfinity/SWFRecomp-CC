<!-- TESTS: displacementmapfilter_mappoint_throw_error -->

<!-- PLAN_META
id: DISPLACEMENTMAPFILTER
status: blocked
phases:
  - id: 1
    name: "Native property setter for mapPoint"
    status: not_started
  - id: 2
    name: "valueOf error propagation"
    status: not_started
  - id: 3
    name: "toString for Point display"
    status: not_started
dependencies: []
blockers:
  - reason: "Requires native property setter with valueOf coercion and try/catch error propagation"
-->

# DisplacementMapFilter mapPoint Setter Plan

## Status: BLOCKED — requires native property setter with valueOf coercion and try/catch integration

## Test Summary

| Test | Lines | Match | Status | Root Cause |
|------|-------|-------|--------|------------|
| displacementmapfilter_mappoint_throw_error | 13 | 0/13 (0%) | output_mismatch | mapPoint setter not implemented |

## What the Test Does

Source: `~/CC/ruffle/tests/tests/swfs/avm1/displacementmapfilter_mappoint_throw_error/test.as`

The test creates a `DisplacementMapFilter`, then repeatedly sets its `mapPoint` property using
a helper `trySetting(f, p)` that wraps the assignment in try/catch:

```actionscript
function trySetting(f, p) {
    try {
        f.mapPoint = p;
        trace("Set: " + f.mapPoint);
    } catch (e) {
        trace("Caught: " + e + ", " + f.mapPoint);
    }
}
```

It passes various objects as `p`:
1. Normal `{x:1, y:2}` — should succeed, trace `Set: (x=1, y=2)`
2. Object with `valueOf` that throws — should catch the error, mapPoint unchanged
3. Objects with one valid and one throwing property — partial coercion behavior
4. Primitives `true`/`false` — should coerce to Point(0,0)

## Current Behavior

Every line outputs `Set: [object Object]` or `Set: true`/`Set: false`. The raw value
passed to `trySetting` is stored directly on the filter object as a plain property —
no coercion to Point, no valueOf invocation, no error catching.

## Root Cause Analysis

The `DisplacementMapFilter` constructor initializes `mapPoint` to a proper `Point(0,0)`
object (action.c:38506). However, subsequent `f.mapPoint = p` assignments go through
the generic `actionSetMember` path, which stores `p` as-is without any type coercion.

Flash's real behavior for `DisplacementMapFilter.mapPoint` setter:
1. Read `p.x` — coerce to int32 via `valueOf()` (may throw)
2. Read `p.y` — coerce to int32 via `valueOf()` (may throw)
3. If both succeed, create a new Point(x_int32, y_int32) and store it
4. If valueOf throws at step 1, mapPoint is reset to `Point(INT32_MIN, y_unchanged)`
5. If valueOf throws at step 2, x is updated but y becomes INT32_MIN
6. Non-object values (bool, number, etc.) coerce to Point(0,0)

## What Would Be Needed

### Phase 1: Native property setter for mapPoint

The `mapPoint` property needs to be an addProperty-style virtual property (or a native
setter check in `actionSetMember`) that intercepts writes and coerces the value:

```c
// In actionSetMember, when target is a filter object and member is "mapPoint":
// 1. If value is not an object → create Point(0, 0)
// 2. If value is an object:
//    a. Get value.x, coerce to int32 via valueOf (may throw)
//    b. Get value.y, coerce to int32 via valueOf (may throw)
//    c. Clamp via (int32_t)(int64_t)double_val for wrapping overflow
//    d. Create new Point(x_i32, y_i32)
// 3. Store the resulting Point as mapPoint
```

### Phase 2: valueOf error propagation

The tricky part: when `valueOf()` throws during coercion, the error must propagate
out through the property setter and be catchable by the outer try/catch. This requires:
- The coercion code to call `valueOf` as a function invocation
- If the function throws (via `actionThrow`), the throw must bubble up through
  `actionSetMember` → back to the try/catch in the calling script
- Partial state: if x's valueOf succeeds but y's throws, x is updated to its
  coerced value but y becomes INT32_MIN (−2147483648)

### Phase 3: toString for Point display

The `trace("Set: " + f.mapPoint)` output shows `(x=1, y=2)` format, which is
the Point object's `toString()`. Our Point class already has toString, so this
should work once mapPoint stores actual Point objects.

## Difficulty Assessment

**Hard.** The core challenge is the valueOf-throws-during-setter interaction:
- We have try/catch infrastructure (`actionTryBegin`/`actionThrow`)
- We have valueOf coercion (`convertFloat` calls valueOf)
- But connecting these through a property setter in `actionSetMember` requires
  ensuring throw propagation works across the call stack (setter → valueOf → throw → catch)
- The partial-update semantics (x updates but y gets INT32_MIN when y's valueOf throws)
  add complexity

This is a self-contained fix (only affects this one test) with moderate implementation
effort. It does NOT require any external infrastructure (no networking, IPC, or graphics).

## Feasibility

**Potentially actionable** but low priority at 0/13. The fix requires:
1. ~30 lines: native setter intercept in `actionSetMember` for filter mapPoint
2. ~20 lines: valueOf coercion with int32 wrapping
3. ~10 lines: partial-state handling when valueOf throws
4. Testing the throw propagation through the existing try/catch infrastructure

The implementation is not blocked by any missing infrastructure — it's a matter of
implementing the specific coercion semantics for this one property setter.
