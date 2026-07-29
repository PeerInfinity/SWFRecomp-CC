# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-29 01:40 UTC

**Git SHA**: `767a301d2b`

**Run Duration**: 3m 17s

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
| 1 | `auto_size/height` | 1 | 23.9s |  |
| 2 | `auto_size/return` | 12 | 24.8s |  |
| 3 | `auto_size/width` | 6 | 24.2s |  |
| 4 | `br_at_start` | 0 | 1.5s |  |
| 5 | `style_changes_in_html` | 0 | 20.5s |  |
| 6 | `text_caret_placement_align` | 248 | 25.4s |  |
| 7 | `text_caret_placement_leading` | 244 | 22.9s |  |
| 8 | `text_caret_placement_scroll` | 108 | 25.0s |  |
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
