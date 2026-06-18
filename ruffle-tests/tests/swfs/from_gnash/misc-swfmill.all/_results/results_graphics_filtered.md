# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 5m 23s

**Filtered**: 0 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **15** (93.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **16** (100.0%) |
| Failing | 0 |
| Total expected lines | 42 |
| Matching lines | 40 (95.2%) |
| Mismatched lines | 2 |

## Passing Tests

**15 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 20.2s |  |
| 2 | `background` | 0 | 13.7s |  |
| 3 | `dict_callframe` | 3 | 20.8s |  |
| 4 | `dict_cross` | 3 | 20.6s |  |
| 5 | `dict_override` | 2 | 20.1s |  |
| 6 | `func_dict` | 3 | 20.6s |  |
| 7 | `initaction_in_definesprite` | 2 | 20.4s |  |
| 8 | `jump_after_end` | 3 | 22.4s |  |
| 9 | `jump_to_prev_block` | 1 | 15.8s |  |
| 10 | `missing_bitmap` | 0 | 21.8s |  |
| 11 | `mixed-bytecode-as2` | 1 | 21.2s |  |
| 12 | `tags_after_last_showframe` | 1 | 20.1s |  |
| 13 | `trace-as2/arguments` | 8 | 20.6s |  |
| 14 | `trace-as2/shortstack` | 2 | 20.6s |  |
| 15 | `trace-as2/super` | 8 | 21.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 22.3s |  |

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
