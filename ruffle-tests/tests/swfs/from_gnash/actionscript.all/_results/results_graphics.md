# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-16 20:55 UTC

**Git SHA**: `ef6584787e`

**Run Duration**: 24m 26s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **127** (52.3%) |
| Ruffle-matched | 73 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **200** (82.3%) |
| Failing | 43 |
| Total expected lines | 38787 |
| Matching lines | 27714 (71.5%) |
| Mismatched lines | 11073 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 40 | 93.0% |
| Runtime Error | 3 | 7.0% |

## Passing Tests

**127 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.2s |  |
| 2 | `Accessibility-v6` | 19 | 1.2s |  |
| 3 | `Accessibility-v7` | 19 | 1.2s |  |
| 4 | `Accessibility-v8` | 19 | 1.2s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.2s |  |
| 6 | `BitmapData-v5` | 7 | 1.0s |  |
| 7 | `BitmapData-v6` | 7 | 0.8s |  |
| 8 | `BitmapData-v7` | 7 | 1.0s |  |
| 9 | `Boolean-v5` | 38 | 1.0s |  |
| 10 | `Boolean-v6` | 38 | 1.0s |  |
| 11 | `Boolean-v7` | 38 | 19.0s |  |
| 12 | `Boolean-v8` | 38 | 1.1s |  |
| 13 | `Camera-v5` | 7 | 1.1s |  |
| 14 | `Color-v5` | 140 | 1.2s |  |
| 15 | `Color-v6` | 171 | 1.2s |  |
| 16 | `Color-v7` | 161 | 1.1s |  |
| 17 | `Color-v8` | 161 | 16.0s |  |
| 18 | `ColorTransform-v5` | 7 | 1.0s |  |
| 19 | `ColorTransform-v6` | 7 | 0.8s |  |
| 20 | `ColorTransform-v7` | 7 | 1.0s |  |
| 21 | `ColorTransform-v8` | 55 | 1.0s |  |
| 22 | `ContextMenu-v5` | 7 | 1.0s |  |
| 23 | `ContextMenu-v6` | 7 | 0.8s |  |
| 24 | `ContextMenu-v7` | 131 | 1.0s |  |
| 25 | `ContextMenu-v8` | 131 | 18.2s |  |
| 26 | `Error-v5` | 28 | 0.9s |  |
| 27 | `Error-v6` | 31 | 0.9s |  |
| 28 | `Error-v7` | 31 | 1.0s |  |
| 29 | `Error-v8` | 31 | 19.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.2s |  |
| 31 | `ExternalInterface-v6` | 55 | 1.2s |  |
| 32 | `ExternalInterface-v7` | 55 | 1.2s |  |
| 33 | `Global-v5` | 172 | 1.2s |  |
| 34 | `Global-v7` | 182 | 1.2s |  |
| 35 | `Global-v8` | 169 | 1.2s |  |
| 36 | `Instance-v5` | 52 | 1.2s |  |
| 37 | `Instance-v6` | 52 | 1.1s |  |
| 38 | `Instance-v7` | 52 | 1.2s |  |
| 39 | `Instance-v8` | 52 | 1.2s |  |
| 40 | `Key-v5` | 51 | 19.6s |  |
| 41 | `Key-v6` | 55 | 1.3s |  |
| 42 | `Key-v7` | 55 | 1.2s |  |
| 43 | `Key-v8` | 55 | 1.2s |  |
| 44 | `LoadVars-v5` | 8 | 19.7s |  |
| 45 | `LocalConnection-v5` | 7 | 15.7s |  |
| 46 | `LocalConnection-v6` | 58 | 1.0s |  |
| 47 | `LocalConnection-v7` | 58 | 1.0s |  |
| 48 | `LocalConnection-v8` | 58 | 1.0s |  |
| 49 | `Matrix-v5` | 7 | 19.1s |  |
| 50 | `Microphone-v5` | 6 | 1.2s |  |
| 51 | `Mouse-v5` | 13 | 19.7s |  |
| 52 | `Mouse-v6` | 21 | 2.4s |  |
| 53 | `Mouse-v7` | 21 | 2.1s |  |
| 54 | `Mouse-v8` | 21 | 1.7s |  |
| 55 | `MovieClipLoader-v5` | 6 | 20.1s |  |
| 56 | `MovieClipLoader-v6` | 6 | 1.0s |  |
| 57 | `NetConnection-v5` | 7 | 19.7s |  |
| 58 | `NetStream-v5` | 6 | 19.0s |  |
| 59 | `NetStream-v6` | 80 | 1.2s |  |
| 60 | `NetStream-v7` | 80 | 1.2s |  |
| 61 | `NetStream-v8` | 80 | 1.2s |  |
| 62 | `Number-v6` | 239 | 1.3s |  |
| 63 | `Number-v7` | 237 | 1.2s |  |
| 64 | `Number-v8` | 237 | 1.3s |  |
| 65 | `Point-v5` | 7 | 19.1s |  |
| 66 | `Point-v6` | 7 | 0.8s |  |
| 67 | `Point-v7` | 7 | 1.0s |  |
| 68 | `Point-v8` | 193 | 1.1s |  |
| 69 | `Random-v5` | 30 | 18.3s |  |
| 70 | `Random-v6` | 30 | 0.9s |  |
| 71 | `Random-v7` | 30 | 1.1s |  |
| 72 | `Random-v8` | 30 | 1.1s |  |
| 73 | `Rectangle-v5` | 7 | 1.1s |  |
| 74 | `Rectangle-v6` | 7 | 0.9s |  |
| 75 | `Rectangle-v7` | 7 | 1.1s |  |
| 76 | `Selection-v5` | 21 | 18.6s |  |
| 77 | `Stage-v5` | 38 | 21.9s |  |
| 78 | `System-v5` | 67 | 20.8s |  |
| 79 | `System-v6` | 100 | 4.2s |  |
| 80 | `System-v7` | 101 | 4.2s |  |
| 81 | `System-v8` | 101 | 1.7s |  |
| 82 | `TextFieldHTML-v5` | 6 | 18.9s |  |
| 83 | `TextFieldHTML-v6` | 37 | 1.2s |  |
| 84 | `TextFieldHTML-v7` | 37 | 1.2s |  |
| 85 | `TextFieldHTML-v8` | 37 | 1.2s |  |
| 86 | `TextFormat-v5` | 128 | 1.2s |  |
| 87 | `TextFormat-v6` | 128 | 1.1s |  |
| 88 | `TextSnapshot-v5` | 7 | 19.6s |  |
| 89 | `TextSnapshot-v6` | 173 | 1.2s |  |
| 90 | `TextSnapshot-v7` | 173 | 1.3s |  |
| 91 | `TextSnapshot-v8` | 173 | 1.3s |  |
| 92 | `Transform-v5` | 7 | 1.2s |  |
| 93 | `Transform-v6` | 7 | 1.2s |  |
| 94 | `Transform-v7` | 7 | 1.2s |  |
| 95 | `Try-v5` | 20 | 21.4s |  |
| 96 | `Try-v6` | 20 | 1.3s |  |
| 97 | `Try-v7` | 20 | 2.9s |  |
| 98 | `Try-v8` | 20 | 1.8s |  |
| 99 | `Video-v5` | 7 | 20.5s |  |
| 100 | `Video-v6` | 85 | 3.9s |  |
| 101 | `Video-v7` | 85 | 3.7s |  |
| 102 | `Video-v8` | 85 | 1.9s |  |
| 103 | `XMLSocket-v5` | 35 | 19.2s |  |
| 104 | `XMLSocket-v6` | 35 | 1.2s |  |
| 105 | `XMLSocket-v7` | 35 | 1.2s |  |
| 106 | `XMLSocket-v8` | 35 | 1.2s |  |
| 107 | `argstest-v5` | 4 | 1.2s |  |
| 108 | `case-v5` | 39 | 1.2s |  |
| 109 | `case-v7` | 67 | 1.2s |  |
| 110 | `case-v8` | 67 | 1.2s |  |
| 111 | `delete-v5` | 60 | 20.6s |  |
| 112 | `delete-v6` | 60 | 1.3s |  |
| 113 | `delete-v7` | 60 | 1.3s |  |
| 114 | `delete-v8` | 60 | 1.2s |  |
| 115 | `enumerate-v5` | 6 | 1.2s |  |
| 116 | `enumerate-v6` | 49 | 1.3s |  |
| 117 | `enumerate-v7` | 49 | 1.2s |  |
| 118 | `enumerate-v8` | 49 | 1.2s |  |
| 119 | `flash-v5` | 10 | 19.0s |  |
| 120 | `flash-v6` | 10 | 1.1s |  |
| 121 | `flash-v7` | 10 | 1.1s |  |
| 122 | `flash-v8` | 41 | 19.2s |  |
| 123 | `swap-v5` | 7 | 19.8s |  |
| 124 | `swap-v6` | 7 | 0.8s |  |
| 125 | `swap-v7` | 7 | 1.0s |  |
| 126 | `swap-v8` | 7 | 1.0s |  |
| 127 | `targetPath-v5` | 12 | 1.0s |  |

## Ruffle-Matched Tests

**73 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 19.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 1.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 1.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.2s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 18.7s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 1.0s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.0s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.4s |  |
| 9 | `Camera-v6` | 57 | 57 | 1.1s |  |
| 10 | `Camera-v7` | 57 | 57 | 1.1s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 12 | `Date-v5` | 7 | 7 | 18.5s |  |
| 13 | `Date-v6` | 6 | 6 | 1.2s |  |
| 14 | `Date-v7` | 6 | 6 | 1.2s |  |
| 15 | `Date-v8` | 6 | 6 | 1.2s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 1.2s |  |
| 17 | `Global-v6` | 9 | 10 | 18.5s |  |
| 18 | `HitTest-v6` | 8 | 8 | 1.1s |  |
| 19 | `HitTest-v7` | 8 | 8 | 1.1s |  |
| 20 | `HitTest-v8` | 9 | 9 | 1.1s |  |
| 21 | `Inheritance-v7` | 5 | 10 | 1.3s |  |
| 22 | `Inheritance-v8` | 5 | 10 | 1.3s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 1.2s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 1.2s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 1.2s |  |
| 26 | `Math-v5` | 5 | 5 | 1.1s |  |
| 27 | `Math-v6` | 5 | 5 | 1.0s |  |
| 28 | `Math-v7` | 5 | 5 | 1.1s |  |
| 29 | `Math-v8` | 5 | 5 | 1.1s |  |
| 30 | `Matrix-v6` | 29 | 71 | 1.2s |  |
| 31 | `Matrix-v7` | 28 | 70 | 1.3s |  |
| 32 | `Matrix-v8` | 28 | 70 | 1.3s |  |
| 33 | `Microphone-v6` | 31 | 31 | 1.2s |  |
| 34 | `Microphone-v7` | 31 | 31 | 1.2s |  |
| 35 | `Microphone-v8` | 31 | 31 | 1.2s |  |
| 36 | `MovieClip-v5` | 48 | 226 | 30.8s |  |
| 37 | `MovieClipLoader-v7` | 118 | 118 | 1.2s |  |
| 38 | `MovieClipLoader-v8` | 118 | 118 | 1.2s |  |
| 39 | `Number-v5` | 8 | 13 | 1.3s |  |
| 40 | `Object-v5` | 3 | 7 | 19.3s |  |
| 41 | `Rectangle-v8` | 21 | 21 | 1.1s |  |
| 42 | `Selection-v6` | 7 | 13 | 1.0s |  |
| 43 | `Selection-v7` | 7 | 13 | 1.1s |  |
| 44 | `Selection-v8` | 7 | 13 | 1.0s |  |
| 45 | `Sound-v5` | 27 | 27 | 19.2s |  |
| 46 | `Stage-v6` | 14 | 14 | 22.4s |  |
| 47 | `Stage-v7` | 14 | 14 | 3.4s |  |
| 48 | `Stage-v8` | 14 | 14 | 1.9s |  |
| 49 | `String-v5` | 19 | 21 | 16.6s |  |
| 50 | `String-v6` | 10 | 10 | 17.6s |  |
| 51 | `String-v7` | 10 | 10 | 17.4s |  |
| 52 | `String-v8` | 10 | 10 | 2.3s |  |
| 53 | `TextField-v5` | 3 | 3 | 2.3s |  |
| 54 | `TextFormat-v7` | 38 | 40 | 1.3s |  |
| 55 | `ops-v5` | 7 | 9 | 19.4s |  |
| 56 | `ops-v6` | 7 | 11 | 1.4s |  |
| 57 | `ops-v7` | 7 | 11 | 1.4s |  |
| 58 | `ops-v8` | 7 | 11 | 18.9s |  |
| 59 | `setProperty-v5` | 49 | 49 | 1.2s |  |
| 60 | `setProperty-v6` | 49 | 49 | 1.2s |  |
| 61 | `setProperty-v7` | 49 | 49 | 1.2s |  |
| 62 | `setProperty-v8` | 49 | 49 | 1.2s |  |
| 63 | `targetPath-v6` | 17 | 17 | 1.0s |  |
| 64 | `targetPath-v7` | 17 | 17 | 1.0s |  |
| 65 | `targetPath-v8` | 17 | 17 | 1.0s |  |
| 66 | `toString_valueOf-v5` | 34 | 34 | 19.3s |  |
| 67 | `toString_valueOf-v6` | 5 | 5 | 1.0s |  |
| 68 | `toString_valueOf-v7` | 5 | 5 | 1.1s |  |
| 69 | `toString_valueOf-v8` | 5 | 5 | 1.0s |  |
| 70 | `with-v5` | 42 | 42 | 1.0s |  |
| 71 | `with-v6` | 91 | 91 | 1.0s |  |
| 72 | `with-v7` | 91 | 91 | 1.0s |  |
| 73 | `with-v8` | 91 | 91 | 1.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**37 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |
| 2 | `array-v6` | 93.8% | 604 | 644 | 40 |  |
| 3 | `Object-v7` | 89.8% | 299 | 333 | 34 |  |
| 4 | `Object-v8` | 89.8% | 299 | 333 | 34 |  |
| 5 | `array-v7` | 89.4% | 585 | 654 | 69 |  |
| 6 | `array-v8` | 89.4% | 585 | 654 | 69 |  |
| 7 | `Object-v6` | 85.9% | 286 | 333 | 47 |  |
| 8 | `Function-v5` | 85.4% | 135 | 158 | 23 |  |
| 9 | `XMLNode-v5` | 84.1% | 174 | 207 | 33 |  |
| 10 | `XMLNode-v6` | 84.1% | 174 | 207 | 33 |  |
| 11 | `XMLNode-v7` | 84.1% | 174 | 207 | 33 |  |
| 12 | `XMLNode-v8` | 84.1% | 174 | 207 | 33 |  |
| 13 | `MovieClip-v6` | 83.0% | 777 | 936 | 159 |  |
| 14 | `MovieClip-v7` | 82.2% | 797 | 969 | 172 |  |
| 15 | `MovieClip-v8` | 81.4% | 885 | 1087 | 202 |  |
| 16 | `Sound-v7` | 76.9% | 93 | 121 | 28 |  |
| 17 | `Sound-v8` | 76.9% | 93 | 121 | 28 |  |
| 18 | `getvariable-v7` | 76.6% | 49 | 64 | 15 |  |
| 19 | `getvariable-v8` | 76.6% | 49 | 64 | 15 |  |
| 20 | `getvariable-v5` | 75.9% | 44 | 58 | 14 |  |
| 21 | `Function-v7` | 75.4% | 205 | 272 | 67 |  |
| 22 | `Function-v8` | 75.4% | 205 | 272 | 67 |  |
| 23 | `Sound-v6` | 75.2% | 91 | 121 | 30 |  |
| 24 | `getvariable-v6` | 75.0% | 48 | 64 | 16 |  |
| 25 | `TextFormat-v8` | 74.4% | 128 | 172 | 44 |  |
| 26 | `TextField-v6` | 74.1% | 404 | 545 | 141 |  |
| 27 | `TextField-v8` | 72.9% | 416 | 571 | 155 |  |
| 28 | `TextField-v7` | 72.6% | 414 | 570 | 156 |  |
| 29 | `Transform-v8` | 70.3% | 71 | 101 | 30 |  |
| 30 | `Function-v6` | 66.8% | 181 | 271 | 90 |  |
| 31 | `XML-v5` | 62.6% | 281 | 449 | 168 |  |
| 32 | `NetConnection-v7` | 59.5% | 75 | 126 | 51 |  |
| 33 | `NetConnection-v8` | 59.5% | 75 | 126 | 51 |  |
| 34 | `XML-v6` | 59.3% | 288 | 486 | 198 |  |
| 35 | `XML-v7` | 59.1% | 288 | 487 | 199 |  |
| 36 | `XML-v8` | 59.1% | 288 | 487 | 199 |  |
| 37 | `NetConnection-v6` | 56.3% | 71 | 126 | 55 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `Inheritance-v5` | exit code -6 | 20.2s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.9s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 1.9s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**40 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
| 2 | `array-v6` | 93.8% | 604/644 | 644 | 644 |  |
| 3 | `Object-v7` | 89.8% | 299/333 | 333 | 333 |  |
| 4 | `Object-v8` | 89.8% | 299/333 | 333 | 333 |  |
| 5 | `array-v7` | 89.4% | 585/654 | 654 | 654 |  |
| 6 | `array-v8` | 89.4% | 585/654 | 654 | 654 |  |
| 7 | `Object-v6` | 85.9% | 286/333 | 333 | 333 |  |
| 8 | `Function-v5` | 85.4% | 135/158 | 158 | 158 |  |
| 9 | `XMLNode-v5` | 84.1% | 174/207 | 207 | 207 |  |
| 10 | `XMLNode-v6` | 84.1% | 174/207 | 207 | 207 |  |
| 11 | `XMLNode-v7` | 84.1% | 174/207 | 207 | 207 |  |
| 12 | `XMLNode-v8` | 84.1% | 174/207 | 207 | 207 |  |
| 13 | `MovieClip-v6` | 83.0% | 777/936 | 921 | 936 |  |
| 14 | `MovieClip-v7` | 82.2% | 797/969 | 956 | 969 |  |
| 15 | `MovieClip-v8` | 81.4% | 885/1087 | 1074 | 1087 |  |
| 16 | `Sound-v7` | 76.9% | 93/121 | 121 | 121 |  |
| 17 | `Sound-v8` | 76.9% | 93/121 | 121 | 121 |  |
| 18 | `getvariable-v7` | 76.6% | 49/64 | 64 | 64 |  |
| 19 | `getvariable-v8` | 76.6% | 49/64 | 64 | 64 |  |
| 20 | `getvariable-v5` | 75.9% | 44/58 | 58 | 58 |  |
| 21 | `Function-v7` | 75.4% | 205/272 | 272 | 272 |  |
| 22 | `Function-v8` | 75.4% | 205/272 | 272 | 272 |  |
| 23 | `Sound-v6` | 75.2% | 91/121 | 121 | 121 |  |
| 24 | `getvariable-v6` | 75.0% | 48/64 | 64 | 64 |  |
| 25 | `TextFormat-v8` | 74.4% | 128/172 | 172 | 172 |  |
| 26 | `TextField-v6` | 74.1% | 404/545 | 545 | 545 |  |
| 27 | `TextField-v8` | 72.9% | 416/571 | 571 | 571 |  |
| 28 | `TextField-v7` | 72.6% | 414/570 | 570 | 570 |  |
| 29 | `Transform-v8` | 70.3% | 71/101 | 101 | 101 |  |
| 30 | `Function-v6` | 66.8% | 181/271 | 271 | 271 |  |
| 31 | `XML-v5` | 62.6% | 281/449 | 419 | 449 |  |
| 32 | `NetConnection-v7` | 59.5% | 75/126 | 126 | 126 |  |
| 33 | `NetConnection-v8` | 59.5% | 75/126 | 126 | 126 |  |
| 34 | `XML-v6` | 59.3% | 288/486 | 456 | 486 |  |
| 35 | `XML-v7` | 59.1% | 288/487 | 487 | 486 |  |
| 36 | `XML-v8` | 59.1% | 288/487 | 487 | 465 |  |
| 37 | `NetConnection-v6` | 56.3% | 71/126 | 126 | 126 |  |
| 38 | `argstest-v6` | 0.8% | 58/7731 | 7731 | 2192 |  |
| 39 | `argstest-v8` | 0.6% | 51/8093 | 8093 | 2434 |  |
| 40 | `argstest-v7` | 0.6% | 45/7731 | 7731 | 2061 |  |
