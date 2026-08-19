# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-19 16:36 UTC

**Git SHA**: `a946ee1838`

**Run Duration**: 3m 39s

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
| 1 | `auto_size/height` | 1 | 31.3s |  |
| 2 | `auto_size/return` | 12 | 31.4s |  |
| 3 | `auto_size/width` | 6 | 24.1s |  |
| 4 | `br_at_start` | 0 | 2.8s |  |
| 5 | `html_entity_parsing` | 213 | 6.5s |  |
| 6 | `style_changes_in_html` | 0 | 17.6s |  |
| 7 | `text_caret_placement_align` | 248 | 29.6s |  |
| 8 | `text_caret_placement_leading` | 244 | 29.3s |  |
| 9 | `text_caret_placement_scroll` | 108 | 20.9s |  |
| 10 | `text_caret_placement_translated_bounds` | 140 | 22.7s |  |

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
