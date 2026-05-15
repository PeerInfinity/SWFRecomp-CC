# Ruffle Test Results (Filtered)

**Date**: 2026-05-15 02:10 UTC

**Git SHA**: `eb8206f8aa`

**Run Duration**: 5m 4s

**Filtered**: 1 tests ignored out of 19 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **8** (44.4%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **14** (77.8%) |
| Failing | 4 |
| Total expected lines | 550 |
| Matching lines | 405 (73.6%) |
| Mismatched lines | 145 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 1.8s |  |
| 2 | `edittext_test1` | 47 | 20.0s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 19.3s |  |
| 4 | `hello` | 4 | 18.5s |  |
| 5 | `mouse_drag_test` | 12 | 21.6s |  |
| 6 | `movieclip_destruction_test2` | 56 | 2.2s |  |
| 7 | `stackscope` | 11 | 1.6s |  |
| 8 | `submoviegetvar` | 4 | 18.8s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 20.2s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 19.8s |  |
| 3 | `opcode_guard_test2` | 5 | 5 | 19.3s |  |
| 4 | `registerclass_test3` | 12 | 20 | 18.8s |  |
| 5 | `soft_reference_test1` | 3 | 4 | 20.3s |  |
| 6 | `swf4opcode` | 4 | 13 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `matrix_accuracy_test1` | 55.6% | 10 | 18 | 8 |  |

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
| 1 | `matrix_accuracy_test1` | 55.6% | 10/18 | 18 | 18 |  |
| 2 | `action_execution_order_test12` | 40.9% | 9/22 | 20 | 22 |  |
| 3 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
| 4 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
