# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-19 13:28 UTC

**Git SHA**: `9d038c750e`

**Run Duration**: 21m 20s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **138** (56.8%) |
| Ruffle-matched | 92 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (94.7%) |
| Failing | 13 |
| Total expected lines | 38791 |
| Matching lines | 30386 (78.3%) |
| Mismatched lines | 8405 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**138 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.6s |  |
| 2 | `Accessibility-v6` | 19 | 1.7s |  |
| 3 | `Accessibility-v7` | 19 | 1.4s |  |
| 4 | `Accessibility-v8` | 19 | 1.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.5s |  |
| 6 | `BitmapData-v5` | 7 | 2.1s |  |
| 7 | `BitmapData-v6` | 7 | 0.7s |  |
| 8 | `BitmapData-v7` | 7 | 1.8s |  |
| 9 | `Boolean-v5` | 38 | 2.7s |  |
| 10 | `Boolean-v6` | 38 | 2.1s |  |
| 11 | `Boolean-v7` | 38 | 2.8s |  |
| 12 | `Boolean-v8` | 38 | 1.6s |  |
| 13 | `Camera-v5` | 7 | 2.2s |  |
| 14 | `Color-v5` | 140 | 6.3s |  |
| 15 | `Color-v6` | 171 | 7.4s |  |
| 16 | `Color-v7` | 161 | 7.0s |  |
| 17 | `Color-v8` | 161 | 6.8s |  |
| 18 | `ColorTransform-v5` | 7 | 2.1s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.8s |  |
| 21 | `ColorTransform-v8` | 55 | 3.4s |  |
| 22 | `ContextMenu-v5` | 7 | 2.1s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 5.3s |  |
| 25 | `ContextMenu-v8` | 131 | 5.0s |  |
| 26 | `Error-v5` | 28 | 2.5s |  |
| 27 | `Error-v6` | 31 | 2.5s |  |
| 28 | `Error-v7` | 31 | 2.2s |  |
| 29 | `Error-v8` | 31 | 2.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.2s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.0s |  |
| 33 | `Global-v5` | 172 | 7.9s |  |
| 34 | `Global-v7` | 182 | 8.3s |  |
| 35 | `Global-v8` | 169 | 7.7s |  |
| 36 | `Instance-v5` | 52 | 3.2s |  |
| 37 | `Instance-v6` | 52 | 1.7s |  |
| 38 | `Instance-v7` | 52 | 2.7s |  |
| 39 | `Instance-v8` | 52 | 1.5s |  |
| 40 | `Key-v5` | 51 | 2.8s |  |
| 41 | `Key-v6` | 55 | 2.8s |  |
| 42 | `Key-v7` | 55 | 2.5s |  |
| 43 | `Key-v8` | 55 | 1.5s |  |
| 44 | `LoadVars-v5` | 8 | 2.0s |  |
| 45 | `LocalConnection-v5` | 7 | 2.1s |  |
| 46 | `LocalConnection-v6` | 58 | 3.2s |  |
| 47 | `LocalConnection-v7` | 58 | 2.9s |  |
| 48 | `LocalConnection-v8` | 58 | 1.6s |  |
| 49 | `Matrix-v5` | 7 | 1.5s |  |
| 50 | `Microphone-v5` | 6 | 1.4s |  |
| 51 | `Mouse-v5` | 13 | 2.2s |  |
| 52 | `Mouse-v6` | 21 | 2.4s |  |
| 53 | `Mouse-v7` | 21 | 2.1s |  |
| 54 | `Mouse-v8` | 21 | 1.6s |  |
| 55 | `MovieClipLoader-v5` | 6 | 2.0s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.6s |  |
| 57 | `NetConnection-v5` | 7 | 1.9s |  |
| 58 | `NetStream-v5` | 6 | 1.5s |  |
| 59 | `NetStream-v6` | 80 | 2.6s |  |
| 60 | `NetStream-v7` | 80 | 2.4s |  |
| 61 | `NetStream-v8` | 80 | 1.1s |  |
| 62 | `Number-v6` | 239 | 6.2s |  |
| 63 | `Number-v7` | 237 | 6.2s |  |
| 64 | `Number-v8` | 237 | 1.2s |  |
| 65 | `Point-v5` | 7 | 1.4s |  |
| 66 | `Point-v6` | 7 | 0.4s |  |
| 67 | `Point-v7` | 7 | 1.6s |  |
| 68 | `Point-v8` | 193 | 5.7s |  |
| 69 | `Random-v5` | 30 | 2.6s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.3s |  |
| 72 | `Random-v8` | 30 | 1.6s |  |
| 73 | `Rectangle-v5` | 7 | 2.1s |  |
| 74 | `Rectangle-v6` | 7 | 0.7s |  |
| 75 | `Rectangle-v7` | 7 | 1.7s |  |
| 76 | `Selection-v5` | 21 | 2.4s |  |
| 77 | `Sound-v6` | 121 | 5.9s |  |
| 78 | `Sound-v7` | 121 | 5.7s |  |
| 79 | `Sound-v8` | 121 | 2.1s |  |
| 80 | `Stage-v5` | 38 | 2.1s |  |
| 81 | `System-v5` | 67 | 3.4s |  |
| 82 | `System-v6` | 100 | 4.2s |  |
| 83 | `System-v7` | 101 | 4.3s |  |
| 84 | `System-v8` | 101 | 1.6s |  |
| 85 | `TextFieldHTML-v5` | 6 | 2.1s |  |
| 86 | `TextFieldHTML-v6` | 37 | 2.9s |  |
| 87 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 88 | `TextFieldHTML-v8` | 37 | 1.6s |  |
| 89 | `TextFormat-v5` | 128 | 5.5s |  |
| 90 | `TextFormat-v6` | 128 | 0.8s |  |
| 91 | `TextSnapshot-v5` | 7 | 2.1s |  |
| 92 | `TextSnapshot-v6` | 173 | 8.1s |  |
| 93 | `TextSnapshot-v7` | 173 | 7.8s |  |
| 94 | `TextSnapshot-v8` | 173 | 1.7s |  |
| 95 | `Transform-v5` | 7 | 2.1s |  |
| 96 | `Transform-v6` | 7 | 1.5s |  |
| 97 | `Transform-v7` | 7 | 1.7s |  |
| 98 | `Try-v5` | 20 | 3.0s |  |
| 99 | `Try-v6` | 20 | 0.7s |  |
| 100 | `Try-v7` | 20 | 2.6s |  |
| 101 | `Try-v8` | 20 | 1.6s |  |
| 102 | `Video-v5` | 7 | 2.1s |  |
| 103 | `Video-v6` | 85 | 3.8s |  |
| 104 | `Video-v7` | 85 | 3.4s |  |
| 105 | `Video-v8` | 85 | 1.6s |  |
| 106 | `XMLSocket-v5` | 35 | 2.7s |  |
| 107 | `XMLSocket-v6` | 35 | 2.7s |  |
| 108 | `XMLSocket-v7` | 35 | 2.3s |  |
| 109 | `XMLSocket-v8` | 35 | 1.6s |  |
| 110 | `argstest-v5` | 4 | 2.2s |  |
| 111 | `case-v5` | 39 | 2.6s |  |
| 112 | `case-v6` | 73 | 3.5s |  |
| 113 | `case-v7` | 67 | 3.4s |  |
| 114 | `case-v8` | 67 | 1.5s |  |
| 115 | `delete-v5` | 61 | 3.1s |  |
| 116 | `delete-v6` | 61 | 2.6s |  |
| 117 | `delete-v7` | 61 | 2.6s |  |
| 118 | `delete-v8` | 61 | 1.6s |  |
| 119 | `enumerate-v5` | 6 | 1.9s |  |
| 120 | `enumerate-v6` | 49 | 3.2s |  |
| 121 | `enumerate-v7` | 49 | 2.9s |  |
| 122 | `enumerate-v8` | 49 | 1.3s |  |
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
| 133 | `swap-v7` | 7 | 1.7s |  |
| 134 | `swap-v8` | 7 | 1.5s |  |
| 135 | `targetPath-v5` | 12 | 2.2s |  |
| 136 | `targetPath-v6` | 23 | 2.4s |  |
| 137 | `targetPath-v7` | 23 | 2.0s |  |
| 138 | `targetPath-v8` | 23 | 1.5s |  |

## Ruffle-Matched Tests

**92 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 3.9s |  |
| 2 | `ASnative-v6` | 40 | 40 | 3.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 3.7s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.2s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.5s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.1s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.8s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.4s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.6s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.2s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.7s |  |
| 12 | `Date-v5` | 7 | 7 | 13.7s |  |
| 13 | `Date-v6` | 6 | 6 | 15.5s |  |
| 14 | `Date-v7` | 6 | 6 | 16.0s |  |
| 15 | `Date-v8` | 6 | 6 | 2.1s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.2s |  |
| 17 | `Function-v5` | 14 | 24 | 4.7s |  |
| 18 | `Function-v6` | 8 | 33 | 8.0s |  |
| 19 | `Function-v7` | 8 | 33 | 8.2s |  |
| 20 | `Function-v8` | 8 | 33 | 10.8s |  |
| 21 | `Global-v6` | 9 | 10 | 9.5s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.6s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.2s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.2s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 5.1s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.0s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.2s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.1s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 5.5s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.2s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.4s |  |
| 32 | `Math-v5` | 5 | 5 | 14.5s |  |
| 33 | `Math-v6` | 5 | 5 | 0.9s |  |
| 34 | `Math-v7` | 5 | 5 | 14.9s |  |
| 35 | `Math-v8` | 5 | 5 | 1.9s |  |
| 36 | `Matrix-v6` | 29 | 71 | 5.4s |  |
| 37 | `Matrix-v7` | 28 | 70 | 5.9s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.1s |  |
| 39 | `Microphone-v6` | 31 | 31 | 2.6s |  |
| 40 | `Microphone-v7` | 31 | 31 | 2.3s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.0s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 14.2s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.3s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.6s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.1s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.0s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.6s |  |
| 48 | `Number-v5` | 8 | 12 | 6.3s |  |
| 49 | `Object-v5` | 3 | 6 | 3.9s |  |
| 50 | `Object-v6` | 8 | 24 | 9.5s |  |
| 51 | `Object-v7` | 8 | 15 | 9.7s |  |
| 52 | `Object-v8` | 8 | 15 | 1.6s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 7.2s |  |
| 54 | `Selection-v6` | 7 | 13 | 6.1s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.7s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.7s |  |
| 57 | `Sound-v5` | 14 | 16 | 6.0s |  |
| 58 | `Stage-v6` | 14 | 14 | 2.6s |  |
| 59 | `Stage-v7` | 14 | 14 | 2.5s |  |
| 60 | `Stage-v8` | 14 | 14 | 1.3s |  |
| 61 | `String-v5` | 19 | 21 | 14.6s |  |
| 62 | `String-v6` | 10 | 10 | 15.5s |  |
| 63 | `String-v7` | 10 | 10 | 15.2s |  |
| 64 | `String-v8` | 10 | 10 | 1.7s |  |
| 65 | `TextField-v5` | 3 | 3 | 2.1s |  |
| 66 | `TextFormat-v7` | 38 | 40 | 7.2s |  |
| 67 | `TextFormat-v8` | 36 | 38 | 7.1s |  |
| 68 | `Transform-v8` | 7 | 11 | 5.2s |  |
| 69 | `XML-v5` | 10 | 79 | 15.2s |  |
| 70 | `XML-v6` | 3 | 98 | 16.9s |  |
| 71 | `XML-v7` | 3 | 98 | 16.5s |  |
| 72 | `XML-v8` | 24 | 116 | 5.2s |  |
| 73 | `XMLNode-v5` | 3 | 22 | 9.2s |  |
| 74 | `XMLNode-v6` | 3 | 22 | 9.0s |  |
| 75 | `XMLNode-v7` | 3 | 22 | 7.9s |  |
| 76 | `XMLNode-v8` | 3 | 22 | 1.8s |  |
| 77 | `ops-v5` | 7 | 9 | 10.2s |  |
| 78 | `ops-v6` | 7 | 11 | 9.6s |  |
| 79 | `ops-v7` | 7 | 11 | 10.2s |  |
| 80 | `ops-v8` | 7 | 11 | 1.5s |  |
| 81 | `setProperty-v5` | 49 | 49 | 3.1s |  |
| 82 | `setProperty-v6` | 49 | 49 | 3.1s |  |
| 83 | `setProperty-v7` | 49 | 49 | 2.8s |  |
| 84 | `setProperty-v8` | 49 | 49 | 1.8s |  |
| 85 | `toString_valueOf-v5` | 34 | 34 | 5.5s |  |
| 86 | `toString_valueOf-v6` | 5 | 5 | 5.8s |  |
| 87 | `toString_valueOf-v7` | 5 | 5 | 5.6s |  |
| 88 | `toString_valueOf-v8` | 5 | 5 | 1.7s |  |
| 89 | `with-v5` | 3 | 3 | 3.8s |  |
| 90 | `with-v6` | 6 | 9 | 5.0s |  |
| 91 | `with-v7` | 6 | 9 | 4.6s |  |
| 92 | `with-v8` | 6 | 9 | 1.9s |  |

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
