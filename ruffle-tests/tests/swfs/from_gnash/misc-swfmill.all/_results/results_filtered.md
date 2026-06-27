# Ruffle Test Results (Filtered)

**Date**: 2026-06-27 22:59 UTC

**Git SHA**: `b7f1a17597`

**Run Duration**: 5m 9s

**Filtered**: 0 tests ignored out of 20 available

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
| 1 | `afunc_dict` | 2 | 0.9s |  |
| 2 | `background` | 0 | 19.9s |  |
| 3 | `dict_callframe` | 3 | 19.6s |  |
| 4 | `dict_cross` | 3 | 19.5s |  |
| 5 | `dict_event` | 5 | 19.7s |  |
| 6 | `dict_override` | 2 | 22.0s |  |
| 7 | `func_dict` | 3 | 1.0s |  |
| 8 | `initaction_in_definesprite` | 2 | 20.0s |  |
| 9 | `jump_after_end` | 3 | 1.1s |  |
| 10 | `jump_to_prev_block` | 1 | 19.4s |  |
| 11 | `missing_bitmap` | 0 | 19.7s |  |
| 12 | `mixed-bytecode-as2` | 1 | 20.6s |  |
| 13 | `registers` | 36 | 20.1s |  |
| 14 | `tags_after_last_showframe` | 1 | 20.8s |  |
| 15 | `trace-as2/arguments` | 8 | 20.4s |  |
| 16 | `trace-as2/root_onload` | 4 | 19.7s |  |
| 17 | `trace-as2/shortstack` | 2 | 1.1s |  |
| 18 | `trace-as2/super` | 8 | 1.1s |  |
| 19 | `trace-as2/this` | 8 | 20.3s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 20.9s |  |

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
