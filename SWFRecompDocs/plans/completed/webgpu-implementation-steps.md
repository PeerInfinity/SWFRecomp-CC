> **AUDIT OUTCOME (2026-07-04):** Shipped — render_webgpu.c is the production renderer.

# Phase 2 WebGPU Implementation — Concrete Next Steps

**Created:** February 6, 2026

**Parent Document:** [wasm-project-plan.md](./wasm-project-plan.md) (Phase 2 section)

**Status:** Ready to implement

---

## Purpose

The main project plan (`wasm-project-plan.md`) describes *what* Phase 2 delivers and *why*
WebGPU was chosen. This document describes *how* to implement it, step by step, based on
the actual codebase as it exists today.

---

## Current State of the Code

| Component | Status | Key Files |
|-----------|--------|-----------|
| **ActionScript VM + WASM** | Working | `SWFRecomp/tests/trace_swf_4/runtime/wasm/` |
| **Native GPU renderer** | Working | `flashbang.c` (975 lines, SDL3 GPU / SPIR-V) |
| **Shaders** | GLSL 4.60 + SPIR-V | `vertex.glsl`, `fragment.glsl`, `compute.glsl` |
| **NO_GRAPHICS mode** | Working | `swf_core.c` + `tag_stubs.c` |
| **Rendering abstraction** | Does not exist | No `render_api.h`, no `render_webgpu.c` |
| **WebGPU code** | Does not exist | Nothing yet |

### What the Native Renderer Does

`flashbang.c` uses the SDL3 GPU API (`SDL_GPU*`) with SPIR-V shaders. It:

1. **Initializes** an SDL3 window, GPU device, and graphics/compute pipelines
2. **Uploads static data** once (vertex buffer, transform buffer, color buffer,
   uninverted gradient matrices, gradient textures, bitmap textures, color transforms)
3. **Runs a compute shader** once at init to invert gradient matrices on the GPU
4. **Per frame:** clears, iterates the display list, draws each shape with
   `flashbang_draw_shape(offset, num_verts, transform_id)`, resolves MSAA, presents

### How the Renderer is Called

`swf.c` creates a `FlashbangContext*`, copies all data pointers from `SWFAppContext`,
and calls `flashbang_init()`. The rendering loop lives in `tag.c`:

```
tagShowFrame():
    flashbang_open_pass()
    for each display object:
        flashbang_draw_shape(offset, num_verts, transform_id)
    flashbang_close_pass()
```

The full flashbang API surface used by `swf.c` and `tag.c`:

```c
// Lifecycle
FlashbangContext* flashbang_new();
void flashbang_init(SWFAppContext*, FlashbangContext*);
void flashbang_free(SWFAppContext*, FlashbangContext*);

// Event loop
int flashbang_poll();                      // returns 1 on quit

// Per-frame rendering
void flashbang_set_window_background(FlashbangContext*, u8 r, u8 g, u8 b);
void flashbang_open_pass(FlashbangContext*);
void flashbang_draw_shape(FlashbangContext*, size_t offset, size_t num_verts, u32 transform_id);
void flashbang_close_pass(FlashbangContext*);

// Dynamic data (text rendering, display list transforms)
void flashbang_upload_extra_transform_id(FlashbangContext*, u32 transform_id);
void flashbang_upload_extra_transform(FlashbangContext*, float* transform);
void flashbang_upload_cxform_id(FlashbangContext*, u32 cxform_id);
void flashbang_upload_cxform(FlashbangContext*, float* cxform);

// Bitmap loading (during init)
void flashbang_upload_bitmap(FlashbangContext*, size_t offset, size_t size, u32 w, u32 h);
void flashbang_finalize_bitmaps(FlashbangContext*);
```

### Shader Architecture (3 shaders, ~100 lines total GLSL)

**Vertex shader** (`vertex.glsl`, 59 lines):
- Inputs: `vec2 position`, `uvec2 style` (type + packed ID)
- Storage buffers: transforms[], colors[], inv_mats[], bitmap_sizes[]
- Uniforms: stage_to_ndc (mat4), transform_id (uint)
- Computes: `gl_Position = stage_to_ndc * transforms[transform_id] * pos`
- Pre-computes per-fill-type args (solid color / gradient UV / bitmap UV)

**Fragment shader** (`fragment.glsl`, 22 lines):
- Inputs: flat v_style_type, flat v_style_id, interpolated v_args
- Samplers: gradient_tex (2D array), bitmap_tex (2D array)
- Branches on style type: solid (0x00), linear gradient (0x10),
  radial gradient (0x12), bitmap (0x41)

**Compute shader** (`compute.glsl`, 22 lines):
- Workgroup: 64x1x1
- Reads uninverted gradient matrices, writes inverted matrices
- `inv_gradmats[i] = inverse(gradmats[i])`

### GPU Resource Layout

| Set | Binding | Stage | Resource | Type |
|-----|---------|-------|----------|------|
| 0 | 0 | Vertex | transforms[] | Storage buffer (readonly) |
| 0 | 1 | Vertex | colors[] | Storage buffer (readonly) |
| 0 | 2 | Vertex | inv_mats[] | Storage buffer (readonly) |
| 0 | 3 | Vertex | bitmap_sizes[] | Storage buffer (readonly) |
| 1 | 0 | Vertex | stage_to_ndc | Uniform buffer |
| 1 | 1 | Vertex | transform_id | Uniform buffer |
| 2 | 0 | Fragment | gradient_tex | Texture + sampler |
| 2 | 1 | Fragment | bitmap_tex | Texture + sampler |
| — | 0 | Fragment | cxform[] | Storage buffer (readonly) |

Compute shader:
| Set | Binding | Resource | Type |
|-----|---------|----------|------|
| 0 | 0 | gradmats[] | Storage buffer (readonly) |
| 1 | 0 | inv_gradmats[] | Storage buffer (readwrite) |

---

## Implementation Steps

### Step 1: Port Shaders to WGSL

**Why first:** Shaders define the GPU interface. The WebGPU C code must match the
WGSL bind group layout, so start here and let the shader definitions drive the C code.

**What to do:**

1. Install naga-cli: `cargo install naga-cli`
2. Compile existing GLSL to SPIR-V: `glslc -fshader-stage=vertex vertex.glsl -o vertex.spv`
   (repeat for fragment, compute)
3. Convert SPIR-V to WGSL: `naga vertex.spv vertex.wgsl` (repeat for all three)
4. Review and clean up the generated WGSL — naga output is correct but verbose
5. Manually verify bind group / binding indices match the planned C layout

**Output files:**
```
SWFModernRuntime/src/flashbang/shaders/
├── vertex.glsl      (existing)
├── fragment.glsl    (existing)
├── compute.glsl     (existing)
├── vertex.wgsl      (new)
├── fragment.wgsl    (new)
└── compute.wgsl     (new)
```

**Key WGSL translation notes:**

- `layout(std430, set=0, binding=0) readonly buffer` → `@group(0) @binding(0) var<storage, read>`
- `layout(set=1, binding=0) uniform` → `@group(1) @binding(0) var<uniform>`
- `sampler2DArray` → `texture_2d_array<f32>` + `sampler` (separate binding for each)
- `gl_Position` → return value with `@builtin(position)`
- `gl_GlobalInvocationID` → `@builtin(global_invocation_id)`
- `inverse()` does not exist in WGSL — must be implemented manually in the compute
  shader (4x4 matrix inverse via cofactor expansion or adjugate/determinant)
- `flat` interpolation → `@interpolate(flat)` in WGSL
- WGSL uses `textureSample(tex, samp, coords)` not `texture(sampler2DArray, coords)`
- For 2D array textures: `textureSample(tex, samp, vec2f(u, v), array_index)`

**Complexity concern: `inverse()` in WGSL.** WGSL has no built-in matrix inverse. Options:
- (a) Implement a `mat4x4_inverse()` function in WGSL (~30 lines, cofactor method)
- (b) Pre-compute inverses on the CPU before upload (avoid compute shader entirely)
- (c) Use a simplified inverse if matrices have known structure (e.g., affine only)

Recommendation: Option (a). The compute shader is short and the inverse is well-defined.
This preserves the existing architecture and keeps the CPU path identical.

**Verification:** The WGSL shaders can be validated offline using `naga --validate`
or by loading them into a test WebGPU program that just creates the pipeline.

---

### Step 2: Implement `render_webgpu.c` (WebGPU Backend)

**Goal:** A new C file that implements the same API surface as `flashbang.c` but uses
`webgpu.h` instead of `SDL_GPU*`. This file works for both native (Dawn/wgpu-native)
and WASM (emdawnwebgpu) because `webgpu.h` is the same API in both cases.

**Approach: Match flashbang's API, not create a new abstraction.** The simplest path
is to give `render_webgpu.c` the *same function signatures* as `flashbang.c` and use
the same `FlashbangContext`-like struct (renamed to `WebGPUContext`). This means `swf.c`
and `tag.c` need only trivial `#ifdef` changes to switch between backends.

**File:** `SWFModernRuntime/src/rendering/render_webgpu.c`

**Header:** `SWFModernRuntime/include/rendering/render_webgpu.h`

The header should expose the same function signatures as `flashbang.h`, but with a
different context type and using `webgpu.h` types internally.

#### Sub-step 2a: Context Structure

```c
// render_webgpu.h
#include <webgpu/webgpu.h>

typedef struct WebGPURenderContext {
    int width, height;
    const float* stage_to_ndc;

    // Bitmap metadata (same as FlashbangContext)
    size_t bitmap_count, bitmap_highest_w, bitmap_highest_h;
    size_t current_bitmap;
    u32* bitmap_sizes;

    // CPU-side data pointers (same as FlashbangContext)
    char* shape_data;       size_t shape_data_size;
    char* transform_data;   size_t transform_data_size;
    char* color_data;       size_t color_data_size;
    char* uninv_mat_data;   size_t uninv_mat_data_size;
    char* gradient_data;    size_t gradient_data_size;
    char* bitmap_data;      size_t bitmap_data_size;
    char* cxform_data;      size_t cxform_data_size;

    // WebGPU objects
    WGPUInstance instance;
    WGPUAdapter adapter;
    WGPUDevice device;
    WGPUQueue queue;
    WGPUSurface surface;

    // Buffers
    WGPUBuffer vertex_buffer;
    WGPUBuffer xform_buffer;
    WGPUBuffer color_buffer;
    WGPUBuffer uninv_mat_buffer;
    WGPUBuffer inv_mat_buffer;
    WGPUBuffer bitmap_sizes_buffer;
    WGPUBuffer cxform_buffer;
    WGPUBuffer stage_to_ndc_uniform;
    WGPUBuffer transform_id_uniform;

    // Textures and samplers
    WGPUTexture gradient_tex;
    WGPUSampler gradient_sampler;
    WGPUTexture bitmap_tex;
    WGPUSampler bitmap_sampler;
    WGPUTexture msaa_texture;
    WGPUTexture resolve_texture;
    WGPUTextureView msaa_view;
    WGPUTextureView resolve_view;

    // Pipelines
    WGPURenderPipeline render_pipeline;
    WGPUComputePipeline compute_pipeline;

    // Bind groups
    WGPUBindGroup vertex_storage_bg;    // group 0: transforms, colors, inv_mats, bitmap_sizes
    WGPUBindGroup vertex_uniform_bg;    // group 1: stage_to_ndc, transform_id
    WGPUBindGroup fragment_sampler_bg;  // group 2: gradient_tex, bitmap_tex
    WGPUBindGroup fragment_storage_bg;  // group 3: cxform (NOTE: renumber from flashbang)
    WGPUBindGroup compute_read_bg;      // compute group 0
    WGPUBindGroup compute_write_bg;     // compute group 1

    // Per-frame state
    WGPUCommandEncoder encoder;
    WGPURenderPassEncoder render_pass;

    // SDL window (native only)
#ifndef __EMSCRIPTEN__
    SDL_Window* window;
#endif

    u8 red, green, blue;
} WebGPURenderContext;
```

#### Sub-step 2b: Initialization Sequence

The init function mirrors `flashbang_init()` but uses WebGPU calls:

1. **Create instance:** `wgpuCreateInstance(&desc)`
2. **Create surface:**
   - Native: Use `sdl3webgpu` to get `WGPUSurface` from SDL3 window
   - WASM: Use `WGPUSurfaceDescriptorFromCanvasHTMLSelector("#canvas")`
3. **Request adapter:** `wgpuInstanceRequestAdapter(instance, &opts, callback, userdata)`
   - Note: This is **async** in WASM. Use Emscripten's Asyncify or
     `emscripten_request_animation_frame_loop` pattern
4. **Request device:** `wgpuAdapterRequestDevice(adapter, &desc, callback, userdata)`
   - Also async. Dawn requires device limits to be explicitly requested
5. **Get queue:** `wgpuDeviceGetQueue(device)`
6. **Configure surface:** `wgpuSurfaceConfigure(surface, &config)` with preferred format
7. **Create buffers:** `wgpuDeviceCreateBuffer(device, &desc)` for each GPU buffer
   - Mark vertex buffer with `WGPUBufferUsage_Vertex | WGPUBufferUsage_CopyDst`
   - Mark storage buffers with `WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst`
8. **Upload data:** `wgpuQueueWriteBuffer(queue, buffer, offset, data, size)`
   (simpler than SDL3's transfer buffer dance)
9. **Create textures:** `wgpuDeviceCreateTexture(device, &desc)`
   - Gradient: 2D array, 256x1, N layers, RGBA8Unorm
   - Bitmap: 2D array, (max_w+1) x (max_h+1), N layers
   - MSAA: match surface format, sampleCount=4 (or 8 if supported)
   - Resolve: same format, sampleCount=1
10. **Upload textures:** `wgpuQueueWriteTexture(queue, &dest, data, size, &layout, &extent)`
11. **Create samplers:** `wgpuDeviceCreateSampler(device, &desc)` with linear filtering
12. **Load WGSL shaders:**
    - Native: load from file at runtime, or embed as C string at compile time
    - WASM: embed as C string (no filesystem)
    - Create shader modules: `wgpuDeviceCreateShaderModule(device, &desc)` with WGSL source
13. **Create bind group layouts + pipeline layouts**
14. **Create render pipeline:** vertex + fragment stages, vertex buffer layout,
    color target (with alpha blending), multisample state
15. **Create compute pipeline:** for gradient matrix inversion
16. **Create bind groups:** bind actual buffers/textures to layouts
17. **Run compute dispatch:** invert gradient matrices
    ```c
    WGPUCommandEncoder enc = wgpuDeviceCreateCommandEncoder(device, &desc);
    WGPUComputePassEncoder pass = wgpuCommandEncoderBeginComputePass(enc, NULL);
    wgpuComputePassEncoderSetPipeline(pass, compute_pipeline);
    wgpuComputePassEncoderSetBindGroup(pass, 0, compute_read_bg, 0, NULL);
    wgpuComputePassEncoderSetBindGroup(pass, 1, compute_write_bg, 0, NULL);
    wgpuComputePassEncoderDispatchWorkgroups(pass, ceil(n/64), 1, 1);
    wgpuComputePassEncoderEnd(pass);
    WGPUCommandBuffer cmd = wgpuCommandEncoderFinish(enc, NULL);
    wgpuQueueSubmit(queue, 1, &cmd);
    ```

#### Sub-step 2c: Per-Frame Rendering

**`render_webgpu_open_pass()`:**
```c
// Get current surface texture
WGPUSurfaceTexture surfTex;
wgpuSurfaceGetCurrentTexture(ctx->surface, &surfTex);
WGPUTextureView surfView = wgpuTextureCreateView(surfTex.texture, NULL);

// Create command encoder
ctx->encoder = wgpuDeviceCreateCommandEncoder(ctx->device, &encDesc);

// Begin render pass
WGPURenderPassColorAttachment colorAtt = {
    .view = ctx->msaa_view,          // Render to MSAA texture
    .resolveTarget = surfView,        // Resolve to surface (or resolve_view)
    .loadOp = WGPULoadOp_Clear,
    .storeOp = WGPUStoreOp_Store,
    .clearValue = { r/255.0, g/255.0, b/255.0, 1.0 },
};
WGPURenderPassDescriptor rpDesc = {
    .colorAttachmentCount = 1,
    .colorAttachments = &colorAtt,
};
ctx->render_pass = wgpuCommandEncoderBeginRenderPass(ctx->encoder, &rpDesc);

// Bind pipeline and static bind groups
wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 0, ctx->vertex_storage_bg, 0, NULL);
wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 2, ctx->fragment_sampler_bg, 0, NULL);
wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 3, ctx->fragment_storage_bg, 0, NULL);

// Upload stage_to_ndc uniform
wgpuQueueWriteBuffer(ctx->queue, ctx->stage_to_ndc_uniform, 0,
                     ctx->stage_to_ndc, 16 * sizeof(float));
```

**`render_webgpu_draw_shape()`:**
```c
// Update transform_id uniform
wgpuQueueWriteBuffer(ctx->queue, ctx->transform_id_uniform, 0,
                     &transform_id, sizeof(u32));

// Rebind group 1 (or use dynamic offsets if supported)
wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 1, ctx->vertex_uniform_bg, 0, NULL);

// Set vertex buffer with byte offset
wgpuRenderPassEncoderSetVertexBuffer(ctx->render_pass, 0, ctx->vertex_buffer,
                                     offset * 4 * sizeof(u32), num_verts * 4 * sizeof(u32));

// Draw
wgpuRenderPassEncoderDraw(ctx->render_pass, num_verts, 1, 0, 0);
```

**Note on per-draw uniforms:** WebGPU does not have push constants. The `transform_id`
must be updated via `wgpuQueueWriteBuffer` before each draw call, or by using a larger
uniform buffer with dynamic offsets. The simplest approach for correctness is
`wgpuQueueWriteBuffer` per draw. Optimize later if it becomes a bottleneck.

**`render_webgpu_close_pass()`:**
```c
wgpuRenderPassEncoderEnd(ctx->render_pass);
WGPUCommandBuffer cmd = wgpuCommandEncoderFinish(ctx->encoder, NULL);
wgpuQueueSubmit(ctx->queue, 1, &cmd);
wgpuSurfacePresent(ctx->surface);

// Release per-frame objects
wgpuCommandBufferRelease(cmd);
wgpuRenderPassEncoderRelease(ctx->render_pass);
wgpuCommandEncoderRelease(ctx->encoder);
```

#### Sub-step 2d: Async Initialization (WASM)

WebGPU adapter and device requests are asynchronous. On native (Dawn), these can be
synchronous. On WASM, you must use one of:

- **Asyncify** (`-sASYNCIFY=1`): Allows blocking C code to work by saving/restoring
  the call stack. Simplest approach; adds ~10% code size overhead.
- **Callback chaining:** Structure init as a series of callbacks. More complex, but
  no Asyncify overhead.

Recommendation: **Use Asyncify.** The initialization runs once and the code size
overhead is acceptable. This lets the init code look identical to native.

---

### Step 3: Integrate with Existing Code (`swf.c` / `tag.c`)

**Goal:** Make `swf.c` and `tag.c` use either flashbang or the WebGPU renderer based
on a compile-time flag, with minimal changes to these files.

**Approach A (recommended): Shared header with matching signatures.**

Create `SWFModernRuntime/include/rendering/renderer.h`:

```c
#pragma once

#include <common.h>

typedef struct SWFAppContext SWFAppContext;

#if defined(USE_WEBGPU)
    #include "render_webgpu.h"
    typedef WebGPURenderContext RenderContext;
#else
    #include <flashbang.h>
    typedef FlashbangContext RenderContext;
#endif

// Unified function names (macros or inline wrappers)
#if defined(USE_WEBGPU)
    #define renderer_new()                          render_webgpu_new()
    #define renderer_init(app, ctx)                 render_webgpu_init(app, ctx)
    #define renderer_poll()                         render_webgpu_poll()
    #define renderer_set_background(ctx, r, g, b)   render_webgpu_set_background(ctx, r, g, b)
    #define renderer_open_pass(ctx)                 render_webgpu_open_pass(ctx)
    #define renderer_draw_shape(ctx, o, n, t)       render_webgpu_draw_shape(ctx, o, n, t)
    #define renderer_close_pass(ctx)                render_webgpu_close_pass(ctx)
    #define renderer_free(app, ctx)                 render_webgpu_free(app, ctx)
    #define renderer_upload_bitmap(ctx, o, s, w, h) render_webgpu_upload_bitmap(ctx, o, s, w, h)
    #define renderer_finalize_bitmaps(ctx)          render_webgpu_finalize_bitmaps(ctx)
    #define renderer_upload_extra_transform_id(ctx, t) render_webgpu_upload_extra_transform_id(ctx, t)
    #define renderer_upload_extra_transform(ctx, t)    render_webgpu_upload_extra_transform(ctx, t)
    #define renderer_upload_cxform_id(ctx, id)         render_webgpu_upload_cxform_id(ctx, id)
    #define renderer_upload_cxform(ctx, c)             render_webgpu_upload_cxform(ctx, c)
#else
    #define renderer_new()                          flashbang_new()
    #define renderer_init(app, ctx)                 flashbang_init(app, ctx)
    #define renderer_poll()                         flashbang_poll()
    #define renderer_set_background(ctx, r, g, b)   flashbang_set_window_background(ctx, r, g, b)
    #define renderer_open_pass(ctx)                 flashbang_open_pass(ctx)
    #define renderer_draw_shape(ctx, o, n, t)       flashbang_draw_shape(ctx, o, n, t)
    #define renderer_close_pass(ctx)                flashbang_close_pass(ctx)
    #define renderer_free(app, ctx)                 flashbang_free(app, ctx)
    #define renderer_upload_bitmap(ctx, o, s, w, h) flashbang_upload_bitmap(ctx, o, s, w, h)
    #define renderer_finalize_bitmaps(ctx)          flashbang_finalize_bitmaps(ctx)
    #define renderer_upload_extra_transform_id(ctx, t) flashbang_upload_extra_transform_id(ctx, t)
    #define renderer_upload_extra_transform(ctx, t)    flashbang_upload_extra_transform(ctx, t)
    #define renderer_upload_cxform_id(ctx, id)         flashbang_upload_cxform_id(ctx, id)
    #define renderer_upload_cxform(ctx, c)             flashbang_upload_cxform(ctx, c)
#endif
```

Then `swf.c` changes from:
```c
#include <flashbang.h>
FlashbangContext* context;
context = flashbang_new();
flashbang_init(app_context, context);
```
To:
```c
#include <renderer.h>
RenderContext* context;
context = renderer_new();
renderer_init(app_context, context);
```

This keeps `swf.c` and `tag.c` almost unchanged — just different include and identifier
names. The native build with `USE_WEBGPU` undefined compiles exactly the same as before.

**Approach B (alternative): Keep flashbang names, use separate source files.**

Instead of renaming, give `render_webgpu.c` functions the exact same names as
`flashbang_*` and select which .c file to compile. This avoids touching `swf.c`/`tag.c`
at all but means the WebGPU context struct must use the name `FlashbangContext` (confusing)
or `swf.c` must be duplicated.

Recommendation: **Approach A.** It's a small diff to `swf.c`/`tag.c` and cleanly
separates the naming.

---

### Step 4: Build System (CMake)

**Changes to `SWFModernRuntime/CMakeLists.txt`:**

```cmake
# Add after the NO_GRAPHICS option
option(USE_WEBGPU "Use WebGPU rendering backend (native + WASM)" OFF)

if(NO_GRAPHICS)
    # ... existing NO_GRAPHICS path, unchanged ...

elseif(USE_WEBGPU)
    message(STATUS "Building with WebGPU rendering backend")
    add_definitions(-DUSE_WEBGPU)

    set(SWF_SOURCES
        ${PROJECT_SOURCE_DIR}/src/libswf/swf.c
        ${PROJECT_SOURCE_DIR}/src/libswf/tag.c
        ${PROJECT_SOURCE_DIR}/src/rendering/render_webgpu.c
    )

    if(EMSCRIPTEN)
        # WASM: use emdawnwebgpu port
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --use-port=emdawnwebgpu")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --use-port=emdawnwebgpu -sASYNCIFY=1 -sALLOW_MEMORY_GROWTH=1")
    else()
        # Native: use SDL3 + sdl3webgpu + Dawn or wgpu-native
        list(APPEND SWF_SOURCES ${PROJECT_SOURCE_DIR}/lib/sdl3webgpu/sdl3webgpu.c)
        # Dawn or wgpu-native linked via WEBGPU_BACKEND variable
    endif()

else()
    # ... existing SDL3 GPU path, unchanged ...
endif()
```

**New include paths:**
```cmake
if(USE_WEBGPU)
    target_include_directories(${PROJECT_NAME} PRIVATE
        ${PROJECT_SOURCE_DIR}/include/rendering
    )
    if(NOT EMSCRIPTEN)
        target_include_directories(${PROJECT_NAME} PRIVATE
            ${PROJECT_SOURCE_DIR}/lib/sdl3webgpu
            ${PROJECT_SOURCE_DIR}/lib/SDL3/include  # Still needed for window management
        )
    endif()
endif()
```

**Build commands:**
```bash
# Native + SDL3 GPU (unchanged, existing behavior)
cmake -B build-native ..
cmake --build build-native

# Native + WebGPU (new)
cmake -B build-webgpu -DUSE_WEBGPU=ON ..
cmake --build build-webgpu

# WASM + WebGPU (new)
emcmake cmake -B build-wasm -DUSE_WEBGPU=ON ..
emmake cmake --build build-wasm
```

---

### Step 5: Dependencies Setup

#### 5a. sdl3webgpu (native only)

```bash
# Add as a single-file library
mkdir -p SWFModernRuntime/lib/sdl3webgpu
# Download sdl3webgpu.h and sdl3webgpu.c from:
# https://github.com/eliemichel/sdl3webgpu
```

This is two files (~300 lines total) that bridge SDL3 window → WGPUSurface.

#### 5b. Dawn or wgpu-native (native only)

**Option A: Dawn** (recommended for debugging — same impl as Chrome)
- Download pre-built from Dawn releases or build from source
- Provides `libwebgpu_dawn.so` / `webgpu_dawn.dll` + `webgpu.h`

**Option B: wgpu-native** (simpler to integrate — pre-built binaries on GitHub)
- Download from https://github.com/gfx-rs/wgpu-native/releases
- Provides `libwgpu_native.so` / `wgpu_native.dll` + `webgpu.h`
- Note: not yet fully conformant with the stable `webgpu.h` spec

Recommendation: Start with **wgpu-native** (easiest setup), switch to Dawn if
conformance issues arise.

#### 5c. emdawnwebgpu (WASM only)

Built into Emscripten 4.0.10+. No manual setup needed.

```bash
# Verify Emscripten version
emcc --version  # Must be >= 4.0.10

# The flag --use-port=emdawnwebgpu handles everything
```

#### 5d. naga-cli (shader conversion)

```bash
cargo install naga-cli
```

Used at build time to convert SPIR-V → WGSL. Not a runtime dependency.

---

### Step 6: WASM Event Loop Integration

Flash games run in a frame loop. In native, this is a `while(!quit)` loop. In WASM,
the browser controls the event loop — blocking the main thread freezes the page.

**Solution:** Use Emscripten's `emscripten_set_main_loop()` or Asyncify.

The current `tagMain()` in `swf.c` is a `while(!quit_swf)` loop. With Asyncify
enabled (`-sASYNCIFY=1`), this loop can yield to the browser between frames by
inserting `emscripten_sleep(0)` calls.

**Minimal change to `swf.c` tagMain loop:**

```c
void tagMain(SWFAppContext* app_context) {
    while (!quit_swf) {
        current_frame = next_frame;
        frame_funcs[next_frame](app_context);
        if (!manual_next_frame) next_frame += 1;
        manual_next_frame = 0;

#ifdef __EMSCRIPTEN__
        emscripten_sleep(0);  // Yield to browser, resume next frame
#endif
        bad_poll |= renderer_poll();
        quit_swf |= bad_poll;
    }
}
```

Alternatively, restructure into a callback:

```c
#ifdef __EMSCRIPTEN__
void one_frame(void* arg) {
    SWFAppContext* app_context = (SWFAppContext*)arg;
    if (quit_swf) { emscripten_cancel_main_loop(); return; }
    current_frame = next_frame;
    frame_funcs[next_frame](app_context);
    if (!manual_next_frame) next_frame += 1;
    manual_next_frame = 0;
}
// In swfStart: emscripten_set_main_loop_arg(one_frame, app_context, 0, 1);
#endif
```

Recommendation: Start with Asyncify + `emscripten_sleep(0)` for simplicity. It requires
the least code change. The callback approach can be adopted later if Asyncify's overhead
is a concern.

---

### Step 7: Test with a Graphics Example

**Target test case:** `three_boxes` (simple, no gradients/bitmaps — just solid colors)

1. Build the test with `USE_WEBGPU=ON` for native
2. Verify the window opens and three colored boxes render correctly
3. Compare output visually with the existing SDL3 GPU build
4. Build the test with WASM + WebGPU
5. Open in Chrome, verify rendering matches native

**Progressive test complexity:**
1. `three_boxes` — solid fills only (validates pipeline, transforms, colors)
2. `mess` — more complex shapes (validates vertex buffer offsets, display list)
3. `awful_gradient` — linear gradients (validates compute shader, gradient textures)
4. `awful_radial_gradient` — radial gradients (validates radial gradient UV math)
5. `wild_shadow` — bitmaps (validates bitmap textures, UV computation)

---

## Bind Group Layout Design

WebGPU requires explicit bind group layouts. Unlike SDL3 which uses ad-hoc buffer
binding, WebGPU pre-defines which resources are in each group.

**Proposed layout (matching the shader sets in vertex.glsl):**

```
Group 0 (per-pipeline, vertex stage):
  @binding(0) transforms: storage<read>
  @binding(1) colors: storage<read>
  @binding(2) inv_mats: storage<read>
  @binding(3) bitmap_sizes: storage<read>

Group 1 (per-draw, vertex stage):
  @binding(0) stage_to_ndc: uniform
  @binding(1) transform_id: uniform

Group 2 (per-pipeline, fragment stage):
  @binding(0) gradient_tex: texture_2d_array
  @binding(1) gradient_sampler: sampler
  @binding(2) bitmap_tex: texture_2d_array
  @binding(3) bitmap_sampler: sampler

Group 3 (per-pipeline, fragment stage):
  @binding(0) cxform: storage<read>
```

**Note on Group 2:** WebGPU requires textures and samplers to be separate bindings
(unlike GLSL's combined `sampler2DArray`). This means 4 bindings in group 2 instead
of 2.

**Note on Group 1 (per-draw uniforms):** `transform_id` changes every draw call.
Two approaches:
- Simple: Call `wgpuQueueWriteBuffer()` per draw. Works but may be slow.
- Better: Use a dynamic uniform buffer offset — create one large buffer with all
  transform IDs packed, then use `wgpuRenderPassEncoderSetBindGroup` with a dynamic
  offset per draw. Requires `hasDynamicOffset: true` in the bind group layout.

Start with the simple approach. Optimize later.

---

## Key Differences: SDL3 GPU vs WebGPU

| Feature | SDL3 GPU (flashbang.c) | WebGPU (render_webgpu.c) |
|---------|----------------------|--------------------------|
| Push constants | `SDL_PushGPUVertexUniformData` | Not available; use uniform buffer |
| Buffer upload | Transfer buffer → CopyPass → Upload | `wgpuQueueWriteBuffer` (simpler) |
| Texture upload | Transfer buffer → CopyPass → Upload | `wgpuQueueWriteTexture` (simpler) |
| Shader format | SPIR-V binary | WGSL source text |
| Resource binding | Bind slots individually | Bind groups (pre-created) |
| MSAA resolve | `STOREOP_RESOLVE` | `resolveTarget` in color attachment |
| Present | Blit resolve→swapchain + Submit | `wgpuSurfacePresent()` after submit |
| Pipeline creation | Verbose struct init | Verbose struct init (similar) |
| Combined sampler | `sampler2DArray` (1 binding) | Separate texture + sampler (2 bindings) |

---

## Risk Assessment for This Implementation

| Risk | Likelihood | Impact | Mitigation |
|------|-----------|--------|------------|
| WGSL `inverse()` missing | Certain | Low | Implement manually (~30 lines) |
| Async init complexity (WASM) | Medium | Medium | Use Asyncify (simplest path) |
| Per-draw uniform updates slow | Medium | Low | Start simple, optimize with dynamic offsets |
| MSAA sample count differences | Low | Low | Use 4x instead of 8x; check adapter limits |
| Texture array support gaps | Low | Medium | All modern browsers support this |
| wgpu-native conformance issues | Medium | Medium | Switch to Dawn if problems arise |

---

## File Checklist

New files to create:

```
SWFModernRuntime/
├── include/rendering/
│   ├── render_webgpu.h         # WebGPU context struct + function declarations
│   └── renderer.h              # Unified macro layer (flashbang or webgpu)
├── src/rendering/
│   └── render_webgpu.c         # WebGPU backend implementation
├── src/flashbang/shaders/
│   ├── vertex.wgsl             # Ported vertex shader
│   ├── fragment.wgsl           # Ported fragment shader
│   └── compute.wgsl            # Ported compute shader (with manual inverse)
└── lib/sdl3webgpu/             # Third-party (native only)
    ├── sdl3webgpu.h
    └── sdl3webgpu.c
```

Files to modify:

```
SWFModernRuntime/
├── CMakeLists.txt              # Add USE_WEBGPU option + new source files
├── src/libswf/swf.c            # #include renderer.h, use renderer_* macros
└── src/libswf/tag.c            # #include renderer.h, use renderer_* macros
```

---

## Suggested Implementation Order

1. **Shaders first** — Port GLSL → WGSL, validate with naga
2. **render_webgpu.c init** — Get a colored triangle on screen (native + Dawn/wgpu)
3. **Full pipeline** — Add all buffers, storage, textures; render `three_boxes`
4. **WASM build** — Hook up emdawnwebgpu, test in Chrome
5. **Gradients** — Compute shader + gradient textures
6. **Bitmaps** — Bitmap texture array support
7. **Text** — Extra transform/cxform upload
8. **Polish** — MSAA, error handling, resource cleanup

Each step produces a testable result. Don't move to the next until the current step
renders correctly on at least one platform.
