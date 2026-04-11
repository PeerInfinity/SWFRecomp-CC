# Filters Multi-Filter Support — Prompt for New Instance

## Task

Implement multi-filter support so `mc.filters` returns all SWF-authored filters, not just the first one. This fixes the Shumway `filters` test (`ruffle-tests/tests/swfs/from_shumway/avm1/filters/`).

## Background

Read these docs first:
- `ruffle-tests/tests/swfs/_investigation/SESSION_START_GUIDE.md`
- `CLAUDE.md`

The test SWF has 7 filters on a MovieClip (DropShadow, Blur, Glow, Bevel, GradientGlow, GradientBevel, ColorMatrix). The test reads `sym1.filters` and dumps each filter's properties. Currently we return `Filters (0)` for the SWF-authored section because only the first filter is stored and the getter only returns one.

## Root Cause — Three Layers Are Broken

### Layer 1: Recompiler (`SWFRecomp/src/swf.cpp`, lines ~2962-3270)

The recompiler parses all 8 SWF filter types (cases 0-7 in the switch at line 2968), BUT each case has `if (parsed_filter_type == 0)` which means only the FIRST filter's data is kept. Similarly `ext_filter_type == 0` for extended filters.

After parsing, the emission code (lines 3544-3649) emits at most ONE `tagSetFilter()` + ONE extended filter call (`tagSetFilterColorMatrix`/`tagSetFilterConvolution`/`tagSetFilterGradient`).

### Layer 2: Runtime tag storage (`SWFModernRuntime/src/libswf/tag.c`)

`tagSetFilter` (line ~4261) stores filter data in scalar fields on `display_list[depth]` (filter_type, filter_blur_x/y, filter_quality, etc.). Extended filters use a separate `g_ext_filters` array. Both assume ONE filter per depth.

### Layer 3: Runtime getter (`SWFModernRuntime/src/actionmodern/action.c`, lines ~40412-40642)

The `mc.filters` getter for SWF-authored filters checks for extended filters first, then simple filters. Each path wraps ONE filter in a 1-element array and returns immediately — no accumulation loop.

## Recommended Approach

**Don't try to store multiple scalar filter fields per depth.** Instead:

### New design: store a pre-built filter ASArray on the display entry

1. **Recompiler**: Instead of emitting `tagSetFilter(depth, type, ...)` calls with scalar parameters, emit code that:
   - Constructs each filter as an ASObject with the correct properties (using the existing filter constructor infrastructure)
   - Builds an ASArray containing all filters
   - Stores the array via a new `tagSetFilterArray(app_context, depth, array)` call

2. **Runtime tag storage**: Add `tagSetFilterArray(SWFAppContext*, size_t depth, ASArray* filters)` that stores the array pointer on the display entry (new field `display_list[depth].filter_array` or similar).

3. **Runtime getter**: Before checking the scalar filter fields, check if the display entry has a `filter_array`. If so, clone and return it. The scalar paths remain as fallback for the existing `tagSetFilter` calls.

### Alternative simpler approach

If constructing ASObjects in generated tag code is too complex, the recompiler could emit a series of calls to populate an array:

```c
tagBeginFilterList(app_context, depth, 7);  // start list of 7 filters
tagAddDropShadowFilter(app_context, depth, distance, angle, ...);
tagAddBlurFilter(app_context, depth, blurX, blurY, quality);
tagAddGlowFilter(app_context, depth, color, alpha, ...);
// etc.
tagEndFilterList(app_context, depth);  // finalize
```

Each `tagAdd*Filter` constructs the filter ASObject and appends to the list. `tagEndFilterList` stores the completed array on the display entry.

## Key Files

| File | What to change |
|------|---------------|
| `SWFRecomp/src/swf.cpp` lines 2962-3649 | Remove `if (parsed_filter_type == 0)` guards; collect ALL filters; emit multi-filter code |
| `SWFModernRuntime/src/libswf/tag.c` lines ~4261-4380 | Add new `tagSetFilterArray` or `tagBeginFilterList`/`tagAdd*` functions |
| `SWFModernRuntime/src/libswf/tag.h` | Declare new functions |
| `SWFModernRuntime/include/libswf/swf.h` | Add `filter_array` field to DisplayObject if needed |
| `SWFModernRuntime/src/actionmodern/action.c` lines ~40412-40642 | Check display entry's filter array before scalar fallback |

## Existing Infrastructure to Reuse

- **Filter constructors** in `action.c` (`invokeNativeSuperConstructor`, lines ~44279+): All 9 filter types are fully implemented with correct default values and property initialization. The `NATIVE_FILTER` type and filter subclass constructors (DropShadowFilter through DisplacementMapFilter) can be used to create filter objects.

- **Filter property setters** in `action.c` (lines ~35903+): Full validation/clamping for all filter properties (angle wrapping, color bounds, alpha quantization, etc.).

- **mc.filters getter clone logic** (lines ~40415-40436): The AS-set path already clones filter arrays correctly. Reuse this for the SWF-authored path.

- **Existing tagSetFilter/tagSetFilterColorMatrix/etc.**: Keep these as fallback for backwards compatibility with existing recompiled test code. The new multi-filter path should be additive.

## Test

```bash
python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/from_shumway/avm1 --test=filters --diff --verbose
```

Expected: 149/149 lines match. Currently: 3/149.

Also check for regressions:
```bash
python3 ruffle-tests/verify_output.py --test=bitmap_filters --diff --verbose
```

The `bitmap_filters` AVM1 test exercises filter construction (not SWF-authored reading) and should continue to pass.

## Scope

This is a cross-cutting change across recompiler (C++) and runtime (C). Expect ~200-400 lines of new code. The recompiler changes are the most complex (SWF binary parsing + C code generation). The runtime changes are straightforward if using the pre-built array approach.
