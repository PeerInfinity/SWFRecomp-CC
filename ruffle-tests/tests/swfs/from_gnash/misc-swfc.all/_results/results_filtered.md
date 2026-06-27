# Ruffle Test Results (Filtered)

**Date**: 2026-06-27 22:59 UTC

**Git SHA**: `b7f1a17597`

**Run Duration**: 5m 6s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **10** (55.6%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **16** (88.9%) |
| Failing | 2 |
| Total expected lines | 555 |
| Matching lines | 421 (75.9%) |
| Mismatched lines | 134 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 1.8s |  |
| 2 | `edittext_test1` | 47 | 20.6s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 22.7s |  |
| 4 | `hello` | 4 | 19.8s |  |
| 5 | `mouse_drag_test` | 12 | 1.7s |  |
| 6 | `movieclip_destruction_test2` | 56 | 20.4s |  |
| 7 | `opcode_guard_test2` | 24 | 21.8s |  |
| 8 | `stackscope` | 11 | 21.2s |  |
| 9 | `submoviegetvar` | 4 | 20.9s |  |
| 10 | `swf4opcode` | 117 | 2.9s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 20.4s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 21.1s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 1.5s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 20.9s |  |
| 5 | `registerclass_test3` | 12 | 20 | 1.9s |  |
| 6 | `soft_reference_test1` | 3 | 4 | 20.4s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
| 2 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
