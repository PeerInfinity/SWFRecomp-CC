# createTextField / DefineEditText Rendering Plan
<!-- TESTS: frame_size_translated_negative, frame_size_translated_positive, edittext_stylesheet, edittext_tag_indent, movieclip_create_text_field -->

<!-- PLAN_META
id: CREATETEXTFIELD_RENDERING
status: blocked
phases:
  - id: 1
    name: "Background/border rendering"
    status: complete
  - id: 2
    name: "Negative dimension positioning"
    status: complete
  - id: 3
    name: "Glyph rendering pipeline"
    status: complete
  - id: 4
    name: "Text layout (HTML colors, word wrap, alignment)"
    status: blocked
dependencies: []
blockers:
  - reason: "Anti-aliasing rendering difference: headless tessellated polygons vs rasterized text"
-->

Last updated: 2026-04-06

## Status: BLOCKED — Image tests blocked by anti-aliasing rendering difference

### Blocker

Our headless renderer produces **tessellated polygon outlines** (filled triangles, no anti-aliasing) for text glyphs. The expected images use **anti-aliased rasterized text** from Ruffle's font renderer. Even with perfect positioning, colors, and layout, the pixel-level appearance differs significantly — aliased triangle edges vs smooth anti-aliased edges produce per-pixel differences exceeding the test tolerances.

The two remaining image tests are not achievable without either:
1. Adding anti-aliased rasterization (e.g., stb_truetype bitmap rasterization → texture quads), OR
2. Ruffle increasing the test tolerances / max_outliers to accommodate outline rendering

All 5 trace tests **PASS** in CI (2026-04-06 run, 569/620 overall) and locally confirmed. The image failures are headless-only and do not affect the filtered pass rate.

### Investigated 2026-04-06

Reviewed whether the blocker can be overcome:
- **No rendering code changes** since the plan was blocked (2026-03-28). No commits touching `SWFModernRuntime/src/render/` or text glyph rendering in `tag.c`.
- **stbtt_MakeGlyph bitmap rasterization NOT implemented** — stb_truetype.h is present in `SWFRecomp/lib/stb/` with bitmap functions available, but no code uses them for glyph rendering.
- **PIXEL_TEXT_LAYOUT_PLAN completed** (2026-04-03) — addresses different tests (asfunction, edittext_drag_select, edittext_ime_focus_lost) but does not change the rendering pipeline.
- **No alternative approaches found** — the three options (bitmap rasterization, upstream tolerance increase, SDF rendering) remain the only paths forward.
- **Conclusion**: Blocker remains. All functional (trace) testing is complete. This plan is blocked only for headless image quality.

### Image Test Status

| Test | Tolerance | Status | Notes |
|------|-----------|--------|-------|
| frame_size_translated_negative | max_outliers=1 | **PASS** (0 outliers) | Background/border rendering |
| frame_size_translated_positive | max_outliers=1 | **PASS** (0 outliers) | Background/border rendering |
| movieclip_create_text_field | trigger-based | **PASS** (0 outliers) | Fixed negative dimension positioning |
| edittext_tag_indent | 128, known_failure | FAIL (6987 outliers) | Glyphs render but aliased; known_failure anyway |
| edittext_stylesheet | 64 | FAIL (35556 outliers) | Needs CSS colors + anti-aliased rendering |

### Completed Work

#### Phase 1+2: Background/Border Rendering (c7eb3a54)

1. **Negative dimension positioning** (`action.c`): `createTextField(x, y, -w, -h)` stores `_tf_visualOffX/Y` on dynamic_props. `actionIterateTextFields()` applies the offset.
2. **Conditional +1 pixel edge** (`action.c`): Flash includes the right/bottom edge pixel for positive-dimension text fields but not negative-dimension ones.

#### Phase 3: Glyph Rendering Pipeline (3efe326b)

1. `tagDefineFontGlyphBase()` exposes font glyph_data offsets to runtime.
2. Font glyph lookup APIs: `ng_font_find_glyph()`, `ng_font_get_glyph_base()`, `ng_font_get_metrics()`, `ng_font_glyph_advance_by_idx()`.
3. `textfield_glyph_render_cb()` reads glyph triangles from shape_data, applies CPU-side transforms, renders via `renderer_draw_tris()`.
4. `actionIterateTextFieldGlyphs()` iterator provides text content, font info, text color, field bounds.

#### Device Font Tessellation (581e91f2)

Bundled Noto Sans TTF (238 KB, 1527 glyphs) at `SWFRecomp/assets/NotoSans.ttf`. Recompiler tessellates device font glyphs via stb_truetype + earcut when DefineFont has no outlines.

### Phase 4 (Text Layout) — Not Implemented, Lower Priority

Phase 4 improvements would improve visual quality but won't make image tests pass due to the anti-aliasing blocker:

1. **HTML color styling**: Per-run colors from CSS classes (`edittext_stylesheet` needs this)
2. **Word wrap / multiline**: Line breaking for glyph positioning
3. **Alignment**: center/right/justify
4. **Indent/margins**: Apply DefineEditText indent values to x positions

### To Unblock

The image tests could potentially pass with:
- **Option A**: Bitmap rasterization using `stbtt_MakeGlyphBitmap()` → texture quads in WebGPU (significant work: texture atlas, UV mapping, alpha blending)
- **Option B**: Increase test tolerances / max_outliers in test.toml to accommodate aliased rendering (upstream Ruffle change)
- **Option C**: SDF (signed distance field) rendering for smooth edges at any scale (complex GPU shader changes)

None of these are worth pursuing now since both tests already pass their trace output.
