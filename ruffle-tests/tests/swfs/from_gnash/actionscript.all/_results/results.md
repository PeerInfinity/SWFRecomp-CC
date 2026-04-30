# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-30 21:28 UTC

**Git SHA**: `19cc9a8d78`

**Run Duration**: 1m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **118** (62.1%) |
| Ruffle-matched | 60 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **178** (93.7%) |
| Failing | 12 |
| Total expected lines | 16957 |
| Matching lines | 15065 (88.8%) |
| Mismatched lines | 1892 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 12 | 100.0% |

## Passing Tests

**118 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.6s |  |
| 3 | `Accessibility-v7` | 19 | 0.5s |  |
| 4 | `Accessibility-v8` | 19 | 0.2s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.2s |  |
| 6 | `BitmapData-v5` | 7 | 0.2s |  |
| 7 | `BitmapData-v6` | 7 | 0.2s |  |
| 8 | `BitmapData-v7` | 7 | 0.2s |  |
| 9 | `Boolean-v5` | 38 | 0.2s |  |
| 10 | `Boolean-v6` | 38 | 0.2s |  |
| 11 | `Boolean-v7` | 38 | 0.2s |  |
| 12 | `Boolean-v8` | 38 | 0.3s |  |
| 13 | `Camera-v5` | 7 | 0.2s |  |
| 14 | `Color-v5` | 140 | 0.2s |  |
| 15 | `Color-v6` | 171 | 0.2s |  |
| 16 | `Color-v7` | 161 | 0.3s |  |
| 17 | `Color-v8` | 161 | 0.2s |  |
| 18 | `ColorTransform-v5` | 7 | 1.3s |  |
| 19 | `ColorTransform-v6` | 7 | 1.4s |  |
| 20 | `ColorTransform-v7` | 7 | 1.4s |  |
| 21 | `ColorTransform-v8` | 55 | 0.8s |  |
| 22 | `ContextMenu-v5` | 7 | 0.5s |  |
| 23 | `ContextMenu-v6` | 7 | 0.2s |  |
| 24 | `Error-v5` | 28 | 0.7s |  |
| 25 | `Error-v6` | 31 | 0.3s |  |
| 26 | `Error-v7` | 31 | 0.2s |  |
| 27 | `Error-v8` | 31 | 0.2s |  |
| 28 | `ExternalInterface-v5` | 7 | 0.2s |  |
| 29 | `ExternalInterface-v6` | 55 | 0.2s |  |
| 30 | `ExternalInterface-v7` | 55 | 0.2s |  |
| 31 | `Key-v5` | 51 | 0.2s |  |
| 32 | `Key-v6` | 55 | 0.2s |  |
| 33 | `Key-v7` | 55 | 0.2s |  |
| 34 | `Key-v8` | 55 | 0.2s |  |
| 35 | `LoadVars-v5` | 8 | 0.2s |  |
| 36 | `LocalConnection-v5` | 7 | 0.2s |  |
| 37 | `LocalConnection-v6` | 58 | 0.2s |  |
| 38 | `LocalConnection-v7` | 58 | 0.2s |  |
| 39 | `LocalConnection-v8` | 58 | 0.2s |  |
| 40 | `Matrix-v5` | 7 | 0.2s |  |
| 41 | `Microphone-v5` | 6 | 0.2s |  |
| 42 | `Mouse-v5` | 13 | 0.3s |  |
| 43 | `Mouse-v6` | 21 | 0.2s |  |
| 44 | `Mouse-v7` | 21 | 0.2s |  |
| 45 | `Mouse-v8` | 21 | 0.2s |  |
| 46 | `MovieClipLoader-v5` | 6 | 0.2s |  |
| 47 | `MovieClipLoader-v6` | 6 | 0.3s |  |
| 48 | `NetConnection-v5` | 7 | 0.2s |  |
| 49 | `NetStream-v5` | 6 | 0.2s |  |
| 50 | `NetStream-v6` | 80 | 0.2s |  |
| 51 | `NetStream-v7` | 80 | 0.2s |  |
| 52 | `NetStream-v8` | 80 | 0.2s |  |
| 53 | `Number-v6` | 239 | 0.2s |  |
| 54 | `Number-v7` | 237 | 0.2s |  |
| 55 | `Number-v8` | 237 | 0.2s |  |
| 56 | `Point-v5` | 7 | 0.2s |  |
| 57 | `Point-v6` | 7 | 0.2s |  |
| 58 | `Point-v7` | 7 | 0.2s |  |
| 59 | `Point-v8` | 193 | 0.3s |  |
| 60 | `Random-v5` | 30 | 0.3s |  |
| 61 | `Random-v6` | 30 | 0.3s |  |
| 62 | `Random-v7` | 30 | 0.2s |  |
| 63 | `Random-v8` | 30 | 0.2s |  |
| 64 | `Rectangle-v5` | 7 | 0.2s |  |
| 65 | `Rectangle-v6` | 7 | 0.7s |  |
| 66 | `Rectangle-v7` | 7 | 0.6s |  |
| 67 | `Selection-v5` | 21 | 0.2s |  |
| 68 | `Stage-v5` | 38 | 0.2s |  |
| 69 | `System-v5` | 67 | 0.2s |  |
| 70 | `System-v6` | 100 | 0.2s |  |
| 71 | `System-v7` | 101 | 0.2s |  |
| 72 | `System-v8` | 101 | 0.2s |  |
| 73 | `TextFieldHTML-v5` | 6 | 0.2s |  |
| 74 | `TextFieldHTML-v6` | 37 | 0.2s |  |
| 75 | `TextFieldHTML-v7` | 37 | 0.2s |  |
| 76 | `TextFieldHTML-v8` | 37 | 0.2s |  |
| 77 | `TextFormat-v5` | 128 | 0.2s |  |
| 78 | `TextFormat-v6` | 128 | 0.2s |  |
| 79 | `TextSnapshot-v5` | 7 | 0.2s |  |
| 80 | `TextSnapshot-v6` | 173 | 0.3s |  |
| 81 | `TextSnapshot-v7` | 173 | 0.2s |  |
| 82 | `TextSnapshot-v8` | 173 | 0.3s |  |
| 83 | `Transform-v5` | 7 | 0.2s |  |
| 84 | `Transform-v6` | 7 | 0.3s |  |
| 85 | `Transform-v7` | 7 | 0.2s |  |
| 86 | `Try-v5` | 20 | 0.2s |  |
| 87 | `Try-v6` | 20 | 0.2s |  |
| 88 | `Try-v7` | 20 | 0.2s |  |
| 89 | `Try-v8` | 20 | 0.2s |  |
| 90 | `Video-v5` | 7 | 0.2s |  |
| 91 | `Video-v6` | 85 | 0.2s |  |
| 92 | `Video-v7` | 85 | 0.2s |  |
| 93 | `Video-v8` | 85 | 0.2s |  |
| 94 | `XMLSocket-v5` | 35 | 0.2s |  |
| 95 | `XMLSocket-v6` | 35 | 0.2s |  |
| 96 | `XMLSocket-v7` | 35 | 0.2s |  |
| 97 | `XMLSocket-v8` | 35 | 0.2s |  |
| 98 | `argstest-v5` | 4 | 0.2s |  |
| 99 | `case-v5` | 39 | 0.2s |  |
| 100 | `case-v6` | 73 | 0.2s |  |
| 101 | `case-v7` | 67 | 0.2s |  |
| 102 | `case-v8` | 67 | 0.2s |  |
| 103 | `delete-v5` | 60 | 0.2s |  |
| 104 | `delete-v6` | 60 | 0.2s |  |
| 105 | `delete-v7` | 60 | 0.2s |  |
| 106 | `delete-v8` | 60 | 0.2s |  |
| 107 | `enumerate-v5` | 6 | 0.3s |  |
| 108 | `enumerate-v6` | 49 | 0.2s |  |
| 109 | `enumerate-v7` | 49 | 0.2s |  |
| 110 | `enumerate-v8` | 49 | 0.2s |  |
| 111 | `flash-v5` | 10 | 0.2s |  |
| 112 | `flash-v6` | 10 | 0.2s |  |
| 113 | `flash-v7` | 10 | 0.2s |  |
| 114 | `swap-v5` | 7 | 0.2s |  |
| 115 | `swap-v6` | 7 | 0.2s |  |
| 116 | `swap-v7` | 7 | 0.2s |  |
| 117 | `swap-v8` | 7 | 0.2s |  |
| 118 | `targetPath-v5` | 12 | 0.3s |  |

## Ruffle-Matched Tests

**60 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 0.3s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.3s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 0.2s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.2s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.2s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.3s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.2s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.2s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.2s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 0.2s |  |
| 13 | `HitTest-v6` | 8 | 8 | 0.2s |  |
| 14 | `HitTest-v7` | 8 | 8 | 0.2s |  |
| 15 | `HitTest-v8` | 9 | 9 | 0.2s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 0.2s |  |
| 17 | `Inheritance-v6` | 9 | 16 | 0.2s |  |
| 18 | `Inheritance-v7` | 5 | 10 | 0.3s |  |
| 19 | `Inheritance-v8` | 5 | 10 | 0.2s |  |
| 20 | `LoadVars-v6` | 6 | 21 | 0.3s |  |
| 21 | `LoadVars-v7` | 6 | 21 | 0.3s |  |
| 22 | `LoadVars-v8` | 6 | 21 | 0.3s |  |
| 23 | `Math-v5` | 5 | 5 | 0.3s |  |
| 24 | `Math-v6` | 5 | 5 | 0.2s |  |
| 25 | `Math-v7` | 5 | 5 | 0.3s |  |
| 26 | `Math-v8` | 5 | 5 | 0.3s |  |
| 27 | `Matrix-v6` | 29 | 71 | 0.2s |  |
| 28 | `Matrix-v7` | 28 | 70 | 0.2s |  |
| 29 | `Matrix-v8` | 28 | 70 | 0.2s |  |
| 30 | `Microphone-v6` | 31 | 31 | 0.2s |  |
| 31 | `Microphone-v7` | 31 | 31 | 0.2s |  |
| 32 | `Microphone-v8` | 31 | 31 | 0.2s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 0.2s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 0.2s |  |
| 35 | `Number-v5` | 8 | 13 | 0.2s |  |
| 36 | `Rectangle-v8` | 21 | 21 | 0.5s |  |
| 37 | `Selection-v6` | 7 | 13 | 0.2s |  |
| 38 | `Selection-v7` | 7 | 13 | 0.2s |  |
| 39 | `Selection-v8` | 7 | 13 | 0.2s |  |
| 40 | `Sound-v5` | 27 | 27 | 0.4s |  |
| 41 | `Sound-v6` | 30 | 51 | 0.4s |  |
| 42 | `Sound-v7` | 28 | 51 | 0.4s |  |
| 43 | `Sound-v8` | 28 | 51 | 0.4s |  |
| 44 | `String-v5` | 19 | 21 | 0.3s |  |
| 45 | `String-v6` | 10 | 10 | 0.3s |  |
| 46 | `String-v7` | 10 | 10 | 0.3s |  |
| 47 | `String-v8` | 10 | 10 | 0.3s |  |
| 48 | `TextField-v5` | 3 | 3 | 0.2s |  |
| 49 | `ops-v8` | 7 | 11 | 0.2s |  |
| 50 | `targetPath-v6` | 17 | 17 | 0.2s |  |
| 51 | `targetPath-v7` | 17 | 17 | 0.2s |  |
| 52 | `targetPath-v8` | 17 | 17 | 0.2s |  |
| 53 | `toString_valueOf-v5` | 34 | 34 | 0.3s |  |
| 54 | `toString_valueOf-v6` | 5 | 5 | 0.2s |  |
| 55 | `toString_valueOf-v7` | 5 | 5 | 0.3s |  |
| 56 | `toString_valueOf-v8` | 5 | 5 | 0.2s |  |
| 57 | `with-v5` | 42 | 42 | 0.2s |  |
| 58 | `with-v6` | 91 | 91 | 0.2s |  |
| 59 | `with-v7` | 91 | 91 | 0.2s |  |
| 60 | `with-v8` | 91 | 91 | 0.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 92.3% | 517 | 560 | 43 |  |
| 2 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 3 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 4 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 5 | `MovieClip-v5` | 76.3% | 277 | 363 | 86 |  |
| 6 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 7 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 8 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 9 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 10 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**12 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 92.3% | 517/560 | 560 | 560 |  |
| 2 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 3 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 4 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 5 | `MovieClip-v5` | 76.3% | 277/363 | 350 | 363 |  |
| 6 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 7 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 8 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 9 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 10 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 11 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 12 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
