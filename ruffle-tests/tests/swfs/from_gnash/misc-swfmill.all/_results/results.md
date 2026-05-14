# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-14 00:42 UTC

**Git SHA**: `b20ee46207`

**Run Duration**: 5m 35s

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
| 1 | `afunc_dict` | 2 | 17.7s |  |
| 2 | `background` | 0 | 18.0s |  |
| 3 | `dict_callframe` | 3 | 19.4s |  |
| 4 | `dict_cross` | 3 | 19.2s |  |
| 5 | `dict_event` | 5 | 18.4s |  |
| 6 | `dict_override` | 2 | 18.7s |  |
| 7 | `func_dict` | 3 | 18.2s |  |
| 8 | `initaction_in_definesprite` | 2 | 18.5s |  |
| 9 | `jump_after_end` | 3 | 18.3s |  |
| 10 | `jump_to_prev_block` | 1 | 18.9s |  |
| 11 | `missing_bitmap` | 0 | 18.5s |  |
| 12 | `mixed-bytecode-as2` | 1 | 18.0s |  |
| 13 | `tags_after_last_showframe` | 1 | 19.0s |  |
| 14 | `trace-as2/root_onload` | 4 | 18.1s |  |
| 15 | `trace-as2/shortstack` | 2 | 19.3s |  |
| 16 | `trace-as2/super` | 8 | 18.2s |  |
| 17 | `trace-as2/this` | 8 | 19.4s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 18.1s |  |

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
