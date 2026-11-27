# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 16:16 UTC

**Git SHA**: `2d40d37996`

**Run Duration**: 23m 40s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **181** (74.5%) |
| Ruffle-matched | 59 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (98.8%) |
| Failing | 3 |
| Total expected lines | 38791 |
| Matching lines | 31177 (80.4%) |
| Mismatched lines | 7614 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**181 tests passing**

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
| 54 | `LocalConnection-v5` | 7 | 3.0s |  |
| 55 | `LocalConnection-v6` | 58 | 4.1s |  |
| 56 | `LocalConnection-v7` | 58 | 3.8s |  |
| 57 | `LocalConnection-v8` | 58 | 2.5s |  |
| 58 | `Matrix-v5` | 7 | 2.2s |  |
| 59 | `Matrix-v6` | 168 | 5.8s |  |
| 60 | `Matrix-v7` | 168 | 5.8s |  |
| 61 | `Matrix-v8` | 168 | 1.9s |  |
| 62 | `Microphone-v5` | 6 | 2.1s |  |
| 63 | `Mouse-v5` | 13 | 2.3s |  |
| 64 | `Mouse-v6` | 21 | 2.4s |  |
| 65 | `Mouse-v7` | 21 | 2.1s |  |
| 66 | `Mouse-v8` | 21 | 1.9s |  |
| 67 | `MovieClip-v5` | 363 | 11.5s |  |
| 68 | `MovieClip-v6` | 936 | 37.4s |  |
| 69 | `MovieClip-v7` | 969 | 39.4s |  |
| 70 | `MovieClip-v8` | 1087 | 47.4s |  |
| 71 | `MovieClipLoader-v5` | 6 | 2.3s |  |
| 72 | `MovieClipLoader-v6` | 6 | 1.1s |  |
| 73 | `NetConnection-v5` | 7 | 2.2s |  |
| 74 | `NetStream-v5` | 6 | 19.7s |  |
| 75 | `NetStream-v6` | 80 | 3.3s |  |
| 76 | `NetStream-v7` | 80 | 3.1s |  |
| 77 | `NetStream-v8` | 80 | 1.8s |  |
| 78 | `Number-v5` | 244 | 7.0s |  |
| 79 | `Number-v6` | 239 | 6.9s |  |
| 80 | `Number-v7` | 237 | 6.8s |  |
| 81 | `Number-v8` | 237 | 1.9s |  |
| 82 | `Object-v5` | 145 | 6.3s |  |
| 83 | `Point-v5` | 7 | 2.8s |  |
| 84 | `Point-v6` | 7 | 1.4s |  |
| 85 | `Point-v7` | 7 | 2.5s |  |
| 86 | `Point-v8` | 193 | 8.6s |  |
| 87 | `Random-v5` | 30 | 3.8s |  |
| 88 | `Random-v6` | 30 | 1.6s |  |
| 89 | `Random-v7` | 30 | 3.4s |  |
| 90 | `Random-v8` | 30 | 2.7s |  |
| 91 | `Rectangle-v5` | 7 | 3.3s |  |
| 92 | `Rectangle-v6` | 7 | 1.6s |  |
| 93 | `Rectangle-v7` | 7 | 2.9s |  |
| 94 | `Rectangle-v8` | 166 | 8.1s |  |
| 95 | `Selection-v5` | 21 | 2.4s |  |
| 96 | `Selection-v6` | 125 | 4.6s |  |
| 97 | `Selection-v7` | 125 | 4.4s |  |
| 98 | `Selection-v8` | 125 | 1.9s |  |
| 99 | `Sound-v6` | 121 | 4.9s |  |
| 100 | `Sound-v7` | 121 | 4.4s |  |
| 101 | `Sound-v8` | 121 | 2.2s |  |
| 102 | `Stage-v5` | 38 | 3.9s |  |
| 103 | `String-v6` | 377 | 18.9s |  |
| 104 | `String-v7` | 377 | 18.5s |  |
| 105 | `String-v8` | 377 | 3.3s |  |
| 106 | `System-v5` | 67 | 3.3s |  |
| 107 | `System-v6` | 100 | 3.8s |  |
| 108 | `System-v7` | 101 | 4.0s |  |
| 109 | `System-v8` | 101 | 1.9s |  |
| 110 | `TextField-v5` | 12 | 2.4s |  |
| 111 | `TextFieldHTML-v5` | 6 | 2.8s |  |
| 112 | `TextFieldHTML-v6` | 37 | 3.3s |  |
| 113 | `TextFieldHTML-v7` | 37 | 3.0s |  |
| 114 | `TextFieldHTML-v8` | 37 | 2.3s |  |
| 115 | `TextFormat-v5` | 128 | 5.5s |  |
| 116 | `TextFormat-v6` | 128 | 1.4s |  |
| 117 | `TextSnapshot-v5` | 7 | 21.6s |  |
| 118 | `TextSnapshot-v6` | 173 | 8.2s |  |
| 119 | `TextSnapshot-v7` | 173 | 8.0s |  |
| 120 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 121 | `Transform-v5` | 7 | 2.8s |  |
| 122 | `Transform-v6` | 7 | 2.4s |  |
| 123 | `Transform-v7` | 7 | 2.5s |  |
| 124 | `Try-v5` | 20 | 3.1s |  |
| 125 | `Try-v6` | 20 | 1.1s |  |
| 126 | `Try-v7` | 20 | 2.8s |  |
| 127 | `Try-v8` | 20 | 1.9s |  |
| 128 | `Video-v5` | 7 | 2.3s |  |
| 129 | `Video-v6` | 85 | 3.5s |  |
| 130 | `Video-v7` | 85 | 3.2s |  |
| 131 | `Video-v8` | 85 | 1.9s |  |
| 132 | `XML-v6` | 486 | 13.1s |  |
| 133 | `XML-v7` | 486 | 13.1s |  |
| 134 | `XMLNode-v5` | 207 | 7.2s |  |
| 135 | `XMLNode-v6` | 207 | 7.4s |  |
| 136 | `XMLNode-v7` | 207 | 6.8s |  |
| 137 | `XMLNode-v8` | 207 | 2.0s |  |
| 138 | `XMLSocket-v5` | 35 | 20.9s |  |
| 139 | `XMLSocket-v6` | 35 | 2.8s |  |
| 140 | `XMLSocket-v7` | 35 | 2.5s |  |
| 141 | `XMLSocket-v8` | 35 | 2.0s |  |
| 142 | `argstest-v5` | 4 | 2.4s |  |
| 143 | `case-v5` | 39 | 4.3s |  |
| 144 | `case-v6` | 73 | 5.1s |  |
| 145 | `case-v7` | 67 | 5.4s |  |
| 146 | `case-v8` | 67 | 3.2s |  |
| 147 | `delete-v5` | 61 | 3.2s |  |
| 148 | `delete-v6` | 61 | 2.8s |  |
| 149 | `delete-v7` | 61 | 2.9s |  |
| 150 | `delete-v8` | 61 | 2.0s |  |
| 151 | `enumerate-v5` | 6 | 2.3s |  |
| 152 | `enumerate-v6` | 49 | 3.1s |  |
| 153 | `enumerate-v7` | 49 | 2.9s |  |
| 154 | `enumerate-v8` | 49 | 1.9s |  |
| 155 | `flash-v5` | 10 | 20.3s |  |
| 156 | `flash-v6` | 10 | 2.3s |  |
| 157 | `flash-v7` | 10 | 2.1s |  |
| 158 | `flash-v8` | 41 | 3.0s |  |
| 159 | `getvariable-v5` | 58 | 3.2s |  |
| 160 | `getvariable-v6` | 64 | 3.3s |  |
| 161 | `getvariable-v7` | 64 | 3.4s |  |
| 162 | `getvariable-v8` | 64 | 1.9s |  |
| 163 | `ops-v5` | 260 | 9.6s |  |
| 164 | `ops-v6` | 260 | 8.9s |  |
| 165 | `ops-v7` | 262 | 9.4s |  |
| 166 | `ops-v8` | 262 | 2.1s |  |
| 167 | `swap-v5` | 7 | 3.5s |  |
| 168 | `swap-v6` | 7 | 1.7s |  |
| 169 | `swap-v7` | 7 | 3.1s |  |
| 170 | `swap-v8` | 7 | 2.8s |  |
| 171 | `targetPath-v5` | 12 | 3.6s |  |
| 172 | `targetPath-v6` | 23 | 3.9s |  |
| 173 | `targetPath-v7` | 23 | 3.4s |  |
| 174 | `targetPath-v8` | 23 | 2.9s |  |
| 175 | `toString_valueOf-v6` | 155 | 4.7s |  |
| 176 | `toString_valueOf-v7` | 155 | 4.4s |  |
| 177 | `toString_valueOf-v8` | 155 | 1.9s |  |
| 178 | `with-v5` | 49 | 3.4s |  |
| 179 | `with-v6` | 107 | 4.2s |  |
| 180 | `with-v7` | 107 | 4.1s |  |
| 181 | `with-v8` | 107 | 2.1s |  |

## Ruffle-Matched Tests

**59 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

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
| 23 | `Math-v5` | 5 | 5 | 15.5s |  |
| 24 | `Math-v6` | 5 | 5 | 1.7s |  |
| 25 | `Math-v7` | 5 | 5 | 15.8s |  |
| 26 | `Math-v8` | 5 | 5 | 2.8s |  |
| 27 | `Microphone-v6` | 31 | 31 | 3.3s |  |
| 28 | `Microphone-v7` | 31 | 31 | 3.0s |  |
| 29 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 30 | `MovieClipLoader-v7` | 118 | 118 | 3.8s |  |
| 31 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 32 | `NetConnection-v6` | 4 | 49 | 4.3s |  |
| 33 | `NetConnection-v7` | 4 | 45 | 4.4s |  |
| 34 | `NetConnection-v8` | 4 | 45 | 1.9s |  |
| 35 | `Object-v6` | 8 | 21 | 13.1s |  |
| 36 | `Object-v7` | 8 | 12 | 13.3s |  |
| 37 | `Object-v8` | 8 | 12 | 3.0s |  |
| 38 | `Sound-v5` | 14 | 16 | 4.5s |  |
| 39 | `Stage-v6` | 14 | 14 | 4.5s |  |
| 40 | `Stage-v7` | 14 | 14 | 4.1s |  |
| 41 | `Stage-v8` | 14 | 14 | 2.9s |  |
| 42 | `String-v5` | 8 | 21 | 17.9s |  |
| 43 | `TextField-v6` | 15 | 57 | 19.6s |  |
| 44 | `TextField-v7` | 15 | 73 | 21.0s |  |
| 45 | `TextField-v8` | 14 | 72 | 20.8s |  |
| 46 | `TextFormat-v7` | 38 | 38 | 7.2s |  |
| 47 | `TextFormat-v8` | 36 | 36 | 7.2s |  |
| 48 | `Transform-v8` | 7 | 7 | 5.7s |  |
| 49 | `XML-v5` | 9 | 79 | 11.8s |  |
| 50 | `XML-v8` | 21 | 116 | 4.2s |  |
| 51 | `array-v5` | 5 | 17 | 32.6s |  |
| 52 | `array-v6` | 6 | 25 | 38.2s |  |
| 53 | `array-v7` | 5 | 23 | 40.7s |  |
| 54 | `array-v8` | 5 | 23 | 5.2s |  |
| 55 | `setProperty-v5` | 49 | 49 | 3.2s |  |
| 56 | `setProperty-v6` | 49 | 49 | 3.2s |  |
| 57 | `setProperty-v7` | 49 | 49 | 3.0s |  |
| 58 | `setProperty-v8` | 49 | 49 | 2.2s |  |
| 59 | `toString_valueOf-v5` | 12 | 34 | 5.0s |  |

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
| 1 | `argstest-v8` | 4.0% | 121/3006 | 3006 | 2434 |  |
| 2 | `argstest-v6` | 3.2% | 84/2644 | 2644 | 2192 |  |
| 3 | `argstest-v7` | 3.0% | 78/2644 | 2644 | 2061 |  |
