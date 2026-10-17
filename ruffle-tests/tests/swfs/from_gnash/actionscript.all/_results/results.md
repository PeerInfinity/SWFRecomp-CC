# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-17 02:06 UTC

**Git SHA**: `9396522982`

**Run Duration**: 22m 26s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **144** (59.3%) |
| Ruffle-matched | 88 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **232** (95.5%) |
| Failing | 11 |
| Total expected lines | 38791 |
| Matching lines | 30606 (78.9%) |
| Mismatched lines | 8185 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 100.0% |

## Passing Tests

**144 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.7s |  |
| 2 | `Accessibility-v6` | 19 | 1.8s |  |
| 3 | `Accessibility-v7` | 19 | 1.5s |  |
| 4 | `Accessibility-v8` | 19 | 1.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.6s |  |
| 6 | `AsBroadcaster-v6` | 121 | 4.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.1s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.4s |  |
| 9 | `BitmapData-v5` | 7 | 1.7s |  |
| 10 | `BitmapData-v6` | 7 | 0.5s |  |
| 11 | `BitmapData-v7` | 7 | 1.4s |  |
| 12 | `Boolean-v5` | 38 | 2.2s |  |
| 13 | `Boolean-v6` | 38 | 1.6s |  |
| 14 | `Boolean-v7` | 38 | 23.6s |  |
| 15 | `Boolean-v8` | 38 | 1.6s |  |
| 16 | `Camera-v5` | 7 | 2.2s |  |
| 17 | `Color-v5` | 140 | 5.8s |  |
| 18 | `Color-v6` | 171 | 6.8s |  |
| 19 | `Color-v7` | 161 | 6.5s |  |
| 20 | `Color-v8` | 161 | 26.8s |  |
| 21 | `ColorTransform-v5` | 7 | 2.1s |  |
| 22 | `ColorTransform-v6` | 7 | 0.7s |  |
| 23 | `ColorTransform-v7` | 7 | 1.8s |  |
| 24 | `ColorTransform-v8` | 55 | 3.4s |  |
| 25 | `ContextMenu-v5` | 7 | 2.1s |  |
| 26 | `ContextMenu-v6` | 7 | 0.7s |  |
| 27 | `ContextMenu-v7` | 131 | 5.0s |  |
| 28 | `ContextMenu-v8` | 131 | 22.4s |  |
| 29 | `Error-v5` | 28 | 2.3s |  |
| 30 | `Error-v6` | 31 | 2.2s |  |
| 31 | `Error-v7` | 31 | 1.9s |  |
| 32 | `Error-v8` | 31 | 2.5s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.0s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.9s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.5s |  |
| 36 | `Function-v6` | 271 | 9.3s |  |
| 37 | `Function-v7` | 272 | 9.5s |  |
| 38 | `Function-v8` | 272 | 9.9s |  |
| 39 | `Global-v5` | 172 | 7.0s |  |
| 40 | `Global-v7` | 182 | 7.3s |  |
| 41 | `Global-v8` | 169 | 6.7s |  |
| 42 | `Instance-v5` | 52 | 3.0s |  |
| 43 | `Instance-v6` | 52 | 1.6s |  |
| 44 | `Instance-v7` | 52 | 2.6s |  |
| 45 | `Instance-v8` | 52 | 1.6s |  |
| 46 | `Key-v5` | 51 | 3.1s |  |
| 47 | `Key-v6` | 55 | 3.1s |  |
| 48 | `Key-v7` | 55 | 2.8s |  |
| 49 | `Key-v8` | 55 | 1.6s |  |
| 50 | `LoadVars-v5` | 8 | 2.1s |  |
| 51 | `LocalConnection-v5` | 7 | 2.1s |  |
| 52 | `LocalConnection-v6` | 58 | 3.2s |  |
| 53 | `LocalConnection-v7` | 58 | 3.0s |  |
| 54 | `LocalConnection-v8` | 58 | 1.6s |  |
| 55 | `Matrix-v5` | 7 | 23.0s |  |
| 56 | `Microphone-v5` | 6 | 2.1s |  |
| 57 | `Mouse-v5` | 13 | 2.0s |  |
| 58 | `Mouse-v6` | 21 | 2.1s |  |
| 59 | `Mouse-v7` | 21 | 1.8s |  |
| 60 | `Mouse-v8` | 21 | 1.3s |  |
| 61 | `MovieClipLoader-v5` | 6 | 1.6s |  |
| 62 | `MovieClipLoader-v6` | 6 | 0.4s |  |
| 63 | `NetConnection-v5` | 7 | 1.4s |  |
| 64 | `NetStream-v5` | 6 | 1.7s |  |
| 65 | `NetStream-v6` | 80 | 3.1s |  |
| 66 | `NetStream-v7` | 80 | 2.8s |  |
| 67 | `NetStream-v8` | 80 | 1.3s |  |
| 68 | `Number-v6` | 239 | 8.4s |  |
| 69 | `Number-v7` | 237 | 8.3s |  |
| 70 | `Number-v8` | 237 | 1.6s |  |
| 71 | `Point-v5` | 7 | 2.0s |  |
| 72 | `Point-v6` | 7 | 0.6s |  |
| 73 | `Point-v7` | 7 | 1.7s |  |
| 74 | `Point-v8` | 193 | 7.8s |  |
| 75 | `Random-v5` | 30 | 2.5s |  |
| 76 | `Random-v6` | 30 | 0.7s |  |
| 77 | `Random-v7` | 30 | 2.2s |  |
| 78 | `Random-v8` | 30 | 1.5s |  |
| 79 | `Rectangle-v5` | 7 | 2.1s |  |
| 80 | `Rectangle-v6` | 7 | 0.7s |  |
| 81 | `Rectangle-v7` | 7 | 1.7s |  |
| 82 | `Selection-v5` | 21 | 1.6s |  |
| 83 | `Sound-v6` | 121 | 3.4s |  |
| 84 | `Sound-v7` | 121 | 3.2s |  |
| 85 | `Sound-v8` | 121 | 1.3s |  |
| 86 | `Stage-v5` | 38 | 1.7s |  |
| 87 | `System-v5` | 67 | 2.3s |  |
| 88 | `System-v6` | 100 | 2.9s |  |
| 89 | `System-v7` | 101 | 3.1s |  |
| 90 | `System-v8` | 101 | 1.1s |  |
| 91 | `TextFieldHTML-v5` | 6 | 2.1s |  |
| 92 | `TextFieldHTML-v6` | 37 | 2.8s |  |
| 93 | `TextFieldHTML-v7` | 37 | 2.4s |  |
| 94 | `TextFieldHTML-v8` | 37 | 1.6s |  |
| 95 | `TextFormat-v5` | 128 | 5.4s |  |
| 96 | `TextFormat-v6` | 128 | 0.8s |  |
| 97 | `TextSnapshot-v5` | 7 | 22.1s |  |
| 98 | `TextSnapshot-v6` | 173 | 8.2s |  |
| 99 | `TextSnapshot-v7` | 173 | 7.9s |  |
| 100 | `TextSnapshot-v8` | 173 | 1.7s |  |
| 101 | `Transform-v5` | 7 | 2.1s |  |
| 102 | `Transform-v6` | 7 | 1.6s |  |
| 103 | `Transform-v7` | 7 | 1.8s |  |
| 104 | `Try-v5` | 20 | 2.0s |  |
| 105 | `Try-v6` | 20 | 0.5s |  |
| 106 | `Try-v7` | 20 | 1.7s |  |
| 107 | `Try-v8` | 20 | 1.2s |  |
| 108 | `Video-v5` | 7 | 1.5s |  |
| 109 | `Video-v6` | 85 | 2.6s |  |
| 110 | `Video-v7` | 85 | 2.4s |  |
| 111 | `Video-v8` | 85 | 1.4s |  |
| 112 | `XMLSocket-v5` | 35 | 14.2s |  |
| 113 | `XMLSocket-v6` | 35 | 1.7s |  |
| 114 | `XMLSocket-v7` | 35 | 1.6s |  |
| 115 | `XMLSocket-v8` | 35 | 1.1s |  |
| 116 | `argstest-v5` | 4 | 1.4s |  |
| 117 | `case-v5` | 39 | 2.9s |  |
| 118 | `case-v6` | 73 | 3.9s |  |
| 119 | `case-v7` | 67 | 3.7s |  |
| 120 | `case-v8` | 67 | 1.7s |  |
| 121 | `delete-v5` | 61 | 2.1s |  |
| 122 | `delete-v6` | 61 | 1.6s |  |
| 123 | `delete-v7` | 61 | 1.8s |  |
| 124 | `delete-v8` | 61 | 1.2s |  |
| 125 | `enumerate-v5` | 6 | 1.4s |  |
| 126 | `enumerate-v6` | 49 | 2.0s |  |
| 127 | `enumerate-v7` | 49 | 2.0s |  |
| 128 | `enumerate-v8` | 49 | 1.1s |  |
| 129 | `flash-v5` | 10 | 18.5s |  |
| 130 | `flash-v6` | 10 | 1.7s |  |
| 131 | `flash-v7` | 10 | 1.6s |  |
| 132 | `flash-v8` | 41 | 2.3s |  |
| 133 | `getvariable-v5` | 58 | 2.6s |  |
| 134 | `getvariable-v6` | 64 | 2.8s |  |
| 135 | `getvariable-v7` | 64 | 2.8s |  |
| 136 | `getvariable-v8` | 64 | 1.2s |  |
| 137 | `swap-v5` | 7 | 2.1s |  |
| 138 | `swap-v6` | 7 | 0.7s |  |
| 139 | `swap-v7` | 7 | 1.8s |  |
| 140 | `swap-v8` | 7 | 1.6s |  |
| 141 | `targetPath-v5` | 12 | 2.2s |  |
| 142 | `targetPath-v6` | 23 | 2.4s |  |
| 143 | `targetPath-v7` | 23 | 2.1s |  |
| 144 | `targetPath-v8` | 23 | 1.6s |  |

## Ruffle-Matched Tests

**88 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 4.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.1s |  |
| 3 | `ASnative-v7` | 40 | 40 | 3.9s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.2s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 20.2s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.4s |  |
| 7 | `Camera-v7` | 57 | 57 | 4.0s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.6s |  |
| 9 | `Date-v5` | 7 | 7 | 12.6s |  |
| 10 | `Date-v6` | 6 | 6 | 14.0s |  |
| 11 | `Date-v7` | 6 | 6 | 14.5s |  |
| 12 | `Date-v8` | 6 | 6 | 1.6s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 4.9s |  |
| 14 | `Function-v5` | 10 | 25 | 5.7s |  |
| 15 | `Global-v6` | 9 | 10 | 8.4s |  |
| 16 | `HitTest-v6` | 8 | 8 | 5.0s |  |
| 17 | `HitTest-v7` | 8 | 8 | 4.6s |  |
| 18 | `HitTest-v8` | 9 | 9 | 4.5s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 24.7s |  |
| 20 | `Inheritance-v6` | 9 | 16 | 7.0s |  |
| 21 | `Inheritance-v7` | 5 | 10 | 7.2s |  |
| 22 | `Inheritance-v8` | 5 | 10 | 2.2s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 5.8s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 5.5s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 2.5s |  |
| 26 | `Math-v5` | 5 | 5 | 14.1s |  |
| 27 | `Math-v6` | 5 | 5 | 0.9s |  |
| 28 | `Math-v7` | 5 | 5 | 14.5s |  |
| 29 | `Math-v8` | 5 | 5 | 1.9s |  |
| 30 | `Microphone-v6` | 31 | 31 | 3.8s |  |
| 31 | `Microphone-v7` | 31 | 31 | 3.5s |  |
| 32 | `Microphone-v8` | 31 | 31 | 1.6s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 13.5s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 48.0s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 52.0s |  |
| 36 | `MovieClipLoader-v7` | 118 | 118 | 2.7s |  |
| 37 | `MovieClipLoader-v8` | 118 | 118 | 1.8s |  |
| 38 | `NetConnection-v6` | 4 | 49 | 3.7s |  |
| 39 | `NetConnection-v7` | 4 | 45 | 3.7s |  |
| 40 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 41 | `Number-v5` | 8 | 12 | 8.2s |  |
| 42 | `Object-v5` | 3 | 4 | 5.7s |  |
| 43 | `Object-v6` | 8 | 22 | 12.4s |  |
| 44 | `Object-v7` | 8 | 13 | 12.6s |  |
| 45 | `Object-v8` | 8 | 13 | 2.3s |  |
| 46 | `Selection-v6` | 7 | 13 | 3.4s |  |
| 47 | `Selection-v7` | 7 | 13 | 3.1s |  |
| 48 | `Selection-v8` | 7 | 13 | 1.0s |  |
| 49 | `Sound-v5` | 14 | 16 | 3.3s |  |
| 50 | `Stage-v6` | 14 | 14 | 2.0s |  |
| 51 | `Stage-v7` | 14 | 14 | 1.7s |  |
| 52 | `Stage-v8` | 14 | 14 | 1.1s |  |
| 53 | `String-v5` | 18 | 21 | 11.0s |  |
| 54 | `String-v6` | 9 | 10 | 11.4s |  |
| 55 | `String-v7` | 9 | 10 | 11.2s |  |
| 56 | `String-v8` | 9 | 10 | 1.3s |  |
| 57 | `TextField-v5` | 3 | 3 | 1.4s |  |
| 58 | `TextFormat-v7` | 38 | 40 | 7.1s |  |
| 59 | `TextFormat-v8` | 36 | 38 | 7.2s |  |
| 60 | `Transform-v8` | 7 | 7 | 5.3s |  |
| 61 | `XML-v5` | 10 | 79 | 10.4s |  |
| 62 | `XML-v6` | 3 | 98 | 11.8s |  |
| 63 | `XML-v7` | 3 | 98 | 11.4s |  |
| 64 | `XML-v8` | 24 | 116 | 3.6s |  |
| 65 | `XMLNode-v5` | 3 | 22 | 6.1s |  |
| 66 | `XMLNode-v6` | 3 | 22 | 6.1s |  |
| 67 | `XMLNode-v7` | 3 | 22 | 5.3s |  |
| 68 | `XMLNode-v8` | 3 | 22 | 1.4s |  |
| 69 | `array-v5` | 5 | 17 | 29.3s |  |
| 70 | `array-v6` | 6 | 25 | 33.6s |  |
| 71 | `array-v7` | 5 | 23 | 34.3s |  |
| 72 | `array-v8` | 5 | 23 | 3.5s |  |
| 73 | `ops-v5` | 7 | 9 | 20.4s |  |
| 74 | `ops-v6` | 7 | 11 | 6.9s |  |
| 75 | `ops-v7` | 7 | 11 | 7.4s |  |
| 76 | `ops-v8` | 7 | 11 | 1.3s |  |
| 77 | `setProperty-v5` | 49 | 49 | 2.2s |  |
| 78 | `setProperty-v6` | 49 | 49 | 2.2s |  |
| 79 | `setProperty-v7` | 49 | 49 | 1.9s |  |
| 80 | `setProperty-v8` | 49 | 49 | 1.4s |  |
| 81 | `toString_valueOf-v5` | 34 | 34 | 3.6s |  |
| 82 | `toString_valueOf-v6` | 5 | 5 | 3.9s |  |
| 83 | `toString_valueOf-v7` | 5 | 5 | 3.8s |  |
| 84 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 85 | `with-v5` | 3 | 3 | 2.3s |  |
| 86 | `with-v6` | 6 | 9 | 3.2s |  |
| 87 | `with-v7` | 6 | 9 | 3.1s |  |
| 88 | `with-v8` | 6 | 9 | 1.2s |  |

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
