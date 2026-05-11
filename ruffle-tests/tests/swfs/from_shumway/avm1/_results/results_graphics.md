# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 00:07 UTC

**Git SHA**: `f874599629`

**Run Duration**: 1m 49s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **38** (80.9%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **39** (83.0%) |
| Failing | 8 |
| Total expected lines | 491 |
| Matching lines | 467 (95.1%) |
| Mismatched lines | 24 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**38 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.6s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.6s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 4 | `callee` | 2 | 0.7s |  |
| 5 | `depth` | 6 | 0.9s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.8s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.7s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.8s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.8s |  |
| 10 | `externalinterface` | 4 | 0.7s |  |
| 11 | `filters` | 149 | 1.0s |  |
| 12 | `haxe/flocons1` | 2 | 0.8s |  |
| 13 | `haxe/flocons2` | 3 | 0.7s |  |
| 14 | `label` | 4 | 18.4s |  |
| 15 | `loadevent` | 9 | 0.8s |  |
| 16 | `loadvariables/loadvariables` | 7 | 0.8s |  |
| 17 | `loadvariables/loadvars` | 2 | 0.8s |  |
| 18 | `lookup` | 3 | 0.8s |  |
| 19 | `nativeinheritance` | 6 | 0.8s |  |
| 20 | `operations` | 13 | 0.9s |  |
| 21 | `property-paths/property-paths-6` | 6 | 0.9s |  |
| 22 | `property-paths/property-paths-7` | 7 | 0.8s |  |
| 23 | `propertycase/propertycase` | 7 | 0.8s |  |
| 24 | `propertycase/propertycase-preserving-6` | 2 | 0.8s |  |
| 25 | `propertycase/propertycase-preserving-7` | 5 | 0.8s |  |
| 26 | `rollover` | 4 | 0.9s |  |
| 27 | `scope` | 14 | 0.7s |  |
| 28 | `super` | 11 | 0.8s |  |
| 29 | `target` | 18 | 0.7s |  |
| 30 | `text-bind` | 0 | 18.6s |  |
| 31 | `textfield/textfield-html` | 4 | 0.8s |  |
| 32 | `textfield/textfield-text-setters` | 8 | 0.7s |  |
| 33 | `undefined/undefined-swf6` | 39 | 0.6s |  |
| 34 | `undefined/undefined-swf7` | 39 | 0.8s |  |
| 35 | `watch` | 2 | 0.8s |  |
| 36 | `xml/xmlbuild` | 1 | 0.7s |  |
| 37 | `xml/xmlload` | 4 | 0.7s |  |
| 38 | `xml/xmlstring` | 9 | 0.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 18.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `moviecliploader` | 85.7% | 6 | 7 | 1 |  |
| 2 | `duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 3 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `moviecliploader` | 85.7% | 6/7 | 6 | 7 |  |
| 2 | `duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 3 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 4 | `settimeout` | 45.2% | 14/31 | 31 | 17 |  |
| 5 | `levels` | 44.4% | 4/9 | 4 | 9 |  |
| 6 | `setinterval` | 0.1% | 14/12719 | 12719 | 20 |  |
| 7 | `mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 8 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
