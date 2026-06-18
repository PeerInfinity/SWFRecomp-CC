# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 05:42 UTC

**Git SHA**: `5f25304460`

**Run Duration**: 38m 2s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 235 |
| Passing | **134** (57.0%) |
| Ruffle-matched | 88 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **222** (94.5%) |
| Failing | 13 |
| Total expected lines | 37932 |
| Matching lines | 29185 (76.9%) |
| Mismatched lines | 8747 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**134 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.9s |  |
| 2 | `Accessibility-v6` | 19 | 3.0s |  |
| 3 | `Accessibility-v7` | 19 | 2.6s |  |
| 4 | `Accessibility-v8` | 19 | 2.2s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.8s |  |
| 6 | `BitmapData-v5` | 7 | 3.0s |  |
| 7 | `BitmapData-v6` | 7 | 1.3s |  |
| 8 | `BitmapData-v7` | 7 | 2.5s |  |
| 9 | `Boolean-v5` | 38 | 3.7s |  |
| 10 | `Boolean-v6` | 38 | 2.9s |  |
| 11 | `Boolean-v7` | 38 | 17.4s |  |
| 12 | `Boolean-v8` | 38 | 2.2s |  |
| 13 | `Camera-v5` | 7 | 2.2s |  |
| 14 | `Color-v5` | 140 | 5.4s |  |
| 15 | `Color-v6` | 171 | 6.3s |  |
| 16 | `Color-v7` | 161 | 6.0s |  |
| 17 | `Color-v8` | 161 | 25.4s |  |
| 18 | `ColorTransform-v5` | 7 | 2.6s |  |
| 19 | `ColorTransform-v6` | 7 | 1.2s |  |
| 20 | `ColorTransform-v7` | 7 | 2.3s |  |
| 21 | `ColorTransform-v8` | 55 | 3.9s |  |
| 22 | `ContextMenu-v5` | 7 | 2.6s |  |
| 23 | `ContextMenu-v6` | 7 | 1.2s |  |
| 24 | `ContextMenu-v7` | 131 | 5.4s |  |
| 25 | `ContextMenu-v8` | 131 | 24.1s |  |
| 26 | `Error-v5` | 28 | 3.1s |  |
| 27 | `Error-v6` | 31 | 3.1s |  |
| 28 | `Error-v7` | 31 | 2.8s |  |
| 29 | `Error-v8` | 31 | 21.8s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.6s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.2s |  |
| 33 | `Global-v5` | 172 | 8.3s |  |
| 34 | `Global-v7` | 182 | 8.4s |  |
| 35 | `Global-v8` | 169 | 7.7s |  |
| 36 | `Instance-v5` | 52 | 4.0s |  |
| 37 | `Instance-v6` | 52 | 2.5s |  |
| 38 | `Instance-v7` | 52 | 3.6s |  |
| 39 | `Instance-v8` | 52 | 2.3s |  |
| 40 | `Key-v5` | 51 | 22.3s |  |
| 41 | `Key-v6` | 55 | 3.7s |  |
| 42 | `Key-v7` | 55 | 3.3s |  |
| 43 | `Key-v8` | 55 | 2.3s |  |
| 44 | `LoadVars-v5` | 8 | 21.8s |  |
| 45 | `LocalConnection-v5` | 7 | 21.2s |  |
| 46 | `LocalConnection-v6` | 58 | 3.7s |  |
| 47 | `LocalConnection-v7` | 58 | 3.4s |  |
| 48 | `LocalConnection-v8` | 58 | 2.1s |  |
| 49 | `Matrix-v5` | 7 | 21.5s |  |
| 50 | `Microphone-v5` | 6 | 2.8s |  |
| 51 | `Mouse-v5` | 13 | 22.4s |  |
| 52 | `Mouse-v6` | 21 | 3.0s |  |
| 53 | `Mouse-v7` | 21 | 2.7s |  |
| 54 | `Mouse-v8` | 21 | 2.2s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.2s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.2s |  |
| 57 | `NetConnection-v5` | 7 | 20.9s |  |
| 58 | `NetStream-v5` | 6 | 21.1s |  |
| 59 | `NetStream-v6` | 80 | 4.3s |  |
| 60 | `NetStream-v7` | 80 | 3.9s |  |
| 61 | `NetStream-v8` | 80 | 2.2s |  |
| 62 | `Number-v6` | 239 | 9.5s |  |
| 63 | `Number-v7` | 237 | 9.3s |  |
| 64 | `Number-v8` | 237 | 2.3s |  |
| 65 | `Point-v5` | 7 | 20.8s |  |
| 66 | `Point-v6` | 7 | 1.2s |  |
| 67 | `Point-v7` | 7 | 2.3s |  |
| 68 | `Point-v8` | 193 | 8.5s |  |
| 69 | `Random-v5` | 30 | 21.8s |  |
| 70 | `Random-v6` | 30 | 1.3s |  |
| 71 | `Random-v7` | 30 | 2.9s |  |
| 72 | `Random-v8` | 30 | 2.2s |  |
| 73 | `Rectangle-v5` | 7 | 2.8s |  |
| 74 | `Rectangle-v6` | 7 | 1.2s |  |
| 75 | `Rectangle-v7` | 7 | 2.4s |  |
| 76 | `Stage-v5` | 38 | 22.8s |  |
| 77 | `System-v5` | 67 | 22.4s |  |
| 78 | `System-v6` | 100 | 4.7s |  |
| 79 | `System-v7` | 101 | 4.7s |  |
| 80 | `System-v8` | 101 | 2.2s |  |
| 81 | `TextFieldHTML-v5` | 6 | 20.4s |  |
| 82 | `TextFieldHTML-v6` | 37 | 3.0s |  |
| 83 | `TextFieldHTML-v7` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 85 | `TextFormat-v5` | 128 | 5.3s |  |
| 86 | `TextFormat-v6` | 128 | 1.1s |  |
| 87 | `TextSnapshot-v5` | 7 | 21.3s |  |
| 88 | `TextSnapshot-v6` | 173 | 8.6s |  |
| 89 | `TextSnapshot-v7` | 173 | 8.2s |  |
| 90 | `TextSnapshot-v8` | 173 | 2.4s |  |
| 91 | `Transform-v5` | 7 | 2.8s |  |
| 92 | `Transform-v6` | 7 | 2.2s |  |
| 93 | `Transform-v7` | 7 | 2.4s |  |
| 94 | `Try-v5` | 20 | 21.9s |  |
| 95 | `Try-v6` | 20 | 1.2s |  |
| 96 | `Try-v7` | 20 | 3.3s |  |
| 97 | `Try-v8` | 20 | 2.1s |  |
| 98 | `Video-v5` | 7 | 20.8s |  |
| 99 | `Video-v6` | 85 | 4.1s |  |
| 100 | `Video-v7` | 85 | 3.7s |  |
| 101 | `Video-v8` | 85 | 2.1s |  |
| 102 | `XMLSocket-v5` | 35 | 21.8s |  |
| 103 | `XMLSocket-v6` | 35 | 3.4s |  |
| 104 | `XMLSocket-v7` | 35 | 3.0s |  |
| 105 | `XMLSocket-v8` | 35 | 2.3s |  |
| 106 | `argstest-v5` | 4 | 2.8s |  |
| 107 | `case-v5` | 39 | 3.8s |  |
| 108 | `case-v6` | 73 | 4.9s |  |
| 109 | `case-v7` | 67 | 4.8s |  |
| 110 | `case-v8` | 67 | 2.5s |  |
| 111 | `delete-v5` | 61 | 22.2s |  |
| 112 | `delete-v6` | 61 | 3.1s |  |
| 113 | `delete-v7` | 61 | 3.3s |  |
| 114 | `delete-v8` | 61 | 2.3s |  |
| 115 | `enumerate-v5` | 6 | 2.6s |  |
| 116 | `enumerate-v6` | 49 | 3.6s |  |
| 117 | `enumerate-v7` | 49 | 3.2s |  |
| 118 | `enumerate-v8` | 49 | 2.1s |  |
| 119 | `flash-v5` | 10 | 21.5s |  |
| 120 | `flash-v6` | 10 | 2.6s |  |
| 121 | `flash-v7` | 10 | 2.3s |  |
| 122 | `flash-v8` | 41 | 22.7s |  |
| 123 | `getvariable-v5` | 58 | 3.9s |  |
| 124 | `getvariable-v6` | 64 | 4.2s |  |
| 125 | `getvariable-v7` | 64 | 4.2s |  |
| 126 | `getvariable-v8` | 64 | 2.2s |  |
| 127 | `swap-v5` | 7 | 21.1s |  |
| 128 | `swap-v6` | 7 | 1.2s |  |
| 129 | `swap-v7` | 7 | 2.2s |  |
| 130 | `swap-v8` | 7 | 2.0s |  |
| 131 | `targetPath-v5` | 12 | 2.6s |  |
| 132 | `targetPath-v6` | 23 | 2.8s |  |
| 133 | `targetPath-v7` | 23 | 2.4s |  |
| 134 | `targetPath-v8` | 23 | 1.9s |  |

## Ruffle-Matched Tests

**88 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 6.7s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 26.1s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 6.2s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.6s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 26.2s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.9s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.9s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.8s |  |
| 12 | `Date-v5` | 7 | 7 | 33.0s |  |
| 13 | `Date-v6` | 6 | 6 | 15.7s |  |
| 14 | `Date-v7` | 6 | 6 | 16.0s |  |
| 15 | `Date-v8` | 6 | 6 | 2.6s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.7s |  |
| 17 | `Function-v5` | 14 | 24 | 25.1s |  |
| 18 | `Function-v6` | 8 | 33 | 10.1s |  |
| 19 | `Function-v7` | 8 | 33 | 10.3s |  |
| 20 | `Function-v8` | 8 | 33 | 30.2s |  |
| 21 | `Global-v6` | 9 | 10 | 28.0s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.8s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.4s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.4s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 27.1s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 8.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 8.1s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.9s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.4s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 6.1s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 3.0s |  |
| 32 | `Math-v5` | 5 | 5 | 14.4s |  |
| 33 | `Math-v6` | 5 | 5 | 1.5s |  |
| 34 | `Math-v7` | 5 | 5 | 14.8s |  |
| 35 | `Math-v8` | 5 | 5 | 2.4s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.2s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.3s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.3s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.2s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.9s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.2s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 32.9s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.7s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.2s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.6s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.7s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.3s |  |
| 48 | `Number-v5` | 8 | 12 | 9.7s |  |
| 49 | `Object-v5` | 3 | 6 | 24.7s |  |
| 50 | `Object-v6` | 9 | 24 | 13.3s |  |
| 51 | `Object-v7` | 8 | 15 | 13.4s |  |
| 52 | `Object-v8` | 8 | 15 | 2.7s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 7.5s |  |
| 54 | `Stage-v6` | 14 | 14 | 23.0s |  |
| 55 | `Stage-v7` | 14 | 14 | 3.8s |  |
| 56 | `Stage-v8` | 14 | 14 | 2.4s |  |
| 57 | `String-v5` | 19 | 21 | 17.5s |  |
| 58 | `String-v6` | 10 | 10 | 18.5s |  |
| 59 | `String-v7` | 10 | 10 | 18.2s |  |
| 60 | `String-v8` | 10 | 10 | 2.8s |  |
| 61 | `TextField-v5` | 3 | 3 | 2.7s |  |
| 62 | `TextFormat-v7` | 38 | 40 | 6.9s |  |
| 63 | `TextFormat-v8` | 36 | 38 | 25.5s |  |
| 64 | `Transform-v8` | 7 | 11 | 24.4s |  |
| 65 | `XML-v5` | 10 | 79 | 32.5s |  |
| 66 | `XML-v6` | 3 | 98 | 15.7s |  |
| 67 | `XML-v7` | 3 | 98 | 15.3s |  |
| 68 | `XML-v8` | 24 | 116 | 5.1s |  |
| 69 | `XMLNode-v5` | 3 | 22 | 8.7s |  |
| 70 | `XMLNode-v6` | 3 | 22 | 8.8s |  |
| 71 | `XMLNode-v7` | 3 | 22 | 7.6s |  |
| 72 | `XMLNode-v8` | 3 | 22 | 2.4s |  |
| 73 | `ops-v5` | 7 | 9 | 29.5s |  |
| 74 | `ops-v6` | 7 | 11 | 10.1s |  |
| 75 | `ops-v7` | 7 | 11 | 11.1s |  |
| 76 | `ops-v8` | 7 | 11 | 21.6s |  |
| 77 | `setProperty-v5` | 49 | 49 | 3.9s |  |
| 78 | `setProperty-v6` | 49 | 49 | 3.9s |  |
| 79 | `setProperty-v7` | 49 | 49 | 3.5s |  |
| 80 | `setProperty-v8` | 49 | 49 | 2.6s |  |
| 81 | `toString_valueOf-v5` | 34 | 34 | 26.1s |  |
| 82 | `toString_valueOf-v6` | 5 | 5 | 6.8s |  |
| 83 | `toString_valueOf-v7` | 5 | 5 | 6.3s |  |
| 84 | `toString_valueOf-v8` | 5 | 5 | 2.4s |  |
| 85 | `with-v5` | 3 | 3 | 4.3s |  |
| 86 | `with-v6` | 6 | 9 | 5.7s |  |
| 87 | `with-v7` | 6 | 9 | 5.2s |  |
| 88 | `with-v8` | 6 | 9 | 2.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |
| 2 | `array-v6` | 94.4% | 608 | 644 | 36 |  |
| 3 | `MovieClip-v6` | 94.0% | 880 | 936 | 56 |  |
| 4 | `MovieClip-v7` | 93.1% | 902 | 969 | 67 |  |
| 5 | `MovieClip-v8` | 90.9% | 988 | 1087 | 99 |  |
| 6 | `array-v7` | 90.1% | 589 | 654 | 65 |  |
| 7 | `array-v8` | 90.1% | 589 | 654 | 65 |  |
| 8 | `TextField-v6` | 83.7% | 456 | 545 | 89 |  |
| 9 | `TextField-v8` | 81.8% | 467 | 571 | 104 |  |
| 10 | `TextField-v7` | 81.6% | 465 | 570 | 105 |  |

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
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
| 2 | `array-v6` | 94.4% | 608/644 | 644 | 644 |  |
| 3 | `MovieClip-v6` | 94.0% | 880/936 | 921 | 936 |  |
| 4 | `MovieClip-v7` | 93.1% | 902/969 | 956 | 969 |  |
| 5 | `MovieClip-v8` | 90.9% | 988/1087 | 1074 | 1087 |  |
| 6 | `array-v7` | 90.1% | 589/654 | 654 | 654 |  |
| 7 | `array-v8` | 90.1% | 589/654 | 654 | 654 |  |
| 8 | `TextField-v6` | 83.7% | 456/545 | 545 | 545 |  |
| 9 | `TextField-v8` | 81.8% | 467/571 | 571 | 571 |  |
| 10 | `TextField-v7` | 81.6% | 465/570 | 570 | 570 |  |
| 11 | `argstest-v7` | 0.9% | 67/7301 | 7301 | 2061 |  |
| 12 | `argstest-v8` | 0.8% | 58/7663 | 7663 | 2434 |  |
| 13 | `argstest-v6` | 0.6% | 42/7301 | 7301 | 2192 |  |
