# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:49 UTC

**Git SHA**: `c489b84d99`

**Run Duration**: 1m 17s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 8 |
| Passing | **7** (87.5%) |
| Failing | 1 |
| Total expected lines | 216 |
| Matching lines | 211 (97.7%) |
| Mismatched lines | 5 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `request_matching_profiles` | 190 | 5.8s |  |
| 2 | `request_profiles` | 16 | 5.8s |  |
| 3 | `sampler_odd_size` | 1 | 10.4s |  |
| 4 | `scissor_rectangle` | 0 | 11.7s |  |
| 5 | `scissor_rectangle_invalid` | 1 | 7.7s |  |
| 6 | `unbound_texture` | 0 | 7.4s |  |
| 7 | `unbound_texture_multiple` | 0 | 6.8s |  |

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
| 1 | `draw_to_bitmap_data_unconfigured` | 37.5% | 3/8 | 4 | 8 |  |
