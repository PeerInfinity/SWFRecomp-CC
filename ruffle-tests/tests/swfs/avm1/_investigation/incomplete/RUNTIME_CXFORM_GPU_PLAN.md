# Runtime Color Transform (cxform) GPU Updates Plan
<!-- TESTS: color, display_object_properties -->

Last updated: 2026-03-27

## Status: PARTIALLY WORKING — Per-frame upload exists, but gaps remain

### Problem

When ActionScript calls `Color.setRGB()`, `Color.setTransform()`, or sets `_alpha`, the display object's `cx_*` fields are updated and `cx_overridden = 1` is set. The per-frame render loop in `tag.c` already detects `cx_overridden` and uploads dynamic cxform slots to the GPU. However, there are gaps in parent-child cxform composition and potential slot exhaustion issues.

### Affected Image Tests

| Test | Tolerance | Notes |
|------|-----------|-------|
| color | 1 | 3 grey rectangles instead of pink/yellow/blue; also needs runtime transform fix |
| display_object_properties | 90 | Partial — alpha changes may not render correctly |

### Current Infrastructure (What Already Works)

The cxform pipeline is more complete than the transform pipeline:

1. **Display object fields**: `DisplayObject` has `cx_ra/ga/ba/aa` (multipliers, percentage 0-100) and `cx_rb/gb/bb/ab` (addends, 0-255), plus `cx_overridden` flag (`swf.h:160-162`)
2. **Runtime setters**: `Color.setRGB()` (`action.c:7728-7767`), `Color.setTransform()` (`action.c:7635-7695`), and `_alpha` (`action.c:31342-31356`) all write to MC and display object fields
3. **Display list sync**: `ng_setColorTransform()` (`tag_stubs.c:2707-2725`) writes all 8 cx_* fields and sets `cx_overridden = 1`
4. **Per-frame GPU upload**: `tag.c:1725-1738` scans display list for `cx_overridden` entries, builds GPU-format cxform via `build_cxform_from_obj()`, allocates dynamic cxform slot, uploads via `renderer_write_cxform()`
5. **GPU buffer**: Over-allocated with 256 extra dynamic slots (`render_webgpu.c:723-738`)
6. **Shader**: Fragment shader applies cxform via `apply_cxform()` — 4x4 mult matrix + addend vec4 (`render_webgpu.c:139-144`)

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| Cxform buffer init | `render_webgpu.c` | 723-738 |
| GPU write function | `render_webgpu.c` | 1993-2000 (`render_webgpu_write_cxform`) |
| Per-frame upload loop | `tag.c` | 1725-1738 |
| build_cxform_from_obj | `tag.c` | 946-959 |
| Cxform override stack | `tag.c` | 890-916 |
| Color.setRGB() | `action.c` | 7728-7767 |
| Color.setTransform() | `action.c` | 7635-7695 |
| _alpha setter | `action.c` | 31342-31356 |
| ng_setColorTransform | `tag_stubs.c` | 2707-2725 |
| ng_setCTAlpha | `tag_stubs.c` | 2727-2733 |
| DisplayObject cx_* fields | `swf.h` | 160-162 |
| Shader apply_cxform | `render_webgpu.c` | 139-144 |

### Remaining Gaps

#### Gap 1: Parent-Child Cxform Composition

**Current behavior** (`tag.c:1003-1007`): When rendering a sprite's children, if the parent has an overridden cxform, the child's cxform_id is simply set to the parent's cxform_id. This replaces the child's cxform rather than composing parent × child.

**Correct behavior**: Flash composes cxforms: `result_mult = parent_mult * child_mult`, `result_add = parent_mult * child_add + parent_add`. This matters when both parent and child have non-identity cxforms.

**Fix**: In `compose_children()`, when parent has a non-identity cxform AND child has its own cxform, compute the composed cxform and write to a new dynamic slot.

```c
// Cxform composition: result = parent ∘ child
// Multipliers: result_r = parent_ra * child_ra / 100
// Addends: result_rb = parent_ra * child_rb / 100 + parent_rb (approximately)
```

#### Gap 2: Dynamic Cxform Slot Exhaustion

**Current behavior**: 256 dynamic cxform slots are pre-allocated. If more than 256 display objects have runtime cxform changes in a single frame, the upload is silently skipped (`tag.c:1731-1737`).

**Fix**: For the image tests this is unlikely to be a problem (small scenes), but a warning or slot expansion would be more robust for complex SWFs. Low priority.

#### Gap 3: Cxform for Runtime-Created Display Objects

**Current behavior**: The per-frame upload loop scans `display_list[1..max_depth]` for `cx_overridden`. Runtime-created children (e.g., via `createEmptyMovieClip`, `attachMovie`) that aren't in the tag display list may not be scanned.

**Fix**: Ensure `actionIterateDrawings()` or an equivalent callback also checks cxform state for child_mc_cache entries.

### Implementation Plan

#### Step 1: Verify existing per-frame upload works for simple cases

Test with `color` test (after runtime transform fix is also applied):
```bash
python3 ruffle-tests/verify_output.py --test=color --headless --diff --verbose
```

The `color` test uses `Color.setRGB()` and `Color.setTransform()` on timeline-placed rectangles. The per-frame upload loop should already handle this if the display objects are in the tag display list. Verify and identify what's actually failing.

#### Step 2: Fix parent-child cxform composition (if needed)

If tests show incorrect colors on sprite children, implement proper cxform composition in `compose_children()`:

```c
static void compose_cxform(float out[20], const float parent[20], const float child[20]) {
    // Multiply diagonal (mult × mult)
    out[0]  = parent[0]  * child[0];   // ra
    out[5]  = parent[5]  * child[5];   // ga
    out[10] = parent[10] * child[10];  // ba
    out[15] = parent[15] * child[15];  // aa
    // Addends: parent_mult * child_add + parent_add
    out[16] = parent[0]  * child[16] + parent[16];  // rb
    out[17] = parent[5]  * child[17] + parent[17];  // gb
    out[18] = parent[10] * child[18] + parent[18];  // bb
    out[19] = parent[15] * child[19] + parent[19];  // ab
    // Off-diagonal remains 0
    out[1]=out[2]=out[3]=out[4]=out[6]=out[7]=out[8]=out[9]=out[11]=out[12]=out[13]=out[14]=0;
}
```

#### Step 3: Verify with color test

The `color` test expects 3 colored rectangles (pink, yellow, blue) modified via `Color.setRGB()` and `Color.setTransform()`. After both this plan and RUNTIME_TRANSFORM_GPU_PLAN are implemented, all 3 should render correctly.

### Dependencies

- Complementary to RUNTIME_TRANSFORM_GPU_PLAN.md — `color` test needs both fixes
- The per-frame cxform upload infrastructure already exists, so this may be partially working already

### Estimated Complexity

Low. The infrastructure is largely in place. The main work is:
1. Testing what already works with the existing per-frame upload (~1 hour investigation)
2. Implementing cxform composition if needed (~20 lines)
3. Extending child_mc_cache scanning if needed (~10 lines)
