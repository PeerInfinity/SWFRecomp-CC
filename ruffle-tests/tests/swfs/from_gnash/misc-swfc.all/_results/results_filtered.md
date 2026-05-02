# Ruffle Test Results (Filtered)

**Date**: 2026-05-02 19:29 UTC

**Git SHA**: `802674fd5c`

**Run Duration**: 3m 58s

**Filtered**: 0 tests ignored out of 16 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **6** (37.5%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **10** (62.5%) |
| Failing | 6 |
| Total expected lines | 499 |
| Matching lines | 333 (66.7%) |
| Mismatched lines | 166 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 17.6s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 17.7s |  |
| 3 | `hello` | 4 | 16.9s |  |
| 4 | `movieclip_destruction_test2` | 56 | 0.3s |  |
| 5 | `stackscope` | 11 | 16.9s |  |
| 6 | `submoviegetvar` | 4 | 16.7s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 16.7s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 17.4s |  |
| 3 | `registerclass_test3` | 12 | 20 | 13.4s |  |
| 4 | `swf4opcode` | 4 | 13 | 17.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 2 | `button_test1` | 58.1% | 18 | 31 | 13 |  |
| 3 | `soft_reference_test1` | 51.1% | 23 | 45 | 22 |  |
| 4 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 2 | `button_test1` | 58.1% | 18/31 | 20 | 31 |  |
| 3 | `soft_reference_test1` | 51.1% | 23/45 | 45 | 45 |  |
| 4 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 5 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 6 | `opcode_guard_test2` | 7.7% | 2/26 | 26 | 24 |  |
