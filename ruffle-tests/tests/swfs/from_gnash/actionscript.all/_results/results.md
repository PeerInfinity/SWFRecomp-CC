# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 02:09 UTC

**Git SHA**: `6ee6eded7b`

**Run Duration**: 22m 29s

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
| 1 | `Accessibility-v5` | 15 | 2.4s |  |
| 2 | `Accessibility-v6` | 19 | 2.5s |  |
| 3 | `Accessibility-v7` | 19 | 2.1s |  |
| 4 | `Accessibility-v8` | 19 | 1.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.3s |  |
| 6 | `AsBroadcaster-v6` | 121 | 21.1s |  |
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
| 18 | `Color-v6` | 171 | 5.1s |  |
| 19 | `Color-v7` | 161 | 4.8s |  |
| 20 | `Color-v8` | 161 | 5.1s |  |
| 21 | `ColorTransform-v5` | 7 | 1.6s |  |
| 22 | `ColorTransform-v6` | 7 | 0.5s |  |
| 23 | `ColorTransform-v7` | 7 | 1.3s |  |
| 24 | `ColorTransform-v8` | 55 | 2.5s |  |
| 25 | `ContextMenu-v5` | 7 | 1.5s |  |
| 26 | `ContextMenu-v6` | 7 | 0.5s |  |
| 27 | `ContextMenu-v7` | 131 | 3.7s |  |
| 28 | `ContextMenu-v8` | 131 | 21.5s |  |
| 29 | `Error-v5` | 28 | 1.8s |  |
| 30 | `Error-v6` | 31 | 1.9s |  |
| 31 | `Error-v7` | 31 | 1.6s |  |
| 32 | `Error-v8` | 31 | 19.7s |  |
| 33 | `ExternalInterface-v5` | 7 | 1.5s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.2s |  |
| 35 | `ExternalInterface-v7` | 55 | 1.9s |  |
| 36 | `Function-v6` | 271 | 7.6s |  |
| 37 | `Function-v7` | 272 | 7.6s |  |
| 38 | `Function-v8` | 272 | 22.3s |  |
| 39 | `Global-v5` | 172 | 5.4s |  |
| 40 | `Global-v6` | 210 | 6.7s |  |
| 41 | `Global-v7` | 182 | 5.5s |  |
| 42 | `Global-v8` | 169 | 5.1s |  |
| 43 | `HitTest-v6` | 88 | 3.6s |  |
| 44 | `HitTest-v7` | 88 | 3.6s |  |
| 45 | `Instance-v5` | 52 | 3.4s |  |
| 46 | `Instance-v6` | 52 | 1.8s |  |
| 47 | `Instance-v7` | 52 | 2.9s |  |
| 48 | `Instance-v8` | 52 | 1.7s |  |
| 49 | `Key-v5` | 51 | 26.5s |  |
| 50 | `Key-v6` | 55 | 3.4s |  |
| 51 | `Key-v7` | 55 | 3.1s |  |
| 52 | `Key-v8` | 55 | 1.8s |  |
| 53 | `LoadVars-v5` | 8 | 2.4s |  |
| 54 | `LocalConnection-v5` | 7 | 19.7s |  |
| 55 | `LocalConnection-v6` | 58 | 2.5s |  |
| 56 | `LocalConnection-v7` | 58 | 2.2s |  |
| 57 | `LocalConnection-v8` | 58 | 1.2s |  |
| 58 | `Matrix-v5` | 7 | 1.5s |  |
| 59 | `Matrix-v6` | 168 | 5.7s |  |
| 60 | `Matrix-v7` | 168 | 5.7s |  |
| 61 | `Matrix-v8` | 168 | 1.2s |  |
| 62 | `Microphone-v5` | 6 | 1.5s |  |
| 63 | `Mouse-v5` | 13 | 1.5s |  |
| 64 | `Mouse-v6` | 21 | 1.6s |  |
| 65 | `Mouse-v7` | 21 | 1.4s |  |
| 66 | `Mouse-v8` | 21 | 1.1s |  |
| 67 | `MovieClipLoader-v5` | 6 | 1.7s |  |
| 68 | `MovieClipLoader-v6` | 6 | 0.6s |  |
| 69 | `NetConnection-v5` | 7 | 1.6s |  |
| 70 | `NetStream-v5` | 6 | 1.5s |  |
| 71 | `NetStream-v6` | 80 | 2.7s |  |
| 72 | `NetStream-v7` | 80 | 2.4s |  |
| 73 | `NetStream-v8` | 80 | 1.1s |  |
| 74 | `Number-v5` | 244 | 7.2s |  |
| 75 | `Number-v6` | 239 | 7.0s |  |
| 76 | `Number-v7` | 237 | 7.0s |  |
| 77 | `Number-v8` | 237 | 1.3s |  |
| 78 | `Object-v5` | 145 | 21.7s |  |
| 79 | `Point-v5` | 7 | 1.3s |  |
| 80 | `Point-v6` | 7 | 0.5s |  |
| 81 | `Point-v7` | 7 | 1.1s |  |
| 82 | `Point-v8` | 193 | 5.9s |  |
| 83 | `Random-v5` | 30 | 25.6s |  |
| 84 | `Random-v6` | 30 | 0.8s |  |
| 85 | `Random-v7` | 30 | 2.5s |  |
| 86 | `Random-v8` | 30 | 1.8s |  |
| 87 | `Rectangle-v5` | 7 | 2.3s |  |
| 88 | `Rectangle-v6` | 7 | 0.7s |  |
| 89 | `Rectangle-v7` | 7 | 1.9s |  |
| 90 | `Rectangle-v8` | 166 | 7.3s |  |
| 91 | `Selection-v5` | 21 | 25.1s |  |
| 92 | `Selection-v6` | 125 | 5.7s |  |
| 93 | `Selection-v7` | 125 | 5.3s |  |
| 94 | `Selection-v8` | 125 | 1.9s |  |
| 95 | `Sound-v6` | 121 | 5.8s |  |
| 96 | `Sound-v7` | 121 | 5.3s |  |
| 97 | `Sound-v8` | 121 | 2.2s |  |
| 98 | `Stage-v5` | 38 | 2.0s |  |
| 99 | `String-v6` | 377 | 14.7s |  |
| 100 | `String-v7` | 377 | 14.6s |  |
| 101 | `String-v8` | 377 | 1.7s |  |
| 102 | `System-v5` | 67 | 3.8s |  |
| 103 | `System-v6` | 100 | 4.6s |  |
| 104 | `System-v7` | 101 | 4.7s |  |
| 105 | `System-v8` | 101 | 1.8s |  |
| 106 | `TextField-v5` | 12 | 2.5s |  |
| 107 | `TextFieldHTML-v5` | 6 | 1.4s |  |
| 108 | `TextFieldHTML-v6` | 37 | 2.0s |  |
| 109 | `TextFieldHTML-v7` | 37 | 1.7s |  |
| 110 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 111 | `TextFormat-v5` | 128 | 3.6s |  |
| 112 | `TextFormat-v6` | 128 | 0.5s |  |
| 113 | `TextSnapshot-v5` | 7 | 1.5s |  |
| 114 | `TextSnapshot-v6` | 173 | 5.9s |  |
| 115 | `TextSnapshot-v7` | 173 | 5.6s |  |
| 116 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 117 | `Transform-v5` | 7 | 1.5s |  |
| 118 | `Transform-v6` | 7 | 1.1s |  |
| 119 | `Transform-v7` | 7 | 1.2s |  |
| 120 | `Try-v5` | 20 | 2.3s |  |
| 121 | `Try-v6` | 20 | 0.5s |  |
| 122 | `Try-v7` | 20 | 2.1s |  |
| 123 | `Try-v8` | 20 | 1.2s |  |
| 124 | `Video-v5` | 7 | 1.6s |  |
| 125 | `Video-v6` | 85 | 2.8s |  |
| 126 | `Video-v7` | 85 | 2.5s |  |
| 127 | `Video-v8` | 85 | 1.2s |  |
| 128 | `XML-v6` | 486 | 11.8s |  |
| 129 | `XML-v7` | 486 | 11.5s |  |
| 130 | `XMLNode-v5` | 207 | 6.2s |  |
| 131 | `XMLNode-v6` | 207 | 6.0s |  |
| 132 | `XMLNode-v7` | 207 | 5.3s |  |
| 133 | `XMLNode-v8` | 207 | 1.2s |  |
| 134 | `XMLSocket-v5` | 35 | 2.0s |  |
| 135 | `XMLSocket-v6` | 35 | 2.0s |  |
| 136 | `XMLSocket-v7` | 35 | 1.7s |  |
| 137 | `XMLSocket-v8` | 35 | 1.2s |  |
| 138 | `argstest-v5` | 4 | 1.6s |  |
| 139 | `case-v5` | 39 | 3.2s |  |
| 140 | `case-v6` | 73 | 4.3s |  |
| 141 | `case-v7` | 67 | 4.1s |  |
| 142 | `case-v8` | 67 | 1.9s |  |
| 143 | `delete-v5` | 61 | 3.4s |  |
| 144 | `delete-v6` | 61 | 2.8s |  |
| 145 | `delete-v7` | 61 | 3.0s |  |
| 146 | `delete-v8` | 61 | 1.9s |  |
| 147 | `enumerate-v5` | 6 | 2.2s |  |
| 148 | `enumerate-v6` | 49 | 3.3s |  |
| 149 | `enumerate-v7` | 49 | 3.0s |  |
| 150 | `enumerate-v8` | 49 | 1.7s |  |
| 151 | `flash-v5` | 10 | 1.6s |  |
| 152 | `flash-v6` | 10 | 1.6s |  |
| 153 | `flash-v7` | 10 | 1.3s |  |
| 154 | `flash-v8` | 41 | 2.2s |  |
| 155 | `getvariable-v5` | 58 | 2.4s |  |
| 156 | `getvariable-v6` | 64 | 2.6s |  |
| 157 | `getvariable-v7` | 64 | 2.6s |  |
| 158 | `getvariable-v8` | 64 | 1.2s |  |
| 159 | `ops-v5` | 260 | 10.6s |  |
| 160 | `ops-v6` | 260 | 9.9s |  |
| 161 | `ops-v7` | 262 | 10.6s |  |
| 162 | `ops-v8` | 262 | 1.8s |  |
| 163 | `swap-v5` | 7 | 2.0s |  |
| 164 | `swap-v6` | 7 | 0.6s |  |
| 165 | `swap-v7` | 7 | 1.6s |  |
| 166 | `swap-v8` | 7 | 1.5s |  |
| 167 | `targetPath-v5` | 12 | 2.0s |  |
| 168 | `targetPath-v6` | 23 | 2.2s |  |
| 169 | `targetPath-v7` | 23 | 1.9s |  |
| 170 | `targetPath-v8` | 23 | 1.5s |  |
| 171 | `toString_valueOf-v6` | 155 | 5.8s |  |
| 172 | `toString_valueOf-v7` | 155 | 5.4s |  |
| 173 | `toString_valueOf-v8` | 155 | 1.8s |  |
| 174 | `with-v5` | 49 | 3.8s |  |
| 175 | `with-v6` | 107 | 5.0s |  |
| 176 | `with-v7` | 107 | 4.6s |  |
| 177 | `with-v8` | 107 | 2.0s |  |

## Ruffle-Matched Tests

**63 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 34 | 35 | 28.8s |  |
| 2 | `ASnative-v6` | 39 | 40 | 6.1s |  |
| 3 | `ASnative-v7` | 39 | 40 | 5.7s |  |
| 4 | `ASnative-v8` | 39 | 40 | 1.9s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 18.5s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.1s |  |
| 7 | `Camera-v7` | 57 | 57 | 2.9s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.2s |  |
| 9 | `Date-v5` | 6 | 7 | 10.5s |  |
| 10 | `Date-v6` | 6 | 6 | 11.9s |  |
| 11 | `Date-v7` | 6 | 6 | 12.1s |  |
| 12 | `Date-v8` | 6 | 6 | 1.4s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 3.7s |  |
| 14 | `Function-v5` | 4 | 25 | 4.4s |  |
| 15 | `HitTest-v8` | 3 | 9 | 3.3s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 5.2s |  |
| 17 | `Inheritance-v6` | 9 | 13 | 7.2s |  |
| 18 | `Inheritance-v7` | 5 | 7 | 7.2s |  |
| 19 | `Inheritance-v8` | 5 | 7 | 2.4s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 6.5s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 6.2s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 2.7s |  |
| 23 | `Math-v5` | 5 | 5 | 11.7s |  |
| 24 | `Math-v6` | 5 | 5 | 0.6s |  |
| 25 | `Math-v7` | 5 | 5 | 12.1s |  |
| 26 | `Math-v8` | 5 | 5 | 1.4s |  |
| 27 | `Microphone-v6` | 31 | 31 | 2.6s |  |
| 28 | `Microphone-v7` | 31 | 31 | 2.4s |  |
| 29 | `Microphone-v8` | 31 | 31 | 1.1s |  |
| 30 | `MovieClip-v5` | 10 | 226 | 9.5s |  |
| 31 | `MovieClip-v6` | 20 | 60 | 36.8s |  |
| 32 | `MovieClip-v7` | 20 | 64 | 39.4s |  |
| 33 | `MovieClip-v8` | 25 | 68 | 50.1s |  |
| 34 | `MovieClipLoader-v7` | 118 | 118 | 3.3s |  |
| 35 | `MovieClipLoader-v8` | 118 | 118 | 2.0s |  |
| 36 | `NetConnection-v6` | 4 | 49 | 4.3s |  |
| 37 | `NetConnection-v7` | 4 | 45 | 4.5s |  |
| 38 | `NetConnection-v8` | 4 | 45 | 1.4s |  |
| 39 | `Object-v6` | 8 | 21 | 10.1s |  |
| 40 | `Object-v7` | 8 | 12 | 10.3s |  |
| 41 | `Object-v8` | 8 | 12 | 1.5s |  |
| 42 | `Sound-v5` | 14 | 16 | 5.7s |  |
| 43 | `Stage-v6` | 14 | 14 | 2.6s |  |
| 44 | `Stage-v7` | 14 | 14 | 2.2s |  |
| 45 | `Stage-v8` | 14 | 14 | 1.4s |  |
| 46 | `String-v5` | 14 | 21 | 13.4s |  |
| 47 | `TextField-v6` | 15 | 57 | 24.9s |  |
| 48 | `TextField-v7` | 15 | 73 | 26.6s |  |
| 49 | `TextField-v8` | 14 | 72 | 26.5s |  |
| 50 | `TextFormat-v7` | 38 | 38 | 4.8s |  |
| 51 | `TextFormat-v8` | 36 | 36 | 4.7s |  |
| 52 | `Transform-v8` | 7 | 7 | 3.7s |  |
| 53 | `XML-v5` | 9 | 79 | 10.3s |  |
| 54 | `XML-v8` | 21 | 116 | 3.4s |  |
| 55 | `array-v5` | 5 | 17 | 31.5s |  |
| 56 | `array-v6` | 6 | 25 | 37.0s |  |
| 57 | `array-v7` | 5 | 23 | 38.8s |  |
| 58 | `array-v8` | 5 | 23 | 3.9s |  |
| 59 | `setProperty-v5` | 49 | 49 | 3.3s |  |
| 60 | `setProperty-v6` | 49 | 49 | 3.3s |  |
| 61 | `setProperty-v7` | 49 | 49 | 3.1s |  |
| 62 | `setProperty-v8` | 49 | 49 | 1.9s |  |
| 63 | `toString_valueOf-v5` | 12 | 34 | 5.3s |  |

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
