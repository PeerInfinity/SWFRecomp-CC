# BitmapData Implementation Plan
<!-- TESTS: bitmap_data, bitmap_data_colortransform, bitmap_data_compare, bitmap_data_copypixels, bitmap_data_fillrect, bitmap_data_hittest, bitmap_data_max_size_swf9, bitmap_data_max_size_swf10, bitmap_data_noise, bitmap_data_perlinnoise, bitmap_data_pixeldissolve, bitmap_data_pixeldissolve_image, bitmap_data_threshold, bitmap_filters, bitmapdata_applyfilter_colormatrix, bitmapdata_channels, textfield_cache_as_bitmap -->

Last updated: 2026-03-13

## Status: INCOMPLETE — 8/17 tests passing, Phases 1-2 actionable

### Current Results

| Test | Lines | Status | Notes |
|------|-------|--------|-------|
| bitmap_data_fillrect | 0 | **PASS** | 0 expected lines |
| bitmap_data_colortransform | 0 | **PASS** | 0 expected lines |
| bitmap_data_perlinnoise | 0 | **PASS** | 0 expected lines |
| bitmapdata_applyfilter_colormatrix | 0 | **PASS** | 0 expected lines |
| bitmap_data_pixeldissolve_image | 0 | **PASS** | 0 expected lines (image comparison) |
| bitmap_data_max_size_swf9 | 10 | **PASS** | Constructor validation |
| bitmap_data_max_size_swf10 | 12 | **PASS** | Constructor validation |
| textfield_cache_as_bitmap | 1 | **PASS** | Property existence check |
| bitmap_data | 1126 | FAIL (~2211 diff) | Core methods + properties |
| bitmapdata_channels | 19 | FAIL | Channel constants |
| bitmap_data_compare | 41 | FAIL | compare() method |
| bitmap_data_copypixels | 17 | FAIL | copyPixels() method |
| bitmap_data_hittest | 133 | FAIL | hitTest() method |
| bitmap_data_noise | 631 | FAIL | noise() PRNG |
| bitmap_data_pixeldissolve | 1075 | FAIL | pixelDissolve() PRNG |
| bitmap_data_threshold | 176 | FAIL | threshold() method |
| bitmap_filters | 548 | SEGFAULT | Filter .clone() crash |

### What exists today

The constructor validates width/height and creates an ASObject with `native_type = NATIVE_BITMAPDATA`, storing `width` and `height` as float properties. There is no pixel buffer, no pixel operations, and no prototype methods.

---

## Phase 1: Core BitmapData Structure + Properties + Pixel Ops

**Goal:** Implement the pixel buffer, read-only properties, and basic pixel methods. Fixes `bitmap_data` (~1126 lines) and `bitmapdata_channels` (19 lines).

### 1a. Pixel buffer storage

Add a pixel buffer to the BitmapData ASObject. Store a `uint32_t*` pointer and metadata alongside the ASObject:

```c
// Stored as native data on the ASObject (keyed by native_type == NATIVE_BITMAPDATA)
typedef struct {
    uint32_t* pixels;    // ARGB pixel data, row-major
    int32_t width;
    int32_t height;
    uint8_t transparent; // 0 = opaque (alpha always 0xFF), 1 = transparent
    uint8_t disposed;    // 1 = disposed (all operations return -1)
} BitmapDataNative;
```

Store the `BitmapDataNative*` pointer in an unused field on the ASObject (e.g., a native data pointer), or use a side table indexed by a serial ID stored in a property.

**Constructor changes:**
- Allocate `width * height * sizeof(uint32_t)` pixel buffer
- 3rd arg = transparent (bool, default `true`)
- 4th arg = fill color (uint32, default `0xFFFFFFFF` if transparent, `0xFFFFFFFF` if not)
- Non-transparent bitmaps: force alpha to 0xFF on all writes
- Store width/height as integers (not floats)

### 1b. Read-only properties

| Property | Type | Behavior |
|----------|------|----------|
| `width` | int | Read-only. Returns pixel width (integer, not float). Setter is ignored. |
| `height` | int | Read-only. Returns pixel height (integer). Setter is ignored. |
| `transparent` | bool | Read-only. Set at construction. |
| `rectangle` | Rectangle | Read-only. Returns `new Rectangle(0, 0, width, height)` each time. |

`width` and `height` must return integers (the test expects `10`, not `10.5`). The current code stores them as float F64 properties — need to use integer storage or coerce on read.

### 1c. Channel constants

Register static properties on `flash.display.BitmapData`:

```
BitmapData.RED_CHANNEL = 1
BitmapData.GREEN_CHANNEL = 2
BitmapData.BLUE_CHANNEL = 4
BitmapData.ALPHA_CHANNEL = 8
```

These should be non-enumerable, non-deletable properties. The `bitmapdata_channels` test checks both the values and ASSetPropFlags behavior.

### 1d. Pixel read/write methods

```c
// getPixel(x, y) → int (RGB, no alpha)
// Returns 0 for out-of-bounds. Returns -1 if disposed.
int getPixel(BitmapDataNative* bmp, int x, int y) {
    if (bmp->disposed) return -1;
    if (x < 0 || x >= bmp->width || y < 0 || y >= bmp->height) return 0;
    return bmp->pixels[y * bmp->width + x] & 0x00FFFFFF;
}

// getPixel32(x, y) → int (ARGB as signed 32-bit)
// Flash returns as signed int: 0xFFFFFFFF → -1, 0x80FFFFFF → -2130706433
int32_t getPixel32(BitmapDataNative* bmp, int x, int y) {
    if (bmp->disposed) return -1;
    if (x < 0 || x >= bmp->width || y < 0 || y >= bmp->height) return 0;
    return (int32_t)bmp->pixels[y * bmp->width + x];
}

// setPixel(x, y, color) — sets RGB, preserves existing alpha
void setPixel(BitmapDataNative* bmp, int x, int y, uint32_t color) {
    if (bmp->disposed || x < 0 || x >= bmp->width || y < 0 || y >= bmp->height) return;
    uint32_t existing = bmp->pixels[y * bmp->width + x];
    bmp->pixels[y * bmp->width + x] = (existing & 0xFF000000) | (color & 0x00FFFFFF);
}

// setPixel32(x, y, color) — sets full ARGB
// Non-transparent bitmaps: force alpha to 0xFF
void setPixel32(BitmapDataNative* bmp, int x, int y, uint32_t color) {
    if (bmp->disposed || x < 0 || x >= bmp->width || y < 0 || y >= bmp->height) return;
    if (!bmp->transparent) color = color | 0xFF000000;
    bmp->pixels[y * bmp->width + x] = color;
}
```

### 1e. fillRect, clone, dispose

```c
// fillRect(rect, color) — fills rectangle with color
// rect is a Rectangle or plain {x, y, width, height} object
// Non-transparent: force alpha to 0xFF
// Clips to bitmap bounds

// clone() — returns new BitmapData with copied pixels
// Preserves transparent flag

// dispose() — frees pixel buffer, marks as disposed
// All subsequent operations return -1 or undefined
```

### 1f. copyChannel

```c
// copyChannel(src, srcRect, destPoint, sourceChannel, destChannel)
// sourceChannel/destChannel: 1=R, 2=G, 4=B, 8=A
// Copies channel bits from source to destination channel
// 16 possible combinations (4 source × 4 dest channels)
```

### Tests fixed by Phase 1

- **bitmap_data** (1126 lines) — Core test covering all Phase 1 features
- **bitmapdata_channels** (19 lines) — Channel constants

**Estimated line gain: ~1145 lines**

---

## Phase 2: Comparison and Copy Operations

**Goal:** Implement compare, copyPixels, threshold. Fixes 3 more tests.

### 2a. compare(otherBitmapData)

Returns:
- `0` — identical pixels
- `-1` — first bitmap disposed/invalid
- `-2` — second bitmap disposed/invalid
- `-3` — different widths
- `-4` — different heights
- BitmapData object — containing XOR of differing pixels (if pixels differ)

For trace-only mode, we can return the integer codes and a new BitmapData for pixel diffs.

### 2b. copyPixels(src, srcRect, destPoint, alphaBmp, alphaPoint, mergeAlpha)

Copies rectangular region of pixels from source to destination. Handles:
- Source/dest clipping
- Alpha bitmap overlay (optional)
- Merge alpha flag

### 2c. threshold(src, srcRect, destPoint, operation, threshold, color, mask, copySource)

Compares each pixel against threshold value using operation ("==", "!=", "<", "<=", ">", ">="). If comparison passes, writes fill color; if not and copySource is true, copies source pixel. Returns count of modified pixels.

### Tests fixed by Phase 2

- **bitmap_data_compare** (41 lines)
- **bitmap_data_copypixels** (17 lines)
- **bitmap_data_threshold** (176 lines)

**Estimated line gain: ~234 lines**

---

## Phase 3: PRNG-Based Operations

**Goal:** Implement noise and pixelDissolve with exact PRNG matching. Fixes 2 more tests.

### 3a. Lehmer/Park-Miller PRNG

Flash uses a Lehmer PRNG with fixed parameters. Must match exactly for deterministic output:

```c
typedef struct {
    uint32_t x;
} LehmerRng;

void lehmer_init(LehmerRng* rng, uint32_t seed) {
    rng->x = seed;
}

uint32_t lehmer_next(LehmerRng* rng) {
    rng->x = (uint32_t)(((uint64_t)rng->x * 16807ULL) % 2147483647ULL);
    return rng->x;
}

uint8_t lehmer_range(LehmerRng* rng, uint8_t low, uint8_t high) {
    return low + (uint8_t)(lehmer_next(rng) % ((uint32_t)(high - low) + 1));
}
```

### 3b. noise(seed, low, high, channelOptions, grayScale)

```c
// Seed handling: if seed <= 0, use -seed + 1
// Per-pixel generation:
//   For each pixel (row-major order):
//     If grayScale:
//       gray = lehmer_range(rng, low, high)
//       R = G = B = gray (if channel in channelOptions, else 0)
//       A = lehmer_range(rng, low, high) if ALPHA in channelOptions, else 0xFF
//     Else:
//       R = lehmer_range(rng, low, high) if RED in channelOptions, else 0
//       G = lehmer_range(rng, low, high) if GREEN in channelOptions, else 0
//       B = lehmer_range(rng, low, high) if BLUE in channelOptions, else 0
//       A = lehmer_range(rng, low, high) if ALPHA in channelOptions, else 0xFF
```

The exact per-pixel call order must match Flash/Ruffle. The test checks specific pixel values at specific coordinates.

### 3c. pixelDissolve(src, srcRect, destPoint, seed, numPixels, fillColor)

Uses the same Lehmer PRNG to select random pixel positions. Each call:
1. Randomly selects `numPixels` unvisited pixels
2. Either copies from source or fills with fillColor
3. Returns count of pixels actually modified
4. Uses a visited-pixel tracking bitmask

The PRNG-based position selection must match Flash's algorithm exactly. Ruffle's implementation in `bitmap_data_operations.rs` uses the Lehmer RNG to generate (x, y) coordinates.

### Tests fixed by Phase 3

- **bitmap_data_noise** (631 lines)
- **bitmap_data_pixeldissolve** (1075 lines)

**Estimated line gain: ~1706 lines**

---

## Phase 4: HitTest + Filters

**Goal:** Implement pixel-level hitTest and fix filter segfault. Fixes 2 more tests.

### 4a. hitTest(firstPoint, firstAlphaThreshold, secondObject, secondPoint, secondAlphaThreshold)

Tests pixel-level overlap between two BitmapData objects (or a BitmapData and a Point/Rectangle):
1. For each pixel in the intersection region
2. Check if pixel alpha >= alphaThreshold for both bitmaps
3. Return true if any pixel passes both thresholds

### 4b. Filter clone() segfault fix

The `bitmap_filters` test segfaults on filter `.clone()`. This is likely a missing method on filter objects (BevelFilter, BlurFilter, etc.) — calling `.clone()` dereferences a NULL function pointer. Need to investigate and add clone methods to filter prototype objects.

### Tests fixed by Phase 4

- **bitmap_data_hittest** (133 lines)
- **bitmap_filters** (548 lines) — after segfault fix + filter property implementation

**Estimated line gain: ~681 lines**

---

## Phase 5: Advanced Operations (deferred)

These operations have 0 expected output lines (image comparison tests) so they already pass. Listed for completeness:

- `colorTransform(rect, colorTransform)` — applies ColorTransform to pixel region
- `applyFilter(src, srcRect, destPoint, filter)` — applies BitmapFilter
- `perlinNoise(baseX, baseY, numOctaves, seed, stitch, fractalNoise, channelOptions, grayScale, offsets)` — Perlin noise
- `floodFill(x, y, color)` — flood fill from point
- `scroll(x, y)` — scrolls pixel content
- `merge(src, srcRect, destPoint, redMult, greenMult, blueMult, alphaMult)` — per-channel merge
- `paletteMap(src, srcRect, destPoint, redArray, greenArray, blueArray, alphaArray)` — palette lookup
- `draw(source, matrix, colorTransform, blendMode, clipRect, smooth)` — renders display object to bitmap
- `generateFilterRect(srcRect, filter)` — computes output rect for filter
- `getColorBoundsRect(mask, color, findColor)` — finds bounding rect of matching pixels

---

## Implementation Priority

```
Phase 1 (pixel buffer + properties + pixel ops)
    │
    ├──→ Phase 2 (compare, copyPixels, threshold)
    │
    ├──→ Phase 3 (noise, pixelDissolve)    [independent]
    │
    └──→ Phase 4 (hitTest, filters)        [independent]
```

Phase 1 is the prerequisite for all others. Phases 2-4 are independent of each other.

## Estimated Test Impact

| Phase | Tests Fixed | Lines Gained | Cumulative |
|-------|-----------|-------------|------------|
| 1 | bitmap_data, bitmapdata_channels | ~1145 | ~1145 |
| 2 | bitmap_data_compare, bitmap_data_copypixels, bitmap_data_threshold | ~234 | ~1379 |
| 3 | bitmap_data_noise, bitmap_data_pixeldissolve | ~1706 | ~3085 |
| 4 | bitmap_data_hittest, bitmap_filters | ~681 | ~3766 |

**Total potential: ~3766 lines gained, 9 additional tests passing (17/17 total).**

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | BitmapData constructor rewrite, prototype methods (getPixel, setPixel, getPixel32, setPixel32, fillRect, clone, dispose, copyChannel, compare, copyPixels, threshold, noise, pixelDissolve, hitTest), channel constants, pixel buffer management |
| `SWFModernRuntime/include/actionmodern/action.h` | BitmapDataNative struct, function declarations |

No recompiler changes needed — BitmapData is constructed entirely from ActionScript.

## Design Decisions

1. **Pixel buffer storage:** Use a side-allocated `BitmapDataNative*` stored via a property on the ASObject (e.g. `__native__` with a pointer cast to u64). This avoids modifying the ASObject struct. The `dispose()` method frees the pixel buffer and sets the disposed flag.

2. **Memory limits:** Cap total bitmap allocation at a reasonable limit (e.g., 64MB) to prevent OOM from pathological test inputs. The SWF9 max is 2880×2880 = ~32MB per bitmap.

3. **PRNG exactness:** The Lehmer PRNG must use `uint64_t` intermediate multiplication to avoid overflow. The modulus (2^31 - 1) and multiplier (16807) are fixed Flash constants. Any deviation produces cascading failures across all noise/dissolve pixel values.

4. **Signed int output:** `getPixel32` returns pixels as signed 32-bit integers per Flash convention. `0xFFFF0000` = `-65536`, `0xFFFFFFFF` = `-1`. Use `(int32_t)` cast.
