# s28 w1-text-glyph-aa: text glyph fidelity vs Flash (wordwrap glyph AA, held rotated fixture)

**New files** (all under `SWFRecompDocs/plans/session28-fanout-reports/`):
- `w1-text-glyph-aa-report.md` (this report)
- `w1-text-glyph-aa-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; one hunk in `tag.c`
  `textfield_glyph_render_cb`; `git apply --check` verified on `origin/master` `d5f9726d`)

No fixture lands: `avm1_edittext_rotated_glyphs` stays HELD (§3).

**Box.** Cloud box, `SETUP_STATUS` all OK (apt, Pillow, Dawn/lavapipe). Branch from `origin/master` `d5f9726d`. Corpus:
`download_tests.sh from_shumway avm1 avm2 visual text fonts from_gnash`, upstream master on 2026-11-25 (= `c2f7d24b7`, the
head of my blobless Ruffle clone from the same hour); `apply_flash_fixes` ran.
**Fidelity:** my clean-master `from_shumway/acid/acid-text-4` render is byte-identical to CI's actual PNG on
`origin/ruffle-image-results` (`475131d7…`), so local grading is CI-grade for text rows on this box.

## Verdicts (lead)

| # | item | verdict | priced flips |
|---|---|---|---|
| 1 | **Premise: "wordwrap residual = glyph AA (~590 ch)"** | **PARTLY REFUTED.** 176 of the 199 px that are off by more than 2 (88 %) are glyph **geometry**, not AA. Flash draws the 10 px square glyph **115 twips tall, not 117.19**. Its bottoms sit exactly on our baselines (our 214-twip pitch is right, §1.2) and its tops are 1/4 px lower. Only **23 px** (69 ch) are true AA: the 4-sample MSAA vs Flash's 16-level coverage at rectangle corners. | — |
| 2 | **Mechanism found: Flash snaps the scaled glyph outline to a 1/4-px (5-twip) grid**, glyph-local (before the pen/baseline translate) | **GO as prototype (measured).** Wordwrap vs its Flash capture: **199 → 23 px** (>2), so the Flash PNG is usable as golden at `tolerance = 1, max_outliers = 69`. Every **Flash-golden** row it touches moves toward Flash: `avm1_edittext_tab_render` 113 → 66 px, `avm1_edittext_tabstops_metric` 153 → 86, `avm1_edittext_border_subpixel` 151 → 102, `text/br_at_start` 782 → 612. None moves away. | **Not landable as-is:** 22 comparisons on **Ruffle** goldens go pass → fail (§4). Disposition needs FLASH captures (LOCAL ORACLE REQUEST 1). |
| 2b | "Flash rounds line metrics" (my first prototype: ascent/descent rounded instead of truncated) | **REFUTED by our own Flash goldens.** It closed wordwrap the same way (199 → 23), but broke `avm1_edittext_tab_render` / `_tabstops_metric` (both Flash golden). At 20 px Flash keeps the truncated 429-twip pitch, and a 4-line fit shows the glyph *bottoms* match truncation on every line. Both the round-each and round-pitch variants were measured. | — |
| 3 | Held `avm1_edittext_rotated_glyphs` vs Flash (1111 px; 1065 px > 2) | **HOLD (NO-GO this wave).** Per-region decomposition: **~744 px (70 %) are the BOX BORDERS**, not glyphs. Our rotated/sheared border is a 1-px axis-projected quad (`tf_border_line_segment`, Ruffle's model). Flash's rotated hairline is 25–32 % heavier: cross-section 1.26–1.32 px vs our 1.00, on every slanted edge. The **glyph part is ~321 px**, on the 30° and shear fields only (the 90° field's glyphs are 0 px). Those are 16-level coverage plus a ~1/16-px edge offset that no fixed sample model fits (§3). The ¼-px snap cannot touch this fixture: font height 1024 means 1 em unit = 1 twip, already on the grid. | 0 |
| 4 | Glyph AA itself (4-sample MSAA vs Flash's 16 coverage levels) | **NO-GO, priced L, renderer-global.** Flash's coverage values are 255 − 16·n in **every** Flash golden checked (glyphs AND shape edges AND borders). WebGPU allows `sampleCount` ∈ {1, 4} only. Exact 16-level coverage needs 4×4 SSAA (16× fill) or analytic coverage, and it would move nearly every Ruffle-golden image row (Ruffle = wgpu 4× MSAA). Axis-aligned edges already match (the 4× rotated-grid x/y thresholds equal the 4×4 grid's). Only corners and diagonals differ. | 0 now; the 23 wordwrap corner px are its floor |
| 5 | Free evidence rows (`acid-text-2/3`, `acid-textfield-scroll`, `flash_text_TextField2`, Flash goldens that PASS) | **They pass by tolerance, not by matching.** `acid-text-2` passes at tolerance 128 with 2 187 px > 2, and its Flash levels are 239/223/207/159 (16-level), ours 255/191/128/64. `acid-textfield-scroll` passes at 552/600 outliers. `flash_text_TextField2` passes at exactly 250/250 (zero headroom). `acid-text-3` is 0 px off, but its golden holds only white and **one flat colour** (324 px of (123,116,94), no AA level at all), so it says nothing about edge coverage. **None is evidence of AA parity.** | — |

**Expected CI movement of the prototype if landed as-is:** pixel **−22 comparisons** (13 rows) on Ruffle goldens, 0 on
Flash goldens, 0 trace. That is why it is delivered as a prototype plus an oracle request, not a landing.

---

## 1. `regression/avm1_edittext_wordwrap_render` vs its Flash capture

Inputs: our graphics render on clean master (`2ba31b4a…`, passes its interim Ruffle golden 45/45) vs
`session27-fanout-reports/w2-local-oracles/w2-avm1-text-layout/avm1_edittext_wordwrap_render/flash.png`.
Diff: 572 px differ, **199 px by > 2** (597 channels at tolerance 1; the brief's "~590").

### 1.1 Classification (per pixel pair, not totals)

| ours → Flash | px | what it is |
|---|---|---|
| 128 → 127, 64 → 63 | ~373 | 1-level rounding of the same coverage (Flash writes 255 − 16·n, n = 8 → 127; ours 255·(1 − n/16) → 128). Inside tolerance 1. |
| **128 → 191** | **136** | **Line-2 glyph top edge:** ours covers 2/4 of row 25, Flash 4/16. |
| **64 → 127** | **40** | **Line-3 glyph top edge:** ours 3/4 of row 36, Flash 8/16. |
| 191 → 159, 128 → 159, 64 → 111 | 23 | **Rectangle corners:** Flash = product coverage on its 4×4 grid (2 cols × 3 rows = 6/16 → 159), ours = 4× rotated-grid MSAA. True AA. |

So **176 / 199 px** are glyph vertical geometry, all on **top** edges.

### 1.2 Which geometry: fitted from four Flash goldens

Font: square `A` glyph 400 × 600 units, em 1024, ascent 900, descent 200, size 200 twips. Exact glyph height
117.1875 twips (5.859 px). Ruffle and we: baseline₁ = 240 + trunc(175.78) = 415, pitch trunc(175.78) + trunc(39.06) = 214.
Constraints from Flash's 16-level edge coverage (4 sub-rows at ⅛ ⅜ ⅝ ⅞), on `wordwrap_render` and `tab_render` (same font,
4 lines in field `d`):

| line | Flash bottom-row coverage → baseline (twips) | ours | Flash top-row coverage | ours |
|---|---|---|---|---|
| 1 | row 20: 12/16 → (412.5, 417.5) | 415 ✓ | row 15 full, row 14 empty | same |
| 2 | row 31: 8/16 → (627.5, 632.5) | 629 ✓ | **row 25: 4/16** | **8/16** |
| 3 | row 42: 4/16 → (842.5, 847.5) | 843 ✓ | **row 36: 8/16** | **12/16** |
| 4 | row 52: 12/16 → (1052.5, 1057.5) | 1057 ✓ | row 47 full, row 46 empty | same |

The bottoms admit our 415 + 214k on all four lines. A brute-force search over every constant pitch, baseline and sub-row
phase finds **no** solution that also keeps the exact glyph height. Intersecting the top-edge intervals gives Flash's
glyph height **h ∈ (114.5, 115.5) twips**: 117.1875 → **115** = 5.75 px, i.e. **snapped to ¼ px**.
The 20 px field `b` of `tab_render` gives h ∈ (233.5, 238.5); exact 234.375 → ¼-px snap **235** ✓.

Grid alternatives were measured on all five Flash goldens (px > 2 vs Flash):

| variant | wordwrap | tab_render | tabstops_metric | border_subpixel | br_at_start |
|---|---|---|---|---|---|
| master (no snap) | 199 | 113 | 153 | 151 | 782 |
| **¼ px, x and y (prototype)** | **23** | **66** | **86** | **102** | **612** |
| ¼ px, y only | 23 | 67 | 87 | 102 | 841 |
| ⅛ px | 824 | 191 | 403 | 320 | 749 |
| ½ px | 355 | 146 | 254 | 194 | 855 |
| line metrics rounded (refuted §2b) | 23 | 157 | 197 | 131 | 703 |

¼ px on both axes is the only variant that improves all five. `br_at_start` is a real-font (multi-glyph-shape) Flash
golden, so this is not just a square-glyph artefact.

### 1.3 Golden swap answer (brief task 4)

**With the prototype, the wordwrap fixture CAN take its Flash capture as golden:** 23 px / **69 channels** exceed
tolerance 1 (all rectangle-corner AA, §4 floor), trace unchanged (`flash.txt` == `output.txt`). Use
`tolerance = 1, max_outliers = 69`. **Without the prototype it cannot** (597 channels). So the swap belongs to whichever
wave-2 lands the snap. Do not swap the golden alone, because master would then fail it.

## 2. The prototype (`w1-text-glyph-aa-prototype.patch`)

`tag.c textfield_glyph_render_cb`, identity-matrix (`!tf_mm`) glyph arm only: the glyph vertex becomes
`rintf(v · scale / 5) · 5 + pen` (glyph-local ¼-px snap of the scaled outline, then the unsnapped twip pen/baseline).
Compile-time escape `-DTF_GLYPH_NO_QSNAP` for A/B. Nothing else changes: line metrics, layout, matrix arm, AVM2 and
DefineText are untouched.

Not done (each a completion item, not a blocker for the oracle request):
- **Matrix arm (`tf_mm`)**: Flash presumably snaps in the same glyph-local space before the world matrix. No fixture
  exercises it with fractional glyph coordinates (scaled/rotated fixtures use font height 1024). XS.
- **AVM2 glyphs** (`avm2_display.c avm2_render_glyphs`) and **DefineText** (`tag_text_glyph_compose`, recompiler
  static text): the same Flash glyph cache very likely applies. Not measured; needs a Flash-golden AVM2 / DefineText row
  with fractional glyph scale. S each.
- **Browser stage scale**: the grid should be ¼ **device** px. The prototype snaps in local twips (stage scale 1 in
  tests). Needs the glyph's device scale (`dscale`) before landing for games. XS.

## 3. Held `avm1_edittext_rotated_glyphs` (brief task 1, 4)

Our render is unchanged by the prototype (`74102da1…` = s27 `ours-after.png`). Against the archived Flash PNG:
1111 px differ, **1065 px by > 2**, max 255.

Per-region map (pixels within 1.2 px of each glyph polygon, from the analytic placement):

| region | px > 2 | character |
|---|---|---|
| 90° field glyphs (2) | **0 / 0** | axis-aligned, all edges on whole pixels |
| 30° field glyphs (2) | 89 / 92 | diagonal-edge coverage |
| shear-0.5 field glyphs (2) | 70 / 70 | diagonal-edge coverage, plus Flash ~1/16 px left of the exact geometry |
| **box borders + the 2 corner dots** | **~744** | **rotated hairline weight** |

- **Borders (dominant).** Summed coverage across each slanted border edge is ours **1.00 px**, Flash **1.255–1.318 px**,
  measured on every 4th row/column of the 30° left/top edges and the shear left edge. Ours is
  `tf_border_line_segment` (`tag.c:7533`): a 1-px quad **projected on the major axis**, Ruffle's `draw_text_box` model,
  pinned by `visual/edittext/edittext_border_transform` (Ruffle goldens). Flash's equals a perpendicular width of
  ~1.12–1.14 px. Neither a square pen (1.37×) nor a diamond pen (= ours) fits. This is a **Ruffle ≠ Flash border-weight
  difference** with one fixture as evidence. Completion: Flash captures of single rotated hairline boxes at 15/30/45/60°
  (LOCAL ORACLE REQUEST 2), then a pen model in `tf_border_line_segment` for the skewed arm only. Priced S once the
  model is known. It moves `edittext_border_transform` .04/.06 (Ruffle goldens), a priced RvF loss.
- **Glyph diagonals.** Analytic 4×4-grid sampling of the exact geometry fits Flash on the 90° field (0 px) but leaves
  56/62 (30°) and 70/70 (shear) px. The shear edge needs **13/16** coverage where any regular 4-column grid gives 12 or 14,
  so Flash's horizontal coverage is finer than ¼ px per sub-scanline. 4 sub-rows × fine-x (exact area) plus a geometry
  shift of −1/16 px fits the shear field at **0 px**. No single shift fits all three fields, so Flash's transformed-glyph
  placement differs by ~1 twip per field in a way not yet pinned. Completion: depends on item 4 (16-level coverage) anyway.
- **Verdict:** not within any tolerance of its Flash capture. **Not landed.** Keep HELD with the Flash PNG archived;
  it becomes landable only after the border pen model, with a glyph-diagonal budget of ~321 px (≈ 960 channels).

## 4. Gate (brief task 3): what the prototype moves

**Scope argument.** The hunk is inside `textfield_glyph_render_cb`'s identity arm. That callback is only reached from
`actionIterateTextFieldGlyphs` (AVM1 EditText, `tag.c:~9163`), so AVM2 text, DefineText, shapes and every non-text row
cannot move by construction. I therefore ran the A/B (`render_canary.py capture/compare`, clean master vs prototype,
`-P 2`) over **every AVM1 image row with text** in avm1/visual/from_shumway/text/fonts/regression/from_gnash: 45 rows
with DefineEditText/DefineText found by a SWF tag scan, 10 `createTextField` rows, and the AVM1 text canary members.
That is **60 tests / 92 comparisons**. My first attempt at the full 211-test canary ∪ text set was killed by the
10-minute background limit at test 61. Nothing in it is reachable that the 60-test set lacks, but the coordinator's CI
run is the full check.

**Result: 30 comparisons DIFFER, 62 md5-identical, 0 trace changes.** Image status:

| moved row | golden provenance | status | vs a Flash PNG (px > 2, before → after) |
|---|---|---|---|
| `regression/avm1_edittext_tab_render` | **Flash** | pass → pass | **113 → 66** |
| `regression/avm1_edittext_tabstops_metric` | **Flash** | pass → pass | **153 → 86** |
| `regression/avm1_edittext_border_subpixel` | **Flash** | pass → pass | **151 → 102** |
| `text/br_at_start` | **Flash** | pass → pass | **782 → 612** |
| `regression/avm1_edittext_wordwrap_render` | Ruffle (interim) | **pass → fail** | Flash capture **199 → 23** |
| `regression/avm1_long_text_layout` | hand/Ruffle | **pass → fail** (48 ch, max 64) | — |
| `from_shumway/acid/acid-text` | not Flash | **pass → fail** (tol 0) | 3783 → 3816 (+0.9 %) |
| `from_shumway/acid/acid-text-escape` | not Flash | **pass → fail** (tol 0) | 2238 → 2238 |
| `text/style_changes_in_html` | not Flash | **pass → fail** (tol 0) | 2901 → 2950 (+1.7 %) |
| `visual/simple_shapes/text_field_mask` | not Flash | **pass → fail** (tol 0) | 1189 → 1185 |
| `visual/text/String_path_variable_button` | untestable | **pass → fail** | — |
| `visual/cache_as_bitmap/edittext_scroll` .01/.02 | untestable | **pass → fail** ×2 | — |
| `visual/filters/{bevel, bevel_full, bevel_inner, bevel_outer, drop_shadow, glow, glow_with_alpha_strength, glow_without_composite_source}` | untestable | **pass → fail** ×8 | — |
| `from_gnash/misc-ming.all/morph_test1` frame2–6 | Gnash/Ruffle | **pass → fail** ×5 (63 ch) | — |
| `from_shumway/avm1/text-bind` | not Flash | pass → pass | 2924 → 2937 |
| `visual/cache_as_bitmap/text` | not Flash | pass → pass | 4787 → 4762 |
| `from_gnash/.../BeginBitmapFill`, `acid-color-0` | — | fail → fail | — |

Reading: every row with a **real Flash golden** moves toward Flash, and none moves away. The pass → fail rows are all
Ruffle / untestable goldens at tight tolerances. Where a Flash PNG exists for them (the four "not Flash" rows), our
distance to Flash moves ±2 %. That is noise against a 1–4 k px gap dominated by other mechanisms (quality-low aliasing
vs a HIGH Flash capture, real-font hinting). So they **neither confirm nor refute** the snap. Under the Flash-over-Ruffle
rule this is a priced RvF loss of **22 comparisons / 13 rows**. It is too large to book on 5 synthetic-or-text Flash
goldens without a Flash look at the losers: LOCAL ORACLE REQUEST 1.

Mode parity: `tag.c` glyph painter, graphics only (the producer and painter run under `HEADLESS_RENDER_ENABLED`). No
no-graphics leg is needed.

## 5. Refutations / premise attacks

- **"~590 channels of glyph-edge AA"**: 88 % of the > 2 px are glyph-height geometry (§1.1). The AA share is 23 px.
- **My own first lead, "Flash rounds ascent/descent"**: it fitted wordwrap alone (199 → 23) but was killed by
  `tab_render`'s 20 px field (Flash keeps trunc 429) and a 4-line bottom-edge fit (bottoms = ours on every line). Lesson
  for the board: a single-fixture fit of a layout rule is not evidence. Test against every Flash golden sharing the font.
- **"The passing Flash-provenance text rows prove we match Flash's glyph AA"**: they pass on tolerance (128, 600, 250/250).
  Their Flash goldens show 16-level coverage everywhere.
- **"The rotated fixture's 1111 px is glyph fidelity"**: 70 % is border hairline weight (§3), a different mechanism and
  a different function (`tf_border_line_segment`).

## 6. New unclaimed leads

1. **Glyph ¼-px snap for AVM2 (`avm2_render_glyphs`) and DefineText** (AVM1 `swf.cpp` / AVM2 `abc_timeline.cpp` static
   text). Same Flash glyph path, presumably. Needs one Flash-golden fixture each with fractional glyph scale. S.
2. **Rotated/sheared border pen weight** (`tf_border_line_segment`, and the AVM2 twin in `avm2_render_textbox`): Flash
   ~1.12–1.14 px perpendicular vs our 1 px axis-projected. Needs Flash captures (REQUEST 2). S after.
3. **Tab-stop pen x at 20 px** (`tab_render` field `b`): Flash's glyph sits ¼ px left of ours at columns 162/170 after
   the snap (the remaining 22 px of that row). Probably a ¼-px snap of the pen/tab-stop x. XS to probe once REQUEST 1
   is in.
4. **`acid-text-3`'s golden has no antialiased pixel** (white plus one flat colour, 324 px). Its exact pass is vacuous as a glyph-AA oracle.
5. **16-level coverage (renderer-global)**: priced L. The only route inside WebGPU's {1, 4} sample counts is 4×4 SSAA on
   an offscreen glyph/shape layer or analytic coverage. Recommend NOT pursuing unless Flash-golden rows become the
   majority of the image board.

## LOCAL ORACLE REQUESTS

1. **FLASH, image, 1 frame, direct (pinned), HIGH quality, for the rows the ¼-px snap moves pass → fail**, so the loss can be
   dispositioned (Flash-ward = RvF + flash_fixes candidates; Ruffle-ward = the snap rule is wrong for that case):
   `regression/avm1_long_text_layout` (SWF in git); `visual/filters/bevel`, `visual/filters/glow`, `visual/filters/drop_shadow`,
   `visual/filters/glow_with_alpha_strength` (all "untestable" in s27; a `--screen` capture is fine, filters only);
   `visual/cache_as_bitmap/edittext_scroll` (2 frames); `visual/text/String_path_variable_button`;
   `from_gnash/misc-ming.all/morph_test1` frame 2. Compare each against **both** legs of the prototype
   (`git apply` / `-R` of `w1-text-glyph-aa-prototype.patch`, `--mode=graphics`). Grade only the text region (the canary
   bboxes in §4). Expected if the snap is right: the after leg is closer on the text glyph rows.
2. **FLASH, image, rotated hairline weight**: an AVM1 SWF with four bordered empty EditTexts (no glyphs, embedded font
   not needed) rotated 15°, 30°, 45°, 60°, plus a sheared one (c = 0.5). Build it from
   `session27-fanout-reports/w2-avm1-text-layout-fixtures/avm1_edittext_rotated_glyphs/create_test_swf.py` with
   `edittext(..., '')` and the four matrices. Measure the summed coverage across each edge. It pins the pen model for
   `tf_border_line_segment`'s skewed arm.
3. (Optional, low priority) **FLASH, image**: `regression/avm1_edittext_wordwrap_render` at `_quality = "BEST"`, to check
   whether Flash's ¼-px glyph grid is tied to the 4×4 HIGH-quality supersampling (BEST would then show a finer grid).
