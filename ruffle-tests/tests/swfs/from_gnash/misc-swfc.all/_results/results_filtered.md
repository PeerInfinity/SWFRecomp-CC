# Ruffle Test Results (Filtered)

**Date**: 2026-05-05 04:21 UTC

**Git SHA**: `c5994ec1ad`

**Run Duration**: 0m 4s

**Filtered**: 1 tests ignored out of 16 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 15 |
| Passing | **7** (46.7%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **12** (80.0%) |
| Failing | 3 |
| Total expected lines | 492 |
| Matching lines | 353 (71.7%) |
| Mismatched lines | 139 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `edittext_test1` | 47 | 0.1s |  |
| 2 | `gotoFrameLabelAsFunction` | 6 | 0.2s |  |
| 3 | `hello` | 4 | 0.1s |  |
| 4 | `mouse_drag_test` | 12 | 0.2s |  |
| 5 | `movieclip_destruction_test2` | 56 | 0.1s |  |
| 6 | `stackscope` | 11 | 0.2s |  |
| 7 | `submoviegetvar` | 4 | 0.1s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 0.2s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 0.2s |  |
| 3 | `registerclass_test3` | 12 | 20 | 0.2s |  |
| 4 | `soft_reference_test1` | 3 | 4 | 0.2s |  |
| 5 | `swf4opcode` | 4 | 13 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `button_test1` | 64.5% | 20 | 31 | 11 |  |

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
| 1 | `button_test1` | 64.5% | 20/31 | 20 | 31 |  |
| 2 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
| 3 | `opcode_guard_test2` | 7.7% | 2/26 | 26 | 24 |  |
