# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-05 21:43 UTC

**Git SHA**: `2786394534`

**Run Duration**: 12m 2s

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
| 1 | `Accessibility-v5` | 15 | 0.3s |  |
| 2 | `Accessibility-v6` | 19 | 0.3s |  |
| 3 | `Accessibility-v7` | 19 | 0.3s |  |
| 4 | `Accessibility-v8` | 19 | 17.2s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.3s |  |
| 6 | `BitmapData-v5` | 7 | 0.3s |  |
| 7 | `BitmapData-v6` | 7 | 0.3s |  |
| 8 | `BitmapData-v7` | 7 | 17.9s |  |
| 9 | `Boolean-v5` | 38 | 0.4s |  |
| 10 | `Boolean-v6` | 38 | 0.4s |  |
| 11 | `Boolean-v7` | 38 | 0.4s |  |
| 12 | `Boolean-v8` | 38 | 0.4s |  |
| 13 | `Camera-v5` | 7 | 0.4s |  |
| 14 | `Color-v5` | 140 | 0.4s |  |
| 15 | `Color-v6` | 171 | 0.4s |  |
| 16 | `Color-v7` | 161 | 0.4s |  |
| 17 | `Color-v8` | 161 | 0.4s |  |
| 18 | `ColorTransform-v5` | 7 | 16.8s |  |
| 19 | `ColorTransform-v6` | 7 | 0.3s |  |
| 20 | `ColorTransform-v7` | 7 | 0.3s |  |
| 21 | `ColorTransform-v8` | 55 | 0.3s |  |
| 22 | `ContextMenu-v5` | 7 | 0.3s |  |
| 23 | `ContextMenu-v6` | 7 | 0.3s |  |
| 24 | `ContextMenu-v7` | 131 | 0.3s |  |
| 25 | `ContextMenu-v8` | 131 | 17.0s |  |
| 26 | `Error-v5` | 28 | 0.3s |  |
| 27 | `Error-v6` | 31 | 0.3s |  |
| 28 | `Error-v7` | 31 | 0.3s |  |
| 29 | `Error-v8` | 31 | 0.3s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.4s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.3s |  |
| 32 | `ExternalInterface-v7` | 55 | 17.7s |  |
| 33 | `Global-v7` | 182 | 0.4s |  |
| 34 | `Global-v8` | 169 | 0.4s |  |
| 35 | `Instance-v5` | 52 | 0.3s |  |
| 36 | `Instance-v6` | 52 | 0.3s |  |
| 37 | `Instance-v7` | 52 | 18.4s |  |
| 38 | `Instance-v8` | 52 | 0.4s |  |
| 39 | `Key-v5` | 51 | 0.4s |  |
| 40 | `Key-v6` | 55 | 0.4s |  |
| 41 | `Key-v7` | 55 | 0.4s |  |
| 42 | `Key-v8` | 55 | 0.4s |  |
| 43 | `LoadVars-v5` | 8 | 18.5s |  |
| 44 | `LocalConnection-v5` | 7 | 17.4s |  |
| 45 | `LocalConnection-v6` | 58 | 0.4s |  |
| 46 | `LocalConnection-v7` | 58 | 0.4s |  |
| 47 | `LocalConnection-v8` | 58 | 0.4s |  |
| 48 | `Matrix-v5` | 7 | 0.3s |  |
| 49 | `Microphone-v5` | 6 | 0.3s |  |
| 50 | `Mouse-v5` | 13 | 19.1s |  |
| 51 | `Mouse-v6` | 21 | 0.4s |  |
| 52 | `Mouse-v7` | 21 | 0.4s |  |
| 53 | `Mouse-v8` | 21 | 0.4s |  |
| 54 | `MovieClipLoader-v5` | 6 | 0.4s |  |
| 55 | `MovieClipLoader-v6` | 6 | 19.3s |  |
| 56 | `NetConnection-v5` | 7 | 18.7s |  |
| 57 | `NetStream-v5` | 6 | 0.4s |  |
| 58 | `NetStream-v6` | 80 | 0.4s |  |
| 59 | `NetStream-v7` | 80 | 16.7s |  |
| 60 | `NetStream-v8` | 80 | 0.3s |  |
| 61 | `Number-v6` | 239 | 0.4s |  |
| 62 | `Number-v7` | 237 | 0.4s |  |
| 63 | `Number-v8` | 237 | 0.4s |  |
| 64 | `Point-v5` | 7 | 17.2s |  |
| 65 | `Point-v6` | 7 | 0.3s |  |
| 66 | `Point-v7` | 7 | 0.3s |  |
| 67 | `Point-v8` | 193 | 0.3s |  |
| 68 | `Random-v5` | 30 | 0.3s |  |
| 69 | `Random-v6` | 30 | 0.3s |  |
| 70 | `Random-v7` | 30 | 17.6s |  |
| 71 | `Random-v8` | 30 | 0.4s |  |
| 72 | `Rectangle-v5` | 7 | 0.3s |  |
| 73 | `Rectangle-v6` | 7 | 0.3s |  |
| 74 | `Rectangle-v7` | 7 | 0.3s |  |
| 75 | `Selection-v5` | 21 | 13.6s |  |
| 76 | `Stage-v5` | 38 | 18.2s |  |
| 77 | `System-v5` | 67 | 0.4s |  |
| 78 | `System-v6` | 100 | 0.4s |  |
| 79 | `System-v7` | 101 | 0.4s |  |
| 80 | `System-v8` | 101 | 0.4s |  |
| 81 | `TextFieldHTML-v5` | 6 | 18.3s |  |
| 82 | `TextFieldHTML-v6` | 37 | 0.3s |  |
| 83 | `TextFieldHTML-v7` | 37 | 0.3s |  |
| 84 | `TextFieldHTML-v8` | 37 | 0.3s |  |
| 85 | `TextFormat-v5` | 128 | 0.3s |  |
| 86 | `TextFormat-v6` | 128 | 0.3s |  |
| 87 | `TextSnapshot-v5` | 7 | 0.4s |  |
| 88 | `TextSnapshot-v6` | 173 | 0.4s |  |
| 89 | `TextSnapshot-v7` | 173 | 0.4s |  |
| 90 | `TextSnapshot-v8` | 173 | 0.4s |  |
| 91 | `Transform-v5` | 7 | 0.4s |  |
| 92 | `Transform-v6` | 7 | 17.3s |  |
| 93 | `Transform-v7` | 7 | 0.3s |  |
| 94 | `Try-v5` | 20 | 0.3s |  |
| 95 | `Try-v6` | 20 | 0.3s |  |
| 96 | `Try-v7` | 20 | 0.3s |  |
| 97 | `Try-v8` | 20 | 0.3s |  |
| 98 | `Video-v5` | 7 | 20.6s |  |
| 99 | `Video-v6` | 85 | 0.4s |  |
| 100 | `Video-v7` | 85 | 0.4s |  |
| 101 | `Video-v8` | 85 | 0.4s |  |
| 102 | `XMLSocket-v5` | 35 | 20.4s |  |
| 103 | `XMLSocket-v6` | 35 | 0.4s |  |
| 104 | `XMLSocket-v7` | 35 | 17.1s |  |
| 105 | `XMLSocket-v8` | 35 | 0.3s |  |
| 106 | `argstest-v5` | 4 | 0.3s |  |
| 107 | `case-v5` | 39 | 0.3s |  |
| 108 | `case-v6` | 73 | 0.3s |  |
| 109 | `case-v7` | 67 | 17.4s |  |
| 110 | `case-v8` | 67 | 0.3s |  |
| 111 | `delete-v5` | 60 | 0.3s |  |
| 112 | `delete-v6` | 60 | 0.3s |  |
| 113 | `delete-v7` | 60 | 0.3s |  |
| 114 | `delete-v8` | 60 | 0.3s |  |
| 115 | `enumerate-v5` | 6 | 17.2s |  |
| 116 | `enumerate-v6` | 49 | 0.3s |  |
| 117 | `enumerate-v7` | 49 | 0.3s |  |
| 118 | `enumerate-v8` | 49 | 0.3s |  |
| 119 | `flash-v5` | 10 | 0.3s |  |
| 120 | `flash-v6` | 10 | 0.3s |  |
| 121 | `flash-v7` | 10 | 18.4s |  |
| 122 | `swap-v5` | 7 | 0.4s |  |
| 123 | `swap-v6` | 7 | 0.3s |  |
| 124 | `swap-v7` | 7 | 0.4s |  |
| 125 | `swap-v8` | 7 | 0.4s |  |
| 126 | `targetPath-v5` | 12 | 18.1s |  |

## Ruffle-Matched Tests

**62 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 17.0s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.3s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.3s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 0.4s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.4s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.4s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.5s |  |
| 9 | `Camera-v6` | 57 | 57 | 17.8s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.4s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.4s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 0.4s |  |
| 13 | `Global-v6` | 9 | 10 | 0.4s |  |
| 14 | `HitTest-v6` | 8 | 8 | 0.4s |  |
| 15 | `HitTest-v7` | 8 | 8 | 0.4s |  |
| 16 | `HitTest-v8` | 9 | 9 | 18.5s |  |
| 17 | `Inheritance-v5` | 1 | 17 | 0.4s |  |
| 18 | `Inheritance-v6` | 9 | 16 | 0.4s |  |
| 19 | `Inheritance-v7` | 5 | 10 | 0.4s |  |
| 20 | `Inheritance-v8` | 5 | 10 | 0.4s |  |
| 21 | `LoadVars-v6` | 6 | 8 | 17.6s |  |
| 22 | `LoadVars-v7` | 6 | 8 | 0.4s |  |
| 23 | `LoadVars-v8` | 6 | 8 | 0.4s |  |
| 24 | `Math-v5` | 5 | 5 | 17.1s |  |
| 25 | `Math-v6` | 5 | 5 | 0.3s |  |
| 26 | `Math-v7` | 5 | 5 | 0.4s |  |
| 27 | `Math-v8` | 5 | 5 | 0.4s |  |
| 28 | `Matrix-v6` | 29 | 71 | 0.4s |  |
| 29 | `Matrix-v7` | 28 | 70 | 18.1s |  |
| 30 | `Matrix-v8` | 28 | 70 | 0.4s |  |
| 31 | `Microphone-v6` | 31 | 31 | 0.3s |  |
| 32 | `Microphone-v7` | 31 | 31 | 0.3s |  |
| 33 | `Microphone-v8` | 31 | 31 | 0.3s |  |
| 34 | `MovieClip-v5` | 48 | 226 | 19.2s |  |
| 35 | `MovieClipLoader-v7` | 118 | 118 | 0.4s |  |
| 36 | `MovieClipLoader-v8` | 118 | 118 | 0.4s |  |
| 37 | `Number-v5` | 8 | 13 | 0.4s |  |
| 38 | `Rectangle-v8` | 21 | 21 | 0.4s |  |
| 39 | `Selection-v6` | 7 | 13 | 0.3s |  |
| 40 | `Selection-v7` | 7 | 13 | 0.3s |  |
| 41 | `Selection-v8` | 7 | 13 | 0.3s |  |
| 42 | `Sound-v5` | 27 | 27 | 14.1s |  |
| 43 | `Sound-v6` | 30 | 51 | 0.4s |  |
| 44 | `Sound-v7` | 28 | 51 | 18.6s |  |
| 45 | `Sound-v8` | 28 | 51 | 0.5s |  |
| 46 | `String-v5` | 19 | 21 | 0.4s |  |
| 47 | `String-v6` | 10 | 10 | 0.4s |  |
| 48 | `String-v7` | 10 | 10 | 0.4s |  |
| 49 | `String-v8` | 10 | 10 | 17.2s |  |
| 50 | `TextField-v5` | 3 | 3 | 0.4s |  |
| 51 | `ops-v8` | 7 | 11 | 0.4s |  |
| 52 | `targetPath-v6` | 17 | 17 | 0.4s |  |
| 53 | `targetPath-v7` | 17 | 17 | 0.4s |  |
| 54 | `targetPath-v8` | 17 | 17 | 0.4s |  |
| 55 | `toString_valueOf-v5` | 34 | 34 | 0.4s |  |
| 56 | `toString_valueOf-v6` | 5 | 5 | 0.4s |  |
| 57 | `toString_valueOf-v7` | 5 | 5 | 17.3s |  |
| 58 | `toString_valueOf-v8` | 5 | 5 | 0.3s |  |
| 59 | `with-v5` | 42 | 42 | 0.3s |  |
| 60 | `with-v6` | 91 | 91 | 0.3s |  |
| 61 | `with-v7` | 91 | 91 | 0.3s |  |
| 62 | `with-v8` | 91 | 91 | 0.3s |  |

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
