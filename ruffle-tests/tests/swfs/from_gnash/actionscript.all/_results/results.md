# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-05 04:40 UTC

**Git SHA**: `7f7a6ba369`

**Run Duration**: 30m 30s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **141** (58.0%) |
| Ruffle-matched | 89 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (94.7%) |
| Failing | 13 |
| Total expected lines | 38791 |
| Matching lines | 30418 (78.4%) |
| Mismatched lines | 8373 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**141 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.2s |  |
| 2 | `Accessibility-v6` | 19 | 2.2s |  |
| 3 | `Accessibility-v7` | 19 | 1.9s |  |
| 4 | `Accessibility-v8` | 19 | 1.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.1s |  |
| 6 | `BitmapData-v5` | 7 | 1.8s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.5s |  |
| 9 | `Boolean-v5` | 38 | 2.3s |  |
| 10 | `Boolean-v6` | 38 | 1.8s |  |
| 11 | `Boolean-v7` | 38 | 21.7s |  |
| 12 | `Boolean-v8` | 38 | 1.5s |  |
| 13 | `Camera-v5` | 7 | 2.1s |  |
| 14 | `Color-v5` | 140 | 5.4s |  |
| 15 | `Color-v6` | 171 | 6.5s |  |
| 16 | `Color-v7` | 161 | 6.2s |  |
| 17 | `Color-v8` | 161 | 26.7s |  |
| 18 | `ColorTransform-v5` | 7 | 2.1s |  |
| 19 | `ColorTransform-v6` | 7 | 0.7s |  |
| 20 | `ColorTransform-v7` | 7 | 1.8s |  |
| 21 | `ColorTransform-v8` | 55 | 3.4s |  |
| 22 | `ContextMenu-v5` | 7 | 2.1s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 4.9s |  |
| 25 | `ContextMenu-v8` | 131 | 20.0s |  |
| 26 | `Error-v5` | 28 | 1.9s |  |
| 27 | `Error-v6` | 31 | 1.9s |  |
| 28 | `Error-v7` | 31 | 1.6s |  |
| 29 | `Error-v8` | 31 | 21.7s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.9s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 33 | `Function-v6` | 271 | 9.6s |  |
| 34 | `Function-v7` | 272 | 9.8s |  |
| 35 | `Function-v8` | 272 | 31.5s |  |
| 36 | `Global-v5` | 172 | 8.0s |  |
| 37 | `Global-v7` | 182 | 8.3s |  |
| 38 | `Global-v8` | 169 | 7.5s |  |
| 39 | `Instance-v5` | 52 | 2.4s |  |
| 40 | `Instance-v6` | 52 | 1.3s |  |
| 41 | `Instance-v7` | 52 | 2.3s |  |
| 42 | `Instance-v8` | 52 | 1.2s |  |
| 43 | `Key-v5` | 51 | 21.9s |  |
| 44 | `Key-v6` | 55 | 3.0s |  |
| 45 | `Key-v7` | 55 | 2.6s |  |
| 46 | `Key-v8` | 55 | 1.6s |  |
| 47 | `LoadVars-v5` | 8 | 2.1s |  |
| 48 | `LocalConnection-v5` | 7 | 21.8s |  |
| 49 | `LocalConnection-v6` | 58 | 3.4s |  |
| 50 | `LocalConnection-v7` | 58 | 3.0s |  |
| 51 | `LocalConnection-v8` | 58 | 1.6s |  |
| 52 | `Matrix-v5` | 7 | 16.8s |  |
| 53 | `Microphone-v5` | 6 | 1.7s |  |
| 54 | `Mouse-v5` | 13 | 21.4s |  |
| 55 | `Mouse-v6` | 21 | 2.3s |  |
| 56 | `Mouse-v7` | 21 | 2.0s |  |
| 57 | `Mouse-v8` | 21 | 1.6s |  |
| 58 | `MovieClipLoader-v5` | 6 | 21.4s |  |
| 59 | `MovieClipLoader-v6` | 6 | 0.7s |  |
| 60 | `NetConnection-v5` | 7 | 2.1s |  |
| 61 | `NetStream-v5` | 6 | 21.1s |  |
| 62 | `NetStream-v6` | 80 | 3.7s |  |
| 63 | `NetStream-v7` | 80 | 3.3s |  |
| 64 | `NetStream-v8` | 80 | 1.6s |  |
| 65 | `Number-v6` | 239 | 9.0s |  |
| 66 | `Number-v7` | 237 | 9.0s |  |
| 67 | `Number-v8` | 237 | 1.8s |  |
| 68 | `Point-v5` | 7 | 2.2s |  |
| 69 | `Point-v6` | 7 | 0.7s |  |
| 70 | `Point-v7` | 7 | 1.8s |  |
| 71 | `Point-v8` | 193 | 8.6s |  |
| 72 | `Random-v5` | 30 | 22.3s |  |
| 73 | `Random-v6` | 30 | 0.7s |  |
| 74 | `Random-v7` | 30 | 2.3s |  |
| 75 | `Random-v8` | 30 | 1.6s |  |
| 76 | `Rectangle-v5` | 7 | 2.1s |  |
| 77 | `Rectangle-v6` | 7 | 0.7s |  |
| 78 | `Rectangle-v7` | 7 | 1.8s |  |
| 79 | `Selection-v5` | 21 | 21.7s |  |
| 80 | `Sound-v6` | 121 | 5.5s |  |
| 81 | `Sound-v7` | 121 | 5.1s |  |
| 82 | `Sound-v8` | 121 | 2.0s |  |
| 83 | `Stage-v5` | 38 | 18.4s |  |
| 84 | `System-v5` | 67 | 22.2s |  |
| 85 | `System-v6` | 100 | 4.1s |  |
| 86 | `System-v7` | 101 | 4.2s |  |
| 87 | `System-v8` | 101 | 1.6s |  |
| 88 | `TextFieldHTML-v5` | 6 | 23.0s |  |
| 89 | `TextFieldHTML-v6` | 37 | 2.8s |  |
| 90 | `TextFieldHTML-v7` | 37 | 2.4s |  |
| 91 | `TextFieldHTML-v8` | 37 | 1.6s |  |
| 92 | `TextFormat-v5` | 128 | 5.4s |  |
| 93 | `TextFormat-v6` | 128 | 0.7s |  |
| 94 | `TextSnapshot-v5` | 7 | 21.5s |  |
| 95 | `TextSnapshot-v6` | 173 | 8.1s |  |
| 96 | `TextSnapshot-v7` | 173 | 7.7s |  |
| 97 | `TextSnapshot-v8` | 173 | 1.8s |  |
| 98 | `Transform-v5` | 7 | 2.1s |  |
| 99 | `Transform-v6` | 7 | 1.6s |  |
| 100 | `Transform-v7` | 7 | 1.8s |  |
| 101 | `Try-v5` | 20 | 22.5s |  |
| 102 | `Try-v6` | 20 | 0.7s |  |
| 103 | `Try-v7` | 20 | 2.6s |  |
| 104 | `Try-v8` | 20 | 1.6s |  |
| 105 | `Video-v5` | 7 | 2.2s |  |
| 106 | `Video-v6` | 85 | 3.7s |  |
| 107 | `Video-v7` | 85 | 3.4s |  |
| 108 | `Video-v8` | 85 | 1.6s |  |
| 109 | `XMLSocket-v5` | 35 | 19.0s |  |
| 110 | `XMLSocket-v6` | 35 | 2.4s |  |
| 111 | `XMLSocket-v7` | 35 | 2.0s |  |
| 112 | `XMLSocket-v8` | 35 | 1.3s |  |
| 113 | `argstest-v5` | 4 | 1.7s |  |
| 114 | `case-v5` | 39 | 2.1s |  |
| 115 | `case-v6` | 73 | 2.7s |  |
| 116 | `case-v7` | 67 | 2.6s |  |
| 117 | `case-v8` | 67 | 1.2s |  |
| 118 | `delete-v5` | 61 | 19.3s |  |
| 119 | `delete-v6` | 61 | 2.1s |  |
| 120 | `delete-v7` | 61 | 2.4s |  |
| 121 | `delete-v8` | 61 | 1.6s |  |
| 122 | `enumerate-v5` | 6 | 1.6s |  |
| 123 | `enumerate-v6` | 49 | 2.5s |  |
| 124 | `enumerate-v7` | 49 | 2.2s |  |
| 125 | `enumerate-v8` | 49 | 1.2s |  |
| 126 | `flash-v5` | 10 | 16.5s |  |
| 127 | `flash-v6` | 10 | 1.5s |  |
| 128 | `flash-v7` | 10 | 1.2s |  |
| 129 | `flash-v8` | 41 | 2.1s |  |
| 130 | `getvariable-v5` | 58 | 2.3s |  |
| 131 | `getvariable-v6` | 64 | 2.5s |  |
| 132 | `getvariable-v7` | 64 | 2.5s |  |
| 133 | `getvariable-v8` | 64 | 1.1s |  |
| 134 | `swap-v5` | 7 | 21.5s |  |
| 135 | `swap-v6` | 7 | 0.7s |  |
| 136 | `swap-v7` | 7 | 1.8s |  |
| 137 | `swap-v8` | 7 | 1.6s |  |
| 138 | `targetPath-v5` | 12 | 2.2s |  |
| 139 | `targetPath-v6` | 23 | 2.4s |  |
| 140 | `targetPath-v7` | 23 | 2.1s |  |
| 141 | `targetPath-v8` | 23 | 1.6s |  |

## Ruffle-Matched Tests

**89 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.3s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.6s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 23.3s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.3s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.5s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 22.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.1s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.7s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.6s |  |
| 12 | `Date-v5` | 7 | 7 | 10.0s |  |
| 13 | `Date-v6` | 6 | 6 | 11.3s |  |
| 14 | `Date-v7` | 6 | 6 | 11.9s |  |
| 15 | `Date-v8` | 6 | 6 | 1.4s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.0s |  |
| 17 | `Function-v5` | 10 | 24 | 5.8s |  |
| 18 | `Global-v6` | 9 | 10 | 9.6s |  |
| 19 | `HitTest-v6` | 8 | 8 | 5.5s |  |
| 20 | `HitTest-v7` | 8 | 8 | 5.2s |  |
| 21 | `HitTest-v8` | 9 | 9 | 5.0s |  |
| 22 | `Inheritance-v5` | 1 | 17 | 20.9s |  |
| 23 | `Inheritance-v6` | 9 | 16 | 5.5s |  |
| 24 | `Inheritance-v7` | 5 | 10 | 5.7s |  |
| 25 | `Inheritance-v8` | 5 | 10 | 1.8s |  |
| 26 | `LoadVars-v6` | 6 | 8 | 5.6s |  |
| 27 | `LoadVars-v7` | 6 | 8 | 5.3s |  |
| 28 | `LoadVars-v8` | 6 | 8 | 2.4s |  |
| 29 | `Math-v5` | 5 | 5 | 14.0s |  |
| 30 | `Math-v6` | 5 | 5 | 0.9s |  |
| 31 | `Math-v7` | 5 | 5 | 14.2s |  |
| 32 | `Math-v8` | 5 | 5 | 1.8s |  |
| 33 | `Matrix-v6` | 29 | 71 | 6.2s |  |
| 34 | `Matrix-v7` | 28 | 70 | 6.6s |  |
| 35 | `Matrix-v8` | 28 | 70 | 1.4s |  |
| 36 | `Microphone-v6` | 31 | 31 | 2.9s |  |
| 37 | `Microphone-v7` | 31 | 31 | 2.5s |  |
| 38 | `Microphone-v8` | 31 | 31 | 1.2s |  |
| 39 | `MovieClip-v5` | 24 | 226 | 13.4s |  |
| 40 | `MovieClipLoader-v7` | 118 | 118 | 4.1s |  |
| 41 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 42 | `NetConnection-v6` | 4 | 49 | 5.2s |  |
| 43 | `NetConnection-v7` | 4 | 45 | 5.2s |  |
| 44 | `NetConnection-v8` | 4 | 45 | 1.7s |  |
| 45 | `Number-v5` | 8 | 12 | 9.1s |  |
| 46 | `Object-v5` | 3 | 6 | 26.5s |  |
| 47 | `Object-v6` | 8 | 24 | 13.5s |  |
| 48 | `Object-v7` | 8 | 15 | 13.7s |  |
| 49 | `Object-v8` | 8 | 15 | 2.5s |  |
| 50 | `Rectangle-v8` | 21 | 21 | 7.1s |  |
| 51 | `Selection-v6` | 7 | 13 | 5.3s |  |
| 52 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 53 | `Selection-v8` | 7 | 13 | 1.6s |  |
| 54 | `Sound-v5` | 14 | 16 | 5.2s |  |
| 55 | `Stage-v6` | 14 | 14 | 2.5s |  |
| 56 | `Stage-v7` | 14 | 14 | 2.2s |  |
| 57 | `Stage-v8` | 14 | 14 | 1.2s |  |
| 58 | `String-v5` | 18 | 21 | 14.0s |  |
| 59 | `String-v6` | 9 | 10 | 14.6s |  |
| 60 | `String-v7` | 9 | 10 | 14.3s |  |
| 61 | `String-v8` | 9 | 10 | 1.5s |  |
| 62 | `TextField-v5` | 3 | 3 | 2.1s |  |
| 63 | `TextFormat-v7` | 38 | 40 | 6.9s |  |
| 64 | `TextFormat-v8` | 36 | 38 | 6.8s |  |
| 65 | `Transform-v8` | 7 | 11 | 5.2s |  |
| 66 | `XML-v5` | 10 | 79 | 34.8s |  |
| 67 | `XML-v6` | 3 | 98 | 16.6s |  |
| 68 | `XML-v7` | 3 | 98 | 16.4s |  |
| 69 | `XML-v8` | 24 | 116 | 5.0s |  |
| 70 | `XMLNode-v5` | 3 | 22 | 8.9s |  |
| 71 | `XMLNode-v6` | 3 | 22 | 9.0s |  |
| 72 | `XMLNode-v7` | 3 | 22 | 7.8s |  |
| 73 | `XMLNode-v8` | 3 | 22 | 1.8s |  |
| 74 | `ops-v5` | 7 | 9 | 28.8s |  |
| 75 | `ops-v6` | 7 | 11 | 9.1s |  |
| 76 | `ops-v7` | 7 | 11 | 9.7s |  |
| 77 | `ops-v8` | 7 | 11 | 1.8s |  |
| 78 | `setProperty-v5` | 49 | 49 | 3.1s |  |
| 79 | `setProperty-v6` | 49 | 49 | 3.1s |  |
| 80 | `setProperty-v7` | 49 | 49 | 2.8s |  |
| 81 | `setProperty-v8` | 49 | 49 | 1.8s |  |
| 82 | `toString_valueOf-v5` | 34 | 34 | 25.6s |  |
| 83 | `toString_valueOf-v6` | 5 | 5 | 5.8s |  |
| 84 | `toString_valueOf-v7` | 5 | 5 | 5.5s |  |
| 85 | `toString_valueOf-v8` | 5 | 5 | 1.7s |  |
| 86 | `with-v5` | 3 | 3 | 3.7s |  |
| 87 | `with-v6` | 6 | 9 | 5.0s |  |
| 88 | `with-v7` | 6 | 9 | 4.7s |  |
| 89 | `with-v8` | 6 | 9 | 1.9s |  |

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
