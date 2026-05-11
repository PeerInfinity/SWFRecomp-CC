# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 17:30 UTC

**Git SHA**: `e0568fe7e5`

**Run Duration**: 1m 46s

**Filtered**: 2 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **43** (95.6%) |
| Failing | 2 |
| Total expected lines | 480 |
| Matching lines | 478 (99.6%) |
| Mismatched lines | 2 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**43 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.7s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.7s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.8s |  |
| 4 | `callee` | 2 | 0.8s |  |
| 5 | `depth` | 6 | 0.9s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.7s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.8s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 18.4s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.7s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.7s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 0.8s |  |
| 12 | `externalinterface` | 4 | 0.8s |  |
| 13 | `filters` | 149 | 0.8s |  |
| 14 | `haxe/flocons1` | 2 | 0.7s |  |
| 15 | `haxe/flocons2` | 3 | 0.6s |  |
| 16 | `label` | 4 | 18.7s |  |
| 17 | `levels` | 9 | 0.8s |  |
| 18 | `loadevent` | 9 | 0.7s |  |
| 19 | `loadvariables/loadvariables` | 7 | 0.6s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.8s |  |
| 21 | `lookup` | 3 | 0.8s |  |
| 22 | `nativeinheritance` | 6 | 0.8s |  |
| 23 | `operations` | 13 | 0.7s |  |
| 24 | `property-paths/property-paths-6` | 6 | 0.7s |  |
| 25 | `property-paths/property-paths-7` | 7 | 0.8s |  |
| 26 | `propertycase/propertycase` | 7 | 0.8s |  |
| 27 | `propertycase/propertycase-preserving-6` | 2 | 0.8s |  |
| 28 | `propertycase/propertycase-preserving-7` | 5 | 0.7s |  |
| 29 | `rollover` | 4 | 0.9s |  |
| 30 | `scope` | 14 | 0.7s |  |
| 31 | `setinterval` | 20 | 0.7s |  |
| 32 | `settimeout` | 17 | 0.7s |  |
| 33 | `super` | 11 | 0.6s |  |
| 34 | `target` | 18 | 0.7s |  |
| 35 | `text-bind` | 0 | 15.2s |  |
| 36 | `textfield/textfield-html` | 4 | 0.7s |  |
| 37 | `textfield/textfield-text-setters` | 8 | 0.8s |  |
| 38 | `undefined/undefined-swf6` | 39 | 0.7s |  |
| 39 | `undefined/undefined-swf7` | 39 | 0.8s |  |
| 40 | `watch` | 2 | 0.7s |  |
| 41 | `xml/xmlbuild` | 1 | 0.7s |  |
| 42 | `xml/xmlload` | 4 | 0.7s |  |
| 43 | `xml/xmlstring` | 9 | 0.8s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 2 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
