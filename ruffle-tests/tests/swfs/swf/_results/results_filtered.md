# Ruffle Test Results (Filtered)

**Date**: 2026-07-29 03:45 UTC

**Git SHA**: `72fdc5e933`

**Run Duration**: 0m 42s

**Filtered**: 0 tests ignored out of 5 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 5 |
| Passing | **4** (80.0%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **5** (100.0%) |
| Failing | 0 |
| Total expected lines | 57 |
| Matching lines | 51 (89.5%) |
| Mismatched lines | 6 |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `convolution_filter_big_matrix` | 2 | 20.1s |  |
| 2 | `swf_length_too_short_no_end` | 19 | 1.4s |  |
| 3 | `swf_length_too_short_no_second_frame` | 18 | 17.5s |  |
| 4 | `swf_length_zero` | 0 | 1.3s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `swf_length_too_long` | 6 | 6 | 1.4s |  |

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
