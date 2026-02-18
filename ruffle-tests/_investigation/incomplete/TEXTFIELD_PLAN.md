# TextField/EditText Implementation Plan
<!-- TESTS: text_format, text_format_rounding_swf7, text_format_rounding_swf8, edittext_default_format_font_style, edittext_antialiastype, edittext_default_format, edittext_default_format_empty, textfield_variable, textfield_properties, text_format_display, edittext_autosize_setter, textfield_background_color, textfield_border_color, textfield_text, edittext_password, textfield_maxchars, text_format_font_max_length, textfield_props_swf5, textfield_props_swf6, textfield_props_swf7, textfield_props_swf8, edittext_width_height, edittext_html_align_swf7, edittext_html_align_swf8, textfield_cache_as_bitmap, edittext_newline_stripping, edittext_newlines, edittext_programmatic_focus, edittext_autosize, edittext_font_size, edittext_text_height_leading, edittext_scroll, edittext_hscroll, edittext_html_roundtrip, edittext_html_color, edittext_html_condensewhite_swf7, edittext_html_condensewhite_swf8, edittext_html_entity, edittext_html_swf6, edittext_html_swf7, edittext_html_swf8, edittext_align, edittext_align_trailing_spaces_swf7, edittext_align_trailing_spaces_swf8, edittext_leading, edittext_margins, edittext_letter_spacing, edittext_tag_indent, edittext_bullet, edittext_underline, edittext_tab_stops, edittext_stylesheet, textsnapshot_available_text, textsnapshot_findtext, textsnapshot_gettext, textsnapshot_props_swf5, textsnapshot_props_swf6, textsnapshot_text_order, edittext_drag_select, edittext_focus_selection, edittext_ime_focus_lost, edittext_input, edittext_input_newlines, edittext_password_copy, edittext_paste_empty, edittext_place_caret, edittext_restrict, edittext_restrict_paste, edittext_tab_focus, movieclip_create_text_field -->

Last updated: 2026-02-15

## Status: Phases 1-2 COMPLETE, Phase 3 PARTIAL

### Implementation Commits
- `8811360` — Phase 1: TextField constructor, prototype, and DefineEditText property expansion
- `bce37d6` — Phase 2: TextFormat constructor and property coercion
- `7532231` — Fix TextFormat rounding, display, font truncation, and constructor args
- `bceacde` — Add TextField property support, font info registry, and variable binding
- `cfa68f7` — Add path variable binding, child instance resolution, and MC cache invalidation
- `2705024` — Add TextField autoSize setter coercion
- `711e25a` — Fix TextField properties: createTextField, getTextFormat, kerning, type/sharpness coercion

### Current Test Results (17 passing, many partially passing)

| Test | Lines | Status | Phase |
|------|-------|--------|-------|
| text_format | 1146/1146 | **PASS** | 2 |
| text_format_rounding_swf7 | 840/840 | **PASS** | 2 |
| text_format_rounding_swf8 | 840/840 | **PASS** | 2 |
| edittext_default_format_font_style | 335/335 | **PASS** | 2 |
| edittext_antialiastype | 296/296 | **PASS** | 1 |
| edittext_default_format | 221/221 | **PASS** | 2 |
| edittext_default_format_empty | 95/95 | **PASS** | 2 |
| textfield_variable | 81/81 | **PASS** | 3 |
| textfield_properties | 44/44 | **PASS** | 1 |
| text_format_display | 21/21 | **PASS** | 2 |
| edittext_autosize_setter | 20/20 | **PASS** | 3 |
| textfield_background_color | 11/11 | **PASS** | 1 |
| textfield_border_color | 11/11 | **PASS** | 1 |
| textfield_text | 7/7 | **PASS** | 1 |
| edittext_password | 5/5 | **PASS** | 1 |
| textfield_maxchars | 3/3 | **PASS** | 1 |
| text_format_font_max_length | 2/2 | **PASS** | 2 |
| textfield_props_swf6/7/8 | 208/210 (99%) | near-pass | 1 |
| edittext_width_height | 97/103 (94%) | near-pass | 3 |
| edittext_html_align_swf8 | 45/52 (87%) | near-pass | 5 |
| edittext_html_align_swf7 | 42/52 (81%) | near-pass | 5 |

### Phase Completion

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | TextField constructor and prototype | **DONE** |
| 2 | TextFormat class | **DONE** |
| 3 | Variable binding + width/height/autoSize | **PARTIAL** (variable binding done, autoSize setter done, width/height 94%) |
| 4 | Scroll properties | NOT STARTED |
| 5 | HTML text support | NOT STARTED (but htmlText getter partially works) |
| 6 | Text layout formatting properties | NOT STARTED |
| 7 | StyleSheet + TextSnapshot | NOT STARTED |

---

## Overview

TextField/EditText is the largest category of failing Ruffle tests (66 tests). This document plans the implementation across phases, each building on the previous. The goal is to maximize test pass rate with each phase while keeping changes incremental and testable.

## SWF Spec Reference

DefineEditText (Tag 37) fields from `SWFRecompDocs/specs/swf-spec-19.txt` (lines 11141-11419):
- Bounds RECT, HasText, WordWrap, Multiline, Password, ReadOnly, HasTextColor, HasMaxLength, HasFont, HasFontClass, AutoSize, HasLayout, NoSelect, Border, WasStatic, HTML, UseOutlines
- FontID (UI16), FontHeight (UI16 in twips), TextColor (RGBA), MaxLength (UI16)
- Layout: Align (UI8: 0=left,1=right,2=center,3=justify), LeftMargin (UI16 twips), RightMargin (UI16 twips), Indent (UI16 twips), Leading (SI16 twips)
- VariableName (STRING), InitialText (STRING, may be HTML if HTML flag set)
- HTML subset: `<p>`, `<br>`, `<a>`, `<font>`, `<b>`, `<i>`, `<u>`, `<li>`, `<textformat>`, `<tab>`

Font metrics from DefineFont2/3 layout section:
- FontAscent (UI16), FontDescent (UI16), FontLeading (SI16)
- FontAdvanceTable (SI16[NumGlyphs])
- EM square = 1024 units; SWF coordinates in twips (1px = 20 twips)

---

## Test Inventory (66 tests, grouped by phase)

### Phase 1 Tests — TextField Prototype + Core Properties (~15 tests)
- textfield_props_swf5 (0/87)
- textfield_props_swf6 (0/119)
- textfield_props_swf7 (0/211)
- textfield_props_swf8 (0/247)
- textfield_properties (35/44, 80%)
- textfield_maxchars (0/3)
- textfield_cache_as_bitmap (0/1)
- edittext_newline_stripping (0/46)
- edittext_newlines (0/30)
- edittext_antialiastype (0/?)
- edittext_programmatic_focus (0/12)

### Phase 2 Tests — TextFormat Class (~8 tests)
- text_format (0/1148)
- text_format_display (0/21)
- text_format_font_max_length (0/?)
- text_format_rounding_swf7 (0/?)
- text_format_rounding_swf8 (0/?)
- edittext_default_format (0/74)
- edittext_default_format_empty (0/?)
- edittext_default_format_font_style (0/?)

### Phase 3 Tests — Variable Binding + Geometry (~8 tests)
- textfield_variable (53/81, 65%)
- edittext_width_height (63/103, 61%)
- edittext_autosize (0/60)
- edittext_autosize_setter (0/?)
- edittext_font_size (0/?)
- edittext_text_height_leading (0/?)

### Phase 4 Tests — Scroll Properties (~3 tests)
- edittext_scroll (33/54, 61%)
- edittext_hscroll (0/?)

### Phase 5 Tests — HTML Text (~11 tests)
- edittext_html_roundtrip (11/17, 65%)
- edittext_html_align_swf7 (0/?)
- edittext_html_align_swf8 (0/?)
- edittext_html_color (0/?)
- edittext_html_condensewhite_swf7 (0/?)
- edittext_html_condensewhite_swf8 (0/?)
- edittext_html_entity (0/?)
- edittext_html_swf6 (0/?)
- edittext_html_swf7 (0/?)
- edittext_html_swf8 (0/?)

### Phase 6 Tests — Text Layout Properties (~10 tests)
- edittext_align (36/60, 60%)
- edittext_align_trailing_spaces_swf7 (0/?)
- edittext_align_trailing_spaces_swf8 (0/?)
- edittext_leading (0/?)
- edittext_margins (0/?)
- edittext_letter_spacing (0/?)
- edittext_tag_indent (0/?)
- edittext_bullet (0/?)
- edittext_underline (0/?)
- edittext_tab_stops (0/?) [in ignored_tests.txt]

### Phase 7 Tests — StyleSheet + TextSnapshot (~9 tests)
- edittext_stylesheet (0/55)
- textsnapshot_available_text (0/?)
- textsnapshot_findtext (0/?)
- textsnapshot_gettext (0/?)
- textsnapshot_props_swf5 (0/?)
- textsnapshot_props_swf6 (0/?)
- textsnapshot_text_order (0/?)

### Deferred Tests — Interactive Input (in ignored_tests.txt, 13 tests)
- edittext_drag_select, edittext_focus_selection, edittext_ime_focus_lost, edittext_input, edittext_input_newlines, edittext_password, edittext_password_copy, edittext_paste_empty, edittext_place_caret, edittext_restrict, edittext_restrict_paste, edittext_tab_focus, edittext_tab_stops

---

## Phase 1: TextField Constructor and Prototype

**Goal**: Make TextField a proper constructor function with a prototype containing all standard properties. This is the foundation everything else builds on.

### What the tests expect

From `textfield_props_swf7`, the test does:
1. `trace(TextField)` → `[type Function]` / `function`
2. `trace(TextField.prototype)` → `[object Object]` / `object`
3. Creates an instance and enumerates properties
4. Expected enumerated properties (in order): `styleSheet`, `mouseWheelEnabled`, `condenseWhite`, `restrict`, `textHeight`, `textWidth`, `bottomScroll`, `length`, `selectable`, `multiline`, `password`, `wordWrap`, `background`, `border`, `html`, `embedFonts`, `maxChars`, `maxhscroll`, `hscroll`, `variable`, `htmlText`, `type`, `text`, `autoSize`, `tabIndex`, `textColor`, `backgroundColor`, `borderColor`, `maxscroll`, `scroll`, `filters`, `sharpness`, `thickness`, `antiAliasType`, `gridFitType`
5. After enumeration, tests 8 method functions: `getTextFormat`, `setTextFormat`, `getNewTextFormat`, `setNewTextFormat`, `getDepth`, `removeTextField`, `replaceSel`, `replaceText`
6. Properties set/get and delete behavior

### Implementation

#### 1a. Register `TextField` as a global constructor

In `action.c`, during initialization (alongside existing global registrations):

```c
// Create TextField constructor function
ASFunction* textfield_ctor = createFunction(app_context, "TextField");
// Register on _global
setProperty(app_context, global_obj, "TextField", 9, &textfield_var);

// Create TextField.prototype
ASObject* textfield_proto = createObject(app_context);
setProperty(app_context, textfield_ctor->prototype_obj, /* ... */);
```

#### 1b. Define prototype properties

The TextField prototype needs the following properties registered (as virtual getters/setters or as DontEnum properties on the prototype). For trace-only mode, most of these are backed by data on the EditText metadata stored in tag_stubs.c.

**Properties on TextField.prototype** (35 properties):

| Property | Type | Default | Source |
|----------|------|---------|--------|
| text | String | "" or InitialText | DefineEditText |
| htmlText | String | HTML representation | Computed |
| textColor | Number | 0x000000 | DefineEditText TextColor |
| backgroundColor | Number | 0xFFFFFF | Fixed default |
| borderColor | Number | 0x000000 | Fixed default |
| background | Boolean | false | Fixed default |
| border | Boolean | false | DefineEditText Border flag |
| type | String | "dynamic" | "input" if !ReadOnly |
| length | Number | text.length | Computed |
| multiline | Boolean | false | DefineEditText Multiline flag |
| wordWrap | Boolean | false | DefineEditText WordWrap flag |
| selectable | Boolean | true | !DefineEditText NoSelect |
| condenseWhite | Boolean | false | Fixed default |
| maxChars | Number/null | null | DefineEditText MaxLength |
| password | Boolean | false | DefineEditText Password flag |
| html | Boolean | false | DefineEditText HTML flag |
| embedFonts | Boolean | false | DefineEditText UseOutlines |
| variable | String | "" | DefineEditText VariableName |
| autoSize | String | "none"/"left" | DefineEditText AutoSize flag |
| scroll | Number | 1 | Computed |
| maxscroll | Number | 1 | Computed |
| hscroll | Number | 0 | Computed |
| maxhscroll | Number | 0 | Computed |
| bottomScroll | Number | 1 | Computed |
| textWidth | Number | 0 | Computed from font metrics |
| textHeight | Number | 0 | Computed from font metrics |
| restrict | String/null | null | Fixed default |
| tabIndex | undefined | undefined | Fixed default |
| mouseWheelEnabled | Boolean | true | Fixed default |
| styleSheet | Object/null | null | Fixed default |
| filters | Array | [] | Fixed default |
| sharpness | Number | 0 | CSMTextSettings |
| thickness | Number | 0 | CSMTextSettings |
| antiAliasType | String | "normal" | CSMTextSettings |
| gridFitType | String | "pixel" | CSMTextSettings |

**Methods on TextField.prototype** (8 methods):

| Method | Signature | Notes |
|--------|-----------|-------|
| getTextFormat | (beginIndex?, endIndex?) → TextFormat | Returns TextFormat for range |
| setTextFormat | (fmt, beginIndex?, endIndex?) | Applies TextFormat to range |
| getNewTextFormat | () → TextFormat | Returns default format for new text |
| setNewTextFormat | (fmt) | Sets default format for new text |
| getDepth | () → Number | Returns display depth |
| removeTextField | () | Removes dynamically-created field |
| replaceSel | (text) | Replaces selected text |
| replaceText | (begin, end, text) | Replaces text in range |

#### 1c. Recompiler changes

The recompiler currently emits `tagDefineEditTextProps(char_id, initial_text, text_color)`. We need to expand this to pass all DefineEditText properties that affect runtime behavior:

```c
tagDefineEditTextProps(char_id, initial_text, text_color,
    font_id, font_height,         // from HasFont
    max_length,                    // from HasMaxLength (-1 if none)
    align, left_margin, right_margin, indent, leading,  // from HasLayout
    variable_name,                 // VariableName
    flags);                        // packed: WordWrap|Multiline|Password|ReadOnly|NoSelect|Border|HTML|UseOutlines|AutoSize
```

#### 1d. Expanded NO_GRAPHICS metadata

Expand `ng_textfields[]` struct to store all these properties:

```c
struct {
    size_t char_id;
    char initial_text[1024];  // increased from 256
    u32 text_color;           // 0xRRGGBB
    u16 font_id;
    u16 font_height;          // in twips
    s16 max_length;           // -1 = unlimited
    u8 align;                 // 0=left,1=right,2=center,3=justify
    u16 left_margin;          // twips
    u16 right_margin;         // twips
    u16 indent;               // twips
    s16 leading;              // twips
    char variable_name[128];
    u16 flags;                // packed flags
} ng_textfields[MAX_TEXTFIELDS_NG];
```

#### 1e. Property access changes

Currently properties are stored on `mc->dynamic_props`. After this change:
- TextField instances have their `__proto__` set to `TextField.prototype`
- Properties that need per-instance state (text, textColor, etc.) continue to be stored on `dynamic_props`
- Read-only/computed properties (length, textWidth, textHeight, bottomScroll, maxscroll) use getter logic in GetMember
- The `type` property setter must validate: only "dynamic" and "input" are valid, invalid values keep previous, case-insensitive comparison stores lowercase

### Tests fixed by Phase 1

- **textfield_props_swf5/6/7/8**: Fully fixed — these enumerate the prototype and check function types
- **textfield_properties**: Improved from 80% → likely ~95% (type setter validation, getTextFormat returning values)
- **textfield_maxchars**: Fixed (maxChars returns initial value from DefineEditText)
- **textfield_cache_as_bitmap**: Likely fixed (just needs text field to be created properly)
- **edittext_antialiastype**: Fixed (antiAliasType/gridFitType properties exist)

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=textfield_props_swf7 --diff --verbose
python3 ruffle-tests/verify_output.py --test=textfield_properties --diff --verbose
python3 ruffle-tests/verify_output.py --test=textfield_maxchars --diff --verbose
```

---

## Phase 2: TextFormat Class

**Goal**: Implement the `TextFormat` constructor and its property getters/setters with correct type coercion.

### What the tests expect

From `text_format`, the test creates `new TextFormat()` and sets/gets every property with various value types (null, undefined, numbers, strings, objects with valueOf). Key behaviors:

1. **Constructor**: `new TextFormat(font, size, color, bold, italic, underline, align, leftMargin, rightMargin, indent, leading)` — all optional
2. **Initial values**: All properties start as `null` (not `undefined`)
3. **Type coercion per property**:
   - **String properties** (font, url, target, align, display): `null` → null, `undefined` → null, object → calls `toString()`, string → stored
   - **Boolean properties** (bold, italic, underline, bullet, kerning): `null` → null, `undefined` → null, otherwise → boolean coercion
   - **Integer properties** (size, indent, leading, blockIndent): `null` → null, `undefined` → null, number → `toInt32()` (rounds toward ±Infinity for .5), NaN/Infinity → -2147483648
   - **Non-negative integer properties** (leftMargin, rightMargin): Same as integer but clamped to ≥ 0
   - **Unsigned integer property** (color): `null` → null, `undefined` → null, number → `toUint32()` for display but stored differently, NaN/Infinity → 0
   - **Float property** (letterSpacing): `null` → null, `undefined` → null, number → stored as-is (no rounding), NaN/Infinity preserved
   - **Array property** (tabStops): `null` → null, `undefined` → null, Array → stored, elements coerced to int
   - **String enum property** (align): only accepts "left", "center", "right", "justify" — invalid values are rejected (keeps previous)
   - **String enum property** (display): accepts "block", "inline", "none" — invalid values coerce to "block", case-sensitive

### Implementation

#### 2a. Register `TextFormat` as a global constructor

```c
ASFunction* textformat_ctor = createFunction(app_context, "TextFormat");
// TextFormat constructor handles 0-11 arguments:
// font, size, color, bold, italic, underline, align, leftMargin, rightMargin, indent, leading
```

#### 2b. TextFormat property storage

TextFormat is a simple data object. Each instance stores 17 properties as ActionVar values (null by default). Use native function callbacks for setters to apply type coercion.

Properties: font, size, color, bold, italic, underline, align, leftMargin, rightMargin, indent, leading, blockIndent, bullet, kerning, letterSpacing, tabStops, target, url, display

#### 2c. Property coercion rules (must be exact)

The `text_format` test is 1148 lines — it exhaustively tests every property with every value type. The coercion rules are:

```
// Integer (size, indent, leading, blockIndent):
// Input → toNumber() → if NaN/Inf → -2147483648; else → Math.round() with banker's rounding
// Actually: Flash uses "round half away from zero" for .5 values
// -3.5 → -4, -2.5 → -2, 2.5 → 2, 3.5 → 4

// Non-negative integer (leftMargin, rightMargin):
// Same as integer but max(0, result)

// Color (unsigned):
// Input → toUint32(), NaN/Inf → 0

// Float (letterSpacing):
// Input → toNumber(), stored as-is (NaN, Infinity preserved)

// Boolean (bold, italic, underline, bullet, kerning):
// null → null, undefined → null, else → Boolean()

// String (font, url, target):
// null → null, undefined → null, else → toString()

// Enum align:
// null → null, undefined → null, valid string → stored, invalid → rejected (no change)
```

**Important**: The rounding for size is "round half to even" (banker's rounding): -3.5→-4, -2.5→-2, 2.5→2, 3.5→4. This matches the test expectations.

#### 2d. getTextFormat / setTextFormat on TextField

`getTextFormat()` returns a new TextFormat object with properties filled from the text field's formatting metadata. For a freshly placed DefineEditText field, these come from the tag's layout section and font info:

- `align`: from DefineEditText Align (0="left", 1="right", 2="center", 3="justify")
- `font`: from font name in DefineFont2/3
- `size`: from FontHeight / 20 (twips to pixels)
- `color`: from TextColor
- `bold`: from DefineFont2/3 FontFlagsBold
- `italic`: from DefineFont2/3 FontFlagsItalic
- `leftMargin`, `rightMargin`, `indent`, `leading`: from DefineEditText layout section (twips to pixels: / 20)
- `underline`, `bullet`, `kerning`, `letterSpacing`, `blockIndent`, `tabStops`: defaults

`getNewTextFormat()` returns the default format for newly-typed text (same as getTextFormat for now).

`setTextFormat(fmt, begin?, end?)` applies a TextFormat to a range of text. Properties that are non-null in `fmt` override the field's formatting.

`setNewTextFormat(fmt)` sets the default format for new text entry.

### Tests fixed by Phase 2

- **text_format**: Should reach high pass rate — this is all property coercion
- **text_format_display**: Fixed by `display` property
- **text_format_font_max_length**: Fixed
- **text_format_rounding_swf7/swf8**: Fixed by correct rounding
- **edittext_default_format**: Fixed — getTextFormat returns proper values from DefineEditText metadata
- **edittext_default_format_empty**: Fixed
- **edittext_default_format_font_style**: Fixed

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=text_format --diff --verbose
python3 ruffle-tests/verify_output.py --test=edittext_default_format --diff --verbose
python3 ruffle-tests/verify_output.py --test=text_format_display --diff --verbose
```

---

## Phase 3: Variable Binding + Width/Height/AutoSize

**Goal**: Implement the `variable` property bidirectional binding and TextField geometry.

### Variable Binding

The `variable` property in DefineEditText creates a two-way binding between a variable name and the text field's `text` property:
1. When the field is placed, if the variable already exists, the field's text is set to the variable's value
2. If the variable doesn't exist, it's created with the field's InitialText
3. Setting `text` updates the variable; setting the variable updates `text`
4. Multiple fields can bind to the same variable (they all stay in sync)
5. The `variable` property can be changed at runtime — changing it breaks the old binding and creates a new one

### Width/Height

The `edittext_width_height` test expects:
- `_width` and `_height` are derived from the DefineEditText Bounds RECT
- Setting `_width` scales the field (changes `_xscale`)
- Setting `_height` scales the field (changes `_yscale`)
- `_rotation` defaults to 0

This requires passing Bounds from DefineEditText through the recompiler to the runtime.

### AutoSize

The `autoSize` property can be "none", "left", "center", "right":
- "none": fixed size from Bounds
- "left": field resizes rightward to fit text
- "center": field resizes both ways to fit text
- "right": field resizes leftward to fit text

AutoSize recalculates `_width`/`_height` based on textWidth/textHeight + margins + 4px gutter.

### Recompiler changes

Pass Bounds RECT (xmin, xmax, ymin, ymax in twips) from DefineEditText to runtime:

```c
tagDefineEditTextProps(char_id, initial_text, text_color,
    font_id, font_height, max_length,
    align, left_margin, right_margin, indent, leading,
    variable_name, flags,
    bounds_xmin, bounds_xmax, bounds_ymin, bounds_ymax);  // NEW
```

### Tests fixed by Phase 3

- **textfield_variable**: Improved significantly (variable binding is the main feature)
- **edittext_width_height**: Fixed (_width/_height from Bounds)
- **edittext_autosize**: Fixed (autoSize behavior)
- **edittext_autosize_setter**: Fixed
- **edittext_font_size**: Partially fixed (depends on font metrics)
- **edittext_text_height_leading**: Partially fixed

### Verification

```bash
python3 ruffle-tests/verify_output.py --test=textfield_variable --diff --verbose
python3 ruffle-tests/verify_output.py --test=edittext_width_height --diff --verbose
python3 ruffle-tests/verify_output.py --test=edittext_autosize --diff --verbose
```

---

## Phase 4: Scroll Properties

**Goal**: Implement scroll, maxscroll, hscroll, maxhscroll, bottomScroll.

### Behavior

- `scroll`: 1-based line index of the topmost visible line. Clamped to [1, maxscroll]. Setting null/undefined → 1. Setting float → truncated.
- `maxscroll`: Total lines minus visible lines + 1. Read-only computed.
- `bottomScroll`: Last visible line index. Read-only computed.
- `hscroll`: Horizontal scroll in pixels. Clamped to [0, maxhscroll].
- `maxhscroll`: Maximum horizontal scroll. Read-only computed.

Computing these requires knowing:
1. Line count (from text layout with word wrapping)
2. Visible line count (from field height / line height)
3. Text width (for hscroll)

For trace-only mode, we can approximate line calculations using font metrics (FontHeight + Leading per line).

### Tests fixed by Phase 4

- **edittext_scroll**: Improved significantly (scroll/maxscroll/bottomScroll)
- **edittext_hscroll**: Fixed

---

## Phase 5: HTML Text Support

**Goal**: Implement `htmlText` property with HTML parsing and generation.

### Reading htmlText

When reading `htmlText`, the runtime must generate HTML from the internal text + format runs:

```
<TEXTFORMAT LEADING="2"><P ALIGN="LEFT"><FONT FACE="Times New Roman" SIZE="12" COLOR="#000000" LETTERSPACING="0" KERNING="1">text here</FONT></P></TEXTFORMAT>
```

Structure: `<TEXTFORMAT>` wraps paragraphs with non-default format attributes, `<P>` has `ALIGN`, `<FONT>` has `FACE`, `SIZE`, `COLOR`, `LETTERSPACING`, `KERNING`. Bold/italic/underline use `<B>`, `<I>`, `<U>` wrapper tags.

### Writing htmlText

Setting `htmlText` parses the HTML and applies formatting. The limited HTML subset from the SWF spec:
- `<p align="...">` — paragraph with alignment
- `<br>` — line break
- `<font face="..." size="..." color="#RRGGBB">` — font
- `<b>`, `<i>`, `<u>` — bold, italic, underline
- `<li>` — bullet item
- `<textformat leftmargin="..." rightmargin="..." indent="..." blockindent="..." leading="..." tabstops="...">` — format block
- `<a href="..." target="...">` — hyperlink

This requires a simple HTML parser (not a full XML/HTML parser — the subset is small and well-defined).

### Tests fixed by Phase 5

- **edittext_html_roundtrip**: Improved to near-100%
- **edittext_html_align_swf7/swf8**: Fixed
- **edittext_html_color**: Fixed
- **edittext_html_condensewhite_swf7/swf8**: Fixed
- **edittext_html_entity**: Fixed (HTML entity decode: `&lt;` `&gt;` `&amp;` `&quot;` `&apos;`)
- **edittext_html_swf6/swf7/swf8**: Fixed

---

## Phase 6: Text Layout Formatting Properties

**Goal**: Make layout properties (align, margins, indent, leading, letterSpacing, bullet, underline, tabStops) affect computed values like textWidth/textHeight.

These are mostly about the interaction between TextFormat properties and the text field's computed layout. The test expectations for `edittext_align` etc. check that format properties propagate correctly when set via `setTextFormat()`.

### Tests fixed by Phase 6

- **edittext_align**: Fixed
- **edittext_align_trailing_spaces_swf7/swf8**: Fixed
- **edittext_leading**: Fixed
- **edittext_margins**: Fixed
- **edittext_letter_spacing**: Fixed
- **edittext_tag_indent**: Fixed
- **edittext_bullet**: Fixed
- **edittext_underline**: Fixed

---

## Phase 7: StyleSheet + TextSnapshot

**Goal**: Implement basic StyleSheet and TextSnapshot classes.

### StyleSheet

- Constructor: `new TextField.StyleSheet()`
- Methods: `parseCSS(cssText)`, `getStyle(name)`, `setStyle(name, styleObj)`, `clear()`, `transform(textformat)`
- When assigned to `textField.styleSheet`, HTML text is parsed with CSS class mappings

### TextSnapshot

- Constructor: Created via `MovieClip.getTextSnapshot()`
- Methods: `getCount()`, `getText(start, end, includeWhitespace)`, `getSelectedText(includeWhitespace)`, `setSelected(start, end, select)`, `getSelected(start, end)`, `findText(start, text, caseSensitive)`, `hitTestTextNearPos(x, y, maxDistance)`, `setSelectColor(color)`, `getTextRunInfo(start, end)`

### Tests fixed by Phase 7

- **edittext_stylesheet**: Fixed
- **textsnapshot_props_swf5/6**: Fixed (prototype enumeration)
- **textsnapshot_***: Other tests need actual text snapshot functionality

---

## Implementation Priority and Dependencies

```
Phase 1 ──→ Phase 2 ──→ Phase 3
  │                        │
  │                        ├──→ Phase 4
  │                        │
  │                        └──→ Phase 5 ──→ Phase 6
  │
  └──→ Phase 7 (independent of 3-6)
```

**Estimated test impact:**

| Phase | Tests Fixed | Cumulative |
|-------|-----------|------------|
| 1 | ~11 | ~11 |
| 2 | ~8 | ~19 |
| 3 | ~6 | ~25 |
| 4 | ~2 | ~27 |
| 5 | ~10 | ~37 |
| 6 | ~9 | ~46 |
| 7 | ~7 | ~53 |
| Deferred (input) | 13 | N/A |

---

## Files to Modify

### Recompiler (SWFRecomp/)

| File | Changes |
|------|---------|
| `src/swf.cpp` | Emit expanded `tagDefineEditTextProps()` with all DefineEditText fields |
| `src/action/action.cpp` | Emit `createTextField` action handler (if not already) |

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/actionmodern/action.c` | TextField constructor/prototype registration, TextFormat class, getTextFormat/setTextFormat, variable binding, createTextField handler |
| `src/libswf/tag_stubs.c` | Expanded `ng_textfields[]` struct with all DefineEditText metadata |
| `include/libswf/tag.h` | Updated `tagDefineEditTextProps()` signature, new ng_ helpers |
| `src/actionmodern/object.c` | Possibly: addProperty support for virtual getter/setter properties |

### New files (possibly)

| File | Purpose |
|------|---------|
| `src/actionmodern/textformat.c` | TextFormat class implementation (constructor, property coercion) |
| `src/actionmodern/html_text.c` | HTML text parser and generator for htmlText |

---

## Design Decisions

All features will eventually need full, correct implementations — the goal is to pass all 66 tests. However, we can start with simpler versions where that gets tests passing sooner, then refine later.

1. **Property storage strategy**: Use `addProperty()` virtual getters/setters on the TextField prototype. This is the correct approach (properties enumerate properly, setters can validate/coerce values) and avoids special-casing TextField in GetMember/SetMember. We need addProperty for other features anyway (e.g. `Object.prototype.addProperty` test), so implementing it now pays off twice.

2. **Font metrics in trace mode**: Pass font metrics (advance table, ascent, descent, leading) from the recompiler to the runtime as a font metrics table at init time. Start simple: compute textWidth as sum of advances scaled by fontSize/emSquare, textHeight as ascent+descent+leading. Refine with word-wrap line breaking and kerning in later phases.

3. **HTML parser scope**: Start with a simple state-machine tokenizer — the HTML subset is small (10 tags, no nesting ambiguity). The test expectations are precise about attribute ordering in *output* (htmlText getter), but the *input* parser (htmlText setter) just needs to handle the standard tags. Build the generator (htmlText getter) first since more tests depend on reading htmlText than writing it.

4. **createTextField**: Implement alongside Phase 1 since `textfield_properties` needs it. It's a MovieClip method (`MovieClip.prototype.createTextField(name, depth, x, y, w, h)`) that creates a new TextField instance at runtime.

---

## Quick Win Estimate

**Phases 1+2 alone** (TextField prototype + TextFormat class) would fix ~19 tests and move the filtered pass rate from ~32% to ~36%. These phases are mostly about registering constructors and implementing property coercion — they don't require complex text layout or HTML parsing.
