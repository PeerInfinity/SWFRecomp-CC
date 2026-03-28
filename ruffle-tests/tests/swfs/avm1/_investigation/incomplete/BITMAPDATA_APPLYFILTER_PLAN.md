# BitmapData.applyFilter() Implementation Plan
<!-- TESTS: bitmapdata_applyfilter_colormatrix (image) -->

Last updated: 2026-03-28

## Status: NOT STARTED

### Problem

`bitmapDataApplyFilter()` in `action.c:8930-8938` is a stub that returns immediately without applying any filter. The `bitmapdata_applyfilter_colormatrix` image test creates BitmapData objects, applies a ColorMatrixFilter, and displays the results. The test only exercises ColorMatrixFilter (not BlurFilter, GlowFilter, etc.).

### API Signature

```actionscript
bitmapData.applyFilter(sourceBitmap, sourceRect, destPoint, filter) : Number
```

| Parameter | Index | Type | Description |
|-----------|-------|------|-------------|
| `sourceBitmap` | 0 | BitmapData | Source pixel data |
| `sourceRect` | 1 | Rectangle | Region to read from source (x, y, width, height) |
| `destPoint` | 2 | Point | Where to write in destination (x, y) |
| `filter` | 3 | BitmapFilter | Filter object (ColorMatrixFilter for this test) |

Returns: 0 on success, -1 if dest disposed, -2 if source not BitmapData, -3 if source disposed.

### ColorMatrixFilter Algorithm

The filter has a 4x5 matrix (20 floats) that transforms each pixel's color channels:

```
new_r = clamp(m[0]*r + m[1]*g + m[2]*b + m[3]*a + m[4]/255, 0, 1)
new_g = clamp(m[5]*r + m[6]*g + m[7]*b + m[8]*a + m[9]/255, 0, 1)
new_b = clamp(m[10]*r + m[11]*g + m[12]*b + m[13]*a + m[14]/255, 0, 1)
new_a = clamp(m[15]*r + m[16]*g + m[17]*b + m[18]*a + m[19]/255, 0, 1)
```

Where r, g, b, a are **un-premultiplied** float values in [0, 1].

**Critical alpha handling:**
1. Read premultiplied ARGB pixel
2. Un-premultiply: divide R, G, B by alpha
3. Apply 4x5 matrix multiplication
4. Clamp each channel to [0, 1]
5. Re-premultiply: multiply R, G, B by new alpha
6. Write premultiplied ARGB pixel
7. If `transparent == 0`: force alpha to 0xFF

### Test Case Details

The test at `bitmapdata_applyfilter_colormatrix/` applies `applyFilter(bmd, sourceRect, destPoint, colorMatrixFilter)` where:
- Source and dest are the same BitmapData
- sourceRect = (0, 0, 150, 150)
- destPoint = (0, 0)
- ColorMatrixFilter constructed with a 20-element array

The test matrix includes an alpha offset of +20 (adds ~0.078 to alpha).

### ColorMatrixFilter Object Access

The filter is an ASObject constructed via `new flash.filters.ColorMatrixFilter(matrixArray)`. To read the matrix:
1. `args[3]` is the filter object
2. Read `"matrix"` property from the object → ASArray of 20 elements
3. Convert each element to f64

Flash AS2 filter class hierarchy:
- `flash.filters.BitmapFilter` (base)
- `flash.filters.ColorMatrixFilter` extends BitmapFilter

For this plan, we only need ColorMatrixFilter. Detection: check if the object has a `"matrix"` property that's an array of length 20.

### Implementation Steps

#### Step 1: Argument Validation (~15 lines)
- Check arg_count >= 4
- Validate sourceBitmap (type OBJECT, has BitmapDataNative, not disposed)
- Extract sourceRect (x, y, width, height from ASObject properties)
- Extract destPoint (x, y from ASObject properties)
- Return appropriate error codes (-1, -2, -3)

#### Step 2: Filter Type Detection (~20 lines)
- Read `"matrix"` property from args[3]
- If it's an ASArray with ~20 elements → ColorMatrixFilter
- Read 20 float values from the array
- Future: detect other filter types (BlurFilter, DropShadowFilter, etc.)

#### Step 3: Color Matrix Application (~40 lines)
```c
static uint32_t applyColorMatrix(uint32_t argb_premul, const float matrix[20]) {
    uint32_t a = (argb_premul >> 24) & 0xFF;
    float fa = a / 255.0f;

    // Un-premultiply
    float fr, fg, fb;
    if (a > 0 && a < 255) {
        fr = ((argb_premul >> 16) & 0xFF) / (float)a;  // Note: divided by a, not 255
        fg = ((argb_premul >> 8) & 0xFF) / (float)a;
        fb = (argb_premul & 0xFF) / (float)a;
    } else if (a == 255) {
        fr = ((argb_premul >> 16) & 0xFF) / 255.0f;
        fg = ((argb_premul >> 8) & 0xFF) / 255.0f;
        fb = (argb_premul & 0xFF) / 255.0f;
    } else {
        fr = fg = fb = 0.0f;
    }

    // Apply 4x5 matrix
    float nr = matrix[0]*fr + matrix[1]*fg + matrix[2]*fb + matrix[3]*fa + matrix[4]/255.0f;
    float ng = matrix[5]*fr + matrix[6]*fg + matrix[7]*fb + matrix[8]*fa + matrix[9]/255.0f;
    float nb = matrix[10]*fr + matrix[11]*fg + matrix[12]*fb + matrix[13]*fa + matrix[14]/255.0f;
    float na = matrix[15]*fr + matrix[16]*fg + matrix[17]*fb + matrix[18]*fa + matrix[19]/255.0f;

    // Clamp
    nr = fmaxf(0, fminf(1, nr));
    ng = fmaxf(0, fminf(1, ng));
    nb = fmaxf(0, fminf(1, nb));
    na = fmaxf(0, fminf(1, na));

    // Re-premultiply and convert to ARGB
    uint32_t oa = (uint32_t)(na * 255.0f + 0.5f);
    uint32_t or = (uint32_t)(nr * na * 255.0f + 0.5f);
    uint32_t og = (uint32_t)(ng * na * 255.0f + 0.5f);
    uint32_t ob = (uint32_t)(nb * na * 255.0f + 0.5f);
    return (oa << 24) | (or << 16) | (og << 8) | ob;
}
```

#### Step 4: Pixel Iteration (~25 lines)
- Iterate sourceRect, clamp to source bounds
- Map to dest using destPoint, clamp to dest bounds
- Apply filter to each pixel, write to dest

### Key Ruffle Source Files

| File | Content |
|------|---------|
| `~/CC/ruffle/render/wgpu/shaders/filter/color_matrix.wgsl` | GPU shader (exact formula) |
| `~/CC/ruffle/core/src/bitmap/operations.rs:1218-1285` | applyFilter pixel loop |
| `~/CC/ruffle/core/src/avm1/globals/bitmap_data.rs:582-647` | AVM1 entry point |
| `~/CC/ruffle/core/src/avm1/globals/color_matrix_filter.rs` | Filter object handling |

### Estimated Complexity

Low-medium (~100 lines of C). The ColorMatrixFilter is a straightforward per-pixel matrix multiplication. The main complexity is:
- Correct un-premultiply/re-premultiply roundtrip
- Reading the matrix array from the ASObject
- Source/dest rect clipping
- Future-proofing for other filter types
