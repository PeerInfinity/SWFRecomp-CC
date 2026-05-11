# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 21:26 UTC

**Git SHA**: `6beabb40c1`

**Run Duration**: 0m 14s

**Filtered**: 1 tests ignored out of 16 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 15 |
| Passing | **8** (53.3%) |
| Ruffle-matched | 6 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **14** (93.3%) |
| Failing | 1 |
| Total expected lines | 492 |
| Matching lines | 381 (77.4%) |
| Mismatched lines | 111 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 0.8s |  |
| 2 | `edittext_test1` | 47 | 0.9s |  |
| 3 | `gotoFrameLabelAsFunction` | 6 | 0.7s |  |
| 4 | `hello` | 4 | 0.7s |  |
| 5 | `mouse_drag_test` | 12 | 0.7s |  |
| 6 | `movieclip_destruction_test2` | 56 | 0.7s |  |
| 7 | `stackscope` | 11 | 0.8s |  |
| 8 | `submoviegetvar` | 4 | 0.7s |  |

## Ruffle-Matched Tests

**6 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 12 | 14 | 0.9s |  |
| 2 | `movieclip_destruction_test1` | 43 | 52 | 0.9s |  |
| 3 | `opcode_guard_test2` | 5 | 5 | 0.8s |  |
| 4 | `registerclass_test3` | 12 | 20 | 0.9s |  |
| 5 | `soft_reference_test1` | 3 | 4 | 0.8s |  |
| 6 | `swf4opcode` | 4 | 13 | 0.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `movieclip_destruction_test4` | 20.0% | 8/40 | 24 | 40 |  |
