# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-11 05:59 UTC

**Git SHA**: `cff54dc173`

**Run Duration**: 7m 23s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **16** (69.6%) |
| Failing | 7 |
| Total expected lines | 311 |
| Matching lines | 136 (43.7%) |
| Mismatched lines | 175 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**16 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `callee` | 2 | 19.6s |  |
| 2 | `depth` | 6 | 19.0s |  |
| 3 | `externalinterface` | 4 | 19.8s |  |
| 4 | `label` | 4 | 19.7s |  |
| 5 | `levels` | 9 | 18.6s |  |
| 6 | `loadevent` | 9 | 18.9s |  |
| 7 | `lookup` | 3 | 18.4s |  |
| 8 | `mouse-transparency` | 1 | 19.4s |  |
| 9 | `operations` | 13 | 19.0s |  |
| 10 | `rollover` | 4 | 19.6s |  |
| 11 | `scope` | 14 | 20.1s |  |
| 12 | `setinterval` | 20 | 18.5s |  |
| 13 | `settimeout` | 17 | 18.7s |  |
| 14 | `super` | 11 | 18.9s |  |
| 15 | `text-bind` | 0 | 19.1s |  |
| 16 | `watch` | 2 | 19.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `nativeinheritance` | 83.3% | 5 | 6 | 1 |  |
| 2 | `hitarea` | 50.0% | 2 | 4 | 2 |  |

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
| 1 | `nativeinheritance` | 83.3% | 5/6 | 6 | 6 |  |
| 2 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 3 | `target` | 27.3% | 6/22 | 22 | 18 |  |
| 4 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 5 | `filters` | 2.0% | 3/149 | 85 | 149 |  |
| 6 | `array` | 0.0% | 0/7 | 7 | 7 |  |
| 7 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
