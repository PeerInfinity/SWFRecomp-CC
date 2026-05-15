# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-15 02:10 UTC

**Git SHA**: `eb8206f8aa`

**Run Duration**: 35m 0s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **127** (52.3%) |
| Ruffle-matched | 70 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **197** (81.1%) |
| Failing | 46 |
| Total expected lines | 38787 |
| Matching lines | 27666 (71.3%) |
| Mismatched lines | 11121 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 46 | 100.0% |

## Passing Tests

**127 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.9s |  |
| 2 | `Accessibility-v6` | 19 | 2.0s |  |
| 3 | `Accessibility-v7` | 19 | 1.7s |  |
| 4 | `Accessibility-v8` | 19 | 1.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.0s |  |
| 6 | `BitmapData-v5` | 7 | 1.9s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.6s |  |
| 9 | `Boolean-v5` | 38 | 2.5s |  |
| 10 | `Boolean-v6` | 38 | 2.0s |  |
| 11 | `Boolean-v7` | 38 | 19.6s |  |
| 12 | `Boolean-v8` | 38 | 1.2s |  |
| 13 | `Camera-v5` | 7 | 1.8s |  |
| 14 | `Color-v5` | 140 | 5.2s |  |
| 15 | `Color-v6` | 171 | 6.3s |  |
| 16 | `Color-v7` | 161 | 6.1s |  |
| 17 | `Color-v8` | 161 | 23.6s |  |
| 18 | `ColorTransform-v5` | 7 | 2.0s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.6s |  |
| 21 | `ColorTransform-v8` | 55 | 3.2s |  |
| 22 | `ContextMenu-v5` | 7 | 2.0s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.8s |  |
| 25 | `ContextMenu-v8` | 131 | 23.6s |  |
| 26 | `Error-v5` | 28 | 2.5s |  |
| 27 | `Error-v6` | 31 | 2.5s |  |
| 28 | `Error-v7` | 31 | 2.2s |  |
| 29 | `Error-v8` | 31 | 19.9s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.7s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.5s |  |
| 33 | `Global-v5` | 172 | 6.9s |  |
| 34 | `Global-v7` | 182 | 6.9s |  |
| 35 | `Global-v8` | 169 | 6.4s |  |
| 36 | `Instance-v5` | 52 | 3.1s |  |
| 37 | `Instance-v6` | 52 | 1.9s |  |
| 38 | `Instance-v7` | 52 | 3.0s |  |
| 39 | `Instance-v8` | 52 | 1.6s |  |
| 40 | `Key-v5` | 51 | 19.7s |  |
| 41 | `Key-v6` | 55 | 2.5s |  |
| 42 | `Key-v7` | 55 | 2.1s |  |
| 43 | `Key-v8` | 55 | 1.1s |  |
| 44 | `LoadVars-v5` | 8 | 18.9s |  |
| 45 | `LocalConnection-v5` | 7 | 20.3s |  |
| 46 | `LocalConnection-v6` | 58 | 3.2s |  |
| 47 | `LocalConnection-v7` | 58 | 2.8s |  |
| 48 | `LocalConnection-v8` | 58 | 1.3s |  |
| 49 | `Matrix-v5` | 7 | 19.3s |  |
| 50 | `Microphone-v5` | 6 | 1.9s |  |
| 51 | `Mouse-v5` | 13 | 19.6s |  |
| 52 | `Mouse-v6` | 21 | 2.2s |  |
| 53 | `Mouse-v7` | 21 | 1.8s |  |
| 54 | `Mouse-v8` | 21 | 1.4s |  |
| 55 | `MovieClipLoader-v5` | 6 | 19.3s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.6s |  |
| 57 | `NetConnection-v5` | 7 | 19.3s |  |
| 58 | `NetStream-v5` | 6 | 18.8s |  |
| 59 | `NetStream-v6` | 80 | 3.1s |  |
| 60 | `NetStream-v7` | 80 | 2.9s |  |
| 61 | `NetStream-v8` | 80 | 1.2s |  |
| 62 | `Number-v6` | 239 | 8.1s |  |
| 63 | `Number-v7` | 237 | 8.0s |  |
| 64 | `Number-v8` | 237 | 1.3s |  |
| 65 | `Point-v5` | 7 | 19.6s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.6s |  |
| 68 | `Point-v8` | 193 | 8.3s |  |
| 69 | `Random-v5` | 30 | 19.9s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.0s |  |
| 72 | `Random-v8` | 30 | 1.4s |  |
| 73 | `Rectangle-v5` | 7 | 1.9s |  |
| 74 | `Rectangle-v6` | 7 | 0.6s |  |
| 75 | `Rectangle-v7` | 7 | 1.5s |  |
| 76 | `Selection-v5` | 21 | 19.7s |  |
| 77 | `Stage-v5` | 38 | 19.6s |  |
| 78 | `System-v5` | 67 | 20.5s |  |
| 79 | `System-v6` | 100 | 3.9s |  |
| 80 | `System-v7` | 101 | 4.0s |  |
| 81 | `System-v8` | 101 | 1.4s |  |
| 82 | `TextFieldHTML-v5` | 6 | 18.7s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.4s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.2s |  |
| 86 | `TextFormat-v5` | 128 | 4.6s |  |
| 87 | `TextFormat-v6` | 128 | 0.5s |  |
| 88 | `TextSnapshot-v5` | 7 | 19.8s |  |
| 89 | `TextSnapshot-v6` | 173 | 7.4s |  |
| 90 | `TextSnapshot-v7` | 173 | 7.0s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.4s |  |
| 92 | `Transform-v5` | 7 | 1.8s |  |
| 93 | `Transform-v6` | 7 | 1.3s |  |
| 94 | `Transform-v7` | 7 | 1.4s |  |
| 95 | `Try-v5` | 20 | 20.2s |  |
| 96 | `Try-v6` | 20 | 0.6s |  |
| 97 | `Try-v7` | 20 | 2.6s |  |
| 98 | `Try-v8` | 20 | 1.4s |  |
| 99 | `Video-v5` | 7 | 19.3s |  |
| 100 | `Video-v6` | 85 | 3.4s |  |
| 101 | `Video-v7` | 85 | 3.0s |  |
| 102 | `Video-v8` | 85 | 1.4s |  |
| 103 | `XMLSocket-v5` | 35 | 20.0s |  |
| 104 | `XMLSocket-v6` | 35 | 2.4s |  |
| 105 | `XMLSocket-v7` | 35 | 2.2s |  |
| 106 | `XMLSocket-v8` | 35 | 1.5s |  |
| 107 | `argstest-v5` | 4 | 2.1s |  |
| 108 | `case-v5` | 39 | 2.4s |  |
| 109 | `case-v6` | 73 | 3.2s |  |
| 110 | `case-v7` | 67 | 3.3s |  |
| 111 | `case-v8` | 67 | 1.4s |  |
| 112 | `delete-v5` | 60 | 20.8s |  |
| 113 | `delete-v6` | 60 | 2.3s |  |
| 114 | `delete-v7` | 60 | 2.5s |  |
| 115 | `delete-v8` | 60 | 1.5s |  |
| 116 | `enumerate-v5` | 6 | 2.0s |  |
| 117 | `enumerate-v6` | 49 | 3.0s |  |
| 118 | `enumerate-v7` | 49 | 2.7s |  |
| 119 | `enumerate-v8` | 49 | 1.4s |  |
| 120 | `flash-v5` | 10 | 19.7s |  |
| 121 | `flash-v6` | 10 | 2.1s |  |
| 122 | `flash-v7` | 10 | 1.7s |  |
| 123 | `swap-v5` | 7 | 19.8s |  |
| 124 | `swap-v6` | 7 | 0.6s |  |
| 125 | `swap-v7` | 7 | 1.6s |  |
| 126 | `swap-v8` | 7 | 1.4s |  |
| 127 | `targetPath-v5` | 12 | 1.9s |  |

## Ruffle-Matched Tests

**70 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 23.3s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.4s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 23.1s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.7s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 23.8s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.9s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.5s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.4s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 4.9s |  |
| 13 | `Global-v6` | 9 | 10 | 25.3s |  |
| 14 | `HitTest-v6` | 8 | 8 | 4.7s |  |
| 15 | `HitTest-v7` | 8 | 8 | 4.3s |  |
| 16 | `HitTest-v8` | 9 | 9 | 4.3s |  |
| 17 | `Inheritance-v5` | 1 | 17 | 26.2s |  |
| 18 | `Inheritance-v6` | 9 | 16 | 7.7s |  |
| 19 | `Inheritance-v7` | 5 | 10 | 7.8s |  |
| 20 | `Inheritance-v8` | 5 | 10 | 1.9s |  |
| 21 | `LoadVars-v6` | 6 | 8 | 5.1s |  |
| 22 | `LoadVars-v7` | 6 | 8 | 4.8s |  |
| 23 | `LoadVars-v8` | 6 | 8 | 2.0s |  |
| 24 | `Math-v5` | 5 | 5 | 14.4s |  |
| 25 | `Math-v6` | 5 | 5 | 0.7s |  |
| 26 | `Math-v7` | 5 | 5 | 14.8s |  |
| 27 | `Math-v8` | 5 | 5 | 1.6s |  |
| 28 | `Matrix-v6` | 29 | 71 | 7.0s |  |
| 29 | `Matrix-v7` | 28 | 70 | 7.3s |  |
| 30 | `Matrix-v8` | 28 | 70 | 1.5s |  |
| 31 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 32 | `Microphone-v7` | 31 | 31 | 3.1s |  |
| 33 | `Microphone-v8` | 31 | 31 | 1.5s |  |
| 34 | `MovieClip-v5` | 48 | 226 | 30.5s |  |
| 35 | `MovieClipLoader-v7` | 118 | 118 | 3.8s |  |
| 36 | `MovieClipLoader-v8` | 118 | 118 | 2.4s |  |
| 37 | `Number-v5` | 8 | 13 | 8.3s |  |
| 38 | `Rectangle-v8` | 21 | 21 | 6.5s |  |
| 39 | `Selection-v6` | 7 | 13 | 5.2s |  |
| 40 | `Selection-v7` | 7 | 13 | 4.8s |  |
| 41 | `Selection-v8` | 7 | 13 | 1.5s |  |
| 42 | `Sound-v5` | 27 | 27 | 22.7s |  |
| 43 | `Sound-v6` | 30 | 51 | 5.2s |  |
| 44 | `Sound-v7` | 28 | 51 | 4.9s |  |
| 45 | `Sound-v8` | 28 | 51 | 1.9s |  |
| 46 | `String-v5` | 19 | 21 | 14.9s |  |
| 47 | `String-v6` | 10 | 10 | 15.8s |  |
| 48 | `String-v7` | 10 | 10 | 15.4s |  |
| 49 | `String-v8` | 10 | 10 | 1.6s |  |
| 50 | `TextField-v5` | 3 | 3 | 2.0s |  |
| 51 | `TextFormat-v7` | 38 | 40 | 6.1s |  |
| 52 | `ops-v5` | 7 | 9 | 27.1s |  |
| 53 | `ops-v6` | 7 | 11 | 8.5s |  |
| 54 | `ops-v7` | 7 | 11 | 9.1s |  |
| 55 | `ops-v8` | 7 | 11 | 19.0s |  |
| 56 | `setProperty-v5` | 49 | 49 | 3.0s |  |
| 57 | `setProperty-v6` | 49 | 49 | 3.0s |  |
| 58 | `setProperty-v7` | 49 | 49 | 2.6s |  |
| 59 | `setProperty-v8` | 49 | 49 | 1.6s |  |
| 60 | `targetPath-v6` | 17 | 17 | 2.1s |  |
| 61 | `targetPath-v7` | 17 | 17 | 1.7s |  |
| 62 | `targetPath-v8` | 17 | 17 | 1.2s |  |
| 63 | `toString_valueOf-v5` | 34 | 34 | 23.8s |  |
| 64 | `toString_valueOf-v6` | 5 | 5 | 6.0s |  |
| 65 | `toString_valueOf-v7` | 5 | 5 | 5.5s |  |
| 66 | `toString_valueOf-v8` | 5 | 5 | 1.4s |  |
| 67 | `with-v5` | 42 | 42 | 3.6s |  |
| 68 | `with-v6` | 91 | 91 | 5.2s |  |
| 69 | `with-v7` | 91 | 91 | 4.7s |  |
| 70 | `with-v8` | 91 | 91 | 1.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**43 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Date-v7` | 97.8% | 349 | 357 | 8 |  |
| 2 | `Date-v8` | 97.8% | 349 | 357 | 8 |  |
| 3 | `Date-v6` | 97.5% | 348 | 357 | 9 |  |
| 4 | `Date-v5` | 96.8% | 305 | 315 | 10 |  |
| 5 | `array-v5` | 95.7% | 536 | 560 | 24 |  |
| 6 | `array-v6` | 93.8% | 604 | 644 | 40 |  |
| 7 | `Object-v5` | 93.1% | 135 | 145 | 10 |  |
| 8 | `array-v7` | 89.4% | 585 | 654 | 69 |  |
| 9 | `array-v8` | 89.4% | 585 | 654 | 69 |  |
| 10 | `flash-v8` | 87.8% | 36 | 41 | 5 |  |
| 11 | `Object-v7` | 87.7% | 292 | 333 | 41 |  |
| 12 | `Object-v8` | 87.7% | 292 | 333 | 41 |  |
| 13 | `Function-v5` | 85.4% | 135 | 158 | 23 |  |
| 14 | `Stage-v6` | 84.4% | 54 | 64 | 10 |  |
| 15 | `Stage-v7` | 84.4% | 54 | 64 | 10 |  |
| 16 | `Stage-v8` | 84.4% | 54 | 64 | 10 |  |
| 17 | `XMLNode-v5` | 84.1% | 174 | 207 | 33 |  |
| 18 | `XMLNode-v6` | 84.1% | 174 | 207 | 33 |  |
| 19 | `XMLNode-v7` | 84.1% | 174 | 207 | 33 |  |
| 20 | `XMLNode-v8` | 84.1% | 174 | 207 | 33 |  |
| 21 | `Object-v6` | 83.8% | 279 | 333 | 54 |  |
| 22 | `MovieClip-v6` | 83.0% | 777 | 936 | 159 |  |
| 23 | `MovieClip-v7` | 82.4% | 798 | 969 | 171 |  |
| 24 | `MovieClip-v8` | 81.4% | 885 | 1087 | 202 |  |
| 25 | `getvariable-v7` | 76.6% | 49 | 64 | 15 |  |
| 26 | `getvariable-v8` | 76.6% | 49 | 64 | 15 |  |
| 27 | `getvariable-v5` | 75.9% | 44 | 58 | 14 |  |
| 28 | `Function-v7` | 75.4% | 205 | 272 | 67 |  |
| 29 | `Function-v8` | 75.4% | 205 | 272 | 67 |  |
| 30 | `getvariable-v6` | 75.0% | 48 | 64 | 16 |  |
| 31 | `TextFormat-v8` | 74.4% | 128 | 172 | 44 |  |
| 32 | `TextField-v6` | 74.1% | 404 | 545 | 141 |  |
| 33 | `TextField-v8` | 72.9% | 416 | 571 | 155 |  |
| 34 | `TextField-v7` | 72.6% | 414 | 570 | 156 |  |
| 35 | `Transform-v8` | 70.3% | 71 | 101 | 30 |  |
| 36 | `Function-v6` | 66.8% | 181 | 271 | 90 |  |
| 37 | `XML-v5` | 62.6% | 281 | 449 | 168 |  |
| 38 | `NetConnection-v7` | 59.5% | 75 | 126 | 51 |  |
| 39 | `NetConnection-v8` | 59.5% | 75 | 126 | 51 |  |
| 40 | `XML-v6` | 59.3% | 288 | 486 | 198 |  |
| 41 | `XML-v7` | 59.1% | 288 | 487 | 199 |  |
| 42 | `XML-v8` | 59.1% | 288 | 487 | 199 |  |
| 43 | `NetConnection-v6` | 56.3% | 71 | 126 | 55 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**46 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Date-v7` | 97.8% | 349/357 | 357 | 357 |  |
| 2 | `Date-v8` | 97.8% | 349/357 | 357 | 357 |  |
| 3 | `Date-v6` | 97.5% | 348/357 | 357 | 357 |  |
| 4 | `Date-v5` | 96.8% | 305/315 | 315 | 315 |  |
| 5 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
| 6 | `array-v6` | 93.8% | 604/644 | 644 | 644 |  |
| 7 | `Object-v5` | 93.1% | 135/145 | 145 | 145 |  |
| 8 | `array-v7` | 89.4% | 585/654 | 654 | 654 |  |
| 9 | `array-v8` | 89.4% | 585/654 | 654 | 654 |  |
| 10 | `flash-v8` | 87.8% | 36/41 | 41 | 41 |  |
| 11 | `Object-v7` | 87.7% | 292/333 | 333 | 333 |  |
| 12 | `Object-v8` | 87.7% | 292/333 | 333 | 333 |  |
| 13 | `Function-v5` | 85.4% | 135/158 | 158 | 158 |  |
| 14 | `Stage-v6` | 84.4% | 54/64 | 64 | 64 |  |
| 15 | `Stage-v7` | 84.4% | 54/64 | 64 | 64 |  |
| 16 | `Stage-v8` | 84.4% | 54/64 | 64 | 64 |  |
| 17 | `XMLNode-v5` | 84.1% | 174/207 | 207 | 207 |  |
| 18 | `XMLNode-v6` | 84.1% | 174/207 | 207 | 207 |  |
| 19 | `XMLNode-v7` | 84.1% | 174/207 | 207 | 207 |  |
| 20 | `XMLNode-v8` | 84.1% | 174/207 | 207 | 207 |  |
| 21 | `Object-v6` | 83.8% | 279/333 | 333 | 333 |  |
| 22 | `MovieClip-v6` | 83.0% | 777/936 | 921 | 936 |  |
| 23 | `MovieClip-v7` | 82.4% | 798/969 | 956 | 969 |  |
| 24 | `MovieClip-v8` | 81.4% | 885/1087 | 1074 | 1087 |  |
| 25 | `getvariable-v7` | 76.6% | 49/64 | 64 | 64 |  |
| 26 | `getvariable-v8` | 76.6% | 49/64 | 64 | 64 |  |
| 27 | `getvariable-v5` | 75.9% | 44/58 | 58 | 58 |  |
| 28 | `Function-v7` | 75.4% | 205/272 | 272 | 272 |  |
| 29 | `Function-v8` | 75.4% | 205/272 | 272 | 272 |  |
| 30 | `getvariable-v6` | 75.0% | 48/64 | 64 | 64 |  |
| 31 | `TextFormat-v8` | 74.4% | 128/172 | 172 | 172 |  |
| 32 | `TextField-v6` | 74.1% | 404/545 | 545 | 545 |  |
| 33 | `TextField-v8` | 72.9% | 416/571 | 571 | 571 |  |
| 34 | `TextField-v7` | 72.6% | 414/570 | 570 | 570 |  |
| 35 | `Transform-v8` | 70.3% | 71/101 | 101 | 101 |  |
| 36 | `Function-v6` | 66.8% | 181/271 | 271 | 271 |  |
| 37 | `XML-v5` | 62.6% | 281/449 | 419 | 449 |  |
| 38 | `NetConnection-v7` | 59.5% | 75/126 | 126 | 126 |  |
| 39 | `NetConnection-v8` | 59.5% | 75/126 | 126 | 126 |  |
| 40 | `XML-v6` | 59.3% | 288/486 | 456 | 486 |  |
| 41 | `XML-v7` | 59.1% | 288/487 | 487 | 486 |  |
| 42 | `XML-v8` | 59.1% | 288/487 | 487 | 465 |  |
| 43 | `NetConnection-v6` | 56.3% | 71/126 | 126 | 126 |  |
| 44 | `argstest-v7` | 0.5% | 46/9115 | 9115 | 2061 |  |
| 45 | `argstest-v8` | 0.5% | 46/9477 | 9477 | 2434 |  |
| 46 | `argstest-v6` | 0.5% | 44/9115 | 9115 | 2192 |  |
