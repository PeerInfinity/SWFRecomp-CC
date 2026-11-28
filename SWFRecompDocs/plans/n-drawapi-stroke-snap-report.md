# n-drawapi-stroke-snap: the timeline snap's perf check + Flash's stroke rule for Drawing-API strokes (2026-11-25)

One-task session (LOCAL) after `n-stroke-snap` (`n-stroke-snap-report.md`, code `09b2c9130`), launched by
`s28-coordinator`. Brief: `SWFRecomp-CC-history:SWFRecompDocs/plans/session28-fanout-reports/n-drawapi-stroke-snap-prompt.md`.

**Summary**
- **Perf (§1): the timeline snap is NOT a material cost.** Measured inside the wasm on real-GPU Windows Chrome, the
  stroke restage in N gameplay costs **0.52 µs/draw with `SWF_STROKE_SNAP=0` and 0.73 µs/draw with the snap**, about
  **+0.11 ms per frame** (~1 % of N's ~10 ms frame; ~510 draws/frame). The brief's "+0.7 ms" first reading was machine drift: a second
  interleaved series reversed the order. A per-(draw, device matrix) cache was built and measured: it halves the
  native cost (0.40 → 0.17 ms/frame, 89 % hits, output identical) but buys nothing in the browser, so it was **not
  kept**. `hairline_restage` and `render_webgpu_draw_shape` are untouched by this slice.
- **Drawing-API strokes (§2) now follow Flash's device-space rule**, AVM1 (`action.c`) and AVM2 (`avm2_display.c`)
  alike, through one renderer entry point `render_webgpu_stroke_snap`:
  - snap of exactly axis-aligned segments (u ≤ 4 / 8 / 12, pixelHinting → all widths);
  - AA width `2·floor(u/2)/4` and the quarter-pixel grid otherwise;
  - the declared width is whole pixels, **truncated in AVM1, rounded in AVM2** (n-stroke-snap §1);
  - width = `|M·(1,1)|/√2`, or `|v.x|` / `|v.y|` / stage-only for the noScale modes (w2-flash-stroke-width's model);
  - on a non-similarity matrix (non-uniform scale, shear) every offset is rebuilt in DEVICE space by the timeline
    pass's `hairline_flash_offset` (w2b-stroke-width-merge, `a7c72d830`, landed while this slice ran): device offset
    lines, device-circle joins and caps, miters.
- **Flash-golden fixtures** (tolerance 2, outlier channels):

  | fixture | before | after |
  |---|---|---|
  | `regression/avm1_drawapi_stroke_snap` (new; Flash capture `drawapi_as2`) | 33300 | **2442** |
  | `regression/avm2_drawapi_stroke_snap` (new; Flash capture `drawapi_as3`) | 33471 | **2559** |
  | `regression/avm1_drawing_stroke_scale` (w2's fixture, coordinator's Flash HIGH capture) | 33528 | **12315** |

- **Defect found in our own port, not Ruffle's:** AVM1 `lineStyle` noScale names are the OPPOSITE of AS3
  `LineScaleMode`: AVM1 `"vertical"` keeps only the X scale (NoVScale). Flash's `vertical` row thickens under
  `_xscale`; Ruffle already maps it that way (`avm1/globals/movie_clip.rs` vs `avm2/.../graphics.rs`). Not an RvF.
- **Corpus pricing (§3), drawing-API pass alone** (`SWF_STROKE_SNAP_DRAWAPI=0` vs on, timeline snap on in both):
  - Flash goldens: `acid-shapes-testing` **31420 → 6936 px**, `acid-morph` 2427 → 291 outliers, `graphics_bitmaps`
    393 → 386 px; `graphics_simple_shapes` 79 → 82 px and `acid-shapes` +104 px of 41.8k (both already failing).
  - **2 pass → fail, both on Ruffle-made LOW-quality goldens**: `visual/drawing_api/cursor` (vs the archived Flash
    PNG **399 → 200 px, toward Flash**) and `visual/drawing_api/fills_and_lines` (flat vs Flash: 20166 → 20239 of
    ~20k off). `drawing_order` also fails now, but from `09b2c9130`'s timeline pass, not this one.

## 1. Perf check owed by `09b2c9130`

Setup: N (`flasharchive/N`) rebuilt from a clean HEAD worktree as `docs2/examples/flasharchive/NAB`, driven into
gameplay (menu clicks at 12 s / 16 s, level 0 "the motherlode"), real-GPU Windows Chrome (Intel Xe-3LPG) via
`tools/divergence/perf/n_ab_win.py` (copy with `SWF_PAGE_ENV`, below). The kill switch is a getenv, so one build
serves every arm: an `add_init_script` hook pushes `ENV.SWF_STROKE_SNAP='0'` into `Module.preRun`.

| measurement | snap off | snap on | snap on + cache |
|---|---|---|---|
| browser frame CPU, gameplay window 22–48 s, series 1 (3× interleaved, no cache build) | 9.24–10.25 ms | 9.93–10.12 ms | — |
| browser frame CPU, series 2 (cache build, 3× interleaved) | 9.18–9.40 | 9.14–10.56 | 9.06–9.79 |
| browser frame CPU, series 3 (final drawing-API build, machine load 5–9) | 9.79–10.15 | 9.51–9.81 | 10.06–10.41 |
| **in-wasm restage timer, 2 runs each (≈1.8 M draws)** | **0.52 µs/draw** | **0.74 µs/draw** | **0.73 µs/draw** |
| native restage timer, 199 gameplay renders, 23.5k restaged draws | 0.12 ms/frame | 0.40 ms/frame | 0.17 ms/frame |

- Frame-CPU A/Bs on this machine drift ±0.5 ms between runs (memory `attached-pump-perf-n-real-gpu`), more under
  peer builds; the three series disagree on the order. The in-wasm timer (`emscripten_get_now` around
  `hairline_restage`, cumulative, printed every 20k draws) is consistent to ±2 % across repeats and is the number.
- Native OFFSCREEN renders only capture ticks; the native A/B passes `CAPTURE_TRIGGERS` for every 5th frame
  300–1290 (`f<N>:iteration:<N>` tokens, ≤ 4096 bytes). Cache-on vs cache-off PNGs differed only in N's wall-clock
  fps counter (x 2–13, y 581–586).
- Decision: +0.11 ms/frame is not material, and the cache (up to 48 MB) did not move the browser number, so the
  timeline pass stays as `09b2c9130` shipped it. If a game ever shows the restage hot, the measured design is in this
  report's history: a direct-mapped table keyed on (vertex range, device affine incl. translation, stage scale)
  wrapping `hairline_restage`, replaying the staged vertices.

## 2. Drawing-API implementation

Contract: `SWFModernRuntime/include/stroke_snap.h` (`StrokeSnapSrc`).
- **Builders** (`action.c drawingBuildStroke`, `avm2_display.c gfx_build_stroke`): every emitted stroke vertex is
  `centre + offset`, the centre being a polyline vertex (segment quads: both ends; join / cap fans: the joint). The
  builders now record, per vertex, that centre (twips) and the centre's axis flags (`STROKE_SNAP_VERT` /
  `STROKE_SNAP_HORZ` when an adjacent segment is exactly vertical / horizontal in local space, including closing
  segments and explicit-close seams). The soup is kept BEFORE the translucent-stroke union, with a generation id.
- **Renderer** (`render_webgpu_stroke_snap`): device affine from the CPU xform mirror (now kept whether or not the
  movie has timeline stroke tables), then the n-stroke-snap rule per vertex; translucent strokes re-run the union
  (`StrokeSnapSrc.post` = `actionDrawingUnionTris` / `gfx_union_tris`) on the restaged copy. Results are cached per
  (generation, device affine): a static drawing restages and unions once.
- **Callers**: `tag.c render_drawing_path` (AVM1 fill+stroke paths, solid and gradient strokes) and
  `avm2_render_graphics` (solid, gradient and bitmap strokes).
- **Width**: AVM1 `trunc(thickness)` px, AVM2 `round(thickness)` px (hairline 0 → u = 0 → 1 px snapped);
  `lineStyle` args 3 (pixelHinting) and 4 (noScale / scaleMode) and `GraphicsStroke.pixelHinting/scaleMode` are now
  parsed. noScale: `none` → stage scale only; NoVScale → `|v.x|`; NoHScale → `|v.y|`; normal → `|v|/√2`,
  `v = M·(1,1)` in device px (w2-flash-stroke-width's acid-stroke-0 model; confirmed here on the Drawing API).
- **Isotropic width under rotation / shear**: same branches as the timeline pass after `a7c72d830`: a
  non-similarity matrix goes through `hairline_flash_offset` (its kill switch `SWF_STROKE_FLASH_WIDTH=0`, if set,
  applies here too), an axis-aligned one rescales offsets per device axis, a rotation uniformly. Before the rebase
  this slice used its own per-vertex "distance to the device edge line" scaling (scale fixture 12543); the shared
  function is slightly better (12315) and keeps one model.
- Kill switches: `SWF_STROKE_SNAP=0` (both passes), `SWF_STROKE_SNAP_DRAWAPI=0` (this pass only, for pricing),
  `SWF_STROKE_SNAP_CACHE=0` (the drawing cache).
- Tools: `tools/divergence/perf/n_ab_env_win.py` (n_ab_win.py + `SWF_PAGE_ENV="K=V,…"` → `ENV` in `preRun`,
  stage-coordinate clicks, `HLPROF` console lines) and `SWFRecompDocs/plans/n-stroke-snap-captures/
  scan_linestyle.py` (image tests whose SWF calls the drawing API's `lineStyle` / `GraphicsStroke`).
- Not covered: the BitmapData.draw CPU raster path (`avm2_cpu_raster_tris` of `line_verts`), hit tests (they read
  `line_verts`, unchanged), and LOW quality (w2-lowq-sample-point's slot).

## 3. Corpus pricing

`scan_linestyle.py` (decompress each image test's SWF, look for `lineStyle` / `GraphicsStroke`) finds 27 image
tests; minus `_swfbridge`, Stage3D/away3d and `regression/` that leaves 21, plus `graphics_draw_triangles` /
`graphics_draw_path`. The sweep ran before the rebase onto `a7c72d830` (only non-similarity matrices take the new
offset function; the moved rows here are axis-aligned or similarity). Each ran in one build per suite × arm: all-on, all-off (`SWF_STROKE_SNAP=0`), and for every
row that moved, drawing-only-off (`SWF_STROKE_SNAP_DRAWAPI=0`). "px" = pixels with max channel delta > 2 vs the
golden (or the archived Flash PNG where noted); otherwise verify_output's outlier count.

| row | golden | quality | drawing-off → on | status | note |
|---|---|---|---|---|---|
| `from_shumway/acid/acid-shapes-testing` | Flash | high | 31420 → **6936 px** | fail → fail | →F, the big one |
| `from_shumway/acid/acid-morph` | Flash | high | 2427 → **291** | pass → pass | →F |
| `from_shumway/acid/acid-shapes` | Flash | high | 41758 → 41862 px (tol-200 check 0 → 2 px) | fail → fail | thick curved strokes, quarter-grid AA, slightly away |
| `avm2/graphics_bitmaps` | Flash | low | 393 → 386 px (verify 526 → 705, limit 800) | pass → pass | →F by px; verify's 3-check count rises |
| `avm2/graphics_simple_shapes` | Flash | low | 79 → 82 px | fail → fail | 11 px change on a 2 px round rect, mixed |
| `avm2/graphics_gradients` | Flash | low | 3685 → 3681 | fail → fail | — |
| `avm2/displayobject_getbounds_shape` | — | — | 3716 → 3714 | pass → pass | — |
| `visual/drawing_api/cursor` | not Flash | low | 0 → 200 vs golden; **vs Flash 399 → 200** | **pass → FAIL** | →F; priced loss |
| `visual/drawing_api/fills_and_lines` | not Flash | low | 0 → 394 vs golden; vs Flash (screen) 20166 → 20239 | **pass → FAIL** | flat vs Flash; LOW-quality row (w2-lowq-sample-point) |
| `visual/drawing_api/drawing_order` | not Flash | low | 5985 → 5985 | fail (from `09b2c9130`) | not this slice |
| `avm2/graphics_draw_triangles`, `graphics_draw_path`, `graphics_direct_commands`, `graphics_bad_direct_commands`, `graphics_bitmap_fill`, `bitmapdata_draw`, `bitmapdata_drawwithquality`, `bitmapdata_opaque`, `visual/cache_as_bitmap/drawing_api`, `visual/definefont4`, `avm1/movieclip_begin_gradient_fill`, `movieclip_line_gradient_style`, `movieclip_setmask` | mixed | — | unchanged | unchanged | — |

- `drawTriangles` / `drawPath` strokes are diagonal or curved: nothing to snap, and their AA width already matched.
- Regression fixtures (graphics): the three new ones pass at their limits; the predecessor's `avm1_stroke_pixel_snap`
  (225 / 240) and `avm1_stroke_pixel_snap_matrix` (11760 / 12000 after the rebase) pass. No-graphics build: the new
  fixtures + `avm2_graphics_runtime` pass (traces). Browser build links clean under `-Wl,--fatal-warnings`.

## 4. Flash-golden ledger

Rows with a Flash-made golden (or a Flash capture) that this slice moves, drawing-only-off → on:

| row | before | after | direction |
|---|---|---|---|
| `regression/avm1_drawapi_stroke_snap` (new) | 33300 | 2442 | →F |
| `regression/avm2_drawapi_stroke_snap` (new) | 33471 | 2559 | →F |
| `regression/avm1_drawing_stroke_scale` (new, w2's fixture) | 33528 | 12315 | →F |
| `from_shumway/acid/acid-shapes-testing` | 31420 px | 6936 px | →F |
| `from_shumway/acid/acid-morph` | 2427 | 291 | →F |
| `visual/drawing_api/cursor` (Flash PNG, golden is Ruffle's) | 399 px | 200 px | →F |
| `avm2/graphics_bitmaps` | 393 px | 386 px | →F (small) |
| `avm2/graphics_simple_shapes` | 79 px | 82 px | away (3 px) |
| `from_shumway/acid/acid-shapes` | 41758 px | 41862 px | away (0.25 %) |
| `visual/drawing_api/fills_and_lines` (Flash screen PNG) | 20166 px | 20239 px | flat |

## 5. Findings and next slice

1. **Join / cap residue (brief goal 3, not landed):** the ~3 px/rect left on both drawapi fixtures are round-join
   corners. Flash's join disc on a SNAPPED stroke is not snapped with the band: at W = 3 it sits on the quarter-pixel
   centre and paints partial pixels one column outside the band (`191 239` above, `143 239` left of a 3 px rect's
   corner), while at W = 1 the corner stays inside the band. Leaving every fan centre unsnapped made the fixture worse
   (2442 → 3519), so the rule is subtler (likely Flash's 4×4 supersampled coverage of a disc at the quarter centre,
   which our 4× MSAA can't reproduce exactly). Next: capture single corners at W = 1/2/3 × quarter offsets with
   `probe.py` and fit.
2. **The R(45)·diag(1,2) `vertical` cell** of `avm1_drawing_stroke_scale`: Flash draws a hairline where the `|v.x|`
   model gives 2.8 px (w2's "NoVScale anomaly"). Unmodelled.
3. `acid-small`'s slight move away (n-stroke-snap §5.2) is a TIMELINE row, untouched here.
4. Drawing-API strokes through `BitmapData.draw` (CPU raster) still use the unsnapped soup.
