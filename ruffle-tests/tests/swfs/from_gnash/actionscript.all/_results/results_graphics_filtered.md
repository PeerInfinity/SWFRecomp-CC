# Ruffle Test Results (Filtered)

**Date**: 2026-07-04 18:46 UTC

**Git SHA**: `3c806aac09`

**Run Duration**: 39m 35s

**Filtered**: 7 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 236 |
| Passing | **132** (55.9%) |
| Ruffle-matched | 95 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **227** (96.2%) |
| Failing | 9 |
| Total expected lines | 31358 |
| Matching lines | 29253 (93.3%) |
| Mismatched lines | 2105 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**132 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.6s |  |
| 2 | `Accessibility-v6` | 19 | 2.7s |  |
| 3 | `Accessibility-v7` | 19 | 2.3s |  |
| 4 | `Accessibility-v8` | 19 | 1.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.6s |  |
| 6 | `BitmapData-v5` | 7 | 2.7s |  |
| 7 | `BitmapData-v6` | 7 | 1.2s |  |
| 8 | `BitmapData-v7` | 7 | 2.4s |  |
| 9 | `Boolean-v5` | 38 | 3.3s |  |
| 10 | `Boolean-v6` | 38 | 2.7s |  |
| 11 | `Boolean-v7` | 38 | 21.6s |  |
| 12 | `Boolean-v8` | 38 | 2.1s |  |
| 13 | `Camera-v5` | 7 | 1.9s |  |
| 14 | `Color-v5` | 140 | 5.9s |  |
| 15 | `Color-v6` | 171 | 6.9s |  |
| 16 | `Color-v7` | 161 | 6.6s |  |
| 17 | `Color-v8` | 161 | 21.9s |  |
| 18 | `ColorTransform-v5` | 7 | 2.2s |  |
| 19 | `ColorTransform-v6` | 7 | 1.1s |  |
| 20 | `ColorTransform-v7` | 7 | 2.1s |  |
| 21 | `ColorTransform-v8` | 55 | 3.5s |  |
| 22 | `ContextMenu-v5` | 7 | 2.4s |  |
| 23 | `ContextMenu-v6` | 7 | 1.1s |  |
| 24 | `ContextMenu-v7` | 131 | 4.9s |  |
| 25 | `ContextMenu-v8` | 131 | 23.8s |  |
| 26 | `Error-v5` | 28 | 3.0s |  |
| 27 | `Error-v6` | 31 | 3.1s |  |
| 28 | `Error-v7` | 31 | 2.8s |  |
| 29 | `Error-v8` | 31 | 24.6s |  |
| 30 | `ExternalInterface-v5` | 7 | 3.0s |  |
| 31 | `ExternalInterface-v6` | 55 | 4.1s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.7s |  |
| 33 | `Global-v5` | 172 | 7.9s |  |
| 34 | `Global-v7` | 182 | 8.0s |  |
| 35 | `Global-v8` | 169 | 7.5s |  |
| 36 | `Instance-v5` | 52 | 3.6s |  |
| 37 | `Instance-v6` | 52 | 2.1s |  |
| 38 | `Instance-v7` | 52 | 3.2s |  |
| 39 | `Instance-v8` | 52 | 2.2s |  |
| 40 | `Key-v5` | 51 | 22.5s |  |
| 41 | `Key-v6` | 55 | 3.7s |  |
| 42 | `Key-v7` | 55 | 3.3s |  |
| 43 | `Key-v8` | 55 | 2.2s |  |
| 44 | `LoadVars-v5` | 8 | 21.7s |  |
| 45 | `LocalConnection-v5` | 7 | 21.3s |  |
| 46 | `LocalConnection-v6` | 58 | 3.4s |  |
| 47 | `LocalConnection-v7` | 58 | 3.0s |  |
| 48 | `LocalConnection-v8` | 58 | 1.7s |  |
| 49 | `Matrix-v5` | 7 | 20.9s |  |
| 50 | `Microphone-v5` | 6 | 2.6s |  |
| 51 | `Mouse-v5` | 13 | 22.3s |  |
| 52 | `Mouse-v6` | 21 | 3.0s |  |
| 53 | `Mouse-v7` | 21 | 2.6s |  |
| 54 | `Mouse-v8` | 21 | 2.2s |  |
| 55 | `MovieClipLoader-v5` | 6 | 22.6s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.2s |  |
| 57 | `NetConnection-v5` | 7 | 22.2s |  |
| 58 | `NetStream-v5` | 6 | 22.7s |  |
| 59 | `NetStream-v6` | 80 | 4.4s |  |
| 60 | `NetStream-v7` | 80 | 4.0s |  |
| 61 | `NetStream-v8` | 80 | 2.1s |  |
| 62 | `Number-v6` | 239 | 9.8s |  |
| 63 | `Number-v7` | 237 | 9.7s |  |
| 64 | `Number-v8` | 237 | 2.2s |  |
| 65 | `Point-v5` | 7 | 22.2s |  |
| 66 | `Point-v6` | 7 | 1.2s |  |
| 67 | `Point-v7` | 7 | 2.4s |  |
| 68 | `Point-v8` | 193 | 9.0s |  |
| 69 | `Random-v5` | 30 | 21.6s |  |
| 70 | `Random-v6` | 30 | 1.2s |  |
| 71 | `Random-v7` | 30 | 2.8s |  |
| 72 | `Random-v8` | 30 | 2.1s |  |
| 73 | `Rectangle-v5` | 7 | 2.7s |  |
| 74 | `Rectangle-v6` | 7 | 1.2s |  |
| 75 | `Rectangle-v7` | 7 | 2.3s |  |
| 76 | `Selection-v5` | 21 | 23.0s |  |
| 77 | `Stage-v5` | 38 | 22.4s |  |
| 78 | `System-v5` | 67 | 24.3s |  |
| 79 | `System-v6` | 100 | 5.1s |  |
| 80 | `System-v7` | 101 | 5.0s |  |
| 81 | `System-v8` | 101 | 2.2s |  |
| 82 | `TextFieldHTML-v5` | 6 | 21.5s |  |
| 83 | `TextFieldHTML-v6` | 37 | 3.3s |  |
| 84 | `TextFieldHTML-v7` | 37 | 3.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 2.1s |  |
| 86 | `TextFormat-v5` | 128 | 5.7s |  |
| 87 | `TextFormat-v6` | 128 | 1.3s |  |
| 88 | `TextSnapshot-v5` | 7 | 21.1s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.4s |  |
| 90 | `TextSnapshot-v7` | 173 | 8.1s |  |
| 91 | `TextSnapshot-v8` | 173 | 2.0s |  |
| 92 | `Transform-v5` | 7 | 2.4s |  |
| 93 | `Transform-v6` | 7 | 1.9s |  |
| 94 | `Transform-v7` | 7 | 2.1s |  |
| 95 | `Try-v5` | 20 | 22.6s |  |
| 96 | `Try-v6` | 20 | 1.1s |  |
| 97 | `Try-v7` | 20 | 3.1s |  |
| 98 | `Try-v8` | 20 | 2.1s |  |
| 99 | `Video-v5` | 7 | 22.8s |  |
| 100 | `Video-v6` | 85 | 4.0s |  |
| 101 | `Video-v7` | 85 | 3.8s |  |
| 102 | `Video-v8` | 85 | 2.0s |  |
| 103 | `XMLSocket-v5` | 35 | 22.6s |  |
| 104 | `XMLSocket-v6` | 35 | 3.2s |  |
| 105 | `XMLSocket-v7` | 35 | 2.8s |  |
| 106 | `XMLSocket-v8` | 35 | 2.1s |  |
| 107 | `argstest-v5` | 4 | 2.7s |  |
| 108 | `case-v5` | 39 | 3.5s |  |
| 109 | `case-v6` | 73 | 4.5s |  |
| 110 | `case-v7` | 67 | 4.5s |  |
| 111 | `case-v8` | 67 | 2.3s |  |
| 112 | `delete-v5` | 61 | 22.3s |  |
| 113 | `delete-v6` | 61 | 2.9s |  |
| 114 | `delete-v7` | 61 | 3.1s |  |
| 115 | `delete-v8` | 61 | 2.1s |  |
| 116 | `enumerate-v5` | 6 | 2.4s |  |
| 117 | `enumerate-v6` | 49 | 3.5s |  |
| 118 | `enumerate-v7` | 49 | 3.1s |  |
| 119 | `enumerate-v8` | 49 | 2.0s |  |
| 120 | `flash-v5` | 10 | 21.6s |  |
| 121 | `flash-v6` | 10 | 2.8s |  |
| 122 | `flash-v7` | 10 | 2.4s |  |
| 123 | `flash-v8` | 41 | 22.4s |  |
| 124 | `getvariable-v6` | 64 | 4.1s |  |
| 125 | `swap-v5` | 7 | 20.4s |  |
| 126 | `swap-v6` | 7 | 1.0s |  |
| 127 | `swap-v7` | 7 | 1.0s |  |
| 128 | `swap-v8` | 7 | 1.1s |  |
| 129 | `targetPath-v5` | 12 | 1.0s |  |
| 130 | `targetPath-v6` | 23 | 1.1s |  |
| 131 | `targetPath-v7` | 23 | 1.0s |  |
| 132 | `targetPath-v8` | 23 | 1.1s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 24.3s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.5s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.0s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 24.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.6s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.1s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.5s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.2s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.1s |  |
| 12 | `Date-v5` | 7 | 7 | 32.1s |  |
| 13 | `Date-v6` | 6 | 6 | 14.8s |  |
| 14 | `Date-v7` | 6 | 6 | 16.5s |  |
| 15 | `Date-v8` | 6 | 6 | 2.6s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 6.5s |  |
| 17 | `Function-v5` | 14 | 24 | 28.2s |  |
| 18 | `Function-v6` | 8 | 33 | 11.7s |  |
| 19 | `Function-v7` | 8 | 33 | 12.2s |  |
| 20 | `Function-v8` | 8 | 33 | 29.8s |  |
| 21 | `Global-v6` | 9 | 10 | 28.4s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.7s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.4s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.2s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 24.2s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 7.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 7.5s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.8s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.2s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.8s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 3.0s |  |
| 32 | `Math-v5` | 5 | 5 | 13.8s |  |
| 33 | `Math-v6` | 5 | 5 | 1.4s |  |
| 34 | `Math-v7` | 5 | 5 | 14.1s |  |
| 35 | `Math-v8` | 5 | 5 | 2.0s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.7s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.6s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.2s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.0s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.6s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.1s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 34.6s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.8s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.4s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.9s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.9s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.4s |  |
| 48 | `Number-v5` | 8 | 12 | 10.1s |  |
| 49 | `Object-v5` | 3 | 6 | 26.2s |  |
| 50 | `Object-v6` | 9 | 24 | 14.1s |  |
| 51 | `Object-v7` | 8 | 15 | 14.2s |  |
| 52 | `Object-v8` | 8 | 15 | 3.0s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 7.7s |  |
| 54 | `Selection-v6` | 7 | 13 | 6.7s |  |
| 55 | `Selection-v7` | 7 | 13 | 6.0s |  |
| 56 | `Selection-v8` | 7 | 13 | 2.4s |  |
| 57 | `Sound-v5` | 16 | 16 | 25.7s |  |
| 58 | `Sound-v6` | 8 | 37 | 6.3s |  |
| 59 | `Sound-v7` | 8 | 37 | 6.0s |  |
| 60 | `Sound-v8` | 8 | 37 | 2.8s |  |
| 61 | `Stage-v6` | 14 | 14 | 23.2s |  |
| 62 | `Stage-v7` | 14 | 14 | 3.6s |  |
| 63 | `Stage-v8` | 14 | 14 | 2.4s |  |
| 64 | `String-v5` | 19 | 21 | 17.3s |  |
| 65 | `String-v6` | 10 | 10 | 18.2s |  |
| 66 | `String-v7` | 10 | 10 | 18.0s |  |
| 67 | `String-v8` | 10 | 10 | 2.8s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.9s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 7.4s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 26.2s |  |
| 71 | `Transform-v8` | 7 | 11 | 24.3s |  |
| 72 | `XML-v5` | 10 | 79 | 33.5s |  |
| 73 | `XML-v6` | 3 | 98 | 16.4s |  |
| 74 | `XML-v7` | 3 | 98 | 15.9s |  |
| 75 | `XML-v8` | 24 | 116 | 5.3s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 8.9s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 8.9s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 7.9s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 2.5s |  |
| 80 | `ops-v5` | 7 | 9 | 30.3s |  |
| 81 | `ops-v6` | 7 | 11 | 10.2s |  |
| 82 | `ops-v7` | 7 | 11 | 10.7s |  |
| 83 | `ops-v8` | 7 | 11 | 21.3s |  |
| 84 | `setProperty-v5` | 49 | 49 | 3.9s |  |
| 85 | `setProperty-v6` | 49 | 49 | 4.0s |  |
| 86 | `setProperty-v7` | 49 | 49 | 3.7s |  |
| 87 | `setProperty-v8` | 49 | 49 | 2.6s |  |
| 88 | `toString_valueOf-v5` | 34 | 34 | 25.9s |  |
| 89 | `toString_valueOf-v6` | 5 | 5 | 6.5s |  |
| 90 | `toString_valueOf-v7` | 5 | 5 | 6.2s |  |
| 91 | `toString_valueOf-v8` | 5 | 5 | 2.3s |  |
| 92 | `with-v5` | 3 | 3 | 4.3s |  |
| 93 | `with-v6` | 6 | 9 | 5.8s |  |
| 94 | `with-v7` | 6 | 9 | 5.3s |  |
| 95 | `with-v8` | 6 | 9 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**9 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v6` | 96.9% | 624 | 644 | 20 |  |
| 2 | `MovieClip-v7` | 96.4% | 934 | 969 | 35 |  |
| 3 | `MovieClip-v6` | 96.3% | 901 | 936 | 35 |  |
| 4 | `MovieClip-v8` | 93.8% | 1020 | 1087 | 67 |  |
| 5 | `array-v7` | 92.2% | 603 | 654 | 51 |  |
| 6 | `array-v8` | 92.2% | 603 | 654 | 51 |  |
| 7 | `TextField-v6` | 85.5% | 466 | 545 | 79 |  |
| 8 | `TextField-v8` | 83.5% | 477 | 571 | 94 |  |
| 9 | `TextField-v7` | 83.3% | 475 | 570 | 95 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v6` | 96.9% | 624/644 | 644 | 644 |  |
| 2 | `MovieClip-v7` | 96.4% | 934/969 | 954 | 969 |  |
| 3 | `MovieClip-v6` | 96.3% | 901/936 | 921 | 936 |  |
| 4 | `MovieClip-v8` | 93.8% | 1020/1087 | 1072 | 1087 |  |
| 5 | `array-v7` | 92.2% | 603/654 | 654 | 654 |  |
| 6 | `array-v8` | 92.2% | 603/654 | 654 | 654 |  |
| 7 | `TextField-v6` | 85.5% | 466/545 | 545 | 545 |  |
| 8 | `TextField-v8` | 83.5% | 477/571 | 571 | 571 |  |
| 9 | `TextField-v7` | 83.3% | 475/570 | 570 | 570 |  |
