# Ruffle Test Results (Filtered)

**Date**: 2026-11-21 17:00 UTC

**Git SHA**: `08709f6584`

**Run Duration**: 1m 20s

**Filtered**: 0 tests ignored out of 8 available

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
| 1 | `request_matching_profiles` | 190 | 6.0s |  |
| 2 | `request_profiles` | 16 | 5.6s |  |
| 3 | `sampler_odd_size` | 1 | 11.0s |  |
| 4 | `scissor_rectangle` | 0 | 7.7s |  |
| 5 | `scissor_rectangle_invalid` | 1 | 12.2s |  |
| 6 | `unbound_texture` | 0 | 6.6s |  |
| 7 | `unbound_texture_multiple` | 0 | 8.5s |  |

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
