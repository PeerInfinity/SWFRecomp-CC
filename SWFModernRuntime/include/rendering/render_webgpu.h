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
	u32 xform_slot_count;             // total slots in xform_buffer (original + dynamic)
	WGPUBuffer color_buffer;          // storage: colors[]
	WGPUBuffer uninv_mat_buffer;      // storage: gradient matrices (input)
	WGPUBuffer inv_mat_buffer;        // storage: inverted gradient matrices (output)
	WGPUBuffer bitmap_sizes_buffer;   // storage: bitmap_sizes[]
	WGPUBuffer cxform_buffer;         // storage: cxform data
	u32 cxform_slot_count;            // total slots in cxform_buffer (original + dynamic)

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

	WGPUTexture depth_stencil_texture;
	WGPUTextureView depth_stencil_view;

	// --- Pipelines ---
	WGPURenderPipeline render_pipeline;         // normal: no stencil test
	WGPURenderPipeline stencil_write_pipeline;  // writes stencil, no color output
	WGPURenderPipeline stencil_test_pipeline;   // tests stencil, normal color output
	WGPURenderPipeline blend_add_pipeline;      // blend mode 8: additive
	WGPURenderPipeline blend_lighten_pipeline;  // blend mode 5: lighten (max)
	WGPURenderPipeline blend_darken_pipeline;   // blend mode 6: darken (min)
	WGPURenderPipeline blend_subtract_pipeline; // blend mode 9: subtract
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

	// --- Filter resources (lazy-initialized on first filtered object) ---
	int filter_resources_created;
	WGPUTexture filter_tex_a;          // canvas-sized RGBA8 non-MSAA ping-pong A
	WGPUTexture filter_tex_b;          // canvas-sized RGBA8 non-MSAA ping-pong B
	WGPUTextureView filter_view_a;
	WGPUTextureView filter_view_b;
	WGPUTexture filter_msaa_texture;   // separate MSAA 4x texture for offscreen rendering
	WGPUTextureView filter_msaa_view;
	WGPUSampler filter_sampler;        // linear, clamp-to-edge
	WGPUBuffer filter_quad_buffer;     // 6-vertex fullscreen NDC quad
	WGPUBuffer blur_params_buf;        // uniform: direction(vec2f), texel_size(vec2f), radius(f32), strength(f32), color(vec4f) = 48 bytes padded to 64
	WGPURenderPipeline blur_pipeline;
	WGPUBindGroupLayout blur_bgl;
	WGPUPipelineLayout blur_pipeline_layout;
	WGPURenderPipeline composite_pipeline;  // draws filtered result into MSAA main pass
	WGPUBindGroupLayout composite_bgl;
	WGPUPipelineLayout composite_pipeline_layout;

	// --- SDL window (native only) ---
#if !defined(__EMSCRIPTEN__) && !defined(HEADLESS_GRAPHICS)
	struct SDL_Window* window;
#endif

#ifdef HEADLESS_GRAPHICS
	// --- Headless rendering resources ---
	WGPUTexture offscreen_texture;   // offscreen RGBA8 render target (resolve target)
	WGPUTextureView offscreen_view;  // persistent view of offscreen_texture
	WGPUBuffer readback_buffer;      // staging buffer for GPU→CPU readback
	size_t readback_row_stride;      // bytes per row in readback buffer (256-aligned)
	int capture_requested;           // 1 if next close_pass should copy to readback buffer
#endif

	// Window background color
	u8 red;
	u8 green;
	u8 blue;

	// Dynamic rendering (text field backgrounds/borders, Drawing API)
	u32 dynamic_vertex_base;    // vertex offset (in vertices) where dynamic area starts
	u32 dynamic_color_base;     // color index where dynamic colors start
	u32 dynamic_rect_count;     // number of dynamic color slots used this frame
	u32 dynamic_vertex_used;    // total dynamic vertices used this frame

	// Renderer initialization status (0 = not ready, 1 = fully initialized)
	int renderer_ok;
} WebGPURenderContext;

// --- Public API (matches flashbang.h signatures) ---

WebGPURenderContext* render_webgpu_new(void);
void render_webgpu_init(SWFAppContext* app_context, WebGPURenderContext* context);
int render_webgpu_poll(SWFAppContext* app_context);
void render_webgpu_set_background(WebGPURenderContext* context, u8 r, u8 g, u8 b);
void render_webgpu_upload_bitmap(WebGPURenderContext* context, size_t offset, size_t size, u32 width, u32 height);
void render_webgpu_finalize_bitmaps(WebGPURenderContext* context);
void render_webgpu_open_pass(WebGPURenderContext* context);
void render_webgpu_upload_extra_transform_id(WebGPURenderContext* context, u32 transform_id);
void render_webgpu_upload_extra_transform(WebGPURenderContext* context, float* transform);
void render_webgpu_upload_cxform_id(WebGPURenderContext* context, u32 cxform_id);
void render_webgpu_upload_cxform(WebGPURenderContext* context, float* cxform);
void render_webgpu_draw_shape(WebGPURenderContext* context, size_t offset, size_t num_verts, u32 transform_id, u32 cxform_id);
void render_webgpu_draw_rect(WebGPURenderContext* context, float x, float y, float w, float h, float r, float g, float b, float a, u32 transform_id, u32 cxform_id);
void render_webgpu_draw_tris(WebGPURenderContext* context, const float* xy_pairs, u32 vertex_count, float r, float g, float b, float a, u32 transform_id, u32 cxform_id);
void render_webgpu_begin_clip_mask(WebGPURenderContext* context);
void render_webgpu_end_clip_mask(WebGPURenderContext* context);
void render_webgpu_end_clip(WebGPURenderContext* context);
void render_webgpu_close_pass(WebGPURenderContext* context);
void render_webgpu_compose_text_transforms(WebGPURenderContext* context, const char* transform_data, u32 place_transform_id, u32 glyph_start, size_t count);
void render_webgpu_compose_sprite_transform(WebGPURenderContext* context, const char* transform_data, u32 parent_transform_id, u32 child_transform_id);
void render_webgpu_write_transform(WebGPURenderContext* context, u32 transform_id, const float composed[16]);
void render_webgpu_write_cxform(WebGPURenderContext* context, u32 cxform_slot, const float cxform[20]);
void render_webgpu_update_vertices(WebGPURenderContext* context, size_t byte_offset, const void* data, size_t byte_size);
void render_webgpu_update_colors(WebGPURenderContext* context, size_t byte_offset, const void* data, size_t byte_size);
void render_webgpu_set_blend_mode(WebGPURenderContext* context, u8 blend_mode);
void render_webgpu_suspend_pass(WebGPURenderContext* context);
void render_webgpu_resume_pass(WebGPURenderContext* context);
void render_webgpu_begin_offscreen_pass(WebGPURenderContext* context);
void render_webgpu_end_offscreen_pass(WebGPURenderContext* context);
void render_webgpu_run_blur(WebGPURenderContext* context, float blur_x, float blur_y, u8 quality, float strength, float r, float g, float b, float a, int colorize);
void render_webgpu_composite_filtered(WebGPURenderContext* context, float offset_x, float offset_y, float tint_r, float tint_g, float tint_b, float tint_a);
void render_webgpu_ensure_filter_resources(WebGPURenderContext* context);
void render_webgpu_free(SWFAppContext* app_context, WebGPURenderContext* context);

#ifdef HEADLESS_GRAPHICS
// Headless rendering: framebuffer capture and PNG output
void render_webgpu_request_capture(WebGPURenderContext* context);
int render_webgpu_save_png(WebGPURenderContext* context, const char* path);
#endif
