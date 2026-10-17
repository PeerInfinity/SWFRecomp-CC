# w2-hairline-device-width — session 22, wave 2 (cloud): device-scale minimum stroke width for timeline strokes

**New files (all under `SWFRecompDocs/plans/session22-fanout-reports/`):**
- `w2-hairline-device-width-report.md` (this file)
- `w2-hairline-device-width.patch`: **the patch to apply** =
  `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`
  (touches `SWFRecomp/include/swf.hpp`, `SWFRecomp/src/swf.cpp`,
  `SWFModernRuntime/src/rendering/render_webgpu.c`, `ruffle-tests/render_canary_tests.txt`;
  `verify_output.py` is untouched). Proven with `git apply --check -R` on the branch head.
- `w2-hairline-device-width-tools/`: `stroke_scan.py` (recompile every image test, count timeline
  stroke runs), `additive_check.py` (master vs patched generated code with the new tables stripped),
  `grade.py` / `vs_ruffle.py` (grade captures with `verify_output.compare_images`), and the raw
  outputs: `stroke_scan_393_image_tests.txt`, `additive_check_65.txt`, `sweep_set_128.txt`,
  `canary_compare_before_after.txt`.

No new source files, no new fixtures. Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe).
Corpus: `download_tests.sh visual from_shumway from_gnash avm1 avm2` + `text fonts timeline swf
import_assets mixed_avm`, upstream master on 2026-10-17. `/root/ruffle` clone at `653ef4f41`;
`render/src/tessellator.rs`, `core/src/display_object/graphic.rs` and
`core/src/tessellation_cache.rs` are unchanged vs the coordinator's `45366370e`.
Base: origin/master `41cf67236` (includes `5edcc1a5d` w2-float-verts).

## 0. Verdicts

| item | verdict |
|---|---|
| **L1 device-scale minimum stroke width (timeline strokes)** | **GO, landed.** +2 pixel flips (`acid-small .01`, `acid-small .05`; `.05` is the −1 that w2-float-verts cost, `.01` was failing on CI before that), 0 pixel regressions, 0 trace moves. |
| Design | **Re-expand at draw time, not re-tessellate.** The recompiler emits, per stroke run, `{vert_start, vert_count, centre_start, width, emitted_width}` plus the centreline point of every stroke vertex. At draw time the runtime computes Ruffle's draw scale and, only when a run needs `k = max(width, 20/scale)/emitted ≠ 1`, draws a copy of the range from the dynamic vertex region with `v' = c + k·(v − c)`. Exact for every stroke vertex we emit (segments, round/miter/bevel joins, round/square caps are all `centre + halfwidth·d`); only the round-arc segment count stays at the compile-time width. |
| Runtime re-tessellation cache (Ruffle `TessellationCache`) | **Not needed for L1, not built.** The only per-scale quantity L1 needs is a uniform width factor, and that is exact without re-tessellating. A real re-tessellation cache is only needed for L2 (below). |
| Ruffle's cache hysteresis (re-tessellate only on a ×2 scale change, 4-entry LRU) | **Not emulated, deliberately.** It is a Ruffle performance artifact; Flash sizes per draw. `acid-small`'s goldens are **Flash Player's output** (upstream `e6eaa4549`, 2026-02-17). No moved row changes scale between frames, so the choice is invisible on the corpus today. |
| `acid-small output.05` back to pass | **YES.** t80 3027 → **2193**/3000 (t20 19476 → 10755/21000, t0 25974 → 24036/30000). |
| `acid-small output.01` (3624/3000) | **FLIPS.** t80 3624 → **2529**/3000 (t20 19860 → 11355/20000, t0 26004 → 24081). |
| `acid-scale` (8/0) | **Unmoved, byte-identical.** No stroke in it is drawn at a scale where the clamp changes anything. Its 8 single-pixel ties are not L1 (see L2 below). |
| gnash `simple_loop_test` | **Already passing, unmoved (md5-identical, all 7 frames).** Its ACCEPTED_DIFFS entry is already marked STALE ("all 7 frames now PASS") in `from_gnash/_investigation/ACCEPTED_DIFFS.md:699`. No hairline mechanism is left there. |
| `simple_shapes/strokes/scale` (KF) | **Large improvement, still fails:** 71397 → **19308** outliers vs Flash; vs Ruffle's own render 59148 → 6687. The rest is curve flattening of an upscaled circle (L2). |
| `acid-stroke-0` (KF) | Fail → fail, 52522 → 52702 (+180). The bottom row's two thin squares, which we did NOT draw before, are now drawn, as in Flash's golden. Ruffle's own render draws only one of them. The count rises because our squares are not pixel-snapped like Flash's. KF image row with a tol 0 / 0 budget: no verdict change possible. |
| Width-0 (hairline) LINESTYLEs | We drop them (`drawLines` returns on width 0); Ruffle/Flash draw 1 device px. **Measured zero yield:** a recompile scan with width 0 emitted shows **no image test in the corpus has a width-0 timeline stroke.** Not landed (it would add hit-test geometry for no measured gain). Lead L3. |

## 1. EXPECTED-FLIP LEDGER (for the coordinator's CI check)

Fidelity: on this box, the **pre-float-verts tree (`42017e6f5`) renders `acid-scale`,
`acid-small output.01` and `simple_shapes/strokes/scale` byte-identical (RGBA) to CI's actual PNGs on
`origin/ruffle-image-results`** (images run at `02df69d28`). The *before* leg here (master incl.
float-verts) reproduces w2-float-verts' graded "after" numbers exactly (3624, 3027, 8, 71397).
So the absolute verdicts below are CI-grade.

### Pixel axis: fail → pass (+2)

| test / comparison | before (master `41cf67236`) | after |
|---|---|---|
| `from_shumway/acid/acid-small output.01` | FAIL t0 26004/30000, t20 19860/20000, **t80 3624/3000** | **PASS** 24081, 11355, **2529** |
| `from_shumway/acid/acid-small output.05` | FAIL t0 25974/30000, t20 19476/21000, **t80 3027/3000** | **PASS** 24036, 10755, **2193** |

Note: CI's last images run (`02df69d28`) predates float-verts and shows `.05` PASS / `.01` FAIL. Against
the CI board of record this is **+1** (`.01`); against current master (float-verts landed, `.05` red)
it is **+2**. Either way both comparisons end PASS with ≥ 471 outliers of margin on every check.

### Pixel axis: pass → fail

**None.** No CI-passing comparison moves at all (§3).

### Pixel axis: moves on rows that stay failing

| comparison | budget | before | after | note |
|---|---|---:|---:|---|
| `visual/simple_shapes/strokes/scale` (KF) | tol 5 / 0 | 71397 | **19308** | vs Ruffle's render: 59148 → 6687 |
| `from_shumway/acid/acid-stroke-0` (KF) | 0 / 0 | 52522 | 52702 | bottom-row thin squares now drawn (Flash draws them) |
| `from_gnash/misc-ming.all/shape_test` (KF) | 50 / 0 | 16074 | 17911 | strokes go from 2 px to 1 px wide (Flash and Ruffle both draw 1 px; vs Ruffle 4602 → 2691). Flash pixel-snaps the hairlines, so the overlap with Flash's black pixels drops (4615 → 3685) while our black-pixel total moves toward Flash's (6179 → 5234 vs 5599). |

### Trace axis

**No flips expected.** The recompiler change is additive: across all 65 image tests with timeline
strokes, the generated `RecompiledTags`/`RecompiledScripts` trees are **byte-identical to master's
once the three new tables are stripped** (`additive_check_65.txt`: 65/65 SAME). Every other test only
gains `stroke_run_count = 0` and two 1-element arrays. `shape_data` (which the CPU hit tester reads)
is unchanged, and the runtime reads the new tables only in `render_webgpu.c`. The graphics capture
showed `TRACE STATUS CHANGES: (none)` over 128 tests. No-graphics: `acid-small`, `acid-stroke-0`,
`regression/avm2_timeline_stroke_gradient`, `avm2_timeline_solid` and `avm2_parent_child_render` all
PASS with `--recompile`.

## 2. The patch (exact scope)

**Recompiler** (`swf.hpp`, `swf.cpp`, inside w2-float-verts' `drawLines` / stroke-emission region,
the area SIBLING_FILE_MAP gives this slot):
- `drawLineJoin` / `drawLineCap` / `SWF::drawLines` take a trailing `offset_scale` (default 1.0).
  It multiplies every offset from the source path vertex, while `strokeArcSegments` keeps the unscaled
  half-width. With 1.0 the arithmetic is bit-identical (`x*1.0`), which `additive_check` confirms.
- Stroke emission: for plain DefineShapes (`!is_morph && !is_font`), a second `drawLines(..., 0.0)`
  pass yields the same triangle list with every vertex collapsed onto its centreline point. It is
  emitted as `stroke_centre_data[][2]` (float bits), plus one `stroke_run_data[][5]` row per run:
  `{vert_start, vert_count, centre_start, width_twips, emitted_width_twips}`, and `stroke_run_count`.
  Morph strokes keep the frozen width (their vertices are rewritten per frame by the morph lerp).
- New `SWF` members use default member initializers (no constructor init-list edit).

**Runtime** (`render_webgpu.c` only; one self-contained block plus four one-line hooks):
- Weak externs for the three tables (`#ifndef DYNAMIC_HOST`). Generated code without them links,
  and the feature is then off. The in-browser recompiler host does not bridge them, so it is off there.
- `hairline_init` (called from `create_buffers_and_upload`) keeps a CPU copy of every xform slot and
  of the current stage_to_ndc. Hooks: `xform_slot_write` (the single choke point for per-frame
  xform writes), `render_webgpu_open_pass` and `render_webgpu_upload_stage_transform` (root
  `_xscale` etc. are folded into the stage matrix there, and acid-small's 0.73/0.50 root scale is one).
- `hairline_restage`, called from `render_webgpu_draw_shape` **after** the mask-stencil stroke trim.
  It binary-searches the runs that overlap the draw range. From the local→device 2×2,
  `diag(W/2,H/2)·(stage·xform)`, ×20 for Ruffle's twips→device-twips convention, it computes
  Ruffle's `scale = sqrt((|a+c|² + |b+d|²)/2)` (`graphic.rs:254-259`) and then
  `target = max(width, 20/scale)` twips (`tessellator.rs:178-186`). Only if some run has
  `|target/emitted − 1| > 1e-4` does it copy the range to the dynamic region (`stage_dyn_verts`,
  the same path `draw_tris` uses), re-expand the run vertices and draw the copy. Every other draw is
  untouched; if the dynamic region is full it falls back to the static draw.
- Child movies (Loader / import): `verify_output.py` copies only the listed draws.c arrays into the
  combined wrapper, so a child's new tables are simply not linked (no symbol clash) and its strokes
  keep today's behaviour. The root's table indexes the root's vertices, which stay at base 0 of the
  combined table (`ng_shared.c:2532`).

**Canary:** appended at EOF (tier 2) `visual/simple_shapes/strokes/scale`. It is the "other
direction" witness (sub-20-twip strokes under a >1× parent shrink to 1 device px). `acid-small`, the
sub-pixel witness, is already a member.

Sibling overlap: `render_webgpu.c` is also edited by `w2-filter-fixes` (new `compose_layer_pipeline`).
My hunks are a new block before `create_buffers_and_upload`, one call in that function, and one line
each in `upload_stage_transform`, `open_pass`, `xform_slot_write` and `draw_shape`. I touch none of
the drawing-API `gfx_*` code (`w2-drawing-api-lyon`).

## 3. Sweep (every image row that CAN move, by construction)

The runtime change only acts on draws that cover a timeline stroke run, so a test can only move if
its recompiled code has `stroke_run_count > 0`. `stroke_scan.py` recompiled **all 393 image tests**
in the downloaded corpus (+ `regression/`). **65 have timeline stroke runs.** I rendered those 65 plus
the full standing canary (128 tests, 209 comparisons), before (master recompiler + runtime, with
`--recompile`) and after:

- **204 comparisons md5-IDENTICAL, 5 DIFFER**: `acid-small .01`, `acid-small .05` (fail→pass),
  `strokes/scale`, `acid-stroke-0`, `shape_test` (all fail→fail, §1).
- Image status changes: only the two ledger flips. Trace status changes: none.
- Every standing-canary member outside the ledger is md5-identical, including all 6 `regression/`
  rows, the filter, blend, mask and cacheAsBitmap rows, and `timeline_loop` /
  `cache_as_bitmap/masks .02` (the 5-outlier-margin rows from float-verts).
- Final tree re-captured (13 comparisons): md5-identical to the graded "after".

`regression` suite: the only `regression/` test with a timeline stroke run is
`avm2_timeline_stroke_gradient`. It PASSes in graphics (0 outliers) and no-graphics with
`--recompile`, as do `avm2_timeline_solid` and `avm2_parent_child_render`. No new fixture: the behaviour
has a corpus witness graded against Flash's own output (`acid-small`), the oracle-outside-SWFRecomp
requirement.

## 4. Refutations / corrections of record

- **"`simple_loop_test` — hairline-stroke pixel-snapping"**: already resolved (stale entry, all
  frames pass at baseline). L1 does not touch it (md5-identical). It was never an L1 row.
- **"`acid-scale` (8/0) is L1"** (w1 §6 / w2-float-verts §7): **refuted.** L1 moves 0 pixels there.
  Its 4 single-pixel ties are on scaled FILLED shapes at `quality = "low"`, which makes them L2
  (scale-dependent flattening tolerance) or rasterizer ties, not width.
- **"`strokes/scale` is L1"**: partly. L1 removes 73 % of its outliers. The visible remainder is a
  13-gon instead of a circle: an upscaled shape flattened at the compile-time 2-twip tolerance (L2).
- **Brief premise "per-draw-scale re-tessellation is needed"**: not for the width. A uniform
  per-run factor on centre-relative offsets is exact for our stroker. Only flattening needs re-tessellation.

## 5. Not finished / HOLD (with completion mechanisms)

- **L2 scale-aware flattening tolerance (fills + strokes): HOLD, not attempted.** Ruffle flattens at
  `0.1/scale` px (`tessellator.rs:168, 189`), and we flatten once at 2 twips. Owner rows:
  `strokes/scale` (the circle), probably `acid-scale`'s 4 ties. Completion mechanism, cheapest first:
  (a) **compile-time**: the recompiler knows every static PlaceObject matrix (and sprite nesting), so it
  can flatten each character at `2/max_static_scale` twips. That is no runtime change, it costs more
  vertices only on upscaled shapes, and AS-driven scale is not covered. (b) **runtime**: emit curve
  control points and re-flatten + re-tessellate (libtess2 in the runtime) per scale bucket with a
  Ruffle-style cache. That is much larger. Price (a) first on `strokes/scale` + `acid-scale`.
- **L3 width-0 LINESTYLE hairlines**: currently dropped. Measured 0 image rows affected. Fold into a
  later slot only together with a corpus row that has one. It also needs a hit-test decision (Ruffle's
  shape hit test for a 0-width stroke).
- **Morph strokes** keep the frozen compile-time width (no run table). No corpus morph row with thin
  strokes was in the movable set. Completion: emit runs for morphs and re-expand after the morph lerp
  (tag.c morph upload).
- **Child (loaded/imported) movies' strokes** are not re-expanded (§2). Completion: extend
  `verify_output.py`'s child extraction with the three tables plus a per-movie base in
  `hairline_restage`. Fund only with a loader row that shows thin strokes.
- **In-browser recompiler (DYNAMIC_HOST)**: feature compiled out. Completion: bridge the three tables
  in `host_main_graphics.c` like `shape_data`.
- Emscripten deploy build not exercised in the cloud (weak data references are standard wasm-ld;
  `text_char_codes` already uses the same pattern).

## 6. New unclaimed leads

- **L2** above (compile-time per-character flattening tolerance from static PlaceObject scale). This is
  the next step on `strokes/scale` and likely `acid-scale`.
- **Flash hairline pixel-snapping** (`shape_test`, `acid-stroke-0`'s row 4, gnash rows): Flash snaps
  1-px strokes to the pixel grid, which neither we nor Ruffle do. All the affected rows are KF.
- The `stroke_scan.py` "which tests carry construct X in generated code" pattern bounded this
  sweep to 65 tests exactly. It is worth reusing for any runtime render change keyed on recompiler data.

## LOCAL ORACLE REQUESTS

None. The witness rows' goldens are Flash Player output (`acid-small`) or carry Ruffle's own render
(`output.ruffle.png` for the KF rows), which was used to check the implementation's direction.
