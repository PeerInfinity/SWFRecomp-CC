# HTML Text Remaining Work

## Status Summary

| Test | Total Lines | Diff Lines | Status |
|------|-------------|------------|--------|
| `edittext_html_roundtrip` | 17 | 0 | PASS |
| `edittext_html_color` | 114 | 0 | PASS |
| `edittext_html_align_swf7` | — | 0 | PASS |
| `edittext_html_align_swf8` | — | 0 | PASS |
| `edittext_html_entity` | — | 0 | PASS |
| `edittext_html_swf7` | 5377 | 55 | 99% match |
| `edittext_html_swf8` | 5377 | 143 | 97% match |
| `edittext_html_swf6` | 5377 | 2955 | 45% match |
| `edittext_html_condensewhite_swf7` | 311 | 213 | 31% match |
| `edittext_html_condensewhite_swf8` | 311 | 269 | 14% match |

**Previously attempted and reverted**: Trailing color revert markers via broad `</font>` close detection caused massive regression (55→133). The behavior is context-dependent and needs a more surgical approach.

---

## Part A: edittext_html_swf7 (55 diff lines remaining)

The 55 remaining diffs fall into 6 categories. Each appears 3 times in the test (the test runs the same HTML inputs with 3 different default format configurations: section 1 with SIZE=6 COLOR=#000000, section 2 with SIZE=12 COLOR=#CC00CC, section 3 with SIZE=12 COLOR=#000000 + TEXTFORMAT RIGHTMARGIN=2 LEADING=2).

### A1. Trailing color revert marker in `</p>` paragraphs (6 diff lines)

**Lines:** 910, 916, 2701, 2707, 4492, 4498

**HTML input examples:**
- `<p>test<font color="#121212"></font><p>test<font color="#131313"></font><p>test<font color="#141414"></font></p></p></p><p>test</p>` (line 907)
- `<p>test<font color="#121212"></font><p>test</p><font color="#131313"><p>test</p></font>` (line 913)

**Expected (Flash):** Second paragraph ends with `<FONT COLOR="#141414"></FONT>` or `<FONT COLOR="#121212"></FONT>` before `</FONT></P>`
**Got:** Second paragraph ends with just `</FONT></P>` — missing trailing color revert marker.

**Root cause:** When `<font color>` creates a color scope and `</font>` closes it, Flash emits a zero-length `<FONT COLOR>` tag at the point where the color reverts. This only happens in multiline mode and only when the color actually changes from a nested `<font>`. Our parser doesn't create these "revert" markers.

**Difficulty:** Hard. The previous attempt to create revert markers on every `</font>` close that changed color caused a 78-line regression. The behavior is context-dependent:
- Occurs in multiline `</p>` paragraphs but NOT in singleline
- Occurs when `</font>` closes a color change
- Does NOT occur for other attributes (bold, size, etc.)
- The revert color is the color from the *closed* font scope, not the parent scope
- Needs to interact correctly with the nested-`<p>` suppression logic

**Approach:** Create zero-length color revert marker runs at `</font>` close ONLY when:
1. The closed font changed color
2. We're inside a paragraph (not at top level)
3. Serialize these markers only in multiline mode

### A2. Trailing color revert marker in `</li>` paragraphs (6 diff lines)

**Lines:** 1084, 1597, 2875, 3388, 4666, 5179

**HTML input:** `<li><font color="#010101">text</font></li>` (lines 1081, 1594)

**Expected (Flash):** `<LI>..text<FONT COLOR="#000000"></FONT>..</LI>` — trailing color revert to default color
**Got:** `<!-- the same -->` (singleline and multiline identical, no revert marker)

**Root cause:** Same as A1 but in LI context. When `<font color="#010101">` wraps text inside `<li>`, Flash's multiline output includes a trailing `<FONT COLOR="#000000"></FONT>` (or `<FONT COLOR="#CC00CC"></FONT>` for section 2) that reverts to the default/outer color.

**Difficulty:** Medium. This is the simpler case of the color revert problem — it's always just one `</font>` at the end of an LI.

**Approach:** Tied to A1 — both need the same "color revert marker on `</font>`" mechanism.

### A3. Alignment inheritance after `</li>` auto-close (3 diff lines)

**Lines:** 808, 2599, 4390

**HTML input:** `<p align="right">text<li></li></p>` (line 805)

**Expected (Flash):** `...<P ALIGN="RIGHT">...` for the trailing empty P paragraph
**Got:** `...<P ALIGN="LEFT">...`

**Root cause:** When `<li>` auto-closes the `<p align="right">`, it pops the P's format scope (which carried align=RIGHT). The `</p>` then creates a break with the default alignment (LEFT). Flash apparently remembers the P's alignment even after `<li>` auto-closes it.

**Difficulty:** Medium. Need to track the "last P alignment" separately from the format stack so that when `</p>` fires after a `</li>`, the subsequent P paragraph inherits the original alignment.

**Approach:** When `<li>` auto-closes a `<p>`, stash the P's alignment in a variable. When an unmatched `</p>` creates a break after an LI paragraph, use the stashed alignment instead of the current scope alignment.

### A4. Color leak from `</li>` to subsequent `</p>` paragraph (3 diff lines)

**Lines:** 1270, 3061, 4852

**HTML input:** `<font color="#010101"><textformat rightmargin="3"><p><li></li></p></textformat></font>` (line 1267)

**Expected (Flash):** LI has COLOR="#010101", P has COLOR="#000000" (default)
**Got:** Both LI and P have COLOR="#010101"

**Root cause:** The `</p>` break paragraph inherits the color from the enclosing `<font color="#010101">` scope. Flash apparently resets color to the field's default color when creating a P paragraph after an LI.

**Difficulty:** Hard. This is a subtle interaction between font color scopes, LI auto-close, and P paragraph creation. May be related to A3 (alignment inheritance).

**Approach:** When creating the post-LI P paragraph (from unmatched `</p>`), reset color to the field's default color rather than inheriting from the current scope.

### A5. `<li><p><li>` nesting produces extra LI paragraph (3 + 3 diff lines)

**Lines:** 1536+1537, 3327+3328, 5118+5119

**HTML input:** `<li><p><li><p>test</p></li></p></li>` (line 1533)

**Expected (Flash):** 3 paragraphs (LI "test" + 2 empty LIs), text="test\r\r\r"
**Got:** 4 paragraphs (LI "test" + 3 empty LIs), text="test\r\r\r\r"

**Root cause:** The `</p></li></p></li>` close sequence creates one extra paragraph break. Our nested-`<p>` suppression (`nested_p_ignored`) only handles `<p>` inside `<p>`, not `<p>` inside `<li>`. The `</p>` inside `</li>` is being treated as a break when it should be suppressed.

**Difficulty:** Medium. Need to extend the nested paragraph suppression to handle `<p>` inside `<li>` in certain contexts.

**Approach:** When `<p>` is ignored inside `<li>` (because a paragraph is already open), track it the same way as nested `<p>` inside `<p>`. The corresponding `</p>` should be suppressed.

### A6. Font size doesn't pop on `</font>` in singleline mode (3 diff lines)

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

## Part B: edittext_html_swf8 (143 diff lines)

SWF8 shares most diffs with SWF7 (the same 55 lines from Part A appear in the SWF8 output range 1-5377 too). The additional ~88 diffs are SWF8-specific:

### B1. SWF8 whitespace preservation in text nodes

SWF8 preserves whitespace-only text content that SWF7 strips. Our parser's SWF7 whitespace stripping is working but SWF8 preservation has issues:
- Lines like `<P ALIGN="RIGHT">` vs `<P ALIGN="LEFT">` — alignment not propagating correctly in whitespace-preserved paragraphs
- Empty `<a href>` tags being stripped when they should be preserved in SWF8

### B2. Trailing color revert markers (same as A1/A2 but in SWF8 context)

Same 6+6 trailing color revert issues as SWF7.

### B3. `</font>` color behavior with default color (SWF8-specific)

Lines 263, 635, 745, 751, 757: Font color not resetting correctly on `</font>` in some contexts. Example: `<font color="#111111">test</font>` followed by empty `<font>` tags — the color from the closed font leaks.

### B4. Empty `<a href>` preservation

Lines 1280-1300: `<a href="http://example.com">` wrapping empty content should produce `<A HREF="..." TARGET="..."></A>` in output, but we're stripping it.

**Approach for SWF8:** Fix the SWF7 issues first (Part A), then tackle SWF8-specific whitespace and `<a>` preservation issues. Many SWF8 fixes will be incremental.

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

## Part D: edittext_html_condensewhite (swf7: 213 diffs, swf8: 269 diffs)

The condenseWhite tests need implementation of whitespace collapsing rules:

### D1. Whitespace-only content handling

Lines 7-40 (swf7): `condenseWhite` should collapse whitespace to nothing, but we produce a single space ` `. The SWF7 rule should strip whitespace-only text nodes entirely when condenseWhite is true.

### D2. Trailing space after content

Lines 85-86 (swf7): `<b>test</b>` followed by whitespace should not have a trailing space when condenseWhite is true. We produce `<B>test</B> ` with trailing space.

### D3. condenseWhite is NOT just whitespace stripping

The `condenseWhite` flag affects the HTML *parser*, not just the output:
- Replace `\t`, `\r`, `\n` with spaces in text content
- Collapse runs of whitespace to single space
- SWF7: strip whitespace-only text nodes
- SWF8: preserve some whitespace differently

**Approach for condenseWhite:**
1. Implement condenseWhite logic in `tf_parse_html()`:
   - When condenseWhite flag is set, collapse whitespace in text nodes
   - SWF7: discard whitespace-only text nodes entirely
   - SWF8: collapse but don't discard
2. The condenseWhite flag is already read from the MC properties — just need to apply it during parsing
3. Test with `edittext_html_condensewhite_swf7` first, then swf8

---

## Priority Order

1. **A5: `<li><p><li>` nesting** (6 diff lines) — Most tractable, extends existing `nested_p_ignored` mechanism
2. **A3: Alignment inheritance after `</li>`** (3 diff lines) — Medium difficulty, clear root cause
3. **A1+A2: Trailing color revert markers** (12 diff lines) — Hardest of the fixable issues, needs surgical approach
4. **A4: Color leak from `</li>` to `</p>`** (3 diff lines) — May be fixed as side-effect of A1+A2
5. **D1-D3: condenseWhite implementation** (213+ diff lines) — Big win for test count
6. **B1-B4: SWF8-specific issues** (88 diff lines) — After SWF7 is stable
7. **A6: Font size pop behavior** (3 diff lines) — Risky to change, may break other things
8. **C1-C3: SWF6 paragraph model** (2955 diff lines) — Largest effort, lowest priority

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
