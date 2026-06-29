# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-29 18:27 UTC

**Git SHA**: `a0db68a54d`

**Run Duration**: 35m 53s

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
| 1 | `Accessibility-v5` | 15 | 2.7s |  |
| 2 | `Accessibility-v6` | 19 | 2.7s |  |
| 3 | `Accessibility-v7` | 19 | 2.3s |  |
| 4 | `Accessibility-v8` | 19 | 1.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.5s |  |
| 6 | `BitmapData-v5` | 7 | 2.9s |  |
| 7 | `BitmapData-v6` | 7 | 1.3s |  |
| 8 | `BitmapData-v7` | 7 | 2.5s |  |
| 9 | `Boolean-v5` | 38 | 3.5s |  |
| 10 | `Boolean-v6` | 38 | 2.9s |  |
| 11 | `Boolean-v7` | 38 | 24.4s |  |
| 12 | `Boolean-v8` | 38 | 2.3s |  |
| 13 | `Camera-v5` | 7 | 2.7s |  |
| 14 | `Color-v5` | 140 | 6.7s |  |
| 15 | `Color-v6` | 171 | 7.8s |  |
| 16 | `Color-v7` | 161 | 7.6s |  |
| 17 | `Color-v8` | 161 | 26.9s |  |
| 18 | `ColorTransform-v5` | 7 | 2.8s |  |
| 19 | `ColorTransform-v6` | 7 | 1.3s |  |
| 20 | `ColorTransform-v7` | 7 | 2.3s |  |
| 21 | `ColorTransform-v8` | 55 | 4.0s |  |
| 22 | `ContextMenu-v5` | 7 | 2.7s |  |
| 23 | `ContextMenu-v6` | 7 | 1.3s |  |
| 24 | `ContextMenu-v7` | 131 | 5.9s |  |
| 25 | `ContextMenu-v8` | 131 | 23.5s |  |
| 26 | `Error-v5` | 28 | 3.0s |  |
| 27 | `Error-v6` | 31 | 3.1s |  |
| 28 | `Error-v7` | 31 | 2.7s |  |
| 29 | `Error-v8` | 31 | 14.1s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.3s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.1s |  |
| 33 | `Global-v5` | 172 | 7.3s |  |
| 34 | `Global-v7` | 182 | 7.6s |  |
| 35 | `Global-v8` | 169 | 7.1s |  |
| 36 | `Instance-v5` | 52 | 3.7s |  |
| 37 | `Instance-v6` | 52 | 2.3s |  |
| 38 | `Instance-v7` | 52 | 3.4s |  |
| 39 | `Instance-v8` | 52 | 2.3s |  |
| 40 | `Key-v5` | 51 | 21.1s |  |
| 41 | `Key-v6` | 55 | 3.2s |  |
| 42 | `Key-v7` | 55 | 2.8s |  |
| 43 | `Key-v8` | 55 | 1.9s |  |
| 44 | `LoadVars-v5` | 8 | 20.9s |  |
| 45 | `LocalConnection-v5` | 7 | 20.4s |  |
| 46 | `LocalConnection-v6` | 58 | 1.1s |  |
| 47 | `LocalConnection-v7` | 58 | 1.1s |  |
| 48 | `LocalConnection-v8` | 58 | 1.0s |  |
| 49 | `Matrix-v5` | 7 | 21.8s |  |
| 50 | `Microphone-v5` | 6 | 2.7s |  |
| 51 | `Mouse-v5` | 13 | 22.2s |  |
| 52 | `Mouse-v6` | 21 | 3.1s |  |
| 53 | `Mouse-v7` | 21 | 2.7s |  |
| 54 | `Mouse-v8` | 21 | 2.3s |  |
| 55 | `MovieClipLoader-v5` | 6 | 14.3s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.8s |  |
| 57 | `NetConnection-v5` | 7 | 13.9s |  |
| 58 | `NetStream-v5` | 6 | 20.8s |  |
| 59 | `NetStream-v6` | 80 | 4.0s |  |
| 60 | `NetStream-v7` | 80 | 3.6s |  |
| 61 | `NetStream-v8` | 80 | 1.9s |  |
| 62 | `Number-v6` | 239 | 9.1s |  |
| 63 | `Number-v7` | 237 | 9.1s |  |
| 64 | `Number-v8` | 237 | 2.2s |  |
| 65 | `Point-v5` | 7 | 22.4s |  |
| 66 | `Point-v6` | 7 | 1.3s |  |
| 67 | `Point-v7` | 7 | 2.4s |  |
| 68 | `Point-v8` | 193 | 9.0s |  |
| 69 | `Selection-v5` | 21 | 21.4s |  |
| 70 | `Stage-v5` | 38 | 18.0s |  |
| 71 | `System-v5` | 67 | 23.0s |  |
| 72 | `System-v6` | 100 | 4.7s |  |
| 73 | `System-v7` | 101 | 4.8s |  |
| 74 | `System-v8` | 101 | 2.2s |  |
| 75 | `TextFieldHTML-v5` | 6 | 21.9s |  |
| 76 | `TextFieldHTML-v6` | 37 | 3.2s |  |
| 77 | `TextFieldHTML-v7` | 37 | 2.8s |  |
| 78 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 79 | `TextFormat-v5` | 128 | 5.7s |  |
| 80 | `TextFormat-v6` | 128 | 1.1s |  |
| 81 | `TextSnapshot-v5` | 7 | 22.6s |  |
| 82 | `TextSnapshot-v6` | 173 | 9.1s |  |
| 83 | `TextSnapshot-v7` | 173 | 8.7s |  |
| 84 | `TextSnapshot-v8` | 173 | 2.4s |  |
| 85 | `Transform-v5` | 7 | 2.8s |  |
| 86 | `Transform-v6` | 7 | 2.3s |  |
| 87 | `Transform-v7` | 7 | 2.5s |  |
| 88 | `Try-v5` | 20 | 14.9s |  |
| 89 | `Try-v6` | 20 | 0.9s |  |
| 90 | `Try-v7` | 20 | 2.2s |  |
| 91 | `Try-v8` | 20 | 1.5s |  |
| 92 | `Video-v5` | 7 | 14.8s |  |
| 93 | `Video-v6` | 85 | 3.1s |  |
| 94 | `Video-v7` | 85 | 2.7s |  |
| 95 | `Video-v8` | 85 | 1.5s |  |
| 96 | `XMLSocket-v5` | 35 | 13.0s |  |
| 97 | `XMLSocket-v6` | 35 | 1.9s |  |
| 98 | `XMLSocket-v7` | 35 | 1.7s |  |
| 99 | `XMLSocket-v8` | 35 | 1.3s |  |
| 100 | `argstest-v5` | 4 | 1.7s |  |
| 101 | `case-v5` | 39 | 3.5s |  |
| 102 | `case-v6` | 73 | 4.3s |  |
| 103 | `case-v7` | 67 | 4.2s |  |
| 104 | `case-v8` | 67 | 2.3s |  |
| 105 | `delete-v5` | 61 | 24.1s |  |
| 106 | `delete-v6` | 61 | 3.5s |  |
| 107 | `delete-v7` | 61 | 3.7s |  |
| 108 | `delete-v8` | 61 | 2.4s |  |
| 109 | `enumerate-v5` | 6 | 2.9s |  |
| 110 | `enumerate-v6` | 49 | 4.0s |  |
| 111 | `enumerate-v7` | 49 | 3.6s |  |
| 112 | `enumerate-v8` | 49 | 2.4s |  |
| 113 | `flash-v5` | 10 | 14.1s |  |
| 114 | `flash-v6` | 10 | 1.9s |  |
| 115 | `flash-v7` | 10 | 1.6s |  |
| 116 | `flash-v8` | 41 | 14.6s |  |
| 117 | `getvariable-v5` | 58 | 2.7s |  |
| 118 | `getvariable-v6` | 64 | 2.9s |  |
| 119 | `getvariable-v7` | 64 | 2.7s |  |
| 120 | `getvariable-v8` | 64 | 1.6s |  |
| 121 | `swap-v5` | 7 | 22.5s |  |
| 122 | `swap-v6` | 7 | 1.2s |  |
| 123 | `swap-v7` | 7 | 2.2s |  |
| 124 | `swap-v8` | 7 | 2.0s |  |
| 125 | `targetPath-v5` | 12 | 2.7s |  |
| 126 | `targetPath-v6` | 23 | 2.9s |  |
| 127 | `targetPath-v7` | 23 | 2.6s |  |
| 128 | `targetPath-v8` | 23 | 2.1s |  |

## Ruffle-Matched Tests

**94 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.7s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.0s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.7s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.1s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 25.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.8s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.5s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.8s |  |
| 9 | `Camera-v6` | 57 | 57 | 5.2s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.8s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.3s |  |
| 12 | `Date-v5` | 7 | 7 | 31.9s |  |
| 13 | `Date-v6` | 6 | 6 | 14.8s |  |
| 14 | `Date-v7` | 6 | 6 | 15.4s |  |
| 15 | `Date-v8` | 6 | 6 | 2.5s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.0s |  |
| 17 | `Function-v5` | 14 | 24 | 16.2s |  |
| 18 | `Function-v6` | 8 | 33 | 7.5s |  |
| 19 | `Function-v7` | 8 | 33 | 7.2s |  |
| 20 | `Function-v8` | 8 | 33 | 29.4s |  |
| 21 | `Global-v6` | 9 | 10 | 27.7s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.5s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.0s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.9s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 25.0s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.8s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.8s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.9s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 5.7s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.4s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.7s |  |
| 32 | `Math-v5` | 5 | 5 | 1.3s |  |
| 33 | `Math-v6` | 5 | 5 | 1.2s |  |
| 34 | `Math-v7` | 5 | 5 | 1.3s |  |
| 35 | `Math-v8` | 5 | 5 | 1.3s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.0s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.1s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.3s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.2s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.9s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.2s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 34.7s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 3.1s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.2s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 4.2s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 3.9s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.7s |  |
| 48 | `Number-v5` | 8 | 12 | 9.4s |  |
| 49 | `Object-v5` | 3 | 6 | 26.8s |  |
| 50 | `Object-v6` | 9 | 24 | 14.1s |  |
| 51 | `Object-v7` | 8 | 15 | 14.3s |  |
| 52 | `Object-v8` | 8 | 15 | 3.1s |  |
| 53 | `Selection-v6` | 7 | 13 | 5.8s |  |
| 54 | `Selection-v7` | 7 | 13 | 5.4s |  |
| 55 | `Selection-v8` | 7 | 13 | 2.1s |  |
| 56 | `Sound-v5` | 16 | 16 | 24.2s |  |
| 57 | `Sound-v6` | 8 | 37 | 5.8s |  |
| 58 | `Sound-v7` | 8 | 37 | 5.5s |  |
| 59 | `Sound-v8` | 8 | 37 | 2.6s |  |
| 60 | `Stage-v6` | 14 | 14 | 18.5s |  |
| 61 | `Stage-v7` | 14 | 14 | 2.9s |  |
| 62 | `Stage-v8` | 14 | 14 | 1.9s |  |
| 63 | `String-v5` | 19 | 21 | 14.7s |  |
| 64 | `String-v6` | 10 | 10 | 15.2s |  |
| 65 | `String-v7` | 10 | 10 | 15.0s |  |
| 66 | `String-v8` | 10 | 10 | 2.2s |  |
| 67 | `TextField-v5` | 3 | 3 | 2.8s |  |
| 68 | `TextFormat-v7` | 38 | 40 | 7.2s |  |
| 69 | `TextFormat-v8` | 36 | 38 | 26.7s |  |
| 70 | `Transform-v8` | 7 | 11 | 25.7s |  |
| 71 | `XML-v5` | 10 | 79 | 33.6s |  |
| 72 | `XML-v6` | 3 | 98 | 16.5s |  |
| 73 | `XML-v7` | 3 | 98 | 16.3s |  |
| 74 | `XML-v8` | 24 | 116 | 5.3s |  |
| 75 | `XMLNode-v5` | 3 | 22 | 9.2s |  |
| 76 | `XMLNode-v6` | 3 | 22 | 9.2s |  |
| 77 | `XMLNode-v7` | 3 | 22 | 8.1s |  |
| 78 | `XMLNode-v8` | 3 | 22 | 2.5s |  |
| 79 | `ops-v5` | 7 | 9 | 28.6s |  |
| 80 | `ops-v6` | 7 | 11 | 9.3s |  |
| 81 | `ops-v7` | 7 | 11 | 9.9s |  |
| 82 | `ops-v8` | 7 | 11 | 20.6s |  |
| 83 | `setProperty-v5` | 49 | 49 | 3.7s |  |
| 84 | `setProperty-v6` | 49 | 49 | 3.7s |  |
| 85 | `setProperty-v7` | 49 | 49 | 3.4s |  |
| 86 | `setProperty-v8` | 49 | 49 | 2.5s |  |
| 87 | `toString_valueOf-v5` | 34 | 34 | 23.3s |  |
| 88 | `toString_valueOf-v6` | 5 | 5 | 5.5s |  |
| 89 | `toString_valueOf-v7` | 5 | 5 | 5.1s |  |
| 90 | `toString_valueOf-v8` | 5 | 5 | 1.8s |  |
| 91 | `with-v5` | 3 | 3 | 3.7s |  |
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
