# Ruffle Test Results (Unfiltered)

**Date**: 2026-04-20 22:23 UTC

**Git SHA**: `483fff6cfb`

**Run Duration**: 3m 1s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **109** (57.4%) |
| Ruffle-matched | 43 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **152** (80.0%) |
| Failing | 38 |
| Total expected lines | 16957 |
| Matching lines | 14325 (84.5%) |
| Mismatched lines | 2632 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 38 | 100.0% |

## Passing Tests

**109 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 0.6s |  |
| 2 | `Accessibility-v6` | 19 | 0.7s |  |
| 3 | `Accessibility-v7` | 19 | 0.2s |  |
| 4 | `Accessibility-v8` | 19 | 0.7s |  |
| 5 | `AsBroadcaster-v5` | 11 | 0.7s |  |
| 6 | `BitmapData-v5` | 7 | 0.7s |  |
| 7 | `BitmapData-v6` | 7 | 0.2s |  |
| 8 | `BitmapData-v7` | 7 | 0.8s |  |
| 9 | `Boolean-v5` | 38 | 0.7s |  |
| 10 | `Boolean-v6` | 38 | 0.3s |  |
| 11 | `Boolean-v7` | 38 | 0.7s |  |
| 12 | `Boolean-v8` | 38 | 0.3s |  |
| 13 | `Camera-v5` | 7 | 0.7s |  |
| 14 | `Color-v5` | 140 | 0.8s |  |
| 15 | `Color-v6` | 171 | 0.8s |  |
| 16 | `Color-v7` | 161 | 0.8s |  |
| 17 | `Color-v8` | 161 | 0.3s |  |
| 18 | `ColorTransform-v5` | 7 | 0.7s |  |
| 19 | `ColorTransform-v6` | 7 | 0.2s |  |
| 20 | `ColorTransform-v7` | 7 | 0.2s |  |
| 21 | `ColorTransform-v8` | 55 | 0.7s |  |
| 22 | `ContextMenu-v5` | 7 | 0.6s |  |
| 23 | `ContextMenu-v6` | 7 | 0.2s |  |
| 24 | `Error-v5` | 28 | 0.7s |  |
| 25 | `Error-v6` | 31 | 0.7s |  |
| 26 | `Error-v7` | 31 | 0.3s |  |
| 27 | `Error-v8` | 31 | 0.2s |  |
| 28 | `ExternalInterface-v5` | 7 | 0.7s |  |
| 29 | `Key-v5` | 51 | 0.6s |  |
| 30 | `Key-v6` | 55 | 0.6s |  |
| 31 | `Key-v7` | 55 | 0.2s |  |
| 32 | `Key-v8` | 55 | 0.2s |  |
| 33 | `LoadVars-v5` | 8 | 0.6s |  |
| 34 | `LocalConnection-v5` | 7 | 0.7s |  |
| 35 | `LocalConnection-v6` | 58 | 0.7s |  |
| 36 | `LocalConnection-v7` | 58 | 0.3s |  |
| 37 | `LocalConnection-v8` | 58 | 0.2s |  |
| 38 | `Matrix-v5` | 7 | 0.6s |  |
| 39 | `Microphone-v5` | 6 | 0.7s |  |
| 40 | `Mouse-v5` | 13 | 0.7s |  |
| 41 | `Mouse-v6` | 21 | 0.7s |  |
| 42 | `Mouse-v7` | 21 | 0.3s |  |
| 43 | `Mouse-v8` | 21 | 0.2s |  |
| 44 | `MovieClipLoader-v5` | 6 | 0.7s |  |
| 45 | `MovieClipLoader-v6` | 6 | 0.8s |  |
| 46 | `NetConnection-v5` | 7 | 0.7s |  |
| 47 | `NetStream-v5` | 6 | 0.7s |  |
| 48 | `NetStream-v6` | 80 | 0.7s |  |
| 49 | `NetStream-v7` | 80 | 3.5s |  |
| 50 | `NetStream-v8` | 80 | 1.3s |  |
| 51 | `Number-v6` | 239 | 8.6s |  |
| 52 | `Number-v7` | 237 | 8.7s |  |
| 53 | `Number-v8` | 237 | 1.4s |  |
| 54 | `Point-v5` | 7 | 0.7s |  |
| 55 | `Point-v6` | 7 | 0.2s |  |
| 56 | `Point-v7` | 7 | 0.3s |  |
| 57 | `Random-v5` | 30 | 0.8s |  |
| 58 | `Random-v6` | 30 | 0.2s |  |
| 59 | `Random-v7` | 30 | 0.8s |  |
| 60 | `Random-v8` | 30 | 0.3s |  |
| 61 | `Rectangle-v5` | 7 | 0.7s |  |
| 62 | `Rectangle-v6` | 7 | 0.2s |  |
| 63 | `Rectangle-v7` | 7 | 0.3s |  |
| 64 | `Selection-v5` | 21 | 0.6s |  |
| 65 | `Stage-v5` | 38 | 0.7s |  |
| 66 | `System-v5` | 67 | 0.7s |  |
| 67 | `System-v6` | 100 | 0.7s |  |
| 68 | `System-v7` | 101 | 0.7s |  |
| 69 | `System-v8` | 101 | 0.3s |  |
| 70 | `TextFieldHTML-v5` | 6 | 0.7s |  |
| 71 | `TextFormat-v5` | 128 | 0.7s |  |
| 72 | `TextFormat-v6` | 128 | 0.2s |  |
| 73 | `TextSnapshot-v5` | 7 | 0.7s |  |
| 74 | `TextSnapshot-v6` | 173 | 0.7s |  |
| 75 | `TextSnapshot-v7` | 173 | 0.3s |  |
| 76 | `TextSnapshot-v8` | 173 | 0.3s |  |
| 77 | `Transform-v5` | 7 | 0.7s |  |
| 78 | `Transform-v6` | 7 | 0.8s |  |
| 79 | `Transform-v7` | 7 | 0.3s |  |
| 80 | `Try-v5` | 20 | 0.7s |  |
| 81 | `Try-v6` | 20 | 0.2s |  |
| 82 | `Try-v7` | 20 | 0.3s |  |
| 83 | `Try-v8` | 20 | 0.2s |  |
| 84 | `Video-v5` | 7 | 17.9s |  |
| 85 | `Video-v6` | 85 | 3.3s |  |
| 86 | `Video-v7` | 85 | 2.9s |  |
| 87 | `Video-v8` | 85 | 1.3s |  |
| 88 | `XMLSocket-v5` | 35 | 2.4s |  |
| 89 | `XMLSocket-v6` | 35 | 2.4s |  |
| 90 | `XMLSocket-v7` | 35 | 0.7s |  |
| 91 | `XMLSocket-v8` | 35 | 0.3s |  |
| 92 | `argstest-v5` | 4 | 0.7s |  |
| 93 | `case-v5` | 39 | 0.7s |  |
| 94 | `delete-v5` | 60 | 2.8s |  |
| 95 | `delete-v6` | 60 | 2.3s |  |
| 96 | `delete-v7` | 60 | 2.4s |  |
| 97 | `delete-v8` | 60 | 1.4s |  |
| 98 | `enumerate-v5` | 6 | 0.8s |  |
| 99 | `enumerate-v6` | 49 | 0.7s |  |
| 100 | `enumerate-v7` | 49 | 0.3s |  |
| 101 | `enumerate-v8` | 49 | 0.3s |  |
| 102 | `flash-v5` | 10 | 0.7s |  |
| 103 | `flash-v6` | 10 | 0.7s |  |
| 104 | `flash-v7` | 10 | 0.7s |  |
| 105 | `swap-v5` | 7 | 0.7s |  |
| 106 | `swap-v6` | 7 | 0.2s |  |
| 107 | `swap-v7` | 7 | 0.3s |  |
| 108 | `swap-v8` | 7 | 0.2s |  |
| 109 | `targetPath-v5` | 12 | 0.7s |  |

## Ruffle-Matched Tests

**43 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 0.7s |  |
| 2 | `ASnative-v6` | 40 | 40 | 0.7s |  |
| 3 | `ASnative-v7` | 40 | 40 | 0.2s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.2s |  |
| 5 | `BitmapData-v8` | 8 | 13 | 0.9s |  |
| 6 | `Camera-v6` | 57 | 57 | 0.8s |  |
| 7 | `Camera-v7` | 57 | 57 | 0.3s |  |
| 8 | `Camera-v8` | 57 | 57 | 0.3s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 0.7s |  |
| 10 | `Inheritance-v5` | 1 | 17 | 0.7s |  |
| 11 | `Inheritance-v6` | 9 | 16 | 0.7s |  |
| 12 | `Inheritance-v7` | 5 | 10 | 0.7s |  |
| 13 | `Inheritance-v8` | 5 | 10 | 0.3s |  |
| 14 | `Math-v5` | 5 | 5 | 0.7s |  |
| 15 | `Math-v6` | 5 | 5 | 0.2s |  |
| 16 | `Math-v7` | 5 | 5 | 0.7s |  |
| 17 | `Math-v8` | 5 | 5 | 0.2s |  |
| 18 | `Matrix-v6` | 29 | 71 | 0.7s |  |
| 19 | `Matrix-v7` | 28 | 70 | 0.7s |  |
| 20 | `Matrix-v8` | 28 | 70 | 0.3s |  |
| 21 | `Microphone-v6` | 31 | 31 | 0.7s |  |
| 22 | `Microphone-v7` | 31 | 31 | 0.3s |  |
| 23 | `Microphone-v8` | 31 | 31 | 0.3s |  |
| 24 | `MovieClipLoader-v7` | 118 | 118 | 0.7s |  |
| 25 | `MovieClipLoader-v8` | 118 | 118 | 0.3s |  |
| 26 | `Point-v8` | 3 | 20 | 0.7s |  |
| 27 | `Rectangle-v8` | 21 | 21 | 0.7s |  |
| 28 | `Sound-v5` | 27 | 27 | 0.7s |  |
| 29 | `Sound-v6` | 30 | 51 | 0.7s |  |
| 30 | `Sound-v7` | 28 | 51 | 0.8s |  |
| 31 | `Sound-v8` | 28 | 51 | 0.4s |  |
| 32 | `TextField-v5` | 3 | 3 | 0.7s |  |
| 33 | `case-v7` | 54 | 54 | 3.2s |  |
| 34 | `case-v8` | 54 | 54 | 1.3s |  |
| 35 | `ops-v8` | 7 | 11 | 0.7s |  |
| 36 | `targetPath-v6` | 17 | 17 | 0.7s |  |
| 37 | `targetPath-v7` | 17 | 17 | 0.3s |  |
| 38 | `targetPath-v8` | 17 | 17 | 0.2s |  |
| 39 | `toString_valueOf-v5` | 34 | 34 | 0.7s |  |
| 40 | `toString_valueOf-v6` | 5 | 5 | 0.7s |  |
| 41 | `toString_valueOf-v7` | 5 | 5 | 0.8s |  |
| 42 | `toString_valueOf-v8` | 5 | 5 | 0.3s |  |
| 43 | `with-v5` | 42 | 42 | 0.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**32 tests** within reach

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
| 25 | `String-v6` | 69.8% | 263 | 377 | 114 |  |
| 26 | `String-v7` | 69.0% | 260 | 377 | 117 |  |
| 27 | `String-v8` | 69.0% | 260 | 377 | 117 |  |
| 28 | `String-v5` | 67.9% | 243 | 358 | 115 |  |
| 29 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 30 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 31 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 32 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**38 tests** with output mismatch, sorted by match rate (best first)

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
| 25 | `String-v6` | 69.8% | 263/377 | 377 | 377 |  |
| 26 | `String-v7` | 69.0% | 260/377 | 377 | 377 |  |
| 27 | `String-v8` | 69.0% | 260/377 | 377 | 377 |  |
| 28 | `String-v5` | 67.9% | 243/358 | 358 | 358 |  |
| 29 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 30 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 31 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 32 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 33 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 34 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 35 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 36 | `with-v6` | 19.3% | 23/119 | 119 | 107 |  |
| 37 | `with-v7` | 19.3% | 23/119 | 119 | 107 |  |
| 38 | `with-v8` | 19.3% | 23/119 | 119 | 107 |  |
