# Phase 2: Compile Generated C to WASM In-Browser

**Date:** 2026-02-15
**Status:** Plan
**Parent:** IN_BROWSER_RECOMPILATION_FEASIBILITY.md
**Depends on:** Phase 1 (PHASE1_RECOMPILER_TO_WASM.md — complete)

## Goal

After Phase 1's SWFRecomp.wasm generates C source files from a dropped SWF, Phase 2 compiles those C files (plus the SWFModernRuntime) into a runnable WASM module — entirely in the browser, no server.

## Approach: @wasmer/sdk + Clang

Use the Wasmer JS SDK (`@wasmer/sdk`, version 0.9.0) to run the full LLVM Clang toolchain as WASM inside the browser. Clang compiles the generated C code, links it against a pre-compiled runtime static library, and produces a wasm32-wasi binary. JavaScript then instantiates that binary and captures its output.

---

## Architecture Overview

```
                        Browser
┌──────────────────────────────────────────────────────────────┐
│                                                              │
│  User drops .swf file                                        │
│       │                                                      │
│       ▼                                                      │
│  [SWFRecomp.wasm]  (621 KB, cached)                          │
│  Reads SWF from MEMFS, writes .c/.h files to MEMFS           │
│       │                                                      │
│       ▼                                                      │
│  [Clang.wasm via @wasmer/sdk]  (~100 MB, cached in IDB)      │
│  Compiles generated .c → .o (wasm32-wasi)                    │
│  Links .o + libswfruntime.a → output.wasm                    │
│       │                                                      │
│       ▼                                                      │
│  [WebAssembly.instantiate(output.wasm)]                       │
│  With WASI imports (stdout → trace capture)                   │
│  Runs the SWF, collects trace output                         │
│                                                              │
└──────────────────────────────────────────────────────────────┘
```

## Key Design Decision: Pre-compiled Runtime

The generated C code calls ~120 runtime functions across 10 source files (~20K lines). Recompiling the entire runtime from source every time a user drops a SWF would be slow.

**Solution:** Pre-compile the runtime into a static library (`libswfruntime.a`) targeting wasm32-wasi at build time. Ship it alongside the web app. Only the generated C files (small, test-specific) need to be compiled in-browser.

### What gets compiled in-browser (per SWF):
- `tagMain.c` — frame functions, tag setup (~50-200 lines)
- `script_N.c` — action scripts (~50-500 lines each, typically 1-5 files)
- `script_defs.c` — string constants (~20-100 lines)
- `constants.c`, `draws.c` — data tables (~50-300 lines)
- `main.c` — entry point wrapper (~30 lines, same for all tests)

**Typical total: 300-1500 lines of C.** This should compile in seconds even with Clang-as-WASM.

### What's pre-compiled into libswfruntime.a:
| File | Lines | Purpose |
|------|-------|---------|
| `action.c` | ~15,000 | Core AVM1 runtime |
| `variables.c` | ~2,000 | Variable storage |
| `object.c` | ~2,500 | ASObject/ASFunction/ASArray |
| `utils.c` | ~200 | Utility functions |
| `swf_core.c` | ~300 | SWF lifecycle (NO_GRAPHICS) |
| `tag_stubs.c` | ~100 | Tag stubs (NO_GRAPHICS) |
| `heap.c` | ~200 | Memory management |
| `map.c` | ~800 | Hashmap library |
| `o1heap.c` | ~500 | O(1) heap allocator |

**Total: ~21,600 lines**, compiled once at build time.

---

## Step 1: Pre-compile Runtime Static Library

### 1.1 Target ABI: wasm32-wasi

The Wasmer SDK's `clang/clang` package targets wasm32-wasi by default. For the pre-compiled `.a` to link correctly with in-browser-compiled `.o` files, it must use the same target triple and ABI.

**Option A: Use WASI-SDK (cleanest)**

Install [WASI-SDK](https://github.com/WebAssembly/wasi-sdk) and compile:

```bash
WASI_SDK=/path/to/wasi-sdk
CC="${WASI_SDK}/bin/clang --sysroot=${WASI_SDK}/share/wasi-sysroot"

for f in action.c variables.c object.c utils.c swf_core.c tag_stubs.c heap.c map.c o1heap.c; do
    $CC -c $f -DNO_GRAPHICS -I... -O2 -o "${f%.c}.o"
done

${WASI_SDK}/bin/llvm-ar rcs libswfruntime.a *.o
```

**Option B: Use Wasmer CLI to run the same Clang**

```bash
wasmer run clang/clang -- -c action.c --target=wasm32-wasi -DNO_GRAPHICS -I... -O2 -o action.o
# ... repeat for each file, then ar
```

This guarantees ABI compatibility since it's the exact same compiler the browser will use.

### 1.2 Build Script

Create `SWFRecomp/scripts/build_wasm_runtime_lib.sh`:

```bash
#!/bin/bash
# Build libswfruntime.a (wasm32-wasi) for in-browser linking
# Requires: WASI-SDK or wasmer CLI
```

This script:
1. Compiles each runtime .c file to .o targeting wasm32-wasi
2. Archives into libswfruntime.a
3. Outputs to `SWFRecomp/build_wasm/libswfruntime.a`

### 1.3 Header Packaging

The in-browser Clang needs access to runtime headers. These are written to Wasmer's virtual filesystem before compilation.

**13 header files needed** (total ~3,000 lines, ~80 KB uncompressed):

| Path in virtual FS | Source |
|--------------------|--------|
| `/include/common.h` | `SWFModernRuntime/include/common.h` |
| `/include/utils.h` | `SWFModernRuntime/include/utils.h` |
| `/include/actionmodern/action.h` | `SWFModernRuntime/include/actionmodern/action.h` |
| `/include/actionmodern/object.h` | `SWFModernRuntime/include/actionmodern/object.h` |
| `/include/actionmodern/stackvalue.h` | `SWFModernRuntime/include/actionmodern/stackvalue.h` |
| `/include/actionmodern/variables.h` | `SWFModernRuntime/include/actionmodern/variables.h` |
| `/include/libswf/recomp.h` | `SWFModernRuntime/include/libswf/recomp.h` |
| `/include/libswf/swf.h` | `SWFModernRuntime/include/libswf/swf.h` |
| `/include/libswf/tag.h` | `SWFModernRuntime/include/libswf/tag.h` |
| `/include/memory/heap.h` | `SWFModernRuntime/include/memory/heap.h` |
| `/project/map.h` | `SWFModernRuntime/lib/c-hashmap/map.h` |
| `/project/o1heap.h` | `SWFModernRuntime/lib/o1heap/o1heap.h` |
| `/project/unicode_case_tables.h` | `SWFModernRuntime/src/actionmodern/unicode_case_tables.h` |

**Packaging strategy:** Bundle all headers + the .a into a single file that the browser downloads once and caches:
- Option: A `.tar` or `.zip` fetched on first use, stored in IndexedDB
- Option: Embed as base64 in a JS module (headers are small enough)
- Option: Individual fetch calls (simplest, but more HTTP requests)

---

## Step 2: Integrate @wasmer/sdk

### 2.1 SDK Setup

```javascript
import { init, Wasmer, Directory } from "@wasmer/sdk";
await init();

// Load Clang (one-time, ~100 MB, cached by Wasmer SDK internally)
const clang = await Wasmer.fromRegistry("clang/clang");
```

### 2.2 Required HTTP Headers

The Wasmer SDK uses `SharedArrayBuffer` (for its internal threadpool), which requires Cross-Origin Isolation:

```
Cross-Origin-Opener-Policy: same-origin
Cross-Origin-Embedder-Policy: require-corp
```

**For GitHub Pages** (where the project demos are hosted): These headers cannot be set directly. Workaround: use [coi-serviceworker](https://github.com/niccokunzmann/coi-serviceworker) which patches them via a service worker.

### 2.3 Compilation Pipeline

```javascript
async function compileGeneratedCode(generatedFiles, runtimeLib, headers) {
    const project = new Directory();

    // Write pre-compiled runtime library
    await project.writeFile("/project/libswfruntime.a", runtimeLib);

    // Write headers to virtual filesystem
    for (const [path, content] of Object.entries(headers)) {
        await project.writeFile(path, content);
    }

    // Write generated .c and .h files
    for (const [name, content] of Object.entries(generatedFiles)) {
        await project.writeFile(`/project/${name}`, new TextEncoder().encode(content));
    }

    // Write main.c wrapper
    await project.writeFile("/project/main.c", mainCSource);

    // Compile each .c file to .o
    const cFiles = Object.keys(generatedFiles)
        .filter(f => f.endsWith('.c'))
        .concat(["main.c"]);

    for (const cFile of cFiles) {
        const instance = await clang.entrypoint.run({
            args: [
                `/project/${cFile}`,
                "--target=wasm32-wasi",
                "-DNO_GRAPHICS",
                "-I/project",
                "-I/include",
                "-I/include/actionmodern",
                "-I/include/libswf",
                "-I/include/memory",
                "-c",
                "-O2",
                "-o", `/project/${cFile.replace('.c', '.o')}`,
            ],
            mount: { "/project": project, "/include": includeDir },
        });
        const result = await instance.wait();
        if (!result.ok) throw new Error(`Compile ${cFile} failed: ${result.stderr}`);
    }

    // Link all .o files + runtime library
    const oFiles = cFiles.map(f => `/project/${f.replace('.c', '.o')}`);
    const linkInstance = await clang.entrypoint.run({
        args: [
            ...oFiles,
            "/project/libswfruntime.a",
            "--target=wasm32-wasi",
            "-o", "/project/output.wasm",
            "-lm",
        ],
        mount: { "/project": project },
    });
    const linkResult = await linkInstance.wait();
    if (!linkResult.ok) throw new Error(`Link failed: ${linkResult.stderr}`);

    // Read the compiled WASM binary
    return await project.readFile("/project/output.wasm");
}
```

---

## Step 3: Run the Compiled WASM

### 3.1 WASI Runtime for the Output

The compiled `output.wasm` is a wasm32-wasi binary. It needs WASI imports to run:

- `fd_write` — for printf/trace output (capture to a string buffer)
- `proc_exit` — for exit()
- `clock_time_get` — for getTime()
- `args_get`, `args_sizes_get` — for main(argc, argv)
- Various memory/random imports

**Options for providing WASI:**

1. **@aspect-build/aspect-wasi** or **@aspect-build/aspect-wasi-preview1** — Lightweight WASI polyfill for browsers
2. **wasmer-wasi** (part of @wasmer/sdk) — Can run WASI modules directly
3. **Custom minimal WASI shim** — Only implement the ~5 syscalls actually used. This is simple since we only need stdout capture, a clock, and basic memory.

A minimal WASI shim for trace-only mode:

```javascript
function createWasiImports(traceOutput) {
    return {
        wasi_snapshot_preview1: {
            fd_write(fd, iovs_ptr, iovs_len, nwritten_ptr) {
                // Read iov structs from WASM memory, capture stdout (fd=1)
                // Append to traceOutput array
            },
            proc_exit(code) { /* no-op or signal completion */ },
            clock_time_get(id, precision, time_ptr) {
                // Return performance.now() in nanoseconds
            },
            args_get(argv, argv_buf) { return 0; },
            args_sizes_get(argc_ptr, argv_buf_size_ptr) {
                // Set argc=0
            },
            // ... other stubs as needed
        }
    };
}
```

### 3.2 Instantiation and Execution

```javascript
async function runCompiledSWF(wasmBytes) {
    const traceLines = [];
    const wasiImports = createWasiImports(traceLines);

    const { instance } = await WebAssembly.instantiate(wasmBytes, wasiImports);

    // Call _start (WASI entry point) or main
    instance.exports._start();

    return traceLines.join("\n");
}
```

---

## Step 4: End-to-End Integration

Combine Phase 1 (SWFRecomp.wasm) + Phase 2 (Clang.wasm + runtime linking) + Phase 3 (WASI execution) into a single browser page:

```javascript
async function processSwf(swfBytes) {
    // Phase 1: Recompile SWF → C files
    const generatedFiles = await recompileSWF(swfBytes);  // from Phase 1

    // Phase 2: Compile C → WASM
    const outputWasm = await compileGeneratedCode(generatedFiles, runtimeLib, headers);

    // Phase 3: Run
    const traceOutput = await runCompiledSWF(outputWasm);

    return traceOutput;
}
```

---

## Step 5: Optimize the Compilation Pipeline

### 5.1 Batch Compilation

Instead of invoking Clang once per .c file, investigate whether Wasmer Clang supports compiling multiple files in one invocation:

```bash
clang main.c tagMain.c script_0.c script_defs.c constants.c draws.c \
    libswfruntime.a --target=wasm32-wasi -DNO_GRAPHICS -I... -O2 -o output.wasm
```

This avoids the overhead of spinning up the Clang WASM module multiple times.

### 5.2 Caching

| Asset | Size | Cache Strategy |
|-------|------|---------------|
| `@wasmer/sdk` Clang package | ~100 MB | Wasmer SDK handles caching internally |
| `libswfruntime.a` | ~500 KB–2 MB (estimate) | Cache-Control + IndexedDB |
| Runtime headers | ~80 KB | Inline in JS or Cache-Control |
| SWFRecomp.wasm | 621 KB | Cache-Control |

### 5.3 Progress Reporting

The compilation step may take several seconds. Show progress to the user:
- "Parsing SWF..." (Phase 1, fast)
- "Loading compiler..." (first time only)
- "Compiling..." (Phase 2)
- "Running..." (Phase 3, fast)

---

## Unknowns and Risks

### Risk 1: setjmp/longjmp on wasm32-wasi

The runtime uses `setjmp`/`longjmp` for exception handling. Clang's WASM backend supports this via the WASM Exception Handling proposal (`-mllvm -wasm-enable-sjlj`) or via Emscripten's ASYNCIFY transform.

For wasm32-wasi, the EH-based approach should work, but needs testing. If it doesn't work out of the box, alternatives:
- Compile with `-fno-exceptions` and refactor try-catch in the runtime
- Use a different Clang flag for setjmp support

**Mitigation:** Test this early with a simple C program using setjmp, compiled via Wasmer Clang.

### Risk 2: Wasmer SDK Stability

The SDK is version 0.9.0 (pre-1.0). Open issues include:
- Safari compatibility problems (#465)
- Object file write failures on mounted directories (#467)
- Module serialization errors (#468)

**Mitigation:** Prototype early. If Wasmer proves unreliable, @yowasp/clang is a backup with a simpler API.

### Risk 3: WASI Completeness

The runtime may call WASI functions beyond the basic set (fd_write, clock_time_get, proc_exit). If so, the WASI shim needs to be expanded.

**Mitigation:** Compile a simple test to WASI and check which imports it requires. Add stubs as needed.

### Risk 4: ABI Compatibility Between Pre-compiled .a and In-Browser .o

If the pre-compiled library uses a different LLVM version than Wasmer's Clang, linking may fail.

**Mitigation:** Build the .a using the same Clang that Wasmer ships (via `wasmer run clang/clang` locally), or build it in-browser once on first load and cache it.

### Risk 5: Clang Compilation Speed

Clang running as WASM is slower than native. For small generated files (300-1500 lines), this should be acceptable (seconds, not minutes). For complex SWFs with many scripts, it could be slow.

**Mitigation:** Measure compilation times early. If too slow, consider compiling files in parallel (if Wasmer supports it) or batching into a single invocation.

---

## Implementation Order

### Milestone 1: Prove Wasmer Clang works for our use case
- Install @wasmer/sdk
- Compile a trivial C program (hello world with printf) to wasm32-wasi in-browser
- Run the output with a minimal WASI shim
- Verify stdout capture works

### Milestone 2: Compile a real generated test
- Take the `add2_swf_5` test's generated C files
- Pre-compile libswfruntime.a locally
- Compile the generated files in-browser using Wasmer Clang, link against .a
- Run and verify trace output matches expected

### Milestone 3: Full pipeline integration
- Wire Phase 1 (SWFRecomp.wasm) → Phase 2 (Clang.wasm) → Phase 3 (WASI run)
- User drops any SWF, sees trace output
- Error handling and progress display

### Milestone 4: Polish
- Caching (Clang package, runtime library, headers)
- COOP/COEP headers / coi-serviceworker for GitHub Pages
- Performance measurement and optimization
- UI improvements

---

## Files to Create

| File | Purpose |
|------|---------|
| `scripts/build_wasm_runtime_lib.sh` | Pre-compile libswfruntime.a |
| `wasm_recompiler_demo.html` | Browser demo page (upgrade Phase 1's) |
| `wasm_recompiler_demo.js` | Pipeline orchestration (Stages 1-3) |
| `wasi_shim.js` | Minimal WASI polyfill for running output |

## Expected Output Sizes

| Asset | Estimated Size |
|-------|---------------|
| SWFRecomp.wasm | 621 KB |
| Clang WASM (Wasmer) | ~100 MB (one-time, cached) |
| libswfruntime.a | ~500 KB–2 MB |
| Runtime headers bundle | ~80 KB |
| Per-SWF output.wasm | ~100-500 KB |

## Scope Boundaries

This plan covers **NO_GRAPHICS (trace) mode only.** Graphics mode (WebGPU rendering, audio, mouse input) would require:
- Additional runtime files (tag.c, swf.c, render_webgpu.c, etc.)
- Emscripten-specific features (ASYNCIFY, WebGPU port, JS interop)
- A fundamentally different approach since WASI doesn't provide WebGPU

Graphics support would likely require either:
- Using Emscripten as the in-browser compiler (via Emception, if it gets fixed)
- Direct WASM emission (Option C from the feasibility study)
- A hybrid approach (WASI for logic, JS bridge for rendering)

This is left for a future phase.
