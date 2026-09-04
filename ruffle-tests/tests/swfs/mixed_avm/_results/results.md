# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 09:14 UTC

**Git SHA**: `2002bc3ece`

**Run Duration**: 1m 15s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 12 |
| Passing | **10** (83.3%) |
| Failing | 2 |
| Total expected lines | 79 |
| Matching lines | 56 (70.9%) |
| Mismatched lines | 23 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm1_doabc` | 1 | 1.0s |  |
| 2 | `avm1_loads_avm2_doaction` | 2 | 1.4s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 14.5s |  |
| 4 | `avm2_doaction` | 1 | 7.1s |  |
| 5 | `avm2_loads_avm1` | 14 | 6.0s |  |
| 6 | `avm2_loads_avm1_doabc` | 4 | 6.2s |  |
| 7 | `avm2_loads_avm1_loads_avm2_doabc` | 3 | 7.4s |  |
| 8 | `avm2_loads_avm1_loads_into_root` | 2 | 7.2s |  |
| 9 | `avm2_loads_avm1_v10` | 8 | 7.2s |  |
| 10 | `avm2_loads_avm1_v9` | 8 | 7.4s |  |

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
| 1 | `avm1_loads_avm2` | 42.9% | 3/7 | 3 | 7 |  |
| 2 | `avm2_loads_avm1_events` | 26.9% | 7/26 | 25 | 26 |  |
