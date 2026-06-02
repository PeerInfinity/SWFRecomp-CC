# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-02 04:22 UTC

**Git SHA**: `307f37c9b3`

**Run Duration**: 37m 17s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **132** (54.3%) |
| Ruffle-matched | 98 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **230** (94.7%) |
| Failing | 13 |
| Total expected lines | 38791 |
| Matching lines | 29839 (76.9%) |
| Mismatched lines | 8952 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

## Passing Tests

**132 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.9s |  |
| 2 | `Accessibility-v6` | 19 | 2.0s |  |
| 3 | `Accessibility-v7` | 19 | 1.7s |  |
| 4 | `Accessibility-v8` | 19 | 1.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.9s |  |
| 6 | `BitmapData-v5` | 7 | 2.2s |  |
| 7 | `BitmapData-v6` | 7 | 1.1s |  |
| 8 | `BitmapData-v7` | 7 | 1.8s |  |
| 9 | `Boolean-v5` | 38 | 2.7s |  |
| 10 | `Boolean-v6` | 38 | 2.1s |  |
| 11 | `Boolean-v7` | 38 | 21.3s |  |
| 12 | `Boolean-v8` | 38 | 1.7s |  |
| 13 | `Camera-v5` | 7 | 2.2s |  |
| 14 | `Color-v5` | 140 | 5.7s |  |
| 15 | `Color-v6` | 171 | 6.8s |  |
| 16 | `Color-v7` | 161 | 6.5s |  |
| 17 | `Color-v8` | 161 | 24.8s |  |
| 18 | `ColorTransform-v5` | 7 | 2.2s |  |
| 19 | `ColorTransform-v6` | 7 | 1.2s |  |
| 20 | `ColorTransform-v7` | 7 | 1.8s |  |
| 21 | `ColorTransform-v8` | 55 | 3.4s |  |
| 22 | `ContextMenu-v5` | 7 | 2.1s |  |
| 23 | `ContextMenu-v6` | 7 | 1.1s |  |
| 24 | `ContextMenu-v7` | 131 | 5.0s |  |
| 25 | `ContextMenu-v8` | 131 | 24.1s |  |
| 26 | `Error-v5` | 28 | 2.7s |  |
| 27 | `Error-v6` | 31 | 2.8s |  |
| 28 | `Error-v7` | 31 | 2.4s |  |
| 29 | `Error-v8` | 31 | 21.3s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.2s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.1s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.8s |  |
| 33 | `Global-v5` | 172 | 7.3s |  |
| 34 | `Global-v7` | 182 | 7.5s |  |
| 35 | `Global-v8` | 169 | 7.1s |  |
| 36 | `Instance-v5` | 52 | 3.2s |  |
| 37 | `Instance-v6` | 52 | 2.2s |  |
| 38 | `Instance-v7` | 52 | 2.8s |  |
| 39 | `Instance-v8` | 52 | 1.7s |  |
| 40 | `Key-v5` | 51 | 20.8s |  |
| 41 | `Key-v6` | 55 | 3.0s |  |
| 42 | `Key-v7` | 55 | 2.6s |  |
| 43 | `Key-v8` | 55 | 1.6s |  |
| 44 | `LoadVars-v5` | 8 | 20.1s |  |
| 45 | `LocalConnection-v5` | 7 | 21.2s |  |
| 46 | `LocalConnection-v6` | 58 | 3.5s |  |
| 47 | `LocalConnection-v7` | 58 | 3.1s |  |
| 48 | `LocalConnection-v8` | 58 | 1.8s |  |
| 49 | `Matrix-v5` | 7 | 20.8s |  |
| 50 | `Microphone-v5` | 6 | 2.2s |  |
| 51 | `Mouse-v5` | 13 | 20.7s |  |
| 52 | `Mouse-v6` | 21 | 2.4s |  |
| 53 | `Mouse-v7` | 21 | 2.0s |  |
| 54 | `Mouse-v8` | 21 | 1.6s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.6s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.3s |  |
| 57 | `NetConnection-v5` | 7 | 21.1s |  |
| 58 | `NetStream-v5` | 6 | 21.0s |  |
| 59 | `NetStream-v6` | 80 | 3.9s |  |
| 60 | `NetStream-v7` | 80 | 3.6s |  |
| 61 | `NetStream-v8` | 80 | 1.8s |  |
| 62 | `Number-v6` | 239 | 10.0s |  |
| 63 | `Number-v7` | 237 | 10.0s |  |
| 64 | `Number-v8` | 237 | 2.0s |  |
| 65 | `Point-v5` | 7 | 20.0s |  |
| 66 | `Point-v6` | 7 | 1.0s |  |
| 67 | `Point-v7` | 7 | 1.6s |  |
| 68 | `Point-v8` | 193 | 7.5s |  |
| 69 | `Random-v5` | 30 | 22.0s |  |
| 70 | `Random-v6` | 30 | 1.3s |  |
| 71 | `Random-v7` | 30 | 2.4s |  |
| 72 | `Random-v8` | 30 | 1.8s |  |
| 73 | `Rectangle-v5` | 7 | 2.3s |  |
| 74 | `Rectangle-v6` | 7 | 1.2s |  |
| 75 | `Rectangle-v7` | 7 | 1.9s |  |
| 76 | `Selection-v5` | 21 | 21.3s |  |
| 77 | `Stage-v5` | 38 | 20.9s |  |
| 78 | `System-v5` | 67 | 24.1s |  |
| 79 | `System-v6` | 100 | 4.7s |  |
| 80 | `System-v7` | 101 | 4.7s |  |
| 81 | `System-v8` | 101 | 1.8s |  |
| 82 | `TextFieldHTML-v5` | 6 | 20.3s |  |
| 83 | `TextFieldHTML-v6` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.2s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.4s |  |
| 86 | `TextFormat-v5` | 128 | 5.0s |  |
| 87 | `TextFormat-v6` | 128 | 1.1s |  |
| 88 | `TextSnapshot-v5` | 7 | 21.9s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.9s |  |
| 90 | `TextSnapshot-v7` | 173 | 8.5s |  |
| 91 | `TextSnapshot-v8` | 173 | 2.0s |  |
| 92 | `Transform-v5` | 7 | 2.4s |  |
| 93 | `Transform-v6` | 7 | 1.8s |  |
| 94 | `Transform-v7` | 7 | 2.0s |  |
| 95 | `Try-v5` | 20 | 16.9s |  |
| 96 | `Try-v6` | 20 | 1.0s |  |
| 97 | `Try-v7` | 20 | 2.2s |  |
| 98 | `Try-v8` | 20 | 1.4s |  |
| 99 | `Video-v5` | 7 | 16.3s |  |
| 100 | `Video-v6` | 85 | 3.2s |  |
| 101 | `Video-v7` | 85 | 2.8s |  |
| 102 | `Video-v8` | 85 | 1.3s |  |
| 103 | `XMLSocket-v5` | 35 | 21.4s |  |
| 104 | `XMLSocket-v6` | 35 | 2.8s |  |
| 105 | `XMLSocket-v7` | 35 | 2.5s |  |
| 106 | `XMLSocket-v8` | 35 | 1.8s |  |
| 107 | `argstest-v5` | 4 | 2.4s |  |
| 108 | `case-v5` | 39 | 2.9s |  |
| 109 | `case-v6` | 73 | 3.8s |  |
| 110 | `case-v7` | 67 | 3.8s |  |
| 111 | `case-v8` | 67 | 1.7s |  |
| 112 | `delete-v5` | 61 | 21.8s |  |
| 113 | `delete-v6` | 61 | 2.8s |  |
| 114 | `delete-v7` | 61 | 3.0s |  |
| 115 | `delete-v8` | 61 | 1.9s |  |
| 116 | `enumerate-v5` | 6 | 2.2s |  |
| 117 | `enumerate-v6` | 49 | 3.2s |  |
| 118 | `enumerate-v7` | 49 | 2.9s |  |
| 119 | `enumerate-v8` | 49 | 1.7s |  |
| 120 | `flash-v5` | 10 | 20.4s |  |
| 121 | `flash-v6` | 10 | 2.2s |  |
| 122 | `flash-v7` | 10 | 1.8s |  |
| 123 | `flash-v8` | 41 | 21.4s |  |
| 124 | `getvariable-v5` | 58 | 3.3s |  |
| 125 | `getvariable-v6` | 64 | 3.6s |  |
| 126 | `getvariable-v7` | 64 | 3.6s |  |
| 127 | `getvariable-v8` | 64 | 1.7s |  |
| 128 | `swap-v5` | 7 | 20.4s |  |
| 129 | `swap-v6` | 7 | 1.2s |  |
| 130 | `swap-v7` | 7 | 1.8s |  |
| 131 | `swap-v8` | 7 | 1.6s |  |
| 132 | `targetPath-v5` | 12 | 2.2s |  |

## Ruffle-Matched Tests

**98 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 20.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.6s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.5s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 23.8s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.8s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 23.8s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.3s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.0s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.6s |  |
| 12 | `Date-v5` | 7 | 7 | 34.3s |  |
| 13 | `Date-v6` | 6 | 6 | 15.6s |  |
| 14 | `Date-v7` | 6 | 6 | 16.1s |  |
| 15 | `Date-v8` | 6 | 6 | 2.1s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.2s |  |
| 17 | `Function-v5` | 14 | 24 | 25.1s |  |
| 18 | `Function-v6` | 8 | 34 | 9.8s |  |
| 19 | `Function-v7` | 8 | 34 | 10.1s |  |
| 20 | `Function-v8` | 8 | 34 | 29.7s |  |
| 21 | `Global-v6` | 9 | 10 | 27.9s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.2s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.9s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.7s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 24.0s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.1s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.4s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.3s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 5.5s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.1s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.4s |  |
| 32 | `Math-v5` | 5 | 5 | 14.8s |  |
| 33 | `Math-v6` | 5 | 5 | 1.5s |  |
| 34 | `Math-v7` | 5 | 5 | 15.6s |  |
| 35 | `Math-v8` | 5 | 5 | 2.0s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.7s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.8s |  |
| 38 | `Matrix-v8` | 28 | 70 | 1.9s |  |
| 39 | `Microphone-v6` | 31 | 31 | 3.7s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.3s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.7s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 32.1s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.3s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.8s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.4s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.5s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.8s |  |
| 48 | `Number-v5` | 8 | 13 | 10.3s |  |
| 49 | `Object-v5` | 3 | 7 | 24.0s |  |
| 50 | `Object-v6` | 9 | 29 | 11.8s |  |
| 51 | `Object-v7` | 8 | 20 | 12.0s |  |
| 52 | `Object-v8` | 8 | 20 | 2.1s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 7.5s |  |
| 54 | `Selection-v6` | 7 | 13 | 5.5s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.8s |  |
| 57 | `Sound-v5` | 16 | 16 | 24.0s |  |
| 58 | `Sound-v6` | 8 | 37 | 5.5s |  |
| 59 | `Sound-v7` | 8 | 37 | 5.1s |  |
| 60 | `Sound-v8` | 8 | 37 | 2.1s |  |
| 61 | `Stage-v6` | 14 | 14 | 21.6s |  |
| 62 | `Stage-v7` | 14 | 14 | 2.9s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.7s |  |
| 64 | `String-v5` | 19 | 21 | 16.0s |  |
| 65 | `String-v6` | 10 | 10 | 17.0s |  |
| 66 | `String-v7` | 10 | 10 | 16.4s |  |
| 67 | `String-v8` | 10 | 10 | 2.1s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.4s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 6.5s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 24.7s |  |
| 71 | `Transform-v8` | 7 | 11 | 25.5s |  |
| 72 | `XML-v5` | 10 | 79 | 32.5s |  |
| 73 | `XML-v6` | 3 | 98 | 15.7s |  |
| 74 | `XML-v7` | 3 | 98 | 15.1s |  |
| 75 | `XML-v8` | 24 | 116 | 4.6s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 8.5s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.6s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 7.8s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.8s |  |
| 80 | `ops-v5` | 7 | 9 | 29.5s |  |
| 81 | `ops-v6` | 7 | 11 | 9.2s |  |
| 82 | `ops-v7` | 7 | 11 | 10.2s |  |
| 83 | `ops-v8` | 7 | 11 | 21.0s |  |
| 84 | `setProperty-v5` | 49 | 49 | 3.3s |  |
| 85 | `setProperty-v6` | 49 | 49 | 3.3s |  |
| 86 | `setProperty-v7` | 49 | 49 | 3.0s |  |
| 87 | `setProperty-v8` | 49 | 49 | 2.0s |  |
| 88 | `targetPath-v6` | 17 | 17 | 2.4s |  |
| 89 | `targetPath-v7` | 17 | 17 | 2.0s |  |
| 90 | `targetPath-v8` | 17 | 17 | 1.6s |  |
| 91 | `toString_valueOf-v5` | 34 | 34 | 25.8s |  |
| 92 | `toString_valueOf-v6` | 5 | 5 | 6.3s |  |
| 93 | `toString_valueOf-v7` | 5 | 5 | 6.0s |  |
| 94 | `toString_valueOf-v8` | 5 | 5 | 2.0s |  |
| 95 | `with-v5` | 3 | 3 | 4.1s |  |
| 96 | `with-v6` | 43 | 43 | 5.4s |  |
| 97 | `with-v7` | 43 | 43 | 5.0s |  |
| 98 | `with-v8` | 43 | 43 | 2.1s |  |

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

No runtime errors.

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
