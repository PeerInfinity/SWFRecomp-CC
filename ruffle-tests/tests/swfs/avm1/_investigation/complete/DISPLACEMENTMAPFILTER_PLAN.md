<!-- TESTS: displacementmapfilter_mappoint_throw_error -->

<!-- PLAN_META
id: DISPLACEMENTMAPFILTER
status: complete
phases:
  - id: 1
    name: "Native property setter for mapPoint"
    status: complete
  - id: 2
    name: "valueOf error propagation"
    status: complete
  - id: 3
    name: "toString for Point display"
    status: complete
dependencies: []
blockers: []
-->

# DisplacementMapFilter mapPoint Setter Plan

## Status: COMPLETE — all 13/13 lines passing

## Test Summary

| Test | Lines | Match | Status | Root Cause |
|------|-------|-------|--------|------------|
| displacementmapfilter_mappoint_throw_error | 13 | 13/13 (100%) | PASS | All phases implemented |

## Implementation Summary

### Phase 1: Native property setter for mapPoint (was already done)
The mapPoint setter in `actionSetMember` already intercepted writes and coerced values
to Point objects with int32 truncation. Non-object values (bool, null, etc.) correctly
set Point(0,0). Objects with both x and y properties had their values coerced.

### Phase 2: valueOf error propagation (fixed 2026-04-03)
The core fix: when `valueOf()` throws during x/y coercion, the error must propagate
out to the caller's try/catch. Implementation uses local `setjmp`/`longjmp` exception
handlers around each coercion call:

1. Push a local exception frame on `g_exception_state`
2. Call `tsArgToDouble_ctx()` which invokes valueOf via `convertFloat`
3. If valueOf throws → `actionThrow` longjmps to our local handler
4. Capture the exception value, set component to INT32_MIN, continue
5. After both coercions: store the Point (state commits before re-throw)
6. Re-throw the first captured exception via `pushVar` + `actionThrow`

Key semantics matching Ruffle:
- Both x and y are coerced eagerly (even if x throws, y is still coerced)
- Point is stored regardless of errors (INT32_MIN for failed components)
- Only if BOTH x and y properties exist are coerced values used; otherwise Point(0,0)
- x error takes priority over y error for re-throw
- State commits before throw (Ruffle: `self.0.map_point.set(point)` before `x?`)

Infrastructure change: moved `ExceptionFrame`/`ExceptionState`/`g_exception_state`
and `#include <setjmp.h>` earlier in action.c (from line ~41088 to ~355) so the
mapPoint setter code at line ~33650 can access the exception infrastructure.

### Phase 3: toString for Point display (was already done)
Point objects already had toString returning `(x=N, y=N)` format.
