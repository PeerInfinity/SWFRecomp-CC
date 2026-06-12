# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-12 22:01 UTC

**Git SHA**: `3de56efba1`

**Run Duration**: 0m 12s

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
| 1 | `array` | 7 | 0.2s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.2s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.2s |  |
| 4 | `callee` | 2 | 0.2s |  |
| 5 | `depth` | 6 | 0.2s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.2s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.2s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 0.2s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.2s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.2s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 0.1s |  |
| 12 | `externalinterface` | 4 | 0.1s |  |
| 13 | `filters` | 149 | 0.6s |  |
| 14 | `haxe/flocons1` | 2 | 0.5s |  |
| 15 | `haxe/flocons2` | 3 | 0.2s |  |
| 16 | `label` | 4 | 0.2s |  |
| 17 | `levels` | 9 | 0.3s |  |
| 18 | `loadevent` | 9 | 0.2s |  |
| 19 | `loadvariables/loadvariables` | 7 | 0.2s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.2s |  |
| 21 | `lookup` | 3 | 0.2s |  |
| 22 | `mouse-transparency` | 1 | 0.2s |  |
| 23 | `moviecliploader` | 7 | 0.2s |  |
| 24 | `nativeinheritance` | 6 | 0.2s |  |
| 25 | `nested-button` | 1 | 0.2s |  |
| 26 | `operations` | 13 | 0.2s |  |
| 27 | `property-paths/property-paths-6` | 6 | 0.2s |  |
| 28 | `property-paths/property-paths-7` | 7 | 0.2s |  |
| 29 | `propertycase/propertycase` | 7 | 0.2s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 0.2s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 0.2s |  |
| 32 | `rollover` | 4 | 0.2s |  |
| 33 | `scope` | 14 | 0.2s |  |
| 34 | `setinterval` | 20 | 0.2s |  |
| 35 | `settimeout` | 17 | 0.2s |  |
| 36 | `super` | 11 | 0.2s |  |
| 37 | `target` | 18 | 0.2s |  |
| 38 | `text-bind` | 0 | 0.2s |  |
| 39 | `textfield/textfield-html` | 4 | 0.2s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 0.2s |  |
| 41 | `undefined/undefined-swf6` | 39 | 0.2s |  |
| 42 | `undefined/undefined-swf7` | 39 | 0.2s |  |
| 43 | `watch` | 2 | 0.2s |  |
| 44 | `xml/xmlbuild` | 1 | 0.2s |  |
| 45 | `xml/xmlload` | 4 | 0.2s |  |
| 46 | `xml/xmlstring` | 9 | 0.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 0.2s |  |

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
