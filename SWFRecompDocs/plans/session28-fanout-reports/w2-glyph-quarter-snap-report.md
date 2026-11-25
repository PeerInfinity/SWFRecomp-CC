# s28 w2-glyph-quarter-snap: Flash's 1/4-px glyph snap + slanted border pen weight (wave 2, implementation)

**New files**
- `SWFRecompDocs/plans/session28-fanout-reports/w2-glyph-quarter-snap-report.md` (this report)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-glyph-quarter-snap.patch` (the landable patch; see Delivery)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_rotated_borders/` (`create_test_swf.py`, `test.swf`, `test.toml`,
  `output.txt`, `output.expected.png` = FP32 direct-pinned capture from `w1-local-oracles/w1-text-glyph-aa/`)
- `ruffle-tests/tests/swfs/regression/avm1_edittext_rotated_glyphs/` (the s27 HELD fixture, now landed;
  `output.expected.png` = s27 FP32 `flash.png`)
- `SWFRecompDocs/plans/session28-fanout-reports/w2-glyph-quarter-snap-fixtures/` (FLASH-request SWFs, not landed:
  `avm1_edittext_glyph_snap_matrix/`, `avm2_edittext_glyph_snap_matrix/`, `avm2_edittext_rotated_borders/`, each
  with generator or recipe, `test.toml`, `output.txt`, and `ours-after.png`)

**Modified:** `SWFModernRuntime/src/libswf/tag.c` (new `tf_glyph_quarter_snap`; one call in
`textfield_glyph_render_cb`'s identity arm; `tf_border_line_segment`), the golden + `test.toml` of
`regression/avm1_edittext_wordwrap_render` and `regression/avm1_long_text_layout`, `ruffle-tests/render_canary_tests.txt`
(2 members appended at EOF), `RUFFLE_VS_FLASH_DIFFERENCES.md` (1 entry appended at EOF).

**Box.** Cloud, `SETUP_STATUS` all OK. Branch `fanout/w2-glyph-quarter-snap` from `origin/master` `6f0a3c67`.
Corpus: `download_tests.sh visual text from_gnash from_shumway avm1 avm2 fonts` (upstream master at the time, 2026-11-25;
`ls-remote` at report time is `d2a801a98`), `apply_flash_fixes` ran. **Fidelity: 18/18 of my clean-master renders that
have a CI actual PNG on `origin/ruffle-image-results` are byte-identical** (incl. the text rows `acid-text-4`,
`acid-text-5`, `acid-textfield`, `BeginBitmapFill`, `Video-EmbedSquareTest`), so the local grades below are CI-grade.

## Verdicts (lead)

| # | item | verdict | priced flips |
|---|---|---|---|
| 1 | Land the 1/4-px glyph snap | **GO, with the rule refined by measurement**: embedded fonts only, antialiased builds only (MSAA > 1), identity-matrix arm, grid = 1/4 DEVICE px (`5 / stage_scale` twips), pen rounded to the same grid. | 0 corpus status changes; 2 regression goldens swapped to Flash (both pass) |
| 1a | w1's 22 pass → fail comparisons | **All 22 dispositioned, 0 lost.** 11 were **device-font** rows (UseOutlines = 0: 8 `visual/filters/*`, `edittext_scroll` ×2, `String_path_variable_button`): Ruffle-ward, fixed by the embedded-only rule. 9 were **quality = low** rows (`acid-text`, `acid-text-escape`, `style_changes_in_html`, `text_field_mask`, `morph_test1` ×5): no LOW rule fits all the available Flash captures; LOW is left unsnapped (FLASH request F3). 2 are our own regression rows, **Flash-ward by measurement**, golden swapped to the Flash capture. | — |
| 2 | Slanted border pen weight (`tf_border_line_segment`) | **GO (fitted, Flash golden).** Flash's ink across a slanted edge is **1 + tan(θ)/2 px** along the minor axis, centred on the line (no HALF_PX). `rotated_borders` L1 vs Flash 166 744 → 69 309. `edittext_border_transform` .04/.06 (Ruffle goldens) move **toward** their goldens (outliers 16/15 → 0/0), so there is no RvF loss to price. | +2 new regression rows (pass) |
| 3 | Land HELD `avm1_edittext_rotated_glyphs` | **GO** at a stated budget: tolerance 128, max_outliers 24 (ours 12; before the border fix 219). L1 vs Flash 59 857 → 40 220. | +1 row |
| 4 | `avm1_edittext_wordwrap_render` golden → Flash | **DONE.** Re-measured: 69 channels > 1 (= w1's prediction), `tolerance = 1, max_outliers = 69`. Trace: `flash.txt` == `output.txt`. | pass → pass |
| 5 | Matrix arm (`tf_mm`) | **NO-GO this wave (refuted variant + no oracle).** A device-space snap of the transformed outline measured slightly **away** from Flash on `rotated_glyphs` (L1 40 220 → 40 889, px > 2 1034 → 1035). A glyph-local snap is a no-op on every fixture (they use FontHeight 1024 = whole twips). FLASH request F2 (built). | 0 |
| 6 | Device-px grid | **DONE** inside the identity arm (`q = 5 / context->stage_scale`). Stage scale is 1 in every test, so it is inert on CI; it matters only in the browser. | 0 |
| 7 | AVM2 `avm2_render_glyphs` / `avm2_render_textbox`, DefineText | **NOT implemented: no Flash capture.** AVM2 SWFs built for F1/F2 (via the `avm2_edittext_placed_cxform` DoABC converter). DefineText request F4 is written, not built. | 0 |

**Expected CI movement: trace 0. Pixels: +2 comparisons (2 new regression rows, both pass), 0 status changes on
existing rows.** The regression rows `wordwrap_render` and `long_text_layout` stay pass because their goldens change in
the same patch.

## EXPECTED-FLIP LEDGER (coordinator: check CI against this)

| test | axis | before (master) | after (patch) | note |
|---|---|---|---|---|
| `regression/avm1_edittext_rotated_borders` | pixel | — (new) | **pass** (12 / 24 @ tol 128) | NEW row, Flash golden. On master it would fail at 891 / 24. |
| `regression/avm1_edittext_rotated_borders` | trace | — (new) | pass (empty output) | |
| `regression/avm1_edittext_rotated_glyphs` | pixel | — (new) | **pass** (12 / 24 @ tol 128) | NEW row, Flash golden. On master it would fail at 219 / 24. |
| `regression/avm1_edittext_rotated_glyphs` | trace | — (new) | pass (empty output) | |
| `regression/avm1_edittext_wordwrap_render` | pixel | pass (45/45 vs Ruffle interim) | pass (69/69 vs **Flash**) | golden swapped; md5 moves |
| `regression/avm1_long_text_layout` | pixel | pass (0/0 vs hand golden) | pass (48/48 vs **Flash**) | golden swapped; md5 moves |
| `regression/avm1_edittext_tab_render`, `_tabstops_metric`, `_border_subpixel`, `text/br_at_start` | pixel | pass | pass | md5 moves, all toward their Flash goldens (table below) |
| `visual/edittext/edittext_border_transform` .04 / .06 | pixel | pass (16/20, 15/20) | pass (0/20, 0/20) | md5 moves toward the Ruffle goldens |
| `from_gnash/misc-ming.all/Video-EmbedSquareTest` | pixel | fail (1782) | fail (1818) | Gnash golden, video row "untestable" for Flash in s27 provenance; the +36 channels are the "- xtrace enabled" text line (embedded font, HIGH) |

Everything else in the 230-test / 330-comparison gate is **md5-identical**.

## Per-test before/after (clean `origin/master` vs patch, same box)

Graded against the row's FLASH reference (px with any channel > 2 / channels > 1):

| test | Flash reference | before | after |
|---|---|---|---|
| `regression/avm1_edittext_wordwrap_render` | s27 `flash.png` (now the golden) | 199 px / 597 ch | **23 px / 69 ch** |
| `regression/avm1_long_text_layout` | w1 direct capture (now the golden) | 30 px / 90 ch | **16 px / 48 ch** |
| `regression/avm1_edittext_tab_render` | golden (Flash) | 113 / 339 | **66 / 198** |
| `regression/avm1_edittext_tabstops_metric` | golden (Flash) | 153 / 459 | **86 / 258** |
| `regression/avm1_edittext_border_subpixel` | golden (Flash) | 151 / 453 | **102 / 306** |
| `text/br_at_start` | golden (Flash) | 782 / 1833 | **598 / 1406** (golden check 4/8 → 0/8 outliers) |
| `regression/avm1_edittext_rotated_borders` | golden (Flash direct-pinned) | 2174 px; L1 166 744; tol-128 ch 891 | 1829 px; **L1 69 309**; tol-128 ch **12** |
| `regression/avm1_edittext_rotated_glyphs` | golden (s27 Flash) | 1065 px; L1 59 857; tol-128 ch 219 | 1034 px; **L1 40 220**; tol-128 ch **12** |

The px > 2 floor on the rotated rows is 16-level coverage vs 4× MSAA (w1 §4, priced L, renderer-global). That is why
their budget is set at tolerance 128.

## 1. The w1 pass → fail rows, classified (task 1)

Method: our render before/after the w1 prototype vs the Flash capture. For each row I compare only the pixels the snap
changes, dilated by 2 px. For LOW rows I also do a per-text-block ±2 px shift-aligned grade, because those captures
carry pre-existing 1–2 px layout offsets.

| row (w1 loss) | font | quality | Flash vs ours, text region | class → disposition |
|---|---|---|---|---|
| `visual/filters/{bevel,bevel_full,bevel_inner,bevel_outer,drop_shadow,glow,glow_with_alpha_strength,glow_without_composite_source}` | **device** (UseOutlines 0) | high | Flash's labels are its OS font: AA'd, 4 px higher, wider (e.g. "K" bbox 498–515 × 26–46 vs ours 499–513 × 30–50). The snap moved 27–57 px each: glow/drop_shadow 102 → 116 px > 2 (21 farther, 6 closer); bevel 221 → 215 | **Ruffle-ward / no basis** → fixed: snap is embedded-only |
| `visual/cache_as_bitmap/edittext_scroll` .01/.02 | device | high | 24 → 26, 31 → 35 | Ruffle-ward → fixed (embedded-only) |
| `visual/text/String_path_variable_button` | device | high | no Flash capture | fixed (embedded-only) |
| `from_shumway/acid/acid-text` | embedded | **low** | aligned L1 1.05 M → 1.07 M (¼ px) / 1.11 M (1 px rule) | ~neutral / slightly away → LOW unsnapped |
| `from_shumway/acid/acid-text-escape` | embedded | low | aligned px > 2 1808 → 1809; Flash sits +1–2 px right in both legs (pre-existing) | neutral → LOW unsnapped |
| `text/style_changes_in_html` | embedded | low | ¼ px 2901 → 2950 (away); 1 px + pen rule → 2396 | ¼ px wrong at LOW → LOW unsnapped |
| `visual/simple_shapes/text_field_mask` | embedded | low | ¼ px 1189 → 1185; 1 px + pen → 439 | ¼ px neutral → LOW unsnapped |
| `from_gnash/misc-ming.all/morph_test1` frame2–6 | embedded | low | vs s27 LOW `draw()` capture, text line: ¼ px 120 → 119; 1 px rule → 83 (it restores the "t" stem that our LOW render and the Gnash golden drop) | LOW unsnapped (see below) |
| `regression/avm1_long_text_layout` | embedded | high | Flash 30 → 16 px > 2; the remaining 16 px are glyph corners (16-level AA) | **Flash-ward** → golden swapped to Flash (task 4 analogue) |
| `regression/avm1_edittext_wordwrap_render` | embedded | high | 199 → 23 | **Flash-ward** → golden swapped (task 4) |

**Why LOW is left alone (attacking my own best lead).** At LOW I swept the grid (none, ¼, ½, 1 px), pen rounding on
and off, and per-axis splits (7 variants × 4 rows). The "1-px glyph-local snap + pen rounded to px" variant is strongly
Flash-ward on `text_field_mask` (aligned L1 606 k → 224 k) and `style_changes_in_html` (433 k → 389 k), and on morph's
text line (120 → 83 px). But it is 4–6 % **away** on both acid rows, and every variant that fixes the acid rows
loses the other two. The captures themselves are suspect for this question. They are s27 `draw()`-wrapper captures with
forced LOW quality, and s27 showed that wrapper's forced quality was wrong for `acid-bitmap-draw_quality_low`. The w1
direct captures are HIGH (`"quality": null`, antialiased), so they cannot grade a LOW row. So no LOW rule is landable.
FLASH request F3 asks for direct-root LOW captures. If those confirm the 1-px rule, it is a one-line `#elif
MSAA_SAMPLES == 1` arm in `tf_glyph_quarter_snap` (grid 20 twips). Its expected moves are `text_field_mask` and
`style_changes_in_html` pass → fail vs their tol-0 Ruffle goldens (Flash-ward, so flash_fixes candidates), and
`morph_test1` frame2–6 (93 px vs the Gnash golden).

**No flash_fixes candidates from this slot.** The two Flash-ward losers are our own regression rows, and their goldens
are swapped in this patch.

## 2. Completing the snap (task 2)

- **Rule as landed** (`tag.c tf_glyph_quarter_snap`): `v' = rint(v·scale / q)·q + rint(pen / q)·q`, with
  `q = 5 / stage_scale` stage twips. Pen rounding was tested separately: it is neutral on 5 of the 6 HIGH Flash rows
  and helps `br_at_start` (612 → 598). It cannot move axis-aligned edges under the 4× pattern (samples sit at odd
  eighths, and ¼-px rounding moves an edge ≤ ⅛ px). A device-space snap of the final coordinate alone is a
  **no-op** at HIGH on axis-aligned glyphs for the same reason. Measured: that leg was byte-identical to master on 5
  of the 6 HIGH Flash rows, and on the sixth (`br_at_start`, real-font curves) it moved slightly **away**
  (782 → 793 px > 2). This confirms w1's finding that the snap is glyph-local.
- **Matrix arm (`tf_mm`)**: left unsnapped (verdict 5). F2 (`avm1_edittext_glyph_snap_matrix`, built) puts FontHeight 200
  glyphs at identity / 2× / 0.5× / 1.37× / 30°, so a glyph-local snap (115 → 135-twip glyph) and a device snap give
  different pixels.
- **AVM2 / DefineText**: not touched. F2's AVM2 twin (`avm2_edittext_glyph_snap_matrix`, built with the
  `avm2_edittext_placed_cxform` DoABC converter) covers `avm2_render_glyphs`. F4 (DefineText) is written but not built
  (no fractional-scale DefineText generator yet; `regression/avm1_definetext_matrix`'s generator is the starting point).

## 3. Border pen weight (task 3)

Measured on `avm1_edittext_rotated_borders` (FP32 direct-pinned; draw() is within 242 px / max 16 and gives the same
sums). "sum" is the ink summed across the edge along its minor axis, averaged over the middle 50 % of each edge:

| edge | Flash sum | Ruffle model (master) | landed model | Flash centroid off line | master | landed |
|---|---|---|---|---|---|---|
| 15° (4 edges) | 1.136–1.138 | 0.998 | 1.123–1.133 | +0.02..+0.18 | +0.37..+0.64 | ±0.00 |
| 30° / 60° (8 edges) | 1.292–1.294 | 0.998 | 1.264–1.312 | −0.16..+0.28 | +0.20..+0.79 | ±0.01 |
| shear 26.6° (2) | 1.255 | 1.000 | 1.366 | 0.00 | 0.00 | −0.24 |
| 45° (2 unclipped) | 1.004 | 1.000 | 1.000 | +0.13/+0.34 | −0.03/+0.75 | −0.03/−0.25 |
| axis-aligned (shear top/bottom) | 1.000 | 1.000 | unchanged | +0.50 | +0.50 | unchanged |

Model: `k = 1 + tan(θ)/2` (θ off the major axis; k = 1 at the exact 45° tie), centre offset 1/16 device px (best of
−⅛, 0, 1/16, ⅛, ¼ by L1 and blurred L1; k = 0.4 / 0.6 both worse). The shear edge over-inks under 4× MSAA because
its 2-row phase period aliases with the sample pattern. **Not a pen.** For any convex pen the minor-axis cross-section
is convex in tan θ, but Flash's is 1.0 at 0°, ~1.29 at 30° and 1.0 again at 45°. Flash's hairline is a
rasterizer-specific run rule. w1's "neither square nor diamond pen fits" was right, and this is why. Gated
`MSAA_SAMPLES > 1` (no LOW capture). The AVM2 twin `avm2_draw_border_line` (Ruffle's 1-px perpendicular
`emulate_line_as_rect`) is **not changed**: F1 (`avm2_edittext_rotated_borders`, built) is the request.

`visual/edittext/edittext_border_transform` (Ruffle goldens) .04/.06 go from 16/15 to **0/0** outliers at tolerance 128,
so there is no RvF loss to price. An RvF entry is written anyway, for the confirmed Ruffle ≠ Flash hairline difference.

## 4. Gate (wave-2 bar)

- **Set:** the standing render canary (`render_canary_tests.txt`, all tiers) ∪ every image row with a DefineEditText /
  DefineText / `createTextField` in avm1, avm2, visual, text, fonts, regression, from_shumway and from_gnash (a SWF tag scan,
  AVM1 and AVM2 alike). Total **230 tests, 330 comparisons**. That covers w1's 60-test / 92-comparison set and all
  regression text rows. `render_canary.py capture` before (clean master) and after (patch), `-P 3`.
- **Result:** 321 IDENTICAL, 9 DIFFERS (exactly the ledger), trace status changes **none**, image status changes
  only the two swapped goldens. With the swapped goldens, all four touched regression rows pass
  (`verify_output.py --tests-dir=…/regression --mode=graphics --verbose`): wordwrap 69/69, long_text 48/48,
  rotated_borders 12/24, rotated_glyphs 12/24.
- **Regression suite:** 53 regression rows are in the gate, with no trace changes. The patch is renderer-only (inside
  `#ifndef NO_GRAPHICS`, gated on `MSAA_SAMPLES`), so **no no-graphics leg is needed** (brief: graphics only).
- **Canary:** 2 members appended at EOF (`regression/avm1_edittext_rotated_{borders,glyphs}`), because the standing set
  had no slanted-border Flash row.

## Refutations / premise attacks

- **"The 22 Ruffle-golden losses need Flash captures to disposition"**: half need no capture. 11 of 22 are device-font
  text, which Flash draws with the OS font engine, so a snap of our stand-in outlines has no Flash basis at all.
- **"The w1 direct captures grade the LOW rows"**: they are HIGH (antialiased, `quality: null`). Grading LOW
  `morph_test1` against them says the opposite (binarised: unsnapped 55 vs 1-px 110) of the LOW draw() capture (120 vs 83).
- **"Snap in device space"**: inert on axis-aligned glyphs at HIGH under 4× MSAA (byte-identical on 5 of 6 Flash rows), slightly away on `br_at_start` (782 → 793) and on the matrix arm.
  The snap is glyph-local.
- **"Border weight is a pen model"** (w1's framing): refuted by convexity (§3). It is a run rule.
- **"Rotated border fix = priced RvF loss on `edittext_border_transform`"**: it is the opposite, a move toward the
  Ruffle golden (16/15 → 0/0).

## Not finished, with completion mechanism

1. **LOW-quality glyph snap**: FLASH F3 (direct-root LOW captures), then an `MSAA_SAMPLES == 1` arm (XS).
2. **Matrix-arm snap**: FLASH F2, then extend `tf_glyph_quarter_snap` to the `tf_mm` arm in whichever space F2 pins (XS).
3. **AVM2 glyph snap + AVM2 border weight**: FLASH F1/F2-AVM2, then port to `avm2_render_glyphs` and
   `avm2_draw_border_line` (S).
4. **DefineText snap**: build F4, then FLASH, then `tag_text_glyph_compose` / recompiler static text (S).
5. **16-level coverage** (the floor under every remaining Flash-golden text residual): renderer-global, priced L (w1 §4).

## New unclaimed leads

1. `from_gnash/misc-ming.all/morph_test1`'s Gnash golden drops the "t" stem of "xtrace" at LOW, as our unsnapped render
   does. Flash's LOW draw() capture keeps it. If F3 confirms, that is a golden-provenance note for the gnash suite.
2. `acid-text-escape`: Flash's text blocks sit a consistent +1–2 px right of ours in every block. This is a layout
   offset unrelated to the snap, roughly 400 of its 2 207 px > 2.
3. The shear-edge over-ink (1.366 vs 1.255) is 4× MSAA phase aliasing at slope ½. A per-segment offset tweak could take
   it, but it would be fitting noise. Leave it for the 16-level coverage work.

## LOCAL ORACLE REQUESTS

- **F1. FLASH, image, 1 frame, direct pinned + draw(), HIGH:**
  `session28-fanout-reports/w2-glyph-quarter-snap-fixtures/avm2_edittext_rotated_borders/test.swf`. It is the AVM2
  twin of `regression/avm1_edittext_rotated_borders` (same boxes, DoABC stub). Compare the per-edge ink sums with the AVM1
  capture. If they are equal, port the landed model to `avm2_draw_border_line`.
- **F2. FLASH, image, 1 frame, direct pinned + draw(), HIGH:** `…/avm1_edittext_glyph_snap_matrix/test.swf` and its AVM2
  twin `…/avm2_edittext_glyph_snap_matrix/test.swf`. FontHeight 200 square glyphs at identity / 2× / 0.5× / 1.37× / 30°.
  It pins the snap space for scaled/rotated fields and whether AVM2 glyphs snap. `ours-after.png` is next to each.
- **F3. FLASH, image, DIRECT ROOT at quality LOW** (the stub's `_quality = "LOW"`, not the draw() wrapper):
  `visual/simple_shapes/text_field_mask`, `text/style_changes_in_html`, `from_shumway/acid/acid-text`,
  `from_shumway/acid/acid-text-escape`, `from_gnash/misc-ming.all/morph_test1` (last frame). It decides the LOW glyph
  rule (1-px glyph-local + pen-rounded vs none).
- **F4. (not built) FLASH, image, HIGH:** a DefineText with FontHeight 200 square glyphs (start from
  `regression/avm1_definetext_matrix/create_test_swf.py`) at identity and 2×. It answers whether static text snaps.

## Delivery

`w2-glyph-quarter-snap.patch` = `git diff --binary origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py
ruffle-tests/render_canary_tests.txt ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md
ruffle-tests/tests/swfs/regression/{avm1_edittext_rotated_borders,avm1_edittext_rotated_glyphs,avm1_edittext_wordwrap_render,avm1_long_text_layout}`
(17 files; it is **binary**, because the goldens are PNG swaps/additions, so apply it with `git apply`, not `patch`). It is
wider than the standard list because the two golden swaps and the RvF entry must land with the code, or master fails
`wordwrap_render` / `long_text_layout`. Proven: `git apply --check -R` on the branch head, and `git apply --check` on
a fresh `origin/master` (`6f0a3c67`) worktree. The FLASH-request fixtures under `w2-glyph-quarter-snap-fixtures/` are
on the branch only, not in the patch. `RecompiledScripts/` were not committed (gitignored, and deleted in the new dirs).
Functions touched in `tag.c`: `tf_border_line_segment` (slanted arm), `tf_glyph_quarter_snap` (new, static),
`textfield_glyph_render_cb` (one call in the identity arm). No sibling-map overlap: w2-lowq-sample-point may touch
`tag.c cab_snap_delta` only.
