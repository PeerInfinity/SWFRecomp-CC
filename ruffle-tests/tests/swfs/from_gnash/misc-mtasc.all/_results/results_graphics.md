# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 1m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 6 |
| Passing | **4** (66.7%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **6** (100.0%) |
| Failing | 0 |
| Total expected lines | 178 |
| Matching lines | 158 (88.8%) |
| Mismatched lines | 20 |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `enum` | 19 | 16.7s |  |
| 2 | `exception` | 35 | 23.5s |  |
| 3 | `function_test` | 26 | 21.0s |  |
| 4 | `inheritance` | 22 | 2.7s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `TextFieldTest` | 1 | 1 | 21.7s |  |
| 2 | `levels` | 19 | 21 | 4.5s |  |

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
