# Ruffle Test Results (Filtered)

**Date**: 2026-05-24 00:04 UTC

**Git SHA**: `2d64da6746`

**Run Duration**: 0m 6s

**Filtered**: 2 tests ignored out of 19 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **8** (47.1%) |
| Ruffle-matched | 7 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (88.2%) |
| Failing | 2 |
| Total expected lines | 532 |
| Matching lines | 407 (76.5%) |
| Mismatched lines | 125 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 0.2s |  |
| 2 | `edittext_test1` | 47 | 0.3s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 0.2s |  |
| 4 | `hello` | 4 | 0.2s |  |
| 5 | `mouse_drag_test` | 12 | 0.2s |  |
| 6 | `movieclip_destruction_test2` | 56 | 0.2s |  |
| 7 | `stackscope` | 11 | 0.2s |  |
| 8 | `submoviegetvar` | 4 | 0.2s |  |

## Ruffle-Matched Tests

**7 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 0.2s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 0.2s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 0.2s |  |
| 4 | `opcode_guard_test2` | 5 | 5 | 0.2s |  |
| 5 | `registerclass_test3` | 12 | 20 | 0.3s |  |
| 6 | `soft_reference_test1` | 3 | 4 | 0.2s |  |
| 7 | `swf4opcode` | 4 | 13 | 0.2s |  |

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
