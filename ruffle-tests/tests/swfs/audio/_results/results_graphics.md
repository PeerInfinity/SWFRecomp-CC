# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-29 04:05 UTC

**Git SHA**: `72fdc5e933`

**Run Duration**: 1m 20s

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
| 1 | `g711_event_alaw` | 0 | 21.0s |  |
| 2 | `g711_event_mulaw` | 0 | 20.9s |  |
| 3 | `stream_incomplete_loop` | 0 | 22.2s |  |

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
| 1 | `g711` | 33.3% | 2/6 | 4 | 6 |  |
| 2 | `aac` | 16.7% | 3/18 | 12 | 18 |  |
