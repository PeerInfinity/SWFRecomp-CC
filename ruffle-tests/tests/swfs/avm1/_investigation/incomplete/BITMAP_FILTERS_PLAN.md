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
    status: mostly_complete
  - id: 3
    name: "Property coercion native getters/setters"
    status: mostly_complete
  - id: 4
    name: "Gradient array synchronization"
    status: mostly_complete
dependencies: []
blockers:
  - "mc.filters[0] initial read requires SWF tag filter data storage (8 lines)"
-->

Last updated: 2026-03-30

## Status: IN PROGRESS — 536/548 matching lines (97.8%)

### Session Progress (2026-03-30)

Started at: 496/548 (from CI, prior session)

| Fix | Lines Fixed | New Total |
|-----|-----------|-----------|
| Angle precision (Ruffle 0.785398163 rad default) | +4 | 500 |
| DisplacementMapFilter default properties + coercions | +13 | 513 |
| Gradient array sync (colors/alphas/ratios coupling) | +12 | 525 |
| Gradient alpha defaults + string colors | +4 | 529 |
| ConvolutionFilter matrix NaN/string/number handling | +4 | 533 |
| ConvMatrix string element parsing (valid number strings) | +3 | 536 |
| **Total** | **+40** | **536/548** |

### Remaining Failures (12 lines)

**BLOCKED — mc.filters[0] initial read (8 lines: 15, 90, 113, 156, 289, 360, 411, 484)**
Reading filters from MC's that have SWF-authored filters (from PlaceObject3 tags). Requires storing filter data from the tag system and returning it via the mc.filters getter. This is a significant infrastructure addition.

**mapPoint defensive copy (2 lines: 278, 280)**
`f.mapPoint == f.mapPoint` should return `false` (each read returns a new clone). Currently returns `true`. Requires getter interception for NATIVE_FILTER objects in actionGetMember.

**Gradient internal array persistence (4 lines: 445, 518 × 2)**
When `colors` is set to expand num_colors, old alpha/ratio values should be preserved from the internal arrays. Current implementation creates new arrays each time, losing old values. Requires persistent fixed-size internal storage (like Ruffle's approach).
