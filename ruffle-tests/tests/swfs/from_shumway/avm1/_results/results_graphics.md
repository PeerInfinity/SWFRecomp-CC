# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 00:01 UTC

**Git SHA**: `079c0fefec`

**Run Duration**: 3m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 46 |
| Passing | **45** (97.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **46** (100.0%) |
| Failing | 0 |
| Total expected lines | 452 |
| Matching lines | 450 (99.6%) |
| Mismatched lines | 2 |

## Passing Tests

**45 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 1.9s |  |
| 2 | `bitmapdata/getPixel` | 2 | 1.7s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.9s |  |
| 4 | `callee` | 2 | 1.8s |  |
| 5 | `depth` | 6 | 2.0s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.4s |  |
| 7 | `doactionorder/symbolclass` | 4 | 2.0s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 20.2s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 2.0s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 1.8s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 1.9s |  |
| 12 | `externalinterface` | 4 | 1.8s |  |
| 13 | `filters` | 149 | 2.4s |  |
| 14 | `haxe/flocons1` | 2 | 1.8s |  |
| 15 | `haxe/flocons2` | 3 | 1.8s |  |
| 16 | `label` | 4 | 20.6s |  |
| 17 | `levels` | 9 | 1.9s |  |
| 18 | `loadevent` | 9 | 1.0s |  |
| 19 | `loadvariables/loadvariables` | 7 | 0.9s |  |
| 20 | `loadvariables/loadvars` | 2 | 1.9s |  |
| 21 | `lookup` | 3 | 2.2s |  |
| 22 | `mouse-transparency` | 1 | 2.0s |  |
| 23 | `moviecliploader` | 7 | 19.0s |  |
| 24 | `nativeinheritance` | 6 | 1.8s |  |
| 25 | `nested-button` | 1 | 1.8s |  |
| 26 | `operations` | 13 | 2.0s |  |
| 27 | `property-paths/property-paths-6` | 6 | 1.2s |  |
| 28 | `property-paths/property-paths-7` | 7 | 1.0s |  |
| 29 | `propertycase/propertycase` | 7 | 1.0s |  |
| 30 | `propertycase/propertycase-preserving-6` | 2 | 1.1s |  |
| 31 | `propertycase/propertycase-preserving-7` | 5 | 1.0s |  |
| 32 | `rollover` | 4 | 21.1s |  |
| 33 | `scope` | 14 | 2.0s |  |
| 34 | `setinterval` | 20 | 1.7s |  |
| 35 | `settimeout` | 17 | 1.9s |  |
| 36 | `super` | 11 | 1.8s |  |
| 37 | `target` | 18 | 1.9s |  |
| 38 | `text-bind` | 0 | 22.8s |  |
| 39 | `textfield/textfield-html` | 4 | 2.2s |  |
| 40 | `textfield/textfield-text-setters` | 8 | 2.2s |  |
| 41 | `undefined/undefined-swf6` | 39 | 1.7s |  |
| 42 | `watch` | 2 | 1.6s |  |
| 43 | `xml/xmlbuild` | 1 | 1.8s |  |
| 44 | `xml/xmlload` | 4 | 1.1s |  |
| 45 | `xml/xmlstring` | 9 | 1.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 20.3s |  |

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
