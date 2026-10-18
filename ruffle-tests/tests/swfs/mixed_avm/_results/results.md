# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-18 08:49 UTC

**Git SHA**: `f555113796`

**Run Duration**: 0m 59s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 12 |
| Passing | **10** (83.3%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **11** (91.7%) |
| Failing | 1 |
| Total expected lines | 79 |
| Matching lines | 57 (72.2%) |
| Mismatched lines | 22 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm1_doabc` | 1 | 1.2s |  |
| 2 | `avm1_loads_avm2_doaction` | 2 | 1.5s |  |
| 3 | `avm1_sprite_sc_ignored` | 3 | 1.4s |  |
| 4 | `avm2_doaction` | 1 | 7.3s |  |
| 5 | `avm2_loads_avm1` | 14 | 7.8s |  |
| 6 | `avm2_loads_avm1_doabc` | 4 | 7.7s |  |
| 7 | `avm2_loads_avm1_loads_avm2_doabc` | 3 | 5.2s |  |
| 8 | `avm2_loads_avm1_loads_into_root` | 2 | 2.6s |  |
| 9 | `avm2_loads_avm1_v10` | 8 | 6.2s |  |
| 10 | `avm2_loads_avm1_v9` | 8 | 7.6s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm2_loads_avm1_events` | 18 | 18 | 8.0s |  |

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
