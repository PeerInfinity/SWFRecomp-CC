# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-18 04:04 UTC

**Git SHA**: `ef1e80b3a4`

**Run Duration**: 3m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 14 |
| Passing | **4** (28.6%) |
| Failing | 10 |
| Total expected lines | 17 |
| Matching lines | 8 (47.1%) |
| Mismatched lines | 9 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 60.0% |
| Compile Fail | 4 | 40.0% |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `background` | 0 | 15.5s |  |
| 2 | `dict_callframe` | 3 | 15.9s |  |
| 3 | `missing_bitmap` | 0 | 16.3s |  |
| 4 | `mixed-bytecode-as2` | 1 | 15.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `afunc_dict` | 50.0% | 1 | 2 | 1 |  |
| 2 | `dict_override` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `afunc_dict` | 50.0% | 1/2 | 2 | 2 |  |
| 2 | `dict_override` | 50.0% | 1/2 | 2 | 2 |  |
| 3 | `func_dict` | 33.3% | 1/3 | 3 | 3 |  |
| 4 | `zeroframe_definesprite` | 33.3% | 1/3 | 3 | 3 |  |
| 5 | `initaction_in_definesprite` | 0.0% | 0/2 | 0 | 2 |  |
| 6 | `tags_after_last_showframe` | 0.0% | 0/15 | 15 | 1 |  |
