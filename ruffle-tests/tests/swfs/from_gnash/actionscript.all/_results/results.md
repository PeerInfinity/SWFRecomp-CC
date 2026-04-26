# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-26 19:07 UTC

**Git SHA**: `d58ce3bf77`

**Run Duration**: 6m 42s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **113** (59.5%) |
| Ruffle-matched | 55 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **168** (88.4%) |
| Failing | 22 |
| Total expected lines | 16957 |
| Matching lines | 14757 (87.0%) |
| Mismatched lines | 2200 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 22 | 100.0% |

## Passing Tests

**113 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 2.0s |  |
| 2 | `Accessibility-v6` | 19 | 2.1s |  |
| 3 | `Accessibility-v7` | 19 | 1.7s |  |
| 4 | `Accessibility-v8` | 19 | 2.3s |  |
| 5 | `AsBroadcaster-v5` | 11 | 2.0s |  |
| 6 | `BitmapData-v5` | 7 | 1.4s |  |
| 7 | `BitmapData-v6` | 7 | 0.6s |  |
| 8 | `BitmapData-v7` | 7 | 0.2s |  |
| 9 | `Boolean-v5` | 38 | 0.2s |  |
| 10 | `Boolean-v6` | 38 | 0.2s |  |
| 11 | `Boolean-v7` | 38 | 0.2s |  |
| 12 | `Boolean-v8` | 38 | 0.2s |  |
| 13 | `Camera-v5` | 7 | 0.2s |  |
| 14 | `Color-v5` | 140 | 0.2s |  |
| 15 | `Color-v6` | 171 | 0.2s |  |
| 16 | `Color-v7` | 161 | 0.2s |  |
| 17 | `Color-v8` | 161 | 0.2s |  |
| 18 | `ColorTransform-v5` | 7 | 0.2s |  |
| 19 | `ColorTransform-v6` | 7 | 0.2s |  |
| 20 | `ColorTransform-v7` | 7 | 0.2s |  |
| 21 | `ColorTransform-v8` | 55 | 0.2s |  |
| 22 | `ContextMenu-v5` | 7 | 0.2s |  |
| 23 | `ContextMenu-v6` | 7 | 0.2s |  |
| 24 | `Error-v5` | 28 | 0.2s |  |
| 25 | `Error-v6` | 31 | 0.2s |  |
| 26 | `Error-v7` | 31 | 0.2s |  |
| 27 | `Error-v8` | 31 | 0.2s |  |
| 28 | `ExternalInterface-v5` | 7 | 0.2s |  |
| 29 | `Key-v5` | 51 | 2.6s |  |
| 30 | `Key-v6` | 55 | 2.6s |  |
| 31 | `Key-v7` | 55 | 2.3s |  |
| 32 | `Key-v8` | 55 | 1.2s |  |
| 33 | `LoadVars-v5` | 8 | 1.7s |  |
| 34 | `LocalConnection-v5` | 7 | 1.9s |  |
| 35 | `LocalConnection-v6` | 58 | 3.1s |  |
| 36 | `LocalConnection-v7` | 58 | 2.6s |  |
| 37 | `LocalConnection-v8` | 58 | 1.3s |  |
| 38 | `Matrix-v5` | 7 | 1.9s |  |
| 39 | `Microphone-v5` | 6 | 1.0s |  |
| 40 | `Mouse-v5` | 13 | 0.2s |  |
| 41 | `Mouse-v6` | 21 | 0.2s |  |
| 42 | `Mouse-v7` | 21 | 0.2s |  |
| 43 | `Mouse-v8` | 21 | 0.2s |  |
| 44 | `MovieClipLoader-v5` | 6 | 0.2s |  |
| 45 | `MovieClipLoader-v6` | 6 | 0.2s |  |
| 46 | `NetConnection-v5` | 7 | 0.2s |  |
| 47 | `NetStream-v5` | 6 | 0.2s |  |
| 48 | `NetStream-v6` | 80 | 0.2s |  |
| 49 | `NetStream-v7` | 80 | 3.2s |  |
| 50 | `NetStream-v8` | 80 | 1.3s |  |
| 51 | `Number-v6` | 239 | 9.2s |  |
| 52 | `Number-v7` | 237 | 9.0s |  |
| 53 | `Number-v8` | 237 | 1.4s |  |
| 54 | `Point-v5` | 7 | 1.3s |  |
| 55 | `Point-v6` | 7 | 0.6s |  |
| 56 | `Point-v7` | 7 | 1.3s |  |
| 57 | `Point-v8` | 193 | 7.5s |  |
| 58 | `Random-v5` | 30 | 2.3s |  |
| 59 | `Random-v6` | 30 | 0.6s |  |
| 60 | `Random-v7` | 30 | 2.5s |  |
| 61 | `Random-v8` | 30 | 1.4s |  |
| 62 | `Rectangle-v5` | 7 | 1.3s |  |
| 63 | `Rectangle-v6` | 7 | 0.6s |  |
| 64 | `Rectangle-v7` | 7 | 1.4s |  |
| 65 | `Selection-v5` | 21 | 0.2s |  |
| 66 | `Stage-v5` | 38 | 0.2s |  |
| 67 | `System-v5` | 67 | 3.2s |  |
| 68 | `System-v6` | 100 | 3.9s |  |
| 69 | `System-v7` | 101 | 4.0s |  |
| 70 | `System-v8` | 101 | 1.3s |  |
| 71 | `TextFieldHTML-v5` | 6 | 0.2s |  |
| 72 | `TextFieldHTML-v6` | 37 | 0.2s |  |
| 73 | `TextFieldHTML-v7` | 37 | 0.2s |  |
| 74 | `TextFieldHTML-v8` | 37 | 0.2s |  |
| 75 | `TextFormat-v5` | 128 | 0.2s |  |
| 76 | `TextFormat-v6` | 128 | 0.2s |  |
| 77 | `TextSnapshot-v5` | 7 | 1.1s |  |
| 78 | `TextSnapshot-v6` | 173 | 7.3s |  |
| 79 | `TextSnapshot-v7` | 173 | 6.9s |  |
| 80 | `TextSnapshot-v8` | 173 | 1.2s |  |
| 81 | `Transform-v5` | 7 | 1.3s |  |
| 82 | `Transform-v6` | 7 | 0.2s |  |
| 83 | `Transform-v7` | 7 | 0.2s |  |
| 84 | `Try-v5` | 20 | 0.2s |  |
| 85 | `Try-v6` | 20 | 0.2s |  |
| 86 | `Try-v7` | 20 | 0.5s |  |
| 87 | `Try-v8` | 20 | 0.6s |  |
| 88 | `Video-v5` | 7 | 0.2s |  |
| 89 | `Video-v6` | 85 | 0.2s |  |
| 90 | `Video-v7` | 85 | 0.2s |  |
| 91 | `Video-v8` | 85 | 0.2s |  |
| 92 | `XMLSocket-v5` | 35 | 0.2s |  |
| 93 | `XMLSocket-v6` | 35 | 0.2s |  |
| 94 | `XMLSocket-v7` | 35 | 2.5s |  |
| 95 | `XMLSocket-v8` | 35 | 1.4s |  |
| 96 | `argstest-v5` | 4 | 2.0s |  |
| 97 | `case-v5` | 39 | 2.5s |  |
| 98 | `delete-v5` | 60 | 2.9s |  |
| 99 | `delete-v6` | 60 | 2.3s |  |
| 100 | `delete-v7` | 60 | 2.5s |  |
| 101 | `delete-v8` | 60 | 1.4s |  |
| 102 | `enumerate-v5` | 6 | 0.2s |  |
| 103 | `enumerate-v6` | 49 | 0.2s |  |
| 104 | `enumerate-v7` | 49 | 0.2s |  |
| 105 | `enumerate-v8` | 49 | 0.2s |  |
| 106 | `flash-v5` | 10 | 0.2s |  |
| 107 | `flash-v6` | 10 | 0.2s |  |
| 108 | `flash-v7` | 10 | 1.9s |  |
| 109 | `swap-v5` | 7 | 1.8s |  |
| 110 | `swap-v6` | 7 | 0.6s |  |
| 111 | `swap-v7` | 7 | 1.4s |  |
| 112 | `swap-v8` | 7 | 1.2s |  |
| 113 | `targetPath-v5` | 12 | 2.0s |  |

## Ruffle-Matched Tests

**55 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 5.5s |  |
| 2 | `ASnative-v6` | 40 | 40 | 5.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 5.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 1.4s |  |
| 5 | `BitmapData-v8` | 8 | 13 | 0.4s |  |
| 6 | `Camera-v6` | 57 | 57 | 0.2s |  |
| 7 | `Camera-v7` | 57 | 57 | 0.2s |  |
| 8 | `Camera-v8` | 57 | 57 | 0.2s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 0.2s |  |
| 10 | `Inheritance-v5` | 1 | 17 | 4.7s |  |
| 11 | `Inheritance-v6` | 9 | 16 | 6.7s |  |
| 12 | `Inheritance-v7` | 5 | 10 | 6.8s |  |
| 13 | `Inheritance-v8` | 5 | 10 | 1.8s |  |
| 14 | `LoadVars-v6` | 6 | 21 | 5.6s |  |
| 15 | `LoadVars-v7` | 6 | 21 | 5.2s |  |
| 16 | `LoadVars-v8` | 6 | 21 | 2.1s |  |
| 17 | `Math-v5` | 5 | 5 | 13.6s |  |
| 18 | `Math-v6` | 5 | 5 | 0.6s |  |
| 19 | `Math-v7` | 5 | 5 | 14.0s |  |
| 20 | `Math-v8` | 5 | 5 | 1.4s |  |
| 21 | `Matrix-v6` | 29 | 71 | 7.1s |  |
| 22 | `Matrix-v7` | 28 | 70 | 6.5s |  |
| 23 | `Matrix-v8` | 28 | 70 | 1.2s |  |
| 24 | `Microphone-v6` | 31 | 31 | 3.0s |  |
| 25 | `Microphone-v7` | 31 | 31 | 2.6s |  |
| 26 | `Microphone-v8` | 31 | 31 | 1.1s |  |
| 27 | `MovieClipLoader-v7` | 118 | 118 | 0.2s |  |
| 28 | `MovieClipLoader-v8` | 118 | 118 | 0.2s |  |
| 29 | `Rectangle-v8` | 21 | 21 | 7.0s |  |
| 30 | `Selection-v6` | 7 | 13 | 0.2s |  |
| 31 | `Selection-v7` | 7 | 13 | 0.2s |  |
| 32 | `Selection-v8` | 7 | 13 | 0.2s |  |
| 33 | `Sound-v5` | 27 | 27 | 0.3s |  |
| 34 | `Sound-v6` | 30 | 51 | 0.3s |  |
| 35 | `Sound-v7` | 28 | 51 | 0.4s |  |
| 36 | `Sound-v8` | 28 | 51 | 0.3s |  |
| 37 | `String-v5` | 19 | 21 | 0.2s |  |
| 38 | `String-v6` | 10 | 10 | 0.2s |  |
| 39 | `String-v7` | 10 | 10 | 0.2s |  |
| 40 | `String-v8` | 10 | 10 | 1.6s |  |
| 41 | `TextField-v5` | 3 | 3 | 2.0s |  |
| 42 | `case-v7` | 54 | 54 | 3.4s |  |
| 43 | `case-v8` | 54 | 54 | 1.4s |  |
| 44 | `ops-v8` | 7 | 11 | 9.2s |  |
| 45 | `targetPath-v6` | 17 | 17 | 2.2s |  |
| 46 | `targetPath-v7` | 17 | 17 | 1.8s |  |
| 47 | `targetPath-v8` | 17 | 17 | 1.3s |  |
| 48 | `toString_valueOf-v5` | 34 | 34 | 5.2s |  |
| 49 | `toString_valueOf-v6` | 5 | 5 | 5.7s |  |
| 50 | `toString_valueOf-v7` | 5 | 5 | 5.9s |  |
| 51 | `toString_valueOf-v8` | 5 | 5 | 1.4s |  |
| 52 | `with-v5` | 42 | 42 | 3.5s |  |
| 53 | `with-v6` | 91 | 91 | 4.8s |  |
| 54 | `with-v7` | 91 | 91 | 4.5s |  |
| 55 | `with-v8` | 91 | 91 | 1.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**19 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Number-v5` | 95.1% | 232 | 244 | 12 |  |
| 2 | `array-v5` | 91.4% | 512 | 560 | 48 |  |
| 3 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 4 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 5 | `HitTest-v8` | 81.8% | 72 | 88 | 16 |  |
| 6 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 7 | `HitTest-v6` | 80.7% | 71 | 88 | 17 |  |
| 8 | `HitTest-v7` | 80.7% | 71 | 88 | 17 |  |
| 9 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 10 | `MovieClip-v5` | 76.0% | 276 | 363 | 87 |  |
| 11 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 12 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 13 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 14 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 15 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 16 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 17 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 18 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 19 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**22 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Number-v5` | 95.1% | 232/244 | 244 | 244 |  |
| 2 | `array-v5` | 91.4% | 512/560 | 560 | 560 |  |
| 3 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 4 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 5 | `HitTest-v8` | 81.8% | 72/88 | 88 | 88 |  |
| 6 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 7 | `HitTest-v6` | 80.7% | 71/88 | 88 | 88 |  |
| 8 | `HitTest-v7` | 80.7% | 71/88 | 88 | 88 |  |
| 9 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 10 | `MovieClip-v5` | 76.0% | 276/363 | 350 | 363 |  |
| 11 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 12 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 13 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 14 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 15 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 16 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 17 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 18 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 19 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 20 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 21 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 22 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
