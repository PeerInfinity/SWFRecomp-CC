# Bitmap texture pools replace the uniform bitmap array (2026-09-02)

Slice brief: `SWFRecompDocs/prompts/bitmap-texture-envelope-prompt.md`
(baseline `923b90469`). Landed in `c6681e744`
(`SWFModernRuntime/src/rendering/render_webgpu.c`, its header, and the bundle
`build.sh` template).

## Problem

`render_webgpu.c` allocated ONE `texture_2d_array` for every static bitmap of
the movie plus a dynamic reserve, each layer `(highest_w+1) x (highest_h+1)`
where the two maxima come from different bitmaps. The original Seedling
(Newgrounds 598977) has 284 bitmaps holding 13.4 MiB of RGBA pixels; a 4480x82
strip and a 486x1106 image made the envelope 4481x1107, i.e. 5.25 GiB for the
static layers alone. D3D12 refused the allocation, Dawn lost the device
(`DXGI_ERROR_DEVICE_REMOVED`) and the canvas stayed black
(`in-browser-recompiler-refresh-assessment.md` §8). `BITMAP_ARRAY_HARD_LIMIT`
only clamped the dynamic growth, by design.

## Design chosen: size-class pools (option 1 of the brief), 12 of them

- **Static pools 0..7** — class by `max(w,h)+1 <= 64, 128, 256, 512, 1024,
  2048, 4096`, and everything larger. Each pool's layer is the bounding box of
  ITS members. Built in `render_webgpu_finalize_bitmaps`, when every static
  size is known (the recompiler emits all `defineBitmap` calls, then
  `finalizeBitmaps`, in `tagInit` before the first frame); `upload_bitmap` only
  records size + data offset now. No recompiler change and no regenerated C:
  the slot numbering in the vertex data is unchanged.
- **Dynamic pools 8..11** — nominal squares 256, 512, 1024 (each clipped to
  `dynamic_bitmap_max`) and the full `dynamic_bitmap_max` box. A draw takes
  the first pool its source fits. Pools are created on first use with 16
  layers and DOUBLE mid-frame when exhausted, up to the old policy's ceiling
  (`64` floor, `128` when the 384 MiB budget allows, `1.5 GiB` per-allocation
  hard limit). Growth mid-pass works because every dynamic draw is its own draw
  call: the bind group is rebuilt and re-set on the open pass; draws already
  recorded keep the old texture alive through the old bind group. Nothing is
  allocated for sizes a movie never draws — relevant because the AVM2 boot
  raises `dynamic_bitmap_max` to the largest embedded bitmap.
- **Shader** — the 12 pools are bound at group(2) bindings 4..15 (13 sampled
  textures per stage, under WebGPU's guaranteed 16). The vertex stage reads the
  slot table (now 8 u32 per slot: `{content, padded}`, `{pool, layer}`) and
  packs `pool << 16 | layer` into `v_style_id`; `sample_bitmap()` switches on
  the pool (explicit-LOD sampling, so non-uniform control flow is fine).
- **Layer contents are unchanged**: a bitmap sits at the layer origin with the
  same +1 edge-clamp row/column and the rest of the layer stays transparent
  (never written), so a clipped static fill reading past its bitmap still
  reads transparent. `beginBitmapFill` no longer pre-tiles a full layer: it
  uploads `(src+1)^2` (wrap copy for repeat, edge copy for clipped) and its
  clipped arm sets style-word bit 11, which makes the fragment stage clamp UVs
  to the content instead of reading whatever a previous frame left in the
  reused dynamic layer. Static fills never set the bit.
- Diagnostics: browser builds log every pool allocation and each init step
  (with buffer sizes) to the console via `emscripten_log` (never stdout, so
  trace capture is untouched); native builds print the same under
  `SWF_WARN_BITMAP_CAP`.

Rejected: a packed atlas (needs UV rescale + gutters and changes the clipped
edge behaviour of every static fill) and per-bitmap bind groups (static shapes
batch several bitmaps into one draw).

## Measurements

| Movie | before (one array) | after (pools) |
|---|---|---|
| Seedling original, 284 bitmaps, 13.4 MiB pixels | 4481x1107 x (284+1) = **5.25 GiB** → device lost | 7 static pools, **92.3 MiB** (61x51x134, 121x105x62, 225x193x41, 487x481x32, 921x641x10, 1681x1107x4, 4481x83x1) |
| Seedling teleport (docs2 demo), 281 bitmaps | 4481x641 x (281+64) = 3.0 GiB | same class layout minus the 1106-tall image; the biggest pool is 1681x641 |
| Doodle Jump (docs2 demo), 18 bitmaps | 241x401 x (18+128) ≈ 54 MiB | 3 pools, **2.7 MiB** (61x46x10, 63x67x1, 241x401x7) |

Note: in AVM2 movies `tagInit` never runs (only `swfStart`/`swf_core` call it),
so the static bitmaps are not uploaded at all — the Seedling arrays were pure
waste, and the game's bitmaps reach the GPU through the dynamic BitmapData
path (pool 9/10 for its 480x480 buffer). Static bitmap *fills* inside AVM2
shapes were and remain un-uploaded (pre-existing gap, outside this slice).

Pixel A/B (`ruffle-tests/render_canary.py`, local Dawn, byte bar):
**60/61 comparisons IDENTICAL**; `from_shumway/acid/acid-bitmap-fill`
(smoothed static fill) differs on 54 of 1,920,000 channels by max 1 LSB — the
`inv_pos / padded * padded` round trip with a different `padded`. Trace and
image statuses unchanged on all 29 canary tests.

Browser (Windows Chrome via WSL interop, real GPU):
- Original Seedling through the brief's repro bundle
  (`~/CC/seedling_original_build/bundle`, `FRESH=1 ./build.sh`): init completes,
  no device loss, the Newgrounds intro screen (tank + PLAY + progress bar)
  renders. Same result for the original built through
  `build_wasm_avm2.sh` and served from `docs2/demo.html?test=avm2/seedling_orig`.
- Doodle Jump (rebuilt with the new runtime, deployed to docs2): title screen
  renders.
- Seedling teleport (docs2 demo): the DEPLOYED demo (`docs2/examples/avm2/
  seedling`, built 2026-07 from `~/CC/seedling_teleport_build/recompiled`)
  is untouched and still renders OverWorld1. A rebuild with the new runtime
  could NOT be verified: that recompiled tree no longer links against the
  current runtime (undefined `avm2_generated_statictexts` /
  `avm2_generated_shape_geom_count`), and a tree regenerated with today's
  recompiler (`recompiled_pools`) builds but its page never reaches "WASM SWF
  Runtime Loaded" — it stalls before any runtime or renderer code runs, so
  this is recompiler/runtime drift for the teleport tree, not the pool change
  (the ORIGINAL Seedling built the same way, same runtime, same page, renders).
  Left for the AVM2 in-browser slice, which rebuilds AS3 titles anyway.

CI: `ruffle-tests.yml` graphics `categories=all`, run 33682840260 at
`c6681e744`: green, `corpus_status_diff.py` on the 4478-test intersection —
status histogram identical (pass 4120, ruffle_matched 235, output_mismatch
122, runtime_error 1; effective 4355), 0 gains, 0 regressions, 0 other moves.
Pages deploy (bundle `build.sh` template) run 33682992483: success.

## Things that cost time (recorded in memory `bitmap-texture-pools`)

1. `smooth` is a reserved WGSL word. The shader failed to parse, every pipeline
   was invalid, Dawn dropped every draw — and the trace tests all PASSED. Only
   the render canary (whole-image DIFFERS on the four probe tests) caught it.
   The error text is visible by running a kept test binary
   (`SWF_KEEP_BUILD_DIR`) under lavapipe.
2. A `python3 -m http.server` left by a previous session owned port 8021 and
   served an old scratchpad copy of the bundle; every Chrome run for an hour
   showed "the failure persists" against the wrong wasm. Check
   `Content-Length` against the file on disk and `readlink /proc/<pid>/cwd`
   of the listener before believing a browser result.
3. The downloaded bundle's `build.sh` was incremental by `.c` mtime only, so a
   header change left every other TU compiled against the old
   `WebGPURenderContext` layout (symptom: `createBindGroup ... 'resource' ...
   Required member is undefined`). The template now rebuilds when any header
   under `runtime/include` is newer than the `.o`; an existing bundle needs
   `FRESH=1` once.
4. `deploy_wasm_avm2.sh <name>` deploys `build_wasm_avm2/<name>/`; with a custom
   `AVM2_OUT_DIR` it silently deploys a stale same-name directory. The teleport
   `recompiled/` tree also predates the current runtime (undefined
   `avm2_generated_*` at link) and had to be regenerated with the current
   recompiler (`~/CC/seedling_teleport_build/recompiled_pools`).

## Residuals

- A static pool with more than the adapter's `maxTextureArrayLayers` members
  (256 on SwiftShader/WSL2) still fails — same wall as before, now per class
  instead of per movie. Splitting a class across two bindings would need more
  than the 16 guaranteed sampled textures; revisit if a real title hits it.
- A single bitmap wider/taller than `maxTextureDimension2D` fails as before.
- Smoothed repeating `beginBitmapFill` now blends into its own first texel at
  the right/bottom tile edge (wrap copy) but clamps at the left/top edge — the
  same asymmetry the static repeat path always had.
- `flashbang.c` (the SDL GPU backend, off by default) keeps the old single
  array.

## Next slice

`SWFRecompDocs/prompts/avm2-in-browser-investigation-prompt.md` (can AS3 SWFs
run through the in-browser recompiler). Nothing here moves bitmap data out of
the generated static arrays: `bitmap_data[]` is still emitted by the
recompiler and only the GPU-side layout changed, so that brief's data-path
question stands as written. One fact worth carrying over: the in-browser
bundle's incremental `build.sh` now honours header changes.
