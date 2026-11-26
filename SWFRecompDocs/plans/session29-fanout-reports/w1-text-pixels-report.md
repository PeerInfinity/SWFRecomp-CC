# s29 w1-text-pixels: text pixels vs Flash (`rotated_glyphs`, wordwrap golden, the 22 glyph-snap losses)

**New files** (all under `SWFRecompDocs/plans/session29-fanout-reports/`):
- `w1-text-pixels-report.md` (this report)
- `w1-text-pixels-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; `tag.c` only, +185 lines;
  `git apply --check` verified on `origin/master` `aa36d43a`; source reverted on the branch)
- `w1-text-pixels-evidence/`: before/after PNGs of `rotated_glyphs` and `rotated_borders`, the Python model render
  (`rotated_glyphs.python_model.png`), the fit scripts (`scan.py` = the scanline coverage model, `model.py`, `edgefit.py`,
  `glyph.py`, `full.py`, `grid.py` = the 4×4-grid control, `lab.py` = region labels, `grade.py`), the reachability
  scanner `scan_skewed_text_rows.py` and the gate list `gate_tests.txt`. The scripts expect `flash.png` (=
  `regression/avm1_edittext_rotated_glyphs/output.expected.png`) and our render in the working directory.

**Box.** Cloud, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Branch `fanout/w1-text-pixels` from
`origin/master` `aa36d43a` (code = `bfa47037b`). Corpus: `download_tests.sh from_shumway text visual avm1 from_gnash fonts`,
upstream Ruffle master **`b7ff32d93`** (`ls-remote` at download time). `apply_flash_fixes` ran.
**Fidelity: CI-grade.** My clean-master `from_shumway/acid/acid-text-4` render is byte-identical to CI's actual PNG on
`origin/ruffle-image-results` (`01b05e1b…`). My clean-master `rotated_glyphs` render md5 (`36b8b1c3…`) equals the gate's
before leg.

## Verdicts (lead)

| # | item | verdict | priced flips |
|---|---|---|---|
| 1 | **`rotated_glyphs`: which pixels, what rule is left** | **Premise stale, then the residual is ANSWERED.** The "1111 px" is the s27 number. At baseline the row PASSES (12/24 ch @ tol 128), with 1102 px off and 1034 px > 2. Of those: **border 713 (69 %)**, glyphs 321 (rot30 181, shear 140), 90° field 2. **None are interior pixels.** All of them are edge coverage. **A perfect 5-level (4-sample) renderer would still miss 888 px > 2**, so the residual is the AA rule itself. It is now pinned (#2). | 0 status flips (row already passes) |
| 2 | **Flash Player 32's HIGH coverage rule** (NO-GO L re-attacked, task 4) | **FOUND and measured.** It is **not** 4×4 SSAA. Flash uses **4 sub-scanlines per pixel row at y + j/4 (j = 0..3), with EXACT horizontal coverage on each**. It quantises the total to 1/16 and writes 255 − 16n. Geometry: vertices are rounded to **¼ device px** after an **unrounded** composition. The skewed text box is **not size-snapped**. A Python model of exactly this gives **196 px > 2** on the fixture. The best 4×4 grid (any sample phase) gives 825, and our 4× MSAA gives 1034. | — |
| 2a | **Prototype** (`tag.c`, skewed text fields only): CPU scan-conversion with that rule, emitted as alpha runs | **GO as prototype, measured.** `rotated_glyphs` vs FP32: **1102 → 198 px off**, and every other pixel is now **bit-exact**. px > 2 1034 → 198. L1 120 660 → 11 001 (−91 %). Shear glyphs **0 px off**. `rotated_borders` vs FP32: px > 2 1829 → 522, L1 207 927 → 26 691 (−87 %). **Gate: 22 tests / 43 comparisons, 39 md5-identical, 0 image or trace status changes.** The two Ruffle-golden movers (`edittext_border_transform` .04/.06) move **toward** their goldens too. **Not landable as-is**: one alpha rect per coverage run is a draw call, against `MAX_DYNAMIC_RECTS` = 4096 per frame (§2.4). | 0 flips. Bands: 2 Flash-golden rows −87/−91 % L1, 2 Ruffle-golden rows −59/−41 % L1 |
| 3 | **Wordwrap fixture "still carries an interim Ruffle golden"** | **REFUTED.** `regression/avm1_edittext_wordwrap_render/output.expected.png` md5 `50d2b8c9…` **is** the s27 FP32 capture (`session27-fanout-reports/w2-local-oracles/w2-avm1-text-layout/avm1_edittext_wordwrap_render/flash.png`, the same md5). s28 w2-glyph-quarter-snap swapped it in (`test.toml` says so). It passes at baseline at 69/69 @ tol 1. **No FLASH request is needed.** The playbook §27 board line is stale. | — |
| 4 | **The 22 "unpriced" glyph-snap losses** | **REFUTED as glyph-snap losses: all 22 were priced by s28 w2-glyph-quarter-snap, and the landed snap owns 0 of them by construction** (`tf_glyph_quarter_snap` returns for device fonts and is compiled out at `MSAA_SAMPLES == 1`). But **20 of the 22 FAIL at baseline**. Other s28 models own them (stroke snap, LOW model, filter residuals), each already priced. **Flash goldens among the 22:** the 2 regression rows (pass) and **`morph_test1` frame1–6** (FP32 LOW `flash_fixes`): the only **real** losses. Their text share is **327 of 1530 channels** on frames 2–6, owned by the unimplemented LOW glyph rule (w2 F3), not by the ¼ snap. Ledger in §3. | 0 |

**Expected CI movement of the prototype if landed as-is: trace 0, pixel status 0.** Four md5 moves, all toward their
goldens (ledger §2.3).

---

## 1. `rotated_glyphs`: where the pixels are (task 1)

Grading: our graphics render vs the row's golden (= s27 FP32 `flash.png`, `c8498d8d…`), luminance, per region.
Region = analytic placement of each field's box (border band ±1.5 px of the box edge, "glyphs" = box interior,
`lab.py`). "Floor" = Flash's image re-quantised to our 5 MSAA levels (0/64/128/191/255), i.e. the best any
4-sample renderer could do.

| region | px > 2, master | floor (perfect 5-level) | px ≥ 1 MSAA level off the floor | L1 master | L1 floor |
|---|---:|---:|---:|---:|---:|
| rot30 border | 461 | 378 | 268 | 20 586 | 8 398 |
| rot30 glyphs | 181 | 151 | 87 | 6 326 | 3 239 |
| shear border | 250 | 218 | 124 | 10 895 | 3 437 |
| shear glyphs | 140 | 140 | **0** | 2 238 | 2 238 |
| 90° border / glyphs | 2 / 0 | 1 / 0 | 2 / 0 | 175 / 0 | 17 / 0 |
| **total** | **1034** | **888** | 481 | 40 220 | 17 329 |

- **Interior pixels: 0.** Flash's levels are the 17 values 255 − 16n. Ours are 0/64/128/191/255. Every off pixel is an
  edge pixel.
- **Shear glyphs are already at the MSAA floor.** That residual is purely the coverage rule.
- **Our slanted border weight aliases.** Along the shear left edge, our ink per row is **1.00 / 1.25 / 1.50 / 1.25 / 1.00**
  in bands of ~12 rows, a beat between the edge phase and 4× MSAA's one-sample-per-sub-row pattern. Flash's is
  **exactly 20/16 on every row**, alternating 7+13 and 15+5 sixteenths. That is the "shear over-ink" w2 noted.
- **Flash's shear edge has slope exactly 0.5** (the 7/13, 15/5 pattern repeats every 2 rows). Ours is 27/55, from
  Ruffle's `rint(27.5 − 0.35)` size snap in `tf_border_skewed_line_rect`. **Flash does not size-snap a skewed box.**

## 2. The rule, and the prototype (task 1 + task 4)

### 2.1 Fitting (Python, `scan.py` / `full.py`)

A scanline rasterizer was fitted against Flash's 16-level sample counts n = (255 − F)/16. It uses N sub-scanlines per
row at y + (j + φ)/N, exact x-coverage per sub-scanline, and union of polygons. Measured on the fixture:

| model | px > 2 vs FP32 | L1 (lum) |
|---|---:|---:|
| our 4× MSAA (master) | 1034 | 40 220 |
| 4×4 grid, best of 6 sample phases (`grid.py`) | 825 | 24 615 |
| 4×4 grid, centred samples | 1017 | 21 081 |
| **4 sub-scanlines at y + j/4, exact x, ¼-px vertices, unsnapped skewed box, border 1 + tan/2** | **196** | **3 587** |

The rule's pieces, each measured on its own:
- **Sub-scanline phase j/4, not (j + ½)/4.** Shear glyphs go 140 → **0** sixteenths off (100 % exact). w1-text-glyph-aa's
  "Flash sits ~1/16 px left of the exact geometry" is this phase, not a geometry shift.
- **Exact x, not 4 columns.** The shear edge's 7/13 split needs a non-quarter x overlap. Every 4-column phase gives 6/14.
- **¼-px corner rounding of the skewed box.** rot30 border error 413 → 83 sixteenths. It is the same ¼-px grid as the s28
  glyph snap.
- **¼-px vertex rounding of skewed glyphs, after an UNROUNDED composition.** rot30 glyphs 396 → 37 sixteenths. Ruffle's
  per-push whole-twip rounding (`matrix.rs Mul`, our `tf_mm` arm) puts the rot30 glyph bottom at 70.0 px. Flash's is at
  69.75 = the unrounded 69.87 → ¼ px.
- **Border width 1 + tan(θ)/2 along the minor axis, centred on the line** (s28 w2's fit). It survives unchanged. Under
  the exact coverage rule the ink per row is exact (20/16 on the shear edge), so w2's "not a pen, a run rule" is now
  explained. It is a parallelogram of that width, scan-converted by the rule above.
- **Axis-aligned edges of a skewed box** keep the pixel row/column below/right of the line (the old model).

Residual 196 px: 94 % are a single 1/16 step (`full.py`), e.g. sub-scanline x precision. Only 25 are within 3 px of a box
corner. I stopped fitting there: a fixed-point x model would be fitting the last 1/16.

### 2.2 The prototype (`w1-text-pixels-prototype.patch`, `SWFModernRuntime/src/libswf/tag.c` only)

Functions touched / added (all in `#ifndef NO_GRAPHICS`, all `#if MSAA_SAMPLES > 1`):
- **new** `tf_cpu_cov_fill` (static): scan-converts convex polygons (device px) with the rule. It merges the
  sub-scanline intervals, accumulates exact coverage per pixel and quantises n = round(16·cov). It emits **runs of equal
  n** as `renderer_draw_rect` alpha rects (alpha **16n/255**, so black on white writes exactly 255 − 16n) through slot 0
  (stage twips). It returns 0 (caller falls back) when the bbox exceeds its row buffer.
- **new** `tf_cpu_cov_enabled` (static, `SWF_TF_CPU_COV=0` opts out: the A/B leg), `tf_cov_iv_cmp`, types
  `TfCovPoly` / `TfCovIv`.
- `tf_border_skewed_line_rect`: new arm before Ruffle's size snap. It takes unsnapped corners rounded to ¼ device px,
  4 border parallelograms (slanted: 1 + tan/2; axis: the old row/column) and `tf_cpu_cov_fill`.
- `textfield_glyph_render_cb`, matrix arm (`tf_mm`) only, skewed matrices only (not 90°/180°/axis-aligned): the glyph's
  triangles are recomposed with the **unrounded** translation, rounded to ¼ device px and drawn by `tf_cpu_cov_fill`
  instead of `renderer_draw_tris`. A label `tf_glyph_drawn` skips the MSAA draw.
- **Untouched:** `tf_border_line_segment` (still the axis-aligned/fallback path), `tf_glyph_quarter_snap`, the identity
  arm, `avm2_display.c` (`avm2_render_glyphs`, `avm2_draw_border_line`), DefineText, LOW quality.

### 2.3 Gate

**Reachability:** the CPU path runs only for an AVM1 EditText with a skewed world matrix, at HIGH quality.
`scan_skewed_text_rows.py` lists every image row (all downloaded suites + regression) with DefineEditText or
`createTextField`, no DoABC, and a rotate/skew PlaceObject matrix (sprites walked) or `_rotation`/`rotation`/`matrix`
in the SWF. That is **14 rows**. I added 8 axis-aligned text controls (wordwrap, long_text_layout, tab_render,
scaled_glyphs, placed_cxform, border_subpixel, `text/br_at_start`, `acid-text-4`), for **22 tests / 43 comparisons**,
captured with `render_canary.py capture` (before = `SWF_TF_CPU_COV=0` ≡ master, md5-checked on `rotated_glyphs`).

**Result: 39 IDENTICAL, 4 DIFFERS, TRACE STATUS CHANGES none, IMAGE STATUS CHANGES none.**

| moved comparison | golden | status | vs golden: px > 2 / L1 (RGB) / ch > 128, before → after |
|---|---|---|---|
| `regression/avm1_edittext_rotated_glyphs` | **FP32** | pass → pass | 1034 / 120 660 / 12 → **198 / 11 001 / 0** |
| `regression/avm1_edittext_rotated_borders` | **FP32** | pass → pass | 1829 / 207 927 / 12 → **522 / 26 691 / 0** |
| `visual/edittext/edittext_border_transform` .04 | Ruffle | pass → pass | 181 / 6 532 / 0 → 86 / 2 660 / 2 (limit 20) |
| `visual/edittext/edittext_border_transform` .06 | Ruffle | pass → pass | 213 / 8 065 / 0 → 140 / 4 743 / 2 (limit 20) |

The 90°-rotated, 2× and placed fields, the axis-aligned regression rows and the device-font rotation rows
(`edittext_device_transform_small_rotation/_shear`: device text is culled under rotation) are md5-identical.
Mode parity: renderer-only, graphics build only, so no no-graphics leg is needed.

### 2.4 Why it is a prototype, not a landing (completion mechanism)

1. **Draw-call budget.** Each coverage run is one `render_webgpu_draw_rect_ex`, i.e. one draw and one dynamic colour
   slot. `MAX_DYNAMIC_RECTS` is 4096 per frame (`render_webgpu.c:2187`). A rotated paragraph (~50 glyphs × ~150 runs)
   would silently drop rects. **Landing needs a batched emit.** Either (a) one R8 coverage texture per field, drawn as a
   single textured quad through the bitmap path, or (b) a single dynamic vertex batch of run quads with per-vertex
   alpha. Scope S–M in `render_webgpu.c` (sibling-owned file: coordinate with w1-aa-sizing).
2. **Browser stage scale**: the rule is applied in device px via `context->stage_scale`, but a browser camera or scroll
   offset that is not in slot 0 would misplace the runs. Same caveat as w2's device-px grid. Needs one browser probe.
3. **Coloured / alpha text**: alpha 16n/255 reproduces 255 − 16n for black on white. For a colour c, Flash's level
   formula is unmeasured. Needs one FP32 capture (request W1 below).
4. **AVM2 twin** (`avm2_render_glyphs`, `avm2_draw_border_line`): not ported. s28 F1/F2 AVM2 fixtures are built and
   waiting for capture.

### 2.5 Scope beyond text (NO-GO L re-priced)

The rule is a renderer-global fact: Flash HIGH = 4 sub-scanlines with exact x coverage. That makes "16-level glyph AA"
a misnomer. The same rule should hold for every Flash shape edge (w1-text-glyph-aa saw 255 − 16n in every Flash golden,
on shapes too). Inside WebGPU it is still **NO-GO L for general shapes**: sample positions are fixed (4× standard
pattern), so no MSAA configuration gives exact per-sub-scanline x coverage. It would need analytic coverage in the
fragment shader (edge-distance or sparse-scanline compute) for every fill. What changes:
- the **target is now exact** (a deterministic rule, verified at 0 px on the shear glyphs), not "some 16-level AA";
- for CPU-known geometry (text boxes, glyphs, possibly hairline strokes) it is **S–M**, not L, via §2.4 (1);
- for w1-aa-sizing: the claim "Flash HIGH = 4×4 SSAA" (w1-avm2-vector-flash) is **refuted on slanted edges** by 825 vs
  196 px. On axis-aligned ¼-snapped geometry the two are indistinguishable, which is why it looked like 4×4.

## 3. The 22 rows (task 3): ledger at results `014124ed5`

"Glyph-snap ownership" = can the landed `tf_glyph_quarter_snap` change this row at all. It cannot for a device-font
(UseOutlines 0) field, and it is compiled out at quality LOW (`MSAA_SAMPLES == 1`). Baseline owner = the s28 model that
made it fail, from the priced lists in `snap-pixel-audit-report.md`, `lowq-corner-rule-report.md` /
`lowq-recapture-report.md` and `w1-filter-residuals-report.md`.

| row (comparisons) | font / quality | golden provenance | status @ `014124ed5` (outliers / limit) | glyph-snap ownership | baseline owner → disposition |
|---|---|---|---|---|---|
| `visual/filters/bevel` | device / high | Ruffle ("untestable", default font) | fail 58 894 / 6 | 0 (device) | stroke snap `09b2c9130` (+ LOW pass) → priced, host fonts, no flash_fix |
| `visual/filters/bevel_full` | device | Ruffle | fail 22 945 / 18 | 0 | same |
| `visual/filters/bevel_inner` | device | Ruffle | fail 15 433 / 18 | 0 | same |
| `visual/filters/bevel_outer` | device | Ruffle | fail 27 926 / 18 | 0 | same |
| `visual/filters/drop_shadow` | device | Ruffle | fail 39 985 / 0 | 0 | stroke snap + filter residuals → priced |
| `visual/filters/glow` | device | Ruffle | fail 18 373 / 0 | 0 | stroke snap → priced |
| `visual/filters/glow_with_alpha_strength` | device | Ruffle | fail 15 800 / 18 | 0 | stroke snap → priced |
| `visual/filters/glow_without_composite_source` | device | Ruffle | fail 19 184 / 0 | 0 | stroke snap → priced |
| `visual/cache_as_bitmap/edittext_scroll` .01 / .02 | device | Ruffle ("untestable") | fail 287 / 5, 289 / 5 | 0 | filter residuals `bc585e9f2` (fractional shadow offset) → priced, playbook §27 |
| `visual/text/String_path_variable_button` | device | Ruffle ("untestable") | fail 78 / 12 | 0 | LOW model (lowq-recapture after→golden 78) → priced |
| `from_shumway/acid/acid-text` | embedded / **low** | not Flash (s27) | fail 2 868 / 0 | 0 (LOW) | stroke snap → RvF (snap-pixel-audit) |
| `from_shumway/acid/acid-text-escape` | embedded / low | not Flash | fail 480 / 0 | 0 | LOW model → priced (lowq §6) |
| `text/style_changes_in_html` | embedded / low | not Flash | fail 688 / 0 | 0 | LOW model → priced |
| `visual/simple_shapes/text_field_mask` | embedded / low | not Flash | fail 630 / 0 | 0 | LOW model → priced (class c) |
| `from_gnash/misc-ming.all/morph_test1` frame1 | embedded / low | **FP32 LOW (`flash_fixes`, lowq-recapture)** | fail 193 / 0 | 0 | LOW model; **real Flash loss**, but not text (one vertical shape edge, 20 px per 20-row band) |
| `morph_test1` frame2–5 (×4) | embedded / low | **FP32 LOW** | fail 1 530 / 0 each | 0 | **real Flash loss: text line 327 ch** ("- xtrace enabled", rows 2–10) + morph shape 1 203 ch |
| `morph_test1` frame6 | embedded / low | **FP32 LOW** | fail 727 / 0 | 0 | real Flash loss: text 327 ch + shape 400 |
| `regression/avm1_long_text_layout` | embedded / high | **FP32** (swapped s28 w2) | pass 48 / 48 | Flash-ward (30 → 16 px) | — |
| `regression/avm1_edittext_wordwrap_render` | embedded / high | **FP32** (swapped s28 w2) | pass 69 / 69 | Flash-ward (199 → 23 px) | — |

That is 23 comparisons on 15 rows, counting `morph_test1` ×6 and `edittext_scroll` ×2. w1-text-glyph-aa's "22"
counted `morph_test1` ×5. Its frame1 was never a snap mover.

**Reading.** No row on this list is a loss of the landed glyph snap. **Real losses (Flash goldens, failing): `morph_test1`
×6 only.** Their text part (327 ch × 5 frames) belongs to the **LOW glyph rule**. s28 w2 found a "1-px glyph-local snap +
pen rounded to px" variant Flash-ward on morph's text line (120 → 83 px) but away on the acid rows. Its F3 request
asked for direct-root LOW captures. Correction to w2's reason for holding it: the s28 lowq-recapture shows the `draw()`
wrapper **always** set `stage.quality` (the old-stub trap hit pinned-direct runs only). So the LOW captures w2 graded
against were valid, and "no single LOW rule fits" stands on good evidence. The shape part (1 203 ch) is the LOW model's
board (`lowq-sample-point-model-status`). Everything else is a priced Ruffle-golden loss with an existing disposition.
**No flash_fixes candidates from this slot.**

## 4. Refutations / premise attacks

- **"rotated_glyphs is 1111 px off"**: 1102 px / 1034 px > 2 at baseline. The row passes at its tol-128 budget.
- **"The wordwrap fixture still carries an interim Ruffle golden"**: it carries the FP32 capture (md5 match).
- **"22 unpriced glyph-snap losses"**: all priced in s28 w2-glyph-quarter-snap §1. The landed snap cannot reach 20 of
  them, and the other 2 are Flash-ward.
- **"Flash HIGH = 4×4 SSAA"** (w1-avm2-vector-flash, the w1-aa-sizing premise): 825 px (best grid) vs 196 px (4
  sub-scanlines + exact x) on slanted edges.
- **"The rotated residual is border weight"** (w1-text-glyph-aa): the weight was fixed by s28 w2. The border still
  dominates (69 %) because 4× MSAA cannot hold a 1.25-px ink constant along a slope (1.00–1.50 beat). That is the
  coverage rule, not the weight.
- **"Flash's shear glyphs sit ~1/16 px left"** (w1-text-glyph-aa): it is the sub-scanline phase (y + j/4). With it the
  exact geometry is 0 px off.
- **w2's "matrix-arm snap: device-space snap measured slightly away"**: true under MSAA. Under the exact coverage rule,
  the ¼-px device-space vertex rounding is Flash-ward (rot30 glyphs 396 → 37). The missing piece was the unrounded
  composition.

## 5. New unclaimed leads

1. **Land the coverage rule for skewed AVM1 text** with a batched emit (§2.4 (1)). It moves 4 comparisons, all toward
   their goldens, 0 status changes. It needs the colour capture W1 first. S–M, `tag.c` + `render_webgpu.c`.
2. **AVM2 twin**: `avm2_render_glyphs` / `avm2_draw_border_line` with the same rule. The s28 F1/F2 AVM2 fixtures exist.
3. **Exact coverage for other CPU-known hairlines**: the s28 thin-stroke snap rows (axis-aligned, so unaffected) and any
   slanted hairline stroke in `acid-shapes` / `acid-stroke-0`. Probe: does the same rule fit a slanted stroke's Flash
   pixels? If so, the "Flash stroke rule" board item gets an exact target.
4. **Ruffle's per-push twip rounding of glyph translations** (`tf_mm` arm, `tag_text_glyph_compose`) is not Flash's.
   Flash composes unrounded and then snaps to ¼ px. The MSAA arm keeps Ruffle's rounding, and it may cost on
   scaled-text rows too (not measured).
5. **Skewed-box size snap**: Ruffle's `rint(s − 0.35)` on a sheared box (C = 27.5 → 27) is not Flash's. That is an RvF
   entry once the prototype lands. Not written now (no landing).
6. `morph_test1` frame2–6 text line: 327 ch × 5 frames of a FP32-golden row, owned by the LOW glyph rule (w2 F3).

## LOCAL ORACLE REQUESTS

- **W1. FLASH, image, 1 frame, direct pinned, HIGH:** a colour variant of `regression/avm1_edittext_rotated_glyphs`.
  Build it with `create_test_swf.py`, changing `base.edittext(5, 1, (0, 0, 0), 'II')` to text colour `(0xCC, 0x33, 0x00)`.
  Also put one field over a mid-grey background shape (`DefineShape` rect 0x808080 behind depth 2). It pins Flash's level
  formula for a coloured glyph/border at coverage n/16 over white and over grey, needed before landing (§2.4 (3)).
  Compare: per-pixel value vs n from the black capture.
- **W2. (optional) FLASH, image, 1 frame, direct pinned, HIGH:** one slanted hairline **shape stroke** (DefineShape,
  LineStyle width 0 / 20 twips, black, from (10.3, 10.1) px to (180.7, 95.4) px) plus a filled slanted triangle. It tests
  lead 3: does the 4-sub-scanline exact-x rule hold for shapes and strokes too? Grade with
  `w1-text-pixels-evidence/scan.py`.
