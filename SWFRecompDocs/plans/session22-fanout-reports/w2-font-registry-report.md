# w2-font-registry: embedded-font name registry + "embedded font missing → nothing" (session 22, wave 2)

**NEW files: none** (no new source files, no new fixture dirs). Deliverables: this report and
`w2-font-registry.patch` (= `git diff origin/master -- SWFRecomp SWFModernRuntime ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`;
it touches 6 existing files and has been checked with `git apply --check -R` against the branch head).

## 0. Verdict and expected flips

**GO, landed as a patch. +1 trace pass: `fonts/embed_name_lookup` (output_mismatch → pass, 242/242).**
I measured zero collateral movement:
- **Trace A/B over 100 rows** (clean `origin/master` `e412dd55f` vs the patch, same box, `--mode=graphics --recompile`):
  exactly 1 status change and 1 changed actual-output file, both `fonts/embed_name_lookup`. The other 99 actual outputs are byte-identical.
- **Pixel A/B over 83 rows / 111 PNGs**: the standing render canary plus every `fonts/*`, `text/*` and AVM1 `embedFonts` row that has an
  `[image_comparisons]` block. Result: **111/111 md5-IDENTICAL**, no trace status changes, no image status changes.
- **Mode parity**: the headline row also passes under no-graphics (`--recompile`). No `swf_core.c`, `tag_stubs.c` or
  `#ifdef NO_GRAPHICS` arm was touched.

### EXPECTED-FLIP LEDGER (what the coordinator should see on CI)

| axis | test | before → after |
|---|---|---|
| trace | `fonts/embed_name_lookup` | output_mismatch (86/242) → **pass** |
| trace | everything else | no change expected |
| pixel | (none) | no pixel row is expected to move. 111/111 identical locally on lavapipe |

CI mode: graphics `categories=full`. The headline row is in the `misc` group (`fonts`), which the classic `all` run does not include.

## 1. What changed (exact patch scope)

**Recompiler (`SWFRecomp/src/swf.cpp`, `SWFRecomp/include/tag.hpp`).** It now emits every embedded-font name event into `tagInit`, in tag order:

- **DefineFont2/3 own name**: unchanged. It is the existing `tagDefineFontInfo(id, name, bold, italic)` call, which now also registers the name.
- **DefineFontInfo (13) / DefineFontInfo2 (62, new enum `SWF_TAG_DEFINE_FONT_INFO_2`)**: emits `tagRegisterFontName(app_context, id, "name")`.
  - It is emitted only when the font id is already defined by a DefineFont/2/3 (`font_em_square.count(id)`), which is rule 4.
  - Previously the case skipped the tag body and DefineFontInfo2 fell to `default`.
- **ExportAssets**: after the existing `tagRegisterExport`, it emits `tagRegisterFontExport(app_context, "name", id, is_font)`.
  - It is emitted only when the id is already defined (`defined_chars` / `font_em_square`), which is rule 4.
  - `is_font = 0` for a non-font, which hides the name (rule 7).
  - `tagRegisterExport` itself is untouched, so attachMovie semantics are unchanged.
- **DefineFontName**: still emits nothing (rule 2).
- New static helper `escapeFontNameForC` escapes `\ " \n \r \t ?` for the emitted literals.

**Runtime (`SWFModernRuntime/src/libswf/ng_shared.c`, `tag.c`, `include/libswf/tag.h`).** The new block sits after `ng_findFontIdByName`, which is left as it was:

- **Name table**: `ng_font_names[256]`, keyed on case-insensitive (name, bold, italic). The first registration of a key wins (rule 5).
  - Style comes from the font's DefineFont2 flags (`ng_getFontBold/Italic`), never from FontInfo's flags (rule 8). Same as Ruffle `movie_clip.rs` `define_font_info`.
- **Export table**: `ng_font_exports[256]`, case-insensitive. A later export of a name replaces an earlier one.
- **`ng_findEmbeddedFontId(name, bold, italic, &id)`**:
  - Checks the export table first. A hit on a non-font returns "not found" (rules 6 and 7).
  - Then checks the name table, using Ruffle's `FontMap::find` style-fallback order (`library.rs:754`, tested upstream by `fonts/embed_matching/fallback_preferences`).
- **`ng_resolveTextFormatFontId(name, bold, italic)`** returns the registry hit or 0 (the builtin device font). It falls back to the legacy scan only if the name table overflowed.
- **`ng_register_swf_font`**, called from `tagDefineFontInfo`, records the own name and sets a 64 Kbit "defined by DefineFont2/3" bitmap.
  - The bitmap is independent of `MAX_FONTS_NG` (32), so a SWF with more than 31 fonts never trips rule 9 for its late fonts.
- **`ng_isSwfEmbeddedFont(id)`** reads that bitmap.

**AVM1 TextField (`SWFModernRuntime/src/actionmodern/action.c`).**
- The 4 TextField name→id sites now call `ng_resolveTextFormatFontId` with the format's bold/italic. Those sites are `tfRebuildFromHtml`, the htmlText sync in `actionSetMember`, `setTextFormat` and `setNewTextFormat`.
- `TextFormat.getTextExtent` (`:19091`) is deliberately left on the old lookup.
- **Rule 9** is a new static `tf_embedded_font_missing(mc, font_id)`: `embedFonts === true` and the resolved font is not a DefineFont2/3. It is applied in three places:
  - `computeTextFieldDimension`: `textWidth` / `textHeight` return 0.
  - `applyAutoSize`: zero text extent. This generalises the existing `font_id == 0 && ng_textfield_idx == -2` arm and keeps it.
  - `actionIterateTextFieldGlyphs`: draws no glyphs. Background and border are drawn by a separate walk and are unaffected.
- New static `tf_fmt_flag_set` reads `fmt.bold` / `fmt.italic` as boolean true.

**Not touched (sibling separation):** the zero-glyph device-font synth in `swf.cpp` (~2610), `abc_devicefont.cpp`, `avm2_text.c` and every AVM2 font path. AVM2 never calls any of the new functions.

## 2. Rule 9: checked against Ruffle and Flash before applying it

- **Ruffle does NOT implement rule 9.** `core/src/html/layout.rs` `resolve_font` (at `653ef4f41`) leaves it as a TODO: *"If set to use embedded fonts and we couldn't find any matching font, show nothing. However … we don't support DefineFont4."* Ruffle falls back to a device font instead.
  - Ruffle's test harness passes `embed_name_lookup` only because it has no device fonts loaded.
  - So there is no Ruffle-vs-Flash conflict on this row: both expected files say 0.
- **Flash does implement rule 9**, in both measure and draw:
  - Measure: `embed_name_lookup`'s `output.txt` has 63 rows of `textWidth 0` for absent or unusable fonts.
  - Draw: `fonts/embed_matching/no_font_found`'s Flash golden `output.expected.png` is a single colour (220000 px of white) for four `embedFonts = true` fields naming an absent font. Ruffle's `output.ruffle.png` has 7526 black text pixels, and its `test.toml` marks the image as `known_failure`, *"we intentionally fall back"*.
  - That row is AVM2 and out of my scope (see §6).
- **Corpus exposure:**
  - Every AVM1 row whose source sets `embedFonts` is in the A/B: 8 avm1 rows, `text/*`, `fonts/*`, and the AVM1 `visual/edittext/*` and `visual/fonts/*` rows.
  - So are all 49 `avm1/edittext_*` rows, the gnash `TextField*`, `TextFormat*` and `*EditText*` rows, `misc-mtasc TextFieldTest`, `misc-swfc edittext_test1`, and 6 text-adjacent `regression/` rows.
  - None of them moved on either axis. The only rows where rule 9 decides an observable value are inside `embed_name_lookup`.
- **Game risk, and how it is bounded:**
  - Rule 9 fires only when an AVM1 field has `embedFonts === true` (set by a script, or the DefineEditText UseOutlines flag) **and** its resolved font id is not a DefineFont2/3 the SWF defined.
  - DefineEditText fields keep their static font id: `font_id == 0 → ng_getTextFieldFontId` runs first, as before. So authored embedded-font fields are unaffected.
  - What goes blank is exactly the Flash-blank case: a script-assigned `TextFormat.font` that names no embedded font, or a `createTextField` default with `embedFonts = true`. Today we paint those with Noto Sans.
  - Fonts brought in by ImportAssets register through the imported SWF's own `tagInit` (`tagDefineFontInfo`), so they are found.

## 3. Per-test before/after (same box, clean `origin/master` `e412dd55f` vs patch, graphics, `--recompile`)

| test | before | after |
|---|---|---|
| **fonts/embed_name_lookup** | output_mismatch 86/242 | **pass** |
| fonts/embed_name_lookup (no-graphics) | — | pass |
| avm1/edittext_* (49 rows) | 47 pass, `edittext_onscroller` ruffle_matched, `edittext_html_duplicate_attributes` mismatch | identical (byte-equal actual output) |
| avm1 clone_sprite_edittext{,_dynamic}, textfield_props_swf8 | pass | identical |
| fonts/* (other 8: device_font_{glyph_fallback,kerning,list,name_case,no_ink}, embed_matching/{fallback_preferences,match_style,no_font_found}) | `device_font_name_case` mismatch; `device_font_no_ink` ruffle_matched; the rest pass | identical |
| text/* (11) | pass | identical |
| gnash TextField-v5 / v6 / v7 / v8 | ruffle_matched / mismatch / mismatch / mismatch | identical |
| gnash TextFormat-v5..v8, TextFieldHTML-v5..v8, DefineEditTextTest / VariableNameTest{,2}, edittext_test1 (13 rows) | pass, or ruffle_matched for TextFormat-v7/v8 | identical |
| misc-mtasc TextFieldTest | ruffle_matched | identical |
| visual AVM1 embedFonts rows (border_transform, small_rotation, small_shear, advance_u16, leading_define_font) | pass | identical |
| regression: avm1_parent_child_text, avm1_parent_child_render, avm2_parent_child_static_text, avm2_static_text, avm2_timeline_text, avm2_bitmapdata_draw_textfield | pass | pass, identical |

**Fails that are not mine:**
- `avm1/edittext_html_duplicate_attributes` and `fonts/device_font_name_case` are **upstream drift**: both test dirs are `A` (newly added) in `wave0-upstream-drift-namestatus.txt` and absent from the CI board. They fail identically before and after.
- gnash `TextField-v6..v8` are ACC/KF board rows.

## 4. Canary

`render_canary.py capture before/after --tests <standing set + 11 font/text image rows> --recompile` → `compare`:
**83 tests / 111 comparisons: IDENTICAL 111, DIFFERS 0, APPEARED 0, VANISHED 0. No TRACE or IMAGE status changes.**

The 11 rows added for this run are not appended to `render_canary_tests.txt`:
- `avm1/edittext_stylesheet`
- `fonts/device_font_no_ink`
- `fonts/embed_matching/{fallback_preferences,match_style,no_font_found}`
- `text/auto_size/{height,return}`
- `text/br_at_start`
- `text/style_changes_in_html`
- `visual/fonts/{advance_u16,leading_define_font}`

The 10 `from_shumway` "runner exit != 0" rows are the same in both legs.

**Canary coverage gap (honest).** No corpus *pixel* row exercises the AVM1 rule-9 draw skip: nothing moved, and no AVM1 image row has an `embedFonts` field naming an absent font. The draw arm is therefore verified only by construction, plus Flash's AVM2 golden (§2). A covering canary member needs an oracle from outside SWFRecomp. Ruffle can't serve, because it deliberately falls back. See LOCAL ORACLE REQUESTS.

## 5. Refutations / premise checks

- The brief's "29 calls for 38 fonts" is right in kind. The 8 DefineFont v1 fonts (ids 1, 6, 7, 8, 15, 18, 37, 38) never get a `tagDefineFontInfo`. With this patch they get FontInfo names but are still not DefineFont2/3, so rule 9 sends them to 0. That matches Flash (AH, AJ, AK, BB, BC, BP, CZ = 0).
  - This is the "v1 has no advances" case and needs no special handling.
- **Rule 7 premise check:** "export of a non-font" (CU) is the export of a **DefineShape2** id 34 that *is* defined before the export. A walker that lists only font tags misses it and could misread CU as an export of an undefined id, which would contradict rule 4.
- **Legacy-lookup trap:** my first draft fell back to the old `ng_findFontIdByName` after a registry miss. That re-found font 33 'CU' behind the export hide. Removing that fallback (it is kept only for registry overflow) was what took the row from 239/242 to 242/242.

## 6. New unclaimed leads

1. **AVM2 rule 9.** `fonts/embed_matching/no_font_found` has a Flash golden that is blank. Our AVM2 path (`avm2_text.c` device lookup, sibling `w2-default-fonts-draw` territory) presumably paints the fallback.
   - `ng_findEmbeddedFontId` + `ng_isSwfEmbeddedFont` are ready to reuse there. The `[image_comparisons]` is `known_failure` for Ruffle, so a pass would be pixel yield.
2. **AVM2 style matching.** `fonts/embed_matching/{match_style,fallback_preferences}` test Ruffle's style-fallback order, which `ng_findEmbeddedFontId` now implements. Check whether the AVM2 lookup honours it.
3. **`MAX_FONTS_NG = 32`** silently drops the 32nd and later fonts' metrics. Rule 9 is insulated by the bitmap, but measuring and drawing those fonts still falls to the builtin. Bump it (each slot is ~3 KB) if a game shows it.
4. **`tagRegisterExport`** emits the export name unescaped, so a `"` or `\` in an export name breaks the generated C. `escapeFontNameForC` is available.
5. **`TextFormat.getTextExtent`** (`action.c:19091`) still uses the one-name-per-font lookup and ignores export/style rules. Flash's getTextExtent measures device text unless the font is embedded, so it was left alone pending a fixture.

## 7. Anything not finished

Nothing in scope is left. The one open item is the draw-arm pixel fixture, which needs a Flash oracle; its completion mechanism is the local oracle request below.

Upstream test corpus: `download_tests.sh` (prints no SHA) was run 2026-10-17 against upstream master. The Ruffle source clone taken the same hour is at `653ef4f41`.

## LOCAL ORACLE REQUESTS

1. (Optional, only to add a pixel canary for the AVM1 draw arm.) A Flash Player (not Ruffle) render of a 1-frame AS2 SWF:
   - `createTextField("t", 1, 10, 10, 200, 40); t.embedFonts = true; t.setNewTextFormat(new TextFormat("NoSuchFont", 20)); t.text = "abc";`
   - plus a second field with `embedFonts = false` as an ink control.
   - Expected under rule 9: field 1 blank, field 2 inked.
   - The Ruffle exporter cannot serve, because Ruffle deliberately falls back (`layout.rs` TODO).
   - If no Flash render is available, skip this: the trace row and the AVM2 Flash golden already pin the rule.
