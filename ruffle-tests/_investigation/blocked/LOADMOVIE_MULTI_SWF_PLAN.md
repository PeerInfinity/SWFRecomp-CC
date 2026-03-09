# LoadMovie / Multi-SWF Infrastructure — Implementation Plan

Last updated: 2026-03-09

**Goal**: Close the remaining gaps in multi-SWF support. This is the single largest blocker in the project (11 plans, 25+ tests, 2000+ lines).

**Current state**: Phases 0–5, 7, 8, 10, 13, and 14 are implemented. 27/49 loadMovie-related tests pass. The pre-compiled child movie registry, symbol prefix-renaming, MCL event dispatch, unloadMovie, loadVariables, two-group version globals, failed load state, sequential MCL dispatch, _root scope in loaded SWFs, and MCL root replacement all work.

**Status: BLOCKED** — All remaining phases (6, 9, 11, 12) are blocked on per-movie `_global` isolation (Phase 6) or mouse event infrastructure (Phase 12).

---

## Table of Contents

1. [Architecture Overview](#1-architecture-overview)
2. [Gap Analysis](#2-gap-analysis)
3. [Phase 6: Per-Movie `_global` Isolation](#3-phase-6-per-movie-_global-isolation)
4. [Phase 8: Failed Load State](#4-phase-8-failed-load-state)
5. [Phase 9: Child URL / Version Properties](#5-phase-9-child-url--version-properties)
6. [Phase 10: Sequential MCL Dispatch](#6-phase-10-sequential-mcl-dispatch)
7. [Phase 11: Child RegisterClass](#7-phase-11-child-registerclass)
8. [Phase 12: Root Button Mode / Mouse Events](#8-phase-12-root-button-mode--mouse-events)
9. [Phase 13: _root Scope in Loaded SWFs](#9-phase-13-_root-scope-in-loaded-swfs)
10. [Phase 14: MCL loadClip Replace Root (MTASC)](#10-phase-14-mcl-loadclip-replace-root-mtasc)
11. [Dependency Graph](#11-dependency-graph)
12. [Test Impact Matrix](#12-test-impact-matrix)
13. [Risk Assessment](#13-risk-assessment)

---

## 1. Architecture Overview

### Current Pipeline

```
Build time:
  test.swf ──► SWFRecomp ──► script_0.c, tagMain.c, constants.h, ...
  target.swf ──► SWFRecomp ──► _child_target/script_0.c, tagMain.c, ...
                     │
                     ▼
              verify_output.py
                     │
              ┌──────┴──────┐
              │  Symbol     │  target_str_0, target_script_0,
              │  Prefixing  │  target_sprite_1_frame_0, ...
              └──────┬──────┘
                     │
              movie_target.c   (prefixed child code + MovieEntry struct)
              movie_registry.c (findMovieEntry() lookup table)
                     │
              gcc -DHAS_CHILD_MOVIES *.c ──► test_run
```

### Key Runtime Data Structures

```c
// Pre-compiled child SWF metadata (swf.h:293)
typedef struct MovieEntry {
    const char* filename;               // "target.swf"
    frame_func* frame_funcs;            // child's frame function array
    void (*init_func)(SWFAppContext*);   // child's tagInit function
    u16 swf_version;
    u16 frame_count;
    u16 stage_width, stage_height;
} MovieEntry;

// Level management (action.c:12150)
#define MAX_LEVELS 16
MovieClip* g_levels[MAX_LEVELS];  // g_levels[0] = &root_movieclip

// Version-group globals (action.c:8040)
ASObject* global_object = NULL;          // active _global pointer
static ASObject* g_global_legacy = NULL; // SWF 1-6
static ASObject* g_global_modern = NULL; // SWF 7+
static ASObject* g_object_proto_legacy/modern = NULL;
static ASObject* g_array_proto_legacy/modern = NULL;
```

### Loading Entry Points

| Entry Point | Source | Notes |
|-------------|--------|-------|
| `actionGetURL(url, target)` | SWF4 GetURL opcode | Handles `_levelN` and named targets |
| `actionGetURL2(send, load_target, load_vars)` | SWF5+ GetURL2 opcode | Stack-based, loadMovie/loadVariables modes |
| `builtin_mcl_loadClip(url, target)` | MovieClipLoader.loadClip() | Deferred dispatch via PendingMCLLoad queue |
| `actionImportAssets(url)` | ImportAssets tag | Loads child init + classes |

### What's Implemented (Phases 0–5, 7)

| Phase | Feature | Status |
|-------|---------|--------|
| 0 | Child SWF discovery & compilation in verify_output.py | DONE |
| 1 | `_level` management (getOrCreateLevel, level lookup) | DONE |
| 2 | Core loadMovie (GetURL, GetURL2 routing, MovieEntry lookup) | DONE |
| 3 | actionGetURL2 load_target/load_variables routing | DONE |
| 4 | MovieClipLoader class (loadClip, deferred events, progress) | DONE |
| 5 | unloadMovie (deferred marking, event firing) | DONE |
| 7 | loadVariables (DataFileEntry registry, URL-encoded parsing) | DONE |

---

## 2. Gap Analysis

| # | Gap | Tests Affected | Lines at Stake | Difficulty | Status |
|---|-----|----------------|----------------|------------|--------|
| 6 | Per-movie `_global` isolation | global_swf5_6_7_8_9 (88 lines), loadmovienum_cross_version_prototype (3 lines) | ~91 | HIGH | **BLOCKED** |
| 8 | Failed load state (`-1` values) | movieclip_state_values | ~100+ | LOW | **DONE** (load_failed flag, DeferredFailedLoad queue, getter checks) |
| 9 | Child URL / version properties | movieclip_library_state_values (1 _url line) | ~1 | LOW | **BLOCKED** (URL format inconsistent across tests — changing risks regressions; _xmouse needs mouse sim) |
| 10 | Sequential MCL dispatch (one-per-frame) | mcl_events_swf_version | ~50 | MEDIUM | **DONE** — mcl_events_swf_version 232/232 PASS |
| 11 | Child RegisterClass in child scope | register_class (19 lines), register_class_swf6 (34 lines) | ~53 | MEDIUM | **BLOCKED** (depends on Phase 6 for per-movie prototype isolation) |
| 12 | Root button mode / mouse events | root_button_mode (10 lines) | ~10 | MEDIUM (needs mouse infra) | **BLOCKED** (mouse event sim) |
| 13 | `_root` scope in loaded SWFs | resolve_different_root (2 lines) | ~2 | LOW | **DONE** — resolve_different_root PASS |
| 14 | MCL loadClip replace root (MTASC) | mcl_loadclip_replace_root (1 line) | ~1 | MEDIUM | **DONE** — mcl_loadclip_replace_root PASS |

---

## 3. Phase 6: Per-Movie `_global` Isolation

**Impact**: ~120 lines across 3 tests. Highest architectural complexity.

### Problem

In Ruffle/Flash, each SWF7+ loaded movie gets its own `_global` object with **distinct constructor instances** (`Object`, `Array`, `MovieClip`, etc.). Cross-movie `instanceof` checks fail when constructors are shared because `instanceof` compares constructor identity.

Our current model uses **two groups**:
- `g_global_legacy` (SWF 1–6) — all legacy SWFs share one `_global`
- `g_global_modern` (SWF 7+) — all modern SWFs share one `_global`

This fails when:
1. A SWF8 parent loads a SWF7 child — both share `g_global_modern`, so `parent._global === child._global` (wrong: should be different objects)
2. A SWF6 parent loads a SWF5 child — both share `g_global_legacy`
3. `{} instanceof child._global.Object` returns true (wrong: should be false, different constructor identity)

### What the Tests Expect

**global_swf5_6_7_8_9** (1031/1145, need 114 more lines):
```
// Parent SWF8 loads child5.swf (SWF5) into _level1
// Each loaded SWF defines anObjectClass, creates objects
// Cross-version instanceof:
{} instanceof s1.anObjectClass: false    // s1's Object !== parent's Object
s1.anObj instanceof Object: false        // different constructor identity
```

**loadmovienum_cross_version_prototype** (6/9, need 3 more lines):
```
_level2.__proto__ === MovieClip.prototype: true   // SWF8 child uses SWF8 MovieClip.prototype
_level0.__proto__ === MovieClip.prototype: false   // SWF6 parent uses SWF6 MovieClip.prototype (no proto)
```

### Design: Per-MovieEntry Global Allocation

Replace the two-group model with a per-movie model:

```c
// NEW: Per-movie global tracking
typedef struct MovieGlobalEntry {
    const char* movie_filename;   // NULL for root SWF
    u16 swf_version;
    ASObject* global_obj;
    ASObject* object_proto;
    ASObject* array_proto;
} MovieGlobalEntry;

#define MAX_MOVIE_GLOBALS 16
static MovieGlobalEntry g_movie_globals[MAX_MOVIE_GLOBALS];
static int g_movie_global_count = 0;
```

#### Initialization Strategy

1. **Root SWF**: `ensureGlobalInit()` creates the root global as today. Store as `g_movie_globals[0]` with `movie_filename = NULL`.

2. **Child SWF load**: At each load site (actionGetURL, actionGetURL2, MCL loadClip, ImportAssets), call `getOrCreateMovieGlobal(entry)`:
   ```c
   static MovieGlobalEntry* getOrCreateMovieGlobal(MovieEntry* entry) {
       // Check if already exists for this filename
       for (int i = 0; i < g_movie_global_count; i++) {
           if (g_movie_globals[i].movie_filename != NULL &&
               strcmp(g_movie_globals[i].movie_filename, entry->filename) == 0)
               return &g_movie_globals[i];
       }
       // Create new: allocate fresh _global, constructors, prototypes
       MovieGlobalEntry* mge = &g_movie_globals[g_movie_global_count++];
       mge->movie_filename = entry->filename;
       mge->swf_version = entry->swf_version;
       mge->global_obj = createFreshGlobal(entry->swf_version);
       mge->object_proto = createFreshObjectPrototype();
       mge->array_proto = createFreshArrayPrototype(mge->object_proto);
       return mge;
   }
   ```

3. **`createFreshGlobal(version)`**: Extracted from `ensureSecondaryGlobalInit()`. Creates a complete `_global` with all constructors, using fresh prototype instances. The key difference from today: each call creates **new** Object/Array/String/Number/Boolean/Function constructors with **new** prototypes.

4. **Shared singletons stay shared**: Math, Accessibility, Key, Mouse, Selection, Stage remain the same C pointers across all movies (Flash shares these).

#### Context Switching

Replace `switchToFunctionVersion()` with version that resolves per-movie global:

```c
// On child SWF init:
MovieGlobalEntry* child_global = getOrCreateMovieGlobal(entry);
ASObject* saved_global = global_object;
ASObject* saved_obj_proto = g_object_prototype;
ASObject* saved_arr_proto = g_array_prototype;
global_object = child_global->global_obj;
g_object_prototype = child_global->object_proto;
g_array_prototype = child_global->array_proto;
// ... run child code ...
// restore
```

For user-defined functions, the `ASFunction.swf_version` field is insufficient — we also need to know which movie the function belongs to. Options:

**Option A**: Add `ASFunction.movie_global_idx` (u8) — index into `g_movie_globals[]`. Set at function definition time. `switchToFunctionVersion()` uses this index to resolve the correct global. **Preferred** — minimal memory overhead (1 byte per function).

**Option B**: Add `ASFunction.global_obj` (ASObject*) — direct pointer. More direct but uses 8 bytes per function.

#### Backward Compatibility

The `g_global_legacy` / `g_global_modern` variables can be kept as aliases to `g_movie_globals[0]` for code that only needs version-group lookup (e.g., `getActiveGlobal()` for auto-boxing). Or `getActiveGlobal()` can be rewritten to use the current context's movie global.

#### Sites to Update

1. `actionGetURL()` _level target path (action.c:18434) — switch to per-movie global
2. `actionGetURL()` named clip target path (action.c:18499) — switch to per-movie global
3. `actionGetURL2()` loadMovie path (action.c:26380) — switch to per-movie global
4. `actionFirePendingLoadInits()` Phase 2 (action.c:19200) — switch to per-movie global
5. `actionImportAssets()` (action.c:19103) — switch to per-movie global
6. `switchToFunctionVersion()` (action.c:8070) — resolve function's movie global
7. `getActiveGlobal()` (action.c:8057) — resolve from current movie context
8. `getVersionedObjectProto()` / `getVersionedArrayProto()` (action.c:21222-21232) — resolve from current movie
9. Primitive auto-boxing (object literal `{}`, `new Object()`, `new Array()`) — use current movie's prototypes

#### Testing Strategy

1. Build `global_swf5_6_7_8_9` test first — it has 5 child SWFs and exercises all cross-version paths
2. Verify `loadmovienum_cross_version_prototype` passes
3. Check for regressions on the 24 already-passing loadMovie tests

#### Risks

- **Memory**: Each movie global allocates ~40 ASFunction constructors + 2 ASObject prototypes. At 16 max movies, this is ~640 small allocations. Acceptable.
- **Function lookup**: Functions defined in child SWFs need to resolve the child's global, not the parent's. The `movie_global_idx` on ASFunction handles this.
- **Prototype chain**: `new Object()` in child must use child's Object.prototype, not parent's. Must ensure `createObject()` / `allocObject()` use `getVersionedObjectProto()` which resolves from current movie.
- **Shared singletons**: Test expects `Key`, `Mouse`, `Stage` to be the **same** object across movies. Must not duplicate these.

---

## 4. Phase 8: Failed Load State

**Impact**: ~100 lines in `movieclip_state_values`. Low difficulty.

### Problem

When `loadMovie("nonexistent.swf", target)` is called and the SWF is not found, the target MC's properties should reflect a failed load:

| Property | Expected Value |
|----------|----------------|
| `_framesloaded` | `-1` |
| `_totalframes` | `0` (or `-1`) |
| `getBytesTotal()` | `-1` |
| `getBytesLoaded()` | `-1` |
| `getSWFVersion()` | `-1` |
| `_url` | The attempted URL |

Currently, when `findMovieEntry()` returns NULL, we don't modify the target MC at all — properties remain at their pre-load values.

### Implementation

In `actionGetURL()` and `actionGetURL2()`, after `findMovieEntry()` returns NULL:

```c
MovieEntry* entry = findMovieEntry(url);
if (entry == NULL) {
    // Mark as failed load
    mc->framesloaded = -1;    // or use a new field: mc->load_failed = 1
    mc->totalframes = 0;
    mc->byte_size = 0;
    mc->swf_version = 0;      // getSWFVersion returns -1 via check
    mc->unloaded = 0;
    snprintf(mc->url, sizeof(mc->url), "file:///%s", url);
    // Clear dynamic_props (loadMovie clears existing vars even on failure)
    if (mc->dynamic_props != NULL) {
        freeObject(app_context, (ASObject*)mc->dynamic_props);
        mc->dynamic_props = NULL;
    }
}
```

Then in the property getters:
```c
// _framesloaded: return -1 when load_failed
if (mc->load_failed) { PUSH_F32(-1.0f); return; }

// getBytesTotal/getBytesLoaded: return -1 when load_failed
if (mc->load_failed) { PUSH_F64(-1.0); return; }

// getSWFVersion: return -1 when load_failed
if (mc->load_failed) { PUSH_F64(-1.0); return; }
```

**Alternative**: Use a dedicated `mc->load_failed` flag (u8) rather than overloading `framesloaded = -1`, to avoid ambiguity with legitimate -1 values.

### Files to Modify

- `action.h`: Add `u8 load_failed;` to MovieClip struct
- `action.c`: Set `load_failed = 1` on failed findMovieEntry, set `load_failed = 0` on successful load
- `action.c`: Check `load_failed` in `_framesloaded`, `getBytesTotal`, `getBytesLoaded`, `getSWFVersion` getters

### Testing

Run `movieclip_state_values` — expect significant jump (3/114 → much higher). Some failures will remain due to other gaps (child URL, setInterval polling).

---

## 5. Phase 9: Child URL / Version Properties

**Impact**: ~5 lines across 2 tests. Low difficulty.

### Problem

`movieclip_library_state_values` is 76/78 — the 2 failing lines are:
1. `_url` — returns parent's URL instead of child's
2. `_xmouse` — returns wrong value (likely already accepted diff)

For `mcl_events_swf_version`, the child's `getSWFVersion()` should return the child SWF's version, not the parent's.

### Current State

The URL is already set in most load paths:
```c
snprintf(mc->url, sizeof(mc->url), "file:///%s", entry->filename);
```

But the format may not match what tests expect. Tests expect `file:///{test_name}/target.swf` but we generate `file:///target.swf`.

### Implementation

Update URL generation to include the test directory context:
```c
// The SWF_URL macro already provides "file:///test.swf" for the parent
// For child loads, construct path relative to parent:
snprintf(mc->url, sizeof(mc->url), "file:///%s/%s", g_parent_dir, entry->filename);
```

Or, since `verify_output.py` already defines `-DSWF_URL="file:///test.swf"`, we can derive the parent directory from that and construct child URLs relative to it.

**Note**: `movieclip_library_state_values` is already in `ACCEPTED_DIFFS.md` for the `_xmouse` line. If the `_url` line is also cosmetic, this phase may not be needed. Verify by running the test diff.

### Files to Modify

- `action.c`: Update URL construction in load paths
- Possibly `verify_output.py`: Pass parent directory info via `-D` define

---

## 6. Phase 10: Sequential MCL Dispatch

**Impact**: ~50 lines in `mcl_events_swf_version`. Medium difficulty.

### Problem

When multiple `MovieClipLoader.loadClip()` calls are made in the same frame, Flash/Ruffle fires their events **one load per frame** (sequential), not all at once. Our current implementation fires all pending loads in `actionFirePendingLoadInits()` at each ShowFrame.

### What the Test Expects

```actionscript
mcl.loadClip("child5.swf", target1);  // frame 1: fires events for child5
mcl.loadClip("child7.swf", target2);  // frame 2: fires events for child7
mcl.loadClip("child8.swf", target3);  // frame 3: fires events for child8
```

Each load's onLoadStart/onLoadProgress/onLoadComplete/onLoadInit fires in a separate frame.

### Implementation

Change `actionFirePendingLoadInits()` to process **at most one** pending load per ShowFrame call:

```c
void actionFirePendingLoadInits(SWFAppContext* app_context) {
    if (g_pending_mcl_load_count == 0) return;

    // Process only the FIRST pending load (FIFO)
    PendingMCLLoad* load = &g_pending_mcl_loads[0];

    // ... fire events for this one load ...

    // Shift remaining loads down
    for (int i = 1; i < g_pending_mcl_load_count; i++)
        g_pending_mcl_loads[i-1] = g_pending_mcl_loads[i];
    g_pending_mcl_load_count--;
}
```

**Caveat**: Non-MCL loads (actionGetURL/actionGetURL2) execute immediately, not deferred. Only MCL loads are sequential. The current architecture already separates these — MCL loads go through `g_pending_mcl_loads[]`, direct loads execute inline.

**Frame loop impact**: If there are pending MCL loads, the frame loop must continue ticking even if the main timeline is stopped. Check `hasActiveTimers()` equivalent — may need `hasPendingMCLLoads()` added to the loop exit condition.

### Files to Modify

- `action.c`: Modify `actionFirePendingLoadInits()` to process one load per call
- `swf_core.c`: Add `hasPendingMCLLoads()` to frame loop exit condition (if not already)

### Testing

Run `mcl_events_swf_version` after implementation.

---

## 7. Phase 11: Child RegisterClass

**Impact**: ~55 lines across `register_class` (22 lines) and `register_class_swf6` (33 lines). Medium difficulty.

### Problem

When a child SWF is loaded, its `DoInitAction` should register classes in the **child's scope context**. Currently, classes registered by child SWFs may not fire constructors correctly because:

1. The child's class constructors are defined with the child's symbol-prefixed names
2. The registered class lookup uses `g_registered_classes[]` which is global
3. Constructor invocation during timeline-placed sprite init may not switch to the child's version/global context

### What the Tests Expect

**register_class** (44/66): Parent registers a class, then loads child.swf. Child also registers a class. Timeline-placed sprites in the child should trigger the child's registered constructor:
```
In CustomClass constructor    // from child's DoInitAction
typeof mc: movieclip
Prototype check passed
```

**register_class_swf6** (4/37): SWF6 version — constructor invoked with SWF6 semantics (case-insensitive property lookup, etc.).

### Current RegisterClass Architecture

```c
// Global registry (action.c)
typedef struct {
    char symbol_name[128];
    void* constructor;    // ASFunction*
} RegisteredClassEntry;

#define MAX_REGISTERED_CLASSES 128
static RegisteredClassEntry g_registered_classes[MAX_REGISTERED_CLASSES];

// Timeline sprite init calls:
actionInvokeRegisteredClassConstructor(app_context, export_name, mc);
```

### Implementation

The key fix: when child SWF's `DoInitAction` registers a class, ensure:

1. **Export name resolution**: Child SWFs use prefixed export names. The `ng_lookupExportName(char_id)` must return the correct (possibly prefixed) name for child symbols.

2. **Constructor version context**: When `actionInvokeRegisteredClassConstructor()` calls the child's constructor, it must switch to the child's SWF version and global context. The constructor (an ASFunction) already has `swf_version` and (after Phase 6) `movie_global_idx` — so `switchToFunctionVersion()` should handle this automatically.

3. **DoInitAction context**: When child SWF's init runs during load, `g_current_context` is set to the child MC. `Object.registerClass()` inside the child should use the child's export namespace. This should already work if the child's tagInit properly sets up the init action context.

### Investigation Needed

Run `register_class` test with `--diff --verbose` to see exactly which lines fail. The failures may be:
- Constructor not found (export name mismatch between child prefix and registry)
- Constructor found but invoked without child's global context
- `typeof mc` returning wrong value (MC not properly initialized)

### Likely Fix

The child's `tagInit` function (generated by the recompiler) calls `Object.registerClass(symbolName, constructor)`. The `symbolName` here is the **original** un-prefixed export name (e.g., "MyClip"), but the child's timeline sprites reference prefixed char_ids. The `ng_lookupExportName()` for child char_ids may return the wrong name.

**Fix**: In the movie wrapper generation (`verify_output.py`), ensure that `registerExportAsset()` calls in child `tagInit` use the same export names that `ng_lookupExportName()` will return for child sprite char_ids.

### Files to Modify

- `action.c`: Ensure `actionInvokeRegisteredClassConstructor()` uses constructor's version context
- `verify_output.py`: Verify child export name consistency
- Possibly `tag.c` / `tag_stubs.c`: Ensure child sprite init lookup works with child exports

---

## 8. Phase 12: Root Button Mode / Mouse Events

**Impact**: 10 lines in `root_button_mode`. Medium difficulty (needs mouse event infrastructure).

### Problem

`root_button_mode` loads child SWFs that define button event handlers (onMouseDown, onMouseUp, onPress, onRelease) on MovieClips. These handlers fire in response to mouse events, which our trace-only runtime doesn't dispatch.

### What the Test Expects

```
_level0.mc2.onMouseDown
_level0.onMouseDown
_level0.mc2.onMouseUp
_level0.mc2.onPress
_level0.onRelease
...
```

### Dependency

This test requires **mouse event simulation** — the `test.toml` likely specifies mouse input events. Our runtime doesn't process mouse input in trace mode.

### Implementation (if mouse sim exists)

If mouse event simulation is already available (check test.toml for `[input]` section):

1. Parse mouse events from test.toml
2. Dispatch onMouseDown/onMouseUp to all MCs with handlers (broadcast)
3. Dispatch onPress/onRelease to the MC under the cursor (hit test)

**Blocked on**: Mouse event dispatch infrastructure (separate from loadMovie). This is a cross-cutting concern.

### Recommendation

Defer this phase. It requires mouse simulation infrastructure that is not yet implemented and is orthogonal to loadMovie. Add to `ignored_tests.txt` if not already there.

---

## 9. Phase 13: `_root` Scope in Loaded SWFs

**Impact**: ~4 lines across 2 tests. Low difficulty.

### Problem

**resolve_different_root** (0/2): When a child SWF is loaded into a target MC, `_root` inside the child should resolve to the **container MC**, not the global `_level0`. The child's scripts use `_root` to reference their own top-level scope.

```
Expected:
From TestClip root is _level0.container_mc
From TestClip parent is _level0.container_mc
```

**sandbox_type_remote** (1/3): Child SWF loaded via loadMovie traces sandbox type. Needs child to execute and trace.

### Implementation

For `resolve_different_root`:
- When loading a child SWF into a non-root MC, set `mc->_lockroot = 1` (or equivalent) so that `_root` resolution inside the child returns the target MC, not `_level0`
- We already have `_lockroot` support (LOCKROOT_PLAN is complete, movieclip_lockroot 29/29 PASS). The question is whether loaded SWFs **automatically** treat their container as `_root`.

**Flash behavior**: In Flash, loaded SWFs treat their load target as `_root` unless `_lockroot` is explicitly set. This is the default behavior — each loaded SWF has its own `_root`.

**Fix**: When `actionGetURL`/`actionGetURL2` loads a child SWF into a non-`_level0` target, the child's scripts should use `g_current_context` (the target MC) as their `_root`, not `&root_movieclip`. This may require:
- Setting `actionSetBaseClip(target_mc)` before running child init (may already be done)
- Ensuring `actionGetVariable("_root")` resolves to the base_clip when in child context

### Investigation

Check if `_root` resolution already respects `g_current_context` / base_clip. If `actionGetVariable("_root")` always returns `&root_movieclip`, it needs to return the current base_clip instead.

### Files to Modify

- `action.c`: `actionGetVariable("_root")` should return base_clip (the loaded SWF's container), not always `&root_movieclip`

---

## 10. Phase 14: MCL loadClip Replace Root (MTASC)

**Impact**: 1 line in `mcl_loadclip_replace_root`. Medium difficulty.

### Problem

The child SWF uses MTASC class convention: it defines a `main` class with a constructor that's called as `_root.main()`. Our runtime doesn't support this pattern.

### What the Test Expects

```
message from onLoadStart
```

The onLoadStart event should fire when the MCL loadClip begins loading the child SWF.

### Current State

`mcl_loadclip_replace_root` is 0/1 — no output at all, suggesting the MCL loadClip into `_root` path fails before events fire.

### Implementation

1. Debug why the MCL loadClip path fails for root replacement — the non-MCL root replacement works (`loadmovie_replace_root` 5/5 PASS)
2. The issue may be in `builtin_mcl_loadClip()` — when target is `_root` / `_level0`, the deferred load may not properly handle root state clearing
3. Fix root replacement in MCL path to match direct loadMovie root replacement

### Files to Modify

- `action.c`: Debug `builtin_mcl_loadClip()` and `actionFirePendingLoadInits()` for root target

---

## 11. Dependency Graph

```
Phase 6 (Per-Movie _global) ─── BLOCKED (high complexity, core architectural change)
    │
    ├──► Phase 11 (Child RegisterClass) — needs child's global context ── BLOCKED
    │
    ├──► global_swf5_6_7_8_9 test (88 lines remaining)
    │
    └──► loadmovienum_cross_version_prototype test (3 lines)

Phase 8 (Failed Load State) ──► movieclip_state_values ─── DONE ✅

Phase 9 (Child URL/Version) ──► movieclip_library_state_values ─── BLOCKED (URL format risk)

Phase 10 (Sequential MCL) ──► mcl_events_swf_version ─── DONE ✅

Phase 12 (Mouse Events) ──► root_button_mode ─── BLOCKED (separate infra)

Phase 13 (_root Scope) ──► resolve_different_root ─── DONE ✅

Phase 14 (MCL Root Replace) ──► mcl_loadclip_replace_root ─── DONE ✅
```

### Completion Status (2026-03-09)

**Completed phases**: 8, 10, 13, 14 (all passing tests verified locally)
**Remaining blocked phases**: 6 (core blocker), 9 (URL risk), 11 (depends on 6), 12 (mouse infra)

Phase 6 (per-movie `_global` isolation) is the single remaining actionable blocker. It requires:
- Extracting `ensureSecondaryGlobalInit()` into a per-movie factory function
- Adding `movie_global_idx` to ASFunction for per-function global resolution
- Updating 9+ sites that resolve globals/prototypes
- HIGH regression risk (affects all 425+ filtered-passing tests)

---

## 12. Test Impact Matrix

| Test | Plan Estimate | Actual (2026-03-09) | Phase Needed | Status |
|------|---------------|---------------------|--------------|--------|
| mcl_events_swf_version | 232/232 | 232/232 PASS | Phase 10 | DONE |
| mcl_loadclip_replace_root | 0/1 | 1/1 PASS | Phase 14 | DONE |
| resolve_different_root | 0/2 | 2/2 PASS | Phase 13 | DONE |
| global_swf5_6_7_8_9 | 1031/1145 | 1057/1145 | Phase 6 | BLOCKED |
| loadmovienum_cross_version_prototype | 6/9 | 6/9 | Phase 6 | BLOCKED |
| movieclip_state_values | 3/114 | 41/114 | Phase 8 DONE; test 3 blocked on image loading | PARTIAL |
| movieclip_library_state_values | 76/78 | 76/78 | Phase 9 | BLOCKED |
| register_class | 44/66 | 48/67 | Phase 11 (depends on Phase 6) | BLOCKED |
| register_class_swf6 | 4/37 | 4/38 | Phase 11 (depends on Phase 6) | BLOCKED |
| sandbox_type_remote | 1/3 | 1/3 | Needs network loading | BLOCKED |
| root_button_mode | 0/10 | 0/10 | Phase 12 (mouse infra) | BLOCKED |

**Remaining actionable lines**: ~200 lines across blocked tests, all gated on Phase 6 (per-movie `_global`) or external infrastructure (mouse events, image loading, network).

**Key blocker**: Phase 6 (per-movie `_global` isolation) blocks ~91 lines directly (global_swf5_6_7_8_9 + loadmovienum_cross_version_prototype) and ~53 lines indirectly via Phase 11 (register_class + register_class_swf6). HIGH regression risk — affects all 425+ filtered-passing tests.

---

## 13. Risk Assessment

### High Risk: Phase 6 (Per-Movie _global)

- **Regression risk**: Changing global resolution affects every operation that touches `_global`, constructors, or prototypes. The 24 already-passing loadMovie tests and all 425 filtered-passing tests could regress.
- **Mitigation**: Implement behind a flag initially. Run full test suite in CI after. Ensure `getActiveGlobal()` fallback works when no per-movie context is set.
- **Complexity**: Moderate — the `ensureSecondaryGlobalInit()` function already creates a fresh global. The main work is making it per-movie instead of per-version-group, and threading the movie context through function calls.

### Medium Risk: Phase 10 (Sequential MCL)

- **Regression risk**: Changing MCL dispatch to one-per-frame could break tests that rely on all loads completing in one frame.
- **Mitigation**: Check all MCL test expectations. The 3 currently-passing MCL tests (mcl_as_broadcaster, mcl_getprogress, mcl_loadclip) use single loads, so sequential dispatch shouldn't affect them.

### Low Risk: Phases 8, 9, 13, 14

- These are additive changes (new behavior for previously-unhandled cases). Risk of regression is minimal since they don't change existing code paths significantly.

---

## Appendix: Key File Locations

| Component | File | Key Lines |
|-----------|------|-----------|
| MovieEntry struct | `SWFModernRuntime/include/libswf/swf.h` | 293–301 |
| MovieClip struct | `SWFModernRuntime/include/actionmodern/action.h` | 18–66 |
| Global version management | `SWFModernRuntime/src/actionmodern/action.c` | 8040–8085 |
| ensureGlobalInit() | `action.c` | 20537 (~400 lines) |
| ensureSecondaryGlobalInit() | `action.c` | 21017 (~200 lines) |
| actionGetURL() | `action.c` | 18384–18516 |
| actionGetURL2() | `action.c` | 26298–26552 |
| MCL loadClip | `action.c` | 18882–18976 |
| MCL deferred dispatch | `action.c` | 19115–19238 |
| PendingMCLLoad struct | `action.c` | 18778–18787 |
| RegisterClass registry | `action.c` | ~registerClassForSymbol |
| _level management | `action.c` | 12150–12171 |
| findMovieEntry stub | `SWFModernRuntime/src/libswf/swf_core.c` | 43–48 |
| ShowFrame MCL fire | `SWFModernRuntime/src/libswf/tag.c` | 1294–1295 |
| Child SWF discovery | `ruffle-tests/verify_output.py` | 303–309 |
| Symbol prefix & wrapping | `verify_output.py` | 355–586 |
| Movie registry generation | `verify_output.py` | 588–614 |
| Recompiler GetURL | `SWFRecomp/src/action/action.cpp` | 1101–1120 |
| Recompiler GetURL2 | `SWFRecomp/src/action/action.cpp` | 2000–2020 |
