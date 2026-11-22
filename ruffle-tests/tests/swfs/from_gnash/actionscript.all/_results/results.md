# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-22 07:25 UTC

**Git SHA**: `9561027db3`

**Run Duration**: 19m 52s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **148** (60.9%) |
| Ruffle-matched | 89 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **237** (97.5%) |
| Failing | 6 |
| Total expected lines | 38791 |
| Matching lines | 30657 (79.0%) |
| Mismatched lines | 8134 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**148 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.0s |  |
| 2 | `Accessibility-v6` | 19 | 2.1s |  |
| 3 | `Accessibility-v7` | 19 | 1.8s |  |
| 4 | `Accessibility-v8` | 19 | 1.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.9s |  |
| 6 | `AsBroadcaster-v6` | 121 | 5.6s |  |
| 7 | `AsBroadcaster-v7` | 121 | 5.2s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.8s |  |
| 9 | `BitmapData-v5` | 7 | 2.2s |  |
| 10 | `BitmapData-v6` | 7 | 0.7s |  |
| 11 | `BitmapData-v7` | 7 | 1.9s |  |
| 12 | `Boolean-v5` | 38 | 2.8s |  |
| 13 | `Boolean-v6` | 38 | 2.2s |  |
| 14 | `Boolean-v7` | 38 | 1.9s |  |
| 15 | `Boolean-v8` | 38 | 1.0s |  |
| 16 | `Camera-v5` | 7 | 0.8s |  |
| 17 | `Color-v5` | 140 | 3.7s |  |
| 18 | `Color-v6` | 171 | 4.5s |  |
| 19 | `Color-v7` | 161 | 4.3s |  |
| 20 | `Color-v8` | 161 | 29.3s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 0.7s |  |
| 23 | `ColorTransform-v7` | 7 | 1.9s |  |
| 24 | `ColorTransform-v8` | 55 | 3.8s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 0.7s |  |
| 27 | `ContextMenu-v7` | 131 | 5.8s |  |
| 28 | `ContextMenu-v8` | 131 | 3.7s |  |
| 29 | `Error-v5` | 28 | 1.8s |  |
| 30 | `Error-v6` | 31 | 1.9s |  |
| 31 | `Error-v7` | 31 | 1.6s |  |
| 32 | `Error-v8` | 31 | 17.6s |  |
| 33 | `ExternalInterface-v5` | 7 | 1.4s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.1s |  |
| 35 | `ExternalInterface-v7` | 55 | 1.8s |  |
| 36 | `Function-v6` | 271 | 7.1s |  |
| 37 | `Function-v7` | 272 | 7.5s |  |
| 38 | `Function-v8` | 272 | 24.0s |  |
| 39 | `Global-v5` | 172 | 5.5s |  |
| 40 | `Global-v7` | 182 | 5.7s |  |
| 41 | `Global-v8` | 169 | 5.3s |  |
| 42 | `Instance-v5` | 52 | 2.2s |  |
| 43 | `Instance-v6` | 52 | 1.2s |  |
| 44 | `Instance-v7` | 52 | 1.9s |  |
| 45 | `Instance-v8` | 52 | 1.1s |  |
| 46 | `Key-v5` | 51 | 2.1s |  |
| 47 | `Key-v6` | 55 | 2.2s |  |
| 48 | `Key-v7` | 55 | 1.9s |  |
| 49 | `Key-v8` | 55 | 1.1s |  |
| 50 | `LoadVars-v5` | 8 | 1.5s |  |
| 51 | `LocalConnection-v5` | 7 | 1.5s |  |
| 52 | `LocalConnection-v6` | 58 | 2.3s |  |
| 53 | `LocalConnection-v7` | 58 | 2.1s |  |
| 54 | `LocalConnection-v8` | 58 | 1.1s |  |
| 55 | `Matrix-v5` | 7 | 1.8s |  |
| 56 | `Matrix-v6` | 168 | 7.4s |  |
| 57 | `Matrix-v7` | 168 | 7.6s |  |
| 58 | `Matrix-v8` | 168 | 1.5s |  |
| 59 | `Microphone-v5` | 6 | 1.8s |  |
| 60 | `Mouse-v5` | 13 | 1.6s |  |
| 61 | `Mouse-v6` | 21 | 1.7s |  |
| 62 | `Mouse-v7` | 21 | 1.4s |  |
| 63 | `Mouse-v8` | 21 | 1.1s |  |
| 64 | `MovieClipLoader-v5` | 6 | 20.5s |  |
| 65 | `MovieClipLoader-v6` | 6 | 0.6s |  |
| 66 | `NetConnection-v5` | 7 | 2.1s |  |
| 67 | `NetStream-v5` | 6 | 1.5s |  |
| 68 | `NetStream-v6` | 80 | 2.9s |  |
| 69 | `NetStream-v7` | 80 | 2.6s |  |
| 70 | `NetStream-v8` | 80 | 1.1s |  |
| 71 | `Number-v6` | 239 | 7.4s |  |
| 72 | `Number-v7` | 237 | 7.3s |  |
| 73 | `Number-v8` | 237 | 1.2s |  |
| 74 | `Point-v5` | 7 | 1.8s |  |
| 75 | `Point-v6` | 7 | 0.6s |  |
| 76 | `Point-v7` | 7 | 1.6s |  |
| 77 | `Point-v8` | 193 | 7.2s |  |
| 78 | `Random-v5` | 30 | 17.9s |  |
| 79 | `Random-v6` | 30 | 0.5s |  |
| 80 | `Random-v7` | 30 | 1.6s |  |
| 81 | `Random-v8` | 30 | 1.1s |  |
| 82 | `Rectangle-v5` | 7 | 1.5s |  |
| 83 | `Rectangle-v6` | 7 | 0.5s |  |
| 84 | `Rectangle-v7` | 7 | 1.2s |  |
| 85 | `Rectangle-v8` | 166 | 5.2s |  |
| 86 | `Selection-v5` | 21 | 1.7s |  |
| 87 | `Sound-v6` | 121 | 4.2s |  |
| 88 | `Sound-v7` | 121 | 4.0s |  |
| 89 | `Sound-v8` | 121 | 1.5s |  |
| 90 | `Stage-v5` | 38 | 1.9s |  |
| 91 | `System-v5` | 67 | 2.3s |  |
| 92 | `System-v6` | 100 | 2.9s |  |
| 93 | `System-v7` | 101 | 2.9s |  |
| 94 | `System-v8` | 101 | 1.1s |  |
| 95 | `TextFieldHTML-v5` | 6 | 2.2s |  |
| 96 | `TextFieldHTML-v6` | 37 | 2.8s |  |
| 97 | `TextFieldHTML-v7` | 37 | 2.4s |  |
| 98 | `TextFieldHTML-v8` | 37 | 1.6s |  |
| 99 | `TextFormat-v5` | 128 | 5.2s |  |
| 100 | `TextFormat-v6` | 128 | 0.8s |  |
| 101 | `TextSnapshot-v5` | 7 | 1.5s |  |
| 102 | `TextSnapshot-v6` | 173 | 6.6s |  |
| 103 | `TextSnapshot-v7` | 173 | 6.3s |  |
| 104 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 105 | `Transform-v5` | 7 | 1.5s |  |
| 106 | `Transform-v6` | 7 | 1.1s |  |
| 107 | `Transform-v7` | 7 | 1.3s |  |
| 108 | `Try-v5` | 20 | 2.3s |  |
| 109 | `Try-v6` | 20 | 0.5s |  |
| 110 | `Try-v7` | 20 | 2.0s |  |
| 111 | `Try-v8` | 20 | 1.1s |  |
| 112 | `Video-v5` | 7 | 1.5s |  |
| 113 | `Video-v6` | 85 | 2.7s |  |
| 114 | `Video-v7` | 85 | 2.4s |  |
| 115 | `Video-v8` | 85 | 1.1s |  |
| 116 | `XMLSocket-v5` | 35 | 2.0s |  |
| 117 | `XMLSocket-v6` | 35 | 2.0s |  |
| 118 | `XMLSocket-v7` | 35 | 1.8s |  |
| 119 | `XMLSocket-v8` | 35 | 1.2s |  |
| 120 | `argstest-v5` | 4 | 1.6s |  |
| 121 | `case-v5` | 39 | 2.6s |  |
| 122 | `case-v6` | 73 | 3.4s |  |
| 123 | `case-v7` | 67 | 3.4s |  |
| 124 | `case-v8` | 67 | 1.5s |  |
| 125 | `delete-v5` | 61 | 3.4s |  |
| 126 | `delete-v6` | 61 | 2.8s |  |
| 127 | `delete-v7` | 61 | 3.0s |  |
| 128 | `delete-v8` | 61 | 1.8s |  |
| 129 | `enumerate-v5` | 6 | 2.2s |  |
| 130 | `enumerate-v6` | 49 | 3.4s |  |
| 131 | `enumerate-v7` | 49 | 3.0s |  |
| 132 | `enumerate-v8` | 49 | 1.7s |  |
| 133 | `flash-v5` | 10 | 1.4s |  |
| 134 | `flash-v6` | 10 | 1.4s |  |
| 135 | `flash-v7` | 10 | 1.2s |  |
| 136 | `flash-v8` | 41 | 2.1s |  |
| 137 | `getvariable-v5` | 58 | 2.3s |  |
| 138 | `getvariable-v6` | 64 | 2.4s |  |
| 139 | `getvariable-v7` | 64 | 2.4s |  |
| 140 | `getvariable-v8` | 64 | 1.1s |  |
| 141 | `swap-v5` | 7 | 16.9s |  |
| 142 | `swap-v6` | 7 | 0.3s |  |
| 143 | `swap-v7` | 7 | 0.3s |  |
| 144 | `swap-v8` | 7 | 0.3s |  |
| 145 | `targetPath-v5` | 12 | 0.3s |  |
| 146 | `targetPath-v6` | 23 | 0.3s |  |
| 147 | `targetPath-v7` | 23 | 0.3s |  |
| 148 | `targetPath-v8` | 23 | 0.3s |  |

## Ruffle-Matched Tests

**89 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 4.8s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.6s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.5s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 25.6s |  |
| 6 | `Camera-v6` | 57 | 57 | 2.8s |  |
| 7 | `Camera-v7` | 57 | 57 | 2.6s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 9 | `Date-v5` | 7 | 7 | 10.2s |  |
| 10 | `Date-v6` | 6 | 6 | 11.6s |  |
| 11 | `Date-v7` | 6 | 6 | 12.0s |  |
| 12 | `Date-v8` | 6 | 6 | 1.4s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 3.4s |  |
| 14 | `Function-v5` | 10 | 25 | 4.1s |  |
| 15 | `Global-v6` | 9 | 10 | 6.6s |  |
| 16 | `HitTest-v6` | 8 | 8 | 3.8s |  |
| 17 | `HitTest-v7` | 8 | 8 | 3.6s |  |
| 18 | `HitTest-v8` | 9 | 9 | 3.5s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 3.5s |  |
| 20 | `Inheritance-v6` | 9 | 13 | 5.1s |  |
| 21 | `Inheritance-v7` | 5 | 7 | 5.2s |  |
| 22 | `Inheritance-v8` | 5 | 7 | 1.5s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 4.3s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 4.2s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 1.8s |  |
| 26 | `Math-v5` | 5 | 5 | 10.9s |  |
| 27 | `Math-v6` | 5 | 5 | 0.6s |  |
| 28 | `Math-v7` | 5 | 5 | 11.2s |  |
| 29 | `Math-v8` | 5 | 5 | 1.3s |  |
| 30 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 31 | `Microphone-v7` | 31 | 31 | 3.0s |  |
| 32 | `Microphone-v8` | 31 | 31 | 1.3s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 10.9s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 38.9s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 41.3s |  |
| 36 | `MovieClip-v8` | 25 | 68 | 52.6s |  |
| 37 | `MovieClipLoader-v7` | 118 | 118 | 4.0s |  |
| 38 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 39 | `NetConnection-v6` | 4 | 49 | 5.5s |  |
| 40 | `NetConnection-v7` | 4 | 45 | 5.6s |  |
| 41 | `NetConnection-v8` | 4 | 45 | 1.8s |  |
| 42 | `Number-v5` | 8 | 12 | 7.6s |  |
| 43 | `Object-v5` | 3 | 4 | 5.2s |  |
| 44 | `Object-v6` | 8 | 21 | 11.7s |  |
| 45 | `Object-v7` | 8 | 12 | 11.8s |  |
| 46 | `Object-v8` | 8 | 12 | 2.0s |  |
| 47 | `Selection-v6` | 7 | 13 | 4.3s |  |
| 48 | `Selection-v7` | 7 | 13 | 4.0s |  |
| 49 | `Selection-v8` | 7 | 13 | 1.2s |  |
| 50 | `Sound-v5` | 14 | 16 | 4.0s |  |
| 51 | `Stage-v6` | 14 | 14 | 2.2s |  |
| 52 | `Stage-v7` | 14 | 14 | 2.0s |  |
| 53 | `Stage-v8` | 14 | 14 | 1.1s |  |
| 54 | `String-v5` | 18 | 21 | 12.3s |  |
| 55 | `String-v6` | 9 | 10 | 12.9s |  |
| 56 | `String-v7` | 9 | 10 | 12.9s |  |
| 57 | `String-v8` | 9 | 10 | 1.4s |  |
| 58 | `TextField-v5` | 3 | 3 | 1.5s |  |
| 59 | `TextFormat-v7` | 38 | 38 | 6.9s |  |
| 60 | `TextFormat-v8` | 36 | 36 | 6.8s |  |
| 61 | `Transform-v8` | 7 | 7 | 4.0s |  |
| 62 | `XML-v5` | 10 | 79 | 10.7s |  |
| 63 | `XML-v6` | 3 | 98 | 11.8s |  |
| 64 | `XML-v7` | 3 | 98 | 11.6s |  |
| 65 | `XML-v8` | 24 | 116 | 3.4s |  |
| 66 | `XMLNode-v5` | 3 | 22 | 6.3s |  |
| 67 | `XMLNode-v6` | 3 | 22 | 6.3s |  |
| 68 | `XMLNode-v7` | 3 | 22 | 5.6s |  |
| 69 | `XMLNode-v8` | 3 | 22 | 1.2s |  |
| 70 | `array-v5` | 5 | 17 | 29.2s |  |
| 71 | `array-v6` | 6 | 25 | 33.9s |  |
| 72 | `array-v7` | 5 | 23 | 35.6s |  |
| 73 | `array-v8` | 5 | 23 | 3.1s |  |
| 74 | `ops-v5` | 7 | 9 | 7.3s |  |
| 75 | `ops-v6` | 7 | 11 | 7.0s |  |
| 76 | `ops-v7` | 7 | 11 | 7.4s |  |
| 77 | `ops-v8` | 7 | 11 | 1.2s |  |
| 78 | `setProperty-v5` | 49 | 49 | 2.3s |  |
| 79 | `setProperty-v6` | 49 | 49 | 2.3s |  |
| 80 | `setProperty-v7` | 49 | 49 | 2.0s |  |
| 81 | `setProperty-v8` | 49 | 49 | 1.3s |  |
| 82 | `toString_valueOf-v5` | 34 | 34 | 4.3s |  |
| 83 | `toString_valueOf-v6` | 5 | 5 | 4.5s |  |
| 84 | `toString_valueOf-v7` | 5 | 5 | 4.3s |  |
| 85 | `toString_valueOf-v8` | 5 | 5 | 1.2s |  |
| 86 | `with-v5` | 3 | 3 | 2.8s |  |
| 87 | `with-v6` | 6 | 9 | 3.8s |  |
| 88 | `with-v7` | 6 | 9 | 3.5s |  |
| 89 | `with-v8` | 6 | 9 | 1.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 2 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 3 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 2 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 3 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 4 | `argstest-v8` | 4.0% | 121/3006 | 3006 | 2434 |  |
| 5 | `argstest-v6` | 3.2% | 84/2644 | 2644 | 2192 |  |
| 6 | `argstest-v7` | 3.0% | 78/2644 | 2644 | 2061 |  |
