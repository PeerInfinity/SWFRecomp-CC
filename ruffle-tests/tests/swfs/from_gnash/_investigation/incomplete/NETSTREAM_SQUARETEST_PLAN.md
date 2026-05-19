# NetStream-SquareTest Plan
<!-- TESTS: misc-ming.all/NetStream-SquareTest -->

Last updated: 2026-05-19 (graduated from REMAINING_TAIL_TRIAGE
"NetStream-SquareTest" entry which already said "Promote to
standalone plan when work begins")

<!-- PLAN_META
id: NETSTREAM_SQUARETEST_PLAN
status: pending
phases:
  - id: 1
    name: "Diagnose: NetStream timer interval vs frame-sync mechanism"
    status: pending
  - id: 2
    name: "NetStream callback timing for video frame events"
    status: pending
  - id: 3
    name: "FLV demuxer frame-time progression match with timer ticks"
    status: pending
dependencies: []
related:
  - id: VIDEO_EMBED_SQUARE_PLAN
    reason: "Existing incomplete plan in from_gnash/_investigation/incomplete/. Confirm whether it actually covers NetStream-SquareTest or just the related (but distinct) embedded-video test."
  - id: FLV_PLAYBACK_PLAN
    reason: "AVM1 plan (complete) — 3/3 trace tests pass. The Gnash test exercises specific NetStream timing semantics not covered by AVM1."
blockers: []
status_note: |
  Before committing real work, verify whether `incomplete/VIDEO_EMBED_SQUARE_PLAN.md`
  covers this test. If it does, this plan can be folded in or
  closed as a duplicate. If it covers only the embedded-video
  variant, this plan stands alone.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-ming.all/NetStream-SquareTest | 86/216 | 39.8% | output_mismatch |

## Failure surface (from REMAINING_TAIL_TRIAGE)

> NetStream timing test that exercises video playback. Expected
> output cycles through video frames with timing-dependent
> assertions. We produce ~40% of the expected lines.

Per MISC_MING_SWFC_PLAN: "netstream timing". NetStream playback uses
a timer-based callback; the timer interval or sync-with-frame
mechanism diverges from Flash. The 14 AVM1 NetStream tests pass, so
the basic NetStream API works — this test exercises specific
timing semantics.

## Approach

1. **Confirm scope against VIDEO_EMBED_SQUARE_PLAN.** Open the
   existing plan and check whether it names NetStream-SquareTest
   specifically. If yes → close this plan. If no → continue.

2. **Identify which assertions fail.** Likely the test asserts on
   video-frame timestamps, frame-progression rate, or onMetaData
   payload. Categorize failing lines.

3. **Compare timer-interval semantics.** Ruffle drives NetStream
   playback via the main player tick clock; we drive via
   `processSoundPlayback` analog. If our tick interval differs from
   Flash's (33.33ms at 30fps), playback timing drifts.

4. **Frame-sync mechanism.** Verify that our FLV-frame-event
   dispatch (`fireFrameEvent`-equivalent) interleaves with the
   timeline tick at the right boundary.

Estimate: 4-6 hours timing investigation per REMAINING_TAIL_TRIAGE.

## Promotion plumbing

Test has `known_failure = true` + `output.ruffle.txt` sidecar.
Subset-match auto-promotes once our diff is within Ruffle's. At
40% line-match, substantial work needed before threshold.
