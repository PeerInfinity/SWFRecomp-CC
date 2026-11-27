# s30 w1-lowq-residues: the LOW pixel residues (diagnosis + measured prototypes)

Slot `w1-lowq-residues`, wave 1. Branch `fanout/w1-lowq-residues`, base `origin/master` `f4edebdc` (runtime = s29 FINAL
code `2d40d3799` plus the s30 landing batch 0 goldens).
- Cloud box, Dawn on lavapipe. `SETUP_STATUS`: apt OK, Pillow OK, Dawn OK.
- Corpus: `download_tests.sh avm2 from_gnash visual from_shumway avm1`, then `text fonts`, on 2026-11-27. flash_fixes
  APPLIED 79. The script prints no upstream SHA.
- **CI fidelity is proven on 10 renders.** Clean-master local renders are md5-identical to the CI actuals on
  `origin/ruffle-image-results`:
  - `avm2/sprite_with_frames`;
  - `from_gnash/misc-ming.all/place_object_test`;
  - `morph_test1` frame1–6;
  - `regression/avm2_layer_group_alpha` and `_erase`;
  - plus the HIGH row `avm2/graphics_draw_triangles`, with the prototype applied.

  Local grading on these rows is CI-grade.
- **Every A/B below is a same-binary env-leg A/B.** One build per row; the kill switches reproduce the clean-master
  render md5-exactly (checked on `layer_alpha`, `layer_erase`, `lowq_tsnap_tie_probe` and `morph_test1`).

## New files

- `SWFRecompDocs/plans/session30-fanout-reports/w1-lowq-residues-report.md` (this file).
- `SWFRecompDocs/plans/session30-fanout-reports/w1-lowq-residues-prototype.patch`: prototypes A + C (§5).
  `git apply --check` was verified against `origin/master`; the source tree is reverted.
- `SWFRecompDocs/plans/session30-fanout-reports/w1-lowq-residues-fixtures/`:
  - **`lowq_glyph_probe/`, for FLASH REQUEST 1:**
    - `create_test_swf.py`, which builds `test.swf` (DefineFont2) and `test_df3.swf` (DefineFont3);
    - our renders `ours_s30_master_plus_tie_eps.png` and `ours_df3_s30_worktree.png`;
    - CPU-model predictions `pred_chord_halfup.png`, `pred_chord_rint.png` and `pred_fine16_halfup.png`.
  - **`ledger/`:**
    - `flash_low_gate_pass3.txt`: all 146 rows, 5 legs;
    - `flash_low_gate_pass4_final.txt`: the shipped A + C;
    - `flash_low_gate_pass2_xy_eps.txt`;
    - `c_scope_mainpass.txt`;
    - `pen_text_rows.txt`;
    - `x_tie_scope.txt`.
  - **`tools/`:**
    - the CPU glyph-raster model: `font2.py` (a DefineFont2/3 parser), `glyphs.py`, `model.py`;
    - the pricing scripts `price.py` and `evaltext.py`;
    - `gate2.py`, the per-row gate: one `SWF_KEEP_BUILD_DIR` build, then env legs;
    - `rerun.py`, which re-executes a kept build with env vars and the test's capture triggers.

## Verdicts (lead)

**Gate result (shipped A + C):**
- The 146 rows are the 114-row s29 Flash LOW gate, the 11 regression LOW rows, the item rows and the 33 LOW text rows.
- **1 status move: `visual/simple_shapes/gradients/gradients` fail → PASS.** It is a flash_fixes FP32 golden, so the
  move is Flash-ward.
- **0 pass → fail.** The trace axis is untouched (render-only change).
- **The one priced loss:** the 14 FP32 `blend_modes/*` rows move away by +10 … +48 channels each (+397 in total) under
  C (§4).

**Priced flips available beyond the shipped patch:**
- `from_gnash/misc-ming.all/morph_test1` [frame1] **fail → PASS** (193 → 0, FP32): needs the x half of the tie rule,
  HOLD (§2.3).
- Its frames 2–6 then sit at 198 (150 with B). With the chord glyph rule (LEAD 4, §2.1), the priced value is 48 each.

1. **GO (prototype A): the LOW TSNAP tie is decided on the object's LOCAL device offset from its (already snapped)
   parent, not on the composed world value.**
   - **Evidence.** `visual/blend_modes/layer_alpha`, FP32: sprite 5 sits at local y −90.5 under a parent at 140.95,
     which snaps to 141.
     - World 50.5 rounds half-even to 50: that is ours.
     - Local −90.5 rounds half-even to −90, giving 51: that is FP32 (the gradient bar occupies rows 51..95 in Flash and
       50..94 in ours).
   - **Why s29 missed it.** The s29 probe cannot separate the rules: every snapped parent in `lowq_stroke_probe` row 6
     is an EVEN integer, so both rules agree on all 16 cells (checked against `cells.json`).
   - **Gate:** exactly 6 rows move, all toward FP32 (channels):

     | row | master | A |
     |---|---:|---:|
     | `blend_modes/layer_alpha` | 4268 | 3733 |
     | `layer_erase` | 2033 | 1514 |
     | `alpha_no_layer` | 2225 | 1660 |
     | `erase_no_layer` | 2141 | 1591 |
     | `regression/avm2_layer_group_alpha` | 4268 | 3733 |
     | `regression/avm2_layer_group_erase` | 2033 | 1514 |

     Kill switch: `SWF_LOWQ_TSNAP_LOCAL=0`.
2. **GO with a priced cost (prototype C): an exact-centre tie of a LOW vertex in y is exclusive at the top and
   inclusive at the bottom.**
   - **Evidence.** The tie probe's drawRect 5.5..25.5 covers rows 6..25 in FP32 and 6..24 in ours. `morph_test1`'s
     1-twip outline is the same tie.
   - **On the GPU:** vertex y biased by +1/256 px (the lavapipe subpixel step) before the existing LOW y rule. Text
     soups are exempt.
   - **Gate (FP32 goldens), master → C:**
     - `morph_test1` frames 2–5: 1401 → **804** each; frame6: 598 → **398**;
     - `acid-stroke-0`: 3413 → **3032**;
     - **`gradients`: 3 → 0, PASS**;
     - `lowq_tsnap_tie_probe` 1250 → 1148, `lowq_stroke_probe` 5745 → 5370, `lowq_gradient_orient_probe` 915 → 744,
       `lowq_sample_point_probe` 1225 → 1231 (all pass → pass).
   - **Cost:** 14 `blend_modes/*` rows +397 channels in total (FP32), the two regression twins +39 / +34, and
     `acid-text-6` frame5 +3 (not Flash).
   - Kill switch: `SWF_LOWQ_TIE_EPS=0`; `=m` = main pass only, which is identical on every row.
3. **HOLD (prototype B, measured, not shipped): the LOW glyph pen rounds half-UP.**
   - **For:** it fits `place_object_test`. Its 'a' at 10.5 / 68.5 and ',' at 520.5 sit at 11 / 69 / 521 in FP32.
     Moves: `place_object_test` 2604 → 2442, `morph_test1` −48 per frame, `shape_test` 9709 → 9661,
     `BeginBitmapFill` 894 → 888.
   - **Against:** it is **refuted as a universal rule** by the FP32 golden of `visual/simple_shapes/text_field_mask`
     (1336 → **2152**). That row's 'W' pens at 180.5 / 418.5 round DOWN (half-even holds) in Flash.
   - **What differs:** the advances are whole twips in both rows, so both are genuine .5 ties. The rows differ in font
     tag (DefineFont2 12 px vs DefineFont3 64 px, HTML).
   - Net it is away (−496 vs +816), so it is not in the patch. **FLASH REQUEST 1 decides it** (both fonts, x phases
     .25 / .5 / .75, and many natural .5 pens at 18–96 px).
4. **LEAD (measured on a CPU model; needs a recompiler change): at LOW, Flash draws each quadratic glyph edge as its
   CHORD.** This is "the LOW glyph rule" the brief asked for.
   - **The model** (`tools/model.py`) parses the DefineFont2 curves and rasterises them with the existing LOW vertex
     rule. With our fine flattening and our pen it **reproduces our GPU text at 0 px**, given the dumped triangles.
   - **Text px ≠ FP32 (12 px gnash Bitstream Vera; every curve deviates ≤ 0.34 px):**

     | row | now (GPU) | fine curves | chords, rint pen | chords, half-up pen |
     |---|---:|---:|---:|---:|
     | `place_object_test` | 868 | 1049 | 362 | **296** |
     | `shape_test` | 181 | 213 | 89 | **69** |
     | `morph_test1` line | 66 | 81 | 36 | **16** |

   - **Ruled out:** every vertex-quantisation grid (twip, 1/32, 1/16, 1/8, 1/4) is worse, and so is every sample
     offset; chords with the existing LOW rule are the clear minimum.
   - **Thresholds:** any device tolerance from 0.35 px to 3 px gives the same result here. The data bound the
     threshold from below only.
   - **Priced with verify's comparator** (model composited into our renders, channels at the test's tolerance):
     - `place_object_test` 2604 → **888** (rint pen: 1086);
     - `shape_test` 9709 → 9373;
     - `morph_test1` frames 2–6 → **48** together with C and the x-tie half.
   - **Owner:** `SWFRecomp/src/swf.cpp`, the embedded-font glyph loop (`font_glyph_entries`, around :3006, which calls
     `interpretShape`). Emit a second, chord-flattened tessellation per glyph. The runtime picks it in `tag.c`
     `textfield_glyph_render_cb` (identity arm, LOW, `!device_font && !csm_advanced`).
   - **Why it cannot be a runtime prototype:** embedded glyphs reach the runtime only as triangles, and their path
     slots are `{0, 0}`.
5. **HOLD: the x half of the vertex tie** (`x_tie_scope.txt`).
   - **Same bias on x:**
     - fixes the tie probe c6 / c7 (174 → 0 each) and `morph_test1` frame1 (**→ PASS**); frames 2–6 go to 150 with B;
     - fails two FP32 passes: `visual/cache_as_bitmap/scroll_rect` (0 → 96, one column, x = 229) and
       `visual/edittext/edittext_underline` (0 → 106, glyph pixels).
   - **Exempting text soups** fixes `edittext_underline`.
   - **`scroll_rect` is still 96, cause not found.** Its cached and crop draws are already flagged out of the LOW
     vertex rule (`transform[2].w`).
6. **`avm2/sprite_with_frames`: NO flash_fixes swap. The 44 k premise is refuted.**
   - **39 756 of the 44 694 channels are loop phase.** The s30 capture caught the child's OTHER frame (no green square).
   - The golden IS Flash at this tick: s27 golden-provenance has "Flash (exact) 0/0@t0" and "a 2-frame loop, which
     passes at some settle times only".
   - **Ours vs golden 4944:**
     - root "Frame 1" label 2478;
     - child label 2463;
     - square 3 (one bottom-right corner pixel, 0 vs 111 grey).
   - **The labels are FlashType** (`CSMTextSettings` useFlashType = 1, gridFit = 2), which Flash anti-aliases even at
     LOW. That is the standing NO-GO, register row `acid-textfield`: "a FlashType rasteriser".
   - **No cheap move.** Rendering the same SWF through our HIGH text-coverage path is NOT Flash-ward: root text
     2478 → 2578 at t0, 1640 → 1789 at t8.
7. **`regression/avm2_layer_group_alpha` / `_erase` priced.**
   - They are byte-identical twins of `visual/blend_modes/layer_alpha` / `layer_erase`: same golden PNG (0 channels),
     and our AVM2 render is md5-equal to our AVM1 render.
   - **alpha, 4268:**
     - **(a) 2186 ch: a Ruffle ≠ Flash compositing rule.** The ALPHA child (shape 19, a linear alpha 0→1 gradient
       whose pad region covers world x 116..124) PAINTS alpha 0 there.
       - **Flash** multiplies the group by 0 and erases the first "r" in all three logo rows.
       - **Ruffle's** `alpha.wgsl` discards src.a == 0, so it cannot tell painted-0 from unpainted. The upstream
         golden keeps the glyph, and so do we.
       - Our layer goes through the child-layer composite (`render_webgpu.c` `fs_alpha_erase` over a cleared texture),
         so a per-draw shader edit does not reach it; that was tested, 0 effect.
       - Completion mechanism: a coverage channel for the child layer (stencil written by the child's draws; composite
         with stencil test instead of `discard`). M. RvF entry ready in §7.
     - **(b) ~535 ch:** the bar's TSNAP tie. **Fixed by A.**
     - **(c) ~1547 ch:** logo edge rasterisation (curve chords / ties: blend rows move under C) plus ≤ 16-level blend
       rounding (~509 ch).
   - **erase, 2033:** (b) + (c) only. (a) cannot occur, since ERASE at a = 0 is a no-op.
8. **`lowq_tsnap_tie_probe` rows 4–5 (item 1): the premises are re-read.**
   - The **45° regime switch and the w = 5 clamp** were solved by s29 w2b (width on the ¼ grid, n = min(W, 4) below
     5.5 px). Row 4 c1–c6 are 12–42 channels each now.
   - The **3-px band** is solved (c0 / c1: 6 ch each).
   - The **drawRect .5 tie** is C (y) plus the HOLD x half.
   - **What is left (1148 with A + C):**
     - row 4 c0 (171 ch): the w = 1 "\" diagonal is 1 px right of Flash, while "/" is exact;
     - row 4 c7 (186 ch): the w = 10 polygon caps and one flank;
     - row 5 c2 / c3 / c4: the acid matrices (168 / 138 / 51);
     - c6 / c7: x ties, 120 each.

     All of it except c6 / c7 is LOW stroke placement (`render_webgpu.c` `lowq_stroke_place` / `lowq_band_centre`).
     **HOLD:** fitting a direction-dependent 45° tie from one cell would be over-fitting; the stroke probe's rows 7–11
     (the same 1-px diagonal raster) are the better fit set.

## 1. Item 2 (`morph_test1`, `place_object_test`): what the residues are

- **`morph_test1` (FP32 LOW).** The brief's "morph-shape residue (1203 ch)" and "frame1's vertical shape edge (193)" are
  ONE thing: the morph square's 1-twip outline.
  - We emit it as a 1-px quad centred on the integer edge (139.5..140.5). The GPU top-left tie puts it on pixel c − 1;
    Flash puts it on pixel c.
  - So every frame is our square shifted (−1, −1) at the outline (extents per frame: ours 139..239 × 99..199, FP32
    140..240 × 100..200).
  - The y half (C) fixes the rows; the x half (HOLD) fixes the columns.
  - **Not** a missing morph restage. `hairline_restage` never sees morph draws: they sit in the dynamic region, and
    `hairline_runs` is keyed on static offsets. Fixing that is a separate lead (§8) that this row does not need.
- **The text line** ("- xtrace enabled", 327 ch on frames 2–6) is the glyph rule of LEAD 4 (chords) and LEAD 3 (pen).
- **`place_object_test`.** 100 % text. 868 px → 296 px under chords + half-up pen (§Verdicts 4).
  - The 296 left are 1–2 px per glyph, spread over 'e' 'o' 't' 'c' 's'. None of the vertex-quantisation or offset
    variants reduce them.

## 2. Mechanisms and evidence

### 2.1 The chord rule

- **Fit.** For each glyph the dumped pen (an env-gated debug dump in a scratch worktree, not in the patch), the
  DefineFont2 outline and the existing LOW vertex rule give:

  | variant | `place_object_test` text px ≠ FP32 |
  |---|---:|
  | fine (16 segments / Levien) | 1049 |
  | n = 2 | 782 |
  | n = 3 | 910 |
  | tolerance 0.1 px | 732 |
  | tolerance 0.25 px | 408 |
  | tolerance ≥ 0.35 px, or n = 1 | **362** (rint pen) |

- **Sampling sweep** (x bias ±0.1 / ±0.25, plain centre sampling at sy 0 … 0.5): all ≥ 538. The existing LOW rule is
  the minimum.
- **Pen sweep** with chords: raw (unrounded) 1201; rint 362; half-up 296; half-down 388.
- **The same rule on the other two FP32 rows:** `shape_test` 181 → 69, `morph_test1` 66 → 16.

### 2.2 The pen tie (B) and its refutation

- **`place_object_test` per-glyph best shift:** 204 glyphs prefer 0, 5 prefer +1. The 4 clear cases sit at exactly
  x.5 (10.5 ×2, 68.5, 520.5), where `rintf` rounds to even.
- **`text_field_mask`** ('W' advance 59.5 px, pens 2.0, 61.5, 121.0, 180.5, …):
  - half-even matches FP32 on every glyph;
  - half-up makes 180.5 and 418.5 worse (144 → 544 px each).
- **Field origins are integers in both rows** (place_object_test bounds −2, placed at 0; text_field_mask placed at
  (2, 102)). So the rule depends on something the two rows do not separate. REQUEST 1 has both fonts at the same
  sizes and phases.

### 2.3 The x half of the tie

- **Variants** (worktree builds; `x_tie_scope.txt`):

  | variant | scroll_rect | underline | tie probe | morph f1 | morph f2–5 |
  |---|---:|---:|---:|---:|---:|
  | y only | P0 | P0 | 1094 | 193 | 756 |
  | x only | 96 | 106 | 1022 | P0 | 753 |
  | x + y, text exempt from x | 96 | **P0** | 974 | P0 | 150 |

  All three builds had B on, so the morph values include B (−48 per frame).
- **Main-pass-only scope** (`SWF_LOWQ_TIE_EPS=m`) changes nothing on `scroll_rect`.
- **Completion mechanism:**
  - find the draw that owns `scroll_rect`'s column x = 229 (a shape inside a cacheAsBitmap sprite with a scrollRect;
    Flash ends the cyan region at 228, x-ε at 229);
  - then gate the x bias with the same text exemption.

  **The flip:** `morph_test1` [frame1].

## 3. Item 3 (`sprite_with_frames`) detail

| region | ours → FP32 | golden → FP32 | ours → golden |
|---|---:|---:|---:|
| root text (y < 60) | 2478 | **0** | 2478 |
| child text (y 160–215) | 2460 | 2066 | 2463 |
| square (y 215–400) | 39 756 | 39 756 | 3 |

- **The golden is FP32-exact on the root label**, which shows no phase difference.
- The child label moves 1 px between the child's two frames (`DefineEditText` ids 3 / 4); that is the golden→FP32 2066.
- **The flash_fixes swap the brief floated is NOT warranted.** It would make the row grade against the frame the test
  does not render at `num_ticks = 2`.

## 4. Gate ledger (final shipped prototype A + C; `flash_low_gate_pass4_final.txt`)

Only rows that moved under any leg are listed. Pass 3 moved 49 of the 146 rows; the other 97 were byte-identical
under every leg. Pass 4 re-ran those 49 rows (56 comparisons) with the final code: 30 comparisons moved, all listed. Values are outliers vs the row's
golden.

| row | golden | master | A | C | A + C |
|---|---|---:|---:|---:|---:|
| `visual/simple_shapes/gradients/gradients` | FP32 (ff) | F3 | F3 | **P0** | **P0** |
| `from_gnash/misc-ming.all/morph_test1` frame2–5 | FP32 (ff) | 1401 | 1401 | 804 | **804** |
| `morph_test1` frame6 | FP32 (ff) | 598 | 598 | 398 | **398** |
| `from_shumway/acid/acid-stroke-0` | Flash (gate) | 3413 | 3413 | 3032 | **3032** |
| `visual/blend_modes/layer_alpha` | FP32 (ff) | 4268 | 3733 | 4307 | **3772** |
| `visual/blend_modes/layer_erase` | FP32 (ff) | 2033 | 1514 | 2067 | **1548** |
| `visual/blend_modes/alpha_no_layer` | FP32 (ff) | 2225 | 1660 | 2266 | **1701** |
| `visual/blend_modes/erase_no_layer` | FP32 (ff) | 2141 | 1591 | 2180 | **1630** |
| `regression/avm2_layer_group_alpha` | FP32 | 4268 | 3733 | 4307 | **3772** |
| `regression/avm2_layer_group_erase` | FP32 | 2033 | 1514 | 2067 | **1548** |
| `visual/blend_modes/add` | FP32 (ff) | 712 | 712 | 725 | 725 |
| `darken` | FP32 (ff) | 1067 | — | 1092 | 1092 |
| `difference` | FP32 (ff) | 818 | — | 830 | 830 |
| `hardlight` | FP32 (ff) | 1512 | — | 1556 | 1556 |
| `invert` | FP32 (ff) | 1692 | — | 1740 | 1740 |
| `lighten` | FP32 (ff) | 681 | — | 693 | 693 |
| `multiply` | FP32 (ff) | 1090 | — | 1115 | 1115 |
| `overlay` | FP32 (ff) | 1424 | — | 1468 | 1468 |
| `screen` | FP32 (ff) | 699 | — | 709 | 709 |
| `subtract` | FP32 (ff) | 722 | — | 733 | 733 |
| `regression/lowq_tsnap_tie_probe` | FP32 | P1250 | — | P1148 | P1148 |
| `regression/lowq_stroke_probe` | FP32 | P5745 | — | P5370 | P5370 |
| `regression/lowq_gradient_orient_probe` | FP32 | P915 | — | P744 | P744 |
| `regression/lowq_sample_point_probe` | FP32 | P1225 | — | P1231 | P1231 |
| `visual/simple_shapes/gradients/focal_radial` | FP32 (ff) | P0 | — | P0 (render moved, still 0) | P0 |
| `from_shumway/acid/acid-text` | not Flash | 309 | — | 303 | 303 |
| `from_shumway/acid/acid-text-6` frame5 | not Flash | 18 | — | 21 | 21 |

(— = same as master. ff = flash_fixes.)

**Net on FP32 / Flash goldens:**
- **A: −3 223 channels**, on 6 rows.
- **C: −2 972 on 3 rows (7 comparisons), +397 on 14 rows, +73 on the 2 regression twins; 1 flip.**

**HIGH:** every change is under `MSAA_SAMPLES == 1`, except:
- one static field write in `avm2_render_node` (a dead store at HIGH);
- the `render_webgpu_draw_tris` style word, which is `#if`-guarded.

`avm2/graphics_draw_triangles` (HIGH) with the patch is md5-identical to its CI actual.

**B (not shipped), pass 3 H leg** (pen half-up alone, master otherwise):
- `place_object_test` 2604 → 2442;
- `morph_test1` frames 2–5 1401 → 1353, frame6 598 → 550;
- `shape_test` 9709 → 9661;
- `BeginBitmapFill` 894 → 888;
- **`text_field_mask` 1336 → 2152.**

## 5. The prototype (`w1-lowq-residues-prototype.patch`): functions touched

**A, the TSNAP local tie** (kill switch `SWF_LOWQ_TSNAP_LOCAL=0`):
- **`SWFModernRuntime/src/libswf/tag.c`, inside TSNAP's `MSAA_SAMPLES == 1` block:**
  - new `lowq_tsnap_local_on`;
  - new non-static `lowq_tsnap_delta_px(t, o, have_o)`: rounds t − o half-even when the origin o is a whole px, else
    the world rule;
  - new statics `g_tsnap_origin`, `g_tsnap_have_origin`;
  - touched `lowq_tsnap_delta` (uses `lowq_tsnap_delta_px`) and `compose_children`: sets the origin to
    `parent_composed[12..13]` around `LOWQ_TSNAP_IN_PLACE`, under `#if`.
  - Root-level callers (`lowq_tsnap_world`, `lowq_tsnap_root_leaf`, `lowq_tsnap_attached`) keep the world rule; their
    parent is the stage.
- **`SWFModernRuntime/src/avm2/avm2_display.c`:**
  - new static `g_avm2_tsnap_origin`;
  - touched `avm2_lowq_tsnap` (calls `lowq_tsnap_delta_px`) and `avm2_render_node` (sets the origin from
    `parent_world`).

**C, the vertex-y tie** (kill switch `SWF_LOWQ_TIE_EPS=0`; `=m` main pass only). All in
`SWFModernRuntime/src/rendering/render_webgpu.c`:
- WGSL `LOWQ_SNAP_Y` (bias `lq_ey`) and `LOWQ_VS_POSITION` (reads `lq_eps` from stage m[10] and exempts style bit 16);
- `lowq_put_target` (writes m[10] = 1/256);
- `render_webgpu_draw_tris` (sets style bit 16 at LOW).

**Wave-2 notes:**
- **Bit 16 is set on EVERY `render_webgpu_draw_tris` soup.** That covers the text paths (tag.c :9783 / :9878 / :9910 /
  :9977, `avm2_display.c` glyph batches) and also the **AVM2 runtime Graphics** fills / strokes (`avm2_display.c`
  ~:19737 / :19774 / :19830 / :19949). So C does not reach AVM2 Graphics draws in this prototype.
  - Wave 2 should set the bit from the text callers only, through a flag parameter or a text wrapper, and re-gate the
    AVM2 Graphics rows (`graphics_*`, `acid-*` AVM2).
- **Not touched:** `swf.cpp`, `swf_core.c`, `tag_stubs.c` and `NO_GRAPHICS` arms. No new TU and no recompiler change,
  so `--recompile` is not needed.
- **Sibling overlap:** w1-stroke-geometry owns `drawingUnionTris` and `gfx_build_stroke`, neither touched.
  - C changes the LOW vertex stage for strokes too. That is how `acid-stroke-0` and `lowq_stroke_probe` move, so the
    two slots should land in sequence and re-gate.

## 6. Refutations / premise attacks

- **"sprite_with_frames: both are far from Flash (44 k)":** refuted, §3. It is a loop-phase capture; the golden is
  Flash.
- **"morph-shape residue 1203 ch + frame1 vertical edge 193":** it is one vertex-tie rule, not morph geometry (§1).
- **"place_object_test: pen → whole px is the LOW glyph rule":** half right. The pen rounding is real, but its .5 tie
  differs between two FP32 rows. The larger term is the curve rule: chords cut the text error 66 %.
- **"Ties go to EVEN" (s29 TSNAP):** refined. Even, but on the LOCAL offset (A).
- **"no model fits row 4's regime switch and the w = 5 clamp":** obsolete. s29 w2b fitted both. What is left on row 4 is
  c0 (one diagonal) and c7 (caps).
- **"avm2_layer_group_*: a separate ~80 k layer-group gap"** (already corrected at launch): the actual residue is 4268,
  and half of it (2186) is the painted-alpha-0 ALPHA rule.

## 7. RvF entry (ready to append at EOF of `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`; not appended here, to keep this commit inside `session30-fanout-reports/`)

```
## s30 ALPHA blend: a PAINTED alpha-0 child pixel erases the layer (w1-lowq-residues, 2026-11-27)

**Tests:** `visual/blend_modes/layer_alpha` (flash_fixes FP32 LOW `--screen`), `regression/avm2_layer_group_alpha` (twin).

The ALPHA child (shape 19: linear gradient alpha 0 → 1, padded, at world x 116..363) paints alpha 0 over world
x 116..124. FP32 multiplies the LAYER group by that 0 and erases the first "r" of all three logo rows. Ruffle's
`shaders/blend/alpha.wgsl` discards src.a == 0 (it cannot tell painted-0 from unpainted in its child surface), so the
upstream golden keeps the glyph; ours copies that (`render_webgpu.c` `fs_alpha_erase` / `fs_alpha_layer`). 2186 of
layer_alpha's 4268 channels vs FP32. ERASE is unaffected (a = 0 is a no-op there).

**Decision:** match Flash (pending: a child-layer coverage channel; see the w1-lowq-residues report §Verdicts 7).
Prune criterion: Ruffle's alpha blend stops discarding painted alpha-0 texels.
```

## 8. New unclaimed leads

- **LOW glyph chords** (LEAD 4): the recompiler emits a chord tessellation of embedded glyphs, and the runtime selects
  it at LOW. ≈ −1 700 channels on `place_object_test` alone. FLASH REQUEST 1 gives the threshold.
- **The x half of the vertex tie** (§2.3): one `morph_test1` flip, plus the tie probe c6 / c7. Blocked on
  `scroll_rect`'s column.
- **Child-layer ALPHA coverage** (§Verdicts 7a): −2186 channels on `layer_alpha` and its twin.
- **Morph strokes never reach `hairline_restage`.** `render_webgpu_draw_morph` stages its lerped vertices in the
  dynamic region, and `hairline_runs` is keyed on static offsets. So morph hairlines get neither the min-1px
  re-expansion (HIGH) nor the LOW stroke rule.
  - `morph_test1` does not need it: its residue was the tie.
  - At HIGH, a 1-twip morph outline is drawn at the emitted width.
  - Fix: let the restage take the lerped soup and derive centres from the quad pairs (A + n, A − n).
- **The C cost on `blend_modes/*`** (+10 … +48 each): the logo shapes are curve-heavy. The chord rule may apply to
  shape curves too at small sizes; test it on `blend_modes/add` with the CPU model.
- **Row 4 c0 of the tie probe:** the w = 1 "\" diagonal is 1 px right of FP32 ("/" is exact). Fit it on
  `lowq_stroke_probe` rows 7–11.

## LOCAL ORACLE REQUESTS

1. **FLASH: `session30-fanout-reports/w1-lowq-residues-fixtures/lowq_glyph_probe/test.swf` AND `test_df3.swf`, image,
   tick 1, direct pinned. The SWFs set `_quality = "LOW"` themselves.** LNX, plus WIN for a WIN == LNX check.
   - **`test.swf`** (gnash DefineFont2, the font of the three FP32 rows the rule was fitted on), with 12 px rows at
     field x + 0 / .25 / .5 / .75. Compare against:
     - `pred_chord_halfup.png` vs `pred_chord_rint.png`: decides the pen tie;
     - `pred_fine16_halfup.png`: chords vs curves;
     - 18 / 24 / 36 / 48 / 72 / 96 px rows: the deviation threshold where Flash stops drawing chords.
   - **`test_df3.swf`** (text_field_mask's DefineFont3, only 'A' / 'W') at 12 / 24 / 64 px and the same phases: whether
     the opposite pen tie of `text_field_mask` comes from the font tag / size rather than HTML layout.
   - Rebuild with `python3 create_test_swf.py` (it reads the corpus `place_object_test` and `text_field_mask` SWFs);
     byte-identical output.
