# s27 w1-text-wordwrap: AVM1 soft wrap in the native painter

**New files** (all under `session27-fanout-reports/`):
- `w1-text-wordwrap-report.md` (this report)
- `w1-text-wordwrap-prototype.patch` (`git diff origin/master -- SWFModernRuntime SWFRecomp`; source reverted)
- `w1-text-wordwrap-fixtures/avm1_edittext_wordwrap_render/` (HELD fixture): `create_test_swf.py`, `test.toml`,
  `output.ours.txt`, `output.ours-prototype.png`, `output.ours-master.png`. `test.swf` is not committed; run the generator.

**Setup.** Base `origin/master` `ae7f50cb1`. Baseline: the s26 record `df7729df2`, because wave-0's images run had not
published when I started. Box: Dawn and apt OK (lavapipe). Corpus: `download_tests.sh avm1 avm2 visual text fonts
from_shumway from_gnash` (upstream master on 2026-11-24, about 01:00 UTC). Ruffle source: a blobless clone at
`1e604fa87`.

**Fidelity.** On `from_shumway/hardwrap`, my *before* render is byte-identical to CI's actual PNG on
`origin/ruffle-image-results` (`8d824305…`), so local grading is CI-grade for this family.

## Verdicts

| # | Item | Verdict | Priced flips |
|---|---|---|---|
| 1 | "The native renderer never soft-wraps `wordWrap` fields; possibly a large family (M–L)" | **Premise half-REFUTED.** Only the **AVM1** painter (`tag.c textfield_glyph_render_cb`) lacks soft wrap. The AVM2 painter has always wrapped: `avm2_text.c` lays out with a Ruffle port of `lay_out_span` / `wrap_line` (`avm2_text.c:3699`, `wrap_line` at `:3586`). | — |
| 2 | Price of the family | **0 pixel flips; family is EMPTY on the graded corpus.** 430 graded tests were scanned. 11 graded **AVM1** rows hold a `wordWrap` field. In the prototype only **one** of those fields ever produces a soft break (gnash `Video-EmbedSquareTest`'s xtrace log, 1 break), and that row's final PNG is md5-identical. | **0** |
| 3 | F/G rows named in the brief (`hardwrap`, `captions`, `stylesheet`, `flash_text_TextField`, `acid-textfield`, `acid-text-4/5`) | **Wrap share = 0 for every row.** All are **AS3** SWFs, so they use the AVM2 painter, which already wraps. The device-font four are ACCEPTED (s26 `w1-pixel-tail`: platform device fonts; Ruffle draws them blank too). `stylesheet` and `acid-text-5` have no wordWrap field at all. The `acid-textfield` / `acid-text-4` line layout already matches the golden, so the residual there is glyph AA, which belongs to the sibling `w1-text-glyph-fidelity`. | 0 |
| 4 | Prototype: soft wrap in the AVM1 painter | **GO as a correctness fix (S), not as yield.** It is measured at 0 movement on every affected graded row (md5) and it fixes the new HELD fixture (master draws 1 clipped line per paragraph while the trace metrics already say 2–3 lines). **HOLD on landing until** the fixture has an exporter golden (LOCAL ORACLE REQUEST below). | 0 corpus; +1 held fixture |
| 5 | A Flash rule the wrap needs: whole-line culling | **Found and prototyped (scoped).** A wrap without it regresses `avm1/edittext_tag_indent` (pass → FAIL 1044) on a **Flash** golden. Ruffle's `edit_text.rs:1241` documents the FP rule: *"FP always displays the first visible line ... culls any other line which is not fully visible"*. Ruffle does not implement it, which is why that test is `known_failure`. With the culling the row is md5-identical to master. | keeps 1 pass |

**Owner of the gap:** `SWFModernRuntime/src/libswf/tag.c` `textfield_glyph_render_cb`. Its measure pass and its draw
pass both split only at `\n`, `\r`, 0xFE and 0xFF. `TextFieldGlyphInfo` (`action.h:963`) carried no wrap input. The
trace side already wraps (`ng_shared.c ng_wrap_count_lines`, `ng_computeScrollMixedFont`), so before this prototype
the render and the metrics disagreed for every wrapped AVM1 field (see the fixture).

**Why the corpus can't see it.** An AVM1 graded field whose text overflows its width almost never exists. The Ruffle
AVM1 rows with wordWrap fields hold short text (`abcdabcd`, `SUCCESS`, `Updated text`). Gnash's xtrace fields are
804 px wide. The long-text wrap rows (`text/auto_size/*`, `fonts/glyph`, the shumway acid rows) are all AS3. The real
consumers are AVM1 **games**: dialogue boxes, help screens and credits, which the N/browser lane sees and CI does not.

## Pricing evidence

**Scan.** I parsed every SWF of every graded image row (430 tests, all `image_results_graphics.json`, nested suites
included). A row is a candidate when it has a DefineEditText with WordWrap, or the string `wordWrap` anywhere in its
tags. For each candidate I read the FileAttributes AS3 bit.
- **AS3 (AVM2 painter; already wraps), 19 rows:** `avm2/{edittext_tag_indent, edittext_autosize_align,
  edittext_autosize_height_dynamic, edittext_autosize_lazy_bounds_visual, edittext_get_char_index_at_point}`,
  `from_shumway/{MaskTest-2, acid/acid, acid/acid-text, acid/acid-text-4, acid/acid-textfield, captions,
  flash_text_TextField, flash_text_TextField2, hardwrap}`, `text/auto_size/{height, return, width}`,
  `visual/fonts/glyph`, `visual/edittext/edittext_justify`.
- **AVM1 (`tag.c` painter), 11 rows:** `avm1/edittext_tag_indent`, `from_gnash/misc-ming.all/{BeginBitmapFill,
  Video-EmbedSquareTest, morph_test1, place_object_test, shape_test}`, `from_shumway/avm1/text-bind`,
  `text/{br_at_start, style_changes_in_html}`, `visual/cache_as_bitmap/text`, `visual/edittext/edittext_negative_bounds`
  (SWF 43, no AS3 bit).
- **Which fields break.** An instrumented prototype logged every wordWrap field that reached the painter, with its
  break count. Across all 24 candidates of the first sweep, only `Video-EmbedSquareTest`'s xtrace (204 px, SWF7,
  74 chars) produced a break. `edittext_tag_indent` also breaks once Ruffle's SWF8 `Some(1)` rule is in place (see
  item 5). No AS3 field ever reached the painter, which confirms the AS3 rows by construction too.

**F/G excess attribution.** This is CI's outlier count and how much of it the missing wrap explains.

| row | CI outliers | AS3 | wordWrap field | wrap share | the excess is |
|---|---|---|---|---|---|
| `hardwrap` | 3099 | yes | yes (40 px, `_sans` 0 glyphs) | 0 | blank device glyphs (ACCEPTED). Ruffle wraps it per char; our AVM2 layout does the same, but nothing draws |
| `captions` | 6528 | yes | AS only | 0 | blank device glyphs (ACCEPTED) |
| `stylesheet` | 2089 | yes | none | 0 | device font (ACCEPTED) |
| `flash_text_TextField` | 966 | yes | AS only | 0 | blank device glyphs (ACCEPTED) |
| `acid-textfield` | 15754 | yes | yes | 0 | each line is its own `<p>`, the layout matches the golden, and the residual is glyph AA (sibling) |
| `acid-text-4` | 51678 | yes | `wordWrap` in AS | 0 | the layout matches visually (side-by-side), and the residual is glyph AA (sibling) |
| `acid-text-5` | 422241 | yes | none | 0 | not wrap |

## Prototype (`w1-text-wordwrap-prototype.patch`, 430 lines)

The prototype is self-localized. It adds one trailing struct field and one new static helper, plus guarded hooks in
the painter. Nothing changes inside the glyph emit arithmetic.

- **`action.h`:** `TextFieldGlyphInfo` gets a trailing `int word_wrap`.
- **`action.c`:** `actionIterateTextFieldGlyphs` sets it from the `wordWrap` property, the same read the metric path
  uses. The orphan builder (the `TextFieldGlyphInfo info = {0}` site) sets it from DefineEditText flag `0x0001`.
- **`tag.c`, new statics** `tf_ww_sum`, `tf_ww_wrap_line` and `tf_soft_wrap_breaks`. Together they port Ruffle's
  `lay_out_span` word-wrap loop, `wrap_dimensions`, `wrap_line` and `find_allowed_breaks`:
  - SWF8 breaks after space runs and after `-`. SWF7 breaks at every space and on both sides of `-`.
  - Trailing spaces are trimmed for measurement.
  - A first word wider than the field breaks at its last fitting char (SWF8: at least 1; SWF7: give up when at most
    1 char fits). The SWF8 rule `remaining < 0` gives `Some(1)`.
  - Spans are the run table's runs.
  - Widths: `w*20 - 80 - right_margin`. The offset is the left margin, plus the indent on the first line only, plus
    720 for a bullet, plus the pen x.
  - `measure` is the painter's own `tf_glyph_advance_twips` plus kerning, per run face and size.
  - The output is the byte offsets where a soft line starts. Not ported: the CJK break rule, and tab stops inside a
    wrapped line.
- **`tag.c`, in `textfield_glyph_render_cb`:**
  - **Measure pass:** a soft break closes the paragraph record without consuming a char.
  - **New `TfParagraph` fields:** `cont` (a continuation line takes no first-line indent), `soft_end` and `trail_w`.
    For SWF8 and non-left alignment, a soft-ended line aligns without its trailing spaces (Ruffle `fixup_line`
    `trim_end`). I applied that to soft-ended lines only, so hard lines stay byte-identical.
  - **Draw pass:** a soft break performs the newline advance.
  - **Caret and selection:** their single-line paths now treat a soft-wrapped field as multi-line.
  - **Flash whole-line culling for soft-wrapped fields (`sb_n > 0`):** any line after the first visible one is
    skipped when `k*pitch + ascent + descent > h - 2*GUTTER`.
- **Equivalence.** When `sb_n == 0`, every changed expression reduces to the old one (`lo = first_line_left_off`,
  `ulw = usable_line_width`, `pw = width`, `cull_from = INT_MAX`). Fields with no soft break therefore render
  byte-identically by construction.
- **Touched functions** (for the N-ladder session): `tag.c textfield_glyph_render_cb` (hooks only),
  `action.c actionIterateTextFieldGlyphs`, and the orphan `TextFieldGlyphInfo` builder (just above `otf_walk_dl`).

### Per-row before/after (`--mode=graphics`; before = clean `origin/master`, after = final prototype)

| row | before | after | PNG md5 |
|---|---|---|---|
| avm1/edittext_tag_indent | pass 0 | pass 0 | identical (`0779fdf4…`) |
| from_gnash/misc-ming.all/Video-EmbedSquareTest | fail 1782 | fail 1782 | identical (`fb80304c…`) |
| from_gnash/misc-ming.all/{BeginBitmapFill 939, place_object_test 38238, shape_test 15994} | fail | fail, same | identical |
| from_gnash/misc-ming.all/morph_test1 (6 frames) | pass | pass | 6/6 identical |
| from_shumway/avm1/text-bind | pass 587/600 | same | identical |
| text/br_at_start, text/style_changes_in_html | pass | pass | identical |
| visual/cache_as_bitmap/text | pass 1257/1500 | same | identical |
| visual/edittext/edittext_negative_bounds | pass 0 | pass 0 | identical |
| 19 AS3 candidate rows | — | same outlier counts as CI baseline | n/a: the painter is never reached (instrumented log) |
| **held fixture** `avm1_edittext_wordwrap_render` | 1 clipped line per paragraph (`output.ours-master.png`) | wrapped 2/2/3/2/3 lines (`output.ours-prototype.png`); the render now agrees with its own `bottomScroll` trace | moved (intended) |

How the legs ran:
- The full before/after md5 table was taken on the instrumented build. The instrumentation is a `getenv`-gated file
  log, inactive in the after leg.
- The final patch (culling plus caret gating) was re-run on `edittext_tag_indent`, `Video-EmbedSquareTest` and the
  fixture: md5 identical to before, and the fixture is pixel-identical to the pre-culling after.
- The intermediate "give-up" variant (Flash gives up when the indent exceeds the width) was **refuted** by the AVM2
  twin (item 5) and dropped.

### Render canary

- 153 canary members. Only 10 have a wordWrap-capable field: `avm1/edittext_tag_indent`, `text/auto_size/width`,
  `avm2/edittext_autosize_height_dynamic`, `visual/cache_as_bitmap/text`, `from_shumway/avm1/text-bind`,
  `from_shumway/acid/acid-textfield`, `text/style_changes_in_html`, `text/br_at_start`, `from_shumway/acid/acid-text`
  and `from_gnash/misc-ming.all/morph_test1`.
- All 10 are in the per-row sweep above: AVM1 members are md5-identical, AS3 members never reach the painter.
- The other 143 contain no wordWrap field, so the patch is the identity on them by construction (`word_wrap = 0`
  gives `sb_n = 0`).
- I did not run a full 153-row capture. A wave-2 lander should run `render_canary.py` on the final diff.

### Trace axis

- The patch writes one new struct field and changes only the painter.
- A trace-only row has no `[image_comparisons]`, so it never defines `HEADLESS_RENDER_ENABLED` and never runs the
  painter.
- Sanity rows with the patch, all unchanged from baseline:
  - `regression/avm1_wrap_giveup_mixed_runs`: pass
  - `regression/avm1_long_text_layout`: pass, image 0
  - `avm1/edittext_scroll`: pass, and also pass in **no-graphics** (`action.c` compiles in both modes)
  - `avm1/edittext_margins`: pass
  - `from_gnash/misc-swfc.all/edittext_test1`: pass
  - `from_gnash/actionscript.all/TextField-v8`: `ruffle_matched` = baseline
- The fixture's trace (`textHeight`, `bottomScroll`) comes from `ng_wrap_count_lines`. A hand trace of Ruffle's
  `wrap_line` gives the same per-field break count:
  - field content = 1120 twips, 100 twips per glyph
  - `w`/`c`: break after `"AA AAA AAAA "`
  - `i`: indent 400 + margin 100, then 2 breaks
  - `l`: 11 chars, then 9
  - `h`: one hard break and one soft break after `-`

## Refutations / premise attacks

- **"Never soft-wraps" was true of the AVM1 painter only.** Every long-text wrap row in the graded corpus is AS3 and
  already wraps (`avm2_text.c`). The brief's F/G list is all AS3.
- **"Possibly a large family (M–L)" is refuted.** It prices at 0 flips. The work itself is S: a self-contained helper,
  since `ng_shared.c`'s metric wrap could not be reused as-is (it counts lines and emits no positions).
- **My own intermediate claim, "Flash gives up wrapping when the indent exceeds the width", is refuted.** The AVM2
  twin `avm2/edittext_tag_indent` (field 44.5 px tall, not `known_failure`) shows line 2 drawn exactly where Ruffle's
  `Some(1)` puts it. The AVM1 golden (field 40 px) hides it because line 2 does not fully fit. That is the Flash
  culling rule, not a wrap rule.
- **Do not treat the trace metrics as a free "render from the layout the metrics use".** `ng_wrap_count_lines` returns
  counts and widths only, and its offsets differ (it clamps `cur_avail` to 0 instead of Ruffle's `remaining < 0`
  early-out). A shared break iterator is the phase-2 cleanup, not the first step.

## Phase plan (only if the coordinator wants the correctness fix landed)

1. **Phase 1 (S, prototyped here).**
   - Land the patch plus the fixture into `regression/` once the exporter golden arrives.
   - Lander checklist: full render-canary capture/compare; regression suite; graphics `--mode` on the 11 AVM1 rows.
     Expected flips: none in the corpus, plus the fixture (a new row).
2. **Phase 2 (M).**
   - Extend Flash whole-line culling to ALL multi-line AVM1 fields (today: soft-wrapped only).
   - It needs a sweep of every AVM1 image row with a multi-line field whose last line is partial. Ruffle-made goldens
     show the partial line, so this must be graded against Flash goldens only.
   - Same phase: share one break iterator between `ng_wrap_count_lines` and the painter, so render and metrics cannot
     drift. The CJK break rule (`swf_is_cjk_like` / opening / closing) goes in here.
3. **Phase 3 (S).** The SWF8 trailing-space trim for hard lines in centred or right-aligned fields (Ruffle applies it
   to every line).

## New unclaimed leads

- **Flash whole-line culling for all AVM1 multi-line fields.** Ruffle documents the FP rule (`edit_text.rs:1241`) but
  only culls lines whose top lies below the box. We cull nothing (mask only). This is the likely Flash-side cause of
  other `known_failure` text rows. Price: sweep only.
- **AVM2 twin of the culling:** `avm2_text.c` and `avm2_display.c` follow Ruffle (no FP culling). It is unpriced;
  check AS3 rows whose Flash golden lacks a partial bottom line.
- **Metric twin:** `ng_wrap_count_lines` clamps `cur_avail` to 0 when indent > width (char-level fallback) instead of
  Ruffle's `remaining < 0` → `Some(1)` (SWF8) or `None` (SWF7). `maxscroll` / `bottomScroll` / `textHeight` for that
  case are unverified against an oracle.
- **RvF candidate:** `avm1/edittext_tag_indent` is a Ruffle-vs-Flash culling difference (the Flash golden is right).
  No entry exists in `RUFFLE_VS_FLASH_DIFFERENCES.md` (`known_failure` upstream). Write one when phase 2 lands.

## LOCAL ORACLE REQUESTS

1. **Fixture `w1-text-wordwrap-fixtures/avm1_edittext_wordwrap_render`.**
   - Build: `python3 create_test_swf.py test.swf` (SWF8, 220x150, 1 frame, embedded square-glyph DefineFont2).
   - Run: `exporter -s -f 1 --trace-log out.txt test.swf out.png`.
   - Need: `out.txt` (5 lines `w/c/i/l/h: maxscroll=… bottomScroll=… textHeight=…`) and `out.png`.
   - Compare against `output.ours.txt` / `output.ours-prototype.png`. Every line of the fixture fully fits its field,
     so Ruffle's conservative culling and Flash's agree, and the exporter is a valid oracle here.
   - If both match, wave 2 lands the prototype plus this fixture with `output.expected.png = out.png`.
