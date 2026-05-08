# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-08 20:08 UTC

**Git SHA**: `84a147bd4f`

**Run Duration**: 0m 21s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 47 |
| Passing | **45** (95.7%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **46** (97.9%) |
| Failing | 1 |
| Total expected lines | 491 |
| Matching lines | 488 (99.4%) |
| Mismatched lines | 3 |

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
| 3 | `bitmapdata/loadBitmap` | 3 | 0.4s |  |
| 4 | `callee` | 2 | 0.4s |  |
| 5 | `depth` | 6 | 0.5s |  |
| 6 | `doactionorder/doactionorder` | 7 | 0.3s |  |
| 7 | `doactionorder/symbolclass` | 4 | 0.4s |  |
| 8 | `duplicateMovieClip/dontremove` | 6 | 0.4s |  |
| 9 | `duplicateMovieClip/duplicateMovieClip` | 4 | 0.4s |  |
| 10 | `duplicateMovieClip/name-coercion` | 3 | 0.4s |  |
| 11 | `duplicateMovieClip/samedepth` | 6 | 0.4s |  |
| 12 | `externalinterface` | 4 | 0.4s |  |
| 13 | `filters` | 149 | 0.4s |  |
| 14 | `haxe/flocons1` | 2 | 0.4s |  |
| 15 | `haxe/flocons2` | 3 | 0.4s |  |
| 16 | `label` | 4 | 0.4s |  |
| 17 | `levels` | 9 | 0.4s |  |
| 18 | `loadevent` | 9 | 0.4s |  |
| 19 | `loadvariables/loadvariables` | 7 | 0.4s |  |
| 20 | `loadvariables/loadvars` | 2 | 0.4s |  |
| 21 | `lookup` | 3 | 0.4s |  |
| 22 | `mouse-transparency` | 1 | 0.4s |  |
| 23 | `nativeinheritance` | 6 | 0.4s |  |
| 24 | `nested-button` | 1 | 0.4s |  |
| 25 | `operations` | 13 | 0.4s |  |
| 26 | `property-paths/property-paths-6` | 6 | 0.4s |  |
| 27 | `property-paths/property-paths-7` | 7 | 0.4s |  |
| 28 | `propertycase/propertycase` | 7 | 0.3s |  |
| 29 | `propertycase/propertycase-preserving-6` | 2 | 0.3s |  |
| 30 | `propertycase/propertycase-preserving-7` | 5 | 0.1s |  |
| 31 | `rollover` | 4 | 0.4s |  |
| 32 | `scope` | 14 | 0.4s |  |
| 33 | `setinterval` | 20 | 0.4s |  |
| 34 | `settimeout` | 17 | 0.4s |  |
| 35 | `super` | 11 | 0.4s |  |
| 36 | `target` | 18 | 0.4s |  |
| 37 | `text-bind` | 0 | 0.4s |  |
| 38 | `textfield/textfield-html` | 4 | 0.4s |  |
| 39 | `textfield/textfield-text-setters` | 8 | 0.4s |  |
| 40 | `undefined/undefined-swf6` | 39 | 0.4s |  |
| 41 | `undefined/undefined-swf7` | 39 | 0.4s |  |
| 42 | `watch` | 2 | 0.4s |  |
| 43 | `xml/xmlbuild` | 1 | 0.4s |  |
| 44 | `xml/xmlload` | 4 | 0.4s |  |
| 45 | `xml/xmlstring` | 9 | 0.4s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `hitarea` | 2 | 2 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `moviecliploader` | 85.7% | 6 | 7 | 1 |  |

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
| 1 | `moviecliploader` | 85.7% | 6/7 | 6 | 7 |  |
