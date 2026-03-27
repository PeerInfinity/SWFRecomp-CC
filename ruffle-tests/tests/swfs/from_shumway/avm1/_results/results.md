# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-27 20:50 UTC

**Git SHA**: `79d4f2cb53`

**Run Duration**: 6m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **12** (52.2%) |
| Failing | 11 |
| Total expected lines | 311 |
| Matching lines | 115 (37.0%) |
| Mismatched lines | 196 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 90.9% |
| Runtime Error | 1 | 9.1% |

## Passing Tests

**12 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `callee` | 2 | 15.7s |  |
| 2 | `depth` | 6 | 16.1s |  |
| 3 | `externalinterface` | 4 | 16.0s |  |
| 4 | `label` | 4 | 16.1s |  |
| 5 | `levels` | 9 | 15.6s |  |
| 6 | `loadevent` | 9 | 16.3s |  |
| 7 | `lookup` | 3 | 15.6s |  |
| 8 | `mouse-transparency` | 1 | 16.0s |  |
| 9 | `operations` | 13 | 16.4s |  |
| 10 | `rollover` | 4 | 16.8s |  |
| 11 | `super` | 11 | 15.7s |  |
| 12 | `text-bind` | 0 | 15.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `scope` | 92.9% | 13 | 14 | 1 |  |
| 2 | `nativeinheritance` | 83.3% | 5 | 6 | 1 |  |
| 3 | `settimeout` | 64.7% | 11 | 17 | 6 |  |
| 4 | `setinterval` | 55.0% | 11 | 20 | 9 |  |
| 5 | `hitarea` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `watch` | exit code -6 | 17.9s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `scope` | 92.9% | 13/14 | 14 | 14 |  |
| 2 | `nativeinheritance` | 83.3% | 5/6 | 6 | 6 |  |
| 3 | `settimeout` | 64.7% | 11/17 | 12 | 17 |  |
| 4 | `setinterval` | 55.0% | 11/20 | 12 | 20 |  |
| 5 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 6 | `target` | 22.7% | 5/22 | 22 | 18 |  |
| 7 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 8 | `array` | 0.0% | 0/7 | 7 | 7 |  |
| 9 | `filters` | 0.0% | 0/149 | 85 | 149 |  |
| 10 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
