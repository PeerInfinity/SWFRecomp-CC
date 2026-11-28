# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 16:53 UTC

**Git SHA**: `d81f64081e`

**Run Duration**: 21m 23s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **193** (79.4%) |
| Ruffle-matched | 47 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (98.8%) |
| Failing | 3 |
| Total expected lines | 38791 |
| Matching lines | 31367 (80.9%) |
| Mismatched lines | 7424 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**193 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.5s |  |
| 2 | `Accessibility-v6` | 19 | 3.5s |  |
| 3 | `Accessibility-v7` | 19 | 3.2s |  |
| 4 | `Accessibility-v8` | 19 | 2.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.4s |  |
| 6 | `AsBroadcaster-v6` | 121 | 5.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.5s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.0s |  |
| 9 | `BitmapData-v5` | 7 | 2.3s |  |
| 10 | `BitmapData-v6` | 7 | 1.2s |  |
| 11 | `BitmapData-v7` | 7 | 2.0s |  |
| 12 | `Boolean-v5` | 38 | 2.8s |  |
| 13 | `Boolean-v6` | 38 | 2.4s |  |
| 14 | `Boolean-v7` | 38 | 2.7s |  |
| 15 | `Boolean-v8` | 38 | 1.8s |  |
| 16 | `Camera-v5` | 7 | 2.2s |  |
| 17 | `Color-v5` | 140 | 4.8s |  |
| 18 | `Color-v6` | 171 | 5.8s |  |
| 19 | `Color-v7` | 161 | 5.5s |  |
| 20 | `Color-v8` | 161 | 6.2s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 1.1s |  |
| 23 | `ColorTransform-v7` | 7 | 2.1s |  |
| 24 | `ColorTransform-v8` | 55 | 3.3s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 1.1s |  |
| 27 | `ContextMenu-v7` | 131 | 4.6s |  |
| 28 | `ContextMenu-v8` | 131 | 5.5s |  |
| 29 | `Error-v5` | 28 | 3.1s |  |
| 30 | `Error-v6` | 31 | 3.5s |  |
| 31 | `Error-v7` | 31 | 3.0s |  |
| 32 | `Error-v8` | 31 | 3.4s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.9s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.8s |  |
| 35 | `ExternalInterface-v7` | 55 | 3.5s |  |
| 36 | `ExternalInterface-v8` | 118 | 6.0s |  |
| 37 | `Function-v6` | 271 | 10.6s |  |
| 38 | `Function-v7` | 272 | 10.8s |  |
| 39 | `Function-v8` | 272 | 7.5s |  |
| 40 | `Global-v5` | 172 | 5.5s |  |
| 41 | `Global-v6` | 210 | 6.5s |  |
| 42 | `Global-v7` | 182 | 5.7s |  |
| 43 | `Global-v8` | 169 | 5.4s |  |
| 44 | `HitTest-v6` | 88 | 4.2s |  |
| 45 | `HitTest-v7` | 88 | 4.0s |  |
| 46 | `Instance-v5` | 52 | 3.0s |  |
| 47 | `Instance-v6` | 52 | 1.9s |  |
| 48 | `Instance-v7` | 52 | 2.8s |  |
| 49 | `Instance-v8` | 52 | 1.9s |  |
| 50 | `Key-v5` | 51 | 3.0s |  |
| 51 | `Key-v6` | 55 | 3.0s |  |
| 52 | `Key-v7` | 55 | 2.8s |  |
| 53 | `Key-v8` | 55 | 1.9s |  |
| 54 | `LoadVars-v5` | 8 | 2.3s |  |
| 55 | `LoadVars-v6` | 152 | 5.1s |  |
| 56 | `LoadVars-v7` | 152 | 4.9s |  |
| 57 | `LoadVars-v8` | 152 | 2.6s |  |
| 58 | `LocalConnection-v5` | 7 | 2.3s |  |
| 59 | `LocalConnection-v6` | 58 | 3.1s |  |
| 60 | `LocalConnection-v7` | 58 | 2.9s |  |
| 61 | `LocalConnection-v8` | 58 | 1.9s |  |
| 62 | `Matrix-v5` | 7 | 2.3s |  |
| 63 | `Matrix-v6` | 168 | 6.4s |  |
| 64 | `Matrix-v7` | 168 | 6.5s |  |
| 65 | `Matrix-v8` | 168 | 1.9s |  |
| 66 | `Microphone-v5` | 6 | 2.2s |  |
| 67 | `Mouse-v5` | 13 | 2.4s |  |
| 68 | `Mouse-v6` | 21 | 2.5s |  |
| 69 | `Mouse-v7` | 21 | 2.2s |  |
| 70 | `Mouse-v8` | 21 | 1.9s |  |
| 71 | `MovieClip-v5` | 363 | 12.0s |  |
| 72 | `MovieClip-v6` | 936 | 40.0s |  |
| 73 | `MovieClip-v7` | 969 | 42.1s |  |
| 74 | `MovieClip-v8` | 1087 | 53.2s |  |
| 75 | `MovieClipLoader-v5` | 6 | 2.5s |  |
| 76 | `MovieClipLoader-v6` | 6 | 1.2s |  |
| 77 | `NetConnection-v5` | 7 | 2.4s |  |
| 78 | `NetStream-v5` | 6 | 2.2s |  |
| 79 | `NetStream-v6` | 80 | 3.5s |  |
| 80 | `NetStream-v7` | 80 | 3.2s |  |
| 81 | `NetStream-v8` | 80 | 1.9s |  |
| 82 | `Number-v5` | 244 | 8.2s |  |
| 83 | `Number-v6` | 239 | 7.8s |  |
| 84 | `Number-v7` | 237 | 7.8s |  |
| 85 | `Number-v8` | 237 | 2.0s |  |
| 86 | `Object-v5` | 145 | 6.5s |  |
| 87 | `Object-v6` | 333 | 13.1s |  |
| 88 | `Object-v7` | 333 | 13.2s |  |
| 89 | `Object-v8` | 333 | 3.0s |  |
| 90 | `Point-v5` | 7 | 2.8s |  |
| 91 | `Point-v6` | 7 | 1.4s |  |
| 92 | `Point-v7` | 7 | 2.5s |  |
| 93 | `Point-v8` | 193 | 8.6s |  |
| 94 | `Random-v5` | 30 | 3.3s |  |
| 95 | `Random-v6` | 30 | 1.3s |  |
| 96 | `Random-v7` | 30 | 2.8s |  |
| 97 | `Random-v8` | 30 | 2.2s |  |
| 98 | `Rectangle-v5` | 7 | 2.6s |  |
| 99 | `Rectangle-v6` | 7 | 1.2s |  |
| 100 | `Rectangle-v7` | 7 | 2.4s |  |
| 101 | `Rectangle-v8` | 166 | 7.2s |  |
| 102 | `Selection-v5` | 21 | 2.4s |  |
| 103 | `Selection-v6` | 125 | 4.7s |  |
| 104 | `Selection-v7` | 125 | 4.4s |  |
| 105 | `Selection-v8` | 125 | 1.9s |  |
| 106 | `Sound-v5` | 100 | 4.5s |  |
| 107 | `Sound-v6` | 121 | 4.8s |  |
| 108 | `Sound-v7` | 121 | 4.4s |  |
| 109 | `Sound-v8` | 121 | 2.2s |  |
| 110 | `Stage-v5` | 38 | 2.7s |  |
| 111 | `String-v6` | 377 | 14.1s |  |
| 112 | `String-v7` | 377 | 13.6s |  |
| 113 | `String-v8` | 377 | 2.1s |  |
| 114 | `System-v5` | 67 | 3.1s |  |
| 115 | `System-v6` | 100 | 3.8s |  |
| 116 | `System-v7` | 101 | 3.8s |  |
| 117 | `System-v8` | 101 | 1.9s |  |
| 118 | `TextField-v5` | 12 | 2.3s |  |
| 119 | `TextFieldHTML-v5` | 6 | 2.4s |  |
| 120 | `TextFieldHTML-v6` | 37 | 2.9s |  |
| 121 | `TextFieldHTML-v7` | 37 | 2.7s |  |
| 122 | `TextFieldHTML-v8` | 37 | 2.0s |  |
| 123 | `TextFormat-v5` | 128 | 5.0s |  |
| 124 | `TextFormat-v6` | 128 | 1.2s |  |
| 125 | `TextSnapshot-v5` | 7 | 3.2s |  |
| 126 | `TextSnapshot-v6` | 173 | 8.6s |  |
| 127 | `TextSnapshot-v7` | 173 | 8.2s |  |
| 128 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 129 | `Transform-v5` | 7 | 2.9s |  |
| 130 | `Transform-v6` | 7 | 2.5s |  |
| 131 | `Transform-v7` | 7 | 2.8s |  |
| 132 | `Try-v5` | 20 | 2.9s |  |
| 133 | `Try-v6` | 20 | 1.2s |  |
| 134 | `Try-v7` | 20 | 2.8s |  |
| 135 | `Try-v8` | 20 | 2.1s |  |
| 136 | `Video-v5` | 7 | 2.6s |  |
| 137 | `Video-v6` | 85 | 4.2s |  |
| 138 | `Video-v7` | 85 | 3.8s |  |
| 139 | `Video-v8` | 85 | 2.2s |  |
| 140 | `XML-v6` | 486 | 13.0s |  |
| 141 | `XML-v7` | 486 | 12.8s |  |
| 142 | `XMLNode-v5` | 207 | 6.9s |  |
| 143 | `XMLNode-v6` | 207 | 7.0s |  |
| 144 | `XMLNode-v7` | 207 | 6.3s |  |
| 145 | `XMLNode-v8` | 207 | 2.0s |  |
| 146 | `XMLSocket-v5` | 35 | 2.8s |  |
| 147 | `XMLSocket-v6` | 35 | 2.8s |  |
| 148 | `XMLSocket-v7` | 35 | 2.6s |  |
| 149 | `XMLSocket-v8` | 35 | 2.0s |  |
| 150 | `argstest-v5` | 4 | 2.5s |  |
| 151 | `case-v5` | 39 | 3.6s |  |
| 152 | `case-v6` | 73 | 4.5s |  |
| 153 | `case-v7` | 67 | 4.4s |  |
| 154 | `case-v8` | 67 | 2.7s |  |
| 155 | `delete-v5` | 61 | 3.0s |  |
| 156 | `delete-v6` | 61 | 2.6s |  |
| 157 | `delete-v7` | 61 | 2.8s |  |
| 158 | `delete-v8` | 61 | 1.9s |  |
| 159 | `enumerate-v5` | 6 | 2.2s |  |
| 160 | `enumerate-v6` | 49 | 3.0s |  |
| 161 | `enumerate-v7` | 49 | 2.7s |  |
| 162 | `enumerate-v8` | 49 | 1.8s |  |
| 163 | `flash-v5` | 10 | 2.2s |  |
| 164 | `flash-v6` | 10 | 2.1s |  |
| 165 | `flash-v7` | 10 | 2.1s |  |
| 166 | `flash-v8` | 41 | 2.2s |  |
| 167 | `getvariable-v5` | 58 | 2.1s |  |
| 168 | `getvariable-v6` | 64 | 2.1s |  |
| 169 | `getvariable-v7` | 64 | 2.1s |  |
| 170 | `getvariable-v8` | 64 | 2.2s |  |
| 171 | `ops-v5` | 260 | 2.3s |  |
| 172 | `ops-v6` | 260 | 2.2s |  |
| 173 | `ops-v7` | 262 | 2.3s |  |
| 174 | `ops-v8` | 262 | 2.2s |  |
| 175 | `setProperty-v5` | 52 | 2.0s |  |
| 176 | `setProperty-v6` | 52 | 2.0s |  |
| 177 | `setProperty-v7` | 52 | 2.0s |  |
| 178 | `setProperty-v8` | 52 | 2.0s |  |
| 179 | `swap-v5` | 7 | 2.8s |  |
| 180 | `swap-v6` | 7 | 1.4s |  |
| 181 | `swap-v7` | 7 | 2.5s |  |
| 182 | `swap-v8` | 7 | 2.3s |  |
| 183 | `targetPath-v5` | 12 | 2.8s |  |
| 184 | `targetPath-v6` | 23 | 3.0s |  |
| 185 | `targetPath-v7` | 23 | 2.7s |  |
| 186 | `targetPath-v8` | 23 | 2.5s |  |
| 187 | `toString_valueOf-v6` | 155 | 5.3s |  |
| 188 | `toString_valueOf-v7` | 155 | 5.1s |  |
| 189 | `toString_valueOf-v8` | 155 | 2.0s |  |
| 190 | `with-v5` | 49 | 3.6s |  |
| 191 | `with-v6` | 107 | 4.7s |  |
| 192 | `with-v7` | 107 | 4.2s |  |
| 193 | `with-v8` | 107 | 2.2s |  |

## Ruffle-Matched Tests

**47 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 7.2s |  |
| 2 | `ASnative-v6` | 39 | 40 | 7.5s |  |
| 3 | `ASnative-v7` | 39 | 40 | 6.9s |  |
| 4 | `ASnative-v8` | 39 | 40 | 3.0s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 40.5s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.8s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.6s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.9s |  |
| 9 | `Date-v5` | 6 | 7 | 13.9s |  |
| 10 | `Date-v6` | 6 | 6 | 15.7s |  |
| 11 | `Date-v7` | 6 | 6 | 15.6s |  |
| 12 | `Date-v8` | 6 | 6 | 2.9s |  |
| 13 | `Function-v5` | 4 | 25 | 6.9s |  |
| 14 | `HitTest-v8` | 3 | 9 | 3.9s |  |
| 15 | `Inheritance-v5` | 1 | 17 | 4.4s |  |
| 16 | `Inheritance-v6` | 9 | 13 | 6.0s |  |
| 17 | `Inheritance-v7` | 5 | 7 | 6.1s |  |
| 18 | `Inheritance-v8` | 5 | 7 | 2.3s |  |
| 19 | `Math-v5` | 5 | 5 | 11.9s |  |
| 20 | `Math-v6` | 5 | 5 | 1.3s |  |
| 21 | `Math-v7` | 5 | 5 | 12.1s |  |
| 22 | `Math-v8` | 5 | 5 | 2.0s |  |
| 23 | `Microphone-v6` | 31 | 31 | 3.4s |  |
| 24 | `Microphone-v7` | 31 | 31 | 3.2s |  |
| 25 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 26 | `MovieClipLoader-v7` | 118 | 118 | 4.1s |  |
| 27 | `MovieClipLoader-v8` | 118 | 118 | 2.9s |  |
| 28 | `NetConnection-v6` | 4 | 49 | 5.0s |  |
| 29 | `NetConnection-v7` | 4 | 45 | 5.0s |  |
| 30 | `NetConnection-v8` | 4 | 45 | 2.1s |  |
| 31 | `Stage-v6` | 14 | 14 | 3.1s |  |
| 32 | `Stage-v7` | 14 | 14 | 2.8s |  |
| 33 | `Stage-v8` | 14 | 14 | 1.9s |  |
| 34 | `String-v5` | 8 | 21 | 13.1s |  |
| 35 | `TextField-v6` | 15 | 57 | 19.8s |  |
| 36 | `TextField-v7` | 15 | 73 | 20.3s |  |
| 37 | `TextField-v8` | 14 | 72 | 20.8s |  |
| 38 | `TextFormat-v7` | 38 | 38 | 6.5s |  |
| 39 | `TextFormat-v8` | 36 | 36 | 6.5s |  |
| 40 | `Transform-v8` | 7 | 7 | 6.0s |  |
| 41 | `XML-v5` | 9 | 79 | 11.4s |  |
| 42 | `XML-v8` | 21 | 116 | 4.1s |  |
| 43 | `array-v5` | 5 | 17 | 27.9s |  |
| 44 | `array-v6` | 6 | 25 | 32.5s |  |
| 45 | `array-v7` | 5 | 23 | 33.2s |  |
| 46 | `array-v8` | 5 | 23 | 4.0s |  |
| 47 | `toString_valueOf-v5` | 12 | 34 | 5.6s |  |

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
