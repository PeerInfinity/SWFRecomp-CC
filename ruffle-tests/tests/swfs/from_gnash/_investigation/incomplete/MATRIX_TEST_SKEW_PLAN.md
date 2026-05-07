# matrix_test Plan — Skew Tracking on MovieClip

<!-- TESTS: matrix_test -->

<!-- PLAN_META
id: MATRIX_TEST_SKEW
status: pending
phases:
  - id: 1
    name: "Add `skew` field to MovieClip + initialize at all creation sites"
    status: pending
  - id: 2
    name: "transformMatrixSetter: decompose skew via atan2(-c,d) - atan2(b,a)"
    status: pending
  - id: 3
    name: "getLocalMatrixForMC + _render: use cos(rot+skew) / sin(rot+skew) for c/d"
    status: pending
  - id: 4
    name: "Audit _xscale / _yscale / _rotation setters to preserve skew"
    status: pending
  - id: 5
    name: "Audit getBounds / getRect / hitTest paths that consume the local matrix"
    status: pending
  - id: 6
    name: "Regression battery + rebaseline"
    status: pending
dependencies: []
blockers: []
-->

Last updated: 2026-05-07. Standalone plan promoted from `REMAINING_TAIL_TRIAGE.md` after root cause was confirmed against Ruffle source.

## Status: pending — root cause identified, not yet implemented

`matrix_test` (`from_gnash/misc-ming.all/matrix_test/`) is at **84.5% effective** (949/1086 expected lines per CI `8fdf3311`; 948/1083 in latest local run, modulo ~1-line drift from re-baselined #passed/#total counts). 135 raw failures.

Per-test verification command:

```bash
python3 ruffle-tests/verify_output.py \
  --tests-dir=ruffle-tests/tests/swfs/from_gnash/misc-ming.all \
  --test=matrix_test --diff --verbose
```

Test marked `known_failure = true` in `test.toml` and ships `output.ruffle.txt`, so a partial fix that brings our diff into a strict subset of Ruffle's against `output.txt` will auto-promote via `verify_output.py::ruffle_subset_match`.

## Problem statement

Most of the 135 failures fall into two visually-distinct families that share the same root cause: when the test sets `staticmc.transform.matrix = ...` directly with a matrix that encodes scale + rotation **plus a skew component**, our implementation discards the skew. Reading `transform.matrix` back recomposes from `xscale`/`yscale`/`rotation` only, so signs on the `c` term flip; `getBounds` against `_root` then computes the wrong rotated AABB.

### Family A — `transform.matrix.toString()` `c` sign wrong

```
expected: '(a=0, b=-1, c=-2, d=0, tx=0, ty=0)' [matrix_test.c:1845]
obtained: '(a=0, b=-1, c=2,  d=0, tx=0, ty=0)'
```

Test reads `staticmc._rotation == -90, _xscale == 100, _yscale == 200` then reads
`staticmc.transform.matrix.toString()`. Our recomposed matrix has `c = +2`; Flash and
Ruffle report `c = -2` because the skew term flips the sign back.

### Family B — `getBounds(_root)` swapped or undersized after script-set matrix

```
expected: '-60.1,-30.05 60.1,30.05'  [matrix_test.c:1844]   ← 90° rotation with yscale=200
obtained: '-30.05,-60.1 30.05,60.1'                          (xy axes swapped)

expected: '-60.1,-30.05 60.1,30.05'  [matrix_test.c:1868]   ← negative-_xscale + rotation
obtained: '-30.05,-30.05 30.05,30.05'                        (scale not applied — likely
                                                             negative-scale path falls back to
                                                             identity-shaped bounds)
```

The bounds path consumes our `getLocalMatrixForMC` recomposition, so the same skew loss
contaminates all subsequent geometry that depends on it.

## Root cause

Ruffle stores `skew` as a separate cached field on `DisplayObjectBase`
(`~/CC/ruffle/core/src/display_object.rs:280`) alongside `scale_x`, `scale_y`, and
`rotation`. When a matrix is assigned directly via `set_matrix` (`:416`), the four-way
decomposition runs lazily in `cache_scale_rotation` (`:470-501`):

```rust
let rotation_x = atan2(b, a);                   // x-axis vector after transform
let rotation_y = atan2(-c, d);                  // y-axis vector after transform
let scale_x    = sqrt(a*a + b*b);
let scale_y    = sqrt(c*c + d*d);
self.rotation.set(Degrees::from_radians(rotation_x));
self.scale_x.set(Percent::from_unit(scale_x));
self.scale_y.set(Percent::from_unit(scale_y));
self.skew.set(rotation_y - rotation_x);
```

Then when individual scale setters mutate the matrix (`set_scale_y` at `:584-613`),
they recompose c/d using `cos(rot + skew)` / `sin(rot + skew)`:

```rust
let skew = self.skew.get();
let cos = f64::cos(rot + skew);
let sin = f64::sin(rot + skew);
matrix.c = (-sin * value.unit()) as f32;
matrix.d = ( cos * value.unit()) as f32;
```

`matrix()` (the getter at `:412`) returns the stored matrix verbatim — never the
recomposed one — so the original `(a, b, c, d)` is preserved exactly when no individual
setter has touched it.

**Our implementation** in `SWFModernRuntime/src/actionmodern/action.c`:

- `transformMatrixSetter` (`action.c:8070`) computes only `xscale`,
  `yscale`, `rotation`. No `skew`.
- `getLocalMatrixForMC` (`action.c:7670`) uses `bc = -(ys * sin(rot))`,
  `bd = ys * cos(rot)`. No skew term.
- `transformMatrixGetter` (`action.c:8048`) calls `getLocalMatrixForMC` to
  rebuild the matrix on every read. Same code path as `getBounds` /
  `hitTest` consumers, so all share the same bug.

For the `(0, -1, -2, 0)` test case: our setter records `xscale=100`,
`yscale=200`, `rotation=-90`. Reading back, `getLocalMatrixForMC`
recomputes `c = -(2 * sin(-90°)) = -(2 * -1) = +2`. With Ruffle's
`skew = atan2(-c,d) - atan2(b,a) = atan2(2,0) - atan2(-1,0) = π/2 - (-π/2) = π`,
the corrected formula gives `c = -(2 * sin(-90° + 180°)) = -(2 * sin(90°)) = -(2 * 1) = -2`. ✓

## Fix design

### Phase 1 — Add `skew` to MovieClip

`SWFModernRuntime/include/actionmodern/action.h` (struct `MovieClip` at line 19):

```c
float skew;  // radians, cached from direct transform.matrix assignment.
             // 0 for the common case (rotation only). Preserved across
             // _xscale / _yscale / _rotation setters (Ruffle parity).
```

Default-initialize to `0.0f` at every MovieClip creation site:

- `root_movieclip` static initializer (file: search for `root_movieclip = {`)
- `actionFindOrCreateMovieClip` HCALLOC + manual init block
- `getOrCreateLevel` (level MC creation)
- `actionCloneSprite` / `ng_cloneSprite` (duplicateMovieClip)
- `actionAttachMovie` / corresponding tag.c sites
- `createEmptyMovieClip` paths
- Any other HCALLOC'd MovieClip — grep `MovieClip*\s*\w+\s*=\s*HCALLOC`

(HCALLOC zero-fills, so 0.0f is the natural default — but make sure none of those
sites overwrite the field unintentionally.)

### Phase 2 — `transformMatrixSetter` decomposes skew

`action.c:8070-8105`. Replace the existing `xs/ys/rot_deg` block with the
four-way Ruffle decomposition:

```c
double rot_x = atan2(b, a);
double rot_y = atan2(-c, d);
double xs    = sqrt(a*a + b*b);
double ys    = sqrt(c*c + d*d);
mc->xscale   = (float)(xs * 100.0);
mc->yscale   = (float)(ys * 100.0);
mc->rotation = normalizeRotation((float)(rot_x * 180.0 / M_PI));
mc->skew     = (float)(rot_y - rot_x);
mc->as_set_flags |= (1|2|4|8|16);
markTransformedByScript(mc);
```

(Use `M_PI` if defined; fall back to the existing `3.14159265358979323846`
literal pattern used elsewhere in the file.)

### Phase 3 — `getLocalMatrixForMC` + `_render` use skew

`action.c:7670-7704` (`getLocalMatrixForMC`):

```c
double rot      = (double)mc->rotation * M_PI / 180.0;
double skew     = (double)mc->skew;
double cr_x     = cos(rot);
double sr_x     = sin(rot);
double cr_y     = cos(rot + skew);
double sr_y     = sin(rot + skew);
if (fabs(cr_x) < 1e-12) cr_x = 0.0;
if (fabs(sr_x) < 1e-12) sr_x = 0.0;
if (fabs(cr_y) < 1e-12) cr_y = 0.0;
if (fabs(sr_y) < 1e-12) sr_y = 0.0;
ba = xs * cr_x;
bb = xs * sr_x;
bc = -(ys * sr_y);
bd =  (ys * cr_y);
```

Apply the same change to the AS-override branch (lines 7691-7700) and to
`getLocalMatrixForMC_render` (`action.c:7710-7737`) for the float/twips
variant. Without the `_render` change, rendering paths still use the
skewless matrix and the visible transform diverges from the AS-visible
transform.

### Phase 4 — Audit individual property setters

`_xscale` / `_yscale` / `_rotation` setters must **leave skew alone**.
That's already the default for our impl (we don't touch `skew` anywhere
new), but cross-check:

- `actionSetProperty` for properties 4 (xscale), 5 (yscale), 6 (rotation).
- `actionSetMember` MOVIECLIP path for `_xscale`/`_yscale`/`_rotation` keys.
- Any place that does `mc->xscale = ...` / `mc->yscale = ...` /
  `mc->rotation = ...` outside of `transformMatrixSetter` and the
  initialization sites in Phase 1.

If any setter currently zeroes `skew`, that's a bug to remove. Conversely,
**`tagPlaceObject2` placement** (which captures the timeline matrix into
`xscale`/`yscale`/`rotation`) needs to set `skew` to the value implied by
the placed matrix — same decomposition as Phase 2. The timeline matrix is
stored in `transform_data` and consumed via `ng_getMatrixFromEntry`, which
`getLocalMatrixForMC` already prefers when `as_set_flags == 0`. So a
freshly-placed MC with a skewed timeline matrix will read correctly via
`transform.matrix` (since `getLocalMatrixForMC` returns the timeline
matrix verbatim) **but** `_rotation`/`_xscale`/`_yscale` reads return the
wrong values until skew is decomposed at placement time. Decide whether
to:

1. Decompose skew at placement time and stash it on `mc->skew`. Cheaper at
   read time, costs O(1) per PlaceObject2 (we already compute matrix
   decomp lazily for `_rotation` etc.).
2. Lazy-decompose: compute skew on demand when an individual setter fires
   and `as_set_flags` is still empty. Matches Ruffle's
   `cache_scale_rotation` model more closely.

Recommend Option 1 for simplicity unless a regression surfaces — most MCs
never touch the individual setters, so the cost is bounded by the number
of placements.

### Phase 5 — Audit geometry consumers

Anything that consumes `getLocalMatrixForMC` will pick up the skew-aware
matrix automatically. Verify:

- `getBounds` / `getRect` / `pixelBounds` — these compute AABB after
  applying the local matrix, so the skew fix should propagate.
- `hitTest` (the rect-against-rect check) — same.
- `localToGlobal` / `globalToLocal` — same.
- Render path (uses `getLocalMatrixForMC_render`) — same.

Single-line check: the matrix functions are the **only** entry point for
local-matrix data on a script-modified MC. `mc->xscale`, `mc->yscale`,
`mc->rotation` are exposed only via the `_xscale`/`_yscale`/`_rotation`
property getters. No code should reach into those fields and recompose a
matrix without going through `getLocalMatrixForMC`.

### Phase 6 — Regression battery + rebaseline

Run the following locally before commit. Required-pass (must stay green):

**AVM1 transform / drag / bounds (≥18 tests):**
- `display_object_properties`, `display_object_properties_swf6`,
  `mask_reapply`, `frame_size_swf5`, `frame_size_swf7`,
  `movieclip_setmask`, `movieclip_create_text_field`,
  `drag_drop`, `drag_over_from_outside`, `drag_over_without_startdrag`,
  `mouse_hover_events_while_dragging`, `edittext_drag_select`,
  `movieclip_default_state`, `movieclip_get_instance_at_depth`,
  `movieclip_state_values`, `movieclip_invalid_get_bounds_1`,
  `movieclip_invalid_get_bounds_2`, `bitmap_data_thorough/copyChannel`,
  `movieclip_methods_with_loaded_image`, `displacementmapfilter_mappoint_throw_error`.

**Gnash misc-ming / misc-swfc transform-touching:**
- `RollOverOutTest`, `ButtonPropertiesTest`, `mouse_drag_test`,
  `DragDropTest` (already failing; ensure no fresh regression vs the
  current `_results/results_diff.md` baseline), `displaylist_depths_test*`.

**Shumway:**
- `from_shumway/avm1/duplicateMovieClip/dontremove`,
  `from_shumway/avm1/duplicateMovieClip/duplicateMovieClip`,
  `from_shumway/avm1/duplicateMovieClip/samedepth`.

**Target:** `matrix_test` raw match expected to flip from 949/1086 to
≥1080/1086, eliminating Family A (sign of `c`) and Family B (axis-swap
+ negative-scale bounds) failures. Residuals expected: `sin(90°)`
`6e-17` precision (already documented as a separate issue in
`REMAINING_TAIL_TRIAGE.md`'s entry — not addressed by this plan; the
existing `if (fabs(sr) < 1e-12) sr = 0.0;` guard already snaps it to 0
at the rotation-only path, but a script-set matrix with c-component
near `6e-17` would skip that guard. Re-evaluate once Phase 3 lands).

If raw match flips ≥1080/1086 and Ruffle's `output.ruffle.txt` is a
strict superset of our remaining diff (likely since Ruffle tracks skew
correctly and shares any residual Flash-specific FP noise with us), the
test promotes to `ruffle_matched` automatically.

## Risk

- **High blast radius.** Every script-driven transform on every MC consumes
  `getLocalMatrixForMC`. A bug in the formula (sign error, units wrong,
  skew not initialized) regresses widely.
- **Initialization risk.** If `mc->skew` defaults to garbage on any
  creation path, every MC's matrix is corrupted before the first
  `transform.matrix =` assignment. HCALLOC zeroes the field, so this is
  bounded — but verify static initializers (`root_movieclip`) explicitly
  set `0.0f`.
- **Render parity risk.** `getLocalMatrixForMC_render` powers display
  rendering. A mismatch between AS-visible and rendered transform could
  break visual tests (image-comparison tests in `IMAGE_COMPARISON_TESTS.md`).
  Run the strict image battery (~14 tests) before commit.

## Estimated session budget

- Phase 1 (struct field + init audit): 30-45 min.
- Phase 2 (setter rewrite): 15-30 min.
- Phase 3 (getLocalMatrixForMC + _render): 30-45 min.
- Phase 4 (setter audit): 30 min reading + 15-30 min if any zeroing
  bug found.
- Phase 5 (geometry consumer audit): 30 min reading; likely no code change.
- Phase 6 (regression battery + rebaseline): 60-90 min for full local
  battery + verifying matrix_test deltas.

**Total: 4-6 hours**, single session. The change is mechanically simple
once the formula is verified; most of the budget is regression
verification.

## Open questions

1. **Skew on timeline-placed MCs.** Phase 4 Option 1 vs Option 2 — pick
   eagerly at PlaceObject2 vs. lazy on first individual setter. Default
   to eager unless it surfaces a regression. The eager path also makes
   `_rotation` / `_xscale` / `_yscale` read-after-place correct without
   needing `cache_scale_rotation` infrastructure.

2. **Negative scale + rotation interaction.** Test lines 1869-1886 use
   `_xscale = -200` (horizontal flip) with rotations of 0, ±90. Ruffle's
   note in the source (`display_object.rs:489-491`): "a horizontal flip
   could also be a 180 degree skew followed by 180 degree rotation." Our
   atan2-based decomposition has the same ambiguity as Ruffle's, so as
   long as the formulas match exactly, the disambiguation falls out the
   same way. Verify on lines 1869+ specifically.

3. **NaN handling.** Ruffle special-cases NaN scale/rotation (treats as 0
   for matrix calc but reports as NaN to AS). Our `transformMatrixSetter`
   already has `if (isnan(...)) ... = 0.0` guards on the input matrix
   components, but the `xscale`/`yscale`/`rotation` writes don't guard.
   Out of scope for this plan unless `matrix_test` exercises NaN — quick
   grep of the gnash test source for `NaN` confirms it doesn't.

## References

- Ruffle source — matrix decomposition / skew tracking:
  - `core/src/display_object.rs:280` (struct field)
  - `core/src/display_object.rs:412-419` (matrix getter / setter)
  - `core/src/display_object.rs:470-501` (`cache_scale_rotation`)
  - `core/src/display_object.rs:584-613` (`set_scale_y` recompose)
  - `swf/src/types/matrix.rs:64-72` (pure rotation matrix)

- Memory note: `project_matrix_skew_finding.md` (recorded 2026-05-07).

- Triage entry: `REMAINING_TAIL_TRIAGE.md` "matrix_test (87.4%, 949/1086)
  — multi-issue".
