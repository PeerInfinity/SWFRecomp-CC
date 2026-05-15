# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-15 02:10 UTC

**Git SHA**: `eb8206f8aa`

**Run Duration**: 6m 18s

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
| 1 | `afunc_dict` | 2 | 18.6s |  |
| 2 | `background` | 0 | 19.1s |  |
| 3 | `dict_callframe` | 3 | 18.2s |  |
| 4 | `dict_cross` | 3 | 18.6s |  |
| 5 | `dict_event` | 5 | 19.6s |  |
| 6 | `dict_override` | 2 | 18.3s |  |
| 7 | `func_dict` | 3 | 18.6s |  |
| 8 | `initaction_in_definesprite` | 2 | 22.1s |  |
| 9 | `jump_after_end` | 3 | 18.0s |  |
| 10 | `jump_to_prev_block` | 1 | 19.1s |  |
| 11 | `missing_bitmap` | 0 | 18.5s |  |
| 12 | `mixed-bytecode-as2` | 1 | 18.7s |  |
| 13 | `tags_after_last_showframe` | 1 | 18.3s |  |
| 14 | `trace-as2/arguments` | 8 | 19.2s |  |
| 15 | `trace-as2/root_onload` | 4 | 18.8s |  |
| 16 | `trace-as2/shortstack` | 2 | 18.7s |  |
| 17 | `trace-as2/super` | 8 | 18.3s |  |
| 18 | `trace-as2/this` | 8 | 18.5s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 18.1s |  |

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
