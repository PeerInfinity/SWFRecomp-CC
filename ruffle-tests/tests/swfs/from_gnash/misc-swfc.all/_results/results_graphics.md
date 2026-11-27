# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 06:45 UTC

**Git SHA**: `2d40d37996`

**Run Duration**: 5m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **16** (80.0%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (95.0%) |
| Failing | 1 |
| Total expected lines | 591 |
| Matching lines | 553 (93.6%) |
| Mismatched lines | 38 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**16 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `action_execution_order_test12` | 22 | 20.6s |  |
| 2 | `button_test1` | 31 | 2.2s |  |
| 3 | `edittext_test1` | 47 | 21.7s |  |
| 4 | `gotoFrameFromInterval` | 23 | 20.0s |  |
| 5 | `gotoFrameFromInterval2` | 23 | 26.0s |  |
| 6 | `gotoFrameLabelAsFunction` | 6 | 19.6s |  |
| 7 | `hello` | 4 | 26.4s |  |
| 8 | `movieclip_destruction_test2` | 56 | 17.0s |  |
| 9 | `movieclip_destruction_test3` | 18 | 20.2s |  |
| 10 | `movieclip_destruction_test4` | 40 | 19.7s |  |
| 11 | `opcode_guard_test2` | 24 | 21.7s |  |
| 12 | `soft_reference_test1` | 45 | 19.9s |  |
| 13 | `sound` | 7 | 26.0s |  |
| 14 | `stackscope` | 11 | 2.0s |  |
| 15 | `submoviegetvar` | 4 | 2.4s |  |
| 16 | `swf4opcode` | 117 | 3.9s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 20.9s |  |
| 2 | `movieclip_destruction_test1` | 12 | 52 | 20.2s |  |
| 3 | `registerclass_test3` | 12 | 20 | 3.4s |  |

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
