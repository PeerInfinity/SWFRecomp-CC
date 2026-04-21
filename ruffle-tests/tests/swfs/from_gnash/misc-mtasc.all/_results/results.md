# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-21 15:42 UTC

**Git SHA**: `23e1174436`

**Run Duration**: 1m 54s

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
| 1 | `enum` | 19 | 17.7s |  |
| 2 | `exception` | 35 | 17.3s |  |
| 3 | `function_test` | 26 | 19.7s |  |
| 4 | `hello` | 8 | 17.3s |  |
| 5 | `implementsOpTest` | 28 | 18.1s |  |
| 6 | `inheritance` | 22 | 1.5s |  |
| 7 | `super_test1` | 17 | 1.6s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `TextFieldTest` | 1 | 1 | 16.9s |  |

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
