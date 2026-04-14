# Ruffle Test Results (Filtered)

**Date**: 2026-04-13 23:00 UTC

**Git SHA**: `1d207c1674`

**Run Duration**: 5m 46s

**Filtered**: 0 tests ignored out of 18 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **14** (77.8%) |
| Failing | 4 |
| Total expected lines | 51 |
| Matching lines | 45 (88.2%) |
| Mismatched lines | 6 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 18.7s |  |
| 2 | `background` | 0 | 19.1s |  |
| 3 | `dict_callframe` | 3 | 20.9s |  |
| 4 | `dict_cross` | 3 | 19.8s |  |
| 5 | `dict_override` | 2 | 19.3s |  |
| 6 | `func_dict` | 3 | 19.2s |  |
| 7 | `initaction_in_definesprite` | 2 | 18.8s |  |
| 8 | `jump_after_end` | 3 | 19.3s |  |
| 9 | `missing_bitmap` | 0 | 19.6s |  |
| 10 | `mixed-bytecode-as2` | 1 | 19.2s |  |
| 11 | `trace-as2/shortstack` | 2 | 18.7s |  |
| 12 | `trace-as2/super` | 8 | 18.8s |  |
| 13 | `trace-as2/this` | 8 | 19.0s |  |
| 14 | `zeroframe_definesprite` | 3 | 18.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `dict_event` | 60.0% | 3 | 5 | 2 |  |
| 2 | `trace-as2/root_onload` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `dict_event` | 60.0% | 3/5 | 5 | 5 |  |
| 2 | `trace-as2/root_onload` | 50.0% | 2/4 | 4 | 4 |  |
| 3 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
| 4 | `tags_after_last_showframe` | 0.0% | 0/15 | 15 | 1 |  |
