# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-30 00:21 UTC

**Git SHA**: `ff04de9186`

**Run Duration**: 0m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **19** (95.0%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **20** (100.0%) |
| Failing | 0 |
| Total expected lines | 95 |
| Matching lines | 93 (97.9%) |
| Mismatched lines | 2 |

## Passing Tests

**19 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 0.7s |  |
| 2 | `background` | 0 | 1.1s |  |
| 3 | `dict_callframe` | 3 | 0.8s |  |
| 4 | `dict_cross` | 3 | 0.6s |  |
| 5 | `dict_event` | 5 | 0.8s |  |
| 6 | `dict_override` | 2 | 0.8s |  |
| 7 | `func_dict` | 3 | 0.9s |  |
| 8 | `initaction_in_definesprite` | 2 | 0.8s |  |
| 9 | `jump_after_end` | 3 | 0.8s |  |
| 10 | `jump_to_prev_block` | 1 | 0.8s |  |
| 11 | `missing_bitmap` | 0 | 1.4s |  |
| 12 | `mixed-bytecode-as2` | 1 | 0.9s |  |
| 13 | `registers` | 36 | 0.8s |  |
| 14 | `tags_after_last_showframe` | 1 | 0.8s |  |
| 15 | `trace-as2/arguments` | 8 | 0.8s |  |
| 16 | `trace-as2/root_onload` | 4 | 0.8s |  |
| 17 | `trace-as2/shortstack` | 2 | 0.8s |  |
| 18 | `trace-as2/super` | 8 | 0.8s |  |
| 19 | `trace-as2/this` | 8 | 0.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 0.8s |  |

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
