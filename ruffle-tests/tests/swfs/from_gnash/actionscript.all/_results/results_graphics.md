# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-17 04:05 UTC

**Git SHA**: `38cf9b1a0a`

**Run Duration**: 29m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **148** (60.9%) |
| Ruffle-matched | 88 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **236** (97.1%) |
| Failing | 7 |
| Total expected lines | 38791 |
| Matching lines | 30712 (79.2%) |
| Mismatched lines | 8079 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 7 | 100.0% |

## Passing Tests

**148 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.1s |  |
| 2 | `Accessibility-v6` | 19 | 3.3s |  |
| 3 | `Accessibility-v7` | 19 | 2.9s |  |
| 4 | `Accessibility-v8` | 19 | 2.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.1s |  |
| 6 | `AsBroadcaster-v6` | 121 | 6.0s |  |
| 7 | `AsBroadcaster-v7` | 121 | 5.6s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.5s |  |
| 9 | `BitmapData-v5` | 7 | 2.9s |  |
| 10 | `BitmapData-v6` | 7 | 1.3s |  |
| 11 | `BitmapData-v7` | 7 | 2.5s |  |
| 12 | `Boolean-v5` | 38 | 3.5s |  |
| 13 | `Boolean-v6` | 38 | 2.9s |  |
| 14 | `Boolean-v7` | 38 | 18.7s |  |
| 15 | `Boolean-v8` | 38 | 1.9s |  |
| 16 | `Camera-v5` | 7 | 2.4s |  |
| 17 | `Color-v5` | 140 | 5.3s |  |
| 18 | `Color-v6` | 171 | 6.3s |  |
| 19 | `Color-v7` | 161 | 6.0s |  |
| 20 | `Color-v8` | 161 | 7.5s |  |
| 21 | `ColorTransform-v5` | 7 | 3.1s |  |
| 22 | `ColorTransform-v6` | 7 | 1.4s |  |
| 23 | `ColorTransform-v7` | 7 | 2.7s |  |
| 24 | `ColorTransform-v8` | 55 | 4.5s |  |
| 25 | `ContextMenu-v5` | 7 | 3.1s |  |
| 26 | `ContextMenu-v6` | 7 | 1.4s |  |
| 27 | `ContextMenu-v7` | 131 | 6.2s |  |
| 28 | `ContextMenu-v8` | 131 | 5.8s |  |
| 29 | `Error-v5` | 28 | 3.3s |  |
| 30 | `Error-v6` | 31 | 3.4s |  |
| 31 | `Error-v7` | 31 | 3.0s |  |
| 32 | `Error-v8` | 31 | 3.5s |  |
| 33 | `ExternalInterface-v5` | 7 | 3.1s |  |
| 34 | `ExternalInterface-v6` | 55 | 4.0s |  |
| 35 | `ExternalInterface-v7` | 55 | 3.6s |  |
| 36 | `Function-v6` | 271 | 11.0s |  |
| 37 | `Function-v7` | 272 | 11.3s |  |
| 38 | `Function-v8` | 272 | 29.8s |  |
| 39 | `Global-v5` | 172 | 7.6s |  |
| 40 | `Global-v7` | 182 | 7.9s |  |
| 41 | `Global-v8` | 169 | 7.3s |  |
| 42 | `Instance-v5` | 52 | 3.9s |  |
| 43 | `Instance-v6` | 52 | 2.3s |  |
| 44 | `Instance-v7` | 52 | 3.6s |  |
| 45 | `Instance-v8` | 52 | 2.5s |  |
| 46 | `Key-v5` | 51 | 24.3s |  |
| 47 | `Key-v6` | 55 | 3.6s |  |
| 48 | `Key-v7` | 55 | 3.2s |  |
| 49 | `Key-v8` | 55 | 2.0s |  |
| 50 | `LoadVars-v5` | 8 | 2.6s |  |
| 51 | `LocalConnection-v5` | 7 | 2.1s |  |
| 52 | `LocalConnection-v6` | 58 | 2.9s |  |
| 53 | `LocalConnection-v7` | 58 | 2.7s |  |
| 54 | `LocalConnection-v8` | 58 | 1.7s |  |
| 55 | `Matrix-v5` | 7 | 1.9s |  |
| 56 | `Matrix-v6` | 168 | 5.9s |  |
| 57 | `Matrix-v7` | 168 | 6.1s |  |
| 58 | `Matrix-v8` | 168 | 1.7s |  |
| 59 | `Microphone-v5` | 6 | 2.3s |  |
| 60 | `Mouse-v5` | 13 | 22.9s |  |
| 61 | `Mouse-v6` | 21 | 3.2s |  |
| 62 | `Mouse-v7` | 21 | 2.8s |  |
| 63 | `Mouse-v8` | 21 | 2.4s |  |
| 64 | `MovieClipLoader-v5` | 6 | 23.5s |  |
| 65 | `MovieClipLoader-v6` | 6 | 1.4s |  |
| 66 | `NetConnection-v5` | 7 | 2.9s |  |
| 67 | `NetStream-v5` | 6 | 2.9s |  |
| 68 | `NetStream-v6` | 80 | 4.6s |  |
| 69 | `NetStream-v7` | 80 | 4.2s |  |
| 70 | `NetStream-v8` | 80 | 2.4s |  |
| 71 | `Number-v6` | 239 | 10.0s |  |
| 72 | `Number-v7` | 237 | 9.9s |  |
| 73 | `Number-v8` | 237 | 2.6s |  |
| 74 | `Point-v5` | 7 | 2.9s |  |
| 75 | `Point-v6` | 7 | 1.3s |  |
| 76 | `Point-v7` | 7 | 2.5s |  |
| 77 | `Point-v8` | 193 | 8.9s |  |
| 78 | `Random-v5` | 30 | 2.8s |  |
| 79 | `Random-v6` | 30 | 1.2s |  |
| 80 | `Random-v7` | 30 | 2.6s |  |
| 81 | `Random-v8` | 30 | 2.0s |  |
| 82 | `Rectangle-v5` | 7 | 2.5s |  |
| 83 | `Rectangle-v6` | 7 | 1.2s |  |
| 84 | `Rectangle-v7` | 7 | 2.2s |  |
| 85 | `Rectangle-v8` | 166 | 7.2s |  |
| 86 | `Selection-v5` | 21 | 3.2s |  |
| 87 | `Sound-v6` | 121 | 6.4s |  |
| 88 | `Sound-v7` | 121 | 6.0s |  |
| 89 | `Sound-v8` | 121 | 2.9s |  |
| 90 | `Stage-v5` | 38 | 3.5s |  |
| 91 | `System-v5` | 67 | 4.2s |  |
| 92 | `System-v6` | 100 | 5.0s |  |
| 93 | `System-v7` | 101 | 5.0s |  |
| 94 | `System-v8` | 101 | 2.4s |  |
| 95 | `TextFieldHTML-v5` | 6 | 23.1s |  |
| 96 | `TextFieldHTML-v6` | 37 | 3.3s |  |
| 97 | `TextFieldHTML-v7` | 37 | 3.0s |  |
| 98 | `TextFieldHTML-v8` | 37 | 2.2s |  |
| 99 | `TextFormat-v5` | 128 | 5.8s |  |
| 100 | `TextFormat-v6` | 128 | 1.3s |  |
| 101 | `TextSnapshot-v5` | 7 | 22.6s |  |
| 102 | `TextSnapshot-v6` | 173 | 8.6s |  |
| 103 | `TextSnapshot-v7` | 173 | 8.1s |  |
| 104 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 105 | `Transform-v5` | 7 | 2.9s |  |
| 106 | `Transform-v6` | 7 | 2.3s |  |
| 107 | `Transform-v7` | 7 | 2.5s |  |
| 108 | `Try-v5` | 20 | 23.9s |  |
| 109 | `Try-v6` | 20 | 1.4s |  |
| 110 | `Try-v7` | 20 | 3.7s |  |
| 111 | `Try-v8` | 20 | 2.4s |  |
| 112 | `Video-v5` | 7 | 3.0s |  |
| 113 | `Video-v6` | 85 | 4.6s |  |
| 114 | `Video-v7` | 85 | 4.1s |  |
| 115 | `Video-v8` | 85 | 2.5s |  |
| 116 | `XMLSocket-v5` | 35 | 2.4s |  |
| 117 | `XMLSocket-v6` | 35 | 2.4s |  |
| 118 | `XMLSocket-v7` | 35 | 2.2s |  |
| 119 | `XMLSocket-v8` | 35 | 1.7s |  |
| 120 | `argstest-v5` | 4 | 2.1s |  |
| 121 | `case-v5` | 39 | 3.6s |  |
| 122 | `case-v6` | 73 | 4.7s |  |
| 123 | `case-v7` | 67 | 4.4s |  |
| 124 | `case-v8` | 67 | 2.5s |  |
| 125 | `delete-v5` | 61 | 3.9s |  |
| 126 | `delete-v6` | 61 | 3.4s |  |
| 127 | `delete-v7` | 61 | 3.5s |  |
| 128 | `delete-v8` | 61 | 2.5s |  |
| 129 | `enumerate-v5` | 6 | 2.8s |  |
| 130 | `enumerate-v6` | 49 | 3.9s |  |
| 131 | `enumerate-v7` | 49 | 3.5s |  |
| 132 | `enumerate-v8` | 49 | 2.4s |  |
| 133 | `flash-v5` | 10 | 23.3s |  |
| 134 | `flash-v6` | 10 | 3.0s |  |
| 135 | `flash-v7` | 10 | 2.7s |  |
| 136 | `flash-v8` | 41 | 3.9s |  |
| 137 | `getvariable-v5` | 58 | 4.1s |  |
| 138 | `getvariable-v6` | 64 | 4.3s |  |
| 139 | `getvariable-v7` | 64 | 4.3s |  |
| 140 | `getvariable-v8` | 64 | 2.5s |  |
| 141 | `swap-v5` | 7 | 2.9s |  |
| 142 | `swap-v6` | 7 | 1.3s |  |
| 143 | `swap-v7` | 7 | 2.5s |  |
| 144 | `swap-v8` | 7 | 2.3s |  |
| 145 | `targetPath-v5` | 12 | 3.0s |  |
| 146 | `targetPath-v6` | 23 | 3.2s |  |
| 147 | `targetPath-v7` | 23 | 2.8s |  |
| 148 | `targetPath-v8` | 23 | 2.4s |  |

## Ruffle-Matched Tests

**88 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 28.0s |  |
| 2 | `ASnative-v6` | 40 | 40 | 7.1s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.8s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.7s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 24.5s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.3s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.9s |  |
| 8 | `Camera-v8` | 57 | 57 | 2.1s |  |
| 9 | `Date-v5` | 7 | 7 | 14.3s |  |
| 10 | `Date-v6` | 6 | 6 | 15.9s |  |
| 11 | `Date-v7` | 6 | 6 | 16.2s |  |
| 12 | `Date-v8` | 6 | 6 | 2.9s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 6.2s |  |
| 14 | `Function-v5` | 10 | 25 | 7.1s |  |
| 15 | `Global-v6` | 9 | 10 | 8.9s |  |
| 16 | `HitTest-v6` | 8 | 8 | 5.6s |  |
| 17 | `HitTest-v7` | 8 | 8 | 5.3s |  |
| 18 | `HitTest-v8` | 9 | 9 | 5.1s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 26.1s |  |
| 20 | `Inheritance-v6` | 9 | 16 | 7.7s |  |
| 21 | `Inheritance-v7` | 5 | 10 | 8.0s |  |
| 22 | `Inheritance-v8` | 5 | 10 | 3.0s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 6.3s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 6.0s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 2.9s |  |
| 26 | `Math-v5` | 5 | 5 | 11.3s |  |
| 27 | `Math-v6` | 5 | 5 | 1.1s |  |
| 28 | `Math-v7` | 5 | 5 | 12.0s |  |
| 29 | `Math-v8` | 5 | 5 | 1.9s |  |
| 30 | `Microphone-v6` | 31 | 31 | 3.0s |  |
| 31 | `Microphone-v7` | 31 | 31 | 2.8s |  |
| 32 | `Microphone-v8` | 31 | 31 | 1.6s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 14.1s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 48.6s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 53.5s |  |
| 36 | `MovieClipLoader-v7` | 118 | 118 | 5.0s |  |
| 37 | `MovieClipLoader-v8` | 118 | 118 | 3.5s |  |
| 38 | `NetConnection-v6` | 4 | 49 | 6.0s |  |
| 39 | `NetConnection-v7` | 4 | 45 | 6.2s |  |
| 40 | `NetConnection-v8` | 4 | 45 | 2.6s |  |
| 41 | `Number-v5` | 8 | 12 | 10.2s |  |
| 42 | `Object-v5` | 3 | 4 | 26.7s |  |
| 43 | `Object-v6` | 8 | 22 | 13.6s |  |
| 44 | `Object-v7` | 8 | 13 | 13.8s |  |
| 45 | `Object-v8` | 8 | 13 | 3.2s |  |
| 46 | `Selection-v6` | 7 | 13 | 6.2s |  |
| 47 | `Selection-v7` | 7 | 13 | 5.8s |  |
| 48 | `Selection-v8` | 7 | 13 | 2.5s |  |
| 49 | `Sound-v5` | 14 | 16 | 6.3s |  |
| 50 | `Stage-v6` | 14 | 14 | 4.1s |  |
| 51 | `Stage-v7` | 14 | 14 | 3.8s |  |
| 52 | `Stage-v8` | 14 | 14 | 2.5s |  |
| 53 | `String-v5` | 18 | 21 | 16.8s |  |
| 54 | `String-v6` | 9 | 10 | 17.5s |  |
| 55 | `String-v7` | 9 | 10 | 17.3s |  |
| 56 | `String-v8` | 9 | 10 | 2.9s |  |
| 57 | `TextField-v5` | 3 | 3 | 3.0s |  |
| 58 | `TextFormat-v7` | 38 | 40 | 7.7s |  |
| 59 | `TextFormat-v8` | 36 | 38 | 7.5s |  |
| 60 | `Transform-v8` | 7 | 7 | 5.8s |  |
| 61 | `XML-v5` | 10 | 79 | 15.3s |  |
| 62 | `XML-v6` | 3 | 98 | 17.2s |  |
| 63 | `XML-v7` | 3 | 98 | 17.3s |  |
| 64 | `XML-v8` | 24 | 116 | 5.9s |  |
| 65 | `XMLNode-v5` | 3 | 22 | 9.9s |  |
| 66 | `XMLNode-v6` | 3 | 22 | 9.8s |  |
| 67 | `XMLNode-v7` | 3 | 22 | 8.5s |  |
| 68 | `XMLNode-v8` | 3 | 22 | 2.7s |  |
| 69 | `array-v5` | 5 | 17 | 29.9s |  |
| 70 | `array-v6` | 6 | 25 | 34.5s |  |
| 71 | `array-v7` | 5 | 23 | 34.5s |  |
| 72 | `array-v8` | 5 | 23 | 4.3s |  |
| 73 | `ops-v5` | 7 | 9 | 28.8s |  |
| 74 | `ops-v6` | 7 | 11 | 8.8s |  |
| 75 | `ops-v7` | 7 | 11 | 9.4s |  |
| 76 | `ops-v8` | 7 | 11 | 2.2s |  |
| 77 | `setProperty-v5` | 49 | 49 | 3.6s |  |
| 78 | `setProperty-v6` | 49 | 49 | 3.5s |  |
| 79 | `setProperty-v7` | 49 | 49 | 3.3s |  |
| 80 | `setProperty-v8` | 49 | 49 | 2.4s |  |
| 81 | `toString_valueOf-v5` | 34 | 34 | 17.5s |  |
| 82 | `toString_valueOf-v6` | 5 | 5 | 4.7s |  |
| 83 | `toString_valueOf-v7` | 5 | 5 | 4.5s |  |
| 84 | `toString_valueOf-v8` | 5 | 5 | 1.8s |  |
| 85 | `with-v5` | 3 | 3 | 3.1s |  |
| 86 | `with-v6` | 6 | 9 | 4.0s |  |
| 87 | `with-v7` | 6 | 9 | 3.8s |  |
| 88 | `with-v8` | 6 | 9 | 1.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `MovieClip-v8` | 95.2% | 1035 | 1087 | 52 |  |
| 2 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 3 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 4 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**7 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `MovieClip-v8` | 95.2% | 1035/1087 | 1087 | 1087 |  |
| 2 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 3 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 4 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 5 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 6 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 7 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
