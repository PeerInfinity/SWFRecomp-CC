# Ruffle Test Results (Filtered)

**Date**: 2026-04-30 21:28 UTC

**Git SHA**: `19cc9a8d78`

**Run Duration**: 0m 4s

**Filtered**: 0 tests ignored out of 16 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **5** (31.2%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (50.0%) |
| Failing | 8 |
| Total expected lines | 499 |
| Matching lines | 304 (60.9%) |
| Mismatched lines | 195 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**5 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 0.2s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 0.2s |  |
| 3 | `hello` | 4 | 0.1s |  |
| 4 | `stackscope` | 11 | 0.2s |  |
| 5 | `submoviegetvar` | 4 | 0.2s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 0.2s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 0.6s |  |
| 3 | `registerclass_test3` | 12 | 20 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_destruction_test2` | 92.9% | 52 | 56 | 4 |  |
| 2 | `swf4opcode` | 75.2% | 88 | 117 | 29 |  |
| 3 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 4 | `button_test1` | 58.1% | 18 | 31 | 13 |  |
| 5 | `soft_reference_test1` | 51.1% | 23 | 45 | 22 |  |
| 6 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_destruction_test2` | 92.9% | 52/56 | 56 | 56 |  |
| 2 | `swf4opcode` | 75.2% | 88/117 | 117 | 117 |  |
| 3 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 4 | `button_test1` | 58.1% | 18/31 | 20 | 31 |  |
| 5 | `soft_reference_test1` | 51.1% | 23/45 | 45 | 45 |  |
| 6 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 7 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 8 | `opcode_guard_test2` | 7.7% | 2/26 | 26 | 24 |  |
