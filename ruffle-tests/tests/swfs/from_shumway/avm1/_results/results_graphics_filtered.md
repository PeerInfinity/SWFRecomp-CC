# Ruffle Test Results (Filtered)

**Date**: 2026-06-14 04:01 UTC

**Git SHA**: `eb85f9fc9f`

**Run Duration**: 2m 51s

**Filtered**: 3 tests ignored out of 47 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 44 |
| Passing | **43** (97.7%) |
| Failing | 1 |
| Total expected lines | 480 |
| Matching lines | 480 (100.0%) |
| Mismatched lines | 0 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**43 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 1.7s |  |
| 2 | `bitmapdata/getPixel` | 2 | 1.6s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.9s |  |
| 4 | `callee` | 2 | 1.8s |  |
| 5 | `depth` | 6 | 1.9s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.3s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.9s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 20.0s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 2.1s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 1.9s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 2.0s |  |
| 12 | `externalinterface` | 4 | 1.9s |  |
| 13 | `filters` | 149 | 2.5s |  |
| 14 | `haxe/flocons1` | 2 | 2.0s |  |
| 15 | `haxe/flocons2` | 3 | 1.8s |  |
| 16 | `label` | 4 | 22.0s |  |
| 17 | `levels` | 9 | 2.0s |  |
| 18 | `loadevent` | 9 | 2.2s |  |
| 19 | `loadvariables/loadvariables` | 7 | 1.9s |  |
| 20 | `loadvariables/loadvars` | 2 | 1.9s |  |
| 21 | `lookup` | 3 | 2.1s |  |
| 22 | `nativeinheritance` | 6 | 2.1s |  |
| 23 | `nested-button` | 1 | 2.1s |  |
| 24 | `operations` | 13 | 2.0s |  |
| 25 | `property-paths/property-paths-6` | 6 | 1.9s |  |
| 26 | `property-paths/property-paths-7` | 7 | 1.8s |  |
| 27 | `propertycase/propertycase` | 7 | 1.8s |  |
| 28 | `propertycase/propertycase-preserving-6` | 2 | 1.6s |  |
| 29 | `propertycase/propertycase-preserving-7` | 5 | 0.8s |  |
| 30 | `rollover` | 4 | 2.2s |  |
| 31 | `scope` | 14 | 1.9s |  |
| 32 | `setinterval` | 20 | 2.1s |  |
| 33 | `settimeout` | 17 | 1.8s |  |
| 34 | `super` | 11 | 1.9s |  |
| 35 | `target` | 18 | 1.9s |  |
| 36 | `textfield/textfield-html` | 4 | 2.3s |  |
| 37 | `textfield/textfield-text-setters` | 8 | 2.2s |  |
| 38 | `undefined/undefined-swf6` | 39 | 1.8s |  |
| 39 | `undefined/undefined-swf7` | 39 | 2.0s |  |
| 40 | `watch` | 2 | 2.0s |  |
| 41 | `xml/xmlbuild` | 1 | 1.9s |  |
| 42 | `xml/xmlload` | 4 | 1.7s |  |
| 43 | `xml/xmlstring` | 9 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `mouse-transparency` | 50.0% | 1 | 2 | 1 |  |

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
| 1 | `mouse-transparency` | 50.0% | 1/2 | 2 | 1 |  |
