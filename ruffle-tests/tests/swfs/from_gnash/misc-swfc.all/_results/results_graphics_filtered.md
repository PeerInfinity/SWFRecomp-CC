# Ruffle Test Results (Filtered)

**Date**: 2026-06-21 00:33 UTC

**Git SHA**: `d359234e74`

**Run Duration**: 4m 50s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **10** (58.8%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **14** (82.4%) |
| Failing | 3 |
| Total expected lines | 510 |
| Matching lines | 376 (73.7%) |
| Mismatched lines | 134 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.7s |  |
| 2 | `edittext_test1` | 47 | 3.5s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 20.9s |  |
| 4 | `hello` | 4 | 21.4s |  |
| 5 | `mouse_drag_test` | 12 | 17.3s |  |
| 6 | `movieclip_destruction_test2` | 56 | 21.9s |  |
| 7 | `opcode_guard_test2` | 24 | 1.0s |  |
| 8 | `stackscope` | 11 | 22.0s |  |
| 9 | `submoviegetvar` | 4 | 21.0s |  |
| 10 | `swf4opcode` | 117 | 17.6s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 2.8s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 22.0s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 22.4s |  |
| 4 | `registerclass_test3` | 12 | 20 | 22.2s |  |

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

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
| 2 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 3 | `gotoFrameFromInterval2` | 8.3% | 2/24 | 24 | 23 |  |
