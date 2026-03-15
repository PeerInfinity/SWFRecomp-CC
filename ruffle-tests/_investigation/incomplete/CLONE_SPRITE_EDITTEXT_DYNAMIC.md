# clone_sprite_edittext_dynamic — Text Field Clone Properties

**Status**: 78/86 (91%)
**Category**: duplicateMovieClip text field cloning

## Test Overview

Creates 4 text fields with various configurations (borders, htmlText, wordWrap, transforms), clones each via `duplicateMovieClip()`, then compares 60+ properties between original and clone.

## The 8 Diffs

All failures are in **text2** (styled field with htmlText + wordWrap) and **text4** (small rounding):

| Line | Property | Expected | Actual | Issue |
|------|----------|----------|--------|-------|
| 13 | text2._x | 19 → -4 | -237.6 → -237.6 | Position not initialized from source |
| 15 | text2._width | 4 → 0 | 19 → 0 | Width computed from unwrapped text |
| 16 | text2._height | 4 → 0 | 20.3 → 0 | Height computed from unwrapped text |
| 28 | text2._height | 4 → 0 | 20.3 → 0 | Same (duplicate trace) |
| 32 | text2.htmlText | single `<P>` | 4 separate `<P>` tags | Word-wrap not applied to clone |
| 38 | text2._width | 4 → 0 | 19 → 0 | Same (duplicate trace) |
| 73 | text4._height | 21.5 → 0 | 21.55 → 0 | Rounding: 0.05 difference |

## Root Cause

`duplicateMovieClip` does not copy text field properties from the source. The clone gets fresh defaults via `actionInitDynTextFieldClone()` instead of inheriting the source's configuration.

### Current clone flow

1. `actionCloneSprite()` → `ng_cloneSpriteFromMC()` (tag_stubs.c:3777)
2. `ng_duplicateMovieClip()` copies basic MC fields: x, y, xscale, yscale, rotation, alpha, visible
3. `actionInitDynTextFieldClone()` (action.c:14122) sets ALL textfield properties to defaults:
   - wordWrap=false, multiline=false, text="", htmlText="", etc.
4. **Missing**: copy source textfield's actual property values

### Consequences

- text2 has `wordWrap=true` + htmlText with long text → clone gets `wordWrap=false` → different line breaking → different _width/_height
- text2 has _x=19 → clone gets _x from display object transform (-237.6 in twips/20) instead of source's _x
- htmlText stored with `<br>` breaks from original wrapping → clone re-renders without wordWrap → 4 separate `<P>` tags

## Fix

After `actionInitDynTextFieldClone()` sets defaults, copy the source textfield's dynamic_props over the defaults. Specifically:

1. In `ng_cloneSpriteFromMC()` or `ng_duplicateMovieClip()`, after calling `actionInitDynTextFieldClone()`:
   - Copy text content properties: `text`, `htmlText`
   - Copy formatting properties: `wordWrap`, `multiline`, `textColor`, font settings
   - Copy bounds: `_width`, `_height` from source MC
   - Copy position: `_x`, `_y` from source MC (not from display object transform)

2. For the `_x` issue specifically: the source MC's `_x` is set by ActionScript (`as_set_flags & 1`), but the clone's position comes from the display object transform. Need to copy `mc->x` and set `as_set_flags` on the clone.

3. For the `_height` rounding (text4): likely a floating-point precision issue in font height calculation. Minor — may resolve naturally or need a small rounding adjustment.

### Implementation approach

The simplest approach: after `actionInitDynTextFieldClone()`, iterate the source MC's `dynamic_props` and copy all properties to the clone's `dynamic_props` (overwriting defaults). This is a bulk copy rather than cherry-picking individual properties.

```c
// In ng_cloneSpriteFromMC, after actionInitDynTextFieldClone():
if (src_mc->dynamic_props != NULL && clone_mc->dynamic_props != NULL) {
    ASObject* src = (ASObject*)src_mc->dynamic_props;
    ASObject* dst = (ASObject*)clone_mc->dynamic_props;
    for (u32 i = 0; i < src->num_used; i++) {
        if (src->properties[i].name_length > 0) {
            setProperty(app_context, dst,
                src->properties[i].name, src->properties[i].name_length,
                &src->properties[i].value);
        }
    }
}
```

**Caution**: Some properties should NOT be copied (e.g., event handlers like `onChanged` might need special treatment, `__proto__` should not be duplicated). May need a blocklist.

## Files to Modify

- `SWFModernRuntime/src/libswf/tag_stubs.c`:
  - `ng_cloneSpriteFromMC()` (~line 3777): add property copy after init
  - `ng_duplicateMovieClip()` (~line 3894): ensure MC position fields copied
- `SWFModernRuntime/src/actionmodern/action.c`:
  - `actionInitDynTextFieldClone()` (~line 14122): possibly extend to accept source MC

## Related Tests

- `clone_sprite_types` (Ruffle known_failure) — related cloning edge cases
- `selection` (453/455 PASS) — text field selection (separate issue)
