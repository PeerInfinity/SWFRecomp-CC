# movieclip_destruction_test3 Plan
<!-- TESTS: misc-swfc.all/movieclip_destruction_test3 -->

Last updated: 2026-05-19 (initial planning doc, drafted from local
single-test reproduction at the current `master` SHA)

<!-- PLAN_META
id: MOVIECLIP_DESTRUCTION_TEST3_PLAN
status: pending
phases:
  - id: 1
    name: "removeMovieClip at frame N triggers expected 'removed at frame N' trace + abort"
    status: pending
  - id: 2
    name: "After removal: nestedMovieClip.getDepth() = -32779 (biased depth) + typeof = undefined"
    status: pending
  - id: 3
    name: "Post-removal _root.x and _root.as_order values from completed sprite frames"
    status: pending
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: MOVIECLIP_VN_PLAN
    reason: "Phase 6 (soft/hard reference) and Phase 7 (unloadMovie binding) cover the same removed-MC visibility issues."
  - id: MOVIECLIP_DESTRUCTION_TEST4_PLAN
    reason: "Sibling test; same removeMovieClip lifecycle bugs."
  - id: SPRITE_REWIND_IDENTITY_PLAN
    reason: "Blocked plan covers the goto-driven sprite double-fire that may interact with this test's expected frame sequencing."
blockers: []
status_note: |
  Smaller than test4 (only ~18 expected lines). Test exercises
  nested removeMovieClip + verification that depth, _root vars,
  and as_order survive the removal in specific ways. Several
  symptoms identical to test4, so fixes here likely cascade.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-swfc.all/movieclip_destruction_test3 | 5/18 | 27.8% | output_mismatch |

## Failure surface

Test removes a deeply-nested MovieClip at frame 10 then verifies:

1. **Expected trace `nestedMovieClip removed at frame 10`** — emitted
   from a `removeMovieClip` handler we should fire.
2. **Expected trace `actions here should not be executed`** — actually
   sentinel for "this trace IS expected to fire (test verifies the
   sprite's last frame ran before removal)."
3. **`nestedMovieClip.getDepth() == -32779`** — after removal, the
   reference's getDepth still works, returning the biased depth
   (-32768 - 10 - 1).
4. **`_root.x == 300`** — value set by the now-removed sprite's
   final frame.
5. **`typeof(nestedMovieClip) == undefined`** — same hard-reference
   clearance as MOVIECLIP_VN Phase 6.
6. **`_root.as_order == '0+1+2+'`** — frame-by-frame trace order.

Our output (paraphrased):
- Skip the two custom trace lines (1, 2) entirely
- Report depth 10 instead of -32779 (we don't bias-adjust after
  removal)
- _root.x is undefined (sprite's last frame didn't run)
- typeof nestedMovieClip stays movieclip
- as_order is just "0+" (sprite's frame 1 traces missing)

## Approach

Multi-phase debug:

1. **Phase 1 + 3 (sprite final frame execution).** After
   `removeMovieClip` is called from the sprite's own frame
   script, the *current frame's* DoAction needs to complete
   before the removal takes effect. We are likely aborting the
   sprite's frame at the `removeMovieClip` call, dropping the
   subsequent `_root.x = 300` and the `as_order +=` traces.
   Fix: `removeMovieClip` should be a deferred operation
   (queue + run after frame's DoAction completes).

2. **Phase 2 (depth biasing on removed MC).** After removal, MC
   stays alive at biased depth `-32768 - swf_depth - 1`. Mirrors
   the AVM1 `unload` test handling. Bug: we return the original
   unbiased depth.

3. **Phase 2 (hard reference clearance).** Same fix as
   MOVIECLIP_VN Phase 6.

## Recommended fix order

1. **Coordinate with MOVIECLIP_VN_PLAN Phase 6.** Land that first;
   most of Phase 2 here resolves automatically.
2. **Phase 1 (deferred removeMovieClip).** Estimate: 2-3 hours.
   Verify against AVM1 `unload`, `removeMovieClip` tests.
3. **Phase 3 (frame DoAction completion before removal).**
   Estimate: 1-2 hours after Phase 1.

Total estimate: 3-5 hours, 1-2 sessions. Strong PASS candidate
after MOVIECLIP_VN_PLAN closes.

## Promotion plumbing

`known_failure = true` + `output.ruffle.txt`. At 28% line match,
moderate work needed.
