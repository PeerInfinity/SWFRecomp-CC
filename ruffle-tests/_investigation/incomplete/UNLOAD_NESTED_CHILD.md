# unload_nested_child — Deferred Unload Timing

**Status**: 4/5 locally, 3/5 CI (ordering issue)
**Remaining issue**: "unload" fires before "go completed" — should fire after

## Test Structure

```
Frame 0: stop(). Place "clip" (sprite_5) at depth 1.
  clip contains: sprite_2 at depth 1 with UNLOAD clip action (traces "unload")
                 sprite_4 ("button") at depth 3 with onRelease = go
Frame 1: RemoveObject("clip"). DoAction: trace "frame 2", trace getVariable("clip")
Frame 2: DoAction: trace "frame 3", stop()
```

User clicks button → `go()` runs:
1. `_root.nextFrame()` — advance root to frame 1
2. `_root.play()` — make root continue playing
3. `trace("go completed")`

### Expected output
```
go completed        ← go() finishes first
unload              ← child unload fires during frame 1 processing
frame 2             ← frame 1's DoAction
_level0.clip        ← clip still findable as pending removal
frame 3             ← frame 2's DoAction
```

### Current output
```
unload              ← fires during ng_executeGotoTagsOnly (inline in nextFrame)
go completed        ← go() continues after nextFrame returns
frame 2
_level0.clip        ← FIXED: recursive child unload detection
frame 3
```

## Root Cause

`_root.nextFrame()` calls `ng_executeGotoTagsOnly()` (action.c:43634) which runs frame 1's tags **inline**, including `tagRemoveObject2` → `fire_recursive_child_unloads` → traces "unload". This happens BEFORE `go()` continues to `trace("go completed")`.

In Flash, `nextFrame()` sets the target frame and defers actual frame processing to the frame loop. The calling script completes first.

## Architecture: How nextFrame Currently Works

```
nextFrame() [action.c:43612]
  ├── Sets: goto_from_action=1, next_frame=1, manual_next_frame=1
  ├── Sets: root_movieclip.currentframe=2
  └── Calls ng_executeGotoTagsOnly() [swf_core.c:176]
        ├── Runs frame tags in catch_up_mode=1 (scripts suppressed)
        │     └── tagRemoveObject2 fires UNLOAD clip actions ← THE PROBLEM
        ├── Sets g_deferred_root_goto=1
        └── Returns to nextFrame(), which returns to go()

go() continues: _root.play(), trace("go completed")

Main frame loop [swf_core.c:822]:
  ├── Sees g_deferred_root_goto=1, skips re-running current frame
  └── Goto catch-up [swf_core.c:830]:
        ├── Re-processes frame 1 with scripts enabled
        │     ├── tagRemoveObject2 fires AGAIN (double-fire risk!)
        │     └── script_3 runs ("frame 2", "_level0.clip")
        └── Continues to frame 2 → script_4 ("frame 3")
```

## Fix Options

### Option A: Suppress UNLOAD clip actions during catch_up_mode

In `tagRemoveObject2` (tag.c:3715-3741), skip `fire_recursive_child_unloads` and the UNLOAD clip_action dispatch when `catch_up_mode=1`. The UNLOAD will fire later when the main loop's goto catch-up re-processes the target frame with `catch_up_mode=0`.

**Pros**: Minimal change, localized to tagRemoveObject2.
**Cons**: Need to verify UNLOAD doesn't double-fire (once suppressed during ng_executeGotoTagsOnly, once during main loop catch-up). Need to check that the `unload` test (52/52 PASS) and other tests aren't broken — many gotos use ng_executeGotoTagsOnly.

**Key concern**: `ng_executeGotoTagsOnly` runs frames 0..target ALL in catch_up_mode. The main loop catch-up ALSO runs frames, but forward gotos only run intermediate frames in catch_up_mode and the target with scripts enabled. If tagRemoveObject2 on the target frame is processed by both paths, UNLOAD would fire during the main loop's pass (correct timing) but the display list entry was already cleared during ng_executeGotoTagsOnly (so the second pass might not find anything to unload).

### Option B: Don't call ng_executeGotoTagsOnly for nextFrame

Change the `nextFrame()` handler to just set flags (`goto_from_action`, `next_frame`, `manual_next_frame`, `currentframe`) WITHOUT calling `ng_executeGotoTagsOnly`. Let the main frame loop's goto catch-up handle everything.

**Pros**: Cleanest semantics — nextFrame just sets the target, loop handles execution.
**Cons**: Many other tests may depend on nextFrame running tags inline (display list updates visible immediately after nextFrame returns). gotoAndStop/gotoAndPlay handlers use the same pattern. Breaking this could regress numerous tests.

### Option C: Queue UNLOAD actions for deferred execution

Instead of firing UNLOAD clip actions immediately in `tagRemoveObject2`, queue them in a deferred action list. Fire the queued actions after the current script completes (before the next frame loop iteration).

**Pros**: Most accurate to Flash behavior. Doesn't change when tags run, only when UNLOAD callbacks execute.
**Cons**: Requires new deferred action queue infrastructure. Need to determine exactly when to flush the queue (after script_N returns? after the frame function returns? at frame boundary?).

## Recommended Approach

**Option A** is the least risky starting point. The key test:

1. In `tagRemoveObject2`, wrap the UNLOAD clip action firing (lines 3715-3741) in a `if (!catch_up_mode)` guard.
2. Run the `unload` test (52/52) to check for regressions.
3. Run `unload_nested_child` to verify the ordering fix.
4. Run broader regression suite.

If Option A causes double-fire issues (UNLOAD fires during both ng_executeGotoTagsOnly and main loop catch-up), fall back to Option C.

## Files to Modify

- `SWFModernRuntime/src/libswf/tag.c` — `tagRemoveObject2` UNLOAD dispatch
- Possibly `SWFModernRuntime/src/libswf/swf_core.c` — `ng_executeGotoTagsOnly` or main loop

## Related Tests

- `unload` (52/52 PASS) — primary regression target
- `clip_events` (18/18 PASS) — clip event UNLOAD
- `bad_placeobject_clipaction` — clip action handling
- `goto_frame`, `goto_frame2`, `goto_methods` — goto dispatch
- `execution_order2`, `execution_order3`, `goto_execution_order2` — execution ordering
