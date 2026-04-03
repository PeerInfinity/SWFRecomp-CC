# bitmap_filters mc.filters[0] Initial Read Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTERS_MCFILTERS
status: complete
phases:
  - id: 1
    name: "Fix PlaceObject3 flags2 bit positions"
    status: complete
  - id: 2
    name: "Build filter ASObjects from display list data"
    status: complete
dependencies:
  - plan: BITMAP_FILTERS
    type: continues
    reason: "Remaining 4 lines from bitmap_filters (544/548)"
blockers: []
-->

Last updated: 2026-04-02

## Status: COMPLETE — 548/548 PASS

### Phase 1 (completed earlier): PlaceObject3 flags2 bit fix

The recompiler had PlaceObject3 flags2 bits shifted by 1 position. Fixed in both main frame and sprite contexts.

### Phase 2 (completed 2026-04-02): Extended filter data for mc.filters getter

The remaining 4 mismatches were all `mc.filters[0]` reads for filter types not stored in the display list:

1. **ColorMatrixFilter** (line 113) — matrix of 20 floats
2. **ConvolutionFilter** (line 156) — matrixX/Y, matrix array, divisor, bias, preserveAlpha, clamp, color, alpha
3. **GradientBevelFilter** (line 411) — colors/alphas/ratios arrays + common props
4. **GradientGlowFilter** (line 484) — colors/alphas/ratios arrays + common props

#### Implementation

**Runtime (tag.c, tag.h):**
- Added `ExtFilterData` struct with fields for all 4 extended filter types
- Added global side table `g_ext_filters[32]` with depth-indexed lookup
- New tag functions: `tagSetFilterColorMatrix`, `tagSetFilterConvolution`, `tagSetFilterGradient`
- Accessor: `ng_getExtFilterData(entry_idx)` returns const pointer or NULL

**Recompiler (swf.cpp):**
- Modified SWF filter type 4 (GradientGlow), 5 (Convolution), 6 (ColorMatrix), 7 (GradientBevel) parsing to store full data
- Emits new tag function calls with array data via C compound literals
- Fixed quality mask: 0x1F → 0x0F for GradientGlow/GradientBevel (4-bit UB[4], not 5-bit)
- Fixed flag extraction: bits 7/6/5/4 for InnerShadow/Knockout/CompositeSource/OnTop
- Added `flit()` / `dlit()` helpers for float literal emission (ensures decimal point for `f` suffix)

**mc.filters getter (action.c):**
- Extended `g_filter_protos_by_type` array from 5 to 9 entries
- Added ext filter check before simple filter check
- Constructs proper ASObjects for each extended type with correct properties
- Fixed type determination: ON_TOP → "full" (matching Ruffle), not (inner && onTop)

#### Bug fixes along the way
- SWF ConvolutionFilter flags: Clamp is bit 1, PreserveAlpha is bit 0 (was swapped)
- GradientGlow/GradientBevel quality bits: UB[4] not UB[5] (mask 0x0F not 0x1F)
- BevelFilter/GradientFilter type: Ruffle uses ON_TOP alone for "full" (not inner&&onTop)
