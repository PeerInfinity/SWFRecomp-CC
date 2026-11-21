# w2-context3d-readback: `Context3D.drawToBitmapData` readback, the #3692 clear state, and #3611 / skip for unset streams

Session 23 wave 2 (implementation), slot S4 of `w1-drift-avm2`. Branch `fanout/w2-context3d-readback`, based on
`origin/master` `adf4da13` (which includes the RTT landing `cfbcb6658`). Upstream tests downloaded at Ruffle
`aa9f62a70` (2026-11-21). All three headline rows are byte-unchanged since `0ddd12b6a`, so they carry no drift.

**New files (deliverables only, no new source files):**
- `SWFRecompDocs/plans/session23-fanout-reports/w2-context3d-readback-report.md`
- `SWFRecompDocs/plans/session23-fanout-reports/w2-context3d-readback.patch`

**Patch scope** (`w2-context3d-readback.patch` = `git diff origin/master -- SWFRecomp SWFModernRuntime
ruffle-tests/verify_output.py ruffle-tests/render_canary_tests.txt`, md5 `6820da6a…`, `git apply --check -R` OK):

| file | change |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | +159 / −2. Only file touched |

There are no recompiler changes, no `swf_core.c` / `tag_stubs.c` / `NO_GRAPHICS` arms, no new `.c`/`.h` files, no
`render_canary_tests.txt` change, and no fixtures. All new state goes in trailing struct fields (`S3dBackend.seen_clear`,
`Avm2Program3DExt.va_read_mask`) and `static` functions.

---

## Verdicts (lead)

| # | Item | Verdict | Before → after (clean master vs patch, same box, graphics) |
|---|---|---|---|
| 1 | `drawToBitmapData` back-buffer readback | **GO, landed** | `avm2/context3d_draw_to_bitmap_data` trace 2/15 → **15/15 PASS**; image fail 7500 → **PASS 0 outliers, max diff 0** |
| 2 | #3692 state machine (clear sets it; configureBackBuffer / present reset it; silent no-op before configure) | **GO, landed** | `stage3d/draw_to_bitmap_data_unconfigured` 3/8 → **8/8 PASS** |
| 3 | `stage3d_missing_vertex_stream` (known_failure) | **GO, landed, Flash-exact (not just ruffle_matched)** | 13/37 → **37/37 PASS** |
| 4 | Sweep: 55 tests (42 Stage3D/Context3D rows + away3d + 3 Context3D users + 10 BitmapData canary members) | **clean** | only the 3 ledger rows move; 39/40 PNGs md5-identical (the 40th is the ledger row) |
| 5 | Fidelity | **proven** | the before PNG md5 of `context3d_draw_to_bitmap_data` `2c576ac3…` equals CI's actual on `origin/ruffle-image-results` `10e5e39c` (run `44922638965`). The before trace line counts of all 3 rows equal `origin/ruffle-test-results`. |

Priced flips: **+3 trace** (both modes), **+1 pixel**.

## EXPECTED-FLIP LEDGER (for CI)

**Trace axis (identical in graphics AND no-graphics, both measured locally):**

| test | CI before | expected after |
|---|---|---|
| `avm2/context3d_draw_to_bitmap_data` | output_mismatch 2/15 | **pass 15/15** |
| `avm2/stage3d_missing_vertex_stream` (`known_failure = true`) | output_mismatch 13/37 | **pass 37/37**. This matches Flash's `output.txt`, not `output.ruffle.txt`, so it is a pass, not a ruffle_matched |
| `stage3d/draw_to_bitmap_data_unconfigured` | output_mismatch 3/8 | **pass 8/8** |

**Pixel axis (images run):**

| test | CI before | expected after |
|---|---|---|
| `avm2/context3d_draw_to_bitmap_data` | fail 7500 outliers (limit 0), max diff 128 | **PASS 0 outliers, max diff 0** (fidelity-proven row, so this is CI-grade) |

Every other image row must stay md5-identical.

---

## 1. Mechanism (`avm2_stage3d.c`)

Ruffle implemented this in `b36debbc7` and `e0923f3cf` (`core/src/avm2/globals/flash/display3D/context_3d.rs
draw_to_bitmap_data`; `render/wgpu/src/context3d/mod.rs` `back_buffer_handle`, `back_buffer_size`,
`buffers_cleared` = `seen_clear_command`).

- **`context3d_draw_to_bitmap_data`** replaces `s3d_noop` at the registration (`avm2_register_stage3d`). It follows
  Ruffle's order:
  1. A null destination throws `TypeError #2007 "Parameter destination must be non-null."`.
  2. Before `configureBackBuffer` the call is a silent no-op (`e0923f3cf`). This holds whether or not `clear()` was
     called.
  3. If nothing has cleared the buffers since the last configure or present, it throws plain `Error #3692 "All buffers
     need to be cleared every frame before drawing."`.
  4. Otherwise it reads the **back** buffer. That is the same buffer `s3d_present` resolves, not `front`. While
     render-to-texture is open, it reads the parked `bb_*` buffer, because Ruffle reads `back_buffer_raw_texture_handle`
     regardless of the RTT target. The resolve is the same per-sample quantise + floor-mean that `s3d_present` and
     `s3d_rtt_end` use, with alpha kept. The read is drawn 1:1 at the destination's top-left: clipped, never scaled,
     and pixels outside the back buffer keep their fill.
  5. An opaque source texel (a = 255) is stored as-is. Otherwise it goes through premultiplied src-over onto the
     premultiplied store; that is Ruffle's `render_bitmap` blend. A non-transparent destination forces alpha 255.
  6. It writes `Avm2BitmapDataExt.pixels` directly. The BitmapData has no dirty/version bookkeeping on our side:
     `avm2_render_bitmap` and all CPU readers read `pixels` every frame. The pixel test (`addChild(new Bitmap(big))`)
     proves a later render sees the data.
- **Pending clear.** Our `clear()` is deferred to the next draw, as in Ruffle. The readback applies a still-pending
  clear first, but only when it is not in RTT, where the pending clear targets the RTT surface. Flash's clear is
  effectively immediate. `stage3d_missing_vertex_stream` reads the clear colour after a draw that was skipped or
  threw. Without this, it would read the previous frame's red: our back buffer is single, not swapped.
- **#3692 state**: `S3dBackend.seen_clear` is set in `context3d_clear`. It is reset in `configureBackBuffer` (after
  the range checks, at the real reallocation; this is `e0923f3cf`) and in `present` (`mod.rs:1268`). As in Ruffle,
  `drawTriangles` does **not** throw #3692. No corpus `output.txt` expects that, and Ruffle only warns.
- **Unset vertex streams** (`stage3d_missing_vertex_stream`, which the brief did not price beyond "the same
  readback"):
  - At `Program3D.upload` we record `va_read_mask` (`s3d_va_read_mask`): the `va<i>` registers the vertex program
    reads. That covers every source operand of every token, plus an indirect operand's index register, which mirrors
    naga_agal `get_vertex_input`.
  - src2 is only counted for two-source opcodes. A unary op's zeroed second word would otherwise decode as `va0`,
    which would spuriously skip draws that never read `va0`. `tex`'s sampler operand is excluded too.
  - `drawTriangles` checks the mask after the pending clear lands. Ruffle's `MissingVertexAttributeData` arm opens
    the pass, so the clear lands, and then skips `draw_indexed`.
  - On a read of an unbound stream, the draw is skipped. With `enableErrorChecking` it throws plain
    `Error #3611 "Stream N is read by the current vertex program but not set."`. That is Flash's line in
    `output.txt`; Ruffle has it as a TODO.
  - The before output was 13/37 for two reasons: the read returned the untouched `0` fill, and the draw with unset
    streams ran using zero attributes.

## 2. Per-test before/after (clean `origin/master` `adf4da13` vs patch, same box)

**Headline rows, both modes:**

| test | graphics trace | graphics image | no-graphics trace |
|---|---|---|---|
| `avm2/context3d_draw_to_bitmap_data` | 2/15 → **15/15** | fail 7500 → **pass 0** | 2/15 → **15/15** |
| `stage3d/draw_to_bitmap_data_unconfigured` | 3/8 → **8/8** | (none) | 3/8 → **8/8** |
| `avm2/stage3d_missing_vertex_stream` | 13/37 → **37/37** | (none) | 13/37 → **37/37** |

**Graphics sweep, 55 tests** (`render_canary.py capture` over an explicit list: every `avm2/stage3d*`,
`avm2/context3d*` and `stage3d/*` row, plus `away3d_advanced_shallow_water_demo`, `agal_compiler`,
`stage_scale_factor`, `abstract_classes` (the other corpus Context3D users), plus the BitmapData canary members).
Compare result: **IDENTICAL 39, DIFFERS 1** (`context3d_draw_to_bitmap_data`, fail→pass). Trace status changes are
exactly the 3 ledger rows. Full table:

| test | trace before | trace after | image before | image after | png md5 |
|---|---|---|---|---|---|
| `avm1/bitmap_data_fillrect` | pass | pass | pass 0 | pass 0 | same |
| `avm1/bitmapdata_applyfilter_colormatrix` | pass | pass | pass 0 | pass 0 | same |
| `avm2/abstract_classes` | pass | pass | — | — | no png |
| `avm2/agal_compiler` | pass | pass | — | — | no png |
| `avm2/away3d_advanced_shallow_water_demo` | pass | pass | fail 1326765 | fail 1326765 | same |
| `avm2/bitmapdata_copypixels` | pass | pass | pass 0 | pass 0 | same |
| `avm2/bitmapdata_draw_masks` | pass | pass | pass 0 | pass 0 | same |
| `avm2/bitmapdata_draw_self_via_graphic` | pass | pass | pass 0 | pass 0 | same |
| `avm2/bitmapdata_opaque` | pass | pass | fail 4 | fail 4 | same |
| `avm2/context3d_clear_mask` | pass | pass | — | — | no png |
| `avm2/context3d_creation` | pass | pass | — | — | no png |
| `avm2/context3d_draw_to_bitmap_data` | output_mismatch | **pass** | fail 7500 | **pass 0** | DIFFERS (ledger) |
| `avm2/graphics_bitmaps` | pass | pass | pass 526 | pass 526 | same |
| `avm2/stage3d_agal_cross_product` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_agal_upload_errors` | pass | pass | — | — | no png |
| `avm2/stage3d_bitmap` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_blend` | pass | pass | pass 5064 | pass 5064 | same |
| `avm2/stage3d_context3d_string_args` | pass | pass | — | — | no png |
| `avm2/stage3d_errors` | pass | pass | — | — | no png |
| `avm2/stage3d_errors_atf` | pass | pass | — | — | no png |
| `avm2/stage3d_errors_swf_29` | pass | pass | — | — | no png |
| `avm2/stage3d_float1_index` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_fractal` | pass | pass | fail 1104108 | fail 1104108 | same |
| `avm2/stage3d_ignore_sampler_override` | pass | pass | pass 6 | pass 6 | same |
| `avm2/stage3d_missing_vertex_stream` | output_mismatch | **pass** | — | — | no png |
| `avm2/stage3d_multistage_triangle` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_program_constants_bytearray_be` | pass | pass | pass 3523 | pass 3523 | same |
| `avm2/stage3d_program_constants_bytearray_le` | pass | pass | pass 3523 | pass 3523 | same |
| `avm2/stage3d_program_constants_invalid_input` | pass | pass | — | — | no png |
| `avm2/stage3d_raytrace` | pass | pass | fail 660000 | fail 660000 | same |
| `avm2/stage3d_rotating_cube` | pass | pass | pass 244 | pass 244 | same |
| `avm2/stage3d_sampler` | pass | pass | pass 50 | pass 50 | same |
| `avm2/stage3d_sampler_partial_upload` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_stencil` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_texture` | pass | pass | pass 2 | pass 2 | same |
| `avm2/stage3d_texture_bytearray` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_texture_bytearray_compressed_alpha` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_texture_bytearray_compressed_raw_alpha` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_triangle` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_triangle_bytes4` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_triangle_float1` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_triangle_index_upload` | pass | pass | pass 0 | pass 0 | same |
| `avm2/stage3d_x_y` | pass | pass | — | — | no png |
| `avm2/stage_scale_factor` | pass | pass | pass 0 | pass 0 | same |
| `from_shumway/acid/acid-bitmapData-copyPixels` | pass | pass | pass 0 | pass 0 | same |
| `from_shumway/acid/acid-bitmapData-draw` | pass | pass | pass 0 | pass 0 | same |
| `stage3d/draw_to_bitmap_data_unconfigured` | output_mismatch | **pass** | — | — | no png |
| `stage3d/request_matching_profiles` | pass | pass | — | — | no png |
| `stage3d/request_profiles` | pass | pass | — | — | no png |
| `stage3d/sampler_odd_size` | pass | pass | pass 0 | pass 0 | same |
| `stage3d/scissor_rectangle` | pass | pass | pass 0 | pass 0 | same |
| `stage3d/scissor_rectangle_invalid` | pass | pass | pass 0 | pass 0 | same |
| `stage3d/unbound_texture` | pass | pass | pass 0 | pass 0 | same |
| `stage3d/unbound_texture_multiple` | pass | pass | pass 0 | pass 0 | same |
| `visual/bitmapdata_copypixels_with_alpha_oob` | pass | pass | pass 0 | pass 0 | same |

Two notes on this table:
- `stage3d_texture_bytearray_compressed_alpha` passes 0/0 locally on both legs, but failed 8192 on the CI images run.
  It is unchanged by this patch either way. It is upstream drift (`5021d0ed7`) plus test-file state, owned by the
  drift slots.
- `stage3d_blend` (5064) and `graphics_bitmaps` (526) report as pass because the per-test limits are above those
  counts.

**No-graphics trace sweep** (every `avm2/stage3d*`, `avm2/context3d*` and `stage3d/*` row, 41 tests): the only status
or output change is the 3 ledger rows. All other `actual_output` is byte-identical.

**Regression suite** (`--tests-dir=ruffle-tests/tests/swfs/regression`, graphics): `avm2_bitmapdata_draw_textfield`,
`bitmap_pool_layer_cap` (image 0/0), `avm2_parent_child_render` (image 0), `avm2_gc_string_survives_collect` and
`avm2_graphics_runtime` all **PASS** with the patch. The suite has no Stage3D fixture.

**Render canary**: the run was over the Stage3D + BitmapData canary members as above. The standing members
(`stage3d_triangle`, `stage3d_rotating_cube`, `stage3d_stencil`, `stage3d_sampler`, `stage3d_texture*`, `bitmapdata_*`,
`acid-bitmapData-*`) are all md5-identical. I added no new canary member. The change class (a readback into
BitmapData) only shows up in a test that calls `drawToBitmapData`. The corpus has exactly three, all in this ledger;
the four `stage3d_triangle*` mentions are commented-out code. `context3d_draw_to_bitmap_data` is the only one with an
image, and it fails on CI today. A coordinator could append it at EOF (tier 1) once CI confirms the pass.

## 3. Refutations and premise checks

- **Brief: "respect the BitmapData dirty/version bookkeeping".** There is none on our side. `Avm2BitmapDataExt` is
  `{w, h, transparency, disposed, pixels}`. The renderer (`avm2_render_bitmap` → `renderer_draw_bitmap_quad_scaled`)
  and the CPU composite upload `pixels` every frame. Writing `pixels` is sufficient, and the image pass proves it.
- **Brief: "missing_vertex_stream: ruffle_matched target if Flash-exact is out of reach".** Flash-exact was in reach.
  Flash's lines are #3611 under `enableErrorChecking` and a skipped draw otherwise. The row now matches `output.txt`.
  Because it is `known_failure`, a ruffle_matched outcome would have been the weaker one.
- **"draw throws #3692 too".** Refuted for the corpus. No `output.txt` expects #3692 from `drawTriangles`, and Ruffle's
  `drawTriangles` only warns (`mod.rs:900`). I did not add it. Adding it could break draws that skip `clear()` in
  passing rows.

## 4. Not done / limits (with completion mechanism)

- **The alpha < 255 src-over arm and the readback-during-RTT arm have no corpus coverage.** Every corpus reader clears
  with alpha 1, and none reads while RTT is open. Both follow Ruffle's `render_bitmap` semantics as written, but no
  oracle has checked them. Completion: the local oracle request below, then a `regression/` fixture.
- **`m33`/`m44`/`m34` with an attribute as the matrix (src2) operand** marks only `va<n>`, not `va<n+1..n+3>`. Corpus
  programs use constants there. If that pattern ever matters, extend `s3d_va_read_mask`.
- **A destination that is a non-BitmapData object, or a disposed BitmapData**, is a silent no-op. Flash would give
  #1034 or #2015. No corpus row exercises it.

## New unclaimed leads

- None found in the sweep. All Stage3D image failures (`stage3d_raytrace` 660000, `stage3d_fractal`, away3d) are
  unchanged and belong to the existing boards.

## LOCAL ORACLE REQUESTS

1. (Optional, for a `regression/` fixture.) The Ruffle exporter or Flash trace + render for a small AS3 SWF that:
   - clears a 64×64 back buffer to `(1,0,0,0.5)`;
   - calls `drawToBitmapData` into a transparent BitmapData filled `0xff0000ff`, then into an opaque one filled the
     same;
   - traces `getPixel32(5,5)` for both;
   - repeats the read after `setRenderToTexture(tex)` + `clear(0,1,0,1)` + a draw, to prove the back buffer (not the
     RTT) is read.

   That would pin the alpha-blend arm and the RTT arm of `context3d_draw_to_bitmap_data`. It does not block anything:
   all graded rows pass without it.
