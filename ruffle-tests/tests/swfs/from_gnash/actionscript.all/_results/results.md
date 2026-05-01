# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-01 18:13 UTC

**Git SHA**: `faf492a5eb`

**Run Duration**: 11m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **122** (64.2%) |
| Ruffle-matched | 63 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **185** (97.4%) |
| Failing | 5 |
| Total expected lines | 16957 |
| Matching lines | 15243 (89.9%) |
| Mismatched lines | 1714 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**122 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.3s |  |
| 3 | `Accessibility-v7` | 19 | 0.3s |  |
| 4 | `Accessibility-v8` | 19 | 16.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.3s |  |
| 6 | `BitmapData-v5` | 7 | 0.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.3s |  |
| 8 | `BitmapData-v7` | 7 | 16.9s |  |
| 9 | `Boolean-v5` | 38 | 0.3s |  |
| 10 | `Boolean-v6` | 38 | 0.3s |  |
| 11 | `Boolean-v7` | 38 | 0.3s |  |
| 12 | `Boolean-v8` | 38 | 0.3s |  |
| 13 | `Camera-v5` | 7 | 0.3s |  |
| 14 | `Color-v5` | 140 | 0.3s |  |
| 15 | `Color-v6` | 171 | 0.3s |  |
| 16 | `Color-v7` | 161 | 0.3s |  |
| 17 | `Color-v8` | 161 | 0.3s |  |
| 18 | `ColorTransform-v5` | 7 | 16.9s |  |
| 19 | `ColorTransform-v6` | 7 | 0.3s |  |
| 20 | `ColorTransform-v7` | 7 | 0.3s |  |
| 21 | `ColorTransform-v8` | 55 | 0.4s |  |
| 22 | `ContextMenu-v5` | 7 | 0.3s |  |
| 23 | `ContextMenu-v6` | 7 | 0.3s |  |
| 24 | `Error-v5` | 28 | 0.4s |  |
| 25 | `Error-v6` | 31 | 0.4s |  |
| 26 | `Error-v7` | 31 | 0.4s |  |
| 27 | `Error-v8` | 31 | 0.4s |  |
| 28 | `ExternalInterface-v5` | 7 | 0.3s |  |
| 29 | `ExternalInterface-v6` | 55 | 0.4s |  |
| 30 | `ExternalInterface-v7` | 55 | 18.1s |  |
| 31 | `Instance-v5` | 52 | 0.4s |  |
| 32 | `Instance-v6` | 52 | 0.4s |  |
| 33 | `Instance-v7` | 52 | 17.1s |  |
| 34 | `Instance-v8` | 52 | 0.3s |  |
| 35 | `Key-v5` | 51 | 0.3s |  |
| 36 | `Key-v6` | 55 | 0.3s |  |
| 37 | `Key-v7` | 55 | 0.3s |  |
| 38 | `Key-v8` | 55 | 0.3s |  |
| 39 | `LoadVars-v5` | 8 | 17.1s |  |
| 40 | `LocalConnection-v5` | 7 | 17.8s |  |
| 41 | `LocalConnection-v6` | 58 | 0.4s |  |
| 42 | `LocalConnection-v7` | 58 | 0.4s |  |
| 43 | `LocalConnection-v8` | 58 | 0.4s |  |
| 44 | `Matrix-v5` | 7 | 0.4s |  |
| 45 | `Microphone-v5` | 6 | 0.3s |  |
| 46 | `Mouse-v5` | 13 | 18.1s |  |
| 47 | `Mouse-v6` | 21 | 0.4s |  |
| 48 | `Mouse-v7` | 21 | 0.4s |  |
| 49 | `Mouse-v8` | 21 | 0.4s |  |
| 50 | `MovieClipLoader-v5` | 6 | 0.4s |  |
| 51 | `MovieClipLoader-v6` | 6 | 17.9s |  |
| 52 | `NetConnection-v5` | 7 | 17.8s |  |
| 53 | `NetStream-v5` | 6 | 0.4s |  |
| 54 | `NetStream-v6` | 80 | 0.4s |  |
| 55 | `NetStream-v7` | 80 | 17.1s |  |
| 56 | `NetStream-v8` | 80 | 0.3s |  |
| 57 | `Number-v6` | 239 | 0.4s |  |
| 58 | `Number-v7` | 237 | 0.4s |  |
| 59 | `Number-v8` | 237 | 0.4s |  |
| 60 | `Point-v5` | 7 | 17.6s |  |
| 61 | `Point-v6` | 7 | 0.3s |  |
| 62 | `Point-v7` | 7 | 0.3s |  |
| 63 | `Point-v8` | 193 | 0.3s |  |
| 64 | `Random-v5` | 30 | 0.3s |  |
| 65 | `Random-v6` | 30 | 0.3s |  |
| 66 | `Random-v7` | 30 | 13.9s |  |
| 67 | `Random-v8` | 30 | 0.3s |  |
| 68 | `Rectangle-v5` | 7 | 0.3s |  |
| 69 | `Rectangle-v6` | 7 | 0.3s |  |
| 70 | `Rectangle-v7` | 7 | 0.3s |  |
| 71 | `Selection-v5` | 21 | 16.5s |  |
| 72 | `Stage-v5` | 38 | 16.7s |  |
| 73 | `System-v5` | 67 | 0.3s |  |
| 74 | `System-v6` | 100 | 0.3s |  |
| 75 | `System-v7` | 101 | 0.3s |  |
| 76 | `System-v8` | 101 | 0.3s |  |
| 77 | `TextFieldHTML-v5` | 6 | 20.3s |  |
| 78 | `TextFieldHTML-v6` | 37 | 0.4s |  |
| 79 | `TextFieldHTML-v7` | 37 | 0.4s |  |
| 80 | `TextFieldHTML-v8` | 37 | 0.4s |  |
| 81 | `TextFormat-v5` | 128 | 0.4s |  |
| 82 | `TextFormat-v6` | 128 | 0.4s |  |
| 83 | `TextSnapshot-v5` | 7 | 0.3s |  |
| 84 | `TextSnapshot-v6` | 173 | 0.3s |  |
| 85 | `TextSnapshot-v7` | 173 | 0.3s |  |
| 86 | `TextSnapshot-v8` | 173 | 0.3s |  |
| 87 | `Transform-v5` | 7 | 0.3s |  |
| 88 | `Transform-v6` | 7 | 16.9s |  |
| 89 | `Transform-v7` | 7 | 0.3s |  |
| 90 | `Try-v5` | 20 | 0.3s |  |
| 91 | `Try-v6` | 20 | 0.4s |  |
| 92 | `Try-v7` | 20 | 0.3s |  |
| 93 | `Try-v8` | 20 | 0.3s |  |
| 94 | `Video-v5` | 7 | 17.3s |  |
| 95 | `Video-v6` | 85 | 0.4s |  |
| 96 | `Video-v7` | 85 | 0.4s |  |
| 97 | `Video-v8` | 85 | 0.4s |  |
| 98 | `XMLSocket-v5` | 35 | 17.6s |  |
| 99 | `XMLSocket-v6` | 35 | 0.3s |  |
| 100 | `XMLSocket-v7` | 35 | 16.9s |  |
| 101 | `XMLSocket-v8` | 35 | 0.3s |  |
| 102 | `argstest-v5` | 4 | 0.3s |  |
| 103 | `case-v5` | 39 | 0.3s |  |
| 104 | `case-v6` | 73 | 0.4s |  |
| 105 | `case-v7` | 67 | 16.4s |  |
| 106 | `case-v8` | 67 | 0.3s |  |
| 107 | `delete-v5` | 60 | 0.3s |  |
| 108 | `delete-v6` | 60 | 0.3s |  |
| 109 | `delete-v7` | 60 | 0.3s |  |
| 110 | `delete-v8` | 60 | 0.3s |  |
| 111 | `enumerate-v5` | 6 | 18.8s |  |
| 112 | `enumerate-v6` | 49 | 0.4s |  |
| 113 | `enumerate-v7` | 49 | 0.4s |  |
| 114 | `enumerate-v8` | 49 | 0.4s |  |
| 115 | `flash-v5` | 10 | 0.4s |  |
| 116 | `flash-v6` | 10 | 0.4s |  |
| 117 | `flash-v7` | 10 | 17.6s |  |
| 118 | `swap-v5` | 7 | 0.4s |  |
| 119 | `swap-v6` | 7 | 0.4s |  |
| 120 | `swap-v7` | 7 | 0.4s |  |
| 121 | `swap-v8` | 7 | 0.4s |  |
| 122 | `targetPath-v5` | 12 | 17.1s |  |

## Ruffle-Matched Tests

**63 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 17.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.3s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 0.3s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.3s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.3s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.5s |  |
| 9 | `Camera-v6` | 57 | 57 | 16.9s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.3s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.3s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 0.4s |  |
| 13 | `Global-v6` | 14 | 17 | 0.4s |  |
| 14 | `Global-v7` | 7 | 10 | 0.4s |  |
| 15 | `Global-v8` | 7 | 10 | 0.4s |  |
| 16 | `HitTest-v6` | 8 | 8 | 0.4s |  |
| 17 | `HitTest-v7` | 8 | 8 | 0.4s |  |
| 18 | `HitTest-v8` | 9 | 9 | 18.2s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 0.4s |  |
| 20 | `Inheritance-v6` | 9 | 16 | 0.4s |  |
| 21 | `Inheritance-v7` | 5 | 10 | 0.4s |  |
| 22 | `Inheritance-v8` | 5 | 10 | 0.4s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 18.1s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 0.4s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 0.4s |  |
| 26 | `Math-v5` | 5 | 5 | 18.5s |  |
| 27 | `Math-v6` | 5 | 5 | 0.4s |  |
| 28 | `Math-v7` | 5 | 5 | 0.4s |  |
| 29 | `Math-v8` | 5 | 5 | 0.4s |  |
| 30 | `Matrix-v6` | 29 | 71 | 0.4s |  |
| 31 | `Matrix-v7` | 28 | 70 | 16.7s |  |
| 32 | `Matrix-v8` | 28 | 70 | 0.3s |  |
| 33 | `Microphone-v6` | 31 | 31 | 0.3s |  |
| 34 | `Microphone-v7` | 31 | 31 | 0.3s |  |
| 35 | `Microphone-v8` | 31 | 31 | 0.3s |  |
| 36 | `MovieClipLoader-v7` | 118 | 118 | 0.4s |  |
| 37 | `MovieClipLoader-v8` | 118 | 118 | 0.4s |  |
| 38 | `Number-v5` | 8 | 13 | 0.4s |  |
| 39 | `Rectangle-v8` | 21 | 21 | 0.3s |  |
| 40 | `Selection-v6` | 7 | 13 | 0.3s |  |
| 41 | `Selection-v7` | 7 | 13 | 0.3s |  |
| 42 | `Selection-v8` | 7 | 13 | 0.3s |  |
| 43 | `Sound-v5` | 27 | 27 | 16.9s |  |
| 44 | `Sound-v6` | 30 | 51 | 0.4s |  |
| 45 | `Sound-v7` | 28 | 51 | 17.1s |  |
| 46 | `Sound-v8` | 28 | 51 | 0.4s |  |
| 47 | `String-v5` | 19 | 21 | 0.3s |  |
| 48 | `String-v6` | 10 | 10 | 0.3s |  |
| 49 | `String-v7` | 10 | 10 | 0.3s |  |
| 50 | `String-v8` | 10 | 10 | 16.8s |  |
| 51 | `TextField-v5` | 3 | 3 | 0.3s |  |
| 52 | `ops-v8` | 7 | 11 | 0.4s |  |
| 53 | `targetPath-v6` | 17 | 17 | 0.3s |  |
| 54 | `targetPath-v7` | 17 | 17 | 0.3s |  |
| 55 | `targetPath-v8` | 17 | 17 | 0.3s |  |
| 56 | `toString_valueOf-v5` | 34 | 34 | 0.3s |  |
| 57 | `toString_valueOf-v6` | 5 | 5 | 0.3s |  |
| 58 | `toString_valueOf-v7` | 5 | 5 | 17.3s |  |
| 59 | `toString_valueOf-v8` | 5 | 5 | 0.3s |  |
| 60 | `with-v5` | 42 | 42 | 0.3s |  |
| 61 | `with-v6` | 91 | 91 | 0.3s |  |
| 62 | `with-v7` | 91 | 91 | 0.3s |  |
| 63 | `with-v8` | 91 | 91 | 0.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 92.3% | 517 | 560 | 43 |  |
| 2 | `MovieClip-v5` | 76.3% | 277 | 363 | 86 |  |
| 3 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 4 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 5 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |

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
| 1 | `array-v5` | 92.3% | 517/560 | 560 | 560 |  |
| 2 | `MovieClip-v5` | 76.3% | 277/363 | 350 | 363 |  |
| 3 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 4 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 5 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
