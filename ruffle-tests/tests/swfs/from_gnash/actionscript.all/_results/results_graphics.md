# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-19 13:54 UTC

**Git SHA**: `9d038c750e`

**Run Duration**: 39m 33s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 235 |
| Passing | **131** (55.7%) |
| Ruffle-matched | 91 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **222** (94.5%) |
| Failing | 13 |
| Total expected lines | 38484 |
| Matching lines | 30100 (78.2%) |
| Mismatched lines | 8384 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**131 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.2s |  |
| 2 | `Accessibility-v6` | 19 | 3.2s |  |
| 3 | `Accessibility-v7` | 19 | 2.9s |  |
| 4 | `Accessibility-v8` | 19 | 2.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.0s |  |
| 6 | `BitmapData-v5` | 7 | 3.0s |  |
| 7 | `BitmapData-v6` | 7 | 1.4s |  |
| 8 | `BitmapData-v7` | 7 | 2.6s |  |
| 9 | `Boolean-v5` | 38 | 3.5s |  |
| 10 | `Boolean-v6` | 38 | 2.9s |  |
| 11 | `Boolean-v7` | 38 | 22.7s |  |
| 12 | `Boolean-v8` | 38 | 2.3s |  |
| 13 | `Camera-v5` | 7 | 2.7s |  |
| 14 | `Color-v5` | 140 | 6.4s |  |
| 15 | `Color-v6` | 171 | 7.5s |  |
| 16 | `Color-v7` | 161 | 7.2s |  |
| 17 | `Color-v8` | 161 | 27.9s |  |
| 18 | `ColorTransform-v5` | 7 | 3.1s |  |
| 19 | `ColorTransform-v6` | 7 | 1.4s |  |
| 20 | `ColorTransform-v7` | 7 | 2.7s |  |
| 21 | `ColorTransform-v8` | 55 | 4.4s |  |
| 22 | `ContextMenu-v5` | 7 | 3.0s |  |
| 23 | `ContextMenu-v6` | 7 | 1.4s |  |
| 24 | `ContextMenu-v7` | 131 | 6.2s |  |
| 25 | `ContextMenu-v8` | 131 | 25.5s |  |
| 26 | `Error-v5` | 28 | 3.3s |  |
| 27 | `Error-v6` | 31 | 3.4s |  |
| 28 | `Error-v7` | 31 | 3.0s |  |
| 29 | `Error-v8` | 31 | 23.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.9s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.8s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.3s |  |
| 33 | `Global-v5` | 172 | 7.8s |  |
| 34 | `Global-v7` | 182 | 8.1s |  |
| 35 | `Global-v8` | 169 | 7.7s |  |
| 36 | `Instance-v5` | 52 | 3.6s |  |
| 37 | `Instance-v6` | 52 | 2.2s |  |
| 38 | `Instance-v7` | 52 | 3.2s |  |
| 39 | `Instance-v8` | 52 | 2.2s |  |
| 40 | `Key-v5` | 51 | 18.1s |  |
| 41 | `Key-v6` | 55 | 3.1s |  |
| 42 | `Key-v7` | 55 | 2.8s |  |
| 43 | `Key-v8` | 55 | 1.9s |  |
| 44 | `LoadVars-v5` | 8 | 17.4s |  |
| 45 | `LocalConnection-v5` | 7 | 22.0s |  |
| 46 | `LocalConnection-v6` | 58 | 4.1s |  |
| 47 | `LocalConnection-v7` | 58 | 3.7s |  |
| 48 | `LocalConnection-v8` | 58 | 2.4s |  |
| 49 | `Matrix-v5` | 7 | 22.3s |  |
| 50 | `Microphone-v5` | 6 | 2.9s |  |
| 51 | `Mouse-v5` | 13 | 22.3s |  |
| 52 | `Mouse-v6` | 21 | 3.2s |  |
| 53 | `Mouse-v7` | 21 | 2.8s |  |
| 54 | `Mouse-v8` | 21 | 2.4s |  |
| 55 | `MovieClipLoader-v5` | 6 | 22.4s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.4s |  |
| 57 | `NetConnection-v5` | 7 | 21.8s |  |
| 58 | `NetStream-v5` | 6 | 23.2s |  |
| 59 | `NetStream-v6` | 80 | 5.0s |  |
| 60 | `NetStream-v7` | 80 | 4.6s |  |
| 61 | `NetStream-v8` | 80 | 2.6s |  |
| 62 | `Number-v6` | 239 | 10.5s |  |
| 63 | `Number-v7` | 237 | 10.5s |  |
| 64 | `Number-v8` | 237 | 2.7s |  |
| 65 | `Point-v5` | 7 | 23.0s |  |
| 66 | `Point-v6` | 7 | 1.4s |  |
| 67 | `Point-v7` | 7 | 2.7s |  |
| 68 | `Point-v8` | 193 | 9.8s |  |
| 69 | `Selection-v5` | 21 | 19.0s |  |
| 70 | `Sound-v6` | 121 | 5.7s |  |
| 71 | `Sound-v7` | 121 | 5.3s |  |
| 72 | `Sound-v8` | 121 | 2.4s |  |
| 73 | `Stage-v5` | 38 | 22.9s |  |
| 74 | `System-v5` | 67 | 23.8s |  |
| 75 | `System-v6` | 100 | 4.8s |  |
| 76 | `System-v7` | 101 | 4.8s |  |
| 77 | `System-v8` | 101 | 2.2s |  |
| 78 | `TextFieldHTML-v5` | 6 | 21.6s |  |
| 79 | `TextFieldHTML-v6` | 37 | 3.4s |  |
| 80 | `TextFieldHTML-v7` | 37 | 3.1s |  |
| 81 | `TextFieldHTML-v8` | 37 | 2.3s |  |
| 82 | `TextFormat-v5` | 128 | 5.8s |  |
| 83 | `TextFormat-v6` | 128 | 1.3s |  |
| 84 | `TextSnapshot-v5` | 7 | 22.8s |  |
| 85 | `TextSnapshot-v6` | 173 | 9.7s |  |
| 86 | `TextSnapshot-v7` | 173 | 9.1s |  |
| 87 | `TextSnapshot-v8` | 173 | 2.6s |  |
| 88 | `Transform-v5` | 7 | 3.0s |  |
| 89 | `Transform-v6` | 7 | 2.5s |  |
| 90 | `Transform-v7` | 7 | 2.6s |  |
| 91 | `Try-v5` | 20 | 23.2s |  |
| 92 | `Try-v6` | 20 | 1.4s |  |
| 93 | `Try-v7` | 20 | 3.5s |  |
| 94 | `Try-v8` | 20 | 2.5s |  |
| 95 | `Video-v5` | 7 | 22.8s |  |
| 96 | `Video-v6` | 85 | 4.8s |  |
| 97 | `Video-v7` | 85 | 4.5s |  |
| 98 | `Video-v8` | 85 | 2.5s |  |
| 99 | `XMLSocket-v5` | 35 | 22.2s |  |
| 100 | `XMLSocket-v6` | 35 | 3.5s |  |
| 101 | `XMLSocket-v7` | 35 | 3.2s |  |
| 102 | `XMLSocket-v8` | 35 | 2.4s |  |
| 103 | `argstest-v5` | 4 | 3.0s |  |
| 104 | `case-v5` | 39 | 3.5s |  |
| 105 | `case-v6` | 73 | 4.4s |  |
| 106 | `case-v7` | 67 | 4.3s |  |
| 107 | `case-v8` | 67 | 2.4s |  |
| 108 | `delete-v5` | 61 | 3.9s |  |
| 109 | `delete-v6` | 61 | 3.3s |  |
| 110 | `delete-v7` | 61 | 3.6s |  |
| 111 | `delete-v8` | 61 | 2.4s |  |
| 112 | `enumerate-v5` | 6 | 2.8s |  |
| 113 | `enumerate-v6` | 49 | 3.9s |  |
| 114 | `enumerate-v7` | 49 | 3.6s |  |
| 115 | `enumerate-v8` | 49 | 2.3s |  |
| 116 | `flash-v5` | 10 | 21.1s |  |
| 117 | `flash-v6` | 10 | 2.7s |  |
| 118 | `flash-v7` | 10 | 2.4s |  |
| 119 | `flash-v8` | 41 | 22.1s |  |
| 120 | `getvariable-v5` | 58 | 3.9s |  |
| 121 | `getvariable-v6` | 64 | 4.0s |  |
| 122 | `getvariable-v7` | 64 | 4.0s |  |
| 123 | `getvariable-v8` | 64 | 2.3s |  |
| 124 | `swap-v5` | 7 | 22.8s |  |
| 125 | `swap-v6` | 7 | 1.3s |  |
| 126 | `swap-v7` | 7 | 2.4s |  |
| 127 | `swap-v8` | 7 | 2.2s |  |
| 128 | `targetPath-v5` | 12 | 2.9s |  |
| 129 | `targetPath-v6` | 23 | 3.1s |  |
| 130 | `targetPath-v7` | 23 | 2.7s |  |
| 131 | `targetPath-v8` | 23 | 2.2s |  |

## Ruffle-Matched Tests

**91 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 26.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 7.0s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.7s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.6s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 25.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 6.1s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.6s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 5.0s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.6s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.3s |  |
| 12 | `Date-v5` | 7 | 7 | 34.0s |  |
| 13 | `Date-v6` | 6 | 6 | 16.1s |  |
| 14 | `Date-v7` | 6 | 6 | 16.4s |  |
| 15 | `Date-v8` | 6 | 6 | 2.9s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.8s |  |
| 17 | `Function-v5` | 14 | 24 | 25.5s |  |
| 18 | `Function-v6` | 8 | 33 | 10.5s |  |
| 19 | `Function-v7` | 8 | 33 | 10.7s |  |
| 20 | `Function-v8` | 8 | 33 | 29.6s |  |
| 21 | `Global-v6` | 9 | 10 | 27.8s |  |
| 22 | `HitTest-v6` | 8 | 8 | 6.1s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.9s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.5s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 23.7s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.4s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.8s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 5.4s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.2s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.6s |  |
| 32 | `Math-v5` | 5 | 5 | 14.6s |  |
| 33 | `Math-v6` | 5 | 5 | 1.4s |  |
| 34 | `Math-v7` | 5 | 5 | 14.8s |  |
| 35 | `Math-v8` | 5 | 5 | 2.6s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.5s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.3s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.5s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.4s |  |
| 40 | `Microphone-v7` | 31 | 31 | 4.1s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.3s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 33.9s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 5.1s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.5s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.8s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 6.1s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.5s |  |
| 48 | `Number-v5` | 8 | 12 | 11.0s |  |
| 49 | `Object-v5` | 3 | 6 | 27.4s |  |
| 50 | `Object-v6` | 8 | 24 | 14.8s |  |
| 51 | `Object-v7` | 8 | 15 | 14.9s |  |
| 52 | `Object-v8` | 8 | 15 | 3.4s |  |
| 53 | `Selection-v6` | 7 | 13 | 5.7s |  |
| 54 | `Selection-v7` | 7 | 13 | 5.5s |  |
| 55 | `Selection-v8` | 7 | 13 | 2.1s |  |
| 56 | `Sound-v5` | 14 | 16 | 22.1s |  |
| 57 | `Stage-v6` | 14 | 14 | 23.9s |  |
| 58 | `Stage-v7` | 14 | 14 | 3.8s |  |
| 59 | `Stage-v8` | 14 | 14 | 2.6s |  |
| 60 | `String-v5` | 19 | 21 | 17.8s |  |
| 61 | `String-v6` | 10 | 10 | 18.8s |  |
| 62 | `String-v7` | 10 | 10 | 18.6s |  |
| 63 | `String-v8` | 10 | 10 | 3.0s |  |
| 64 | `TextField-v5` | 3 | 3 | 2.7s |  |
| 65 | `TextFormat-v7` | 38 | 40 | 7.5s |  |
| 66 | `TextFormat-v8` | 36 | 38 | 26.0s |  |
| 67 | `Transform-v8` | 7 | 11 | 26.5s |  |
| 68 | `XML-v5` | 10 | 79 | 36.6s |  |
| 69 | `XML-v6` | 3 | 98 | 18.1s |  |
| 70 | `XML-v7` | 3 | 98 | 18.1s |  |
| 71 | `XML-v8` | 24 | 116 | 6.1s |  |
| 72 | `XMLNode-v5` | 3 | 22 | 10.2s |  |
| 73 | `XMLNode-v6` | 3 | 22 | 10.2s |  |
| 74 | `XMLNode-v7` | 3 | 22 | 9.0s |  |
| 75 | `XMLNode-v8` | 3 | 22 | 2.7s |  |
| 76 | `ops-v5` | 7 | 9 | 30.2s |  |
| 77 | `ops-v6` | 7 | 11 | 10.0s |  |
| 78 | `ops-v7` | 7 | 11 | 10.6s |  |
| 79 | `ops-v8` | 7 | 11 | 22.6s |  |
| 80 | `setProperty-v5` | 49 | 49 | 4.0s |  |
| 81 | `setProperty-v6` | 49 | 49 | 3.8s |  |
| 82 | `setProperty-v7` | 49 | 49 | 3.5s |  |
| 83 | `setProperty-v8` | 49 | 49 | 2.6s |  |
| 84 | `toString_valueOf-v5` | 34 | 34 | 25.8s |  |
| 85 | `toString_valueOf-v6` | 5 | 5 | 6.7s |  |
| 86 | `toString_valueOf-v7` | 5 | 5 | 6.4s |  |
| 87 | `toString_valueOf-v8` | 5 | 5 | 2.6s |  |
| 88 | `with-v5` | 3 | 3 | 4.7s |  |
| 89 | `with-v6` | 6 | 9 | 5.9s |  |
| 90 | `with-v7` | 6 | 9 | 5.6s |  |
| 91 | `with-v8` | 6 | 9 | 2.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 98.4% | 551 | 560 | 9 |  |
| 2 | `array-v6` | 96.7% | 623 | 644 | 21 |  |
| 3 | `MovieClip-v7` | 96.4% | 934 | 969 | 35 |  |
| 4 | `MovieClip-v6` | 96.3% | 901 | 936 | 35 |  |
| 5 | `MovieClip-v8` | 93.8% | 1020 | 1087 | 67 |  |
| 6 | `array-v7` | 92.4% | 604 | 654 | 50 |  |
| 7 | `array-v8` | 92.4% | 604 | 654 | 50 |  |
| 8 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 9 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 10 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 98.4% | 551/560 | 560 | 560 |  |
| 2 | `array-v6` | 96.7% | 623/644 | 644 | 644 |  |
| 3 | `MovieClip-v7` | 96.4% | 934/969 | 954 | 969 |  |
| 4 | `MovieClip-v6` | 96.3% | 901/936 | 921 | 936 |  |
| 5 | `MovieClip-v8` | 93.8% | 1020/1087 | 1072 | 1087 |  |
| 6 | `array-v7` | 92.4% | 604/654 | 654 | 654 |  |
| 7 | `array-v8` | 92.4% | 604/654 | 654 | 654 |  |
| 8 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 9 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 10 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 11 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 12 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 13 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
