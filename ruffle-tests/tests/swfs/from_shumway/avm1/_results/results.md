# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-20 04:06 UTC

**Git SHA**: `a7c046709d`

**Run Duration**: 1m 36s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **43** (91.5%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **44** (93.6%) |
| Failing | 3 |
| Total expected lines | 491 |
| Matching lines | 477 (97.1%) |
| Mismatched lines | 14 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**43 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.3s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.3s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.3s |  |
| 4 | `callee` | 2 | 0.3s |  |
| 5 | `depth` | 6 | 0.4s |  |
| 6 | `doactionorder/symbolclass` | 4 | 0.3s |  |
| 7 | `duplicateMovieClip/dontremove` | 6 | 16.2s |  |
| 8 | `duplicateMovieClip/name-coercion` | 3 | 0.3s |  |
| 9 | `duplicateMovieClip/samedepth` | 6 | 0.3s |  |
| 10 | `externalinterface` | 4 | 0.3s |  |
| 11 | `filters` | 149 | 0.3s |  |
| 12 | `haxe/flocons1` | 2 | 0.3s |  |
| 13 | `haxe/flocons2` | 3 | 0.2s |  |
| 14 | `label` | 4 | 16.2s |  |
| 15 | `levels` | 9 | 0.3s |  |
| 16 | `loadevent` | 9 | 0.3s |  |
| 17 | `loadvariables/loadvariables` | 7 | 0.3s |  |
| 18 | `loadvariables/loadvars` | 2 | 0.3s |  |
| 19 | `lookup` | 3 | 0.3s |  |
| 20 | `mouse-transparency` | 1 | 0.3s |  |
| 21 | `nativeinheritance` | 6 | 0.3s |  |
| 22 | `nested-button` | 1 | 15.9s |  |
| 23 | `operations` | 13 | 0.3s |  |
| 24 | `property-paths/property-paths-6` | 6 | 0.3s |  |
| 25 | `property-paths/property-paths-7` | 7 | 0.3s |  |
| 26 | `propertycase/propertycase` | 7 | 0.3s |  |
| 27 | `propertycase/propertycase-preserving-6` | 2 | 0.3s |  |
| 28 | `propertycase/propertycase-preserving-7` | 5 | 0.2s |  |
| 29 | `rollover` | 4 | 0.3s |  |
| 30 | `scope` | 14 | 0.3s |  |
| 31 | `setinterval` | 20 | 0.3s |  |
| 32 | `settimeout` | 17 | 0.3s |  |
| 33 | `super` | 11 | 0.3s |  |
| 34 | `target` | 18 | 0.3s |  |
| 35 | `text-bind` | 0 | 16.8s |  |
| 36 | `textfield/textfield-html` | 4 | 0.3s |  |
| 37 | `textfield/textfield-text-setters` | 8 | 0.3s |  |
| 38 | `undefined/undefined-swf6` | 39 | 0.3s |  |
| 39 | `undefined/undefined-swf7` | 39 | 0.3s |  |
| 40 | `watch` | 2 | 0.3s |  |
| 41 | `xml/xmlbuild` | 1 | 0.3s |  |
| 42 | `xml/xmlload` | 4 | 0.3s |  |
| 43 | `xml/xmlstring` | 9 | 0.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 15.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `duplicateMovieClip/duplicateMovieClip` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `duplicateMovieClip/duplicateMovieClip` | 50.0% | 2/4 | 4 | 4 |  |
| 2 | `doactionorder/doactionorder` | 42.9% | 3/7 | 7 | 7 |  |
| 3 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
