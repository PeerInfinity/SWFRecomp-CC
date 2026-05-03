# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-03 00:05 UTC

**Git SHA**: `345f32d109`

**Run Duration**: 0m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **7** (43.8%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **11** (68.8%) |
| Failing | 5 |
| Total expected lines | 499 |
| Matching lines | 339 (67.9%) |
| Mismatched lines | 160 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 0.2s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 0.1s |  |
| 3 | `hello` | 4 | 0.1s |  |
| 4 | `mouse_drag_test` | 12 | 0.2s |  |
| 5 | `movieclip_destruction_test2` | 56 | 0.2s |  |
| 6 | `stackscope` | 11 | 0.2s |  |
| 7 | `submoviegetvar` | 4 | 0.2s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 0.2s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 0.2s |  |
| 3 | `registerclass_test3` | 12 | 20 | 0.1s |  |
| 4 | `swf4opcode` | 4 | 13 | 0.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 2 | `button_test1` | 58.1% | 18 | 31 | 13 |  |
| 3 | `soft_reference_test1` | 51.1% | 23 | 45 | 22 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 2 | `button_test1` | 58.1% | 18/31 | 20 | 31 |  |
| 3 | `soft_reference_test1` | 51.1% | 23/45 | 45 | 45 |  |
| 4 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 5 | `opcode_guard_test2` | 7.7% | 2/26 | 26 | 24 |  |
