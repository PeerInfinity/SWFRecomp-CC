# w2-gfx-acid-shapes-aabb — AVM2 runtime `Graphics` stroke bounds (`shape_bounds` / `edge_bounds`)

**Session 17, wave 2 (FOLLOW-UP wave; TRACE axis with a pixel side).**
**Worktree:** `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a749e8d27f7b9364d`
**Base:** `6d2b64fa2` (master, 14 merged s17 patches). All before/after numbers
below are measured **locally against that HEAD**, `--mode=graphics`, via
`git diff` / `git apply -R` legs (never `git stash`).

## NEW FILES (stage these by name — `git add -u` will drop them)

**No new source files.** The patch touches two already-tracked files:

```
SWFModernRuntime/include/avm2/avm2_globals.h |   8 +
SWFModernRuntime/src/avm2/avm2_display.c     | 151 ++++++++++++++++++++++----
```

The two deliverables are new files under
`SWFRecompDocs/plans/session17-fanout-reports/`:

- `w2-gfx-acid-shapes-aabb.patch`
- `w2-gfx-acid-shapes-aabb-report.md` (this file)

---

## VERDICT — **GO**

| | |
|---|---|
| **Trace flips** | **+1** — `from_shumway/acid/acid-shapes` `output_mismatch` → **PASS** (0/120 → **120/120** matching lines) |
| **Trace line gains, no flip** | `avm2/displayobject_getrect` **9/16 → 11/16** (7 mismatches → 5) |
| **Pixel band moves** | `from_shumway/acid/acid-shapes` **92 808 → 42 012** (−54.7 %); `avm2/displayobject_getbounds_shape` **28 348 → 22 290** (−21.4 %); `from_shumway/acid/acid-shapes-testing` **48 033 → 44 661** (−7.0 %) |
| **Pixel flips** | 0 (all three rows are `max_outliers = 0` / far-from-budget) |
| **Regressions** | **none.** 26 `avm2` bounds/graphics/hit-test rows + 8 `from_shumway/acid` rows graded; standing render canary **61/61 IDENTICAL, 0 status changes** |
| **Premise** | **CONFIRMED on mechanism, PARTIALLY REFUTED on side-effects** — see "Refutations" |
| **Blast radius** | runtime-only, AVM2 only. AVM1's own drawing AABB (`action.c drawingUpdateBounds`) is untouched and has the identical gap (lead recorded below) |

---

## Mechanism

Ruffle's `Drawing` (`core/src/drawing.rs`) keeps **two** boxes, not one:

* `shape_bounds` — every path point grown by the active stroke's half-width
  (`stretch_bounds`, `drawing.rs:456`: `let radius = stroke_width / 2;`,
  `Twips` integer division, so a hairline of width 0 contributes **zero**).
* `edge_bounds` — the same points with `Twips::ZERO` as the stroke width.

`Drawing::self_bounds(include_strokes)` picks between them, and
`BoundsMode` (`display_object.rs:914`) decides which caller gets which:

| caller | mode | strokes |
|---|---|---|
| `getBounds`, `width`, `height`, `hitTestObject`, `transform.pixelBounds`, AVM1 `_width`/`_height`/`getBounds` | `Script` | **included** |
| AVM2 `DisplayObject.getRect` **only** | `ScriptWithoutStrokes` | excluded |
| rendering / hit testing | `Engine` | included |

Our runtime kept **one** box (`Avm2DisplayObjectExt.draw_*`, fed by
`draw_union_point`, `avm2_display.c:~7934`), unioned raw path points, and bound
**`getBounds` and `getRect` to the same function** (`do_get_bounds`). So the
half-width was missing everywhere and `getRect` over-reported wherever a stroke
existed.

`acid-shapes` draws every one of its 120 shapes at runtime through
`graphics.beginFill / lineStyle(4, …) / moveTo / lineTo / curveTo / drawCircle /
drawEllipse / drawRoundRect`, then traces `shape.width shape.height`. Thickness
4 → `Twips::from_pixels(4) = 80` → `radius = 40 tw = 2 px` per side → **+4 on
each axis**, which is exactly the `20 30` vs `24 34` the whole file was off by.

### Patch shape (5 pieces, all self-localised)

1. **Header** (`avm2_globals.h`, trailing fields on `Avm2DisplayObjectExt`):
   `draw_edge_valid` + `draw_exmin/exmax/eymin/eymax` — the `edge_bounds` box
   beside the existing `draw_*` (now the `shape_bounds` box).
2. **`Avm2GraphicsExt.clw_bnd`** (trailing field): the stroke width used for
   *bounds*. `clw` is deliberately clamped **up** to a nominal 1 px so a
   hairline still rasterises; Ruffle's bounds use the raw clamped thickness, for
   which a hairline is exactly 0. Keeping them apart is what stops
   `lineStyle(0)` from inflating `getBounds` by half a pixel per side.
3. **`draw_union_shape_tw` / `draw_union_edge_tw` / `draw_union_stroke`**
   replace `draw_union_point`'s single box. `gfx_stroke_radius_tw()` reproduces
   `stroke_width / 2` with `twips_from_pixels` (already truncating, matching
   `Twips::from_pixels`) and C integer division. The 10 pen call sites
   (`moveTo` / `lineTo` / `curveTo` / `cubicCurveTo` / `drawRect` /
   `drawRoundRect(Complex)` / `drawCircle` / `drawEllipse`) now pass the
   `Avm2GraphicsExt`; `video_init`'s two intrinsic-box points keep the
   stroke-free `draw_union_point`.
4. **`gfx_line_style` thickness rules** aligned with Ruffle
   `globals/flash/display/graphics.rs:353` — **NaN ⇒ no stroke at all** (was: a
   1 px hairline), everything else **clamped 0..255**. This is the same rule
   `gfx_apply_stroke_carrier` (the `GraphicsStroke` carrier) already applied, so
   the patch removes an internal inconsistency rather than inventing a rule.
   `gfx_reset` / `gfx_clear` reset `clw_bnd` and the edge box.
5. **`do_get_bounds` → `do_get_bounds_mode(act, no_strokes)`**, with
   `do_get_bounds` / **new `do_get_rect`** wrappers, and `getRect` re-bound to
   `do_get_rect`. The mode reaches `display_self_bounds` through a file-static
   (`g_bounds_no_strokes`) set immediately before `bounds_with_transform` and
   cleared immediately after — deliberately, so that `bounds_with_transform`'s
   17 call sites (owned by four other agents' regions this session) stay
   textually untouched. The walk between set and clear cannot throw.

`char_self_bounds` is **unchanged** in both modes: `Avm2CharInfo` only carries
`ShapeBounds`, so a DefineShape character still reports stroke-inclusive bounds
to `getRect`. That is the one residual (below), and it is recompiler-side.

---

## Before/after ledger (local, `--mode=graphics`, same worktree, A/B by `git apply -R`)

### Headline

| test | axis | before (`6d2b64fa2`) | after | Δ |
|---|---|---|---|---|
| `from_shumway/acid/acid-shapes` | **trace** | `output_mismatch`, **0/120** matching | **`PASS`, 120/120** | **FLIP** |
| `from_shumway/acid/acid-shapes` | image `output` | fail, **92 808** outliers (tol 200 / max 0) | fail, **42 012** | **−50 796 (−54.7 %)**, no flip |
| `avm2/displayobject_getrect` | trace | `output_mismatch`, **9/16** (7 diffs) | `output_mismatch`, **11/16** (5 diffs) | **+2 lines** |

`acid-shapes` at the s16 grading run `31877239992` was 78 982 outliers; T10
(`#2007 targetCoordinateSpace`, already merged) raised it to 92 808 by getting
the shapes drawn at all. 42 012 is therefore also a **−36 970 improvement on the
s17 gfx board's published number** for the `blank_render` M8 row.

### Other rows that moved

| test | axis | before | after | note |
|---|---|---|---|---|
| `avm2/displayobject_getbounds_shape` | image | 28 348 | **22 290** | −6 058 (−21.4 %); trace `PASS` both legs |
| `from_shumway/acid/acid-shapes-testing` | image | 48 033 | **44 661** | −3 372 (−7.0 %); trace **unchanged** at 36/120 — different mechanism (see residuals) |

### Rows verified INERT (before == after, both legs measured locally)

`avm2/bounds_mode` (`ruffle_matched` both legs) · `avm2/graphics_gradients`
(image 299 → 299) · `avm2/displayobject_hittestpoint_boundary` (trace `PASS`,
image 812/900 `PASS`, both legs).

### Canary sweep — trace + image, `--mode=graphics`, all `PASS`/unchanged

26 `avm2` rows (after leg; every one at or above its CI baseline status):

| row | after | CI baseline (`aeebf9ede`) |
|---|---|---|
| `bounds_mode` | `ruffle_matched` | `output_mismatch` (moved by a sibling, inert to me) |
| `button_bounds`, `empty_bounds`, `edittext_bounds_scale`, `displayobject_getbounds_shape` | `PASS` | `pass` |
| `graphics_simple_shapes`, `graphics_path`, `graphics_round_rects`, `graphics_bad_direct_commands`, `graphics_direct_commands`, `graphics_gradients`, `graphics_gradients_nulls`, `graphics_bitmaps`, `graphics_bitmap_fill`, `graphics_draw_triangles` | `PASS` | `pass` |
| `graphics_draw_path` | `ruffle_matched` | `ruffle_matched` |
| `displayobject_hittestobject`, `displayobject_hittestpoint`, `displayobject_hittestpoint_root`, `displayobject_hittestpoint_boundary`, `movieclip_hittest`, `button_hittest`, `hittest_morph`, `bitmapdata_hittest`, `bitmapdata_hittest_threshold` | `PASS` | `pass` (boundary was `output_mismatch`; a sibling fixed it) |
| `displayobject_getrect` | `output_mismatch` 11/16 | `output_mismatch` 2/16 |

8 `from_shumway/acid` rows: `acid`, `acid-small`, `acid-chars`, `acid-child`,
`acid-clip`, `acid-scale`, `acid-stroke-0` all `PASS` with image numbers
**byte-identical to the CI baseline** (`acid` 18 comparisons 8677/11845/…,
`acid-scale` 320, `acid-stroke-0` 52 786, `acid-small` 25 989/25 959) —
i.e. provably inert. `acid-shapes` flips; `acid-shapes-testing` unchanged on
trace, image improved.

**Standing render canary** (`render_canary.py capture/compare` over
`render_canary_tests.txt`, `-P 2`, `--timeout 5400`, both legs captured in this
worktree with local Dawn):

```
RENDER CANARY  before=before  after=after   29 tests / 61 comparisons
  IDENTICAL    61
  DIFFERS       0
  APPEARED      0   VANISHED 0   NO_RENDER 0
  TRACE STATUS CHANGES: (none)
  IMAGE STATUS CHANGES: (none)
```

**Canary blind spot (stated per the s15 rule):** the standing set contains
**no** member that calls AVM2 `Graphics.lineStyle` and then reads a bounds-derived
value — its one runtime-drawing member is `avm1/mask_with_drawing` (AVM1 route,
which this patch does not touch). The covering tests I graded by hand instead are
`avm2/displayobject_getrect`, `avm2/graphics_*` (10 rows), `avm2/*hittest*`
(9 rows) and `from_shumway/acid/acid-shapes{,-testing}`.

---

## Refutations / premise attacks

1. **"`getBounds` vs `getRect`" — the brief's alternative was the *right half* of
   the answer, not an alternative.** `acid-shapes` calls `getBounds`, so the
   stroke-inclusive fix alone flips it. But `avm2/displayobject_getrect` calls
   **both** on the same runtime-drawn `MovieClip`
   (`Test.as:29-38`: `lineStyle(3, 0x00FF00); drawCircle(20,20,8)`), and Ruffle's
   expected pair is `(10.5,10.5,19,19)` / `(12,12,16,16)`. Implementing only
   the shape box would have fixed lines 11/13 and **broken** 12/14 — exactly what
   `w2-avm2-display`'s hand-off predicted. Implementing both boxes is what makes
   the net **+2 with 0 breaks**. The hand-off's "12/14 break" prediction is
   therefore **refuted as a necessary cost**.

2. **"Hairline (width 0) strokes still count 1 twip?" — NO.** `stretch_bounds`
   computes `stroke_width / 2` as `Twips` integer division; `Twips(0)/2 = 0`.
   A `lineStyle(0)` contributes **nothing** to bounds. Our `clw` is clamped to a
   nominal 1 px for *rasterisation*; reusing it for bounds would have added
   half a pixel per side to every hairline drawing in the corpus. Hence the
   separate `clw_bnd` field.

3. **The `blank_render` M8 row does NOT flip on the pixel axis, and could not
   have.** After the trace fix the residual 42 012 outliers are dominated by two
   *tessellation* gaps visible in `output.difference.png`, neither of them
   bounds-related: (a) **`drawRoundRect` / `drawRoundRectComplex` ignore their
   corner radii entirely** — `gfx_draw_rect`'s own comment says
   *"round-rect corner radii are approximated as a plain rect this tranche"* —
   so the whole lower-left block of the frame is squares where Ruffle draws
   rounded rects and circles; (b) stroke join/cap geometry on the zig-zag
   polygon rows. The check is `tolerance 200 / max_outliers 0`, so nothing short
   of near-byte-exactness flips it. **M8 should be re-labelled on the pixel board
   from "trace-first" to "round-rect tessellation", and it is not a bounds item.**

4. **Most of the `avm2/graphics_*` image movement this session is NOT mine.**
   Nine of the ten `graphics_*` image numbers I measured (`bad_direct_commands`
   0, `bitmap_fill` 194, `direct_commands` 587, `draw_path` 204,
   `draw_triangles` 1812, `bitmaps` 37 650, `gradients_nulls` 0,
   `simple_shapes` 240) reproduce `w2-gfx-drawgraphicsdata`'s and
   `w2-gfx-smalls`' published after-numbers **to the digit**, and the explicit
   before-leg on `graphics_gradients` came back 299 → 299. This patch is
   **provably inert** across that whole family — which is the point: a bounds
   change that moved tessellated pixels would have been a bug.

---

## Residuals (what is still wrong, and who owns it)

| residual | evidence | completion mechanism |
|---|---|---|
| `avm2/displayobject_getrect` lines 4, 6, 8, 10, 16 | all five are `getRect` on **DefineShape / MorphShape characters**, where Ruffle uses the tag's `EdgeBounds` and we only have `ShapeBounds` in `Avm2CharInfo` | **recompiler-side**: emit `EdgeBounds` alongside `ShapeBounds` in `Avm2CharInfo` (`SWFRecomp/src/swf.cpp`), then let `char_self_bounds` honour `g_bounds_no_strokes`. That is ~10 lines on top of this patch and flips the row to 16/16 — the single cheapest +1 left in this family |
| `from_shumway/acid/acid-shapes` image (42 012) | round-rect radii unimplemented + stroke joins | `gfx_draw_rect` / `gfx_draw_round_rect_complex` in the Graphics **tessellation** region (`w2-gfx-drawgraphicsdata`'s area), emitting Ruffle's `draw_round_rect_internal` curve set. Bounds are already correct for it (a round rect's AABB *is* the rect) |
| `from_shumway/acid/acid-shapes-testing` trace 36/120 | unchanged by this patch; its rows are `(x=0,y=0,w=28,h=42)` for everything where Ruffle reports five distinct boxes — a **scale/`width`-setter** family, not a stroke family | separate triage slot; start from the fact that we report the *same* box for every variant |
| **AVM1 has the identical gap** | `action.c:28708 drawingUpdateBounds` unions raw points with no half-width, exactly like the AVM2 helper did. Any AVM1 `lineStyle` + `_width`/`_height`/`getBounds` row is off by the thickness | port items (2)+(3) of this patch to `MovieClip.draw_*` in `action.c` (owned this session by `w2-crossvm-legE` / `w2-sound-load`; needs its own slot). **Unpriced** — I did not grade the AVM1 corpus for it |

---

## Exact patch scope

| file | region | change |
|---|---|---|
| `SWFModernRuntime/include/avm2/avm2_globals.h` | `Avm2DisplayObjectExt`, after `draw_xmin…` | +5 trailing fields (`draw_edge_valid`, `draw_exmin/exmax/eymin/eymax`) |
| `SWFModernRuntime/src/avm2/avm2_display.c` | `display_self_bounds` (~:705) | mode-select shape vs edge box; new file-static `g_bounds_no_strokes` |
| | `do_get_bounds` (~:3894) | → `do_get_bounds_mode(act, no_strokes)` + `do_get_bounds` / **new** `do_get_rect` wrappers; `getRect` re-bound (~:15600) |
| | `Avm2GraphicsExt` (~:7913) | +1 trailing field `clw_bnd` |
| | `draw_union_point` (~:7934) | split into `draw_union_shape_tw` / `draw_union_edge_tw` / `draw_union_point` / **new** `gfx_stroke_radius_tw` / `draw_union_stroke` |
| | `gfx_clear`, `gfx_reset`, `gfx_line_style`, `gfx_apply_stroke_carrier` | edge-box reset, `clw_bnd` maintenance, NaN/clamp rules |
| | 10 pen call sites (`gfx_move_to` … `gfx_draw_ellipse`) | `draw_union_point(ext,…)` → `draw_union_stroke(ext, g, …)` |

**No textual overlap** with the live siblings: nothing here is in the
mask/stencil path (`w2-gfx-cab-mask-stencil`), the EditText path
(`w2-gfx-edittext-bg`), `compose_children`, the filters region, the hit-test
region, or `gfx_draw_graphics_data`. The only shared-line risk is the single
`Rect d = {…}` initialiser inside `display_self_bounds`, in
`w2-avm2-display`'s (already-merged) transform/bounds region.

## Tests run (all `--mode=graphics`, `SWFRECOMP_COMPILE_TIMEOUT=2400`, `-P 2` max)

* after leg: 26 `avm2` rows + 8 `from_shumway/acid` rows + canary capture (29 tests / 61 PNGs)
* before leg (`git apply -R`): 7 targeted rows + canary capture (29 / 61)
* `render_canary.py compare before after` → 61 IDENTICAL / 0 DIFFERS
* No full suites; no commits; no pushes.
