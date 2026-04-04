# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-04 02:19 UTC

**Git SHA**: `112f7a9df7`

**Run Duration**: 5m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **2** (12.5%) |
| Failing | 14 |
| Total expected lines | 511 |
| Matching lines | 216 (42.3%) |
| Mismatched lines | 295 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 92.9% |
| Runtime Error | 1 | 7.1% |

## Passing Tests

**2 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `gotoFrameLabelAsFunction` | 6 | 18.3s |  |
| 2 | `hello` | 4 | 18.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_test1` | 76.6% | 36 | 47 | 11 |  |
| 2 | `movieclip_destruction_test2` | 73.2% | 41 | 56 | 15 |  |
| 3 | `swf4opcode` | 63.2% | 74 | 117 | 43 |  |
| 4 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `opcode_guard_test2` | exit code -6 | 20.3s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_test1` | 76.6% | 36/47 | 47 | 47 |  |
| 2 | `movieclip_destruction_test2` | 73.2% | 41/56 | 56 | 56 |  |
| 3 | `swf4opcode` | 63.2% | 74/117 | 117 | 117 |  |
| 4 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 5 | `sound` | 41.7% | 5/12 | 12 | 7 |  |
| 6 | `soft_reference_test1` | 35.6% | 16/45 | 42 | 45 |  |
| 7 | `registerclass_test3` | 33.3% | 9/27 | 27 | 27 |  |
| 8 | `button_test1` | 25.8% | 8/31 | 20 | 31 |  |
| 9 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 10 | `action_execution_order_test10` | 12.5% | 2/16 | 10 | 16 |  |
| 11 | `gotoFrameFromInterval2` | 4.2% | 1/24 | 24 | 23 |  |
| 12 | `movieclip_destruction_test1` | 0.0% | 0/52 | 35 | 52 |  |
| 13 | `submoviegetvar` | 0.0% | 0/4 | 4 | 4 |  |
