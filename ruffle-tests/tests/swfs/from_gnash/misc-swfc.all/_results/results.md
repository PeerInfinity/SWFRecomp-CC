# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-05 02:00 UTC

**Git SHA**: `e707c68962`

**Run Duration**: 4m 17s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **7** (43.8%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **12** (75.0%) |
| Failing | 4 |
| Total expected lines | 499 |
| Matching lines | 360 (72.1%) |
| Mismatched lines | 139 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 19.0s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 18.0s |  |
| 3 | `hello` | 4 | 17.9s |  |
| 4 | `mouse_drag_test` | 12 | 17.7s |  |
| 5 | `movieclip_destruction_test2` | 56 | 1.6s |  |
| 6 | `stackscope` | 11 | 18.1s |  |
| 7 | `submoviegetvar` | 4 | 18.4s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 19.2s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 15.6s |  |
| 3 | `registerclass_test3` | 12 | 20 | 14.5s |  |
| 4 | `soft_reference_test1` | 3 | 4 | 19.1s |  |
| 5 | `swf4opcode` | 4 | 13 | 18.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `button_test1` | 64.5% | 20 | 31 | 11 |  |
| 2 | `sound` | 58.3% | 7 | 12 | 5 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `button_test1` | 64.5% | 20/31 | 20 | 31 |  |
| 2 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 3 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 4 | `opcode_guard_test2` | 7.7% | 2/26 | 26 | 24 |  |
