# LoadMovie / Multi-SWF Infrastructure Plan
<!-- TESTS: loadmovie, loadmovie_fail, loadmovie_flashvars, loadmovie_method, loadmovie_registerclass, loadmovie_replace_root, loadmovie_var_persistence, loadmovienum, loadmovienum_cross_version_prototype, loadvariables, loadvariables2, loadvariables_method, loadvariablesnum, mcl_as_broadcaster, mcl_events_swf_version, mcl_getprogress, mcl_loadclip, mcl_unloadclip, moviecliploader_flashvars, mcl_loadclip_properties, mcl_loadclip_replace_root, mcl_mislabeled_target, mcl_replace_root_swf7_to_swf5, mcl_replace_root_swf7_to_swf6, mcl_target_gif87a, mcl_target_gif89a, mcl_target_jpg, mcl_target_png, loading_avm2, unloadmovie, unloadmovie_method, unloadmovienum, movieclip_invalid_get_bounds_1, movieclip_invalid_get_bounds_2, movieclip_invalid_get_bounds_3, movieclip_invalid_get_bounds_4, movieclip_invalid_get_bounds_5, movieclip_invalid_get_bounds_6, movieclip_invalid_get_bounds_7, movieclip_invalid_get_bounds_8, root_button_mode, movieclip_state_values, movieclip_library_state_values, movieclip_methods_with_loaded_image, do_init_action_child, register_class, register_class_swf6, global_swf5_6_7_8_9, global_swf6_7_8 -->

Last updated: 2026-02-23

## Status: NOT STARTED — 0/46 tests passing, ~46 tests blocked

This is the single largest blocker across the entire test suite. loadMovie infrastructure
is referenced as a blocker in BUTTON_PLAN, HIT_TESTING_PLAN, UNLOAD_PLAN, MOVIECLIP_PLAN,
GLOBALS_PLAN, REGISTERCLASS_PLAN, and others.

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

## Test Inventory (46 tests)

### Tier 1: Core loadMovie (8 tests)

| Test | Lines | Feature |
|------|-------|---------|
| loadmovie | 2 | Basic `loadMovie(url, target)` |
| loadmovie_method | 2 | `MovieClip.loadMovie(url)` method |
| loadmovie_fail | ? | Error handling when load fails |
| loadmovie_flashvars | ? | FlashVars parameter passing |
| loadmovie_registerclass | ? | RegisterClass in loaded SWF |
| loadmovie_replace_root | ? | Loading into `_root` |
| loadmovie_var_persistence | ? | Variable state across loaded SWFs |
| loading_avm2 | ? | Cross-AVM loading (AVM1->AVM2, likely unfixable) |

### Tier 2: loadMovieNum / _level targets (2 tests)

| Test | Lines | Feature |
|------|-------|---------|
| loadmovienum | 3 | Load into `_level0`, `_level1`, etc. |
| loadmovienum_cross_version_prototype | ? | Cross-version global scope isolation |

### Tier 3: loadVariables (4 tests)

| Test | Lines | Feature |
|------|-------|---------|
| loadvariables | ? | Load URL-encoded vars into clip |
| loadvariables2 | ? | Load vars (variant) |
| loadvariables_method | ? | `MovieClip.loadVariables()` method |
| loadvariablesnum | ? | Load vars into `_levelN` |

### Tier 4: MovieClipLoader class (14 tests)

| Test | Lines | Feature |
|------|-------|---------|
| mcl_as_broadcaster | ? | AsBroadcaster inheritance |
| mcl_events_swf_version | ? | Version-specific event names |
| mcl_getprogress | ? | `getProgress()` method |
| mcl_loadclip | 150 | `loadClip(url, target)` |
| mcl_unloadclip | ? | `unloadClip(target)` |
| moviecliploader_flashvars | ? | FlashVars with MCL |
| mcl_loadclip_properties | ? | Target clip properties after load |
| mcl_loadclip_replace_root | ? | MCL loading into `_root` |
| mcl_mislabeled_target | ? | Invalid target handling |
| mcl_replace_root_swf7_to_swf5 | ? | Version downgrade |
| mcl_replace_root_swf7_to_swf6 | ? | Version transition |
| mcl_target_gif87a | ? | Load GIF87a (image, not SWF) |
| mcl_target_gif89a | ? | Load GIF89a |
| mcl_target_jpg | ? | Load JPEG |
| mcl_target_png | ? | Load PNG |

### Tier 5: Secondary blockers (18 tests from other plans)

| Test | Lines | Blocked Plan | Feature |
|------|-------|-------------|---------|
| movieclip_invalid_get_bounds_1-8 | 75/13/13/13/11/10/10/11 | HIT_TESTING | getBounds on loaded clip |
| root_button_mode | 10 | BUTTON | createEmptyMovieClip + loadMovie |
| movieclip_state_values | 114 | MOVIECLIP | Clip state after load |
| movieclip_library_state_values | 78 | MOVIECLIP | Library state after load |
| movieclip_methods_with_loaded_image | 4 | MOVIECLIP | Image loading |
| do_init_action_child | 12 | MOVIECLIP | DoInitAction in child SWF |
| unloadmovie | 4 | UNLOAD | loadMovie + unloadMovie |
| unloadmovie_method | 3 | UNLOAD | loadMovie + unloadMovie() |
| unloadmovienum | 13 | UNLOAD | loadMovie + unloadMovieNum |
| register_class | ? | REGISTERCLASS | Child SWF + RegisterClass |
| register_class_swf6 | ? | REGISTERCLASS | Cross-version child SWF |
| global_swf5_6_7_8_9 | 1145 | GLOBALS | Multi-SWF global isolation |
| global_swf6_7_8 | 15 | GLOBALS | Multi-SWF globals |

---

## Existing Infrastructure

### What exists

- **`_level0` / `_root` resolution** (action.c:7778-7787): Both resolve to `&root_movieclip`.
  Dot-path resolution for `_level0.child.grandchild` works.
- **`targetPath()`** (action.c:10698-10742): Returns `_level0` for root, `_level0.clip.child` for nested.
- **`actionGetURL2` stub** (action.c:16692-16755): Recompiler emits calls to `actionGetURL2()`.
  Currently only handles FSCommand protocol; movie/variable loading is stubbed out.
- **Recompiler emission** (action.cpp:1912-1931): Emits `actionGetURL2(app_context, method, loadTarget, loadVars)` with correct flags from SWF bytecode.

### What does NOT exist

- **_level1+ management**: Only `_level0` exists. No container for multiple levels.
- **External SWF loading/parsing**: No runtime SWF parser. No HTTP/file I/O.
- **Multi-SWF binary linking**: No mechanism to compile multiple SWFs into one binary.
- **MovieClipLoader class**: Not implemented.
- **unloadMovie()**: Not implemented (actionRemoveSprite exists but is different).
- **loadVariables()**: Not implemented.
- **Cross-SWF global scope isolation**: SWF7+ need separate `_global` per loaded SWF.

---

## Design: Pre-Compiled Multi-SWF Approach

Since our architecture is compile-time SWF-to-C, we pre-compile all SWFs in a test directory
and link them into a single binary. At runtime, `loadMovie("target.swf", mc)` looks up a
pre-compiled SWF by filename and instantiates it.

### Build pipeline changes (verify_output.py)

```
For each test directory:
  1. Find all .swf files (test.swf, target.swf, child.swf, etc.)
  2. Recompile EACH .swf through SWFRecomp → generates separate script_defs.c / tag_funcs.c
  3. Rename generated symbols to avoid collisions:
     - test.swf  → script_defs_main.c, tag_funcs_main.c
     - target.swf → script_defs_target.c, tag_funcs_target.c
  4. Generate a movie_registry.c that maps filenames → init functions
  5. Compile all C files + runtime into single binary
```

### Movie registry (runtime)

```c
// Generated at compile time:
typedef struct {
    const char* filename;        // "target.swf"
    void (*init_tags)(SWFAppContext*);   // sets up dictionary, frames
    void (*init_scripts)(SWFAppContext*); // registers frame scripts
    u16 swf_version;
    u16 frame_count;
    u16 stage_width, stage_height;
} MovieEntry;

static MovieEntry g_movie_registry[] = {
    { "target.swf", target_init_tags, target_init_scripts, 8, 1, 550, 400 },
    { NULL, NULL, NULL, 0, 0, 0, 0 }
};
```

### Runtime loadMovie flow

```c
void actionLoadMovie(SWFAppContext* app_context, const char* url, MovieClip* target) {
    // 1. Look up url in g_movie_registry
    MovieEntry* entry = findMovieEntry(url);
    if (!entry) { /* fire onLoadError */ return; }

    // 2. Save current target clip state
    // 3. Clear target clip's display list and variables
    // 4. Set target clip's movie context to the loaded movie
    // 5. Run loaded movie's tag init (populates dictionary for the loaded clip)
    // 6. Run loaded movie's frame 0 script
    // 7. Fire onLoadComplete / onLoadInit callbacks
}
```

### Key challenge: Symbol isolation

Each compiled SWF generates functions and data with potentially conflicting names
(`frame_0_func`, `dictionary`, etc.). Solutions:

**Option A: Namespace prefixing** — Recompiler prefixes all symbols with SWF name:
`test_frame_0_func`, `target_frame_0_func`. Requires recompiler changes.

**Option B: Separate compilation units with static linkage** — Each SWF's generated code
uses `static` globals. An init function exposes them via function pointers. Minimal
recompiler changes.

**Option C: Per-movie SWFAppContext** — Each loaded movie gets its own context struct
with its own dictionary, display list, etc. The parent clip hosts the child context.
Most architecturally clean but largest change.

**Recommended: Option B** — least invasive. Each SWF compiles to a .c file with static
globals. A generated init function populates function pointers into a MovieEntry struct.

---

## Implementation Phases

### Phase 0: Child SWF compilation (verify_output.py)

**Goal**: Get child SWFs compiled and linked into the test binary.

1. Detect `.swf` files beyond `test.swf` in test directories
2. Check for pre-existing `target.swf` or compile from `.fla` if needed
   (Note: most Ruffle test dirs have `.fla` source only, not compiled `.swf` for children.
   We may need to compile `.fla` → `.swf` using a tool, or check if the Ruffle repo has
   pre-compiled versions.)
3. Run SWFRecomp on each child SWF with symbol prefixing
4. Compile all generated C files together

**Blocker investigation needed**: Do the Ruffle test directories in the upstream Ruffle repo
(`~/CC/ruffle/tests/tests/swfs/avm1/`) have pre-compiled child `.swf` files? If so, we can
copy them. If not, we need a Flash/Animate compiler or use Ruffle's own test harness to
generate them.

### Phase 1: _level management (runtime)

**Goal**: Support `_level0`, `_level1`, etc. as separate MovieClip roots.

```c
// In swf.h or action.c:
#define MAX_LEVELS 16
static MovieClip* g_levels[MAX_LEVELS];  // g_levels[0] = &root_movieclip

MovieClip* getLevel(int level_id) {
    if (level_id < 0 || level_id >= MAX_LEVELS) return NULL;
    return g_levels[level_id];
}

MovieClip* getOrCreateLevel(int level_id) {
    if (g_levels[level_id]) return g_levels[level_id];
    // Allocate new MovieClip at this level
    // ...
    return g_levels[level_id];
}
```

Update `actionGetVariable` to resolve `_level1`, `_level2`, etc. (currently only `_level0`).

**Tests enabled**: loadmovienum (partial — still needs movie loading)

### Phase 2: Core loadMovie (runtime)

**Goal**: `loadMovie(url, target)` replaces a clip's content with a pre-compiled movie.

Key behaviors from Ruffle reference (`~/CC/ruffle/core/src/avm1/activation.rs:1147-1289`):
- Resolve target (string path → MovieClip, or level number)
- Clear target's display list and variables
- Load new movie's dictionary and frames into target
- Run frame 0 of loaded movie
- Fire `onLoad` clip event

```c
void actionLoadMovie(SWFAppContext* app, const char* url, const char* target_path) {
    MovieEntry* entry = findMovieEntry(url);
    if (!entry) return;

    // Resolve target
    MovieClip* target = resolveMovieClipPath(target_path);
    if (!target) return;

    // Clear target
    clearMovieClipContent(target);

    // Install loaded movie
    installMovie(app, target, entry);

    // Fire callbacks
    dispatchOnLoadComplete(target);
}
```

**Tests enabled**: loadmovie, loadmovie_method

### Phase 3: actionGetURL2 routing

**Goal**: Route `actionGetURL2` calls to the correct handler based on flags.

From SWF spec, ActionGetURL2 flags:
- `LoadTargetFlag=1, LoadVariablesFlag=0` → loadMovie
- `LoadTargetFlag=1, LoadVariablesFlag=1` → loadVariables
- `LoadTargetFlag=0` → browser navigation (no-op in trace mode)

```c
void actionGetURL2(SWFAppContext* app, u8 method, u8 loadTarget, u8 loadVars) {
    // Pop target and URL from stack
    char* target = popString();
    char* url = popString();

    if (loadTarget) {
        if (loadVars) {
            actionLoadVariables(app, url, target, method);
        } else {
            actionLoadMovie(app, url, target);
        }
    }
    // else: browser navigation, ignored in trace mode
}
```

**Tests enabled**: Any test using GetURL2 opcode for loading

### Phase 4: MovieClipLoader class

**Goal**: AS2 `MovieClipLoader` with broadcaster pattern.

```c
// MovieClipLoader is an ASObject with:
// - loadClip(url, target) method
// - unloadClip(target) method
// - getProgress(target) method
// - addListener(obj) / removeListener(obj) via AsBroadcaster mixin

void mclLoadClip(SWFAppContext* app, ActionVar* args, u32 arg_count) {
    char* url = convertToString(args[0]);
    // target can be: string path, number (level), or MovieClip object
    MovieClip* target = resolveTarget(args[1]);

    MovieEntry* entry = findMovieEntry(url);
    if (!entry) {
        broadcastMessage(mcl, "onLoadError", target, "URLNotFound", 0);
        return;
    }

    broadcastMessage(mcl, "onLoadStart", target);
    installMovie(app, target, entry);
    broadcastMessage(mcl, "onLoadComplete", target, 0);
    // onLoadInit fires after first frame executes
}
```

**Tests enabled**: mcl_loadclip, mcl_as_broadcaster, mcl_getprogress, mcl_unloadclip, etc.

### Phase 5: unloadMovie

**Goal**: Remove loaded content from a clip or level.

```c
void actionUnloadMovie(SWFAppContext* app, MovieClip* target) {
    // Fire onUnload clip event
    dispatchClipEvent(target, CLIP_EVENT_UNLOAD);

    // Clear display list
    clearDisplayList(target);

    // Clear variables
    clearVariables(target);

    // Reset to empty state (1 frame, no content)
}
```

**Tests enabled**: unloadmovie, unloadmovie_method, unloadmovienum

### Phase 6: Cross-version global isolation

**Goal**: SWF7+ loaded movies get separate `_global` scope.

From Ruffle (`activation.rs:2797-2823`): Each loaded SWF at a different version gets its own
global scope. SWF 1-6 share one global, SWF 7+ each get their own.

**Tests enabled**: global_swf5_6_7_8_9, global_swf6_7_8, loadmovienum_cross_version_prototype

### Phase 7: loadVariables

**Goal**: Load URL-encoded variables into a clip's variable space.

For trace tests, the "loaded" data would need to be pre-bundled (similar to pre-compiled SWFs).
This may be low priority since it requires simulating network responses.

**Tests enabled**: loadvariables, loadvariables2, loadvariables_method, loadvariablesnum

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

- **Image loading** (mcl_target_jpg/png/gif): Would require image decoders. These 4 tests
  are likely unfixable in trace mode.
- **loading_avm2**: Cross-AVM loading is out of scope.
- **Network-dependent loadVariables**: Would need pre-bundled response data.
- **loadmovie_fail**: Error handling for missing URLs requires simulated failure.

### Estimated impact

| Phase | Tests Fixed | Cumulative | Difficulty |
|-------|-----------|------------|------------|
| 0-2 | ~4 (loadmovie, loadmovie_method, loadmovienum partial) | ~4 | High |
| 3 | ~2 (GetURL2 routing) | ~6 | Low |
| 4 | ~6 (MCL core) | ~12 | Medium |
| 5 | ~3 (unloadmovie variants) | ~15 | Low |
| 6 | ~2 (global isolation) | ~17 | Medium |
| 7 | ~4 (loadVariables) | ~21 | Medium |
| Secondary | ~10 (getBounds, buttons, registerClass) | ~31 | Varies |

**Realistically fixable**: ~25-31 of the 46 tests. Image loading (4), loading_avm2 (1),
and some edge cases (~10) are likely unfixable.

---

## Open Questions

1. **Child SWF availability**: Do Ruffle test directories in `~/CC/ruffle/tests/tests/swfs/avm1/`
   have pre-compiled child `.swf` files? Or only `.fla` source? If only `.fla`, we need a
   Flash-to-SWF compiler (or extract from the Ruffle test harness).

2. **Symbol isolation strategy**: Option A (prefixing) vs Option B (static linkage) vs
   Option C (per-movie context). Needs prototyping to determine which is least invasive.

3. **Execution model**: When a loaded movie has multiple frames, does it advance on the
   same tick as the parent? Or does it have its own timeline? (Answer from Ruffle: loaded
   movies share the global tick and advance in the same frame loop.)

4. **Priority**: Should we prioritize this over other blocker categories (closure capture,
   morph interpolation)? loadMovie unblocks the most tests (~46) but is also the most
   complex infrastructure change.

---

## Files to Modify

### Build system
| File | Changes |
|------|---------|
| `ruffle-tests/verify_output.py` | Detect child SWFs, compile each, link together |
| `SWFRecomp/scripts/build_test.sh` | Support multi-SWF compilation |

### Recompiler
| File | Changes |
|------|---------|
| `SWFRecomp/src/action/action.cpp` | Symbol prefixing for multi-SWF builds |
| `SWFRecomp/src/swf.cpp` | Per-SWF init function generation |

### Runtime
| File | Changes |
|------|---------|
| `SWFModernRuntime/include/libswf/swf.h` | MovieEntry struct, level array, MovieClipLoader |
| `SWFModernRuntime/src/actionmodern/action.c` | loadMovie/unloadMovie, _levelN resolution, MCL class, global scope isolation |
| `SWFModernRuntime/src/libswf/tag.c` | Movie installation into target clip, display list clearing |
| `SWFModernRuntime/src/libswf/swf_core.c` | Multi-movie frame advancement |

---

## Ruffle Reference

Key files in `~/CC/ruffle/core/src/avm1/`:
- `activation.rs:1147-1289` — ActionGetURL2 handling, level/clip target resolution
- `activation.rs:2797-2823` — `get_or_create_level()`, level management
- `globals/movie_clip.rs:1613-1664` — `loadMovie()`, `unloadMovie()`, `loadVariables()` methods
- `globals/movie_clip_loader.rs` — MovieClipLoader class implementation
