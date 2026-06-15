# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-15 03:41 UTC

**Git SHA**: `3f8c0c1ec7`

**Run Duration**: 3m 4s

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
| 1 | `afunc_dict` | 2 | 1.1s |  |
| 2 | `background` | 0 | 19.5s |  |
| 3 | `dict_callframe` | 3 | 20.1s |  |
| 4 | `dict_cross` | 3 | 19.9s |  |
| 5 | `dict_event` | 5 | 1.1s |  |
| 6 | `dict_override` | 2 | 1.0s |  |
| 7 | `func_dict` | 3 | 1.1s |  |
| 8 | `initaction_in_definesprite` | 2 | 1.2s |  |
| 9 | `jump_after_end` | 3 | 1.1s |  |
| 10 | `jump_to_prev_block` | 1 | 0.2s |  |
| 11 | `missing_bitmap` | 0 | 20.5s |  |
| 12 | `mixed-bytecode-as2` | 1 | 12.1s |  |
| 13 | `registers` | 36 | 20.2s |  |
| 14 | `tags_after_last_showframe` | 1 | 20.3s |  |
| 15 | `trace-as2/arguments` | 8 | 19.4s |  |
| 16 | `trace-as2/root_onload` | 4 | 1.2s |  |
| 17 | `trace-as2/shortstack` | 2 | 1.2s |  |
| 18 | `trace-as2/super` | 8 | 1.1s |  |
| 19 | `trace-as2/this` | 8 | 1.1s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 19.4s |  |

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
