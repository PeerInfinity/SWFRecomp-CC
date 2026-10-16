# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-11 08:51 UTC

**Git SHA**: `8b69f982f7`

**Run Duration**: 17m 49s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **141** (58.0%) |
| Ruffle-matched | 91 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **232** (95.5%) |
| Failing | 11 |
| Total expected lines | 38791 |
| Matching lines | 30558 (78.8%) |
| Mismatched lines | 8233 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 100.0% |

## Passing Tests

**141 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.3s |  |
| 2 | `Accessibility-v6` | 19 | 2.3s |  |
| 3 | `Accessibility-v7` | 19 | 2.0s |  |
| 4 | `Accessibility-v8` | 19 | 1.6s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.2s |  |
| 6 | `BitmapData-v5` | 7 | 1.7s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.5s |  |
| 9 | `Boolean-v5` | 38 | 2.2s |  |
| 10 | `Boolean-v6` | 38 | 1.7s |  |
| 11 | `Boolean-v7` | 38 | 2.8s |  |
| 12 | `Boolean-v8` | 38 | 1.6s |  |
| 13 | `Camera-v5` | 7 | 2.1s |  |
| 14 | `Color-v5` | 140 | 6.2s |  |
| 15 | `Color-v6` | 171 | 7.6s |  |
| 16 | `Color-v7` | 161 | 6.8s |  |
| 17 | `Color-v8` | 161 | 5.8s |  |
| 18 | `ColorTransform-v5` | 7 | 1.7s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.5s |  |
| 21 | `ColorTransform-v8` | 55 | 3.0s |  |
| 22 | `ContextMenu-v5` | 7 | 2.0s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 4.4s |  |
| 25 | `ContextMenu-v8` | 131 | 4.8s |  |
| 26 | `Error-v5` | 28 | 2.3s |  |
| 27 | `Error-v6` | 31 | 2.4s |  |
| 28 | `Error-v7` | 31 | 2.0s |  |
| 29 | `Error-v8` | 31 | 1.6s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.3s |  |
| 31 | `ExternalInterface-v6` | 55 | 1.9s |  |
| 32 | `ExternalInterface-v7` | 55 | 1.7s |  |
| 33 | `Function-v6` | 271 | 7.0s |  |
| 34 | `Function-v7` | 272 | 6.7s |  |
| 35 | `Function-v8` | 272 | 9.8s |  |
| 36 | `Global-v5` | 172 | 7.2s |  |
| 37 | `Global-v7` | 182 | 7.6s |  |
| 38 | `Global-v8` | 169 | 6.9s |  |
| 39 | `Instance-v5` | 52 | 2.7s |  |
| 40 | `Instance-v6` | 52 | 1.5s |  |
| 41 | `Instance-v7` | 52 | 2.4s |  |
| 42 | `Instance-v8` | 52 | 1.4s |  |
| 43 | `Key-v5` | 51 | 2.9s |  |
| 44 | `Key-v6` | 55 | 2.9s |  |
| 45 | `Key-v7` | 55 | 2.6s |  |
| 46 | `Key-v8` | 55 | 1.6s |  |
| 47 | `LoadVars-v5` | 8 | 2.1s |  |
| 48 | `LocalConnection-v5` | 7 | 1.8s |  |
| 49 | `LocalConnection-v6` | 58 | 2.8s |  |
| 50 | `LocalConnection-v7` | 58 | 2.5s |  |
| 51 | `LocalConnection-v8` | 58 | 1.4s |  |
| 52 | `Matrix-v5` | 7 | 2.1s |  |
| 53 | `Microphone-v5` | 6 | 2.1s |  |
| 54 | `Mouse-v5` | 13 | 0.2s |  |
| 55 | `Mouse-v6` | 21 | 0.2s |  |
| 56 | `Mouse-v7` | 21 | 0.2s |  |
| 57 | `Mouse-v8` | 21 | 0.2s |  |
| 58 | `MovieClipLoader-v5` | 6 | 1.8s |  |
| 59 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 60 | `NetConnection-v5` | 7 | 1.8s |  |
| 61 | `NetStream-v5` | 6 | 2.1s |  |
| 62 | `NetStream-v6` | 80 | 3.7s |  |
| 63 | `NetStream-v7` | 80 | 3.4s |  |
| 64 | `NetStream-v8` | 80 | 1.6s |  |
| 65 | `Number-v6` | 239 | 9.0s |  |
| 66 | `Number-v7` | 237 | 8.9s |  |
| 67 | `Number-v8` | 237 | 1.8s |  |
| 68 | `Point-v5` | 7 | 1.6s |  |
| 69 | `Point-v6` | 7 | 0.5s |  |
| 70 | `Point-v7` | 7 | 1.4s |  |
| 71 | `Point-v8` | 193 | 6.8s |  |
| 72 | `Random-v5` | 30 | 2.7s |  |
| 73 | `Random-v6` | 30 | 0.7s |  |
| 74 | `Random-v7` | 30 | 2.3s |  |
| 75 | `Random-v8` | 30 | 1.6s |  |
| 76 | `Rectangle-v5` | 7 | 2.2s |  |
| 77 | `Rectangle-v6` | 7 | 0.7s |  |
| 78 | `Rectangle-v7` | 7 | 1.8s |  |
| 79 | `Selection-v5` | 21 | 1.5s |  |
| 80 | `Sound-v6` | 121 | 3.7s |  |
| 81 | `Sound-v7` | 121 | 3.6s |  |
| 82 | `Sound-v8` | 121 | 1.4s |  |
| 83 | `Stage-v5` | 38 | 2.8s |  |
| 84 | `System-v5` | 67 | 3.6s |  |
| 85 | `System-v6` | 100 | 4.4s |  |
| 86 | `System-v7` | 101 | 4.6s |  |
| 87 | `System-v8` | 101 | 1.6s |  |
| 88 | `TextFieldHTML-v5` | 6 | 2.2s |  |
| 89 | `TextFieldHTML-v6` | 37 | 2.9s |  |
| 90 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 91 | `TextFieldHTML-v8` | 37 | 1.6s |  |
| 92 | `TextFormat-v5` | 128 | 5.5s |  |
| 93 | `TextFormat-v6` | 128 | 0.8s |  |
| 94 | `TextSnapshot-v5` | 7 | 2.1s |  |
| 95 | `TextSnapshot-v6` | 173 | 8.1s |  |
| 96 | `TextSnapshot-v7` | 173 | 7.6s |  |
| 97 | `TextSnapshot-v8` | 173 | 1.7s |  |
| 98 | `Transform-v5` | 7 | 2.1s |  |
| 99 | `Transform-v6` | 7 | 1.6s |  |
| 100 | `Transform-v7` | 7 | 1.8s |  |
| 101 | `Try-v5` | 20 | 1.9s |  |
| 102 | `Try-v6` | 20 | 0.5s |  |
| 103 | `Try-v7` | 20 | 1.7s |  |
| 104 | `Try-v8` | 20 | 1.1s |  |
| 105 | `Video-v5` | 7 | 1.5s |  |
| 106 | `Video-v6` | 85 | 2.5s |  |
| 107 | `Video-v7` | 85 | 2.3s |  |
| 108 | `Video-v8` | 85 | 1.1s |  |
| 109 | `XMLSocket-v5` | 35 | 2.9s |  |
| 110 | `XMLSocket-v6` | 35 | 2.8s |  |
| 111 | `XMLSocket-v7` | 35 | 2.5s |  |
| 112 | `XMLSocket-v8` | 35 | 1.8s |  |
| 113 | `argstest-v5` | 4 | 2.3s |  |
| 114 | `case-v5` | 39 | 2.2s |  |
| 115 | `case-v6` | 73 | 2.9s |  |
| 116 | `case-v7` | 67 | 2.9s |  |
| 117 | `case-v8` | 67 | 1.3s |  |
| 118 | `delete-v5` | 61 | 3.1s |  |
| 119 | `delete-v6` | 61 | 2.6s |  |
| 120 | `delete-v7` | 61 | 2.9s |  |
| 121 | `delete-v8` | 61 | 1.7s |  |
| 122 | `enumerate-v5` | 6 | 2.1s |  |
| 123 | `enumerate-v6` | 49 | 3.3s |  |
| 124 | `enumerate-v7` | 49 | 2.9s |  |
| 125 | `enumerate-v8` | 49 | 1.6s |  |
| 126 | `flash-v5` | 10 | 1.4s |  |
| 127 | `flash-v6` | 10 | 1.4s |  |
| 128 | `flash-v7` | 10 | 1.1s |  |
| 129 | `flash-v8` | 41 | 1.9s |  |
| 130 | `getvariable-v5` | 58 | 2.3s |  |
| 131 | `getvariable-v6` | 64 | 2.4s |  |
| 132 | `getvariable-v7` | 64 | 2.5s |  |
| 133 | `getvariable-v8` | 64 | 1.0s |  |
| 134 | `swap-v5` | 7 | 2.2s |  |
| 135 | `swap-v6` | 7 | 0.7s |  |
| 136 | `swap-v7` | 7 | 1.8s |  |
| 137 | `swap-v8` | 7 | 1.6s |  |
| 138 | `targetPath-v5` | 12 | 2.2s |  |
| 139 | `targetPath-v6` | 23 | 2.5s |  |
| 140 | `targetPath-v7` | 23 | 2.0s |  |
| 141 | `targetPath-v8` | 23 | 1.6s |  |

## Ruffle-Matched Tests

**91 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 5.7s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.5s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.7s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 4.3s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.1s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.4s |  |
| 8 | `BitmapData-v8` | 8 | 8 | 21.9s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.4s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.0s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.7s |  |
| 12 | `Date-v5` | 7 | 7 | 12.7s |  |
| 13 | `Date-v6` | 6 | 6 | 13.8s |  |
| 14 | `Date-v7` | 6 | 6 | 14.2s |  |
| 15 | `Date-v8` | 6 | 6 | 1.8s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 3.4s |  |
| 17 | `Function-v5` | 10 | 24 | 4.0s |  |
| 18 | `Global-v6` | 9 | 10 | 8.5s |  |
| 19 | `HitTest-v6` | 8 | 8 | 5.1s |  |
| 20 | `HitTest-v7` | 8 | 8 | 4.8s |  |
| 21 | `HitTest-v8` | 9 | 9 | 4.6s |  |
| 22 | `Inheritance-v5` | 1 | 17 | 4.5s |  |
| 23 | `Inheritance-v6` | 9 | 16 | 6.4s |  |
| 24 | `Inheritance-v7` | 5 | 10 | 6.5s |  |
| 25 | `Inheritance-v8` | 5 | 10 | 2.0s |  |
| 26 | `LoadVars-v6` | 6 | 8 | 5.5s |  |
| 27 | `LoadVars-v7` | 6 | 8 | 5.2s |  |
| 28 | `LoadVars-v8` | 6 | 8 | 2.4s |  |
| 29 | `Math-v5` | 5 | 5 | 12.7s |  |
| 30 | `Math-v6` | 5 | 5 | 0.7s |  |
| 31 | `Math-v7` | 5 | 5 | 12.6s |  |
| 32 | `Math-v8` | 5 | 5 | 1.5s |  |
| 33 | `Microphone-v6` | 31 | 31 | 3.6s |  |
| 34 | `Microphone-v7` | 31 | 31 | 3.2s |  |
| 35 | `Microphone-v8` | 31 | 31 | 1.6s |  |
| 36 | `MovieClip-v5` | 11 | 226 | 0.4s |  |
| 37 | `MovieClip-v6` | 20 | 60 | 1.4s |  |
| 38 | `MovieClip-v7` | 20 | 64 | 1.5s |  |
| 39 | `MovieClipLoader-v7` | 118 | 118 | 3.5s |  |
| 40 | `MovieClipLoader-v8` | 118 | 118 | 2.2s |  |
| 41 | `NetConnection-v6` | 4 | 49 | 4.7s |  |
| 42 | `NetConnection-v7` | 4 | 45 | 4.8s |  |
| 43 | `NetConnection-v8` | 4 | 45 | 1.5s |  |
| 44 | `Number-v5` | 8 | 12 | 9.2s |  |
| 45 | `Object-v5` | 3 | 4 | 4.8s |  |
| 46 | `Object-v6` | 8 | 22 | 10.7s |  |
| 47 | `Object-v7` | 8 | 13 | 10.9s |  |
| 48 | `Object-v8` | 8 | 13 | 1.9s |  |
| 49 | `Selection-v6` | 7 | 13 | 3.9s |  |
| 50 | `Selection-v7` | 7 | 13 | 3.6s |  |
| 51 | `Selection-v8` | 7 | 13 | 1.1s |  |
| 52 | `Sound-v5` | 14 | 16 | 3.5s |  |
| 53 | `Stage-v6` | 14 | 14 | 3.4s |  |
| 54 | `Stage-v7` | 14 | 14 | 3.1s |  |
| 55 | `Stage-v8` | 14 | 14 | 1.8s |  |
| 56 | `String-v5` | 18 | 21 | 16.5s |  |
| 57 | `String-v6` | 9 | 10 | 17.2s |  |
| 58 | `String-v7` | 9 | 10 | 17.1s |  |
| 59 | `String-v8` | 9 | 10 | 2.1s |  |
| 60 | `TextField-v5` | 3 | 3 | 2.3s |  |
| 61 | `TextFormat-v7` | 38 | 40 | 7.2s |  |
| 62 | `TextFormat-v8` | 36 | 38 | 7.2s |  |
| 63 | `Transform-v8` | 7 | 7 | 5.3s |  |
| 64 | `XML-v5` | 10 | 79 | 14.0s |  |
| 65 | `XML-v6` | 3 | 98 | 15.7s |  |
| 66 | `XML-v7` | 3 | 98 | 15.5s |  |
| 67 | `XML-v8` | 24 | 116 | 4.8s |  |
| 68 | `XMLNode-v5` | 3 | 22 | 8.6s |  |
| 69 | `XMLNode-v6` | 3 | 22 | 8.6s |  |
| 70 | `XMLNode-v7` | 3 | 22 | 7.5s |  |
| 71 | `XMLNode-v8` | 3 | 22 | 1.8s |  |
| 72 | `array-v5` | 5 | 17 | 24.1s |  |
| 73 | `array-v6` | 15 | 34 | 27.3s |  |
| 74 | `array-v7` | 14 | 32 | 28.3s |  |
| 75 | `array-v8` | 14 | 32 | 2.7s |  |
| 76 | `ops-v5` | 7 | 9 | 8.3s |  |
| 77 | `ops-v6` | 7 | 11 | 7.7s |  |
| 78 | `ops-v7` | 7 | 11 | 8.5s |  |
| 79 | `ops-v8` | 7 | 11 | 1.4s |  |
| 80 | `setProperty-v5` | 49 | 49 | 2.6s |  |
| 81 | `setProperty-v6` | 49 | 49 | 2.5s |  |
| 82 | `setProperty-v7` | 49 | 49 | 2.3s |  |
| 83 | `setProperty-v8` | 49 | 49 | 1.5s |  |
| 84 | `toString_valueOf-v5` | 34 | 34 | 5.1s |  |
| 85 | `toString_valueOf-v6` | 5 | 5 | 5.5s |  |
| 86 | `toString_valueOf-v7` | 5 | 5 | 5.2s |  |
| 87 | `toString_valueOf-v8` | 5 | 5 | 1.7s |  |
| 88 | `with-v5` | 3 | 3 | 3.5s |  |
| 89 | `with-v6` | 6 | 9 | 4.7s |  |
| 90 | `with-v7` | 6 | 9 | 4.4s |  |
| 91 | `with-v8` | 6 | 9 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**8 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `MovieClip-v8` | 95.2% | 1035 | 1087 | 52 |  |
| 2 | `Rectangle-v8` | 87.3% | 145 | 166 | 21 |  |
| 3 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 4 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 5 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |
| 6 | `Matrix-v7` | 83.3% | 140 | 168 | 28 |  |
| 7 | `Matrix-v8` | 83.3% | 140 | 168 | 28 |  |
| 8 | `Matrix-v6` | 82.7% | 139 | 168 | 29 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**11 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `MovieClip-v8` | 95.2% | 1035/1087 | 1087 | 1087 |  |
| 2 | `Rectangle-v8` | 87.3% | 145/166 | 166 | 166 |  |
| 3 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 4 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 5 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 6 | `Matrix-v7` | 83.3% | 140/168 | 168 | 168 |  |
| 7 | `Matrix-v8` | 83.3% | 140/168 | 168 | 168 |  |
| 8 | `Matrix-v6` | 82.7% | 139/168 | 168 | 168 |  |
| 9 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 10 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 11 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
