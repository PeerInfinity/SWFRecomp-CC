# Ruffle Test Results (Filtered)

**Date**: 2026-11-24 07:25 UTC

**Git SHA**: `cceb5133a1`

**Run Duration**: 4m 44s

**Filtered**: 1 tests ignored out of 21 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **14** (70.0%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **20** (100.0%) |
| Failing | 0 |
| Total expected lines | 585 |
| Matching lines | 512 (87.5%) |
| Mismatched lines | 73 |

## Passing Tests

**14 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 3.0s |  |
| 2 | `edittext_test1` | 47 | 19.1s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 2.1s |  |
| 4 | `hello` | 4 | 18.9s |  |
| 5 | `mouse_drag_test` | 12 | 2.0s |  |
| 6 | `movieclip_destruction_test2` | 56 | 3.6s |  |
| 7 | `movieclip_destruction_test3` | 18 | 19.0s |  |
| 8 | `movieclip_destruction_test4` | 40 | 20.3s |  |
| 9 | `opcode_guard_test2` | 24 | 20.3s |  |
| 10 | `soft_reference_test1` | 45 | 24.7s |  |
| 11 | `sound` | 7 | 24.9s |  |
| 12 | `stackscope` | 11 | 1.9s |  |
| 13 | `submoviegetvar` | 4 | 18.6s |  |
| 14 | `swf4opcode` | 117 | 3.9s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 19.3s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 19.7s |  |
| 3 | `gotoFrameFromInterval` | 18 | 30 | 19.3s |  |
| 4 | `gotoFrameFromInterval2` | 18 | 18 | 18.9s |  |
| 5 | `movieclip_destruction_test1` | 12 | 52 | 20.1s |  |
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
