# HTML Text Remaining Work

## Status Summary

| Test | Total Lines | Diff Lines | Status |
|------|-------------|------------|--------|
| `edittext_html_roundtrip` | 17 | 0 | PASS |
| `edittext_html_color` | 114 | 0 | PASS |
| `edittext_html_align_swf7` | — | 0 | PASS |
| `edittext_html_align_swf8` | — | 0 | PASS |
| `edittext_html_entity` | — | 0 | PASS |
| `edittext_html_swf7` | 5377 | 0 | **PASS** ✅ (font size 0 clamping fix) |
| `edittext_html_swf8` | 5377 | 0 | **PASS** ✅ (font size 0 clamping fix) |
| `edittext_html_swf6` | 5377 | ~1480 | ~72% match |
| `edittext_html_condensewhite_swf7` | 311 | 3 | 99.0% match |
| `edittext_html_condensewhite_swf8` | 311 | ~134 | ~57% match |

**History:**
- Initial broad `</font>` revert markers caused 55→133 regression (reverted). Surgical approach in `afb3880d` fixed 36 lines (55→19 for swf7, 125→107 for swf8) with no regressions.
- condenseWhite fix + serializer font marker carry-over: swf7 19→7, condensewhite_swf7 213→7, swf8 107→95.
- SWF8 batch fixes: color revert markers (6 lines), empty `<a>` preservation (18 lines), empty content font reset (14 lines), alignment with leading whitespace (6 lines). Total: swf8 47→3 (from CI baseline).

---

## Part A: edittext_html_swf7 (3 diff lines remaining)

The 3 remaining diffs are all A6 (font size pop behavior), appearing once per test section.

### ~~A1-A5: All fixed~~ — FIXED

See previous entries for details.

### ~~A6. Font size doesn't pop on `</font>` in singleline mode (3 diff lines)~~ — FIXED

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

## Part B: edittext_html_swf8 (3 diff lines remaining)

### ~~B1. SWF8 whitespace preservation alignment~~ — FIXED

**Fixed by using first content run's alignment for non-empty paragraphs.** When SWF8 preserves whitespace before `<p align="right">`, the whitespace creates content with LEFT alignment that should determine the paragraph's output alignment. Changed serializer to use `pruns[0]->align` instead of `pfmt.align` for non-empty paragraphs. Fixed 6 diff lines.

### ~~B2. Trailing color revert markers~~ — FIXED

**Fixed by adding SWF8+ synthetic color revert marker in serializer.** When `CTX.color != pfmt.color` at content-NL paragraph breaks in SWF8+, emit `<FONT COLOR="..."></FONT>`. Fixed 6 diff lines.

### ~~B3. Empty content font/color/face reset~~ — FIXED

**Fixed by skipping zero-length marker scan for singleline empty paragraphs.** In singleline mode, merged tag breaks contain zero-length font markers that shouldn't affect the outer font. The pfmt from the `\n` break already has correct text field defaults. Added `if (is_multiline)` guard around marker scan. Fixed 14 diff lines.

### ~~B4. Empty `<a href>` preservation~~ — FIXED

**Fixed by extending empty paragraph `<A>` emission to P paragraphs with content NL breaks.** Changed condition from `pfmt.para_type == 1` (LI only) to `pfmt.para_type == 1 || p_break_kind[pi] == 1` (LI + content NL breaks). Tag breaks from `</p>` structural closes (p_break_kind==2) correctly do not emit anchors. Fixed 18 diff lines.

### ~~B5. Font size pop (same as A6)~~ — FIXED

Same fix as A6 — font size 0 clamping to minimum 1. All 3 diff lines resolved.

---

## Part C: edittext_html_swf6 (~1480 diff lines)

SWF6 is fundamentally different — it needs single-paragraph singleline-like behavior even for multiline fields in many contexts. CI shows ~1480 mismatched lines (~72% match), significantly improved from the plan's original 2955 estimate.

### C1-C3: SWF6 paragraph model

See original plan entries. This is the lowest priority and needs a significant investment in SWF6-specific paragraph splitting logic.

---

## Part D: edittext_html_condensewhite (swf7: 3 diffs, swf8: ~134 diffs)

### ~~D1. Whitespace-only content handling~~ — FIXED

### D2. Remaining condensewhite_swf7 diffs (3 lines)

The 3 remaining lines in condensewhite_swf7 are control character handling in multiline mode — `\x01`/`\x02` paragraph break markers being treated differently than expected. Lines 236-238 show whitespace with embedded control chars creating unexpected paragraph breaks.

### D3. condensewhite_swf8 (~134 diffs)

SWF8 condenseWhite has different rules from SWF7. Needs separate investigation.

---

## Priority Order

1. ~~**A1-A5: All fixed**~~
2. ~~**D1: condenseWhite whitespace stripping**~~ — FIXED
3. ~~**B1-B4: SWF8-specific issues**~~ — ALL FIXED (47→3 mismatches)
4. ~~**A6/B5: Font size pop behavior**~~ — FIXED (font size 0 clamping)
5. **D2: Remaining condensewhite_swf7** (3 diff lines) — Small, investigate
6. **D3: condensewhite_swf8** (~134 diff lines) — Separate SWF8 rules
7. **C1-C3: SWF6 paragraph model** (~1480 diff lines) — Largest effort, lowest priority

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
