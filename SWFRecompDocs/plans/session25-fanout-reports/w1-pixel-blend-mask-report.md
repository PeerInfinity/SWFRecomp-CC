# s25 wave 1 — `w1-pixel-blend-mask` (blend modes, masks, layers, colour transforms)

New files: this report, `w1-pixel-blend-mask-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`,
75+/6−, 4 files). Sources reverted; the commit holds only these two files.

Box: cloud, lavapipe, `SETUP_STATUS` all OK. Code base `ca14fe02` (origin/master). Tests downloaded from upstream Ruffle
master **`3ac8dcb07`** (categories visual, from_shumway, avm2, from_gnash, avm1, fonts, text). Pixel baseline of record:
images run `44986836161` / `08fdbcad6`, failing PNGs on `origin/ruffle-image-results`.

**Fidelity proven** on three rows: local *before* render md5 == CI actual for `visual/blend_modes/layer_alpha`
(`56f2f77a…`), `avm1/netstream_play_flv_screen` (`7dc6ff78…`); the canary *before* capture also reproduced CI
verdicts on all 164 comparisons. Local grading here is CI-grade.

## Verdicts (lead)

| # | verdict | row(s) | baseline | measured after | mechanism / owner |
|---|---|---|---|---|---|
| 1 | **GO (+2, measured, canary clean)** | `visual/blend_modes/layer_alpha`, `layer_erase` | 66744, 66949 | **0/0 max 2 (tol 2)**, **0/0 max 3 (tol 3)** | Layer groups: LAYER (2) renders its subtree into the existing offscreen and composites premultiplied-over; ALPHA (11)/ERASE (12) children inside it draw with `dst *= src.a` / `dst *= 1-src.a` and Ruffle's `discard` at 8-bit alpha 0. `render_webgpu.c` + `tag.c` blend arms |
| 2 | **GO (+1, measured)** | `avm2/bitmapdata_colortransform` | 726 (max 125) | **0/0 max 4 (tol 5)** | AVM2 `BitmapData.colorTransform` lacks the Flash "alpha-multiplier-only ≥ 1 is a no-op" bug that the AVM1 twin replicates (`FLASH_BUGS_REPLICATED.md` §colorTransform; ruffle `operations.rs:489`). `avm2_bitmap.c` `bd_color_transform`, 6 lines |
| 3 | NO-GO (AA model) | `from_shumway/acid/acid-mask` .01/.05/.10 | 12018/10915/9447 vs budget 20 @ tol 4 | — | **Not a mask mechanism; brief premise refuted.** Every diff is an outline AA pixel on every shape (5074 px, sparse, no shift helps: best whole-pixel or half-pixel shift is 2–3× worse). Quality=high MSAA-4 vs Flash's 16-level coverage; Ruffle (KF) is worse (18494). Completion: a 16-sample/analytic coverage rasteriser |
| 4 | NO-GO (device font) | `from_shumway/MaskTest-2` (KF) | 7162 | — | AVM2 `txt.mask = grad` with both `cacheAsBitmap` (alpha mask) over a **device-font** EditText (`DefineFont3 "_sans"`, 0 glyphs). We render nothing, **byte-identical to Ruffle's `output.ruffle.png`**. Even with the alpha-masked text drawn, tol 3/0 against Flash's Arial raster is unwinnable. Completion: device-font glyph parity (T3 arc) + alpha mask on device text |
| 5 | NO-GO (blendShader) | `visual/blend_modes/shader_as_mask` (KF), `avm2/blend_shader_luma_lighten` | 2100; 40318 | — | Shared mechanism: `blendShader`/`BlendMode.SHADER` is drawn as NORMAL. Quadrants: top-left (shader, no mask) 1036 ch, bottom-right (shader + cab mask) 790 ch; **plus** the plain cab alpha-mask quadrant has 274 ch at max diff 2 vs tol 1, so even a perfect shader leaves `shader_as_mask` failing. Completion: GPU layer+backdrop readback → s24's CPU PixelBender evaluator → upload (an alternative to PBJ→WGSL), and an alpha-mask rounding pass |
| 6 | disposition stands | `avm2/blend_scroll` | 296 | — | s22 "decided −2" (`w2-draw-bigcap-aa`): Flash AA's `draw()` at LOW; the golden is Ruffle's aliased one. 148 sparse circle-edge px. No work |
| 7 | NO-GO (display-list model) | `from_gnash/misc-ming.all/place_object_test` (KF, trace KF too) | 38238 | — | Two characters at ONE depth (`PlaceObject2` non-move at an occupied depth, frames 1–2): Flash keeps both. We (and Ruffle, `output.ruffle.txt`) refuse the second, so trace and image both diverge. Completion: multi-occupancy depth slots in `tag.c display_list` (L, timeline-wide risk) |
| 8 | HOLD (re-diagnosis) | `from_shumway/acid/acid-morph` | 31977 / 4022 vs 5600 / 2600 | — | Silhouettes match (XOR 1350 px); the diff is **inside** the gradient fills: best-fit gradient translation is +3.25 px on the radial ellipse (morph 1) and +2.3 px on the linear polygon. Not priced: needs the morph-ratio / gradient-matrix interpolation checked frame by frame. See lead L2 |
| 9 | HOLD (arc, verdict of record stands) | `from_shumway/bitmapbuttons` | 618042 | — | Still `swf.cpp:10966` `shape_renderable = false` for any bitmap fill on the AVM2 path; whole-stage JPEG UI + drop shadows at tol 4 / 0 outliers. Flip probability ≈ 0 even after the slice |
| 10 | **RVF entry REFUTED** (stale) | `avm1/netstream_play_flv_screen` (ignored) | 44751 | — | See §4. Our render is now **blank**, not the 160×120 overflow the RVF entry describes; and Ruffle uses the same declared-bounds rule yet passes, so the 128×128 golden is not an "asset stamp". Lead L1 |
| 11 | report-only (band lead) | `visual/cache_as_bitmap/avm1_color` (KF, Flash golden) | 1200 | 230 @ max 1 under ablation | Our s17 cab `PixelSnapping::Always` (Ruffle model) is what diverges from Flash here: disabling it gives 1200 → 230 outliers, max diff 1 (still a fail at tol 0), and **regresses `cache_as_bitmap/scroll_rect` pass → 2056**. No flip; lead L3 |

Priced yield: **+3 flips, all measured on a CI-grade box** (`layer_alpha`, `layer_erase`, `bitmapdata_colortransform`).

## 1. Layer groups (`layer_alpha`, `layer_erase`) — GO, +2

### 1.1 The s21 NO-GO premise is dead
s21 `w1-pixel-smalls` struck the pair at "ZERO flips" because the no-layer twins `alpha_no_layer` / `erase_no_layer`
failed on 7 edge-tie pixels. Since s22 `w2-float-verts` both twins **pass** (0/0, max 1 at tol 2/3 in the baseline
JSON). The strike was never re-priced (s22 `w1-pixel-catastrophic` "struck of record; not re-priced").

### 1.2 Mechanism
`layer_alpha/test.swf`: root depth 3 = sprite 23 `PlaceObject3 blend=layer`; inside it, depth 6 = sprite 20 (one
gradient shape, `sy 0.3`) with `blend=alpha` (`layer_erase`: `blend=erase`). Flash/Ruffle draw the LAYER subtree into
an isolated transparent group; the ALPHA child multiplies the group by its alpha (ruffle
`render/wgpu/shaders/blend/alpha.wgsl`: `out = (dst.rgb * src.a, dst.a * src.a)`, **`discard` where `src.a == 0`**);
ERASE multiplies by `1 - src.a`. Ruffle resolves the target via `nearest_layer` (`surface.rs:236-243`, only
`BlendMode::Layer` sets `LayerRef::Current`, `commands.rs:216`).
We had no layer groups: `blend_skip` dropped every ALPHA/ERASE draw (`tag.c` root loops ~8013/~9033 and the nested
`render_display_list` arm ~4925) and LAYER drew as normal, so the faded band never appeared.

### 1.3 Prototype (in `w1-pixel-blend-mask-prototype.patch`)
- `render_webgpu.c`
  - `blend_mode_is_trivial_layer` now includes **2**; new `blend_layer_pipeline[2]` ("blend_layer_layer": colour and
    alpha `One / OneMinusSrcAlpha`, premultiplied over) in the existing trivial table (same `MSAA_SAMPLES`, stencil-Equal
    state as its siblings). So `render_webgpu_blend_mode_is_layered(ctx, 2)` is true at `offscreen_depth == 0`.
  - Two per-draw pipelines `blend_alpha_pipeline` / `blend_erase_pipeline` (colour+alpha `Zero / SrcAlpha` and
    `Zero / OneMinusSrcAlpha`) built from the same `rp_desc` as `blend_add_pipeline` (so `MSAA_SAMPLES`, `ds_normal`),
    selected by `render_webgpu_set_blend_mode` cases 11/12.
  - The main WGSL `fs_main` body becomes `fn shade_main`; `fs_main` is a one-line wrapper (canary: byte-identical), and a
    new entry `fs_alpha_layer` discards when `c.a * 255 < 0.5` (Ruffle's 8-bit-zero discard). **Without the discard
    `layer_alpha` measured 66744 → 2083** (a 9-px column at the gradient's alpha-0 end where Flash keeps the text).
  - Two trailing `WebGPURenderContext` fields (`render_webgpu.h`).
- `tag.c`: `static int g_layer_group_depth`, incremented around `render_single_object` when a layered entry's mode is
  2 (three sites: both root loops and the nested arm); `blend_skip` now also requires `g_layer_group_depth == 0`; the
  nested arm draws an ALPHA/ERASE entry inside a group with `renderer_set_blend_mode(11/12)` → `render_single_object` →
  `renderer_set_blend_mode(0)`. Functions touched in `tag.c`: `render_display_list` (nested blend arm), and the two
  root display loops (`tagShowFrame`/`tagRerenderFrame` render arms). No button/mouse code (n-play-game is clear).

### 1.4 Measured
| row | before (= CI) | after |
|---|---|---|
| `visual/blend_modes/layer_alpha` | FAIL 66744, max 254 | **PASS 0/0, max 2 (tol 2)** |
| `visual/blend_modes/layer_erase` | FAIL 66949, max 255 | **PASS 0/0, max 3 (tol 3)** |
| `alpha_no_layer`, `erase_no_layer` | pass | pass (draw still dropped: no LAYER above) |

Both flips are **zero-headroom on max_diff** (max == tolerance); note them on the zero-headroom watch list.

**Canary md5 sweep** (`render_canary.py`, standing set, 106 tests): `before` (clean master) vs `after` (prototype):
**158/158 IDENTICAL**; the 6 `fonts`/`text` comparisons missing from the first `after` (categories not yet downloaded)
were captured with the prototype as `after5`: **6/6 IDENTICAL**. Total **164/164 md5-identical**, 0 DIFFERS.
Blast radius scan (`PlaceObject3` blend byte over every downloaded `test.swf`): only these four SWFs use static
LAYER/ALPHA/ERASE; the only runtime `BlendMode.LAYER` in the corpus is AVM2 (`masked_layer_cached_children`), whose
path (`avm2_display.c:20709`) the prototype does not touch.

### 1.5 Stated limits (wave-2 scope decisions, none blocks the +2)
1. ALPHA/ERASE are applied **per draw** of the child subtree, not via the child's own layer: identical for a
   single-shape child (both rows), differs where the child's own shapes overlap. Exact model = nested offscreen
   (texture pool) + Ruffle's alpha/erase shader composite.
2. LAYER is only isolated at `offscreen_depth == 0` (inside a filter/blend offscreen it falls back to today's normal
   draw and its ALPHA/ERASE children stay dropped) and never with a filter on the same entry (`filter_type == 0` gate,
   as for the other layered modes).
3. AVM2 twin not done: `avm2_display.c:20709-20722` still skips ALPHA/ERASE unconditionally and does not layer mode 2.
   No graded row needs it (lead L4).
4. The LAYER entry's own cxform still multiplies each child inside the group rather than the composite (same as every
   existing layered blend).

Wave 2: land the patch's render_webgpu.c / .h / tag.c hunks as-is; append `visual/blend_modes/layer_alpha` and
`visual/blend_modes/layer_erase` to `render_canary_tests.txt` at EOF (the set has no LAYER/ALPHA/ERASE member, so it
cannot see this class). No regression fixture is needed for the flip itself (two corpus rows); a nested-overlap
fixture for limit 1 would need an outside oracle (LOCAL ORACLE REQUESTS #1).

## 2. `avm2/bitmapdata_colortransform` — GO, +1
All 726 channels sit on ONE row, y = 39: the last line of bitmap 4, `new ColorTransform(1,1,1,2,0,0,0,0)` (the test's
own comment: "Flash bug: Transform with only alpha multiplier > 1 has no effect!"). That line of `test.png` is white
with alpha = x; we doubled alpha (ours 78 at x = 40 vs golden 39). The AVM1 path already replicates the bug (entry in
`FLASH_BUGS_REPLICATED.md`); AVM2 `bd_color_transform` (`avm2_bitmap.c` ~1904) never got it. Patch: early return
when `rm == gm == bm == 256 && am >= 256 && ro == go == bo == ao == 0` (Ruffle's condition, `a_multiply >= ONE` —
identity included, which also skips a premul/unmul round trip). Measured **726 → 0/0, max 4 (tol 5)**.
Blast check: every corpus test whose source calls `BitmapData.colorTransform` outside avm1 (`avm2/bitmap_data`,
`bitmapdata_colortransform_oob`) plus the one sourceless SWF with both strings (`avm2/json_errors`): all PASS after.
Wave 2: land the hunk; append `avm2/bitmapdata_colortransform` to the canary at EOF; extend the
`FLASH_BUGS_REPLICATED.md` entry's "File" line with the AVM2 site. No-graphics parity: the code is mode-independent
(`avm2_bitmap.c`, not in the no-graphics-only list), no `NO_GRAPHICS` arm.

## 3. Refutations

- **"layer pair and acid-mask share a mechanism" — refuted.** acid-mask has no blend mode and no timeline clipDepth;
  its diffs are AA edge pixels on every outline at quality=high (diff map: every contour, 232 of 5074 diff pixels have
  ≥ 6 diff neighbours, i.e. 1-px rings). Every other quality=high acid row carries a 3 000–13 000 outlier budget; acid-mask
  carries 20 at tol 4. No shift model helps (0,0) = 12018 is the minimum over ±1 px and half-pixel shifts.
- **s21 layer NO-GO** — its premise (no-layer twins fail) fell with s22 float-verts; +2 measured.
- **RVF "Video Display Object Render Bounds: `netstream_play_flv_screen` Asset Stamp"** — two claims fail: (a) our
  render is not "the top-left ~128×120 of the stretched logo"; it is entirely blank (md5 `7dc6ff78…`, CI-identical);
  (b) ScreenVideo is lossless, so a 1:1 render *should* be byte-identical to `rufflelogo.png` — identity is not evidence
  of a stamp, and Ruffle renders with the same "stretch to declared bounds" rule (`video.rs:570-576`) yet passes,
  because the FLVPlayback root instance is placed with scale 0.4 × 0.533 (`PlaceObject2` char 9) and the component sizes
  its player to 128×128. The ignore entry should be re-opened as a diagnosis lead (L1).
- `acid-mask`'s KF tag is honest: Ruffle is 18494 at the same check.

## 4. Evidence notes

- `netstream_play_flv_screen` (gdb on the kept build, `SWF_KEEP_BUILD_DIR`): `actionGetVideoFramePixels`,
  `actionGetEmbeddedVideoFramePixels` and `render_webgpu_draw_bitmap_quad_scaled` are **never called** in 60 ticks;
  `ng_isVideoChar(4)` fires only from `actionOnVideoPlaced` ← `tagPlaceObject2` ← `sprite_5_frame_0` ← `ng_attachMovie`.
  So the Video (char 4) inside the attached VideoPlayer clip (sprite 5) never reaches `render_single_object`.
- `MaskTest-2`: `DefineEditText` text `<font face="_sans">SHUMWAY`, `DefineFont3 _sans` with 0 glyphs; frame script
  sets `cacheAsBitmap` on `txt` and `grad` and `txt.mask = grad`.
- `shader_as_mask` per-quadrant channel counts > tol 1: TL 1036 (max 128), MR 274 (max 2), BR 790 (max 128), rest 0.
- `place_object_test`: frame 1 places `sh1` and `sh2` both at depth 3 (no move flag); frame 2 `mc2`/`mc1` at depth 4.

## New unclaimed leads

- **L1 `avm1/netstream_play_flv_screen` blank render (S–M diagnosis, possible +1).** The attached VideoPlayer
  subtree is never walked. Candidates: FLVPlayback keeps the player `_visible = false` until a NetStream
  ready/metadata event our AVM1 NetStream never delivers to the component, or attached clips under a nested timeline
  sprite are not walked in `OFFSCREEN_RENDER` (the interleave block in `render_display_list` is `#ifndef
  OFFSCREEN_RENDER`). Fix then needs the component to size the Video to 128×128 (Ruffle passes at tol 1 on a lossless
  codec, so a correct path should be exact). Remove from `ignored_tests.txt` / RVF once diagnosed.
- **L2 `acid-morph` gradient offset.** Gradient content offset by ~2–3 px in both morph fills while the silhouettes
  agree; check our morph gradient-matrix lerp and which ratio each depth shows at tick 30 (depth 4 is replaced by
  static `DefineShape4` 6 on frame 30; depth 3 stays at ratio 63276). Then re-price against 5600 / 2600.
- **L3 cacheAsBitmap snapping vs Flash.** Unsnapped rendering brings Flash-goldened `avm1_color` to 230 / max 1 but
  breaks `cache_as_bitmap/scroll_rect` (quality low). A Flash model (cache origin at floor(bounds), sub-pixel content
  kept) might separate the two; no flip in sight (tol 0, max 1 residual).
- **L4 AVM2 layer groups.** Port §1.3 to `avm2_display.c:20709` (same three hooks). No graded row; game-visible.
- **L5 Layer-group fidelity (limits 1–2 above).** Nested offscreen pool + Ruffle alpha/erase composite shader; needed
  for an ALPHA child with overlapping shapes or LAYER inside a filter.
- **L6 blendShader via CPU PixelBender** (rows in §5 of the verdict table): readback-evaluate-upload instead of PBJ→WGSL.

## LOCAL ORACLE REQUESTS

1. (optional, for a wave-2 regression fixture on layer-group limit 1) an AVM1 SWF with a `blendMode = "layer"` clip
   containing an `"alpha"` child built from TWO overlapping 50%-alpha squares, rendered by the Ruffle exporter
   (`exporter -s -f 1`), PNG. Not needed for the +2.
2. (for L1) Ruffle exporter `--trace-log` run of `avm1/netstream_play_flv_screen/test.swf` for 60 frames with an
   instrumented build printing the VideoPlayer clip's `_visible`, `_width`, `_height` per frame — only if L1 is
   scheduled.
