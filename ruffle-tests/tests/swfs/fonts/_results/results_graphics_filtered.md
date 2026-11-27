# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 16:16 UTC

**Git SHA**: `2d40d37996`

**Run Duration**: 2m 59s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 9 |
| Passing | **8** (88.9%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **9** (100.0%) |
| Failing | 0 |
| Total expected lines | 377 |
| Matching lines | 363 (96.3%) |
| Mismatched lines | 14 |

## Passing Tests

**8 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `device_font_glyph_fallback` | 36 | 25.6s |  |
| 2 | `device_font_kerning` | 4 | 25.6s |  |
| 3 | `device_font_list` | 64 | 25.9s |  |
| 4 | `device_font_name_case` | 13 | 1.4s |  |
| 5 | `embed_matching/fallback_preferences` | 0 | 36.4s |  |
| 6 | `embed_matching/match_style` | 0 | 8.1s |  |
| 7 | `embed_matching/no_font_found` | 0 | 10.0s |  |
| 8 | `embed_name_lookup` | 242 | 20.1s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `device_font_no_ink` | 14 | 14 | 25.6s |  |

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

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
