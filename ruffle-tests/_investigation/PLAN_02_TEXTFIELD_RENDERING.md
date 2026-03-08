# Plan 02: TextField Rendering

**Priority**: High — unlocks 5 tests, including 2 with very high tolerance
**Tests unlocked**: `frame_size_translated_negative` (max_outliers=1), `frame_size_translated_positive` (max_outliers=1), `edittext_tag_indent` (tolerance=128, known_failure), `edittext_stylesheet` (tolerance=64), `movieclip_create_text_field`
**Estimated complexity**: Large (text layout is inherently complex)
**Depends on**: Plan 01 (runtime transforms) for correct text field positioning

**Status: Phase 1 COMPLETE** — `frame_size_translated_negative` and `frame_size_translated_positive` both passing (0 outliers)

---

## Problem

Text fields created via `createTextField()` or placed via DefineEditText tags don't render in graphics mode. The runtime tracks all text field properties (text content, colors, background, border, font, etc.) in NO_GRAPHICS mode, but nothing draws them.

---

## Scope

### Phase 1: Background + Border Only (Quick Win)
Render text field background rectangles and borders without any text content. This would pass `frame_size_translated_negative` and `frame_size_translated_positive` where the expected image shows a cyan rectangle (text field with background+border enabled, backgroundColor=0x00FFFF).

### Phase 2: Static Text Content
Render text glyphs using the existing glyph shape infrastructure. This would help with `edittext_tag_indent` (tolerance=128) and `edittext_stylesheet` (tolerance=64).

### Phase 3: Advanced Text Features
HTML rendering, multi-line layout, word wrap, scroll, etc. Needed for full compliance but not for initial test passing.

---

## Phase 1: Background + Border Rendering — COMPLETE

### What's Needed

A text field with `background=true` needs a filled rectangle. A text field with `border=true` needs a 1-pixel stroked rectangle. Both need to render at the text field's position with its width/height.

### Data Available at Render Time

From the MovieClip struct and its `dynamic_props`:
- `mc->x`, `mc->y` — position in pixels
- `mc->width`, `mc->height` — dimensions in pixels
- `dynamic_props.background` — boolean
- `dynamic_props.backgroundColor` — 24-bit RGB (0xFFFFFF default)
- `dynamic_props.border` — boolean
- `dynamic_props.borderColor` — 24-bit RGB (0x000000 default)

From `ng_textfields[]` for static DefineEditText:
- `bounds_xmin`, `bounds_xmax`, `bounds_ymin`, `bounds_ymax` — bounds in twips
- `flags & 0x0020` — border flag

### Implementation Approach

#### Option A: Dynamic Vertex Generation
Generate quad vertices (2 triangles = 6 vertices) for the background rectangle at render time, upload to GPU, draw.

**Pros**: Simple, precise
**Cons**: Requires dynamic vertex allocation in the vertex buffer

#### Option B: Use a Unit Quad + Transform
Store a 1x1 unit quad in the vertex buffer (once). Scale/translate it via the transform matrix to match the text field dimensions.

**Pros**: No per-frame vertex uploads
**Cons**: Needs a custom transform that encodes position+size

#### Recommended: Option A for simplicity

### Implementation Steps

#### Step 1: Add `renderer_draw_rect` function

```c
void render_webgpu_draw_rect(WebGPURenderContext* ctx,
    float x, float y, float w, float h,    // in twips
    float r, float g, float b, float a,    // fill color 0-1
    u32 cxform_id)
```

This function:
1. Creates 6 vertices for a quad (two triangles) at (x,y)-(x+w,y+h)
2. The vertex format matches the existing shape vertices (x, y, color_idx, flags)
3. Uploads the vertices to a scratch area in the vertex buffer (or appends)
4. Sets up a temporary color entry for the fill color
5. Draws with identity transform (coordinates are in stage space, `stage_to_ndc` handles the rest)

**Simpler alternative**: Use existing draw infrastructure by writing directly to vertex + color + transform buffers at reserved dynamic slots:

```c
// Reserve slots at end of buffers for dynamic rect rendering
#define MAX_DYNAMIC_RECTS 32
// Each rect = 6 vertices, each vertex = 4 u32 (x, y, color_idx, flags)
```

#### Step 2: Identify text fields in the display list

Text fields in the display list are MovieClips with `MC_IS_TEXTFIELD(mc)` true. They're placed as sprites (CHAR_TYPE_SPRITE). During the render loop, check each sprite's `display_obj` to see if it's a text field.

Add to `render_display_list()` or to a new post-render step:

```c
// After rendering all standard display objects
for (size_t i = 1; i <= max_depth; ++i)
{
    DisplayObject* obj = &dl[i];
    if (obj->char_id == 0) continue;
    MovieClip* mc = obj->display_obj;
    if (mc == NULL || !MC_IS_TEXTFIELD(mc)) continue;

    render_textfield(app_context, mc, obj);
}
```

#### Step 3: Render text field background

```c
static void render_textfield(SWFAppContext* app_context, MovieClip* mc, DisplayObject* obj)
{
    // Get properties from dynamic_props
    int has_bg = get_bool_prop(mc->dynamic_props, "background");
    int has_border = get_bool_prop(mc->dynamic_props, "border");
    if (!has_bg && !has_border) return;

    float x = mc->x * 20.0f;  // to twips
    float y = mc->y * 20.0f;
    float w = mc->width * 20.0f;
    float h = mc->height * 20.0f;

    if (has_bg) {
        u32 bg_color = get_num_prop(mc->dynamic_props, "backgroundColor");
        float r = ((bg_color >> 16) & 0xFF) / 255.0f;
        float g = ((bg_color >> 8) & 0xFF) / 255.0f;
        float b = (bg_color & 0xFF) / 255.0f;
        renderer_draw_rect(context, x, y, w, h, r, g, b, 1.0f, obj->cxform_id);
    }

    if (has_border) {
        u32 bd_color = get_num_prop(mc->dynamic_props, "borderColor");
        float r = ((bd_color >> 16) & 0xFF) / 255.0f;
        float g = ((bd_color >> 8) & 0xFF) / 255.0f;
        float b = (bd_color & 0xFF) / 255.0f;
        // Draw 4 thin rectangles for the border (1 pixel = 20 twips)
        float t = 20.0f;  // 1 pixel thick
        renderer_draw_rect(context, x, y, w, t, r, g, b, 1.0f, 0);       // top
        renderer_draw_rect(context, x, y+h-t, w, t, r, g, b, 1.0f, 0);   // bottom
        renderer_draw_rect(context, x, y, t, h, r, g, b, 1.0f, 0);       // left
        renderer_draw_rect(context, x+w-t, y, t, h, r, g, b, 1.0f, 0);   // right
    }
}
```

#### Step 4: Property access helpers

Need helper functions to read properties from `dynamic_props` ASObject:
- `get_bool_prop(ASObject* obj, const char* name)` — returns 0 or 1
- `get_num_prop(ASObject* obj, const char* name)` — returns numeric value as u32

These can use the existing `findPropertyByName()` or `lookupOwnPropByName()` functions in `action.c`.

---

## Phase 2: Text Content Rendering (Future)

### Approach

1. **Font lookup**: Map font name/ID to glyph shapes via `ng_fonts[]` table
2. **Text layout**: For each character in the text string:
   - Look up glyph shape in font's glyph table
   - Calculate advance width from font metrics
   - Build per-glyph transform (position + size)
3. **Glyph rendering**: Use `renderer_draw_shape()` with glyph shape offset/size and per-glyph transform

### Challenges
- Font metrics may not be available for all fonts (some tests use device fonts)
- Multi-line text requires line-break calculation
- HTML text requires parsing formatting tags
- Embedded fonts vs device fonts have different rendering paths

### Tests Affected
- `edittext_tag_indent` (tolerance=128): Static EditText with indentation — needs font rendering
- `edittext_stylesheet` (tolerance=64): CSS-styled text — needs HTML parsing + font rendering
- `movieclip_create_text_field`: Dynamic text field — needs basic text rendering

---

## Phase 1 Testing

### `frame_size_translated_negative`
- Expected: magenta square + cyan text field rectangle + magenta square
- Current: two magenta squares (text field missing)
- After Phase 1: cyan rectangle should appear at (-50,-50) with 20x10 pixel dimensions
- max_outliers=1 means almost all pixels must match

### `frame_size_translated_positive`
- Similar to above but with positive offsets

### Validation
```bash
python3 ruffle-tests/verify_output.py --test=frame_size_translated_negative --headless --diff --verbose
python3 ruffle-tests/verify_output.py --test=frame_size_translated_positive --headless --diff --verbose
```

---

## File Changes Summary

| File | Change |
|------|--------|
| `SWFModernRuntime/src/rendering/render_webgpu.c` | Add `render_webgpu_draw_rect()` for dynamic rectangle drawing |
| `SWFModernRuntime/include/rendering/render_webgpu.h` | Declare `render_webgpu_draw_rect()` |
| `SWFModernRuntime/include/rendering/renderer.h` | Add `renderer_draw_rect` macro |
| `SWFModernRuntime/src/libswf/tag.c` | Add text field rendering in `tagShowFrame()` render loop |

---

## Risks / Open Questions

1. **Vertex buffer space**: Dynamic rectangle vertices need space in the vertex buffer. Either reserve a region at the end or use a separate small buffer.

2. **Color buffer space**: Each rectangle needs a color entry. Either reserve dynamic color slots or use a separate mechanism.

3. **Render order**: Text fields should render at their depth in the display list, not in a separate pass. This means the text field rendering should be integrated into `render_display_list()`, not added as a post-pass.

4. **Static EditText**: DefineEditText tags place text fields differently from `createTextField()`. The rendering approach should work for both. Static EditText have character data in the dictionary; dynamic ones don't.

5. **Transform composition**: Text fields inside sprites need their transforms composed with the parent sprite's transform. The existing `compose_children` handles sprites but may need updates for text fields.
