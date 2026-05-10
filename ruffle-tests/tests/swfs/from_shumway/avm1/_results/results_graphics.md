# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-10 18:18 UTC

**Git SHA**: `ebaa7506c1`

**Run Duration**: 2m 12s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **37** (78.7%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **38** (80.9%) |
| Failing | 9 |
| Total expected lines | 491 |
| Matching lines | 464 (94.5%) |
| Mismatched lines | 27 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**37 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.9s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.6s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 1.7s |  |
| 4 | `callee` | 2 | 1.6s |  |
| 5 | `depth` | 6 | 1.8s |  |
| 6 | `doactionorder/doactionorder` | 7 | 1.6s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.4s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 1.6s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.9s |  |
| 10 | `externalinterface` | 4 | 1.6s |  |
| 11 | `filters` | 149 | 2.5s |  |
| 12 | `haxe/flocons1` | 2 | 1.6s |  |
| 13 | `haxe/flocons2` | 3 | 1.5s |  |
| 14 | `label` | 4 | 19.7s |  |
| 15 | `loadevent` | 9 | 1.9s |  |
| 16 | `loadvariables/loadvariables` | 7 | 1.8s |  |
| 17 | `loadvariables/loadvars` | 2 | 1.7s |  |
| 18 | `lookup` | 3 | 1.7s |  |
| 19 | `nativeinheritance` | 6 | 1.6s |  |
| 20 | `operations` | 13 | 2.0s |  |
| 21 | `property-paths/property-paths-6` | 6 | 1.6s |  |
| 22 | `property-paths/property-paths-7` | 7 | 2.1s |  |
| 23 | `propertycase/propertycase` | 7 | 1.6s |  |
| 24 | `propertycase/propertycase-preserving-6` | 2 | 1.9s |  |
| 25 | `propertycase/propertycase-preserving-7` | 5 | 0.8s |  |
| 26 | `scope` | 14 | 1.6s |  |
| 27 | `super` | 11 | 0.9s |  |
| 28 | `target` | 18 | 0.7s |  |
| 29 | `text-bind` | 0 | 20.6s |  |
| 30 | `textfield/textfield-html` | 4 | 1.8s |  |
| 31 | `textfield/textfield-text-setters` | 8 | 1.7s |  |
| 32 | `undefined/undefined-swf6` | 39 | 1.7s |  |
| 33 | `undefined/undefined-swf7` | 39 | 1.6s |  |
| 34 | `watch` | 2 | 1.6s |  |
| 35 | `xml/xmlbuild` | 1 | 1.5s |  |
| 36 | `xml/xmlload` | 4 | 1.4s |  |
| 37 | `xml/xmlstring` | 9 | 1.5s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 19.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `moviecliploader` | 85.7% | 6 | 7 | 1 |  |
| 2 | `settimeout` | 82.4% | 14 | 17 | 3 |  |
| 3 | `setinterval` | 70.0% | 14 | 20 | 6 |  |
| 4 | `duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 5 | `duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `moviecliploader` | 85.7% | 6/7 | 6 | 7 |  |
| 2 | `settimeout` | 82.4% | 14/17 | 14 | 17 |  |
| 3 | `setinterval` | 70.0% | 14/20 | 14 | 20 |  |
| 4 | `duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 5 | `duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 6 | `levels` | 44.4% | 4/9 | 4 | 9 |  |
| 7 | `rollover` | 25.0% | 1/4 | 3 | 4 |  |
| 8 | `mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 9 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
