# In-Browser C-to-WASM Compilation Research

## Goal

Build a 3-phase in-browser demo:
1. **Phase 1**: SWFRecomp.wasm (Emscripten) converts SWF bytecode to C files — **WORKING**
2. **Phase 2**: Compile generated C files + runtime headers + precompiled `.o`/`.a` → executable WASM — **WORKING (Chrome only)**
3. **Phase 3**: Run output — **WORKING (Trace mode: WASI shim captures output. Graphics mode: WebGPU rendering with keyboard input)**

Both trace mode (NO_GRAPHICS) and graphics mode (WebGPU) are working. Phase 2 uses `@wasmer/sdk@0.8.0-beta.1` (Wasmer clang) for both modes.

---

## Working Solution

### Overview

The pipeline works end-to-end in **Chrome** using `@wasmer/sdk@0.8.0-beta.1`:

1. SWFRecomp.wasm (Emscripten) recompiles SWF → C files
2. `clang/clang` WEBC package (via `clang.entrypoint.run()`) compiles C → WASM
3. Custom WASI shim instantiates and runs the output WASM, capturing stdout

### Key Constraints Discovered

1. **Chrome only** — Firefox panics on all SDK versions (module.rs:74 unwrap-on-None)
2. **Single invocation** — SDK crashes on 2nd `command.run()` call (module.rs:294 panic). All compilation + linking must happen in one clang invocation
3. **Large files OOM** — action.c (~10K lines) and object.c (~3K lines) cause cc1 to exit with code 45 (likely OOM in WASM linear memory). Must be pre-compiled offline
4. **Preset threading flags** — The slim driver's entrypoint includes `-matomics -mbulk-memory -mmutable-globals -pthread -ftls-model=local-exec -Wl,--shared-memory,--max-memory=4294967296,--import-memory`. Output WASM imports shared memory from `env` and threading functions from `wasix_32v1`
5. **WASI shim must handle threading imports** — Output WASM expects `env.memory` (SharedArrayBuffer), `wasix_32v1.*` (5 threading functions), and `wasi_snapshot_preview1.sched_yield`. All auto-stubbed by the shim

### Pre-compiled Runtime Objects

`action.c` and `object.c` are pre-compiled offline with wasi-sdk 30. Flags must match the wasmer clang preset:

```bash
WASI_SDK=/tmp/wasi-sdk-30.0-x86_64-linux
RUNTIME=../SWFModernRuntime

$WASI_SDK/bin/clang \
    --target=wasm32-wasi \
    --sysroot=$WASI_SDK/share/wasi-sysroot \
    -matomics -mbulk-memory -mmutable-globals \
    -pthread -ftls-model=local-exec \
    -fno-trapping-math \
    -mllvm -wasm-enable-sjlj \
    -DNO_GRAPHICS \
    -include string.h -include strings.h \
    -I$RUNTIME/include -I$RUNTIME/include/actionmodern \
    -I$RUNTIME/include/libswf -I$RUNTIME/include/memory \
    -I$RUNTIME/lib/c-hashmap -I$RUNTIME/lib/o1heap \
    -O0 -w -c \
    $RUNTIME/src/actionmodern/action.c -o action.o
```

**Note**: `SWF_VERSION` is now a runtime variable (`g_swf_version`), set from `constants.h` in `main()`. A single pre-compiled action.o/object.o works for all SWF versions.

### Compilation Command (In-Browser)

The slim driver compiles 6 small generated files + links with pre-compiled objects:

```javascript
const compileResult = await runCmd(clangCmd, [
    ...cFiles.map(f => `/project/${f}`),  // main.c + 5 generated files
    "-DNO_GRAPHICS",
    "-include", "string.h",
    "-include", "strings.h",
    "-I/project", "-I/project/include",
    "-I/project/include/actionmodern",
    "-I/project/include/libswf",
    "-I/project/include/memory",
    "-O0", "-w",
    "/project/action.o",       // pre-compiled
    "/project/object.o",       // pre-compiled
    "/project/libswfruntime.a", // pre-compiled static lib
    "-o", "/project/output.wasm",
], { mount: { "/project": project } });
```

### WASI Shim Design

The output WASM uses WASIX threading extensions. The shim handles this by:

1. Inspecting `WebAssembly.Module.imports(compiled)` to discover all needed imports
2. Wrapping `wasi_snapshot_preview1` in a `Proxy` that auto-stubs missing functions (like `sched_yield`)
3. Generating stubs for `env` module (shared memory) and `wasix_32v1` (threading functions)
4. Using imported shared memory (`env.memory`) as fallback when module doesn't export memory

---

## @wasmer/sdk Investigation

### Architecture

The `@wasmer/sdk` provides browser APIs (`Wasmer.fromRegistry()`, `runWasix()`, etc.) to download and run WASI/WASIX programs. It:

1. Downloads WEBC packages from `cdn.wasmer.io` (the clang package is ~100 MB)
2. Extracts WASM "atoms" (the actual binaries) from the WEBC container
3. Compiles atoms via `WebAssembly.Module()`
4. Runs them inside Web Workers using `SharedArrayBuffer` for communication
5. Requires cross-origin isolation (`Cross-Origin-Opener-Policy` + `Cross-Origin-Embedder-Policy` headers)

We use `coi-serviceworker.js` to inject these headers client-side (for GitHub Pages deployment without server config).

### Registry Bypass

Firefox includes `User-Agent` in CORS preflight headers. `registry.wasmer.io` doesn't allow it, so the GraphQL query to resolve `clang/clang` fails in Firefox.

**Fix**: Intercept `fetch()` and `XMLHttpRequest` for `registry.wasmer.io` URLs, return a pre-cached response from `clang_registry_response.json` (captured from a working curl request). This works across all SDK versions.

### Two Code Paths in the SDK

The SDK has two fundamentally different paths for running WASM:

1. **`runWasix(module, opts)`** — Takes a `WebAssembly.Module` or `Uint8Array`, goes through `WasmModule::to_module()` → internal compilation → `SpawnWasm` → Web Worker. This path is broken on ALL versions.

2. **`package.entrypoint.run(opts)` / `package.commands[name].run(opts)`** — Runs a command from a WEBC package. Goes through the WEBC runner which loads atoms from package data. This is the path used by Wasmer's official `clang-cdn` example. **Works in Chrome with v0.8.0-beta.1.**

### Two Atoms in clang Package

- **`clang-16-slim`** (entrypoint) — Driver only, invokes cc1 as subprocess. Works for multi-file compilation
- **`clang-16`** — Full binary, crashes when run standalone (exit 45, no output). Only works as cc1 subprocess

### Version-by-Version Results

#### @wasmer/sdk v0.10.0

| Test | Result |
|------|--------|
| `runWasix(compiled_module)` | Panic: `module.serialize().unwrap()` at `task_wasm.rs:38` — "Not able to serialize module" |
| `runWasix(uint8array)` | `CompileError: Validate("Unknown validation error")` |
| `Wasmer.fromWasm(bytes)` + `.run()` | `ok=false, code=1` (silent failure) |
| `clang.entrypoint.run()` | `ok=false, code=1` (silent failure) + "deprecated parameters" warnings |

#### @wasmer/sdk v0.9.0

| Test | Browser | Result |
|------|---------|--------|
| `clang.entrypoint.run()` | Firefox | Panic at `module.rs:74:77` — `Option::unwrap()` on `None` |
| `clang.entrypoint.run()` | Chrome | Not tested (v0.8.0 used instead) |

#### @wasmer/sdk v0.8.0-beta.1 (version used in official clang-cdn example)

| Test | Browser | Result |
|------|---------|--------|
| `clang.entrypoint.run()` | Firefox | Same panic at `module.rs:74:77` |
| `clang.entrypoint.run()` | Chrome | **WORKS** — compiles and links successfully |
| 2nd `command.run()` call | Chrome | Panic at `module.rs:294` — can only invoke once |

### Root Cause Analysis

#### Firefox — Module.rs Panic (all versions)

**File**: `wasmer/lib/api/src/js/module.rs:74:77`

`WebAssembly::Module::new()` fails on the clang WASM atom inside a Web Worker, and the error handler tries to stringify the JS error with `.as_string().or_else(|| JSON::stringify()).unwrap()`. Both return `None`, causing the unwrap to panic.

Our main-thread `WebAssembly.Module` monkey-patch never fired, confirming the compilation happens in a Web Worker with clean globals.

#### Chrome — Works Because...

Chrome's `WebAssembly.Module()` (sync) succeeds on the clang atom where Firefox's fails. The atom likely uses WASM features that Chrome supports but Firefox doesn't (or has different sync compilation limits).

#### `runWasix()` — Serialization Panic (v0.10.0)

**File**: `wasmer-js/src/tasks/task_wasm.rs:38`

The SDK needs to serialize modules for Web Worker transfer. The `js-serializable-module` cargo feature is NOT enabled, so serialization fails when raw bytes aren't stored.

#### Large File OOM (exit code 45)

action.c (~10K lines) causes cc1 to crash with exit 45 when compiled in-WASI. Likely OOM in WASM linear memory. Solution: pre-compile offline.

---

## Graphics Mode — Dual-Module Architecture (March 2026)

### The Problem

The graphics runtime uses Emscripten-specific APIs (WebGPU via `--use-port=emdawnwebgpu`, ASYNCIFY for frame timing via `emscripten_sleep()`, event callbacks via `emscripten_set_keydown_callback()`, inline JS via `EM_ASM`). The in-browser Wasmer clang produces `wasm32-wasi` output, not Emscripten output. A single WASM module can't have both Emscripten and WASI features.

### Solution: Pre-built Host + In-browser Guest

Two WASM modules sharing memory:

- **Host module** (`graphics_host.js` + `.wasm`, 127KB + 941KB): Pre-built with Emscripten. Contains all runtime code (action.c, object.c, swf.c, tag.c, render_webgpu.c, audio.c). Exports 432 runtime functions. Built with `-s SHARED_MEMORY=1 -s ALLOW_MEMORY_GROWTH=1 -s ALLOW_TABLE_GROWTH=1 -sASYNCIFY`.

- **Guest module** (~97KB): Compiled in-browser with Wasmer clang. Contains only per-SWF generated code (tagMain.c, script_*.c, draws.c, constants.c). Linked with `-Wl,--allow-undefined` so runtime function calls become WASM imports. Uses `--global-base=1.5GB` to avoid data segment overlap with host's 1GB heap.

### Technical Challenges Solved

1. **Shared memory**: Host built with `-s SHARED_MEMORY=1` so both modules use `SharedArrayBuffer`. Guest compiled with the clang preset's `--shared-memory`. Host memory pre-grown to 1.6GB before guest instantiation.

2. **Import resolution**: Guest's 136 imports mapped to host exports via JS. The `Module.wasmExports` or `Module["_" + name]` lookup finds Emscripten-exported functions. WASI/WASIX imports stubbed via Proxy.

3. **Global variable bridging**: 5 globals shared between host and guest (`catch_up_mode`, `g_tag_skip_mode`, `quit_swf`, `g_override_this`, `g_override_this_set`). Solved via `bridge_globals.h` — pointer indirection macros defined under `#ifdef DYNAMIC_GUEST`. The guest accesses host globals through pointers initialized by `bridge_init()` before any frame functions execute. Generated code post-processed to remove conflicting `extern` declarations.

4. **Function pointer translation**: Guest's `actionDefineFunction2` import wrapped in JS to translate guest table indices → host table indices via `Module.addFunction()`. The guest's `__indirect_function_table` is queried to find the function object at the guest index, then registered in the host's table.

5. **Sprite frame_funcs patching**: After guest instantiation, sprite frame function arrays in shared memory are read via `WebAssembly.Global` exports and overwritten with host table indices before `tagInit` executes.

6. **Data segment placement**: `--global-base=1610612736` (1.5GB) places guest data past the host's 1GB heap. Memory pre-grown to 1.6GB before guest instantiation so data segments can be initialized.

7. **Declaration-after-label**: Generated C code has goto labels followed by declarations, which is invalid in C17. Post-processed to insert null statements (`;`) after labels.

8. **Export preservation**: Emscripten's dead code elimination removes unreachable functions. A `force_exports.c` with `__attribute__((used))` volatile pointer array didn't work with `-s EXPORT_ALL=1`. Solution: auto-generate `EXPORTED_FUNCTIONS` list from `llvm-nm` on the compiled `.o` files.

### Files

- `SWFRecomp/wasm_wrappers/host_main_graphics.c` — host entry point with config API and global accessors
- `SWFRecomp/wasm_wrappers/guest_main_graphics.c` — guest entry point with data accessor exports
- `SWFRecomp/wasm_wrappers/bridge_globals.c` / `.h` — pointer indirection for shared globals
- `SWFRecomp/scripts/build_graphics_host.sh` — Emscripten host build with auto-generated export list
- `docs/recompiler/pipeline_graphics.js` — graphics compilation + JS bridge pipeline (~460 lines)
- `docs/recompiler/graphics_host.js` + `.wasm` — pre-built host module

### Result

The keyboard_input demo works: green square moves with arrow keys, blue square animates automatically. WebGPU rendering, keyboard events, and frame animation all function correctly.

---

## Alternative Approaches

### 1. YoWASP Clang (@yowasp/clang) — Tested, Strong Alternative

Full LLVM/Clang/LLD toolchain compiled to WebAssembly, distributed as a public npm package. **Tested in March 2026** — works well and eliminates most Wasmer SDK pain points.

**Package**: `@yowasp/clang` v22.0.0 (LLVM 22), 101MB installed. Contains `llvm.core.wasm` (73MB), `llvm-resources.tar` (29MB, includes wasm32-wasip1 sysroot + libc). Repository archived March 11, 2026 but npm package is functional.

**API**: Simple file-in/file-out model:
```javascript
import { runClang, runLLVM } from '@yowasp/clang';
const filesOut = await runClang(
    ['clang', '--target=wasm32-wasip1', '-O2', '-o', 'out.wasm', 'main.c', 'helper.o'],
    { 'main.c': sourceCode, 'helper.o': precompiledBytes }
);
const wasm = filesOut['out.wasm'];  // Uint8Array
```

**Test results (Node.js, March 2026):**

| Test | Result | Time |
|------|--------|------|
| Simple freestanding C → WASM | Works | 697ms |
| Multi-file WASI compilation (printf, string.h) | Works | 867ms |
| Separate compile (-c) then link | Works | 191ms (link only) |
| Link with pre-compiled .o file | Works | 191ms |
| Multiple invocations | Works (no crash) | — |

**Comparison to Wasmer SDK clang:**

| Feature | Wasmer SDK clang | YoWASP clang |
|---|---|---|
| Threading imports | Forced (`--shared-memory`, `wasix_32v1`, `env.memory`) | **None** — clean WASI output |
| Memory model | Imported shared (`env.memory` SharedArrayBuffer) | **Exported non-shared** (standard) |
| WASI imports in output | 40+ (wasi_snapshot_preview1 + wasix_32v1) | **5** (minimal wasi_snapshot_preview1) |
| Separate compile + link | Broken (slim driver can't do single-file `-c`) | **Works** |
| Firefox support | Broken (SDK panics on all versions) | **Likely works** (no SDK dependency, uses standard WASM) |
| SharedArrayBuffer required | Yes (COOP/COEP headers needed) | **No** |
| Multiple compilations | Crashes on 2nd call | **Works** |
| API complexity | Complex (Wasmer.fromRegistry, mount dirs, Proxy stubs) | **Simple** (files in → files out) |
| Package size | ~100MB (downloaded on demand from CDN) | 101MB (npm install, cached locally) |
| Sysroot | In `.webc` package (with forced threading flags) | In `llvm-resources.tar` (clean, no threading) |

**Key advantages for our use case:**

1. **No threading imports**: Output WASM only imports 5 basic `wasi_snapshot_preview1` functions. No `env.memory`, no `wasix_32v1`. The WASI shim would be trivial.

2. **Separate compile and link**: Can compile with `runClang(['clang', '-c', ...])` then link with another `runClang` call. This enables using `--allow-undefined` for graphics guest modules and `wasm-ld` for custom linking.

3. **Firefox support**: No Wasmer SDK dependency means no `module.rs` panics. Standard WASM compilation should work in Firefox.

4. **Multiple invocations**: No crash on 2nd call — can compile multiple files in sequence.

5. **No COOP/COEP requirement**: No SharedArrayBuffer needed, so no cross-origin isolation headers.

**Limitations:**

1. **No preset sysroot for `--target=wasm32-wasi`** — must use `--target=wasm32-wasip1` (the newer naming). May need flag adjustments for pre-compiled .o files.

2. **`runLLVM(['wasm-ld', ...])` doesn't auto-find sysroot paths** — need to use `runClang` for linking or specify full paths. The sysroot is at `/lib/wasm32-wasip1/` in the virtual FS.

3. **Repository archived** (March 11, 2026) — no future updates, but v22.0.0 is very recent (LLVM 22).

4. **Same WASI-vs-Emscripten gap for graphics mode** — still produces wasm32-wasi output, so the dual-module architecture would still be needed for WebGPU rendering. But the cleaner output (no threading imports) would simplify the graphics bridge significantly.

**Verdict**: YoWASP is the **best drop-in replacement for trace mode** — cleaner output, simpler API, likely Firefox support, no COOP/COEP needed. For graphics mode, it wouldn't eliminate the dual-module architecture but would make the guest module much simpler (no shared memory mismatch, no wasix_32v1 stubs). **Recommended as the next migration step** if Wasmer SDK issues become blocking.

### 2. Emception (jprendes/emception) — Detailed Analysis

Full Emscripten toolchain compiled to WebAssembly. Produces **native Emscripten output** (JS glue + WASM), not wasm32-wasi. This is the key difference from all other approaches.

**Components**: LLVM/Clang (bundled as `llvm-box.wasm`), Binaryen (`binaryen-box.wasm`), CPython (`python.wasm`), QuickNode (`quicknode.wasm`), Brotli decompressor, wasm-package tool. All compiled to WASM via Emscripten 3.1.24.

**API**: ES6 modules with async initialization. `new Emception()` → `emception.init()` → `emception.fileSystem.writeFile()` → `emception.run("emcc -O2 main.c -o output.js")` → `emception.fileSystem.readFile("output.js")`.

**Key advantages over Wasmer clang for graphics mode:**

| Problem with Wasmer approach | Emception would avoid it |
|---|---|
| Dual-module architecture (host + guest) | Single Emscripten module |
| Shared memory mismatch (WASI shared vs Emscripten non-shared) | Not an issue |
| Function pointer translation (guest→host table) | Not an issue — one table |
| Bridge globals via pointer indirection | Not an issue — one module |
| Data segment overlap (--global-base=1.5GB) | Linker handles layout |
| ~460 lines of JS bridge code | ~50 lines of pipeline code |
| Post-processing extern declarations | Not needed |
| 432-function export list generation | Not needed |

**Key disadvantages:**

1. **Much larger download**: Full LLVM + Binaryen + Python + Emscripten sysroot. Likely 50-100MB+ even with Brotli compression (vs ~100MB for just clang in Wasmer).

2. **Slower compilation**: Full Emscripten pipeline (clang → binaryen wasm-opt → wasm-emscripten-finalize → JS glue generation) vs just clang→wasm-ld.

3. **Old Emscripten version**: 3.1.24 (2022). Our WebGPU support (`--use-port=emdawnwebgpu`) requires newer Emscripten (we use 5.0.0). Would need a custom build.

4. **Build from source required**: No pre-built distribution available. Requires Docker, 30-60 min build time, 15GB+ swap. The GitHub Pages demo bundles everything into webpack (not reusable as a library).

5. **npm package on GitHub Packages only**: `@jprendes/emception` requires GitHub authentication, not on public npm registry.

6. **Pre-compiled .o still needed**: action.c (50K lines) would still be too large for in-browser compilation. Would need pre-compiled .o files matching the Emception Emscripten version exactly.

7. **No SharedArrayBuffer required** (advantage): Uses standard Web Workers + Comlink, no COOP/COEP headers needed.

**Verdict**: Emception would have been the better architectural choice for graphics mode, eliminating the dual-module complexity. But the practical barriers (custom build, old Emscripten, large download) are significant. For trace mode, the current Wasmer approach is simpler and lighter. The **ideal future approach** would be a custom Emception build matching our Emscripten version, with pre-compiled runtime .o files, compiling only per-SWF generated code in-browser.

### 3. binji/wasm-clang

Clang + LLD compiled to WASM. "Alpha demoware" from 2019, likely unmaintained.

### 4. XCC (tyfkda/xcc)

Lightweight C compiler. No `.a` archive support — blocker.

---

## Infrastructure

### Trace Mode (docs/recompiler/)

- **`coi-serviceworker.js`**: Injects COOP/COEP headers for cross-origin isolation
- **`wasi_shim.js`**: Phase 3 WASI shim with proper WASI error codes, SharedArrayBuffer support, TLS init, wasix_32v1 proxy
- **`pipeline.js`**: Full 3-phase pipeline (SWF→C→WASM→output) with mode selector (trace/graphics)
- **`clang_registry_response.json`**: Wasmer registry bypass (avoids Firefox CORS issue)
- **`libswfruntime.a`**: Precompiled runtime library (wasm32-wasi target, includes tag.c + hit_test.c)
- **`runtime_src/action.o`**: Pre-compiled action.c (~11MB, with -matomics -mbulk-memory)
- **`runtime_src/object.o`**: Pre-compiled object.c (~13KB)
- **`runtime_src/main.c`**: WASI wrapper (calls `swfStart()` directly)
- **`runtime_headers/`**: Header files with manifest.json (includes hit_test.h)

### Graphics Mode (docs/recompiler/)

- **`pipeline_graphics.js`**: Graphics compilation pipeline + JS bridge (~460 lines)
- **`graphics_host.js`** + **`graphics_host.wasm`** (127KB + 941KB): Pre-built Emscripten host with WebGPU, ASYNCIFY, shared memory, 432 exported functions
- **`runtime_src_graphics/bridge_globals.o`**: Pre-compiled global pointer bridge
- **`runtime_src_graphics/bridge_globals.h`**: Bridge macros (pointer indirection for shared globals)
- **`runtime_src_graphics/guest_main_graphics.c`**: Guest entry point with data accessor exports
- **`keyboard_input.swf`**: Example SWF for graphics mode demo

### Build Scripts (SWFRecomp/scripts/)

- **`build_wasm_recompiler.sh`**: Builds SWFRecomp.wasm (Phase 1 recompiler) via Emscripten
- **`build_wasm_runtime_lib.sh`**: Builds libswfruntime.a + .o files via WASI-SDK
- **`build_graphics_host.sh`**: Builds graphics_host.js/.wasm via Emscripten with auto-generated export list from llvm-nm
- **`deploy_wasm_demo.sh`**: Deploys all artifacts to docs/recompiler/

---

## Testing Notes

- **Chrome**: Full pipeline works end-to-end for both trace and graphics modes
  - Trace mode tested with "add" test (SWF v15) — correct arithmetic output
  - Graphics mode tested with "keyboard_input" (SWF v6) — WebGPU rendering, keyboard input, frame animation all working
- **Firefox**: Broken at Phase 2 — SDK panics on all versions when compiling clang WASM atom
- Cross-origin isolation (`crossOriginIsolated: true`) confirmed working in both browsers
- Service worker needs one page reload to activate in Chrome
- Wasmer SDK produces background console panics (module.rs:384, instance.rs:62) after Phase 2 completes — these are harmless cleanup crashes and don't affect Phase 3
- Trace mode output WASM is ~678 KB; graphics guest WASM is ~97 KB
- Graphics mode requires ~1.6GB of browser memory (host heap + guest data segment space)
