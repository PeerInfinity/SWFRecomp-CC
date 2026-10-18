# Ruffle Test Results (Unfiltered)

**Date**: 2026-10-18 08:49 UTC

**Git SHA**: `f555113796`

**Run Duration**: 20m 58s

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
| 1 | `Accessibility-v5` | 15 | 2.2s |  |
| 2 | `Accessibility-v6` | 19 | 2.3s |  |
| 3 | `Accessibility-v7` | 19 | 1.9s |  |
| 4 | `Accessibility-v8` | 19 | 1.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.1s |  |
| 6 | `AsBroadcaster-v6` | 121 | 5.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 5.0s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.8s |  |
| 9 | `BitmapData-v5` | 7 | 2.1s |  |
| 10 | `BitmapData-v6` | 7 | 0.7s |  |
| 11 | `BitmapData-v7` | 7 | 1.8s |  |
| 12 | `Boolean-v5` | 38 | 2.6s |  |
| 13 | `Boolean-v6` | 38 | 2.1s |  |
| 14 | `Boolean-v7` | 38 | 2.7s |  |
| 15 | `Boolean-v8` | 38 | 1.6s |  |
| 16 | `Camera-v5` | 7 | 2.1s |  |
| 17 | `Color-v5` | 140 | 5.8s |  |
| 18 | `Color-v6` | 171 | 6.8s |  |
| 19 | `Color-v7` | 161 | 6.8s |  |
| 20 | `Color-v8` | 161 | 7.2s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 0.7s |  |
| 23 | `ColorTransform-v7` | 7 | 2.0s |  |
| 24 | `ColorTransform-v8` | 55 | 3.9s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 0.7s |  |
| 27 | `ContextMenu-v7` | 131 | 5.6s |  |
| 28 | `ContextMenu-v8` | 131 | 4.9s |  |
| 29 | `Error-v5` | 28 | 2.5s |  |
| 30 | `Error-v6` | 31 | 2.5s |  |
| 31 | `Error-v7` | 31 | 2.2s |  |
| 32 | `Error-v8` | 31 | 2.7s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.1s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.0s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `Function-v6` | 271 | 9.9s |  |
| 37 | `Function-v7` | 272 | 10.2s |  |
| 38 | `Function-v8` | 272 | 10.3s |  |
| 39 | `Global-v5` | 172 | 7.4s |  |
| 40 | `Global-v7` | 182 | 7.7s |  |
| 41 | `Global-v8` | 169 | 7.0s |  |
| 42 | `Instance-v5` | 52 | 3.1s |  |
| 43 | `Instance-v6` | 52 | 1.8s |  |
| 44 | `Instance-v7` | 52 | 2.8s |  |
| 45 | `Instance-v8` | 52 | 1.6s |  |
| 46 | `Key-v5` | 51 | 2.0s |  |
| 47 | `Key-v6` | 55 | 2.0s |  |
| 48 | `Key-v7` | 55 | 1.9s |  |
| 49 | `Key-v8` | 55 | 1.1s |  |
| 50 | `LoadVars-v5` | 8 | 1.4s |  |
| 51 | `LocalConnection-v5` | 7 | 2.1s |  |
| 52 | `LocalConnection-v6` | 58 | 3.2s |  |
| 53 | `LocalConnection-v7` | 58 | 2.9s |  |
| 54 | `LocalConnection-v8` | 58 | 1.6s |  |
| 55 | `Matrix-v5` | 7 | 1.8s |  |
| 56 | `Matrix-v6` | 168 | 6.6s |  |
| 57 | `Matrix-v7` | 168 | 6.8s |  |
| 58 | `Matrix-v8` | 168 | 1.4s |  |
| 59 | `Microphone-v5` | 6 | 1.8s |  |
| 60 | `Mouse-v5` | 13 | 2.0s |  |
| 61 | `Mouse-v6` | 21 | 2.1s |  |
| 62 | `Mouse-v7` | 21 | 1.8s |  |
| 63 | `Mouse-v8` | 21 | 1.4s |  |
| 64 | `MovieClipLoader-v5` | 6 | 2.2s |  |
| 65 | `MovieClipLoader-v6` | 6 | 0.7s |  |
| 66 | `NetConnection-v5` | 7 | 2.0s |  |
| 67 | `NetStream-v5` | 6 | 2.1s |  |
| 68 | `NetStream-v6` | 80 | 3.9s |  |
| 69 | `NetStream-v7` | 80 | 3.5s |  |
| 70 | `NetStream-v8` | 80 | 1.6s |  |
| 71 | `Number-v6` | 239 | 9.4s |  |
| 72 | `Number-v7` | 237 | 9.3s |  |
| 73 | `Number-v8` | 237 | 1.9s |  |
| 74 | `Point-v5` | 7 | 2.1s |  |
| 75 | `Point-v6` | 7 | 0.7s |  |
| 76 | `Point-v7` | 7 | 1.8s |  |
| 77 | `Point-v8` | 193 | 8.3s |  |
| 78 | `Random-v5` | 30 | 1.6s |  |
| 79 | `Random-v6` | 30 | 0.4s |  |
| 80 | `Random-v7` | 30 | 1.3s |  |
| 81 | `Random-v8` | 30 | 1.0s |  |
| 82 | `Rectangle-v5` | 7 | 1.3s |  |
| 83 | `Rectangle-v6` | 7 | 0.4s |  |
| 84 | `Rectangle-v7` | 7 | 1.1s |  |
| 85 | `Rectangle-v8` | 166 | 4.4s |  |
| 86 | `Selection-v5` | 21 | 2.3s |  |
| 87 | `Sound-v6` | 121 | 5.7s |  |
| 88 | `Sound-v7` | 121 | 5.2s |  |
| 89 | `Sound-v8` | 121 | 2.1s |  |
| 90 | `Stage-v5` | 38 | 2.7s |  |
| 91 | `System-v5` | 67 | 3.4s |  |
| 92 | `System-v6` | 100 | 4.2s |  |
| 93 | `System-v7` | 101 | 4.2s |  |
| 94 | `System-v8` | 101 | 1.6s |  |
| 95 | `TextFieldHTML-v5` | 6 | 1.7s |  |
| 96 | `TextFieldHTML-v6` | 37 | 2.1s |  |
| 97 | `TextFieldHTML-v7` | 37 | 1.9s |  |
| 98 | `TextFieldHTML-v8` | 37 | 1.2s |  |
| 99 | `TextFormat-v5` | 128 | 4.2s |  |
| 100 | `TextFormat-v6` | 128 | 0.6s |  |
| 101 | `TextSnapshot-v5` | 7 | 1.9s |  |
| 102 | `TextSnapshot-v6` | 173 | 7.3s |  |
| 103 | `TextSnapshot-v7` | 173 | 7.0s |  |
| 104 | `TextSnapshot-v8` | 173 | 1.5s |  |
| 105 | `Transform-v5` | 7 | 1.9s |  |
| 106 | `Transform-v6` | 7 | 1.4s |  |
| 107 | `Transform-v7` | 7 | 1.5s |  |
| 108 | `Try-v5` | 20 | 3.3s |  |
| 109 | `Try-v6` | 20 | 0.7s |  |
| 110 | `Try-v7` | 20 | 2.9s |  |
| 111 | `Try-v8` | 20 | 1.7s |  |
| 112 | `Video-v5` | 7 | 2.2s |  |
| 113 | `Video-v6` | 85 | 3.7s |  |
| 114 | `Video-v7` | 85 | 3.3s |  |
| 115 | `Video-v8` | 85 | 1.6s |  |
| 116 | `XMLSocket-v5` | 35 | 2.4s |  |
| 117 | `XMLSocket-v6` | 35 | 2.2s |  |
| 118 | `XMLSocket-v7` | 35 | 1.9s |  |
| 119 | `XMLSocket-v8` | 35 | 1.3s |  |
| 120 | `argstest-v5` | 4 | 1.8s |  |
| 121 | `case-v5` | 39 | 2.8s |  |
| 122 | `case-v6` | 73 | 3.6s |  |
| 123 | `case-v7` | 67 | 3.6s |  |
| 124 | `case-v8` | 67 | 1.7s |  |
| 125 | `delete-v5` | 61 | 3.1s |  |
| 126 | `delete-v6` | 61 | 2.6s |  |
| 127 | `delete-v7` | 61 | 2.8s |  |
| 128 | `delete-v8` | 61 | 1.7s |  |
| 129 | `enumerate-v5` | 6 | 2.0s |  |
| 130 | `enumerate-v6` | 49 | 3.1s |  |
| 131 | `enumerate-v7` | 49 | 2.8s |  |
| 132 | `enumerate-v8` | 49 | 1.6s |  |
| 133 | `flash-v5` | 10 | 2.2s |  |
| 134 | `flash-v6` | 10 | 2.2s |  |
| 135 | `flash-v7` | 10 | 1.9s |  |
| 136 | `flash-v8` | 41 | 3.1s |  |
| 137 | `getvariable-v5` | 58 | 3.5s |  |
| 138 | `getvariable-v6` | 64 | 3.6s |  |
| 139 | `getvariable-v7` | 64 | 3.7s |  |
| 140 | `getvariable-v8` | 64 | 1.7s |  |
| 141 | `swap-v5` | 7 | 1.8s |  |
| 142 | `swap-v6` | 7 | 0.6s |  |
| 143 | `swap-v7` | 7 | 1.5s |  |
| 144 | `swap-v8` | 7 | 1.3s |  |
| 145 | `targetPath-v5` | 12 | 1.9s |  |
| 146 | `targetPath-v6` | 23 | 2.1s |  |
| 147 | `targetPath-v7` | 23 | 1.8s |  |
| 148 | `targetPath-v8` | 23 | 1.3s |  |

## Ruffle-Matched Tests

**88 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 5.5s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.7s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 24.0s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.2s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.9s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.6s |  |
| 9 | `Date-v5` | 7 | 7 | 13.4s |  |
| 10 | `Date-v6` | 6 | 6 | 15.0s |  |
| 11 | `Date-v7` | 6 | 6 | 15.5s |  |
| 12 | `Date-v8` | 6 | 6 | 2.0s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 5.2s |  |
| 14 | `Function-v5` | 10 | 25 | 6.0s |  |
| 15 | `Global-v6` | 9 | 10 | 9.0s |  |
| 16 | `HitTest-v6` | 8 | 8 | 5.3s |  |
| 17 | `HitTest-v7` | 8 | 8 | 4.8s |  |
| 18 | `HitTest-v8` | 9 | 9 | 4.9s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 4.8s |  |
| 20 | `Inheritance-v6` | 9 | 16 | 7.0s |  |
| 21 | `Inheritance-v7` | 5 | 10 | 7.1s |  |
| 22 | `Inheritance-v8` | 5 | 10 | 2.2s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 3.9s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 3.7s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 1.7s |  |
| 26 | `Math-v5` | 5 | 5 | 13.5s |  |
| 27 | `Math-v6` | 5 | 5 | 0.9s |  |
| 28 | `Math-v7` | 5 | 5 | 13.8s |  |
| 29 | `Math-v8` | 5 | 5 | 1.8s |  |
| 30 | `Microphone-v6` | 31 | 31 | 3.0s |  |
| 31 | `Microphone-v7` | 31 | 31 | 2.7s |  |
| 32 | `Microphone-v8` | 31 | 31 | 1.3s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 13.2s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 45.4s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 50.0s |  |
| 36 | `MovieClipLoader-v7` | 118 | 118 | 4.1s |  |
| 37 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 38 | `NetConnection-v6` | 4 | 49 | 5.0s |  |
| 39 | `NetConnection-v7` | 4 | 45 | 5.1s |  |
| 40 | `NetConnection-v8` | 4 | 45 | 1.7s |  |
| 41 | `Number-v5` | 8 | 12 | 9.6s |  |
| 42 | `Object-v5` | 3 | 4 | 5.8s |  |
| 43 | `Object-v6` | 8 | 22 | 12.9s |  |
| 44 | `Object-v7` | 8 | 13 | 12.9s |  |
| 45 | `Object-v8` | 8 | 13 | 2.4s |  |
| 46 | `Selection-v6` | 7 | 13 | 5.4s |  |
| 47 | `Selection-v7` | 7 | 13 | 5.0s |  |
| 48 | `Selection-v8` | 7 | 13 | 1.7s |  |
| 49 | `Sound-v5` | 14 | 16 | 5.3s |  |
| 50 | `Stage-v6` | 14 | 14 | 3.3s |  |
| 51 | `Stage-v7` | 14 | 14 | 2.9s |  |
| 52 | `Stage-v8` | 14 | 14 | 1.7s |  |
| 53 | `String-v5` | 18 | 21 | 16.2s |  |
| 54 | `String-v6` | 9 | 10 | 17.1s |  |
| 55 | `String-v7` | 9 | 10 | 16.8s |  |
| 56 | `String-v8` | 9 | 10 | 2.1s |  |
| 57 | `TextField-v5` | 3 | 3 | 2.2s |  |
| 58 | `TextFormat-v7` | 38 | 40 | 5.6s |  |
| 59 | `TextFormat-v8` | 36 | 38 | 5.6s |  |
| 60 | `Transform-v8` | 7 | 7 | 4.7s |  |
| 61 | `XML-v5` | 10 | 79 | 14.1s |  |
| 62 | `XML-v6` | 3 | 98 | 15.9s |  |
| 63 | `XML-v7` | 3 | 98 | 15.4s |  |
| 64 | `XML-v8` | 24 | 116 | 4.8s |  |
| 65 | `XMLNode-v5` | 3 | 22 | 8.4s |  |
| 66 | `XMLNode-v6` | 3 | 22 | 8.5s |  |
| 67 | `XMLNode-v7` | 3 | 22 | 7.4s |  |
| 68 | `XMLNode-v8` | 3 | 22 | 1.8s |  |
| 69 | `array-v5` | 5 | 17 | 28.5s |  |
| 70 | `array-v6` | 6 | 25 | 32.9s |  |
| 71 | `array-v7` | 5 | 23 | 33.6s |  |
| 72 | `array-v8` | 5 | 23 | 3.5s |  |
| 73 | `ops-v5` | 7 | 9 | 0.3s |  |
| 74 | `ops-v6` | 7 | 11 | 0.3s |  |
| 75 | `ops-v7` | 7 | 11 | 0.3s |  |
| 76 | `ops-v8` | 7 | 11 | 0.3s |  |
| 77 | `setProperty-v5` | 49 | 49 | 0.2s |  |
| 78 | `setProperty-v6` | 49 | 49 | 0.2s |  |
| 79 | `setProperty-v7` | 49 | 49 | 0.2s |  |
| 80 | `setProperty-v8` | 49 | 49 | 0.2s |  |
| 81 | `toString_valueOf-v5` | 34 | 34 | 5.0s |  |
| 82 | `toString_valueOf-v6` | 5 | 5 | 5.4s |  |
| 83 | `toString_valueOf-v7` | 5 | 5 | 5.1s |  |
| 84 | `toString_valueOf-v8` | 5 | 5 | 1.7s |  |
| 85 | `with-v5` | 3 | 3 | 3.5s |  |
| 86 | `with-v6` | 6 | 9 | 4.7s |  |
| 87 | `with-v7` | 6 | 9 | 4.3s |  |
| 88 | `with-v8` | 6 | 9 | 1.8s |  |

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
