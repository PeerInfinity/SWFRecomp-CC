#pragma once

// WebGPU rendering backend for SWFModernRuntime.
// Uses the standardized webgpu.h C API, which works for both:
//   - Native: via Dawn or wgpu-native (linked as libwebgpu)
//   - WASM:   via emdawnwebgpu (--use-port=emdawnwebgpu)
//
// The API surface matches flashbang.h so that swf.c and tag.c can
// switch between backends via renderer.h macros.

#include <webgpu/webgpu.h>
#include <common.h>

// Forward declaration
typedef struct SWFAppContext SWFAppContext;

typedef struct WebGPURenderContext
{
	int width;
	int height;

	const float* stage_to_ndc;

	// Bitmap metadata (same layout as FlashbangContext)
	size_t bitmap_count;
	size_t bitmap_highest_w;
	size_t bitmap_highest_h;
	size_t current_bitmap;
	u32* bitmap_sizes;

	// CPU-side data pointers (populated by swf.c before init)
	char* shape_data;       size_t shape_data_size;
	char* transform_data;   size_t transform_data_size;
	char* color_data;       size_t color_data_size;
	char* uninv_mat_data;   size_t uninv_mat_data_size;
	char* gradient_data;    size_t gradient_data_size;
	char* bitmap_data;      size_t bitmap_data_size;
	char* cxform_data;      size_t cxform_data_size;

	// --- WebGPU core objects ---
	WGPUInstance instance;
	WGPUAdapter adapter;
	WGPUDevice device;
	WGPUQueue queue;
	WGPUSurface surface;
	WGPUTextureFormat surface_format;

	// --- GPU buffers ---
	WGPUBuffer vertex_buffer;
	WGPUBuffer xform_buffer;          // storage: transforms[]
	WGPUBuffer color_buffer;          // storage: colors[]
	WGPUBuffer uninv_mat_buffer;      // storage: gradient matrices (input)
	WGPUBuffer inv_mat_buffer;        // storage: inverted gradient matrices (output)
	WGPUBuffer bitmap_sizes_buffer;   // storage: bitmap_sizes[]
	WGPUBuffer cxform_buffer;         // storage: cxform data

	// Uniform buffers (written per-frame or per-draw)
	WGPUBuffer stage_to_ndc_buf;      // uniform: mat4
	WGPUBuffer transform_id_buf;      // uniform: u32 (per-draw)
	WGPUBuffer extra_transform_id_buf; // uniform: u32 padded to 16 bytes
	WGPUBuffer extra_transform_buf;   // uniform: mat4 = 64 bytes
	WGPUBuffer cxform_id_buf;         // uniform: u32 padded to 16 bytes
	WGPUBuffer cxform_uniform_buf;    // uniform: 20 floats (5x4 cxform), 80 bytes

	// --- Textures and samplers ---
	WGPUTexture gradient_tex;
	WGPUTextureView gradient_tex_view;
	WGPUSampler gradient_sampler;

	WGPUTexture bitmap_tex;
	WGPUTextureView bitmap_tex_view;
	WGPUSampler bitmap_sampler;

	WGPUTexture dummy_tex;            // 1x1 fallback for empty gradient/bitmap
	WGPUTextureView dummy_tex_view;
	WGPUSampler dummy_sampler;

	WGPUTexture msaa_texture;
	WGPUTextureView msaa_view;

	// --- Pipelines ---
	WGPURenderPipeline render_pipeline;
	WGPUComputePipeline compute_pipeline;

	// --- Bind group layouts ---
	WGPUBindGroupLayout vertex_storage_bgl;   // group 0
	WGPUBindGroupLayout vertex_uniform_bgl;   // group 1
	WGPUBindGroupLayout fragment_sampler_bgl;  // group 2
	WGPUPipelineLayout render_pipeline_layout;

	WGPUBindGroupLayout compute_read_bgl;     // compute group 0
	WGPUBindGroupLayout compute_write_bgl;    // compute group 1
	WGPUPipelineLayout compute_pipeline_layout;

	// --- Bind groups ---
	WGPUBindGroup vertex_storage_bg;   // group 0: transforms, colors, inv_mats, bitmap_sizes
	WGPUBindGroup vertex_uniform_bg;   // group 1: stage_to_ndc, transform_id
	WGPUBindGroup fragment_sampler_bg; // group 2: gradient tex+samp, bitmap tex+samp

	WGPUBindGroup compute_read_bg;     // compute group 0: uninv_mat_buffer
	WGPUBindGroup compute_write_bg;    // compute group 1: inv_mat_buffer

	// --- Per-frame state ---
	WGPUCommandEncoder encoder;
	WGPURenderPassEncoder render_pass;
	WGPUTextureView surface_view;      // current frame's surface texture view

	// --- SDL window (native only) ---
#ifndef __EMSCRIPTEN__
	struct SDL_Window* window;
#endif

	// Window background color
	u8 red;
	u8 green;
	u8 blue;
} WebGPURenderContext;

// --- Public API (matches flashbang.h signatures) ---

WebGPURenderContext* render_webgpu_new(void);
void render_webgpu_init(SWFAppContext* app_context, WebGPURenderContext* context);
int render_webgpu_poll(void);
void render_webgpu_set_background(WebGPURenderContext* context, u8 r, u8 g, u8 b);
void render_webgpu_upload_bitmap(WebGPURenderContext* context, size_t offset, size_t size, u32 width, u32 height);
void render_webgpu_finalize_bitmaps(WebGPURenderContext* context);
void render_webgpu_open_pass(WebGPURenderContext* context);
void render_webgpu_upload_extra_transform_id(WebGPURenderContext* context, u32 transform_id);
void render_webgpu_upload_extra_transform(WebGPURenderContext* context, float* transform);
void render_webgpu_upload_cxform_id(WebGPURenderContext* context, u32 cxform_id);
void render_webgpu_upload_cxform(WebGPURenderContext* context, float* cxform);
void render_webgpu_draw_shape(WebGPURenderContext* context, size_t offset, size_t num_verts, u32 transform_id);
void render_webgpu_close_pass(WebGPURenderContext* context);
void render_webgpu_free(SWFAppContext* app_context, WebGPURenderContext* context);
