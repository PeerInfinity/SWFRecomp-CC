# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-29 00:05 UTC

**Git SHA**: `432dccb031`

**Run Duration**: 20m 9s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **122** (50.2%) |
| Ruffle-matched | 93 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **215** (88.5%) |
| Failing | 28 |
| Total expected lines | 38791 |
| Matching lines | 29488 (76.0%) |
| Mismatched lines | 9303 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 24 | 85.7% |
| Runtime Error | 4 | 14.3% |

## Passing Tests

**122 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.0s |  |
| 2 | `Accessibility-v6` | 19 | 3.0s |  |
| 3 | `Accessibility-v7` | 19 | 2.7s |  |
| 4 | `Accessibility-v8` | 19 | 2.2s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.9s |  |
| 6 | `BitmapData-v5` | 7 | 1.0s |  |
| 7 | `BitmapData-v6` | 7 | 1.0s |  |
| 8 | `BitmapData-v7` | 7 | 1.0s |  |
| 9 | `Boolean-v5` | 38 | 1.0s |  |
| 10 | `Boolean-v6` | 38 | 1.0s |  |
| 11 | `Boolean-v7` | 38 | 19.5s |  |
| 12 | `Boolean-v8` | 38 | 0.9s |  |
| 13 | `Camera-v5` | 7 | 1.0s |  |
| 14 | `Color-v5` | 140 | 1.0s |  |
| 15 | `Color-v6` | 171 | 1.0s |  |
| 16 | `Color-v7` | 161 | 0.9s |  |
| 17 | `Color-v8` | 161 | 19.2s |  |
| 18 | `ColorTransform-v5` | 7 | 0.8s |  |
| 19 | `ColorTransform-v6` | 7 | 0.8s |  |
| 20 | `ColorTransform-v7` | 7 | 0.8s |  |
| 21 | `ColorTransform-v8` | 55 | 0.8s |  |
| 22 | `ContextMenu-v5` | 7 | 0.8s |  |
| 23 | `ContextMenu-v6` | 7 | 0.8s |  |
| 24 | `ContextMenu-v7` | 131 | 0.9s |  |
| 25 | `ContextMenu-v8` | 131 | 19.4s |  |
| 26 | `Error-v5` | 28 | 1.0s |  |
| 27 | `Error-v6` | 31 | 1.0s |  |
| 28 | `Error-v7` | 31 | 1.0s |  |
| 29 | `Error-v8` | 31 | 18.9s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.9s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.9s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.9s |  |
| 33 | `Global-v5` | 172 | 1.1s |  |
| 34 | `Global-v7` | 182 | 1.1s |  |
| 35 | `Global-v8` | 169 | 1.1s |  |
| 36 | `Instance-v5` | 52 | 1.1s |  |
| 37 | `Instance-v6` | 52 | 1.0s |  |
| 38 | `Instance-v7` | 52 | 1.0s |  |
| 39 | `Instance-v8` | 52 | 1.0s |  |
| 40 | `Key-v5` | 51 | 20.5s |  |
| 41 | `Key-v6` | 55 | 1.0s |  |
| 42 | `Key-v7` | 55 | 1.0s |  |
| 43 | `Key-v8` | 55 | 1.0s |  |
| 44 | `LoadVars-v5` | 8 | 20.9s |  |
| 45 | `LocalConnection-v5` | 7 | 21.1s |  |
| 46 | `LocalConnection-v6` | 58 | 3.9s |  |
| 47 | `LocalConnection-v7` | 58 | 3.5s |  |
| 48 | `LocalConnection-v8` | 58 | 2.3s |  |
| 49 | `Matrix-v5` | 7 | 18.8s |  |
| 50 | `Microphone-v5` | 6 | 0.9s |  |
| 51 | `Mouse-v5` | 13 | 20.1s |  |
| 52 | `Mouse-v6` | 21 | 1.0s |  |
| 53 | `Mouse-v7` | 21 | 0.9s |  |
| 54 | `Mouse-v8` | 21 | 1.0s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.5s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.1s |  |
| 57 | `NetConnection-v5` | 7 | 20.8s |  |
| 58 | `NetStream-v5` | 6 | 19.2s |  |
| 59 | `NetStream-v6` | 80 | 0.9s |  |
| 60 | `NetStream-v7` | 80 | 0.9s |  |
| 61 | `NetStream-v8` | 80 | 0.9s |  |
| 62 | `Number-v6` | 239 | 0.9s |  |
| 63 | `Number-v7` | 237 | 1.0s |  |
| 64 | `Number-v8` | 237 | 1.1s |  |
| 65 | `Point-v5` | 7 | 20.1s |  |
| 66 | `Point-v6` | 7 | 0.9s |  |
| 67 | `Point-v7` | 7 | 1.0s |  |
| 68 | `Point-v8` | 193 | 1.1s |  |
| 69 | `Random-v5` | 30 | 20.7s |  |
| 70 | `Random-v6` | 30 | 0.9s |  |
| 71 | `Random-v7` | 30 | 0.9s |  |
| 72 | `Random-v8` | 30 | 0.9s |  |
| 73 | `Rectangle-v5` | 7 | 0.9s |  |
| 74 | `Rectangle-v6` | 7 | 0.8s |  |
| 75 | `Rectangle-v7` | 7 | 0.9s |  |
| 76 | `Selection-v5` | 21 | 18.7s |  |
| 77 | `Stage-v5` | 38 | 19.4s |  |
| 78 | `System-v5` | 67 | 19.9s |  |
| 79 | `System-v6` | 100 | 0.8s |  |
| 80 | `System-v7` | 101 | 0.8s |  |
| 81 | `System-v8` | 101 | 0.8s |  |
| 82 | `TextFieldHTML-v5` | 6 | 19.4s |  |
| 83 | `TextFieldHTML-v6` | 37 | 1.0s |  |
| 84 | `TextFieldHTML-v7` | 37 | 1.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.0s |  |
| 86 | `TextFormat-v5` | 128 | 1.0s |  |
| 87 | `TextFormat-v6` | 128 | 1.0s |  |
| 88 | `TextSnapshot-v5` | 7 | 19.4s |  |
| 89 | `TextSnapshot-v6` | 173 | 1.1s |  |
| 90 | `TextSnapshot-v7` | 173 | 1.1s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.1s |  |
| 92 | `Transform-v5` | 7 | 1.0s |  |
| 93 | `Transform-v6` | 7 | 1.0s |  |
| 94 | `Transform-v7` | 7 | 1.0s |  |
| 95 | `Try-v5` | 20 | 15.4s |  |
| 96 | `Try-v6` | 20 | 0.8s |  |
| 97 | `Try-v7` | 20 | 0.8s |  |
| 98 | `Try-v8` | 20 | 0.8s |  |
| 99 | `Video-v5` | 7 | 15.5s |  |
| 100 | `Video-v6` | 85 | 0.8s |  |
| 101 | `Video-v7` | 85 | 0.8s |  |
| 102 | `Video-v8` | 85 | 0.8s |  |
| 103 | `XMLSocket-v5` | 35 | 19.4s |  |
| 104 | `XMLSocket-v6` | 35 | 1.0s |  |
| 105 | `XMLSocket-v7` | 35 | 1.0s |  |
| 106 | `XMLSocket-v8` | 35 | 1.0s |  |
| 107 | `argstest-v5` | 4 | 1.0s |  |
| 108 | `case-v7` | 67 | 1.1s |  |
| 109 | `case-v8` | 67 | 1.2s |  |
| 110 | `enumerate-v5` | 6 | 1.0s |  |
| 111 | `enumerate-v6` | 49 | 1.0s |  |
| 112 | `enumerate-v7` | 49 | 1.0s |  |
| 113 | `enumerate-v8` | 49 | 1.0s |  |
| 114 | `flash-v5` | 10 | 19.3s |  |
| 115 | `flash-v6` | 10 | 1.0s |  |
| 116 | `flash-v7` | 10 | 1.0s |  |
| 117 | `flash-v8` | 41 | 19.6s |  |
| 118 | `swap-v5` | 7 | 19.0s |  |
| 119 | `swap-v6` | 7 | 0.9s |  |
| 120 | `swap-v7` | 7 | 0.9s |  |
| 121 | `swap-v8` | 7 | 0.9s |  |
| 122 | `targetPath-v5` | 12 | 0.9s |  |

## Ruffle-Matched Tests

**93 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 25.4s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.4s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 19.6s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 1.0s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.1s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 1.0s |  |
| 10 | `Camera-v7` | 57 | 57 | 1.0s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.0s |  |
| 12 | `Date-v5` | 7 | 7 | 19.7s |  |
| 13 | `Date-v6` | 6 | 6 | 1.3s |  |
| 14 | `Date-v7` | 6 | 6 | 1.3s |  |
| 15 | `Date-v8` | 6 | 6 | 1.3s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 1.0s |  |
| 17 | `Function-v5` | 14 | 24 | 19.9s |  |
| 18 | `Function-v6` | 8 | 34 | 1.1s |  |
| 19 | `Function-v7` | 8 | 34 | 1.1s |  |
| 20 | `Function-v8` | 8 | 34 | 20.3s |  |
| 21 | `Global-v6` | 9 | 10 | 19.9s |  |
| 22 | `HitTest-v6` | 8 | 8 | 1.0s |  |
| 23 | `HitTest-v7` | 8 | 8 | 1.1s |  |
| 24 | `HitTest-v8` | 9 | 9 | 1.0s |  |
| 25 | `Inheritance-v7` | 5 | 10 | 1.1s |  |
| 26 | `Inheritance-v8` | 5 | 10 | 1.1s |  |
| 27 | `LoadVars-v6` | 6 | 8 | 1.0s |  |
| 28 | `LoadVars-v7` | 6 | 8 | 1.0s |  |
| 29 | `LoadVars-v8` | 6 | 8 | 1.0s |  |
| 30 | `Math-v5` | 5 | 5 | 14.6s |  |
| 31 | `Math-v6` | 5 | 5 | 1.5s |  |
| 32 | `Math-v7` | 5 | 5 | 15.1s |  |
| 33 | `Math-v8` | 5 | 5 | 2.5s |  |
| 34 | `Matrix-v6` | 29 | 71 | 1.0s |  |
| 35 | `Matrix-v7` | 28 | 70 | 1.0s |  |
| 36 | `Matrix-v8` | 28 | 70 | 1.0s |  |
| 37 | `Microphone-v6` | 31 | 31 | 0.9s |  |
| 38 | `Microphone-v7` | 31 | 31 | 0.9s |  |
| 39 | `Microphone-v8` | 31 | 31 | 0.9s |  |
| 40 | `MovieClip-v5` | 25 | 226 | 20.7s |  |
| 41 | `MovieClipLoader-v7` | 118 | 118 | 1.1s |  |
| 42 | `MovieClipLoader-v8` | 118 | 118 | 1.1s |  |
| 43 | `NetConnection-v6` | 4 | 49 | 1.1s |  |
| 44 | `NetConnection-v7` | 4 | 45 | 1.1s |  |
| 45 | `NetConnection-v8` | 4 | 45 | 1.1s |  |
| 46 | `Number-v5` | 8 | 13 | 1.1s |  |
| 47 | `Object-v5` | 3 | 7 | 20.6s |  |
| 48 | `Object-v6` | 9 | 29 | 1.2s |  |
| 49 | `Object-v7` | 8 | 20 | 1.2s |  |
| 50 | `Object-v8` | 8 | 20 | 1.2s |  |
| 51 | `Rectangle-v8` | 21 | 21 | 0.9s |  |
| 52 | `Selection-v6` | 7 | 13 | 1.0s |  |
| 53 | `Selection-v7` | 7 | 13 | 0.9s |  |
| 54 | `Selection-v8` | 7 | 13 | 0.9s |  |
| 55 | `Sound-v5` | 16 | 16 | 19.0s |  |
| 56 | `Sound-v6` | 8 | 37 | 1.0s |  |
| 57 | `Sound-v7` | 8 | 37 | 1.1s |  |
| 58 | `Sound-v8` | 8 | 37 | 1.1s |  |
| 59 | `Stage-v6` | 14 | 14 | 19.5s |  |
| 60 | `Stage-v7` | 14 | 14 | 1.0s |  |
| 61 | `Stage-v8` | 14 | 14 | 1.0s |  |
| 62 | `String-v5` | 19 | 21 | 1.3s |  |
| 63 | `String-v6` | 10 | 10 | 1.3s |  |
| 64 | `String-v7` | 10 | 10 | 1.3s |  |
| 65 | `String-v8` | 10 | 10 | 1.3s |  |
| 66 | `TextField-v5` | 3 | 3 | 0.8s |  |
| 67 | `TextFormat-v7` | 38 | 40 | 1.1s |  |
| 68 | `TextFormat-v8` | 36 | 38 | 19.7s |  |
| 69 | `Transform-v8` | 7 | 11 | 19.5s |  |
| 70 | `XML-v5` | 10 | 79 | 20.0s |  |
| 71 | `XML-v6` | 3 | 98 | 1.2s |  |
| 72 | `XML-v7` | 3 | 98 | 1.2s |  |
| 73 | `XML-v8` | 24 | 116 | 1.2s |  |
| 74 | `XMLNode-v5` | 3 | 22 | 1.1s |  |
| 75 | `XMLNode-v6` | 3 | 22 | 1.1s |  |
| 76 | `XMLNode-v7` | 3 | 22 | 1.1s |  |
| 77 | `XMLNode-v8` | 3 | 22 | 1.1s |  |
| 78 | `getvariable-v6` | 3 | 5 | 1.0s |  |
| 79 | `ops-v5` | 7 | 9 | 18.8s |  |
| 80 | `ops-v6` | 7 | 11 | 1.1s |  |
| 81 | `ops-v7` | 7 | 11 | 1.0s |  |
| 82 | `ops-v8` | 7 | 11 | 18.5s |  |
| 83 | `setProperty-v5` | 49 | 49 | 0.9s |  |
| 84 | `setProperty-v6` | 49 | 49 | 0.9s |  |
| 85 | `setProperty-v7` | 49 | 49 | 0.9s |  |
| 86 | `setProperty-v8` | 49 | 49 | 0.9s |  |
| 87 | `targetPath-v6` | 17 | 17 | 0.9s |  |
| 88 | `targetPath-v7` | 17 | 17 | 0.9s |  |
| 89 | `targetPath-v8` | 17 | 17 | 0.9s |  |
| 90 | `toString_valueOf-v5` | 34 | 34 | 19.8s |  |
| 91 | `toString_valueOf-v6` | 5 | 5 | 1.1s |  |
| 92 | `toString_valueOf-v7` | 5 | 5 | 1.1s |  |
| 93 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**17 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |
| 2 | `getvariable-v7` | 95.3% | 61 | 64 | 3 |  |
| 3 | `getvariable-v8` | 95.3% | 61 | 64 | 3 |  |
| 4 | `getvariable-v5` | 94.8% | 55 | 58 | 3 |  |
| 5 | `array-v6` | 94.4% | 608 | 644 | 36 |  |
| 6 | `MovieClip-v6` | 90.3% | 845 | 936 | 91 |  |
| 7 | `array-v7` | 90.1% | 589 | 654 | 65 |  |
| 8 | `array-v8` | 90.1% | 589 | 654 | 65 |  |
| 9 | `MovieClip-v7` | 89.5% | 867 | 969 | 102 |  |
| 10 | `MovieClip-v8` | 87.7% | 953 | 1087 | 134 |  |
| 11 | `TextField-v6` | 83.7% | 456 | 545 | 89 |  |
| 12 | `TextField-v8` | 81.8% | 467 | 571 | 104 |  |
| 13 | `TextField-v7` | 81.6% | 465 | 570 | 105 |  |
| 14 | `delete-v5` | 68.9% | 42 | 61 | 19 |  |
| 15 | `delete-v6` | 68.9% | 42 | 61 | 19 |  |
| 16 | `delete-v7` | 68.9% | 42 | 61 | 19 |  |
| 17 | `delete-v8` | 68.9% | 42 | 61 | 19 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `Inheritance-v5` | exit code -6 | 20.5s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.7s |  |
| 3 | `case-v5` | exit code -6 (output matches) | 1.6s |  |
| 4 | `case-v6` | exit code -6 (output matches) | 1.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**24 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
| 2 | `getvariable-v7` | 95.3% | 61/64 | 64 | 64 |  |
| 3 | `getvariable-v8` | 95.3% | 61/64 | 64 | 64 |  |
| 4 | `getvariable-v5` | 94.8% | 55/58 | 58 | 58 |  |
| 5 | `array-v6` | 94.4% | 608/644 | 644 | 644 |  |
| 6 | `MovieClip-v6` | 90.3% | 845/936 | 921 | 936 |  |
| 7 | `array-v7` | 90.1% | 589/654 | 654 | 654 |  |
| 8 | `array-v8` | 90.1% | 589/654 | 654 | 654 |  |
| 9 | `MovieClip-v7` | 89.5% | 867/969 | 956 | 969 |  |
| 10 | `MovieClip-v8` | 87.7% | 953/1087 | 1074 | 1087 |  |
| 11 | `TextField-v6` | 83.7% | 456/545 | 545 | 545 |  |
| 12 | `TextField-v8` | 81.8% | 467/571 | 571 | 571 |  |
| 13 | `TextField-v7` | 81.6% | 465/570 | 570 | 570 |  |
| 14 | `delete-v5` | 68.9% | 42/61 | 60 | 61 |  |
| 15 | `delete-v6` | 68.9% | 42/61 | 60 | 61 |  |
| 16 | `delete-v7` | 68.9% | 42/61 | 60 | 61 |  |
| 17 | `delete-v8` | 68.9% | 42/61 | 60 | 61 |  |
| 18 | `with-v5` | 33.3% | 21/63 | 63 | 49 |  |
| 19 | `with-v6` | 20.2% | 23/114 | 114 | 107 |  |
| 20 | `with-v7` | 20.2% | 23/114 | 114 | 107 |  |
| 21 | `with-v8` | 20.2% | 23/114 | 114 | 107 |  |
| 22 | `argstest-v7` | 0.9% | 67/7301 | 7301 | 2061 |  |
| 23 | `argstest-v8` | 0.8% | 58/7663 | 7663 | 2434 |  |
| 24 | `argstest-v6` | 0.6% | 42/7301 | 7301 | 2192 |  |
