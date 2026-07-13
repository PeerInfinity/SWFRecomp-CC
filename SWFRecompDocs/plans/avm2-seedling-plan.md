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
- **Stage 8 — input harness + input bridge** — **DONE 2026-07-12**
  (commit `ee2107860`; ~42/71 input.json candidates). verify_output.py
  injects Ruffle's input.json into the AVM2 build; the runtime got
  flash.events MouseEvent/KeyboardEvent/FocusEvent/TextEvent, mouse
  hit-test + 3-phase dispatch, Sprite drag, a focus manager (mouse+Tab
  focus, FocusEvent family, automatic 6y+x + custom tabIndex tab order),
  and TextField editing over the Stage-6 EditText engine. 29 misses
  triaged (masks, Loader, SimpleButton highlight geometry, IME, HTML
  link events, real-shape hit-testing — mostly Stage-9/deferred). Fixed
  a pre-existing MovieClip-missing-Sprite.graphics ordering bug. See
  `avm2/_investigation/CURRENT_STATUS.md` + `avm2-stage8-input` memory.
  Original scope: verify_output.py learns Ruffle's input.json
  event-injection format (the 74 interactive tests, incl. the 16
  text-family ones excluded from Stage 6); the AVM2 runtime gets
  KeyboardEvent/MouseEvent/FocusEvent dispatch from injected (and later
  real) input, Keyboard/Mouse constants, focus interplay. This is also
  the bridge design for real platform input in native/browser builds.
- **Stage 9 — minimal AVM2 render path** — **DONE 2026-07-12** (commit
  `bf93755e0`; 8/9 pure-blit bitmap family). A real render-tree walk over the
  AVM2 display tree feeding the existing WebGPU offscreen backend (which was
  already linked in AVM2 graphics builds but never driven). avm2_display.c gained
  an `#ifdef OFFSCREEN_RENDER` render block: avm2_render_init replicates
  swfStart's renderer setup; avm2_render_frame/finish walk the render_list after
  each tick (world matrix + concat alpha per node), blitting each Bitmap's
  premultiplied-ARGB BitmapData pixels via renderer_draw_bitmap_quad_scaled into
  per-object dynamic xform slots, with swf.c/capture.c-style capture
  (last_frame/iteration/fs_command). avm2_bitmap.c gained BitmapData.draw()'s CPU
  fast path (BitmapData/Bitmap source + normal blend + identity 2x2 -> Ruffle
  copy_on_cpu / blend_and_transform; BitmapData-source Alpha/Erase = Flash
  no-op). Passing: fillrect, clone, copychannel, copypixels, colortransform,
  embedded, sync, pixeldissolve_image. See `avm2/_investigation/
  STAGE9_CANDIDATES.txt` + `avm2-stage9-render` memory. **Deferred to Stage 10+**
  (documented): asset-table zlib compression (the ~46 MB Stage-7 finding — a
  broad recompiler change, tests unaffected, only blocks the real Seedling
  recompile), shape/gradient/text/mask rendering (Graphics records only an AABB),
  and the draw() offscreen-GPU pipeline (DisplayObject sources + alpha/erase
  group blends = the bulk of bitmapdata_draw*). Details below:
  A real render-tree traversal over the AVM2 display tree feeding the
  existing render backend, starting with the Bitmap/BitmapData blit path
  (+ solid-color Graphics fills), OFFSCREEN_RENDER/graphics-mode wiring so
  the bitmapdata image-comparison tests (~20 currently trace-empty
  "passes") become observable. Exit: Seedling-shaped content renders;
  image tests triaged.
- **Stage 10 — audio + timers + saves** — **DONE 2026-07-12**. Timer/TimerEvent
  + getTimer 6/6; flash.media Sound family 12 pass (SoundTransform/SoundChannel/
  SoundMixer/Sound + DisplayObject.soundTransform; trace-graded, no real audio
  output); SharedObject shared_object_no_root pass (getLocal→dynamic data). The
  deferred asset-table zlib compression landed: recompiler DEFLATEs every
  DefineBitsLossless2 RGBA table + runtime inflates on BitmapData construction —
  **Seedling recompile 46 MB → 8.9 MB**, bitmapdata_accuracy bit-exact. A
  Ruffle-faithful µs timer core (one priority list, strict `<`, MIN_INTERVAL/
  MAX_TICKS, fired at tick tail) now backs setTimeout/setInterval AND Timer.
  Deferred: 2 multi-entity SoundMixer-accumulation tests, 3 network-load sound
  tests, the two-run shared_object .sol harness. See
  `avm2/_investigation/CURRENT_STATUS.md` + `STAGE10_CANDIDATES.txt` +
  `avm2-stage10-audio` memory. Original scope:
  flash.media.Sound/SoundChannel/SoundTransform over the existing MP3 backend (88
  embedded sounds in Seedling), flash.utils.Timer/TimerEvent on the
  Stage-6 timer core, SharedObject getLocal/flush over the existing
  AMF engine. Graded by sound*/timer*/shared_object* families.
- **Stage 11 — GC enrollment + perf** — **DONE 2026-07-12**. A self-contained
  AVM2 mark-sweep collector (`SWFModernRuntime/src/avm2/avm2_gc.c` +
  `avm2_gc.h`) — a SEPARATE census from AVM1's ASObject/ASArray. Collection runs
  ONLY between ticks (VM quiescent): `Avm2Activation` holds no operand stack /
  locals — emitted bodies keep those as C locals — so mid-tick collection could
  free a C-stack-only value; the tick-boundary is the sole safe point, where the
  live set == the persistent root graph (so "in-flight activations / scope
  chains" is a non-root by construction). Deterministic 4 MB byte-watermark
  trigger (short trace tests never trigger → byte-identical); `AVM2_GC_STRESS=1`
  (CI input `avm2_gc`) forces collect-every-tick as the correctness gate.
  Marking = precise struct fields + array/vector elems + module ext tracers
  (EventDispatcher listeners, DisplayObject children/frame_scripts/EditText
  stylesheet, StyleSheet entries) + a conservative pointer-scan of every other
  native_ext blob (the missed-edge safety net); class objects/prototypes + XML
  wrappers pinned immortal; per-module `*_gc_free_ext` hooks free the ext blob's
  own sub-allocations (BitmapData pixels, ByteArray bytes, display child arrays,
  listener nodes, style entries) so reclamation is byte-complete, not just
  object-complete. **Soak (N-game methodology):** GC off → live climbs
  770 → 2,000,370 over 5000 ticks; STRESS → dead-flat live=370, 2,000,000 swept;
  ASAN-clean. A code-review workflow caught + fixed two real UAFs pre-commit
  (missing drag roots, StyleSheet entry array not traced). See
  `avm2/_investigation/CURRENT_STATUS.md` + the `avm2-stage11-gc` memory.
  Original scope (for reference): enroll AVM2 allocations in the mark-sweep
  collector, root set = domain globals + display tree + timers + scope chains +
  in-flight activations; then a long-run soak. Do this BEFORE extended play
  testing.
- **Stage 12 — Seedling bring-up** — **IN PROGRESS** (first session
  2026-07-13). The real Seedling.swf recompiles (assets = census: 284/116/88;
  8.9 MB; 0 verify fails) + links + runs in BOTH build modes. Driving it
  headless (divergence-harness-first) revealed the document class is the
  **Newgrounds API v3.1.3 AS3** preloader; the whole missing-class error chain
  is cleared (LoaderInfo #1009 → Security #1065 → flash.net #1065 →
  register-order #1006 → flash.events-net #1065), each backed by an upstream
  trace family where one exists (+5 passes: loaderinfo_properties/root/
  root_allows, sandbox_type_local_file, urlrequest). The preloader now runs
  with zero uncaught errors and its NG API connection times out gracefully
  (no network) — reaching the play-button gate.
  **Session 2 (2026-07-13): the game reaches the FlashPunk Engine loop.**
  Fixed the embedded-image decode gap that threw "Invalid source image" — a
  Flex `[Embed]` image's class chain (`<owner>_<var>` → mx.core.BitmapAsset →
  FlexBitmap → Bitmap) forwards a DEFAULT null bitmapData up `super()`, and the
  native Bitmap ctor cleared bitmapData on the null arg instead of seeding from
  the SymbolClass-bound embedded char (oracle `bitmap_subclass`; also unlocked
  `bitmap_subclass_properties`). Then, driving the recompiled game on the
  **portal auto-start path** (new `GAME_SWF_URL` verify override → armorgames
  URL → NG preloader auto-starts, skipping the play-button gate + API.connect),
  cleared 4 more small flash.* classes (StageDisplayState, LineScaleMode,
  flash.ui.Mouse/MouseCursor). **The recompiled Seedling now runs 30 frames
  headless with ZERO uncaught errors in BOTH modes**, reaching the FlashPunk
  `Engine` game loop + `Splash` world. Graphics mode: the render path executes,
  but the PNG *capture* still hits the WSL2 lavapipe Vulkan OOM (481×481×64
  bitmap-tex array → device lost → buffer-map status 4) — render-infra, blocks
  only the *visual* first-frame diff. **Not yet first-playable:** the visual
  first frame (capture OOM), the file:// play-button click (Stage-8 input.json),
  and driving past the 150-tick Splash into `Game`. Detail in
  `avm2/_investigation/CURRENT_STATUS.md` + the `avm2-stage12-seedling` memory.
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
