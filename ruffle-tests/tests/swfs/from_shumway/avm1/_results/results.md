# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-06 03:29 UTC

**Git SHA**: `94cda99476`

**Run Duration**: 0m 52s

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
| 1 | `array` | 7 | 1.0s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.9s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.9s |  |
| 4 | `callee` | 2 | 1.0s |  |
| 5 | `depth` | 6 | 0.3s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.2s |  |
| 7 | `doactionorder/symbolclass` | 4 | 1.2s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 1.1s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.2s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.2s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 0.2s |  |
| 12 | `externalinterface` | 4 | 0.2s |  |
| 13 | `filters` | 149 | 0.2s |  |
| 14 | `haxe/flocons1` | 2 | 0.2s |  |
| 15 | `haxe/flocons2` | 3 | 0.9s |  |
| 16 | `label` | 4 | 0.2s |  |
| 17 | `levels` | 9 | 0.2s |  |
| 18 | `loadevent` | 9 | 1.3s |  |
| 19 | `loadvariables/loadvariables` | 7 | 1.1s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.8s |  |
| 21 | `lookup` | 3 | 0.8s |  |
| 22 | `mouse-transparency` | 1 | 0.2s |  |
| 23 | `nativeinheritance` | 6 | 0.2s |  |
| 24 | `nested-button` | 1 | 0.2s |  |
| 25 | `operations` | 13 | 1.0s |  |
| 26 | `property-paths/property-paths-6` | 6 | 0.9s |  |
| 27 | `property-paths/property-paths-7` | 7 | 0.1s |  |
| 28 | `propertycase/propertycase` | 7 | 0.1s |  |
| 29 | `propertycase/propertycase-preserving-6` | 2 | 0.8s |  |
| 30 | `propertycase/propertycase-preserving-7` | 5 | 0.3s |  |
| 31 | `rollover` | 4 | 0.9s |  |
| 32 | `scope` | 14 | 0.9s |  |
| 33 | `setinterval` | 20 | 0.2s |  |
| 34 | `settimeout` | 17 | 0.1s |  |
| 35 | `super` | 11 | 0.9s |  |
| 36 | `target` | 18 | 1.1s |  |
| 37 | `text-bind` | 0 | 0.2s |  |
| 38 | `textfield/textfield-html` | 4 | 1.0s |  |
| 39 | `textfield/textfield-text-setters` | 8 | 1.0s |  |
| 40 | `undefined/undefined-swf6` | 39 | 1.0s |  |
| 41 | `undefined/undefined-swf7` | 39 | 1.7s |  |
| 42 | `watch` | 2 | 0.8s |  |
| 43 | `xml/xmlbuild` | 1 | 1.0s |  |
| 44 | `xml/xmlload` | 4 | 1.1s |  |
| 45 | `xml/xmlstring` | 9 | 1.1s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 18.8s |  |

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
