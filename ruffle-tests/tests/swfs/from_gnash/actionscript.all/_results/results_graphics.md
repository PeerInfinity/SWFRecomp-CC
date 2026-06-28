# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-28 18:16 UTC

**Git SHA**: `d579ca99ba`

**Run Duration**: 32m 5s

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
| 1 | `Accessibility-v5` | 15 | 2.9s |  |
| 2 | `Accessibility-v6` | 19 | 2.9s |  |
| 3 | `Accessibility-v7` | 19 | 2.5s |  |
| 4 | `Accessibility-v8` | 19 | 2.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.7s |  |
| 6 | `BitmapData-v5` | 7 | 2.8s |  |
| 7 | `BitmapData-v6` | 7 | 1.2s |  |
| 8 | `BitmapData-v7` | 7 | 2.3s |  |
| 9 | `Boolean-v5` | 38 | 3.2s |  |
| 10 | `Boolean-v6` | 38 | 2.6s |  |
| 11 | `Boolean-v7` | 38 | 2.2s |  |
| 12 | `Boolean-v8` | 38 | 1.5s |  |
| 13 | `Camera-v5` | 7 | 1.8s |  |
| 14 | `Color-v5` | 140 | 4.5s |  |
| 15 | `Color-v6` | 171 | 5.8s |  |
| 16 | `Color-v7` | 161 | 5.3s |  |
| 17 | `Color-v8` | 161 | 7.4s |  |
| 18 | `ColorTransform-v5` | 7 | 2.7s |  |
| 19 | `ColorTransform-v6` | 7 | 1.3s |  |
| 20 | `ColorTransform-v7` | 7 | 2.3s |  |
| 21 | `ColorTransform-v8` | 55 | 4.2s |  |
| 22 | `ContextMenu-v5` | 7 | 2.7s |  |
| 23 | `ContextMenu-v6` | 7 | 1.3s |  |
| 24 | `ContextMenu-v7` | 131 | 5.8s |  |
| 25 | `ContextMenu-v8` | 131 | 23.9s |  |
| 26 | `Error-v5` | 28 | 2.8s |  |
| 27 | `Error-v6` | 31 | 2.9s |  |
| 28 | `Error-v7` | 31 | 2.5s |  |
| 29 | `Error-v8` | 31 | 24.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 3.0s |  |
| 31 | `ExternalInterface-v6` | 55 | 4.0s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.7s |  |
| 33 | `Global-v5` | 172 | 8.1s |  |
| 34 | `Global-v7` | 182 | 8.5s |  |
| 35 | `Global-v8` | 169 | 8.0s |  |
| 36 | `Instance-v5` | 52 | 3.5s |  |
| 37 | `Instance-v6` | 52 | 2.2s |  |
| 38 | `Instance-v7` | 52 | 3.2s |  |
| 39 | `Instance-v8` | 52 | 2.1s |  |
| 40 | `Key-v5` | 51 | 21.8s |  |
| 41 | `Key-v6` | 55 | 3.5s |  |
| 42 | `Key-v7` | 55 | 3.1s |  |
| 43 | `Key-v8` | 55 | 2.1s |  |
| 44 | `LoadVars-v5` | 8 | 21.2s |  |
| 45 | `LocalConnection-v5` | 7 | 22.5s |  |
| 46 | `LocalConnection-v6` | 58 | 4.0s |  |
| 47 | `LocalConnection-v7` | 58 | 3.6s |  |
| 48 | `LocalConnection-v8` | 58 | 2.1s |  |
| 49 | `Matrix-v5` | 7 | 2.8s |  |
| 50 | `Microphone-v5` | 6 | 2.9s |  |
| 51 | `Mouse-v5` | 13 | 2.5s |  |
| 52 | `Mouse-v6` | 21 | 2.7s |  |
| 53 | `Mouse-v7` | 21 | 2.3s |  |
| 54 | `Mouse-v8` | 21 | 1.9s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.9s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.2s |  |
| 57 | `NetConnection-v5` | 7 | 21.7s |  |
| 58 | `NetStream-v5` | 6 | 22.3s |  |
| 59 | `NetStream-v6` | 80 | 4.4s |  |
| 60 | `NetStream-v7` | 80 | 4.0s |  |
| 61 | `NetStream-v8` | 80 | 2.1s |  |
| 62 | `Number-v6` | 239 | 9.9s |  |
| 63 | `Number-v7` | 237 | 9.9s |  |
| 64 | `Number-v8` | 237 | 2.3s |  |
| 65 | `Point-v5` | 7 | 2.8s |  |
| 66 | `Point-v6` | 7 | 1.2s |  |
| 67 | `Point-v7` | 7 | 2.4s |  |
| 68 | `Point-v8` | 193 | 8.8s |  |
| 69 | `Selection-v5` | 21 | 2.9s |  |
| 70 | `Stage-v5` | 38 | 3.2s |  |
| 71 | `System-v5` | 67 | 3.9s |  |
| 72 | `System-v6` | 100 | 4.7s |  |
| 73 | `System-v7` | 101 | 4.7s |  |
| 74 | `System-v8` | 101 | 2.1s |  |
| 75 | `TextFieldHTML-v5` | 6 | 2.5s |  |
| 76 | `TextFieldHTML-v6` | 37 | 3.1s |  |
| 77 | `TextFieldHTML-v7` | 37 | 2.7s |  |
| 78 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 79 | `TextFormat-v5` | 128 | 5.4s |  |
| 80 | `TextFormat-v6` | 128 | 1.1s |  |
| 81 | `TextSnapshot-v5` | 7 | 2.6s |  |
| 82 | `TextSnapshot-v6` | 173 | 8.3s |  |
| 83 | `TextSnapshot-v7` | 173 | 8.0s |  |
| 84 | `TextSnapshot-v8` | 173 | 2.2s |  |
| 85 | `Transform-v5` | 7 | 2.6s |  |
| 86 | `Transform-v6` | 7 | 2.0s |  |
| 87 | `Transform-v7` | 7 | 2.2s |  |
| 88 | `Try-v5` | 20 | 23.1s |  |
| 89 | `Try-v6` | 20 | 1.3s |  |
| 90 | `Try-v7` | 20 | 3.4s |  |
| 91 | `Try-v8` | 20 | 2.2s |  |
| 92 | `Video-v5` | 7 | 22.6s |  |
| 93 | `Video-v6` | 85 | 4.6s |  |
| 94 | `Video-v7` | 85 | 4.2s |  |
| 95 | `Video-v8` | 85 | 2.3s |  |
| 96 | `XMLSocket-v5` | 35 | 3.3s |  |
| 97 | `XMLSocket-v6` | 35 | 3.2s |  |
| 98 | `XMLSocket-v7` | 35 | 2.9s |  |
| 99 | `XMLSocket-v8` | 35 | 2.2s |  |
| 100 | `argstest-v5` | 4 | 2.8s |  |
| 101 | `case-v5` | 39 | 2.8s |  |
| 102 | `case-v6` | 73 | 3.6s |  |
| 103 | `case-v7` | 67 | 3.5s |  |
| 104 | `case-v8` | 67 | 1.8s |  |
| 105 | `delete-v5` | 61 | 4.0s |  |
| 106 | `delete-v6` | 61 | 3.4s |  |
| 107 | `delete-v7` | 61 | 3.6s |  |
| 108 | `delete-v8` | 61 | 2.4s |  |
| 109 | `enumerate-v5` | 6 | 2.8s |  |
| 110 | `enumerate-v6` | 49 | 4.0s |  |
| 111 | `enumerate-v7` | 49 | 3.6s |  |
| 112 | `enumerate-v8` | 49 | 2.4s |  |
| 113 | `flash-v5` | 10 | 2.2s |  |
| 114 | `flash-v6` | 10 | 2.2s |  |
| 115 | `flash-v7` | 10 | 1.9s |  |
| 116 | `flash-v8` | 41 | 17.9s |  |
| 117 | `getvariable-v5` | 58 | 3.2s |  |
| 118 | `getvariable-v6` | 64 | 3.4s |  |
| 119 | `getvariable-v7` | 64 | 3.4s |  |
| 120 | `getvariable-v8` | 64 | 1.9s |  |
| 121 | `swap-v5` | 7 | 2.6s |  |
| 122 | `swap-v6` | 7 | 1.2s |  |
| 123 | `swap-v7` | 7 | 2.2s |  |
| 124 | `swap-v8` | 7 | 2.0s |  |
| 125 | `targetPath-v5` | 12 | 2.6s |  |
| 126 | `targetPath-v6` | 23 | 2.9s |  |
| 127 | `targetPath-v7` | 23 | 2.5s |  |
| 128 | `targetPath-v8` | 23 | 2.0s |  |

## Ruffle-Matched Tests

**94 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 27.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.5s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.2s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 24.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.5s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 24.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.4s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.4s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.5s |  |
| 12 | `Date-v5` | 7 | 7 | 31.8s |  |
| 13 | `Date-v6` | 6 | 6 | 14.2s |  |
| 14 | `Date-v7` | 6 | 6 | 14.6s |  |
| 15 | `Date-v8` | 6 | 6 | 2.3s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 6.3s |  |
| 17 | `Function-v5` | 14 | 24 | 27.8s |  |
| 18 | `Function-v6` | 8 | 33 | 11.3s |  |
| 19 | `Function-v7` | 8 | 33 | 11.6s |  |
| 20 | `Function-v8` | 8 | 33 | 32.3s |  |
| 21 | `Global-v6` | 9 | 10 | 9.5s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.9s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.6s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.5s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 5.9s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.4s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.7s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.0s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.7s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.9s |  |
| 32 | `Math-v5` | 5 | 5 | 15.0s |  |
| 33 | `Math-v6` | 5 | 5 | 1.5s |  |
| 34 | `Math-v7` | 5 | 5 | 15.6s |  |
| 35 | `Math-v8` | 5 | 5 | 2.4s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.6s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.6s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.3s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.3s |  |
| 40 | `Microphone-v7` | 31 | 31 | 4.0s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.3s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 32.2s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.7s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.3s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.7s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.7s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.3s |  |
| 48 | `Number-v5` | 8 | 12 | 10.2s |  |
| 49 | `Object-v5` | 3 | 6 | 26.1s |  |
| 50 | `Object-v6` | 9 | 24 | 13.5s |  |
| 51 | `Object-v7` | 8 | 15 | 13.8s |  |
| 52 | `Object-v8` | 8 | 15 | 3.0s |  |
| 53 | `Selection-v6` | 7 | 13 | 5.9s |  |
| 54 | `Selection-v7` | 7 | 13 | 5.5s |  |
| 55 | `Selection-v8` | 7 | 13 | 2.3s |  |
| 56 | `Sound-v5` | 16 | 16 | 24.5s |  |
| 57 | `Sound-v6` | 8 | 37 | 5.8s |  |
| 58 | `Sound-v7` | 8 | 37 | 5.5s |  |
| 59 | `Sound-v8` | 8 | 37 | 2.6s |  |
| 60 | `Stage-v6` | 14 | 14 | 22.9s |  |
| 61 | `Stage-v7` | 14 | 14 | 3.4s |  |
| 62 | `Stage-v8` | 14 | 14 | 2.2s |  |
| 63 | `String-v5` | 19 | 21 | 16.5s |  |
| 64 | `String-v6` | 10 | 10 | 17.2s |  |
| 65 | `String-v7` | 10 | 10 | 16.8s |  |
| 66 | `String-v8` | 10 | 10 | 2.6s |  |
| 67 | `TextField-v5` | 3 | 3 | 2.8s |  |
| 68 | `TextFormat-v7` | 38 | 40 | 7.0s |  |
| 69 | `TextFormat-v8` | 36 | 38 | 26.0s |  |
| 70 | `Transform-v8` | 7 | 11 | 26.3s |  |
| 71 | `XML-v5` | 10 | 79 | 37.9s |  |
| 72 | `XML-v6` | 3 | 98 | 18.5s |  |
| 73 | `XML-v7` | 3 | 98 | 18.2s |  |
| 74 | `XML-v8` | 24 | 116 | 5.7s |  |
| 75 | `XMLNode-v5` | 3 | 22 | 10.5s |  |
| 76 | `XMLNode-v6` | 3 | 22 | 10.2s |  |
| 77 | `XMLNode-v7` | 3 | 22 | 9.2s |  |
| 78 | `XMLNode-v8` | 3 | 22 | 2.4s |  |
| 79 | `ops-v5` | 7 | 9 | 28.7s |  |
| 80 | `ops-v6` | 7 | 11 | 9.8s |  |
| 81 | `ops-v7` | 7 | 11 | 10.2s |  |
| 82 | `ops-v8` | 7 | 11 | 2.3s |  |
| 83 | `setProperty-v5` | 49 | 49 | 3.8s |  |
| 84 | `setProperty-v6` | 49 | 49 | 3.7s |  |
| 85 | `setProperty-v7` | 49 | 49 | 3.4s |  |
| 86 | `setProperty-v8` | 49 | 49 | 2.5s |  |
| 87 | `toString_valueOf-v5` | 34 | 34 | 5.7s |  |
| 88 | `toString_valueOf-v6` | 5 | 5 | 6.0s |  |
| 89 | `toString_valueOf-v7` | 5 | 5 | 5.8s |  |
| 90 | `toString_valueOf-v8` | 5 | 5 | 2.1s |  |
| 91 | `with-v5` | 3 | 3 | 4.1s |  |
| 92 | `with-v6` | 6 | 9 | 5.3s |  |
| 93 | `with-v7` | 6 | 9 | 5.2s |  |
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
