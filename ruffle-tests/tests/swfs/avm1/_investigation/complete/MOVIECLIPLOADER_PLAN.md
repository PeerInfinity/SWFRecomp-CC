# MovieClipLoader Class Plan
<!-- TESTS: mcl_as_broadcaster, mcl_events_swf_version, mcl_getprogress, mcl_loadclip, mcl_unloadclip, moviecliploader_flashvars, mcl_loadclip_properties, mcl_loadclip_replace_root, mcl_mislabeled_target, mcl_replace_root_swf7_to_swf5, mcl_replace_root_swf7_to_swf6, mcl_target_gif87a, mcl_target_gif89a, mcl_target_jpg, mcl_target_png, loadmovie_fail -->

<!-- PLAN_META
id: MOVIECLIPLOADER
status: complete
phases:
  - id: 1
    name: "MCL constructor — auto-add self as listener"
    status: complete
  - id: 2
    name: "Register MCL methods on prototype"
    status: complete
  - id: 3
    name: "Implement getProgress()"
    status: complete
  - id: 4
    name: "Implement loadClip()"
    status: complete
  - id: 5
    name: "Deferred onLoadInit firing"
    status: complete
  - id: 6
    name: "Implement unloadClip()"
    status: complete
dependencies:
  - plan: LOADMOVIE
    type: requires
    reason: "MCL class wraps core loadMovie functionality"
blockers: []
-->

Last updated: 2026-02-23

## Status: NOT STARTED — 0/16 tests passing

MovieClipLoader is an AS2 class that provides a callback-based API for loading external
SWFs. It uses the AsBroadcaster mixin pattern (addListener/removeListener/broadcastMessage)
to dispatch events (onLoadStart, onLoadProgress, onLoadComplete, onLoadInit, onLoadError).

**Depends on:** Multi-SWF build pipeline (DONE), basic loadMovie (DONE), _level management (NOT DONE)

---

## Existing Infrastructure

- **`new MovieClipLoader()` works**: Stub constructor `g_stub_ctors[9]` (action.c:12672) creates objects with MCL prototype
- **AsBroadcaster methods on prototype**: `addListener`, `removeListener`, `broadcastMessage` already installed on `g_stub_ctors[9].prototype_obj` (action.c:13174-13179)
- **`broadcastMessage` fully implemented**: Iterates `_listeners` array, calls method on each listener (action.c:12179-12256)
- **`findMovieEntry()` lookup**: Pre-compiled child SWFs accessible by filename
- **`child_mc_cache`**: MC name→pointer lookup for target resolution

### What's missing

- MCL constructor doesn't auto-add `this` to `_listeners` (Flash does this)
- No `loadClip()`, `unloadClip()`, `getProgress()` methods
- No onLoadInit deferred firing mechanism
- No event argument passing (target MC, bytesLoaded/Total, httpStatus)

---

## Test Inventory (16 tests)

### Feasible (7 tests)

| Test | Lines | Description |
|------|-------|-------------|
| mcl_as_broadcaster | 12 | Constructor init, broadcastMessage dispatches to MCL + external listener |
| mcl_getprogress | 31 | getProgress() returns {bytesLoaded, bytesTotal} with various target types |
| mcl_loadclip | 150 | loadClip() return values, target resolution, full event sequence |
| mcl_unloadclip | 5 | unloadClip() triggers unload |
| mcl_loadclip_properties | 6 | Closure scope capture in event callbacks |
| mcl_mislabeled_target | 6 | Edge cases with undefined/invalid targets |
| loadmovie_fail | 2 | onLoadError when URL not found |

### Partially feasible (2 tests — need _level support)

| Test | Lines | Description |
|------|-------|-------------|
| mcl_events_swf_version | 232 | Loads 6 child SWFs with full event lifecycle + error on missing file |
| mcl_loadclip (partial) | 150 | Some loadClip calls target _level1, _level2 |

### Not feasible (7 tests)

| Test | Lines | Reason |
|------|-------|--------|
| moviecliploader_flashvars | 4 | Needs FlashVars URL parameter parsing |
| mcl_loadclip_replace_root | 1 | Needs _level0 replacement |
| mcl_replace_root_swf7_to_swf5 | 57 | Root replacement + cross-version (known_failure in Ruffle) |
| mcl_replace_root_swf7_to_swf6 | 57 | Root replacement + cross-version (known_failure in Ruffle) |
| mcl_target_gif87a | 6 | Image decoding (GIF87a) |
| mcl_target_gif89a | 6 | Image decoding (GIF89a) |
| mcl_target_jpg | 6 | Image decoding (JPEG) |
| mcl_target_png | 6 | Image decoding (PNG) |

---

## Implementation Phases

### Phase 1: MCL constructor — auto-add self as listener

**Goal:** `new MovieClipLoader()` creates `_listeners` array with `this` as first entry.

**Where:** `actionNewObject()` generic constructor path (~action.c:19801). After object is
created with `__proto__` set, detect `ctor_func == &g_stub_ctors[9]` and initialize:

```c
if (ctor_func == &g_stub_ctors[9]) {
    // MCL auto-init: create _listeners array with [this]
    ASArray* listeners = allocArray(app_context, 4);
    ActionVar self_var = {0};
    self_var.type = ACTION_STACK_VALUE_OBJECT;
    self_var.data.numeric_value = (u64)obj;
    setArrayElement(app_context, listeners, 0, &self_var);
    ActionVar arr_var = {0};
    arr_var.type = ACTION_STACK_VALUE_ARRAY;
    arr_var.data.numeric_value = (u64)listeners;
    setProperty(app_context, obj, "_listeners", 10, &arr_var);
}
```

**Tests enabled:** mcl_as_broadcaster (partial — MCL receives broadcastMessage calls)

### Phase 2: Register MCL methods on prototype

**Goal:** Add `loadClip`, `unloadClip`, `getProgress` to MCL prototype.

**Where:** Global init, after broadcaster method installation (~action.c:13174).

3 static ASFunction objects + 3 C implementations:
- `builtin_mcl_loadClip(app_context, args, arg_count, registers, this_obj)`
- `builtin_mcl_unloadClip(app_context, args, arg_count, registers, this_obj)`
- `builtin_mcl_getProgress(app_context, args, arg_count, registers, this_obj)`

Use `registerGeomMethod()` pattern or manual setup like existing broadcaster methods.

### Phase 3: Implement getProgress()

**Goal:** `getProgress(target)` returns `{bytesLoaded: N, bytesTotal: N}`.

Target resolution:
- STRING → find MC by name in child_mc_cache
- MOVIECLIP → direct pointer
- NUMBER → _level (stub: return undefined props)
- Other → return object with undefined props

For found targets, `bytesLoaded` = `bytesTotal` = SWF compressed size from MovieEntry
(or 0 if not a loaded movie). Both values are equal since loading is instantaneous.

**Tests enabled:** mcl_getprogress

### Phase 4: Implement loadClip()

**Goal:** `loadClip(url, target)` loads a movie and fires events.

Return value:
- `undefined` if < 2 args
- `false` if target is invalid (non-string/non-number/non-MC, or string target not found)
- `true` if target valid (even if URL fails)

Target resolution (matches Ruffle):
1. STRING → find MC by instance name in child_mc_cache
2. NUMBER (F64/F32) → level index (truncate to int). Return true but stub _level.
3. MOVIECLIP → direct pointer
4. Other (OBJECT, NULL, UNDEFINED) → return false

Event firing sequence (synchronous for trace tests):
1. `broadcastMessage("onLoadStart", target_mc)` — immediately
2. `entry->init_func(app_context)` + `entry->frame_funcs[0](app_context)` — run loaded movie
3. `broadcastMessage("onLoadProgress", target_mc, bytesLoaded, bytesTotal)` — after load
4. `broadcastMessage("onLoadComplete", target_mc, httpStatus=0)` — after load
5. Queue `onLoadInit` for deferred firing (see Phase 5)

If URL not in registry (load failure):
1. `broadcastMessage("onLoadStart", target_mc)`
2. `broadcastMessage("onLoadProgress", target_mc, 0, 0)`
3. `broadcastMessage("onLoadComplete", target_mc, 0)`
4. Queue `onLoadError` instead of `onLoadInit`

**Event dispatch helper:**
```c
static void fireMCLEvent(SWFAppContext* app_context, ASObject* mcl,
                         const char* event_name, ActionVar* extra_args, u32 extra_count)
```
Builds args array `[event_name_str, extra_args...]` and calls
`builtin_broadcaster_broadcastMessage(app_context, args, 1+extra_count, NULL, mcl)`.

**Tests enabled:** mcl_loadclip (partial), mcl_loadclip_properties, mcl_mislabeled_target,
loadmovie_fail

### Phase 5: Deferred onLoadInit firing

**Goal:** `onLoadInit` fires after loaded movie's first frame executes, at ShowFrame time.

From `mcl_loadclip` output, onLoadInit fires:
- AFTER all loaded movies' frame 0 scripts ("Child movie loaded!" lines)
- In REVERSE order of loading (LIFO)

Implementation:
```c
#define MAX_PENDING_LOAD_INITS 16
typedef struct { ASObject* mcl; MovieClip* target; int is_error; } PendingLoadInit;
static PendingLoadInit g_pending_load_inits[MAX_PENDING_LOAD_INITS];
static int g_pending_load_init_count = 0;
```

Fire from `tagShowFrame` (same location as `actionFirePendingUnloads`), iterating in
reverse order (last queued fires first).

**Tests enabled:** mcl_loadclip (onLoadInit events), loadmovie_fail (onLoadError event)

### Phase 6: Implement unloadClip()

**Goal:** `unloadClip(target)` fires onUnload on the target MC.

Same target resolution as loadClip. Fire `onUnload` handler on the MC's dynamic_props.
Return `true` if target found, `false` otherwise.

**Tests enabled:** mcl_unloadclip

---

## Estimated Impact

| Phase | Tests Impacted | Difficulty |
|-------|---------------|------------|
| 1 (constructor) | mcl_as_broadcaster | Low |
| 2 (method registration) | — (infrastructure) | Low |
| 3 (getProgress) | mcl_getprogress | Low |
| 4 (loadClip) | mcl_loadclip, mcl_loadclip_properties, mcl_mislabeled_target | Medium |
| 5 (deferred onLoadInit) | mcl_loadclip, loadmovie_fail | Medium |
| 6 (unloadClip) | mcl_unloadclip | Low |

**Expected pass after implementation:** 4-6 of 16 tests.
Remaining failures need _level support (mcl_loadclip partial, mcl_events_swf_version),
root replacement, FlashVars parsing, or image decoding.

---

## Files to Modify

| File | Changes |
|------|---------|
| `SWFModernRuntime/src/actionmodern/action.c` | MCL constructor init, 3 method implementations, event helper, deferred onLoadInit queue |

No other files need modification — all MCL logic fits in the existing runtime.

---

## Ruffle Reference

- `~/CC/ruffle/core/src/avm1/globals/movie_clip_loader.rs` — MCL class (loadClip, unloadClip, getProgress)
- `~/CC/ruffle/core/src/avm1/globals/as_broadcaster.rs` — AsBroadcaster mixin
- `~/CC/ruffle/core/src/loader.rs` — Event timing (onLoadStart/Complete/Init/Error dispatch)
