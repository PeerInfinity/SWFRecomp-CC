# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 21:10 UTC

**Git SHA**: `10a5b515a0`

**Run Duration**: 4m 44s

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
| 1 | `action_execution_order_test12` | 22 | 19.3s |  |
| 2 | `button_test1` | 31 | 1.4s |  |
| 3 | `edittext_test1` | 47 | 19.1s |  |
| 4 | `gotoFrameLabelAsFunction` | 6 | 18.9s |  |
| 5 | `hello` | 4 | 1.1s |  |
| 6 | `mouse_drag_test` | 12 | 1.3s |  |
| 7 | `movieclip_destruction_test2` | 56 | 19.1s |  |
| 8 | `movieclip_destruction_test3` | 18 | 18.5s |  |
| 9 | `movieclip_destruction_test4` | 40 | 19.6s |  |
| 10 | `opcode_guard_test2` | 24 | 19.6s |  |
| 11 | `soft_reference_test1` | 45 | 15.8s |  |
| 12 | `sound` | 7 | 21.3s |  |
| 13 | `stackscope` | 11 | 1.2s |  |
| 14 | `submoviegetvar` | 4 | 18.4s |  |
| 15 | `swf4opcode` | 117 | 2.3s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 24.6s |  |
| 2 | `gotoFrameFromInterval` | 18 | 30 | 20.0s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 18.7s |  |
| 4 | `movieclip_destruction_test1` | 12 | 52 | 19.3s |  |
| 5 | `registerclass_test3` | 12 | 20 | 2.6s |  |

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
