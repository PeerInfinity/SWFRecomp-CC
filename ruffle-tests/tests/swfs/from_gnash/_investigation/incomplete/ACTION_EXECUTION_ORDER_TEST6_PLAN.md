# action_execution_order_test6 Plan
<!-- TESTS: misc-ming.all/action_order/action_execution_order_test6 -->

Last updated: 2026-05-19 (graduated from REMAINING_TAIL_TRIAGE
"action_execution_order_test6" entry — REMAINING_TAIL_TRIAGE has
a detailed case-(c) root-cause analysis, this plan just transcribes
it into the standard PLAN structure)

<!-- PLAN_META
id: ACTION_EXECUTION_ORDER_TEST6_PLAN
status: pending
phases:
  - id: 1
    name: "Approach A: fire ALL events Flash-style (regression risk: RegisterClassTest3)"
    status: pending
  - id: 2
    name: "Approach B: match Ruffle's ordering on lines 0-1, accept ruffle_matched (no Flash PASS)"
    status: pending
dependencies: []
related:
  - id: SPRITE_EXEC_LIST_LIFO_PLAN
  - id: DEFERRED_CLIP_UNLOAD_PLAN
  - id: SPRITE_REWIND_IDENTITY_PLAN
blockers:
  - reason: "Both approaches have regression risk; choose carefully. Approach B is lower-risk and lower-value (RM not PASS), Approach A is higher-risk and higher-value but explicitly noted to regress RegisterClassTest3."
status_note: |
  REMAINING_TAIL_TRIAGE already has a deep case-(c) analysis (2026-05-08
  re-investigation). This plan is mostly mechanical promotion of
  that analysis. The 2026-05-08 commit `281f30b3` (later reverted in
  `4c61f111`) attempted Approach A but regressed
  `reverse_execute_PlaceObject2_test2` (PASS 10/10 → ruffle_matched 7/10).
  Real fix needs per-entry tracking of "this placement was cancelled
  by paired remove in same goto sweep" — more invasive than a 1-line
  gate.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/action_order/action_execution_order_test6 | 0/24 | 0.0% | output_mismatch |

## Root cause (from REMAINING_TAIL_TRIAGE 2026-05-08 re-investigation)

The bug is in the `aq_drain` filter at `action_queue.c:151-160`: for
entries queued during catchup (`queued_in_catchup=1`), if the clip
is `avm1_removed` or `pending_removal` by drain time, the entry is
**skipped**. Comment explicitly says "goto_commands aggregation
(place+remove in same goto sweep) remains canceled."

For test6's first cycle (gotoAndPlay 2→9), all three sprites are
placed AND removed during the catchup (mc1/mc2 placed at frame 3 +
removed at frame 5; mc3 placed at frame 6 + removed at frame 8).
So all three CONSTRUCT entries get filtered out at drain time. The
LOAD entries (AQ_KIND_SCRIPT) ALSO get the filter — but the test's
expected output shows them firing.

Flash's actual semantics: fire ALL events for ALL placements, even
those cancelled in same-goto pairs. Ruffle adopts the cancellation
model; that's why Ruffle's `output.ruffle.txt` for this test ALSO
fails (only emits the second cycle's events from the inner
backward goto).

## Approach options

### Approach A — Flash-exact

Make CLIP_CONSTRUCT and AQ_KIND_SCRIPT (LOAD) `fires_chronologically`
even when `queued_in_catchup=1`. Would fire all events Flash-style.

**Risk:** regresses every test that depends on goto_commands
aggregation. `RegisterClassTest3` explicitly relies on it (comment
at `tag.c:2770-2787`). Verified 2026-05-08 attempt:
`reverse_execute_PlaceObject2_test2` flipped PASS 10/10 →
ruffle_matched 7/10 due to a too-broad gate.

To do safely: need per-entry tracking of "this placement was
cancelled by a same-sweep RemoveObject" vs "this placement followed
by an independent remove tag" — only suppress the former.

### Approach B — match Ruffle, settle for RM

Make our ordering match Ruffle's on lines 0-1 (Construct-before-Load
for mc1/mc2 in the first cycle). Our diff becomes a subset of
Ruffle's, ruffle_matched promotion fires. Test would not PASS but
would count as effective pass.

Simpler diagnostically: just need to figure out why our
Construct vs Load ordering differs from Ruffle's on those two
specific lines. Probably a single fence/queue-flush order tweak.

## Recommended fix order

1. **Approach B diagnosis first** — quick check whether the 2-line
   diff vs Ruffle is fixable cheaply. Estimate: 1-2 hours.
2. **If Approach B works** → land it, declare done. Estimate
   includes Phase 1 verification.
3. **If Approach B doesn't work** → fall back to Approach A with the
   safer per-entry cancellation tracking. Estimate: 4-6 hours.

Total estimate: 1-8 hours depending on approach.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt`. The test's expected
output is the Flash output — both we and Ruffle currently disagree.
Promotion to `ruffle_matched` requires our diff to be a subset of
Ruffle's; Approach B is designed specifically to make that happen.
