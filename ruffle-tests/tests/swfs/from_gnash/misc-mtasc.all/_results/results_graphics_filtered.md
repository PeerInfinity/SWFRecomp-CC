# Ruffle Test Results (Filtered)

**Date**: 2026-06-01 22:27 UTC

**Git SHA**: `6e7cf24ea5`

**Run Duration**: 2m 30s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **7** (77.8%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **9** (100.0%) |
| Failing | 0 |
| Total expected lines | 231 |
| Matching lines | 211 (91.3%) |
| Mismatched lines | 20 |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 19.4s |  |
| 2 | `exception` | 35 | 20.9s |  |
| 3 | `function_test` | 26 | 20.2s |  |
| 4 | `hello` | 8 | 20.3s |  |
| 5 | `implementsOpTest` | 28 | 20.6s |  |
| 6 | `inheritance` | 22 | 20.7s |  |
| 7 | `super_test1` | 17 | 2.1s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `TextFieldTest` | 1 | 1 | 21.6s |  |
| 2 | `levels` | 19 | 21 | 3.9s |  |

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
