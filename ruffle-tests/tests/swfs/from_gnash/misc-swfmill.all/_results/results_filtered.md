# Ruffle Test Results (Filtered)

**Date**: 2026-05-01 01:42 UTC

**Git SHA**: `88cfa5ac26`

**Run Duration**: 5m 11s

**Filtered**: 0 tests ignored out of 18 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **15** (83.3%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **16** (88.9%) |
| Failing | 2 |
| Total expected lines | 51 |
| Matching lines | 48 (94.1%) |
| Mismatched lines | 3 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**15 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 17.1s |  |
| 2 | `background` | 0 | 18.5s |  |
| 3 | `dict_callframe` | 3 | 17.3s |  |
| 4 | `dict_cross` | 3 | 17.1s |  |
| 5 | `dict_event` | 5 | 17.0s |  |
| 6 | `dict_override` | 2 | 17.2s |  |
| 7 | `func_dict` | 3 | 17.2s |  |
| 8 | `initaction_in_definesprite` | 2 | 14.8s |  |
| 9 | `jump_after_end` | 3 | 17.7s |  |
| 10 | `missing_bitmap` | 0 | 17.9s |  |
| 11 | `mixed-bytecode-as2` | 1 | 17.0s |  |
| 12 | `trace-as2/root_onload` | 4 | 18.2s |  |
| 13 | `trace-as2/shortstack` | 2 | 17.9s |  |
| 14 | `trace-as2/super` | 8 | 18.4s |  |
| 15 | `trace-as2/this` | 8 | 17.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 17.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `tags_after_last_showframe` | 6.7% | 1/15 | 15 | 1 |  |
| 2 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
