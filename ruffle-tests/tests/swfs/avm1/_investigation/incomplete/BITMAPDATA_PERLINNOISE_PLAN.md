# BitmapData.perlinNoise() Implementation Plan
<!-- TESTS: bitmap_data_perlinnoise (image) -->

<!-- PLAN_META
id: BITMAPDATA_PERLINNOISE
status: not_started
phases:
  - id: 1
    name: "Port LCG and initialization"
    status: not_started
  - id: 2
    name: "Port noise2 function"
    status: not_started
  - id: 3
    name: "Port turbulence function"
    status: not_started
  - id: 4
    name: "Implement bitmapDataPerlinNoise"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-03-28

## Status: NOT STARTED

### Problem

`bitmapDataPerlinNoise()` in `action.c:8919-8928` is a stub that returns immediately without modifying any pixel data. The `bitmap_data_perlinnoise` image test creates 100x100 BitmapData objects, calls `perlinNoise()` with various parameters, and displays them via `attachBitmap()`. The GPU rendering pipeline works (implemented in the BITMAPDATA_RENDERING_PLAN), but all bitmaps are blank because `perlinNoise()` never writes pixels.

### API Signature

```actionscript
bitmapData.perlinNoise(baseX, baseY, numOctaves, randomSeed, stitch, fractalNoise, channelOptions, grayscale, offsets)
```

| Parameter | Index | Type | Default | Description |
|-----------|-------|------|---------|-------------|
| `baseX` | 0 | f64 | required | X frequency divisor (higher = lower frequency) |
| `baseY` | 1 | f64 | required | Y frequency divisor |
| `numOctaves` | 2 | i32 | required | Number of octave layers (clamped to 0 if negative) |
| `randomSeed` | 3 | i32 | required | Seed for LCG random number generator |
| `stitch` | 4 | bool | required | Enable tileable noise (wrapping at bitmap edges) |
| `fractalNoise` | 5 | bool | required | true=fractal sum (additive), false=turbulence (abs values) |
| `channelOptions` | 6 | u8 | 7 (RGB) | Bitmask: 1=R, 2=G, 4=B, 8=A |
| `grayscale` | 7 | bool | false | If true, R/G/B channels share one noise value |
| `offsets` | 8 | Array | null | Array of Point objects for per-octave offsets |

Returns undefined. Minimum 6 args required.

### Algorithm Overview

This is a port of the **W3C SVG feTurbulence reference implementation** (Perlin noise variant). Three main components:

#### 1. Seed-Based Initialization

Linear congruential generator (LCG):
- Constants: `A=16807`, `M=2^31-1=2147483647`, `Q=127773`, `R=2836`
- `seed = A * (seed % Q) - R * (seed / Q); if (seed <= 0) seed += M`
- Seed clamped to [1, M-1] on input

For **4 independent channels**, generate:
- `lattice_selector[256]` — permutation table (Fisher-Yates shuffle)
- `gradient[256][2]` — normalized 2D gradient vectors
- Duplicate entries at index 256 for boundary wraparound

#### 2. 2D Noise Function (`noise2`)

Standard lattice Perlin noise:
1. Add `PERLIN_N=4096` offset, extract integer (`bx0, by0`) and fractional (`rx0, ry0`) parts
2. Smoothstep: `s(t) = t * t * (3 - 2*t)` for both x and y fractions
3. Look up 4 corner gradients via permutation table
4. Dot product of gradient with relative position for each corner
5. Bilinear interpolation with smoothstep weighting
6. If `stitch`: wrap lattice coordinates at tile boundaries

Output range: [-1, 1]

#### 3. Octave Accumulation (`turbulence`)

For each octave k (0..numOctaves-1):
- Frequency doubles each octave: `freq *= 2`
- Amplitude halves: `ratio *= 2` (divide noise by ratio)
- Apply per-octave offset from `offsets` array
- **Fractal noise mode**: `sum += noise / ratio`
- **Turbulence mode**: `sum += abs(noise) / ratio`
- If stitch: double tile width/height each octave

#### 4. Pixel Assembly

For each pixel (x, y):
- **Grayscale**: One noise value shared by R/G/B (separate for A if channelOptions & 8)
- **RGB**: Independent noise per enabled channel (channel counter advances only for included channels — affects RNG state)
- **Float-to-byte conversion**:
  - Fractal: `byte = clamp(((noise * 255 + 255) + 0.5) / 2, 0, 255)`
  - Turbulence: `byte = clamp(noise * 255 + 0.5, 0, 255)`
- Disabled channels default to 0 (R/G/B) or 0xFF (A if not in channelOptions)
- If `transparent == 0`: force alpha to 0xFF
- Premultiply alpha before writing to pixel buffer

### Implementation Steps

#### Step 1: Port LCG and Initialization (~60 lines)
```c
typedef struct {
    int lattice_selector[257];  // permutation table (256 + 1 wrap)
    float gradient[4][257][2];  // gradient vectors per channel
} PerlinState;

void perlin_init(PerlinState* state, int seed);
```

#### Step 2: Port noise2 Function (~50 lines)
```c
float perlin_noise2(PerlinState* state, int channel, float x, float y,
                    int stitch, int stitch_w, int stitch_h);
```

#### Step 3: Port turbulence Function (~40 lines)
```c
void perlin_turbulence(PerlinState* state, float x, float y,
                       float base_freq_x, float base_freq_y,
                       int num_octaves, int fractal_noise, int stitch,
                       int bmp_width, int bmp_height,
                       float* offsets_x, float* offsets_y,
                       float out[4]);
```

#### Step 4: Implement bitmapDataPerlinNoise (~80 lines)
- Parse all 9 arguments with defaults
- Extract offsets array (iterate ASArray, read x/y from Point objects)
- Initialize PerlinState from seed
- Loop over pixels: call turbulence, convert float→byte per channel, apply alpha/premultiply
- Write to `bmp->pixels[]`

### Test Parameters (from the test SWF)

The test creates ~30 bitmaps with varying parameters:
- baseX/baseY: 3-100
- numOctaves: 1-4
- Seeds: various
- All combinations of stitch/fractalNoise/grayscale
- channelOptions: 1, 2, 4, 7, 8, 15

### Key Ruffle Source Files

| File | Content |
|------|---------|
| `~/CC/ruffle/core/src/bitmap/turbulence.rs` | Core Perlin noise (249 lines) |
| `~/CC/ruffle/core/src/bitmap/operations.rs:254-368` | perlin_noise pixel assembly |
| `~/CC/ruffle/core/src/avm1/globals/bitmap_data.rs:729-782` | AVM1 entry point |

### Estimated Complexity

Medium-high (~230 lines of C). The algorithm is well-defined but has subtle details:
- LCG seed normalization
- Gradient normalization during init
- Stitch boundary wrapping with PERLIN_N offsets
- Channel-skip affecting RNG state in non-grayscale mode
- Exact float-to-byte rounding for fractal vs turbulence modes
