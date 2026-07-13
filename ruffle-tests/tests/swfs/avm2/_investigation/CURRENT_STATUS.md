# avm2 Suite — Current Status

Last updated: 2026-07-13 — Stage 12 (Seedling bring-up) IN PROGRESS; Stage 11
(GC enrollment + perf soak) COMPLETE; Stage 10 (audio + timers + saves + asset
compression), Stage 9 (minimal AVM2 render path), Stage 8 (input harness +
input→event bridge), Stage 7 (embedded assets + BitmapData/Bitmap), Stage 6
(TextField/EditText engine), Stage 5, E4X and Stage 4 before it.

## State (Stage 12 — Seedling bring-up, first session 2026-07-13)

- **The real Seedling.swf recompiles + links + runs — both build modes.** The
  recompiler emits exactly the census counts (284 DefineBitsLossless2 bitmaps,
  116 DefineBinaryData, 88 DefineSound; abc_timeline.c 8.9 MB compressed, 0
  verify failures over 3,607 bodies). Native no-graphics AND graphics (Dawn
  offscreen) both link and run without crashing.
- **Divergence-harness workflow (headless-first): the entire Newgrounds-API
  preloader error chain is cleared.** Seedling's document class is the
  **Newgrounds API v3.1.3 AS3** preloader (NG ads/medals wrapper around the
  FlashPunk `Main`). Running the recompiled game headless surfaced a chain of
  missing-class / null-access divergences, each fixed and (where an upstream
  family exists) backed by a trace test:
  1. `loaderInfo.url` → **#1009** (loaderInfo returned null). Implemented
     **flash.display.LoaderInfo** (root-movie singleton: shared across all
     on-stage objects, null off-stage; `content`=root; bytesLoaded/Total=on-disk
     size; url/contentType/actionScriptVersion/frameRate/width/height/swfVersion/
     parameters/applicationDomain/loader/childAllowsParent/parentAllowsChild/
     sameDomain). **+3 tests: loaderinfo_properties, loaderinfo_root,
     loaderinfo_root_allows.** Added `-DSWF_ONDISK_SIZE` to verify_output (the
     root LoaderInfo reports the compressed download size, not SWF_FILE_SIZE's
     uncompressed header size).
  2. **#1065 Security** → implemented **flash.system.Security** (sandboxType
     "localWithFile", allowDomain/allowInsecureDomain/loadPolicyFile no-ops,
     sandbox-type constants). **+1 test: sandbox_type_local_file.**
  3. **#1065 URLVariables** → implemented the **flash.net URL stack**
     (URLRequest with #2008 method validation, URLVariables, URLRequestMethod,
     URLLoaderDataFormat, URLRequestHeader, URLLoader [EventDispatcher;
     load()=no-op, no network layer], navigateToURL/sendToURL). **+1 test:
     urlrequest.**
  4. **#1006 addEventListener on URLLoader** → registration-order bug:
     `register_net` ran before `avm2_register_events`, so URLLoader was created
     when `event_dispatcher_class` was still NULL (builtin classes snapshot the
     parent vtable at creation). Moved `register_net` after events.
  5. **#1065 ProgressEvent** → implemented the **flash.events network family**
     (ProgressEvent, ErrorEvent, IOErrorEvent, SecurityErrorEvent,
     AsyncErrorEvent, HTTPStatusEvent, StatusEvent) with static type constants.
     No upstream trace family — game-driven stubs.
- **Result:** Seedling now runs the NG preloader **with zero uncaught errors**;
  at ~3000 ticks the NG API connection **times out gracefully** ("Unable to
  connect to the API" — correct headless behaviour, there is no network). The
  preloader then reaches its **play-button gate** (the `onPlayClick` /
  `onMouseDown` handlers in the abc dump): starting the FlashPunk `Main` needs
  an injected mouse click — the next session's work (input.json harness, then
  first render).
- **Known gaps found (next session):** (a) reach `Main` via injected play-button
  click; (b) graphics-mode capture hits `render_webgpu_save_png: buffer map
  failed (status 4)` / lavapipe `VK_ERROR_OUT_OF_DEVICE_MEMORY` under WSL2 — a
  render-infra issue, separate from game logic (headless no-graphics path is
  clean); (c) URLLoader.load never dispatches COMPLETE/IO_ERROR (no network) —
  a faithful async IOError would let API-gated preloaders fall through without
  waiting for the timeout Timer.
- **The game is the INTEGRATION check, never the oracle:** every fix above is
  graded by its upstream trace family (5 new passes) except the flash.events
  network stubs (no upstream family) and the flash.net load()/navigator paths
  (need Ruffle's navigator mock — url_loader/net_navigateToURL stay deferred).

## State (Stage 11)

- **Stage 11 COMPLETE (2026-07-12): AVM2 mark-sweep garbage collector.**
  Before Stage 11 every `avm2_object_alloc`'d object was immortal (a deliberate
  Stage-2 simplification — fine for MAX_FRAMES-bounded trace tests, unbounded
  growth for a 30fps blitting game like Seedling). Now a real root-traced
  mark-sweep collector reclaims per-frame garbage. New files
  `SWFModernRuntime/src/avm2/avm2_gc.c` + `include/avm2/avm2_gc.h`; full design +
  gotchas in the `avm2-stage11-gc` memory. Key design:
  - **Collect only between ticks (VM quiescent).** `Avm2Activation` holds no
    operand stack / locals (emitted bodies keep those as C locals), so the only
    safe collection point is the top of the runSWF_avm2 tick loop, where the
    live set == the persistent root graph. Separate census (`g_gc_head`) from
    AVM1's ASObject/ASArray lists.
  - **Deterministic byte-watermark trigger** (default 4 MB). Short trace tests
    allocate << 4 MB → GC never triggers → trace output byte-identical.
    `AVM2_GC_STRESS=1` forces collect-every-tick (CI correctness gate, workflow
    input `avm2_gc`); `AVM2_GC=0` disables.
  - **Marking:** precise struct fields (proto/slots/dyn_props/bound_methods/
    fn_*/class_ref) + array/vector elems + module ext tracers (EventDispatcher
    listeners, DisplayObject children/frame_scripts/EditText stylesheet) +
    **conservative pointer-scan of every other native_ext blob** (the
    missed-edge safety net — can only over-retain, never free a live object).
    Class objects/prototypes + XML wrappers pinned immortal.
  - **Soak evidence** (`AVM2_GC_SOAK=<ticks>`, synthetic per-frame garbage on
    the real context): GC OFF → live climbs 770 → 2,000,370 over 5000 ticks
    (611 MB, 0 freed); GC ON (4 MB) → bounded sawtooth ~370–11.5k (1,990,400
    reclaimed); STRESS → **dead-flat live=370 across 5000 collections, 2,000,000
    objects swept**. ASAN stress soak (1500 collections) zero AddressSanitizer
    errors.
  - **CI baseline (sha `b5695059b`, avm2_gc=1 STRESS = collect every tick):**
    - **no-graphics (run 29224963308): avm2 819 / 1,204 (68.0%)** — zero
      pass→fail vs the pre-Stage-11 baseline (8c4e8518e, 819). avm1 (634),
      from_gnash, from_shumway (73), regression (41) all "No changes detected";
      wasm-link-smoke green. The GC collecting on EVERY tick produces
      byte-identical trace output across all 1,204 avm2 tests + every AVM1 suite
      — the full marking-correctness gate.
    - **graphics (run 29224968114, avm2_gc=1): avm2 819 / 1,204 (68.0%)** —
      identical to no-graphics; supercall_two_classobjects segfault→2/2, all 10
      fixed, zero newly-failing across all suites; wasm-link-smoke green. GC is
      mode-independent (render reads the same tree), confirmed byte-identical in
      both build modes under collect-every-tick.
    - **The stress run FOUND two real marking bugs in the first pass** (10 avm2
      failures at sha b4db40f98), both fixed in b5695059b: class-scope capture
      of live instances (supercall_two_classobjects segfault) + uninitialized
      Avm2DynProp.key_obj/dead exposed by GC memory reuse (scene/label/callee
      cluster read null). The default 4 MB watermark keeps the trace suite
      GC-inert (byte-identical) regardless.


## State (Stage 10)

- **Stage 10 COMPLETE (2026-07-12): audio + timers + saves + the deferred
  asset-table compression.** Graded families (local single-test runs;
  `_investigation/STAGE10_CANDIDATES.txt`):
  - **flash.utils.Timer / TimerEvent + getTimer — 6/6** (timer, timer_events,
    timer_finished, timer_reset, timer_setdelay, get_timer).
  - **flash.media Sound family — 12 pass** (soundtransform, soundmixer_buffertime,
    soundmixer_stopall, soundchannel_soundtransform{,_exists}, soundchannel_stop,
    sound_valueof, sound_embeddedprops, sound_play, movieclip_soundtransform).
    2 deferred (soundmixer_soundtransform / simplebutton_soundtransform: multi-
    entity SoundMixer accumulation + timeline-child transform persistence), 3
    network-load-deferred (sound_rootless / sound_constructor_with_args /
    sound_load_multiple), 2 upstream known_failure (soundchannel_position /
    _soundcomplete).
  - **flash.net.SharedObject — shared_object_no_root pass** (getLocal → dynamic
    `data` Object); shared_object deferred (two-run .sol harness + AMF byte-exact
    size, unsupported by verify_output).
  - **Asset-table zlib compression** (the Stage-7 ~46 MB finding): the recompiler
    now zlib-DEFLATEs each DefineBitsLossless2 RGBA table (level 9); the runtime
    inflates on BitmapData construction. **Seedling recompile 46 MB → 8.9 MB**
    (~80% smaller), exit 0; bitmapdata_accuracy still bit-exact. Also added a
    DefineSound `data_size` field (bytesTotal) to the recompiler tables.
  - What landed: new `SWFModernRuntime/src/avm2/avm2_media.c` (Sound/SoundChannel/
    SoundTransform/SoundMixer); the Timer class + a Ruffle-faithful µs timer core
    (one priority list, strict `tick_time < cur_time`, MIN_INTERVAL/MAX_TICKS,
    fired at the TAIL of the tick like Ruffle's run_frame→update_timers) in
    avm2_display.c; TimerEvent in avm2_events.c; DisplayObject.soundTransform in
    avm2_display.c; SharedObject in avm2_amf.c; DefineSound `data_size` +
    zlib-compressed bitmap tables in `SWFRecomp/src/abc/abc_timeline.cpp` +
    runtime inflate in avm2_bitmap.c; `getTimer`. verify_output.py adds
    avm2_media.c to the AVM2 source set.
  - **CI baseline BOTH modes (sha `8c4e8518e`):**
    - **no-graphics (run 29219023622): avm2 819 / 1,204 (68.0%)** — **+18** over
      Stage 9's 801 (all 18 Stage-10 candidates + `agal_compiler` bystander).
    - **graphics (run 29219031270): avm2 819 / 1,204 (68.0%)** — identical +18,
      confirming the zlib-compressed bitmap tables render bit-identically.
    - `soundchannel_position` + `soundchannel_soundcomplete` moved
      output_mismatch → **ruffle_matched** (effective pass). `soundmixer_
      soundtransform` (888/900) + `simplebutton_soundtransform` (829/887)
      improved but not fully passing (multi-entity accumulation gap).
    - **ZERO pass→fail regressions in EITHER mode across ALL suites** (avm1 634,
      from_shumway 73, from_gnash sub-suites, regression 41 all unchanged);
      wasm-link-smoke green in both runs.


## State (Stage 9)

- **Stage 9 COMPLETE (2026-07-12, commit `bf93755e0`): minimal AVM2 render
  path — 8/9 pure-blit bitmap family pass** under `--mode=graphics`
  (`_investigation/STAGE9_CANDIDATES.txt`). A real render-tree walk over the
  AVM2 display tree feeding the existing WebGPU offscreen backend (which was
  already linked in AVM2 graphics builds but never driven). What landed:
  - `SWFModernRuntime/src/avm2/avm2_display.c` — a new `#ifdef OFFSCREEN_RENDER`
    render block. `avm2_render_init` replicates swfStart's renderer setup
    (renderer_new/init, stage_to_ndc, stage bg from g_stage_color, dynamic-bitmap
    layer sizing, capture triggers) for the AVM2 entry. `avm2_render_frame`/
    `avm2_render_finish` run a depth-ordered render-list walk after each tick (a
    NEW pass reading the SAME list the tick built — no timeline/goto re-run),
    composing world matrix + concatenated alpha per node and blitting each
    Bitmap's premultiplied-ARGB BitmapData pixels via
    `renderer_draw_bitmap_quad_scaled` into a per-object dynamic xform slot.
    Capture mirrors swf.c/capture.c (last_frame/iteration/fs_command).
  - `SWFModernRuntime/src/avm2/avm2_main.c` — drives render_init before the tick
    loop, render_frame after each tick, render_finish at the end, all gated on
    OFFSCREEN_RENDER (NO_GRAPHICS builds compile none of it).
  - `SWFModernRuntime/src/avm2/avm2_bitmap.c` — BitmapData.draw()'s CPU fast path
    ported from Ruffle operations.rs (BitmapData/Bitmap source + normal blend +
    identity 2x2 matrix -> copy_on_cpu / blend_and_transform; BitmapData-source
    Alpha/Erase = documented Flash no-op). DisplayObject sources / impactful
    blends / scaled matrices still need the offscreen GPU pipeline (Stage 10+).
  - Passing (graphics): bitmapdata_fillrect, _clone, _copychannel, _copypixels,
    _colortransform, _embedded, _sync, _pixeldissolve_image. Miss:
    bitmap_subclass_properties (a pre-existing embedded-subclass trace abort,
    fails identically in no-graphics — NOT a render bug).
  - **DEFERRED to Stage 10+** (documented): asset-table zlib compression (the
    ~46 MB Stage-7 finding — orthogonal to Stage-9 grading, tests use tiny
    bitmaps; a broad recompiler change better done in the asset/audio session;
    only blocks the real Seedling recompile), shape/gradient/text/mask rendering
    (Graphics records only an AABB), and the draw() offscreen-GPU pipeline (the
    bulk of the bitmapdata_draw* family).
  - **CI baseline BOTH modes (sha `bf93755e0`):**
    - **no-graphics (run 29216031666): avm2 801 / 1,204 + 22 RM = 823 effective
      (68.4%)** — IDENTICAL to Stage 8's 823 (the render + draw() additions are
      no-graphics-inert / net-zero); no-graphics diff "No changes detected".
    - **graphics (run 29216038323): avm2 801 / 1,204 + 22 RM = 823 effective
      (66.5% raw pass), +793 over the previously-broken graphics baseline (8)**
      — this is the first real avm2 graphics baseline; the image tests now
      render. Zero graphics regressions (vs trace AND vs previous graphics).
  - **ZERO pass→fail regressions in EITHER mode across ALL suites** (avm1,
    from_gnash all sub-suites, from_shumway, regression all "No changes
    detected" in both modes); wasm-link-smoke green.

## State (Stage 8)

- **Stage 8 COMPLETE (2026-07-12, commit `ee2107860`): ~42/71 input.json
  candidates pass locally** (`_investigation/STAGE8_CANDIDATES.txt`; up from 0
  — the AVM2 runtime ignored input.json entirely before this). The ~29 misses
  are triaged there and cluster on features outside the input bridge: mask
  hit-testing, flash.display.Loader (deferred), SimpleButton highlight_bounds
  geometry + arrow navigation, IME, HTML link events, real-shape hit-testing.
  What landed:
  - `ruffle-tests/verify_output.py` — input.json injection wired to the AVM2
    build; `KEY_DOWN` now carries keyCode/charCode/keyLocation, `MOUSE_DOWN`
    the double-click index, `SET_CLIPBOARD_TEXT` escapes embedded newlines.
  - `SWFModernRuntime/src/avm2/avm2_events.c` — flash.events MouseEvent /
    KeyboardEvent / FocusEvent / TextEvent (subclass ctors, getters, toString
    overrides via in-place vtable replace).
  - `SWFModernRuntime/src/avm2/avm2_display.c` — the input section: parser +
    per-WAIT-tick pump, mouse hit-test (Ruffle mouse_pick_avm2 AABB) + 3-phase
    dispatch (down/up/click/middle/right/rollOver/rollOut/mouseMove/wheel with
    mouseEnabled/mouseChildren gating), Sprite.startDrag/stopDrag/dropTarget,
    keyboard→stage.focus dispatch, the focus manager (mouse+Tab focus, focusIn/
    Out/keyFocusChange/mouseFocusChange, automatic 6y+x tab order + custom
    tabIndex order, is_tabbable/tab_enabled per type, buttonMode/useHandCursor).
    Also fixed a pre-existing bug — MovieClip did not inherit Sprite.graphics
    (getter registered after MovieClip was derived), which crashed every input
    test that drew via `this.graphics.beginFill`.
  - `SWFModernRuntime/src/avm2/avm2_text.c` — TextField editing bridge over the
    Stage-6 EditText engine: text_input (typed + pasted, newline/control
    filter, textInput event, restrict, maxChars, change), text controls
    (move/select/backspace/delete/cut/copy/paste), EditTextRestrict.
  - **CI baseline (no-graphics, run 29213200637, sha `ee2107860`): avm2 800 /
    1,204 passing + 22 ruffle_matched = 822 effective (68.3%)** — +47 over
    Stage-7's 775 (the input harness + the MovieClip.graphics fix unlocked
    bystanders well beyond the 71 candidates). avm1 (634/706+RM), gnash,
    shumway (73/92+RM), regression (41/41) all unchanged; wasm-link-smoke
    green. **One pass→fail regression** — `edittext_autosize_lazy_bounds_
    interactions` (re-focusing the already-focused TextField stopped applying
    pending autosize bounds because the new `set_focus` early-returns on an
    unchanged focus) — **fixed in commit `003b12c89`** (stage.focus applies
    pending bounds unconditionally, like the old setter; set_focus then only
    fires focusIn/Out when the focus actually changes).
  - **Confirmation run 29213827286 (sha `003b12c89`): avm2 801 / 1,204 + 22 RM
    = 823 effective (68.4%), ZERO pass→fail regressions in avm2 or ANY AVM1
    suite** (edittext_autosize_lazy_bounds_interactions newly passing again),
    wasm-link-smoke green. Net Stage-8 gain: **+48 effective** over Stage 7.


## State (Stage 7)

- **Stage 7 COMPLETE (2026-07-12): 28/31 Stage-7 candidates pass locally**
  (`_investigation/STAGE7_CANDIDATES.txt`; exit >=22 met). The 3 misses are
  triaged there: draw_alpha_erase (needs the Stage-9 draw() blend pipeline),
  loader_bitmap_transparency (needs Loader + JPEG/PNG decoders — deferred),
  bitmap_pixelsnapping (upstream `ignore = true`). What landed:
  - `SWFRecomp/src/abc/abc_timeline.cpp` — decode DefineBitsLossless/2 to
    straight-RGBA pixel tables at RECOMPILE time (zlib inflate + 8-bit
    palettized / 15-bit / 32-bit swizzle, ported from Ruffle
    render/utils.rs); emit `avm2_generated_bitmaps` + `avm2_generated_binaries`
    (DefineBinaryData) + `avm2_generated_sounds` (DefineSound metadata). Also
    fixed a PlaceObject3 className bug (the SWF19-spec `HasImage && HasChar`
    wording is wrong — Ruffle uses `HasImage && !HasChar`; the old code
    mis-parsed the char id of every image placed by id, e.g. timeline
    Bitmaps).
  - `SWFModernRuntime/src/avm2/avm2_bitmap.c` (new, ~1.1K lines) —
    flash.display.BitmapData (premultiplied ARGB pixel store, exact Flash
    un-premultiply table, ctor validation with the version-gated
    is_size_valid, get/setPixel(32), fillRect, clone, dispose, noise,
    get/setPixels + copyPixelsToByteArray, get/setVector, copyPixels (+alpha
    source + blend_over), floodFill, threshold, hitTest, histogram,
    pixelDissolve (Feistel permutation), colorTransform, copyChannel, scroll,
    getColorBoundsRect; SymbolClass-bound subclass construction from the
    embedded asset) and flash.display.Bitmap (bitmapData/pixelSnapping/
    smoothing, cached-dims self bounds, timeline placement seeding).
  - `avm2_display.c` — BITMAP chars instantiate as Bitmap display objects;
    a BitmapData-subclass-bound bitmap char seeds a plain Bitmap whose
    bitmapData is that subclass (ctor run with 1,1). Bitmap self bounds hook.
  - `avm2_globals.c` — flash.geom.Point.toString ("(x=, y=)").
  - Seedling smoke: recompiling the real SWF emits 284 bitmaps + 116 binaries
    + 88 sounds (matches the census); generated abc_timeline.c is ~46 MB of
    raw RGBA — compresses well, revisit before Stage 9 (see memory).
  - **CI baseline (run 29209081975, 2026-07-12): 754 / 1,204 passing + 21
    ruffle_matched = 775 effective (62.6%)** — +27 over Stage 6's 748, in
    avm1 (634/706, unchanged), gnash/shumway (73/92, unchanged), regression
    (41/41, unchanged); wasm-link-smoke green. 28 newly passing (all Stage-7
    bitmap candidates). The single avm2 "newly failing" is a PHANTOM regression
    from upstream test drift, NOT this change: `stage_properties2`'s output.txt
    grew 8→213 lines upstream (now asserts full stack-TRACE frames for the
    Stage 2071 setters — `Error$/throwError`/`set height`/`logError`); our
    getStackTrace formatting for those setter frames differs. Unrelated to
    BitmapData/Bitmap; a pre-existing getStackTrace gap newly exposed.


**Plan:** `SWFRecompDocs/plans/avm2-support-plan.md` (umbrella; stages,
architecture sketch, tranche definitions). Phase-1 metric: pass rate on this
suite's trace tests.

## State

- **CI baseline (run 29180816425, 2026-07-12): 727 / 1,201 passing +
  21 ruffle_matched = 748 effective (62.3%)** — up from Stage 5's 657
  effective (+91), **zero pass->fail regressions** in avm2 or ANY AVM1
  suite (avm1 634/706+17RM, gnash suites, shumway 73/92 + 46/47,
  regression 41/41 all unchanged), wasm-link-smoke green. Beyond the 62
  candidate passes, Stage 6 also unlocked all_classes/security/swf11,
  cryptscore, button_nested_frame, displayobject_hittestobject,
  edittext_autosize_height_dynamic and other bystanders (+88 raw).
- **Stage 6 COMPLETE (2026-07-12, commits `45a507da5`..`415205ed7`):
  75/85 Stage-6 candidates pass locally** (72 pass + 3 ruffle_matched;
  exit criterion >=60 met; `_investigation/STAGE6_CANDIDATES.txt` carries
  the triage of the 10 misses: 7 flash.text.engine
  (TextBlock/TextLine family, own follow-up), 2 Loader-infrastructure
  font tests, 1 device-font metric parity). What landed:
  - Tranche 0 — all 13 Stage-5 stragglers: instance scope = class scope
    + [class object] (static slot writes from ctors), SimpleButton
    event/order/naming fixes (wrapper counter slot, nested-framescript
    ctor ordering, set_state detach, set_state_child semantics,
    addedToStage state recursion, button-parent added-event gate),
    nextScene/prevScene current-scene fallback, goto Replace
    swaps-in-place per type, manual_frame_construct.
  - `SWFRecomp/src/abc/abc_timeline.cpp` — full DefineEditText parse ->
    `avm2_generated_edittexts`; DefineFont2/3 (names/codes/advances/
    metrics) -> `avm2_generated_fonts`; CSMTextSettings (tag 74).
  - `SWFModernRuntime/src/avm2/avm2_text.c` (new, ~5K lines) — TextFormat
    (nullable fields, round_to_even, 64-char font cap), FormatSpans
    (normalize/get/set/replace/mix_with), from_html parser + to_html
    writer (canonical FP form), condense_white_swf8, the layout engine
    (f32-exact metrics, wrap_line, align/margins/justify/bullet,
    two-pass autosize, LAZY autosize bounds incl. render-phase apply),
    the full TextField property/method surface, flash.text.Font
    (SymbolClass binding, enumerateFonts/registerFont), StyleSheet
    (CSS parser + EditText integration), TextRun/TextLineMetrics/
    Rectangle/ColorTransform classes, flash.text.engine.FontDescription
    + constant classes, flash.utils setTimeout/setInterval.
  - Display: TextField width/height/x/y route through EditText bounds;
    hitTestObject/hitTestPoint/getBounds/getRect/globalToLocal/
    localToGlobal; Transform concatenatedMatrix (FP quality quirk)/
    pixelBounds/colorTransform; real stage.focus tracking; AVM2 trace
    normalizes \r to \n.

- **CI baseline (run 29174330330, 2026-07-12): 639 / 1,201 passing +
  18 ruffle_matched = 657 effective (54.7%)** — up from the E4X
  baseline's 476 (+163), **zero pass->fail regressions** in avm2 or ANY
  AVM1 suite, wasm-link-smoke green.
- **Stage 5 COMPLETE (2026-07-12): 141/159 Stage-5 candidates pass
  locally and in CI** (`_investigation/STAGE5_CANDIDATES.txt`; exit
  criterion >=100 met; the 18 misses are triaged in that file's header —
  5 infrastructure (Loader/BitmapData/filters/TextField-matrix/
  ApplicationDomain), 6 frame/goto edge semantics, 7 SimpleButton
  event-order details). What landed (commits `f662d9b9a`..`66ae469e1`):
  - `SWFModernRuntime/src/avm2/avm2_events.c` — real flash.events:
    Event internal state + const getters + clone/formatToString family,
    EventDispatcher with priority buckets/capture split/dedup, the
    3-phase DOM dispatch, EventDispatcher(target) aggregation,
    willTrigger parent walk, IEventDispatcher interface aliases, the FP
    broadcast registry (enterFrame/exitFrame/frameConstructed/render,
    length-snapshotted iteration).
  - `SWFRecomp/src/abc/abc_timeline.cpp` — an independent second pass
    over the decompressed tag stream (AVM2 SWFs only) emitting
    RecompiledABC/abc_timeline.c: per-timeline place/remove op tables
    (matrices/names/depths/ratio/visible), frame labels (scene data
    supersedes FrameLabel tags), scenes, a character dictionary with
    bounds + EditText initial text (HTML pre-stripped), DefineButton/2
    state records, stage rect/rate/bg color.
  - `SWFModernRuntime/src/avm2/avm2_display.c` — the AVM2-owned display
    tree: full DisplayObject property surface (matrix decomposition
    cache, twips quantization, exact NaN/Infinity rules, width/height
    cross-coupled scale formulas), container render/depth-list duality
    (rotate-move insert, timeline lock/pull via placed_by_avm2_script,
    2006/2024/2025/2150/3783), Ruffle's allocator model for
    script-created objects, Sprite.constructChildren with the
    RUNNING_CONSTRUCT_FRAME guard, the 5-phase tick, queued gotos +
    survives_rewind, scenes/labels surface, Stage (frameRate clamps,
    color alpha, 2071 setter overrides, invalidate->render),
    SimpleButton eager state construction (wrapper sprites, the
    has-MovieClip nested frame + one-shot framescript order),
    TextField.text, FrameLabel/Scene/Graphics/Matrix/Transform/System
    classes. runSWF_avm2 drives the real frame lifecycle.
  Session prompt `SWFRecompDocs/prompts/avm2-stage5-frames.md` carries
  the gotcha list + the static-slot-write lead for the button misses.
  Next: input.json harness (interactive tests), flash.display.Loader /
  LoaderInfo, BitmapData, or the AVM1-interop track.
- **CI baseline (run 29165717217, 2026-07-11): 475 / 1,201 passing
  (39.6%)** — up from tranche 3's 411/1200 (+64), **zero pass->fail
  regressions** in avm2 or ANY AVM1 suite (avm1 634/706, gnash suites,
  shumway 73/92 + 46/47, regression 41/41 all unchanged),
  wasm-link-smoke green. Beyond the 51 candidate passes, the E4X commit
  also unlocked flash_xml, flash_xml_cloneNode, flash_xml_namespace,
  flash_xml_removeNode (the legacy family), issue_13780, checkfilter,
  doabc_is_eager, bitmapdata_draw_cpu_overwrite_gpu, and three
  edittext_autosize* runtime_error->0-line-mismatch conversions; 40
  more tests moved runtime_error -> output_mismatch (they now run to
  the end). A follow-up commit added describeType(null/undefined)
  ("null"/"void" types), getQualifiedSuperclassName, and the
  flash.utils-vs-avmplus describeType split (1010 on undefined) —
  confirmed by run 29166383620: **476/1201 (39.6%)**, null_void_types
  now passing, zero regressions anywhere, wasm-link-smoke green.
- **E4X/XML engine (2026-07-11): 53 / 55 E4X candidates pass locally**
  (`_investigation/E4X_CANDIDATES.txt`; exit criterion >=40 met). The 2
  misses are triaged infrastructure gaps, not E4X gaps:
  xml_socket (needs flash.net.XMLSocket + the Ruffle test-framework
  socket.json mock) and xml_appendchild_swf_v21 (its first 7 lines pass;
  the rest needs flash.display.Loader loading loadable.swf).
  What landed:
  - `SWFModernRuntime/src/avm2/avm2_e4x.c` — E4XNode tree, hand-written
    parser for the E4X subset (entities + char refs with Ruffle's
    "&[^;]*;-or-verbatim" rule, CDATA/comments/PIs, DOCTYPE/decl skip,
    lenient end tags, dup-attr 1104, errors 1083-1097), namespace
    resolution (xmlns decls, dxns), ECMA-357 ToXMLString with
    prettyPrinting/prettyIndent, toString simple-content rules,
    matches_name/handle_input_multiname (incl. the original-set+public
    rebuild — xml_explicit_use_namespace), deep equals/copy, mutation.
  - `SWFModernRuntime/src/avm2/avm2_xml.c` — XML/XMLList classes: full
    method surface (namespace ops incl. the ECMA 9.1.1.13 prefix strip,
    appendChild/insertChild*/replace/setChildren with maybe_escape_child
    SWF gates, normalize, setName 1117 + namespace clearing), class-call
    conversions (XML(x) identity, 1088), settings statics, the
    [[TargetObject]]/resolve_value append machinery, list numeric-index
    [[Put]], the notification API (attributeAdded/attributeChanged/
    nameSet with ancestor bubbling — xml_notification_bubbling), and the
    legacy flash.xml.XMLNode/XMLDocument/XMLNodeType family (ported from
    Ruffle's AS3 impls; xmldocument/xmlnode/xml_ignore_white).
  - Property engine: XML/XMLList receivers intercept get/set/delete in
    every path of avm2_ops.c (static/dyn/QName/RTQName), with the
    avmplus Toplevel.cpp quirk (public method-trait hits reroute to E4X
    access; explicit AS3::name binds the method), numeric-index rules
    (xml[0] === xml; node->obj wrapper caching for ===), call fallback
    (simple-content string delegation, 1-element list delegation), `in`/
    hasOwnProperty, enumeration hooks, with-scope resolution for filter
    loops, abstract_eq XML/XMLList/QName arms, and the XML+XML → XMLList
    add operator.
  - Ops: GetDescendants (static/lazy/RTQName forms), CheckFilter (1123),
    Dxns/DxnsLate (ctx->dxns, dynamically scoped via avm2_call_method_ref
    save/restore + SET_DXNS reset; feeds handle_input + parser).
  - Integration: AMF3 writer XML arm (0x0B XmlString, pretty-sensitive —
    amf_xml), QName is_attribute flag (honored by lazy names and
    flash_proxy::isAttribute — qname_as_lazy_name_attribute_multiname),
    real describeType (E4X tree: attrs, extendsClass chain, constructor
    signatures, Object's AS3 method trio; atom-int class rule —
    function_proto_created, number_autoconv), avmplus flag constants,
    primitive builtin classes now SEALED|FINAL, avm2_alloc(0) fixed
    (empty-table ABCs — xml_explicit_use_namespace).
  **Census ceiling 1155 -> 1163/1164** with 128 ops
  (`_investigation/E4X_OPS.txt` = TRANCHE3_OPS + GetDescendants/
  CheckFilter/Dxns/DxnsLate); the only op-blocked test left is the
  alchemy (Li8/Sf64/...) one.

- **CI baseline (run 29158224391, 2026-07-11): 411 / 1,200 passing
  (34.2%)** — up from tranche 2's 354/1200 (+57), zero pass->fail
  regressions in avm2 or ANY AVM1 suite (avm1 634/706, gnash suites,
  shumway 73/92 + 46/47, regression 41/41 all unchanged),
  wasm-link-smoke green. Beyond the candidate list, the tranche unlocked
  error_tostring, fast_index_access, get_definition_by_name,
  get_qualified_class_name, nested_iteration, net_getClassByAlias,
  number_autoconv_amf, stage3d_sampler x2, and
  coerce_to_primitive_side_effects_with_nulls (ruffle_matched). NOTE:
  bytearray_oom now runs far enough to TIMEOUT in CI instead of
  erroring (it is upstream-ignored, but it costs its timeout budget
  each run).
- **Stage 4 tranche 3 (2026-07-11): 48 / 53 tranche-3 candidates pass
  locally and in CI** (`_investigation/TRANCHE3_CANDIDATES.txt`; exit
  criterion >=42 met). The 5 misses, all triaged: bytearray_oom +
  dictionary_weak_keys (upstream-ignored / known_failure), amf_xml +
  qname_as_lazy_name_attribute_multiname (E4X — XML literals /
  GetDescendants, deferred to the E4X plan), amf_array_serialization
  (needs flash.net.LocalConnection/NetConnection plus the Ruffle
  test-framework Navigator fetch mock — deferred).
  New since tranche 2: Namespace/QName classes + PushNamespace + the
  full lazy-namespace multiname surface (RTQName/RTQNameL emission,
  QName-valued lazy names, ns-set trait matching for lazy names),
  flash.utils.Dictionary (object-identity keys, numeric-name enumerants,
  tombstoned expandos + a Ruffle dynamic_map-style enumeration cursor so
  delete-during-iteration doesn't shift the iterator),
  flash.utils.Proxy (full property-engine hook routing incl. enumeration
  + coerce_to_primitive side effects), flash.utils.ByteArray
  (endian-aware I/O, avmplus-lenient UTF-8 decode, iconv-backed
  readMultiByte/writeMultiByte, zlib compress/uncompress, [] index
  access), AMF3/AMF0 readObject/writeObject byte-exact against Ruffle's
  flash-lso output (string/trait/object reference-table quirks included),
  flash.net.registerClassAlias/getClassByAlias/ObjectEncoding, a minimal
  Date (millis + getTime/valueOf/toString), and flash.geom.Point as a
  sealed two-slot class. flash.errors instances now keep name "Error"
  (their constructors never re-set it after super()).
  **Census ceiling 1148 -> 1155/1163** with 124 ops
  (`_investigation/TRANCHE3_OPS.txt` = STAGE4_OPS + PushNamespace).
  Remaining blocking ops: GetDescendants (3, E4X), CheckFilter (3, E4X),
  DxnsLate/alchemy (1).
- **CI baseline (run 29154109023, 2026-07-11): 354 / 1,200 passing
  (29.5%)** — up from Stage 3's 296/1198 (+58), zero pass→fail
  regressions in avm2 or ANY AVM1 suite (avm1 634/706, gnash suites,
  shumway 73/92 + 46/47, regression 41/41 all unchanged),
  wasm-link-smoke green. Remaining avm2 statuses: 764 output_mismatch,
  71 runtime_error, 11 ruffle_matched. Beyond the candidate list, the
  tranche unlocked application_domain, event_* (bubbles/cancelable/
  type), eventdispatcher_dispatchevent_this/haseventlistener,
  primitive_edge_cases, resolve_order, rng, symbol_class_root_not_zero,
  negative_volume_panned.
- **Stage 4 tranche 2 (2026-07-11): 50 / 55 tranche-2 candidates pass
  in CI and locally** (`_investigation/TRANCHE2_CANDIDATES.txt`; was 2
  at the Stage-3 baseline — the ≥45-of-55 exit criterion is met). The 5
  misses are all triaged to later work: class_call +
  amf_nondynamic_function_prop (ByteArray/AMF, tranche 3),
  coerce_to_primitive_side_effects (Proxy, tranche 3),
  function_proto_created (avmplus-shell describeType XML / E4X, deferred),
  json_stringify (its output.txt is hand-edited to Ruffle's FnvHashMap
  property iteration order — unmatchable in principle; one line differs).
  New since Stage 3: Vector (ApplyType + full runtime, avm2_vector.c),
  RegExp backed by vendored QuickJS libregexp
  (SWFModernRuntime/third_party/quickjs-libregexp, avm2_regexp.c) incl.
  String match/replace/search/split regex paths, JSON (avm2_json.c,
  SWF13+ gated), the avmplus Error name/message slot model +
  flash.errors classes, minimal flash.events Event/EventDispatcher,
  flash.system.ApplicationDomain (currentDomain + has/getDefinition),
  a describeType attribute stub, findproperty's global-prototype-chain
  fallback, primitive scope boxing, and lenient ConstructProp on
  primitive receivers.
- **Stage-3 CI baseline (run 29145483298, 2026-07-11): 296 / 1,198
  passing (24.7%)** — zero pass→fail regressions in avm2 or ANY AVM1
  suite, wasm-link-smoke green. 152/166 tranche-1 candidates.
- **Static op-surface ceiling: 1148 / 1162 censused tests** with the
  Stage-4 op surface of 123 IR ops
  (`_investigation/STAGE4_OPS.txt`; Stage 3's 122 ops + ApplyType — the
  census: `python3 SWFRecomp/tools/abc_op_census.py --implemented-file
  ruffle-tests/tests/swfs/avm2/_investigation/STAGE4_OPS.txt`).
  Remaining blocking ops: PushNamespace (6), GetDescendants (4, E4X),
  CheckFilter (3), DxnsLate/alchemy ops (1).
- **What exists now (Stage 3, 2026-07-11):**
  - **Emitter** (`SWFRecomp/src/abc/abc_emit.cpp`): full-body emission —
    `op_N:` labels for every branch/switch/exception target, gotos for
    Jump/IfTrue/IfFalse/LookupSwitch, inline (noreturn) aborts for
    unsupported ops with NO truncation. Bodies with active exception tables
    push an `Avm2TryFrame` (setjmp) whose handler dispatches to the catch
    target with the thrown value as the sole stack entry; `sp`/`scope_n`
    are volatile in such bodies. Emits int/uint/double pools, method
    signatures (flags, param types, optional defaults, return type,
    activation traits, `is_function`), class interfaces + protected ns,
    trait default values, and the SWF version
    (`avm2_generated_swf_version` — sort/parse quirks are version-gated).
    Class/script initializer bodies are marked "interpreter mode" (avmplus
    runs them interpreted; the index fast path then ignores the ns set —
    class_init_interpreter_mode, array_access_interpreter).
  - **Runtime** (`SWFModernRuntime/src/avm2/`, now 11 files): full coercion
    matrix + abstract eq/lt + ECMA Add split; Number→string via shortest
    round-trip decimal + Ruffle's MAX_PRECISION exponential arm;
    string_to_f64/int ports (incl. the >15-digit and powi rounding quirks);
    property engine with getters/setters (GETSET merge), prototype chains,
    bound-method caching (obj.m === obj.m), interface-ns aliases,
    protected-ns aliases with override sync, slot metadata tables
    (shadowed parent slots keep their own defaults — supercalls), typed
    slot coercion, sealed/dynamic miss semantics (1069 vs 1081/1056,
    strict "public" = empty-URI Namespace/Package); functions/closures
    (NewFunction, NewActivation, arguments/rest, optional defaults,
    unchecked functions, 1063 with FP display names, call/apply,
    fn.prototype incl. explicit-null state); typed exceptions
    (setjmp/longjmp try frames, is_of_type catch matching, catch-scope
    objects with a synthetic sealed class named after the variable,
    uncaught errors abort only the current top-level entry); debug call
    stack + Error.getStackTrace (construction-time snapshot, FP frame
    names); builtins: Object/Class/Function, String (UTF-16-aware
    length/charAt/charCodeAt/index math over UTF-8 storage, Flash-table
    case mapping, split/slice/substr/substring/indexOf/lastIndexOf/
    localeCompare/fromCharCode incl. surrogate pairs), Number/int/uint/
    Boolean (toString radix, toFixed/toPrecision/toExponential in Rust
    digit-string style), Array (dense+sparse storage, holes resolving
    through the prototype, avmplus qsort port with SWF-version compare
    quirks, sortOn, splice/slice/indexOf/removeAt/insertAt/...), Math
    (avmplus RNG seeded from MOCK_DATE_TIME), Error family (exact FP
    message strings), toplevel (trace/isNaN/isFinite/parseInt/parseFloat/
    escape/unescape/getQualifiedClassName/getDefinitionByName in both
    flash.utils and avmplus namespaces), stubs for XML/XMLList/Date/
    flash.geom.Point.
  - **Harness**: `verify_output.py` gained Ruffle-framework approximations
    semantics — numeric compare is enabled by the presence of an
    `[approximations]` section (epsilon 0 = exact double equality) and
    `max_relative` is honored. Tests with no section keep exact string
    compare, so AVM1 suites can only gain from this.
- **Remaining tranche-1 misses (14, all triaged):**
  - RegExp (tranche 2): string_match, string_replace, string_search,
    string_split, function_unbound_this (also needs dispatchEvent).
  - Vector/ApplyType (tranche 2): try_catch, class_call (also ByteArray),
    array_vector_null_callback.
  - describeType / E4X XML output (deferred): number_autoconv,
    function_proto_created.
  - ByteArray/AMF (tranche 3): number_autoconv_amf.
  - Display/graphics (Stage 5): nan_scale.
  - Upstream `ignore = true`: number_tostring (added to
    ignored_tests.txt along with bytearray_oom in the Stage-3 audit).
- **ABC front-end (Stage 1)** and **Stage-2 wiring** unchanged — see git
  history of this file for the Stage-1/2 tables.
- Run one test: `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. Do NOT run the full
  suite locally (project rule) — full suite via CI.

## Tranche targets (from the 2026-07-10 corpus survey)

1. **Tranche 1 (~90):** pure language — DONE 2026-07-11 (see above).
2. **Tranche 2 (~50):** Vector, JSON, RegExp, object/proto edge cases.
   Vector (ApplyType) is the single biggest unlock: 80 censused tests.
3. **Tranche 3 (~60):** Namespace/QName/Proxy/Dictionary, ByteArray, AMF.
4. **Deferred:** XML/E4X (~51 + describeType), frame-lifecycle tests
   (Stage 5), graphics.
