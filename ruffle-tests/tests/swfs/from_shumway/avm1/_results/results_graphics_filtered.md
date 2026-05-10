# Ruffle Test Results (Filtered)

**Date**: 2026-05-10 21:29 UTC

**Git SHA**: `7767c2657e`

**Run Duration**: 0m 34s

**Filtered**: 2 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **37** (82.2%) |
| Failing | 8 |
| Total expected lines | 480 |
| Matching lines | 456 (95.0%) |
| Mismatched lines | 24 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**37 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.6s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.6s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 4 | `callee` | 2 | 0.7s |  |
| 5 | `depth` | 6 | 0.7s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.6s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.7s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.5s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.5s |  |
| 10 | `externalinterface` | 4 | 0.7s |  |
| 11 | `filters` | 149 | 0.8s |  |
| 12 | `haxe/flocons1` | 2 | 0.6s |  |
| 13 | `haxe/flocons2` | 3 | 0.7s |  |
| 14 | `label` | 4 | 0.7s |  |
| 15 | `loadevent` | 9 | 0.6s |  |
| 16 | `loadvariables/loadvariables` | 7 | 0.6s |  |
| 17 | `loadvariables/loadvars` | 2 | 0.6s |  |
| 18 | `lookup` | 3 | 0.6s |  |
| 19 | `nativeinheritance` | 6 | 0.7s |  |
| 20 | `operations` | 13 | 0.6s |  |
| 21 | `property-paths/property-paths-6` | 6 | 0.6s |  |
| 22 | `property-paths/property-paths-7` | 7 | 0.6s |  |
| 23 | `propertycase/propertycase` | 7 | 0.6s |  |
| 24 | `propertycase/propertycase-preserving-6` | 2 | 0.6s |  |
| 25 | `propertycase/propertycase-preserving-7` | 5 | 0.6s |  |
| 26 | `scope` | 14 | 0.6s |  |
| 27 | `super` | 11 | 0.7s |  |
| 28 | `target` | 18 | 0.7s |  |
| 29 | `text-bind` | 0 | 0.6s |  |
| 30 | `textfield/textfield-html` | 4 | 0.6s |  |
| 31 | `textfield/textfield-text-setters` | 8 | 0.7s |  |
| 32 | `undefined/undefined-swf6` | 39 | 0.7s |  |
| 33 | `undefined/undefined-swf7` | 39 | 0.7s |  |
| 34 | `watch` | 2 | 0.6s |  |
| 35 | `xml/xmlbuild` | 1 | 0.7s |  |
| 36 | `xml/xmlload` | 4 | 0.6s |  |
| 37 | `xml/xmlstring` | 9 | 0.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `settimeout` | 82.4% | 14 | 17 | 3 |  |
| 2 | `setinterval` | 70.0% | 14 | 20 | 6 |  |
| 3 | `duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 4 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `settimeout` | 82.4% | 14/17 | 14 | 17 |  |
| 2 | `setinterval` | 70.0% | 14/20 | 14 | 20 |  |
| 3 | `duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 4 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 5 | `levels` | 44.4% | 4/9 | 4 | 9 |  |
| 6 | `rollover` | 25.0% | 1/4 | 3 | 4 |  |
| 7 | `mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 8 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
