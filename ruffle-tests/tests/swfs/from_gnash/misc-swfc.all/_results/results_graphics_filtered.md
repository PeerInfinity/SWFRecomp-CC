# Ruffle Test Results (Filtered)

**Date**: 2026-06-25 18:24 UTC

**Git SHA**: `54070f5303`

**Run Duration**: 5m 13s

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
| 1 | `button_test1` | 31 | 2.5s |  |
| 2 | `edittext_test1` | 47 | 25.2s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 21.0s |  |
| 4 | `hello` | 4 | 20.6s |  |
| 5 | `mouse_drag_test` | 12 | 13.9s |  |
| 6 | `movieclip_destruction_test2` | 56 | 22.1s |  |
| 7 | `opcode_guard_test2` | 24 | 22.4s |  |
| 8 | `stackscope` | 11 | 21.8s |  |
| 9 | `submoviegetvar` | 4 | 20.7s |  |
| 10 | `swf4opcode` | 117 | 3.6s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 22.1s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 21.4s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 19.5s |  |
| 4 | `registerclass_test3` | 12 | 20 | 2.8s |  |

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
