# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-21 03:00 UTC

**Git SHA**: `ec66bc3379`

**Run Duration**: 19m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **109** (57.4%) |
| Ruffle-matched | 43 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **152** (80.0%) |
| Failing | 38 |
| Total expected lines | 16957 |
| Matching lines | 14325 (84.5%) |
| Mismatched lines | 2632 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 38 | 100.0% |

## Passing Tests

**109 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.5s |  |
| 2 | `Accessibility-v6` | 19 | 1.6s |  |
| 3 | `Accessibility-v7` | 19 | 1.2s |  |
| 4 | `Accessibility-v8` | 19 | 17.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.4s |  |
| 6 | `BitmapData-v5` | 7 | 1.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.5s |  |
| 8 | `BitmapData-v7` | 7 | 17.0s |  |
| 9 | `Boolean-v5` | 38 | 1.9s |  |
| 10 | `Boolean-v6` | 38 | 1.3s |  |
| 11 | `Boolean-v7` | 38 | 1.9s |  |
| 12 | `Boolean-v8` | 38 | 0.8s |  |
| 13 | `Camera-v5` | 7 | 1.3s |  |
| 14 | `Color-v5` | 140 | 5.2s |  |
| 15 | `Color-v6` | 171 | 6.3s |  |
| 16 | `Color-v7` | 161 | 6.0s |  |
| 17 | `Color-v8` | 161 | 0.9s |  |
| 18 | `ColorTransform-v5` | 7 | 17.9s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.0s |  |
| 21 | `ColorTransform-v8` | 55 | 2.7s |  |
| 22 | `ContextMenu-v5` | 7 | 1.4s |  |
| 23 | `ContextMenu-v6` | 7 | 0.5s |  |
| 24 | `Error-v5` | 28 | 1.8s |  |
| 25 | `Error-v6` | 31 | 1.8s |  |
| 26 | `Error-v7` | 31 | 1.4s |  |
| 27 | `Error-v8` | 31 | 0.8s |  |
| 28 | `ExternalInterface-v5` | 7 | 1.4s |  |
| 29 | `Key-v5` | 51 | 2.1s |  |
| 30 | `Key-v6` | 55 | 2.2s |  |
| 31 | `Key-v7` | 55 | 1.8s |  |
| 32 | `Key-v8` | 55 | 0.8s |  |
| 33 | `LoadVars-v5` | 8 | 17.2s |  |
| 34 | `LocalConnection-v5` | 7 | 18.6s |  |
| 35 | `LocalConnection-v6` | 58 | 2.7s |  |
| 36 | `LocalConnection-v7` | 58 | 2.2s |  |
| 37 | `LocalConnection-v8` | 58 | 0.8s |  |
| 38 | `Matrix-v5` | 7 | 1.0s |  |
| 39 | `Microphone-v5` | 6 | 1.4s |  |
| 40 | `Mouse-v5` | 13 | 18.4s |  |
| 41 | `Mouse-v6` | 21 | 1.6s |  |
| 42 | `Mouse-v7` | 21 | 1.3s |  |
| 43 | `Mouse-v8` | 21 | 0.8s |  |
| 44 | `MovieClipLoader-v5` | 6 | 1.4s |  |
| 45 | `MovieClipLoader-v6` | 6 | 17.5s |  |
| 46 | `NetConnection-v5` | 7 | 17.3s |  |
| 47 | `NetStream-v5` | 6 | 1.3s |  |
| 48 | `NetStream-v6` | 80 | 3.0s |  |
| 49 | `NetStream-v7` | 80 | 19.4s |  |
| 50 | `NetStream-v8` | 80 | 0.8s |  |
| 51 | `Number-v6` | 239 | 8.5s |  |
| 52 | `Number-v7` | 237 | 8.3s |  |
| 53 | `Number-v8` | 237 | 0.9s |  |
| 54 | `Point-v5` | 7 | 17.1s |  |
| 55 | `Point-v6` | 7 | 0.5s |  |
| 56 | `Point-v7` | 7 | 1.0s |  |
| 57 | `Random-v5` | 30 | 1.8s |  |
| 58 | `Random-v6` | 30 | 0.6s |  |
| 59 | `Random-v7` | 30 | 18.0s |  |
| 60 | `Random-v8` | 30 | 0.8s |  |
| 61 | `Rectangle-v5` | 7 | 1.3s |  |
| 62 | `Rectangle-v6` | 7 | 0.5s |  |
| 63 | `Rectangle-v7` | 7 | 0.9s |  |
| 64 | `Selection-v5` | 21 | 15.8s |  |
| 65 | `Stage-v5` | 38 | 17.6s |  |
| 66 | `System-v5` | 67 | 2.0s |  |
| 67 | `System-v6` | 100 | 2.8s |  |
| 68 | `System-v7` | 101 | 2.8s |  |
| 69 | `System-v8` | 101 | 0.6s |  |
| 70 | `TextFieldHTML-v5` | 6 | 17.6s |  |
| 71 | `TextFormat-v5` | 128 | 4.4s |  |
| 72 | `TextFormat-v6` | 128 | 0.5s |  |
| 73 | `TextSnapshot-v5` | 7 | 1.3s |  |
| 74 | `TextSnapshot-v6` | 173 | 7.1s |  |
| 75 | `TextSnapshot-v7` | 173 | 6.8s |  |
| 76 | `TextSnapshot-v8` | 173 | 0.9s |  |
| 77 | `Transform-v5` | 7 | 1.3s |  |
| 78 | `Transform-v6` | 7 | 17.0s |  |
| 79 | `Transform-v7` | 7 | 1.0s |  |
| 80 | `Try-v5` | 20 | 2.4s |  |
| 81 | `Try-v6` | 20 | 0.5s |  |
| 82 | `Try-v7` | 20 | 2.0s |  |
| 83 | `Try-v8` | 20 | 0.8s |  |
| 84 | `Video-v5` | 7 | 17.8s |  |
| 85 | `Video-v6` | 85 | 3.0s |  |
| 86 | `Video-v7` | 85 | 2.6s |  |
| 87 | `Video-v8` | 85 | 0.8s |  |
| 88 | `XMLSocket-v5` | 35 | 18.4s |  |
| 89 | `XMLSocket-v6` | 35 | 2.0s |  |
| 90 | `XMLSocket-v7` | 35 | 17.5s |  |
| 91 | `XMLSocket-v8` | 35 | 0.8s |  |
| 92 | `argstest-v5` | 4 | 1.4s |  |
| 93 | `case-v5` | 39 | 1.9s |  |
| 94 | `delete-v5` | 60 | 2.4s |  |
| 95 | `delete-v6` | 60 | 1.8s |  |
| 96 | `delete-v7` | 60 | 2.0s |  |
| 97 | `delete-v8` | 60 | 0.9s |  |
| 98 | `enumerate-v5` | 6 | 18.2s |  |
| 99 | `enumerate-v6` | 49 | 2.7s |  |
| 100 | `enumerate-v7` | 49 | 2.2s |  |
| 101 | `enumerate-v8` | 49 | 0.9s |  |
| 102 | `flash-v5` | 10 | 1.4s |  |
| 103 | `flash-v6` | 10 | 1.4s |  |
| 104 | `flash-v7` | 10 | 16.9s |  |
| 105 | `swap-v5` | 7 | 1.3s |  |
| 106 | `swap-v6` | 7 | 0.5s |  |
| 107 | `swap-v7` | 7 | 0.9s |  |
| 108 | `swap-v8` | 7 | 0.7s |  |
| 109 | `targetPath-v5` | 12 | 15.9s |  |

## Ruffle-Matched Tests

**43 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 21.4s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.7s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.9s |  |
| 5 | `BitmapData-v8` | 8 | 13 | 22.6s |  |
| 6 | `Camera-v6` | 57 | 57 | 21.5s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.4s |  |
| 8 | `Camera-v8` | 57 | 57 | 0.9s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 4.4s |  |
| 10 | `Inheritance-v5` | 1 | 17 | 3.9s |  |
| 11 | `Inheritance-v6` | 9 | 16 | 5.7s |  |
| 12 | `Inheritance-v7` | 5 | 10 | 5.8s |  |
| 13 | `Inheritance-v8` | 5 | 10 | 1.3s |  |
| 14 | `Math-v5` | 5 | 5 | 23.2s |  |
| 15 | `Math-v6` | 5 | 5 | 0.5s |  |
| 16 | `Math-v7` | 5 | 5 | 11.2s |  |
| 17 | `Math-v8` | 5 | 5 | 0.7s |  |
| 18 | `Matrix-v6` | 29 | 71 | 5.5s |  |
| 19 | `Matrix-v7` | 28 | 70 | 23.9s |  |
| 20 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 21 | `Microphone-v6` | 31 | 31 | 2.9s |  |
| 22 | `Microphone-v7` | 31 | 31 | 2.5s |  |
| 23 | `Microphone-v8` | 31 | 31 | 0.8s |  |
| 24 | `MovieClipLoader-v7` | 118 | 118 | 3.3s |  |
| 25 | `MovieClipLoader-v8` | 118 | 118 | 1.9s |  |
| 26 | `Point-v8` | 3 | 20 | 7.1s |  |
| 27 | `Rectangle-v8` | 21 | 21 | 6.0s |  |
| 28 | `Sound-v5` | 27 | 27 | 18.1s |  |
| 29 | `Sound-v6` | 30 | 51 | 4.0s |  |
| 30 | `Sound-v7` | 28 | 51 | 20.1s |  |
| 31 | `Sound-v8` | 28 | 51 | 1.1s |  |
| 32 | `TextField-v5` | 3 | 3 | 1.1s |  |
| 33 | `case-v7` | 54 | 54 | 18.7s |  |
| 34 | `case-v8` | 54 | 54 | 0.9s |  |
| 35 | `ops-v8` | 7 | 11 | 8.5s |  |
| 36 | `targetPath-v6` | 17 | 17 | 1.5s |  |
| 37 | `targetPath-v7` | 17 | 17 | 1.2s |  |
| 38 | `targetPath-v8` | 17 | 17 | 0.7s |  |
| 39 | `toString_valueOf-v5` | 34 | 34 | 4.0s |  |
| 40 | `toString_valueOf-v6` | 5 | 5 | 4.4s |  |
| 41 | `toString_valueOf-v7` | 5 | 5 | 20.2s |  |
| 42 | `toString_valueOf-v8` | 5 | 5 | 0.9s |  |
| 43 | `with-v5` | 42 | 42 | 2.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**32 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `LoadVars-v6` | 95.4% | 146 | 153 | 7 |  |
| 2 | `LoadVars-v7` | 95.4% | 146 | 153 | 7 |  |
| 3 | `LoadVars-v8` | 95.4% | 146 | 153 | 7 |  |
| 4 | `Number-v5` | 95.1% | 232 | 244 | 12 |  |
| 5 | `Selection-v6` | 93.6% | 117 | 125 | 8 |  |
| 6 | `Selection-v7` | 93.6% | 117 | 125 | 8 |  |
| 7 | `Selection-v8` | 93.6% | 117 | 125 | 8 |  |
| 8 | `TextFieldHTML-v6` | 91.9% | 34 | 37 | 3 |  |
| 9 | `TextFieldHTML-v7` | 91.9% | 34 | 37 | 3 |  |
| 10 | `TextFieldHTML-v8` | 91.9% | 34 | 37 | 3 |  |
| 11 | `array-v5` | 91.4% | 512 | 560 | 48 |  |
| 12 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 13 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 14 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 15 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 16 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 17 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 18 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 19 | `MovieClip-v5` | 76.0% | 276 | 363 | 87 |  |
| 20 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 21 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 22 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 23 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 24 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 25 | `String-v6` | 69.8% | 263 | 377 | 114 |  |
| 26 | `String-v7` | 69.0% | 260 | 377 | 117 |  |
| 27 | `String-v8` | 69.0% | 260 | 377 | 117 |  |
| 28 | `String-v5` | 67.9% | 243 | 358 | 115 |  |
| 29 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 30 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 31 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 32 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**38 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `LoadVars-v6` | 95.4% | 146/153 | 153 | 152 |  |
| 2 | `LoadVars-v7` | 95.4% | 146/153 | 153 | 152 |  |
| 3 | `LoadVars-v8` | 95.4% | 146/153 | 153 | 152 |  |
| 4 | `Number-v5` | 95.1% | 232/244 | 244 | 244 |  |
| 5 | `Selection-v6` | 93.6% | 117/125 | 125 | 125 |  |
| 6 | `Selection-v7` | 93.6% | 117/125 | 125 | 125 |  |
| 7 | `Selection-v8` | 93.6% | 117/125 | 125 | 125 |  |
| 8 | `TextFieldHTML-v6` | 91.9% | 34/37 | 37 | 37 |  |
| 9 | `TextFieldHTML-v7` | 91.9% | 34/37 | 37 | 37 |  |
| 10 | `TextFieldHTML-v8` | 91.9% | 34/37 | 37 | 37 |  |
| 11 | `array-v5` | 91.4% | 512/560 | 560 | 560 |  |
| 12 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 13 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 14 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 15 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 16 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 17 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 18 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 19 | `MovieClip-v5` | 76.0% | 276/363 | 350 | 363 |  |
| 20 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 21 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 22 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 23 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 24 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 25 | `String-v6` | 69.8% | 263/377 | 377 | 377 |  |
| 26 | `String-v7` | 69.0% | 260/377 | 377 | 377 |  |
| 27 | `String-v8` | 69.0% | 260/377 | 377 | 377 |  |
| 28 | `String-v5` | 67.9% | 243/358 | 358 | 358 |  |
| 29 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 30 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 31 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 32 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 33 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 34 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 35 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 36 | `with-v6` | 19.3% | 23/119 | 119 | 107 |  |
| 37 | `with-v7` | 19.3% | 23/119 | 119 | 107 |  |
| 38 | `with-v8` | 19.3% | 23/119 | 119 | 107 |  |
