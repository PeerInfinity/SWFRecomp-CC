# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 15:03 UTC

**Git SHA**: `2ac253d474`

**Run Duration**: 3m 44s

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
| 1 | `auto_size/height` | 1 | 28.6s |  |
| 2 | `auto_size/return` | 12 | 27.6s |  |
| 3 | `auto_size/width` | 6 | 30.0s |  |
| 4 | `br_at_start` | 0 | 2.6s |  |
| 5 | `html_entity_parsing` | 213 | 8.2s |  |
| 6 | `style_changes_in_html` | 0 | 22.1s |  |
| 7 | `text_caret_placement_align` | 248 | 29.0s |  |
| 8 | `text_caret_placement_leading` | 244 | 28.3s |  |
| 9 | `text_caret_placement_scroll` | 108 | 29.1s |  |
| 10 | `text_caret_placement_translated_bounds` | 140 | 15.7s |  |

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
