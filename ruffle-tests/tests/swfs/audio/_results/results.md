# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 08:08 UTC

**Git SHA**: `3dfab12779`

**Run Duration**: 1m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 5 |
| Passing | **4** (80.0%) |
| Failing | 1 |
| Total expected lines | 24 |
| Matching lines | 18 (75.0%) |
| Mismatched lines | 6 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `g711` | 6 | 6.7s |  |
| 2 | `g711_event_alaw` | 0 | 19.4s |  |
| 3 | `g711_event_mulaw` | 0 | 18.4s |  |
| 4 | `stream_incomplete_loop` | 0 | 20.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `aac` | 66.7% | 12 | 18 | 6 |  |

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
| 1 | `aac` | 66.7% | 12/18 | 18 | 18 |  |
