# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 03:08 UTC

**Git SHA**: `a3b81f5aab`

**Run Duration**: 4m 17s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **6** (37.5%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **11** (68.8%) |
| Failing | 5 |
| Total expected lines | 499 |
| Matching lines | 332 (66.5%) |
| Mismatched lines | 167 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 17.4s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 17.7s |  |
| 3 | `hello` | 4 | 17.7s |  |
| 4 | `mouse_drag_test` | 12 | 17.4s |  |
| 5 | `stackscope` | 11 | 17.5s |  |
| 6 | `submoviegetvar` | 4 | 18.4s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 19.2s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 18.2s |  |
| 3 | `registerclass_test3` | 12 | 20 | 18.8s |  |
| 4 | `soft_reference_test1` | 3 | 4 | 17.9s |  |
| 5 | `swf4opcode` | 4 | 13 | 18.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `opcode_guard_test2` | 66.7% | 16 | 24 | 8 |  |
| 2 | `button_test1` | 64.5% | 20 | 31 | 11 |  |
| 3 | `sound` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `opcode_guard_test2` | 66.7% | 16/24 | 24 | 24 |  |
| 2 | `button_test1` | 64.5% | 20/31 | 20 | 31 |  |
| 3 | `sound` | 50.0% | 6/12 | 12 | 7 |  |
| 4 | `movieclip_destruction_test2` | 26.8% | 15/56 | 53 | 56 |  |
| 5 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
