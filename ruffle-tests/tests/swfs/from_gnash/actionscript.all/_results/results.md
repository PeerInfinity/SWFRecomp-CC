# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 03:57 UTC

**Git SHA**: `dbc43c1573`

**Run Duration**: 22m 60s

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
| 1 | `Accessibility-v5` | 15 | 2.0s |  |
| 2 | `Accessibility-v6` | 19 | 2.0s |  |
| 3 | `Accessibility-v7` | 19 | 1.8s |  |
| 4 | `Accessibility-v8` | 19 | 1.4s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.9s |  |
| 6 | `AsBroadcaster-v6` | 121 | 21.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 3.4s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.2s |  |
| 9 | `BitmapData-v5` | 7 | 1.5s |  |
| 10 | `BitmapData-v6` | 7 | 0.5s |  |
| 11 | `BitmapData-v7` | 7 | 1.2s |  |
| 12 | `Boolean-v5` | 38 | 1.9s |  |
| 13 | `Boolean-v6` | 38 | 1.5s |  |
| 14 | `Boolean-v7` | 38 | 2.0s |  |
| 15 | `Boolean-v8` | 38 | 1.1s |  |
| 16 | `Camera-v5` | 7 | 1.5s |  |
| 17 | `Color-v5` | 140 | 4.3s |  |
| 18 | `Color-v6` | 171 | 5.3s |  |
| 19 | `Color-v7` | 161 | 5.0s |  |
| 20 | `Color-v8` | 161 | 5.0s |  |
| 21 | `ColorTransform-v5` | 7 | 1.5s |  |
| 22 | `ColorTransform-v6` | 7 | 0.5s |  |
| 23 | `ColorTransform-v7` | 7 | 1.3s |  |
| 24 | `ColorTransform-v8` | 55 | 2.6s |  |
| 25 | `ContextMenu-v5` | 7 | 1.5s |  |
| 26 | `ContextMenu-v6` | 7 | 0.5s |  |
| 27 | `ContextMenu-v7` | 131 | 3.8s |  |
| 28 | `ContextMenu-v8` | 131 | 21.3s |  |
| 29 | `Error-v5` | 28 | 1.8s |  |
| 30 | `Error-v6` | 31 | 1.9s |  |
| 31 | `Error-v7` | 31 | 1.6s |  |
| 32 | `Error-v8` | 31 | 20.1s |  |
| 33 | `ExternalInterface-v5` | 7 | 1.5s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.2s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.0s |  |
| 36 | `Function-v6` | 271 | 7.1s |  |
| 37 | `Function-v7` | 272 | 7.5s |  |
| 38 | `Function-v8` | 272 | 23.3s |  |
| 39 | `Global-v5` | 172 | 5.4s |  |
| 40 | `Global-v6` | 210 | 6.0s |  |
| 41 | `Global-v7` | 182 | 5.2s |  |
| 42 | `Global-v8` | 169 | 4.8s |  |
| 43 | `HitTest-v6` | 88 | 3.4s |  |
| 44 | `HitTest-v7` | 88 | 3.2s |  |
| 45 | `Instance-v5` | 52 | 2.9s |  |
| 46 | `Instance-v6` | 52 | 1.6s |  |
| 47 | `Instance-v7` | 52 | 2.6s |  |
| 48 | `Instance-v8` | 52 | 1.5s |  |
| 49 | `Key-v5` | 51 | 20.3s |  |
| 50 | `Key-v6` | 55 | 2.3s |  |
| 51 | `Key-v7` | 55 | 2.0s |  |
| 52 | `Key-v8` | 55 | 1.2s |  |
| 53 | `LoadVars-v5` | 8 | 1.6s |  |
| 54 | `LocalConnection-v5` | 7 | 24.0s |  |
| 55 | `LocalConnection-v6` | 58 | 3.5s |  |
| 56 | `LocalConnection-v7` | 58 | 3.0s |  |
| 57 | `LocalConnection-v8` | 58 | 1.6s |  |
| 58 | `Matrix-v5` | 7 | 21.2s |  |
| 59 | `Matrix-v6` | 168 | 7.3s |  |
| 60 | `Matrix-v7` | 168 | 7.5s |  |
| 61 | `Matrix-v8` | 168 | 1.7s |  |
| 62 | `Microphone-v5` | 6 | 1.9s |  |
| 63 | `Mouse-v5` | 13 | 18.9s |  |
| 64 | `Mouse-v6` | 21 | 1.7s |  |
| 65 | `Mouse-v7` | 21 | 1.4s |  |
| 66 | `Mouse-v8` | 21 | 1.1s |  |
| 67 | `MovieClip-v5` | 363 | 9.9s |  |
| 68 | `MovieClip-v6` | 936 | 37.5s |  |
| 69 | `MovieClip-v7` | 969 | 39.9s |  |
| 70 | `MovieClip-v8` | 1087 | 50.6s |  |
| 71 | `MovieClipLoader-v5` | 6 | 19.2s |  |
| 72 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 73 | `NetConnection-v5` | 7 | 1.5s |  |
| 74 | `NetStream-v5` | 6 | 19.3s |  |
| 75 | `NetStream-v6` | 80 | 2.8s |  |
| 76 | `NetStream-v7` | 80 | 2.5s |  |
| 77 | `NetStream-v8` | 80 | 1.2s |  |
| 78 | `Number-v5` | 244 | 7.4s |  |
| 79 | `Number-v6` | 239 | 7.4s |  |
| 80 | `Number-v7` | 237 | 7.5s |  |
| 81 | `Number-v8` | 237 | 1.3s |  |
| 82 | `Object-v5` | 145 | 4.5s |  |
| 83 | `Point-v5` | 7 | 1.5s |  |
| 84 | `Point-v6` | 7 | 0.5s |  |
| 85 | `Point-v7` | 7 | 1.2s |  |
| 86 | `Point-v8` | 193 | 6.5s |  |
| 87 | `Random-v5` | 30 | 2.2s |  |
| 88 | `Random-v6` | 30 | 0.6s |  |
| 89 | `Random-v7` | 30 | 1.9s |  |
| 90 | `Random-v8` | 30 | 1.4s |  |
| 91 | `Rectangle-v5` | 7 | 1.8s |  |
| 92 | `Rectangle-v6` | 7 | 0.6s |  |
| 93 | `Rectangle-v7` | 7 | 1.6s |  |
| 94 | `Rectangle-v8` | 166 | 6.2s |  |
| 95 | `Selection-v5` | 21 | 21.3s |  |
| 96 | `Selection-v6` | 125 | 5.5s |  |
| 97 | `Selection-v7` | 125 | 5.0s |  |
| 98 | `Selection-v8` | 125 | 1.5s |  |
| 99 | `Sound-v6` | 121 | 5.2s |  |
| 100 | `Sound-v7` | 121 | 4.9s |  |
| 101 | `Sound-v8` | 121 | 2.1s |  |
| 102 | `Stage-v5` | 38 | 19.7s |  |
| 103 | `String-v6` | 377 | 13.3s |  |
| 104 | `String-v7` | 377 | 12.8s |  |
| 105 | `String-v8` | 377 | 1.4s |  |
| 106 | `System-v5` | 67 | 3.1s |  |
| 107 | `System-v6` | 100 | 4.0s |  |
| 108 | `System-v7` | 101 | 4.0s |  |
| 109 | `System-v8` | 101 | 1.5s |  |
| 110 | `TextField-v5` | 12 | 1.8s |  |
| 111 | `TextFieldHTML-v5` | 6 | 1.9s |  |
| 112 | `TextFieldHTML-v6` | 37 | 2.4s |  |
| 113 | `TextFieldHTML-v7` | 37 | 2.1s |  |
| 114 | `TextFieldHTML-v8` | 37 | 1.4s |  |
| 115 | `TextFormat-v5` | 128 | 4.7s |  |
| 116 | `TextFormat-v6` | 128 | 0.6s |  |
| 117 | `TextSnapshot-v5` | 7 | 19.3s |  |
| 118 | `TextSnapshot-v6` | 173 | 5.8s |  |
| 119 | `TextSnapshot-v7` | 173 | 5.5s |  |
| 120 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 121 | `Transform-v5` | 7 | 1.5s |  |
| 122 | `Transform-v6` | 7 | 1.1s |  |
| 123 | `Transform-v7` | 7 | 1.2s |  |
| 124 | `Try-v5` | 20 | 20.3s |  |
| 125 | `Try-v6` | 20 | 0.5s |  |
| 126 | `Try-v7` | 20 | 2.1s |  |
| 127 | `Try-v8` | 20 | 1.2s |  |
| 128 | `Video-v5` | 7 | 1.6s |  |
| 129 | `Video-v6` | 85 | 2.7s |  |
| 130 | `Video-v7` | 85 | 2.5s |  |
| 131 | `Video-v8` | 85 | 1.1s |  |
| 132 | `XML-v6` | 486 | 12.0s |  |
| 133 | `XML-v7` | 486 | 12.0s |  |
| 134 | `XMLNode-v5` | 207 | 6.2s |  |
| 135 | `XMLNode-v6` | 207 | 6.2s |  |
| 136 | `XMLNode-v7` | 207 | 5.5s |  |
| 137 | `XMLNode-v8` | 207 | 1.3s |  |
| 138 | `XMLSocket-v5` | 35 | 2.6s |  |
| 139 | `XMLSocket-v6` | 35 | 2.6s |  |
| 140 | `XMLSocket-v7` | 35 | 2.3s |  |
| 141 | `XMLSocket-v8` | 35 | 1.6s |  |
| 142 | `argstest-v5` | 4 | 2.1s |  |
| 143 | `case-v5` | 39 | 2.3s |  |
| 144 | `case-v6` | 73 | 3.3s |  |
| 145 | `case-v7` | 67 | 3.2s |  |
| 146 | `case-v8` | 67 | 1.4s |  |
| 147 | `delete-v5` | 61 | 2.4s |  |
| 148 | `delete-v6` | 61 | 2.0s |  |
| 149 | `delete-v7` | 61 | 2.1s |  |
| 150 | `delete-v8` | 61 | 1.3s |  |
| 151 | `enumerate-v5` | 6 | 1.5s |  |
| 152 | `enumerate-v6` | 49 | 2.3s |  |
| 153 | `enumerate-v7` | 49 | 2.1s |  |
| 154 | `enumerate-v8` | 49 | 1.1s |  |
| 155 | `flash-v5` | 10 | 1.7s |  |
| 156 | `flash-v6` | 10 | 1.6s |  |
| 157 | `flash-v7` | 10 | 1.4s |  |
| 158 | `flash-v8` | 41 | 2.2s |  |
| 159 | `getvariable-v5` | 58 | 2.4s |  |
| 160 | `getvariable-v6` | 64 | 2.5s |  |
| 161 | `getvariable-v7` | 64 | 2.6s |  |
| 162 | `getvariable-v8` | 64 | 1.2s |  |
| 163 | `ops-v5` | 260 | 9.3s |  |
| 164 | `ops-v6` | 260 | 8.8s |  |
| 165 | `ops-v7` | 262 | 9.4s |  |
| 166 | `ops-v8` | 262 | 1.6s |  |
| 167 | `swap-v5` | 7 | 1.5s |  |
| 168 | `swap-v6` | 7 | 0.5s |  |
| 169 | `swap-v7` | 7 | 1.2s |  |
| 170 | `swap-v8` | 7 | 1.1s |  |
| 171 | `targetPath-v5` | 12 | 1.6s |  |
| 172 | `targetPath-v6` | 23 | 1.7s |  |
| 173 | `targetPath-v7` | 23 | 1.5s |  |
| 174 | `targetPath-v8` | 23 | 1.1s |  |
| 175 | `toString_valueOf-v6` | 155 | 4.6s |  |
| 176 | `toString_valueOf-v7` | 155 | 4.3s |  |
| 177 | `toString_valueOf-v8` | 155 | 1.3s |  |
| 178 | `with-v5` | 49 | 2.9s |  |
| 179 | `with-v6` | 107 | 3.8s |  |
| 180 | `with-v7` | 107 | 3.6s |  |
| 181 | `with-v8` | 107 | 1.4s |  |

## Ruffle-Matched Tests

**59 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 5.1s |  |
| 2 | `ASnative-v6` | 39 | 40 | 5.2s |  |
| 3 | `ASnative-v7` | 39 | 40 | 4.9s |  |
| 4 | `ASnative-v8` | 39 | 40 | 1.5s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 19.8s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.1s |  |
| 7 | `Camera-v7` | 57 | 57 | 2.9s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 9 | `Date-v5` | 6 | 7 | 10.9s |  |
| 10 | `Date-v6` | 6 | 6 | 12.1s |  |
| 11 | `Date-v7` | 6 | 6 | 12.5s |  |
| 12 | `Date-v8` | 6 | 6 | 1.4s |  |
| 13 | `ExternalInterface-v8` | 3 | 4 | 3.9s |  |
| 14 | `Function-v5` | 4 | 25 | 4.3s |  |
| 15 | `HitTest-v8` | 3 | 9 | 3.0s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 24.4s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 6.7s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 6.8s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 2.0s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 4.2s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 4.1s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 1.8s |  |
| 23 | `Math-v5` | 5 | 5 | 14.2s |  |
| 24 | `Math-v6` | 5 | 5 | 0.8s |  |
| 25 | `Math-v7` | 5 | 5 | 14.7s |  |
| 26 | `Math-v8` | 5 | 5 | 1.8s |  |
| 27 | `Microphone-v6` | 31 | 31 | 3.1s |  |
| 28 | `Microphone-v7` | 31 | 31 | 2.9s |  |
| 29 | `Microphone-v8` | 31 | 31 | 1.4s |  |
| 30 | `MovieClipLoader-v7` | 118 | 118 | 3.1s |  |
| 31 | `MovieClipLoader-v8` | 118 | 118 | 2.0s |  |
| 32 | `NetConnection-v6` | 4 | 49 | 3.5s |  |
| 33 | `NetConnection-v7` | 4 | 45 | 3.6s |  |
| 34 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 35 | `Object-v6` | 8 | 21 | 10.5s |  |
| 36 | `Object-v7` | 8 | 12 | 10.8s |  |
| 37 | `Object-v8` | 8 | 12 | 1.7s |  |
| 38 | `Sound-v5` | 14 | 16 | 4.8s |  |
| 39 | `Stage-v6` | 14 | 14 | 2.3s |  |
| 40 | `Stage-v7` | 14 | 14 | 2.1s |  |
| 41 | `Stage-v8` | 14 | 14 | 1.2s |  |
| 42 | `String-v5` | 8 | 21 | 12.2s |  |
| 43 | `TextField-v6` | 15 | 57 | 20.4s |  |
| 44 | `TextField-v7` | 15 | 73 | 22.4s |  |
| 45 | `TextField-v8` | 14 | 72 | 23.0s |  |
| 46 | `TextFormat-v7` | 38 | 38 | 6.2s |  |
| 47 | `TextFormat-v8` | 36 | 36 | 6.2s |  |
| 48 | `Transform-v8` | 7 | 7 | 3.7s |  |
| 49 | `XML-v5` | 9 | 79 | 10.6s |  |
| 50 | `XML-v8` | 21 | 116 | 3.5s |  |
| 51 | `array-v5` | 5 | 17 | 43.2s |  |
| 52 | `array-v6` | 6 | 25 | 29.1s |  |
| 53 | `array-v7` | 5 | 23 | 30.4s |  |
| 54 | `array-v8` | 5 | 23 | 2.7s |  |
| 55 | `setProperty-v5` | 49 | 49 | 2.9s |  |
| 56 | `setProperty-v6` | 49 | 49 | 2.9s |  |
| 57 | `setProperty-v7` | 49 | 49 | 2.5s |  |
| 58 | `setProperty-v8` | 49 | 49 | 1.8s |  |
| 59 | `toString_valueOf-v5` | 12 | 34 | 4.2s |  |

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
