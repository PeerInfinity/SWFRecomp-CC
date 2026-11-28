# n-seam-caps: a closed stroke seam as two caps, and pixelHinting ends (2026-11-26)

One-task session (LOCAL, s29 N ladder) after `n-join-disc` (`n-join-disc-report.md`, code `03527a3f8`). Launched by
`s29-coordinator`. Brief: `SWFRecomp-CC-history:SWFRecompDocs/plans/session29-fanout-reports/` (n-seam-caps), goal = n-join-disc §5 item 1 + defect (5).

**Summary**
- **Seam caps landed (§2):** all four builders now emit a closed contour's seam as two caps (round caps + round joins):
  recompiler `drawLinesLyon`, AVM1 `drawingBuildStroke`, AVM2 `gfx_build_stroke`. That covers explicitly closed
  contours and, in the drawing APIs, fill-auto-closed ones. Each seam vertex carries the axis of the segment it belongs
  to, and the runtime places it as that segment's cap or as the old snapped corner (`stroke_seam_flags`).
- **The brief's Flash premise is refined (§1):** Flash's seam is two caps **only when snapping moves the two seam ends
  apart** (first segment's start (x_q, Ys) ≠ last segment's end (Xs, y_q)). When they coincide, it is a join in the
  line's join style. Measured on closed rects × every caps × joints combination. For round caps + round joins, caps
  give both cases by themselves, so the cut is exact there. Auto-closed filled contours behave exactly like explicit
  ones (measured).
- **Why the n-join-disc first cut opened holes (§1.4):** it pulled the shared quad ends back to x_q / y_q at **every**
  corner, but the corner's join fan is pivoted on the snapped corner and only sweeps the outer quadrant. A cap fan is
  pivoted on its own segment's end and shares that quad's end vertices, so it is watertight by construction. The
  partly uncovered corner pixel a capped seam leaves is Flash's own (e.g. coverage 15/255 vs 0 in
  `avm1_drawapi_stroke_snap`).
- **Overturned in the brief:** the "first cut's extra N gain (tick 880 215 → ~145)" is not a seam effect. Seam caps are
  N-neutral at every tick (§4). The only on/off pixel differences are N's scrolling console text (tick phase), and the
  880 residual is the ragdoll's pose (gameplay phase).
- **W = 3 seams stay corners by default (§4):** Flash caps them too, but our 4-sample MSAA renders the half-pixel cap
  spill farther from Flash's 16-sample raster than the corner does (`avm1_stroke_seam_caps` 1824 → 1836).
  `SWF_STROKE_SEAM_CAPS=3` enables them.
- **W = 3 snapped caps are octagons now (§3):** n-join-disc's fitted shape. Timeline caps were already octagons (their
  45° fans), but drawing-API caps were discs.
- **Item 3, pixelHinting (§3):** Flash snaps a hinted END **along its axis too**. W = 4..6 caps and corners render
  identically for every sub-pixel offset within a half pixel. Implemented for W ≥ 2 (HIGH):
  `avm1_stroke_hinting_caps` 8388/604 → 7056/368. Hinted corners already snapped both axes and were right. A hinted
  seam always joins in Flash, so it keeps the corner placement.
- **Ledger:** no Flash-golden row moves away from Flash. Four rows move toward Flash, the rest are unchanged.

## 1. Flash measurements (Flash Player 32 LNX, HIGH)

### 1.1 Seam = caps iff the snapped seam ends differ
`regression/avm1_stroke_seam_caps` (new fixture, Flash golden). Closed rects via `moveTo` + 4 `lineTo`. Rows: caps
none / square / round × joints round / miter / bevel. Columns: W = 1 / 2 / 3 × offsets 0 / 0.5 / 0.25. TL = seam,
TR = a real join:

| cell | x_q vs Xs | seam (TL) in Flash |
|---|---|---|
| W2 o0 | equal (130 / 130) | the JOIN style: round 95, miter 0, bevel 159 (same as TR) |
| W2 o.5 | 130.5 vs 131 | the CAP style for every join style: none = no spill, square = square spill 127, round = round spill 207 / 191 |
| W3 o0 | 190 vs 190.5 | CAP style: none leaves the corner notched, square / round spill |
| W3 o.5 | equal | JOIN style: miter = full square, bevel 239 / 47, round 191 / 31 / 15 |

So Flash snaps each segment's endpoints (perpendicular axis) and joins the seam only when the two snapped end points
coincide. Unsnapped, they always coincide (a join).

### 1.2 Auto-closed filled contours
`moveTo` + 3 `lineTo` inside `beginFill` / `endFill`: byte-identical to the explicit close, unfilled or filled (W = 2 / 3 ×
3 offsets). Rows 9 and 10 of the fixture.

### 1.3 pixelHinting
- `avm1_drawapi_stroke_snap` right half (hinted closed rects, W = 2 / 3): the seam is the round corner around the
  snapped vertex, with no spill, at every offset.
- `regression/avm1_stroke_hinting_caps` (new, Flash golden): W = 4 / 5 / 6 open L corners and caps × 16 quarter-pixel
  offsets. The output is identical within each half pixel (q (0, 0) = (1, 1), (2, 2) = (3, 3)). The cap disc and the
  corner's round join sit on the fully snapped end. That is why a hinted seam always joins: both ends snap to the same
  point.

### 1.4 Why the first cut cracked
See the Summary. n-join-disc §3.1 moved the quad ends of corners (not only seams), and nothing covered the strip between
the pulled-back end and the snapped pivot. Seam caps avoid it structurally: no corner fan at the seam, and each cap shares
its own quad's end vertices.

## 2. Implementation

- `stroke_snap.h`: `STROKE_SNAP_OWN_V` (16), `STROKE_SNAP_OWN_H` (32), `STROKE_SNAP_SEAM` (64). A seam vertex (a cap
  vertex, or the seam-side end of its segment's quad) keeps the seam's corner flags (both axes | CLOSE) and adds SEAM |
  its own segment's axis.
- **Recompiler** `swf.cpp`: `drawLinesLyon` / `drawLines` take an optional `seam_owner`. When set (opaque solid strokes,
  not morph / glyph, round caps + round join), a closed path strokes as open (two `drawLineCap`), and each output tri is
  tagged 0 / 1 (edge 0's seam end) / 2 (last edge's). The stroke-run emitter ORs 64 | the owner's axis bit into
  `stroke_snap_data` for vertices centred on the seam. Translucent strokes keep the join: the two caps overlap, and a
  translucent stroke would double-blend there (the timeline has no union pass). The fallback builder (lyon "fold" /
  degenerate edges) keeps the join. `SWF_STROKE_SEAM_CAPS=0` at recompile time = the old join geometry.
- **AVM1** `action.c drawingBuildStroke` and **AVM2** `avm2_display.c gfx_build_stroke`: explicit and auto-closed
  seams become two caps (round / round only). A per-emitted-vertex `vown` array carries the owner, because an
  auto-closed seam's two caps share one centre index. Allocation gets +1 join/cap slot per contour. Translucent
  drawing-API strokes are unioned already (`drawingUnionTranslucentStroke` / `gfx_union_tris`).
  `SWF_STROKE_SEAM_CAPS=0` = the old join (`drawing_stroke_seam_caps_on` / `gfx_stroke_seam_caps_on`).
- **Runtime** `render_webgpu.c`:
  - `stroke_seam_flags(sf, W, hinted)` (new): a SEAM vertex becomes its own segment's END (own axis only) when HIGH,
    join rule on, not hinted and W ≤ `stroke_seam_caps` (default 2). Otherwise it becomes the corner (both axes), which
    for round caps on one centre covers exactly the old round join. Called in both passes (`hairline_restage`,
    `render_webgpu_stroke_snap`).
  - `stroke_snap_place` (now takes `hinted`): a hinted END at W ≥ 2 also snaps its along-axis coordinate (HIGH only).
    A W = 3 END's cap arc points are pushed onto Flash's octagon (circumradius 1.5, vertices on the axes and diagonals).
  - Kill switches: `SWF_STROKE_SEAM_CAPS=0|2|3` (runtime: placement; recompile / build time: geometry),
    `SWF_STROKE_CAP_OCTAGON=0`, `SWF_STROKE_HINT_ENDS=0`.
- Functions touched (for the cloud slots near `render_webgpu.c`): `stroke_seam_flags` (new), `stroke_snap_place`
  (signature + hinted END + W3 octagon), `hairline_restage` and `render_webgpu_stroke_snap` (one call each),
  `hairline_init` (env). Nothing else in that file.

## 3. Shapes: octagon and hinted ends
- Octagon: drawing-API caps used `2 · drawing_arc_segments` points (a disc). Timeline caps (`drawLineCap`, 45° steps)
  were already the octagon, so the jc fixture does not move. Drawing-API rows move only in summed error (avm1 126 → 123).
- Hinted ends: above.

## 4. Ledger

Outlier channels / summed max-channel error in whole pixels (tolerance per `test.toml`). One build per row
(`--recompile`), then the binary re-run per runtime arm. The seam-off arm (`SWF_STROKE_SEAM_CAPS=0`) is HEAD's placement.
Timeline geometry is caps in both arms; for round / round it is the same coverage. N ep1 = px with max channel delta
> 24 vs Flash 32, best of tick k−1..k+1.

| row (golden) | seam off | **on (W ≤ 2)** | W ≤ 3 | no octagon | no hint ends |
|---|---|---|---|---|---|
| regression/avm1_stroke_seam_caps (Flash, new) | 1824/144 | **1824/144** | 1836/145 | — | 1824/144 |
| regression/avm1_stroke_hinting_caps (Flash, new) | 7056/368 | **7056/368** | 7056/368 | — | 8388/604 |
| regression/avm1_drawapi_stroke_snap (Flash) | 2436/126 | **2436/123** | 2436/123 | 2448/124 | 2436/123 |
| regression/avm2_drawapi_stroke_snap (Flash) | 2550/142 | **2550/137** | 2550/138 | 2562/138 | 2550/137 |
| regression/avm1_stroke_pixel_snap (Flash) | 222/8 | **222/7** | 222/7 | | |
| regression/avm1_stroke_pixel_snap_matrix (Flash) | 11730/667 | **11730/662** | 11730/663 | | |
| regression/avm1_stroke_noscale_signed (Flash) | 45795/2771 | **45783/2768** | = | | |
| visual/simple_shapes/strokes/scale (Flash) | 12576/1789 | **12570/1788** | = | | |
| visual/drawing_api/fills_and_lines | 38429/1470 | **38424/1468** | = | | |
| regression/avm1_stroke_join_cap_snap (Flash; open paths, no seams) | 16530/810 | = | = | = | |
| avm1_drawing_stroke_scale / hairline_scaled_instances / stroke_style_id_order / avm2_timeline_stroke_gradient | 11703 / 366 / 56 / 0 | = | = | = | |
| acid-stroke-0 / button3 ×4 / acid-shapes-testing / drawing_api cursor (LOW) | 7025 / 3 / 10317 / 400 | = (gated) | = | = | |
| acid-morph / acid-small .01 .05 / acid-shapes | 43814 / 23457 / 23163 / 129201 | = | = | = | |
| **N ep1 vs Flash**, ticks 32 / 304 / 880 / 1344 | 41 / 808 / 214 / 416 | 42 / 807 / 215 / 416 | 43 / 817 / 215 / 421 | | |

- The W ≤ 3 and "no octagon" columns are the L5 build. The on / seam-off / no-hint-ends columns of every Flash row are
  the final build (L6 + L7, re-priced): hint ends move only avm1_stroke_hinting_caps.
- No-graphics mode: avm1_stroke_seam_caps and both drawapi rows pass (`--recompile`).
- The n-join-disc ledger's N numbers (29 / 809 / 215 / 402) and acid-stroke-0 7173 predate HEAD moves (`ed63ce7c4` and
  later, plus a peer's uncommitted goto hunks in the shared tree during this run). Compare the arms, not across
  sessions.
- N ep1: every on / off difference sits in one 20×20 block, N's scrolling console text (tick phase). Seam caps do not
  move N. The tick-880 residual's largest cluster (68 px) is the ragdoll pose.

## 5. Findings and next slices
- **Overturned:** (§1 of the brief) "Flash caps the closed seam" holds only when snapping separates the seam ends.
  Otherwise Flash joins it (in the join style). (§2) The expected N gain does not exist: N's seam pixels are unchanged.
- **Defects found and fixed:** (a) hinted ends were not snapped along their axis (avm1_stroke_hinting_caps −1332
  outliers); (b) drawing-API W = 3 caps were discs, not Flash's octagon.
- **Defects found, not fixed:**
  - (c) Non-round caps / joins at a seam whose ends separate: Flash draws the CAP style (butt = notch, square = square
    spill); we keep the join. Fixing it needs both geometries per seam (join + 2 caps, the unused one collapsed per
    frame by the runtime decision). `avm1_stroke_seam_caps` rows 0–5 / 10 are the gate (≈ 600 of its error units).
  - (d) W = 3 seam caps (and W ≥ 2 cap spill generally) lose to 4-sample MSAA granularity. That is the analytic-coverage
    stroke pass item from n-join-disc §5.3.
- **Next slices, in value order:**
  1. N: the stroke ladder is at its floor for seams. The remaining N ep1 px are phase (console text, ragdoll pose) and
     AA granularity. Next N work should target the tick phase or the browser ladder, not stroke geometry.
  2. (c) Dual seam geometry for DefineShape4 / drawing-API non-round styles (S–M). Only matters for content with
     non-round caps.
  3. An analytic-coverage (16-sample-equivalent) stroke raster for snapped strokes. It would retire (d) and the W ≥ 2
     cap / corner residue (M–L, render path, coordinate with `w1-aa-sizing`).
  4. pixelHinting W = 1 ends: unmeasured (gated off).
