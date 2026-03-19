# Ruffle Test Results (Filtered)

**Date**: 2026-03-19 20:52 UTC

**Git SHA**: `f246282a73`

**Run Duration**: 7m 52s

**Filtered**: 0 tests ignored out of 23 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 23 |
| Passing | **11** (47.8%) |
| Failing | 12 |
| Total expected lines | 150 |
| Matching lines | 104 (69.3%) |
| Mismatched lines | 46 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 66.7% |
| Compile Fail | 3 | 25.0% |
| Runtime Error | 1 | 8.3% |

## Passing Tests

**11 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `callee` | 2 | 15.5s |  |
| 2 | `externalinterface` | 4 | 16.7s |  |
| 3 | `label` | 4 | 15.5s |  |
| 4 | `levels` | 9 | 16.5s |  |
| 5 | `loadevent` | 9 | 15.5s |  |
| 6 | `lookup` | 3 | 15.9s |  |
| 7 | `mouse-transparency` | 1 | 15.3s |  |
| 8 | `operations` | 13 | 15.5s |  |
| 9 | `rollover` | 4 | 15.8s |  |
| 10 | `super` | 11 | 15.2s |  |
| 11 | `text-bind` | 0 | 16.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `scope` | 92.9% | 13 | 14 | 1 |  |
| 2 | `settimeout` | 64.7% | 11 | 17 | 6 |  |
| 3 | `setinterval` | 55.0% | 11 | 20 | 9 |  |
| 4 | `hitarea` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `watch` | exit code -6 | 17.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `scope` | 92.9% | 13/14 | 14 | 14 |  |
| 2 | `settimeout` | 64.7% | 11/17 | 12 | 17 |  |
| 3 | `setinterval` | 55.0% | 11/20 | 12 | 20 |  |
| 4 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
| 5 | `target` | 22.7% | 5/22 | 22 | 18 |  |
| 6 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 7 | `array` | 0.0% | 0/7 | 7 | 7 |  |
| 8 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
