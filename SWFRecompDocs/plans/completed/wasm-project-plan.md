> **AUDIT OUTCOME (2026-07-04):** Shipped — WASM builds + WebGPU graphics are the production browser path.

# SWFRecomp WASM Port - Project Plan

**Document Version:** 1.2

**Created:** October 27, 2025

**Last Updated:** February 5, 2026

**Upstream Project:** SWFRecomp + SWFModernRuntime

**Status:** Phase 1a Complete, Phase 1b Skipped → Proceeding to Phase 2 (WebGPU)

---

## Table of Contents

1. [Project Overview](#project-overview)
2. [Technical Architecture](#technical-architecture)
3. [Phase 1: Canvas2D Prototype](#phase-1-canvas2d-prototype)
4. [Phase 2: WebGPU Backend (SDL + Dawn/wgpu)](#phase-2-webgpu-backend-sdl--dawnwgpu)
5. [Phase 3: SDL_GPU WebGPU Migration](#phase-3-sdl_gpu-webgpu-migration)
6. [Maintaining Native Runtime Compatibility](#maintaining-native-runtime-compatibility)
7. [Build System Design](#build-system-design)
8. [Testing Strategy](#testing-strategy)
9. [Upstream Sync Strategy](#upstream-sync-strategy)
10. [Timeline & Milestones](#timeline--milestones)
11. [Risk Management](#risk-management)

---

## Project Overview

### Goals

**Primary Goal:** Enable SWFRecomp-generated C code to run in web browsers via WebAssembly (WASM) while maintaining full native runtime compatibility.

**Secondary Goals:**
- Preserve all existing native runtime functionality
- Maintain compatibility with upstream development
- Create a path for WebGPU rendering (SDL + Dawn/wgpu natively, emdawnwebgpu in browser)
- Enable Flash games to run in modern browsers without plugins

### Non-Goals

- ❌ Replacing or modifying upstream native runtime
- ❌ Comprehensive WebGPU optimization beyond target FPS
- ❌ Supporting browsers without WASM support

### Success Criteria

1. ✅ Generated C code compiles to WASM with Emscripten - **ACHIEVED**
2. ⏳ Basic graphics rendering works in browser (Canvas2D) - **IN PROGRESS**
3. ✅ ActionScript execution works in WASM - **ACHIEVED** (trace_swf_4 example working)
4. ✅ Native runtime builds remain unaffected - **MAINTAINED** (on wasm-support branch)
5. ⏳ Test suite passes in both native and WASM builds - **IN PROGRESS**
6. ✅ Easy to sync with upstream changes - **ACHIEVED** (clean separation via wasm/ directory)

### Recent Upstream Progress (October 2025)

**Major Rendering Updates:**
- ✅ **Gradients implemented** - Linear and radial gradients with compute shader support
- ✅ **Bitmaps implemented** - Texture rendering with style indices
- ✅ **MSAA support** - Multi-sample anti-aliasing added
- ✅ **Refactored rendering** - color_info → texture_info, static shapes optimized
- ✅ **Display list architecture** - Character and DisplayObject structs, proper transforms

**Impact on WASM Fork:**
- ⚠️ Rendering backend has significantly evolved since planning phase
- ⚠️ Canvas2D backend will need to support gradients and bitmaps
- ✅ Good news: These features improve visual quality targets
- ⚠️ Complexity: WebGPU backend is now essential for feature parity (elevated to Phase 2)
- ⚠️ Plan adjustment: WebGPU chosen over WebGL2 for better Vulkan alignment and compute shader support

---

## Technical Architecture

### Current Architecture (Native)

```
SWF File
    ↓
SWFRecomp (unchanged - pure C++ tool)
    ↓
Generated C Code
    ├─ RecompiledTags/*.c
    └─ RecompiledScripts/*.c
    ↓
SWFModernRuntime
    ├─ libswf/ (frame management, SWF execution)
    ├─ actionmodern/ (ActionScript VM)
    └─ flashbang/ (SDL_GPU rendering)
    ↓
Native Executable (Linux/Windows/macOS)
```

### Target Architecture (WASM-Compatible)

```
SWF File
    ↓
SWFRecomp (unchanged - still native tool)
    ↓
Generated C Code (100% portable)
    ├─ RecompiledTags/*.c
    └─ RecompiledScripts/*.c
    ↓
SWFModernRuntime Core (WASM-compatible)
    ├─ libswf/ ✅ Portable
    ├─ actionmodern/ ✅ Portable
    └─ rendering/ (ABSTRACTED)
        ├─ render_api.h (interface)
        ├─ render_native.c (SDL_GPU/Vulkan) #ifndef __EMSCRIPTEN__ && !USE_WEBGPU
        ├─ render_canvas2d.c (Canvas2D) #ifdef __EMSCRIPTEN__ && !USE_WEBGPU
        └─ render_webgpu.c (WebGPU via webgpu.h) #ifdef USE_WEBGPU
            ├─ Native: SDL3 + sdl3webgpu + Dawn/wgpu-native
            └─ WASM: emdawnwebgpu (--use-port=emdawnwebgpu)
    ↓
Build Target Selection
    ├─→ Native Executable (Linux/Windows/macOS)
    └─→ WASM Binary + HTML/JS (Browser)
```

### Key Design Principles

1. **Minimal Native Impact:** Native builds should compile exactly as before
2. **Clean Abstraction:** Rendering backend swappable via compile-time flags
3. **Upstream Friendly:** Changes isolated, easy to merge
4. **Progressive Enhancement:** Start simple (Canvas2D), upgrade to WebGPU (Phase 2)

---

## Phase 1: WASM Compilation Proof-of-Concept

**Status:** Phase 1a Complete; Phase 1b (Canvas2D rendering) Skipped

**Priority:** High

**Goal:** Prove WASM compilation works end-to-end

### Progress Update

**✅ Phase 1a Completed (WASM Infrastructure):**
- Emscripten compilation working (trace_swf_4 example)
- ActionScript VM execution in WASM
- Frame management and execution
- Basic runtime infrastructure (runtime.c)
- Build scripts and HTML templates
- GitHub Pages deployment
- Live demo at https://peerinfinity.github.io/SWFModernRuntime/

**⏭️ Phase 1b Skipped (Canvas2D Rendering):**

Canvas2D rendering has been skipped in favor of proceeding directly to Phase 2 (WebGPU).

**Rationale for skipping Canvas2D rendering:**
1. Canvas2D code would be entirely thrown away when moving to WebGPU — zero reuse
2. Upstream uses compute shaders for gradients; Canvas2D has no compute, requiring
   CPU workarounds that are also thrown away
3. WebGPU initialization is not fundamentally harder than Canvas2D EM_ASM interop
4. The rendering abstraction layer (`render_api.h`) is the same regardless of backend
5. NO_GRAPHICS mode already covers non-rendering WASM test cases

### Objectives

1. ✅ Compile generated C code with Emscripten - **DONE**
2. ⏭️ ~~Create Canvas2D rendering backend~~ - **SKIPPED (proceeding to WebGPU)**
3. ⏭️ ~~Render basic shapes via Canvas2D~~ - **SKIPPED (will render via WebGPU instead)**
4. ✅ Verify ActionScript execution in WASM - **DONE** (trace_swf_4)
5. ⏭️ ~~Run graphics tests with Canvas2D~~ - **SKIPPED (will use WebGPU)**

### Dependencies

**Tools:**
- Emscripten SDK (latest)
- Python 3.x (for Emscripten)
- Node.js (for testing)
- Web browser with WASM support

**Knowledge:**
- C/C++ (already have)
- JavaScript basics
- HTML5 Canvas API
- Emscripten build system

### Architecture

#### Rendering Abstraction Layer

```c
// src/rendering/render_api.h
#ifndef RENDER_API_H
#define RENDER_API_H

#include <common.h>

typedef struct RenderContext {
    int width;
    int height;
    void* backend_data;
} RenderContext;

// Core rendering interface
RenderContext* render_init(int width, int height);
void render_begin_frame(RenderContext* ctx);
void render_end_frame(RenderContext* ctx);
void render_cleanup(RenderContext* ctx);

// Data upload (one-time initialization)
void render_upload_shapes(RenderContext* ctx, void* data, size_t size);
void render_upload_transforms(RenderContext* ctx, void* data, size_t size);
void render_upload_colors(RenderContext* ctx, void* data, size_t size);
void render_upload_gradients(RenderContext* ctx, void* data, size_t size);

// Drawing operations (per-frame)
void render_draw_shape(RenderContext* ctx,
                       int shape_id,
                       int transform_id,
                       int color_id);

// Input handling
int render_poll_events(RenderContext* ctx);

#endif
```

#### Canvas2D Implementation

```c
// src/rendering/render_canvas2d.c
#ifdef __EMSCRIPTEN__

#include <emscripten.h>
#include <emscripten/html5.h>
#include "render_api.h"

typedef struct Canvas2DContext {
    int width;
    int height;

    // Cached data
    u32* shape_data;
    size_t shape_data_count;
    float* transform_data;
    size_t transform_count;
    float* color_data;
    size_t color_count;
} Canvas2DContext;

RenderContext* render_init(int width, int height) {
    RenderContext* ctx = malloc(sizeof(RenderContext));
    ctx->width = width;
    ctx->height = height;

    Canvas2DContext* canvas_ctx = malloc(sizeof(Canvas2DContext));
    canvas_ctx->width = width;
    canvas_ctx->height = height;
    ctx->backend_data = canvas_ctx;

    // Setup HTML canvas
    EM_ASM_({
        var canvas = document.getElementById('canvas');
        if (!canvas) {
            canvas = document.createElement('canvas');
            canvas.id = 'canvas';
            canvas.width = $0;
            canvas.height = $1;
            document.body.appendChild(canvas);
        }
    }, width, height);

    return ctx;
}

void render_upload_shapes(RenderContext* ctx, void* data, size_t size) {
    Canvas2DContext* canvas_ctx = (Canvas2DContext*)ctx->backend_data;

    // Copy shape data to WASM heap
    canvas_ctx->shape_data = malloc(size);
    memcpy(canvas_ctx->shape_data, data, size);
    canvas_ctx->shape_data_count = size / (4 * sizeof(u32)); // [x,y,z,w] per vertex
}

void render_upload_transforms(RenderContext* ctx, void* data, size_t size) {
    Canvas2DContext* canvas_ctx = (Canvas2DContext*)ctx->backend_data;

    canvas_ctx->transform_data = malloc(size);
    memcpy(canvas_ctx->transform_data, data, size);
    canvas_ctx->transform_count = size / (16 * sizeof(float)); // 4x4 matrix
}

void render_upload_colors(RenderContext* ctx, void* data, size_t size) {
    Canvas2DContext* canvas_ctx = (Canvas2DContext*)ctx->backend_data;

    canvas_ctx->color_data = malloc(size);
    memcpy(canvas_ctx->color_data, data, size);
    canvas_ctx->color_count = size / (4 * sizeof(float)); // RGBA
}

void render_begin_frame(RenderContext* ctx) {
    // Clear canvas
    EM_ASM({
        var canvas = document.getElementById('canvas');
        var context = canvas.getContext('2d');
        context.clearRect(0, 0, canvas.width, canvas.height);
    });
}

void render_draw_shape(RenderContext* ctx,
                       int shape_id,
                       int transform_id,
                       int color_id) {
    Canvas2DContext* canvas_ctx = (Canvas2DContext*)ctx->backend_data;

    // Get color
    float* color = &canvas_ctx->color_data[color_id * 4];
    int r = (int)(color[0] * 255);
    int g = (int)(color[1] * 255);
    int b = (int)(color[2] * 255);
    float a = color[3];

    // Get transform matrix (simplified - just translation for now)
    float* matrix = &canvas_ctx->transform_data[transform_id * 16];
    float tx = matrix[12];
    float ty = matrix[13];

    // Draw shape vertices as triangles
    // (simplified - assumes triangulated data)
    u32* vertices = &canvas_ctx->shape_data[shape_id * 4];

    EM_ASM_({
        var canvas = document.getElementById('canvas');
        var ctx = canvas.getContext('2d');

        ctx.fillStyle = 'rgba(' + $0 + ',' + $1 + ',' + $2 + ',' + $3 + ')';
        ctx.save();
        ctx.translate($4, $5);

        // Draw triangle (placeholder - would loop through all vertices)
        ctx.beginPath();
        ctx.moveTo(0, 0);
        ctx.lineTo(100, 0);
        ctx.lineTo(50, 100);
        ctx.closePath();
        ctx.fill();

        ctx.restore();
    }, r, g, b, a, tx, ty);
}

void render_end_frame(RenderContext* ctx) {
    // Canvas2D auto-presents
}

int render_poll_events(RenderContext* ctx) {
    // Return 0 to continue, 1 to quit
    // TODO: Hook up keyboard/mouse events
    return 0;
}

void render_cleanup(RenderContext* ctx) {
    Canvas2DContext* canvas_ctx = (Canvas2DContext*)ctx->backend_data;

    free(canvas_ctx->shape_data);
    free(canvas_ctx->transform_data);
    free(canvas_ctx->color_data);
    free(canvas_ctx);
    free(ctx);
}

#endif // __EMSCRIPTEN__
```

#### Native Adapter (Wrapper around existing flashbang)

```c
// src/rendering/render_native.c
#ifndef __EMSCRIPTEN__

#include "render_api.h"
#include <flashbang.h>

// This is just a thin wrapper around the existing flashbang code
// to match the new API

RenderContext* render_init(int width, int height) {
    RenderContext* ctx = malloc(sizeof(RenderContext));
    ctx->width = width;
    ctx->height = height;

    FlashbangContext* fb_ctx = flashbang_new();
    fb_ctx->width = width;
    fb_ctx->height = height;

    ctx->backend_data = fb_ctx;
    return ctx;
}

void render_upload_shapes(RenderContext* ctx, void* data, size_t size) {
    FlashbangContext* fb_ctx = (FlashbangContext*)ctx->backend_data;
    fb_ctx->shape_data = data;
    fb_ctx->shape_data_size = size;
}

// ... similar wrappers for other functions ...
// This allows native builds to continue using flashbang unchanged

#endif // !__EMSCRIPTEN__
```

### Integration with Runtime

Modify `src/libswf/swf.c` to use abstraction layer:

```c
// OLD CODE (native only):
#include <flashbang.h>
FlashbangContext* fb_ctx = flashbang_new();
flashbang_init(fb_ctx);

// NEW CODE (platform-agnostic):
#include <render_api.h>
RenderContext* render_ctx = render_init(width, height);
render_upload_shapes(render_ctx, shape_data, shape_data_size);
```

### Build Configuration

```cmake
# CMakeLists.txt additions
if(EMSCRIPTEN)
    message(STATUS "Building for WASM with Canvas2D")

    set(RENDER_SOURCES
        ${PROJECT_SOURCE_DIR}/src/rendering/render_canvas2d.c
    )

    set(CMAKE_EXECUTABLE_SUFFIX ".html")

    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "\
            -s WASM=1 \
            -s USE_SDL=0 \
            -s ALLOW_MEMORY_GROWTH=1 \
            -s EXPORTED_FUNCTIONS='[\"_main\"]' \
            -s EXPORTED_RUNTIME_METHODS='[\"cwrap\",\"ccall\"]' \
            --shell-file ${PROJECT_SOURCE_DIR}/src/rendering/shell.html \
        "
    )
else()
    message(STATUS "Building for native with SDL_GPU")

    set(RENDER_SOURCES
        ${PROJECT_SOURCE_DIR}/src/rendering/render_native.c
        ${PROJECT_SOURCE_DIR}/src/flashbang/flashbang.c
    )

    add_subdirectory(${PROJECT_SOURCE_DIR}/lib/SDL3)
    target_link_libraries(${PROJECT_NAME} PUBLIC SDL3::SDL3)
endif()

target_sources(${PROJECT_NAME} PRIVATE
    ${RENDER_SOURCES}
    ${PROJECT_SOURCE_DIR}/src/rendering/render_api.h
)
```

### Build Commands

```bash
# Native build (unchanged)
mkdir build-native
cd build-native
cmake ..
make

# WASM build (new)
mkdir build-wasm
cd build-wasm
emcmake cmake ..
emmake make

# Output: TestSWFRecompiled.html, .js, .wasm
```

### Testing

**Priority Test Cases (Currently Working Upstream):**
1. ✅ `mess` - Graphics test (confirmed working)
2. ✅ `wild_shadow` - Complex graphics (confirmed working)
3. ✅ `awful_gradient` - Linear gradient test (confirmed working)
4. ✅ `awful_radial_gradient` - Radial gradient test (confirmed working)

**Secondary Test Cases (May Need Updates):**
5. ⚠️ `trace_swf_4` - ActionScript test (may need runtime updates)
6. ⚠️ `two_squares` - Basic shapes (status unknown)
7. ⚠️ Other ActionScript tests (not yet updated for new runtime)

**Success Metrics (Updated):**
- Graphics tests: `mess`, `wild_shadow`, gradients render correctly in WASM
- Basic rendering visible for at least 3-4 working tests
- No regressions in native builds
- ⚠️ ActionScript test count TBD (test suite in flux)

### Deliverables

**Phase 1a (Complete):**
- [x] `wasm/examples/trace-swf-test/` - Working ActionScript example
- [x] `wasm/examples/trace-swf-test/runtime.c` - Basic runtime implementation
- [x] `wasm/examples/trace-swf-test/build.sh` - Build script
- [x] `wasm/shell-templates/` - HTML templates for hosting
- [x] `docs/` - GitHub Pages site with live demos
- [x] `README.md` - WASM build instructions

**Carried forward to Phase 2 (WebGPU):**
- [ ] `render_api.h` - Platform-agnostic rendering interface → **Phase 2**
- [ ] Graphics test examples (mess, wild_shadow) → **Phase 2**
- [ ] Performance benchmarks document → **Phase 2**

**Phase 1b (Skipped):**
- ~~`render_canvas2d.c` - Canvas2D backend~~ → **Skipped, proceeding to WebGPU**

---

## Phase 2: WebGPU Backend (SDL + Dawn/wgpu)

**Status:** Immediate Next Step (Phase 1b Canvas2D skipped)

**Priority:** High

**Goal:** GPU-accelerated rendering using WebGPU, for both browser (WASM) and native

### Rationale: Why WebGPU Instead of WebGL2

The original plan called for a WebGL2 backend as Phase 2. This has been revised to use
WebGPU directly, for several reasons:

1. **WebGPU is now universally supported in browsers:** Chrome (since 2023), Edge (since 2023),
   Firefox (since July 2025, FF 141), and Safari (since June 2025, Safari 26) all ship WebGPU
   in stable releases. The browser coverage concern that previously favored WebGL2 is resolved.

2. **Closer to existing Vulkan code:** The upstream flashbang.c renderer uses SDL_GPU/Vulkan
   with explicit command buffers, bind groups, and pipelines. WebGPU's API model is far closer
   to Vulkan than WebGL2 is, making the port more natural and less error-prone.

3. **Compute shader support:** The upstream runtime uses compute shaders for gradient matrix
   inversion. WebGL2 lacks compute shaders entirely, requiring CPU workarounds. WebGPU has
   full compute shader support, eliminating this gap.

4. **Single rendering backend for native + WASM:** By writing against the standardized
   `webgpu.h` C API, the same rendering code compiles for native (via Dawn or wgpu-native)
   and for browser (via emdawnwebgpu). WebGL2 would only work in the browser.

5. **Better path to Phase 3:** When SDL_GPU gains its WebGPU backend, the Phase 2 WebGPU
   code and WGSL shaders transfer directly, unlike WebGL2/GLSL ES 3.0 which would be thrown
   away.

### Ecosystem Overview

| Component | Role | Status |
|-----------|------|--------|
| **webgpu.h** | Standardized C header ([webgpu-native/webgpu-headers](https://github.com/webgpu-native/webgpu-headers)) | Stable |
| **Dawn** | Google's WebGPU impl (Chrome/Edge); recommended for debugging | Active, production |
| **wgpu-native** | Rust-based WebGPU impl (Firefox); pre-built binaries available | Active, not yet fully webgpu.h-conformant |
| **emdawnwebgpu** | Emscripten port for browser WebGPU ([built into Emscripten 4.0.10+](https://github.com/emscripten-core/emscripten/pull/24220)) | Official, maintained |
| **sdl3webgpu** | Bridge: SDL3 window → WGPUSurface ([eliemichel/sdl3webgpu](https://github.com/eliemichel/sdl3webgpu)) | Maintained, single .h/.c |
| **Naga** | SPIR-V/GLSL → WGSL shader translation ([gfx-rs/wgpu/naga](https://github.com/gfx-rs/wgpu/tree/trunk/naga)) | Active, fast |
| **Tint** | SPIR-V ↔ WGSL translation (C++, part of Dawn) | Active, thorough |

### Decision Point

**Evaluate before starting Phase 2:**
- ✅ Is Phase 1a working? → **Yes (WASM compilation + ActionScript VM proven)**
- ✅ Should we implement Canvas2D first? → **No (would be thrown away; skip to WebGPU)**
- ✅ Do you need GPU performance now? → **Yes, for feature parity**
- ✅ Are you willing to maintain shader code? → **Required for gradients/bitmaps**
- ✅ Is WebGPU browser support sufficient? → **Yes, all major browsers ship it**
- ✅ Is Emscripten WebGPU tooling mature? → **Yes, emdawnwebgpu in Emscripten 4.0.10+**

**Decision:** Proceed directly to Phase 2 — Phase 1b (Canvas2D) skipped

### Objectives

1. Implement WebGPU rendering backend using the standardized `webgpu.h` C API
2. Port shaders from SPIR-V/GLSL to WGSL
3. Achieve native-like rendering quality on both desktop and browser
4. Support gradients (linear + radial) and bitmaps via compute and fragment shaders
5. Use SDL3 for windowing on native (via sdl3webgpu), HTML canvas for browser

### Architecture

```c
// src/rendering/render_webgpu.c
#include <webgpu/webgpu.h>
#include "render_api.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#else
#include <SDL3/SDL.h>
#include "sdl3webgpu.h"
#endif

typedef struct WebGPUContext {
    WGPUInstance instance;
    WGPUAdapter adapter;
    WGPUDevice device;
    WGPUQueue queue;
    WGPUSurface surface;

    WGPURenderPipeline shape_pipeline;
    WGPUComputePipeline gradient_pipeline;

    WGPUBuffer vertex_buffer;
    WGPUBuffer transform_buffer;
    WGPUBuffer color_buffer;

    // Cached data
    void* shape_data;
    size_t shape_data_size;
} WebGPUContext;

RenderContext* render_init(int width, int height) {
    WebGPUContext* ctx = calloc(1, sizeof(WebGPUContext));

    // Create WebGPU instance
    WGPUInstanceDescriptor desc = { .nextInChain = NULL };
    ctx->instance = wgpuCreateInstance(&desc);

    // Create surface (platform-specific)
#ifdef __EMSCRIPTEN__
    WGPUSurfaceDescriptorFromCanvasHTMLSelector canvasDesc = {
        .chain = { .sType = WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector },
        .selector = "#canvas"
    };
    WGPUSurfaceDescriptor surfDesc = {
        .nextInChain = (WGPUChainedStruct*)&canvasDesc
    };
    ctx->surface = wgpuInstanceCreateSurface(ctx->instance, &surfDesc);
#else
    // Native: use sdl3webgpu bridge
    ctx->surface = SDL_GetWGPUSurface(ctx->instance, sdl_window);
#endif

    // Request adapter, device, queue...
    // Create pipelines, buffers...

    return (RenderContext*)ctx;
}

// ... rest of WebGPU implementation
```

### Shader Porting (WGSL)

WebGPU mandates WGSL as the only shading language in browsers. Native implementations
(Dawn, wgpu) optionally accept SPIR-V, but for cross-platform consistency we target WGSL.

**Conversion pipeline for existing shaders:**
```
GLSL (source) → glslangValidator/Shaderc → SPIR-V → naga-cli or Tint → WGSL
```

Install naga-cli: `cargo install naga-cli`
Convert: `naga input.spv output.wgsl`

**Vertex Shader (WGSL):**
```wgsl
// shaders/webgpu/vertex.wgsl
struct VertexInput {
    @location(0) position: vec4<f32>,
};

struct VertexOutput {
    @builtin(position) position: vec4<f32>,
};

@group(0) @binding(0) var<uniform> transform: mat4x4<f32>;
@group(0) @binding(1) var<uniform> stage_to_ndc: mat4x4<f32>;

@vertex
fn vs_main(in: VertexInput) -> VertexOutput {
    var out: VertexOutput;
    out.position = stage_to_ndc * transform * in.position;
    return out;
}
```

**Fragment Shader (WGSL):**
```wgsl
// shaders/webgpu/fragment.wgsl
@group(1) @binding(0) var<uniform> color: vec4<f32>;

@fragment
fn fs_main() -> @location(0) vec4<f32> {
    return color;
}
```

### Build Configuration

```cmake
option(USE_WEBGPU "Use WebGPU rendering backend" OFF)

if(USE_WEBGPU)
    if(EMSCRIPTEN)
        # Browser: use emdawnwebgpu port (requires Emscripten 4.0.10+)
        message(STATUS "Building for WASM with WebGPU (emdawnwebgpu)")
        set(RENDER_SOURCES ${PROJECT_SOURCE_DIR}/src/rendering/render_webgpu.c)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --use-port=emdawnwebgpu")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --use-port=emdawnwebgpu -sASYNCIFY=1")
    else()
        # Native: use SDL3 + sdl3webgpu + Dawn or wgpu-native
        message(STATUS "Building for native with WebGPU")
        set(RENDER_SOURCES
            ${PROJECT_SOURCE_DIR}/src/rendering/render_webgpu.c
            ${PROJECT_SOURCE_DIR}/lib/sdl3webgpu/sdl3webgpu.c
        )
        # Link against Dawn or wgpu-native (set WEBGPU_BACKEND at configure time)
        target_link_libraries(${PROJECT_NAME} PRIVATE webgpu)
    endif()
elseif(EMSCRIPTEN)
    message(STATUS "Building for WASM with Canvas2D")
    set(RENDER_SOURCES ${PROJECT_SOURCE_DIR}/src/rendering/render_canvas2d.c)
else()
    message(STATUS "Building for native with SDL_GPU (Vulkan)")
    set(RENDER_SOURCES ${PROJECT_SOURCE_DIR}/src/flashbang/flashbang.c)
endif()
```

### Surface Creation: Native vs Browser

| Platform | Surface Source | Library |
|----------|--------------|---------|
| **Linux (X11)** | `SDL_PROP_WINDOW_X11_DISPLAY_POINTER` + window number | sdl3webgpu |
| **Linux (Wayland)** | `SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER` + surface ptr | sdl3webgpu |
| **Windows** | HWND + HINSTANCE from SDL properties | sdl3webgpu |
| **macOS** | `NSWindow` → `CAMetalLayer` via SDL properties | sdl3webgpu (compile as ObjC) |
| **Browser (WASM)** | `WGPUSurfaceDescriptorFromCanvasHTMLSelector("#canvas")` | emdawnwebgpu |

### Deliverables

- [ ] `render_webgpu.c` — WebGPU backend (shared native + WASM code)
- [ ] WGSL shaders (vertex, fragment, compute for gradients)
- [ ] Shader conversion pipeline (SPIR-V → WGSL via naga-cli)
- [ ] sdl3webgpu integration for native builds
- [ ] emdawnwebgpu integration for WASM builds
- [ ] Performance benchmarks (native + browser)
- [ ] Documentation

### Performance Targets

- 60 FPS for simple games (native and browser)
- 30 FPS for complex games (browser)
- Sub-1MB WASM binary size (rendering code; emdawnwebgpu JS glue adds ~50-100KB)

---

## Phase 3: SDL_GPU WebGPU Migration

**Timeline:** TBD (waiting on SDL_GPU WebGPU backend)

**Status:** Future (monitoring)

**Priority:** High (when available)

**Goal:** Migrate from Phase 2's direct `webgpu.h` rendering to SDL_GPU's WebGPU backend,
unifying the native and WASM renderers into the single upstream `flashbang.c`

### Context: Relationship to Phase 2

Phase 2 provides a working WebGPU renderer that writes directly against `webgpu.h`. This
requires maintaining a separate `render_webgpu.c` alongside the native `flashbang.c`. Phase 3
eliminates this split: when SDL_GPU gains a WebGPU backend, `flashbang.c` (which already uses
SDL_GPU) would work unmodified for WASM — no custom rendering code needed.

**Key advantage of the Phase 2 → Phase 3 path:** The WGSL shaders written in Phase 2
transfer directly to Phase 3, and the team gains WebGPU API experience. If Phase 3 never
materializes, Phase 2 is a fully viable long-term solution.

### Monitoring SDL_GPU Progress

**Resources to watch:**
- SDL3 GitHub: https://github.com/libsdl-org/SDL/projects
- SDL_GPU WebGPU backend feature request: https://github.com/libsdl-org/SDL/issues/10768
- SDL_GPU documentation: https://wiki.libsdl.org/SDL3/CategoryGPU
- Emscripten SDL3 support status

**Key milestones to track:**
- ✅ SDL_GPU API stabilization
- ✅ Browser WebGPU availability (Chrome, Firefox, Safari, Edge — all ship it)
- ⏳ Emscripten SDL3 support
- ⏳ SDL_GPU WebGPU backend implementation

### Migration Strategy

**When SDL_GPU's WebGPU backend is ready:**

1. **Test upstream runtime with Emscripten**
   ```bash
   emcmake cmake -DCMAKE_BUILD_TYPE=Release ..
   emmake make
   ```

2. **Verify compatibility**
   - Does flashbang.c compile with Emscripten?
   - Does SDL_GPU map to WebGPU correctly?
   - Do shaders compile (SPIR-V → WGSL via SDL_GPU's internal pipeline)?

3. **Deprecate Phase 2 custom backend**
   - Keep Canvas2D as minimal fallback
   - Deprecate `render_webgpu.c` (Phase 2 custom code)
   - Use native `flashbang.c` for both native and WASM

4. **Build configuration**
   ```cmake
   if(EMSCRIPTEN)
       # Same sources as native!
       set(RENDER_SOURCES
           ${PROJECT_SOURCE_DIR}/src/flashbang/flashbang.c
       )
       set_target_properties(${PROJECT_NAME} PROPERTIES
           LINK_FLAGS "-s USE_SDL=3 -s USE_WEBGPU=1"
       )
   endif()
   ```

### Expected Benefits

- ✅ **Zero maintenance:** Same code as upstream `flashbang.c`
- ✅ **Automatic updates:** Benefit from upstream improvements
- ✅ **Full features:** All native features available in WASM
- ✅ **Performance:** Native-like GPU acceleration
- ✅ **Simplified build:** No separate rendering backends to maintain

### Deliverables

- [ ] SDL_GPU WebGPU compatibility test
- [ ] Migration guide (Phase 2 → Phase 3)
- [ ] Updated build system
- [ ] Deprecation plan for `render_webgpu.c`
- [ ] Performance comparison (Phase 2 WebGPU vs Phase 3 SDL_GPU WebGPU)

---

## Maintaining Native Runtime Compatibility

### Core Principle

**Native builds must remain 100% unaffected by WASM changes.**

### Implementation Strategy

#### 1. Preprocessor Guards

```c
// GOOD: Platform-specific code clearly marked
#ifdef __EMSCRIPTEN__
    // WASM-specific code
    #include <emscripten.h>
    void wasm_function() { ... }
#else
    // Native code
    void native_function() { ... }
#endif

// BAD: Mixing platform code
void mixed_function() {
    if (is_wasm) { ... }  // Runtime check - adds overhead to native
}
```

#### 2. File Separation

```
src/rendering/
├── render_api.h          # Shared interface
├── render_native.c       # Native only (#ifndef __EMSCRIPTEN__ && !USE_WEBGPU)
├── render_canvas2d.c     # WASM fallback (#ifdef __EMSCRIPTEN__ && !USE_WEBGPU)
└── render_webgpu.c       # WebGPU backend (#ifdef USE_WEBGPU — native + WASM)
```

#### 3. Build System Isolation

```cmake
# Native build MUST NOT be affected by WASM options
if(NOT EMSCRIPTEN)
    # Native build - unchanged from upstream
    add_subdirectory(lib/SDL3)
    target_link_libraries(${PROJECT_NAME} SDL3::SDL3)
    # ... existing configuration ...
endif()

# WASM build - completely separate
if(EMSCRIPTEN)
    # WASM-specific configuration
    # ... WASM options ...
endif()
```

#### 4. Test Coverage

**Before every commit:**

```bash
# Test native build
mkdir build-native && cd build-native
cmake .. && make
./TestSWFRecompiled
cd ..

# Test WASM build
mkdir build-wasm && cd build-wasm
emcmake cmake .. && emmake make
# Open .html in browser
cd ..
```

### Continuous Integration

**GitHub Actions workflow:**

```yaml
# .github/workflows/ci.yml
name: CI

on: [push, pull_request]

jobs:
  native-build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
        with:
          submodules: recursive
      - name: Build native
        run: |
          mkdir build && cd build
          cmake ..
          make -j$(nproc)
      - name: Run tests
        run: |
          cd build
          ctest --output-on-failure

  wasm-build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
        with:
          submodules: recursive
      - uses: mymindstorm/setup-emsdk@v11
      - name: Build WASM
        run: |
          mkdir build-wasm && cd build-wasm
          emcmake cmake ..
          emmake make
      - name: Upload artifacts
        uses: actions/upload-artifact@v3
        with:
          name: wasm-build
          path: build-wasm/*.{html,js,wasm}
```

---

## Build System Design

### Directory Structure

```
SWFRecomp/
├── SWFRecomp/                  # Unchanged - recompiler tool (native only)
│   ├── src/
│   ├── CMakeLists.txt
│   └── build/
│
└── SWFModernRuntime/           # Modified - add WASM support
    ├── src/
    │   ├── libswf/             ✅ WASM-compatible (no changes)
    │   ├── actionmodern/       ✅ WASM-compatible (no changes)
    │   ├── flashbang/          ⚠️ Native only
    │   │   └── flashbang.c
    │   └── rendering/          🆕 NEW - abstraction layer
    │       ├── render_api.h
    │       ├── render_native.c
    │       ├── render_canvas2d.c
    │       └── render_webgpu.c   # WebGPU backend (native + WASM)
    ├── shaders/
    │   ├── spirv/              # Native shaders (Vulkan)
    │   └── wgsl/               # WebGPU shaders (Phase 2)
    ├── web/                    🆕 NEW
    │   ├── shell.html          # HTML template
    │   └── style.css           # Styling
    ├── CMakeLists.txt          ⚠️ Modified
    ├── build-native/           # Native builds
    └── build-wasm/             # WASM builds
```

### CMake Organization

```cmake
# SWFModernRuntime/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(SWFModernRuntime)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ============================================================================
# Core sources (platform-agnostic)
# ============================================================================
set(CORE_SOURCES
    ${PROJECT_SOURCE_DIR}/src/libswf/swf.c
    ${PROJECT_SOURCE_DIR}/src/libswf/tag.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/action.c
    ${PROJECT_SOURCE_DIR}/src/actionmodern/variables.c
    ${PROJECT_SOURCE_DIR}/src/utils.c
    ${PROJECT_SOURCE_DIR}/lib/c-hashmap/map.c
)

# ============================================================================
# Platform-specific rendering backend
# ============================================================================
if(EMSCRIPTEN)
    message(STATUS "=== Building for WebAssembly ===")

    # WASM rendering options
    option(USE_WEBGPU "Use WebGPU instead of Canvas2D" OFF)

    if(USE_WEBGPU)
        message(STATUS "Rendering backend: WebGPU (emdawnwebgpu)")
        set(RENDER_SOURCES ${PROJECT_SOURCE_DIR}/src/rendering/render_webgpu.c)
        set(RENDER_FLAGS "--use-port=emdawnwebgpu -sASYNCIFY=1")
    else()
        message(STATUS "Rendering backend: Canvas2D")
        set(RENDER_SOURCES ${PROJECT_SOURCE_DIR}/src/rendering/render_canvas2d.c)
        set(RENDER_FLAGS "")
    endif()

    set(SOURCES ${CORE_SOURCES} ${RENDER_SOURCES})

    # WASM-specific build flags
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    set(EMSCRIPTEN_LINK_FLAGS "\
        -s WASM=1 \
        -s ALLOW_MEMORY_GROWTH=1 \
        -s EXPORTED_FUNCTIONS='[\"_main\"]' \
        -s EXPORTED_RUNTIME_METHODS='[\"cwrap\",\"ccall\"]' \
        -s MODULARIZE=1 \
        -s EXPORT_NAME='SWFRecompiledModule' \
        --shell-file ${PROJECT_SOURCE_DIR}/web/shell.html \
        ${RENDER_FLAGS} \
    ")

else()
    message(STATUS "=== Building for Native ===")
    message(STATUS "Rendering backend: SDL_GPU (Vulkan/Metal/D3D12)")

    # Native rendering (unchanged from upstream)
    set(RENDER_SOURCES
        ${PROJECT_SOURCE_DIR}/src/rendering/render_native.c
        ${PROJECT_SOURCE_DIR}/src/flashbang/flashbang.c
    )

    set(SOURCES ${CORE_SOURCES} ${RENDER_SOURCES})

    # Native dependencies (unchanged)
    add_subdirectory(${PROJECT_SOURCE_DIR}/lib/zlib)
    add_subdirectory(${PROJECT_SOURCE_DIR}/lib/lzma)
    add_subdirectory(${PROJECT_SOURCE_DIR}/lib/SDL3)

endif()

# ============================================================================
# Target configuration
# ============================================================================
add_library(${PROJECT_NAME} STATIC ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/actionmodern
    ${PROJECT_SOURCE_DIR}/include/libswf
    ${PROJECT_SOURCE_DIR}/include/flashbang
    ${PROJECT_SOURCE_DIR}/include/rendering
    ${PROJECT_SOURCE_DIR}/lib/c-hashmap
)

if(NOT EMSCRIPTEN)
    # Native-only includes
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/lib/SDL3/include
        zlib
        lzma/liblzma/api
    )

    # Native-only linking
    target_link_libraries(${PROJECT_NAME} PUBLIC
        zlibstatic
        lzma
        SDL3::SDL3
    )
endif()

# Platform-specific compiler options
if(EMSCRIPTEN)
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wno-format-truncation
    )
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "${EMSCRIPTEN_LINK_FLAGS}"
    )
else()
    if(WIN32)
        target_compile_options(${PROJECT_NAME} PRIVATE)
    else()
        target_compile_options(${PROJECT_NAME} PRIVATE -Wno-format-truncation)
    endif()
endif()

# ============================================================================
# Installation (native only)
# ============================================================================
if(NOT EMSCRIPTEN)
    set(CMAKE_SKIP_BUILD_RPATH FALSE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH "$\{ORIGIN\}")
endif()
```

### Build Scripts

Create helper scripts for common build tasks:

```bash
# scripts/build-native.sh
#!/bin/bash
set -e

echo "=== Building Native Runtime ==="

mkdir -p build-native
cd build-native

cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc)

echo "✓ Native build complete: build-native/libSWFModernRuntime.a"
```

```bash
# scripts/build-wasm.sh
#!/bin/bash
set -e

echo "=== Building WASM Runtime ==="

# Check if Emscripten is available
if ! command -v emcc &> /dev/null; then
    echo "Error: Emscripten not found. Please install and activate emsdk."
    exit 1
fi

mkdir -p build-wasm
cd build-wasm

# Option: USE_WEBGPU=ON for WebGPU, OFF for Canvas2D
emcmake cmake -DCMAKE_BUILD_TYPE=Release -DUSE_WEBGPU=OFF ..
emmake make

echo "✓ WASM build complete:"
echo "  - build-wasm/TestSWFRecompiled.html"
echo "  - build-wasm/TestSWFRecompiled.js"
echo "  - build-wasm/TestSWFRecompiled.wasm"
echo ""
echo "To test: python3 -m http.server -d build-wasm 8000"
echo "Then open: http://localhost:8000/TestSWFRecompiled.html"
```

```bash
# scripts/test-both.sh
#!/bin/bash
set -e

echo "=== Testing Both Platforms ==="

# Build native
./scripts/build-native.sh

# Build WASM
./scripts/build-wasm.sh

# Run native tests
echo ""
echo "=== Running Native Tests ==="
cd build-native
ctest --output-on-failure
cd ..

# Instructions for WASM tests
echo ""
echo "=== WASM Tests (Manual) ==="
echo "To test WASM build:"
echo "  1. cd build-wasm"
echo "  2. python3 -m http.server 8000"
echo "  3. Open http://localhost:8000/TestSWFRecompiled.html"
echo "  4. Check browser console for output"
```

### Test Infrastructure

```cmake
# tests/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

# Common for both platforms
set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/RecompiledTags/tagMain.c
    ${CMAKE_CURRENT_SOURCE_DIR}/RecompiledTags/constants.c
    ${CMAKE_CURRENT_SOURCE_DIR}/RecompiledTags/draws.c
)

# Link against runtime
add_executable(TestSWFRecompiled ${TEST_SOURCES})
target_link_libraries(TestSWFRecompiled SWFModernRuntime)
target_include_directories(TestSWFRecompiled PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/RecompiledTags
)

if(NOT EMSCRIPTEN)
    # Native: Add to CTest
    enable_testing()
    add_test(NAME two_squares COMMAND TestSWFRecompiled)
endif()
```

---

## Testing Strategy

### Test Matrix

| Test Type | Native Build | WASM Canvas2D | WASM WebGPU (Phase 2) | SDL_GPU WebGPU (Phase 3) |
|-----------|--------------|---------------|----------------------|--------------------------|
| **Compilation** | ✅ Required | ✅ Required | ⏳ Phase 2 | ⏳ Phase 3 |
| **ActionScript Tests (50)** | ✅ All pass | ✅ All pass | ✅ All pass | ✅ All pass |
| **Graphics Tests (14)** | ✅ All pass | ⚠️ Basic | ✅ All pass | ✅ All pass |
| **Performance** | ✅ Baseline | ⚠️ Slow | ✅ Good | ✅ Excellent |

### Test Cases

#### 1. Compilation Tests

```bash
# Native
cd build-native && cmake .. && make
# Expected: Clean compile, no warnings

# WASM Canvas2D
cd build-wasm && emcmake cmake -DUSE_WEBGPU=OFF .. && emmake make
# Expected: Clean compile, WASM binary generated

# WASM WebGPU (Phase 2)
cd build-wasm && emcmake cmake -DUSE_WEBGPU=ON .. && emmake make
# Expected: Clean compile, WGSL shaders bundled, emdawnwebgpu linked
```

#### 2. ActionScript Tests

**Test:** `trace_swf_4`

```bash
# Native
./build-native/TestSWFRecompiled
# Expected stdout: "sup from SWF 4"

# WASM
# Open TestSWFRecompiled.html in browser
# Check console: "sup from SWF 4"
```

**Coverage:** All 50 ActionScript tests must produce identical output in native and WASM.

#### 3. Graphics Tests

**Test:** `two_squares`

**Native:**
- Window opens
- Two colored squares visible
- Correct colors (red, green)
- Correct positions

**WASM Canvas2D (Phase 1):**
- Canvas appears
- ⚠️ Squares may be simplified/approximate
- Colors roughly correct
- Positions roughly correct

**WASM WebGPU (Phase 2):**
- Canvas appears
- Pixel-perfect rendering
- Matches native output
- Smooth animation

#### 4. Performance Benchmarks

**Test:** `speed_test_swf_4` (if exists) or create benchmark

| Platform | Frame Time | FPS | Notes |
|----------|-----------|-----|-------|
| Native (SDL_GPU/Vulkan) | 1-2ms | 500+ | Baseline |
| WASM Canvas2D | 20-50ms | 20-50 | CPU limited |
| WASM WebGPU (Phase 2) | 2-5ms | 200+ | GPU accelerated |
| WASM SDL_GPU WebGPU (Phase 3) | 1-3ms | 300+ | Native-like |

#### 5. Regression Testing

**Before every merge to main:**

```bash
# Run full test suite on both platforms
./scripts/test-both.sh

# Check for:
# - Native build still works (no regressions)
# - WASM build compiles
# - ActionScript tests pass on both
# - Graphics rendering works on both
```

### Automated Testing

**GitHub Actions:**
- Run on every push/PR
- Test both native and WASM builds
- Generate screenshots for visual comparison
- Upload WASM build as artifact for manual testing

### Manual Testing Checklist

**Before releasing:**

- [ ] Native build compiles cleanly
- [ ] WASM build compiles cleanly
- [ ] All 50 ActionScript tests pass (native)
- [ ] All 50 ActionScript tests pass (WASM - check browser console)
- [ ] Basic graphics render (two_squares)
- [ ] No console errors in browser
- [ ] File size reasonable (<2MB for WASM binary)
- [ ] Load time acceptable (<3 seconds on fast connection)

---

## Upstream Sync Strategy

### Tracking Upstream

**Git remotes:**
```bash
# Add upstream
git remote add upstream-swfrecomp https://github.com/SWFRecomp/SWFRecomp.git
git remote add upstream-runtime https://github.com/SWFRecomp/SWFModernRuntime.git

# Fetch updates
git fetch upstream-swfrecomp
git fetch upstream-runtime
```

### Merge Strategy

**Weekly sync:**
```bash
# Check for upstream changes
git fetch upstream-runtime

# Merge into your wasm-support branch
git checkout wasm-support
git merge upstream-runtime/master

# Resolve conflicts (if any)
# Priority: Keep WASM compatibility while adopting upstream improvements
```

### Conflict Resolution Guidelines

**Common conflict scenarios:**

1. **Upstream modifies flashbang.c:**
   - ✅ Keep upstream changes in `flashbang.c`
   - ✅ Update `render_native.c` wrapper if needed
   - ❌ Don't modify upstream `flashbang.c`

2. **Upstream modifies swf.c:**
   - ✅ Adopt upstream changes
   - ✅ Update render API calls if needed
   - ⚠️ Test both native and WASM builds

3. **Upstream adds new dependencies:**
   - ✅ Check if dependency works with Emscripten
   - ✅ Add preprocessor guards if needed
   - ⚠️ May need WASM alternative

### Contributing Back Upstream

**Candidates for upstream PRs:**

✅ **Submit upstream:**
- Bug fixes in core runtime
- Performance improvements (platform-agnostic)
- Documentation improvements
- Test cases

❌ **Keep in fork:**
- WASM-specific code (unless requested)
- Rendering abstraction layer
- Emscripten build configuration
- Canvas2D/WebGPU rendering backends

---

## Timeline & Milestones

### Phase 1: Canvas2D Prototype

**Setup & Abstraction**
- [ ] Fork repositories, set up build environment
- [ ] Create rendering abstraction layer (`render_api.h`)
- [ ] Implement `render_native.c` wrapper

**WASM Implementation**
- [ ] Implement `render_canvas2d.c`
- [ ] Configure Emscripten build system
- [ ] Test compilation, fix errors

**Testing & Refinement**
- [ ] Test `trace_swf_4` (ActionScript)
- [ ] Test `two_squares` (graphics)
- [ ] Fix rendering issues
- [ ] Documentation

**Milestone 1:** ✅ WASM builds compile and run basic tests

---

### Phase 2: WebGPU Backend (SDL + Dawn/wgpu)

**Decision:** Proceed immediately (Phase 1b Canvas2D skipped)

**WebGPU Setup**
- [ ] Integrate sdl3webgpu for native surface creation
- [ ] Configure emdawnwebgpu for WASM builds (Emscripten 4.0.10+)
- [ ] WebGPU device/adapter/queue initialization
- [ ] Buffer management (vertex, transform, color)
- [ ] Basic render pipeline creation

**Shader Porting (SPIR-V/GLSL → WGSL)**
- [ ] Install naga-cli (`cargo install naga-cli`)
- [ ] Convert vertex shaders to WGSL
- [ ] Convert fragment shaders to WGSL
- [ ] Convert compute shaders (gradients) to WGSL
- [ ] Shader loading and compilation system

**Features**
- [ ] Solid fills
- [ ] Gradients (linear + radial) via compute shaders
- [ ] Bitmaps/textures
- [ ] Matrix transforms

**Testing & Optimization**
- [ ] All graphics tests (native + browser)
- [ ] Performance profiling
- [ ] Bundle size optimization

**Milestone 2:** ✅ GPU-accelerated rendering on native and WASM via WebGPU

---

### Phase 3: SDL_GPU WebGPU Migration

**Timeline:** TBD (dependent on SDL_GPU WebGPU backend)

**Monitoring Phase (ongoing):**
- [ ] Monthly check: SDL_GPU WebGPU backend status (https://github.com/libsdl-org/SDL/issues/10768)
- [ ] Test Emscripten + SDL3 compatibility
- [ ] Follow SDL development blog/GitHub

**Migration Phase (when ready):**
- [ ] Test upstream flashbang.c with Emscripten + SDL_GPU WebGPU
- [ ] Migrate build system
- [ ] Deprecate Phase 2 custom `render_webgpu.c`
- [ ] Testing, validation, and documentation

**Milestone 3:** ✅ Using upstream `flashbang.c` for both native and WASM

---

## Risk Management

### Technical Risks

#### Risk 1: Emscripten Compatibility Issues
**Probability:** Medium

**Impact:** High

**Mitigation:**
- Test early and often
- Use stable Emscripten version
- Avoid bleeding-edge features
- Have fallback to Canvas2D

#### Risk 2: SDL_GPU WebGPU Backend Delayed
**Probability:** High

**Impact:** Low (reduced from Medium — Phase 2 is now a full WebGPU solution)

**Mitigation:**
- ✅ Phase 2 provides full GPU-accelerated WebGPU rendering without SDL_GPU
- ✅ Phase 2 works for both native (via Dawn/wgpu-native) and WASM (via emdawnwebgpu)
- ✅ No hard dependency on SDL_GPU timeline — Phase 2 is viable long-term
- ⏳ Monitor SDL_GPU WebGPU backend: https://github.com/libsdl-org/SDL/issues/10768

#### Risk 3: Upstream Breaking Changes
**Probability:** High (active development)

**Impact:** Medium

**Mitigation:**
- Weekly upstream syncs
- Good abstraction layer
- Comprehensive test suite

#### Risk 4: Performance Issues
**Probability:** Medium

**Impact:** Medium

**Mitigation:**
- Phase 1: Accept poor performance (proof of concept)
- Phase 2: GPU acceleration solves most issues
- Profile and optimize hot paths
- Consider WebAssembly SIMD if needed

#### Risk 5: Browser Compatibility
**Probability:** Low

**Impact:** Low

**Mitigation:**
- Target modern browsers (last 2 years)
- WebGPU now supported in all major browsers: Chrome 113+, Edge 113+, Firefox 141+, Safari 26+
- Canvas2D (Phase 1) available as fallback for older browsers
- Feature detection: check `navigator.gpu` before initializing WebGPU
- Document minimum browser versions

### Project Risks

#### Risk 1: Scope Creep
**Probability:** Medium

**Impact:** Medium

**Mitigation:**
- Clear phase boundaries
- Stick to plan
- Phase 1 is minimal viable product
- Phase 2 is focused: one renderer (WebGPU) for native + WASM, not two separate backends

#### Risk 2: Maintenance Burden
**Probability:** High

**Impact:** High

**Mitigation:**
- ✅ Minimize custom code (rendering backends only)
- ✅ Automate testing (CI/CD)
- ✅ Good documentation
- ✅ Phase 2 WebGPU backend works for both native + WASM (single codebase)
- ✅ Plan for Phase 3 migration (reduce to zero custom rendering code)

#### Risk 3: Upstream Divergence
**Probability:** Medium

**Impact:** High

**Mitigation:**
- Regular syncs
- Clean abstraction prevents conflicts
- Be prepared to abandon fork if necessary

### Contingency Plans

**If Phase 1 fails:**
- Reassess Emscripten compatibility
- Consider alternative: asm.js fallback
- Consider alternative: Wait for SDL3 only

**If Phase 2 WebGPU is too complex:**
- Fall back to WebGL2 as a simpler alternative (less Vulkan-like but well-documented)
- Use Canvas2D as interim solution
- Focus on non-graphics features until WebGPU tooling matures further

**If SDL_GPU WebGPU backend never materializes:**
- Maintain Phase 2 `render_webgpu.c` long-term (viable — it works for native + WASM)
- Consider contributing WebGPU backend to SDL3
- Accept maintenance burden of separate rendering backend

**If upstream rejects fork concept:**
- Continue as independent project
- Manual upstream merges
- Fork becomes permanent

---

## Success Metrics

### Technical Metrics

**Phase 1 Success:**
- [ ] Native build: 100% tests pass (no regressions)
- [ ] WASM build: Compiles without errors
- [ ] WASM build: 50/50 ActionScript tests pass
- [ ] WASM build: Basic rendering visible
- [ ] Bundle size: <5MB total (HTML + JS + WASM)

**Phase 2 Success (if pursued):**
- [ ] WASM build: 14/14 graphics tests pass
- [ ] WASM build: Rendering matches native (visual comparison)
- [ ] Performance: >30 FPS for test games
- [ ] Bundle size: <2MB total

**Phase 3 Success:**
- [ ] Using upstream runtime unmodified
- [ ] Zero custom rendering code
- [ ] Native and WASM builds identical source
- [ ] Performance: Native-like

### Project Metrics

- [ ] Documentation complete and up-to-date
- [ ] CI/CD pipeline functional
- [ ] At least 1 complete game ported to WASM
- [ ] Positive feedback from community
- [ ] No negative impact on upstream project

---

## Next Steps

### Immediate Actions

1. **Environment Setup**
   ```bash
   # Fork repositories
   # Install Emscripten
   # Set up git remotes
   # Create wasm-support branch
   ```

2. **Create Abstraction Layer**
   ```bash
   # Create src/rendering/ directory
   # Write render_api.h
   # Implement render_native.c wrapper
   # Test native build still works
   ```

3. **Implement Canvas2D**
   ```bash
   # Write render_canvas2d.c
   # Create web/shell.html template
   # Test basic Emscripten compilation
   ```

4. **First WASM Build**
   ```bash
   # Configure CMakeLists.txt for WASM
   # Attempt full build
   # Fix compilation errors
   # Get *something* running in browser
   ```

### Decision Points

- ✅ Does abstraction layer work?
- ✅ Does native build still work?
- ✅ Is approach viable?

- ✅ Does WASM compile?
- ✅ Does Canvas2D render anything?
- ✅ Continue?

- ✅ Is Canvas2D good enough?
- ✅ Proceed to Phase 2 or wait for SDL3?

---

## Appendix A: Technology Reference

### Emscripten

**Version:** Latest stable (3.1.x as of Oct 2025)

**Documentation:** https://emscripten.org/docs/

**Installation:**
```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

### WebGPU

**Browser Support:** Chrome 113+, Edge 113+, Firefox 141+, Safari 26+ (all major browsers)

**Specification:** https://gpuweb.github.io/gpuweb/

**WGSL Specification:** https://gpuweb.github.io/gpuweb/wgsl.html

**Status:** https://caniuse.com/webgpu

**C Header (webgpu.h):** https://github.com/webgpu-native/webgpu-headers

### WebGPU Implementations

**Dawn (Google):** https://dawn.googlesource.com/dawn (GitHub mirror: https://github.com/google/dawn)
- Chrome/Edge WebGPU backend; excellent debug output
- Emscripten integration: emdawnwebgpu (built into Emscripten 4.0.10+)

**wgpu-native (Mozilla/gfx-rs):** https://github.com/gfx-rs/wgpu-native
- Firefox WebGPU backend; pre-built binaries available
- Note: not yet fully conformant with stable webgpu.h

### WebGPU Tooling

**sdl3webgpu:** https://github.com/eliemichel/sdl3webgpu
- Bridge: SDL3 window → WGPUSurface (one .h/.c file)

**Naga (shader compiler):** https://github.com/gfx-rs/wgpu/tree/trunk/naga
- SPIR-V/GLSL → WGSL conversion; install: `cargo install naga-cli`

**Tint (shader compiler):** Part of Dawn
- SPIR-V ↔ WGSL conversion; build via depot_tools

### SDL3

**Repository:** https://github.com/libsdl-org/SDL

**SDL_GPU Documentation:** https://wiki.libsdl.org/SDL3/CategoryGPU

**SDL_GPU WebGPU Backend:** https://github.com/libsdl-org/SDL/issues/10768 (planned, not yet available)

**Emscripten Support:** https://wiki.libsdl.org/SDL3/README/emscripten

### WebGL2 (Fallback Reference)

**Browser Support:** All modern browsers (2020+)

**Reference:** https://developer.mozilla.org/en-US/docs/Web/API/WebGL_API

**Note:** WebGL2 was the original Phase 2 plan. It remains a viable fallback if WebGPU
proves impractical, but lacks compute shaders and is less aligned with the Vulkan-based
upstream renderer.

---

## Appendix B: File Templates

### shell.html Template

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>SWF Recompiled</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            background: #1a1a1a;
            font-family: sans-serif;
            color: #fff;
        }
        #container {
            text-align: center;
        }
        #canvas {
            border: 2px solid #333;
            background: #000;
            image-rendering: pixelated;
            image-rendering: crisp-edges;
        }
        #status {
            margin-top: 1em;
            font-size: 0.9em;
            color: #888;
        }
        #output {
            margin-top: 1em;
            padding: 1em;
            background: #000;
            border: 1px solid #333;
            text-align: left;
            font-family: monospace;
            font-size: 0.8em;
            max-height: 200px;
            overflow-y: auto;
        }
    </style>
</head>
<body>
    <div id="container">
        <h1>SWF Recompiled to WASM</h1>
        <canvas id="canvas"></canvas>
        <div id="status">Loading...</div>
        <div id="output"></div>
    </div>

    <script>
        var Module = {
            preRun: [],
            postRun: [],
            print: function(text) {
                console.log(text);
                var output = document.getElementById('output');
                output.innerHTML += text + '\n';
                output.scrollTop = output.scrollHeight;
            },
            printErr: function(text) {
                console.error(text);
                var output = document.getElementById('output');
                output.innerHTML += '<span style="color: #f88">' + text + '</span>\n';
                output.scrollTop = output.scrollHeight;
            },
            setStatus: function(text) {
                document.getElementById('status').textContent = text;
            },
            canvas: document.getElementById('canvas')
        };
    </script>
    {{{ SCRIPT }}}
</body>
</html>
```

### .gitignore additions

```gitignore
# WASM builds
build-wasm/
*.wasm
*.wat

# Emscripten cache
.emscripten_cache/
.emscripten_ports/
```

---

### GitHub README Addition

```markdown
## WebAssembly Support (Fork)

This fork adds WebAssembly (WASM) compilation support while maintaining full native runtime compatibility.

### Quick Start (WASM)

```bash
# Install Emscripten
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk && ./emsdk install latest && ./emsdk activate latest
source ./emsdk_env.sh

# Build for WASM
cd SWFModernRuntime
./scripts/build-wasm.sh

# Test in browser
cd build-wasm
python3 -m http.server 8000
# Open http://localhost:8000/TestSWFRecompiled.html
```

### Current Status

- ✅ Phase 1a: WASM compilation + ActionScript VM (complete)
- ⏭️ Phase 1b: Canvas2D rendering (skipped — proceeding to WebGPU)
- ⏳ Phase 2: WebGPU rendering via SDL + Dawn/wgpu (immediate next step)
- ⏳ Phase 3: SDL_GPU WebGPU migration (waiting on SDL_GPU backend)

### Upstream Sync

This fork tracks upstream regularly. All native functionality remains unchanged.

**Upstream:** https://github.com/SWFRecomp/SWFModernRuntime

---

## Current Implementation Status (October 27, 2025)

### What's Working

**✅ ActionScript Execution (Phase 1a - Complete)**
- Full ActionScript VM running in WASM
- String operations, variables, stack management
- Frame-by-frame execution
- Console output via printf/trace
- Example: `trace_swf_4` running at https://peerinfinity.github.io/SWFModernRuntime/

**✅ Build Infrastructure**
- Emscripten compilation working
- Clean build scripts (`build.sh` per example)
- HTML shell templates
- GitHub Pages deployment
- Live demos accessible

**✅ Project Structure**
- Clean separation: `wasm/` directory for all WASM code
- Minimal merge conflicts with upstream
- Documentation in place

### What's Next

**Immediate Priorities (Phase 2 - WebGPU):**

Phase 1b (Canvas2D rendering) has been skipped. Proceeding directly to Phase 2.

1. **Create Rendering Abstraction Layer**
   - Design `render_api.h` interface
   - Align with upstream's gradient/bitmap support
   - Plan for texture_info (not just color_info)
   - Support display lists and transforms

2. **Implement WebGPU Backend**
   - Set up sdl3webgpu for native, emdawnwebgpu for WASM
   - WebGPU device/adapter/queue initialization
   - Render pipeline creation (vertex, fragment, compute)
   - Port shaders to WGSL (via naga-cli from SPIR-V)

3. **Test Graphics Examples**
   - Port `mess` test to WASM with WebGPU
   - Port `wild_shadow` test
   - Visual comparison with native
   - Document limitations

### Technical Debt to Address

1. **Upstream Architecture Alignment**
   - Current runtime.c is minimal/standalone
   - Need to integrate with upstream display list architecture
   - Character and DisplayObject structs now in upstream
   - Transform system has been refactored

2. **Feature Gap Analysis**
   - Gradients (linear + radial) - upstream has this
   - Bitmaps - upstream has this
   - MSAA - may skip for WASM
   - Compute shaders - WebGPU (Phase 2) supports compute; Canvas2D needs CPU workaround

3. **Build System Integration**
   - Current: standalone examples with shell scripts
   - Future: integrate with main CMake system
   - Need: EMSCRIPTEN build target in root CMakeLists.txt

### Recommended Adjustments to Plan

**Strategic Shifts:**

1. **Skip Canvas2D, Go Straight to WebGPU**
   - Original plan: Canvas2D proof-of-concept, then evaluate
   - New reality: Upstream rendering is sophisticated; Canvas2D can't keep up
   - Decision: Skip Phase 1b Canvas2D entirely, proceed directly to Phase 2 WebGPU

2. **Feature Parity Focus**
   - Original goal: "basic rendering"
   - New goal: Match upstream gradient/bitmap support
   - Reason: Test suite expects these features

3. **Performance Bar Raised**
   - Original: Canvas2D acceptable for proof-of-concept
   - New: Complex games need GPU acceleration
   - Impact: WebGPU (Phase 2) now essential, not optional

**Timeline Adjustments:**

- **Phase 1a (ActionScript + WASM Infrastructure):** COMPLETE ✅
- **Phase 1b (Canvas2D Rendering):** SKIPPED ⏭️ (proceeding directly to WebGPU)
- **Phase 2 (WebGPU via SDL + Dawn/wgpu):** IMMEDIATE NEXT STEP
  - Priority: High

### Open Questions

1. **Architecture Decision:**
   - Should WASM runtime use upstream's display list code?
   - Or keep standalone runtime for simplicity?
   - Trade-off: Code reuse vs. complexity

2. **Rendering Backend Strategy:**
   - ~~Canvas2D minimal → WebGPU full?~~
   - ~~Or skip Canvas2D, go directly to WebGPU?~~
   - **Resolved:** Skip Canvas2D, go directly to WebGPU (Phase 2)

3. **Compute Shader Strategy:**
   - Upstream uses compute shader for gradient matrix inversion
   - **Resolved:** WebGPU has full compute shader support — no workaround needed
   - ~~Canvas2D would have needed CPU-side pre-computation~~ (Canvas2D skipped)

4. **Test Suite:**
   - Which tests should WASM target?
   - Focus on working upstream tests (mess, wild_shadow, gradients)
   - Or fix ActionScript tests for WASM compatibility?

### Success Metrics (Updated)

**Phase 1a Success (Complete):**
- [x] ActionScript VM working in WASM
- [x] Build system and deployment pipeline
- [x] Live demo deployed (trace_swf_4)

**Phase 1b (Canvas2D rendering) — Skipped:**
- ~~Canvas2D rendering showing *something*~~ → Proceeding directly to WebGPU
- ~~At least 1 graphics test rendered in browser~~ → Will be done via WebGPU
- [ ] Documentation of Phase 1b skip rationale → This document (v1.2)

**Phase 2 Success (Elevated Priority):**
- [ ] WebGPU backend with WGSL shader support (native + WASM)
- [ ] Gradients working (linear + radial) via compute shaders
- [ ] Bitmaps/textures working
- [ ] All upstream graphics tests pass visually
- [ ] Performance: 30+ FPS for test games (60+ on native)
- [ ] Bundle size: <2MB (WASM)

## Document History

| Version | Date | Changes |
|---------|------|---------|
| 1.0 | 2025-10-27 | Initial planning document |
| 1.1 | 2025-10-27 | Updated with current implementation status, upstream rendering progress, adjusted priorities and timelines |
| 1.2 | 2026-02-05 | **Phase 2 redesigned: WebGL2 → WebGPU.** WebGPU now supported in all major browsers (Chrome, Edge, Firefox 141+, Safari 26+). Phase 2 uses SDL3 + sdl3webgpu + Dawn/wgpu-native for native, emdawnwebgpu for WASM. Shaders ported to WGSL. Phase 3 redefined as SDL_GPU WebGPU migration (was SDL3 WebGPU). **Phase 1b (Canvas2D rendering) skipped** — proceeding directly to Phase 2 WebGPU. Canvas2D code would be thrown away; WebGPU has compute shaders matching upstream. Updated ecosystem references, risk assessment, and contingency plans. |

---

*End of Planning Document*
