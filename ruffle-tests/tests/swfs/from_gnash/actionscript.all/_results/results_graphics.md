# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-23 19:43 UTC

**Git SHA**: `1396f1e10b`

**Run Duration**: 31m 3s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 243 |
| Passing | **148** (60.9%) |
| Ruffle-matched | 92 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **240** (98.8%) |
| Failing | 3 |
| Total expected lines | 38791 |
| Matching lines | 30884 (79.6%) |
| Mismatched lines | 7907 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**148 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 3.3s |  |
| 2 | `Accessibility-v6` | 19 | 3.5s |  |
| 3 | `Accessibility-v7` | 19 | 3.1s |  |
| 4 | `Accessibility-v8` | 19 | 2.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 3.3s |  |
| 6 | `AsBroadcaster-v6` | 121 | 30.3s |  |
| 7 | `AsBroadcaster-v7` | 121 | 6.7s |  |
| 8 | `AsBroadcaster-v8` | 121 | 3.0s |  |
| 9 | `BitmapData-v5` | 7 | 3.4s |  |
| 10 | `BitmapData-v6` | 7 | 1.6s |  |
| 11 | `BitmapData-v7` | 7 | 3.0s |  |
| 12 | `Boolean-v5` | 38 | 4.1s |  |
| 13 | `Boolean-v6` | 38 | 3.6s |  |
| 14 | `Boolean-v7` | 38 | 19.6s |  |
| 15 | `Boolean-v8` | 38 | 1.7s |  |
| 16 | `Camera-v5` | 7 | 2.1s |  |
| 17 | `Color-v5` | 140 | 4.6s |  |
| 18 | `Color-v6` | 171 | 5.3s |  |
| 19 | `Color-v7` | 161 | 5.0s |  |
| 20 | `Color-v8` | 161 | 25.4s |  |
| 21 | `ColorTransform-v5` | 7 | 2.8s |  |
| 22 | `ColorTransform-v6` | 7 | 1.3s |  |
| 23 | `ColorTransform-v7` | 7 | 2.5s |  |
| 24 | `ColorTransform-v8` | 55 | 4.0s |  |
| 25 | `ContextMenu-v5` | 7 | 3.0s |  |
| 26 | `ContextMenu-v6` | 7 | 1.4s |  |
| 27 | `ContextMenu-v7` | 131 | 6.1s |  |
| 28 | `ContextMenu-v8` | 131 | 22.1s |  |
| 29 | `Error-v5` | 28 | 2.5s |  |
| 30 | `Error-v6` | 31 | 2.6s |  |
| 31 | `Error-v7` | 31 | 2.3s |  |
| 32 | `Error-v8` | 31 | 3.8s |  |
| 33 | `ExternalInterface-v5` | 7 | 3.3s |  |
| 34 | `ExternalInterface-v6` | 55 | 4.2s |  |
| 35 | `ExternalInterface-v7` | 55 | 3.9s |  |
| 36 | `Function-v6` | 271 | 11.9s |  |
| 37 | `Function-v7` | 272 | 11.8s |  |
| 38 | `Function-v8` | 272 | 35.1s |  |
| 39 | `Global-v5` | 172 | 8.9s |  |
| 40 | `Global-v7` | 182 | 9.4s |  |
| 41 | `Global-v8` | 169 | 8.9s |  |
| 42 | `Instance-v5` | 52 | 4.3s |  |
| 43 | `Instance-v6` | 52 | 2.5s |  |
| 44 | `Instance-v7` | 52 | 3.8s |  |
| 45 | `Instance-v8` | 52 | 2.6s |  |
| 46 | `Key-v5` | 51 | 21.4s |  |
| 47 | `Key-v6` | 55 | 3.8s |  |
| 48 | `Key-v7` | 55 | 3.5s |  |
| 49 | `Key-v8` | 55 | 2.2s |  |
| 50 | `LoadVars-v5` | 8 | 3.0s |  |
| 51 | `LocalConnection-v5` | 7 | 25.8s |  |
| 52 | `LocalConnection-v6` | 58 | 4.5s |  |
| 53 | `LocalConnection-v7` | 58 | 4.1s |  |
| 54 | `LocalConnection-v8` | 58 | 2.7s |  |
| 55 | `Matrix-v5` | 7 | 24.8s |  |
| 56 | `Matrix-v6` | 168 | 8.6s |  |
| 57 | `Matrix-v7` | 168 | 8.7s |  |
| 58 | `Matrix-v8` | 168 | 2.7s |  |
| 59 | `Microphone-v5` | 6 | 3.1s |  |
| 60 | `Mouse-v5` | 13 | 19.1s |  |
| 61 | `Mouse-v6` | 21 | 2.2s |  |
| 62 | `Mouse-v7` | 21 | 2.0s |  |
| 63 | `Mouse-v8` | 21 | 1.7s |  |
| 64 | `MovieClipLoader-v5` | 6 | 25.3s |  |
| 65 | `MovieClipLoader-v6` | 6 | 1.3s |  |
| 66 | `NetConnection-v5` | 7 | 2.9s |  |
| 67 | `NetStream-v5` | 6 | 2.0s |  |
| 68 | `NetStream-v6` | 80 | 3.2s |  |
| 69 | `NetStream-v7` | 80 | 3.0s |  |
| 70 | `NetStream-v8` | 80 | 1.7s |  |
| 71 | `Number-v6` | 239 | 7.5s |  |
| 72 | `Number-v7` | 237 | 7.3s |  |
| 73 | `Number-v8` | 237 | 1.8s |  |
| 74 | `Point-v5` | 7 | 2.0s |  |
| 75 | `Point-v6` | 7 | 1.0s |  |
| 76 | `Point-v7` | 7 | 1.8s |  |
| 77 | `Point-v8` | 193 | 6.2s |  |
| 78 | `Random-v5` | 30 | 19.5s |  |
| 79 | `Random-v6` | 30 | 1.0s |  |
| 80 | `Random-v7` | 30 | 2.2s |  |
| 81 | `Random-v8` | 30 | 1.7s |  |
| 82 | `Rectangle-v5` | 7 | 2.1s |  |
| 83 | `Rectangle-v6` | 7 | 1.0s |  |
| 84 | `Rectangle-v7` | 7 | 1.8s |  |
| 85 | `Rectangle-v8` | 166 | 6.0s |  |
| 86 | `Selection-v5` | 21 | 19.7s |  |
| 87 | `Sound-v6` | 121 | 5.0s |  |
| 88 | `Sound-v7` | 121 | 4.8s |  |
| 89 | `Sound-v8` | 121 | 2.2s |  |
| 90 | `Stage-v5` | 38 | 26.7s |  |
| 91 | `System-v5` | 67 | 20.4s |  |
| 92 | `System-v6` | 100 | 3.7s |  |
| 93 | `System-v7` | 101 | 3.8s |  |
| 94 | `System-v8` | 101 | 1.8s |  |
| 95 | `TextFieldHTML-v5` | 6 | 17.1s |  |
| 96 | `TextFieldHTML-v6` | 37 | 3.0s |  |
| 97 | `TextFieldHTML-v7` | 37 | 2.5s |  |
| 98 | `TextFieldHTML-v8` | 37 | 1.9s |  |
| 99 | `TextFormat-v5` | 128 | 4.9s |  |
| 100 | `TextFormat-v6` | 128 | 1.1s |  |
| 101 | `TextSnapshot-v5` | 7 | 20.2s |  |
| 102 | `TextSnapshot-v6` | 173 | 7.3s |  |
| 103 | `TextSnapshot-v7` | 173 | 7.0s |  |
| 104 | `TextSnapshot-v8` | 173 | 1.9s |  |
| 105 | `Transform-v5` | 7 | 2.2s |  |
| 106 | `Transform-v6` | 7 | 1.8s |  |
| 107 | `Transform-v7` | 7 | 1.9s |  |
| 108 | `Try-v5` | 20 | 20.9s |  |
| 109 | `Try-v6` | 20 | 1.1s |  |
| 110 | `Try-v7` | 20 | 2.8s |  |
| 111 | `Try-v8` | 20 | 1.8s |  |
| 112 | `Video-v5` | 7 | 2.2s |  |
| 113 | `Video-v6` | 85 | 3.5s |  |
| 114 | `Video-v7` | 85 | 3.2s |  |
| 115 | `Video-v8` | 85 | 1.8s |  |
| 116 | `XMLSocket-v5` | 35 | 20.3s |  |
| 117 | `XMLSocket-v6` | 35 | 2.7s |  |
| 118 | `XMLSocket-v7` | 35 | 2.4s |  |
| 119 | `XMLSocket-v8` | 35 | 1.9s |  |
| 120 | `argstest-v5` | 4 | 2.3s |  |
| 121 | `case-v5` | 39 | 3.8s |  |
| 122 | `case-v6` | 73 | 4.8s |  |
| 123 | `case-v7` | 67 | 4.7s |  |
| 124 | `case-v8` | 67 | 2.7s |  |
| 125 | `delete-v5` | 61 | 19.6s |  |
| 126 | `delete-v6` | 61 | 2.5s |  |
| 127 | `delete-v7` | 61 | 2.6s |  |
| 128 | `delete-v8` | 61 | 1.8s |  |
| 129 | `enumerate-v5` | 6 | 2.0s |  |
| 130 | `enumerate-v6` | 49 | 2.8s |  |
| 131 | `enumerate-v7` | 49 | 2.6s |  |
| 132 | `enumerate-v8` | 49 | 1.7s |  |
| 133 | `flash-v5` | 10 | 19.9s |  |
| 134 | `flash-v6` | 10 | 2.1s |  |
| 135 | `flash-v7` | 10 | 1.9s |  |
| 136 | `flash-v8` | 41 | 2.9s |  |
| 137 | `getvariable-v5` | 58 | 3.1s |  |
| 138 | `getvariable-v6` | 64 | 3.2s |  |
| 139 | `getvariable-v7` | 64 | 3.5s |  |
| 140 | `getvariable-v8` | 64 | 1.9s |  |
| 141 | `swap-v5` | 7 | 19.0s |  |
| 142 | `swap-v6` | 7 | 1.0s |  |
| 143 | `swap-v7` | 7 | 1.8s |  |
| 144 | `swap-v8` | 7 | 1.7s |  |
| 145 | `targetPath-v5` | 12 | 2.1s |  |
| 146 | `targetPath-v6` | 23 | 2.3s |  |
| 147 | `targetPath-v7` | 23 | 2.0s |  |
| 148 | `targetPath-v8` | 23 | 1.7s |  |

## Ruffle-Matched Tests

**92 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 30.2s |  |
| 2 | `ASnative-v6` | 40 | 40 | 7.2s |  |
| 3 | `ASnative-v7` | 40 | 40 | 7.0s |  |
| 4 | `ASnative-v8` | 40 | 40 | 2.9s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 28.9s |  |
| 6 | `Camera-v6` | 57 | 57 | 3.7s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.4s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.8s |  |
| 9 | `Date-v5` | 7 | 7 | 12.1s |  |
| 10 | `Date-v6` | 6 | 6 | 13.4s |  |
| 11 | `Date-v7` | 6 | 6 | 13.8s |  |
| 12 | `Date-v8` | 6 | 6 | 2.1s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 6.6s |  |
| 14 | `Function-v5` | 10 | 25 | 7.6s |  |
| 15 | `Global-v6` | 9 | 10 | 10.6s |  |
| 16 | `HitTest-v6` | 8 | 8 | 6.9s |  |
| 17 | `HitTest-v7` | 8 | 8 | 6.5s |  |
| 18 | `HitTest-v8` | 9 | 9 | 6.2s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 28.5s |  |
| 20 | `Inheritance-v6` | 9 | 13 | 8.3s |  |
| 21 | `Inheritance-v7` | 5 | 7 | 8.5s |  |
| 22 | `Inheritance-v8` | 5 | 7 | 3.3s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 6.3s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 6.3s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 3.1s |  |
| 26 | `Math-v5` | 5 | 5 | 16.0s |  |
| 27 | `Math-v6` | 5 | 5 | 1.7s |  |
| 28 | `Math-v7` | 5 | 5 | 16.5s |  |
| 29 | `Math-v8` | 5 | 5 | 3.0s |  |
| 30 | `Microphone-v6` | 31 | 31 | 4.7s |  |
| 31 | `Microphone-v7` | 31 | 31 | 4.4s |  |
| 32 | `Microphone-v8` | 31 | 31 | 2.7s |  |
| 33 | `MovieClip-v5` | 11 | 226 | 11.2s |  |
| 34 | `MovieClip-v6` | 20 | 60 | 39.3s |  |
| 35 | `MovieClip-v7` | 20 | 64 | 42.5s |  |
| 36 | `MovieClip-v8` | 25 | 68 | 54.3s |  |
| 37 | `MovieClipLoader-v7` | 118 | 118 | 5.0s |  |
| 38 | `MovieClipLoader-v8` | 118 | 118 | 3.5s |  |
| 39 | `NetConnection-v6` | 4 | 49 | 6.4s |  |
| 40 | `NetConnection-v7` | 4 | 45 | 6.3s |  |
| 41 | `NetConnection-v8` | 4 | 45 | 2.6s |  |
| 42 | `Number-v5` | 8 | 12 | 7.4s |  |
| 43 | `Object-v5` | 3 | 4 | 4.6s |  |
| 44 | `Object-v6` | 8 | 21 | 10.2s |  |
| 45 | `Object-v7` | 8 | 12 | 10.5s |  |
| 46 | `Object-v8` | 8 | 12 | 2.2s |  |
| 47 | `Selection-v6` | 7 | 13 | 4.8s |  |
| 48 | `Selection-v7` | 7 | 13 | 4.7s |  |
| 49 | `Selection-v8` | 7 | 13 | 1.8s |  |
| 50 | `Sound-v5` | 14 | 16 | 4.8s |  |
| 51 | `Stage-v6` | 14 | 14 | 4.6s |  |
| 52 | `Stage-v7` | 14 | 14 | 4.2s |  |
| 53 | `Stage-v8` | 14 | 14 | 2.9s |  |
| 54 | `String-v5` | 18 | 21 | 19.3s |  |
| 55 | `String-v6` | 9 | 10 | 20.0s |  |
| 56 | `String-v7` | 9 | 10 | 19.8s |  |
| 57 | `String-v8` | 9 | 10 | 3.3s |  |
| 58 | `TextField-v5` | 3 | 3 | 2.2s |  |
| 59 | `TextField-v6` | 13 | 57 | 19.6s |  |
| 60 | `TextField-v7` | 13 | 73 | 21.2s |  |
| 61 | `TextField-v8` | 12 | 72 | 21.3s |  |
| 62 | `TextFormat-v7` | 38 | 38 | 6.3s |  |
| 63 | `TextFormat-v8` | 36 | 36 | 6.2s |  |
| 64 | `Transform-v8` | 7 | 7 | 4.8s |  |
| 65 | `XML-v5` | 10 | 79 | 29.3s |  |
| 66 | `XML-v6` | 3 | 98 | 14.2s |  |
| 67 | `XML-v7` | 3 | 98 | 14.1s |  |
| 68 | `XML-v8` | 24 | 116 | 4.5s |  |
| 69 | `XMLNode-v5` | 3 | 22 | 7.9s |  |
| 70 | `XMLNode-v6` | 3 | 22 | 7.8s |  |
| 71 | `XMLNode-v7` | 3 | 22 | 7.0s |  |
| 72 | `XMLNode-v8` | 3 | 22 | 2.0s |  |
| 73 | `array-v5` | 5 | 17 | 52.6s |  |
| 74 | `array-v6` | 6 | 25 | 36.1s |  |
| 75 | `array-v7` | 5 | 23 | 38.4s |  |
| 76 | `array-v8` | 5 | 23 | 4.5s |  |
| 77 | `ops-v5` | 7 | 9 | 16.8s |  |
| 78 | `ops-v6` | 7 | 11 | 1.2s |  |
| 79 | `ops-v7` | 7 | 11 | 1.2s |  |
| 80 | `ops-v8` | 7 | 11 | 1.2s |  |
| 81 | `setProperty-v5` | 49 | 49 | 1.1s |  |
| 82 | `setProperty-v6` | 49 | 49 | 1.1s |  |
| 83 | `setProperty-v7` | 49 | 49 | 1.1s |  |
| 84 | `setProperty-v8` | 49 | 49 | 1.1s |  |
| 85 | `toString_valueOf-v5` | 34 | 34 | 21.8s |  |
| 86 | `toString_valueOf-v6` | 5 | 5 | 4.9s |  |
| 87 | `toString_valueOf-v7` | 5 | 5 | 4.7s |  |
| 88 | `toString_valueOf-v8` | 5 | 5 | 1.8s |  |
| 89 | `with-v5` | 3 | 3 | 3.4s |  |
| 90 | `with-v6` | 6 | 9 | 4.3s |  |
| 91 | `with-v7` | 6 | 9 | 4.0s |  |
| 92 | `with-v8` | 6 | 9 | 2.0s |  |

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
