# TextSnapshot Implementation Plan
<!-- TESTS: textsnapshot_gettext, textsnapshot_findtext, textsnapshot_available_text, textsnapshot_text_order -->

Last updated: 2026-03-03

## Status: INCOMPLETE — Recompiler + Runtime changes needed

### Overview

TextSnapshot captures static text content (from DefineText tags) within a MovieClip's display
list. The runtime has stub methods (all return undefined) and a constructor that marks objects
with `NATIVE_TEXTSNAPSHOT`. The recompiler stores glyph indices but not character codes,
so text content cannot be reconstructed at runtime.

### Current Infrastructure

**Constructor** (action.c ~26476): Creates TextSnapshot with `NATIVE_TEXTSNAPSHOT` native type.
Takes 1 MovieClip argument.

**Prototype methods** (action.c, 9 stubs via `builtin_stub_method`):
- getCount, getText, findText, getSelected, setSelected, getSelectedText,
  hitTestTextNearPos, setSelectColor, getTextRunInfo

**Recompiler** (swf.cpp ~1869-1939, 2079-2149): Parses DefineText/DefineText2 tags.
Extracts glyph indices + font metrics. Stores in `text_data[]` array. Has font code
tables (`font_code_tables[font_id]`) mapping character code → glyph index, but does NOT
emit the reverse mapping.

**Runtime text_data** (swf.h): `SWFAppContext.text_data` (u32*) stores glyph indices.
Character struct stores `text_start` and `text_size` offsets into this array.

### Critical Gap

The recompiler has character code → glyph index mappings at compile time but only emits
glyph indices. TextSnapshot needs character codes at runtime to implement getText/findText.

### Blocked Tests

| Test | Lines | Match | What It Tests |
|------|-------|-------|--------------|
| textsnapshot_gettext | 55 | 4/55 | getText(start, end, includeNewlines), parameter coercion |
| textsnapshot_findtext | 44 | 5/44 | findText(startIndex, text, caseSensitive), return index |
| textsnapshot_available_text | 20 | 10/20 | Text content from dynamic MCs and createTextField |
| textsnapshot_text_order | 1 | 0/1 | getText(0, 100) returns "BCAB" — text ordering |

### Blocks These Plans
- TEXTFIELD_PLAN Phase 7 (4 tests)

---

## Phase 0: Recompiler — Emit Character Codes

**Goal**: Make character codes available at runtime alongside glyph indices.

### Implementation

The recompiler already has `font_code_tables[font_id]` which maps char_code → glyph_index.
We need the reverse: glyph_index → char_code.

#### Option A: Store character codes in text_data (recommended)

Modify the recompiler to emit character codes instead of (or alongside) glyph indices
in the `text_data[]` array. Since TextSnapshot only needs character codes, not glyph
indices, we can replace glyph indices with character codes for text_data:

In `swf.cpp` where text_data entries are emitted (~line 1929, 2141):

**Before:**
```cpp
text_data << "\t" << to_string(glyph_index);
```

**After:**
```cpp
// Look up character code from glyph index using reverse mapping
u32 char_code = reverse_lookup_char_code(font_id, glyph_index);
text_data << "\t" << to_string(char_code);
```

Build the reverse mapping when font code tables are parsed:
```cpp
// In DefineFont2/3 parsing:
for (int i = 0; i < num_glyphs; i++) {
    font_code_tables[font_id][char_codes[i]] = i;  // existing
    font_glyph_to_char[font_id][i] = char_codes[i]; // NEW reverse
}
```

#### Option B: Emit separate char_code array

Add a parallel `text_chars[]` array in generated constants.h:
```c
u32 text_chars[] = { 'A', 'B', 'C', ... };  // Unicode code points
```

This avoids changing the existing text_data format but adds another array.

**Recommendation**: Option A is simpler — just change what text_data stores.

### Files to Modify
- `SWFRecomp/src/swf.cpp`: Build reverse font tables, emit char codes in text_data
- Possibly `SWFModernRuntime/include/libswf/swf.h`: Document text_data stores char codes

### Estimated Effort
~30-40 lines in recompiler.

---

## Phase 1: Runtime — TextSnapshot Content Capture

**Goal**: TextSnapshot constructor captures text content from MC's display list.

### Implementation

When `new TextSnapshot(mc)` is called, walk the MC's display list and collect all
DefineText characters:

```c
// In TextSnapshot constructor:
// 1. Walk mc->display_list for DefineText entries
// 2. For each DefineText entry:
//    - Read text_data[text_start .. text_start + text_size] (now char codes)
//    - Append to snapshot's internal string buffer
// 3. Store concatenated text on the TextSnapshot object as "__text__" property
// 4. Store character count as "__count__" property
```

**Text ordering**: Characters are ordered by their display list depth (front-to-back),
then by their position within each DefineText record.

### Files to Modify
- `SWFModernRuntime/src/actionmodern/action.c`: TextSnapshot constructor

### Estimated Effort
~40-50 lines.

---

## Phase 2: Runtime — Core Methods (getCount, getText, findText)

**Goal**: Implement the three most-used TextSnapshot methods.

### Implementation

#### getCount()
```c
// Return length of __text__ string
```

#### getText(start, end, includeNewlines)
```c
// 1. Coerce start/end to integers, clamp to [0, count]
// 2. Extract substring from __text__[start..end]
// 3. If includeNewlines is false, strip \n characters
// 4. Push result string
```

#### findText(startIndex, textToFind, caseSensitive)
```c
// 1. Coerce arguments
// 2. If caseSensitive: strstr from startIndex
// 3. If !caseSensitive: case-folded search
// 4. Return index or -1
```

### Test Expectations

**textsnapshot_gettext** key patterns:
```
snap.getCount() = 11
snap.getText(0, 11) = "ABCDEFGHIJK"
snap.getText(1, 3) = "BC"
snap.getText(-1, 3) = "ABC"         // negative clamps to 0
snap.getText(0, 100) = "ABCDEFGHIJK" // past-end clamps
snap.getText(3, 1) = ""             // start > end = empty
```

**textsnapshot_findtext** key patterns:
```
snap.findText(0, "A", true) = 0
snap.findText(0, "a", true) = -1    // case sensitive, no match
snap.findText(0, "a", false) = 0    // case insensitive, matches
snap.findText(1, "A", true) = -1    // past occurrence
snap.findText(0, "BC", true) = 1    // multi-char search
```

### Files to Modify
- `SWFModernRuntime/src/actionmodern/action.c`: Replace stubs with implementations

### Estimated Effort
~60-80 lines.

---

## Phase 3: Dynamic Text Capture (textsnapshot_available_text)

**Goal**: TextSnapshot also captures text from dynamic text fields (createTextField).

### What's Needed

The `textsnapshot_available_text` test creates TextFields dynamically and expects
TextSnapshot to include their content. This requires:

1. Walking the display list for both DefineText (static) AND DefineEditText (dynamic) entries
2. For DefineEditText, reading the current `.text` property value
3. Concatenating all text sources in display order

### Implementation

In the TextSnapshot constructor, extend the display list walk:
```c
for each display_list entry:
    if (entry is DefineText):
        append text_data chars
    else if (entry is DefineEditText / MC_IS_TEXTFIELD):
        append current text field .text value
```

### Files to Modify
- `SWFModernRuntime/src/actionmodern/action.c`: TextSnapshot constructor

### Estimated Effort
~20-30 lines (extends Phase 1).

---

## Priority Assessment

| Phase | Effort | Tests Fixed | ROI |
|-------|--------|------------|-----|
| Phase 0 | ~35 lines (recompiler) | prerequisite | Required |
| Phase 1 | ~45 lines (runtime) | prerequisite | Required |
| Phase 2 | ~70 lines (runtime) | textsnapshot_gettext (+51), textsnapshot_findtext (+39), textsnapshot_text_order (+1) | **HIGH** |
| Phase 3 | ~25 lines (runtime) | textsnapshot_available_text (+10) | Medium |

**Total**: ~175 lines for 4 tests (~100 lines gained). Medium-high ROI.

**Recommendation**: Do Phases 0-2 together (recompiler + runtime core). Phase 3 if straightforward.

---

## Regression Guard

After Phase 0 (recompiler change), all tests using DefineText tags need re-recompilation
(delete RecompiledTags/ directories). Verify no regressions in text rendering tests:

```bash
python3 ruffle-tests/verify_output.py --test=edittext_html_roundtrip --diff --verbose
python3 ruffle-tests/verify_output.py --test=text_format --diff --verbose
python3 ruffle-tests/verify_output.py --test=textsnapshot_gettext --diff --verbose
python3 ruffle-tests/verify_output.py --test=textsnapshot_text_order --diff --verbose
```
