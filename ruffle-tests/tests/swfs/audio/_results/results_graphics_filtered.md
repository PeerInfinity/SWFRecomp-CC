# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 16:10 UTC

**Git SHA**: `d045bec8a8`

**Run Duration**: 1m 16s

**Filtered**: 0 tests ignored out of 5 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 5 |
| Passing | **3** (60.0%) |
| Failing | 2 |
| Total expected lines | 24 |
| Matching lines | 5 (20.8%) |
| Mismatched lines | 19 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**3 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `g711_event_alaw` | 0 | 17.7s |  |
| 2 | `g711_event_mulaw` | 0 | 15.7s |  |
| 3 | `stream_incomplete_loop` | 0 | 23.0s |  |

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
| 1 | `g711` | 25.0% | 2/8 | 8 | 6 |  |
| 2 | `aac` | 12.5% | 3/24 | 24 | 18 |  |
