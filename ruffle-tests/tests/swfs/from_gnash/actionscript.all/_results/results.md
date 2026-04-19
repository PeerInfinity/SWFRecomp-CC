# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-19 04:27 UTC

**Git SHA**: `f5c9599b0f`

**Run Duration**: 10m 50s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **110** (57.9%) |
| Ruffle-matched | 37 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **147** (77.4%) |
| Failing | 43 |
| Total expected lines | 16957 |
| Matching lines | 14038 (82.8%) |
| Mismatched lines | 2919 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 43 | 100.0% |

## Passing Tests

**110 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.3s |  |
| 3 | `Accessibility-v7` | 19 | 0.3s |  |
| 4 | `Accessibility-v8` | 19 | 15.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.3s |  |
| 6 | `BitmapData-v5` | 7 | 0.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.3s |  |
| 8 | `BitmapData-v7` | 7 | 16.5s |  |
| 9 | `Boolean-v5` | 38 | 0.3s |  |
| 10 | `Boolean-v6` | 38 | 0.3s |  |
| 11 | `Boolean-v7` | 38 | 0.3s |  |
| 12 | `Boolean-v8` | 38 | 0.3s |  |
| 13 | `Camera-v5` | 7 | 0.3s |  |
| 14 | `Color-v5` | 140 | 0.3s |  |
| 15 | `Color-v6` | 171 | 0.3s |  |
| 16 | `Color-v7` | 161 | 0.3s |  |
| 17 | `Color-v8` | 161 | 0.3s |  |
| 18 | `ColorTransform-v5` | 7 | 15.5s |  |
| 19 | `ColorTransform-v6` | 7 | 0.3s |  |
| 20 | `ColorTransform-v7` | 7 | 0.3s |  |
| 21 | `ColorTransform-v8` | 55 | 0.3s |  |
| 22 | `ContextMenu-v5` | 7 | 0.3s |  |
| 23 | `ContextMenu-v6` | 7 | 0.3s |  |
| 24 | `Error-v5` | 28 | 0.3s |  |
| 25 | `Error-v6` | 31 | 0.3s |  |
| 26 | `Error-v7` | 31 | 0.3s |  |
| 27 | `Error-v8` | 31 | 0.3s |  |
| 28 | `ExternalInterface-v5` | 7 | 0.3s |  |
| 29 | `Key-v5` | 51 | 0.3s |  |
| 30 | `Key-v6` | 55 | 0.3s |  |
| 31 | `Key-v7` | 55 | 0.3s |  |
| 32 | `Key-v8` | 55 | 0.3s |  |
| 33 | `LoadVars-v5` | 8 | 17.1s |  |
| 34 | `LocalConnection-v5` | 7 | 15.7s |  |
| 35 | `LocalConnection-v6` | 58 | 0.3s |  |
| 36 | `LocalConnection-v7` | 58 | 0.3s |  |
| 37 | `LocalConnection-v8` | 58 | 0.3s |  |
| 38 | `Matrix-v5` | 7 | 0.3s |  |
| 39 | `Microphone-v5` | 6 | 0.3s |  |
| 40 | `Mouse-v5` | 13 | 15.8s |  |
| 41 | `Mouse-v6` | 21 | 0.3s |  |
| 42 | `Mouse-v7` | 21 | 0.3s |  |
| 43 | `Mouse-v8` | 21 | 0.3s |  |
| 44 | `MovieClipLoader-v5` | 6 | 0.3s |  |
| 45 | `MovieClipLoader-v6` | 6 | 16.1s |  |
| 46 | `NetConnection-v5` | 7 | 16.0s |  |
| 47 | `NetStream-v5` | 6 | 0.3s |  |
| 48 | `NetStream-v6` | 80 | 0.3s |  |
| 49 | `NetStream-v7` | 80 | 15.5s |  |
| 50 | `NetStream-v8` | 80 | 0.3s |  |
| 51 | `Number-v6` | 239 | 0.3s |  |
| 52 | `Number-v7` | 237 | 0.3s |  |
| 53 | `Number-v8` | 237 | 0.3s |  |
| 54 | `Point-v5` | 7 | 16.2s |  |
| 55 | `Point-v6` | 7 | 0.3s |  |
| 56 | `Point-v7` | 7 | 0.3s |  |
| 57 | `Random-v5` | 30 | 0.3s |  |
| 58 | `Random-v6` | 30 | 0.3s |  |
| 59 | `Random-v7` | 30 | 15.9s |  |
| 60 | `Random-v8` | 30 | 0.3s |  |
| 61 | `Rectangle-v5` | 7 | 0.3s |  |
| 62 | `Rectangle-v6` | 7 | 0.3s |  |
| 63 | `Rectangle-v7` | 7 | 0.3s |  |
| 64 | `Selection-v5` | 21 | 16.5s |  |
| 65 | `Stage-v5` | 38 | 15.5s |  |
| 66 | `System-v5` | 67 | 0.3s |  |
| 67 | `System-v6` | 100 | 0.3s |  |
| 68 | `System-v7` | 101 | 0.3s |  |
| 69 | `System-v8` | 101 | 0.3s |  |
| 70 | `TextField-v5` | 12 | 0.3s |  |
| 71 | `TextFieldHTML-v5` | 6 | 15.6s |  |
| 72 | `TextFormat-v5` | 128 | 0.3s |  |
| 73 | `TextFormat-v6` | 128 | 0.3s |  |
| 74 | `TextSnapshot-v5` | 7 | 0.3s |  |
| 75 | `TextSnapshot-v6` | 173 | 0.3s |  |
| 76 | `TextSnapshot-v7` | 173 | 0.3s |  |
| 77 | `TextSnapshot-v8` | 173 | 0.3s |  |
| 78 | `Transform-v5` | 7 | 0.3s |  |
| 79 | `Transform-v6` | 7 | 15.7s |  |
| 80 | `Transform-v7` | 7 | 0.3s |  |
| 81 | `Try-v5` | 20 | 0.3s |  |
| 82 | `Try-v6` | 20 | 0.3s |  |
| 83 | `Try-v7` | 20 | 0.3s |  |
| 84 | `Try-v8` | 20 | 0.3s |  |
| 85 | `Video-v5` | 7 | 16.1s |  |
| 86 | `Video-v6` | 85 | 0.3s |  |
| 87 | `Video-v7` | 85 | 0.3s |  |
| 88 | `Video-v8` | 85 | 0.3s |  |
| 89 | `XMLSocket-v5` | 35 | 15.8s |  |
| 90 | `XMLSocket-v6` | 35 | 0.3s |  |
| 91 | `XMLSocket-v7` | 35 | 15.6s |  |
| 92 | `XMLSocket-v8` | 35 | 0.3s |  |
| 93 | `argstest-v5` | 4 | 0.2s |  |
| 94 | `case-v5` | 39 | 0.3s |  |
| 95 | `delete-v5` | 60 | 0.3s |  |
| 96 | `delete-v6` | 60 | 0.3s |  |
| 97 | `delete-v7` | 60 | 0.3s |  |
| 98 | `delete-v8` | 60 | 0.3s |  |
| 99 | `enumerate-v5` | 6 | 16.1s |  |
| 100 | `enumerate-v6` | 49 | 0.3s |  |
| 101 | `enumerate-v7` | 49 | 0.3s |  |
| 102 | `enumerate-v8` | 49 | 0.3s |  |
| 103 | `flash-v5` | 10 | 0.3s |  |
| 104 | `flash-v6` | 10 | 0.3s |  |
| 105 | `flash-v7` | 10 | 16.5s |  |
| 106 | `swap-v5` | 7 | 0.3s |  |
| 107 | `swap-v6` | 7 | 0.3s |  |
| 108 | `swap-v7` | 7 | 0.3s |  |
| 109 | `swap-v8` | 7 | 0.3s |  |
| 110 | `targetPath-v5` | 12 | 15.4s |  |

## Ruffle-Matched Tests

**37 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 16.8s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.3s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.3s |  |
| 5 | `Camera-v6` | 57 | 57 | 16.0s |  |
| 6 | `Camera-v7` | 57 | 57 | 0.3s |  |
| 7 | `Camera-v8` | 57 | 57 | 0.3s |  |
| 8 | `ExternalInterface-v8` | 4 | 4 | 0.3s |  |
| 9 | `Inheritance-v5` | 1 | 17 | 0.3s |  |
| 10 | `Inheritance-v6` | 9 | 16 | 0.3s |  |
| 11 | `Inheritance-v7` | 5 | 10 | 0.3s |  |
| 12 | `Inheritance-v8` | 5 | 10 | 0.3s |  |
| 13 | `Math-v5` | 5 | 5 | 16.0s |  |
| 14 | `Math-v6` | 5 | 5 | 0.3s |  |
| 15 | `Math-v7` | 5 | 5 | 0.3s |  |
| 16 | `Math-v8` | 5 | 5 | 0.3s |  |
| 17 | `Matrix-v6` | 29 | 71 | 0.3s |  |
| 18 | `Matrix-v7` | 28 | 70 | 16.7s |  |
| 19 | `Matrix-v8` | 28 | 70 | 0.3s |  |
| 20 | `Microphone-v6` | 31 | 31 | 0.3s |  |
| 21 | `Microphone-v7` | 31 | 31 | 0.3s |  |
| 22 | `Microphone-v8` | 31 | 31 | 0.3s |  |
| 23 | `Point-v8` | 3 | 20 | 0.3s |  |
| 24 | `Rectangle-v8` | 21 | 21 | 0.3s |  |
| 25 | `Sound-v5` | 23 | 27 | 16.6s |  |
| 26 | `Sound-v6` | 30 | 51 | 0.5s |  |
| 27 | `Sound-v7` | 28 | 51 | 15.9s |  |
| 28 | `Sound-v8` | 28 | 51 | 0.4s |  |
| 29 | `case-v7` | 54 | 54 | 15.4s |  |
| 30 | `case-v8` | 54 | 54 | 0.3s |  |
| 31 | `ops-v8` | 7 | 11 | 0.3s |  |
| 32 | `targetPath-v6` | 17 | 17 | 0.3s |  |
| 33 | `targetPath-v7` | 17 | 17 | 0.3s |  |
| 34 | `targetPath-v8` | 17 | 17 | 0.3s |  |
| 35 | `toString_valueOf-v6` | 5 | 5 | 0.3s |  |
| 36 | `toString_valueOf-v7` | 5 | 5 | 16.5s |  |
| 37 | `toString_valueOf-v8` | 5 | 5 | 0.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**31 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Number-v5` | 95.1% | 232 | 244 | 12 |  |
| 2 | `Selection-v6` | 93.6% | 117 | 125 | 8 |  |
| 3 | `Selection-v7` | 93.6% | 117 | 125 | 8 |  |
| 4 | `Selection-v8` | 93.6% | 117 | 125 | 8 |  |
| 5 | `TextFieldHTML-v6` | 91.9% | 34 | 37 | 3 |  |
| 6 | `TextFieldHTML-v7` | 91.9% | 34 | 37 | 3 |  |
| 7 | `TextFieldHTML-v8` | 91.9% | 34 | 37 | 3 |  |
| 8 | `array-v5` | 91.2% | 511 | 560 | 49 |  |
| 9 | `BitmapData-v8` | 91.1% | 380 | 417 | 37 |  |
| 10 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 11 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 12 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 13 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 14 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 15 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 16 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 17 | `MovieClip-v5` | 76.0% | 276 | 363 | 87 |  |
| 18 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 19 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 20 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 21 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 22 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 23 | `toString_valueOf-v5` | 70.1% | 96 | 137 | 41 |  |
| 24 | `String-v6` | 69.8% | 263 | 377 | 114 |  |
| 25 | `String-v7` | 69.0% | 260 | 377 | 117 |  |
| 26 | `String-v8` | 69.0% | 260 | 377 | 117 |  |
| 27 | `String-v5` | 67.9% | 243 | 358 | 115 |  |
| 28 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 29 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 30 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 31 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**43 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Number-v5` | 95.1% | 232/244 | 244 | 244 |  |
| 2 | `Selection-v6` | 93.6% | 117/125 | 125 | 125 |  |
| 3 | `Selection-v7` | 93.6% | 117/125 | 125 | 125 |  |
| 4 | `Selection-v8` | 93.6% | 117/125 | 125 | 125 |  |
| 5 | `TextFieldHTML-v6` | 91.9% | 34/37 | 37 | 37 |  |
| 6 | `TextFieldHTML-v7` | 91.9% | 34/37 | 37 | 37 |  |
| 7 | `TextFieldHTML-v8` | 91.9% | 34/37 | 37 | 37 |  |
| 8 | `array-v5` | 91.2% | 511/560 | 560 | 560 |  |
| 9 | `BitmapData-v8` | 91.1% | 380/417 | 417 | 417 |  |
| 10 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 11 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 12 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 13 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 14 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 15 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 16 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 17 | `MovieClip-v5` | 76.0% | 276/363 | 350 | 363 |  |
| 18 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 19 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 20 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 21 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 22 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 23 | `toString_valueOf-v5` | 70.1% | 96/137 | 137 | 137 |  |
| 24 | `String-v6` | 69.8% | 263/377 | 377 | 377 |  |
| 25 | `String-v7` | 69.0% | 260/377 | 377 | 377 |  |
| 26 | `String-v8` | 69.0% | 260/377 | 377 | 377 |  |
| 27 | `String-v5` | 67.9% | 243/358 | 358 | 358 |  |
| 28 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 29 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 30 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 31 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 32 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 33 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 34 | `LoadVars-v6` | 40.1% | 61/152 | 139 | 152 |  |
| 35 | `LoadVars-v7` | 40.1% | 61/152 | 139 | 152 |  |
| 36 | `LoadVars-v8` | 40.1% | 61/152 | 139 | 152 |  |
| 37 | `with-v5` | 30.0% | 21/70 | 70 | 49 |  |
| 38 | `MovieClipLoader-v7` | 27.9% | 46/165 | 47 | 165 |  |
| 39 | `MovieClipLoader-v8` | 27.9% | 46/165 | 47 | 165 |  |
| 40 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 41 | `with-v6` | 19.3% | 23/119 | 119 | 107 |  |
| 42 | `with-v7` | 19.3% | 23/119 | 119 | 107 |  |
| 43 | `with-v8` | 19.3% | 23/119 | 119 | 107 |  |
