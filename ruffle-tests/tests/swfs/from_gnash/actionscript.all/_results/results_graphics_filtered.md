# Ruffle Test Results (Filtered)

**Date**: 2026-06-16 19:39 UTC

**Git SHA**: `886c8b0e4f`

**Run Duration**: 30m 7s

**Filtered**: 6 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 237 |
| Passing | **132** (55.7%) |
| Ruffle-matched | 95 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **227** (95.8%) |
| Failing | 10 |
| Total expected lines | 31918 |
| Matching lines | 29630 (92.8%) |
| Mismatched lines | 2288 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 10 | 100.0% |

## Passing Tests

**132 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.1s |  |
| 2 | `Accessibility-v6` | 19 | 3.1s |  |
| 3 | `Accessibility-v7` | 19 | 2.8s |  |
| 4 | `Accessibility-v8` | 19 | 2.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.9s |  |
| 6 | `BitmapData-v5` | 7 | 2.7s |  |
| 7 | `BitmapData-v6` | 7 | 1.2s |  |
| 8 | `BitmapData-v7` | 7 | 2.3s |  |
| 9 | `Boolean-v5` | 38 | 3.2s |  |
| 10 | `Boolean-v6` | 38 | 2.6s |  |
| 11 | `Boolean-v7` | 38 | 3.3s |  |
| 12 | `Boolean-v8` | 38 | 2.2s |  |
| 13 | `Camera-v5` | 7 | 1.8s |  |
| 14 | `Color-v5` | 140 | 6.3s |  |
| 15 | `Color-v6` | 171 | 7.4s |  |
| 16 | `Color-v7` | 161 | 7.2s |  |
| 17 | `Color-v8` | 161 | 7.6s |  |
| 18 | `ColorTransform-v5` | 7 | 2.9s |  |
| 19 | `ColorTransform-v6` | 7 | 1.3s |  |
| 20 | `ColorTransform-v7` | 7 | 2.5s |  |
| 21 | `ColorTransform-v8` | 55 | 4.4s |  |
| 22 | `ContextMenu-v5` | 7 | 2.9s |  |
| 23 | `ContextMenu-v6` | 7 | 1.3s |  |
| 24 | `ContextMenu-v7` | 131 | 6.0s |  |
| 25 | `ContextMenu-v8` | 131 | 5.7s |  |
| 26 | `Error-v5` | 28 | 3.1s |  |
| 27 | `Error-v6` | 31 | 3.2s |  |
| 28 | `Error-v7` | 31 | 2.8s |  |
| 29 | `Error-v8` | 31 | 3.3s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.7s |  |
| 32 | `ExternalInterface-v7` | 55 | 3.3s |  |
| 33 | `Global-v5` | 172 | 8.0s |  |
| 34 | `Global-v7` | 182 | 8.2s |  |
| 35 | `Global-v8` | 169 | 7.7s |  |
| 36 | `Instance-v5` | 52 | 3.8s |  |
| 37 | `Instance-v6` | 52 | 2.3s |  |
| 38 | `Instance-v7` | 52 | 3.4s |  |
| 39 | `Instance-v8` | 52 | 2.3s |  |
| 40 | `Key-v5` | 51 | 3.6s |  |
| 41 | `Key-v6` | 55 | 3.6s |  |
| 42 | `Key-v7` | 55 | 3.3s |  |
| 43 | `Key-v8` | 55 | 2.1s |  |
| 44 | `LoadVars-v5` | 8 | 21.9s |  |
| 45 | `LocalConnection-v5` | 7 | 1.2s |  |
| 46 | `LocalConnection-v6` | 58 | 1.2s |  |
| 47 | `LocalConnection-v7` | 58 | 1.1s |  |
| 48 | `LocalConnection-v8` | 58 | 1.1s |  |
| 49 | `Matrix-v5` | 7 | 2.6s |  |
| 50 | `Microphone-v5` | 6 | 2.6s |  |
| 51 | `Mouse-v5` | 13 | 3.0s |  |
| 52 | `Mouse-v6` | 21 | 3.2s |  |
| 53 | `Mouse-v7` | 21 | 2.8s |  |
| 54 | `Mouse-v8` | 21 | 2.3s |  |
| 55 | `MovieClipLoader-v5` | 6 | 21.4s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.2s |  |
| 57 | `NetConnection-v5` | 7 | 2.7s |  |
| 58 | `NetStream-v5` | 6 | 2.7s |  |
| 59 | `NetStream-v6` | 80 | 4.3s |  |
| 60 | `NetStream-v7` | 80 | 4.0s |  |
| 61 | `NetStream-v8` | 80 | 2.2s |  |
| 62 | `Number-v6` | 239 | 10.0s |  |
| 63 | `Number-v7` | 237 | 9.8s |  |
| 64 | `Number-v8` | 237 | 2.4s |  |
| 65 | `Point-v5` | 7 | 2.6s |  |
| 66 | `Point-v6` | 7 | 1.2s |  |
| 67 | `Point-v7` | 7 | 2.3s |  |
| 68 | `Point-v8` | 193 | 8.3s |  |
| 69 | `Random-v5` | 30 | 3.4s |  |
| 70 | `Random-v6` | 30 | 1.3s |  |
| 71 | `Random-v7` | 30 | 3.1s |  |
| 72 | `Random-v8` | 30 | 2.4s |  |
| 73 | `Rectangle-v5` | 7 | 2.9s |  |
| 74 | `Rectangle-v6` | 7 | 1.3s |  |
| 75 | `Rectangle-v7` | 7 | 2.6s |  |
| 76 | `Selection-v5` | 21 | 3.0s |  |
| 77 | `Stage-v5` | 38 | 3.5s |  |
| 78 | `System-v5` | 67 | 3.8s |  |
| 79 | `System-v6` | 100 | 4.6s |  |
| 80 | `System-v7` | 101 | 4.7s |  |
| 81 | `System-v8` | 101 | 2.1s |  |
| 82 | `TextFieldHTML-v5` | 6 | 2.7s |  |
| 83 | `TextFieldHTML-v6` | 37 | 3.4s |  |
| 84 | `TextFieldHTML-v7` | 37 | 3.0s |  |
| 85 | `TextFieldHTML-v8` | 37 | 2.1s |  |
| 86 | `TextFormat-v5` | 128 | 5.9s |  |
| 87 | `TextFormat-v6` | 128 | 1.2s |  |
| 88 | `TextSnapshot-v5` | 7 | 2.7s |  |
| 89 | `TextSnapshot-v6` | 173 | 8.3s |  |
| 90 | `TextSnapshot-v7` | 173 | 8.1s |  |
| 91 | `TextSnapshot-v8` | 173 | 2.3s |  |
| 92 | `Transform-v5` | 7 | 2.7s |  |
| 93 | `Transform-v6` | 7 | 2.1s |  |
| 94 | `Transform-v7` | 7 | 2.3s |  |
| 95 | `Try-v5` | 20 | 3.7s |  |
| 96 | `Try-v6` | 20 | 1.2s |  |
| 97 | `Try-v7` | 20 | 3.3s |  |
| 98 | `Try-v8` | 20 | 2.1s |  |
| 99 | `Video-v5` | 7 | 21.3s |  |
| 100 | `Video-v6` | 85 | 4.4s |  |
| 101 | `Video-v7` | 85 | 4.0s |  |
| 102 | `Video-v8` | 85 | 2.2s |  |
| 103 | `XMLSocket-v5` | 35 | 3.5s |  |
| 104 | `XMLSocket-v6` | 35 | 3.5s |  |
| 105 | `XMLSocket-v7` | 35 | 3.1s |  |
| 106 | `XMLSocket-v8` | 35 | 2.5s |  |
| 107 | `argstest-v5` | 4 | 3.0s |  |
| 108 | `case-v5` | 39 | 3.7s |  |
| 109 | `case-v6` | 73 | 4.8s |  |
| 110 | `case-v7` | 67 | 4.7s |  |
| 111 | `case-v8` | 67 | 2.4s |  |
| 112 | `delete-v5` | 61 | 3.6s |  |
| 113 | `delete-v6` | 61 | 3.0s |  |
| 114 | `delete-v7` | 61 | 3.3s |  |
| 115 | `delete-v8` | 61 | 2.2s |  |
| 116 | `enumerate-v5` | 6 | 2.5s |  |
| 117 | `enumerate-v6` | 49 | 3.7s |  |
| 118 | `enumerate-v7` | 49 | 3.3s |  |
| 119 | `enumerate-v8` | 49 | 2.0s |  |
| 120 | `flash-v5` | 10 | 2.6s |  |
| 121 | `flash-v6` | 10 | 2.6s |  |
| 122 | `flash-v7` | 10 | 2.2s |  |
| 123 | `flash-v8` | 41 | 23.1s |  |
| 124 | `getvariable-v6` | 64 | 4.1s |  |
| 125 | `swap-v5` | 7 | 0.8s |  |
| 126 | `swap-v6` | 7 | 0.8s |  |
| 127 | `swap-v7` | 7 | 0.8s |  |
| 128 | `swap-v8` | 7 | 0.8s |  |
| 129 | `targetPath-v5` | 12 | 0.8s |  |
| 130 | `targetPath-v6` | 23 | 0.8s |  |
| 131 | `targetPath-v7` | 23 | 0.8s |  |
| 132 | `targetPath-v8` | 23 | 0.8s |  |

## Ruffle-Matched Tests

**95 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 7.3s |  |
| 2 | `ASnative-v6` | 40 | 40 | 7.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 6.7s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.4s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.8s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.4s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.3s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 24.4s |  |
| 9 | `Camera-v6` | 57 | 57 | 4.8s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.5s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.2s |  |
| 12 | `Date-v5` | 7 | 7 | 33.1s |  |
| 13 | `Date-v6` | 6 | 6 | 15.5s |  |
| 14 | `Date-v7` | 6 | 6 | 16.2s |  |
| 15 | `Date-v8` | 6 | 6 | 2.7s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 5.8s |  |
| 17 | `Function-v5` | 14 | 24 | 26.1s |  |
| 18 | `Function-v6` | 8 | 33 | 10.8s |  |
| 19 | `Function-v7` | 8 | 33 | 10.9s |  |
| 20 | `Function-v8` | 8 | 33 | 29.6s |  |
| 21 | `Global-v6` | 9 | 10 | 9.2s |  |
| 22 | `HitTest-v6` | 8 | 8 | 5.8s |  |
| 23 | `HitTest-v7` | 8 | 8 | 5.3s |  |
| 24 | `HitTest-v8` | 9 | 9 | 5.2s |  |
| 25 | `Inheritance-v5` | 1 | 17 | 5.8s |  |
| 26 | `Inheritance-v6` | 9 | 16 | 8.2s |  |
| 27 | `Inheritance-v7` | 5 | 10 | 8.1s |  |
| 28 | `Inheritance-v8` | 5 | 10 | 2.9s |  |
| 29 | `LoadVars-v6` | 6 | 8 | 6.1s |  |
| 30 | `LoadVars-v7` | 6 | 8 | 5.8s |  |
| 31 | `LoadVars-v8` | 6 | 8 | 2.9s |  |
| 32 | `Math-v5` | 5 | 5 | 1.3s |  |
| 33 | `Math-v6` | 5 | 5 | 1.3s |  |
| 34 | `Math-v7` | 5 | 5 | 1.4s |  |
| 35 | `Math-v8` | 5 | 5 | 1.4s |  |
| 36 | `Matrix-v6` | 29 | 71 | 7.9s |  |
| 37 | `Matrix-v7` | 28 | 70 | 7.9s |  |
| 38 | `Matrix-v8` | 28 | 70 | 2.3s |  |
| 39 | `Microphone-v6` | 31 | 31 | 4.1s |  |
| 40 | `Microphone-v7` | 31 | 31 | 3.7s |  |
| 41 | `Microphone-v8` | 31 | 31 | 2.1s |  |
| 42 | `MovieClip-v5` | 24 | 226 | 35.0s |  |
| 43 | `MovieClipLoader-v7` | 118 | 118 | 4.7s |  |
| 44 | `MovieClipLoader-v8` | 118 | 118 | 3.3s |  |
| 45 | `NetConnection-v6` | 4 | 49 | 5.7s |  |
| 46 | `NetConnection-v7` | 4 | 45 | 5.7s |  |
| 47 | `NetConnection-v8` | 4 | 45 | 2.3s |  |
| 48 | `Number-v5` | 8 | 12 | 10.0s |  |
| 49 | `Object-v5` | 3 | 6 | 24.9s |  |
| 50 | `Object-v6` | 9 | 24 | 12.9s |  |
| 51 | `Object-v7` | 8 | 15 | 13.4s |  |
| 52 | `Object-v8` | 8 | 15 | 2.9s |  |
| 53 | `Rectangle-v8` | 21 | 21 | 8.4s |  |
| 54 | `Selection-v6` | 7 | 13 | 6.2s |  |
| 55 | `Selection-v7` | 7 | 13 | 5.9s |  |
| 56 | `Selection-v8` | 7 | 13 | 2.3s |  |
| 57 | `Sound-v5` | 16 | 16 | 25.7s |  |
| 58 | `Sound-v6` | 8 | 37 | 6.4s |  |
| 59 | `Sound-v7` | 8 | 37 | 6.0s |  |
| 60 | `Sound-v8` | 8 | 37 | 2.7s |  |
| 61 | `Stage-v6` | 14 | 14 | 23.9s |  |
| 62 | `Stage-v7` | 14 | 14 | 3.9s |  |
| 63 | `Stage-v8` | 14 | 14 | 2.5s |  |
| 64 | `String-v5` | 19 | 21 | 18.3s |  |
| 65 | `String-v6` | 10 | 10 | 19.1s |  |
| 66 | `String-v7` | 10 | 10 | 18.4s |  |
| 67 | `String-v8` | 10 | 10 | 2.8s |  |
| 68 | `TextField-v5` | 3 | 3 | 2.7s |  |
| 69 | `TextFormat-v7` | 38 | 40 | 7.4s |  |
| 70 | `TextFormat-v8` | 36 | 38 | 26.1s |  |
| 71 | `Transform-v8` | 7 | 11 | 24.6s |  |
| 72 | `XML-v5` | 10 | 79 | 34.0s |  |
| 73 | `XML-v6` | 3 | 98 | 17.1s |  |
| 74 | `XML-v7` | 3 | 98 | 16.8s |  |
| 75 | `XML-v8` | 24 | 116 | 5.5s |  |
| 76 | `XMLNode-v5` | 3 | 22 | 9.6s |  |
| 77 | `XMLNode-v6` | 3 | 22 | 9.6s |  |
| 78 | `XMLNode-v7` | 3 | 22 | 8.4s |  |
| 79 | `XMLNode-v8` | 3 | 22 | 2.5s |  |
| 80 | `ops-v5` | 7 | 9 | 29.4s |  |
| 81 | `ops-v6` | 7 | 11 | 10.1s |  |
| 82 | `ops-v7` | 7 | 11 | 10.8s |  |
| 83 | `ops-v8` | 7 | 11 | 2.5s |  |
| 84 | `setProperty-v5` | 49 | 49 | 3.8s |  |
| 85 | `setProperty-v6` | 49 | 49 | 3.9s |  |
| 86 | `setProperty-v7` | 49 | 49 | 3.5s |  |
| 87 | `setProperty-v8` | 49 | 49 | 2.6s |  |
| 88 | `toString_valueOf-v5` | 34 | 34 | 6.5s |  |
| 89 | `toString_valueOf-v6` | 5 | 5 | 6.9s |  |
| 90 | `toString_valueOf-v7` | 5 | 5 | 6.7s |  |
| 91 | `toString_valueOf-v8` | 5 | 5 | 2.4s |  |
| 92 | `with-v5` | 3 | 3 | 4.6s |  |
| 93 | `with-v6` | 6 | 9 | 6.0s |  |
| 94 | `with-v7` | 6 | 9 | 5.7s |  |
| 95 | `with-v8` | 6 | 9 | 2.6s |  |

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
