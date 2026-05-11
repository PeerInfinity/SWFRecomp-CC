# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 22:57 UTC

**Git SHA**: `a48ecfae33`

**Run Duration**: 13m 56s

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
| 1 | `Accessibility-v5` | 15 | 1.0s |  |
| 2 | `Accessibility-v6` | 19 | 1.0s |  |
| 3 | `Accessibility-v7` | 19 | 1.0s |  |
| 4 | `Accessibility-v8` | 19 | 17.6s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.0s |  |
| 6 | `BitmapData-v5` | 7 | 1.0s |  |
| 7 | `BitmapData-v6` | 7 | 0.8s |  |
| 8 | `BitmapData-v7` | 7 | 14.8s |  |
| 9 | `Boolean-v5` | 38 | 0.8s |  |
| 10 | `Boolean-v6` | 38 | 0.8s |  |
| 11 | `Boolean-v7` | 38 | 0.8s |  |
| 12 | `Boolean-v8` | 38 | 0.8s |  |
| 13 | `Camera-v5` | 7 | 0.8s |  |
| 14 | `Color-v5` | 140 | 0.8s |  |
| 15 | `Color-v6` | 171 | 0.8s |  |
| 16 | `Color-v7` | 161 | 0.8s |  |
| 17 | `Color-v8` | 161 | 0.8s |  |
| 18 | `ColorTransform-v5` | 7 | 19.7s |  |
| 19 | `ColorTransform-v6` | 7 | 0.9s |  |
| 20 | `ColorTransform-v7` | 7 | 1.1s |  |
| 21 | `ColorTransform-v8` | 55 | 1.1s |  |
| 22 | `ContextMenu-v5` | 7 | 1.1s |  |
| 23 | `ContextMenu-v6` | 7 | 0.9s |  |
| 24 | `ContextMenu-v7` | 131 | 1.1s |  |
| 25 | `ContextMenu-v8` | 131 | 18.7s |  |
| 26 | `Error-v5` | 28 | 1.1s |  |
| 27 | `Error-v6` | 31 | 1.1s |  |
| 28 | `Error-v7` | 31 | 1.1s |  |
| 29 | `Error-v8` | 31 | 1.1s |  |
| 30 | `ExternalInterface-v5` | 7 | 1.1s |  |
| 31 | `ExternalInterface-v6` | 55 | 1.1s |  |
| 32 | `ExternalInterface-v7` | 55 | 18.7s |  |
| 33 | `Global-v7` | 182 | 1.1s |  |
| 34 | `Global-v8` | 169 | 1.1s |  |
| 35 | `Instance-v5` | 52 | 1.0s |  |
| 36 | `Instance-v6` | 52 | 0.9s |  |
| 37 | `Instance-v7` | 52 | 17.9s |  |
| 38 | `Instance-v8` | 52 | 1.0s |  |
| 39 | `Key-v5` | 51 | 1.0s |  |
| 40 | `Key-v6` | 55 | 1.0s |  |
| 41 | `Key-v7` | 55 | 1.0s |  |
| 42 | `Key-v8` | 55 | 1.0s |  |
| 43 | `LoadVars-v5` | 8 | 18.1s |  |
| 44 | `LocalConnection-v5` | 7 | 18.2s |  |
| 45 | `LocalConnection-v6` | 58 | 1.0s |  |
| 46 | `LocalConnection-v7` | 58 | 1.0s |  |
| 47 | `LocalConnection-v8` | 58 | 1.0s |  |
| 48 | `Matrix-v5` | 7 | 1.1s |  |
| 49 | `Microphone-v5` | 6 | 1.1s |  |
| 50 | `Mouse-v5` | 13 | 14.3s |  |
| 51 | `Mouse-v6` | 21 | 0.8s |  |
| 52 | `Mouse-v7` | 21 | 0.8s |  |
| 53 | `Mouse-v8` | 21 | 0.8s |  |
| 54 | `MovieClipLoader-v5` | 6 | 0.8s |  |
| 55 | `MovieClipLoader-v6` | 6 | 18.1s |  |
| 56 | `NetConnection-v5` | 7 | 18.0s |  |
| 57 | `NetStream-v5` | 6 | 1.0s |  |
| 58 | `NetStream-v6` | 80 | 1.0s |  |
| 59 | `NetStream-v7` | 80 | 18.1s |  |
| 60 | `NetStream-v8` | 80 | 1.0s |  |
| 61 | `Number-v6` | 239 | 1.0s |  |
| 62 | `Number-v7` | 237 | 1.0s |  |
| 63 | `Number-v8` | 237 | 1.0s |  |
| 64 | `Point-v5` | 7 | 18.1s |  |
| 65 | `Point-v6` | 7 | 0.8s |  |
| 66 | `Point-v7` | 7 | 1.0s |  |
| 67 | `Point-v8` | 193 | 1.0s |  |
| 68 | `Random-v5` | 30 | 1.0s |  |
| 69 | `Random-v6` | 30 | 0.8s |  |
| 70 | `Random-v7` | 30 | 17.8s |  |
| 71 | `Random-v8` | 30 | 0.9s |  |
| 72 | `Rectangle-v5` | 7 | 0.9s |  |
| 73 | `Rectangle-v6` | 7 | 0.7s |  |
| 74 | `Rectangle-v7` | 7 | 0.8s |  |
| 75 | `Selection-v5` | 21 | 17.9s |  |
| 76 | `Stage-v5` | 38 | 19.6s |  |
| 77 | `System-v5` | 67 | 1.0s |  |
| 78 | `System-v6` | 100 | 1.0s |  |
| 79 | `System-v7` | 101 | 1.0s |  |
| 80 | `System-v8` | 101 | 1.0s |  |
| 81 | `TextFieldHTML-v5` | 6 | 17.7s |  |
| 82 | `TextFieldHTML-v6` | 37 | 1.0s |  |
| 83 | `TextFieldHTML-v7` | 37 | 1.0s |  |
| 84 | `TextFieldHTML-v8` | 37 | 1.0s |  |
| 85 | `TextFormat-v5` | 128 | 1.0s |  |
| 86 | `TextFormat-v6` | 128 | 0.8s |  |
| 87 | `TextSnapshot-v5` | 7 | 1.1s |  |
| 88 | `TextSnapshot-v6` | 173 | 1.1s |  |
| 89 | `TextSnapshot-v7` | 173 | 1.1s |  |
| 90 | `TextSnapshot-v8` | 173 | 1.1s |  |
| 91 | `Transform-v5` | 7 | 1.1s |  |
| 92 | `Transform-v6` | 7 | 18.9s |  |
| 93 | `Transform-v7` | 7 | 0.9s |  |
| 94 | `Try-v5` | 20 | 0.9s |  |
| 95 | `Try-v6` | 20 | 0.7s |  |
| 96 | `Try-v7` | 20 | 0.9s |  |
| 97 | `Try-v8` | 20 | 0.9s |  |
| 98 | `Video-v5` | 7 | 18.2s |  |
| 99 | `Video-v6` | 85 | 1.0s |  |
| 100 | `Video-v7` | 85 | 1.0s |  |
| 101 | `Video-v8` | 85 | 1.0s |  |
| 102 | `XMLSocket-v5` | 35 | 17.9s |  |
| 103 | `XMLSocket-v6` | 35 | 1.0s |  |
| 104 | `XMLSocket-v7` | 35 | 18.6s |  |
| 105 | `XMLSocket-v8` | 35 | 1.0s |  |
| 106 | `argstest-v5` | 4 | 1.0s |  |
| 107 | `case-v5` | 39 | 1.0s |  |
| 108 | `case-v7` | 67 | 19.1s |  |
| 109 | `case-v8` | 67 | 1.1s |  |
| 110 | `delete-v5` | 60 | 1.1s |  |
| 111 | `delete-v6` | 60 | 1.1s |  |
| 112 | `delete-v7` | 60 | 1.1s |  |
| 113 | `delete-v8` | 60 | 1.1s |  |
| 114 | `enumerate-v5` | 6 | 19.4s |  |
| 115 | `enumerate-v6` | 49 | 1.1s |  |
| 116 | `enumerate-v7` | 49 | 1.0s |  |
| 117 | `enumerate-v8` | 49 | 1.1s |  |
| 118 | `flash-v5` | 10 | 1.0s |  |
| 119 | `flash-v6` | 10 | 1.0s |  |
| 120 | `flash-v7` | 10 | 18.1s |  |
| 121 | `swap-v5` | 7 | 1.0s |  |
| 122 | `swap-v6` | 7 | 0.8s |  |
| 123 | `swap-v7` | 7 | 1.0s |  |
| 124 | `swap-v8` | 7 | 1.0s |  |
| 125 | `targetPath-v5` | 12 | 18.6s |  |

## Ruffle-Matched Tests

**61 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 18.0s |  |
| 2 | `ASnative-v6` | 40 | 40 | 1.0s |  |
| 3 | `ASnative-v7` | 40 | 40 | 1.0s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.0s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 1.0s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 1.0s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 1.0s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 1.0s |  |
| 9 | `Camera-v6` | 57 | 57 | 17.3s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.8s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.8s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 1.1s |  |
| 13 | `Global-v6` | 9 | 10 | 1.1s |  |
| 14 | `HitTest-v6` | 8 | 8 | 1.1s |  |
| 15 | `HitTest-v7` | 8 | 8 | 1.1s |  |
| 16 | `HitTest-v8` | 9 | 9 | 18.1s |  |
| 17 | `Inheritance-v7` | 5 | 10 | 1.1s |  |
| 18 | `Inheritance-v8` | 5 | 10 | 1.0s |  |
| 19 | `LoadVars-v6` | 6 | 8 | 18.5s |  |
| 20 | `LoadVars-v7` | 6 | 8 | 1.0s |  |
| 21 | `LoadVars-v8` | 6 | 8 | 1.0s |  |
| 22 | `Math-v5` | 5 | 5 | 20.5s |  |
| 23 | `Math-v6` | 5 | 5 | 0.9s |  |
| 24 | `Math-v7` | 5 | 5 | 1.1s |  |
| 25 | `Math-v8` | 5 | 5 | 1.1s |  |
| 26 | `Matrix-v6` | 29 | 71 | 1.1s |  |
| 27 | `Matrix-v7` | 28 | 70 | 18.5s |  |
| 28 | `Matrix-v8` | 28 | 70 | 1.1s |  |
| 29 | `Microphone-v6` | 31 | 31 | 1.1s |  |
| 30 | `Microphone-v7` | 31 | 31 | 1.1s |  |
| 31 | `Microphone-v8` | 31 | 31 | 1.1s |  |
| 32 | `MovieClip-v5` | 48 | 226 | 14.4s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 1.0s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 1.0s |  |
| 35 | `Number-v5` | 8 | 13 | 1.0s |  |
| 36 | `Rectangle-v8` | 21 | 21 | 0.9s |  |
| 37 | `Selection-v6` | 7 | 13 | 1.0s |  |
| 38 | `Selection-v7` | 7 | 13 | 1.0s |  |
| 39 | `Selection-v8` | 7 | 13 | 1.0s |  |
| 40 | `Sound-v5` | 27 | 27 | 18.1s |  |
| 41 | `Sound-v6` | 30 | 51 | 1.1s |  |
| 42 | `Sound-v7` | 28 | 51 | 20.8s |  |
| 43 | `Sound-v8` | 28 | 51 | 1.3s |  |
| 44 | `String-v5` | 19 | 21 | 1.1s |  |
| 45 | `String-v6` | 10 | 10 | 1.1s |  |
| 46 | `String-v7` | 10 | 10 | 1.1s |  |
| 47 | `String-v8` | 10 | 10 | 17.9s |  |
| 48 | `TextField-v5` | 3 | 3 | 1.0s |  |
| 49 | `TextFormat-v7` | 38 | 40 | 18.9s |  |
| 50 | `ops-v8` | 7 | 11 | 1.0s |  |
| 51 | `targetPath-v6` | 17 | 17 | 1.1s |  |
| 52 | `targetPath-v7` | 17 | 17 | 1.1s |  |
| 53 | `targetPath-v8` | 17 | 17 | 1.1s |  |
| 54 | `toString_valueOf-v5` | 34 | 34 | 1.1s |  |
| 55 | `toString_valueOf-v6` | 5 | 5 | 1.1s |  |
| 56 | `toString_valueOf-v7` | 5 | 5 | 19.6s |  |
| 57 | `toString_valueOf-v8` | 5 | 5 | 1.1s |  |
| 58 | `with-v5` | 42 | 42 | 1.1s |  |
| 59 | `with-v6` | 91 | 91 | 1.1s |  |
| 60 | `with-v7` | 91 | 91 | 1.1s |  |
| 61 | `with-v8` | 91 | 91 | 1.1s |  |

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
| 1 | `Inheritance-v5` | exit code -6 | 1.5s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.6s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 1.6s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
