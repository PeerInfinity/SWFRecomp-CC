# Ruffle Test Results (Filtered)

**Date**: 2026-10-17 00:59 UTC

**Git SHA**: `bdf127c35c`

**Run Duration**: 3m 6s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **6** (66.7%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **7** (77.8%) |
| Failing | 2 |
| Total expected lines | 377 |
| Matching lines | 195 (51.7%) |
| Mismatched lines | 182 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `device_font_glyph_fallback` | 36 | 29.9s |  |
| 2 | `device_font_kerning` | 4 | 30.1s |  |
| 3 | `device_font_list` | 64 | 28.9s |  |
| 4 | `embed_matching/fallback_preferences` | 0 | 30.8s |  |
| 5 | `embed_matching/match_style` | 0 | 7.9s |  |
| 6 | `embed_matching/no_font_found` | 0 | 9.9s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `device_font_no_ink` | 14 | 14 | 29.4s |  |

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
| 1 | `embed_name_lookup` | 35.5% | 86/242 | 242 | 242 |  |
| 2 | `device_font_name_case` | 7.7% | 1/13 | 13 | 13 |  |
