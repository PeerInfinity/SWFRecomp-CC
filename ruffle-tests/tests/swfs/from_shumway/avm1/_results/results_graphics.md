# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 19:03 UTC

**Git SHA**: `50fcc7f8bd`

**Run Duration**: 3m 2s

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
| 1 | `array` | 7 | 2.3s |  |
| 2 | `bitmapdata/getPixel` | 2 | 2.2s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 2.0s |  |
| 4 | `callee` | 2 | 2.0s |  |
| 5 | `depth` | 6 | 1.6s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.0s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.9s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 1.9s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 2.3s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 2.2s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 1.9s |  |
| 12 | `externalinterface` | 4 | 1.6s |  |
| 13 | `filters` | 149 | 2.5s |  |
| 14 | `haxe/flocons1` | 2 | 2.0s |  |
| 15 | `haxe/flocons2` | 3 | 2.1s |  |
| 16 | `label` | 4 | 17.1s |  |
| 17 | `levels` | 9 | 1.4s |  |
| 18 | `loadevent` | 9 | 1.9s |  |
| 19 | `loadvariables/loadvariables` | 7 | 1.6s |  |
| 20 | `loadvariables/loadvars` | 2 | 1.6s |  |
| 21 | `lookup` | 3 | 1.4s |  |
| 22 | `mouse-transparency` | 1 | 1.4s |  |
| 23 | `moviecliploader` | 7 | 17.2s |  |
| 24 | `nativeinheritance` | 6 | 1.7s |  |
| 25 | `nested-button` | 1 | 2.1s |  |
| 26 | `operations` | 13 | 2.0s |  |
| 27 | `property-paths/property-paths-6` | 6 | 2.0s |  |
| 28 | `property-paths/property-paths-7` | 7 | 1.8s |  |
| 29 | `propertycase/propertycase` | 7 | 1.8s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 1.8s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 1.6s |  |
| 32 | `rollover` | 4 | 21.3s |  |
| 33 | `scope` | 14 | 2.1s |  |
| 34 | `setinterval` | 20 | 2.1s |  |
| 35 | `settimeout` | 17 | 2.1s |  |
| 36 | `super` | 11 | 2.1s |  |
| 37 | `target` | 18 | 2.3s |  |
| 38 | `text-bind` | 0 | 22.8s |  |
| 39 | `textfield/textfield-html` | 4 | 2.2s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 1.9s |  |
| 41 | `undefined/undefined-swf6` | 39 | 1.6s |  |
| 42 | `undefined/undefined-swf7` | 39 | 1.5s |  |
| 43 | `watch` | 2 | 2.0s |  |
| 44 | `xml/xmlbuild` | 1 | 2.0s |  |
| 45 | `xml/xmlload` | 4 | 0.8s |  |
| 46 | `xml/xmlstring` | 9 | 2.0s |  |

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
