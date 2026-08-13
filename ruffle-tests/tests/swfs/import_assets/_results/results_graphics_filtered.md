# Ruffle Test Results (Filtered)

**Date**: 2026-08-13 22:38 UTC

**Git SHA**: `3db858cbc1`

**Run Duration**: 0m 45s

**Filtered**: 0 tests ignored out of 3 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 3 |
| Passing | **2** (66.7%) |
| Failing | 1 |
| Total expected lines | 14 |
| Matching lines | 8 (57.1%) |
| Mismatched lines | 6 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**2 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `avm1_non_swf_import` | 6 | 21.2s |  |
| 2 | `empty_url` | 2 | 21.2s |  |

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
| 1 | `avm1_imports_avm1` | 0.0% | 0/7 | 7 | 6 |  |
