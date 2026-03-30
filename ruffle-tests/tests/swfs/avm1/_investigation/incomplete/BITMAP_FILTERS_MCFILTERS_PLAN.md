# bitmap_filters mc.filters[0] Initial Read Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTERS_MCFILTERS
status: not_started
phases:
  - id: 1
    name: "Diagnose mc reference in testMovieClipFilterSetter"
    status: not_started
  - id: 2
    name: "Fix mc.filters initial read"
    status: not_started
dependencies:
  - plan: BITMAP_FILTERS
    type: continues
    reason: "Remaining 8 lines from bitmap_filters (540/548)"
blockers: []
-->

Last updated: 2026-03-30

## Status: NOT STARTED — 8/548 lines remaining (540 pass)

### Problem

The `bitmap_filters` test at 540/548 has 8 failing lines (15, 90, 113, 156, 289, 360, 411, 484). All are `mc.filters[0]` reads that return `undefined` instead of the expected filter object.

### Root Cause Analysis

**NOT a SWF tag issue.** The test SWF has `hasFilter=0` on all PlaceObject3 tags — no SWF-authored filters. The filters are set entirely by ActionScript.

The test's `testMovieClipFilterSetter(arg0, mcName, filter)` function:
1. Gets MC reference: `mc = arg0[mcName]` (e.g., `arg0["bevelMC"]`)
2. Reads `mc.filters[0]` and traces it (the failing line)
3. Sets `mc.filters = [filter]`
4. Reads `mc.filters[0]` again (this line passes)

**The issue**: At the call site, `arg0` appears to be the integer `1` (from `main(1)`), not a MovieClip. So `1["bevelMC"]` returns `undefined`, making the MC reference `undefined`, and `undefined.filters[0]` also returns `undefined`.

The function likely intends to use `this` (the root MC/Test instance) to access `this["bevelMC"]`, not `arg0`. This suggests either:
- The recompiler pushes CallMethod arguments in the wrong order for this case
- Or `arg0` is actually a different register (the root MC ref) at the call site

### Investigation Needed

1. **Verify argument ordering**: Parse the raw SWF bytecode for the CallMethod at the call site. Compare the bytecode push order with what the recompiler emits. The recompiler's C code may have the argument pushes in the wrong order.

2. **Check register assignment**: Trace what `reg2` contains at the call to `testMovieClipFilterSetter`. In the generated code, `reg2 = args[0]` of the `main(1)` call, which is `1`. But in Flash, `reg2` might hold the Test instance or root MC.

3. **Compare with Ruffle trace**: The expected output shows the filter read succeeding, meaning Ruffle resolves the MC reference correctly. Check how Ruffle's AVM1 passes arguments for MTASC-compiled class methods.

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| testMovieClipFilterSetter | `script_defs.c` | 2974-3092 |
| Call site (main function) | `script_defs.c` | 132-146 |
| mc.filters getter | `action.c` | ~35792 |
| mc.filters setter | `action.c` | ~32789 |

### Estimated Complexity

Medium — likely a 1-5 line fix if it's an argument ordering issue. But requires careful bytecode analysis to confirm.

### Expected Impact

Fixes the last 8 lines of `bitmap_filters` (540→548, PASS). Would also fix similar patterns in other MTASC-compiled tests.
