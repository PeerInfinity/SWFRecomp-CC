# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 5m 1s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 15 |
| Passing | **14** (93.3%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (100.0%) |
| Failing | 0 |
| Total expected lines | 69 |
| Matching lines | 67 (97.1%) |
| Mismatched lines | 2 |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 20.6s |  |
| 2 | `background` | 0 | 16.7s |  |
| 3 | `dict_callframe` | 3 | 22.8s |  |
| 4 | `dict_cross` | 3 | 20.2s |  |
| 5 | `func_dict` | 3 | 20.6s |  |
| 6 | `initaction_in_definesprite` | 2 | 20.4s |  |
| 7 | `jump_to_prev_block` | 1 | 22.2s |  |
| 8 | `missing_bitmap` | 0 | 21.8s |  |
| 9 | `mixed-bytecode-as2` | 1 | 16.6s |  |
| 10 | `registers` | 36 | 20.3s |  |
| 11 | `tags_after_last_showframe` | 1 | 13.8s |  |
| 12 | `trace-as2/root_onload` | 4 | 20.8s |  |
| 13 | `trace-as2/shortstack` | 2 | 21.5s |  |
| 14 | `trace-as2/super` | 8 | 20.4s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 20.8s |  |

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
