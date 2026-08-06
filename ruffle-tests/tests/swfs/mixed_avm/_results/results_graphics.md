# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-06 23:55 UTC

**Git SHA**: `fb36ba1100`

**Run Duration**: 1m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 11 |
| Passing | **4** (36.4%) |
| Failing | 7 |
| Total expected lines | 53 |
| Matching lines | 26 (49.1%) |
| Mismatched lines | 27 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm1_doabc` | 1 | 2.1s |  |
| 2 | `avm1_loads_avm2_doaction` | 2 | 2.0s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 21.2s |  |
| 4 | `avm2_doaction` | 1 | 7.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm2_loads_avm1_v9` | 87.5% | 7 | 8 | 1 |  |
| 2 | `avm2_loads_avm1_v10` | 62.5% | 5 | 8 | 3 |  |
| 3 | `avm2_loads_avm1_loads_into_root` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm2_loads_avm1_v9` | 87.5% | 7/8 | 7 | 8 |  |
| 2 | `avm2_loads_avm1_v10` | 62.5% | 5/8 | 7 | 8 |  |
| 3 | `avm2_loads_avm1_loads_into_root` | 50.0% | 1/2 | 1 | 2 |  |
| 4 | `avm1_loads_avm2` | 42.9% | 3/7 | 3 | 7 |  |
| 5 | `avm2_loads_avm1_loads_avm2_doabc` | 33.3% | 1/3 | 1 | 3 |  |
| 6 | `avm2_loads_avm1_doabc` | 25.0% | 1/4 | 1 | 4 |  |
| 7 | `avm2_loads_avm1` | 7.1% | 1/14 | 4 | 14 |  |
