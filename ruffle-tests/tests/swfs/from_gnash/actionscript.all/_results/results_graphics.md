# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 00:52 UTC

**Git SHA**: `9498e80c12`

**Run Duration**: 32m 34s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **182** (74.9%) |
| Ruffle-matched | 58 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (98.8%) |
| Failing | 3 |
| Total expected lines | 38791 |
| Matching lines | 31115 (80.2%) |
| Mismatched lines | 7676 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**182 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.7s |  |
| 2 | `Accessibility-v6` | 19 | 2.6s |  |
| 3 | `Accessibility-v7` | 19 | 2.3s |  |
| 4 | `Accessibility-v8` | 19 | 2.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.5s |  |
| 6 | `AsBroadcaster-v6` | 121 | 22.8s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.2s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.0s |  |
| 9 | `BitmapData-v5` | 7 | 2.3s |  |
| 10 | `BitmapData-v6` | 7 | 1.1s |  |
| 11 | `BitmapData-v7` | 7 | 2.0s |  |
| 12 | `Boolean-v5` | 38 | 2.6s |  |
| 13 | `Boolean-v6` | 38 | 2.2s |  |
| 14 | `Boolean-v7` | 38 | 21.8s |  |
| 15 | `Boolean-v8` | 38 | 2.3s |  |
| 16 | `Camera-v5` | 7 | 2.7s |  |
| 17 | `Color-v5` | 140 | 5.8s |  |
| 18 | `Color-v6` | 171 | 6.8s |  |
| 19 | `Color-v7` | 161 | 6.6s |  |
| 20 | `Color-v8` | 161 | 25.1s |  |
| 21 | `ColorTransform-v5` | 7 | 2.8s |  |
| 22 | `ColorTransform-v6` | 7 | 1.4s |  |
| 23 | `ColorTransform-v7` | 7 | 2.5s |  |
| 24 | `ColorTransform-v8` | 55 | 3.9s |  |
| 25 | `ContextMenu-v5` | 7 | 2.7s |  |
| 26 | `ContextMenu-v6` | 7 | 1.5s |  |
| 27 | `ContextMenu-v7` | 131 | 5.4s |  |
| 28 | `ContextMenu-v8` | 131 | 23.9s |  |
| 29 | `Error-v5` | 28 | 3.0s |  |
| 30 | `Error-v6` | 31 | 3.1s |  |
| 31 | `Error-v7` | 31 | 2.8s |  |
| 32 | `Error-v8` | 31 | 20.6s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.2s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.9s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `ExternalInterface-v8` | 118 | 4.2s |  |
| 37 | `Function-v6` | 271 | 7.8s |  |
| 38 | `Function-v7` | 272 | 8.1s |  |
| 39 | `Function-v8` | 272 | 26.7s |  |
| 40 | `Global-v5` | 172 | 6.2s |  |
| 41 | `Global-v6` | 210 | 7.5s |  |
| 42 | `Global-v7` | 182 | 6.5s |  |
| 43 | `Global-v8` | 169 | 6.0s |  |
| 44 | `HitTest-v6` | 88 | 4.5s |  |
| 45 | `HitTest-v7` | 88 | 4.2s |  |
| 46 | `Instance-v5` | 52 | 2.9s |  |
| 47 | `Instance-v6` | 52 | 1.9s |  |
| 48 | `Instance-v7` | 52 | 2.6s |  |
| 49 | `Instance-v8` | 52 | 1.8s |  |
| 50 | `Key-v5` | 51 | 21.5s |  |
| 51 | `Key-v6` | 55 | 3.0s |  |
| 52 | `Key-v7` | 55 | 2.8s |  |
| 53 | `Key-v8` | 55 | 1.9s |  |
| 54 | `LoadVars-v5` | 8 | 2.3s |  |
| 55 | `LocalConnection-v5` | 7 | 23.0s |  |
| 56 | `LocalConnection-v6` | 58 | 4.1s |  |
| 57 | `LocalConnection-v7` | 58 | 3.8s |  |
| 58 | `LocalConnection-v8` | 58 | 2.4s |  |
| 59 | `Matrix-v5` | 7 | 21.2s |  |
| 60 | `Matrix-v6` | 168 | 7.5s |  |
| 61 | `Matrix-v7` | 168 | 7.6s |  |
| 62 | `Matrix-v8` | 168 | 2.4s |  |
| 63 | `Microphone-v5` | 6 | 2.7s |  |
| 64 | `Mouse-v5` | 13 | 20.4s |  |
| 65 | `Mouse-v6` | 21 | 2.4s |  |
| 66 | `Mouse-v7` | 21 | 2.2s |  |
| 67 | `Mouse-v8` | 21 | 1.9s |  |
| 68 | `MovieClip-v5` | 363 | 11.3s |  |
| 69 | `MovieClip-v6` | 936 | 39.0s |  |
| 70 | `MovieClip-v7` | 969 | 42.1s |  |
| 71 | `MovieClip-v8` | 1087 | 52.0s |  |
| 72 | `MovieClipLoader-v5` | 6 | 22.5s |  |
| 73 | `MovieClipLoader-v6` | 6 | 1.5s |  |
| 74 | `NetConnection-v5` | 7 | 3.1s |  |
| 75 | `NetStream-v5` | 6 | 20.3s |  |
| 76 | `NetStream-v6` | 80 | 3.4s |  |
| 77 | `NetStream-v7` | 80 | 3.1s |  |
| 78 | `NetStream-v8` | 80 | 1.9s |  |
| 79 | `Number-v5` | 244 | 7.8s |  |
| 80 | `Number-v6` | 239 | 7.5s |  |
| 81 | `Number-v7` | 237 | 7.5s |  |
| 82 | `Number-v8` | 237 | 2.0s |  |
| 83 | `Object-v5` | 145 | 30.4s |  |
| 84 | `Point-v5` | 7 | 3.3s |  |
| 85 | `Point-v6` | 7 | 1.6s |  |
| 86 | `Point-v7` | 7 | 3.0s |  |
| 87 | `Point-v8` | 193 | 9.6s |  |
| 88 | `Random-v5` | 30 | 18.7s |  |
| 89 | `Random-v6` | 30 | 1.2s |  |
| 90 | `Random-v7` | 30 | 2.5s |  |
| 91 | `Random-v8` | 30 | 2.2s |  |
| 92 | `Rectangle-v5` | 7 | 2.3s |  |
| 93 | `Rectangle-v6` | 7 | 1.2s |  |
| 94 | `Rectangle-v7` | 7 | 2.1s |  |
| 95 | `Rectangle-v8` | 166 | 6.5s |  |
| 96 | `Selection-v5` | 21 | 26.6s |  |
| 97 | `Selection-v6` | 125 | 6.7s |  |
| 98 | `Selection-v7` | 125 | 6.3s |  |
| 99 | `Selection-v8` | 125 | 2.9s |  |
| 100 | `Sound-v6` | 121 | 7.0s |  |
| 101 | `Sound-v7` | 121 | 6.3s |  |
| 102 | `Sound-v8` | 121 | 3.2s |  |
| 103 | `Stage-v5` | 38 | 20.7s |  |
| 104 | `String-v6` | 377 | 13.4s |  |
| 105 | `String-v7` | 377 | 13.1s |  |
| 106 | `String-v8` | 377 | 2.1s |  |
| 107 | `System-v5` | 67 | 19.8s |  |
| 108 | `System-v6` | 100 | 4.1s |  |
| 109 | `System-v7` | 101 | 4.0s |  |
| 110 | `System-v8` | 101 | 1.8s |  |
| 111 | `TextField-v5` | 12 | 2.1s |  |
| 112 | `TextFieldHTML-v5` | 6 | 20.7s |  |
| 113 | `TextFieldHTML-v6` | 37 | 2.8s |  |
| 114 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 115 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 116 | `TextFormat-v5` | 128 | 4.5s |  |
| 117 | `TextFormat-v6` | 128 | 1.2s |  |
| 118 | `TextSnapshot-v5` | 7 | 21.6s |  |
| 119 | `TextSnapshot-v6` | 173 | 7.2s |  |
| 120 | `TextSnapshot-v7` | 173 | 6.9s |  |
| 121 | `TextSnapshot-v8` | 173 | 2.0s |  |
| 122 | `Transform-v5` | 7 | 2.3s |  |
| 123 | `Transform-v6` | 7 | 1.9s |  |
| 124 | `Transform-v7` | 7 | 2.0s |  |
| 125 | `Try-v5` | 20 | 28.0s |  |
| 126 | `Try-v6` | 20 | 1.7s |  |
| 127 | `Try-v7` | 20 | 4.1s |  |
| 128 | `Try-v8` | 20 | 2.9s |  |
| 129 | `Video-v5` | 7 | 3.4s |  |
| 130 | `Video-v6` | 85 | 5.1s |  |
| 131 | `Video-v7` | 85 | 4.7s |  |
| 132 | `Video-v8` | 85 | 2.8s |  |
| 133 | `XML-v6` | 486 | 18.6s |  |
| 134 | `XML-v7` | 486 | 18.3s |  |
| 135 | `XMLNode-v5` | 207 | 10.6s |  |
| 136 | `XMLNode-v6` | 207 | 10.6s |  |
| 137 | `XMLNode-v7` | 207 | 9.2s |  |
| 138 | `XMLNode-v8` | 207 | 3.2s |  |
| 139 | `XMLSocket-v5` | 35 | 22.9s |  |
| 140 | `XMLSocket-v6` | 35 | 3.1s |  |
| 141 | `XMLSocket-v7` | 35 | 2.8s |  |
| 142 | `XMLSocket-v8` | 35 | 2.2s |  |
| 143 | `argstest-v5` | 4 | 2.6s |  |
| 144 | `case-v5` | 39 | 4.0s |  |
| 145 | `case-v6` | 73 | 4.9s |  |
| 146 | `case-v7` | 67 | 4.8s |  |
| 147 | `case-v8` | 67 | 2.8s |  |
| 148 | `delete-v5` | 61 | 28.2s |  |
| 149 | `delete-v6` | 61 | 4.2s |  |
| 150 | `delete-v7` | 61 | 4.4s |  |
| 151 | `delete-v8` | 61 | 3.1s |  |
| 152 | `enumerate-v5` | 6 | 3.4s |  |
| 153 | `enumerate-v6` | 49 | 4.7s |  |
| 154 | `enumerate-v7` | 49 | 4.3s |  |
| 155 | `enumerate-v8` | 49 | 2.8s |  |
| 156 | `flash-v5` | 10 | 20.1s |  |
| 157 | `flash-v6` | 10 | 2.2s |  |
| 158 | `flash-v7` | 10 | 2.0s |  |
| 159 | `flash-v8` | 41 | 2.9s |  |
| 160 | `getvariable-v5` | 58 | 3.1s |  |
| 161 | `getvariable-v6` | 64 | 3.2s |  |
| 162 | `getvariable-v7` | 64 | 3.2s |  |
| 163 | `getvariable-v8` | 64 | 1.9s |  |
| 164 | `ops-v5` | 260 | 22.5s |  |
| 165 | `ops-v6` | 260 | 7.5s |  |
| 166 | `ops-v7` | 262 | 7.9s |  |
| 167 | `ops-v8` | 262 | 1.9s |  |
| 168 | `swap-v5` | 7 | 27.2s |  |
| 169 | `swap-v6` | 7 | 1.7s |  |
| 170 | `swap-v7` | 7 | 3.1s |  |
| 171 | `swap-v8` | 7 | 2.9s |  |
| 172 | `targetPath-v5` | 12 | 3.5s |  |
| 173 | `targetPath-v6` | 23 | 3.7s |  |
| 174 | `targetPath-v7` | 23 | 3.4s |  |
| 175 | `targetPath-v8` | 23 | 2.8s |  |
| 176 | `toString_valueOf-v6` | 155 | 4.9s |  |
| 177 | `toString_valueOf-v7` | 155 | 4.7s |  |
| 178 | `toString_valueOf-v8` | 155 | 2.0s |  |
| 179 | `with-v5` | 49 | 3.4s |  |
| 180 | `with-v6` | 107 | 4.3s |  |
| 181 | `with-v7` | 107 | 4.0s |  |
| 182 | `with-v8` | 107 | 2.1s |  |

## Ruffle-Matched Tests

**58 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 21.6s |  |
| 2 | `ASnative-v6` | 39 | 40 | 5.5s |  |
| 3 | `ASnative-v7` | 39 | 40 | 5.3s |  |
| 4 | `ASnative-v8` | 39 | 40 | 2.3s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 38.4s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.6s |  |
| 7 | `Camera-v7` | 57 | 57 | 4.3s |  |
| 8 | `Camera-v8` | 57 | 57 | 2.4s |  |
| 9 | `Date-v5` | 6 | 7 | 13.7s |  |
| 10 | `Date-v6` | 6 | 6 | 15.0s |  |
| 11 | `Date-v7` | 6 | 6 | 15.5s |  |
| 12 | `Date-v8` | 6 | 6 | 2.7s |  |
| 13 | `Function-v5` | 4 | 25 | 4.9s |  |
| 14 | `HitTest-v8` | 3 | 9 | 4.1s |  |
| 15 | `Inheritance-v5` | 1 | 17 | 22.2s |  |
| 16 | `Inheritance-v6` | 9 | 13 | 5.5s |  |
| 17 | `Inheritance-v7` | 5 | 7 | 5.6s |  |
| 18 | `Inheritance-v8` | 5 | 7 | 2.3s |  |
| 19 | `LoadVars-v6` | 6 | 8 | 5.0s |  |
| 20 | `LoadVars-v7` | 6 | 8 | 4.8s |  |
| 21 | `LoadVars-v8` | 6 | 8 | 2.5s |  |
| 22 | `Math-v5` | 5 | 5 | 14.7s |  |
| 23 | `Math-v6` | 5 | 5 | 1.6s |  |
| 24 | `Math-v7` | 5 | 5 | 15.2s |  |
| 25 | `Math-v8` | 5 | 5 | 2.6s |  |
| 26 | `Microphone-v6` | 31 | 31 | 4.0s |  |
| 27 | `Microphone-v7` | 31 | 31 | 3.7s |  |
| 28 | `Microphone-v8` | 31 | 31 | 2.4s |  |
| 29 | `MovieClipLoader-v7` | 118 | 118 | 4.7s |  |
| 30 | `MovieClipLoader-v8` | 118 | 118 | 3.4s |  |
| 31 | `NetConnection-v6` | 4 | 49 | 5.9s |  |
| 32 | `NetConnection-v7` | 4 | 45 | 5.9s |  |
| 33 | `NetConnection-v8` | 4 | 45 | 2.6s |  |
| 34 | `Object-v6` | 8 | 21 | 14.7s |  |
| 35 | `Object-v7` | 8 | 12 | 14.9s |  |
| 36 | `Object-v8` | 8 | 12 | 3.6s |  |
| 37 | `Sound-v5` | 14 | 16 | 6.5s |  |
| 38 | `Stage-v6` | 14 | 14 | 3.0s |  |
| 39 | `Stage-v7` | 14 | 14 | 2.8s |  |
| 40 | `Stage-v8` | 14 | 14 | 1.9s |  |
| 41 | `String-v5` | 8 | 21 | 12.6s |  |
| 42 | `TextField-v6` | 15 | 57 | 17.8s |  |
| 43 | `TextField-v7` | 15 | 73 | 19.4s |  |
| 44 | `TextField-v8` | 14 | 72 | 19.1s |  |
| 45 | `TextFormat-v7` | 38 | 38 | 6.0s |  |
| 46 | `TextFormat-v8` | 36 | 36 | 6.1s |  |
| 47 | `Transform-v8` | 7 | 7 | 4.7s |  |
| 48 | `XML-v5` | 9 | 79 | 40.5s |  |
| 49 | `XML-v8` | 21 | 116 | 6.4s |  |
| 50 | `array-v5` | 5 | 17 | 53.4s |  |
| 51 | `array-v6` | 6 | 25 | 37.6s |  |
| 52 | `array-v7` | 5 | 23 | 37.5s |  |
| 53 | `array-v8` | 5 | 23 | 4.7s |  |
| 54 | `setProperty-v5` | 49 | 49 | 2.8s |  |
| 55 | `setProperty-v6` | 49 | 49 | 2.7s |  |
| 56 | `setProperty-v7` | 49 | 49 | 2.5s |  |
| 57 | `setProperty-v8` | 49 | 49 | 1.9s |  |
| 58 | `toString_valueOf-v5` | 12 | 34 | 23.4s |  |

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

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `argstest-v6` | 2.3% | 75/3307 | 3307 | 2192 |  |
| 2 | `argstest-v7` | 2.1% | 71/3307 | 3307 | 2061 |  |
| 3 | `argstest-v8` | 2.0% | 72/3659 | 3659 | 2434 |  |
