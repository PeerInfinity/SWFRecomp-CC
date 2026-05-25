# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-25 03:01 UTC

**Git SHA**: `d018fcc20f`

**Run Duration**: 8m 55s

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
| 6 | `BitmapData-v5` | 7 | 0.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.2s |  |
| 8 | `BitmapData-v7` | 7 | 0.3s |  |
| 9 | `Boolean-v5` | 38 | 0.3s |  |
| 10 | `Boolean-v6` | 38 | 0.3s |  |
| 11 | `Boolean-v7` | 38 | 0.3s |  |
| 12 | `Boolean-v8` | 38 | 0.3s |  |
| 13 | `Camera-v5` | 7 | 0.3s |  |
| 14 | `Color-v5` | 140 | 0.3s |  |
| 15 | `Color-v6` | 171 | 0.4s |  |
| 16 | `Color-v7` | 161 | 0.3s |  |
| 17 | `Color-v8` | 161 | 25.6s |  |
| 18 | `ColorTransform-v5` | 7 | 1.9s |  |
| 19 | `ColorTransform-v6` | 7 | 0.7s |  |
| 20 | `ColorTransform-v7` | 7 | 1.5s |  |
| 21 | `ColorTransform-v8` | 55 | 3.1s |  |
| 22 | `ContextMenu-v5` | 7 | 1.9s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.8s |  |
| 25 | `ContextMenu-v8` | 131 | 0.3s |  |
| 26 | `Error-v5` | 28 | 0.3s |  |
| 27 | `Error-v6` | 31 | 0.3s |  |
| 28 | `Error-v7` | 31 | 0.3s |  |
| 29 | `Error-v8` | 31 | 0.3s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.3s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.3s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.3s |  |
| 33 | `Global-v5` | 172 | 0.4s |  |
| 34 | `Global-v7` | 182 | 0.4s |  |
| 35 | `Global-v8` | 169 | 0.3s |  |
| 36 | `Instance-v5` | 52 | 0.3s |  |
| 37 | `Instance-v6` | 52 | 0.3s |  |
| 38 | `Instance-v7` | 52 | 0.3s |  |
| 39 | `Instance-v8` | 52 | 0.3s |  |
| 40 | `Key-v5` | 51 | 0.3s |  |
| 41 | `Key-v6` | 55 | 0.3s |  |
| 42 | `Key-v7` | 55 | 0.3s |  |
| 43 | `Key-v8` | 55 | 0.3s |  |
| 44 | `LoadVars-v5` | 8 | 0.3s |  |
| 45 | `LocalConnection-v5` | 7 | 20.7s |  |
| 46 | `LocalConnection-v6` | 58 | 3.1s |  |
| 47 | `LocalConnection-v7` | 58 | 2.8s |  |
| 48 | `LocalConnection-v8` | 58 | 1.4s |  |
| 49 | `Matrix-v5` | 7 | 0.2s |  |
| 50 | `Microphone-v5` | 6 | 0.2s |  |
| 51 | `Mouse-v5` | 13 | 0.3s |  |
| 52 | `Mouse-v6` | 21 | 0.3s |  |
| 53 | `Mouse-v7` | 21 | 0.3s |  |
| 54 | `Mouse-v8` | 21 | 0.3s |  |
| 55 | `MovieClipLoader-v5` | 6 | 0.3s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.2s |  |
| 57 | `NetConnection-v5` | 7 | 0.3s |  |
| 58 | `NetStream-v5` | 6 | 20.5s |  |
| 59 | `NetStream-v6` | 80 | 3.6s |  |
| 60 | `NetStream-v7` | 80 | 3.2s |  |
| 61 | `NetStream-v8` | 80 | 1.4s |  |
| 62 | `Number-v6` | 239 | 9.1s |  |
| 63 | `Number-v7` | 237 | 9.1s |  |
| 64 | `Number-v8` | 237 | 1.5s |  |
| 65 | `Point-v5` | 7 | 0.3s |  |
| 66 | `Point-v6` | 7 | 0.2s |  |
| 67 | `Point-v7` | 7 | 0.3s |  |
| 68 | `Point-v8` | 193 | 0.3s |  |
| 69 | `Random-v5` | 30 | 0.3s |  |
| 70 | `Random-v6` | 30 | 0.3s |  |
| 71 | `Random-v7` | 30 | 0.3s |  |
| 72 | `Random-v8` | 30 | 0.3s |  |
| 73 | `Rectangle-v5` | 7 | 0.2s |  |
| 74 | `Rectangle-v6` | 7 | 0.2s |  |
| 75 | `Rectangle-v7` | 7 | 0.2s |  |
| 76 | `Selection-v5` | 21 | 0.3s |  |
| 77 | `Stage-v5` | 38 | 0.3s |  |
| 78 | `System-v5` | 67 | 0.3s |  |
| 79 | `System-v6` | 100 | 0.3s |  |
| 80 | `System-v7` | 101 | 0.3s |  |
| 81 | `System-v8` | 101 | 0.3s |  |
| 82 | `TextFieldHTML-v5` | 6 | 0.3s |  |
| 83 | `TextFieldHTML-v6` | 37 | 0.3s |  |
| 84 | `TextFieldHTML-v7` | 37 | 0.3s |  |
| 85 | `TextFieldHTML-v8` | 37 | 0.3s |  |
| 86 | `TextFormat-v5` | 128 | 0.3s |  |
| 87 | `TextFormat-v6` | 128 | 0.3s |  |
| 88 | `TextSnapshot-v5` | 7 | 0.3s |  |
| 89 | `TextSnapshot-v6` | 173 | 0.3s |  |
| 90 | `TextSnapshot-v7` | 173 | 0.4s |  |
| 91 | `TextSnapshot-v8` | 173 | 0.3s |  |
| 92 | `Transform-v5` | 7 | 0.3s |  |
| 93 | `Transform-v6` | 7 | 0.3s |  |
| 94 | `Transform-v7` | 7 | 0.3s |  |
| 95 | `Try-v5` | 20 | 0.3s |  |
| 96 | `Try-v6` | 20 | 0.2s |  |
| 97 | `Try-v7` | 20 | 0.3s |  |
| 98 | `Try-v8` | 20 | 0.3s |  |
| 99 | `Video-v5` | 7 | 0.3s |  |
| 100 | `Video-v6` | 85 | 0.3s |  |
| 101 | `Video-v7` | 85 | 0.3s |  |
| 102 | `Video-v8` | 85 | 0.3s |  |
| 103 | `XMLSocket-v5` | 35 | 0.2s |  |
| 104 | `XMLSocket-v6` | 35 | 0.2s |  |
| 105 | `XMLSocket-v7` | 35 | 0.2s |  |
| 106 | `XMLSocket-v8` | 35 | 0.2s |  |
| 107 | `argstest-v5` | 4 | 0.2s |  |
| 108 | `case-v5` | 39 | 0.3s |  |
| 109 | `case-v6` | 73 | 0.3s |  |
| 110 | `case-v7` | 67 | 0.3s |  |
| 111 | `case-v8` | 67 | 0.3s |  |
| 112 | `delete-v5` | 60 | 21.2s |  |
| 113 | `delete-v6` | 60 | 2.4s |  |
| 114 | `delete-v7` | 60 | 2.5s |  |
| 115 | `delete-v8` | 60 | 1.5s |  |
| 116 | `enumerate-v5` | 6 | 1.8s |  |
| 117 | `enumerate-v6` | 49 | 2.8s |  |
| 118 | `enumerate-v7` | 49 | 2.5s |  |
| 119 | `enumerate-v8` | 49 | 1.3s |  |
| 120 | `flash-v5` | 10 | 20.8s |  |
| 121 | `flash-v6` | 10 | 1.9s |  |
| 122 | `flash-v7` | 10 | 1.6s |  |
| 123 | `flash-v8` | 41 | 21.6s |  |
| 124 | `swap-v5` | 7 | 21.2s |  |
| 125 | `swap-v6` | 7 | 0.7s |  |
| 126 | `swap-v7` | 7 | 1.6s |  |
| 127 | `swap-v8` | 7 | 1.4s |  |
| 128 | `targetPath-v5` | 12 | 2.0s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.6s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.5s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 0.3s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.3s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.3s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.7s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.3s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.3s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.3s |  |
| 12 | `Date-v5` | 7 | 7 | 0.5s |  |
| 13 | `Date-v6` | 6 | 6 | 0.5s |  |
| 14 | `Date-v7` | 6 | 6 | 0.5s |  |
| 15 | `Date-v8` | 6 | 6 | 0.5s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 0.3s |  |
| 17 | `Function-v5` | 14 | 24 | 0.3s |  |
| 18 | `Function-v6` | 8 | 34 | 0.4s |  |
| 19 | `Function-v7` | 8 | 34 | 0.4s |  |
| 20 | `Function-v8` | 8 | 34 | 0.4s |  |
| 21 | `Global-v6` | 9 | 10 | 0.4s |  |
| 22 | `HitTest-v6` | 8 | 8 | 0.3s |  |
| 23 | `HitTest-v7` | 8 | 8 | 0.3s |  |
| 24 | `HitTest-v8` | 9 | 9 | 0.3s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 0.3s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 0.3s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 0.4s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 0.4s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 0.3s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 0.3s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 0.3s |  |
| 32 | `Math-v5` | 5 | 5 | 12.7s |  |
| 33 | `Math-v6` | 5 | 5 | 0.7s |  |
| 34 | `Math-v7` | 5 | 5 | 13.0s |  |
| 35 | `Math-v8` | 5 | 5 | 1.5s |  |
| 36 | `Matrix-v6` | 29 | 71 | 0.3s |  |
| 37 | `Matrix-v7` | 28 | 70 | 0.3s |  |
| 38 | `Matrix-v8` | 28 | 70 | 0.3s |  |
| 39 | `Microphone-v6` | 31 | 31 | 0.3s |  |
| 40 | `Microphone-v7` | 31 | 31 | 0.3s |  |
| 41 | `Microphone-v8` | 31 | 31 | 0.3s |  |
| 42 | `MovieClip-v5` | 25 | 226 | 0.5s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 0.3s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 0.3s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 0.3s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 0.3s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 0.3s |  |
| 48 | `Number-v5` | 8 | 13 | 9.3s |  |
| 49 | `Object-v5` | 3 | 7 | 0.4s |  |
| 50 | `Object-v6` | 9 | 29 | 0.3s |  |
| 51 | `Object-v7` | 8 | 20 | 0.6s |  |
| 52 | `Object-v8` | 8 | 20 | 0.6s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 0.3s |  |
| 54 | `Selection-v6` | 7 | 13 | 0.3s |  |
| 55 | `Selection-v7` | 7 | 13 | 0.3s |  |
| 56 | `Selection-v8` | 7 | 13 | 0.3s |  |
| 57 | `Sound-v5` | 16 | 16 | 0.5s |  |
| 58 | `Sound-v6` | 8 | 37 | 0.5s |  |
| 59 | `Sound-v7` | 8 | 37 | 0.5s |  |
| 60 | `Sound-v8` | 8 | 37 | 0.5s |  |
| 61 | `Stage-v6` | 14 | 14 | 0.3s |  |
| 62 | `Stage-v7` | 14 | 14 | 0.3s |  |
| 63 | `Stage-v8` | 14 | 14 | 0.3s |  |
| 64 | `String-v5` | 19 | 21 | 0.5s |  |
| 65 | `String-v6` | 10 | 10 | 0.6s |  |
| 66 | `String-v7` | 10 | 10 | 0.5s |  |
| 67 | `String-v8` | 10 | 10 | 0.5s |  |
| 68 | `TextField-v5` | 3 | 3 | 0.3s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 0.4s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 0.3s |  |
| 71 | `Transform-v8` | 7 | 11 | 0.3s |  |
| 72 | `XML-v5` | 10 | 79 | 0.4s |  |
| 73 | `XML-v6` | 3 | 98 | 0.5s |  |
| 74 | `XML-v7` | 3 | 98 | 0.5s |  |
| 75 | `XML-v8` | 24 | 116 | 0.4s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 0.3s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 0.3s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 0.3s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 0.3s |  |
| 80 | `getvariable-v6` | 3 | 5 | 3.4s |  |
| 81 | `ops-v5` | 7 | 9 | 28.7s |  |
| 82 | `ops-v6` | 7 | 11 | 9.8s |  |
| 83 | `ops-v7` | 7 | 11 | 10.4s |  |
| 84 | `ops-v8` | 7 | 11 | 20.1s |  |
| 85 | `setProperty-v5` | 49 | 49 | 3.0s |  |
| 86 | `setProperty-v6` | 49 | 49 | 3.0s |  |
| 87 | `setProperty-v7` | 49 | 49 | 2.6s |  |
| 88 | `setProperty-v8` | 49 | 49 | 1.7s |  |
| 89 | `targetPath-v6` | 17 | 17 | 2.2s |  |
| 90 | `targetPath-v7` | 17 | 17 | 1.8s |  |
| 91 | `targetPath-v8` | 17 | 17 | 1.3s |  |
| 92 | `toString_valueOf-v5` | 34 | 34 | 23.3s |  |
| 93 | `toString_valueOf-v6` | 5 | 5 | 5.4s |  |
| 94 | `toString_valueOf-v7` | 5 | 5 | 5.1s |  |
| 95 | `toString_valueOf-v8` | 5 | 5 | 1.4s |  |

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
