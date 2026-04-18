# Ruffle Test Results (Filtered)

**Date**: 2026-04-18 18:58 UTC

**Git SHA**: `924dce10a2`

**Run Duration**: 3m 39s

**Filtered**: 0 tests ignored out of 16 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **2** (12.5%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **5** (31.2%) |
| Failing | 11 |
| Total expected lines | 499 |
| Matching lines | 215 (43.1%) |
| Mismatched lines | 284 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 90.9% |
| Runtime Error | 1 | 9.1% |

## Passing Tests

**2 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `gotoFrameLabelAsFunction` | 6 | 15.7s |  |
| 2 | `hello` | 4 | 16.0s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 14 | 14 | 15.8s |  |
| 2 | `movieclip_destruction_test1` | 52 | 52 | 15.6s |  |
| 3 | `registerclass_test3` | 20 | 20 | 15.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `edittext_test1` | 76.6% | 36 | 47 | 11 |  |
| 2 | `stackscope` | 72.7% | 8 | 11 | 3 |  |
| 3 | `movieclip_destruction_test2` | 66.1% | 37 | 56 | 19 |  |
| 4 | `swf4opcode` | 63.2% | 74 | 117 | 43 |  |
| 5 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

**1 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `opcode_guard_test2` | exit code -6 | 13.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `edittext_test1` | 76.6% | 36/47 | 47 | 47 |  |
| 2 | `stackscope` | 72.7% | 8/11 | 11 | 11 |  |
| 3 | `movieclip_destruction_test2` | 66.1% | 37/56 | 56 | 56 |  |
| 4 | `swf4opcode` | 63.2% | 74/117 | 117 | 117 |  |
| 5 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 6 | `sound` | 41.7% | 5/12 | 12 | 7 |  |
| 7 | `soft_reference_test1` | 31.1% | 14/45 | 42 | 45 |  |
| 8 | `button_test1` | 25.8% | 8/31 | 20 | 31 |  |
| 9 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 10 | `submoviegetvar` | 0.0% | 0/4 | 4 | 4 |  |
