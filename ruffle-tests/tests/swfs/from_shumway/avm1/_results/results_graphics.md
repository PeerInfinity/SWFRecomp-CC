# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 20:29 UTC

**Git SHA**: `ed39ce53d9`

**Run Duration**: 3m 3s

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
| 1 | `array` | 7 | 2.2s |  |
| 2 | `bitmapdata/getPixel` | 2 | 2.2s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 2.2s |  |
| 4 | `callee` | 2 | 2.2s |  |
| 5 | `depth` | 6 | 2.4s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.6s |  |
| 7 | `doactionorder/symbolclass` | 4 | 2.3s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 2.2s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 1.9s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 1.8s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 1.8s |  |
| 12 | `externalinterface` | 4 | 1.7s |  |
| 13 | `filters` | 149 | 2.8s |  |
| 14 | `haxe/flocons1` | 2 | 2.2s |  |
| 15 | `haxe/flocons2` | 3 | 2.0s |  |
| 16 | `label` | 4 | 15.6s |  |
| 17 | `levels` | 9 | 1.7s |  |
| 18 | `loadevent` | 9 | 2.3s |  |
| 19 | `loadvariables/loadvariables` | 7 | 2.0s |  |
| 20 | `loadvariables/loadvars` | 2 | 2.0s |  |
| 21 | `lookup` | 3 | 2.1s |  |
| 22 | `mouse-transparency` | 1 | 2.0s |  |
| 23 | `moviecliploader` | 7 | 20.9s |  |
| 24 | `nativeinheritance` | 6 | 2.2s |  |
| 25 | `nested-button` | 1 | 2.2s |  |
| 26 | `operations` | 13 | 2.2s |  |
| 27 | `property-paths/property-paths-6` | 6 | 2.1s |  |
| 28 | `property-paths/property-paths-7` | 7 | 2.0s |  |
| 29 | `propertycase/propertycase` | 7 | 2.0s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 1.4s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 1.3s |  |
| 32 | `rollover` | 4 | 16.7s |  |
| 33 | `scope` | 14 | 1.7s |  |
| 34 | `setinterval` | 20 | 2.1s |  |
| 35 | `settimeout` | 17 | 2.0s |  |
| 36 | `super` | 11 | 1.3s |  |
| 37 | `target` | 18 | 2.4s |  |
| 38 | `text-bind` | 0 | 21.6s |  |
| 39 | `textfield/textfield-html` | 4 | 2.2s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 2.3s |  |
| 41 | `undefined/undefined-swf6` | 39 | 1.9s |  |
| 42 | `undefined/undefined-swf7` | 39 | 1.6s |  |
| 43 | `watch` | 2 | 1.8s |  |
| 44 | `xml/xmlbuild` | 1 | 0.9s |  |
| 45 | `xml/xmlload` | 4 | 2.3s |  |
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
