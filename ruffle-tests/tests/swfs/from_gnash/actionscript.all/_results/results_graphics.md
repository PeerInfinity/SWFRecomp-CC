# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-13 20:24 UTC

**Git SHA**: `fe491ef7b5`

**Run Duration**: 25m 13s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **125** (65.8%) |
| Ruffle-matched | 61 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **186** (97.9%) |
| Failing | 4 |
| Total expected lines | 16957 |
| Matching lines | 15393 (90.8%) |
| Mismatched lines | 1564 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Runtime Error | 3 | 75.0% |
| Output Mismatch | 1 | 25.0% |

## Passing Tests

**125 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.5s |  |
| 2 | `Accessibility-v6` | 19 | 2.4s |  |
| 3 | `Accessibility-v7` | 19 | 2.7s |  |
| 4 | `Accessibility-v8` | 19 | 20.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.7s |  |
| 6 | `BitmapData-v5` | 7 | 2.6s |  |
| 7 | `BitmapData-v6` | 7 | 1.1s |  |
| 8 | `BitmapData-v7` | 7 | 23.4s |  |
| 9 | `Boolean-v5` | 38 | 3.5s |  |
| 10 | `Boolean-v6` | 38 | 2.9s |  |
| 11 | `Boolean-v7` | 38 | 3.8s |  |
| 12 | `Boolean-v8` | 38 | 2.5s |  |
| 13 | `Camera-v5` | 7 | 3.1s |  |
| 14 | `Color-v5` | 140 | 6.7s |  |
| 15 | `Color-v6` | 171 | 7.7s |  |
| 16 | `Color-v7` | 161 | 7.5s |  |
| 17 | `Color-v8` | 161 | 2.4s |  |
| 18 | `ColorTransform-v5` | 7 | 19.8s |  |
| 19 | `ColorTransform-v6` | 7 | 1.2s |  |
| 20 | `ColorTransform-v7` | 7 | 2.3s |  |
| 21 | `ColorTransform-v8` | 55 | 3.9s |  |
| 22 | `ContextMenu-v5` | 7 | 2.6s |  |
| 23 | `ContextMenu-v6` | 7 | 1.1s |  |
| 24 | `ContextMenu-v7` | 131 | 5.3s |  |
| 25 | `ContextMenu-v8` | 131 | 24.0s |  |
| 26 | `Error-v5` | 28 | 3.2s |  |
| 27 | `Error-v6` | 31 | 3.4s |  |
| 28 | `Error-v7` | 31 | 2.9s |  |
| 29 | `Error-v8` | 31 | 2.2s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.8s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.7s |  |
| 32 | `ExternalInterface-v7` | 55 | 22.1s |  |
| 33 | `Global-v7` | 182 | 8.2s |  |
| 34 | `Global-v8` | 169 | 7.8s |  |
| 35 | `Instance-v5` | 52 | 3.6s |  |
| 36 | `Instance-v6` | 52 | 2.2s |  |
| 37 | `Instance-v7` | 52 | 21.6s |  |
| 38 | `Instance-v8` | 52 | 2.2s |  |
| 39 | `Key-v5` | 51 | 3.6s |  |
| 40 | `Key-v6` | 55 | 3.7s |  |
| 41 | `Key-v7` | 55 | 3.4s |  |
| 42 | `Key-v8` | 55 | 2.3s |  |
| 43 | `LoadVars-v5` | 8 | 20.8s |  |
| 44 | `LocalConnection-v5` | 7 | 20.2s |  |
| 45 | `LocalConnection-v6` | 58 | 3.8s |  |
| 46 | `LocalConnection-v7` | 58 | 3.4s |  |
| 47 | `LocalConnection-v8` | 58 | 2.1s |  |
| 48 | `Matrix-v5` | 7 | 2.7s |  |
| 49 | `Microphone-v5` | 6 | 2.7s |  |
| 50 | `Mouse-v5` | 13 | 19.0s |  |
| 51 | `Mouse-v6` | 21 | 2.8s |  |
| 52 | `Mouse-v7` | 21 | 2.4s |  |
| 53 | `Mouse-v8` | 21 | 1.9s |  |
| 54 | `MovieClipLoader-v5` | 6 | 2.9s |  |
| 55 | `MovieClipLoader-v6` | 6 | 21.2s |  |
| 56 | `NetConnection-v5` | 7 | 20.8s |  |
| 57 | `NetStream-v5` | 6 | 2.8s |  |
| 58 | `NetStream-v6` | 80 | 4.6s |  |
| 59 | `NetStream-v7` | 80 | 22.3s |  |
| 60 | `NetStream-v8` | 80 | 2.3s |  |
| 61 | `Number-v6` | 239 | 10.4s |  |
| 62 | `Number-v7` | 237 | 10.2s |  |
| 63 | `Number-v8` | 237 | 2.3s |  |
| 64 | `Point-v5` | 7 | 19.8s |  |
| 65 | `Point-v6` | 7 | 1.2s |  |
| 66 | `Point-v7` | 7 | 2.2s |  |
| 67 | `Point-v8` | 193 | 8.4s |  |
| 68 | `Random-v5` | 30 | 3.0s |  |
| 69 | `Random-v6` | 30 | 1.2s |  |
| 70 | `Random-v7` | 30 | 21.8s |  |
| 71 | `Random-v8` | 30 | 2.3s |  |
| 72 | `Rectangle-v5` | 7 | 3.0s |  |
| 73 | `Rectangle-v6` | 7 | 1.3s |  |
| 74 | `Rectangle-v7` | 7 | 2.5s |  |
| 75 | `Selection-v5` | 21 | 20.2s |  |
| 76 | `Stage-v5` | 38 | 21.5s |  |
| 77 | `System-v5` | 67 | 3.1s |  |
| 78 | `System-v6` | 100 | 3.8s |  |
| 79 | `System-v7` | 101 | 3.9s |  |
| 80 | `System-v8` | 101 | 1.7s |  |
| 81 | `TextFieldHTML-v5` | 6 | 19.9s |  |
| 82 | `TextFieldHTML-v6` | 37 | 3.2s |  |
| 83 | `TextFieldHTML-v7` | 37 | 2.9s |  |
| 84 | `TextFieldHTML-v8` | 37 | 2.1s |  |
| 85 | `TextFormat-v5` | 128 | 5.6s |  |
| 86 | `TextFormat-v6` | 128 | 1.2s |  |
| 87 | `TextSnapshot-v5` | 7 | 2.6s |  |
| 88 | `TextSnapshot-v6` | 173 | 8.2s |  |
| 89 | `TextSnapshot-v7` | 173 | 7.8s |  |
| 90 | `TextSnapshot-v8` | 173 | 2.2s |  |
| 91 | `Transform-v5` | 7 | 2.6s |  |
| 92 | `Transform-v6` | 7 | 20.5s |  |
| 93 | `Transform-v7` | 7 | 2.3s |  |
| 94 | `Try-v5` | 20 | 3.8s |  |
| 95 | `Try-v6` | 20 | 1.2s |  |
| 96 | `Try-v7` | 20 | 3.3s |  |
| 97 | `Try-v8` | 20 | 2.1s |  |
| 98 | `Video-v5` | 7 | 21.3s |  |
| 99 | `Video-v6` | 85 | 4.3s |  |
| 100 | `Video-v7` | 85 | 3.9s |  |
| 101 | `Video-v8` | 85 | 2.2s |  |
| 102 | `XMLSocket-v5` | 35 | 21.2s |  |
| 103 | `XMLSocket-v6` | 35 | 3.4s |  |
| 104 | `XMLSocket-v7` | 35 | 20.3s |  |
| 105 | `XMLSocket-v8` | 35 | 2.2s |  |
| 106 | `argstest-v5` | 4 | 2.8s |  |
| 107 | `case-v5` | 39 | 3.2s |  |
| 108 | `case-v7` | 67 | 21.2s |  |
| 109 | `case-v8` | 67 | 1.9s |  |
| 110 | `delete-v5` | 60 | 3.4s |  |
| 111 | `delete-v6` | 60 | 2.9s |  |
| 112 | `delete-v7` | 60 | 3.0s |  |
| 113 | `delete-v8` | 60 | 2.0s |  |
| 114 | `enumerate-v5` | 6 | 19.8s |  |
| 115 | `enumerate-v6` | 49 | 3.6s |  |
| 116 | `enumerate-v7` | 49 | 3.2s |  |
| 117 | `enumerate-v8` | 49 | 2.1s |  |
| 118 | `flash-v5` | 10 | 2.6s |  |
| 119 | `flash-v6` | 10 | 2.6s |  |
| 120 | `flash-v7` | 10 | 20.8s |  |
| 121 | `swap-v5` | 7 | 2.9s |  |
| 122 | `swap-v6` | 7 | 1.3s |  |
| 123 | `swap-v7` | 7 | 2.5s |  |
| 124 | `swap-v8` | 7 | 2.3s |  |
| 125 | `targetPath-v5` | 12 | 20.0s |  |

## Ruffle-Matched Tests

**61 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 19.2s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.0s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.9s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.6s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.2s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 2.2s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 25.6s |  |
| 9 | `Camera-v6` | 57 | 57 | 23.2s |  |
| 10 | `Camera-v7` | 57 | 57 | 4.8s |  |
| 11 | `Camera-v8` | 57 | 57 | 2.3s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 5.8s |  |
| 13 | `Global-v6` | 9 | 10 | 9.0s |  |
| 14 | `HitTest-v6` | 8 | 8 | 5.8s |  |
| 15 | `HitTest-v7` | 8 | 8 | 5.4s |  |
| 16 | `HitTest-v8` | 9 | 9 | 23.3s |  |
| 17 | `Inheritance-v7` | 5 | 10 | 7.9s |  |
| 18 | `Inheritance-v8` | 5 | 10 | 2.7s |  |
| 19 | `LoadVars-v6` | 6 | 8 | 23.8s |  |
| 20 | `LoadVars-v7` | 6 | 8 | 5.8s |  |
| 21 | `LoadVars-v8` | 6 | 8 | 3.0s |  |
| 22 | `Math-v5` | 5 | 5 | 32.0s |  |
| 23 | `Math-v6` | 5 | 5 | 1.3s |  |
| 24 | `Math-v7` | 5 | 5 | 14.6s |  |
| 25 | `Math-v8` | 5 | 5 | 2.3s |  |
| 26 | `Matrix-v6` | 29 | 71 | 8.0s |  |
| 27 | `Matrix-v7` | 28 | 70 | 26.5s |  |
| 28 | `Matrix-v8` | 28 | 70 | 2.3s |  |
| 29 | `Microphone-v6` | 31 | 31 | 4.3s |  |
| 30 | `Microphone-v7` | 31 | 31 | 3.9s |  |
| 31 | `Microphone-v8` | 31 | 31 | 2.2s |  |
| 32 | `MovieClip-v5` | 48 | 226 | 29.9s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 4.8s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 3.4s |  |
| 35 | `Number-v5` | 8 | 13 | 10.8s |  |
| 36 | `Rectangle-v8` | 21 | 21 | 8.0s |  |
| 37 | `Selection-v6` | 7 | 13 | 5.6s |  |
| 38 | `Selection-v7` | 7 | 13 | 5.3s |  |
| 39 | `Selection-v8` | 7 | 13 | 1.9s |  |
| 40 | `Sound-v5` | 27 | 27 | 23.7s |  |
| 41 | `Sound-v6` | 30 | 51 | 5.7s |  |
| 42 | `Sound-v7` | 28 | 51 | 25.9s |  |
| 43 | `Sound-v8` | 28 | 51 | 2.8s |  |
| 44 | `String-v5` | 19 | 21 | 17.6s |  |
| 45 | `String-v6` | 10 | 10 | 18.4s |  |
| 46 | `String-v7` | 10 | 10 | 17.8s |  |
| 47 | `String-v8` | 10 | 10 | 28.1s |  |
| 48 | `TextField-v5` | 3 | 3 | 2.2s |  |
| 49 | `TextFormat-v7` | 38 | 40 | 24.3s |  |
| 50 | `ops-v8` | 7 | 11 | 10.8s |  |
| 51 | `targetPath-v6` | 17 | 17 | 2.9s |  |
| 52 | `targetPath-v7` | 17 | 17 | 2.5s |  |
| 53 | `targetPath-v8` | 17 | 17 | 2.1s |  |
| 54 | `toString_valueOf-v5` | 34 | 34 | 5.6s |  |
| 55 | `toString_valueOf-v6` | 5 | 5 | 6.0s |  |
| 56 | `toString_valueOf-v7` | 5 | 5 | 23.9s |  |
| 57 | `toString_valueOf-v8` | 5 | 5 | 2.3s |  |
| 58 | `with-v5` | 42 | 42 | 4.2s |  |
| 59 | `with-v6` | 91 | 91 | 5.5s |  |
| 60 | `with-v7` | 91 | 91 | 5.1s |  |
| 61 | `with-v8` | 91 | 91 | 2.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |

## Segfaults

No segfaults.

## Runtime Errors

**3 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `Inheritance-v5` | exit code -6 | 6.1s |  |
| 2 | `Inheritance-v6` | exit code -6 | 8.8s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 4.8s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
