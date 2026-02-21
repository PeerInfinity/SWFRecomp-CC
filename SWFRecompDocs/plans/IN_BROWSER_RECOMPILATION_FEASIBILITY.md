# Feasibility Study: Full In-Browser SWF Recompilation Pipeline

**Date:** 2026-02-14
**Status:** Research / Investigation

## 1. The Vision

Load a `.swf` file in the browser, recompile it to executable code, and run it — all client-side, with no server involvement.

```
User drops .swf file into browser
  → [Stage 1] SWFRecomp parses SWF, generates executable code
  → [Stage 2] Code is compiled to WASM
  → [Stage 3] WASM executes with SWFModernRuntime (graphics, audio, input)
```

## 2. Current Architecture

Today the pipeline runs on a developer's machine:

```
SWF file
  → [SWFRecomp]  C++ executable, reads .swf, writes ~10 .c files
  → [emcc / gcc]  Compiles generated C + SWFModernRuntime → WASM or native binary
  → [Browser]     Runs the WASM with WebGPU, audio, mouse input
```

**Key insight:** Stage 3 (the runtime) already runs in the browser as WASM. The question is whether Stages 1 and 2 can also move into the browser.

---

## 3. Stage 1: Compiling the Recompiler to WASM

### 3.1 Assessment: Feasible (moderate effort)

The SWFRecomp recompiler is written in C++17 (~10K lines) and is well-suited for Emscripten compilation.

### 3.2 Favorable Properties

| Property | Details |
|----------|---------|
| **No OS-specific code** | Zero `#ifdef _WIN32` blocks, no platform conditionals |
| **No process spawning** | No `system()`, `fork()`, `exec()`, `popen()` calls |
| **No threading** | Entirely single-threaded |
| **No networking** | Pure local computation |
| **No mmap or signals** | No POSIX-specific memory or signal APIs |
| **Pure C/C++ dependencies** | All libraries compile under Emscripten (see below) |

### 3.3 Dependencies — All WASM-Compatible

| Library | Type | Purpose | Emscripten Support |
|---------|------|---------|-------------------|
| **zlib** | Bundled C source | SWF decompression (zlib-compressed SWFs) | Excellent — pure C, no platform deps |
| **lzma** | Bundled C source | SWF decompression (LZMA-compressed SWFs) | Excellent — pure C, no platform deps |
| **toml++** | Header-only C++ | Config file parsing | Good — uses `ifstream` internally |
| **earcut** | Header-only C++ | Polygon triangulation for shapes | Excellent — pure math, no deps |
| **stb_image** | Single-header C | JPEG/PNG decoding for embedded images | Good — data passed as buffers |

### 3.4 What Needs Refactoring

#### 3.4.1 File I/O → In-Memory Buffers

**Current behavior:** The recompiler reads a SWF file via `ifstream` and writes ~10 output `.c`/`.h` files via `ofstream`.

**Input reading** (`swf.cpp:154`):
```cpp
ifstream swf_file(context.swf_path, ios_base::in | ios_base::binary);
```

**Output writing** (`recompilation.cpp:36-48`, `swf.cpp:2152-4305`):
```cpp
context.tag_main = ofstream(context.output_tags_folder + "tagMain.c", ios_base::out);
context.constants = ofstream(context.output_tags_folder + "constants.c", ios_base::out);
context.draws     = ofstream(context.output_tags_folder + "draws.c", ios_base::out);
// ... plus script_*.c files for each frame/button script
```

**Solution options:**

- **Option A (simplest):** Use Emscripten's `MEMFS`. Write the SWF bytes to the virtual filesystem from JavaScript, run the recompiler, read the generated files back out. No C++ changes needed — `ifstream`/`ofstream` work transparently on `MEMFS`.

- **Option B (cleanest):** Refactor the recompiler to accept a byte buffer as input and produce output via `std::ostringstream` collected into a `std::map<std::string, std::string>`. Expose a new C API:
  ```cpp
  extern "C" {
      EMSCRIPTEN_KEEPALIVE
      RecompileResult* recompile_swf(const uint8_t* swf_data, size_t swf_size);
  }
  ```

#### 3.4.2 Directory Creation

**Current behavior** (`recompilation.cpp:23-31`):
```cpp
namespace fs = std::filesystem;
if (!fs::exists(context.output_tags_folder))
    fs::create_directory(context.output_tags_folder);
if (!fs::exists(context.output_scripts_folder))
    fs::create_directory(context.output_scripts_folder);
```

**Issue:** `std::filesystem` has limited/experimental support in Emscripten.

**Solution:** Replace with POSIX `mkdir()` (supported by Emscripten), or pre-create directories from JavaScript before calling the recompiler, or use `MEMFS` which handles directory creation.

#### 3.4.3 Config Parsing

**Current behavior** (`config.cpp`): Reads a TOML file via `toml::parse_file()`.

**Solution:** For in-browser use, pass config values directly via function parameters instead of through a file, or write a TOML string to `MEMFS` and parse it as a file.

#### 3.4.4 Entry Point

**Current behavior** (`main.cpp`): CLI with `main(argc, argv)`.

**Solution:** Add a new `EMSCRIPTEN_KEEPALIVE` entry point alongside the existing `main()`.

### 3.5 Estimated WASM Binary Size

The recompiler is ~10K lines of C++ with bundled zlib/lzma/stb. Expected WASM output: **~1–3 MB** after `-O2` optimization. Acceptable for a web application.

### 3.6 Verdict

**Stage 1 is straightforward.** The simplest path is to use Emscripten's `MEMFS` — write the SWF to the virtual filesystem from JavaScript, invoke the recompiler, then read the generated C files back. This requires minimal C++ changes (just adding an exported entry point and possibly bypassing config file parsing).

---

## 4. Stage 2: Compiling Generated C to WASM in the Browser

### 4.1 Assessment: Theoretically feasible, practically the hardest step

This is the critical bottleneck in the pipeline. The recompiler produces C source code that must be compiled to WASM — and doing that inside a browser is non-trivial.

### 4.2 Characteristics of the Generated C Code

The generated code is **not a trivial C subset**. It uses real C features that any compiler must handle:

#### Constructs Used

| Construct | Usage Pattern | Compiler Difficulty |
|-----------|--------------|-------------------|
| **Function calls** | ~100 runtime API calls (`actionAdd()`, `actionTrace()`, etc.) | Easy |
| **Macros** | `PUSH()`, `POP()`, `PUSH_STR()`, `VAL()` — ~30% of generated code | Preprocessor required |
| **`goto` statements** | Label-based jumps from bytecode branch instructions | Hard for WASM (structured control flow only) |
| **`setjmp`/`longjmp`** | Try-catch-finally exception handling | Hard for WASM (requires ASYNCIFY or Emscripten EH) |
| **Function pointers** | Dynamic dispatch, function definitions | Moderate (WASM `call_indirect`) |
| **Pointer arithmetic** | Stack is a `char[]` buffer, accessed via typed pointer casts | Moderate |
| **Struct access** | `ActionVar`, `ASObject`, `ASFunction` — heavy struct usage | Moderate |
| **Type casting** | Frequent `(ASObject*)`, `(ASFunction*)`, `(ASArray*)` casts | Moderate |
| **`malloc`/`free`** | Heap allocation for objects, arrays, strings | Standard (WASM linear memory) |

#### Example Generated Code

Simple trace test:
```c
void script_0(SWFAppContext* app_context) {
    char* stack = app_context->stack;
    u32* sp = &app_context->sp;

    // Push (String) "Hello World!"
    PUSH_STR(str_0, 14);
    // Trace
    actionTrace(app_context);
}
```

Complex script with control flow and exceptions:
```c
void script_5(SWFAppContext* app_context) {
    char* stack = app_context->stack;
    u32* sp = &app_context->sp;

    PUSH_STR(str_3, 5);
    actionGetVariable(app_context);

    if (evaluateCondition(stack, sp) == 0)
        goto label_42;

    // ... more operations ...

label_42:
    if (ACTION_TRY_SETJMP(app_context) == 0) {
        actionCallMethod(app_context);
    } else {
        actionCatchToVariable(app_context, "e");
    }
    actionTryEnd(app_context);
}
```

#### Runtime Linkage

The generated C code does not stand alone — it must be linked against the full `SWFModernRuntime` library (~42K lines of C across `action.c`, `object.c`, `variables.c`, plus `swf.c`, `tag.c`, etc.).

### 4.3 Options for In-Browser C-to-WASM Compilation

#### Option A: Ship Clang as WASM (Wasmer JS SDK)

**How it works:** The Wasmer project has compiled the full Clang compiler to run as WebAssembly. Their JS SDK exposes it for in-browser use.

**Pipeline:**
```
Generated C files (in memory)
  → [Clang.wasm (~30-100MB)] compiles to .o files
  → [LLD.wasm] links .o + libSWFModernRuntime.a → final .wasm
  → [WebAssembly.instantiate()] runs it
```

| Aspect | Details |
|--------|---------|
| **Download size** | ~30 MB compressed, ~100 MB uncompressed |
| **C feature coverage** | Full C17 — handles everything including `goto`, `setjmp`, complex pointer arithmetic |
| **Compilation speed** | Slow (Clang itself running as WASM adds overhead) |
| **Development effort** | Low — use the SDK as-is |
| **Maturity** | Production-ish (Wasmer, announced October 2024) |
| **Requirements** | Cross-Origin Isolation headers (COOP/COEP) for `SharedArrayBuffer` |
| **Caching** | WASM modules cache well; one-time download |

**References:**
- Wasmer blog: "Running Clang in the browser using WebAssembly"
- JS SDK: `@wasmer/sdk` npm package
- Live demo: wasmer.sh

**Verdict:** This is the **fastest path to a working prototype**. Accept the large download, cache it aggressively, and get full C compatibility for free.

#### Option B: binji/wasm-clang (Older Demo)

A demo by Ben Smith (ex-Google/V8) that compiles Clang + LLD to WASM. Demonstrated at CppCon 2019.

| Aspect | Details |
|--------|---------|
| **Download size** | Large (comparable to Wasmer) |
| **Maturity** | "Very much alpha demoware" — not actively maintained |
| **Availability** | GitHub: binji/wasm-clang |

**Verdict:** Proof that it works, but Wasmer's SDK is more actively maintained.

#### Option C: Emit WASM Directly from the Recompiler (Skip C Entirely)

Instead of generating C source, modify `action.cpp` to emit WASM binary directly.

**Pipeline:**
```
SWF file
  → [SWFRecomp.wasm] parses SWF, emits WASM binary directly
  → [WebAssembly.instantiate()] runs it with runtime as imports
```

**How AVM1 opcodes map to WASM:**

| AVM1 Pattern | WASM Equivalent |
|-------------|-----------------|
| Push constant | `i32.const` / `f64.const` + `call $push` |
| Arithmetic (`ActionAdd`) | `call $actionAdd` (imported runtime function) |
| Variable access | `call $getVariable` / `call $setVariable` |
| Conditional branch | `if`/`else`/`end` blocks |
| Unconditional jump (goto) | Requires Relooper/Stackifier algorithm |
| Function call | `call` / `call_indirect` |
| Try-catch | WASM exception handling proposal, or manual unwinding |

**Key challenges:**

1. **Structured control flow problem.** WASM does not have `goto`. The recompiler currently emits `goto label_N` for bytecode branches. To emit WASM directly, you'd need the **Relooper algorithm** (used by Emscripten) or the **Stackifier algorithm** (used by LLVM's WASM backend) to convert arbitrary control flow graphs into WASM's structured `block`/`loop`/`if`/`br` instructions. Binaryen provides a Relooper implementation.

2. **`setjmp`/`longjmp` semantics.** WASM has no native `setjmp`/`longjmp`. Emscripten implements these via the ASYNCIFY transform (which instruments the entire call stack) or via the WASM Exception Handling proposal. A direct WASM emitter would need to implement one of these approaches.

3. **Runtime linkage.** The ~100 runtime functions would become WASM imports. The runtime itself would need to be a separate WASM module (already the case today), and the generated code would call into it via imported functions.

| Aspect | Details |
|--------|---------|
| **Download size** | Zero extra — built into the recompiler |
| **Compilation speed** | Very fast (no LLVM overhead, direct emission) |
| **Development effort** | Very high — requires Relooper, exception handling, WASM binary format emission |
| **C feature coverage** | N/A — bypasses C entirely |

**Verdict:** The most elegant long-term solution. Eliminates the entire "compile C in browser" problem. But requires significant engineering.

#### Option D: Custom Lightweight C-to-WASM Compiler

Write a purpose-built compiler (in C++ compiled to WASM, or in JavaScript) that handles only the C subset the recompiler generates.

| Aspect | Details |
|--------|---------|
| **Download size** | Potentially <1 MB |
| **C feature coverage** | Only what SWFRecomp generates |
| **Development effort** | Very high — essentially writing a C compiler |
| **Risk** | Must correctly handle `goto`, `setjmp`, macros, pointer arithmetic |

**Verdict:** Not recommended. The generated C uses enough real C features (`goto`, `setjmp`, function pointers, pointer arithmetic, macros) that a "lightweight" compiler would end up being a near-complete C compiler anyway.

#### Option E: TCC (Tiny C Compiler) with WASM Backend

TCC is Fabrice Bellard's tiny C compiler (~100KB native binary). It compiles very fast (10x faster than GCC) but currently has **no WASM code generation backend** — it only targets x86, x86-64, ARM, AArch64, and RISC-V.

| Aspect | Details |
|--------|---------|
| **Download size** | ~1-3 MB estimated as WASM |
| **Compilation speed** | Very fast (single-pass) |
| **Development effort** | High — requires writing a `wasm32-gen.c` backend for TCC |
| **Output quality** | Unoptimized (TCC has no optimization passes) |

**Verdict:** Promising hypothetically, but the WASM backend doesn't exist and would need to be written from scratch.

#### Option F: Recompile to an Interpreted Format Instead of C

Instead of generating C code, generate a compact bytecode or data format that the existing runtime interprets directly.

**Pipeline:**
```
SWF file
  → [SWFRecomp.wasm] parses SWF, emits compact bytecode/data tables
  → [SWFModernRuntime.wasm] interprets the bytecode directly
  → No C compilation step needed at all
```

The runtime's `action.c` already implements an interpreter for AVM1 semantics. The "recompiled" scripts could be encoded as data tables (opcode arrays with operands) rather than C source code. The runtime would dispatch on these opcodes rather than executing pre-compiled C functions.

| Aspect | Details |
|--------|---------|
| **Download size** | Zero extra |
| **Speed** | Slower than compiled code (interpretation overhead) |
| **Development effort** | Moderate — modify recompiler output format + add interpreter loop to runtime |
| **Complexity** | Lower than Options C/D/E — no compiler needed |

**Verdict:** A pragmatic middle ground. Trading some runtime performance for much simpler architecture.

### 4.4 Comparison Table

| Approach | Download Size | Dev Effort | Compile Speed | Run Speed | Maturity |
|----------|:------------:|:----------:|:-------------:|:---------:|:--------:|
| **A: Wasmer+Clang** | ~30-100 MB | Low | Slow | Fast (compiled) | Production-ish |
| **B: wasm-clang** | ~30+ MB | Low | Slow | Fast (compiled) | Alpha |
| **C: Emit WASM directly** | 0 | Very High | Very Fast | Fast (compiled) | N/A |
| **D: Custom C compiler** | <1 MB | Very High | Fast | Fast (compiled) | N/A |
| **E: TCC+WASM backend** | ~1-3 MB | High | Very Fast | Moderate (unoptimized) | N/A |
| **F: Interpreted format** | 0 | Moderate | Instant (no compilation) | Moderate (interpreted) | N/A |

---

## 5. Stage 3: Running the Result in the Browser

### 5.1 Assessment: Already working

The `SWFModernRuntime` already compiles to WASM and runs in the browser. This is fully implemented:

| Feature | Implementation |
|---------|---------------|
| **WebGPU rendering** | `render_webgpu.c` — canvas surface via `#canvas` selector, emdawnwebgpu port |
| **Audio output** | `audio_output_web.c` — `EM_ASM` + ScriptProcessorNode, shared `HEAPF32` buffer |
| **Mouse input** | Emscripten callbacks: `emscripten_set_mousemove_callback()`, etc. |
| **Frame timing** | `emscripten_sleep()` + ASYNCIFY for frame-rate-accurate playback |
| **JS interop** | `EMSCRIPTEN_KEEPALIVE` exports, `Module.ccall()` from JavaScript |
| **HTML wrappers** | `wasm_wrappers/index_template.html` (trace), `index_template_graphics.html` (graphics), `docs/demo.html` |

### 5.2 Build Flags (Already Defined)

Trace mode:
```bash
emcc *.c -DNO_GRAPHICS -sWASM=1 -sEXPORTED_FUNCTIONS='["_main","_runSWF"]' \
    -sEXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -sALLOW_MEMORY_GROWTH=1 \
    -sINITIAL_MEMORY=16MB -O2
```

Graphics mode:
```bash
emcc *.c -DUSE_WEBGPU --use-port=emdawnwebgpu \
    -sEXPORTED_FUNCTIONS='["_main","_runSWF","_audio_fill_buffer"]' \
    -sEXPORTED_RUNTIME_METHODS='["ccall","cwrap","HEAPF32"]' \
    -sALLOW_MEMORY_GROWTH=1 -sINITIAL_MEMORY=64MB -sASYNCIFY \
    -sASYNCIFY_STACK_SIZE=65536 -O2
```

### 5.3 Verdict

**Stage 3 requires no new work.** The runtime, rendering, audio, and input all function in the browser today.

---

## 6. End-to-End Architecture Proposals

### 6.1 Quickest Path: Wasmer + Clang (Option A)

```
                        Browser
┌──────────────────────────────────────────────────┐
│                                                  │
│  User drops .swf file                            │
│       │                                          │
│       ▼                                          │
│  [SWFRecomp.wasm]  (~1-3 MB, cached)             │
│  Reads SWF from MEMFS, writes .c files to MEMFS  │
│       │                                          │
│       ▼                                          │
│  [Clang.wasm]  (~30-100 MB, cached)              │
│  Compiles .c files + links runtime → output.wasm │
│       │                                          │
│       ▼                                          │
│  [WebAssembly.instantiate(output.wasm)]           │
│  Runs with WebGPU, audio, mouse input            │
│                                                  │
└──────────────────────────────────────────────────┘
```

**Pros:** Minimal code changes. Works with current C code generation.
**Cons:** ~30-100 MB one-time download for Clang. Requires COOP/COEP headers. Slow compilation step.

### 6.2 Most Elegant: Direct WASM Emission (Option C)

```
                        Browser
┌──────────────────────────────────────────────────┐
│                                                  │
│  User drops .swf file                            │
│       │                                          │
│       ▼                                          │
│  [SWFRecomp.wasm]  (~1-3 MB, cached)             │
│  Reads SWF, emits WASM binary directly            │
│  (no C intermediate, no compiler needed)          │
│       │                                          │
│       ▼                                          │
│  [WebAssembly.instantiate(generated.wasm)]        │
│  imports: SWFModernRuntime.wasm functions          │
│  Runs with WebGPU, audio, mouse input            │
│                                                  │
└──────────────────────────────────────────────────┘
```

**Pros:** Tiny total download (~1-3 MB). No C compiler needed. Fast.
**Cons:** Major engineering effort. Must solve structured control flow (Relooper), exception handling, and WASM binary emission.

### 6.3 Most Pragmatic: Interpreted Bytecode (Option F)

```
                        Browser
┌──────────────────────────────────────────────────┐
│                                                  │
│  User drops .swf file                            │
│       │                                          │
│       ▼                                          │
│  [SWFRecomp.wasm]  (~1-3 MB, cached)             │
│  Reads SWF, emits compact opcode tables           │
│       │                                          │
│       ▼                                          │
│  [SWFModernRuntime.wasm]  (pre-compiled, cached)  │
│  Interprets opcode tables directly                │
│  Runs with WebGPU, audio, mouse input            │
│                                                  │
└──────────────────────────────────────────────────┘
```

**Pros:** Moderate effort. Small download. No compiler needed. Simpler than direct WASM emission.
**Cons:** Slower execution (interpretation vs. compilation). Requires changes to both recompiler output and runtime.

---

## 7. Key Technical Challenges

### 7.1 The Structured Control Flow Problem (Options C, D)

WASM enforces **structured control flow** — it has `block`, `loop`, `if`/`else`, and `br`/`br_if`/`br_table`, but no `goto`. The generated C code currently uses `goto` for bytecode branch targets.

**Solutions:**
- **Relooper algorithm** (Emscripten's approach): Analyzes the control flow graph and reconstructs structured control flow using loops and conditional branches. Available in Binaryen.
- **Stackifier algorithm** (LLVM's approach): Similar goal, different algorithm. Used by LLVM's WASM backend.
- **Avoid the problem:** If modifying the recompiler, generate structured control flow directly instead of `goto`-based code. AVM1 bytecode branches are relative offsets — many can be converted to structured `if`/`while` without the Relooper.

### 7.2 setjmp/longjmp in WASM (Options C, D)

WASM has no native `setjmp`/`longjmp`. Current approaches:

- **Emscripten ASYNCIFY:** Instruments the entire call stack to allow unwinding and rewinding. Used by the runtime today.
- **WASM Exception Handling proposal:** Newer, more efficient. Uses `try`/`catch`/`throw` instructions. Supported in Chrome, Firefox, Safari.
- **Manual approach:** For direct WASM emission, implement try-catch using the WASM EH proposal, which is a natural fit for ActionScript's try-catch semantics.

### 7.3 Linking Generated Code with Runtime (Options A, C)

The generated code calls ~100 runtime functions. These must be available at link time:

- **For Clang approach (A):** Pre-compile `SWFModernRuntime` to a `.a` static library (WASM object files). Ship it alongside Clang. LLD links everything together.
- **For direct WASM emission (C):** The runtime functions become WASM imports. The runtime is a separate WASM module, and the generated module declares imports that the JavaScript instantiation step resolves.

### 7.4 Memory Model

Both the recompiler-generated code and the runtime share a single linear memory (WASM's memory model). The existing architecture uses:
- 8 MB stack buffer (byte array with pointer arithmetic)
- Heap allocations via `malloc`/`free` (backed by o1heap or dlmalloc in Emscripten)
- String interning and variable arrays

This works naturally in WASM's linear memory model — no special handling needed.

---

## 8. Recommended Path Forward

### Phase 1: Compile the recompiler to WASM (low risk, moderate effort)

1. Add `#ifdef __EMSCRIPTEN__` entry point to `main.cpp`
2. Replace `std::filesystem` calls with POSIX `mkdir()` or use MEMFS
3. Optionally refactor config parsing to accept parameters directly
4. Build with Emscripten: `emcmake cmake . && make`
5. Test: load SWF via JavaScript, invoke recompiler, verify generated C output

This step is valuable regardless of which Stage 2 approach is chosen — it proves the recompiler works in WASM.

### Phase 2: Choose a Stage 2 strategy

- **For a quick proof-of-concept:** Use Wasmer + Clang (Option A). Accept the large download.
- **For a production tool:** Invest in direct WASM emission (Option C) or interpreted bytecode (Option F).
- **For a middle ground:** Start with Option A, then migrate to Option C or F over time.

### Phase 3: Integration

- Build the browser UI (file upload, progress display, output rendering)
- Handle WASM module lifecycle (instantiation, memory management, cleanup)
- Add error handling and user feedback throughout the pipeline

---

## 9. Summary

| Question | Answer |
|----------|--------|
| **Can the recompiler run in the browser?** | Yes — moderate refactoring of file I/O, all dependencies are WASM-compatible |
| **Can generated C be compiled in the browser?** | Yes — via Wasmer+Clang (~30-100 MB) or binji/wasm-clang |
| **Can C compilation be avoided entirely?** | Yes — by emitting WASM directly (hard) or using an interpreted format (moderate) |
| **Does the runtime work in the browser?** | Already works — WebGPU, audio, input all implemented |
| **Is the full pipeline theoretically possible?** | **Yes, by multiple approaches** |
| **What's the fastest path to a demo?** | Compile recompiler to WASM + Wasmer Clang SDK |
| **What's the best long-term architecture?** | Direct WASM emission from the recompiler, eliminating the C intermediate step |
