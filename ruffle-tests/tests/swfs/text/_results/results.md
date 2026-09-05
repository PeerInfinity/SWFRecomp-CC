# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-05 06:00 UTC

**Git SHA**: `1d87c1cfba`

**Run Duration**: 3m 19s

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
| 1 | `auto_size/height` | 1 | 26.8s |  |
| 2 | `auto_size/return` | 12 | 27.4s |  |
| 3 | `auto_size/width` | 6 | 25.7s |  |
| 4 | `br_at_start` | 0 | 1.4s |  |
| 5 | `html_entity_parsing` | 213 | 5.9s |  |
| 6 | `style_changes_in_html` | 0 | 15.0s |  |
| 7 | `text_caret_placement_align` | 248 | 26.8s |  |
| 8 | `text_caret_placement_leading` | 244 | 19.3s |  |
| 9 | `text_caret_placement_scroll` | 108 | 28.0s |  |
| 10 | `text_caret_placement_translated_bounds` | 140 | 20.9s |  |

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
