# Ruffle known_failure Handling Plan
<!-- TESTS: Inheritance-v5, Inheritance-v6, Inheritance-v7, Inheritance-v8 -->

<!-- PLAN_META
id: GNASH_RUFFLE_KNOWN_FAILURE
status: incomplete
phases:
  - id: 1
    name: "Document Inheritance super-chain as Ruffle-matching"
    status: not_started
  - id: 2
    name: "Add Inheritance-v6/v7/v8 to ACCEPTED_DIFFS and ignored_tests"
    status: not_started
  - id: 3
    name: "Broader: survey 84 known_failure overlap and decide on output.ruffle.txt support"
    status: not_started
dependencies: []
blockers: []
-->

Last updated: 2026-04-13

## Status: IN PROGRESS — Inheritance super-chain investigation complete, accepted-diff write-up and broader known_failure survey pending

## Summary

Investigation of the remaining Inheritance-v6/v7/v8 super-chain diffs (documented
as "deep super-chain semantic rewrite needed" in `INHERITANCE_SEGFAULT_PLAN.md`
Fix 3) turned up a much broader finding: **84 of our 95 failing Gnash
actionscript.all tests are tests that Ruffle itself cannot pass** (they ship
with `known_failure = true` and an `output.ruffle.txt` file recording
Ruffle's own divergent output). For the Inheritance tests specifically, our
diffs against Flash's expected output are a strict subset of Ruffle's diffs
against the same file — we are already doing **at least as well as Ruffle**
on every line of every Inheritance test.

This plan has two threads:

1. **Inheritance resolution (Phase 1–2):** Document the finding, mark
   Inheritance-v6/v7/v8 as accepted Ruffle-matching diffs, and move
   `INHERITANCE_SEGFAULT_PLAN.md` to `complete/`.
2. **Broader known_failure handling (Phase 3):** Survey the 84 overlapping
   tests, identify any where we're strictly better than Ruffle, and propose a
   `verify_output.py` enhancement to recognise "our diffs are a subset of
   Ruffle's diffs" as a pass condition for `known_failure` tests.

## Finding 1: Ruffle's Inheritance tests are all known_failure

All four `Inheritance-v{5,6,7,8}` test directories in `~/CC/ruffle/tests/tests/swfs/from_gnash/actionscript.all/` carry `known_failure = true` in `test.toml` and ship an `output.ruffle.txt` file containing Ruffle's actual output. The toml comment reads:

```toml
# Note: due to Flash Player Oddities (frame 1 behavior), Ruffle traces an
# extra line at the end of the test. Other checks probably fail for unrelated
# reasons.
known_failure = true
```

The "extra line" is the `PASSED: !a instanceof b` egg/chicken survival check
already documented in `ACCEPTED_DIFFS.md`. The "other checks" — which the
Ruffle maintainers left unspecified — are the super-chain semantics:

- v7/v8 line 337: `n == "undefinedFFC"` (Flash) vs `undefinedFC` (Ruffle & us)
- v7/v8 line 338: `FctorCalls == 1` (Flash) vs `0` (Ruffle & us)
- v6 lines 255/286/289/331/332/334: `A.B.B` / `FAAC` / `ActorCalls==1` / `FFFC`
  / `FctorCalls==1` / `ActorCalls==1` (Flash) vs the "one-level-shallower"
  chain values (Ruffle & us)

## Finding 2: Our diffs against Flash are a subset of Ruffle's diffs

Running the tests locally (2026-04-13) and comparing our actual output to both
Flash's `output.txt` and Ruffle's `output.ruffle.txt`:

| Test | Our diffs vs Flash | Ruffle diffs vs Flash | Our diffs ⊆ Ruffle's? |
|------|--------------------|------------------------|-----------------------|
| Inheritance-v5 | 1  | 17 | YES |
| Inheritance-v6 | 9  | 16 | YES |
| Inheritance-v7 | 5  | 10 | YES |
| Inheritance-v8 | 5  | 10 | YES |

Where Ruffle and we both fail (super-chain lines), we produce identical output
to Ruffle. Where Ruffle fails but we pass:

- **v5**: Multiple SWF5 version-gate fixes (Fix 3 in `INHERITANCE_SEGFAULT_PLAN.md`) moved us ahead of Ruffle — SWF5 `super` undefined, `Function.prototype.apply` hidden, `extends` `__constructor__` skipped.
- **v6/v7/v8**: We pass `functionObject.__proto__.constructor == Function`, `SubObj1.prototype.constructor.__proto__.constructor == Function`, `DerivedClass1.hasOwnProperty('constructor')`, `DerivedClass1.constructor == Function` — Ruffle fails all of these because their `[type Function]` stringification differs from Flash's `Function` on these specific chained comparisons. **v6** additionally: we pass `ob instanceof A` and `ob instanceof C` which Ruffle fails.

So for every Inheritance test, the story is: we match Ruffle on the super-chain lines (Flash-specific quirks neither of us replicates), and we exceed Ruffle on several prototype/instanceof checks.

## Finding 3: Broader pattern — 84 of 95 Gnash failures are Ruffle known_failures

```
Gnash actionscript.all suite: 190 tests
├── 95 pass, 95 fail (us)
└── 115 tests marked known_failure in Ruffle (have output.ruffle.txt)
    ├── 31 we already pass (strictly better than Ruffle)
    └── 84 we fail (pass rate in this subset: 0%)

Breakdown of our 95 failures:
├── 84 are Ruffle known_failures → we may already match or exceed Ruffle
│       on these tests
└── 11 are Ruffle-passing tests → these are genuine "we diverge from
        Ruffle" failures: ExternalInterface-v6/v7, System-v5/v6/v7/v8,
        TextFieldHTML-v6/v7/v8, Transform-v6/v7
```

The **11 Ruffle-passing tests we fail** are the highest-value targets for
further investigation — fixing any of those is a strict improvement.

The **84 Ruffle-known-failure tests we also fail** deserve a systematic
re-evaluation: how many of them already produce output that is "at least as
good as Ruffle's"?

## Phase 1: Document Inheritance super-chain findings

Add a new section to `INHERITANCE_SEGFAULT_PLAN.md` (or a new
`RUFFLE_VS_FLASH_DIFFERENCES.md` equivalent under `from_gnash/_investigation/`)
capturing:

- All 4 Inheritance tests carry `known_failure = true` in the upstream Ruffle
  tree
- Our diffs against Flash's `output.txt` are a strict subset of Ruffle's
  diffs for all 4 versions
- The remaining v6/v7/v8 super-chain lines are Flash-specific behaviour
  neither Ruffle nor we implement
- Investigation into "fix super-chain to match Flash" is explicitly **out of
  scope** — it would require reverse-engineering Flash-only semantics that
  Ruffle has chosen not to replicate.

Outcome: Inheritance-v6/v7/v8 treated as accepted Ruffle-matching diffs, NOT
deep-rewrite targets.

## Phase 2: Add Inheritance-v6/v7/v8 to ACCEPTED_DIFFS and ignored_tests

Add a new section to `ACCEPTED_DIFFS.md`:

> **Inheritance-v6 / v7 / v8 — super-chain dynamic base class semantics**
>
> Tests carry `known_failure = true` upstream in Ruffle. Our output matches
> Ruffle's for all super-chain lines; our diffs against Flash's expected
> output are a proper subset of Ruffle's diffs. See new plan document.

Add Inheritance-v6/v7/v8 to `ignored_tests.txt` alongside Inheritance-v5.

Regenerate `FAILING_TESTS_BY_FEATURE.md` / `_FILTERED.md` — the filtered
document should drop all 4 Inheritance tests (removing the category entirely).

Move `INHERITANCE_SEGFAULT_PLAN.md` to `complete/` with a closing note.

**Expected filtered pass rate:** 95/181 = 52.5% (removing 3 more tests from
the denominator).

## Phase 3: Broader known_failure survey (future work)

Build a small report that, for each of the 84 Ruffle-known_failure tests we
fail, computes:

- Our diff count against `output.txt`
- Ruffle's diff count against `output.txt` (from `output.ruffle.txt`)
- Whether our diffs are a subset of Ruffle's diffs

Candidate criteria for "matches Ruffle" / "at-least-as-good" promotion to
filtered-pass:

1. **Subset criterion:** every line where our output differs from
   `output.txt`, Ruffle's output also differs. This is the criterion that
   fits the Inheritance tests.
2. **Identity criterion:** our filtered output byte-for-byte matches
   `output.ruffle.txt`. Too strict — we beat Ruffle on many lines.
3. **Line-count criterion:** our diff count is ≤ Ruffle's diff count. Cruder
   than the subset criterion but simpler.

Proposed implementation path:

- Copy `output.ruffle.txt` files from `~/CC/ruffle` into our test directories
  (or reference them via a manifest).
- Extend `verify_output.py` with a new status `ruffle_matched` or equivalent:
  when a test has `known_failure = true` and ships `output.ruffle.txt`, and
  our diffs-vs-`output.txt` ⊆ Ruffle's diffs-vs-`output.txt`, emit status
  `ruffle_matched` instead of `output_mismatch`.
- Update `filter_results.py` to count `ruffle_matched` as pass in filtered
  stats.
- Regenerate reports.

This is a test-framework enhancement and is **not** scope-creep for the
Inheritance investigation — it's a candidate follow-up if we want to
systematically benefit from the 84-test overlap.

## Priority

**Phase 1 + 2:** High — unblocks closing out `INHERITANCE_SEGFAULT_PLAN.md` and
immediately improves filtered pass rate by 3 tests.

**Phase 3:** Medium — larger scope, potentially flipping 20–40 additional
tests across suites (avm1 also has 23 known_failure tests, some of which we
already match). Worth a dedicated follow-up session.

## Related Documents

- `incomplete/INHERITANCE_SEGFAULT_PLAN.md` — current home of Inheritance
  analysis, to be moved to `complete/` once Phase 2 lands.
- `ACCEPTED_DIFFS.md` — where Inheritance-v6/v7/v8 will be documented.
- `actionscript.all/ignored_tests.txt` — where the three tests will be added.
- `../../../verify_output.py` — Phase 3 implementation target.
