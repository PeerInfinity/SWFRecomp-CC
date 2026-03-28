# createTextField / DefineEditText Rendering Plan
<!-- TESTS: frame_size_translated_negative, frame_size_translated_positive, edittext_stylesheet, edittext_tag_indent, movieclip_create_text_field -->

Last updated: 2026-03-27

## Status: PHASE 1-3 COMPLETE — Remaining tests blocked on device fonts

### Image Test Status

| Test | Tolerance | Status | Notes |
|------|-----------|--------|-------|
| frame_size_translated_negative | max_outliers=1 | **PASS** (0 outliers) | Background/border rendering |
| frame_size_translated_positive | max_outliers=1 | **PASS** (0 outliers) | Background/border rendering |
| movieclip_create_text_field | trigger-based | **PASS** (0 outliers) | Fixed negative dimension positioning |
| edittext_tag_indent | 128, known_failure | FAIL (6336 outliers) | **Device font** — no embedded glyph shapes |
| edittext_stylesheet | 64 | FAIL (33126 outliers) | **Device font** — no embedded glyph shapes |

### Changes Already Made (Phase 1+2)

1. **Negative dimension positioning** (`action.c`): `createTextField(x, y, -w, -h)` now stores `_tf_visualOffX/Y` on dynamic_props. `actionIterateTextFields()` applies the offset for rendering while `_x/_y` properties remain unchanged. Fixed in both `actionCallFunction` and `actionCallMethod` paths.

2. **Conditional +1 pixel edge** (`action.c`): Flash includes the right/bottom edge pixel for positive-dimension text fields but not negative-dimension ones. Now applied conditionally in `actionIterateTextFields()`.

---

## Phase 3: Glyph Rendering — Detailed Plan

### Existing Infrastructure (What We Can Reuse)

#### DefineText already renders glyphs end-to-end

DefineText/DefineText2 (static text) has a complete pipeline:

1. **Glyph tessellation** (`swf.cpp`): DefineFont parsing calls `interpretShape()` on each glyph outline, tessellates via earcut → triangles stored in `shape_data[]`
2. **Glyph index** (`glyph_data[]`): Array of `(offset, size)` u32 pairs, indexed by global glyph index. `glyph_data[2*i]` = offset into shape_data, `glyph_data[2*i+1]` = vertex count
3. **Per-glyph transforms** (`transform_data[]`): Each glyph gets its own 4x4 matrix (scale from font_height/em_square + translate to glyph position)
4. **Rendering** (`tag.c`): `render_webgpu_draw_shape(ctx, offset, size, transform_id, cxform_id)` draws each glyph as a pre-tessellated triangle mesh

This pipeline is entirely **compile-time**: the recompiler pre-computes all transforms and glyph indices, emitting them as static arrays.

#### Font metadata at runtime

`ng_fonts[]` in `tag_stubs.c` stores per-font:
- `code_table[512]`: glyph_index → Unicode code point (reverse: linear scan)
- `advance_table[512]`: glyph_index → advance width (EM units)
- `ascent, descent, leading`: font metrics (EM units)
- `em_square`: EM size (1024 for DF2, 20480 for DF3, 1000 for builtin Noto Sans)
- `glyph_count`: number of glyphs in font

#### Text measurement at runtime

- `ng_computeTextWidth()`: computes max line width in twips, handles word-wrap
- `ng_computeTextLineCount()`: counts lines with word-wrap
- `ng_font_glyph_advance()`: linear scan lookup of advance width by Unicode codepoint

#### Dynamic rendering path

`render_webgpu_draw_tris()` accepts runtime-computed triangle vertices:
- Input: `float* xy_pairs` (pre-transformed x,y in twips), vertex_count, RGBA color, transform_id, cxform_id
- Writes vertices to dynamic GPU buffer (MAX_DYNAMIC_VERTICES = 8192, MAX_DYNAMIC_RECTS = 256 color slots)
- Suitable for rendering glyph shapes with CPU-side transform application

### Gap Analysis

| Component | Status | Gap |
|-----------|--------|-----|
| Glyph shapes (tessellated triangles) | EXISTS in `shape_data[]` via `glyph_data[]` | No gap — glyphs already tessellated |
| Font → glyph_data mapping | EXISTS only in recompiler (`font_glyph_bases`) | **GAP**: Runtime can't find a font's glyphs in glyph_data |
| Unicode → glyph_index | EXISTS via `ng_fonts[].code_table[]` (glyph→codepoint direction) | **GAP**: Need reverse lookup (codepoint→glyph_index) |
| Per-glyph transform | EXISTS at compile-time for DefineText | **GAP**: Need runtime computation for DefineEditText |
| Vertex extraction from shape_data | Not needed for DefineText (GPU-side) | **GAP**: Need CPU-side read + transform for dynamic text |
| Text layout (line breaking) | EXISTS for metrics (`ng_computeTextWidth`, `ng_wrap_count_lines`) | **PARTIAL GAP**: Need to produce per-glyph positions, not just counts |
| Color per text run | EXISTS at compile-time for DefineText (cxform) | **GAP**: Need dynamic color from textColor property / HTML format runs |

### Implementation Plan

#### Step 1: Expose font_glyph_base to runtime (~10 lines)

Add `glyph_base` field to the `ng_fonts[]` struct:

```c
// In tag_stubs.c ng_fonts struct:
size_t glyph_base;  // starting index in glyph_data[] for this font's glyphs
```

In the recompiler (`swf.cpp`), emit this value when writing font metadata. It's already computed as `font_glyph_bases[font_id]`. Add a new function or extend `tagDefineFont2Metrics()` to pass this through.

**Files**: `tag_stubs.c` (struct + setter), `swf.cpp` (emit glyph_base)

#### Step 2: Add codepoint → glyph_index reverse lookup (~15 lines)

Add a function to find glyph index by Unicode codepoint:

```c
// Returns glyph index within font, or -1 if not found
static int ng_font_find_glyph(int font_idx, u16 codepoint)
{
    for (size_t j = 0; j < ng_fonts[font_idx].glyph_count; j++) {
        if (ng_fonts[font_idx].code_table[j] == codepoint)
            return (int)j;
    }
    return -1;
}
```

This is already essentially done by `ng_font_glyph_advance()` — just need to return the index instead of the advance.

**Files**: `tag_stubs.c`

#### Step 3: Add glyph rendering function (~80 lines)

New function in `tag.c` (inside `#if !defined(NO_GRAPHICS) || defined(HEADLESS_GRAPHICS)`):

```c
// Render a single glyph shape with CPU-side transform
static void render_glyph(SWFAppContext* app_context,
    size_t global_glyph_index,
    float scale,          // font_height / em_square (EM → twips)
    float x_off,          // glyph x position (twips)
    float y_off,          // glyph y position (twips)
    float r, float g, float b,  // text color
    u32 display_transform_id,    // display object transform
    u32 cxform_id)               // color transform
```

Implementation:
1. Read `offset = glyph_data[2*global_glyph_index]`, `size = glyph_data[2*global_glyph_index + 1]`
2. Allocate temp `float xy_pairs[size * 2]` on stack (or static buffer)
3. For each vertex `i` in `shape_data[offset..offset+size]`:
   - Extract x,y: `union { u32 u; float f; }` reinterpret from `shape_data[offset+i][0]` and `[1]`
   - Transform: `xy_pairs[2*i] = x_f * scale + x_off; xy_pairs[2*i+1] = y_f * scale + y_off;`
4. Call `renderer_draw_tris(context, xy_pairs, size, r, g, b, 1.0f, display_transform_id, cxform_id)`

**Vertex budget**: A typical Latin glyph has 20-50 triangle vertices. A 100-character text field = ~2000-5000 vertices. MAX_DYNAMIC_VERTICES = 8192. Sufficient for most text fields. For safety, batch by color slot (MAX_DYNAMIC_RECTS = 256) and stop if budget exceeded.

**Files**: `tag.c`

#### Step 4: Add textfield text rendering callback (~100 lines)

Extend `actionIterateTextFields()` to provide text content and font info, OR add a new iterator/callback that provides:
- Text content (UTF-8 or UTF-16)
- Font index, font height
- Text color
- Field bounds (for clipping/layout)
- Display object transform_id (from parent MC's display list position)

Alternative: add a separate function `actionRenderTextFieldGlyphs()` that walks text fields and calls `render_glyph()` for each character:

```c
void actionRenderTextFieldGlyphs(SWFAppContext* app_context, GlyphRenderCallback cb, void* user_data)
{
    for each text field MC in child_mc_cache:
        get text from dynamic_props["text"]
        get font_idx from ng_textfield metadata or dynamic_props["_tf_fontId"]
        get font_height, text_color

        int font_ng_idx = find font in ng_fonts by font_id
        float scale = (float)font_height / (float)ng_fonts[font_ng_idx].em_square
        float x_pos = field_x  // starting x position (twips)
        float y_pos = field_y + ascent * scale  // baseline

        for each character in text:
            int glyph_idx = ng_font_find_glyph(font_ng_idx, codepoint)
            if (glyph_idx < 0) continue  // missing glyph

            size_t global_idx = ng_fonts[font_ng_idx].glyph_base + glyph_idx
            render_glyph(app_context, global_idx, scale, x_pos, y_pos, r, g, b, ...)

            x_pos += ng_fonts[font_ng_idx].advance_table[glyph_idx] * scale
```

**Files**: `action.c` (iterator), `tag.c` (integration in render pass)

#### Step 5: Hook into render pass (~5 lines)

Call the new glyph rendering function alongside `actionIterateTextFields(textfield_render_cb, NULL)` in `tagShowFrame()`.

**Files**: `tag.c`

### Data Flow Diagram

```
[DefineFont parsing (swf.cpp)]
    ↓
[glyph shapes → interpretShape → earcut → shape_data[] triangles]
    ↓
[glyph_data[2*i] = (offset, size) into shape_data]
    ↓ (new: expose glyph_base to runtime)
[ng_fonts[].glyph_base = starting glyph index for this font]
    ↓
[Runtime: for each character in text field]
    ↓
[ng_font_find_glyph(font_idx, codepoint) → glyph_index]
    ↓
[global_index = glyph_base + glyph_index]
    ↓
[Read shape_data[glyph_data[2*global_index]] vertices]
    ↓
[CPU transform: x' = x*scale + offset, y' = y*scale + offset]
    ↓
[render_webgpu_draw_tris(xy_pairs, color, display_transform)]
```

### Considerations and Risks

1. **Vertex budget**: MAX_DYNAMIC_VERTICES = 8192. Long text fields may exceed this. Mitigation: render up to budget, skip remaining characters. Most image tests have short text.

2. **Color slots**: MAX_DYNAMIC_RECTS = 256. Each `draw_tris` call consumes one color slot. If rendering each glyph separately, 256 characters max. Mitigation: batch glyphs of the same color into a single `draw_tris` call.

3. **Display object transform**: Dynamic text fields (createTextField) aren't on the tag display list and don't have a `transform_id`. Currently rendered with identity transform (transform_id=0). For tag-placed DefineEditText fields, the display list entry's `transform_id` is needed.

4. **Text layout**: Step 4 above does simple left-to-right layout. Word-wrap, multiline, alignment, and HTML format runs are deferred to Phase 4 unless needed by specific tests.

5. **Missing glyphs**: The builtin Noto Sans covers ASCII 32-126 only. Non-Latin text will show gaps. SWF-embedded fonts may have different coverage.

6. **shape_data access**: The runtime needs access to `shape_data[]` (the raw vertex array). This is declared as `extern` in the generated code and is available in the compiled binary. Need to verify it's accessible from `tag.c`.

### Estimated Complexity

| Step | Lines | Files |
|------|-------|-------|
| 1. glyph_base to runtime | ~10 | tag_stubs.c, swf.cpp |
| 2. codepoint→glyph lookup | ~15 | tag_stubs.c |
| 3. render_glyph function | ~80 | tag.c |
| 4. text field glyph iterator | ~100 | action.c, action.h |
| 5. render pass hookup | ~5 | tag.c |
| **Total** | **~210** | |

This is significantly less than the original 500+ estimate because:
- Glyph tessellation already exists (DefineFont parsing handles it)
- The dynamic rendering path (`draw_tris`) already exists
- Text measurement functions already exist
- The main new code is just the glue: reading text content, looking up glyphs, computing transforms, and calling draw_tris
