# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 22:24 UTC

**Git SHA**: `0224aaf256`

**Run Duration**: 25m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **181** (74.5%) |
| Ruffle-matched | 59 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (98.8%) |
| Failing | 3 |
| Total expected lines | 38791 |
| Matching lines | 31241 (80.5%) |
| Mismatched lines | 7550 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**181 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.5s |  |
| 2 | `Accessibility-v6` | 19 | 2.5s |  |
| 3 | `Accessibility-v7` | 19 | 2.2s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.4s |  |
| 6 | `AsBroadcaster-v6` | 121 | 27.9s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.8s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.7s |  |
| 9 | `BitmapData-v5` | 7 | 2.1s |  |
| 10 | `BitmapData-v6` | 7 | 0.6s |  |
| 11 | `BitmapData-v7` | 7 | 1.7s |  |
| 12 | `Boolean-v5` | 38 | 2.6s |  |
| 13 | `Boolean-v6` | 38 | 2.1s |  |
| 14 | `Boolean-v7` | 38 | 20.6s |  |
| 15 | `Boolean-v8` | 38 | 1.4s |  |
| 16 | `Camera-v5` | 7 | 1.9s |  |
| 17 | `Color-v5` | 140 | 5.0s |  |
| 18 | `Color-v6` | 171 | 5.9s |  |
| 19 | `Color-v7` | 161 | 5.6s |  |
| 20 | `Color-v8` | 161 | 6.7s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 0.7s |  |
| 23 | `ColorTransform-v7` | 7 | 1.9s |  |
| 24 | `ColorTransform-v8` | 55 | 3.6s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 0.7s |  |
| 27 | `ContextMenu-v7` | 131 | 5.2s |  |
| 28 | `ContextMenu-v8` | 131 | 3.4s |  |
| 29 | `Error-v5` | 28 | 1.7s |  |
| 30 | `Error-v6` | 31 | 1.7s |  |
| 31 | `Error-v7` | 31 | 1.5s |  |
| 32 | `Error-v8` | 31 | 2.8s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.3s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.3s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.9s |  |
| 36 | `Function-v6` | 271 | 10.1s |  |
| 37 | `Function-v7` | 272 | 10.4s |  |
| 38 | `Function-v8` | 272 | 6.9s |  |
| 39 | `Global-v5` | 172 | 4.8s |  |
| 40 | `Global-v6` | 210 | 6.0s |  |
| 41 | `Global-v7` | 182 | 5.2s |  |
| 42 | `Global-v8` | 169 | 4.7s |  |
| 43 | `HitTest-v6` | 88 | 3.5s |  |
| 44 | `HitTest-v7` | 88 | 3.3s |  |
| 45 | `Instance-v5` | 52 | 2.2s |  |
| 46 | `Instance-v6` | 52 | 1.2s |  |
| 47 | `Instance-v7` | 52 | 2.0s |  |
| 48 | `Instance-v8` | 52 | 1.1s |  |
| 49 | `Key-v5` | 51 | 19.4s |  |
| 50 | `Key-v6` | 55 | 1.9s |  |
| 51 | `Key-v7` | 55 | 1.7s |  |
| 52 | `Key-v8` | 55 | 0.9s |  |
| 53 | `LoadVars-v5` | 8 | 1.2s |  |
| 54 | `LocalConnection-v5` | 7 | 25.1s |  |
| 55 | `LocalConnection-v6` | 58 | 3.3s |  |
| 56 | `LocalConnection-v7` | 58 | 2.9s |  |
| 57 | `LocalConnection-v8` | 58 | 1.6s |  |
| 58 | `Matrix-v5` | 7 | 19.8s |  |
| 59 | `Matrix-v6` | 168 | 5.9s |  |
| 60 | `Matrix-v7` | 168 | 6.1s |  |
| 61 | `Matrix-v8` | 168 | 1.3s |  |
| 62 | `Microphone-v5` | 6 | 1.6s |  |
| 63 | `Mouse-v5` | 13 | 21.1s |  |
| 64 | `Mouse-v6` | 21 | 2.1s |  |
| 65 | `Mouse-v7` | 21 | 1.9s |  |
| 66 | `Mouse-v8` | 21 | 1.5s |  |
| 67 | `MovieClip-v5` | 363 | 12.8s |  |
| 68 | `MovieClip-v6` | 936 | 43.4s |  |
| 69 | `MovieClip-v7` | 969 | 45.6s |  |
| 70 | `MovieClip-v8` | 1087 | 56.4s |  |
| 71 | `MovieClipLoader-v5` | 6 | 19.1s |  |
| 72 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 73 | `NetConnection-v5` | 7 | 1.5s |  |
| 74 | `NetStream-v5` | 6 | 2.0s |  |
| 75 | `NetStream-v6` | 80 | 3.8s |  |
| 76 | `NetStream-v7` | 80 | 3.5s |  |
| 77 | `NetStream-v8` | 80 | 1.6s |  |
| 78 | `Number-v5` | 244 | 9.6s |  |
| 79 | `Number-v6` | 239 | 9.3s |  |
| 80 | `Number-v7` | 237 | 9.3s |  |
| 81 | `Number-v8` | 237 | 1.7s |  |
| 82 | `Object-v5` | 145 | 22.3s |  |
| 83 | `Point-v5` | 7 | 1.5s |  |
| 84 | `Point-v6` | 7 | 0.5s |  |
| 85 | `Point-v7` | 7 | 1.2s |  |
| 86 | `Point-v8` | 193 | 6.1s |  |
| 87 | `Random-v5` | 30 | 20.2s |  |
| 88 | `Random-v6` | 30 | 0.5s |  |
| 89 | `Random-v7` | 30 | 1.7s |  |
| 90 | `Random-v8` | 30 | 1.2s |  |
| 91 | `Rectangle-v5` | 7 | 1.5s |  |
| 92 | `Rectangle-v6` | 7 | 0.5s |  |
| 93 | `Rectangle-v7` | 7 | 1.3s |  |
| 94 | `Rectangle-v8` | 166 | 5.4s |  |
| 95 | `Selection-v5` | 21 | 20.2s |  |
| 96 | `Selection-v6` | 125 | 4.1s |  |
| 97 | `Selection-v7` | 125 | 4.1s |  |
| 98 | `Selection-v8` | 125 | 1.2s |  |
| 99 | `Sound-v6` | 121 | 4.3s |  |
| 100 | `Sound-v7` | 121 | 4.0s |  |
| 101 | `Sound-v8` | 121 | 1.5s |  |
| 102 | `Stage-v5` | 38 | 2.6s |  |
| 103 | `String-v6` | 377 | 16.7s |  |
| 104 | `String-v7` | 377 | 15.5s |  |
| 105 | `String-v8` | 377 | 1.8s |  |
| 106 | `System-v5` | 67 | 3.5s |  |
| 107 | `System-v6` | 100 | 4.3s |  |
| 108 | `System-v7` | 101 | 4.4s |  |
| 109 | `System-v8` | 101 | 1.8s |  |
| 110 | `TextField-v5` | 12 | 2.3s |  |
| 111 | `TextFieldHTML-v5` | 6 | 19.4s |  |
| 112 | `TextFieldHTML-v6` | 37 | 2.0s |  |
| 113 | `TextFieldHTML-v7` | 37 | 1.8s |  |
| 114 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 115 | `TextFormat-v5` | 128 | 3.8s |  |
| 116 | `TextFormat-v6` | 128 | 0.5s |  |
| 117 | `TextSnapshot-v5` | 7 | 20.8s |  |
| 118 | `TextSnapshot-v6` | 173 | 7.6s |  |
| 119 | `TextSnapshot-v7` | 173 | 7.3s |  |
| 120 | `TextSnapshot-v8` | 173 | 1.6s |  |
| 121 | `Transform-v5` | 7 | 1.9s |  |
| 122 | `Transform-v6` | 7 | 1.4s |  |
| 123 | `Transform-v7` | 7 | 1.6s |  |
| 124 | `Try-v5` | 20 | 21.6s |  |
| 125 | `Try-v6` | 20 | 0.6s |  |
| 126 | `Try-v7` | 20 | 2.4s |  |
| 127 | `Try-v8` | 20 | 1.5s |  |
| 128 | `Video-v5` | 7 | 2.2s |  |
| 129 | `Video-v6` | 85 | 3.5s |  |
| 130 | `Video-v7` | 85 | 3.1s |  |
| 131 | `Video-v8` | 85 | 1.5s |  |
| 132 | `XML-v6` | 486 | 13.3s |  |
| 133 | `XML-v7` | 486 | 13.2s |  |
| 134 | `XMLNode-v5` | 207 | 7.0s |  |
| 135 | `XMLNode-v6` | 207 | 7.0s |  |
| 136 | `XMLNode-v7` | 207 | 6.0s |  |
| 137 | `XMLNode-v8` | 207 | 1.3s |  |
| 138 | `XMLSocket-v5` | 35 | 2.2s |  |
| 139 | `XMLSocket-v6` | 35 | 2.2s |  |
| 140 | `XMLSocket-v7` | 35 | 1.9s |  |
| 141 | `XMLSocket-v8` | 35 | 1.4s |  |
| 142 | `argstest-v5` | 4 | 1.8s |  |
| 143 | `case-v5` | 39 | 2.1s |  |
| 144 | `case-v6` | 73 | 2.8s |  |
| 145 | `case-v7` | 67 | 2.7s |  |
| 146 | `case-v8` | 67 | 1.2s |  |
| 147 | `delete-v5` | 61 | 20.4s |  |
| 148 | `delete-v6` | 61 | 2.0s |  |
| 149 | `delete-v7` | 61 | 2.1s |  |
| 150 | `delete-v8` | 61 | 1.3s |  |
| 151 | `enumerate-v5` | 6 | 1.5s |  |
| 152 | `enumerate-v6` | 49 | 2.3s |  |
| 153 | `enumerate-v7` | 49 | 2.0s |  |
| 154 | `enumerate-v8` | 49 | 1.1s |  |
| 155 | `flash-v5` | 10 | 1.6s |  |
| 156 | `flash-v6` | 10 | 1.6s |  |
| 157 | `flash-v7` | 10 | 1.3s |  |
| 158 | `flash-v8` | 41 | 2.3s |  |
| 159 | `getvariable-v5` | 58 | 2.5s |  |
| 160 | `getvariable-v6` | 64 | 2.7s |  |
| 161 | `getvariable-v7` | 64 | 2.7s |  |
| 162 | `getvariable-v8` | 64 | 1.2s |  |
| 163 | `ops-v5` | 260 | 25.6s |  |
| 164 | `ops-v6` | 260 | 7.4s |  |
| 165 | `ops-v7` | 262 | 7.7s |  |
| 166 | `ops-v8` | 262 | 1.3s |  |
| 167 | `swap-v5` | 7 | 20.2s |  |
| 168 | `swap-v6` | 7 | 0.6s |  |
| 169 | `swap-v7` | 7 | 1.6s |  |
| 170 | `swap-v8` | 7 | 1.4s |  |
| 171 | `targetPath-v5` | 12 | 1.9s |  |
| 172 | `targetPath-v6` | 23 | 2.1s |  |
| 173 | `targetPath-v7` | 23 | 1.8s |  |
| 174 | `targetPath-v8` | 23 | 1.4s |  |
| 175 | `toString_valueOf-v6` | 155 | 5.5s |  |
| 176 | `toString_valueOf-v7` | 155 | 5.2s |  |
| 177 | `toString_valueOf-v8` | 155 | 1.6s |  |
| 178 | `with-v5` | 49 | 3.4s |  |
| 179 | `with-v6` | 107 | 4.5s |  |
| 180 | `with-v7` | 107 | 4.4s |  |
| 181 | `with-v8` | 107 | 1.7s |  |

## Ruffle-Matched Tests

**59 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 29.5s |  |
| 2 | `ASnative-v6` | 39 | 40 | 6.4s |  |
| 3 | `ASnative-v7` | 39 | 40 | 6.0s |  |
| 4 | `ASnative-v8` | 39 | 40 | 1.9s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 24.8s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.6s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.4s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.4s |  |
| 9 | `Date-v5` | 6 | 7 | 9.9s |  |
| 10 | `Date-v6` | 6 | 6 | 10.9s |  |
| 11 | `Date-v7` | 6 | 6 | 11.2s |  |
| 12 | `Date-v8` | 6 | 6 | 1.4s |  |
| 13 | `ExternalInterface-v8` | 3 | 4 | 5.3s |  |
| 14 | `Function-v5` | 4 | 25 | 6.2s |  |
| 15 | `HitTest-v8` | 3 | 9 | 3.2s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 21.5s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 5.0s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 5.1s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 1.6s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 3.7s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 3.5s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 1.5s |  |
| 23 | `Math-v5` | 5 | 5 | 13.5s |  |
| 24 | `Math-v6` | 5 | 5 | 0.8s |  |
| 25 | `Math-v7` | 5 | 5 | 13.9s |  |
| 26 | `Math-v8` | 5 | 5 | 1.8s |  |
| 27 | `Microphone-v6` | 31 | 31 | 2.8s |  |
| 28 | `Microphone-v7` | 31 | 31 | 2.5s |  |
| 29 | `Microphone-v8` | 31 | 31 | 1.2s |  |
| 30 | `MovieClipLoader-v7` | 118 | 118 | 3.1s |  |
| 31 | `MovieClipLoader-v8` | 118 | 118 | 2.0s |  |
| 32 | `NetConnection-v6` | 4 | 49 | 3.5s |  |
| 33 | `NetConnection-v7` | 4 | 45 | 3.5s |  |
| 34 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 35 | `Object-v6` | 8 | 21 | 10.5s |  |
| 36 | `Object-v7` | 8 | 12 | 10.7s |  |
| 37 | `Object-v8` | 8 | 12 | 1.7s |  |
| 38 | `Sound-v5` | 14 | 16 | 4.2s |  |
| 39 | `Stage-v6` | 14 | 14 | 3.1s |  |
| 40 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 41 | `Stage-v8` | 14 | 14 | 1.6s |  |
| 42 | `String-v5` | 8 | 21 | 16.0s |  |
| 43 | `TextField-v6` | 15 | 57 | 23.3s |  |
| 44 | `TextField-v7` | 15 | 73 | 25.2s |  |
| 45 | `TextField-v8` | 14 | 72 | 24.9s |  |
| 46 | `TextFormat-v7` | 38 | 38 | 5.1s |  |
| 47 | `TextFormat-v8` | 36 | 36 | 5.2s |  |
| 48 | `Transform-v8` | 7 | 7 | 4.8s |  |
| 49 | `XML-v5` | 9 | 79 | 30.0s |  |
| 50 | `XML-v8` | 21 | 116 | 3.6s |  |
| 51 | `array-v5` | 5 | 17 | 40.8s |  |
| 52 | `array-v6` | 6 | 25 | 27.0s |  |
| 53 | `array-v7` | 5 | 23 | 28.7s |  |
| 54 | `array-v8` | 5 | 23 | 2.5s |  |
| 55 | `setProperty-v5` | 49 | 49 | 2.4s |  |
| 56 | `setProperty-v6` | 49 | 49 | 2.4s |  |
| 57 | `setProperty-v7` | 49 | 49 | 2.1s |  |
| 58 | `setProperty-v8` | 49 | 49 | 1.4s |  |
| 59 | `toString_valueOf-v5` | 12 | 34 | 5.1s |  |

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
| 1 | `argstest-v8` | 3.9% | 144/3671 | 3671 | 2434 |  |
| 2 | `argstest-v6` | 3.3% | 110/3309 | 3309 | 2192 |  |
| 3 | `argstest-v7` | 2.8% | 93/3309 | 3309 | 2061 |  |
