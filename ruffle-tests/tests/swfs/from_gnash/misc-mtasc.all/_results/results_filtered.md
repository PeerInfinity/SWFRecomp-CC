# Ruffle Test Results (Filtered)

**Date**: 2026-04-05 20:14 UTC

**Git SHA**: `bb4ebc9a2d`

**Run Duration**: 2m 55s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **6** (66.7%) |
| Failing | 3 |
| Total expected lines | 231 |
| Matching lines | 170 (73.6%) |
| Mismatched lines | 61 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 18.9s |  |
| 2 | `exception` | 35 | 19.2s |  |
| 3 | `function_test` | 26 | 18.4s |  |
| 4 | `hello` | 8 | 18.6s |  |
| 5 | `implementsOpTest` | 28 | 19.6s |  |
| 6 | `super_test1` | 17 | 20.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `TextFieldTest` | 87.5% | 7 | 8 | 1 |  |
| 2 | `inheritance` | 86.4% | 19 | 22 | 3 |  |

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
| 1 | `TextFieldTest` | 87.5% | 7/8 | 8 | 8 |  |
| 2 | `inheritance` | 86.4% | 19/22 | 22 | 22 |  |
| 3 | `levels` | 16.2% | 11/68 | 14 | 68 |  |
