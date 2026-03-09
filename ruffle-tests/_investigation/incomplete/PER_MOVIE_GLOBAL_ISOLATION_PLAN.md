# Per-Movie `_global` Isolation Plan

## Problem Statement

Our runtime uses a two-group `_global` model: `g_global_legacy` (SWF 1-6) and `g_global_modern` (SWF 7+). All loaded SWFs within the same version group share one `_global` object, one set of constructors, and one set of prototypes.

Flash/Ruffle gives **each loaded movie** its own `_global` with distinct constructor instances and distinct prototypes. This means:
- Two SWF8 movies loaded via `loadClip` get **different** `Object`, `Array`, `MovieClip`, `Boolean`, etc. constructors
- User-defined functions from different movies have **different** `Function.prototype` (so `func.__proto__` identity differs)
- Cross-movie `instanceof` fails by design (different constructor identity)
- SWF5 movies have no `_global` accessible via direct variable lookup (only via scope chain in functions)

**Current score**: 1031/1145 on `global_swf5_6_7_8_9` (114 failing lines), 6/9 on `loadmovienum_cross_version_prototype` (3 failing lines)

---

## Failure Analysis

### `global_swf5_6_7_8_9` — 177 diff lines (88 expected, 89 actual)

The parent SWF8 loads 5 children (SWF5, SWF6, SWF7, SWF8, SWF9) via `MovieClipLoader.loadClip`. Each child runs:
```actionscript
function getGlobal() { return _global; }
this.global = getGlobal();
this.global2 = _global;
this.anObjectClass = Object;
this.aMovieClipClass = MovieClip;
this.aBooleanClass = Boolean;
```

**Category A: SWF5 `_global` direct access should be undefined (4 diff lines)**
- Lines 16, 128: `typeof s1.global2` should be `undefined`, we return `object`
- SWF5 should NOT have `_global` accessible via direct `GetVariable("_global")`. The closure `getGlobal()` returns the global scope object (typeof=object, toString="undefined"), but direct `this.global2 = _global` should yield actual undefined.

**Category B: SWF5 Object constructor type (2 diff lines)**
- Lines 68, 96: `s1.anObjectClass` should print as `[type Function]`, we print `[object Object]`
- Our SWF5 child is getting a corrupted or wrong Object constructor reference

**Category C: `global2` identity comparisons (12 diff lines)**
- Lines 156, 198, 248, 356, 506, 548, 698, 748, 898, 1006, 1048, 1098
- Cross-version comparisons of `global2` fail because SWF5's `global2` should be `undefined` (not an object)

**Category D: `__proto__` identity on constructors/functions (~72 diff lines, bulk of failures)**
- `s1.aFunction.__proto__ == s2.aFunction.__proto__` should be `false` across different movies, we return `true`
- Same for `aMovieClipClass.__proto__` and `aBooleanClass.__proto__`
- Root cause: all user-defined functions from SWF7+ movies share the same Function.prototype because they share `g_global_modern`
- Each movie needs its own `Function.prototype` so that `func.__proto__` identity differs between movies

### `loadmovienum_cross_version_prototype` — 3 diff lines

- Line 3, 9: `_level2.testProp` should be empty after load/unload (dynamic_props clearing issue)
- Line 6: `_level2.__proto__ === MovieClip.prototype` should be `true` from SWF8 child's perspective — child's MovieClip.prototype should be set on the loaded MC's `__proto__`

---

## Current Architecture

### Data Structures (action.c)

```c
// Line 8043-8058
ASObject* global_object = NULL;                 // Active working pointer
static ASObject* g_global_legacy = NULL;        // SWF 1-6 shared
static ASObject* g_global_modern = NULL;        // SWF 7+ shared
static int g_primary_version_group = -1;        // 0=legacy, 1=modern
static ASObject* g_object_proto_legacy = NULL;
static ASObject* g_object_proto_modern = NULL;
static ASObject* g_array_proto_legacy = NULL;
static ASObject* g_array_proto_modern = NULL;

static inline int versionGroup(int version) { return (version <= 6) ? 0 : 1; }

static inline ASObject* getActiveGlobal(void) {
    ASObject* ag = global_object;
    if (g_swf_version <= 6 && g_global_legacy != NULL) ag = g_global_legacy;
    else if (g_swf_version > 6 && g_global_modern != NULL) ag = g_global_modern;
    return ag;
}
```

### ASFunction struct (action.c line 570)

```c
typedef struct ASFunction {
    char name[256];
    u8 function_type;
    u32 param_count;
    SimpleFunctionPtr simple_func;
    Function2Ptr advanced_func;
    u8 register_count;
    u16 flags;
    ASObject* prototype_obj;
    ASObject* own_props;
    u8 captured_scope_count;
    ASObject* captured_scope[8];
    MovieClip* captured_scope_mc[8];
    u8 captured_scope_is_with[8];
    MovieClip* base_clip;
    u16 swf_version;              // Phase 3: set at definition time
    // NO movie_global_idx yet
} ASFunction;
```

### MovieEntry struct (swf.h line 293)

```c
typedef struct MovieEntry {
    const char* filename;
    frame_func* frame_funcs;
    void (*init_func)(SWFAppContext*);
    u16 swf_version;
    u16 frame_count;
    u16 stage_width;
    u16 stage_height;
    // NO global_idx field yet
} MovieEntry;
```

### Key functions

| Function | Lines | Purpose |
|----------|-------|---------|
| `ensureGlobalInit()` | ~21160-21580 | Create primary `_global` with all constructors |
| `ensureSecondaryGlobalInit()` | ~21649-21851 | Create secondary version-group `_global` |
| `getActiveGlobal()` | ~8062 | Get version-appropriate `_global` |
| `switchToFunctionVersion()` | ~8075 | Save/restore SWF version + global for function calls |
| `getVersionedObjectProto()` | ~21853 | Get version-appropriate Object.prototype |
| `getVersionedArrayProto()` | ~21866 | Get version-appropriate Array.prototype |
| `actionGetVariable("_global")` | ~22685 | Return version-appropriate `_global` on stack |

### Load sites that switch version context (5 total)

1. `actionGetURL()` — `_levelN` target (line ~18941)
2. `actionGetURL()` — named clip target (line ~19039)
3. `actionGetURL2()` — loadMovie (line ~27124)
4. `actionFirePendingLoadInits()` — MCL deferred dispatch (line ~19700)
5. `actionImportAssets()` — ImportAssets2 (line ~19671)

### Recompiler `_global` references (action.cpp)

- `preload_global` in DefineFunction2 (line ~1535): emits `extern ASObject* global_object; regs[N] = global_object`
- `preload_parent + preload_global` combined (line ~1502): runtime register assignment
- `GetVariable` bytecode → `actionGetVariable(app_context)` which handles `"_global"` specially

---

## Proposed Design: Per-Movie Global Registry

### New data structure

```c
// Per-movie global tracking
typedef struct MovieGlobalEntry {
    const char* movie_filename;   // NULL for root movie
    u16 swf_version;
    ASObject* global_obj;         // This movie's _global
    ASObject* object_proto;       // This movie's Object.prototype
    ASObject* array_proto;        // This movie's Array.prototype
    ASObject* function_proto;     // This movie's Function.prototype (for __proto__ identity)
} MovieGlobalEntry;

#define MAX_MOVIE_GLOBALS 16
static MovieGlobalEntry g_movie_globals[MAX_MOVIE_GLOBALS];
static int g_movie_global_count = 0;
static int g_current_movie_global_idx = 0;  // Active movie global index
```

### Changes to existing structs

**ASFunction** — add movie context:
```c
typedef struct ASFunction {
    // ... existing fields ...
    u16 swf_version;
    u16 movie_global_idx;     // NEW: index into g_movie_globals[]
} ASFunction;
```

**MovieEntry** — add global index:
```c
typedef struct MovieEntry {
    // ... existing fields ...
    u16 global_idx;           // NEW: index into g_movie_globals[] (set at load time)
} MovieEntry;
```

### Shared singletons (NOT per-movie)

These objects are shared across all movies (same C pointer):
- `Math`, `Accessibility`, `Key`, `Mouse`, `Selection`, `Stage`
- `ASSetPropFlags`, `ASnative`
- `g_object_prototype` (the base Object.prototype with toString/valueOf/hasOwnProperty)

### Per-movie objects (NEW instance per movie)

Each movie gets its own:
- `_global` object (ASObject with constructors registered)
- Constructor ASFunction instances: `Object`, `Array`, `String`, `Number`, `Boolean`, `Function`, `MovieClip`, `TextField`, `TextFormat`, `XML`, `XMLNode`, `Date`, `Error`, 18 stubs
- `Object.prototype` (wraps shared base but distinct identity)
- `Array.prototype`
- `Function.prototype` (critical for `__proto__` identity on user functions)

---

## Implementation Phases

### Phase 1: Create `MovieGlobalEntry` registry and factory function

**Changes to `action.c`:**

1. Define `MovieGlobalEntry` struct and `g_movie_globals[]` array
2. Add `g_current_movie_global_idx` global (tracks which movie's context is active)
3. Refactor `ensureSecondaryGlobalInit()` into a general `createMovieGlobal(app_context, swf_version, filename)` factory that:
   - Allocates a fresh `_global` ASObject
   - Creates fresh constructor instances (Object, Array, String, etc.)
   - Creates fresh prototype objects (Object.prototype, Array.prototype, Function.prototype)
   - Registers all constructors on the new `_global`
   - Links shared singletons (Math, Key, etc.) from the primary global
   - Returns the index into `g_movie_globals[]`
4. `ensureGlobalInit()` becomes a wrapper: calls `createMovieGlobal()` for index 0 (root movie)
5. `ensureSecondaryGlobalInit()` is removed; replaced by `createMovieGlobal()` at each load site

**Key design decision**: The root movie (parent SWF) gets `g_movie_globals[0]`. Each `loadClip` / `loadMovie` / `loadMovieNum` call creates a new entry.

**Risk**: LOW — this phase only refactors internal initialization; external behavior unchanged until Phase 2.

### Phase 2: Wire up load sites to create per-movie globals

**Changes to `action.c`** (5 load sites):

At each load site, instead of:
```c
ensureSecondaryGlobalInit(app_context, entry->swf_version);
if (versionGroup(g_swf_version) == 0 && g_global_legacy) global_object = g_global_legacy;
else if (versionGroup(g_swf_version) == 1 && g_global_modern) global_object = g_global_modern;
```

Do:
```c
int gidx = createMovieGlobal(app_context, entry->swf_version, entry->filename);
entry->global_idx = gidx;
g_current_movie_global_idx = gidx;
global_object = g_movie_globals[gidx].global_obj;
```

After init:
```c
g_current_movie_global_idx = saved_movie_idx;
global_object = saved_global;
```

**Changes to `MovieEntry` in `swf.h`**: Add `u16 global_idx` field.

**Risk**: MEDIUM — changes what `global_object` points to during child init. All existing tests that don't use loadMovie should be unaffected (they always use index 0).

### Phase 3: Update ASFunction to capture movie context

**Changes to `action.c`**:

1. Add `u16 movie_global_idx` to ASFunction struct
2. In `actionDefineFunction()` and `actionDefineFunction2()`: set `as_func->movie_global_idx = g_current_movie_global_idx`
3. In `switchToFunctionVersion()`: use `func->movie_global_idx` to resolve the correct global instead of `versionGroup()`:
   ```c
   static inline void switchToFunctionVersion(ASFunction* func, int* saved_ver, ASObject** saved_global, int* saved_idx) {
       *saved_ver = g_swf_version;
       *saved_global = global_object;
       *saved_idx = g_current_movie_global_idx;
       if (func->swf_version != 0) {
           g_swf_version = func->swf_version;
           g_current_movie_global_idx = func->movie_global_idx;
           global_object = g_movie_globals[func->movie_global_idx].global_obj;
       }
   }
   ```

**Risk**: MEDIUM — must ensure built-in functions (swf_version=0, movie_global_idx=0) still resolve correctly. All zero-initialized static ASFunctions will have movie_global_idx=0 which is the root movie — correct.

### Phase 4: Update `getActiveGlobal()` and version-aware prototype getters

Replace version-group-based lookups with movie-index-based lookups:

```c
static inline ASObject* getActiveGlobal(void) {
    return g_movie_globals[g_current_movie_global_idx].global_obj;
}

static ASObject* getVersionedObjectProto(SWFAppContext* app_context) {
    ASObject* proto = g_movie_globals[g_current_movie_global_idx].object_proto;
    return proto ? proto : getObjectPrototype(app_context);
}

static ASObject* getVersionedArrayProto(SWFAppContext* app_context) {
    ASObject* proto = g_movie_globals[g_current_movie_global_idx].array_proto;
    return proto ? proto : g_array_prototype;
}
```

Also update `actionGetVariable("_global")` to use `g_movie_globals[g_current_movie_global_idx].global_obj`.

**Risk**: MEDIUM — this is the most pervasive change. All code that calls `getActiveGlobal()`, `getVersionedObjectProto()`, `getVersionedArrayProto()` will now resolve from the current movie context instead of version group.

### Phase 5: Per-movie Function.prototype for `__proto__` identity

This is the critical fix for the ~72 `__proto__` diff lines. Each movie's `createMovieGlobal()` must create a **distinct** Function.prototype object. When a user-defined function is created in that movie's context, its `__proto__` should point to that movie's Function.prototype.

Currently, user-defined functions get `__proto__` set to the shared Function.prototype. We need:

1. Store `function_proto` in `MovieGlobalEntry`
2. In `actionDefineFunction()` / `actionDefineFunction2()`: set the new function's `__proto__` to `g_movie_globals[g_current_movie_global_idx].function_proto`
3. Same for `actionInitObject()` and `actionInitArray()` — use per-movie prototypes

**Risk**: LOW if Phases 1-4 are solid — this is just adding one more per-movie prototype.

### Phase 6: SWF5 `_global` access restriction

In the test, SWF5's `this.global2 = _global` should yield `undefined`. This means `GetVariable("_global")` should NOT return the global object for SWF5 movies.

**Change in `actionGetVariable()`** (line ~22685):
```c
else if (var_name_len == 7 && strncmp(var_name, "_global", 7) == 0)
{
    if (g_swf_version < 6) {
        // SWF5 and below: _global is not a recognized variable
        PUSH(ACTION_STACK_VALUE_UNDEFINED, 0);
        return;
    }
    ensureGlobalInit(app_context);
    ASObject* active_global = g_movie_globals[g_current_movie_global_idx].global_obj;
    PUSH(ACTION_STACK_VALUE_OBJECT, (u64)active_global);
    return;
}
```

Also update the `GetMember` path for `_global` (line ~30472) similarly.

**Note**: `getGlobal()` (the closure) in SWF5 returning an object-typed value that prints as "undefined" is a separate issue — it involves scope chain resolution, not direct `GetVariable`. This may need further investigation but is lower priority (it already passes in the test output).

**Risk**: LOW — only affects SWF5 movies, which are rare. Regression guard: `swf5_global_funcs` must still PASS.

### Phase 7: Recompiler `preload_global` update

The recompiler currently emits `extern ASObject* global_object` for `preload_global`. This is fine — `global_object` is the working pointer that's already switched by `switchToFunctionVersion()` before the function body executes. No change needed here.

However, verify that the preload happens AFTER the version switch. In DefineFunction2 generated code, register init runs at the top of the function body, which is after `switchToFunctionVersion()` in the call dispatch. This should be correct.

**Risk**: NONE — no changes needed, just verification.

### Phase 8: Clean up legacy two-group infrastructure

Remove:
- `g_global_legacy`, `g_global_modern`
- `g_object_proto_legacy`, `g_object_proto_modern`
- `g_array_proto_legacy`, `g_array_proto_modern`
- `g_primary_version_group`, `g_secondary_global_init`
- `ensureSecondaryGlobalInit()`
- `versionGroup()` (unless used elsewhere for non-global purposes)

Replace all references with `g_movie_globals[]` lookups.

**Risk**: LOW — cleanup phase after everything works.

---

## Regression Risks

### High-risk areas

1. **All 501+ passing tests** — any bug in global resolution affects everything. The `getActiveGlobal()` function is called from dozens of code paths.
2. **Constructor identity** — `instanceof` checks, `__proto__` chains, `Object.registerClass` all depend on constructor resolution. Changing from shared to per-movie constructors could break tests that expect shared identity within the same SWF.
3. **Built-in function resolution** — The `actionGetVariable()` fallback paths for `"Array"`, `"Object"`, `"String"`, etc. (lines ~22698-22839) return static global constructors. These must be updated to return the current movie's constructors.

### Mitigation strategy

1. **Phase 1 first, test before Phase 2**: The refactoring in Phase 1 should produce identical behavior. Run regression tests.
2. **Root movie always index 0**: All single-SWF tests (the vast majority) use index 0 exclusively. Per-movie isolation only activates when `createMovieGlobal()` is called at load sites.
3. **Regression guard tests** (run after each phase):
   ```bash
   # Multi-SWF tests
   python3 ruffle-tests/verify_output.py --test=loadmovie_flashvars --test=moviecliploader_flashvars --test=mcl_as_broadcaster --test=mcl_mislabeled_target --test=unloadmovie --test=unloadmovie_method --test=unload_clip_event --test=unloadmovienum --test=as_set_prop_flags_version --test=global_swf6_7_8 --test=do_init_action_child --diff --verbose

   # Core functionality tests
   python3 ruffle-tests/verify_output.py --test=as2_super_and_this_v6 --test=as2_super_and_this_v8 --test=extends_chain --test=interface_implements_op --test=object_resolve --test=register_class_return_value --diff --verbose
   ```

---

## Tests Directly Impacted

| Test | Current | Expected After | Blocked Phase |
|------|---------|----------------|---------------|
| `global_swf5_6_7_8_9` | 1031/1145 | ~1145/1145 | Phases 2-6 |
| `loadmovienum_cross_version_prototype` | 6/9 | 9/9 | Phases 2-5 |
| `global_swf6_7_8` | 15/15 PASS | 15/15 PASS (no regression) | — |
| `register_class` | 26/67 | +lines (Phase 5 of CROSS_VERSION) | Phases 2-3 |
| `register_class_swf6` | 0/? | +lines | Phases 2-3 |

---

## Estimated Effort

| Phase | Effort | Files Changed |
|-------|--------|---------------|
| Phase 1: Registry + factory | Large | action.c |
| Phase 2: Load site wiring | Medium | action.c, swf.h |
| Phase 3: ASFunction movie context | Small | action.c |
| Phase 4: Prototype getters | Medium | action.c |
| Phase 5: Function.prototype identity | Small | action.c |
| Phase 6: SWF5 `_global` restriction | Small | action.c |
| Phase 7: Recompiler verification | Trivial | — (verify only) |
| Phase 8: Legacy cleanup | Small | action.c |

**Total**: ~400-600 lines of changes in `action.c`, ~5 lines in `swf.h`.

The bulk of the work is Phase 1 (refactoring `ensureGlobalInit`/`ensureSecondaryGlobalInit` into a general factory). The existing `ensureSecondaryGlobalInit()` already creates a complete secondary global with all constructors — the refactoring is primarily about making it general-purpose and indexed rather than binary (legacy/modern).

---

## Dependencies

- **Prerequisite**: None (can be started immediately)
- **Blocks**: CROSS_VERSION_ISOLATION_PLAN Phase 5, LOADMOVIE_PLAN Phase 6, REGISTERCLASS_PLAN (child SWF class registration), GLOBALS_PLAN Phase 8
- **Does NOT block**: Font metrics, SWF6 HTML, MC removal lifecycle, closure capture

---

## Open Questions

1. **SWF5 `getGlobal()` behavior**: The expected output shows `getGlobal()` returns an object (typeof=object) that prints as "undefined" in SWF5. How does this differ from direct `_global` access returning actual undefined? This may involve scope chain resolution subtleties — investigate during Phase 6 implementation.

2. **Reloading into same MC**: When `loadMovie` replaces content in an existing MC, should the old movie's global entry be reused or a new one created? Likely: reuse the entry and re-initialize it (avoids leaking entries).

3. **`unloadMovie`**: Should unloading a movie reset `g_current_movie_global_idx` for that MC's context? Probably: unloaded MCs should fall back to parent's movie global.

4. **Constructor fallback paths in `actionGetVariable()`**: The lazy-init paths for `"Array"`, `"Object"`, etc. (lines ~22698-22839) return static singletons. Should these be updated to return per-movie constructors? Likely yes, otherwise `GetVariable("Object")` bypasses per-movie isolation.
