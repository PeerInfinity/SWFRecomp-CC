# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-17 17:56 UTC

**Git SHA**: `f7ed2ce37c`

**Run Duration**: 4m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **14** (77.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (83.3%) |
| Failing | 3 |
| Total expected lines | 51 |
| Matching lines | 45 (88.2%) |
| Mismatched lines | 6 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 15.2s |  |
| 2 | `background` | 0 | 15.8s |  |
| 3 | `dict_callframe` | 3 | 16.2s |  |
| 4 | `dict_cross` | 3 | 17.1s |  |
| 5 | `dict_override` | 2 | 15.2s |  |
| 6 | `func_dict` | 3 | 15.2s |  |
| 7 | `initaction_in_definesprite` | 2 | 14.9s |  |
| 8 | `jump_after_end` | 3 | 15.2s |  |
| 9 | `missing_bitmap` | 0 | 16.1s |  |
| 10 | `mixed-bytecode-as2` | 1 | 15.1s |  |
| 11 | `trace-as2/shortstack` | 2 | 15.2s |  |
| 12 | `trace-as2/super` | 8 | 14.8s |  |
| 13 | `trace-as2/this` | 8 | 15.5s |  |
| 14 | `zeroframe_definesprite` | 3 | 15.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `dict_event` | 2 | 2 | 15.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `trace-as2/root_onload` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `trace-as2/root_onload` | 50.0% | 2/4 | 4 | 4 |  |
| 2 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
| 3 | `tags_after_last_showframe` | 0.0% | 0/15 | 15 | 1 |  |
