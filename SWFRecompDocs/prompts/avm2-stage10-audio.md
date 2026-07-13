# Session prompt — AVM2 Stage 10: audio + timers + saves (+ deferred asset compression)

You are implementing **Stage 10** of the AVM2 Seedling-directed plan
(`SWFRecompDocs/plans/avm2-seedling-plan.md`): flash.media.Sound /
SoundChannel / SoundTransform over the existing MP3 backend, flash.utils.Timer /
TimerEvent on the Stage-6 timer core, and SharedObject getLocal/flush over the
existing AMF engine. Plus the **asset-table zlib compression** deferred from
Stage 9 (the ~46 MB Seedling recompile finding).

Read the plan first, then `avm2/_investigation/CURRENT_STATUS.md`, then the
memories `avm2-stage9-render` (render path + the deferred-compression rationale),
`avm2-stage7-bitmapdata` (embedded-asset pipeline + DefineSound/DefineBinaryData
tables + the ~46 MB finding), `avm2_stage5_display` (tick + broadcast model),
`avm2-stage6-text` (timer core: flash.utils setTimeout/setInterval already
exist), and `seedling-avm2-readiness` (88 embedded sounds; Sound/SoundChannel/
SoundTransform/Timer/SharedObject/ByteArray usage census).

Stage 9 landed at commit `bf93755e0`. CI baseline: **see CURRENT_STATUS.md**
(both modes; avm2 823 effective). Zero regressions expected.

## Goal

Grade by the upstream sound* (~17), timer* (~6), and shared_object* (~2) trace
test families plus the full CI zero-regression gate. **Generate the candidate
list at session start** (no pre-baked file): the sound*/timer*/shared_object*
avm2 tests. Exit: a strong majority of each family passing; the deferred
asset-table compression landed + graded by a Seedling recompile smoke; zero
pass→fail regressions in no-graphics OR graphics mode.

## Suggested tranche order

1. **flash.utils.Timer / TimerEvent** — smallest, and the Stage-6 timer core
   (`SWFModernRuntime/src/actionmodern/timer.c` + the avm2 setTimeout/setInterval
   in avm2_text.c) already exists; wrap it in the AS3 Timer class (start/stop/
   reset, delay/repeatCount/currentCount, timer/timerComplete TimerEvent
   dispatch through the Stage-5 EventDispatcher). run_due_timers already runs at
   the head of avm2_display_run_tick.
2. **flash.media.Sound / SoundChannel / SoundTransform** over the existing MP3
   backend (`SWFModernRuntime/src/audio/`). The recompiler already emits
   `avm2_generated_sounds` (DefineSound metadata, Stage 7); wire DefineSound
   payloads + SymbolClass-bound Sound subclasses. Grade by the sound* family
   (mostly trace: volume/pan/position/length, not actual audio output).
3. **SharedObject.getLocal / flush / data** over the existing AMF engine
   (avm2_amf.c). Persist to a per-test .sol path the harness can seed/inspect.
4. **Asset-table zlib compression (deferred from Stage 9)**: the recompiler
   (`SWFRecomp/src/abc/abc_timeline.cpp`) emits raw straight-RGBA
   DefineBitsLossless2 tables — ~46 MB for Seedling. zlib-recompress the blobs at
   RECOMPILE time and inflate at runtime (zlib is already linked for
   ByteArray.compress). Tests are unaffected (tiny bitmaps), so grade by a
   Seedling recompile smoke (recompile succeeds + the emitted C shrinks
   dramatically), NOT a trace test. REBUILD the recompiler after the change
   (`cd SWFRecomp/build && make -j8`). Watch for a broad avm2 regression — every
   avm2 test's bitmap tables change format, so run BOTH CI modes.
5. Triage the misses; write STAGE10_CANDIDATES.txt; record the CI baseline (BOTH
   modes).

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI (CLAUDE.md).
  Full pipeline per `.claude/pipeline-handoff.md`; run **both** modes if the
  asset-compression change lands (it touches shared recompiler output); otherwise
  no-graphics is enough for audio/timer/saves (they emit no pixels). Confirm zero
  pass→fail across ALL suites + wasm-link-smoke green.
- Conflict boundary: own `SWFRecomp/src/abc/`, `SWFModernRuntime/{src,include}/
  avm2/`, `RecompiledABC/`. Coordinate on `src/audio/` (shared with AVM1) —
  additive AVM2 hooks only; never change AVM1 audio behavior.
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`.
- Honest-failure property everywhere.

## Gotchas carried from earlier stages

- REBUILD the recompiler after any SWFRecomp change; verify_output only rebuilds
  the runtime side.
- Timer/broadcast: listeners registered during a broadcast wait for the next one
  (length-snapshotted iteration); TimerEvent dispatch goes through the real
  Stage-5 EventDispatcher (priority buckets, 3-phase).
- Determinism: Math.random / Date are seeded via MOCK_DATE_TIME (see CLAUDE.md);
  Timer delays are wall-clock in Flash but the harness runs a fixed tick count —
  match Ruffle's tick-driven timer model, not real time.

## End-of-session bookkeeping

- Stage-10 landing note in `avm2-seedling-plan.md` §2.
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline).
- New `avm2-stage10-audio` memory; update `seedling-avm2-readiness` progress
  (items 4-6 + the asset-compression note).
- If complete, mark this prompt COMPLETE and draft the Stage-11 prompt (GC
  enrollment + perf soak).
