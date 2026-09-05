# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-05 03:18 UTC

**Git SHA**: `cdafe1be9c`

**Run Duration**: 2m 38s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 7 |
| Passing | **6** (85.7%) |
| Failing | 1 |
| Total expected lines | 346 |
| Matching lines | 190 (54.9%) |
| Mismatched lines | 156 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `device_font_glyph_fallback` | 36 | 29.2s |  |
| 2 | `device_font_kerning` | 4 | 28.0s |  |
| 3 | `device_font_list` | 64 | 29.1s |  |
| 4 | `embed_matching/fallback_preferences` | 0 | 31.1s |  |
| 5 | `embed_matching/match_style` | 0 | 9.4s |  |
| 6 | `embed_matching/no_font_found` | 0 | 9.1s |  |

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
| 1 | `embed_name_lookup` | 35.5% | 86/242 | 242 | 242 |  |
