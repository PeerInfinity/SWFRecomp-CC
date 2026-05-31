# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-31 03:07 UTC

**Git SHA**: `c5535fe118`

**Run Duration**: 1m 38s

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
| 3 | `bitmapdata/loadBitmap` | 3 | 0.3s |  |
| 4 | `callee` | 2 | 0.3s |  |
| 5 | `depth` | 6 | 0.4s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.3s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.3s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 18.6s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.3s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.3s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 0.3s |  |
| 12 | `externalinterface` | 4 | 0.3s |  |
| 13 | `filters` | 149 | 0.3s |  |
| 14 | `haxe/flocons1` | 2 | 0.3s |  |
| 15 | `haxe/flocons2` | 3 | 0.2s |  |
| 16 | `label` | 4 | 18.9s |  |
| 17 | `levels` | 9 | 0.3s |  |
| 18 | `loadevent` | 9 | 1.4s |  |
| 19 | `loadvariables/loadvariables` | 7 | 1.2s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.2s |  |
| 21 | `lookup` | 3 | 0.2s |  |
| 22 | `mouse-transparency` | 1 | 0.3s |  |
| 23 | `moviecliploader` | 7 | 0.3s |  |
| 24 | `nativeinheritance` | 6 | 0.3s |  |
| 25 | `nested-button` | 1 | 0.3s |  |
| 26 | `operations` | 13 | 1.1s |  |
| 27 | `property-paths/property-paths-6` | 6 | 1.0s |  |
| 28 | `property-paths/property-paths-7` | 7 | 0.3s |  |
| 29 | `propertycase/propertycase` | 7 | 0.3s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 0.3s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 0.3s |  |
| 32 | `rollover` | 4 | 0.3s |  |
| 33 | `scope` | 14 | 0.3s |  |
| 34 | `setinterval` | 20 | 0.2s |  |
| 35 | `settimeout` | 17 | 0.3s |  |
| 36 | `super` | 11 | 0.3s |  |
| 37 | `target` | 18 | 0.3s |  |
| 38 | `text-bind` | 0 | 18.8s |  |
| 39 | `textfield/textfield-html` | 4 | 0.2s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 0.3s |  |
| 41 | `undefined/undefined-swf6` | 39 | 0.3s |  |
| 42 | `undefined/undefined-swf7` | 39 | 0.9s |  |
| 43 | `watch` | 2 | 1.0s |  |
| 44 | `xml/xmlbuild` | 1 | 0.9s |  |
| 45 | `xml/xmlload` | 4 | 1.2s |  |
| 46 | `xml/xmlstring` | 9 | 1.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 18.2s |  |

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
