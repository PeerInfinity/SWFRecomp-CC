# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-13 23:50 UTC

**Git SHA**: `828b69b82d`

**Run Duration**: 2m 48s

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
| 1 | `array` | 7 | 2.0s |  |
| 2 | `bitmapdata/getPixel` | 2 | 1.9s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.8s |  |
| 4 | `callee` | 2 | 1.8s |  |
| 5 | `depth` | 6 | 1.9s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.3s |  |
| 7 | `doactionorder/symbolclass` | 4 | 2.0s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 20.9s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 1.9s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 1.8s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 1.6s |  |
| 12 | `externalinterface` | 4 | 1.5s |  |
| 13 | `filters` | 149 | 2.4s |  |
| 14 | `haxe/flocons1` | 2 | 1.8s |  |
| 15 | `haxe/flocons2` | 3 | 1.5s |  |
| 16 | `label` | 4 | 21.3s |  |
| 17 | `levels` | 9 | 2.0s |  |
| 18 | `loadevent` | 9 | 2.3s |  |
| 19 | `loadvariables/loadvariables` | 7 | 2.2s |  |
| 20 | `loadvariables/loadvars` | 2 | 2.0s |  |
| 21 | `lookup` | 3 | 2.1s |  |
| 22 | `mouse-transparency` | 1 | 2.2s |  |
| 23 | `moviecliploader` | 7 | 2.1s |  |
| 24 | `nativeinheritance` | 6 | 1.9s |  |
| 25 | `nested-button` | 1 | 1.9s |  |
| 26 | `operations` | 13 | 1.9s |  |
| 27 | `property-paths/property-paths-6` | 6 | 1.9s |  |
| 28 | `property-paths/property-paths-7` | 7 | 1.9s |  |
| 29 | `propertycase/propertycase` | 7 | 1.9s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 1.8s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 0.9s |  |
| 32 | `rollover` | 4 | 1.8s |  |
| 33 | `scope` | 14 | 1.6s |  |
| 34 | `setinterval` | 20 | 2.0s |  |
| 35 | `settimeout` | 17 | 1.8s |  |
| 36 | `super` | 11 | 1.9s |  |
| 37 | `target` | 18 | 1.6s |  |
| 38 | `text-bind` | 0 | 21.6s |  |
| 39 | `textfield/textfield-html` | 4 | 2.3s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 1.4s |  |
| 41 | `undefined/undefined-swf6` | 39 | 2.0s |  |
| 42 | `undefined/undefined-swf7` | 39 | 2.1s |  |
| 43 | `watch` | 2 | 2.0s |  |
| 44 | `xml/xmlbuild` | 1 | 1.7s |  |
| 45 | `xml/xmlload` | 4 | 2.3s |  |
| 46 | `xml/xmlstring` | 9 | 1.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 20.0s |  |

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
