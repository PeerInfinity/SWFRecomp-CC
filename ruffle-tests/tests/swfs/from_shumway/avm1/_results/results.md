# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-07 17:42 UTC

**Git SHA**: `fa50429eba`

**Run Duration**: 7m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **12** (52.2%) |
| Failing | 11 |
| Total expected lines | 311 |
| Matching lines | 118 (37.9%) |
| Mismatched lines | 193 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 90.9% |
| Runtime Error | 1 | 9.1% |

## Passing Tests

**12 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `callee` | 2 | 18.8s |  |
| 2 | `depth` | 6 | 19.0s |  |
| 3 | `externalinterface` | 4 | 18.2s |  |
| 4 | `label` | 4 | 20.2s |  |
| 5 | `levels` | 9 | 19.1s |  |
| 6 | `loadevent` | 9 | 18.4s |  |
| 7 | `lookup` | 3 | 18.4s |  |
| 8 | `mouse-transparency` | 1 | 18.4s |  |
| 9 | `operations` | 13 | 18.4s |  |
| 10 | `rollover` | 4 | 18.9s |  |
| 11 | `super` | 11 | 18.9s |  |
| 12 | `text-bind` | 0 | 18.5s |  |

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
| 1 | `watch` | exit code -6 | 20.5s |  |

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
| 8 | `filters` | 2.0% | 3/149 | 85 | 149 |  |
| 9 | `array` | 0.0% | 0/7 | 7 | 7 |  |
| 10 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
