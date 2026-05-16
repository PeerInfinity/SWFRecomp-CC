# Ruffle Test Results (Filtered)

**Date**: 2026-05-16 21:06 UTC

**Git SHA**: `be9aafd78e`

**Run Duration**: 4m 11s

**Filtered**: 0 tests ignored out of 243 available

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
| 1 | `Accessibility-v5` | 15 | 0.8s |  |
| 2 | `Accessibility-v6` | 19 | 0.8s |  |
| 3 | `Accessibility-v7` | 19 | 0.8s |  |
| 4 | `Accessibility-v8` | 19 | 0.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.8s |  |
| 6 | `BitmapData-v5` | 7 | 0.9s |  |
| 7 | `BitmapData-v6` | 7 | 0.9s |  |
| 8 | `BitmapData-v7` | 7 | 0.9s |  |
| 9 | `Boolean-v5` | 38 | 0.9s |  |
| 10 | `Boolean-v6` | 38 | 0.9s |  |
| 11 | `Boolean-v7` | 38 | 0.9s |  |
| 12 | `Boolean-v8` | 38 | 0.9s |  |
| 13 | `Camera-v5` | 7 | 0.9s |  |
| 14 | `Color-v5` | 140 | 1.0s |  |
| 15 | `Color-v6` | 171 | 1.0s |  |
| 16 | `Color-v7` | 161 | 1.0s |  |
| 17 | `Color-v8` | 161 | 0.9s |  |
| 18 | `ColorTransform-v5` | 7 | 1.1s |  |
| 19 | `ColorTransform-v6` | 7 | 0.8s |  |
| 20 | `ColorTransform-v7` | 7 | 0.8s |  |
| 21 | `ColorTransform-v8` | 55 | 0.8s |  |
| 22 | `ContextMenu-v5` | 7 | 0.8s |  |
| 23 | `ContextMenu-v6` | 7 | 0.8s |  |
| 24 | `ContextMenu-v7` | 131 | 0.8s |  |
| 25 | `ContextMenu-v8` | 131 | 1.8s |  |
| 26 | `Error-v5` | 28 | 0.7s |  |
| 27 | `Error-v6` | 31 | 0.8s |  |
| 28 | `Error-v7` | 31 | 0.8s |  |
| 29 | `Error-v8` | 31 | 0.7s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.7s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.7s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.7s |  |
| 33 | `Global-v5` | 172 | 0.9s |  |
| 34 | `Global-v7` | 182 | 0.9s |  |
| 35 | `Global-v8` | 169 | 0.9s |  |
| 36 | `Instance-v5` | 52 | 1.0s |  |
| 37 | `Instance-v6` | 52 | 1.1s |  |
| 38 | `Instance-v7` | 52 | 1.0s |  |
| 39 | `Instance-v8` | 52 | 0.9s |  |
| 40 | `Key-v5` | 51 | 0.7s |  |
| 41 | `Key-v6` | 55 | 0.7s |  |
| 42 | `Key-v7` | 55 | 0.7s |  |
| 43 | `Key-v8` | 55 | 0.7s |  |
| 44 | `LoadVars-v5` | 8 | 0.7s |  |
| 45 | `LocalConnection-v5` | 7 | 0.9s |  |
| 46 | `LocalConnection-v6` | 58 | 0.9s |  |
| 47 | `LocalConnection-v7` | 58 | 0.9s |  |
| 48 | `LocalConnection-v8` | 58 | 0.9s |  |
| 49 | `Matrix-v5` | 7 | 0.9s |  |
| 50 | `Microphone-v5` | 6 | 0.9s |  |
| 51 | `Mouse-v5` | 13 | 0.8s |  |
| 52 | `Mouse-v6` | 21 | 0.8s |  |
| 53 | `Mouse-v7` | 21 | 0.8s |  |
| 54 | `Mouse-v8` | 21 | 0.8s |  |
| 55 | `MovieClipLoader-v5` | 6 | 0.8s |  |
| 56 | `MovieClipLoader-v6` | 6 | 0.8s |  |
| 57 | `NetConnection-v5` | 7 | 0.8s |  |
| 58 | `NetStream-v5` | 6 | 1.0s |  |
| 59 | `NetStream-v6` | 80 | 0.9s |  |
| 60 | `NetStream-v7` | 80 | 0.9s |  |
| 61 | `NetStream-v8` | 80 | 0.9s |  |
| 62 | `Number-v6` | 239 | 1.0s |  |
| 63 | `Number-v7` | 237 | 1.0s |  |
| 64 | `Number-v8` | 237 | 1.0s |  |
| 65 | `Point-v5` | 7 | 0.9s |  |
| 66 | `Point-v6` | 7 | 0.9s |  |
| 67 | `Point-v7` | 7 | 0.9s |  |
| 68 | `Point-v8` | 193 | 1.0s |  |
| 69 | `Random-v5` | 30 | 0.8s |  |
| 70 | `Random-v6` | 30 | 0.8s |  |
| 71 | `Random-v7` | 30 | 0.8s |  |
| 72 | `Random-v8` | 30 | 0.8s |  |
| 73 | `Rectangle-v5` | 7 | 0.8s |  |
| 74 | `Rectangle-v6` | 7 | 0.8s |  |
| 75 | `Rectangle-v7` | 7 | 0.8s |  |
| 76 | `Selection-v5` | 21 | 1.1s |  |
| 77 | `Stage-v5` | 38 | 0.9s |  |
| 78 | `System-v5` | 67 | 0.7s |  |
| 79 | `System-v6` | 100 | 0.7s |  |
| 80 | `System-v7` | 101 | 0.7s |  |
| 81 | `System-v8` | 101 | 1.2s |  |
| 82 | `TextFieldHTML-v5` | 6 | 0.8s |  |
| 83 | `TextFieldHTML-v6` | 37 | 0.8s |  |
| 84 | `TextFieldHTML-v7` | 37 | 0.8s |  |
| 85 | `TextFieldHTML-v8` | 37 | 0.8s |  |
| 86 | `TextFormat-v5` | 128 | 0.8s |  |
| 87 | `TextFormat-v6` | 128 | 0.8s |  |
| 88 | `TextSnapshot-v5` | 7 | 0.9s |  |
| 89 | `TextSnapshot-v6` | 173 | 1.0s |  |
| 90 | `TextSnapshot-v7` | 173 | 1.1s |  |
| 91 | `TextSnapshot-v8` | 173 | 0.9s |  |
| 92 | `Transform-v5` | 7 | 0.9s |  |
| 93 | `Transform-v6` | 7 | 0.8s |  |
| 94 | `Transform-v7` | 7 | 0.9s |  |
| 95 | `Try-v5` | 20 | 0.7s |  |
| 96 | `Try-v6` | 20 | 0.7s |  |
| 97 | `Try-v7` | 20 | 0.7s |  |
| 98 | `Try-v8` | 20 | 0.7s |  |
| 99 | `Video-v5` | 7 | 0.7s |  |
| 100 | `Video-v6` | 85 | 0.7s |  |
| 101 | `Video-v7` | 85 | 0.7s |  |
| 102 | `Video-v8` | 85 | 0.7s |  |
| 103 | `XMLSocket-v5` | 35 | 0.7s |  |
| 104 | `XMLSocket-v6` | 35 | 0.7s |  |
| 105 | `XMLSocket-v7` | 35 | 0.7s |  |
| 106 | `XMLSocket-v8` | 35 | 0.7s |  |
| 107 | `argstest-v5` | 4 | 0.7s |  |
| 108 | `case-v5` | 39 | 0.9s |  |
| 109 | `case-v7` | 67 | 0.9s |  |
| 110 | `case-v8` | 67 | 1.0s |  |
| 111 | `delete-v5` | 60 | 0.8s |  |
| 112 | `delete-v6` | 60 | 0.8s |  |
| 113 | `delete-v7` | 60 | 0.8s |  |
| 114 | `delete-v8` | 60 | 0.8s |  |
| 115 | `enumerate-v5` | 6 | 0.8s |  |
| 116 | `enumerate-v6` | 49 | 0.8s |  |
| 117 | `enumerate-v7` | 49 | 0.8s |  |
| 118 | `enumerate-v8` | 49 | 0.8s |  |
| 119 | `flash-v5` | 10 | 0.9s |  |
| 120 | `flash-v6` | 10 | 0.9s |  |
| 121 | `flash-v7` | 10 | 0.9s |  |
| 122 | `flash-v8` | 41 | 0.9s |  |
| 123 | `swap-v5` | 7 | 0.7s |  |
| 124 | `swap-v6` | 7 | 0.7s |  |
| 125 | `swap-v7` | 7 | 0.7s |  |
| 126 | `swap-v8` | 7 | 0.7s |  |
| 127 | `targetPath-v5` | 12 | 0.7s |  |

## Ruffle-Matched Tests

**73 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 1.0s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.8s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.8s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 0.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.9s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.5s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.9s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.9s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.9s |  |
| 12 | `Date-v5` | 7 | 7 | 2.4s |  |
| 13 | `Date-v6` | 6 | 6 | 1.7s |  |
| 14 | `Date-v7` | 6 | 6 | 2.0s |  |
| 15 | `Date-v8` | 6 | 6 | 1.0s |  |
| 16 | `ExternalInterface-v8` | 4 | 4 | 1.4s |  |
| 17 | `Global-v6` | 9 | 10 | 0.9s |  |
| 18 | `HitTest-v6` | 8 | 8 | 0.8s |  |
| 19 | `HitTest-v7` | 8 | 8 | 0.8s |  |
| 20 | `HitTest-v8` | 9 | 9 | 0.8s |  |
| 21 | `Inheritance-v7` | 5 | 10 | 1.0s |  |
| 22 | `Inheritance-v8` | 5 | 10 | 1.0s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 0.7s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 0.7s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 0.7s |  |
| 26 | `Math-v5` | 5 | 5 | 1.1s |  |
| 27 | `Math-v6` | 5 | 5 | 1.1s |  |
| 28 | `Math-v7` | 5 | 5 | 1.1s |  |
| 29 | `Math-v8` | 5 | 5 | 1.1s |  |
| 30 | `Matrix-v6` | 29 | 71 | 1.0s |  |
| 31 | `Matrix-v7` | 28 | 70 | 0.9s |  |
| 32 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 33 | `Microphone-v6` | 31 | 31 | 0.9s |  |
| 34 | `Microphone-v7` | 31 | 31 | 0.9s |  |
| 35 | `Microphone-v8` | 31 | 31 | 0.9s |  |
| 36 | `MovieClip-v5` | 48 | 226 | 1.0s |  |
| 37 | `MovieClipLoader-v7` | 118 | 118 | 0.8s |  |
| 38 | `MovieClipLoader-v8` | 118 | 118 | 0.8s |  |
| 39 | `Number-v5` | 8 | 13 | 0.9s |  |
| 40 | `Object-v5` | 3 | 7 | 1.0s |  |
| 41 | `Rectangle-v8` | 21 | 21 | 0.8s |  |
| 42 | `Selection-v6` | 7 | 13 | 0.9s |  |
| 43 | `Selection-v7` | 7 | 13 | 0.9s |  |
| 44 | `Selection-v8` | 7 | 13 | 0.9s |  |
| 45 | `Sound-v5` | 27 | 27 | 1.0s |  |
| 46 | `Stage-v6` | 14 | 14 | 0.9s |  |
| 47 | `Stage-v7` | 14 | 14 | 0.9s |  |
| 48 | `Stage-v8` | 14 | 14 | 0.9s |  |
| 49 | `String-v5` | 19 | 21 | 1.2s |  |
| 50 | `String-v6` | 10 | 10 | 1.2s |  |
| 51 | `String-v7` | 10 | 10 | 1.2s |  |
| 52 | `String-v8` | 10 | 10 | 1.2s |  |
| 53 | `TextField-v5` | 3 | 3 | 1.7s |  |
| 54 | `TextFormat-v7` | 38 | 40 | 0.8s |  |
| 55 | `ops-v5` | 7 | 9 | 1.0s |  |
| 56 | `ops-v6` | 7 | 11 | 1.0s |  |
| 57 | `ops-v7` | 7 | 11 | 0.8s |  |
| 58 | `ops-v8` | 7 | 11 | 0.9s |  |
| 59 | `setProperty-v5` | 49 | 49 | 0.8s |  |
| 60 | `setProperty-v6` | 49 | 49 | 0.8s |  |
| 61 | `setProperty-v7` | 49 | 49 | 0.8s |  |
| 62 | `setProperty-v8` | 49 | 49 | 0.8s |  |
| 63 | `targetPath-v6` | 17 | 17 | 0.7s |  |
| 64 | `targetPath-v7` | 17 | 17 | 0.7s |  |
| 65 | `targetPath-v8` | 17 | 17 | 0.7s |  |
| 66 | `toString_valueOf-v5` | 34 | 34 | 1.0s |  |
| 67 | `toString_valueOf-v6` | 5 | 5 | 1.0s |  |
| 68 | `toString_valueOf-v7` | 5 | 5 | 0.9s |  |
| 69 | `toString_valueOf-v8` | 5 | 5 | 1.0s |  |
| 70 | `with-v5` | 42 | 42 | 0.9s |  |
| 71 | `with-v6` | 91 | 91 | 0.9s |  |
| 72 | `with-v7` | 91 | 91 | 0.9s |  |
| 73 | `with-v8` | 91 | 91 | 0.9s |  |

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
| 14 | `MovieClip-v7` | 82.4% | 798 | 969 | 171 |  |
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
| 27 | `TextField-v8` | 72.7% | 415 | 571 | 156 |  |
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
| 1 | `Inheritance-v5` | exit code -6 | 1.6s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.6s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 1.6s |  |

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
| 14 | `MovieClip-v7` | 82.4% | 798/969 | 956 | 969 |  |
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
| 27 | `TextField-v8` | 72.7% | 415/571 | 571 | 571 |  |
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
