# Ruffle Test Results (Filtered)

**Date**: 2026-05-10 18:18 UTC

**Git SHA**: `ebaa7506c1`

**Run Duration**: 3m 13s

**Filtered**: 1 tests ignored out of 16 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 15 |
| Passing | **6** (40.0%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **11** (73.3%) |
| Failing | 4 |
| Total expected lines | 492 |
| Matching lines | 326 (66.3%) |
| Mismatched lines | 166 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 19.9s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 1.8s |  |
| 3 | `hello` | 4 | 18.7s |  |
| 4 | `mouse_drag_test` | 12 | 2.3s |  |
| 5 | `stackscope` | 11 | 0.8s |  |
| 6 | `submoviegetvar` | 4 | 19.9s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 0.9s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 20.7s |  |
| 3 | `registerclass_test3` | 12 | 20 | 2.6s |  |
| 4 | `soft_reference_test1` | 3 | 4 | 20.0s |  |
| 5 | `swf4opcode` | 4 | 13 | 20.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `opcode_guard_test2` | 66.7% | 16 | 24 | 8 |  |
| 2 | `button_test1` | 64.5% | 20 | 31 | 11 |  |

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
| 1 | `opcode_guard_test2` | 66.7% | 16/24 | 24 | 24 |  |
| 2 | `button_test1` | 64.5% | 20/31 | 20 | 31 |  |
| 3 | `movieclip_destruction_test2` | 26.8% | 15/56 | 53 | 56 |  |
| 4 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
