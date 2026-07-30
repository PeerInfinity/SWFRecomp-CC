# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 03:40 UTC

**Git SHA**: `dfbbfc1afa`

**Run Duration**: 2m 1s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 6 |
| Passing | **3** (50.0%) |
| Failing | 3 |
| Total expected lines | 104 |
| Matching lines | 35 (33.7%) |
| Mismatched lines | 69 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**3 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `embed_matching/fallback_preferences` | 0 | 28.8s |  |
| 2 | `embed_matching/match_style` | 0 | 7.5s |  |
| 3 | `embed_matching/no_font_found` | 0 | 6.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `device_font_glyph_fallback` | 80.6% | 29 | 36 | 7 |  |

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
| 1 | `device_font_glyph_fallback` | 80.6% | 29/36 | 36 | 36 |  |
| 2 | `device_font_list` | 9.4% | 6/64 | 48 | 64 |  |
| 3 | `device_font_kerning` | 0.0% | 0/4 | 4 | 4 |  |
