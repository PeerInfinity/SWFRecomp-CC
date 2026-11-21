# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 20:48 UTC

**Git SHA**: `9a970370e0`

**Run Duration**: 5m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **13** (65.0%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **18** (90.0%) |
| Failing | 2 |
| Total expected lines | 580 |
| Matching lines | 486 (83.8%) |
| Mismatched lines | 94 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**13 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.0s |  |
| 2 | `edittext_test1` | 47 | 18.0s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 17.7s |  |
| 4 | `hello` | 4 | 2.4s |  |
| 5 | `mouse_drag_test` | 12 | 22.6s |  |
| 6 | `movieclip_destruction_test2` | 56 | 19.1s |  |
| 7 | `movieclip_destruction_test3` | 18 | 18.2s |  |
| 8 | `movieclip_destruction_test4` | 40 | 17.5s |  |
| 9 | `opcode_guard_test2` | 24 | 19.4s |  |
| 10 | `soft_reference_test1` | 45 | 18.6s |  |
| 11 | `stackscope` | 11 | 23.4s |  |
| 12 | `submoviegetvar` | 4 | 18.2s |  |
| 13 | `swf4opcode` | 117 | 19.1s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 24.1s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 24.0s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 2.9s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 18.6s |  |
| 5 | `registerclass_test3` | 12 | 20 | 17.9s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 2 | `matrix_accuracy_test1` | 55.6% | 10/18 | 18 | 18 |  |
