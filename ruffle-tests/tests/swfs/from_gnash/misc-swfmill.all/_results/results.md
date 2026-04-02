# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-02 20:20 UTC

**Git SHA**: `b8938ab392`

**Run Duration**: 4m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 14 |
| Passing | **11** (78.6%) |
| Failing | 3 |
| Total expected lines | 29 |
| Matching lines | 25 (86.2%) |
| Mismatched lines | 4 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**11 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 17.0s |  |
| 2 | `background` | 0 | 17.3s |  |
| 3 | `dict_callframe` | 3 | 17.4s |  |
| 4 | `dict_cross` | 3 | 17.3s |  |
| 5 | `dict_override` | 2 | 16.7s |  |
| 6 | `func_dict` | 3 | 17.1s |  |
| 7 | `initaction_in_definesprite` | 2 | 16.8s |  |
| 8 | `jump_after_end` | 3 | 17.0s |  |
| 9 | `missing_bitmap` | 0 | 17.1s |  |
| 10 | `mixed-bytecode-as2` | 1 | 17.2s |  |
| 11 | `zeroframe_definesprite` | 3 | 18.3s |  |

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

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `dict_event` | 60.0% | 3/5 | 5 | 5 |  |
| 2 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
| 3 | `tags_after_last_showframe` | 0.0% | 0/15 | 15 | 1 |  |
