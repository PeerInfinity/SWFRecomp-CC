# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-12 20:05 UTC

**Git SHA**: `7cd98a820d`

**Run Duration**: 7m 27s

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
| 1 | `array` | 7 | 19.8s |  |
| 2 | `callee` | 2 | 20.0s |  |
| 3 | `depth` | 6 | 18.8s |  |
| 4 | `externalinterface` | 4 | 19.2s |  |
| 5 | `filters` | 149 | 19.7s |  |
| 6 | `label` | 4 | 19.5s |  |
| 7 | `levels` | 9 | 19.2s |  |
| 8 | `loadevent` | 9 | 19.1s |  |
| 9 | `lookup` | 3 | 18.9s |  |
| 10 | `mouse-transparency` | 1 | 19.3s |  |
| 11 | `nativeinheritance` | 6 | 18.9s |  |
| 12 | `nested-button` | 1 | 19.1s |  |
| 13 | `operations` | 13 | 18.9s |  |
| 14 | `rollover` | 4 | 19.7s |  |
| 15 | `scope` | 14 | 19.1s |  |
| 16 | `setinterval` | 20 | 18.9s |  |
| 17 | `settimeout` | 17 | 18.7s |  |
| 18 | `super` | 11 | 19.7s |  |
| 19 | `target` | 18 | 19.2s |  |
| 20 | `text-bind` | 0 | 20.8s |  |
| 21 | `watch` | 2 | 18.9s |  |

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
