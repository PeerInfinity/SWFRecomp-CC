# Default Instance Names Plan
<!-- TESTS: default_names -->

Last updated: 2026-03-06

## Status: ACTIONABLE — needs investigation

### Overview

Flash auto-assigns instance names ("instance1", "instance2", ...) to scriptable display objects (sprites, buttons, text fields) placed on the timeline without explicit names. Our counter (`ng_auto_instance_counter` in tag_stubs.c:175) is incrementing too aggressively, causing names to be offset.

**Test**: `default_names` — 15/52 (29%). Instance numbers are shifted (expected instance3 but got instance4, etc.) and some output lines are missing entirely.

### Current Implementation

In `tag_stubs.c` lines 1497-1517:
```c
static unsigned int ng_auto_instance_counter = 1;

// In ng_on_place_object2:
if ((is_sprite || is_button || is_tf) && obj->instance_name == NULL) {
    char auto_name[32];
    snprintf(auto_name, sizeof(auto_name), "instance%u", ng_auto_instance_counter++);
    obj->instance_name = strdup(auto_name);
    obj->instance_name_owned = 1;
}
```

There's also `ng_try_reclaim_auto_instance_name()` which decrements the counter if a removed object's name was the most recently assigned.

### Observed Failures

The diff shows:
1. **Counter offset**: Expected `instance3` but got `instance4`, `instance4→instance5`, `instance5→instance6`. Counter is 1 too high starting from line 14.
2. **Missing output**: Lines 19-20 (`Symbol frame 1 (instance6)` and `Symbol frame 1 (instance7)`) are absent — these children don't exist or aren't being placed.
3. **Later sections**: The offset propagates, causing all subsequent names to be shifted.

### Investigation Needed

**Phase 0: Diagnose counter offset**

Determine why the counter is off by 1-2. Possible causes:
1. A non-visible object (e.g., shape placed before sprites) is consuming a counter value even though it's not scriptable
2. A text field or button placed early in the timeline consumes a name that Flash doesn't assign
3. The counter isn't being reset between timeline loops (if the test loops the root timeline)
4. `ng_try_reclaim_auto_instance_name` is failing to reclaim, or reclaiming the wrong name

Debug approach:
- Add temporary trace output showing every `ng_auto_instance_counter++` call with the char_id and depth
- Compare against the expected instance numbering
- Check if non-scriptable objects (shapes, morph shapes) are triggering auto-naming despite the `is_sprite || is_button || is_tf` guard

**Phase 1: Fix counter logic**

Based on Phase 0 findings, fix the counter. Possible fixes:
- Ensure counter resets on timeline loop-back (`gotoFrame(0)` or natural loop)
- Ensure non-scriptable PlaceObject calls don't increment counter
- Fix reclaim logic if it's not working for removed+replaced objects

**Phase 2: Missing children**

Lines 19-20 show `instance6` and `instance7` which are children inside a sprite. If these children aren't being placed, it may be:
- A sprite frame function not executing
- A display list issue with nested sprites
- Related to the "children2" sub-sprite's frame execution

### Expected Outcome

| Phase | Lines Gained | Test Result |
|-------|-------------|-------------|
| Phase 0 | 0 (diagnostic) | 15/52 |
| Phase 1 | +25-30 (name fix) | ~40-45/52 |
| Phase 2 | +7-10 (children) | ~50/52 |

### Dependencies

None for the core counter fix. Missing children might be related to sprite execution ordering (REGISTERCLASS_PLAN territory) but the naming issue itself is standalone.

### Related Tests

- `conflicting_instance_names` — 23/23 PASS (already works correctly)
- `place_and_lookup` — 30/30 PASS (was fixed by video auto-naming exclusion)
- `tab_ordering_children` — 208/208 PASS (fixed by same video auto-naming change)
