# Ruffle Test Results (Filtered)

**Date**: 2026-11-28 07:02 UTC

**Git SHA**: `3dfab12779`

**Run Duration**: 25m 60s

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
| 1 | `Accessibility-v5` | 15 | 2.5s |  |
| 2 | `Accessibility-v6` | 19 | 2.6s |  |
| 3 | `Accessibility-v7` | 19 | 2.3s |  |
| 4 | `Accessibility-v8` | 19 | 2.0s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.5s |  |
| 6 | `AsBroadcaster-v6` | 121 | 23.1s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.3s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.0s |  |
| 9 | `BitmapData-v5` | 7 | 2.3s |  |
| 10 | `BitmapData-v6` | 7 | 1.1s |  |
| 11 | `BitmapData-v7` | 7 | 2.0s |  |
| 12 | `Boolean-v5` | 38 | 2.7s |  |
| 13 | `Boolean-v6` | 38 | 2.3s |  |
| 14 | `Boolean-v7` | 38 | 2.6s |  |
| 15 | `Boolean-v8` | 38 | 1.8s |  |
| 16 | `Camera-v5` | 7 | 2.2s |  |
| 17 | `Color-v5` | 140 | 4.8s |  |
| 18 | `Color-v6` | 171 | 5.6s |  |
| 19 | `Color-v7` | 161 | 5.3s |  |
| 20 | `Color-v8` | 161 | 5.8s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 1.1s |  |
| 23 | `ColorTransform-v7` | 7 | 2.0s |  |
| 24 | `ColorTransform-v8` | 55 | 3.3s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 1.1s |  |
| 27 | `ContextMenu-v7` | 131 | 4.4s |  |
| 28 | `ContextMenu-v8` | 131 | 25.7s |  |
| 29 | `Error-v5` | 28 | 3.4s |  |
| 30 | `Error-v6` | 31 | 3.4s |  |
| 31 | `Error-v7` | 31 | 3.0s |  |
| 32 | `Error-v8` | 31 | 21.1s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.3s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.9s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `ExternalInterface-v8` | 118 | 4.5s |  |
| 37 | `Function-v6` | 271 | 8.5s |  |
| 38 | `Function-v7` | 272 | 8.7s |  |
| 39 | `Function-v8` | 272 | 8.0s |  |
| 40 | `Global-v5` | 172 | 5.9s |  |
| 41 | `Global-v6` | 210 | 7.1s |  |
| 42 | `Global-v7` | 182 | 6.2s |  |
| 43 | `Global-v8` | 169 | 5.5s |  |
| 44 | `HitTest-v6` | 88 | 4.3s |  |
| 45 | `HitTest-v7` | 88 | 4.1s |  |
| 46 | `Instance-v5` | 52 | 3.0s |  |
| 47 | `Instance-v6` | 52 | 1.9s |  |
| 48 | `Instance-v7` | 52 | 2.8s |  |
| 49 | `Instance-v8` | 52 | 1.9s |  |
| 50 | `Key-v5` | 51 | 2.9s |  |
| 51 | `Key-v6` | 55 | 2.9s |  |
| 52 | `Key-v7` | 55 | 2.6s |  |
| 53 | `Key-v8` | 55 | 1.8s |  |
| 54 | `LoadVars-v5` | 8 | 2.2s |  |
| 55 | `LoadVars-v6` | 152 | 4.7s |  |
| 56 | `LoadVars-v7` | 152 | 4.5s |  |
| 57 | `LoadVars-v8` | 152 | 2.5s |  |
| 58 | `LocalConnection-v5` | 7 | 18.5s |  |
| 59 | `LocalConnection-v6` | 58 | 3.8s |  |
| 60 | `LocalConnection-v7` | 58 | 3.5s |  |
| 61 | `LocalConnection-v8` | 58 | 2.7s |  |
| 62 | `Matrix-v5` | 7 | 3.4s |  |
| 63 | `Matrix-v6` | 168 | 8.9s |  |
| 64 | `Matrix-v7` | 168 | 9.0s |  |
| 65 | `Matrix-v8` | 168 | 3.0s |  |
| 66 | `Microphone-v5` | 6 | 3.3s |  |
| 67 | `Mouse-v5` | 13 | 23.2s |  |
| 68 | `Mouse-v6` | 21 | 3.2s |  |
| 69 | `Mouse-v7` | 21 | 3.1s |  |
| 70 | `Mouse-v8` | 21 | 2.5s |  |
| 71 | `MovieClip-v5` | 363 | 14.5s |  |
| 72 | `MovieClip-v6` | 936 | 45.8s |  |
| 73 | `MovieClip-v7` | 969 | 48.4s |  |
| 74 | `MovieClip-v8` | 1087 | 59.6s |  |
| 75 | `MovieClipLoader-v5` | 6 | 2.4s |  |
| 76 | `MovieClipLoader-v6` | 6 | 1.2s |  |
| 77 | `NetConnection-v5` | 7 | 2.3s |  |
| 78 | `NetStream-v5` | 6 | 2.3s |  |
| 79 | `NetStream-v6` | 80 | 3.7s |  |
| 80 | `NetStream-v7` | 80 | 3.5s |  |
| 81 | `NetStream-v8` | 80 | 2.0s |  |
| 82 | `Number-v5` | 244 | 8.6s |  |
| 83 | `Number-v6` | 239 | 8.5s |  |
| 84 | `Number-v7` | 237 | 8.6s |  |
| 85 | `Number-v8` | 237 | 2.1s |  |
| 86 | `Object-v5` | 145 | 21.7s |  |
| 87 | `Object-v6` | 333 | 10.9s |  |
| 88 | `Object-v7` | 333 | 10.8s |  |
| 89 | `Object-v8` | 333 | 2.5s |  |
| 90 | `Point-v5` | 7 | 2.3s |  |
| 91 | `Point-v6` | 7 | 1.1s |  |
| 92 | `Point-v7` | 7 | 2.0s |  |
| 93 | `Point-v8` | 193 | 6.8s |  |
| 94 | `Random-v5` | 30 | 24.1s |  |
| 95 | `Random-v6` | 30 | 1.5s |  |
| 96 | `Random-v7` | 30 | 3.2s |  |
| 97 | `Random-v8` | 30 | 2.4s |  |
| 98 | `Rectangle-v5` | 7 | 3.0s |  |
| 99 | `Rectangle-v6` | 7 | 1.4s |  |
| 100 | `Rectangle-v7` | 7 | 2.6s |  |
| 101 | `Rectangle-v8` | 166 | 7.6s |  |
| 102 | `Selection-v5` | 21 | 20.1s |  |
| 103 | `Selection-v6` | 125 | 4.3s |  |
| 104 | `Selection-v7` | 125 | 4.1s |  |
| 105 | `Selection-v8` | 125 | 1.8s |  |
| 106 | `Sound-v5` | 100 | 4.3s |  |
| 107 | `Sound-v6` | 121 | 4.7s |  |
| 108 | `Sound-v7` | 121 | 4.2s |  |
| 109 | `Sound-v8` | 121 | 2.1s |  |
| 110 | `Stage-v5` | 38 | 2.9s |  |
| 111 | `String-v6` | 377 | 15.2s |  |
| 112 | `String-v7` | 377 | 14.9s |  |
| 113 | `String-v8` | 377 | 2.3s |  |
| 114 | `System-v5` | 67 | 3.2s |  |
| 115 | `System-v6` | 100 | 3.8s |  |
| 116 | `System-v7` | 101 | 3.9s |  |
| 117 | `System-v8` | 101 | 1.9s |  |
| 118 | `TextField-v5` | 12 | 2.3s |  |
| 119 | `TextFieldHTML-v5` | 6 | 2.2s |  |
| 120 | `TextFieldHTML-v6` | 37 | 2.8s |  |
| 121 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 122 | `TextFieldHTML-v8` | 37 | 1.8s |  |
| 123 | `TextFormat-v5` | 128 | 4.5s |  |
| 124 | `TextFormat-v6` | 128 | 1.2s |  |
| 125 | `TextSnapshot-v5` | 7 | 21.6s |  |
| 126 | `TextSnapshot-v6` | 173 | 7.2s |  |
| 127 | `TextSnapshot-v7` | 173 | 6.9s |  |
| 128 | `TextSnapshot-v8` | 173 | 2.0s |  |
| 129 | `Transform-v5` | 7 | 2.3s |  |
| 130 | `Transform-v6` | 7 | 1.9s |  |
| 131 | `Transform-v7` | 7 | 2.0s |  |
| 132 | `Try-v5` | 20 | 3.1s |  |
| 133 | `Try-v6` | 20 | 1.2s |  |
| 134 | `Try-v7` | 20 | 2.9s |  |
| 135 | `Try-v8` | 20 | 1.9s |  |
| 136 | `Video-v5` | 7 | 2.4s |  |
| 137 | `Video-v6` | 85 | 3.6s |  |
| 138 | `Video-v7` | 85 | 3.3s |  |
| 139 | `Video-v8` | 85 | 2.0s |  |
| 140 | `XML-v6` | 486 | 17.9s |  |
| 141 | `XML-v7` | 486 | 17.4s |  |
| 142 | `XMLNode-v5` | 207 | 10.3s |  |
| 143 | `XMLNode-v6` | 207 | 10.4s |  |
| 144 | `XMLNode-v7` | 207 | 9.0s |  |
| 145 | `XMLNode-v8` | 207 | 3.1s |  |
| 146 | `XMLSocket-v5` | 35 | 2.9s |  |
| 147 | `XMLSocket-v6` | 35 | 2.9s |  |
| 148 | `XMLSocket-v7` | 35 | 2.6s |  |
| 149 | `XMLSocket-v8` | 35 | 2.0s |  |
| 150 | `argstest-v5` | 4 | 2.5s |  |
| 151 | `case-v5` | 39 | 2.7s |  |
| 152 | `case-v6` | 73 | 3.3s |  |
| 153 | `case-v7` | 67 | 3.2s |  |
| 154 | `case-v8` | 67 | 1.9s |  |
| 155 | `delete-v5` | 61 | 21.1s |  |
| 156 | `delete-v6` | 61 | 2.7s |  |
| 157 | `delete-v7` | 61 | 2.8s |  |
| 158 | `delete-v8` | 61 | 2.0s |  |
| 159 | `enumerate-v5` | 6 | 2.2s |  |
| 160 | `enumerate-v6` | 49 | 3.0s |  |
| 161 | `enumerate-v7` | 49 | 2.8s |  |
| 162 | `enumerate-v8` | 49 | 1.9s |  |
| 163 | `flash-v5` | 10 | 1.1s |  |
| 164 | `flash-v6` | 10 | 1.0s |  |
| 165 | `flash-v7` | 10 | 1.0s |  |
| 166 | `flash-v8` | 41 | 1.0s |  |
| 167 | `getvariable-v5` | 58 | 1.1s |  |
| 168 | `getvariable-v6` | 64 | 1.0s |  |
| 169 | `getvariable-v7` | 64 | 1.4s |  |
| 170 | `getvariable-v8` | 64 | 1.0s |  |
| 171 | `ops-v5` | 260 | 25.1s |  |
| 172 | `ops-v6` | 260 | 6.9s |  |
| 173 | `ops-v7` | 262 | 7.3s |  |
| 174 | `ops-v8` | 262 | 1.6s |  |
| 175 | `setProperty-v5` | 52 | 2.6s |  |
| 176 | `setProperty-v6` | 52 | 2.6s |  |
| 177 | `setProperty-v7` | 52 | 2.3s |  |
| 178 | `setProperty-v8` | 52 | 1.6s |  |
| 179 | `swap-v5` | 7 | 2.2s |  |
| 180 | `swap-v6` | 7 | 1.1s |  |
| 181 | `swap-v7` | 7 | 1.9s |  |
| 182 | `swap-v8` | 7 | 1.8s |  |
| 183 | `targetPath-v5` | 12 | 2.2s |  |
| 184 | `targetPath-v6` | 23 | 2.4s |  |
| 185 | `targetPath-v7` | 23 | 2.1s |  |
| 186 | `targetPath-v8` | 23 | 1.8s |  |
| 187 | `toString_valueOf-v6` | 155 | 7.8s |  |
| 188 | `toString_valueOf-v7` | 155 | 7.5s |  |
| 189 | `toString_valueOf-v8` | 155 | 3.2s |  |
| 190 | `with-v5` | 49 | 5.4s |  |
| 191 | `with-v6` | 107 | 6.7s |  |
| 192 | `with-v7` | 107 | 6.5s |  |
| 193 | `with-v8` | 107 | 3.3s |  |

## Ruffle-Matched Tests

**47 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 25.1s |  |
| 2 | `ASnative-v6` | 39 | 40 | 5.6s |  |
| 3 | `ASnative-v7` | 39 | 40 | 5.3s |  |
| 4 | `ASnative-v8` | 39 | 40 | 2.1s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 39.9s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.7s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.5s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.9s |  |
| 9 | `Date-v5` | 6 | 7 | 14.3s |  |
| 10 | `Date-v6` | 6 | 6 | 16.0s |  |
| 11 | `Date-v7` | 6 | 6 | 16.6s |  |
| 12 | `Date-v8` | 6 | 6 | 3.0s |  |
| 13 | `Function-v5` | 4 | 25 | 5.1s |  |
| 14 | `HitTest-v8` | 3 | 9 | 4.0s |  |
| 15 | `Inheritance-v5` | 1 | 17 | 4.4s |  |
| 16 | `Inheritance-v6` | 9 | 13 | 6.1s |  |
| 17 | `Inheritance-v7` | 5 | 7 | 6.3s |  |
| 18 | `Inheritance-v8` | 5 | 7 | 2.4s |  |
| 19 | `Math-v5` | 5 | 5 | 12.9s |  |
| 20 | `Math-v6` | 5 | 5 | 1.7s |  |
| 21 | `Math-v7` | 5 | 5 | 13.3s |  |
| 22 | `Math-v8` | 5 | 5 | 2.5s |  |
| 23 | `Microphone-v6` | 31 | 31 | 5.0s |  |
| 24 | `Microphone-v7` | 31 | 31 | 4.6s |  |
| 25 | `Microphone-v8` | 31 | 31 | 2.9s |  |
| 26 | `MovieClipLoader-v7` | 118 | 118 | 4.0s |  |
| 27 | `MovieClipLoader-v8` | 118 | 118 | 2.8s |  |
| 28 | `NetConnection-v6` | 4 | 49 | 4.9s |  |
| 29 | `NetConnection-v7` | 4 | 45 | 5.0s |  |
| 30 | `NetConnection-v8` | 4 | 45 | 2.1s |  |
| 31 | `Stage-v6` | 14 | 14 | 3.2s |  |
| 32 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 33 | `Stage-v8` | 14 | 14 | 2.0s |  |
| 34 | `String-v5` | 8 | 21 | 14.5s |  |
| 35 | `TextField-v6` | 15 | 57 | 19.6s |  |
| 36 | `TextField-v7` | 15 | 73 | 20.8s |  |
| 37 | `TextField-v8` | 14 | 72 | 20.1s |  |
| 38 | `TextFormat-v7` | 38 | 38 | 5.9s |  |
| 39 | `TextFormat-v8` | 36 | 36 | 6.0s |  |
| 40 | `Transform-v8` | 7 | 7 | 4.7s |  |
| 41 | `XML-v5` | 9 | 79 | 39.2s |  |
| 42 | `XML-v8` | 21 | 116 | 6.2s |  |
| 43 | `array-v5` | 5 | 17 | 22.6s |  |
| 44 | `array-v6` | 6 | 25 | 26.9s |  |
| 45 | `array-v7` | 5 | 23 | 27.8s |  |
| 46 | `array-v8` | 5 | 23 | 3.1s |  |
| 47 | `toString_valueOf-v5` | 12 | 34 | 8.3s |  |

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
