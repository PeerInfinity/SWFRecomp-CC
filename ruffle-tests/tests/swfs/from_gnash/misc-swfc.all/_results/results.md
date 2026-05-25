# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-25 20:10 UTC

**Git SHA**: `fc1fed4aba`

**Run Duration**: 5m 2s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **8** (42.1%) |
| Ruffle-matched | 7 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (78.9%) |
| Failing | 4 |
| Total expected lines | 557 |
| Matching lines | 424 (76.1%) |
| Mismatched lines | 133 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 1.7s |  |
| 2 | `edittext_test1` | 47 | 18.9s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 20.0s |  |
| 4 | `hello` | 4 | 21.1s |  |
| 5 | `mouse_drag_test` | 12 | 19.3s |  |
| 6 | `movieclip_destruction_test2` | 56 | 0.3s |  |
| 7 | `stackscope` | 11 | 1.5s |  |
| 8 | `submoviegetvar` | 4 | 20.1s |  |

## Ruffle-Matched Tests

**7 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 14.7s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 20.5s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 20.9s |  |
| 4 | `opcode_guard_test2` | 5 | 5 | 20.2s |  |
| 5 | `registerclass_test3` | 12 | 20 | 18.3s |  |
| 6 | `soft_reference_test1` | 3 | 4 | 19.7s |  |
| 7 | `swf4opcode` | 4 | 11 | 2.6s |  |

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
