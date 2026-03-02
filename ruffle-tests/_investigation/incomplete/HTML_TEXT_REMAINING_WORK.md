# HTML Text Remaining Work

## Status Summary

| Test | Total Lines | Diff Lines | Status |
|------|-------------|------------|--------|
| `edittext_html_roundtrip` | 17 | 0 | PASS |
| `edittext_html_color` | 114 | 0 | PASS |
| `edittext_html_align_swf7` | — | 0 | PASS |
| `edittext_html_align_swf8` | — | 0 | PASS |
| `edittext_html_entity` | — | 0 | PASS |
| `edittext_html_swf7` | 5377 | 7 | 99.9% match |
| `edittext_html_swf8` | 5377 | 95 | 98.2% match |
| `edittext_html_swf6` | 5377 | 2955 | 45% match |
| `edittext_html_condensewhite_swf7` | 311 | 7 | 97.7% match |
| `edittext_html_condensewhite_swf8` | 311 | 269 | 14% match |

**History:**
- Initial broad `</font>` revert markers caused 55→133 regression (reverted). Surgical approach in `afb3880d` fixed 36 lines (55→19 for swf7, 125→107 for swf8) with no regressions.
- condenseWhite fix + serializer font marker carry-over: swf7 19→7, condensewhite_swf7 213→7, swf8 107→95.

---

## Part A: edittext_html_swf7 (7 diff lines remaining)

The 7 remaining diffs are all A6 (font size pop behavior), appearing 3 times (one per test section).

### ~~A1. Trailing color revert marker carry-over across paragraphs (6 diff lines)~~ — FIXED

**Fixed by adding `prev_para_marker` carry-over in `tf_serialize_html()`.** When a paragraph ends with a zero-length font marker, it's saved and re-emitted in subsequent paragraphs that don't have their own marker. Also fixed 12 bonus diff lines in swf8.

### ~~A2. Trailing color revert marker in `</li>` paragraphs (6 diff lines)~~ — FIXED

**Fixed in `afb3880d`.** Added `</font>` color revert markers for non-empty fonts that changed color inside LI paragraphs. Uses `para_type=2` flag to bypass the serializer's LI boundary skip logic. Parser creates zero-length marker with parent scope's color; serializer already handles zero-length font markers.

### ~~A3. Alignment inheritance after `</li>` auto-close (3 diff lines)~~ — FIXED

**Fixed in `afb3880d`.** Added `saved_p_align` variable. When `<li>` auto-closes a `<p>`, the P's alignment is saved before popping. The saved alignment is applied to post-LI `</p>` break runs in both the matching-P/!in_paragraph path and the unmatched `</p>` path.

### ~~A4. Color leak from `</li>` to subsequent `</p>` paragraph (3 diff lines)~~ — FIXED

**Fixed in `afb3880d`.** Post-LI `</p>` break runs in the matching-P/!in_paragraph path now reset color to `defaults->color` instead of inheriting from the current (font-colored) scope.

### ~~A5. `<li><p><li>` nesting produces extra LI paragraph (3 + 3 diff lines)~~ — FIXED

**Fixed in `afb3880d`.** Added `consumed_p` check in the unmatched `</p>` path: when a `</p>` inside an LI already produced a break via the `in_paragraph` path (incrementing `consumed_p`), the outer `</p>` now checks `consumed_p` before producing a break. The check is inside the `!last_break_was_p` guard to avoid prematurely consuming credits when `last_break_was_p` would already suppress the break. Also fixed 6 bonus lines at 1500/1501, 3291/3292, 5082/5083 (the `<p><li><p><li>test</li></p></li></p>` variant).

### A6. Font size doesn't pop on `</font>` in singleline mode (3 diff lines) — BLOCKED

**Lines:** 1778, 3569, 5360

**HTML input:** `<font size="1">text</font><font size="0">text<font size="-1">text</font></font>` (line 1777)

**Expected (Flash):** `<P..><FONT..SIZE="1"..>texttexttext</FONT></P>` — all text at SIZE=1
**Got:** `<P..><FONT..SIZE="1"..>text<FONT SIZE="6">text<FONT SIZE="5">text</FONT></FONT></FONT></P>` — sizes revert on `</font>`

**Root cause:** In Flash, `<font size="0">` and `<font size="-1">` with a relative/zero size appear to NOT create a new size scope — or more precisely, `</font>` doesn't revert font size when the inner font had size=0 or a relative adjustment. The visible effect is that all text inherits SIZE=1 from the first `<font>`.

**Difficulty:** Hard. Flash's font size scoping has unique rules:
- `<font size="0">` — doesn't change size (keeps parent's size=1)
- `<font size="-1">` — relative to parent, but `</font>` doesn't pop it
- This conflicts with normal `</font>` behavior for other sizes
- Changing parser to not pop font size globally would break many other cases

**Approach:** Two possibilities:
1. `<font size="0">` is special-cased to not change size at all. `<font size="-N">` relative sizes that resolve to 0 or below are clamped/ignored.
2. In singleline mode only, font size pops are suppressed when the inner size was 0 or negative.
Needs more investigation with additional test cases from the expected output to determine which rule applies.

---

## Part B: edittext_html_swf8 (95 diff lines)

SWF8 shares most diffs with SWF7 (the Part A fixes reduced SWF8 from 125→95). The remaining ~95 SWF8-specific diffs are:

### B1. SWF8 whitespace preservation in text nodes

SWF8 preserves whitespace-only text content that SWF7 strips. Our parser's SWF7 whitespace stripping is working but SWF8 preservation has issues:
- Lines like `<P ALIGN="RIGHT">` vs `<P ALIGN="LEFT">` — alignment not propagating correctly in whitespace-preserved paragraphs
- Empty `<a href>` tags being stripped when they should be preserved in SWF8

### B2. ~~Trailing color revert markers (same as A1 but in SWF8 context)~~ — PARTIALLY FIXED

A1 carry-over fix also improved SWF8 by 12 diff lines. Some SWF8-specific marker issues remain (first paragraph markers not being emitted).

### B3. `</font>` color behavior with default color (SWF8-specific)

Lines 263, 635, 745, 751, 757: Font color not resetting correctly on `</font>` in some contexts. Example: `<font color="#111111">test</font>` followed by empty `<font>` tags — the color from the closed font leaks.

### B4. Empty `<a href>` preservation

Lines 1280-1300: `<a href="http://example.com">` wrapping empty content should produce `<A HREF="..." TARGET="..."></A>` in output, but we're stripping it.

**Approach for SWF8:** Fix A6 first (if possible), then tackle SWF8-specific whitespace and `<a>` preservation issues. Many SWF8 fixes will be incremental.

---

## Part C: edittext_html_swf6 (2955 diff lines)

SWF6 is fundamentally different — it needs single-paragraph singleline-like behavior even for multiline fields in many contexts. The huge diff count (2955) suggests a major architectural gap:

### C1. SWF6 doesn't treat `<br>` as paragraph breaks in singleline mode

Line 3: Initial value "line 1\nline 2\ntext" gets serialized as separate `<P>` blocks in Flash but we produce one combined `<P>`. This is the initial HTML text from DefineEditText which we parse differently.

### C2. SWF6 `<br>` produces `\r` in text but doesn't create separate paragraphs

Lines 90, 96, 138: Text should contain `test\r` but we produce `test` (missing trailing `\r`).

### C3. SWF6 singleline multiline split behavior

Lines 143-175: Complex interactions between singleline/multiline and how `<p>` and `<br>` are handled in SWF6. `<p>test</p><p>test</p>` in singleline produces separate paragraphs in SWF6 Flash output but we concatenate.

**Approach for SWF6:** This is the lowest priority. With 2955 diffs (45% match), it would need a significant investment in SWF6-specific paragraph splitting logic. Best to get SWF7/SWF8 working well first, then tackle SWF6 as a separate project.

---

## Part D: edittext_html_condensewhite (swf7: 7 diffs, swf8: 269 diffs)

### ~~D1. Whitespace-only content handling~~ — FIXED

**Fixed by removing `!condense_white` guard from whitespace-only text node pre-scan and post-processing.** The SWF7 pre-scan (line ~10321) already correctly strips whitespace-only text nodes; it was gated behind `!condense_white` which disabled it for condenseWhite=true. Removing the guard brought condensewhite_swf7 from 213→7 diff lines.

### D2. Remaining condensewhite_swf7 diffs (7 lines)

The 7 remaining lines in condensewhite_swf7 are multiline paragraph whitespace issues — runs of spaces within content paragraphs where condenseWhite should collapse but doesn't. Needs investigation of condense_white in the text run processing, not just the pre-scan.

### D3. condensewhite_swf8 (269 diffs)

SWF8 condenseWhite has different rules from SWF7. The pre-scan fix is gated on `swf_version <= 7` so it doesn't affect SWF8. SWF8 condenseWhite needs separate investigation.

---

## Priority Order

1. ~~**A1-A5: All fixed**~~
2. ~~**D1: condenseWhite whitespace stripping**~~ — FIXED (213→7 diffs)
3. **A6: Font size pop behavior** (3 diff lines) — Blocked, needs investigation
4. **D2: Remaining condensewhite_swf7** (7 diff lines) — Small, investigate
5. **B1-B4: SWF8-specific issues** (~95 diff lines) — After SWF7 is stable
6. **D3: condensewhite_swf8** (269 diff lines) — Separate SWF8 rules
7. **C1-C3: SWF6 paragraph model** (2955 diff lines) — Largest effort, lowest priority

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
