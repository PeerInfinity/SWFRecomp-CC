# Ruffle Test Results (Filtered)

**Date**: 2026-08-13 22:38 UTC

**Git SHA**: `3db858cbc1`

**Run Duration**: 37m 18s

**Filtered**: 4 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 239 |
| Passing | **135** (56.5%) |
| Ruffle-matched | 95 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (96.2%) |
| Failing | 9 |
| Total expected lines | 31544 |
| Matching lines | 29444 (93.3%) |
| Mismatched lines | 2100 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**135 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.1s |  |
| 2 | `Accessibility-v6` | 19 | 2.2s |  |
| 3 | `Accessibility-v7` | 19 | 1.7s |  |
| 4 | `Accessibility-v8` | 19 | 1.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.2s |  |
| 6 | `BitmapData-v5` | 7 | 2.8s |  |
| 7 | `BitmapData-v6` | 7 | 1.3s |  |
| 8 | `BitmapData-v7` | 7 | 2.4s |  |
| 9 | `Boolean-v5` | 38 | 3.3s |  |
| 10 | `Boolean-v6` | 38 | 2.8s |  |
| 11 | `Boolean-v7` | 38 | 22.1s |  |
| 12 | `Boolean-v8` | 38 | 2.3s |  |
| 13 | `Camera-v5` | 7 | 2.8s |  |
| 14 | `Color-v5` | 140 | 6.3s |  |
| 15 | `Color-v6` | 171 | 7.6s |  |
| 16 | `Color-v7` | 161 | 7.2s |  |
| 17 | `Color-v8` | 161 | 26.8s |  |
| 18 | `ColorTransform-v5` | 7 | 3.0s |  |
| 19 | `ColorTransform-v6` | 7 | 1.4s |  |
| 20 | `ColorTransform-v7` | 7 | 2.6s |  |
| 21 | `ColorTransform-v8` | 55 | 4.3s |  |
| 22 | `ContextMenu-v5` | 7 | 3.0s |  |
| 23 | `ContextMenu-v6` | 7 | 1.4s |  |
| 24 | `ContextMenu-v7` | 131 | 6.1s |  |
| 25 | `ContextMenu-v8` | 131 | 23.9s |  |
| 26 | `Error-v5` | 28 | 3.2s |  |
| 27 | `Error-v6` | 31 | 3.3s |  |
| 28 | `Error-v7` | 31 | 2.9s |  |
| 29 | `Error-v8` | 31 | 18.4s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.3s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.0s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 33 | `Global-v5` | 172 | 6.7s |  |
| 34 | `Global-v7` | 182 | 7.1s |  |
| 35 | `Global-v8` | 169 | 6.9s |  |
| 36 | `Instance-v5` | 52 | 3.0s |  |
| 37 | `Instance-v6` | 52 | 1.8s |  |
| 38 | `Instance-v7` | 52 | 2.6s |  |
| 39 | `Instance-v8` | 52 | 1.7s |  |
| 40 | `Key-v5` | 51 | 22.9s |  |
| 41 | `Key-v6` | 55 | 3.9s |  |
| 42 | `Key-v7` | 55 | 3.5s |  |
| 43 | `Key-v8` | 55 | 2.4s |  |
| 44 | `LoadVars-v5` | 8 | 22.1s |  |
| 45 | `LocalConnection-v5` | 7 | 21.7s |  |
| 46 | `LocalConnection-v6` | 58 | 4.1s |  |
| 47 | `LocalConnection-v7` | 58 | 3.6s |  |
| 48 | `LocalConnection-v8` | 58 | 2.4s |  |
| 49 | `Matrix-v5` | 7 | 21.8s |  |
| 50 | `Microphone-v5` | 6 | 2.9s |  |
| 51 | `Mouse-v5` | 13 | 18.6s |  |
| 52 | `Mouse-v6` | 21 | 2.5s |  |
| 53 | `Mouse-v7` | 21 | 2.2s |  |
| 54 | `Mouse-v8` | 21 | 2.2s |  |
| 55 | `MovieClipLoader-v5` | 6 | 22.2s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.4s |  |
| 57 | `NetConnection-v5` | 7 | 22.0s |  |
| 58 | `NetStream-v5` | 6 | 22.0s |  |
| 59 | `NetStream-v6` | 80 | 4.4s |  |
| 60 | `NetStream-v7` | 80 | 4.0s |  |
| 61 | `NetStream-v8` | 80 | 2.1s |  |
| 62 | `Number-v6` | 239 | 9.5s |  |
| 63 | `Number-v7` | 237 | 9.4s |  |
| 64 | `Number-v8` | 237 | 2.3s |  |
| 65 | `Point-v5` | 7 | 21.4s |  |
| 66 | `Point-v6` | 7 | 1.3s |  |
| 67 | `Point-v7` | 7 | 2.5s |  |
| 68 | `Point-v8` | 193 | 8.8s |  |
| 69 | `Random-v5` | 30 | 16.4s |  |
| 70 | `Random-v6` | 30 | 0.9s |  |
| 71 | `Random-v7` | 30 | 1.9s |  |
| 72 | `Random-v8` | 30 | 1.6s |  |
| 73 | `Rectangle-v5` | 7 | 2.1s |  |
| 74 | `Rectangle-v6` | 7 | 0.9s |  |
| 75 | `Rectangle-v7` | 7 | 1.9s |  |
| 76 | `Selection-v5` | 21 | 22.0s |  |
| 77 | `Stage-v5` | 38 | 17.5s |  |
| 78 | `System-v5` | 67 | 21.6s |  |
| 79 | `System-v6` | 100 | 4.3s |  |
| 80 | `System-v7` | 101 | 4.3s |  |
| 81 | `System-v8` | 101 | 2.0s |  |
| 82 | `TextFieldHTML-v5` | 6 | 17.8s |  |
| 83 | `TextFieldHTML-v6` | 37 | 3.0s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.7s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 86 | `TextFormat-v5` | 128 | 5.3s |  |
| 87 | `TextFormat-v6` | 128 | 1.2s |  |
| 88 | `TextSnapshot-v5` | 7 | 22.1s |  |
| 89 | `TextSnapshot-v6` | 173 | 9.1s |  |
| 90 | `TextSnapshot-v7` | 173 | 8.8s |  |
| 91 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 92 | `Transform-v5` | 7 | 3.0s |  |
| 93 | `Transform-v6` | 7 | 2.4s |  |
| 94 | `Transform-v7` | 7 | 2.6s |  |
| 95 | `Try-v5` | 20 | 24.2s |  |
| 96 | `Try-v6` | 20 | 1.3s |  |
| 97 | `Try-v7` | 20 | 3.4s |  |
| 98 | `Try-v8` | 20 | 2.3s |  |
| 99 | `Video-v5` | 7 | 23.7s |  |
| 100 | `Video-v6` | 85 | 4.7s |  |
| 101 | `Video-v7` | 85 | 4.1s |  |
| 102 | `Video-v8` | 85 | 2.3s |  |
| 103 | `XMLSocket-v5` | 35 | 22.3s |  |
| 104 | `XMLSocket-v6` | 35 | 3.6s |  |
| 105 | `XMLSocket-v7` | 35 | 3.2s |  |
| 106 | `XMLSocket-v8` | 35 | 2.5s |  |
| 107 | `argstest-v5` | 4 | 3.1s |  |
| 108 | `case-v5` | 39 | 3.5s |  |
| 109 | `case-v6` | 73 | 4.4s |  |
| 110 | `case-v7` | 67 | 4.4s |  |
| 111 | `case-v8` | 67 | 2.5s |  |
| 112 | `delete-v5` | 61 | 17.8s |  |
| 113 | `delete-v6` | 61 | 2.7s |  |
| 114 | `delete-v7` | 61 | 2.9s |  |
| 115 | `delete-v8` | 61 | 2.0s |  |
| 116 | `enumerate-v5` | 6 | 2.3s |  |
| 117 | `enumerate-v6` | 49 | 3.1s |  |
| 118 | `enumerate-v7` | 49 | 2.8s |  |
| 119 | `enumerate-v8` | 49 | 1.9s |  |
| 120 | `flash-v5` | 10 | 19.7s |  |
| 121 | `flash-v6` | 10 | 1.1s |  |
| 122 | `flash-v7` | 10 | 1.1s |  |
| 123 | `flash-v8` | 41 | 19.8s |  |
| 124 | `getvariable-v5` | 58 | 1.1s |  |
| 125 | `getvariable-v6` | 64 | 1.1s |  |
| 126 | `getvariable-v7` | 64 | 1.1s |  |
| 127 | `getvariable-v8` | 64 | 1.1s |  |
| 128 | `swap-v5` | 7 | 16.0s |  |
| 129 | `swap-v6` | 7 | 0.8s |  |
| 130 | `swap-v7` | 7 | 1.5s |  |
| 131 | `swap-v8` | 7 | 1.4s |  |
| 132 | `targetPath-v5` | 12 | 1.9s |  |
| 133 | `targetPath-v6` | 23 | 2.3s |  |
| 134 | `targetPath-v7` | 23 | 2.0s |  |
| 135 | `targetPath-v8` | 23 | 1.4s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 18.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.3s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.0s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.5s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 24.1s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.5s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 23.8s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.9s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.5s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.3s |  |
| 12 | `Date-v5` | 7 | 7 | 32.1s |  |
| 13 | `Date-v6` | 6 | 6 | 15.3s |  |
| 14 | `Date-v7` | 6 | 6 | 15.8s |  |
| 15 | `Date-v8` | 6 | 6 | 2.8s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.4s |  |
| 17 | `Function-v5` | 14 | 24 | 21.0s |  |
| 18 | `Function-v6` | 8 | 33 | 8.1s |  |
| 19 | `Function-v7` | 8 | 33 | 8.3s |  |
| 20 | `Function-v8` | 8 | 33 | 25.4s |  |
| 21 | `Global-v6` | 9 | 10 | 22.9s |  |
| 22 | `HitTest-v6` | 8 | 8 | 4.9s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.6s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.4s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 19.9s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 5.6s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 5.9s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.3s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.7s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 6.3s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 3.3s |  |
| 32 | `Math-v5` | 5 | 5 | 14.8s |  |
| 33 | `Math-v6` | 5 | 5 | 1.6s |  |
| 34 | `Math-v7` | 5 | 5 | 15.2s |  |
| 35 | `Math-v8` | 5 | 5 | 2.7s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.2s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.2s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.5s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.4s |  |
| 40 | `Microphone-v7` | 31 | 31 | 4.0s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.4s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 29.4s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 5.0s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.6s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 6.2s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 6.1s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.6s |  |
| 48 | `Number-v5` | 8 | 12 | 9.7s |  |
| 49 | `Object-v5` | 3 | 6 | 25.1s |  |
| 50 | `Object-v6` | 8 | 24 | 13.5s |  |
| 51 | `Object-v7` | 8 | 15 | 13.7s |  |
| 52 | `Object-v8` | 8 | 15 | 3.1s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 5.8s |  |
| 54 | `Selection-v6` | 7 | 13 | 6.2s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.9s |  |
| 56 | `Selection-v8` | 7 | 13 | 2.4s |  |
| 57 | `Sound-v5` | 16 | 16 | 25.2s |  |
| 58 | `Sound-v6` | 8 | 37 | 6.3s |  |
| 59 | `Sound-v7` | 8 | 37 | 5.9s |  |
| 60 | `Sound-v8` | 8 | 37 | 2.8s |  |
| 61 | `Stage-v6` | 14 | 14 | 18.0s |  |
| 62 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 63 | `Stage-v8` | 14 | 14 | 2.0s |  |
| 64 | `String-v5` | 19 | 21 | 14.4s |  |
| 65 | `String-v6` | 10 | 10 | 15.2s |  |
| 66 | `String-v7` | 10 | 10 | 14.7s |  |
| 67 | `String-v8` | 10 | 10 | 2.3s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.6s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 6.8s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 22.5s |  |
| 71 | `Transform-v8` | 7 | 11 | 25.5s |  |
| 72 | `XML-v5` | 10 | 79 | 34.8s |  |
| 73 | `XML-v6` | 3 | 98 | 17.3s |  |
| 74 | `XML-v7` | 3 | 98 | 17.0s |  |
| 75 | `XML-v8` | 24 | 116 | 5.7s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 9.8s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 9.8s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 8.4s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 2.7s |  |
| 80 | `ops-v5` | 7 | 9 | 29.4s |  |
| 81 | `ops-v6` | 7 | 11 | 9.8s |  |
| 82 | `ops-v7` | 7 | 11 | 10.4s |  |
| 83 | `ops-v8` | 7 | 11 | 21.1s |  |
| 84 | `setProperty-v5` | 49 | 49 | 3.8s |  |
| 85 | `setProperty-v6` | 49 | 49 | 3.8s |  |
| 86 | `setProperty-v7` | 49 | 49 | 3.5s |  |
| 87 | `setProperty-v8` | 49 | 49 | 2.5s |  |
| 88 | `toString_valueOf-v5` | 34 | 34 | 26.5s |  |
| 89 | `toString_valueOf-v6` | 5 | 5 | 7.2s |  |
| 90 | `toString_valueOf-v7` | 5 | 5 | 7.1s |  |
| 91 | `toString_valueOf-v8` | 5 | 5 | 2.8s |  |
| 92 | `with-v5` | 3 | 3 | 5.1s |  |
| 93 | `with-v6` | 6 | 9 | 6.4s |  |
| 94 | `with-v7` | 6 | 9 | 5.8s |  |
| 95 | `with-v8` | 6 | 9 | 2.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**9 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v6` | 96.7% | 623 | 644 | 21 |  |
| 2 | `MovieClip-v7` | 96.4% | 934 | 969 | 35 |  |
| 3 | `MovieClip-v6` | 96.3% | 901 | 936 | 35 |  |
| 4 | `MovieClip-v8` | 93.8% | 1020 | 1087 | 67 |  |
| 5 | `array-v7` | 92.4% | 604 | 654 | 50 |  |
| 6 | `array-v8` | 92.4% | 604 | 654 | 50 |  |
| 7 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 8 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 9 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v6` | 96.7% | 623/644 | 644 | 644 |  |
| 2 | `MovieClip-v7` | 96.4% | 934/969 | 954 | 969 |  |
| 3 | `MovieClip-v6` | 96.3% | 901/936 | 921 | 936 |  |
| 4 | `MovieClip-v8` | 93.8% | 1020/1087 | 1072 | 1087 |  |
| 5 | `array-v7` | 92.4% | 604/654 | 654 | 654 |  |
| 6 | `array-v8` | 92.4% | 604/654 | 654 | 654 |  |
| 7 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 8 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 9 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
