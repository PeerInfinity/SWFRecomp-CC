# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-19 02:28 UTC

**Git SHA**: `5002fe1163`

**Run Duration**: 3m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 14 |
| Passing | **8** (57.1%) |
| Failing | 6 |
| Total expected lines | 26 |
| Matching lines | 18 (69.2%) |
| Mismatched lines | 8 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 83.3% |
| Compile Fail | 1 | 16.7% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 15.8s |  |
| 2 | `background` | 0 | 15.4s |  |
| 3 | `dict_callframe` | 3 | 15.6s |  |
| 4 | `dict_cross` | 3 | 15.8s |  |
| 5 | `dict_override` | 2 | 15.2s |  |
| 6 | `func_dict` | 3 | 14.8s |  |
| 7 | `missing_bitmap` | 0 | 14.4s |  |
| 8 | `mixed-bytecode-as2` | 1 | 15.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `dict_event` | 60.0% | 3 | 5 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `dict_event` | 60.0% | 3/5 | 5 | 5 |  |
| 2 | `zeroframe_definesprite` | 33.3% | 1/3 | 3 | 3 |  |
| 3 | `initaction_in_definesprite` | 0.0% | 0/2 | 0 | 2 |  |
| 4 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
| 5 | `tags_after_last_showframe` | 0.0% | 0/15 | 15 | 1 |  |
