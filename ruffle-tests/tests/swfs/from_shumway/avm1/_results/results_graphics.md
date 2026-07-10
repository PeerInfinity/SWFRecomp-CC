# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-10 22:53 UTC

**Git SHA**: `8a8ff17c73`

**Run Duration**: 3m 10s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 45 |
| Passing | **44** (97.8%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **45** (100.0%) |
| Failing | 0 |
| Total expected lines | 472 |
| Matching lines | 470 (99.6%) |
| Mismatched lines | 2 |

## Passing Tests

**44 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.9s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.8s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.0s |  |
| 4 | `callee` | 2 | 1.8s |  |
| 5 | `depth` | 6 | 2.0s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.4s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.7s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 19.7s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 2.0s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 1.9s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 2.0s |  |
| 12 | `externalinterface` | 4 | 1.9s |  |
| 13 | `filters` | 149 | 2.6s |  |
| 14 | `haxe/flocons1` | 2 | 2.1s |  |
| 15 | `haxe/flocons2` | 3 | 1.8s |  |
| 16 | `label` | 4 | 20.6s |  |
| 17 | `levels` | 9 | 2.0s |  |
| 18 | `loadevent` | 9 | 1.0s |  |
| 19 | `loadvariables/loadvariables` | 7 | 1.0s |  |
| 20 | `loadvariables/loadvars` | 2 | 2.0s |  |
| 21 | `lookup` | 3 | 2.3s |  |
| 22 | `mouse-transparency` | 1 | 2.0s |  |
| 23 | `moviecliploader` | 7 | 20.8s |  |
| 24 | `nativeinheritance` | 6 | 1.9s |  |
| 25 | `nested-button` | 1 | 1.9s |  |
| 26 | `property-paths/property-paths-7` | 7 | 0.8s |  |
| 27 | `propertycase/propertycase` | 7 | 0.8s |  |
| 28 | `propertycase/propertycase-preserving-6` | 2 | 1.1s |  |
| 29 | `propertycase/propertycase-preserving-7` | 5 | 1.0s |  |
| 30 | `rollover` | 4 | 20.0s |  |
| 31 | `scope` | 14 | 1.9s |  |
| 32 | `setinterval` | 20 | 2.0s |  |
| 33 | `settimeout` | 17 | 1.9s |  |
| 34 | `super` | 11 | 1.7s |  |
| 35 | `target` | 18 | 2.0s |  |
| 36 | `text-bind` | 0 | 21.0s |  |
| 37 | `textfield/textfield-html` | 4 | 2.3s |  |
| 38 | `textfield/textfield-text-setters` | 8 | 1.0s |  |
| 39 | `undefined/undefined-swf6` | 39 | 1.7s |  |
| 40 | `undefined/undefined-swf7` | 39 | 1.9s |  |
| 41 | `watch` | 2 | 1.5s |  |
| 42 | `xml/xmlbuild` | 1 | 1.9s |  |
| 43 | `xml/xmlload` | 4 | 1.1s |  |
| 44 | `xml/xmlstring` | 9 | 1.0s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 20.2s |  |

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
