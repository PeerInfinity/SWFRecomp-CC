# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-28 17:54 UTC

**Git SHA**: `d387fcee5b`

**Run Duration**: 21m 57s

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
| 1 | `Accessibility-v5` | 15 | 2.4s |  |
| 2 | `Accessibility-v6` | 19 | 2.4s |  |
| 3 | `Accessibility-v7` | 19 | 2.2s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.3s |  |
| 6 | `AsBroadcaster-v6` | 121 | 7.6s |  |
| 7 | `AsBroadcaster-v7` | 121 | 6.2s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.9s |  |
| 9 | `BitmapData-v5` | 7 | 3.3s |  |
| 10 | `BitmapData-v6` | 7 | 1.6s |  |
| 11 | `BitmapData-v7` | 7 | 3.0s |  |
| 12 | `Boolean-v5` | 38 | 3.9s |  |
| 13 | `Boolean-v6` | 38 | 3.3s |  |
| 14 | `Boolean-v7` | 38 | 4.0s |  |
| 15 | `Boolean-v8` | 38 | 2.8s |  |
| 16 | `Camera-v5` | 7 | 3.4s |  |
| 17 | `Color-v5` | 140 | 7.2s |  |
| 18 | `Color-v6` | 171 | 8.3s |  |
| 19 | `Color-v7` | 161 | 7.9s |  |
| 20 | `Color-v8` | 161 | 5.8s |  |
| 21 | `ColorTransform-v5` | 7 | 2.4s |  |
| 22 | `ColorTransform-v6` | 7 | 1.2s |  |
| 23 | `ColorTransform-v7` | 7 | 2.1s |  |
| 24 | `ColorTransform-v8` | 55 | 3.2s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 1.1s |  |
| 27 | `ContextMenu-v7` | 131 | 4.7s |  |
| 28 | `ContextMenu-v8` | 131 | 4.8s |  |
| 29 | `Error-v5` | 28 | 2.7s |  |
| 30 | `Error-v6` | 31 | 2.7s |  |
| 31 | `Error-v7` | 31 | 2.4s |  |
| 32 | `Error-v8` | 31 | 2.6s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.2s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.8s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `ExternalInterface-v8` | 118 | 4.2s |  |
| 37 | `Function-v6` | 271 | 7.8s |  |
| 38 | `Function-v7` | 272 | 8.1s |  |
| 39 | `Function-v8` | 272 | 8.9s |  |
| 40 | `Global-v5` | 172 | 6.6s |  |
| 41 | `Global-v6` | 210 | 7.7s |  |
| 42 | `Global-v7` | 182 | 6.7s |  |
| 43 | `Global-v8` | 169 | 6.2s |  |
| 44 | `HitTest-v6` | 88 | 4.7s |  |
| 45 | `HitTest-v7` | 88 | 4.4s |  |
| 46 | `Instance-v5` | 52 | 2.9s |  |
| 47 | `Instance-v6` | 52 | 1.8s |  |
| 48 | `Instance-v7` | 52 | 2.6s |  |
| 49 | `Instance-v8` | 52 | 1.8s |  |
| 50 | `Key-v5` | 51 | 3.0s |  |
| 51 | `Key-v6` | 55 | 3.0s |  |
| 52 | `Key-v7` | 55 | 2.7s |  |
| 53 | `Key-v8` | 55 | 1.9s |  |
| 54 | `LoadVars-v5` | 8 | 2.3s |  |
| 55 | `LoadVars-v6` | 152 | 5.0s |  |
| 56 | `LoadVars-v7` | 152 | 4.9s |  |
| 57 | `LoadVars-v8` | 152 | 2.6s |  |
| 58 | `LocalConnection-v5` | 7 | 2.3s |  |
| 59 | `LocalConnection-v6` | 58 | 3.2s |  |
| 60 | `LocalConnection-v7` | 58 | 2.9s |  |
| 61 | `LocalConnection-v8` | 58 | 1.9s |  |
| 62 | `Matrix-v5` | 7 | 2.9s |  |
| 63 | `Matrix-v6` | 168 | 8.5s |  |
| 64 | `Matrix-v7` | 168 | 8.5s |  |
| 65 | `Matrix-v8` | 168 | 2.6s |  |
| 66 | `Microphone-v5` | 6 | 2.9s |  |
| 67 | `Mouse-v5` | 13 | 2.3s |  |
| 68 | `Mouse-v6` | 21 | 2.4s |  |
| 69 | `Mouse-v7` | 21 | 2.1s |  |
| 70 | `Mouse-v8` | 21 | 1.8s |  |
| 71 | `MovieClip-v5` | 363 | 11.5s |  |
| 72 | `MovieClip-v6` | 936 | 40.1s |  |
| 73 | `MovieClip-v7` | 969 | 42.7s |  |
| 74 | `MovieClip-v8` | 1087 | 55.0s |  |
| 75 | `MovieClipLoader-v5` | 6 | 3.1s |  |
| 76 | `MovieClipLoader-v6` | 6 | 1.5s |  |
| 77 | `NetConnection-v5` | 7 | 3.0s |  |
| 78 | `NetStream-v5` | 6 | 2.3s |  |
| 79 | `NetStream-v6` | 80 | 3.6s |  |
| 80 | `NetStream-v7` | 80 | 3.4s |  |
| 81 | `NetStream-v8` | 80 | 2.0s |  |
| 82 | `Number-v5` | 244 | 8.7s |  |
| 83 | `Number-v6` | 239 | 8.5s |  |
| 84 | `Number-v7` | 237 | 8.3s |  |
| 85 | `Number-v8` | 237 | 2.1s |  |
| 86 | `Object-v5` | 145 | 5.6s |  |
| 87 | `Object-v6` | 333 | 12.0s |  |
| 88 | `Object-v7` | 333 | 12.5s |  |
| 89 | `Object-v8` | 333 | 2.7s |  |
| 90 | `Point-v5` | 7 | 2.5s |  |
| 91 | `Point-v6` | 7 | 1.3s |  |
| 92 | `Point-v7` | 7 | 2.2s |  |
| 93 | `Point-v8` | 193 | 7.7s |  |
| 94 | `Random-v5` | 30 | 4.2s |  |
| 95 | `Random-v6` | 30 | 1.5s |  |
| 96 | `Random-v7` | 30 | 3.2s |  |
| 97 | `Random-v8` | 30 | 2.5s |  |
| 98 | `Rectangle-v5` | 7 | 3.0s |  |
| 99 | `Rectangle-v6` | 7 | 1.5s |  |
| 100 | `Rectangle-v7` | 7 | 2.7s |  |
| 101 | `Rectangle-v8` | 166 | 8.3s |  |
| 102 | `Selection-v5` | 21 | 3.6s |  |
| 103 | `Selection-v6` | 125 | 6.9s |  |
| 104 | `Selection-v7` | 125 | 6.4s |  |
| 105 | `Selection-v8` | 125 | 2.9s |  |
| 106 | `Sound-v5` | 100 | 6.7s |  |
| 107 | `Sound-v6` | 121 | 7.2s |  |
| 108 | `Sound-v7` | 121 | 6.5s |  |
| 109 | `Sound-v8` | 121 | 3.3s |  |
| 110 | `Stage-v5` | 38 | 4.0s |  |
| 111 | `String-v6` | 377 | 19.5s |  |
| 112 | `String-v7` | 377 | 19.7s |  |
| 113 | `String-v8` | 377 | 3.4s |  |
| 114 | `System-v5` | 67 | 3.3s |  |
| 115 | `System-v6` | 100 | 4.0s |  |
| 116 | `System-v7` | 101 | 3.9s |  |
| 117 | `System-v8` | 101 | 1.9s |  |
| 118 | `TextField-v5` | 12 | 2.3s |  |
| 119 | `TextFieldHTML-v5` | 6 | 2.3s |  |
| 120 | `TextFieldHTML-v6` | 37 | 2.8s |  |
| 121 | `TextFieldHTML-v7` | 37 | 2.6s |  |
| 122 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 123 | `TextFormat-v5` | 128 | 4.7s |  |
| 124 | `TextFormat-v6` | 128 | 1.2s |  |
| 125 | `TextSnapshot-v5` | 7 | 2.5s |  |
| 126 | `TextSnapshot-v6` | 173 | 6.0s |  |
| 127 | `TextSnapshot-v7` | 173 | 5.8s |  |
| 128 | `TextSnapshot-v8` | 173 | 1.9s |  |
| 129 | `Transform-v5` | 7 | 2.1s |  |
| 130 | `Transform-v6` | 7 | 1.8s |  |
| 131 | `Transform-v7` | 7 | 1.9s |  |
| 132 | `Try-v5` | 20 | 2.8s |  |
| 133 | `Try-v6` | 20 | 1.1s |  |
| 134 | `Try-v7` | 20 | 2.6s |  |
| 135 | `Try-v8` | 20 | 2.0s |  |
| 136 | `Video-v5` | 7 | 2.4s |  |
| 137 | `Video-v6` | 85 | 3.8s |  |
| 138 | `Video-v7` | 85 | 3.6s |  |
| 139 | `Video-v8` | 85 | 2.1s |  |
| 140 | `XML-v6` | 486 | 13.6s |  |
| 141 | `XML-v7` | 486 | 13.7s |  |
| 142 | `XMLNode-v5` | 207 | 7.8s |  |
| 143 | `XMLNode-v6` | 207 | 7.7s |  |
| 144 | `XMLNode-v7` | 207 | 6.8s |  |
| 145 | `XMLNode-v8` | 207 | 2.1s |  |
| 146 | `XMLSocket-v5` | 35 | 2.8s |  |
| 147 | `XMLSocket-v6` | 35 | 2.8s |  |
| 148 | `XMLSocket-v7` | 35 | 2.5s |  |
| 149 | `XMLSocket-v8` | 35 | 2.0s |  |
| 150 | `argstest-v5` | 4 | 2.4s |  |
| 151 | `case-v5` | 39 | 2.7s |  |
| 152 | `case-v6` | 73 | 3.4s |  |
| 153 | `case-v7` | 67 | 3.3s |  |
| 154 | `case-v8` | 67 | 1.9s |  |
| 155 | `delete-v5` | 61 | 4.5s |  |
| 156 | `delete-v6` | 61 | 3.9s |  |
| 157 | `delete-v7` | 61 | 4.1s |  |
| 158 | `delete-v8` | 61 | 3.0s |  |
| 159 | `enumerate-v5` | 6 | 3.3s |  |
| 160 | `enumerate-v6` | 49 | 4.4s |  |
| 161 | `enumerate-v7` | 49 | 4.1s |  |
| 162 | `enumerate-v8` | 49 | 2.8s |  |
| 163 | `flash-v5` | 10 | 1.9s |  |
| 164 | `flash-v6` | 10 | 1.9s |  |
| 165 | `flash-v7` | 10 | 1.9s |  |
| 166 | `flash-v8` | 41 | 1.9s |  |
| 167 | `getvariable-v5` | 58 | 1.9s |  |
| 168 | `getvariable-v6` | 64 | 2.0s |  |
| 169 | `getvariable-v7` | 64 | 2.4s |  |
| 170 | `getvariable-v8` | 64 | 2.0s |  |
| 171 | `ops-v5` | 260 | 1.2s |  |
| 172 | `ops-v6` | 260 | 1.2s |  |
| 173 | `ops-v7` | 262 | 1.2s |  |
| 174 | `ops-v8` | 262 | 1.1s |  |
| 175 | `setProperty-v5` | 52 | 1.1s |  |
| 176 | `setProperty-v6` | 52 | 1.1s |  |
| 177 | `setProperty-v7` | 52 | 1.1s |  |
| 178 | `setProperty-v8` | 52 | 1.1s |  |
| 179 | `swap-v5` | 7 | 2.4s |  |
| 180 | `swap-v6` | 7 | 1.2s |  |
| 181 | `swap-v7` | 7 | 2.0s |  |
| 182 | `swap-v8` | 7 | 1.9s |  |
| 183 | `targetPath-v5` | 12 | 2.4s |  |
| 184 | `targetPath-v6` | 23 | 2.5s |  |
| 185 | `targetPath-v7` | 23 | 2.3s |  |
| 186 | `targetPath-v8` | 23 | 1.9s |  |
| 187 | `toString_valueOf-v6` | 155 | 4.7s |  |
| 188 | `toString_valueOf-v7` | 155 | 4.4s |  |
| 189 | `toString_valueOf-v8` | 155 | 1.9s |  |
| 190 | `with-v5` | 49 | 3.3s |  |
| 191 | `with-v6` | 107 | 4.1s |  |
| 192 | `with-v7` | 107 | 3.9s |  |
| 193 | `with-v8` | 107 | 2.1s |  |

## Ruffle-Matched Tests

**47 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 4.9s |  |
| 2 | `ASnative-v6` | 39 | 40 | 5.0s |  |
| 3 | `ASnative-v7` | 39 | 40 | 4.9s |  |
| 4 | `ASnative-v8` | 39 | 40 | 2.0s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 51.1s |  |
| 6 | `Camera-v6` | 57 | 57 | 5.7s |  |
| 7 | `Camera-v7` | 57 | 57 | 5.3s |  |
| 8 | `Camera-v8` | 57 | 57 | 3.0s |  |
| 9 | `Date-v5` | 6 | 7 | 12.2s |  |
| 10 | `Date-v6` | 6 | 6 | 13.5s |  |
| 11 | `Date-v7` | 6 | 6 | 14.2s |  |
| 12 | `Date-v8` | 6 | 6 | 2.3s |  |
| 13 | `Function-v5` | 4 | 25 | 4.9s |  |
| 14 | `HitTest-v8` | 3 | 9 | 4.4s |  |
| 15 | `Inheritance-v5` | 1 | 17 | 4.1s |  |
| 16 | `Inheritance-v6` | 9 | 13 | 5.4s |  |
| 17 | `Inheritance-v7` | 5 | 7 | 5.5s |  |
| 18 | `Inheritance-v8` | 5 | 7 | 2.2s |  |
| 19 | `Math-v5` | 5 | 5 | 12.7s |  |
| 20 | `Math-v6` | 5 | 5 | 1.3s |  |
| 21 | `Math-v7` | 5 | 5 | 13.1s |  |
| 22 | `Math-v8` | 5 | 5 | 2.1s |  |
| 23 | `Microphone-v6` | 31 | 31 | 4.6s |  |
| 24 | `Microphone-v7` | 31 | 31 | 4.2s |  |
| 25 | `Microphone-v8` | 31 | 31 | 2.8s |  |
| 26 | `MovieClipLoader-v7` | 118 | 118 | 5.1s |  |
| 27 | `MovieClipLoader-v8` | 118 | 118 | 3.6s |  |
| 28 | `NetConnection-v6` | 4 | 49 | 6.2s |  |
| 29 | `NetConnection-v7` | 4 | 45 | 6.5s |  |
| 30 | `NetConnection-v8` | 4 | 45 | 2.7s |  |
| 31 | `Stage-v6` | 14 | 14 | 4.6s |  |
| 32 | `Stage-v7` | 14 | 14 | 4.2s |  |
| 33 | `Stage-v8` | 14 | 14 | 2.9s |  |
| 34 | `String-v5` | 8 | 21 | 18.4s |  |
| 35 | `TextField-v6` | 15 | 57 | 19.9s |  |
| 36 | `TextField-v7` | 15 | 73 | 21.6s |  |
| 37 | `TextField-v8` | 14 | 72 | 21.7s |  |
| 38 | `TextFormat-v7` | 38 | 38 | 6.4s |  |
| 39 | `TextFormat-v8` | 36 | 36 | 6.4s |  |
| 40 | `Transform-v8` | 7 | 7 | 4.2s |  |
| 41 | `XML-v5` | 9 | 79 | 12.4s |  |
| 42 | `XML-v8` | 21 | 116 | 4.5s |  |
| 43 | `array-v5` | 5 | 17 | 23.5s |  |
| 44 | `array-v6` | 6 | 25 | 27.6s |  |
| 45 | `array-v7` | 5 | 23 | 28.5s |  |
| 46 | `array-v8` | 5 | 23 | 3.1s |  |
| 47 | `toString_valueOf-v5` | 12 | 34 | 5.0s |  |

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
