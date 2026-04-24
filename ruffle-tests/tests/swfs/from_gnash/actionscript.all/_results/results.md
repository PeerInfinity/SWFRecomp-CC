# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-24 20:40 UTC

**Git SHA**: `9d48962d4c`

**Run Duration**: 17m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **113** (59.5%) |
| Ruffle-matched | 52 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **165** (86.8%) |
| Failing | 25 |
| Total expected lines | 16957 |
| Matching lines | 14751 (87.0%) |
| Mismatched lines | 2206 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 25 | 100.0% |

## Passing Tests

**113 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.3s |  |
| 3 | `Accessibility-v7` | 19 | 0.3s |  |
| 4 | `Accessibility-v8` | 19 | 16.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.3s |  |
| 6 | `BitmapData-v5` | 7 | 0.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.3s |  |
| 8 | `BitmapData-v7` | 7 | 18.0s |  |
| 9 | `Boolean-v5` | 38 | 2.4s |  |
| 10 | `Boolean-v6` | 38 | 1.8s |  |
| 11 | `Boolean-v7` | 38 | 2.5s |  |
| 12 | `Boolean-v8` | 38 | 1.3s |  |
| 13 | `Camera-v5` | 7 | 1.3s |  |
| 14 | `Color-v5` | 140 | 5.6s |  |
| 15 | `Color-v6` | 171 | 6.8s |  |
| 16 | `Color-v7` | 161 | 6.7s |  |
| 17 | `Color-v8` | 161 | 1.4s |  |
| 18 | `ColorTransform-v5` | 7 | 17.9s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.5s |  |
| 21 | `ColorTransform-v8` | 55 | 3.2s |  |
| 22 | `ContextMenu-v5` | 7 | 1.3s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `Error-v5` | 28 | 2.2s |  |
| 25 | `Error-v6` | 31 | 2.2s |  |
| 26 | `Error-v7` | 31 | 1.9s |  |
| 27 | `Error-v8` | 31 | 1.3s |  |
| 28 | `ExternalInterface-v5` | 7 | 1.8s |  |
| 29 | `Key-v5` | 51 | 0.4s |  |
| 30 | `Key-v6` | 55 | 0.4s |  |
| 31 | `Key-v7` | 55 | 0.4s |  |
| 32 | `Key-v8` | 55 | 0.4s |  |
| 33 | `LoadVars-v5` | 8 | 19.6s |  |
| 34 | `LocalConnection-v5` | 7 | 16.3s |  |
| 35 | `LocalConnection-v6` | 58 | 0.3s |  |
| 36 | `LocalConnection-v7` | 58 | 0.3s |  |
| 37 | `LocalConnection-v8` | 58 | 0.3s |  |
| 38 | `Matrix-v5` | 7 | 0.3s |  |
| 39 | `Microphone-v5` | 6 | 1.8s |  |
| 40 | `Mouse-v5` | 13 | 19.6s |  |
| 41 | `Mouse-v6` | 21 | 2.1s |  |
| 42 | `Mouse-v7` | 21 | 1.8s |  |
| 43 | `Mouse-v8` | 21 | 1.3s |  |
| 44 | `MovieClipLoader-v5` | 6 | 2.0s |  |
| 45 | `MovieClipLoader-v6` | 6 | 19.1s |  |
| 46 | `NetConnection-v5` | 7 | 18.5s |  |
| 47 | `NetStream-v5` | 6 | 1.9s |  |
| 48 | `NetStream-v6` | 80 | 3.8s |  |
| 49 | `NetStream-v7` | 80 | 16.5s |  |
| 50 | `NetStream-v8` | 80 | 0.3s |  |
| 51 | `Number-v6` | 239 | 0.3s |  |
| 52 | `Number-v7` | 237 | 0.3s |  |
| 53 | `Number-v8` | 237 | 0.3s |  |
| 54 | `Point-v5` | 7 | 16.7s |  |
| 55 | `Point-v6` | 7 | 0.3s |  |
| 56 | `Point-v7` | 7 | 0.3s |  |
| 57 | `Point-v8` | 193 | 0.3s |  |
| 58 | `Random-v5` | 30 | 0.4s |  |
| 59 | `Random-v6` | 30 | 0.4s |  |
| 60 | `Random-v7` | 30 | 16.2s |  |
| 61 | `Random-v8` | 30 | 0.4s |  |
| 62 | `Rectangle-v5` | 7 | 0.3s |  |
| 63 | `Rectangle-v6` | 7 | 0.3s |  |
| 64 | `Rectangle-v7` | 7 | 0.3s |  |
| 65 | `Selection-v5` | 21 | 18.7s |  |
| 66 | `Stage-v5` | 38 | 20.0s |  |
| 67 | `System-v5` | 67 | 3.0s |  |
| 68 | `System-v6` | 100 | 3.7s |  |
| 69 | `System-v7` | 101 | 3.8s |  |
| 70 | `System-v8` | 101 | 1.3s |  |
| 71 | `TextFieldHTML-v5` | 6 | 16.1s |  |
| 72 | `TextFieldHTML-v6` | 37 | 0.3s |  |
| 73 | `TextFieldHTML-v7` | 37 | 0.3s |  |
| 74 | `TextFieldHTML-v8` | 37 | 0.3s |  |
| 75 | `TextFormat-v5` | 128 | 0.3s |  |
| 76 | `TextFormat-v6` | 128 | 0.3s |  |
| 77 | `TextSnapshot-v5` | 7 | 0.4s |  |
| 78 | `TextSnapshot-v6` | 173 | 0.4s |  |
| 79 | `TextSnapshot-v7` | 173 | 0.4s |  |
| 80 | `TextSnapshot-v8` | 173 | 0.4s |  |
| 81 | `Transform-v5` | 7 | 0.4s |  |
| 82 | `Transform-v6` | 7 | 17.2s |  |
| 83 | `Transform-v7` | 7 | 1.4s |  |
| 84 | `Try-v5` | 20 | 2.9s |  |
| 85 | `Try-v6` | 20 | 0.6s |  |
| 86 | `Try-v7` | 20 | 2.5s |  |
| 87 | `Try-v8` | 20 | 1.3s |  |
| 88 | `Video-v5` | 7 | 16.7s |  |
| 89 | `Video-v6` | 85 | 0.4s |  |
| 90 | `Video-v7` | 85 | 0.3s |  |
| 91 | `Video-v8` | 85 | 0.3s |  |
| 92 | `XMLSocket-v5` | 35 | 16.5s |  |
| 93 | `XMLSocket-v6` | 35 | 0.3s |  |
| 94 | `XMLSocket-v7` | 35 | 13.0s |  |
| 95 | `XMLSocket-v8` | 35 | 0.3s |  |
| 96 | `argstest-v5` | 4 | 0.3s |  |
| 97 | `case-v5` | 39 | 0.3s |  |
| 98 | `delete-v5` | 60 | 0.3s |  |
| 99 | `delete-v6` | 60 | 0.3s |  |
| 100 | `delete-v7` | 60 | 0.3s |  |
| 101 | `delete-v8` | 60 | 0.3s |  |
| 102 | `enumerate-v5` | 6 | 17.6s |  |
| 103 | `enumerate-v6` | 49 | 2.8s |  |
| 104 | `enumerate-v7` | 49 | 2.5s |  |
| 105 | `enumerate-v8` | 49 | 1.3s |  |
| 106 | `flash-v5` | 10 | 1.9s |  |
| 107 | `flash-v6` | 10 | 1.8s |  |
| 108 | `flash-v7` | 10 | 18.1s |  |
| 109 | `swap-v5` | 7 | 1.8s |  |
| 110 | `swap-v6` | 7 | 0.6s |  |
| 111 | `swap-v7` | 7 | 1.4s |  |
| 112 | `swap-v8` | 7 | 1.2s |  |
| 113 | `targetPath-v5` | 12 | 17.7s |  |

## Ruffle-Matched Tests

**52 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 16.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.3s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.3s |  |
| 5 | `BitmapData-v8` | 8 | 13 | 23.1s |  |
| 6 | `Camera-v6` | 57 | 57 | 20.6s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.6s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.3s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 4.5s |  |
| 10 | `Inheritance-v5` | 1 | 17 | 0.4s |  |
| 11 | `Inheritance-v6` | 9 | 16 | 0.4s |  |
| 12 | `Inheritance-v7` | 5 | 10 | 0.4s |  |
| 13 | `Inheritance-v8` | 5 | 10 | 0.4s |  |
| 14 | `LoadVars-v6` | 6 | 21 | 16.5s |  |
| 15 | `LoadVars-v7` | 6 | 21 | 0.3s |  |
| 16 | `LoadVars-v8` | 6 | 21 | 0.3s |  |
| 17 | `Math-v5` | 5 | 5 | 16.8s |  |
| 18 | `Math-v6` | 5 | 5 | 0.4s |  |
| 19 | `Math-v7` | 5 | 5 | 0.4s |  |
| 20 | `Math-v8` | 5 | 5 | 0.4s |  |
| 21 | `Matrix-v6` | 29 | 71 | 0.4s |  |
| 22 | `Matrix-v7` | 28 | 70 | 23.3s |  |
| 23 | `Matrix-v8` | 28 | 70 | 1.4s |  |
| 24 | `Microphone-v6` | 31 | 31 | 3.3s |  |
| 25 | `Microphone-v7` | 31 | 31 | 2.8s |  |
| 26 | `Microphone-v8` | 31 | 31 | 1.3s |  |
| 27 | `MovieClipLoader-v7` | 118 | 118 | 3.9s |  |
| 28 | `MovieClipLoader-v8` | 118 | 118 | 2.4s |  |
| 29 | `Rectangle-v8` | 21 | 21 | 0.3s |  |
| 30 | `Sound-v5` | 27 | 27 | 21.6s |  |
| 31 | `Sound-v6` | 30 | 51 | 4.9s |  |
| 32 | `Sound-v7` | 28 | 51 | 23.5s |  |
| 33 | `Sound-v8` | 28 | 51 | 1.8s |  |
| 34 | `String-v5` | 19 | 21 | 16.2s |  |
| 35 | `String-v6` | 10 | 10 | 17.0s |  |
| 36 | `String-v7` | 10 | 10 | 16.8s |  |
| 37 | `String-v8` | 10 | 10 | 31.6s |  |
| 38 | `TextField-v5` | 3 | 3 | 1.9s |  |
| 39 | `case-v7` | 54 | 54 | 16.1s |  |
| 40 | `case-v8` | 54 | 54 | 0.3s |  |
| 41 | `ops-v8` | 7 | 11 | 9.3s |  |
| 42 | `targetPath-v6` | 17 | 17 | 2.1s |  |
| 43 | `targetPath-v7` | 17 | 17 | 1.7s |  |
| 44 | `targetPath-v8` | 17 | 17 | 1.2s |  |
| 45 | `toString_valueOf-v5` | 34 | 34 | 4.8s |  |
| 46 | `toString_valueOf-v6` | 5 | 5 | 5.2s |  |
| 47 | `toString_valueOf-v7` | 5 | 5 | 21.7s |  |
| 48 | `toString_valueOf-v8` | 5 | 5 | 1.3s |  |
| 49 | `with-v5` | 42 | 42 | 3.4s |  |
| 50 | `with-v6` | 91 | 91 | 4.5s |  |
| 51 | `with-v7` | 91 | 91 | 4.2s |  |
| 52 | `with-v8` | 91 | 91 | 1.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**22 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Number-v5` | 95.1% | 232 | 244 | 12 |  |
| 2 | `Selection-v6` | 93.6% | 117 | 125 | 8 |  |
| 3 | `Selection-v7` | 93.6% | 117 | 125 | 8 |  |
| 4 | `Selection-v8` | 93.6% | 117 | 125 | 8 |  |
| 5 | `array-v5` | 91.4% | 512 | 560 | 48 |  |
| 6 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 7 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 8 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 9 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 10 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 11 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 12 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 13 | `MovieClip-v5` | 76.0% | 276 | 363 | 87 |  |
| 14 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 15 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 16 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 17 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 18 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 19 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 20 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 21 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 22 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**25 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Number-v5` | 95.1% | 232/244 | 244 | 244 |  |
| 2 | `Selection-v6` | 93.6% | 117/125 | 125 | 125 |  |
| 3 | `Selection-v7` | 93.6% | 117/125 | 125 | 125 |  |
| 4 | `Selection-v8` | 93.6% | 117/125 | 125 | 125 |  |
| 5 | `array-v5` | 91.4% | 512/560 | 560 | 560 |  |
| 6 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 7 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 8 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 9 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 10 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 11 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 12 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 13 | `MovieClip-v5` | 76.0% | 276/363 | 350 | 363 |  |
| 14 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 15 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 16 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 17 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 18 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 19 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 20 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 21 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 22 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 23 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 24 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 25 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
