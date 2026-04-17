# Ruffle Test Results (Filtered)

**Date**: 2026-04-17 04:43 UTC

**Git SHA**: `6ddedca895`

**Run Duration**: 1m 32s

**Filtered**: 2 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **42** (93.3%) |
| Failing | 3 |
| Total expected lines | 480 |
| Matching lines | 469 (97.7%) |
| Mismatched lines | 11 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**42 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.3s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.3s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.3s |  |
| 4 | `callee` | 2 | 0.3s |  |
| 5 | `doactionorder/symbolclass` | 4 | 0.3s |  |
| 6 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.2s |  |
| 7 | `duplicateMovieClip/name-coercion` | 3 | 0.2s |  |
| 8 | `duplicateMovieClip/samedepth` | 6 | 0.3s |  |
| 9 | `externalinterface` | 4 | 0.3s |  |
| 10 | `filters` | 149 | 0.3s |  |
| 11 | `haxe/flocons1` | 2 | 0.3s |  |
| 12 | `haxe/flocons2` | 3 | 0.3s |  |
| 13 | `label` | 4 | 14.8s |  |
| 14 | `levels` | 9 | 0.3s |  |
| 15 | `loadevent` | 9 | 0.3s |  |
| 16 | `loadvariables/loadvariables` | 7 | 0.3s |  |
| 17 | `loadvariables/loadvars` | 2 | 0.3s |  |
| 18 | `lookup` | 3 | 0.3s |  |
| 19 | `mouse-transparency` | 1 | 0.3s |  |
| 20 | `nativeinheritance` | 6 | 0.3s |  |
| 21 | `nested-button` | 1 | 15.6s |  |
| 22 | `operations` | 13 | 0.3s |  |
| 23 | `property-paths/property-paths-6` | 6 | 0.3s |  |
| 24 | `property-paths/property-paths-7` | 7 | 0.3s |  |
| 25 | `propertycase/propertycase` | 7 | 0.3s |  |
| 26 | `propertycase/propertycase-preserving-6` | 2 | 0.3s |  |
| 27 | `propertycase/propertycase-preserving-7` | 5 | 0.2s |  |
| 28 | `rollover` | 4 | 0.3s |  |
| 29 | `scope` | 14 | 0.3s |  |
| 30 | `setinterval` | 20 | 0.3s |  |
| 31 | `settimeout` | 17 | 0.3s |  |
| 32 | `super` | 11 | 0.3s |  |
| 33 | `target` | 18 | 0.3s |  |
| 34 | `text-bind` | 0 | 15.1s |  |
| 35 | `textfield/textfield-html` | 4 | 0.3s |  |
| 36 | `textfield/textfield-text-setters` | 8 | 0.3s |  |
| 37 | `undefined/undefined-swf6` | 39 | 0.3s |  |
| 38 | `undefined/undefined-swf7` | 39 | 0.3s |  |
| 39 | `watch` | 2 | 0.3s |  |
| 40 | `xml/xmlbuild` | 1 | 0.3s |  |
| 41 | `xml/xmlload` | 4 | 0.3s |  |
| 42 | `xml/xmlstring` | 9 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 2 | `doactionorder/doactionorder` | 42.9% | 3/7 | 7 | 7 |  |
| 3 | `depth` | 28.6% | 2/7 | 7 | 6 |  |
