# Session prompt — AVM2 Stage 12 (Seedling), session 4: render real gameplay (FlashPunk software-buffer draw() path)

You are continuing **Stage 12** (Seedling bring-up) of the AVM2 Seedling plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md` §2). Session 3 (2026-07-13) reached
**real, playable Seedling gameplay** — but the world doesn't render. Your job this
session: **close the one render gap that stands between "logic runs" and "gameplay
renders."**

## Read first
- Memory **`seedling-teleport-gameplay`** — how the gameplay build was produced and
  the exact render-gap finding. **Start here.**
- Memory **`avm2-stage9-render`** — the AVM2 render walk (`avm2_display.c`
  `avm2_render_*`) + the Stage-9 `BitmapData.draw` CPU fast path and its
  documented "identity-2x2 only" limitation. This is the code you'll extend.
- Memory `avm2-stage12-seedling` (s3) — the CPU-dump validator (`AVM2_CPU_DUMP`),
  the Ruffle `RUFFLE_MOVIE_URL` oracle patch, `AVM2_MAX_TICKS`.
- `ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md` — the two
  "Stage 12 session 3" sections (validated-frames + gameplay-render-gap).
- The game's own FlashPunk source: `~/CC/seedling/src/net/flashpunk/` (read
  `graphics/Canvas.as`, `graphics/Image.as`, `Screen.as` before touching code).

## The state of play (verified in session 3)
- A **teleport build** boots straight into OverWorld1 gameplay (no Newgrounds, no
  intros): `~/CC/seedling_teleport_build/` holds `Seedling_teleport.swf`,
  `build_teleport.sh`, `teleport.patch`, `fix_embed_case.py`, a **pre-recompiled**
  `recompiled/` (RecompiledABC/Scripts/Tags + test.swf + test.toml — skips the
  ~15 min mxmlc + SWFRecomp step), a **`ruffle_oracle_60/`** (60 Ruffle frames
  `00.png..59.png` of the same SWF), and `REFERENCE_ours_vs_ruffle_f59.png`.
- **Our AVM2 runtime runs 60 gameplay frames with ZERO uncaught errors** — the
  game LOGIC is fully correct (character spawns, world loads, HUD present).
- **But ~99% of our frame is black.** Only the player character + the green HUD
  icons render. The overworld tiles/scenery are missing.

## The gap (root-caused — don't re-derive, verify)
FlashPunk renders the whole world into a **software back-buffer** — `FP.buffer`, a
`BitmapData` displayed by an on-stage `Bitmap` (double-buffered in `Screen.as`
`_bitmap[0/1]` with a visible-toggle). Our render walk already blits that on-stage
Bitmap correctly, so **the fix is NOT in the render walk** — it's that `FP.buffer`'s
pixels are incomplete because our `BitmapData.draw` drops most draws:
- `Image.render` (character, HUD): `FP.buffer.copyPixels(...)` (no transform) →
  our `copyPixels` works → **these render.**
- `Canvas.render` (Tilemap + Backdrop extend `Canvas`; scenery is mostly
  `Spritemap`/`Image` with transforms): `FP.buffer.draw(buffer, _matrix, _tint,
  blend)` (Canvas.as ~line 71; Image.as ~line 117) → **`BitmapData.draw` with a
  non-identity matrix and/or blend** → our CPU path rejects it → **scenery never
  composites.**
- Our `bd_draw` in `SWFModernRuntime/src/avm2/avm2_bitmap.c` (~line 1450) only
  CPU-blits when the composed matrix is **identity-2x2 (translation only)** and
  blend is normal (see the `identity_2x2` / `extra_matrix_ok` /
  `blend_alpha_or_erase` guards ~line 1500); anything else falls to the offscreen
  **GPU** path, which the headless CPU compositor never runs → the draw is dropped.

## Goal — general affine (+colorTransform, +blend) CPU rasterization in `bd_draw`
Extend `bd_draw`'s CPU path to composite a **BitmapData source** into the dest
BitmapData under an **arbitrary affine matrix** (scale/rotate/skew/translate) with
the optional `colorTransform` and the common blend modes, so `FP.buffer.draw(...)`
actually writes scenery pixels. Scope notes:
- **BitmapData source only.** FlashPunk always draws BitmapData buffers into
  FP.buffer (never a live DisplayObject), so you do NOT need the DisplayObject/GPU
  draw path — a software raster is the whole job for this game.
- **Reference implementation already exists.** The CPU-dump compositor
  `avm2_cpu_composite_bitmap` (in `avm2_display.c`, added session 3) does exactly
  the inverse-map you need: bbox the source corners through the matrix, invert the
  2×2, per-dest-pixel sample-back (nearest-neighbor), `blend_over`. Port that
  inverse-map into `bd_draw` for the non-identity case, applying the
  `colorTransform` (multiply+add per channel) and honoring `smoothing`
  (nearest is fine to start; the tests are pixel art).
- **Blend modes:** start with `normal` (over) — that covers the tilemap/backdrop.
  `_tint` is a colorTransform (already parsed in `bd_draw` arg 2). If a scenery
  layer uses `add`/`multiply`, add those blend funcs (Ruffle
  `bitmap_data.rs::blend_over`/`blend_*`), but only if the harness shows they're
  needed — don't speculatively implement all 14.
- **Premultiplied ARGB** is the storage (see `premul`/`unmul`/`blend_over` at the
  top of avm2_bitmap.c) — keep the math premultiplied end-to-end.

## Verification (this is the payoff — a live gameplay oracle)
- **Fast inner loop, no rebuild of the game:** the recompiled C is persisted, so
  point verify at it. From a scratch test dir seeded from
  `~/CC/seedling_teleport_build/recompiled/`:
  ```bash
  export AVM2_CPU_DUMP=<scratch>/cpudump/tp_   AVM2_MAX_TICKS=60
  export SWFRECOMP_OPT_LEVEL=-O0 SWFRECOMP_COMPILE_TIMEOUT=900   # 13MB single TU
  python3 ruffle-tests/verify_output.py --test=<name> --tests-dir=<scratch> \
      --mode=no-graphics --verbose 2>&1 | grep -i uncaught
  ```
  Only `avm2_bitmap.c` changes, so the rebuild is one TU (ccache) — fast.
- **Compare to the oracle:** our `tp_NNN.ppm` (3-digit) vs
  `~/CC/seedling_teleport_build/ruffle_oracle_60/NN.png` (2-digit). Convert
  PPM→PNG with PIL; compute per-frame MAD; a correct fix takes frame 59 from
  ~99% black to the overworld matching Ruffle (house/water/trees/path/character).
  Session 3's `cmp.py`/`fullcmp.py` pattern (per-pixel MAD + side-by-side + diff
  heat) is the template.
- **BACK THE FIX WITH AN UPSTREAM TRACE TEST — the game is the INTEGRATION check,
  never the oracle.** The `bitmapdata_draw*` family in
  `ruffle-tests/tests/swfs/avm2/` is the graded oracle for `BitmapData.draw`
  (matrix/colorTransform/blend). Find the ones that need a non-identity matrix
  (they were deferred in Stage 9 — see `_investigation/STAGE9_CANDIDATES.txt` /
  STAGE7) and make them pass under `--mode=graphics`; that is the load-bearing
  proof, not "Seedling looks right." Run each locally with
  `verify_output.py --test=<name> --mode=graphics --diff`.

## Safeguards (carried from the whole plan)
1. The game is the INTEGRATION check, never the oracle — every fix graded by its
   `bitmapdata_draw*` upstream trace family; no "looks right in Seedling" merges.
2. Divergence-harness first: reproduce with a trace test before trusting the game.
3. GC (`avm2-stage11-gc`): any new C-static `Avm2Object*` must be rooted the day
   it's added; any temp BitmapData you alloc inside `bd_draw` must be freed or
   GC-visible. Bisect misbehaviour with `AVM2_GC=0`.
4. Conflict boundary: own `src/avm2/avm2_bitmap.c` (+ `avm2_display.c` only if the
   render walk genuinely needs it — it shouldn't). **Never touch `action.c`.**
   `bd_draw`'s CPU path is AVM2-only; no `render_webgpu.c` change should be needed.

## Workflow & bookkeeping
Per-test local runs only (never the full suite locally). Full suite via CI **both
modes** (`avm2_gc=1`), pipeline per `.claude/pipeline-handoff.md` (autonomous
commit/push/CI authorized) — graphics mode matters here since `bitmapdata_draw*`
is graded under `--mode=graphics`. Keep the game out of the CI pass-rate metric
(no trace oracle). At end of session update the `seedling-teleport-gameplay` +
`avm2-stage9-render` memories + `CURRENT_STATUS.md` + plan §2 with the new render
baseline (which draw() matrices/blends now composite; MAD vs the oracle; any new
gameplay divergence surfaced once the world renders).

## If the world renders — the next divergences to expect
Once scenery composites, driving deeper (raise `AVM2_MAX_TICKS`, or feed the
Stage-8 `input.json` harness to move the character) will surface real gameplay
divergences: `.oel` level streaming (ByteArray/E4X in Game.as), `ColorMatrixFilter`
(flash.filters — likely unimplemented), `Emitter` particles, `flash.ui.Keyboard`
constants. Fix each with a trace/regression test where a family exists. But render
first — it's the gate that makes everything else observable.
