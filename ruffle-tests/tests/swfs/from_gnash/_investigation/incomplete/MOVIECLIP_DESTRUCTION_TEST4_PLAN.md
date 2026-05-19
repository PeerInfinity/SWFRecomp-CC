# movieclip_destruction_test4 Plan
<!-- TESTS: misc-swfc.all/movieclip_destruction_test4 -->

Last updated: 2026-05-19 (graduated from REMAINING_TAIL_TRIAGE
"movieclip_destruction_test4" entry)

<!-- PLAN_META
id: MOVIECLIP_DESTRUCTION_TEST4_PLAN
status: pending
phases:
  - id: 1
    name: "Sprite frame DoAction firing during goto+removeMovieClip on dynamic clones"
    status: pending
  - id: 2
    name: "Removed-brother MC stays live in script context (typeof brother1 == movieclip vs undefined)"
    status: pending
dependencies: []
related:
  - id: MOVIECLIP_VN_PLAN
    reason: "MOVIECLIP_VN Phase 6 (soft/hard reference semantics) and Phase 7 (unloadMovie binding) cover similar removed-MC-still-typeof-movieclip issues. Fix in one may help the other."
  - id: SPRITE_REWIND_IDENTITY_PLAN
    reason: "Blocked plan covers Phase 4 (goto-driven sprite double-fire). Phase 1 here likely depends on that landing."
blockers:
  - reason: "Phase 1 depends on the GOTO_CATCHUP_HYGIENE Phase 4 work — currently blocked in SPRITE_REWIND_IDENTITY_PLAN (blocked/)."
status_note: |
  Listed in REMAINING_TAIL_TRIAGE as "Re-baseline after
  GOTO_CATCHUP_HYGIENE Phase 1 + Phase 4 land." GOTO_CATCHUP_HYGIENE
  has since been superseded (its remaining work moved to other
  plans). This test now waits on whatever covers the goto-driven
  sprite double-fire — currently SPRITE_REWIND_IDENTITY_PLAN
  (blocked).
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-swfc.all/movieclip_destruction_test4 | 8/40 | 20.0% | output_mismatch |

## Failure surface (from REMAINING_TAIL_TRIAGE)

Two issues:

1. **Missing sprite frame DoAction traces.** Lines like "Running
   frame2 actions of mc2", "Running frame3 actions of mc2",
   "Running frame2 actions of brother2", etc. — sprite frames
   don't fire during the test's gotoAndPlay + removeMovieClip
   sequence on dynamic clones.

2. **`typeof(brother1) == undefined` expected, got `movieclip`.**
   Removed brothers stay live in script context. Same pattern as
   MOVIECLIP_VN_PLAN Phase 6 (hard reference clearance).

## Approach

Wait for SPRITE_REWIND_IDENTITY_PLAN (blocked) to land — it covers
the Phase 4 work that drives the missing sprite frames. After that:

1. **Re-baseline.** Run movieclip_destruction_test4 against the
   updated tree. Expect Phase 1's frame DoAction traces to come
   back automatically.
2. **Phase 2 work (hard-reference clearance).** Same fix as
   MOVIECLIP_VN_PLAN Phase 6 — when an MC is removed via
   removeMovieClip(), variables holding the MC value should become
   undefined.

If MOVIECLIP_VN_PLAN Phase 6 lands first, Phase 2 here may already
be done.

Estimate: 2-3 hours after blockers clear.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt` sidecar. Currently
at 20% line-match — substantial work needed before subset-match
threshold.
