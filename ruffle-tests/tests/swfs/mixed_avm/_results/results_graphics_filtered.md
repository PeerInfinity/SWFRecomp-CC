# Ruffle Test Results (Filtered)

**Date**: 2026-08-13 22:38 UTC

**Git SHA**: `3db858cbc1`

**Run Duration**: 1m 19s

**Filtered**: 0 tests ignored out of 11 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 11 |
| Passing | **7** (63.6%) |
| Failing | 4 |
| Total expected lines | 53 |
| Matching lines | 40 (75.5%) |
| Mismatched lines | 13 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm1_doabc` | 1 | 1.6s |  |
| 2 | `avm1_loads_avm2_doaction` | 2 | 2.1s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 21.4s |  |
| 4 | `avm2_doaction` | 1 | 7.4s |  |
| 5 | `avm2_loads_avm1_doabc` | 4 | 6.5s |  |
| 6 | `avm2_loads_avm1_loads_avm2_doabc` | 3 | 6.4s |  |
| 7 | `avm2_loads_avm1_loads_into_root` | 2 | 8.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm2_loads_avm1_v9` | 87.5% | 7 | 8 | 1 |  |
| 2 | `avm2_loads_avm1` | 64.3% | 9 | 14 | 5 |  |
| 3 | `avm2_loads_avm1_v10` | 62.5% | 5 | 8 | 3 |  |

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
| 1 | `avm2_loads_avm1_v9` | 87.5% | 7/8 | 7 | 8 |  |
| 2 | `avm2_loads_avm1` | 64.3% | 9/14 | 11 | 14 |  |
| 3 | `avm2_loads_avm1_v10` | 62.5% | 5/8 | 7 | 8 |  |
| 4 | `avm1_loads_avm2` | 42.9% | 3/7 | 3 | 7 |  |
