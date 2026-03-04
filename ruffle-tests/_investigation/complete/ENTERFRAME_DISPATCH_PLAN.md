# onEnterFrame Per-Tick Dispatch Plan
<!-- TESTS: issue_1104, string_paths_variable_scopes -->

Last updated: 2026-03-03

## Status: COMPLETE

### Summary

Both phases implemented and passing. Per-tick ENTER_FRAME dispatch now matches Ruffle's
INITIALIZED model: init tick fires LOAD only, subsequent ticks fire ENTER_FRAME.

### Results

| Test | Before | After |
|------|--------|-------|
| issue_1104 | 1/2 | 2/2 PASS |
| string_paths_variable_scopes | 5/5 | 5/5 PASS (already passing, confirmed no regression) |
| clip_events | 18/18 | 18/18 PASS (no regression) |
| create_empty_movie_clip | 3/3 | 3/3 PASS (no regression) |
| execution_order2 | PASS | PASS |
| execution_order3 | PASS | PASS |
| execution_order4 | PASS | PASS |
| set_interval | PASS | PASS |
| unload | PASS | PASS |

### Implementation

#### Phase 1: Per-Tick EnterFrame for Sprites

1. **`swf.h`**: Added `sprite_initialized` field to `DisplayObject` (0=not init, 1=init'd this tick, 2=ready for per-tick dispatch)

2. **`tag.c`**:
   - `process_sprite_needs_init`: Sets `sprite_initialized = 1` (replaces old `enterframe_eligible = 1` on init tick)
   - `upgrade_sprite_initialized()`: Recursively upgrades 1→2 in tagShowFrame (after init tick completes)
   - `advance_sprite_frames()`: Sets `enterframe_eligible = 1` for all sprites with `sprite_initialized >= 2`
   - `dispatch_enterframe_clip_actions()`: Recursive clip event ENTER_FRAME dispatch, gates on `sprite_initialized >= 2`
   - `tagFlushPendingEnterFrame()`: Deferred flush mechanism — dispatches clip actions + AS2 onEnterFrame + root var_map

3. **`swf_core.c`**:
   - Within-frame-list: Sets `g_enterframe_flush_pending = 1` before frame function
   - Stopped-root fallback: Flushes pending ENTER_FRAME when root is stopped (createEmptyMovieClip case)
   - Past-frame-list: Direct dispatch (no frame function to trigger flush)

4. **`swf.cpp`** (recompiler): Emits `tagFlushPendingEnterFrame(app_context);` before each DoAction.
   SWF tag ordering guarantees RemoveObject before DoAction, so flush happens after removes (removed clips skipped) but before scripts.

#### Phase 2: Root MC onEnterFrame via SetVariable

Already working via `actionDispatchRootVarMapEnterFrame()` — no changes needed.

### Key Design Decisions

- **Deferred flush**: Rather than pre-frame dispatch (which fires for soon-to-be-removed clips), ENTER_FRAME is deferred until between RemoveObject and DoAction tags. Recompiler emits the flush call; tagShowFrame has a fallback for old compiled code.
- **2-value initialized flag**: Prevents ENTER_FRAME on init tick (Ruffle fires LOAD, not EnterFrame on first tick). Upgraded 1→2 at end of tagShowFrame.
- **Stopped-root fallback**: When root is stopped and within frame list, no frame function runs, so the flush must happen directly in swf_core.c.
