# Ruffle Test Results (Filtered)

**Date**: 2026-04-14 19:00 UTC

**Git SHA**: `0eddf89639`

**Run Duration**: 71m 47s

**Filtered**: 0 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **98** (51.6%) |
| Ruffle-matched | 21 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **119** (62.6%) |
| Failing | 71 |
| Total expected lines | 16957 |
| Matching lines | 13080 (77.1%) |
| Mismatched lines | 3877 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 71 | 100.0% |

## Passing Tests

**98 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 20.2s |  |
| 2 | `Accessibility-v6` | 19 | 20.3s |  |
| 3 | `Accessibility-v7` | 19 | 20.3s |  |
| 4 | `Accessibility-v8` | 19 | 20.3s |  |
| 5 | `AsBroadcaster-v5` | 11 | 20.1s |  |
| 6 | `BitmapData-v5` | 7 | 20.0s |  |
| 7 | `BitmapData-v6` | 7 | 20.8s |  |
| 8 | `BitmapData-v7` | 7 | 20.3s |  |
| 9 | `Boolean-v5` | 38 | 21.0s |  |
| 10 | `Boolean-v6` | 38 | 21.0s |  |
| 11 | `Boolean-v7` | 38 | 21.1s |  |
| 12 | `Boolean-v8` | 38 | 21.1s |  |
| 13 | `Camera-v5` | 7 | 20.4s |  |
| 14 | `Color-v5` | 140 | 23.3s |  |
| 15 | `Color-v6` | 171 | 24.5s |  |
| 16 | `Color-v7` | 161 | 24.1s |  |
| 17 | `Color-v8` | 161 | 24.3s |  |
| 18 | `ColorTransform-v5` | 7 | 20.0s |  |
| 19 | `ColorTransform-v6` | 7 | 19.9s |  |
| 20 | `ColorTransform-v7` | 7 | 19.9s |  |
| 21 | `ColorTransform-v8` | 55 | 20.7s |  |
| 22 | `ContextMenu-v5` | 7 | 19.8s |  |
| 23 | `ContextMenu-v6` | 7 | 19.5s |  |
| 24 | `Error-v5` | 28 | 19.9s |  |
| 25 | `Error-v6` | 31 | 20.0s |  |
| 26 | `Error-v7` | 31 | 20.1s |  |
| 27 | `Error-v8` | 31 | 20.0s |  |
| 28 | `ExternalInterface-v5` | 7 | 19.6s |  |
| 29 | `Key-v5` | 51 | 20.4s |  |
| 30 | `Key-v6` | 55 | 20.4s |  |
| 31 | `Key-v7` | 55 | 20.4s |  |
| 32 | `Key-v8` | 55 | 20.4s |  |
| 33 | `LoadVars-v5` | 8 | 20.0s |  |
| 34 | `LocalConnection-v5` | 7 | 22.0s |  |
| 35 | `LocalConnection-v6` | 58 | 23.4s |  |
| 36 | `LocalConnection-v7` | 58 | 23.6s |  |
| 37 | `LocalConnection-v8` | 58 | 23.8s |  |
| 38 | `Matrix-v5` | 7 | 20.0s |  |
| 39 | `Microphone-v5` | 6 | 19.5s |  |
| 40 | `Mouse-v5` | 13 | 21.6s |  |
| 41 | `Mouse-v6` | 21 | 21.5s |  |
| 42 | `Mouse-v7` | 21 | 21.6s |  |
| 43 | `Mouse-v8` | 21 | 21.0s |  |
| 44 | `MovieClipLoader-v5` | 6 | 20.7s |  |
| 45 | `MovieClipLoader-v6` | 6 | 21.5s |  |
| 46 | `NetConnection-v5` | 7 | 20.6s |  |
| 47 | `NetStream-v5` | 6 | 20.4s |  |
| 48 | `NetStream-v6` | 80 | 21.9s |  |
| 49 | `NetStream-v7` | 80 | 18.3s |  |
| 50 | `NetStream-v8` | 80 | 18.5s |  |
| 51 | `Point-v5` | 7 | 20.4s |  |
| 52 | `Point-v6` | 7 | 20.3s |  |
| 53 | `Point-v7` | 7 | 20.1s |  |
| 54 | `Random-v5` | 30 | 20.6s |  |
| 55 | `Random-v6` | 30 | 21.0s |  |
| 56 | `Random-v7` | 30 | 20.1s |  |
| 57 | `Random-v8` | 30 | 20.1s |  |
| 58 | `Rectangle-v5` | 7 | 19.6s |  |
| 59 | `Rectangle-v6` | 7 | 19.6s |  |
| 60 | `Rectangle-v7` | 7 | 19.6s |  |
| 61 | `Selection-v5` | 21 | 20.0s |  |
| 62 | `Stage-v5` | 38 | 20.6s |  |
| 63 | `TextFieldHTML-v5` | 6 | 19.4s |  |
| 64 | `TextSnapshot-v5` | 7 | 19.3s |  |
| 65 | `TextSnapshot-v6` | 173 | 24.5s |  |
| 66 | `TextSnapshot-v7` | 173 | 24.9s |  |
| 67 | `TextSnapshot-v8` | 173 | 25.1s |  |
| 68 | `Transform-v5` | 7 | 19.3s |  |
| 69 | `Try-v5` | 20 | 20.8s |  |
| 70 | `Try-v6` | 20 | 20.9s |  |
| 71 | `Try-v7` | 20 | 20.8s |  |
| 72 | `Try-v8` | 20 | 20.9s |  |
| 73 | `Video-v5` | 7 | 22.7s |  |
| 74 | `Video-v6` | 85 | 24.8s |  |
| 75 | `Video-v7` | 85 | 24.8s |  |
| 76 | `Video-v8` | 85 | 24.9s |  |
| 77 | `XMLSocket-v5` | 35 | 23.1s |  |
| 78 | `XMLSocket-v6` | 35 | 23.2s |  |
| 79 | `XMLSocket-v7` | 35 | 20.5s |  |
| 80 | `XMLSocket-v8` | 35 | 20.6s |  |
| 81 | `argstest-v5` | 4 | 20.0s |  |
| 82 | `case-v5` | 39 | 20.8s |  |
| 83 | `delete-v5` | 60 | 21.0s |  |
| 84 | `delete-v6` | 60 | 21.0s |  |
| 85 | `delete-v7` | 60 | 21.0s |  |
| 86 | `delete-v8` | 60 | 21.0s |  |
| 87 | `enumerate-v5` | 6 | 20.4s |  |
| 88 | `enumerate-v6` | 49 | 21.5s |  |
| 89 | `enumerate-v7` | 49 | 22.0s |  |
| 90 | `enumerate-v8` | 49 | 22.0s |  |
| 91 | `flash-v5` | 10 | 20.8s |  |
| 92 | `flash-v6` | 10 | 20.9s |  |
| 93 | `flash-v7` | 10 | 19.4s |  |
| 94 | `swap-v5` | 7 | 19.3s |  |
| 95 | `swap-v6` | 7 | 19.4s |  |
| 96 | `swap-v7` | 7 | 19.3s |  |
| 97 | `swap-v8` | 7 | 19.2s |  |
| 98 | `targetPath-v5` | 12 | 20.6s |  |

## Ruffle-Matched Tests

**21 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `Camera-v6` | 57 | 57 | 22.0s |  |
| 2 | `Camera-v7` | 57 | 57 | 22.0s |  |
| 3 | `Camera-v8` | 57 | 57 | 22.1s |  |
| 4 | `Inheritance-v5` | 1 | 17 | 21.9s |  |
| 5 | `Inheritance-v6` | 9 | 16 | 23.9s |  |
| 6 | `Inheritance-v7` | 5 | 10 | 24.0s |  |
| 7 | `Inheritance-v8` | 5 | 10 | 24.2s |  |
| 8 | `Math-v5` | 5 | 5 | 30.8s |  |
| 9 | `Math-v6` | 5 | 5 | 30.8s |  |
| 10 | `Math-v7` | 5 | 5 | 32.3s |  |
| 11 | `Math-v8` | 5 | 5 | 32.1s |  |
| 12 | `Microphone-v6` | 31 | 31 | 20.9s |  |
| 13 | `Microphone-v7` | 31 | 31 | 22.0s |  |
| 14 | `Microphone-v8` | 31 | 31 | 21.1s |  |
| 15 | `Sound-v5` | 23 | 27 | 24.4s |  |
| 16 | `case-v7` | 54 | 54 | 21.3s |  |
| 17 | `case-v8` | 54 | 54 | 21.4s |  |
| 18 | `ops-v8` | 7 | 11 | 26.0s |  |
| 19 | `targetPath-v6` | 17 | 17 | 20.1s |  |
| 20 | `targetPath-v7` | 17 | 17 | 20.1s |  |
| 21 | `targetPath-v8` | 17 | 17 | 20.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**53 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Point-v8` | 95.9% | 185 | 193 | 8 |  |
| 2 | `ExternalInterface-v8` | 95.8% | 113 | 118 | 5 |  |
| 3 | `Number-v7` | 94.1% | 223 | 237 | 14 |  |
| 4 | `Number-v8` | 94.1% | 223 | 237 | 14 |  |
| 5 | `Number-v6` | 92.5% | 221 | 239 | 18 |  |
| 6 | `Selection-v6` | 91.2% | 114 | 125 | 11 |  |
| 7 | `Selection-v7` | 91.2% | 114 | 125 | 11 |  |
| 8 | `Selection-v8` | 91.2% | 114 | 125 | 11 |  |
| 9 | `Number-v5` | 90.2% | 220 | 244 | 24 |  |
| 10 | `toString_valueOf-v6` | 87.7% | 136 | 155 | 19 |  |
| 11 | `toString_valueOf-v7` | 87.7% | 136 | 155 | 19 |  |
| 12 | `toString_valueOf-v8` | 87.7% | 136 | 155 | 19 |  |
| 13 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 14 | `TextFieldHTML-v7` | 86.5% | 32 | 37 | 5 |  |
| 15 | `TextFieldHTML-v8` | 86.5% | 32 | 37 | 5 |  |
| 16 | `Rectangle-v8` | 84.3% | 140 | 166 | 26 |  |
| 17 | `System-v7` | 83.2% | 84 | 101 | 17 |  |
| 18 | `System-v8` | 83.2% | 84 | 101 | 17 |  |
| 19 | `System-v6` | 83.0% | 83 | 100 | 17 |  |
| 20 | `Matrix-v8` | 82.7% | 139 | 168 | 29 |  |
| 21 | `array-v5` | 82.0% | 459 | 560 | 101 |  |
| 22 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 23 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 24 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 25 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 26 | `TextFormat-v5` | 78.9% | 101 | 128 | 27 |  |
| 27 | `TextFormat-v6` | 78.9% | 101 | 128 | 27 |  |
| 28 | `Global-v8` | 78.7% | 133 | 169 | 36 |  |
| 29 | `Global-v7` | 76.4% | 139 | 182 | 43 |  |
| 30 | `System-v5` | 76.1% | 51 | 67 | 16 |  |
| 31 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 32 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 33 | `Global-v6` | 73.3% | 154 | 210 | 56 |  |
| 34 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 35 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 36 | `String-v6` | 69.5% | 262 | 377 | 115 |  |
| 37 | `MovieClip-v5` | 68.9% | 250 | 363 | 113 |  |
| 38 | `String-v7` | 68.7% | 259 | 377 | 118 |  |
| 39 | `String-v8` | 68.7% | 259 | 377 | 118 |  |
| 40 | `String-v5` | 67.6% | 242 | 358 | 116 |  |
| 41 | `TextField-v5` | 66.7% | 8 | 12 | 4 |  |
| 42 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 43 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 44 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 45 | `toString_valueOf-v5` | 62.8% | 86 | 137 | 51 |  |
| 46 | `TextFormat-v7` | 62.6% | 109 | 174 | 65 |  |
| 47 | `BitmapData-v8` | 62.1% | 259 | 417 | 158 |  |
| 48 | `Transform-v6` | 57.1% | 4 | 7 | 3 |  |
| 49 | `Transform-v7` | 57.1% | 4 | 7 | 3 |  |
| 50 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 51 | `ExternalInterface-v6` | 50.9% | 28 | 55 | 27 |  |
| 52 | `ExternalInterface-v7` | 50.9% | 28 | 55 | 27 |  |
| 53 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**71 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Point-v8` | 95.9% | 185/193 | 193 | 193 |  |
| 2 | `ExternalInterface-v8` | 95.8% | 113/118 | 118 | 118 |  |
| 3 | `Number-v7` | 94.1% | 223/237 | 237 | 237 |  |
| 4 | `Number-v8` | 94.1% | 223/237 | 237 | 237 |  |
| 5 | `Number-v6` | 92.5% | 221/239 | 239 | 239 |  |
| 6 | `Selection-v6` | 91.2% | 114/125 | 125 | 125 |  |
| 7 | `Selection-v7` | 91.2% | 114/125 | 125 | 125 |  |
| 8 | `Selection-v8` | 91.2% | 114/125 | 125 | 125 |  |
| 9 | `Number-v5` | 90.2% | 220/244 | 244 | 244 |  |
| 10 | `toString_valueOf-v6` | 87.7% | 136/155 | 155 | 155 |  |
| 11 | `toString_valueOf-v7` | 87.7% | 136/155 | 155 | 155 |  |
| 12 | `toString_valueOf-v8` | 87.7% | 136/155 | 155 | 155 |  |
| 13 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 14 | `TextFieldHTML-v7` | 86.5% | 32/37 | 37 | 37 |  |
| 15 | `TextFieldHTML-v8` | 86.5% | 32/37 | 37 | 37 |  |
| 16 | `Rectangle-v8` | 84.3% | 140/166 | 166 | 166 |  |
| 17 | `System-v7` | 83.2% | 84/101 | 101 | 101 |  |
| 18 | `System-v8` | 83.2% | 84/101 | 101 | 101 |  |
| 19 | `System-v6` | 83.0% | 83/100 | 100 | 100 |  |
| 20 | `Matrix-v8` | 82.7% | 139/168 | 168 | 168 |  |
| 21 | `array-v5` | 82.0% | 459/560 | 560 | 560 |  |
| 22 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 23 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 24 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 25 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 26 | `TextFormat-v5` | 78.9% | 101/128 | 128 | 128 |  |
| 27 | `TextFormat-v6` | 78.9% | 101/128 | 128 | 128 |  |
| 28 | `Global-v8` | 78.7% | 133/169 | 168 | 169 |  |
| 29 | `Global-v7` | 76.4% | 139/182 | 181 | 182 |  |
| 30 | `System-v5` | 76.1% | 51/67 | 67 | 67 |  |
| 31 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 32 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 33 | `Global-v6` | 73.3% | 154/210 | 209 | 210 |  |
| 34 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 35 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 36 | `String-v6` | 69.5% | 262/377 | 377 | 377 |  |
| 37 | `MovieClip-v5` | 68.9% | 250/363 | 350 | 363 |  |
| 38 | `String-v7` | 68.7% | 259/377 | 377 | 377 |  |
| 39 | `String-v8` | 68.7% | 259/377 | 377 | 377 |  |
| 40 | `String-v5` | 67.6% | 242/358 | 358 | 358 |  |
| 41 | `TextField-v5` | 66.7% | 8/12 | 12 | 12 |  |
| 42 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 43 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 44 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 45 | `toString_valueOf-v5` | 62.8% | 86/137 | 137 | 137 |  |
| 46 | `TextFormat-v7` | 62.6% | 109/174 | 174 | 174 |  |
| 47 | `BitmapData-v8` | 62.1% | 259/417 | 417 | 417 |  |
| 48 | `Transform-v6` | 57.1% | 4/7 | 7 | 7 |  |
| 49 | `Transform-v7` | 57.1% | 4/7 | 7 | 7 |  |
| 50 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 51 | `ExternalInterface-v6` | 50.9% | 28/55 | 55 | 55 |  |
| 52 | `ExternalInterface-v7` | 50.9% | 28/55 | 55 | 55 |  |
| 53 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 54 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 55 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 56 | `LoadVars-v6` | 44.1% | 67/152 | 117 | 152 |  |
| 57 | `LoadVars-v7` | 44.1% | 67/152 | 117 | 152 |  |
| 58 | `LoadVars-v8` | 44.1% | 67/152 | 117 | 152 |  |
| 59 | `with-v5` | 30.0% | 21/70 | 70 | 49 |  |
| 60 | `MovieClipLoader-v7` | 27.9% | 46/165 | 47 | 165 |  |
| 61 | `MovieClipLoader-v8` | 27.9% | 46/165 | 47 | 165 |  |
| 62 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 63 | `ASnative-v5` | 24.3% | 26/107 | 107 | 107 |  |
| 64 | `Matrix-v6` | 23.2% | 39/168 | 168 | 168 |  |
| 65 | `ASnative-v6` | 21.8% | 24/110 | 110 | 110 |  |
| 66 | `ASnative-v7` | 21.8% | 24/110 | 110 | 110 |  |
| 67 | `ASnative-v8` | 21.8% | 24/110 | 110 | 110 |  |
| 68 | `Matrix-v7` | 20.8% | 35/168 | 168 | 168 |  |
| 69 | `with-v6` | 19.3% | 23/119 | 119 | 107 |  |
| 70 | `with-v7` | 19.3% | 23/119 | 119 | 107 |  |
| 71 | `with-v8` | 19.3% | 23/119 | 119 | 107 |  |
