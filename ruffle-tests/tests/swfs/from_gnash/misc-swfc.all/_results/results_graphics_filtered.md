# Ruffle Test Results (Filtered)

**Date**: 2026-11-22 01:00 UTC

**Git SHA**: `ff2e2e9d60`

**Run Duration**: 5m 18s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **13** (72.2%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **18** (100.0%) |
| Failing | 0 |
| Total expected lines | 555 |
| Matching lines | 469 (84.5%) |
| Mismatched lines | 86 |

## Passing Tests

**13 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.0s |  |
| 2 | `edittext_test1` | 47 | 18.8s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 18.4s |  |
| 4 | `hello` | 4 | 1.6s |  |
| 5 | `mouse_drag_test` | 12 | 18.0s |  |
| 6 | `movieclip_destruction_test2` | 56 | 18.9s |  |
| 7 | `movieclip_destruction_test3` | 18 | 17.8s |  |
| 8 | `movieclip_destruction_test4` | 40 | 18.2s |  |
| 9 | `opcode_guard_test2` | 24 | 23.7s |  |
| 10 | `soft_reference_test1` | 45 | 18.3s |  |
| 11 | `stackscope` | 11 | 23.3s |  |
| 12 | `submoviegetvar` | 4 | 17.2s |  |
| 13 | `swf4opcode` | 117 | 18.8s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 18.2s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 23.6s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 1.9s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 20.2s |  |
| 5 | `registerclass_test3` | 12 | 20 | 18.9s |  |

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
