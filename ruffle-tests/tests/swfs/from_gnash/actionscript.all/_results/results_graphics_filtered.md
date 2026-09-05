# Ruffle Test Results (Filtered)

**Date**: 2026-09-05 05:20 UTC

**Git SHA**: `12d2ec06b7`

**Run Duration**: 33m 2s

**Filtered**: 4 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 239 |
| Passing | **141** (59.0%) |
| Ruffle-matched | 89 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (96.2%) |
| Failing | 9 |
| Total expected lines | 31544 |
| Matching lines | 29502 (93.5%) |
| Mismatched lines | 2042 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**141 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.0s |  |
| 2 | `Accessibility-v6` | 19 | 3.0s |  |
| 3 | `Accessibility-v7` | 19 | 2.7s |  |
| 4 | `Accessibility-v8` | 19 | 2.3s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.9s |  |
| 6 | `BitmapData-v5` | 7 | 3.1s |  |
| 7 | `BitmapData-v6` | 7 | 1.4s |  |
| 8 | `BitmapData-v7` | 7 | 2.7s |  |
| 9 | `Boolean-v5` | 38 | 3.6s |  |
| 10 | `Boolean-v6` | 38 | 3.1s |  |
| 11 | `Boolean-v7` | 38 | 16.6s |  |
| 12 | `Boolean-v8` | 38 | 1.6s |  |
| 13 | `Camera-v5` | 7 | 2.2s |  |
| 14 | `Color-v5` | 140 | 4.2s |  |
| 15 | `Color-v6` | 171 | 5.1s |  |
| 16 | `Color-v7` | 161 | 4.8s |  |
| 17 | `Color-v8` | 161 | 28.4s |  |
| 18 | `ColorTransform-v5` | 7 | 3.1s |  |
| 19 | `ColorTransform-v6` | 7 | 1.5s |  |
| 20 | `ColorTransform-v7` | 7 | 2.6s |  |
| 21 | `ColorTransform-v8` | 55 | 4.5s |  |
| 22 | `ContextMenu-v5` | 7 | 3.1s |  |
| 23 | `ContextMenu-v6` | 7 | 1.4s |  |
| 24 | `ContextMenu-v7` | 131 | 6.2s |  |
| 25 | `ContextMenu-v8` | 131 | 23.4s |  |
| 26 | `Error-v5` | 28 | 2.8s |  |
| 27 | `Error-v6` | 31 | 2.9s |  |
| 28 | `Error-v7` | 31 | 2.5s |  |
| 29 | `Error-v8` | 31 | 23.4s |  |
| 30 | `ExternalInterface-v5` | 7 | 3.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 4.0s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.6s |  |
| 33 | `Function-v6` | 271 | 11.0s |  |
| 34 | `Function-v7` | 272 | 11.3s |  |
| 35 | `Function-v8` | 272 | 22.7s |  |
| 36 | `Global-v5` | 172 | 5.7s |  |
| 37 | `Global-v7` | 182 | 6.0s |  |
| 38 | `Global-v8` | 169 | 5.5s |  |
| 39 | `Instance-v5` | 52 | 3.7s |  |
| 40 | `Instance-v6` | 52 | 2.3s |  |
| 41 | `Instance-v7` | 52 | 3.3s |  |
| 42 | `Instance-v8` | 52 | 2.1s |  |
| 43 | `Key-v5` | 51 | 23.0s |  |
| 44 | `Key-v6` | 55 | 3.9s |  |
| 45 | `Key-v7` | 55 | 3.5s |  |
| 46 | `Key-v8` | 55 | 2.4s |  |
| 47 | `LoadVars-v5` | 8 | 3.0s |  |
| 48 | `LocalConnection-v5` | 7 | 21.8s |  |
| 49 | `LocalConnection-v6` | 58 | 3.9s |  |
| 50 | `LocalConnection-v7` | 58 | 3.6s |  |
| 51 | `LocalConnection-v8` | 58 | 2.4s |  |
| 52 | `Matrix-v5` | 7 | 22.9s |  |
| 53 | `Microphone-v5` | 6 | 2.9s |  |
| 54 | `Mouse-v5` | 13 | 20.9s |  |
| 55 | `Mouse-v6` | 21 | 2.7s |  |
| 56 | `Mouse-v7` | 21 | 2.3s |  |
| 57 | `Mouse-v8` | 21 | 1.9s |  |
| 58 | `MovieClipLoader-v5` | 6 | 22.4s |  |
| 59 | `MovieClipLoader-v6` | 6 | 1.4s |  |
| 60 | `NetConnection-v5` | 7 | 3.0s |  |
| 61 | `NetStream-v5` | 6 | 22.1s |  |
| 62 | `NetStream-v6` | 80 | 4.5s |  |
| 63 | `NetStream-v7` | 80 | 4.2s |  |
| 64 | `NetStream-v8` | 80 | 2.4s |  |
| 65 | `Number-v6` | 239 | 9.7s |  |
| 66 | `Number-v7` | 237 | 9.7s |  |
| 67 | `Number-v8` | 237 | 2.5s |  |
| 68 | `Point-v5` | 7 | 2.8s |  |
| 69 | `Point-v6` | 7 | 1.3s |  |
| 70 | `Point-v7` | 7 | 2.5s |  |
| 71 | `Point-v8` | 193 | 8.8s |  |
| 72 | `Random-v5` | 30 | 23.3s |  |
| 73 | `Random-v6` | 30 | 1.5s |  |
| 74 | `Random-v7` | 30 | 3.2s |  |
| 75 | `Random-v8` | 30 | 2.5s |  |
| 76 | `Rectangle-v5` | 7 | 3.1s |  |
| 77 | `Rectangle-v6` | 7 | 1.4s |  |
| 78 | `Rectangle-v7` | 7 | 2.7s |  |
| 79 | `Selection-v5` | 21 | 22.7s |  |
| 80 | `Sound-v6` | 121 | 6.3s |  |
| 81 | `Sound-v7` | 121 | 6.0s |  |
| 82 | `Sound-v8` | 121 | 2.9s |  |
| 83 | `Stage-v5` | 38 | 18.8s |  |
| 84 | `System-v5` | 67 | 19.4s |  |
| 85 | `System-v6` | 100 | 4.4s |  |
| 86 | `System-v7` | 101 | 4.4s |  |
| 87 | `System-v8` | 101 | 2.1s |  |
| 88 | `TextFieldHTML-v5` | 6 | 23.9s |  |
| 89 | `TextFieldHTML-v6` | 37 | 3.8s |  |
| 90 | `TextFieldHTML-v7` | 37 | 3.5s |  |
| 91 | `TextFieldHTML-v8` | 37 | 2.6s |  |
| 92 | `TextFormat-v5` | 128 | 6.7s |  |
| 93 | `TextFormat-v6` | 128 | 1.6s |  |
| 94 | `TextSnapshot-v5` | 7 | 22.1s |  |
| 95 | `TextSnapshot-v6` | 173 | 8.6s |  |
| 96 | `TextSnapshot-v7` | 173 | 8.2s |  |
| 97 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 98 | `Transform-v5` | 7 | 2.8s |  |
| 99 | `Transform-v6` | 7 | 2.3s |  |
| 100 | `Transform-v7` | 7 | 2.5s |  |
| 101 | `Try-v5` | 20 | 23.3s |  |
| 102 | `Try-v6` | 20 | 1.5s |  |
| 103 | `Try-v7` | 20 | 3.5s |  |
| 104 | `Try-v8` | 20 | 2.5s |  |
| 105 | `Video-v5` | 7 | 3.1s |  |
| 106 | `Video-v6` | 85 | 4.5s |  |
| 107 | `Video-v7` | 85 | 4.2s |  |
| 108 | `Video-v8` | 85 | 2.5s |  |
| 109 | `XMLSocket-v5` | 35 | 22.7s |  |
| 110 | `XMLSocket-v6` | 35 | 3.5s |  |
| 111 | `XMLSocket-v7` | 35 | 3.2s |  |
| 112 | `XMLSocket-v8` | 35 | 2.5s |  |
| 113 | `argstest-v5` | 4 | 3.0s |  |
| 114 | `case-v5` | 39 | 3.1s |  |
| 115 | `case-v6` | 73 | 3.8s |  |
| 116 | `case-v7` | 67 | 4.0s |  |
| 117 | `case-v8` | 67 | 2.1s |  |
| 118 | `delete-v5` | 61 | 22.8s |  |
| 119 | `delete-v6` | 61 | 3.3s |  |
| 120 | `delete-v7` | 61 | 3.5s |  |
| 121 | `delete-v8` | 61 | 2.5s |  |
| 122 | `enumerate-v5` | 6 | 2.8s |  |
| 123 | `enumerate-v6` | 49 | 3.8s |  |
| 124 | `enumerate-v7` | 49 | 3.5s |  |
| 125 | `enumerate-v8` | 49 | 2.3s |  |
| 126 | `flash-v5` | 10 | 18.4s |  |
| 127 | `flash-v6` | 10 | 2.1s |  |
| 128 | `flash-v7` | 10 | 1.9s |  |
| 129 | `flash-v8` | 41 | 2.8s |  |
| 130 | `getvariable-v5` | 58 | 3.1s |  |
| 131 | `getvariable-v6` | 64 | 3.0s |  |
| 132 | `getvariable-v7` | 64 | 3.2s |  |
| 133 | `getvariable-v8` | 64 | 1.7s |  |
| 134 | `swap-v5` | 7 | 22.2s |  |
| 135 | `swap-v6` | 7 | 1.4s |  |
| 136 | `swap-v7` | 7 | 2.6s |  |
| 137 | `swap-v8` | 7 | 2.4s |  |
| 138 | `targetPath-v5` | 12 | 3.0s |  |
| 139 | `targetPath-v6` | 23 | 3.2s |  |
| 140 | `targetPath-v7` | 23 | 2.8s |  |
| 141 | `targetPath-v8` | 23 | 2.3s |  |

## Ruffle-Matched Tests

**89 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 25.3s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.4s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.1s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.6s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 27.0s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 6.3s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.7s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 26.4s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.5s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.1s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.6s |  |
| 12 | `Date-v5` | 7 | 7 | 12.7s |  |
| 13 | `Date-v6` | 6 | 6 | 14.2s |  |
| 14 | `Date-v7` | 6 | 6 | 14.8s |  |
| 15 | `Date-v8` | 6 | 6 | 2.4s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 6.2s |  |
| 17 | `Function-v5` | 10 | 24 | 7.0s |  |
| 18 | `Global-v6` | 9 | 10 | 7.0s |  |
| 19 | `HitTest-v6` | 8 | 8 | 4.3s |  |
| 20 | `HitTest-v7` | 8 | 8 | 3.9s |  |
| 21 | `HitTest-v8` | 9 | 9 | 3.8s |  |
| 22 | `Inheritance-v5` | 1 | 17 | 25.3s |  |
| 23 | `Inheritance-v6` | 9 | 16 | 7.4s |  |
| 24 | `Inheritance-v7` | 5 | 10 | 7.5s |  |
| 25 | `Inheritance-v8` | 5 | 10 | 2.7s |  |
| 26 | `LoadVars-v6` | 6 | 8 | 6.5s |  |
| 27 | `LoadVars-v7` | 6 | 8 | 6.2s |  |
| 28 | `LoadVars-v8` | 6 | 8 | 3.2s |  |
| 29 | `Math-v5` | 5 | 5 | 14.2s |  |
| 30 | `Math-v6` | 5 | 5 | 1.5s |  |
| 31 | `Math-v7` | 5 | 5 | 14.7s |  |
| 32 | `Math-v8` | 5 | 5 | 2.6s |  |
| 33 | `Matrix-v6` | 29 | 71 | 8.6s |  |
| 34 | `Matrix-v7` | 28 | 70 | 8.7s |  |
| 35 | `Matrix-v8` | 28 | 70 | 2.7s |  |
| 36 | `Microphone-v6` | 31 | 31 | 4.6s |  |
| 37 | `Microphone-v7` | 31 | 31 | 4.2s |  |
| 38 | `Microphone-v8` | 31 | 31 | 2.5s |  |
| 39 | `MovieClip-v5` | 24 | 226 | 12.1s |  |
| 40 | `MovieClipLoader-v7` | 118 | 118 | 5.0s |  |
| 41 | `MovieClipLoader-v8` | 118 | 118 | 3.6s |  |
| 42 | `NetConnection-v6` | 4 | 49 | 6.0s |  |
| 43 | `NetConnection-v7` | 4 | 45 | 6.0s |  |
| 44 | `NetConnection-v8` | 4 | 45 | 2.6s |  |
| 45 | `Number-v5` | 8 | 12 | 10.0s |  |
| 46 | `Object-v5` | 3 | 6 | 25.7s |  |
| 47 | `Object-v6` | 8 | 24 | 13.5s |  |
| 48 | `Object-v7` | 8 | 15 | 13.8s |  |
| 49 | `Object-v8` | 8 | 15 | 3.1s |  |
| 50 | `Rectangle-v8` | 21 | 21 | 8.2s |  |
| 51 | `Selection-v6` | 7 | 13 | 6.4s |  |
| 52 | `Selection-v7` | 7 | 13 | 6.0s |  |
| 53 | `Selection-v8` | 7 | 13 | 2.6s |  |
| 54 | `Sound-v5` | 14 | 16 | 6.2s |  |
| 55 | `Stage-v6` | 14 | 14 | 3.5s |  |
| 56 | `Stage-v7` | 14 | 14 | 3.3s |  |
| 57 | `Stage-v8` | 14 | 14 | 2.2s |  |
| 58 | `String-v5` | 18 | 21 | 15.2s |  |
| 59 | `String-v6` | 9 | 10 | 15.8s |  |
| 60 | `String-v7` | 9 | 10 | 15.9s |  |
| 61 | `String-v8` | 9 | 10 | 2.5s |  |
| 62 | `TextField-v5` | 3 | 3 | 2.7s |  |
| 63 | `TextFormat-v7` | 38 | 40 | 8.5s |  |
| 64 | `TextFormat-v8` | 36 | 38 | 8.3s |  |
| 65 | `Transform-v8` | 7 | 11 | 5.8s |  |
| 66 | `XML-v5` | 10 | 79 | 33.6s |  |
| 67 | `XML-v6` | 3 | 98 | 16.2s |  |
| 68 | `XML-v7` | 3 | 98 | 15.8s |  |
| 69 | `XML-v8` | 24 | 116 | 5.5s |  |
| 70 | `XMLNode-v5` | 3 | 22 | 9.0s |  |
| 71 | `XMLNode-v6` | 3 | 22 | 9.0s |  |
| 72 | `XMLNode-v7` | 3 | 22 | 7.9s |  |
| 73 | `XMLNode-v8` | 3 | 22 | 2.5s |  |
| 74 | `ops-v5` | 7 | 9 | 25.6s |  |
| 75 | `ops-v6` | 7 | 11 | 8.7s |  |
| 76 | `ops-v7` | 7 | 11 | 9.3s |  |
| 77 | `ops-v8` | 7 | 11 | 2.1s |  |
| 78 | `setProperty-v5` | 49 | 49 | 3.2s |  |
| 79 | `setProperty-v6` | 49 | 49 | 3.3s |  |
| 80 | `setProperty-v7` | 49 | 49 | 3.0s |  |
| 81 | `setProperty-v8` | 49 | 49 | 2.1s |  |
| 82 | `toString_valueOf-v5` | 34 | 34 | 26.2s |  |
| 83 | `toString_valueOf-v6` | 5 | 5 | 6.7s |  |
| 84 | `toString_valueOf-v7` | 5 | 5 | 6.4s |  |
| 85 | `toString_valueOf-v8` | 5 | 5 | 2.6s |  |
| 86 | `with-v5` | 3 | 3 | 4.5s |  |
| 87 | `with-v6` | 6 | 9 | 5.8s |  |
| 88 | `with-v7` | 6 | 9 | 5.4s |  |
| 89 | `with-v8` | 6 | 9 | 2.8s |  |

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
