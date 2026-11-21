# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-21 19:30 UTC

**Git SHA**: `bc91565cea`

**Run Duration**: 20m 38s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 235 |
| Passing | **144** (61.3%) |
| Ruffle-matched | 85 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **229** (97.4%) |
| Failing | 6 |
| Total expected lines | 35360 |
| Matching lines | 27384 (77.4%) |
| Mismatched lines | 7976 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**144 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.6s |  |
| 2 | `Accessibility-v6` | 19 | 1.6s |  |
| 3 | `Accessibility-v7` | 19 | 1.3s |  |
| 4 | `Accessibility-v8` | 19 | 1.0s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.5s |  |
| 6 | `AsBroadcaster-v6` | 121 | 3.6s |  |
| 7 | `AsBroadcaster-v7` | 121 | 3.3s |  |
| 8 | `AsBroadcaster-v8` | 121 | 1.1s |  |
| 9 | `BitmapData-v5` | 7 | 1.4s |  |
| 10 | `BitmapData-v6` | 7 | 0.4s |  |
| 11 | `BitmapData-v7` | 7 | 1.1s |  |
| 12 | `Boolean-v5` | 38 | 1.8s |  |
| 13 | `Boolean-v6` | 38 | 1.4s |  |
| 14 | `Boolean-v7` | 38 | 19.5s |  |
| 15 | `Boolean-v8` | 38 | 1.4s |  |
| 16 | `Camera-v5` | 7 | 2.0s |  |
| 17 | `Color-v5` | 140 | 5.3s |  |
| 18 | `Color-v6` | 171 | 6.3s |  |
| 19 | `Color-v7` | 161 | 6.1s |  |
| 20 | `Color-v8` | 161 | 4.6s |  |
| 21 | `ColorTransform-v5` | 7 | 1.4s |  |
| 22 | `ColorTransform-v6` | 7 | 0.4s |  |
| 23 | `ColorTransform-v7` | 7 | 1.2s |  |
| 24 | `ColorTransform-v8` | 55 | 2.4s |  |
| 25 | `ContextMenu-v5` | 7 | 1.4s |  |
| 26 | `ContextMenu-v6` | 7 | 0.5s |  |
| 27 | `ContextMenu-v7` | 131 | 3.5s |  |
| 28 | `ContextMenu-v8` | 131 | 19.0s |  |
| 29 | `Error-v5` | 28 | 1.7s |  |
| 30 | `Error-v6` | 31 | 1.8s |  |
| 31 | `Error-v7` | 31 | 1.5s |  |
| 32 | `Error-v8` | 31 | 1.9s |  |
| 33 | `ExternalInterface-v5` | 7 | 1.5s |  |
| 34 | `ExternalInterface-v6` | 55 | 2.1s |  |
| 35 | `ExternalInterface-v7` | 55 | 1.9s |  |
| 36 | `Function-v6` | 271 | 7.8s |  |
| 37 | `Function-v7` | 272 | 7.8s |  |
| 38 | `Function-v8` | 272 | 7.7s |  |
| 39 | `Global-v5` | 172 | 5.4s |  |
| 40 | `Global-v7` | 182 | 5.5s |  |
| 41 | `Global-v8` | 169 | 5.2s |  |
| 42 | `Instance-v5` | 52 | 2.1s |  |
| 43 | `Instance-v6` | 52 | 1.2s |  |
| 44 | `Instance-v7` | 52 | 1.8s |  |
| 45 | `Instance-v8` | 52 | 1.0s |  |
| 46 | `Key-v5` | 51 | 2.1s |  |
| 47 | `Key-v6` | 55 | 2.2s |  |
| 48 | `Key-v7` | 55 | 1.9s |  |
| 49 | `Key-v8` | 55 | 1.1s |  |
| 50 | `LoadVars-v5` | 8 | 1.5s |  |
| 51 | `LocalConnection-v5` | 7 | 1.4s |  |
| 52 | `LocalConnection-v6` | 58 | 2.3s |  |
| 53 | `LocalConnection-v7` | 58 | 2.0s |  |
| 54 | `LocalConnection-v8` | 58 | 1.1s |  |
| 55 | `Matrix-v5` | 7 | 2.0s |  |
| 56 | `Matrix-v6` | 168 | 7.7s |  |
| 57 | `Matrix-v7` | 168 | 7.5s |  |
| 58 | `Matrix-v8` | 168 | 1.6s |  |
| 59 | `Microphone-v5` | 6 | 1.9s |  |
| 60 | `MovieClipLoader-v5` | 6 | 17.5s |  |
| 61 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 62 | `NetConnection-v5` | 7 | 1.4s |  |
| 63 | `NetStream-v5` | 6 | 17.1s |  |
| 64 | `NetStream-v6` | 80 | 2.5s |  |
| 65 | `NetStream-v7` | 80 | 2.3s |  |
| 66 | `NetStream-v8` | 80 | 1.1s |  |
| 67 | `Number-v6` | 239 | 6.5s |  |
| 68 | `Number-v7` | 237 | 6.5s |  |
| 69 | `Number-v8` | 237 | 1.2s |  |
| 70 | `Point-v5` | 7 | 2.2s |  |
| 71 | `Point-v6` | 7 | 0.7s |  |
| 72 | `Point-v7` | 7 | 1.9s |  |
| 73 | `Point-v8` | 193 | 8.7s |  |
| 74 | `Random-v5` | 30 | 23.2s |  |
| 75 | `Random-v6` | 30 | 0.7s |  |
| 76 | `Random-v7` | 30 | 2.3s |  |
| 77 | `Random-v8` | 30 | 1.6s |  |
| 78 | `Rectangle-v5` | 7 | 2.2s |  |
| 79 | `Rectangle-v6` | 7 | 0.7s |  |
| 80 | `Rectangle-v7` | 7 | 1.8s |  |
| 81 | `Rectangle-v8` | 166 | 7.3s |  |
| 82 | `Selection-v5` | 21 | 18.9s |  |
| 83 | `Sound-v6` | 121 | 4.4s |  |
| 84 | `Sound-v7` | 121 | 4.2s |  |
| 85 | `Sound-v8` | 121 | 1.5s |  |
| 86 | `Stage-v5` | 38 | 18.1s |  |
| 87 | `System-v5` | 67 | 18.0s |  |
| 88 | `System-v6` | 100 | 2.9s |  |
| 89 | `System-v7` | 101 | 2.9s |  |
| 90 | `System-v8` | 101 | 1.1s |  |
| 91 | `TextFieldHTML-v5` | 6 | 17.8s |  |
| 92 | `TextFieldHTML-v6` | 37 | 2.0s |  |
| 93 | `TextFieldHTML-v7` | 37 | 1.7s |  |
| 94 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 95 | `TextFormat-v5` | 128 | 3.9s |  |
| 96 | `TextFormat-v6` | 128 | 0.5s |  |
| 97 | `TextSnapshot-v5` | 7 | 17.5s |  |
| 98 | `TextSnapshot-v6` | 173 | 6.0s |  |
| 99 | `TextSnapshot-v7` | 173 | 5.8s |  |
| 100 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 101 | `Transform-v5` | 7 | 1.5s |  |
| 102 | `Transform-v6` | 7 | 1.1s |  |
| 103 | `Transform-v7` | 7 | 1.2s |  |
| 104 | `Try-v5` | 20 | 24.2s |  |
| 105 | `Try-v6` | 20 | 0.7s |  |
| 106 | `Try-v7` | 20 | 3.0s |  |
| 107 | `Try-v8` | 20 | 1.7s |  |
| 108 | `Video-v5` | 7 | 2.3s |  |
| 109 | `Video-v6` | 85 | 3.9s |  |
| 110 | `Video-v7` | 85 | 3.5s |  |
| 111 | `Video-v8` | 85 | 1.7s |  |
| 112 | `XMLSocket-v5` | 35 | 2.8s |  |
| 113 | `XMLSocket-v6` | 35 | 2.7s |  |
| 114 | `XMLSocket-v7` | 35 | 2.4s |  |
| 115 | `XMLSocket-v8` | 35 | 1.6s |  |
| 116 | `argstest-v5` | 4 | 2.2s |  |
| 117 | `case-v5` | 39 | 3.3s |  |
| 118 | `case-v6` | 73 | 4.4s |  |
| 119 | `case-v7` | 67 | 4.3s |  |
| 120 | `case-v8` | 67 | 1.9s |  |
| 121 | `delete-v5` | 61 | 18.2s |  |
| 122 | `delete-v6` | 61 | 1.9s |  |
| 123 | `delete-v7` | 61 | 2.0s |  |
| 124 | `delete-v8` | 61 | 1.2s |  |
| 125 | `enumerate-v5` | 6 | 1.4s |  |
| 126 | `enumerate-v6` | 49 | 2.2s |  |
| 127 | `enumerate-v7` | 49 | 2.0s |  |
| 128 | `enumerate-v8` | 49 | 1.1s |  |
| 129 | `flash-v5` | 10 | 21.0s |  |
| 130 | `flash-v6` | 10 | 0.5s |  |
| 131 | `flash-v7` | 10 | 0.5s |  |
| 132 | `flash-v8` | 41 | 0.5s |  |
| 133 | `getvariable-v5` | 58 | 0.5s |  |
| 134 | `getvariable-v6` | 64 | 0.5s |  |
| 135 | `getvariable-v7` | 64 | 0.5s |  |
| 136 | `getvariable-v8` | 64 | 0.5s |  |
| 137 | `swap-v5` | 7 | 1.4s |  |
| 138 | `swap-v6` | 7 | 0.4s |  |
| 139 | `swap-v7` | 7 | 1.1s |  |
| 140 | `swap-v8` | 7 | 1.0s |  |
| 141 | `targetPath-v5` | 12 | 1.4s |  |
| 142 | `targetPath-v6` | 23 | 1.5s |  |
| 143 | `targetPath-v7` | 23 | 1.3s |  |
| 144 | `targetPath-v8` | 23 | 1.0s |  |

## Ruffle-Matched Tests

**85 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 19.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 3.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 3.8s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.1s |  |
| 5 | `BitmapData-v8` | 8 | 8 | 17.9s |  |
| 6 | `Camera-v6` | 57 | 57 | 4.3s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.5s |  |
| 8 | `Camera-v8` | 57 | 57 | 1.4s |  |
| 9 | `Date-v5` | 7 | 7 | 9.8s |  |
| 10 | `Date-v6` | 6 | 6 | 11.0s |  |
| 11 | `Date-v7` | 6 | 6 | 11.4s |  |
| 12 | `Date-v8` | 6 | 6 | 1.3s |  |
| 13 | `ExternalInterface-v8` | 4 | 4 | 3.9s |  |
| 14 | `Function-v5` | 10 | 25 | 4.4s |  |
| 15 | `Global-v6` | 9 | 10 | 6.5s |  |
| 16 | `HitTest-v6` | 8 | 8 | 3.7s |  |
| 17 | `HitTest-v7` | 8 | 8 | 3.4s |  |
| 18 | `HitTest-v8` | 9 | 9 | 3.3s |  |
| 19 | `Inheritance-v5` | 1 | 17 | 18.8s |  |
| 20 | `Inheritance-v6` | 9 | 13 | 4.7s |  |
| 21 | `Inheritance-v7` | 5 | 7 | 4.8s |  |
| 22 | `Inheritance-v8` | 5 | 7 | 1.5s |  |
| 23 | `LoadVars-v6` | 6 | 8 | 4.1s |  |
| 24 | `LoadVars-v7` | 6 | 8 | 3.9s |  |
| 25 | `LoadVars-v8` | 6 | 8 | 1.8s |  |
| 26 | `Math-v5` | 5 | 5 | 10.4s |  |
| 27 | `Math-v6` | 5 | 5 | 0.6s |  |
| 28 | `Math-v7` | 5 | 5 | 10.6s |  |
| 29 | `Math-v8` | 5 | 5 | 1.2s |  |
| 30 | `Microphone-v6` | 31 | 31 | 3.3s |  |
| 31 | `Microphone-v7` | 31 | 31 | 2.9s |  |
| 32 | `Microphone-v8` | 31 | 31 | 1.4s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 3.0s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 1.9s |  |
| 35 | `NetConnection-v6` | 4 | 49 | 3.6s |  |
| 36 | `NetConnection-v7` | 4 | 45 | 3.7s |  |
| 37 | `NetConnection-v8` | 4 | 45 | 1.2s |  |
| 38 | `Number-v5` | 8 | 12 | 6.6s |  |
| 39 | `Object-v5` | 3 | 4 | 27.1s |  |
| 40 | `Object-v6` | 8 | 21 | 13.6s |  |
| 41 | `Object-v7` | 8 | 12 | 13.9s |  |
| 42 | `Object-v8` | 8 | 12 | 2.5s |  |
| 43 | `Selection-v6` | 7 | 13 | 4.5s |  |
| 44 | `Selection-v7` | 7 | 13 | 4.2s |  |
| 45 | `Selection-v8` | 7 | 13 | 1.2s |  |
| 46 | `Sound-v5` | 14 | 16 | 4.3s |  |
| 47 | `Stage-v6` | 14 | 14 | 2.4s |  |
| 48 | `Stage-v7` | 14 | 14 | 2.1s |  |
| 49 | `Stage-v8` | 14 | 14 | 1.2s |  |
| 50 | `String-v5` | 18 | 21 | 13.6s |  |
| 51 | `String-v6` | 9 | 10 | 14.0s |  |
| 52 | `String-v7` | 9 | 10 | 13.5s |  |
| 53 | `String-v8` | 9 | 10 | 1.4s |  |
| 54 | `TextField-v5` | 3 | 3 | 1.5s |  |
| 55 | `TextFormat-v7` | 38 | 40 | 5.4s |  |
| 56 | `TextFormat-v8` | 36 | 38 | 5.3s |  |
| 57 | `Transform-v8` | 7 | 7 | 3.7s |  |
| 58 | `XML-v5` | 10 | 79 | 11.2s |  |
| 59 | `XML-v6` | 3 | 98 | 12.3s |  |
| 60 | `XML-v7` | 3 | 98 | 12.3s |  |
| 61 | `XML-v8` | 24 | 116 | 3.5s |  |
| 62 | `XMLNode-v5` | 3 | 22 | 6.5s |  |
| 63 | `XMLNode-v6` | 3 | 22 | 6.5s |  |
| 64 | `XMLNode-v7` | 3 | 22 | 5.9s |  |
| 65 | `XMLNode-v8` | 3 | 22 | 1.2s |  |
| 66 | `array-v5` | 5 | 17 | 55.7s |  |
| 67 | `array-v6` | 6 | 25 | 37.4s |  |
| 68 | `array-v7` | 5 | 23 | 39.6s |  |
| 69 | `array-v8` | 5 | 23 | 3.9s |  |
| 70 | `ops-v5` | 7 | 9 | 22.1s |  |
| 71 | `ops-v6` | 7 | 11 | 6.3s |  |
| 72 | `ops-v7` | 7 | 11 | 6.8s |  |
| 73 | `ops-v8` | 7 | 11 | 1.2s |  |
| 74 | `setProperty-v5` | 49 | 49 | 2.2s |  |
| 75 | `setProperty-v6` | 49 | 49 | 2.2s |  |
| 76 | `setProperty-v7` | 49 | 49 | 2.0s |  |
| 77 | `setProperty-v8` | 49 | 49 | 1.3s |  |
| 78 | `toString_valueOf-v5` | 34 | 34 | 3.6s |  |
| 79 | `toString_valueOf-v6` | 5 | 5 | 4.0s |  |
| 80 | `toString_valueOf-v7` | 5 | 5 | 3.7s |  |
| 81 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 82 | `with-v5` | 3 | 3 | 2.5s |  |
| 83 | `with-v6` | 6 | 9 | 3.4s |  |
| 84 | `with-v7` | 6 | 9 | 3.2s |  |
| 85 | `with-v8` | 6 | 9 | 1.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**3 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `TextField-v6` | 85.7% | 467 | 545 | 78 |  |
| 2 | `TextField-v8` | 83.7% | 478 | 571 | 93 |  |
| 3 | `TextField-v7` | 83.5% | 476 | 570 | 94 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `TextField-v6` | 85.7% | 467/545 | 545 | 545 |  |
| 2 | `TextField-v8` | 83.7% | 478/571 | 571 | 571 |  |
| 3 | `TextField-v7` | 83.5% | 476/570 | 570 | 570 |  |
| 4 | `argstest-v8` | 5.8% | 175/3023 | 3023 | 2434 |  |
| 5 | `argstest-v7` | 4.1% | 110/2661 | 2661 | 2061 |  |
| 6 | `argstest-v6` | 3.0% | 80/2661 | 2661 | 2192 |  |
