# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-12 01:30 UTC

**Git SHA**: `521a537828`

**Run Duration**: 5m 44s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **10** (50.0%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **16** (80.0%) |
| Failing | 4 |
| Total expected lines | 580 |
| Matching lines | 434 (74.8%) |
| Mismatched lines | 146 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.8s |  |
| 2 | `edittext_test1` | 47 | 23.6s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 21.8s |  |
| 4 | `hello` | 4 | 1.9s |  |
| 5 | `mouse_drag_test` | 12 | 17.4s |  |
| 6 | `movieclip_destruction_test2` | 56 | 20.7s |  |
| 7 | `opcode_guard_test2` | 24 | 16.0s |  |
| 8 | `soft_reference_test1` | 45 | 22.3s |  |
| 9 | `stackscope` | 11 | 13.5s |  |
| 10 | `submoviegetvar` | 4 | 23.3s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 23.4s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 17.9s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 2.7s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 23.4s |  |
| 5 | `registerclass_test3` | 12 | 20 | 21.9s |  |
| 6 | `swf4opcode` | 7 | 11 | 23.5s |  |

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
