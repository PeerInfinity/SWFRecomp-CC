# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-06 23:18 UTC

**Git SHA**: `0300e5b395`

**Run Duration**: 2m 57s

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
| 1 | `enum` | 19 | 19.2s |  |
| 2 | `exception` | 35 | 19.7s |  |
| 3 | `function_test` | 26 | 19.3s |  |
| 4 | `hello` | 8 | 19.0s |  |
| 5 | `implementsOpTest` | 28 | 19.5s |  |
| 6 | `inheritance` | 22 | 20.0s |  |
| 7 | `super_test1` | 17 | 19.0s |  |

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
