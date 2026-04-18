# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-18 20:40 UTC

**Git SHA**: `18e004f925`

**Run Duration**: 1m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **44** (93.6%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **45** (95.7%) |
| Failing | 2 |
| Total expected lines | 491 |
| Matching lines | 479 (97.6%) |
| Mismatched lines | 12 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**44 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `array` | 7 | 0.2s |  |
| 2 | `bitmapdata/getPixel` | 2 | 0.2s |  |
| 3 | `bitmapdata/loadBitmap` | 3 | 0.3s |  |
| 4 | `callee` | 2 | 0.3s |  |
| 5 | `depth` | 6 | 0.4s |  |
| 6 | `doactionorder/symbolclass` | 4 | 0.3s |  |
| 7 | `duplicateMovieClip/dontremove` | 6 | 16.3s |  |
| 8 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.2s |  |
| 9 | `duplicateMovieClip/name-coercion` | 3 | 0.2s |  |
| 10 | `duplicateMovieClip/samedepth` | 6 | 0.3s |  |
| 11 | `externalinterface` | 4 | 0.2s |  |
| 12 | `filters` | 149 | 0.2s |  |
| 13 | `haxe/flocons1` | 2 | 0.2s |  |
| 14 | `haxe/flocons2` | 3 | 0.3s |  |
| 15 | `label` | 4 | 16.0s |  |
| 16 | `levels` | 9 | 0.3s |  |
| 17 | `loadevent` | 9 | 0.2s |  |
| 18 | `loadvariables/loadvariables` | 7 | 0.2s |  |
| 19 | `loadvariables/loadvars` | 2 | 0.3s |  |
| 20 | `lookup` | 3 | 0.2s |  |
| 21 | `mouse-transparency` | 1 | 0.2s |  |
| 22 | `nativeinheritance` | 6 | 0.2s |  |
| 23 | `nested-button` | 1 | 12.4s |  |
| 24 | `operations` | 13 | 0.2s |  |
| 25 | `property-paths/property-paths-6` | 6 | 0.2s |  |
| 26 | `property-paths/property-paths-7` | 7 | 0.2s |  |
| 27 | `propertycase/propertycase` | 7 | 0.2s |  |
| 28 | `propertycase/propertycase-preserving-6` | 2 | 0.3s |  |
| 29 | `propertycase/propertycase-preserving-7` | 5 | 0.3s |  |
| 30 | `rollover` | 4 | 0.3s |  |
| 31 | `scope` | 14 | 0.3s |  |
| 32 | `setinterval` | 20 | 0.2s |  |
| 33 | `settimeout` | 17 | 0.3s |  |
| 34 | `super` | 11 | 0.3s |  |
| 35 | `target` | 18 | 0.2s |  |
| 36 | `text-bind` | 0 | 16.0s |  |
| 37 | `textfield/textfield-html` | 4 | 0.2s |  |
| 38 | `textfield/textfield-text-setters` | 8 | 0.3s |  |
| 39 | `undefined/undefined-swf6` | 39 | 0.2s |  |
| 40 | `undefined/undefined-swf7` | 39 | 0.2s |  |
| 41 | `watch` | 2 | 0.2s |  |
| 42 | `xml/xmlbuild` | 1 | 0.3s |  |
| 43 | `xml/xmlload` | 4 | 0.2s |  |
| 44 | `xml/xmlstring` | 9 | 0.2s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 16.7s |  |

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
| 1 | `doactionorder/doactionorder` | 42.9% | 3/7 | 7 | 7 |  |
| 2 | `moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
