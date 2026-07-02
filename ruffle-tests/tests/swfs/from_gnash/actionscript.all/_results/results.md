# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-02 19:28 UTC

**Git SHA**: `8d1e3adef5`

**Run Duration**: 36m 57s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **135** (55.6%) |
| Ruffle-matched | 94 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **229** (94.2%) |
| Failing | 14 |
| Total expected lines | 38791 |
| Matching lines | 30142 (77.7%) |
| Mismatched lines | 8649 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 14 | 100.0% |

## Passing Tests

**135 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.6s |  |
| 2 | `Accessibility-v6` | 19 | 1.7s |  |
| 3 | `Accessibility-v7` | 19 | 1.4s |  |
| 4 | `Accessibility-v8` | 19 | 1.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.7s |  |
| 6 | `BitmapData-v5` | 7 | 1.8s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.4s |  |
| 9 | `Boolean-v5` | 38 | 2.3s |  |
| 10 | `Boolean-v6` | 38 | 1.8s |  |
| 11 | `Boolean-v7` | 38 | 21.4s |  |
| 12 | `Boolean-v8` | 38 | 1.3s |  |
| 13 | `Camera-v5` | 7 | 1.6s |  |
| 14 | `Color-v5` | 140 | 5.2s |  |
| 15 | `Color-v6` | 171 | 6.2s |  |
| 16 | `Color-v7` | 161 | 5.9s |  |
| 17 | `Color-v8` | 161 | 24.9s |  |
| 18 | `ColorTransform-v5` | 7 | 2.0s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.6s |  |
| 21 | `ColorTransform-v8` | 55 | 3.2s |  |
| 22 | `ContextMenu-v5` | 7 | 2.0s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.9s |  |
| 25 | `ContextMenu-v8` | 131 | 24.1s |  |
| 26 | `Error-v5` | 28 | 2.4s |  |
| 27 | `Error-v6` | 31 | 2.4s |  |
| 28 | `Error-v7` | 31 | 2.1s |  |
| 29 | `Error-v8` | 31 | 22.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.1s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 33 | `Global-v5` | 172 | 7.6s |  |
| 34 | `Global-v7` | 182 | 7.9s |  |
| 35 | `Global-v8` | 169 | 7.3s |  |
| 36 | `Instance-v5` | 52 | 2.8s |  |
| 37 | `Instance-v6` | 52 | 1.6s |  |
| 38 | `Instance-v7` | 52 | 2.5s |  |
| 39 | `Instance-v8` | 52 | 1.4s |  |
| 40 | `Key-v5` | 51 | 23.0s |  |
| 41 | `Key-v6` | 55 | 3.0s |  |
| 42 | `Key-v7` | 55 | 2.7s |  |
| 43 | `Key-v8` | 55 | 1.6s |  |
| 44 | `LoadVars-v5` | 8 | 22.3s |  |
| 45 | `LocalConnection-v5` | 7 | 20.3s |  |
| 46 | `LocalConnection-v6` | 58 | 2.9s |  |
| 47 | `LocalConnection-v7` | 58 | 2.5s |  |
| 48 | `LocalConnection-v8` | 58 | 1.3s |  |
| 49 | `Matrix-v5` | 7 | 21.1s |  |
| 50 | `Microphone-v5` | 6 | 2.0s |  |
| 51 | `Mouse-v5` | 13 | 22.6s |  |
| 52 | `Mouse-v6` | 21 | 2.4s |  |
| 53 | `Mouse-v7` | 21 | 2.0s |  |
| 54 | `Mouse-v8` | 21 | 1.6s |  |
| 55 | `MovieClipLoader-v5` | 6 | 22.1s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.6s |  |
| 57 | `NetConnection-v5` | 7 | 22.0s |  |
| 58 | `NetStream-v5` | 6 | 20.8s |  |
| 59 | `NetStream-v6` | 80 | 3.4s |  |
| 60 | `NetStream-v7` | 80 | 3.0s |  |
| 61 | `NetStream-v8` | 80 | 1.3s |  |
| 62 | `Number-v6` | 239 | 9.0s |  |
| 63 | `Number-v7` | 237 | 8.7s |  |
| 64 | `Number-v8` | 237 | 1.5s |  |
| 65 | `Point-v5` | 7 | 20.9s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.6s |  |
| 68 | `Point-v8` | 193 | 8.0s |  |
| 69 | `Random-v5` | 30 | 21.1s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.1s |  |
| 72 | `Random-v8` | 30 | 1.5s |  |
| 73 | `Rectangle-v5` | 7 | 2.0s |  |
| 74 | `Rectangle-v6` | 7 | 0.6s |  |
| 75 | `Rectangle-v7` | 7 | 1.6s |  |
| 76 | `Selection-v5` | 21 | 21.8s |  |
| 77 | `Stage-v5` | 38 | 21.5s |  |
| 78 | `System-v5` | 67 | 22.6s |  |
| 79 | `System-v6` | 100 | 4.2s |  |
| 80 | `System-v7` | 101 | 4.3s |  |
| 81 | `System-v8` | 101 | 1.6s |  |
| 82 | `TextFieldHTML-v5` | 6 | 21.3s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.3s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.5s |  |
| 86 | `TextFormat-v5` | 128 | 5.2s |  |
| 87 | `TextFormat-v6` | 128 | 0.7s |  |
| 88 | `TextSnapshot-v5` | 7 | 20.9s |  |
| 89 | `TextSnapshot-v6` | 173 | 7.8s |  |
| 90 | `TextSnapshot-v7` | 173 | 7.4s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.6s |  |
| 92 | `Transform-v5` | 7 | 2.0s |  |
| 93 | `Transform-v6` | 7 | 1.4s |  |
| 94 | `Transform-v7` | 7 | 1.6s |  |
| 95 | `Try-v5` | 20 | 22.2s |  |
| 96 | `Try-v6` | 20 | 0.7s |  |
| 97 | `Try-v7` | 20 | 2.8s |  |
| 98 | `Try-v8` | 20 | 1.5s |  |
| 99 | `Video-v5` | 7 | 21.3s |  |
| 100 | `Video-v6` | 85 | 3.5s |  |
| 101 | `Video-v7` | 85 | 3.2s |  |
| 102 | `Video-v8` | 85 | 1.5s |  |
| 103 | `XMLSocket-v5` | 35 | 20.9s |  |
| 104 | `XMLSocket-v6` | 35 | 2.4s |  |
| 105 | `XMLSocket-v7` | 35 | 2.0s |  |
| 106 | `XMLSocket-v8` | 35 | 1.4s |  |
| 107 | `argstest-v5` | 4 | 1.9s |  |
| 108 | `case-v5` | 39 | 2.6s |  |
| 109 | `case-v6` | 73 | 3.4s |  |
| 110 | `case-v7` | 67 | 3.4s |  |
| 111 | `case-v8` | 67 | 1.5s |  |
| 112 | `delete-v5` | 61 | 21.4s |  |
| 113 | `delete-v6` | 61 | 2.3s |  |
| 114 | `delete-v7` | 61 | 2.5s |  |
| 115 | `delete-v8` | 61 | 1.5s |  |
| 116 | `enumerate-v5` | 6 | 1.8s |  |
| 117 | `enumerate-v6` | 49 | 2.8s |  |
| 118 | `enumerate-v7` | 49 | 2.4s |  |
| 119 | `enumerate-v8` | 49 | 1.3s |  |
| 120 | `flash-v5` | 10 | 20.9s |  |
| 121 | `flash-v6` | 10 | 2.1s |  |
| 122 | `flash-v7` | 10 | 1.7s |  |
| 123 | `flash-v8` | 41 | 22.0s |  |
| 124 | `getvariable-v5` | 58 | 3.4s |  |
| 125 | `getvariable-v6` | 64 | 3.6s |  |
| 126 | `getvariable-v7` | 64 | 3.6s |  |
| 127 | `getvariable-v8` | 64 | 1.6s |  |
| 128 | `swap-v5` | 7 | 20.5s |  |
| 129 | `swap-v6` | 7 | 0.6s |  |
| 130 | `swap-v7` | 7 | 1.4s |  |
| 131 | `swap-v8` | 7 | 1.2s |  |
| 132 | `targetPath-v5` | 12 | 1.9s |  |
| 133 | `targetPath-v6` | 23 | 2.1s |  |
| 134 | `targetPath-v7` | 23 | 1.7s |  |
| 135 | `targetPath-v8` | 23 | 1.2s |  |

## Ruffle-Matched Tests

**94 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 19.4s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.4s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 23.8s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.6s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.5s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 23.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.0s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.6s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.3s |  |
| 12 | `Date-v5` | 7 | 7 | 33.2s |  |
| 13 | `Date-v6` | 6 | 6 | 15.2s |  |
| 14 | `Date-v7` | 6 | 6 | 15.7s |  |
| 15 | `Date-v8` | 6 | 6 | 1.9s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.1s |  |
| 17 | `Function-v5` | 14 | 24 | 25.3s |  |
| 18 | `Function-v6` | 8 | 33 | 9.8s |  |
| 19 | `Function-v7` | 8 | 33 | 10.0s |  |
| 20 | `Function-v8` | 8 | 33 | 30.9s |  |
| 21 | `Global-v6` | 9 | 10 | 29.0s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.4s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.1s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.0s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 23.9s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 6.8s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 6.8s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 1.9s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.2s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.7s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.3s |  |
| 32 | `Math-v5` | 5 | 5 | 13.1s |  |
| 33 | `Math-v6` | 5 | 5 | 0.8s |  |
| 34 | `Math-v7` | 5 | 5 | 13.5s |  |
| 35 | `Math-v8` | 5 | 5 | 1.6s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.7s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.8s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.7s |  |
| 39 | `Microphone-v6` | 31 | 31 | 3.5s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.2s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.5s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 35.5s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.2s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.6s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.0s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.1s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.5s |  |
| 48 | `Number-v5` | 8 | 12 | 9.1s |  |
| 49 | `Object-v5` | 3 | 6 | 25.6s |  |
| 50 | `Object-v6` | 9 | 24 | 13.0s |  |
| 51 | `Object-v7` | 8 | 15 | 13.2s |  |
| 52 | `Object-v8` | 8 | 15 | 2.3s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 6.7s |  |
| 54 | `Selection-v6` | 7 | 13 | 5.6s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.6s |  |
| 57 | `Sound-v5` | 16 | 16 | 24.8s |  |
| 58 | `Sound-v6` | 8 | 37 | 5.5s |  |
| 59 | `Sound-v7` | 8 | 37 | 5.0s |  |
| 60 | `Sound-v8` | 8 | 37 | 1.9s |  |
| 61 | `Stage-v6` | 14 | 14 | 22.2s |  |
| 62 | `Stage-v7` | 14 | 14 | 2.8s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.6s |  |
| 64 | `String-v5` | 19 | 21 | 16.2s |  |
| 65 | `String-v6` | 10 | 10 | 17.1s |  |
| 66 | `String-v7` | 10 | 10 | 16.8s |  |
| 67 | `String-v8` | 10 | 10 | 2.0s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.1s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 6.7s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 27.4s |  |
| 71 | `XML-v5` | 10 | 79 | 36.1s |  |
| 72 | `XML-v6` | 3 | 98 | 17.0s |  |
| 73 | `XML-v7` | 3 | 98 | 16.7s |  |
| 74 | `XML-v8` | 24 | 116 | 5.0s |  |
| 75 | `XMLNode-v5` | 3 | 22 | 9.2s |  |
| 76 | `XMLNode-v6` | 3 | 22 | 9.2s |  |
| 77 | `XMLNode-v7` | 3 | 22 | 8.1s |  |
| 78 | `XMLNode-v8` | 3 | 22 | 1.6s |  |
| 79 | `ops-v5` | 7 | 9 | 29.1s |  |
| 80 | `ops-v6` | 7 | 11 | 8.9s |  |
| 81 | `ops-v7` | 7 | 11 | 9.6s |  |
| 82 | `ops-v8` | 7 | 11 | 20.6s |  |
| 83 | `setProperty-v5` | 49 | 49 | 3.1s |  |
| 84 | `setProperty-v6` | 49 | 49 | 3.1s |  |
| 85 | `setProperty-v7` | 49 | 49 | 2.8s |  |
| 86 | `setProperty-v8` | 49 | 49 | 1.9s |  |
| 87 | `toString_valueOf-v5` | 34 | 34 | 23.8s |  |
| 88 | `toString_valueOf-v6` | 5 | 5 | 5.3s |  |
| 89 | `toString_valueOf-v7` | 5 | 5 | 5.0s |  |
| 90 | `toString_valueOf-v8` | 5 | 5 | 1.4s |  |
| 91 | `with-v5` | 3 | 3 | 3.4s |  |
| 92 | `with-v6` | 6 | 9 | 4.5s |  |
| 93 | `with-v7` | 6 | 9 | 4.3s |  |
| 94 | `with-v8` | 6 | 9 | 1.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 98.6% | 552 | 560 | 8 |  |
| 2 | `array-v6` | 96.9% | 624 | 644 | 20 |  |
| 3 | `MovieClip-v7` | 96.2% | 932 | 969 | 37 |  |
| 4 | `MovieClip-v6` | 96.0% | 899 | 936 | 37 |  |
| 5 | `MovieClip-v8` | 93.7% | 1018 | 1087 | 69 |  |
| 6 | `array-v7` | 92.2% | 603 | 654 | 51 |  |
| 7 | `array-v8` | 92.2% | 603 | 654 | 51 |  |
| 8 | `Transform-v8` | 92.1% | 93 | 101 | 8 |  |
| 9 | `TextField-v6` | 85.0% | 463 | 545 | 82 |  |
| 10 | `TextField-v8` | 83.0% | 474 | 571 | 97 |  |
| 11 | `TextField-v7` | 82.8% | 472 | 570 | 98 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**14 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 98.6% | 552/560 | 560 | 560 |  |
| 2 | `array-v6` | 96.9% | 624/644 | 644 | 644 |  |
| 3 | `MovieClip-v7` | 96.2% | 932/969 | 954 | 969 |  |
| 4 | `MovieClip-v6` | 96.0% | 899/936 | 921 | 936 |  |
| 5 | `MovieClip-v8` | 93.7% | 1018/1087 | 1072 | 1087 |  |
| 6 | `array-v7` | 92.2% | 603/654 | 654 | 654 |  |
| 7 | `array-v8` | 92.2% | 603/654 | 654 | 654 |  |
| 8 | `Transform-v8` | 92.1% | 93/101 | 101 | 101 |  |
| 9 | `TextField-v6` | 85.0% | 463/545 | 545 | 545 |  |
| 10 | `TextField-v8` | 83.0% | 474/571 | 571 | 571 |  |
| 11 | `TextField-v7` | 82.8% | 472/570 | 570 | 570 |  |
| 12 | `argstest-v7` | 0.9% | 67/7301 | 7301 | 2061 |  |
| 13 | `argstest-v8` | 0.8% | 58/7663 | 7663 | 2434 |  |
| 14 | `argstest-v6` | 0.6% | 42/7301 | 7301 | 2192 |  |
