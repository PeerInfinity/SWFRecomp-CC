# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-17 03:35 UTC

**Git SHA**: `5776106233`

**Run Duration**: 1m 56s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **41** (87.2%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **42** (89.4%) |
| Failing | 5 |
| Total expected lines | 491 |
| Matching lines | 472 (96.1%) |
| Mismatched lines | 19 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**41 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.8s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.7s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 4 | `callee` | 2 | 0.6s |  |
| 5 | `depth` | 6 | 0.8s |  |
| 6 | `doactionorder/symbolclass` | 4 | 0.9s |  |
| 7 | `duplicateMovieClip/name-coercion` | 3 | 0.6s |  |
| 8 | `externalinterface` | 4 | 0.8s |  |
| 9 | `filters` | 149 | 1.1s |  |
| 10 | `haxe/flocons1` | 2 | 0.7s |  |
| 11 | `haxe/flocons2` | 3 | 0.8s |  |
| 12 | `label` | 4 | 16.4s |  |
| 13 | `levels` | 9 | 0.8s |  |
| 14 | `loadevent` | 9 | 0.8s |  |
| 15 | `loadvariables/loadvariables` | 7 | 0.6s |  |
| 16 | `loadvariables/loadvars` | 2 | 0.7s |  |
| 17 | `lookup` | 3 | 0.7s |  |
| 18 | `mouse-transparency` | 1 | 0.8s |  |
| 19 | `nativeinheritance` | 6 | 0.8s |  |
| 20 | `nested-button` | 1 | 16.6s |  |
| 21 | `operations` | 13 | 0.8s |  |
| 22 | `property-paths/property-paths-6` | 6 | 0.7s |  |
| 23 | `property-paths/property-paths-7` | 7 | 0.7s |  |
| 24 | `propertycase/propertycase` | 7 | 0.7s |  |
| 25 | `propertycase/propertycase-preserving-6` | 2 | 0.6s |  |
| 26 | `propertycase/propertycase-preserving-7` | 5 | 0.2s |  |
| 27 | `rollover` | 4 | 0.8s |  |
| 28 | `scope` | 14 | 0.8s |  |
| 29 | `setinterval` | 20 | 0.8s |  |
| 30 | `settimeout` | 17 | 0.8s |  |
| 31 | `super` | 11 | 0.8s |  |
| 32 | `target` | 18 | 0.8s |  |
| 33 | `text-bind` | 0 | 16.5s |  |
| 34 | `textfield/textfield-html` | 4 | 0.7s |  |
| 35 | `textfield/textfield-text-setters` | 8 | 0.8s |  |
| 36 | `undefined/undefined-swf6` | 39 | 0.8s |  |
| 37 | `undefined/undefined-swf7` | 39 | 0.8s |  |
| 38 | `watch` | 2 | 0.7s |  |
| 39 | `xml/xmlbuild` | 1 | 0.7s |  |
| 40 | `xml/xmlload` | 4 | 0.8s |  |
| 41 | `xml/xmlstring` | 9 | 0.7s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 16.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 2 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |
| 3 | `duplicateMovieClip/duplicateMovieClip` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 2 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 3 | `duplicateMovieClip/duplicateMovieClip` | 50.0% | 2/4 | 4 | 4 |  |
| 4 | `doactionorder/doactionorder` | 42.9% | 3/7 | 7 | 7 |  |
| 5 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
