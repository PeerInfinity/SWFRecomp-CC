# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 18:08 UTC

**Git SHA**: `f4edebdcec`

**Run Duration**: 5m 10s

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
| 1 | `action_execution_order_test12` | 22 | 20.6s |  |
| 2 | `button_test1` | 31 | 2.8s |  |
| 3 | `edittext_test1` | 47 | 20.4s |  |
| 4 | `gotoFrameFromInterval` | 23 | 20.7s |  |
| 5 | `gotoFrameFromInterval2` | 23 | 20.2s |  |
| 6 | `gotoFrameLabelAsFunction` | 6 | 25.6s |  |
| 7 | `hello` | 4 | 19.5s |  |
| 8 | `mouse_drag_test` | 12 | 2.6s |  |
| 9 | `movieclip_destruction_test2` | 56 | 23.0s |  |
| 10 | `movieclip_destruction_test3` | 18 | 23.3s |  |
| 11 | `movieclip_destruction_test4` | 40 | 20.4s |  |
| 12 | `opcode_guard_test2` | 24 | 20.2s |  |
| 13 | `soft_reference_test1` | 45 | 19.9s |  |
| 14 | `sound` | 7 | 20.7s |  |
| 15 | `stackscope` | 11 | 1.9s |  |
| 16 | `submoviegetvar` | 4 | 1.9s |  |
| 17 | `swf4opcode` | 117 | 3.0s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 19.4s |  |
| 2 | `movieclip_destruction_test1` | 12 | 52 | 17.9s |  |
| 3 | `registerclass_test3` | 12 | 20 | 3.0s |  |

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
