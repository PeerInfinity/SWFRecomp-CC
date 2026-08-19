# Ruffle Test Results (Filtered)

**Date**: 2026-08-19 13:28 UTC

**Git SHA**: `9d038c750e`

**Run Duration**: 0m 53s

**Filtered**: 0 tests ignored out of 11 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 11 |
| Passing | **10** (90.9%) |
| Failing | 1 |
| Total expected lines | 53 |
| Matching lines | 49 (92.5%) |
| Mismatched lines | 4 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm1_doabc` | 1 | 0.9s |  |
| 2 | `avm1_loads_avm2_doaction` | 2 | 1.4s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 1.4s |  |
| 4 | `avm2_doaction` | 1 | 7.1s |  |
| 5 | `avm2_loads_avm1` | 14 | 5.8s |  |
| 6 | `avm2_loads_avm1_doabc` | 4 | 7.5s |  |
| 7 | `avm2_loads_avm1_loads_avm2_doabc` | 3 | 7.4s |  |
| 8 | `avm2_loads_avm1_loads_into_root` | 2 | 7.2s |  |
| 9 | `avm2_loads_avm1_v10` | 8 | 7.5s |  |
| 10 | `avm2_loads_avm1_v9` | 8 | 5.0s |  |

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

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm1_loads_avm2` | 42.9% | 3/7 | 3 | 7 |  |
