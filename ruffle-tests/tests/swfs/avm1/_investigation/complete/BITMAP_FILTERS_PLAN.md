# Bitmap Filters Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTERS
status: complete
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
    status: complete
dependencies: []
blockers: []
-->

Last updated: 2026-04-03

## Status: 548/548 matching lines (100%) — COMPLETE

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

### Final 4 lines fixed (2026-04-02, commit 53c54f5d)

| Fix | Lines Fixed | New Total |
|-----|-----------|-----------|
| ColorMatrixFilter mc.filters[0] — 20-float matrix in display list | +1 | 545 |
| ConvolutionFilter mc.filters[0] — variable-size matrix + params | +1 | 546 |
| GradientBevelFilter mc.filters[0] — gradient arrays in display list | +1 | 547 |
| GradientGlowFilter mc.filters[0] — gradient arrays in display list | +1 | 548 |
| **Total** | **+52** | **548/548** |

### Also Fixed

- **native_subclasses**: 190/191 → PASS (ConvolutionFilter constructor matrix from args)
