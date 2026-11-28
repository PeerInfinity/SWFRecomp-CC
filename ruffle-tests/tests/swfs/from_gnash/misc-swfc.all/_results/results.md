# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 18:23 UTC

**Git SHA**: `494d7c7e06`

**Run Duration**: 3m 52s

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
| 1 | `action_execution_order_test12` | 22 | 25.5s |  |
| 2 | `button_test1` | 31 | 1.5s |  |
| 3 | `edittext_test1` | 47 | 26.1s |  |
| 4 | `gotoFrameFromInterval` | 23 | 25.6s |  |
| 5 | `gotoFrameFromInterval2` | 23 | 1.8s |  |
| 6 | `gotoFrameLabelAsFunction` | 6 | 1.7s |  |
| 7 | `hello` | 4 | 1.7s |  |
| 8 | `mouse_drag_test` | 12 | 1.4s |  |
| 9 | `movieclip_destruction_test2` | 56 | 1.7s |  |
| 10 | `movieclip_destruction_test3` | 18 | 17.5s |  |
| 11 | `movieclip_destruction_test4` | 40 | 20.3s |  |
| 12 | `opcode_guard_test2` | 24 | 20.6s |  |
| 13 | `soft_reference_test1` | 45 | 19.4s |  |
| 14 | `sound` | 7 | 19.4s |  |
| 15 | `stackscope` | 11 | 1.6s |  |
| 16 | `submoviegetvar` | 4 | 1.2s |  |
| 17 | `swf4opcode` | 117 | 2.3s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 20.3s |  |
| 2 | `movieclip_destruction_test1` | 12 | 52 | 18.4s |  |
| 3 | `registerclass_test3` | 12 | 20 | 1.8s |  |

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
