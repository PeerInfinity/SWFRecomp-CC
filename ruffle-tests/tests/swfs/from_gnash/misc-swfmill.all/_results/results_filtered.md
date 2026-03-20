# Ruffle Test Results (Filtered)

**Date**: 2026-03-20 22:35 UTC

**Git SHA**: `d218f87130`

**Run Duration**: 3m 40s

**Filtered**: 0 tests ignored out of 14 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 14 |
| Passing | **8** (57.1%) |
| Failing | 6 |
| Total expected lines | 29 |
| Matching lines | 18 (62.1%) |
| Mismatched lines | 11 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 15.2s |  |
| 2 | `background` | 0 | 15.8s |  |
| 3 | `dict_callframe` | 3 | 15.3s |  |
| 4 | `dict_cross` | 3 | 15.4s |  |
| 5 | `dict_override` | 2 | 15.9s |  |
| 6 | `func_dict` | 3 | 15.6s |  |
| 7 | `missing_bitmap` | 0 | 15.7s |  |
| 8 | `mixed-bytecode-as2` | 1 | 15.7s |  |

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

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `dict_event` | 60.0% | 3/5 | 5 | 5 |  |
| 2 | `jump_after_end` | 33.3% | 1/3 | 1 | 3 |  |
| 3 | `initaction_in_definesprite` | 0.0% | 0/2 | 0 | 2 |  |
| 4 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
| 5 | `tags_after_last_showframe` | 0.0% | 0/15 | 15 | 1 |  |
| 6 | `zeroframe_definesprite` | 0.0% | 0/3 | 2 | 3 |  |
