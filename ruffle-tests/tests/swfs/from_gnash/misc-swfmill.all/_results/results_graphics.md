# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 06:45 UTC

**Git SHA**: `2d40d37996`

**Run Duration**: 6m 20s

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
| 1 | `afunc_dict` | 2 | 19.8s |  |
| 2 | `background` | 0 | 19.4s |  |
| 3 | `dict_callframe` | 3 | 19.8s |  |
| 4 | `dict_cross` | 3 | 20.8s |  |
| 5 | `dict_event` | 5 | 19.7s |  |
| 6 | `dict_override` | 2 | 25.3s |  |
| 7 | `func_dict` | 3 | 19.1s |  |
| 8 | `initaction_in_definesprite` | 2 | 25.8s |  |
| 9 | `jump_after_end` | 3 | 19.4s |  |
| 10 | `missing_bitmap` | 0 | 19.3s |  |
| 11 | `mixed-bytecode-as2` | 1 | 1.7s |  |
| 12 | `registers` | 36 | 19.7s |  |
| 13 | `tags_after_last_showframe` | 1 | 19.2s |  |
| 14 | `trace-as2/arguments` | 8 | 20.7s |  |
| 15 | `trace-as2/root_onload` | 4 | 25.0s |  |
| 16 | `trace-as2/shortstack` | 2 | 19.4s |  |
| 17 | `trace-as2/super` | 8 | 25.4s |  |
| 18 | `trace-as2/this` | 8 | 19.9s |  |

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
