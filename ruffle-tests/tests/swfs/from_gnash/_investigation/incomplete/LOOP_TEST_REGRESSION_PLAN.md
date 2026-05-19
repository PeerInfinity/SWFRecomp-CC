# loop_test / loop_test10 Regression Plan
<!-- TESTS: misc-ming.all/loop/loop_test, misc-ming.all/loop/loop_test10 -->

Last updated: 2026-05-19 (Phase 2 done — loop_test10 regression
re-landed; Phase 1 loop_test still pending)

<!-- PLAN_META
id: LOOP_TEST_REGRESSION_PLAN
status: in_progress
phases:
  - id: 1
    name: "loop_test: depth-cycle output reordered; auto-instance-counter off by 1"
    status: pending
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

### loop_test (4/21)

The actual output reorders + inserts "Warning: Failed to place
object at depth 64000" / "depth 3" lines that aren't in the
expected output:

```
- PASSED: 47616 == 47616   (line 7 expected)
+ PASSED: -16381 == -16381  (line 7 actual — got line 8's content)
- PASSED: -16381 == -16381  (line 8 expected)
+ PASSED: 47616 == 47616    (line 8 actual — swapped with line 7)
- PASSED: -16381 == -16381  (line 9 expected)
+ Warning: Failed to place object at depth 64000.   (line 9 actual)
- PASSED: 47616 == 47616    (line 10 expected)
+ Warning: Failed to place object at depth 3.       (line 10 actual)
```

Two symptoms in one cluster:
- Adjacent depth-cycle traces are pairwise swapped (lines 7↔8,
  13↔14, 17↔18) — looks like the test does a loop over a sprite
  with two depths and we are iterating in reverse order on
  successive ticks.
- "Warning: Failed to place object at depth N" warnings appear
  where the expected output has clean PASSED lines — the test
  uses `swapDepths` to negative-bias depths (-16381 ≈ ALSPRITE_FLAG
  area), and our placement is rejecting some swaps. Probably a
  bounds check that wasn't present before.

The 2026-05-02 entry in REMAINING_TAIL_TRIAGE said this was
resolved by "cluster fixes recovered the depth-bias / interleave
behavior". Need to git-bisect/git-blame the depth-bias and
PlaceObject swap code to find which later commit re-introduced
the regression.

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
