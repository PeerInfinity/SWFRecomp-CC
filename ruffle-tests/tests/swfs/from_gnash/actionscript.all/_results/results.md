# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-29 01:40 UTC

**Git SHA**: `767a301d2b`

**Run Duration**: 25m 55s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **131** (53.9%) |
| Ruffle-matched | 99 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (94.7%) |
| Failing | 13 |
| Total expected lines | 38791 |
| Matching lines | 30340 (78.2%) |
| Mismatched lines | 8451 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**131 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.1s |  |
| 2 | `Accessibility-v6` | 19 | 2.2s |  |
| 3 | `Accessibility-v7` | 19 | 1.8s |  |
| 4 | `Accessibility-v8` | 19 | 1.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.0s |  |
| 6 | `BitmapData-v5` | 7 | 2.1s |  |
| 7 | `BitmapData-v6` | 7 | 0.7s |  |
| 8 | `BitmapData-v7` | 7 | 1.7s |  |
| 9 | `Boolean-v5` | 38 | 2.6s |  |
| 10 | `Boolean-v6` | 38 | 2.1s |  |
| 11 | `Boolean-v7` | 38 | 2.6s |  |
| 12 | `Boolean-v8` | 38 | 1.5s |  |
| 13 | `Camera-v5` | 7 | 2.0s |  |
| 14 | `Color-v5` | 140 | 5.5s |  |
| 15 | `Color-v6` | 171 | 6.6s |  |
| 16 | `Color-v7` | 161 | 6.2s |  |
| 17 | `Color-v8` | 161 | 26.6s |  |
| 18 | `ColorTransform-v5` | 7 | 2.2s |  |
| 19 | `ColorTransform-v6` | 7 | 0.7s |  |
| 20 | `ColorTransform-v7` | 7 | 1.8s |  |
| 21 | `ColorTransform-v8` | 55 | 3.7s |  |
| 22 | `ContextMenu-v5` | 7 | 2.1s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 5.5s |  |
| 25 | `ContextMenu-v8` | 131 | 5.3s |  |
| 26 | `Error-v5` | 28 | 2.5s |  |
| 27 | `Error-v6` | 31 | 2.6s |  |
| 28 | `Error-v7` | 31 | 2.1s |  |
| 29 | `Error-v8` | 31 | 21.9s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.1s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 33 | `Global-v5` | 172 | 7.1s |  |
| 34 | `Global-v7` | 182 | 7.4s |  |
| 35 | `Global-v8` | 169 | 6.9s |  |
| 36 | `Instance-v5` | 52 | 3.0s |  |
| 37 | `Instance-v6` | 52 | 1.6s |  |
| 38 | `Instance-v7` | 52 | 2.5s |  |
| 39 | `Instance-v8` | 52 | 1.5s |  |
| 40 | `Key-v5` | 51 | 2.6s |  |
| 41 | `Key-v6` | 55 | 2.4s |  |
| 42 | `Key-v7` | 55 | 2.1s |  |
| 43 | `Key-v8` | 55 | 1.2s |  |
| 44 | `LoadVars-v5` | 8 | 1.6s |  |
| 45 | `LocalConnection-v5` | 7 | 20.4s |  |
| 46 | `LocalConnection-v6` | 58 | 3.2s |  |
| 47 | `LocalConnection-v7` | 58 | 2.8s |  |
| 48 | `LocalConnection-v8` | 58 | 1.5s |  |
| 49 | `Matrix-v5` | 7 | 2.0s |  |
| 50 | `Microphone-v5` | 6 | 2.0s |  |
| 51 | `Mouse-v5` | 13 | 2.2s |  |
| 52 | `Mouse-v6` | 21 | 2.3s |  |
| 53 | `Mouse-v7` | 21 | 1.9s |  |
| 54 | `Mouse-v8` | 21 | 1.5s |  |
| 55 | `MovieClipLoader-v5` | 6 | 23.2s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.7s |  |
| 57 | `NetConnection-v5` | 7 | 20.9s |  |
| 58 | `NetStream-v5` | 6 | 2.0s |  |
| 59 | `NetStream-v6` | 80 | 3.7s |  |
| 60 | `NetStream-v7` | 80 | 3.3s |  |
| 61 | `NetStream-v8` | 80 | 1.5s |  |
| 62 | `Number-v6` | 239 | 8.8s |  |
| 63 | `Number-v7` | 237 | 8.9s |  |
| 64 | `Number-v8` | 237 | 1.7s |  |
| 65 | `Point-v5` | 7 | 16.2s |  |
| 66 | `Point-v6` | 7 | 0.5s |  |
| 67 | `Point-v7` | 7 | 1.5s |  |
| 68 | `Point-v8` | 193 | 6.9s |  |
| 69 | `Random-v5` | 30 | 14.9s |  |
| 70 | `Random-v6` | 30 | 0.5s |  |
| 71 | `Random-v7` | 30 | 1.4s |  |
| 72 | `Random-v8` | 30 | 0.9s |  |
| 73 | `Rectangle-v5` | 7 | 1.2s |  |
| 74 | `Rectangle-v6` | 7 | 0.4s |  |
| 75 | `Rectangle-v7` | 7 | 1.0s |  |
| 76 | `Selection-v5` | 21 | 2.3s |  |
| 77 | `Stage-v5` | 38 | 2.6s |  |
| 78 | `System-v5` | 67 | 3.4s |  |
| 79 | `System-v6` | 100 | 4.2s |  |
| 80 | `System-v7` | 101 | 4.4s |  |
| 81 | `System-v8` | 101 | 1.5s |  |
| 82 | `TextFieldHTML-v5` | 6 | 2.0s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.3s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.5s |  |
| 86 | `TextFormat-v5` | 128 | 5.2s |  |
| 87 | `TextFormat-v6` | 128 | 0.7s |  |
| 88 | `TextSnapshot-v5` | 7 | 21.0s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.2s |  |
| 90 | `TextSnapshot-v7` | 173 | 7.8s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.6s |  |
| 92 | `Transform-v5` | 7 | 2.0s |  |
| 93 | `Transform-v6` | 7 | 1.5s |  |
| 94 | `Transform-v7` | 7 | 1.7s |  |
| 95 | `Try-v5` | 20 | 2.9s |  |
| 96 | `Try-v6` | 20 | 0.7s |  |
| 97 | `Try-v7` | 20 | 2.5s |  |
| 98 | `Try-v8` | 20 | 1.5s |  |
| 99 | `Video-v5` | 7 | 2.1s |  |
| 100 | `Video-v6` | 85 | 3.8s |  |
| 101 | `Video-v7` | 85 | 3.4s |  |
| 102 | `Video-v8` | 85 | 1.6s |  |
| 103 | `argstest-v5` | 4 | 2.1s |  |
| 104 | `case-v5` | 39 | 2.7s |  |
| 105 | `case-v6` | 73 | 3.6s |  |
| 106 | `case-v7` | 67 | 3.6s |  |
| 107 | `case-v8` | 67 | 1.5s |  |
| 108 | `delete-v5` | 61 | 3.7s |  |
| 109 | `delete-v6` | 61 | 2.9s |  |
| 110 | `delete-v7` | 61 | 3.1s |  |
| 111 | `delete-v8` | 61 | 1.8s |  |
| 112 | `enumerate-v5` | 6 | 2.2s |  |
| 113 | `enumerate-v6` | 49 | 3.5s |  |
| 114 | `enumerate-v7` | 49 | 3.1s |  |
| 115 | `enumerate-v8` | 49 | 1.7s |  |
| 116 | `flash-v5` | 10 | 2.2s |  |
| 117 | `flash-v6` | 10 | 2.2s |  |
| 118 | `flash-v7` | 10 | 1.8s |  |
| 119 | `flash-v8` | 41 | 3.3s |  |
| 120 | `getvariable-v5` | 58 | 3.7s |  |
| 121 | `getvariable-v6` | 64 | 3.6s |  |
| 122 | `getvariable-v7` | 64 | 3.6s |  |
| 123 | `getvariable-v8` | 64 | 1.7s |  |
| 124 | `swap-v5` | 7 | 1.8s |  |
| 125 | `swap-v6` | 7 | 0.5s |  |
| 126 | `swap-v7` | 7 | 1.4s |  |
| 127 | `swap-v8` | 7 | 1.2s |  |
| 128 | `targetPath-v5` | 12 | 1.9s |  |
| 129 | `targetPath-v6` | 23 | 2.1s |  |
| 130 | `targetPath-v7` | 23 | 1.7s |  |
| 131 | `targetPath-v8` | 23 | 1.3s |  |

## Ruffle-Matched Tests

**99 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 5.4s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.6s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.4s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.0s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.7s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 24.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.1s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.7s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.5s |  |
| 12 | `Date-v5` | 7 | 7 | 14.3s |  |
| 13 | `Date-v6` | 6 | 6 | 15.6s |  |
| 14 | `Date-v7` | 6 | 6 | 16.0s |  |
| 15 | `Date-v8` | 6 | 6 | 2.0s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.1s |  |
| 17 | `Function-v5` | 14 | 24 | 25.0s |  |
| 18 | `Function-v6` | 8 | 33 | 9.8s |  |
| 19 | `Function-v7` | 8 | 33 | 10.0s |  |
| 20 | `Function-v8` | 8 | 33 | 9.6s |  |
| 21 | `Global-v6` | 9 | 10 | 8.3s |  |
| 22 | `HitTest-v6` | 8 | 8 | 4.8s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.6s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.4s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 23.3s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 6.9s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.1s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.0s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 4.2s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 4.0s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 1.9s |  |
| 32 | `Math-v5` | 5 | 5 | 13.5s |  |
| 33 | `Math-v6` | 5 | 5 | 0.7s |  |
| 34 | `Math-v7` | 5 | 5 | 14.1s |  |
| 35 | `Math-v8` | 5 | 5 | 1.8s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.5s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.5s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.5s |  |
| 39 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.1s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.4s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 13.9s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.2s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.8s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.3s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.6s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.7s |  |
| 48 | `Number-v5` | 8 | 12 | 9.1s |  |
| 49 | `Object-v5` | 3 | 6 | 19.9s |  |
| 50 | `Object-v6` | 9 | 24 | 11.0s |  |
| 51 | `Object-v7` | 8 | 15 | 11.1s |  |
| 52 | `Object-v8` | 8 | 15 | 1.9s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 5.1s |  |
| 54 | `Selection-v6` | 7 | 13 | 5.4s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.0s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.6s |  |
| 57 | `Sound-v5` | 16 | 16 | 5.3s |  |
| 58 | `Sound-v6` | 8 | 37 | 5.3s |  |
| 59 | `Sound-v7` | 8 | 37 | 5.0s |  |
| 60 | `Sound-v8` | 8 | 37 | 2.0s |  |
| 61 | `Stage-v6` | 14 | 14 | 3.1s |  |
| 62 | `Stage-v7` | 14 | 14 | 2.8s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.6s |  |
| 64 | `String-v5` | 19 | 21 | 16.0s |  |
| 65 | `String-v6` | 10 | 10 | 16.5s |  |
| 66 | `String-v7` | 10 | 10 | 16.5s |  |
| 67 | `String-v8` | 10 | 10 | 2.0s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.1s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 7.0s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 7.0s |  |
| 71 | `Transform-v8` | 7 | 11 | 24.2s |  |
| 72 | `XML-v5` | 10 | 79 | 31.7s |  |
| 73 | `XML-v6` | 3 | 98 | 14.9s |  |
| 74 | `XML-v7` | 3 | 98 | 15.4s |  |
| 75 | `XML-v8` | 24 | 116 | 4.5s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 7.8s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.5s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 7.2s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.8s |  |
| 80 | `XMLSocket-v5` | 4 | 7 | 2.6s |  |
| 81 | `XMLSocket-v6` | 4 | 7 | 2.6s |  |
| 82 | `XMLSocket-v7` | 4 | 7 | 2.2s |  |
| 83 | `XMLSocket-v8` | 4 | 7 | 1.6s |  |
| 84 | `ops-v5` | 7 | 9 | 20.4s |  |
| 85 | `ops-v6` | 7 | 11 | 6.3s |  |
| 86 | `ops-v7` | 7 | 11 | 7.0s |  |
| 87 | `ops-v8` | 7 | 11 | 14.6s |  |
| 88 | `setProperty-v5` | 49 | 49 | 2.2s |  |
| 89 | `setProperty-v6` | 49 | 49 | 2.3s |  |
| 90 | `setProperty-v7` | 49 | 49 | 2.1s |  |
| 91 | `setProperty-v8` | 49 | 49 | 1.4s |  |
| 92 | `toString_valueOf-v5` | 34 | 34 | 5.0s |  |
| 93 | `toString_valueOf-v6` | 5 | 5 | 5.4s |  |
| 94 | `toString_valueOf-v7` | 5 | 5 | 5.0s |  |
| 95 | `toString_valueOf-v8` | 5 | 5 | 1.6s |  |
| 96 | `with-v5` | 3 | 3 | 3.5s |  |
| 97 | `with-v6` | 6 | 9 | 4.7s |  |
| 98 | `with-v7` | 6 | 9 | 4.3s |  |
| 99 | `with-v8` | 6 | 9 | 1.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 98.6% | 552 | 560 | 8 |  |
| 2 | `array-v6` | 96.9% | 624 | 644 | 20 |  |
| 3 | `MovieClip-v7` | 96.4% | 934 | 969 | 35 |  |
| 4 | `MovieClip-v6` | 96.3% | 901 | 936 | 35 |  |
| 5 | `MovieClip-v8` | 93.8% | 1020 | 1087 | 67 |  |
| 6 | `array-v7` | 92.2% | 603 | 654 | 51 |  |
| 7 | `array-v8` | 92.2% | 603 | 654 | 51 |  |
| 8 | `TextField-v6` | 85.5% | 466 | 545 | 79 |  |
| 9 | `TextField-v8` | 83.5% | 477 | 571 | 94 |  |
| 10 | `TextField-v7` | 83.3% | 475 | 570 | 95 |  |

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
| 1 | `array-v5` | 98.6% | 552/560 | 560 | 560 |  |
| 2 | `array-v6` | 96.9% | 624/644 | 644 | 644 |  |
| 3 | `MovieClip-v7` | 96.4% | 934/969 | 954 | 969 |  |
| 4 | `MovieClip-v6` | 96.3% | 901/936 | 921 | 936 |  |
| 5 | `MovieClip-v8` | 93.8% | 1020/1087 | 1072 | 1087 |  |
| 6 | `array-v7` | 92.2% | 603/654 | 654 | 654 |  |
| 7 | `array-v8` | 92.2% | 603/654 | 654 | 654 |  |
| 8 | `TextField-v6` | 85.5% | 466/545 | 545 | 545 |  |
| 9 | `TextField-v8` | 83.5% | 477/571 | 571 | 571 |  |
| 10 | `TextField-v7` | 83.3% | 475/570 | 570 | 570 |  |
| 11 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 12 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 13 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
