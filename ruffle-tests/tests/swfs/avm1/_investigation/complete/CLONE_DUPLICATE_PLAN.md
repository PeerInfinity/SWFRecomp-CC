# Clone/Duplicate MovieClip Implementation Plan
<!-- TESTS: duplicate_movie_clip, clone_sprite_types, clone_sprite_edittext, clone_sprite_edittext_dynamic, duplicate_movie_clip_drawing, clip_events, clip_event_propagation_order, on_construct -->

Last updated: 2026-03-14

## Status: COMPLETE — 7/8 PASS, clone infrastructure done

Clone/Duplicate MovieClip covers 8 Ruffle tests. The core feature is `ActionCloneSprite` (opcode 0x24), which duplicates an existing display list object, giving the copy a new name and depth. The AS2 method wrapper is `MovieClip.duplicateMovieClip(name, depth, initObj)`.

**Current state (2026-03-14)**:
- `duplicate_movie_clip` ✅ — **PASS**
- `clone_sprite_types` ✅ — **PASS**
- `duplicate_movie_clip_drawing` ✅ — **PASS**
- `clip_events` ✅ — **PASS**
- `on_construct` ✅ — **PASS**
- `clone_sprite_edittext` ✅ — **94/94 PASS** (Blocker 8 resolved 2026-03-14: _alpha quantization, stylesheet scroll reset, device font name)
- `clip_event_propagation_order` ✅ — **PASS** (fixed by MOVIECLIP_PLAN Phase 10: mouse input injection)
- `clone_sprite_edittext_dynamic` (79/86) — 7 remaining mismatches are pre-existing textfield autoSize/dimension bugs on ORIGINAL textfield, not clone-specific

**7/8 PASS. All phases complete. Clone infrastructure is done. Remaining 7 diff lines in clone_sprite_edittext_dynamic are general textfield issues tracked under TEXTFIELD_PLAN.**

## Phase 1: Core Clone/Duplicate — COMPLETE ✅

All Phase 1 work was completed in earlier sessions. Tests passing:
- duplicate_movie_clip (PASS)
- clone_sprite_types (PASS)
- duplicate_movie_clip_drawing (PASS)
- clip_events (PASS)
- on_construct (PASS)

## Phase 2: EditText Clones — SUBSTANTIALLY COMPLETE

### What was done (2026-03-13)

1. **Display list entry creation for clones** (`tag_stubs.c: ng_cloneSpriteFromMC`):
   - `ng_cloneSpriteFromMC` previously did NOT create a display list entry for the clone. This meant `actionFindOrCreateMovieClip` couldn't detect the textfield char_id and never initialized textfield properties. All clone properties returned `undefined`.
   - Added display list entry creation mirroring `ng_cloneSprite` logic: copy source entry, set clone name, ensure capacity, pre-clear occupied depth.
   - This fixed static textfield clones: `clone_sprite_edittext` went from 22/94 → 90/94.

2. **Dynamic textfield clone init** (`action.c: actionInitDynTextFieldClone`):
   - New function to initialize default textfield properties on clones of dynamically-created textfields (`ng_textfield_idx == -2`).
   - Creates `dynamic_props` with `NATIVE_TEXTFIELD`, sets `__proto__` to `TextField.prototype`, initializes all default property values (text, htmlText, background, border, multiline, wordWrap, password, html, embedFonts, condenseWhite, selectable, type, length, textWidth, textHeight, hscroll, scroll, maxChars, restrict, textColor, backgroundColor, borderColor, sharpness, thickness, antiAliasType, gridFitType, autoSize, filters, variable, tabIndex).
   - Called from `ng_cloneSpriteFromMC` and `ng_cloneSprite` when source has `ng_textfield_idx == -2`.
   - `clone_sprite_edittext_dynamic` went from 30/86 → 78/86.

3. **Textfield _x/_y bounds offset** (`action.c: GetMember _x/_y`):
   - Textfield `_x`/`_y` now includes DefineEditText `bounds_xmin`/`bounds_ymin` offset when reading from display list transform. Flash textfield `_x` represents the visual position including bounds origin.

4. **Background property fix** (`action.c: textfield init`):
   - When DefineEditText Border flag (0x0020) is set, `background` is now initialized to `true` (Flash enables both border AND background from the Border flag).

5. **Clone property semantics**:
   - Textfield clones reset `_visible` to `true` (unlike sprite clones which preserve it)
   - Dynamic TF clone `variable` defaults to `null` (not empty string)
   - Dynamic TF clone preserves source's `type` property ("input"/"dynamic")
   - Dynamic TF clone initializes empty `filters` array

### Remaining mismatches (pre-existing textfield issues, NOT clone bugs)

**clone_sprite_edittext (90/94 = 4 mismatches)**:
1. `_alpha` precision: 0.390625 vs 0.5 — color transform quantization not implemented
2. `hscroll` original value: 0 vs 10 — setting styleSheet should reset hscroll
3. `htmlText` clone font name: "Times New Roman" vs "Noto Sans" — embedded font name resolution
4. `scroll` original value: 1 vs 2 — setting styleSheet should reset scroll

**clone_sprite_edittext_dynamic (78/86 = 8 mismatches)**:
1. `text2._x`: original autoSize position differs (pre-existing autoSize calculation)
2. `text2._width`/`_height` (×3): original autoSize-based dimensions differ
3. `text2._alpha`: same quantization issue as static test
4. `text2.htmlText`: original HTML serialization differs (line break handling)
5. `text4._height`: precision (21.5 vs 21.55)

All of these are general textfield implementation gaps, not clone-specific issues.

## Blocked Test

**clip_event_propagation_order (0/17)**: This test requires mouse input injection via `input.json` (MouseMove, MouseDown, MouseUp events). Our NO_GRAPHICS test infrastructure doesn't support input injection. Only 5/17 lines (the onLoad events) could potentially pass without mouse input. This test is covered by MOVIECLIP_PLAN Phase 10.

## Files Modified

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/libswf/tag_stubs.c` | `ng_cloneSpriteFromMC`: added display list entry creation for clone; added dynamic TF clone init call; added textfield _visible reset |
| `SWFModernRuntime/src/actionmodern/action.c` | `actionInitDynTextFieldClone`: new function for dynamic TF clone defaults; `_x`/`_y` getter: add textfield bounds offset; background init: use Border flag |
| `SWFModernRuntime/include/actionmodern/action.h` | Declared `actionInitDynTextFieldClone` |
