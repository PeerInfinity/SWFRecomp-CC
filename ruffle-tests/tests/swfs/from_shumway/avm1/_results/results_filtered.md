# Ruffle Test Results (Filtered)

**Date**: 2026-04-20 02:07 UTC

**Git SHA**: `a8995c83e4`

**Run Duration**: 0m 10s

**Filtered**: 2 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **44** (97.8%) |
| Failing | 1 |
| Total expected lines | 480 |
| Matching lines | 476 (99.2%) |
| Mismatched lines | 4 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**44 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.1s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.1s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.1s |  |
| 4 | `callee` | 2 | 0.1s |  |
| 5 | `depth` | 6 | 0.3s |  |
| 6 | `doactionorder/symbolclass` | 4 | 0.2s |  |
| 7 | `duplicateMovieClip/dontremove` | 6 | 0.2s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.1s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.1s |  |
| 10 | `duplicateMovieClip/samedepth` | 6 | 0.1s |  |
| 11 | `externalinterface` | 4 | 0.1s |  |
| 12 | `filters` | 149 | 0.1s |  |
| 13 | `haxe/flocons1` | 2 | 0.1s |  |
| 14 | `haxe/flocons2` | 3 | 0.1s |  |
| 15 | `label` | 4 | 0.2s |  |
| 16 | `levels` | 9 | 0.2s |  |
| 17 | `loadevent` | 9 | 0.2s |  |
| 18 | `loadvariables/loadvariables` | 7 | 0.1s |  |
| 19 | `loadvariables/loadvars` | 2 | 0.1s |  |
| 20 | `lookup` | 3 | 0.1s |  |
| 21 | `mouse-transparency` | 1 | 0.1s |  |
| 22 | `nativeinheritance` | 6 | 0.1s |  |
| 23 | `nested-button` | 1 | 0.1s |  |
| 24 | `operations` | 13 | 0.1s |  |
| 25 | `property-paths/property-paths-6` | 6 | 0.1s |  |
| 26 | `property-paths/property-paths-7` | 7 | 0.1s |  |
| 27 | `propertycase/propertycase` | 7 | 0.1s |  |
| 28 | `propertycase/propertycase-preserving-6` | 2 | 0.1s |  |
| 29 | `propertycase/propertycase-preserving-7` | 5 | 0.1s |  |
| 30 | `rollover` | 4 | 0.1s |  |
| 31 | `scope` | 14 | 0.1s |  |
| 32 | `setinterval` | 20 | 0.1s |  |
| 33 | `settimeout` | 17 | 0.1s |  |
| 34 | `super` | 11 | 0.1s |  |
| 35 | `target` | 18 | 0.1s |  |
| 36 | `text-bind` | 0 | 0.2s |  |
| 37 | `textfield/textfield-html` | 4 | 0.1s |  |
| 38 | `textfield/textfield-text-setters` | 8 | 0.1s |  |
| 39 | `undefined/undefined-swf6` | 39 | 0.1s |  |
| 40 | `undefined/undefined-swf7` | 39 | 0.1s |  |
| 41 | `watch` | 2 | 0.1s |  |
| 42 | `xml/xmlbuild` | 1 | 0.1s |  |
| 43 | `xml/xmlload` | 4 | 0.1s |  |
| 44 | `xml/xmlstring` | 9 | 0.2s |  |

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
| 1 | `doactionorder/doactionorder` | 42.9% | 3/7 | 7 | 7 |  |
