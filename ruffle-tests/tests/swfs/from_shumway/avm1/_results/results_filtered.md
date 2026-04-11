# Ruffle Test Results (Filtered)

**Date**: 2026-04-11 20:21 UTC

**Git SHA**: `7b73007a45`

**Run Duration**: 7m 25s

**Filtered**: 1 tests ignored out of 23 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 22 |
| Passing | **19** (86.4%) |
| Failing | 3 |
| Total expected lines | 307 |
| Matching lines | 153 (49.8%) |
| Mismatched lines | 154 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**19 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 19.5s |  |
| 2 | `callee` | 2 | 18.9s |  |
| 3 | `depth` | 6 | 19.1s |  |
| 4 | `externalinterface` | 4 | 18.7s |  |
| 5 | `label` | 4 | 19.6s |  |
| 6 | `loadevent` | 9 | 19.4s |  |
| 7 | `lookup` | 3 | 19.7s |  |
| 8 | `mouse-transparency` | 1 | 19.2s |  |
| 9 | `nativeinheritance` | 6 | 19.3s |  |
| 10 | `nested-button` | 1 | 19.3s |  |
| 11 | `operations` | 13 | 19.6s |  |
| 12 | `rollover` | 4 | 18.8s |  |
| 13 | `scope` | 14 | 18.9s |  |
| 14 | `setinterval` | 20 | 19.5s |  |
| 15 | `settimeout` | 17 | 19.4s |  |
| 16 | `super` | 11 | 19.9s |  |
| 17 | `target` | 18 | 18.9s |  |
| 18 | `text-bind` | 0 | 19.2s |  |
| 19 | `watch` | 2 | 20.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `levels` | 77.8% | 7 | 9 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `levels` | 77.8% | 7/9 | 9 | 9 |  |
| 2 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 3 | `filters` | 2.0% | 3/149 | 85 | 149 |  |
