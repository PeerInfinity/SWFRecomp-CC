# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-25 21:42 UTC

**Git SHA**: `10a5b515a0`

**Run Duration**: 28m 41s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **167** (68.7%) |
| Ruffle-matched | 68 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **235** (96.7%) |
| Failing | 8 |
| Total expected lines | 38791 |
| Matching lines | 30990 (79.9%) |
| Mismatched lines | 7801 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 8 | 100.0% |

## Passing Tests

**167 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.3s |  |
| 2 | `Accessibility-v6` | 19 | 2.4s |  |
| 3 | `Accessibility-v7` | 19 | 2.1s |  |
| 4 | `Accessibility-v8` | 19 | 1.8s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.2s |  |
| 6 | `AsBroadcaster-v6` | 121 | 22.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 5.2s |  |
| 8 | `AsBroadcaster-v8` | 121 | 2.2s |  |
| 9 | `BitmapData-v5` | 7 | 2.4s |  |
| 10 | `BitmapData-v6` | 7 | 1.2s |  |
| 11 | `BitmapData-v7` | 7 | 2.2s |  |
| 12 | `Boolean-v5` | 38 | 2.8s |  |
| 13 | `Boolean-v6` | 38 | 2.4s |  |
| 14 | `Boolean-v7` | 38 | 2.7s |  |
| 15 | `Boolean-v8` | 38 | 1.8s |  |
| 16 | `Camera-v5` | 7 | 2.2s |  |
| 17 | `Color-v5` | 140 | 4.5s |  |
| 18 | `Color-v6` | 171 | 5.2s |  |
| 19 | `Color-v7` | 161 | 5.0s |  |
| 20 | `Color-v8` | 161 | 23.9s |  |
| 21 | `ColorTransform-v5` | 7 | 2.3s |  |
| 22 | `ColorTransform-v6` | 7 | 1.2s |  |
| 23 | `ColorTransform-v7` | 7 | 2.0s |  |
| 24 | `ColorTransform-v8` | 55 | 3.3s |  |
| 25 | `ContextMenu-v5` | 7 | 2.3s |  |
| 26 | `ContextMenu-v6` | 7 | 1.1s |  |
| 27 | `ContextMenu-v7` | 131 | 4.5s |  |
| 28 | `ContextMenu-v8` | 131 | 22.6s |  |
| 29 | `Error-v5` | 28 | 2.5s |  |
| 30 | `Error-v6` | 31 | 2.6s |  |
| 31 | `Error-v7` | 31 | 2.3s |  |
| 32 | `Error-v8` | 31 | 19.6s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.2s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.8s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `Function-v6` | 271 | 7.5s |  |
| 37 | `Function-v7` | 272 | 7.7s |  |
| 38 | `Function-v8` | 272 | 8.7s |  |
| 39 | `Global-v5` | 172 | 6.7s |  |
| 40 | `Global-v7` | 182 | 6.6s |  |
| 41 | `Global-v8` | 169 | 6.4s |  |
| 42 | `HitTest-v6` | 88 | 4.7s |  |
| 43 | `HitTest-v7` | 88 | 4.7s |  |
| 44 | `Instance-v5` | 52 | 4.3s |  |
| 45 | `Instance-v6` | 52 | 2.7s |  |
| 46 | `Instance-v7` | 52 | 3.9s |  |
| 47 | `Instance-v8` | 52 | 2.8s |  |
| 48 | `Key-v5` | 51 | 20.2s |  |
| 49 | `Key-v6` | 55 | 2.9s |  |
| 50 | `Key-v7` | 55 | 2.7s |  |
| 51 | `Key-v8` | 55 | 1.9s |  |
| 52 | `LoadVars-v5` | 8 | 2.2s |  |
| 53 | `LocalConnection-v5` | 7 | 19.5s |  |
| 54 | `LocalConnection-v6` | 58 | 3.1s |  |
| 55 | `LocalConnection-v7` | 58 | 2.8s |  |
| 56 | `LocalConnection-v8` | 58 | 1.9s |  |
| 57 | `Matrix-v5` | 7 | 22.2s |  |
| 58 | `Matrix-v6` | 168 | 7.8s |  |
| 59 | `Matrix-v7` | 168 | 8.0s |  |
| 60 | `Matrix-v8` | 168 | 2.4s |  |
| 61 | `Microphone-v5` | 6 | 3.0s |  |
| 62 | `Mouse-v5` | 13 | 2.2s |  |
| 63 | `Mouse-v6` | 21 | 2.3s |  |
| 64 | `Mouse-v7` | 21 | 2.1s |  |
| 65 | `Mouse-v8` | 21 | 1.8s |  |
| 66 | `MovieClipLoader-v5` | 6 | 25.9s |  |
| 67 | `MovieClipLoader-v6` | 6 | 1.6s |  |
| 68 | `NetConnection-v5` | 7 | 3.3s |  |
| 69 | `NetStream-v5` | 6 | 19.7s |  |
| 70 | `NetStream-v6` | 80 | 3.4s |  |
| 71 | `NetStream-v7` | 80 | 3.2s |  |
| 72 | `NetStream-v8` | 80 | 1.9s |  |
| 73 | `Number-v6` | 239 | 7.5s |  |
| 74 | `Number-v7` | 237 | 7.6s |  |
| 75 | `Number-v8` | 237 | 2.0s |  |
| 76 | `Point-v5` | 7 | 2.2s |  |
| 77 | `Point-v6` | 7 | 1.1s |  |
| 78 | `Point-v7` | 7 | 2.0s |  |
| 79 | `Point-v8` | 193 | 7.0s |  |
| 80 | `Random-v5` | 30 | 3.8s |  |
| 81 | `Random-v6` | 30 | 1.6s |  |
| 82 | `Random-v7` | 30 | 3.4s |  |
| 83 | `Random-v8` | 30 | 2.7s |  |
| 84 | `Rectangle-v5` | 7 | 3.3s |  |
| 85 | `Rectangle-v6` | 7 | 1.6s |  |
| 86 | `Rectangle-v7` | 7 | 2.9s |  |
| 87 | `Rectangle-v8` | 166 | 8.2s |  |
| 88 | `Selection-v5` | 21 | 27.8s |  |
| 89 | `Sound-v6` | 121 | 7.6s |  |
| 90 | `Sound-v7` | 121 | 7.0s |  |
| 91 | `Sound-v8` | 121 | 3.5s |  |
| 92 | `Stage-v5` | 38 | 26.8s |  |
| 93 | `String-v6` | 377 | 19.0s |  |
| 94 | `String-v7` | 377 | 18.6s |  |
| 95 | `String-v8` | 377 | 3.3s |  |
| 96 | `System-v5` | 67 | 20.8s |  |
| 97 | `System-v6` | 100 | 3.8s |  |
| 98 | `System-v7` | 101 | 3.9s |  |
| 99 | `System-v8` | 101 | 1.9s |  |
| 100 | `TextField-v5` | 12 | 2.3s |  |
| 101 | `TextFieldHTML-v5` | 6 | 3.4s |  |
| 102 | `TextFieldHTML-v6` | 37 | 3.4s |  |
| 103 | `TextFieldHTML-v7` | 37 | 3.0s |  |
| 104 | `TextFieldHTML-v8` | 37 | 2.4s |  |
| 105 | `TextFormat-v5` | 128 | 5.6s |  |
| 106 | `TextFormat-v6` | 128 | 1.4s |  |
| 107 | `TextSnapshot-v5` | 7 | 3.6s |  |
| 108 | `TextSnapshot-v6` | 173 | 8.4s |  |
| 109 | `TextSnapshot-v7` | 173 | 8.1s |  |
| 110 | `TextSnapshot-v8` | 173 | 2.5s |  |
| 111 | `Transform-v5` | 7 | 2.9s |  |
| 112 | `Transform-v6` | 7 | 2.3s |  |
| 113 | `Transform-v7` | 7 | 2.5s |  |
| 114 | `Try-v5` | 20 | 21.4s |  |
| 115 | `Try-v6` | 20 | 1.4s |  |
| 116 | `Try-v7` | 20 | 3.1s |  |
| 117 | `Try-v8` | 20 | 2.5s |  |
| 118 | `Video-v5` | 7 | 3.0s |  |
| 119 | `Video-v6` | 85 | 4.2s |  |
| 120 | `Video-v7` | 85 | 4.0s |  |
| 121 | `Video-v8` | 85 | 2.3s |  |
| 122 | `XML-v6` | 486 | 12.4s |  |
| 123 | `XML-v7` | 486 | 12.2s |  |
| 124 | `XMLNode-v5` | 207 | 6.7s |  |
| 125 | `XMLNode-v6` | 207 | 6.7s |  |
| 126 | `XMLNode-v7` | 207 | 5.9s |  |
| 127 | `XMLNode-v8` | 207 | 2.0s |  |
| 128 | `XMLSocket-v5` | 35 | 19.9s |  |
| 129 | `XMLSocket-v6` | 35 | 2.7s |  |
| 130 | `XMLSocket-v7` | 35 | 2.5s |  |
| 131 | `XMLSocket-v8` | 35 | 1.9s |  |
| 132 | `argstest-v5` | 4 | 2.3s |  |
| 133 | `case-v5` | 39 | 2.9s |  |
| 134 | `case-v6` | 73 | 3.6s |  |
| 135 | `case-v7` | 67 | 3.6s |  |
| 136 | `case-v8` | 67 | 2.0s |  |
| 137 | `delete-v5` | 61 | 21.2s |  |
| 138 | `delete-v6` | 61 | 2.7s |  |
| 139 | `delete-v7` | 61 | 2.7s |  |
| 140 | `delete-v8` | 61 | 1.8s |  |
| 141 | `enumerate-v5` | 6 | 2.0s |  |
| 142 | `enumerate-v6` | 49 | 2.8s |  |
| 143 | `enumerate-v7` | 49 | 2.6s |  |
| 144 | `enumerate-v8` | 49 | 1.7s |  |
| 145 | `flash-v5` | 10 | 19.4s |  |
| 146 | `flash-v6` | 10 | 2.2s |  |
| 147 | `flash-v7` | 10 | 2.0s |  |
| 148 | `flash-v8` | 41 | 2.9s |  |
| 149 | `getvariable-v5` | 58 | 3.1s |  |
| 150 | `getvariable-v6` | 64 | 3.1s |  |
| 151 | `getvariable-v7` | 64 | 3.2s |  |
| 152 | `getvariable-v8` | 64 | 1.9s |  |
| 153 | `swap-v5` | 7 | 21.4s |  |
| 154 | `swap-v6` | 7 | 1.4s |  |
| 155 | `swap-v7` | 7 | 2.5s |  |
| 156 | `swap-v8` | 7 | 2.3s |  |
| 157 | `targetPath-v5` | 12 | 2.8s |  |
| 158 | `targetPath-v6` | 23 | 3.1s |  |
| 159 | `targetPath-v7` | 23 | 2.8s |  |
| 160 | `targetPath-v8` | 23 | 2.5s |  |
| 161 | `toString_valueOf-v6` | 155 | 6.3s |  |
| 162 | `toString_valueOf-v7` | 155 | 6.2s |  |
| 163 | `toString_valueOf-v8` | 155 | 2.5s |  |
| 164 | `with-v5` | 49 | 4.3s |  |
| 165 | `with-v6` | 107 | 5.5s |  |
| 166 | `with-v7` | 107 | 5.2s |  |
| 167 | `with-v8` | 107 | 2.6s |  |

## Ruffle-Matched Tests

**68 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapData-v8` | 8 | 8 | 22.2s |  |
| 2 | `Camera-v6` | 57 | 57 | 3.7s |  |
| 3 | `Camera-v7` | 57 | 57 | 3.4s |  |
| 4 | `Camera-v8` | 57 | 57 | 1.9s |  |
| 5 | `Date-v5` | 7 | 7 | 11.7s |  |
| 6 | `Date-v6` | 6 | 6 | 12.8s |  |
| 7 | `Date-v7` | 6 | 6 | 13.1s |  |
| 8 | `Date-v8` | 6 | 6 | 2.1s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 4.2s |  |
| 10 | `Function-v5` | 10 | 25 | 4.9s |  |
| 11 | `Global-v6` | 9 | 10 | 7.9s |  |
| 12 | `HitTest-v8` | 3 | 9 | 4.4s |  |
| 13 | `Inheritance-v5` | 1 | 17 | 28.6s |  |
| 14 | `Inheritance-v6` | 9 | 13 | 8.3s |  |
| 15 | `Inheritance-v7` | 5 | 7 | 8.4s |  |
| 16 | `Inheritance-v8` | 5 | 7 | 3.4s |  |
| 17 | `LoadVars-v6` | 6 | 8 | 4.9s |  |
| 18 | `LoadVars-v7` | 6 | 8 | 4.7s |  |
| 19 | `LoadVars-v8` | 6 | 8 | 2.6s |  |
| 20 | `Math-v5` | 5 | 5 | 11.7s |  |
| 21 | `Math-v6` | 5 | 5 | 1.2s |  |
| 22 | `Math-v7` | 5 | 5 | 12.0s |  |
| 23 | `Math-v8` | 5 | 5 | 2.0s |  |
| 24 | `Microphone-v6` | 31 | 31 | 4.6s |  |
| 25 | `Microphone-v7` | 31 | 31 | 3.9s |  |
| 26 | `Microphone-v8` | 31 | 31 | 2.6s |  |
| 27 | `MovieClip-v5` | 11 | 226 | 10.9s |  |
| 28 | `MovieClip-v6` | 20 | 60 | 34.3s |  |
| 29 | `MovieClip-v7` | 20 | 64 | 36.2s |  |
| 30 | `MovieClip-v8` | 25 | 68 | 45.0s |  |
| 31 | `MovieClipLoader-v7` | 118 | 118 | 5.5s |  |
| 32 | `MovieClipLoader-v8` | 118 | 118 | 4.0s |  |
| 33 | `NetConnection-v6` | 4 | 49 | 6.7s |  |
| 34 | `NetConnection-v7` | 4 | 45 | 6.6s |  |
| 35 | `NetConnection-v8` | 4 | 45 | 2.9s |  |
| 36 | `Number-v5` | 8 | 12 | 7.7s |  |
| 37 | `Object-v5` | 3 | 4 | 23.7s |  |
| 38 | `Object-v6` | 8 | 21 | 11.6s |  |
| 39 | `Object-v7` | 8 | 12 | 11.5s |  |
| 40 | `Object-v8` | 8 | 12 | 2.5s |  |
| 41 | `Selection-v6` | 7 | 13 | 7.6s |  |
| 42 | `Selection-v7` | 7 | 13 | 7.1s |  |
| 43 | `Selection-v8` | 7 | 13 | 3.1s |  |
| 44 | `Sound-v5` | 14 | 16 | 7.2s |  |
| 45 | `Stage-v6` | 14 | 14 | 4.6s |  |
| 46 | `Stage-v7` | 14 | 14 | 4.2s |  |
| 47 | `Stage-v8` | 14 | 14 | 3.0s |  |
| 48 | `String-v5` | 18 | 21 | 18.1s |  |
| 49 | `TextField-v6` | 15 | 57 | 19.3s |  |
| 50 | `TextField-v7` | 15 | 73 | 20.4s |  |
| 51 | `TextField-v8` | 14 | 72 | 20.3s |  |
| 52 | `TextFormat-v7` | 38 | 38 | 7.5s |  |
| 53 | `TextFormat-v8` | 36 | 36 | 7.1s |  |
| 54 | `Transform-v8` | 7 | 7 | 5.9s |  |
| 55 | `XML-v5` | 9 | 79 | 11.1s |  |
| 56 | `XML-v8` | 21 | 116 | 4.1s |  |
| 57 | `array-v5` | 5 | 17 | 42.4s |  |
| 58 | `array-v6` | 6 | 25 | 29.2s |  |
| 59 | `array-v7` | 5 | 23 | 30.5s |  |
| 60 | `array-v8` | 5 | 23 | 3.2s |  |
| 61 | `ops-v5` | 7 | 9 | 26.9s |  |
| 62 | `ops-v6` | 7 | 11 | 8.2s |  |
| 63 | `ops-v7` | 7 | 11 | 8.7s |  |
| 64 | `ops-v8` | 7 | 11 | 2.1s |  |
| 65 | `setProperty-v5` | 49 | 49 | 3.2s |  |
| 66 | `setProperty-v6` | 49 | 49 | 3.2s |  |
| 67 | `setProperty-v7` | 49 | 49 | 2.9s |  |
| 68 | `setProperty-v8` | 49 | 49 | 2.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `toString_valueOf-v5` | 76.6% | 105 | 137 | 32 |  |
| 2 | `ASnative-v5` | 67.3% | 72 | 107 | 35 |  |
| 3 | `ASnative-v6` | 63.6% | 70 | 110 | 40 |  |
| 4 | `ASnative-v7` | 63.6% | 70 | 110 | 40 |  |
| 5 | `ASnative-v8` | 63.6% | 70 | 110 | 40 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**8 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `toString_valueOf-v5` | 76.6% | 105/137 | 137 | 137 |  |
| 2 | `ASnative-v5` | 67.3% | 72/107 | 107 | 107 |  |
| 3 | `ASnative-v6` | 63.6% | 70/110 | 110 | 110 |  |
| 4 | `ASnative-v7` | 63.6% | 70/110 | 110 | 110 |  |
| 5 | `ASnative-v8` | 63.6% | 70/110 | 110 | 110 |  |
| 6 | `argstest-v8` | 4.0% | 121/3006 | 3006 | 2434 |  |
| 7 | `argstest-v6` | 3.2% | 84/2644 | 2644 | 2192 |  |
| 8 | `argstest-v7` | 3.0% | 78/2644 | 2644 | 2061 |  |
