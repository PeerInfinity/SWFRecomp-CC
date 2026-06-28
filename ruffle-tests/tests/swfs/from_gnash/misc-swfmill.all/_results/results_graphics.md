# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-28 20:18 UTC

**Git SHA**: `2ed995cc46`

**Run Duration**: 6m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **18** (94.7%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (100.0%) |
| Failing | 0 |
| Total expected lines | 91 |
| Matching lines | 89 (97.8%) |
| Mismatched lines | 2 |

## Passing Tests

**18 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 22.3s |  |
| 2 | `background` | 0 | 23.1s |  |
| 3 | `dict_callframe` | 3 | 20.4s |  |
| 4 | `dict_cross` | 3 | 21.2s |  |
| 5 | `dict_event` | 5 | 20.4s |  |
| 6 | `dict_override` | 2 | 20.9s |  |
| 7 | `func_dict` | 3 | 22.9s |  |
| 8 | `initaction_in_definesprite` | 2 | 21.1s |  |
| 9 | `jump_after_end` | 3 | 20.8s |  |
| 10 | `jump_to_prev_block` | 1 | 20.4s |  |
| 11 | `missing_bitmap` | 0 | 21.2s |  |
| 12 | `mixed-bytecode-as2` | 1 | 21.6s |  |
| 13 | `registers` | 36 | 21.3s |  |
| 14 | `tags_after_last_showframe` | 1 | 21.6s |  |
| 15 | `trace-as2/arguments` | 8 | 21.0s |  |
| 16 | `trace-as2/shortstack` | 2 | 20.8s |  |
| 17 | `trace-as2/super` | 8 | 20.5s |  |
| 18 | `trace-as2/this` | 8 | 20.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 22.6s |  |

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
