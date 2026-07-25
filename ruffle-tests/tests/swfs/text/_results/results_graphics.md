# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-25 20:09 UTC

**Git SHA**: `9b6bbcb575`

**Run Duration**: 3m 0s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 11 |
| Passing | **5** (45.5%) |
| Failing | 6 |
| Total expected lines | 973 |
| Matching lines | 705 (72.5%) |
| Mismatched lines | 268 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**5 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `auto_size/height` | 1 | 4.5s |  |
| 2 | `auto_size/return` | 12 | 25.3s |  |
| 3 | `auto_size/width` | 6 | 24.9s |  |
| 4 | `br_at_start` | 0 | 2.1s |  |
| 5 | `style_changes_in_html` | 0 | 16.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `text_caret_placement_translated_bounds` | 95.7% | 134 | 140 | 6 |  |
| 2 | `text_caret_placement_align` | 76.2% | 189 | 248 | 59 |  |
| 3 | `text_caret_placement_leading` | 75.0% | 183 | 244 | 61 |  |
| 4 | `text_caret_placement_scroll` | 75.0% | 81 | 108 | 27 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `text_caret_placement_translated_bounds` | 95.7% | 134/140 | 140 | 140 |  |
| 2 | `text_caret_placement_align` | 76.2% | 189/248 | 248 | 248 |  |
| 3 | `text_caret_placement_leading` | 75.0% | 183/244 | 244 | 244 |  |
| 4 | `text_caret_placement_scroll` | 75.0% | 81/108 | 108 | 108 |  |
| 5 | `html_entity_parsing` | 45.6% | 99/217 | 217 | 213 |  |
| 6 | `links_in_scrolled_text` | 0.0% | 0/1 | 0 | 1 |  |
