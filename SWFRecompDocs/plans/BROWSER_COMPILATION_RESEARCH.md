# In-Browser C-to-WASM Compilation Research

## Goal

Build a 3-phase in-browser demo:
1. **Phase 1**: SWFRecomp.wasm (Emscripten) converts SWF bytecode to C files — **WORKING**
2. **Phase 2**: Compile generated C files + runtime headers + precompiled `libswfruntime.a` → single WASI `.wasm` — **WORKING (Chrome only)**
3. **Phase 3**: Run output WASM with a WASI shim, capture trace output — **WORKING**

Phase 2 requires: multiple `.c` files, include headers, linking against a `.a` static library, targeting `wasm32-wasi`, all in the browser with no server.

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
    -DNO_GRAPHICS -DSWF_VERSION=15 \
    -include string.h -include strings.h \
    -I$RUNTIME/include -I$RUNTIME/include/actionmodern \
    -I$RUNTIME/include/libswf -I$RUNTIME/include/memory \
    -I$RUNTIME/lib/c-hashmap -I$RUNTIME/lib/o1heap \
    -O0 -w -c \
    $RUNTIME/src/actionmodern/action.c -o action.o
```

**Note**: `SWF_VERSION` is a per-SWF compile-time constant. Currently only version 15 is pre-compiled. To support other versions, pre-compile action.o/object.o for each needed version.

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

## Alternative Approaches (Not Needed — @wasmer/sdk Works)

These were researched as fallbacks before Chrome was tested:

### 1. YoWASP Clang (@yowasp/clang) — Best Alternative

Full LLVM/Clang/LLD toolchain compiled to WebAssembly, distributed as an npm package.

- **npm**: `@yowasp/clang`
- **Includes**: clang, wasm-ld, ar, ranlib, objcopy, nm, readobj, strip
- **WASI output**: Yes
- **Static library linking**: Yes (has wasm-ld)
- **Browser support**: Yes, via npm/CDN import
- **No @wasmer/sdk dependency**: Runs directly
- **Actively maintained**: Last release December 2025

### 2. Emception (jprendes/emception)

Full Emscripten toolchain compiled to WebAssembly. Very large. Requires Docker to build.

### 3. binji/wasm-clang

Clang + LLD compiled to WASM. "Alpha demoware" from 2019, likely unmaintained.

### 4. XCC (tyfkda/xcc)

Lightweight C compiler. No `.a` archive support — blocker.

---

## Infrastructure

- **`coi-serviceworker.js`**: Injects COOP/COEP headers for cross-origin isolation
- **`wasi_shim.js`**: Phase 3 WASI shim with auto-stubbing for threading imports
- **`pipeline.js`**: Full 3-phase pipeline (SWF→C→WASM→output)
- **`clang_registry_response.json`**: Wasmer registry bypass (avoids Firefox CORS issue)
- **`libswfruntime.a`**: Precompiled runtime library (wasm32-wasi target)
- **`runtime_src/action.o`**: Pre-compiled action.c for SWF version 15
- **`runtime_src/object.o`**: Pre-compiled object.c for SWF version 15
- **`runtime_src/main.c`**: WASI wrapper (calls `swfStart()` directly)
- **`runtime_headers/`**: Header files with manifest.json

---

## Testing Notes

- **Chrome**: Full pipeline works end-to-end. Tested with Ruffle "add" test (SWF v15)
- **Firefox**: Broken at Phase 2 — SDK panics on all versions when compiling clang WASM atom
- Cross-origin isolation (`crossOriginIsolated: true`) confirmed working in both browsers
- Service worker needs one page reload to activate in Chrome
- Wasmer SDK produces background console panics (module.rs:384, instance.rs:62) after Phase 2 completes — these are harmless cleanup crashes and don't affect Phase 3
- Output WASM is ~335 KB for the "add" test
