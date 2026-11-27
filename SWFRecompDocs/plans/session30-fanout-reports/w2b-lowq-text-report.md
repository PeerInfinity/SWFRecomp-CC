# s30 w2b-lowq-text: the DF2 ceil switch is the SWF VERSION (landed, SWF ≥ 7); the pen-local y rule scoped to em-1024 fonts

Slot `w2b-lowq-text`, wave 2b (implementation). Branch `fanout/w2b-lowq-text`, base `origin/master` `0224aaf2`
(w2-lowq-land landed in `a18a0e033`).

**The box:**
- Cloud, Dawn on lavapipe. `SETUP_STATUS`: apt OK, Pillow OK, Dawn OK.
- Corpus: `download_tests.sh text from_gnash visual avm1 avm2 from_shumway fonts` (2026-11-27); flash_fixes applied.
  The script prints no upstream SHA.

**Fidelity:**
- Every A/B is a same-binary env-leg A/B (one build per row, legs via kill switches). Leg **M** =
  `SWF_TF_LOW_ADV_CEIL=0 SWF_TF_LOW_PEN_LOCAL_Y=1` restores master behaviour exactly.
- M is md5-identical to a clean-`origin/master` build: md5-identical to a clean `origin/master` build (patch reverted with `git apply -R`, rebuilt) on `style_changes_in_html`, `BeginBitmapFill` and `lowq_glyph_probe_df2`.
- My M leg on `text/style_changes_in_html` reproduces w2-lowq-land's "after" score vs FP32 to the channel
  (24 390 / 5 252 / 2 626 at t0/16/64). That is the same render as their measurement.

## New files

- `SWFRecompDocs/plans/session30-fanout-reports/w2b-lowq-text-report.md` (this file).
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-lowq-text.patch`: the deliverable,
  `git diff origin/master -- SWFModernRuntime ruffle-tests/tests/swfs/regression/lowq_glyph_probe_df2/test.toml
  ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`. No recompiler change and no new
  regression fixture dirs.
- `SWFRecompDocs/plans/session30-fanout-reports/w2b-lowq-text-fixtures/`:
  - **`swfver_ceil_probe/`, for FLASH REQUEST 1:** `create_test_swf.py`, `test_v5.swf` … `test_v8.swf`,
    `test.toml`, `output.txt`, and our renders `ours_v{5..8}_{master,patch}.png`.
  - **`ypen_scope_probe/`, for FLASH REQUEST 2:** `create_test_swf.py`, `test.swf`, `test.toml`, `output.txt`,
    `ours_master.png`, `ours_patch.png`.
  - **`ledger/`:** `gate_c1.txt` (ceil rows), `gate_c2.txt` (headline rows, 4 legs), `gate_c3.txt` (32-row LOW text
    gate), and `tools/` (`gate.py` with env-defined legs, `rerun.py`, `words.py` (the per-word dx/dy matcher),
    `score.py` (channels |Δ| > t), `scan.py` (the corpus DF2-font scan), `df2.py` (tag/DF2 parser)).
- **Edited:**
  - `ruffle-tests/tests/swfs/regression/lowq_glyph_probe_df2/test.toml`: `max_outliers` 52527 → **12891** (the
    patched measurement). It is a tighter guard, so a regression of the ceil rule fails the row.
  - `ruffle-tests/tests/swfs/avm1/_investigation/RUFFLE_VS_FLASH_DIFFERENCES.md`: a new EOF entry for the LOW DF2
    whole-px advance (SWF 7+).

## Verdicts (lead)

1. **GO: the DefineFont2 advance ceil is gated by the SWF VERSION. It is now on for SWF ≥ 7.**
   - **The finding:** `BeginBitmapFill` and `morph_test1` carry a **byte-identical** xtrace DefineEditText
     (`02007ffd87d5…c9 01 0300 f000 _root._trace_text " - xtrace enabled -\n"`) and the same DefineFont2 (0xa4).
     - `BeginBitmapFill` (Flash golden, s27 FP32 wrapper draw() within tolerance) **ceils**: 'e' at 47, 'n' at 67
       relative to the field, matching the ceil model exactly.
     - `morph_test1` (FP32, s27 and s28, LNX + WIN, wrapper) **does not ceil**.
     - So no field property, transform, text source, frame or capture mode can be the switch. The two SWFs differ
       in header version: **morph_test1 is SWF 6, BeginBitmapFill is SWF 8.**
   - **Every FP32 data point fits "SWF ≥ 7":**
     - df2 probe and the 8 adv_flags rows (SWF 8): ceil.
     - `BeginBitmapFill` (SWF 8): ceil.
     - `EmbeddedFontTest` `textWidth` (SWF 7, w1-rm-avm1-gnash request 2): ceil sum.
     - `morph_test1` (SWF 6): fractional.
   - The 7-vs-8 edge rests on the EmbeddedFontTest `textWidth` (a metric, not a render), so it is FLASH REQUEST 1.
     `SWF_TF_LOW_ADV_CEIL_MINVER=8` moves the edge. No corpus LOW row is SWF 7 with DF2 text, so the edge changes no
     ledger row.
   - **Corpus reach (scan of every downloaded suite):** only 5 LOW image rows carry a DefineFont2 with glyphs.
     `place_object_test` (SWF 5), `shape_test` (5) and `morph_test1` (6) are untouched; `BeginBitmapFill` (8) and
     `lowq_glyph_probe_df2` (8) move.
   - **Measured:**
     - `BeginBitmapFill` F894 → **F393**: toward the Flash golden, still over `max_outliers` 100.
     - df2 probe P52527 → **P12891**.
     - `morph_test1` ×6, `place_object_test` and `shape_test` are byte-identical.
     - The old all-versions leg (`SWF_TF_LOW_ADV_CEIL=1`) would have cost `morph_test1` 198 → 918 ×5, frame1
       P0 → F93, `place_object_test` +11 754 and `shape_test` +2 616. The version gate avoids all of it.
2. **GO: scope the field-local pen's Y half to em-1024 (DefineFont/DefineFont2) runs.**
   - **The finding:** I matched each word of `style_changes_in_html` against FP32 LOW LNX
     (`tools/words.py`, best integer dx/dy per word).
     - **x matches FP32 on every word under both rules.** So it is not HTML spans, TextFormat runs or the per-run pen
       origin.
     - **Only field 5's y is wrong: every word sits 1 px HIGH under the local rule** and is exact under the world
       rule.
     - Field 5 is the one field at a .5 y (placed at 68.5; fields 6 and 7 are at integer y, where the two rules
       agree). Its local baseline is 2 + 18540/20480 × 30 = 29.16. Local: half-even(68.5) = 68, + 29 = **97**.
       World: round(97.66) = **98** = FP32.
     - Leading is not the cause: field 5 is single-line, and the local baseline is the same in fields 6 and 7,
       which match.
   - **Against it:** the DF2 probe rows at field y 108.5 / 140.5 (24 / 36 px) need the LOCAL y (FP32 132 / 175,
       world 133 / 176).
   - **So the y rule splits by field kind.** The candidates are the font (DF3 + DefineFontAlignZones vs DF2) and HTML
     vs plain. No corpus row separates them, so this is FLASH REQUEST 2. I gated on the run's em square (1024 = DF1/DF2
     keeps the local y; DF3 takes the world y). x keeps the local rule everywhere, as the df3 'W' evidence requires.
     Kill switch: `SWF_TF_LOW_PEN_LOCAL_Y=1`.
   - **Measured vs FP32 LOW LNX (t0 / t16 / t64):**
     - **before** (master, w2-lowq-land pen rule): 24 390 / 5 252 / 2 626;
     - **after:** **23 208 / 2 888 / 1 444**;
     - w2-lowq-land's pre-pen baseline: 23 938 / 4 348 / 2 174;
     - the Ruffle golden: 24 446 / 5 802 / 2 901.
   - The row now sits **better than before the pen rule landed** (t16 −1 460 vs that baseline, −2 364 vs master).
     WIN is the same ±2. Against its (non-Flash) golden the row goes F4658 → F4002. It stays failing (tolerance 0).
3. **HOLD (not attempted): the LOW glyph chord rule** (brief item 3, optional).
   - The completion mechanism is unchanged from w2-lowq-land §1.3: a recompiler second chord tessellation per glyph
     in `swf.cpp` `font_glyph_entries` plus a runtime LOW identity-arm switch on `dev × scale ≤ 0.35–0.5 px`.
   - Now that the ceil is in, the df2 probe's remaining 12 891 is glyph raster plus the 48 px baseline, so it is the
     right row to price chords on.
   - It is a recompiler change with every-SWF reach, and it did not fit after items 1–2 and the gate.

## Per-test before / after (same box; before = leg M ≡ clean origin/master, after = the patch)

Outliers from `verify_output.compare_images` against each row's golden. P = pass.

| row | SWF | golden | before | after |
|---|---|---|---:|---:|
| `from_gnash/misc-ming.all/BeginBitmapFill` | 8 | Flash (s27) | F894 | **F393** |
| `regression/lowq_glyph_probe_df2` | 8 | FP32 LOW | P52527 | **P12891** (budget tightened to 12891) |
| `regression/lowq_glyph_probe_df3` | 8 | FP32 LOW | P9024 | P9024 |
| `text/style_changes_in_html` | 15 | Ruffle (FP32 capture: see verdict 2) | F4658 | **F4002** |
| `from_gnash/misc-ming.all/morph_test1` frame1 / 2–5 / 6 | 6 | FP32 (ff) | P0 / F198 / F198 | P0 / F198 / F198 (md5-same) |
| `from_gnash/misc-ming.all/place_object_test` | 5 | not Flash | F2604 | F2604 (md5-same) |
| `from_gnash/misc-ming.all/shape_test` | 5 | not Flash | F9709 | F9709 (md5-same) |

## EXPECTED-FLIP LEDGER (for the CI grading run)

**Image axis (graphics, `images=true`): no status flips.** Moves, with status unchanged:
- **toward Flash:**
  - `from_gnash/misc-ming.all/BeginBitmapFill` 894 → 393 (F);
  - `regression/lowq_glyph_probe_df2` 52527 → 12891 (P, budget now 12891);
  - `text/style_changes_in_html` 4658 → 4002 vs its golden (F; toward FP32 LOW by −2 364 channels at t16).
- **byte-identical:**
  - `morph_test1` frames 1–6 (frame1 stays PASS);
  - `place_object_test`, `shape_test`, `lowq_glyph_probe_df3`;
  - every other row of the 32-row LOW text gate (below).
- **HIGH:** preprocessor-dead. Both edits sit inside `MSAA_SAMPLES == 1` arms.

**Trace axis: no expected moves.** The change is render-only: `textfield_glyph_render_cb_impl` and
`tf_glyph_quarter_snap` LOW arm, graphics builds only. No metric (`textWidth`, autosize) path is touched.

**Mode:** graphics. Nothing in `swf_core.c`, `tag_stubs.c` or `NO_GRAPHICS` arms.

## Gates

- **Logical cover of the w2-lowq-land 148-row gate (+38 canary rows).**
  - Its pass-1/pass-2 legs T (ceil on, every SWF) and U (pen-local off) name every row each mechanism can move. T
    moved exactly {BeginBitmapFill, morph_test1, place_object_test, shape_test, df2}. Pen-local moved exactly {df2,
    df3, style_changes_in_html}.
  - My version gate is a subset of T. My y-scope is a partial revert of pen-local, so on the other rows it is a no-op
    (local == world there for every glyph).
  - All 8 rows were re-measured on this code (`gate_c1.txt`, `gate_c2.txt`).
- **32-row LOW text gate** (`gate_c3.txt`, M vs X md5):
  - the 74 LOW image rows NOT in the w2 gate, filtered to text-bearing ones (fonts/, captions, hardwrap,
    acid-chars, acid-text*);
  - plus every LOW `text/`, `edittext`, `fonts/` row and the canary's LOW text members.
  - Result: **32 rows / 49 comparisons: 48 md5-same, 1 moved = `BeginBitmapFill` F894 → F393** (on the ledger). 0 pass → fail.
- **Canary:**
  - The LOW text members `style_changes_in_html`, `BeginBitmapFill`, `morph_test1`, `place_object_test`,
    `lowq_glyph_probe_df3`, `text/auto_size/width`, `visual/fonts/device-font`, `edittext_scroll` and
    `text_field_mask` are all in the gates above. Only the first two move, both on the ledger.
  - The HIGH members are preprocessor-dead for both edits.
  - The existing members `BeginBitmapFill` (ceil) and `style_changes_in_html` (y scope) already see both change
    classes, so no member was appended.
- **`regression/`:**
  - The two glyph probes are in the gate (df2 moves, inside its budget; df3 is md5-same).
  - The LOW regression rows without text (`lowq_*_probe`, `layer_group_*`) cannot reach either edit (no glyph draw).
  - HIGH md5 A/B, clean master vs patch: `regression/avm1_edittext_wordwrap_render` and `avm1_long_text_layout` are identical (PASS 69/69 and 48/48).
  - `verify_output.py` on the patched tree: `lowq_glyph_probe_df2` PASS 12891/12891, `lowq_glyph_probe_df3` PASS 9024/9024.

## Functions touched (all `SWFModernRuntime/src/libswf/tag.c`, LOW-only)

- `textfield_glyph_render_cb_impl`: the ceil block now defaults on for `g_swf_version >= 7`. `SWF_TF_LOW_ADV_CEIL`
  = 0 / 1 forces it off / on; `SWF_TF_LOW_ADV_CEIL_MINVER` sets the edge. It also sets the new static
  `g_tf_low_pen_run_em = run_em` before `tf_glyph_quarter_snap`.
- `tf_glyph_quarter_snap`, LOW arm: the field-local y applies only when `g_tf_low_pen_run_em == 1024` (or
  `SWF_TF_LOW_PEN_LOCAL_Y=1`).
- The comment on `g_tf_low_adv_ceil_q` was updated.
- **Sibling note:** w2-rm-avm1-gnash-land owns the SmallText-flag plumbing (recompiler font case → runtime font
  record). Once it lands, AND the ceil gate with the SmallText bit if REQUEST 1 row r2 shows that SmallText-off fonts
  do not ceil. No LOW corpus row has a non-SmallText DF2 font, so this changes no ledger row.

## Refutations / premise attacks

- **"Find the field property that switches the rule (transform, script-set text, autoSize, line count, size vs em,
  capture frame)":** refuted as a class. BeginBitmapFill's and morph_test1's xtrace fields are byte-identical
  (bounds, flags, font, size, variable, initial text) and the sprite holding them differs only in translation. One
  ceils, one does not, so the switch is outside the field: the SWF version.
- **"The wrapper vs direct capture mode switches it":** refuted. BeginBitmapFill's FP32 check (s27) and morph_test1's
  (s27, s28) were both wrapper draw() captures.
- **"style_changes_in_html moves away through HTML spans / TextFormat runs / per-run pen origins":** refuted. x is
  exact per word under both rules, and the whole loss is field 5's y (a single line, so leading is not involved).

## New unclaimed leads

- **The 48 px df2 row's baseline** is still 1 px high under both y rules (field y 187.5, local 46.53). Request 2's
  data may explain it: DF2 rows there use 24 px only.
- **`textWidth` for SWF 7+ DF2 fonts** (w2-rm-avm1-gnash-land's EmbeddedFontTest rider): the render rule here and the
  metric rule there should share one gate (version + SmallText). Align them after both land.
- **LOW chords** (verdict 3).

## LOCAL ORACLE REQUESTS

1. **FLASH: `session30-fanout-reports/w2b-lowq-text-fixtures/swfver_ceil_probe/test_v5.swf`, `test_v6.swf`,
   `test_v7.swf`, `test_v8.swf`, image, tick 1, direct pinned, LNX (`--screen` or draw()).** Each SWF sets
   `_quality = "LOW"` itself; they are identical apart from the header version.
   - **Rows:**
     - r0: the probe field, font 1 (SmallText on);
     - r1: morph_test1's exact xtrace field, font 1;
     - r2 / r3: the same two fields with font 2 = the same font with the SmallText bit cleared.
   - **Compare** each row's ink starts with `ours_v8_patch.png` (ceil: r0 13, 21, 28, 36, 44, …) and
     `ours_v8_master.png` (fractional: 13, 20, 27, 34, 41, …).
   - **Answers:**
     - the version edge (is v7 ceil? v6 fractional?) → `SWF_TF_LOW_ADV_CEIL_MINVER`;
     - whether SmallText gates it (r2 / r3) → AND with the sibling's SmallText bit.
   - Rebuild with `python3 create_test_swf.py` (it reads the corpus place_object_test SWF).
2. **FLASH: `session30-fanout-reports/w2b-lowq-text-fixtures/ypen_scope_probe/test.swf`, image, tick 1, direct
   pinned, LNX.** Every field sits at an EVEN + 0.5 y, so on each row the local-rule baseline is 1 px above the world
   one.
   - **Rows:**
     - r0: DF3 + align zones, plain;
     - r1: the same, HTML;
     - r2: DF3 without align zones, plain;
     - r3: DF2, plain;
     - r4: DF2, HTML.
   - **Compare** each row's top / bottom ink rows with `ours_patch.png` and `ours_master.png`:
     - ours_patch ink bands: (13, 39), (53, 79), (93, 119), (130, 152), (170, 192);
     - master: the DF3 rows 1 px higher.
   - **The row(s) that take the world y name the property:**
     - font kind → the em gate is right;
     - HTML → switch the gate to `info->html`;
     - align zones → gate on the zones tag.
   - Rebuild with `python3 create_test_swf.py` (it reads place_object_test and text/style_changes_in_html).
