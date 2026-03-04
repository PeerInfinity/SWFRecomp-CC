# onEnterFrame Per-Tick Dispatch Plan
<!-- TESTS: issue_1104, string_paths_variable_scopes -->

Last updated: 2026-03-03

## Status: INCOMPLETE — Architecture change needed

### Overview

onEnterFrame currently fires only during sprite initialization, not on subsequent ticks.
Ruffle fires EnterFrame unconditionally every tick after the INITIALIZED flag is set.
This blocks `issue_1104` (1/2) and `string_paths_variable_scopes` (0/5).

### Current Architecture (Flag-Based)

The current system uses a **consumed flag** model:

1. **`enterframe_eligible`** flag on DisplayObject — set by:
   - `process_sprite_needs_init()` (tag.c:279) — init tick
   - `advance_sprite_frames()` manual goto (tag.c:475)
   - `advance_sprite_frames()` natural advance (tag.c:516)

2. **`actionDispatchEnterFrameHandlers()`** (action.c:16167-16262):
   - Iterates all cached MovieClips
   - Checks `dobj->enterframe_eligible` flag
   - Fires `onEnterFrame` handler if found
   - **Consumes the flag** (`dobj->enterframe_eligible = 0` at line 16185)

3. **Dispatch called from** (swf_core.c):
   - Line 562: when root MC stops (within frame list)
   - Line 587: past frame list (loop for timers/events)

**Problem**: The flag is consumed after dispatch and only re-set when the sprite advances.
One-frame sprites that aren't playing never advance, so EnterFrame fires only once.

### Ruffle Architecture (INITIALIZED-Based)

From `movie_clip.rs` lines 424-441:

```rust
pub fn run_frame_avm1(self, context: &mut UpdateContext<'gc>) {
    let is_load_frame = !self.0.contains_flag(MovieClipFlags::INITIALIZED);
    if is_load_frame {
        self.event_dispatch(context, ClipEvent::Load);
        self.0.set_initialized(true);
    } else {
        self.event_dispatch(context, ClipEvent::EnterFrame);  // EVERY tick after init
    }
    if self.playing() {
        self.run_frame_internal(context, true, true, false);
    }
}
```

**Key difference**: INITIALIZED is a **persistent flag** (set once, never cleared). After init,
EnterFrame fires unconditionally every tick — no eligibility check, no consumption.

### Blocked Tests

| Test | Lines | Match | Specific Issue |
|------|-------|-------|---------------|
| issue_1104 | 2 | 1/2 | 3-frame test. onEnterFrame fires on frame 1 but not frame 2. Expects 2 lines. |
| string_paths_variable_scopes | 5 | 0/5 | onEnterFrame set via SetVariable on root MC; dispatcher can't find it (variable-table vs dynamic_props disconnect) |

### Also Affects
- FOCUS_SYSTEM_PLAN: focus_keyboard_press (partially — event pumping model difference)
- Any test with MC.onEnterFrame that expects per-tick firing

---

## Phase 1: Per-Tick EnterFrame for Sprites

**Goal**: EnterFrame fires every tick after initialization, matching Ruffle's INITIALIZED model.

### Implementation

#### 1a. Add `initialized` flag to DisplayObject/MovieClip

In `swf.h`, add to `DisplayObject` struct:
```c
u8 sprite_initialized;  // Set once after first frame execution
```

Set this flag in `process_sprite_needs_init()` (tag.c) after the sprite's first frame runs:
```c
// After running init script and setting enterframe_eligible:
obj->sprite_initialized = 1;
```

#### 1b. Change dispatch condition

In `actionDispatchEnterFrameHandlers()` (action.c:16167-16262):

**Before:**
```c
if (dobj != NULL && dobj->enterframe_eligible) {
    dobj->enterframe_eligible = 0;  // consume
    // dispatch onEnterFrame
}
```

**After:**
```c
if (dobj != NULL && dobj->sprite_initialized) {
    // dispatch onEnterFrame (no consumption — fires every tick)
}
```

Keep `enterframe_eligible` for the **first-tick suppression** case (createEmptyMovieClip shouldn't fire onEnterFrame on creation tick — test `create_empty_movie_clip`). The `sprite_initialized` flag handles subsequent ticks.

#### 1c. Ensure dispatcher is called every tick

Currently `actionDispatchEnterFrameHandlers()` is called from two places in swf_core.c:
- Line 562: within frame list (after tagShowFrame)
- Line 587: past frame list (timer/event loop)

Both paths already call it per-tick, so no change needed here. But verify that the "within frame list" path calls it for every ShowFrame, not just when root stops.

### Risk Assessment

**Regression risk**: Medium. Changing from consumed-flag to persistent-flag could cause:
- Tests expecting EnterFrame to fire exactly once (currently correct by accident)
- Performance increase (more dispatch calls per frame)
- Ordering changes if dispatch happens at different points

**Mitigation**: Keep `enterframe_eligible` as a first-tick gate alongside `sprite_initialized`.
The logic becomes:
```c
// Fire onEnterFrame if:
//   (sprite_initialized && tick > init_tick) OR enterframe_eligible
// Don't fire on init tick (LOAD fires instead)
```

### Files to Modify
- `SWFModernRuntime/include/libswf/swf.h`: Add `sprite_initialized` to DisplayObject
- `SWFModernRuntime/src/libswf/tag.c`: Set `sprite_initialized = 1` in `process_sprite_needs_init()`
- `SWFModernRuntime/src/actionmodern/action.c`: Change dispatch condition in `actionDispatchEnterFrameHandlers()`

### Estimated Effort
~20-30 lines changed. Low code volume but needs careful testing.

---

## Phase 2: Root MC onEnterFrame via SetVariable (string_paths_variable_scopes)

**Goal**: onEnterFrame set on root MC via `SetVariable("onEnterFrame", func)` is discoverable by the dispatcher.

### The Problem

`string_paths_variable_scopes` sets `onEnterFrame` via `SetVariable` which writes to the root MC's **variable table** (`var_map`). But `actionDispatchEnterFrameHandlers()` looks up `onEnterFrame` in the MC's **`dynamic_props`** (ASObject). These are separate storage.

### Implementation

In `actionDispatchEnterFrameHandlers()`, after checking `dynamic_props` for "onEnterFrame", also check `var_map`:

```c
// Check dynamic_props first (normal path)
ActionVar handler = getPropertyFromDynamicProps(mc, "onEnterFrame");
if (handler.type == ACTION_STACK_VALUE_UNDEFINED) {
    // Fallback: check var_map (for SetVariable-assigned handlers)
    handler = getVariableFromVarMap(mc, "onEnterFrame");
}
if (handler.type == ACTION_STACK_VALUE_FUNCTION) {
    // dispatch
}
```

Alternatively, route through `actionGetVariable` which already handles both paths, but that's heavier.

### Test Expectations (string_paths_variable_scopes)

```
frame 1
enter_frame 1    ← onEnterFrame fires, reads variable from scope
enter_frame 2    ← fires again on next tick
frame 3
enter_frame 3    ← fires on frame 3
```

### Files to Modify
- `SWFModernRuntime/src/actionmodern/action.c`: `actionDispatchEnterFrameHandlers()` var_map fallback

### Estimated Effort
~10-15 lines. Low difficulty but depends on Phase 1.

---

## Priority Assessment

| Phase | Effort | Tests Fixed | ROI |
|-------|--------|------------|-----|
| Phase 1 | ~25 lines | issue_1104 (+1 line) | Medium — architectural correctness |
| Phase 2 | ~15 lines | string_paths_variable_scopes (+5 lines) | Medium — unblocks TELLTARGET |

**Combined**: ~40 lines for 2 tests. Medium ROI but important for architectural correctness —
many future tests may depend on per-tick EnterFrame firing.

---

## Regression Guard

```bash
python3 ruffle-tests/verify_output.py --test=create_empty_movie_clip --diff --verbose
python3 ruffle-tests/verify_output.py --test=clip_events --diff --verbose
python3 ruffle-tests/verify_output.py --test=execution_order4 --diff --verbose
python3 ruffle-tests/verify_output.py --test=issue_1104 --diff --verbose
python3 ruffle-tests/verify_output.py --test=string_paths_variable_scopes --diff --verbose
```
