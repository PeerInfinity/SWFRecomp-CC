# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 18:36 UTC

**Git SHA**: `2358a37b1c`

**Run Duration**: 0m 54s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 11 |
| Passing | **3** (27.3%) |
| Failing | 8 |
| Total expected lines | 53 |
| Matching lines | 19 (35.8%) |
| Mismatched lines | 34 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**3 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm1_doabc` | 1 | 2.1s |  |
| 2 | `avm1_sprite_sc_ignored` | 3 | 2.1s |  |
| 3 | `avm2_doaction` | 1 | 7.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm1_loads_avm2_doaction` | 50.0% | 2 | 4 | 2 |  |
| 2 | `avm2_loads_avm1_loads_into_root` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm1_loads_avm2_doaction` | 50.0% | 2/4 | 4 | 2 |  |
| 2 | `avm2_loads_avm1_loads_into_root` | 50.0% | 1/2 | 1 | 2 |  |
| 3 | `avm1_loads_avm2` | 42.9% | 3/7 | 3 | 7 |  |
| 4 | `avm2_loads_avm1_v10` | 37.5% | 3/8 | 6 | 8 |  |
| 5 | `avm2_loads_avm1_loads_avm2_doabc` | 33.3% | 1/3 | 1 | 3 |  |
| 6 | `avm2_loads_avm1_doabc` | 25.0% | 1/4 | 1 | 4 |  |
| 7 | `avm2_loads_avm1_v9` | 25.0% | 2/8 | 6 | 8 |  |
| 8 | `avm2_loads_avm1` | 7.1% | 1/14 | 6 | 14 |  |
