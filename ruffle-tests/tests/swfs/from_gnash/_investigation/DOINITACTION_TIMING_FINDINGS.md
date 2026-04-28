# DoInitAction Timing — Research Findings

Research-only document. No code changes. Generated 2026-04-27 from a
follow-up investigation prompted by the reverted "SWF top-level
DoInitAction inline emission" attempt (commits abf1b163 → c958a5b6).

## Problem statement

`SWFRecomp/src/swf.cpp:2612` (top-level `SWF_TAG_DO_INIT_ACTION`)
currently emits each DoInitAction script as a call into the
`tag_init_scripts` buffer that runs once at process startup, inside
`tagInit()`, after dictionary setup but before any frame plays. This
breaks tests where a DoInitAction in a non-zero frame depends on state
established by a prior frame's DoAction:

- `gnash misc-ming.all/register_class/registerClassTest2` (0/44):
  mc3's frame-3 InitAction calls `_root.note(...)` /
  `_root.check_equals(...)`, but those helpers are defined by
  dejagnu's frame-1 DoAction. With the startup-hoist, the InitAction
  runs before frame 1, so the helpers don't exist yet and the traces
  silently no-op.

A prior session tried emitting top-level DoInitAction inline in
`frame_N` body in SWF stream order. That fixed `registerClassTest2`
(0/44 → 41/44) but catastrophically regressed the tests where a SWF
has the pattern `PlaceObject2(custom_clip char_id=N) → DoInitAction(N)`
within the same frame:

| Test | Before | After inline emission |
|------|--------|-----------------------|
| `register_and_init_order` (AVM1) | 231/231 | 41/231 |
| `on_construct` (AVM1) | 25/25 | 11/25 |
| `resolve_different_root` (AVM1) | 2/2 | 0/2 |
| `from_shumway/avm1/doactionorder/symbolclass` | 4/4 | 0/4 |

The regression is because the registered class's constructor fires at
PlaceObject2 placement time (Phase 3 of the existing registerClass
infrastructure). With inline-stream-order emission, DoInitAction (which
calls `Object.registerClass(...)`) runs after PlaceObject2, so the
class isn't registered yet when the constructor would fire.

## (a) What does Flash actually do? — Confidence: HIGH

Within a single frame, **all DoInitAction tags execute before any of
that frame's PlaceObject*/RemoveObject*/DoAction tags, regardless of
byte order in the SWF stream**. This is the only ordering that
satisfies all the empirical evidence:

- **Group A** (`registerClassTest2`): DoInitAction(mc3) sits in frame
  3, but depends on frame-1 dejagnu helpers → DoInitAction must run
  AFTER prior frames have completed their DoAction drain.
- **Group B** (`register_and_init_order`, `on_construct`,
  `resolve_different_root`, `from_shumway/.../symbolclass`): SWF
  stream is `PlaceObject2(custom_clip) → DoInitAction(custom_clip)`
  within the same frame, but the registered class's constructor must
  fire at PlaceObject2 → DoInitAction must run BEFORE same-frame
  PlaceObject2.

Both constraints are simultaneously satisfied iff DoInitActions for
frame N run after frame N-1's drain and before frame N's display +
script tags.

## (b) What does Ruffle do? — Confidence: HIGH (verified in source)

Ruffle uses a **two-pass model** keyed on a separate "preload" cursor.
References are to `~/CC/ruffle/core/src/display_object/movie_clip.rs`:

- `MovieClip::preload()` (lines 455–591) iterates the tag stream up
  through ShowFrame, dispatching the `tag_callback` declared at line
  498. That callback handles **definition tags** (DefineShape,
  DefineSprite, DefineButton, …), **DoInitAction** (line 530),
  **ExportAssets** (line 532), and **ImportAssets / ImportAssets2**
  (lines 541–548). It does NOT handle PlaceObject*/RemoveObject*/
  DoAction.
- `MovieClip::run_frame_internal()` (lines 1282–1407) iterates the
  same tag stream a second time, but its `tag_callback` (line 1311)
  only handles **display + script tags**: DoAction, PlaceObject*,
  RemoveObject*, SetBackgroundColor, StartSound, ShowFrame.
- Preload is gated to advance ahead of the play cursor:
  `run_frame_internal` early-returns if
  `current_frame() + 1 >= cur_preload_frame.get()`. So all of frame
  N's DoInitActions / ImportAssets / Exports complete during preload
  BEFORE `run_frame_internal(N)` ever runs PlaceObject2 / DoAction
  for frame N.

This directly confirms: in Ruffle, DoInitAction is decoupled from
same-frame display/script ordering, runs in its own pass, and finishes
before the frame's display tags.

## (c) Concrete recompiler proposal — Confidence: MEDIUM-HIGH

Mirror Ruffle's two-pass model **at per-frame granularity** by
introducing a per-frame "init prologue" buffer in the recompiler.

1. Add an `std::stringstream current_frame_init_actions` member and a
   `bool frame_init_emitted` flag to the SWF parser state.
2. **Top-level DoInitAction** (`SWFRecomp/src/swf.cpp:2612`): instead
   of `tag_init_scripts << "\t" << func_name << "(app_context);"`,
   write to the prologue buffer:
   ```
   current_frame_init_actions
       << "\tif (!catch_up_mode || g_tag_skip_mode) "
       << "tagDoInitActionGuarded(app_context, "
       << init_sprite_id << ", " << func_name << ");\n";
   ```
3. **Top-level ImportAssets / ImportAssets2** (`swf.cpp:4020-4053`):
   redirect from `tag_init_scripts` to `current_frame_init_actions`,
   in stream order with DoInitAction. Required by
   `do_init_action_child`, which depends on the within-frame
   DoInitAction↔ImportAssets stream order.
4. **Frame-body emission gate**: every site that currently writes a
   non-init tag's emission to `context.tag_main` for the current
   frame body (PlaceObject2, RemoveObject2, DoAction
   `actionQueueScript`, `tagSetBackgroundColor`, etc.) should call a
   helper first:
   ```cpp
   void flushFrameInitPrologue() {
       if (!frame_init_emitted &&
           !current_frame_init_actions.str().empty()) {
           context.tag_main << current_frame_init_actions.str();
       }
       frame_init_emitted = true;
   }
   ```
5. **Frame open / close**: at the frame-open sites
   (`swf.cpp:447-449` and `~828-833`), reset
   `current_frame_init_actions.str("")` and
   `frame_init_emitted = false`. At ShowFrame (`swf.cpp:886`), if
   `!frame_init_emitted` (e.g. a frame containing only DoInitAction
   with no other tags), call `flushFrameInitPrologue()` before
   `tagShowFrame`.

Resulting `frame_N` layout:

```c
void frame_N(SWFAppContext* app_context) {
    /* prologue (new) */
    if (!catch_up_mode || g_tag_skip_mode)
        tagDoInitActionGuarded(app_context, A, script_a);
    if (!catch_up_mode || g_tag_skip_mode)
        tagDoInitActionGuarded(app_context, B, script_b);
    actionImportAssets(app_context, "child.swf");
    tagImportCharacter(app_context, …);
    /* body (existing) */
    actionQueueScript(app_context, script_X);
    tagPlaceObject2(app_context, …);
    …
    /* epilogue (existing) */
    tagFlushPendingEnterFrame(app_context);
    if (!catch_up_mode || g_tag_skip_mode)
        actionDrainOnloadAndScript(app_context);
    tagShowFrame(app_context);
}
```

`tag_init_scripts` becomes empty for top-level DoInitAction /
ImportAssets and can be removed from `tagInit()`. `tag_init`
(definition tags, `tagDefineSprite` / `tagRegisterExport` /
`initVarArray`) is unchanged.

## (d) tagDoInitActionGuarded / actionImportAssets adjustments — Confidence: MEDIUM-HIGH

- **Re-apply the `(g_current_movie_id, char_id)` keying** on
  `g_init_action_done` in
  `SWFModernRuntime/src/libswf/tag.c:5258-5268`. With the prologue
  running inside `frame_N`, the guard now actually executes (the
  previous startup hoist bypassed it because `tag_init_scripts`
  called `script_X(app_context)` directly, not via the guard
  wrapper). Parent and child SWFs sharing `char_id=1` for their
  DoInitAction sprites must not shadow each other — this was the
  latent bug exposed in the reverted attempt.
- **Gate at the call site**: `(!catch_up_mode || g_tag_skip_mode)`.
  This makes:
  - Forward catch-up (`catch_up_mode=1, g_tag_skip_mode=0`) NOT
    re-run prior frames' DoInitActions — they fired during the
    original play-through.
  - Script-only target-frame replay (`g_tag_skip_mode=1`) DOES
    invoke the guarded call, but `tagDoInitActionGuarded`
    short-circuits on the `(movie_id, char_id)` key so a single init
    script never runs twice.
- **`actionImportAssets` idempotency**: if `actionImportAssets` is
  not already self-guarding, add a side dictionary keyed on
  `(movie_id, url)` to no-op repeat invocations during script-only
  replay. (May already be handled — verify on `do_init_action_child`
  before extending.)
- **Sprite-internal DoInitAction** (`swf.cpp:5075-5111`) is
  unchanged. It already emits inline through
  `tagDoInitActionGuarded` and Ruffle has the same arrangement
  (sprite preload nests inside the outer preload).

## (e) Regression risk assessment — Confidence: MEDIUM

| Risk | Likelihood | Why |
|------|------------|-----|
| Group B (`register_and_init_order` 233/233, `on_construct` 25/25, `resolve_different_root` 2/2, `doactionorder/symbolclass` 4/4) | LOW | All four had DoInitActions in frame 0; prologue runs before frame-0 PlaceObject2, identical effective ordering to the current startup-hoist for these tests. |
| `do_init_action_child` (multi-SWF) | LOW–MEDIUM | The `(movie_id, char_id)` guard rework is mandatory; verify the gate also fires for sub-SWF DoInitActions invoked through `actionImportAssets`. |
| `register_class_with_sound`, `attach_movie`, `attach_movie_stop`, `clip_constructors`, `movieclip_init_object`, `init_object_order`, `clip_events` | LOW | DoInitActions in frame 0; same as Group B. |
| `register_class_return_value` (16/16), `bad_placeobject_clipaction` | LOW | Single-frame; equivalent ordering. |
| Misc-ming recently-fixed (`loop_test3/5/8`, `instanceNameTest`, `attachMovieTest`, `ResolveEventsTest`, `event_handler_scope_test`) | LOW | None have multi-frame DoInitAction patterns. |
| `registerClassTest2` (Group A target) | TARGET | Expected 0/44 → ~41/44, recovers prior reverted-attempt result. |
| Goto / catch-up paths (`goto_execution_order`, `goto_execution_order2`, `execution_order2/3`, `goto_rewind*`, `RegisterClassTest3`) | MEDIUM | Need careful audit of `(!catch_up_mode || g_tag_skip_mode)` gating, especially backward gotos that re-run frame_0 in script-only mode (guard must short-circuit). |
| Tests relying on DoInitAction firing literally at process startup before any runtime setup | LOW | None observed; runtime sequence between `tagInit()` and `frame_0()` is internal setup only, no AS execution. |
| `actionImportAssets` re-entrancy under goto replay | MEDIUM | Need an idempotency guard in the runtime (or verify the gate alone is sufficient if catch-up replay doesn't include `g_tag_skip_mode`). Test on `do_init_action_child`. |

## Required-pass guardrail before merging

- 14-test AVM1 registerClass set: `register_and_init_order` 233/233,
  `register_class_return_value`, `register_globals_across_frames`,
  `register_underflow`, `attach_movie`, `attach_movie_stop`,
  `export_assets`, `clip_constructors`, `on_construct`,
  `movieclip_init_object`, `empty_movieclip_can_attach_movies`,
  `do_init_action_child`, `register_class_with_sound`,
  `bad_placeobject_clipaction`.
- Misc-ming recently-fixed: `attachMovieTest`, `instanceNameTest`,
  `ResolveEventsTest`, `event_handler_scope_test`, `loop_test3`,
  `loop_test5`, `loop_test8`, `init_object_order`,
  `init_object_invalid`, `attach_movie_stop`,
  `movieclip_in_removed_button`, `clip_events`.
- Shumway: `from_shumway/avm1/doactionorder/symbolclass`,
  `from_shumway/avm1/doubleAndRegister`.
- Goto-sensitive: `goto_execution_order`, `goto_execution_order2`,
  `execution_order2`, `execution_order3`, `goto_rewind1/2/3`,
  `goto_both_ways1/2`.
- Multi-SWF: `do_init_action_child` (highest-risk re. the
  `(movie_id, char_id)` key extension).

## Out of scope / explicitly deferred

The remaining 3 lines on `registerClassTest2` after this fix lands
(`clip2.getDepth() == undefined` MC built-in handler gating, and
`clipevs.onLoad` / `clip3.onLoad` ordering) are independent of
frame-init ordering and tracked in `REGISTERCLASS_LIFECYCLE_PLAN.md`.

## Cross-references

- `incomplete/REGISTERCLASS_LIFECYCLE_PLAN.md` — original
  registerClass lifecycle plan; "Reverted: SWF top-level DoInitAction
  inline emission" section captured the regression that motivated
  this investigation.
- `incomplete/DOINITACTION_PER_FRAME_PROLOGUE_PLAN.md` —
  implementation plan derived from these findings.
- `~/CC/ruffle/core/src/display_object/movie_clip.rs:455-591` —
  Ruffle preload pass.
- `~/CC/ruffle/core/src/display_object/movie_clip.rs:1282-1407` —
  Ruffle run_frame_internal pass.
- `~/CC/gnash/testsuite/misc-ming.all/register_class/registerClassTest2.c`
  — Group A canonical test.
- `SWFRecomp/src/swf.cpp:2612` — top-level DoInitAction emission.
- `SWFRecomp/src/swf.cpp:4020-4053` — top-level ImportAssets emission.
- `SWFRecomp/src/swf.cpp:5075-5111` — sprite-internal DoInitAction
  emission (unchanged by this proposal).
- `SWFModernRuntime/src/libswf/tag.c:5257-5268` —
  `tagDoInitActionGuarded` once-per-character guard.
