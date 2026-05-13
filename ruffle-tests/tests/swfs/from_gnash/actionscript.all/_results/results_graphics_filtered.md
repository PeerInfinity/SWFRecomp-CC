# Ruffle Test Results (Filtered)

**Date**: 2026-05-13 00:24 UTC

**Git SHA**: `7bef032ea2`

**Run Duration**: 23m 40s

**Filtered**: 0 tests ignored out of 190 available

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
| 1 | `Accessibility-v5` | 15 | 2.3s |  |
| 2 | `Accessibility-v6` | 19 | 2.3s |  |
| 3 | `Accessibility-v7` | 19 | 1.9s |  |
| 4 | `Accessibility-v8` | 19 | 19.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.3s |  |
| 6 | `BitmapData-v5` | 7 | 2.2s |  |
| 7 | `BitmapData-v6` | 7 | 1.1s |  |
| 8 | `BitmapData-v7` | 7 | 19.2s |  |
| 9 | `Boolean-v5` | 38 | 2.6s |  |
| 10 | `Boolean-v6` | 38 | 2.1s |  |
| 11 | `Boolean-v7` | 38 | 2.7s |  |
| 12 | `Boolean-v8` | 38 | 1.6s |  |
| 13 | `Camera-v5` | 7 | 2.1s |  |
| 14 | `Color-v5` | 140 | 5.3s |  |
| 15 | `Color-v6` | 171 | 6.3s |  |
| 16 | `Color-v7` | 161 | 6.0s |  |
| 17 | `Color-v8` | 161 | 1.6s |  |
| 18 | `ColorTransform-v5` | 7 | 20.8s |  |
| 19 | `ColorTransform-v6` | 7 | 1.1s |  |
| 20 | `ColorTransform-v7` | 7 | 1.9s |  |
| 21 | `ColorTransform-v8` | 55 | 3.6s |  |
| 22 | `ContextMenu-v5` | 7 | 2.2s |  |
| 23 | `ContextMenu-v6` | 7 | 1.1s |  |
| 24 | `ContextMenu-v7` | 131 | 5.3s |  |
| 25 | `ContextMenu-v8` | 131 | 21.5s |  |
| 26 | `Error-v5` | 28 | 2.5s |  |
| 27 | `Error-v6` | 31 | 2.6s |  |
| 28 | `Error-v7` | 31 | 2.2s |  |
| 29 | `Error-v8` | 31 | 1.5s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 2.9s |  |
| 32 | `ExternalInterface-v7` | 55 | 20.4s |  |
| 33 | `Global-v7` | 182 | 7.1s |  |
| 34 | `Global-v8` | 169 | 6.6s |  |
| 35 | `Instance-v5` | 52 | 3.0s |  |
| 36 | `Instance-v6` | 52 | 2.0s |  |
| 37 | `Instance-v7` | 52 | 21.7s |  |
| 38 | `Instance-v8` | 52 | 1.8s |  |
| 39 | `Key-v5` | 51 | 3.3s |  |
| 40 | `Key-v6` | 55 | 3.3s |  |
| 41 | `Key-v7` | 55 | 3.0s |  |
| 42 | `Key-v8` | 55 | 1.8s |  |
| 43 | `LoadVars-v5` | 8 | 21.8s |  |
| 44 | `LocalConnection-v5` | 7 | 20.5s |  |
| 45 | `LocalConnection-v6` | 58 | 3.5s |  |
| 46 | `LocalConnection-v7` | 58 | 3.1s |  |
| 47 | `LocalConnection-v8` | 58 | 1.7s |  |
| 48 | `Matrix-v5` | 7 | 2.3s |  |
| 49 | `Microphone-v5` | 6 | 2.2s |  |
| 50 | `Mouse-v5` | 13 | 19.5s |  |
| 51 | `Mouse-v6` | 21 | 2.4s |  |
| 52 | `Mouse-v7` | 21 | 2.0s |  |
| 53 | `Mouse-v8` | 21 | 1.6s |  |
| 54 | `MovieClipLoader-v5` | 6 | 2.1s |  |
| 55 | `MovieClipLoader-v6` | 6 | 19.6s |  |
| 56 | `NetConnection-v5` | 7 | 19.3s |  |
| 57 | `NetStream-v5` | 6 | 2.1s |  |
| 58 | `NetStream-v6` | 80 | 3.8s |  |
| 59 | `NetStream-v7` | 80 | 21.4s |  |
| 60 | `NetStream-v8` | 80 | 1.6s |  |
| 61 | `Number-v6` | 239 | 9.2s |  |
| 62 | `Number-v7` | 237 | 9.0s |  |
| 63 | `Number-v8` | 237 | 1.7s |  |
| 64 | `Point-v5` | 7 | 20.7s |  |
| 65 | `Point-v6` | 7 | 1.1s |  |
| 66 | `Point-v7` | 7 | 1.9s |  |
| 67 | `Point-v8` | 193 | 8.7s |  |
| 68 | `Random-v5` | 30 | 2.8s |  |
| 69 | `Random-v6` | 30 | 1.1s |  |
| 70 | `Random-v7` | 30 | 21.0s |  |
| 71 | `Random-v8` | 30 | 1.7s |  |
| 72 | `Rectangle-v5` | 7 | 2.5s |  |
| 73 | `Rectangle-v6` | 7 | 1.1s |  |
| 74 | `Rectangle-v7` | 7 | 1.9s |  |
| 75 | `Selection-v5` | 21 | 20.5s |  |
| 76 | `Stage-v5` | 38 | 20.1s |  |
| 77 | `System-v5` | 67 | 2.9s |  |
| 78 | `System-v6` | 100 | 3.6s |  |
| 79 | `System-v7` | 101 | 3.7s |  |
| 80 | `System-v8` | 101 | 1.6s |  |
| 81 | `TextFieldHTML-v5` | 6 | 20.2s |  |
| 82 | `TextFieldHTML-v6` | 37 | 2.9s |  |
| 83 | `TextFieldHTML-v7` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v8` | 37 | 1.7s |  |
| 85 | `TextFormat-v5` | 128 | 5.4s |  |
| 86 | `TextFormat-v6` | 128 | 1.1s |  |
| 87 | `TextSnapshot-v5` | 7 | 2.2s |  |
| 88 | `TextSnapshot-v6` | 173 | 7.8s |  |
| 89 | `TextSnapshot-v7` | 173 | 7.4s |  |
| 90 | `TextSnapshot-v8` | 173 | 1.7s |  |
| 91 | `Transform-v5` | 7 | 2.2s |  |
| 92 | `Transform-v6` | 7 | 19.2s |  |
| 93 | `Transform-v7` | 7 | 1.8s |  |
| 94 | `Try-v5` | 20 | 3.1s |  |
| 95 | `Try-v6` | 20 | 1.0s |  |
| 96 | `Try-v7` | 20 | 2.8s |  |
| 97 | `Try-v8` | 20 | 1.6s |  |
| 98 | `Video-v5` | 7 | 20.2s |  |
| 99 | `Video-v6` | 85 | 3.9s |  |
| 100 | `Video-v7` | 85 | 3.5s |  |
| 101 | `Video-v8` | 85 | 1.7s |  |
| 102 | `XMLSocket-v5` | 35 | 20.6s |  |
| 103 | `XMLSocket-v6` | 35 | 2.9s |  |
| 104 | `XMLSocket-v7` | 35 | 20.9s |  |
| 105 | `XMLSocket-v8` | 35 | 1.8s |  |
| 106 | `argstest-v5` | 4 | 2.4s |  |
| 107 | `case-v5` | 39 | 3.0s |  |
| 108 | `case-v7` | 67 | 21.2s |  |
| 109 | `case-v8` | 67 | 1.8s |  |
| 110 | `delete-v5` | 60 | 3.3s |  |
| 111 | `delete-v6` | 60 | 2.8s |  |
| 112 | `delete-v7` | 60 | 2.9s |  |
| 113 | `delete-v8` | 60 | 1.9s |  |
| 114 | `enumerate-v5` | 6 | 19.8s |  |
| 115 | `enumerate-v6` | 49 | 3.3s |  |
| 116 | `enumerate-v7` | 49 | 3.0s |  |
| 117 | `enumerate-v8` | 49 | 1.7s |  |
| 118 | `flash-v5` | 10 | 2.3s |  |
| 119 | `flash-v6` | 10 | 2.3s |  |
| 120 | `flash-v7` | 10 | 19.7s |  |
| 121 | `swap-v5` | 7 | 2.2s |  |
| 122 | `swap-v6` | 7 | 1.1s |  |
| 123 | `swap-v7` | 7 | 1.8s |  |
| 124 | `swap-v8` | 7 | 1.6s |  |
| 125 | `targetPath-v5` | 12 | 19.8s |  |

## Ruffle-Matched Tests

**61 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 22.8s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.7s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.4s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.0s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.8s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 22.7s |  |
| 9 | `Camera-v6` | 57 | 57 | 20.6s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.6s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.6s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 4.9s |  |
| 13 | `Global-v6` | 9 | 10 | 8.1s |  |
| 14 | `HitTest-v6` | 8 | 8 | 4.9s |  |
| 15 | `HitTest-v7` | 8 | 8 | 4.6s |  |
| 16 | `HitTest-v8` | 9 | 9 | 22.5s |  |
| 17 | `Inheritance-v7` | 5 | 10 | 7.1s |  |
| 18 | `Inheritance-v8` | 5 | 10 | 2.1s |  |
| 19 | `LoadVars-v6` | 6 | 8 | 24.3s |  |
| 20 | `LoadVars-v7` | 6 | 8 | 5.7s |  |
| 21 | `LoadVars-v8` | 6 | 8 | 2.6s |  |
| 22 | `Math-v5` | 5 | 5 | 33.6s |  |
| 23 | `Math-v6` | 5 | 5 | 1.2s |  |
| 24 | `Math-v7` | 5 | 5 | 15.1s |  |
| 25 | `Math-v8` | 5 | 5 | 1.9s |  |
| 26 | `Matrix-v6` | 29 | 71 | 8.0s |  |
| 27 | `Matrix-v7` | 28 | 70 | 25.2s |  |
| 28 | `Matrix-v8` | 28 | 70 | 1.8s |  |
| 29 | `Microphone-v6` | 31 | 31 | 3.7s |  |
| 30 | `Microphone-v7` | 31 | 31 | 3.3s |  |
| 31 | `Microphone-v8` | 31 | 31 | 1.7s |  |
| 32 | `MovieClip-v5` | 48 | 226 | 31.7s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 4.0s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 2.7s |  |
| 35 | `Number-v5` | 8 | 13 | 9.3s |  |
| 36 | `Rectangle-v8` | 21 | 21 | 7.3s |  |
| 37 | `Selection-v6` | 7 | 13 | 5.6s |  |
| 38 | `Selection-v7` | 7 | 13 | 5.3s |  |
| 39 | `Selection-v8` | 7 | 13 | 1.7s |  |
| 40 | `Sound-v5` | 27 | 27 | 23.2s |  |
| 41 | `Sound-v6` | 30 | 51 | 5.5s |  |
| 42 | `Sound-v7` | 28 | 51 | 22.6s |  |
| 43 | `Sound-v8` | 28 | 51 | 1.9s |  |
| 44 | `String-v5` | 19 | 21 | 15.5s |  |
| 45 | `String-v6` | 10 | 10 | 16.4s |  |
| 46 | `String-v7` | 10 | 10 | 16.3s |  |
| 47 | `String-v8` | 10 | 10 | 28.4s |  |
| 48 | `TextField-v5` | 3 | 3 | 1.9s |  |
| 49 | `TextFormat-v7` | 38 | 40 | 24.6s |  |
| 50 | `ops-v8` | 7 | 11 | 9.6s |  |
| 51 | `targetPath-v6` | 17 | 17 | 2.5s |  |
| 52 | `targetPath-v7` | 17 | 17 | 2.1s |  |
| 53 | `targetPath-v8` | 17 | 17 | 1.6s |  |
| 54 | `toString_valueOf-v5` | 34 | 34 | 5.2s |  |
| 55 | `toString_valueOf-v6` | 5 | 5 | 5.7s |  |
| 56 | `toString_valueOf-v7` | 5 | 5 | 23.6s |  |
| 57 | `toString_valueOf-v8` | 5 | 5 | 1.7s |  |
| 58 | `with-v5` | 42 | 42 | 3.8s |  |
| 59 | `with-v6` | 91 | 91 | 4.9s |  |
| 60 | `with-v7` | 91 | 91 | 4.7s |  |
| 61 | `with-v8` | 91 | 91 | 1.9s |  |

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
| 1 | `Inheritance-v5` | exit code -6 | 5.4s |  |
| 2 | `Inheritance-v6` | exit code -6 | 7.7s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 4.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
