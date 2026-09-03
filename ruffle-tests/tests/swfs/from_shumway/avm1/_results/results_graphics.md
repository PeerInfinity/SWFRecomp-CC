# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 22:29 UTC

**Git SHA**: `df9560ff61`

**Run Duration**: 2m 35s

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
| 1 | `array` | 7 | 2.1s |  |
| 2 | `bitmapdata/getPixel` | 2 | 2.0s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.6s |  |
| 4 | `callee` | 2 | 1.5s |  |
| 5 | `depth` | 6 | 2.5s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.4s |  |
| 7 | `doactionorder/symbolclass` | 4 | 2.0s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 1.9s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 2.2s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 2.0s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 2.3s |  |
| 12 | `externalinterface` | 4 | 2.1s |  |
| 13 | `filters` | 149 | 2.4s |  |
| 14 | `haxe/flocons1` | 2 | 1.8s |  |
| 15 | `haxe/flocons2` | 3 | 2.0s |  |
| 16 | `label` | 4 | 21.7s |  |
| 17 | `levels` | 9 | 2.2s |  |
| 18 | `loadevent` | 9 | 2.4s |  |
| 19 | `loadvariables/loadvariables` | 7 | 2.2s |  |
| 20 | `loadvariables/loadvars` | 2 | 2.2s |  |
| 21 | `lookup` | 3 | 2.4s |  |
| 22 | `mouse-transparency` | 1 | 2.4s |  |
| 23 | `moviecliploader` | 7 | 2.5s |  |
| 24 | `nativeinheritance` | 6 | 1.8s |  |
| 25 | `nested-button` | 1 | 1.9s |  |
| 26 | `operations` | 13 | 2.2s |  |
| 27 | `property-paths/property-paths-6` | 6 | 1.9s |  |
| 28 | `property-paths/property-paths-7` | 7 | 0.6s |  |
| 29 | `propertycase/propertycase` | 7 | 0.6s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 2.0s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 1.8s |  |
| 32 | `rollover` | 4 | 2.3s |  |
| 33 | `scope` | 14 | 2.2s |  |
| 34 | `setinterval` | 20 | 2.2s |  |
| 35 | `settimeout` | 17 | 1.7s |  |
| 36 | `super` | 11 | 2.1s |  |
| 37 | `target` | 18 | 2.1s |  |
| 38 | `text-bind` | 0 | 21.9s |  |
| 39 | `textfield/textfield-html` | 4 | 2.3s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 2.2s |  |
| 41 | `undefined/undefined-swf6` | 39 | 2.1s |  |
| 42 | `undefined/undefined-swf7` | 39 | 1.5s |  |
| 43 | `watch` | 2 | 2.0s |  |
| 44 | `xml/xmlbuild` | 1 | 1.5s |  |
| 45 | `xml/xmlload` | 4 | 2.3s |  |
| 46 | `xml/xmlstring` | 9 | 1.8s |  |

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
