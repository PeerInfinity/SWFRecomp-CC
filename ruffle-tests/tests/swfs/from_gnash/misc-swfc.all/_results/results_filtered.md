# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 19:31 UTC

**Git SHA**: `0e70f553f1`

**Run Duration**: 6m 3s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 18 |
| Passing | **9** (50.0%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **15** (83.3%) |
| Failing | 3 |
| Total expected lines | 555 |
| Matching lines | 416 (75.0%) |
| Mismatched lines | 139 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**9 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 1.9s |  |
| 2 | `edittext_test1` | 47 | 20.9s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 21.0s |  |
| 4 | `hello` | 4 | 20.7s |  |
| 5 | `mouse_drag_test` | 12 | 23.2s |  |
| 6 | `movieclip_destruction_test2` | 56 | 20.7s |  |
| 7 | `stackscope` | 11 | 19.6s |  |
| 8 | `submoviegetvar` | 4 | 20.1s |  |
| 9 | `swf4opcode` | 117 | 22.7s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 19.4s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 20.9s |  |
| 3 | `gotoFrameFromInterval2` | 18 | 18 | 1.7s |  |
| 4 | `movieclip_destruction_test1` | 43 | 52 | 23.2s |  |
| 5 | `registerclass_test3` | 12 | 20 | 20.9s |  |
| 6 | `soft_reference_test1` | 3 | 4 | 20.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `opcode_guard_test2` | 79.2% | 19 | 24 | 5 |  |

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
| 1 | `opcode_guard_test2` | 79.2% | 19/24 | 24 | 24 |  |
| 2 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
| 3 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
