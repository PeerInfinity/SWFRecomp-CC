# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-23 19:37 UTC

**Git SHA**: `abacc3d612`

**Run Duration**: 3m 53s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **4** (25.0%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **7** (43.8%) |
| Failing | 9 |
| Total expected lines | 499 |
| Matching lines | 232 (46.5%) |
| Mismatched lines | 267 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**4 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 16.4s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 16.1s |  |
| 3 | `hello` | 4 | 16.4s |  |
| 4 | `submoviegetvar` | 4 | 17.3s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 14 | 14 | 17.4s |  |
| 2 | `movieclip_destruction_test1` | 52 | 52 | 16.0s |  |
| 3 | `registerclass_test3` | 20 | 20 | 16.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `stackscope` | 72.7% | 8 | 11 | 3 |  |
| 2 | `movieclip_destruction_test2` | 66.1% | 37 | 56 | 19 |  |
| 3 | `swf4opcode` | 63.2% | 74 | 117 | 43 |  |
| 4 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 5 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `stackscope` | 72.7% | 8/11 | 11 | 11 |  |
| 2 | `movieclip_destruction_test2` | 66.1% | 37/56 | 56 | 56 |  |
| 3 | `swf4opcode` | 63.2% | 74/117 | 117 | 117 |  |
| 4 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 5 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 6 | `soft_reference_test1` | 31.1% | 14/45 | 42 | 45 |  |
| 7 | `button_test1` | 25.8% | 8/31 | 20 | 31 |  |
| 8 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 9 | `opcode_guard_test2` | 0.0% | 0/26 | 26 | 24 |  |
