# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-21 16:42 UTC

**Git SHA**: `a5c8f86ee1`

**Run Duration**: 26m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **135** (55.6%) |
| Ruffle-matched | 95 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (94.7%) |
| Failing | 13 |
| Total expected lines | 38791 |
| Matching lines | 30356 (78.3%) |
| Mismatched lines | 8435 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**135 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.5s |  |
| 2 | `Accessibility-v6` | 19 | 0.5s |  |
| 3 | `Accessibility-v7` | 19 | 0.5s |  |
| 4 | `Accessibility-v8` | 19 | 0.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.5s |  |
| 6 | `BitmapData-v5` | 7 | 2.1s |  |
| 7 | `BitmapData-v6` | 7 | 0.7s |  |
| 8 | `BitmapData-v7` | 7 | 1.7s |  |
| 9 | `Boolean-v5` | 38 | 2.6s |  |
| 10 | `Boolean-v6` | 38 | 2.1s |  |
| 11 | `Boolean-v7` | 38 | 2.5s |  |
| 12 | `Boolean-v8` | 38 | 1.4s |  |
| 13 | `Camera-v5` | 7 | 1.6s |  |
| 14 | `Color-v5` | 140 | 5.3s |  |
| 15 | `Color-v6` | 171 | 6.5s |  |
| 16 | `Color-v7` | 161 | 6.2s |  |
| 17 | `Color-v8` | 161 | 6.7s |  |
| 18 | `ColorTransform-v5` | 7 | 2.0s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.7s |  |
| 21 | `ColorTransform-v8` | 55 | 3.4s |  |
| 22 | `ContextMenu-v5` | 7 | 2.1s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 5.1s |  |
| 25 | `ContextMenu-v8` | 131 | 5.1s |  |
| 26 | `Error-v5` | 28 | 2.4s |  |
| 27 | `Error-v6` | 31 | 2.5s |  |
| 28 | `Error-v7` | 31 | 2.1s |  |
| 29 | `Error-v8` | 31 | 2.4s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.0s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.8s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.5s |  |
| 33 | `Global-v5` | 172 | 7.5s |  |
| 34 | `Global-v7` | 182 | 7.7s |  |
| 35 | `Global-v8` | 169 | 7.2s |  |
| 36 | `Instance-v5` | 52 | 3.2s |  |
| 37 | `Instance-v6` | 52 | 1.8s |  |
| 38 | `Instance-v7` | 52 | 2.9s |  |
| 39 | `Instance-v8` | 52 | 1.6s |  |
| 40 | `Key-v5` | 51 | 2.9s |  |
| 41 | `Key-v6` | 55 | 3.0s |  |
| 42 | `Key-v7` | 55 | 2.7s |  |
| 43 | `Key-v8` | 55 | 1.5s |  |
| 44 | `LoadVars-v5` | 8 | 20.8s |  |
| 45 | `LocalConnection-v5` | 7 | 2.2s |  |
| 46 | `LocalConnection-v6` | 58 | 3.5s |  |
| 47 | `LocalConnection-v7` | 58 | 3.1s |  |
| 48 | `LocalConnection-v8` | 58 | 1.6s |  |
| 49 | `Matrix-v5` | 7 | 2.0s |  |
| 50 | `Microphone-v5` | 6 | 1.4s |  |
| 51 | `Mouse-v5` | 13 | 2.0s |  |
| 52 | `Mouse-v6` | 21 | 2.2s |  |
| 53 | `Mouse-v7` | 21 | 1.8s |  |
| 54 | `Mouse-v8` | 21 | 1.4s |  |
| 55 | `MovieClipLoader-v5` | 6 | 13.3s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.4s |  |
| 57 | `NetConnection-v5` | 7 | 1.4s |  |
| 58 | `NetStream-v5` | 6 | 2.1s |  |
| 59 | `NetStream-v6` | 80 | 4.0s |  |
| 60 | `NetStream-v7` | 80 | 3.6s |  |
| 61 | `NetStream-v8` | 80 | 1.6s |  |
| 62 | `Number-v6` | 239 | 9.7s |  |
| 63 | `Number-v7` | 237 | 9.7s |  |
| 64 | `Number-v8` | 237 | 1.8s |  |
| 65 | `Point-v5` | 7 | 2.0s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.7s |  |
| 68 | `Point-v8` | 193 | 8.6s |  |
| 69 | `Random-v5` | 30 | 2.6s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.3s |  |
| 72 | `Random-v8` | 30 | 1.6s |  |
| 73 | `Rectangle-v5` | 7 | 2.1s |  |
| 74 | `Rectangle-v6` | 7 | 0.7s |  |
| 75 | `Rectangle-v7` | 7 | 1.8s |  |
| 76 | `Selection-v5` | 21 | 2.3s |  |
| 77 | `Stage-v5` | 38 | 2.6s |  |
| 78 | `System-v5` | 67 | 3.5s |  |
| 79 | `System-v6` | 100 | 4.2s |  |
| 80 | `System-v7` | 101 | 4.3s |  |
| 81 | `System-v8` | 101 | 1.5s |  |
| 82 | `TextFieldHTML-v5` | 6 | 2.0s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.2s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.4s |  |
| 86 | `TextFormat-v5` | 128 | 5.0s |  |
| 87 | `TextFormat-v6` | 128 | 0.7s |  |
| 88 | `TextSnapshot-v5` | 7 | 1.5s |  |
| 89 | `TextSnapshot-v6` | 173 | 5.7s |  |
| 90 | `TextSnapshot-v7` | 173 | 5.4s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 92 | `Transform-v5` | 7 | 1.6s |  |
| 93 | `Transform-v6` | 7 | 1.1s |  |
| 94 | `Transform-v7` | 7 | 1.2s |  |
| 95 | `Try-v5` | 20 | 3.0s |  |
| 96 | `Try-v6` | 20 | 0.6s |  |
| 97 | `Try-v7` | 20 | 2.6s |  |
| 98 | `Try-v8` | 20 | 1.4s |  |
| 99 | `Video-v5` | 7 | 20.3s |  |
| 100 | `Video-v6` | 85 | 3.7s |  |
| 101 | `Video-v7` | 85 | 3.3s |  |
| 102 | `Video-v8` | 85 | 1.6s |  |
| 103 | `XMLSocket-v5` | 35 | 2.6s |  |
| 104 | `XMLSocket-v6` | 35 | 2.6s |  |
| 105 | `XMLSocket-v7` | 35 | 2.2s |  |
| 106 | `XMLSocket-v8` | 35 | 1.5s |  |
| 107 | `argstest-v5` | 4 | 2.1s |  |
| 108 | `case-v5` | 39 | 2.4s |  |
| 109 | `case-v6` | 73 | 3.2s |  |
| 110 | `case-v7` | 67 | 3.1s |  |
| 111 | `case-v8` | 67 | 1.3s |  |
| 112 | `delete-v5` | 61 | 1.2s |  |
| 113 | `delete-v6` | 61 | 0.8s |  |
| 114 | `delete-v7` | 61 | 0.9s |  |
| 115 | `delete-v8` | 61 | 0.8s |  |
| 116 | `enumerate-v5` | 6 | 1.0s |  |
| 117 | `enumerate-v6` | 49 | 0.9s |  |
| 118 | `enumerate-v7` | 49 | 0.8s |  |
| 119 | `enumerate-v8` | 49 | 0.8s |  |
| 120 | `flash-v5` | 10 | 2.1s |  |
| 121 | `flash-v6` | 10 | 2.1s |  |
| 122 | `flash-v7` | 10 | 1.7s |  |
| 123 | `flash-v8` | 41 | 21.1s |  |
| 124 | `getvariable-v5` | 58 | 3.2s |  |
| 125 | `getvariable-v6` | 64 | 3.3s |  |
| 126 | `getvariable-v7` | 64 | 3.4s |  |
| 127 | `getvariable-v8` | 64 | 1.6s |  |
| 128 | `swap-v5` | 7 | 0.7s |  |
| 129 | `swap-v6` | 7 | 0.4s |  |
| 130 | `swap-v7` | 7 | 0.7s |  |
| 131 | `swap-v8` | 7 | 0.7s |  |
| 132 | `targetPath-v5` | 12 | 0.7s |  |
| 133 | `targetPath-v6` | 23 | 0.7s |  |
| 134 | `targetPath-v7` | 23 | 0.7s |  |
| 135 | `targetPath-v8` | 23 | 0.7s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 0.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.5s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.5s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.5s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.1s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.7s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.9s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.0s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.6s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.5s |  |
| 12 | `Date-v5` | 7 | 7 | 32.3s |  |
| 13 | `Date-v6` | 6 | 6 | 15.2s |  |
| 14 | `Date-v7` | 6 | 6 | 15.6s |  |
| 15 | `Date-v8` | 6 | 6 | 2.0s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.9s |  |
| 17 | `Function-v5` | 14 | 24 | 23.8s |  |
| 18 | `Function-v6` | 8 | 33 | 9.4s |  |
| 19 | `Function-v7` | 8 | 33 | 9.6s |  |
| 20 | `Function-v8` | 8 | 33 | 29.9s |  |
| 21 | `Global-v6` | 9 | 10 | 8.9s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.3s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.9s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.9s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 5.2s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.5s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.2s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 5.8s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.5s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.4s |  |
| 32 | `Math-v5` | 5 | 5 | 15.0s |  |
| 33 | `Math-v6` | 5 | 5 | 0.7s |  |
| 34 | `Math-v7` | 5 | 5 | 15.4s |  |
| 35 | `Math-v8` | 5 | 5 | 1.9s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.3s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.4s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.6s |  |
| 39 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.1s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.5s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 30.4s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 2.6s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 1.7s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 3.6s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 3.8s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 48 | `Number-v5` | 8 | 12 | 10.0s |  |
| 49 | `Object-v5` | 3 | 6 | 25.6s |  |
| 50 | `Object-v6` | 9 | 24 | 14.6s |  |
| 51 | `Object-v7` | 8 | 15 | 14.4s |  |
| 52 | `Object-v8` | 8 | 15 | 2.4s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 7.5s |  |
| 54 | `Selection-v6` | 7 | 13 | 5.4s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.6s |  |
| 57 | `Sound-v5` | 16 | 16 | 24.3s |  |
| 58 | `Sound-v6` | 8 | 37 | 5.2s |  |
| 59 | `Sound-v7` | 8 | 37 | 5.1s |  |
| 60 | `Sound-v8` | 8 | 37 | 1.9s |  |
| 61 | `Stage-v6` | 14 | 14 | 21.6s |  |
| 62 | `Stage-v7` | 14 | 14 | 2.9s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.6s |  |
| 64 | `String-v5` | 19 | 21 | 16.6s |  |
| 65 | `String-v6` | 10 | 10 | 17.4s |  |
| 66 | `String-v7` | 10 | 10 | 17.3s |  |
| 67 | `String-v8` | 10 | 10 | 2.0s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.2s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 6.8s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 25.0s |  |
| 71 | `Transform-v8` | 7 | 11 | 19.3s |  |
| 72 | `XML-v5` | 10 | 79 | 32.3s |  |
| 73 | `XML-v6` | 3 | 98 | 15.4s |  |
| 74 | `XML-v7` | 3 | 98 | 15.2s |  |
| 75 | `XML-v8` | 24 | 116 | 4.5s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 8.3s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.3s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 7.3s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.7s |  |
| 80 | `ops-v5` | 7 | 9 | 28.4s |  |
| 81 | `ops-v6` | 7 | 11 | 9.2s |  |
| 82 | `ops-v7` | 7 | 11 | 9.9s |  |
| 83 | `ops-v8` | 7 | 11 | 1.7s |  |
| 84 | `setProperty-v5` | 49 | 49 | 3.1s |  |
| 85 | `setProperty-v6` | 49 | 49 | 3.1s |  |
| 86 | `setProperty-v7` | 49 | 49 | 2.8s |  |
| 87 | `setProperty-v8` | 49 | 49 | 1.8s |  |
| 88 | `toString_valueOf-v5` | 34 | 34 | 0.9s |  |
| 89 | `toString_valueOf-v6` | 5 | 5 | 0.8s |  |
| 90 | `toString_valueOf-v7` | 5 | 5 | 0.8s |  |
| 91 | `toString_valueOf-v8` | 5 | 5 | 0.8s |  |
| 92 | `with-v5` | 3 | 3 | 0.8s |  |
| 93 | `with-v6` | 6 | 9 | 0.8s |  |
| 94 | `with-v7` | 6 | 9 | 0.8s |  |
| 95 | `with-v8` | 6 | 9 | 0.8s |  |

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
