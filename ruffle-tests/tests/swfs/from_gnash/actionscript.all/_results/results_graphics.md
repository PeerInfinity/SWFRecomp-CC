# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-31 02:39 UTC

**Git SHA**: `5d27de9a7d`

**Run Duration**: 38m 21s

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
| 1 | `Accessibility-v5` | 15 | 2.5s |  |
| 2 | `Accessibility-v6` | 19 | 2.6s |  |
| 3 | `Accessibility-v7` | 19 | 2.2s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.4s |  |
| 6 | `BitmapData-v5` | 7 | 2.0s |  |
| 7 | `BitmapData-v6` | 7 | 1.0s |  |
| 8 | `BitmapData-v7` | 7 | 1.7s |  |
| 9 | `Boolean-v5` | 38 | 2.5s |  |
| 10 | `Boolean-v6` | 38 | 2.0s |  |
| 11 | `Boolean-v7` | 38 | 21.4s |  |
| 12 | `Boolean-v8` | 38 | 1.9s |  |
| 13 | `Camera-v5` | 7 | 2.4s |  |
| 14 | `Color-v5` | 140 | 6.0s |  |
| 15 | `Color-v6` | 171 | 7.1s |  |
| 16 | `Color-v7` | 161 | 6.8s |  |
| 17 | `Color-v8` | 161 | 20.4s |  |
| 18 | `ColorTransform-v5` | 7 | 1.9s |  |
| 19 | `ColorTransform-v6` | 7 | 1.0s |  |
| 20 | `ColorTransform-v7` | 7 | 1.6s |  |
| 21 | `ColorTransform-v8` | 55 | 3.1s |  |
| 22 | `ContextMenu-v5` | 7 | 1.9s |  |
| 23 | `ContextMenu-v6` | 7 | 1.0s |  |
| 24 | `ContextMenu-v7` | 131 | 4.4s |  |
| 25 | `ContextMenu-v8` | 131 | 26.5s |  |
| 26 | `Error-v5` | 28 | 3.0s |  |
| 27 | `Error-v6` | 31 | 3.1s |  |
| 28 | `Error-v7` | 31 | 2.7s |  |
| 29 | `Error-v8` | 31 | 21.4s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.5s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.3s |  |
| 32 | `ExternalInterface-v7` | 55 | 2.9s |  |
| 33 | `Global-v5` | 172 | 7.0s |  |
| 34 | `Global-v7` | 182 | 7.3s |  |
| 35 | `Global-v8` | 169 | 6.8s |  |
| 36 | `Instance-v5` | 52 | 3.1s |  |
| 37 | `Instance-v6` | 52 | 2.1s |  |
| 38 | `Instance-v7` | 52 | 2.8s |  |
| 39 | `Instance-v8` | 52 | 1.7s |  |
| 40 | `Key-v5` | 51 | 22.5s |  |
| 41 | `Key-v6` | 55 | 3.6s |  |
| 42 | `Key-v7` | 55 | 3.1s |  |
| 43 | `Key-v8` | 55 | 1.9s |  |
| 44 | `LoadVars-v5` | 8 | 21.8s |  |
| 45 | `LocalConnection-v5` | 7 | 20.7s |  |
| 46 | `LocalConnection-v6` | 58 | 3.5s |  |
| 47 | `LocalConnection-v7` | 58 | 3.2s |  |
| 48 | `LocalConnection-v8` | 58 | 1.8s |  |
| 49 | `Matrix-v5` | 7 | 21.5s |  |
| 50 | `Microphone-v5` | 6 | 2.4s |  |
| 51 | `Mouse-v5` | 13 | 21.6s |  |
| 52 | `Mouse-v6` | 21 | 2.8s |  |
| 53 | `Mouse-v7` | 21 | 2.3s |  |
| 54 | `Mouse-v8` | 21 | 1.9s |  |
| 55 | `MovieClipLoader-v5` | 6 | 17.3s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.0s |  |
| 57 | `NetConnection-v5` | 7 | 17.0s |  |
| 58 | `NetStream-v5` | 6 | 21.4s |  |
| 59 | `NetStream-v6` | 80 | 4.2s |  |
| 60 | `NetStream-v7` | 80 | 3.9s |  |
| 61 | `NetStream-v8` | 80 | 1.9s |  |
| 62 | `Number-v6` | 239 | 9.8s |  |
| 63 | `Number-v7` | 237 | 9.7s |  |
| 64 | `Number-v8` | 237 | 2.1s |  |
| 65 | `Point-v5` | 7 | 22.1s |  |
| 66 | `Point-v6` | 7 | 1.3s |  |
| 67 | `Point-v7` | 7 | 2.1s |  |
| 68 | `Point-v8` | 193 | 9.3s |  |
| 69 | `Random-v5` | 30 | 23.7s |  |
| 70 | `Random-v6` | 30 | 1.4s |  |
| 71 | `Random-v7` | 30 | 2.9s |  |
| 72 | `Random-v8` | 30 | 2.0s |  |
| 73 | `Rectangle-v5` | 7 | 2.6s |  |
| 74 | `Rectangle-v6` | 7 | 1.4s |  |
| 75 | `Rectangle-v7` | 7 | 2.2s |  |
| 76 | `Selection-v5` | 21 | 21.2s |  |
| 77 | `Stage-v5` | 38 | 20.9s |  |
| 78 | `System-v5` | 67 | 24.5s |  |
| 79 | `System-v6` | 100 | 5.0s |  |
| 80 | `System-v7` | 101 | 5.1s |  |
| 81 | `System-v8` | 101 | 2.0s |  |
| 82 | `TextFieldHTML-v5` | 6 | 21.3s |  |
| 83 | `TextFieldHTML-v6` | 37 | 3.1s |  |
| 84 | `TextFieldHTML-v7` | 37 | 2.7s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 86 | `TextFormat-v5` | 128 | 6.0s |  |
| 87 | `TextFormat-v6` | 128 | 1.4s |  |
| 88 | `TextSnapshot-v5` | 7 | 20.3s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.0s |  |
| 90 | `TextSnapshot-v7` | 173 | 7.6s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.9s |  |
| 92 | `Transform-v5` | 7 | 2.3s |  |
| 93 | `Transform-v6` | 7 | 1.7s |  |
| 94 | `Transform-v7` | 7 | 1.9s |  |
| 95 | `Try-v5` | 20 | 21.2s |  |
| 96 | `Try-v6` | 20 | 1.2s |  |
| 97 | `Try-v7` | 20 | 3.0s |  |
| 98 | `Try-v8` | 20 | 1.8s |  |
| 99 | `Video-v5` | 7 | 20.4s |  |
| 100 | `Video-v6` | 85 | 3.7s |  |
| 101 | `Video-v7` | 85 | 3.4s |  |
| 102 | `Video-v8` | 85 | 1.8s |  |
| 103 | `XMLSocket-v5` | 35 | 21.0s |  |
| 104 | `XMLSocket-v6` | 35 | 2.8s |  |
| 105 | `XMLSocket-v7` | 35 | 2.4s |  |
| 106 | `XMLSocket-v8` | 35 | 1.7s |  |
| 107 | `argstest-v5` | 4 | 2.2s |  |
| 108 | `case-v5` | 39 | 3.1s |  |
| 109 | `case-v6` | 73 | 4.0s |  |
| 110 | `case-v7` | 67 | 3.9s |  |
| 111 | `case-v8` | 67 | 1.9s |  |
| 112 | `delete-v5` | 61 | 22.6s |  |
| 113 | `delete-v6` | 61 | 3.0s |  |
| 114 | `delete-v7` | 61 | 3.2s |  |
| 115 | `delete-v8` | 61 | 2.0s |  |
| 116 | `enumerate-v5` | 6 | 2.4s |  |
| 117 | `enumerate-v6` | 49 | 3.4s |  |
| 118 | `enumerate-v7` | 49 | 3.1s |  |
| 119 | `enumerate-v8` | 49 | 1.9s |  |
| 120 | `flash-v5` | 10 | 21.4s |  |
| 121 | `flash-v6` | 10 | 2.2s |  |
| 122 | `flash-v7` | 10 | 1.9s |  |
| 123 | `flash-v8` | 41 | 22.4s |  |
| 124 | `getvariable-v5` | 58 | 3.5s |  |
| 125 | `getvariable-v6` | 64 | 3.6s |  |
| 126 | `getvariable-v7` | 64 | 3.6s |  |
| 127 | `getvariable-v8` | 64 | 1.7s |  |
| 128 | `swap-v5` | 7 | 20.6s |  |
| 129 | `swap-v6` | 7 | 1.2s |  |
| 130 | `swap-v7` | 7 | 1.9s |  |
| 131 | `swap-v8` | 7 | 1.8s |  |
| 132 | `targetPath-v5` | 12 | 2.4s |  |

## Ruffle-Matched Tests

**98 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.8s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.8s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.9s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 23.3s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.6s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.7s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 21.4s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.5s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.1s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.9s |  |
| 12 | `Date-v5` | 7 | 7 | 36.5s |  |
| 13 | `Date-v6` | 6 | 6 | 17.5s |  |
| 14 | `Date-v7` | 6 | 6 | 18.0s |  |
| 15 | `Date-v8` | 6 | 6 | 2.5s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.4s |  |
| 17 | `Function-v5` | 14 | 24 | 24.8s |  |
| 18 | `Function-v6` | 8 | 34 | 10.2s |  |
| 19 | `Function-v7` | 8 | 34 | 10.6s |  |
| 20 | `Function-v8` | 8 | 34 | 27.9s |  |
| 21 | `Global-v6` | 9 | 10 | 26.2s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.1s |  |
| 23 | `HitTest-v7` | 8 | 8 | 4.7s |  |
| 24 | `HitTest-v8` | 9 | 9 | 4.6s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 22.7s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 6.7s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 6.9s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.3s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.4s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 6.1s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.8s |  |
| 32 | `Math-v5` | 5 | 5 | 13.8s |  |
| 33 | `Math-v6` | 5 | 5 | 1.4s |  |
| 34 | `Math-v7` | 5 | 5 | 14.3s |  |
| 35 | `Math-v8` | 5 | 5 | 2.0s |  |
| 36 | `Matrix-v6` | 29 | 71 | 8.2s |  |
| 37 | `Matrix-v7` | 28 | 70 | 8.4s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.1s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.2s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.9s |  |
| 41 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 34.7s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 3.6s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 2.4s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 4.6s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 4.6s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.6s |  |
| 48 | `Number-v5` | 8 | 13 | 10.1s |  |
| 49 | `Object-v5` | 3 | 7 | 26.3s |  |
| 50 | `Object-v6` | 9 | 29 | 14.3s |  |
| 51 | `Object-v7` | 8 | 20 | 14.5s |  |
| 52 | `Object-v8` | 8 | 20 | 2.7s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 8.4s |  |
| 54 | `Selection-v6` | 7 | 13 | 5.7s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.3s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.9s |  |
| 57 | `Sound-v5` | 16 | 16 | 24.3s |  |
| 58 | `Sound-v6` | 8 | 37 | 5.8s |  |
| 59 | `Sound-v7` | 8 | 37 | 5.5s |  |
| 60 | `Sound-v8` | 8 | 37 | 2.2s |  |
| 61 | `Stage-v6` | 14 | 14 | 21.5s |  |
| 62 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.8s |  |
| 64 | `String-v5` | 19 | 21 | 16.1s |  |
| 65 | `String-v6` | 10 | 10 | 16.5s |  |
| 66 | `String-v7` | 10 | 10 | 16.4s |  |
| 67 | `String-v8` | 10 | 10 | 2.2s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.6s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 7.8s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 27.5s |  |
| 71 | `Transform-v8` | 7 | 11 | 23.5s |  |
| 72 | `XML-v5` | 10 | 79 | 33.8s |  |
| 73 | `XML-v6` | 3 | 98 | 16.4s |  |
| 74 | `XML-v7` | 3 | 98 | 16.1s |  |
| 75 | `XML-v8` | 24 | 116 | 5.0s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 9.0s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.9s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 8.3s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.9s |  |
| 80 | `ops-v5` | 7 | 9 | 31.3s |  |
| 81 | `ops-v6` | 7 | 11 | 11.0s |  |
| 82 | `ops-v7` | 7 | 11 | 11.6s |  |
| 83 | `ops-v8` | 7 | 11 | 22.2s |  |
| 84 | `setProperty-v5` | 49 | 49 | 3.7s |  |
| 85 | `setProperty-v6` | 49 | 49 | 3.8s |  |
| 86 | `setProperty-v7` | 49 | 49 | 3.4s |  |
| 87 | `setProperty-v8` | 49 | 49 | 2.3s |  |
| 88 | `targetPath-v6` | 17 | 17 | 2.6s |  |
| 89 | `targetPath-v7` | 17 | 17 | 2.2s |  |
| 90 | `targetPath-v8` | 17 | 17 | 1.7s |  |
| 91 | `toString_valueOf-v5` | 34 | 34 | 23.4s |  |
| 92 | `toString_valueOf-v6` | 5 | 5 | 5.8s |  |
| 93 | `toString_valueOf-v7` | 5 | 5 | 5.4s |  |
| 94 | `toString_valueOf-v8` | 5 | 5 | 1.9s |  |
| 95 | `with-v5` | 3 | 3 | 3.8s |  |
| 96 | `with-v6` | 43 | 43 | 4.9s |  |
| 97 | `with-v7` | 43 | 43 | 4.5s |  |
| 98 | `with-v8` | 43 | 43 | 2.0s |  |

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
