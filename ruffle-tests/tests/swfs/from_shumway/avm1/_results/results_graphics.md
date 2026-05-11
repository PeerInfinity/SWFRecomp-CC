# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 17:30 UTC

**Git SHA**: `e0568fe7e5`

**Run Duration**: 1m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **44** (93.6%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **45** (95.7%) |
| Failing | 2 |
| Total expected lines | 491 |
| Matching lines | 487 (99.2%) |
| Mismatched lines | 4 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**44 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.7s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.7s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.8s |  |
| 4 | `callee` | 2 | 0.8s |  |
| 5 | `depth` | 6 | 0.9s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.7s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.8s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 18.4s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.7s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.7s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 0.8s |  |
| 12 | `externalinterface` | 4 | 0.8s |  |
| 13 | `filters` | 149 | 0.8s |  |
| 14 | `haxe/flocons1` | 2 | 0.7s |  |
| 15 | `haxe/flocons2` | 3 | 0.6s |  |
| 16 | `label` | 4 | 18.7s |  |
| 17 | `levels` | 9 | 0.8s |  |
| 18 | `loadevent` | 9 | 0.7s |  |
| 19 | `loadvariables/loadvariables` | 7 | 0.6s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.8s |  |
| 21 | `lookup` | 3 | 0.8s |  |
| 22 | `moviecliploader` | 7 | 0.8s |  |
| 23 | `nativeinheritance` | 6 | 0.8s |  |
| 24 | `operations` | 13 | 0.7s |  |
| 25 | `property-paths/property-paths-6` | 6 | 0.7s |  |
| 26 | `property-paths/property-paths-7` | 7 | 0.8s |  |
| 27 | `propertycase/propertycase` | 7 | 0.8s |  |
| 28 | `propertycase/propertycase-preserving-6` | 2 | 0.8s |  |
| 29 | `propertycase/propertycase-preserving-7` | 5 | 0.7s |  |
| 30 | `rollover` | 4 | 0.9s |  |
| 31 | `scope` | 14 | 0.7s |  |
| 32 | `setinterval` | 20 | 0.7s |  |
| 33 | `settimeout` | 17 | 0.7s |  |
| 34 | `super` | 11 | 0.6s |  |
| 35 | `target` | 18 | 0.7s |  |
| 36 | `text-bind` | 0 | 15.2s |  |
| 37 | `textfield/textfield-html` | 4 | 0.7s |  |
| 38 | `textfield/textfield-text-setters` | 8 | 0.8s |  |
| 39 | `undefined/undefined-swf6` | 39 | 0.7s |  |
| 40 | `undefined/undefined-swf7` | 39 | 0.8s |  |
| 41 | `watch` | 2 | 0.7s |  |
| 42 | `xml/xmlbuild` | 1 | 0.7s |  |
| 43 | `xml/xmlload` | 4 | 0.7s |  |
| 44 | `xml/xmlstring` | 9 | 0.8s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 18.3s |  |

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

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 2 | `nested-button` | 0.0% | 0/1 | 0 | 1 |  |
