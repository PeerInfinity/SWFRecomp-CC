# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-05 02:00 UTC

**Git SHA**: `e707c68962`

**Run Duration**: 21m 5s

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
| 1 | `Accessibility-v5` | 15 | 1.6s |  |
| 2 | `Accessibility-v6` | 19 | 1.7s |  |
| 3 | `Accessibility-v7` | 19 | 1.3s |  |
| 4 | `Accessibility-v8` | 19 | 18.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.6s |  |
| 6 | `BitmapData-v5` | 7 | 1.6s |  |
| 7 | `BitmapData-v6` | 7 | 0.5s |  |
| 8 | `BitmapData-v7` | 7 | 18.7s |  |
| 9 | `Boolean-v5` | 38 | 2.1s |  |
| 10 | `Boolean-v6` | 38 | 1.5s |  |
| 11 | `Boolean-v7` | 38 | 2.1s |  |
| 12 | `Boolean-v8` | 38 | 1.0s |  |
| 13 | `Camera-v5` | 7 | 1.6s |  |
| 14 | `Color-v5` | 140 | 4.9s |  |
| 15 | `Color-v6` | 171 | 5.9s |  |
| 16 | `Color-v7` | 161 | 5.8s |  |
| 17 | `Color-v8` | 161 | 1.1s |  |
| 18 | `ColorTransform-v5` | 7 | 18.8s |  |
| 19 | `ColorTransform-v6` | 7 | 0.6s |  |
| 20 | `ColorTransform-v7` | 7 | 1.2s |  |
| 21 | `ColorTransform-v8` | 55 | 2.9s |  |
| 22 | `ContextMenu-v5` | 7 | 1.6s |  |
| 23 | `ContextMenu-v6` | 7 | 0.6s |  |
| 24 | `ContextMenu-v7` | 131 | 4.5s |  |
| 25 | `ContextMenu-v8` | 131 | 20.6s |  |
| 26 | `Error-v5` | 28 | 1.8s |  |
| 27 | `Error-v6` | 31 | 1.9s |  |
| 28 | `Error-v7` | 31 | 1.5s |  |
| 29 | `Error-v8` | 31 | 0.9s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.4s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.2s |  |
| 32 | `ExternalInterface-v7` | 55 | 15.8s |  |
| 33 | `Global-v7` | 182 | 6.0s |  |
| 34 | `Global-v8` | 169 | 5.5s |  |
| 35 | `Instance-v5` | 52 | 2.2s |  |
| 36 | `Instance-v6` | 52 | 1.4s |  |
| 37 | `Instance-v7` | 52 | 19.2s |  |
| 38 | `Instance-v8` | 52 | 0.9s |  |
| 39 | `Key-v5` | 51 | 2.3s |  |
| 40 | `Key-v6` | 55 | 2.3s |  |
| 41 | `Key-v7` | 55 | 1.9s |  |
| 42 | `Key-v8` | 55 | 0.9s |  |
| 43 | `LoadVars-v5` | 8 | 17.9s |  |
| 44 | `LocalConnection-v5` | 7 | 19.1s |  |
| 45 | `LocalConnection-v6` | 58 | 2.7s |  |
| 46 | `LocalConnection-v7` | 58 | 2.4s |  |
| 47 | `LocalConnection-v8` | 58 | 1.1s |  |
| 48 | `Matrix-v5` | 7 | 1.2s |  |
| 49 | `Microphone-v5` | 6 | 1.6s |  |
| 50 | `Mouse-v5` | 13 | 20.0s |  |
| 51 | `Mouse-v6` | 21 | 1.9s |  |
| 52 | `Mouse-v7` | 21 | 1.5s |  |
| 53 | `Mouse-v8` | 21 | 1.1s |  |
| 54 | `MovieClipLoader-v5` | 6 | 1.6s |  |
| 55 | `MovieClipLoader-v6` | 6 | 18.7s |  |
| 56 | `NetConnection-v5` | 7 | 18.5s |  |
| 57 | `NetStream-v5` | 6 | 1.6s |  |
| 58 | `NetStream-v6` | 80 | 3.2s |  |
| 59 | `NetStream-v7` | 80 | 20.6s |  |
| 60 | `NetStream-v8` | 80 | 1.1s |  |
| 61 | `Number-v6` | 239 | 8.4s |  |
| 62 | `Number-v7` | 237 | 8.4s |  |
| 63 | `Number-v8` | 237 | 1.1s |  |
| 64 | `Point-v5` | 7 | 18.0s |  |
| 65 | `Point-v6` | 7 | 0.6s |  |
| 66 | `Point-v7` | 7 | 1.2s |  |
| 67 | `Point-v8` | 193 | 7.2s |  |
| 68 | `Random-v5` | 30 | 2.0s |  |
| 69 | `Random-v6` | 30 | 0.6s |  |
| 70 | `Random-v7` | 30 | 19.4s |  |
| 71 | `Random-v8` | 30 | 1.1s |  |
| 72 | `Rectangle-v5` | 7 | 1.6s |  |
| 73 | `Rectangle-v6` | 7 | 0.6s |  |
| 74 | `Rectangle-v7` | 7 | 1.2s |  |
| 75 | `Selection-v5` | 21 | 18.0s |  |
| 76 | `Stage-v5` | 38 | 19.3s |  |
| 77 | `System-v5` | 67 | 2.7s |  |
| 78 | `System-v6` | 100 | 3.7s |  |
| 79 | `System-v7` | 101 | 3.8s |  |
| 80 | `System-v8` | 101 | 1.0s |  |
| 81 | `TextFieldHTML-v5` | 6 | 18.8s |  |
| 82 | `TextFieldHTML-v6` | 37 | 2.2s |  |
| 83 | `TextFieldHTML-v7` | 37 | 1.9s |  |
| 84 | `TextFieldHTML-v8` | 37 | 1.1s |  |
| 85 | `TextFormat-v5` | 128 | 4.8s |  |
| 86 | `TextFormat-v6` | 128 | 0.6s |  |
| 87 | `TextSnapshot-v5` | 7 | 1.6s |  |
| 88 | `TextSnapshot-v6` | 173 | 7.1s |  |
| 89 | `TextSnapshot-v7` | 173 | 6.8s |  |
| 90 | `TextSnapshot-v8` | 173 | 1.1s |  |
| 91 | `Transform-v5` | 7 | 1.5s |  |
| 92 | `Transform-v6` | 7 | 19.3s |  |
| 93 | `Transform-v7` | 7 | 1.2s |  |
| 94 | `Try-v5` | 20 | 2.5s |  |
| 95 | `Try-v6` | 20 | 0.6s |  |
| 96 | `Try-v7` | 20 | 2.1s |  |
| 97 | `Try-v8` | 20 | 1.1s |  |
| 98 | `Video-v5` | 7 | 19.1s |  |
| 99 | `Video-v6` | 85 | 3.2s |  |
| 100 | `Video-v7` | 85 | 2.9s |  |
| 101 | `Video-v8` | 85 | 1.1s |  |
| 102 | `XMLSocket-v5` | 35 | 19.5s |  |
| 103 | `XMLSocket-v6` | 35 | 2.2s |  |
| 104 | `XMLSocket-v7` | 35 | 19.2s |  |
| 105 | `XMLSocket-v8` | 35 | 1.2s |  |
| 106 | `argstest-v5` | 4 | 1.8s |  |
| 107 | `case-v5` | 39 | 2.2s |  |
| 108 | `case-v6` | 73 | 3.2s |  |
| 109 | `case-v7` | 67 | 18.4s |  |
| 110 | `case-v8` | 67 | 1.1s |  |
| 111 | `delete-v5` | 60 | 2.4s |  |
| 112 | `delete-v6` | 60 | 1.9s |  |
| 113 | `delete-v7` | 60 | 2.1s |  |
| 114 | `delete-v8` | 60 | 1.1s |  |
| 115 | `enumerate-v5` | 6 | 18.4s |  |
| 116 | `enumerate-v6` | 49 | 2.6s |  |
| 117 | `enumerate-v7` | 49 | 2.2s |  |
| 118 | `enumerate-v8` | 49 | 1.1s |  |
| 119 | `flash-v5` | 10 | 1.6s |  |
| 120 | `flash-v6` | 10 | 1.6s |  |
| 121 | `flash-v7` | 10 | 18.9s |  |
| 122 | `swap-v5` | 7 | 1.6s |  |
| 123 | `swap-v6` | 7 | 0.6s |  |
| 124 | `swap-v7` | 7 | 1.2s |  |
| 125 | `swap-v8` | 7 | 1.0s |  |
| 126 | `targetPath-v5` | 12 | 19.7s |  |

## Ruffle-Matched Tests

**62 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 22.1s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.9s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.6s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.0s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 4.5s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 4.2s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.1s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 22.9s |  |
| 9 | `Camera-v6` | 57 | 57 | 20.0s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.2s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.0s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 3.9s |  |
| 13 | `Global-v6` | 9 | 10 | 6.9s |  |
| 14 | `HitTest-v6` | 8 | 8 | 3.9s |  |
| 15 | `HitTest-v7` | 8 | 8 | 3.5s |  |
| 16 | `HitTest-v8` | 9 | 9 | 20.5s |  |
| 17 | `Inheritance-v5` | 1 | 17 | 3.9s |  |
| 18 | `Inheritance-v6` | 9 | 16 | 5.8s |  |
| 19 | `Inheritance-v7` | 5 | 10 | 5.8s |  |
| 20 | `Inheritance-v8` | 5 | 10 | 1.4s |  |
| 21 | `LoadVars-v6` | 6 | 8 | 22.8s |  |
| 22 | `LoadVars-v7` | 6 | 8 | 5.0s |  |
| 23 | `LoadVars-v8` | 6 | 8 | 1.9s |  |
| 24 | `Math-v5` | 5 | 5 | 24.6s |  |
| 25 | `Math-v6` | 5 | 5 | 0.5s |  |
| 26 | `Math-v7` | 5 | 5 | 11.6s |  |
| 27 | `Math-v8` | 5 | 5 | 0.9s |  |
| 28 | `Matrix-v6` | 29 | 71 | 6.1s |  |
| 29 | `Matrix-v7` | 28 | 70 | 24.4s |  |
| 30 | `Matrix-v8` | 28 | 70 | 1.2s |  |
| 31 | `Microphone-v6` | 31 | 31 | 3.1s |  |
| 32 | `Microphone-v7` | 31 | 31 | 2.7s |  |
| 33 | `Microphone-v8` | 31 | 31 | 1.0s |  |
| 34 | `MovieClip-v5` | 48 | 226 | 33.5s |  |
| 35 | `MovieClipLoader-v7` | 118 | 118 | 3.5s |  |
| 36 | `MovieClipLoader-v8` | 118 | 118 | 2.1s |  |
| 37 | `Number-v5` | 8 | 13 | 8.7s |  |
| 38 | `Rectangle-v8` | 21 | 21 | 6.8s |  |
| 39 | `Selection-v6` | 7 | 13 | 4.6s |  |
| 40 | `Selection-v7` | 7 | 13 | 4.2s |  |
| 41 | `Selection-v8` | 7 | 13 | 1.1s |  |
| 42 | `Sound-v5` | 27 | 27 | 20.4s |  |
| 43 | `Sound-v6` | 30 | 51 | 4.5s |  |
| 44 | `Sound-v7` | 28 | 51 | 22.9s |  |
| 45 | `Sound-v8` | 28 | 51 | 1.4s |  |
| 46 | `String-v5` | 19 | 21 | 15.9s |  |
| 47 | `String-v6` | 10 | 10 | 16.8s |  |
| 48 | `String-v7` | 10 | 10 | 16.5s |  |
| 49 | `String-v8` | 10 | 10 | 32.6s |  |
| 50 | `TextField-v5` | 3 | 3 | 1.7s |  |
| 51 | `ops-v8` | 7 | 11 | 9.5s |  |
| 52 | `targetPath-v6` | 17 | 17 | 1.8s |  |
| 53 | `targetPath-v7` | 17 | 17 | 1.4s |  |
| 54 | `targetPath-v8` | 17 | 17 | 1.0s |  |
| 55 | `toString_valueOf-v5` | 34 | 34 | 5.2s |  |
| 56 | `toString_valueOf-v6` | 5 | 5 | 5.7s |  |
| 57 | `toString_valueOf-v7` | 5 | 5 | 22.4s |  |
| 58 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 59 | `with-v5` | 42 | 42 | 3.2s |  |
| 60 | `with-v6` | 91 | 91 | 4.3s |  |
| 61 | `with-v7` | 91 | 91 | 4.0s |  |
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
