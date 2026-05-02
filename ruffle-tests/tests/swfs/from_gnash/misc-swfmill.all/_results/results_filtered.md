# Ruffle Test Results (Filtered)

**Date**: 2026-05-02 03:07 UTC

**Git SHA**: `6364db8fd5`

**Run Duration**: 0m 4s

**Filtered**: 0 tests ignored out of 18 available

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
| 1 | `afunc_dict` | 2 | 0.2s |  |
| 2 | `background` | 0 | 0.2s |  |
| 3 | `dict_callframe` | 3 | 0.2s |  |
| 4 | `dict_cross` | 3 | 0.2s |  |
| 5 | `dict_event` | 5 | 0.2s |  |
| 6 | `dict_override` | 2 | 0.2s |  |
| 7 | `func_dict` | 3 | 0.2s |  |
| 8 | `initaction_in_definesprite` | 2 | 0.2s |  |
| 9 | `jump_after_end` | 3 | 0.1s |  |
| 10 | `jump_to_prev_block` | 1 | 0.2s |  |
| 11 | `missing_bitmap` | 0 | 0.2s |  |
| 12 | `mixed-bytecode-as2` | 1 | 0.2s |  |
| 13 | `tags_after_last_showframe` | 1 | 0.2s |  |
| 14 | `trace-as2/root_onload` | 4 | 0.1s |  |
| 15 | `trace-as2/shortstack` | 2 | 0.1s |  |
| 16 | `trace-as2/super` | 8 | 0.2s |  |
| 17 | `trace-as2/this` | 8 | 0.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 0.2s |  |

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
