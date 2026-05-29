# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-29 00:38 UTC

**Git SHA**: `808f578c0f`

**Run Duration**: 34m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **124** (51.0%) |
| Ruffle-matched | 95 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **219** (90.1%) |
| Failing | 24 |
| Total expected lines | 38791 |
| Matching lines | 29488 (76.0%) |
| Mismatched lines | 9303 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 24 | 100.0% |

## Passing Tests

**124 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.8s |  |
| 2 | `Accessibility-v6` | 19 | 1.9s |  |
| 3 | `Accessibility-v7` | 19 | 1.5s |  |
| 4 | `Accessibility-v8` | 19 | 1.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.7s |  |
| 6 | `BitmapData-v5` | 7 | 1.7s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.3s |  |
| 9 | `Boolean-v5` | 38 | 2.2s |  |
| 10 | `Boolean-v6` | 38 | 1.6s |  |
| 11 | `Boolean-v7` | 38 | 16.2s |  |
| 12 | `Boolean-v8` | 38 | 0.9s |  |
| 13 | `Camera-v5` | 7 | 1.3s |  |
| 14 | `Color-v5` | 140 | 4.6s |  |
| 15 | `Color-v6` | 171 | 5.2s |  |
| 16 | `Color-v7` | 161 | 5.0s |  |
| 17 | `Color-v8` | 161 | 24.7s |  |
| 18 | `ColorTransform-v5` | 7 | 1.7s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.4s |  |
| 21 | `ColorTransform-v8` | 55 | 2.9s |  |
| 22 | `ContextMenu-v5` | 7 | 1.7s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.6s |  |
| 25 | `ContextMenu-v8` | 131 | 25.1s |  |
| 26 | `Error-v5` | 28 | 2.2s |  |
| 27 | `Error-v6` | 31 | 2.2s |  |
| 28 | `Error-v7` | 31 | 1.8s |  |
| 29 | `Error-v8` | 31 | 20.6s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.7s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.6s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.2s |  |
| 33 | `Global-v5` | 172 | 6.5s |  |
| 34 | `Global-v7` | 182 | 7.0s |  |
| 35 | `Global-v8` | 169 | 6.3s |  |
| 36 | `Instance-v5` | 52 | 2.5s |  |
| 37 | `Instance-v6` | 52 | 1.5s |  |
| 38 | `Instance-v7` | 52 | 2.1s |  |
| 39 | `Instance-v8` | 52 | 1.1s |  |
| 40 | `Key-v5` | 51 | 20.8s |  |
| 41 | `Key-v6` | 55 | 2.6s |  |
| 42 | `Key-v7` | 55 | 2.3s |  |
| 43 | `Key-v8` | 55 | 1.2s |  |
| 44 | `LoadVars-v5` | 8 | 20.5s |  |
| 45 | `LocalConnection-v5` | 7 | 20.1s |  |
| 46 | `LocalConnection-v6` | 58 | 2.8s |  |
| 47 | `LocalConnection-v7` | 58 | 2.4s |  |
| 48 | `LocalConnection-v8` | 58 | 1.1s |  |
| 49 | `Matrix-v5` | 7 | 20.4s |  |
| 50 | `Microphone-v5` | 6 | 1.7s |  |
| 51 | `Mouse-v5` | 13 | 20.3s |  |
| 52 | `Mouse-v6` | 21 | 1.9s |  |
| 53 | `Mouse-v7` | 21 | 1.6s |  |
| 54 | `Mouse-v8` | 21 | 1.1s |  |
| 55 | `MovieClipLoader-v5` | 6 | 20.3s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.7s |  |
| 57 | `NetConnection-v5` | 7 | 20.1s |  |
| 58 | `NetStream-v5` | 6 | 19.8s |  |
| 59 | `NetStream-v6` | 80 | 3.3s |  |
| 60 | `NetStream-v7` | 80 | 2.9s |  |
| 61 | `NetStream-v8` | 80 | 1.1s |  |
| 62 | `Number-v6` | 239 | 8.6s |  |
| 63 | `Number-v7` | 237 | 8.6s |  |
| 64 | `Number-v8` | 237 | 1.3s |  |
| 65 | `Point-v5` | 7 | 19.6s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.2s |  |
| 68 | `Point-v8` | 193 | 7.5s |  |
| 69 | `Random-v5` | 30 | 20.4s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 1.7s |  |
| 72 | `Random-v8` | 30 | 1.1s |  |
| 73 | `Rectangle-v5` | 7 | 1.6s |  |
| 74 | `Rectangle-v6` | 7 | 0.6s |  |
| 75 | `Rectangle-v7` | 7 | 1.2s |  |
| 76 | `Selection-v5` | 21 | 20.3s |  |
| 77 | `Stage-v5` | 38 | 20.7s |  |
| 78 | `System-v5` | 67 | 21.6s |  |
| 79 | `System-v6` | 100 | 3.9s |  |
| 80 | `System-v7` | 101 | 4.0s |  |
| 81 | `System-v8` | 101 | 1.2s |  |
| 82 | `TextFieldHTML-v5` | 6 | 20.7s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.4s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 86 | `TextFormat-v5` | 128 | 5.0s |  |
| 87 | `TextFormat-v6` | 128 | 0.6s |  |
| 88 | `TextSnapshot-v5` | 7 | 19.9s |  |
| 89 | `TextSnapshot-v6` | 173 | 7.5s |  |
| 90 | `TextSnapshot-v7` | 173 | 7.0s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 92 | `Transform-v5` | 7 | 1.6s |  |
| 93 | `Transform-v6` | 7 | 1.1s |  |
| 94 | `Transform-v7` | 7 | 1.3s |  |
| 95 | `Try-v5` | 20 | 20.9s |  |
| 96 | `Try-v6` | 20 | 0.6s |  |
| 97 | `Try-v7` | 20 | 2.3s |  |
| 98 | `Try-v8` | 20 | 1.1s |  |
| 99 | `Video-v5` | 7 | 20.0s |  |
| 100 | `Video-v6` | 85 | 3.2s |  |
| 101 | `Video-v7` | 85 | 2.8s |  |
| 102 | `Video-v8` | 85 | 1.1s |  |
| 103 | `XMLSocket-v5` | 35 | 22.6s |  |
| 104 | `XMLSocket-v6` | 35 | 2.4s |  |
| 105 | `XMLSocket-v7` | 35 | 2.1s |  |
| 106 | `XMLSocket-v8` | 35 | 1.3s |  |
| 107 | `argstest-v5` | 4 | 1.9s |  |
| 108 | `case-v5` | 39 | 2.2s |  |
| 109 | `case-v6` | 73 | 3.0s |  |
| 110 | `case-v7` | 67 | 2.9s |  |
| 111 | `case-v8` | 67 | 1.0s |  |
| 112 | `enumerate-v5` | 6 | 1.6s |  |
| 113 | `enumerate-v6` | 49 | 2.8s |  |
| 114 | `enumerate-v7` | 49 | 2.5s |  |
| 115 | `enumerate-v8` | 49 | 1.1s |  |
| 116 | `flash-v5` | 10 | 21.0s |  |
| 117 | `flash-v6` | 10 | 1.7s |  |
| 118 | `flash-v7` | 10 | 1.4s |  |
| 119 | `flash-v8` | 41 | 21.9s |  |
| 120 | `swap-v5` | 7 | 21.1s |  |
| 121 | `swap-v6` | 7 | 0.6s |  |
| 122 | `swap-v7` | 7 | 1.3s |  |
| 123 | `swap-v8` | 7 | 1.1s |  |
| 124 | `targetPath-v5` | 12 | 1.8s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.0s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 23.5s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.6s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.3s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 23.7s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.0s |  |
| 10 | `Camera-v7` | 57 | 57 | 2.7s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.9s |  |
| 12 | `Date-v5` | 7 | 7 | 34.9s |  |
| 13 | `Date-v6` | 6 | 6 | 16.4s |  |
| 14 | `Date-v7` | 6 | 6 | 16.9s |  |
| 15 | `Date-v8` | 6 | 6 | 1.6s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.7s |  |
| 17 | `Function-v5` | 14 | 24 | 24.0s |  |
| 18 | `Function-v6` | 8 | 34 | 9.4s |  |
| 19 | `Function-v7` | 8 | 34 | 9.7s |  |
| 20 | `Function-v8` | 8 | 34 | 27.7s |  |
| 21 | `Global-v6` | 9 | 10 | 26.2s |  |
| 22 | `HitTest-v6` | 8 | 8 | 4.5s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.1s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.2s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 22.2s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 6.1s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 6.3s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 1.7s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 5.3s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.0s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 1.9s |  |
| 32 | `Math-v5` | 5 | 5 | 13.2s |  |
| 33 | `Math-v6` | 5 | 5 | 0.8s |  |
| 34 | `Math-v7` | 5 | 5 | 13.7s |  |
| 35 | `Math-v8` | 5 | 5 | 1.4s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.5s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.5s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.2s |  |
| 39 | `Microphone-v6` | 31 | 31 | 3.3s |  |
| 40 | `Microphone-v7` | 31 | 31 | 2.9s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.1s |  |
| 42 | `MovieClip-v5` | 25 | 226 | 32.1s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 3.6s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.2s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 4.8s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 4.9s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 48 | `Number-v5` | 8 | 13 | 8.7s |  |
| 49 | `Object-v5` | 3 | 7 | 23.7s |  |
| 50 | `Object-v6` | 9 | 29 | 12.1s |  |
| 51 | `Object-v7` | 8 | 20 | 12.2s |  |
| 52 | `Object-v8` | 8 | 20 | 1.8s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 6.2s |  |
| 54 | `Selection-v6` | 7 | 13 | 5.0s |  |
| 55 | `Selection-v7` | 7 | 13 | 4.6s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.1s |  |
| 57 | `Sound-v5` | 16 | 16 | 22.9s |  |
| 58 | `Sound-v6` | 8 | 37 | 4.9s |  |
| 59 | `Sound-v7` | 8 | 37 | 4.5s |  |
| 60 | `Sound-v8` | 8 | 37 | 1.5s |  |
| 61 | `Stage-v6` | 14 | 14 | 21.4s |  |
| 62 | `Stage-v7` | 14 | 14 | 2.4s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.2s |  |
| 64 | `String-v5` | 19 | 21 | 15.6s |  |
| 65 | `String-v6` | 10 | 10 | 16.4s |  |
| 66 | `String-v7` | 10 | 10 | 16.2s |  |
| 67 | `String-v8` | 10 | 10 | 1.6s |  |
| 68 | `TextField-v5` | 3 | 3 | 1.8s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 6.8s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 25.3s |  |
| 71 | `Transform-v8` | 7 | 11 | 23.1s |  |
| 72 | `XML-v5` | 10 | 79 | 32.2s |  |
| 73 | `XML-v6` | 3 | 98 | 15.2s |  |
| 74 | `XML-v7` | 3 | 98 | 15.1s |  |
| 75 | `XML-v8` | 24 | 116 | 4.1s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 8.1s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.2s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 7.2s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.2s |  |
| 80 | `getvariable-v6` | 3 | 5 | 3.1s |  |
| 81 | `ops-v5` | 7 | 9 | 27.7s |  |
| 82 | `ops-v6` | 7 | 11 | 8.6s |  |
| 83 | `ops-v7` | 7 | 11 | 9.4s |  |
| 84 | `ops-v8` | 7 | 11 | 19.5s |  |
| 85 | `setProperty-v5` | 49 | 49 | 2.7s |  |
| 86 | `setProperty-v6` | 49 | 49 | 2.7s |  |
| 87 | `setProperty-v7` | 49 | 49 | 2.3s |  |
| 88 | `setProperty-v8` | 49 | 49 | 1.4s |  |
| 89 | `targetPath-v6` | 17 | 17 | 2.0s |  |
| 90 | `targetPath-v7` | 17 | 17 | 1.6s |  |
| 91 | `targetPath-v8` | 17 | 17 | 1.1s |  |
| 92 | `toString_valueOf-v5` | 34 | 34 | 22.2s |  |
| 93 | `toString_valueOf-v6` | 5 | 5 | 4.8s |  |
| 94 | `toString_valueOf-v7` | 5 | 5 | 4.4s |  |
| 95 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |

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

No runtime errors.

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
