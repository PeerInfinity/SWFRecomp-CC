# w1-pixel-nearpass: pixel near-passes and the gradient-ramp twins (session 26, wave 1, cloud)

**New files (this branch):**
- `SWFRecompDocs/plans/session26-fanout-reports/w1-pixel-nearpass-report.md` (this report)
- `SWFRecompDocs/plans/session26-fanout-reports/w1-pixel-nearpass-prototype.patch` (`git diff origin/master -- SWFRecomp SWFModernRuntime`,
  97 lines, two hunks; `git apply --check` clean on `ec07cc9e`; sources reverted on the branch)

Box: `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Corpus: `download_tests.sh` from upstream Ruffle master **`3e98d9ba6`**
(my blobless clone, also used for source reads). lyon / ttf-parser sources read at Ruffle's `Cargo.lock` pins (lyon_tessellation 1.0.15,
lyon_geom 1.0.6, ttf-parser 0.25.1).

**Fidelity proven (CI-grade):** my BEFORE renders are md5-identical to CI's actual PNGs on `origin/ruffle-image-results` for
`visual/filters/bevel` (`3862d2a6…`), `from_gnash/misc-ming.all/morph_test1 frame1` (`39c7e185…`), `avm2/graphics_gradients` (`09af5717…`)
and `from_shumway/acid/acid-clip` (`8b9be2da…`). So the verdicts below are absolute, not just A/B.

---

## 1. Verdicts

### GO: 2 priced flips, both measured on the prototype, 0 pass→fail, 0 trace moves

| rank | comparison | CI baseline (`9277f3799`) | prototype (lavapipe, CI-grade) | hunk | price |
|---|---|---|---|---|---|
| 1 | `from_gnash/misc-ming.all/morph_test1 frame1` | 217 / 0 @5, max 255 | **0 / 0, max 0** | T: nested EditText painted at its root ancestor's depth | S (`action.c`, 2 functions, +35 lines) |
| 2 | `visual/filters/bevel output` | 9 / 6 @3, max 254 | **6 / 6, max 199: PASS at zero headroom** | M: TrueType implied midpoints truncate (ttf-parser + `as i32`) | XS (vendored `stb_truetype.h`, 4 call sites + 1 macro; **needs `--recompile`**) |

The hunks are independent and can land separately. **Add `visual/filters/bevel` to the zero-headroom watch list** (6/6, like `bevel_inner/_full/_outer`
at 18/18). Its last 2 pixels are explained only by a sub-pixel field offset (§2.2), with no mechanism yet.

### NO-GO / HOLD (each with its completion mechanism)

| comparison | verdict | mechanism / completion |
|---|---|---|
| AVM2 twin of the s25 Drawing-API ramp fix (`gfx_gen_ramp`) | **NO-GO: 0 flips, and it moves away from Flash** | Measured: float-linear endpoints + truncating alpha + NaN guard (diff in §3). Of the 8 non-AVM1 image rows that call `beginGradientFill` / `lineGradientStyle` / `GraphicsGradientFill`, **only `avm2/graphics_gradients` moves**: Flash golden 3685 → **3704** channels at tol 1 (worse); Ruffle sidecar 1279 → 559 (better). The golden is Flash, the row is `known_failure` ("Gradient fills are off by up to ~20 levels"), and the Flash-over-Ruffle rule applies. The Fixed16 a–d / truncated-twip gradient-matrix variant renders md5-identical to the ramp-only one. Completion: a Flash gradient model, i.e. a Flash capture (not a Ruffle port). Land the ramp only as AVM1/AVM2 parity hygiene, if wanted, and book it as −19 channels on a fail row. |
| `avm2/graphics_draw_triangles`, `avm2/sprite_with_frames` (brief: "do they move with the twin?") | **Premise refuted** | A byte scan of every decompressed image-row SWF for the three gradient API names finds neither row. Neither can move from `gfx_gen_ramp`. Both are re-goldened-to-Flash rows (playbook §21). |
| CPU `BitmapData.draw` gradient sampler (`SAMPLE_GRADIENT_RAMP`, nearest) | **NO-GO, re-confirmed by record** | s25 `w2-nearpass-land` §2.2 measured the GPU-style `t*256-0.5` lerp as **worse** (`GradientFillTest` 159 mismatching lines vs 155): the nearest sampler is tuned to Flash's pixel probes. No image row draws a gradient into a BitmapData except `blend_shader_luma_lighten` (PBJ NO-GO). Completion: a Flash-vs-Ruffle audit of GFT's probes (oracle-gated). |
| `avm2/blend_scroll` (296) | **NO-GO of record, re-confirmed** | s22 "decided −2": Flash anti-aliases `draw()` at quality LOW; the golden is Ruffle's aliased render (RVF entry). |
| `avm2/bitmapdata_opaque` (4 / 0) | **NO-GO of record, re-confirmed** | Same decision: (9,9), (190,9), (9,190), (190,190) are our AA'd round-join corners (128 vs 255), matching Flash. |
| `visual/video/colorconversion/h263` (3) | **NO-GO** | One-pixel Spark IDCT residual; completion = an h263-rs port. |
| `avm2/graphics_draw_path` (664) | **NO-GO (Flash fidelity only)** | CI actual vs `output.ruffle.png`: **0 channels**, byte-identical to Ruffle. The golden is Flash's. Completion: Flash's own rasteriser model; no Ruffle signal left. |
| `avm2/graphics_simple_shapes` (158, KF) | **NO-GO; still live only as Flash-fidelity work** | Still exactly **1 pixel** off Ruffle's sidecar ((76,8): ours green, Ruffle red, a quality-low tie). Matching Ruffle flips nothing (Ruffle is itself 160 off Flash). |
| `from_shumway/gradientTransform` (9, KF) | **NO-GO** | Flash golden with `known_failure`. At the graded tol 3, **ours and Ruffle's sidecar are equally off: 9 channels / 3 px each** (at tol 0 ours differs on the edge columns x = 0, 1, 99, 100 by ±1). Matching Ruffle would gain nothing. Completion: Flash's edge-column gradient sampling. |
| `avm2/bitmapdata_draw` (753 / 600 @128) | **NO-GO of record** | Tol-128 check on a 1-px text baseline. The golden is a Flash capture, and Ruffle's model puts the baseline where we do (s23). |
| `from_shumway/3_joystick` (4 @128) | **HOLD (unchanged since s25)** | 2 px, (339,125) and (340,125), at the bottom of the knob highlight (ours 140,64,64 vs 253,251,251), plus a broad tol-32 field = a sub-pixel offset of the mouse-driven knob at quality high. Completion: s25's LOCAL ORACLE REQUEST 2 (Ruffle's knob world matrix at tick 21). Re-filed below if still open. |
| `from_shumway/acid/acid-clip` (409 / 140 @64) | **HOLD: mechanism narrowed (not masks)** | 111 of the 185 tol-64 pixels are one disc in the top strip: root depth 3 = sprite 4 = {shape 5 clip layer (clip depth 3), shape 6}. Ours shows a blue-grey disc over the red one; the golden has red only. The disc is **inside the single DefineShape `char 6`**, so this is fill-style region/order semantics of overlapping sub-paths in one shape (which fill wins where two styles' circles overlap), not mask or nesting. Completion: dump char 6's fill styles and records, then compare our per-style draw order with Ruffle's `ShapeConverter` region output (S–M probe). Even if fixed, the remaining ~74 px of AA field may keep it above 140 channels, so price the flip at **≤ 50 %**. |
| `from_shumway/acid/acid-shapes` (25688 / 25600 @32) | **HOLD (unchanged)** | Drawing-API self-intersecting translucent fills (s25 §1). Numbers identical to s25, so nothing moved it. Completion: the drawing-API fill-rule semantics for self-intersecting curved paths. |
| `from_shumway/acid/acid-text-6` frame5 12 / output 198 | **HOLD; method handed over** | AS3 **static text** (DefineText ×1, DefineFont3 "InputMono Bold", 296 PlaceObject2) at quality low, tol 0. frame5 = 4 glyph-edge pixels ((535,518), (538,518), (541,518), (541,519)). Same tie family as bevel. The §2.2 label-model fitting tool (rasterise Ruffle's glyph geometry in f32 at pixel centres; scan sub-pixel offsets per glyph) is the cheapest way to find which quantization differs. Static text belongs to sibling `w1-pixel-tail`. |

---

## 2. Mechanisms and evidence

### 2.1 T: a sprite's EditText is painted after the whole display list (`action.c` `tf_window_skip`, `actionBeginTextFieldDepthPass`)

`morph_test1` frame1 (tick 2): the golden's red morph (root depth 2) **covers** the Dejagnu `xtrace` field. The field is DefineEditText `char 2`,
placed at depth 10 inside sprite `char 1`, which sits at root depth 1. We draw the text on top of the morph (image: the xtrace text is drawn over
the red rectangle).

Owner: since s17 the root render loops paint root-timeline fields at their own depth (`tf_draw_at_root_depth`, `TF_WINDOW_AT_DEPTH`). Everything
else, **including fields inside timeline sprites**, falls into the end-of-frame `TF_WINDOW_REST` pass (`tag.c` ~8643 and ~9714, comment: "covers
only what the walk could not place: createTextField fields, fields inside sprites, and orphans"). So a nested field always lands above every
later root depth. Ruffle paints it from the sprite's `render_self`.

Prototype: new static `tf_nested_anchor_depth(mc, max)` walks a field up to its root ancestor. If that ancestor is a root-timeline object
(`depth` in `[TF_TIMELINE_DEPTH_BASE, +max]`), the field is anchored at **ancestor depth + 1**. That anchor is the pre-draw window of the next
root depth, so the field draws right after its sprite and before later depths. `max` anchors fall back to REST, which is after everything and
therefore already correct. `actionBeginTextFieldDepthPass` marks the anchor in the presence table, and `tf_window_skip` admits the field only in
its anchor window and skips it in REST. No `tag.c` change. The window machinery is native-only (browser-WASM paths run `TF_WINDOW_ALL`), the
same as for s17's root fields.

Approximations, stated: within its sprite the field still draws after all of the sprite's other children, as it does today. Two edge cases fall
through to the old behaviour and are no worse than today: an ancestor rendered through the filter or cacheAsBitmap route, and an anchor depth
whose entry is a filtered root EditText (`tag_root_edittext_is_filtered` skips that window). The kill-switch `NP_TF_NESTED_OFF` exists only for
the A/B; **drop it when landing**.

**Sweep (argued scope):** the hunk only affects AVM1 text fields (`child_mc_cache`). I byte-scanned every image row's decompressed SWF and kept
those with no AS3 FileAttributes flag that contain DefineEditText (tag 37) or `createTextField`: **41 tests / 71 PNGs** across avm1, text, visual,
from_gnash and from_shumway. Same binary on both legs (env kill-switch): **70 IDENTICAL, 1 DIFFERS = `morph_test1 frame1` fail → pass
(217 → 0, max 0), 0 trace status changes.** Regression: `regression/avm1_parent_child_text` (image, PASS, md5 `ac67a59f…` both legs) and
`avm2_static_text` (trace PASS both legs).

### 2.2 M: TrueType implied on-curve midpoints (`SWFRecomp/lib/stb/stb_truetype.h`, used by `swf.cpp`'s device-glyph synth)

`bevel`'s 3 residual pixels are aliased (quality = low) `_sans` device-font label pixels: (456,28) is in "Knockout" (the foot of the `t`), and
(19,294) and (19,299) are in "Out" (the inner left edge of the `O`). To attribute them I built a geometry model:
- Python reads the Noto Sans outlines. Ruffle's `notosans.subset.ttf.gz` outlines are **identical** to `SWFRecomp/assets/NotoSans.ttf` for the
  glyphs involved.
- An f32 port of lyon_geom 1.0.6's Levien flattening at `FillOptions::DEFAULT_TOLERANCE` (0.1) on the font_units/20 path.
- Ruffle's glyph transform (`font_like.rs` `evaluate`: a = d = height / units_per_em, device advances `round_to_pixel`).
- A non-zero point-in-polygon test at pixel centres, over all four labels.

**The model reproduces our render exactly: 0 mismatching label pixels against our PNG and the same 3 against the golden.**

Then, by modelling ttf-parser 0.25.1's `glyf::Builder::push_point` / `finish_contour` instead of stb: ttf-parser lerps implied midpoints in f32
(exact .5), and Ruffle `font_face.rs` `GlyphToDrawing` stores `Twips::new(x as i32)` / `Twips::new(-y as i32)`, which **truncates toward zero**.
stb computes `(a+b)>>1`, which **floors**. They differ exactly when a midpoint has a negative half-integer coordinate (descenders, overshoots). The
`t`'s bottom curve has the midpoint of (325,−1) and (273,−10): y = −5.5. stb gives −6; Ruffle gives −5, one font unit (0.02 px at 20 px) higher.
With ttf-parser semantics the model matches the golden at (456,28) and changes nothing else in the four labels. The prototype replaces the 3
midpoint sites (open, close, interior) with `STBTT__MID(a,b) = (a+b)/2` (C division truncates toward zero, so this is bit-exact with the f32 lerp
+ `as i32` for TrueType's int16 range).

**The remaining 2 pixels (the `O` of "Out") are NOT explained.** In the model, per-glyph offset windows that reproduce the golden are: `O` dx ∈
[+0.025, +0.055] px; every other glyph of In/Out/Full ∋ +0.05; every "Knockout" glyph ∋ 0 but Knockout's `o`/`c` ≤ +0.01. So a **+1-twip x shift of
the three fields at tx = 321** (not Knockout at tx = 7399) fits all data, but I found no source for it in `edit_text.rs`. I checked: layout
origin, `layout_to_local_matrix` (`device_font_scale_x` = 1), `EditTextPixelSnapping` (applies to the box/caret/underline only, not glyphs) and
`Matrix * Matrix` rounding (all-integer here). Flattening tolerance 0.125–0.2 fixes `O` but breaks Knockout (6–9 px), so it is not tolerance. Left as
a lead; bevel passes without it.

**Sweep (argued scope, cheapest exact one):** the hunk only changes recompiler output, so I recompiled **every** image-row test (417 dirs, all
suites incl. `regression`) with the old and new recompiler binaries and diffed the generated `RecompiledTags`/`RecompiledScripts`: **405 SAME,
12 DIFF**. Only those 12 can move. I rendered all 12 both legs with `--recompile`: **12 tests / 13 PNGs: 12 IDENTICAL, 1 DIFFERS =
`bevel` fail → pass; 0 trace status changes.** The 12 are `bevel`, `bevel_inner`, `bevel_outer`, `bevel_full` (zero-headroom rows:
**md5-identical**), `glow`, `glow_without_composite_source`, `glow_with_alpha_strength`, `drop_shadow`, `cache_as_bitmap/edittext_scroll`,
`text/String_path_variable_button`, `from_shumway/MaskTest-2` and `hardwrap`. I verified the in-tree generated code on the after leg equals a fresh
new-recompiler run for `glow`, `hardwrap` and `String_path_variable_button`, so the IDENTICALs are real. AVM2 device fonts (`abc_devicefont.cpp`)
share this stb, but no AVM2 image row's generated code changed.

### 2.3 AVM2 gradient-ramp twin: measured, NO-GO (`avm2_display.c` `gfx_gen_ramp`, not landed)

The prototype I measured, then reverted (`gfx_gen_ramp` + the alpha clamp in its caller):

```c
stops[s].a = (uint8_t) (alphas[s] * 255.0f);                 // Ruffle `(alpha * 255.0) as u8` (graphics.rs build_gradient_records)
linear ? GRADIENT_RAMP_LINEAR : GRADIENT_RAMP_SRGB             // float linear endpoints, as AVM1 since 697669e5f
alps[i] = !(av > 0) ? 0 : av > 1 ? 1 : av;                     // NaN -> 0 (was: NaN passed through -> UB cast)
```

A/B over the 8 non-AVM1 gradient-API rows (`blend_shader_luma_lighten`, `graphics_bad_direct_commands`, `graphics_gradients`,
`graphics_gradients_nulls`, `regression/avm2_graphics_runtime`, `fills_and_lines`, `gradient_focal_point`, `displacement_map`): **7 IDENTICAL**, and
`graphics_gradients` DIFFERS by ≤ 1 level on 837 channels (fail → fail; Flash 3685 → 3704, Ruffle sidecar 1279 → 559). Of the remaining
559 channels vs Ruffle, 318 are ±1 and the rest is a handful of 27–74-level pixels in two 50-px cells: not ramp. One more Ruffle difference
was found but not measured: AVM2 ratios use `coerce_to_u32` then clamp, so a **negative ratio becomes 255 in Ruffle** (we clamp to 0). No row
exercises it.

---

## 3. Patch scope (`w1-pixel-nearpass-prototype.patch`)

| file | functions | hunk |
|---|---|---|
| `SWFModernRuntime/src/actionmodern/action.c` | new static `tf_nested_anchor_depth`; `tf_window_skip`; `actionBeginTextFieldDepthPass` | T (+35) |
| `SWFRecomp/lib/stb/stb_truetype.h` | new macro `STBTT__MID`; `stbtt__close_shape`, `stbtt__GetGlyphShapeTT` (3 midpoint sites) | M (+9 / −4), **`--recompile`** |

Nothing in `tag.c`, `ng_shared.c` or `swf.c` (the `n-pixel-pass` files). Landing T: drop the `getenv("NP_TF_NESTED_OFF")` line. Neither hunk
touches `swf_core.c`, `tag_stubs.c` or a `NO_GRAPHICS` arm (both are render-only in effect; trace text identical on all swept rows). Canary:
neither change class is covered by a tier-1 canary member at tol 0. Suggest appending `from_gnash/misc-ming.all/morph_test1` (T) and
`visual/filters/bevel` (M, zero headroom) at EOF when landing.

---

## 4. Refutations

1. **"graphics_gradients / graphics_draw_triangles / sprite_with_frames move with the AVM2 ramp twin":** only `graphics_gradients` calls the
   gradient API, and the twin moves it *away* from its Flash golden.
2. **"bevel's residual is device-font text (`w1-pixel-text` family)":** half right. It is device-font glyph *geometry*, but the owner is the
   recompiler's TrueType decode (stb floor vs ttf-parser trunc), not the runtime text layout. The layout model matches Ruffle exactly.
3. **"morph_test1 frame1 is a near-pass" (brief) / "hand to w1-pixel-text" (s25):** it is neither pixels nor text layout; it is z-order of
   sprite-nested text, an S fix in the text-window code.
4. **acid-clip "content placement inside the clip" (s25):** the wrong disc sits inside one DefineShape under a plain one-level clip, so this is
   shape fill-region semantics, not mask placement.

## 5. New unclaimed leads

1. **bevel "Out" `O`, 2 pixels:** a fit says the three tx = 321 fields sit +1 twip right in Ruffle; the source is unknown. If found, bevel gains
   6 channels of headroom. Tool: the label model (§2.2; ~150 lines Python + the lyon f32 Levien port).
2. **acid-clip char 6 fill-style region order** (§1 HOLD), ≤ 50 % flip.
3. **acid-text-6 frame5/output:** apply the §2.2 model to InputMono DefineFont3 static text (`w1-pixel-tail`).
4. AVM2 `beginGradientFill` negative-ratio semantics (`coerce_to_u32` → 255): trace-invisible, no row.
5. Text-window approximations left by T: a sprite-nested field still draws after all of its sprite's other children (Ruffle interleaves by
   child depth), and fields under filtered or cacheAsBitmap ancestors still use the REST pass. Game-visible, no row.

## LOCAL ORACLE REQUESTS

1. (Carry-over from s25, only if not yet run.) `from_shumway/3_joystick/test.swf`, `--trace-log` + render at frame 21: the knob's world matrix
   (or a trace of its x/y) so the sub-pixel knob offset can be pinned.

No exporter request for bevel: the row is quality = low, and the exporter renders HIGH only.
