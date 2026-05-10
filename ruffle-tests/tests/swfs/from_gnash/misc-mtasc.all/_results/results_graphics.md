# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-10 23:40 UTC

**Git SHA**: `e527f41066`

**Run Duration**: 2m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **7** (77.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (88.9%) |
| Failing | 1 |
| Total expected lines | 231 |
| Matching lines | 165 (71.4%) |
| Mismatched lines | 66 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 18.9s |  |
| 2 | `exception` | 35 | 17.8s |  |
| 3 | `function_test` | 26 | 17.4s |  |
| 4 | `hello` | 8 | 18.0s |  |
| 5 | `implementsOpTest` | 28 | 17.9s |  |
| 6 | `inheritance` | 22 | 14.2s |  |
| 7 | `super_test1` | 17 | 0.9s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `TextFieldTest` | 1 | 1 | 18.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

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
| 1 | `levels` | 3.3% | 3/90 | 90 | 68 |  |
