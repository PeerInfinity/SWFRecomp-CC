# Ruffle Test Results (Filtered)

**Date**: 2026-05-11 18:15 UTC

**Git SHA**: `65b8068012`

**Run Duration**: 3m 15s

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
| 1 | `Accessibility-v5` | 15 | 0.8s |  |
| 2 | `Accessibility-v6` | 19 | 0.8s |  |
| 3 | `Accessibility-v7` | 19 | 0.8s |  |
| 4 | `Accessibility-v8` | 19 | 0.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.9s |  |
| 6 | `BitmapData-v5` | 7 | 0.9s |  |
| 7 | `BitmapData-v6` | 7 | 0.7s |  |
| 8 | `BitmapData-v7` | 7 | 0.7s |  |
| 9 | `Boolean-v5` | 38 | 0.7s |  |
| 10 | `Boolean-v6` | 38 | 0.7s |  |
| 11 | `Boolean-v7` | 38 | 0.7s |  |
| 12 | `Boolean-v8` | 38 | 0.7s |  |
| 13 | `Camera-v5` | 7 | 0.9s |  |
| 14 | `Color-v5` | 140 | 0.7s |  |
| 15 | `Color-v6` | 171 | 0.7s |  |
| 16 | `Color-v7` | 161 | 0.8s |  |
| 17 | `Color-v8` | 161 | 0.7s |  |
| 18 | `ColorTransform-v5` | 7 | 0.8s |  |
| 19 | `ColorTransform-v6` | 7 | 0.7s |  |
| 20 | `ColorTransform-v7` | 7 | 0.8s |  |
| 21 | `ColorTransform-v8` | 55 | 0.8s |  |
| 22 | `ContextMenu-v5` | 7 | 0.8s |  |
| 23 | `ContextMenu-v6` | 7 | 0.7s |  |
| 24 | `ContextMenu-v7` | 131 | 0.8s |  |
| 25 | `ContextMenu-v8` | 131 | 0.9s |  |
| 26 | `Error-v5` | 28 | 0.9s |  |
| 27 | `Error-v6` | 31 | 0.9s |  |
| 28 | `Error-v7` | 31 | 1.0s |  |
| 29 | `Error-v8` | 31 | 0.9s |  |
| 30 | `ExternalInterface-v5` | 7 | 0.9s |  |
| 31 | `ExternalInterface-v6` | 55 | 0.9s |  |
| 32 | `ExternalInterface-v7` | 55 | 0.8s |  |
| 33 | `Global-v7` | 182 | 0.8s |  |
| 34 | `Global-v8` | 169 | 0.8s |  |
| 35 | `Instance-v5` | 52 | 0.8s |  |
| 36 | `Instance-v6` | 52 | 0.7s |  |
| 37 | `Instance-v7` | 52 | 0.9s |  |
| 38 | `Instance-v8` | 52 | 0.9s |  |
| 39 | `Key-v5` | 51 | 0.9s |  |
| 40 | `Key-v6` | 55 | 0.9s |  |
| 41 | `Key-v7` | 55 | 0.9s |  |
| 42 | `Key-v8` | 55 | 0.9s |  |
| 43 | `LoadVars-v5` | 8 | 0.9s |  |
| 44 | `LocalConnection-v5` | 7 | 0.9s |  |
| 45 | `LocalConnection-v6` | 58 | 0.8s |  |
| 46 | `LocalConnection-v7` | 58 | 0.8s |  |
| 47 | `LocalConnection-v8` | 58 | 0.8s |  |
| 48 | `Matrix-v5` | 7 | 0.9s |  |
| 49 | `Microphone-v5` | 6 | 0.9s |  |
| 50 | `Mouse-v5` | 13 | 0.8s |  |
| 51 | `Mouse-v6` | 21 | 0.8s |  |
| 52 | `Mouse-v7` | 21 | 0.8s |  |
| 53 | `Mouse-v8` | 21 | 0.8s |  |
| 54 | `MovieClipLoader-v5` | 6 | 0.8s |  |
| 55 | `MovieClipLoader-v6` | 6 | 0.9s |  |
| 56 | `NetConnection-v5` | 7 | 0.9s |  |
| 57 | `NetStream-v5` | 6 | 0.8s |  |
| 58 | `NetStream-v6` | 80 | 0.9s |  |
| 59 | `NetStream-v7` | 80 | 0.8s |  |
| 60 | `NetStream-v8` | 80 | 0.8s |  |
| 61 | `Number-v6` | 239 | 0.8s |  |
| 62 | `Number-v7` | 237 | 0.8s |  |
| 63 | `Number-v8` | 237 | 0.8s |  |
| 64 | `Point-v5` | 7 | 0.8s |  |
| 65 | `Point-v6` | 7 | 0.7s |  |
| 66 | `Point-v7` | 7 | 0.8s |  |
| 67 | `Point-v8` | 193 | 0.8s |  |
| 68 | `Random-v5` | 30 | 0.9s |  |
| 69 | `Random-v6` | 30 | 0.8s |  |
| 70 | `Random-v7` | 30 | 0.9s |  |
| 71 | `Random-v8` | 30 | 1.0s |  |
| 72 | `Rectangle-v5` | 7 | 0.8s |  |
| 73 | `Rectangle-v6` | 7 | 0.7s |  |
| 74 | `Rectangle-v7` | 7 | 0.8s |  |
| 75 | `Selection-v5` | 21 | 1.1s |  |
| 76 | `Stage-v5` | 38 | 0.7s |  |
| 77 | `System-v5` | 67 | 0.8s |  |
| 78 | `System-v6` | 100 | 0.8s |  |
| 79 | `System-v7` | 101 | 0.8s |  |
| 80 | `System-v8` | 101 | 0.8s |  |
| 81 | `TextFieldHTML-v5` | 6 | 0.8s |  |
| 82 | `TextFieldHTML-v6` | 37 | 0.9s |  |
| 83 | `TextFieldHTML-v7` | 37 | 0.8s |  |
| 84 | `TextFieldHTML-v8` | 37 | 0.8s |  |
| 85 | `TextFormat-v5` | 128 | 0.8s |  |
| 86 | `TextFormat-v6` | 128 | 0.7s |  |
| 87 | `TextSnapshot-v5` | 7 | 0.9s |  |
| 88 | `TextSnapshot-v6` | 173 | 0.9s |  |
| 89 | `TextSnapshot-v7` | 173 | 0.9s |  |
| 90 | `TextSnapshot-v8` | 173 | 0.9s |  |
| 91 | `Transform-v5` | 7 | 0.9s |  |
| 92 | `Transform-v6` | 7 | 1.0s |  |
| 93 | `Transform-v7` | 7 | 0.9s |  |
| 94 | `Try-v5` | 20 | 0.8s |  |
| 95 | `Try-v6` | 20 | 0.7s |  |
| 96 | `Try-v7` | 20 | 0.9s |  |
| 97 | `Try-v8` | 20 | 0.8s |  |
| 98 | `Video-v5` | 7 | 0.9s |  |
| 99 | `Video-v6` | 85 | 0.8s |  |
| 100 | `Video-v7` | 85 | 0.8s |  |
| 101 | `Video-v8` | 85 | 0.8s |  |
| 102 | `XMLSocket-v5` | 35 | 0.8s |  |
| 103 | `XMLSocket-v6` | 35 | 0.8s |  |
| 104 | `XMLSocket-v7` | 35 | 0.9s |  |
| 105 | `XMLSocket-v8` | 35 | 0.8s |  |
| 106 | `argstest-v5` | 4 | 0.9s |  |
| 107 | `case-v5` | 39 | 0.8s |  |
| 108 | `case-v7` | 67 | 0.9s |  |
| 109 | `case-v8` | 67 | 0.9s |  |
| 110 | `delete-v5` | 60 | 0.9s |  |
| 111 | `delete-v6` | 60 | 0.9s |  |
| 112 | `delete-v7` | 60 | 0.9s |  |
| 113 | `delete-v8` | 60 | 0.9s |  |
| 114 | `enumerate-v5` | 6 | 18.8s |  |
| 115 | `enumerate-v6` | 49 | 0.9s |  |
| 116 | `enumerate-v7` | 49 | 0.9s |  |
| 117 | `enumerate-v8` | 49 | 0.9s |  |
| 118 | `flash-v5` | 10 | 0.9s |  |
| 119 | `flash-v6` | 10 | 0.9s |  |
| 120 | `flash-v7` | 10 | 0.8s |  |
| 121 | `swap-v5` | 7 | 0.8s |  |
| 122 | `swap-v6` | 7 | 0.7s |  |
| 123 | `swap-v7` | 7 | 0.8s |  |
| 124 | `swap-v8` | 7 | 0.8s |  |
| 125 | `targetPath-v5` | 12 | 0.9s |  |

## Ruffle-Matched Tests

**61 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 0.9s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.8s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.8s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.8s |  |
| 5 | `AsBroadcaster-v6` | 7 | 13 | 0.9s |  |
| 6 | `AsBroadcaster-v7` | 7 | 13 | 0.9s |  |
| 7 | `AsBroadcaster-v8` | 7 | 13 | 0.9s |  |
| 8 | `BitmapData-v8` | 8 | 13 | 0.9s |  |
| 9 | `Camera-v6` | 57 | 57 | 0.7s |  |
| 10 | `Camera-v7` | 57 | 57 | 0.7s |  |
| 11 | `Camera-v8` | 57 | 57 | 0.7s |  |
| 12 | `ExternalInterface-v8` | 4 | 4 | 0.8s |  |
| 13 | `Global-v6` | 9 | 10 | 0.8s |  |
| 14 | `HitTest-v6` | 8 | 8 | 0.8s |  |
| 15 | `HitTest-v7` | 8 | 8 | 0.8s |  |
| 16 | `HitTest-v8` | 9 | 9 | 0.8s |  |
| 17 | `Inheritance-v7` | 5 | 10 | 0.9s |  |
| 18 | `Inheritance-v8` | 5 | 10 | 1.0s |  |
| 19 | `LoadVars-v6` | 6 | 8 | 0.9s |  |
| 20 | `LoadVars-v7` | 6 | 8 | 0.8s |  |
| 21 | `LoadVars-v8` | 6 | 8 | 0.9s |  |
| 22 | `Math-v5` | 5 | 5 | 0.9s |  |
| 23 | `Math-v6` | 5 | 5 | 0.8s |  |
| 24 | `Math-v7` | 5 | 5 | 0.9s |  |
| 25 | `Math-v8` | 5 | 5 | 0.9s |  |
| 26 | `Matrix-v6` | 29 | 71 | 0.9s |  |
| 27 | `Matrix-v7` | 28 | 70 | 0.9s |  |
| 28 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 29 | `Microphone-v6` | 31 | 31 | 0.9s |  |
| 30 | `Microphone-v7` | 31 | 31 | 0.9s |  |
| 31 | `Microphone-v8` | 31 | 31 | 0.9s |  |
| 32 | `MovieClip-v5` | 48 | 226 | 0.8s |  |
| 33 | `MovieClipLoader-v7` | 118 | 118 | 0.9s |  |
| 34 | `MovieClipLoader-v8` | 118 | 118 | 0.9s |  |
| 35 | `Number-v5` | 8 | 13 | 0.8s |  |
| 36 | `Rectangle-v8` | 21 | 21 | 0.8s |  |
| 37 | `Selection-v6` | 7 | 13 | 0.9s |  |
| 38 | `Selection-v7` | 7 | 13 | 0.9s |  |
| 39 | `Selection-v8` | 7 | 13 | 0.9s |  |
| 40 | `Sound-v5` | 27 | 27 | 1.0s |  |
| 41 | `Sound-v6` | 30 | 51 | 1.0s |  |
| 42 | `Sound-v7` | 28 | 51 | 0.8s |  |
| 43 | `Sound-v8` | 28 | 51 | 0.8s |  |
| 44 | `String-v5` | 19 | 21 | 1.3s |  |
| 45 | `String-v6` | 10 | 10 | 1.4s |  |
| 46 | `String-v7` | 10 | 10 | 2.0s |  |
| 47 | `String-v8` | 10 | 10 | 0.9s |  |
| 48 | `TextField-v5` | 3 | 3 | 0.8s |  |
| 49 | `TextFormat-v7` | 38 | 40 | 0.9s |  |
| 50 | `ops-v8` | 7 | 11 | 0.8s |  |
| 51 | `targetPath-v6` | 17 | 17 | 0.8s |  |
| 52 | `targetPath-v7` | 17 | 17 | 0.8s |  |
| 53 | `targetPath-v8` | 17 | 17 | 0.8s |  |
| 54 | `toString_valueOf-v5` | 34 | 34 | 0.9s |  |
| 55 | `toString_valueOf-v6` | 5 | 5 | 0.9s |  |
| 56 | `toString_valueOf-v7` | 5 | 5 | 0.8s |  |
| 57 | `toString_valueOf-v8` | 5 | 5 | 0.8s |  |
| 58 | `with-v5` | 42 | 42 | 0.8s |  |
| 59 | `with-v6` | 91 | 91 | 0.8s |  |
| 60 | `with-v7` | 91 | 91 | 0.8s |  |
| 61 | `with-v8` | 91 | 91 | 0.9s |  |

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
| 1 | `Inheritance-v5` | exit code -6 | 1.4s |  |
| 2 | `Inheritance-v6` | exit code -6 | 1.4s |  |
| 3 | `case-v6` | exit code -6 (output matches) | 1.5s |  |

## Timeouts

No timeouts.

## All Output Mismatches

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `array-v5` | 95.7% | 536/560 | 560 | 560 |  |
