# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 12:05 UTC

**Git SHA**: `ec6bffa09f`

**Run Duration**: 2m 38s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **46** (97.9%) |
| Failing | 1 |
| Total expected lines | 491 |
| Matching lines | 489 (99.6%) |
| Mismatched lines | 2 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**46 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 1.3s |  |
| 2 | `bitmapdata/getPixel` | 2 | 1.2s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.3s |  |
| 4 | `callee` | 2 | 1.3s |  |
| 5 | `depth` | 6 | 1.0s |  |
| 6 | `doactionorder/doactionorder` | 7 | 1.3s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.1s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 1.1s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 1.4s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 1.3s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 1.4s |  |
| 12 | `externalinterface` | 4 | 1.2s |  |
| 13 | `filters` | 149 | 1.4s |  |
| 14 | `haxe/flocons1` | 2 | 0.8s |  |
| 15 | `haxe/flocons2` | 3 | 1.4s |  |
| 16 | `label` | 4 | 17.0s |  |
| 17 | `levels` | 9 | 1.1s |  |
| 18 | `loadevent` | 9 | 1.6s |  |
| 19 | `loadvariables/loadvariables` | 7 | 1.4s |  |
| 20 | `loadvariables/loadvars` | 2 | 1.4s |  |
| 21 | `lookup` | 3 | 1.5s |  |
| 22 | `mouse-transparency` | 1 | 1.4s |  |
| 23 | `moviecliploader` | 7 | 20.8s |  |
| 24 | `nativeinheritance` | 6 | 1.2s |  |
| 25 | `nested-button` | 1 | 1.1s |  |
| 26 | `operations` | 13 | 1.3s |  |
| 27 | `property-paths/property-paths-6` | 6 | 1.3s |  |
| 28 | `property-paths/property-paths-7` | 7 | 1.3s |  |
| 29 | `propertycase/propertycase` | 7 | 1.3s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 1.3s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 1.0s |  |
| 32 | `rollover` | 4 | 21.6s |  |
| 33 | `scope` | 14 | 1.4s |  |
| 34 | `setinterval` | 20 | 1.4s |  |
| 35 | `settimeout` | 17 | 1.3s |  |
| 36 | `super` | 11 | 1.1s |  |
| 37 | `target` | 18 | 1.4s |  |
| 38 | `text-bind` | 0 | 20.1s |  |
| 39 | `textfield/textfield-html` | 4 | 1.5s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 1.5s |  |
| 41 | `undefined/undefined-swf6` | 39 | 1.0s |  |
| 42 | `undefined/undefined-swf7` | 39 | 1.3s |  |
| 43 | `watch` | 2 | 1.1s |  |
| 44 | `xml/xmlbuild` | 1 | 1.3s |  |
| 45 | `xml/xmlload` | 4 | 1.5s |  |
| 46 | `xml/xmlstring` | 9 | 1.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `hitarea` | 50.0% | 2 | 4 | 2 |  |

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
| 1 | `hitarea` | 50.0% | 2/4 | 3 | 4 |  |
