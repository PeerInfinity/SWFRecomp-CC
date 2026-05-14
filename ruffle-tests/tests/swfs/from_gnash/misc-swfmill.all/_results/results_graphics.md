# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-14 21:43 UTC

**Git SHA**: `17a60dbb68`

**Run Duration**: 0m 19s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **18** (90.0%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (95.0%) |
| Failing | 1 |
| Total expected lines | 95 |
| Matching lines | 87 (91.6%) |
| Mismatched lines | 8 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**18 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 0.9s |  |
| 2 | `background` | 0 | 2.4s |  |
| 3 | `dict_callframe` | 3 | 0.7s |  |
| 4 | `dict_cross` | 3 | 0.8s |  |
| 5 | `dict_event` | 5 | 0.7s |  |
| 6 | `dict_override` | 2 | 0.8s |  |
| 7 | `func_dict` | 3 | 0.7s |  |
| 8 | `initaction_in_definesprite` | 2 | 0.8s |  |
| 9 | `jump_after_end` | 3 | 0.7s |  |
| 10 | `jump_to_prev_block` | 1 | 0.8s |  |
| 11 | `missing_bitmap` | 0 | 1.7s |  |
| 12 | `mixed-bytecode-as2` | 1 | 0.6s |  |
| 13 | `tags_after_last_showframe` | 1 | 0.8s |  |
| 14 | `trace-as2/arguments` | 8 | 0.9s |  |
| 15 | `trace-as2/root_onload` | 4 | 0.8s |  |
| 16 | `trace-as2/shortstack` | 2 | 0.8s |  |
| 17 | `trace-as2/super` | 8 | 0.8s |  |
| 18 | `trace-as2/this` | 8 | 0.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 0.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `registers` | 83.3% | 30 | 36 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `registers` | 83.3% | 30/36 | 36 | 36 |  |
