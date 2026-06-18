# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 4m 15s

**Filtered**: 2 tests ignored out of 20 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 13 |
| Passing | **6** (46.2%) |
| Ruffle-matched | 4 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **10** (76.9%) |
| Failing | 3 |
| Total expected lines | 483 |
| Matching lines | 374 (77.4%) |
| Mismatched lines | 109 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `button_test1` | 31 | 2.8s |  |
| 2 | `edittext_test1` | 47 | 21.6s |  |
| 3 | `hello` | 4 | 21.2s |  |
| 4 | `movieclip_destruction_test2` | 56 | 21.4s |  |
| 5 | `stackscope` | 11 | 20.8s |  |
| 6 | `swf4opcode` | 117 | 3.5s |  |

## Ruffle-Matched Tests

**4 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `action_execution_order_test10` | 11 | 14 | 21.6s |  |
| 2 | `action_execution_order_test12` | 2 | 2 | 17.2s |  |
| 3 | `movieclip_destruction_test1` | 43 | 52 | 24.4s |  |
| 4 | `soft_reference_test1` | 3 | 4 | 22.9s |  |

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
