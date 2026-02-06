// Fragment shader — direct port of fragment.glsl
// Matches the bind group layout used by render_webgpu.c
//
// Note: WebGPU requires separate texture and sampler bindings,
// unlike GLSL's combined sampler2DArray.

// Group 2: Per-pipeline fragment texture/sampler bindings
@group(2) @binding(0) var gradient_tex: texture_2d_array<f32>;
@group(2) @binding(1) var gradient_samp: sampler;
@group(2) @binding(2) var bitmap_tex: texture_2d_array<f32>;
@group(2) @binding(3) var bitmap_samp: sampler;

struct FragmentInput {
	@location(0) @interpolate(flat) v_style_type: u32,
	@location(1) @interpolate(flat) v_style_id: u32,
	@location(2) v_args: vec4f,
};

fn linear_t(v_args: vec4f) -> f32 {
	return (v_args.x + 16384.0) / 32768.0;
}

fn radial_t(v_args: vec4f) -> f32 {
	return distance(v_args.xy, vec2f(0.0, 0.0)) / 16384.0;
}

@fragment
fn fs_main(in: FragmentInput) -> @location(0) vec4f {
	if (in.v_style_type == 0x00u) {
		// Solid color
		return in.v_args;
	} else if (in.v_style_type == 0x10u) {
		// Linear gradient
		return textureSample(gradient_tex, gradient_samp,
			vec2f(linear_t(in.v_args), 0.5), i32(in.v_style_id));
	} else if (in.v_style_type == 0x12u) {
		// Radial gradient
		return textureSample(gradient_tex, gradient_samp,
			vec2f(radial_t(in.v_args), 0.5), i32(in.v_style_id));
	} else if (in.v_style_type == 0x41u) {
		// Bitmap
		return textureSample(bitmap_tex, bitmap_samp,
			in.v_args.xy, i32(in.v_style_id));
	}
	return vec4f(0.0);
}
