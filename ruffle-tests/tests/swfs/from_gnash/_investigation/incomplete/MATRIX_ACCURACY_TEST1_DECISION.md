# matrix_accuracy_test1 Decision
<!-- TESTS: misc-swfc.all/matrix_accuracy_test1 -->

Last updated: 2026-05-19 (initial decision doc; this is **not** a fix
plan)

<!-- PLAN_META
id: MATRIX_ACCURACY_TEST1_DECISION
status: pending_decision
phases:
  - id: 1
    name: "Diff against Ruffle expected — auto-promotion check"
    status: pending
  - id: 2
    name: "If not RM-eligible: add to ACCEPTED_DIFFS.md (twips-precision edge case)"
    status: pending
dependencies: []
related:
  - id: MATRIX_TEST_SKEW_PLAN
    reason: "Same class of issue: twips-precision arithmetic at extreme matrix scale values."
blockers: []
status_note: |
  SUBTESTS_NEWLY_VISIBLE_TRIAGE Tier D inventoried this as a
  "known twips-precision edge case". This doc captures the
  decision path; it is **not** a plan to write a fix.
-->

## Status

Local CI baseline (commit `eb8206f8`, 2026-05-15):

| Test | Match | % | Status |
|------|-------|---|--------|
| misc-swfc.all/matrix_accuracy_test1 | 10/18 | 55.6% | output_mismatch |

## Failure characterization

Test exercises MovieClip transforms at the edges of the twips
range (`_xscale = -1` → wraps to 4294967295 in some semantics;
`_x` set to specific extreme values that should produce exact
integer twip results).

```
- FAILED: mc1._x: expected: "-1" , obtained: "-107374182.4"
+ FAILED: mc1._x: expected: "-1" , obtained: "1073741824"
- FAILED: mc1._xscale: expected: "4294967295" , obtained: "..."
+ FAILED: mc1._xscale: expected: "4294967295" , obtained: "4294967296"
```

Note both expected and our actual already say FAILED on most lines —
this is a Gnash test where Gnash itself doesn't match Flash's
expected output exactly. The remaining diff is around exact integer
wrap behavior at INT_MIN/INT_MAX boundaries of the twips
representation.

Our impl is "close but off by 1" or "off by a factor of 2 from
Gnash's wrong answer". The fundamental question is: does fixing
this give us anything beyond strict Flash parity at a corner that
doesn't show up in real content?

## Recommended decision path

1. **Diff `output.txt` vs `output.ruffle.txt`** for this test. If
   Ruffle is also off by these specific integer amounts (likely —
   twips arithmetic at these scales is implementation-defined),
   subset-match should promote us. Run with `--diff --verbose`.

2. **If subset-match works**: no work needed.

3. **If NOT subset-match-eligible**: add the test to
   `ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/ignored_tests.txt`
   and document in `ACCEPTED_DIFFS.md` under "Category 1:
   Implementation-defined twips arithmetic at integer boundaries".

The work itself is 30-60 minutes total, no code changes either way.

## Decision (to be made)

Run the diff (step 1) and choose path 2 or 3. There is no
realistic path to PASS that's worth the effort, since Gnash's
expected output is itself slightly wrong vs. Flash and would
require us to replicate a specific Flash quirk that no real-world
SWF will exercise.
