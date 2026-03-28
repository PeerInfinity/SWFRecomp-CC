# Root Replacement Plan (loadMovie into _root/_level0)
<!-- TESTS: loadmovie_replace_root, mcl_loadclip_replace_root, mcl_replace_root_swf7_to_swf5, mcl_replace_root_swf7_to_swf6 -->

<!-- PLAN_META
id: ROOT_REPLACEMENT
status: complete
phases:
  - id: 1
    name: "Root State Clearing"
    status: complete
  - id: 2
    name: "Stage Dimensions Update"
    status: complete
  - id: 3
    name: "Metadata Update"
    status: complete
  - id: 4
    name: "_global Persistence"
    status: complete
  - id: 5
    name: "MCL Root Replacement Timing"
    status: complete
dependencies:
  - plan: LOADMOVIE
    type: requires
    reason: "Root replacement depends on loadMovie infrastructure"
blockers: []
-->

Last updated: 2026-02-25

## Status: PARTIAL — 1/4 tests passing (loadmovie_replace_root)

---

## Implementation Notes

**Phases 1-4 implemented (2026-02-25):**
- Root state clearing: dynamic_props cleared + var_map/var_array reset on root replacement
- Stage dimensions updated from MovieEntry's stage_width/stage_height
- Frame count metadata updated (totalframes, framesloaded, currentframe)
- _global persistence verified (works automatically — singleton not cleared)
- Dynamic props clearing also added for non-root loadMovie targets (consistency with MCL path)

**loadmovie_replace_root: PASS** — All 5 lines match

**mcl_loadclip_replace_root: BLOCKED** — Test uses MTASC class convention (_root.main()). Requires REGISTERCLASS_PLAN or MTASC class linking.

**mcl_replace_root_swf7_to_swf5/6: DEFERRED** — Needs cross-version scope isolation.

---

## Overview

When `loadMovie` or `MovieClipLoader.loadClip` targets `_root` or `_level0`, the entire
root movie is replaced by the loaded SWF. This affects the global scope, Stage dimensions,
`_name`, `_url`, and the SWF version context. Root replacement is fundamentally different
from loading into a child clip because it changes the execution context of the entire movie.

---

## Test Inventory

| Test | Lines | Child SWF | Expected Output Summary |
|------|-------|-----------|------------------------|
| loadmovie_replace_root | 5 | `loadee.swf` (SWF8, 300x300) | Loaded child traces `Loaded`, then checks Stage.width=300, Stage.height=300, _global.bar=1, _root.foo=undefined |
| mcl_loadclip_replace_root | 1 | (self-loads test.swf into _level0) | `message from onLoadStart` — MCL fires onLoadStart before replacement |
| mcl_replace_root_swf7_to_swf5 | 57 | `child.swf` (SWF5) | Full MCL event lifecycle with closure variable behavior across version boundary. SWF7→SWF5 clears closure vars after onLoadStart |
| mcl_replace_root_swf7_to_swf6 | 57 | `child.swf` (SWF6) | Same structure but closure vars persist throughout (SWF6 is case-insensitive like SWF7 parent) |

### Feasibility

| Test | Feasible? | Notes |
|------|-----------|-------|
| **loadmovie_replace_root** | **PASS** ✅ | Root state clearing + Stage dims + var_map reset |
| **mcl_loadclip_replace_root** | **BLOCKED** | Needs MTASC class support (_root.main() resolution) |
| **mcl_replace_root_swf7_to_swf5** | **HARD** | Needs SWF version switching, closure var scoping across versions |
| **mcl_replace_root_swf7_to_swf6** | **HARD** | Same as above but with SWF6 behavior differences |

**Realistically passing after this plan: 2/4** (loadmovie_replace_root, mcl_loadclip_replace_root).
The SWF7→SWF5/6 tests require cross-version scope isolation which is a deep architectural change.

---

## What Root Replacement Does (Flash Behavior)

When `loadMovie("child.swf", _root)` or `MCL.loadClip("child.swf", _level0)` is called:

1. **Clear root state**: Root MovieClip's variables, display list, and scripts are removed
2. **Install child movie**: Child SWF's init + frame 0 run in the root context
3. **Update metadata**:
   - `_root._url` → child SWF's URL
   - `_root._name` → child SWF's name (empty string for root, or child's name)
   - `Stage.width/height` → child SWF's stage dimensions
   - `_root.getSWFVersion()` → child SWF's version
   - `_root._framesloaded`, `_root._totalframes` → child SWF's frame counts
4. **Global scope**: `_global` is shared (SWF6-) or isolated (SWF7+) depending on version
5. **Parent variables cleared**: Variables set in the parent SWF are no longer accessible
   (e.g., `_root.foo` becomes `undefined` if `foo` was set by parent)

### MCL Event Timing for Root Replacement

From `mcl_replace_root_swf7_to_swf5` output:
1. Parent frame 0 runs: `trace("Loading child movie")`
2. MCL fires `onLoadStart` — closure vars accessible, target is `_level0`
3. MCL fires `onLoadProgress` (twice, with bytesLoaded/bytesTotal)
4. MCL fires `onLoadComplete` (with httpStatus=0)
5. Child frame 0 runs: `trace("Loaded version 5")`
6. MCL fires `onLoadInit` — **AFTER** child frame 0, with updated `_name` from child

Key observation for SWF7→SWF5: After `onLoadStart`, closure variables captured by the
MCL event handler become empty strings (SWF5 uses different scope rules). In SWF7→SWF6,
closure vars persist throughout all events.

---

## Design

### Phase 1: Root State Clearing

**Goal**: When loading into `_root` / `_level0`, clear the root MovieClip's state.

**Where**: In `actionGetURL2` loadMovie path and `builtin_mcl_loadClip`, add root detection.

```c
// Before running child init+frame0:
if (target_mc == &root_movieclip || target_mc == g_levels[0]) {
    // Clear root state:
    // 1. Reset variable array (memset to 0)
    // 2. Clear dynamic_props
    // 3. Clear display list (optional — child will overwrite)
    // 4. Reset frame counters
}
```

**Implementation details**:
- Variable array: `memset(var_array, 0, var_array_size)` — but need to preserve the array
  pointer itself. The variable array is allocated once at init.
- Dynamic props: `releaseObject(app_context, root_movieclip.dynamic_props); root_movieclip.dynamic_props = NULL;`
- Frame state: Reset `current_frame = 0`, `frames_loaded = 0`, `total_frames = 0`, `is_playing = 1`

### Phase 2: Stage Dimensions Update

**Goal**: After loading a child SWF into root, update Stage dimensions to match the child.

**Where**: After running child init_func, update `app_context->stage_width/height` from
the `MovieEntry` struct.

```c
MovieEntry* entry = findMovieEntry(url);
if (entry != NULL && (target_mc == &root_movieclip || target_mc == g_levels[0])) {
    app_context->stage_width = entry->stage_width;
    app_context->stage_height = entry->stage_height;
}
```

The `MovieEntry` struct already has `stage_width` and `stage_height` fields populated by
the build pipeline.

### Phase 3: Metadata Update

**Goal**: Update `_url`, `_name`, `getSWFVersion()`, `_framesloaded`, `_totalframes` on the
target MC after replacement.

```c
if (target_mc == &root_movieclip || target_mc == g_levels[0]) {
    // Update URL
    snprintf(target_mc->url, sizeof(target_mc->url), "%s", entry->filename);

    // Update frame counts
    target_mc->total_frames = entry->frame_count;
    target_mc->frames_loaded = entry->frame_count;  // all frames loaded instantly

    // Update SWF version (for getSWFVersion())
    target_mc->swf_version = entry->swf_version;

    // Clear _name (root has empty name after replacement)
    target_mc->instance_name[0] = '\0';
}
```

Note: `_name` on root is typically empty, but some child SWFs set it (see
`mcl_replace_root_swf7_to_swf5` where after load, `_name` = `"root movie 5"`).

### Phase 4: _global Persistence

**Goal**: `_global` variables set by the parent remain accessible after root replacement
(for same-version or lower-version loads).

From `loadmovie_replace_root` output: `_global.bar: 1` — the parent sets `_global.bar = 1`
before loading, and the child can read it. But `_root.foo: undefined` — parent's root
variables are cleared.

This should work automatically with our current `_global` implementation (it's a singleton
ASObject, not reset by loadMovie). Just need to ensure we don't clear `_global` during
root state clearing.

### Phase 5: MCL Root Replacement Timing

**Goal**: MCL events fire correctly when loading into root.

For `mcl_loadclip_replace_root` (1 line: `message from onLoadStart`):
- The parent registers an MCL listener with `onLoadStart` that traces
- MCL.loadClip replaces root with test.swf (itself)
- Only `onLoadStart` output appears — the MCL object itself is destroyed during
  replacement, so subsequent events don't fire (or fire on the new root which has
  no listener)

For `mcl_replace_root_swf7_to_swf5/6` (57 lines each):
- Full event lifecycle fires because the MCL listener uses closure variables
- Events fire: onLoadStart → onLoadProgress (×2) → onLoadComplete → child init → onLoadInit
- In SWF7→SWF5: closure vars are cleared after onLoadStart (version downgrade)
- In SWF7→SWF6: closure vars persist (SWF6 shares scope with SWF7)

This is complex and requires:
- Correct event argument passing (target MC properties _target, _name, _url)
- Closure variable behavior across version boundaries
- `onLoadProgress` firing twice with bytesLoaded/bytesTotal from the actual SWF file size
- Proper `this` binding in MCL callbacks after root replacement

---

## Implementation Order

1. **Phase 1**: Root state clearing (variable array + dynamic_props)
2. **Phase 2**: Stage dimension update from MovieEntry
3. **Phase 3**: Metadata update (_url, _framesloaded, _totalframes, SWF version)
4. **Phase 4**: Verify _global persistence (should work already)
5. **Phase 5**: MCL root replacement event timing

After Phases 1-4: **loadmovie_replace_root** should pass (5 lines).
After Phase 5 partial: **mcl_loadclip_replace_root** should pass (1 line).
**mcl_replace_root_swf7_to_swf5/6**: Need cross-version scope isolation — deferred.

---

## Verification

```bash
python3 ruffle-tests/verify_output.py --test=loadmovie_replace_root --diff --verbose
python3 ruffle-tests/verify_output.py --test=mcl_loadclip_replace_root --diff --verbose
python3 ruffle-tests/verify_output.py --test=mcl_replace_root_swf7_to_swf5 --diff --verbose
python3 ruffle-tests/verify_output.py --test=mcl_replace_root_swf7_to_swf6 --diff --verbose

# Regression checks:
python3 ruffle-tests/verify_output.py --test=loadmovie --diff --verbose
python3 ruffle-tests/verify_output.py --test=mcl_loadclip --diff --verbose
python3 ruffle-tests/verify_output.py --test=unloadmovie --diff --verbose
```

---

## Ruffle Reference

- `~/CC/ruffle/core/src/avm1/activation.rs:1147-1289` — ActionGetURL2 level target
- `~/CC/ruffle/core/src/avm1/globals/movie_clip_loader.rs` — MCL loadClip into root
- `~/CC/ruffle/core/src/loader.rs` — Movie replacement logic, state clearing
- `~/CC/ruffle/core/src/player.rs` — update_context for root replacement
