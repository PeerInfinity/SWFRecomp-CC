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

## Demos

### Demo 1: loadMovie Inspection (ActionScript)

**Approach:** A parent SWF uses `loadMovie()` to load a child SWF into a MovieClip,
then uses `for..in` loops and property access to enumerate everything visible on
the child MC, and outputs the results via `trace()`.

**What it tests:**
- Timeline variables and functions on the child MC
- `_global` contributions made by the child SWF's init code
- Child MC properties (`_x`, `_y`, `_width`, `_height`, `_totalframes`, etc.)
- Prototype chain of the child MC
- Whether the parent can call functions defined in the child

**Implementation:**
- Author two SWFs with swfmill (XML → bytecode assembly)
- Child SWF: defines some variables, functions, and `_global` properties
- Parent SWF: loads child via `loadMovie`, waits a frame, enumerates with `for..in`
- Uses existing multi-SWF infrastructure (`find_child_swfs`, `generate_movie_registry`,
  `MovieEntry`, `-DHAS_CHILD_MOVIES`)
- Start as a local-only test, then deploy as WASM demo

**Feasibility:** Ready now — all infrastructure exists and is tested (e.g., `loadmovie`,
`mcl_loadclip` tests already pass).

### Demo 2: Bytecode Injection (Lowest Priority / May Skip)

**Approach:** Modify the recompiler to inject additional AVM1 bytecode into the SWF
before the normal bytecode→C translation. The injected bytecode would perform the
same enumeration as Demo 1 but from "inside" the SWF.

**What it tests:**
- Whether injected bytecode can see everything that native bytecode can see
- Same scope visibility as the original SWF code

**Implementation:**
- Would require a new recompiler feature to prepend/append bytecode to frame scripts
- The injected bytecode goes through the normal `action.cpp` translation pipeline
- Complex: need to handle constant pool merging, register allocation conflicts

**Feasibility:** Significant new recompiler feature. Deferred or skipped unless
Demos 1 and 3 leave unanswered questions.

### Demo 3: C Code Injection (test_harness)

**Approach:** A `test_harness.c` file uses runtime C APIs to walk internal data
structures and trace everything it finds — display list entries, `_global` properties,
dictionary characters, variable maps, function registries.

**What it tests:**
- Full visibility into runtime internals (things AS2 code cannot directly see)
- Dictionary entries (shapes, sprites, fonts, etc.)
- Internal function registry
- Display list structure
- Variable storage internals

**Implementation:**
- Uses existing `test_harness.c` mechanism (`-DHAS_TEST_HARNESS`, `test_harness_init`)
- C code calls runtime APIs: `getVariable`, `getProperty`, iterates `display_list`,
  walks `dictionary`, enumerates `_global` object properties
- Can hook `g_after_tick_handler` to run after each frame (like `external_interface` does)

**Feasibility:** Ready now — mechanism exists and is proven by `external_interface` test.

### Demo 4: Prelude SWF (LittleCube's Full Vision)

**Approach:** A "runtime" SWF is recompiled to C and statically linked with the game
SWF. The runtime SWF's init code runs *before* the game SWF's init, in the same
scope. The game SWF sees the runtime's `_global` definitions as if they were native
builtins.

**What it tests:**
- Whether a prelude SWF can set up `_global` prototypes that the game SWF uses
- Execution ordering (runtime init → game init → runtime frame 1 → game frame 1?)
- Scope isolation or sharing between the two SWFs
- Whether this could replace C-coded builtins with AS2-coded ones

**How it differs from Demo 1:**
- Build-time static linking, not runtime `loadMovie`
- Runtime SWF runs at top level, not inside a child MovieClip
- Runtime SWF's init code runs before game's frame 1
- No deferred loading — definitions available immediately

**Implementation:**
- Needs a new execution mode: "prelude" MovieEntry whose `tagInit` + frame 1 runs
  during `swfStart()` before the main SWF's `tagInit`
- Could reuse `MovieEntry` infrastructure but with a different trigger (startup vs
  `loadMovie`)
- The runtime SWF's `_global` modifications persist because `_global` is shared

**Feasibility:** Requires new runtime code in `swf_core.c` to run prelude SWFs at
startup. The MovieEntry/movie_registry infrastructure is close — mainly needs a new
execution path.

## Execution Order

1. **Demo 1** (loadMovie) — start here, local test first, then WASM
2. **Demo 3** (test_harness C injection) — parallel or immediately after
3. **Demo 4** (prelude SWF) — after 1 and 3 inform the design
4. **Demo 2** (bytecode injection) — only if needed

## Child SWF Design

The child/target SWF should contain a variety of things to enumerate:

- Timeline variables (strings, numbers, booleans, objects)
- Timeline functions (both `DefineFunction` and `DefineFunction2`)
- `_global` property assignments
- Prototype modifications (e.g., `MovieClip.prototype.customMethod`)
- Multiple frames with different content
- At least one sprite definition in the dictionary
- Named instances on the display list

All SWFs will be authored with swfmill (XML → bytecode assembly), consistent with
the rest of the project.

## Deployment

- Local-only tests first (run with `verify_output.py` or standalone native binary)
- WASM demos later, deployed to `docs/injector/` with subdirectories per demo
- Similar structure to `docs/recompiler/` (self-contained HTML + WASM)

## Open Questions

- Should Demo 4's prelude SWF run its *all* frames before the game starts, or just
  frame 1? (Probably just init + frame 1, since runtime setup should be one-shot.)
- For Demo 4, should the runtime SWF's functions be scoped to a namespace
  (e.g., `_global.__runtime`) or injected directly into `_global`?
- How should version conflicts be handled if the runtime SWF is SWF8 but the game
  is SWF6? (Probably: runtime SWF matches game's version.)
- Can swfmill handle everything we need for the child SWF, or will we need MTASC
  for more complex AS2 constructs? (swfmill handles raw bytecode, so it should be
  sufficient for hand-crafted test cases.)
