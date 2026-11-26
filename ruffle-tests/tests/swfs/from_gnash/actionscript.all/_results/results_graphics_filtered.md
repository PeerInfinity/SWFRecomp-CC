# Ruffle Test Results (Filtered)

**Date**: 2026-11-26 20:41 UTC

**Git SHA**: `bfa47037b1`

**Run Duration**: 29m 32s

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
| 1 | `Accessibility-v5` | 15 | 3.2s |  |
| 2 | `Accessibility-v6` | 19 | 3.3s |  |
| 3 | `Accessibility-v7` | 19 | 3.0s |  |
| 4 | `Accessibility-v8` | 19 | 2.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.1s |  |
| 6 | `AsBroadcaster-v6` | 121 | 23.2s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.6s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.0s |  |
| 9 | `BitmapData-v5` | 7 | 2.4s |  |
| 10 | `BitmapData-v6` | 7 | 1.2s |  |
| 11 | `BitmapData-v7` | 7 | 2.0s |  |
| 12 | `Boolean-v5` | 38 | 2.7s |  |
| 13 | `Boolean-v6` | 38 | 2.3s |  |
| 14 | `Boolean-v7` | 38 | 23.1s |  |
| 15 | `Boolean-v8` | 38 | 2.6s |  |
| 16 | `Camera-v5` | 7 | 3.2s |  |
| 17 | `Color-v5` | 140 | 6.8s |  |
| 18 | `Color-v6` | 171 | 7.9s |  |
| 19 | `Color-v7` | 161 | 7.8s |  |
| 20 | `Color-v8` | 161 | 24.0s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 1.2s |  |
| 23 | `ColorTransform-v7` | 7 | 2.0s |  |
| 24 | `ColorTransform-v8` | 55 | 3.3s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 1.1s |  |
| 27 | `ContextMenu-v7` | 131 | 4.4s |  |
| 28 | `ContextMenu-v8` | 131 | 22.7s |  |
| 29 | `Error-v5` | 28 | 2.6s |  |
| 30 | `Error-v6` | 31 | 2.7s |  |
| 31 | `Error-v7` | 31 | 2.4s |  |
| 32 | `Error-v8` | 31 | 26.4s |  |
| 33 | `ExternalInterface-v5` | 7 | 3.3s |  |
| 34 | `ExternalInterface-v6` | 55 | 4.2s |  |
| 35 | `ExternalInterface-v7` | 55 | 3.9s |  |
| 36 | `Function-v6` | 271 | 11.1s |  |
| 37 | `Function-v7` | 272 | 11.4s |  |
| 38 | `Function-v8` | 272 | 26.0s |  |
| 39 | `Global-v5` | 172 | 6.0s |  |
| 40 | `Global-v6` | 210 | 7.2s |  |
| 41 | `Global-v7` | 182 | 6.3s |  |
| 42 | `Global-v8` | 169 | 5.8s |  |
| 43 | `HitTest-v6` | 88 | 4.4s |  |
| 44 | `HitTest-v7` | 88 | 4.2s |  |
| 45 | `Instance-v5` | 52 | 4.2s |  |
| 46 | `Instance-v6` | 52 | 2.6s |  |
| 47 | `Instance-v7` | 52 | 3.9s |  |
| 48 | `Instance-v8` | 52 | 2.8s |  |
| 49 | `Key-v5` | 51 | 4.0s |  |
| 50 | `Key-v6` | 55 | 4.0s |  |
| 51 | `Key-v7` | 55 | 3.7s |  |
| 52 | `Key-v8` | 55 | 2.6s |  |
| 53 | `LoadVars-v5` | 8 | 3.2s |  |
| 54 | `LocalConnection-v5` | 7 | 19.2s |  |
| 55 | `LocalConnection-v6` | 58 | 3.0s |  |
| 56 | `LocalConnection-v7` | 58 | 2.8s |  |
| 57 | `LocalConnection-v8` | 58 | 2.0s |  |
| 58 | `Matrix-v5` | 7 | 21.2s |  |
| 59 | `Matrix-v6` | 168 | 8.0s |  |
| 60 | `Matrix-v7` | 168 | 8.5s |  |
| 61 | `Matrix-v8` | 168 | 2.5s |  |
| 62 | `Microphone-v5` | 6 | 3.0s |  |
| 63 | `Mouse-v5` | 13 | 19.3s |  |
| 64 | `Mouse-v6` | 21 | 2.4s |  |
| 65 | `Mouse-v7` | 21 | 2.1s |  |
| 66 | `Mouse-v8` | 21 | 1.8s |  |
| 67 | `MovieClipLoader-v5` | 6 | 17.8s |  |
| 68 | `MovieClipLoader-v6` | 6 | 1.2s |  |
| 69 | `NetConnection-v5` | 7 | 2.3s |  |
| 70 | `NetStream-v5` | 6 | 2.5s |  |
| 71 | `NetStream-v6` | 80 | 4.2s |  |
| 72 | `NetStream-v7` | 80 | 3.8s |  |
| 73 | `NetStream-v8` | 80 | 2.1s |  |
| 74 | `Number-v5` | 244 | 9.0s |  |
| 75 | `Number-v6` | 239 | 8.8s |  |
| 76 | `Number-v7` | 237 | 9.0s |  |
| 77 | `Number-v8` | 237 | 2.3s |  |
| 78 | `Object-v5` | 145 | 28.5s |  |
| 79 | `Point-v5` | 7 | 3.1s |  |
| 80 | `Point-v6` | 7 | 1.5s |  |
| 81 | `Point-v7` | 7 | 2.7s |  |
| 82 | `Point-v8` | 193 | 9.5s |  |
| 83 | `Random-v5` | 30 | 3.8s |  |
| 84 | `Random-v6` | 30 | 1.6s |  |
| 85 | `Random-v7` | 30 | 3.4s |  |
| 86 | `Random-v8` | 30 | 2.7s |  |
| 87 | `Rectangle-v5` | 7 | 3.3s |  |
| 88 | `Rectangle-v6` | 7 | 1.6s |  |
| 89 | `Rectangle-v7` | 7 | 2.9s |  |
| 90 | `Rectangle-v8` | 166 | 8.1s |  |
| 91 | `Selection-v5` | 21 | 27.5s |  |
| 92 | `Selection-v6` | 125 | 7.3s |  |
| 93 | `Selection-v7` | 125 | 6.8s |  |
| 94 | `Selection-v8` | 125 | 3.1s |  |
| 95 | `Sound-v6` | 121 | 7.6s |  |
| 96 | `Sound-v7` | 121 | 6.9s |  |
| 97 | `Sound-v8` | 121 | 3.5s |  |
| 98 | `Stage-v5` | 38 | 21.6s |  |
| 99 | `String-v6` | 377 | 16.6s |  |
| 100 | `String-v7` | 377 | 16.3s |  |
| 101 | `String-v8` | 377 | 2.5s |  |
| 102 | `System-v5` | 67 | 20.7s |  |
| 103 | `System-v6` | 100 | 3.7s |  |
| 104 | `System-v7` | 101 | 3.7s |  |
| 105 | `System-v8` | 101 | 1.9s |  |
| 106 | `TextField-v5` | 12 | 2.3s |  |
| 107 | `TextFieldHTML-v5` | 6 | 2.9s |  |
| 108 | `TextFieldHTML-v6` | 37 | 2.7s |  |
| 109 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 110 | `TextFieldHTML-v8` | 37 | 1.8s |  |
| 111 | `TextFormat-v5` | 128 | 4.5s |  |
| 112 | `TextFormat-v6` | 128 | 1.2s |  |
| 113 | `TextSnapshot-v5` | 7 | 27.3s |  |
| 114 | `TextSnapshot-v6` | 173 | 9.0s |  |
| 115 | `TextSnapshot-v7` | 173 | 8.5s |  |
| 116 | `TextSnapshot-v8` | 173 | 2.7s |  |
| 117 | `Transform-v5` | 7 | 3.1s |  |
| 118 | `Transform-v6` | 7 | 2.5s |  |
| 119 | `Transform-v7` | 7 | 2.7s |  |
| 120 | `Try-v5` | 20 | 20.9s |  |
| 121 | `Try-v6` | 20 | 1.2s |  |
| 122 | `Try-v7` | 20 | 2.9s |  |
| 123 | `Try-v8` | 20 | 1.9s |  |
| 124 | `Video-v5` | 7 | 2.3s |  |
| 125 | `Video-v6` | 85 | 3.4s |  |
| 126 | `Video-v7` | 85 | 3.1s |  |
| 127 | `Video-v8` | 85 | 1.9s |  |
| 128 | `XML-v6` | 486 | 12.3s |  |
| 129 | `XML-v7` | 486 | 12.5s |  |
| 130 | `XMLNode-v5` | 207 | 7.1s |  |
| 131 | `XMLNode-v6` | 207 | 7.4s |  |
| 132 | `XMLNode-v7` | 207 | 6.3s |  |
| 133 | `XMLNode-v8` | 207 | 2.0s |  |
| 134 | `XMLSocket-v5` | 35 | 22.4s |  |
| 135 | `XMLSocket-v6` | 35 | 3.5s |  |
| 136 | `XMLSocket-v7` | 35 | 3.2s |  |
| 137 | `XMLSocket-v8` | 35 | 2.6s |  |
| 138 | `argstest-v5` | 4 | 3.0s |  |
| 139 | `case-v5` | 39 | 4.1s |  |
| 140 | `case-v6` | 73 | 5.0s |  |
| 141 | `case-v7` | 67 | 4.9s |  |
| 142 | `case-v8` | 67 | 2.9s |  |
| 143 | `delete-v5` | 61 | 27.9s |  |
| 144 | `delete-v6` | 61 | 4.1s |  |
| 145 | `delete-v7` | 61 | 4.3s |  |
| 146 | `delete-v8` | 61 | 3.1s |  |
| 147 | `enumerate-v5` | 6 | 3.4s |  |
| 148 | `enumerate-v6` | 49 | 4.5s |  |
| 149 | `enumerate-v7` | 49 | 4.2s |  |
| 150 | `enumerate-v8` | 49 | 2.9s |  |
| 151 | `flash-v5` | 10 | 2.1s |  |
| 152 | `flash-v6` | 10 | 2.1s |  |
| 153 | `flash-v7` | 10 | 1.9s |  |
| 154 | `flash-v8` | 41 | 2.6s |  |
| 155 | `getvariable-v5` | 58 | 2.9s |  |
| 156 | `getvariable-v6` | 64 | 3.0s |  |
| 157 | `getvariable-v7` | 64 | 3.0s |  |
| 158 | `getvariable-v8` | 64 | 1.9s |  |
| 159 | `ops-v5` | 260 | 8.1s |  |
| 160 | `ops-v6` | 260 | 7.5s |  |
| 161 | `ops-v7` | 262 | 8.1s |  |
| 162 | `ops-v8` | 262 | 1.9s |  |
| 163 | `swap-v5` | 7 | 3.0s |  |
| 164 | `swap-v6` | 7 | 1.4s |  |
| 165 | `swap-v7` | 7 | 2.9s |  |
| 166 | `swap-v8` | 7 | 2.3s |  |
| 167 | `targetPath-v5` | 12 | 2.8s |  |
| 168 | `targetPath-v6` | 23 | 3.4s |  |
| 169 | `targetPath-v7` | 23 | 2.8s |  |
| 170 | `targetPath-v8` | 23 | 2.6s |  |
| 171 | `toString_valueOf-v6` | 155 | 4.7s |  |
| 172 | `toString_valueOf-v7` | 155 | 4.3s |  |
| 173 | `toString_valueOf-v8` | 155 | 1.9s |  |
| 174 | `with-v5` | 49 | 3.3s |  |
| 175 | `with-v6` | 107 | 4.1s |  |
| 176 | `with-v7` | 107 | 3.9s |  |
| 177 | `with-v8` | 107 | 2.0s |  |

## Ruffle-Matched Tests

**63 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 30.1s |  |
| 2 | `ASnative-v6` | 39 | 40 | 7.0s |  |
| 3 | `ASnative-v7` | 39 | 40 | 6.6s |  |
| 4 | `ASnative-v8` | 39 | 40 | 2.8s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 21.0s |  |
| 6 | `Camera-v6` | 57 | 57 | 5.6s |  |
| 7 | `Camera-v7` | 57 | 57 | 4.8s |  |
| 8 | `Camera-v8` | 57 | 57 | 2.6s |  |
| 9 | `Date-v5` | 6 | 7 | 12.0s |  |
| 10 | `Date-v6` | 6 | 6 | 13.4s |  |
| 11 | `Date-v7` | 6 | 6 | 13.9s |  |
| 12 | `Date-v8` | 6 | 6 | 2.2s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 6.4s |  |
| 14 | `Function-v5` | 4 | 25 | 7.2s |  |
| 15 | `HitTest-v8` | 3 | 9 | 4.1s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 28.9s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 8.2s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 8.3s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 3.4s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 6.9s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 6.7s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 3.4s |  |
| 23 | `Math-v5` | 5 | 5 | 12.0s |  |
| 24 | `Math-v6` | 5 | 5 | 1.4s |  |
| 25 | `Math-v7` | 5 | 5 | 12.5s |  |
| 26 | `Math-v8` | 5 | 5 | 2.1s |  |
| 27 | `Microphone-v6` | 31 | 31 | 4.5s |  |
| 28 | `Microphone-v7` | 31 | 31 | 3.9s |  |
| 29 | `Microphone-v8` | 31 | 31 | 2.5s |  |
| 30 | `MovieClip-v5` | 10 | 226 | 11.4s |  |
| 31 | `MovieClip-v6` | 20 | 60 | 39.3s |  |
| 32 | `MovieClip-v7` | 20 | 64 | 40.9s |  |
| 33 | `MovieClip-v8` | 25 | 68 | 52.6s |  |
| 34 | `MovieClipLoader-v7` | 118 | 118 | 3.8s |  |
| 35 | `MovieClipLoader-v8` | 118 | 118 | 2.8s |  |
| 36 | `NetConnection-v6` | 4 | 49 | 4.9s |  |
| 37 | `NetConnection-v7` | 4 | 45 | 5.1s |  |
| 38 | `NetConnection-v8` | 4 | 45 | 2.1s |  |
| 39 | `Object-v6` | 8 | 21 | 14.3s |  |
| 40 | `Object-v7` | 8 | 12 | 14.8s |  |
| 41 | `Object-v8` | 8 | 12 | 3.4s |  |
| 42 | `Sound-v5` | 14 | 16 | 7.0s |  |
| 43 | `Stage-v6` | 14 | 14 | 3.8s |  |
| 44 | `Stage-v7` | 14 | 14 | 3.6s |  |
| 45 | `Stage-v8` | 14 | 14 | 2.4s |  |
| 46 | `String-v5` | 14 | 21 | 16.0s |  |
| 47 | `TextField-v6` | 15 | 57 | 18.3s |  |
| 48 | `TextField-v7` | 15 | 73 | 19.3s |  |
| 49 | `TextField-v8` | 14 | 72 | 19.3s |  |
| 50 | `TextFormat-v7` | 38 | 38 | 6.0s |  |
| 51 | `TextFormat-v8` | 36 | 36 | 5.9s |  |
| 52 | `Transform-v8` | 7 | 7 | 6.3s |  |
| 53 | `XML-v5` | 9 | 79 | 10.7s |  |
| 54 | `XML-v8` | 21 | 116 | 3.9s |  |
| 55 | `array-v5` | 5 | 17 | 31.1s |  |
| 56 | `array-v6` | 6 | 25 | 36.6s |  |
| 57 | `array-v7` | 5 | 23 | 38.4s |  |
| 58 | `array-v8` | 5 | 23 | 4.8s |  |
| 59 | `setProperty-v5` | 49 | 49 | 3.0s |  |
| 60 | `setProperty-v6` | 49 | 49 | 3.0s |  |
| 61 | `setProperty-v7` | 49 | 49 | 2.7s |  |
| 62 | `setProperty-v8` | 49 | 49 | 2.0s |  |
| 63 | `toString_valueOf-v5` | 12 | 34 | 4.9s |  |

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
