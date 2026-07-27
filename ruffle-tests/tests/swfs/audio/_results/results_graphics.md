# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 04:25 UTC

**Git SHA**: `a9900a4786`

**Run Duration**: 1m 7s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 5 |
| Passing | **3** (60.0%) |
| Failing | 2 |
| Total expected lines | 24 |
| Matching lines | 4 (16.7%) |
| Mismatched lines | 20 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**3 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `g711_event_alaw` | 0 | 14.6s |  |
| 2 | `g711_event_mulaw` | 0 | 20.6s |  |
| 3 | `stream_incomplete_loop` | 0 | 20.8s |  |

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
| 1 | `g711` | 14.3% | 2/14 | 14 | 6 |  |
| 2 | `aac` | 4.8% | 2/42 | 42 | 18 |  |
