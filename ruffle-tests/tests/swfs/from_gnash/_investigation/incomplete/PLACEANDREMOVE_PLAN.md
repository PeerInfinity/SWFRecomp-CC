# action_order/PlaceAndRemove Plan
<!-- TESTS: misc-ming.all/action_order/PlaceAndRemove -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: PLACEANDREMOVE_PLAN
status: pending
phases:
  - id: 1
    name: "PlaceObject+RemoveObject in same frame suppresses CONSTRUCT and DoAction"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: ACTION_EXECUTION_ORDER_TEST6_PLAN
    reason: "Same root cause: same-frame PlaceObject+RemoveObject pair semantics. test6's analysis applies here."
  - id: SPRITE_EXEC_LIST_LIFO_PLAN
  - id: DEFERRED_CLIP_UNLOAD_PLAN
blockers: []
status_note: |
  Test source places MovieClips with constructor-firing assertions
  AND immediately removes them within the same frame. Expected
  output is uniformly "Done" lines (15 of them) — no "moo N" or
  "This MovieClip should never be constructed" should leak. We
  emit those forbidden lines, indicating the same-frame Place+Remove
  is firing the constructor + DoAction when it shouldn't.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/action_order/PlaceAndRemove | 15/96 | 15.6% | output_mismatch |

## Failure surface

Expected output is uniformly `Done` lines:

```
Done
Done
Done
Done
...
```

We emit:

```
Done
moo 1                                           <- shouldn't appear
FAILED: This MovieClip should never be constructed  <- shouldn't appear
Done
moo 2                                           <- shouldn't appear
FAILED: ...
```

The "moo N" line comes from a DoAction in the placed-and-removed
sprite; the FAILED line comes from a CONSTRUCT-event assertion
explicitly designed to flag "this should never happen if
Place+Remove same-frame is correct."

## Approach

Same root cause as ACTION_EXECUTION_ORDER_TEST6 (q.v.): the
`aq_drain` filter at `action_queue.c:151-160` is supposed to
suppress events for clips that are `avm1_removed` or
`pending_removal` by drain time. For test6 the filter is suppressing
too much (Flash fires them, we don't). Here the inverse: the
filter isn't suppressing enough (Flash suppresses them, we fire
them).

The discrepancy suggests this test's expected output captures
Ruffle's cancellation model (suppress same-frame Remove-cancelled
placements), and test6's expected output captures Flash's
fire-all-anyway model.

Cross-check `output.ruffle.txt` for both tests:
- If PlaceAndRemove's ruffle.txt also says all "Done", Ruffle
  cancels — and our bug is that we're NOT cancelling here.
- If test6's ruffle.txt suppresses (matches our current behavior),
  Ruffle cancels there too.

If both confirm Ruffle's cancellation model, then test6's expected
output is Flash-only-correct and *both* should be on the
cancellation side — meaning we have a separate bug in test6 (not
the cancellation filter; something else).

## Recommended fix order

1. **Diagnose first.** Diff `output.ruffle.txt` for both
   PlaceAndRemove and action_execution_order_test6. Determine which
   model Ruffle uses. 30 min.
2. **If Ruffle cancels (likely)**: our cancellation filter at
   `action_queue.c:151-160` is too lenient — entries with
   `pending_removal=1` AND with the same-frame paired-Remove signal
   should be suppressed. Currently the suppression only fires for
   `avm1_removed` (already-finalized), not `pending_removal`
   (queued-for-finalize at end of frame).
   Estimate: 2-3 hours fix + verification on test6 and AVM1
   `reverse_execute_PlaceObject2_test2` (the regression that
   killed the 2026-05-08 attempt).

Total estimate: 3-4 hours, 1 session.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt`. Even if Phase 1 only
gets us partway, ruffle_matched promotion may fire if our diff
becomes subset of Ruffle's.
