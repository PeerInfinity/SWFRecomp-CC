# Default Instance Names Plan
<!-- TESTS: default_names -->

Last updated: 2026-03-06

## Status: COMPLETE — 52/52 PASS

### Overview

Flash auto-assigns instance names ("instance1", "instance2", ...) to scriptable display objects (sprites, buttons, text fields) placed on the timeline without explicit names. Our counter was incrementing too aggressively, causing names to be offset, and child sprites inside named parent sprites weren't running their frame 0 scripts.

**Test**: `default_names` — 52/52 (100%)

### Root Causes Found

1. **Counter waste from explicit names**: The recompiler emitted `tagSetInstanceName` AFTER `tagPlaceObject2`. This meant `ng_on_place_object2` would auto-name the sprite (consuming a counter value), then `tagSetInstanceName` would overwrite it with the explicit name — wasting a counter value. Example: sprite "children" at depth 5 consumed "instance3" before being renamed.

2. **Missing child traces**: `ng_fire_pending_attach_inits` (for attachMovie) didn't recursively init child sprites placed by the frame function, so children of attachMovie'd sprites never ran their frame 0 scripts.

### Fixes Applied

**Fix 1: Recompiler — tagSetInstanceName before tagPlaceObject2** (`SWFRecomp/src/swf.cpp`)

Moved instance name emission BEFORE placement call. This sets `g_pending_instance_name` which `ng_on_place_object2` checks — if set, it uses the pending name instead of auto-generating one, so the counter is not incremented.

Applied in two places: root-level PlaceObject2 emission and sprite definition PlaceObject2 emission.

**Fix 2: Runtime — recursive child init for attachMovie** (`tag_stubs.c`)

Added `process_sprite_needs_init_public()` call in `ng_fire_pending_attach_inits` after running the frame function, so child sprites placed by attachMovie'd sprites get initialized.

**Fix 3: Runtime — public wrapper for process_sprite_needs_init** (`tag.c`)

Added `process_sprite_needs_init_public()` wrapper since `process_sprite_needs_init` is static in tag.c.

### Key Insight

The existing eager init in `tagPlaceObject2` (tag.c) already provides depth-first auto-naming order. When a sprite is placed, tag.c immediately runs its frame 0 with `catch_up_mode=1`, which triggers `ng_on_place_object2` for child sprites — assigning auto-names to children before the parent continues placing siblings. No additional eager init in `tag_stubs.c` was needed.

### Related Tests (no regressions)

- `conflicting_instance_names` — 23/23 PASS
- `place_and_lookup` — 30/30 PASS
- `tab_ordering_children` — 208/208 PASS
- `clip_events` — 18/18 PASS
- `on_construct` — 25/25 PASS
- `execution_order2`, `execution_order3`, `goto_execution_order2` — all PASS
