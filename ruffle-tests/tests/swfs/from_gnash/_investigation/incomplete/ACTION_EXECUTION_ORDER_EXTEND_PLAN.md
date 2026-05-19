# action_execution_order_extend_test Plan
<!-- TESTS: misc-ming.all/action_order/action_execution_order_extend_test -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: ACTION_EXECUTION_ORDER_EXTEND_PLAN
status: pending
phases:
  - id: 1
    name: "Missing 'mc_red load executed' line at expected position"
    status: pending
  - id: 2
    name: "enterFrame ordering: mc_blu fires before mc_red instead of after"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: SPRITE_EXEC_LIST_LIFO_PLAN
    reason: "Phase 2 (enterFrame ordering) is exactly the LIFO-vs-FIFO sprite-exec-list issue. Once that plan lands, this test likely auto-fixes."
  - id: ENTERFRAME_DISPATCH_PLAN
    reason: "AVM1 plan (complete) — 18 tests pass for clip events. This test exercises specific nested-sprite ordering."
blockers: []
status_note: |
  Two small bugs revealed by the test:
  (1) 'mc_red load executed' is missing entirely from our output
      (likely a CLIP_EVENT_LOAD vs DoAction ordering issue —
      we fire the DoAction first).
  (2) enterFrame dispatch order reverses parent vs child (we fire
      mc_red first, then mc_blu; Flash fires mc_blu first then
      mc_red).
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/action_order/action_execution_order_extend_test | 8/32 | 25.0% | output_mismatch |

## Failure surface

```
  Expected:                          Actual:
7   mc_red clip load executed         mc_red clip load executed
8   mc_red load executed              as in frame1 of mc_red       <- shifted
9   as in frame1 of mc_red            as in frame1 of mc_blu       <- shifted
10  as in frame1 of mc_blu            as in frame2 of mc_blu       <- shifted
11  mc_blu enterFrame executed        mc_blu enterFrame executed
12  as in frame2 of mc_blu            mc_red enterFrame executed   <- wrong order
13  mc_red enterFrame executed        as in frame2 of mc_red       <- shifted
14  as in frame2 of mc_red            as in frame3 of root         <- shifted
15  as in frame3 of root              PASSED: ...
```

Two distinct bugs cluster here:

1. **Missing `mc_red load executed`.** The `clip load executed`
   line (CLIP_EVENT_LOAD via `onClipLoad`) fires; the bare `load
   executed` line (an `onLoad` handler — sprite-scope) doesn't.
   Suggests `onLoad` and `onClipLoad` aren't both being dispatched
   when a sprite has both.

2. **enterFrame parent-vs-child order reversed.** Flash fires
   `mc_blu.onEnterFrame` (child) before `mc_red.onEnterFrame`
   (parent). We fire mc_red first. Same LIFO-vs-FIFO root cause as
   `loop_test2`/`loop_test3`/`action_execution_order_test11`/
   `ActionOrderTest3` — all covered by SPRITE_EXEC_LIST_LIFO_PLAN.

## Recommended fix order

1. **Phase 2 (LIFO ordering)** — once SPRITE_EXEC_LIST_LIFO_PLAN
   lands, expect re-baseline to show only Phase 1 remaining.
2. **Phase 1 (`onLoad` dispatch)** — small diagnosis: trace the
   load-event dispatch path and see why `onLoad` (script-scope
   handler) isn't firing alongside `onClipLoad` (clip-event).
   Probably a one-line registration miss. Estimate: 1-2 hours.

Total estimate: 1-2 hours once SPRITE_EXEC_LIST_LIFO lands. May
auto-resolve to ruffle_matched without code change if Ruffle
shares both bugs.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt`. Check subset-match
during Phase 2 diagnosis.
