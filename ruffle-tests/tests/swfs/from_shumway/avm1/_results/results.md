# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-12 20:39 UTC

**Git SHA**: `3e6993b0e7`

**Run Duration**: 7m 29s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **21** (91.3%) |
| Failing | 2 |
| Total expected lines | 311 |
| Matching lines | 303 (97.4%) |
| Mismatched lines | 8 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**21 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 19.0s |  |
| 2 | `callee` | 2 | 19.1s |  |
| 3 | `depth` | 6 | 20.4s |  |
| 4 | `externalinterface` | 4 | 18.8s |  |
| 5 | `filters` | 149 | 19.6s |  |
| 6 | `label` | 4 | 19.1s |  |
| 7 | `levels` | 9 | 20.0s |  |
| 8 | `loadevent` | 9 | 20.3s |  |
| 9 | `lookup` | 3 | 19.0s |  |
| 10 | `mouse-transparency` | 1 | 19.4s |  |
| 11 | `nativeinheritance` | 6 | 20.4s |  |
| 12 | `nested-button` | 1 | 19.1s |  |
| 13 | `operations` | 13 | 19.0s |  |
| 14 | `rollover` | 4 | 19.9s |  |
| 15 | `scope` | 14 | 18.9s |  |
| 16 | `setinterval` | 20 | 18.7s |  |
| 17 | `settimeout` | 17 | 19.6s |  |
| 18 | `super` | 11 | 19.0s |  |
| 19 | `target` | 18 | 20.0s |  |
| 20 | `text-bind` | 0 | 19.8s |  |
| 21 | `watch` | 2 | 19.6s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 2 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
