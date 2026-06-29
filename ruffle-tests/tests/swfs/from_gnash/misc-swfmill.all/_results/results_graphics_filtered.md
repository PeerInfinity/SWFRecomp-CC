# Ruffle Test Results (Filtered)

**Date**: 2026-06-29 18:27 UTC

**Git SHA**: `a0db68a54d`

**Run Duration**: 6m 24s

**Filtered**: 0 tests ignored out of 20 available

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
| 1 | `afunc_dict` | 2 | 20.3s |  |
| 2 | `background` | 0 | 24.2s |  |
| 3 | `dict_callframe` | 3 | 22.5s |  |
| 4 | `dict_cross` | 3 | 21.2s |  |
| 5 | `dict_event` | 5 | 20.0s |  |
| 6 | `dict_override` | 2 | 13.9s |  |
| 7 | `func_dict` | 3 | 20.6s |  |
| 8 | `initaction_in_definesprite` | 2 | 21.2s |  |
| 9 | `jump_after_end` | 3 | 19.8s |  |
| 10 | `jump_to_prev_block` | 1 | 20.2s |  |
| 11 | `missing_bitmap` | 0 | 21.6s |  |
| 12 | `mixed-bytecode-as2` | 1 | 21.1s |  |
| 13 | `registers` | 36 | 13.4s |  |
| 14 | `tags_after_last_showframe` | 1 | 20.0s |  |
| 15 | `trace-as2/arguments` | 8 | 22.7s |  |
| 16 | `trace-as2/shortstack` | 2 | 20.2s |  |
| 17 | `trace-as2/super` | 8 | 17.0s |  |
| 18 | `trace-as2/this` | 8 | 21.0s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 21.4s |  |

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
