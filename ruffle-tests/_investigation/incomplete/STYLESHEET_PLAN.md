# TextField.StyleSheet Implementation Plan
<!-- TESTS: edittext_stylesheet -->

Last updated: 2026-03-03

## Status: INCOMPLETE — Large feature, low priority

### Overview

TextField.StyleSheet is an ActionScript class that provides CSS-like styling for HTML text
in TextFields. The runtime has a constructor stub but no functional methods. This is a
**large feature** (~300+ lines) for a single test (edittext_stylesheet, 204/325 match).

### Current Infrastructure

**Constructor** (action.c ~6313-6328): Registered on `TextField.StyleSheet`.
Creates object with basic prototype chain. `NATIVE_STYLESHEET` type not yet defined.

**TextField integration**: `styleSheet` property exists as null default on TextFields.
Setting `styleSheet` to a StyleSheet instance should enable CSS class application during
`htmlText` processing.

**Super() support**: StyleSheet is handled in super() return value check (action.c ~29226).

### Blocked Test

| Test | Lines | Match | What It Tests |
|------|-------|-------|--------------|
| edittext_stylesheet | 325 | 204/325 (62.8%) | Full CSS styling: setStyle, getStyleNames, style application to HTML, cascading, class/element selectors |

### What's Needed

#### StyleSheet Methods

1. **`setStyle(selector, styleObject)`** — Register a CSS selector with properties
   - Selector types: class (`.className`), element (`p`, `font`, `a`), wildcard (`*`)
   - Style object has properties: `color`, `fontSize`, `fontFamily`, `textAlign`,
     `fontWeight`, `fontStyle`, `textDecoration`, `marginLeft`, `marginRight`,
     `indent`, `leading`, `letterSpacing`, `kerning`, `display`
   - Store in internal registry keyed by selector string

2. **`getStyle(selector)`** — Return the style object for a selector

3. **`getStyleNames()`** — Return array/comma-separated list of registered selectors

4. **`clear()`** — Remove all registered styles

5. **`parseCSS(cssText)`** — Parse CSS text string into styles (advanced, may be deferred)

6. **`transform(textNode)`** — Apply styles to a text node (advanced)

#### TextField Integration

When `textField.styleSheet = styleSheetObj`:
- The htmlText setter must parse `class="..."` attributes on HTML elements
- Look up class names in the StyleSheet registry
- Apply style properties to matching text runs (convert to TextFormat properties)
- Support cascading: element selectors < class selectors < inline styles

This requires changes to the HTML text parser in action.c (the htmlText setter
at ~line 7800+) to check for an active StyleSheet and apply CSS rules during parsing.

### Architecture

```
StyleSheet Object
  └─ styles: { ".classRed": {color:"#FF0000"}, "p": {fontSize:14}, ... }
  └─ methods: setStyle, getStyle, getStyleNames, clear, parseCSS, transform

TextField.htmlText setter (with active styleSheet):
  1. Parse HTML normally
  2. For each element with class="X":
     a. Look up ".X" in styleSheet.styles
     b. Look up element name (e.g., "p") in styleSheet.styles
     c. Merge styles (class overrides element)
     d. Convert CSS properties to TextFormat properties
     e. Apply to text run
```

### CSS Property → TextFormat Mapping

| CSS Property | TextFormat Property | Notes |
|-------------|-------------------|-------|
| color | color | Parse "#RRGGBB" → int |
| fontSize | size | In pixels |
| fontFamily | font | Font name string |
| textAlign | align | "left", "center", "right", "justify" |
| fontWeight | bold | "bold" → true |
| fontStyle | italic | "italic" → true |
| textDecoration | underline | "underline" → true |
| marginLeft | leftMargin | In pixels |
| marginRight | rightMargin | In pixels |
| textIndent / indent | indent | In pixels |
| leading | leading | In pixels |
| letterSpacing | letterSpacing | In pixels |
| kerning | kerning | boolean |
| display | - | "block" vs "inline" |

### Estimated Effort

| Component | Lines | Difficulty |
|-----------|-------|-----------|
| StyleSheet class (constructor, methods, storage) | ~80 | Low |
| CSS property parsing | ~60 | Medium |
| TextField htmlText integration | ~150 | High |
| parseCSS (CSS text parser) | ~100 | High |
| **Total** | **~390** | **High** |

### Priority Assessment

**LOW PRIORITY** — This is a large feature (~390 lines) for a single test that already
matches 204/325 (62.8%). The 121 failing lines are all CSS-related behavior.

The 204 matching lines suggest the basic HTML structure is already correct; only CSS
application is missing. This means the feature is self-contained and won't regress
other tests, but the effort/reward ratio is low compared to other blockers.

### Recommendation

**Defer** until higher-ROI blockers are resolved. If implemented, start with:
1. setStyle/getStyle/getStyleNames (basic storage)
2. Simple class selector application in htmlText
3. Skip parseCSS initially (most tests use setStyle directly)

### Files to Modify (when implemented)
- `SWFModernRuntime/src/actionmodern/action.c`: StyleSheet methods, htmlText CSS integration
- `SWFModernRuntime/include/actionmodern/object.h`: NATIVE_STYLESHEET type
