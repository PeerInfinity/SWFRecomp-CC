# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-25 22:36 UTC

**Git SHA**: `16033a1546`

**Run Duration**: 5m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 21 |
| Passing | **15** (71.4%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **20** (95.2%) |
| Failing | 1 |
| Total expected lines | 603 |
| Matching lines | 529 (87.7%) |
| Mismatched lines | 74 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**15 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `action_execution_order_test12` | 22 | 22.6s |  |
| 2 | `button_test1` | 31 | 2.1s |  |
| 3 | `edittext_test1` | 47 | 20.5s |  |
| 4 | `gotoFrameLabelAsFunction` | 6 | 16.4s |  |
| 5 | `hello` | 4 | 21.0s |  |
| 6 | `mouse_drag_test` | 12 | 2.2s |  |
| 7 | `movieclip_destruction_test2` | 56 | 21.6s |  |
| 8 | `movieclip_destruction_test3` | 18 | 21.4s |  |
| 9 | `movieclip_destruction_test4` | 40 | 20.7s |  |
| 10 | `opcode_guard_test2` | 24 | 20.3s |  |
| 11 | `soft_reference_test1` | 45 | 26.1s |  |
| 12 | `sound` | 7 | 19.4s |  |
| 13 | `stackscope` | 11 | 3.0s |  |
| 14 | `submoviegetvar` | 4 | 20.4s |  |
| 15 | `swf4opcode` | 117 | 2.9s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 20.7s |  |
| 2 | `gotoFrameFromInterval` | 18 | 30 | 20.8s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 21.3s |  |
| 4 | `movieclip_destruction_test1` | 12 | 52 | 21.0s |  |
| 5 | `registerclass_test3` | 12 | 20 | 3.8s |  |

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
