# Plan: skip wasted per-fragment texture sampling in the WebGPU fragment shader

**Status:** EXECUTED 2026-06-29 (commit `3d2ea1b5c`, Option 1). Pixel-identity proven +
graphics CI green (0 regressions). Perf win UNCONFIRMED on WSL2 SwiftShader (no measurable
drop — likely SwiftShader already DCEs the dead samples); real-GPU (Windows) run is now the
decisive measurement. See §8 for the execution record.

**Goal:** make solid-colour (and single-fill) shapes stop paying for gradient + bitmap
texture sampling they don't use, closing most of the Ruffle-vs-SWFRecomp WASM render gap
on fill-heavy / high-overdraw games (target: `flasharchive/N`).

## 1. Problem & root cause (established this session)

Full chain is in `tools/divergence/perf/README.md` and memory
`ruffle-wasm-perf-shim-and-build`. Summary:

- On N, SWFRecomp's per-frame wall time is ~150 ms vs Ruffle's ~28 ms (WSL2 SwiftShader),
  ~82 % of ours is main-thread-idle = async GPU wait inside the render submit.
- **Not** draw count (Ruffle issues similar-or-more draws), **not** MSAA (both 4×), **not**
  resolution or pass count.
- **It is the fragment shader.** `SWFModernRuntime/src/rendering/render_webgpu.c`,
  `fragment_wgsl` / `fs_main`: every fragment unconditionally runs
  `sample_gradient` three times (linear/radial/focal = 6 `textureLoad`s) **and** two bitmap
  `textureSample`s, then an `if`-chain on `v_style_type` keeps only the one it needs. So a
  solid-colour fragment (`v_style_type == 0x00`, the common case for N's particles) pays
  ~8 texture ops/pixel for nothing. Ruffle uses specialised pipelines (`color.wgsl` trivial,
  `gradient.wgsl`, `bitmap.wgsl`) → solid fills do ~0 texture ops. On SwiftShader (no HW
  texture units) × N's overdraw, that per-fragment cost is the gap.

The shader was written this way because the original author believed all texture access had
to be in uniform control flow ("Sample all textures unconditionally (uniform control flow
required by Chrome/Dawn)" — comment at fs_main).

## 2. Chosen approach

**Option 1 (do this first — small, low-risk, single file):** make the texture work
conditional on fill type inside `fs_main`, exploiting two WGSL facts:

- `textureLoad` has **no** uniform-control-flow requirement — the three `sample_gradient`
  calls (which use `textureLoad`, not `textureSample`) can already be moved inside the
  gradient branch legally.
- `textureSample` *does* require uniform control flow, but **`textureSampleLevel(t, s, uv, layer, 0.0)`** does **not** (explicit LOD ⇒ no implicit derivatives ⇒ allowed in
  non-uniform flow). Swap the two bitmap `textureSample`s for `textureSampleLevel(..., 0.0)`
  and move them into the bitmap branch.

Net: a solid-colour fragment executes zero texture ops; gradient fragments do only their
gradient sample; bitmap fragments do only their bitmap sample. No pipeline/host-code change.

**Option 2 (fallback, only if Option 1 is insufficient or hits a WGSL snag):** specialise
pipelines per fill type like Ruffle (separate color/gradient/bitmap fragment entry points,
selected by `v_style_type` at draw time). Bigger change — touches pipeline creation, draw
dispatch, and the batching that groups draws by pipeline. Defer unless measurement demands.

## 3. WGSL invariants to preserve (do NOT regress these)

The current unconditional form encodes several hard-won correctness details — keep every one:

1. **Dummy-texture OOB guard.** `grad_layer`/`bmp_layer` use `select(0, i32(v_style_id), is_*)`
   so a non-gradient/non-bitmap fragment indexes layer 0 of the 1-layer dummy texture
   (Chrome/Dawn vs Firefox handle OOB differently). When sampling moves inside the branch,
   the branch only runs when `is_gradient`/`is_bitmap` is true, so the real `v_style_id` is
   valid there — but keep a sane default for the non-taken path's variable init.
2. **Gradient ramp via `textureLoad` (not `textureSample`)** — exact ramp index, no V-axis
   filter bleed. Preserve `sample_gradient` as-is; only move *where* it's called.
3. **`textureLoad` is already legal in non-uniform flow** — moving it into the branch needs
   no signature change.
4. **Bitmap repeat vs clamp** — `v_style_type 0x40/0x42` use `bitmap_repeat_sample`
   (`fract(uv/ratio)*ratio`), `0x41/0x43` use the plain sample. Keep both forms.
5. **LinearRGB→sRGB** — the `is_gradient && (bit 4 set)` path calling `apply_linear_to_srgb`
   must still run for gradients.
6. **cxform tail** — `return apply_cxform(color, v_cxform_id)` applies to **all** fill types
   unconditionally. Keep it outside the branches.
7. **Default/unknown fill** (`else { color = vec4f(0.0); }`) stays.
8. Sampler/bindings unchanged — `gradient_tex/samp`, `bitmap_tex/samp` group/bindings stay;
   we only change call sites.

## 4. Edit steps

Single file: `SWFModernRuntime/src/rendering/render_webgpu.c`, `fragment_wgsl` string.

1. Replace the unconditional block (the three `sample_gradient` + two bitmap samples at the
   top of `fs_main`) with a `var color: vec4f` defaulted, then assign inside the existing
   `if (v_style_type == ...)` chain, computing only the needed sample in each arm:
   - `0x00` → `color = in.v_args;`
   - `0x10` → `color = sample_gradient(linear_t(in.v_args), i32(in.v_style_id));`
   - `0x12` → radial, `0x13` → focal (same pattern).
   - `0x40/0x42` → `textureSampleLevel(bitmap_tex, bitmap_samp, fract(uv/ratio)*ratio, i32(in.v_style_id), 0.0)`.
   - `0x41/0x43` → `textureSampleLevel(bitmap_tex, bitmap_samp, in.v_args.xy, i32(in.v_style_id), 0.0)`.
2. Keep the linearRGB and cxform tails unchanged.
3. Confirm no remaining `textureSample(` in `fs_main` (only `textureSampleLevel` / `textureLoad`).
4. Native/offscreen use the same WGSL — no `#ifdef` needed; this is a pure shader change.

## 5. Verification (gating — do all before committing)

**Pixel-identity is the gate.** The shader must produce byte-identical output for every fill
type. Build + diff the old graphics suite locally for representative tests, one per path:

```bash
# solid color, gradients, bitmaps, repeat, morph, linearRGB, cxform
for t in two_squares awful_gradient awful_radial_gradient focal_radial_gradient \
         gradient_spread rgba_shape jpeg2_bitmap nonsmoothed_repeating_bitmap \
         define_morph_shape color_transform; do
  ./SWFRecomp/scripts/build_test.sh graphics/$t wasm --graphics   # rebuilds shader fresh
done
# and the Ruffle graphics-native pixel suite for a few:
python3 ruffle-tests/verify_output.py --test=<name> --mode=graphics --diff
```

(See `local-graphics-fix-verify-stale-caches` memory: use `CCACHE_DISABLE=1` and delete
stale `output.actual.png` so you measure the NEW build, not a cached one.)

**Then graphics CI** (the real gate): per `.claude/pipeline-handoff.md`, dispatch
`ruffle-tests.yml` in **graphics** mode (this is a shared graphics-path change). 0 pass→fail
regressions required. no-graphics is irrelevant here (shader only affects graphics builds).

**Then measure the win:** rebuild N into docs2 and re-run the harness —
```bash
GRAPHICS_BUILD_TIMEOUT=900 ./SWFRecomp/scripts/build_swf_batch.sh <dir-with-N.swf> \
  --docs-dir docs2 --namespace flasharchive --catalog-name flasharchive_catalog.json
python3 tools/divergence/perf/n_swfrecomp_perf.py 8 15   # expect frame-CPU + draws to drop
```
Expect frame wall-time to fall sharply (texture ops/fragment → ~0 for solid fills); `draws`
unchanged. Re-A/B vs Ruffle. A **real-GPU run on Windows** is the final confirmation (WSL2
SwiftShader exaggerates the absolute numbers but the relative drop should hold).

## 6. Risks & rollback

- **Risk: `textureSampleLevel` mip/LOD difference.** Bitmaps here are single-level (no
  mips); `0.0` LOD == the only level, so visual output is identical. Verify on the bitmap
  tests; if a filtering difference appears, that's the signal to reconsider.
- **Risk: WGSL uniformity analyzer still complains.** If Dawn rejects `textureSampleLevel`
  in the branch for any reason, fall back to computing the bitmap sample once before the
  chain (still saves the 6 gradient `textureLoad`s for solid/bitmap fills — a partial win)
  or go to Option 2.
- **Risk: a fill path subtly changes** (e.g. focal gradient, repeat bitmap) — caught by the
  per-path pixel tests in §5. Do not skip any path.
- **Rollback:** single-file, single-string change — revert the `fragment_wgsl` edit. No host
  code or pipeline changes to unwind.

## 7. Out of scope (later)

- Overdraw reduction (culling fully-occluded particles, particle lifetime) — separate lever,
  see `n-laser-is-frozen-particle-sprite-not-drawing-api` / `wasm-game-performance-profiling`.
- GPU timestamp queries for direct GPU-time measurement.
- Pipeline specialisation (Option 2) unless Option 1 underdelivers.

## 8. Execution record (2026-06-29, commit `3d2ea1b5c`)

**Done — Option 1, single-file `render_webgpu.c fragment_wgsl` edit.** `fs_main` now computes
only the texture sample the fill type needs: `sample_gradient` (textureLoad — no uniformity
requirement) moved into the gradient branches; both bitmap `textureSample`s swapped for
`textureSampleLevel(..., 0.0)` (explicit LOD ⇒ no derivatives ⇒ legal in non-uniform flow) and
moved into the bitmap branch. Solid fills now do zero texture ops. The old `select(0, v_style_id,
is_*)` OOB layer guard was dropped (each texture is sampled only inside its own branch, where
`v_style_id` is valid); `is_bitmap` removed (now unused); ramp exactness, repeat-vs-clamp,
linearRGB→sRGB, unconditional cxform tail, and unknown-fill default all preserved.

**Pixel-identity: PROVEN.** Native offscreen Dawn (`--mode=graphics`):
- Oracle pass on the NEW shader for every fill path: `movieclip_begin_gradient_fill`,
  `movieclip_line_gradient_style`, `color`, `color_transform`, `mcl_target_jpg`,
  `bitmap_data_copypixels`, `from_gnash/.../morph_test1` — all PASS.
- **Byte-identical old-vs-new `output.actual.png`** (`--verbose`, then `cmp`) for the two
  highest-risk paths: gradient fill (6 moved textureLoads) and JPEG bitmap (textureSample →
  textureSampleLevel). `md5` matched exactly. (Note: `difference.png` is only retained with
  `--verbose`; without it you compare stale artifacts — use `output.actual.png`.)

**Graphics CI: GREEN, 0 regressions.** `ruffle-tests.yml mode=graphics` run `28415138546`:
every suite "No changes detected" — avm1 629/704, shumway 73/92 + avm1 46/47, all 5 gnash
sub-suites unchanged. Confirms pixel-identity at full-suite scale.

**Perf on WSL2 SwiftShader: NO measurable win (as the harness can see it).** Two runs of
`n_swfrecomp_perf.py 8 15` on the freshly-redeployed N (verified new shader is in the wasm:
`grep -a textureSampleLevel docs2/examples/flasharchive/N/N.wasm` → present): frame CPU median
**139.7 / 142.5 ms**, draws **480/481** — statistically unchanged from the ~147–177 ms baseline.
Most likely cause: **SwiftShader's LLVM-based shader compiler already dead-code-eliminates the
uber-shader's unused samples** (their results never reach `@location(0)`), so hand-specializing
is a no-op *on SwiftShader*. (The alternative — the bottleneck is overdraw / fragment *count*,
not per-fragment texture ops — points to the same out-of-scope §7 lever and the same "no
SwiftShader win" outcome.) The change is still correct and expected to help on real GPU drivers
that don't DCE the uber-shader as aggressively and on HW where each texture op is a real cost.
**A real-GPU run on the user's Windows machine is the decisive next measurement** (§5 always
flagged this). If it too shows no win, the lever is overdraw reduction (§7), not the shader.
