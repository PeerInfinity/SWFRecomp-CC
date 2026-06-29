# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-29 20:06 UTC

**Git SHA**: `b980ca79e3`

**Run Duration**: 38m 31s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 235 |
| Passing | **128** (54.5%) |
| Ruffle-matched | 94 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **222** (94.5%) |
| Failing | 13 |
| Total expected lines | 38484 |
| Matching lines | 29815 (77.5%) |
| Mismatched lines | 8669 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**128 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.6s |  |
| 2 | `Accessibility-v6` | 19 | 2.7s |  |
| 3 | `Accessibility-v7` | 19 | 2.3s |  |
| 4 | `Accessibility-v8` | 19 | 1.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.5s |  |
| 6 | `BitmapData-v5` | 7 | 2.8s |  |
| 7 | `BitmapData-v6` | 7 | 1.2s |  |
| 8 | `BitmapData-v7` | 7 | 2.3s |  |
| 9 | `Boolean-v5` | 38 | 3.3s |  |
| 10 | `Boolean-v6` | 38 | 2.7s |  |
| 11 | `Boolean-v7` | 38 | 23.4s |  |
| 12 | `Boolean-v8` | 38 | 2.3s |  |
| 13 | `Camera-v5` | 7 | 2.7s |  |
| 14 | `Color-v5` | 140 | 6.8s |  |
| 15 | `Color-v6` | 171 | 7.8s |  |
| 16 | `Color-v7` | 161 | 7.4s |  |
| 17 | `Color-v8` | 161 | 25.0s |  |
| 18 | `ColorTransform-v5` | 7 | 2.5s |  |
| 19 | `ColorTransform-v6` | 7 | 1.2s |  |
| 20 | `ColorTransform-v7` | 7 | 2.1s |  |
| 21 | `ColorTransform-v8` | 55 | 3.6s |  |
| 22 | `ContextMenu-v5` | 7 | 2.5s |  |
| 23 | `ContextMenu-v6` | 7 | 1.2s |  |
| 24 | `ContextMenu-v7` | 131 | 5.1s |  |
| 25 | `ContextMenu-v8` | 131 | 24.9s |  |
| 26 | `Error-v5` | 28 | 3.0s |  |
| 27 | `Error-v6` | 31 | 3.0s |  |
| 28 | `Error-v7` | 31 | 2.6s |  |
| 29 | `Error-v8` | 31 | 22.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.7s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.6s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.6s |  |
| 33 | `Global-v5` | 172 | 7.8s |  |
| 34 | `Global-v7` | 182 | 7.9s |  |
| 35 | `Global-v8` | 169 | 7.5s |  |
| 36 | `Instance-v5` | 52 | 3.5s |  |
| 37 | `Instance-v6` | 52 | 2.1s |  |
| 38 | `Instance-v7` | 52 | 3.1s |  |
| 39 | `Instance-v8` | 52 | 2.1s |  |
| 40 | `Key-v5` | 51 | 21.7s |  |
| 41 | `Key-v6` | 55 | 3.5s |  |
| 42 | `Key-v7` | 55 | 3.2s |  |
| 43 | `Key-v8` | 55 | 2.1s |  |
| 44 | `LoadVars-v5` | 8 | 21.2s |  |
| 45 | `LocalConnection-v5` | 7 | 21.3s |  |
| 46 | `LocalConnection-v6` | 58 | 3.5s |  |
| 47 | `LocalConnection-v7` | 58 | 3.2s |  |
| 48 | `LocalConnection-v8` | 58 | 1.9s |  |
| 49 | `Matrix-v5` | 7 | 22.3s |  |
| 50 | `Microphone-v5` | 6 | 2.7s |  |
| 51 | `Mouse-v5` | 13 | 23.0s |  |
| 52 | `Mouse-v6` | 21 | 3.2s |  |
| 53 | `Mouse-v7` | 21 | 2.7s |  |
| 54 | `Mouse-v8` | 21 | 2.3s |  |
| 55 | `MovieClipLoader-v5` | 6 | 22.7s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.3s |  |
| 57 | `NetConnection-v5` | 7 | 23.2s |  |
| 58 | `NetStream-v5` | 6 | 20.8s |  |
| 59 | `NetStream-v6` | 80 | 4.1s |  |
| 60 | `NetStream-v7` | 80 | 3.7s |  |
| 61 | `NetStream-v8` | 80 | 2.0s |  |
| 62 | `Number-v6` | 239 | 9.3s |  |
| 63 | `Number-v7` | 237 | 9.3s |  |
| 64 | `Number-v8` | 237 | 2.2s |  |
| 65 | `Point-v5` | 7 | 21.4s |  |
| 66 | `Point-v6` | 7 | 1.2s |  |
| 67 | `Point-v7` | 7 | 2.3s |  |
| 68 | `Point-v8` | 193 | 8.7s |  |
| 69 | `Selection-v5` | 21 | 21.5s |  |
| 70 | `Stage-v5` | 38 | 22.9s |  |
| 71 | `System-v5` | 67 | 20.3s |  |
| 72 | `System-v6` | 100 | 4.4s |  |
| 73 | `System-v7` | 101 | 4.4s |  |
| 74 | `System-v8` | 101 | 1.9s |  |
| 75 | `TextFieldHTML-v5` | 6 | 22.4s |  |
| 76 | `TextFieldHTML-v6` | 37 | 3.5s |  |
| 77 | `TextFieldHTML-v7` | 37 | 3.1s |  |
| 78 | `TextFieldHTML-v8` | 37 | 2.5s |  |
| 79 | `TextFormat-v5` | 128 | 6.1s |  |
| 80 | `TextFormat-v6` | 128 | 1.4s |  |
| 81 | `TextSnapshot-v5` | 7 | 20.7s |  |
| 82 | `TextSnapshot-v6` | 173 | 7.6s |  |
| 83 | `TextSnapshot-v7` | 173 | 7.5s |  |
| 84 | `TextSnapshot-v8` | 173 | 2.1s |  |
| 85 | `Transform-v5` | 7 | 2.5s |  |
| 86 | `Transform-v6` | 7 | 1.9s |  |
| 87 | `Transform-v7` | 7 | 2.0s |  |
| 88 | `Try-v5` | 20 | 22.6s |  |
| 89 | `Try-v6` | 20 | 1.2s |  |
| 90 | `Try-v7` | 20 | 3.4s |  |
| 91 | `Try-v8` | 20 | 2.2s |  |
| 92 | `Video-v5` | 7 | 21.9s |  |
| 93 | `Video-v6` | 85 | 4.2s |  |
| 94 | `Video-v7` | 85 | 3.8s |  |
| 95 | `Video-v8` | 85 | 2.2s |  |
| 96 | `XMLSocket-v5` | 35 | 21.6s |  |
| 97 | `XMLSocket-v6` | 35 | 3.1s |  |
| 98 | `XMLSocket-v7` | 35 | 2.8s |  |
| 99 | `XMLSocket-v8` | 35 | 2.1s |  |
| 100 | `argstest-v5` | 4 | 2.6s |  |
| 101 | `case-v5` | 39 | 3.3s |  |
| 102 | `case-v6` | 73 | 4.1s |  |
| 103 | `case-v7` | 67 | 4.0s |  |
| 104 | `case-v8` | 67 | 2.2s |  |
| 105 | `delete-v5` | 61 | 22.5s |  |
| 106 | `delete-v6` | 61 | 3.2s |  |
| 107 | `delete-v7` | 61 | 3.4s |  |
| 108 | `delete-v8` | 61 | 2.3s |  |
| 109 | `enumerate-v5` | 6 | 2.6s |  |
| 110 | `enumerate-v6` | 49 | 3.7s |  |
| 111 | `enumerate-v7` | 49 | 3.3s |  |
| 112 | `enumerate-v8` | 49 | 2.1s |  |
| 113 | `flash-v5` | 10 | 21.3s |  |
| 114 | `flash-v6` | 10 | 2.7s |  |
| 115 | `flash-v7` | 10 | 2.4s |  |
| 116 | `flash-v8` | 41 | 22.3s |  |
| 117 | `getvariable-v5` | 58 | 3.9s |  |
| 118 | `getvariable-v6` | 64 | 4.0s |  |
| 119 | `getvariable-v7` | 64 | 4.0s |  |
| 120 | `getvariable-v8` | 64 | 2.2s |  |
| 121 | `swap-v5` | 7 | 21.9s |  |
| 122 | `swap-v6` | 7 | 1.3s |  |
| 123 | `swap-v7` | 7 | 2.2s |  |
| 124 | `swap-v8` | 7 | 2.1s |  |
| 125 | `targetPath-v5` | 12 | 2.6s |  |
| 126 | `targetPath-v6` | 23 | 2.9s |  |
| 127 | `targetPath-v7` | 23 | 2.5s |  |
| 128 | `targetPath-v8` | 23 | 2.1s |  |

## Ruffle-Matched Tests

**94 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.5s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.6s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.1s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 25.2s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.7s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 24.9s |  |
| 9 | `Camera-v6` | 57 | 57 | 5.1s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.8s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.3s |  |
| 12 | `Date-v5` | 7 | 7 | 32.6s |  |
| 13 | `Date-v6` | 6 | 6 | 14.7s |  |
| 14 | `Date-v7` | 6 | 6 | 15.2s |  |
| 15 | `Date-v8` | 6 | 6 | 2.4s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.7s |  |
| 17 | `Function-v5` | 14 | 24 | 26.0s |  |
| 18 | `Function-v6` | 8 | 33 | 10.7s |  |
| 19 | `Function-v7` | 8 | 33 | 11.5s |  |
| 20 | `Function-v8` | 8 | 33 | 29.6s |  |
| 21 | `Global-v6` | 9 | 10 | 28.0s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.6s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.3s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.1s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 23.9s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.3s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.6s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.0s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.7s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.9s |  |
| 32 | `Math-v5` | 5 | 5 | 14.3s |  |
| 33 | `Math-v6` | 5 | 5 | 1.5s |  |
| 34 | `Math-v7` | 5 | 5 | 14.7s |  |
| 35 | `Math-v8` | 5 | 5 | 2.2s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.2s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.3s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.3s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.3s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.9s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.2s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 34.7s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 5.1s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.5s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 6.2s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 6.3s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.5s |  |
| 48 | `Number-v5` | 8 | 12 | 9.3s |  |
| 49 | `Object-v5` | 3 | 6 | 25.4s |  |
| 50 | `Object-v6` | 9 | 24 | 13.3s |  |
| 51 | `Object-v7` | 8 | 15 | 13.6s |  |
| 52 | `Object-v8` | 8 | 15 | 3.0s |  |
| 53 | `Selection-v6` | 7 | 13 | 5.9s |  |
| 54 | `Selection-v7` | 7 | 13 | 5.5s |  |
| 55 | `Selection-v8` | 7 | 13 | 2.2s |  |
| 56 | `Sound-v5` | 16 | 16 | 24.4s |  |
| 57 | `Sound-v6` | 8 | 37 | 5.8s |  |
| 58 | `Sound-v7` | 8 | 37 | 5.5s |  |
| 59 | `Sound-v8` | 8 | 37 | 2.6s |  |
| 60 | `Stage-v6` | 14 | 14 | 23.6s |  |
| 61 | `Stage-v7` | 14 | 14 | 3.7s |  |
| 62 | `Stage-v8` | 14 | 14 | 2.4s |  |
| 63 | `String-v5` | 19 | 21 | 17.8s |  |
| 64 | `String-v6` | 10 | 10 | 19.0s |  |
| 65 | `String-v7` | 10 | 10 | 18.4s |  |
| 66 | `String-v8` | 10 | 10 | 2.8s |  |
| 67 | `TextField-v5` | 3 | 3 | 2.4s |  |
| 68 | `TextFormat-v7` | 38 | 40 | 7.8s |  |
| 69 | `TextFormat-v8` | 36 | 38 | 26.8s |  |
| 70 | `Transform-v8` | 7 | 11 | 24.0s |  |
| 71 | `XML-v5` | 10 | 79 | 35.5s |  |
| 72 | `XML-v6` | 3 | 98 | 17.0s |  |
| 73 | `XML-v7` | 3 | 98 | 16.6s |  |
| 74 | `XML-v8` | 24 | 116 | 5.5s |  |
| 75 | `XMLNode-v5` | 3 | 22 | 9.6s |  |
| 76 | `XMLNode-v6` | 3 | 22 | 9.6s |  |
| 77 | `XMLNode-v7` | 3 | 22 | 8.3s |  |
| 78 | `XMLNode-v8` | 3 | 22 | 2.4s |  |
| 79 | `ops-v5` | 7 | 9 | 29.2s |  |
| 80 | `ops-v6` | 7 | 11 | 9.5s |  |
| 81 | `ops-v7` | 7 | 11 | 10.4s |  |
| 82 | `ops-v8` | 7 | 11 | 20.9s |  |
| 83 | `setProperty-v5` | 49 | 49 | 3.8s |  |
| 84 | `setProperty-v6` | 49 | 49 | 3.8s |  |
| 85 | `setProperty-v7` | 49 | 49 | 3.4s |  |
| 86 | `setProperty-v8` | 49 | 49 | 2.5s |  |
| 87 | `toString_valueOf-v5` | 34 | 34 | 24.6s |  |
| 88 | `toString_valueOf-v6` | 5 | 5 | 6.2s |  |
| 89 | `toString_valueOf-v7` | 5 | 5 | 5.9s |  |
| 90 | `toString_valueOf-v8` | 5 | 5 | 2.2s |  |
| 91 | `with-v5` | 3 | 3 | 4.2s |  |
| 92 | `with-v6` | 6 | 9 | 5.3s |  |
| 93 | `with-v7` | 6 | 9 | 5.0s |  |
| 94 | `with-v8` | 6 | 9 | 2.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 98.6% | 552 | 560 | 8 |  |
| 2 | `array-v6` | 96.9% | 624 | 644 | 20 |  |
| 3 | `MovieClip-v7` | 94.7% | 918 | 969 | 51 |  |
| 4 | `MovieClip-v6` | 94.6% | 885 | 936 | 51 |  |
| 5 | `MovieClip-v8` | 92.4% | 1004 | 1087 | 83 |  |
| 6 | `array-v7` | 92.2% | 603 | 654 | 51 |  |
| 7 | `array-v8` | 92.2% | 603 | 654 | 51 |  |
| 8 | `TextField-v6` | 85.0% | 463 | 545 | 82 |  |
| 9 | `TextField-v8` | 83.0% | 474 | 571 | 97 |  |
| 10 | `TextField-v7` | 82.8% | 472 | 570 | 98 |  |

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
| 3 | `MovieClip-v7` | 94.7% | 918/969 | 954 | 969 |  |
| 4 | `MovieClip-v6` | 94.6% | 885/936 | 921 | 936 |  |
| 5 | `MovieClip-v8` | 92.4% | 1004/1087 | 1072 | 1087 |  |
| 6 | `array-v7` | 92.2% | 603/654 | 654 | 654 |  |
| 7 | `array-v8` | 92.2% | 603/654 | 654 | 654 |  |
| 8 | `TextField-v6` | 85.0% | 463/545 | 545 | 545 |  |
| 9 | `TextField-v8` | 83.0% | 474/571 | 571 | 571 |  |
| 10 | `TextField-v7` | 82.8% | 472/570 | 570 | 570 |  |
| 11 | `argstest-v7` | 0.9% | 67/7301 | 7301 | 2061 |  |
| 12 | `argstest-v8` | 0.8% | 58/7663 | 7663 | 2434 |  |
| 13 | `argstest-v6` | 0.6% | 42/7301 | 7301 | 2192 |  |
