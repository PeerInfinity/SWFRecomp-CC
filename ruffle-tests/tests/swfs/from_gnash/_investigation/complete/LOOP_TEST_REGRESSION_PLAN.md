# loop_test / loop_test10 Regression Plan
<!-- TESTS: misc-ming.all/loop/loop_test, misc-ming.all/loop/loop_test10 -->

Last updated: 2026-05-19 (Phase 1 + Phase 2 both done — loop_test
PASS, loop_test10 ruffle_matched; plan complete)

<!-- PLAN_META
id: LOOP_TEST_REGRESSION_PLAN
status: complete
phases:
  - id: 1
    name: "loop_test: depth-cycle output reordered; auto-instance-counter off by 1"
    status: done
  - id: 2
    name: "loop_test10: PlaceObject2 + Remove same-frame regression; auto-instance counter off by 3"
    status: done
dependencies: []
related:
  - id: SPRITE_EXEC_LIST_LIFO_PLAN
    reason: "loop_test and loop_test10 were original targets of the LIFO-ordering investigation. Once that lands the regressions may resolve."
  - id: SPRITE_REWIND_IDENTITY_PLAN
    reason: "blocked plan in from_gnash/_investigation/blocked/ — covers the place/remove/instance-counter machinery that both regressions stress."
blockers: []
status_note: |
  Both tests were previously marked "Resolved" in
  `incomplete/REMAINING_TAIL_TRIAGE.md`:

  - loop_test → "Resolved 2026-05-02 (PASS)" — cluster fixes
    recovered depth-bias / interleave behavior.
  - loop_test10 → "Resolved 2026-05-08 (ruffle_matched 14/16)" via
    two paired same-frame Remove+Place fixes in `libswf/tag.c`.

  Local re-runs at the current master SHA show both back at
  output_mismatch (loop_test 4/21, loop_test10 1/28). Some
  later commit appears to have regressed them. This plan exists to
  rediscover and re-land the regressed fix, NOT to design a new
  fix from scratch.
-->

## Status

Local reproduction at the current `master` SHA:

| Test | Match | Status |
|------|-------|--------|
| misc-ming.all/loop/loop_test | 4/21 | output_mismatch |
| misc-ming.all/loop/loop_test10 | 1/28 | output_mismatch |

The CI snapshot `eb8206f8` (2026-05-15) result file shows the same
output_mismatch state, so this is a real regression confirmed
both in CI and locally.

## Failure surface

### loop_test — RESOLVED 2026-05-19 (PASS)

Root cause: the same Phase-3 Place-refusal gate from commit
`12fa91a3` that broke loop_test10. loop_test places movieClip1
(char 5) at depth 64000 and movieClip2 (char 7) at depth 3, then a
clip-event handler `swapDepths` them every loop iteration. swapDepths
does NOT bump `placed_at_frame`, so after the swap each depth holds
a different character whose `placed_at_frame` is still 0. On the
natural timeline loop wrap (frame 2 → frame 0), frame 0's
`tagPlaceObject2` Place tags re-target depths 64000/3 — now occupied
by the swapped-in (different) character. The Phase-3 gate
(`char_id != display_list[depth].char_id && placed_at_frame <=
current_frame`) fired and printed "Warning: Failed to place object
at depth N" — 6 spurious lines (2 per loop). The pairwise-swap
appearance in the diff was a line-alignment artifact of those 6
extra lines; actual-minus-warnings already matched expected exactly.

Ruffle never warns here: a natural loop wrap is an implicit
`run_goto(1, is_rewind=true)` (`NextFrame::First`), and `run_goto`'s
`(_, Some(prev_child), true)` arm treats a Place at an occupied
depth during a rewind as a *modify* of the surviving child, never an
instantiate/refuse. `survives_rewind` keeps a MovieClip at a depth
whenever `ratio_equals` holds (id mismatch is irrelevant for MCs),
so the swapped clips survive and persist across the loop.

Fix: a new `g_loopback_replay` flag (`swf_core.c` / `swf.c`), armed
by the natural-backward-wrap branch and scoped to exactly the
frame_0 re-run. `tagPlaceObject2`'s Phase-3 refusal is now gated
`&& !g_loopback_replay`, and the existing `catch_up_backward`
survives-block (already implementing Ruffle's `survives_rewind` +
modify) now also fires on `g_loopback_replay`. The natural loop
wrap thus goes through the same rewind-modify path as a goto-driven
backward catch-up.

Verified PASS; regression battery clean — see Phase 2 note below
(same battery covers both fixes) plus 16-test avm1 goto/rewind
battery and 5-test from_shumway timeline_as2 battery, all green.

### loop_test10 — RESOLVED 2026-05-19 (ruffle_matched)

Root cause: commit `12fa91a3` ("refuse Place on occupied depth")
added a Phase-3 gate in `tagPlaceObject2` / `tagPlaceObject2Ratio`
that rejects a Place of a different character on an occupied
depth. loop_test10 frame 3 does `Remove(mc1)` + `Place(mc2)` at
depth 100; mc1 carries an UNLOAD handler so its removal is
deferred (pending-finalize) and `display_list[100].char_id`
still holds mc1's stale char_id. The gate saw a different char on
an "occupied" depth and refused the Place → "Warning: Failed to
place object at depth 100" instead of mc2 initializing.

Fix: added `&& !ng_depth_has_pending_finalize(depth)` to both
Phase-3 refusal gates. A same-frame Remove of an UNLOAD-handler
child logically vacates the depth (the stale char_id lingers only
until the deferred finalize runs); Ruffle's RemoveObject frees the
depth immediately. Now `loop_test10` is `ruffle_matched`.

Verified no regressions: 12-test placement/replace battery
(place_object_test{,2}, place_and_remove_object_test{,_insane},
PlaceObject2Test, replace_{sprites,shapes,buttons}1test,
reverse_execute_PlaceObject2_test{1,2}, morph_test1, shape_test)
all effective pass; avm1 placeobject_occupied_depth, clip_events,
issue_1104, unload, unload_nested_child, default_names,
button_order, movieclip_in_removed_button, goto_rewind3 all PASS.

## Recommended approach

Both regressions are about diagnosis, not new design:

1. **Bisect to find the regressing commit for each test.** Use
   `git log --oneline` on `SWFModernRuntime/src/libswf/tag.c` and
   `SWFModernRuntime/src/actionmodern/action.c` for changes after
   the relevant resolution date (loop_test: 2026-05-02; loop_test10:
   2026-05-08). Bisect with `git bisect run` driving
   `verify_output.py --test=loop/loop_test10`.

2. **Once identified, decide:**
   - If the regressing commit landed a legitimate fix that was
     incompatible with the old loop_test fix → port the old fix
     forward (likely a single-line gating change).
   - If the regression was an oversight (unrelated change broke
     the path) → restore the old behavior.

3. **Verify against the full Phase 6 lifecycle battery in
   REMAINING_TAIL_TRIAGE** before committing — these tests have
   tight interactions with `RegisterClassTest3`/`4`,
   `reverse_execute_PlaceObject2_test2`, and `place_and_remove_object_insane_test`.

Total estimate: 2-4 hours of bisect + ~1 hour to re-apply or
patch the fix. Two distinct bisects (loop_test vs loop_test10
have different resolution dates so likely different regressing
commits).

## Promotion plumbing

Both have `known_failure = true` + `output.ruffle.txt` sidecars.
loop_test10 will auto-promote to `ruffle_matched` once the diff
becomes a subset of Ruffle's — which it was as of
2026-05-08, and should be again after the regression is reverted.
loop_test was a full PASS at that point and might return to PASS.
