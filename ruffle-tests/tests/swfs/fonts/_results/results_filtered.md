# Ruffle Test Results (Filtered)

**Date**: 2026-10-18 08:49 UTC

**Git SHA**: `f555113796`

**Run Duration**: 2m 54s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **7** (77.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (88.9%) |
| Failing | 1 |
| Total expected lines | 377 |
| Matching lines | 351 (93.1%) |
| Mismatched lines | 26 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `device_font_glyph_fallback` | 36 | 27.5s |  |
| 2 | `device_font_kerning` | 4 | 29.7s |  |
| 3 | `device_font_list` | 64 | 28.6s |  |
| 4 | `embed_matching/fallback_preferences` | 0 | 29.5s |  |
| 5 | `embed_matching/match_style` | 0 | 8.0s |  |
| 6 | `embed_matching/no_font_found` | 0 | 7.6s |  |
| 7 | `embed_name_lookup` | 242 | 13.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `device_font_no_ink` | 14 | 14 | 27.7s |  |

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
| 1 | `device_font_name_case` | 7.7% | 1/13 | 13 | 13 |  |
