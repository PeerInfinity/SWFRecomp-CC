# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 17:00 UTC

**Git SHA**: `08709f6584`

**Run Duration**: 27m 38s

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
| 1 | `Accessibility-v5` | 15 | 1.6s |  |
| 2 | `Accessibility-v6` | 19 | 1.7s |  |
| 3 | `Accessibility-v7` | 19 | 1.4s |  |
| 4 | `Accessibility-v8` | 19 | 1.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.5s |  |
| 6 | `AsBroadcaster-v6` | 121 | 20.8s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.0s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.3s |  |
| 9 | `BitmapData-v5` | 7 | 1.6s |  |
| 10 | `BitmapData-v6` | 7 | 0.5s |  |
| 11 | `BitmapData-v7` | 7 | 1.2s |  |
| 12 | `Boolean-v5` | 38 | 2.0s |  |
| 13 | `Boolean-v6` | 38 | 1.6s |  |
| 14 | `Boolean-v7` | 38 | 17.8s |  |
| 15 | `Boolean-v8` | 38 | 1.1s |  |
| 16 | `Camera-v5` | 7 | 1.4s |  |
| 17 | `Color-v5` | 140 | 3.9s |  |
| 18 | `Color-v6` | 171 | 4.6s |  |
| 19 | `Color-v7` | 161 | 4.5s |  |
| 20 | `Color-v8` | 161 | 27.6s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 0.7s |  |
| 23 | `ColorTransform-v7` | 7 | 1.9s |  |
| 24 | `ColorTransform-v8` | 55 | 3.6s |  |
| 25 | `ContextMenu-v5` | 7 | 2.2s |  |
| 26 | `ContextMenu-v6` | 7 | 0.7s |  |
| 27 | `ContextMenu-v7` | 131 | 5.2s |  |
| 28 | `ContextMenu-v8` | 131 | 20.4s |  |
| 29 | `Error-v5` | 28 | 1.8s |  |
| 30 | `Error-v6` | 31 | 1.9s |  |
| 31 | `Error-v7` | 31 | 1.6s |  |
| 32 | `Error-v8` | 31 | 26.9s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.5s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.7s |  |
| 35 | `ExternalInterface-v7` | 55 | 3.3s |  |
| 36 | `Function-v6` | 271 | 11.8s |  |
| 37 | `Function-v7` | 272 | 12.1s |  |
| 38 | `Function-v8` | 272 | 20.2s |  |
| 39 | `Global-v5` | 172 | 5.1s |  |
| 40 | `Global-v7` | 182 | 5.9s |  |
| 41 | `Global-v8` | 169 | 5.2s |  |
| 42 | `Instance-v5` | 52 | 2.5s |  |
| 43 | `Instance-v6` | 52 | 1.3s |  |
| 44 | `Instance-v7` | 52 | 2.2s |  |
| 45 | `Instance-v8` | 52 | 1.3s |  |
| 46 | `Key-v5` | 51 | 14.7s |  |
| 47 | `Key-v6` | 55 | 2.0s |  |
| 48 | `Key-v7` | 55 | 1.8s |  |
| 49 | `Key-v8` | 55 | 1.1s |  |
| 50 | `LoadVars-v5` | 8 | 1.4s |  |
| 51 | `LocalConnection-v5` | 7 | 17.4s |  |
| 52 | `LocalConnection-v6` | 58 | 2.3s |  |
| 53 | `LocalConnection-v7` | 58 | 2.0s |  |
| 54 | `LocalConnection-v8` | 58 | 1.1s |  |
| 55 | `Matrix-v5` | 7 | 16.9s |  |
| 56 | `Matrix-v6` | 168 | 4.9s |  |
| 57 | `Matrix-v7` | 168 | 5.0s |  |
| 58 | `Matrix-v8` | 168 | 1.1s |  |
| 59 | `Microphone-v5` | 6 | 1.4s |  |
| 60 | `Mouse-v5` | 13 | 17.2s |  |
| 61 | `Mouse-v6` | 21 | 1.6s |  |
| 62 | `Mouse-v7` | 21 | 1.4s |  |
| 63 | `Mouse-v8` | 21 | 1.1s |  |
| 64 | `MovieClipLoader-v5` | 6 | 17.7s |  |
| 65 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 66 | `NetConnection-v5` | 7 | 1.5s |  |
| 67 | `NetStream-v5` | 6 | 23.9s |  |
| 68 | `NetStream-v6` | 80 | 4.2s |  |
| 69 | `NetStream-v7` | 80 | 3.9s |  |
| 70 | `NetStream-v8` | 80 | 1.8s |  |
| 71 | `Number-v6` | 239 | 10.0s |  |
| 72 | `Number-v7` | 237 | 10.1s |  |
| 73 | `Number-v8` | 237 | 1.9s |  |
| 74 | `Point-v5` | 7 | 2.4s |  |
| 75 | `Point-v6` | 7 | 0.7s |  |
| 76 | `Point-v7` | 7 | 2.0s |  |
| 77 | `Point-v8` | 193 | 9.7s |  |
| 78 | `Random-v5` | 30 | 17.4s |  |
| 79 | `Random-v6` | 30 | 0.5s |  |
| 80 | `Random-v7` | 30 | 1.5s |  |
| 81 | `Random-v8` | 30 | 1.1s |  |
| 82 | `Rectangle-v5` | 7 | 1.4s |  |
| 83 | `Rectangle-v6` | 7 | 0.4s |  |
| 84 | `Rectangle-v7` | 7 | 1.1s |  |
| 85 | `Rectangle-v8` | 166 | 4.7s |  |
| 86 | `Selection-v5` | 21 | 17.0s |  |
| 87 | `Sound-v6` | 121 | 3.5s |  |
| 88 | `Sound-v7` | 121 | 3.3s |  |
| 89 | `Sound-v8` | 121 | 1.3s |  |
| 90 | `Stage-v5` | 38 | 18.4s |  |
| 91 | `System-v5` | 67 | 26.5s |  |
| 92 | `System-v6` | 100 | 4.8s |  |
| 93 | `System-v7` | 101 | 4.9s |  |
| 94 | `System-v8` | 101 | 1.9s |  |
| 95 | `TextFieldHTML-v5` | 6 | 17.8s |  |
| 96 | `TextFieldHTML-v6` | 37 | 2.0s |  |
| 97 | `TextFieldHTML-v7` | 37 | 1.7s |  |
| 98 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 99 | `TextFormat-v5` | 128 | 3.9s |  |
| 100 | `TextFormat-v6` | 128 | 0.5s |  |
| 101 | `TextSnapshot-v5` | 7 | 17.5s |  |
| 102 | `TextSnapshot-v6` | 173 | 5.9s |  |
| 103 | `TextSnapshot-v7` | 173 | 5.6s |  |
| 104 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 105 | `Transform-v5` | 7 | 1.4s |  |
| 106 | `Transform-v6` | 7 | 1.1s |  |
| 107 | `Transform-v7` | 7 | 1.2s |  |
| 108 | `Try-v5` | 20 | 23.6s |  |
| 109 | `Try-v6` | 20 | 0.7s |  |
| 110 | `Try-v7` | 20 | 2.9s |  |
| 111 | `Try-v8` | 20 | 1.7s |  |
| 112 | `Video-v5` | 7 | 2.2s |  |
| 113 | `Video-v6` | 85 | 3.8s |  |
| 114 | `Video-v7` | 85 | 3.5s |  |
| 115 | `Video-v8` | 85 | 1.6s |  |
| 116 | `XMLSocket-v5` | 35 | 18.1s |  |
| 117 | `XMLSocket-v6` | 35 | 2.0s |  |
| 118 | `XMLSocket-v7` | 35 | 1.7s |  |
| 119 | `XMLSocket-v8` | 35 | 1.2s |  |
| 120 | `argstest-v5` | 4 | 1.6s |  |
| 121 | `case-v5` | 39 | 2.0s |  |
| 122 | `case-v6` | 73 | 2.7s |  |
| 123 | `case-v7` | 67 | 2.6s |  |
| 124 | `case-v8` | 67 | 1.1s |  |
| 125 | `delete-v5` | 61 | 18.7s |  |
| 126 | `delete-v6` | 61 | 1.9s |  |
| 127 | `delete-v7` | 61 | 2.1s |  |
| 128 | `delete-v8` | 61 | 1.2s |  |
| 129 | `enumerate-v5` | 6 | 1.4s |  |
| 130 | `enumerate-v6` | 49 | 2.3s |  |
| 131 | `enumerate-v7` | 49 | 2.0s |  |
| 132 | `enumerate-v8` | 49 | 1.1s |  |
| 133 | `flash-v5` | 10 | 17.3s |  |
| 134 | `flash-v6` | 10 | 1.5s |  |
| 135 | `flash-v7` | 10 | 1.2s |  |
| 136 | `flash-v8` | 41 | 2.1s |  |
| 137 | `getvariable-v5` | 58 | 2.4s |  |
| 138 | `getvariable-v6` | 64 | 2.5s |  |
| 139 | `getvariable-v7` | 64 | 2.5s |  |
| 140 | `getvariable-v8` | 64 | 1.1s |  |
| 141 | `swap-v5` | 7 | 23.3s |  |
| 142 | `swap-v6` | 7 | 0.7s |  |
| 143 | `swap-v7` | 7 | 1.9s |  |
| 144 | `swap-v8` | 7 | 1.7s |  |
| 145 | `targetPath-v5` | 12 | 2.3s |  |
| 146 | `targetPath-v6` | 23 | 2.6s |  |
| 147 | `targetPath-v7` | 23 | 2.2s |  |
| 148 | `targetPath-v8` | 23 | 1.7s |  |

## Ruffle-Matched Tests

**88 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 20.5s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.4s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.0s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.2s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 20.8s |  |
| 6 | `Camera-v6` | 57 | 57 | 2.9s |  |
| 7 | `Camera-v7` | 57 | 57 | 2.7s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 9 | `Date-v5` | 7 | 7 | 11.3s |  |
| 10 | `Date-v6` | 6 | 6 | 12.6s |  |
| 11 | `Date-v7` | 6 | 6 | 13.0s |  |
| 12 | `Date-v8` | 6 | 6 | 1.4s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 6.3s |  |
| 14 | `Function-v5` | 10 | 25 | 7.1s |  |
| 15 | `Global-v6` | 9 | 10 | 6.5s |  |
| 16 | `HitTest-v6` | 8 | 8 | 3.6s |  |
| 17 | `HitTest-v7` | 8 | 8 | 3.3s |  |
| 18 | `HitTest-v8` | 9 | 9 | 3.2s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 20.3s |  |
| 20 | `Inheritance-v6` | 9 | 13 | 6.0s |  |
| 21 | `Inheritance-v7` | 5 | 7 | 6.1s |  |
| 22 | `Inheritance-v8` | 5 | 7 | 1.8s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 3.8s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 3.6s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 1.6s |  |
| 26 | `Math-v5` | 5 | 5 | 10.4s |  |
| 27 | `Math-v6` | 5 | 5 | 0.6s |  |
| 28 | `Math-v7` | 5 | 5 | 10.8s |  |
| 29 | `Math-v8` | 5 | 5 | 1.2s |  |
| 30 | `Microphone-v6` | 31 | 31 | 2.4s |  |
| 31 | `Microphone-v7` | 31 | 31 | 2.2s |  |
| 32 | `Microphone-v8` | 31 | 31 | 1.0s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 10.4s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 38.4s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 41.3s |  |
| 36 | `MovieClipLoader-v7` | 118 | 118 | 3.1s |  |
| 37 | `MovieClipLoader-v8` | 118 | 118 | 2.0s |  |
| 38 | `NetConnection-v6` | 4 | 49 | 3.8s |  |
| 39 | `NetConnection-v7` | 4 | 45 | 3.8s |  |
| 40 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 41 | `Number-v5` | 8 | 12 | 10.3s |  |
| 42 | `Object-v5` | 3 | 4 | 30.4s |  |
| 43 | `Object-v6` | 8 | 21 | 15.1s |  |
| 44 | `Object-v7` | 8 | 12 | 15.3s |  |
| 45 | `Object-v8` | 8 | 12 | 2.7s |  |
| 46 | `Selection-v6` | 7 | 13 | 3.6s |  |
| 47 | `Selection-v7` | 7 | 13 | 3.3s |  |
| 48 | `Selection-v8` | 7 | 13 | 1.1s |  |
| 49 | `Sound-v5` | 14 | 16 | 3.5s |  |
| 50 | `Stage-v6` | 14 | 14 | 2.4s |  |
| 51 | `Stage-v7` | 14 | 14 | 2.1s |  |
| 52 | `Stage-v8` | 14 | 14 | 1.2s |  |
| 53 | `String-v5` | 18 | 21 | 13.8s |  |
| 54 | `String-v6` | 9 | 10 | 14.2s |  |
| 55 | `String-v7` | 9 | 10 | 14.1s |  |
| 56 | `String-v8` | 9 | 10 | 1.4s |  |
| 57 | `TextField-v5` | 3 | 3 | 2.4s |  |
| 58 | `TextFormat-v7` | 38 | 40 | 5.1s |  |
| 59 | `TextFormat-v8` | 36 | 38 | 5.0s |  |
| 60 | `Transform-v8` | 7 | 7 | 3.6s |  |
| 61 | `XML-v5` | 10 | 79 | 25.8s |  |
| 62 | `XML-v6` | 3 | 98 | 12.0s |  |
| 63 | `XML-v7` | 3 | 98 | 11.8s |  |
| 64 | `XML-v8` | 24 | 116 | 3.3s |  |
| 65 | `XMLNode-v5` | 3 | 22 | 6.5s |  |
| 66 | `XMLNode-v6` | 3 | 22 | 6.5s |  |
| 67 | `XMLNode-v7` | 3 | 22 | 5.7s |  |
| 68 | `XMLNode-v8` | 3 | 22 | 1.3s |  |
| 69 | `array-v5` | 5 | 17 | 40.5s |  |
| 70 | `array-v6` | 6 | 25 | 27.3s |  |
| 71 | `array-v7` | 5 | 23 | 28.5s |  |
| 72 | `array-v8` | 5 | 23 | 2.4s |  |
| 73 | `ops-v5` | 7 | 9 | 30.0s |  |
| 74 | `ops-v6` | 7 | 11 | 9.3s |  |
| 75 | `ops-v7` | 7 | 11 | 10.0s |  |
| 76 | `ops-v8` | 7 | 11 | 1.9s |  |
| 77 | `setProperty-v5` | 49 | 49 | 3.3s |  |
| 78 | `setProperty-v6` | 49 | 49 | 3.3s |  |
| 79 | `setProperty-v7` | 49 | 49 | 2.9s |  |
| 80 | `setProperty-v8` | 49 | 49 | 1.9s |  |
| 81 | `toString_valueOf-v5` | 34 | 34 | 27.5s |  |
| 82 | `toString_valueOf-v6` | 5 | 5 | 5.8s |  |
| 83 | `toString_valueOf-v7` | 5 | 5 | 5.3s |  |
| 84 | `toString_valueOf-v8` | 5 | 5 | 1.6s |  |
| 85 | `with-v5` | 3 | 3 | 3.7s |  |
| 86 | `with-v6` | 6 | 9 | 4.9s |  |
| 87 | `with-v7` | 6 | 9 | 4.5s |  |
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
