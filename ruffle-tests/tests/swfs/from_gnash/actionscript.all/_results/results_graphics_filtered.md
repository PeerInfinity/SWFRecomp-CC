# Ruffle Test Results (Filtered)

**Date**: 2026-11-28 19:48 UTC

**Git SHA**: `ab18c4dff1`

**Run Duration**: 34m 19s

**Filtered**: 3 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 240 |
| Passing | **193** (80.4%) |
| Ruffle-matched | 47 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (100.0%) |
| Failing | 0 |
| Total expected lines | 32104 |
| Matching lines | 31149 (97.0%) |
| Mismatched lines | 955 |

## Passing Tests

**193 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.4s |  |
| 2 | `Accessibility-v6` | 19 | 3.5s |  |
| 3 | `Accessibility-v7` | 19 | 3.1s |  |
| 4 | `Accessibility-v8` | 19 | 2.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.3s |  |
| 6 | `AsBroadcaster-v6` | 121 | 32.0s |  |
| 7 | `AsBroadcaster-v7` | 121 | 6.5s |  |
| 8 | `AsBroadcaster-v8` | 121 | 3.0s |  |
| 9 | `BitmapData-v5` | 7 | 3.4s |  |
| 10 | `BitmapData-v6` | 7 | 1.7s |  |
| 11 | `BitmapData-v7` | 7 | 3.1s |  |
| 12 | `Boolean-v5` | 38 | 4.0s |  |
| 13 | `Boolean-v6` | 38 | 3.5s |  |
| 14 | `Boolean-v7` | 38 | 28.2s |  |
| 15 | `Boolean-v8` | 38 | 2.9s |  |
| 16 | `Camera-v5` | 7 | 3.4s |  |
| 17 | `Color-v5` | 140 | 7.4s |  |
| 18 | `Color-v6` | 171 | 8.7s |  |
| 19 | `Color-v7` | 161 | 8.2s |  |
| 20 | `Color-v8` | 161 | 25.2s |  |
| 21 | `ColorTransform-v5` | 7 | 2.7s |  |
| 22 | `ColorTransform-v6` | 7 | 1.3s |  |
| 23 | `ColorTransform-v7` | 7 | 2.5s |  |
| 24 | `ColorTransform-v8` | 55 | 3.8s |  |
| 25 | `ContextMenu-v5` | 7 | 2.7s |  |
| 26 | `ContextMenu-v6` | 7 | 1.3s |  |
| 27 | `ContextMenu-v7` | 131 | 5.2s |  |
| 28 | `ContextMenu-v8` | 131 | 19.8s |  |
| 29 | `Error-v5` | 28 | 2.6s |  |
| 30 | `Error-v6` | 31 | 2.6s |  |
| 31 | `Error-v7` | 31 | 2.4s |  |
| 32 | `Error-v8` | 31 | 20.8s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.8s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.2s |  |
| 35 | `ExternalInterface-v7` | 55 | 3.0s |  |
| 36 | `ExternalInterface-v8` | 118 | 5.2s |  |
| 37 | `Function-v6` | 271 | 8.9s |  |
| 38 | `Function-v7` | 272 | 9.3s |  |
| 39 | `Function-v8` | 272 | 36.2s |  |
| 40 | `Global-v5` | 172 | 9.0s |  |
| 41 | `Global-v6` | 210 | 10.6s |  |
| 42 | `Global-v7` | 182 | 9.2s |  |
| 43 | `Global-v8` | 169 | 8.7s |  |
| 44 | `HitTest-v6` | 88 | 6.7s |  |
| 45 | `HitTest-v7` | 88 | 6.4s |  |
| 46 | `Instance-v5` | 52 | 2.9s |  |
| 47 | `Instance-v6` | 52 | 1.8s |  |
| 48 | `Instance-v7` | 52 | 2.6s |  |
| 49 | `Instance-v8` | 52 | 1.8s |  |
| 50 | `Key-v5` | 51 | 27.4s |  |
| 51 | `Key-v6` | 55 | 4.3s |  |
| 52 | `Key-v7` | 55 | 3.9s |  |
| 53 | `Key-v8` | 55 | 2.8s |  |
| 54 | `LoadVars-v5` | 8 | 3.4s |  |
| 55 | `LoadVars-v6` | 152 | 7.0s |  |
| 56 | `LoadVars-v7` | 152 | 6.7s |  |
| 57 | `LoadVars-v8` | 152 | 3.7s |  |
| 58 | `LocalConnection-v5` | 7 | 17.5s |  |
| 59 | `LocalConnection-v6` | 58 | 2.9s |  |
| 60 | `LocalConnection-v7` | 58 | 2.7s |  |
| 61 | `LocalConnection-v8` | 58 | 1.8s |  |
| 62 | `Matrix-v5` | 7 | 21.0s |  |
| 63 | `Matrix-v6` | 168 | 6.5s |  |
| 64 | `Matrix-v7` | 168 | 6.5s |  |
| 65 | `Matrix-v8` | 168 | 2.0s |  |
| 66 | `Microphone-v5` | 6 | 2.2s |  |
| 67 | `Mouse-v5` | 13 | 27.1s |  |
| 68 | `Mouse-v6` | 21 | 3.6s |  |
| 69 | `Mouse-v7` | 21 | 3.3s |  |
| 70 | `Mouse-v8` | 21 | 2.8s |  |
| 71 | `MovieClip-v5` | 363 | 15.3s |  |
| 72 | `MovieClip-v6` | 936 | 53.5s |  |
| 73 | `MovieClip-v7` | 969 | 57.0s |  |
| 74 | `MovieClip-v8` | 1087 | 72.7s |  |
| 75 | `MovieClipLoader-v5` | 6 | 16.9s |  |
| 76 | `MovieClipLoader-v6` | 6 | 1.1s |  |
| 77 | `NetConnection-v5` | 7 | 2.2s |  |
| 78 | `NetStream-v5` | 6 | 20.5s |  |
| 79 | `NetStream-v6` | 80 | 4.3s |  |
| 80 | `NetStream-v7` | 80 | 3.8s |  |
| 81 | `NetStream-v8` | 80 | 2.2s |  |
| 82 | `Number-v5` | 244 | 9.0s |  |
| 83 | `Number-v6` | 239 | 9.0s |  |
| 84 | `Number-v7` | 237 | 9.0s |  |
| 85 | `Number-v8` | 237 | 2.4s |  |
| 86 | `Object-v5` | 145 | 25.7s |  |
| 87 | `Object-v6` | 333 | 13.3s |  |
| 88 | `Object-v7` | 333 | 13.7s |  |
| 89 | `Object-v8` | 333 | 3.0s |  |
| 90 | `Point-v5` | 7 | 2.8s |  |
| 91 | `Point-v6` | 7 | 1.4s |  |
| 92 | `Point-v7` | 7 | 2.6s |  |
| 93 | `Point-v8` | 193 | 9.1s |  |
| 94 | `Random-v5` | 30 | 21.7s |  |
| 95 | `Random-v6` | 30 | 1.2s |  |
| 96 | `Random-v7` | 30 | 2.5s |  |
| 97 | `Random-v8` | 30 | 1.9s |  |
| 98 | `Rectangle-v5` | 7 | 2.3s |  |
| 99 | `Rectangle-v6` | 7 | 1.1s |  |
| 100 | `Rectangle-v7` | 7 | 2.0s |  |
| 101 | `Rectangle-v8` | 166 | 6.4s |  |
| 102 | `Selection-v5` | 21 | 26.9s |  |
| 103 | `Selection-v6` | 125 | 6.5s |  |
| 104 | `Selection-v7` | 125 | 6.3s |  |
| 105 | `Selection-v8` | 125 | 2.6s |  |
| 106 | `Sound-v5` | 100 | 6.0s |  |
| 107 | `Sound-v6` | 121 | 6.7s |  |
| 108 | `Sound-v7` | 121 | 6.0s |  |
| 109 | `Sound-v8` | 121 | 2.9s |  |
| 110 | `Stage-v5` | 38 | 21.5s |  |
| 111 | `String-v6` | 377 | 15.1s |  |
| 112 | `String-v7` | 377 | 14.8s |  |
| 113 | `String-v8` | 377 | 2.2s |  |
| 114 | `System-v5` | 67 | 23.9s |  |
| 115 | `System-v6` | 100 | 4.9s |  |
| 116 | `System-v7` | 101 | 5.1s |  |
| 117 | `System-v8` | 101 | 2.3s |  |
| 118 | `TextField-v5` | 12 | 2.9s |  |
| 119 | `TextFieldHTML-v5` | 6 | 20.5s |  |
| 120 | `TextFieldHTML-v6` | 37 | 2.7s |  |
| 121 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 122 | `TextFieldHTML-v8` | 37 | 1.8s |  |
| 123 | `TextFormat-v5` | 128 | 4.3s |  |
| 124 | `TextFormat-v6` | 128 | 1.2s |  |
| 125 | `TextSnapshot-v5` | 7 | 25.7s |  |
| 126 | `TextSnapshot-v6` | 173 | 9.7s |  |
| 127 | `TextSnapshot-v7` | 173 | 9.5s |  |
| 128 | `TextSnapshot-v8` | 173 | 2.9s |  |
| 129 | `Transform-v5` | 7 | 3.2s |  |
| 130 | `Transform-v6` | 7 | 2.7s |  |
| 131 | `Transform-v7` | 7 | 2.9s |  |
| 132 | `Try-v5` | 20 | 21.2s |  |
| 133 | `Try-v6` | 20 | 1.1s |  |
| 134 | `Try-v7` | 20 | 2.8s |  |
| 135 | `Try-v8` | 20 | 1.8s |  |
| 136 | `Video-v5` | 7 | 2.3s |  |
| 137 | `Video-v6` | 85 | 3.4s |  |
| 138 | `Video-v7` | 85 | 3.1s |  |
| 139 | `Video-v8` | 85 | 1.9s |  |
| 140 | `XML-v6` | 486 | 14.9s |  |
| 141 | `XML-v7` | 486 | 14.5s |  |
| 142 | `XMLNode-v5` | 207 | 8.4s |  |
| 143 | `XMLNode-v6` | 207 | 8.3s |  |
| 144 | `XMLNode-v7` | 207 | 7.4s |  |
| 145 | `XMLNode-v8` | 207 | 2.2s |  |
| 146 | `XMLSocket-v5` | 35 | 22.1s |  |
| 147 | `XMLSocket-v6` | 35 | 3.0s |  |
| 148 | `XMLSocket-v7` | 35 | 2.7s |  |
| 149 | `XMLSocket-v8` | 35 | 2.1s |  |
| 150 | `argstest-v5` | 4 | 2.5s |  |
| 151 | `case-v5` | 39 | 4.5s |  |
| 152 | `case-v6` | 73 | 5.5s |  |
| 153 | `case-v7` | 67 | 5.3s |  |
| 154 | `case-v8` | 67 | 3.1s |  |
| 155 | `delete-v5` | 61 | 21.8s |  |
| 156 | `delete-v6` | 61 | 2.7s |  |
| 157 | `delete-v7` | 61 | 2.9s |  |
| 158 | `delete-v8` | 61 | 2.0s |  |
| 159 | `enumerate-v5` | 6 | 2.3s |  |
| 160 | `enumerate-v6` | 49 | 3.2s |  |
| 161 | `enumerate-v7` | 49 | 2.9s |  |
| 162 | `enumerate-v8` | 49 | 1.9s |  |
| 163 | `flash-v5` | 10 | 24.7s |  |
| 164 | `flash-v6` | 10 | 1.7s |  |
| 165 | `flash-v7` | 10 | 1.7s |  |
| 166 | `flash-v8` | 41 | 1.7s |  |
| 167 | `getvariable-v5` | 58 | 1.7s |  |
| 168 | `getvariable-v6` | 64 | 1.9s |  |
| 169 | `getvariable-v7` | 64 | 1.7s |  |
| 170 | `getvariable-v8` | 64 | 1.8s |  |
| 171 | `ops-v5` | 260 | 19.6s |  |
| 172 | `ops-v6` | 260 | 1.4s |  |
| 173 | `ops-v7` | 262 | 1.4s |  |
| 174 | `ops-v8` | 262 | 1.4s |  |
| 175 | `setProperty-v5` | 52 | 1.3s |  |
| 176 | `setProperty-v6` | 52 | 1.3s |  |
| 177 | `setProperty-v7` | 52 | 1.3s |  |
| 178 | `setProperty-v8` | 52 | 1.3s |  |
| 179 | `swap-v5` | 7 | 26.5s |  |
| 180 | `swap-v6` | 7 | 1.6s |  |
| 181 | `swap-v7` | 7 | 3.0s |  |
| 182 | `swap-v8` | 7 | 2.8s |  |
| 183 | `targetPath-v5` | 12 | 3.4s |  |
| 184 | `targetPath-v6` | 23 | 3.6s |  |
| 185 | `targetPath-v7` | 23 | 3.3s |  |
| 186 | `targetPath-v8` | 23 | 2.8s |  |
| 187 | `toString_valueOf-v6` | 155 | 5.2s |  |
| 188 | `toString_valueOf-v7` | 155 | 5.0s |  |
| 189 | `toString_valueOf-v8` | 155 | 2.0s |  |
| 190 | `with-v5` | 49 | 3.5s |  |
| 191 | `with-v6` | 107 | 4.5s |  |
| 192 | `with-v7` | 107 | 4.2s |  |
| 193 | `with-v8` | 107 | 2.1s |  |

## Ruffle-Matched Tests

**47 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 29.5s |  |
| 2 | `ASnative-v6` | 39 | 40 | 7.0s |  |
| 3 | `ASnative-v7` | 39 | 40 | 6.6s |  |
| 4 | `ASnative-v8` | 39 | 40 | 2.9s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 55.7s |  |
| 6 | `Camera-v6` | 57 | 57 | 5.9s |  |
| 7 | `Camera-v7` | 57 | 57 | 5.5s |  |
| 8 | `Camera-v8` | 57 | 57 | 3.0s |  |
| 9 | `Date-v5` | 6 | 7 | 11.8s |  |
| 10 | `Date-v6` | 6 | 6 | 12.9s |  |
| 11 | `Date-v7` | 6 | 6 | 13.4s |  |
| 12 | `Date-v8` | 6 | 6 | 2.3s |  |
| 13 | `Function-v5` | 4 | 25 | 5.7s |  |
| 14 | `HitTest-v8` | 3 | 9 | 6.3s |  |
| 15 | `Inheritance-v5` | 1 | 17 | 22.1s |  |
| 16 | `Inheritance-v6` | 9 | 13 | 5.4s |  |
| 17 | `Inheritance-v7` | 5 | 7 | 5.5s |  |
| 18 | `Inheritance-v8` | 5 | 7 | 2.2s |  |
| 19 | `Math-v5` | 5 | 5 | 11.2s |  |
| 20 | `Math-v6` | 5 | 5 | 1.2s |  |
| 21 | `Math-v7` | 5 | 5 | 12.0s |  |
| 22 | `Math-v8` | 5 | 5 | 2.1s |  |
| 23 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 24 | `Microphone-v7` | 31 | 31 | 3.2s |  |
| 25 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 26 | `MovieClipLoader-v7` | 118 | 118 | 3.4s |  |
| 27 | `MovieClipLoader-v8` | 118 | 118 | 2.6s |  |
| 28 | `NetConnection-v6` | 4 | 49 | 4.4s |  |
| 29 | `NetConnection-v7` | 4 | 45 | 4.7s |  |
| 30 | `NetConnection-v8` | 4 | 45 | 2.1s |  |
| 31 | `Stage-v6` | 14 | 14 | 3.2s |  |
| 32 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 33 | `Stage-v8` | 14 | 14 | 2.0s |  |
| 34 | `String-v5` | 8 | 21 | 14.3s |  |
| 35 | `TextField-v6` | 15 | 57 | 22.6s |  |
| 36 | `TextField-v7` | 15 | 73 | 24.2s |  |
| 37 | `TextField-v8` | 14 | 72 | 24.1s |  |
| 38 | `TextFormat-v7` | 38 | 38 | 5.6s |  |
| 39 | `TextFormat-v8` | 36 | 36 | 5.6s |  |
| 40 | `Transform-v8` | 7 | 7 | 6.5s |  |
| 41 | `XML-v5` | 9 | 79 | 32.6s |  |
| 42 | `XML-v8` | 21 | 116 | 4.7s |  |
| 43 | `array-v5` | 5 | 17 | 58.1s |  |
| 44 | `array-v6` | 6 | 25 | 38.6s |  |
| 45 | `array-v7` | 5 | 23 | 40.4s |  |
| 46 | `array-v8` | 5 | 23 | 5.2s |  |
| 47 | `toString_valueOf-v5` | 12 | 34 | 23.9s |  |

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
