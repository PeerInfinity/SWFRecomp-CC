# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 18:24 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 1m 38s

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
| 1 | `request_matching_profiles` | 190 | 12.1s |  |
| 2 | `request_profiles` | 16 | 9.2s |  |
| 3 | `sampler_odd_size` | 1 | 10.5s |  |
| 4 | `scissor_rectangle` | 0 | 12.5s |  |
| 5 | `scissor_rectangle_invalid` | 1 | 9.0s |  |
| 6 | `unbound_texture` | 0 | 8.9s |  |
| 7 | `unbound_texture_multiple` | 0 | 12.6s |  |

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
