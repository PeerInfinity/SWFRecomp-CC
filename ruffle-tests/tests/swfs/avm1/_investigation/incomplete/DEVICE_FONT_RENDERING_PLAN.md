# Device Font Rendering Plan
<!-- TESTS: edittext_tag_indent, edittext_stylesheet, and any future test using device fonts -->

Last updated: 2026-03-27

## Status: NOT STARTED — All prerequisites in place

### Problem

Many SWF files use "device fonts" — fonts where the SWF stores only code/advance tables but no glyph outlines. Flash Player renders these using system-installed fonts. Ruffle uses a bundled Noto Sans subset as its device font.

Our Phase 3 glyph rendering (committed in 3efe326b) works correctly for embedded fonts but produces no output for device fonts because there are no tessellated glyph shapes in `glyph_data[]`.

The two remaining failing image tests (`edittext_tag_indent`, `edittext_stylesheet`) both use device fonts.

### Key Insight: Recompile-Time Tessellation

The cleanest approach is to **tessellate device font glyphs at recompile time** in `swf.cpp`, producing the same `shape_data[]`/`glyph_data[]` output as embedded fonts. This means:

- **No runtime changes** — the Phase 3 glyph rendering code handles everything
- **Same pipeline** — reuses the existing earcut tessellation in `swf.cpp`
- **Same data format** — glyph triangles stored identically to embedded fonts

### What Already Exists

| Component | Location | Status |
|-----------|----------|--------|
| stb_truetype.h | `SWFRecomp/lib/stb/stb_truetype.h` | Available (5079 lines, v1.26) |
| earcut.hpp | `SWFRecomp/lib/earcut/include/mapbox/earcut.hpp` | Already used for shape tessellation |
| Noto Sans TTF | `~/CC/ruffle/core/assets/notosans.subset.ttf.gz` | 238 KB decompressed, 1527 glyphs, U+0000–U+22FF |
| STB include path | `SWFRecomp/lib/stb/` | Already in verify_output.py `-I` flags |
| Glyph rendering | `tag.c:textfield_glyph_render_cb()` | Phase 3, committed |
| Font glyph base | `tagDefineFontGlyphBase()` | Phase 3, committed |

### Implementation Plan

#### Step 1: Bundle Noto Sans TTF (~5 min)

Decompress and copy the font file:
```bash
python3 -c "import zlib; open('SWFRecomp/assets/NotoSans.ttf','wb').write(zlib.decompress(open('$HOME/CC/ruffle/core/assets/notosans.subset.ttf.gz','rb').read(),-15))"
```

Store at `SWFRecomp/assets/NotoSans.ttf` (238 KB). Add to `.gitignore` or commit directly.

#### Step 2: Load TTF in recompiler (~20 lines in swf.cpp)

At startup (or lazy on first device font hit), load the TTF:

```cpp
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

static stbtt_fontinfo g_device_font;
static bool g_device_font_loaded = false;
static unsigned char* g_device_font_data = NULL;

static bool loadDeviceFont() {
    if (g_device_font_loaded) return g_device_font_data != NULL;
    g_device_font_loaded = true;
    // Try relative paths: ./assets/NotoSans.ttf, ../SWFRecomp/assets/NotoSans.ttf
    FILE* f = fopen("assets/NotoSans.ttf", "rb");
    if (!f) f = fopen(ASSET_PATH "/NotoSans.ttf", "rb");
    if (!f) return false;
    fseek(f, 0, SEEK_END);
    size_t sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    g_device_font_data = (unsigned char*)malloc(sz);
    fread(g_device_font_data, 1, sz, f);
    fclose(f);
    return stbtt_InitFont(&g_device_font, g_device_font_data, 0) != 0;
}
```

#### Step 3: Tessellate device font glyphs (~100 lines in swf.cpp)

When `interpretShape()` produces no triangles for a font glyph (device font), fall back to the TTF:

```cpp
// After interpretShape() for a font glyph:
size_t glyph_size = 3*current_tri - glyph_start;

if (glyph_size == 0 && loadDeviceFont()) {
    // Find glyph in TTF by Unicode codepoint
    u16 codepoint = font_code_tables[font_id][i];
    int ttf_glyph = stbtt_FindGlyphIndex(&g_device_font, codepoint);
    if (ttf_glyph > 0) {
        tessellateDeviceFontGlyph(context, ttf_glyph, font_em_square[font_id]);
        glyph_size = 3*current_tri - glyph_start;
    }
}
```

The `tessellateDeviceFontGlyph()` function:

1. **Get glyph outline**: `stbtt_GetGlyphShape(&g_device_font, glyph_idx, &vertices)`
   - Returns array of `stbtt_vertex`: moveto, lineto, curveto (quadratic bezier)

2. **Convert curves to line segments**: Subdivide quadratic beziers into N line segments (e.g., 4-8 segments per curve). The outline is in the TTF's EM coordinate space.

3. **Scale to match SWF font EM**: TTF uses a different EM square (1000 for Noto Sans) than DefineFont3 (20480). Scale vertices by `swf_em / ttf_em`.

4. **Build polygon for earcut**: Collect line segments into contour(s). Font glyphs can have multiple contours (e.g., 'O' has outer + inner ring). `vmove` starts a new contour.

5. **Tessellate**: Call `mapbox::earcut()` on the polygon (with holes) — identical to existing `fillShape()` code in swf.cpp.

6. **Write to shape_data**: Emit tessellated triangles in the same format as embedded fonts:
   ```cpp
   shape_data << "{ 0x" << hex << VAL(u32, &x_f) << ", 0x" << VAL(u32, &y_f)
              << ", 0x00, 0x00 }," << endl;
   ```
   (style_type=0x00 solid fill, style_index=0x00 — color comes from cxform at render time)

#### Step 4: Verify and test (~5 min)

```bash
rm -rf ruffle-tests/tests/swfs/avm1/edittext_tag_indent/RecompiledScripts \
       ruffle-tests/tests/swfs/avm1/edittext_tag_indent/RecompiledTags
python3 ruffle-tests/verify_output.py --test=edittext_tag_indent --headless --diff --verbose
```

### Data Flow

```
[DefineFont parsing (swf.cpp)]
    ↓
[interpretShape() → 0 triangles (device font, no outlines)]
    ↓
[loadDeviceFont() → stbtt_InitFont(NotoSans.ttf)]
    ↓
[stbtt_GetGlyphShape() → quadratic bezier contours]
    ↓
[Subdivide beziers → line segments → polygon contours]
    ↓
[mapbox::earcut() → triangle indices]
    ↓
[Emit to shape_data[] in same format as embedded fonts]
    ↓
[glyph_data[] records (offset, size) — identical to embedded]
    ↓
[Existing Phase 3 rendering path handles the rest]
```

### Key Technical Details

**stb_truetype coordinate system**: Y-axis points UP (standard typographic). SWF font coordinates also have Y-up in EM space. So no Y-flip needed.

**EM square scaling**: Noto Sans uses EM=1000. If the SWF font has a different EM (e.g., DefineFont3 uses 20480), scale TTF coordinates: `x_swf = x_ttf * (swf_em / ttf_em)`.

**Multiple contours**: Font glyphs often have holes (e.g., 'O', 'D', 'P'). `stbtt_GetGlyphShape()` uses `STBTT_vmove` to start each contour. The first contour is the outer boundary; subsequent contours are holes. earcut.hpp handles this via its polygon+holes input format.

**Quadratic bezier subdivision**: `STBTT_vcurve` vertices define quadratic beziers (start, control, end). Subdivide into N line segments:
```cpp
for (int s = 1; s <= N; s++) {
    float t = (float)s / N;
    float x = (1-t)*(1-t)*x0 + 2*(1-t)*t*cx + t*t*x1;
    float y = (1-t)*(1-t)*y0 + 2*(1-t)*t*cy + t*t*y1;
    contour.push_back({x, y});
}
```
N=6 is a good default (smooth enough for most glyph sizes).

**Winding direction**: earcut requires counterclockwise outer contours and clockwise holes. TTF fonts may use either convention depending on the font. `stbtt_GetGlyphShape()` returns contours in the font's native winding. If the tessellation produces inverted/missing triangles, flip the contour order.

### Estimated Complexity

| Step | Lines | Notes |
|------|-------|-------|
| 1. Bundle font | 0 | File copy |
| 2. Load TTF | ~20 | stbtt_InitFont |
| 3. Tessellate | ~100 | Bezier subdivision + earcut + shape_data emit |
| 4. Test | 0 | Run existing tests |
| **Total** | **~120** | |

### Risks

1. **Glyph matching**: Noto Sans glyphs may not match the original Flash device font (typically _sans, _serif, _typewriter). Visual differences are expected but acceptable — the goal is to render something recognizable, not pixel-perfect.

2. **Missing codepoints**: Noto Sans subset covers U+0000–U+22FF (1527 glyphs). Characters outside this range (CJK, Arabic, etc.) won't render. Acceptable for the current test suite.

3. **Winding issues**: Some TTF fonts have inconsistent winding directions. May need a signed-area check to detect and fix inverted contours.

4. **Performance**: Tessellation adds time to recompilation. With 1527 glyphs and ~6 bezier subdivisions each, total triangle count is manageable (likely <50K triangles).

5. **Font file path**: The recompiler needs to find `NotoSans.ttf`. Use a relative path from the recompiler binary, or pass via environment variable / config.
