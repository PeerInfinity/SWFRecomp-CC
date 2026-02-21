# Phase 1: Compile the SWFRecomp Recompiler to WASM

**Date:** 2026-02-15
**Status:** Plan
**Parent:** IN_BROWSER_RECOMPILATION_FEASIBILITY.md

## Goal

Get the SWFRecomp recompiler (the C++ program that reads a `.swf` and writes `.c`/`.h` files) compiling and running as WebAssembly, first testable via Node.js CLI, then in a browser demo page.

## Approach: MEMFS (Option A)

Use Emscripten's in-memory virtual filesystem. All existing `ifstream`/`ofstream` calls work transparently — JavaScript writes the SWF bytes into MEMFS before invoking the recompiler, then reads the generated files back out afterward. This requires **minimal C++ changes**.

---

## Step 1: Fix `std::filesystem` usage in `recompilation.cpp`

**File:** `SWFRecomp/src/recompilation.cpp`

This is the **only file** that uses `std::filesystem` (Emscripten's support is limited). There are exactly 3 uses:

```cpp
// Lines 23-26: directory existence check + creation
if (!fs::exists(context.output_tags_folder))
    fs::create_directory(context.output_tags_folder);
if (!fs::exists(context.output_scripts_folder))
    fs::create_directory(context.output_scripts_folder);

// Lines 33-34: path separator
context.output_tags_folder = string("") + context.output_tags_folder + ((char) fs::path::preferred_separator);
context.output_scripts_folder = string("") + context.output_scripts_folder + ((char) fs::path::preferred_separator);
```

**Change:** Replace with POSIX `mkdir()` and hardcoded `'/'`:

```cpp
#include <sys/stat.h>   // instead of <filesystem>

// mkdir -p equivalent (ignore EEXIST)
mkdir(context.output_tags_folder.c_str(), 0755);
mkdir(context.output_scripts_folder.c_str(), 0755);

// POSIX separator (works on all our targets including native Linux)
context.output_tags_folder += '/';
context.output_scripts_folder += '/';
```

This change is safe for the native Linux build too — the project only targets Linux (no Windows `#ifdef` blocks anywhere). The `#include <filesystem>` and `namespace fs` can be removed entirely.

**Risk:** None. This is a strict simplification that works identically on native Linux and Emscripten.

## Step 2: Add an Emscripten entry point

**File:** `SWFRecomp/src/main.cpp`

The current `main()` reads a config file path from `argv[1]`, parses it with toml++, and calls `recompile()`. For the WASM build, we need an exported function that JavaScript can call.

**Two sub-options:**

### Option 2a: Keep `main()` as-is, use MEMFS for config too (simplest)

Write a TOML config string to MEMFS from JavaScript, then call `main()` via `Module.callMain(["config.toml"])`. No C++ changes at all — Emscripten's `callMain` is designed for this.

The JavaScript side would do:
```js
// Write config.toml to MEMFS
FS.writeFile("config.toml", `[input]\npath_to_swf = "input.swf"\noutput_tags_folder = "RecompiledTags"\noutput_scripts_folder = "RecompiledScripts"\n`);

// Write SWF data to MEMFS
FS.writeFile("input.swf", swfBytes);

// Run recompiler
Module.callMain(["config.toml"]);

// Read generated files
const tagMain = FS.readFile("RecompiledTags/tagMain.c", { encoding: "utf8" });
// ... etc
```

### Option 2b: Add a dedicated `EMSCRIPTEN_KEEPALIVE` function (cleaner API)

Add a new entry point that bypasses config parsing:

```cpp
#ifdef __EMSCRIPTEN__
#include <emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE
    int recompile_swf(const char* swf_path) {
        SWFRecomp::Context context;
        context.swf_path = swf_path;
        context.output_tags_folder = "RecompiledTags";
        context.output_scripts_folder = "RecompiledScripts";
        SWFRecomp::recompile(context);
        return 0;
    }
}
#endif
```

JavaScript calls:
```js
FS.writeFile("input.swf", swfBytes);
Module._recompile_swf(Module.allocateUTF8("input.swf"));
```

**Recommendation:** Start with **2a** (zero C++ changes, test immediately), then optionally add 2b later for a cleaner JS API.

## Step 3: Build with Emscripten

**Approach:** Use `emcmake cmake` with the existing `CMakeLists.txt`. The CMake build already uses `add_subdirectory` for zlib and lzma, and Emscripten's CMake toolchain handles these transparently.

**Build script:** `SWFRecomp/scripts/build_wasm_recompiler.sh`

```bash
#!/bin/bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
SWFRECOMP_ROOT="$(cd "${SCRIPT_DIR}/.." && pwd)"
PROJECT_ROOT="$(cd "${SWFRECOMP_ROOT}/.." && pwd)"
BUILD_DIR="${SWFRECOMP_ROOT}/build_wasm"

# Source Emscripten
source "${PROJECT_ROOT}/emsdk/emsdk_env.sh"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

emcmake cmake "${SWFRECOMP_ROOT}" \
    -DCMAKE_BUILD_TYPE=Release

emmake make -j$(nproc)

# The output is build_wasm/SWFRecomp.js + SWFRecomp.wasm
echo "Built: ${BUILD_DIR}/SWFRecomp.js + SWFRecomp.wasm"
```

**Required CMake additions** (conditional on Emscripten):

```cmake
if(EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".js"
    )
    target_link_options(${PROJECT_NAME} PRIVATE
        -sMODULARIZE=1
        -sEXPORT_NAME="SWFRecompModule"
        -sEXPORTED_RUNTIME_METHODS=["callMain","FS"]
        -sALLOW_MEMORY_GROWTH=1
        -sINITIAL_MEMORY=33554432
        -sENVIRONMENT=node,web
        -sEXIT_RUNTIME=0
        -sINVOKE_RUN=0
        -O2
    )
endif()
```

Key flags:
- `-sMODULARIZE=1` + `-sEXPORT_NAME`: makes it a proper JS module (not a global)
- `-sEXPORTED_RUNTIME_METHODS=["callMain","FS"]`: exposes `callMain()` and MEMFS `FS` API
- `-sINVOKE_RUN=0`: don't run `main()` on load — we call it explicitly
- `-sENVIRONMENT=node,web`: support both Node.js testing and browser use

**Potential issues to watch for:**
1. **toml++ and `ifstream`**: toml++'s `parse_file()` opens a file via `ifstream`. This works on MEMFS, but we need to write the TOML file to MEMFS first. With approach 2a this is handled naturally.
2. **`printf`/`fprintf` output**: Goes to the JS console in browser, stdout in Node.js. No changes needed, but for the browser demo we may want to capture it.
3. **Exception handling**: The recompiler uses C++ exceptions (`throw std::exception()`). Emscripten supports these by default (with some code size overhead). If binary size matters later, we could add `-fno-exceptions` and refactor error handling, but this is not needed for Phase 1.

## Step 4: Test with Node.js

**Test script:** `SWFRecomp/scripts/test_wasm_recompiler.mjs`

```js
import SWFRecompModule from "../build_wasm/SWFRecomp.js";
import fs from "fs";

const Module = await SWFRecompModule();

// Load a test SWF
const swfData = fs.readFileSync(process.argv[2] || "../tests/trace_hello_world/test.swf");

// Write to MEMFS
Module.FS.writeFile("input.swf", swfData);
Module.FS.writeFile("config.toml",
    `[input]\npath_to_swf = "input.swf"\noutput_tags_folder = "RecompiledTags"\noutput_scripts_folder = "RecompiledScripts"\n`
);

// Run recompiler
Module.callMain(["config.toml"]);

// List generated files
console.log("=== Generated files ===");
for (const dir of ["RecompiledTags", "RecompiledScripts"]) {
    for (const file of Module.FS.readdir(dir)) {
        if (file === "." || file === "..") continue;
        const content = Module.FS.readFile(`${dir}/${file}`, { encoding: "utf8" });
        console.log(`\n--- ${dir}/${file} (${content.length} bytes) ---`);
        console.log(content.slice(0, 500) + (content.length > 500 ? "\n..." : ""));
    }
}
```

**Verification:** Run against the simplest existing test (`trace_hello_world`) and diff the generated C files against the native build's output. They should be byte-identical.

```bash
# Native build output (already exists)
diff <(cat tests/trace_hello_world/RecompiledTags/tagMain.c) \
     <(node scripts/test_wasm_recompiler.mjs tests/trace_hello_world/test.swf 2>/dev/null | ...)
```

## Step 5: Browser demo page

**File:** `SWFRecomp/wasm_recompiler_demo.html`

A simple single-page HTML file:
- Drag-and-drop zone for `.swf` files (or file picker button)
- "Recompile" button
- Output panel showing the generated C file names and contents (syntax highlighted if easy, plain text otherwise)
- Console output area (captures `printf` output from the recompiler)
- Download button to save the generated files as a `.zip` or `.tar`

The page loads `build_wasm/SWFRecomp.js` and uses the same MEMFS pattern as the Node.js test.

This step can be done after the CLI test is working — it's purely a JS/HTML wrapper around the same WASM module.

---

## Summary of C++ changes

| File | Change | Impact on native build |
|------|--------|----------------------|
| `recompilation.cpp` | Replace `<filesystem>` with `<sys/stat.h>` + `mkdir()` | None — works identically on Linux |
| `CMakeLists.txt` | Add `if(EMSCRIPTEN)` block for link flags | None — block is skipped for native builds |
| `main.cpp` | (Optional) Add `#ifdef __EMSCRIPTEN__` entry point | None — guarded by preprocessor |

**Total C++ diff: ~15 lines changed, ~5 lines added.**

## New files

| File | Purpose |
|------|---------|
| `scripts/build_wasm_recompiler.sh` | Build script (calls emcmake + emmake) |
| `scripts/test_wasm_recompiler.mjs` | Node.js smoke test |
| `wasm_recompiler_demo.html` | Browser demo page (Step 5) |

## Expected output

- `build_wasm/SWFRecomp.js` — ~50-100 KB JS glue
- `build_wasm/SWFRecomp.wasm` — ~1-3 MB WASM binary (recompiler + zlib + lzma + stb + toml++ + earcut)

## What this does NOT include

- Stage 2 (compiling the generated C to WASM in-browser) — that's a separate effort
- Any changes to the runtime (`SWFModernRuntime`)
- Any changes to the native build pipeline or test infrastructure
