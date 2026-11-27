# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 22:24 UTC

**Git SHA**: `0224aaf256`

**Run Duration**: 4m 48s

**Filtered**: 1 tests ignored out of 21 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 20 |
| Passing | **17** (85.0%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **20** (100.0%) |
| Failing | 0 |
| Total expected lines | 585 |
| Matching lines | 550 (94.0%) |
| Mismatched lines | 35 |

## Passing Tests

**17 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `action_execution_order_test12` | 22 | 24.9s |  |
| 2 | `button_test1` | 31 | 1.8s |  |
| 3 | `edittext_test1` | 47 | 25.5s |  |
| 4 | `gotoFrameFromInterval` | 23 | 15.5s |  |
| 5 | `gotoFrameFromInterval2` | 23 | 2.1s |  |
| 6 | `gotoFrameLabelAsFunction` | 6 | 1.2s |  |
| 7 | `hello` | 4 | 19.6s |  |
| 8 | `mouse_drag_test` | 12 | 1.8s |  |
| 9 | `movieclip_destruction_test2` | 56 | 21.2s |  |
| 10 | `movieclip_destruction_test3` | 18 | 19.1s |  |
| 11 | `movieclip_destruction_test4` | 40 | 21.5s |  |
| 12 | `opcode_guard_test2` | 24 | 19.8s |  |
| 13 | `soft_reference_test1` | 45 | 20.4s |  |
| 14 | `sound` | 7 | 20.3s |  |
| 15 | `stackscope` | 11 | 1.9s |  |
| 16 | `submoviegetvar` | 4 | 19.2s |  |
| 17 | `swf4opcode` | 117 | 3.0s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 26.1s |  |
| 2 | `movieclip_destruction_test1` | 12 | 52 | 20.6s |  |
| 3 | `registerclass_test3` | 12 | 20 | 1.6s |  |

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
