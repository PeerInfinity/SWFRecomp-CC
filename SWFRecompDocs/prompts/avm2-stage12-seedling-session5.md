# Session prompt — AVM2 Stage 12 (Seedling), session 5: fix the NaN full-screen scenery matrix (`.oel`/property init)

You are continuing **Stage 12** (Seedling bring-up) of the AVM2 Seedling plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md` §2). Session 4 (2026-07-13) built the
render-compositing machinery — `flash.geom.Matrix` methods + a general-affine
`BitmapData.draw` CPU raster — and **re-diagnosed the Seedling render gap**: it is
NOT a `bd_draw` limitation. The world still renders ~99% black, but now for a
precise, located reason. **Your job: find why the one full-screen scenery surface
draws with a NaN matrix, fix it, and get Seedling gameplay to actually render.**

## Read first (in this order)
- Memory **`seedling-teleport-gameplay`** — the teleport build recipe + the
  corrected render-gap finding + the s4 NaN-probe result. **Start here.**
- Memory **`avm2-stage9-render`** — the AVM2 render walk + the s4 general-affine
  `bd_draw` path (avm2_bitmap.c) + the `flash.geom.Matrix` surface (avm2_display.c).
- Memory **`image-comparisons-dont-gate-passfail`** — CRITICAL: `verify_output.py`
  pass/fail is TRACE-only; image comparisons are recorded but never gate. Don't
  trust graphics-mode "pass" counts for render health. Local WSL2 rendering isn't
  pixel-exact either — **use `AVM2_CPU_DUMP` (GPU-free, deterministic) to validate,
  not `--mode=graphics` capture.**
- Memory `avm2-stage12-seedling` (s3) — the `AVM2_CPU_DUMP` sink, the Ruffle
  `RUFFLE_MOVIE_URL` oracle, `AVM2_MAX_TICKS`.
- The FlashPunk source: `~/CC/seedling/src/net/flashpunk/` — read `graphics/Image.as`
  (render ~L109, `_matrix.a = scaleX * scale`), `graphics/Canvas.as`,
  `graphics/Backdrop.as`, `graphics/Tilemap.as`, and how the OverWorld builds its
  background (`~/CC/seedling/src/` worlds/levels).

## The state of play (verified in s4)
- **The render-compositing code is DONE and correct.** `flash.geom.Matrix`
  (rotate/translate/scale/concat/invert/createBox/createGradientBox/transformPoint/
  deltaTransformPoint/setTo/copyFrom/copyRow+ColumnFrom, pure f64) and `bd_draw`'s
  general-affine CPU raster (inverse-map, nearest-neighbor, +colorTransform) both
  landed in `9e27d9d61`. Proven by the `bitmapdata_draw_rotation` oracle:
  **CPU-dump MAD 0.134, 116/220000 px differ** (all rotated-edge). CI both modes:
  avm2 828→828, ZERO pass→fail, wasm green; `matrix` trace test 9→281/338 lines
  (rest is its stale committed test.swf, not our code).
- **The remaining gap is NaN INPUT matrices, not `bd_draw`.** With Matrix methods
  in, Seedling's scenery draws now REACH `bd_draw`'s affine branch — but every one
  arrives with `m=[nan nan nan nan nan nan]`. `bd_draw` now no-ops non-finite
  matrices (clean miss). Frame 59 still ~98.7% black, 0 uncaught.

## The lead (root-cause this, don't re-derive the above)
The s4 NaN-probe (temporary instrumentation of `bd_draw`, now reverted) found:
- **EVERY NaN affine draw is `src=160x160 → dst=160x160`.** `dst 160x160` =
  `FP.buffer` (480 stage / `FP.screen.scale = 3`). So it's **ONE full-screen-sized
  buffer** — a Backdrop/Canvas/level Image, NOT scattered sprites.
- **ZERO finite-affine draws** — nothing scaled renders at all.
- The character + HUD still render (via `copyPixels`, `scale==1`), so AS3 field-init
  (`public var scale:Number = 1`) works for *those* Images.

So: **one 160x160 scenery surface has `scaleX * scale` = NaN** (Image.render ~L110).
Find which entity/graphic creates it and why its `scale`/`scaleX` is NaN. Two
hypotheses to test first:
1. **`.oel` level data drives its scale/position and isn't loaded** (Game.as reads
   `.oel` via `[Embed]` ByteArray → XML/E4X). If the level geometry never parses,
   scenery scale/origin stay NaN. Check whether the `.oel` ByteArray→E4X path runs.
2. **A specific graphic subclass skips field-init** (less likely — char works).

## How to reproduce (fast inner loop, no game rebuild of the SWF)
The recompiled C is persisted; only your `SWFModernRuntime/src/avm2/*.c` changes
rebuild (one TU, ccache). Seed a scratch dir from the teleport build:
```bash
SCRATCH=<scratchpad>/tp
rm -rf $SCRATCH && mkdir -p $SCRATCH/seedling_tp $SCRATCH/cpudump
cp -r ~/CC/seedling_teleport_build/recompiled/* $SCRATCH/seedling_tp/
export AVM2_CPU_DUMP=$SCRATCH/cpudump/tp_ AVM2_MAX_TICKS=60
export SWFRECOMP_OPT_LEVEL=-O0 SWFRECOMP_COMPILE_TIMEOUT=900   # 13MB single TU
python3 ruffle-tests/verify_output.py --test=seedling_tp --tests-dir=$SCRATCH \
    --mode=no-graphics --verbose 2>&1 | grep -iE "uncaught|error"
```
- **CPU dump** writes `tp_NNN.ppm` per tick (GPU-free). Compare to the oracle
  `~/CC/seedling_teleport_build/ruffle_oracle_60/NN.png` (2-digit) — a correct fix
  takes frame 59 from ~98.7% black to the overworld (house/water/trees/path). A
  side-by-side/MAD script pattern is in the s4 scratchpad (`seed_cmp.py`).
- **Instrument the AS3 side**, not just `bd_draw`: the NaN is upstream of the draw.
  Options — env-gated `fprintf` in the recompiled Image.render path is hard (it's
  generated C); better to trace which entity's graphic is 160x160 and dump its
  `scale`/`scaleX`/`origin` and whether the level `.oel` parsed. Consider a
  focused native probe in the AVM2 property-get path, or bisect by checking if the
  `.oel` embedded ByteArray → XML conversion produces a populated level.

## Safeguards (carried from the whole plan)
1. **The game is the INTEGRATION check, never the oracle.** Back any runtime fix
   with an upstream trace/regression test where a family exists (e.g. ByteArray/E4X
   for `.oel`, a field-init regression test if that's the cause). No "looks right
   in Seedling" merges.
2. **Divergence-harness first** — reproduce with a trace test before trusting the
   game. `AVM2_CPU_DUMP` is the deterministic validator; graphics-mode capture is
   NOT reliable locally (lavapipe sub-pixel drift).
3. **GC** (`avm2-stage11-gc`): any new C-static `Avm2Object*` must be rooted; bisect
   with `AVM2_GC=0`.
4. **Conflict boundary:** the fix is likely in `avm2_bytearray.c`/`avm2_e4x.c`/
   `avm2_ops.c` (if `.oel`) or the class/slot init path (if field-init). **Never
   touch `action.c`.** `bd_draw`'s affine path and the Matrix surface are DONE —
   don't re-open them.

## Workflow & bookkeeping
Per-test local runs only (never the full suite locally). Full suite via CI **both
modes** (`avm2_gc=1`), pipeline per `.claude/pipeline-handoff.md` (autonomous
commit/push/CI authorized). Keep the game out of the CI pass-rate metric (no trace
oracle). At end of session update `seedling-teleport-gameplay` + `CURRENT_STATUS.md`
+ plan §2 with the new render baseline (does the world render now? MAD vs the
oracle? what was the NaN source?).

## If the world renders — the next divergences to expect
Once the 160x160 surface composites, driving deeper (raise `AVM2_MAX_TICKS`, or feed
the Stage-8 `input.json` harness to move the character) will surface: `ColorMatrixFilter`
(flash.filters — likely unimplemented), `Emitter` particles, `flash.ui.Keyboard`
constants, more `.oel` streaming. Fix each with a trace/regression test where a
family exists — but render first.
