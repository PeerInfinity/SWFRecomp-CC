# n-join-disc: Flash's cap / corner rule on snapped strokes, and the signed noScale width (2026-11-25)

One-task session (LOCAL) after `n-drawapi-stroke-snap` (`n-drawapi-stroke-snap-report.md`, code `e81d27317`),
launched by `s28-coordinator`. Brief: `session28-fanout-reports/n-join-disc-prompt.md` (goal list in the launch prompt).

**Summary**
- **The brief's premise is overturned (§1.3):** the predecessor's "join disc painted outside a W = 3 band" is not a
  join. Flash does **not join the seam of a closed contour**: a rect drawn moveTo + 4 lineTo gets two CAPS at its start
  corner. That holds for timeline shapes and for the AVM1 drawing API. Caps reach past the band end along the axis, so
  that corner spills. Real joins never leave the corner square.
- **Rule pinned (§1)** from 960 Flash HIGH cells (`n-join-disc-captures/jc`: W = ½/1/2/3/4 × 4 caps × 8 corners × 16
  quarter-pixel (qx, qy) offsets). A snapped segment is its band (perpendicular axis snapped) between its
  **quantised, unsnapped** endpoints, plus:
  - **caps:** W = 1 none (butt); W ≥ 2 a disc of radius W/2 on the snapped centreline at the quantised end;
  - **corners:** the two segments' end discs, (Xs, y_q) and (x_q, Ys), **clipped to the corner square**;
  - **closed-contour seam:** the same two discs unclipped (= two caps); W = 1 nothing.
  - Sampling: 4×4 per pixel, x at subpixel centres and y at whole subpixels. W = 3 discs are closer to an octagon.
    The model reproduces Flash to ≈ 1/16 coverage per cell at W = 1 and 2 to 4/16 at W = 2 and 3 (§1.2).
  - **LOW quality is a different raster:** every cap is butt and every corner square (miter-like), at all widths
    (§1.4). It belongs to the LOW slots and is not implemented here.
- **Goal 2 solved (§2):** a single noVScale / noHScale flag scales the width by the **signed** device component
  `max(0, a + c)` (noVScale) / `max(0, b + d)` (noHScale) of v = M·(1,1), with a hairline at ≤ 0. Pinned on 102 cells
  (34 matrices × normal / noV / noH): it fits 57/58 single-flag cells. The old |v.x| / |v.y| rule fails 16 of them by
  up to 20× (diag(−1, 2) noVScale: rule 8 px, Flash 1 px; R70·diag(1,3): 19.8 px vs 1). acid-stroke-0's
  R45·diag(1,2) cell is one of them (a + c = −0.71).
- **Implementation (§3):** one helper `stroke_snap_place` used by both the timeline pass (`hairline_restage`) and the
  drawing-API pass (`render_webgpu_stroke_snap`). Caps are exact; corners are the join fan pushed onto Flash's union
  inside the corner square. The first cut moved quad ends and opened holes; the ledger caught it and the fix is
  in-session (§3.1). New per-centre flags `STROKE_SNAP_END` / `STROKE_SNAP_CLOSE` come from
  the recompiler (`swf.cpp`) and from both drawing-API builders. Kill switches: `SWF_STROKE_JOIN_RULE=0` and
  `SWF_STROKE_NOSCALE_SIGNED=0`.
- **Ledger (§4):** no Flash-golden row moves away from Flash.
  - The corner / cap rule moves 6 rows toward Flash, including the new jc fixture (19431 → 16530) and N ep1 at all four
    ticks (e.g. tick 304: 865 → 809 px). The rest are neutral.
  - The signed noScale width moves 3 rows toward Flash: the new nsig fixture 110025 → 45795, avm1_drawing_stroke_scale
    12315 → 11703, acid-stroke-0 7965 → 7173.
  - The rule is HIGH-only: quality LOW builds (MSAA_SAMPLES = 1) keep the old placement (§1.4).

## 1. The cap / corner rule (Flash Player 32 LNX, HIGH)

Tools (`n-join-disc-captures/`):
- `probe2.py SPEC OUT`: open polylines (DefineShape1, round caps and joins) at arbitrary matrices.
- `sweeps2.py jc`: the cap / corner sweep.
- `show.py DIR PNG LW SHAPE [e]`: coverage in 1/16 per (qx, qy).
- `model.py DIR PNG`: the candidate model's 4×4 coverage vs Flash; env knobs `CAPN`, `SX/SY`, `NS`, `CLOSE`, `SHOW`.
- `cmp.py DIR FLASH OURS…`: our render vs Flash per (width, shape class).

Flash HIGH coverage comes in exact 1/16 steps (16 samples per pixel).

### 1.1 Caps (single segments, origin = start)
- **W = 1** (lw 0.5 and 1 px identical): no cap. The band starts at the quantised start x: coverage 16 − 4·qx.
- **W = 2:** a half-disc of radius 1 on the snapped centreline. Its rows are asymmetric (10 / 14 at q = 0), which is
  exactly a disc sampled at y = whole subpixels and x = subpixel centres (fit error 0 on 64 cells).
- **W = 3:** a smaller-than-circle shape on the snapped centre. A regular octagon of radius 1.5 fits best (37 error
  units / 16 cells, vs 446 for the disc).

### 1.2 Corners (two-segment L, 8 orientations)
- The model `bands to quantised endpoints ∪ (both end discs ∩ corner square)` takes the total model error from 2957
  (per-segment discs, unclipped) to 1449 (octagon caps). Per cell: W = 1 ≈ 1/16, W = 2 ≈ 2/16, W = 3 ≈ 4/16 over a 7×7
  window.
- Without the square clip: 2667. W = 1 corners without discs: 1825 (so W = 1 corners DO get the clipped discs,
  although W = 1 caps get nothing).

### 1.3 The closing vertex is capped, not joined
- `n-stroke-snap-captures/w_v1` (DefineShape1 rect outlines, 60 cells), the start/TL corner: open-path (two caps)
  model error **53**; joined **125**.
- `drawapi_as2` (AVM1 lineTo rects): open **71**; joined **143**.
- Our tessellators (`swf.cpp drawLinesLyon` / `drawLines`, `action.c` / `avm2_display.c` builders) join that seam, as
  lyon / Ruffle do. For round caps and round joins the unsnapped geometry is the same either way. It matters only
  once the two segments snap differently, or for non-round caps (not changed here; see §5).

### 1.4 LOW
- `jc/flash_low.png`: every cap is butt and every corner is a full square, at W = 1, 2 and 3. The band position also
  follows a different tie rule (qy = 2 lands one row lower than HIGH).
- Owned by `lowq-*` / `stroke-snap-low-audit`; recorded here, not implemented.

## 2. Goal 2: noVScale / noHScale under rotation

`sweeps_nov.py` (17 matrices) + `sweeps_nov.py 2` (17 more), merged into the fixture
`regression/avm1_stroke_noscale_signed` (Flash capture `n-join-disc-captures/nsig/flash_high.png`; `widths.py`
measures each edge's ink width). 8 px declared stroke, 24 px rects, DefineShape4.

| cell (a c; b d) | mode | \|v\| rule | signed rule | Flash |
|---|---|---|---|---|
| R45·diag(1,2) (.71 −1.41; .71 1.41) | noV | 5.66 | 1 | 0.69 |
| diag(−1,2) | noV | 8 | 1 | 1.00 |
| R90·diag(1,2) (0 −2; 1 0) | noV | 16 | 1 | 1.00 |
| R70·diag(1,3) | noV | 19.8 | 1 | 1.26 |
| R180 | noV / noH | 8 | 1 | 1.00 |
| diag(2,−1) | noH | 8 | 1 | 1.00 |
| R−45·diag(2,1) | noH | 5.66 | 1 | 0.69 |
| R45·diag(2,1) | noV | 5.66 | 5.66 | 5.50 |
| R100 | noH | 6.49 | 6.48 | 6.6 |

- The one misfit (noH d12R45: 24.4 vs 22.6) misses equally under both rules. The NORMAL row of the same matrix is off
  the same way (17.6–18.4 vs 16), so it is the general width model under that matrix, not the sign.
- Shears and the half-scale cells are not graded: the ink strip overlaps the rect's other edge.
- Code: `stroke_noscale_axis()` in `render_webgpu.c`, used by both passes.

## 3. Implementation

- `stroke_snap.h`: `STROKE_SNAP_END` (4) and `STROKE_SNAP_CLOSE` (8).
- **Recompiler** `swf.cpp` (stroke_snap_data emission): ORs END into the first / last path vertex of an open path and
  CLOSE into the seam of a closed one. An end that another path of the same line style starts or ends on is not a cap (edges split at a fill change; acid-shapes-testing). Old generated code without the bits keeps working: corners take the new rule,
  and W = 1 caps keep their disc.
- **AVM1** `action.c drawingBuildStroke` and **AVM2** `avm2_display.c gfx_build_stroke`: the same bits, CLOSE only for
  explicitly closed contours. Auto-closed filled contours keep the join (Flash unmeasured there).
- **Runtime** `render_webgpu.c stroke_snap_place` (both passes, after the quarter-pixel quantisation; only when the
  run snaps; HIGH only (`MSAA_SAMPLES > 1`); W = 1..3, the fitted range: pixelHinting W ≥ 4 keeps the n-stroke-snap placement):
  - Corner centre (both flags): every vertex is snapped on both axes as before, except the round-join **arc points**
    (|offset| = W/2, diagonal). Each is cast from the snapped corner to the farthest of: the horizontal band reaching
    x_q, the vertical band reaching y_q, disc(Xs, y_q) and disc(x_q, Ys). The result is clipped to the corner square.
    W = 1 CLOSE uses the bands only (butt caps).
  - W = 1 END centre with one flag: the along-axis offset is zeroed (butt).
  - W ≥ 2 END centre with one flag: only the perpendicular axis snaps, so the cap disc sits at the quantised end.
- **Design defect found and fixed in-session (§3.1).**

### 3.1 First cut opened holes (found by the ledger)
- The first implementation moved the segment-side vertices of a corner to the quantised corner along the axis
  (band ends at x_q / y_q, as Flash draws them).
- Our builders draw a corner as two quads plus an OUTER-side join fan pivoted on the snapped corner. A quad end pulled
  back from Xs to x_q left part of the corner square uncovered. Every W = 3 corner showed 1-sample holes (64/255 inside
  solid ink).
- Ledger cost before the fix (rule on vs off, outlier channels): avm1/avm2_drawapi_stroke_snap 2742 / 2892 vs 2442 /
  2559; acid-stroke-0 9854 vs 9842.
- Fix: the quads never move. The fan carries the bands' quantised ends (the band rays above), so nothing can crack.
- Cost: the seam's spill past the square (§1.3, Flash caps a closed seam) is not placed. It lies along the axes, and
  the fan can only grow diagonally from a fixed pivot. A diagonal spill measured worse than none (drawapi W = 3 seams).
  Placing it needs cap geometry at the seam from the builders (§5).
- `stroke_noscale_axis` (goal 2), in both width blocks.

## 4. Ledger

Outlier channels (tolerance from each `test.toml`; N ep1 = px with max channel delta > 24, best of tick k−1..k+1).
Final build; `ledger5/6` drivers: one build per row, then the binary is re-run per kill-switch arm.

| row (golden) | quality | rule off (`JOIN_RULE=0`) | **on** | old noScale (`NOSCALE_SIGNED=0`) |
|---|---|---|---|---|
| regression/avm1_stroke_join_cap_snap (Flash, new) | HIGH | 19431 | **16530** | 16530 |
| regression/avm1_stroke_noscale_signed (Flash, new) | HIGH | 45795 | **45795** | 110025 |
| regression/avm1_stroke_pixel_snap (Flash) | HIGH | 225 | **222** | 222 |
| regression/avm1_stroke_pixel_snap_matrix (Flash) | HIGH | 11760 | **11730** | 11730 |
| regression/avm1_drawapi_stroke_snap (Flash) | HIGH | 2442 | **2436** | 2436 |
| regression/avm2_drawapi_stroke_snap (Flash) | HIGH | 2559 | **2550** | 2550 |
| regression/avm1_drawing_stroke_scale (Flash) | HIGH | 11703 | **11703** | 12315 |
| regression/avm1_hairline_scaled_instances / avm1_stroke_style_id_order / avm2_timeline_stroke_gradient | HIGH | 366 / 56 / 0 | = | = |
| visual/simple_shapes/strokes/scale (Flash) | HIGH | 12576 | = | = |
| acid-morph / acid-small (.01 / .05) / acid-shapes | HIGH | 43814 / 23457 / 23163 / 129201 | = | = |
| acid-stroke-0 (Flash) | LOW | 7173 | = | 7965 |
| acid-shapes-testing / button3 ×4 / drawing_api cursor, fills_and_lines | LOW | 10317 / 3 / 400, 394 | = (gated) | = |
| **N ep1 vs Flash 32**, ticks 32 / 304 / 880 / 1344 | HIGH | 45 / 865 / 224 / 438 | **29 / 809 / 215 / 402** | — |

The LOW rows were priced before the LOW gate too, as defects found by the ledger:
- acid-shapes-testing: 15155 vs 15079 (HEAD before `ed63ce7c4`), then 10387 vs 10317. Its W = 1 grid corners lost their
  corner pixel to the W = 1 butt-cap rule.
- acid-stroke-0: +12 under the first cut.

Fixed twice:
- (a) The recompiler no longer marks an open end as a cap when another path of the same line style starts or ends on it
  (`swf.cpp`). A shape's edges split at a fill change, and Flash strokes through the junction.
- (b) LOW is gated off entirely. It is a different raster (§1.4).

The first cut's numbers (§3.1) are superseded. Its N gain was larger (tick 304: 799, 880: 145), because moving the quad
ends also placed the seam spill. Recovering that needs builder geometry (§5).

## 5. Findings and next slices

- **Overturned in the brief:** the "join disc outside the W = 3 band" is two caps at a closed contour's start vertex.
  Flash never joins the seam (§1.3).
- **Defects found:**
  - (1) noScale under rotation and flips used |v| (§2).
  - (2) The first-cut corner placement cracked our quads + outer-fan topology (§3.1).
  - (3) Edges split by style changes were treated as open caps (§4).
  - (4) The rule had leaked into LOW (§4).
  - (5, not fixed) Our tessellators JOIN the closed seam (`drawLinesLyon` / `drawLines` / both drawing-API builders),
    where Flash caps it. This only matters once the two sides snap differently, or for non-round caps.
- **Next slices, in value order:**
  1. **Seam caps as geometry:** make the builders emit the closed seam as two caps (lyon: stroke the contour as open;
     builders: `_DR_EMIT_CAP` twice instead of the seam join). Then the runtime places the spill along the axes as it
     already does for caps. Expected: the first cut's extra N gain (tick 880 215 → ~145) without its holes. Price on the
     same ledger.
  2. **LOW stroke raster** (butt caps, square corners, LOW band tie rule; `jc/flash_low.png`): belongs with the LOW slots
     (`lowq-*` / `stroke-snap-low-audit`), now that `ed63ce7c4` landed the LOW gradient model.
  3. **W ≥ 2 cap / corner residue** is AA granularity (4 MSAA samples vs Flash's 16). Not fixable per vertex. Revisit
     only with an analytic-coverage stroke pass.
  4. **pixelHinting W ≥ 4** snapped corners: unmeasured (the rule is gated to W ≤ 3). One `sweeps2.py` run with
     pixelHinting covers it.
  5. **Width residual** under R45·diag(1,2) noHScale (24.4 vs 22.6) and its normal row: general device-width model, not
     the sign (§2).
- **D1** (snap-pixel-audit: LOW ¼-px AA-centre quantisation of non-snapped strokes) was offered as optional scope and
  not taken. It is LOW-only and belongs with item 2. The archived `exp_qlow.patch` stays the reference.
