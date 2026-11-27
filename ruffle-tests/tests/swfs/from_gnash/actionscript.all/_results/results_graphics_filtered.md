# Ruffle Test Results (Filtered)

**Date**: 2026-11-27 01:51 UTC

**Git SHA**: `6ee6eded7b`

**Run Duration**: 30m 44s

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
| 1 | `Accessibility-v5` | 15 | 2.2s |  |
| 2 | `Accessibility-v6` | 19 | 2.2s |  |
| 3 | `Accessibility-v7` | 19 | 2.0s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.1s |  |
| 6 | `AsBroadcaster-v6` | 121 | 29.4s |  |
| 7 | `AsBroadcaster-v7` | 121 | 6.3s |  |
| 8 | `AsBroadcaster-v8` | 121 | 3.0s |  |
| 9 | `BitmapData-v5` | 7 | 3.4s |  |
| 10 | `BitmapData-v6` | 7 | 1.6s |  |
| 11 | `BitmapData-v7` | 7 | 3.0s |  |
| 12 | `Boolean-v5` | 38 | 4.0s |  |
| 13 | `Boolean-v6` | 38 | 3.4s |  |
| 14 | `Boolean-v7` | 38 | 20.3s |  |
| 15 | `Boolean-v8` | 38 | 2.5s |  |
| 16 | `Camera-v5` | 7 | 2.6s |  |
| 17 | `Color-v5` | 140 | 6.0s |  |
| 18 | `Color-v6` | 171 | 6.6s |  |
| 19 | `Color-v7` | 161 | 7.0s |  |
| 20 | `Color-v8` | 161 | 31.3s |  |
| 21 | `ColorTransform-v5` | 7 | 3.5s |  |
| 22 | `ColorTransform-v6` | 7 | 1.7s |  |
| 23 | `ColorTransform-v7` | 7 | 3.1s |  |
| 24 | `ColorTransform-v8` | 55 | 4.9s |  |
| 25 | `ContextMenu-v5` | 7 | 3.4s |  |
| 26 | `ContextMenu-v6` | 7 | 1.6s |  |
| 27 | `ContextMenu-v7` | 131 | 6.3s |  |
| 28 | `ContextMenu-v8` | 131 | 22.9s |  |
| 29 | `Error-v5` | 28 | 2.6s |  |
| 30 | `Error-v6` | 31 | 2.7s |  |
| 31 | `Error-v7` | 31 | 2.4s |  |
| 32 | `Error-v8` | 31 | 20.9s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.3s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.0s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.8s |  |
| 36 | `Function-v6` | 271 | 8.7s |  |
| 37 | `Function-v7` | 272 | 8.7s |  |
| 38 | `Function-v8` | 272 | 25.8s |  |
| 39 | `Global-v5` | 172 | 5.8s |  |
| 40 | `Global-v6` | 210 | 6.8s |  |
| 41 | `Global-v7` | 182 | 6.1s |  |
| 42 | `Global-v8` | 169 | 5.7s |  |
| 43 | `HitTest-v6` | 88 | 4.3s |  |
| 44 | `HitTest-v7` | 88 | 4.0s |  |
| 45 | `Instance-v5` | 52 | 4.2s |  |
| 46 | `Instance-v6` | 52 | 2.6s |  |
| 47 | `Instance-v7` | 52 | 3.9s |  |
| 48 | `Instance-v8` | 52 | 2.8s |  |
| 49 | `Key-v5` | 51 | 21.3s |  |
| 50 | `Key-v6` | 55 | 3.1s |  |
| 51 | `Key-v7` | 55 | 2.9s |  |
| 52 | `Key-v8` | 55 | 1.9s |  |
| 53 | `LoadVars-v5` | 8 | 2.4s |  |
| 54 | `LocalConnection-v5` | 7 | 26.6s |  |
| 55 | `LocalConnection-v6` | 58 | 4.4s |  |
| 56 | `LocalConnection-v7` | 58 | 4.1s |  |
| 57 | `LocalConnection-v8` | 58 | 2.6s |  |
| 58 | `Matrix-v5` | 7 | 20.1s |  |
| 59 | `Matrix-v6` | 168 | 6.1s |  |
| 60 | `Matrix-v7` | 168 | 6.2s |  |
| 61 | `Matrix-v8` | 168 | 1.9s |  |
| 62 | `Microphone-v5` | 6 | 2.2s |  |
| 63 | `Mouse-v5` | 13 | 21.5s |  |
| 64 | `Mouse-v6` | 21 | 3.0s |  |
| 65 | `Mouse-v7` | 21 | 2.8s |  |
| 66 | `Mouse-v8` | 21 | 2.4s |  |
| 67 | `MovieClipLoader-v5` | 6 | 20.2s |  |
| 68 | `MovieClipLoader-v6` | 6 | 1.1s |  |
| 69 | `NetConnection-v5` | 7 | 2.2s |  |
| 70 | `NetStream-v5` | 6 | 19.7s |  |
| 71 | `NetStream-v6` | 80 | 3.3s |  |
| 72 | `NetStream-v7` | 80 | 3.0s |  |
| 73 | `NetStream-v8` | 80 | 1.8s |  |
| 74 | `Number-v5` | 244 | 7.1s |  |
| 75 | `Number-v6` | 239 | 6.9s |  |
| 76 | `Number-v7` | 237 | 6.9s |  |
| 77 | `Number-v8` | 237 | 1.9s |  |
| 78 | `Object-v5` | 145 | 22.3s |  |
| 79 | `Point-v5` | 7 | 2.2s |  |
| 80 | `Point-v6` | 7 | 1.1s |  |
| 81 | `Point-v7` | 7 | 1.9s |  |
| 82 | `Point-v8` | 193 | 6.4s |  |
| 83 | `Random-v5` | 30 | 27.5s |  |
| 84 | `Random-v6` | 30 | 1.6s |  |
| 85 | `Random-v7` | 30 | 3.3s |  |
| 86 | `Random-v8` | 30 | 2.6s |  |
| 87 | `Rectangle-v5` | 7 | 3.1s |  |
| 88 | `Rectangle-v6` | 7 | 1.5s |  |
| 89 | `Rectangle-v7` | 7 | 2.8s |  |
| 90 | `Rectangle-v8` | 166 | 8.3s |  |
| 91 | `Selection-v5` | 21 | 20.7s |  |
| 92 | `Selection-v6` | 125 | 4.9s |  |
| 93 | `Selection-v7` | 125 | 4.7s |  |
| 94 | `Selection-v8` | 125 | 2.0s |  |
| 95 | `Sound-v6` | 121 | 5.1s |  |
| 96 | `Sound-v7` | 121 | 4.6s |  |
| 97 | `Sound-v8` | 121 | 2.2s |  |
| 98 | `Stage-v5` | 38 | 21.2s |  |
| 99 | `String-v6` | 377 | 15.2s |  |
| 100 | `String-v7` | 377 | 14.7s |  |
| 101 | `String-v8` | 377 | 2.2s |  |
| 102 | `System-v5` | 67 | 20.9s |  |
| 103 | `System-v6` | 100 | 3.7s |  |
| 104 | `System-v7` | 101 | 3.7s |  |
| 105 | `System-v8` | 101 | 1.9s |  |
| 106 | `TextField-v5` | 12 | 2.3s |  |
| 107 | `TextFieldHTML-v5` | 6 | 20.3s |  |
| 108 | `TextFieldHTML-v6` | 37 | 2.8s |  |
| 109 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 110 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 111 | `TextFormat-v5` | 128 | 4.6s |  |
| 112 | `TextFormat-v6` | 128 | 1.2s |  |
| 113 | `TextSnapshot-v5` | 7 | 20.6s |  |
| 114 | `TextSnapshot-v6` | 173 | 6.6s |  |
| 115 | `TextSnapshot-v7` | 173 | 6.4s |  |
| 116 | `TextSnapshot-v8` | 173 | 1.9s |  |
| 117 | `Transform-v5` | 7 | 2.2s |  |
| 118 | `Transform-v6` | 7 | 1.9s |  |
| 119 | `Transform-v7` | 7 | 2.1s |  |
| 120 | `Try-v5` | 20 | 21.9s |  |
| 121 | `Try-v6` | 20 | 1.5s |  |
| 122 | `Try-v7` | 20 | 3.1s |  |
| 123 | `Try-v8` | 20 | 2.3s |  |
| 124 | `Video-v5` | 7 | 3.2s |  |
| 125 | `Video-v6` | 85 | 4.0s |  |
| 126 | `Video-v7` | 85 | 3.7s |  |
| 127 | `Video-v8` | 85 | 2.3s |  |
| 128 | `XML-v6` | 486 | 12.8s |  |
| 129 | `XML-v7` | 486 | 12.6s |  |
| 130 | `XMLNode-v5` | 207 | 7.4s |  |
| 131 | `XMLNode-v6` | 207 | 7.3s |  |
| 132 | `XMLNode-v7` | 207 | 6.6s |  |
| 133 | `XMLNode-v8` | 207 | 2.2s |  |
| 134 | `XMLSocket-v5` | 35 | 20.1s |  |
| 135 | `XMLSocket-v6` | 35 | 2.6s |  |
| 136 | `XMLSocket-v7` | 35 | 2.4s |  |
| 137 | `XMLSocket-v8` | 35 | 1.9s |  |
| 138 | `argstest-v5` | 4 | 2.3s |  |
| 139 | `case-v5` | 39 | 2.8s |  |
| 140 | `case-v6` | 73 | 3.5s |  |
| 141 | `case-v7` | 67 | 3.4s |  |
| 142 | `case-v8` | 67 | 1.9s |  |
| 143 | `delete-v5` | 61 | 22.1s |  |
| 144 | `delete-v6` | 61 | 2.9s |  |
| 145 | `delete-v7` | 61 | 3.1s |  |
| 146 | `delete-v8` | 61 | 2.2s |  |
| 147 | `enumerate-v5` | 6 | 2.4s |  |
| 148 | `enumerate-v6` | 49 | 3.2s |  |
| 149 | `enumerate-v7` | 49 | 2.9s |  |
| 150 | `enumerate-v8` | 49 | 2.0s |  |
| 151 | `flash-v5` | 10 | 19.8s |  |
| 152 | `flash-v6` | 10 | 2.2s |  |
| 153 | `flash-v7` | 10 | 2.0s |  |
| 154 | `flash-v8` | 41 | 2.9s |  |
| 155 | `getvariable-v5` | 58 | 3.1s |  |
| 156 | `getvariable-v6` | 64 | 3.2s |  |
| 157 | `getvariable-v7` | 64 | 3.2s |  |
| 158 | `getvariable-v8` | 64 | 1.9s |  |
| 159 | `ops-v5` | 260 | 26.9s |  |
| 160 | `ops-v6` | 260 | 8.3s |  |
| 161 | `ops-v7` | 262 | 8.8s |  |
| 162 | `ops-v8` | 262 | 1.9s |  |
| 163 | `swap-v5` | 7 | 20.4s |  |
| 164 | `swap-v6` | 7 | 1.2s |  |
| 165 | `swap-v7` | 7 | 1.8s |  |
| 166 | `swap-v8` | 7 | 1.6s |  |
| 167 | `targetPath-v5` | 12 | 2.1s |  |
| 168 | `targetPath-v6` | 23 | 2.3s |  |
| 169 | `targetPath-v7` | 23 | 2.0s |  |
| 170 | `targetPath-v8` | 23 | 1.6s |  |
| 171 | `toString_valueOf-v6` | 155 | 5.2s |  |
| 172 | `toString_valueOf-v7` | 155 | 5.0s |  |
| 173 | `toString_valueOf-v8` | 155 | 2.0s |  |
| 174 | `with-v5` | 49 | 3.6s |  |
| 175 | `with-v6` | 107 | 4.6s |  |
| 176 | `with-v7` | 107 | 4.4s |  |
| 177 | `with-v8` | 107 | 2.2s |  |

## Ruffle-Matched Tests

**63 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 18.2s |  |
| 2 | `ASnative-v6` | 39 | 40 | 4.6s |  |
| 3 | `ASnative-v7` | 39 | 40 | 4.4s |  |
| 4 | `ASnative-v8` | 39 | 40 | 1.9s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 26.9s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.8s |  |
| 7 | `Camera-v7` | 57 | 57 | 4.7s |  |
| 8 | `Camera-v8` | 57 | 57 | 2.5s |  |
| 9 | `Date-v5` | 6 | 7 | 12.1s |  |
| 10 | `Date-v6` | 6 | 6 | 13.4s |  |
| 11 | `Date-v7` | 6 | 6 | 13.7s |  |
| 12 | `Date-v8` | 6 | 6 | 2.2s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 4.7s |  |
| 14 | `Function-v5` | 4 | 25 | 5.3s |  |
| 15 | `HitTest-v8` | 3 | 9 | 3.9s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 28.8s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 8.2s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 8.4s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 3.4s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 5.4s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 5.0s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 2.6s |  |
| 23 | `Math-v5` | 5 | 5 | 15.3s |  |
| 24 | `Math-v6` | 5 | 5 | 1.7s |  |
| 25 | `Math-v7` | 5 | 5 | 15.3s |  |
| 26 | `Math-v8` | 5 | 5 | 2.7s |  |
| 27 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 28 | `Microphone-v7` | 31 | 31 | 3.1s |  |
| 29 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 30 | `MovieClip-v5` | 10 | 226 | 13.3s |  |
| 31 | `MovieClip-v6` | 20 | 60 | 44.3s |  |
| 32 | `MovieClip-v7` | 20 | 64 | 46.5s |  |
| 33 | `MovieClip-v8` | 25 | 68 | 58.0s |  |
| 34 | `MovieClipLoader-v7` | 118 | 118 | 3.9s |  |
| 35 | `MovieClipLoader-v8` | 118 | 118 | 2.8s |  |
| 36 | `NetConnection-v6` | 4 | 49 | 4.5s |  |
| 37 | `NetConnection-v7` | 4 | 45 | 4.4s |  |
| 38 | `NetConnection-v8` | 4 | 45 | 1.9s |  |
| 39 | `Object-v6` | 8 | 21 | 10.7s |  |
| 40 | `Object-v7` | 8 | 12 | 10.6s |  |
| 41 | `Object-v8` | 8 | 12 | 2.4s |  |
| 42 | `Sound-v5` | 14 | 16 | 4.7s |  |
| 43 | `Stage-v6` | 14 | 14 | 3.2s |  |
| 44 | `Stage-v7` | 14 | 14 | 2.9s |  |
| 45 | `Stage-v8` | 14 | 14 | 2.0s |  |
| 46 | `String-v5` | 14 | 21 | 14.3s |  |
| 47 | `TextField-v6` | 15 | 57 | 18.6s |  |
| 48 | `TextField-v7` | 15 | 73 | 19.8s |  |
| 49 | `TextField-v8` | 14 | 72 | 20.0s |  |
| 50 | `TextFormat-v7` | 38 | 38 | 6.0s |  |
| 51 | `TextFormat-v8` | 36 | 36 | 6.0s |  |
| 52 | `Transform-v8` | 7 | 7 | 4.5s |  |
| 53 | `XML-v5` | 9 | 79 | 25.8s |  |
| 54 | `XML-v8` | 21 | 116 | 4.0s |  |
| 55 | `array-v5` | 5 | 17 | 42.1s |  |
| 56 | `array-v6` | 6 | 25 | 27.7s |  |
| 57 | `array-v7` | 5 | 23 | 29.1s |  |
| 58 | `array-v8` | 5 | 23 | 3.2s |  |
| 59 | `setProperty-v5` | 49 | 49 | 3.0s |  |
| 60 | `setProperty-v6` | 49 | 49 | 3.0s |  |
| 61 | `setProperty-v7` | 49 | 49 | 2.7s |  |
| 62 | `setProperty-v8` | 49 | 49 | 1.9s |  |
| 63 | `toString_valueOf-v5` | 12 | 34 | 24.0s |  |

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
