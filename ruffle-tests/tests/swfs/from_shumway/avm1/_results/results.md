# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-16 22:43 UTC

**Git SHA**: `a05b56ddf0`

**Run Duration**: 1m 28s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **44** (97.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **45** (100.0%) |
| Failing | 0 |
| Total expected lines | 481 |
| Matching lines | 479 (99.6%) |
| Mismatched lines | 2 |

## Passing Tests

**44 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.2s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.2s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.2s |  |
| 4 | `callee` | 2 | 1.2s |  |
| 5 | `depth` | 6 | 1.2s |  |
| 6 | `doactionorder/doactionorder` | 7 | 1.4s |  |
| 7 | `duplicateMovieClip/duplicateMovieClip` | 4 | 1.3s |  |
| 8 | `duplicateMovieClip/name-coercion` | 3 | 1.1s |  |
| 9 | `duplicateMovieClip/samedepth` | 6 | 1.2s |  |
| 10 | `externalinterface` | 4 | 1.0s |  |
| 11 | `filters` | 149 | 1.2s |  |
| 12 | `haxe/flocons1` | 2 | 0.8s |  |
| 13 | `haxe/flocons2` | 3 | 1.1s |  |
| 14 | `label` | 4 | 21.4s |  |
| 15 | `levels` | 9 | 1.4s |  |
| 16 | `loadevent` | 9 | 1.4s |  |
| 17 | `loadvariables/loadvariables` | 7 | 1.2s |  |
| 18 | `loadvariables/loadvars` | 2 | 1.2s |  |
| 19 | `lookup` | 3 | 1.3s |  |
| 20 | `mouse-transparency` | 1 | 1.4s |  |
| 21 | `moviecliploader` | 7 | 1.5s |  |
| 22 | `nativeinheritance` | 6 | 1.2s |  |
| 23 | `nested-button` | 1 | 1.2s |  |
| 24 | `operations` | 13 | 1.2s |  |
| 25 | `property-paths/property-paths-6` | 6 | 1.2s |  |
| 26 | `property-paths/property-paths-7` | 7 | 1.0s |  |
| 27 | `propertycase/propertycase` | 7 | 1.0s |  |
| 28 | `propertycase/propertycase-preserving-6` | 2 | 1.2s |  |
| 29 | `propertycase/propertycase-preserving-7` | 5 | 0.9s |  |
| 30 | `rollover` | 4 | 1.3s |  |
| 31 | `scope` | 14 | 1.2s |  |
| 32 | `setinterval` | 20 | 1.0s |  |
| 33 | `settimeout` | 17 | 1.1s |  |
| 34 | `super` | 11 | 1.2s |  |
| 35 | `target` | 18 | 1.3s |  |
| 36 | `text-bind` | 0 | 19.7s |  |
| 37 | `textfield/textfield-html` | 4 | 0.9s |  |
| 38 | `textfield/textfield-text-setters` | 8 | 1.0s |  |
| 39 | `undefined/undefined-swf6` | 39 | 0.8s |  |
| 40 | `undefined/undefined-swf7` | 39 | 0.2s |  |
| 41 | `watch` | 2 | 1.1s |  |
| 42 | `xml/xmlbuild` | 1 | 1.1s |  |
| 43 | `xml/xmlload` | 4 | 0.2s |  |
| 44 | `xml/xmlstring` | 9 | 0.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 1.2s |  |

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
