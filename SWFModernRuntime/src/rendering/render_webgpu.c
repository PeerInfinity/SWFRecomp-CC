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

// Renderer-mode flag. Set when the renderer must run without a window
// surface — no SDL, no JS canvas. Decoupled from HEADLESS_GRAPHICS so the
// new --mode=graphics native build can use offscreen rendering without
// inheriting the legacy headless frame loop in swf_headless.c.
// HEADLESS_GRAPHICS implies OFFSCREEN_RENDER (back-compat).
#if defined(HEADLESS_GRAPHICS) && !defined(OFFSCREEN_RENDER)
#define OFFSCREEN_RENDER
#endif

#ifdef OFFSCREEN_RENDER
// Offscreen mode: no SDL, no Emscripten — render to a buffer for capture.
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#elif !defined(__EMSCRIPTEN__)
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
"  let is_linear_rgb = (in.style.x >> 10u) & 0x1u;\n"
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
"    out.v_args = vec4f(inv_pos.xy, focal_z, f32(spread_mode) + f32(is_linear_rgb) * 4.0);\n"
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
"  let m = u32(mode + 0.5) & 0x3u;\n"
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
"// UVs are now in [0,1] range (normalization baked into inverse matrix)\n"
"fn linear_t(v_args: vec4f) -> f32 { return apply_spread(v_args.x, v_args.w); }\n"
"fn radial_t(v_args: vec4f) -> f32 { return apply_spread(length(v_args.xy * 2.0 - 1.0), v_args.w); }\n"
"fn focal_radial_t(v_args: vec4f) -> f32 {\n"
"  // Match Ruffle's focal gradient formula exactly (gradient.wgsl)\n"
"  let f = v_args.z;\n"
"  let uv = v_args.xy * 2.0 - 1.0;\n"
"  var d = vec2f(f, 0.0) - uv;\n"
"  let l = length(d);\n"
"  if (l < 0.00001) { return 0.0; }\n"
"  d = d / l;\n"
"  let denom = sqrt(max(1.0 - f * f * d.y * d.y, 0.0)) + f * d.x;\n"
"  if (abs(denom) < 0.00001) { return 0.0; }\n"
"  return apply_spread(l / denom, v_args.w);\n"
"}\n"
"\n"
"fn linear_to_srgb_ch(c: f32) -> f32 {\n"
"  if (c <= 0.0031308) { return c * 12.92; }\n"
"  return 1.055 * pow(c, 1.0 / 2.4) - 0.055;\n"
"}\n"
"fn apply_linear_to_srgb(color: vec4f) -> vec4f {\n"
"  var rgb = color.rgb;\n"
"  if (color.a > 0.0) { rgb = rgb / color.a; }\n"
"  let result = vec3f(linear_to_srgb_ch(rgb.r), linear_to_srgb_ch(rgb.g), linear_to_srgb_ch(rgb.b));\n"
"  return vec4f(result * color.a, color.a);\n"
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
"  // LinearRGB gradients: ramp stored in linear space, convert to sRGB\n"
"  if (is_gradient && (u32(in.v_args.w + 0.5) & 4u) != 0u) {\n"
"    color = apply_linear_to_srgb(color);\n"
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
	size_t data_size = size;  // actual data to upload
	if (size < 64) size = 64;

	WGPUBufferDescriptor desc = {0};
	desc.label = WGPU_LABEL(label);
	desc.size = size;
	desc.usage = usage;
	if (data)
		desc.usage |= WGPUBufferUsage_CopyDst;
	desc.mappedAtCreation = false;

	WGPUBuffer buffer = wgpuDeviceCreateBuffer(device, &desc);
	if (data && data_size > 0)
	{
		wgpuQueueWriteBuffer(queue, buffer, 0, data, data_size);
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
#elif defined(OFFSCREEN_RENDER)
	// Headless: use ProcessEvents polling (WaitAny requires timed wait features)
	(void)future;
	while (ctx->adapter == NULL)
		wgpuInstanceProcessEvents(ctx->instance);
#else
	// Native: poll until the callback fires
	WGPUFutureWaitInfo wait_info = {0};
	wait_info.future = future;
	wgpuInstanceWaitAny(ctx->instance, 1, &wait_info, UINT64_MAX);
#endif
}

static void on_uncaptured_error(const WGPUDevice* device, WGPUErrorType type,
                                struct WGPUStringView message, void* u1, void* u2)
{
	(void)device;(void)u1;(void)u2;
	fprintf(stderr, "WebGPU error (type %d): %.*s\n", (int)type,
		(int)message.length, message.data ? message.data : "");
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
#elif defined(OFFSCREEN_RENDER)
	(void)future;
	while (ctx->device == NULL)
		wgpuInstanceProcessEvents(ctx->instance);
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

// EmscriptenMouseEvent's targetX/Y are CSS-pixel coordinates relative to the
// canvas element. When the canvas is displayed at a different size than its
// internal pixel buffer (e.g. canvas.style.width=100% but canvas.width=320),
// targetX needs to be rescaled to canvas-internal pixel coordinates before
// being converted to twips. Without this scaling, button hit-tests miss
// whenever the canvas is rendered at a non-1:1 CSS:internal ratio.
// canvasX/canvasY in EmscriptenMouseEvent are deprecated and not populated
// (see html5.h note), so compute the scale here via canvas.width / clientWidth.
static void compute_canvas_mouse_pos(int target_x, int target_y, float* out_x, float* out_y) {
	double sx = (double)target_x;
	double sy = (double)target_y;
	EM_ASM({
		var c = document.getElementById('canvas');
		if (c) {
			var rw = c.clientWidth || c.width;
			var rh = c.clientHeight || c.height;
			if (rw > 0) HEAPF64[$0 >> 3] = HEAPF64[$0 >> 3] * c.width / rw;
			if (rh > 0) HEAPF64[$1 >> 3] = HEAPF64[$1 >> 3] * c.height / rh;
		}
	}, &sx, &sy);
	*out_x = (float)sx;
	*out_y = (float)sy;
}

static EM_BOOL on_mouse_move(int type, const EmscriptenMouseEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context) {
		float px, py;
		compute_canvas_mouse_pos(evt->targetX, evt->targetY, &px, &py);
		g_mouse_app_context->mouse.stage_x = px * 20.0f;
		g_mouse_app_context->mouse.stage_y = py * 20.0f;
	}
	return EM_TRUE;
}

static EM_BOOL on_mouse_down(int type, const EmscriptenMouseEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context && evt->button == 0) {
		g_mouse_app_context->mouse.button_down = 1;
		g_mouse_app_context->mouse.clicked = 1;
		float px, py;
		compute_canvas_mouse_pos(evt->targetX, evt->targetY, &px, &py);
		g_mouse_app_context->mouse.stage_x = px * 20.0f;
		g_mouse_app_context->mouse.stage_y = py * 20.0f;
	}
	return EM_TRUE;
}

static EM_BOOL on_mouse_up(int type, const EmscriptenMouseEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context && evt->button == 0) {
		g_mouse_app_context->mouse.button_down = 0;
		g_mouse_app_context->mouse.released = 1;
		float px, py;
		compute_canvas_mouse_pos(evt->targetX, evt->targetY, &px, &py);
		g_mouse_app_context->mouse.stage_x = px * 20.0f;
		g_mouse_app_context->mouse.stage_y = py * 20.0f;
	}
	return EM_TRUE;
}

static EM_BOOL on_key_down(int type, const EmscriptenKeyboardEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context) {
		int code = evt->keyCode;
		if (code >= 0 && code < 256) {
			g_mouse_app_context->keys.down[code] = 1;
			// Latch a press-edge so swf.c can dispatch keyPress / keyDown
			// even if a paired keyup arrives in the same 60Hz tick.
			g_mouse_app_context->keys.edge_down[code] = 1;
		}
		g_mouse_app_context->keys.last_key_down = code;
		g_mouse_app_context->keys.last_key_ascii = evt->which;
	}
	// Prevent default for arrow keys / space to stop page scrolling
	return EM_TRUE;
}

static EM_BOOL on_key_up(int type, const EmscriptenKeyboardEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (g_mouse_app_context) {
		int code = evt->keyCode;
		if (code >= 0 && code < 256) {
			g_mouse_app_context->keys.down[code] = 0;
			g_mouse_app_context->keys.edge_up[code] = 1;
		}
	}
	return EM_TRUE;
}

// Text input: ring buffer of typed Unicode codepoints (from emscripten
// keypress events, which fire AFTER dead-key composition and IME). Drained
// per-frame by swf.c into actionTextFieldInput.
#define TEXT_INPUT_RING_SIZE 64
int g_text_input_ring[TEXT_INPUT_RING_SIZE];
int g_text_input_ring_head = 0;  // write position (next free)
int g_text_input_ring_tail = 0;  // read position (next to consume)

static EM_BOOL on_keypress(int type, const EmscriptenKeyboardEvent* evt, void* ud) {
	(void)type; (void)ud;
	if (!g_mouse_app_context) return EM_TRUE;
	int cp = evt->charCode ? evt->charCode : evt->which;
	if (cp <= 0) return EM_TRUE;
	int next = (g_text_input_ring_head + 1) % TEXT_INPUT_RING_SIZE;
	if (next == g_text_input_ring_tail) return EM_TRUE;  // ring full — drop
	g_text_input_ring[g_text_input_ring_head] = cp;
	g_text_input_ring_head = next;
	return EM_TRUE;
}

// Window-blur flag — set by on_blur, drained per-frame in swf.c.
int g_window_focus_lost = 0;

static EM_BOOL on_blur(int type, const EmscriptenFocusEvent* evt, void* ud) {
	(void)type; (void)evt; (void)ud;
	g_window_focus_lost = 1;
	return EM_TRUE;
}

// IME (composition) state — emscripten has no native compositionstart/end
// callback, so we register listeners via EM_JS and bridge into these
// globals. swf.c drains them per-frame and dispatches actionTextFieldImeCompose
// / actionTextFieldImeCommit.
//
// During composition: g_ime_compose_text holds the current composition string.
// On compositionupdate: g_ime_compose_pending=1, swf.c calls Compose with text
//   and the caret position (set to end of text).
// On compositionend: g_ime_commit_pending=1, swf.c calls Commit with the
//   final text. Also clears any pending compose state.
#define IME_TEXT_BUF_SIZE 256
char g_ime_compose_text[IME_TEXT_BUF_SIZE];
char g_ime_commit_text[IME_TEXT_BUF_SIZE];
int  g_ime_compose_pending = 0;
int  g_ime_commit_pending  = 0;

EM_JS(void, ng_register_ime_listeners, (), {
	var c = document.getElementById('canvas');
	if (!c) return;
	c.addEventListener('compositionstart', function(e) {
		// Mark composition active — swf.c will start sending Compose calls.
		Module._ng_ime_compose_set('');
	});
	c.addEventListener('compositionupdate', function(e) {
		Module._ng_ime_compose_set(e.data || '');
	});
	c.addEventListener('compositionend', function(e) {
		Module._ng_ime_commit_set(e.data || '');
	});
});

// Called from JS via EM_ASM_INT-style bridging. Simple ASCII-truncation
// for the buffer; non-ASCII codepoints in compose text get UTF-8-encoded
// by the JS engine, which we accept as-is (the runtime decodes UTF-8).
EMSCRIPTEN_KEEPALIVE
void ng_ime_compose_set(const char* text) {
	if (!text) text = "";
	size_t n = 0;
	while (text[n] && n < IME_TEXT_BUF_SIZE - 1) { g_ime_compose_text[n] = text[n]; n++; }
	g_ime_compose_text[n] = '\0';
	g_ime_compose_pending = 1;
}

EMSCRIPTEN_KEEPALIVE
void ng_ime_commit_set(const char* text) {
	if (!text) text = "";
	size_t n = 0;
	while (text[n] && n < IME_TEXT_BUF_SIZE - 1) { g_ime_commit_text[n] = text[n]; n++; }
	g_ime_commit_text[n] = '\0';
	g_ime_commit_pending = 1;
}
#endif

// ---------------------------------------------------------------------------
// render_webgpu_new
// ---------------------------------------------------------------------------
WebGPURenderContext* render_webgpu_new(void)
{
	WebGPURenderContext* ctx = calloc(1, sizeof(WebGPURenderContext));
	// Default background is white when the SWF has no SetBackgroundColor tag
	// (matches Flash Player behavior). tagSetBackgroundColor overrides this
	// during recompiled tag execution.
	ctx->red = 255;
	ctx->green = 255;
	ctx->blue = 255;
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
#ifdef OFFSCREEN_RENDER
	// Headless mode: no surface, no window
	ctx->surface = NULL;
#elif defined(__EMSCRIPTEN__)
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
#ifndef OFFSCREEN_RENDER
	assert(ctx->surface != NULL);
#endif

	// --- Request adapter ---
	{
		WGPURequestAdapterOptions opts = {0};
#ifdef OFFSCREEN_RENDER
		opts.compatibleSurface = NULL;  // No surface in headless mode
#else
		opts.compatibleSurface = ctx->surface;
#endif
		opts.powerPreference = WGPUPowerPreference_HighPerformance;

		request_adapter_sync(ctx, &opts);
		assert(ctx->adapter != NULL);
	}

	// --- Request device ---
	{
		WGPUDeviceDescriptor dev_desc = {0};
		dev_desc.label = WGPU_LABEL("swf_device");
		dev_desc.defaultQueue.label = WGPU_LABEL("swf_queue");
		dev_desc.uncapturedErrorCallbackInfo.callback = on_uncaptured_error;

		// Request the adapter's full limits rather than the WebGPU defaults.
		// The default maxTextureArrayLayers is 256, but the gradient (and bitmap)
		// texture arrays use one layer per distinct gradient/bitmap — content-heavy
		// SWFs (e.g. Meteor Storm: 519 gradients) blow past 256, which makes the
		// array-texture creation fail. An invalid texture poisons the bind group
		// and silently drops EVERY command buffer that references it (including the
		// clear + MSAA resolve), so the offscreen target reads back as fully
		// transparent black. Requesting the adapter maximum (often 2048 layers,
		// larger buffer sizes) lets these games render. Limits queried from the
		// adapter are by definition grantable.
		WGPULimits adapter_limits = WGPU_LIMITS_INIT;
		WGPULimits required_limits = WGPU_LIMITS_INIT;
		if (wgpuAdapterGetLimits(ctx->adapter, &adapter_limits) == WGPUStatus_Success) {
			required_limits = adapter_limits;
			required_limits.nextInChain = NULL;
			dev_desc.requiredLimits = &required_limits;
		}

		request_device_sync(ctx, &dev_desc);
		assert(ctx->device != NULL);
	}

	// --- Configure surface (or create offscreen texture for headless) ---
	ctx->surface_format = WGPUTextureFormat_BGRA8Unorm;

#ifdef OFFSCREEN_RENDER
	// Create offscreen render target texture (used as MSAA resolve target)
	{
		WGPUTextureDescriptor offscreen_desc = {0};
		offscreen_desc.label = WGPU_LABEL("offscreen_target");
		offscreen_desc.dimension = WGPUTextureDimension_2D;
		offscreen_desc.size = (WGPUExtent3D){ctx->width, ctx->height, 1};
		offscreen_desc.format = ctx->surface_format;
		offscreen_desc.usage = WGPUTextureUsage_RenderAttachment | WGPUTextureUsage_CopySrc;
		offscreen_desc.mipLevelCount = 1;
		offscreen_desc.sampleCount = 1;
		ctx->offscreen_texture = wgpuDeviceCreateTexture(ctx->device, &offscreen_desc);
		assert(ctx->offscreen_texture != NULL);
		ctx->offscreen_view = wgpuTextureCreateView(ctx->offscreen_texture, NULL);

		// Create staging buffer for readback
		size_t row_bytes = (size_t)ctx->width * 4;
		// WebGPU requires bytesPerRow aligned to 256
		size_t aligned_row = (row_bytes + 255) & ~(size_t)255;
		ctx->readback_row_stride = aligned_row;
		WGPUBufferDescriptor buf_desc = {0};
		buf_desc.label = WGPU_LABEL("readback_buffer");
		buf_desc.size = aligned_row * ctx->height;
		buf_desc.usage = WGPUBufferUsage_CopyDst | WGPUBufferUsage_MapRead;
		buf_desc.mappedAtCreation = false;
		ctx->readback_buffer = wgpuDeviceCreateBuffer(ctx->device, &buf_desc);
		assert(ctx->readback_buffer != NULL);
	}
#else
	WGPUSurfaceConfiguration surf_config = {0};
	surf_config.device = ctx->device;
	surf_config.format = ctx->surface_format;
	surf_config.usage = WGPUTextureUsage_RenderAttachment;
	surf_config.alphaMode = WGPUCompositeAlphaMode_Auto;
	surf_config.width = ctx->width;
	surf_config.height = ctx->height;
	surf_config.presentMode = WGPUPresentMode_Fifo;
	wgpuSurfaceConfigure(ctx->surface, &surf_config);
#endif

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

	// --- Register mouse input callbacks (WASM only, not headless) ---
#if defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)
	g_mouse_app_context = app_context;
	emscripten_set_mousemove_callback("#canvas", NULL, 0, on_mouse_move);
	emscripten_set_mousedown_callback("#canvas", NULL, 0, on_mouse_down);
	emscripten_set_mouseup_callback("#canvas", NULL, 0, on_mouse_up);
	// Make canvas focusable, auto-focus, and re-focus on click
	EM_ASM({
		var c = document.getElementById('canvas');
		if (c) {
			c.setAttribute('tabindex', '0');
			c.style.outline = 'none';
			c.focus();
			c.addEventListener('mousedown', function() { c.focus(); });
		}
	});
	emscripten_set_keydown_callback("#canvas", NULL, 0, on_key_down);
	emscripten_set_keyup_callback("#canvas", NULL, 0, on_key_up);
	emscripten_set_keypress_callback("#canvas", NULL, 0, on_keypress);
	emscripten_set_blur_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, NULL, 0, on_blur);
	ng_register_ime_listeners();
#endif

	// Mark renderer as ready only if critical objects were created
	if (ctx->device && ctx->render_pipeline && ctx->queue)
		ctx->renderer_ok = 1;
	else
		fprintf(stderr, "Warning: WebGPU renderer not fully initialized, rendering disabled\n");
}

// ---------------------------------------------------------------------------
// create_buffers_and_upload: create GPU buffers and upload static data
// ---------------------------------------------------------------------------
static void create_buffers_and_upload(WebGPURenderContext* ctx)
{
	// Vertex buffer (shape geometry) — over-allocate for dynamic rendering.
	// MAX_DYNAMIC_RECTS must accommodate the largest per-frame draw count: each
	// dynamic createTextField with a border emits 4 draw_rect calls (one per
	// border edge), plus one draw_tris per glyph rendered. Tests like
	// avm1/edittext_stylesheet create 60+ text fields with borders + glyphs.
	#define MAX_DYNAMIC_RECTS 1024    // max color slots for dynamic rendering
	#define MAX_DYNAMIC_VERTICES 32768 // max vertices for dynamic rendering
	{
		u32 orig_verts = (u32)(ctx->shape_data_size / (4 * sizeof(u32)));
		size_t extra_bytes = (size_t)MAX_DYNAMIC_VERTICES * 4 * sizeof(u32);
		size_t total_size = ctx->shape_data_size + extra_bytes;
		ctx->vertex_buffer = create_buffer(ctx->device, ctx->queue,
			WGPUBufferUsage_Vertex | WGPUBufferUsage_CopyDst,
			NULL, total_size, "vertex_buffer");
		if (ctx->shape_data && ctx->shape_data_size > 0)
			wgpuQueueWriteBuffer(ctx->queue, ctx->vertex_buffer, 0,
				ctx->shape_data, ctx->shape_data_size);
		ctx->dynamic_vertex_base = orig_verts;
	}

	// Storage buffers
	// Over-allocate xform buffer to leave room for dynamic composed transform
	// slots.  compose_children() in tag.c needs unique slots when multiple
	// sprite instances share the same child transform_id.
	{
		u32 orig_slots = (u32)(ctx->transform_data_size / (16 * sizeof(float)));
		// Dynamic composed-transform slots, allocated fresh each frame by
		// compose_children() (one per nested/attached child instance). Games
		// that build a large grid of attachMovie'd clips need many: Tetris's
		// board alone is up to ~180 cells x 3 child shapes. 512 exhausted
		// mid-board, so the overflow fell back to overwriting the shared child
		// transform_id in place — every block collapsed onto the last one's
		// matrix (only one cell rendered). 4096 covers a full board + falling
		// piece + preview with headroom.
		u32 extra_slots = 4096;
		u32 total_slots = orig_slots + extra_slots;
		size_t total_size = (size_t)total_slots * 16 * sizeof(float);
		ctx->xform_buffer = create_buffer(ctx->device, ctx->queue,
			WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
			NULL, total_size, "xform_buffer");
		// Upload original data into the first orig_slots
		if (ctx->transform_data && ctx->transform_data_size > 0)
			wgpuQueueWriteBuffer(ctx->queue, ctx->xform_buffer, 0,
				ctx->transform_data, ctx->transform_data_size);
		ctx->xform_slot_count = total_slots;
	}

	// Color buffer — over-allocate for dynamic rect colors
	{
		u32 orig_colors = ctx->color_data_size > 0
			? (u32)(ctx->color_data_size / (4 * sizeof(float))) : 1;
		size_t extra_bytes = (size_t)MAX_DYNAMIC_RECTS * 4 * sizeof(float);
		size_t total_size = ctx->color_data_size + extra_bytes;
		ctx->color_buffer = create_buffer(ctx->device, ctx->queue,
			WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
			NULL, total_size, "color_buffer");
		if (ctx->color_data && ctx->color_data_size > 0)
			wgpuQueueWriteBuffer(ctx->queue, ctx->color_buffer, 0,
				ctx->color_data, ctx->color_data_size);
		ctx->dynamic_color_base = orig_colors;
	}

	// CPU staging mirrors for the dynamic vertex/color regions (batched upload —
	// see the comment on dyn_vtx_staging in render_webgpu.h).
	ctx->dyn_vtx_staging = (u32*)malloc((size_t)MAX_DYNAMIC_VERTICES * 4 * sizeof(u32));
	ctx->dyn_color_staging = (float*)malloc((size_t)MAX_DYNAMIC_RECTS * 4 * sizeof(float));

	// Retained-upload-skip mirrors (browser only — see prev_dyn_vtx in the header).
	// Native/OFFSCREEN leave these NULL so the skip is disabled and every frame
	// uploads as before (keeps the graphics-native test suite bit-for-bit).
#ifdef __EMSCRIPTEN__
	ctx->prev_dyn_vtx = (u32*)malloc((size_t)MAX_DYNAMIC_VERTICES * 4 * sizeof(u32));
	ctx->prev_dyn_color = (float*)malloc((size_t)MAX_DYNAMIC_RECTS * 4 * sizeof(float));
#endif
	ctx->prev_dyn_vtx_used = 0;
	ctx->prev_dyn_rect_count = 0;

	// Over-allocate uninv_mat and inv_mat buffers for dynamic gradient + bitmap matrices
	#define MAX_DYNAMIC_GRADIENTS 64
	#define MAX_DYNAMIC_BITMAPS 64
	{
		u32 static_mats = ctx->uninv_mat_data_size > 0
			? (u32)(ctx->uninv_mat_data_size / (16 * sizeof(float))) : 0;
		size_t total_mat_size = (size_t)(static_mats + MAX_DYNAMIC_GRADIENTS + MAX_DYNAMIC_BITMAPS) * 16 * sizeof(float);
		if (total_mat_size == 0) total_mat_size = 16 * sizeof(float); // minimum 1 slot

		ctx->uninv_mat_buffer = create_buffer(ctx->device, ctx->queue,
			WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
			NULL, total_mat_size, "uninv_mat_buffer");
		if (ctx->uninv_mat_data && ctx->uninv_mat_data_size > 0)
			wgpuQueueWriteBuffer(ctx->queue, ctx->uninv_mat_buffer, 0,
				ctx->uninv_mat_data, ctx->uninv_mat_data_size);

		ctx->inv_mat_buffer = create_buffer(ctx->device, ctx->queue,
			WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
			NULL, total_mat_size, "inv_mat_buffer");

		ctx->static_mat_count = static_mats;
		ctx->dynamic_gradient_capacity = MAX_DYNAMIC_GRADIENTS;
	}

	// Over-allocate bitmap_sizes_buffer for dynamic attached bitmaps
	{
		u32 total_bmp_slots = (u32)ctx->bitmap_count + MAX_DYNAMIC_BITMAPS;
		if (total_bmp_slots == 0) total_bmp_slots = 1;
		ctx->bitmap_sizes_buffer = create_buffer(ctx->device, ctx->queue,
			WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
			NULL, 2 * sizeof(u32) * total_bmp_slots, "bitmap_sizes_buffer");
		ctx->dynamic_bitmap_base = (u32)ctx->bitmap_count;
		ctx->dynamic_bitmap_capacity = MAX_DYNAMIC_BITMAPS;
		ctx->dynamic_bitmap_used = 0;
		// Callers (e.g. swf.c::swfStart) may pre-set these to fit a bundled
		// image larger than 256×256 before renderer_init; only apply the
		// default floor when unset.
		if (ctx->dynamic_bitmap_max_w == 0) ctx->dynamic_bitmap_max_w = 256;
		if (ctx->dynamic_bitmap_max_h == 0) ctx->dynamic_bitmap_max_h = 256;
	}

	// Over-allocate cxform buffer for dynamic runtime cxform slots
	// (Color.setRGB/setTransform modify cx_* at runtime)
	{
		u32 orig_cxform_slots = ctx->cxform_data_size > 0
			? (u32)(ctx->cxform_data_size / (20 * sizeof(float))) : 1;
		u32 extra_cxform_slots = 256;
		u32 total_cxform_slots = orig_cxform_slots + extra_cxform_slots;
		size_t total_cxform_size = (size_t)total_cxform_slots * 20 * sizeof(float);
		ctx->cxform_buffer = create_buffer(ctx->device, ctx->queue,
			WGPUBufferUsage_Storage | WGPUBufferUsage_CopyDst,
			NULL, total_cxform_size, "cxform_buffer");
		if (ctx->cxform_data && ctx->cxform_data_size > 0)
			wgpuQueueWriteBuffer(ctx->queue, ctx->cxform_buffer, 0,
				ctx->cxform_data, ctx->cxform_data_size);
		ctx->cxform_slot_count = total_cxform_slots;
	}

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
	u32 total_gradient_layers = (u32)num_gradients + MAX_DYNAMIC_GRADIENTS;
	if (total_gradient_layers == 0) total_gradient_layers = 1; // minimum 1 layer
	ctx->static_gradient_count = (u32)num_gradients;

	// --- Gradient texture array (always created, over-allocated for dynamic gradients) ---
	{
		WGPUTextureDescriptor tex_desc = {0};
		tex_desc.label = WGPU_LABEL("gradient_tex");
		tex_desc.dimension = WGPUTextureDimension_2D;
		tex_desc.size = (WGPUExtent3D){256, 1, total_gradient_layers};
		tex_desc.format = WGPUTextureFormat_RGBA8Unorm;
		tex_desc.mipLevelCount = 1;
		tex_desc.sampleCount = 1;
		tex_desc.usage = WGPUTextureUsage_TextureBinding | WGPUTextureUsage_CopyDst;
		ctx->gradient_tex = wgpuDeviceCreateTexture(ctx->device, &tex_desc);

		WGPUTextureViewDescriptor view_desc = {0};
		view_desc.dimension = WGPUTextureViewDimension_2DArray;
		view_desc.arrayLayerCount = total_gradient_layers;
		view_desc.mipLevelCount = 1;
		ctx->gradient_tex_view = wgpuTextureCreateView(ctx->gradient_tex, &view_desc);

		// Upload static gradient data
		if (num_gradients > 0)
		{
			WGPUTexelCopyTextureInfo dest = {0};
			dest.texture = ctx->gradient_tex;
			WGPUTexelCopyBufferLayout layout = {0};
			layout.bytesPerRow = 256 * 4;
			layout.rowsPerImage = 1;
			WGPUExtent3D extent = {256, 1, (u32)num_gradients};
			wgpuQueueWriteTexture(ctx->queue, &dest, ctx->gradient_data,
			                      num_gradients * 256 * 4, &layout, &extent);
		}

		WGPUSamplerDescriptor samp_desc = {0};
		samp_desc.label = WGPU_LABEL("gradient_sampler");
		samp_desc.addressModeU = WGPUAddressMode_ClampToEdge;
		samp_desc.addressModeV = WGPUAddressMode_ClampToEdge;
		samp_desc.magFilter = WGPUFilterMode_Linear;
		samp_desc.minFilter = WGPUFilterMode_Linear;
		samp_desc.maxAnisotropy = 1;
		ctx->gradient_sampler = wgpuDeviceCreateSampler(ctx->device, &samp_desc);
	}

	// --- Bitmap texture array (always created, over-allocated for dynamic attachBitmap) ---
	{
		u32 total_bitmap_layers = (u32)ctx->bitmap_count + MAX_DYNAMIC_BITMAPS;
		// Padded dimensions: max of static bitmaps and dynamic bitmap max size
		u32 bw = (u32)(ctx->bitmap_highest_w > 0 ? ctx->bitmap_highest_w + 1 : ctx->dynamic_bitmap_max_w + 1);
		u32 bh = (u32)(ctx->bitmap_highest_h > 0 ? ctx->bitmap_highest_h + 1 : ctx->dynamic_bitmap_max_h + 1);
		// If static bitmaps exist, ensure dynamic max fits within the texture dimensions
		if (ctx->bitmap_count > 0) {
			if (ctx->dynamic_bitmap_max_w + 1 > bw) bw = ctx->dynamic_bitmap_max_w + 1;
			if (ctx->dynamic_bitmap_max_h + 1 > bh) bh = ctx->dynamic_bitmap_max_h + 1;
		}
		// Update highest dimensions for upload consistency
		ctx->bitmap_highest_w = bw - 1;
		ctx->bitmap_highest_h = bh - 1;

		WGPUTextureDescriptor tex_desc = {0};
		tex_desc.label = WGPU_LABEL("bitmap_tex");
		tex_desc.dimension = WGPUTextureDimension_2D;
		tex_desc.size = (WGPUExtent3D){bw, bh, total_bitmap_layers};
		tex_desc.format = WGPUTextureFormat_RGBA8Unorm;
		tex_desc.mipLevelCount = 1;
		tex_desc.sampleCount = 1;
		tex_desc.usage = WGPUTextureUsage_TextureBinding | WGPUTextureUsage_CopyDst;
		ctx->bitmap_tex = wgpuDeviceCreateTexture(ctx->device, &tex_desc);

		WGPUTextureViewDescriptor view_desc = {0};
		view_desc.dimension = WGPUTextureViewDimension_2DArray;
		view_desc.arrayLayerCount = total_bitmap_layers;
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
	// Alpha: standard Porter-Duff "source over" — src_alpha + dst_alpha * (1 - src_alpha)
	// Using SrcAlpha here would square the alpha: src_alpha² + dst_alpha * (1 - src_alpha)
	blend.alpha.srcFactor = WGPUBlendFactor_One;
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
		blend_add.alpha.srcFactor = WGPUBlendFactor_One;
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

	// Premultiplied alpha (for attached BitmapData): One / OneMinusSrcAlpha
	{
		WGPUBlendState blend_premul = {0};
		blend_premul.color.srcFactor = WGPUBlendFactor_One;
		blend_premul.color.dstFactor = WGPUBlendFactor_OneMinusSrcAlpha;
		blend_premul.color.operation = WGPUBlendOperation_Add;
		blend_premul.alpha.srcFactor = WGPUBlendFactor_One;
		blend_premul.alpha.dstFactor = WGPUBlendFactor_OneMinusSrcAlpha;
		blend_premul.alpha.operation = WGPUBlendOperation_Add;

		WGPUColorTargetState ct_premul = color_target;
		ct_premul.blend = &blend_premul;
		WGPUFragmentState fs_premul = frag_state;
		fs_premul.targets = &ct_premul;

		rp_desc.label = WGPU_LABEL("blend_premul_pipeline");
		rp_desc.fragment = &fs_premul;
		ctx->blend_premul_pipeline = wgpuDeviceCreateRenderPipeline(ctx->device, &rp_desc);
		assert(ctx->blend_premul_pipeline != NULL);
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
#ifdef OFFSCREEN_RENDER
	// Headless mode: no events to poll
	(void)app_context;
	return 0;
#elif defined(__EMSCRIPTEN__)
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

// Overwrites the stage_to_ndc uniform buffer. Called from tag.c after
// render_webgpu_open_pass when _root has an AS-set transform to compose
// (e.g. _root._x = 200 shifting the whole scene).
void render_webgpu_upload_stage_transform(WebGPURenderContext* ctx, const float matrix[16])
{
	wgpuQueueWriteBuffer(ctx->queue, ctx->stage_to_ndc_buf, 0, matrix, 16 * sizeof(float));
}

// ---------------------------------------------------------------------------
// render_webgpu_open_pass
// ---------------------------------------------------------------------------
void render_webgpu_open_pass(WebGPURenderContext* ctx)
{
	if (!ctx->renderer_ok) return;
	ctx->dynamic_rect_count = 0;
	ctx->dynamic_vertex_used = 0;
	ctx->dynamic_gradient_used = 0;
	ctx->dynamic_bitmap_used = 0;
#ifdef OFFSCREEN_RENDER
	// Headless: use the persistent offscreen texture as resolve target
	ctx->surface_view = ctx->offscreen_view;
#else
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
#endif

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
	if (!ctx->renderer_ok) return;
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
// Dynamic vertex/color staging — accumulate into a CPU mirror of the dynamic
// region, flushed by render_webgpu_close_pass as one writeBuffer per buffer
// (instead of one tiny writeBuffer per shape). See dyn_vtx_staging in the header.
// ---------------------------------------------------------------------------
static inline void stage_dyn_verts(WebGPURenderContext* ctx, u32 vert_base,
	const void* verts, u32 vcount)
{
	if (ctx->dyn_vtx_staging == NULL) {   // staging unavailable — fall back to direct upload
		wgpuQueueWriteBuffer(ctx->queue, ctx->vertex_buffer,
			(uint64_t)vert_base * 4 * sizeof(u32), verts, (size_t)vcount * 4 * sizeof(u32));
		return;
	}
	memcpy(&ctx->dyn_vtx_staging[(size_t)(vert_base - ctx->dynamic_vertex_base) * 4],
		verts, (size_t)vcount * 4 * sizeof(u32));
}

static inline void stage_dyn_color(WebGPURenderContext* ctx, u32 color_idx,
	const float color[4])
{
	if (ctx->dyn_color_staging == NULL) {
		wgpuQueueWriteBuffer(ctx->queue, ctx->color_buffer,
			(uint64_t)color_idx * 4 * sizeof(float), color, 4 * sizeof(float));
		return;
	}
	float* dst = &ctx->dyn_color_staging[(size_t)(color_idx - ctx->dynamic_color_base) * 4];
	dst[0] = color[0]; dst[1] = color[1]; dst[2] = color[2]; dst[3] = color[3];
}

// ---------------------------------------------------------------------------
// render_webgpu_draw_rect — dynamic filled rectangle (for text field bg/border)
// ---------------------------------------------------------------------------
void render_webgpu_draw_rect(WebGPURenderContext* ctx,
	float x, float y, float w, float h,      // position/size in twips
	float r, float g, float b, float a,      // fill color (0-1)
	u32 transform_id, u32 cxform_id)
{
	if (!ctx->renderer_ok) return;
	if (ctx->dynamic_rect_count >= MAX_DYNAMIC_RECTS) return;
	if (ctx->dynamic_vertex_used + 6 > MAX_DYNAMIC_VERTICES) return;

	u32 idx = ctx->dynamic_rect_count++;
	u32 color_idx = ctx->dynamic_color_base + idx;
	u32 vert_base = ctx->dynamic_vertex_base + ctx->dynamic_vertex_used;
	ctx->dynamic_vertex_used += 6;

	// Stage color into the dynamic color slot (flushed once in close_pass)
	float color[4] = { r, g, b, a };
	stage_dyn_color(ctx, color_idx, color);

	// Generate 6 vertices (2 triangles) for the quad
	// Vertex format: { float x, float y, u32 style_x, u32 style_y }
	// style_x = 0x00 (solid color), style_y = color_idx
	union { float f; u32 u; } x0, y0, x1, y1;
	x0.f = x;       y0.f = y;
	x1.f = x + w;   y1.f = y + h;

	u32 sx = 0x00;   // solid color fill
	u32 sy = color_idx;

	u32 verts[6][4] = {
		{ x0.u, y0.u, sx, sy },  // top-left
		{ x1.u, y0.u, sx, sy },  // top-right
		{ x0.u, y1.u, sx, sy },  // bottom-left
		{ x1.u, y0.u, sx, sy },  // top-right
		{ x1.u, y1.u, sx, sy },  // bottom-right
		{ x0.u, y1.u, sx, sy },  // bottom-left
	};

	// Stage vertices into the dynamic area (flushed once in close_pass)
	stage_dyn_verts(ctx, vert_base, verts, 6);

	// Issue draw call
	render_webgpu_draw_shape(ctx, vert_base, 6, transform_id, cxform_id);
}

// ---------------------------------------------------------------------------
// render_webgpu_draw_tris — arbitrary solid-color triangles (for Drawing API)
// ---------------------------------------------------------------------------
void render_webgpu_draw_tris(WebGPURenderContext* ctx,
	const float* xy_pairs, u32 vertex_count,   // pre-tessellated triangle verts in twips
	float r, float g, float b, float a,        // fill color (0-1)
	u32 transform_id, u32 cxform_id)
{
	if (!ctx->renderer_ok || vertex_count == 0 || xy_pairs == NULL) return;
	if (ctx->dynamic_rect_count >= MAX_DYNAMIC_RECTS) return;
	if (ctx->dynamic_vertex_used + vertex_count > MAX_DYNAMIC_VERTICES)
		vertex_count = MAX_DYNAMIC_VERTICES - ctx->dynamic_vertex_used;
	if (vertex_count == 0) return;

	u32 idx = ctx->dynamic_rect_count++;
	u32 color_idx = ctx->dynamic_color_base + idx;

	// Stage color into the dynamic color slot (flushed once in close_pass)
	float color[4] = { r, g, b, a };
	stage_dyn_color(ctx, color_idx, color);

	u32 vert_base = ctx->dynamic_vertex_base + ctx->dynamic_vertex_used;
	ctx->dynamic_vertex_used += vertex_count;

	// Build vertex data: { float x, float y, u32 style_x, u32 style_y } per vertex
	u32 sx = 0x00;   // solid color fill
	u32 sy = color_idx;
	u32* verts = (u32*)malloc(vertex_count * 4 * sizeof(u32));
	for (u32 i = 0; i < vertex_count; i++) {
		union { float f; u32 u; } xv, yv;
		xv.f = xy_pairs[i * 2];
		yv.f = xy_pairs[i * 2 + 1];
		verts[i * 4 + 0] = xv.u;
		verts[i * 4 + 1] = yv.u;
		verts[i * 4 + 2] = sx;
		verts[i * 4 + 3] = sy;
	}

	// Write vertices to the dynamic area
	stage_dyn_verts(ctx, vert_base, verts, vertex_count);
	free(verts);

	// Issue draw call
	render_webgpu_draw_shape(ctx, vert_base, vertex_count, transform_id, cxform_id);
}

// ---------------------------------------------------------------------------
// CPU-side 4x4 matrix inverse (for dynamic gradient matrices)
// ---------------------------------------------------------------------------
static int invert_4x4_matrix(const float m[16], float inv[16])
{
	// For our 2D affine matrices, only the 2x2 + translation part matters.
	// Full 4x4 inverse for generality:
	float a = m[0], b = m[1], c = m[4], d = m[5];
	float tx = m[12], ty = m[13];
	float det = a * d - b * c;
	if (det == 0.0f) return 0;  // singular
	float inv_det = 1.0f / det;
	// Zero-initialize
	for (int i = 0; i < 16; i++) inv[i] = 0.0f;
	inv[0]  =  d * inv_det;
	inv[1]  = -b * inv_det;
	inv[4]  = -c * inv_det;
	inv[5]  =  a * inv_det;
	inv[10] = 1.0f;
	inv[15] = 1.0f;
	inv[12] = -(inv[0] * tx + inv[4] * ty);
	inv[13] = -(inv[1] * tx + inv[5] * ty);
	return 1;
}

// ---------------------------------------------------------------------------
// render_webgpu_draw_gradient_tris — gradient-filled triangles (Drawing API)
// ---------------------------------------------------------------------------
void render_webgpu_draw_gradient_tris(WebGPURenderContext* ctx,
	const float* xy_pairs, u32 vertex_count,
	u8 gradient_type, u8 spread_mode, u8 interpolation, float focal_ratio,
	const u8* gradient_ramp, const float* gradient_matrix,
	u32 transform_id, u32 cxform_id)
{
	if (!ctx->renderer_ok || vertex_count == 0 || xy_pairs == NULL) return;
	if (ctx->dynamic_gradient_used >= ctx->dynamic_gradient_capacity) return;
	if (ctx->dynamic_vertex_used + vertex_count > MAX_DYNAMIC_VERTICES)
		vertex_count = MAX_DYNAMIC_VERTICES - ctx->dynamic_vertex_used;
	if (vertex_count == 0) return;

	// Allocate a gradient layer (after all static gradients)
	u32 grad_id = ctx->static_gradient_count + ctx->dynamic_gradient_used;
	ctx->dynamic_gradient_used++;

	// Upload gradient ramp to this texture layer
	{
		WGPUTexelCopyTextureInfo dest = {0};
		dest.texture = ctx->gradient_tex;
		dest.origin = (WGPUOrigin3D){0, 0, grad_id};
		WGPUTexelCopyBufferLayout layout = {0};
		layout.bytesPerRow = 256 * 4;
		layout.rowsPerImage = 1;
		WGPUExtent3D extent = {256, 1, 1};
		wgpuQueueWriteTexture(ctx->queue, &dest, gradient_ramp,
		                      256 * 4, &layout, &extent);
	}

	// Compute inverse of the gradient matrix on CPU, then compose normalization
	// so that the vertex shader outputs [0,1] UVs instead of [-16384, 16384].
	// This matches Ruffle's precision characteristics (operations near 1.0 instead of 16384).
	{
		float inv_mat[16];
		if (!invert_4x4_matrix(gradient_matrix, inv_mat)) {
			// Singular matrix — use identity as fallback
			for (int i = 0; i < 16; i++) inv_mat[i] = (i % 5 == 0) ? 1.0f : 0.0f;
		}
		// Compose normalization: uv = (grad_coord + 16384) / 32768
		// In matrix form: scale by 1/32768, translate by +0.5
		float s = 1.0f / 32768.0f;
		float norm_inv[16];
		for (int i = 0; i < 16; i++) norm_inv[i] = 0.0f;
		norm_inv[0]  = inv_mat[0]  * s;
		norm_inv[1]  = inv_mat[1]  * s;
		norm_inv[4]  = inv_mat[4]  * s;
		norm_inv[5]  = inv_mat[5]  * s;
		norm_inv[10] = 1.0f;
		norm_inv[12] = inv_mat[12] * s + 0.5f;
		norm_inv[13] = inv_mat[13] * s + 0.5f;
		norm_inv[15] = 1.0f;
		uint64_t mat_offset = (uint64_t)grad_id * 16 * sizeof(float);
		wgpuQueueWriteBuffer(ctx->queue, ctx->inv_mat_buffer, mat_offset,
			norm_inv, 16 * sizeof(float));
	}

	// Allocate dynamic vertices (shared counter with draw_rect/draw_tris)
	u32 vert_base = ctx->dynamic_vertex_base + ctx->dynamic_vertex_used;
	ctx->dynamic_vertex_used += vertex_count;

	// Style encoding: gradient_type | (spread_mode << 8) | (interpolation << 10)
	u32 sx = (u32)gradient_type | ((u32)spread_mode << 8) | ((u32)interpolation << 10);

	// Style Y: gradient_id in lower 16, focal_encoded in upper 16
	u16 focal_encoded = (u16)(focal_ratio * 16384.0f + 32768.0f);
	u32 sy = (u32)grad_id | ((u32)focal_encoded << 16);

	u32* verts = (u32*)malloc(vertex_count * 4 * sizeof(u32));
	for (u32 i = 0; i < vertex_count; i++) {
		union { float f; u32 u; } xv, yv;
		xv.f = xy_pairs[i * 2];
		yv.f = xy_pairs[i * 2 + 1];
		verts[i * 4 + 0] = xv.u;
		verts[i * 4 + 1] = yv.u;
		verts[i * 4 + 2] = sx;
		verts[i * 4 + 3] = sy;
	}

	stage_dyn_verts(ctx, vert_base, verts, vertex_count);
	free(verts);

	render_webgpu_draw_shape(ctx, vert_base, vertex_count, transform_id, cxform_id);
}

// ---------------------------------------------------------------------------
// render_webgpu_draw_bitmap_quad_scaled — render an attached BitmapData as a
// textured quad with separate source (texture) and destination (quad) sizes.
//
// src_w/src_h: pixel dims of argb_pixels — drives texture upload + UV range.
// dst_w/dst_h: on-stage pixel dims — drives quad twips. The shader sample-
// stretches via UV mapping when src != dst (Flash's Video render rule).
// When src == dst, equivalent to the original unscaled function.
// ---------------------------------------------------------------------------
void render_webgpu_draw_bitmap_quad_scaled(WebGPURenderContext* ctx,
	const uint32_t* argb_pixels, u32 src_w, u32 src_h,
	u32 dst_w, u32 dst_h,
	float x_twips, float y_twips,
	u32 transform_id, u32 cxform_id)
{
	if (!ctx->renderer_ok || argb_pixels == NULL) return;
	if (src_w == 0 || src_h == 0 || dst_w == 0 || dst_h == 0) return;
	if (ctx->dynamic_bitmap_used >= ctx->dynamic_bitmap_capacity) return;
	if (src_w > ctx->dynamic_bitmap_max_w || src_h > ctx->dynamic_bitmap_max_h) return;
	if (ctx->dynamic_vertex_used + 6 > MAX_DYNAMIC_VERTICES) return;

	// Allocate a dynamic bitmap layer
	u32 bmp_layer = ctx->dynamic_bitmap_base + ctx->dynamic_bitmap_used;
	ctx->dynamic_bitmap_used++;

	// Upload ARGB pixels as RGBA to the bitmap texture layer.
	// Texture upload uses src dims; layer is padded to (bw, bh).
	{
		u32 bw = (u32)(ctx->bitmap_highest_w + 1);
		u32 bh = (u32)(ctx->bitmap_highest_h + 1);
		size_t slice_bytes = bw * bh * 4;
		u8* temp = (u8*)calloc(1, slice_bytes);

		// Convert premultiplied ARGB to premultiplied RGBA with edge clamping.
		// Keep premultiplied — renderer uses premultiplied alpha blend mode.
		u32* dst = (u32*)temp;
		for (u32 y = 0; y <= src_h; y++) {
			u32 sy = (y < src_h) ? y : src_h - 1;
			for (u32 x = 0; x <= src_w; x++) {
				u32 sx_px = (x < src_w) ? x : src_w - 1;
				u32 argb = argb_pixels[sy * src_w + sx_px];
				// ARGB u32: A=bits31-24, R=bits23-16, G=bits15-8, B=bits7-0
				u32 a = (argb >> 24) & 0xFF;
				u32 r = (argb >> 16) & 0xFF;
				u32 g = (argb >> 8) & 0xFF;
				u32 b = argb & 0xFF;
				// RGBA bytes on little-endian: R=byte0, G=byte1, B=byte2, A=byte3
				dst[y * bw + x] = r | (g << 8) | (b << 16) | (a << 24);
			}
		}

		WGPUTexelCopyTextureInfo dest = {0};
		dest.texture = ctx->bitmap_tex;
		dest.origin = (WGPUOrigin3D){0, 0, bmp_layer};
		WGPUTexelCopyBufferLayout layout = {0};
		layout.bytesPerRow = bw * 4;
		layout.rowsPerImage = bh;
		WGPUExtent3D extent = {bw, bh, 1};
		wgpuQueueWriteTexture(ctx->queue, &dest, temp, slice_bytes, &layout, &extent);

		// Upload bitmap_sizes for this layer — must match texture layer padded dimensions
		// so the shader's UV mapping (inv_pos / padded) correctly addresses the data.
		u32 sizes[2] = { bw, bh };
		wgpuQueueWriteBuffer(ctx->queue, ctx->bitmap_sizes_buffer,
			(uint64_t)bmp_layer * 2 * sizeof(u32), sizes, sizeof(sizes));

		free(temp);
	}

	// Compute and upload inverse matrix for UV mapping (twips → pixel coordinates).
	// Maps vertex position (x_twips, y_twips) → (0, 0) in bitmap space and
	// (x_twips + dst_w*20, y_twips + dst_h*20) → (src_w, src_h) in bitmap space.
	// Sample-stretch happens for free when src != dst.
	// Column-major 4x4: [sx, 0, 0, 0,  0, sy, 0, 0,  0, 0, 1, 0,  tx, ty, 0, 1]
	u32 inv_mat_id = ctx->static_mat_count + MAX_DYNAMIC_GRADIENTS + (ctx->dynamic_bitmap_used - 1);
	{
		float sx = (float)src_w / ((float)dst_w * 20.0f);
		float sy = (float)src_h / ((float)dst_h * 20.0f);
		float tx = -x_twips * sx;
		float ty = -y_twips * sy;
		float inv_mat[16] = {
			sx,   0.0f, 0.0f, 0.0f,
			0.0f, sy,   0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			tx,   ty,   0.0f, 1.0f
		};
		uint64_t mat_offset = (uint64_t)inv_mat_id * 16 * sizeof(float);
		wgpuQueueWriteBuffer(ctx->queue, ctx->inv_mat_buffer, mat_offset,
			inv_mat, 16 * sizeof(float));
	}

	// Generate 6 vertices (2 triangles) for the quad
	// Vertex format: { float x, float y, u32 style_type, u32 style_id }
	// style_type = 0x41 (clipped bitmap fill, no repeat)
	// style_id = bitmap_layer_id (lower 16) | inv_mat_id (upper 16)
	float w_twips = (float)dst_w * 20.0f;
	float h_twips = (float)dst_h * 20.0f;

	union { float f; u32 u; } x0, y0, x1, y1;
	x0.f = x_twips;            y0.f = y_twips;
	x1.f = x_twips + w_twips;  y1.f = y_twips + h_twips;

	u32 sx = 0x41;  // clipped bitmap fill
	u32 sy = (bmp_layer & 0xFFFF) | ((inv_mat_id & 0xFFFF) << 16);

	u32 vert_base = ctx->dynamic_vertex_base + ctx->dynamic_vertex_used;
	ctx->dynamic_vertex_used += 6;

	u32 verts[6][4] = {
		{ x0.u, y0.u, sx, sy },  // top-left
		{ x1.u, y0.u, sx, sy },  // top-right
		{ x0.u, y1.u, sx, sy },  // bottom-left
		{ x1.u, y0.u, sx, sy },  // top-right
		{ x1.u, y1.u, sx, sy },  // bottom-right
		{ x0.u, y1.u, sx, sy },  // bottom-left
	};

	stage_dyn_verts(ctx, vert_base, verts, 6);

	// Switch to premultiplied alpha blending for bitmap rendering
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->blend_premul_pipeline);
	render_webgpu_draw_shape(ctx, vert_base, 6, transform_id, cxform_id);
	// Restore normal blend pipeline
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
}

// Unscaled wrapper — quad geometry matches source dims (no GPU sample-stretch).
// Used by attachBitmap and the video render fallback when declared bounds are 0.
void render_webgpu_draw_bitmap_quad(WebGPURenderContext* ctx,
	const uint32_t* argb_pixels, u32 bmp_width, u32 bmp_height,
	float x_twips, float y_twips,
	u32 transform_id, u32 cxform_id)
{
	render_webgpu_draw_bitmap_quad_scaled(ctx, argb_pixels,
		bmp_width, bmp_height, bmp_width, bmp_height,
		x_twips, y_twips, transform_id, cxform_id);
}

// ---------------------------------------------------------------------------
// render_webgpu_draw_bitmap_tris — bitmap-filled triangles for the Drawing
// API's beginBitmapFill. Source `argb_pixels` is uploaded with row-stride
// padding to fill the whole bitmap-array layer: tiled (for repeat=true) or
// edge-clamped (for repeat=false), so that UVs outside the data region map
// to the desired values without a custom sampler.
// user_matrix6: a, b, c, d, tx_pixels, ty_pixels — maps bitmap pixel coords →
// MC local pixel coords (Flash semantics).
// ---------------------------------------------------------------------------
void render_webgpu_draw_bitmap_tris(WebGPURenderContext* ctx,
	const float* xy_pairs, u32 vertex_count,
	const uint32_t* argb_pixels, u32 src_w, u32 src_h,
	const float* user_matrix6, int repeat, int smooth,
	u32 transform_id, u32 cxform_id)
{
	(void)smooth;  // smoothing flag — sampler is currently fixed at linear
	if (!ctx->renderer_ok || vertex_count == 0 || xy_pairs == NULL) return;
	if (argb_pixels == NULL || src_w == 0 || src_h == 0) return;
	if (ctx->dynamic_bitmap_used >= ctx->dynamic_bitmap_capacity) return;
	if (ctx->dynamic_vertex_used + vertex_count > MAX_DYNAMIC_VERTICES)
		vertex_count = MAX_DYNAMIC_VERTICES - ctx->dynamic_vertex_used;
	if (vertex_count == 0) return;

	// Allocate dynamic bitmap layer
	u32 bmp_layer = ctx->dynamic_bitmap_base + ctx->dynamic_bitmap_used;
	ctx->dynamic_bitmap_used++;

	u32 bw = (u32)(ctx->bitmap_highest_w + 1);
	u32 bh = (u32)(ctx->bitmap_highest_h + 1);

	// Build the padded layer: tile for repeat=true, edge-clamp for repeat=false.
	{
		size_t slice_bytes = (size_t)bw * bh * 4;
		u8* temp = (u8*)calloc(1, slice_bytes);
		u32* dst = (u32*)temp;
		for (u32 y = 0; y < bh; y++) {
			u32 sy;
			if (repeat) sy = y % src_h;
			else        sy = (y < src_h) ? y : src_h - 1;
			for (u32 x = 0; x < bw; x++) {
				u32 sx;
				if (repeat) sx = x % src_w;
				else        sx = (x < src_w) ? x : src_w - 1;
				u32 argb = argb_pixels[sy * src_w + sx];
				u32 a = (argb >> 24) & 0xFF;
				u32 r = (argb >> 16) & 0xFF;
				u32 g = (argb >> 8)  & 0xFF;
				u32 b =  argb        & 0xFF;
				dst[y * bw + x] = r | (g << 8) | (b << 16) | (a << 24);
			}
		}

		WGPUTexelCopyTextureInfo dest = {0};
		dest.texture = ctx->bitmap_tex;
		dest.origin = (WGPUOrigin3D){0, 0, bmp_layer};
		WGPUTexelCopyBufferLayout layout = {0};
		layout.bytesPerRow = bw * 4;
		layout.rowsPerImage = bh;
		WGPUExtent3D extent = {bw, bh, 1};
		wgpuQueueWriteTexture(ctx->queue, &dest, temp, slice_bytes, &layout, &extent);

		// Record the bitmap size for the layer (same convention as other paths).
		u32 sizes[2] = { bw, bh };
		wgpuQueueWriteBuffer(ctx->queue, ctx->bitmap_sizes_buffer,
			(uint64_t)bmp_layer * 2 * sizeof(u32), sizes, sizeof(sizes));

		free(temp);
	}

	// Compose inv_mat: pos_twips → bitmap_pixel_coord in layer space.
	// Flash matrix M = [a, c, tx; b, d, ty] maps bitmap_pixel → mc_local_pixel.
	// M^-1 maps mc_local_pixel → bitmap_pixel. We also fold a (1/20) factor so
	// the matrix consumes pos_twips directly.
	u32 inv_mat_id = ctx->static_mat_count + MAX_DYNAMIC_GRADIENTS + (ctx->dynamic_bitmap_used - 1);
	{
		float a = user_matrix6[0], b = user_matrix6[1];
		float c = user_matrix6[2], d = user_matrix6[3];
		float tx = user_matrix6[4], ty = user_matrix6[5];
		float det = a * d - b * c;
		float inv_mat[16];
		for (int i = 0; i < 16; i++) inv_mat[i] = 0.0f;
		inv_mat[10] = 1.0f;
		inv_mat[15] = 1.0f;
		if (det != 0.0f) {
			float inv_det = 1.0f / det;
			float ai =  d * inv_det, bi = -b * inv_det;
			float ci = -c * inv_det, di =  a * inv_det;
			// Translation in inverse: -M^-1 * t (pixel space)
			float txi = -(ai * tx + ci * ty);
			float tyi = -(bi * tx + di * ty);
			// Combined matrix: (1/20) scale on the 2x2 part folds in the twips→pixel divide.
			inv_mat[0]  = ai / 20.0f;
			inv_mat[1]  = bi / 20.0f;
			inv_mat[4]  = ci / 20.0f;
			inv_mat[5]  = di / 20.0f;
			inv_mat[12] = txi;
			inv_mat[13] = tyi;
		} else {
			// Singular: collapse to (0,0) — fill samples bitmap origin
			inv_mat[0] = 0.0f; inv_mat[5] = 0.0f;
			inv_mat[12] = 0.0f; inv_mat[13] = 0.0f;
		}
		uint64_t mat_offset = (uint64_t)inv_mat_id * 16 * sizeof(float);
		wgpuQueueWriteBuffer(ctx->queue, ctx->inv_mat_buffer, mat_offset,
			inv_mat, 16 * sizeof(float));
	}

	// Generate triangle vertices.
	// style_type 0x40 = repeating bitmap fill, 0x41 = clipped (no repeat).
	u32 sx_word = repeat ? 0x40u : 0x41u;
	u32 sy_word = (bmp_layer & 0xFFFFu) | ((inv_mat_id & 0xFFFFu) << 16);

	u32 vert_base = ctx->dynamic_vertex_base + ctx->dynamic_vertex_used;
	ctx->dynamic_vertex_used += vertex_count;

	u32* verts = (u32*)malloc((size_t)vertex_count * 4 * sizeof(u32));
	for (u32 i = 0; i < vertex_count; i++) {
		union { float f; u32 u; } xv, yv;
		xv.f = xy_pairs[i * 2];
		yv.f = xy_pairs[i * 2 + 1];
		verts[i * 4 + 0] = xv.u;
		verts[i * 4 + 1] = yv.u;
		verts[i * 4 + 2] = sx_word;
		verts[i * 4 + 3] = sy_word;
	}
	stage_dyn_verts(ctx, vert_base, verts, vertex_count);
	free(verts);

	// Premultiplied blend (bitmap data is pre-multiplied via fillRect).
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->blend_premul_pipeline);
	render_webgpu_draw_shape(ctx, vert_base, vertex_count, transform_id, cxform_id);
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
}

// ---------------------------------------------------------------------------
// Clip mask control: stencil-based clipping for PlaceObject2 clipDepth
// ---------------------------------------------------------------------------
void render_webgpu_begin_clip_mask(WebGPURenderContext* ctx)
{
	if (!ctx->renderer_ok) return;
	// Switch to stencil-write pipeline: draws to stencil buffer only (no color)
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->stencil_write_pipeline);
	wgpuRenderPassEncoderSetStencilReference(ctx->render_pass, 1);
}

void render_webgpu_end_clip_mask(WebGPURenderContext* ctx)
{
	if (!ctx->renderer_ok) return;
	// Switch to stencil-test pipeline: only draws where stencil == 1 (inside mask)
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->stencil_test_pipeline);
	wgpuRenderPassEncoderSetStencilReference(ctx->render_pass, 1);
}

void render_webgpu_end_clip(WebGPURenderContext* ctx)
{
	if (!ctx->renderer_ok) return;
	// Switch back to normal pipeline (no stencil testing)
	wgpuRenderPassEncoderSetPipeline(ctx->render_pass, ctx->render_pipeline);
}

void render_webgpu_set_blend_mode(WebGPURenderContext* ctx, u8 blend_mode)
{
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;

	// Flush this frame's batched dynamic vertex/color staging — ONE writeBuffer per
	// buffer instead of one tiny writeBuffer per shape (the per-call overhead
	// dominated browser frame CPU). queue.writeBuffer is ordered before the submit
	// below, so the dynamic regions hold their final data before any recorded draw
	// executes. The used ranges are fully populated (each draw writes its slice
	// contiguously from offset 0), so flushing [0, used) is exact.
	// Retained-mode upload skip: a fully static screen (e.g. the Minesweeper
	// difficulty screen) re-tessellates and re-stages byte-identical dynamic
	// geometry every frame — ~281 KB/frame of vertices that never change. The
	// vertex/color buffers still hold the previous frame's bytes (we never clear
	// them), and the per-frame draw calls reference the same offsets, so when this
	// frame's staged content matches what was last uploaded we can skip the
	// writeBuffer entirely and the GPU reads the identical retained data →
	// pixel-identical output, zero re-upload. We compare against an exact CPU copy
	// of the last upload (memcmp, not a hash) so correctness is provable, and skip
	// the vertex and color regions independently. writeBuffer bytes were the only
	// frame-CPU cost that survives on a real GPU (the SwiftShader createView cost
	// is a software-present artifact), so cutting them is the lever toward 30fps.
	if (ctx->dyn_vtx_staging != NULL && ctx->dynamic_vertex_used > 0)
	{
		size_t vbytes = (size_t)ctx->dynamic_vertex_used * 4 * sizeof(u32);
		int unchanged = (ctx->prev_dyn_vtx != NULL &&
			ctx->prev_dyn_vtx_used == ctx->dynamic_vertex_used &&
			memcmp(ctx->prev_dyn_vtx, ctx->dyn_vtx_staging, vbytes) == 0);
		if (!unchanged)
		{
			wgpuQueueWriteBuffer(ctx->queue, ctx->vertex_buffer,
				(uint64_t)ctx->dynamic_vertex_base * 4 * sizeof(u32),
				ctx->dyn_vtx_staging, vbytes);
			if (ctx->prev_dyn_vtx != NULL)
			{
				memcpy(ctx->prev_dyn_vtx, ctx->dyn_vtx_staging, vbytes);
				ctx->prev_dyn_vtx_used = ctx->dynamic_vertex_used;
			}
		}
	}
	else { ctx->prev_dyn_vtx_used = 0; }  // empty frame: invalidate retained copy

	if (ctx->dyn_color_staging != NULL && ctx->dynamic_rect_count > 0)
	{
		size_t cbytes = (size_t)ctx->dynamic_rect_count * 4 * sizeof(float);
		int unchanged = (ctx->prev_dyn_color != NULL &&
			ctx->prev_dyn_rect_count == ctx->dynamic_rect_count &&
			memcmp(ctx->prev_dyn_color, ctx->dyn_color_staging, cbytes) == 0);
		if (!unchanged)
		{
			wgpuQueueWriteBuffer(ctx->queue, ctx->color_buffer,
				(uint64_t)ctx->dynamic_color_base * 4 * sizeof(float),
				ctx->dyn_color_staging, cbytes);
			if (ctx->prev_dyn_color != NULL)
			{
				memcpy(ctx->prev_dyn_color, ctx->dyn_color_staging, cbytes);
				ctx->prev_dyn_rect_count = ctx->dynamic_rect_count;
			}
		}
	}
	else { ctx->prev_dyn_rect_count = 0; }  // empty frame: invalidate retained copy

	wgpuRenderPassEncoderEnd(ctx->render_pass);

#ifdef OFFSCREEN_RENDER
	// Headless: copy offscreen texture to staging buffer for readback
	if (ctx->capture_requested)
	{
		WGPUTexelCopyTextureInfo src = {0};
		src.texture = ctx->offscreen_texture;
		src.mipLevel = 0;
		src.origin = (WGPUOrigin3D){0, 0, 0};
		src.aspect = WGPUTextureAspect_All;

		WGPUTexelCopyBufferInfo dst = {0};
		dst.buffer = ctx->readback_buffer;
		dst.layout.offset = 0;
		dst.layout.bytesPerRow = (uint32_t)ctx->readback_row_stride;
		dst.layout.rowsPerImage = ctx->height;

		WGPUExtent3D copy_size = {(uint32_t)ctx->width, (uint32_t)ctx->height, 1};
		wgpuCommandEncoderCopyTextureToBuffer(ctx->encoder, &src, &dst, &copy_size);
	}
#endif

	WGPUCommandBufferDescriptor cmd_desc = {0};
	WGPUCommandBuffer cmd = wgpuCommandEncoderFinish(ctx->encoder, &cmd_desc);
	wgpuQueueSubmit(ctx->queue, 1, &cmd);

#ifdef OFFSCREEN_RENDER
	// Headless: no surface to present
#elif !defined(__EMSCRIPTEN__)
	wgpuSurfacePresent(ctx->surface);
#endif

	// Release per-frame objects
	wgpuCommandBufferRelease(cmd);
	wgpuRenderPassEncoderRelease(ctx->render_pass);
	wgpuCommandEncoderRelease(ctx->encoder);
#ifndef OFFSCREEN_RENDER
	wgpuTextureViewRelease(ctx->surface_view);
#endif

	ctx->render_pass = NULL;
	ctx->encoder = NULL;
#ifndef OFFSCREEN_RENDER
	ctx->surface_view = NULL;
#endif
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
	if (!ctx->renderer_ok) return;
	// Upload to GPU buffer (matching flashbang behavior).
	// Not yet bound to shaders — deferred until both backends' shaders are updated.
	u32 id_data[4] = {transform_id, 0, 0, 0};
	wgpuQueueWriteBuffer(ctx->queue, ctx->extra_transform_id_buf, 0, id_data, 16);
}

void render_webgpu_upload_extra_transform(WebGPURenderContext* ctx, float* transform)
{
	if (!ctx->renderer_ok) return;
	// Upload mat4 to GPU buffer (matching flashbang behavior).
	// Not yet bound to shaders — deferred until both backends' shaders are updated.
	wgpuQueueWriteBuffer(ctx->queue, ctx->extra_transform_buf, 0, transform, 16 * sizeof(float));
}

void render_webgpu_upload_cxform_id(WebGPURenderContext* ctx, u32 cxform_id)
{
	if (!ctx->renderer_ok) return;
	// Upload to GPU buffer (matching flashbang behavior).
	// Not yet bound to shaders — deferred until both backends' shaders are updated.
	u32 id_data[4] = {cxform_id, 0, 0, 0};
	wgpuQueueWriteBuffer(ctx->queue, ctx->cxform_id_buf, 0, id_data, 16);
}

void render_webgpu_upload_cxform(WebGPURenderContext* ctx, float* cxform)
{
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
	uint64_t offset = (uint64_t)transform_id * 16 * sizeof(float);
	wgpuQueueWriteBuffer(ctx->queue, ctx->xform_buffer, offset,
	                     composed, 16 * sizeof(float));
}

// ---------------------------------------------------------------------------
// render_webgpu_write_cxform: write a 20-float cxform entry to the GPU
// cxform_buffer at the given slot.  Used for runtime Color.setRGB/setTransform.
// ---------------------------------------------------------------------------
void render_webgpu_write_cxform(WebGPURenderContext* ctx,
                                u32 cxform_slot, const float cxform[20])
{
	if (!ctx->renderer_ok) return;
	uint64_t offset = (uint64_t)cxform_slot * 20 * sizeof(float);
	wgpuQueueWriteBuffer(ctx->queue, ctx->cxform_buffer, offset,
	                     cxform, 20 * sizeof(float));
}

// ---------------------------------------------------------------------------
// render_webgpu_update_vertices / render_webgpu_update_colors
// Write interpolated morph data into GPU buffers before the render pass.
// ---------------------------------------------------------------------------
void render_webgpu_update_vertices(WebGPURenderContext* ctx,
	size_t byte_offset, const void* data, size_t byte_size)
{
	if (!ctx->renderer_ok) return;
	wgpuQueueWriteBuffer(ctx->queue, ctx->vertex_buffer, byte_offset, data, byte_size);
}

void render_webgpu_update_colors(WebGPURenderContext* ctx,
	size_t byte_offset, const void* data, size_t byte_size)
{
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
	if (ctx->render_pass)
	{
		wgpuRenderPassEncoderEnd(ctx->render_pass);
		wgpuRenderPassEncoderRelease(ctx->render_pass);
		ctx->render_pass = NULL;
	}
}

void render_webgpu_resume_pass(WebGPURenderContext* ctx)
{
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
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
	if (!ctx->renderer_ok) return;
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
	if (ctx->blend_premul_pipeline)
		wgpuRenderPipelineRelease(ctx->blend_premul_pipeline);
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
#if !defined(__EMSCRIPTEN__) && !defined(OFFSCREEN_RENDER)
	if (ctx->window)
		SDL_DestroyWindow(ctx->window);
#endif

#ifdef OFFSCREEN_RENDER
	// Release headless resources
	if (ctx->offscreen_view) wgpuTextureViewRelease(ctx->offscreen_view);
	if (ctx->offscreen_texture) wgpuTextureRelease(ctx->offscreen_texture);
	if (ctx->readback_buffer) wgpuBufferRelease(ctx->readback_buffer);
#endif

	free(ctx);
}

// ---------------------------------------------------------------------------
// Headless framebuffer capture and PNG output
// ---------------------------------------------------------------------------
#ifdef OFFSCREEN_RENDER

// Synchronous callback state for buffer mapping
static volatile int g_map_done = 0;
static volatile WGPUMapAsyncStatus g_map_status;

static void on_map_callback(WGPUMapAsyncStatus status,
                            WGPUStringView message,
                            void* userdata1, void* userdata2)
{
	(void)message;
	(void)userdata1;
	(void)userdata2;
	g_map_status = status;
	g_map_done = 1;
}

void render_webgpu_request_capture(WebGPURenderContext* ctx)
{
	ctx->capture_requested = 1;
}

int render_webgpu_save_png(WebGPURenderContext* ctx, const char* path)
{
	if (!ctx->readback_buffer) return 0;

	// Map the staging buffer synchronously
	g_map_done = 0;
	WGPUBufferMapCallbackInfo map_info = {0};
	map_info.mode = WGPUCallbackMode_AllowProcessEvents;
	map_info.callback = on_map_callback;
	wgpuBufferMapAsync(ctx->readback_buffer, WGPUMapMode_Read, 0,
	                   ctx->readback_row_stride * ctx->height, map_info);

	// Poll until mapped (synchronous spin — fine for headless test runner)
	while (!g_map_done) {
		wgpuInstanceProcessEvents(ctx->instance);
	}

	if (g_map_status != WGPUMapAsyncStatus_Success) {
		fprintf(stderr, "render_webgpu_save_png: buffer map failed (status %d)\n",
		        (int)g_map_status);
		return 0;
	}

	const void* mapped = wgpuBufferGetConstMappedRange(ctx->readback_buffer, 0,
	                                                   ctx->readback_row_stride * ctx->height);
	if (!mapped) {
		wgpuBufferUnmap(ctx->readback_buffer);
		return 0;
	}

	// Convert BGRA8 (GPU format) to RGBA8 (PNG format), stripping row padding
	int w = ctx->width;
	int h = ctx->height;
	unsigned char* rgba = malloc(w * h * 4);
	if (!rgba) {
		wgpuBufferUnmap(ctx->readback_buffer);
		return 0;
	}

	for (int y = 0; y < h; y++) {
		const unsigned char* src_row = (const unsigned char*)mapped + y * ctx->readback_row_stride;
		unsigned char* dst_row = rgba + y * w * 4;
		for (int x = 0; x < w; x++) {
			dst_row[x * 4 + 0] = src_row[x * 4 + 2]; // R <- B
			dst_row[x * 4 + 1] = src_row[x * 4 + 1]; // G <- G
			dst_row[x * 4 + 2] = src_row[x * 4 + 0]; // B <- R
			dst_row[x * 4 + 3] = src_row[x * 4 + 3]; // A <- A
		}
	}

	wgpuBufferUnmap(ctx->readback_buffer);

	// Write PNG
	int ok = stbi_write_png(path, w, h, 4, rgba, w * 4);
	free(rgba);

	ctx->capture_requested = 0;
	return ok;
}

#endif // OFFSCREEN_RENDER
