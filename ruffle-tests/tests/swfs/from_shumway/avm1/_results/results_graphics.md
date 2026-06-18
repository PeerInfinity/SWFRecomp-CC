# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 3m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 41 |
| Passing | **40** (97.6%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **41** (100.0%) |
| Failing | 0 |
| Total expected lines | 421 |
| Matching lines | 419 (99.5%) |
| Mismatched lines | 2 |

## Passing Tests

**40 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 1.9s |  |
| 2 | `bitmapdata/getPixel` | 2 | 1.8s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.3s |  |
| 4 | `callee` | 2 | 1.3s |  |
| 5 | `depth` | 6 | 2.0s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.4s |  |
| 7 | `doactionorder/symbolclass` | 4 | 2.1s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 21.0s |  |
| 9 | `duplicateMovieClip/samedepth` | 6 | 1.9s |  |
| 10 | `externalinterface` | 4 | 1.8s |  |
| 11 | `filters` | 149 | 2.5s |  |
| 12 | `haxe/flocons1` | 2 | 1.9s |  |
| 13 | `haxe/flocons2` | 3 | 1.8s |  |
| 14 | `label` | 4 | 22.3s |  |
| 15 | `levels` | 9 | 2.2s |  |
| 16 | `loadevent` | 9 | 1.6s |  |
| 17 | `loadvariables/loadvariables` | 7 | 1.4s |  |
| 18 | `loadvariables/loadvars` | 2 | 1.9s |  |
| 19 | `lookup` | 3 | 2.2s |  |
| 20 | `mouse-transparency` | 1 | 2.2s |  |
| 21 | `moviecliploader` | 7 | 21.1s |  |
| 22 | `operations` | 13 | 1.8s |  |
| 23 | `property-paths/property-paths-6` | 6 | 1.6s |  |
| 24 | `property-paths/property-paths-7` | 7 | 1.5s |  |
| 25 | `propertycase/propertycase` | 7 | 1.4s |  |
| 26 | `propertycase/propertycase-preserving-6` | 2 | 1.7s |  |
| 27 | `propertycase/propertycase-preserving-7` | 5 | 1.0s |  |
| 28 | `rollover` | 4 | 20.7s |  |
| 29 | `scope` | 14 | 2.0s |  |
| 30 | `setinterval` | 20 | 2.1s |  |
| 31 | `super` | 11 | 2.1s |  |
| 32 | `target` | 18 | 2.0s |  |
| 33 | `text-bind` | 0 | 21.1s |  |
| 34 | `textfield/textfield-html` | 4 | 1.7s |  |
| 35 | `textfield/textfield-text-setters` | 8 | 2.2s |  |
| 36 | `undefined/undefined-swf7` | 39 | 1.8s |  |
| 37 | `watch` | 2 | 1.7s |  |
| 38 | `xml/xmlbuild` | 1 | 1.9s |  |
| 39 | `xml/xmlload` | 4 | 0.8s |  |
| 40 | `xml/xmlstring` | 9 | 1.4s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 20.6s |  |

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
