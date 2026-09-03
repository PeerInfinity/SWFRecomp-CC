# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 20:58 UTC

**Git SHA**: `92ee912f3f`

**Run Duration**: 3m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 11 |
| Passing | **10** (90.9%) |
| Failing | 1 |
| Total expected lines | 973 |
| Matching lines | 972 (99.9%) |
| Mismatched lines | 1 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**10 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `auto_size/height` | 1 | 32.0s |  |
| 2 | `auto_size/return` | 12 | 28.1s |  |
| 3 | `auto_size/width` | 6 | 22.7s |  |
| 4 | `br_at_start` | 0 | 2.5s |  |
| 5 | `html_entity_parsing` | 213 | 6.6s |  |
| 6 | `style_changes_in_html` | 0 | 21.6s |  |
| 7 | `text_caret_placement_align` | 248 | 21.6s |  |
| 8 | `text_caret_placement_leading` | 244 | 31.0s |  |
| 9 | `text_caret_placement_scroll` | 108 | 29.0s |  |
| 10 | `text_caret_placement_translated_bounds` | 140 | 21.7s |  |

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
| 1 | `links_in_scrolled_text` | 0.0% | 0/1 | 0 | 1 |  |
