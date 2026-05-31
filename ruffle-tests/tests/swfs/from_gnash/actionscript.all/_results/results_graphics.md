# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-31 16:03 UTC

**Git SHA**: `7d161fd4bd`

**Run Duration**: 19m 15s

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
| 1 | `Accessibility-v5` | 15 | 1.0s |  |
| 2 | `Accessibility-v6` | 19 | 1.0s |  |
| 3 | `Accessibility-v7` | 19 | 1.0s |  |
| 4 | `Accessibility-v8` | 19 | 1.0s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.0s |  |
| 6 | `BitmapData-v5` | 7 | 1.0s |  |
| 7 | `BitmapData-v6` | 7 | 1.0s |  |
| 8 | `BitmapData-v7` | 7 | 1.0s |  |
| 9 | `Boolean-v5` | 38 | 1.0s |  |
| 10 | `Boolean-v6` | 38 | 1.0s |  |
| 11 | `Boolean-v7` | 38 | 19.8s |  |
| 12 | `Boolean-v8` | 38 | 1.0s |  |
| 13 | `Camera-v5` | 7 | 1.0s |  |
| 14 | `Color-v5` | 140 | 1.1s |  |
| 15 | `Color-v6` | 171 | 1.1s |  |
| 16 | `Color-v7` | 161 | 1.0s |  |
| 17 | `Color-v8` | 161 | 20.5s |  |
| 18 | `ColorTransform-v5` | 7 | 1.0s |  |
| 19 | `ColorTransform-v6` | 7 | 1.0s |  |
| 20 | `ColorTransform-v7` | 7 | 1.0s |  |
| 21 | `ColorTransform-v8` | 55 | 1.1s |  |
| 22 | `ContextMenu-v5` | 7 | 1.0s |  |
| 23 | `ContextMenu-v6` | 7 | 1.0s |  |
| 24 | `ContextMenu-v7` | 131 | 1.1s |  |
| 25 | `ContextMenu-v8` | 131 | 19.8s |  |
| 26 | `Error-v5` | 28 | 1.0s |  |
| 27 | `Error-v6` | 31 | 1.0s |  |
| 28 | `Error-v7` | 31 | 1.0s |  |
| 29 | `Error-v8` | 31 | 19.1s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.8s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.8s |  |
| 33 | `Global-v5` | 172 | 1.1s |  |
| 34 | `Global-v7` | 182 | 1.0s |  |
| 35 | `Global-v8` | 169 | 1.1s |  |
| 36 | `Instance-v5` | 52 | 0.9s |  |
| 37 | `Instance-v6` | 52 | 0.9s |  |
| 38 | `Instance-v7` | 52 | 0.9s |  |
| 39 | `Instance-v8` | 52 | 0.9s |  |
| 40 | `Key-v5` | 51 | 20.8s |  |
| 41 | `Key-v6` | 55 | 1.0s |  |
| 42 | `Key-v7` | 55 | 1.0s |  |
| 43 | `Key-v8` | 55 | 1.0s |  |
| 44 | `LoadVars-v5` | 8 | 20.8s |  |
| 45 | `LocalConnection-v5` | 7 | 19.4s |  |
| 46 | `LocalConnection-v6` | 58 | 1.0s |  |
| 47 | `LocalConnection-v7` | 58 | 1.0s |  |
| 48 | `LocalConnection-v8` | 58 | 0.9s |  |
| 49 | `Matrix-v5` | 7 | 19.2s |  |
| 50 | `Microphone-v5` | 6 | 0.9s |  |
| 51 | `Mouse-v5` | 13 | 20.5s |  |
| 52 | `Mouse-v6` | 21 | 1.0s |  |
| 53 | `Mouse-v7` | 21 | 1.0s |  |
| 54 | `Mouse-v8` | 21 | 1.0s |  |
| 55 | `MovieClipLoader-v5` | 6 | 19.9s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.9s |  |
| 57 | `NetConnection-v5` | 7 | 19.8s |  |
| 58 | `NetStream-v5` | 6 | 15.1s |  |
| 59 | `NetStream-v6` | 80 | 0.8s |  |
| 60 | `NetStream-v7` | 80 | 0.8s |  |
| 61 | `NetStream-v8` | 80 | 0.8s |  |
| 62 | `Number-v6` | 239 | 0.9s |  |
| 63 | `Number-v7` | 237 | 0.9s |  |
| 64 | `Number-v8` | 237 | 0.9s |  |
| 65 | `Point-v5` | 7 | 18.8s |  |
| 66 | `Point-v6` | 7 | 0.9s |  |
| 67 | `Point-v7` | 7 | 0.9s |  |
| 68 | `Point-v8` | 193 | 1.0s |  |
| 69 | `Random-v5` | 30 | 20.1s |  |
| 70 | `Random-v6` | 30 | 1.0s |  |
| 71 | `Random-v7` | 30 | 1.1s |  |
| 72 | `Random-v8` | 30 | 1.1s |  |
| 73 | `Rectangle-v5` | 7 | 1.1s |  |
| 74 | `Rectangle-v6` | 7 | 1.1s |  |
| 75 | `Rectangle-v7` | 7 | 1.1s |  |
| 76 | `Selection-v5` | 21 | 20.3s |  |
| 77 | `Stage-v5` | 38 | 19.6s |  |
| 78 | `System-v5` | 67 | 19.0s |  |
| 79 | `System-v6` | 100 | 0.9s |  |
| 80 | `System-v7` | 101 | 0.9s |  |
| 81 | `System-v8` | 101 | 0.9s |  |
| 82 | `TextFieldHTML-v5` | 6 | 20.3s |  |
| 83 | `TextFieldHTML-v6` | 37 | 1.0s |  |
| 84 | `TextFieldHTML-v7` | 37 | 1.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.0s |  |
| 86 | `TextFormat-v5` | 128 | 1.1s |  |
| 87 | `TextFormat-v6` | 128 | 1.0s |  |
| 88 | `TextSnapshot-v5` | 7 | 18.8s |  |
| 89 | `TextSnapshot-v6` | 173 | 1.0s |  |
| 90 | `TextSnapshot-v7` | 173 | 0.9s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.0s |  |
| 92 | `Transform-v5` | 7 | 0.9s |  |
| 93 | `Transform-v6` | 7 | 0.9s |  |
| 94 | `Transform-v7` | 7 | 0.9s |  |
| 95 | `Try-v5` | 20 | 19.6s |  |
| 96 | `Try-v6` | 20 | 1.0s |  |
| 97 | `Try-v7` | 20 | 1.0s |  |
| 98 | `Try-v8` | 20 | 1.0s |  |
| 99 | `Video-v5` | 7 | 19.9s |  |
| 100 | `Video-v6` | 85 | 1.0s |  |
| 101 | `Video-v7` | 85 | 1.0s |  |
| 102 | `Video-v8` | 85 | 1.0s |  |
| 103 | `XMLSocket-v5` | 35 | 19.6s |  |
| 104 | `XMLSocket-v6` | 35 | 1.0s |  |
| 105 | `XMLSocket-v7` | 35 | 1.0s |  |
| 106 | `XMLSocket-v8` | 35 | 1.0s |  |
| 107 | `argstest-v5` | 4 | 1.0s |  |
| 108 | `case-v5` | 39 | 1.1s |  |
| 109 | `case-v6` | 73 | 1.1s |  |
| 110 | `case-v7` | 67 | 1.1s |  |
| 111 | `case-v8` | 67 | 1.0s |  |
| 112 | `delete-v5` | 61 | 19.9s |  |
| 113 | `delete-v6` | 61 | 1.0s |  |
| 114 | `delete-v7` | 61 | 1.0s |  |
| 115 | `delete-v8` | 61 | 1.0s |  |
| 116 | `enumerate-v5` | 6 | 1.0s |  |
| 117 | `enumerate-v6` | 49 | 1.0s |  |
| 118 | `enumerate-v7` | 49 | 1.0s |  |
| 119 | `enumerate-v8` | 49 | 1.0s |  |
| 120 | `flash-v5` | 10 | 19.8s |  |
| 121 | `flash-v6` | 10 | 1.0s |  |
| 122 | `flash-v7` | 10 | 1.0s |  |
| 123 | `flash-v8` | 41 | 19.9s |  |
| 124 | `getvariable-v5` | 58 | 1.0s |  |
| 125 | `getvariable-v6` | 64 | 1.0s |  |
| 126 | `getvariable-v7` | 64 | 1.0s |  |
| 127 | `getvariable-v8` | 64 | 1.0s |  |
| 128 | `swap-v5` | 7 | 19.4s |  |
| 129 | `swap-v6` | 7 | 1.0s |  |
| 130 | `swap-v7` | 7 | 1.0s |  |
| 131 | `swap-v8` | 7 | 1.0s |  |
| 132 | `targetPath-v5` | 12 | 1.0s |  |

## Ruffle-Matched Tests

**98 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 20.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 1.1s |  |
| 3 | `ASnative-v7` | 40 | 40 | 1.1s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.1s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 19.4s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 1.0s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.0s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 1.1s |  |
| 10 | `Camera-v7` | 57 | 57 | 1.0s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 12 | `Date-v5` | 7 | 7 | 20.1s |  |
| 13 | `Date-v6` | 6 | 6 | 1.3s |  |
| 14 | `Date-v7` | 6 | 6 | 1.3s |  |
| 15 | `Date-v8` | 6 | 6 | 1.3s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 0.8s |  |
| 17 | `Function-v5` | 14 | 24 | 19.4s |  |
| 18 | `Function-v6` | 8 | 34 | 0.9s |  |
| 19 | `Function-v7` | 8 | 34 | 0.9s |  |
| 20 | `Function-v8` | 8 | 34 | 19.9s |  |
| 21 | `Global-v6` | 9 | 10 | 19.6s |  |
| 22 | `HitTest-v6` | 8 | 8 | 1.0s |  |
| 23 | `HitTest-v7` | 8 | 8 | 1.0s |  |
| 24 | `HitTest-v8` | 9 | 9 | 1.0s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 18.9s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 1.0s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 1.0s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 1.0s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 1.0s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 1.0s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 1.0s |  |
| 32 | `Math-v5` | 5 | 5 | 1.1s |  |
| 33 | `Math-v6` | 5 | 5 | 1.1s |  |
| 34 | `Math-v7` | 5 | 5 | 1.1s |  |
| 35 | `Math-v8` | 5 | 5 | 1.2s |  |
| 36 | `Matrix-v6` | 29 | 71 | 1.0s |  |
| 37 | `Matrix-v7` | 28 | 70 | 1.0s |  |
| 38 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 39 | `Microphone-v6` | 31 | 31 | 0.9s |  |
| 40 | `Microphone-v7` | 31 | 31 | 0.9s |  |
| 41 | `Microphone-v8` | 31 | 31 | 0.9s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 20.6s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 0.9s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 0.9s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 1.0s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 1.0s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 1.0s |  |
| 48 | `Number-v5` | 8 | 13 | 0.9s |  |
| 49 | `Object-v5` | 3 | 7 | 19.1s |  |
| 50 | `Object-v6` | 9 | 29 | 1.1s |  |
| 51 | `Object-v7` | 8 | 20 | 1.1s |  |
| 52 | `Object-v8` | 8 | 20 | 1.1s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 1.1s |  |
| 54 | `Selection-v6` | 7 | 13 | 1.1s |  |
| 55 | `Selection-v7` | 7 | 13 | 1.1s |  |
| 56 | `Selection-v8` | 7 | 13 | 1.0s |  |
| 57 | `Sound-v5` | 16 | 16 | 20.4s |  |
| 58 | `Sound-v6` | 8 | 37 | 1.2s |  |
| 59 | `Sound-v7` | 8 | 37 | 1.2s |  |
| 60 | `Sound-v8` | 8 | 37 | 1.2s |  |
| 61 | `Stage-v6` | 14 | 14 | 19.8s |  |
| 62 | `Stage-v7` | 14 | 14 | 1.0s |  |
| 63 | `Stage-v8` | 14 | 14 | 1.0s |  |
| 64 | `String-v5` | 19 | 21 | 1.3s |  |
| 65 | `String-v6` | 10 | 10 | 1.3s |  |
| 66 | `String-v7` | 10 | 10 | 1.3s |  |
| 67 | `String-v8` | 10 | 10 | 1.3s |  |
| 68 | `TextField-v5` | 3 | 3 | 0.9s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 1.1s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 20.8s |  |
| 71 | `Transform-v8` | 7 | 11 | 19.0s |  |
| 72 | `XML-v5` | 10 | 79 | 19.9s |  |
| 73 | `XML-v6` | 3 | 98 | 1.3s |  |
| 74 | `XML-v7` | 3 | 98 | 1.3s |  |
| 75 | `XML-v8` | 24 | 116 | 1.3s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 1.1s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 1.1s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 1.0s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 1.0s |  |
| 80 | `ops-v5` | 7 | 9 | 19.0s |  |
| 81 | `ops-v6` | 7 | 11 | 0.9s |  |
| 82 | `ops-v7` | 7 | 11 | 1.1s |  |
| 83 | `ops-v8` | 7 | 11 | 18.7s |  |
| 84 | `setProperty-v5` | 49 | 49 | 0.9s |  |
| 85 | `setProperty-v6` | 49 | 49 | 0.9s |  |
| 86 | `setProperty-v7` | 49 | 49 | 0.9s |  |
| 87 | `setProperty-v8` | 49 | 49 | 0.9s |  |
| 88 | `targetPath-v6` | 17 | 17 | 1.0s |  |
| 89 | `targetPath-v7` | 17 | 17 | 1.0s |  |
| 90 | `targetPath-v8` | 17 | 17 | 1.0s |  |
| 91 | `toString_valueOf-v5` | 34 | 34 | 20.6s |  |
| 92 | `toString_valueOf-v6` | 5 | 5 | 1.1s |  |
| 93 | `toString_valueOf-v7` | 5 | 5 | 1.0s |  |
| 94 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 95 | `with-v5` | 3 | 3 | 1.0s |  |
| 96 | `with-v6` | 43 | 43 | 1.1s |  |
| 97 | `with-v7` | 43 | 43 | 1.1s |  |
| 98 | `with-v8` | 43 | 43 | 1.1s |  |

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
