# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 16:53 UTC

**Git SHA**: `d81f64081e`

**Run Duration**: 4m 20s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 21 |
| Passing | **17** (81.0%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **20** (95.2%) |
| Failing | 1 |
| Total expected lines | 603 |
| Matching lines | 565 (93.7%) |
| Mismatched lines | 38 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**17 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `action_execution_order_test12` | 22 | 21.2s |  |
| 2 | `button_test1` | 31 | 2.2s |  |
| 3 | `edittext_test1` | 47 | 18.1s |  |
| 4 | `gotoFrameFromInterval` | 23 | 21.9s |  |
| 5 | `gotoFrameFromInterval2` | 23 | 2.7s |  |
| 6 | `gotoFrameLabelAsFunction` | 6 | 1.9s |  |
| 7 | `hello` | 4 | 1.8s |  |
| 8 | `mouse_drag_test` | 12 | 2.1s |  |
| 9 | `movieclip_destruction_test2` | 56 | 2.4s |  |
| 10 | `movieclip_destruction_test3` | 18 | 21.6s |  |
| 11 | `movieclip_destruction_test4` | 40 | 20.9s |  |
| 12 | `opcode_guard_test2` | 24 | 22.0s |  |
| 13 | `soft_reference_test1` | 45 | 20.6s |  |
| 14 | `sound` | 7 | 20.0s |  |
| 15 | `stackscope` | 11 | 2.0s |  |
| 16 | `submoviegetvar` | 4 | 20.5s |  |
| 17 | `swf4opcode` | 117 | 3.6s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 27.8s |  |
| 2 | `movieclip_destruction_test1` | 12 | 52 | 21.4s |  |
| 3 | `registerclass_test3` | 12 | 20 | 2.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_accuracy_test1` | 83.3% | 15 | 18 | 3 |  |

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
| 1 | `matrix_accuracy_test1` | 83.3% | 15/18 | 18 | 18 |  |
