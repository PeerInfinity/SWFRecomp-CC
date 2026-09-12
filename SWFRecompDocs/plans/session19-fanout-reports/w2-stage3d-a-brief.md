# w2-stage3d-a: Stage3D phase A — AGAL + back buffer + present + composite (CPU raster route)

Read `BRIEFS_COMMON.md` (wave-2 section included), then `w1-gfx-stage3d-report.md` IN FULL. That
report is your diagnosis of record and it is unusually specific about the target model. Worktree
agent: nothing commits, you deliver a patch. Branch from CURRENT master and record the commit.

This is the largest slice in the session. Land phase A only. If you cannot finish it, deliver what
works plus a HOLD naming exactly what is left — a partial, well-tested phase A is a good outcome.

## The measured model (do not re-derive; verify, then build to it)
A ~40-line CPU rasteriser already reproduces the `stage3d_triangle` golden at **max diff 1 and zero
channels over tolerance**, which is a pass. The model, confirmed pixel-by-pixel by the diagnosis:
- opaque nearest composite at `(x,y)` under the display list;
- standard Vulkan 4x sample positions;
- attributes extrapolated at the pixel centre even outside the primitive;
- per-sample round-to-unorm8, then `floor(mean)`;
- composite filtering is nearest (confirmed via `stage_scale_factor`'s 2x blocks).

Take the **CPU raster route** (~750 LOC), not the GPU/WGSL route (~1600-1900). It is half the LOC,
it is the one that has been measured, and its known ceiling (`raytrace`, `away3d`) is out of scope
here anyway.

## Target comparisons (the report's phase A list, 13)
`stage3d_triangle`, `_bytes4`, `_float1`, `_float1_index`, `_index_upload`,
`program_constants_bytearray_be`, `_le`, `rotating_cube`, `multistage_triangle`,
`agal_cross_product`, `stage_scale_factor`, `stage3d/scissor_rectangle`, `_invalid`.

**Five of these are in the `stage3d` suite, which is the CI `misc` group** — they are invisible to
`categories=all`, so grade them locally and say so explicitly in your ledger.

## Explicitly out of scope
- `stage3d_bitmap` (needs textures AND `with_default_font`; our actual is uniformly black from a
  second missing mechanism), `stage3d_blend` (needs G2 plus textures), `away3d*`, `raytrace`.
- Phases A′ (stencil/colorMask), B (textures/RTT), B′ (ATF/DXT), C.
- **Licence**: vendoring `naga-agal` is OUT (memory `ruffle-code-reuse-ruled-out`). Transliterating
  the algorithm from `builder.rs` is IN, the same way `agal_validate` and PixelBender P1/P2 were
  done. Follow that precedent exactly and say in your report which functions you transliterated.

## Required checks
- Every target comparison with `--mode=graphics --images`, before and after, with the CI PNGs in
  `<scratchpad>/image-results/` as the absolute verdict where one exists.
- The trace side of the `stage3d` suite currently passes 7/7 — it must still pass.
- The render canary, and the `regression` suite.
- New files must be added to `verify_output.py`'s explicit source list, CMakeLists AND the
  Emscripten build (or live inside an existing TU). List every new file at the TOP of your report.

Siblings: several agents have landed changes in `avm2_display.c` already; **w2-avm2-rest** may touch
`avm2_stage3d.c` (it owns an unrelated `recompose` constant there) — check master before you start
and flag any overlap in your final message.
