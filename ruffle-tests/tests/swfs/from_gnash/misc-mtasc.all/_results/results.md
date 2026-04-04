# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-04 01:50 UTC

**Git SHA**: `7a348be46a`

**Run Duration**: 2m 36s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 8 |
| Passing | **4** (50.0%) |
| Failing | 4 |
| Total expected lines | 205 |
| Matching lines | 140 (68.3%) |
| Mismatched lines | 65 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 19.0s |  |
| 2 | `exception` | 35 | 19.1s |  |
| 3 | `hello` | 8 | 18.5s |  |
| 4 | `implementsOpTest` | 28 | 18.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `TextFieldTest` | 87.5% | 7 | 8 | 1 |  |
| 2 | `inheritance` | 86.4% | 19 | 22 | 3 |  |
| 3 | `super_test1` | 76.5% | 13 | 17 | 4 |  |

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
| 1 | `TextFieldTest` | 87.5% | 7/8 | 8 | 8 |  |
| 2 | `inheritance` | 86.4% | 19/22 | 22 | 22 |  |
| 3 | `super_test1` | 76.5% | 13/17 | 17 | 17 |  |
| 4 | `levels` | 16.2% | 11/68 | 14 | 68 |  |
