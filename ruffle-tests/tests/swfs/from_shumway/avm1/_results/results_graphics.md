# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 03:59 UTC

**Git SHA**: `be795aae22`

**Run Duration**: 1m 49s

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
| 1 | `array` | 7 | 0.9s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.9s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.9s |  |
| 4 | `callee` | 2 | 0.8s |  |
| 5 | `depth` | 6 | 1.0s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.9s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.8s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.8s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.8s |  |
| 10 | `externalinterface` | 4 | 0.8s |  |
| 11 | `filters` | 149 | 0.9s |  |
| 12 | `haxe/flocons1` | 2 | 0.8s |  |
| 13 | `haxe/flocons2` | 3 | 0.7s |  |
| 14 | `label` | 4 | 18.3s |  |
| 15 | `levels` | 9 | 0.9s |  |
| 16 | `loadevent` | 9 | 0.9s |  |
| 17 | `loadvariables/loadvariables` | 7 | 0.8s |  |
| 18 | `loadvariables/loadvars` | 2 | 0.9s |  |
| 19 | `lookup` | 3 | 0.9s |  |
| 20 | `moviecliploader` | 7 | 1.0s |  |
| 21 | `nativeinheritance` | 6 | 0.9s |  |
| 22 | `operations` | 13 | 1.0s |  |
| 23 | `property-paths/property-paths-6` | 6 | 0.9s |  |
| 24 | `property-paths/property-paths-7` | 7 | 0.7s |  |
| 25 | `propertycase/propertycase` | 7 | 0.7s |  |
| 26 | `propertycase/propertycase-preserving-6` | 2 | 0.8s |  |
| 27 | `propertycase/propertycase-preserving-7` | 5 | 0.7s |  |
| 28 | `rollover` | 4 | 1.0s |  |
| 29 | `scope` | 14 | 0.9s |  |
| 30 | `setinterval` | 20 | 0.8s |  |
| 31 | `settimeout` | 17 | 1.0s |  |
| 32 | `super` | 11 | 0.8s |  |
| 33 | `target` | 18 | 0.9s |  |
| 34 | `text-bind` | 0 | 17.9s |  |
| 35 | `textfield/textfield-html` | 4 | 0.9s |  |
| 36 | `textfield/textfield-text-setters` | 8 | 0.9s |  |
| 37 | `undefined/undefined-swf6` | 39 | 0.7s |  |
| 38 | `undefined/undefined-swf7` | 39 | 0.7s |  |
| 39 | `watch` | 2 | 0.8s |  |
| 40 | `xml/xmlbuild` | 1 | 0.8s |  |
| 41 | `xml/xmlload` | 4 | 0.8s |  |
| 42 | `xml/xmlstring` | 9 | 0.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 14.9s |  |

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
