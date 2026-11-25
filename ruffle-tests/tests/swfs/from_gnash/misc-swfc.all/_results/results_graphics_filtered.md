# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 20:23 UTC

**Git SHA**: `13b40eabb0`

**Run Duration**: 5m 31s

**Filtered**: 1 tests ignored out of 21 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **14** (70.0%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (95.0%) |
| Failing | 1 |
| Total expected lines | 585 |
| Matching lines | 511 (87.4%) |
| Mismatched lines | 74 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.3s |  |
| 2 | `edittext_test1` | 47 | 28.1s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 19.3s |  |
| 4 | `hello` | 4 | 1.8s |  |
| 5 | `mouse_drag_test` | 12 | 2.1s |  |
| 6 | `movieclip_destruction_test2` | 56 | 19.5s |  |
| 7 | `movieclip_destruction_test3` | 18 | 22.4s |  |
| 8 | `movieclip_destruction_test4` | 40 | 20.4s |  |
| 9 | `opcode_guard_test2` | 24 | 26.0s |  |
| 10 | `soft_reference_test1` | 45 | 26.8s |  |
| 11 | `sound` | 7 | 19.6s |  |
| 12 | `stackscope` | 11 | 2.0s |  |
| 13 | `submoviegetvar` | 4 | 27.9s |  |
| 14 | `swf4opcode` | 117 | 3.0s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 19.7s |  |
| 2 | `gotoFrameFromInterval` | 18 | 30 | 25.5s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 19.0s |  |
| 4 | `movieclip_destruction_test1` | 12 | 52 | 20.1s |  |
| 5 | `registerclass_test3` | 12 | 20 | 3.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `action_execution_order_test12` | 86.4% | 19 | 22 | 3 |  |

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
| 1 | `action_execution_order_test12` | 86.4% | 19/22 | 22 | 22 |  |
