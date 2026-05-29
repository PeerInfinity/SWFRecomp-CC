# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-29 23:57 UTC

**Git SHA**: `99221dcfc6`

**Run Duration**: 4m 14s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **131** (53.9%) |
| Ruffle-matched | 96 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **227** (93.4%) |
| Failing | 16 |
| Total expected lines | 38791 |
| Matching lines | 29839 (76.9%) |
| Mismatched lines | 8952 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 81.2% |
| Runtime Error | 3 | 18.8% |

## Passing Tests

**131 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.8s |  |
| 2 | `Accessibility-v6` | 19 | 0.8s |  |
| 3 | `Accessibility-v7` | 19 | 0.8s |  |
| 4 | `Accessibility-v8` | 19 | 0.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.8s |  |
| 6 | `BitmapData-v5` | 7 | 0.9s |  |
| 7 | `BitmapData-v6` | 7 | 0.9s |  |
| 8 | `BitmapData-v7` | 7 | 0.9s |  |
| 9 | `Boolean-v5` | 38 | 0.9s |  |
| 10 | `Boolean-v6` | 38 | 0.9s |  |
| 11 | `Boolean-v7` | 38 | 0.8s |  |
| 12 | `Boolean-v8` | 38 | 0.8s |  |
| 13 | `Camera-v5` | 7 | 0.8s |  |
| 14 | `Color-v5` | 140 | 0.8s |  |
| 15 | `Color-v6` | 171 | 0.9s |  |
| 16 | `Color-v7` | 161 | 0.9s |  |
| 17 | `Color-v8` | 161 | 0.8s |  |
| 18 | `ColorTransform-v5` | 7 | 0.7s |  |
| 19 | `ColorTransform-v6` | 7 | 0.7s |  |
| 20 | `ColorTransform-v7` | 7 | 0.7s |  |
| 21 | `ColorTransform-v8` | 55 | 0.8s |  |
| 22 | `ContextMenu-v5` | 7 | 0.7s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 0.8s |  |
| 25 | `ContextMenu-v8` | 131 | 1.0s |  |
| 26 | `Error-v5` | 28 | 0.9s |  |
| 27 | `Error-v6` | 31 | 0.9s |  |
| 28 | `Error-v7` | 31 | 0.9s |  |
| 29 | `Error-v8` | 31 | 0.9s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.9s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.9s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.9s |  |
| 33 | `Global-v5` | 172 | 0.9s |  |
| 34 | `Global-v7` | 182 | 0.9s |  |
| 35 | `Global-v8` | 169 | 0.9s |  |
| 36 | `Instance-v5` | 52 | 0.7s |  |
| 37 | `Instance-v6` | 52 | 0.7s |  |
| 38 | `Instance-v7` | 52 | 0.7s |  |
| 39 | `Instance-v8` | 52 | 0.7s |  |
| 40 | `Key-v5` | 51 | 1.1s |  |
| 41 | `Key-v6` | 55 | 0.9s |  |
| 42 | `Key-v7` | 55 | 0.9s |  |
| 43 | `Key-v8` | 55 | 0.9s |  |
| 44 | `LoadVars-v5` | 8 | 0.9s |  |
| 45 | `LocalConnection-v5` | 7 | 0.8s |  |
| 46 | `LocalConnection-v6` | 58 | 0.7s |  |
| 47 | `LocalConnection-v7` | 58 | 0.7s |  |
| 48 | `LocalConnection-v8` | 58 | 0.7s |  |
| 49 | `Matrix-v5` | 7 | 1.1s |  |
| 50 | `Microphone-v5` | 6 | 0.8s |  |
| 51 | `Mouse-v5` | 13 | 0.9s |  |
| 52 | `Mouse-v6` | 21 | 0.8s |  |
| 53 | `Mouse-v7` | 21 | 0.8s |  |
| 54 | `Mouse-v8` | 21 | 0.8s |  |
| 55 | `MovieClipLoader-v5` | 6 | 0.9s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.8s |  |
| 57 | `NetConnection-v5` | 7 | 0.8s |  |
| 58 | `NetStream-v5` | 6 | 0.8s |  |
| 59 | `NetStream-v6` | 80 | 0.8s |  |
| 60 | `NetStream-v7` | 80 | 1.2s |  |
| 61 | `NetStream-v8` | 80 | 0.8s |  |
| 62 | `Number-v6` | 239 | 0.9s |  |
| 63 | `Number-v7` | 237 | 0.9s |  |
| 64 | `Number-v8` | 237 | 0.9s |  |
| 65 | `Point-v5` | 7 | 0.9s |  |
| 66 | `Point-v6` | 7 | 0.9s |  |
| 67 | `Point-v7` | 7 | 0.9s |  |
| 68 | `Point-v8` | 193 | 1.0s |  |
| 69 | `Random-v5` | 30 | 1.0s |  |
| 70 | `Random-v6` | 30 | 0.9s |  |
| 71 | `Random-v7` | 30 | 0.9s |  |
| 72 | `Random-v8` | 30 | 1.0s |  |
| 73 | `Rectangle-v5` | 7 | 0.9s |  |
| 74 | `Rectangle-v6` | 7 | 0.9s |  |
| 75 | `Rectangle-v7` | 7 | 1.0s |  |
| 76 | `Selection-v5` | 21 | 0.9s |  |
| 77 | `Stage-v5` | 38 | 0.9s |  |
| 78 | `System-v5` | 67 | 1.0s |  |
| 79 | `System-v6` | 100 | 0.9s |  |
| 80 | `System-v7` | 101 | 1.0s |  |
| 81 | `System-v8` | 101 | 0.9s |  |
| 82 | `TextFieldHTML-v5` | 6 | 0.8s |  |
| 83 | `TextFieldHTML-v6` | 37 | 0.8s |  |
| 84 | `TextFieldHTML-v7` | 37 | 0.7s |  |
| 85 | `TextFieldHTML-v8` | 37 | 0.8s |  |
| 86 | `TextFormat-v5` | 128 | 0.8s |  |
| 87 | `TextFormat-v6` | 128 | 0.8s |  |
| 88 | `TextSnapshot-v5` | 7 | 0.9s |  |
| 89 | `TextSnapshot-v6` | 173 | 0.9s |  |
| 90 | `TextSnapshot-v7` | 173 | 1.0s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.0s |  |
| 92 | `Transform-v5` | 7 | 0.9s |  |
| 93 | `Transform-v6` | 7 | 0.9s |  |
| 94 | `Transform-v7` | 7 | 0.9s |  |
| 95 | `Try-v5` | 20 | 0.9s |  |
| 96 | `Try-v6` | 20 | 0.9s |  |
| 97 | `Try-v7` | 20 | 0.9s |  |
| 98 | `Try-v8` | 20 | 0.9s |  |
| 99 | `Video-v5` | 7 | 0.9s |  |
| 100 | `Video-v6` | 85 | 0.9s |  |
| 101 | `Video-v7` | 85 | 0.9s |  |
| 102 | `Video-v8` | 85 | 0.9s |  |
| 103 | `XMLSocket-v5` | 35 | 0.8s |  |
| 104 | `XMLSocket-v6` | 35 | 0.8s |  |
| 105 | `XMLSocket-v7` | 35 | 0.8s |  |
| 106 | `XMLSocket-v8` | 35 | 0.8s |  |
| 107 | `argstest-v5` | 4 | 0.8s |  |
| 108 | `case-v5` | 39 | 0.8s |  |
| 109 | `case-v7` | 67 | 0.9s |  |
| 110 | `case-v8` | 67 | 0.8s |  |
| 111 | `delete-v5` | 61 | 0.9s |  |
| 112 | `delete-v6` | 61 | 0.8s |  |
| 113 | `delete-v7` | 61 | 0.8s |  |
| 114 | `delete-v8` | 61 | 0.8s |  |
| 115 | `enumerate-v5` | 6 | 0.8s |  |
| 116 | `enumerate-v6` | 49 | 0.9s |  |
| 117 | `enumerate-v7` | 49 | 0.8s |  |
| 118 | `enumerate-v8` | 49 | 0.8s |  |
| 119 | `flash-v5` | 10 | 0.9s |  |
| 120 | `flash-v6` | 10 | 0.9s |  |
| 121 | `flash-v7` | 10 | 0.9s |  |
| 122 | `flash-v8` | 41 | 1.0s |  |
| 123 | `getvariable-v5` | 58 | 0.9s |  |
| 124 | `getvariable-v6` | 64 | 0.9s |  |
| 125 | `getvariable-v7` | 64 | 0.9s |  |
| 126 | `getvariable-v8` | 64 | 0.9s |  |
| 127 | `swap-v5` | 7 | 1.0s |  |
| 128 | `swap-v6` | 7 | 0.9s |  |
| 129 | `swap-v7` | 7 | 0.9s |  |
| 130 | `swap-v8` | 7 | 0.9s |  |
| 131 | `targetPath-v5` | 12 | 1.0s |  |

## Ruffle-Matched Tests

**96 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 1.2s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.9s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.9s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 1.0s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.9s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.5s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.8s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.9s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.8s |  |
| 12 | `Date-v5` | 7 | 7 | 1.1s |  |
| 13 | `Date-v6` | 6 | 6 | 1.2s |  |
| 14 | `Date-v7` | 6 | 6 | 1.2s |  |
| 15 | `Date-v8` | 6 | 6 | 1.2s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 1.0s |  |
| 17 | `Function-v5` | 14 | 24 | 1.0s |  |
| 18 | `Function-v6` | 8 | 34 | 1.1s |  |
| 19 | `Function-v7` | 8 | 34 | 1.1s |  |
| 20 | `Function-v8` | 8 | 34 | 0.9s |  |
| 21 | `Global-v6` | 9 | 10 | 0.8s |  |
| 22 | `HitTest-v6` | 8 | 8 | 0.8s |  |
| 23 | `HitTest-v7` | 8 | 8 | 0.8s |  |
| 24 | `HitTest-v8` | 9 | 9 | 0.9s |  |
| 25 | `Inheritance-v7` | 5 | 10 | 0.9s |  |
| 26 | `Inheritance-v8` | 5 | 10 | 0.8s |  |
| 27 | `LoadVars-v6` | 6 | 8 | 1.0s |  |
| 28 | `LoadVars-v7` | 6 | 8 | 0.9s |  |
| 29 | `LoadVars-v8` | 6 | 8 | 0.9s |  |
| 30 | `Math-v5` | 5 | 5 | 1.3s |  |
| 31 | `Math-v6` | 5 | 5 | 1.4s |  |
| 32 | `Math-v7` | 5 | 5 | 1.1s |  |
| 33 | `Math-v8` | 5 | 5 | 0.9s |  |
| 34 | `Matrix-v6` | 29 | 71 | 0.8s |  |
| 35 | `Matrix-v7` | 28 | 70 | 0.8s |  |
| 36 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 37 | `Microphone-v6` | 31 | 31 | 0.8s |  |
| 38 | `Microphone-v7` | 31 | 31 | 0.9s |  |
| 39 | `Microphone-v8` | 31 | 31 | 1.4s |  |
| 40 | `MovieClip-v5` | 24 | 226 | 1.1s |  |
| 41 | `MovieClipLoader-v7` | 118 | 118 | 0.9s |  |
| 42 | `MovieClipLoader-v8` | 118 | 118 | 0.8s |  |
| 43 | `NetConnection-v6` | 4 | 49 | 0.9s |  |
| 44 | `NetConnection-v7` | 4 | 45 | 0.9s |  |
| 45 | `NetConnection-v8` | 4 | 45 | 0.9s |  |
| 46 | `Number-v5` | 8 | 13 | 0.9s |  |
| 47 | `Object-v5` | 3 | 7 | 1.0s |  |
| 48 | `Object-v6` | 9 | 29 | 1.1s |  |
| 49 | `Object-v7` | 8 | 20 | 1.2s |  |
| 50 | `Object-v8` | 8 | 20 | 1.2s |  |
| 51 | `Rectangle-v8` | 21 | 21 | 1.0s |  |
| 52 | `Selection-v6` | 7 | 13 | 0.9s |  |
| 53 | `Selection-v7` | 7 | 13 | 0.9s |  |
| 54 | `Selection-v8` | 7 | 13 | 0.9s |  |
| 55 | `Sound-v5` | 16 | 16 | 1.0s |  |
| 56 | `Sound-v6` | 8 | 37 | 1.0s |  |
| 57 | `Sound-v7` | 8 | 37 | 1.0s |  |
| 58 | `Sound-v8` | 8 | 37 | 1.0s |  |
| 59 | `Stage-v6` | 14 | 14 | 0.9s |  |
| 60 | `Stage-v7` | 14 | 14 | 0.9s |  |
| 61 | `Stage-v8` | 14 | 14 | 0.9s |  |
| 62 | `String-v5` | 19 | 21 | 1.2s |  |
| 63 | `String-v6` | 10 | 10 | 1.2s |  |
| 64 | `String-v7` | 10 | 10 | 1.3s |  |
| 65 | `String-v8` | 10 | 10 | 1.3s |  |
| 66 | `TextField-v5` | 3 | 3 | 0.9s |  |
| 67 | `TextFormat-v7` | 38 | 40 | 0.8s |  |
| 68 | `TextFormat-v8` | 36 | 38 | 0.8s |  |
| 69 | `Transform-v8` | 7 | 11 | 0.9s |  |
| 70 | `XML-v5` | 10 | 79 | 1.3s |  |
| 71 | `XML-v6` | 3 | 98 | 1.2s |  |
| 72 | `XML-v7` | 3 | 98 | 1.2s |  |
| 73 | `XML-v8` | 24 | 116 | 1.2s |  |
| 74 | `XMLNode-v5` | 3 | 22 | 1.0s |  |
| 75 | `XMLNode-v6` | 3 | 22 | 0.9s |  |
| 76 | `XMLNode-v7` | 3 | 22 | 0.9s |  |
| 77 | `XMLNode-v8` | 3 | 22 | 1.0s |  |
| 78 | `ops-v5` | 7 | 9 | 1.1s |  |
| 79 | `ops-v6` | 7 | 11 | 1.1s |  |
| 80 | `ops-v7` | 7 | 11 | 1.1s |  |
| 81 | `ops-v8` | 7 | 11 | 1.1s |  |
| 82 | `setProperty-v5` | 49 | 49 | 0.9s |  |
| 83 | `setProperty-v6` | 49 | 49 | 0.9s |  |
| 84 | `setProperty-v7` | 49 | 49 | 0.9s |  |
| 85 | `setProperty-v8` | 49 | 49 | 0.9s |  |
| 86 | `targetPath-v6` | 17 | 17 | 1.0s |  |
| 87 | `targetPath-v7` | 17 | 17 | 0.9s |  |
| 88 | `targetPath-v8` | 17 | 17 | 1.0s |  |
| 89 | `toString_valueOf-v5` | 34 | 34 | 1.0s |  |
| 90 | `toString_valueOf-v6` | 5 | 5 | 0.9s |  |
| 91 | `toString_valueOf-v7` | 5 | 5 | 0.9s |  |
| 92 | `toString_valueOf-v8` | 5 | 5 | 1.2s |  |
| 93 | `with-v5` | 3 | 3 | 0.9s |  |
| 94 | `with-v6` | 43 | 43 | 0.9s |  |
| 95 | `with-v7` | 43 | 43 | 0.9s |  |
| 96 | `with-v8` | 43 | 43 | 0.9s |  |

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
| 1 | `Inheritance-v5` | exit code -6 | 1.3s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.4s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 1.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `argstest-v7` | 0.9% | 67/7301 | 7301 | 2061 |  |
| 12 | `argstest-v8` | 0.8% | 58/7663 | 7663 | 2434 |  |
| 13 | `argstest-v6` | 0.6% | 42/7301 | 7301 | 2192 |  |
