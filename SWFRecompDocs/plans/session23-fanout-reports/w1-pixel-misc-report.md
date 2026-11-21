# w1-pixel-misc — pixel misc tail + harness gaps (session 23, wave 1)

**New files:** `w1-pixel-misc-report.md` (this), `w1-pixel-misc-prototype.patch` (all five
prototypes in one diff against `origin/master` `ad99dc15`; sources reverted on the branch).
The hunks are independent per file; see "Prototype map" below.

Environment: cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn). Upstream tests downloaded at
Ruffle `0ddd12b6a` (categories avm1 avm2 visual stage3d from_gnash from_shumway timeline text swf
import_assets audio fonts mixed_avm). Ruffle source: blobless clone at `0ddd12b6a`; h263-rs cloned at
the rev Ruffle pins (`8215bc7a7`).

**Cloud fidelity, proven first.** `avm2/netstream_play_flv` and `avm1/netstream_play_flv` before-renders
are md5-identical to CI's actual PNGs on `origin/ruffle-image-results` @ `35f66723` (= images run
**`38995363802`**, s22 final; the new baseline images run `44922638965` was still *queued/in progress* at
report time and had not force-pushed the branch):
`133196064b6b140c60f9a27964fd4296` / `e48cfd789b6e795a4ed5d3d93a9de184`. Every other before-number below
also reproduced CI's outlier count exactly (acid-color-0 17376, h263 10808, deblocking 104,
drawwithquality n/a, stage3d_bitmap 135407, …), so local grading is CI-grade for these rows.

---

## Verdicts (lead)

| # | Row(s) | Verdict | Measured (before → after, CI-grade) | Flips |
|---|---|---|---|---|
| 1 | Spark/H.263 (`FF_IDCT_FAAN`) | **GO — 9-line patch** | avm2 `netstream_play_flv` 179 → **0**; avm1 `netstream_play_flv` 44 → **0**; `visual/video/deblocking` 104 → **0**; `colorconversion/h263` 10808 → **3** (1 px, still fail) | **+3** |
| 2a | `pixelbender_effect_glassDisplace_shaderfilter` | **GO-candidate for wave 2** (scoped: Bitmap-source display ShaderFilter + `applyFilter(ShaderFilter)`), ~250 LOC, not prototyped | 879464 | +1 (medium confidence) |
| 2b | `blend_shader_luma_lighten` | **NO-GO** | 40318 | 0 this session |
| 3a | `stage3d_texture` | **GO as enabler (RTT + budget), no flip alone** | 204781 → **2786** (3D residual: 2 px; rest = text glyph advances) | 0 alone; +1 with the glyph-advance fix |
| 3a′ | `stage3d_bitmap` (rider, not on brief) | budget raise alone | 135407 → **48** (limit 24; 16 px = one glyph 1 px off) | 0 alone; +1 with the glyph-advance fix |
| 3b | `acid-color-0` | **GO as correctness/band** (premise "band, not flip" CONFIRMED) | 17376 → **749** | 0 (gradient residual) |
| 3c | `definefont4` | **NO-GO** — nothing short of three independent links | blank render | 0 |
| 4 | Harness: `ignore = true` + `[subtests]` images | **GO — GRADING-INSTRUMENT CHANGE** (moves numbers without changing renders) | denominator **+2** (−1 ignored, +3 subtest rows); with the `drawWithQuality` one-liner the two new drawwithquality rows **pass** | see §4 |

**Summary of priced flips for wave 2:** +3 certain (FAAN); +2 conditional on the harness change landing
together with a one-line `drawWithQuality` alias (measured passing, but near their limits); +1 medium
(ShaderFilter); +2 (`stage3d_texture`, `stage3d_bitmap`) gated on one default-font glyph-advance fix that
belongs to the glyph-precision owner.

---

## 1. `netstream_play_flv` — Sorenson Spark decode precision

**Mechanism.** We decode FLV1 with libavcodec (`video_codec.c::decode_via_libavcodec` /
`video_decoder_create`), then do the Ruffle-exact BT.601 conversion and the `h263-rs-deblock` port
(both already byte-exact). The remaining drift is the **IDCT**. Ruffle's `h263-rs`
(`h263/src/decoder/cpu/idct.rs`) is a separable **f32 reference IDCT** with a precomputed `BASIS_TABLE`,
`(v/4 + signum(v)*0.5) as i16` rounding (half away from zero), clamp to [-256,255] and add-then-clamp to
u8. libavcodec's default `FF_IDCT_AUTO` resolves to the integer `simple_idct`, which drifts 1–4 LSB per
block and compounds through P-frames (hence 179/44 outliers at the 60th frame).

**Measured sweep of libavcodec's x86 IDCTs** (avm2 row unless noted; `idct_algo` set before `avcodec_open2`):

| `idct_algo` | avm2 nsp_flv | avm1 nsp_flv | h263 | deblocking |
|---|---|---|---|---|
| 0 AUTO (today) | 179 / max 4 | 44 / 3 | 10808 / 2 | 104 / 4 |
| 1 INT | 143 / 3 | – | – | – |
| 2 SIMPLE, 3 SIMPLEMMX, 128 SIMPLEAUTO | 179 / 4 | – | 10808 / 2 | – |
| 14 XVID | – | – | 4671 / 2 | – |
| **20 FAAN (float AAN)** | **0 / 0** | **0 / 0** | **3 / 1** | **0 / 0** |

**Patch** (in the prototype patch, `video_codec.c`): `flv1_select_idct()` sets `idct_algo = FF_IDCT_FAAN`
only for `AV_CODEC_ID_FLV1`, in both the one-shot and the persistent decoder. VP6 (vp3dsp) and H.264
(h264dsp) ignore `idct_algo` anyway; the scope is belt-and-braces.

**No-regression evidence (all CI-grade, identical before/after):** `colorconversion/vp6` 0, `vp6a` 0,
`video/h264` frame2–11 all 0, `h264_multinalu`, `from_shumway/acid/acid-video` .01/.10/.20 (270/254/101),
avm2 `netstream_seek_flv` 27/271. Corpus census of every SWF/FLV carrying codec 2 (scanner over all
downloaded suites): 15 files; the image-graded ones are exactly the 6 rows above plus
`Video-EmbedSquareTest` (unchanged by FAAN; see drift note) and avm2 `netstream_seek_flv` (unchanged).
avm1 `netstream_seek_flv`'s image comparison is commented out upstream.

**h263's last pixel** (289,447: ours 48,48,48 vs 47): FAAN ends in `lrintf` (round-half-to-even), while
h263-rs rounds half away from zero. libavcodec exposes no IDCT hook, so exact closure means **porting
h263-rs's decoder to C** (~2–3k lines incl. VLC tables) for **one** row. **NO-GO**; completion mechanism =
that port, only if Spark ever matters beyond this row.

**Risks for wave 2:** (a) FAAN is plain C float in Ubuntu 24.04's libavcodec 60.31.102; CI is pinned to
the same image (`08709f658`), so bit-identity should hold; still run CI before booking. (b) Check whether
the Emscripten build links libavcodec at all (`SWFModernRuntime/CMakeLists.txt:21` defaults
`WITH_LIBAVCODEC` OFF on one arm). If it does, FAAN applies there too; no browser pixels are graded either way.
(c) Trace dispositions: both `netstream_play_flv` names sit in `ignored_tests.txt` (avm1 root list,
`avm2/ignored_tests.txt`) for **trace**; the image rows are graded regardless.
Owner: `SWFModernRuntime/src/actionmodern/video_codec.c` (decode_via_libavcodec / video_decoder_create).
Mode parity: graphics-only effect (no-graphics never decodes pixels into a graded image).

---

## 2. PixelBender: ShaderFilter and blendShader

**What exists today.** `avm2_pixelbender.c` has the full CPU PBJ parser + evaluator (P1–P3, 26/27
census green). The evaluator is reachable **only** through `ShaderJob.start` (`sj_start`, ~line 1775).
`ShaderFilter` is a real class (`avm2_pixelbender.c:2159-2230`) that round-trips through
`DisplayObject.filters` (`avm2_filters.c` kind `AVM2_FILTER_SHADER`), so the two trace lines pass. But:
- the display-list filter arm (`avm2_display.c::avm2_filter_renderable`, ~19572) renders only
  blur/shadow/glow/bevel/displacement, so a ShaderFilter is silently dropped;
- `BitmapData.applyFilter` (`avm2_bitmap.c` ~3355) handles color-matrix/blur/displace (+ passthroughs),
  not SHADER, so out2 stays solid blue;
- `blendMode = "shader"` composites as NORMAL; `render_webgpu.c`'s `blend_shader_*` pipelines are the
  standard complex blend modes, not PixelBender.

### 2a. `glassDisplace_shaderfilter`: GO-candidate, ~250 LOC, flip probability medium

Two independent halves, and both are needed (tol 3 / 380 outliers over a 1000×1000 frame):
1. **`applyFilter(src, rect, pt, ShaderFilter)`**: refactor `sj_start`'s evaluator body into
   `pb_run(shader_data, input0_override, out, w, h, filter_mode)`. Filter mode differs from ShaderJob
   in sampling: transparent-black outside the input rather than clamp (`avm2_pixelbender.c:1224`
   comment, naga-pixelbender lib.rs:106-118). **Semantic found in the golden:** the shader output in
   out2 covers rows 390–764 × cols 0–499, i.e. the *whole 500×375 source*, not the 20×20 `sourceRect`.
   Ruffle's `ShaderFilter::apply` (render/wgpu/src/filters/shader.rs) binds the whole source texture as
   input 0 and renders over the target; wave 2 should port that extent rule exactly. ~120 LOC.
2. **Display-list ShaderFilter on a `Bitmap`** (out1): CPU-filter the BitmapData's pixels (input 0 =
   the bitmap, cached by pixel version) and draw the result instead of the source. ~100 LOC in
   `avm2_display.c`. General display objects (vector content) would need a mid-frame capture/readback
   that the WebGPU path does not have: out of scope, and not needed by this row.

Precision evidence: the non-filter sibling `pixelbender_effect_glassDisplace` passes at **17 / 1003**
with the same CPU evaluator and shader, so two 500×375 outputs at ~17 each sit well inside 380.

**Rider lead (unpriced):** `avm2/pixelbender_dithering` fails at **2 764 800** outliers (our frame is one
flat purple colour). The SWF uses `BitmapData.draw` + a `ShaderFilter` on a Bitmap (`bitmapBaseData`,
`shaderFilter`, `filters`), so half 2 above is likely its owner too, but the flat colour says something
upstream (the draw of `mcScene`?) also fails. Re-diagnose before booking.

### 2b. `blend_shader_luma_lighten`: NO-GO

Ruffle (`render/wgpu/src/surface.rs:192-225`) runs the PBJ as a GPU shader with inputs
`(background = parent blend buffer, foreground = layer texture)`. We have no GPU PBJ path and no
mid-frame readback, so either:
- **port `naga-pixelbender` → WGSL** (1958 Rust lines; also the general completion mechanism for
  display-list ShaderFilter on vector content), or
- add a **native-only synchronous mid-frame readback** (backdrop + layer → CPU eval → upload), which
  diverges browser from native.
One row (golden also carries an AA FIXME: tol 2/3300, 64/280, 180/0). **Completion mechanism: the
PBJ→WGSL translator, when a second consumer appears.**

---

## 3. `stage3d_texture`, `acid-color-0`, `definefont4`

### 3a. `stage3d_texture`: RTT prototyped. "True advances" are glyph advances; frame advances already match

s20 (`w1-stage3d-report.md` §6) declined RTT because device fonts were empty boxes. Device fonts have
since landed, so I re-priced it. Our Stage3D is a CPU rasteriser (`avm2_stage3d.c`, `S3dBackend`);
`setRenderToTexture` was validation-only and `setRenderToBackBuffer` was `s3d_noop`, so the full-screen
quad sampled a never-written texture (black).

**Prototype** (`avm2_stage3d.c`, ~100 LOC, trailing `S3dBackend` fields): `setRenderToTexture` parks the
back-buffer pointers, allocates an RTT surface of the texture's size with `sample_count = antiAlias`
rounded down to {1,4} (Ruffle `context3d/mod.rs:779`), seeds it from the texels (LoadOp::Load), and makes
depth/stencil follow `enableDepthAndStencil`. `setRenderToBackBuffer` (and `configureBackBuffer`) resolve
it into the texel store (same per-sample quantise + floor-mean as `s3d_present`, alpha kept) and restore.

| step | `stage3d_texture` |
|---|---|
| CI / before | 204781 |
| + RTT | 23864 (output identical for **every** `num_ticks` 5..14, i.e. frozen) |
| + `S3D_FRAG_BUDGET` 12M → 24M | 14933 |
| + budget 48M (or 96M) | **2786**: 3D area 2 px; 928 px in two text lines |

The identical-for-every-tick-count result exposed the real second mechanism: **the 12M fragment budget
latches mid-run** (4× MSAA 1024×512 RTT + a full-screen quad per frame), freezing the frame. With the
budget lifted, `num_ticks` 5 is the minimum (4: 14933, 6: 14829, 8: 23797, 12: 31783). **Refutation:**
our frame-advance count already matches Ruffle's, even though Ruffle's runner calls
`player.tick(1000/24 ms)` against `stage.frameRate = 60`. The board's "true advances" is a different
thing: the residual is **text**. In "Driver: Dummy Ruffle driver" and "Shapes: (rows=5, …)", glyphs
after the first few drift by 1 px. That is a default-font glyph-advance rounding defect.

**Rider, `stage3d_bitmap`** (not on the brief): the budget raise alone takes it **135407 → 48**
(limit 24). This refutes s20's reading ("residual is sprite placement: 7 `Math.random` + 7 `getTimer`").
The frame was frozen by the latch. The last 16 px are one glyph: the final `0` of "FPS: 0" sits 1 px to
the right of the golden's (ASCII dump in my notes: identical bitmaps, x+1). **Same mechanism as
stage3d_texture's text.**

**Budget cost check:** at 48M, `stage3d_fractal` (1104123) and `away3d_advanced_shallow_water_demo`
(1326849) grade **identically**, run time +1.0 s / +0.6 s. **24-row Stage3D sweep** (all of
`avm2/stage3d_*` + `stage3d/*` with images) with RTT+48M: every row byte-for-byte the same message as
the baseline JSON, except (a) `stage3d_bitmap` (improved, above) and (b)
`stage3d_texture_bytearray_compressed_alpha` 1/66 → **8192**, which **fails identically on clean master**.
That is upstream drift: `5021d0ed7` "Fix second alpha endpoint index in COMPRESSED_ALPHA ATF textures"
re-goldened it. The drift slots own it; it's a cheap port.

**Verdict:** GO to land RTT + budget 48M as an enabler (2 rows from ~10⁵ to ≤3k/48). Flips (+2) need the
default-font advance fix. Lead for the glyph-precision owner: AVM1 already rounds device-font advances
to whole pixels (`action.h` TextFieldGlyphInfo `device_font` comment, citing `font_like.rs`
`FontType::Device`); check whether the AVM2 TextField layout (`avm2_text.c`) does the same for default-font /
device faces. Both rows show exactly a cumulative 1-px shift.

### 3b. `acid-color-0`: band confirmed; owner found; 17376 → 749

This SWF (v21, FileAttributes AS3, but **no DoABC/DoAction**) renders through the **AVM1/timeline
text path**, not `avm2_render_text`. I confirmed this: an instrumentation probe in `avm2_render_text`
never fires. The two text diffs (first "ABC" should be green; the second "Hello" box should be green
with black text) are EditTexts inside sprites placed with a colour transform: depth 22 sprite → EditText
13 with cx (rMult 0, gAdd 255); depth 27 sprite → EditText 16 with cx (0,1,0).
**Mechanism:** `TextFieldRenderInfo` and `TextFieldGlyphInfo` (`include/actionmodern/action.h`) carry
**no colour transform at all**. Box colours and glyph run colours go to the GPU as literal RGB, so
**no ancestor cxform ever reaches AVM1/timeline text**.

**Prototype** (`action.c` + one line in `swf.c`): compose the ancestor cx chain (diag mult + add) in
the MovieClip text iterators (`mc_text_cx` over `mc->parent`, reading each entry's `cx_overridden`
fields or its baked `cxform_data` slot) and in the orphan walk (`otf_walk_dl`), and apply it on the
CPU to background, border, `text_color` and every run colour. Result: **17376 → 749**, both text items
pixel-correct. The remaining 410 px >tol: **365 px in the radial-gradient row** (y 300–500, max diff
≤39, a gradient-precision mechanism) plus ~45 glyph/ring edge pixels. Limit is 3, so it **stays a band**.

**No-regression sweep:** every image-graded AVM1/timeline test that has a DefineEditText and no DoABC
(36 tests: avm1, gnash, shumway acid/text-bind, `text/*`, `visual/edittext/*`, cache_as_bitmap text,
filters/bevel*/glow*/drop_shadow, focus_highlight, text_field_mask, …). **34 identical**; changed only
`acid-color-0` (intended) and `Video-EmbedSquareTest` (drift, below).
**Wave-2 notes:** the prototype's `g_proto_tf_app` global set in `swf.c` is a hack; plumb
`SWFAppContext` properly. Alpha is untouched (already handled). Also, `avm2_display.c::avm2_render_textbox`
draws the AVM2 box with cxform slot 0 (alpha only), a **latent AVM2 twin** of this bug with no
measured corpus row.

### 3c. `definefont4`: NO-GO (nothing short of three links)

Our render is blank (CI 16086, max 255; tol 1 / 0 outliers). The SWF embeds the **entire TLF framework**
(`flashx.textLayout.*`). The pixels need **all** of:
1. **DefineFont4** (tag 91): the recompiler emits nothing for it (no handler in `SWFRecomp/src`), and the
   runtime has no CFF outline path. Cheapest route: Ruffle uses `ttf-parser`; we already vendor
   `SWFRecomp/lib/stb/stb_truetype.h`, which parses OpenType-CFF outlines.
2. **TLF compose completing** (arc §16/§23: last known stop was a null `getEffectiveLineHeight` in
   `TextFlowLine.getLineLeading`; trace is now silent-pass, render state unverified).
3. **TextLine glyph rendering**: Ruffle backs FTE `TextLine` with an EditText. **No pixel-graded
   TextLine test exists** in the corpus (all 14 `textblock_*`/`textline_*` rows are trace-only), so this
   path has never been checked against a golden.
One row at tolerance 1 / 0 outliers. **Completion mechanism: a "DefineFont4 + TextLine render" mini-arc
(not the full FTE arc), funded only if a second DefineFont4/FTE pixel row appears.**

---

## 4. Harness: `ignore = true` and `[subtests]` images (GRADING-INSTRUMENT CHANGE)

**This moves the pixel numbers without changing a single render.** Book it separately from render
flips, and run one images CI pass with it alone (or diff by row name) so the before/after attributions
stay clean.

**Census (all downloaded categories, `tomllib`):** top-level `ignore = true` with image comparisons =
**1** (`avm2/bitmap_pixelsnapping`). `1600c5ba6` only renamed `num_frames` → `num_ticks`; `ignore = true`
is unchanged. Image comparisons inside `[subtests]` = **5** across 3 tests. (3 avm1 tomls fail
`tomllib` on TOML 1.1 inline tables; none has images.)

**Ruffle semantics (read at `0ddd12b6a`):** `tests/framework/src/options.rs::deserialize_toml`: with
≥2 subtests, Ruffle runs **each subtest** with the top level **deep-merged** into it
(`merge_into_subtest`: tables merge, scalars subtest-wins) and grades only the subtests' comparisons.
`device_font_renderer = "freetype"` runs only with the optional `freetype` feature
(`backends/ui.rs FontRendererKind::can_run`). `ignore = true`: the test is not run at all.

**Exact change (prototyped in `ruffle-tests/verify_output.py` + `scripts/build_image_report.py`):**
1. `parse_image_comparisons`: top-level `ignore = true` → each comparison gets `ignored_upstream`.
   With ≥2 subtests → `_parse_subtest_image_comparisons`: deep-merge per subtest, one comparison per
   (subtest, cmp) keyed **`<subtest>__<cmp>`**, with `png_name = <cmp>` (expected file
   `<cmp>.expected.png`), `msaa` from the merged `with_renderer.quality`, `known_failure` from the
   subtest. Freetype subtests are tagged `ignored_upstream`. Top-level comparisons of a subtest test
   are no longer graded on their own (Ruffle never grades them).
2. Per-subtest quality: `MSAA_OVERRIDE` + `_rerun_subtest_variants()` rebuild and re-run once per
   distinct MSAA that differs from the main build, capturing only those comparisons into the same
   build dir. The main run's `CAPTURE_TRIGGERS` skip them.
3. Comparison loop: expected path uses `png_name`. An `ignored_upstream` comparison is still compared
   (stats kept) but recorded as `status: "ignored"`, `would_pass`, `ignored_upstream: <reason>`.
4. `build_image_report.py`: `comparisons` (the denominator) and `pass_rate` exclude `ignored` rows,
   and a new `ignored` total is emitted. Rows stay in `results` for the board ("board flag rather than skip").

**Measured effect per row (local, CI-grade):**

| row | before (graded as) | after |
|---|---|---|
| `avm2/bitmap_pixelsnapping` `output` | fail 3831 | **ignored** (leaves denominator) |
| `fonts/leading_device_font` `output` | pass | renamed **`embedded__output`**: pass (same config: tol 128 inherited); `freetype__output` ignored |
| `visual/edittext/edittext_device_transform_basic` | not graded | **`embedded__output`: FAIL 1020** (2 checks: 0/90, 128/14); `freetype__output` ignored (also `known_failure`) |
| `avm2/bitmapdata_drawwithquality` | not graded | `low__output.low` + `high__output.high`: **FAIL 47381 / 47426** today; **PASS 3152/3200 and 3197/3204** with the one-line `drawWithQuality` alias below |

**Denominator: +2** (−1 + 1 + 2; the leading_device_font row is a rename, so `image_status_diff` will
show one removed + one added name, which is the same comparison). Numerator: −0 / +2 depending on
whether the alias lands in the same wave. Fails: −1 (pixelsnapping) +1 (edittext embedded) [+2 without
the alias].

**`drawWithQuality` alias** (prototype, `avm2_bitmap.c:4025`): it was registered as `bd_noop`; mapping it
to `bd_draw` (identical first 6 args, quality ignored) is consistent with s22's decided ruling (Flash
anti-aliases `BitmapData.draw()` at LOW too; RVF entry). Both rows pass but near their limits
(48 and 7 outliers of headroom). Put them in the canary watch list if landed.

Trace side is untouched (`bitmap_pixelsnapping`'s trace is still graded; Ruffle ignores the whole test.
That is a separate trace-instrument question, not priced here).

---

## Prototype map (`w1-pixel-misc-prototype.patch`)

| file | hunk | item |
|---|---|---|
| `SWFModernRuntime/src/actionmodern/video_codec.c` | `flv1_select_idct` + 2 call sites | §1 (land as-is) |
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | RTT fields, `s3d_rtt_end`, set_render_to_texture/back_buffer, `S3D_FRAG_BUDGET 48000000u` | §3a |
| `SWFModernRuntime/src/actionmodern/action.c` + `src/libswf/swf.c` | `otf_entry_cx`, `otf_cx_rgb`, `mc_text_cx`, walk composition, colour application; `g_proto_tf_app` hack | §3b (re-plumb app ctx) |
| `SWFModernRuntime/src/avm2/avm2_bitmap.c` | `drawWithQuality` → `bd_draw` | §4 rider |
| `ruffle-tests/verify_output.py`, `scripts/build_image_report.py` | ignore/subtests instrument | §4 |

Not regression-suite-checked (wave 1). Wave 2 must run the `regression` suite and the render canary.
`video_codec.c` / `avm2_stage3d.c` / text are graphics-only effects; `action.c`'s iterators run in
graphics mode only for rendering, but run a no-graphics spot check anyway (shared TU).

## Drift hit (not booked; drift slots own these)

- `from_gnash/misc-ming.all/Video-EmbedSquareTest`: CI 12 → local **1794** on clean master. Upstream
  `74323048b` re-goldened it (quality low→high, new `output.ruffle.png`, `known_failure = true`).
- `avm2/stage3d_texture_bytearray_compressed_alpha`: pass (1/66) → **8192** on clean master. Upstream
  `5021d0ed7` changed the COMPRESSED_ALPHA second alpha endpoint index and the golden. Port that fix.

## Refutations

1. **"stage3d_texture needs true (frame) advances"**: refuted. Frame count already matches (n=5 is the
   unique minimum). The second mechanism was the **12M fragment-budget latch**, and the residual is
   **glyph** advances.
2. **s20 "stage3d_bitmap residual is sprite placement (Math.random/getTimer)"**: refuted. It was the
   budget latch freezing the frame. Budget alone: 135407 → 48.
3. **s20 "RTT flips nothing"**: still true for flips, but stale as a price. With device fonts landed,
   RTT+budget takes the row from 204781 to 2786, and the remainder is one text mechanism shared with
   stage3d_bitmap.
4. **"acid-color-0 is a TextField colour bug"**: true, but the owner is not AVM2 text. It is the
   AVM1/timeline text pipeline, which has **no colour-transform plumbing at all** (an AS3-flagged SWF
   with no ABC). Even fixed, it stays a band (gradient residual).
5. **Brief item 1 scope**: `visual/video/deblocking` (104) is the same IDCT mechanism and flips too
   (it was not on the brief).

## New unclaimed leads

1. **Default-font / device-face glyph-advance rounding in AVM2 TextField layout**: it gates
   `stage3d_texture` and `stage3d_bitmap` (both otherwise ≤3k/48 after §3a). Evidence: cumulative 1-px
   x shifts within a line; AVM1 already rounds device advances per `font_like.rs`.
2. `drawWithQuality` was a no-op (`bd_noop`); one-line alias, +2 once the harness grades subtests.
3. `pixelbender_dithering` (2.76M, flat purple frame): ShaderFilter-on-Bitmap plus an upstream draw issue.
4. `acid-color-0` radial-gradient residual (365 px, max 39): gradient interpolation precision, likely
   shared with other acid gradient rows.
5. AVM2 `avm2_render_textbox` ignores RGB colour transforms (slot 0); no row measured.
6. `stage3d_texture_bytearray_compressed_alpha`: port upstream `5021d0ed7` (drift slots).
7. Spark exactness for `colorconversion/h263` (1 px): only via an h263-rs port. Parked.

## LOCAL ORACLE REQUESTS

None required. Optional: a current-Ruffle export of `avm2/pixelbender_effect_glassDisplace_shaderfilter`
(1 tick) to confirm the applyFilter extent rule (whole source vs sourceRect) against Ruffle rather than
inferring it from the golden.
