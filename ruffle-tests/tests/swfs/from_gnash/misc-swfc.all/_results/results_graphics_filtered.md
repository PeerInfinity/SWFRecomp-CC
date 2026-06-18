# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 4m 20s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 14 |
| Passing | **8** (57.1%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **12** (85.7%) |
| Failing | 2 |
| Total expected lines | 443 |
| Matching lines | 357 (80.6%) |
| Mismatched lines | 86 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.9s |  |
| 2 | `edittext_test1` | 47 | 22.1s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 20.6s |  |
| 4 | `hello` | 4 | 21.2s |  |
| 5 | `mouse_drag_test` | 12 | 22.3s |  |
| 6 | `movieclip_destruction_test2` | 56 | 22.0s |  |
| 7 | `stackscope` | 11 | 21.8s |  |
| 8 | `swf4opcode` | 117 | 4.0s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 21.4s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 14.1s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 17.4s |  |
| 4 | `registerclass_test3` | 12 | 20 | 2.5s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `opcode_guard_test2` | 79.2% | 19/24 | 24 | 24 |  |
| 2 | `movieclip_destruction_test3` | 27.8% | 5/18 | 16 | 18 |  |
