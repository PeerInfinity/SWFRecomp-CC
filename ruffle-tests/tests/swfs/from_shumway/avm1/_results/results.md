# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 19:23 UTC

**Git SHA**: `50fcc7f8bd`

**Run Duration**: 1m 51s

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
| 1 | `array` | 7 | 1.4s |  |
| 2 | `bitmapdata/getPixel` | 2 | 1.3s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.9s |  |
| 4 | `callee` | 2 | 0.9s |  |
| 5 | `depth` | 6 | 1.4s |  |
| 6 | `doactionorder/doactionorder` | 7 | 1.6s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.8s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 1.5s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.8s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.7s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 1.1s |  |
| 12 | `externalinterface` | 4 | 0.9s |  |
| 13 | `filters` | 149 | 1.7s |  |
| 14 | `haxe/flocons1` | 2 | 1.3s |  |
| 15 | `haxe/flocons2` | 3 | 0.8s |  |
| 16 | `label` | 4 | 21.9s |  |
| 17 | `levels` | 9 | 1.4s |  |
| 18 | `loadevent` | 9 | 1.4s |  |
| 19 | `loadvariables/loadvariables` | 7 | 1.6s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.8s |  |
| 21 | `lookup` | 3 | 1.1s |  |
| 22 | `mouse-transparency` | 1 | 1.4s |  |
| 23 | `moviecliploader` | 7 | 1.5s |  |
| 24 | `nativeinheritance` | 6 | 1.4s |  |
| 25 | `nested-button` | 1 | 1.4s |  |
| 26 | `operations` | 13 | 1.1s |  |
| 27 | `property-paths/property-paths-6` | 6 | 1.0s |  |
| 28 | `property-paths/property-paths-7` | 7 | 1.3s |  |
| 29 | `propertycase/propertycase` | 7 | 1.3s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 1.3s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 1.0s |  |
| 32 | `rollover` | 4 | 1.4s |  |
| 33 | `scope` | 14 | 1.3s |  |
| 34 | `setinterval` | 20 | 1.3s |  |
| 35 | `settimeout` | 17 | 1.3s |  |
| 36 | `super` | 11 | 1.1s |  |
| 37 | `target` | 18 | 1.4s |  |
| 38 | `text-bind` | 0 | 16.9s |  |
| 39 | `textfield/textfield-html` | 4 | 1.1s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 1.4s |  |
| 41 | `undefined/undefined-swf6` | 39 | 1.3s |  |
| 42 | `undefined/undefined-swf7` | 39 | 0.8s |  |
| 43 | `watch` | 2 | 1.3s |  |
| 44 | `xml/xmlbuild` | 1 | 1.3s |  |
| 45 | `xml/xmlload` | 4 | 1.5s |  |
| 46 | `xml/xmlstring` | 9 | 1.2s |  |

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
