# clone_sprite_edittext_dynamic — Text Field Clone Properties

**Status**: 86/86 PASS (100%) ✅
**Category**: duplicateMovieClip text field cloning
**Completed**: 2026-03-15

## Test Overview

Creates 4 text fields with various configurations (borders, htmlText, wordWrap, transforms), clones each via `duplicateMovieClip()`, then compares 60+ properties between original and clone.

## Root Causes and Fixes Applied

The original 8 diffs had multiple root causes, all in the source textfield property computation (not in clone property copying):

### 1. embedFonts=true with missing font → zero text dimensions (lines 13, 15, 16, 28, 38)

**Root cause**: `applyAutoSize()` computed text dimensions using built-in font metrics even when `embedFonts=true` and the font doesn't exist in the SWF. Flash renders nothing for missing embedded fonts.

**Fix**: In `applyAutoSize()` (action.c), detect `embedFonts=true` with `font_id=0` on dynamic textfields (`ng_textfield_idx == -2`). Skip text width/height computation, treating dimensions as zero.

### 2. _width setter not triggering autoSize (lines 13, 15, 38)

**Root cause**: `mcSetEffectiveWidth()` for textfields just set `mc->width` directly without triggering `applyAutoSize()`. In Flash, setting `_width` on a textfield with active autoSize causes recalculation.

**Fix**: Call `applyAutoSize()` after setting `mc->width` in `mcSetEffectiveWidth()` and `mc->height` in `mcSetEffectiveHeight()` for textfields.

### 3. Clone position from autoSize-adjusted source (line 13)

**Root cause**: `ng_cloneSpriteFromMC()` copied `src_mc->x` which included autoSize adjustment. Flash clones get the original `createTextField()` position, not the autoSize-adjusted position.

**Fix**: Store original `createTextField()` coordinates as `_tf_createX`/`_tf_createY` properties in `dynamic_props` at creation time. In clone functions, when source has active autoSize (!= "none"), restore clone position from these stored original coordinates.

### 4. htmlText with stylesheet showing split paragraphs (line 32)

**Root cause**: When a stylesheet was active, the htmlText getter serialized from the TFRunTable which treated `<br>` tags as paragraph separators (separate `<P>` blocks). Flash merges `<br>` breaks into a single paragraph when a stylesheet is present.

**Fix**: In the htmlText getter, when a stylesheet is detected, pass `is_multiline = -1` (stylesheet mode) to `tf_serialize_html()`. This mode merges tag breaks like single-line mode but without converting breaks to spaces (unlike condenseWhite SWF8 behavior).

### 5. _height rounding (line 73)

**Root cause**: `mcGetEffectiveSize()` rounded each rotated dimension term individually before summing: `round(w*sin) + round(h*cos)`. This could differ by 1 twip from `round(w*sin + h*cos)`.

**Fix**: Sum the terms first, then round once: `round(sw_twips * s + sh_twips * c) / 20.0`.

## Files Modified

- `SWFModernRuntime/src/actionmodern/action.c`:
  - `applyAutoSize()`: skip text dimension computation for embedFonts=true with missing font
  - `mcSetEffectiveWidth()` / `mcSetEffectiveHeight()`: call `applyAutoSize()` after setting textfield dimensions
  - `mcGetEffectiveSize()`: sum-then-round for rotated bounding box
  - `createTextField` (both CallFunction and CallMethod paths): store `_tf_createX`/`_tf_createY`
  - htmlText getter: pass stylesheet mode flag to serializer
  - `tf_serialize_html()`: handle `is_multiline == -1` stylesheet mode

- `SWFModernRuntime/src/libswf/tag_stubs.c`:
  - `ng_cloneSpriteFromMC()`: restore original createTextField position for autoSize-adjusted sources
  - `ng_cloneSprite()`: same fix for the string-based clone path
