# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-13 22:44 UTC

**Git SHA**: `2511a98544`

**Run Duration**: 0m 17s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **9** (47.4%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **14** (73.7%) |
| Failing | 5 |
| Total expected lines | 557 |
| Matching lines | 428 (76.8%) |
| Mismatched lines | 129 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**9 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 0.8s |  |
| 2 | `edittext_test1` | 47 | 0.8s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 0.8s |  |
| 4 | `hello` | 4 | 0.7s |  |
| 5 | `mouse_drag_test` | 12 | 0.8s |  |
| 6 | `movieclip_destruction_test2` | 56 | 0.8s |  |
| 7 | `stackscope` | 11 | 0.8s |  |
| 8 | `submoviegetvar` | 4 | 0.7s |  |
| 9 | `swf4opcode` | 117 | 0.8s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 1.0s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 0.8s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 0.9s |  |
| 4 | `registerclass_test3` | 12 | 20 | 0.9s |  |
| 5 | `soft_reference_test1` | 3 | 4 | 0.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `opcode_guard_test2` | 79.2% | 19 | 24 | 5 |  |
| 2 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 3 | `matrix_accuracy_test1` | 55.6% | 10 | 18 | 8 |  |

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
| 1 | `opcode_guard_test2` | 79.2% | 19/24 | 24 | 24 |  |
| 2 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 3 | `matrix_accuracy_test1` | 55.6% | 10/18 | 18 | 18 |  |
| 4 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
| 5 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
