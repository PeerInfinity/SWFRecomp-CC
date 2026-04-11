# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-11 18:55 UTC

**Git SHA**: `8d0881a2c6`

**Run Duration**: 7m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **18** (78.3%) |
| Failing | 5 |
| Total expected lines | 311 |
| Matching lines | 138 (44.4%) |
| Mismatched lines | 173 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**18 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `callee` | 2 | 19.1s |  |
| 2 | `depth` | 6 | 18.8s |  |
| 3 | `externalinterface` | 4 | 19.2s |  |
| 4 | `label` | 4 | 18.9s |  |
| 5 | `levels` | 9 | 18.9s |  |
| 6 | `loadevent` | 9 | 19.1s |  |
| 7 | `lookup` | 3 | 18.8s |  |
| 8 | `mouse-transparency` | 1 | 19.9s |  |
| 9 | `nativeinheritance` | 6 | 19.2s |  |
| 10 | `nested-button` | 1 | 19.7s |  |
| 11 | `operations` | 13 | 18.8s |  |
| 12 | `rollover` | 4 | 19.0s |  |
| 13 | `scope` | 14 | 19.2s |  |
| 14 | `setinterval` | 20 | 19.3s |  |
| 15 | `settimeout` | 17 | 18.9s |  |
| 16 | `super` | 11 | 18.5s |  |
| 17 | `text-bind` | 0 | 20.6s |  |
| 18 | `watch` | 2 | 19.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `hitarea` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 2 | `target` | 27.3% | 6/22 | 22 | 18 |  |
| 3 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 4 | `filters` | 2.0% | 3/149 | 85 | 149 |  |
| 5 | `array` | 0.0% | 0/7 | 7 | 7 |  |
