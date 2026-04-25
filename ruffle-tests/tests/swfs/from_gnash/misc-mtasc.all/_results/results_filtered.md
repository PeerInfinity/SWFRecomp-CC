# Ruffle Test Results (Filtered)

**Date**: 2026-04-25 01:45 UTC

**Git SHA**: `3a9cd203ba`

**Run Duration**: 1m 40s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **7** (77.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (88.9%) |
| Failing | 1 |
| Total expected lines | 231 |
| Matching lines | 205 (88.7%) |
| Mismatched lines | 26 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 15.7s |  |
| 2 | `exception` | 35 | 16.7s |  |
| 3 | `function_test` | 26 | 16.0s |  |
| 4 | `hello` | 8 | 16.6s |  |
| 5 | `implementsOpTest` | 28 | 16.5s |  |
| 6 | `inheritance` | 22 | 0.2s |  |
| 7 | `super_test1` | 17 | 0.3s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `TextFieldTest` | 1 | 1 | 17.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `levels` | 63.2% | 43 | 68 | 25 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `levels` | 63.2% | 43/68 | 68 | 68 |  |
