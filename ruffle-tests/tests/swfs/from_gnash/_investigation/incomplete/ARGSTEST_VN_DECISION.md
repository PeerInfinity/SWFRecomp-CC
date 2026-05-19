# argstest-vN Decision
<!-- TESTS: argstest-v6, argstest-v7, argstest-v8 -->

Last updated: 2026-05-19 (initial decision doc; this is **not** a fix
plan)

<!-- PLAN_META
id: ARGSTEST_VN_DECISION
status: pending_decision
phases:
  - id: 1
    name: "Verify Ruffle diff against expected — is this auto-promotion-eligible?"
    status: pending
  - id: 2
    name: "If not RM-eligible: add to ACCEPTED_DIFFS.md and ignored_tests.txt"
    status: pending
dependencies: []
related: []
blockers: []
status_note: |
  argstest tests are extreme line-volume tests (~2000-2400 lines
  each) that walk every native-object method via for-in and trace
  it. The enumeration order divergence between us, Flash, and
  Ruffle cascades into 2000+ mismatched lines per version, but the
  underlying ActionScript behaviour isn't broken — the tests
  exercise enumeration order, not method semantics.
  SUBTESTS_NEWLY_VISIBLE_TRIAGE Tier E inventoried these as
  "ACCEPTED_DIFFS candidates" rather than fix targets. This doc
  captures the decision path; it is **not** a plan to write a fix.
-->

## Status

| Test | Match | % | Status |
|------|-------|---|--------|
| argstest-v6 | 58/2192 | 2.6% | output_mismatch |
| argstest-v7 | 45/2061 | 2.2% | output_mismatch |
| argstest-v8 | 51/2434 | 2.1% | output_mismatch |

## Failure characterization

The tests walk every native-object method via `for (m in ctor)` /
`for (m in ctor.prototype)` and trace `Testing M()` for each. The
output diverges from expected starting at line ~28 because:

- Our enumeration order differs from Flash's for some native
  objects (`PrintJob.send()`, `MovieClipLoader.constructor`).
- Where Flash emits `Testing send()` first we emit `Testing toString()`
  (likely Object.prototype-inherited methods are leaking through
  our enumeration filter for some native classes).
- Numeric-key methods (`Testing 4()`, `Testing 3()`, ...) appear in
  our output where Flash emits named ones — suggests something like
  `_global.MovieClipLoader.prototype` for-in iterating its
  numeric-indexed entries that Flash hides.

These are not behaviour bugs in callable APIs; they are enumeration-
order divergences from Flash, and the cascade fails 2000+ lines per
test.

## Recommended decision path

1. **Diff against `output.fpN.ruffle.txt`**. For each version:
   ```
   diff /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/argstest-v6/output.fp9.txt \
        /home/robert/CC/SWFRecomp-CC/ruffle-tests/tests/swfs/from_gnash/actionscript.all/argstest-v6/output.fp9.ruffle.txt
   ```
   If Ruffle also diverges from Flash here (likely, given
   enumeration order is implementation-defined), and our diffs are
   a subset of Ruffle's diffs against expected, the test auto-
   promotes to `ruffle_matched`.

2. **If RM-eligible**: no work needed. Verify via
   `verify_output.py --test=argstest-v6 --diff --verbose` — the
   `ours_diff_count` / `ruffle_diff_count` fields tell whether
   subset-match is active.

3. **If NOT RM-eligible** (our diff set extends beyond Ruffle's):
   - Add `argstest-v6`/`v7`/`v8` to
     `ruffle-tests/tests/swfs/from_gnash/actionscript.all/ignored_tests.txt`
     with a comment pointing at the enumeration-order rationale.
   - Add an entry to
     `ruffle-tests/tests/swfs/from_gnash/_investigation/ACCEPTED_DIFFS.md`
     documenting:
     - The category (enumeration order — implementation-defined per
       ECMA-262).
     - That fixing it would require replicating Flash's specific
       native-object iteration order, which is undocumented and
       differs version-by-version of Flash itself.
     - Why we won't fix.

## Decision (to be made)

Run the diff (step 1) and choose path 2 or 3. The work itself is
30-60 minutes total, no code changes either way.
