# Runtime SWF / Code Injection Demos

## Background

LittleCube proposed implementing the AS2 runtime through mostly actual AS2 code,
building a "runtime" SWF from it, and recompiling that SWF before the game SWF.
This would lower the barrier to entry for contributing to the runtime API — people
write ActionScript instead of C.

This plan sets up exploratory demos to evaluate different approaches to this idea
and understand what each approach can and cannot see inside a target SWF.

## Goals

1. Determine what a loaded SWF can see inside another SWF (properties, functions,
   dictionary entries, `_global` contributions).
2. Compare three different injection/inspection approaches.
3. Identify which approach best supports the "runtime SWF" architecture where AS2
   code provides runtime API implementations.

## Status: Demos 1 and 3 Complete

Both demos live in `demos/runtime-swf/` and use `verify_output.py --tests-dir`:
- `demos/runtime-swf/loadmovie_enumerate/` — Demo 1
- `demos/runtime-swf/loadmovie_c_inspect/` — Demo 3

Run with:
```bash
python3 ruffle-tests/verify_output.py --tests-dir=demos/runtime-swf --test=loadmovie_enumerate --diff --verbose
python3 ruffle-tests/verify_output.py --tests-dir=demos/runtime-swf --test=loadmovie_c_inspect --diff --verbose
```

## Experimental Results

### Demo 1: loadMovie Inspection (ActionScript) — PASS

**Test:** `loadmovie_enumerate`

ActionScript in the parent SWF can see everything in the loaded child:

| What | Visible? | Method |
|------|----------|--------|
| Timeline variables (myVar, childNum, childBool, childObj) | Yes | `for..in` on holder MC |
| Timeline functions (myFunc) | Yes | `for..in`, `typeof`, callable via `holder.myFunc()` |
| `_global.childGlobal` | Yes | `_global.childGlobal` returns "child was here" |
| `MovieClip.prototype.childMethod` | Yes | `typeof` = "function", callable |
| `_totalframes` | Yes | Returns 2 (child's frame count) |
| `_currentframe` | Yes | Returns 1 |
| Object properties | Yes | `childObj` is `[object Object]` |

**Key finding:** ActionScript has unified visibility — `for..in` and `GetMember`
integrate multiple data sources (var_array, dynamic_props, prototype chain, builtins)
into a single coherent view.

### Demo 3: C Code Injection (test_harness) — PASS

**Test:** `loadmovie_c_inspect`

C code via `test_harness.c` sees a much more limited view:

| What | Visible? | Why |
|------|----------|-----|
| MovieClip struct (name, address) | Yes | `actionFindOrCreateMovieClip()` works |
| MC `totalframes` | 1 (wrong — should be 2) | Child frame count not synced to holder MC struct |
| `dynamic_props` (ASObject*) | NULL | Child's `SetVariable` stores in var_array, not MC props |
| `_global.childGlobal` | Not found | Child's `_global` modifications not visible on `global_object` |
| var_array | Only parent's slots visible | Child's string_id-offset variables not accessible |
| Display list | Empty (root level) | `createEmptyMovieClip` depth not in scanned range |
| Dictionary | Empty | Expected in NO_GRAPHICS mode |

**Key finding:** C code sees raw struct fields but NOT the integrated variable
scope. The ActionScript runtime functions (`actionGetVariable`, `actionGetMember`,
`actionEnumerate2`) combine var_array lookups, dynamic_props, prototype chain
walking, and builtin property synthesis into a unified view. Raw C struct access
skips all of this integration.

### Comparison

| Capability | Demo 1 (AS) | Demo 3 (C) |
|-----------|-------------|------------|
| Timeline variables | Full access | Not accessible (stored in var_array, not MC props) |
| Timeline functions | Callable | Not accessible |
| `_global` contributions | Visible | Not visible (version-isolated globals) |
| Prototype modifications | Visible | Not directly (would need to walk ASObject chain) |
| MC struct fields | Indirect (via builtins) | Direct pointer access |
| Display list | Not directly | Direct struct iteration |
| Dictionary | Not accessible | Direct struct iteration (but empty in NO_GRAPHICS) |
| Execution hooks | Limited to AS timing | Full control (after-tick, before-init) |

### Implications for the Runtime SWF Architecture

1. **ActionScript approach (Demo 1 / LittleCube's idea) is more natural** for
   runtime API implementation. AS code has full visibility into the object model
   and can modify prototypes, _global, etc. naturally.

2. **C approach (Demo 3) is better for low-level integration** — renderer
   interface, display list manipulation, dictionary access. But it cannot easily
   participate in the ActionScript scope chain.

3. **The ideal architecture is hybrid:** Runtime API implementations written in
   AS2 (compiled into a prelude SWF) for the high-level API surface, with C
   code providing the low-level bridge to the renderer and other native systems.

## Bugs Discovered

1. **Child SWF `stop()` stops the root timeline.** During deferred loadMovie
   execution (`actionFirePendingDirectLoads`), `g_current_sprite_obj` is not set,
   so `actionStop()` falls through to `is_playing = 0` on the root MC. This is
   because the deferred load doesn't go through `exec_sprite_frame` which normally
   sets `g_current_sprite_obj`.

2. **AVM1 SetVariable stack convention.** The runtime's `actionSetVariable()`
   expects value at SP (top) and name at SP_SECOND_TOP (second). The standard
   AVM1 bytecode convention is: push name first (bottom), push value second (top).
   The code comments are correct but easily misread. For hand-authored bytecode:
   push name first, then value.

## Demos

### Demo 1: loadMovie Inspection (ActionScript)

**Test location:** `demos/runtime-swf/loadmovie_enumerate/`

**Files:**
- `create_test_swf.py` — generates parent SWF (3 frames: load, wait, enumerate)
- `create_target_swf.py` — generates child SWF (variables, functions, _global mods)
- `test.toml` — `num_frames = 3`
- `output.txt` — expected output (27 lines)

**Implementation notes:**
- SWFs authored as raw AVM1 bytecode via Python struct.pack
- Uses `GetURL2` with `loadTarget=1` for loadMovie (same as Flash compiler output)
- `for..in` loop uses `Enumerate2` + `StoreRegister` + `Equals2(null)` pattern
- Each iteration consumes one name from the stack via `Equals2` popping both operands
- Child SWF must NOT call `stop()` (see bug #1 above)
- Parent uses `FSCommand:quit` to cleanly exit the frame loop

### Demo 2: Bytecode Injection (Skipped)

Not implemented. The results from Demos 1 and 3 provide sufficient insight.
If needed, bytecode injection would require modifying the recompiler's bytecode
parsing to prepend/append extra actions before the normal translation.

### Demo 3: C Code Injection (test_harness)

**Test location:** `demos/runtime-swf/loadmovie_c_inspect/`

**Files:**
- `create_test_swf.py` — generates minimal parent SWF (load child, wait, quit)
- `create_target_swf.py` — same child SWF as Demo 1
- `test_harness.c` — C code that runs after tick 2 via `g_after_tick_handler`
- `test.toml` — `num_frames = 3`
- `output.txt` — expected output (20 lines)

**What the harness inspects:**
- `actionFindOrCreateMovieClip()` to get the holder MC
- `holder->dynamic_props` (ASObject*) for timeline variables
- `global_object` for `_global` properties
- `var_array` for string-id-indexed variable storage
- `display_list` for root-level display objects
- `dictionary` for character definitions

### Demo 4: Prelude SWF (LittleCube's Full Vision) — Not Yet Implemented

**Approach:** A "runtime" SWF is recompiled to C and statically linked with the game
SWF. The runtime SWF's init code runs *before* the game SWF's init, in the same
scope. The game SWF sees the runtime's `_global` definitions as if they were native
builtins.

**Implementation plan:**
- Add a new execution mode in `swf_core.c`: before `tagInit` + frame 0 of the main
  SWF, run prelude SWFs' init + frame 0
- Prelude SWFs share the same `_global`, var_array, and scope chain as the main SWF
- Use existing `MovieEntry`/`movie_registry.c` infrastructure with a "prelude" flag
- The prelude SWF's `_global` modifications (prototype setups, constructor
  definitions) would be immediately available to the game SWF

**Key question answered by Demo 1:** ActionScript CAN modify `_global` and
`MovieClip.prototype` from a loaded SWF, and those modifications are visible to
the parent. This validates the core premise of LittleCube's idea.

## Open Questions

- **Demo 4 scope isolation:** Should the prelude SWF run in the same var_array scope
  as the main SWF, or a separate scope? The child in Demo 1 uses a separate scope
  (var_array with string_id offset), but a prelude SWF should probably share scope.
- **Version matching:** The prelude SWF should match the game's SWF version to avoid
  version-group isolation (SWF≤6 vs SWF7+ have separate `_global` objects).
- **Multiple prelude SWFs:** Should the architecture support chaining multiple
  prelude SWFs? (e.g., core runtime + game-specific overrides)
