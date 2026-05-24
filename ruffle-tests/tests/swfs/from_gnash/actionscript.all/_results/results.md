# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-24 03:24 UTC

**Git SHA**: `ae6fdcb6f9`

**Run Duration**: 16m 49s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **128** (52.7%) |
| Ruffle-matched | 99 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **227** (93.4%) |
| Failing | 16 |
| Total expected lines | 38787 |
| Matching lines | 29518 (76.1%) |
| Mismatched lines | 9269 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 16 | 100.0% |

## Passing Tests

**128 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.3s |  |
| 3 | `Accessibility-v7` | 19 | 0.3s |  |
| 4 | `Accessibility-v8` | 19 | 0.3s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.3s |  |
| 6 | `BitmapData-v5` | 7 | 0.4s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 0.4s |  |
| 9 | `Boolean-v5` | 38 | 0.4s |  |
| 10 | `Boolean-v6` | 38 | 0.4s |  |
| 11 | `Boolean-v7` | 38 | 19.6s |  |
| 12 | `Boolean-v8` | 38 | 0.4s |  |
| 13 | `Camera-v5` | 7 | 0.3s |  |
| 14 | `Color-v5` | 140 | 0.4s |  |
| 15 | `Color-v6` | 171 | 0.5s |  |
| 16 | `Color-v7` | 161 | 0.4s |  |
| 17 | `Color-v8` | 161 | 18.6s |  |
| 18 | `ColorTransform-v5` | 7 | 0.4s |  |
| 19 | `ColorTransform-v6` | 7 | 0.4s |  |
| 20 | `ColorTransform-v7` | 7 | 0.4s |  |
| 21 | `ColorTransform-v8` | 55 | 0.4s |  |
| 22 | `ContextMenu-v5` | 7 | 0.4s |  |
| 23 | `ContextMenu-v6` | 7 | 0.4s |  |
| 24 | `ContextMenu-v7` | 131 | 0.4s |  |
| 25 | `ContextMenu-v8` | 131 | 19.5s |  |
| 26 | `Error-v5` | 28 | 0.4s |  |
| 27 | `Error-v6` | 31 | 0.9s |  |
| 28 | `Error-v7` | 31 | 0.7s |  |
| 29 | `Error-v8` | 31 | 11.6s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.2s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.2s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.2s |  |
| 33 | `Global-v5` | 172 | 0.4s |  |
| 34 | `Global-v7` | 182 | 0.5s |  |
| 35 | `Global-v8` | 169 | 0.4s |  |
| 36 | `Instance-v5` | 52 | 0.4s |  |
| 37 | `Instance-v6` | 52 | 0.4s |  |
| 38 | `Instance-v7` | 52 | 0.4s |  |
| 39 | `Instance-v8` | 52 | 0.4s |  |
| 40 | `Key-v5` | 51 | 19.1s |  |
| 41 | `Key-v6` | 55 | 0.4s |  |
| 42 | `Key-v7` | 55 | 0.4s |  |
| 43 | `Key-v8` | 55 | 0.5s |  |
| 44 | `LoadVars-v5` | 8 | 19.4s |  |
| 45 | `LocalConnection-v5` | 7 | 18.5s |  |
| 46 | `LocalConnection-v6` | 58 | 0.4s |  |
| 47 | `LocalConnection-v7` | 58 | 0.4s |  |
| 48 | `LocalConnection-v8` | 58 | 0.4s |  |
| 49 | `Matrix-v5` | 7 | 18.6s |  |
| 50 | `Microphone-v5` | 6 | 0.4s |  |
| 51 | `Mouse-v5` | 13 | 18.9s |  |
| 52 | `Mouse-v6` | 21 | 0.4s |  |
| 53 | `Mouse-v7` | 21 | 0.7s |  |
| 54 | `Mouse-v8` | 21 | 0.4s |  |
| 55 | `MovieClipLoader-v5` | 6 | 18.8s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.4s |  |
| 57 | `NetConnection-v5` | 7 | 19.0s |  |
| 58 | `NetStream-v5` | 6 | 18.1s |  |
| 59 | `NetStream-v6` | 80 | 0.3s |  |
| 60 | `NetStream-v7` | 80 | 0.3s |  |
| 61 | `NetStream-v8` | 80 | 0.3s |  |
| 62 | `Number-v6` | 239 | 0.3s |  |
| 63 | `Number-v7` | 237 | 0.4s |  |
| 64 | `Number-v8` | 237 | 0.3s |  |
| 65 | `Point-v5` | 7 | 19.0s |  |
| 66 | `Point-v6` | 7 | 0.4s |  |
| 67 | `Point-v7` | 7 | 0.4s |  |
| 68 | `Point-v8` | 193 | 0.4s |  |
| 69 | `Random-v5` | 30 | 19.3s |  |
| 70 | `Random-v6` | 30 | 0.4s |  |
| 71 | `Random-v7` | 30 | 0.4s |  |
| 72 | `Random-v8` | 30 | 0.4s |  |
| 73 | `Rectangle-v5` | 7 | 0.4s |  |
| 74 | `Rectangle-v6` | 7 | 0.4s |  |
| 75 | `Rectangle-v7` | 7 | 0.4s |  |
| 76 | `Selection-v5` | 21 | 18.6s |  |
| 77 | `Stage-v5` | 38 | 18.7s |  |
| 78 | `System-v5` | 67 | 18.1s |  |
| 79 | `System-v6` | 100 | 0.3s |  |
| 80 | `System-v7` | 101 | 0.4s |  |
| 81 | `System-v8` | 101 | 0.3s |  |
| 82 | `TextFieldHTML-v5` | 6 | 18.7s |  |
| 83 | `TextFieldHTML-v6` | 37 | 0.5s |  |
| 84 | `TextFieldHTML-v7` | 37 | 0.5s |  |
| 85 | `TextFieldHTML-v8` | 37 | 0.7s |  |
| 86 | `TextFormat-v5` | 128 | 0.6s |  |
| 87 | `TextFormat-v6` | 128 | 0.4s |  |
| 88 | `TextSnapshot-v5` | 7 | 14.6s |  |
| 89 | `TextSnapshot-v6` | 173 | 0.4s |  |
| 90 | `TextSnapshot-v7` | 173 | 0.3s |  |
| 91 | `TextSnapshot-v8` | 173 | 0.3s |  |
| 92 | `Transform-v5` | 7 | 0.3s |  |
| 93 | `Transform-v6` | 7 | 0.3s |  |
| 94 | `Transform-v7` | 7 | 0.3s |  |
| 95 | `Try-v5` | 20 | 20.4s |  |
| 96 | `Try-v6` | 20 | 0.4s |  |
| 97 | `Try-v7` | 20 | 1.4s |  |
| 98 | `Try-v8` | 20 | 0.4s |  |
| 99 | `Video-v5` | 7 | 19.4s |  |
| 100 | `Video-v6` | 85 | 0.6s |  |
| 101 | `Video-v7` | 85 | 0.7s |  |
| 102 | `Video-v8` | 85 | 0.5s |  |
| 103 | `XMLSocket-v5` | 35 | 18.9s |  |
| 104 | `XMLSocket-v6` | 35 | 0.3s |  |
| 105 | `XMLSocket-v7` | 35 | 0.3s |  |
| 106 | `XMLSocket-v8` | 35 | 0.3s |  |
| 107 | `argstest-v5` | 4 | 0.3s |  |
| 108 | `case-v5` | 39 | 0.3s |  |
| 109 | `case-v6` | 73 | 0.5s |  |
| 110 | `case-v7` | 67 | 0.3s |  |
| 111 | `case-v8` | 67 | 0.3s |  |
| 112 | `delete-v5` | 60 | 15.3s |  |
| 113 | `delete-v6` | 60 | 0.3s |  |
| 114 | `delete-v7` | 60 | 0.3s |  |
| 115 | `delete-v8` | 60 | 0.3s |  |
| 116 | `enumerate-v5` | 6 | 0.3s |  |
| 117 | `enumerate-v6` | 49 | 0.3s |  |
| 118 | `enumerate-v7` | 49 | 0.3s |  |
| 119 | `enumerate-v8` | 49 | 0.3s |  |
| 120 | `flash-v5` | 10 | 18.8s |  |
| 121 | `flash-v6` | 10 | 0.4s |  |
| 122 | `flash-v7` | 10 | 0.4s |  |
| 123 | `flash-v8` | 41 | 19.3s |  |
| 124 | `swap-v5` | 7 | 18.4s |  |
| 125 | `swap-v6` | 7 | 0.4s |  |
| 126 | `swap-v7` | 7 | 0.4s |  |
| 127 | `swap-v8` | 7 | 0.4s |  |
| 128 | `targetPath-v5` | 12 | 0.4s |  |

## Ruffle-Matched Tests

**99 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 18.4s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.4s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.4s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.4s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 19.5s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.4s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.9s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.4s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.4s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.4s |  |
| 12 | `Date-v5` | 7 | 7 | 20.3s |  |
| 13 | `Date-v6` | 6 | 6 | 0.9s |  |
| 14 | `Date-v7` | 6 | 6 | 0.7s |  |
| 15 | `Date-v8` | 6 | 6 | 0.7s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 0.3s |  |
| 17 | `Function-v5` | 14 | 24 | 12.4s |  |
| 18 | `Function-v6` | 8 | 34 | 0.6s |  |
| 19 | `Function-v7` | 8 | 34 | 0.3s |  |
| 20 | `Function-v8` | 8 | 34 | 20.6s |  |
| 21 | `Global-v6` | 9 | 10 | 25.5s |  |
| 22 | `HitTest-v6` | 8 | 8 | 0.5s |  |
| 23 | `HitTest-v7` | 8 | 8 | 0.4s |  |
| 24 | `HitTest-v8` | 9 | 9 | 0.4s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 18.6s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 0.4s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 0.4s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 0.4s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 0.5s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 0.5s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 0.5s |  |
| 32 | `Math-v5` | 5 | 5 | 0.6s |  |
| 33 | `Math-v6` | 5 | 5 | 0.6s |  |
| 34 | `Math-v7` | 5 | 5 | 0.6s |  |
| 35 | `Math-v8` | 5 | 5 | 0.6s |  |
| 36 | `Matrix-v6` | 29 | 71 | 0.4s |  |
| 37 | `Matrix-v7` | 28 | 70 | 0.4s |  |
| 38 | `Matrix-v8` | 28 | 70 | 0.5s |  |
| 39 | `Microphone-v6` | 31 | 31 | 0.4s |  |
| 40 | `Microphone-v7` | 31 | 31 | 0.4s |  |
| 41 | `Microphone-v8` | 31 | 31 | 0.4s |  |
| 42 | `MovieClip-v5` | 25 | 226 | 19.5s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 0.4s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 0.5s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 0.4s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 0.5s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 0.4s |  |
| 48 | `Number-v5` | 8 | 13 | 0.4s |  |
| 49 | `Object-v5` | 3 | 7 | 19.6s |  |
| 50 | `Object-v6` | 9 | 29 | 0.7s |  |
| 51 | `Object-v7` | 8 | 20 | 0.7s |  |
| 52 | `Object-v8` | 8 | 20 | 0.7s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 0.5s |  |
| 54 | `Selection-v6` | 7 | 13 | 0.7s |  |
| 55 | `Selection-v7` | 7 | 13 | 0.5s |  |
| 56 | `Selection-v8` | 7 | 13 | 0.7s |  |
| 57 | `Sound-v5` | 16 | 16 | 19.1s |  |
| 58 | `Sound-v6` | 8 | 37 | 0.6s |  |
| 59 | `Sound-v7` | 8 | 37 | 0.6s |  |
| 60 | `Sound-v8` | 8 | 37 | 0.6s |  |
| 61 | `Stage-v6` | 14 | 14 | 20.6s |  |
| 62 | `Stage-v7` | 14 | 14 | 0.5s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.0s |  |
| 64 | `String-v5` | 19 | 21 | 1.6s |  |
| 65 | `String-v6` | 10 | 10 | 0.7s |  |
| 66 | `String-v7` | 10 | 10 | 0.9s |  |
| 67 | `String-v8` | 10 | 10 | 0.7s |  |
| 68 | `TextField-v5` | 3 | 3 | 0.3s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 0.5s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 19.2s |  |
| 71 | `Transform-v8` | 7 | 11 | 14.6s |  |
| 72 | `XML-v5` | 10 | 79 | 19.6s |  |
| 73 | `XML-v6` | 3 | 98 | 0.7s |  |
| 74 | `XML-v7` | 3 | 98 | 0.7s |  |
| 75 | `XML-v8` | 24 | 116 | 0.7s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 0.5s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 0.5s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 0.5s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 0.5s |  |
| 80 | `getvariable-v6` | 3 | 5 | 0.4s |  |
| 81 | `ops-v5` | 7 | 9 | 19.1s |  |
| 82 | `ops-v6` | 7 | 11 | 0.6s |  |
| 83 | `ops-v7` | 7 | 11 | 0.4s |  |
| 84 | `ops-v8` | 7 | 11 | 18.7s |  |
| 85 | `setProperty-v5` | 49 | 49 | 0.4s |  |
| 86 | `setProperty-v6` | 49 | 49 | 0.4s |  |
| 87 | `setProperty-v7` | 49 | 49 | 0.4s |  |
| 88 | `setProperty-v8` | 49 | 49 | 0.4s |  |
| 89 | `targetPath-v6` | 17 | 17 | 0.4s |  |
| 90 | `targetPath-v7` | 17 | 17 | 0.4s |  |
| 91 | `targetPath-v8` | 17 | 17 | 0.4s |  |
| 92 | `toString_valueOf-v5` | 34 | 34 | 18.6s |  |
| 93 | `toString_valueOf-v6` | 5 | 5 | 0.4s |  |
| 94 | `toString_valueOf-v7` | 5 | 5 | 0.4s |  |
| 95 | `toString_valueOf-v8` | 5 | 5 | 0.4s |  |
| 96 | `with-v5` | 42 | 42 | 0.4s |  |
| 97 | `with-v6` | 91 | 91 | 0.4s |  |
| 98 | `with-v7` | 91 | 91 | 0.4s |  |
| 99 | `with-v8` | 91 | 91 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |
| 2 | `getvariable-v7` | 95.3% | 61 | 64 | 3 |  |
| 3 | `getvariable-v8` | 95.3% | 61 | 64 | 3 |  |
| 4 | `getvariable-v5` | 94.8% | 55 | 58 | 3 |  |
| 5 | `array-v6` | 94.1% | 606 | 644 | 38 |  |
| 6 | `MovieClip-v6` | 90.3% | 845 | 936 | 91 |  |
| 7 | `array-v7` | 89.8% | 587 | 654 | 67 |  |
| 8 | `array-v8` | 89.8% | 587 | 654 | 67 |  |
| 9 | `MovieClip-v7` | 89.5% | 867 | 969 | 102 |  |
| 10 | `MovieClip-v8` | 87.7% | 953 | 1087 | 134 |  |
| 11 | `TextField-v6` | 81.5% | 444 | 545 | 101 |  |
| 12 | `TextField-v8` | 79.7% | 455 | 571 | 116 |  |
| 13 | `TextField-v7` | 79.5% | 453 | 570 | 117 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**16 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
| 2 | `getvariable-v7` | 95.3% | 61/64 | 64 | 64 |  |
| 3 | `getvariable-v8` | 95.3% | 61/64 | 64 | 64 |  |
| 4 | `getvariable-v5` | 94.8% | 55/58 | 58 | 58 |  |
| 5 | `array-v6` | 94.1% | 606/644 | 644 | 644 |  |
| 6 | `MovieClip-v6` | 90.3% | 845/936 | 921 | 936 |  |
| 7 | `array-v7` | 89.8% | 587/654 | 654 | 654 |  |
| 8 | `array-v8` | 89.8% | 587/654 | 654 | 654 |  |
| 9 | `MovieClip-v7` | 89.5% | 867/969 | 956 | 969 |  |
| 10 | `MovieClip-v8` | 87.7% | 953/1087 | 1074 | 1087 |  |
| 11 | `TextField-v6` | 81.5% | 444/545 | 545 | 545 |  |
| 12 | `TextField-v8` | 79.7% | 455/571 | 571 | 571 |  |
| 13 | `TextField-v7` | 79.5% | 453/570 | 570 | 570 |  |
| 14 | `argstest-v7` | 0.9% | 67/7301 | 7301 | 2061 |  |
| 15 | `argstest-v8` | 0.8% | 58/7663 | 7663 | 2434 |  |
| 16 | `argstest-v6` | 0.6% | 42/7301 | 7301 | 2192 |  |
