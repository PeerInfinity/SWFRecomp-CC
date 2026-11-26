# Ruffle Test Results (Filtered)

**Date**: 2026-11-26 00:30 UTC

**Git SHA**: `b030ed745d`

**Run Duration**: 31m 6s

**Filtered**: 3 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 240 |
| Passing | **177** (73.8%) |
| Ruffle-matched | 63 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (100.0%) |
| Failing | 0 |
| Total expected lines | 32104 |
| Matching lines | 30812 (96.0%) |
| Mismatched lines | 1292 |

## Passing Tests

**177 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.4s |  |
| 2 | `Accessibility-v6` | 19 | 2.4s |  |
| 3 | `Accessibility-v7` | 19 | 2.1s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.3s |  |
| 6 | `AsBroadcaster-v6` | 121 | 22.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.3s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.0s |  |
| 9 | `BitmapData-v5` | 7 | 2.2s |  |
| 10 | `BitmapData-v6` | 7 | 1.1s |  |
| 11 | `BitmapData-v7` | 7 | 2.0s |  |
| 12 | `Boolean-v5` | 38 | 2.6s |  |
| 13 | `Boolean-v6` | 38 | 2.2s |  |
| 14 | `Boolean-v7` | 38 | 21.0s |  |
| 15 | `Boolean-v8` | 38 | 1.9s |  |
| 16 | `Camera-v5` | 7 | 2.3s |  |
| 17 | `Color-v5` | 140 | 5.0s |  |
| 18 | `Color-v6` | 171 | 6.0s |  |
| 19 | `Color-v7` | 161 | 5.7s |  |
| 20 | `Color-v8` | 161 | 24.4s |  |
| 21 | `ColorTransform-v5` | 7 | 2.7s |  |
| 22 | `ColorTransform-v6` | 7 | 1.4s |  |
| 23 | `ColorTransform-v7` | 7 | 2.4s |  |
| 24 | `ColorTransform-v8` | 55 | 3.7s |  |
| 25 | `ContextMenu-v5` | 7 | 2.7s |  |
| 26 | `ContextMenu-v6` | 7 | 1.3s |  |
| 27 | `ContextMenu-v7` | 131 | 5.2s |  |
| 28 | `ContextMenu-v8` | 131 | 22.0s |  |
| 29 | `Error-v5` | 28 | 2.6s |  |
| 30 | `Error-v6` | 31 | 2.6s |  |
| 31 | `Error-v7` | 31 | 2.3s |  |
| 32 | `Error-v8` | 31 | 20.1s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.2s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.9s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `Function-v6` | 271 | 8.2s |  |
| 37 | `Function-v7` | 272 | 8.2s |  |
| 38 | `Function-v8` | 272 | 34.0s |  |
| 39 | `Global-v5` | 172 | 8.6s |  |
| 40 | `Global-v6` | 210 | 9.9s |  |
| 41 | `Global-v7` | 182 | 8.9s |  |
| 42 | `Global-v8` | 169 | 8.3s |  |
| 43 | `HitTest-v6` | 88 | 6.4s |  |
| 44 | `HitTest-v7` | 88 | 6.0s |  |
| 45 | `Instance-v5` | 52 | 3.0s |  |
| 46 | `Instance-v6` | 52 | 1.9s |  |
| 47 | `Instance-v7` | 52 | 2.9s |  |
| 48 | `Instance-v8` | 52 | 2.1s |  |
| 49 | `Key-v5` | 51 | 20.5s |  |
| 50 | `Key-v6` | 55 | 3.0s |  |
| 51 | `Key-v7` | 55 | 2.7s |  |
| 52 | `Key-v8` | 55 | 1.8s |  |
| 53 | `LoadVars-v5` | 8 | 2.2s |  |
| 54 | `LocalConnection-v5` | 7 | 19.6s |  |
| 55 | `LocalConnection-v6` | 58 | 3.0s |  |
| 56 | `LocalConnection-v7` | 58 | 2.8s |  |
| 57 | `LocalConnection-v8` | 58 | 1.8s |  |
| 58 | `Matrix-v5` | 7 | 16.8s |  |
| 59 | `Matrix-v6` | 168 | 6.4s |  |
| 60 | `Matrix-v7` | 168 | 6.4s |  |
| 61 | `Matrix-v8` | 168 | 2.0s |  |
| 62 | `Microphone-v5` | 6 | 2.2s |  |
| 63 | `Mouse-v5` | 13 | 19.7s |  |
| 64 | `Mouse-v6` | 21 | 2.4s |  |
| 65 | `Mouse-v7` | 21 | 2.1s |  |
| 66 | `Mouse-v8` | 21 | 1.8s |  |
| 67 | `MovieClipLoader-v5` | 6 | 19.9s |  |
| 68 | `MovieClipLoader-v6` | 6 | 1.1s |  |
| 69 | `NetConnection-v5` | 7 | 2.2s |  |
| 70 | `NetStream-v5` | 6 | 20.4s |  |
| 71 | `NetStream-v6` | 80 | 3.6s |  |
| 72 | `NetStream-v7` | 80 | 3.5s |  |
| 73 | `NetStream-v8` | 80 | 2.0s |  |
| 74 | `Number-v5` | 244 | 8.7s |  |
| 75 | `Number-v6` | 239 | 8.4s |  |
| 76 | `Number-v7` | 237 | 8.5s |  |
| 77 | `Number-v8` | 237 | 2.1s |  |
| 78 | `Object-v5` | 145 | 5.5s |  |
| 79 | `Point-v5` | 7 | 2.3s |  |
| 80 | `Point-v6` | 7 | 1.1s |  |
| 81 | `Point-v7` | 7 | 2.0s |  |
| 82 | `Point-v8` | 193 | 7.4s |  |
| 83 | `Random-v5` | 30 | 18.7s |  |
| 84 | `Random-v6` | 30 | 1.2s |  |
| 85 | `Random-v7` | 30 | 2.6s |  |
| 86 | `Random-v8` | 30 | 2.1s |  |
| 87 | `Rectangle-v5` | 7 | 2.5s |  |
| 88 | `Rectangle-v6` | 7 | 1.2s |  |
| 89 | `Rectangle-v7` | 7 | 2.2s |  |
| 90 | `Rectangle-v8` | 166 | 6.6s |  |
| 91 | `Selection-v5` | 21 | 20.1s |  |
| 92 | `Selection-v6` | 125 | 4.7s |  |
| 93 | `Selection-v7` | 125 | 4.5s |  |
| 94 | `Selection-v8` | 125 | 2.0s |  |
| 95 | `Sound-v6` | 121 | 5.0s |  |
| 96 | `Sound-v7` | 121 | 4.4s |  |
| 97 | `Sound-v8` | 121 | 2.2s |  |
| 98 | `Stage-v5` | 38 | 26.6s |  |
| 99 | `String-v6` | 377 | 18.8s |  |
| 100 | `String-v7` | 377 | 18.5s |  |
| 101 | `String-v8` | 377 | 2.9s |  |
| 102 | `System-v5` | 67 | 28.9s |  |
| 103 | `System-v6` | 100 | 5.8s |  |
| 104 | `System-v7` | 101 | 5.9s |  |
| 105 | `System-v8` | 101 | 3.0s |  |
| 106 | `TextField-v5` | 12 | 3.6s |  |
| 107 | `TextFieldHTML-v5` | 6 | 31.4s |  |
| 108 | `TextFieldHTML-v6` | 37 | 4.7s |  |
| 109 | `TextFieldHTML-v7` | 37 | 4.2s |  |
| 110 | `TextFieldHTML-v8` | 37 | 3.2s |  |
| 111 | `TextFormat-v5` | 128 | 7.9s |  |
| 112 | `TextFormat-v6` | 128 | 2.0s |  |
| 113 | `TextSnapshot-v5` | 7 | 20.4s |  |
| 114 | `TextSnapshot-v6` | 173 | 6.6s |  |
| 115 | `TextSnapshot-v7` | 173 | 6.2s |  |
| 116 | `TextSnapshot-v8` | 173 | 1.9s |  |
| 117 | `Transform-v5` | 7 | 2.2s |  |
| 118 | `Transform-v6` | 7 | 1.8s |  |
| 119 | `Transform-v7` | 7 | 2.0s |  |
| 120 | `Try-v5` | 20 | 26.6s |  |
| 121 | `Try-v6` | 20 | 1.6s |  |
| 122 | `Try-v7` | 20 | 4.0s |  |
| 123 | `Try-v8` | 20 | 2.8s |  |
| 124 | `Video-v5` | 7 | 3.3s |  |
| 125 | `Video-v6` | 85 | 4.8s |  |
| 126 | `Video-v7` | 85 | 4.5s |  |
| 127 | `Video-v8` | 85 | 2.7s |  |
| 128 | `XML-v6` | 486 | 13.6s |  |
| 129 | `XML-v7` | 486 | 13.4s |  |
| 130 | `XMLNode-v5` | 207 | 7.7s |  |
| 131 | `XMLNode-v6` | 207 | 7.7s |  |
| 132 | `XMLNode-v7` | 207 | 6.9s |  |
| 133 | `XMLNode-v8` | 207 | 2.1s |  |
| 134 | `XMLSocket-v5` | 35 | 18.6s |  |
| 135 | `XMLSocket-v6` | 35 | 2.8s |  |
| 136 | `XMLSocket-v7` | 35 | 2.6s |  |
| 137 | `XMLSocket-v8` | 35 | 2.1s |  |
| 138 | `argstest-v5` | 4 | 2.5s |  |
| 139 | `case-v5` | 39 | 4.1s |  |
| 140 | `case-v6` | 73 | 5.0s |  |
| 141 | `case-v7` | 67 | 5.0s |  |
| 142 | `case-v8` | 67 | 2.9s |  |
| 143 | `delete-v5` | 61 | 20.6s |  |
| 144 | `delete-v6` | 61 | 2.6s |  |
| 145 | `delete-v7` | 61 | 2.8s |  |
| 146 | `delete-v8` | 61 | 2.0s |  |
| 147 | `enumerate-v5` | 6 | 2.2s |  |
| 148 | `enumerate-v6` | 49 | 3.0s |  |
| 149 | `enumerate-v7` | 49 | 2.7s |  |
| 150 | `enumerate-v8` | 49 | 1.8s |  |
| 151 | `flash-v5` | 10 | 19.6s |  |
| 152 | `flash-v6` | 10 | 2.2s |  |
| 153 | `flash-v7` | 10 | 2.0s |  |
| 154 | `flash-v8` | 41 | 2.9s |  |
| 155 | `getvariable-v5` | 58 | 3.1s |  |
| 156 | `getvariable-v6` | 64 | 3.2s |  |
| 157 | `getvariable-v7` | 64 | 3.2s |  |
| 158 | `getvariable-v8` | 64 | 1.9s |  |
| 159 | `ops-v5` | 260 | 27.9s |  |
| 160 | `ops-v6` | 260 | 8.3s |  |
| 161 | `ops-v7` | 262 | 8.9s |  |
| 162 | `ops-v8` | 262 | 1.8s |  |
| 163 | `swap-v5` | 7 | 18.3s |  |
| 164 | `swap-v6` | 7 | 1.2s |  |
| 165 | `swap-v7` | 7 | 2.1s |  |
| 166 | `swap-v8` | 7 | 2.0s |  |
| 167 | `targetPath-v5` | 12 | 2.4s |  |
| 168 | `targetPath-v6` | 23 | 2.6s |  |
| 169 | `targetPath-v7` | 23 | 2.3s |  |
| 170 | `targetPath-v8` | 23 | 2.0s |  |
| 171 | `toString_valueOf-v6` | 155 | 5.1s |  |
| 172 | `toString_valueOf-v7` | 155 | 4.9s |  |
| 173 | `toString_valueOf-v8` | 155 | 2.0s |  |
| 174 | `with-v5` | 49 | 3.4s |  |
| 175 | `with-v6` | 107 | 4.4s |  |
| 176 | `with-v7` | 107 | 4.1s |  |
| 177 | `with-v8` | 107 | 2.1s |  |

## Ruffle-Matched Tests

**63 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 22.8s |  |
| 2 | `ASnative-v6` | 39 | 40 | 5.0s |  |
| 3 | `ASnative-v7` | 39 | 40 | 4.7s |  |
| 4 | `ASnative-v8` | 39 | 40 | 2.0s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 20.3s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.0s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.6s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.9s |  |
| 9 | `Date-v5` | 6 | 7 | 11.4s |  |
| 10 | `Date-v6` | 6 | 6 | 12.9s |  |
| 11 | `Date-v7` | 6 | 6 | 13.2s |  |
| 12 | `Date-v8` | 6 | 6 | 2.2s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 4.4s |  |
| 14 | `Function-v5` | 4 | 25 | 5.0s |  |
| 15 | `HitTest-v8` | 3 | 9 | 5.9s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 20.5s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 6.4s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 6.3s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 2.4s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 4.8s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 4.6s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 2.5s |  |
| 23 | `Math-v5` | 5 | 5 | 11.4s |  |
| 24 | `Math-v6` | 5 | 5 | 1.2s |  |
| 25 | `Math-v7` | 5 | 5 | 11.9s |  |
| 26 | `Math-v8` | 5 | 5 | 1.9s |  |
| 27 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 28 | `Microphone-v7` | 31 | 31 | 3.2s |  |
| 29 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 30 | `MovieClip-v5` | 10 | 226 | 10.9s |  |
| 31 | `MovieClip-v6` | 20 | 60 | 38.6s |  |
| 32 | `MovieClip-v7` | 20 | 64 | 41.2s |  |
| 33 | `MovieClip-v8` | 25 | 68 | 52.8s |  |
| 34 | `MovieClipLoader-v7` | 118 | 118 | 3.8s |  |
| 35 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 36 | `NetConnection-v6` | 4 | 49 | 4.5s |  |
| 37 | `NetConnection-v7` | 4 | 45 | 4.5s |  |
| 38 | `NetConnection-v8` | 4 | 45 | 2.0s |  |
| 39 | `Object-v6` | 8 | 21 | 11.9s |  |
| 40 | `Object-v7` | 8 | 12 | 11.9s |  |
| 41 | `Object-v8` | 8 | 12 | 2.5s |  |
| 42 | `Sound-v5` | 14 | 16 | 4.7s |  |
| 43 | `Stage-v6` | 14 | 14 | 4.2s |  |
| 44 | `Stage-v7` | 14 | 14 | 3.9s |  |
| 45 | `Stage-v8` | 14 | 14 | 2.6s |  |
| 46 | `String-v5` | 14 | 21 | 17.8s |  |
| 47 | `TextField-v6` | 15 | 57 | 26.3s |  |
| 48 | `TextField-v7` | 15 | 73 | 28.2s |  |
| 49 | `TextField-v8` | 14 | 72 | 27.9s |  |
| 50 | `TextFormat-v7` | 38 | 38 | 10.3s |  |
| 51 | `TextFormat-v8` | 36 | 36 | 10.2s |  |
| 52 | `Transform-v8` | 7 | 7 | 4.5s |  |
| 53 | `XML-v5` | 9 | 79 | 30.1s |  |
| 54 | `XML-v8` | 21 | 116 | 4.3s |  |
| 55 | `array-v5` | 5 | 17 | 54.6s |  |
| 56 | `array-v6` | 6 | 25 | 37.3s |  |
| 57 | `array-v7` | 5 | 23 | 38.9s |  |
| 58 | `array-v8` | 5 | 23 | 4.8s |  |
| 59 | `setProperty-v5` | 49 | 49 | 3.0s |  |
| 60 | `setProperty-v6` | 49 | 49 | 3.0s |  |
| 61 | `setProperty-v7` | 49 | 49 | 2.7s |  |
| 62 | `setProperty-v8` | 49 | 49 | 1.9s |  |
| 63 | `toString_valueOf-v5` | 12 | 34 | 5.4s |  |

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
