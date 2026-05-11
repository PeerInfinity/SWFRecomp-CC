# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 04:19 UTC

**Git SHA**: `b232f7e6fa`

**Run Duration**: 1m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **42** (89.4%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **43** (91.5%) |
| Failing | 4 |
| Total expected lines | 491 |
| Matching lines | 482 (98.2%) |
| Mismatched lines | 9 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**42 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.7s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.7s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 4 | `callee` | 2 | 0.7s |  |
| 5 | `depth` | 6 | 0.8s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.6s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.6s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.8s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.8s |  |
| 10 | `externalinterface` | 4 | 0.8s |  |
| 11 | `filters` | 149 | 0.8s |  |
| 12 | `haxe/flocons1` | 2 | 0.7s |  |
| 13 | `haxe/flocons2` | 3 | 0.6s |  |
| 14 | `label` | 4 | 18.5s |  |
| 15 | `levels` | 9 | 0.7s |  |
| 16 | `loadevent` | 9 | 0.6s |  |
| 17 | `loadvariables/loadvariables` | 7 | 0.6s |  |
| 18 | `loadvariables/loadvars` | 2 | 0.8s |  |
| 19 | `lookup` | 3 | 0.8s |  |
| 20 | `moviecliploader` | 7 | 0.8s |  |
| 21 | `nativeinheritance` | 6 | 0.8s |  |
| 22 | `operations` | 13 | 0.7s |  |
| 23 | `property-paths/property-paths-6` | 6 | 0.7s |  |
| 24 | `property-paths/property-paths-7` | 7 | 0.7s |  |
| 25 | `propertycase/propertycase` | 7 | 0.7s |  |
| 26 | `propertycase/propertycase-preserving-6` | 2 | 0.7s |  |
| 27 | `propertycase/propertycase-preserving-7` | 5 | 0.7s |  |
| 28 | `rollover` | 4 | 0.9s |  |
| 29 | `scope` | 14 | 0.8s |  |
| 30 | `setinterval` | 20 | 0.7s |  |
| 31 | `settimeout` | 17 | 0.7s |  |
| 32 | `super` | 11 | 0.7s |  |
| 33 | `target` | 18 | 0.7s |  |
| 34 | `text-bind` | 0 | 17.8s |  |
| 35 | `textfield/textfield-html` | 4 | 0.7s |  |
| 36 | `textfield/textfield-text-setters` | 8 | 0.6s |  |
| 37 | `undefined/undefined-swf6` | 39 | 0.8s |  |
| 38 | `undefined/undefined-swf7` | 39 | 0.7s |  |
| 39 | `watch` | 2 | 0.7s |  |
| 40 | `xml/xmlbuild` | 1 | 0.7s |  |
| 41 | `xml/xmlload` | 4 | 0.6s |  |
| 42 | `xml/xmlstring` | 9 | 0.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 17.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 2 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 2 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 3 | `mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 4 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
