// WebGPU rendering backend for SWFModernRuntime.
// Implements the same API surface as flashbang.c using the standardized
// webgpu.h C API. Works for both native (Dawn/wgpu-native) and WASM (emdawnwebgpu).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include <common.h>
#include <render_webgpu.h>
#include <swf.h>
#include <heap.h>

#ifndef __EMSCRIPTEN__
#include <SDL3/SDL.h>
#include "sdl3webgpu.h"
#else
#include <emscripten.h>
#include <emscripten/html5.h>
#endif

// Helper: convert C string to WGPUStringView for descriptor labels.
#define WGPU_LABEL(s) ((WGPUStringView){.data = (s), .length = WGPU_STRLEN})

// ---------------------------------------------------------------------------
// Embedded WGSL shader sources
// ---------------------------------------------------------------------------

static const char* vertex_wgsl =
"@group(0) @binding(0) var<storage, read> transforms: array<mat4x4f>;\n"
"@group(0) @binding(1) var<storage, read> colors: array<vec4f>;\n"
"@group(0) @binding(2) var<storage, read> inv_mats: array<mat4x4f>;\n"
"@group(0) @binding(3) var<storage, read> bitmap_sizes: array<vec2u>;\n"
"\n"
"struct StageTransform { matrix: mat4x4f };\n"
"@group(1) @binding(0) var<uniform> stage_transform: StageTransform;\n"
"\n"
"struct TransformID { id: u32 };\n"
"@group(1) @binding(1) var<uniform> current_transform: TransformID;\n"
"\n"
"struct VertexInput {\n"
"  @location(0) position: vec2f,\n"
"  @location(1) style: vec2u,\n"
"};\n"
"struct VertexOutput {\n"
"  @builtin(position) position: vec4f,\n"
"  @location(0) @interpolate(flat) v_style_type: u32,\n"
"  @location(1) @interpolate(flat) v_style_id: u32,\n"
"  @location(2) v_args: vec4f,\n"
"};\n"
"\n"
"@vertex\n"
"fn vs_main(in: VertexInput) -> VertexOutput {\n"
"  var out: VertexOutput;\n"
"  let transform = transforms[current_transform.id];\n"
"  let pos = vec4f(in.position, 0.0, 1.0);\n"
"  out.v_style_type = in.style.x;\n"
"  out.v_style_id = in.style.y & 0xFFFFu;\n"
"  let style_upper = (in.style.y >> 16u) & 0xFFFFu;\n"
"  out.position = stage_transform.matrix * transform * pos;\n"
"  if (out.v_style_type == 0x00u) {\n"
"    out.v_args = colors[out.v_style_id];\n"
"  } else if ((out.v_style_type & 0xF0u) == 0x10u) {\n"
"    let inv_pos = inv_mats[out.v_style_id] * pos;\n"
"    out.v_args = vec4f(inv_pos.xy, 0.0, 0.0);\n"
"  } else if ((out.v_style_type & 0xF0u) == 0x40u) {\n"
"    let inv_pos = inv_mats[style_upper] * pos;\n"
"    let sizes = bitmap_sizes[out.v_style_id];\n"
"    out.v_args = vec4f(inv_pos.x / f32(sizes.x), inv_pos.y / f32(sizes.y), 0.0, 0.0);\n"
"  } else {\n"
"    out.v_args = vec4f(0.0);\n"
"  }\n"
"  return out;\n"
"}\n";

static const char* fragment_wgsl =
"@group(2) @binding(0) var gradient_tex: texture_2d_array<f32>;\n"
"@group(2) @binding(1) var gradient_samp: sampler;\n"
"@group(2) @binding(2) var bitmap_tex: texture_2d_array<f32>;\n"
"@group(2) @binding(3) var bitmap_samp: sampler;\n"
"\n"
"struct FragmentInput {\n"
"  @location(0) @interpolate(flat) v_style_type: u32,\n"
"  @location(1) @interpolate(flat) v_style_id: u32,\n"
"  @location(2) v_args: vec4f,\n"
"};\n"
"\n"
"fn linear_t(v_args: vec4f) -> f32 { return (v_args.x + 16384.0) / 32768.0; }\n"
"fn radial_t(v_args: vec4f) -> f32 { return distance(v_args.xy, vec2f(0.0)) / 16384.0; }\n"
"\n"
"@fragment\n"
"fn fs_main(in: FragmentInput) -> @location(0) vec4f {\n"
"  if (in.v_style_type == 0x00u) {\n"
"    return in.v_args;\n"
"  } else if (in.v_style_type == 0x10u) {\n"
"    return textureSample(gradient_tex, gradient_samp, vec2f(linear_t(in.v_args), 0.5), i32(in.v_style_id));\n"
"  } else if (in.v_style_type == 0x12u) {\n"
"    return textureSample(gradient_tex, gradient_samp, vec2f(radial_t(in.v_args), 0.5), i32(in.v_style_id));\n"
"  } else if (in.v_style_type == 0x41u) {\n"
"    return textureSample(bitmap_tex, bitmap_samp, in.v_args.xy, i32(in.v_style_id));\n"
"  }\n"
"  return vec4f(0.0);\n"
"}\n";

static const char* compute_wgsl =
"@group(0) @binding(0) var<storage, read> gradmats: array<mat4x4f>;\n"
"@group(1) @binding(0) var<storage, read_write> inv_gradmats: array<mat4x4f>;\n"
"\n"
"fn mat4_inverse(m: mat4x4f) -> mat4x4f {\n"
"  let a00 = m[0][0]; let a01 = m[0][1]; let a02 = m[0][2]; let a03 = m[0][3];\n"
"  let a10 = m[1][0]; let a11 = m[1][1]; let a12 = m[1][2]; let a13 = m[1][3];\n"
"  let a20 = m[2][0]; let a21 = m[2][1]; let a22 = m[2][2]; let a23 = m[2][3];\n"
"  let a30 = m[3][0]; let a31 = m[3][1]; let a32 = m[3][2]; let a33 = m[3][3];\n"
"  let s0 = a00*a11 - a10*a01; let s1 = a00*a12 - a10*a02;\n"
"  let s2 = a00*a13 - a10*a03; let s3 = a01*a12 - a11*a02;\n"
"  let s4 = a01*a13 - a11*a03; let s5 = a02*a13 - a12*a03;\n"
"  let c5 = a22*a33 - a32*a23; let c4 = a21*a33 - a31*a23;\n"
"  let c3 = a21*a32 - a31*a22; let c2 = a20*a33 - a30*a23;\n"
"  let c1 = a20*a32 - a30*a22; let c0 = a20*a31 - a30*a21;\n"
"  let det = s0*c5 - s1*c4 + s2*c3 + s3*c2 - s4*c1 + s5*c0;\n"
"  let inv_det = 1.0 / det;\n"
"  return mat4x4f(\n"
"    vec4f( (a11*c5-a12*c4+a13*c3)*inv_det, (-a01*c5+a02*c4-a03*c3)*inv_det,\n"
"           (a31*s5-a32*s4+a33*s3)*inv_det, (-a21*s5+a22*s4-a23*s3)*inv_det),\n"
"    vec4f((-a10*c5+a12*c2-a13*c1)*inv_det, ( a00*c5-a02*c2+a03*c1)*inv_det,\n"
"          (-a30*s5+a32*s2-a33*s1)*inv_det, ( a20*s5-a22*s2+a23*s1)*inv_det),\n"
"    vec4f( (a10*c4-a11*c2+a13*c0)*inv_det, (-a00*c4+a01*c2-a03*c0)*inv_det,\n"
"           (a30*s4-a31*s2+a33*s0)*inv_det, (-a20*s4+a21*s2-a23*s0)*inv_det),\n"
"    vec4f((-a10*c3+a11*c1-a12*c0)*inv_det, ( a00*c3-a01*c1+a02*c0)*inv_det,\n"
"          (-a30*s3+a31*s1-a32*s0)*inv_det, ( a20*s3-a21*s1+a22*s0)*inv_det),\n"
"  );\n"
"}\n"
"\n"
"@compute @workgroup_size(64, 1, 1)\n"
"fn cs_main(@builtin(global_invocation_id) gid: vec3u) {\n"
"  let mat_i = gid.x;\n"
"  inv_gradmats[mat_i] = mat4_inverse(gradmats[mat_i]);\n"
"}\n";

// ---------------------------------------------------------------------------
// Helper: create a WGPUBuffer and optionally upload data
// ---------------------------------------------------------------------------
static WGPUBuffer create_buffer(WGPUDevice device, WGPUQueue queue,
                                WGPUBufferUsage usage,
                                const void* data, size_t size,
                                const char* label)
{
	// Ensure minimum buffer size of 64 bytes. WebGPU requires non-zero buffers,
	// and shader bindings like array<mat4x4f> require at least 64 bytes even
	// when no data is present.
	if (size < 64) size = 64;

	WGPUBufferDescriptor desc = {0};
	desc.label = WGPU_LABEL(label);
	desc.size = size;
	desc.usage = usage;
	if (data)
		desc.usage |= WGPUBufferUsage_CopyDst;
	desc.mappedAtCreation = false;

	WGPUBuffer buffer = wgpuDeviceCreateBuffer(device, &desc);
	if (data && size > 0)
	{
		wgpuQueueWriteBuffer(queue, buffer, 0, data, size);
	}
	return buffer;
}

// ---------------------------------------------------------------------------
// Helper: create a shader module from WGSL source
// ---------------------------------------------------------------------------
static WGPUShaderModule create_shader(WGPUDevice device, const char* wgsl,
                                      const char* label)
{
	WGPUShaderSourceWGSL wgsl_src = {0};
	wgsl_src.chain.sType = WGPUSType_ShaderSourceWGSL;
	wgsl_src.code.data = wgsl;
	wgsl_src.code.length = strlen(wgsl);

	WGPUShaderModuleDescriptor desc = {0};
	desc.label = WGPU_LABEL(label);
	desc.nextInChain = (const WGPUChainedStruct*)&wgsl_src;

	return wgpuDeviceCreateShaderModule(device, &desc);
}

// ---------------------------------------------------------------------------
// Adapter/device request helpers
// ---------------------------------------------------------------------------
// The webgpu.h callback API varies across implementations. These helpers use
// the standard callback-based pattern. On native (Dawn/wgpu-native), the
// callback typically fires synchronously. On WASM with emdawnwebgpu + Asyncify,
// control returns to the browser until the callback fires.

static void on_adapter_ready(WGPURequestAdapterStatus status,
                             WGPUAdapter adapter,
                             struct WGPUStringView message,
                             void* userdata1, void* userdata2)
{
	(void)message;
	(void)userdata2;
	WebGPURenderContext* ctx = (WebGPURenderContext*)userdata1;
	if (status == WGPURequestAdapterStatus_Success)
	{
		ctx->adapter = adapter;
	}
	else
	{
		fprintf(stderr, "Failed to get WebGPU adapter (status %d)\n", (int)status);
	}
}

static void request_adapter_sync(WebGPURenderContext* ctx,
                                 const WGPURequestAdapterOptions* opts)
{
	WGPURequestAdapterCallbackInfo cb_info = {0};
	cb_info.mode = WGPUCallbackMode_AllowSpontaneous;
	cb_info.callback = on_adapter_ready;
	cb_info.userdata1 = ctx;

	WGPUFuture future = wgpuInstanceRequestAdapter(ctx->instance, opts, cb_info);

#ifdef __EMSCRIPTEN__
	// In the browser, async WebGPU operations need us to yield back to
	// the event loop so the browser can process the request.
	while (ctx->adapter == NULL)
	{
		emscripten_sleep(10);
	}
#else
	// Native: poll until the callback fires
	WGPUFutureWaitInfo wait_info = {0};
	wait_info.future = future;
	wgpuInstanceWaitAny(ctx->instance, 1, &wait_info, UINT64_MAX);
#endif
}

static void on_device_ready(WGPURequestDeviceStatus status,
                            WGPUDevice device,
                            struct WGPUStringView message,
                            void* userdata1, void* userdata2)
{
	(void)message;
	(void)userdata2;
	WebGPURenderContext* ctx = (WebGPURenderContext*)userdata1;
	if (status == WGPURequestDeviceStatus_Success)
	{
		ctx->device = device;
		ctx->queue = wgpuDeviceGetQueue(device);
	}
	else
	{
		fprintf(stderr, "Failed to get WebGPU device (status %d)\n", (int)status);
	}
}

static void request_device_sync(WebGPURenderContext* ctx,
                                const WGPUDeviceDescriptor* desc)
{
	WGPURequestDeviceCallbackInfo cb_info = {0};
	cb_info.mode = WGPUCallbackMode_AllowSpontaneous;
	cb_info.callback = on_device_ready;
	cb_info.userdata1 = ctx;

	WGPUFuture future = wgpuAdapterRequestDevice(ctx->adapter, desc, cb_info);

#ifdef __EMSCRIPTEN__
	while (ctx->device == NULL)
	{
		emscripten_sleep(10);
	}
#else
	WGPUFutureWaitInfo wait_info = {0};
	wait_info.future = future;
	wgpuInstanceWaitAny(ctx->instance, 1, &wait_info, UINT64_MAX);
#endif
}

// ---------------------------------------------------------------------------
// Helper: create a 1x1 RGBA dummy texture
// ---------------------------------------------------------------------------
static void create_dummy_texture(WebGPURenderContext* ctx)
{
	WGPUTextureDescriptor tex_desc = {0};
	tex_desc.label = WGPU_LABEL("dummy_tex");
	tex_desc.dimension = WGPUTextureDimension_2D;
	tex_desc.size = (WGPUExtent3D){1, 1, 1};
	tex_desc.format = WGPUTextureFormat_RGBA8Unorm;
	tex_desc.mipLevelCount = 1;
	tex_desc.sampleCount = 1;
	tex_desc.usage = WGPUTextureUsage_TextureBinding | WGPUTextureUsage_CopyDst;
	ctx->dummy_tex = wgpuDeviceCreateTexture(ctx->device, &tex_desc);

	WGPUTextureViewDescriptor view_desc = {0};
	view_desc.dimension = WGPUTextureViewDimension_2DArray;
	view_desc.arrayLayerCount = 1;
	view_desc.mipLevelCount = 1;
	ctx->dummy_tex_view = wgpuTextureCreateView(ctx->dummy_tex, &view_desc);

	WGPUSamplerDescriptor samp_desc = {0};
	samp_desc.label = WGPU_LABEL("dummy_sampler");
	samp_desc.addressModeU = WGPUAddressMode_ClampToEdge;
	samp_desc.addressModeV = WGPUAddressMode_ClampToEdge;
	samp_desc.magFilter = WGPUFilterMode_Nearest;
	samp_desc.minFilter = WGPUFilterMode_Nearest;
	samp_desc.maxAnisotropy = 1;
	ctx->dummy_sampler = wgpuDeviceCreateSampler(ctx->device, &samp_desc);

	// Upload a single white pixel
	u32 white = 0xFFFFFFFF;
	WGPUTexelCopyTextureInfo dest = {0};
	dest.texture = ctx->dummy_tex;
	WGPUTexelCopyBufferLayout layout = {0};
	layout.bytesPerRow = 4;
	layout.rowsPerImage = 1;
	WGPUExtent3D extent = {1, 1, 1};
	wgpuQueueWriteTexture(ctx->queue, &dest, &white, 4, &layout, &extent);
}

// ---------------------------------------------------------------------------
// Forward declarations for init sub-steps
// ---------------------------------------------------------------------------
static void create_buffers_and_upload(WebGPURenderContext* ctx);
static void create_textures(WebGPURenderContext* ctx);
static void create_pipelines(WebGPURenderContext* ctx);
static void create_bind_groups(WebGPURenderContext* ctx);
static void run_compute_pass(WebGPURenderContext* ctx);

// ---------------------------------------------------------------------------
// render_webgpu_new
// ---------------------------------------------------------------------------
WebGPURenderContext* render_webgpu_new(void)
{
	WebGPURenderContext* ctx = calloc(1, sizeof(WebGPURenderContext));
	return ctx;
}

// ---------------------------------------------------------------------------
// render_webgpu_init
// ---------------------------------------------------------------------------
void render_webgpu_init(SWFAppContext* app_context, WebGPURenderContext* ctx)
{
	ctx->current_bitmap = 0;
	ctx->bitmap_sizes = (u32*)HALLOC(2 * sizeof(u32) * ctx->bitmap_count);

	// --- Create WebGPU instance ---
	WGPUInstanceDescriptor inst_desc = {0};
	ctx->instance = wgpuCreateInstance(&inst_desc);
	assert(ctx->instance != NULL);

	// --- Create surface ---
#ifdef __EMSCRIPTEN__
	WGPUEmscriptenSurfaceSourceCanvasHTMLSelector canvas_src = {0};
	canvas_src.chain.sType = WGPUSType_EmscriptenSurfaceSourceCanvasHTMLSelector;
	canvas_src.selector = WGPU_LABEL("#canvas");

	WGPUSurfaceDescriptor surf_desc = {0};
	surf_desc.nextInChain = (const WGPUChainedStruct*)&canvas_src;
	ctx->surface = wgpuInstanceCreateSurface(ctx->instance, &surf_desc);
#else
	// Native: create SDL window and use sdl3webgpu bridge
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr, "Failed to init SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	ctx->window = SDL_CreateWindow("TestSWFRecompiled", ctx->width, ctx->height,
	                               SDL_WINDOW_RESIZABLE);
	assert(ctx->window != NULL);

	ctx->surface = SDL_GetWGPUSurface(ctx->instance, ctx->window);
#endif
	assert(ctx->surface != NULL);

	// --- Request adapter ---
	{
		WGPURequestAdapterOptions opts = {0};
		opts.compatibleSurface = ctx->surface;
		opts.powerPreference = WGPUPowerPreference_HighPerformance;

		request_adapter_sync(ctx, &opts);
		assert(ctx->adapter != NULL);
	}

	// --- Request device ---
	{
		WGPUDeviceDescriptor dev_desc = {0};
		dev_desc.label = WGPU_LABEL("swf_device");
		// Request defaults — no special limits or features needed
		dev_desc.defaultQueue.label = WGPU_LABEL("swf_queue");

		request_device_sync(ctx, &dev_desc);
		assert(ctx->device != NULL);
	}

	// --- Configure surface ---
	ctx->surface_format = WGPUTextureFormat_BGRA8Unorm;

	WGPUSurfaceConfiguration surf_config = {0};
	surf_config.device = ctx->device;
	surf_config.format = ctx->surface_format;
	surf_config.usage = WGPUTextureUsage_RenderAttachment;
	surf_config.alphaMode = WGPUCompositeAlphaMode_Auto;
	surf_config.width = ctx->width;
	surf_config.height = ctx->height;
	surf_config.presentMode = WGPUPresentMode_Fifo;
	wgpuSurfaceConfigure(ctx->surface, &surf_config);

	// --- Create all GPU resources ---
	create_dummy_texture(ctx);
	create_buffers_and_upload(ctx);
	create_textures(ctx);
	create_pipelines(ctx);
	create_bind_groups(ctx);

	// --- Run compute pass to invert gradient matrices ---
	size_t num_gradients = ctx->uninv_mat_data_size / (16 * sizeof(float));
	if (num_gradients > 0)
	{
		run_compute_pass(ctx);
		// Recreate bind groups after compute (inv_mat_buffer now has data)
		// Actually the buffer is the same, just the contents changed, so
		// the bind group remains valid.
	}
}

// ---------------------------------------------------------------------------
// create_buffers_and_upload: create GPU buffers and upload static data
// ---------------------------------------------------------------------------
static void create_buffers_and_upload(WebGPURenderContext* ctx)
{
	// Vertex buffer (shape geometry)
	ctx->vertex_buffer = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Vertex | WGPUBufferUsage_CopyDst,
		ctx->shape_data, ctx->shape_data_size, "vertex_buffer");

	// Storage buffers
	ctx->xform_buffer = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
		ctx->transform_data, ctx->transform_data_size, "xform_buffer");

	ctx->color_buffer = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
		ctx->color_data, ctx->color_data_size, "color_buffer");

	ctx->uninv_mat_buffer = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
		ctx->uninv_mat_data, ctx->uninv_mat_data_size, "uninv_mat_buffer");

	ctx->inv_mat_buffer = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
		NULL, ctx->uninv_mat_data_size, "inv_mat_buffer");

	ctx->bitmap_sizes_buffer = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
		NULL, 2 * sizeof(u32) * ctx->bitmap_count, "bitmap_sizes_buffer");

	ctx->cxform_buffer = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
		ctx->cxform_data, ctx->cxform_data_size, "cxform_buffer");

	// Uniform buffers (small, updated per-frame/per-draw)
	ctx->stage_to_ndc_buf = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst,
		NULL, 64, "stage_to_ndc_uniform");  // mat4 = 64 bytes

	ctx->transform_id_buf = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst,
		NULL, 16, "transform_id_uniform");  // u32 padded to 16 bytes (min uniform alignment)

	ctx->extra_transform_id_buf = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst,
		NULL, 16, "extra_transform_id_uniform");  // u32 padded to 16 bytes

	ctx->extra_transform_buf = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst,
		NULL, 64, "extra_transform_uniform");  // mat4 = 64 bytes

	ctx->cxform_id_buf = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst,
		NULL, 16, "cxform_id_uniform");  // u32 padded to 16 bytes

	ctx->cxform_uniform_buf = create_buffer(ctx->device, ctx->queue,
		WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst,
		NULL, 80, "cxform_uniform");  // 20 floats = 80 bytes
}

// ---------------------------------------------------------------------------
// create_textures: gradient texture array, bitmap texture array, MSAA
// ---------------------------------------------------------------------------
static void create_textures(WebGPURenderContext* ctx)
{
	size_t sizeof_gradient = 256 * 4 * sizeof(float);
	size_t num_gradients = ctx->gradient_data_size / sizeof_gradient;

	// --- Gradient texture array ---
	if (num_gradients > 0)
	{
		WGPUTextureDescriptor tex_desc = {0};
		tex_desc.label = WGPU_LABEL("gradient_tex");
		tex_desc.dimension = WGPUTextureDimension_2D;
		tex_desc.size = (WGPUExtent3D){256, 1, (u32)num_gradients};
		tex_desc.format = WGPUTextureFormat_RGBA8Unorm;
		tex_desc.mipLevelCount = 1;
		tex_desc.sampleCount = 1;
		tex_desc.usage = WGPUTextureUsage_TextureBinding | WGPUTextureUsage_CopyDst;
		ctx->gradient_tex = wgpuDeviceCreateTexture(ctx->device, &tex_desc);

		WGPUTextureViewDescriptor view_desc = {0};
		view_desc.dimension = WGPUTextureViewDimension_2DArray;
		view_desc.arrayLayerCount = (u32)num_gradients;
		view_desc.mipLevelCount = 1;
		ctx->gradient_tex_view = wgpuTextureCreateView(ctx->gradient_tex, &view_desc);

		// Upload gradient data (each gradient = 256 RGBA pixels = 1024 bytes)
		// Note: gradient_data is stored as float RGBA (256 * 4 * sizeof(float) per gradient)
		// but the texture is RGBA8Unorm, so the data is actually u8 per channel.
		// Actually in flashbang.c, gradient_data_size / sizeof_gradient gives count,
		// and sizeof_gradient = 256*4*sizeof(float). But the texture is RGBA8.
		// The upstream stores gradient pixels as floats but uploads them to an
		// R8G8B8A8 texture. So the data is actually packed u8 RGBA, and
		// sizeof_gradient is just used for counting.
		// Let's check: 256 pixels * 4 bytes/pixel = 1024 bytes per gradient as RGBA8.
		// But sizeof_gradient = 256*4*4 = 4096. So the data is float per channel.
		// flashbang.c uploads it directly to RGBA8 texture... this suggests
		// the data is actually u8 despite sizeof_gradient being calculated with sizeof(float).
		// Let's match flashbang: upload gradient_data directly.
		WGPUTexelCopyTextureInfo dest = {0};
		dest.texture = ctx->gradient_tex;
		WGPUTexelCopyBufferLayout layout = {0};
		layout.bytesPerRow = 256 * 4; // 256 pixels * 4 bytes (RGBA8)
		layout.rowsPerImage = 1;
		WGPUExtent3D extent = {256, 1, (u32)num_gradients};

		// The gradient data size per layer needs to match RGBA8 = 1024 bytes per layer
		// Total upload = num_gradients * 1024 bytes
		wgpuQueueWriteTexture(ctx->queue, &dest, ctx->gradient_data,
		                      num_gradients * 256 * 4, &layout, &extent);

		WGPUSamplerDescriptor samp_desc = {0};
		samp_desc.label = WGPU_LABEL("gradient_sampler");
		samp_desc.addressModeU = WGPUAddressMode_ClampToEdge;
		samp_desc.addressModeV = WGPUAddressMode_ClampToEdge;
		samp_desc.magFilter = WGPUFilterMode_Linear;
		samp_desc.minFilter = WGPUFilterMode_Linear;
		samp_desc.maxAnisotropy = 1;
		ctx->gradient_sampler = wgpuDeviceCreateSampler(ctx->device, &samp_desc);
	}

	// --- Bitmap texture array ---
	if (ctx->bitmap_count > 0)
	{
		u32 bw = (u32)(ctx->bitmap_highest_w + 1);
		u32 bh = (u32)(ctx->bitmap_highest_h + 1);

		WGPUTextureDescriptor tex_desc = {0};
		tex_desc.label = WGPU_LABEL("bitmap_tex");
		tex_desc.dimension = WGPUTextureDimension_2D;
		tex_desc.size = (WGPUExtent3D){bw, bh, (u32)ctx->bitmap_count};
		tex_desc.format = WGPUTextureFormat_RGBA8Unorm;
		tex_desc.mipLevelCount = 1;
		tex_desc.sampleCount = 1;
		tex_desc.usage = WGPUTextureUsage_TextureBinding | WGPUTextureUsage_CopyDst;
		ctx->bitmap_tex = wgpuDeviceCreateTexture(ctx->device, &tex_desc);

		WGPUTextureViewDescriptor view_desc = {0};
		view_desc.dimension = WGPUTextureViewDimension_2DArray;
		view_desc.arrayLayerCount = (u32)ctx->bitmap_count;
		view_desc.mipLevelCount = 1;
		ctx->bitmap_tex_view = wgpuTextureCreateView(ctx->bitmap_tex, &view_desc);

		WGPUSamplerDescriptor samp_desc = {0};
		samp_desc.label = WGPU_LABEL("bitmap_sampler");
		samp_desc.addressModeU = WGPUAddressMode_ClampToEdge;
		samp_desc.addressModeV = WGPUAddressMode_ClampToEdge;
		samp_desc.magFilter = WGPUFilterMode_Linear;
		samp_desc.minFilter = WGPUFilterMode_Linear;
		samp_desc.maxAnisotropy = 1;
		ctx->bitmap_sampler = wgpuDeviceCreateSampler(ctx->device, &samp_desc);
	}

	// --- MSAA texture (4x) ---
	{
		WGPUTextureDescriptor tex_desc = {0};
		tex_desc.label = WGPU_LABEL("msaa_texture");
		tex_desc.dimension = WGPUTextureDimension_2D;
		tex_desc.size = (WGPUExtent3D){(u32)ctx->width, (u32)ctx->height, 1};
		tex_desc.format = ctx->surface_format;
		tex_desc.mipLevelCount = 1;
		tex_desc.sampleCount = 4;
		tex_desc.usage = WGPUTextureUsage_RenderAttachment;
		ctx->msaa_texture = wgpuDeviceCreateTexture(ctx->device, &tex_desc);

		WGPUTextureViewDescriptor view_desc = {0};
		view_desc.mipLevelCount = 1;
		view_desc.arrayLayerCount = 1;
		ctx->msaa_view = wgpuTextureCreateView(ctx->msaa_texture, &view_desc);
	}
}

// ---------------------------------------------------------------------------
// create_pipelines: render pipeline + compute pipeline
// ---------------------------------------------------------------------------
static void create_pipelines(WebGPURenderContext* ctx)
{
	// --- Bind group layouts ---

	// Group 0: vertex storage buffers
	WGPUBindGroupLayoutEntry bg0_entries[4] = {0};
	for (int i = 0; i < 4; i++)
	{
		bg0_entries[i].binding = i;
		bg0_entries[i].visibility = WGPUShaderStage_Vertex;
		bg0_entries[i].buffer.type = WGPUBufferBindingType_ReadOnlyStorage;
	}

	WGPUBindGroupLayoutDescriptor bg0_desc = {0};
	bg0_desc.label = WGPU_LABEL("vertex_storage_bgl");
	bg0_desc.entryCount = 4;
	bg0_desc.entries = bg0_entries;
	ctx->vertex_storage_bgl = wgpuDeviceCreateBindGroupLayout(ctx->device, &bg0_desc);

	// Group 1: vertex uniforms
	WGPUBindGroupLayoutEntry bg1_entries[2] = {0};
	bg1_entries[0].binding = 0;
	bg1_entries[0].visibility = WGPUShaderStage_Vertex;
	bg1_entries[0].buffer.type = WGPUBufferBindingType_Uniform;
	bg1_entries[1].binding = 1;
	bg1_entries[1].visibility = WGPUShaderStage_Vertex;
	bg1_entries[1].buffer.type = WGPUBufferBindingType_Uniform;

	WGPUBindGroupLayoutDescriptor bg1_desc = {0};
	bg1_desc.label = WGPU_LABEL("vertex_uniform_bgl");
	bg1_desc.entryCount = 2;
	bg1_desc.entries = bg1_entries;
	ctx->vertex_uniform_bgl = wgpuDeviceCreateBindGroupLayout(ctx->device, &bg1_desc);

	// Group 2: fragment texture + sampler (4 entries: gradient tex, gradient samp,
	// bitmap tex, bitmap samp)
	WGPUBindGroupLayoutEntry bg2_entries[4] = {0};
	bg2_entries[0].binding = 0;
	bg2_entries[0].visibility = WGPUShaderStage_Fragment;
	bg2_entries[0].texture.sampleType = WGPUTextureSampleType_Float;
	bg2_entries[0].texture.viewDimension = WGPUTextureViewDimension_2DArray;
	bg2_entries[1].binding = 1;
	bg2_entries[1].visibility = WGPUShaderStage_Fragment;
	bg2_entries[1].sampler.type = WGPUSamplerBindingType_Filtering;
	bg2_entries[2].binding = 2;
	bg2_entries[2].visibility = WGPUShaderStage_Fragment;
	bg2_entries[2].texture.sampleType = WGPUTextureSampleType_Float;
	bg2_entries[2].texture.viewDimension = WGPUTextureViewDimension_2DArray;
	bg2_entries[3].binding = 3;
	bg2_entries[3].visibility = WGPUShaderStage_Fragment;
	bg2_entries[3].sampler.type = WGPUSamplerBindingType_Filtering;

	WGPUBindGroupLayoutDescriptor bg2_desc = {0};
	bg2_desc.label = WGPU_LABEL("fragment_sampler_bgl");
	bg2_desc.entryCount = 4;
	bg2_desc.entries = bg2_entries;
	ctx->fragment_sampler_bgl = wgpuDeviceCreateBindGroupLayout(ctx->device, &bg2_desc);

	// Render pipeline layout
	WGPUBindGroupLayout render_bgls[3] = {
		ctx->vertex_storage_bgl,
		ctx->vertex_uniform_bgl,
		ctx->fragment_sampler_bgl,
	};
	WGPUPipelineLayoutDescriptor pl_desc = {0};
	pl_desc.label = WGPU_LABEL("render_pipeline_layout");
	pl_desc.bindGroupLayoutCount = 3;
	pl_desc.bindGroupLayouts = render_bgls;
	ctx->render_pipeline_layout = wgpuDeviceCreatePipelineLayout(ctx->device, &pl_desc);

	// --- Create shader modules ---
	WGPUShaderModule vs_module = create_shader(ctx->device, vertex_wgsl, "vertex_shader");
	WGPUShaderModule fs_module = create_shader(ctx->device, fragment_wgsl, "fragment_shader");

	// --- Render pipeline ---
	WGPUVertexAttribute attrs[2] = {0};
	attrs[0].format = WGPUVertexFormat_Float32x2;  // position
	attrs[0].offset = 0;
	attrs[0].shaderLocation = 0;
	attrs[1].format = WGPUVertexFormat_Uint32x2;   // style
	attrs[1].offset = 2 * sizeof(u32);
	attrs[1].shaderLocation = 1;

	WGPUVertexBufferLayout vb_layout = {0};
	vb_layout.arrayStride = 4 * sizeof(u32);  // 16 bytes per vertex
	vb_layout.stepMode = WGPUVertexStepMode_Vertex;
	vb_layout.attributeCount = 2;
	vb_layout.attributes = attrs;

	WGPUBlendState blend = {0};
	blend.color.srcFactor = WGPUBlendFactor_SrcAlpha;
	blend.color.dstFactor = WGPUBlendFactor_OneMinusSrcAlpha;
	blend.color.operation = WGPUBlendOperation_Add;
	blend.alpha.srcFactor = WGPUBlendFactor_SrcAlpha;
	blend.alpha.dstFactor = WGPUBlendFactor_OneMinusSrcAlpha;
	blend.alpha.operation = WGPUBlendOperation_Add;

	WGPUColorTargetState color_target = {0};
	color_target.format = ctx->surface_format;
	color_target.blend = &blend;
	color_target.writeMask = WGPUColorWriteMask_All;

	WGPUFragmentState frag_state = {0};
	frag_state.module = fs_module;
	frag_state.entryPoint.data = "fs_main";
	frag_state.entryPoint.length = 7;
	frag_state.targetCount = 1;
	frag_state.targets = &color_target;

	WGPURenderPipelineDescriptor rp_desc = {0};
	rp_desc.label = WGPU_LABEL("render_pipeline");
	rp_desc.layout = ctx->render_pipeline_layout;
	rp_desc.vertex.module = vs_module;
	rp_desc.vertex.entryPoint.data = "vs_main";
	rp_desc.vertex.entryPoint.length = 7;
	rp_desc.vertex.bufferCount = 1;
	rp_desc.vertex.buffers = &vb_layout;
	rp_desc.fragment = &frag_state;
	rp_desc.primitive.topology = WGPUPrimitiveTopology_TriangleList;
	rp_desc.multisample.count = 4;
	rp_desc.multisample.mask = ~0u;

	ctx->render_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
	assert(ctx->render_pipeline != NULL);

	wgpuShaderModuleRelease(vs_module);
	wgpuShaderModuleRelease(fs_module);

	// --- Compute pipeline (for gradient matrix inversion) ---
	size_t num_gradients = ctx->uninv_mat_data_size / (16 * sizeof(float));
	if (num_gradients > 0)
	{
		WGPUBindGroupLayoutEntry comp0_entry = {0};
		comp0_entry.binding = 0;
		comp0_entry.visibility = WGPUShaderStage_Compute;
		comp0_entry.buffer.type = WGPUBufferBindingType_ReadOnlyStorage;

		WGPUBindGroupLayoutDescriptor comp0_desc = {0};
		comp0_desc.label = WGPU_LABEL("compute_read_bgl");
		comp0_desc.entryCount = 1;
		comp0_desc.entries = &comp0_entry;
		ctx->compute_read_bgl = wgpuDeviceCreateBindGroupLayout(ctx->device, &comp0_desc);

		WGPUBindGroupLayoutEntry comp1_entry = {0};
		comp1_entry.binding = 0;
		comp1_entry.visibility = WGPUShaderStage_Compute;
		comp1_entry.buffer.type = WGPUBufferBindingType_Storage;

		WGPUBindGroupLayoutDescriptor comp1_desc = {0};
		comp1_desc.label = WGPU_LABEL("compute_write_bgl");
		comp1_desc.entryCount = 1;
		comp1_desc.entries = &comp1_entry;
		ctx->compute_write_bgl = wgpuDeviceCreateBindGroupLayout(ctx->device, &comp1_desc);

		WGPUBindGroupLayout comp_bgls[2] = {ctx->compute_read_bgl, ctx->compute_write_bgl};
		WGPUPipelineLayoutDescriptor comp_pl_desc = {0};
		comp_pl_desc.label = WGPU_LABEL("compute_pipeline_layout");
		comp_pl_desc.bindGroupLayoutCount = 2;
		comp_pl_desc.bindGroupLayouts = comp_bgls;
		ctx->compute_pipeline_layout = wgpuDeviceCreatePipelineLayout(ctx->device, &comp_pl_desc);

		WGPUShaderModule cs_module = create_shader(ctx->device, compute_wgsl, "compute_shader");

		WGPUComputePipelineDescriptor cp_desc = {0};
		cp_desc.label = WGPU_LABEL("compute_pipeline");
		cp_desc.layout = ctx->compute_pipeline_layout;
		cp_desc.compute.module = cs_module;
		cp_desc.compute.entryPoint.data = "cs_main";
		cp_desc.compute.entryPoint.length = 7;

		ctx->compute_pipeline = wgpuDeviceCreateComputePipeline(ctx->device, &cp_desc);
		assert(ctx->compute_pipeline != NULL);

		wgpuShaderModuleRelease(cs_module);
	}
}

// ---------------------------------------------------------------------------
// create_bind_groups
// ---------------------------------------------------------------------------
static void create_bind_groups(WebGPURenderContext* ctx)
{
	// --- Group 0: vertex storage buffers ---
	WGPUBindGroupEntry bg0_entries[4] = {0};
	bg0_entries[0].binding = 0;
	bg0_entries[0].buffer = ctx->xform_buffer;
	bg0_entries[0].size = wgpuBufferGetSize(ctx->xform_buffer);
	bg0_entries[1].binding = 1;
	bg0_entries[1].buffer = ctx->color_buffer;
	bg0_entries[1].size = wgpuBufferGetSize(ctx->color_buffer);
	bg0_entries[2].binding = 2;
	bg0_entries[2].buffer = ctx->inv_mat_buffer;
	bg0_entries[2].size = wgpuBufferGetSize(ctx->inv_mat_buffer);
	bg0_entries[3].binding = 3;
	bg0_entries[3].buffer = ctx->bitmap_sizes_buffer;
	bg0_entries[3].size = wgpuBufferGetSize(ctx->bitmap_sizes_buffer);

	WGPUBindGroupDescriptor bg0_desc = {0};
	bg0_desc.label = WGPU_LABEL("vertex_storage_bg");
	bg0_desc.layout = ctx->vertex_storage_bgl;
	bg0_desc.entryCount = 4;
	bg0_desc.entries = bg0_entries;
	ctx->vertex_storage_bg = wgpuDeviceCreateBindGroup(ctx->device, &bg0_desc);

	// --- Group 1: vertex uniforms ---
	WGPUBindGroupEntry bg1_entries[2] = {0};
	bg1_entries[0].binding = 0;
	bg1_entries[0].buffer = ctx->stage_to_ndc_buf;
	bg1_entries[0].size = 64; // mat4
	bg1_entries[1].binding = 1;
	bg1_entries[1].buffer = ctx->transform_id_buf;
	bg1_entries[1].size = 16; // u32 padded

	WGPUBindGroupDescriptor bg1_desc = {0};
	bg1_desc.label = WGPU_LABEL("vertex_uniform_bg");
	bg1_desc.layout = ctx->vertex_uniform_bgl;
	bg1_desc.entryCount = 2;
	bg1_desc.entries = bg1_entries;
	ctx->vertex_uniform_bg = wgpuDeviceCreateBindGroup(ctx->device, &bg1_desc);

	// --- Group 2: fragment textures + samplers ---
	// Use dummy textures as fallback when gradients/bitmaps are absent
	WGPUTextureView grad_view = ctx->gradient_tex_view ? ctx->gradient_tex_view : ctx->dummy_tex_view;
	WGPUSampler grad_samp = ctx->gradient_sampler ? ctx->gradient_sampler : ctx->dummy_sampler;
	WGPUTextureView bmp_view = ctx->bitmap_tex_view ? ctx->bitmap_tex_view : ctx->dummy_tex_view;
	WGPUSampler bmp_samp = ctx->bitmap_sampler ? ctx->bitmap_sampler : ctx->dummy_sampler;

	WGPUBindGroupEntry bg2_entries[4] = {0};
	bg2_entries[0].binding = 0;
	bg2_entries[0].textureView = grad_view;
	bg2_entries[1].binding = 1;
	bg2_entries[1].sampler = grad_samp;
	bg2_entries[2].binding = 2;
	bg2_entries[2].textureView = bmp_view;
	bg2_entries[3].binding = 3;
	bg2_entries[3].sampler = bmp_samp;

	WGPUBindGroupDescriptor bg2_desc = {0};
	bg2_desc.label = WGPU_LABEL("fragment_sampler_bg");
	bg2_desc.layout = ctx->fragment_sampler_bgl;
	bg2_desc.entryCount = 4;
	bg2_desc.entries = bg2_entries;
	ctx->fragment_sampler_bg = wgpuDeviceCreateBindGroup(ctx->device, &bg2_desc);

	// --- Compute bind groups ---
	size_t num_gradients = ctx->uninv_mat_data_size / (16 * sizeof(float));
	if (num_gradients > 0)
	{
		WGPUBindGroupEntry comp0_entry = {0};
		comp0_entry.binding = 0;
		comp0_entry.buffer = ctx->uninv_mat_buffer;
		comp0_entry.size = wgpuBufferGetSize(ctx->uninv_mat_buffer);

		WGPUBindGroupDescriptor comp0_desc = {0};
		comp0_desc.label = WGPU_LABEL("compute_read_bg");
		comp0_desc.layout = ctx->compute_read_bgl;
		comp0_desc.entryCount = 1;
		comp0_desc.entries = &comp0_entry;
		ctx->compute_read_bg = wgpuDeviceCreateBindGroup(ctx->device, &comp0_desc);

		WGPUBindGroupEntry comp1_entry = {0};
		comp1_entry.binding = 0;
		comp1_entry.buffer = ctx->inv_mat_buffer;
		comp1_entry.size = wgpuBufferGetSize(ctx->inv_mat_buffer);

		WGPUBindGroupDescriptor comp1_desc = {0};
		comp1_desc.label = WGPU_LABEL("compute_write_bg");
		comp1_desc.layout = ctx->compute_write_bgl;
		comp1_desc.entryCount = 1;
		comp1_desc.entries = &comp1_entry;
		ctx->compute_write_bg = wgpuDeviceCreateBindGroup(ctx->device, &comp1_desc);
	}
}

// ---------------------------------------------------------------------------
// run_compute_pass: invert gradient matrices on the GPU
// ---------------------------------------------------------------------------
static void run_compute_pass(WebGPURenderContext* ctx)
{
	size_t num_gradients = ctx->uninv_mat_data_size / (16 * sizeof(float));
	if (num_gradients == 0) return;

	// Upload uninverted matrix data
	wgpuQueueWriteBuffer(ctx->queue, ctx->uninv_mat_buffer, 0,
	                     ctx->uninv_mat_data, ctx->uninv_mat_data_size);

	WGPUCommandEncoderDescriptor enc_desc = {0};
	enc_desc.label = WGPU_LABEL("compute_encoder");
	WGPUCommandEncoder encoder = wgpuDeviceCreateCommandEncoder(ctx->device, &enc_desc);

	WGPUComputePassEncoder pass = wgpuCommandEncoderBeginComputePass(encoder, NULL);
	wgpuComputePassEncoderSetPipeline(pass, ctx->compute_pipeline);
	wgpuComputePassEncoderSetBindGroup(pass, 0, ctx->compute_read_bg, 0, NULL);
	wgpuComputePassEncoderSetBindGroup(pass, 1, ctx->compute_write_bg, 0, NULL);

	u32 workgroups = (u32)((num_gradients + 63) / 64);
	wgpuComputePassEncoderDispatchWorkgroups(pass, workgroups, 1, 1);
	wgpuComputePassEncoderEnd(pass);

	WGPUCommandBufferDescriptor cmd_desc = {0};
	WGPUCommandBuffer cmd = wgpuCommandEncoderFinish(encoder, &cmd_desc);
	wgpuQueueSubmit(ctx->queue, 1, &cmd);

	wgpuCommandBufferRelease(cmd);
	wgpuComputePassEncoderRelease(pass);
	wgpuCommandEncoderRelease(encoder);
}

// ---------------------------------------------------------------------------
// render_webgpu_poll: check for quit events
// ---------------------------------------------------------------------------
int render_webgpu_poll(void)
{
#ifdef __EMSCRIPTEN__
	// In WASM, the browser handles events. Return 0 (keep running).
	return 0;
#else
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
			return 1;
		if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE)
			return 1;
	}
	return 0;
#endif
}

// ---------------------------------------------------------------------------
// render_webgpu_set_background
// ---------------------------------------------------------------------------
void render_webgpu_set_background(WebGPURenderContext* ctx, u8 r, u8 g, u8 b)
{
	ctx->red = r;
	ctx->green = g;
	ctx->blue = b;
}

// ---------------------------------------------------------------------------
// render_webgpu_open_pass
// ---------------------------------------------------------------------------
void render_webgpu_open_pass(WebGPURenderContext* ctx)
{
	// Get the current surface texture
	WGPUSurfaceTexture surf_tex;
	wgpuSurfaceGetCurrentTexture(ctx->surface, &surf_tex);
	if (surf_tex.status != WGPUSurfaceGetCurrentTextureStatus_SuccessOptimal &&
	    surf_tex.status != WGPUSurfaceGetCurrentTextureStatus_SuccessSuboptimal)
	{
		fprintf(stderr, "Failed to get surface texture\n");
		return;
	}

	ctx->surface_view = wgpuTextureCreateView(surf_tex.texture, NULL);

	// Create command encoder
	WGPUCommandEncoderDescriptor enc_desc = {0};
	enc_desc.label = WGPU_LABEL("frame_encoder");
	ctx->encoder = wgpuDeviceCreateCommandEncoder(ctx->device, &enc_desc);

	// Begin render pass with MSAA
	WGPURenderPassColorAttachment color_att = {0};
	color_att.depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
	color_att.view = ctx->msaa_view;
	color_att.resolveTarget = ctx->surface_view;
	color_att.loadOp = WGPULoadOp_Clear;
	color_att.storeOp = WGPUStoreOp_Discard; // MSAA texture discarded after resolve
	color_att.clearValue = (WGPUColor){
		ctx->red / 255.0, ctx->green / 255.0, ctx->blue / 255.0, 1.0
	};

	WGPURenderPassDescriptor rp_desc = {0};
	rp_desc.label = WGPU_LABEL("render_pass");
	rp_desc.colorAttachmentCount = 1;
	rp_desc.colorAttachments = &color_att;

	ctx->render_pass = wgpuCommandEncoderBeginRenderPass(ctx->encoder, &rp_desc);

	// Bind pipeline and static bind groups
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 0, ctx->vertex_storage_bg, 0, NULL);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 2, ctx->fragment_sampler_bg, 0, NULL);

	// Upload stage_to_ndc uniform
	wgpuQueueWriteBuffer(ctx->queue, ctx->stage_to_ndc_buf, 0,
	                     ctx->stage_to_ndc, 16 * sizeof(float));
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 1, ctx->vertex_uniform_bg, 0, NULL);

	// Initialize extra_transform_id to 0, extra_transform to identity,
	// cxform_id to 0 (matching flashbang_open_pass behavior)
	u32 identity_id[4] = {0, 0, 0, 0};
	static const float identity_mat[16] = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	static const float identity_cxform[20] = {
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	};

	wgpuQueueWriteBuffer(ctx->queue, ctx->extra_transform_id_buf, 0, identity_id, 16);
	wgpuQueueWriteBuffer(ctx->queue, ctx->extra_transform_buf, 0, identity_mat, 64);
	wgpuQueueWriteBuffer(ctx->queue, ctx->cxform_id_buf, 0, identity_id, 16);
	wgpuQueueWriteBuffer(ctx->queue, ctx->cxform_uniform_buf, 0, identity_cxform, 80);
}

// ---------------------------------------------------------------------------
// render_webgpu_draw_shape
// ---------------------------------------------------------------------------
void render_webgpu_draw_shape(WebGPURenderContext* ctx, size_t offset,
                              size_t num_verts, u32 transform_id)
{
	// Update transform_id uniform
	// Pad to 16 bytes (WGSL uniform minimum binding size)
	u32 id_data[4] = {transform_id, 0, 0, 0};
	wgpuQueueWriteBuffer(ctx->queue, ctx->transform_id_buf, 0, id_data, 16);

	// Re-bind group 1 with updated uniform
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 1, ctx->vertex_uniform_bg, 0, NULL);

	// Set vertex buffer with byte offset
	uint64_t byte_offset = offset * 4 * sizeof(u32);
	uint64_t byte_size = num_verts * 4 * sizeof(u32);
	wgpuRenderPassEncoderSetVertexBuffer(ctx->render_pass, 0, ctx->vertex_buffer,
	                                     byte_offset, byte_size);

	// Draw
	wgpuRenderPassEncoderDraw(ctx->render_pass, (u32)num_verts, 1, 0, 0);
}

// ---------------------------------------------------------------------------
// render_webgpu_close_pass
// ---------------------------------------------------------------------------
void render_webgpu_close_pass(WebGPURenderContext* ctx)
{
	wgpuRenderPassEncoderEnd(ctx->render_pass);

	WGPUCommandBufferDescriptor cmd_desc = {0};
	WGPUCommandBuffer cmd = wgpuCommandEncoderFinish(ctx->encoder, &cmd_desc);
	wgpuQueueSubmit(ctx->queue, 1, &cmd);

#ifndef __EMSCRIPTEN__
	wgpuSurfacePresent(ctx->surface);
#endif

	// Release per-frame objects
	wgpuCommandBufferRelease(cmd);
	wgpuRenderPassEncoderRelease(ctx->render_pass);
	wgpuCommandEncoderRelease(ctx->encoder);
	wgpuTextureViewRelease(ctx->surface_view);

	ctx->render_pass = NULL;
	ctx->encoder = NULL;
	ctx->surface_view = NULL;
}

// ---------------------------------------------------------------------------
// Bitmap upload (called during init, before rendering starts)
// ---------------------------------------------------------------------------
void render_webgpu_upload_bitmap(WebGPURenderContext* ctx, size_t offset,
                                 size_t size, u32 width, u32 height)
{
	if (!ctx->bitmap_tex) return;

	u32 bw = (u32)(ctx->bitmap_highest_w + 1);
	u32 bh = (u32)(ctx->bitmap_highest_h + 1);

	// Allocate temporary RGBA buffer for this bitmap layer (padded to array slice size)
	size_t slice_bytes = bw * bh * 4;
	u8* temp = calloc(1, slice_bytes);

	// Copy bitmap data row-by-row into padded buffer
	u32* src = (u32*)(ctx->bitmap_data + offset * 4);
	u32* dst = (u32*)temp;
	for (u32 y = 0; y <= height; y++)
	{
		for (u32 x = 0; x <= width; x++)
		{
			dst[y * bw + x] = src[y * (width + 1) + x];
		}
	}

	// Upload to the correct array layer
	WGPUTexelCopyTextureInfo dest = {0};
	dest.texture = ctx->bitmap_tex;
	dest.origin = (WGPUOrigin3D){0, 0, (u32)ctx->current_bitmap};
	WGPUTexelCopyBufferLayout layout = {0};
	layout.bytesPerRow = bw * 4;
	layout.rowsPerImage = bh;
	WGPUExtent3D extent = {bw, bh, 1};
	wgpuQueueWriteTexture(ctx->queue, &dest, temp, slice_bytes, &layout, &extent);

	// Store bitmap dimensions
	ctx->bitmap_sizes[2 * ctx->current_bitmap] = width;
	ctx->bitmap_sizes[2 * ctx->current_bitmap + 1] = height;
	ctx->current_bitmap++;

	free(temp);
}

void render_webgpu_finalize_bitmaps(WebGPURenderContext* ctx)
{
	if (ctx->bitmap_count == 0) return;

	// Upload bitmap_sizes to GPU
	wgpuQueueWriteBuffer(ctx->queue, ctx->bitmap_sizes_buffer, 0,
	                     ctx->bitmap_sizes, 2 * sizeof(u32) * ctx->bitmap_count);
}

// ---------------------------------------------------------------------------
// Extra transform / cxform uploads (used for text rendering)
// Data is uploaded to GPU buffers (matching flashbang behavior) but not yet
// bound to bind groups or used by shaders. Shader/bind-group integration is
// deferred until both backends' shaders are updated.
// ---------------------------------------------------------------------------
void render_webgpu_upload_extra_transform_id(WebGPURenderContext* ctx, u32 transform_id)
{
	// Upload to GPU buffer (matching flashbang behavior).
	// Not yet bound to shaders — deferred until both backends' shaders are updated.
	u32 id_data[4] = {transform_id, 0, 0, 0};
	wgpuQueueWriteBuffer(ctx->queue, ctx->extra_transform_id_buf, 0, id_data, 16);
}

void render_webgpu_upload_extra_transform(WebGPURenderContext* ctx, float* transform)
{
	// Upload mat4 to GPU buffer (matching flashbang behavior).
	// Not yet bound to shaders — deferred until both backends' shaders are updated.
	wgpuQueueWriteBuffer(ctx->queue, ctx->extra_transform_buf, 0, transform, 16 * sizeof(float));
}

void render_webgpu_upload_cxform_id(WebGPURenderContext* ctx, u32 cxform_id)
{
	// Upload to GPU buffer (matching flashbang behavior).
	// Not yet bound to shaders — deferred until both backends' shaders are updated.
	u32 id_data[4] = {cxform_id, 0, 0, 0};
	wgpuQueueWriteBuffer(ctx->queue, ctx->cxform_id_buf, 0, id_data, 16);
}

void render_webgpu_upload_cxform(WebGPURenderContext* ctx, float* cxform)
{
	// Upload 20 floats (5x4 color transform) to GPU buffer (matching flashbang behavior).
	// Not yet bound to shaders — deferred until both backends' shaders are updated.
	wgpuQueueWriteBuffer(ctx->queue, ctx->cxform_uniform_buf, 0, cxform, 20 * sizeof(float));
}

// ---------------------------------------------------------------------------
// render_webgpu_free: release all GPU resources
// ---------------------------------------------------------------------------
void render_webgpu_free(SWFAppContext* app_context, WebGPURenderContext* ctx)
{
	(void)app_context;

	// Release pipelines
	if (ctx->render_pipeline)
		wgpuRenderPipelineRelease(ctx->render_pipeline);
	if (ctx->compute_pipeline)
		wgpuComputePipelineRelease(ctx->compute_pipeline);

	// Release bind groups
	if (ctx->vertex_storage_bg) wgpuBindGroupRelease(ctx->vertex_storage_bg);
	if (ctx->vertex_uniform_bg) wgpuBindGroupRelease(ctx->vertex_uniform_bg);
	if (ctx->fragment_sampler_bg) wgpuBindGroupRelease(ctx->fragment_sampler_bg);
	if (ctx->compute_read_bg) wgpuBindGroupRelease(ctx->compute_read_bg);
	if (ctx->compute_write_bg) wgpuBindGroupRelease(ctx->compute_write_bg);

	// Release bind group layouts
	if (ctx->vertex_storage_bgl) wgpuBindGroupLayoutRelease(ctx->vertex_storage_bgl);
	if (ctx->vertex_uniform_bgl) wgpuBindGroupLayoutRelease(ctx->vertex_uniform_bgl);
	if (ctx->fragment_sampler_bgl) wgpuBindGroupLayoutRelease(ctx->fragment_sampler_bgl);
	if (ctx->compute_read_bgl) wgpuBindGroupLayoutRelease(ctx->compute_read_bgl);
	if (ctx->compute_write_bgl) wgpuBindGroupLayoutRelease(ctx->compute_write_bgl);

	// Release pipeline layouts
	if (ctx->render_pipeline_layout) wgpuPipelineLayoutRelease(ctx->render_pipeline_layout);
	if (ctx->compute_pipeline_layout) wgpuPipelineLayoutRelease(ctx->compute_pipeline_layout);

	// Release buffers
	if (ctx->vertex_buffer) wgpuBufferRelease(ctx->vertex_buffer);
	if (ctx->xform_buffer) wgpuBufferRelease(ctx->xform_buffer);
	if (ctx->color_buffer) wgpuBufferRelease(ctx->color_buffer);
	if (ctx->uninv_mat_buffer) wgpuBufferRelease(ctx->uninv_mat_buffer);
	if (ctx->inv_mat_buffer) wgpuBufferRelease(ctx->inv_mat_buffer);
	if (ctx->bitmap_sizes_buffer) wgpuBufferRelease(ctx->bitmap_sizes_buffer);
	if (ctx->cxform_buffer) wgpuBufferRelease(ctx->cxform_buffer);
	if (ctx->stage_to_ndc_buf) wgpuBufferRelease(ctx->stage_to_ndc_buf);
	if (ctx->transform_id_buf) wgpuBufferRelease(ctx->transform_id_buf);
	if (ctx->extra_transform_id_buf) wgpuBufferRelease(ctx->extra_transform_id_buf);
	if (ctx->extra_transform_buf) wgpuBufferRelease(ctx->extra_transform_buf);
	if (ctx->cxform_id_buf) wgpuBufferRelease(ctx->cxform_id_buf);
	if (ctx->cxform_uniform_buf) wgpuBufferRelease(ctx->cxform_uniform_buf);

	// Release textures and views
	if (ctx->gradient_tex_view) wgpuTextureViewRelease(ctx->gradient_tex_view);
	if (ctx->gradient_tex) wgpuTextureRelease(ctx->gradient_tex);
	if (ctx->gradient_sampler) wgpuSamplerRelease(ctx->gradient_sampler);
	if (ctx->bitmap_tex_view) wgpuTextureViewRelease(ctx->bitmap_tex_view);
	if (ctx->bitmap_tex) wgpuTextureRelease(ctx->bitmap_tex);
	if (ctx->bitmap_sampler) wgpuSamplerRelease(ctx->bitmap_sampler);
	if (ctx->dummy_tex_view) wgpuTextureViewRelease(ctx->dummy_tex_view);
	if (ctx->dummy_tex) wgpuTextureRelease(ctx->dummy_tex);
	if (ctx->dummy_sampler) wgpuSamplerRelease(ctx->dummy_sampler);
	if (ctx->msaa_view) wgpuTextureViewRelease(ctx->msaa_view);
	if (ctx->msaa_texture) wgpuTextureRelease(ctx->msaa_texture);

	// Release surface
	if (ctx->surface) wgpuSurfaceRelease(ctx->surface);

	// Release device, adapter, instance
	if (ctx->queue) wgpuQueueRelease(ctx->queue);
	if (ctx->device) wgpuDeviceRelease(ctx->device);
	if (ctx->adapter) wgpuAdapterRelease(ctx->adapter);
	if (ctx->instance) wgpuInstanceRelease(ctx->instance);

	// Release heap-allocated data
	FREE(ctx->bitmap_sizes);

	// Destroy SDL window (native only)
#ifndef __EMSCRIPTEN__
	if (ctx->window)
		SDL_DestroyWindow(ctx->window);
#endif

	free(ctx);
}
