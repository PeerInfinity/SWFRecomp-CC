# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-29 20:58 UTC

**Git SHA**: `ddf6a589f7`

**Run Duration**: 5m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **10** (50.0%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (75.0%) |
| Failing | 5 |
| Total expected lines | 580 |
| Matching lines | 435 (75.0%) |
| Mismatched lines | 145 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.9s |  |
| 2 | `edittext_test1` | 47 | 21.4s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 21.8s |  |
| 4 | `hello` | 4 | 21.2s |  |
| 5 | `mouse_drag_test` | 12 | 21.6s |  |
| 6 | `movieclip_destruction_test2` | 56 | 22.3s |  |
| 7 | `opcode_guard_test2` | 24 | 21.5s |  |
| 8 | `stackscope` | 11 | 21.3s |  |
| 9 | `submoviegetvar` | 4 | 21.7s |  |
| 10 | `swf4opcode` | 117 | 3.5s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 22.2s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 21.5s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 23.2s |  |
| 4 | `registerclass_test3` | 12 | 20 | 2.8s |  |
| 5 | `soft_reference_test1` | 3 | 4 | 22.5s |  |

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
