# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 06:45 UTC

**Git SHA**: `2d40d37996`

**Run Duration**: 22m 50s

**Filtered**: 3 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 232 |
| Passing | **177** (76.3%) |
| Ruffle-matched | 55 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **232** (100.0%) |
| Failing | 0 |
| Total expected lines | 30793 |
| Matching lines | 29603 (96.1%) |
| Mismatched lines | 1190 |

## Passing Tests

**177 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.4s |  |
| 2 | `Accessibility-v6` | 19 | 2.4s |  |
| 3 | `Accessibility-v7` | 19 | 2.1s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.3s |  |
| 6 | `AsBroadcaster-v6` | 121 | 4.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.1s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.9s |  |
| 9 | `BitmapData-v5` | 7 | 2.2s |  |
| 10 | `BitmapData-v6` | 7 | 1.1s |  |
| 11 | `BitmapData-v7` | 7 | 1.9s |  |
| 12 | `Boolean-v5` | 38 | 2.6s |  |
| 13 | `Boolean-v6` | 38 | 2.2s |  |
| 14 | `Boolean-v7` | 38 | 2.7s |  |
| 15 | `Boolean-v8` | 38 | 1.9s |  |
| 16 | `Camera-v5` | 7 | 2.2s |  |
| 17 | `Color-v5` | 140 | 4.9s |  |
| 18 | `Color-v6` | 171 | 5.7s |  |
| 19 | `Color-v7` | 161 | 5.5s |  |
| 20 | `Color-v8` | 161 | 6.8s |  |
| 21 | `ColorTransform-v5` | 7 | 3.1s |  |
| 22 | `ColorTransform-v6` | 7 | 1.4s |  |
| 23 | `ColorTransform-v7` | 7 | 2.5s |  |
| 24 | `ColorTransform-v8` | 55 | 3.9s |  |
| 25 | `ContextMenu-v5` | 7 | 2.8s |  |
| 26 | `ContextMenu-v6` | 7 | 1.4s |  |
| 27 | `ContextMenu-v7` | 131 | 5.6s |  |
| 28 | `ContextMenu-v8` | 131 | 4.3s |  |
| 29 | `Error-v5` | 28 | 2.6s |  |
| 30 | `Error-v6` | 31 | 2.6s |  |
| 31 | `Error-v7` | 31 | 2.3s |  |
| 32 | `Error-v8` | 31 | 26.8s |  |
| 33 | `ExternalInterface-v5` | 7 | 3.4s |  |
| 34 | `ExternalInterface-v6` | 55 | 4.3s |  |
| 35 | `ExternalInterface-v7` | 55 | 3.9s |  |
| 36 | `Function-v6` | 271 | 11.1s |  |
| 37 | `Function-v7` | 272 | 11.4s |  |
| 38 | `Function-v8` | 272 | 7.7s |  |
| 39 | `Global-v5` | 172 | 5.6s |  |
| 40 | `Global-v6` | 210 | 6.6s |  |
| 41 | `Global-v7` | 182 | 5.8s |  |
| 42 | `Global-v8` | 169 | 5.4s |  |
| 43 | `HitTest-v6` | 88 | 4.3s |  |
| 44 | `HitTest-v7` | 88 | 4.0s |  |
| 45 | `Instance-v5` | 52 | 4.0s |  |
| 46 | `Instance-v6` | 52 | 2.5s |  |
| 47 | `Instance-v7` | 52 | 3.7s |  |
| 48 | `Instance-v8` | 52 | 2.6s |  |
| 49 | `Key-v5` | 51 | 2.9s |  |
| 50 | `Key-v6` | 55 | 2.9s |  |
| 51 | `Key-v7` | 55 | 2.6s |  |
| 52 | `Key-v8` | 55 | 1.8s |  |
| 53 | `LoadVars-v5` | 8 | 2.2s |  |
| 54 | `Matrix-v5` | 7 | 2.2s |  |
| 55 | `Matrix-v6` | 168 | 5.8s |  |
| 56 | `Matrix-v7` | 168 | 5.8s |  |
| 57 | `Matrix-v8` | 168 | 1.9s |  |
| 58 | `Microphone-v5` | 6 | 2.1s |  |
| 59 | `Mouse-v5` | 13 | 2.3s |  |
| 60 | `Mouse-v6` | 21 | 2.4s |  |
| 61 | `Mouse-v7` | 21 | 2.1s |  |
| 62 | `Mouse-v8` | 21 | 1.9s |  |
| 63 | `MovieClip-v5` | 363 | 11.5s |  |
| 64 | `MovieClip-v6` | 936 | 37.4s |  |
| 65 | `MovieClip-v7` | 969 | 39.4s |  |
| 66 | `MovieClip-v8` | 1087 | 47.4s |  |
| 67 | `MovieClipLoader-v5` | 6 | 2.3s |  |
| 68 | `MovieClipLoader-v6` | 6 | 1.1s |  |
| 69 | `NetConnection-v5` | 7 | 2.2s |  |
| 70 | `NetStream-v5` | 6 | 19.7s |  |
| 71 | `NetStream-v6` | 80 | 3.3s |  |
| 72 | `NetStream-v7` | 80 | 3.1s |  |
| 73 | `NetStream-v8` | 80 | 1.8s |  |
| 74 | `Number-v5` | 244 | 7.0s |  |
| 75 | `Number-v6` | 239 | 6.9s |  |
| 76 | `Number-v7` | 237 | 6.8s |  |
| 77 | `Number-v8` | 237 | 1.9s |  |
| 78 | `Object-v5` | 145 | 6.3s |  |
| 79 | `Point-v5` | 7 | 2.8s |  |
| 80 | `Point-v6` | 7 | 1.4s |  |
| 81 | `Point-v7` | 7 | 2.5s |  |
| 82 | `Point-v8` | 193 | 8.6s |  |
| 83 | `Random-v5` | 30 | 3.8s |  |
| 84 | `Random-v6` | 30 | 1.6s |  |
| 85 | `Random-v7` | 30 | 3.4s |  |
| 86 | `Random-v8` | 30 | 2.7s |  |
| 87 | `Rectangle-v5` | 7 | 3.3s |  |
| 88 | `Rectangle-v6` | 7 | 1.6s |  |
| 89 | `Rectangle-v7` | 7 | 2.9s |  |
| 90 | `Rectangle-v8` | 166 | 8.1s |  |
| 91 | `Selection-v5` | 21 | 2.4s |  |
| 92 | `Selection-v6` | 125 | 4.6s |  |
| 93 | `Selection-v7` | 125 | 4.4s |  |
| 94 | `Selection-v8` | 125 | 1.9s |  |
| 95 | `Sound-v6` | 121 | 4.9s |  |
| 96 | `Sound-v7` | 121 | 4.4s |  |
| 97 | `Sound-v8` | 121 | 2.2s |  |
| 98 | `Stage-v5` | 38 | 3.9s |  |
| 99 | `String-v6` | 377 | 18.9s |  |
| 100 | `String-v7` | 377 | 18.5s |  |
| 101 | `String-v8` | 377 | 3.3s |  |
| 102 | `System-v5` | 67 | 3.3s |  |
| 103 | `System-v6` | 100 | 3.8s |  |
| 104 | `System-v7` | 101 | 4.0s |  |
| 105 | `System-v8` | 101 | 1.9s |  |
| 106 | `TextField-v5` | 12 | 2.4s |  |
| 107 | `TextFieldHTML-v5` | 6 | 2.8s |  |
| 108 | `TextFieldHTML-v6` | 37 | 3.3s |  |
| 109 | `TextFieldHTML-v7` | 37 | 3.0s |  |
| 110 | `TextFieldHTML-v8` | 37 | 2.3s |  |
| 111 | `TextFormat-v5` | 128 | 5.5s |  |
| 112 | `TextFormat-v6` | 128 | 1.4s |  |
| 113 | `TextSnapshot-v5` | 7 | 21.6s |  |
| 114 | `TextSnapshot-v6` | 173 | 8.2s |  |
| 115 | `TextSnapshot-v7` | 173 | 8.0s |  |
| 116 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 117 | `Transform-v5` | 7 | 2.8s |  |
| 118 | `Transform-v6` | 7 | 2.4s |  |
| 119 | `Transform-v7` | 7 | 2.5s |  |
| 120 | `Try-v5` | 20 | 3.1s |  |
| 121 | `Try-v6` | 20 | 1.1s |  |
| 122 | `Try-v7` | 20 | 2.8s |  |
| 123 | `Try-v8` | 20 | 1.9s |  |
| 124 | `Video-v5` | 7 | 2.3s |  |
| 125 | `Video-v6` | 85 | 3.5s |  |
| 126 | `Video-v7` | 85 | 3.2s |  |
| 127 | `Video-v8` | 85 | 1.9s |  |
| 128 | `XML-v6` | 486 | 13.1s |  |
| 129 | `XML-v7` | 486 | 13.1s |  |
| 130 | `XMLNode-v5` | 207 | 7.2s |  |
| 131 | `XMLNode-v6` | 207 | 7.4s |  |
| 132 | `XMLNode-v7` | 207 | 6.8s |  |
| 133 | `XMLNode-v8` | 207 | 2.0s |  |
| 134 | `XMLSocket-v5` | 35 | 20.9s |  |
| 135 | `XMLSocket-v6` | 35 | 2.8s |  |
| 136 | `XMLSocket-v7` | 35 | 2.5s |  |
| 137 | `XMLSocket-v8` | 35 | 2.0s |  |
| 138 | `argstest-v5` | 4 | 2.4s |  |
| 139 | `case-v5` | 39 | 4.3s |  |
| 140 | `case-v6` | 73 | 5.1s |  |
| 141 | `case-v7` | 67 | 5.4s |  |
| 142 | `case-v8` | 67 | 3.2s |  |
| 143 | `delete-v5` | 61 | 3.2s |  |
| 144 | `delete-v6` | 61 | 2.8s |  |
| 145 | `delete-v7` | 61 | 2.9s |  |
| 146 | `delete-v8` | 61 | 2.0s |  |
| 147 | `enumerate-v5` | 6 | 2.3s |  |
| 148 | `enumerate-v6` | 49 | 3.1s |  |
| 149 | `enumerate-v7` | 49 | 2.9s |  |
| 150 | `enumerate-v8` | 49 | 1.9s |  |
| 151 | `flash-v5` | 10 | 20.3s |  |
| 152 | `flash-v6` | 10 | 2.3s |  |
| 153 | `flash-v7` | 10 | 2.1s |  |
| 154 | `flash-v8` | 41 | 3.0s |  |
| 155 | `getvariable-v5` | 58 | 3.2s |  |
| 156 | `getvariable-v6` | 64 | 3.3s |  |
| 157 | `getvariable-v7` | 64 | 3.4s |  |
| 158 | `getvariable-v8` | 64 | 1.9s |  |
| 159 | `ops-v5` | 260 | 9.6s |  |
| 160 | `ops-v6` | 260 | 8.9s |  |
| 161 | `ops-v7` | 262 | 9.4s |  |
| 162 | `ops-v8` | 262 | 2.1s |  |
| 163 | `swap-v5` | 7 | 3.5s |  |
| 164 | `swap-v6` | 7 | 1.7s |  |
| 165 | `swap-v7` | 7 | 3.1s |  |
| 166 | `swap-v8` | 7 | 2.8s |  |
| 167 | `targetPath-v5` | 12 | 3.6s |  |
| 168 | `targetPath-v6` | 23 | 3.9s |  |
| 169 | `targetPath-v7` | 23 | 3.4s |  |
| 170 | `targetPath-v8` | 23 | 2.9s |  |
| 171 | `toString_valueOf-v6` | 155 | 4.7s |  |
| 172 | `toString_valueOf-v7` | 155 | 4.4s |  |
| 173 | `toString_valueOf-v8` | 155 | 1.9s |  |
| 174 | `with-v5` | 49 | 3.4s |  |
| 175 | `with-v6` | 107 | 4.2s |  |
| 176 | `with-v7` | 107 | 4.1s |  |
| 177 | `with-v8` | 107 | 2.1s |  |

## Ruffle-Matched Tests

**55 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 5.0s |  |
| 2 | `ASnative-v6` | 39 | 40 | 5.0s |  |
| 3 | `ASnative-v7` | 39 | 40 | 4.7s |  |
| 4 | `ASnative-v8` | 39 | 40 | 2.0s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 20.0s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.8s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.6s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.9s |  |
| 9 | `Date-v5` | 6 | 7 | 11.5s |  |
| 10 | `Date-v6` | 6 | 6 | 12.9s |  |
| 11 | `Date-v7` | 6 | 6 | 13.1s |  |
| 12 | `Date-v8` | 6 | 6 | 2.1s |  |
| 13 | `ExternalInterface-v8` | 3 | 4 | 6.5s |  |
| 14 | `Function-v5` | 4 | 25 | 7.3s |  |
| 15 | `HitTest-v8` | 3 | 9 | 3.9s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 5.8s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 7.8s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 8.1s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 3.1s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 4.8s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 4.5s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 2.5s |  |
| 23 | `Microphone-v6` | 31 | 31 | 3.3s |  |
| 24 | `Microphone-v7` | 31 | 31 | 3.0s |  |
| 25 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 26 | `MovieClipLoader-v7` | 118 | 118 | 3.8s |  |
| 27 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 28 | `NetConnection-v6` | 4 | 49 | 4.3s |  |
| 29 | `NetConnection-v7` | 4 | 45 | 4.4s |  |
| 30 | `NetConnection-v8` | 4 | 45 | 1.9s |  |
| 31 | `Object-v6` | 8 | 21 | 13.1s |  |
| 32 | `Object-v7` | 8 | 12 | 13.3s |  |
| 33 | `Object-v8` | 8 | 12 | 3.0s |  |
| 34 | `Sound-v5` | 14 | 16 | 4.5s |  |
| 35 | `Stage-v6` | 14 | 14 | 4.5s |  |
| 36 | `Stage-v7` | 14 | 14 | 4.1s |  |
| 37 | `Stage-v8` | 14 | 14 | 2.9s |  |
| 38 | `String-v5` | 8 | 21 | 17.9s |  |
| 39 | `TextField-v6` | 15 | 57 | 19.6s |  |
| 40 | `TextField-v7` | 15 | 73 | 21.0s |  |
| 41 | `TextField-v8` | 14 | 72 | 20.8s |  |
| 42 | `TextFormat-v7` | 38 | 38 | 7.2s |  |
| 43 | `TextFormat-v8` | 36 | 36 | 7.2s |  |
| 44 | `Transform-v8` | 7 | 7 | 5.7s |  |
| 45 | `XML-v5` | 9 | 79 | 11.8s |  |
| 46 | `XML-v8` | 21 | 116 | 4.2s |  |
| 47 | `array-v5` | 5 | 17 | 32.6s |  |
| 48 | `array-v6` | 6 | 25 | 38.2s |  |
| 49 | `array-v7` | 5 | 23 | 40.7s |  |
| 50 | `array-v8` | 5 | 23 | 5.2s |  |
| 51 | `setProperty-v5` | 49 | 49 | 3.2s |  |
| 52 | `setProperty-v6` | 49 | 49 | 3.2s |  |
| 53 | `setProperty-v7` | 49 | 49 | 3.0s |  |
| 54 | `setProperty-v8` | 49 | 49 | 2.2s |  |
| 55 | `toString_valueOf-v5` | 12 | 34 | 5.0s |  |

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
