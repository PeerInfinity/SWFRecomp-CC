# DrawingApiTest hitTest Plan
<!-- TESTS: misc-ming.all/DrawingApiTest -->

Last updated: 2026-05-19 (graduated from REMAINING_TAIL_TRIAGE
2026-05-08 entry; bounds work landed previously, hitTest residual
remains)

<!-- PLAN_META
id: DRAWING_API_HITTEST_PLAN
status: pending
phases:
  - id: 1
    name: "Drawing-API hitTest precision for zshape (returns undefined where Flash returns boolean)"
    status: pending
  - id: 2
    name: "Drawing-API hitTest boolean drift on inverted/edge cases (inv4, inv8)"
    status: pending
  - id: 3
    name: "Drawing-API hitTest false-positive at shape corner (e.hitTest)"
    status: pending
dependencies: []
related:
  - id: DRAWING_API_RENDERING_PLAN
    reason: "AVM1 Drawing-API plan (complete) covers rendering. hitTest path is separate from rendering."
  - id: VECTOR_PATH_HITTEST_PLAN
    reason: "AVM1 VECTOR_PATH_HITTEST (complete: 329/338) covers static-shape hitTest. Drawing-API shapes need similar precision work but operate on the runtime drawing buffer, not baked DefineShape geometry."
blockers: []
status_note: |
  Bounds-related portion of DrawingApiTest was fixed 2026-05-08
  (commit not yet identified; CURRENT_STATUS notes 66/93 → 80/93).
  Residual 13 diff lines + 2 trailing lines are all hitTest
  precision. Our 20 diffs are entirely disjoint from Ruffle's 14
  diffs (Ruffle ahead on bounds, behind on hitTests; mirror of our
  pre-fix state), so no path to ruffle_matched without doing
  hitTest work.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/DrawingApiTest | 80/93 | 86.0% | output_mismatch |

## Failure surface (transcribed from REMAINING_TAIL_TRIAGE)

Residual after the bounds-rewrite fix: 13 diff lines + 2 extra
trailing lines, all hitTest precision:

- `zshape.hitTest` returns undefined where Flash returns boolean
- `inv4.hitTest` / `inv8.hitTest` boolean drift (sign of returning
  test point produces opposite result from Flash for certain
  inverted-winding shapes)
- `e.hitTest` false-positive at corner pixel of a shape

## Approach

Drawing-API hitTest needs to be implemented against the *runtime*
drawing buffer (`mc->drawing_paths`), not the baked DefineShape
geometry that VECTOR_PATH_HITTEST handles. The drawing buffer is
a list of moveTo/lineTo/curveTo/beginFill/endFill ops; hitTest
must:

1. **Flatten the drawing into a winding-rule polygon** (bezier
   subdivision similar to the existing flattening done at render
   time).
2. **Run a point-in-polygon test** honoring Flash's even-odd vs
   non-zero winding (Drawing API uses non-zero winding per Flash
   spec).
3. **Return undefined** for cases where the shape has no fill (only
   strokes) AND the point isn't on the stroke — Flash's quirk that
   the test relies on.
4. **Match Flash's specific corner-pixel inclusion rule** — the
   `e.hitTest false-positive at corner` case suggests Flash
   excludes exact-corner points; we include them.

Reference: Ruffle's `drawing.rs::hit_test` for the algorithm.

## Recommended fix order

1. **Phase 1 (zshape undefined return)** — diagnose whether
   zshape has fills or only strokes; gate the hitTest return value
   on shape fill presence. Estimate: 1-2 hours.
2. **Phase 2 (inv4/inv8 winding rule)** — verify our winding
   counter accumulates signed crossings correctly for inverted
   shapes. Estimate: 2-3 hours.
3. **Phase 3 (corner-pixel exclusion)** — likely a `<` vs `<=`
   choice in the edge crossing test. Estimate: 1 hour.

Total estimate: 4-6 hours, 1-2 sessions.

## Promotion plumbing

Test has `known_failure = true` + `output.ruffle.txt`. Subset-match
auto-promotes once our diff is within Ruffle's. Currently our
diff is disjoint from Ruffle's diff, so subset-match cannot fire
until our 13 lines line up inside Ruffle's 14-line diff set —
specifically, Ruffle is wrong on bounds and we are now right;
Ruffle is right on hitTests and we are wrong. Fixing hitTests
will close all 13 our-side lines, and Ruffle's bounds diffs will
still be inside their own diff set — promotion follows.
