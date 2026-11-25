# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 21:10 UTC

**Git SHA**: `10a5b515a0`

**Run Duration**: 27m 30s

**Filtered**: 3 tests ignored out of 243 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 240 |
| Passing | **167** (69.6%) |
| Ruffle-matched | 68 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **235** (97.9%) |
| Failing | 5 |
| Total expected lines | 32104 |
| Matching lines | 30707 (95.6%) |
| Mismatched lines | 1397 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**167 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.1s |  |
| 2 | `Accessibility-v6` | 19 | 2.2s |  |
| 3 | `Accessibility-v7` | 19 | 1.9s |  |
| 4 | `Accessibility-v8` | 19 | 1.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.1s |  |
| 6 | `AsBroadcaster-v6` | 121 | 23.1s |  |
| 7 | `AsBroadcaster-v7` | 121 | 4.2s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.3s |  |
| 9 | `BitmapData-v5` | 7 | 1.6s |  |
| 10 | `BitmapData-v6` | 7 | 0.5s |  |
| 11 | `BitmapData-v7` | 7 | 1.3s |  |
| 12 | `Boolean-v5` | 38 | 2.0s |  |
| 13 | `Boolean-v6` | 38 | 1.6s |  |
| 14 | `Boolean-v7` | 38 | 19.1s |  |
| 15 | `Boolean-v8` | 38 | 1.1s |  |
| 16 | `Camera-v5` | 7 | 1.4s |  |
| 17 | `Color-v5` | 140 | 3.9s |  |
| 18 | `Color-v6` | 171 | 4.7s |  |
| 19 | `Color-v7` | 161 | 4.5s |  |
| 20 | `Color-v8` | 161 | 21.7s |  |
| 21 | `ColorTransform-v5` | 7 | 1.5s |  |
| 22 | `ColorTransform-v6` | 7 | 0.5s |  |
| 23 | `ColorTransform-v7` | 7 | 1.2s |  |
| 24 | `ColorTransform-v8` | 55 | 2.4s |  |
| 25 | `ContextMenu-v5` | 7 | 1.4s |  |
| 26 | `ContextMenu-v6` | 7 | 0.4s |  |
| 27 | `ContextMenu-v7` | 131 | 3.4s |  |
| 28 | `ContextMenu-v8` | 131 | 23.1s |  |
| 29 | `Error-v5` | 28 | 2.3s |  |
| 30 | `Error-v6` | 31 | 2.2s |  |
| 31 | `Error-v7` | 31 | 2.0s |  |
| 32 | `Error-v8` | 31 | 19.5s |  |
| 33 | `ExternalInterface-v5` | 7 | 1.5s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.2s |  |
| 35 | `ExternalInterface-v7` | 55 | 1.9s |  |
| 36 | `Function-v6` | 271 | 7.2s |  |
| 37 | `Function-v7` | 272 | 7.5s |  |
| 38 | `Function-v8` | 272 | 26.3s |  |
| 39 | `Global-v5` | 172 | 5.8s |  |
| 40 | `Global-v7` | 182 | 6.1s |  |
| 41 | `Global-v8` | 169 | 5.5s |  |
| 42 | `HitTest-v6` | 88 | 3.9s |  |
| 43 | `HitTest-v7` | 88 | 3.7s |  |
| 44 | `Instance-v5` | 52 | 2.2s |  |
| 45 | `Instance-v6` | 52 | 1.2s |  |
| 46 | `Instance-v7` | 52 | 2.0s |  |
| 47 | `Instance-v8` | 52 | 1.1s |  |
| 48 | `Key-v5` | 51 | 19.8s |  |
| 49 | `Key-v6` | 55 | 2.3s |  |
| 50 | `Key-v7` | 55 | 2.0s |  |
| 51 | `Key-v8` | 55 | 1.1s |  |
| 52 | `LoadVars-v5` | 8 | 1.5s |  |
| 53 | `LocalConnection-v5` | 7 | 18.9s |  |
| 54 | `LocalConnection-v6` | 58 | 2.4s |  |
| 55 | `LocalConnection-v7` | 58 | 2.1s |  |
| 56 | `LocalConnection-v8` | 58 | 1.1s |  |
| 57 | `Matrix-v5` | 7 | 18.7s |  |
| 58 | `Matrix-v6` | 168 | 5.4s |  |
| 59 | `Matrix-v7` | 168 | 5.2s |  |
| 60 | `Matrix-v8` | 168 | 1.2s |  |
| 61 | `Microphone-v5` | 6 | 1.5s |  |
| 62 | `Mouse-v5` | 13 | 18.9s |  |
| 63 | `Mouse-v6` | 21 | 1.6s |  |
| 64 | `Mouse-v7` | 21 | 1.3s |  |
| 65 | `Mouse-v8` | 21 | 1.0s |  |
| 66 | `MovieClipLoader-v5` | 6 | 18.6s |  |
| 67 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 68 | `NetConnection-v5` | 7 | 1.5s |  |
| 69 | `NetStream-v5` | 6 | 19.5s |  |
| 70 | `NetStream-v6` | 80 | 3.2s |  |
| 71 | `NetStream-v7` | 80 | 3.0s |  |
| 72 | `NetStream-v8` | 80 | 1.5s |  |
| 73 | `Number-v6` | 239 | 8.3s |  |
| 74 | `Number-v7` | 237 | 8.3s |  |
| 75 | `Number-v8` | 237 | 1.6s |  |
| 76 | `Point-v5` | 7 | 1.5s |  |
| 77 | `Point-v6` | 7 | 0.5s |  |
| 78 | `Point-v7` | 7 | 1.2s |  |
| 79 | `Point-v8` | 193 | 6.4s |  |
| 80 | `Random-v5` | 30 | 28.8s |  |
| 81 | `Random-v6` | 30 | 0.8s |  |
| 82 | `Random-v7` | 30 | 2.8s |  |
| 83 | `Random-v8` | 30 | 1.9s |  |
| 84 | `Rectangle-v5` | 7 | 2.5s |  |
| 85 | `Rectangle-v6` | 7 | 0.8s |  |
| 86 | `Rectangle-v7` | 7 | 2.1s |  |
| 87 | `Rectangle-v8` | 166 | 8.4s |  |
| 88 | `Selection-v5` | 21 | 17.4s |  |
| 89 | `Sound-v6` | 121 | 5.3s |  |
| 90 | `Sound-v7` | 121 | 4.1s |  |
| 91 | `Sound-v8` | 121 | 1.6s |  |
| 92 | `Stage-v5` | 38 | 22.5s |  |
| 93 | `String-v6` | 377 | 17.0s |  |
| 94 | `String-v7` | 377 | 16.9s |  |
| 95 | `String-v8` | 377 | 1.9s |  |
| 96 | `System-v5` | 67 | 20.0s |  |
| 97 | `System-v6` | 100 | 3.0s |  |
| 98 | `System-v7` | 101 | 3.1s |  |
| 99 | `System-v8` | 101 | 1.2s |  |
| 100 | `TextField-v5` | 12 | 1.6s |  |
| 101 | `TextFieldHTML-v5` | 6 | 18.7s |  |
| 102 | `TextFieldHTML-v6` | 37 | 2.0s |  |
| 103 | `TextFieldHTML-v7` | 37 | 1.8s |  |
| 104 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 105 | `TextFormat-v5` | 128 | 3.6s |  |
| 106 | `TextFormat-v6` | 128 | 0.5s |  |
| 107 | `TextSnapshot-v5` | 7 | 19.6s |  |
| 108 | `TextSnapshot-v6` | 173 | 6.5s |  |
| 109 | `TextSnapshot-v7` | 173 | 6.3s |  |
| 110 | `TextSnapshot-v8` | 173 | 1.3s |  |
| 111 | `Transform-v5` | 7 | 1.6s |  |
| 112 | `Transform-v6` | 7 | 1.1s |  |
| 113 | `Transform-v7` | 7 | 1.3s |  |
| 114 | `Try-v5` | 20 | 19.4s |  |
| 115 | `Try-v6` | 20 | 0.5s |  |
| 116 | `Try-v7` | 20 | 2.0s |  |
| 117 | `Try-v8` | 20 | 1.1s |  |
| 118 | `Video-v5` | 7 | 1.5s |  |
| 119 | `Video-v6` | 85 | 2.6s |  |
| 120 | `Video-v7` | 85 | 2.3s |  |
| 121 | `Video-v8` | 85 | 1.1s |  |
| 122 | `XML-v6` | 486 | 14.9s |  |
| 123 | `XML-v7` | 486 | 14.5s |  |
| 124 | `XMLNode-v5` | 207 | 8.5s |  |
| 125 | `XMLNode-v6` | 207 | 8.3s |  |
| 126 | `XMLNode-v7` | 207 | 7.2s |  |
| 127 | `XMLNode-v8` | 207 | 1.6s |  |
| 128 | `XMLSocket-v5` | 35 | 19.5s |  |
| 129 | `XMLSocket-v6` | 35 | 2.1s |  |
| 130 | `XMLSocket-v7` | 35 | 1.8s |  |
| 131 | `XMLSocket-v8` | 35 | 1.2s |  |
| 132 | `argstest-v5` | 4 | 1.7s |  |
| 133 | `case-v5` | 39 | 2.1s |  |
| 134 | `case-v6` | 73 | 2.7s |  |
| 135 | `case-v7` | 67 | 2.7s |  |
| 136 | `case-v8` | 67 | 1.2s |  |
| 137 | `delete-v5` | 61 | 19.6s |  |
| 138 | `delete-v6` | 61 | 1.9s |  |
| 139 | `delete-v7` | 61 | 2.1s |  |
| 140 | `delete-v8` | 61 | 1.3s |  |
| 141 | `enumerate-v5` | 6 | 1.5s |  |
| 142 | `enumerate-v6` | 49 | 2.3s |  |
| 143 | `enumerate-v7` | 49 | 2.1s |  |
| 144 | `enumerate-v8` | 49 | 1.1s |  |
| 145 | `flash-v5` | 10 | 19.6s |  |
| 146 | `flash-v6` | 10 | 1.9s |  |
| 147 | `flash-v7` | 10 | 1.6s |  |
| 148 | `flash-v8` | 41 | 2.6s |  |
| 149 | `getvariable-v5` | 58 | 3.0s |  |
| 150 | `getvariable-v6` | 64 | 3.4s |  |
| 151 | `getvariable-v7` | 64 | 3.1s |  |
| 152 | `getvariable-v8` | 64 | 1.6s |  |
| 153 | `swap-v5` | 7 | 19.5s |  |
| 154 | `swap-v6` | 7 | 0.5s |  |
| 155 | `swap-v7` | 7 | 1.2s |  |
| 156 | `swap-v8` | 7 | 1.0s |  |
| 157 | `targetPath-v5` | 12 | 1.5s |  |
| 158 | `targetPath-v6` | 23 | 1.7s |  |
| 159 | `targetPath-v7` | 23 | 1.4s |  |
| 160 | `targetPath-v8` | 23 | 1.0s |  |
| 161 | `toString_valueOf-v6` | 155 | 6.2s |  |
| 162 | `toString_valueOf-v7` | 155 | 5.8s |  |
| 163 | `toString_valueOf-v8` | 155 | 1.8s |  |
| 164 | `with-v5` | 49 | 3.9s |  |
| 165 | `with-v6` | 107 | 5.2s |  |
| 166 | `with-v7` | 107 | 4.9s |  |
| 167 | `with-v8` | 107 | 1.9s |  |

## Ruffle-Matched Tests

**68 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `BitmapData-v8` | 8 | 8 | 21.1s |  |
| 2 | `Camera-v6` | 57 | 57 | 3.0s |  |
| 3 | `Camera-v7` | 57 | 57 | 2.7s |  |
| 4 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 5 | `Date-v5` | 7 | 7 | 13.4s |  |
| 6 | `Date-v6` | 6 | 6 | 14.7s |  |
| 7 | `Date-v7` | 6 | 6 | 15.1s |  |
| 8 | `Date-v8` | 6 | 6 | 1.8s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 3.6s |  |
| 10 | `Function-v5` | 10 | 25 | 4.2s |  |
| 11 | `Global-v6` | 9 | 10 | 7.0s |  |
| 12 | `HitTest-v8` | 3 | 9 | 3.5s |  |
| 13 | `Inheritance-v5` | 1 | 17 | 21.1s |  |
| 14 | `Inheritance-v6` | 9 | 13 | 5.0s |  |
| 15 | `Inheritance-v7` | 5 | 7 | 5.2s |  |
| 16 | `Inheritance-v8` | 5 | 7 | 1.6s |  |
| 17 | `LoadVars-v6` | 6 | 8 | 4.2s |  |
| 18 | `LoadVars-v7` | 6 | 8 | 4.0s |  |
| 19 | `LoadVars-v8` | 6 | 8 | 1.8s |  |
| 20 | `Math-v5` | 5 | 5 | 10.9s |  |
| 21 | `Math-v6` | 5 | 5 | 0.6s |  |
| 22 | `Math-v7` | 5 | 5 | 11.2s |  |
| 23 | `Math-v8` | 5 | 5 | 1.3s |  |
| 24 | `Microphone-v6` | 31 | 31 | 2.5s |  |
| 25 | `Microphone-v7` | 31 | 31 | 2.3s |  |
| 26 | `Microphone-v8` | 31 | 31 | 1.1s |  |
| 27 | `MovieClip-v5` | 11 | 226 | 10.6s |  |
| 28 | `MovieClip-v6` | 20 | 60 | 39.0s |  |
| 29 | `MovieClip-v7` | 20 | 64 | 40.8s |  |
| 30 | `MovieClip-v8` | 25 | 68 | 52.0s |  |
| 31 | `MovieClipLoader-v7` | 118 | 118 | 3.1s |  |
| 32 | `MovieClipLoader-v8` | 118 | 118 | 2.0s |  |
| 33 | `NetConnection-v6` | 4 | 49 | 3.5s |  |
| 34 | `NetConnection-v7` | 4 | 45 | 3.5s |  |
| 35 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 36 | `Number-v5` | 8 | 12 | 8.6s |  |
| 37 | `Object-v5` | 3 | 4 | 22.4s |  |
| 38 | `Object-v6` | 8 | 21 | 10.8s |  |
| 39 | `Object-v7` | 8 | 12 | 10.7s |  |
| 40 | `Object-v8` | 8 | 12 | 1.7s |  |
| 41 | `Selection-v6` | 7 | 13 | 4.4s |  |
| 42 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 43 | `Selection-v8` | 7 | 13 | 1.5s |  |
| 44 | `Sound-v5` | 14 | 16 | 5.3s |  |
| 45 | `Stage-v6` | 14 | 14 | 3.1s |  |
| 46 | `Stage-v7` | 14 | 14 | 3.0s |  |
| 47 | `Stage-v8` | 14 | 14 | 1.6s |  |
| 48 | `String-v5` | 18 | 21 | 16.4s |  |
| 49 | `TextField-v6` | 15 | 57 | 18.4s |  |
| 50 | `TextField-v7` | 15 | 73 | 20.1s |  |
| 51 | `TextField-v8` | 14 | 72 | 20.0s |  |
| 52 | `TextFormat-v7` | 38 | 38 | 4.9s |  |
| 53 | `TextFormat-v8` | 36 | 36 | 4.8s |  |
| 54 | `Transform-v8` | 7 | 7 | 4.0s |  |
| 55 | `XML-v5` | 9 | 79 | 30.8s |  |
| 56 | `XML-v8` | 21 | 116 | 4.3s |  |
| 57 | `array-v5` | 5 | 17 | 42.6s |  |
| 58 | `array-v6` | 6 | 25 | 28.5s |  |
| 59 | `array-v7` | 5 | 23 | 29.3s |  |
| 60 | `array-v8` | 5 | 23 | 2.5s |  |
| 61 | `ops-v5` | 7 | 9 | 24.4s |  |
| 62 | `ops-v6` | 7 | 11 | 6.8s |  |
| 63 | `ops-v7` | 7 | 11 | 7.3s |  |
| 64 | `ops-v8` | 7 | 11 | 1.2s |  |
| 65 | `setProperty-v5` | 49 | 49 | 2.3s |  |
| 66 | `setProperty-v6` | 49 | 49 | 2.3s |  |
| 67 | `setProperty-v7` | 49 | 49 | 2.1s |  |
| 68 | `setProperty-v8` | 49 | 49 | 1.3s |  |

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

**5 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `toString_valueOf-v5` | 76.6% | 105/137 | 137 | 137 |  |
| 2 | `ASnative-v5` | 67.3% | 72/107 | 107 | 107 |  |
| 3 | `ASnative-v6` | 63.6% | 70/110 | 110 | 110 |  |
| 4 | `ASnative-v7` | 63.6% | 70/110 | 110 | 110 |  |
| 5 | `ASnative-v8` | 63.6% | 70/110 | 110 | 110 |  |
