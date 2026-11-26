# Ruffle Test Results (Filtered)

**Date**: 2026-11-26 23:43 UTC

**Git SHA**: `4989a9dfb5`

**Run Duration**: 4m 28s

**Filtered**: 1 tests ignored out of 21 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **15** (75.0%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **20** (100.0%) |
| Failing | 0 |
| Total expected lines | 585 |
| Matching lines | 514 (87.9%) |
| Mismatched lines | 71 |

## Passing Tests

**15 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `action_execution_order_test12` | 22 | 21.9s |  |
| 2 | `button_test1` | 31 | 2.2s |  |
| 3 | `edittext_test1` | 47 | 20.5s |  |
| 4 | `gotoFrameLabelAsFunction` | 6 | 20.7s |  |
| 5 | `hello` | 4 | 1.8s |  |
| 6 | `mouse_drag_test` | 12 | 2.8s |  |
| 7 | `movieclip_destruction_test2` | 56 | 19.5s |  |
| 8 | `movieclip_destruction_test3` | 18 | 19.7s |  |
| 9 | `movieclip_destruction_test4` | 40 | 2.7s |  |
| 10 | `opcode_guard_test2` | 24 | 20.0s |  |
| 11 | `soft_reference_test1` | 45 | 20.1s |  |
| 12 | `sound` | 7 | 19.2s |  |
| 13 | `stackscope` | 11 | 2.5s |  |
| 14 | `submoviegetvar` | 4 | 19.5s |  |
| 15 | `swf4opcode` | 117 | 3.0s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 21.9s |  |
| 2 | `gotoFrameFromInterval` | 18 | 30 | 3.7s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 19.7s |  |
| 4 | `movieclip_destruction_test1` | 12 | 52 | 20.7s |  |
| 5 | `registerclass_test3` | 12 | 20 | 2.3s |  |

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
