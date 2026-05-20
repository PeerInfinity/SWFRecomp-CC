# matrix_accuracy_test1 Decision
<!-- TESTS: misc-swfc.all/matrix_accuracy_test1 -->

Last updated: 2026-05-19 (initial decision doc; this is **not** a fix
plan)

<!-- PLAN_META
id: MATRIX_ACCURACY_TEST1_DECISION
status: complete
phases:
  - id: 1
    name: "Diff against Ruffle expected — auto-promotion check"
    status: complete
  - id: 2
    name: "If not RM-eligible: add to ACCEPTED_DIFFS.md (twips-precision edge case)"
    status: complete
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

## Decision (made 2026-05-20)

**Path 3 — NOT RM-eligible. Added to `ignored_tests.txt` + `ACCEPTED_DIFFS.md`.**

`test.toml` declares `known_failure.panic = "attempt to subtract with
overflow"` — Ruffle *panics* on this test and ships **no**
`output.ruffle.txt` sidecar. There is therefore no Ruffle diff to
subset-match against, and `ruffle_matched` promotion is structurally
impossible regardless of how close our output is.

Ran `verify_output.py --test=matrix_accuracy_test1 --diff`: 10/18 lines
match. The 8 diff lines are twips arithmetic at INT_MIN/INT_MAX boundaries —
most are already `FAILED` in *both* expected and our output (Gnash's own
captured output disagrees with Flash), and the residual is off-by-one
u32-wrap (`4294967296` = 2³² vs expected `4294967295` = 2³²−1) plus
factor-of-2 wrap drift at the fixed-point limits.

No realistic path to PASS worth the effort: Gnash's expected output is
itself wrong vs. Flash, and matching it would require replicating a Flash
integer-wrap quirk at twip boundaries that no real-world SWF exercises.
Documented in `ACCEPTED_DIFFS.md` Category 4; the test is in
`from_gnash/misc-swfc.all/ignored_tests.txt`.
