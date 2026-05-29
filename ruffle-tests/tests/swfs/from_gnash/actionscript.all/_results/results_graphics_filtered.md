# Ruffle Test Results (Filtered)

**Date**: 2026-05-29 23:01 UTC

**Git SHA**: `55d725fb0c`

**Run Duration**: 29m 32s

**Filtered**: 6 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 237 |
| Passing | **127** (53.6%) |
| Ruffle-matched | 96 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **223** (94.1%) |
| Failing | 14 |
| Total expected lines | 31918 |
| Matching lines | 29486 (92.4%) |
| Mismatched lines | 2432 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 71.4% |
| Runtime Error | 4 | 28.6% |

## Passing Tests

**127 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.1s |  |
| 2 | `Accessibility-v6` | 19 | 1.1s |  |
| 3 | `Accessibility-v7` | 19 | 1.1s |  |
| 4 | `Accessibility-v8` | 19 | 1.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.1s |  |
| 6 | `BitmapData-v5` | 7 | 0.8s |  |
| 7 | `BitmapData-v6` | 7 | 0.8s |  |
| 8 | `BitmapData-v7` | 7 | 0.8s |  |
| 9 | `Boolean-v5` | 38 | 0.9s |  |
| 10 | `Boolean-v6` | 38 | 0.8s |  |
| 11 | `Boolean-v7` | 38 | 21.2s |  |
| 12 | `Boolean-v8` | 38 | 1.1s |  |
| 13 | `Camera-v5` | 7 | 1.1s |  |
| 14 | `Color-v5` | 140 | 1.1s |  |
| 15 | `Color-v6` | 171 | 1.2s |  |
| 16 | `Color-v7` | 161 | 1.2s |  |
| 17 | `Color-v8` | 161 | 19.6s |  |
| 18 | `ColorTransform-v5` | 7 | 1.0s |  |
| 19 | `ColorTransform-v6` | 7 | 0.9s |  |
| 20 | `ColorTransform-v7` | 7 | 1.0s |  |
| 21 | `ColorTransform-v8` | 55 | 1.0s |  |
| 22 | `ContextMenu-v5` | 7 | 1.0s |  |
| 23 | `ContextMenu-v6` | 7 | 1.0s |  |
| 24 | `ContextMenu-v7` | 131 | 1.1s |  |
| 25 | `ContextMenu-v8` | 131 | 24.9s |  |
| 26 | `Error-v5` | 28 | 2.9s |  |
| 27 | `Error-v6` | 31 | 3.0s |  |
| 28 | `Error-v7` | 31 | 2.6s |  |
| 29 | `Error-v8` | 31 | 23.7s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.8s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.5s |  |
| 33 | `Global-v5` | 172 | 8.1s |  |
| 34 | `Global-v7` | 182 | 8.3s |  |
| 35 | `Global-v8` | 169 | 7.7s |  |
| 36 | `Instance-v5` | 52 | 1.3s |  |
| 37 | `Instance-v6` | 52 | 1.1s |  |
| 38 | `Instance-v7` | 52 | 1.1s |  |
| 39 | `Instance-v8` | 52 | 1.4s |  |
| 40 | `Key-v5` | 51 | 22.0s |  |
| 41 | `Key-v6` | 55 | 3.5s |  |
| 42 | `Key-v7` | 55 | 3.2s |  |
| 43 | `Key-v8` | 55 | 2.0s |  |
| 44 | `LoadVars-v5` | 8 | 21.6s |  |
| 45 | `LocalConnection-v5` | 7 | 19.4s |  |
| 46 | `LocalConnection-v6` | 58 | 0.9s |  |
| 47 | `LocalConnection-v7` | 58 | 0.9s |  |
| 48 | `LocalConnection-v8` | 58 | 0.9s |  |
| 49 | `Matrix-v5` | 7 | 21.4s |  |
| 50 | `Microphone-v5` | 6 | 2.5s |  |
| 51 | `Mouse-v5` | 13 | 20.7s |  |
| 52 | `Mouse-v6` | 21 | 2.8s |  |
| 53 | `Mouse-v7` | 21 | 2.4s |  |
| 54 | `Mouse-v8` | 21 | 2.0s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.4s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.3s |  |
| 57 | `NetConnection-v5` | 7 | 21.0s |  |
| 58 | `NetStream-v5` | 6 | 19.0s |  |
| 59 | `NetStream-v6` | 80 | 1.0s |  |
| 60 | `NetStream-v7` | 80 | 1.0s |  |
| 61 | `NetStream-v8` | 80 | 1.0s |  |
| 62 | `Number-v6` | 239 | 1.1s |  |
| 63 | `Number-v7` | 237 | 1.1s |  |
| 64 | `Number-v8` | 237 | 1.0s |  |
| 65 | `Point-v5` | 7 | 19.5s |  |
| 66 | `Point-v6` | 7 | 0.9s |  |
| 67 | `Point-v7` | 7 | 1.0s |  |
| 68 | `Point-v8` | 193 | 1.1s |  |
| 69 | `Random-v5` | 30 | 17.4s |  |
| 70 | `Random-v6` | 30 | 1.0s |  |
| 71 | `Random-v7` | 30 | 2.3s |  |
| 72 | `Random-v8` | 30 | 1.7s |  |
| 73 | `Rectangle-v5` | 7 | 2.1s |  |
| 74 | `Rectangle-v6` | 7 | 1.0s |  |
| 75 | `Rectangle-v7` | 7 | 1.8s |  |
| 76 | `Selection-v5` | 21 | 21.4s |  |
| 77 | `Stage-v5` | 38 | 22.6s |  |
| 78 | `System-v5` | 67 | 18.7s |  |
| 79 | `System-v6` | 100 | 4.0s |  |
| 80 | `System-v7` | 101 | 4.3s |  |
| 81 | `System-v8` | 101 | 1.8s |  |
| 82 | `TextFieldHTML-v5` | 6 | 19.4s |  |
| 83 | `TextFieldHTML-v6` | 37 | 1.0s |  |
| 84 | `TextFieldHTML-v7` | 37 | 1.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.0s |  |
| 86 | `TextFormat-v5` | 128 | 1.0s |  |
| 87 | `TextFormat-v6` | 128 | 1.2s |  |
| 88 | `TextSnapshot-v5` | 7 | 20.8s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.4s |  |
| 90 | `TextSnapshot-v7` | 173 | 7.9s |  |
| 91 | `TextSnapshot-v8` | 173 | 2.1s |  |
| 92 | `Transform-v5` | 7 | 2.5s |  |
| 93 | `Transform-v6` | 7 | 2.0s |  |
| 94 | `Transform-v7` | 7 | 2.2s |  |
| 95 | `Try-v5` | 20 | 21.4s |  |
| 96 | `Try-v6` | 20 | 1.2s |  |
| 97 | `Try-v7` | 20 | 3.3s |  |
| 98 | `Try-v8` | 20 | 2.0s |  |
| 99 | `Video-v5` | 7 | 20.5s |  |
| 100 | `Video-v6` | 85 | 4.1s |  |
| 101 | `Video-v7` | 85 | 3.7s |  |
| 102 | `Video-v8` | 85 | 2.1s |  |
| 103 | `XMLSocket-v5` | 35 | 19.4s |  |
| 104 | `XMLSocket-v6` | 35 | 1.0s |  |
| 105 | `XMLSocket-v7` | 35 | 1.0s |  |
| 106 | `XMLSocket-v8` | 35 | 1.0s |  |
| 107 | `argstest-v5` | 4 | 1.0s |  |
| 108 | `case-v7` | 67 | 1.1s |  |
| 109 | `case-v8` | 67 | 1.1s |  |
| 110 | `delete-v5` | 61 | 22.6s |  |
| 111 | `delete-v6` | 61 | 3.3s |  |
| 112 | `delete-v7` | 61 | 3.5s |  |
| 113 | `delete-v8` | 61 | 2.4s |  |
| 114 | `enumerate-v5` | 6 | 2.8s |  |
| 115 | `enumerate-v6` | 49 | 3.9s |  |
| 116 | `enumerate-v7` | 49 | 3.5s |  |
| 117 | `enumerate-v8` | 49 | 2.3s |  |
| 118 | `flash-v5` | 10 | 19.6s |  |
| 119 | `flash-v6` | 10 | 1.0s |  |
| 120 | `flash-v7` | 10 | 1.0s |  |
| 121 | `flash-v8` | 41 | 19.7s |  |
| 122 | `getvariable-v6` | 64 | 1.1s |  |
| 123 | `swap-v5` | 7 | 21.1s |  |
| 124 | `swap-v6` | 7 | 1.0s |  |
| 125 | `swap-v7` | 7 | 2.0s |  |
| 126 | `swap-v8` | 7 | 1.9s |  |
| 127 | `targetPath-v5` | 12 | 2.5s |  |

## Ruffle-Matched Tests

**96 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 20.4s |  |
| 2 | `ASnative-v6` | 40 | 40 | 1.1s |  |
| 3 | `ASnative-v7` | 40 | 40 | 1.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.1s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 15.8s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.9s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.3s |  |
| 9 | `Camera-v6` | 57 | 57 | 1.1s |  |
| 10 | `Camera-v7` | 57 | 57 | 1.1s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 12 | `Date-v5` | 7 | 7 | 33.2s |  |
| 13 | `Date-v6` | 6 | 6 | 14.8s |  |
| 14 | `Date-v7` | 6 | 6 | 15.4s |  |
| 15 | `Date-v8` | 6 | 6 | 2.3s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 6.1s |  |
| 17 | `Function-v5` | 14 | 24 | 27.1s |  |
| 18 | `Function-v6` | 8 | 34 | 11.1s |  |
| 19 | `Function-v7` | 8 | 34 | 11.4s |  |
| 20 | `Function-v8` | 8 | 34 | 29.9s |  |
| 21 | `Global-v6` | 9 | 10 | 28.3s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.8s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.4s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.3s |  |
| 25 | `Inheritance-v7` | 5 | 10 | 1.2s |  |
| 26 | `Inheritance-v8` | 5 | 10 | 1.1s |  |
| 27 | `LoadVars-v6` | 6 | 8 | 6.2s |  |
| 28 | `LoadVars-v7` | 6 | 8 | 5.8s |  |
| 29 | `LoadVars-v8` | 6 | 8 | 2.8s |  |
| 30 | `Math-v5` | 5 | 5 | 1.0s |  |
| 31 | `Math-v6` | 5 | 5 | 0.8s |  |
| 32 | `Math-v7` | 5 | 5 | 1.0s |  |
| 33 | `Math-v8` | 5 | 5 | 1.0s |  |
| 34 | `Matrix-v6` | 29 | 71 | 7.8s |  |
| 35 | `Matrix-v7` | 28 | 70 | 7.9s |  |
| 36 | `Matrix-v8` | 28 | 70 | 2.1s |  |
| 37 | `Microphone-v6` | 31 | 31 | 4.0s |  |
| 38 | `Microphone-v7` | 31 | 31 | 3.7s |  |
| 39 | `Microphone-v8` | 31 | 31 | 2.0s |  |
| 40 | `MovieClip-v5` | 24 | 226 | 31.7s |  |
| 41 | `MovieClipLoader-v7` | 118 | 118 | 4.6s |  |
| 42 | `MovieClipLoader-v8` | 118 | 118 | 3.2s |  |
| 43 | `NetConnection-v6` | 4 | 49 | 5.7s |  |
| 44 | `NetConnection-v7` | 4 | 45 | 5.7s |  |
| 45 | `NetConnection-v8` | 4 | 45 | 2.3s |  |
| 46 | `Number-v5` | 8 | 13 | 1.1s |  |
| 47 | `Object-v5` | 3 | 7 | 19.5s |  |
| 48 | `Object-v6` | 9 | 29 | 1.2s |  |
| 49 | `Object-v7` | 8 | 20 | 1.2s |  |
| 50 | `Object-v8` | 8 | 20 | 1.2s |  |
| 51 | `Rectangle-v8` | 21 | 21 | 6.3s |  |
| 52 | `Selection-v6` | 7 | 13 | 5.9s |  |
| 53 | `Selection-v7` | 7 | 13 | 5.6s |  |
| 54 | `Selection-v8` | 7 | 13 | 2.1s |  |
| 55 | `Sound-v5` | 16 | 16 | 24.6s |  |
| 56 | `Sound-v6` | 8 | 37 | 5.9s |  |
| 57 | `Sound-v7` | 8 | 37 | 5.6s |  |
| 58 | `Sound-v8` | 8 | 37 | 2.4s |  |
| 59 | `Stage-v6` | 14 | 14 | 23.6s |  |
| 60 | `Stage-v7` | 14 | 14 | 3.7s |  |
| 61 | `Stage-v8` | 14 | 14 | 2.5s |  |
| 62 | `String-v5` | 19 | 21 | 17.8s |  |
| 63 | `String-v6` | 10 | 10 | 18.8s |  |
| 64 | `String-v7` | 10 | 10 | 18.4s |  |
| 65 | `String-v8` | 10 | 10 | 2.7s |  |
| 66 | `TextField-v5` | 3 | 3 | 2.3s |  |
| 67 | `TextFormat-v7` | 38 | 40 | 1.1s |  |
| 68 | `TextFormat-v8` | 36 | 38 | 19.5s |  |
| 69 | `Transform-v8` | 7 | 11 | 23.9s |  |
| 70 | `XML-v5` | 10 | 79 | 19.7s |  |
| 71 | `XML-v6` | 3 | 98 | 1.4s |  |
| 72 | `XML-v7` | 3 | 98 | 1.4s |  |
| 73 | `XML-v8` | 24 | 116 | 1.4s |  |
| 74 | `XMLNode-v5` | 3 | 22 | 1.1s |  |
| 75 | `XMLNode-v6` | 3 | 22 | 1.1s |  |
| 76 | `XMLNode-v7` | 3 | 22 | 1.0s |  |
| 77 | `XMLNode-v8` | 3 | 22 | 1.1s |  |
| 78 | `ops-v5` | 7 | 9 | 19.9s |  |
| 79 | `ops-v6` | 7 | 11 | 1.0s |  |
| 80 | `ops-v7` | 7 | 11 | 1.0s |  |
| 81 | `ops-v8` | 7 | 11 | 19.4s |  |
| 82 | `setProperty-v5` | 49 | 49 | 0.9s |  |
| 83 | `setProperty-v6` | 49 | 49 | 0.8s |  |
| 84 | `setProperty-v7` | 49 | 49 | 0.9s |  |
| 85 | `setProperty-v8` | 49 | 49 | 0.8s |  |
| 86 | `targetPath-v6` | 17 | 17 | 2.7s |  |
| 87 | `targetPath-v7` | 17 | 17 | 2.3s |  |
| 88 | `targetPath-v8` | 17 | 17 | 1.9s |  |
| 89 | `toString_valueOf-v5` | 34 | 34 | 20.7s |  |
| 90 | `toString_valueOf-v6` | 5 | 5 | 1.1s |  |
| 91 | `toString_valueOf-v7` | 5 | 5 | 1.1s |  |
| 92 | `toString_valueOf-v8` | 5 | 5 | 1.2s |  |
| 93 | `with-v5` | 3 | 3 | 1.1s |  |
| 94 | `with-v6` | 43 | 43 | 1.1s |  |
| 95 | `with-v7` | 43 | 43 | 1.1s |  |
| 96 | `with-v8` | 43 | 43 | 1.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**10 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |
| 2 | `array-v6` | 94.4% | 608 | 644 | 36 |  |
| 3 | `MovieClip-v6` | 94.0% | 880 | 936 | 56 |  |
| 4 | `MovieClip-v7` | 93.1% | 902 | 969 | 67 |  |
| 5 | `MovieClip-v8` | 90.9% | 988 | 1087 | 99 |  |
| 6 | `array-v7` | 90.1% | 589 | 654 | 65 |  |
| 7 | `array-v8` | 90.1% | 589 | 654 | 65 |  |
| 8 | `TextField-v6` | 83.7% | 456 | 545 | 89 |  |
| 9 | `TextField-v8` | 81.8% | 467 | 571 | 104 |  |
| 10 | `TextField-v7` | 81.6% | 465 | 570 | 105 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `Inheritance-v5` | exit code -6 | 20.9s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.8s |  |
| 3 | `case-v5` | exit code -6 (output matches) | 1.6s |  |
| 4 | `case-v6` | exit code -6 (output matches) | 1.7s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**10 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
| 2 | `array-v6` | 94.4% | 608/644 | 644 | 644 |  |
| 3 | `MovieClip-v6` | 94.0% | 880/936 | 921 | 936 |  |
| 4 | `MovieClip-v7` | 93.1% | 902/969 | 956 | 969 |  |
| 5 | `MovieClip-v8` | 90.9% | 988/1087 | 1074 | 1087 |  |
| 6 | `array-v7` | 90.1% | 589/654 | 654 | 654 |  |
| 7 | `array-v8` | 90.1% | 589/654 | 654 | 654 |  |
| 8 | `TextField-v6` | 83.7% | 456/545 | 545 | 545 |  |
| 9 | `TextField-v8` | 81.8% | 467/571 | 571 | 571 |  |
| 10 | `TextField-v7` | 81.6% | 465/570 | 570 | 570 |  |
