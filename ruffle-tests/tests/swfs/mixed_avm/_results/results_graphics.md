# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-15 09:18 UTC

**Git SHA**: `86434112a7`

**Run Duration**: 1m 24s

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
| 2 | `avm1_loads_avm2_doaction` | 2 | 2.2s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 23.3s |  |
| 4 | `avm2_doaction` | 1 | 7.7s |  |
| 5 | `avm2_loads_avm1` | 14 | 8.1s |  |
| 6 | `avm2_loads_avm1_doabc` | 4 | 7.8s |  |
| 7 | `avm2_loads_avm1_loads_avm2_doabc` | 3 | 5.4s |  |
| 8 | `avm2_loads_avm1_loads_into_root` | 2 | 8.0s |  |
| 9 | `avm2_loads_avm1_v10` | 8 | 7.9s |  |
| 10 | `avm2_loads_avm1_v9` | 8 | 8.4s |  |

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
