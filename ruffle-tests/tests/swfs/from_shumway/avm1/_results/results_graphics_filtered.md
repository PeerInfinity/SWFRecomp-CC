# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 00:46 UTC

**Git SHA**: `f1b087ec6a`

**Run Duration**: 0m 36s

**Filtered**: 2 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **41** (91.1%) |
| Failing | 4 |
| Total expected lines | 480 |
| Matching lines | 473 (98.5%) |
| Mismatched lines | 7 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**41 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.7s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.7s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 4 | `callee` | 2 | 0.7s |  |
| 5 | `depth` | 6 | 0.7s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.6s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.8s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.6s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.6s |  |
| 10 | `externalinterface` | 4 | 0.7s |  |
| 11 | `filters` | 149 | 0.8s |  |
| 12 | `haxe/flocons1` | 2 | 0.7s |  |
| 13 | `haxe/flocons2` | 3 | 0.6s |  |
| 14 | `label` | 4 | 0.8s |  |
| 15 | `levels` | 9 | 0.8s |  |
| 16 | `loadevent` | 9 | 0.7s |  |
| 17 | `loadvariables/loadvariables` | 7 | 0.8s |  |
| 18 | `loadvariables/loadvars` | 2 | 0.7s |  |
| 19 | `lookup` | 3 | 0.7s |  |
| 20 | `nativeinheritance` | 6 | 0.7s |  |
| 21 | `operations` | 13 | 0.7s |  |
| 22 | `property-paths/property-paths-6` | 6 | 0.7s |  |
| 23 | `property-paths/property-paths-7` | 7 | 0.7s |  |
| 24 | `propertycase/propertycase` | 7 | 0.6s |  |
| 25 | `propertycase/propertycase-preserving-6` | 2 | 0.6s |  |
| 26 | `propertycase/propertycase-preserving-7` | 5 | 0.6s |  |
| 27 | `rollover` | 4 | 0.8s |  |
| 28 | `scope` | 14 | 0.7s |  |
| 29 | `setinterval` | 20 | 1.0s |  |
| 30 | `settimeout` | 17 | 0.9s |  |
| 31 | `super` | 11 | 0.7s |  |
| 32 | `target` | 18 | 0.7s |  |
| 33 | `text-bind` | 0 | 0.7s |  |
| 34 | `textfield/textfield-html` | 4 | 0.7s |  |
| 35 | `textfield/textfield-text-setters` | 8 | 0.6s |  |
| 36 | `undefined/undefined-swf6` | 39 | 0.7s |  |
| 37 | `undefined/undefined-swf7` | 39 | 0.8s |  |
| 38 | `watch` | 2 | 0.6s |  |
| 39 | `xml/xmlbuild` | 1 | 0.5s |  |
| 40 | `xml/xmlload` | 4 | 0.7s |  |
| 41 | `xml/xmlstring` | 9 | 0.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 2 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 2 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 3 | `mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 4 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
