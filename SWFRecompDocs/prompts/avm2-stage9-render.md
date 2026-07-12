# Session prompt — AVM2 Stage 9: minimal AVM2 render path

You are implementing **Stage 9** of the AVM2 Seedling-directed plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md`): a real render-tree traversal over
the AVM2 display tree feeding the existing render backend, starting with the
Bitmap/BitmapData blit path (+ solid-color Graphics fills), with
OFFSCREEN_RENDER / graphics-mode wiring so the ~20 currently trace-empty
bitmapdata image-comparison tests become observable.

Read the plan first, then `avm2/_investigation/CURRENT_STATUS.md`, then the
memories `avm2-stage7-bitmapdata` (BitmapData pixel store + the ~46 MB
asset-table finding), `avm2_stage5_display` (display tree + tick),
`avm2-stage8-input`, and `graphics_native_workflow` (per-mode CI result-file
isolation).

Stage 8 landed at (see `git log` for `ee2107860`). CI baseline: **see
CURRENT_STATUS.md** (Stage-8 no-graphics run). Zero regressions expected.

## Goal

Grade by the bitmapdata image-comparison test family (the tests with
`[image_comparisons]` in test.toml that currently "pass" only because they
trace nothing) plus the `--mode=graphics` avm2 run. **Generate the candidate
list at session start** (there is no pre-baked file): the image-comparison
avm2 tests, cross-referenced against the graphics-mode results. Exit: Seedling-
shaped content (Bitmap blit + solid Graphics fill) renders and the image tests
are triaged; a strong majority of the image-gradeable bitmap family passing;
zero pass→fail regressions in no-graphics OR graphics mode.

## Code seams (what exists today)

- `SWFModernRuntime/src/avm2/avm2_display.c` — the AVM2 display tree + the
  5-phase tick. There is NO render pass yet (the runtime is NO_GRAPHICS-only;
  `render_apply_text_bounds` is the only render-phase hook). You need a real
  `avm2_render_tree(ctx)` that walks the depth list, composes world matrices +
  color transforms, and emits draw calls to the backend.
- `SWFModernRuntime/src/avm2/avm2_bitmap.c` — BitmapData holds premultiplied
  ARGB pixels; Bitmap references a BitmapData. The blit path feeds these pixels
  to a GPU texture (or the offscreen framebuffer).
- The render backend + offscreen Dawn wiring: `SWFModernRuntime/src/libswf/
  swf.c` (graphics-mode main loop), `src/libswf/capture.c`,
  `src/rendering/render_webgpu.c`. verify_output's `--mode=graphics` compiles
  these (see compile_native's `mode == "graphics"` branch) with
  `-DOFFSCREEN_RENDER`. The AVM1 path renders via the tag/DisplayObject system;
  AVM2 needs its OWN render walk feeding the same backend primitives.
- `ruffle-tests/verify_output.py` — `parse_image_comparisons` +
  `CAPTURE_TRIGGERS` env drive the PNG capture + outlier comparison. The AVM2
  build must honor the same capture triggers (fs_command / last_frame /
  specific_iteration).

## Prerequisite (from the Stage-7 finding)

Recompiling the real Seedling.swf emits a **~46 MB** RecompiledABC/abc_timeline.c
(284 raw straight-RGBA DefineBitsLossless2 tables). BEFORE wiring the Seedling
render path, emit **zlib-recompressed** blobs from the recompiler and inflate at
runtime (zlib is already linked for ByteArray.compress) — otherwise the Seedling
build's compile time / binary size will dominate. Tests are unaffected (tiny
bitmaps), so this can be a parallel recompiler change graded by a Seedling
recompile smoke, not a test.

## Suggested tranche order

1. **Render walk skeleton**: `avm2_render_tree` over the depth list; world
   matrix + concatenated color transform per node; solid-color Graphics fills
   (drawRect/beginFill) to the backend. Prove one solid-fill test renders.
2. **Bitmap blit**: BitmapData pixels → texture → quad at the Bitmap's world
   matrix. Wire the bitmapdata image-comparison tests (turn trace-empty passes
   into real image checks). Honor smoothing/pixelSnapping where traced.
3. **Graphics-mode wiring**: OFFSCREEN_RENDER + capture triggers for the AVM2
   build; per-mode result-file isolation (see `graphics_native_workflow`).
4. **draw() blend pipeline**: the Stage-7 straggler `draw_alpha_erase` needs
   the BitmapData.draw() source-over/erase blend (Ruffle operations.rs).
5. **Asset-table compression**: zlib-recompress the recompiler's bitmap blobs;
   Seedling recompile smoke.
6. Triage the misses; write STAGE9_CANDIDATES.txt; record the CI baseline
   (BOTH modes — graphics for the image tests, no-graphics for regressions).

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI (CLAUDE.md).
  Full pipeline per `.claude/pipeline-handoff.md`; run **both** modes (this
  touches shared render code) and confirm zero pass→fail across ALL suites +
  wasm-link-smoke green.
- Conflict boundary: own `SWFRecomp/src/abc/`, `SWFModernRuntime/{src,include}/
  avm2/`, `RecompiledABC/`, and the new AVM2 render-walk. Coordinate on
  `src/rendering/` + `src/libswf/swf.c` (shared with AVM1 graphics) — additive
  hooks only; never change AVM1 render behavior.
- Local Dawn install required at `~/CC/dawn-install` (or `DAWN_INSTALL` env).
- Do NOT run the full avm2 suite locally. Single graphics tests:
  `python3 ruffle-tests/verify_output.py --test=NAME --mode=graphics
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`.
- Honest-failure property everywhere.

## Gotchas carried from earlier stages

- REBUILD the recompiler after any SWFRecomp change (`cd SWFRecomp/build &&
  make -j8`); verify_output only rebuilds the runtime side.
- BitmapData pixels are PREMULTIPLIED ARGB (0xAARRGGBB); the blit must
  un-premultiply or use a premultiplied-alpha blend to match FP exactly
  (bitmapdata_accuracy is the oracle).
- graphics-mode SIGABRT-after-correct-output = a real heap bug
  (`graphics-sigabrt-real-heap-bugs`); WebGPU texture-array layer limit → blank
  render (`webgpu-texture-array-layer-limit-blank-render`).
- The AVM2 tick already runs the display lifecycle; the render pass is a NEW
  phase after PHASE_IDLE, reading the SAME depth list — do not duplicate the
  timeline/goto logic.

## End-of-session bookkeeping

- Stage-9 landing note in `avm2-seedling-plan.md` §2.
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline BOTH modes).
- New `avm2-stage9-render` memory; update `seedling-avm2-readiness` progress.
- If complete, mark this prompt COMPLETE and draft the Stage-10 prompt (audio +
  timers + saves).
