# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 19:43 UTC

**Git SHA**: `1396f1e10b`

**Run Duration**: 5m 41s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 21 |
| Passing | **14** (66.7%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **20** (95.2%) |
| Failing | 1 |
| Total expected lines | 603 |
| Matching lines | 491 (81.4%) |
| Mismatched lines | 112 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.0s |  |
| 2 | `edittext_test1` | 47 | 21.8s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 25.6s |  |
| 4 | `hello` | 4 | 2.5s |  |
| 5 | `mouse_drag_test` | 12 | 3.0s |  |
| 6 | `movieclip_destruction_test2` | 56 | 19.1s |  |
| 7 | `movieclip_destruction_test3` | 18 | 25.1s |  |
| 8 | `movieclip_destruction_test4` | 40 | 19.0s |  |
| 9 | `opcode_guard_test2` | 24 | 18.9s |  |
| 10 | `soft_reference_test1` | 45 | 19.5s |  |
| 11 | `sound` | 7 | 26.5s |  |
| 12 | `stackscope` | 11 | 1.9s |  |
| 13 | `submoviegetvar` | 4 | 16.2s |  |
| 14 | `swf4opcode` | 117 | 3.0s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 26.4s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 27.4s |  |
| 3 | `gotoFrameFromInterval` | 20 | 30 | 25.9s |  |
| 4 | `gotoFrameFromInterval2` | 18 | 18 | 25.9s |  |
| 5 | `movieclip_destruction_test1` | 43 | 52 | 25.9s |  |
| 6 | `registerclass_test3` | 12 | 20 | 2.2s |  |

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
