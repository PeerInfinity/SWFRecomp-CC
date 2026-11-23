# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 02:33 UTC

**Git SHA**: `509768d1d3`

**Run Duration**: 5m 36s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **14** (70.0%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (95.0%) |
| Failing | 1 |
| Total expected lines | 580 |
| Matching lines | 488 (84.1%) |
| Mismatched lines | 92 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.0s |  |
| 2 | `edittext_test1` | 47 | 25.2s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 18.5s |  |
| 4 | `hello` | 4 | 1.6s |  |
| 5 | `mouse_drag_test` | 12 | 18.4s |  |
| 6 | `movieclip_destruction_test2` | 56 | 19.0s |  |
| 7 | `movieclip_destruction_test3` | 18 | 19.3s |  |
| 8 | `movieclip_destruction_test4` | 40 | 18.8s |  |
| 9 | `opcode_guard_test2` | 24 | 18.6s |  |
| 10 | `soft_reference_test1` | 45 | 24.5s |  |
| 11 | `sound` | 7 | 23.9s |  |
| 12 | `stackscope` | 11 | 18.9s |  |
| 13 | `submoviegetvar` | 4 | 18.7s |  |
| 14 | `swf4opcode` | 117 | 26.0s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 24.9s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 14.8s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 2.0s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 19.4s |  |
| 5 | `registerclass_test3` | 12 | 20 | 18.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_accuracy_test1` | 66.7% | 12 | 18 | 6 |  |

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
| 1 | `matrix_accuracy_test1` | 66.7% | 12/18 | 18 | 18 |  |
