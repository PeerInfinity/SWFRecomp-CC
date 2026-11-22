# Ruffle Test Results (Filtered)

**Date**: 2026-11-22 02:31 UTC

**Git SHA**: `336749f142`

**Run Duration**: 5m 27s

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
| 1 | `button_test1` | 31 | 1.9s |  |
| 2 | `edittext_test1` | 47 | 20.1s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 17.9s |  |
| 4 | `hello` | 4 | 2.0s |  |
| 5 | `mouse_drag_test` | 12 | 18.2s |  |
| 6 | `movieclip_destruction_test2` | 56 | 18.1s |  |
| 7 | `movieclip_destruction_test3` | 18 | 24.7s |  |
| 8 | `movieclip_destruction_test4` | 40 | 18.6s |  |
| 9 | `opcode_guard_test2` | 24 | 15.7s |  |
| 10 | `soft_reference_test1` | 45 | 18.0s |  |
| 11 | `stackscope` | 11 | 17.3s |  |
| 12 | `submoviegetvar` | 4 | 17.4s |  |
| 13 | `swf4opcode` | 117 | 25.4s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 24.0s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 19.3s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 2.0s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 25.7s |  |
| 5 | `registerclass_test3` | 12 | 20 | 20.4s |  |

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
