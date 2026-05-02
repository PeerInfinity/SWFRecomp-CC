# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-02 04:01 UTC

**Git SHA**: `80ead5236b`

**Run Duration**: 4m 2s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **6** (37.5%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **9** (56.2%) |
| Failing | 7 |
| Total expected lines | 499 |
| Matching lines | 331 (66.3%) |
| Mismatched lines | 168 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 17.3s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 17.1s |  |
| 3 | `hello` | 4 | 16.9s |  |
| 4 | `movieclip_destruction_test2` | 56 | 0.3s |  |
| 5 | `stackscope` | 11 | 17.2s |  |
| 6 | `submoviegetvar` | 4 | 16.8s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 17.3s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 17.1s |  |
| 3 | `registerclass_test3` | 12 | 20 | 16.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `swf4opcode` | 94.9% | 111 | 117 | 6 |  |
| 2 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 3 | `button_test1` | 58.1% | 18 | 31 | 13 |  |
| 4 | `soft_reference_test1` | 51.1% | 23 | 45 | 22 |  |
| 5 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `swf4opcode` | 94.9% | 111/117 | 117 | 117 |  |
| 2 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 3 | `button_test1` | 58.1% | 18/31 | 20 | 31 |  |
| 4 | `soft_reference_test1` | 51.1% | 23/45 | 45 | 45 |  |
| 5 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 6 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 7 | `opcode_guard_test2` | 7.7% | 2/26 | 26 | 24 |  |
