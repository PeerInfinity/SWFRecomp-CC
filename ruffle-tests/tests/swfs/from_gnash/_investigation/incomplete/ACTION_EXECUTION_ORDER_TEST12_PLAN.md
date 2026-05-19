# action_execution_order_test12 Plan
<!-- TESTS: misc-swfc.all/action_execution_order_test12 -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: ACTION_EXECUTION_ORDER_TEST12_PLAN
status: pending
phases:
  - id: 1
    name: "Unload event ordering: mc1.mc11 unload fires before mc2.mc21 unload"
    status: pending
  - id: 2
    name: "enterFrameOrder: extra '4+' / '5+' frame indices emitted"
    status: pending
  - id: 3
    name: "loadOrder + asOrder: missing/extra entries"
    status: pending
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
  Sibling of action_execution_order_test2..11 (sibling plan
  DEFERRED_CLIP_UNLOAD_PLAN complete, covers 2/3/5/11). This
  test12 was newly visible via SUBTESTS_HARNESS and wasn't
  included in the original cluster. The same root causes likely
  apply but specific failures need fresh diagnosis.
-->

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
