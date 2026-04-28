# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-28 21:20 UTC

**Git SHA**: `7384509438`

**Run Duration**: 21m 7s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **113** (59.5%) |
| Ruffle-matched | 55 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **168** (88.4%) |
| Failing | 22 |
| Total expected lines | 16957 |
| Matching lines | 14763 (87.1%) |
| Mismatched lines | 2194 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 22 | 100.0% |

## Passing Tests

**113 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.6s |  |
| 2 | `Accessibility-v6` | 19 | 1.6s |  |
| 3 | `Accessibility-v7` | 19 | 1.3s |  |
| 4 | `Accessibility-v8` | 19 | 19.6s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.7s |  |
| 6 | `BitmapData-v5` | 7 | 1.6s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 18.4s |  |
| 9 | `Boolean-v5` | 38 | 2.1s |  |
| 10 | `Boolean-v6` | 38 | 1.6s |  |
| 11 | `Boolean-v7` | 38 | 2.1s |  |
| 12 | `Boolean-v8` | 38 | 1.0s |  |
| 13 | `Camera-v5` | 7 | 1.6s |  |
| 14 | `Color-v5` | 140 | 5.0s |  |
| 15 | `Color-v6` | 171 | 6.0s |  |
| 16 | `Color-v7` | 161 | 5.6s |  |
| 17 | `Color-v8` | 161 | 1.1s |  |
| 18 | `ColorTransform-v5` | 7 | 18.1s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.2s |  |
| 21 | `ColorTransform-v8` | 55 | 2.9s |  |
| 22 | `ContextMenu-v5` | 7 | 1.6s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `Error-v5` | 28 | 1.7s |  |
| 25 | `Error-v6` | 31 | 1.7s |  |
| 26 | `Error-v7` | 31 | 1.4s |  |
| 27 | `Error-v8` | 31 | 0.8s |  |
| 28 | `ExternalInterface-v5` | 7 | 1.3s |  |
| 29 | `Key-v5` | 51 | 2.4s |  |
| 30 | `Key-v6` | 55 | 2.5s |  |
| 31 | `Key-v7` | 55 | 2.1s |  |
| 32 | `Key-v8` | 55 | 1.0s |  |
| 33 | `LoadVars-v5` | 8 | 18.1s |  |
| 34 | `LocalConnection-v5` | 7 | 18.0s |  |
| 35 | `LocalConnection-v6` | 58 | 2.6s |  |
| 36 | `LocalConnection-v7` | 58 | 2.3s |  |
| 37 | `LocalConnection-v8` | 58 | 1.0s |  |
| 38 | `Matrix-v5` | 7 | 1.6s |  |
| 39 | `Microphone-v5` | 6 | 1.6s |  |
| 40 | `Mouse-v5` | 13 | 18.4s |  |
| 41 | `Mouse-v6` | 21 | 1.9s |  |
| 42 | `Mouse-v7` | 21 | 1.5s |  |
| 43 | `Mouse-v8` | 21 | 1.1s |  |
| 44 | `MovieClipLoader-v5` | 6 | 1.6s |  |
| 45 | `MovieClipLoader-v6` | 6 | 17.5s |  |
| 46 | `NetConnection-v5` | 7 | 17.2s |  |
| 47 | `NetStream-v5` | 6 | 1.4s |  |
| 48 | `NetStream-v6` | 80 | 2.9s |  |
| 49 | `NetStream-v7` | 80 | 19.9s |  |
| 50 | `NetStream-v8` | 80 | 1.0s |  |
| 51 | `Number-v6` | 239 | 8.1s |  |
| 52 | `Number-v7` | 237 | 8.1s |  |
| 53 | `Number-v8` | 237 | 1.1s |  |
| 54 | `Point-v5` | 7 | 19.1s |  |
| 55 | `Point-v6` | 7 | 0.6s |  |
| 56 | `Point-v7` | 7 | 1.2s |  |
| 57 | `Point-v8` | 193 | 8.1s |  |
| 58 | `Random-v5` | 30 | 2.2s |  |
| 59 | `Random-v6` | 30 | 0.6s |  |
| 60 | `Random-v7` | 30 | 18.4s |  |
| 61 | `Random-v8` | 30 | 1.0s |  |
| 62 | `Rectangle-v5` | 7 | 1.6s |  |
| 63 | `Rectangle-v6` | 7 | 0.6s |  |
| 64 | `Rectangle-v7` | 7 | 1.1s |  |
| 65 | `Selection-v5` | 21 | 18.6s |  |
| 66 | `Stage-v5` | 38 | 18.1s |  |
| 67 | `System-v5` | 67 | 3.0s |  |
| 68 | `System-v6` | 100 | 3.9s |  |
| 69 | `System-v7` | 101 | 4.1s |  |
| 70 | `System-v8` | 101 | 1.1s |  |
| 71 | `TextFieldHTML-v5` | 6 | 17.9s |  |
| 72 | `TextFieldHTML-v6` | 37 | 2.2s |  |
| 73 | `TextFieldHTML-v7` | 37 | 1.8s |  |
| 74 | `TextFieldHTML-v8` | 37 | 1.0s |  |
| 75 | `TextFormat-v5` | 128 | 4.7s |  |
| 76 | `TextFormat-v6` | 128 | 0.6s |  |
| 77 | `TextSnapshot-v5` | 7 | 1.6s |  |
| 78 | `TextSnapshot-v6` | 173 | 7.0s |  |
| 79 | `TextSnapshot-v7` | 173 | 6.7s |  |
| 80 | `TextSnapshot-v8` | 173 | 1.1s |  |
| 81 | `Transform-v5` | 7 | 1.5s |  |
| 82 | `Transform-v6` | 7 | 17.8s |  |
| 83 | `Transform-v7` | 7 | 1.1s |  |
| 84 | `Try-v5` | 20 | 2.4s |  |
| 85 | `Try-v6` | 20 | 0.5s |  |
| 86 | `Try-v7` | 20 | 2.0s |  |
| 87 | `Try-v8` | 20 | 0.9s |  |
| 88 | `Video-v5` | 7 | 18.7s |  |
| 89 | `Video-v6` | 85 | 3.2s |  |
| 90 | `Video-v7` | 85 | 2.9s |  |
| 91 | `Video-v8` | 85 | 1.1s |  |
| 92 | `XMLSocket-v5` | 35 | 19.2s |  |
| 93 | `XMLSocket-v6` | 35 | 2.3s |  |
| 94 | `XMLSocket-v7` | 35 | 19.1s |  |
| 95 | `XMLSocket-v8` | 35 | 1.2s |  |
| 96 | `argstest-v5` | 4 | 1.8s |  |
| 97 | `case-v5` | 39 | 2.3s |  |
| 98 | `delete-v5` | 60 | 2.9s |  |
| 99 | `delete-v6` | 60 | 2.3s |  |
| 100 | `delete-v7` | 60 | 2.5s |  |
| 101 | `delete-v8` | 60 | 1.2s |  |
| 102 | `enumerate-v5` | 6 | 18.2s |  |
| 103 | `enumerate-v6` | 49 | 2.6s |  |
| 104 | `enumerate-v7` | 49 | 2.3s |  |
| 105 | `enumerate-v8` | 49 | 1.1s |  |
| 106 | `flash-v5` | 10 | 1.7s |  |
| 107 | `flash-v6` | 10 | 1.6s |  |
| 108 | `flash-v7` | 10 | 18.3s |  |
| 109 | `swap-v5` | 7 | 1.6s |  |
| 110 | `swap-v6` | 7 | 0.6s |  |
| 111 | `swap-v7` | 7 | 1.2s |  |
| 112 | `swap-v8` | 7 | 1.0s |  |
| 113 | `targetPath-v5` | 12 | 18.6s |  |

## Ruffle-Matched Tests

**55 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 21.2s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.5s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.0s |  |
| 5 | `BitmapData-v8` | 8 | 13 | 23.9s |  |
| 6 | `Camera-v6` | 57 | 57 | 19.9s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.2s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.0s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 4.3s |  |
| 10 | `Inheritance-v5` | 1 | 17 | 4.5s |  |
| 11 | `Inheritance-v6` | 9 | 16 | 6.5s |  |
| 12 | `Inheritance-v7` | 5 | 10 | 6.7s |  |
| 13 | `Inheritance-v8` | 5 | 10 | 1.6s |  |
| 14 | `LoadVars-v6` | 6 | 21 | 21.7s |  |
| 15 | `LoadVars-v7` | 6 | 21 | 4.7s |  |
| 16 | `LoadVars-v8` | 6 | 21 | 1.8s |  |
| 17 | `Math-v5` | 5 | 5 | 30.4s |  |
| 18 | `Math-v6` | 5 | 5 | 0.7s |  |
| 19 | `Math-v7` | 5 | 5 | 14.4s |  |
| 20 | `Math-v8` | 5 | 5 | 1.2s |  |
| 21 | `Matrix-v6` | 29 | 71 | 7.3s |  |
| 22 | `Matrix-v7` | 28 | 70 | 23.4s |  |
| 23 | `Matrix-v8` | 28 | 70 | 1.1s |  |
| 24 | `Microphone-v6` | 31 | 31 | 3.0s |  |
| 25 | `Microphone-v7` | 31 | 31 | 2.6s |  |
| 26 | `Microphone-v8` | 31 | 31 | 1.0s |  |
| 27 | `MovieClipLoader-v7` | 118 | 118 | 3.3s |  |
| 28 | `MovieClipLoader-v8` | 118 | 118 | 2.0s |  |
| 29 | `Rectangle-v8` | 21 | 21 | 6.2s |  |
| 30 | `Selection-v6` | 7 | 13 | 4.9s |  |
| 31 | `Selection-v7` | 7 | 13 | 4.4s |  |
| 32 | `Selection-v8` | 7 | 13 | 1.1s |  |
| 33 | `Sound-v5` | 27 | 27 | 20.6s |  |
| 34 | `Sound-v6` | 30 | 51 | 4.7s |  |
| 35 | `Sound-v7` | 28 | 51 | 21.1s |  |
| 36 | `Sound-v8` | 28 | 51 | 1.4s |  |
| 37 | `String-v5` | 19 | 21 | 14.8s |  |
| 38 | `String-v6` | 10 | 10 | 15.6s |  |
| 39 | `String-v7` | 10 | 10 | 15.4s |  |
| 40 | `String-v8` | 10 | 10 | 35.2s |  |
| 41 | `TextField-v5` | 3 | 3 | 1.7s |  |
| 42 | `case-v7` | 54 | 54 | 21.0s |  |
| 43 | `case-v8` | 54 | 54 | 1.2s |  |
| 44 | `ops-v8` | 7 | 11 | 9.2s |  |
| 45 | `targetPath-v6` | 17 | 17 | 1.9s |  |
| 46 | `targetPath-v7` | 17 | 17 | 1.5s |  |
| 47 | `targetPath-v8` | 17 | 17 | 1.0s |  |
| 48 | `toString_valueOf-v5` | 34 | 34 | 4.7s |  |
| 49 | `toString_valueOf-v6` | 5 | 5 | 5.2s |  |
| 50 | `toString_valueOf-v7` | 5 | 5 | 22.4s |  |
| 51 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 52 | `with-v5` | 42 | 42 | 3.2s |  |
| 53 | `with-v6` | 91 | 91 | 4.5s |  |
| 54 | `with-v7` | 91 | 91 | 4.1s |  |
| 55 | `with-v8` | 91 | 91 | 1.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**19 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Number-v5` | 95.1% | 232 | 244 | 12 |  |
| 2 | `array-v5` | 92.3% | 517 | 560 | 43 |  |
| 3 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 4 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 5 | `HitTest-v8` | 81.8% | 72 | 88 | 16 |  |
| 6 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 7 | `HitTest-v6` | 80.7% | 71 | 88 | 17 |  |
| 8 | `HitTest-v7` | 80.7% | 71 | 88 | 17 |  |
| 9 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 10 | `MovieClip-v5` | 76.3% | 277 | 363 | 86 |  |
| 11 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 12 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 13 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 14 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 15 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 16 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 17 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 18 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 19 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**22 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Number-v5` | 95.1% | 232/244 | 244 | 244 |  |
| 2 | `array-v5` | 92.3% | 517/560 | 560 | 560 |  |
| 3 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 4 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 5 | `HitTest-v8` | 81.8% | 72/88 | 88 | 88 |  |
| 6 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 7 | `HitTest-v6` | 80.7% | 71/88 | 88 | 88 |  |
| 8 | `HitTest-v7` | 80.7% | 71/88 | 88 | 88 |  |
| 9 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 10 | `MovieClip-v5` | 76.3% | 277/363 | 350 | 363 |  |
| 11 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 12 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 13 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 14 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 15 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 16 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 17 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 18 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 19 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 20 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 21 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 22 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
