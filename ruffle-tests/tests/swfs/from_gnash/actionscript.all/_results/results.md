# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-30 04:01 UTC

**Git SHA**: `56970ac27a`

**Run Duration**: 35m 39s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **135** (55.6%) |
| Ruffle-matched | 95 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (94.7%) |
| Failing | 13 |
| Total expected lines | 38791 |
| Matching lines | 30101 (77.6%) |
| Mismatched lines | 8690 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**135 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.0s |  |
| 2 | `Accessibility-v6` | 19 | 2.1s |  |
| 3 | `Accessibility-v7` | 19 | 1.7s |  |
| 4 | `Accessibility-v8` | 19 | 1.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.9s |  |
| 6 | `BitmapData-v5` | 7 | 0.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.3s |  |
| 8 | `BitmapData-v7` | 7 | 0.3s |  |
| 9 | `Boolean-v5` | 38 | 0.3s |  |
| 10 | `Boolean-v6` | 38 | 0.3s |  |
| 11 | `Boolean-v7` | 38 | 17.0s |  |
| 12 | `Boolean-v8` | 38 | 1.2s |  |
| 13 | `Camera-v5` | 7 | 1.0s |  |
| 14 | `Color-v5` | 140 | 4.8s |  |
| 15 | `Color-v6` | 171 | 5.6s |  |
| 16 | `Color-v7` | 161 | 5.4s |  |
| 17 | `Color-v8` | 161 | 25.1s |  |
| 18 | `ColorTransform-v5` | 7 | 1.4s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.5s |  |
| 21 | `ColorTransform-v8` | 55 | 3.3s |  |
| 22 | `ContextMenu-v5` | 7 | 2.0s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.8s |  |
| 25 | `ContextMenu-v8` | 131 | 23.7s |  |
| 26 | `Error-v5` | 28 | 2.4s |  |
| 27 | `Error-v6` | 31 | 2.5s |  |
| 28 | `Error-v7` | 31 | 2.1s |  |
| 29 | `Error-v8` | 31 | 21.3s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.0s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.8s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.4s |  |
| 33 | `Global-v5` | 172 | 7.1s |  |
| 34 | `Global-v7` | 182 | 7.4s |  |
| 35 | `Global-v8` | 169 | 6.8s |  |
| 36 | `Instance-v5` | 52 | 2.9s |  |
| 37 | `Instance-v6` | 52 | 1.6s |  |
| 38 | `Instance-v7` | 52 | 2.6s |  |
| 39 | `Instance-v8` | 52 | 1.5s |  |
| 40 | `Key-v5` | 51 | 21.8s |  |
| 41 | `Key-v6` | 55 | 2.9s |  |
| 42 | `Key-v7` | 55 | 2.5s |  |
| 43 | `Key-v8` | 55 | 1.4s |  |
| 44 | `LoadVars-v5` | 8 | 20.9s |  |
| 45 | `LocalConnection-v5` | 7 | 16.8s |  |
| 46 | `LocalConnection-v6` | 58 | 2.5s |  |
| 47 | `LocalConnection-v7` | 58 | 2.2s |  |
| 48 | `LocalConnection-v8` | 58 | 1.1s |  |
| 49 | `Matrix-v5` | 7 | 20.7s |  |
| 50 | `Microphone-v5` | 6 | 2.0s |  |
| 51 | `Mouse-v5` | 13 | 22.5s |  |
| 52 | `Mouse-v6` | 21 | 2.3s |  |
| 53 | `Mouse-v7` | 21 | 1.9s |  |
| 54 | `Mouse-v8` | 21 | 1.5s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.4s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.6s |  |
| 57 | `NetConnection-v5` | 7 | 20.9s |  |
| 58 | `NetStream-v5` | 6 | 20.4s |  |
| 59 | `NetStream-v6` | 80 | 3.4s |  |
| 60 | `NetStream-v7` | 80 | 3.0s |  |
| 61 | `NetStream-v8` | 80 | 1.3s |  |
| 62 | `Number-v6` | 239 | 8.5s |  |
| 63 | `Number-v7` | 237 | 8.6s |  |
| 64 | `Number-v8` | 237 | 1.5s |  |
| 65 | `Point-v5` | 7 | 20.1s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.5s |  |
| 68 | `Point-v8` | 193 | 8.1s |  |
| 69 | `Random-v5` | 30 | 21.6s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.1s |  |
| 72 | `Random-v8` | 30 | 1.5s |  |
| 73 | `Rectangle-v5` | 7 | 1.5s |  |
| 74 | `Rectangle-v6` | 7 | 0.6s |  |
| 75 | `Rectangle-v7` | 7 | 1.5s |  |
| 76 | `Selection-v5` | 21 | 25.0s |  |
| 77 | `Stage-v5` | 38 | 21.7s |  |
| 78 | `System-v5` | 67 | 24.6s |  |
| 79 | `System-v6` | 100 | 4.5s |  |
| 80 | `System-v7` | 101 | 4.5s |  |
| 81 | `System-v8` | 101 | 1.6s |  |
| 82 | `TextFieldHTML-v5` | 6 | 20.8s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.2s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.4s |  |
| 86 | `TextFormat-v5` | 128 | 5.2s |  |
| 87 | `TextFormat-v6` | 128 | 0.7s |  |
| 88 | `TextSnapshot-v5` | 7 | 22.4s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.4s |  |
| 90 | `TextSnapshot-v7` | 173 | 8.1s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.6s |  |
| 92 | `Transform-v5` | 7 | 1.6s |  |
| 93 | `Transform-v6` | 7 | 1.5s |  |
| 94 | `Transform-v7` | 7 | 1.7s |  |
| 95 | `Try-v5` | 20 | 21.4s |  |
| 96 | `Try-v6` | 20 | 0.6s |  |
| 97 | `Try-v7` | 20 | 2.4s |  |
| 98 | `Try-v8` | 20 | 1.3s |  |
| 99 | `Video-v5` | 7 | 20.7s |  |
| 100 | `Video-v6` | 85 | 3.4s |  |
| 101 | `Video-v7` | 85 | 3.0s |  |
| 102 | `Video-v8` | 85 | 1.3s |  |
| 103 | `XMLSocket-v5` | 35 | 21.6s |  |
| 104 | `XMLSocket-v6` | 35 | 2.6s |  |
| 105 | `XMLSocket-v7` | 35 | 2.3s |  |
| 106 | `XMLSocket-v8` | 35 | 1.6s |  |
| 107 | `argstest-v5` | 4 | 2.2s |  |
| 108 | `case-v5` | 39 | 2.6s |  |
| 109 | `case-v6` | 73 | 3.5s |  |
| 110 | `case-v7` | 67 | 3.3s |  |
| 111 | `case-v8` | 67 | 1.4s |  |
| 112 | `delete-v5` | 61 | 22.4s |  |
| 113 | `delete-v6` | 61 | 2.4s |  |
| 114 | `delete-v7` | 61 | 2.6s |  |
| 115 | `delete-v8` | 61 | 1.5s |  |
| 116 | `enumerate-v5` | 6 | 1.8s |  |
| 117 | `enumerate-v6` | 49 | 3.0s |  |
| 118 | `enumerate-v7` | 49 | 2.5s |  |
| 119 | `enumerate-v8` | 49 | 1.3s |  |
| 120 | `flash-v5` | 10 | 20.9s |  |
| 121 | `flash-v6` | 10 | 2.0s |  |
| 122 | `flash-v7` | 10 | 1.7s |  |
| 123 | `flash-v8` | 41 | 22.0s |  |
| 124 | `getvariable-v5` | 58 | 3.4s |  |
| 125 | `getvariable-v6` | 64 | 3.4s |  |
| 126 | `getvariable-v7` | 64 | 3.5s |  |
| 127 | `getvariable-v8` | 64 | 1.6s |  |
| 128 | `swap-v5` | 7 | 19.3s |  |
| 129 | `swap-v6` | 7 | 0.4s |  |
| 130 | `swap-v7` | 7 | 0.4s |  |
| 131 | `swap-v8` | 7 | 0.4s |  |
| 132 | `targetPath-v5` | 12 | 0.4s |  |
| 133 | `targetPath-v6` | 23 | 0.4s |  |
| 134 | `targetPath-v7` | 23 | 0.4s |  |
| 135 | `targetPath-v8` | 23 | 0.4s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.8s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.5s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 16.5s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.3s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.3s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.7s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.4s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.1s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.2s |  |
| 12 | `Date-v5` | 7 | 7 | 32.5s |  |
| 13 | `Date-v6` | 6 | 6 | 15.1s |  |
| 14 | `Date-v7` | 6 | 6 | 15.7s |  |
| 15 | `Date-v8` | 6 | 6 | 2.0s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.9s |  |
| 17 | `Function-v5` | 14 | 24 | 24.9s |  |
| 18 | `Function-v6` | 8 | 33 | 9.6s |  |
| 19 | `Function-v7` | 8 | 33 | 9.8s |  |
| 20 | `Function-v8` | 8 | 33 | 29.6s |  |
| 21 | `Global-v6` | 9 | 10 | 27.4s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.5s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.7s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.5s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 23.7s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 6.9s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.1s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.1s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 5.5s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.3s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.2s |  |
| 32 | `Math-v5` | 5 | 5 | 11.9s |  |
| 33 | `Math-v6` | 5 | 5 | 0.7s |  |
| 34 | `Math-v7` | 5 | 5 | 12.4s |  |
| 35 | `Math-v8` | 5 | 5 | 1.3s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.5s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.5s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.5s |  |
| 39 | `Microphone-v6` | 31 | 31 | 3.5s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.1s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.5s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 34.0s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.0s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.6s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.1s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.2s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.6s |  |
| 48 | `Number-v5` | 8 | 12 | 8.7s |  |
| 49 | `Object-v5` | 3 | 6 | 25.0s |  |
| 50 | `Object-v6` | 9 | 24 | 13.1s |  |
| 51 | `Object-v7` | 8 | 15 | 13.3s |  |
| 52 | `Object-v8` | 8 | 15 | 2.2s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 7.0s |  |
| 54 | `Selection-v6` | 7 | 13 | 6.4s |  |
| 55 | `Selection-v7` | 7 | 13 | 6.1s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.6s |  |
| 57 | `Sound-v5` | 16 | 16 | 26.5s |  |
| 58 | `Sound-v6` | 8 | 37 | 6.0s |  |
| 59 | `Sound-v7` | 8 | 37 | 5.6s |  |
| 60 | `Sound-v8` | 8 | 37 | 2.0s |  |
| 61 | `Stage-v6` | 14 | 14 | 22.4s |  |
| 62 | `Stage-v7` | 14 | 14 | 2.9s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.6s |  |
| 64 | `String-v5` | 19 | 21 | 16.8s |  |
| 65 | `String-v6` | 10 | 10 | 17.6s |  |
| 66 | `String-v7` | 10 | 10 | 17.4s |  |
| 67 | `String-v8` | 10 | 10 | 2.0s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.2s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 6.9s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 25.9s |  |
| 71 | `Transform-v8` | 7 | 11 | 26.3s |  |
| 72 | `XML-v5` | 10 | 79 | 33.8s |  |
| 73 | `XML-v6` | 3 | 98 | 16.0s |  |
| 74 | `XML-v7` | 3 | 98 | 15.7s |  |
| 75 | `XML-v8` | 24 | 116 | 4.6s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 8.7s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.7s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 7.5s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.8s |  |
| 80 | `ops-v5` | 7 | 9 | 28.1s |  |
| 81 | `ops-v6` | 7 | 11 | 8.4s |  |
| 82 | `ops-v7` | 7 | 11 | 9.1s |  |
| 83 | `ops-v8` | 7 | 11 | 20.5s |  |
| 84 | `setProperty-v5` | 49 | 49 | 2.9s |  |
| 85 | `setProperty-v6` | 49 | 49 | 3.0s |  |
| 86 | `setProperty-v7` | 49 | 49 | 2.6s |  |
| 87 | `setProperty-v8` | 49 | 49 | 1.6s |  |
| 88 | `toString_valueOf-v5` | 34 | 34 | 19.3s |  |
| 89 | `toString_valueOf-v6` | 5 | 5 | 4.6s |  |
| 90 | `toString_valueOf-v7` | 5 | 5 | 4.2s |  |
| 91 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 92 | `with-v5` | 3 | 3 | 2.7s |  |
| 93 | `with-v6` | 6 | 9 | 3.8s |  |
| 94 | `with-v7` | 6 | 9 | 3.5s |  |
| 95 | `with-v8` | 6 | 9 | 1.3s |  |

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
