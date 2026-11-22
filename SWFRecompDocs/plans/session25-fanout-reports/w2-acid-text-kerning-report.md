# s25 wave 2: `w2-acid-text-kerning` (DefineFont2/3 kerning on the AVM1/timeline EditText path)

**NEW FILES:** this report, `w2-acid-text-kerning.patch`. No new source files and no new fixture dirs.
**Branch:** `fanout/w2-acid-text-kerning`. **Base:** `origin/master` `d08236ee`. **Upstream tests:** `download_tests.sh`
at Ruffle master `3ac8dcb07` (categories: avm1, avm2, from_gnash, from_shumway, text, fonts, visual; regression is in git).
**Box:** `SETUP_STATUS` all OK (apt, Pillow, Dawn on lavapipe).

## Verdict

**GO, +1 pixel: `from_shumway/acid/acid-text` `[output]` fail → pass** (3429 outliers / max 255 → **0 / 0** at tol 0).
Trace axis: **0 moves** (no graded trace row has a kern-pair font in a field that reads metrics; see §4).
A/B over 149 tests (113 canary + 36 kerning sweep), `--recompile`, graphics: **200/201 PNGs md5-identical**; the
only mover is `acid-text`. 0 trace-status changes.

**Fidelity proven before measuring:** my clean-`origin/master` render of `acid-text` is md5-identical
(`9c550f0d55a44c4b91df5b96b903f3a5`) to CI's actual PNG on `origin/ruffle-image-results`
(`images/from_shumway/acid/acid-text/output.actual.png`). Local grading of this row is therefore CI-grade, and 0/0
after is a CI-grade prediction. (The coordinator's exporter render could not settle this because it has no
`quality = "low"` option. That is not needed now.)

## EXPECTED-FLIP LEDGER (check CI against this)

| axis | test | before | after |
|---|---|---|---|
| pixel | `from_shumway/acid/acid-text` `[output]` | fail (3429 outliers, max 255, tol 0) | **pass (0, 0)** |
| trace | none | n/a | n/a |

Anything else that moves on CI is outside this ledger and is a regression (or upstream drift, if the expected file
changed).

## 1. Mechanism (owner `file:line`)

- `acid-text` has three DefineEditText HTML fields with `kerning="1"` (SWF 21). They use the DefineFont3 faces Tahoma
  (id 2, 674 pairs) and MetaBold-Roman (id 4, 1021 pairs). They render through the AVM1/timeline path
  (`tag.c textfield_glyph_render_cb`). Before the patch the recompiler skipped the kerning table
  (`swf.cpp`, "Skip any remaining data (bounds table, kerning, etc.)") and the render advance had no kerning term, so
  every glyph after a kern pair (`Wo`, `r d`, …) sat 2–3 px right. This patch also fixes field 3 (`Hello`/`World`,
  two `<p>`), which w1 had not attributed.
- Ruffle, the model: `font_like.rs:109-124` adds `get_kerning_offset(c, next)` to the glyph advance **before** scaling
  when `has_kerning_info() && (device || params.kerning)`. `params.kerning` is the span's `TextFormat.kerning`, which
  `text_format.rs:980` sets from `kerning="1"` only for SWF ≥ 8. Our `tf_parse_html` already applies the same SWF ≥ 8 gate
  to `TFRun.kerning`. `next` is peeked only inside one evaluated fragment. `html/layout.rs lay_out_span` splits on span
  edges, `\n` `\r` `\t` and wrap breakpoints, and `append_text` splits per word under justify.

## 2. Patch scope: every function touched

| file | function / symbol | change |
|---|---|---|
| `SWFRecomp/src/swf.cpp` | `SWF_TAG_DEFINE_FONT{,_2,_3}` case (block-local `kern_pairs`) | Parse bounds table and kerning table (UI8/UI16 codes, SI16 adj). Drop zero adjustments. Sort by `(left<<16)\|right`. Emit `static const s32 font_N_kerning[]` plus `tagDefineFontKerning(CHARID(N), …, count)` inside the existing font-metrics block. No header change. |
| `SWFModernRuntime/include/libswf/tag.h` | decls | `tagDefineFontKerning`, `ng_record_font_kerning`, `ng_font_kerning_by_idx` |
| `SWFModernRuntime/src/libswf/tag.c` | **new** `tagDefineFontKerning` (next to `tagDefineFontGlyphBase`, all-modes block) | thin wrapper |
| `SWFModernRuntime/src/libswf/tag.c` | **new** `static tf_kern_units` | Ruffle fragment rules: run must have `kerning`; next char in the same run; no `\n` `\r` `\t` or 0xFE/0xFF sentinel; no `' '` pair in justify. Returns EM-unit adjustment. |
| `SWFModernRuntime/src/libswf/tag.c` | `textfield_glyph_render_cb` | `adv += tf_kern_units(...)` before `tf_glyph_advance_twips` in 4 places: the paragraph-width measure pass (alignment), the caret auto-scroll walk, the selection walk, and the draw loop. Measure and draw agree. |
| `SWFModernRuntime/src/libswf/ng_shared.c` | `ng_fonts[]` struct (trailing `kern_pairs`, `kern_count`); **new** `ng_record_font_kerning`, `ng_font_kerning_by_idx` (binary search) | Table read in place from generated code, like `ext_codes`. |
| `SWFModernRuntime/include/actionmodern/action.h` | `TextFieldGlyphRun` (trailing `u8 kerning`) | Fits in existing struct padding. |
| `SWFModernRuntime/src/actionmodern/action.c` | run builders only (one line each): `tf_styled_runs_from_html` `FLUSH_RUN` (=0), `actionIterateTextFieldGlyphs` TFRunTable loop (`= r->kerning`), plus its two synthesized single runs (=0), orphan-field HTML run loop (`= r->kerning`) and its synthesized run (=0) | The run buffers are shared statics, so every builder sets the field (no stale values). |
| `ruffle-tests/render_canary_tests.txt` | EOF | Adds `from_shumway/acid/acid-text`. No standing member saw this change class. |

**Sibling overlap (`w1-textfield-vn`, `n-play-game`):** the `action.c` hunks are six single-line assignments next to
the existing `.font_id = 0` lines in the glyph-run builders. They do not touch TextField prototype or property code,
and do not touch button or mouse dispatch. `tag.c` hunks are confined to the font-registration block and
`textfield_glyph_render_cb`.
Not touched: `swf_core.c`, `tag_stubs.c`, `#ifdef NO_GRAPHICS` arms, `verify_output.py`, CMake, Emscripten lists
(no new TUs).

## 3. Before/after (same box, clean `origin/master` vs patch, `--mode=graphics --recompile`)

Headline: `from_shumway/acid/acid-text` before **3429 outliers, max 255** (md5 == CI actual); after **0 outliers, max 0**.

Canary (`render_canary.py capture/compare`, 113 standing members + 36 sweep rows, `-P 2`, `--timeout 5400`):
`IDENTICAL 200, DIFFERS 1 (acid-text), APPEARED/VANISHED/NO_RENDER 0`, trace status changes none.

Zero-headroom and tol-0 rows named in the brief, plus the kerning sweep (every corpus SWF in the downloaded categories
that mentions `kerning`, found by a decompress + DefineFont2/3 kerning-table scan; rows with real pairs **and**
`kerning="1"` are avm1 `asfunction` / `edittext_password` / `textfield_properties` / `textfield_text`, shumway `acid`,
`acid-text`, `acid-text-4`, `acid-text-escape`, `flash_text_TextField2`, text `links_in_scrolled_text` /
`style_changes_in_html`, visual `fonts/duplicate_font`):

| test | trace before → after | image before → after | PNG md5 |
|---|---|---|---|
| `from_shumway/acid/acid-text-escape` | pass → pass | output:pass → output:pass | identical |
| `text/style_changes_in_html` | pass → pass | output:pass → output:pass | identical |
| `from_shumway/avm1/text-bind` | pass → pass | output:pass → output:pass | identical |
| `fonts/embed_matching/fallback_preferences` | pass → pass | output:pass → output:pass | identical |
| `visual/edittext/edittext_border_filters` | pass → pass | output:pass → output:pass | identical |
| `from_shumway/acid/acid-textfield` | ruffle_matched → ruffle_matched | output:fail → output:fail | identical |
| `from_shumway/acid/acid-text` | pass → pass | output:fail → output:pass | DIFFERS |
| `from_shumway/acid/acid` | pass → pass | 18 cmps all pass → 18 cmps all pass | identical |
| `from_shumway/acid/acid-text-4` | pass → pass | output:fail → output:fail | identical |
| `from_shumway/acid/acid-text-5` | pass → pass | output:fail → output:fail | identical |
| `from_shumway/acid/acid-text-x` | ruffle_matched → ruffle_matched | output:pass → output:pass | identical |
| `from_shumway/acid/acid-textfield-scroll` | pass → pass | output:pass → output:pass | identical |
| `from_shumway/acid/acid-color-0` | pass → pass | output:fail → output:fail | identical |
| `from_shumway/flash_text_TextField2` | ruffle_matched → ruffle_matched | output:pass → output:pass | identical |
| `from_shumway/MaskTest-2` | pass → pass | output:fail → output:fail | identical |
| `from_shumway/hardwrap` | pass → pass | output:fail → output:fail | identical |
| `from_shumway/getobjectsunderpoint` | ruffle_matched → ruffle_matched | — → — | (no render) |
| `from_shumway/avm1/xml/xmlload` | pass → pass | — → — | (no render) |
| `text/links_in_scrolled_text` | pass → pass | — → — | (no render) |
| `text/auto_size/height` | pass → pass | output:pass → output:pass | identical |
| `text/auto_size/return` | pass → pass | output:pass → output:pass | identical |
| `visual/fonts/duplicate_font` | pass → pass | output:pass → output:pass | identical |
| `avm1/asfunction` | pass → pass | — → — | (no render) |
| `avm1/edittext_password` | pass → pass | — → — | (no render) |
| `avm1/textfield_properties` | pass → pass | — → — | (no render) |
| `avm1/textfield_text` | pass → pass | — → — | (no render) |
| `avm1/gettextextent` | pass → pass | — → — | (no render) |
| `avm1/device_font_spacing` | pass → pass | — → — | (no render) |
| `avm1/edittext_letter_spacing` | pass → pass | — → — | (no render) |
| `avm1/edittext_align` | pass → pass | — → — | (no render) |
| `avm1/edittext_bullet` | pass → pass | — → — | (no render) |
| `avm1/edittext_html_swf8` | pass → pass | — → — | (no render) |
| `avm1/edittext_html_entity` | pass → pass | — → — | (no render) |
| `avm1/edittext_margins` | pass → pass | — → — | (no render) |
| `avm1/edittext_newlines` | pass → pass | — → — | (no render) |
| `avm1/edittext_font_size` | pass → pass | — → — | (no render) |
| `avm1/edittext_leading` | pass → pass | — → — | (no render) |
| `avm1/edittext_underline` | pass → pass | — → — | (no render) |
| `avm1/edittext_tab_stops` | pass → pass | — → — | (no render) |
| `avm1/edittext_default_format` | pass → pass | — → — | (no render) |
| `avm1/tab_ordering_tabbable` | pass → pass | — → — | (no render) |
| `avm1/default_names` | pass → pass | — → — | (no render) |
| `avm1/nested_textfields_in_buttons` | pass → pass | — → — | (no render) |

Regression suite (`--tests-dir=ruffle-tests/tests/swfs/regression`, graphics, `--recompile`): `avm1_parent_child_text`
(image pass 0/0), `avm2_static_text`, `avm2_timeline_text`, `avm2_parent_child_static_text`: all PASS.
No-graphics sanity (trace, `--recompile`): `avm1/textfield_text`, `edittext_password`, `asfunction`: PASS. Not required
by mode parity, since nothing no-graphics-only was touched.

No new `regression/` fixture: the behaviour now has a tol-0 corpus row (`acid-text`) with an external (Flash) golden,
and it is in the canary.

## 4. Refutations / attacks on the brief

- **"Likely +1, unmeasured; field 3 unattributed"**: measured. All three fields are kerning; 0/0 at tol 0.
- **"Apply in layout AND render advance (or `textWidth`/`getCharBoundaries` diverge)"**: done for the render-side
  layout (alignment widths, caret, selection, draw). **HOLD on the trace-side measurement twins** (`ng_shared.c`
  `ng_computeTextWidth`, `ng_measure_substr_twips`, `ng_wrap_count_lines`, `ng_measure_substr_mixed_twips`,
  `ng_computeScrollMixedFont`, `ng_getCharIndexAtPointFont`). Evidence: these functions take a single
  font id + height and no run info. In the graded corpus (avm1, from_gnash, from_shumway, text, fonts, visual), **no
  trace row reads textWidth / textHeight / getCharBoundaries / getLineMetrics / getTextExtent on a field whose font has
  kern pairs**. `avm1/gettextextent` has 22 metric lines, but its font has a layout block with **0** kerning
  records. The other kern-pair rows (`asfunction`, `edittext_password`, `textfield_properties`, `textfield_text`,
  `links_in_scrolled_text`, …) print no metrics. A measurement change would therefore move nothing on CI and would have
  no oracle here. Wave-2 rules forbid shipping it unverified.
  **Completion mechanism:** add a module-level `ng_kerning_mode` set beside `setDeviceFontModeForMC` from the field's
  TFRunTable (any run with `kerning`), and add the same `tf_kern_units`-style term (same fragment rules) in those six
  loops. Price: S–M, ~40 LOC. Gate it on a `regression/` fixture: an AVM1 field with an embedded kern-pair font,
  `kerning=true`, tracing `textWidth` and `getCharBoundaries` across `AV`/`Wo`. Its expected output comes from the
  LOCAL ORACLE REQUEST below. Until then, a kerning=1 field's `textWidth` is the unkerned width (pre-existing
  behaviour, unchanged by this patch).
- **Device fonts:** Ruffle kerns device faces regardless of `params.kerning`. Our AVM1 device path has no kern table,
  so this is moot (as w1 said). Not changed.
- **`acid-text-escape` (tol 0, kern font, `kerning="1"`) stayed md5-identical**: its strings hit no pair (not a sign
  the term is inert; `acid-text` moved with the same code).

## New unclaimed leads

- The trace-side kerning twin above (HOLD, S–M, oracle-gated).
- Glyph runs carry no `letter_spacing` either (`TextFieldGlyphRun` has no field). The AVM1 render advance ignores
  per-run `letterSpacing`, while Ruffle adds it after scaling (`font_like.rs:126-137`). Not measured. Candidate rows:
  `avm1/edittext_letter_spacing` (trace-only here), and any graded AVM1 pixel row with `letterSpacing` ≠ 0 in its HTML.

## LOCAL ORACLE REQUESTS

1. (Only for the HOLD'd trace twin, non-blocking.) A Ruffle exporter **trace** of a new AVM1 fixture, which I could
   not author here (no MTASC/Flash in the cloud, and MTASC cannot embed fonts): an SWF 8+ with an embedded
   DefineFont3 that has a kerning table (e.g. reuse `from_shumway/acid/acid-text`'s Tahoma via a Flash-authored
   FLA), a dynamic field with `kerning=true`, text `"AVAWoWo"`, and traces of `textWidth`, `getCharBoundaries(i)` for
   each i, and the same with `kerning=false`. The coordinator can author it locally with Flash/JPEXS, or skip it.
