# Ruffle Test Results (Filtered)

**Date**: 2026-08-06 23:55 UTC

**Git SHA**: `fb36ba1100`

**Run Duration**: 3m 41s

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
| 1 | `auto_size/height` | 1 | 29.7s |  |
| 2 | `auto_size/return` | 12 | 28.9s |  |
| 3 | `auto_size/width` | 6 | 26.6s |  |
| 4 | `br_at_start` | 0 | 2.7s |  |
| 5 | `html_entity_parsing` | 213 | 7.3s |  |
| 6 | `style_changes_in_html` | 0 | 20.7s |  |
| 7 | `text_caret_placement_align` | 248 | 23.4s |  |
| 8 | `text_caret_placement_leading` | 244 | 28.3s |  |
| 9 | `text_caret_placement_scroll` | 108 | 27.7s |  |
| 10 | `text_caret_placement_translated_bounds` | 140 | 22.5s |  |

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
