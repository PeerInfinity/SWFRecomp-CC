# w1-gfx-stage3d: wave-1 scoping of the Stage3D blank_render cluster (the largest single pixel pool)

Read `BRIEFS_COMMON.md` and `SWFRecompDocs/plans/graphics-fanout-playbook.md` (§1-7) first. This is
read-only work with no source edits (a throwaway prototype worktree under your scratch dir is fine).
Deliverable: `SWFRecompDocs/plans/session19-fanout-reports/w1-gfx-stage3d-report.md`. Scratch dir:
`<scratchpad>/w1-gfx-stage3d/`.

## Premise to attack
The fresh board's biggest group is `blank_render × Stage3D / AGAL / shaders [BACKEND]`: 22
comparisons, all catastrophic/large. Examples: `avm2/stage3d_bitmap` (85 740), `stage3d_triangle*`
(144 k-191 k), `stage3d_multistage_triangle`, `stage3d_program_constants_bytearray_{be,le}` (323 k),
`stage3d_rotating_cube`, `stage3d_blend` (1.0 M). There are more under the `stage3d` suite that
show png_unavailable (`sampler_odd_size`, `scissor_rectangle`, …; render them locally). The trace
side of the `stage3d` suite passes 7/7, so some Context3D API surface exists. The premise is that
nothing reaches the screen. Maybe one missing present/composite step flips many; maybe a whole
AGAL→WGSL backend is missing. Find out which.

## Questions
1. What exists: grep the runtime for `Context3D`, `AGAL`, `Program3D`, `VertexBuffer3D`, `present`.
   Where does a `drawTriangles` call end up today?
2. How Ruffle does it: `~/CC/ruffle/render/wgpu` (context3d), `render/naga-agal`. What is the
   minimum architecture that renders a triangle?
3. Enumerate every Stage3D comparison (the image JSON plus the `stage3d` suite), and group them by
   the features they need: basic triangle, textures/samplers, blend, constants, multistage,
   scissor, odd sizes, and so on.
4. Price a first slice (for example "AGAL vertex+fragment → WGSL for the opcodes the triangle
   tests use, plus present into the stage composite") with the comparisons it would flip, its
   LOC, and which files it creates. Price follow-on slices too.
5. Say whether a vendored/ported AGAL translator is realistic (licence: Ruffle is MIT/Apache; see
   memory `ruffle-code-reuse-ruled-out` for the standing ruling, and respect it).

Also glance at the two `blank_render × Video / NetStream [BACKEND]` rows and say whether they are
dispositioned or cheap.

Siblings: w1-gfx-geometry, w1-gfx-text-filters, w1-drift, trace agents. You own everything
Stage3D/AGAL/video on the pixel axis.
