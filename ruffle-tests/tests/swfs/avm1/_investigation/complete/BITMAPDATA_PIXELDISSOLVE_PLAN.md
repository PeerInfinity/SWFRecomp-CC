# BitmapData.pixelDissolve() Implementation Plan
<!-- TESTS: bitmap_data_pixeldissolve_image (image) -->

<!-- PLAN_META
id: BITMAPDATA_PIXELDISSOLVE
status: complete
phases:
  - id: 1
    name: "Argument validation and extraction"
    status: complete
  - id: 2
    name: "Feistel PRNG"
    status: complete
  - id: 3
    name: "Pixel iteration"
    status: complete
  - id: 4
    name: "Pixel writing"
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-03-29

## Status: COMPLETE

Both tests pass:
- **bitmap_data_pixeldissolve** (trace): 1075/1075 lines match
- **bitmap_data_pixeldissolve_image** (image): 0 outliers, 0 max difference (pixel-perfect)

Implementation: ~120 lines of C replacing the stub. Feistel network PRNG for bijective pixel permutation, source rect clipping via shared coordinate system, self-referential fill and cross-bitmap copy modes, proper error codes (-1/-2/-3/-4).

### Problem (original)

`bitmapDataPixelDissolve()` in `action.c` was a stub using simple LCG. The `bitmap_data_pixeldissolve_image` image test creates BitmapData objects, uses `pixelDissolve()` to pseudo-randomly copy/fill pixels, and displays the results.

### API Signature

```actionscript
bitmapData.pixelDissolve(sourceBitmap, sourceRect, destPoint, randomSeed, numPixels, fillColor) : int
```

| Parameter | Index | Type | Default | Description |
|-----------|-------|------|---------|-------------|
| `sourceBitmap` | 0 | BitmapData | required | Source bitmap (can be self) |
| `sourceRect` | 1 | Rectangle | required | Region to read from source |
| `destPoint` | 2 | Point | required | Where to write in destination |
| `randomSeed` | 3 | int | 0 | Initial seed for Feistel PRNG |
| `numPixels` | 4 | int | 0 | Number of pixels to process |
| `fillColor` | 5 | uint | 0 | Fill color (used when source == dest) |

**Returns:** New random seed (for chaining calls). Error codes: -1 (bad args), -2 (bad source type), -3 (source disposed), -4 (bad sourceRect).

### Algorithm: Feistel Network PRNG

pixelDissolve uses a **1-round Feistel network** to generate a pseudo-random permutation of pixel indices. This ensures every pixel is visited exactly once (bijective mapping).

#### 1. Calculate Feistel Block Size

```c
u32 feistel_block_size(u32 sequence_length) {
    // Bits needed to represent sequence_length - 1, rounded up to even
    u32 bits = 0;
    u32 v = sequence_length - 1;
    while (v > 0) { bits++; v >>= 1; }
    if (bits < 2) bits = 2;
    if (bits & 1) bits++;  // Round up to even
    return bits;
}
```

#### 2. Feistel Transform

```c
u32 feistel_index(u32 raw_index, u32 block_size) {
    u32 half = block_size / 2;
    u32 mask = (1 << half) - 1;

    u32 h1 = raw_index >> half;       // Upper half
    u32 h2 = raw_index & mask;        // Lower half

    // Feistel round: f(x) = (x*x + 1) mod 2^half
    u32 f = ((h2 * h2) + 1) & mask;

    // Swap and XOR
    u32 new_h1 = h2;
    u32 new_h2 = h1 ^ f;

    return (new_h2 << half) | new_h1;
}
```

#### 3. Pixel Selection Loop

```c
u32 perm_length = 1 << feistel_block_size(sequence_length);
u32 raw_idx = randomSeed % perm_length;

// Pixel (0,0) is ALWAYS written first
write_pixel(0, 0);

for (int i = 0; i < numPixels; i++) {
    do {
        raw_idx = (raw_idx + 1) % perm_length;
        u32 feistel_idx = feistel_index(raw_idx, block_size);
    } while ((feistel_idx == 0 || feistel_idx >= sequence_length)
             && sequence_length != 1);

    int x = feistel_idx % width;
    int y = feistel_idx / width;
    write_pixel(x, y);
}
return raw_idx;  // New seed for chaining
```

#### 4. Pixel Writing Modes

**When `sourceBitmap == this` (self-referential):**
- Write `fillColor` to the selected pixel
- Premultiply fillColor if bitmap is transparent

**When `sourceBitmap != this`:**
- Copy pixel from source at the same relative position within sourceRect
- Respect source/dest bounds clipping

### Test Case Details

From `bitmap_data_pixeldissolve_image/test.as`:

1. **Self-referential fill**: `dest.pixelDissolve(dest, rect, point, 0, 9999, 0xFF33FF99)` — overwrites own pixels with green fill color
2. **Cross-bitmap copy**: `dest.pixelDissolve(source, rect, point, 0, 9999)` — copies pixels from source to dest
3. **Offset rectangles**: `dest.pixelDissolve(src, Rectangle(30,40,35,55), Point(25,10), 0, 9999)` — partial rect with offset

Test tolerance: 1 (allows single-channel 1-value differences).

### Implementation Steps

#### Step 1: Argument Validation & Extraction (~25 lines)
- Validate arg_count, source bitmap, sourceRect, destPoint
- Extract numeric values (randomSeed, numPixels, fillColor)
- Compute effective region (intersection of source rect with source bounds, dest bounds)
- Return error codes for invalid inputs

#### Step 2: Feistel PRNG (~20 lines)
- `feistel_block_size()` — compute block size from pixel count
- `feistel_index()` — one-round Feistel transform

#### Step 3: Pixel Iteration (~30 lines)
- Write pixel (0,0) unconditionally
- Loop numPixels times, advancing through Feistel permutation
- Skip out-of-bounds indices (feistel generates up to `2^block_size` but region may be smaller)
- Convert 1D index to 2D (x, y) within the effective region

#### Step 4: Pixel Writing (~15 lines)
- Self-referential mode: premultiply fillColor, write to dest
- Cross-bitmap mode: read from source, write to dest
- Handle transparent vs opaque bitmap flags

### Also Needed: BitmapData.merge()

The `bitmap_data_copypixels` test requires `merge()` (currently a stub at `action.c:8897-8905`).

**API:**
```actionscript
bitmapData.merge(sourceBitmap, sourceRect, destPoint, redMult, greenMult, blueMult, alphaMult) : void
```

**Algorithm** (per pixel, per channel):
```c
new_channel = (src_channel * srcMult + dest_channel * (256 - srcMult)) / 256
```

Where `srcMult` is the per-channel multiplier (0-256 range, clamped). This is a simple weighted blend.

**Estimated complexity:** ~40 lines of C (straightforward per-pixel blend).

### Key Ruffle Source Files

| File | Content |
|------|---------|
| `~/CC/ruffle/core/src/bitmap/operations.rs:1767-1984` | pixelDissolve implementation |
| `~/CC/ruffle/core/src/avm1/globals/bitmap_data.rs:1092-1153` | AVM1 entry point |

### Estimated Complexity

Low-medium (~90 lines of C). The Feistel PRNG is simple but must match Flash exactly for deterministic output. The pixel loop is straightforward. The main risk is getting the Feistel function exactly right (f(x) = x*x + 1 with the correct half-piece masking).
