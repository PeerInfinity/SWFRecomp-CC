# Ruffle Test Results (Filtered)

**Date**: 2026-08-19 16:36 UTC

**Git SHA**: `a946ee1838`

**Run Duration**: 1m 23s

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
| 1 | `avm1_doabc` | 1 | 2.2s |  |
| 2 | `avm1_loads_avm2_doaction` | 2 | 1.6s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 22.2s |  |
| 4 | `avm2_doaction` | 1 | 6.4s |  |
| 5 | `avm2_loads_avm1` | 14 | 9.1s |  |
| 6 | `avm2_loads_avm1_doabc` | 4 | 6.6s |  |
| 7 | `avm2_loads_avm1_loads_avm2_doabc` | 3 | 9.0s |  |
| 8 | `avm2_loads_avm1_loads_into_root` | 2 | 8.7s |  |
| 9 | `avm2_loads_avm1_v10` | 8 | 5.7s |  |
| 10 | `avm2_loads_avm1_v9` | 8 | 9.0s |  |

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
