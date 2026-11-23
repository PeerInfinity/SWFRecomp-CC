# Ruffle Test Results (Filtered)

**Date**: 2026-11-22 23:31 UTC

**Git SHA**: `697669e5f9`

**Run Duration**: 5m 18s

**Filtered**: 1 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **13** (68.4%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **18** (94.7%) |
| Failing | 1 |
| Total expected lines | 562 |
| Matching lines | 476 (84.7%) |
| Mismatched lines | 86 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**13 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 1.8s |  |
| 2 | `edittext_test1` | 47 | 18.1s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 23.4s |  |
| 4 | `hello` | 4 | 1.6s |  |
| 5 | `mouse_drag_test` | 12 | 18.4s |  |
| 6 | `movieclip_destruction_test2` | 56 | 19.9s |  |
| 7 | `movieclip_destruction_test3` | 18 | 21.5s |  |
| 8 | `movieclip_destruction_test4` | 40 | 18.3s |  |
| 9 | `opcode_guard_test2` | 24 | 18.7s |  |
| 10 | `soft_reference_test1` | 45 | 25.6s |  |
| 11 | `stackscope` | 11 | 18.0s |  |
| 12 | `submoviegetvar` | 4 | 19.9s |  |
| 13 | `swf4opcode` | 117 | 18.1s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 18.3s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 18.0s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 1.3s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 19.6s |  |
| 5 | `registerclass_test3` | 12 | 20 | 17.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `sound` | 58.3% | 7 | 12 | 5 |  |

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
| 1 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
