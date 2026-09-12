# w2-stage3d-a — Stage3D phase A (AGAL + back buffer + present + composite), CPU raster route

Worktree `/home/robert/CC/SWFRecomp-CC/.claude/worktrees/agent-a11f1664fd5f6406e`,
branched from master **`3cce6a1f7`**. Patch: `w2-stage3d-a.patch`, delivered beside this
report. No commits, no pushes.

## 0. New files

**None.** The whole backend lives inside the existing TU
`SWFModernRuntime/src/avm2/avm2_stage3d.c`, so there is nothing to add to
`verify_output.py`'s explicit source list, `CMakeLists.txt` or the Emscripten build, and
nothing for the coordinator to stage by name beyond the five modified files:

| file | what |
|---|---|
| `SWFModernRuntime/src/avm2/avm2_stage3d.c` | +~1200: retained state, AGAL interpreter, software MSAA rasteriser, present/resolve, the composite + GC-free exports |
| `SWFModernRuntime/src/avm2/avm2_display.c` | +24: `avm2_render_stage3ds()` and its one call at the top of `avm2_render_walk` |
| `SWFModernRuntime/src/avm2/avm2_gc.c` | +1: the new ext-free hook in the sweep list |
| `SWFModernRuntime/include/avm2/avm2_gc.h` | +3: its prototype |
| `ruffle-tests/render_canary_tests.txt` | +20: two tier-2 Stage3D canary members (the set had none, and could not have had one before this) |

**Applying this patch.** It is against `3cce6a1f7`; master has since moved to `53b7df481`.
Two of my five files were touched in between:

* `ruffle-tests/render_canary_tests.txt` — `w2-gfx-text` and `w2-setprops` also **append**
  blocks at end of file, so my append **will conflict**. It is a pure append of a comment
  block plus two `suite/test` lines; resolve by keeping all three blocks.
* `SWFModernRuntime/src/avm2/avm2_display.c` — master's newest hunk ends around
  `avm2_render_textbox` (~line 18619); mine is the single call at the top of
  `avm2_render_walk` (~line 19682) plus the `avm2_render_stage3ds` helper just above it. No
  textual overlap; it should apply with an offset.

The other three files (`avm2_stage3d.c`, `avm2_gc.c`, `avm2_gc.h`) are untouched on master
since `3cce6a1f7`.

## 1. Verdict and ledger

**GO — phase A is complete and graded.** The w1 report's measured model held end to end: a
CPU AGAL interpreter plus a software 4x-MSAA rasteriser reproduces the upstream goldens
inside their own tolerances, with no new GPU pipeline and no new file.

**All thirteen of the brief's target comparisons flip to PASS.**
All numbers are local `--mode=graphics --images` runs in this worktree; "before" is the
baseline excess from `wave0-image-board.md` / the CI failing PNGs at
`<scratchpad>/image-results/`, re-measured locally for the two `stage3d`-suite rows whose CI
PNGs do not exist.

| # | comparison | suite / CI group | budget (tol / max_outliers) | before | after | verdict |
|---|---|---|---|---|---|---|
| 1 | `avm2/stage3d_triangle` | avm2 — **`all`** | 1 / 0 | 191 267 excess | **0 outliers, max diff 1** | **PASS** |
| 2 | `avm2/stage3d_triangle_bytes4` | avm2 — **`all`** | 1 / 0 | 191 267 | **0, max 1** | **PASS** |
| 3 | `avm2/stage3d_triangle_float1` | avm2 — **`all`** | 1 / 0 | 144 420 | **0, max 1** | **PASS** |
| 4 | `avm2/stage3d_triangle_index_upload` | avm2 — **`all`** | 1 / 0 | 191 267 | **0, max 1** | **PASS** |
| 5 | `avm2/stage3d_float1_index` | avm2 — **`all`** | 1 / 0 | blank | **0, max 1** | **PASS** |
| 6 | `avm2/stage3d_program_constants_bytearray_be` | avm2 — **`all`** | 50 / 5000 | 323 452 | **3520, max 255** | **PASS** |
| 7 | `avm2/stage3d_program_constants_bytearray_le` | avm2 — **`all`** | 50 / 5000 | 323 452 | **3520, max 255** | **PASS** |
| 8 | `avm2/stage3d_rotating_cube` | avm2 — **`all`** | 3 / 2160 | 331 894 | **2144, max 64** | **PASS (tight, 16 to spare)** |
| 9 | `avm2/stage3d_multistage_triangle` | avm2 — **`all`** | 1 / 0 | 191 416 | **0, max 1** | **PASS** |
| 10 | `avm2/stage3d_agal_cross_product` | avm2 — **`all`** | 2 / 10 | blank | **0, max 1** | **PASS** |
| 11 | `stage3d/scissor_rectangle` | stage3d — **`misc`, CI-INVISIBLE at `categories=all`** | 1 / 0 | blank (all-white) | **0, max 1** | **PASS** |
| 12 | `stage3d/scissor_rectangle_invalid` | stage3d — **`misc`, CI-INVISIBLE** | 1 / 0 | blank (all-white) | **0, max 1** | **PASS** |
| 13 | `avm2/stage_scale_factor` | avm2 — **`all`** | 1 / 0 | 1 912 924 outlier channels of 2 640 000 | **0, max 1** | **PASS** (I nearly mis-called this one — §4.1) |

**CI visibility.** The brief warned that five of the pool's 29 comparisons are `stage3d`-suite
= CI `misc` group. Of my thirteen, **two** are (`scissor_rectangle`, `scissor_rectangle_invalid`)
— they will NOT move on a `categories=all` images run and must be graded on
`categories=full`. The other ten flips are in `avm2`, i.e. in the classic five suites, and are
visible to a normal `images=true` run. (The other three `misc`-group Stage3D rows —
`sampler_odd_size`, `unbound_texture`, `unbound_texture_multiple` — are phase-B texture rows
and stay failing; see §4.3.)

**Trace axis: no regression — but it took work.** The `stage3d` suite is 7/7 PASS on trace
after the patch (runs 3 and 11), which was the brief's explicit requirement, and every
`avm2/stage3d_*` row still passes including the out-of-scope ones. That was **not** free: an
early version of the cost guard turned `avm2/away3d_advanced_shallow_water_demo` from a
10.5 s pass into a 30 s **timeout**. See §4.3 — it is the most important thing in this report.

**Sibling overlap.** `w2-avm2-rest` was flagged as possibly touching `avm2_stage3d.c` for an
unrelated `recompose` constant. As of master `3cce6a1f7` it had not landed, so this patch is
against a clean `avm2_stage3d.c`; a `recompose` change lives in the `flash.geom.Matrix3D`
half at the bottom of the file and does not overlap the S3 block textually, but the
coordinator should apply the smaller of the two second.

## 2. Mechanism

### 2.1 What was missing and what replaced it

The w1 report's central claim held on inspection: `avm2_stage3d.c` retained **nothing**
renderable. `drawTriangles` was a four-line null check, `present` was literally `s3d_noop`,
`uploadFromVector`/`uploadFromByteArray` were `s3d_noop` on both buffer classes, the AGAL
bytecode was discarded the moment `agal_validate` accepted it, and `clear`/`setScissorRectangle`/
`setProgramConstantsFrom*` ignored their arguments. So phase A is not a missing final step;
it is a backend.

What the patch retains:

* `Avm2Program3DExt` — the validated vertex and fragment AGAL bytecode (`vcode`/`fcode`).
* `Avm2Buffer3DExt` — `words`, a raw 32-bit word array. A vertex buffer holds
  `numVertices * data32PerVertex` words and the *attribute format* decides how each word is
  read at fetch time (so `float1..4` and `bytes4` share one storage); an index buffer holds
  one word per index.
* `Avm2Context3DExt` — the GC-visible object edges only (`program`, `va_buf[8]`), plus a
  pointer to `S3dBackend`.
* `S3dBackend` (one heap block per context) — the per-sample colour and depth buffers, the
  resolved front buffer, `vc[128]`/`fc[28]`, the eight attribute bindings, cull/depth/scissor
  state, and the deferred clear.

The split between the ext and `S3dBackend` is deliberate and is a GC constraint, not a style
choice: `avm2_gc.c::conservative_scan` walks the **ext blob** word by word looking for object
pointers, and it cannot follow into a side allocation. So every `Avm2Object*` stays in the ext
(where the collector sees it) and only non-object bulk data moves out.

### 2.2 The AGAL interpreter (transliterated, not vendored)

Per the brief and the standing `ruffle-code-reuse-ruled-out` ruling, `naga-agal` is used as
the **spec**, exactly as tranche S2 did for `parse_bytecode`. Transliterated functions, all
cited by line range in the source comments:

| Ruffle | ours |
|---|---|
| `types.rs:100-124` `SourceField::parse`, `DestField::parse` | the bit unpacking in `s3d_src_load` / `s3d_dest_store` |
| `builder.rs:909-1063` `emit_source_field_load_with_swizzle_out` | `s3d_src_load`, including the indirect `vc[regN.X + offset]` arm and its Float1-index special case |
| `builder.rs:156-236` `VertexAttributeFormat::extend_to_float4` | `s3d_extend4` (pad with `0,0,1`) |
| `builder.rs:1063-1130` `emit_dest_store` | `s3d_dest_store`, including the **scalar-write** rule (a write mask with exactly one bit takes component 0 of the source, not component `i`) |
| `builder.rs:1164-1720` `process_opcode` | the `switch` in `s3d_run_agal` |
| `current_pipeline.rs:455-470` | `s3d_fetch_attr`'s `Unorm8x4` reading of `bytes4` |

Two Ruffle behaviours that are easy to get wrong and that the corpus actually grades:

* `dp3`/`dp4` produce a **scalar**, and `emit_dest_store`'s `source_is_scalar` arm writes it
  into every masked component. We splat the dot into all four components before storing,
  which makes the scalar arm and the ordinary arm the same code.
* `m33`/`m34`/`m44` read `num_rows` **consecutive** source-2 registers (or, in indirect mode,
  increment the indirect offset), compose them as columns, then transpose — i.e. row `i` of
  the matrix is register `reg+i`, and `out[i] = dot(row_i, v)`. `m33`/`m34` then
  `extend_to_float4` their three-component result with `w = 1`.

Opcodes implemented: `mov add sub mul div rcp min max frc sqt rsq pow log exp nrm sin cos crs
dp3 dp4 abs neg sat m33 m44 m34 sge slt seq sne kil` plus `ife/ine/ifg/ifl/els/eif`.
`ddx`/`ddy` read as zero (a CPU raster shades one pixel at a time, there is no 2x2 quad) and
`tex` writes zero (phase B).

### 2.3 The rasteriser — the w1 model, re-verified before building to it

The w1 report's §4 model was **independently re-derived** before any code was written, because
the prototype left in the scratchpad (`w1-gfx-stage3d/raster.py`) does *not* reproduce the
number in the report: as saved it masks fragment colour to centre-inside
(`m & any_in`) and scores **max 127 / 826 outliers**. Rebuilt with per-sample colour buffers and
attributes evaluated at the pixel centre regardless of coverage
(`<scratchpad>/w2-stage3d-a/raster_percov.py`), it scores exactly the report's figure:

```
round trunc  max 1  outliers>1 0  nonzero 517 of 192000
```

That is the model the C rasteriser implements:

1. screen position `((x/w)*0.5+0.5)*W`, `(0.5-(y/w)*0.5)*H`, depth `z/w`;
2. coverage per sample at the standard Vulkan 4x positions
   `(0.375,0.125) (0.875,0.375) (0.125,0.625) (0.625,0.875)`, strict `> 0` on all three
   edge functions, no top-left rule (a single sample at the pixel centre when `antiAlias < 2`);
3. **varyings interpolated at the pixel centre and extrapolated** when the centre is outside
   the primitive — this is the one non-obvious part, and skipping it leaves a wrong edge with
   diffs up to 127;
4. perspective-correct varyings (`Σ b_i/w_i · a_i / Σ b_i/w_i`), screen-linear depth;
5. per sample store `round(clamp(c,0,1)·255)`, resolve `floor(mean)`.

Culling: `FrontFace::Cw` (`current_pipeline.rs:576`) — with y pointing down, a clockwise
winding gives a **negative** signed area under this edge function, so front = `area < 0`.
Depth default is `depth_mask = true, LessEqual` (`current_pipeline.rs:169`), and there is no
depth test at all when `configureBackBuffer` was called with `enableDepthAndStencil = false`
(which `stage3d_rotating_cube` does — that cube is correct *because of back-face culling*,
not because of a depth buffer).

Clear is **deferred**, as in Ruffle: `Context3DCommand::Clear` only records a pending clear,
`make_render_pass` (`mod.rs:206-227`) consumes it at the next draw, and `present`
(`mod.rs:1240-1241`) drops an unconsumed one. A `clear()` with no following `drawTriangles`
therefore never reaches the buffer, in Ruffle and here.

### 2.4 Present and composite

`present()` resolves the multisample buffer into an ARGB front buffer. The composite is one
call at the top of `avm2_render_walk`, before `avm2_render_node(ctx->stage, ...)`, walking
`stage3Ds` in index order (`stage.rs:625-634`): Stage3D renders **underneath** the whole
display list, at `(Stage3D.x, Stage3D.y)`, and `surface/commands.rs:866` scales the unit quad
by the **texture size**, so the back buffer occupies exactly `w x h` stage pixels — unscaled,
whatever the viewport scale factor. It reuses the existing
`render_webgpu_draw_bitmap_quad_scaled` with identity transform/cxform slots, so **no new GPU
pipeline is added** and the blast radius on the other ~550 image comparisons is a single extra
`if` that no-ops when no Stage3D has a configured back buffer.

Alpha: Ruffle draws this quad through `bitmap_opaque`, which is `BlendState::REPLACE` with
`write_mask: ColorWrites::COLOR`. Reading `bitmap.wgsl` end to end, the RGB always passes
through unchanged (the `a > 0` branch un-premultiplies and re-multiplies by the same alpha with
`late_saturate` suppressing the intermediate clamp; the `a == 0` branch returns the texel as
is). So the 3D content's alpha never reaches the stage. We reproduce that by writing the front
buffer with `a = 255` and the resolved RGB — which is also exactly what the premultiplied
bitmap-quad path we reuse needs. This matters for real content:
`stage3d_agal_cross_product`'s fragment alpha is **0** (`sub v0, va0, va0` then
`crs v0.xyz, ...` never rewrites `w`), and it still grades green.

## 3. Tests run

Every run below is in this worktree with `SWFRECOMP_COMPILE_TIMEOUT=2400` and
`DAWN_INSTALL=~/CC/dawn-install`, `--mode=graphics`, sequential.

| run | scope | result |
|---|---|---|
| 1 | `avm2/stage3d_triangle` **before** the patch | image FAIL, 191 267 outliers, max diff 255 (the baseline blank) |
| 2 | the ten `avm2` target rows | **10/10 trace PASS, 10/10 image PASS** (§1) |
| 3 | the whole `stage3d` suite (7 tests) | **7/7 trace PASS** — the brief's explicit requirement. Images: the two scissor rows failed here and were fixed by §4.4; `sampler_odd_size` / `unbound_texture{,_multiple}` are phase-B rows and still fail |
| 4 | `stage3d/scissor_rectangle{,_invalid}` after the §4.4 crop | **both image PASS, 0 outliers, max diff 1** |
| 5 | the eight out-of-scope Stage3D rows (`raytrace`, `away3d`, `blend`, `bitmap`, `fractal`, `stencil`, `sampler`, `texture`) | 7/8 trace PASS; **`away3d` TIMED OUT** — the §4.3 regression, since fixed. Images all still fail (phases A'/B/C) |
| 6 | **`regression` suite**, 11 tests spanning the three shared paths the patch touches (`avm2_gc_dynprop_tombstone_purge`, `avm2_gc_string_concat_reclaim`, `avm2_gc_string_survives_collect` for the new GC free hook; `avm2_parent_child_render`, `avm2_timeline_solid`, `avm2_timeline_gradients`, `avm2_static_text`, `avm2_graphics_runtime`, `avm2_morph` for the AVM2 render walk; `mask_nested_intersect`, `bitmap_pool_layer_cap` for the bitmap-quad path) | **11/11 PASS**, and every image comparison with a golden passed — `mask_nested_intersect` and `bitmap_pool_layer_cap` at **0 outliers / max diff 0**, `avm2_timeline_gradients` at 0 outliers, `avm2_parent_child_render` 96/400 |
| 7-12 | three further retune rounds over the eleven `avm2` rows, the two scissor rows and `away3d`/`raytrace` | all still PASS at every setting; the §4.3 timings |
| baseline | **patch reverted** (diff + reverse-apply + re-apply — never the shared stash), `away3d` + `raytrace` | the local baseline the §4.3 table needs: away3d **19.86 s**, raytrace 1.57 s |
| **F** | **the authoritative run at the delivered source**: all eleven `avm2` target rows + both `stage3d` scissor rows | **13/13 image PASS**, and the §1 numbers are this run |

**Render canary.** See §4.7.

## 4. Refutations and risks (attacking my own brief and my own pricing)

### 4.1 The refutation I nearly filed on `avm2/stage_scale_factor` was itself wrong

I had this row written up as a NO-GO for most of the session, and it is worth recording why,
because the trap is a general one.

The board clusters `stage_scale_factor` as **`content_displaced`**, not `blank_render`, and its
baseline CI actual is wrong over **1 912 924 of 2 640 000 channels, max diff 254, bounding box
(0,0)-(1099,799)** — the *entire* 1100x800 frame, not a 320x200 corner. `Test.as` sets
`stage.scaleMode = "noScale"` and `stage.transform.matrix = new Matrix(1.5, 0, 0, 1, 10, 100)`
before it ever constructs the Stage3D sub-object, so "a Stage-level transform we do not
implement" is an extremely plausible reading of a whole-frame diff, and it is the reading the
cluster label invites.

It is wrong. Reading actual pixels rather than diff magnitudes settles it: the baseline
actual's top-left is `(255,255,255)` while the golden's is `(76,76,76)` = `0.3 * 255`, the
Stage3D **clear colour**. The Stage3D back buffer covers most of this frame, so the
whole-frame diff simply *is* the blank render, and the areas away from it — e.g. `(550,400)`
= `(0,51,0)` in both — already matched. With phase A the row grades **0 outliers, max diff 1**.

Lesson for the board: `content_displaced` vs `blank_render` is a magnitude/shape heuristic, and
a blank render that happens to cover most of the frame lands in the wrong bucket. Priced at
13, phase A delivers **13**.

### 4.2 The w1 prototype as saved does NOT reproduce the w1 number — and the difference is the model

`<scratchpad>/w1-gfx-stage3d/raster.py` scores **max 127 / 826 outliers**, not "max 1 / 0". Its
fragment colour is masked to `m & any_in` where `m` is centre-inside, so every edge pixel whose
centre falls outside the primitive keeps the clear colour. The report's *prose* (§4.3) is
right and its *code* is the earlier draft; anyone building from the file rather than the prose
would have shipped a wrong edge. Re-derived in
`<scratchpad>/w2-stage3d-a/raster_percov.py` (per-sample colour buffers, centre-extrapolated
attributes): `round trunc → max 1, outliers>1 0, nonzero 517 of 192000`, exactly the reported
figure. Recorded so the next slice trusts the prose, not the prototype.

### 4.3 A CPU rasteriser introduces a *new* class of regression the GPU route would not: runtime — and it BIT

This is the biggest risk in the patch, it is not on the pixel axis, and it produced a real
`pass -> fail` before the guard was tuned. Recording the whole sequence, because the next
Stage3D slice will hit it again.

`avm2/stage3d_raytrace` is an 833-token OGSL fragment shader over 550x400 for 80 frames — on
the order of **15 billion** interpreted instructions. It currently **passes on trace** (its
image is the graded axis); a backend that runs for hours turns a green row red. So the patch
carries a whole-run **budget**, after which rasterisation stops and every later draw is a
no-op: the trace side is untouched and the image side is no worse than the blank it replaced.

The first budget counted *instruction executions* only (64 M). `raytrace` was then fine —
run time 4.19 s against a 0.465 s baseline. But
**`away3d_advanced_shallow_water_demo` TIMED OUT**: its shaders are short, so an
instruction-only budget let it shade tens of millions of pixels, and its run went from
**10.468 s** (CI baseline `254145a5b`) to **over 30 s**, which is `verify_output.py`'s hard
execution timeout — an outright `pass -> fail` on the trace axis, invisible on the image axis,
and exactly the regression the guard existed to prevent.

It took three rounds to get right, and the intermediate measurements are the useful part:

| guard | away3d run time |
|---|---|
| **patch reverted — the local baseline, measured** | **19.86 s** |
| 64 M, instruction-only | **TIMEOUT** (> 30 s) |
| 24 M, `instructions + 8` per shaded pixel, per-pixel `memset` removed | 25.41 s |
| + scanned (uncovered) pixels charged 1, vertex loop stops when spent | 24.51 s |
| + the whole backend **latches off** when spent (clear and resolve included), 12 M | 25.39 s |
| + per-triangle vertex charge (final) | 25.4 s |

All of these are on this loaded shared box, which is why the local baseline matters: CI ran
away3d in **10.468 s** at `254145a5b`, so the box is ~1.9x slower here. The patch's cost on
away3d is **+5.5 s local ≈ +2.9 s at CI speed**, i.e. ~13.4 s against a 30 s cap. (`raytrace`:
1.57 s baseline → 2.58 s, +1 s local.) The tuning past the first row bought little on the
clock, but the first row is the one that mattered: **the instruction-only budget really did
time out**, and I would have shipped that regression if I had not run the out-of-scope rows.

The third row is the lesson: budgeting the *shading* was not enough, because the per-frame
**clear and resolve are themselves O(w * h * samples)** and ran every tick regardless — a
960x700 4x buffer is a 43 MB colour clear plus an 11 M-sample resolve, twenty times over. So
the final guard is a **latch**: once the budget is spent, `drawTriangles`, the deferred clear
and `present` all return immediately and the last front buffer simply keeps compositing.
Everything in the patch:

* budget **12 M units**, charged `instructions + S3D_PIXEL_COST (8)` per shaded pixel and 1
  per scanned-but-uncovered pixel (a thin triangle with a big bounding box is all scan and no
  shading);
* the vertex loop stops at the top of each triangle once the budget is spent;
* the fragment register file is **reset, not re-zeroed**, per pixel. Clearing the ~600-byte
  `S3dShader` for every pixel was the single largest cost in the rasteriser. AGAL temporaries
  are naga `LocalVariable`s with no initialiser, so their value across fragments is undefined
  in Ruffle too — not zeroing them is conformant, not a shortcut.

For scale, the most expensive phase-A row (`agal_cross_product`, a 500x500 quad) spends
~2.25 M units, so every graded row keeps ~5x headroom at 12 M — and all thirteen were re-run
and re-graded at the final setting (run F). A matching **memory** guard caps the back buffer
at 8 M samples (128 MB colour + 32 MB depth), because
`configureBackBuffer(16384, 16384, 4, ...)` is legal and would otherwise ask for 16 GB.

### 4.4 The composite had a second, non-obvious failure mode: the dynamic-bitmap pool cap

`stage3d/scissor_rectangle` configures a **640x480** back buffer on a **550x400** stage, and
`avm2_render_init` sets `dynamic_bitmap_max_{w,h}` to the stage's longest side (550). The
composite quad was therefore *silently dropped* by
`render_webgpu_draw_bitmap_quad_scaled`'s source-size guard, and the test rendered
all-white — 657 946 outliers — with a perfectly correct back buffer sitting in memory. The fix
is a crop to the visible stage rectangle (Ruffle draws the whole quad and lets the render
target clip it, which is visibly identical), which by construction always fits the cap because
`max(crop_w, crop_h) <= max(stage_w, stage_h)`. Both scissor rows then went to **0 outliers**.
Worth flagging for phase B: any future Stage3D row with a back buffer larger than the stage
depends on this crop, and so does any browser title that configures a large back buffer.

### 4.5 `stage3d_rotating_cube` passes with a 0.7 % margin

2144 outliers against a limit of 2160. It is the one flip in the ledger I would not bet on
surviving a renderer change. Its content is the only phase-A row with perspective
(`PerspectiveMatrix3D` + `m44`) and the only one relying on back-face culling for
correctness (it configures `enableDepthAndStencil = false`, so there is no depth buffer at
all), so both the perspective-correct varying interpolation and the `FrontFace::Cw` sign
convention are load-bearing there. `test.toml` does carry two looser alternative checks
(16/1250 and 32/250), which we also satisfy.

### 4.6 Rows that now render but still fail — no verdict change, but the excess moves

`stage3d/{sampler_odd_size,unbound_texture,unbound_texture_multiple}` and the `avm2`
texture/stencil rows now draw geometry with `tex` returning zero, i.e. black where they used
to be blank. They were failing before and they fail after; image comparisons never gate
pass/fail, so there is no CI risk, but a `images=true` baseline read will show their excess
move in both directions. They are phase-B rows and their completion mechanism is the texture
sampler.

### 4.7 Render canary — and the audit the playbook asks for

**Canary audit against my change class.** Before this slice the standing set had **no Stage3D
member and could not have had one**: every Stage3D row was a flat blank render, so a change to
a backend that did not exist could only ever report IDENTICAL. Two tier-2 members are added
(`avm2/stage3d_triangle` — the whole phase-A path in one comparison — and
`avm2/stage3d_rotating_cube` — `m44` + `setProgramConstantsFromMatrix` + back-face culling +
the multi-tick redraw). `stage3d_triangle` graded **0 outliers / max diff 1** against its
golden locally at tolerance 1 / max_outliers 0, so it can be promoted to **tier 1** as soon as
a CI images run confirms it.

**A/B run.** Six members, `-P 1`, `--recompile`, before leg produced by reverse-applying the
patch (never `git stash` — `refs/stash` is shared across worktrees):
`avm1/color`, `avm2/blend_multiply_alpha`, `visual/cache_as_bitmap/masks` (7 comparisons),
`regression/mask_nested_intersect`, `from_shumway/acid/acid-bitmap-fill`,
`avm2/stage3d_triangle` — 12 PNGs. The first five are the shared paths the patch touches (the
AVM2 render walk, the dynamic bitmap-quad path, and — through the sweep — the new GC ext-free
hook); the sixth is expected to DIFFER, and a DIFFERS there is the fix working.

Result — exactly the shape a correct slice should produce:

```
RENDER CANARY  before=before  after=after   6 tests / 12 comparisons

  IDENTICAL    11
  DIFFERS       1
  APPEARED      0   VANISHED 0   NO_RENDER 0

  DIFFERS:
    avm2/stage3d_triangle  output   [DIFFERS]
        diff_channels 192000/880000  mean 27.527  max 255   bbox (0,0)-(320,200)
        image status: fail -> pass    trace: pass -> pass

  TRACE STATUS CHANGES: (none)
```

Every non-Stage3D comparison is **byte-identical**, the one that moved is the new member, its
diff bounding box is **exactly the 320x200 back buffer** (so the composite is landing where
§2.4 says it should and nowhere else), and its image status went **fail -> pass** while its
trace status did not move.

**What the canary cannot tell you here, and what does.** An A/B over non-Stage3D content is
structurally weak for this patch: `avm2_render_stage3ds` returns without drawing unless some
Stage3D has a configured back buffer, and `g_stage3ds[]` is only populated by a
`stage.stage3Ds` read, so for every canary member except the sixth the change provably cannot
reach the pixels. The stronger evidence is run 6's **absolute** verdicts against repo goldens:
`regression/mask_nested_intersect` and `regression/bitmap_pool_layer_cap` at **0 outliers /
max diff 0**, `avm2_timeline_gradients` at 0 outliers, 11/11 trace PASS.

## 5. What is left of the Stage3D arc (each with its completion mechanism)

| slice | rows | what phase A already gives it | what is still missing |
|---|---|---|---|
| **A′** stencil + colorMask | `avm2/stage3d_stencil` (tol **0/0**), `avm2/stage3d_fractal` | the rasteriser, the interpreter, the composite | a per-sample stencil plane, `setStencilActions` + `setStencilReferenceValue` retention, `setColorMask` as a write mask in the sample store. ~150 LOC on top of what is here; the sample loop already has the hook point. |
| **B** textures | `sampler`, `sampler_partial_upload`, `stage3d/sampler_odd_size`, `ignore_sampler_override`, `stage3d/unbound_texture{,_multiple}`, `texture_bytearray`, `stage3d_texture`, `stage3d_bitmap` | `tex` is already decoded and dispatched; it writes zero | texel storage on `Avm2Texture3DExt`, `uploadFrom{BitmapData,ByteArray}`, the sampler-state precedence rule (bytecode config vs `setSamplerStateAt`, the `ignore_sampler` bit), unbound-texture semantics, and `setRenderToTexture` (render target redirection, which the backend does not model at all yet). |
| **B′** ATF/DXT | `texture_bytearray_compressed_{alpha,raw_alpha}` | the ATF header parse already exists (S2) | DXT1/DXT5 block decode. |
| **G2 blend** | `stage3d_blend` (the board's largest single row, 1.0 M excess) | `setBlendFactors` is still a validator only | the ten blend factors in the sample store — but the test also needs B's textures, so it is a B row, not an A′ one. |
| **C** heavy | `stage3d_raytrace`, `away3d_*` | nothing — they hit the §4.3 budget by design | **the CPU route is a permanent NO-GO for these.** They are the only rows that require the GPU/WGSL route the w1 report priced at 1600-1900 LOC. Decide that separately; phase A's interpreter remains a useful byte-level oracle for it either way. |

## 6. New unclaimed leads

* **`avm2/stage_scale_factor` is a `Stage.transform.matrix` row, not a Stage3D row** (§4.1).
  Nobody owns it. Its whole 1100x800 frame is wrong, including two plain `Shape`s drawn under
  a `Matrix(1.5, 0, 0, 1, 10, 100)` set on the Stage with `scaleMode = "noScale"`. Cheap to
  scope, probably not cheap to fix.
* **The composite is the first consumer of the dynamic-bitmap pool that can legitimately want
  a source larger than the stage** (§4.4). The crop dodges it for the corpus, but a browser
  title with a large Stage3D back buffer and a Stage3D `x`/`y` offset will pay a per-frame
  `memcpy` of the visible rectangle. If that ever matters, the honest fix is a renderer-side
  sub-rectangle upload, not a bigger cap.
* **A `regression/` fixture for the §2.3 model is still unwritten** — the w1 report asked for
  one (a `mov`-only triangle with a golden from the Ruffle exporter, not from us) to pin the
  composite position/scale/filter rules analytically rather than by way of the upstream
  goldens. I did not write it: the twelve upstream rows now cover the same rules with
  *upstream* goldens, which is a stronger oracle than an exporter capture, so the fixture is
  now a nice-to-have rather than the only pin. It would still be the right place to pin the
  crop rule of §4.4, which no corpus row exercises with a non-zero `Stage3D.x`.
* **Nothing in the corpus exercises `Stage3D.x`/`y` non-zero.** Every fixture leaves them at
  0 (`stage3d_triangle` even has the assignment commented out), so the translate arm of the
  composite is implemented from `context3d_object.rs:310-313` and unverified by any test.
* **`ife`/`els`/`eif` are implemented on component 0 of the comparison**, which is a guess:
  Ruffle emits a naga `Binary` on two vec4s and lets the backend scalarise it. No phase-A
  row uses control flow; `raytrace` does. Whoever takes slice C should pin the real rule.
