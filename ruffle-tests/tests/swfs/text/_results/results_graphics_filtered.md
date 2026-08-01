# Ruffle Test Results (Filtered)

**Date**: 2026-08-01 02:48 UTC

**Git SHA**: `73c786e3fa`

**Run Duration**: 3m 38s

**Filtered**: 0 tests ignored out of 11 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 11 |
| Passing | **9** (81.8%) |
| Failing | 2 |
| Total expected lines | 973 |
| Matching lines | 858 (88.2%) |
| Mismatched lines | 115 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**9 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `auto_size/height` | 1 | 29.1s |  |
| 2 | `auto_size/return` | 12 | 29.4s |  |
| 3 | `auto_size/width` | 6 | 27.3s |  |
| 4 | `br_at_start` | 0 | 2.6s |  |
| 5 | `style_changes_in_html` | 0 | 20.5s |  |
| 6 | `text_caret_placement_align` | 248 | 27.5s |  |
| 7 | `text_caret_placement_leading` | 244 | 28.3s |  |
| 8 | `text_caret_placement_scroll` | 108 | 21.8s |  |
| 9 | `text_caret_placement_translated_bounds` | 140 | 20.6s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `html_entity_parsing` | 45.6% | 99/217 | 217 | 213 |  |
| 2 | `links_in_scrolled_text` | 0.0% | 0/1 | 0 | 1 |  |
