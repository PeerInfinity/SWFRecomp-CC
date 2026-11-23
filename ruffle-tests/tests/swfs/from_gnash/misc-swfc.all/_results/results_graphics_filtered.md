# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 23:56 UTC

**Git SHA**: `005bea42a2`

**Run Duration**: 4m 57s

**Filtered**: 1 tests ignored out of 21 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 19 |
| Passing | **13** (68.4%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **19** (100.0%) |
| Failing | 0 |
| Total expected lines | 581 |
| Matching lines | 475 (81.8%) |
| Mismatched lines | 106 |

## Passing Tests

**13 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 3.1s |  |
| 2 | `edittext_test1` | 47 | 19.2s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 19.1s |  |
| 4 | `mouse_drag_test` | 12 | 1.9s |  |
| 5 | `movieclip_destruction_test2` | 56 | 19.4s |  |
| 6 | `movieclip_destruction_test3` | 18 | 19.5s |  |
| 7 | `movieclip_destruction_test4` | 40 | 19.4s |  |
| 8 | `opcode_guard_test2` | 24 | 19.7s |  |
| 9 | `soft_reference_test1` | 45 | 18.8s |  |
| 10 | `sound` | 7 | 18.9s |  |
| 11 | `stackscope` | 11 | 2.6s |  |
| 12 | `submoviegetvar` | 4 | 18.9s |  |
| 13 | `swf4opcode` | 117 | 2.9s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 19.2s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 19.4s |  |
| 3 | `gotoFrameFromInterval` | 20 | 30 | 25.0s |  |
| 4 | `gotoFrameFromInterval2` | 18 | 18 | 24.2s |  |
| 5 | `movieclip_destruction_test1` | 43 | 52 | 19.8s |  |
| 6 | `registerclass_test3` | 12 | 20 | 2.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
