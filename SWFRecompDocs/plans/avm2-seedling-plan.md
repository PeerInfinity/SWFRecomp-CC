# AVM2 Phase 2 — Seedling-directed plan

Draft v1, 2026-07-12. Successor to the phase-1 trace-parity plan
(`avm2-support-plan.md`, Stages 0–6 all DONE). Phase 2 re-orders the
remaining work around the first real AS3 game target: **Seedling**
(FlashPunk, SWF10, 480x480 @30fps), with the Archipelago-injected
variant (`Seedling_injected.swf`) as the eventual endgame.

## 1. Why this ordering (and what it keeps from phase 1)

The 2026-07-12 census (memory `seedling-avm2-readiness`) showed:

- **Language: already 100% covered.** Seedling's ABC (2 DoABC tags,
  3,607 bodies) parses + verifies clean and uses zero unimplemented
  opcodes against the Stage-6 op surface.
- Its weight is all in **infrastructure we haven't started**: 284
  DefineBitsLossless2 bitmaps + 116 DefineBinaryData + 88 DefineSound
  behind 491 SymbolClass bindings ([Embed] assets), the FlashPunk
  BitmapData blit kit (copyPixels/fillRect/setPixel32/getPixel32/
  colorTransform/lock/unlock/draw/applyFilter/hitTest), keyboard+mouse
  input, Sound playback, Timer, SharedObject saves.

Crucially, each of those features is itself a large upstream test
family (bitmapdata* 43, mouse* 29, sound* 17, timer* 6, shared_object
2; 74 tests ship input.json). So phase 2 is NOT a departure from the
test-first playbook — it is the same playbook with the stage order
chosen by Seedling's dependency graph instead of by family size.

**Non-negotiable safeguards carried over from phase 1** (these are the
answer to "what could go wrong with game-first development"):

1. Every stage is graded by its upstream trace-test family + the full
   CI zero-regression gate — the game is the integration check, never
   the oracle. No "looks right in Seedling" merges.
2. The game itself is only opened for debugging AFTER its supporting
   stages are test-green (the AVM1 lesson: divergence-hunting on
   half-built foundations multiplies unknowns).
3. The minimal render path is designed as the FIRST CONSUMER of the
   real AVM2 render-tree walk, not a special-cased hack (it must grow
   into shapes/text/filters later).
4. GC enrollment is an explicit stage. AVM2 allocations are currently
   census-invisible/immortal (a deliberate Stage-2 simplification) —
   fine for tests that run seconds, unbounded growth for a 30fps
   blitting game. This is the one mandatory item that is invisible in
   any feature census.

## 2. Stages

- **Stage 7 — embedded assets + BitmapData/Bitmap (trace-level)** — **DONE
  2026-07-12** (28/31 candidates; exit met). Recompiler decodes
  DefineBitsLossless/2 to RGBA tables + emits DefineBinaryData/DefineSound
  tables (+ a PlaceObject3 className parse fix); runtime `avm2_bitmap.c`
  implements BitmapData (full operation kit, premultiply-exact) + Bitmap +
  SymbolClass/timeline construction. 3 triaged misses: draw() blend
  (Stage 9), Loader (deferred), pixelsnapping (upstream-ignored). Seedling
  smoke: 284 bitmaps/116 binaries/88 sounds emit, ~46 MB raw RGBA (compress
  before Stage 9). See `avm2/_investigation/CURRENT_STATUS.md` +
  `avm2-stage7-bitmapdata` memory. Details below:
  Recompiler: decode DefineBitsLossless/2 to ARGB pixel tables, emit
  DefineBinaryData bytes, register both (and DefineSound metadata) as
  character kinds; runtime: flash.display.BitmapData (pixel store +
  the full operation kit, ported from Ruffle
  core/src/bitmap/operations.rs) and Bitmap, with SymbolClass-bound
  subclasses constructing their asset (the existing font/sprite
  binding mechanism), DefineBinaryData -> ByteArray subclasses.
  Graded by: 31 trace-gradeable bitmap candidates
  (`avm2/_investigation/STAGE7_CANDIDATES.txt`). Exit: >=22 of 31 +
  zero regressions. Session prompt:
  `SWFRecompDocs/prompts/avm2-stage7-bitmapdata.md`.
- **Stage 8 — input harness + input bridge**. verify_output.py learns
  Ruffle's input.json event-injection format (the 74 interactive
  tests, incl. the 16 text-family ones excluded from Stage 6); the
  AVM2 runtime gets KeyboardEvent/MouseEvent/FocusEvent dispatch from
  injected (and later real) input, Keyboard/Mouse constants, focus
  interplay. Graded by: the input.json test family (candidate list to
  be generated at session start). This is also the bridge design for
  real platform input in native/browser builds.
- **Stage 9 — minimal AVM2 render path**. A real render-tree traversal
  over the AVM2 display tree feeding the existing render backend,
  starting with the Bitmap/BitmapData blit path (+ solid-color
  Graphics fills), OFFSCREEN_RENDER/graphics-mode wiring so the
  bitmapdata image-comparison tests (~20 currently trace-empty
  "passes") become observable. Exit: Seedling-shaped content renders;
  image tests triaged.
- **Stage 10 — audio + timers + saves**. flash.media.Sound/
  SoundChannel/SoundTransform over the existing MP3 backend (88
  embedded sounds in Seedling), flash.utils.Timer/TimerEvent on the
  Stage-6 timer core, SharedObject getLocal/flush over the existing
  AMF engine. Graded by sound*/timer*/shared_object* families.
- **Stage 11 — GC enrollment + perf**. Enroll AVM2 allocations in the
  object.c mark-sweep collector (g_avm2_gc_mark_roots is already
  registered; Stage-2 TODO), root set = domain globals + display tree
  + timers + scope chains + in-flight activations; then a long-run
  soak (N-game methodology). Do this BEFORE extended play testing.
- **Stage 12 — Seedling bring-up**. Recompile the real SWF, drive with
  the divergence-harness workflow (`wasm-game-debugging` memory).
  Post-baseline: AVM2 `Rando` counterpart for the injected variant.

Deferred (phase-1 leftovers, none Seedling-blocking):
flash.text.engine TextBlock/TextLine family (7 tests), Loader/
LoaderInfo (needed by 2 font tests + some bitmap/loader tests),
device-font TTF metric parity (1 test).

## 3. Verification & workflow

Unchanged from phase 1: per-test local runs only, full suite via CI
(`no-graphics` until Stage 9, then both modes), pipeline per
`.claude/pipeline-handoff.md`, honest-failure property everywhere.
Conflict boundary unchanged (own `src/avm2/`, `SWFRecomp/src/abc/`,
`RecompiledABC/`; never touch `action.c`).
