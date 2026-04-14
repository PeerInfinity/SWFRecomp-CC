# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-14 00:48 UTC

**Git SHA**: `c3d9506ef0`

**Run Duration**: 15m 8s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **32** (68.1%) |
| Failing | 15 |
| Total expected lines | 491 |
| Matching lines | 451 (91.9%) |
| Mismatched lines | 40 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 93.3% |

## Passing Tests

**32 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 20.3s |  |
| 2 | `bitmapdata/getPixel` | 2 | 20.2s |  |
| 3 | `callee` | 2 | 18.6s |  |
| 4 | `depth` | 6 | 19.4s |  |
| 5 | `doactionorder/symbolclass` | 4 | 19.6s |  |
| 6 | `externalinterface` | 4 | 18.8s |  |
| 7 | `filters` | 149 | 19.1s |  |
| 8 | `haxe/flocons1` | 2 | 18.9s |  |
| 9 | `label` | 4 | 17.6s |  |
| 10 | `levels` | 9 | 17.6s |  |
| 11 | `loadevent` | 9 | 19.8s |  |
| 12 | `loadvariables/loadvariables` | 7 | 20.0s |  |
| 13 | `lookup` | 3 | 18.7s |  |
| 14 | `mouse-transparency` | 1 | 19.2s |  |
| 15 | `nativeinheritance` | 6 | 20.4s |  |
| 16 | `nested-button` | 1 | 20.7s |  |
| 17 | `operations` | 13 | 19.0s |  |
| 18 | `property-paths/property-paths-7` | 7 | 19.2s |  |
| 19 | `propertycase/propertycase` | 7 | 19.1s |  |
| 20 | `propertycase/propertycase-preserving-7` | 5 | 18.2s |  |
| 21 | `rollover` | 4 | 19.6s |  |
| 22 | `scope` | 14 | 20.2s |  |
| 23 | `setinterval` | 20 | 20.0s |  |
| 24 | `settimeout` | 17 | 18.8s |  |
| 25 | `super` | 11 | 19.0s |  |
| 26 | `target` | 18 | 19.3s |  |
| 27 | `text-bind` | 0 | 19.7s |  |
| 28 | `undefined/undefined-swf6` | 39 | 19.8s |  |
| 29 | `undefined/undefined-swf7` | 39 | 19.3s |  |
| 30 | `watch` | 2 | 18.8s |  |
| 31 | `xml/xmlbuild` | 1 | 21.0s |  |
| 32 | `xml/xmlstring` | 9 | 19.4s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 19.1s |  |

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

**14 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 11 | `bitmapdata/loadBitmap` | 0.0% | 0/3 | 3 | 3 |  |
| 12 | `loadvariables/loadvars` | 0.0% | 0/2 | 0 | 2 |  |
| 13 | `propertycase/propertycase-preserving-6` | 0.0% | 0/4 | 4 | 2 |  |
| 14 | `xml/xmlload` | 0.0% | 0/4 | 3 | 4 |  |
