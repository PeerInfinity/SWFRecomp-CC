# `with()`-scope Gradient Fill Dispatch Plan
<!-- TESTS: GradientFillTest, DrawingApiTest (from_gnash/misc-ming.all) -->

<!-- PLAN_META
id: WITH_SCOPE_GRADIENT_FILL
status: not_started
phases:
  - id: 1
    name: "Add beginGradientFill handler to with-scope actionCallFunction branch"
    status: not_started
  - id: 2
    name: "Add lineGradientStyle handler (same branch)"
    status: not_started
  - id: 3
    name: "Verify GradientFillTest canvas + DrawingApiTest"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-05-14

## Status: NOT STARTED — root cause confirmed, fix scope is tight

## Problem

`with(mc) { beginGradientFill(...); moveTo(...); lineTo(...); endFill(); }` is
the standard Gnash-test idiom for drawing gradient-filled shapes. Inside
the `with(mc)`, the `beginGradientFill` call is a bare-name function call,
so the recompiler emits `actionCallFunction("beginGradientFill", …)` — not
`actionCallMethod(mc, "beginGradientFill", …)`.

`actionCallFunction` (`action.c` ~52185) has a special branch that
intercepts drawing-API names when there's a `with(mc)` scope active and
dispatches them as if they were method calls on the MC. The branch handles:

- `beginFill` (52193)
- `endFill` (52208)
- `moveTo` (52215)
- `lineTo` (52223)
- `curveTo` (52242)
- `lineStyle` (~52270)
- `clear` (~52290)
- `beginBitmapFill` (~52300)

**Missing:** `beginGradientFill` and `lineGradientStyle`. Calls to these
inside `with(mc)` fall through the drawing-API branch, get treated as
ordinary undefined-name function calls, and silently no-op. Result:
`ds->has_gradient` and `ds->has_fill` are never set, so the subsequent
`moveTo`/`lineTo`/`endFill` produces a `DrawPath` with `has_fill == 0`,
`drawingFinalizePath` skips tessellation, `fill_vert_count` stays 0, and
the path renders as nothing.

This is the immediate cause of the blank `output.actual.png` in
`from_gnash/misc-ming.all/GradientFillTest` (and the `0xffffff` pixel
sampling in `testbmp.draw(grad)`).

## Confirmation

Debug instrumentation in `actionIterateDrawings`:

```
[DBG] mc[0] name=grad path_count=25 cmd_count=0
[DBG]   fillDrawingInfos returned 0
```

25 paths exist on `grad` (`endFill` runs and calls `drawingFinalizePath`)
but every one fails the `fillDrawingInfos` filter
`(fill_vert_count == 0 || !has_fill) && (line_vert_count == 0 || !has_line)`
— because `path->has_fill == 0`.

## Affected Tests

Direct hits:
- `from_gnash/misc-ming.all/GradientFillTest` (motivator)
- `from_gnash/misc-ming.all/DrawingApiTest` (same `with(grad) { beginGradientFill ... }` pattern)

Other tests using `beginGradientFill` via the *method-call* form
(`mc.beginGradientFill(...)`) — like the avm1-suite
`movieclip_begin_gradient_fill` — are unaffected and already render
correctly via the `actionCallMethod` path.

## Implementation Plan

### Phase 1 — `beginGradientFill` handler in with-scope branch

The full `beginGradientFill` implementation lives in `actionCallMethod`
at `action.c:62890` (~170 LOC: type/colors/alphas/ratios parsing, matrix
parsing including box-matrix shorthand, spread mode, interpolation,
focal). Duplicating that block under the with-scope branch is the
simplest fix, mirroring how `beginBitmapFill` is duplicated.

Cleaner alternative: extract the body into a static helper
`drawingApplyGradientFill(MovieClip* mc, ActionVar* args, u32 num_args,
SWFAppContext* app_context)`, called from both the with-scope branch and
`actionCallMethod`. Either works; the helper extraction is preferable
for maintenance.

### Phase 2 — `lineGradientStyle` handler

`mc.lineGradientStyle(...)` (the gradient analogue of `lineStyle`) has
the same dispatch gap. Tests that use `with(mc) { lineGradientStyle(...) }`
would silently lose their stroke style. Quick survey: no current test
appears to exercise this via the with-scope path, but the fix is trivial
once Phase 1 lands — add the same dispatch for `lineGradientStyle`
alongside.

### Phase 3 — Verify

- `python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-ming.all --test=GradientFillTest --mode=graphics --expected-suffix=fp10 --diff --verbose`
- Expected outcome: `output.actual.png` shows the gradient grid matching
  `output.expected.png`. Image FAIL → much smaller outlier count (or
  PASS within the tolerance=34 / max_outliers=1070 budget). Trace
  failures from `testbmp.getPixel(...)` returning white will only be
  fully resolved once `CPU_GRADIENT_RASTERIZER_PLAN` also lands.
- `--test=DrawingApiTest` — should also benefit (currently failing on
  trace; image not checked).
- Regression-check: `movieclip_begin_gradient_fill`,
  `movieclip_line_gradient_style`, and any other test using
  `mc.beginGradientFill(...)` directly should be unaffected since they
  don't go through the with-scope branch.

## Design Considerations

1. **Code duplication vs. helper extraction.** The existing pattern in
   the file already duplicates `beginBitmapFill` between the two call
   sites (~80 LOC each). Extracting helpers is a cleanup that's worth
   doing while we're in this area; both `beginGradientFill` and
   `beginBitmapFill` would benefit. Make this a follow-up if it would
   expand the diff too much.

2. **No new design questions.** This is a pure dispatch-table gap —
   semantics are identical to the existing method-call path. No matrix
   math, no rendering changes.

3. **Doesn't fix the test alone.** GradientFillTest also depends on
   `SUBTESTS_HARNESS_PLAN` (to find an expected output) and
   `CPU_GRADIENT_RASTERIZER_PLAN` (for the trace pixel checks via
   BitmapData.draw). Landing all three is what gets the test to PASS
   (or to ACCEPTED_DIFFS for unfixable per-fp-version diffs).

## Estimated Complexity

Low. ~100 LOC if duplicated (mirrors `beginBitmapFill`), ~40 LOC if
extracted into a shared helper plus call-site replacements at both
locations. Single file, single function.
