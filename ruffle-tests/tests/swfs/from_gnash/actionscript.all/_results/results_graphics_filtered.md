# Ruffle Test Results (Filtered)

**Date**: 2026-05-30 03:47 UTC

**Git SHA**: `59c1b2c3db`

**Run Duration**: 25m 15s

**Filtered**: 6 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 237 |
| Passing | **128** (54.0%) |
| Ruffle-matched | 96 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **224** (94.5%) |
| Failing | 13 |
| Total expected lines | 31918 |
| Matching lines | 29486 (92.4%) |
| Mismatched lines | 2432 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 76.9% |
| Runtime Error | 3 | 23.1% |

## Passing Tests

**128 tests passing**

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
| 10 | `Boolean-v6` | 38 | 0.9s |  |
| 11 | `Boolean-v7` | 38 | 19.3s |  |
| 12 | `Boolean-v8` | 38 | 0.9s |  |
| 13 | `Camera-v5` | 7 | 0.9s |  |
| 14 | `Color-v5` | 140 | 1.0s |  |
| 15 | `Color-v6` | 171 | 1.0s |  |
| 16 | `Color-v7` | 161 | 1.0s |  |
| 17 | `Color-v8` | 161 | 15.6s |  |
| 18 | `ColorTransform-v5` | 7 | 0.9s |  |
| 19 | `ColorTransform-v6` | 7 | 0.8s |  |
| 20 | `ColorTransform-v7` | 7 | 0.9s |  |
| 21 | `ColorTransform-v8` | 55 | 0.9s |  |
| 22 | `ContextMenu-v5` | 7 | 0.9s |  |
| 23 | `ContextMenu-v6` | 7 | 0.8s |  |
| 24 | `ContextMenu-v7` | 131 | 0.9s |  |
| 25 | `ContextMenu-v8` | 131 | 20.1s |  |
| 26 | `Error-v5` | 28 | 1.1s |  |
| 27 | `Error-v6` | 31 | 1.1s |  |
| 28 | `Error-v7` | 31 | 1.1s |  |
| 29 | `Error-v8` | 31 | 19.4s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 1.1s |  |
| 32 | `ExternalInterface-v7` | 55 | 1.1s |  |
| 33 | `Global-v5` | 172 | 1.1s |  |
| 34 | `Global-v7` | 182 | 1.1s |  |
| 35 | `Global-v8` | 169 | 1.1s |  |
| 36 | `Instance-v5` | 52 | 1.1s |  |
| 37 | `Instance-v6` | 52 | 1.1s |  |
| 38 | `Instance-v7` | 52 | 1.2s |  |
| 39 | `Instance-v8` | 52 | 1.2s |  |
| 40 | `Key-v5` | 51 | 19.7s |  |
| 41 | `Key-v6` | 55 | 1.1s |  |
| 42 | `Key-v7` | 55 | 1.1s |  |
| 43 | `Key-v8` | 55 | 1.1s |  |
| 44 | `LoadVars-v5` | 8 | 19.9s |  |
| 45 | `LocalConnection-v5` | 7 | 18.9s |  |
| 46 | `LocalConnection-v6` | 58 | 1.0s |  |
| 47 | `LocalConnection-v7` | 58 | 1.0s |  |
| 48 | `LocalConnection-v8` | 58 | 1.0s |  |
| 49 | `Matrix-v5` | 7 | 15.2s |  |
| 50 | `Microphone-v5` | 6 | 0.8s |  |
| 51 | `Mouse-v5` | 13 | 20.6s |  |
| 52 | `Mouse-v6` | 21 | 2.5s |  |
| 53 | `Mouse-v7` | 21 | 2.2s |  |
| 54 | `Mouse-v8` | 21 | 1.8s |  |
| 55 | `MovieClipLoader-v5` | 6 | 19.8s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.0s |  |
| 57 | `NetConnection-v5` | 7 | 19.6s |  |
| 58 | `NetStream-v5` | 6 | 15.5s |  |
| 59 | `NetStream-v6` | 80 | 0.9s |  |
| 60 | `NetStream-v7` | 80 | 0.8s |  |
| 61 | `NetStream-v8` | 80 | 0.9s |  |
| 62 | `Number-v6` | 239 | 1.0s |  |
| 63 | `Number-v7` | 237 | 0.9s |  |
| 64 | `Number-v8` | 237 | 0.9s |  |
| 65 | `Point-v5` | 7 | 19.3s |  |
| 66 | `Point-v6` | 7 | 0.9s |  |
| 67 | `Point-v7` | 7 | 1.0s |  |
| 68 | `Point-v8` | 193 | 1.1s |  |
| 69 | `Random-v5` | 30 | 19.3s |  |
| 70 | `Random-v6` | 30 | 1.0s |  |
| 71 | `Random-v7` | 30 | 1.0s |  |
| 72 | `Random-v8` | 30 | 1.0s |  |
| 73 | `Rectangle-v5` | 7 | 1.0s |  |
| 74 | `Rectangle-v6` | 7 | 0.9s |  |
| 75 | `Rectangle-v7` | 7 | 1.0s |  |
| 76 | `Selection-v5` | 21 | 20.0s |  |
| 77 | `Stage-v5` | 38 | 21.8s |  |
| 78 | `System-v5` | 67 | 23.1s |  |
| 79 | `System-v6` | 100 | 4.8s |  |
| 80 | `System-v7` | 101 | 4.9s |  |
| 81 | `System-v8` | 101 | 2.2s |  |
| 82 | `TextFieldHTML-v5` | 6 | 19.6s |  |
| 83 | `TextFieldHTML-v6` | 37 | 1.0s |  |
| 84 | `TextFieldHTML-v7` | 37 | 1.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 0.9s |  |
| 86 | `TextFormat-v5` | 128 | 1.0s |  |
| 87 | `TextFormat-v6` | 128 | 0.8s |  |
| 88 | `TextSnapshot-v5` | 7 | 21.2s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.7s |  |
| 90 | `TextSnapshot-v7` | 173 | 8.3s |  |
| 91 | `TextSnapshot-v8` | 173 | 2.2s |  |
| 92 | `Transform-v5` | 7 | 2.6s |  |
| 93 | `Transform-v6` | 7 | 2.1s |  |
| 94 | `Transform-v7` | 7 | 2.3s |  |
| 95 | `Try-v5` | 20 | 23.0s |  |
| 96 | `Try-v6` | 20 | 1.3s |  |
| 97 | `Try-v7` | 20 | 3.5s |  |
| 98 | `Try-v8` | 20 | 2.2s |  |
| 99 | `Video-v5` | 7 | 22.1s |  |
| 100 | `Video-v6` | 85 | 4.4s |  |
| 101 | `Video-v7` | 85 | 4.0s |  |
| 102 | `Video-v8` | 85 | 2.2s |  |
| 103 | `XMLSocket-v5` | 35 | 20.4s |  |
| 104 | `XMLSocket-v6` | 35 | 1.2s |  |
| 105 | `XMLSocket-v7` | 35 | 1.1s |  |
| 106 | `XMLSocket-v8` | 35 | 1.2s |  |
| 107 | `argstest-v5` | 4 | 1.1s |  |
| 108 | `case-v5` | 39 | 0.9s |  |
| 109 | `case-v7` | 67 | 0.9s |  |
| 110 | `case-v8` | 67 | 0.9s |  |
| 111 | `delete-v5` | 61 | 22.0s |  |
| 112 | `delete-v6` | 61 | 3.1s |  |
| 113 | `delete-v7` | 61 | 3.3s |  |
| 114 | `delete-v8` | 61 | 2.3s |  |
| 115 | `enumerate-v5` | 6 | 2.6s |  |
| 116 | `enumerate-v6` | 49 | 3.7s |  |
| 117 | `enumerate-v7` | 49 | 3.3s |  |
| 118 | `enumerate-v8` | 49 | 2.1s |  |
| 119 | `flash-v5` | 10 | 19.7s |  |
| 120 | `flash-v6` | 10 | 1.2s |  |
| 121 | `flash-v7` | 10 | 1.2s |  |
| 122 | `flash-v8` | 41 | 20.4s |  |
| 123 | `getvariable-v6` | 64 | 1.2s |  |
| 124 | `swap-v5` | 7 | 17.7s |  |
| 125 | `swap-v6` | 7 | 1.0s |  |
| 126 | `swap-v7` | 7 | 1.9s |  |
| 127 | `swap-v8` | 7 | 1.8s |  |
| 128 | `targetPath-v5` | 12 | 2.3s |  |

## Ruffle-Matched Tests

**96 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 20.0s |  |
| 2 | `ASnative-v6` | 40 | 40 | 1.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 1.1s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.1s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 19.1s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.9s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.3s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.9s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.9s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.9s |  |
| 12 | `Date-v5` | 7 | 7 | 20.6s |  |
| 13 | `Date-v6` | 6 | 6 | 1.4s |  |
| 14 | `Date-v7` | 6 | 6 | 1.4s |  |
| 15 | `Date-v8` | 6 | 6 | 1.4s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 1.1s |  |
| 17 | `Function-v5` | 14 | 24 | 22.2s |  |
| 18 | `Function-v6` | 8 | 34 | 1.2s |  |
| 19 | `Function-v7` | 8 | 34 | 1.3s |  |
| 20 | `Function-v8` | 8 | 34 | 19.9s |  |
| 21 | `Global-v6` | 9 | 10 | 19.4s |  |
| 22 | `HitTest-v6` | 8 | 8 | 1.0s |  |
| 23 | `HitTest-v7` | 8 | 8 | 1.1s |  |
| 24 | `HitTest-v8` | 9 | 9 | 1.1s |  |
| 25 | `Inheritance-v7` | 5 | 10 | 1.2s |  |
| 26 | `Inheritance-v8` | 5 | 10 | 1.2s |  |
| 27 | `LoadVars-v6` | 6 | 8 | 1.1s |  |
| 28 | `LoadVars-v7` | 6 | 8 | 1.1s |  |
| 29 | `LoadVars-v8` | 6 | 8 | 1.1s |  |
| 30 | `Math-v5` | 5 | 5 | 1.2s |  |
| 31 | `Math-v6` | 5 | 5 | 1.1s |  |
| 32 | `Math-v7` | 5 | 5 | 1.2s |  |
| 33 | `Math-v8` | 5 | 5 | 1.2s |  |
| 34 | `Matrix-v6` | 29 | 71 | 0.9s |  |
| 35 | `Matrix-v7` | 28 | 70 | 0.9s |  |
| 36 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 37 | `Microphone-v6` | 31 | 31 | 0.9s |  |
| 38 | `Microphone-v7` | 31 | 31 | 0.9s |  |
| 39 | `Microphone-v8` | 31 | 31 | 0.9s |  |
| 40 | `MovieClip-v5` | 24 | 226 | 31.0s |  |
| 41 | `MovieClipLoader-v7` | 118 | 118 | 1.1s |  |
| 42 | `MovieClipLoader-v8` | 118 | 118 | 1.1s |  |
| 43 | `NetConnection-v6` | 4 | 49 | 1.1s |  |
| 44 | `NetConnection-v7` | 4 | 45 | 1.1s |  |
| 45 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 46 | `Number-v5` | 8 | 13 | 1.0s |  |
| 47 | `Object-v5` | 3 | 7 | 19.6s |  |
| 48 | `Object-v6` | 9 | 29 | 1.2s |  |
| 49 | `Object-v7` | 8 | 20 | 1.2s |  |
| 50 | `Object-v8` | 8 | 20 | 1.2s |  |
| 51 | `Rectangle-v8` | 21 | 21 | 1.0s |  |
| 52 | `Selection-v6` | 7 | 13 | 5.1s |  |
| 53 | `Selection-v7` | 7 | 13 | 4.8s |  |
| 54 | `Selection-v8` | 7 | 13 | 1.8s |  |
| 55 | `Sound-v5` | 16 | 16 | 22.7s |  |
| 56 | `Sound-v6` | 8 | 37 | 5.2s |  |
| 57 | `Sound-v7` | 8 | 37 | 4.9s |  |
| 58 | `Sound-v8` | 8 | 37 | 2.1s |  |
| 59 | `Stage-v6` | 14 | 14 | 22.5s |  |
| 60 | `Stage-v7` | 14 | 14 | 3.5s |  |
| 61 | `Stage-v8` | 14 | 14 | 2.4s |  |
| 62 | `String-v5` | 19 | 21 | 16.9s |  |
| 63 | `String-v6` | 10 | 10 | 17.8s |  |
| 64 | `String-v7` | 10 | 10 | 17.6s |  |
| 65 | `String-v8` | 10 | 10 | 2.7s |  |
| 66 | `TextField-v5` | 3 | 3 | 2.9s |  |
| 67 | `TextFormat-v7` | 38 | 40 | 1.0s |  |
| 68 | `TextFormat-v8` | 36 | 38 | 19.3s |  |
| 69 | `Transform-v8` | 7 | 11 | 25.1s |  |
| 70 | `XML-v5` | 10 | 79 | 20.1s |  |
| 71 | `XML-v6` | 3 | 98 | 1.5s |  |
| 72 | `XML-v7` | 3 | 98 | 1.5s |  |
| 73 | `XML-v8` | 24 | 116 | 1.5s |  |
| 74 | `XMLNode-v5` | 3 | 22 | 1.3s |  |
| 75 | `XMLNode-v6` | 3 | 22 | 1.2s |  |
| 76 | `XMLNode-v7` | 3 | 22 | 1.0s |  |
| 77 | `XMLNode-v8` | 3 | 22 | 1.3s |  |
| 78 | `ops-v5` | 7 | 9 | 19.9s |  |
| 79 | `ops-v6` | 7 | 11 | 1.2s |  |
| 80 | `ops-v7` | 7 | 11 | 1.3s |  |
| 81 | `ops-v8` | 7 | 11 | 19.4s |  |
| 82 | `setProperty-v5` | 49 | 49 | 1.1s |  |
| 83 | `setProperty-v6` | 49 | 49 | 1.1s |  |
| 84 | `setProperty-v7` | 49 | 49 | 1.1s |  |
| 85 | `setProperty-v8` | 49 | 49 | 1.1s |  |
| 86 | `targetPath-v6` | 17 | 17 | 2.5s |  |
| 87 | `targetPath-v7` | 17 | 17 | 2.1s |  |
| 88 | `targetPath-v8` | 17 | 17 | 1.8s |  |
| 89 | `toString_valueOf-v5` | 34 | 34 | 16.8s |  |
| 90 | `toString_valueOf-v6` | 5 | 5 | 1.0s |  |
| 91 | `toString_valueOf-v7` | 5 | 5 | 1.0s |  |
| 92 | `toString_valueOf-v8` | 5 | 5 | 1.0s |  |
| 93 | `with-v5` | 3 | 3 | 1.0s |  |
| 94 | `with-v6` | 43 | 43 | 1.0s |  |
| 95 | `with-v7` | 43 | 43 | 1.0s |  |
| 96 | `with-v8` | 43 | 43 | 1.0s |  |

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

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `Inheritance-v5` | exit code -6 | 20.8s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.9s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 1.4s |  |

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
