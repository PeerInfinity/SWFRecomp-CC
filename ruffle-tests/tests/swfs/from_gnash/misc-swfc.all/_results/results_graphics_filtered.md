# Ruffle Test Results (Filtered)

**Date**: 2026-07-29 19:07 UTC

**Git SHA**: `6cf854900e`

**Run Duration**: 6m 19s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **11** (61.1%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (83.3%) |
| Failing | 3 |
| Total expected lines | 555 |
| Matching lines | 421 (75.9%) |
| Mismatched lines | 134 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**11 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.7s |  |
| 2 | `edittext_test1` | 47 | 22.4s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 22.2s |  |
| 4 | `hello` | 4 | 20.7s |  |
| 5 | `mouse_drag_test` | 12 | 16.7s |  |
| 6 | `movieclip_destruction_test2` | 56 | 21.8s |  |
| 7 | `opcode_guard_test2` | 24 | 21.8s |  |
| 8 | `soft_reference_test1` | 45 | 21.7s |  |
| 9 | `stackscope` | 11 | 21.5s |  |
| 10 | `submoviegetvar` | 4 | 21.5s |  |
| 11 | `swf4opcode` | 117 | 22.9s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 24.0s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 22.9s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 21.8s |  |
| 4 | `registerclass_test3` | 12 | 20 | 21.7s |  |

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
