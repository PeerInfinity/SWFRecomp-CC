# Ruffle Test Results (Filtered)

**Date**: 2026-09-19 12:56 UTC

**Git SHA**: `53a188c38f`

**Run Duration**: 2m 38s

**Filtered**: 0 tests ignored out of 8 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 8 |
| Passing | **6** (75.0%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **7** (87.5%) |
| Failing | 1 |
| Total expected lines | 364 |
| Matching lines | 194 (53.3%) |
| Mismatched lines | 170 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**6 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `device_font_glyph_fallback` | 36 | 21.3s |  |
| 2 | `device_font_kerning` | 4 | 27.8s |  |
| 3 | `device_font_list` | 64 | 25.5s |  |
| 4 | `embed_matching/fallback_preferences` | 0 | 22.8s |  |
| 5 | `embed_matching/match_style` | 0 | 6.3s |  |
| 6 | `embed_matching/no_font_found` | 0 | 6.1s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `device_font_no_ink` | 14 | 14 | 26.9s |  |

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
| 1 | `embed_name_lookup` | 35.5% | 86/242 | 242 | 242 |  |
