# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-19 01:34 UTC

**Git SHA**: `ea87da0d59`

**Run Duration**: 6m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **11** (47.8%) |
| Failing | 12 |
| Total expected lines | 311 |
| Matching lines | 107 (34.4%) |
| Mismatched lines | 204 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 91.7% |
| Runtime Error | 1 | 8.3% |

## Passing Tests

**11 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `callee` | 2 | 16.2s |  |
| 2 | `depth` | 6 | 15.5s |  |
| 3 | `externalinterface` | 4 | 15.6s |  |
| 4 | `label` | 4 | 16.6s |  |
| 5 | `levels` | 9 | 15.5s |  |
| 6 | `lookup` | 3 | 16.3s |  |
| 7 | `mouse-transparency` | 1 | 15.6s |  |
| 8 | `operations` | 13 | 15.5s |  |
| 9 | `rollover` | 4 | 17.3s |  |
| 10 | `super` | 11 | 15.7s |  |
| 11 | `text-bind` | 0 | 15.4s |  |

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
| 1 | `watch` | exit code -6 | 17.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**11 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `scope` | 92.9% | 13/14 | 14 | 14 |  |
| 2 | `nativeinheritance` | 83.3% | 5/6 | 6 | 6 |  |
| 3 | `settimeout` | 64.7% | 11/17 | 12 | 17 |  |
| 4 | `setinterval` | 55.0% | 11/20 | 12 | 20 |  |
| 5 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 6 | `target` | 22.7% | 5/22 | 22 | 18 |  |
| 7 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 8 | `loadevent` | 11.1% | 1/9 | 7 | 9 |  |
| 9 | `array` | 0.0% | 0/7 | 7 | 7 |  |
| 10 | `filters` | 0.0% | 0/149 | 85 | 149 |  |
| 11 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
