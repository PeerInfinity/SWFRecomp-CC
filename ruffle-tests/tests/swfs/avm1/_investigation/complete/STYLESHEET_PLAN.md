# TextField.StyleSheet Implementation Plan
<!-- TESTS: edittext_stylesheet -->

Last updated: 2026-03-04

## Status: COMPLETE — edittext_stylesheet 326/326 PASS

### Overview

TextField.StyleSheet is an ActionScript class that provides CSS-like styling for HTML text
in TextFields. All methods (setStyle, getStyle, getStyleNames, clear, parseCSS, transform,
load) were implemented in previous sessions.

### Test Result

| Test | Lines | Match | Status |
|------|-------|-------|--------|
| edittext_stylesheet | 326 | 326/326 (100%) | PASS |

### Final Fix (2026-03-04)

The plan document was outdated (said 204/325). Actual baseline was 325/326 — only 1 line
failing. The issue was in the `htmlText` getter when:
1. Content set via `text.htmlText = '...'` without a stylesheet (stored as raw text)
2. Stylesheet assigned later via `text.styleSheet = styleObj`
3. Reading `text.htmlText` should produce formatted HTML with entity-escaped text

**Fix:** Added `_tf_raw_content` flag on TextField dynamic_props:
- Set to 1 when htmlText is stored as raw text (non-HTML, no stylesheet)
- Cleared in all other setter paths (text setter, htmlText with stylesheet, htmlText with HTML, stylesheet removal)
- In htmlText getter: when no format table exists, stylesheet active, and flag=1, generate
  `<P ALIGN="..."><FONT FACE="..." SIZE="..." COLOR="..." LETTERSPACING="..." KERNING="...">entity_escaped_text</FONT></P>`
  using defaults from tf_get_defaults() + setNewTextFormat overrides

### Files Modified
- `SWFModernRuntime/src/actionmodern/action.c`: htmlText getter (raw content → formatted HTML), setter flag management
