# w1-acid-flash: session 28 wave 1 (cloud). Shumway acid rows with Flash goldens

**New files (all under `SWFRecompDocs/plans/session28-fanout-reports/`):**
- `w1-acid-flash-report.md` (this file)
- `w1-acid-flash-prototype.patch`: both prototypes together, `git diff origin/master -- SWFRecomp SWFModernRuntime`
  (touches `SWFRecomp/include/swf.hpp`, `SWFRecomp/src/swf.cpp` and `SWFModernRuntime/src/rendering/render_webgpu.c`)
- `w1-acid-flash-prototype-tie-only.patch`: prototype P1 alone (`render_webgpu.c`: new `lowq_stage_shift`, plus its two
  call sites in `render_webgpu_upload_stage_transform` and the stage upload in the frame-open path)
- `w1-acid-flash-prototype-stroke-only.patch`: prototype P2 alone (`swf.hpp` `LineStyle`, `swf.cpp` DefineShape4
  LINESTYLE2 parse and the `stroke_run_data` emit, `render_webgpu.c` `hairline_restage`)

All three pass `git apply --check` on `origin/master` `d5f9726d`. The sources are reverted on this branch.

**Box:** `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). **Corpus:** `download_tests.sh from_shumway`, then `avm1
avm2 visual from_gnash text timeline swf fonts mixed_avm import_assets`. That is upstream master on 2026-11-25; the
script prints no SHA. 5 flash-fixes were applied.

**Fidelity is CI-grade for all seven rows.** My *before* renders are md5-identical to CI's actual PNGs on
`origin/ruffle-image-results`:

| row | md5 |
|---|---|
| `acid-mask` .01 | `02cdb2d0` |
| `acid-mask` .05 | `63a2d8cb` |
| `acid-mask` .10 | `c36af0e5` |
| `acid-shapes` | `50b2e338` |
| `acid-shapes-testing` | `a275e1f8` |
| `acid-stroke-0` | `48cfef43` |
| `acid-textfield` | `7da090c3` |

Every outlier count reproduced CI's exactly.

## 0. Verdicts (lead)

**Priced yield: 0 flips on the seven briefed rows.** Five of the seven are tolerance 0 or have a 20-outlier budget,
and none can flip without byte-exact Flash anti-aliasing or Flash's text rasteriser. The two real Flash mechanisms
this slot found are Flash-ward but cost passing rows that have Ruffle goldens. Each is a decision for the coordinator,
not a free landing.

| # | row(s) | verdict | mechanism (owner) | measured |
|---|---|---|---|---|
| 1 | `acid-stroke-0` (KF, low, tol 0) | **NO-GO flip; mechanism found and prototyped (P2), HOLD for a disposition decision** | **Flash's stroke-width model.** Flash scales a stroke ISOTROPICALLY in device space by a scalar taken from v = M·(1,1) of the local→device matrix: NORMAL → \|v\|/√2, NoVScale → \|v.x\|, NoHScale → \|v.y\|, both flags → 1, then a 1-device-px minimum. We, and Ruffle (byte-identical render), stroke in local space and let the matrix stretch the stroke anisotropically. We also ignore NoHScale/NoVScale. Owner: `render_webgpu.c` `hairline_restage` plus a flag plumb in `swf.cpp` | **52702 → 18381** (P2), **→ 16883** (P1+P2) |
| 2 | `acid-shapes-testing` (KF image, low, tol 0) | **NO-GO flip; mechanism found and prototyped (P1), HOLD for a decision** | **Aliased pixel-centre tie rule.** At quality low, Flash puts a 1-px line centred on integer x into column x. Vulkan/D3D's top-left rule (ours, and Ruffle's wgpu) puts it into column x−1. Every red `getRect` box in this row (25k of the 31k diff px) is one pixel up/left of Flash's. Owner: `render_webgpu.c` stage upload (P1: +1/128 device px stage nudge at `MSAA_SAMPLES == 1`) | **41339 → 13705** (rest: curve-edge fills and fractional-coordinate boxes) |
| 3 | `acid-mask` .01/.05/.10 (KF, high, tol 4, 20 outliers) | **NO-GO (s25 verdict of record stands; brief premise refuted again)** | Anti-aliasing coverage model, not a mask mechanism. Diffs are 1-px outline rings on all 4 robots, and the per-robot counts are near-equal (3086/2913/2593/2422 ch). The `R1.mask = M1` set in frame 1 has no visible footprint in the diff. Ours is brighter on 2774 px and darker on 2298 (balanced: no alpha or gain error). The max-124 pixels are our full coverage where Flash has ~½ | best global sub-pixel shift (0.2,−0.05) gives 12018 → 10030; far from 20 |
| 4 | `acid-shapes` (high, 6 checks; fails tol 16 by 85 and tol 32 by 88) | **NO-GO (AA noise; s25 "self-intersecting fills" lead refuted)** | **0 interior colour mismatches**: every pixel that is uniform in a 3×3 window in both images matches exactly, so all 88 channels are edge AA. The (20,2,46)-vs-black and "0.75× intensity" pixels s25 cited are AA edge pixels of thin features | a 1/16-px stage nudge passes all 6 checks, but the shift that helps `acid-mask` has the opposite y sign. No consistent sample offset exists, so this is fitting noise, not a mechanism |
| 5 | `acid-textfield` (KF, low, tol 0) | **NO-GO** | Flash anti-aliases CSMTextSettings-advanced text (`DefineEditText` + `CSMTextSettings` flags 0x50 = FlashType, subpixel grid-fit) **even at stage quality LOW**: the golden has 795 colours, ours and Ruffle's have 7. The trailing "dot" is a glyph, not a shape. Tol 0 against Saffron is unwinnable | ours 15754 vs Ruffle's own render 17351; P1 does nothing (15753) |

## 1. Prototypes and measurements

### P1: Flash's aliased tie rule (`w1-acid-flash-prototype-tie-only.patch`)

**Mechanism.** In `acid-shapes-testing` each cell draws a `getRect()` box with `lineStyle(1, red)` at integer
coordinates. At (0,0,28,35) Flash fills columns 0..28 and rows 0..35. We fill −1..27 and −1..34, because the line
covers [x−½, x+½] and both pixel centres sit exactly on its edges. Any positive sub-pixel nudge gives Flash's choice;
a sweep on the kept build showed this:

| nudge (px) | outliers |
|---|---|
| 0 | 41339 |
| 0.004 | 13771 |
| 0.0078 | 13705 |
| 0.02 | 13537 |
| 0.25 | 11491 (best) |
| 0.5 | 12915 |

The rule is in the nudge, not in its size. **Prototype:** at `MSAA_SAMPLES == 1` only, translate the uploaded
stage→NDC by +1/128 device px on both axes. 1/64 cost `acid-color [frame1]` one channel of gradient phase; 1/128 does
not. The prototype honours `LOWQ_SHIFT=x,y` for measurement. MSAA-4 builds compile it out, so only quality=low rows can
move.

**Gate:** 116 low-quality image tests, all with the prototype at 1/128:
- the 32-row argued set;
- every canary member with quality low (68 more);
- every remaining low-quality `from_shumway/acid/*` and `visual/*mask*` row (16).

Trace axis: 0 failures in all logs.

**Flash-target rows (all improve; none flips):**

| row | before | after |
|---|---|---|
| `acid-shapes-testing` | 41339 | 13705 |
| `acid-stroke-0` | 52702 | 52207 |
| `avm2/sprite_with_frames` | 6342 | 4956 |
| `avm2/graphics_draw_path` | 704 | 248 |
| `avm2/graphics_gradients` | 3685 | 3680 |
| `acid-text-4` | 51678 | 51639 |

`graphics_simple_shapes` (158), `gradientTransform` (9) and `BeginBitmapFill` (939/100) do not move.

**Losses: 43 comparisons pass → fail (42 tests; `acid-text-6` loses both `output` and `frame5`).**
- 42 comparisons have Ruffle-made (or s27-untestable) goldens, mostly at tol 0. They include `simple_shapes/layers`, `masks`,
  `masks_equal_clipdepth`, `overlaps`, `scroll_rect_mask`, `text_field_mask`, `drawing_api/{fills_and_lines,
  drawing_order}`, the `blend_modes` rows (`add`, `multiply`, `layer_alpha`, `layer_erase`), the filter rows (`bevel`,
  `bevel_inner`, `glow`, `drop_shadow`, `drop_shadow_angles`, `displacement_map`, `color_matrix`), `acid-text`,
  `-text-6` ×2, `-text-escape`, `-text-x`, `-scale`, `-child frame5`, `-chars`, `-gc`, `-blend`, `-gradient`,
  `-gradient-2` and `-image`, plus `doubleAndRegister`, `text/auto_size/width`, `style_changes_in_html`,
  `fonts/device-font`, `fallback_preferences`, `nested_rotation`, `mouse_pick_dobj_mask`, `stage3d_texture` and
  `movieclip_line_gradient_style`.
- **1 has a Flash-provenance golden:** `acid-big` ("Flash (in tol)"). It passes 0/20 at nudge 0 and fails 43/20 (max
  59 vs tol 50, 22 scattered px) at 1/128. Its Flash capture was not archived, so I cannot tell which side is
  Flash-correct.
- The gnash rows in `cmp_gate` show `base ?` because my base-lookup script does not read gnash keys. They are not
  real moves: `background` stays pass, and `BeginBitmapFill` stays 939 (= the baseline's excess 839 + 100).

**The 42 losses are mostly Flash-ward where Flash can judge.** I graded both sides of each moved row against s27's
archived Flash captures (`session27-fanout-reports/golden-provenance/*.png`). "Before" is the golden, which these rows
matched at their tolerance. Of 31 rows with a capture, **25 end closer to Flash or equal**, counting pixels more than 3
off. Pixels off Flash, before → after:

| row | measure | before | after |
|---|---|---|---|
| `gradients` | >32 | 639 | **1** |
| `acid-text` | >3 | 3745 | 2916 |
| `acid-chars` | >0 | 1008 | 584 |
| `blend_modes/multiply` | >32 | 3979 | 3361 |
| `acid-child frame5` | >0 | 174 | 160 |
| `text/auto_size/width` | >0 | 5214 | 5148 |

Six get worse at >3:

| row | before | after |
|---|---|---|
| `masks` | 2118 | 2129 |
| `masks_equal_clipdepth` | 2118 | 2129 |
| `acid-gc` | 1264 | 1342 |
| `drop_shadow_angles` | 25038 | 25117 |
| `blend_modes/add` | 3805 | 3807 (its >32 count improves, 3424 → 3215) |
| `acid-text-6 frame5` | 106 | 107 |

`acid-color-0` (RvF JPEG entry; its Flash capture is archived from s27) moves 1138 → 1391 against the Ruffle golden
but **26495 → 25456 px > 3 against Flash**.

**Price and verdict:** Flash-correct by the evidence, but **net −43 pixel comparisons for +0 flips**, one of them a near-Flash
golden. Landing it means about 42 RvF dispositions plus the `acid-big` oracle check. **HOLD, coordinator decision.**
Completion mechanism: Flash captures of the 9 moved rows that have none (§ LOCAL ORACLE REQUESTS), then decide by
rule 3. Overlap: sibling `w1-render-flash-headroom` owns the quality model and gnash shape strokes, so it should see
this rule before pricing hairline rows.

### P2: Flash stroke-width model (`w1-acid-flash-prototype-stroke-only.patch`)

**Derivation (acid-stroke-0, Flash golden).** The SWF has 5 DefineShape4 rectangles (4 px NORMAL, 4 px NoVScale, 4 px
NoHScale, 4 px both flags, 1 px both flags), each placed under 11 matrices. The ABC only rotates children on click,
so the timeline is static. Measured golden stroke widths:

| matrix | NORMAL | NoVScale | NoHScale | both flags |
|---|---|---|---|---|
| scale(2,1) | 6 on all four sides | 8 | 4 | 4 |
| scale(1,2) | 6 | 4 | 8 | 4 |

The two mirrored shears, M=[[2,∓1.414],[0,1.414]], give a thin outline (~4 px) and a thick one (10/16 px). That
asymmetry pins the vector to M·(1,1), not to a norm of M: Flash's scale factor depends on the shear's sign.
\|M(1,1)\|/√2 is the same formula Ruffle uses only for its hairline minimum (`graphic.rs:254-259`). Flash uses it for
the width itself.

**Prototype.**
- `swf.cpp` carries NoHScale/NoVScale into bits 30/31 of `stroke_run_data[][3]`.
- `hairline_restage` computes Flash's device width per run and re-expands every vertex of a non-similarity draw:
  - A segment or arc vertex d (\|d\| = h_e) goes to d̂·(w/2)·\|M⁻ᵀd̂\|.
  - A miter/inner-join vertex (\|d\| > h_e) recovers its two edge normals from d alone (n = cosφ·d̂ ± sinφ·d̂⊥,
    cosφ = h_e/\|d\|), and the 2×2 system d'·nᵢ = (w/2)·\|M⁻ᵀnᵢ\| is solved for it.
- Similarity draws keep the old uniform k. For them it reduces to s22's rule exactly, so they stay byte-identical.

The first try mapped offsets by M⁻ᵀ. It mis-sized the miter vertices (still L5/T7 on scale(2,1)), and the second
version fixed that.

**Gate:** all 63 image tests with timeline strokes, from s22's complete stroke scan (`stroke_scan_393_image_tests.txt`,
with the non-`:0:0` rows minus away3d and netstream), run with `--recompile`. Trace axis: 0 failures. 2 pass → fail;
every other row is unchanged, byte-for-byte counts:

| row | golden | before | after | vs Flash |
|---|---|---|---|---|
| `acid-stroke-0` (KF) | Flash | 52702 | **18381** | n/a: golden is Flash |
| `visual/simple_shapes/strokes/scale` (KF, tol 5) | Flash (capture = golden, 0 px) | 23391 | **15720** | n/a |
| `from_shumway/acid/acid-scale` | Ruffle | pass 0 | **fail 8498** | **Flash-ward**: 5620 → 2299 px off the s27 Flash capture (the 6:1-scaled ellipses' strokes thicken, as in Flash) |
| `visual/filters/blur_scales_with_screen` | Ruffle | pass 0 | **fail 72378 (max 41, tol 2)** | no capture. The filtered square has a 0.82×1.11 world matrix. Flash's rule gives an isotropic ~0.98·w, and the blur turns each 1-px edge move into a wide band. Needs a Flash capture |

`acid-small .01/.05`, `acid-morph`, `acid`×18, `button3`×4, bevel/glow/displacement, `simple_loop_test`, `shape_test`,
`place_object_test`, `sprite_with_frames` and `regression/avm2_timeline_stroke_gradient` show identical counts.

**Residual on acid-stroke-0 (18381):**
- Round joins of the sheared cells bulge: the bbox is 115×50 vs Flash's 111×49, because a local-space arc mapped
  direction-by-direction is not a device-space circle.
- Flash's hairline row has pixel-snapped, partially drawn 1-px outlines (the `64×2` fragments).
- Tie positions account for 1.5k: P1 takes P2 to 16883.

**Price and verdict:** Flash-correct (two Flash goldens improve by 34k and 7.7k channels). 2 Ruffle-golden losses, one
of them proven Flash-ward. **0 flips** (both Flash rows are KF with tol 0 / tol 5). **HOLD for wave 2, price M.**
Completion:
1. Device-space round-join/cap arcs: emit arc vertices with their angle, or re-tessellate joins at draw time.
2. Width-0 and pixel-hinted hairlines (s22 L3).
3. The same model on morph strokes, glyph strokes and drawing-API strokes. Drawing-API strokes are not covered: the
   prototype touches only timeline DefineShape strokes, as s22's tables do.
4. An RvF entry for `acid-scale`, and a Flash capture for `blur_scales_with_screen`.

## 2. Refutations

- **"acid-mask is one systematic mask-AA/alpha mechanism"**: refuted (again, after s25 §3).
  - Diffs are spread evenly over all four robots, though only R1 is masked.
  - Signs are balanced (2774 brighter / 2298 darker), so there is no alpha gain.
  - No sub-pixel stage offset gets near the budget: (0.125,0) gives 10222, (0.2,−0.05) 10030, (0.25,0.25) 15044,
    (0.5,0.5) 22624.
  - It is MSAA-4 coverage vs Flash's high-quality coverage at a 20-outlier budget.
- **"acid-shapes' 88 are translucent self-intersecting fills" (s25/s26 HOLD)**: refuted. There are 0 interior
  mismatches; the cited pixels are edge AA on thin features.
- **"acid-shapes-testing / acid-stroke-0 are diffuse AA at tol 0" (s26 tail: "byte-exact Flash AA. NO-GO")**: refuted.
  Both rows are quality **low**, so Flash and the golden are aliased (2 colours plus background). The real mechanisms
  are P1 (tie rule) and P2 (stroke width), not AA.
- **"acid-stroke-0: the golden varies by LineScaleMode" (s25 F / s26)**: true but incomplete. Even NORMAL-mode rows
  differ: Flash's NORMAL width is isotropic and shear-sign dependent (§P2).
- **"acid-textfield = Flash advanced AA" (s25 G)**: confirmed, with one addition: Flash applies it **at quality LOW**.

## 3. Evidence notes

- Per-cell widths: a connected-components scan (`cells.py`) gives the L/R/T/B run lengths per outline. Golden row 1
  (NORMAL), scale(2,1) cell: L6 R6 T6 B6. Before: L8 R8 T4 B4. After P2: L6 R6 T6 B6.
- acid-shapes-testing diff classes, before: R↔K 25,121 px; W↔K 3,620; W↔R 2,679. After P1: R↔K 2,777;
  W↔K 3,374; W↔R 319.
- acid-textfield: the golden has 795 colours, ours and Ruffle's 7. Best whole-pixel shift of ours vs the golden is
  (1,−1).
- `acid-color [frame1]` stays pass at 1/128 but fails at 1/64 (1 channel, max 4 vs tol 3). Its golden is Flash at
  quality HIGH (s27).

## 4. New unclaimed leads

1. **P1 decision.** Is Flash's aliased tie rule worth 42 Ruffle-golden pixel passes? The s27 Flash captures say 25 of
   31 move Flash-ward or stay level, counting pixels more than 3 off. Captures for the remaining moved rows settle it.
2. **`hairline_restage` matrix bookkeeping.** `blur_scales_with_screen`'s draw reports a 0.82×1.11 matrix for a 200×200
   stage in a 400×400 viewport. Check that the matrix is the object's own and not a stage/pad artefact before
   trusting P2 there. It is not refuted: I did not trace which display object it is.
3. **P2 on drawing-API strokes.** `lineStyle(..., scaleMode)` in `avm2_display.c` around line 9812 is parsed. The
   same isotropic rule should apply, and `strokes/scale` noScale diagonals are the visible case.
4. **Round joins in device space.** This is the last big component of `acid-stroke-0` after P2.

## LOCAL ORACLE REQUESTS

All FLASH, image, `run_image.py` at the test's own quality (draw wrapper, as s27). Archive full frames.
1. FLASH: `from_shumway/acid/acid-big`, image, tick 300. Arbitrates P1 on the one near-Flash golden it loses.
2. FLASH: `visual/filters/blur_scales_with_screen`, image, tick 1. Arbitrates P2's second loss. If it renders via
   filter, use `--screen` if `draw()` mis-renders.
3. FLASH: the P1-moved rows with no archived capture: `drop_shadow`, `glow`, `bevel`, `bevel_inner`,
   `fallback_preferences`, `mouse_pick_dobj_mask`, `stage3d_texture`, `acid-big`, `acid-blend`. Most are
   "untestable" in s27 (default font / input / stage3d), so skip any still untestable.
4. FLASH: `from_shumway/acid/acid-stroke-0`, image, at quality HIGH as well as low. Confirms the stroke-width rule
   is quality-independent, so P2 is not a low-quality artefact.
