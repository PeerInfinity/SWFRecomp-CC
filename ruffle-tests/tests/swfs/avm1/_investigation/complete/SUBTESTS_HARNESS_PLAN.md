# `[subtests]` Harness Support Plan
<!-- TESTS: GradientFillTest, Date-v5, MovieClip-v6, Object-v6, setProperty-v5, matrix_accuracy_test1, … (70 total) -->

<!-- PLAN_META
id: SUBTESTS_HARNESS
status: completed
phases:
  - id: 1
    name: "Parse [subtests] in test.toml and enumerate variants"
    status: completed
  - id: 2
    name: "Pick canonical variant per test (or run all variants)"
    status: completed
  - id: 3
    name: "Wire output_path through verify_output.py expected-file selection"
    status: completed
  - id: 4
    name: "Validate against affected tests"
    status: completed
dependencies: []
blockers: []
-->

Last updated: 2026-05-14

## Status: COMPLETED — Option A (canonical-variant mode) shipped

`verify_output.py` now resolves the expected-output filename per-test via
a new `resolve_expected_filename(test_dir, suffix_override)` helper.
Resolution order:

1. `--expected-suffix=SUFFIX` (if given on the CLI) → `output.SUFFIX.txt`
2. `output.txt` if present (canonical / single-variant tests)
3. `[subtests]` table in `test.toml`: pick the variant with the highest
   `player_options.version` and use its `output_path`
4. Otherwise `None` (test excluded from discovery)

The matching Ruffle-actual filename (`output.fpN.ruffle.txt` etc.) is
derived from the resolved expected name, so the existing
`ruffle_matched` heuristic continues to work.

No runtime player-version override — we just compare our normal output
against the highest-version expected. Per-version-gated behavior
mismatches will land as line diffs and can be triaged via
`ACCEPTED_DIFFS.md` or fixed individually.

Verified locally:

- `GradientFillTest` → runs (resolves `output.fp10.txt`); image fails on
  real feature gaps (#2/#3 below), not the harness.
- `BitmapDataDraw` → resolves `output.fp15.txt`; reports
  `Ruffle-matched: 1 (100.0%)` (was `runtime_error` before).
- `matrix_accuracy_test1` → resolves `output.fp10.txt`; runs trace diff
  cleanly.
- `Date-v5`, `MovieClip-v6` (fp23), `Object-v6` (fp18-20) — picked up by
  discovery.
- `display_object_properties`, `matrix`, etc. (output.txt) → unchanged.

## Problem

70 tests across `from_gnash/actionscript.all`, `from_gnash/misc-swfc.all`, and
`from_gnash/misc-ming.all` ship a `[subtests]` block in `test.toml` that
declares per-Flash-Player-version expected outputs (`output.fp9.txt`,
`output.fp10.txt`, …, up to `output.fp32.txt`, plus range-style names like
`output.fp10-14.txt`). They do not ship a canonical `output.txt`.

`verify_output.py` only reads `output.txt`, so all 70 tests fail with
`FileNotFoundError` → `runtime_error` in our results. This makes the tests
appear broken when in fact most of them probably pass already against at
least one fp variant.

Example (`misc-ming.all/GradientFillTest/test.toml`):

```toml
[subtests.fp9]
output_path = "output.fp9.txt"
player_options.version = 9

[subtests.fp10]
output_path = "output.fp10.txt"
player_options.version = 10
```

Sample fp9-vs-fp10 diff (GradientFillTest): 8 lines out of 278. Most
per-variant diffs are similarly tiny.

## Affected Tests

70 tests with `[subtests]`. Discoverable via:

```bash
grep -rln "\[subtests\." ruffle-tests/tests/swfs/ | wc -l  # → 70
```

Subdirs:
- `from_gnash/actionscript.all/` — majority (Date-v5, MovieClip-v6, Object-v6, ops-v5, setProperty-v5, XML-v5, …)
- `from_gnash/misc-swfc.all/` — action_execution_order_test12, movieclip_destruction_test3, matrix_accuracy_test1
- `from_gnash/misc-ming.all/` — GradientFillTest (and probably BitmapDataDraw — has `output.fp9.txt`/`output.fp11.txt`/`output.fp15.txt` but no canonical `output.txt`)

## Design Considerations

### 1. Do we need actual player-version override at runtime?

Ruffle subtests run the same SWF with different `player_options.version`
values to exercise per-Flash-Player-version behavior gating. Our runtime has
`g_swf_version` (the SWF file's own version), but no separate concept of
player version.

**Practical observation:** fp9-vs-fp10 diffs are tiny (often <10 lines out
of hundreds). Player-version-gated behavior is rare and mostly cosmetic.

**Two options:**

**Option A — Canonical-variant mode (recommended for v1).** Pick the
highest fp variant per test (matches Ruffle's "newest player wins" default
in many runners), use its `output_path` as expected. Don't override player
version in our runtime — we just compare against the highest-version
expected. Per-test failures from version-gated behavior land in
`ACCEPTED_DIFFS.md` or get fixed individually. Unblocks all 70 tests
immediately.

**Option B — Full subtest support.** Run the SWF N times per test, once
per subtest, with each comparing to its own expected. Requires
`g_player_version` global separate from `g_swf_version`, plus identifying
and gating every per-player-version behavior. Big change. Returns a "did
all N subtests pass" result per test.

Recommendation: ship A. Reconsider B if version-gated diffs prove
widespread.

### 2. Range-style output_path naming

Some tests use `output.fp10-14.txt` to mean "same expected for fp10 through
fp14". Our code only needs to follow the `output_path` field literally —
no need to parse the version range from the filename.

### 3. Ruffle's `output.fp*.ruffle.txt` alongside `output.fp*.txt`

Many tests also ship a `*.ruffle.txt` per variant — Ruffle's own actual
output for that fp version, used by the existing "did Ruffle pass?"
heuristic (line ~2912 in `verify_output.py` that checks subset diffs against
Ruffle's known failures). When we pick variant fp10, we should look for
`output.fp10.ruffle.txt` rather than `output.ruffle.txt`.

## Implementation Plan

### Phase 1 — Parse `[subtests]`

`verify_output.py` already parses `test.toml` via `tomllib`. Extend the
parser to detect `subtests.*` tables and collect:

```python
{
    "fp9":  {"output_path": "output.fp9.txt",  "player_version": 9},
    "fp10": {"output_path": "output.fp10.txt", "player_version": 10},
    ...
}
```

### Phase 2 — Pick canonical variant

When `[subtests]` is present and no `output.txt` exists, select the variant
with the highest `player_version`. Use its `output_path` as the expected
file. Also use the matching `output.fpN.ruffle.txt` if present for the
known-failure subset heuristic.

CLI escape hatch: `--subtest-variant=fp9` to force a specific variant.
Otherwise the canonical-highest pick is automatic.

### Phase 3 — Wire output_path through the existing expected-file logic

`verify_output.py:445` (`discover_tests`) and `verify_output.py:2485`
(`expected_filename`) currently use a fixed name. Replace with: per-test
selected expected filename from Phase 2, with `output.txt` as the fallback
default when no `[subtests]` block exists.

`output.SUFFIX.txt` (`--expected-suffix`) flag and subtest selection are
orthogonal — keep both.

### Phase 4 — Validate

Run all 70 affected tests:

```bash
for d in $(grep -rln "\[subtests\." ruffle-tests/tests/swfs/ | xargs -n1 dirname); do
    suite=$(echo $d | sed 's|ruffle-tests/tests/swfs/||; s|/[^/]*$||')
    test=$(basename $d)
    python3 ruffle-tests/verify_output.py --tests-dir=ruffle-tests/tests/swfs/$suite --test=$test
done
```

Expected outcome: 60+ tests should move from `runtime_error` to either
`pass` or a normal line-diff failure (the latter genuinely needing
investigation). Group failures by category:

- Already passing under Option A (canonical variant matches): land as PASS
- Failing on per-version-gated behavior: candidates for ACCEPTED_DIFFS.md
  or for moving to Option B in a future plan
- Failing on real feature gaps: separate plans per gap

## Out of Scope

- Actual player-version override at runtime (Option B above).
- Subtests for image comparisons (`[image_comparisons.subtests.…]` if any).
- Cross-version regression matrix CI.

## Estimated Complexity

Low. Python-only change, ~80–150 LOC in `verify_output.py`. No C runtime
work. Most of the diff is plumbing the selected expected path through the
existing test-running code.
