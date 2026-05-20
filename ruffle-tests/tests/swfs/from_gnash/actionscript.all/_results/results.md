# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-20 01:39 UTC

**Git SHA**: `747c91f86f`

**Run Duration**: 15m 55s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **128** (52.7%) |
| Ruffle-matched | 77 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **205** (84.4%) |
| Failing | 38 |
| Total expected lines | 38787 |
| Matching lines | 27910 (72.0%) |
| Mismatched lines | 10877 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 38 | 100.0% |

## Passing Tests

**128 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.3s |  |
| 3 | `Accessibility-v7` | 19 | 0.3s |  |
| 4 | `Accessibility-v8` | 19 | 0.3s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.3s |  |
| 6 | `BitmapData-v5` | 7 | 0.4s |  |
| 7 | `BitmapData-v6` | 7 | 0.4s |  |
| 8 | `BitmapData-v7` | 7 | 0.4s |  |
| 9 | `Boolean-v5` | 38 | 0.4s |  |
| 10 | `Boolean-v6` | 38 | 0.4s |  |
| 11 | `Boolean-v7` | 38 | 17.5s |  |
| 12 | `Boolean-v8` | 38 | 0.3s |  |
| 13 | `Camera-v5` | 7 | 0.3s |  |
| 14 | `Color-v5` | 140 | 0.4s |  |
| 15 | `Color-v6` | 171 | 0.4s |  |
| 16 | `Color-v7` | 161 | 0.4s |  |
| 17 | `Color-v8` | 161 | 18.1s |  |
| 18 | `ColorTransform-v5` | 7 | 0.4s |  |
| 19 | `ColorTransform-v6` | 7 | 0.4s |  |
| 20 | `ColorTransform-v7` | 7 | 0.4s |  |
| 21 | `ColorTransform-v8` | 55 | 0.4s |  |
| 22 | `ContextMenu-v5` | 7 | 0.4s |  |
| 23 | `ContextMenu-v6` | 7 | 0.4s |  |
| 24 | `ContextMenu-v7` | 131 | 0.4s |  |
| 25 | `ContextMenu-v8` | 131 | 18.8s |  |
| 26 | `Error-v5` | 28 | 0.4s |  |
| 27 | `Error-v6` | 31 | 0.4s |  |
| 28 | `Error-v7` | 31 | 0.4s |  |
| 29 | `Error-v8` | 31 | 17.6s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.3s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.4s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.4s |  |
| 33 | `Global-v5` | 172 | 0.5s |  |
| 34 | `Global-v7` | 182 | 0.5s |  |
| 35 | `Global-v8` | 169 | 0.5s |  |
| 36 | `Instance-v5` | 52 | 0.3s |  |
| 37 | `Instance-v6` | 52 | 0.3s |  |
| 38 | `Instance-v7` | 52 | 0.3s |  |
| 39 | `Instance-v8` | 52 | 0.3s |  |
| 40 | `Key-v5` | 51 | 19.1s |  |
| 41 | `Key-v6` | 55 | 0.4s |  |
| 42 | `Key-v7` | 55 | 0.4s |  |
| 43 | `Key-v8` | 55 | 0.4s |  |
| 44 | `LoadVars-v5` | 8 | 19.0s |  |
| 45 | `LocalConnection-v5` | 7 | 18.0s |  |
| 46 | `LocalConnection-v6` | 58 | 0.4s |  |
| 47 | `LocalConnection-v7` | 58 | 0.4s |  |
| 48 | `LocalConnection-v8` | 58 | 0.4s |  |
| 49 | `Matrix-v5` | 7 | 17.4s |  |
| 50 | `Microphone-v5` | 6 | 0.3s |  |
| 51 | `Mouse-v5` | 13 | 15.9s |  |
| 52 | `Mouse-v6` | 21 | 0.3s |  |
| 53 | `Mouse-v7` | 21 | 0.3s |  |
| 54 | `Mouse-v8` | 21 | 0.3s |  |
| 55 | `MovieClipLoader-v5` | 6 | 18.4s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.4s |  |
| 57 | `NetConnection-v5` | 7 | 18.1s |  |
| 58 | `NetStream-v5` | 6 | 17.6s |  |
| 59 | `NetStream-v6` | 80 | 0.3s |  |
| 60 | `NetStream-v7` | 80 | 0.3s |  |
| 61 | `NetStream-v8` | 80 | 0.3s |  |
| 62 | `Number-v6` | 239 | 0.4s |  |
| 63 | `Number-v7` | 237 | 0.4s |  |
| 64 | `Number-v8` | 237 | 0.4s |  |
| 65 | `Point-v5` | 7 | 18.4s |  |
| 66 | `Point-v6` | 7 | 0.3s |  |
| 67 | `Point-v7` | 7 | 0.3s |  |
| 68 | `Point-v8` | 193 | 0.4s |  |
| 69 | `Random-v5` | 30 | 18.3s |  |
| 70 | `Random-v6` | 30 | 0.4s |  |
| 71 | `Random-v7` | 30 | 0.4s |  |
| 72 | `Random-v8` | 30 | 0.4s |  |
| 73 | `Rectangle-v5` | 7 | 0.4s |  |
| 74 | `Rectangle-v6` | 7 | 0.4s |  |
| 75 | `Rectangle-v7` | 7 | 0.4s |  |
| 76 | `Selection-v5` | 21 | 18.3s |  |
| 77 | `Stage-v5` | 38 | 19.2s |  |
| 78 | `System-v5` | 67 | 18.0s |  |
| 79 | `System-v6` | 100 | 0.4s |  |
| 80 | `System-v7` | 101 | 0.4s |  |
| 81 | `System-v8` | 101 | 0.4s |  |
| 82 | `TextFieldHTML-v5` | 6 | 20.1s |  |
| 83 | `TextFieldHTML-v6` | 37 | 0.4s |  |
| 84 | `TextFieldHTML-v7` | 37 | 0.4s |  |
| 85 | `TextFieldHTML-v8` | 37 | 0.4s |  |
| 86 | `TextFormat-v5` | 128 | 0.5s |  |
| 87 | `TextFormat-v6` | 128 | 0.4s |  |
| 88 | `TextSnapshot-v5` | 7 | 18.1s |  |
| 89 | `TextSnapshot-v6` | 173 | 0.4s |  |
| 90 | `TextSnapshot-v7` | 173 | 0.4s |  |
| 91 | `TextSnapshot-v8` | 173 | 0.4s |  |
| 92 | `Transform-v5` | 7 | 0.3s |  |
| 93 | `Transform-v6` | 7 | 0.3s |  |
| 94 | `Transform-v7` | 7 | 0.3s |  |
| 95 | `Try-v5` | 20 | 18.2s |  |
| 96 | `Try-v6` | 20 | 0.4s |  |
| 97 | `Try-v7` | 20 | 0.4s |  |
| 98 | `Try-v8` | 20 | 0.4s |  |
| 99 | `Video-v5` | 7 | 18.4s |  |
| 100 | `Video-v6` | 85 | 0.4s |  |
| 101 | `Video-v7` | 85 | 0.4s |  |
| 102 | `Video-v8` | 85 | 0.4s |  |
| 103 | `XMLSocket-v5` | 35 | 18.5s |  |
| 104 | `XMLSocket-v6` | 35 | 0.4s |  |
| 105 | `XMLSocket-v7` | 35 | 0.4s |  |
| 106 | `XMLSocket-v8` | 35 | 0.4s |  |
| 107 | `argstest-v5` | 4 | 0.4s |  |
| 108 | `case-v5` | 39 | 0.3s |  |
| 109 | `case-v6` | 73 | 0.4s |  |
| 110 | `case-v7` | 67 | 0.4s |  |
| 111 | `case-v8` | 67 | 0.4s |  |
| 112 | `delete-v5` | 60 | 14.6s |  |
| 113 | `delete-v6` | 60 | 0.3s |  |
| 114 | `delete-v7` | 60 | 0.3s |  |
| 115 | `delete-v8` | 60 | 0.3s |  |
| 116 | `enumerate-v5` | 6 | 0.3s |  |
| 117 | `enumerate-v6` | 49 | 0.3s |  |
| 118 | `enumerate-v7` | 49 | 0.3s |  |
| 119 | `enumerate-v8` | 49 | 0.3s |  |
| 120 | `flash-v5` | 10 | 14.4s |  |
| 121 | `flash-v6` | 10 | 0.3s |  |
| 122 | `flash-v7` | 10 | 0.3s |  |
| 123 | `flash-v8` | 41 | 14.4s |  |
| 124 | `swap-v5` | 7 | 18.3s |  |
| 125 | `swap-v6` | 7 | 0.4s |  |
| 126 | `swap-v7` | 7 | 0.4s |  |
| 127 | `swap-v8` | 7 | 0.4s |  |
| 128 | `targetPath-v5` | 12 | 0.4s |  |

## Ruffle-Matched Tests

**77 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 17.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.4s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.4s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.4s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 18.2s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.4s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.9s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.4s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.4s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.4s |  |
| 12 | `Date-v5` | 7 | 7 | 19.6s |  |
| 13 | `Date-v6` | 6 | 6 | 0.7s |  |
| 14 | `Date-v7` | 6 | 6 | 0.7s |  |
| 15 | `Date-v8` | 6 | 6 | 0.7s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 0.4s |  |
| 17 | `Global-v6` | 9 | 10 | 18.7s |  |
| 18 | `HitTest-v6` | 8 | 8 | 0.4s |  |
| 19 | `HitTest-v7` | 8 | 8 | 0.4s |  |
| 20 | `HitTest-v8` | 9 | 9 | 0.4s |  |
| 21 | `Inheritance-v5` | 1 | 17 | 18.1s |  |
| 22 | `Inheritance-v6` | 9 | 16 | 0.4s |  |
| 23 | `Inheritance-v7` | 5 | 10 | 0.4s |  |
| 24 | `Inheritance-v8` | 5 | 10 | 0.4s |  |
| 25 | `LoadVars-v6` | 6 | 8 | 0.4s |  |
| 26 | `LoadVars-v7` | 6 | 8 | 0.4s |  |
| 27 | `LoadVars-v8` | 6 | 8 | 0.4s |  |
| 28 | `Math-v5` | 5 | 5 | 0.6s |  |
| 29 | `Math-v6` | 5 | 5 | 0.6s |  |
| 30 | `Math-v7` | 5 | 5 | 0.6s |  |
| 31 | `Math-v8` | 5 | 5 | 0.6s |  |
| 32 | `Matrix-v6` | 29 | 71 | 0.3s |  |
| 33 | `Matrix-v7` | 28 | 70 | 0.4s |  |
| 34 | `Matrix-v8` | 28 | 70 | 0.4s |  |
| 35 | `Microphone-v6` | 31 | 31 | 0.4s |  |
| 36 | `Microphone-v7` | 31 | 31 | 0.4s |  |
| 37 | `Microphone-v8` | 31 | 31 | 0.4s |  |
| 38 | `MovieClip-v5` | 48 | 226 | 16.6s |  |
| 39 | `MovieClipLoader-v7` | 118 | 118 | 0.4s |  |
| 40 | `MovieClipLoader-v8` | 118 | 118 | 0.4s |  |
| 41 | `NetConnection-v6` | 4 | 49 | 0.4s |  |
| 42 | `NetConnection-v7` | 4 | 45 | 0.4s |  |
| 43 | `NetConnection-v8` | 4 | 45 | 0.4s |  |
| 44 | `Number-v5` | 8 | 13 | 0.4s |  |
| 45 | `Object-v5` | 3 | 7 | 18.6s |  |
| 46 | `Rectangle-v8` | 21 | 21 | 0.5s |  |
| 47 | `Selection-v6` | 7 | 13 | 0.4s |  |
| 48 | `Selection-v7` | 7 | 13 | 0.4s |  |
| 49 | `Selection-v8` | 7 | 13 | 0.4s |  |
| 50 | `Stage-v6` | 14 | 14 | 19.1s |  |
| 51 | `Stage-v7` | 14 | 14 | 0.4s |  |
| 52 | `Stage-v8` | 14 | 14 | 0.4s |  |
| 53 | `String-v5` | 19 | 21 | 0.7s |  |
| 54 | `String-v6` | 10 | 10 | 0.7s |  |
| 55 | `String-v7` | 10 | 10 | 0.7s |  |
| 56 | `String-v8` | 10 | 10 | 0.7s |  |
| 57 | `TextField-v5` | 3 | 3 | 0.3s |  |
| 58 | `TextFormat-v7` | 38 | 40 | 0.5s |  |
| 59 | `ops-v5` | 7 | 9 | 18.4s |  |
| 60 | `ops-v6` | 7 | 11 | 0.5s |  |
| 61 | `ops-v7` | 7 | 11 | 0.4s |  |
| 62 | `ops-v8` | 7 | 11 | 18.2s |  |
| 63 | `setProperty-v5` | 49 | 49 | 0.4s |  |
| 64 | `setProperty-v6` | 49 | 49 | 0.4s |  |
| 65 | `setProperty-v7` | 49 | 49 | 0.4s |  |
| 66 | `setProperty-v8` | 49 | 49 | 0.4s |  |
| 67 | `targetPath-v6` | 17 | 17 | 0.4s |  |
| 68 | `targetPath-v7` | 17 | 17 | 0.4s |  |
| 69 | `targetPath-v8` | 17 | 17 | 0.4s |  |
| 70 | `toString_valueOf-v5` | 34 | 34 | 18.3s |  |
| 71 | `toString_valueOf-v6` | 5 | 5 | 0.4s |  |
| 72 | `toString_valueOf-v7` | 5 | 5 | 0.4s |  |
| 73 | `toString_valueOf-v8` | 5 | 5 | 0.4s |  |
| 74 | `with-v5` | 42 | 42 | 0.4s |  |
| 75 | `with-v6` | 91 | 91 | 0.4s |  |
| 76 | `with-v7` | 91 | 91 | 0.4s |  |
| 77 | `with-v8` | 91 | 91 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**35 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |
| 2 | `array-v6` | 93.8% | 604 | 644 | 40 |  |
| 3 | `getvariable-v7` | 92.2% | 59 | 64 | 5 |  |
| 4 | `getvariable-v8` | 92.2% | 59 | 64 | 5 |  |
| 5 | `getvariable-v6` | 90.6% | 58 | 64 | 6 |  |
| 6 | `Object-v7` | 89.8% | 299 | 333 | 34 |  |
| 7 | `Object-v8` | 89.8% | 299 | 333 | 34 |  |
| 8 | `getvariable-v5` | 89.7% | 52 | 58 | 6 |  |
| 9 | `array-v7` | 89.4% | 585 | 654 | 69 |  |
| 10 | `array-v8` | 89.4% | 585 | 654 | 69 |  |
| 11 | `Object-v6` | 85.9% | 286 | 333 | 47 |  |
| 12 | `Function-v5` | 85.4% | 135 | 158 | 23 |  |
| 13 | `Transform-v8` | 85.1% | 86 | 101 | 15 |  |
| 14 | `XMLNode-v5` | 84.1% | 174 | 207 | 33 |  |
| 15 | `XMLNode-v6` | 84.1% | 174 | 207 | 33 |  |
| 16 | `XMLNode-v7` | 84.1% | 174 | 207 | 33 |  |
| 17 | `XMLNode-v8` | 84.1% | 174 | 207 | 33 |  |
| 18 | `MovieClip-v6` | 83.0% | 777 | 936 | 159 |  |
| 19 | `MovieClip-v7` | 82.4% | 798 | 969 | 171 |  |
| 20 | `MovieClip-v8` | 81.3% | 884 | 1087 | 203 |  |
| 21 | `Sound-v7` | 76.9% | 93 | 121 | 28 |  |
| 22 | `Sound-v8` | 76.9% | 93 | 121 | 28 |  |
| 23 | `Function-v7` | 75.4% | 205 | 272 | 67 |  |
| 24 | `Function-v8` | 75.4% | 205 | 272 | 67 |  |
| 25 | `Sound-v6` | 75.2% | 91 | 121 | 30 |  |
| 26 | `TextFormat-v8` | 74.4% | 128 | 172 | 44 |  |
| 27 | `TextField-v6` | 73.9% | 403 | 545 | 142 |  |
| 28 | `Sound-v5` | 73.0% | 73 | 100 | 27 |  |
| 29 | `TextField-v8` | 72.9% | 416 | 571 | 155 |  |
| 30 | `TextField-v7` | 72.5% | 413 | 570 | 157 |  |
| 31 | `Function-v6` | 66.8% | 181 | 271 | 90 |  |
| 32 | `XML-v5` | 62.6% | 281 | 449 | 168 |  |
| 33 | `XML-v6` | 59.3% | 288 | 486 | 198 |  |
| 34 | `XML-v7` | 59.1% | 288 | 487 | 199 |  |
| 35 | `XML-v8` | 59.1% | 288 | 487 | 199 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**38 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
| 2 | `array-v6` | 93.8% | 604/644 | 644 | 644 |  |
| 3 | `getvariable-v7` | 92.2% | 59/64 | 64 | 64 |  |
| 4 | `getvariable-v8` | 92.2% | 59/64 | 64 | 64 |  |
| 5 | `getvariable-v6` | 90.6% | 58/64 | 64 | 64 |  |
| 6 | `Object-v7` | 89.8% | 299/333 | 333 | 333 |  |
| 7 | `Object-v8` | 89.8% | 299/333 | 333 | 333 |  |
| 8 | `getvariable-v5` | 89.7% | 52/58 | 58 | 58 |  |
| 9 | `array-v7` | 89.4% | 585/654 | 654 | 654 |  |
| 10 | `array-v8` | 89.4% | 585/654 | 654 | 654 |  |
| 11 | `Object-v6` | 85.9% | 286/333 | 333 | 333 |  |
| 12 | `Function-v5` | 85.4% | 135/158 | 158 | 158 |  |
| 13 | `Transform-v8` | 85.1% | 86/101 | 101 | 101 |  |
| 14 | `XMLNode-v5` | 84.1% | 174/207 | 207 | 207 |  |
| 15 | `XMLNode-v6` | 84.1% | 174/207 | 207 | 207 |  |
| 16 | `XMLNode-v7` | 84.1% | 174/207 | 207 | 207 |  |
| 17 | `XMLNode-v8` | 84.1% | 174/207 | 207 | 207 |  |
| 18 | `MovieClip-v6` | 83.0% | 777/936 | 921 | 936 |  |
| 19 | `MovieClip-v7` | 82.4% | 798/969 | 956 | 969 |  |
| 20 | `MovieClip-v8` | 81.3% | 884/1087 | 1074 | 1087 |  |
| 21 | `Sound-v7` | 76.9% | 93/121 | 121 | 121 |  |
| 22 | `Sound-v8` | 76.9% | 93/121 | 121 | 121 |  |
| 23 | `Function-v7` | 75.4% | 205/272 | 272 | 272 |  |
| 24 | `Function-v8` | 75.4% | 205/272 | 272 | 272 |  |
| 25 | `Sound-v6` | 75.2% | 91/121 | 121 | 121 |  |
| 26 | `TextFormat-v8` | 74.4% | 128/172 | 172 | 172 |  |
| 27 | `TextField-v6` | 73.9% | 403/545 | 545 | 545 |  |
| 28 | `Sound-v5` | 73.0% | 73/100 | 100 | 100 |  |
| 29 | `TextField-v8` | 72.9% | 416/571 | 571 | 571 |  |
| 30 | `TextField-v7` | 72.5% | 413/570 | 570 | 570 |  |
| 31 | `Function-v6` | 66.8% | 181/271 | 271 | 271 |  |
| 32 | `XML-v5` | 62.6% | 281/449 | 419 | 449 |  |
| 33 | `XML-v6` | 59.3% | 288/486 | 456 | 486 |  |
| 34 | `XML-v7` | 59.1% | 288/487 | 487 | 486 |  |
| 35 | `XML-v8` | 59.1% | 288/487 | 487 | 465 |  |
| 36 | `argstest-v6` | 0.8% | 58/7731 | 7731 | 2192 |  |
| 37 | `argstest-v8` | 0.6% | 51/8093 | 8093 | 2434 |  |
| 38 | `argstest-v7` | 0.6% | 45/7731 | 7731 | 2061 |  |
