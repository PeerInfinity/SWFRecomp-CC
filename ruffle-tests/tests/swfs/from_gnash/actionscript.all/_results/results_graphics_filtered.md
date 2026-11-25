# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 05:10 UTC

**Git SHA**: `7c3cfdcb7b`

**Run Duration**: 21m 47s

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
| 1 | `Accessibility-v5` | 15 | 2.3s |  |
| 2 | `Accessibility-v6` | 19 | 2.4s |  |
| 3 | `Accessibility-v7` | 19 | 2.1s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.2s |  |
| 6 | `AsBroadcaster-v6` | 121 | 4.7s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.3s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.9s |  |
| 9 | `BitmapData-v5` | 7 | 2.1s |  |
| 10 | `BitmapData-v6` | 7 | 1.1s |  |
| 11 | `BitmapData-v7` | 7 | 1.8s |  |
| 12 | `Boolean-v5` | 38 | 2.5s |  |
| 13 | `Boolean-v6` | 38 | 2.2s |  |
| 14 | `Boolean-v7` | 38 | 2.6s |  |
| 15 | `Boolean-v8` | 38 | 1.9s |  |
| 16 | `Camera-v5` | 7 | 2.3s |  |
| 17 | `Color-v5` | 140 | 4.9s |  |
| 18 | `Color-v6` | 171 | 5.8s |  |
| 19 | `Color-v7` | 161 | 5.6s |  |
| 20 | `Color-v8` | 161 | 5.6s |  |
| 21 | `ColorTransform-v5` | 7 | 2.2s |  |
| 22 | `ColorTransform-v6` | 7 | 1.1s |  |
| 23 | `ColorTransform-v7` | 7 | 2.0s |  |
| 24 | `ColorTransform-v8` | 55 | 3.2s |  |
| 25 | `ContextMenu-v5` | 7 | 2.2s |  |
| 26 | `ContextMenu-v6` | 7 | 1.1s |  |
| 27 | `ContextMenu-v7` | 131 | 4.3s |  |
| 28 | `ContextMenu-v8` | 131 | 4.5s |  |
| 29 | `Error-v5` | 28 | 2.6s |  |
| 30 | `Error-v6` | 31 | 2.6s |  |
| 31 | `Error-v7` | 31 | 2.4s |  |
| 32 | `Error-v8` | 31 | 2.7s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.2s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.0s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.7s |  |
| 36 | `Function-v6` | 271 | 8.5s |  |
| 37 | `Function-v7` | 272 | 8.8s |  |
| 38 | `Function-v8` | 272 | 11.7s |  |
| 39 | `Global-v5` | 172 | 8.7s |  |
| 40 | `Global-v7` | 182 | 9.0s |  |
| 41 | `Global-v8` | 169 | 8.4s |  |
| 42 | `Instance-v5` | 52 | 2.9s |  |
| 43 | `Instance-v6` | 52 | 1.8s |  |
| 44 | `Instance-v7` | 52 | 2.6s |  |
| 45 | `Instance-v8` | 52 | 1.8s |  |
| 46 | `Key-v5` | 51 | 4.2s |  |
| 47 | `Key-v6` | 55 | 4.3s |  |
| 48 | `Key-v7` | 55 | 4.0s |  |
| 49 | `Key-v8` | 55 | 2.8s |  |
| 50 | `LoadVars-v5` | 8 | 3.4s |  |
| 51 | `LocalConnection-v5` | 7 | 2.2s |  |
| 52 | `LocalConnection-v6` | 58 | 3.1s |  |
| 53 | `LocalConnection-v7` | 58 | 2.8s |  |
| 54 | `LocalConnection-v8` | 58 | 1.8s |  |
| 55 | `Matrix-v5` | 7 | 2.9s |  |
| 56 | `Matrix-v6` | 168 | 8.2s |  |
| 57 | `Matrix-v7` | 168 | 8.1s |  |
| 58 | `Matrix-v8` | 168 | 2.6s |  |
| 59 | `Microphone-v5` | 6 | 2.4s |  |
| 60 | `Mouse-v5` | 13 | 2.3s |  |
| 61 | `Mouse-v6` | 21 | 2.4s |  |
| 62 | `Mouse-v7` | 21 | 2.2s |  |
| 63 | `Mouse-v8` | 21 | 1.9s |  |
| 64 | `MovieClipLoader-v5` | 6 | 3.1s |  |
| 65 | `MovieClipLoader-v6` | 6 | 1.7s |  |
| 66 | `NetConnection-v5` | 7 | 3.5s |  |
| 67 | `NetStream-v5` | 6 | 2.3s |  |
| 68 | `NetStream-v6` | 80 | 3.5s |  |
| 69 | `NetStream-v7` | 80 | 3.3s |  |
| 70 | `NetStream-v8` | 80 | 1.9s |  |
| 71 | `Number-v6` | 239 | 8.1s |  |
| 72 | `Number-v7` | 237 | 8.1s |  |
| 73 | `Number-v8` | 237 | 2.0s |  |
| 74 | `Point-v5` | 7 | 2.2s |  |
| 75 | `Point-v6` | 7 | 1.1s |  |
| 76 | `Point-v7` | 7 | 1.9s |  |
| 77 | `Point-v8` | 193 | 6.4s |  |
| 78 | `Random-v5` | 30 | 2.7s |  |
| 79 | `Random-v6` | 30 | 1.1s |  |
| 80 | `Random-v7` | 30 | 2.4s |  |
| 81 | `Random-v8` | 30 | 1.9s |  |
| 82 | `Rectangle-v5` | 7 | 2.3s |  |
| 83 | `Rectangle-v6` | 7 | 1.1s |  |
| 84 | `Rectangle-v7` | 7 | 2.0s |  |
| 85 | `Rectangle-v8` | 166 | 6.1s |  |
| 86 | `Selection-v5` | 21 | 2.5s |  |
| 87 | `Sound-v6` | 121 | 5.2s |  |
| 88 | `Sound-v7` | 121 | 4.7s |  |
| 89 | `Sound-v8` | 121 | 2.2s |  |
| 90 | `Stage-v5` | 38 | 2.8s |  |
| 91 | `System-v5` | 67 | 4.7s |  |
| 92 | `System-v6` | 100 | 5.6s |  |
| 93 | `System-v7` | 101 | 5.7s |  |
| 94 | `System-v8` | 101 | 2.9s |  |
| 95 | `TextFieldHTML-v5` | 6 | 2.8s |  |
| 96 | `TextFieldHTML-v6` | 37 | 2.7s |  |
| 97 | `TextFieldHTML-v7` | 37 | 2.4s |  |
| 98 | `TextFieldHTML-v8` | 37 | 1.8s |  |
| 99 | `TextFormat-v5` | 128 | 4.3s |  |
| 100 | `TextFormat-v6` | 128 | 1.1s |  |
| 101 | `TextSnapshot-v5` | 7 | 2.7s |  |
| 102 | `TextSnapshot-v6` | 173 | 6.9s |  |
| 103 | `TextSnapshot-v7` | 173 | 6.7s |  |
| 104 | `TextSnapshot-v8` | 173 | 2.0s |  |
| 105 | `Transform-v5` | 7 | 2.2s |  |
| 106 | `Transform-v6` | 7 | 1.9s |  |
| 107 | `Transform-v7` | 7 | 2.0s |  |
| 108 | `Try-v5` | 20 | 3.0s |  |
| 109 | `Try-v6` | 20 | 1.1s |  |
| 110 | `Try-v7` | 20 | 2.7s |  |
| 111 | `Try-v8` | 20 | 1.8s |  |
| 112 | `Video-v5` | 7 | 2.2s |  |
| 113 | `Video-v6` | 85 | 3.3s |  |
| 114 | `Video-v7` | 85 | 3.0s |  |
| 115 | `Video-v8` | 85 | 1.8s |  |
| 116 | `XMLSocket-v5` | 35 | 4.1s |  |
| 117 | `XMLSocket-v6` | 35 | 4.2s |  |
| 118 | `XMLSocket-v7` | 35 | 3.8s |  |
| 119 | `XMLSocket-v8` | 35 | 3.0s |  |
| 120 | `argstest-v5` | 4 | 3.7s |  |
| 121 | `case-v5` | 39 | 3.0s |  |
| 122 | `case-v6` | 73 | 3.8s |  |
| 123 | `case-v7` | 67 | 3.8s |  |
| 124 | `case-v8` | 67 | 2.1s |  |
| 125 | `delete-v5` | 61 | 0.9s |  |
| 126 | `delete-v6` | 61 | 0.8s |  |
| 127 | `delete-v7` | 61 | 0.8s |  |
| 128 | `delete-v8` | 61 | 0.8s |  |
| 129 | `enumerate-v5` | 6 | 0.8s |  |
| 130 | `enumerate-v6` | 49 | 0.8s |  |
| 131 | `enumerate-v7` | 49 | 0.8s |  |
| 132 | `enumerate-v8` | 49 | 0.9s |  |
| 133 | `flash-v5` | 10 | 3.3s |  |
| 134 | `flash-v6` | 10 | 3.2s |  |
| 135 | `flash-v7` | 10 | 2.9s |  |
| 136 | `flash-v8` | 41 | 4.2s |  |
| 137 | `getvariable-v5` | 58 | 4.6s |  |
| 138 | `getvariable-v6` | 64 | 4.8s |  |
| 139 | `getvariable-v7` | 64 | 4.9s |  |
| 140 | `getvariable-v8` | 64 | 2.7s |  |
| 141 | `swap-v5` | 7 | 2.3s |  |
| 142 | `swap-v6` | 7 | 1.1s |  |
| 143 | `swap-v7` | 7 | 2.0s |  |
| 144 | `swap-v8` | 7 | 1.9s |  |
| 145 | `targetPath-v5` | 12 | 2.4s |  |
| 146 | `targetPath-v6` | 23 | 2.5s |  |
| 147 | `targetPath-v7` | 23 | 2.3s |  |
| 148 | `targetPath-v8` | 23 | 1.9s |  |

## Ruffle-Matched Tests

**92 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 4.8s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.7s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.9s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 21.2s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.1s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.8s |  |
| 8 | `Camera-v8` | 57 | 57 | 2.1s |  |
| 9 | `Date-v5` | 7 | 7 | 11.5s |  |
| 10 | `Date-v6` | 6 | 6 | 13.1s |  |
| 11 | `Date-v7` | 6 | 6 | 13.6s |  |
| 12 | `Date-v8` | 6 | 6 | 2.2s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 4.6s |  |
| 14 | `Function-v5` | 10 | 25 | 5.2s |  |
| 15 | `Global-v6` | 9 | 10 | 10.3s |  |
| 16 | `HitTest-v6` | 8 | 8 | 6.6s |  |
| 17 | `HitTest-v7` | 8 | 8 | 6.3s |  |
| 18 | `HitTest-v8` | 9 | 9 | 6.1s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 4.1s |  |
| 20 | `Inheritance-v6` | 9 | 13 | 5.5s |  |
| 21 | `Inheritance-v7` | 5 | 7 | 5.6s |  |
| 22 | `Inheritance-v8` | 5 | 7 | 2.2s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 7.2s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 6.9s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 3.7s |  |
| 26 | `Math-v5` | 5 | 5 | 11.7s |  |
| 27 | `Math-v6` | 5 | 5 | 1.3s |  |
| 28 | `Math-v7` | 5 | 5 | 12.2s |  |
| 29 | `Math-v8` | 5 | 5 | 2.0s |  |
| 30 | `Microphone-v6` | 31 | 31 | 4.3s |  |
| 31 | `Microphone-v7` | 31 | 31 | 4.0s |  |
| 32 | `Microphone-v8` | 31 | 31 | 2.5s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 11.8s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 40.8s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 43.0s |  |
| 36 | `MovieClip-v8` | 25 | 68 | 54.5s |  |
| 37 | `MovieClipLoader-v7` | 118 | 118 | 5.8s |  |
| 38 | `MovieClipLoader-v8` | 118 | 118 | 4.2s |  |
| 39 | `NetConnection-v6` | 4 | 49 | 7.2s |  |
| 40 | `NetConnection-v7` | 4 | 45 | 7.2s |  |
| 41 | `NetConnection-v8` | 4 | 45 | 3.2s |  |
| 42 | `Number-v5` | 8 | 12 | 8.4s |  |
| 43 | `Object-v5` | 3 | 4 | 4.9s |  |
| 44 | `Object-v6` | 8 | 21 | 10.4s |  |
| 45 | `Object-v7` | 8 | 12 | 10.7s |  |
| 46 | `Object-v8` | 8 | 12 | 2.4s |  |
| 47 | `Selection-v6` | 7 | 13 | 4.9s |  |
| 48 | `Selection-v7` | 7 | 13 | 4.7s |  |
| 49 | `Selection-v8` | 7 | 13 | 2.0s |  |
| 50 | `Sound-v5` | 14 | 16 | 4.8s |  |
| 51 | `Stage-v6` | 14 | 14 | 3.2s |  |
| 52 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 53 | `Stage-v8` | 14 | 14 | 2.0s |  |
| 54 | `String-v5` | 18 | 21 | 14.0s |  |
| 55 | `String-v6` | 9 | 10 | 15.1s |  |
| 56 | `String-v7` | 9 | 10 | 14.8s |  |
| 57 | `String-v8` | 9 | 10 | 2.2s |  |
| 58 | `TextField-v5` | 3 | 3 | 3.5s |  |
| 59 | `TextField-v6` | 15 | 57 | 25.3s |  |
| 60 | `TextField-v7` | 15 | 73 | 27.3s |  |
| 61 | `TextField-v8` | 14 | 72 | 27.0s |  |
| 62 | `TextFormat-v7` | 38 | 38 | 5.5s |  |
| 63 | `TextFormat-v8` | 36 | 36 | 5.6s |  |
| 64 | `Transform-v8` | 7 | 7 | 4.5s |  |
| 65 | `XML-v5` | 10 | 79 | 12.5s |  |
| 66 | `XML-v6` | 3 | 98 | 14.2s |  |
| 67 | `XML-v7` | 3 | 98 | 14.0s |  |
| 68 | `XML-v8` | 24 | 116 | 4.4s |  |
| 69 | `XMLNode-v5` | 3 | 22 | 7.8s |  |
| 70 | `XMLNode-v6` | 3 | 22 | 7.6s |  |
| 71 | `XMLNode-v7` | 3 | 22 | 6.6s |  |
| 72 | `XMLNode-v8` | 3 | 22 | 2.0s |  |
| 73 | `array-v5` | 5 | 17 | 26.3s |  |
| 74 | `array-v6` | 6 | 25 | 31.4s |  |
| 75 | `array-v7` | 5 | 23 | 32.0s |  |
| 76 | `array-v8` | 5 | 23 | 3.3s |  |
| 77 | `ops-v5` | 7 | 9 | 9.1s |  |
| 78 | `ops-v6` | 7 | 11 | 8.0s |  |
| 79 | `ops-v7` | 7 | 11 | 8.5s |  |
| 80 | `ops-v8` | 7 | 11 | 2.0s |  |
| 81 | `setProperty-v5` | 49 | 49 | 3.1s |  |
| 82 | `setProperty-v6` | 49 | 49 | 3.1s |  |
| 83 | `setProperty-v7` | 49 | 49 | 2.9s |  |
| 84 | `setProperty-v8` | 49 | 49 | 2.1s |  |
| 85 | `toString_valueOf-v5` | 34 | 34 | 5.2s |  |
| 86 | `toString_valueOf-v6` | 5 | 5 | 4.8s |  |
| 87 | `toString_valueOf-v7` | 5 | 5 | 4.6s |  |
| 88 | `toString_valueOf-v8` | 5 | 5 | 1.9s |  |
| 89 | `with-v5` | 3 | 3 | 3.3s |  |
| 90 | `with-v6` | 6 | 9 | 4.2s |  |
| 91 | `with-v7` | 6 | 9 | 4.0s |  |
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
