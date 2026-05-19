# action_execution_order_extend_test Plan
<!-- TESTS: misc-ming.all/action_order/action_execution_order_extend_test -->

Last updated: 2026-05-19 (re-investigated from RecompiledScripts at the
current `master` SHA — root cause refined, plan reclassified as BLOCKED)

<!-- PLAN_META
id: ACTION_EXECUTION_ORDER_EXTEND_PLAN
status: blocked
phases:
  - id: 1
    name: "onLoad/onUnload METHOD-handler dispatch for plain timeline sprites"
    status: blocked
  - id: 2
    name: "enterFrame ordering: mc_blu fires before mc_red instead of after"
    status: blocked
dependencies:
  - id: SUBTESTS_HARNESS
    reason: "Discovery shipped 2026-05-14 (commit 39b797ac)."
related:
  - id: SPRITE_EXEC_LIST_LIFO_PLAN
    reason: "Phase 2 (enterFrame ordering) is exactly the LIFO-vs-FIFO sprite-exec-list issue. SPRITE_EXEC_LIST_LIFO is in_progress (Phases 1-3 complete, Phase 4 partial) — this test still mis-orders so the remaining LIFO work is not yet sufficient."
  - id: ENTERFRAME_DISPATCH_PLAN
    reason: "AVM1 plan (complete) — 18 tests pass for clip events. This test exercises specific nested-sprite ordering."
blockers:
  - "Phase 1 requires onLoad/onUnload METHOD-event dispatch for plain timeline-placed sprites (not registerClass, not attachMovie). Currently actionDispatchMCOnLoad is only invoked for the root MC, dynamically-attached MCs, and registerClass sprites. Adding it for every timeline sprite is regression-prone: the test itself expects mc_red.onLoad to fire but mc_blu.onLoad NOT to fire (y4 == undefined is the EXPECTED line), and Ruffle gets this wrong (fires both). The fire/no-fire rule is subtle and Flash-version/timing-specific — needs the Gnash C source to pin down."
  - "Phase 2 (enterFrame parent/child interleave) is the SPRITE_EXEC_LIST_LIFO issue; that plan is in_progress and the landed Phases 1-3 do not yet fix this test's ordering."
  - "Even a perfect Phase 1 fix cannot promote the test on its own — our diff against expected is ~24/32 lines and would still not be a subset of Ruffle's 10-line diff without Phase 2 also landing."
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

Two distinct bugs cluster here.

## Refined diagnosis (2026-05-19 re-investigation)

Read from `RecompiledScripts/script_7.c` + `script_defs.c`
(`func_anonymous_22`..`27`). The test registers six METHOD-style
lifecycle handlers in a root frame DoAction (`script_7`):

```
_root.mc_red.onLoad        = func22  -> traces "mc_red load executed",        sets _root.y1
_root.mc_red.onEnterFrame  = func23  -> traces "mc_red enterFrame executed",  sets _root.y2
_root.mc_red.onUnload      = func24  -> traces "mc_red unload executed",      sets _root.y3
_root.mc_red.mc_blu.onLoad       = func25  -> traces "mc_blu load executed",       sets _root.y4
_root.mc_red.mc_blu.onEnterFrame = func26  -> traces "mc_blu enterFrame executed", sets _root.y5
_root.mc_red.mc_blu.onUnload     = func27  -> traces "mc_blu user-defined UNLOAD executed", sets _root.y6
```

mc_red and mc_blu are plain **timeline-placed** sprites (not
`attachMovie`, not `Object.registerClass`). The `clip load`/
`onClipLoad` lines come from SWF-embedded `onClipEvent` blocks
and DO fire correctly.

**Bug 1 — `onLoad`/`onUnload` METHOD handlers never dispatch for
plain timeline sprites.** `actionDispatchMCOnLoad` (action.c:31885)
is only invoked from `aq_dispatch_mc_onload` (attachMovie /
createEmptyMovieClip path) and `actionDispatchRootOnLoad` (root MC).
Plain timeline sprites are never queued via `actionQueueMCOnLoad`,
so `mc_red.onLoad`/`mc_red.onUnload` (and the mc_blu equivalents)
are silent. Symptom: `y1` FAILS (`mc_red onLoad called` never set),
`mc_red load executed` line missing, `mc_red unload executed`
missing, `mc_blu user-defined UNLOAD executed` missing. (`onEnterFrame`
METHOD handlers DO fire — that path is wired separately via
`actionDispatchEnterFrameHandlers` / `dispatch_enterframe_clip_actions`.)

**The fire/no-fire rule is subtle and version-specific.** The
EXPECTED (Flash, `output.fp10.txt`) output fires `mc_red.onLoad`
(line 8) but NOT `mc_blu.onLoad` — line 27 `y4 == undefined` is an
*expected PASS*. Ruffle gets this wrong: its `output.fp10.ruffle.txt`
fires both (line 27 is `FAILED ... obtained: mc_blu onLoad called`).
So a naive "dispatch onLoad for every timeline sprite" change would
match Ruffle, not Flash, and would regress any suite test that
asserts a timeline sprite's `onLoad` does not fire. Pinning the
exact rule (top-level vs nested? handler registered before vs after
the load tick? SWF version gate?) needs the Gnash C source
(`action_execution_order_extend.c`), which is not in this repo.

**Bug 2 — enterFrame parent/child interleave.** Flash interleaves
per-clip (`mc_blu enterFrame` → `mc_blu` frame DoAction → `mc_red
enterFrame` → `mc_red` frame DoAction), processing the child clip
fully before the parent. We process all frame DoActions first, then
enterFrames. Same LIFO-vs-FIFO root cause as `loop_test2`/
`loop_test3`/`action_execution_order_test11`/`ActionOrderTest3`,
covered by SPRITE_EXEC_LIST_LIFO_PLAN. That plan is `in_progress`
(Phases 1-3 landed, Phase 4 partial); the landed work does not yet
fix this test's ordering.

## Why this is BLOCKED, not a quick win

- The plan's original 1-2h estimate assumed Bug 1 was "a one-line
  registration miss." It is not — it is a missing feature
  (timeline-sprite `onLoad`/`onUnload` method dispatch) with a
  subtle, undocumented fire/no-fire rule that diverges from Ruffle.
- Even a perfect Bug 1 fix cannot promote the test: our diff vs
  `output.fp10.txt` is ~24/32 lines; Ruffle's diff is only 10 lines
  ({10-17, 27, 28}). Subset-match promotion needs BOTH bugs fixed
  AND the four currently-missing lines (`mc_red load executed`,
  the extra `mc_blu enterFrame executed`, `mc_blu user-defined
  UNLOAD executed`, `mc_red unload executed`) inserted in the right
  positions so lines 18-32 realign.
- Load-event timing changes are historically regression-prone here
  — see CURRENT_STATUS.md "Investigated 2026-05-08 (CI `281f30b3`,
  reverted)" for a load-filter attempt that passed a 60-test local
  battery but regressed `reverse_execute_PlaceObject2_test2` in CI.

## Recommended fix order (when unblocked)

1. **Obtain the Gnash C source** for `action_execution_order_extend.c`
   to pin down the exact `onLoad` fire/no-fire rule for timeline
   sprites (top-level vs nested, registration-timing gate).
2. **Wait for SPRITE_EXEC_LIST_LIFO_PLAN** to fully land (Phase 4
   dispatcher-proper), then re-baseline.
3. **Implement Bug 1** behind the rule from step 1, with a wide
   regression battery focused on tests that assert timeline-sprite
   `onLoad`/`onUnload` non-firing.

## Promotion plumbing

`known_failure = true` + `output.fp10.ruffle.txt` already present.
Subset-match against Ruffle's 10-line diff is the promotion path —
but only reachable after both bugs land.
