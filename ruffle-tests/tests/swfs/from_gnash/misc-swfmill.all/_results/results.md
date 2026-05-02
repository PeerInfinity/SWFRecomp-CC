# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-02 19:29 UTC

**Git SHA**: `802674fd5c`

**Run Duration**: 5m 5s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **17** (94.4%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **18** (100.0%) |
| Failing | 0 |
| Total expected lines | 51 |
| Matching lines | 49 (96.1%) |
| Mismatched lines | 2 |

## Passing Tests

**17 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 16.5s |  |
| 2 | `background` | 0 | 17.0s |  |
| 3 | `dict_callframe` | 3 | 17.1s |  |
| 4 | `dict_cross` | 3 | 17.7s |  |
| 5 | `dict_event` | 5 | 16.8s |  |
| 6 | `dict_override` | 2 | 17.0s |  |
| 7 | `func_dict` | 3 | 17.3s |  |
| 8 | `initaction_in_definesprite` | 2 | 17.3s |  |
| 9 | `jump_after_end` | 3 | 17.6s |  |
| 10 | `jump_to_prev_block` | 1 | 17.0s |  |
| 11 | `missing_bitmap` | 0 | 13.5s |  |
| 12 | `mixed-bytecode-as2` | 1 | 16.6s |  |
| 13 | `tags_after_last_showframe` | 1 | 17.4s |  |
| 14 | `trace-as2/root_onload` | 4 | 16.9s |  |
| 15 | `trace-as2/shortstack` | 2 | 16.8s |  |
| 16 | `trace-as2/super` | 8 | 17.0s |  |
| 17 | `trace-as2/this` | 8 | 16.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 18.0s |  |

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
