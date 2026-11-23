# Ruffle Test Results (Filtered)

**Date**: 2026-11-23 23:56 UTC

**Git SHA**: `005bea42a2`

**Run Duration**: 2m 52s

**Filtered**: 0 tests ignored out of 9 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 8 |
| Passing | **7** (87.5%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **8** (100.0%) |
| Failing | 0 |
| Total expected lines | 377 |
| Matching lines | 363 (96.3%) |
| Mismatched lines | 14 |

## Passing Tests

**7 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `device_font_glyph_fallback` | 36 | 24.0s |  |
| 2 | `device_font_kerning` | 4 | 24.8s |  |
| 3 | `device_font_list` | 64 | 32.2s |  |
| 4 | `device_font_name_case` | 13 | 1.5s |  |
| 5 | `embed_matching/fallback_preferences` | 0 | 33.4s |  |
| 6 | `embed_matching/match_style` | 0 | 7.3s |  |
| 7 | `embed_name_lookup` | 242 | 24.3s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `device_font_no_ink` | 14 | 14 | 24.4s |  |

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
