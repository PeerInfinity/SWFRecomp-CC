# Session prompt — AVM2 Stage 5: frame lifecycle + display basics

**STATUS: COMPLETE (2026-07-12).** 141/159 candidates pass (exit >=100);
CI baseline 639/1201 (+18 RM = 657 effective, 54.7%) at run 29174330330,
zero regressions anywhere, wasm-link-smoke green. Misses triaged in
STAGE5_CANDIDATES.txt. The "resume state" section below is kept as the
gotcha record for follow-up sessions (esp. the static-slot-write lead).

## RESUME STATE (2026-07-11, session 2 — read this first)

Tranches 1-5 are all substantially implemented and committed
(`f662d9b9a`..`66ae469e1`): avm2_events.c (full Event/EventDispatcher/
broadcast registry), abc_timeline.cpp (static timeline tables incl.
button records + EditText initial text), avm2_display.c (~4everything:
property surface, containers, timeline instantiation, tick phases, goto
machinery, Stage incl. 2071 overrides, SimpleButton, TextField.text,
Graphics/Matrix/Transform/System stubs). runSWF_avm2 runs the real
frame lifecycle; the no-char-0 fallback only constructs never-placed
bindings.

Local candidate status at last count: ~120+/159 expected (final sweep
result in the CI baseline / commit messages; ≥100 exit already met).
Known remaining misses (triaged):
- displayobject_early_init (needs Graphics identity + BitmapData 2015),
  displayobject_filters (real filter classes), displayobject_transform
  (TextField + concatenatedMatrix), displayobject_set_name_loaded
  (flash.display.Loader) — infrastructure, not Stage-5.
- movieclip_frameconstruct_skipped (ctor-failure semantics: children
  stay unconstructed after root ctor throws — needs archaeology).
- simplebutton_symbolclass + a few button-event tests: static-slot
  write INSTANCE=this inside ctor reads back null from Main.INSTANCE
  (likely findproperty/class-scope static write bug — investigate in
  avm2_ops.c FindProperty scope walk); simplebutton_childevents*
  (event order details), goto_button_nested_framescript.
- stage_domain_getQualifiedDefinitionNames (ApplicationDomain
  parentDomain + getQualifiedDefinitionNames + fresh-instance-per-get).
- goto_nested_framescript (TextField replace mid-goto — check tf_text
  after run_goto materialize), movieclip_gotoandstop_framescripts2/
  _self, goto_in_scene_last_frame, movieclip_goto_scene_last_frame_*,
  movieclip_next_scene/prev_scene (scene-relative goto edges),
  movieclip_dispatchevent_selfadd/_target/_handlerorder/willtrigger
  (check individually — may already pass).

Next steps: (1) read the final sweep result, fix cheap stragglers if
any; (2) run the full CI pipeline (no-graphics mode) per
.claude/pipeline-handoff.md — commits are already pushed-ready; (3)
zero pass→fail regressions across all suites is the gate (avm2
baseline was 476/1201 at run 29166383620); (4) bookkeeping: plan §5
landing note, CURRENT_STATUS.md, avm2-e4x-engine/direction memories,
mark this prompt COMPLETE or refresh again.

Gotchas added this session (beyond the ones below): vtable accessor
overrides must REPLACE in place (lookup returns first match); broadcast
lists snapshot length before iterating; script-created display objects
are placed_by_avm2_script + NOT playing (frame 0 forever, framesLoaded
1); never-constructed children fire no events/scripts/orphans; normalize
uses the ±2^28 atom-int range (goto arg arithmetic is wrapping/
saturating with truncating u16 cast); FrameLabel tags ignored when
scene DATA exists (even 0 labels); SimpleButton has the one-shot
up/over/down/hit framescript order + nested frame when the up state
holds a MovieClip (SWF>9).


You are implementing **Stage 5** of the AVM2 plan
(`SWFRecompDocs/plans/avm2-support-plan.md` §5): the frame lifecycle
(broadcast events, addFrameScript, goto machinery) and the display
basics (DisplayObject/DisplayObjectContainer hierarchy, timeline
instantiation, the full Event/EventDispatcher semantics). The E4X/XML
engine is COMPLETE (2026-07-11); this is now the largest remaining
coherent unlock on the trace-test metric. Read the plan first (§4.4
execution semantics, §5 stage notes), then
`ruffle-tests/tests/swfs/avm2/_investigation/CURRENT_STATUS.md`, then
the memories `avm2-e4x-engine` / `avm2-stage4-tranche3` /
`avm2-stage3-tranche1` (gotcha lists), then skim the code you are
extending (seams below).

E4X landed at `f1d27c50c`..`93a612a50`. CI baseline: **avm2 476/1201
(39.6%)**, run 29166383620; zero regressions anywhere; wasm-link-smoke
green. Census ceiling 1163/1164 (`_investigation/E4X_OPS.txt`, 128 ops)
— the op surface is essentially DONE (only the alchemy-ops test is
op-blocked). Everything Stage 5 unlocks is runtime semantics, not ops.

## Goal

Candidate list (159 names, all failing at the baseline, grouped by
family with exclusions annotated):
`ruffle-tests/tests/swfs/avm2/_investigation/STAGE5_CANDIDATES.txt`
— events 16, displayobject 20, displayobjectcontainer 24, movieclip 52,
frames/goto/timeline 22, stage 11, simplebutton 12, misc 2. Tests
needing injected input (input.json), hit-test geometry, BitmapData
pixels, Stage3D, or LoaderInfo are excluded up front (own plans).

Exit: **≥100 of the 159 candidates passing in CI; every miss triaged**;
zero pass→fail regressions anywhere (the avm2 476 baseline must stay
green). This is a big stage — if you stop at a coherent tranche
boundary instead, refresh THIS prompt with precise resume state (the
Stage-3/4/E4X convention) and record the CI baseline you reached.

## Code seams (what exists today)

- `SWFModernRuntime/src/avm2/avm2_main.c::runSWF_avm2()` — the §4.4
  load ordering is done (ABC load → SymbolClass → eager last-script
  init → root construction). The gaps are marked: **step 2** records
  non-root SymbolClass bindings but never instantiates placed symbols
  ("Stage 5 (timeline instantiation)"), and **step 5**'s tick loop is a
  stub that runs only the root's frame-0 script once ("Stage-5 TODO:
  real timeline (playhead advance, enterFrame / frameConstructed
  broadcasts, non-root frame scripts)").
- `avm2_globals.c` — the display chain is a stub ladder (EventDispatcher
  → DisplayObject → InteractiveObject → DisplayObjectContainer → Sprite
  → MovieClip): EventDispatcher has add/remove/has/dispatch listeners
  (`ed_*` fns, `Avm2EventDispatcherExt`) but no capture phase, no
  priority ordering, no bubbling, no willTrigger; flash.events.Event is
  an expando-props stub (no clone/formatToString/isDefaultPrevented/
  const-getters); MovieClip has native addFrameScript storing closures
  in `Avm2MovieClipExt.frame_scripts` (0-based frame index).
- **Timeline data**: every avm2 test build already compiles
  `RecompiledTags/tagMain.c` (per-frame tag-fn calls, `tagShowFrame`,
  `frame_label_data[]`, `sprite_N_frame_labels[]`, PlaceObject/
  DefineSprite emissions) AND links the whole AVM1/tag.c runtime —
  runSWF_avm2 just never touches it. Two options for reaching frame
  structure from AVM2:
  1. **(Recommended)** Extend the recompiler to emit an AVM2-specific
     static timeline table into `RecompiledABC/` (per character:
     frame count, per-frame place/remove/name/depth ops, frame labels,
     scenes from DefineSceneAndFrameLabelData — see `swf.cpp:865`/`6201`
     for where labels are already parsed) and keep an AVM2-owned display
     tree in `src/avm2/`. Mirrors Ruffle's static movie data; zero
     entanglement with AVM1 structures; no shared-code CI risk.
  2. Drive tag.c's NO_GRAPHICS display list from runSWF_avm2. Touches
     shared runtime paths → per CLAUDE.md you'd need BOTH CI modes, and
     tag.c's display list is AVM1-shaped (child_mc_cache etc.). Avoid
     unless (1) proves unworkable.
- The `null_void_types`-style abstract_classes test family expects
  errors 2012/1115 for non-constructible flash classes — a cheap
  side-quest if you touch class flags (see `abstract_classes` expected
  output in the results.json for the inventory).

## Ruffle reference (local at ~/CC/ruffle)

- **Frame lifecycle ground truth**: `core/src/display_object/movie_clip.rs`
  (5013 lines — `run_frame_internal`, `enter_frame` (2531) with
  `skip_next_enter_frame`, `construct_frame` (2103 area), goto queueing
  (`queued_goto`), frame scripts; the AVM2 order per tick is:
  enterFrame broadcast → timeline advance/construct_frame (children
  instantiated + constructors run) → frameConstructed broadcast → frame
  scripts (addFrameScript closures) → exitFrame broadcast. Study the
  goto catch-up semantics before writing any of it — the
  movieclip_goto* / movieclip_displayevents_* tests probe exact
  phase/order and are unforgiving).
- **Broadcast events**: `core/src/avm2/mod.rs` / `avm2.rs`
  (`broadcast_event`: delivered to ALL constructed DisplayObjects in
  creation order regardless of display-list membership — plan §4.4).
- **Event machinery**: `core/src/avm2/events.rs` (513 — the 3-phase
  dispatch algorithm, ancestor chain build, priority buckets),
  `globals/flash/events/event_dispatcher.rs` (138) +
  `EventDispatcher.as`, `Event.as` (98) + `event.rs` (clone/
  formatToString/preventDefault semantics).
- **Display objects**: `globals/flash/display/display_object.rs` (1161 —
  the property surface incl. invalid-float clamping quirks),
  `display_object_container.rs` (629 — add/remove/swap/setChildIndex
  incl. the 2025-family error codes and timeline-vs-script depth
  rules), `movie_clip.rs` (568 — currentFrame/currentLabels/scenes/
  gotoAndX/play/stop surface), `stage.rs` (498), `sprite.rs`,
  `interactive_object.rs`. AS3 shims in the same dir (*.as).
- The container "timelinepull"/"timelinelock" tests probe Ruffle's
  depth-list vs render-list duality (`core/src/display_object/
  container.rs`) — read it before implementing addChildAt on
  timeline-placed children.

## Suggested tranche order (commit + local-batch at each checkpoint)

1. **Event machinery** (event_* + eventdispatcher_* — 16 tests, no
   display dependency): full Event class (type/bubbles/cancelable
   const-getters, clone-on-redispatch, formatToString, valueOf,
   preventDefault/isDefaultPrevented, target/currentTarget), dispatch
   with priority ordering + once-per-dispatch listener snapshot,
   willTrigger/hasEventListener split, EventDispatcher(target) ctor
   for the aggregation pattern, toString.
2. **Display tree + property surface** (displayobject_* + doc_* +
   stage core + movieclip_constr/properties): an AVM2-owned display
   model (parent/children/name/root/stage links), the property surface
   (x/y/width/height/rotation/alpha/visible with Ruffle's NaN/infinity
   handling), DOC child ops with exact error codes, SymbolClass
   timeline instantiation of frame-1 placed symbols (option 1 above:
   recompiler-emitted timeline tables), instance auto-names
   ("instanceN"), addedToStage/added event dispatch.
3. **Frame lifecycle** (movieclip_displayevents_* non-click +
   addframescript + timeline_scripts): the per-tick phase order,
   broadcast events to all constructed clips in creation order,
   addFrameScript execution (incl. same-frame re-entry rules),
   currentFrame/totalFrames/isPlaying.
4. **Goto machinery + labels/scenes** (goto_* + movieclip_goto* +
   currentlabels/scenes + framelabel_constr): queued gotos, catch-up
   construction, frame-script skipping rules, scene/label tables
   (DefineSceneAndFrameLabelData through the recompiler).
5. **SimpleButton structural** (simplebutton_* non-input): up/over/down
   state children, construction order quirks (avmplus constructs state
   symbols eagerly), soundTransform excluded.
6. Triage the misses; refresh STAGE5_CANDIDATES.txt statuses.

## Constraints & conventions (unchanged)

- Trunk-based; commit directly to `master`; autonomous commit/push/CI
  authorized (CLAUDE.md). Standard trailer. Full pipeline per
  `.claude/pipeline-handoff.md` at the end (no-graphics mode — unless
  you took option 2 and touched shared tag/render code, then BOTH
  modes); confirm zero pass→fail across ALL suites and wasm-link-smoke
  green.
- Conflict boundary: own `SWFRecomp/src/abc/`, `SWFRecomp/include/abc/`,
  `SWFModernRuntime/{src,include}/avm2/`, `RecompiledABC/` paths. Do NOT
  touch `SWFModernRuntime/src/actionmodern/action.c`. If you extend the
  recompiler's tag pass (timeline tables), keep the emission additive
  and gated on the AS3 FileAttributes bit (the Stage-2 `03c86381d`
  lesson — an AVM1-side behavior change there caused the only
  regression any stage has had).
- New src/avm2/*.c files go into verify_output.py `compile_native`'s
  avm2 list (the one allowed edit there).
- Do NOT run the full avm2 suite locally. Single tests:
  `python3 ruffle-tests/verify_output.py --test=NAME
  --tests-dir=ruffle-tests/tests/swfs/avm2 --diff`. Batch loop greping
  `^Pass:` over the candidate list is ~2-4 s/test warm.
- Keep the honest-failure property: unimplemented paths abort with a
  named message, never silently mis-execute.

## Gotchas from earlier stages you must not trip over

- REBUILD the recompiler after any SWFRecomp change
  (`cd SWFRecomp/build && make -j8`) — verify_output only recompiles
  the runtime side; stale binaries show up as "unimplemented op" or
  missing-table link errors.
- `RUFFLE_MATCHED` counts as effective pass — grep for `Effective` too
  before calling a test regressed.
- Some expected outputs are hand-edited to Ruffle's HashMap iteration
  order or use test-side normalizeXML-style helpers (sorted children,
  doubled indents) — match the SEMANTICS, read output.txt with cat -A
  before chasing byte diffs (json_stringify / describe_type_basic
  precedents).
- Class/script initializers are interpreter-mode (the `interp` flag);
  loose test statements land there.
- Primitive builtins are SEALED|FINAL since E4X; avm2_alloc clamps
  zero-size requests (ABCs with empty tables exist).
- flash.utils.describeType throws 1010 on undefined; the avmplus
  two-arg form doesn't. Both live in avm2_globals.c.
- movieclip_displayevents_* tests trace exact event ORDER across
  multiple ticks — get the tick phase order right ONCE (tranche 3)
  before attempting goto variants; MAX_FRAMES gates how many ticks a
  test runs (num_frames in test.toml → verify_output -DMAX_FRAMES).
- The E4X property-engine intercepts in avm2_ops.c check
  `avm2_value_is_xmlish` FIRST in every path — new display-object
  side-paths should slot in after them, and Dictionary/Proxy checks
  stay ahead of generic resolve (see the Resolved struct routing).

## End-of-session bookkeeping

- Stage-5 landing note in `avm2-support-plan.md` §5 (promote the Stage 5
  bullet to DONE, or record partial tranche state).
- Update `avm2/_investigation/CURRENT_STATUS.md` (new CI baseline,
  what landed, misses triaged).
- Update the `avm2-e4x-engine` / direction memories (Stage-5 status;
  what's next — likely the input.json harness for interactive tests,
  Loader/LoaderInfo, or BitmapData).
- If partial, refresh THIS prompt with precise "resume here" state; if
  complete, mark it COMPLETE at the top (Stage-1/2/3/4/E4X convention).
