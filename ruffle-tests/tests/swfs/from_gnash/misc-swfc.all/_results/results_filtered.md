# Ruffle Test Results (Filtered)

**Date**: 2026-04-13 19:34 UTC

**Git SHA**: `83d3748a60`

**Run Duration**: 5m 23s

**Filtered**: 0 tests ignored out of 16 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **2** (12.5%) |
| Failing | 14 |
| Total expected lines | 499 |
| Matching lines | 222 (44.5%) |
| Mismatched lines | 277 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 92.9% |
| Runtime Error | 1 | 7.1% |

## Passing Tests

**2 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `gotoFrameLabelAsFunction` | 6 | 19.8s |  |
| 2 | `hello` | 4 | 19.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_test1` | 76.6% | 36 | 47 | 11 |  |
| 2 | `movieclip_destruction_test2` | 73.2% | 41 | 56 | 15 |  |
| 3 | `stackscope` | 72.7% | 8 | 11 | 3 |  |
| 4 | `swf4opcode` | 63.2% | 74 | 117 | 43 |  |
| 5 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `opcode_guard_test2` | exit code -6 | 21.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_test1` | 76.6% | 36/47 | 47 | 47 |  |
| 2 | `movieclip_destruction_test2` | 73.2% | 41/56 | 56 | 56 |  |
| 3 | `stackscope` | 72.7% | 8/11 | 11 | 11 |  |
| 4 | `swf4opcode` | 63.2% | 74/117 | 117 | 117 |  |
| 5 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 6 | `sound` | 41.7% | 5/12 | 12 | 7 |  |
| 7 | `soft_reference_test1` | 37.8% | 17/45 | 42 | 45 |  |
| 8 | `registerclass_test3` | 25.9% | 7/27 | 27 | 27 |  |
| 9 | `button_test1` | 25.8% | 8/31 | 20 | 31 |  |
| 10 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 11 | `action_execution_order_test10` | 12.5% | 2/16 | 10 | 16 |  |
| 12 | `movieclip_destruction_test1` | 0.0% | 0/52 | 35 | 52 |  |
| 13 | `submoviegetvar` | 0.0% | 0/4 | 4 | 4 |  |
