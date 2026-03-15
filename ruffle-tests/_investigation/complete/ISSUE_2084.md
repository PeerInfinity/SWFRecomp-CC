# issue_2084 — Nested attachMovie with registerClass

**Status**: COMPLETE — 16/16 (100%) ✅
**Completed**: 2026-03-15

## Test Structure

Uses `registerClass` to bind Main and Column classes to exported sprites, then tests nested `attachMovie` initialization:

1. **Main class** (registered to export "main", char_id=4):
   - `onLoad`: creates two columns via `attachMovie("column", "col_mc_1", 1)` and `attachMovie("column", "col_mc_2", 2)`
   - First column at `_x=10`; second at `_x=100, _width=20` (makes it invisible via xscale=0)

2. **Column class** (registered to export "column", char_id=9):
   - `onLoad`: attaches 4 icon sprites via `attachIcon` method
   - Icons positioned at `_y=20, 40, 60, 80` with various `_width/_height` overrides

3. **Root**: Places "main_mc" (sprite_4) at depth 0 → triggers Main.onLoad → triggers Column.onLoad for each column

## Bugs Fixed

### Bug 1: actionFlushPendingOnLoads array overwrite
Second column's onLoad never fired because nested `attachMovie` calls during the first column's onLoad overwrote the pending onLoad queue (same array, reset to count=0 before dispatch). Fixed by copying the queue locally before dispatching.

### Bug 2: ng_attachMovie bounds missing child transforms
Icon sprites showed `_width=1, _height=1` instead of `20,20`. The bounds computation in `ng_attachMovie` used raw char bounds without applying child transforms (a 20-twip shape placed with a 20x scale transform). Fixed by using `sprite_content_bounds_twips` which accounts for transforms.

### Bug 3: onEnterFrame prototype chain invisible
`actionHasEnterFrameHandlers` and `actionDispatchEnterFrameHandlers` used `getProperty` (direct only) instead of `getPropertyWithPrototype`. The registered class's `onEnterFrame` on the prototype was never found.

### Bug 4: Display list loops skipping depth 0
Six display list iteration functions started at `i=1`, skipping `display_list[0]` where main_mc was placed. This prevented `sprite_initialized` upgrade (stuck at 1) and `enterframe_eligible` flag setting for sprites at SWF depth 0.

### Bug 5: mcGetOriginalBounds missing dynamic children
`mcGetOriginalBounds` couldn't compute bounds for MCs whose children were added via `attachMovie` (not in static display list). Added a fallback that iterates `child_mc_cache` to find children by parent pointer and computes union bounds.

## Files Modified

- `SWFModernRuntime/src/actionmodern/action.c`:
  - `actionFlushPendingOnLoads`: local copy before dispatch
  - `actionHasEnterFrameHandlers` / `actionDispatchEnterFrameHandlers`: prototype chain lookup
  - `mcGetOriginalBounds`: dynamic child bounds fallback
- `SWFModernRuntime/src/libswf/tag.c`:
  - `upgrade_sprite_initialized`, `set_enterframe_eligible_recursive`, `dispatch_enterframe_clip_actions`, `advance_sprite_frames`, `advance_nested_sprite_frames`, `hasClipEnterFrameHandlers_impl`: start loop at i=0
  - `sprite_content_bounds_twips`: made non-static (was static)
- `SWFModernRuntime/src/libswf/tag_stubs.c`:
  - `ng_attachMovie`: use `sprite_content_bounds_twips` for bounds computation
- `SWFModernRuntime/include/libswf/tag.h`:
  - Added `sprite_content_bounds_twips` declaration
