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
"  @location(3) @interpolate(flat) v_cxform_id: u32,\n"
"};\n"
"\n"
"@vertex\n"
"fn vs_main(in: VertexInput, @builtin(instance_index) instance_id: u32) -> VertexOutput {\n"
"  var out: VertexOutput;\n"
"  let transform_id = instance_id & 0xFFFFu;\n"
"  let cxform_id = instance_id >> 16u;\n"
"  let transform = transforms[transform_id];\n"
"  let pos = vec4f(in.position, 0.0, 1.0);\n"
"  let spread_mode = (in.style.x >> 8u) & 0x3u;\n"
"  out.v_style_type = in.style.x & 0xFFu;\n"
"  out.v_style_id = in.style.y & 0xFFFFu;\n"
"  let style_upper = (in.style.y >> 16u) & 0xFFFFu;\n"
"  out.position = stage_transform.matrix * transform * pos;\n"
"  if (out.v_style_type == 0x00u) {\n"
"    out.v_args = colors[out.v_style_id];\n"
"  } else if ((out.v_style_type & 0xF0u) == 0x10u) {\n"
"    let inv_pos = inv_mats[out.v_style_id] * pos;\n"
"    var focal_z = 0.0;\n"
"    if (out.v_style_type == 0x13u) {\n"
"      focal_z = (f32(style_upper) - 32768.0) / 16384.0;\n"
"    }\n"
"    out.v_args = vec4f(inv_pos.xy, focal_z, f32(spread_mode));\n"
"  } else if ((out.v_style_type & 0xF0u) == 0x40u) {\n"
"    let inv_pos = inv_mats[style_upper] * pos;\n"
"    let sizes = bitmap_sizes[out.v_style_id];\n"
"    let padded = vec2f(f32(sizes.x), f32(sizes.y));\n"
"    let actual = padded - vec2f(1.0);\n"
"    out.v_args = vec4f(inv_pos.x / padded.x, inv_pos.y / padded.y, actual.x / padded.x, actual.y / padded.y);\n"
"  } else {\n"
"    out.v_args = vec4f(0.0);\n"
"  }\n"
"  out.v_cxform_id = cxform_id;\n"
"  return out;\n"
"}\n";

static const char* fragment_wgsl =
"@group(0) @binding(4) var<storage, read> cxforms: array<vec4f>;\n"
"\n"
"@group(2) @binding(0) var gradient_tex: texture_2d_array<f32>;\n"
"@group(2) @binding(1) var gradient_samp: sampler;\n"
"@group(2) @binding(2) var bitmap_tex: texture_2d_array<f32>;\n"
"@group(2) @binding(3) var bitmap_samp: sampler;\n"
"\n"
"struct FragmentInput {\n"
"  @location(0) @interpolate(flat) v_style_type: u32,\n"
"  @location(1) @interpolate(flat) v_style_id: u32,\n"
"  @location(2) v_args: vec4f,\n"
"  @location(3) @interpolate(flat) v_cxform_id: u32,\n"
"};\n"
"\n"
"fn apply_spread(t: f32, mode: f32) -> f32 {\n"
"  let m = u32(mode + 0.5);\n"
"  if (m == 1u) {\n"
"    // Reflect: triangle wave\n"
"    let p = t - 2.0 * floor(t / 2.0);\n"
"    return select(2.0 - p, p, p <= 1.0);\n"
"  } else if (m == 2u) {\n"
"    // Repeat: fract\n"
"    return t - floor(t);\n"
"  }\n"
"  // Pad: clamp 0-1\n"
"  return clamp(t, 0.0, 1.0);\n"
"}\n"
"\n"
"fn linear_t(v_args: vec4f) -> f32 { return apply_spread((v_args.x + 16384.0) / 32768.0, v_args.w); }\n"
"fn radial_t(v_args: vec4f) -> f32 { return apply_spread(distance(v_args.xy, vec2f(0.0)) / 16384.0, v_args.w); }\n"
"fn focal_radial_t(v_args: vec4f) -> f32 {\n"
"  let f = v_args.z;\n"
"  let R = 16384.0;\n"
"  let fx = f * R;\n"
"  let dx = v_args.x - fx;\n"
"  let dy = v_args.y;\n"
"  let A = dx * dx + dy * dy;\n"
"  let B = 2.0 * fx * dx;\n"
"  let C = fx * fx - R * R;\n"
"  let disc = B * B - 4.0 * A * C;\n"
"  let s_denom = -B + sqrt(max(disc, 0.0));\n"
"  if (s_denom < 0.001) { return 0.0; }\n"
"  return apply_spread(2.0 * A / s_denom, v_args.w);\n"
"}\n"
"\n"
"fn apply_cxform(color: vec4f, cxform_id: u32) -> vec4f {\n"
"  let ci = cxform_id * 5u;\n"
"  let mult = mat4x4f(cxforms[ci], cxforms[ci+1u], cxforms[ci+2u], cxforms[ci+3u]);\n"
"  let add = cxforms[ci+4u];\n"
"  return clamp(mult * color + add, vec4f(0.0), vec4f(1.0));\n"
"}\n"
"\n"
"@fragment\n"
"fn fs_main(in: FragmentInput) -> @location(0) vec4f {\n"
"  // Sample all textures unconditionally (uniform control flow required by Chrome/Dawn).\n"
"  // Use select() for array layer indices: only use v_style_id when the fill type\n"
"  // actually uses that texture, otherwise use 0 to avoid out-of-bounds access\n"
"  // on 1-layer dummy textures (Chrome/Dawn and Firefox handle OOB differently).\n"
"  let is_gradient = (in.v_style_type & 0xF0u) == 0x10u;\n"
"  let is_bitmap = (in.v_style_type & 0xF0u) == 0x40u;\n"
"  let grad_layer = select(0, i32(in.v_style_id), is_gradient);\n"
"  let bmp_layer = select(0, i32(in.v_style_id), is_bitmap);\n"
"  let linear_sample = textureSample(gradient_tex, gradient_samp, vec2f(linear_t(in.v_args), 0.5), grad_layer);\n"
"  let radial_sample = textureSample(gradient_tex, gradient_samp, vec2f(radial_t(in.v_args), 0.5), grad_layer);\n"
"  let focal_sample = textureSample(gradient_tex, gradient_samp, vec2f(focal_radial_t(in.v_args), 0.5), grad_layer);\n"
"  let bitmap_sample = textureSample(bitmap_tex, bitmap_samp, in.v_args.xy, bmp_layer);\n"
"  let bm_ratio = max(in.v_args.zw, vec2f(0.001));\n"
"  let bitmap_repeat_sample = textureSample(bitmap_tex, bitmap_samp, fract(in.v_args.xy / bm_ratio) * bm_ratio, bmp_layer);\n"
"  var color: vec4f;\n"
"  if (in.v_style_type == 0x00u) {\n"
"    color = in.v_args;\n"
"  } else if (in.v_style_type == 0x10u) {\n"
"    color = linear_sample;\n"
"  } else if (in.v_style_type == 0x12u) {\n"
"    color = radial_sample;\n"
"  } else if (in.v_style_type == 0x13u) {\n"
"    color = focal_sample;\n"
"  } else if (in.v_style_type == 0x40u || in.v_style_type == 0x42u) {\n"
"    color = bitmap_repeat_sample;\n"
"  } else if (in.v_style_type == 0x41u || in.v_style_type == 0x43u) {\n"
"    color = bitmap_sample;\n"
"  } else {\n"
"    color = vec4f(0.0);\n"
"  }\n"
"  return apply_cxform(color, in.v_cxform_id);\n"
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
// WASM mouse input callbacks (registered in render_webgpu_init)
// ---------------------------------------------------------------------------
#ifdef __EMSCRIPTEN__
static SWFAppContext* g_mouse_app_context = NULL;

static EM_BOOL on_mouse_move(int type, const EmscriptenMouseEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context) {
		g_mouse_app_context->mouse.stage_x = (float)evt->targetX * 20.0f;
		g_mouse_app_context->mouse.stage_y = (float)evt->targetY * 20.0f;
	}
	return EM_TRUE;
}

static EM_BOOL on_mouse_down(int type, const EmscriptenMouseEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context && evt->button == 0) {
		g_mouse_app_context->mouse.button_down = 1;
		g_mouse_app_context->mouse.clicked = 1;
		g_mouse_app_context->mouse.stage_x = (float)evt->targetX * 20.0f;
		g_mouse_app_context->mouse.stage_y = (float)evt->targetY * 20.0f;
	}
	return EM_TRUE;
}

static EM_BOOL on_mouse_up(int type, const EmscriptenMouseEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context && evt->button == 0) {
		g_mouse_app_context->mouse.button_down = 0;
		g_mouse_app_context->mouse.released = 1;
		g_mouse_app_context->mouse.stage_x = (float)evt->targetX * 20.0f;
		g_mouse_app_context->mouse.stage_y = (float)evt->targetY * 20.0f;
	}
	return EM_TRUE;
}
#endif

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

	// --- Register mouse input callbacks (WASM only) ---
#ifdef __EMSCRIPTEN__
	g_mouse_app_context = app_context;
	emscripten_set_mousemove_callback("#canvas", NULL, 0, on_mouse_move);
	emscripten_set_mousedown_callback("#canvas", NULL, 0, on_mouse_down);
	emscripten_set_mouseup_callback("#canvas", NULL, 0, on_mouse_up);
#endif
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
	size_t sizeof_gradient = 256 * 4; // 256 RGBA8 entries per gradient = 1024 bytes
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

		// Upload gradient data: each gradient = 256 RGBA8 pixels = 1024 bytes
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
		samp_desc.magFilter = WGPUFilterMode_Nearest;
		samp_desc.minFilter = WGPUFilterMode_Nearest;
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

	// --- Depth-stencil MSAA texture (for clip masks) ---
	{
		WGPUTextureDescriptor tex_desc = {0};
		tex_desc.label = WGPU_LABEL("depth_stencil_texture");
		tex_desc.dimension = WGPUTextureDimension_2D;
		tex_desc.size = (WGPUExtent3D){(u32)ctx->width, (u32)ctx->height, 1};
		tex_desc.format = WGPUTextureFormat_Depth24PlusStencil8;
		tex_desc.mipLevelCount = 1;
		tex_desc.sampleCount = 4;
		tex_desc.usage = WGPUTextureUsage_RenderAttachment;
		ctx->depth_stencil_texture = wgpuDeviceCreateTexture(ctx->device, &tex_desc);

		WGPUTextureViewDescriptor view_desc = {0};
		view_desc.mipLevelCount = 1;
		view_desc.arrayLayerCount = 1;
		ctx->depth_stencil_view = wgpuTextureCreateView(ctx->depth_stencil_texture, &view_desc);
	}
}

// ---------------------------------------------------------------------------
// create_pipelines: render pipeline + compute pipeline
// ---------------------------------------------------------------------------
static void create_pipelines(WebGPURenderContext* ctx)
{
	// --- Bind group layouts ---

	// Group 0: storage buffers (vertex + fragment)
	WGPUBindGroupLayoutEntry bg0_entries[5] = {0};
	for (int i = 0; i < 4; i++)
	{
		bg0_entries[i].binding = i;
		bg0_entries[i].visibility = WGPUShaderStage_Vertex;
		bg0_entries[i].buffer.type = WGPUBufferBindingType_ReadOnlyStorage;
	}
	// Entry 4: cxform buffer (fragment shader)
	bg0_entries[4].binding = 4;
	bg0_entries[4].visibility = WGPUShaderStage_Fragment;
	bg0_entries[4].buffer.type = WGPUBufferBindingType_ReadOnlyStorage;

	WGPUBindGroupLayoutDescriptor bg0_desc = {0};
	bg0_desc.label = WGPU_LABEL("storage_bgl");
	bg0_desc.entryCount = 5;
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

	// --- Depth-stencil state (shared base for all pipelines) ---
	// All pipelines must have depth-stencil state since the render pass
	// always has a depth-stencil attachment (needed for clip masks).

	// Normal pipeline: stencil always passes, never written (no-op)
	WGPUDepthStencilState ds_normal = {0};
	ds_normal.format = WGPUTextureFormat_Depth24PlusStencil8;
	ds_normal.depthWriteEnabled = false;
	ds_normal.depthCompare = WGPUCompareFunction_Always;
	ds_normal.stencilFront.compare = WGPUCompareFunction_Always;
	ds_normal.stencilFront.passOp = WGPUStencilOperation_Keep;
	ds_normal.stencilFront.failOp = WGPUStencilOperation_Keep;
	ds_normal.stencilFront.depthFailOp = WGPUStencilOperation_Keep;
	ds_normal.stencilBack = ds_normal.stencilFront;
	ds_normal.stencilReadMask = 0xFF;
	ds_normal.stencilWriteMask = 0x00;

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
	rp_desc.depthStencil = &ds_normal;

	ctx->render_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
	assert(ctx->render_pipeline != NULL);

	// --- Stencil write pipeline: writes to stencil, no color output ---
	// Used for clip mask shapes. The mask's geometry defines the clipping region.
	WGPUDepthStencilState ds_write = ds_normal;
	ds_write.stencilFront.compare = WGPUCompareFunction_Always;
	ds_write.stencilFront.passOp = WGPUStencilOperation_Replace;
	ds_write.stencilWriteMask = 0xFF;
	ds_write.stencilBack = ds_write.stencilFront;

	WGPUColorTargetState color_target_masked = color_target;
	color_target_masked.writeMask = WGPUColorWriteMask_None;
	WGPUFragmentState frag_state_masked = frag_state;
	frag_state_masked.targets = &color_target_masked;

	rp_desc.label = WGPU_LABEL("stencil_write_pipeline");
	rp_desc.depthStencil = &ds_write;
	rp_desc.fragment = &frag_state_masked;

	ctx->stencil_write_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
	assert(ctx->stencil_write_pipeline != NULL);

	// --- Stencil test pipeline: only draws where stencil == ref ---
	// Used for objects clipped by a mask.
	WGPUDepthStencilState ds_test = ds_normal;
	ds_test.stencilFront.compare = WGPUCompareFunction_Equal;
	ds_test.stencilBack = ds_test.stencilFront;

	rp_desc.label = WGPU_LABEL("stencil_test_pipeline");
	rp_desc.depthStencil = &ds_test;
	rp_desc.fragment = &frag_state;  // normal color output

	ctx->stencil_test_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
	assert(ctx->stencil_test_pipeline != NULL);

	// --- Blend mode pipelines ---
	// Reset to normal depth-stencil state and normal color output
	rp_desc.depthStencil = &ds_normal;
	rp_desc.fragment = &frag_state;

	// Add (blend mode 8): SrcAlpha / One / Add
	{
		WGPUBlendState blend_add = {0};
		blend_add.color.srcFactor = WGPUBlendFactor_SrcAlpha;
		blend_add.color.dstFactor = WGPUBlendFactor_One;
		blend_add.color.operation = WGPUBlendOperation_Add;
		blend_add.alpha.srcFactor = WGPUBlendFactor_SrcAlpha;
		blend_add.alpha.dstFactor = WGPUBlendFactor_One;
		blend_add.alpha.operation = WGPUBlendOperation_Add;

		WGPUColorTargetState ct_add = color_target;
		ct_add.blend = &blend_add;
		WGPUFragmentState fs_add = frag_state;
		fs_add.targets = &ct_add;

		rp_desc.label = WGPU_LABEL("blend_add_pipeline");
		rp_desc.fragment = &fs_add;
		ctx->blend_add_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
		assert(ctx->blend_add_pipeline != NULL);
	}

	// Lighten (blend mode 5): One / One / Max
	{
		WGPUBlendState blend_lighten = {0};
		blend_lighten.color.srcFactor = WGPUBlendFactor_One;
		blend_lighten.color.dstFactor = WGPUBlendFactor_One;
		blend_lighten.color.operation = WGPUBlendOperation_Max;
		blend_lighten.alpha.srcFactor = WGPUBlendFactor_One;
		blend_lighten.alpha.dstFactor = WGPUBlendFactor_One;
		blend_lighten.alpha.operation = WGPUBlendOperation_Max;

		WGPUColorTargetState ct_lighten = color_target;
		ct_lighten.blend = &blend_lighten;
		WGPUFragmentState fs_lighten = frag_state;
		fs_lighten.targets = &ct_lighten;

		rp_desc.label = WGPU_LABEL("blend_lighten_pipeline");
		rp_desc.fragment = &fs_lighten;
		ctx->blend_lighten_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
		assert(ctx->blend_lighten_pipeline != NULL);
	}

	// Darken (blend mode 6): One / One / Min
	{
		WGPUBlendState blend_darken = {0};
		blend_darken.color.srcFactor = WGPUBlendFactor_One;
		blend_darken.color.dstFactor = WGPUBlendFactor_One;
		blend_darken.color.operation = WGPUBlendOperation_Min;
		blend_darken.alpha.srcFactor = WGPUBlendFactor_One;
		blend_darken.alpha.dstFactor = WGPUBlendFactor_One;
		blend_darken.alpha.operation = WGPUBlendOperation_Min;

		WGPUColorTargetState ct_darken = color_target;
		ct_darken.blend = &blend_darken;
		WGPUFragmentState fs_darken = frag_state;
		fs_darken.targets = &ct_darken;

		rp_desc.label = WGPU_LABEL("blend_darken_pipeline");
		rp_desc.fragment = &fs_darken;
		ctx->blend_darken_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
		assert(ctx->blend_darken_pipeline != NULL);
	}

	// Subtract (blend mode 9): SrcAlpha / One / ReverseSubtract
	{
		WGPUBlendState blend_sub = {0};
		blend_sub.color.srcFactor = WGPUBlendFactor_SrcAlpha;
		blend_sub.color.dstFactor = WGPUBlendFactor_One;
		blend_sub.color.operation = WGPUBlendOperation_ReverseSubtract;
		blend_sub.alpha.srcFactor = WGPUBlendFactor_SrcAlpha;
		blend_sub.alpha.dstFactor = WGPUBlendFactor_One;
		blend_sub.alpha.operation = WGPUBlendOperation_ReverseSubtract;

		WGPUColorTargetState ct_sub = color_target;
		ct_sub.blend = &blend_sub;
		WGPUFragmentState fs_sub = frag_state;
		fs_sub.targets = &ct_sub;

		rp_desc.label = WGPU_LABEL("blend_subtract_pipeline");
		rp_desc.fragment = &fs_sub;
		ctx->blend_subtract_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
		assert(ctx->blend_subtract_pipeline != NULL);
	}

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
	// --- Group 0: storage buffers ---
	WGPUBindGroupEntry bg0_entries[5] = {0};
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
	bg0_entries[4].binding = 4;
	bg0_entries[4].buffer = ctx->cxform_buffer;
	bg0_entries[4].size = wgpuBufferGetSize(ctx->cxform_buffer);

	WGPUBindGroupDescriptor bg0_desc = {0};
	bg0_desc.label = WGPU_LABEL("storage_bg");
	bg0_desc.layout = ctx->vertex_storage_bgl;
	bg0_desc.entryCount = 5;
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
// render_webgpu_poll: check for quit/mouse events
// ---------------------------------------------------------------------------
int render_webgpu_poll(SWFAppContext* app_context)
{
#ifdef __EMSCRIPTEN__
	// In WASM, mouse events are handled by callbacks registered in init.
	return 0;
#else
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
			return 1;
		if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE)
			return 1;
		if (event.type == SDL_EVENT_MOUSE_MOTION)
		{
			app_context->mouse.stage_x = event.motion.x * 20.0f;
			app_context->mouse.stage_y = event.motion.y * 20.0f;
		}
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN && event.button.button == SDL_BUTTON_LEFT)
		{
			app_context->mouse.button_down = 1;
			app_context->mouse.clicked = 1;
			app_context->mouse.stage_x = event.button.x * 20.0f;
			app_context->mouse.stage_y = event.button.y * 20.0f;
		}
		else if (event.type == SDL_EVENT_MOUSE_BUTTON_UP && event.button.button == SDL_BUTTON_LEFT)
		{
			app_context->mouse.button_down = 0;
			app_context->mouse.released = 1;
			app_context->mouse.stage_x = event.button.x * 20.0f;
			app_context->mouse.stage_y = event.button.y * 20.0f;
		}
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
	color_att.storeOp = WGPUStoreOp_Store; // Store so filters can suspend/resume pass
	color_att.clearValue = (WGPUColor){
		ctx->red / 255.0, ctx->green / 255.0, ctx->blue / 255.0, 1.0
	};

	WGPURenderPassDepthStencilAttachment ds_att = {0};
	ds_att.view = ctx->depth_stencil_view;
	ds_att.depthLoadOp = WGPULoadOp_Clear;
	ds_att.depthStoreOp = WGPUStoreOp_Discard;
	ds_att.depthClearValue = 1.0f;
	ds_att.stencilLoadOp = WGPULoadOp_Clear;
	ds_att.stencilStoreOp = WGPUStoreOp_Store; // Store for filter suspend/resume
	ds_att.stencilClearValue = 0;

	WGPURenderPassDescriptor rp_desc = {0};
	rp_desc.label = WGPU_LABEL("render_pass");
	rp_desc.colorAttachmentCount = 1;
	rp_desc.colorAttachments = &color_att;
	rp_desc.depthStencilAttachment = &ds_att;

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
                              size_t num_verts, u32 transform_id, u32 cxform_id)
{
	// Set vertex buffer with byte offset
	uint64_t byte_offset = offset * 4 * sizeof(u32);
	uint64_t byte_size = num_verts * 4 * sizeof(u32);
	wgpuRenderPassEncoderSetVertexBuffer(ctx->render_pass, 0, ctx->vertex_buffer,
	                                     byte_offset, byte_size);

	// Pack transform_id (low 16 bits) and cxform_id (high 16 bits) into
	// firstInstance. The vertex shader extracts both via @builtin(instance_index).
	// This avoids uniform buffer writes between draw calls, which don't take
	// effect until the next queue submit.
	u32 packed_id = transform_id | (cxform_id << 16);
	wgpuRenderPassEncoderDraw(ctx->render_pass, (u32)num_verts, 1, 0, packed_id);
}

// ---------------------------------------------------------------------------
// Clip mask control: stencil-based clipping for PlaceObject2 clipDepth
// ---------------------------------------------------------------------------
void render_webgpu_begin_clip_mask(WebGPURenderContext* ctx)
{
	// Switch to stencil-write pipeline: draws to stencil buffer only (no color)
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->stencil_write_pipeline);
	wgpuRenderPassEncoderSetStencilReference(ctx->render_pass, 1);
}

void render_webgpu_end_clip_mask(WebGPURenderContext* ctx)
{
	// Switch to stencil-test pipeline: only draws where stencil == 1 (inside mask)
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->stencil_test_pipeline);
	wgpuRenderPassEncoderSetStencilReference(ctx->render_pass, 1);
}

void render_webgpu_end_clip(WebGPURenderContext* ctx)
{
	// Switch back to normal pipeline (no stencil testing)
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
}

void render_webgpu_set_blend_mode(WebGPURenderContext* ctx, u8 blend_mode)
{
	WGPURenderPipeline pipeline;
	switch (blend_mode)
	{
		case 5: pipeline = ctx->blend_lighten_pipeline; break;
		case 6: pipeline = ctx->blend_darken_pipeline; break;
		case 8: pipeline = ctx->blend_add_pipeline; break;
		case 9: pipeline = ctx->blend_subtract_pipeline; break;
		default: pipeline = ctx->render_pipeline; break; // Normal or unsupported
	}
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, pipeline);
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

	// Copy bitmap data row-by-row into padded buffer (with edge clamping for
	// the extra padding column/row, matching flashbang_upload_bitmap behavior)
	u32* src = (u32*)(ctx->bitmap_data + offset);
	u32* dst = (u32*)temp;
	for (u32 y = 0; y <= height; y++)
	{
		u32 sy = (y < height) ? y : height - 1;
		for (u32 x = 0; x <= width; x++)
		{
			u32 sx = (x < width) ? x : width - 1;
			dst[y * bw + x] = src[sy * width + sx];
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

	// Store padded texture dimensions (not raw bitmap size) so that the
	// vertex shader UV computation (texel_pos / size) maps correctly to the
	// actual texture layer, which includes a +1 edge-clamp padding column/row.
	ctx->bitmap_sizes[2 * ctx->current_bitmap] = bw;
	ctx->bitmap_sizes[2 * ctx->current_bitmap + 1] = bh;
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
// mat4_multiply: C = A * B (column-major 4x4)
// ---------------------------------------------------------------------------
static void mat4_multiply(float* out, const float* A, const float* B)
{
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			out[col * 4 + row] =
				A[0 * 4 + row] * B[col * 4 + 0] +
				A[1 * 4 + row] * B[col * 4 + 1] +
				A[2 * 4 + row] * B[col * 4 + 2] +
				A[3 * 4 + row] * B[col * 4 + 3];
		}
	}
}

// ---------------------------------------------------------------------------
// render_webgpu_compose_text_transforms: compose PlaceObject2 transform with
// each glyph transform and write composed results to GPU xform_buffer.
// Called before renderer_open_pass so all writes happen before the render pass.
// Does NOT modify CPU-side transform_data (safe for multi-frame rendering).
// ---------------------------------------------------------------------------
void render_webgpu_compose_text_transforms(WebGPURenderContext* ctx,
                                            const char* transform_data,
                                            u32 place_transform_id,
                                            u32 glyph_start,
                                            size_t count)
{
	const float* transforms = (const float*)transform_data;
	const float* place_xform = &transforms[place_transform_id * 16];

	for (size_t i = 0; i < count; i++)
	{
		u32 glyph_xform_id = glyph_start + (u32)i;
		const float* glyph_xform = &transforms[glyph_xform_id * 16];

		float composed[16];
		mat4_multiply(composed, place_xform, glyph_xform);

		// Write composed transform to the GPU buffer at the glyph's slot
		uint64_t offset = (uint64_t)glyph_xform_id * 16 * sizeof(float);
		wgpuQueueWriteBuffer(ctx->queue, ctx->xform_buffer, offset,
		                     composed, 16 * sizeof(float));
	}
}

// ---------------------------------------------------------------------------
// render_webgpu_compose_sprite_transform: compose parent PlaceObject2 transform
// with a single child transform and write the result to the child's xform slot
// in the GPU buffer.  Called before renderer_open_pass.
// ---------------------------------------------------------------------------
void render_webgpu_compose_sprite_transform(WebGPURenderContext* ctx,
                                            const char* transform_data,
                                            u32 parent_transform_id,
                                            u32 child_transform_id)
{
	const float* transforms = (const float*)transform_data;
	const float* parent_xform = &transforms[parent_transform_id * 16];
	const float* child_xform  = &transforms[child_transform_id * 16];

	float composed[16];
	mat4_multiply(composed, parent_xform, child_xform);

	uint64_t offset = (uint64_t)child_transform_id * 16 * sizeof(float);
	wgpuQueueWriteBuffer(ctx->queue, ctx->xform_buffer, offset,
	                     composed, 16 * sizeof(float));
}

// ---------------------------------------------------------------------------
// render_webgpu_write_transform: write a pre-computed composed transform to the
// GPU xform_buffer at the given slot.  Used by tag.c's recursive composition.
// ---------------------------------------------------------------------------
void render_webgpu_write_transform(WebGPURenderContext* ctx,
                                   u32 transform_id, const float composed[16])
{
	uint64_t offset = (uint64_t)transform_id * 16 * sizeof(float);
	wgpuQueueWriteBuffer(ctx->queue, ctx->xform_buffer, offset,
	                     composed, 16 * sizeof(float));
}

// ---------------------------------------------------------------------------
// render_webgpu_update_vertices / render_webgpu_update_colors
// Write interpolated morph data into GPU buffers before the render pass.
// ---------------------------------------------------------------------------
void render_webgpu_update_vertices(WebGPURenderContext* ctx,
	size_t byte_offset, const void* data, size_t byte_size)
{
	wgpuQueueWriteBuffer(ctx->queue, ctx->vertex_buffer, byte_offset, data, byte_size);
}

void render_webgpu_update_colors(WebGPURenderContext* ctx,
	size_t byte_offset, const void* data, size_t byte_size)
{
	wgpuQueueWriteBuffer(ctx->queue, ctx->color_buffer, byte_offset, data, byte_size);
}

// ---------------------------------------------------------------------------
// Filter support: WGSL shaders, resource creation, blur + composite passes
// ---------------------------------------------------------------------------

static const char* blur_wgsl =
	"struct Params {\n"
	"  direction: vec2f,\n"     // (1,0) for H, (0,1) for V
	"  texel_size: vec2f,\n"    // 1/width, 1/height
	"  radius: f32,\n"
	"  strength: f32,\n"
	"  color: vec4f,\n"         // for colorize (glow/shadow)
	"  colorize: f32,\n"        // 0=blur, 1=colorize alpha
	"  pad1: f32,\n"
	"  pad2: f32,\n"
	"  pad3: f32,\n"
	"}\n"
	"@group(0) @binding(0) var in_tex: texture_2d<f32>;\n"
	"@group(0) @binding(1) var in_samp: sampler;\n"
	"@group(0) @binding(2) var<uniform> params: Params;\n"
	"\n"
	"struct VSOut { @builtin(position) pos: vec4f, @location(0) uv: vec2f }\n"
	"\n"
	"@vertex fn vs_main(@builtin(vertex_index) vi: u32) -> VSOut {\n"
	"  var positions = array<vec2f, 6>(\n"
	"    vec2f(-1.0, -1.0), vec2f(1.0, -1.0), vec2f(-1.0, 1.0),\n"
	"    vec2f(-1.0, 1.0), vec2f(1.0, -1.0), vec2f(1.0, 1.0)\n"
	"  );\n"
	"  var uvs = array<vec2f, 6>(\n"
	"    vec2f(0.0, 1.0), vec2f(1.0, 1.0), vec2f(0.0, 0.0),\n"
	"    vec2f(0.0, 0.0), vec2f(1.0, 1.0), vec2f(1.0, 0.0)\n"
	"  );\n"
	"  var out: VSOut;\n"
	"  out.pos = vec4f(positions[vi], 0.0, 1.0);\n"
	"  out.uv = uvs[vi];\n"
	"  return out;\n"
	"}\n"
	"\n"
	"@fragment fn fs_main(@location(0) uv: vec2f) -> @location(0) vec4f {\n"
	"  let r = i32(params.radius);\n"
	"  let sigma = max(params.radius * 0.5, 0.001);\n"
	"  var total = vec4f(0.0);\n"
	"  var weight_sum = 0.0;\n"
	"  for (var i = -r; i <= r; i++) {\n"
	"    let offset = vec2f(f32(i)) * params.direction * params.texel_size;\n"
	"    let w = exp(-f32(i*i) / (2.0 * sigma * sigma));\n"
	"    total += textureSample(in_tex, in_samp, uv + offset) * w;\n"
	"    weight_sum += w;\n"
	"  }\n"
	"  var result = total / weight_sum;\n"
	"  result = clamp(result * params.strength, vec4f(0.0), vec4f(1.0));\n"
	"  if (params.colorize > 0.5) {\n"
	"    let a2 = result.a * params.color.a;\n"
	"    result = vec4f(params.color.rgb * a2, a2);\n"  // pre-multiplied alpha
	"  }\n"
	"  return result;\n"
	"}\n";

static const char* composite_wgsl =
	"struct Params {\n"
	"  offset_and_mode: vec4f,\n"  // xy=NDC offset, z=tint_mode (0=passthrough, 1=tint), w=unused
	"  tint: vec4f,\n"             // RGBA tint color (used when tint_mode > 0.5)
	"}\n"
	"@group(0) @binding(0) var in_tex: texture_2d<f32>;\n"
	"@group(0) @binding(1) var in_samp: sampler;\n"
	"@group(0) @binding(2) var<uniform> params: Params;\n"
	"\n"
	"struct VSOut { @builtin(position) pos: vec4f, @location(0) uv: vec2f }\n"
	"\n"
	"@vertex fn vs_main(@builtin(vertex_index) vi: u32) -> VSOut {\n"
	"  var positions = array<vec2f, 6>(\n"
	"    vec2f(-1.0, -1.0), vec2f(1.0, -1.0), vec2f(-1.0, 1.0),\n"
	"    vec2f(-1.0, 1.0), vec2f(1.0, -1.0), vec2f(1.0, 1.0)\n"
	"  );\n"
	"  var uvs = array<vec2f, 6>(\n"
	"    vec2f(0.0, 1.0), vec2f(1.0, 1.0), vec2f(0.0, 0.0),\n"
	"    vec2f(0.0, 0.0), vec2f(1.0, 1.0), vec2f(1.0, 0.0)\n"
	"  );\n"
	"  var out: VSOut;\n"
	"  out.pos = vec4f(positions[vi] + params.offset_and_mode.xy, 0.0, 1.0);\n"
	"  out.uv = uvs[vi];\n"
	"  return out;\n"
	"}\n"
	"\n"
	"@fragment fn fs_main(@location(0) uv: vec2f) -> @location(0) vec4f {\n"
	"  let c = textureSample(in_tex, in_samp, uv);\n"
	"  let a_tinted = c.a * params.tint.a;\n"
	"  let tinted = vec4f(params.tint.rgb * a_tinted, a_tinted);\n"
	"  return select(c, tinted, params.offset_and_mode.z > 0.5);\n"
	"}\n";

void render_webgpu_ensure_filter_resources(WebGPURenderContext* ctx)
{
	if (ctx->filter_resources_created) return;
	ctx->filter_resources_created = 1;

	// --- Filter textures (non-MSAA, RGBA8) ---
	WGPUTextureDescriptor ftex_desc = {0};
	ftex_desc.label = WGPU_LABEL("filter_tex_a");
	ftex_desc.dimension = WGPUTextureDimension_2D;
	ftex_desc.size = (WGPUExtent3D){(u32)ctx->width, (u32)ctx->height, 1};
	ftex_desc.format = ctx->surface_format;
	ftex_desc.mipLevelCount = 1;
	ftex_desc.sampleCount = 1;
	ftex_desc.usage = WGPUTextureUsage_RenderAttachment | WGPUTextureUsage_TextureBinding;
	ctx->filter_tex_a = wgpuDeviceCreateTexture(ctx->device, &ftex_desc);
	ftex_desc.label = WGPU_LABEL("filter_tex_b");
	ctx->filter_tex_b = wgpuDeviceCreateTexture(ctx->device, &ftex_desc);

	WGPUTextureViewDescriptor fview_desc = {0};
	fview_desc.mipLevelCount = 1;
	fview_desc.arrayLayerCount = 1;
	ctx->filter_view_a = wgpuTextureCreateView(ctx->filter_tex_a, &fview_desc);
	ctx->filter_view_b = wgpuTextureCreateView(ctx->filter_tex_b, &fview_desc);

	// --- Separate MSAA 4x texture for offscreen rendering ---
	{
		WGPUTextureDescriptor msaa_desc = {0};
		msaa_desc.label = WGPU_LABEL("filter_msaa");
		msaa_desc.dimension = WGPUTextureDimension_2D;
		msaa_desc.size = (WGPUExtent3D){(u32)ctx->width, (u32)ctx->height, 1};
		msaa_desc.format = ctx->surface_format;
		msaa_desc.mipLevelCount = 1;
		msaa_desc.sampleCount = 4;
		msaa_desc.usage = WGPUTextureUsage_RenderAttachment;
		ctx->filter_msaa_texture = wgpuDeviceCreateTexture(ctx->device, &msaa_desc);
		ctx->filter_msaa_view = wgpuTextureCreateView(ctx->filter_msaa_texture, NULL);
	}

	// --- Filter sampler ---
	WGPUSamplerDescriptor samp_desc = {0};
	samp_desc.label = WGPU_LABEL("filter_sampler");
	samp_desc.addressModeU = WGPUAddressMode_ClampToEdge;
	samp_desc.addressModeV = WGPUAddressMode_ClampToEdge;
	samp_desc.magFilter = WGPUFilterMode_Linear;
	samp_desc.minFilter = WGPUFilterMode_Linear;
	samp_desc.maxAnisotropy = 1;
	ctx->filter_sampler = wgpuDeviceCreateSampler(ctx->device, &samp_desc);

	// --- Blur params uniform buffer (64 bytes) ---
	{
		WGPUBufferDescriptor buf_desc = {0};
		buf_desc.label = WGPU_LABEL("blur_params");
		buf_desc.size = 64;
		buf_desc.usage = WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst;
		ctx->blur_params_buf = wgpuDeviceCreateBuffer(ctx->device, &buf_desc);
	}

	// --- Blur pipeline ---
	{
		WGPUBindGroupLayoutEntry entries[3] = {0};
		entries[0].binding = 0;
		entries[0].visibility = WGPUShaderStage_Fragment;
		entries[0].texture.sampleType = WGPUTextureSampleType_Float;
		entries[0].texture.viewDimension = WGPUTextureViewDimension_2D;
		entries[1].binding = 1;
		entries[1].visibility = WGPUShaderStage_Fragment;
		entries[1].sampler.type = WGPUSamplerBindingType_Filtering;
		entries[2].binding = 2;
		entries[2].visibility = WGPUShaderStage_Fragment;
		entries[2].buffer.type = WGPUBufferBindingType_Uniform;
		entries[2].buffer.minBindingSize = 64;

		WGPUBindGroupLayoutDescriptor bgl_desc = {0};
		bgl_desc.entryCount = 3;
		bgl_desc.entries = entries;
		ctx->blur_bgl = wgpuDeviceCreateBindGroupLayout(ctx->device, &bgl_desc);

		WGPUPipelineLayoutDescriptor pl_desc = {0};
		pl_desc.bindGroupLayoutCount = 1;
		pl_desc.bindGroupLayouts = &ctx->blur_bgl;
		ctx->blur_pipeline_layout = wgpuDeviceCreatePipelineLayout(ctx->device, &pl_desc);

		WGPUShaderModule blur_sm = create_shader(ctx->device, blur_wgsl, "blur_shader");

		WGPUColorTargetState ct = {0};
		ct.format = ctx->surface_format;
		ct.writeMask = WGPUColorWriteMask_All;
		// Pre-multiplied alpha blending for blur output
		WGPUBlendState blend = {0};
		blend.color.srcFactor = WGPUBlendFactor_One;
		blend.color.dstFactor = WGPUBlendFactor_Zero;
		blend.color.operation = WGPUBlendOperation_Add;
		blend.alpha.srcFactor = WGPUBlendFactor_One;
		blend.alpha.dstFactor = WGPUBlendFactor_Zero;
		blend.alpha.operation = WGPUBlendOperation_Add;
		ct.blend = &blend;

		WGPUFragmentState fs = {0};
		fs.module = blur_sm;
		fs.entryPoint = WGPU_LABEL("fs_main");
		fs.targetCount = 1;
		fs.targets = &ct;

		WGPURenderPipelineDescriptor rpd = {0};
		rpd.label = WGPU_LABEL("blur_pipeline");
		rpd.layout = ctx->blur_pipeline_layout;
		rpd.vertex.module = blur_sm;
		rpd.vertex.entryPoint = WGPU_LABEL("vs_main");
		rpd.fragment = &fs;
		rpd.primitive.topology = WGPUPrimitiveTopology_TriangleList;
		rpd.multisample.count = 1;
		rpd.multisample.mask = 0xFFFFFFFF;
		ctx->blur_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rpd);
		wgpuShaderModuleRelease(blur_sm);
	}

	// --- Composite pipeline (draws into MSAA 4x main pass) ---
	{
		WGPUBindGroupLayoutEntry entries[3] = {0};
		entries[0].binding = 0;
		entries[0].visibility = WGPUShaderStage_Fragment;
		entries[0].texture.sampleType = WGPUTextureSampleType_Float;
		entries[0].texture.viewDimension = WGPUTextureViewDimension_2D;
		entries[1].binding = 1;
		entries[1].visibility = WGPUShaderStage_Fragment;
		entries[1].sampler.type = WGPUSamplerBindingType_Filtering;
		entries[2].binding = 2;
		entries[2].visibility = WGPUShaderStage_Vertex | WGPUShaderStage_Fragment;
		entries[2].buffer.type = WGPUBufferBindingType_Uniform;
		entries[2].buffer.minBindingSize = 32;

		WGPUBindGroupLayoutDescriptor bgl_desc = {0};
		bgl_desc.entryCount = 3;
		bgl_desc.entries = entries;
		ctx->composite_bgl = wgpuDeviceCreateBindGroupLayout(ctx->device, &bgl_desc);

		WGPUPipelineLayoutDescriptor pl_desc = {0};
		pl_desc.bindGroupLayoutCount = 1;
		pl_desc.bindGroupLayouts = &ctx->composite_bgl;
		ctx->composite_pipeline_layout = wgpuDeviceCreatePipelineLayout(ctx->device, &pl_desc);

		WGPUShaderModule comp_sm = create_shader(ctx->device, composite_wgsl, "composite_shader");

		WGPUColorTargetState ct = {0};
		ct.format = ctx->surface_format;
		ct.writeMask = WGPUColorWriteMask_All;
		// Pre-multiplied alpha blending (over operator)
		WGPUBlendState blend = {0};
		blend.color.srcFactor = WGPUBlendFactor_One;
		blend.color.dstFactor = WGPUBlendFactor_OneMinusSrcAlpha;
		blend.color.operation = WGPUBlendOperation_Add;
		blend.alpha.srcFactor = WGPUBlendFactor_One;
		blend.alpha.dstFactor = WGPUBlendFactor_OneMinusSrcAlpha;
		blend.alpha.operation = WGPUBlendOperation_Add;
		ct.blend = &blend;

		WGPUFragmentState fs = {0};
		fs.module = comp_sm;
		fs.entryPoint = WGPU_LABEL("fs_main");
		fs.targetCount = 1;
		fs.targets = &ct;

		// Depth-stencil: test stencil (so clip masks work) but don't write
		WGPUDepthStencilState ds = {0};
		ds.format = WGPUTextureFormat_Depth24PlusStencil8;
		ds.depthWriteEnabled = 0;
		ds.depthCompare = WGPUCompareFunction_Always;
		ds.stencilFront.compare = WGPUCompareFunction_Equal;
		ds.stencilFront.failOp = WGPUStencilOperation_Keep;
		ds.stencilFront.depthFailOp = WGPUStencilOperation_Keep;
		ds.stencilFront.passOp = WGPUStencilOperation_Keep;
		ds.stencilBack = ds.stencilFront;
		ds.stencilReadMask = 0xFF;
		ds.stencilWriteMask = 0x00;

		WGPURenderPipelineDescriptor rpd = {0};
		rpd.label = WGPU_LABEL("composite_pipeline");
		rpd.layout = ctx->composite_pipeline_layout;
		rpd.vertex.module = comp_sm;
		rpd.vertex.entryPoint = WGPU_LABEL("vs_main");
		rpd.fragment = &fs;
		rpd.primitive.topology = WGPUPrimitiveTopology_TriangleList;
		rpd.multisample.count = 4;
		rpd.multisample.mask = 0xFFFFFFFF;
		rpd.depthStencil = &ds;
		ctx->composite_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rpd);
		wgpuShaderModuleRelease(comp_sm);
	}

	// --- Composite params uniform buffer (32 bytes: offset+mode vec4f + tint vec4f) ---
	{
		WGPUBufferDescriptor buf_desc = {0};
		buf_desc.label = WGPU_LABEL("composite_params");
		buf_desc.size = 32;
		buf_desc.usage = WGPUBufferUsage_Uniform | WGPUBufferUsage_CopyDst;
		ctx->filter_quad_buffer = wgpuDeviceCreateBuffer(ctx->device, &buf_desc);
	}
}

void render_webgpu_suspend_pass(WebGPURenderContext* ctx)
{
	if (ctx->render_pass)
	{
		wgpuRenderPassEncoderEnd(ctx->render_pass);
		wgpuRenderPassEncoderRelease(ctx->render_pass);
		ctx->render_pass = NULL;
	}
}

void render_webgpu_resume_pass(WebGPURenderContext* ctx)
{
	// Resume the main render pass with loadOp=Load to preserve existing content + stencil
	WGPURenderPassColorAttachment color_att = {0};
	color_att.depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
	color_att.view = ctx->msaa_view;
	color_att.resolveTarget = ctx->surface_view;
	color_att.loadOp = WGPULoadOp_Load;
	color_att.storeOp = WGPUStoreOp_Store;

	WGPURenderPassDepthStencilAttachment ds_att = {0};
	ds_att.view = ctx->depth_stencil_view;
	ds_att.depthLoadOp = WGPULoadOp_Load;
	ds_att.depthStoreOp = WGPUStoreOp_Discard;
	ds_att.stencilLoadOp = WGPULoadOp_Load;
	ds_att.stencilStoreOp = WGPUStoreOp_Store;

	WGPURenderPassDescriptor rp_desc = {0};
	rp_desc.label = WGPU_LABEL("resume_pass");
	rp_desc.colorAttachmentCount = 1;
	rp_desc.colorAttachments = &color_att;
	rp_desc.depthStencilAttachment = &ds_att;

	ctx->render_pass = wgpuCommandEncoderBeginRenderPass(ctx->encoder, &rp_desc);

	// Re-bind everything
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 0, ctx->vertex_storage_bg, 0, NULL);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 2, ctx->fragment_sampler_bg, 0, NULL);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 1, ctx->vertex_uniform_bg, 0, NULL);
}

void render_webgpu_begin_offscreen_pass(WebGPURenderContext* ctx)
{
	render_webgpu_ensure_filter_resources(ctx);

	// Use a SEPARATE MSAA texture (filter_msaa_view) so we don't clobber
	// the main pass content stored in ctx->msaa_view during suspend.
	WGPURenderPassColorAttachment color_att = {0};
	color_att.depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
	color_att.view = ctx->filter_msaa_view;
	color_att.resolveTarget = ctx->filter_view_a;
	color_att.loadOp = WGPULoadOp_Clear;
	color_att.storeOp = WGPUStoreOp_Store;
	color_att.clearValue = (WGPUColor){0.0, 0.0, 0.0, 0.0};

	// Depth-stencil required because render_pipeline was created with it
	WGPURenderPassDepthStencilAttachment ds_att = {0};
	ds_att.view = ctx->depth_stencil_view;
	ds_att.depthLoadOp = WGPULoadOp_Clear;
	ds_att.depthStoreOp = WGPUStoreOp_Discard;
	ds_att.depthClearValue = 1.0f;
	ds_att.stencilLoadOp = WGPULoadOp_Clear;
	ds_att.stencilStoreOp = WGPUStoreOp_Discard;
	ds_att.stencilClearValue = 0;

	WGPURenderPassDescriptor rp_desc = {0};
	rp_desc.label = WGPU_LABEL("offscreen_pass");
	rp_desc.colorAttachmentCount = 1;
	rp_desc.colorAttachments = &color_att;
	rp_desc.depthStencilAttachment = &ds_att;

	ctx->render_pass = wgpuCommandEncoderBeginRenderPass(ctx->encoder, &rp_desc);

	// Bind the main pipeline (MSAA 4x compatible)
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 0, ctx->vertex_storage_bg, 0, NULL);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 2, ctx->fragment_sampler_bg, 0, NULL);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 1, ctx->vertex_uniform_bg, 0, NULL);
}

void render_webgpu_end_offscreen_pass(WebGPURenderContext* ctx)
{
	if (ctx->render_pass)
	{
		wgpuRenderPassEncoderEnd(ctx->render_pass);
		wgpuRenderPassEncoderRelease(ctx->render_pass);
		ctx->render_pass = NULL;
	}
}

void render_webgpu_run_blur(WebGPURenderContext* ctx,
	float blur_x, float blur_y, u8 quality,
	float strength, float r, float g, float b, float a, int colorize)
{
	float texel_w = 1.0f / (float)ctx->width;
	float texel_h = 1.0f / (float)ctx->height;

	// Convert blur (in pixels) to radius (half-width of kernel, capped at 31)
	float radius_x = blur_x * 0.5f;
	float radius_y = blur_y * 0.5f;
	if (radius_x > 31.0f) radius_x = 31.0f;
	if (radius_y > 31.0f) radius_y = 31.0f;
	if (radius_x < 1.0f) radius_x = 1.0f;
	if (radius_y < 1.0f) radius_y = 1.0f;

	// Params layout (64 bytes):
	// vec2f direction (8), vec2f texel_size (8), f32 radius (4), f32 strength (4),
	// vec4f color (16), f32 colorize (4), f32 pad1 (4), f32 pad2 (4), f32 pad3 (4) = 56 bytes padded to 64
	float params[16]; // 64 bytes

	for (u8 q = 0; q < quality; q++)
	{
		// Horizontal blur: filter_tex_a -> filter_tex_b
		params[0] = 1.0f; params[1] = 0.0f;   // direction
		params[2] = texel_w; params[3] = texel_h; // texel_size
		params[4] = radius_x;                    // radius
		params[5] = (q == quality - 1) ? strength : 1.0f; // strength (only on last pass)
		params[6] = r; params[7] = g; params[8] = b; params[9] = a; // color
		params[10] = (q == quality - 1 && colorize) ? 1.0f : 0.0f; // colorize (only on last pass)
		params[11] = 0; params[12] = 0; params[13] = 0;

		wgpuQueueWriteBuffer(ctx->queue, ctx->blur_params_buf, 0, params, 64);

		// Create bind group for H-blur: read filter_tex_a
		WGPUBindGroupEntry bg_entries[3] = {0};
		bg_entries[0].binding = 0;
		bg_entries[0].textureView = ctx->filter_view_a;
		bg_entries[1].binding = 1;
		bg_entries[1].sampler = ctx->filter_sampler;
		bg_entries[2].binding = 2;
		bg_entries[2].buffer = ctx->blur_params_buf;
		bg_entries[2].size = 64;

		WGPUBindGroupDescriptor bg_desc = {0};
		bg_desc.layout = ctx->blur_bgl;
		bg_desc.entryCount = 3;
		bg_desc.entries = bg_entries;
		WGPUBindGroup bg = wgpuDeviceCreateBindGroup(ctx->device, &bg_desc);

		// Render to filter_tex_b
		WGPURenderPassColorAttachment color_att = {0};
		color_att.depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
		color_att.view = ctx->filter_view_b;
		color_att.loadOp = WGPULoadOp_Clear;
		color_att.storeOp = WGPUStoreOp_Store;
		color_att.clearValue = (WGPUColor){0, 0, 0, 0};

		WGPURenderPassDescriptor rp_desc = {0};
		rp_desc.label = WGPU_LABEL("blur_h");
		rp_desc.colorAttachmentCount = 1;
		rp_desc.colorAttachments = &color_att;

		WGPURenderPassEncoder pass = wgpuCommandEncoderBeginRenderPass(ctx->encoder, &rp_desc);
		wgpuRenderPassEncoderSetPipeline(pass, ctx->blur_pipeline);
		wgpuRenderPassEncoderSetBindGroup(pass, 0, bg, 0, NULL);
		wgpuRenderPassEncoderDraw(pass, 6, 1, 0, 0);
		wgpuRenderPassEncoderEnd(pass);
		wgpuRenderPassEncoderRelease(pass);
		wgpuBindGroupRelease(bg);

		// Vertical blur: filter_tex_b -> filter_tex_a
		params[0] = 0.0f; params[1] = 1.0f; // direction = vertical
		params[4] = radius_y;

		wgpuQueueWriteBuffer(ctx->queue, ctx->blur_params_buf, 0, params, 64);

		bg_entries[0].textureView = ctx->filter_view_b;
		bg = wgpuDeviceCreateBindGroup(ctx->device, &bg_desc);

		color_att.view = ctx->filter_view_a;
		rp_desc.label = WGPU_LABEL("blur_v");

		pass = wgpuCommandEncoderBeginRenderPass(ctx->encoder, &rp_desc);
		wgpuRenderPassEncoderSetPipeline(pass, ctx->blur_pipeline);
		wgpuRenderPassEncoderSetBindGroup(pass, 0, bg, 0, NULL);
		wgpuRenderPassEncoderDraw(pass, 6, 1, 0, 0);
		wgpuRenderPassEncoderEnd(pass);
		wgpuRenderPassEncoderRelease(pass);
		wgpuBindGroupRelease(bg);
	}
}

void render_webgpu_composite_filtered(WebGPURenderContext* ctx,
	float offset_x, float offset_y,
	float tint_r, float tint_g, float tint_b, float tint_a)
{
	// offset_x/y are in NDC space; tint rgba = 0 means passthrough
	float has_tint = (tint_r != 0 || tint_g != 0 || tint_b != 0 || tint_a != 0) ? 1.0f : 0.0f;
	float params[8] = {offset_x, offset_y, has_tint, 0, tint_r, tint_g, tint_b, tint_a};
	wgpuQueueWriteBuffer(ctx->queue, ctx->filter_quad_buffer, 0, params, 32);

	// Create bind group for composite: read filter_tex_a
	WGPUBindGroupEntry bg_entries[3] = {0};
	bg_entries[0].binding = 0;
	bg_entries[0].textureView = ctx->filter_view_a;
	bg_entries[1].binding = 1;
	bg_entries[1].sampler = ctx->filter_sampler;
	bg_entries[2].binding = 2;
	bg_entries[2].buffer = ctx->filter_quad_buffer;
	bg_entries[2].size = 32;

	WGPUBindGroupDescriptor bg_desc = {0};
	bg_desc.layout = ctx->composite_bgl;
	bg_desc.entryCount = 3;
	bg_desc.entries = bg_entries;
	WGPUBindGroup bg = wgpuDeviceCreateBindGroup(ctx->device, &bg_desc);

	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->composite_pipeline);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 0, bg, 0, NULL);
	wgpuRenderPassEncoderSetStencilReference(ctx->render_pass, 0);
	wgpuRenderPassEncoderDraw(ctx->render_pass, 6, 1, 0, 0);

	// Restore normal pipeline
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 0, ctx->vertex_storage_bg, 0, NULL);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 2, ctx->fragment_sampler_bg, 0, NULL);
	wgpuRenderPassEncoderSetBindGroup(ctx->render_pass, 1, ctx->vertex_uniform_bg, 0, NULL);

	wgpuBindGroupRelease(bg);
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
	if (ctx->stencil_write_pipeline)
		wgpuRenderPipelineRelease(ctx->stencil_write_pipeline);
	if (ctx->stencil_test_pipeline)
		wgpuRenderPipelineRelease(ctx->stencil_test_pipeline);
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
	if (ctx->depth_stencil_view) wgpuTextureViewRelease(ctx->depth_stencil_view);
	if (ctx->depth_stencil_texture) wgpuTextureRelease(ctx->depth_stencil_texture);

	// Release filter resources
	if (ctx->filter_msaa_view) wgpuTextureViewRelease(ctx->filter_msaa_view);
	if (ctx->filter_msaa_texture) wgpuTextureRelease(ctx->filter_msaa_texture);
	if (ctx->filter_view_a) wgpuTextureViewRelease(ctx->filter_view_a);
	if (ctx->filter_tex_a) wgpuTextureRelease(ctx->filter_tex_a);
	if (ctx->filter_view_b) wgpuTextureViewRelease(ctx->filter_view_b);
	if (ctx->filter_tex_b) wgpuTextureRelease(ctx->filter_tex_b);
	if (ctx->filter_sampler) wgpuSamplerRelease(ctx->filter_sampler);
	if (ctx->blur_params_buf) wgpuBufferRelease(ctx->blur_params_buf);
	if (ctx->filter_quad_buffer) wgpuBufferRelease(ctx->filter_quad_buffer);
	if (ctx->blur_pipeline) wgpuRenderPipelineRelease(ctx->blur_pipeline);
	if (ctx->blur_bgl) wgpuBindGroupLayoutRelease(ctx->blur_bgl);
	if (ctx->blur_pipeline_layout) wgpuPipelineLayoutRelease(ctx->blur_pipeline_layout);
	if (ctx->composite_pipeline) wgpuRenderPipelineRelease(ctx->composite_pipeline);
	if (ctx->composite_bgl) wgpuBindGroupLayoutRelease(ctx->composite_bgl);
	if (ctx->composite_pipeline_layout) wgpuPipelineLayoutRelease(ctx->composite_pipeline_layout);

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
