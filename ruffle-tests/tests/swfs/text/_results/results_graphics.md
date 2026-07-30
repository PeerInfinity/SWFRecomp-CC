# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 01:47 UTC

**Git SHA**: `34171042fc`

**Run Duration**: 3m 31s

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
| 1 | `auto_size/height` | 1 | 26.6s |  |
| 2 | `auto_size/return` | 12 | 26.1s |  |
| 3 | `auto_size/width` | 6 | 26.7s |  |
| 4 | `br_at_start` | 0 | 2.9s |  |
| 5 | `style_changes_in_html` | 0 | 21.7s |  |
| 6 | `text_caret_placement_align` | 248 | 22.6s |  |
| 7 | `text_caret_placement_leading` | 244 | 27.9s |  |
| 8 | `text_caret_placement_scroll` | 108 | 27.2s |  |
| 9 | `text_caret_placement_translated_bounds` | 140 | 20.0s |  |

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
