# Ruffle Test Results (Filtered)

**Date**: 2026-04-04 17:24 UTC

**Git SHA**: `57ba121d14`

**Run Duration**: 2m 53s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **4** (44.4%) |
| Failing | 5 |
| Total expected lines | 231 |
| Matching lines | 163 (70.6%) |
| Mismatched lines | 68 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 18.9s |  |
| 2 | `exception` | 35 | 19.1s |  |
| 3 | `hello` | 8 | 19.2s |  |
| 4 | `implementsOpTest` | 28 | 18.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `function_test` | 88.5% | 23 | 26 | 3 |  |
| 2 | `TextFieldTest` | 87.5% | 7 | 8 | 1 |  |
| 3 | `inheritance` | 86.4% | 19 | 22 | 3 |  |
| 4 | `super_test1` | 76.5% | 13 | 17 | 4 |  |

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
| 1 | `function_test` | 88.5% | 23/26 | 26 | 26 |  |
| 2 | `TextFieldTest` | 87.5% | 7/8 | 8 | 8 |  |
| 3 | `inheritance` | 86.4% | 19/22 | 22 | 22 |  |
| 4 | `super_test1` | 76.5% | 13/17 | 17 | 17 |  |
| 5 | `levels` | 16.2% | 11/68 | 14 | 68 |  |
