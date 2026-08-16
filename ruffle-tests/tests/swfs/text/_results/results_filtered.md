# Ruffle Test Results (Filtered)

**Date**: 2026-08-16 08:44 UTC

**Git SHA**: `88ebde6653`

**Run Duration**: 3m 28s

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
| 1 | `auto_size/height` | 1 | 26.2s |  |
| 2 | `auto_size/return` | 12 | 25.8s |  |
| 3 | `auto_size/width` | 6 | 26.0s |  |
| 4 | `br_at_start` | 0 | 1.0s |  |
| 5 | `html_entity_parsing` | 213 | 4.7s |  |
| 6 | `style_changes_in_html` | 0 | 21.0s |  |
| 7 | `text_caret_placement_align` | 248 | 26.7s |  |
| 8 | `text_caret_placement_leading` | 244 | 27.1s |  |
| 9 | `text_caret_placement_scroll` | 108 | 27.7s |  |
| 10 | `text_caret_placement_translated_bounds` | 140 | 20.1s |  |

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
