# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 2m 38s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 35 |
| Passing | **34** (97.1%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **35** (100.0%) |
| Failing | 0 |
| Total expected lines | 416 |
| Matching lines | 414 (99.5%) |
| Mismatched lines | 2 |

## Passing Tests

**34 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 2.0s |  |
| 2 | `bitmapdata/getPixel` | 2 | 1.8s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.8s |  |
| 4 | `callee` | 2 | 1.5s |  |
| 5 | `depth` | 6 | 2.2s |  |
| 6 | `doactionorder/doactionorder` | 7 | 2.6s |  |
| 7 | `doactionorder/symbolclass` | 4 | 2.0s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 20.4s |  |
| 9 | `filters` | 149 | 2.4s |  |
| 10 | `haxe/flocons1` | 2 | 1.9s |  |
| 11 | `haxe/flocons2` | 3 | 1.9s |  |
| 12 | `loadevent` | 9 | 2.1s |  |
| 13 | `loadvariables/loadvariables` | 7 | 1.9s |  |
| 14 | `loadvariables/loadvars` | 2 | 2.0s |  |
| 15 | `lookup` | 3 | 2.3s |  |
| 16 | `mouse-transparency` | 1 | 1.7s |  |
| 17 | `moviecliploader` | 7 | 16.4s |  |
| 18 | `nativeinheritance` | 6 | 1.9s |  |
| 19 | `nested-button` | 1 | 1.8s |  |
| 20 | `operations` | 13 | 1.3s |  |
| 21 | `property-paths/property-paths-6` | 6 | 1.2s |  |
| 22 | `propertycase/propertycase-preserving-6` | 2 | 1.7s |  |
| 23 | `propertycase/propertycase-preserving-7` | 5 | 1.0s |  |
| 24 | `rollover` | 4 | 21.6s |  |
| 25 | `scope` | 14 | 2.1s |  |
| 26 | `setinterval` | 20 | 1.9s |  |
| 27 | `super` | 11 | 1.9s |  |
| 28 | `target` | 18 | 1.7s |  |
| 29 | `text-bind` | 0 | 21.5s |  |
| 30 | `undefined/undefined-swf6` | 39 | 1.7s |  |
| 31 | `undefined/undefined-swf7` | 39 | 2.2s |  |
| 32 | `xml/xmlbuild` | 1 | 1.8s |  |
| 33 | `xml/xmlload` | 4 | 0.8s |  |
| 34 | `xml/xmlstring` | 9 | 1.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 20.8s |  |

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
