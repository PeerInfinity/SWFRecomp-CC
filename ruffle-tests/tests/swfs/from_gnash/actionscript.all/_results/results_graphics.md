# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-03 19:03 UTC

**Git SHA**: `50fcc7f8bd`

**Run Duration**: 23m 43s

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
| 1 | `Accessibility-v5` | 15 | 3.2s |  |
| 2 | `Accessibility-v6` | 19 | 3.3s |  |
| 3 | `Accessibility-v7` | 19 | 3.0s |  |
| 4 | `Accessibility-v8` | 19 | 2.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.2s |  |
| 6 | `BitmapData-v5` | 7 | 2.8s |  |
| 7 | `BitmapData-v6` | 7 | 1.3s |  |
| 8 | `BitmapData-v7` | 7 | 2.5s |  |
| 9 | `Boolean-v5` | 38 | 3.4s |  |
| 10 | `Boolean-v6` | 38 | 2.8s |  |
| 11 | `Boolean-v7` | 38 | 2.8s |  |
| 12 | `Boolean-v8` | 38 | 1.8s |  |
| 13 | `Camera-v5` | 7 | 1.6s |  |
| 14 | `Color-v5` | 140 | 4.9s |  |
| 15 | `Color-v6` | 171 | 6.2s |  |
| 16 | `Color-v7` | 161 | 5.9s |  |
| 17 | `Color-v8` | 161 | 7.0s |  |
| 18 | `ColorTransform-v5` | 7 | 2.6s |  |
| 19 | `ColorTransform-v6` | 7 | 1.2s |  |
| 20 | `ColorTransform-v7` | 7 | 2.2s |  |
| 21 | `ColorTransform-v8` | 55 | 3.7s |  |
| 22 | `ContextMenu-v5` | 7 | 2.6s |  |
| 23 | `ContextMenu-v6` | 7 | 1.2s |  |
| 24 | `ContextMenu-v7` | 131 | 5.3s |  |
| 25 | `ContextMenu-v8` | 131 | 6.3s |  |
| 26 | `Error-v5` | 28 | 3.4s |  |
| 27 | `Error-v6` | 31 | 3.5s |  |
| 28 | `Error-v7` | 31 | 3.1s |  |
| 29 | `Error-v8` | 31 | 2.8s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.6s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.0s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.9s |  |
| 33 | `Global-v5` | 172 | 7.8s |  |
| 34 | `Global-v7` | 182 | 8.1s |  |
| 35 | `Global-v8` | 169 | 7.6s |  |
| 36 | `Instance-v5` | 52 | 3.9s |  |
| 37 | `Instance-v6` | 52 | 2.5s |  |
| 38 | `Instance-v7` | 52 | 3.6s |  |
| 39 | `Instance-v8` | 52 | 2.5s |  |
| 40 | `Key-v5` | 51 | 3.1s |  |
| 41 | `Key-v6` | 55 | 3.0s |  |
| 42 | `Key-v7` | 55 | 3.1s |  |
| 43 | `Key-v8` | 55 | 2.0s |  |
| 44 | `LoadVars-v5` | 8 | 2.5s |  |
| 45 | `LocalConnection-v5` | 7 | 3.0s |  |
| 46 | `LocalConnection-v6` | 58 | 4.3s |  |
| 47 | `LocalConnection-v7` | 58 | 3.8s |  |
| 48 | `LocalConnection-v8` | 58 | 2.5s |  |
| 49 | `Matrix-v5` | 7 | 2.1s |  |
| 50 | `Microphone-v5` | 6 | 2.0s |  |
| 51 | `Mouse-v5` | 13 | 2.3s |  |
| 52 | `Mouse-v6` | 21 | 2.5s |  |
| 53 | `Mouse-v7` | 21 | 2.1s |  |
| 54 | `Mouse-v8` | 21 | 1.7s |  |
| 55 | `MovieClipLoader-v5` | 6 | 3.2s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.4s |  |
| 57 | `NetConnection-v5` | 7 | 3.0s |  |
| 58 | `NetStream-v5` | 6 | 2.8s |  |
| 59 | `NetStream-v6` | 80 | 4.4s |  |
| 60 | `NetStream-v7` | 80 | 4.1s |  |
| 61 | `NetStream-v8` | 80 | 2.3s |  |
| 62 | `Number-v6` | 239 | 9.6s |  |
| 63 | `Number-v7` | 237 | 9.6s |  |
| 64 | `Number-v8` | 237 | 2.5s |  |
| 65 | `Point-v5` | 7 | 2.6s |  |
| 66 | `Point-v6` | 7 | 1.2s |  |
| 67 | `Point-v7` | 7 | 2.2s |  |
| 68 | `Point-v8` | 193 | 8.3s |  |
| 69 | `Random-v5` | 30 | 3.2s |  |
| 70 | `Random-v6` | 30 | 1.2s |  |
| 71 | `Random-v7` | 30 | 2.8s |  |
| 72 | `Random-v8` | 30 | 2.1s |  |
| 73 | `Rectangle-v5` | 7 | 2.6s |  |
| 74 | `Rectangle-v6` | 7 | 1.2s |  |
| 75 | `Rectangle-v7` | 7 | 2.3s |  |
| 76 | `Selection-v5` | 21 | 3.1s |  |
| 77 | `Sound-v6` | 121 | 6.3s |  |
| 78 | `Sound-v7` | 121 | 5.9s |  |
| 79 | `Sound-v8` | 121 | 2.9s |  |
| 80 | `Stage-v5` | 38 | 3.5s |  |
| 81 | `System-v5` | 67 | 4.2s |  |
| 82 | `System-v6` | 100 | 5.1s |  |
| 83 | `System-v7` | 101 | 5.1s |  |
| 84 | `System-v8` | 101 | 2.5s |  |
| 85 | `TextFieldHTML-v5` | 6 | 3.1s |  |
| 86 | `TextFieldHTML-v6` | 37 | 3.6s |  |
| 87 | `TextFieldHTML-v7` | 37 | 3.3s |  |
| 88 | `TextFieldHTML-v8` | 37 | 2.5s |  |
| 89 | `TextFormat-v5` | 128 | 6.2s |  |
| 90 | `TextFormat-v6` | 128 | 1.5s |  |
| 91 | `TextSnapshot-v5` | 7 | 3.3s |  |
| 92 | `TextSnapshot-v6` | 173 | 10.2s |  |
| 93 | `TextSnapshot-v7` | 173 | 9.9s |  |
| 94 | `TextSnapshot-v8` | 173 | 2.8s |  |
| 95 | `Transform-v5` | 7 | 3.2s |  |
| 96 | `Transform-v6` | 7 | 2.7s |  |
| 97 | `Transform-v7` | 7 | 2.9s |  |
| 98 | `Try-v5` | 20 | 3.9s |  |
| 99 | `Try-v6` | 20 | 1.5s |  |
| 100 | `Try-v7` | 20 | 3.6s |  |
| 101 | `Try-v8` | 20 | 2.5s |  |
| 102 | `Video-v5` | 7 | 3.1s |  |
| 103 | `Video-v6` | 85 | 4.8s |  |
| 104 | `Video-v7` | 85 | 4.5s |  |
| 105 | `Video-v8` | 85 | 2.5s |  |
| 106 | `XMLSocket-v5` | 35 | 2.4s |  |
| 107 | `XMLSocket-v6` | 35 | 2.5s |  |
| 108 | `XMLSocket-v7` | 35 | 2.2s |  |
| 109 | `XMLSocket-v8` | 35 | 1.8s |  |
| 110 | `argstest-v5` | 4 | 2.3s |  |
| 111 | `case-v5` | 39 | 2.8s |  |
| 112 | `case-v6` | 73 | 3.7s |  |
| 113 | `case-v7` | 67 | 3.4s |  |
| 114 | `case-v8` | 67 | 1.9s |  |
| 115 | `delete-v5` | 61 | 2.9s |  |
| 116 | `delete-v6` | 61 | 2.4s |  |
| 117 | `delete-v7` | 61 | 2.9s |  |
| 118 | `delete-v8` | 61 | 1.7s |  |
| 119 | `enumerate-v5` | 6 | 1.9s |  |
| 120 | `enumerate-v6` | 49 | 2.7s |  |
| 121 | `enumerate-v7` | 49 | 2.5s |  |
| 122 | `enumerate-v8` | 49 | 1.6s |  |
| 123 | `flash-v5` | 10 | 2.9s |  |
| 124 | `flash-v6` | 10 | 2.9s |  |
| 125 | `flash-v7` | 10 | 2.5s |  |
| 126 | `flash-v8` | 41 | 3.6s |  |
| 127 | `getvariable-v5` | 58 | 4.0s |  |
| 128 | `getvariable-v6` | 64 | 4.1s |  |
| 129 | `getvariable-v7` | 64 | 4.2s |  |
| 130 | `getvariable-v8` | 64 | 2.4s |  |
| 131 | `swap-v5` | 7 | 0.9s |  |
| 132 | `swap-v6` | 7 | 0.9s |  |
| 133 | `swap-v7` | 7 | 0.9s |  |
| 134 | `swap-v8` | 7 | 0.9s |  |
| 135 | `targetPath-v5` | 12 | 0.9s |  |
| 136 | `targetPath-v6` | 23 | 0.9s |  |
| 137 | `targetPath-v7` | 23 | 0.9s |  |
| 138 | `targetPath-v8` | 23 | 0.9s |  |

## Ruffle-Matched Tests

**89 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 7.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 7.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.8s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.7s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.6s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.5s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 24.5s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.8s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.0s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.1s |  |
| 12 | `Date-v5` | 7 | 7 | 15.7s |  |
| 13 | `Date-v6` | 6 | 6 | 16.8s |  |
| 14 | `Date-v7` | 6 | 6 | 17.4s |  |
| 15 | `Date-v8` | 6 | 6 | 2.9s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.8s |  |
| 17 | `Function-v5` | 14 | 24 | 5.6s |  |
| 18 | `Global-v6` | 9 | 10 | 9.1s |  |
| 19 | `HitTest-v6` | 8 | 8 | 5.7s |  |
| 20 | `HitTest-v7` | 8 | 8 | 5.3s |  |
| 21 | `HitTest-v8` | 9 | 9 | 5.2s |  |
| 22 | `Inheritance-v5` | 1 | 17 | 5.8s |  |
| 23 | `Inheritance-v6` | 9 | 16 | 7.8s |  |
| 24 | `Inheritance-v7` | 5 | 10 | 8.1s |  |
| 25 | `Inheritance-v8` | 5 | 10 | 3.0s |  |
| 26 | `LoadVars-v6` | 6 | 8 | 5.4s |  |
| 27 | `LoadVars-v7` | 6 | 8 | 5.2s |  |
| 28 | `LoadVars-v8` | 6 | 8 | 2.6s |  |
| 29 | `Math-v5` | 5 | 5 | 15.3s |  |
| 30 | `Math-v6` | 5 | 5 | 1.6s |  |
| 31 | `Math-v7` | 5 | 5 | 15.8s |  |
| 32 | `Math-v8` | 5 | 5 | 2.7s |  |
| 33 | `Matrix-v6` | 29 | 71 | 6.4s |  |
| 34 | `Matrix-v7` | 28 | 70 | 6.5s |  |
| 35 | `Matrix-v8` | 28 | 70 | 1.7s |  |
| 36 | `Microphone-v6` | 31 | 31 | 3.3s |  |
| 37 | `Microphone-v7` | 31 | 31 | 2.8s |  |
| 38 | `Microphone-v8` | 31 | 31 | 1.6s |  |
| 39 | `MovieClip-v5` | 24 | 226 | 10.9s |  |
| 40 | `MovieClipLoader-v7` | 118 | 118 | 5.3s |  |
| 41 | `MovieClipLoader-v8` | 118 | 118 | 3.7s |  |
| 42 | `NetConnection-v6` | 4 | 49 | 6.4s |  |
| 43 | `NetConnection-v7` | 4 | 45 | 6.5s |  |
| 44 | `NetConnection-v8` | 4 | 45 | 2.7s |  |
| 45 | `Number-v5` | 8 | 12 | 9.7s |  |
| 46 | `Object-v5` | 3 | 6 | 6.4s |  |
| 47 | `Object-v6` | 8 | 24 | 12.8s |  |
| 48 | `Object-v7` | 8 | 15 | 13.1s |  |
| 49 | `Object-v8` | 8 | 15 | 2.8s |  |
| 50 | `Rectangle-v8` | 21 | 21 | 7.4s |  |
| 51 | `Selection-v6` | 7 | 13 | 6.3s |  |
| 52 | `Selection-v7` | 7 | 13 | 6.0s |  |
| 53 | `Selection-v8` | 7 | 13 | 2.5s |  |
| 54 | `Sound-v5` | 14 | 16 | 6.1s |  |
| 55 | `Stage-v6` | 14 | 14 | 4.0s |  |
| 56 | `Stage-v7` | 14 | 14 | 3.6s |  |
| 57 | `Stage-v8` | 14 | 14 | 2.4s |  |
| 58 | `String-v5` | 19 | 21 | 17.2s |  |
| 59 | `String-v6` | 10 | 10 | 18.6s |  |
| 60 | `String-v7` | 10 | 10 | 18.2s |  |
| 61 | `String-v8` | 10 | 10 | 2.8s |  |
| 62 | `TextField-v5` | 3 | 3 | 3.1s |  |
| 63 | `TextFormat-v7` | 38 | 40 | 7.9s |  |
| 64 | `TextFormat-v8` | 36 | 38 | 7.8s |  |
| 65 | `Transform-v8` | 7 | 11 | 6.9s |  |
| 66 | `XML-v5` | 10 | 79 | 15.1s |  |
| 67 | `XML-v6` | 3 | 98 | 16.9s |  |
| 68 | `XML-v7` | 3 | 98 | 16.3s |  |
| 69 | `XML-v8` | 24 | 116 | 5.5s |  |
| 70 | `XMLNode-v5` | 3 | 22 | 9.4s |  |
| 71 | `XMLNode-v6` | 3 | 22 | 9.3s |  |
| 72 | `XMLNode-v7` | 3 | 22 | 8.2s |  |
| 73 | `XMLNode-v8` | 3 | 22 | 2.6s |  |
| 74 | `ops-v5` | 7 | 9 | 10.3s |  |
| 75 | `ops-v6` | 7 | 11 | 9.6s |  |
| 76 | `ops-v7` | 7 | 11 | 10.4s |  |
| 77 | `ops-v8` | 7 | 11 | 2.5s |  |
| 78 | `setProperty-v5` | 49 | 49 | 3.9s |  |
| 79 | `setProperty-v6` | 49 | 49 | 3.8s |  |
| 80 | `setProperty-v7` | 49 | 49 | 3.5s |  |
| 81 | `setProperty-v8` | 49 | 49 | 2.6s |  |
| 82 | `toString_valueOf-v5` | 34 | 34 | 6.8s |  |
| 83 | `toString_valueOf-v6` | 5 | 5 | 7.2s |  |
| 84 | `toString_valueOf-v7` | 5 | 5 | 6.8s |  |
| 85 | `toString_valueOf-v8` | 5 | 5 | 2.7s |  |
| 86 | `with-v5` | 3 | 3 | 4.8s |  |
| 87 | `with-v6` | 6 | 9 | 6.0s |  |
| 88 | `with-v7` | 6 | 9 | 5.5s |  |
| 89 | `with-v8` | 6 | 9 | 2.7s |  |

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
