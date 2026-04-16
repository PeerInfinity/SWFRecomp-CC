# Gnash Flaky Tests

Tests whose **matched-line count varies between identical runs**. These are not
regressions — the test itself consumes non-determinism (typically `Math.random()`),
so the actual output contains run-dependent values.

If `results_diff.md` flags one of these with a small `matching_lines` wobble
(e.g. ±2/560) and **no pass/fail flip**, the cause is almost certainly run-to-run
noise, not a code change.

This is distinct from `ACCEPTED_DIFFS.md` (permanent diffs where specific lines
never match) — here the *count* of mismatched lines is what's non-deterministic,
and a given line might happen to match the expected value by coincidence on any
given run.

---

## actionscript.all / array-v5 — `Array.sort(randomComparator)` (observed ±2/560)

**Observed variance (5 local back-to-back runs):** matching_lines = 461, 459, 459, 461, 459.

**Cause:** The test defines `randomComparator = function(a, b) { return Math.random() < 0.5 ? -1 : 1; }`
and calls `trysortarray.sort(randomComparator)`. Subsequent assertions inspect
`trysortarray[i]` and `trysortarray.toString()`, so the actual output contains
the sorted-by-coin-flip element order. The expected output (generated once by
Gnash at record time) captured one particular random ordering.

Example lines that flip between runs (all stay FAILED against expected; only the
`obtained:` value changes):

```
FAILED: expected: "2,4" obtained: 5    [./array.as:469]
FAILED: expected: "2,4" obtained: 0    [./array.as:469]

FAILED: expected: ""    obtained: 5    [./array.as:472]
FAILED: expected: ""    obtained: 0    [./array.as:472]

FAILED: expected: ""    obtained: 5    [./array.as:499]
FAILED: expected: ""    obtained: 0    [./array.as:499]
```

Our `Math.random()` is seeded from `time(NULL)` on first use (avmplus-compatible
RNG, see `SWFModernRuntime/src/actionmodern/math.c`), so different launch times
produce different sort orders.

**Decision:** Accept as flaky. A `±2/560` `matching_lines` wobble on array-v5 in
`results_diff.md` is noise, not a regression. Only investigate if a pass/fail
transition appears, or if the wobble exceeds the observed range.

---

## Summary Table

| Test | Observed range | Cause |
|------|---------------|-------|
| actionscript.all / array-v5 | matching_lines 459–461 / 560 | `Math.random()` inside `Array.sort` comparator |
