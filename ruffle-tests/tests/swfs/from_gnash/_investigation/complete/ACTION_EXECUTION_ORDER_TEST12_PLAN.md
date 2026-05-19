# action_execution_order_test12 Plan
<!-- TESTS: misc-swfc.all/action_execution_order_test12 -->

Last updated: 2026-05-19 (RESOLVED — test promoted to ruffle_matched
via two fixes in `tag.c`; see "Resolution" below)

<!-- PLAN_META
id: ACTION_EXECUTION_ORDER_TEST12_PLAN
status: complete
phases:
  - id: 1
    name: "Unload event ordering: inner-sprite loop-back fires onUnload"
    status: complete
  - id: 2
    name: "enterFrameOrder: extra '4+' / '5+' frame indices emitted"
    status: complete
  - id: 3
    name: "loadOrder: spurious onLoad for plain exported timeline sprites"
    status: complete
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: DEFERRED_CLIP_UNLOAD_PLAN
    reason: "Complete plan covering action_execution_order_test2/3/5/11 (sibling tests). test12 is the next entry in that family and likely shares some root causes."
  - id: SPRITE_EXEC_LIST_LIFO_PLAN
    reason: "enterFrame ordering interacts with sprite exec list LIFO."
blockers: []
status_note: |
  RESOLVED 2026-05-19. test12 → ruffle_matched (effective pass).
  Two fixes in SWFModernRuntime/src/libswf/tag.c. Phase 2 fell out
  of the Phase 1 fix for free (invalidating the loop-back children
  also stopped their spurious onEnterFrame).
-->

## Resolution (2026-05-19)

`misc-swfc.all/action_execution_order_test12` is now **ruffle_matched**
(effective pass). Two fixes, both in `SWFModernRuntime/src/libswf/tag.c`:

**Fix 1 — sprite loop-back fires child onUnload (Phases 1 + 2).**
`advance_sprite_frames`' natural loop-back (`frame == 0 && max_depth > 0`)
freed the looping sprite's child display-list entries *silently* — children
placed on inner frames (mc11/mc12/mc21) never got onUnload. Flash rewinds a
looping sprite to frame 0 via `run_goto`, which removes every object not in
frame 0 and fires their UNLOAD events. The fix queues, before the existing
free loop and gated `NO_GRAPHICS || OFFSCREEN_RENDER` + `!catch_up_mode`:
  - `actionQueueDynamicChildUnloads(loopback_mc)` — AS-level `onUnload`
    handlers for all descendants (queued FIRST, before invalidation, since
    `fire_recursive_child_unloads` sets `depth = INT_MIN` which makes
    `queueChildOnUnloads` skip the entry).
  - `fire_recursive_child_unloads(...)` — clip-action UNLOAD callbacks +
    cached-MC invalidation.
This also resolved Phase 2: invalidating the loop-back children stops their
(spurious) `onEnterFrame` from firing, so `enterFrameOrder` became
`0+1+2+3+1+2+3+1+2+1+2+` (Ruffle's value — a PASS).

**Fix 2 — onLoad only for actually-registered classes (Phase 3).**
The sprite-init path queued `actionQueueMCOnLoad` for any timeline-placed
sprite whose character had an export name (`ng_lookupExportName != NULL`).
Every swfc `.sprite` gets an export name, so plain sprites mc1/mc2 had their
`onLoad` queued; the handler — assigned by a later DoAction, *after* the
clip's LOAD already passed — was then found at drain time and fired
(`loadOrder` became `0+1+2+`). Flash never fires a post-load-assigned
`onLoad`. Fix: gate the `actionQueueMCOnLoad` on
`lookupRegisteredClassByCharId(char_id, swf_version, NULL) != NULL` —
`Object.registerClass` installs `onLoad` on the prototype *before*
placement, making it a valid LOAD-time handler; a plain exported `.sprite`
is not a registerClass sprite.

**Result.** Our output now matches Ruffle's `output.fp10.ruffle.txt`
byte-for-byte; the only diffs vs Gnash's `output.fp10.txt` are lines 17
(`enterFrameOrder` — Gnash itself fails this assertion) and 19
(`asOrder` — Ruffle itself fails this), exactly Ruffle's diff set, so the
test promotes via subset-match.

**Regression battery (43 tests, all status-stable).** 12 AVM1
(clip_events, issue_1104, on_construct, register_class_return_value,
register_and_init_order, default_names, goto_rewind3, execution_order2/3,
bad_placeobject_clipaction, button_order, movieclip_in_removed_button) +
13 AVM1 (looping, clip_event_propagation_order, duplicate_movie_clip,
attach_movie{,_stop}, mcl_unloadclip, movieclip_name_from_timeline,
movieclip_onconstruct, register_class{,_swf6}, register_and_init_order,
removed_clip_halts_script, depth_replacement_audio_unloading) + 21
misc-ming.all (all loop_test*, action_order test2/3/5/6/11 + ActionOrderTest3,
all register_class) + 10 misc-swfc.all (action_execution_order_test10/12,
movieclip_destruction_test1-4, registerclass_test3, soft_reference_test1,
button_test1, gotoFrameLabelAsFunction) — every test held its baseline
status; test12 promoted output_mismatch → ruffle_matched.

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-swfc.all/action_execution_order_test12 | 9/22 | 40.9% | output_mismatch |

## Failure surface

The test runs nested MovieClips with onLoad / onEnterFrame /
onUnload handlers, recording the order in `_root.loadOrder`,
`enterFrameOrder`, `unloadOrder`, `asOrder` counters.

Expected unload sequence:
```
mc2.mc21 unloaded
mc1.mc11 unloaded
mc1.mc12 unloaded
mc1 unloaded
mc2 unloaded
```

Actual unload sequence:
```
mc1.mc12 unloaded         <- mc1.mc11 missing entirely
mc1 unloaded
mc2 unloaded
```

Counters:
- `loadOrder == 0+` expected (only initial load counts in this
  test), actual `0+1+2+`. We are counting too many loads.
- `enterFrameOrder` expected `0+1+2+3+1+2+3+1+2+1+2+`,
  actual `0+1+2+3+1+2+4+3+1+2+5+3+1+2+`. We emit extra `4+`,
  `5+` indices — looks like duplicate dispatches for some
  parent MCs.
- `unloadOrder` expected `0+1+2+3+4+5+`, actual `0+3+4+5+`.
  Missing 1+ and 2+ unload events.
- `asOrder` expected `0+1+2+3+4+`, actual `0+1+2+4+`. Missing
  `3+`.

## Approach

Sibling tests action_execution_order_test2/3/5/11 are passing
(or were before LOOP_TEST regressions). Compare against test11's
output structure (test11 has similar nested-unload assertions) —
the deltas should isolate which path is missing.

1. **Phase 1 (mc1.mc11 unload missing).** Likely the
   deferred-clip-unload ordering for *inner* nested MCs.
   Verify the `pending_finalize` queue records mc11's UNLOAD
   event when `mc1` is removed.

2. **Phase 2 (enterFrame extra dispatches).** Likely the
   LIFO-ordering issue where parent MC's onEnterFrame fires
   twice during a goto+unload sequence.

3. **Phase 3 (loadOrder / asOrder).** Probably falls out of
   Phase 1+2 fixes. Re-baseline after both land.

## Recommended fix order

1. Verify Phase 1 isn't covered by DEFERRED_CLIP_UNLOAD_PLAN
   already; if so the regression is recent. Check git log on
   `tag.c` / `action.c` around DEFERRED_CLIP_UNLOAD landing.
2. **Phase 1 (nested mc11 unload).** Estimate: 2-3 hours.
3. **Phase 2 (enterFrame duplicate dispatch).** Estimate: 1-2
   hours (likely shares root with LOOP_TEST_REGRESSION_PLAN —
   re-investigate after that lands).
4. **Phase 3** — re-baseline.

Total estimate: 3-5 hours, 1-2 sessions.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt`. 41% line match —
moderate work needed.
