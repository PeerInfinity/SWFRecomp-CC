# s25 w1-pixel-drawing: drawing API, strokes, bitmap fills, DrawingApiTest

**New files:** this report and `w1-pixel-drawing-prototype.patch` (487 lines, `git diff origin/master -- SWFModernRuntime`,
2 files: `actionmodern/action.c`, `libswf/tag.c`). The source is reverted in this commit.

Box: cloud, lavapipe. `SETUP_STATUS` all OK. Upstream test SHA **`3ac8dcb07`** (depth-1 download at the same
moment as my blobless Ruffle clone, HEAD `3ac8dcb07`). Code base `ca14fe02` (= `746c39489` runtime).

**Fidelity proven on every PNG row in the brief (21/21):** my clean-master render md5 equals CI's actual PNG on
`origin/ruffle-image-results` for all of them (table in §Baseline). So every absolute verdict below is CI-grade.

## Verdicts (GO/NO-GO, priced flips)

| # | group / row | verdict | priced flips (graphics) | prototype |
|---|---|---|---|---|
| A | **Runtime drawing placement: z-order + transforms** (`visual/drawing_api/drawing_order`, `visual/cache_as_bitmap/drawing_api`) | **GO** | **+2 pixel**: `drawing_order` 6658 → **0** (max 0), `cache_as_bitmap/drawing_api` 2295 → **0** (max 0) | measured |
| B | **Translucent runtime strokes double-blend at joins** (`avm1/movieclip_line_gradient_style`) | **GO as band, NO-GO as flip** | 0. 1023 → **33** (−97 %); the 33 are a different mechanism (gradient seam/hard-stop sampling, §B) | measured |
| C | **DrawingApiTest hitTest** (trace) | **GO for 7 of 12 lines; plan of record REFUTED** | 0 flips (row stays `output_mismatch` 88/93, was 81/93). The other 5 lines + 2 trailing lines are AVM1 scope/dispatch, not hitTest geometry | measured |
| D | `avm2/graphics_direct_commands` | HOLD (cheap measurement) | 0–1. `Graphics.copyFrom` is a **`gfx_noop`** (`avm2_display.c:17875`); the blue/red dot is that, ~314 ch at every tol. Tol-64 (589/300) would clear; tol-32 (2503/1800) needs the dash residual too | none (source frozen during sweep) |
| E | `avm2/bitmapdata_draw_filters` | NO-GO here → **filters slot** | 0 here. It is not a drawing row: **AVM2 `ColorMatrixFilter` is not rendered at all** (off-diagonal G←B), on stage AND in `draw()` | none |
| F | scale-mode strokes (`acid-stroke-0` KF tol 0, `strokes/scale` KF tol 5) | NO-GO (L) | 0 | none |
| G | `from_gnash/shape_test` (KF, tol 50 / max 0) | NO-GO (unchanged from s24 §4) | 0 | none |
| H | `from_gnash/BeginBitmapFill` | NO-GO here → **text slot** | 0. 666 of its 939 outliers are the xtrace device-font label | none |
| I | the rest (one line each) | see §I | 0 | none |

**Total GO: +2 pixel flips** (A, md5-exact), plus a 97 % band (B) and a 7-line trace improvement on a known_failure
row (C). The whole prototype was swept (§Sweep).

## Baseline and fidelity

All renders from clean `origin/master` (`ca14fe02`), `render_canary.py capture`, graphics. "md5" is the first 8
hex of our PNG; FIDELITY-OK means it equals CI's `output.actual.png` on `origin/ruffle-image-results` byte for byte.
Brief discrepancies (not drift: same PNG as CI): `BeginBitmapFill` is 939, not 839;
`applyfilter_destpoint_edges` is 149477, not 149442; `pixelbender_dithering` is 1297344, not 1277415 (this
matches the s24 report's own after-number).

| row | md5 | vs CI actual | message (first failing check) |
|---|---|---|---|
| `avm1/movieclip_line_gradient_style` | 0a7b394b | FIDELITY-OK | 1023 outliers exceed limit of 0, max difference 209 |
| `avm2/away3d_advanced_shallow_water_demo` | 48849177 | FIDELITY-OK | 1326765 outliers exceed limit of 400, max difference 255 |
| `avm2/bitmapdata_applyfilter_destpoint_edges` | 9930264b | FIDELITY-OK | 149477 outliers exceed limit of 35, max difference 238 |
| `avm2/bitmapdata_draw` | 6f11cf21 | FIDELITY-OK | 753 outliers exceed limit of 600, max difference 255 (check tol 1 |
| `avm2/bitmapdata_draw_filters` | fec226c2 | FIDELITY-OK | 14400 outliers exceed limit of 0, max difference 255 |
| `avm2/graphics_direct_commands` | f5d9c1ac | FIDELITY-OK | 2503 outliers exceed limit of 1800, max difference 255 (check tol |
| `avm2/graphics_draw_path` | 07d7ce1c | FIDELITY-OK | 664 outliers exceed limit of 0, max difference 255 |
| `avm2/graphics_draw_triangles` | 64fc90d3 | FIDELITY-OK | 1812 outliers exceed limit of 0, max difference 255 |
| `avm2/graphics_gradients` | 6dc3140f | FIDELITY-OK | 3685 outliers exceed limit of 0, max difference 255 |
| `avm2/pixelbender_dithering` | 3153e740 | FIDELITY-OK | 1297344 outliers exceed limit of 19929, max difference 255 |
| `avm2/sprite_with_frames` | 8264a6a6 | FIDELITY-OK | 6342 outliers exceed limit of 0, max difference 255 |
| `avm2/stage3d_fractal` | 27190aff | FIDELITY-OK | 1104108 outliers exceed limit of 100, max difference 255 |
| `avm2/stage3d_raytrace` | 67d4f13a | FIDELITY-OK | 660000 outliers exceed limit of 10, max difference 255 |
| `from_gnash/misc-ming.all/BeginBitmapFill` | 642e53c8 | FIDELITY-OK | 939 outliers exceed limit of 100, max difference 255 |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | fb80304c | FIDELITY-OK | 1782 outliers exceed limit of 0, max difference 255 |
| `from_gnash/misc-ming.all/shape_test` | a5cb2877 | FIDELITY-OK | 15994 outliers exceed limit of 0, max difference 255 |
| `from_shumway/acid/acid-shapes-testing` | a275e1f8 | FIDELITY-OK | 41339 outliers exceed limit of 0, max difference 255 |
| `from_shumway/acid/acid-stroke-0` | 48cfef43 | FIDELITY-OK | 52702 outliers exceed limit of 0, max difference 255 |
| `visual/cache_as_bitmap/drawing_api` | 9036a83c | FIDELITY-OK | 2295 outliers exceed limit of 0, max difference 255 |
| `visual/drawing_api/drawing_order` | fffea066 | FIDELITY-OK | 6658 outliers exceed limit of 0, max difference 255 |
| `visual/simple_shapes/strokes/scale` | 2b515a5f | FIDELITY-OK | 19308 outliers exceed limit of 0, max difference 255 |


## A. Runtime drawing placement (GO, +2)

Three defects, all in how AVM1 Drawing-API geometry reaches the GPU, not in tessellation.

1. **A dynamic clip whose dynamic chain ends at a timeline-placed sprite loses that sprite's world matrix.**
   `tag.c::apply_dynamic_mc_transforms` composes only the fully-dynamic chain (`dyn_mc_compose_parent_chain` stops
   at `display_obj != NULL`). `cache_as_bitmap/drawing_api` does `this.createEmptyMovieClip("line_mc")` inside a
   sprite placed at (139,149), so the lines drew at the stage origin (+140,+150 off). With the placed ancestor's
   world composed on top, 2295 → 604. The remaining 604 were the ancestor's **cacheAsBitmap blit snap**
   (`cab_snap_delta`, +0.3/+0.25 px here), which Ruffle applies to the whole cached subtree. Adding that snap
   delta brings it to **0 / max 0**.
2. **A clip WITH a display entry draws its Drawing-API paths through `mc->last_transform_id`, the baked LOCAL
   slot.** An `attachMovie`'d clip keeps slot 0 (identity), so `drawing_order`'s `mc.moveTo(-250,250);
   mc.lineTo(250,-250)` drew off-stage. The prototype gives such clips (AS-moved, or not parented to `_root`) a
   per-tick world slot built from `getConcatMatrixForMC`.
3. **Z-order: every Drawing-API path is painted in one global pass AFTER the whole display list**
   (`actionIterateDrawings` from `tagShowFrame`/`tagRerenderFrame`). Flash/Ruffle paint a clip's Graphics BENEATH
   its children (`MovieClip::render_self`: drawing, then children). The prototype draws a clip's paths inline right
   before its child list, and the global pass skips clips already drawn. The hooks are the `CHAR_TYPE_SPRITE`
   arms of `render_single_object` and `render_display_list`, both root-attach passes (`render_attached_child` and
   `tagRerenderFrame`'s own copy; the capture is taken from `tagRerenderFrame`), and the root clip before the root
   loop in both twins.
4. **Bare `lineStyle(...)` / `lineTo(...)` in a frame script did nothing** (the s20 lead): with no WITH scope the
   drawing-name dispatch in `actionCallFunction` had no target. It now falls back to `actionGetBaseClip()`
   (else `_root`). s21's refutation ("routing to the base clip rendered nothing") was true at the time because
   the root clip's drawing is in no render pass; with (3) it is drawn before the root list.

`drawing_order` needed 2 + 3 + 4 together: 6658 → 5730 (2) → 3570 (3 + 4, root green line correct) → **0**
(attached clip inline). `cache_as_bitmap/drawing_api` needed only 1.

**Wave-2 cleanup the prototype skips:**
- Link a display entry to its MovieClip instead of the unique-name fallback in `actionFindMCForDisplayObj`:
  `attachMovie` keeps a standalone `display_obj` that is not the rendered entry.
- Use `compute_mc_world_xform` (the renderer's own) in place of `getConcatMatrixForMC` for the world slot.
- Decide the masked-drawing route; `actionIterateMaskedDrawings` is untouched, so masked clips keep the old order.

Owner functions:
- `tag.c`: `apply_dynamic_mc_transforms`, `render_single_object` (SPRITE arm), `render_display_list` (SPRITE arm),
  `render_attached_child`, `tagRerenderFrame`, `tagShowFrame` (one line each before the root loop).
- `action.c`: `actionIterateDrawings`, `actionCallFunction` (drawing-name WITH block), plus new exports
  `actionGetPlacedAncestorWorldMatrix`, `actionGetMCWorldMatrixTwips`, `actionDrawingInlineReset`,
  `actionFindMCForDisplayObj`, `actionRenderMCDrawingsInline`, `actionGetRootMC`.

**Overlap with `n-play-game`:** I touch `actionCallFunction` in two places: the drawing-name WITH dispatch, and
the bare `getBounds/getRect/hitTest` → `actionCallMethod` delegation (§C). That is AVM1 call dispatch, next to
mouse/button code but not in it. Wave 2 should merge after `n-play-game` lands.

## B. Translucent runtime strokes (band 1023 → 33)

All 1023 outliers sit on the four corners of the 7 cells whose gradient alphas are < 100. Our stroke is
per-segment quads plus join wedges (`action.c::drawingBuildStroke`). They overlap at every corner, and a
translucent stroke blends twice there: (110,10) golden (255,138,140), ours (255,78,83).

Flash fills the stroke outline once. The prototype adds `drawingUnionTranslucentStroke`: when `line_a < 1`, or any
line-gradient ramp alpha is < 255, it re-tessellates the triangle soup with libtess2. Each triangle is normalised
CCW, then `TESS_WINDING_NONZERO` gives the union. Opaque strokes are untouched, so they stay md5-stable.

Result: **1023 → 33**. The 33 are:
- cell 9 (`radial`, `repeat`, `linearRGB`, focal 0.8): 1 px seam picks the wrong side of the repeat, e.g.
  (455,111) golden red, ours blue;
- cell 10 (`reflect`, ratios [50,50], a hard stop): ±8–40 on the step;
- a few ±7–9 B-channel pixels.

That residual is gradient seam/step sampling, the same family as `graphics_gradients`. No flip, because the row
is tol 6 / max 0. **Completion mechanism:** an exact repeat/reflect seam and hard-stop rule in the gradient
sampler (GPU), checked against `graphics_gradients`' Flash golden.

## C. DrawingApiTest (trace, 81/93 → 88/93 measured; plan of record refuted)

`DRAWING_API_HITTEST_PLAN.md`'s three phases ("zshape returns undefined", "inv4/inv8 sign", "e corner pixel") do
not describe today's 12 lines. Measured per line:

| line | expected | mechanism | prototype |
|---|---|---|---|
| 227/230/231 `zshape.hitTest` | true | pending stroke-only path: we ran the FILL winding test on an open polyline. Ruffle tests `current_line` by stroke distance (`shape_utils::draw_command_stroke_hit_test`, round caps/joins, min width 1 screen px) | **fixed** (C port `drawingCmdStrokeHitTest`) |
| 680 `!e.hitTest` | false | `beginFill()` with no argument starts no fill in Flash/Ruffle (`set_fill_style(None)`); we set `has_fill = 1` (both the CallMethod arm and the WITH-dispatch arm) | **fixed** |
| 398 `!inv4`, 575 `!inv8` | false | **Drawing-API default fill rule is EvenOdd** (Ruffle `Drawing::new`: `default_winding_rule: FillRule::EvenOdd`). We tessellate (`drawingFinalizePath`) and hit-test NONZERO. The in-code comment "NonZero … Flash's drawing-API default" is wrong | **fixed** (TESS_WINDING_ODD + `winding & 1`) |
| 365 `!inv3` | false | the pending-fill winding test auto-closed only the LAST sub-path; every `moveTo` closes the previous one | **fixed** |
| 126 `hitTest(376,139,true)` inside `with (a)` | true | the call never reaches the hitTest arm (instrumented). Bare `hitTest` is delegated to `g_current_context` (`actionCallFunction`, `_bm_match`). I retargeted it to the WITH clip, but it is still not reached: an earlier scope-chain arm resolves the name first | open: AVM1 call dispatch |
| 256/257/264/266 `x.hitTest` | true | **name resolution, not hitTest**: `x` never reaches the MovieClip hitTest arm (instrumented), and even the BOUNDS form fails. The script sets `x = 223` inside `with (zshape)` nested in `with (a)`, then `createEmptyMovieClip("x")` inside `with (a)`. Flash resolves `x` through `with (a)`'s child clip before the timeline variable | open: AVM1 scope (Ruffle `stage_object::get_property` order: own props, then child by name) |
| +2 trailing `FAILED: delete this.onEnterFrame returned false` | absent | AVM1 `delete` on an MC's `onEnterFrame` returns false, so the handler keeps running. Ruffle/Flash print nothing in 30 ticks | open: AVM1 delete semantics |

Row status: `known_failure = true`, 7 diff lines + 2 extra remain, so no promotion is possible yet.
**Plan-of-record repricing:**
- Phases 1–3 as written are obsolete. The geometry work is done in this prototype (~110 LOC).
- What is left is two AVM1 scope/dispatch items (S each, but in shared `actionCallFunction`/`actionGetVariable`,
  so the sweep risk is high) plus `delete` semantics (S).
- The plan should be rewritten to those three items.

The even-odd change also alters RENDERING of self-intersecting AVM1 drawings: Flash-correct, and sweep-checked.

## D–I. Pricing of the other rows

- **D `graphics_direct_commands`** (all 4 checks fail: 6597/4264/2503/589 vs 6000/4000/1800/300):
  - `Graphics.copyFrom` is registered as `gfx_noop`. The `partial` shape should inherit the dash path and the
    pending `beginFill(0xFF0000FF)` (low 24 bits = blue) and draw its r=10 circle blue; ours keeps its own
    `beginFill(0xFFFF0000)` (red).
  - Price: copyFrom (deep copy of `Avm2GraphicsExt` paths + pending state), ~60 LOC. It removes ~314 channels at
    every tolerance.
  - tol-64 589 → ~275 clears its 300. tol-0/16/32 (597/264/703 over) also need the translucent `LineScaleMode.NONE`
    square-cap dashes. Probably the AVM2 twin of B (double-blend at overlaps; AVM2 builds strokes in
    `avm2_display.c`, untouched here). HOLD: measure copyFrom + an AVM2 union twin together.
- **E `bitmapdata_draw_filters`** 14400 = exactly 2 squares × 3600 px × 2 channels:
  - The `ColorMatrixFilter` (G←B) is dropped by `avm2_filter_renderable` (`avm2_display.c` ~19960: colorMatrix not
    covered).
  - The timeline route folds ColorMatrix into a cxform (`tag.c::build_filter_chain`), which cannot express an
    off-diagonal term.
  - Needs a real colour-matrix pass on stage (GPU) and in `draw()` (CPU). Ruffle's own sidecar fails the `draw()`
    half (KF), so Flash is the oracle. Price M. Owner: filters.
- **F scale-mode strokes.** `acid-stroke-0` (52702, KF, tol 0): every column renders the same stroke width per
  row, while the golden varies by `LineScaleMode`/`NoHScale`/`NoVScale` under scaled and sheared parents.
  `strokes/scale` (19308, KF, tol 5) has three mechanisms:
  - noScale diagonals drawn scaled;
  - a coarse ~16-gon circle: the recompile-time flattening tolerance is applied in local units, then scaled up;
  - square-cap nubs at the rect corners.
  - Both rows are KF with zero budgets, so only bands are possible. L.
- **G `shape_test`:** s24 §4 stands (NO-GO, 0 flips). The floor is whole missing Ming shapes (the left green
  glyph pair and bar; the square outlines are hairline-colour ties). Completion: diagnose the Ming fill0/fill1
  edge case in the recompiler shape converter.
- **H `BeginBitmapFill`:** the brief says 839; the measured CI-identical row is 939 / limit 100 at tol 50. By region:
  - 666 xtrace label (device font: text slot);
  - 231 rotated bitmap-fill parallelogram edges;
  - 42 elsewhere.
  - Even a perfect bitmap edge leaves 708 > 100. NO-GO here.
- **I one-liners:**
  - `graphics_draw_triangles` (1812, KF):
    - an aliased diagonal tie (1 px stair offset on every diagonal);
    - drawTriangles culling/index semantics: one golden triangle is a full square in ours;
    - a uvt/colour row drawn solid magenta where Flash interleaves magenta/cyan triangles.
    - M, needs Flash oracle.
  - `graphics_draw_path` (664, re-goldened to Flash, ruffle_matched): **live**, but the whole residual is the 1-px
    diagonal stair tie of Flash's aliased (quality=low) rasteriser. Same family as draw_triangles' first item.
    No cheap flip.
  - `graphics_gradients` (3685, re-goldened): **live**. Every gradient differs by ±1–3 (Flash ramp quantisation,
    tol 1). Our repeat-radial ellipse also shows speckle artefacts (a real seam bug, see B). L.
  - `bitmapdata_applyfilter_destpoint_edges` (149477): several tiles are empty (filter kinds not applied by
    `applyFilter`) plus destPoint clipping. Filters slot, L.
  - `bitmapdata_draw` (753 / 600 at tol 1): tol-128 Flash hinting NO-GO stands.
  - `pixelbender_dithering` (1297344): confirmed `avm2_cpu_raster_shape` skips bitmap fills 0x40–0x43
    (`avm2_cpu_raster.c`, "Bitmap fills … are skipped"). Needs the CPU bitmap-fill arm (matrix invert,
    repeat/clamp, bilinear): M. The flip is unproven at a 19929 budget.
  - `sprite_with_frames` (6342): 4953 are the two "Frame 1" text labels (text slot); 1389 are the green square's
    two 1-px vertical hairline columns (x-tie).
  - `Video-EmbedSquareTest` (1782): xtrace label (text) + video-frame chroma noise at the red square corner (video).
  - `stage3d_fractal` / `stage3d_raytrace` / `away3d_advanced_shallow_water_demo`: the 3D viewport is **entirely
    black** in all three while the 2D overlay text renders, and they log nothing. Each needs an instrumented run
    to find the first failing Context3D call (program upload/AGAL opcode, texture format or present). Simpler
    stage3d rows pass, so it is content-specific. Unpriced.

## Sweep (graphics, md5; whole prototype)

**Scope (168 tests / 177 comparisons):** every standing `render_canary_tests.txt` member, plus every test in my
downloaded AVM1 suites whose SWF names a Drawing-API or hitTest method (`lineTo`, `curveTo`, `beginFill`,
`lineStyle`, `hitTest`, `beginGradientFill`, `lineGradientStyle`, `beginBitmapFill`). That is 68 tests across
`avm1`, `from_gnash`, `from_shumway`, `visual` and `regression` (the 4 `regression/` tests included).
**Method:** `render_canary.py capture` (graphics), BEFORE = clean `origin/master` (patch reverted),
AFTER = patch, then `compare`.

```
IDENTICAL   174
DIFFERS       3   (all on the ledger)
  avm1/movieclip_line_gradient_style  fail -> fail   1023 -> 33 outliers (band, §B)
  visual/cache_as_bitmap/drawing_api  fail -> PASS   2295 -> 0, max diff 0
  visual/drawing_api/drawing_order    fail -> PASS   6658 -> 0, max diff 0
APPEARED 0  VANISHED 0  NO_RENDER 0
TRACE STATUS CHANGES: from_gnash/misc-ming.all/DrawingApiTest output_mismatch -> output_mismatch (12+2 -> 5+2 lines)
```

What the sweep shows:
- **The even-odd rule change moved no other comparison.** That includes `avm1/hittest_winding_rule`,
  `mask_with_drawing` and every gnash drawing row.
- **The z-order change moved nothing** outside `drawing_order`.

**Mode parity:** `action.c`'s CallFunction / hitTest hunks are shared code, so I ran a no-graphics leg:
- `DrawingApiTest` gives the same 5+2 residual lines as graphics.
- `masks_test`: ruffle_matched, unchanged.
- `hittest_winding_rule` and `movieclip_hittest` pass.
- `movieclip_hittest_shapeflag` fails in no-graphics with a byte-identical diff before and after the patch
  (pre-existing, not mine).

**Canary riders for wave 2** (append at EOF):
- `visual/drawing_api/drawing_order`: tier 1 once CI confirms. It is the only row that sees the z-order and the
  attached-clip transform.
- `visual/cache_as_bitmap/drawing_api`: dynamic child of a placed cacheAsBitmap sprite.
- `avm1/movieclip_line_gradient_style`: tier 2, the only translucent runtime stroke.

## Refutations

1. **DrawingApiTest plan of record** (§C):
   - its three phases do not match today's 12 lines;
   - "Drawing API uses non-zero winding per Flash spec" is wrong (Ruffle: EvenOdd);
   - 4 of the 12 lines are AVM1 name resolution, where even the bounds form fails.
2. **s21's `drawing_order` refutation of lead 1** ("routing bare calls to the base clip rendered nothing") was
   true only because the root clip's drawing reached no render pass, AND the attached clip drew through the
   identity slot. With both fixed, lead 1 is necessary and the row flips.
3. **`bitmapdata_draw_filters` is not a drawing row**: missing AVM2 ColorMatrixFilter, not draw() geometry.
4. **`BeginBitmapFill` is 71 % text** (the xtrace label), not bitmap-fill sampling.
5. **`movieclip_line_gradient_style` is not a gradient-ramp row** (97 % of it is stroke self-overlap).

## New unclaimed leads

- AVM2 twin of B (translucent stroke union in the AVM2 stroke builder); probably part of `graphics_direct_commands`.
- `Graphics.copyFrom` (AVM2) is a no-op.
- AVM1 `with`-scope name resolution of a child clip vs a timeline variable (DrawingApiTest ×4).
- Bare `hitTest()` inside `with (clip)` (DrawingApiTest ×1).
- AVM1 `delete this.onEnterFrame` returns false (DrawingApiTest +2 trailing lines).
- AVM2 ColorMatrixFilter on display objects and in `draw()` (filters slot).
- Stage3D content-black triad: instrumented first-failing-call run.

## LOCAL ORACLE REQUESTS

none. Every verdict above is against a Flash golden that is already in the corpus, and the rows I measured are
CI-identical locally.
