# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-03 23:46 UTC

**Git SHA**: `5e58450d1d`

**Run Duration**: 21m 48s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **124** (65.3%) |
| Ruffle-matched | 61 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **185** (97.4%) |
| Failing | 5 |
| Total expected lines | 16957 |
| Matching lines | 15351 (90.5%) |
| Mismatched lines | 1606 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 5 | 100.0% |

## Passing Tests

**124 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.9s |  |
| 2 | `Accessibility-v6` | 19 | 1.9s |  |
| 3 | `Accessibility-v7` | 19 | 1.6s |  |
| 4 | `Accessibility-v8` | 19 | 19.0s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.8s |  |
| 6 | `BitmapData-v5` | 7 | 1.7s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 19.5s |  |
| 9 | `Boolean-v5` | 38 | 2.4s |  |
| 10 | `Boolean-v6` | 38 | 1.8s |  |
| 11 | `Boolean-v7` | 38 | 2.3s |  |
| 12 | `Boolean-v8` | 38 | 1.2s |  |
| 13 | `Camera-v5` | 7 | 1.8s |  |
| 14 | `Color-v5` | 140 | 5.3s |  |
| 15 | `Color-v6` | 171 | 6.3s |  |
| 16 | `Color-v7` | 161 | 6.0s |  |
| 17 | `Color-v8` | 161 | 1.2s |  |
| 18 | `ColorTransform-v5` | 7 | 18.8s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.4s |  |
| 21 | `ColorTransform-v8` | 55 | 3.1s |  |
| 22 | `ContextMenu-v5` | 7 | 1.7s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.7s |  |
| 25 | `ContextMenu-v8` | 131 | 22.2s |  |
| 26 | `Error-v5` | 28 | 2.2s |  |
| 27 | `Error-v6` | 31 | 2.3s |  |
| 28 | `Error-v7` | 31 | 1.9s |  |
| 29 | `Error-v8` | 31 | 1.2s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.7s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.8s |  |
| 32 | `ExternalInterface-v7` | 55 | 20.9s |  |
| 33 | `Instance-v5` | 52 | 2.5s |  |
| 34 | `Instance-v6` | 52 | 1.4s |  |
| 35 | `Instance-v7` | 52 | 20.3s |  |
| 36 | `Instance-v8` | 52 | 1.2s |  |
| 37 | `Key-v5` | 51 | 2.7s |  |
| 38 | `Key-v6` | 55 | 2.8s |  |
| 39 | `Key-v7` | 55 | 2.4s |  |
| 40 | `Key-v8` | 55 | 1.2s |  |
| 41 | `LoadVars-v5` | 8 | 19.5s |  |
| 42 | `LocalConnection-v5` | 7 | 18.4s |  |
| 43 | `LocalConnection-v6` | 58 | 2.8s |  |
| 44 | `LocalConnection-v7` | 58 | 2.4s |  |
| 45 | `LocalConnection-v8` | 58 | 1.2s |  |
| 46 | `Matrix-v5` | 7 | 1.7s |  |
| 47 | `Microphone-v5` | 6 | 1.7s |  |
| 48 | `Mouse-v5` | 13 | 18.5s |  |
| 49 | `Mouse-v6` | 21 | 2.0s |  |
| 50 | `Mouse-v7` | 21 | 1.6s |  |
| 51 | `Mouse-v8` | 21 | 1.2s |  |
| 52 | `MovieClipLoader-v5` | 6 | 1.7s |  |
| 53 | `MovieClipLoader-v6` | 6 | 19.0s |  |
| 54 | `NetConnection-v5` | 7 | 18.3s |  |
| 55 | `NetStream-v5` | 6 | 1.6s |  |
| 56 | `NetStream-v6` | 80 | 3.2s |  |
| 57 | `NetStream-v7` | 80 | 20.4s |  |
| 58 | `NetStream-v8` | 80 | 1.2s |  |
| 59 | `Number-v6` | 239 | 8.9s |  |
| 60 | `Number-v7` | 237 | 8.9s |  |
| 61 | `Number-v8` | 237 | 1.3s |  |
| 62 | `Point-v5` | 7 | 18.9s |  |
| 63 | `Point-v6` | 7 | 0.5s |  |
| 64 | `Point-v7` | 7 | 1.2s |  |
| 65 | `Point-v8` | 193 | 7.5s |  |
| 66 | `Random-v5` | 30 | 2.2s |  |
| 67 | `Random-v6` | 30 | 0.6s |  |
| 68 | `Random-v7` | 30 | 20.4s |  |
| 69 | `Random-v8` | 30 | 1.3s |  |
| 70 | `Rectangle-v5` | 7 | 1.8s |  |
| 71 | `Rectangle-v6` | 7 | 0.6s |  |
| 72 | `Rectangle-v7` | 7 | 1.4s |  |
| 73 | `Selection-v5` | 21 | 18.3s |  |
| 74 | `Stage-v5` | 38 | 18.5s |  |
| 75 | `System-v5` | 67 | 3.3s |  |
| 76 | `System-v6` | 100 | 4.2s |  |
| 77 | `System-v7` | 101 | 4.2s |  |
| 78 | `System-v8` | 101 | 1.2s |  |
| 79 | `TextFieldHTML-v5` | 6 | 18.0s |  |
| 80 | `TextFieldHTML-v6` | 37 | 2.3s |  |
| 81 | `TextFieldHTML-v7` | 37 | 1.9s |  |
| 82 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 83 | `TextFormat-v5` | 128 | 4.5s |  |
| 84 | `TextFormat-v6` | 128 | 0.6s |  |
| 85 | `TextSnapshot-v5` | 7 | 1.7s |  |
| 86 | `TextSnapshot-v6` | 173 | 7.7s |  |
| 87 | `TextSnapshot-v7` | 173 | 7.2s |  |
| 88 | `TextSnapshot-v8` | 173 | 1.3s |  |
| 89 | `Transform-v5` | 7 | 1.7s |  |
| 90 | `Transform-v6` | 7 | 18.0s |  |
| 91 | `Transform-v7` | 7 | 1.3s |  |
| 92 | `Try-v5` | 20 | 2.7s |  |
| 93 | `Try-v6` | 20 | 0.6s |  |
| 94 | `Try-v7` | 20 | 2.3s |  |
| 95 | `Try-v8` | 20 | 1.2s |  |
| 96 | `Video-v5` | 7 | 18.8s |  |
| 97 | `Video-v6` | 85 | 3.3s |  |
| 98 | `Video-v7` | 85 | 2.9s |  |
| 99 | `Video-v8` | 85 | 1.2s |  |
| 100 | `XMLSocket-v5` | 35 | 19.1s |  |
| 101 | `XMLSocket-v6` | 35 | 2.3s |  |
| 102 | `XMLSocket-v7` | 35 | 18.8s |  |
| 103 | `XMLSocket-v8` | 35 | 1.2s |  |
| 104 | `argstest-v5` | 4 | 1.7s |  |
| 105 | `case-v5` | 39 | 2.2s |  |
| 106 | `case-v6` | 73 | 3.2s |  |
| 107 | `case-v7` | 67 | 20.0s |  |
| 108 | `case-v8` | 67 | 1.3s |  |
| 109 | `delete-v5` | 60 | 2.8s |  |
| 110 | `delete-v6` | 60 | 2.2s |  |
| 111 | `delete-v7` | 60 | 2.4s |  |
| 112 | `delete-v8` | 60 | 1.3s |  |
| 113 | `enumerate-v5` | 6 | 18.6s |  |
| 114 | `enumerate-v6` | 49 | 2.7s |  |
| 115 | `enumerate-v7` | 49 | 2.4s |  |
| 116 | `enumerate-v8` | 49 | 1.2s |  |
| 117 | `flash-v5` | 10 | 1.8s |  |
| 118 | `flash-v6` | 10 | 1.8s |  |
| 119 | `flash-v7` | 10 | 19.0s |  |
| 120 | `swap-v5` | 7 | 1.7s |  |
| 121 | `swap-v6` | 7 | 0.6s |  |
| 122 | `swap-v7` | 7 | 1.3s |  |
| 123 | `swap-v8` | 7 | 1.2s |  |
| 124 | `targetPath-v5` | 12 | 18.4s |  |

## Ruffle-Matched Tests

**61 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 22.5s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 4.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.5s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.3s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 24.2s |  |
| 9 | `Camera-v6` | 57 | 57 | 20.6s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.5s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.2s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 4.7s |  |
| 13 | `HitTest-v6` | 8 | 8 | 4.6s |  |
| 14 | `HitTest-v7` | 8 | 8 | 4.2s |  |
| 15 | `HitTest-v8` | 9 | 9 | 20.9s |  |
| 16 | `Inheritance-v5` | 1 | 17 | 4.2s |  |
| 17 | `Inheritance-v6` | 9 | 16 | 6.1s |  |
| 18 | `Inheritance-v7` | 5 | 10 | 6.2s |  |
| 19 | `Inheritance-v8` | 5 | 10 | 1.6s |  |
| 20 | `LoadVars-v6` | 6 | 8 | 22.1s |  |
| 21 | `LoadVars-v7` | 6 | 8 | 4.9s |  |
| 22 | `LoadVars-v8` | 6 | 8 | 2.0s |  |
| 23 | `Math-v5` | 5 | 5 | 29.4s |  |
| 24 | `Math-v6` | 5 | 5 | 0.7s |  |
| 25 | `Math-v7` | 5 | 5 | 13.3s |  |
| 26 | `Math-v8` | 5 | 5 | 1.3s |  |
| 27 | `Matrix-v6` | 29 | 71 | 6.7s |  |
| 28 | `Matrix-v7` | 28 | 70 | 23.3s |  |
| 29 | `Matrix-v8` | 28 | 70 | 1.2s |  |
| 30 | `Microphone-v6` | 31 | 31 | 3.2s |  |
| 31 | `Microphone-v7` | 31 | 31 | 2.7s |  |
| 32 | `Microphone-v8` | 31 | 31 | 1.1s |  |
| 33 | `MovieClip-v5` | 48 | 226 | 29.7s |  |
| 34 | `MovieClipLoader-v7` | 118 | 118 | 3.7s |  |
| 35 | `MovieClipLoader-v8` | 118 | 118 | 2.3s |  |
| 36 | `Number-v5` | 8 | 13 | 9.2s |  |
| 37 | `Rectangle-v8` | 21 | 21 | 7.2s |  |
| 38 | `Selection-v6` | 7 | 13 | 4.8s |  |
| 39 | `Selection-v7` | 7 | 13 | 4.5s |  |
| 40 | `Selection-v8` | 7 | 13 | 1.2s |  |
| 41 | `Sound-v5` | 27 | 27 | 20.7s |  |
| 42 | `Sound-v6` | 30 | 51 | 4.7s |  |
| 43 | `Sound-v7` | 28 | 51 | 21.4s |  |
| 44 | `Sound-v8` | 28 | 51 | 1.5s |  |
| 45 | `String-v5` | 19 | 21 | 14.9s |  |
| 46 | `String-v6` | 10 | 10 | 15.8s |  |
| 47 | `String-v7` | 10 | 10 | 15.4s |  |
| 48 | `String-v8` | 10 | 10 | 35.5s |  |
| 49 | `TextField-v5` | 3 | 3 | 1.9s |  |
| 50 | `ops-v8` | 7 | 11 | 9.7s |  |
| 51 | `targetPath-v6` | 17 | 17 | 2.0s |  |
| 52 | `targetPath-v7` | 17 | 17 | 1.6s |  |
| 53 | `targetPath-v8` | 17 | 17 | 1.1s |  |
| 54 | `toString_valueOf-v5` | 34 | 34 | 4.7s |  |
| 55 | `toString_valueOf-v6` | 5 | 5 | 5.2s |  |
| 56 | `toString_valueOf-v7` | 5 | 5 | 24.5s |  |
| 57 | `toString_valueOf-v8` | 5 | 5 | 1.4s |  |
| 58 | `with-v5` | 42 | 42 | 3.7s |  |
| 59 | `with-v6` | 91 | 91 | 5.2s |  |
| 60 | `with-v7` | 91 | 91 | 4.6s |  |
| 61 | `with-v8` | 91 | 91 | 1.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Global-v7` | 96.2% | 175 | 182 | 7 |  |
| 2 | `Global-v8` | 95.9% | 162 | 169 | 7 |  |
| 3 | `Global-v6` | 93.3% | 196 | 210 | 14 |  |
| 4 | `array-v5` | 92.3% | 517 | 560 | 43 |  |
| 5 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |

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
| 1 | `Global-v7` | 96.2% | 175/182 | 181 | 182 |  |
| 2 | `Global-v8` | 95.9% | 162/169 | 168 | 169 |  |
| 3 | `Global-v6` | 93.3% | 196/210 | 209 | 210 |  |
| 4 | `array-v5` | 92.3% | 517/560 | 560 | 560 |  |
| 5 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
