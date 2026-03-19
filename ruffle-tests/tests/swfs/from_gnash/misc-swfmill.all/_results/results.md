# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-19 20:52 UTC

**Git SHA**: `f246282a73`

**Run Duration**: 5m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 14 |
| Passing | **3** (21.4%) |
| Failing | 11 |
| Total expected lines | 7 |
| Matching lines | 2 (28.6%) |
| Mismatched lines | 5 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Compile Fail | 8 | 72.7% |
| Output Mismatch | 3 | 27.3% |

## Passing Tests

**3 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `background` | 0 | 15.5s |  |
| 2 | `missing_bitmap` | 0 | 15.3s |  |
| 3 | `mixed-bytecode-as2` | 1 | 16.3s |  |

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

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `jump_after_end` | 33.3% | 1/3 | 1 | 3 |  |
| 2 | `initaction_in_definesprite` | 0.0% | 0/2 | 0 | 2 |  |
| 3 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
