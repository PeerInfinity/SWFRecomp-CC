# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-24 23:52 UTC

**Git SHA**: `6fe6fb1a2f`

**Run Duration**: 4m 49s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **126** (51.9%) |
| Ruffle-matched | 93 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **219** (90.1%) |
| Failing | 24 |
| Total expected lines | 38787 |
| Matching lines | 29560 (76.2%) |
| Mismatched lines | 9227 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 20 | 83.3% |
| Runtime Error | 4 | 16.7% |

## Passing Tests

**126 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.9s |  |
| 2 | `Accessibility-v6` | 19 | 0.9s |  |
| 3 | `Accessibility-v7` | 19 | 0.9s |  |
| 4 | `Accessibility-v8` | 19 | 0.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.9s |  |
| 6 | `BitmapData-v5` | 7 | 1.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.8s |  |
| 8 | `BitmapData-v7` | 7 | 0.8s |  |
| 9 | `Boolean-v5` | 38 | 0.8s |  |
| 10 | `Boolean-v6` | 38 | 0.8s |  |
| 11 | `Boolean-v7` | 38 | 0.8s |  |
| 12 | `Boolean-v8` | 38 | 0.8s |  |
| 13 | `Camera-v5` | 7 | 0.8s |  |
| 14 | `Color-v5` | 140 | 0.9s |  |
| 15 | `Color-v6` | 171 | 0.9s |  |
| 16 | `Color-v7` | 161 | 0.9s |  |
| 17 | `Color-v8` | 161 | 1.0s |  |
| 18 | `ColorTransform-v5` | 7 | 0.9s |  |
| 19 | `ColorTransform-v6` | 7 | 0.9s |  |
| 20 | `ColorTransform-v7` | 7 | 0.9s |  |
| 21 | `ColorTransform-v8` | 55 | 0.9s |  |
| 22 | `ContextMenu-v5` | 7 | 0.9s |  |
| 23 | `ContextMenu-v6` | 7 | 0.9s |  |
| 24 | `ContextMenu-v7` | 131 | 0.9s |  |
| 25 | `ContextMenu-v8` | 131 | 1.1s |  |
| 26 | `Error-v5` | 28 | 0.8s |  |
| 27 | `Error-v6` | 31 | 0.9s |  |
| 28 | `Error-v7` | 31 | 0.8s |  |
| 29 | `Error-v8` | 31 | 1.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.9s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.9s |  |
| 32 | `ExternalInterface-v7` | 55 | 1.0s |  |
| 33 | `Global-v5` | 172 | 1.0s |  |
| 34 | `Global-v7` | 182 | 0.9s |  |
| 35 | `Global-v8` | 169 | 0.9s |  |
| 36 | `Instance-v5` | 52 | 0.9s |  |
| 37 | `Instance-v6` | 52 | 0.9s |  |
| 38 | `Instance-v7` | 52 | 0.8s |  |
| 39 | `Instance-v8` | 52 | 0.8s |  |
| 40 | `Key-v5` | 51 | 0.9s |  |
| 41 | `Key-v6` | 55 | 0.9s |  |
| 42 | `Key-v7` | 55 | 0.9s |  |
| 43 | `Key-v8` | 55 | 0.9s |  |
| 44 | `LoadVars-v5` | 8 | 0.9s |  |
| 45 | `LocalConnection-v5` | 7 | 0.8s |  |
| 46 | `LocalConnection-v6` | 58 | 0.8s |  |
| 47 | `LocalConnection-v7` | 58 | 1.0s |  |
| 48 | `LocalConnection-v8` | 58 | 0.8s |  |
| 49 | `Matrix-v5` | 7 | 0.8s |  |
| 50 | `Microphone-v5` | 6 | 0.8s |  |
| 51 | `Mouse-v5` | 13 | 0.9s |  |
| 52 | `Mouse-v6` | 21 | 0.9s |  |
| 53 | `Mouse-v7` | 21 | 0.9s |  |
| 54 | `Mouse-v8` | 21 | 0.9s |  |
| 55 | `MovieClipLoader-v5` | 6 | 1.0s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.8s |  |
| 57 | `NetConnection-v5` | 7 | 0.8s |  |
| 58 | `NetStream-v5` | 6 | 0.8s |  |
| 59 | `NetStream-v6` | 80 | 0.8s |  |
| 60 | `NetStream-v7` | 80 | 0.8s |  |
| 61 | `NetStream-v8` | 80 | 1.1s |  |
| 62 | `Number-v6` | 239 | 0.9s |  |
| 63 | `Number-v7` | 237 | 0.9s |  |
| 64 | `Number-v8` | 237 | 0.8s |  |
| 65 | `Point-v5` | 7 | 0.8s |  |
| 66 | `Point-v6` | 7 | 0.8s |  |
| 67 | `Point-v7` | 7 | 0.8s |  |
| 68 | `Point-v8` | 193 | 0.9s |  |
| 69 | `Random-v5` | 30 | 0.7s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 0.7s |  |
| 72 | `Random-v8` | 30 | 0.7s |  |
| 73 | `Rectangle-v5` | 7 | 0.7s |  |
| 74 | `Rectangle-v6` | 7 | 0.7s |  |
| 75 | `Rectangle-v7` | 7 | 0.7s |  |
| 76 | `Selection-v5` | 21 | 0.8s |  |
| 77 | `Stage-v5` | 38 | 0.8s |  |
| 78 | `System-v5` | 67 | 0.7s |  |
| 79 | `System-v6` | 100 | 1.1s |  |
| 80 | `System-v7` | 101 | 0.7s |  |
| 81 | `System-v8` | 101 | 0.7s |  |
| 82 | `TextFieldHTML-v5` | 6 | 0.9s |  |
| 83 | `TextFieldHTML-v6` | 37 | 0.9s |  |
| 84 | `TextFieldHTML-v7` | 37 | 0.9s |  |
| 85 | `TextFieldHTML-v8` | 37 | 0.9s |  |
| 86 | `TextFormat-v5` | 128 | 0.9s |  |
| 87 | `TextFormat-v6` | 128 | 1.0s |  |
| 88 | `TextSnapshot-v5` | 7 | 0.9s |  |
| 89 | `TextSnapshot-v6` | 173 | 0.9s |  |
| 90 | `TextSnapshot-v7` | 173 | 1.1s |  |
| 91 | `TextSnapshot-v8` | 173 | 0.9s |  |
| 92 | `Transform-v5` | 7 | 0.9s |  |
| 93 | `Transform-v6` | 7 | 0.9s |  |
| 94 | `Transform-v7` | 7 | 0.9s |  |
| 95 | `Try-v5` | 20 | 0.7s |  |
| 96 | `Try-v6` | 20 | 0.7s |  |
| 97 | `Try-v7` | 20 | 0.7s |  |
| 98 | `Try-v8` | 20 | 0.7s |  |
| 99 | `Video-v5` | 7 | 0.7s |  |
| 100 | `Video-v6` | 85 | 0.9s |  |
| 101 | `Video-v7` | 85 | 0.7s |  |
| 102 | `Video-v8` | 85 | 0.7s |  |
| 103 | `XMLSocket-v5` | 35 | 0.9s |  |
| 104 | `XMLSocket-v6` | 35 | 1.0s |  |
| 105 | `XMLSocket-v7` | 35 | 0.9s |  |
| 106 | `XMLSocket-v8` | 35 | 0.9s |  |
| 107 | `argstest-v5` | 4 | 0.9s |  |
| 108 | `case-v7` | 67 | 1.0s |  |
| 109 | `case-v8` | 67 | 0.9s |  |
| 110 | `delete-v5` | 60 | 22.6s |  |
| 111 | `delete-v6` | 60 | 3.3s |  |
| 112 | `delete-v7` | 60 | 3.5s |  |
| 113 | `delete-v8` | 60 | 2.5s |  |
| 114 | `enumerate-v5` | 6 | 2.8s |  |
| 115 | `enumerate-v6` | 49 | 3.8s |  |
| 116 | `enumerate-v7` | 49 | 3.4s |  |
| 117 | `enumerate-v8` | 49 | 2.3s |  |
| 118 | `flash-v5` | 10 | 1.4s |  |
| 119 | `flash-v6` | 10 | 0.9s |  |
| 120 | `flash-v7` | 10 | 0.9s |  |
| 121 | `flash-v8` | 41 | 0.9s |  |
| 122 | `swap-v5` | 7 | 0.9s |  |
| 123 | `swap-v6` | 7 | 0.9s |  |
| 124 | `swap-v7` | 7 | 0.9s |  |
| 125 | `swap-v8` | 7 | 0.9s |  |
| 126 | `targetPath-v5` | 12 | 0.9s |  |

## Ruffle-Matched Tests

**93 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 1.2s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.9s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.9s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 0.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.8s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.9s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.3s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.8s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.8s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.8s |  |
| 12 | `Date-v5` | 7 | 7 | 1.0s |  |
| 13 | `Date-v6` | 6 | 6 | 1.1s |  |
| 14 | `Date-v7` | 6 | 6 | 1.1s |  |
| 15 | `Date-v8` | 6 | 6 | 1.1s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 1.0s |  |
| 17 | `Function-v5` | 14 | 24 | 1.0s |  |
| 18 | `Function-v6` | 8 | 34 | 1.1s |  |
| 19 | `Function-v7` | 8 | 34 | 1.1s |  |
| 20 | `Function-v8` | 8 | 34 | 1.1s |  |
| 21 | `Global-v6` | 9 | 10 | 1.0s |  |
| 22 | `HitTest-v6` | 8 | 8 | 0.8s |  |
| 23 | `HitTest-v7` | 8 | 8 | 0.8s |  |
| 24 | `HitTest-v8` | 9 | 9 | 0.8s |  |
| 25 | `Inheritance-v7` | 5 | 10 | 0.9s |  |
| 26 | `Inheritance-v8` | 5 | 10 | 0.9s |  |
| 27 | `LoadVars-v6` | 6 | 8 | 1.0s |  |
| 28 | `LoadVars-v7` | 6 | 8 | 1.0s |  |
| 29 | `LoadVars-v8` | 6 | 8 | 0.9s |  |
| 30 | `Math-v5` | 5 | 5 | 1.0s |  |
| 31 | `Math-v6` | 5 | 5 | 1.0s |  |
| 32 | `Math-v7` | 5 | 5 | 1.0s |  |
| 33 | `Math-v8` | 5 | 5 | 1.0s |  |
| 34 | `Matrix-v6` | 29 | 71 | 0.9s |  |
| 35 | `Matrix-v7` | 28 | 70 | 0.9s |  |
| 36 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 37 | `Microphone-v6` | 31 | 31 | 0.8s |  |
| 38 | `Microphone-v7` | 31 | 31 | 0.8s |  |
| 39 | `Microphone-v8` | 31 | 31 | 0.8s |  |
| 40 | `MovieClip-v5` | 25 | 226 | 1.2s |  |
| 41 | `MovieClipLoader-v7` | 118 | 118 | 0.8s |  |
| 42 | `MovieClipLoader-v8` | 118 | 118 | 0.8s |  |
| 43 | `NetConnection-v6` | 4 | 49 | 0.9s |  |
| 44 | `NetConnection-v7` | 4 | 45 | 0.9s |  |
| 45 | `NetConnection-v8` | 4 | 45 | 0.9s |  |
| 46 | `Number-v5` | 8 | 13 | 0.9s |  |
| 47 | `Object-v5` | 3 | 7 | 0.9s |  |
| 48 | `Object-v6` | 9 | 29 | 1.1s |  |
| 49 | `Object-v7` | 8 | 20 | 1.2s |  |
| 50 | `Object-v8` | 8 | 20 | 1.0s |  |
| 51 | `Rectangle-v8` | 21 | 21 | 0.8s |  |
| 52 | `Selection-v6` | 7 | 13 | 0.8s |  |
| 53 | `Selection-v7` | 7 | 13 | 0.8s |  |
| 54 | `Selection-v8` | 7 | 13 | 0.9s |  |
| 55 | `Sound-v5` | 16 | 16 | 1.2s |  |
| 56 | `Sound-v6` | 8 | 37 | 0.9s |  |
| 57 | `Sound-v7` | 8 | 37 | 0.9s |  |
| 58 | `Sound-v8` | 8 | 37 | 0.9s |  |
| 59 | `Stage-v6` | 14 | 14 | 0.8s |  |
| 60 | `Stage-v7` | 14 | 14 | 0.8s |  |
| 61 | `Stage-v8` | 14 | 14 | 0.8s |  |
| 62 | `String-v5` | 19 | 21 | 1.1s |  |
| 63 | `String-v6` | 10 | 10 | 1.1s |  |
| 64 | `String-v7` | 10 | 10 | 1.1s |  |
| 65 | `String-v8` | 10 | 10 | 1.1s |  |
| 66 | `TextField-v5` | 3 | 3 | 0.7s |  |
| 67 | `TextFormat-v7` | 38 | 40 | 1.1s |  |
| 68 | `TextFormat-v8` | 36 | 38 | 1.0s |  |
| 69 | `Transform-v8` | 7 | 11 | 0.9s |  |
| 70 | `XML-v5` | 10 | 79 | 1.1s |  |
| 71 | `XML-v6` | 3 | 98 | 1.1s |  |
| 72 | `XML-v7` | 3 | 98 | 1.1s |  |
| 73 | `XML-v8` | 24 | 116 | 1.1s |  |
| 74 | `XMLNode-v5` | 3 | 22 | 0.9s |  |
| 75 | `XMLNode-v6` | 3 | 22 | 0.8s |  |
| 76 | `XMLNode-v7` | 3 | 22 | 0.8s |  |
| 77 | `XMLNode-v8` | 3 | 22 | 0.9s |  |
| 78 | `getvariable-v6` | 3 | 5 | 0.9s |  |
| 79 | `ops-v5` | 7 | 9 | 0.9s |  |
| 80 | `ops-v6` | 7 | 11 | 1.0s |  |
| 81 | `ops-v7` | 7 | 11 | 1.0s |  |
| 82 | `ops-v8` | 7 | 11 | 1.0s |  |
| 83 | `setProperty-v5` | 49 | 49 | 0.9s |  |
| 84 | `setProperty-v6` | 49 | 49 | 0.9s |  |
| 85 | `setProperty-v7` | 49 | 49 | 0.9s |  |
| 86 | `setProperty-v8` | 49 | 49 | 0.9s |  |
| 87 | `targetPath-v6` | 17 | 17 | 0.9s |  |
| 88 | `targetPath-v7` | 17 | 17 | 0.9s |  |
| 89 | `targetPath-v8` | 17 | 17 | 0.9s |  |
| 90 | `toString_valueOf-v5` | 34 | 34 | 1.0s |  |
| 91 | `toString_valueOf-v6` | 5 | 5 | 1.1s |  |
| 92 | `toString_valueOf-v7` | 5 | 5 | 0.9s |  |
| 93 | `toString_valueOf-v8` | 5 | 5 | 0.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

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

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `Inheritance-v5` | exit code -6 | 1.6s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.6s |  |
| 3 | `case-v5` | exit code -6 (output matches) | 1.5s |  |
| 4 | `case-v6` | exit code -6 (output matches) | 1.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**20 tests** with output mismatch, sorted by match rate (best first)

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
| 14 | `with-v5` | 33.3% | 21/63 | 63 | 49 |  |
| 15 | `with-v6` | 20.2% | 23/114 | 114 | 107 |  |
| 16 | `with-v7` | 20.2% | 23/114 | 114 | 107 |  |
| 17 | `with-v8` | 20.2% | 23/114 | 114 | 107 |  |
| 18 | `argstest-v7` | 0.9% | 67/7301 | 7301 | 2061 |  |
| 19 | `argstest-v8` | 0.8% | 58/7663 | 7663 | 2434 |  |
| 20 | `argstest-v6` | 0.6% | 42/7301 | 7301 | 2192 |  |
