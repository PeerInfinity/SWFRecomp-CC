# Ruffle Test Results (Filtered)

**Date**: 2026-05-14 03:41 UTC

**Git SHA**: `50f5aa00c1`

**Run Duration**: 24m 10s

**Filtered**: 0 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **124** (65.3%) |
| Ruffle-matched | 61 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **185** (97.4%) |
| Failing | 5 |
| Total expected lines | 16957 |
| Matching lines | 15393 (90.8%) |
| Mismatched lines | 1564 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Runtime Error | 4 | 80.0% |
| Output Mismatch | 1 | 20.0% |

## Passing Tests

**124 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.5s |  |
| 2 | `Accessibility-v6` | 19 | 2.6s |  |
| 3 | `Accessibility-v7` | 19 | 2.2s |  |
| 4 | `Accessibility-v8` | 19 | 21.2s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.5s |  |
| 6 | `BitmapData-v5` | 7 | 2.4s |  |
| 7 | `BitmapData-v6` | 7 | 1.2s |  |
| 8 | `BitmapData-v7` | 7 | 20.2s |  |
| 9 | `Boolean-v5` | 38 | 2.9s |  |
| 10 | `Boolean-v6` | 38 | 2.3s |  |
| 11 | `Boolean-v7` | 38 | 2.9s |  |
| 12 | `Boolean-v8` | 38 | 1.8s |  |
| 13 | `Camera-v5` | 7 | 2.3s |  |
| 14 | `Color-v5` | 140 | 5.6s |  |
| 15 | `Color-v6` | 171 | 6.5s |  |
| 16 | `Color-v7` | 161 | 6.3s |  |
| 17 | `Color-v8` | 161 | 1.8s |  |
| 18 | `ColorTransform-v5` | 7 | 20.2s |  |
| 19 | `ColorTransform-v6` | 7 | 1.1s |  |
| 20 | `ColorTransform-v7` | 7 | 1.8s |  |
| 21 | `ColorTransform-v8` | 55 | 3.5s |  |
| 22 | `ContextMenu-v5` | 7 | 2.2s |  |
| 23 | `ContextMenu-v6` | 7 | 1.1s |  |
| 24 | `ContextMenu-v7` | 131 | 5.3s |  |
| 25 | `ContextMenu-v8` | 131 | 22.4s |  |
| 26 | `Error-v5` | 28 | 2.7s |  |
| 27 | `Error-v6` | 31 | 2.8s |  |
| 28 | `Error-v7` | 31 | 2.4s |  |
| 29 | `Error-v8` | 31 | 1.8s |  |
| 30 | `ExternalInterface-v5` | 7 | 2.3s |  |
| 31 | `ExternalInterface-v6` | 55 | 3.1s |  |
| 32 | `ExternalInterface-v7` | 55 | 20.4s |  |
| 33 | `Global-v7` | 182 | 7.3s |  |
| 34 | `Global-v8` | 169 | 6.8s |  |
| 35 | `Instance-v5` | 52 | 3.7s |  |
| 36 | `Instance-v6` | 52 | 2.5s |  |
| 37 | `Instance-v7` | 52 | 21.4s |  |
| 38 | `Instance-v8` | 52 | 1.8s |  |
| 39 | `Key-v5` | 51 | 3.2s |  |
| 40 | `Key-v6` | 55 | 3.4s |  |
| 41 | `Key-v7` | 55 | 3.0s |  |
| 42 | `Key-v8` | 55 | 1.8s |  |
| 43 | `LoadVars-v5` | 8 | 20.7s |  |
| 44 | `LocalConnection-v5` | 7 | 20.4s |  |
| 45 | `LocalConnection-v6` | 58 | 3.7s |  |
| 46 | `LocalConnection-v7` | 58 | 3.2s |  |
| 47 | `LocalConnection-v8` | 58 | 1.9s |  |
| 48 | `Matrix-v5` | 7 | 2.4s |  |
| 49 | `Microphone-v5` | 6 | 2.4s |  |
| 50 | `Mouse-v5` | 13 | 19.9s |  |
| 51 | `Mouse-v6` | 21 | 2.5s |  |
| 52 | `Mouse-v7` | 21 | 2.2s |  |
| 53 | `Mouse-v8` | 21 | 1.8s |  |
| 54 | `MovieClipLoader-v5` | 6 | 2.3s |  |
| 55 | `MovieClipLoader-v6` | 6 | 20.5s |  |
| 56 | `NetConnection-v5` | 7 | 20.1s |  |
| 57 | `NetStream-v5` | 6 | 2.4s |  |
| 58 | `NetStream-v6` | 80 | 4.1s |  |
| 59 | `NetStream-v7` | 80 | 22.7s |  |
| 60 | `NetStream-v8` | 80 | 2.0s |  |
| 61 | `Number-v6` | 239 | 10.1s |  |
| 62 | `Number-v7` | 237 | 10.0s |  |
| 63 | `Number-v8` | 237 | 2.1s |  |
| 64 | `Point-v5` | 7 | 20.4s |  |
| 65 | `Point-v6` | 7 | 1.3s |  |
| 66 | `Point-v7` | 7 | 2.1s |  |
| 67 | `Point-v8` | 193 | 8.6s |  |
| 68 | `Random-v5` | 30 | 2.9s |  |
| 69 | `Random-v6` | 30 | 1.2s |  |
| 70 | `Random-v7` | 30 | 19.8s |  |
| 71 | `Random-v8` | 30 | 1.8s |  |
| 72 | `Rectangle-v5` | 7 | 2.3s |  |
| 73 | `Rectangle-v6` | 7 | 1.2s |  |
| 74 | `Rectangle-v7` | 7 | 1.9s |  |
| 75 | `Selection-v5` | 21 | 20.1s |  |
| 76 | `Stage-v5` | 38 | 16.4s |  |
| 77 | `System-v5` | 67 | 3.8s |  |
| 78 | `System-v6` | 100 | 4.6s |  |
| 79 | `System-v7` | 101 | 4.7s |  |
| 80 | `System-v8` | 101 | 1.9s |  |
| 81 | `TextFieldHTML-v5` | 6 | 19.7s |  |
| 82 | `TextFieldHTML-v6` | 37 | 3.0s |  |
| 83 | `TextFieldHTML-v7` | 37 | 2.6s |  |
| 84 | `TextFieldHTML-v8` | 37 | 1.8s |  |
| 85 | `TextFormat-v5` | 128 | 5.3s |  |
| 86 | `TextFormat-v6` | 128 | 1.2s |  |
| 87 | `TextSnapshot-v5` | 7 | 2.1s |  |
| 88 | `TextSnapshot-v6` | 173 | 7.5s |  |
| 89 | `TextSnapshot-v7` | 173 | 7.1s |  |
| 90 | `TextSnapshot-v8` | 173 | 1.7s |  |
| 91 | `Transform-v5` | 7 | 2.1s |  |
| 92 | `Transform-v6` | 7 | 20.4s |  |
| 93 | `Transform-v7` | 7 | 2.1s |  |
| 94 | `Try-v5` | 20 | 3.3s |  |
| 95 | `Try-v6` | 20 | 1.2s |  |
| 96 | `Try-v7` | 20 | 2.9s |  |
| 97 | `Try-v8` | 20 | 1.9s |  |
| 98 | `Video-v5` | 7 | 20.4s |  |
| 99 | `Video-v6` | 85 | 4.3s |  |
| 100 | `Video-v7` | 85 | 3.9s |  |
| 101 | `Video-v8` | 85 | 1.9s |  |
| 102 | `XMLSocket-v5` | 35 | 21.9s |  |
| 103 | `XMLSocket-v6` | 35 | 3.1s |  |
| 104 | `XMLSocket-v7` | 35 | 21.7s |  |
| 105 | `XMLSocket-v8` | 35 | 2.0s |  |
| 106 | `argstest-v5` | 4 | 2.7s |  |
| 107 | `case-v7` | 67 | 21.5s |  |
| 108 | `case-v8` | 67 | 2.0s |  |
| 109 | `delete-v5` | 60 | 3.4s |  |
| 110 | `delete-v6` | 60 | 2.9s |  |
| 111 | `delete-v7` | 60 | 3.1s |  |
| 112 | `delete-v8` | 60 | 2.0s |  |
| 113 | `enumerate-v5` | 6 | 19.7s |  |
| 114 | `enumerate-v6` | 49 | 3.4s |  |
| 115 | `enumerate-v7` | 49 | 3.0s |  |
| 116 | `enumerate-v8` | 49 | 1.8s |  |
| 117 | `flash-v5` | 10 | 2.4s |  |
| 118 | `flash-v6` | 10 | 2.4s |  |
| 119 | `flash-v7` | 10 | 16.0s |  |
| 120 | `swap-v5` | 7 | 2.1s |  |
| 121 | `swap-v6` | 7 | 1.1s |  |
| 122 | `swap-v7` | 7 | 1.6s |  |
| 123 | `swap-v8` | 7 | 1.4s |  |
| 124 | `targetPath-v5` | 12 | 20.1s |  |

## Ruffle-Matched Tests

**61 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 23.9s |  |
| 2 | `ASnative-v6` | 40 | 40 | 6.1s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.8s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.9s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 5.7s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 5.3s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.9s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 24.1s |  |
| 9 | `Camera-v6` | 57 | 57 | 21.4s |  |
| 10 | `Camera-v7` | 57 | 57 | 3.8s |  |
| 11 | `Camera-v8` | 57 | 57 | 1.8s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 5.0s |  |
| 13 | `Global-v6` | 9 | 10 | 8.2s |  |
| 14 | `HitTest-v6` | 8 | 8 | 5.1s |  |
| 15 | `HitTest-v7` | 8 | 8 | 4.7s |  |
| 16 | `HitTest-v8` | 9 | 9 | 26.3s |  |
| 17 | `Inheritance-v7` | 5 | 10 | 8.2s |  |
| 18 | `Inheritance-v8` | 5 | 10 | 2.5s |  |
| 19 | `LoadVars-v6` | 6 | 8 | 24.2s |  |
| 20 | `LoadVars-v7` | 6 | 8 | 5.8s |  |
| 21 | `LoadVars-v8` | 6 | 8 | 2.7s |  |
| 22 | `Math-v5` | 5 | 5 | 32.0s |  |
| 23 | `Math-v6` | 5 | 5 | 1.3s |  |
| 24 | `Math-v7` | 5 | 5 | 14.9s |  |
| 25 | `Math-v8` | 5 | 5 | 2.0s |  |
| 26 | `Matrix-v6` | 29 | 71 | 7.8s |  |
| 27 | `Matrix-v7` | 28 | 70 | 25.9s |  |
| 28 | `Matrix-v8` | 28 | 70 | 1.9s |  |
| 29 | `Microphone-v6` | 31 | 31 | 3.9s |  |
| 30 | `Microphone-v7` | 31 | 31 | 3.5s |  |
| 31 | `Microphone-v8` | 31 | 31 | 1.8s |  |
| 32 | `MovieClip-v5` | 48 | 226 | 30.9s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 4.4s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 3.0s |  |
| 35 | `Number-v5` | 8 | 13 | 10.3s |  |
| 36 | `Rectangle-v8` | 21 | 21 | 6.7s |  |
| 37 | `Selection-v6` | 7 | 13 | 5.6s |  |
| 38 | `Selection-v7` | 7 | 13 | 5.2s |  |
| 39 | `Selection-v8` | 7 | 13 | 1.9s |  |
| 40 | `Sound-v5` | 27 | 27 | 22.6s |  |
| 41 | `Sound-v6` | 30 | 51 | 5.4s |  |
| 42 | `Sound-v7` | 28 | 51 | 19.3s |  |
| 43 | `Sound-v8` | 28 | 51 | 1.8s |  |
| 44 | `String-v5` | 19 | 21 | 13.8s |  |
| 45 | `String-v6` | 10 | 10 | 14.3s |  |
| 46 | `String-v7` | 10 | 10 | 14.2s |  |
| 47 | `String-v8` | 10 | 10 | 35.6s |  |
| 48 | `TextField-v5` | 3 | 3 | 2.5s |  |
| 49 | `TextFormat-v7` | 38 | 40 | 24.5s |  |
| 50 | `ops-v8` | 7 | 11 | 8.3s |  |
| 51 | `targetPath-v6` | 17 | 17 | 2.6s |  |
| 52 | `targetPath-v7` | 17 | 17 | 2.2s |  |
| 53 | `targetPath-v8` | 17 | 17 | 1.8s |  |
| 54 | `toString_valueOf-v5` | 34 | 34 | 5.3s |  |
| 55 | `toString_valueOf-v6` | 5 | 5 | 5.8s |  |
| 56 | `toString_valueOf-v7` | 5 | 5 | 24.7s |  |
| 57 | `toString_valueOf-v8` | 5 | 5 | 1.9s |  |
| 58 | `with-v5` | 42 | 42 | 4.0s |  |
| 59 | `with-v6` | 91 | 91 | 5.2s |  |
| 60 | `with-v7` | 91 | 91 | 4.8s |  |
| 61 | `with-v8` | 91 | 91 | 2.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `array-v5` | 95.7% | 536 | 560 | 24 |  |

## Segfaults

No segfaults.

## Runtime Errors

**4 tests** fail with runtime errors

| # | Test | Detail | Duration | Notes |
|---|------|--------|----------|-------|
| 1 | `Inheritance-v5` | exit code -6 | 6.5s |  |
| 2 | `Inheritance-v6` | exit code -6 | 8.9s |  |
| 3 | `case-v5` | exit code -6 (output matches) | 4.0s |  |
| 4 | `case-v6` | exit code -6 (output matches) | 5.0s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
