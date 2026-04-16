# Ruffle Test Results (Filtered)

**Date**: 2026-04-16 17:03 UTC

**Git SHA**: `998e879af4`

**Run Duration**: 15m 14s

**Filtered**: 2 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **32** (71.1%) |
| Failing | 13 |
| Total expected lines | 480 |
| Matching lines | 448 (93.3%) |
| Mismatched lines | 32 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**32 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 15.2s |  |
| 2 | `bitmapdata/getPixel` | 2 | 15.2s |  |
| 3 | `callee` | 2 | 19.2s |  |
| 4 | `depth` | 6 | 19.3s |  |
| 5 | `doactionorder/symbolclass` | 4 | 20.6s |  |
| 6 | `externalinterface` | 4 | 18.9s |  |
| 7 | `filters` | 149 | 20.0s |  |
| 8 | `haxe/flocons1` | 2 | 20.0s |  |
| 9 | `label` | 4 | 21.4s |  |
| 10 | `levels` | 9 | 20.9s |  |
| 11 | `loadevent` | 9 | 18.8s |  |
| 12 | `loadvariables/loadvariables` | 7 | 19.0s |  |
| 13 | `lookup` | 3 | 19.5s |  |
| 14 | `mouse-transparency` | 1 | 19.2s |  |
| 15 | `nativeinheritance` | 6 | 20.9s |  |
| 16 | `nested-button` | 1 | 21.3s |  |
| 17 | `operations` | 13 | 20.4s |  |
| 18 | `property-paths/property-paths-7` | 7 | 19.3s |  |
| 19 | `propertycase/propertycase` | 7 | 19.5s |  |
| 20 | `propertycase/propertycase-preserving-7` | 5 | 19.0s |  |
| 21 | `rollover` | 4 | 19.2s |  |
| 22 | `scope` | 14 | 19.1s |  |
| 23 | `setinterval` | 20 | 19.8s |  |
| 24 | `settimeout` | 17 | 19.5s |  |
| 25 | `super` | 11 | 19.0s |  |
| 26 | `target` | 18 | 18.9s |  |
| 27 | `text-bind` | 0 | 19.1s |  |
| 28 | `undefined/undefined-swf6` | 39 | 19.7s |  |
| 29 | `undefined/undefined-swf7` | 39 | 20.4s |  |
| 30 | `watch` | 2 | 19.6s |  |
| 31 | `xml/xmlbuild` | 1 | 19.2s |  |
| 32 | `xml/xmlstring` | 9 | 19.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `property-paths/property-paths-6` | 83.3% | 5 | 6 | 1 |  |
| 2 | `textfield/textfield-html` | 75.0% | 3 | 4 | 1 |  |
| 3 | `duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 4 | `haxe/flocons2` | 66.7% | 2 | 3 | 1 |  |
| 5 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |
| 6 | `textfield/textfield-text-setters` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `property-paths/property-paths-6` | 83.3% | 5/6 | 6 | 6 |  |
| 2 | `textfield/textfield-html` | 75.0% | 3/4 | 4 | 4 |  |
| 3 | `duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 4 | `haxe/flocons2` | 66.7% | 2/3 | 3 | 3 |  |
| 5 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 6 | `textfield/textfield-text-setters` | 50.0% | 4/8 | 8 | 8 |  |
| 7 | `doactionorder/doactionorder` | 42.9% | 3/7 | 7 | 7 |  |
| 8 | `duplicateMovieClip/name-coercion` | 33.3% | 1/3 | 3 | 3 |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 25.0% | 1/4 | 4 | 4 |  |
| 10 | `bitmapdata/loadBitmap` | 0.0% | 0/3 | 3 | 3 |  |
| 11 | `loadvariables/loadvars` | 0.0% | 0/2 | 0 | 2 |  |
| 12 | `propertycase/propertycase-preserving-6` | 0.0% | 0/4 | 4 | 2 |  |
| 13 | `xml/xmlload` | 0.0% | 0/4 | 3 | 4 |  |
