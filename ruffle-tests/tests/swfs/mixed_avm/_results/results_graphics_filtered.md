# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 09:54 UTC

**Git SHA**: `6591538655`

**Run Duration**: 0m 59s

**Filtered**: 0 tests ignored out of 12 available

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
| 1 | `avm1_doabc` | 1 | 1.4s |  |
| 2 | `avm1_loads_avm2_doaction` | 2 | 1.9s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 2.1s |  |
| 4 | `avm2_doaction` | 1 | 5.7s |  |
| 5 | `avm2_loads_avm1` | 14 | 8.6s |  |
| 6 | `avm2_loads_avm1_doabc` | 4 | 7.6s |  |
| 7 | `avm2_loads_avm1_loads_avm2_doabc` | 3 | 3.5s |  |
| 8 | `avm2_loads_avm1_loads_into_root` | 2 | 2.3s |  |
| 9 | `avm2_loads_avm1_v10` | 8 | 6.2s |  |
| 10 | `avm2_loads_avm1_v9` | 8 | 8.2s |  |

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
