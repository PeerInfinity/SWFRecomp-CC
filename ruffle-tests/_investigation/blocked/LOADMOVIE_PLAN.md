# LoadMovie / Multi-SWF Infrastructure Plan
<!-- TESTS: loadmovie, loadmovie_fail, loadmovie_flashvars, loadmovie_method, loadmovie_registerclass, loadmovie_replace_root, loadmovie_var_persistence, loadmovienum, loadmovienum_cross_version_prototype, loadvariables, loadvariables2, loadvariables_method, loadvariablesnum, mcl_as_broadcaster, mcl_events_swf_version, mcl_getprogress, mcl_loadclip, mcl_unloadclip, moviecliploader_flashvars, mcl_loadclip_properties, mcl_loadclip_replace_root, mcl_mislabeled_target, mcl_replace_root_swf7_to_swf5, mcl_replace_root_swf7_to_swf6, mcl_target_gif87a, mcl_target_gif89a, mcl_target_jpg, mcl_target_png, loading_avm2, unloadmovie, unloadmovie_method, unloadmovienum, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8, root_button_mode, movieclip_state_values, movieclip_library_state_values, movieclip_methods_with_loaded_image, do_init_action_child, register_class, register_class_swf6, global_swf5_6_7_8_9, global_swf6_7_8 -->

Last updated: 2026-03-10

## Status: MOSTLY COMPLETE — 31/35 core loadMovie tests passing locally

Phases 0-5, 7, 8, 10, 13, 14 all implemented. **Phase 6 (per-movie `_global` isolation)
was CANCELLED** — Ruffle source investigation confirmed it shares `_global` across movies,
matching our existing two-group model. See LOADMOVIE_MULTI_SWF_PLAN.md for details.

31 tests pass locally: `loadmovie`, `loadmovie_fail`, `loadmovie_flashvars`,
`loadmovie_method`, `loadmovie_replace_root`, `loadmovie_var_persistence`, `loadmovienum`,
`loadmovienum_cross_version_prototype`, `loadvariables`, `loadvariables2`,
`loadvariablesnum`, `mcl_as_broadcaster`, `mcl_events_swf_version`, `mcl_getprogress`,
`mcl_loadclip`, `mcl_loadclip_properties`, `mcl_loadclip_replace_root`,
`mcl_mislabeled_target`, `mcl_unloadclip`, `mcl_target_gif87a`, `mcl_target_gif89a`,
`mcl_target_jpg`, `mcl_target_png`, `moviecliploader_flashvars`, `unloadmovie`,
`unloadmovie_method`, `unloadmovienum`, `do_init_action_child`,
`global_swf5_6_7_8_9`, `global_swf6_7_8`, `resolve_different_root`.

### Remaining 4 failures (of 35 core loadMovie tests)

| Category | Tests | Blocker |
|----------|-------|---------|
| **RegisterClass in child SWF** | register_class (64/66), register_class_swf6 (~30/38) | Child class constructor typeof/prototype — **ACTIONABLE** |
| **MCL root replace cross-version** | mcl_replace_root_swf7_to_swf5 (~37/57), mcl_replace_root_swf7_to_swf6 (~37/57) | Closure var clearing, _name reset, onLoadProgress count — **ACTIONABLE** |

### Additional loadMovie-adjacent tests (not in core 35)

| Category | Tests | Blocker |
|----------|-------|---------|
| **getBounds on loaded clips** | movieclip_invalid_get_bounds_1-8 | getBounds returns undefined after child load; _6/_7 crash (heap_free) |
| **RegisterClass + loadMovie** | loadmovie_registerclass (24/30) | Child class registration |
| **Mouse events** | root_button_mode (0/10) | Mouse event dispatch now implemented; still needs loadMovie |
| **Clip state after load** | movieclip_state_values (41/114), movieclip_library_state_values (76/78) | Image loading, URL format |
| **Image loading methods** | movieclip_methods_with_loaded_image | MC methods on loaded image clip |
| **loadVariables POST** | loadvariables_method | Needs log_fetch / network POST trace infra |
| **AVM2 (unfixable)** | loading_avm2 | Cross-AVM loading out of scope |

---

## The Core Problem

Our recompiler converts SWF bytecode to C at **compile time**. loadMovie loads external SWFs
at **runtime**. This is a fundamental architectural mismatch — we can't dynamically parse and
execute SWF bytecode that wasn't pre-compiled.

**However**, the Ruffle test suite is structured so that each test directory has a fixed set of
assets (main `test.swf` plus child SWFs compiled from `target.fla`, `child.fla`, etc.). We know
at build time which SWFs a test will load. This means we can **pre-compile all SWFs** and link
them into the same binary, using a dispatch mechanism to "load" them at runtime.

---

## Test Inventory (49 tests) — 22 PASS, 27 FAIL

### Tier 1: Core loadMovie (8 tests) — 4 PASS

| Test | Status | Feature |
|------|--------|---------|
| loadmovie | ✅ PASS | Basic `loadMovie(url, target)` |
| loadmovie_method | ✅ PASS | `MovieClip.loadMovie(url)` method |
| loadmovie_fail | ✅ PASS | Error handling when load fails |
| loadmovie_replace_root | ✅ PASS | Loading into `_root` |
| loadmovie_flashvars | ✅ PASS | FlashVars parameter passing (regression fixed) |
| loadmovie_registerclass | ❌ output_mismatch | RegisterClass in loaded SWF |
| loadmovie_var_persistence | ❌ output_mismatch | Variable state across loaded SWFs (needs var clearing on load) |
| loading_avm2 | ❌ output_mismatch | Cross-AVM loading (AVM1→AVM2, **unfixable**) |

### Tier 2: loadMovieNum / _level targets (2 tests) — 1 PASS

| Test | Status | Feature |
|------|--------|---------|
| loadmovienum | ✅ PASS | Load into `_level0`, `_level1`, etc. |
| loadmovienum_cross_version_prototype | ❌ output_mismatch | Cross-version global scope isolation (Phase 6) |

### Tier 3: loadVariables (4 tests) — 3 PASS

| Test | Status | Feature |
|------|--------|---------|
| loadvariables | ✅ PASS | Load URL-encoded vars into clip |
| loadvariables2 | ✅ PASS | Load vars (variant) |
| loadvariablesnum | ✅ PASS | Load vars into `_levelN` |
| loadvariables_method | ❌ output_mismatch | Needs log_fetch / POST trace infra (**not feasible**) |

### Tier 4: MovieClipLoader class (14 tests) — 10 PASS

| Test | Status | Feature |
|------|--------|---------|
| mcl_as_broadcaster | ✅ PASS | AsBroadcaster inheritance |
| mcl_getprogress | ✅ PASS | `getProgress()` method |
| mcl_loadclip | ✅ PASS | `loadClip(url, target)` |
| mcl_loadclip_properties | ✅ PASS | Target clip properties after load |
| mcl_mislabeled_target | ✅ PASS | Invalid target handling |
| mcl_unloadclip | ✅ PASS | `unloadClip(target)` |
| moviecliploader_flashvars | ✅ PASS | FlashVars with MCL |
| mcl_target_gif87a | ✅ PASS | Load GIF87a |
| mcl_target_gif89a | ✅ PASS | Load GIF89a |
| mcl_target_jpg | ✅ PASS | Load JPEG |
| mcl_target_png | ✅ PASS | Load PNG |
| mcl_events_swf_version | ❌ output_mismatch | Version-specific event names (Phase 6) |
| mcl_loadclip_replace_root | ❌ output_mismatch | MCL loading into `_root` + cross-version |
| mcl_replace_root_swf7_to_swf5 | ❌ output_mismatch | Version downgrade via MCL |
| mcl_replace_root_swf7_to_swf6 | ❌ output_mismatch | Version transition via MCL |

### Tier 5: Secondary blockers (21 tests from other plans) — 4 PASS

| Test | Status | Blocked Plan | Feature |
|------|--------|-------------|---------|
| unloadmovie | ✅ PASS | UNLOAD | loadMovie + unloadMovie |
| unloadmovie_method | ✅ PASS | UNLOAD | loadMovie + unloadMovie() |
| unloadmovienum | ✅ PASS | UNLOAD | loadMovie + unloadMovieNum |
| movieclip_invalid_get_bounds_1 | ❌ output_mismatch | HIT_TESTING | getBounds on loaded clip |
| movieclip_invalid_get_bounds_2 | ❌ output_mismatch | HIT_TESTING | getBounds on loaded clip |
| movieclip_invalid_get_bounds_3 | ❌ output_mismatch | HIT_TESTING | getBounds on loaded clip |
| movieclip_invalid_get_bounds_4 | ❌ output_mismatch | HIT_TESTING | getBounds on loaded clip |
| movieclip_invalid_get_bounds_5 | ❌ output_mismatch | HIT_TESTING | getBounds on loaded clip |
| movieclip_invalid_get_bounds_6 | ❌ runtime_error | HIT_TESTING | getBounds on loaded clip |
| movieclip_invalid_get_bounds_7 | ❌ runtime_error | HIT_TESTING | getBounds on loaded clip |
| movieclip_invalid_get_bounds_8 | ❌ output_mismatch | HIT_TESTING | getBounds on loaded clip |
| root_button_mode | ❌ output_mismatch | BUTTON | Mouse events implemented; still needs loadMovie |
| movieclip_state_values | ❌ output_mismatch | MOVIECLIP | Clip state after load |
| movieclip_library_state_values | ❌ output_mismatch (77/78) | MOVIECLIP | Library state after load (segfault fixed) |
| movieclip_methods_with_loaded_image | ❌ output_mismatch | MOVIECLIP | MC methods on loaded image |
| do_init_action_child | ✅ PASS | MOVIECLIP | DoInitAction in child SWF (cross-version Phase 1+4) |
| register_class | ❌ output_mismatch | REGISTERCLASS | Child SWF + RegisterClass |
| register_class_swf6 | ❌ output_mismatch | REGISTERCLASS | Cross-version child SWF |
| global_swf5_6_7_8_9 | ❌ output_mismatch (1031/1145) | GLOBALS | Per-movie `_global` isolation (Phase 6) |
| global_swf6_7_8 | ✅ PASS (15/15) | GLOBALS | Cross-version Phase 1+4 |

---

## Existing Infrastructure

### What exists (implemented)

- **`_level0` / `_root` resolution** (action.c:7778-7787): Both resolve to `&root_movieclip`.
  Dot-path resolution for `_level0.child.grandchild` works.
- **`targetPath()`** (action.c:10698-10742): Returns `_level0` for root, `_level0.clip.child` for nested.
- **Recompiler emission** (action.cpp:1912-1931): Emits `actionGetURL2(app_context, method, loadTarget, loadVars)` with correct flags from SWF bytecode.
- **Multi-SWF build pipeline** (verify_output.py): Detects child .swf files, recompiles each via SWFRecomp, generates wrapper C files with symbol isolation (prefix-based renaming), generates movie_registry.c, compiles all together. Handles complex SWFs with buttons, clip events, sprites.
- **MovieEntry struct** (swf.h): `{ filename, frame_funcs, init_func, swf_version, frame_count, stage_width, stage_height }`. Runtime registry with `findMovieEntry()`.
- **actionGetURL2** (action.c:~16751): Handles loadTarget=1/loadVars=0 → calls `findMovieEntry()` + runs init + frame 0.
- **MC.loadMovie()** (action.c:~27235): Built-in MovieClip method, same flow as actionGetURL2.
- **Child SWF availability**: 110 child .swf files copied from upstream Ruffle repo. `download_tests.sh` updated to copy them.

### What does NOT exist (still needed)

- ~~**_level1+ management**~~: ✅ DONE — `g_levels[MAX_LEVELS]` with `getOrCreateLevel()`
- ~~**MovieClipLoader class**~~: ✅ DONE — loadClip, unloadClip, getProgress, deferred events
- ~~**unloadMovie()**~~: ✅ DONE — via empty URL in actionGetURL/GetURL2
- ~~**loadVariables()**~~: ✅ DONE — 3/4 tests pass (loadvariables, loadvariables2, loadvariablesnum)
- ~~**initVarArray protection**~~: ✅ DONE — child SWF init no longer clobbers parent's variable array
- **Cross-SWF global scope isolation**: SWF7+ need separate `_global` per loaded SWF. Blocks 4+ tests.
- **Proper clip clearing on loadMovie**: Current loadMovie just runs init+frame0 without clearing target clip state. Blocks loadmovie_var_persistence.
- ~~**DoInitAction for child SWFs**~~: ✅ DONE — do_init_action_child now 12/12 PASS.
- **getBounds on loaded clips**: Returns wrong values (loaded clip doesn't update display list properly). Blocks 8 tests.
- **MCL root replacement**: MCL loadClip into _root with cross-version transitions. Blocks 3 tests.

---

## Design: Pre-Compiled Multi-SWF Approach (Implemented)

Since our architecture is compile-time SWF-to-C, we pre-compile all SWFs in a test directory
and link them into a single binary. At runtime, `loadMovie("target.swf", mc)` looks up a
pre-compiled SWF by filename and instantiates it.

### Build pipeline (verify_output.py) — IMPLEMENTED

```
For each test directory with child .swf files:
  1. find_child_swfs() detects non-test.swf .swf files
  2. recompile_child_swf() runs SWFRecomp on each child in temp dir
  3. generate_child_movie_file() creates movie_<prefix>.c wrapper:
     - Reads all generated files (script_defs.c, script_N.c, tagMain.c, etc.)
     - Builds rename dict: str_N, script_N, func2_*, frame_N, sprite_N_frame_*,
       button_*_state_funcs, button_*_actions, clip_actions_* → prefix_*
     - Single-pass regex replacement (handles 2000+ symbols in <0.5s)
     - Generates forward declarations, inlined script bodies, MovieEntry struct
  4. generate_movie_registry() creates movie_registry.c with findMovieEntry()
  5. compile_native() compiles all .c files + runtime with -DHAS_CHILD_MOVIES
```

### Symbol isolation: Option A (prefix-based renaming) — IMPLEMENTED

Each child SWF's symbols are prefixed with a sanitized version of the filename
(`target.swf` → `target_`, `8LParent7L7.swf` → `m_8LParent7L7_`).
Handles: str_N, script_N, func2_*, func_anonymous_*, frame_N, frame_funcs,
sprite_N_frame_*, button_N_*, clip_actions_N, tagInit, frame_label_data/count.

### Movie registry (runtime) — IMPLEMENTED

```c
// In swf.h:
typedef struct MovieEntry {
    const char* filename;
    frame_func* frame_funcs;
    void (*init_func)(SWFAppContext*);
    u16 swf_version, frame_count, stage_width, stage_height;
} MovieEntry;

// Generated in movie_registry.c:
MovieEntry* findMovieEntry(const char* filename) {
    // Linear search through extern MovieEntry pointers
}
```

---

## Implementation Phases

### Phase 0: Child SWF compilation (verify_output.py) — DONE ✅

**Goal**: Get child SWFs compiled and linked into the test binary.

**Completed:**
1. ✅ `download_tests.sh` copies all non-test.swf .swf files from upstream Ruffle repo
2. ✅ 110 child .swf files copied from `~/CC/ruffle/tests/tests/swfs/avm1/`
3. ✅ `verify_output.py` detects child SWFs via `find_child_swfs()`
4. ✅ Each child SWF recompiled via `recompile_child_swf()` in temp dir
5. ✅ `generate_child_movie_file()` creates wrapper C with symbol isolation:
   - Prefix-based renaming (str_N, script_N, func2_*, frame_N, sprite_N_frame_*, button_*, clip_actions_*)
   - Single-pass regex replacement (fast even for 2000+ symbols)
   - Forward declarations for all symbol types
6. ✅ `generate_movie_registry()` creates findMovieEntry() dispatch
7. ✅ `compile_native()` links everything together with `-DHAS_CHILD_MOVIES`

### Phase 1: _level management (runtime) — DONE ✅

**Goal**: Support `_level0`, `_level1`, etc. as separate MovieClip roots.

**Completed:**
- ✅ `g_levels[MAX_LEVELS]` array with `g_levels[0] = &root_movieclip`
- ✅ `getOrCreateLevel(level_num)` creates synthetic MCs for higher levels
- ✅ `actionGetVariable` resolves `_levelN` (N > 0) to level MCs
- ✅ `getMovieClipByTarget` resolves `_levelN` paths
- ✅ Level MCs registered in `child_mc_cache` for lookup

**Tests passing**: loadmovienum ✅, unloadmovienum ✅

### Phase 2: Core loadMovie (runtime) — PARTIAL ✅

**Goal**: `loadMovie(url, target)` replaces a clip's content with a pre-compiled movie.

**Completed:**
- ✅ `MovieEntry` struct in swf.h with `findMovieEntry()` lookup
- ✅ `MC.loadMovie(url)` method in action.c MC dispatch chain (~line 27235)
- ✅ Basic flow: findMovieEntry → run init_func → run frame_funcs[0]

**Still needed:**
- Clear target clip's display list and variables before loading
- Proper target resolution (currently only works for the calling MC)
- DoInitAction support for child SWFs
- onLoad clip event firing
- Proper display list installation (loaded clip's children should appear on target)

**Tests passing**: loadmovie ✅, loadmovie_method ✅

### Phase 3: actionGetURL2 routing — DONE ✅

**Goal**: Route `actionGetURL2` calls to the correct handler based on flags.

**Completed:**
- ✅ actionGetURL2 now routes `loadTarget=1, loadVars=0` to findMovieEntry + init + frame 0
- ✅ Pops URL and target from stack, converts to UTF-8, looks up in registry

**Tests passing via this path**: loadmovie ✅ (uses GetURL2 opcode)

### Phase 4: MovieClipLoader class — DONE ✅

**Goal**: AS2 `MovieClipLoader` with broadcaster pattern.

**Completed:**
- ✅ MCL constructor auto-adds self as first listener (in actionNewObject)
- ✅ `loadClip(url, target)` — resolves target, queues deferred event dispatch
- ✅ `unloadClip(target)` — resolves target, fires onUnload
- ✅ `getProgress(target)` — returns {bytesLoaded, bytesTotal} object
- ✅ Deferred event dispatch at ShowFrame: onLoadStart/Progress/Complete (FIFO), child init, onLoadInit (LIFO)
- ✅ onLoadError for missing .swf URLs, onLoadInit for non-.swf URLs
- ✅ broadcastMessage this-binding for type 1 and type 2 functions
- ✅ Instance broadcastMessage overrides respected via property chain lookup

**Tests passing**: mcl_as_broadcaster ✅, mcl_getprogress ✅, mcl_loadclip ✅,
mcl_loadclip_properties ✅, mcl_unloadclip ✅, loadmovie_fail ✅

### Phase 5: unloadMovie — DONE ✅

**Goal**: Remove loaded content from a clip or level.

**Completed:**
- ✅ Empty URL in `actionGetURL2` and `MC.loadMovie("")` triggers onUnload handler
- ✅ `MC.unloadMovie()` method fires onUnload handler
- ✅ Target MC resolved from stack (direct MC pointer or name lookup)
- ✅ `actionGetURL("", "_levelN")` unloads level N (fires onUnload)
- ✅ Level MCs persist after unload (Flash behavior)

**Tests passing**: unloadmovie ✅, unloadmovie_method ✅, unloadmovienum ✅

### Phase 6: Cross-version global isolation

**Goal**: SWF7+ loaded movies get separate `_global` scope.

From Ruffle (`activation.rs:2797-2823`): Each loaded SWF at a different version gets its own
global scope. SWF 1-6 share one global, SWF 7+ each get their own.

**Tests enabled**: global_swf5_6_7_8_9, global_swf6_7_8, loadmovienum_cross_version_prototype

### Phase 7: loadVariables — DONE ✅

**Goal**: Load URL-encoded variables into a clip's variable space.

**Tests passing**: loadvariables ✅, loadvariables2 ✅, loadvariablesnum ✅

**Remaining**: loadvariables_method needs log_fetch / network POST trace infrastructure (not feasible)

---

## Feasibility Assessment

### What's feasible for trace tests

- **Pre-compiled multi-SWF linking**: Feasible if child .swf files exist or can be generated.
  The main challenge is symbol isolation in generated C code.
- **_level management**: Straightforward extension of existing `_level0` support.
- **loadMovie into target clip**: Feasible — clear clip, install new movie, run frame 0.
- **MovieClipLoader**: Straightforward AS2 object with broadcaster pattern.
- **unloadMovie**: Mostly done (removeMovieClip infrastructure exists).

### What's NOT feasible

- **loading_avm2**: Cross-AVM loading (AVM1→AVM2) is out of scope.
- **loadvariables_method**: Needs log_fetch / network POST trace infrastructure.

### Previously thought unfixable, now passing

- ~~**Image loading** (mcl_target_jpg/png/gif)~~: All 4 tests now PASS ✅
- ~~**loadmovie_fail**~~: Now PASS ✅

### Estimated impact (updated)

| Phase | Status | Tests Fixed | Difficulty |
|-------|--------|-----------|------------|
| 0 (build pipeline) | ✅ DONE | — (infrastructure) | High (done) |
| 1 (_level management) | ✅ DONE | loadmovienum ✅, unloadmovienum ✅ | Medium (done) |
| 2 (core loadMovie) | ✅ DONE | loadmovie ✅, loadmovie_method ✅, loadmovie_replace_root ✅ | High (done) |
| 3 (GetURL2/GetURL routing) | ✅ DONE | actionGetURL + actionGetURL2 _level routing | Low (done) |
| 4 (MovieClipLoader) | ✅ DONE | mcl_as_broadcaster ✅, mcl_getprogress ✅, mcl_loadclip ✅, mcl_loadclip_properties ✅, mcl_unloadclip ✅, loadmovie_fail ✅, mcl_target_gif87a ✅, mcl_target_gif89a ✅, mcl_target_jpg ✅, mcl_target_png ✅ | Medium (done) |
| 5 (unloadMovie) | ✅ DONE | unloadmovie ✅, unloadmovie_method ✅, unloadmovienum ✅ | Low (done) |
| 6 (global isolation) | BLOCKED | global_swf5_6_7_8_9, global_swf6_7_8, loadmovienum_cross_version_prototype, mcl_events_swf_version | Medium — needs per-SWF `_global` scope |
| 7 (loadVariables) | ✅ DONE | loadvariables ✅, loadvariables2 ✅, loadvariablesnum ✅ | Medium (done) |

**Current**: 24/49 passing (updated 2026-03-03). Remaining 25 failures are blocked by cross-version global
isolation, RegisterClass in child SWFs, MCL root replacement, variable
clearing on loadMovie, mouse events, getBounds after load, and AVM2 (unfixable).

---

## Open Questions (Resolved)

1. ~~**Child SWF availability**~~: **RESOLVED** — Upstream Ruffle repo at `~/CC/ruffle/tests/tests/swfs/avm1/` has pre-compiled child `.swf` files. 110 copied. `download_tests.sh` updated.

2. ~~**Symbol isolation strategy**~~: **RESOLVED** — Used Option A (prefix-based renaming) implemented in verify_output.py. Single-pass regex replacement handles str_N, script_N, func2_*, frame_N, sprite_N_frame_*, button_*, clip_actions_* symbols efficiently.

3. **Execution model**: Loaded movies share the global tick and advance in the same frame loop (confirmed from Ruffle source).

4. ~~**Priority**~~: loadMovie is the single largest blocker. Phases 0-3 complete, unblocking compile for all 49 tests.

---

## Files Modified / To Modify

### Build system (DONE)
| File | Status | Changes |
|------|--------|---------|
| `ruffle-tests/verify_output.py` | ✅ Done | +306 lines: find_child_swfs, recompile_child_swf, generate_child_movie_file, generate_movie_registry, compile_native updates |
| `ruffle-tests/download_tests.sh` | ✅ Done | Copy child .swf files from upstream |

### Runtime (Partial)
| File | Status | Changes |
|------|--------|---------|
| `SWFModernRuntime/include/libswf/swf.h` | ✅ Done | MovieEntry struct + findMovieEntry decl |
| `SWFModernRuntime/src/libswf/swf_core.c` | ✅ Done | Default findMovieEntry stub (when !HAS_CHILD_MOVIES) |
| `SWFModernRuntime/src/actionmodern/action.c` | Partial | MC.loadMovie method + actionGetURL2 routing done. Still needs: _levelN, MCL class, unloadMovie, global isolation |

### Still needed for remaining phases
| File | Changes Needed |
|------|----------------|
| `SWFModernRuntime/src/actionmodern/action.c` | Cross-SWF global isolation (Phase 6), variable clearing on loadMovie |
| `SWFModernRuntime/src/libswf/tag.c` | DoInitAction for child SWFs, display list update after load for getBounds |

---

## Ruffle Reference

Key files in `~/CC/ruffle/core/src/avm1/`:
- `activation.rs:1147-1289` — ActionGetURL2 handling, level/clip target resolution
- `activation.rs:2797-2823` — `get_or_create_level()`, level management
- `globals/movie_clip.rs:1613-1664` — `loadMovie()`, `unloadMovie()`, `loadVariables()` methods
- `globals/movie_clip_loader.rs` — MovieClipLoader class implementation
