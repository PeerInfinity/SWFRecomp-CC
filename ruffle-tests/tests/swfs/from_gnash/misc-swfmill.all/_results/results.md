# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-11 02:53 UTC

**Git SHA**: `83bef14d7e`

**Run Duration**: 6m 23s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **18** (90.0%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (95.0%) |
| Failing | 1 |
| Total expected lines | 95 |
| Matching lines | 92 (96.8%) |
| Mismatched lines | 3 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Runtime Error | 1 | 100.0% |

## Passing Tests

**18 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 19.2s |  |
| 2 | `background` | 0 | 19.2s |  |
| 3 | `dict_callframe` | 3 | 22.0s |  |
| 4 | `dict_cross` | 3 | 19.3s |  |
| 5 | `dict_event` | 5 | 18.8s |  |
| 6 | `dict_override` | 2 | 19.0s |  |
| 7 | `func_dict` | 3 | 16.0s |  |
| 8 | `initaction_in_definesprite` | 2 | 19.2s |  |
| 9 | `jump_after_end` | 3 | 19.2s |  |
| 10 | `jump_to_prev_block` | 1 | 19.3s |  |
| 11 | `missing_bitmap` | 0 | 20.0s |  |
| 12 | `registers` | 36 | 20.2s |  |
| 13 | `tags_after_last_showframe` | 1 | 19.4s |  |
| 14 | `trace-as2/arguments` | 8 | 19.7s |  |
| 15 | `trace-as2/root_onload` | 4 | 19.2s |  |
| 16 | `trace-as2/shortstack` | 2 | 20.3s |  |
| 17 | `trace-as2/super` | 8 | 15.4s |  |
| 18 | `trace-as2/this` | 8 | 17.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 19.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `mixed-bytecode-as2` | exit code 1 | 19.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
