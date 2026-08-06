# w1-gfx-board — session 12 pixel-axis board regeneration + ranking

**Agent:** wave-1 `w1-gfx-board` (read-only diagnosis).
**Repo state:** `f166e424e` (master).
**Board provenance:** image run `31075033086`, JSONs built at `6de650432`,
2026-08-06T06:23:36Z — i.e. the s11 closeout run, exactly the documented
baseline. `ruffle-image-results` extracted (not checked out) to
`<scratch>/image-results`, 15 MB, 306 failing-comparison PNGs.

Regeneration command (22 s at `--jobs 2`):

```bash
git fetch origin ruffle-image-results
git archive origin/ruffle-image-results | tar -x -C <scratch>/image-results
python3 scripts/image_triage.py --images-dir <scratch>/image-results --jobs 2 \
    --out <scratch>/board.json --markdown <scratch>/board.md --top 60
```

Totals: **566 unique comparisons, 257 pass (45.4%), 306 fail, 3 skip.** Four
comparisons carry HARD image-axis dispositions and are excluded → **302 live
failing comparisons**. Nine carry SOFT (trace-axis) flags and are KEPT
(`avm2` 8, `from_shumway` 1); applying trace ignores would have deleted 113 of
403, per playbook §3.

---

## 1. Accounting check: zero worsened bands persist

`scripts/image_status_diff.py 64d1f266b 34c0bd012` (s10 run `30713776612` at
`c4496a4c8` → s11 run `31075033086` at `6de650432`):

```
fail 346 -> 306 (-40)   pass 217 -> 257 (+40)   REGRESSIONS: 0
BAND MOVES: improved 73 / worsened 0 / band-only 0
NEW: regression/mask_sibling_union [output] pass    GONE: 0
```

**The s10 worsened-band watchlist is fully cleared and nothing new worsened.**
Concretely:

- `edittext_caret_empty` ×12 — all 12 now `pass` (s11 caret work).
- `from_gnash .../place_object_test` — still `d_moderate` 42819, unchanged
  (0.0%), still double-`known_failure`; the s11 KEEP disposition holds and it
  did not degrade further.
- `cache_as_bitmap/masks [.01–.07]` — all seven byte-identical (0.0%), still
  `extra_element d_moderate`; the s11 KEEP ("mask-blocked") disposition holds.

**Frame-phase suspects: ZERO.** `image_triage.py` printed no frame-phase
section this run — `simple_loop_test` now passes frames 1,2,3,5,6,7 and
`edittext_border_transform` collapsed to a single `hairline_edge_drift` row.
The frame-phase channel that s9/s10 mined is exhausted.

Two stale dispositions the board flags (worth a one-line doc note, not a
session): `avm1/display_object_properties` now PASSES; the
`simple_loop_test` ACCEPTED_DIFFS entry (scoped frames 1–2) now covers a
passing comparison.

---

## 2. Ranked cluster board (302 live failing comparisons)

`owned` = claimed by a session-12 sibling (text/auto_size+fonts near-passes,
scrollRect, AVM2 static-bitmap upload, masks B/C/D + `avm2/mask_reapply`).

| # | mechanism key | cmps | tests | near-pass | owned | **unowned** | fixability verdict |
|---:|---|---:|---:|---:|---:|---:|---|
| 1 | `hairline_edge_drift` | 56 | 44 | 42 | 7 | **49** | **A-INHERENT (presumed).** Post-MSAA this is the residual lavapipe-vs-Flash rasterisation gap. Do not scope as a cluster. |
| 2 | `same_geometry_wrong_fill` | 54 | 38 | 5 | 4 | **50** | **MIXED — highest-yield head.** 18 = Shumway acid (see §4, one mechanism ×16), 7 filters, 6 blend, 5 bitmapdata, 3 gradients. |
| 3 | `blank_render` | 53 | 54 | 0 | 3 | **48** | **ARC.** 26 Stage3D + 7 video + 7 acid + 3 gradient + 2 bitmap-fill + 2 jpegxr. Unimplemented backends; confirmed §5. |
| 4 | `extra_element` | 30 | 21 | 0 | 19 | **11** | Mostly OWNED (masks 16, scrollRect 3). Unowned residue = filters 6 (halo/edge growth), acid-clip-3 ×2. |
| 5 | `diffuse_mixed` | 24 | 24 | 10 | 2 | **22** | **CAPPED head.** 8 = `visual/blend_modes/*` at 20–54 excess channels (a_epsilon sub-pixel ties, s11 ruling — do not scope). Live tail = 5 acid + 2 gradients. |
| 6 | `missing_element` | 17 | 17 | 2 | 3 | **14** | B-FIXABLE-ish: 4 filters (blur size/pass), 4 text (3 KF), 2 video, 1 gradient. |
| 7 | `halo_penumbra` | 17 | 17 | 0 | 3 | **14** | **B-FIXABLE, cheap prior (0.90).** 7 EditText background/border/device-transform, 5 filters (bevel ×3). |
| 8 | `unrelated_content` | 16 | 8 | 0 | 4 | **12** | 9 = `visual/video/h264` frames (decoder arc), 1 away3d, 1 timeline_loop, 1 edittext_bounds_vs_position. |
| 9 | `content_displaced` | 12 | 12 | 0 | 2 | **10** | 3 displacement-map filters, `stage_scale_factor`, `opaque_background`, 2 text. |
| 10 | `row_banded` | 7 | 7 | 2 | 1 | **6** | 4 of 6 are Ruffle `known_failure` (acid text). Low yield. |
| 11 | `no_render` | 5 | 3 | 0 | 0 | **5** | acid/acid ×2, acid-large, acid-video ×2 — harness produced no render at all. |
| 12 | `whole_frame_wrong` | 3 | 3 | 0 | 1 | **2** | `bitmapdata_applyfilter_blur`, `gradient_nonsequential_ratios`. |
| 13 | `localized_region` | 3 | 3 | 0 | 1 | **2** | `graphics_bad_direct_commands`, `captions` (KF). |
| 14 | `offset_translation` | 3 | 3 | 0 | 1 | **2** | s10 already recommended **retiring this cluster** (±8px shift probe saturates on small images). Confirmed still noise. |
| 15 | `global_color_shift` | 2 | 2 | 0 | 0 | **2** | 1 KF; `error_stack_trace_release_swf17` (200 excess). |

Unowned total: **250 of 302**. Owned by siblings: 52.

### Unowned by FAMILY (the more actionable cut)

| cmps | KF | tests | family |
|---:|---:|---:|---|
| 44 | 6 | 24 | Shumway acid render tests |
| 31 | 2 | 31 | **Filters (blur/glow/drop-shadow/bevel/displacement)** |
| 30 | 4 | 27 | Text: EditText / layout / HTML |
| 30 | 0 | 30 | Stage3D / AGAL / shaders *(arc)* |
| 21 | 0 | 11 | Video / NetStream *(arc, partially cheap — §6)* |
| 19 | 2 | 19 | BitmapData / drawing API |
| 18 | 0 | 17 | Blend modes *(8 capped, 2 = F5, 1 = F7-AVM2)* |
| 13 | 1 | 13 | Gradients |
| 10 | 0 | 4 | Timeline / frames *(8 are hairline a_epsilon)* |
| 8 | 0 | 3 | Morph shapes / tweens *(all hairline b_tiny)* |
| 6 | 1 | 6 | Shapes / fills / tessellation |
| 5 | 0 | 5 | Loader / external assets |
| 3 | 0 | 3 | Buttons |

---

## 3. F5 — layer groups (`layer_alpha` / `layer_erase`): scoped, and **refuted as a flip item**

### Measurement first

All four of `layer_alpha`, `layer_erase`, `alpha_no_layer`, `erase_no_layer`
render **byte-identically** on our side:

```
f95756f39fe8b3d8051a3a27470a754e   {layer_alpha,layer_erase,alpha_no_layer,erase_no_layer}/output.actual.png
```

That is the whole F5 defect in one line: mode 11/12 objects are dropped
unconditionally, so a layer group's alpha/erase child never happens. Current
state: both at `same_geometry_wrong_fill / d_moderate`, excess 66791 / 66996,
ink IoU 1.00, `missing_ink_frac` 0.0 (nothing missing — the *fill* inside the
group is wrong). s10→s11 they moved -11% (MSAA rider), nothing more.

### The refutation (attack this premise before wave 2 scopes it)

`layer_alpha` tolerance = 2, `layer_erase` tolerance = 3, **`max_outliers = 0`
on both.** Their no-layer siblings — which we already render *correctly*, since
"drop the object" is the right answer with no Layer above — still sit at
**50 excess channels each** in the capped `a_epsilon` tie class. I located
those residuals:

```
alpha_no_layer  tol=2  outlier channels=50  px=19
layer-group affected region: y[50,329] x[125,365]  (30861 px)
residual pixels INSIDE that region: 3 of 19
```

**16 of the 19 residual outlier pixels lie outside the region a layer group
would ever repaint.** So a pixel-perfect F5 lands `layer_alpha` at ≈40–50
excess channels: a `d_moderate → a_epsilon` band move into the CAPPED tie
class, and **zero flips**. F5 is worth doing for browser-game fidelity
(alpha/erase inside a layer is common in real content), not for the
scoreboard. Scope it as 0-flip / 2-band-move, and do not let it displace a
flip-bearing item.

### Implementation surface (file:line)

Renderer (`SWFModernRuntime/src/rendering/render_webgpu.c`):

- **3386–3406** — the layer-composite doctrine comment. States verbatim: *"Alpha
  (11) and Erase (12) are handled by the caller: with no Layer above them Flash
  ignores the object entirely (surface.rs:239-244), and we have no layer groups
  yet, so that is always true. Layer (2) itself still falls through to normal."*
  This paragraph is the spec that F5 replaces.
- **3408** `blend_mode_is_trivial_layer()` — {4,8,9}; **3409–3412**
  `blend_mode_is_complex()` — {3,5,6,7,10,13,14}. Mode 2 (Layer), 11 (Alpha),
  12 (Erase) are in neither set: they have no pipeline at all.
- **3414–3426** `render_webgpu_blend_mode_is_layered()` — **`if
  (ctx->offscreen_depth > 0) return 0;`** is the structural blocker. A layer
  group is an offscreen pass; a blended child *inside* it would be the second
  level. F5 needs a small texture pool (or an A/B ping-pong with a saved
  depth), not just a new pipeline.
- **3685–3706** `render_webgpu_capture_backdrop()` — copies `main_color_texture`
  → `filter_tex_b`. For a nested layer the "backdrop" must be the enclosing
  *group* texture, not the main target.
- **3708–3782** `render_webgpu_composite_blend()` — single composite site; needs
  two new pipelines (ALPHA = dst.a := src.a masked; ERASE = dst.a := 1-src.a)
  writing the **group** target, plus a plain Layer(2) group composite.
- **2656–2678** `render_webgpu_set_blend_mode()` — legacy per-draw fallback; its
  `switch` has no case 2/11/12 and silently falls to `restore_draw_pipeline`.
  **Standing invariant reminder:** any new pipeline here must use
  `MSAA_SAMPLES`, never a literal 4. I audited the file: no literal
  `sampleCount = 4` / `multisample.count = 4` remains (the only literals are
  `= 1` on resolve targets and 1-sample staging textures, which are correct);
  the stale comment at **4318** still says "4x MSAA pass" and should be reworded
  when touched.

Caller (`SWFModernRuntime/src/libswf/tag.c`) — **three sites, all must change
together**:

- **3285–3300** in `render_display_list()` — `if (obj->blend_mode == 11 ||
  obj->blend_mode == 12) continue;`
- **5546–5570** stage display loop — `int blend_skip = (obj->blend_mode == 11 ||
  obj->blend_mode == 12);` with the comment *"We have no layer groups yet, so
  'no layer above' is unconditionally true. When layer groups land, this
  condition becomes a layer-stack query."* That is the exact edit.
- **6528–6560** the second (sprite/root-attached) loop — a verbatim copy of the
  same block. Historically the blend fixes had to be applied to all three; a
  patch that misses one produces a partial band move and looks like a
  half-working fix.

Also on the blend axis and unowned: **F7-AVM2** — `avm2/displayobject_blendmode`
(`same_geometry_wrong_fill`, e_large, 62400, **0.0% movement s10→s11**). The
AVM2 render walk does not route through the tag.c blend block at all. Sized: 1
comparison, but it is the AVM2 half of a mechanism we already own on the AVM1
side.

---

## 4. The biggest unowned single-mechanism lead: `from_shumway/acid/acid` ×16

Board row #1 (score 5.17). **All 16 comparisons sit at excess exactly 2541,
byte-identical across s10→s11 and across every frame** — that is one static
element wrong in every frame, not 16 bugs.

Feature dump (`output.01`): ink IoU 1.00, `missing_ink_frac` 0.0013,
`uniform_shift` false, and the tell — **`ncolors_actual` 18 vs
`ncolors_expected` 208.** Our render of this frame contains eighteen distinct
colours; Ruffle's contains two hundred and eight.

Dominant diff pairs at threshold 60 (2008 significant px):

```
1239 px   actual (51,51,0)      expected (255,255,0)
  97 px   actual (153,153,0)    expected (255,255,0)
  50 px   actual (51,51,0)      expected (216,216,0)
  32 px   actual (51,51,0)      expected (242,242,0)
  32 px   actual (255,102,217)  expected (255,255,255)
```

Our side quantises to multiples of 51 (255/5) where the oracle has a smooth
ramp (216, 242, 178, 119, 221 …). This is a **ramp-resolution / interpolation
defect, not an AA or geometry defect** — the geometry matches at IoU 1.00. Two
hypotheses for wave 2 (both cheap to discriminate with a single
`image_triage.py --test` before/after):

- (H1) a gradient whose ramp is being written as its control points without
  interpolation, so it samples ~6 levels;
- (H2) a colour-transform / alpha composite applying a 0.2 factor where the
  oracle applies 1.0 (51 = 0.2 × 255 exactly, and 102/153 = 0.4/0.6).

**16 comparisons for one mechanism, entirely unowned, and it has been on the
"named leads left on the board" list since session 9 without ever being
taken.** This is my #1 wave-2 recommendation.

Adjacent, same suite, near-zero-cost: `from_shumway/acid/acid-blend-2
[output.15]` and `[output.26]` are **1 excess channel each**, with per-comparison
tolerances of 128 and 117:

```
output.15  px(203,374)  actual (255,0,51)      expected (114,105,51)
output.26  px(282,153)  actual (229,235,242)   expected (102,140,178)
```

Two lone pixels, each one channel over a very generous tolerance. Time-box to
one hour: if it is a rasteriser sample-point tie it joins the capped class; if
it is a seam/crack it is 2 free flips.

---

## 5. Backends: confirmed arc-sized (NOT scoped)

**Stage3D / AGAL — 30 comparisons (26 `blank_render`, 2 `same_geometry`, 1
`halo_penumbra`, 1 `content_displaced`), 30 tests, 0 near-pass.**
`SWFModernRuntime/src/avm2/avm2_stage3d.c` is 2454 lines and contains **zero**
occurrences of `renderer_`/`wgpu` — it is an argument validator plus an AGAL
bytecode *validator* (tranche S2). `context3d_draw_triangles`
(avm2_stage3d.c:762) is three lines and draws nothing. Closing this needs a
Context3D GPU backend plus an AGAL→WGSL translator. **Confirmed arc-sized;
unchanged from the s9 assessment.**

**Video / NetStream — 21 unowned comparisons across 11 tests** (7
`blank_render`, 9 `unrelated_content`, 2 `missing_element`, 2 `no_render`, 1
hairline). Mostly arc — but see §6, one slice is smaller than the label
implies.

---

## 6. New unowned bucket found: the video codec gate (Phase B is 4 comparisons)

I extracted the `DefineVideoStream` codec byte from every failing video test:

| test | codec | current cluster |
|---|---:|---|
| `visual/video/colorconversion/h263` | 2 (Sorenson Spark) | blank_render f_catastrophic |
| `visual/video/deblocking` (12 streams) | 2 | missing_element f_catastrophic |
| `visual/video/colorconversion/vp6` | 4 (VP6) | blank_render f_catastrophic |
| `visual/video/vp6_dispsize` | 4 | blank_render f_catastrophic |
| `visual/video/colorconversion/vp6a` | 5 (VP6α) | blank_render f_catastrophic |
| `visual/video/vp6_alphaoffset` | 5 | blank_render e_large |
| `visual/video/h264`, `h264_multinalu` | 7, NetStream (no DefineVideoStream) | unrelated_content ×9 + blank |

The embedded-video pipeline is **already codec-agnostic and complete**:
`tagVideoFrame` (tag.c:11490) → `actionStoreEmbeddedVideoFrame`
(action.c:3466) → per-stream **persistent** `VideoDecoderCtx` (action.c:3424,
created at action.c:3443) → `video_decoder_decode` → RGBA cache →
`actionGetEmbeddedVideoFramePixels`. `map_flv_codec_id`
(video_codec.c:46–55) already maps 4→`VP6F`, 5→`VP6A`, 7→`H264`.

The **only** thing stopping VP6 is `video_codec_supported()`
(`SWFModernRuntime/src/actionmodern/video_codec.c:31–42`), whose `switch`
returns 1 for codec 3 and 2 and **0 for everything else** — so
`video_decoder_create` returns NULL and no frames are ever stored. CI does
install libavcodec on graphics shards (`ruffle-tests.yml:240` and `:556`,
`graphics-apt-deps`), and it resolves locally too.

**Premise attacked, partially refuted:** this is *not* an oversight — it is the
declared Phase-A boundary of `SWFRecompDocs/plans/video-codec-support-plan.md`
("Status: Phase A complete"), and Phase B is that doc's named next step. But
the plan assumed Phase B needed inter-frame decoder persistence, and **that
already exists** (built for embedded Spark). So Phase B has shrunk to roughly:
add cases 4/5 guarded by `avcodec_find_decoder`, plus VP6α's separate alpha
plane. **4 comparisons.**

**Second refutation, and the reason I rank this MEDIUM not HIGH:** all four
VP6 tests carry `tolerance = 0`, and `ruffle-tests/ignored_tests.txt:163-170`
already records the governing fact — our libavcodec H.263 output runs *1–3
levels off* Ruffle's `h263-rs` because of a different YUV→RGB path
(`sws_scale` vs Ruffle's own conversion), ACCEPTED_DIFFS Category 9. Decoded
luma/chroma should be bit-exact (both decoders implement the same spec); the
**colour conversion is the risk**, and it is separately fixable by replacing
`sws_scale` with a direct port of Ruffle's YUV→RGB matrix. A wave-2 slice
should land VP6 decode *and* the exact conversion together, or expect band
moves rather than flips.

Also unexplained and worth 30 minutes: **`colorconversion/h263` is
`blank_render` on a codec we already support** (2). Blank, not off-by-3. That
is a distinct defect sitting in front of the whole video family and it is the
cheapest thing in this section to diagnose.

---

## 7. Diagnosis signals — s11 fixes that should have moved a cluster and didn't

### 7a. MSAA: the quality axis is CLOSED (refutation, negative result)

I cross-referenced every failing comparison against its
`[player_options].with_renderer.quality`:

```
failing comparisons by quality:  low 183   high 117   best 2   (none absent)
corpus-wide quality values:      low 266   high 144   best 2   medium 1
```

Every image-graded test declares a quality, so there is no "unmapped default"
population. `get_msaa_samples()` (verify_output.py:2011–2035) clamps
medium/8/16 to 4; the corpus contains exactly **one** `medium` comparison and
it already passes. **There is no residual MSAA/quality slice to mine** — the
s11 mechanism is fully exploited. Do not re-open it.

### 7b. `quality="low"` comparisons the MSAA fix did NOT move: 113, and that is correct

113 quality-low comparisons improved <5% s10→s11. My initial hypothesis — that
the MSAA=1 define fails to reach the offscreen/filter/CPU-raster paths — is
**refuted**: `render_webgpu.c` uses `MSAA_SAMPLES` at 1258, 1266, 1284, 1440,
1947, 3219, 3282, 3427, 3485, 3585, 3701, 3744, which covers the offscreen and
filter targets; the surviving literals are all `= 1` on resolve/staging
textures. These 113 simply have a non-AA dominant mechanism (missing filter
geometry, unimplemented backend, wrong fill). No action.

### 7c. Genuine "should have moved, didn't" flags

| item | s10→s11 | why it is a signal |
|---|---|---|
| `avm2/displayobject_blendmode` | 62400 → 62400 (**0.0%**) | Every AVM1 blend fix of s10/s11 (F0–F4, F6, F7-AVM1, MSAA) moved its AVM1 twins by 56–100%. Zero movement ⇒ the AVM2 walk never reaches the tag.c blend block. Same shape as the known "AVM2 walk reads none of clip_depth/mask/scroll_rect" defect. |
| `visual/edittext/edittext_underline` + `_scale2` | 1974 → 1974, 27656 → 27656 (**0.0%**) | Clustered `hairline_edge_drift`, but an underline is an axis-aligned rect — AA cannot explain 27656 channels. The s11 EditText work (caret, corners, device fonts) moved every neighbour and missed these two. Likely a real underline thickness/baseline-offset bug mis-clustered as hairline. **2 comparisons, unowned, cheap.** |
| `visual/cache_as_bitmap/avm2_button_state` | 10353 → 10353 (0.0%) | `button2` ×3 flipped in s11 via the MovieClip `_up/_over/_down` mechanism; this sibling did not move at all, so it is a *different* mechanism than the one s11 solved. Do not assume the button arc is closed. |
| `avm1/bitmap_data_copypixels` | 840 → 840, `signed_mean = [-1,-1,-1,0]`, `signed_std` all 0, `uniform_shift` true | A perfectly uniform off-by-one on 840 channels. Mis-clustered as `hairline_edge_drift`; it is a rounding constant in the copyPixels path. 1 comparison, trivially diagnosable, possibly shared with `bitmapdata_colortransform` (726) and `bitmapdata_draw_rotation` (348), which are also frozen at 0.0%. |

---

## 8. Filters: the largest unowned non-backend family (31 cmps / 31 tests)

One comparison per test, spread across seven mechanism keys — which reads as
"no single fix" but decomposes cleanly by *filter feature*:

| slice | cmps | members |
|---|---:|---|
| bevel | 4 | `bevel`, `bevel_full`, `bevel_inner`, `bevel_outer` (all e_large, 385k–680k) |
| blur kernel / quality | 4 | `blur_fractional`, `blur_quality`, `blur_size_grows`, `blur_pass_scaling` |
| scale-with-screen | 4 | `blur_scales_with_screen`, `any_blur_scales_with_screen`, `drop_shadow_scales_with_screen`, `glow_pass_scaling` |
| glow | 3 | `glow`, `glow_without_composite_source`, `glow_with_alpha_strength` |
| displacement map | 4 | `displacement_map`, `_scales_with_screen`, `_through_applyFilter`, `_through_filters` |
| drop shadow | 2 | `drop_shadow`, `drop_shadow_angles` |
| bitmapdata applyFilter | 5 | `applyfilter_blur`, `_colormatrix`, `_destpoint_edges` (KF), `filter_sourcerect`, `color_matrix` |
| misc | 5 | `contains_grown_filter`, `acid-filter`, `acid-filter-2`, `shader_as_mask` (KF), `bitmapdata_draw_filters` (KF) |

**Premise attacked:** I expected "scale-with-screen" to be an unhandled
parameter. It is handled — `render_webgpu_run_blur` at
`render_webgpu.c:3925–3939` explicitly multiplies the radius by
`ctx->stage_scale` with a comment naming those very tests. So the residual is
**kernel shape**, not parameter plumbing: we run `quality` passes of a single
radius-capped separable kernel (`radius = blur * scale * 0.5`, clamped to 31),
where Flash/Ruffle run three box-blur passes of specific integer widths. A port
of Ruffle's box-blur is one change that plausibly touches the blur, glow,
drop-shadow and bevel slices at once (11+ comparisons) — with the standing
`shared-mechanism-fixes-overshoot-estimates` caution applied.

---

## 9. Recommended wave-2 pixel roster (beyond the sibling-owned leads)

Ranked by (unowned) × (single mechanism) × (flip-bearing).

1. **`from_shumway/acid/acid` ramp/quantisation defect — 16 comparisons, 1
   mechanism.** §4. Highest comparison-per-fix ratio on the entire board and
   never taken. Start from the `ncolors 18 vs 208` + multiple-of-51 evidence;
   discriminate H1 (gradient ramp) vs H2 (0.2 alpha/cxform factor) before
   writing any code.
2. **Filters box-blur port — up to 11 comparisons across blur/glow/shadow/bevel.**
   §8. One renderer change (`render_webgpu_run_blur`), no AVM2 dependency,
   and the scale plumbing it needs already exists. Discount the estimate.
3. **AVM2 blend-mode walk (F7-AVM2) — 1 comparison but a diagnosis multiplier.**
   §3 + §7c. `avm2/displayobject_blendmode` is frozen at 0.0% through two
   sessions of AVM1 blend work; it is the same "AVM2 walk reads none of the
   display fields" family the masks sibling is inside, and confirming that
   shared root is worth more than the single flip.
4. **EditText underline (`edittext_underline`, `_scale2`) — 2 comparisons.**
   §7c. Mis-clustered, frozen, axis-aligned geometry, and outside the
   sibling's auto_size/fonts scope.
5. **`acid-blend-2 [.15]/[.26]` single-pixel misses — 2 comparisons, 1-hour
   time-box.** §4.
6. **`colorconversion/h263` blank-render diagnosis — 1–2 comparisons, 30 min.**
   §6. A supported codec rendering nothing is a bug in front of the whole
   video family; cheap to answer and it re-prices item 7.
7. **Video Phase B (VP6 4/5) — 4 comparisons, MEDIUM confidence.** §6. Land the
   codec gate *and* an exact YUV→RGB port together, or expect band moves only.
   Do **not** start this before item 6 answers why an already-supported codec
   is blank.
8. **F5 layer groups — 2 comparisons, 0 expected flips.** §3. Correctness value
   for real content; explicitly de-prioritised on the scoreboard by its own
   measurement. If it is scoped anyway, its ledger must predict *band moves*,
   not flips, or the closeout will read as a miss.

**Explicitly NOT recommended:** `hairline_edge_drift` as a cluster (49 unowned,
A-INHERENT); `visual/blend_modes/*` proper (8 comparisons, capped at
`a_epsilon` by the s11 ruling); `offset_translation` (retire the cluster);
Stage3D (30, arc); H.264 (11, needs Phase C + Phase D multi-frame NetStream).

---

## 10. Playbook deltas proposed (for whoever owns §10 → §11)

- Record that the **frame-phase suspect channel is empty** as of run
  `31075033086` — a session should no longer budget for it.
- Record the **quality/MSAA axis as closed** with the corpus census (low 266 /
  high 144 / best 2 / medium 1, the single medium already passing), so no
  future session re-derives it.
- Record the **F5 measurement** (four blend tests byte-identical on our side;
  16/19 residual outliers outside the layer region ⇒ 0 flips) so F5 is never
  again ranked as a flip item.
- Add to §3 or §6 the rule this session validated by accident: **an
  `excess`-frozen comparison (0.0% across a session that moved its whole
  neighbourhood) is a mis-clustering signal**, and it is cheaper to detect than
  any feature the classifier computes. `image_status_diff.py` already prints
  the data; nothing in the board surfaces it. A `--frozen` flag on
  `image_triage.py` (join the previous run, list live rows with <1% movement)
  would have produced §7c mechanically.
