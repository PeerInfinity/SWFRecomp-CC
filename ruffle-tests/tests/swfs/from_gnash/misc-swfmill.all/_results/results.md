# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-01 20:42 UTC

**Git SHA**: `48a97e0b07`

**Run Duration**: 5m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **16** (88.9%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **17** (94.4%) |
| Failing | 1 |
| Total expected lines | 51 |
| Matching lines | 48 (94.1%) |
| Mismatched lines | 3 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**16 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `afunc_dict` | 2 | 18.4s |  |
| 2 | `background` | 0 | 18.1s |  |
| 3 | `dict_callframe` | 3 | 17.1s |  |
| 4 | `dict_cross` | 3 | 17.8s |  |
| 5 | `dict_event` | 5 | 16.8s |  |
| 6 | `dict_override` | 2 | 17.0s |  |
| 7 | `func_dict` | 3 | 17.0s |  |
| 8 | `initaction_in_definesprite` | 2 | 16.7s |  |
| 9 | `jump_after_end` | 3 | 18.1s |  |
| 10 | `missing_bitmap` | 0 | 18.7s |  |
| 11 | `mixed-bytecode-as2` | 1 | 17.3s |  |
| 12 | `tags_after_last_showframe` | 1 | 13.2s |  |
| 13 | `trace-as2/root_onload` | 4 | 17.3s |  |
| 14 | `trace-as2/shortstack` | 2 | 17.4s |  |
| 15 | `trace-as2/super` | 8 | 18.2s |  |
| 16 | `trace-as2/this` | 8 | 17.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `zeroframe_definesprite` | 2 | 2 | 16.5s |  |

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

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `jump_to_prev_block` | 0.0% | 0/1 | 1 | 1 |  |
