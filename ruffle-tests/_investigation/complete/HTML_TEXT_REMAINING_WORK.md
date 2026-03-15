# HTML Text Remaining Work

## Status: COMPLETE — All 10 tests PASS

| Test | Total Lines | Diff Lines | Status |
|------|-------------|------------|--------|
| `edittext_html_roundtrip` | 17 | 0 | **PASS** |
| `edittext_html_color` | 114 | 0 | **PASS** |
| `edittext_html_align_swf7` | — | 0 | **PASS** |
| `edittext_html_align_swf8` | — | 0 | **PASS** |
| `edittext_html_entity` | — | 0 | **PASS** |
| `edittext_html_swf7` | 5377 | 0 | **PASS** |
| `edittext_html_swf8` | 5377 | 0 | **PASS** |
| `edittext_html_swf6` | 5377 | 0 | **PASS** (was 5289/5377, fixed by SWF6 paragraph semantics — Blocker 2 resolved 2026-03-14) |
| `edittext_html_condensewhite_swf7` | 311 | 0 | **PASS** |
| `edittext_html_condensewhite_swf8` | 311 | 0 | **PASS** |

**History:**
- Initial broad `</font>` revert markers caused 55→133 regression (reverted). Surgical approach in `afb3880d` fixed 36 lines (55→19 for swf7, 125→107 for swf8) with no regressions.
- condenseWhite fix + serializer font marker carry-over: swf7 19→7, condensewhite_swf7 213→7, swf8 107→95.
- SWF8 batch fixes: color revert markers (6 lines), empty `<a>` preservation (18 lines), empty content font reset (14 lines), alignment with leading whitespace (6 lines). Total: swf8 47→3 (from CI baseline).
- SWF8 condenseWhite leading ws strip: `cw8_para_start` flag in `tf_parse_html` strips leading whitespace from text content at paragraph start for SWF8+. condensewhite_swf8 reduced from ~62 diffs to 24. No regressions on 9 passing HTML tests.

---

## ~~Part A: edittext_html_swf7~~ — PASS ✅

All diffs fixed (font size 0 clamping).

---

## ~~Part B: edittext_html_swf8~~ — PASS ✅

All diffs fixed (font size 0 clamping + SWF8 whitespace fixes).

---

## Part C: edittext_html_swf6 (~88 diff lines remaining) — MOSTLY FIXED

**Fixed (2026-03-12, commit 19e968ed):** SWF<=6 non-multiline text fields preserve tag-based paragraph breaks like multiline. Three `swf_version >= 7` gates added to `tf_serialize_html` and `tf_get_plain_text`. Improved from 3900/5377 (72%) to **5289/5377 (98.4%)** (+1389 lines).

**Remaining 88 lines:** Pre-existing HTML serialization issues unrelated to paragraph breaks:
- Trailing empty styled runs (e.g. `<B></B>`, `<FONT COLOR="#121212"></FONT>`) — expected output has them, our serializer omits empty runs
- Empty paragraph font/color defaults differ (expected: original font from tag, actual: text field's default font)
- `<!-- the same -->` lines that fail because the HTML get line itself is wrong (ml output differs from the wrong non-ml output)

---

## Part D: edittext_html_condensewhite — BLOCKED

### D2. Remaining condensewhite_swf7 diffs (4 lines)

Lines 236-238: Literal `\x01`/`\x02`/`\x03` control characters in input text are confused with internal paragraph break markers (`\x01` for tag breaks, `\x02` for `<br>` breaks).

**Blocker:** The HTML text engine uses in-band signaling (embedding `\x01`/`\x02` in the text buffer) for paragraph break positions. Literal occurrences of these bytes in input text collide with the sentinels. Fixing requires either:
1. A side-channel paragraph break position array (architectural refactor)
2. An escape/unescape mechanism for the sentinel bytes

Low impact (4 lines, edge case with control characters).

### D3. Remaining condensewhite_swf8 diffs (24 lines)

Three categories of remaining diffs:

**D3a. Trailing space after paragraph break in singleline (10 lines)**
Lines 85-88, 97-99, 145-147, 289-291. In SWF8 condenseWhite singleline, whitespace after `</p>`, `</li>`, `</b>` tag closes should produce a trailing space. Currently the whitespace-only text node is skipped (SWF7 behavior).

**D3b. Space between paragraphs in singleline (2 lines)**
Line 151-152. `<p>test</p>  <p>test</p>` → expected `test test ` but produces `testtest`. The inter-paragraph whitespace should collapse to a single space in singleline.

**D3c. Double space between inline tags (8 lines)**
Lines 301-304, 307-310. `<b> test1 </b> <b> test2 </b>` → expected `test1 test2 ` but produces `test1  test2 `. The trailing space from "test1 " and the skipped inter-tag whitespace produce a double space.

**D3d. Control character issue (4 lines, same as D2)**
Lines 236-238. Same `\x01`/`\x02` sentinel collision.

**Blocker:** These all require the singleline serializer/text getter to handle paragraph break markers as spaces — but the paragraph break markers are also used by the multiline serializer to create paragraph boundaries. The text buffer is shared between singleline and multiline rendering. Approaches attempted and rejected:
1. **Ws-only text node → space collapse**: Creates double/triple spaces when combined with adjacent content whitespace.
2. **Temporarily replace `\x01`/`\x02` with spaces in serializer**: Breaks empty paragraph handling (creates spurious content), loses LI/P type information, creates double spaces around breaks.
3. **Paragraph break → space in text getter only**: Would need matching serializer change to keep HTML and text output consistent.

A clean fix requires either:
- Per-mode rendering where paragraph break markers produce spaces in singleline and `\r` in multiline (both in serializer AND text getter), with proper consecutive-space collapsing
- Or a separate singleline text buffer generated during parsing

---

## Priority Order

1. ~~**A1-A5: All fixed**~~
2. ~~**D1: condenseWhite whitespace stripping**~~ — FIXED
3. ~~**B1-B4: SWF8-specific issues**~~ — ALL FIXED (47→3 mismatches)
4. ~~**A6/B5: Font size pop behavior**~~ — FIXED (font size 0 clamping)
5. ~~**D3 partial: SWF8 condenseWhite leading ws strip**~~ — FIXED (62→24 diffs)
6. **D2: condensewhite_swf7 control chars** (4 diff lines) — BLOCKED (sentinel collision)
7. **D3: condensewhite_swf8 remaining** (24 diff lines) — BLOCKED (paragraph break → space in singleline)
8. **C1-C3: SWF6 paragraph model** (~1478 diff lines) — BLOCKED (architectural)

## Regression Guard

Always verify these tests remain PASS after any change:
```bash
python3 ruffle-tests/verify_output.py --test=edittext_html_roundtrip --diff --verbose
python3 ruffle-tests/verify_output.py --test=edittext_html_color --diff --verbose
python3 ruffle-tests/verify_output.py --test=edittext_html_align_swf7 --diff --verbose
python3 ruffle-tests/verify_output.py --test=edittext_html_align_swf8 --diff --verbose
python3 ruffle-tests/verify_output.py --test=edittext_html_entity --diff --verbose
python3 ruffle-tests/verify_output.py --test=text_format --diff --verbose
```

## Out of Scope

These HTML text tests are **not** in scope for this work:
- `edittext_stylesheet` — Needs a CSS parser (StyleSheet class)
- `edittext_bullet` — Needs bullet width calculation for LI rendering metrics
