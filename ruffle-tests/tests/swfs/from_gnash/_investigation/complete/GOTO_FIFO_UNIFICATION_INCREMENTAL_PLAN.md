# Goto FIFO Unification — Incremental Plan

<!-- TESTS: consecutive_goto_frame_test -->

<!-- PLAN_META
id: GOTO_FIFO_UNIFICATION_INCREMENTAL
status: pending
phases:
  - id: A
    name: "Side table: recompiler emits (char_id, frame) → script_func* mapping"
    status: complete
  - id: B
    name: "ng_gotoFrameCurrentSprite records target into a deferred-script-queue (no dispatch)"
    status: complete
  - id: C
    name: "Drain hook for deferred-script-queue, gated behind g_unify_sprite_drain (default 0)"
    status: complete
  - id: D
    name: "Flip g_unify_sprite_drain=1 — sprite goto from inside sprite scripts dispatches in FIFO"
    status: complete
  - id: E
    name: "ng_executeGotoCatchUp: inline funcs[target] with drain-suppress (was Phase 2 of original plan)"
    status: complete
  - id: F
    name: "Phase 4 gate simplification + sprite eager-init force-queue during catch-up"
    status: complete
  - id: G
    name: "Retire g_deferred_goto_queue + outer drain loop (was Phase 3 of original plan)"
    status: complete
  - id: H
    name: "swf_headless.c parity (was Phase 5 of original plan)"
    status: complete
dependencies:
  - "Reframes: GOTO_FIFO_UNIFICATION_PLAN.md (blocked/) — same problem, atomic-commit framing was untractable. The original plan stays as the architectural reference (problem statement, FIFO-order trace, related docs). This plan is the shippable rollout."
  - "Foundation: DRAIN_SUPPRESS_PRIMITIVE_PLAN.md (complete/, commit d1cd1d1f) — used by Phase E."
target_test:
  - "consecutive_goto_frame_test (4/12 baseline → 12/12 once Phase F lands)"
-->

## Why this plan exists

The original `GOTO_FIFO_UNIFICATION_PLAN.md` (now in `blocked/`) framed the
work as "Phases 1+2+3 in a single atomic commit, Phase 4 as cleanup."
Detailed dispatch tracing (see that plan's "Updated finding 2026-04-26b"
section) showed:

1. Phase 4 (recompiler gate simplification) is **required atomically**, not
   cleanup — without it, sprite-script sync-fire through gate g2 cascades
   under Phase 1's inline-fire and breaks the test worse than baseline.
2. The combined scope (4+ runtime changes + 1 recompiler change + headless
   parity + regression triage on `loop_test*` / `goto_rewind*` / `unload*`)
   exceeds a single working session and requires CI roundtrips per
   iteration that can't be locally pre-screened.

The fix is to **separate primitives from semantics**. Each session adds a
piece of infrastructure that doesn't change behavior, then a single
opt-in flag flips semantics atomically. Regressions concentrate in the
flip-day session (Phase D / Phase F), and infrastructure sessions (A, B,
C, G, H) are zero-risk.

## Session map (one phase per session)

Sessions are ordered so each one either has zero behavioral impact OR
has its impact bounded by a runtime flag. Land them strictly in order;
later sessions assume earlier infrastructure.

### Phase A — Sprite frame script side table — COMPLETE 2026-04-26

**Scope.** Recompiler emits a side table mapping
`(sprite_char_id, frame_idx) → script_func*`. Runtime exposes
`actionGetSpriteFrameScript(char_id, frame_idx) → script_func*`. Nothing
uses the table yet.

**Files changed.**
- `SWFModernRuntime/include/actionmodern/sprite_frame_scripts.h` (new)
- `SWFModernRuntime/src/actionmodern/sprite_frame_scripts.c` (new)
- `SWFModernRuntime/CMakeLists.txt` (new source in CORE_SOURCES)
- `ruffle-tests/verify_output.py` (new source in both core_sources lists)
- `SWFRecomp/include/swf.hpp` (`sprite_frame_scripts_table` + `_count` fields)
- `SWFRecomp/src/swf.cpp` (table accumulation at sprite DoAction site
  ~line 4940; emission in tag_main + `tagInitSpriteFrameScripts` call
  at start of tagInit)

**Behavior delta.** None. Verified on `consecutive_goto_frame_test`
(unchanged 4/12 baseline) plus 18 guardrail tests (all pass): 8 AVM1
goto/init/clip-events tests + 10 misc-ming loop/init tests.

**Sample emission.** `consecutive_goto_frame_test`'s tagMain.c now
contains a 5-entry table (`{ 1, 0, script_0 }`, `{ 1, 0, script_1 }`,
`{ 4, 0, script_3 }`, `{ 4, 1, script_4 }`, `{ 4, 2, script_5 }`)
registered via `tagInitSpriteFrameScripts(...)` at the start of
`tagInit`. Multiple scripts at the same `(char_id, frame_idx)` are
preserved (sprite 1 has 2 DoActions in frame 0); the accessor returns
the first match — later phases will refine if multi-DoAction-per-frame
ordering matters.

### Phase B — Record sprite goto target into a deferred-script queue — COMPLETE 2026-04-26

**Scope.** Added a bounded-array runtime queue
(`g_pending` in `sprite_frame_scripts.c`,
`MAX_PENDING_SPRITE_SCRIPTS=16` — separate from `g_aq` and
`g_deferred_goto_queue`). `ng_gotoFrameCurrentSprite` resolves the
target script via Phase A's `actionGetSpriteFrameScript` and pushes
onto this queue via `actionQueuePendingSpriteScript`. **Nothing
dispatches it yet.**

**Files changed.**
- `SWFModernRuntime/include/actionmodern/sprite_frame_scripts.h`:
  added `PendingSpriteScriptEntry`,
  `actionQueuePendingSpriteScript`,
  `actionPendingSpriteScriptCount`,
  `actionPendingSpriteScriptAt`,
  `actionResetPendingSpriteScriptQueue`.
- `SWFModernRuntime/src/actionmodern/sprite_frame_scripts.c`:
  fixed-array queue (cap 16), drop-on-overflow.
- `SWFModernRuntime/src/libswf/tag_stubs.c`:
  added `#include <actionmodern/sprite_frame_scripts.h>` and the
  queue push at the bottom of `ng_gotoFrameCurrentSprite` (after
  the existing frame clamp + state mutations).
- `SWFModernRuntime/src/libswf/swf_core.c`:
  added `#include <sprite_frame_scripts.h>` and
  `actionResetPendingSpriteScriptQueue()` call once per tick (after
  the after-tick hook). Phase B no-drain — clearing prevents stale
  entries from leaking across ticks. Phase C will replace the no-op
  reset with FIFO dispatch when `g_unify_sprite_drain` is set.

**Behavior delta.** None visible. The script is queued but never
dispatched, so the existing `sprite_manual_next_frame=1` path still
drives sprite advancement.

**Verification.** `consecutive_goto_frame_test` unchanged at 0/12
baseline (3 matching lines as before). 30+ guardrail tests pass:
AVM1 goto/rewind (15/15: goto_rewind1/2/3, execution_order1/2/3,
goto_execution_order/2, goto_both_ways1/2, rewind_depth, goto_frame,
goto_frame2, goto_label, goto_methods); AVM1 unload/init (11/11:
unload, unloadmovie, unload_clip_event, unload_nested_child,
mcl_unloadclip, clip_events, on_construct, register_and_init_order,
init_object_order, set_interval, movieclip_state_values); AVM1 misc
(4/4: depth_replacement_audio_unloading, textsnapshot_available_text,
movieclip_in_removed_button, conflicting_instance_names);
misc-ming.all loop battery (6/6 pass on the in-guardrail subset
loop_test2/3/5/8/9/simple_loop_test) plus pre-existing pre-Phase-B
status preserved on out-of-guardrail loops (loop_test, loop_test6,
loop_test10 still output_mismatch; loop_test4 pass; loop_test7
ruffle_matched); misc-ming.all flat (9/9 in-guardrail —
DefineEditTextTest, DefineEditTextVariableNameTest2,
ResolveEventsTest, attachMovieTest, event_handler_scope_test,
instanceNameTest, new_child_in_unload_test, static_vs_dynamic1/2);
misc-swfc battery (3/3 in-guardrail: stackscope, submoviegetvar,
edittext_test1; movieclip_destruction_test2 unchanged at
output_mismatch baseline 50/52); Shumway duplicateMovieClip suite
(4/4: duplicateMovieClip, samedepth, name-coercion, dontremove).

**Risk.** Zero functionally — confirmed. Queue is bounded
(MAX_PENDING_SPRITE_SCRIPTS=16) with silent drop-on-overflow;
end-of-tick reset prevents cross-tick leaks. Phase B does not modify
`swf_headless.c` — Phase H mirrors there.

### Phase C — Drain hook gated behind a runtime flag — COMPLETE 2026-04-26

**Scope.** Added a runtime flag `g_unify_sprite_drain_flag` (default 0)
in `action_queue.c` with `actionSetUnifySpriteDrain` setter and
`actionUnifySpriteDrain` getter. When set, the per-iteration scan
inside `actionDrainOnloadAndScript` first calls
`actionFlushPendingSpriteScriptsToScriptQueue` to transfer any pending
sprite-script entries (queued via `ng_gotoFrameCurrentSprite`) into the
`AQ_KIND_SCRIPT` bucket, where they FIFO-interleave with other queued
scripts. Default-off: with the flag at 0 the pending queue stays
untouched and is cleaned up at end of tick by the existing Phase B
reset. **Phase C does not flip the flag anywhere — Phase D does.**

To preserve the sprite's MC at dispatch time, `PendingSpriteScriptEntry`
was extended with `ctx_mc`/`ctx_base`/`ctx_sprite_obj` (typed `void*`
to keep the sprite_frame_scripts.h header free of libswf dependencies).
`actionQueuePendingSpriteScript` reads `g_current_context`,
`actionGetBaseClip()`, `g_current_sprite_obj` at push time. The new
helper `actionQueueSpriteScriptCaptured` in `action_queue.c` accepts
pre-captured context arguments — the existing `actionQueueSpriteScript`
is refactored as a thin wrapper that captures from globals. The flush
helper builds `PendingSpriteScript` payloads via the new captured-arg
variant so the dispatch context comes from goto-issue time, not
drain-side root context.

**Files changed.**
- `SWFModernRuntime/include/actionmodern/sprite_frame_scripts.h`:
  extended `PendingSpriteScriptEntry` with three `void*` ctx fields;
  added `actionFlushPendingSpriteScriptsToScriptQueue`.
- `SWFModernRuntime/src/actionmodern/sprite_frame_scripts.c`:
  capture context globals at push time; implement flush helper.
- `SWFModernRuntime/include/actionmodern/action_queue.h`:
  declared `actionQueueSpriteScriptCaptured`,
  `actionSetUnifySpriteDrain`, `actionUnifySpriteDrain`.
- `SWFModernRuntime/src/actionmodern/action_queue.c`:
  added `g_unify_sprite_drain_flag` + accessors;
  refactored `actionQueueSpriteScript` to delegate to
  `actionQueueSpriteScriptCaptured`;
  per-iteration flush hook in `actionDrainOnloadAndScript` gated on
  the flag.

**Behavior delta.** None visible. With `g_unify_sprite_drain_flag=0`
(default), `actionDrainOnloadAndScript`'s flush call is a flag check
that never executes the transfer. `consecutive_goto_frame_test`
unchanged at 4/12 baseline. Captured context fields are populated
in the queue but ignored because the queue is drained (reset, not
dispatched) at end of tick.

**Verification.** 4/12 baseline preserved on
`consecutive_goto_frame_test`. Guardrail (no regressions): 15/15 AVM1
goto/rewind/clip_events (goto_rewind1/2/3, execution_order1/2/3,
goto_execution_order/2, goto_both_ways1/2, goto_frame, goto_frame2,
goto_label, goto_methods, clip_events); 11/11 AVM1 unload/init
(unload, unloadmovie, unload_clip_event, unload_nested_child,
mcl_unloadclip, register_and_init_order, on_construct,
init_object_order, set_interval, movieclip_state_values,
rewind_depth); 11/11 misc-ming flat (attachMovieTest, instanceNameTest,
DefineEditTextTest, DefineEditTextVariableNameTest2,
event_handler_scope_test, new_child_in_unload_test,
static_vs_dynamic1/2, multi_doactions_and_goto_frame_test,
goto_frame_test, ResolveEventsTest); 7/9 misc-ming loop battery
(loop_test2/3/4/5/8/9/simple_loop_test pass; loop_test7
ruffle_matched; loop_test pre-existing fail unchanged); 4/4 Shumway
duplicateMovieClip (duplicateMovieClip, samedepth, name-coercion,
dontremove); 3/4 misc-swfc battery (stackscope, submoviegetvar,
edittext_test1 pass; movieclip_destruction_test2 unchanged at
50/52 — pre-existing baseline).

**Risk.** Zero in the default-off path — confirmed.

### Phase D — Flip g_unify_sprite_drain=1 — COMPLETE 2026-04-26

**Scope.** Set `g_unify_sprite_drain=1` globally by changing the
default of `g_unify_sprite_drain_flag` in
`SWFModernRuntime/src/actionmodern/action_queue.c` from 0 to 1.
`actionSetUnifySpriteDrain` is the public setter but is never called
externally, so flipping the default is the cleanest activation path.

**Behavior delta on target test.** `consecutive_goto_frame_test`
shifted from 4 matching lines to 3 — the queueing now fires
sprite scripts in sequence (`frm1/frm2/frm3 of mc_red`
gotoAndStop traces appear adjacent at the start) but they cluster
*before* root re-entry, so the expected interleaved
`PASSED ... frm3 of root ...` ordering still doesn't match. As
predicted in the plan, Phase D alone is insufficient — Phases E and F
must land for the test to reach 12/12.

**Verification.** No guardrail regressions. Tested:
- AVM1 goto/rewind: 15/15 PASS (`goto_rewind1/2/3`,
  `execution_order1/2/3`, `goto_execution_order/2`,
  `goto_both_ways1/2`, `rewind_depth`, `goto_frame`, `goto_frame2`,
  `goto_label`, `goto_methods`).
- AVM1 unload + init: 12/12 PASS (`unload`, `unloadmovie`,
  `unload_clip_event`, `unload_nested_child`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`, `clip_events`, `on_construct`,
  `register_and_init_order`, `init_object_order`, `set_interval`,
  `movieclip_state_values`).
- misc-ming loop battery: 7 PASS + 1 ruffle_matched + 3 pre-existing
  output_mismatch (`loop_test`, `loop_test6`, `loop_test10` —
  unchanged from Phase B/C baseline).
- misc-ming flat: 17/17 PASS (`DefineEditTextTest`,
  `DefineEditTextVariableNameTest2`, `ResolveEventsTest`,
  `attachMovieTest`, `event_handler_scope_test`, `instanceNameTest`,
  `new_child_in_unload_test`, `static_vs_dynamic1/2`,
  `displaylist_depths_test11`, `place_and_remove_object_test`,
  `shape_test`, `get_frame_number_test`,
  `action_execution_order_test8-v5/v6`,
  `reverse_execute_PlaceObject2_test1/2`).
- Shumway duplicateMovieClip: 4/4 PASS.
- misc-swfc: 3 PASS + `movieclip_destruction_test2` unchanged at 50/52.

**Risk.** High — first behavior change. Cleared local guardrail; CI
roundtrip should confirm no regressions outside the local guardrail.

**CI regressions (2 — under stop threshold).** CI run 24971025400
caught two AVM1 regressions that the local guardrail didn't touch:

| Test | Prev | Now | Notes |
|------|------|-----|-------|
| `avm1/issue_9885` | PASS (2/2) | timeout | Sprite goto inside `tellTarget`; runtime now hangs >10s. Likely a re-queue loop in the unified drain (sprite-frame script gets re-flushed each iteration). |
| `avm1/tell_target_invalid_swf6` | PASS (5/5) | output_mismatch (5/6) | Extra trailing `This should only be reached in SWF6 and below` line — the SWF6-only frame's script fires twice instead of once under unified drain. |

Both reproduce locally only after wiping the cached `RecompiledScripts`
/ `RecompiledTags` directories — the earlier "PASS" of these tests
during the local guardrail used stale Phase-C-built artifacts. Both
are accepted as Phase D fallout to be addressed in Phase E/F (Phase E's
catch-up inline + drain-suppress wrap should defang the re-queue loop;
Phase F's eager-init queueing should normalize the double-fire).

**Stop criterion (not triggered).** If regressions exceed ~5 unrelated
tests, revert the flip and document; that pivots back to investigating
a narrower flag scope. We saw 2 — well under threshold.

### Phase E — ng_executeGotoCatchUp: inline funcs[target] with drain-suppress — COMPLETE 2026-04-26

**Scope.** Same as Phase 2 of the original plan. After catch-up tags,
wrap `funcs[target](app_context)` in
`actionDrainSuppressEnter/Leave` with `g_tag_skip_mode=1`. Don't push
into `g_deferred_goto_queue`. Target script lands in `AQ_KIND_SCRIPT`,
drains via the outer recompiler-emitted drain in FIFO order.

**Files changed.**
- `SWFModernRuntime/src/libswf/swf_core.c`: introduced
  `g_skip_inline_target_script` one-shot flag (next to existing
  `g_deferred_goto_*` declarations). Replaced the
  `g_deferred_goto_queue` push at the end of `ng_executeGotoCatchUp`
  with an inline `funcs[target](app_context)` call wrapped in
  `actionDrainSuppressEnter/Leave` and `g_tag_skip_mode=1`. The flag
  gates the inline call so callers that need the target's script
  suppressed (gotoAndStop(9999) clamp) opt out.
- `SWFModernRuntime/src/actionmodern/action.c`: `actionGotoFrame`'s
  `was_clamped` block now sets `g_skip_inline_target_script = 1`
  before calling `ng_executeGotoCatchUp` instead of post-call
  decrementing the deferred queue (which Phase E no longer fills).

**Companion fix (sibling Phase D fallout).** While verifying Phase E
against the issue_9885 timeout, traced the loop to a pre-existing
`actionSetTarget2` bug surfaced by Phase D. The MOVIECLIP-typed top
of stack path (`SetTarget2` invoked with a MovieClip already on the
stack — e.g. `_root.gotoAndStop(N)` compiled as
`Push("_root"); GetVariable; SetTarget2; ...`) bypassed the
`g_settarget_explicit_root` bookkeeping that the string path sets.
Subsequent `GotoFrame` inside a sprite script then fell through to
`ng_gotoFrameCurrentSprite` instead of the root catch-up branch;
under Phase D's unified drain the sprite script re-queued itself
indefinitely. Fixed in `actionSetTarget2` to mirror `actionSetTarget`'s
flag set after `setCurrentContext`, so `g_settarget_explicit_root` is
1 when the target is `_root` and 0 otherwise.

**Behavior delta on target test.** `consecutive_goto_frame_test` 12/12
PASS — Phase E delivered the target ahead of Phase F. Phase D
regression `avm1/issue_9885` (timeout) is fixed by the actionSetTarget2
companion fix.

**Verification.** Local guardrail (Phase E + actionSetTarget2 fix):
- AVM1 `consecutive_goto_frame_test`: PASS (12/12 — was 3/12 in Phase D).
- AVM1 `issue_9885`: PASS (was timeout in Phase D).
- AVM1 `tell_target_invalid_swf6`: still output_mismatch 5/6
  (extra trailing trace) — Phase F double-fire normalization needed.
- Predicted Phase E regressions, all expected per plan
  ("tests that exercise the deferred-goto-queue drain ordering"):
  `goto_rewind2`, `goto_rewind3`, `execution_order2`, `execution_order3`,
  `goto_execution_order2`, `goto_both_ways1` — Phase F predicted to fix.
- AVM1 unload + init guardrail: 13/14 PASS (1 mismatch, pre-existing
  on a goto-related test).
- Shumway duplicateMovieClip: 4/4 PASS.
- Other guardrail batches verified as part of the post-commit run.

**Risk.** Medium-high (acknowledged in plan). The drain-suppress
primitive (foundation) is in place, so re-entry is bounded. Phase F
must address the predicted regressions before this is shippable as a
single-phase improvement, but Phase E commits cleanly because the
regressions are scoped to the documented set.

### Phase F — Phase 4 gate simplification + sprite eager-init force-queue — COMPLETE 2026-04-26

**Scope.** Two coupled changes (different from the original plan's
literal `g_tag_skip_mode=1` proposal — that approach would short-circuit
inner placements via `tagPlaceObject2`'s `if (g_tag_skip_mode) return;`
guard). The shipped form:

1. Recompiler gate at `swf.cpp:5013-5031` rewrites the AND-with-ELSE
   construct to a single OR with four queue-triggering signals:
   ```c
   if (!catch_up_mode || g_tag_skip_mode ||
       (actionEagerInitActive() && !actionGotoCatchupActive()) ||
       (actionScriptOnlyMode() && actionDeferredSpriteInitActive()))
       actionQueueSpriteScript(app_context, script_name);
   ```
   The pre-Phase-F gate guarded with `&& !actionScriptOnlyMode()` and
   relied on a separate ELSE branch (`else if (!catch_up_mode &&
   actionScriptOnlyMode() && actionDeferredSpriteInitActive())
   script_name(app_context);`) for sync-fire. Phase F merges those into
   one queue-only path: the Phase-2 deferred re-run now QUEUES via the
   `actionScriptOnlyMode() && actionDeferredSpriteInitActive()`
   disjunct, so sprite scripts FIFO-interleave with the target frame's
   root DoAction at the outer drain instead of firing synchronously.
2. `ng_executeGotoCatchUp` (`SWFModernRuntime/src/libswf/swf_core.c`)
   wraps Phase E's inline `funcs[target]` call with explicit phase 1/3
   sprite init invocations:
   ```c
   ng_run_deferred_sprite_init_before(app_context, target);
   /* Phase E: g_tag_skip_mode=1 + drain-suppress + funcs[target] */
   ng_run_deferred_sprite_init_on_or_after(app_context, target);
   ```
   These were previously called only from the
   `g_deferred_goto_queue/_script` outer-drain loop in `swf_core.c:1110-
   1153` — that loop went dead after Phase E removed the queue push, so
   sprite eager-init scripts queued under goto catch-up never fired.
   Phase F restores the 3-phase ordering (Phase 1 sprites BEFORE target
   queue first, target script queues mid, Phase 3 sprites AT/AFTER
   target queue last) inline in `ng_executeGotoCatchUp`. The outer drain
   loop is now functionally redundant — Phase G retires it.
   `g_defer_sprite_init` is locally cleared/restored around the wrap so
   Phase 1/3 calls can actually iterate.

**Behavior delta on target test.** `consecutive_goto_frame_test` 12/12
PASS preserved (Phase E delivered this; Phase F doesn't regress it).
Phase E's predicted regressions are all fixed:

| Test | Phase E | Phase F |
|------|---------|---------|
| `execution_order2` | 3/7 | PASS (7/7) |
| `execution_order3` | 2/4 | PASS (4/4) |
| `goto_rewind2` | 2/3 | PASS (3/3) |
| `goto_rewind3` | 1/2 | PASS (2/2) |
| `goto_execution_order2` | 0/2 | PASS (2/2) |
| `goto_both_ways1` | 1/3 | PASS (3/3) |

**Verification.** Local guardrail (Phase F):
- AVM1 36-test guardrail (goto/rewind/unload/init-order/clip-events/
  goto_execution_order/conflicting_instance_names/movieclip_in_removed_button/
  button_order/textsnapshot_available_text/bad_placeobject_clipaction/
  tell_target_invalid* + issue_9885 + issue_1104): 35/36. Only
  unchanged failure: `tell_target_invalid_swf6` (5/6 — pre-existing
  Phase D fallout, NOT a new regression; same trailing-line shape it
  had after Phase D's flip).
- AVM1 sanity: 9/9 (add, add2, arguments, array_concat,
  as1_constructor_v6, as2_oop, attach_movie, as2_super_and_this_v6,
  as_broadcaster).
- AVM1 super/closure: 12/12 (swf5_to_6_cross_call, swf5_no_closure,
  as2_super_and_this_v6/v8, extends_chain, goto_rewind1/2/3,
  execution_order2/3, as2_oop, add).
- Misc-ming flat: 14/14 (static_vs_dynamic1/2,
  place_and_remove_object_test, new_child_in_unload_test,
  event_handler_scope_test, instanceNameTest, attachMovieTest,
  DefineEditTextTest, DefineEditTextVariableNameTest2, shape_test,
  get_frame_number_test, reverse_execute_PlaceObject2_test1/2,
  ResolveEventsTest).
- Misc-ming loop: 7 PASS + 1 ruffle_matched + 3 pre-existing
  output_mismatch (loop_test/loop_test6/loop_test10 — same as
  baseline).
- Misc-ming displaylist_depths: 6/9 (same as baseline:
  displaylist_depths_test/test2/test3 pre-existing fail).
- Misc-ming action_order: action_execution_order_test8-v5 + v6 PASS
  (regained — these had stale-artifact false-fail until fresh
  recompile).
- Misc-ming consecutive_goto_frame_test, multi_doactions_and_goto_frame_test,
  goto_frame_test: 3/3 PASS.
- Misc-swfc: 3 PASS + button_test1/movieclip_destruction_test2 at
  pre-existing baselines (50/52 unchanged on destruction_test2).
- Shumway duplicateMovieClip: 4/4 (duplicateMovieClip, samedepth,
  name-coercion, dontremove).

**Risk.** Bounded — within stop-criterion threshold of "~5 unrelated
tests with unclear fix paths". Single unchanged Phase D fallout
(`tell_target_invalid_swf6`).

**Note on the `g_tag_skip_mode=1` rewrite.** The plan's original
literal proposal was to set `g_tag_skip_mode=1` around
`sprite_X_frame_0(app_context)` in tagPlaceObject2's eager-init block.
Investigation showed `tagPlaceObject2`'s `if (g_tag_skip_mode) return;`
guard at line 3667 would short-circuit inner sprite placements (the
sprite's own children would never get placed under `g_tag_skip_mode=1`).
The shipped form preserves the eager-init wrapper as-is and instead
extends the recompiler gate to recognize the
`(actionScriptOnlyMode() && actionDeferredSpriteInitActive())`
combination — Phase 2 deferred re-run brackets that combination via
`ng_run_deferred_sprite_init_impl`'s existing
`actionDeferredSpriteInitEnter`. This achieves the same end (sprite
scripts queue during goto catch-up at the right FIFO position) without
breaking placements.

**Follow-up fix 1 — `actionAttachInitActive`.** The first Phase F gate
`((actionScriptOnlyMode() && actionDeferredSpriteInitActive()))`
collapsed two distinct deferred-init paths into one queue branch:

- goto Phase 2 deferred init (set by
  `ng_run_deferred_sprite_init_impl`) — must QUEUE so sprite scripts
  FIFO-interleave with the inline target-frame DoAction.
- runtime-attach Phase 2 deferred init (set by
  `aq_dispatch_pending_attach_init` in `tag_stubs.c:259-282`) — must
  SYNC-FIRE to preserve the PAI dispatch ordering. (Comment on line
  273-276 explicitly documents the `default_names` regression that was
  originally fixed by adding the sync-fire ELSE to this path.)

Both paths share the same flag set
(`actionScriptOnlyMode + actionDeferredSpriteInitActive`), so the gate
couldn't tell them apart. Phase F's first iteration broke the attach
sync-fire and regressed `attach_movie` 59→55, `default_names` 52→42,
and `removed_target_clip_scope` 35→8 in the CI run.

The fix adds a separate `actionAttachInitActive()` flag whose
`Enter/Leave` brackets are used only by
`aq_dispatch_pending_attach_init`. The recompiler gate now keys off it:

```c
if (!actionAttachInitActive() && (!catch_up_mode || g_tag_skip_mode ||
    (actionEagerInitActive() && !actionGotoCatchupActive()) ||
    (actionScriptOnlyMode() && actionDeferredSpriteInitActive())))
    actionQueueSpriteScript(app_context, script_name);
else if (actionAttachInitActive() && actionScriptOnlyMode() &&
    actionDeferredSpriteInitActive())
    script_name(app_context);
```

`!actionAttachInitActive()` prefixes the entire queue branch so attach
init never queues, restoring the previous sync-fire path. After this
fix all three CI regressions are recovered.

**Follow-up fix 2 — `advance_sprite_frames` double-queue.** Phase B
queues sprite-script entries via `actionQueuePendingSpriteScript`
inside `ng_gotoFrameCurrentSprite`; Phase D's flip
(`g_unify_sprite_drain_flag=1`) made these flush into AQ_KIND_SCRIPT
on every drain. But `advance_sprite_frames`' manual-goto branch in
`tag.c` (forward and backward goto loops) ALSO calls
`sprite_frame_funcs[target](app_context)` with `catch_up_mode=0` — and
under `catch_up_mode=0` the recompiler-emitted gate still queues.
Result: post-Phase-D every sprite goto via `GotoFrame`/`GotoFrame2`
double-queued the target script. `tell_target_invalid_swf6` showed it
clearly (5/5 → 5/6 since Phase D — extra trailing trace). Other tests
masked it because one of the two fires landed before output diff
boundaries.

The fix forces `catch_up_mode = 1` for the entire
`advance_sprite_frames` manual-goto loop (both forward and backward
branches). Tags still execute (placement happens), but the gate's
`!catch_up_mode` term doesn't fire, so the target script is queued
exactly once — by Phase B's pending sprite-script queue. Backward
goto needed a parallel `int saved_bw_cm` save/restore since that
branch had previously been a passive inheritor of the caller's
`catch_up_mode`.

After both follow-ups: AVM1 44-test guardrail 44/44, misc-ming flat
17/17, misc-ming loop battery preserved at baseline (7 PASS + 1
ruffle_matched + 3 unchanged output_mismatch),
`tell_target_invalid_swf6` recovered to PASS.

**Follow-up fix 3 — `!catch_up_mode` constraint on attach sync-fire.**
The first follow-up's gate ELSE
(`actionAttachInitActive() && actionScriptOnlyMode() && actionDeferredSpriteInitActive()`)
fired sync-fire even under `catch_up_mode=1`. Phase E's pre-Phase-F gate
had explicit `!catch_up_mode` on the sync-fire ELSE
(`!catch_up_mode && actionScriptOnlyMode() && actionDeferredSpriteInitActive()`),
so attach Phase 2 paths under catch-up silently dropped. My follow-up
restored sync-fire universally — which broke
`removed_clip_halts_script` (15/15 → 3/15) by sync-firing an extra
"clip 3" trace during a goto catch-up that re-entered the attach Phase 2
machinery.

The fix adds `!catch_up_mode &&` to the sync-fire ELSE so it matches
Phase E's "fire only outside catch-up" behavior:

```c
else if (!catch_up_mode && actionAttachInitActive() &&
    actionScriptOnlyMode() && actionDeferredSpriteInitActive())
    script_name(app_context);
```

Verified: AVM1 23-test critical-path battery 23/23 (incl. all 4 attach
tests + tell_target_invalid_swf6 + 12 goto/init tests), misc-ming
flat 17/17, loop battery at baseline, Shumway duplicateMovieClip 4/4.

### Phase G — Retire g_deferred_goto_queue + outer drain loop — COMPLETE 2026-04-27

**Scope.** Same as Phase 3 of the original plan. Removed the
`g_deferred_goto_queue` array, the count
(`g_deferred_goto_queue_count`), the trailing-target tracker
(`g_deferred_goto_target`), the `g_deferred_goto_script` flag, and the
`MAX_DEFERRED_GOTO_QUEUE` macro from `swf_core.c`. Replaced the
3-phase deferred goto drain loop in `swf_core.c:1124-1173` with a
short comment explaining the retirement. Phase E moved every push site
inline into `ng_executeGotoCatchUp` and Phase F restored the surrounding
sprite Phase 1/3 init calls there, so the outer drain block had been
dead code since Phase E. Loop-exit conditions did not need updating —
the `g_deferred_goto_queue_count > 0` term only existed inside the
retired drain loop itself; the `for(;;)` retry around catch-up still
keys off `goto_from_action && manual_next_frame`, which
`ng_executeGotoTagsOnly` continues to set when a deferred script
triggers another goto.

**Behavior delta.** None functionally — confirmed.

**Verification.** Local guardrail (Phase G):
- AVM1 30-test goto/rewind/unload/init guardrail (`goto_rewind1/2/3`,
  `execution_order1/2/3`, `goto_execution_order/2`,
  `goto_both_ways1/2`, `rewind_depth`, `goto_frame`, `goto_frame2`,
  `goto_label`, `goto_methods`, `unload`, `unloadmovie`,
  `unload_clip_event`, `unload_nested_child`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`, `clip_events`, `on_construct`,
  `register_and_init_order`, `init_object_order`, `set_interval`,
  `movieclip_state_values`, `tell_target_invalid_swf6`, `issue_9885`,
  `issue_1104`): 30/30 PASS.
- Misc-ming 27-test battery (loop_test/2/3/5/7/8/9, simple_loop_test,
  static_vs_dynamic1/2, displaylist_depths_test11,
  place_and_remove_object_test, new_child_in_unload_test,
  event_handler_scope_test, instanceNameTest, attachMovieTest,
  DefineEditTextTest, DefineEditTextVariableNameTest2, shape_test,
  get_frame_number_test, reverse_execute_PlaceObject2_test1/2,
  action_execution_order_test8-v5/v6, consecutive_goto_frame_test,
  multi_doactions_and_goto_frame_test, goto_frame_test):
  25 PASS + 1 ruffle_matched (loop_test7) + 1 unchanged
  output_mismatch (loop_test — pre-existing baseline failure noted in
  Phase F).
- Misc-swfc 4-test battery (stackscope, submoviegetvar, edittext_test1
  pass; movieclip_destruction_test2 unchanged at 50/52 — pre-existing
  baseline).
- Shumway duplicateMovieClip 4/4 PASS.

**Risk.** Low — pure cleanup, confirmed.

### Phase H — swf_headless.c parity — COMPLETE 2026-04-27

**Scope.** Applied Phase E + F + G changes to `swf_headless.c`'s
mirror of `ng_executeGotoCatchUp` and the per-tick outer drain loop:

1. Retired the `g_deferred_goto_queue`/`_count`/`_script`/`_target`
   declarations and the `MAX_DEFERRED_GOTO_QUEUE` macro in the file
   header. Added the Phase E `g_skip_inline_target_script` one-shot
   flag (declaration mirrors `swf_core.c`).
2. Replaced the trailing queue push at the end of the original
   `ng_executeGotoCatchUp` with the Phase E inline `funcs[target]`
   call wrapped in `actionDrainSuppressEnter/Leave` and
   `g_tag_skip_mode=1`, plus the Phase F surrounding
   `ng_run_deferred_sprite_init_before/_on_or_after` calls and
   `g_defer_sprite_init` save/restore. Also added the
   `actionGotoCatchupEnter/Leave` brackets around the catch-up replay
   loop (Phase 7b machinery) which were already present in
   `swf_core.c`.
3. Removed the outer 3-phase drain `while` loop from the per-tick
   `for(;;)` retry, replacing it with the same short retirement
   comment used in `swf_core.c`.
4. Mirrored the Phase E goto-retry-limit safety guard (`int
   goto_retry_limit = 16; if (--goto_retry_limit <= 0) break;`) added
   to the per-tick outer `for(;;)` retry — `swf_headless.c` had been
   missing this.

**Behavior delta.** None unless `--headless` mode is in use, in which
case it now matches NO_GRAPHICS (`swf_core.c`) goto FIFO semantics.

**Verification.** `swf_headless.c` compiles cleanly standalone with
the same flags `verify_output.py` uses
(`-DNO_GRAPHICS -DHEADLESS_GRAPHICS -DUSE_WEBGPU -DNDEBUG
-D_GNU_SOURCE -O2 -std=c17`) — confirmed via standalone `gcc -c` build
in /tmp. No-op for NO_GRAPHICS tests (the file is not linked).
Headless image tests cannot be executed locally on this WSL2
environment (Dawn/lavapipe linker fails — pre-existing, reproduces
unchanged on master with Phase H reverted), so headless behavior
verification relies on CI's headless image-test suite per the plan's
documented fallback.

**Risk.** Low — symmetric with E + F + G; Phase H is a literal port of
those changes to a sibling file with no behavior gates.

## Required-pass guardrail (any session that flips behavior)

These tests must not regress after Phases D, E, or F. List from the
original plan's Phase 6:

- AVM1 goto/rewind: `goto_rewind1/2/3`, `execution_order1/2/3`,
  `goto_execution_order/2`, `goto_both_ways1/2`, `rewind_depth`,
  `goto_frame`, `goto_frame_test`, `goto_frame2`, `goto_label`,
  `goto_methods`, `goto_methods_to_label`.
- AVM1 unload: `unload`, `unloadmovie`, `unload_clip_event`,
  `unload_nested_child`, `mcl_unloadclip`,
  `depth_replacement_audio_unloading`.
- Misc-ming: `loop/loop_test2/3/5/8/9`, `simple_loop_test`,
  `static_vs_dynamic1/2`, `displaylist_depths_test11`,
  `place_and_remove_object_test`, `new_child_in_unload_test`,
  `event_handler_scope_test`, `instanceNameTest`, `attachMovieTest`,
  `DefineEditTextTest`, `DefineEditTextVariableNameTest2`,
  `shape_test`, `get_frame_number_test`,
  `reverse_execute_PlaceObject2_test1/2`,
  `action_execution_order_test8-v5/v6`.
- Shumway duplicateMovieClip: `dontremove`, `duplicateMovieClip`,
  `samedepth`, `name-coercion`.
- Misc-swfc: `movieclip_destruction_test2` (50/52 baseline),
  `stackscope`, `submoviegetvar`, `edittext_test1`.
- Init-order: `register_and_init_order`, `on_construct`,
  `init_object_order`, `clip_events`.

## Estimated session budget

| Phase | Effort | CI roundtrip needed? |
|-------|--------|----------------------|
| A | 1-2 hr | Optional (zero-risk) |
| B | 1-2 hr | Optional |
| C | 1 hr | Optional |
| D | 2-3 hr | **Yes** — first behavior change |
| E | 2-3 hr | **Yes** |
| F | 3-4 hr | **Yes** — highest regression risk |
| G | 1 hr | Yes (cleanup) |
| H | 30 min | Yes (headless suite) |

Total: 12-17 hours across 6-8 sessions. Each session has a clean
stopping point (commit + push or revert).

## Open questions (carried over from original plan)

1. **Eager-init timing under unified FIFO** — see original plan's open
   question 1.
2. **Nested goto: sprite-frame calling `_root.gotoAndStop`** — see
   original plan's open question 2.
3. **Drain reentry during catch-up tag replay** — addressed by
   `actionDrainSuppressEnter/Leave`; verify no new re-entry sites in
   Phase E.
4. **Loop-exit conditions** — addressed in Phase G.

## Why this is the right shape

The original plan tried to land everything atomically because the FIFO
order is a global invariant — partial implementations don't preserve it.
The reframe trades one atomic commit for two atomic commits (Phase D
flip and Phase F gate change), but separates them with infrastructure
sessions that build the necessary primitives **without** committing to
the new behavior. That makes regressions traceable to a single change
rather than a tangled atomic.

## Related docs

| Doc | Relationship |
|-----|--------------|
| `blocked/GOTO_FIFO_UNIFICATION_PLAN.md` | Architectural reference. Don't implement it directly — implement THIS plan, which preserves its FIFO-order analysis but ships in shippable units. |
| `complete/DRAIN_SUPPRESS_PRIMITIVE_PLAN.md` | Foundation for Phase E's drain-suppress wrap. |
| `incomplete/DEFERRED_CLIP_UNLOAD_PLAN.md` | Sensitive to Phase D/E/F drain-timing changes. Cross-check after each behavior phase. |
| `incomplete/TRANSFORMED_BY_SCRIPT_WRAP_BACK_PLAN.md` | Independent code paths but shares catch-up machinery. Spot-check during Phase E. |
| `PLAN_DEPENDENCIES.md` | Index — update when this plan moves buckets. |
