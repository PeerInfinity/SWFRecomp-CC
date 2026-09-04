# Ruffle Test Results (Filtered)

**Date**: 2026-09-04 09:14 UTC

**Git SHA**: `2002bc3ece`

**Run Duration**: 3m 30s

**Filtered**: 0 tests ignored out of 11 available

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
| 1 | `auto_size/height` | 1 | 21.0s |  |
| 2 | `auto_size/return` | 12 | 26.6s |  |
| 3 | `auto_size/width` | 6 | 27.3s |  |
| 4 | `br_at_start` | 0 | 1.3s |  |
| 5 | `html_entity_parsing` | 213 | 7.3s |  |
| 6 | `style_changes_in_html` | 0 | 19.8s |  |
| 7 | `text_caret_placement_align` | 248 | 28.5s |  |
| 8 | `text_caret_placement_leading` | 244 | 27.6s |  |
| 9 | `text_caret_placement_scroll` | 108 | 27.4s |  |
| 10 | `text_caret_placement_translated_bounds` | 140 | 21.6s |  |

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
