# Ruffle Test Results (Filtered)

**Date**: 2026-04-04 02:19 UTC

**Git SHA**: `112f7a9df7`

**Run Duration**: 3m 58s

**Filtered**: 0 tests ignored out of 14 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 13 |
| Passing | **10** (76.9%) |
| Failing | 3 |
| Total expected lines | 26 |
| Matching lines | 22 (84.6%) |
| Mismatched lines | 4 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 18.7s |  |
| 2 | `background` | 0 | 18.2s |  |
| 3 | `dict_callframe` | 3 | 19.6s |  |
| 4 | `dict_override` | 2 | 18.1s |  |
| 5 | `func_dict` | 3 | 18.4s |  |
| 6 | `initaction_in_definesprite` | 2 | 18.3s |  |
| 7 | `jump_after_end` | 3 | 18.1s |  |
| 8 | `missing_bitmap` | 0 | 18.0s |  |
| 9 | `mixed-bytecode-as2` | 1 | 17.8s |  |
| 10 | `zeroframe_definesprite` | 3 | 18.2s |  |

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
