# bitmap_filters mc.filters[0] Initial Read Plan
<!-- TESTS: bitmap_filters -->

<!-- PLAN_META
id: BITMAP_FILTERS_MCFILTERS
status: in_progress
phases:
  - id: 1
    name: "Fix PlaceObject3 flags2 bit positions"
    status: complete
  - id: 2
    name: "Build filter ASObjects from display list data"
    status: not_started
dependencies:
  - plan: BITMAP_FILTERS
    type: continues
    reason: "Remaining 8 lines from bitmap_filters (540/548)"
blockers: []
-->

Last updated: 2026-03-30

## Status: IN PROGRESS — 540/548, infrastructure in place

### Completed: PlaceObject3 flags2 bit fix

The recompiler had PlaceObject3 flags2 bits **shifted by 1 position** (both main frame and sprite contexts). `HasFilterList` was at bit 1 (0x02) instead of bit 0 (0x01), causing ALL filter data to be silently ignored. Fixed in both `swf.cpp` locations.

After fix, the recompiler correctly emits `tagSetFilter()` and `tagSetFilterHighlight()` calls. The display list's filter fields are populated at runtime. An `ng_getDisplayEntryFilterData()` accessor was also added.

### Remaining: Build filter ASObjects from display list

The mc.filters getter needs to construct filter ASObjects from the display list's filter fields when no script-set filters exist. The initial attempt segfaulted because `invokeNativeSuperConstructor` was called with a stack-allocated dummy ASFunction, which likely caused issues with global state.

**Approach for fix**: Instead of invoking the full constructor pipeline, directly allocate an ASObject, set `native_type = NATIVE_FILTER`, set the correct `__proto__` chain, and populate properties manually. This avoids the constructor machinery and is safer.

**Specific needs per filter type**:
- **BevelFilter** (type 4): distance, angle (radians→degrees), highlightColor/Alpha, shadowColor/Alpha, quality, strength, blurX/Y, knockout, inner, type
- **BlurFilter** (type 1): blurX, blurY, quality
- **DropShadowFilter** (type 2): distance, angle, color, alpha, quality, inner, knockout, blurX/Y, strength, hideObject
- **GlowFilter** (type 3): color, alpha, quality, inner, knockout, blurX/Y, strength
- **GradientBevel/GlowFilter** (types with gradient data): needs gradient array support — currently NOT stored in display list (tagSetFilter only supports simple filters)

### Key Code Locations

| Component | File | Description |
|-----------|------|-------------|
| flags2 fix | `swf.cpp:2682-2691, 3897-3905` | Both main frame and sprite PO3 |
| tagSetFilter emission | `swf.cpp:3408-3438` | Emits filter calls |
| ng_getDisplayEntryFilterData | `tag_stubs.c` | Reads filter fields from display list |
| mc.filters getter | `action.c:~35792` | TODO: build filter objects |
| Filter constructor init | `action.c:invokeNativeSuperConstructor` | For property defaults |

### Estimated Work

~50 lines: create filter object, set __proto__, populate properties from display list data. Gradient filters need additional work (gradient data not in display list).
