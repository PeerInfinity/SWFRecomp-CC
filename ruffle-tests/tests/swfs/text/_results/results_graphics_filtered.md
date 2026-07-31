# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 00:57 UTC

**Git SHA**: `cebf30b89e`

**Run Duration**: 3m 35s

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
| 1 | `auto_size/height` | 1 | 25.9s |  |
| 2 | `auto_size/return` | 12 | 26.9s |  |
| 3 | `auto_size/width` | 6 | 25.1s |  |
| 4 | `br_at_start` | 0 | 2.6s |  |
| 5 | `style_changes_in_html` | 0 | 21.2s |  |
| 6 | `text_caret_placement_align` | 248 | 27.8s |  |
| 7 | `text_caret_placement_leading` | 244 | 27.4s |  |
| 8 | `text_caret_placement_scroll` | 108 | 26.9s |  |
| 9 | `text_caret_placement_translated_bounds` | 140 | 21.1s |  |

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
