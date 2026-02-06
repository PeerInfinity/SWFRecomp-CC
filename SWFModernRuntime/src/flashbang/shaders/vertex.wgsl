// Vertex shader — direct port of vertex.glsl
// Matches the bind group layout used by render_webgpu.c

// Group 0: Per-pipeline vertex storage buffers
@group(0) @binding(0) var<storage, read> transforms: array<mat4x4f>;
@group(0) @binding(1) var<storage, read> colors: array<vec4f>;
@group(0) @binding(2) var<storage, read> inv_mats: array<mat4x4f>;
@group(0) @binding(3) var<storage, read> bitmap_sizes: array<vec2u>;

// Group 1: Per-draw vertex uniforms
struct StageTransform {
	matrix: mat4x4f,
};
@group(1) @binding(0) var<uniform> stage_transform: StageTransform;

struct TransformID {
	id: u32,
};
@group(1) @binding(1) var<uniform> current_transform: TransformID;

struct VertexInput {
	@location(0) position: vec2f,
	@location(1) style: vec2u,
};

struct VertexOutput {
	@builtin(position) position: vec4f,
	@location(0) @interpolate(flat) v_style_type: u32,
	@location(1) @interpolate(flat) v_style_id: u32,
	@location(2) v_args: vec4f,
};

@vertex
fn vs_main(in: VertexInput) -> VertexOutput {
	var out: VertexOutput;

	let transform = transforms[current_transform.id];
	let pos = vec4f(in.position, 0.0, 1.0);

	out.v_style_type = in.style.x;
	out.v_style_id = in.style.y & 0xFFFFu;
	let style_upper = (in.style.y >> 16u) & 0xFFFFu;

	out.position = stage_transform.matrix * transform * pos;

	// Pre-compute fill arguments based on style type
	if (out.v_style_type == 0x00u) {
		// Solid color: pass color directly
		out.v_args = colors[out.v_style_id];
	} else if ((out.v_style_type & 0xF0u) == 0x10u) {
		// Gradient: compute UV via inverse matrix
		let inv_pos = inv_mats[out.v_style_id] * pos;
		out.v_args = vec4f(inv_pos.xy, 0.0, 0.0);
	} else if ((out.v_style_type & 0xF0u) == 0x40u) {
		// Bitmap: compute UV via inverse matrix, normalized by bitmap size
		let inv_pos = inv_mats[style_upper] * pos;
		let sizes = bitmap_sizes[out.v_style_id];
		out.v_args = vec4f(inv_pos.x / f32(sizes.x), inv_pos.y / f32(sizes.y), 0.0, 0.0);
	} else {
		out.v_args = vec4f(0.0);
	}

	return out;
}
