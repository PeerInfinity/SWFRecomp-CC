# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-19 00:55 UTC

**Git SHA**: `c00efd4d8f`

**Run Duration**: 2m 41s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **46** (97.9%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **47** (100.0%) |
| Failing | 0 |
| Total expected lines | 491 |
| Matching lines | 489 (99.6%) |
| Mismatched lines | 2 |

## Passing Tests

**46 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.8s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.7s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 4 | `callee` | 2 | 1.1s |  |
| 5 | `depth` | 6 | 1.2s |  |
| 6 | `doactionorder/doactionorder` | 7 | 1.4s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.3s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 19.8s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 1.2s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 1.1s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 1.3s |  |
| 12 | `externalinterface` | 4 | 1.2s |  |
| 13 | `filters` | 149 | 1.5s |  |
| 14 | `haxe/flocons1` | 2 | 1.2s |  |
| 15 | `haxe/flocons2` | 3 | 0.8s |  |
| 16 | `label` | 4 | 20.8s |  |
| 17 | `levels` | 9 | 1.3s |  |
| 18 | `loadevent` | 9 | 0.9s |  |
| 19 | `loadvariables/loadvariables` | 7 | 0.7s |  |
| 20 | `loadvariables/loadvars` | 2 | 1.2s |  |
| 21 | `lookup` | 3 | 1.4s |  |
| 22 | `mouse-transparency` | 1 | 1.3s |  |
| 23 | `moviecliploader` | 7 | 20.2s |  |
| 24 | `nativeinheritance` | 6 | 1.2s |  |
| 25 | `nested-button` | 1 | 1.2s |  |
| 26 | `operations` | 13 | 1.1s |  |
| 27 | `property-paths/property-paths-6` | 6 | 0.7s |  |
| 28 | `property-paths/property-paths-7` | 7 | 0.7s |  |
| 29 | `propertycase/propertycase` | 7 | 0.6s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 0.7s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 0.4s |  |
| 32 | `rollover` | 4 | 19.5s |  |
| 33 | `scope` | 14 | 1.2s |  |
| 34 | `setinterval` | 20 | 1.2s |  |
| 35 | `settimeout` | 17 | 1.2s |  |
| 36 | `super` | 11 | 1.3s |  |
| 37 | `target` | 18 | 1.2s |  |
| 38 | `text-bind` | 0 | 20.2s |  |
| 39 | `textfield/textfield-html` | 4 | 1.3s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 1.1s |  |
| 41 | `undefined/undefined-swf6` | 39 | 1.2s |  |
| 42 | `undefined/undefined-swf7` | 39 | 1.2s |  |
| 43 | `watch` | 2 | 1.1s |  |
| 44 | `xml/xmlbuild` | 1 | 1.2s |  |
| 45 | `xml/xmlload` | 4 | 1.1s |  |
| 46 | `xml/xmlstring` | 9 | 1.0s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 12.9s |  |

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

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
