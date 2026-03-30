# Bitmap Filters Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTERS
status: incomplete
phases:
  - id: 1
    name: "Implement filter.clone()"
    status: complete
  - id: 2
    name: "Fix mc.filters round-trip storage/retrieval"
    status: complete
  - id: 3
    name: "Property coercion native getters/setters"
    status: complete
  - id: 4
    name: "Gradient array synchronization"
    status: complete
  - id: 5
    name: "mc.filters[0] initial read from display list"
    status: mostly_complete
dependencies: []
blockers:
  - "4 lines need extended filter infrastructure (ColorMatrix/Convolution/Gradient data in display list)"
-->

Last updated: 2026-03-30

## Status: 544/548 matching lines (99.3%)

### Session Progress (2026-03-30)

Started at: 496/548 (from CI)

| Fix | Lines Fixed | New Total |
|-----|-----------|-----------|
| Angle precision (Ruffle 0.785398163 rad default) | +4 | 500 |
| DisplacementMapFilter default properties + coercions | +13 | 513 |
| Gradient array sync (colors/alphas/ratios coupling) | +12 | 525 |
| Gradient alpha defaults + string colors | +4 | 529 |
| ConvolutionFilter matrix NaN/string/number handling | +4 | 533 |
| ConvMatrix string element parsing | +3 | 536 |
| mapPoint defensive copy (clone on read) | +2 | 538 |
| Gradient persistent backing arrays | +2 | 540 |
| PlaceObject3 flags2 bit positions fix | +0 | 540 |
| Filter flag extraction (MSB-first per SWF spec) | +0 | 540 |
| mc.filters display list getter (Blur/DropShadow/Glow/Bevel) | +1 | 541 |
| Property enumeration order per filter type | +0 | 541 |
| float→double precision chain (display list + recompiler) | +3 | 544 |
| BevelFilter color order (highlight first) | +0 | 544 |
| **Total** | **+48** | **544/548** |

### Remaining 4 Lines

All require extended display list filter data storage:

1. **Line 113 (ColorMatrixFilter)**: Needs 20-float matrix stored in display list
2. **Line 156 (ConvolutionFilter)**: Needs variable-size matrix + divisor/bias/preserveAlpha/clamp/color/alpha
3. **Line 411 (GradientBevelFilter)**: Needs gradient colors/alphas/ratios arrays in display list
4. **Line 484 (GradientGlowFilter)**: Same gradient array requirement

### Also Fixed

- **native_subclasses**: 190/191 → PASS (ConvolutionFilter constructor matrix from args)
