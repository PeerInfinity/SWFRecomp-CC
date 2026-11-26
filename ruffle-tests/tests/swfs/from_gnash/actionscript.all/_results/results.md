# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-26 21:04 UTC

**Git SHA**: `bfa47037b1`

**Run Duration**: 23m 58s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **177** (72.8%) |
| Ruffle-matched | 63 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (98.8%) |
| Failing | 3 |
| Total expected lines | 38791 |
| Matching lines | 31095 (80.2%) |
| Mismatched lines | 7696 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**177 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.6s |  |
| 2 | `Accessibility-v6` | 19 | 1.7s |  |
| 3 | `Accessibility-v7` | 19 | 1.4s |  |
| 4 | `Accessibility-v8` | 19 | 1.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.5s |  |
| 6 | `AsBroadcaster-v6` | 121 | 4.0s |  |
| 7 | `AsBroadcaster-v7` | 121 | 3.9s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.3s |  |
| 9 | `BitmapData-v5` | 7 | 1.1s |  |
| 10 | `BitmapData-v6` | 7 | 0.5s |  |
| 11 | `BitmapData-v7` | 7 | 1.2s |  |
| 12 | `Boolean-v5` | 38 | 2.0s |  |
| 13 | `Boolean-v6` | 38 | 1.6s |  |
| 14 | `Boolean-v7` | 38 | 3.0s |  |
| 15 | `Boolean-v8` | 38 | 1.8s |  |
| 16 | `Camera-v5` | 7 | 2.4s |  |
| 17 | `Color-v5` | 140 | 6.5s |  |
| 18 | `Color-v6` | 171 | 7.7s |  |
| 19 | `Color-v7` | 161 | 7.3s |  |
| 20 | `Color-v8` | 161 | 28.6s |  |
| 21 | `ColorTransform-v5` | 7 | 2.0s |  |
| 22 | `ColorTransform-v6` | 7 | 0.7s |  |
| 23 | `ColorTransform-v7` | 7 | 1.7s |  |
| 24 | `ColorTransform-v8` | 55 | 3.3s |  |
| 25 | `ContextMenu-v5` | 7 | 2.0s |  |
| 26 | `ContextMenu-v6` | 7 | 0.6s |  |
| 27 | `ContextMenu-v7` | 131 | 4.7s |  |
| 28 | `ContextMenu-v8` | 131 | 5.1s |  |
| 29 | `Error-v5` | 28 | 2.5s |  |
| 30 | `Error-v6` | 31 | 2.4s |  |
| 31 | `Error-v7` | 31 | 2.0s |  |
| 32 | `Error-v8` | 31 | 25.3s |  |
| 33 | `ExternalInterface-v5` | 7 | 2.1s |  |
| 34 | `ExternalInterface-v6` | 55 | 3.0s |  |
| 35 | `ExternalInterface-v7` | 55 | 2.6s |  |
| 36 | `Function-v6` | 271 | 9.8s |  |
| 37 | `Function-v7` | 272 | 10.1s |  |
| 38 | `Function-v8` | 272 | 25.2s |  |
| 39 | `Global-v5` | 172 | 5.2s |  |
| 40 | `Global-v6` | 210 | 6.5s |  |
| 41 | `Global-v7` | 182 | 5.6s |  |
| 42 | `Global-v8` | 169 | 5.4s |  |
| 43 | `HitTest-v6` | 88 | 3.9s |  |
| 44 | `HitTest-v7` | 88 | 3.6s |  |
| 45 | `Instance-v5` | 52 | 2.2s |  |
| 46 | `Instance-v6` | 52 | 1.2s |  |
| 47 | `Instance-v7` | 52 | 1.9s |  |
| 48 | `Instance-v8` | 52 | 1.1s |  |
| 49 | `Key-v5` | 51 | 2.1s |  |
| 50 | `Key-v6` | 55 | 2.2s |  |
| 51 | `Key-v7` | 55 | 1.9s |  |
| 52 | `Key-v8` | 55 | 1.1s |  |
| 53 | `LoadVars-v5` | 8 | 1.5s |  |
| 54 | `LocalConnection-v5` | 7 | 25.1s |  |
| 55 | `LocalConnection-v6` | 58 | 3.7s |  |
| 56 | `LocalConnection-v7` | 58 | 3.4s |  |
| 57 | `LocalConnection-v8` | 58 | 1.8s |  |
| 58 | `Matrix-v5` | 7 | 2.5s |  |
| 59 | `Matrix-v6` | 168 | 9.0s |  |
| 60 | `Matrix-v7` | 168 | 9.0s |  |
| 61 | `Matrix-v8` | 168 | 2.1s |  |
| 62 | `Microphone-v5` | 6 | 2.5s |  |
| 63 | `Mouse-v5` | 13 | 1.5s |  |
| 64 | `Mouse-v6` | 21 | 1.6s |  |
| 65 | `Mouse-v7` | 21 | 1.3s |  |
| 66 | `Mouse-v8` | 21 | 1.1s |  |
| 67 | `MovieClipLoader-v5` | 6 | 1.6s |  |
| 68 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 69 | `NetConnection-v5` | 7 | 1.5s |  |
| 70 | `NetStream-v5` | 6 | 25.2s |  |
| 71 | `NetStream-v6` | 80 | 4.4s |  |
| 72 | `NetStream-v7` | 80 | 3.9s |  |
| 73 | `NetStream-v8` | 80 | 1.9s |  |
| 74 | `Number-v5` | 244 | 10.4s |  |
| 75 | `Number-v6` | 239 | 10.1s |  |
| 76 | `Number-v7` | 237 | 9.9s |  |
| 77 | `Number-v8` | 237 | 2.0s |  |
| 78 | `Object-v5` | 145 | 23.0s |  |
| 79 | `Point-v5` | 7 | 1.5s |  |
| 80 | `Point-v6` | 7 | 0.5s |  |
| 81 | `Point-v7` | 7 | 1.3s |  |
| 82 | `Point-v8` | 193 | 6.4s |  |
| 83 | `Random-v5` | 30 | 1.8s |  |
| 84 | `Random-v6` | 30 | 0.5s |  |
| 85 | `Random-v7` | 30 | 1.5s |  |
| 86 | `Random-v8` | 30 | 1.2s |  |
| 87 | `Rectangle-v5` | 7 | 1.1s |  |
| 88 | `Rectangle-v6` | 7 | 0.5s |  |
| 89 | `Rectangle-v7` | 7 | 1.2s |  |
| 90 | `Rectangle-v8` | 166 | 5.0s |  |
| 91 | `Selection-v5` | 21 | 1.7s |  |
| 92 | `Selection-v6` | 125 | 4.2s |  |
| 93 | `Selection-v7` | 125 | 3.7s |  |
| 94 | `Selection-v8` | 125 | 1.2s |  |
| 95 | `Sound-v6` | 121 | 3.8s |  |
| 96 | `Sound-v7` | 121 | 3.5s |  |
| 97 | `Sound-v8` | 121 | 1.4s |  |
| 98 | `Stage-v5` | 38 | 26.3s |  |
| 99 | `String-v6` | 377 | 18.5s |  |
| 100 | `String-v7` | 377 | 18.0s |  |
| 101 | `String-v8` | 377 | 2.3s |  |
| 102 | `System-v5` | 67 | 20.8s |  |
| 103 | `System-v6` | 100 | 3.2s |  |
| 104 | `System-v7` | 101 | 3.2s |  |
| 105 | `System-v8` | 101 | 1.2s |  |
| 106 | `TextField-v5` | 12 | 1.6s |  |
| 107 | `TextFieldHTML-v5` | 6 | 24.9s |  |
| 108 | `TextFieldHTML-v6` | 37 | 2.7s |  |
| 109 | `TextFieldHTML-v7` | 37 | 2.4s |  |
| 110 | `TextFieldHTML-v8` | 37 | 1.5s |  |
| 111 | `TextFormat-v5` | 128 | 5.4s |  |
| 112 | `TextFormat-v6` | 128 | 0.8s |  |
| 113 | `TextSnapshot-v5` | 7 | 1.5s |  |
| 114 | `TextSnapshot-v6` | 173 | 6.4s |  |
| 115 | `TextSnapshot-v7` | 173 | 6.2s |  |
| 116 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 117 | `Transform-v5` | 7 | 1.2s |  |
| 118 | `Transform-v6` | 7 | 1.1s |  |
| 119 | `Transform-v7` | 7 | 1.3s |  |
| 120 | `Try-v5` | 20 | 3.3s |  |
| 121 | `Try-v6` | 20 | 0.7s |  |
| 122 | `Try-v7` | 20 | 3.0s |  |
| 123 | `Try-v8` | 20 | 1.7s |  |
| 124 | `Video-v5` | 7 | 2.4s |  |
| 125 | `Video-v6` | 85 | 4.0s |  |
| 126 | `Video-v7` | 85 | 3.5s |  |
| 127 | `Video-v8` | 85 | 1.8s |  |
| 128 | `XML-v6` | 486 | 12.5s |  |
| 129 | `XML-v7` | 486 | 12.4s |  |
| 130 | `XMLNode-v5` | 207 | 6.6s |  |
| 131 | `XMLNode-v6` | 207 | 6.5s |  |
| 132 | `XMLNode-v7` | 207 | 5.8s |  |
| 133 | `XMLNode-v8` | 207 | 1.3s |  |
| 134 | `XMLSocket-v5` | 35 | 19.8s |  |
| 135 | `XMLSocket-v6` | 35 | 2.0s |  |
| 136 | `XMLSocket-v7` | 35 | 1.8s |  |
| 137 | `XMLSocket-v8` | 35 | 1.3s |  |
| 138 | `argstest-v5` | 4 | 1.7s |  |
| 139 | `case-v5` | 39 | 3.0s |  |
| 140 | `case-v6` | 73 | 4.0s |  |
| 141 | `case-v7` | 67 | 3.8s |  |
| 142 | `case-v8` | 67 | 1.8s |  |
| 143 | `delete-v5` | 61 | 20.2s |  |
| 144 | `delete-v6` | 61 | 2.0s |  |
| 145 | `delete-v7` | 61 | 2.1s |  |
| 146 | `delete-v8` | 61 | 1.3s |  |
| 147 | `enumerate-v5` | 6 | 1.5s |  |
| 148 | `enumerate-v6` | 49 | 2.3s |  |
| 149 | `enumerate-v7` | 49 | 2.0s |  |
| 150 | `enumerate-v8` | 49 | 1.1s |  |
| 151 | `flash-v5` | 10 | 2.3s |  |
| 152 | `flash-v6` | 10 | 2.3s |  |
| 153 | `flash-v7` | 10 | 1.9s |  |
| 154 | `flash-v8` | 41 | 3.1s |  |
| 155 | `getvariable-v5` | 58 | 3.5s |  |
| 156 | `getvariable-v6` | 64 | 3.7s |  |
| 157 | `getvariable-v7` | 64 | 3.9s |  |
| 158 | `getvariable-v8` | 64 | 1.9s |  |
| 159 | `ops-v5` | 260 | 9.0s |  |
| 160 | `ops-v6` | 260 | 8.5s |  |
| 161 | `ops-v7` | 262 | 9.1s |  |
| 162 | `ops-v8` | 262 | 1.4s |  |
| 163 | `swap-v5` | 7 | 1.5s |  |
| 164 | `swap-v6` | 7 | 0.5s |  |
| 165 | `swap-v7` | 7 | 1.2s |  |
| 166 | `swap-v8` | 7 | 1.1s |  |
| 167 | `targetPath-v5` | 12 | 1.6s |  |
| 168 | `targetPath-v6` | 23 | 1.7s |  |
| 169 | `targetPath-v7` | 23 | 1.5s |  |
| 170 | `targetPath-v8` | 23 | 1.1s |  |
| 171 | `toString_valueOf-v6` | 155 | 5.7s |  |
| 172 | `toString_valueOf-v7` | 155 | 5.4s |  |
| 173 | `toString_valueOf-v8` | 155 | 1.7s |  |
| 174 | `with-v5` | 49 | 3.6s |  |
| 175 | `with-v6` | 107 | 4.8s |  |
| 176 | `with-v7` | 107 | 4.5s |  |
| 177 | `with-v8` | 107 | 1.9s |  |

## Ruffle-Matched Tests

**63 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 4.1s |  |
| 2 | `ASnative-v6` | 39 | 40 | 4.1s |  |
| 3 | `ASnative-v7` | 39 | 40 | 3.9s |  |
| 4 | `ASnative-v8` | 39 | 40 | 1.2s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 20.6s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.8s |  |
| 7 | `Camera-v7` | 57 | 57 | 4.5s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.9s |  |
| 9 | `Date-v5` | 6 | 7 | 13.8s |  |
| 10 | `Date-v6` | 6 | 6 | 15.4s |  |
| 11 | `Date-v7` | 6 | 6 | 15.8s |  |
| 12 | `Date-v8` | 6 | 6 | 1.9s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 5.0s |  |
| 14 | `Function-v5` | 4 | 25 | 5.9s |  |
| 15 | `HitTest-v8` | 3 | 9 | 3.6s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 20.9s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 4.8s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 4.9s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 1.6s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 4.1s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 3.8s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 1.8s |  |
| 23 | `Math-v5` | 5 | 5 | 15.1s |  |
| 24 | `Math-v6` | 5 | 5 | 1.0s |  |
| 25 | `Math-v7` | 5 | 5 | 15.7s |  |
| 26 | `Math-v8` | 5 | 5 | 2.1s |  |
| 27 | `Microphone-v6` | 31 | 31 | 4.4s |  |
| 28 | `Microphone-v7` | 31 | 31 | 4.0s |  |
| 29 | `Microphone-v8` | 31 | 31 | 1.9s |  |
| 30 | `MovieClip-v5` | 10 | 226 | 9.7s |  |
| 31 | `MovieClip-v6` | 20 | 60 | 32.7s |  |
| 32 | `MovieClip-v7` | 20 | 64 | 34.5s |  |
| 33 | `MovieClip-v8` | 25 | 68 | 43.1s |  |
| 34 | `MovieClipLoader-v7` | 118 | 118 | 3.1s |  |
| 35 | `MovieClipLoader-v8` | 118 | 118 | 2.0s |  |
| 36 | `NetConnection-v6` | 4 | 49 | 3.7s |  |
| 37 | `NetConnection-v7` | 4 | 45 | 3.8s |  |
| 38 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 39 | `Object-v6` | 8 | 21 | 10.9s |  |
| 40 | `Object-v7` | 8 | 12 | 10.9s |  |
| 41 | `Object-v8` | 8 | 12 | 1.7s |  |
| 42 | `Sound-v5` | 14 | 16 | 3.6s |  |
| 43 | `Stage-v6` | 14 | 14 | 3.6s |  |
| 44 | `Stage-v7` | 14 | 14 | 3.2s |  |
| 45 | `Stage-v8` | 14 | 14 | 1.9s |  |
| 46 | `String-v5` | 14 | 21 | 17.6s |  |
| 47 | `TextField-v6` | 15 | 57 | 19.0s |  |
| 48 | `TextField-v7` | 15 | 73 | 20.3s |  |
| 49 | `TextField-v8` | 14 | 72 | 20.1s |  |
| 50 | `TextFormat-v7` | 38 | 38 | 7.2s |  |
| 51 | `TextFormat-v8` | 36 | 36 | 7.1s |  |
| 52 | `Transform-v8` | 7 | 7 | 3.8s |  |
| 53 | `XML-v5` | 9 | 79 | 11.2s |  |
| 54 | `XML-v8` | 21 | 116 | 3.5s |  |
| 55 | `array-v5` | 5 | 17 | 30.2s |  |
| 56 | `array-v6` | 6 | 25 | 35.3s |  |
| 57 | `array-v7` | 5 | 23 | 37.0s |  |
| 58 | `array-v8` | 5 | 23 | 3.6s |  |
| 59 | `setProperty-v5` | 49 | 49 | 2.6s |  |
| 60 | `setProperty-v6` | 49 | 49 | 2.8s |  |
| 61 | `setProperty-v7` | 49 | 49 | 2.3s |  |
| 62 | `setProperty-v8` | 49 | 49 | 1.5s |  |
| 63 | `toString_valueOf-v5` | 12 | 34 | 28.3s |  |

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
