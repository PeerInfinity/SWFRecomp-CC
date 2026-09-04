# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-04 06:19 UTC

**Git SHA**: `b20dff160b`

**Run Duration**: 21m 53s

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
| 1 | `Accessibility-v5` | 15 | 2.1s |  |
| 2 | `Accessibility-v6` | 19 | 2.2s |  |
| 3 | `Accessibility-v7` | 19 | 1.9s |  |
| 4 | `Accessibility-v8` | 19 | 1.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.0s |  |
| 6 | `BitmapData-v5` | 7 | 2.1s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.7s |  |
| 9 | `Boolean-v5` | 38 | 2.6s |  |
| 10 | `Boolean-v6` | 38 | 2.0s |  |
| 11 | `Boolean-v7` | 38 | 2.6s |  |
| 12 | `Boolean-v8` | 38 | 1.5s |  |
| 13 | `Camera-v5` | 7 | 2.0s |  |
| 14 | `Color-v5` | 140 | 5.4s |  |
| 15 | `Color-v6` | 171 | 6.5s |  |
| 16 | `Color-v7` | 161 | 6.2s |  |
| 17 | `Color-v8` | 161 | 7.2s |  |
| 18 | `ColorTransform-v5` | 7 | 2.2s |  |
| 19 | `ColorTransform-v6` | 7 | 0.7s |  |
| 20 | `ColorTransform-v7` | 7 | 1.8s |  |
| 21 | `ColorTransform-v8` | 55 | 3.6s |  |
| 22 | `ContextMenu-v5` | 7 | 2.2s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 5.4s |  |
| 25 | `ContextMenu-v8` | 131 | 4.9s |  |
| 26 | `Error-v5` | 28 | 2.3s |  |
| 27 | `Error-v6` | 31 | 2.3s |  |
| 28 | `Error-v7` | 31 | 1.9s |  |
| 29 | `Error-v8` | 31 | 2.6s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.0s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 33 | `Global-v5` | 172 | 7.4s |  |
| 34 | `Global-v7` | 182 | 7.7s |  |
| 35 | `Global-v8` | 169 | 7.2s |  |
| 36 | `Instance-v5` | 52 | 2.9s |  |
| 37 | `Instance-v6` | 52 | 1.6s |  |
| 38 | `Instance-v7` | 52 | 2.6s |  |
| 39 | `Instance-v8` | 52 | 1.5s |  |
| 40 | `Key-v5` | 51 | 2.9s |  |
| 41 | `Key-v6` | 55 | 3.0s |  |
| 42 | `Key-v7` | 55 | 2.6s |  |
| 43 | `Key-v8` | 55 | 1.5s |  |
| 44 | `LoadVars-v5` | 8 | 2.1s |  |
| 45 | `LocalConnection-v5` | 7 | 1.8s |  |
| 46 | `LocalConnection-v6` | 58 | 2.8s |  |
| 47 | `LocalConnection-v7` | 58 | 2.4s |  |
| 48 | `LocalConnection-v8` | 58 | 1.3s |  |
| 49 | `Matrix-v5` | 7 | 2.1s |  |
| 50 | `Microphone-v5` | 6 | 2.1s |  |
| 51 | `Mouse-v5` | 13 | 2.4s |  |
| 52 | `Mouse-v6` | 21 | 2.5s |  |
| 53 | `Mouse-v7` | 21 | 2.1s |  |
| 54 | `Mouse-v8` | 21 | 1.7s |  |
| 55 | `MovieClipLoader-v5` | 6 | 2.1s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.7s |  |
| 57 | `NetConnection-v5` | 7 | 2.1s |  |
| 58 | `NetStream-v5` | 6 | 1.8s |  |
| 59 | `NetStream-v6` | 80 | 3.3s |  |
| 60 | `NetStream-v7` | 80 | 3.0s |  |
| 61 | `NetStream-v8` | 80 | 1.4s |  |
| 62 | `Number-v6` | 239 | 8.7s |  |
| 63 | `Number-v7` | 237 | 8.8s |  |
| 64 | `Number-v8` | 237 | 1.6s |  |
| 65 | `Point-v5` | 7 | 1.9s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.6s |  |
| 68 | `Point-v8` | 193 | 8.0s |  |
| 69 | `Random-v5` | 30 | 2.5s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.2s |  |
| 72 | `Random-v8` | 30 | 1.6s |  |
| 73 | `Rectangle-v5` | 7 | 2.1s |  |
| 74 | `Rectangle-v6` | 7 | 0.6s |  |
| 75 | `Rectangle-v7` | 7 | 1.7s |  |
| 76 | `Selection-v5` | 21 | 2.3s |  |
| 77 | `Sound-v6` | 121 | 5.5s |  |
| 78 | `Sound-v7` | 121 | 5.1s |  |
| 79 | `Sound-v8` | 121 | 2.0s |  |
| 80 | `Stage-v5` | 38 | 2.1s |  |
| 81 | `System-v5` | 67 | 3.6s |  |
| 82 | `System-v6` | 100 | 4.4s |  |
| 83 | `System-v7` | 101 | 4.5s |  |
| 84 | `System-v8` | 101 | 1.7s |  |
| 85 | `TextFieldHTML-v5` | 6 | 2.0s |  |
| 86 | `TextFieldHTML-v6` | 37 | 2.6s |  |
| 87 | `TextFieldHTML-v7` | 37 | 2.2s |  |
| 88 | `TextFieldHTML-v8` | 37 | 1.5s |  |
| 89 | `TextFormat-v5` | 128 | 4.9s |  |
| 90 | `TextFormat-v6` | 128 | 0.7s |  |
| 91 | `TextSnapshot-v5` | 7 | 2.1s |  |
| 92 | `TextSnapshot-v6` | 173 | 7.9s |  |
| 93 | `TextSnapshot-v7` | 173 | 7.5s |  |
| 94 | `TextSnapshot-v8` | 173 | 1.6s |  |
| 95 | `Transform-v5` | 7 | 2.0s |  |
| 96 | `Transform-v6` | 7 | 1.5s |  |
| 97 | `Transform-v7` | 7 | 1.7s |  |
| 98 | `Try-v5` | 20 | 2.3s |  |
| 99 | `Try-v6` | 20 | 0.5s |  |
| 100 | `Try-v7` | 20 | 2.0s |  |
| 101 | `Try-v8` | 20 | 1.2s |  |
| 102 | `Video-v5` | 7 | 1.8s |  |
| 103 | `Video-v6` | 85 | 2.9s |  |
| 104 | `Video-v7` | 85 | 2.6s |  |
| 105 | `Video-v8` | 85 | 1.3s |  |
| 106 | `XMLSocket-v5` | 35 | 2.8s |  |
| 107 | `XMLSocket-v6` | 35 | 2.7s |  |
| 108 | `XMLSocket-v7` | 35 | 2.4s |  |
| 109 | `XMLSocket-v8` | 35 | 1.7s |  |
| 110 | `argstest-v5` | 4 | 2.2s |  |
| 111 | `case-v5` | 39 | 2.7s |  |
| 112 | `case-v6` | 73 | 3.6s |  |
| 113 | `case-v7` | 67 | 3.5s |  |
| 114 | `case-v8` | 67 | 1.6s |  |
| 115 | `delete-v5` | 61 | 3.2s |  |
| 116 | `delete-v6` | 61 | 2.6s |  |
| 117 | `delete-v7` | 61 | 2.9s |  |
| 118 | `delete-v8` | 61 | 1.8s |  |
| 119 | `enumerate-v5` | 6 | 2.1s |  |
| 120 | `enumerate-v6` | 49 | 3.1s |  |
| 121 | `enumerate-v7` | 49 | 2.8s |  |
| 122 | `enumerate-v8` | 49 | 1.6s |  |
| 123 | `flash-v5` | 10 | 0.3s |  |
| 124 | `flash-v6` | 10 | 0.3s |  |
| 125 | `flash-v7` | 10 | 0.3s |  |
| 126 | `flash-v8` | 41 | 0.3s |  |
| 127 | `getvariable-v5` | 58 | 0.3s |  |
| 128 | `getvariable-v6` | 64 | 0.3s |  |
| 129 | `getvariable-v7` | 64 | 0.3s |  |
| 130 | `getvariable-v8` | 64 | 0.3s |  |
| 131 | `swap-v5` | 7 | 2.1s |  |
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
| 1 | `ASnative-v5` | 35 | 35 | 5.5s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.1s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.6s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.2s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.8s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.7s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 23.7s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.0s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.7s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.5s |  |
| 12 | `Date-v5` | 7 | 7 | 13.6s |  |
| 13 | `Date-v6` | 6 | 6 | 15.3s |  |
| 14 | `Date-v7` | 6 | 6 | 15.8s |  |
| 15 | `Date-v8` | 6 | 6 | 1.8s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.0s |  |
| 17 | `Function-v5` | 14 | 24 | 5.8s |  |
| 18 | `Global-v6` | 9 | 10 | 8.8s |  |
| 19 | `HitTest-v6` | 8 | 8 | 5.2s |  |
| 20 | `HitTest-v7` | 8 | 8 | 4.8s |  |
| 21 | `HitTest-v8` | 9 | 9 | 4.7s |  |
| 22 | `Inheritance-v5` | 1 | 17 | 4.8s |  |
| 23 | `Inheritance-v6` | 9 | 16 | 6.9s |  |
| 24 | `Inheritance-v7` | 5 | 10 | 6.8s |  |
| 25 | `Inheritance-v8` | 5 | 10 | 2.1s |  |
| 26 | `LoadVars-v6` | 6 | 8 | 5.6s |  |
| 27 | `LoadVars-v7` | 6 | 8 | 5.3s |  |
| 28 | `LoadVars-v8` | 6 | 8 | 2.4s |  |
| 29 | `Math-v5` | 5 | 5 | 11.9s |  |
| 30 | `Math-v6` | 5 | 5 | 0.7s |  |
| 31 | `Math-v7` | 5 | 5 | 12.6s |  |
| 32 | `Math-v8` | 5 | 5 | 1.6s |  |
| 33 | `Matrix-v6` | 29 | 71 | 7.6s |  |
| 34 | `Matrix-v7` | 28 | 70 | 7.6s |  |
| 35 | `Matrix-v8` | 28 | 70 | 1.8s |  |
| 36 | `Microphone-v6` | 31 | 31 | 3.6s |  |
| 37 | `Microphone-v7` | 31 | 31 | 3.3s |  |
| 38 | `Microphone-v8` | 31 | 31 | 1.6s |  |
| 39 | `MovieClip-v5` | 24 | 226 | 14.6s |  |
| 40 | `MovieClipLoader-v7` | 118 | 118 | 4.1s |  |
| 41 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 42 | `NetConnection-v6` | 4 | 49 | 5.0s |  |
| 43 | `NetConnection-v7` | 4 | 45 | 5.0s |  |
| 44 | `NetConnection-v8` | 4 | 45 | 1.7s |  |
| 45 | `Number-v5` | 8 | 12 | 8.9s |  |
| 46 | `Object-v5` | 3 | 6 | 5.8s |  |
| 47 | `Object-v6` | 8 | 24 | 12.3s |  |
| 48 | `Object-v7` | 8 | 15 | 12.6s |  |
| 49 | `Object-v8` | 8 | 15 | 2.2s |  |
| 50 | `Rectangle-v8` | 21 | 21 | 6.9s |  |
| 51 | `Selection-v6` | 7 | 13 | 5.6s |  |
| 52 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 53 | `Selection-v8` | 7 | 13 | 1.6s |  |
| 54 | `Sound-v5` | 14 | 16 | 5.3s |  |
| 55 | `Stage-v6` | 14 | 14 | 2.5s |  |
| 56 | `Stage-v7` | 14 | 14 | 2.2s |  |
| 57 | `Stage-v8` | 14 | 14 | 1.3s |  |
| 58 | `String-v5` | 19 | 21 | 13.5s |  |
| 59 | `String-v6` | 10 | 10 | 14.3s |  |
| 60 | `String-v7` | 10 | 10 | 14.2s |  |
| 61 | `String-v8` | 10 | 10 | 1.6s |  |
| 62 | `TextField-v5` | 3 | 3 | 2.2s |  |
| 63 | `TextFormat-v7` | 38 | 40 | 6.7s |  |
| 64 | `TextFormat-v8` | 36 | 38 | 6.5s |  |
| 65 | `Transform-v8` | 7 | 11 | 5.1s |  |
| 66 | `XML-v5` | 10 | 79 | 15.4s |  |
| 67 | `XML-v6` | 3 | 98 | 17.0s |  |
| 68 | `XML-v7` | 3 | 98 | 16.4s |  |
| 69 | `XML-v8` | 24 | 116 | 4.9s |  |
| 70 | `XMLNode-v5` | 3 | 22 | 8.9s |  |
| 71 | `XMLNode-v6` | 3 | 22 | 8.9s |  |
| 72 | `XMLNode-v7` | 3 | 22 | 7.8s |  |
| 73 | `XMLNode-v8` | 3 | 22 | 1.9s |  |
| 74 | `ops-v5` | 7 | 9 | 10.9s |  |
| 75 | `ops-v6` | 7 | 11 | 10.2s |  |
| 76 | `ops-v7` | 7 | 11 | 10.8s |  |
| 77 | `ops-v8` | 7 | 11 | 1.9s |  |
| 78 | `setProperty-v5` | 49 | 49 | 3.4s |  |
| 79 | `setProperty-v6` | 49 | 49 | 3.4s |  |
| 80 | `setProperty-v7` | 49 | 49 | 2.9s |  |
| 81 | `setProperty-v8` | 49 | 49 | 2.0s |  |
| 82 | `toString_valueOf-v5` | 34 | 34 | 5.1s |  |
| 83 | `toString_valueOf-v6` | 5 | 5 | 5.5s |  |
| 84 | `toString_valueOf-v7` | 5 | 5 | 5.2s |  |
| 85 | `toString_valueOf-v8` | 5 | 5 | 1.7s |  |
| 86 | `with-v5` | 3 | 3 | 3.6s |  |
| 87 | `with-v6` | 6 | 9 | 4.7s |  |
| 88 | `with-v7` | 6 | 9 | 4.4s |  |
| 89 | `with-v8` | 6 | 9 | 1.8s |  |

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
