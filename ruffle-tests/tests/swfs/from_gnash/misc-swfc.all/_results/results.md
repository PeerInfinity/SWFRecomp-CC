# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-27 00:35 UTC

**Git SHA**: `d6808409a8`

**Run Duration**: 0m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 16 |
| Passing | **5** (31.2%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (50.0%) |
| Failing | 8 |
| Total expected lines | 499 |
| Matching lines | 262 (52.5%) |
| Mismatched lines | 237 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**5 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 0.2s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 0.1s |  |
| 3 | `hello` | 4 | 0.1s |  |
| 4 | `stackscope` | 11 | 0.2s |  |
| 5 | `submoviegetvar` | 4 | 0.2s |  |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 14 | 14 | 0.2s |  |
| 2 | `movieclip_destruction_test1` | 52 | 52 | 0.2s |  |
| 3 | `registerclass_test3` | 20 | 20 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `movieclip_destruction_test2` | 92.9% | 52 | 56 | 4 |  |
| 2 | `swf4opcode` | 63.2% | 74 | 117 | 43 |  |
| 3 | `sound` | 58.3% | 7 | 12 | 5 |  |
| 4 | `button_test1` | 58.1% | 18 | 31 | 13 |  |
| 5 | `mouse_drag_test` | 50.0% | 6 | 12 | 6 |  |

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
| 2 | `swf4opcode` | 63.2% | 74/117 | 117 | 117 |  |
| 3 | `sound` | 58.3% | 7/12 | 12 | 7 |  |
| 4 | `button_test1` | 58.1% | 18/31 | 20 | 31 |  |
| 5 | `mouse_drag_test` | 50.0% | 6/12 | 12 | 12 |  |
| 6 | `soft_reference_test1` | 31.1% | 14/45 | 42 | 45 |  |
| 7 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 8 | `opcode_guard_test2` | 7.7% | 2/26 | 26 | 24 |  |
