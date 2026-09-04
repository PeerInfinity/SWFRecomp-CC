# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 04:42 UTC

**Git SHA**: `82f27e5f90`

**Run Duration**: 0m 43s

**Filtered**: 0 tests ignored out of 7 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 7 |
| Passing | **5** (71.4%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **7** (100.0%) |
| Failing | 0 |
| Total expected lines | 94 |
| Matching lines | 78 (83.0%) |
| Mismatched lines | 16 |

## Passing Tests

**5 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `convolution_filter_big_matrix` | 2 | 17.4s |  |
| 2 | `lzma_length_too_short` | 18 | 1.4s |  |
| 3 | `swf_length_too_short_no_end` | 19 | 1.5s |  |
| 4 | `swf_length_too_short_no_second_frame` | 18 | 1.2s |  |
| 5 | `swf_length_zero` | 0 | 1.4s |  |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `lzma_length_too_long` | 68 | 68 | 18.4s |  |
| 2 | `swf_length_too_long` | 6 | 6 | 1.2s |  |

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
