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
    name: "mc.filters[0] initial read from SWF tags"
    status: blocked
dependencies: []
blockers:
  - "mc.filters[0] initial read requires SWF tag filter data storage (8 lines)"
-->

Last updated: 2026-03-30

## Status: 540/548 matching lines (98.5%) — BLOCKED on SWF tag filters

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
| **Total** | **+44** | **540/548** |

### Remaining Failures (8 lines)

**ALL BLOCKED — mc.filters[0] initial read (lines 15, 90, 113, 156, 289, 360, 411, 484)**

These 8 lines read the initial filters from MovieClips that have SWF-authored filters set via PlaceObject3 tags with filter data. Each expects the filter's property values (e.g., distance, angle, blurX/Y, colors/alphas/ratios for gradient filters).

**Required infrastructure:**
1. Recompiler: parse FILTERLIST from PlaceObject3 tags and emit filter data in tagMain.c
2. Runtime: store filter data on the DisplayObject at placement time
3. mc.filters getter: if no script-set filters, return SWF-authored filters

This is a substantial cross-cutting feature (recompiler + runtime + tag system). Estimated ~200 lines.
