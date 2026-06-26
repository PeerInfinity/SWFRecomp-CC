# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-26 19:50 UTC

**Git SHA**: `2c07e01a5a`

**Run Duration**: 32m 8s

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
| 1 | `Accessibility-v5` | 15 | 3.1s |  |
| 2 | `Accessibility-v6` | 19 | 3.2s |  |
| 3 | `Accessibility-v7` | 19 | 2.8s |  |
| 4 | `Accessibility-v8` | 19 | 2.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.0s |  |
| 6 | `BitmapData-v5` | 7 | 2.7s |  |
| 7 | `BitmapData-v6` | 7 | 1.2s |  |
| 8 | `BitmapData-v7` | 7 | 2.4s |  |
| 9 | `Boolean-v5` | 38 | 3.3s |  |
| 10 | `Boolean-v6` | 38 | 2.8s |  |
| 11 | `Boolean-v7` | 38 | 22.7s |  |
| 12 | `Boolean-v8` | 38 | 2.0s |  |
| 13 | `Camera-v5` | 7 | 1.9s |  |
| 14 | `Color-v5` | 140 | 6.0s |  |
| 15 | `Color-v6` | 171 | 7.0s |  |
| 16 | `Color-v7` | 161 | 6.8s |  |
| 17 | `Color-v8` | 161 | 6.8s |  |
| 18 | `ColorTransform-v5` | 7 | 2.5s |  |
| 19 | `ColorTransform-v6` | 7 | 1.2s |  |
| 20 | `ColorTransform-v7` | 7 | 2.2s |  |
| 21 | `ColorTransform-v8` | 55 | 3.8s |  |
| 22 | `ContextMenu-v5` | 7 | 2.5s |  |
| 23 | `ContextMenu-v6` | 7 | 1.2s |  |
| 24 | `ContextMenu-v7` | 131 | 5.4s |  |
| 25 | `ContextMenu-v8` | 131 | 5.3s |  |
| 26 | `Error-v5` | 28 | 2.9s |  |
| 27 | `Error-v6` | 31 | 3.0s |  |
| 28 | `Error-v7` | 31 | 2.5s |  |
| 29 | `Error-v8` | 31 | 3.2s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.7s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.5s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.1s |  |
| 33 | `Global-v5` | 172 | 6.3s |  |
| 34 | `Global-v7` | 182 | 6.6s |  |
| 35 | `Global-v8` | 169 | 6.2s |  |
| 36 | `Instance-v5` | 52 | 3.5s |  |
| 37 | `Instance-v6` | 52 | 2.1s |  |
| 38 | `Instance-v7` | 52 | 3.1s |  |
| 39 | `Instance-v8` | 52 | 2.1s |  |
| 40 | `Key-v5` | 51 | 22.6s |  |
| 41 | `Key-v6` | 55 | 3.7s |  |
| 42 | `Key-v7` | 55 | 3.3s |  |
| 43 | `Key-v8` | 55 | 2.3s |  |
| 44 | `LoadVars-v5` | 8 | 22.0s |  |
| 45 | `LocalConnection-v5` | 7 | 20.4s |  |
| 46 | `LocalConnection-v6` | 58 | 1.0s |  |
| 47 | `LocalConnection-v7` | 58 | 1.0s |  |
| 48 | `LocalConnection-v8` | 58 | 1.0s |  |
| 49 | `Matrix-v5` | 7 | 2.8s |  |
| 50 | `Microphone-v5` | 6 | 2.6s |  |
| 51 | `Mouse-v5` | 13 | 3.1s |  |
| 52 | `Mouse-v6` | 21 | 3.2s |  |
| 53 | `Mouse-v7` | 21 | 2.8s |  |
| 54 | `Mouse-v8` | 21 | 2.4s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.6s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.1s |  |
| 57 | `NetConnection-v5` | 7 | 2.4s |  |
| 58 | `NetStream-v5` | 6 | 17.1s |  |
| 59 | `NetStream-v6` | 80 | 3.4s |  |
| 60 | `NetStream-v7` | 80 | 3.1s |  |
| 61 | `NetStream-v8` | 80 | 1.7s |  |
| 62 | `Number-v6` | 239 | 8.1s |  |
| 63 | `Number-v7` | 237 | 8.0s |  |
| 64 | `Number-v8` | 237 | 1.9s |  |
| 65 | `Point-v5` | 7 | 2.7s |  |
| 66 | `Point-v6` | 7 | 1.2s |  |
| 67 | `Point-v7` | 7 | 2.3s |  |
| 68 | `Point-v8` | 193 | 8.5s |  |
| 69 | `Selection-v5` | 21 | 23.0s |  |
| 70 | `Stage-v5` | 38 | 2.8s |  |
| 71 | `System-v5` | 67 | 4.2s |  |
| 72 | `System-v6` | 100 | 5.1s |  |
| 73 | `System-v7` | 101 | 5.1s |  |
| 74 | `System-v8` | 101 | 2.3s |  |
| 75 | `TextFieldHTML-v5` | 6 | 2.8s |  |
| 76 | `TextFieldHTML-v6` | 37 | 3.5s |  |
| 77 | `TextFieldHTML-v7` | 37 | 3.1s |  |
| 78 | `TextFieldHTML-v8` | 37 | 2.2s |  |
| 79 | `TextFormat-v5` | 128 | 6.0s |  |
| 80 | `TextFormat-v6` | 128 | 1.3s |  |
| 81 | `TextSnapshot-v5` | 7 | 3.0s |  |
| 82 | `TextSnapshot-v6` | 173 | 9.7s |  |
| 83 | `TextSnapshot-v7` | 173 | 9.1s |  |
| 84 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 85 | `Transform-v5` | 7 | 2.8s |  |
| 86 | `Transform-v6` | 7 | 2.4s |  |
| 87 | `Transform-v7` | 7 | 2.5s |  |
| 88 | `Try-v5` | 20 | 23.0s |  |
| 89 | `Try-v6` | 20 | 1.3s |  |
| 90 | `Try-v7` | 20 | 3.4s |  |
| 91 | `Try-v8` | 20 | 2.3s |  |
| 92 | `Video-v5` | 7 | 22.1s |  |
| 93 | `Video-v6` | 85 | 4.4s |  |
| 94 | `Video-v7` | 85 | 4.0s |  |
| 95 | `Video-v8` | 85 | 2.3s |  |
| 96 | `XMLSocket-v5` | 35 | 3.2s |  |
| 97 | `XMLSocket-v6` | 35 | 3.2s |  |
| 98 | `XMLSocket-v7` | 35 | 2.9s |  |
| 99 | `XMLSocket-v8` | 35 | 2.2s |  |
| 100 | `argstest-v5` | 4 | 2.8s |  |
| 101 | `case-v5` | 39 | 3.3s |  |
| 102 | `case-v6` | 73 | 4.4s |  |
| 103 | `case-v7` | 67 | 4.1s |  |
| 104 | `case-v8` | 67 | 2.3s |  |
| 105 | `delete-v5` | 61 | 22.6s |  |
| 106 | `delete-v6` | 61 | 3.1s |  |
| 107 | `delete-v7` | 61 | 3.3s |  |
| 108 | `delete-v8` | 61 | 2.3s |  |
| 109 | `enumerate-v5` | 6 | 2.7s |  |
| 110 | `enumerate-v6` | 49 | 3.7s |  |
| 111 | `enumerate-v7` | 49 | 3.3s |  |
| 112 | `enumerate-v8` | 49 | 2.2s |  |
| 113 | `flash-v5` | 10 | 2.7s |  |
| 114 | `flash-v6` | 10 | 2.8s |  |
| 115 | `flash-v7` | 10 | 2.4s |  |
| 116 | `flash-v8` | 41 | 22.6s |  |
| 117 | `getvariable-v5` | 58 | 4.0s |  |
| 118 | `getvariable-v6` | 64 | 4.1s |  |
| 119 | `getvariable-v7` | 64 | 4.2s |  |
| 120 | `getvariable-v8` | 64 | 2.3s |  |
| 121 | `swap-v5` | 7 | 1.0s |  |
| 122 | `swap-v6` | 7 | 0.8s |  |
| 123 | `swap-v7` | 7 | 1.0s |  |
| 124 | `swap-v8` | 7 | 1.0s |  |
| 125 | `targetPath-v5` | 12 | 1.0s |  |
| 126 | `targetPath-v6` | 23 | 1.0s |  |
| 127 | `targetPath-v7` | 23 | 1.0s |  |
| 128 | `targetPath-v8` | 23 | 1.0s |  |

## Ruffle-Matched Tests

**94 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 7.3s |  |
| 2 | `ASnative-v6` | 40 | 40 | 7.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 7.0s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.5s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.7s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.3s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.7s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.3s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.0s |  |
| 12 | `Date-v5` | 7 | 7 | 32.5s |  |
| 13 | `Date-v6` | 6 | 6 | 14.4s |  |
| 14 | `Date-v7` | 6 | 6 | 14.9s |  |
| 15 | `Date-v8` | 6 | 6 | 2.4s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.5s |  |
| 17 | `Function-v5` | 14 | 24 | 25.1s |  |
| 18 | `Function-v6` | 8 | 33 | 10.0s |  |
| 19 | `Function-v7` | 8 | 33 | 10.2s |  |
| 20 | `Function-v8` | 8 | 33 | 23.4s |  |
| 21 | `Global-v6` | 9 | 10 | 22.2s |  |
| 22 | `HitTest-v6` | 8 | 8 | 4.5s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.2s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.1s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 23.7s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.4s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.7s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.5s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 6.3s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 3.1s |  |
| 32 | `Math-v5` | 5 | 5 | 1.2s |  |
| 33 | `Math-v6` | 5 | 5 | 1.1s |  |
| 34 | `Math-v7` | 5 | 5 | 1.1s |  |
| 35 | `Math-v8` | 5 | 5 | 1.1s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.7s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.0s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.3s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.1s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.8s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.2s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 37.2s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.5s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.0s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.3s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.4s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.1s |  |
| 48 | `Number-v5` | 8 | 12 | 8.3s |  |
| 49 | `Object-v5` | 3 | 6 | 25.3s |  |
| 50 | `Object-v6` | 9 | 24 | 13.3s |  |
| 51 | `Object-v7` | 8 | 15 | 13.4s |  |
| 52 | `Object-v8` | 8 | 15 | 3.0s |  |
| 53 | `Selection-v6` | 7 | 13 | 6.6s |  |
| 54 | `Selection-v7` | 7 | 13 | 6.2s |  |
| 55 | `Selection-v8` | 7 | 13 | 2.4s |  |
| 56 | `Sound-v5` | 16 | 16 | 26.7s |  |
| 57 | `Sound-v6` | 8 | 37 | 6.6s |  |
| 58 | `Sound-v7` | 8 | 37 | 6.2s |  |
| 59 | `Sound-v8` | 8 | 37 | 2.9s |  |
| 60 | `Stage-v6` | 14 | 14 | 19.5s |  |
| 61 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 62 | `Stage-v8` | 14 | 14 | 1.9s |  |
| 63 | `String-v5` | 19 | 21 | 15.2s |  |
| 64 | `String-v6` | 10 | 10 | 16.1s |  |
| 65 | `String-v7` | 10 | 10 | 16.1s |  |
| 66 | `String-v8` | 10 | 10 | 2.4s |  |
| 67 | `TextField-v5` | 3 | 3 | 3.0s |  |
| 68 | `TextFormat-v7` | 38 | 40 | 7.7s |  |
| 69 | `TextFormat-v8` | 36 | 38 | 27.2s |  |
| 70 | `Transform-v8` | 7 | 11 | 27.5s |  |
| 71 | `XML-v5` | 10 | 79 | 33.1s |  |
| 72 | `XML-v6` | 3 | 98 | 16.0s |  |
| 73 | `XML-v7` | 3 | 98 | 15.7s |  |
| 74 | `XML-v8` | 24 | 116 | 5.2s |  |
| 75 | `XMLNode-v5` | 3 | 22 | 9.0s |  |
| 76 | `XMLNode-v6` | 3 | 22 | 9.0s |  |
| 77 | `XMLNode-v7` | 3 | 22 | 7.9s |  |
| 78 | `XMLNode-v8` | 3 | 22 | 2.4s |  |
| 79 | `ops-v5` | 7 | 9 | 29.7s |  |
| 80 | `ops-v6` | 7 | 11 | 10.0s |  |
| 81 | `ops-v7` | 7 | 11 | 10.7s |  |
| 82 | `ops-v8` | 7 | 11 | 21.2s |  |
| 83 | `setProperty-v5` | 49 | 49 | 3.9s |  |
| 84 | `setProperty-v6` | 49 | 49 | 3.9s |  |
| 85 | `setProperty-v7` | 49 | 49 | 3.5s |  |
| 86 | `setProperty-v8` | 49 | 49 | 2.6s |  |
| 87 | `toString_valueOf-v5` | 34 | 34 | 5.1s |  |
| 88 | `toString_valueOf-v6` | 5 | 5 | 5.5s |  |
| 89 | `toString_valueOf-v7` | 5 | 5 | 5.1s |  |
| 90 | `toString_valueOf-v8` | 5 | 5 | 1.8s |  |
| 91 | `with-v5` | 3 | 3 | 3.6s |  |
| 92 | `with-v6` | 6 | 9 | 4.8s |  |
| 93 | `with-v7` | 6 | 9 | 4.4s |  |
| 94 | `with-v8` | 6 | 9 | 2.0s |  |

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
