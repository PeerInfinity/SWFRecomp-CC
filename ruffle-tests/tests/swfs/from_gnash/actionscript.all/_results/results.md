# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 14:22 UTC

**Git SHA**: `027418adc4`

**Run Duration**: 31m 1s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **138** (56.8%) |
| Ruffle-matched | 89 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **227** (93.4%) |
| Failing | 16 |
| Total expected lines | 38791 |
| Matching lines | 30386 (78.3%) |
| Mismatched lines | 8405 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 100.0% |

## Passing Tests

**138 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.9s |  |
| 2 | `Accessibility-v6` | 19 | 1.8s |  |
| 3 | `Accessibility-v7` | 19 | 1.5s |  |
| 4 | `Accessibility-v8` | 19 | 1.2s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.7s |  |
| 6 | `BitmapData-v5` | 7 | 2.0s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.6s |  |
| 9 | `Boolean-v5` | 38 | 2.5s |  |
| 10 | `Boolean-v6` | 38 | 2.0s |  |
| 11 | `Boolean-v7` | 38 | 22.9s |  |
| 12 | `Boolean-v8` | 38 | 1.6s |  |
| 13 | `Camera-v5` | 7 | 2.2s |  |
| 14 | `Color-v5` | 140 | 5.6s |  |
| 15 | `Color-v6` | 171 | 6.9s |  |
| 16 | `Color-v7` | 161 | 6.5s |  |
| 17 | `Color-v8` | 161 | 27.0s |  |
| 18 | `ColorTransform-v5` | 7 | 2.2s |  |
| 19 | `ColorTransform-v6` | 7 | 0.7s |  |
| 20 | `ColorTransform-v7` | 7 | 1.9s |  |
| 21 | `ColorTransform-v8` | 55 | 3.6s |  |
| 22 | `ContextMenu-v5` | 7 | 2.2s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 5.4s |  |
| 25 | `ContextMenu-v8` | 131 | 19.6s |  |
| 26 | `Error-v5` | 28 | 1.9s |  |
| 27 | `Error-v6` | 31 | 1.9s |  |
| 28 | `Error-v7` | 31 | 1.7s |  |
| 29 | `Error-v8` | 31 | 17.1s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.7s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.3s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.1s |  |
| 33 | `Global-v5` | 172 | 7.2s |  |
| 34 | `Global-v7` | 182 | 7.5s |  |
| 35 | `Global-v8` | 169 | 7.0s |  |
| 36 | `Instance-v5` | 52 | 3.3s |  |
| 37 | `Instance-v6` | 52 | 1.8s |  |
| 38 | `Instance-v7` | 52 | 2.9s |  |
| 39 | `Instance-v8` | 52 | 1.7s |  |
| 40 | `Key-v5` | 51 | 26.2s |  |
| 41 | `Key-v6` | 55 | 3.5s |  |
| 42 | `Key-v7` | 55 | 3.2s |  |
| 43 | `Key-v8` | 55 | 1.6s |  |
| 44 | `LoadVars-v5` | 8 | 2.2s |  |
| 45 | `LocalConnection-v5` | 7 | 23.2s |  |
| 46 | `LocalConnection-v6` | 58 | 3.8s |  |
| 47 | `LocalConnection-v7` | 58 | 3.4s |  |
| 48 | `LocalConnection-v8` | 58 | 1.7s |  |
| 49 | `Matrix-v5` | 7 | 20.9s |  |
| 50 | `Microphone-v5` | 6 | 2.0s |  |
| 51 | `Mouse-v5` | 13 | 21.3s |  |
| 52 | `Mouse-v6` | 21 | 2.4s |  |
| 53 | `Mouse-v7` | 21 | 2.0s |  |
| 54 | `Mouse-v8` | 21 | 1.6s |  |
| 55 | `MovieClipLoader-v5` | 6 | 14.0s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.4s |  |
| 57 | `NetConnection-v5` | 7 | 1.4s |  |
| 58 | `NetStream-v5` | 6 | 20.6s |  |
| 59 | `NetStream-v6` | 80 | 3.6s |  |
| 60 | `NetStream-v7` | 80 | 3.3s |  |
| 61 | `NetStream-v8` | 80 | 1.6s |  |
| 62 | `Number-v6` | 239 | 8.7s |  |
| 63 | `Number-v7` | 237 | 8.7s |  |
| 64 | `Number-v8` | 237 | 1.8s |  |
| 65 | `Point-v5` | 7 | 1.9s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.6s |  |
| 68 | `Point-v8` | 193 | 8.4s |  |
| 69 | `Random-v5` | 30 | 22.3s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.3s |  |
| 72 | `Random-v8` | 30 | 1.6s |  |
| 73 | `Rectangle-v5` | 7 | 2.1s |  |
| 74 | `Rectangle-v6` | 7 | 0.7s |  |
| 75 | `Rectangle-v7` | 7 | 1.8s |  |
| 76 | `Selection-v5` | 21 | 15.7s |  |
| 77 | `Sound-v6` | 121 | 3.6s |  |
| 78 | `Sound-v7` | 121 | 3.7s |  |
| 79 | `Sound-v8` | 121 | 1.4s |  |
| 80 | `Stage-v5` | 38 | 23.2s |  |
| 81 | `System-v5` | 67 | 24.7s |  |
| 82 | `System-v6` | 100 | 4.7s |  |
| 83 | `System-v7` | 101 | 4.8s |  |
| 84 | `System-v8` | 101 | 1.8s |  |
| 85 | `TextFieldHTML-v5` | 6 | 20.5s |  |
| 86 | `TextFieldHTML-v6` | 37 | 2.5s |  |
| 87 | `TextFieldHTML-v7` | 37 | 2.1s |  |
| 88 | `TextFieldHTML-v8` | 37 | 1.4s |  |
| 89 | `TextFormat-v5` | 128 | 4.8s |  |
| 90 | `TextFormat-v6` | 128 | 0.6s |  |
| 91 | `TextSnapshot-v5` | 7 | 21.0s |  |
| 92 | `TextSnapshot-v6` | 173 | 7.8s |  |
| 93 | `TextSnapshot-v7` | 173 | 7.6s |  |
| 94 | `TextSnapshot-v8` | 173 | 1.7s |  |
| 95 | `Transform-v5` | 7 | 2.0s |  |
| 96 | `Transform-v6` | 7 | 1.5s |  |
| 97 | `Transform-v7` | 7 | 1.7s |  |
| 98 | `Try-v5` | 20 | 18.5s |  |
| 99 | `Try-v6` | 20 | 0.5s |  |
| 100 | `Try-v7` | 20 | 2.2s |  |
| 101 | `Try-v8` | 20 | 1.2s |  |
| 102 | `Video-v5` | 7 | 1.9s |  |
| 103 | `Video-v6` | 85 | 2.7s |  |
| 104 | `Video-v7` | 85 | 2.4s |  |
| 105 | `Video-v8` | 85 | 1.2s |  |
| 106 | `XMLSocket-v5` | 35 | 22.0s |  |
| 107 | `XMLSocket-v6` | 35 | 2.7s |  |
| 108 | `XMLSocket-v7` | 35 | 2.4s |  |
| 109 | `XMLSocket-v8` | 35 | 1.7s |  |
| 110 | `argstest-v5` | 4 | 2.2s |  |
| 111 | `case-v5` | 39 | 2.8s |  |
| 112 | `case-v6` | 73 | 3.7s |  |
| 113 | `case-v7` | 67 | 3.6s |  |
| 114 | `case-v8` | 67 | 1.6s |  |
| 115 | `delete-v5` | 61 | 24.1s |  |
| 116 | `delete-v6` | 61 | 3.0s |  |
| 117 | `delete-v7` | 61 | 3.1s |  |
| 118 | `delete-v8` | 61 | 1.9s |  |
| 119 | `enumerate-v5` | 6 | 2.2s |  |
| 120 | `enumerate-v6` | 49 | 3.5s |  |
| 121 | `enumerate-v7` | 49 | 3.0s |  |
| 122 | `enumerate-v8` | 49 | 1.7s |  |
| 123 | `flash-v5` | 10 | 19.4s |  |
| 124 | `flash-v6` | 10 | 1.6s |  |
| 125 | `flash-v7` | 10 | 1.4s |  |
| 126 | `flash-v8` | 41 | 2.5s |  |
| 127 | `getvariable-v5` | 58 | 2.7s |  |
| 128 | `getvariable-v6` | 64 | 2.8s |  |
| 129 | `getvariable-v7` | 64 | 3.0s |  |
| 130 | `getvariable-v8` | 64 | 1.4s |  |
| 131 | `swap-v5` | 7 | 22.1s |  |
| 132 | `swap-v6` | 7 | 0.7s |  |
| 133 | `swap-v7` | 7 | 1.8s |  |
| 134 | `swap-v8` | 7 | 1.6s |  |
| 135 | `targetPath-v5` | 12 | 2.2s |  |
| 136 | `targetPath-v6` | 23 | 2.4s |  |
| 137 | `targetPath-v7` | 23 | 2.1s |  |
| 138 | `targetPath-v8` | 23 | 1.6s |  |

## Ruffle-Matched Tests

**89 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 20.0s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.7s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.4s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 24.6s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.6s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 22.1s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.5s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.0s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.6s |  |
| 12 | `Date-v5` | 7 | 7 | 10.1s |  |
| 13 | `Date-v6` | 6 | 6 | 11.8s |  |
| 14 | `Date-v7` | 6 | 6 | 11.8s |  |
| 15 | `Date-v8` | 6 | 6 | 1.4s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.1s |  |
| 17 | `Function-v5` | 14 | 24 | 4.7s |  |
| 18 | `Global-v6` | 9 | 10 | 8.6s |  |
| 19 | `HitTest-v6` | 8 | 8 | 5.0s |  |
| 20 | `HitTest-v7` | 8 | 8 | 4.7s |  |
| 21 | `HitTest-v8` | 9 | 9 | 4.5s |  |
| 22 | `Inheritance-v5` | 1 | 17 | 26.9s |  |
| 23 | `Inheritance-v6` | 9 | 16 | 7.7s |  |
| 24 | `Inheritance-v7` | 5 | 10 | 7.8s |  |
| 25 | `Inheritance-v8` | 5 | 10 | 2.3s |  |
| 26 | `LoadVars-v6` | 6 | 8 | 6.7s |  |
| 27 | `LoadVars-v7` | 6 | 8 | 6.5s |  |
| 28 | `LoadVars-v8` | 6 | 8 | 2.6s |  |
| 29 | `Math-v5` | 5 | 5 | 15.0s |  |
| 30 | `Math-v6` | 5 | 5 | 0.9s |  |
| 31 | `Math-v7` | 5 | 5 | 15.8s |  |
| 32 | `Math-v8` | 5 | 5 | 2.0s |  |
| 33 | `Matrix-v6` | 29 | 71 | 7.2s |  |
| 34 | `Matrix-v7` | 28 | 70 | 7.3s |  |
| 35 | `Matrix-v8` | 28 | 70 | 1.7s |  |
| 36 | `Microphone-v6` | 31 | 31 | 3.5s |  |
| 37 | `Microphone-v7` | 31 | 31 | 3.1s |  |
| 38 | `Microphone-v8` | 31 | 31 | 1.5s |  |
| 39 | `MovieClip-v5` | 24 | 226 | 13.4s |  |
| 40 | `MovieClipLoader-v7` | 118 | 118 | 2.9s |  |
| 41 | `MovieClipLoader-v8` | 118 | 118 | 1.8s |  |
| 42 | `NetConnection-v6` | 4 | 49 | 3.6s |  |
| 43 | `NetConnection-v7` | 4 | 45 | 3.8s |  |
| 44 | `NetConnection-v8` | 4 | 45 | 1.1s |  |
| 45 | `Number-v5` | 8 | 12 | 9.0s |  |
| 46 | `Object-v5` | 3 | 6 | 26.1s |  |
| 47 | `Object-v6` | 8 | 24 | 13.5s |  |
| 48 | `Object-v7` | 8 | 15 | 13.8s |  |
| 49 | `Object-v8` | 8 | 15 | 2.2s |  |
| 50 | `Rectangle-v8` | 21 | 21 | 7.2s |  |
| 51 | `Selection-v6` | 7 | 13 | 3.8s |  |
| 52 | `Selection-v7` | 7 | 13 | 3.5s |  |
| 53 | `Selection-v8` | 7 | 13 | 1.0s |  |
| 54 | `Sound-v5` | 14 | 16 | 3.9s |  |
| 55 | `Stage-v6` | 14 | 14 | 3.2s |  |
| 56 | `Stage-v7` | 14 | 14 | 2.9s |  |
| 57 | `Stage-v8` | 14 | 14 | 1.6s |  |
| 58 | `String-v5` | 19 | 21 | 15.6s |  |
| 59 | `String-v6` | 10 | 10 | 16.3s |  |
| 60 | `String-v7` | 10 | 10 | 16.2s |  |
| 61 | `String-v8` | 10 | 10 | 1.9s |  |
| 62 | `TextField-v5` | 3 | 3 | 2.3s |  |
| 63 | `TextFormat-v7` | 38 | 40 | 6.6s |  |
| 64 | `TextFormat-v8` | 36 | 38 | 6.6s |  |
| 65 | `Transform-v8` | 7 | 11 | 5.1s |  |
| 66 | `XML-v5` | 10 | 79 | 34.7s |  |
| 67 | `XML-v6` | 3 | 98 | 16.9s |  |
| 68 | `XML-v7` | 3 | 98 | 16.4s |  |
| 69 | `XML-v8` | 24 | 116 | 5.1s |  |
| 70 | `XMLNode-v5` | 3 | 22 | 9.2s |  |
| 71 | `XMLNode-v6` | 3 | 22 | 9.2s |  |
| 72 | `XMLNode-v7` | 3 | 22 | 8.0s |  |
| 73 | `XMLNode-v8` | 3 | 22 | 1.9s |  |
| 74 | `ops-v5` | 7 | 9 | 28.4s |  |
| 75 | `ops-v6` | 7 | 11 | 8.6s |  |
| 76 | `ops-v7` | 7 | 11 | 9.2s |  |
| 77 | `ops-v8` | 7 | 11 | 1.6s |  |
| 78 | `setProperty-v5` | 49 | 49 | 3.0s |  |
| 79 | `setProperty-v6` | 49 | 49 | 3.0s |  |
| 80 | `setProperty-v7` | 49 | 49 | 2.7s |  |
| 81 | `setProperty-v8` | 49 | 49 | 1.7s |  |
| 82 | `toString_valueOf-v5` | 34 | 34 | 26.0s |  |
| 83 | `toString_valueOf-v6` | 5 | 5 | 6.1s |  |
| 84 | `toString_valueOf-v7` | 5 | 5 | 5.7s |  |
| 85 | `toString_valueOf-v8` | 5 | 5 | 1.8s |  |
| 86 | `with-v5` | 3 | 3 | 3.9s |  |
| 87 | `with-v6` | 6 | 9 | 5.1s |  |
| 88 | `with-v7` | 6 | 9 | 4.8s |  |
| 89 | `with-v8` | 6 | 9 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 98.4% | 551 | 560 | 9 |  |
| 2 | `Function-v7` | 97.1% | 264 | 272 | 8 |  |
| 3 | `Function-v8` | 97.1% | 264 | 272 | 8 |  |
| 4 | `Function-v6` | 97.0% | 263 | 271 | 8 |  |
| 5 | `array-v6` | 96.7% | 623 | 644 | 21 |  |
| 6 | `MovieClip-v7` | 96.4% | 934 | 969 | 35 |  |
| 7 | `MovieClip-v6` | 96.3% | 901 | 936 | 35 |  |
| 8 | `MovieClip-v8` | 93.8% | 1020 | 1087 | 67 |  |
| 9 | `array-v7` | 92.4% | 604 | 654 | 50 |  |
| 10 | `array-v8` | 92.4% | 604 | 654 | 50 |  |
| 11 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 12 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 13 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**16 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 98.4% | 551/560 | 560 | 560 |  |
| 2 | `Function-v7` | 97.1% | 264/272 | 272 | 272 |  |
| 3 | `Function-v8` | 97.1% | 264/272 | 272 | 272 |  |
| 4 | `Function-v6` | 97.0% | 263/271 | 271 | 271 |  |
| 5 | `array-v6` | 96.7% | 623/644 | 644 | 644 |  |
| 6 | `MovieClip-v7` | 96.4% | 934/969 | 954 | 969 |  |
| 7 | `MovieClip-v6` | 96.3% | 901/936 | 921 | 936 |  |
| 8 | `MovieClip-v8` | 93.8% | 1020/1087 | 1072 | 1087 |  |
| 9 | `array-v7` | 92.4% | 604/654 | 654 | 654 |  |
| 10 | `array-v8` | 92.4% | 604/654 | 654 | 654 |  |
| 11 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 12 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 13 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 14 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 15 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 16 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
