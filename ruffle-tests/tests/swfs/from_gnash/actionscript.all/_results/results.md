# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-23 00:28 UTC

**Git SHA**: `2234cc5a3d`

**Run Duration**: 1m 33s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **110** (57.9%) |
| Ruffle-matched | 49 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **159** (83.7%) |
| Failing | 31 |
| Total expected lines | 16957 |
| Matching lines | 14742 (86.9%) |
| Mismatched lines | 2215 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 31 | 100.0% |

## Passing Tests

**110 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.4s |  |
| 2 | `Accessibility-v6` | 19 | 0.4s |  |
| 3 | `Accessibility-v7` | 19 | 0.4s |  |
| 4 | `Accessibility-v8` | 19 | 0.5s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.4s |  |
| 6 | `BitmapData-v5` | 7 | 0.4s |  |
| 7 | `BitmapData-v6` | 7 | 0.2s |  |
| 8 | `BitmapData-v7` | 7 | 0.5s |  |
| 9 | `Boolean-v5` | 38 | 0.5s |  |
| 10 | `Boolean-v6` | 38 | 0.5s |  |
| 11 | `Boolean-v7` | 38 | 0.5s |  |
| 12 | `Boolean-v8` | 38 | 0.5s |  |
| 13 | `Camera-v5` | 7 | 0.5s |  |
| 14 | `Color-v5` | 140 | 0.4s |  |
| 15 | `Color-v6` | 171 | 0.4s |  |
| 16 | `Color-v7` | 161 | 0.4s |  |
| 17 | `Color-v8` | 161 | 0.4s |  |
| 18 | `ColorTransform-v5` | 7 | 0.4s |  |
| 19 | `ColorTransform-v6` | 7 | 0.2s |  |
| 20 | `ColorTransform-v7` | 7 | 0.4s |  |
| 21 | `ColorTransform-v8` | 55 | 0.4s |  |
| 22 | `ContextMenu-v5` | 7 | 0.4s |  |
| 23 | `ContextMenu-v6` | 7 | 0.2s |  |
| 24 | `Error-v5` | 28 | 0.4s |  |
| 25 | `Error-v6` | 31 | 0.4s |  |
| 26 | `Error-v7` | 31 | 0.4s |  |
| 27 | `Error-v8` | 31 | 0.4s |  |
| 28 | `ExternalInterface-v5` | 7 | 0.4s |  |
| 29 | `Key-v5` | 51 | 0.4s |  |
| 30 | `Key-v6` | 55 | 0.4s |  |
| 31 | `Key-v7` | 55 | 0.4s |  |
| 32 | `Key-v8` | 55 | 0.4s |  |
| 33 | `LoadVars-v5` | 8 | 0.5s |  |
| 34 | `LocalConnection-v5` | 7 | 0.4s |  |
| 35 | `LocalConnection-v6` | 58 | 0.4s |  |
| 36 | `LocalConnection-v7` | 58 | 0.4s |  |
| 37 | `LocalConnection-v8` | 58 | 0.4s |  |
| 38 | `Matrix-v5` | 7 | 0.3s |  |
| 39 | `Microphone-v5` | 6 | 0.4s |  |
| 40 | `Mouse-v5` | 13 | 0.4s |  |
| 41 | `Mouse-v6` | 21 | 0.4s |  |
| 42 | `Mouse-v7` | 21 | 0.4s |  |
| 43 | `Mouse-v8` | 21 | 0.4s |  |
| 44 | `MovieClipLoader-v5` | 6 | 0.4s |  |
| 45 | `MovieClipLoader-v6` | 6 | 0.5s |  |
| 46 | `NetConnection-v5` | 7 | 0.4s |  |
| 47 | `NetStream-v5` | 6 | 0.4s |  |
| 48 | `NetStream-v6` | 80 | 0.4s |  |
| 49 | `NetStream-v7` | 80 | 0.4s |  |
| 50 | `NetStream-v8` | 80 | 0.4s |  |
| 51 | `Number-v6` | 239 | 0.4s |  |
| 52 | `Number-v7` | 237 | 0.4s |  |
| 53 | `Number-v8` | 237 | 0.4s |  |
| 54 | `Point-v5` | 7 | 0.4s |  |
| 55 | `Point-v6` | 7 | 0.2s |  |
| 56 | `Point-v7` | 7 | 0.4s |  |
| 57 | `Point-v8` | 193 | 0.4s |  |
| 58 | `Random-v5` | 30 | 0.5s |  |
| 59 | `Random-v6` | 30 | 0.3s |  |
| 60 | `Random-v7` | 30 | 0.5s |  |
| 61 | `Random-v8` | 30 | 0.5s |  |
| 62 | `Rectangle-v5` | 7 | 0.4s |  |
| 63 | `Rectangle-v6` | 7 | 0.2s |  |
| 64 | `Rectangle-v7` | 7 | 0.4s |  |
| 65 | `Selection-v5` | 21 | 0.4s |  |
| 66 | `Stage-v5` | 38 | 0.4s |  |
| 67 | `System-v5` | 67 | 0.5s |  |
| 68 | `System-v6` | 100 | 0.5s |  |
| 69 | `System-v7` | 101 | 0.5s |  |
| 70 | `System-v8` | 101 | 0.5s |  |
| 71 | `TextFieldHTML-v5` | 6 | 0.4s |  |
| 72 | `TextFormat-v5` | 128 | 0.4s |  |
| 73 | `TextFormat-v6` | 128 | 0.2s |  |
| 74 | `TextSnapshot-v5` | 7 | 0.4s |  |
| 75 | `TextSnapshot-v6` | 173 | 0.4s |  |
| 76 | `TextSnapshot-v7` | 173 | 0.4s |  |
| 77 | `TextSnapshot-v8` | 173 | 0.4s |  |
| 78 | `Transform-v5` | 7 | 0.4s |  |
| 79 | `Transform-v6` | 7 | 0.4s |  |
| 80 | `Transform-v7` | 7 | 0.4s |  |
| 81 | `Try-v5` | 20 | 0.4s |  |
| 82 | `Try-v6` | 20 | 0.2s |  |
| 83 | `Try-v7` | 20 | 0.4s |  |
| 84 | `Try-v8` | 20 | 0.4s |  |
| 85 | `Video-v5` | 7 | 0.5s |  |
| 86 | `Video-v6` | 85 | 0.5s |  |
| 87 | `Video-v7` | 85 | 0.5s |  |
| 88 | `Video-v8` | 85 | 0.5s |  |
| 89 | `XMLSocket-v5` | 35 | 0.4s |  |
| 90 | `XMLSocket-v6` | 35 | 0.4s |  |
| 91 | `XMLSocket-v7` | 35 | 0.4s |  |
| 92 | `XMLSocket-v8` | 35 | 0.4s |  |
| 93 | `argstest-v5` | 4 | 0.4s |  |
| 94 | `case-v5` | 39 | 0.4s |  |
| 95 | `delete-v5` | 60 | 0.4s |  |
| 96 | `delete-v6` | 60 | 0.4s |  |
| 97 | `delete-v7` | 60 | 0.4s |  |
| 98 | `delete-v8` | 60 | 0.4s |  |
| 99 | `enumerate-v5` | 6 | 0.4s |  |
| 100 | `enumerate-v6` | 49 | 0.4s |  |
| 101 | `enumerate-v7` | 49 | 0.6s |  |
| 102 | `enumerate-v8` | 49 | 0.4s |  |
| 103 | `flash-v5` | 10 | 0.4s |  |
| 104 | `flash-v6` | 10 | 0.6s |  |
| 105 | `flash-v7` | 10 | 0.4s |  |
| 106 | `swap-v5` | 7 | 0.4s |  |
| 107 | `swap-v6` | 7 | 0.2s |  |
| 108 | `swap-v7` | 7 | 0.4s |  |
| 109 | `swap-v8` | 7 | 0.4s |  |
| 110 | `targetPath-v5` | 12 | 0.4s |  |

## Ruffle-Matched Tests

**49 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 0.5s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.5s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.4s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.5s |  |
| 5 | `BitmapData-v8` | 8 | 13 | 0.6s |  |
| 6 | `Camera-v6` | 57 | 57 | 0.4s |  |
| 7 | `Camera-v7` | 57 | 57 | 0.4s |  |
| 8 | `Camera-v8` | 57 | 57 | 0.4s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 0.4s |  |
| 10 | `Inheritance-v5` | 1 | 17 | 0.5s |  |
| 11 | `Inheritance-v6` | 9 | 16 | 0.4s |  |
| 12 | `Inheritance-v7` | 5 | 10 | 0.4s |  |
| 13 | `Inheritance-v8` | 5 | 10 | 0.4s |  |
| 14 | `Math-v5` | 5 | 5 | 0.4s |  |
| 15 | `Math-v6` | 5 | 5 | 0.2s |  |
| 16 | `Math-v7` | 5 | 5 | 0.4s |  |
| 17 | `Math-v8` | 5 | 5 | 0.4s |  |
| 18 | `Matrix-v6` | 29 | 71 | 0.3s |  |
| 19 | `Matrix-v7` | 28 | 70 | 0.4s |  |
| 20 | `Matrix-v8` | 28 | 70 | 0.4s |  |
| 21 | `Microphone-v6` | 31 | 31 | 0.4s |  |
| 22 | `Microphone-v7` | 31 | 31 | 0.4s |  |
| 23 | `Microphone-v8` | 31 | 31 | 0.4s |  |
| 24 | `MovieClipLoader-v7` | 118 | 118 | 0.4s |  |
| 25 | `MovieClipLoader-v8` | 118 | 118 | 0.4s |  |
| 26 | `Rectangle-v8` | 21 | 21 | 0.5s |  |
| 27 | `Sound-v5` | 27 | 27 | 0.6s |  |
| 28 | `Sound-v6` | 30 | 51 | 0.6s |  |
| 29 | `Sound-v7` | 28 | 51 | 0.6s |  |
| 30 | `Sound-v8` | 28 | 51 | 0.6s |  |
| 31 | `String-v5` | 19 | 21 | 0.5s |  |
| 32 | `String-v6` | 10 | 10 | 0.5s |  |
| 33 | `String-v7` | 10 | 10 | 0.5s |  |
| 34 | `String-v8` | 10 | 10 | 0.5s |  |
| 35 | `TextField-v5` | 3 | 3 | 0.5s |  |
| 36 | `case-v7` | 54 | 54 | 0.4s |  |
| 37 | `case-v8` | 54 | 54 | 0.4s |  |
| 38 | `ops-v8` | 7 | 11 | 0.4s |  |
| 39 | `targetPath-v6` | 17 | 17 | 0.4s |  |
| 40 | `targetPath-v7` | 17 | 17 | 0.4s |  |
| 41 | `targetPath-v8` | 17 | 17 | 0.4s |  |
| 42 | `toString_valueOf-v5` | 34 | 34 | 0.4s |  |
| 43 | `toString_valueOf-v6` | 5 | 5 | 0.4s |  |
| 44 | `toString_valueOf-v7` | 5 | 5 | 0.5s |  |
| 45 | `toString_valueOf-v8` | 5 | 5 | 0.4s |  |
| 46 | `with-v5` | 42 | 42 | 0.4s |  |
| 47 | `with-v6` | 91 | 91 | 0.6s |  |
| 48 | `with-v7` | 91 | 91 | 0.6s |  |
| 49 | `with-v8` | 91 | 91 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**28 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `LoadVars-v6` | 95.4% | 146 | 153 | 7 |  |
| 2 | `LoadVars-v7` | 95.4% | 146 | 153 | 7 |  |
| 3 | `LoadVars-v8` | 95.4% | 146 | 153 | 7 |  |
| 4 | `Number-v5` | 95.1% | 232 | 244 | 12 |  |
| 5 | `Selection-v6` | 93.6% | 117 | 125 | 8 |  |
| 6 | `Selection-v7` | 93.6% | 117 | 125 | 8 |  |
| 7 | `Selection-v8` | 93.6% | 117 | 125 | 8 |  |
| 8 | `TextFieldHTML-v6` | 91.9% | 34 | 37 | 3 |  |
| 9 | `TextFieldHTML-v7` | 91.9% | 34 | 37 | 3 |  |
| 10 | `TextFieldHTML-v8` | 91.9% | 34 | 37 | 3 |  |
| 11 | `array-v5` | 91.4% | 512 | 560 | 48 |  |
| 12 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 13 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 14 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 15 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 16 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 17 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 18 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 19 | `MovieClip-v5` | 76.0% | 276 | 363 | 87 |  |
| 20 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 21 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 22 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 23 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 24 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 25 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 26 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 27 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 28 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**31 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `LoadVars-v6` | 95.4% | 146/153 | 153 | 152 |  |
| 2 | `LoadVars-v7` | 95.4% | 146/153 | 153 | 152 |  |
| 3 | `LoadVars-v8` | 95.4% | 146/153 | 153 | 152 |  |
| 4 | `Number-v5` | 95.1% | 232/244 | 244 | 244 |  |
| 5 | `Selection-v6` | 93.6% | 117/125 | 125 | 125 |  |
| 6 | `Selection-v7` | 93.6% | 117/125 | 125 | 125 |  |
| 7 | `Selection-v8` | 93.6% | 117/125 | 125 | 125 |  |
| 8 | `TextFieldHTML-v6` | 91.9% | 34/37 | 37 | 37 |  |
| 9 | `TextFieldHTML-v7` | 91.9% | 34/37 | 37 | 37 |  |
| 10 | `TextFieldHTML-v8` | 91.9% | 34/37 | 37 | 37 |  |
| 11 | `array-v5` | 91.4% | 512/560 | 560 | 560 |  |
| 12 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 13 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 14 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 15 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 16 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 17 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 18 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 19 | `MovieClip-v5` | 76.0% | 276/363 | 350 | 363 |  |
| 20 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 21 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 22 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 23 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 24 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 25 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 26 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 27 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 28 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 29 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 30 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 31 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
