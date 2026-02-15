# Unload / UnloadMovie Implementation Plan
<!-- TESTS: unload_clip_event, unload_nested_child, unload, unloadmovie, unloadmovie_method, unloadmovienum, clip_events, clip_event_propagation_order, movieclip_depth_methods, remove_movie_clip, attach_movie, empty_movieclip_can_attach_movies -->

Last updated: 2026-02-14

## Overview

There are 6 failing Ruffle tests related to unloading movie clips. Three tests (`unload`, `unload_clip_event`, `unload_nested_child`) test timeline-based clip removal with onUnload event dispatch. Three tests (`unloadmovie`, `unloadmovie_method`, `unloadmovienum`) test runtime movie loading/unloading which requires loadMovie infrastructure that is out of scope.

**Current state**: In NO_GRAPHICS mode, `tagPlaceObject2WithClipActions` is a complete no-op (doesn't place the clip OR store clip actions), `tagRemoveObject2` removes from `ng_display` but never fires unload events, `actionRemoveSprite` does nothing, and `getDepth()` always returns 0. No onUnload handlers (either clip events or AS-set handlers) are ever called.

**Key insight**: The first 3 tests are fixable with targeted changes to existing infrastructure. The last 3 require loadMovie/loadMovieNum which is a larger feature (network-dependent). We should focus on the first 3.

---

## Test Inventory (6 tests)

### Fixable Tests (3 tests)

| Test | Expected Lines | Current Match | Frames | Key Features Needed |
|------|---------------|---------------|--------|-------------------|
| unload_clip_event | 4 | 0/4 (0%) | 2 | Clip action unload dispatch, onUnload handler invocation |
| unload_nested_child | 5 | ~1/5 (20%) | 3 | Nested clip unload events, clip action dispatch inside sprites |
| unload | 52 | 0/52 (0%) | 4 | getDepth(), getNextHighestDepth(), createEmptyMovieClip depth tracking, removeMovieClip, onUnload handlers, clip action unload dispatch |

### Network-Dependent Tests (3 tests -- deferred)

| Test | Expected Lines | Frames | Why Deferred |
|------|---------------|--------|-------------|
| unloadmovie | 4 | 11 | Uses GetURL2 to load external SWF into _level1 |
| unloadmovie_method | 3 | 11 | Calls unloadMovie() method, loads external SWF |
| unloadmovienum | 13 | 4 | Uses GetURL with _level1 targets, loads external SWF |

---

## Root Causes Analysis

### Problem 1: `tagPlaceObject2WithClipActions` is a no-op in NO_GRAPHICS

**File**: `SWFModernRuntime/src/libswf/tag_stubs.c:458-463`

```c
void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count)
{
    (void)app_context; (void)depth; (void)char_id; (void)transform_id;
    (void)cxform_id; (void)clip_depth; (void)clip_actions; (void)clip_action_count;
}
```

This means clips placed with clip actions (like the `unload_clip_event` test's clip at depth 1) are never added to the display list at all. The clip doesn't exist, so it can't be found by name, and when `tagRemoveObject2` runs there's nothing to remove.

**Impact**: `unload_clip_event` (clip never placed), `unload` (clip at depth 1 with UNLOAD clip action never placed), `unload_nested_child` (nested clip with UNLOAD clip action never placed).

### Problem 2: No clip action storage in `ng_display`

The `ng_display` struct has no fields for clip actions:

```c
static struct {
    size_t depth;
    size_t sprite_idx;
    size_t current_frame;
    int is_playing;
    int needs_init;
    size_t placed_at_frame;
    u32 transform_id;
    int is_button;
    int is_textfield;
    int textfield_idx;
    char instance_name[64];
} ng_display[MAX_DISPLAY_NG];
```

Even after fixing Problem 1, there's nowhere to store the clip actions for later dispatch during removal.

### Problem 3: `tagRemoveObject2` doesn't fire unload events

**File**: `SWFModernRuntime/src/libswf/tag_stubs.c:768-791`

The function removes the entry from `ng_display` but never checks for or dispatches clip action unload handlers or AS-set `onUnload` handlers.

### Problem 4: `actionRemoveSprite` is a no-op

**File**: `SWFModernRuntime/src/actionmodern/action.c:~12722`

Pops the target name from the stack but doesn't actually remove anything in NO_GRAPHICS mode.

### Problem 5: `getDepth()` always returns 0

**File**: `SWFModernRuntime/src/actionmodern/action.c:~16120`

Stub implementation that always pushes 0.0. Flash's `getDepth()` returns `swf_depth - 16384` (so SWF depth 1 -> -16383, SWF depth 3 -> -16381, etc.). Dynamically created clips at AS depth N have `getDepth()` = N.

### Problem 6: `getNextHighestDepth()` always returns 0

**File**: `SWFModernRuntime/src/actionmodern/action.c:~16130`

Stub. Should scan the display list and return `max(0, highest_occupied_depth + 1)` in ActionScript depth space.

### Problem 7: `removeMovieClip` method not handled

Listed in MovieClip.prototype but no actual handler in the method dispatch chain. The method exists as a named function but when called, it falls through to the generic "unhandled method" path and does nothing.

### Problem 8: onUnload AS handler not invoked

When a clip is removed (by `tagRemoveObject2` or `removeMovieClip`), the AS-set `onUnload` handler (set via `clip.onUnload = function() {...}`) is never looked up or called.

### Problem 9: Unused `clip_actions` arrays in recompiled code

The recompiler generates clip_actions arrays (e.g., `clip_actions_19` in the `unload` test) but doesn't always attach them to the correct `tagPlaceObject2WithClipActions` call. In the `unload` test, clip5 at depth 5 should be placed with `clip_actions_19` but is placed with `tagPlaceObject2` instead. This appears to be a recompiler bug where the PlaceObject2 tag for clip5 has clip actions in the SWF but the recompiler emits a plain `tagPlaceObject2` call.

---

## Implementation Plan

### Phase 1: Fix PlaceObject2WithClipActions + Store Clip Actions

**Goal**: Make clips placed with clip actions actually appear in the display list, with their clip actions stored for later dispatch.

#### 1a. Add clip action fields to `ng_display`

In `tag_stubs.c`, add clip action storage to the `ng_display` struct:

```c
static struct {
    // ... existing fields ...
    ClipAction* clip_actions;      // pointer to static clip_actions array (from tagMain.c)
    size_t clip_action_count;
} ng_display[MAX_DISPLAY_NG];
```

The `clip_actions` pointer references the static array defined in the generated `tagMain.c` (e.g., `clip_actions_11[]`). No dynamic allocation needed -- these arrays have program lifetime.

#### 1b. Implement `tagPlaceObject2WithClipActions`

Delegate to `tagPlaceObject2` for placement, then store the clip actions on the display entry:

```c
void tagPlaceObject2WithClipActions(SWFAppContext* app_context, size_t depth, size_t char_id,
    u32 transform_id, u32 cxform_id, u16 clip_depth, ClipAction* clip_actions, size_t clip_action_count)
{
    tagPlaceObject2(app_context, depth, char_id, transform_id, cxform_id, clip_depth);
    // Store clip actions on the display entry
    for (size_t i = 0; i < ng_display_count; i++) {
        if (ng_display[i].depth == depth) {
            ng_display[i].clip_actions = clip_actions;
            ng_display[i].clip_action_count = clip_action_count;
            return;
        }
    }
}
```

#### 1c. Initialize clip_actions to NULL in `tagPlaceObject2`

Ensure new entries and replacements in `tagPlaceObject2` initialize `clip_actions = NULL; clip_action_count = 0;`.

#### Tests fixed by Phase 1 (partial)

This alone doesn't fire unload events, but it ensures clips are placed correctly. `unload_clip_event` will at least have the clip in the display list. `unload_nested_child`'s nested clip will be placed.

### Phase 2: Fire Unload Events on Removal

**Goal**: When a clip is removed by `tagRemoveObject2`, fire both clip action unload handlers and AS-set `onUnload` handlers, in the correct order.

#### Critical: Dispatch Order

From the `unload_clip_event` test, the expected output is:
```
unload clipEvent       <- from onClipEvent(unload) clip action
unload clipEvent end   <- from onClipEvent(unload) clip action
unload handler         <- from AS-set onUnload function
unload handler end     <- from AS-set onUnload function
```

The clip action body (`clip_action_1`) traces "unload clipEvent", calls `_root.stop()`, then traces "unload clipEvent end". The AS-set onUnload handler runs AFTER the clip action completes. This means:

1. **First**: fire all clip action UNLOAD events (onClipEvent(unload) handlers from PlaceObject2WithClipActions)
2. **Then**: fire the AS-set onUnload handler (from `clip.onUnload = function()`)

The clip action's call to `_root.stop()` does NOT call onUnload -- it's a separate function call. The onUnload handler fires as a separate dispatch step after all clip actions complete.

#### 2a. Dispatch unload events in `tagRemoveObject2`

Before removing the entry from `ng_display`, fire unload events in order:

```c
void tagRemoveObject2(SWFAppContext* app_context, size_t depth)
{
    // ... existing catch-up guard ...

    for (size_t i = 0; i < ng_display_count; i++) {
        if (ng_display[i].depth == depth) {
            // Step 1: Fire clip action UNLOAD events
            if (ng_display[i].clip_actions != NULL) {
                for (size_t a = 0; a < ng_display[i].clip_action_count; a++) {
                    if (ng_display[i].clip_actions[a].event_flags & 0x4) {  // CLIP_EVENT_UNLOAD
                        ng_display[i].clip_actions[a].action(app_context);
                    }
                }
            }

            // Step 2: Fire AS-set onUnload handler
            if (ng_display[i].instance_name[0] != '\0') {
                actionFireOnUnload(app_context, ng_display[i].instance_name);
            }

            // ... existing removal logic (invalidate cache, shift array) ...
        }
    }
}
```

#### 2b. Implement `actionFireOnUnload` helper

In `action.c`, add a helper that looks up a MovieClip by instance name, gets its `onUnload` property, and calls it if it's a function:

```c
void actionFireOnUnload(SWFAppContext* app_context, const char* instance_name)
{
    // Find the MovieClip by instance name
    MovieClip* mc = findMovieClipByName(instance_name);
    if (mc == NULL || mc->dynamic_props == NULL) return;

    // Look up onUnload property
    ActionVar* handler = getProperty(mc->dynamic_props, "onUnload", 8);
    if (handler == NULL || handler->type != ACTION_STACK_VALUE_FUNCTION) return;

    // Call the handler with mc as `this`
    ASFunction* func = (ASFunction*) handler->data.numeric_value;
    // Use invokeSpecialFunction or direct call mechanism
    // ...
}
```

Declare this in `action.h` so `tag_stubs.c` can call it.

#### 2c. Also handle `tagRemoveObject` (currently a no-op)

Make `tagRemoveObject` delegate to `tagRemoveObject2` (they do the same thing in this context).

#### Tests fixed by Phase 2

- **unload_clip_event**: 4/4 -- clip's UNLOAD clip action fires ("unload clipEvent" / "unload clipEvent end"), then AS-set onUnload fires ("unload handler" / "unload handler end")
- **unload_nested_child**: Partial improvement -- the UNLOAD clip action inside the sprite fires ("unload")

### Phase 3: Depth Tracking (getDepth / getNextHighestDepth)

**Goal**: Implement `getDepth()` and `getNextHighestDepth()` with correct Flash depth semantics.

#### Flash Depth Convention

SWF depths are 1-based unsigned values stored in PlaceObject2 tags. Flash's `getDepth()` returns `swf_depth - 16384`:
- SWF depth 1 -> getDepth() = -16383
- SWF depth 3 -> getDepth() = -16381
- SWF depth 5 -> getDepth() = -16379

Dynamically created clips (via `createEmptyMovieClip`/`attachMovie`) use ActionScript depths which map differently:
- AS depth 0 -> SWF depth 16384 -> getDepth() = 0
- AS depth 1 -> SWF depth 16385 -> getDepth() = 1

The `unload` test expected output confirms this:
```
clip.depth = -16383   <- SWF depth 1 (timeline-placed)
clip2.depth = -16381  <- SWF depth 3 (timeline-placed)
clip3.depth = 0       <- dynamic, AS depth 0 (from getNextHighestDepth)
clip4.depth = 1       <- dynamic, AS depth 1 (from getNextHighestDepth)
clip5.depth = -16379  <- SWF depth 5 (timeline-placed)
```

#### 3a. Store depth on MovieClip

Add `int depth;` to the MovieClip struct. Set it:
- For timeline-placed clips: `swf_depth - 16384` (when tagSetInstanceName creates/finds the MovieClip)
- For dynamically created clips: the AS depth argument directly

#### 3b. Implement `getDepth()`

Replace the stub in the MovieClip method dispatch:

```c
else if (method_name_len == 8 && strncmp(method_name, "getDepth", 8) == 0)
{
    if (args != NULL) FREE(args);
    double v = (double)(mc->depth);
    PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
    return;
}
```

#### 3c. Implement `getNextHighestDepth()`

Scan ng_display for the maximum occupied depth in AS space, return highest + 1 (min 0):

```c
else if (method_name_len == 19 && strncmp(method_name, "getNextHighestDepth", 19) == 0)
{
    if (args != NULL) FREE(args);
    int highest = -1;
    for (size_t i = 0; i < ng_display_count; i++) {
        int as_depth = (int)ng_display[i].depth - 16384;
        if (as_depth > highest) highest = as_depth;
    }
    double v = (double)(highest + 1);
    if (v < 0) v = 0;
    PUSH(ACTION_STACK_VALUE_F64, VAL(u64, &v));
    return;
}
```

Note: `getNextHighestDepth()` only considers children of the target clip. For the root timeline this is all of ng_display. For child clips, it would need to scan that clip's children.

#### 3d. Store depth on dynamically created clips

In `createEmptyMovieClip`, store the depth and register in ng_display:

```c
int depth_val = (int) varToDouble(&args[1]);
MovieClip* child = createMovieClip(inst_name, mc);
child->depth = depth_val;  // AS depth

// Also register in ng_display at SWF depth (depth_val + 16384)
// so tagRemoveObject2 and getNextHighestDepth work uniformly
```

#### Tests fixed by Phase 3

- **unload**: Partial -- depth values now correct for all 5 clips
- **movieclip_depth_methods** (collateral): Improved from 66%

### Phase 4: removeMovieClip Implementation

**Goal**: Implement the `removeMovieClip` action (SWF_ACTION_REMOVE_SPRITE, opcode 0x25) and the `removeMovieClip()` MovieClip method.

#### Flash removeMovieClip semantics

- Only removes dynamically created clips (AS depth >= 0, i.e., SWF depth >= 16384)
- Timeline-placed clips (negative AS depth) cannot be removed by removeMovieClip
- Fires onUnload handler on the removed clip (same dispatch as tagRemoveObject2)
- After removal, the clip reference becomes undefined when accessed by name

#### 4a. Implement `actionRemoveSprite` in NO_GRAPHICS mode

```c
void actionRemoveSprite(SWFAppContext* app_context)
{
    ActionVar target;
    popVar(app_context, &target);

    const char* target_name = varToString(&target);
    if (target_name == NULL || target_name[0] == '\0') return;

    // Find in ng_display by instance_name
    for (size_t i = 0; i < ng_display_count; i++) {
        if (strcmp(ng_display[i].instance_name, target_name) == 0) {
            int as_depth = (int)ng_display[i].depth - 16384;
            if (as_depth < 0) return;  // timeline-placed, can't remove
            tagRemoveObject2(app_context, ng_display[i].depth);
            return;
        }
    }
}
```

#### 4b. Implement `removeMovieClip` as a MovieClip method

```c
else if (method_name_len == 15 && strncmp(method_name, "removeMovieClip", 15) == 0)
{
    if (args != NULL) FREE(args);
    if (mc->depth >= 0) {
        size_t swf_depth = (size_t)(mc->depth + 16384);
        tagRemoveObject2(app_context, swf_depth);
    }
    pushUndefined(app_context);
    return;
}
```

#### Tests fixed by Phase 4

- **unload**: More progress -- removeMovieClip on clip3/clip4 works, onUnload fires for clip4
- **remove_movie_clip** (collateral): Improved from 59%

### Phase 5: Investigate Recompiler Issue (clip_actions not attached)

**Goal**: Fix the recompiler bug where clip_actions arrays are generated but not attached to the correct `tagPlaceObject2WithClipActions` call.

In the `unload` test tagMain.c:
- `clip_actions_19` is defined with `{ 0x4, clip_action_3 }` (UNLOAD handler)
- But clip5 at depth 5 is placed with `tagPlaceObject2(app_context, 5, 2, 4, 0, 0)` -- no clip actions
- Should be `tagPlaceObject2WithClipActions(app_context, 5, 2, 4, 0, 0, clip_actions_19, 1)`

Need to investigate PlaceObject2 parsing in `SWFRecomp/src/swf.cpp` to find why clip actions for certain depths are dropped.

**Impact**: `unload` test's "unload clipEvent 2" trace depends on clip5's UNLOAD clip action.

---

## Files to Modify

### Runtime (SWFModernRuntime/)

| File | Changes |
|------|---------|
| `src/libswf/tag_stubs.c` | Add clip_actions/clip_action_count to ng_display struct; implement tagPlaceObject2WithClipActions; fire unload events in tagRemoveObject2; make tagRemoveObject delegate to tagRemoveObject2 |
| `src/actionmodern/action.c` | Implement getDepth, getNextHighestDepth, removeMovieClip method, actionRemoveSprite, actionFireOnUnload helper, depth tracking on createEmptyMovieClip |
| `include/actionmodern/action.h` | Declare actionFireOnUnload |
| `include/actionmodern/variables.h` | Add `int depth;` to MovieClip struct (if not already present) |

### Recompiler (SWFRecomp/) -- Phase 5 only

| File | Changes |
|------|---------|
| `src/swf.cpp` | Fix PlaceObject2 emission to use tagPlaceObject2WithClipActions when clip actions present |

---

## Implementation Priority and Dependencies

```
Phase 1 (PlaceObject2WithClipActions) --> Phase 2 (Fire unload events)
                                               |
Phase 3 (Depth tracking) --------------------+
                                               |
Phase 4 (removeMovieClip) -------------------+

Phase 5 (Recompiler fix) -- independent investigation
```

Phases 1+2 are the minimum useful increment. Phase 3 and 4 can be done in parallel after 1+2.

### Estimated test impact

| Phase | Tests Improved | Notes |
|-------|---------------|-------|
| 1 | 0 (infrastructure) | Clips now placed correctly, but no unload events yet |
| 2 | 1 (unload_clip_event: 4/4) | Clip action UNLOAD dispatch + onUnload handler invocation |
| 1+2 | partial (unload_nested_child) | Nested clip action dispatch |
| 3 | partial (unload) | getDepth/getNextHighestDepth values correct |
| 4 | partial (unload) | removeMovieClip works, more of the unload test passes |
| 5 | partial (unload) | clip_actions_19 properly attached |

**Realistic outcome**: Phases 1-4 should fully fix `unload_clip_event` (4 lines) and substantially fix `unload_nested_child` (~4/5 lines). The `unload` test (52 lines) will likely reach ~60-70% after all phases.

The 3 network-dependent tests are not fixable without loadMovie infrastructure.

---

## Side Effects and Other Tests

The changes in Phases 1-4 may also improve other failing tests:

| Test | Current | Expected Improvement | Why |
|------|---------|---------------------|-----|
| clip_events | 0% | Partial | Depends on clip action dispatch (Phase 2) |
| clip_event_propagation_order | 0/17 | Partial | Same |
| movieclip_depth_methods | 65/98 (66%) | Improved | Depends on getDepth, getNextHighestDepth (Phase 3) |
| remove_movie_clip | 59% | Improved | Depends on removeMovieClip (Phase 4) |
| attach_movie | 43/59 (73%) | Partial | May benefit from getNextHighestDepth (Phase 3) |
| empty_movieclip_can_attach_movies | 8/11 (73%) | Partial | May benefit from depth tracking |

---

## Detailed Test Walkthrough

### unload_clip_event (simplest, 4 lines expected)

**SWF structure** (from recompiled tagMain.c):
- Frame 0: DefineShape(1), DefineSprite(2), PlaceObject2WithClipActions(depth=1, char=2, clip_actions=[{0x4, clip_action_1}]), SetInstanceName("clip")
- Frame 0 DoAction: script_0 sets `clip.onUnload = anonymous_function`
- Frame 1: RemoveObject2(depth=1), script_2 (actionStop)

**String table** (from script_defs.c):
- str_0 = "clip", str_1 = "onUnload", str_2 = "unload handler", str_3 = "stop"
- str_4 = "unload handler end", str_5 = "unload clipEvent", str_6 = "_root"
- str_7 = "unload clipEvent end"

**clip_action_1** (onClipEvent(unload)):
1. Trace "unload clipEvent"
2. Call `_root.stop()` (stops main timeline playback)
3. Trace "unload clipEvent end"

**func2_anonymous_0** (AS-set onUnload handler):
1. Trace "unload handler"
2. Call `arguments.stop()` (no-op on empty arguments array)
3. Trace "unload handler end"

**Expected dispatch on RemoveObject2(1)**:
1. Clip action UNLOAD fires -> clip_action_1 runs -> "unload clipEvent", _root.stop(), "unload clipEvent end"
2. AS-set onUnload fires -> func2_anonymous_0 runs -> "unload handler", no-op, "unload handler end"

**Expected output** (matches exactly):
```
unload clipEvent
unload clipEvent end
unload handler
unload handler end
```

### unload_nested_child (5 lines expected)

**Expected output**:
```
go completed
unload
frame 2
_level0.clip
frame 3
```

**SWF structure**:
- Frame 0: Place sprite_5 at depth 1, named "clip". sprite_5 contains: script_1 (defines "go" function), PlaceObject2WithClipActions(child at depth 1 with {0x4, clip_action_2}), PlaceObject2(child "button" at depth 3)
- Frame 1: RemoveObject2(1), script_3 (traces "frame 2" + GetVariable("clip"))
- Frame 2: script_4 (traces "frame 3", stops)

clip_action_2 traces "unload" when the nested child is removed.

Key complexity: Line 4 shows `_level0.clip` -- the variable "clip" still resolves after removal. This may be because GetVariable("clip") finds a MovieClip object that still exists in memory even though removed from the display list, or because a variable alias was set.

### unload (52 lines, most complex)

**Frame 0** (script_0):
1. Traces "Frame 1:"
2. Creates clip3/clip4 dynamically via createEmptyMovieClip at depths from getNextHighestDepth()
3. Sets clip4.onUnload and clip5.onUnload handlers
4. Traces depths and references for all 5 clips
5. Calls removeMovieClip on clip3 and clip4
6. Traces "End frame 1"

**Between frames**: "Unload clip4" and "Unload clip5" fire

**Frame 1** (script_2 after tag operations):
- RemoveObject2 on depths 3, 5, 1; re-place clip at depth 1
- Traces state: clip still exists (re-placed), clip2/clip3/clip4 undefined, clip5 persists briefly

**Frame 2** (script_4 after RemoveObject2(1)):
- Traces state, "unload clipEvent" and "unload clipEvent 2" fire

**Frame 3** (script_5): All clips undefined, traces "End frame 4", stops

The exact timing of deferred unload events will need empirical verification during implementation.

---

## Design Decisions

1. **Clip action storage**: Use pointer to static arrays from tagMain.c (no allocation). The clip_actions arrays have program lifetime since they're global/static in the generated code.

2. **Unload event ordering**: Clip action handlers fire first, then AS-set onUnload handlers. This matches Flash's behavior as demonstrated by the `unload_clip_event` test.

3. **Depth field location**: Store on MovieClip struct directly rather than looking up from ng_display each time. Simpler and handles dynamic clips that may not have an ng_display entry.

4. **Dynamic clip registration in ng_display**: When `createEmptyMovieClip` creates a clip, register it in ng_display at SWF depth `as_depth + 16384`. This ensures tagRemoveObject2, getDepth, and getNextHighestDepth all work uniformly.

---

## Quick Win Estimate

**Phases 1+2** (fix PlaceObject2WithClipActions + fire unload events) would fix `unload_clip_event` (4 lines) with minimal code changes. This is the smallest useful increment.

**Phases 1-4** together fix `unload_clip_event`, substantially fix `unload_nested_child`, and partially fix `unload`. Estimated new passing lines: ~10 out of 61 total expected lines across the 3 fixable tests.
