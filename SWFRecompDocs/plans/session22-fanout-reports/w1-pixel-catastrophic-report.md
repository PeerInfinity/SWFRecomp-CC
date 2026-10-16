# w1-pixel-catastrophic — pricing the catastrophic-band clusters (s22 wave 1, cloud)

**NEW FILES:**
- `SWFRecompDocs/plans/session22-fanout-reports/w1-pixel-catastrophic-report.md` (this report)
- `SWFRecompDocs/plans/session22-fanout-reports/w1-pixel-catastrophic-prototype.patch`: a measured prototype. It is env-gated
  (`SWFRECOMP_PROTO_DEVFONT`, `PROTO_NOSLOT`, `PROTO_DEFAULT_FAMILY`, `PROTO_BMPCAP`) except for the `draw()` clipRect arm and
  the face-upem scale, which is byte-neutral for the bundled 1000-upem Noto. `git apply --check` passes on `origin/master`.
  Source is reverted, so this commit holds report files only.

**Box / provenance.** `SETUP_STATUS` reports apt, Pillow and Dawn all OK. Corpus `avm1 avm2 visual from_shumway stage3d` was
downloaded at upstream Ruffle **`45366370e`**, the same SHA the coordinator synced to. CI image data is run `36515003936` at
`02df69d28`, read from `origin/ruffle-image-results` and the per-suite `image_results_graphics.json`.
**Cloud↔CI fidelity is PROVEN on non-trivial rows.** My local `--mode=graphics --images` renders are **md5-identical** to CI's
actual PNGs for `avm2/displayobject_z` (6-colour geometry), `from_shumway/acid/acid-bitmap-draw_quality_high`,
`visual/cache_as_bitmap/text`, `avm1/netstream_play_flv_screen`, `from_shumway/hardwrap` and `visual/video/h264_multinalu`.
So every absolute local grade in this report is CI-grade.

---

## 1. Verdicts, ranked (lead with flips)

| # | row(s) | verdict | priced flips | evidence | mechanism / owner |
|---:|---|---|---:|---|---|
| 1 | `from_shumway/avm1/text-bind`, `visual/cache_as_bitmap/text` | **GO, MEASURED** | **+2** | prototype: text-bind **583/600 PASS** (tol 64; tol-128 check passes too). cab/text **1200/1500 PASS**. Trace PASS on both | (a) `[default_fonts]` + test `[fonts.*]` are never used for AVM1 zero-glyph device fonts. `swf.cpp:2593-2648` always synthesizes from the bundled 1000-upem Noto. Both tests ship a 1024-upem Noto with ascent 784, so ours sits **exactly 8 px (size 29) / ~13 px (size 42) low**. (b) cab/text also needs `cab_snap_world` (`tag.c:3218`) to stop repointing a CAB root sprite to a dynamic slot: `compute_mc_world_xform` (`tag.c:7499`) then indexes past the baked CPU table and the EditText children vanish |
| 2 | `avm2/bitmapdata_draw` | **GO** (2 of 3 mechanisms measured) | +1 | 37 079 → **1725** @tol64 (budget 1500), 761 @tol128 (600), 5013 @tol0 (5200 ✓). The remaining text residual is a **uniform 1 px (ours high)**. A +1 px shift takes the stage field to 6 @64 / 0 @128, which projects to a pass | (a) `draw()` ignores `clipRect` (`avm2_bitmap.c:2614-2631`, "not supported yet"); ellipse 35 120 → 108. (b) the AVM2 device lookup has no `[default_fonts]` (`avm2_text.c:2690` "Ruffle then goes to a DefaultFont; we keep the baked-in Noto"), so both TextFields drew **nothing**. (c) a 1-px baseline is still open |
| 3 | `avm2/pixelbender_effect_glassDisplace` | **GO** | +1 | with the viewport removed, our 550×400 render vs the golden's centred crop at (25,150): **17 outlier channels / 1003**. The PixelBender output is right | AVM2 `stage.scaleMode` setter is a no-op (`avm2_display.c:13715`) and nothing in the renderer reads scaleMode, so we fit 550×400 into the 600×700 viewport (×1.09). Needs noScale + centre align + drawing content **outside the stage rect** (57 344 golden px lie below/right of it). It is the only image row where noScale ≠ showAll (`stage_scale_factor`, `stage3d_program_constants_*` already pass) |
| 4 | `avm2/displayobject_z` | **GO (model-priced)** | +1 | a 25-line numpy model of Ruffle's z rule (no tuning) grades **6675/6500 @tol100, 16730/17500 @tol10** vs ours 211 814 / 223 951. The residual is 1-px edges of the 15.9×-scaled bitmap | `z` is stored but never rendered. Ruffle `render/src/transform.rs:26` accumulates `tz` additively, and `render/wgpu/src/globals.rs:30-63` applies a perspective divide: f = 250/tan 27.5° = 480.25, centred at the viewport centre, culled at z ≤ −f. For z-only children this is an exact 2D scale about the centre, so it can be done in the AVM2 compose walk with no 3D pipeline |
| 5 | `avm2/bitmapdata_draw_masks` | **GO (small)** | +1 | the golden is red exactly at mask∩rect in draw space (900 px: x0-24 rows 0-19, x40-59 rows 40-59). We paint the full 60×60 (3600 px). All residual 2700 @tol0 sits in this bitmap; the stage half already matches | `bd_draw_shape_walk` (`avm2_bitmap.c:2355`) ignores the source's `mask`. The mask applies with its OWN matrix in draw space (−10,−10), and the source's cxform/blendMode are ignored, as we already do. Axis-aligned, so tol 0 is reachable |
| 6 | `avm2/stage3d_texture_bytearray_compressed_raw_alpha` | **GO (small-medium)**, B′ split | +1 | ATF header byte 12 = **format 5 (RawCompressedAlpha)** = raw DXT5 only. **No JPEG-XR or LZMA needed** (Ruffle `atf_jpegxr.rs:146-163` uploads the `dxt5` record as-is; the wgpu path uses `Bc3RgbaUnorm`) | s20 filed all three B′ rows together. This one needs only an ATF-5 record walk + a BC3 decode in `avm2_stage3d.c`. Exactness risk: BC3 colour interpolation rounding vs lavapipe (tol 4 / 66) |
| 7 | `avm2/loader_jpegxr`, `loader_jpegxr_alpha`, `stage3d_texture_bytearray`, `stage3d_texture_bytearray_compressed_alpha` | **HOLD for a dependency ruling** | up to +4 | ATF formats 1 / 4 and Loader JPEG-XR all need one JPEG-XR decoder. Ruffle's `jpegxr` crate wraps **jxrlib**, and Ubuntu 24.04 ships it as **`libjxr-dev` (1.2~git20170615)**, so a decode is plausibly bit-identical. Format 4 also needs LZMA (`liblzma`) + DXT reconstruction (`atf_jpegxr.rs:49-144`) | Completion mechanism: the coordinator/user approves adding `libjxr-dev` (+`liblzma-dev`) to `scripts/cloud_env_setup.sh` and `ruffle-tests.yml`, behind an optional `SWF_HAVE_LIBJXR` the way `SWF_HAVE_LIBAVCODEC` works. I did not install it (BRIEFS_COMMON: no ad-hoc binaries) |
| 8 | `visual/video/h264_multinalu` (+ `h264` ×10, `avm2/netstream_seek_flv`) | **GO for a first slice (+1)**; the rest is an arc | +1 now; up to +11 more | `h264_multinalu` is a STATIC image (NOTE.txt: `-loop 1 … -frames:v 8`): black circles on white, so any decoded frame clamps exact under our existing Ruffle-exact `yuv420_frame_to_rgba_bt601` (Ruffle `render/src/bitmap.rs:249`; openh264 output is I420). `h264` frames 2-11 need real timed playback with Ruffle's 2-frame B-frame delay (`test.toml` comment) | **AVM2 NetStream has no video pipeline at all**: `Video.attachNetStream` = `video_noop` (`avm2_display.c:17332`) and `ns_play` only queues onMetaData (`avm2_net.c:2015`). Also `video_codec.c` feeds codec-7 payloads raw: no AVCPacketType/composition-time strip, no AVCDecoderConfigurationRecord → extradata, no length-prefixed NALUs. The s19 lead "maybe just an unrefreshed stem" is **refuted**: CI renders nothing |
| 9 | `acid-bitmap-draw_quality_high` (+ `_low`, kf) | **GO for a prototype-first slot**: band now, flips need draw()-AA | 0 now; +1 to +2 with AA | the prototype cap (`PROTO_BMPCAP=512`) moves **195 744 → 55 532 @5 / 5817 @32 / 542 @64** (budgets 35 000 / 700 / 0). Our render now matches **Ruffle's own `output.ruffle.png` for `_low`** (716 / 390 / 126): we are aliased exactly like Ruffle-low, while Flash's golden (md5-identical for `_high` and `_low`) is antialiased | (a) `dynamic_bitmap_max = max(stage, 256)` (`avm2_display.c:20238`) silently skips any runtime BitmapData larger than that (`avm2_display.c:18261`). Here a 512² draw target on a 256² stage drew blank, and the CPU `draw()` itself was fine (257 536 px written). (b) CPU `draw()` has no AA. Flash AAs `draw()` even at stage quality low, which is why `_low` is a Ruffle `known_failure`: matching Flash flips BOTH. Precedent: the Stage3D CPU rasteriser already uses Vulkan 4x sample positions |
| 10 | `avm2/stage3d_texture` | **REOPENED, HOLD** (s20 "RTT flips nothing" premise refuted) | 0 (one slot) | s20 said "blocked by device fonts". Since s21's Noto work **the text draws**, so the s20 premise no longer holds. Now: the whole 3D scene, including the green clear, is missing (RTT → post-filter quad samples an unrendered texture). If the 3D layer were exact, **486 px** would remain in two autosized text lines (budget 117) | Needs RTT + MSAA-4 RTT resolve + true Noto advances for autosize width (the baked advances are "rounded to tens", `avm2_text.c` D1-2). Completion mechanism: fund RTT only together with the true-advance change and its ~20-test trace A/B |
| 11 | `avm2/pixelbender_effect_glassDisplace_shaderfilter` | HOLD, medium | +1 | out1 shows the plain flowers (no filter applied); out2 is plain blue (applyFilter with a ShaderFilter is a no-op) | the CPU PB evaluator EXISTS (shader3d-arc P2, `avm2_pixelbender.c:1043`), so s17's "Pixel Bender not executed / PARKED" is **stale**. What is missing is ShaderFilter as a display filter + `applyFilter(ShaderFilter)` (`generateFilterRect` too). Sizeable |
| 12 | `avm2/blend_shader_luma_lighten` | HOLD, large | +1 | we draw a plain normal blend (the whole orange ellipse); the golden shows the luma-lighten split | `blendShader`/`BlendMode.SHADER` compositing is unimplemented. It needs a dest readback + CPU PB per pixel. The evaluator exists, the compositing route does not |

**Total GO now: +7 priced (+2 measured, +5 model/partial-measured)**, plus +1 for the h264 first slice. Rows 7-9 hold up to
+16 more behind one dependency ruling, one video arc and one draw()-AA slot.

### NO-GO / dispositions confirmed or corrected (each with its completion mechanism)

| row(s) | verdict | why / completion mechanism |
|---|---|---|
| `from_shumway/flash_text_TextField`, `hardwrap`, `stylesheet` | **NO-GO (A-INHERENT-like; all Ruffle `known_failure`)** | goldens are Flash device-font raster (Times/Arial glyphs) at tol 3-5 / max 0. We draw NOTHING today (AVM2 zero-glyph `_sans`/serif, s20 "price 0"), and drawing Noto would not match. Completion mechanism: none short of shipping the Windows fonts |
| `from_shumway/MaskTest-2` | NO-GO (kf; s20 price 0) | same zero-glyph AVM2 device-text root as above |
| `visual/definefont4` | **NO-GO (arc)** | it is a **TLF scene**: the SWF carries the whole `flashx.textLayout` framework + FTE, with DefineFont4 `Exo 2` as `OTTO`/CFF. stb_truetype could read the CFF, but the text is laid out by TLF/FTE TextLine rendering, which we don't render. Completion mechanism: an FTE TextLine renderer arc |
| `avm2/stage3d_raytrace`, `stage3d_fractal`, `away3d_advanced_shallow_water_demo` | NO-GO (verdict of record, s20 §406: CPU budget-latched) | completion mechanism: the GPU/WGSL Stage3D route (1600-1900 LOC) |
| `avm2/stage3d_bitmap` | HOLD (s20: sprite placement, 7 `Math.random` + 7 `getTimer`) | not re-priced. Note: our RNG already follows Ruffle's deterministic seed, so the next step is diffing the 7 positions against a Ruffle trace (oracle request below) |
| `from_shumway/acid/acid-text` | **NO-GO (raster parity)** | 1674 px at tol 0 / max 0, **no shift helps** (best (0,0) in all three columns): aliased glyph-edge parity |
| `from_shumway/acid/acid-color-0` | **band only, 0 flips** | 16 697 of 17 388 channels are TextField colour/background (ABC drawn red not green; the 2nd "Hello" box missing its green bg / black text), a real B-FIXABLE bug. But the logos (668) + ring (23) alone exceed the 3-outlier budget |
| `visual/blend_modes/layer_alpha`, `layer_erase` | struck of record (s21 "0 flips even with layer groups"); not re-priced | — |
| `visual/blend_modes/shader_as_mask`, `acid-text-4`, `acid-textfield` | Ruffle `known_failure`; not priced | — |
| `from_shumway/bitmapbuttons` | verdict of record stands (s19: `swf.cpp:10709` marks bitmap-filled shapes `renderable = 0`; s12: tol 4 / max 0 on resampled JPEG) | not re-priced |
| `avm1/movieclip_line_gradient_style` | **handoff → `w1-stroke-staircase`** | all 1023 channels are dark dots at the INNER corners of semi-transparent gradient strokes, from overlapping alpha at joins (we composite per segment; lyon strokes one polygon) |
| `visual/fonts/font_lookup_as3` | **HOLD, oracle question** | two lookup gaps. (1) The `embedFonts=true, font=""` column draws nothing: `avm2_text.c:2807` deliberately returns no outline for an unmatched embedded field, citing Flash's blank `no_font_found`. This golden (Ruffle, `with_default_font`) draws Noto there, per `layout.rs:556` "we don't support DefineFont4". (2) The device column's C-F glyphs differ. Flash-over-Ruffle forbids (1) until Flash's behaviour for font `""` is known (oracle request) |
| `avm1/netstream_play_flv_screen` | **disposition text STALE** (still hard-excluded via global `ignored_tests.txt:147`) | RVF "Video Display Object Render Bounds" says we render "the stretched logo, ~13.5k outliers". Under `--mode=graphics` (the CI grade, history since 2026-09-04) we render **nothing** (44 751, all white, local = CI md5). The ruling (stretched vs asset stamp) is untouched, but the entry's description of our render is wrong. Completion mechanism: fix the AVM1 graphics-mode Video draw (swf.c path), then re-read the entry |
| `edittext_device_transform_negative`, `acid-morph`, `acid-small .01` | not re-priced (s20/s21 owners: device-transform family / G-HOLD / near-pass) | — |
| `text/style_changes_in_html`, `from_gnash/…/place_object_test` | not priced: categories not in my download set (`place_object_test` is kf) | — |

---

## 2. Evidence and refutations

1. **`text-bind`'s ACCEPTED_DIFFS entry is REFUTED.** (`avm1/_investigation/ACCEPTED_DIFFS.md:475`, "device-font file
   mismatch … replicating per-test fontconfig resolution is high-effort / narrow value".) The recompiler has read `test.toml`
   per test since s19 (`abc_devicefont.cpp:526 emitDeviceFonts`, cwd = test dir), so the "high effort" premise is gone. The
   entry's own swap experiment scaled a 1024-upem face by `swf_em/1000` (2.4 % oversize). Done upem-correctly (`swf_em *
   stbtt_ScaleForMappingEmToPixels(…,1)`), it **passes: 583/600**. Doc action at landing: delete the entry and its
   summary-table row, and add nothing to `ignored_tests.txt`.
   Margin warning: 17 channels. Also, `[default_fonts]` resolution must follow Ruffle `layout.rs:611-625`: Times New Roman →
   Serif, Arial → Sans, Courier* / Consolas / NSimSun → Typewriter, anything else → Sans, with the `_sans`/`_serif` aliases from
   `font.rs:104`.
2. **`cache_as_bitmap/text` was "passing" blank text under the old ANY rule.** Its tol-0 check (10 233 / 12 000) passes with
   NO text drawn. The s21 ANY→ALL correction exposed it, and the render was blank all along. The mechanism is the CAB slot
   repoint (`PROTO_NOSLOT` alone, with the old font, still leaves the 8-px offset at 8457 outliers; both fixes together pass).
   Wave-2 fix shape: make `compute_mc_world_xform` resolve an overridden slot through `xform_overrides` (or the snapped
   matrix), not drop the repoint. The repoint is what carries the opaque-background snap (`opaque_background` 3856 → 4).
3. **s20 "RTT flips nothing … stage3d_texture (blocked by device fonts)" is stale**: the fonts unblocked in s21 (§1 row 10).
4. **s17 "Pixel Bender not executed / PARKED" is stale for pixel rows**: the evaluator shipped in shader3d-arc P2. `glassDisplace`
   needs **no PB work at all**: it is a stage-scaleMode bug (17 channels with the content placed correctly).
5. **s19 "h264 may be an unrefreshed stem" is refuted**: CI and local both render the video area empty. The cause is the absent
   AVM2 NetStream→Video path plus raw AVC packets fed to libavcodec.
6. **s20 B′ "ATF decode unblocks three, one mechanism" is refined**: the three rows split by ATF format byte into **raw DXT5
   (format 5, no JPEG-XR)** vs **JPEG-XR-backed (formats 1 and 4)**, and the latter shares its decoder with `loader_jpegxr` ×2.
7. **The "oversized-bitmap blank_render class closed" (s12/s16) is incomplete**: the cap only covers the stage and static
   DefineBits sizes. A **runtime-created** BitmapData larger than max(stage, 256) still renders blank, with no warning.

---

## 3. Wave-2 slots I would fund (in order)

| slot | scope (owner files) | ledger | size | notes |
|---|---|---|---|---|
| **w2-default-fonts-avm1** | `SWFRecomp/src/swf.cpp` (zero-glyph synth: resolve the face via `test.toml` `[default_fonts]`→`[fonts.*]` per `layout.rs:611`, upem-correct scale); `SWFModernRuntime/src/libswf/tag.c` (`compute_mc_world_xform` under a CAB slot override) | `text-bind`, `cache_as_bitmap/text` (+2, measured) | S-M | trace A/B the 4 `[default_fonts]` tests + every AVM1 `[fonts.*]` test (TextField-v6/7/8, TextFieldTest). Canary: add `cache_as_bitmap/text` (no AVM1 CAB-text member exists). Retire the `text-bind` ACCEPTED_DIFFS entry |
| **w2-bitmapdata-draw** | `avm2_bitmap.c` (`draw()` clipRect for shape/text/bitmap sources; source `mask` in the CPU walk); `abc_devicefont.cpp` + `avm2_text.c` (emit `[default_fonts]`, resolve on a list miss); the 1-px baseline | `bitmapdata_draw`, `bitmapdata_draw_masks` (+2) | M | `bitmapdata_drawwithquality` (subtests, ungraded) also uses `[default_fonts]`. Self-localize from the AVM1 slot (it shares the `[default_fonts]` table emit) or merge the two slots |
| **w2-stage-noscale** | `avm2_display.c` (scaleMode store) + the AVM2 view transform (`avm2_render_init` / `stage_to_ndc`) + an unclipped stage rect | `pixelbender_effect_glassDisplace` (+1, 17/1003) | S-M | must stay md5-identical on the other 14 `viewport_dimensions` image tests (edittext `*_scale2` ×3, filters `*_scales_with_screen` ×4, `pixelbender_effect_twirl`/`BlurredFocus`, `bitmapdata_draw_cab_quality`, `stage3d_program_constants_bytearray_be/le`, `stage_scale_factor`, `edittext_get_char_index_at_point`) |
| **w2-z-projection** | AVM2 compose walk: accumulate tz, scale about the viewport centre by f/(f+tz), cull at tz ≤ −f | `displayobject_z` (+1) | S | the model is in this report. Check Ruffle's 1-px edge behaviour on the 15.9× bitmap |
| **w2-atf-dxt5** | `avm2_stage3d.c` ATF format 5 record walk + BC3 decode | `stage3d_texture_bytearray_compressed_raw_alpha` (+1) | S-M | tol 4 / 66 |
| **w2-avm2-video-stamp** | `avm2_display.c` `attachNetStream` + Video render; `avm2_net.c` FLV demux of the first keyframe; `video_codec.c` AVC config → extradata + NALU framing | `h264_multinalu` (+1) | M | the first slice of an AVM2-video arc. The timed-playback follow-on is worth +10 (`h264 [frame2..11]`) + `netstream_seek_flv` |
| **w2-draw-bigcap-aa** (prototype-first) | `avm2_display.c` cap (size to the largest live BitmapData, not a constant); CPU `draw()` 4x-sample AA | `acid-bitmap-draw_quality_high` (+1), `_low` (kf, Flash-correct, +1) | M | the cap alone is a −72 % band move. **Sweep first** for other AVM2 rows whose runtime BitmapData exceeds max(stage, 256): they render blank silently today |

Not funded: JPEG-XR (pending the dependency ruling), RTT (only with the advance fix), ShaderFilter/blendShader (arc), definefont4
(FTE arc), CPU-budget Stage3D rows.

## 4. New unclaimed leads

- **The silent blank class above** (`avm2_display.c:18261`): any AVM2 runtime BitmapData bigger than max(stage, 256) is never
  drawn. This is unpriced corpus-wide, and real games build atlases like this.
- **`acid-color-0` TextField colour/background bug** (16 697 channels: green text drawn red, missing green background). A
  correctness/band lead; the flip is blocked by logo edges.
- **`stage3d_texture` autosize width**: the baked default-font advances are rounded to tens, giving 486 px of box-width residual.
- **The AVM1 graphics-mode Video draw** for `netstream_play_flv_screen` renders nothing, which contradicts its own RVF entry text.
- **`movieclip_line_gradient_style`** → the stroke-join alpha overlap (sibling `w1-stroke-staircase`).
- **`font_lookup_as3`**: device column C-F glyph mismatch (unexplained; C, D, E, F differ while A, B and @ match).

## LOCAL ORACLE REQUESTS

1. **Flash/Ruffle, `visual/fonts/font_lookup_as3/test.swf`, frame 1.** Is the golden's top-right column (`embedFonts = true`,
   `font = ""`) what Flash draws, or Ruffle's device fallback? Need: the golden's provenance (`git log` of the PNG upstream / the
   PR that added it), or a Flash capture. This decides whether `avm2_text.c:2807`'s "draw nothing" rule must split on an empty
   name.
2. **Ruffle exporter, `avm2/stage3d_bitmap/test.swf`**: a trace of the 7 `Math.random()` results and 7 `getTimer()` values.
   Compare with ours to tell RNG drift from timer drift (the s20 placement residual).
3. **Ruffle exporter, `avm2/bitmapdata_draw/test.swf`, frame 1**: the two TextFields' `getLineMetrics(0)` (ascent / descent /
   leading) and `textHeight`. This localizes the uniform 1-px baseline gap in §1 row 2 (test font: upem 1024, hhea 784/−247/170,
   typo 1024/−171/170, no USE_TYPO_METRICS).
4. (Optional) **Ruffle exporter, `avm2/displayobject_z/test.swf`**: the rendered PNG at `quality = "high"`, to confirm the cull
   threshold (−480.25) and edge rounding before w2-z-projection tunes the 175-channel overshoot.
