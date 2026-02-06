// Compute shader — port of compute.glsl
// Inverts gradient transformation matrices on the GPU.
//
// WGSL has no built-in inverse() for matrices, so we implement
// 4x4 matrix inversion using the adjugate/determinant method.

@group(0) @binding(0) var<storage, read> gradmats: array<mat4x4f>;
@group(1) @binding(0) var<storage, read_write> inv_gradmats: array<mat4x4f>;

// 4x4 matrix inverse via cofactor expansion.
// WGSL mat4x4f is column-major: m[col][row].
fn mat4_inverse(m: mat4x4f) -> mat4x4f {
	let a00 = m[0][0]; let a01 = m[0][1]; let a02 = m[0][2]; let a03 = m[0][3];
	let a10 = m[1][0]; let a11 = m[1][1]; let a12 = m[1][2]; let a13 = m[1][3];
	let a20 = m[2][0]; let a21 = m[2][1]; let a22 = m[2][2]; let a23 = m[2][3];
	let a30 = m[3][0]; let a31 = m[3][1]; let a32 = m[3][2]; let a33 = m[3][3];

	// 2x2 sub-determinants from rows 0,1
	let s0 = a00 * a11 - a10 * a01;
	let s1 = a00 * a12 - a10 * a02;
	let s2 = a00 * a13 - a10 * a03;
	let s3 = a01 * a12 - a11 * a02;
	let s4 = a01 * a13 - a11 * a03;
	let s5 = a02 * a13 - a12 * a03;

	// 2x2 sub-determinants from rows 2,3
	let c5 = a22 * a33 - a32 * a23;
	let c4 = a21 * a33 - a31 * a23;
	let c3 = a21 * a32 - a31 * a22;
	let c2 = a20 * a33 - a30 * a23;
	let c1 = a20 * a32 - a30 * a22;
	let c0 = a20 * a31 - a30 * a21;

	let det = s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
	let inv_det = 1.0 / det;

	// Adjugate matrix (transposed cofactor) divided by determinant
	return mat4x4f(
		// Column 0
		vec4f(
			( a11 * c5 - a12 * c4 + a13 * c3) * inv_det,
			(-a01 * c5 + a02 * c4 - a03 * c3) * inv_det,
			( a31 * s5 - a32 * s4 + a33 * s3) * inv_det,
			(-a21 * s5 + a22 * s4 - a23 * s3) * inv_det,
		),
		// Column 1
		vec4f(
			(-a10 * c5 + a12 * c2 - a13 * c1) * inv_det,
			( a00 * c5 - a02 * c2 + a03 * c1) * inv_det,
			(-a30 * s5 + a32 * s2 - a33 * s1) * inv_det,
			( a20 * s5 - a22 * s2 + a23 * s1) * inv_det,
		),
		// Column 2
		vec4f(
			( a10 * c4 - a11 * c2 + a13 * c0) * inv_det,
			(-a00 * c4 + a01 * c2 - a03 * c0) * inv_det,
			( a30 * s4 - a31 * s2 + a33 * s0) * inv_det,
			(-a20 * s4 + a21 * s2 - a23 * s0) * inv_det,
		),
		// Column 3
		vec4f(
			(-a10 * c3 + a11 * c1 - a12 * c0) * inv_det,
			( a00 * c3 - a01 * c1 + a02 * c0) * inv_det,
			(-a30 * s3 + a31 * s1 - a32 * s0) * inv_det,
			( a20 * s3 - a21 * s1 + a22 * s0) * inv_det,
		),
	);
}

@compute @workgroup_size(64, 1, 1)
fn cs_main(@builtin(global_invocation_id) gid: vec3u) {
	let mat_i = gid.x;
	let gradmat = gradmats[mat_i];
	inv_gradmats[mat_i] = mat4_inverse(gradmat);
}
