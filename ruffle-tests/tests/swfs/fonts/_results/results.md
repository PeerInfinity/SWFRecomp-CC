# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 12:05 UTC

**Git SHA**: `ec6bffa09f`

**Run Duration**: 2m 12s

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
| 1 | `device_font_glyph_fallback` | 36 | 27.1s |  |
| 2 | `device_font_kerning` | 4 | 27.7s |  |
| 3 | `device_font_list` | 64 | 22.7s |  |
| 4 | `embed_matching/fallback_preferences` | 0 | 21.7s |  |
| 5 | `embed_matching/match_style` | 0 | 7.8s |  |
| 6 | `embed_matching/no_font_found` | 0 | 8.4s |  |

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
