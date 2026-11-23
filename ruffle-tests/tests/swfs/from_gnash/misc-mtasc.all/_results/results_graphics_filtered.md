# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 23:56 UTC

**Git SHA**: `005bea42a2`

**Run Duration**: 1m 54s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 8 |
| Passing | **7** (87.5%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (100.0%) |
| Failing | 0 |
| Total expected lines | 163 |
| Matching lines | 162 (99.4%) |
| Mismatched lines | 1 |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 2.1s |  |
| 2 | `exception` | 35 | 25.4s |  |
| 3 | `function_test` | 26 | 19.0s |  |
| 4 | `hello` | 8 | 1.9s |  |
| 5 | `implementsOpTest` | 28 | 24.2s |  |
| 6 | `inheritance` | 22 | 19.1s |  |
| 7 | `super_test1` | 17 | 3.1s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `TextFieldTest` | 1 | 1 | 18.7s |  |

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

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
