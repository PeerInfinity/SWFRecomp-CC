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

**Status (2026-04-16):** The only entry below (`array-v5`) is RESOLVED. Ruffle-style
deterministic RNG seeding in test builds (commit `f42c9fc2`) eliminates the
`Math.random()` source of flakiness across the whole suite — this file is kept as a
record of the fix and as the place to log any future test that becomes flaky.

---

## ~~actionscript.all / array-v5~~ — RESOLVED (2026-04-16)

**Was:** `Array.sort(randomComparator)` produced run-dependent element order.
Observed variance across 5 local back-to-back runs: matching_lines = 461, 459, 459,
461, 459 (out of 560).

**Cause:** The test defines `randomComparator = function(a, b) { return Math.random() < 0.5 ? -1 : 1; }`
and calls `trysortarray.sort(randomComparator)`. Subsequent assertions inspect
`trysortarray[i]` and `trysortarray.toString()`, so the actual output contained
the sorted-by-coin-flip element order. The expected output (generated once by
Gnash at record time) captured one particular random ordering.

Example lines that flipped between runs (all stayed FAILED against expected; only
the `obtained:` value changed):

```
FAILED: expected: "2,4" obtained: 5    [./array.as:469]
FAILED: expected: "2,4" obtained: 0    [./array.as:469]

FAILED: expected: ""    obtained: 5    [./array.as:472]
FAILED: expected: ""    obtained: 0    [./array.as:472]

FAILED: expected: ""    obtained: 5    [./array.as:499]
FAILED: expected: ""    obtained: 0    [./array.as:499]
```

Our `Math.random()` was seeded from `time(NULL)` on first use (avmplus-compatible
RNG), so different launch times produced different sort orders.

**Fix (commit `f42c9fc2`):** Match Ruffle's deterministic test mode. When
`MOCK_DATE_TIME` is defined — i.e. in test builds, where `constants.h` pins the
simulated "now" — seed the avmplus RNG from `MOCK_DATE_TIME * 1000` (milliseconds →
microseconds), which is exactly what Ruffle's `avm_rng::get_seed` does under its
`deterministic` feature: `get_current_date_time().timestamp_micros() as u32`.
Production builds (no `MOCK_DATE_TIME`) keep the `time(NULL)` seed so live
playback still gets a fresh stream each run.

```c
if (pRandomFast->uValue == 0) {
#ifdef MOCK_DATE_TIME
    RandomFastInit(pRandomFast, (uint32_t)((int64_t)(MOCK_DATE_TIME) * 1000LL));
#else
    RandomFastInit(pRandomFast, (uint32_t)time(NULL));
#endif
}
```

After the fix, `matching_lines` for `array-v5` is locked across reruns; the test
continues to show permanent diffs on those lines (the expected output encodes one
specific Gnash-era random ordering, which our Ruffle-compatible RNG does not
reproduce), but the *count* no longer wobbles. The test correctly falls under the
same category as other entries in `ACCEPTED_DIFFS.md` — some lines will never
match — but it does not need its own entry there because the non-matching lines
are a direct consequence of RNG-divergence from Gnash, not an implementation
choice on our side.

---

## Summary Table

| Test | Status | Cause | Fixed in |
|------|--------|-------|----------|
| ~~actionscript.all / array-v5~~ | RESOLVED | `Math.random()` inside `Array.sort` comparator | `f42c9fc2` (2026-04-16) |
