# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-22 21:18 UTC

**Git SHA**: `19ba533729`

**Run Duration**: 35m 4s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **141** (58.0%) |
| Ruffle-matched | 89 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (94.7%) |
| Failing | 13 |
| Total expected lines | 38791 |
| Matching lines | 30495 (78.6%) |
| Mismatched lines | 8296 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**141 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.0s |  |
| 2 | `Accessibility-v6` | 19 | 3.1s |  |
| 3 | `Accessibility-v7` | 19 | 2.8s |  |
| 4 | `Accessibility-v8` | 19 | 2.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.0s |  |
| 6 | `BitmapData-v5` | 7 | 3.0s |  |
| 7 | `BitmapData-v6` | 7 | 1.4s |  |
| 8 | `BitmapData-v7` | 7 | 2.6s |  |
| 9 | `Boolean-v5` | 38 | 3.6s |  |
| 10 | `Boolean-v6` | 38 | 3.1s |  |
| 11 | `Boolean-v7` | 38 | 21.5s |  |
| 12 | `Boolean-v8` | 38 | 2.0s |  |
| 13 | `Camera-v5` | 7 | 2.5s |  |
| 14 | `Color-v5` | 140 | 5.5s |  |
| 15 | `Color-v6` | 171 | 6.7s |  |
| 16 | `Color-v7` | 161 | 6.3s |  |
| 17 | `Color-v8` | 161 | 28.1s |  |
| 18 | `ColorTransform-v5` | 7 | 2.8s |  |
| 19 | `ColorTransform-v6` | 7 | 1.3s |  |
| 20 | `ColorTransform-v7` | 7 | 2.4s |  |
| 21 | `ColorTransform-v8` | 55 | 4.1s |  |
| 22 | `ContextMenu-v5` | 7 | 2.7s |  |
| 23 | `ContextMenu-v6` | 7 | 1.2s |  |
| 24 | `ContextMenu-v7` | 131 | 5.9s |  |
| 25 | `ContextMenu-v8` | 131 | 26.4s |  |
| 26 | `Error-v5` | 28 | 3.6s |  |
| 27 | `Error-v6` | 31 | 3.7s |  |
| 28 | `Error-v7` | 31 | 3.2s |  |
| 29 | `Error-v8` | 31 | 22.3s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.6s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.4s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.1s |  |
| 33 | `Function-v6` | 271 | 10.0s |  |
| 34 | `Function-v7` | 272 | 10.4s |  |
| 35 | `Function-v8` | 272 | 31.2s |  |
| 36 | `Global-v5` | 172 | 8.2s |  |
| 37 | `Global-v7` | 182 | 8.6s |  |
| 38 | `Global-v8` | 169 | 8.0s |  |
| 39 | `Instance-v5` | 52 | 3.8s |  |
| 40 | `Instance-v6` | 52 | 2.3s |  |
| 41 | `Instance-v7` | 52 | 3.5s |  |
| 42 | `Instance-v8` | 52 | 2.4s |  |
| 43 | `Key-v5` | 51 | 23.4s |  |
| 44 | `Key-v6` | 55 | 3.9s |  |
| 45 | `Key-v7` | 55 | 3.5s |  |
| 46 | `Key-v8` | 55 | 2.4s |  |
| 47 | `LoadVars-v5` | 8 | 2.9s |  |
| 48 | `LocalConnection-v5` | 7 | 22.9s |  |
| 49 | `LocalConnection-v6` | 58 | 4.2s |  |
| 50 | `LocalConnection-v7` | 58 | 3.9s |  |
| 51 | `LocalConnection-v8` | 58 | 2.5s |  |
| 52 | `Matrix-v5` | 7 | 20.3s |  |
| 53 | `Microphone-v5` | 6 | 2.6s |  |
| 54 | `Mouse-v5` | 13 | 23.3s |  |
| 55 | `Mouse-v6` | 21 | 3.2s |  |
| 56 | `Mouse-v7` | 21 | 2.9s |  |
| 57 | `Mouse-v8` | 21 | 2.4s |  |
| 58 | `MovieClipLoader-v5` | 6 | 23.6s |  |
| 59 | `MovieClipLoader-v6` | 6 | 1.4s |  |
| 60 | `NetConnection-v5` | 7 | 3.0s |  |
| 61 | `NetStream-v5` | 6 | 22.5s |  |
| 62 | `NetStream-v6` | 80 | 4.7s |  |
| 63 | `NetStream-v7` | 80 | 4.2s |  |
| 64 | `NetStream-v8` | 80 | 2.4s |  |
| 65 | `Number-v6` | 239 | 9.8s |  |
| 66 | `Number-v7` | 237 | 10.0s |  |
| 67 | `Number-v8` | 237 | 2.6s |  |
| 68 | `Point-v5` | 7 | 2.2s |  |
| 69 | `Point-v6` | 7 | 1.1s |  |
| 70 | `Point-v7` | 7 | 1.9s |  |
| 71 | `Point-v8` | 193 | 6.7s |  |
| 72 | `Random-v5` | 30 | 22.8s |  |
| 73 | `Random-v6` | 30 | 1.3s |  |
| 74 | `Random-v7` | 30 | 3.0s |  |
| 75 | `Random-v8` | 30 | 2.4s |  |
| 76 | `Rectangle-v5` | 7 | 2.9s |  |
| 77 | `Rectangle-v6` | 7 | 1.3s |  |
| 78 | `Rectangle-v7` | 7 | 2.5s |  |
| 79 | `Selection-v5` | 21 | 18.3s |  |
| 80 | `Sound-v6` | 121 | 5.4s |  |
| 81 | `Sound-v7` | 121 | 5.3s |  |
| 82 | `Sound-v8` | 121 | 2.4s |  |
| 83 | `Stage-v5` | 38 | 23.1s |  |
| 84 | `System-v5` | 67 | 36.2s |  |
| 85 | `System-v6` | 100 | 8.3s |  |
| 86 | `System-v7` | 101 | 7.1s |  |
| 87 | `System-v8` | 101 | 2.5s |  |
| 88 | `TextFieldHTML-v5` | 6 | 22.7s |  |
| 89 | `TextFieldHTML-v6` | 37 | 3.6s |  |
| 90 | `TextFieldHTML-v7` | 37 | 3.2s |  |
| 91 | `TextFieldHTML-v8` | 37 | 2.5s |  |
| 92 | `TextFormat-v5` | 128 | 6.2s |  |
| 93 | `TextFormat-v6` | 128 | 1.4s |  |
| 94 | `TextSnapshot-v5` | 7 | 19.0s |  |
| 95 | `TextSnapshot-v6` | 173 | 8.3s |  |
| 96 | `TextSnapshot-v7` | 173 | 7.9s |  |
| 97 | `TextSnapshot-v8` | 173 | 2.2s |  |
| 98 | `Transform-v5` | 7 | 2.6s |  |
| 99 | `Transform-v6` | 7 | 2.2s |  |
| 100 | `Transform-v7` | 7 | 2.2s |  |
| 101 | `Try-v5` | 20 | 19.2s |  |
| 102 | `Try-v6` | 20 | 1.2s |  |
| 103 | `Try-v7` | 20 | 2.8s |  |
| 104 | `Try-v8` | 20 | 2.0s |  |
| 105 | `Video-v5` | 7 | 2.9s |  |
| 106 | `Video-v6` | 85 | 4.0s |  |
| 107 | `Video-v7` | 85 | 3.7s |  |
| 108 | `Video-v8` | 85 | 2.0s |  |
| 109 | `XMLSocket-v5` | 35 | 25.0s |  |
| 110 | `XMLSocket-v6` | 35 | 3.8s |  |
| 111 | `XMLSocket-v7` | 35 | 3.5s |  |
| 112 | `XMLSocket-v8` | 35 | 2.7s |  |
| 113 | `argstest-v5` | 4 | 3.3s |  |
| 114 | `case-v5` | 39 | 3.5s |  |
| 115 | `case-v6` | 73 | 4.7s |  |
| 116 | `case-v7` | 67 | 4.4s |  |
| 117 | `case-v8` | 67 | 2.5s |  |
| 118 | `delete-v5` | 61 | 24.3s |  |
| 119 | `delete-v6` | 61 | 3.7s |  |
| 120 | `delete-v7` | 61 | 3.9s |  |
| 121 | `delete-v8` | 61 | 2.7s |  |
| 122 | `enumerate-v5` | 6 | 3.0s |  |
| 123 | `enumerate-v6` | 49 | 4.2s |  |
| 124 | `enumerate-v7` | 49 | 3.9s |  |
| 125 | `enumerate-v8` | 49 | 2.5s |  |
| 126 | `flash-v5` | 10 | 18.2s |  |
| 127 | `flash-v6` | 10 | 1.7s |  |
| 128 | `flash-v7` | 10 | 2.2s |  |
| 129 | `flash-v8` | 41 | 1.8s |  |
| 130 | `getvariable-v5` | 58 | 1.8s |  |
| 131 | `getvariable-v6` | 64 | 1.8s |  |
| 132 | `getvariable-v7` | 64 | 1.8s |  |
| 133 | `getvariable-v8` | 64 | 1.8s |  |
| 134 | `swap-v5` | 7 | 18.1s |  |
| 135 | `swap-v6` | 7 | 1.2s |  |
| 136 | `swap-v7` | 7 | 2.1s |  |
| 137 | `swap-v8` | 7 | 1.9s |  |
| 138 | `targetPath-v5` | 12 | 2.6s |  |
| 139 | `targetPath-v6` | 23 | 2.7s |  |
| 140 | `targetPath-v7` | 23 | 2.4s |  |
| 141 | `targetPath-v8` | 23 | 2.0s |  |

## Ruffle-Matched Tests

**89 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 26.4s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.6s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 25.7s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.8s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.6s |  |
| 8 | `BitmapData-v8` | 8 | 8 | 26.0s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.3s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.0s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.1s |  |
| 12 | `Date-v5` | 7 | 7 | 15.4s |  |
| 13 | `Date-v6` | 6 | 6 | 17.2s |  |
| 14 | `Date-v7` | 6 | 6 | 18.2s |  |
| 15 | `Date-v8` | 6 | 6 | 3.1s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.3s |  |
| 17 | `Function-v5` | 10 | 24 | 6.3s |  |
| 18 | `Global-v6` | 9 | 10 | 9.6s |  |
| 19 | `HitTest-v6` | 8 | 8 | 6.1s |  |
| 20 | `HitTest-v7` | 8 | 8 | 5.8s |  |
| 21 | `HitTest-v8` | 9 | 9 | 5.7s |  |
| 22 | `Inheritance-v5` | 1 | 17 | 25.2s |  |
| 23 | `Inheritance-v6` | 9 | 16 | 7.6s |  |
| 24 | `Inheritance-v7` | 5 | 10 | 7.8s |  |
| 25 | `Inheritance-v8` | 5 | 10 | 3.0s |  |
| 26 | `LoadVars-v6` | 6 | 8 | 6.6s |  |
| 27 | `LoadVars-v7` | 6 | 8 | 6.3s |  |
| 28 | `LoadVars-v8` | 6 | 8 | 3.3s |  |
| 29 | `Math-v5` | 5 | 5 | 15.3s |  |
| 30 | `Math-v6` | 5 | 5 | 1.6s |  |
| 31 | `Math-v7` | 5 | 5 | 15.7s |  |
| 32 | `Math-v8` | 5 | 5 | 2.8s |  |
| 33 | `Matrix-v6` | 29 | 71 | 7.5s |  |
| 34 | `Matrix-v7` | 28 | 70 | 7.5s |  |
| 35 | `Matrix-v8` | 28 | 70 | 2.4s |  |
| 36 | `Microphone-v6` | 31 | 31 | 4.0s |  |
| 37 | `Microphone-v7` | 31 | 31 | 3.7s |  |
| 38 | `Microphone-v8` | 31 | 31 | 2.3s |  |
| 39 | `MovieClip-v5` | 13 | 226 | 14.7s |  |
| 40 | `MovieClipLoader-v7` | 118 | 118 | 5.2s |  |
| 41 | `MovieClipLoader-v8` | 118 | 118 | 3.6s |  |
| 42 | `NetConnection-v6` | 4 | 49 | 6.3s |  |
| 43 | `NetConnection-v7` | 4 | 45 | 6.3s |  |
| 44 | `NetConnection-v8` | 4 | 45 | 2.7s |  |
| 45 | `Number-v5` | 8 | 12 | 10.1s |  |
| 46 | `Object-v5` | 3 | 4 | 21.7s |  |
| 47 | `Object-v6` | 8 | 22 | 11.0s |  |
| 48 | `Object-v7` | 8 | 13 | 11.4s |  |
| 49 | `Object-v8` | 8 | 13 | 2.4s |  |
| 50 | `Rectangle-v8` | 21 | 21 | 7.8s |  |
| 51 | `Selection-v6` | 7 | 13 | 5.4s |  |
| 52 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 53 | `Selection-v8` | 7 | 13 | 2.1s |  |
| 54 | `Sound-v5` | 14 | 16 | 5.2s |  |
| 55 | `Stage-v6` | 14 | 14 | 4.4s |  |
| 56 | `Stage-v7` | 14 | 14 | 4.0s |  |
| 57 | `Stage-v8` | 14 | 14 | 2.6s |  |
| 58 | `String-v5` | 18 | 21 | 17.7s |  |
| 59 | `String-v6` | 9 | 10 | 17.7s |  |
| 60 | `String-v7` | 9 | 10 | 18.1s |  |
| 61 | `String-v8` | 9 | 10 | 3.0s |  |
| 62 | `TextField-v5` | 3 | 3 | 2.8s |  |
| 63 | `TextFormat-v7` | 38 | 40 | 7.9s |  |
| 64 | `TextFormat-v8` | 36 | 38 | 7.8s |  |
| 65 | `Transform-v8` | 7 | 7 | 5.6s |  |
| 66 | `XML-v5` | 10 | 79 | 36.4s |  |
| 67 | `XML-v6` | 3 | 98 | 17.6s |  |
| 68 | `XML-v7` | 3 | 98 | 17.5s |  |
| 69 | `XML-v8` | 24 | 116 | 5.8s |  |
| 70 | `XMLNode-v5` | 3 | 22 | 10.1s |  |
| 71 | `XMLNode-v6` | 3 | 22 | 10.0s |  |
| 72 | `XMLNode-v7` | 3 | 22 | 8.8s |  |
| 73 | `XMLNode-v8` | 3 | 22 | 2.7s |  |
| 74 | `ops-v5` | 7 | 9 | 18.6s |  |
| 75 | `ops-v6` | 7 | 11 | 1.6s |  |
| 76 | `ops-v7` | 7 | 11 | 1.9s |  |
| 77 | `ops-v8` | 7 | 11 | 1.8s |  |
| 78 | `setProperty-v5` | 49 | 49 | 1.5s |  |
| 79 | `setProperty-v6` | 49 | 49 | 1.6s |  |
| 80 | `setProperty-v7` | 49 | 49 | 2.0s |  |
| 81 | `setProperty-v8` | 49 | 49 | 1.5s |  |
| 82 | `toString_valueOf-v5` | 34 | 34 | 28.4s |  |
| 83 | `toString_valueOf-v6` | 5 | 5 | 7.4s |  |
| 84 | `toString_valueOf-v7` | 5 | 5 | 6.9s |  |
| 85 | `toString_valueOf-v8` | 5 | 5 | 2.6s |  |
| 86 | `with-v5` | 3 | 3 | 4.7s |  |
| 87 | `with-v6` | 6 | 9 | 5.8s |  |
| 88 | `with-v7` | 6 | 9 | 5.5s |  |
| 89 | `with-v8` | 6 | 9 | 2.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 98.8% | 553 | 560 | 7 |  |
| 2 | `array-v6` | 97.4% | 627 | 644 | 17 |  |
| 3 | `array-v7` | 96.9% | 634 | 654 | 20 |  |
| 4 | `array-v8` | 96.9% | 634 | 654 | 20 |  |
| 5 | `MovieClip-v7` | 96.4% | 934 | 969 | 35 |  |
| 6 | `MovieClip-v6` | 96.3% | 901 | 936 | 35 |  |
| 7 | `MovieClip-v8` | 93.8% | 1020 | 1087 | 67 |  |
| 8 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 9 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 10 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |

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
| 1 | `array-v5` | 98.8% | 553/560 | 560 | 560 |  |
| 2 | `array-v6` | 97.4% | 627/644 | 644 | 644 |  |
| 3 | `array-v7` | 96.9% | 634/654 | 654 | 654 |  |
| 4 | `array-v8` | 96.9% | 634/654 | 654 | 654 |  |
| 5 | `MovieClip-v7` | 96.4% | 934/969 | 968 | 969 |  |
| 6 | `MovieClip-v6` | 96.3% | 901/936 | 935 | 936 |  |
| 7 | `MovieClip-v8` | 93.8% | 1020/1087 | 1086 | 1087 |  |
| 8 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 9 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 10 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 11 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 12 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 13 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
