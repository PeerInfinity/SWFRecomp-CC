# Ruffle Test Results (Filtered)

**Date**: 2026-04-11 19:59 UTC

**Git SHA**: `8b070eb6ec`

**Run Duration**: 7m 26s

**Filtered**: 0 tests ignored out of 23 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **19** (82.6%) |
| Failing | 4 |
| Total expected lines | 311 |
| Matching lines | 145 (46.6%) |
| Mismatched lines | 166 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**19 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 19.5s |  |
| 2 | `callee` | 2 | 18.6s |  |
| 3 | `depth` | 6 | 18.7s |  |
| 4 | `externalinterface` | 4 | 19.5s |  |
| 5 | `label` | 4 | 19.2s |  |
| 6 | `levels` | 9 | 19.4s |  |
| 7 | `loadevent` | 9 | 20.4s |  |
| 8 | `lookup` | 3 | 19.8s |  |
| 9 | `mouse-transparency` | 1 | 19.1s |  |
| 10 | `nativeinheritance` | 6 | 18.8s |  |
| 11 | `nested-button` | 1 | 19.3s |  |
| 12 | `operations` | 13 | 19.3s |  |
| 13 | `rollover` | 4 | 19.6s |  |
| 14 | `scope` | 14 | 18.7s |  |
| 15 | `setinterval` | 20 | 19.3s |  |
| 16 | `settimeout` | 17 | 19.4s |  |
| 17 | `super` | 11 | 19.0s |  |
| 18 | `text-bind` | 0 | 20.0s |  |
| 19 | `watch` | 2 | 18.8s |  |

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

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 2 | `target` | 27.3% | 6/22 | 22 | 18 |  |
| 3 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 4 | `filters` | 2.0% | 3/149 | 85 | 149 |  |
