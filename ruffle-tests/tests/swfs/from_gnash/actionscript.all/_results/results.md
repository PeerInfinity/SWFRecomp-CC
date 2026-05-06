# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-06 04:11 UTC

**Git SHA**: `b91b7202e8`

**Run Duration**: 21m 26s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **126** (66.3%) |
| Ruffle-matched | 62 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **188** (98.9%) |
| Failing | 2 |
| Total expected lines | 16957 |
| Matching lines | 15370 (90.6%) |
| Mismatched lines | 1587 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 2 | 100.0% |

## Passing Tests

**126 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.8s |  |
| 2 | `Accessibility-v6` | 19 | 1.9s |  |
| 3 | `Accessibility-v7` | 19 | 1.4s |  |
| 4 | `Accessibility-v8` | 19 | 20.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.6s |  |
| 6 | `BitmapData-v5` | 7 | 1.6s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 18.3s |  |
| 9 | `Boolean-v5` | 38 | 2.1s |  |
| 10 | `Boolean-v6` | 38 | 1.5s |  |
| 11 | `Boolean-v7` | 38 | 2.1s |  |
| 12 | `Boolean-v8` | 38 | 1.1s |  |
| 13 | `Camera-v5` | 7 | 1.5s |  |
| 14 | `Color-v5` | 140 | 4.9s |  |
| 15 | `Color-v6` | 171 | 5.9s |  |
| 16 | `Color-v7` | 161 | 5.6s |  |
| 17 | `Color-v8` | 161 | 1.1s |  |
| 18 | `ColorTransform-v5` | 7 | 18.3s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.2s |  |
| 21 | `ColorTransform-v8` | 55 | 2.8s |  |
| 22 | `ContextMenu-v5` | 7 | 1.5s |  |
| 23 | `ContextMenu-v6` | 7 | 0.5s |  |
| 24 | `ContextMenu-v7` | 131 | 4.3s |  |
| 25 | `ContextMenu-v8` | 131 | 20.6s |  |
| 26 | `Error-v5` | 28 | 2.0s |  |
| 27 | `Error-v6` | 31 | 2.0s |  |
| 28 | `Error-v7` | 31 | 1.6s |  |
| 29 | `Error-v8` | 31 | 1.0s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.6s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.3s |  |
| 32 | `ExternalInterface-v7` | 55 | 21.4s |  |
| 33 | `Global-v7` | 182 | 7.2s |  |
| 34 | `Global-v8` | 169 | 7.0s |  |
| 35 | `Instance-v5` | 52 | 2.4s |  |
| 36 | `Instance-v6` | 52 | 1.5s |  |
| 37 | `Instance-v7` | 52 | 19.6s |  |
| 38 | `Instance-v8` | 52 | 1.0s |  |
| 39 | `Key-v5` | 51 | 2.4s |  |
| 40 | `Key-v6` | 55 | 2.5s |  |
| 41 | `Key-v7` | 55 | 2.1s |  |
| 42 | `Key-v8` | 55 | 1.0s |  |
| 43 | `LoadVars-v5` | 8 | 18.9s |  |
| 44 | `LocalConnection-v5` | 7 | 20.0s |  |
| 45 | `LocalConnection-v6` | 58 | 3.0s |  |
| 46 | `LocalConnection-v7` | 58 | 2.6s |  |
| 47 | `LocalConnection-v8` | 58 | 1.1s |  |
| 48 | `Matrix-v5` | 7 | 1.6s |  |
| 49 | `Microphone-v5` | 6 | 1.6s |  |
| 50 | `Mouse-v5` | 13 | 18.6s |  |
| 51 | `Mouse-v6` | 21 | 1.7s |  |
| 52 | `Mouse-v7` | 21 | 1.3s |  |
| 53 | `Mouse-v8` | 21 | 0.9s |  |
| 54 | `MovieClipLoader-v5` | 6 | 1.4s |  |
| 55 | `MovieClipLoader-v6` | 6 | 18.8s |  |
| 56 | `NetConnection-v5` | 7 | 18.9s |  |
| 57 | `NetStream-v5` | 6 | 1.6s |  |
| 58 | `NetStream-v6` | 80 | 3.2s |  |
| 59 | `NetStream-v7` | 80 | 20.3s |  |
| 60 | `NetStream-v8` | 80 | 1.1s |  |
| 61 | `Number-v6` | 239 | 8.2s |  |
| 62 | `Number-v7` | 237 | 8.2s |  |
| 63 | `Number-v8` | 237 | 1.1s |  |
| 64 | `Point-v5` | 7 | 18.6s |  |
| 65 | `Point-v6` | 7 | 0.6s |  |
| 66 | `Point-v7` | 7 | 1.2s |  |
| 67 | `Point-v8` | 193 | 7.6s |  |
| 68 | `Random-v5` | 30 | 2.1s |  |
| 69 | `Random-v6` | 30 | 0.6s |  |
| 70 | `Random-v7` | 30 | 19.3s |  |
| 71 | `Random-v8` | 30 | 1.1s |  |
| 72 | `Rectangle-v5` | 7 | 1.6s |  |
| 73 | `Rectangle-v6` | 7 | 0.6s |  |
| 74 | `Rectangle-v7` | 7 | 1.2s |  |
| 75 | `Selection-v5` | 21 | 18.3s |  |
| 76 | `Stage-v5` | 38 | 21.0s |  |
| 77 | `System-v5` | 67 | 3.0s |  |
| 78 | `System-v6` | 100 | 3.9s |  |
| 79 | `System-v7` | 101 | 3.9s |  |
| 80 | `System-v8` | 101 | 1.1s |  |
| 81 | `TextFieldHTML-v5` | 6 | 18.5s |  |
| 82 | `TextFieldHTML-v6` | 37 | 2.2s |  |
| 83 | `TextFieldHTML-v7` | 37 | 1.8s |  |
| 84 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 85 | `TextFormat-v5` | 128 | 4.6s |  |
| 86 | `TextFormat-v6` | 128 | 0.6s |  |
| 87 | `TextSnapshot-v5` | 7 | 1.6s |  |
| 88 | `TextSnapshot-v6` | 173 | 7.0s |  |
| 89 | `TextSnapshot-v7` | 173 | 6.6s |  |
| 90 | `TextSnapshot-v8` | 173 | 1.1s |  |
| 91 | `Transform-v5` | 7 | 1.5s |  |
| 92 | `Transform-v6` | 7 | 20.4s |  |
| 93 | `Transform-v7` | 7 | 1.3s |  |
| 94 | `Try-v5` | 20 | 2.6s |  |
| 95 | `Try-v6` | 20 | 0.6s |  |
| 96 | `Try-v7` | 20 | 2.3s |  |
| 97 | `Try-v8` | 20 | 1.1s |  |
| 98 | `Video-v5` | 7 | 18.3s |  |
| 99 | `Video-v6` | 85 | 3.0s |  |
| 100 | `Video-v7` | 85 | 2.7s |  |
| 101 | `Video-v8` | 85 | 1.0s |  |
| 102 | `XMLSocket-v5` | 35 | 18.7s |  |
| 103 | `XMLSocket-v6` | 35 | 2.2s |  |
| 104 | `XMLSocket-v7` | 35 | 19.4s |  |
| 105 | `XMLSocket-v8` | 35 | 1.2s |  |
| 106 | `argstest-v5` | 4 | 1.8s |  |
| 107 | `case-v5` | 39 | 2.3s |  |
| 108 | `case-v6` | 73 | 3.2s |  |
| 109 | `case-v7` | 67 | 20.2s |  |
| 110 | `case-v8` | 67 | 1.1s |  |
| 111 | `delete-v5` | 60 | 2.7s |  |
| 112 | `delete-v6` | 60 | 2.1s |  |
| 113 | `delete-v7` | 60 | 2.3s |  |
| 114 | `delete-v8` | 60 | 1.2s |  |
| 115 | `enumerate-v5` | 6 | 18.6s |  |
| 116 | `enumerate-v6` | 49 | 2.6s |  |
| 117 | `enumerate-v7` | 49 | 2.3s |  |
| 118 | `enumerate-v8` | 49 | 1.1s |  |
| 119 | `flash-v5` | 10 | 1.6s |  |
| 120 | `flash-v6` | 10 | 1.6s |  |
| 121 | `flash-v7` | 10 | 14.7s |  |
| 122 | `swap-v5` | 7 | 1.3s |  |
| 123 | `swap-v6` | 7 | 0.5s |  |
| 124 | `swap-v7` | 7 | 0.9s |  |
| 125 | `swap-v8` | 7 | 0.8s |  |
| 126 | `targetPath-v5` | 12 | 19.2s |  |

## Ruffle-Matched Tests

**62 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 22.7s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.0s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.2s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 4.8s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.6s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.2s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 22.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 20.2s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.2s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.1s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 4.8s |  |
| 13 | `Global-v6` | 9 | 10 | 8.2s |  |
| 14 | `HitTest-v6` | 8 | 8 | 5.0s |  |
| 15 | `HitTest-v7` | 8 | 8 | 4.5s |  |
| 16 | `HitTest-v8` | 9 | 9 | 21.5s |  |
| 17 | `Inheritance-v5` | 1 | 17 | 4.3s |  |
| 18 | `Inheritance-v6` | 9 | 16 | 6.2s |  |
| 19 | `Inheritance-v7` | 5 | 10 | 6.4s |  |
| 20 | `Inheritance-v8` | 5 | 10 | 1.6s |  |
| 21 | `LoadVars-v6` | 6 | 8 | 23.2s |  |
| 22 | `LoadVars-v7` | 6 | 8 | 5.4s |  |
| 23 | `LoadVars-v8` | 6 | 8 | 1.9s |  |
| 24 | `Math-v5` | 5 | 5 | 29.4s |  |
| 25 | `Math-v6` | 5 | 5 | 0.6s |  |
| 26 | `Math-v7` | 5 | 5 | 13.1s |  |
| 27 | `Math-v8` | 5 | 5 | 1.2s |  |
| 28 | `Matrix-v6` | 29 | 71 | 6.7s |  |
| 29 | `Matrix-v7` | 28 | 70 | 24.6s |  |
| 30 | `Matrix-v8` | 28 | 70 | 1.2s |  |
| 31 | `Microphone-v6` | 31 | 31 | 3.2s |  |
| 32 | `Microphone-v7` | 31 | 31 | 2.8s |  |
| 33 | `Microphone-v8` | 31 | 31 | 1.1s |  |
| 34 | `MovieClip-v5` | 48 | 226 | 28.9s |  |
| 35 | `MovieClipLoader-v7` | 118 | 118 | 3.5s |  |
| 36 | `MovieClipLoader-v8` | 118 | 118 | 2.1s |  |
| 37 | `Number-v5` | 8 | 13 | 8.2s |  |
| 38 | `Rectangle-v8` | 21 | 21 | 6.6s |  |
| 39 | `Selection-v6` | 7 | 13 | 4.6s |  |
| 40 | `Selection-v7` | 7 | 13 | 4.3s |  |
| 41 | `Selection-v8` | 7 | 13 | 1.1s |  |
| 42 | `Sound-v5` | 27 | 27 | 20.7s |  |
| 43 | `Sound-v6` | 30 | 51 | 4.5s |  |
| 44 | `Sound-v7` | 28 | 51 | 22.6s |  |
| 45 | `Sound-v8` | 28 | 51 | 1.5s |  |
| 46 | `String-v5` | 19 | 21 | 16.1s |  |
| 47 | `String-v6` | 10 | 10 | 16.8s |  |
| 48 | `String-v7` | 10 | 10 | 16.3s |  |
| 49 | `String-v8` | 10 | 10 | 34.1s |  |
| 50 | `TextField-v5` | 3 | 3 | 1.7s |  |
| 51 | `ops-v8` | 7 | 11 | 7.7s |  |
| 52 | `targetPath-v6` | 17 | 17 | 1.9s |  |
| 53 | `targetPath-v7` | 17 | 17 | 1.5s |  |
| 54 | `targetPath-v8` | 17 | 17 | 1.1s |  |
| 55 | `toString_valueOf-v5` | 34 | 34 | 4.9s |  |
| 56 | `toString_valueOf-v6` | 5 | 5 | 5.4s |  |
| 57 | `toString_valueOf-v7` | 5 | 5 | 21.6s |  |
| 58 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 59 | `with-v5` | 42 | 42 | 3.0s |  |
| 60 | `with-v6` | 91 | 91 | 4.2s |  |
| 61 | `with-v7` | 91 | 91 | 3.9s |  |
| 62 | `with-v8` | 91 | 91 | 1.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 92.3% | 517 | 560 | 43 |  |
| 2 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**2 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 92.3% | 517/560 | 560 | 560 |  |
| 2 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
