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

## Status: All Demos Complete

All three demos live in `demos/runtime-swf/` and use `verify_output.py --tests-dir`:
- `demos/runtime-swf/loadmovie_enumerate/` — Demo 1 (AS loadMovie inspection)
- `demos/runtime-swf/loadmovie_c_inspect/` — Demo 3 (C test_harness inspection)
- `demos/runtime-swf/prelude_swf/` — Demo 4 (prelude SWF, LittleCube's idea)

Run all:
```bash
python3 ruffle-tests/verify_output.py --tests-dir=demos/runtime-swf --diff --verbose
```

Regression test (all 9 loadmovie + 14 MCL tests verified, no regressions from
the prelude/stop-fix changes; 3 MCL failures are pre-existing):
```bash
python3 ruffle-tests/verify_output.py --test='loadmovie*' --diff --verbose
python3 ruffle-tests/verify_output.py --test='mcl_*' --diff --verbose
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

### Demo 4: Prelude SWF (LittleCube's Full Vision) — PASS

**Test:** `prelude_swf`

A prelude SWF's setup is fully visible to the main SWF on its first frame:

| What | Visible? | Detail |
|------|----------|--------|
| `_global.runtimeVersion` | Yes | Returns "1.0" |
| `_global.runtimeReady` | Yes | Returns true |
| `MovieClip.prototype.greet` | Yes | `this.greet()` traces "hello from runtime" |
| `_global.Greeter` constructor | Yes | `typeof Greeter` = "function" |
| `new Greeter("World")` | Yes | Constructor sets `this.name = "World"` |
| `greeter.sayHi()` | Yes | Traces "Hi, I'm World" via prototype method |

**Key finding:** Prelude SWFs share the same `_global`, var_array, and prototype
chains as the main SWF. Everything the prelude defines is immediately available —
no deferred loading, no scope isolation, no version-group barriers (when versions
match). This fully validates LittleCube's proposal.

### Comparison

| Capability | Demo 1 (AS loadMovie) | Demo 3 (C harness) | Demo 4 (Prelude) |
|-----------|----------------------|--------------------|--------------------|
| Timeline variables | Full access | Not accessible | Shared scope |
| Timeline functions | Callable | Not accessible | Shared scope |
| `_global` contributions | Visible | Not visible | Shared `_global` |
| Prototype modifications | Visible | Not directly | Shared prototypes |
| Custom constructors | N/A (not tested) | N/A | Full OOP support |
| Timing | Deferred (next frame) | After-tick hook | Before first frame |
| Scope isolation | Separate var_array | Raw struct access | None (shared) |
| MC struct fields | Indirect (builtins) | Direct pointer | Indirect (builtins) |

### Implications for the Runtime SWF Architecture

1. **Demo 4 (prelude SWF) is the clear winner** for LittleCube's proposal.
   It provides shared scope, immediate availability, and full OOP support
   (constructors, prototypes, inheritance). Contributors can write AS2 code
   that "just works" as if it were built into the runtime.

2. **Demo 1 (loadMovie) is useful for dynamic content** but the deferred loading
   and scope isolation make it unsuitable for runtime API bootstrapping.

3. **Demo 3 (C harness) is complementary** — best for low-level integration
   (renderer bridge, display list manipulation) that AS2 can't do alone.

4. **The ideal architecture is hybrid:** Prelude SWFs for high-level AS2 runtime
   APIs, with C code providing the low-level bridge to native systems (renderer,
   audio, input). The prelude's AS2 code can call C functions exposed via
   `ExternalInterface` or similar bridging mechanisms.

## Bugs Discovered and Fixed

1. **Child SWF `stop()` stops the root timeline (FIXED).**
   During deferred loadMovie execution (`actionFirePendingDirectLoads`),
   `g_current_sprite_obj` was not set and dynamically created MCs have
   `display_obj == NULL`, so `actionStop()` fell through to `is_playing = 0`
   on the root MC. Fixed by saving/restoring `is_playing` around child frame
   execution, and setting `g_current_sprite_obj` when `display_obj` is available.
   Commit: `16341d93`.

2. **AVM1 SetVariable stack convention (documented).**
   The runtime's `actionSetVariable()` expects value at SP (top) and name at
   SP_SECOND_TOP (second). The standard AVM1 bytecode convention is: push name
   first (bottom), push value second (top). The code comments are correct but
   easily misread. For hand-authored bytecode: push name first, then value.

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
- Child SWF calls `stop()` (safe after bug #1 fix)
- Parent uses `FSCommand:quit` to cleanly exit the frame loop

### Demo 2: Bytecode Injection (Skipped)

Not implemented. The results from Demos 1, 3, and 4 provide sufficient insight.
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

### Demo 4: Prelude SWF (LittleCube's Full Vision)

**Test location:** `demos/runtime-swf/prelude_swf/`

**Files:**
- `create_prelude_swf.py` — generates prelude SWF (sets up _global, prototypes, constructor)
- `create_test_swf.py` — generates main SWF (verifies prelude's setup is available)
- `test.toml` — `num_frames = 1`
- `output.txt` — expected output (11 lines)

**Implementation:**
- `MovieEntry.is_prelude` field marks prelude entries in the movie registry
- `getPreludeEntry(idx)` iterates prelude entries
- `swfStart()` runs prelude init + frame 0 after `tagInit`, before the main frame loop
- Prelude shares the same `_global`, `var_array`, and scope chain — no isolation
- `verify_output.py` detects prelude SWFs by `prelude_*.swf` naming convention
- SWF version auto-detected from binary header; prelude must match main SWF version

**What the prelude sets up:**
- `_global.runtimeVersion = "1.0"`
- `_global.runtimeReady = true`
- `MovieClip.prototype.greet` — method callable on any MC
- `_global.Greeter` — constructor with prototype.sayHi method

**What the main SWF verifies:**
- All `_global` properties readable
- `this.greet()` callable (inherited via MovieClip.prototype)
- `typeof Greeter` = "function"
- `new Greeter("World").sayHi()` traces "Hi, I'm World"

## Open Questions (Answered)

- **Prelude scope isolation:** Preludes share the main SWF's scope entirely (same
  `_global`, same `var_array`). No isolation needed — that's the point.
- **Version matching:** SWF version is auto-detected from the binary header. The
  prelude SWF must be authored with the same version byte as the main SWF to
  avoid version-group isolation (SWF≤6 vs SWF7+ have separate `_global` objects).
- **Multiple prelude SWFs:** Supported — `getPreludeEntry(idx)` iterates all
  prelude entries. They execute in the order they appear in the movie registry.

## Future Work

- **WASM deployment:** Deploy demos to `docs/injector/` as in-browser demos
  (similar to `docs/recompiler/`).
- **AS2 compiler integration:** Explore using MTASC or Flex SDK to compile
  AS2 source files directly into prelude SWFs, rather than hand-authoring
  bytecode with Python.
- **Real runtime API migration:** Identify a C-coded runtime builtin (e.g., a
  simple `MovieClip.prototype` method) and reimplement it as a prelude SWF to
  validate the full workflow end-to-end with a real game SWF.
