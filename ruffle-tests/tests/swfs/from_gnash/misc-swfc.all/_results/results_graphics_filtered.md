# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 00:22 UTC

**Git SHA**: `ed44b710b7`

**Run Duration**: 4m 19s

**Filtered**: 2 tests ignored out of 19 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 17 |
| Passing | **9** (52.9%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **14** (82.4%) |
| Failing | 3 |
| Total expected lines | 532 |
| Matching lines | 411 (77.3%) |
| Mismatched lines | 121 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**9 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.7s |  |
| 2 | `edittext_test1` | 47 | 21.9s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 2.6s |  |
| 4 | `hello` | 4 | 16.8s |  |
| 5 | `mouse_drag_test` | 12 | 2.4s |  |
| 6 | `movieclip_destruction_test2` | 56 | 0.8s |  |
| 7 | `stackscope` | 11 | 2.3s |  |
| 8 | `submoviegetvar` | 4 | 20.6s |  |
| 9 | `swf4opcode` | 117 | 3.6s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 17.3s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 21.4s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 21.4s |  |
| 4 | `registerclass_test3` | 12 | 20 | 2.8s |  |
| 5 | `soft_reference_test1` | 3 | 4 | 20.9s |  |

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
