# TextSnapshot Implementation Plan
<!-- TESTS: textsnapshot_gettext, textsnapshot_findtext, textsnapshot_available_text, textsnapshot_text_order -->

Last updated: 2026-03-04

## Status: COMPLETE — All 4 tests PASS (CI confirmed, commit 94c64bbe)

| Test | Result |
|------|--------|
| textsnapshot_gettext | 55/55 PASS |
| textsnapshot_findtext | 44/44 PASS |
| textsnapshot_text_order | 1/1 PASS |
| textsnapshot_available_text | 20/20 PASS |

### Implementation Summary

**Phase 0: Recompiler — Emit Character Codes** (DONE)
- `SWFRecomp/include/swf.hpp`: Added `text_glyph_entries` vector for deferred char code lookup
- `SWFRecomp/src/swf.cpp`: Deferred text_data emission — stores (font_id, glyph_index) pairs during DefineText parsing, resolves to character codes after all font tables are loaded

**Phase 1: Runtime — TextSnapshot Content Capture** (DONE)
- `textSnapshotCapture()` in action.c: Walks MC display list, collects text from CHAR_TYPE_TEXT entries into UTF-16 strings, stores as `__ts_text__`, `__ts_count__`, `__ts_nl__` properties

**Phase 2: Core Methods** (DONE)
- `builtin_ts_getCount()`: Returns `__ts_count__` property
- `builtin_ts_getText()`: Extracts substring with clamp logic and newline insertion between text records
- `builtin_ts_findText()`: Case-sensitive/insensitive search with toString coercion for OBJECT/ARRAY/numeric args

**Phase 3: Dynamic Text (duplicateMovieClip)** (DONE)
- `ng_cloneSprite` and `ng_duplicateMovieClip` in tag_stubs.c: Run frame 0 to populate clone's sprite_display_list (display list context switching)
- `tagDefineText` in tag.c: Accumulate text ranges for same char_id across multiple calls
- Flash behavior: after cloning, source MC's display_obj cleared (TextSnapshot returns empty for source, clone gets text)

**CI Fix (commit 94c64bbe)**: `textSnapshotCapture()` was using `text_data[]` (global glyph indices for rendering) as character codes. This worked locally (pre-compiled glyph indices happened to match ASCII) but failed in CI (fresh recompilation produced different indices). Fixed by having the recompiler emit `text_char_codes[]` (a parallel `u16` array of Unicode code points, resolved via `font_code_tables[font_id][glyph_index]`). Runtime uses `__attribute__((weak))` on `text_char_codes` for backward compatibility — falls back to `text_data` if the symbol isn't defined (older recompiler builds).
