# Ruffle Test Results (Filtered)

**Date**: 2026-06-24 03:30 UTC

**Git SHA**: `b436318402`

**Run Duration**: 5m 45s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **10** (55.6%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (83.3%) |
| Failing | 3 |
| Total expected lines | 555 |
| Matching lines | 418 (75.3%) |
| Mismatched lines | 137 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.7s |  |
| 2 | `edittext_test1` | 47 | 23.5s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 21.6s |  |
| 4 | `hello` | 4 | 20.4s |  |
| 5 | `mouse_drag_test` | 12 | 20.6s |  |
| 6 | `movieclip_destruction_test2` | 56 | 21.5s |  |
| 7 | `opcode_guard_test2` | 24 | 17.8s |  |
| 8 | `stackscope` | 11 | 21.0s |  |
| 9 | `submoviegetvar` | 4 | 22.6s |  |
| 10 | `swf4opcode` | 117 | 4.1s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 22.8s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 25.4s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 21.9s |  |
| 4 | `registerclass_test3` | 12 | 20 | 3.1s |  |
| 5 | `soft_reference_test1` | 3 | 4 | 22.8s |  |

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
