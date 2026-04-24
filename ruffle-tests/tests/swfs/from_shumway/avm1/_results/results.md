# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-24 04:05 UTC

**Git SHA**: `9fee5dc139`

**Run Duration**: 1m 37s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **45** (95.7%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **46** (97.9%) |
| Failing | 1 |
| Total expected lines | 491 |
| Matching lines | 483 (98.4%) |
| Mismatched lines | 8 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**45 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.4s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.4s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.5s |  |
| 4 | `callee` | 2 | 0.5s |  |
| 5 | `depth` | 6 | 0.5s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.4s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.5s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 16.3s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.5s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.5s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 0.4s |  |
| 12 | `externalinterface` | 4 | 0.4s |  |
| 13 | `filters` | 149 | 0.5s |  |
| 14 | `haxe/flocons1` | 2 | 0.5s |  |
| 15 | `haxe/flocons2` | 3 | 0.4s |  |
| 16 | `label` | 4 | 15.9s |  |
| 17 | `levels` | 9 | 0.5s |  |
| 18 | `loadevent` | 9 | 0.5s |  |
| 19 | `loadvariables/loadvariables` | 7 | 0.5s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.4s |  |
| 21 | `lookup` | 3 | 0.4s |  |
| 22 | `mouse-transparency` | 1 | 0.5s |  |
| 23 | `nativeinheritance` | 6 | 0.5s |  |
| 24 | `nested-button` | 1 | 16.7s |  |
| 25 | `operations` | 13 | 0.4s |  |
| 26 | `property-paths/property-paths-6` | 6 | 0.4s |  |
| 27 | `property-paths/property-paths-7` | 7 | 0.5s |  |
| 28 | `propertycase/propertycase` | 7 | 0.4s |  |
| 29 | `propertycase/propertycase-preserving-6` | 2 | 0.5s |  |
| 30 | `propertycase/propertycase-preserving-7` | 5 | 0.3s |  |
| 31 | `rollover` | 4 | 0.5s |  |
| 32 | `scope` | 14 | 0.5s |  |
| 33 | `setinterval` | 20 | 0.4s |  |
| 34 | `settimeout` | 17 | 0.5s |  |
| 35 | `super` | 11 | 0.5s |  |
| 36 | `target` | 18 | 0.5s |  |
| 37 | `text-bind` | 0 | 14.0s |  |
| 38 | `textfield/textfield-html` | 4 | 0.4s |  |
| 39 | `textfield/textfield-text-setters` | 8 | 0.4s |  |
| 40 | `undefined/undefined-swf6` | 39 | 0.5s |  |
| 41 | `undefined/undefined-swf7` | 39 | 0.5s |  |
| 42 | `watch` | 2 | 0.4s |  |
| 43 | `xml/xmlbuild` | 1 | 0.4s |  |
| 44 | `xml/xmlload` | 4 | 0.5s |  |
| 45 | `xml/xmlstring` | 9 | 0.5s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 13.0s |  |

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

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
