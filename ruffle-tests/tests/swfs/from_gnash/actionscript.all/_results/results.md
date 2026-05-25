# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-25 02:39 UTC

**Git SHA**: `fd99759a05`

**Run Duration**: 35m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **128** (52.7%) |
| Ruffle-matched | 95 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **223** (91.8%) |
| Failing | 20 |
| Total expected lines | 38787 |
| Matching lines | 29560 (76.2%) |
| Mismatched lines | 9227 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 20 | 100.0% |

## Passing Tests

**128 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.0s |  |
| 2 | `Accessibility-v6` | 19 | 2.1s |  |
| 3 | `Accessibility-v7` | 19 | 1.8s |  |
| 4 | `Accessibility-v8` | 19 | 1.3s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.9s |  |
| 6 | `BitmapData-v5` | 7 | 1.9s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 1.6s |  |
| 9 | `Boolean-v5` | 38 | 2.4s |  |
| 10 | `Boolean-v6` | 38 | 1.8s |  |
| 11 | `Boolean-v7` | 38 | 20.7s |  |
| 12 | `Boolean-v8` | 38 | 1.3s |  |
| 13 | `Camera-v5` | 7 | 1.9s |  |
| 14 | `Color-v5` | 140 | 5.4s |  |
| 15 | `Color-v6` | 171 | 6.4s |  |
| 16 | `Color-v7` | 161 | 6.2s |  |
| 17 | `Color-v8` | 161 | 24.1s |  |
| 18 | `ColorTransform-v5` | 7 | 1.8s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.5s |  |
| 21 | `ColorTransform-v8` | 55 | 3.0s |  |
| 22 | `ContextMenu-v5` | 7 | 1.8s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.6s |  |
| 25 | `ContextMenu-v8` | 131 | 23.5s |  |
| 26 | `Error-v5` | 28 | 2.2s |  |
| 27 | `Error-v6` | 31 | 2.3s |  |
| 28 | `Error-v7` | 31 | 1.9s |  |
| 29 | `Error-v8` | 31 | 21.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.8s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.4s |  |
| 33 | `Global-v5` | 172 | 7.3s |  |
| 34 | `Global-v7` | 182 | 7.6s |  |
| 35 | `Global-v8` | 169 | 7.2s |  |
| 36 | `Instance-v5` | 52 | 2.7s |  |
| 37 | `Instance-v6` | 52 | 1.5s |  |
| 38 | `Instance-v7` | 52 | 2.3s |  |
| 39 | `Instance-v8` | 52 | 1.3s |  |
| 40 | `Key-v5` | 51 | 22.1s |  |
| 41 | `Key-v6` | 55 | 3.1s |  |
| 42 | `Key-v7` | 55 | 2.7s |  |
| 43 | `Key-v8` | 55 | 1.4s |  |
| 44 | `LoadVars-v5` | 8 | 21.9s |  |
| 45 | `LocalConnection-v5` | 7 | 20.7s |  |
| 46 | `LocalConnection-v6` | 58 | 3.1s |  |
| 47 | `LocalConnection-v7` | 58 | 2.7s |  |
| 48 | `LocalConnection-v8` | 58 | 1.3s |  |
| 49 | `Matrix-v5` | 7 | 20.1s |  |
| 50 | `Microphone-v5` | 6 | 1.8s |  |
| 51 | `Mouse-v5` | 13 | 20.2s |  |
| 52 | `Mouse-v6` | 21 | 2.1s |  |
| 53 | `Mouse-v7` | 21 | 1.7s |  |
| 54 | `Mouse-v8` | 21 | 1.3s |  |
| 55 | `MovieClipLoader-v5` | 6 | 20.7s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.7s |  |
| 57 | `NetConnection-v5` | 7 | 20.5s |  |
| 58 | `NetStream-v5` | 6 | 20.7s |  |
| 59 | `NetStream-v6` | 80 | 3.6s |  |
| 60 | `NetStream-v7` | 80 | 3.2s |  |
| 61 | `NetStream-v8` | 80 | 1.3s |  |
| 62 | `Number-v6` | 239 | 9.0s |  |
| 63 | `Number-v7` | 237 | 9.1s |  |
| 64 | `Number-v8` | 237 | 1.5s |  |
| 65 | `Point-v5` | 7 | 20.6s |  |
| 66 | `Point-v6` | 7 | 0.6s |  |
| 67 | `Point-v7` | 7 | 1.4s |  |
| 68 | `Point-v8` | 193 | 7.8s |  |
| 69 | `Random-v5` | 30 | 21.2s |  |
| 70 | `Random-v6` | 30 | 0.7s |  |
| 71 | `Random-v7` | 30 | 2.0s |  |
| 72 | `Random-v8` | 30 | 1.3s |  |
| 73 | `Rectangle-v5` | 7 | 1.8s |  |
| 74 | `Rectangle-v6` | 7 | 0.6s |  |
| 75 | `Rectangle-v7` | 7 | 1.5s |  |
| 76 | `Selection-v5` | 21 | 20.9s |  |
| 77 | `Stage-v5` | 38 | 20.6s |  |
| 78 | `System-v5` | 67 | 20.7s |  |
| 79 | `System-v6` | 100 | 3.8s |  |
| 80 | `System-v7` | 101 | 3.9s |  |
| 81 | `System-v8` | 101 | 1.3s |  |
| 82 | `TextFieldHTML-v5` | 6 | 20.4s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.5s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.1s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.3s |  |
| 86 | `TextFormat-v5` | 128 | 5.1s |  |
| 87 | `TextFormat-v6` | 128 | 0.7s |  |
| 88 | `TextSnapshot-v5` | 7 | 19.4s |  |
| 89 | `TextSnapshot-v6` | 173 | 7.2s |  |
| 90 | `TextSnapshot-v7` | 173 | 6.9s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.4s |  |
| 92 | `Transform-v5` | 7 | 1.8s |  |
| 93 | `Transform-v6` | 7 | 1.2s |  |
| 94 | `Transform-v7` | 7 | 1.4s |  |
| 95 | `Try-v5` | 20 | 21.6s |  |
| 96 | `Try-v6` | 20 | 0.7s |  |
| 97 | `Try-v7` | 20 | 2.4s |  |
| 98 | `Try-v8` | 20 | 1.4s |  |
| 99 | `Video-v5` | 7 | 20.4s |  |
| 100 | `Video-v6` | 85 | 3.5s |  |
| 101 | `Video-v7` | 85 | 3.1s |  |
| 102 | `Video-v8` | 85 | 1.4s |  |
| 103 | `XMLSocket-v5` | 35 | 20.5s |  |
| 104 | `XMLSocket-v6` | 35 | 2.5s |  |
| 105 | `XMLSocket-v7` | 35 | 2.1s |  |
| 106 | `XMLSocket-v8` | 35 | 1.4s |  |
| 107 | `argstest-v5` | 4 | 2.0s |  |
| 108 | `case-v5` | 39 | 2.5s |  |
| 109 | `case-v6` | 73 | 3.4s |  |
| 110 | `case-v7` | 67 | 3.3s |  |
| 111 | `case-v8` | 67 | 1.4s |  |
| 112 | `delete-v5` | 60 | 21.5s |  |
| 113 | `delete-v6` | 60 | 2.3s |  |
| 114 | `delete-v7` | 60 | 2.4s |  |
| 115 | `delete-v8` | 60 | 1.3s |  |
| 116 | `enumerate-v5` | 6 | 1.6s |  |
| 117 | `enumerate-v6` | 49 | 2.8s |  |
| 118 | `enumerate-v7` | 49 | 2.4s |  |
| 119 | `enumerate-v8` | 49 | 1.2s |  |
| 120 | `flash-v5` | 10 | 20.1s |  |
| 121 | `flash-v6` | 10 | 1.9s |  |
| 122 | `flash-v7` | 10 | 1.5s |  |
| 123 | `flash-v8` | 41 | 20.9s |  |
| 124 | `swap-v5` | 7 | 20.4s |  |
| 125 | `swap-v6` | 7 | 0.7s |  |
| 126 | `swap-v7` | 7 | 1.5s |  |
| 127 | `swap-v8` | 7 | 1.3s |  |
| 128 | `targetPath-v5` | 12 | 1.9s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.7s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.4s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 23.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.5s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.1s |  |
| 9 | `Camera-v6` | 57 | 57 | 3.9s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.5s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.4s |  |
| 12 | `Date-v5` | 7 | 7 | 32.0s |  |
| 13 | `Date-v6` | 6 | 6 | 14.7s |  |
| 14 | `Date-v7` | 6 | 6 | 15.3s |  |
| 15 | `Date-v8` | 6 | 6 | 1.8s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 4.8s |  |
| 17 | `Function-v5` | 14 | 24 | 24.3s |  |
| 18 | `Function-v6` | 8 | 34 | 9.5s |  |
| 19 | `Function-v7` | 8 | 34 | 9.9s |  |
| 20 | `Function-v8` | 8 | 34 | 29.0s |  |
| 21 | `Global-v6` | 9 | 10 | 27.4s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.1s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.7s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.5s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 22.5s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 6.3s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 6.5s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 1.9s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.6s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 6.0s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.3s |  |
| 32 | `Math-v5` | 5 | 5 | 13.7s |  |
| 33 | `Math-v6` | 5 | 5 | 0.8s |  |
| 34 | `Math-v7` | 5 | 5 | 14.2s |  |
| 35 | `Math-v8` | 5 | 5 | 1.6s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.1s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.2s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.4s |  |
| 39 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 40 | `Microphone-v7` | 31 | 31 | 2.9s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.3s |  |
| 42 | `MovieClip-v5` | 25 | 226 | 31.5s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 3.9s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.5s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.2s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.3s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.5s |  |
| 48 | `Number-v5` | 8 | 13 | 9.3s |  |
| 49 | `Object-v5` | 3 | 7 | 24.7s |  |
| 50 | `Object-v6` | 9 | 29 | 13.0s |  |
| 51 | `Object-v7` | 8 | 20 | 13.2s |  |
| 52 | `Object-v8` | 8 | 20 | 2.2s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 6.8s |  |
| 54 | `Selection-v6` | 7 | 13 | 5.4s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.0s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.4s |  |
| 57 | `Sound-v5` | 16 | 16 | 23.9s |  |
| 58 | `Sound-v6` | 8 | 37 | 5.4s |  |
| 59 | `Sound-v7` | 8 | 37 | 4.9s |  |
| 60 | `Sound-v8` | 8 | 37 | 1.8s |  |
| 61 | `Stage-v6` | 14 | 14 | 21.4s |  |
| 62 | `Stage-v7` | 14 | 14 | 2.7s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.4s |  |
| 64 | `String-v5` | 19 | 21 | 15.5s |  |
| 65 | `String-v6` | 10 | 10 | 16.5s |  |
| 66 | `String-v7` | 10 | 10 | 16.1s |  |
| 67 | `String-v8` | 10 | 10 | 1.5s |  |
| 68 | `TextField-v5` | 3 | 3 | 1.9s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 6.8s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 25.4s |  |
| 71 | `Transform-v8` | 7 | 11 | 22.7s |  |
| 72 | `XML-v5` | 10 | 79 | 31.9s |  |
| 73 | `XML-v6` | 3 | 98 | 15.3s |  |
| 74 | `XML-v7` | 3 | 98 | 15.0s |  |
| 75 | `XML-v8` | 24 | 116 | 4.4s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 8.3s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.3s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 7.4s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.5s |  |
| 80 | `getvariable-v6` | 3 | 5 | 3.2s |  |
| 81 | `ops-v5` | 7 | 9 | 22.5s |  |
| 82 | `ops-v6` | 7 | 11 | 7.5s |  |
| 83 | `ops-v7` | 7 | 11 | 8.0s |  |
| 84 | `ops-v8` | 7 | 11 | 15.7s |  |
| 85 | `setProperty-v5` | 49 | 49 | 2.3s |  |
| 86 | `setProperty-v6` | 49 | 49 | 2.3s |  |
| 87 | `setProperty-v7` | 49 | 49 | 2.1s |  |
| 88 | `setProperty-v8` | 49 | 49 | 1.3s |  |
| 89 | `targetPath-v6` | 17 | 17 | 2.1s |  |
| 90 | `targetPath-v7` | 17 | 17 | 1.8s |  |
| 91 | `targetPath-v8` | 17 | 17 | 1.3s |  |
| 92 | `toString_valueOf-v5` | 34 | 34 | 23.6s |  |
| 93 | `toString_valueOf-v6` | 5 | 5 | 5.6s |  |
| 94 | `toString_valueOf-v7` | 5 | 5 | 5.2s |  |
| 95 | `toString_valueOf-v8` | 5 | 5 | 1.5s |  |

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

No runtime errors.

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
