# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 23:41 UTC

**Git SHA**: `87465d1130`

**Run Duration**: 5m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **10** (50.0%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **16** (80.0%) |
| Failing | 4 |
| Total expected lines | 580 |
| Matching lines | 438 (75.5%) |
| Mismatched lines | 142 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.0s |  |
| 2 | `edittext_test1` | 47 | 21.4s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 19.6s |  |
| 4 | `hello` | 4 | 21.4s |  |
| 5 | `mouse_drag_test` | 12 | 20.4s |  |
| 6 | `movieclip_destruction_test2` | 56 | 20.6s |  |
| 7 | `opcode_guard_test2` | 24 | 18.2s |  |
| 8 | `stackscope` | 11 | 19.5s |  |
| 9 | `submoviegetvar` | 4 | 20.5s |  |
| 10 | `swf4opcode` | 117 | 21.2s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 19.2s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 20.4s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 1.7s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 14.0s |  |
| 5 | `registerclass_test3` | 12 | 20 | 20.6s |  |
| 6 | `soft_reference_test1` | 3 | 4 | 20.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 2 | `matrix_accuracy_test1` | 55.6% | 10 | 18 | 8 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 2 | `matrix_accuracy_test1` | 55.6% | 10/18 | 18 | 18 |  |
| 3 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
| 4 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
