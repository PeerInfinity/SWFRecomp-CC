# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-09 01:53 UTC

**Git SHA**: `9d4d874294`

**Run Duration**: 2m 58s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **7** (77.8%) |
| Failing | 2 |
| Total expected lines | 231 |
| Matching lines | 173 (74.9%) |
| Mismatched lines | 58 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 20.1s |  |
| 2 | `exception` | 35 | 19.1s |  |
| 3 | `function_test` | 26 | 18.7s |  |
| 4 | `hello` | 8 | 19.4s |  |
| 5 | `implementsOpTest` | 28 | 19.6s |  |
| 6 | `inheritance` | 22 | 19.2s |  |
| 7 | `super_test1` | 17 | 19.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `TextFieldTest` | 87.5% | 7 | 8 | 1 |  |

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
| 1 | `TextFieldTest` | 87.5% | 7/8 | 8 | 8 |  |
| 2 | `levels` | 16.2% | 11/68 | 14 | 68 |  |
