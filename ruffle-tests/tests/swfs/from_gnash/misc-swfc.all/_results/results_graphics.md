# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-20 20:13 UTC

**Git SHA**: `6dcffb0b49`

**Run Duration**: 4m 56s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **10** (52.6%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **14** (73.7%) |
| Failing | 5 |
| Total expected lines | 535 |
| Matching lines | 393 (73.5%) |
| Mismatched lines | 142 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.7s |  |
| 2 | `edittext_test1` | 47 | 3.1s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 21.0s |  |
| 4 | `hello` | 4 | 13.8s |  |
| 5 | `mouse_drag_test` | 12 | 21.6s |  |
| 6 | `movieclip_destruction_test2` | 56 | 23.6s |  |
| 7 | `opcode_guard_test2` | 24 | 1.0s |  |
| 8 | `stackscope` | 11 | 21.5s |  |
| 9 | `submoviegetvar` | 4 | 24.4s |  |
| 10 | `swf4opcode` | 117 | 23.1s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 3.3s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 21.5s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 22.5s |  |
| 4 | `registerclass_test3` | 12 | 20 | 21.5s |  |

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

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 2 | `matrix_accuracy_test1` | 55.6% | 10/18 | 18 | 18 |  |
| 3 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
| 4 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 5 | `gotoFrameFromInterval2` | 8.3% | 2/24 | 24 | 23 |  |
