# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-15 09:18 UTC

**Git SHA**: `86434112a7`

**Run Duration**: 39m 57s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **135** (55.6%) |
| Ruffle-matched | 92 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **227** (93.4%) |
| Failing | 16 |
| Total expected lines | 38791 |
| Matching lines | 30360 (78.3%) |
| Mismatched lines | 8431 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 100.0% |

## Passing Tests

**135 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.1s |  |
| 2 | `Accessibility-v6` | 19 | 3.1s |  |
| 3 | `Accessibility-v7` | 19 | 2.8s |  |
| 4 | `Accessibility-v8` | 19 | 2.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.9s |  |
| 6 | `BitmapData-v5` | 7 | 3.0s |  |
| 7 | `BitmapData-v6` | 7 | 1.3s |  |
| 8 | `BitmapData-v7` | 7 | 2.5s |  |
| 9 | `Boolean-v5` | 38 | 3.5s |  |
| 10 | `Boolean-v6` | 38 | 2.9s |  |
| 11 | `Boolean-v7` | 38 | 23.0s |  |
| 12 | `Boolean-v8` | 38 | 2.4s |  |
| 13 | `Camera-v5` | 7 | 2.8s |  |
| 14 | `Color-v5` | 140 | 6.5s |  |
| 15 | `Color-v6` | 171 | 7.6s |  |
| 16 | `Color-v7` | 161 | 7.5s |  |
| 17 | `Color-v8` | 161 | 29.4s |  |
| 18 | `ColorTransform-v5` | 7 | 3.1s |  |
| 19 | `ColorTransform-v6` | 7 | 1.4s |  |
| 20 | `ColorTransform-v7` | 7 | 2.7s |  |
| 21 | `ColorTransform-v8` | 55 | 4.6s |  |
| 22 | `ContextMenu-v5` | 7 | 3.0s |  |
| 23 | `ContextMenu-v6` | 7 | 1.4s |  |
| 24 | `ContextMenu-v7` | 131 | 6.2s |  |
| 25 | `ContextMenu-v8` | 131 | 24.2s |  |
| 26 | `Error-v5` | 28 | 3.1s |  |
| 27 | `Error-v6` | 31 | 3.2s |  |
| 28 | `Error-v7` | 31 | 2.9s |  |
| 29 | `Error-v8` | 31 | 22.1s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.7s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.3s |  |
| 33 | `Global-v5` | 172 | 7.8s |  |
| 34 | `Global-v7` | 182 | 8.0s |  |
| 35 | `Global-v8` | 169 | 7.4s |  |
| 36 | `Instance-v5` | 52 | 2.4s |  |
| 37 | `Instance-v6` | 52 | 1.5s |  |
| 38 | `Instance-v7` | 52 | 2.1s |  |
| 39 | `Instance-v8` | 52 | 1.5s |  |
| 40 | `Key-v5` | 51 | 21.8s |  |
| 41 | `Key-v6` | 55 | 3.6s |  |
| 42 | `Key-v7` | 55 | 3.3s |  |
| 43 | `Key-v8` | 55 | 2.3s |  |
| 44 | `LoadVars-v5` | 8 | 21.1s |  |
| 45 | `LocalConnection-v5` | 7 | 21.1s |  |
| 46 | `LocalConnection-v6` | 58 | 3.8s |  |
| 47 | `LocalConnection-v7` | 58 | 3.5s |  |
| 48 | `LocalConnection-v8` | 58 | 2.3s |  |
| 49 | `Matrix-v5` | 7 | 21.8s |  |
| 50 | `Microphone-v5` | 6 | 2.9s |  |
| 51 | `Mouse-v5` | 13 | 21.8s |  |
| 52 | `Mouse-v6` | 21 | 3.0s |  |
| 53 | `Mouse-v7` | 21 | 2.7s |  |
| 54 | `Mouse-v8` | 21 | 2.3s |  |
| 55 | `MovieClipLoader-v5` | 6 | 23.7s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.5s |  |
| 57 | `NetConnection-v5` | 7 | 22.3s |  |
| 58 | `NetStream-v5` | 6 | 21.9s |  |
| 59 | `NetStream-v6` | 80 | 4.3s |  |
| 60 | `NetStream-v7` | 80 | 3.9s |  |
| 61 | `NetStream-v8` | 80 | 2.1s |  |
| 62 | `Number-v6` | 239 | 9.7s |  |
| 63 | `Number-v7` | 237 | 9.6s |  |
| 64 | `Number-v8` | 237 | 2.2s |  |
| 65 | `Point-v5` | 7 | 21.8s |  |
| 66 | `Point-v6` | 7 | 1.3s |  |
| 67 | `Point-v7` | 7 | 2.6s |  |
| 68 | `Point-v8` | 193 | 9.4s |  |
| 69 | `Random-v5` | 30 | 22.3s |  |
| 70 | `Random-v6` | 30 | 1.4s |  |
| 71 | `Random-v7` | 30 | 3.1s |  |
| 72 | `Random-v8` | 30 | 2.4s |  |
| 73 | `Rectangle-v5` | 7 | 2.9s |  |
| 74 | `Rectangle-v6` | 7 | 1.4s |  |
| 75 | `Rectangle-v7` | 7 | 2.6s |  |
| 76 | `Selection-v5` | 21 | 21.4s |  |
| 77 | `Stage-v5` | 38 | 24.0s |  |
| 78 | `System-v5` | 67 | 22.7s |  |
| 79 | `System-v6` | 100 | 4.8s |  |
| 80 | `System-v7` | 101 | 4.9s |  |
| 81 | `System-v8` | 101 | 2.3s |  |
| 82 | `TextFieldHTML-v5` | 6 | 22.1s |  |
| 83 | `TextFieldHTML-v6` | 37 | 3.5s |  |
| 84 | `TextFieldHTML-v7` | 37 | 3.2s |  |
| 85 | `TextFieldHTML-v8` | 37 | 2.4s |  |
| 86 | `TextFormat-v5` | 128 | 6.2s |  |
| 87 | `TextFormat-v6` | 128 | 1.4s |  |
| 88 | `TextSnapshot-v5` | 7 | 17.8s |  |
| 89 | `TextSnapshot-v6` | 173 | 7.7s |  |
| 90 | `TextSnapshot-v7` | 173 | 7.6s |  |
| 91 | `TextSnapshot-v8` | 173 | 2.1s |  |
| 92 | `Transform-v5` | 7 | 2.4s |  |
| 93 | `Transform-v6` | 7 | 1.9s |  |
| 94 | `Transform-v7` | 7 | 2.1s |  |
| 95 | `Try-v5` | 20 | 22.8s |  |
| 96 | `Try-v6` | 20 | 1.4s |  |
| 97 | `Try-v7` | 20 | 3.5s |  |
| 98 | `Try-v8` | 20 | 2.5s |  |
| 99 | `Video-v5` | 7 | 22.2s |  |
| 100 | `Video-v6` | 85 | 4.7s |  |
| 101 | `Video-v7` | 85 | 4.2s |  |
| 102 | `Video-v8` | 85 | 2.5s |  |
| 103 | `XMLSocket-v5` | 35 | 21.7s |  |
| 104 | `XMLSocket-v6` | 35 | 3.1s |  |
| 105 | `XMLSocket-v7` | 35 | 2.8s |  |
| 106 | `XMLSocket-v8` | 35 | 2.1s |  |
| 107 | `argstest-v5` | 4 | 2.6s |  |
| 108 | `case-v5` | 39 | 3.5s |  |
| 109 | `case-v6` | 73 | 4.4s |  |
| 110 | `case-v7` | 67 | 4.3s |  |
| 111 | `case-v8` | 67 | 2.4s |  |
| 112 | `delete-v5` | 61 | 22.7s |  |
| 113 | `delete-v6` | 61 | 3.1s |  |
| 114 | `delete-v7` | 61 | 3.2s |  |
| 115 | `delete-v8` | 61 | 2.2s |  |
| 116 | `enumerate-v5` | 6 | 2.5s |  |
| 117 | `enumerate-v6` | 49 | 3.6s |  |
| 118 | `enumerate-v7` | 49 | 3.2s |  |
| 119 | `enumerate-v8` | 49 | 2.0s |  |
| 120 | `flash-v5` | 10 | 21.6s |  |
| 121 | `flash-v6` | 10 | 2.7s |  |
| 122 | `flash-v7` | 10 | 2.4s |  |
| 123 | `flash-v8` | 41 | 22.6s |  |
| 124 | `getvariable-v5` | 58 | 3.9s |  |
| 125 | `getvariable-v6` | 64 | 4.1s |  |
| 126 | `getvariable-v7` | 64 | 4.1s |  |
| 127 | `getvariable-v8` | 64 | 2.3s |  |
| 128 | `swap-v5` | 7 | 21.3s |  |
| 129 | `swap-v6` | 7 | 1.3s |  |
| 130 | `swap-v7` | 7 | 2.3s |  |
| 131 | `swap-v8` | 7 | 2.1s |  |
| 132 | `targetPath-v5` | 12 | 2.7s |  |
| 133 | `targetPath-v6` | 23 | 2.9s |  |
| 134 | `targetPath-v7` | 23 | 2.5s |  |
| 135 | `targetPath-v8` | 23 | 2.1s |  |

## Ruffle-Matched Tests

**92 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 26.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.5s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.5s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 25.2s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.5s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.8s |  |
| 9 | `Camera-v6` | 57 | 57 | 5.2s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.7s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.4s |  |
| 12 | `Date-v5` | 7 | 7 | 32.8s |  |
| 13 | `Date-v6` | 6 | 6 | 15.5s |  |
| 14 | `Date-v7` | 6 | 6 | 15.9s |  |
| 15 | `Date-v8` | 6 | 6 | 2.8s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.7s |  |
| 17 | `Function-v5` | 14 | 24 | 25.2s |  |
| 18 | `Function-v6` | 8 | 33 | 10.1s |  |
| 19 | `Function-v7` | 8 | 33 | 10.4s |  |
| 20 | `Function-v8` | 8 | 33 | 29.1s |  |
| 21 | `Global-v6` | 9 | 10 | 27.5s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.7s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.3s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.1s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 17.2s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 4.9s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 5.0s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 1.8s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.2s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.8s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 3.1s |  |
| 32 | `Math-v5` | 5 | 5 | 13.8s |  |
| 33 | `Math-v6` | 5 | 5 | 1.4s |  |
| 34 | `Math-v7` | 5 | 5 | 14.4s |  |
| 35 | `Math-v8` | 5 | 5 | 2.6s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.5s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.4s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.6s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.4s |  |
| 40 | `Microphone-v7` | 31 | 31 | 4.0s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.4s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 32.7s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 5.3s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.7s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 6.2s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 6.5s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.7s |  |
| 48 | `Number-v5` | 8 | 12 | 10.2s |  |
| 49 | `Object-v5` | 3 | 6 | 26.6s |  |
| 50 | `Object-v6` | 8 | 24 | 13.8s |  |
| 51 | `Object-v7` | 8 | 15 | 14.1s |  |
| 52 | `Object-v8` | 8 | 15 | 3.2s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 7.9s |  |
| 54 | `Selection-v6` | 7 | 13 | 6.0s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.6s |  |
| 56 | `Selection-v8` | 7 | 13 | 2.4s |  |
| 57 | `Sound-v5` | 16 | 16 | 24.5s |  |
| 58 | `Stage-v6` | 14 | 14 | 24.9s |  |
| 59 | `Stage-v7` | 14 | 14 | 5.4s |  |
| 60 | `Stage-v8` | 14 | 14 | 3.1s |  |
| 61 | `String-v5` | 19 | 21 | 24.0s |  |
| 62 | `String-v6` | 10 | 10 | 19.5s |  |
| 63 | `String-v7` | 10 | 10 | 18.1s |  |
| 64 | `String-v8` | 10 | 10 | 2.9s |  |
| 65 | `TextField-v5` | 3 | 3 | 2.9s |  |
| 66 | `TextFormat-v7` | 38 | 40 | 7.8s |  |
| 67 | `TextFormat-v8` | 36 | 38 | 27.7s |  |
| 68 | `Transform-v8` | 7 | 11 | 20.6s |  |
| 69 | `XML-v5` | 10 | 79 | 36.5s |  |
| 70 | `XML-v6` | 3 | 98 | 17.9s |  |
| 71 | `XML-v7` | 3 | 98 | 17.7s |  |
| 72 | `XML-v8` | 24 | 116 | 6.1s |  |
| 73 | `XMLNode-v5` | 3 | 22 | 9.9s |  |
| 74 | `XMLNode-v6` | 3 | 22 | 10.1s |  |
| 75 | `XMLNode-v7` | 3 | 22 | 8.8s |  |
| 76 | `XMLNode-v8` | 3 | 22 | 2.6s |  |
| 77 | `ops-v5` | 7 | 9 | 25.6s |  |
| 78 | `ops-v6` | 7 | 11 | 9.5s |  |
| 79 | `ops-v7` | 7 | 11 | 9.7s |  |
| 80 | `ops-v8` | 7 | 11 | 18.0s |  |
| 81 | `setProperty-v5` | 49 | 49 | 3.4s |  |
| 82 | `setProperty-v6` | 49 | 49 | 3.7s |  |
| 83 | `setProperty-v7` | 49 | 49 | 3.3s |  |
| 84 | `setProperty-v8` | 49 | 49 | 2.2s |  |
| 85 | `toString_valueOf-v5` | 34 | 34 | 26.4s |  |
| 86 | `toString_valueOf-v6` | 5 | 5 | 7.1s |  |
| 87 | `toString_valueOf-v7` | 5 | 5 | 7.2s |  |
| 88 | `toString_valueOf-v8` | 5 | 5 | 2.8s |  |
| 89 | `with-v5` | 3 | 3 | 5.2s |  |
| 90 | `with-v6` | 6 | 9 | 6.5s |  |
| 91 | `with-v7` | 6 | 9 | 6.1s |  |
| 92 | `with-v8` | 6 | 9 | 2.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 98.4% | 551 | 560 | 9 |  |
| 2 | `array-v6` | 96.7% | 623 | 644 | 21 |  |
| 3 | `MovieClip-v7` | 96.4% | 934 | 969 | 35 |  |
| 4 | `MovieClip-v6` | 96.3% | 901 | 936 | 35 |  |
| 5 | `MovieClip-v8` | 93.8% | 1020 | 1087 | 67 |  |
| 6 | `Sound-v6` | 93.4% | 113 | 121 | 8 |  |
| 7 | `Sound-v7` | 93.4% | 113 | 121 | 8 |  |
| 8 | `Sound-v8` | 93.4% | 113 | 121 | 8 |  |
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
| 2 | `array-v6` | 96.7% | 623/644 | 644 | 644 |  |
| 3 | `MovieClip-v7` | 96.4% | 934/969 | 954 | 969 |  |
| 4 | `MovieClip-v6` | 96.3% | 901/936 | 921 | 936 |  |
| 5 | `MovieClip-v8` | 93.8% | 1020/1087 | 1072 | 1087 |  |
| 6 | `Sound-v6` | 93.4% | 113/121 | 121 | 121 |  |
| 7 | `Sound-v7` | 93.4% | 113/121 | 121 | 121 |  |
| 8 | `Sound-v8` | 93.4% | 113/121 | 121 | 121 |  |
| 9 | `array-v7` | 92.4% | 604/654 | 654 | 654 |  |
| 10 | `array-v8` | 92.4% | 604/654 | 654 | 654 |  |
| 11 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 12 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 13 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 14 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 15 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 16 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
