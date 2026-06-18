# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 2m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 8 |
| Passing | **6** (75.0%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (100.0%) |
| Failing | 0 |
| Total expected lines | 223 |
| Matching lines | 203 (91.0%) |
| Mismatched lines | 20 |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 13.8s |  |
| 2 | `exception` | 35 | 22.9s |  |
| 3 | `function_test` | 26 | 21.5s |  |
| 4 | `implementsOpTest` | 28 | 21.1s |  |
| 5 | `inheritance` | 22 | 2.7s |  |
| 6 | `super_test1` | 17 | 21.8s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `TextFieldTest` | 1 | 1 | 20.8s |  |
| 2 | `levels` | 19 | 21 | 4.4s |  |

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
