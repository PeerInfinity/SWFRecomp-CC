# Ruffle Test Results (Filtered)

**Date**: 2026-11-24 17:26 UTC

**Git SHA**: `78fee9e13f`

**Run Duration**: 31m 27s

**Filtered**: 3 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 240 |
| Passing | **148** (61.7%) |
| Ruffle-matched | 92 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (100.0%) |
| Failing | 0 |
| Total expected lines | 32104 |
| Matching lines | 30595 (95.3%) |
| Mismatched lines | 1509 |

## Passing Tests

**148 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.2s |  |
| 2 | `Accessibility-v6` | 19 | 2.3s |  |
| 3 | `Accessibility-v7` | 19 | 2.1s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.2s |  |
| 6 | `AsBroadcaster-v6` | 121 | 21.9s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.5s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.0s |  |
| 9 | `BitmapData-v5` | 7 | 2.3s |  |
| 10 | `BitmapData-v6` | 7 | 1.1s |  |
| 11 | `BitmapData-v7` | 7 | 1.9s |  |
| 12 | `Boolean-v5` | 38 | 2.7s |  |
| 13 | `Boolean-v6` | 38 | 2.3s |  |
| 14 | `Boolean-v7` | 38 | 19.8s |  |
| 15 | `Boolean-v8` | 38 | 1.8s |  |
| 16 | `Camera-v5` | 7 | 2.1s |  |
| 17 | `Color-v5` | 140 | 4.5s |  |
| 18 | `Color-v6` | 171 | 5.5s |  |
| 19 | `Color-v7` | 161 | 5.2s |  |
| 20 | `Color-v8` | 161 | 30.7s |  |
| 21 | `ColorTransform-v5` | 7 | 3.3s |  |
| 22 | `ColorTransform-v6` | 7 | 1.6s |  |
| 23 | `ColorTransform-v7` | 7 | 3.0s |  |
| 24 | `ColorTransform-v8` | 55 | 4.8s |  |
| 25 | `ContextMenu-v5` | 7 | 3.3s |  |
| 26 | `ContextMenu-v6` | 7 | 1.6s |  |
| 27 | `ContextMenu-v7` | 131 | 6.4s |  |
| 28 | `ContextMenu-v8` | 131 | 27.7s |  |
| 29 | `Error-v5` | 28 | 3.4s |  |
| 30 | `Error-v6` | 31 | 3.4s |  |
| 31 | `Error-v7` | 31 | 3.0s |  |
| 32 | `Error-v8` | 31 | 19.7s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.2s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.9s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `Function-v6` | 271 | 7.9s |  |
| 37 | `Function-v7` | 272 | 8.0s |  |
| 38 | `Function-v8` | 272 | 26.0s |  |
| 39 | `Global-v5` | 172 | 6.4s |  |
| 40 | `Global-v7` | 182 | 6.5s |  |
| 41 | `Global-v8` | 169 | 6.0s |  |
| 42 | `Instance-v5` | 52 | 3.1s |  |
| 43 | `Instance-v6` | 52 | 1.9s |  |
| 44 | `Instance-v7` | 52 | 2.8s |  |
| 45 | `Instance-v8` | 52 | 1.9s |  |
| 46 | `Key-v5` | 51 | 20.3s |  |
| 47 | `Key-v6` | 55 | 3.0s |  |
| 48 | `Key-v7` | 55 | 2.7s |  |
| 49 | `Key-v8` | 55 | 1.8s |  |
| 50 | `LoadVars-v5` | 8 | 2.2s |  |
| 51 | `LocalConnection-v5` | 7 | 21.7s |  |
| 52 | `LocalConnection-v6` | 58 | 3.9s |  |
| 53 | `LocalConnection-v7` | 58 | 3.8s |  |
| 54 | `LocalConnection-v8` | 58 | 2.4s |  |
| 55 | `Matrix-v5` | 7 | 25.5s |  |
| 56 | `Matrix-v6` | 168 | 8.9s |  |
| 57 | `Matrix-v7` | 168 | 9.0s |  |
| 58 | `Matrix-v8` | 168 | 2.9s |  |
| 59 | `Microphone-v5` | 6 | 3.2s |  |
| 60 | `Mouse-v5` | 13 | 15.8s |  |
| 61 | `Mouse-v6` | 21 | 2.3s |  |
| 62 | `Mouse-v7` | 21 | 2.1s |  |
| 63 | `Mouse-v8` | 21 | 1.8s |  |
| 64 | `MovieClipLoader-v5` | 6 | 26.4s |  |
| 65 | `MovieClipLoader-v6` | 6 | 1.7s |  |
| 66 | `NetConnection-v5` | 7 | 3.5s |  |
| 67 | `NetStream-v5` | 6 | 17.9s |  |
| 68 | `NetStream-v6` | 80 | 3.8s |  |
| 69 | `NetStream-v7` | 80 | 3.7s |  |
| 70 | `NetStream-v8` | 80 | 2.2s |  |
| 71 | `Number-v6` | 239 | 8.7s |  |
| 72 | `Number-v7` | 237 | 9.0s |  |
| 73 | `Number-v8` | 237 | 2.3s |  |
| 74 | `Point-v5` | 7 | 2.2s |  |
| 75 | `Point-v6` | 7 | 1.1s |  |
| 76 | `Point-v7` | 7 | 1.9s |  |
| 77 | `Point-v8` | 193 | 6.9s |  |
| 78 | `Random-v5` | 30 | 22.2s |  |
| 79 | `Random-v6` | 30 | 1.4s |  |
| 80 | `Random-v7` | 30 | 3.0s |  |
| 81 | `Random-v8` | 30 | 2.4s |  |
| 82 | `Rectangle-v5` | 7 | 2.9s |  |
| 83 | `Rectangle-v6` | 7 | 1.4s |  |
| 84 | `Rectangle-v7` | 7 | 2.5s |  |
| 85 | `Rectangle-v8` | 166 | 7.6s |  |
| 86 | `Selection-v5` | 21 | 21.8s |  |
| 87 | `Sound-v6` | 121 | 5.2s |  |
| 88 | `Sound-v7` | 121 | 4.6s |  |
| 89 | `Sound-v8` | 121 | 2.4s |  |
| 90 | `Stage-v5` | 38 | 19.7s |  |
| 91 | `System-v5` | 67 | 26.3s |  |
| 92 | `System-v6` | 100 | 5.0s |  |
| 93 | `System-v7` | 101 | 5.2s |  |
| 94 | `System-v8` | 101 | 2.4s |  |
| 95 | `TextFieldHTML-v5` | 6 | 18.0s |  |
| 96 | `TextFieldHTML-v6` | 37 | 3.0s |  |
| 97 | `TextFieldHTML-v7` | 37 | 2.7s |  |
| 98 | `TextFieldHTML-v8` | 37 | 2.1s |  |
| 99 | `TextFormat-v5` | 128 | 5.0s |  |
| 100 | `TextFormat-v6` | 128 | 1.3s |  |
| 101 | `TextSnapshot-v5` | 7 | 26.9s |  |
| 102 | `TextSnapshot-v6` | 173 | 9.6s |  |
| 103 | `TextSnapshot-v7` | 173 | 9.4s |  |
| 104 | `TextSnapshot-v8` | 173 | 2.8s |  |
| 105 | `Transform-v5` | 7 | 3.2s |  |
| 106 | `Transform-v6` | 7 | 2.6s |  |
| 107 | `Transform-v7` | 7 | 2.8s |  |
| 108 | `Try-v5` | 20 | 20.1s |  |
| 109 | `Try-v6` | 20 | 1.1s |  |
| 110 | `Try-v7` | 20 | 2.7s |  |
| 111 | `Try-v8` | 20 | 1.8s |  |
| 112 | `Video-v5` | 7 | 2.2s |  |
| 113 | `Video-v6` | 85 | 3.3s |  |
| 114 | `Video-v7` | 85 | 3.0s |  |
| 115 | `Video-v8` | 85 | 1.8s |  |
| 116 | `XMLSocket-v5` | 35 | 20.2s |  |
| 117 | `XMLSocket-v6` | 35 | 2.7s |  |
| 118 | `XMLSocket-v7` | 35 | 2.5s |  |
| 119 | `XMLSocket-v8` | 35 | 1.9s |  |
| 120 | `argstest-v5` | 4 | 2.3s |  |
| 121 | `case-v5` | 39 | 4.0s |  |
| 122 | `case-v6` | 73 | 5.0s |  |
| 123 | `case-v7` | 67 | 4.9s |  |
| 124 | `case-v8` | 67 | 2.8s |  |
| 125 | `delete-v5` | 61 | 21.6s |  |
| 126 | `delete-v6` | 61 | 3.1s |  |
| 127 | `delete-v7` | 61 | 3.4s |  |
| 128 | `delete-v8` | 61 | 2.3s |  |
| 129 | `enumerate-v5` | 6 | 2.4s |  |
| 130 | `enumerate-v6` | 49 | 3.6s |  |
| 131 | `enumerate-v7` | 49 | 3.3s |  |
| 132 | `enumerate-v8` | 49 | 2.1s |  |
| 133 | `flash-v5` | 10 | 20.0s |  |
| 134 | `flash-v6` | 10 | 2.3s |  |
| 135 | `flash-v7` | 10 | 2.0s |  |
| 136 | `flash-v8` | 41 | 3.0s |  |
| 137 | `getvariable-v5` | 58 | 3.1s |  |
| 138 | `getvariable-v6` | 64 | 3.4s |  |
| 139 | `getvariable-v7` | 64 | 3.4s |  |
| 140 | `getvariable-v8` | 64 | 2.0s |  |
| 141 | `swap-v5` | 7 | 26.1s |  |
| 142 | `swap-v6` | 7 | 1.6s |  |
| 143 | `swap-v7` | 7 | 3.1s |  |
| 144 | `swap-v8` | 7 | 2.8s |  |
| 145 | `targetPath-v5` | 12 | 3.5s |  |
| 146 | `targetPath-v6` | 23 | 3.6s |  |
| 147 | `targetPath-v7` | 23 | 3.3s |  |
| 148 | `targetPath-v8` | 23 | 2.8s |  |

## Ruffle-Matched Tests

**92 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 22.2s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.5s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.9s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 20.9s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.7s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.4s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.8s |  |
| 9 | `Date-v5` | 7 | 7 | 14.1s |  |
| 10 | `Date-v6` | 6 | 6 | 15.6s |  |
| 11 | `Date-v7` | 6 | 6 | 15.9s |  |
| 12 | `Date-v8` | 6 | 6 | 2.9s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 4.3s |  |
| 14 | `Function-v5` | 10 | 25 | 5.0s |  |
| 15 | `Global-v6` | 9 | 10 | 7.6s |  |
| 16 | `HitTest-v6` | 8 | 8 | 4.6s |  |
| 17 | `HitTest-v7` | 8 | 8 | 4.3s |  |
| 18 | `HitTest-v8` | 9 | 9 | 4.1s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 22.7s |  |
| 20 | `Inheritance-v6` | 9 | 13 | 6.3s |  |
| 21 | `Inheritance-v7` | 5 | 7 | 6.5s |  |
| 22 | `Inheritance-v8` | 5 | 7 | 2.4s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 4.9s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 4.7s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 2.5s |  |
| 26 | `Math-v5` | 5 | 5 | 14.1s |  |
| 27 | `Math-v6` | 5 | 5 | 1.5s |  |
| 28 | `Math-v7` | 5 | 5 | 14.4s |  |
| 29 | `Math-v8` | 5 | 5 | 2.6s |  |
| 30 | `Microphone-v6` | 31 | 31 | 4.9s |  |
| 31 | `Microphone-v7` | 31 | 31 | 4.6s |  |
| 32 | `Microphone-v8` | 31 | 31 | 2.9s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 10.7s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 35.1s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 38.0s |  |
| 36 | `MovieClip-v8` | 25 | 68 | 47.1s |  |
| 37 | `MovieClipLoader-v7` | 118 | 118 | 5.7s |  |
| 38 | `MovieClipLoader-v8` | 118 | 118 | 4.1s |  |
| 39 | `NetConnection-v6` | 4 | 49 | 6.9s |  |
| 40 | `NetConnection-v7` | 4 | 45 | 7.1s |  |
| 41 | `NetConnection-v8` | 4 | 45 | 3.1s |  |
| 42 | `Number-v5` | 8 | 12 | 8.9s |  |
| 43 | `Object-v5` | 3 | 4 | 22.5s |  |
| 44 | `Object-v6` | 8 | 21 | 11.1s |  |
| 45 | `Object-v7` | 8 | 12 | 11.0s |  |
| 46 | `Object-v8` | 8 | 12 | 2.4s |  |
| 47 | `Selection-v6` | 7 | 13 | 5.0s |  |
| 48 | `Selection-v7` | 7 | 13 | 4.9s |  |
| 49 | `Selection-v8` | 7 | 13 | 2.2s |  |
| 50 | `Sound-v5` | 14 | 16 | 4.9s |  |
| 51 | `Stage-v6` | 14 | 14 | 3.0s |  |
| 52 | `Stage-v7` | 14 | 14 | 2.8s |  |
| 53 | `Stage-v8` | 14 | 14 | 1.9s |  |
| 54 | `String-v5` | 18 | 21 | 13.3s |  |
| 55 | `String-v6` | 9 | 10 | 14.3s |  |
| 56 | `String-v7` | 9 | 10 | 14.0s |  |
| 57 | `String-v8` | 9 | 10 | 2.1s |  |
| 58 | `TextField-v5` | 3 | 3 | 3.0s |  |
| 59 | `TextField-v6` | 15 | 57 | 22.8s |  |
| 60 | `TextField-v7` | 15 | 73 | 24.5s |  |
| 61 | `TextField-v8` | 14 | 72 | 24.6s |  |
| 62 | `TextFormat-v7` | 38 | 38 | 7.0s |  |
| 63 | `TextFormat-v8` | 36 | 36 | 6.4s |  |
| 64 | `Transform-v8` | 7 | 7 | 6.6s |  |
| 65 | `XML-v5` | 10 | 79 | 28.7s |  |
| 66 | `XML-v6` | 3 | 98 | 12.9s |  |
| 67 | `XML-v7` | 3 | 98 | 12.7s |  |
| 68 | `XML-v8` | 24 | 116 | 4.2s |  |
| 69 | `XMLNode-v5` | 3 | 22 | 7.2s |  |
| 70 | `XMLNode-v6` | 3 | 22 | 7.0s |  |
| 71 | `XMLNode-v7` | 3 | 22 | 6.2s |  |
| 72 | `XMLNode-v8` | 3 | 22 | 1.9s |  |
| 73 | `array-v5` | 5 | 17 | 54.1s |  |
| 74 | `array-v6` | 6 | 25 | 37.2s |  |
| 75 | `array-v7` | 5 | 23 | 39.1s |  |
| 76 | `array-v8` | 5 | 23 | 4.8s |  |
| 77 | `ops-v5` | 7 | 9 | 26.8s |  |
| 78 | `ops-v6` | 7 | 11 | 8.2s |  |
| 79 | `ops-v7` | 7 | 11 | 8.7s |  |
| 80 | `ops-v8` | 7 | 11 | 1.8s |  |
| 81 | `setProperty-v5` | 49 | 49 | 2.9s |  |
| 82 | `setProperty-v6` | 49 | 49 | 2.9s |  |
| 83 | `setProperty-v7` | 49 | 49 | 2.6s |  |
| 84 | `setProperty-v8` | 49 | 49 | 1.9s |  |
| 85 | `toString_valueOf-v5` | 34 | 34 | 22.6s |  |
| 86 | `toString_valueOf-v6` | 5 | 5 | 5.1s |  |
| 87 | `toString_valueOf-v7` | 5 | 5 | 4.8s |  |
| 88 | `toString_valueOf-v8` | 5 | 5 | 1.9s |  |
| 89 | `with-v5` | 3 | 3 | 3.5s |  |
| 90 | `with-v6` | 6 | 9 | 4.4s |  |
| 91 | `with-v7` | 6 | 9 | 4.2s |  |
| 92 | `with-v8` | 6 | 9 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.
