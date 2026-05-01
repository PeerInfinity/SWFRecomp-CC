# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-01 23:05 UTC

**Git SHA**: `2e50fd7e45`

**Run Duration**: 16m 15s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **122** (64.2%) |
| Ruffle-matched | 60 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **182** (95.8%) |
| Failing | 8 |
| Total expected lines | 16957 |
| Matching lines | 15243 (89.9%) |
| Mismatched lines | 1714 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**122 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.3s |  |
| 3 | `Accessibility-v7` | 19 | 0.3s |  |
| 4 | `Accessibility-v8` | 19 | 18.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.9s |  |
| 6 | `BitmapData-v5` | 7 | 1.9s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 16.9s |  |
| 9 | `Boolean-v5` | 38 | 0.3s |  |
| 10 | `Boolean-v6` | 38 | 0.3s |  |
| 11 | `Boolean-v7` | 38 | 0.3s |  |
| 12 | `Boolean-v8` | 38 | 0.3s |  |
| 13 | `Camera-v5` | 7 | 0.3s |  |
| 14 | `Color-v5` | 140 | 4.9s |  |
| 15 | `Color-v6` | 171 | 6.0s |  |
| 16 | `Color-v7` | 161 | 5.8s |  |
| 17 | `Color-v8` | 161 | 1.3s |  |
| 18 | `ColorTransform-v5` | 7 | 18.3s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.2s |  |
| 21 | `ColorTransform-v8` | 55 | 3.0s |  |
| 22 | `ContextMenu-v5` | 7 | 1.6s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `Error-v5` | 28 | 2.2s |  |
| 25 | `Error-v6` | 31 | 2.3s |  |
| 26 | `Error-v7` | 31 | 1.9s |  |
| 27 | `Error-v8` | 31 | 1.3s |  |
| 28 | `ExternalInterface-v5` | 7 | 1.8s |  |
| 29 | `ExternalInterface-v6` | 55 | 2.6s |  |
| 30 | `ExternalInterface-v7` | 55 | 19.2s |  |
| 31 | `Instance-v5` | 52 | 0.3s |  |
| 32 | `Instance-v6` | 52 | 0.3s |  |
| 33 | `Instance-v7` | 52 | 13.6s |  |
| 34 | `Instance-v8` | 52 | 0.3s |  |
| 35 | `Key-v5` | 51 | 0.3s |  |
| 36 | `Key-v6` | 55 | 0.3s |  |
| 37 | `Key-v7` | 55 | 0.3s |  |
| 38 | `Key-v8` | 55 | 0.3s |  |
| 39 | `LoadVars-v5` | 8 | 14.0s |  |
| 40 | `LocalConnection-v5` | 7 | 18.2s |  |
| 41 | `LocalConnection-v6` | 58 | 2.9s |  |
| 42 | `LocalConnection-v7` | 58 | 2.6s |  |
| 43 | `LocalConnection-v8` | 58 | 1.3s |  |
| 44 | `Matrix-v5` | 7 | 1.8s |  |
| 45 | `Microphone-v5` | 6 | 0.3s |  |
| 46 | `Mouse-v5` | 13 | 16.6s |  |
| 47 | `Mouse-v6` | 21 | 0.3s |  |
| 48 | `Mouse-v7` | 21 | 0.3s |  |
| 49 | `Mouse-v8` | 21 | 0.3s |  |
| 50 | `MovieClipLoader-v5` | 6 | 0.3s |  |
| 51 | `MovieClipLoader-v6` | 6 | 17.4s |  |
| 52 | `NetConnection-v5` | 7 | 17.4s |  |
| 53 | `NetStream-v5` | 6 | 1.5s |  |
| 54 | `NetStream-v6` | 80 | 3.0s |  |
| 55 | `NetStream-v7` | 80 | 21.0s |  |
| 56 | `NetStream-v8` | 80 | 1.3s |  |
| 57 | `Number-v6` | 239 | 9.0s |  |
| 58 | `Number-v7` | 237 | 8.9s |  |
| 59 | `Number-v8` | 237 | 1.5s |  |
| 60 | `Point-v5` | 7 | 18.6s |  |
| 61 | `Point-v6` | 7 | 0.6s |  |
| 62 | `Point-v7` | 7 | 1.4s |  |
| 63 | `Point-v8` | 193 | 7.9s |  |
| 64 | `Random-v5` | 30 | 2.4s |  |
| 65 | `Random-v6` | 30 | 0.6s |  |
| 66 | `Random-v7` | 30 | 16.6s |  |
| 67 | `Random-v8` | 30 | 0.3s |  |
| 68 | `Rectangle-v5` | 7 | 0.3s |  |
| 69 | `Rectangle-v6` | 7 | 0.3s |  |
| 70 | `Rectangle-v7` | 7 | 0.3s |  |
| 71 | `Selection-v5` | 21 | 17.1s |  |
| 72 | `Stage-v5` | 38 | 17.6s |  |
| 73 | `System-v5` | 67 | 0.3s |  |
| 74 | `System-v6` | 100 | 0.3s |  |
| 75 | `System-v7` | 101 | 0.3s |  |
| 76 | `System-v8` | 101 | 0.3s |  |
| 77 | `TextFieldHTML-v5` | 6 | 17.2s |  |
| 78 | `TextFieldHTML-v6` | 37 | 0.3s |  |
| 79 | `TextFieldHTML-v7` | 37 | 0.3s |  |
| 80 | `TextFieldHTML-v8` | 37 | 0.3s |  |
| 81 | `TextFormat-v5` | 128 | 0.3s |  |
| 82 | `TextFormat-v6` | 128 | 0.3s |  |
| 83 | `TextSnapshot-v5` | 7 | 0.8s |  |
| 84 | `TextSnapshot-v6` | 173 | 1.0s |  |
| 85 | `TextSnapshot-v7` | 173 | 0.5s |  |
| 86 | `TextSnapshot-v8` | 173 | 0.5s |  |
| 87 | `Transform-v5` | 7 | 0.8s |  |
| 88 | `Transform-v6` | 7 | 16.6s |  |
| 89 | `Transform-v7` | 7 | 0.3s |  |
| 90 | `Try-v5` | 20 | 0.3s |  |
| 91 | `Try-v6` | 20 | 0.3s |  |
| 92 | `Try-v7` | 20 | 0.3s |  |
| 93 | `Try-v8` | 20 | 0.3s |  |
| 94 | `Video-v5` | 7 | 18.8s |  |
| 95 | `Video-v6` | 85 | 3.4s |  |
| 96 | `Video-v7` | 85 | 3.0s |  |
| 97 | `Video-v8` | 85 | 1.4s |  |
| 98 | `XMLSocket-v5` | 35 | 19.0s |  |
| 99 | `XMLSocket-v6` | 35 | 2.5s |  |
| 100 | `XMLSocket-v7` | 35 | 16.7s |  |
| 101 | `XMLSocket-v8` | 35 | 0.3s |  |
| 102 | `argstest-v5` | 4 | 0.3s |  |
| 103 | `case-v5` | 39 | 0.3s |  |
| 104 | `case-v6` | 73 | 0.3s |  |
| 105 | `case-v7` | 67 | 20.0s |  |
| 106 | `case-v8` | 67 | 1.4s |  |
| 107 | `delete-v5` | 60 | 2.9s |  |
| 108 | `delete-v6` | 60 | 2.3s |  |
| 109 | `delete-v7` | 60 | 2.5s |  |
| 110 | `delete-v8` | 60 | 1.4s |  |
| 111 | `enumerate-v5` | 6 | 18.3s |  |
| 112 | `enumerate-v6` | 49 | 2.9s |  |
| 113 | `enumerate-v7` | 49 | 2.5s |  |
| 114 | `enumerate-v8` | 49 | 1.3s |  |
| 115 | `flash-v5` | 10 | 1.9s |  |
| 116 | `flash-v6` | 10 | 1.9s |  |
| 117 | `flash-v7` | 10 | 19.9s |  |
| 118 | `swap-v5` | 7 | 1.5s |  |
| 119 | `swap-v6` | 7 | 0.6s |  |
| 120 | `swap-v7` | 7 | 1.5s |  |
| 121 | `swap-v8` | 7 | 1.3s |  |
| 122 | `targetPath-v5` | 12 | 18.2s |  |

## Ruffle-Matched Tests

**60 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 17.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.3s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.0s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.6s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.5s |  |
| 9 | `Camera-v6` | 57 | 57 | 19.2s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.2s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.2s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 4.7s |  |
| 13 | `HitTest-v6` | 8 | 8 | 4.8s |  |
| 14 | `HitTest-v7` | 8 | 8 | 4.4s |  |
| 15 | `HitTest-v8` | 9 | 9 | 17.3s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 0.3s |  |
| 17 | `Inheritance-v6` | 9 | 16 | 0.3s |  |
| 18 | `Inheritance-v7` | 5 | 10 | 0.3s |  |
| 19 | `Inheritance-v8` | 5 | 10 | 0.3s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 21.7s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 4.9s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 2.1s |  |
| 23 | `Math-v5` | 5 | 5 | 29.3s |  |
| 24 | `Math-v6` | 5 | 5 | 0.6s |  |
| 25 | `Math-v7` | 5 | 5 | 13.3s |  |
| 26 | `Math-v8` | 5 | 5 | 1.4s |  |
| 27 | `Matrix-v6` | 29 | 71 | 6.7s |  |
| 28 | `Matrix-v7` | 28 | 70 | 18.6s |  |
| 29 | `Matrix-v8` | 28 | 70 | 0.3s |  |
| 30 | `Microphone-v6` | 31 | 31 | 0.3s |  |
| 31 | `Microphone-v7` | 31 | 31 | 0.3s |  |
| 32 | `Microphone-v8` | 31 | 31 | 0.3s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 3.5s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 2.1s |  |
| 35 | `Number-v5` | 8 | 13 | 9.2s |  |
| 36 | `Rectangle-v8` | 21 | 21 | 0.3s |  |
| 37 | `Selection-v6` | 7 | 13 | 0.3s |  |
| 38 | `Selection-v7` | 7 | 13 | 0.3s |  |
| 39 | `Selection-v8` | 7 | 13 | 0.3s |  |
| 40 | `Sound-v5` | 27 | 27 | 17.4s |  |
| 41 | `Sound-v6` | 30 | 51 | 0.5s |  |
| 42 | `Sound-v7` | 28 | 51 | 18.0s |  |
| 43 | `Sound-v8` | 28 | 51 | 0.4s |  |
| 44 | `String-v5` | 19 | 21 | 0.3s |  |
| 45 | `String-v6` | 10 | 10 | 0.3s |  |
| 46 | `String-v7` | 10 | 10 | 0.3s |  |
| 47 | `String-v8` | 10 | 10 | 16.4s |  |
| 48 | `TextField-v5` | 3 | 3 | 0.3s |  |
| 49 | `ops-v8` | 7 | 11 | 9.9s |  |
| 50 | `targetPath-v6` | 17 | 17 | 2.1s |  |
| 51 | `targetPath-v7` | 17 | 17 | 1.7s |  |
| 52 | `targetPath-v8` | 17 | 17 | 1.2s |  |
| 53 | `toString_valueOf-v5` | 34 | 34 | 4.8s |  |
| 54 | `toString_valueOf-v6` | 5 | 5 | 5.2s |  |
| 55 | `toString_valueOf-v7` | 5 | 5 | 22.3s |  |
| 56 | `toString_valueOf-v8` | 5 | 5 | 1.4s |  |
| 57 | `with-v5` | 42 | 42 | 3.3s |  |
| 58 | `with-v6` | 91 | 91 | 4.6s |  |
| 59 | `with-v7` | 91 | 91 | 4.2s |  |
| 60 | `with-v8` | 91 | 91 | 1.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Global-v7` | 96.2% | 175 | 182 | 7 |  |
| 2 | `Global-v8` | 95.9% | 162 | 169 | 7 |  |
| 3 | `Global-v6` | 93.3% | 196 | 210 | 14 |  |
| 4 | `array-v5` | 92.3% | 517 | 560 | 43 |  |
| 5 | `MovieClip-v5` | 76.3% | 277 | 363 | 86 |  |
| 6 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 7 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 8 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Global-v7` | 96.2% | 175/182 | 181 | 182 |  |
| 2 | `Global-v8` | 95.9% | 162/169 | 168 | 169 |  |
| 3 | `Global-v6` | 93.3% | 196/210 | 209 | 210 |  |
| 4 | `array-v5` | 92.3% | 517/560 | 560 | 560 |  |
| 5 | `MovieClip-v5` | 76.3% | 277/363 | 350 | 363 |  |
| 6 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 7 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 8 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
