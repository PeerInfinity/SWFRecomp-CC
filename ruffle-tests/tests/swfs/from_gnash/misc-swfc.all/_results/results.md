# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-11 21:24 UTC

**Git SHA**: `192e8317be`

**Run Duration**: 4m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **9** (47.4%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (78.9%) |
| Failing | 4 |
| Total expected lines | 557 |
| Matching lines | 428 (76.8%) |
| Mismatched lines | 129 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**9 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 0.3s |  |
| 2 | `edittext_test1` | 47 | 19.7s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 19.9s |  |
| 4 | `hello` | 4 | 18.7s |  |
| 5 | `mouse_drag_test` | 12 | 20.1s |  |
| 6 | `movieclip_destruction_test2` | 56 | 0.2s |  |
| 7 | `stackscope` | 11 | 0.3s |  |
| 8 | `submoviegetvar` | 4 | 0.1s |  |
| 9 | `swf4opcode` | 117 | 0.3s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 19.1s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 18.4s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 15.8s |  |
| 4 | `opcode_guard_test2` | 5 | 5 | 14.6s |  |
| 5 | `registerclass_test3` | 12 | 20 | 18.2s |  |
| 6 | `soft_reference_test1` | 3 | 4 | 18.1s |  |

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
