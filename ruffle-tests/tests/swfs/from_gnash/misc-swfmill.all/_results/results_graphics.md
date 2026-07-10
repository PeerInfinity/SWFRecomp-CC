# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-10 22:53 UTC

**Git SHA**: `8a8ff17c73`

**Run Duration**: 6m 25s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **18** (94.7%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (100.0%) |
| Failing | 0 |
| Total expected lines | 94 |
| Matching lines | 92 (97.9%) |
| Mismatched lines | 2 |

## Passing Tests

**18 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 18.4s |  |
| 2 | `background` | 0 | 20.6s |  |
| 3 | `dict_callframe` | 3 | 20.2s |  |
| 4 | `dict_cross` | 3 | 19.4s |  |
| 5 | `dict_event` | 5 | 20.5s |  |
| 6 | `dict_override` | 2 | 19.9s |  |
| 7 | `func_dict` | 3 | 21.5s |  |
| 8 | `initaction_in_definesprite` | 2 | 20.1s |  |
| 9 | `jump_after_end` | 3 | 20.3s |  |
| 10 | `jump_to_prev_block` | 1 | 20.3s |  |
| 11 | `missing_bitmap` | 0 | 23.0s |  |
| 12 | `mixed-bytecode-as2` | 1 | 20.3s |  |
| 13 | `registers` | 36 | 20.3s |  |
| 14 | `trace-as2/arguments` | 8 | 16.9s |  |
| 15 | `trace-as2/root_onload` | 4 | 20.7s |  |
| 16 | `trace-as2/shortstack` | 2 | 19.9s |  |
| 17 | `trace-as2/super` | 8 | 20.8s |  |
| 18 | `trace-as2/this` | 8 | 20.4s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 20.4s |  |

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
