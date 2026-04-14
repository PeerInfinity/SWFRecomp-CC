# Ruffle Test Results (Filtered)

**Date**: 2026-04-14 23:50 UTC

**Git SHA**: `ed7f770a89`

**Run Duration**: 70m 17s

**Filtered**: 0 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **98** (51.6%) |
| Ruffle-matched | 22 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **120** (63.2%) |
| Failing | 70 |
| Total expected lines | 16957 |
| Matching lines | 13122 (77.4%) |
| Mismatched lines | 3835 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 70 | 100.0% |

## Passing Tests

**98 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 20.1s |  |
| 2 | `Accessibility-v6` | 19 | 20.1s |  |
| 3 | `Accessibility-v7` | 19 | 20.3s |  |
| 4 | `Accessibility-v8` | 19 | 19.9s |  |
| 5 | `AsBroadcaster-v5` | 11 | 19.8s |  |
| 6 | `BitmapData-v5` | 7 | 19.7s |  |
| 7 | `BitmapData-v6` | 7 | 19.4s |  |
| 8 | `BitmapData-v7` | 7 | 19.5s |  |
| 9 | `Boolean-v5` | 38 | 20.0s |  |
| 10 | `Boolean-v6` | 38 | 20.0s |  |
| 11 | `Boolean-v7` | 38 | 20.1s |  |
| 12 | `Boolean-v8` | 38 | 20.1s |  |
| 13 | `Camera-v5` | 7 | 19.5s |  |
| 14 | `Color-v5` | 140 | 24.1s |  |
| 15 | `Color-v6` | 171 | 25.3s |  |
| 16 | `Color-v7` | 161 | 24.8s |  |
| 17 | `Color-v8` | 161 | 24.7s |  |
| 18 | `ColorTransform-v5` | 7 | 19.6s |  |
| 19 | `ColorTransform-v6` | 7 | 19.5s |  |
| 20 | `ColorTransform-v7` | 7 | 19.9s |  |
| 21 | `ColorTransform-v8` | 55 | 20.9s |  |
| 22 | `ContextMenu-v5` | 7 | 19.8s |  |
| 23 | `ContextMenu-v6` | 7 | 19.7s |  |
| 24 | `Error-v5` | 28 | 19.7s |  |
| 25 | `Error-v6` | 31 | 19.7s |  |
| 26 | `Error-v7` | 31 | 19.8s |  |
| 27 | `Error-v8` | 31 | 19.8s |  |
| 28 | `ExternalInterface-v5` | 7 | 19.3s |  |
| 29 | `Key-v5` | 51 | 21.0s |  |
| 30 | `Key-v6` | 55 | 21.0s |  |
| 31 | `Key-v7` | 55 | 21.2s |  |
| 32 | `Key-v8` | 55 | 21.0s |  |
| 33 | `LoadVars-v5` | 8 | 20.2s |  |
| 34 | `LocalConnection-v5` | 7 | 19.5s |  |
| 35 | `LocalConnection-v6` | 58 | 20.6s |  |
| 36 | `LocalConnection-v7` | 58 | 20.7s |  |
| 37 | `LocalConnection-v8` | 58 | 20.7s |  |
| 38 | `Matrix-v5` | 7 | 19.5s |  |
| 39 | `Microphone-v5` | 6 | 20.3s |  |
| 40 | `Mouse-v5` | 13 | 20.2s |  |
| 41 | `Mouse-v6` | 21 | 20.2s |  |
| 42 | `Mouse-v7` | 21 | 20.3s |  |
| 43 | `Mouse-v8` | 21 | 20.3s |  |
| 44 | `MovieClipLoader-v5` | 6 | 20.4s |  |
| 45 | `MovieClipLoader-v6` | 6 | 19.6s |  |
| 46 | `NetConnection-v5` | 7 | 19.4s |  |
| 47 | `NetStream-v5` | 6 | 19.4s |  |
| 48 | `NetStream-v6` | 80 | 21.0s |  |
| 49 | `NetStream-v7` | 80 | 20.8s |  |
| 50 | `NetStream-v8` | 80 | 20.9s |  |
| 51 | `Point-v5` | 7 | 19.3s |  |
| 52 | `Point-v6` | 7 | 19.3s |  |
| 53 | `Point-v7` | 7 | 19.3s |  |
| 54 | `Random-v5` | 30 | 19.8s |  |
| 55 | `Random-v6` | 30 | 19.8s |  |
| 56 | `Random-v7` | 30 | 20.1s |  |
| 57 | `Random-v8` | 30 | 20.1s |  |
| 58 | `Rectangle-v5` | 7 | 19.6s |  |
| 59 | `Rectangle-v6` | 7 | 19.6s |  |
| 60 | `Rectangle-v7` | 7 | 19.6s |  |
| 61 | `Selection-v5` | 21 | 20.6s |  |
| 62 | `Stage-v5` | 38 | 20.1s |  |
| 63 | `TextFieldHTML-v5` | 6 | 20.0s |  |
| 64 | `TextSnapshot-v5` | 7 | 20.5s |  |
| 65 | `TextSnapshot-v6` | 173 | 25.8s |  |
| 66 | `TextSnapshot-v7` | 173 | 25.6s |  |
| 67 | `TextSnapshot-v8` | 173 | 25.8s |  |
| 68 | `Transform-v5` | 7 | 20.5s |  |
| 69 | `Try-v5` | 20 | 21.0s |  |
| 70 | `Try-v6` | 20 | 21.0s |  |
| 71 | `Try-v7` | 20 | 21.0s |  |
| 72 | `Try-v8` | 20 | 21.1s |  |
| 73 | `Video-v5` | 7 | 20.1s |  |
| 74 | `Video-v6` | 85 | 22.2s |  |
| 75 | `Video-v7` | 85 | 21.3s |  |
| 76 | `Video-v8` | 85 | 21.4s |  |
| 77 | `XMLSocket-v5` | 35 | 20.2s |  |
| 78 | `XMLSocket-v6` | 35 | 20.4s |  |
| 79 | `XMLSocket-v7` | 35 | 21.4s |  |
| 80 | `XMLSocket-v8` | 35 | 21.2s |  |
| 81 | `argstest-v5` | 4 | 20.2s |  |
| 82 | `case-v5` | 39 | 21.5s |  |
| 83 | `delete-v5` | 60 | 20.8s |  |
| 84 | `delete-v6` | 60 | 20.8s |  |
| 85 | `delete-v7` | 60 | 21.0s |  |
| 86 | `delete-v8` | 60 | 20.9s |  |
| 87 | `enumerate-v5` | 6 | 19.6s |  |
| 88 | `enumerate-v6` | 49 | 20.6s |  |
| 89 | `enumerate-v7` | 49 | 20.6s |  |
| 90 | `enumerate-v8` | 49 | 20.6s |  |
| 91 | `flash-v5` | 10 | 19.7s |  |
| 92 | `flash-v6` | 10 | 19.8s |  |
| 93 | `flash-v7` | 10 | 21.2s |  |
| 94 | `swap-v5` | 7 | 21.0s |  |
| 95 | `swap-v6` | 7 | 21.1s |  |
| 96 | `swap-v7` | 7 | 21.0s |  |
| 97 | `swap-v8` | 7 | 21.0s |  |
| 98 | `targetPath-v5` | 12 | 20.3s |  |

## Ruffle-Matched Tests

**22 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `Camera-v6` | 57 | 57 | 22.1s |  |
| 2 | `Camera-v7` | 57 | 57 | 22.2s |  |
| 3 | `Camera-v8` | 57 | 57 | 22.4s |  |
| 4 | `Inheritance-v5` | 1 | 17 | 18.2s |  |
| 5 | `Inheritance-v6` | 9 | 16 | 20.3s |  |
| 6 | `Inheritance-v7` | 5 | 10 | 20.0s |  |
| 7 | `Inheritance-v8` | 5 | 10 | 19.9s |  |
| 8 | `Math-v5` | 5 | 5 | 30.6s |  |
| 9 | `Math-v6` | 5 | 5 | 30.4s |  |
| 10 | `Math-v7` | 5 | 5 | 30.8s |  |
| 11 | `Math-v8` | 5 | 5 | 31.1s |  |
| 12 | `Microphone-v6` | 31 | 31 | 21.7s |  |
| 13 | `Microphone-v7` | 31 | 31 | 21.8s |  |
| 14 | `Microphone-v8` | 31 | 31 | 21.5s |  |
| 15 | `Point-v8` | 3 | 20 | 24.8s |  |
| 16 | `Sound-v5` | 23 | 27 | 23.7s |  |
| 17 | `case-v7` | 54 | 54 | 21.2s |  |
| 18 | `case-v8` | 54 | 54 | 21.2s |  |
| 19 | `ops-v8` | 7 | 11 | 28.9s |  |
| 20 | `targetPath-v6` | 17 | 17 | 20.3s |  |
| 21 | `targetPath-v7` | 17 | 17 | 21.2s |  |
| 22 | `targetPath-v8` | 17 | 17 | 20.7s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**52 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `ExternalInterface-v8` | 95.8% | 113 | 118 | 5 |  |
| 2 | `Number-v7` | 95.4% | 226 | 237 | 11 |  |
| 3 | `Number-v8` | 95.4% | 226 | 237 | 11 |  |
| 4 | `Number-v6` | 93.7% | 224 | 239 | 15 |  |
| 5 | `Number-v5` | 91.4% | 223 | 244 | 21 |  |
| 6 | `Selection-v6` | 91.2% | 114 | 125 | 11 |  |
| 7 | `Selection-v7` | 91.2% | 114 | 125 | 11 |  |
| 8 | `Selection-v8` | 91.2% | 114 | 125 | 11 |  |
| 9 | `toString_valueOf-v6` | 90.3% | 140 | 155 | 15 |  |
| 10 | `toString_valueOf-v7` | 90.3% | 140 | 155 | 15 |  |
| 11 | `toString_valueOf-v8` | 90.3% | 140 | 155 | 15 |  |
| 12 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 13 | `TextFieldHTML-v7` | 86.5% | 32 | 37 | 5 |  |
| 14 | `TextFieldHTML-v8` | 86.5% | 32 | 37 | 5 |  |
| 15 | `System-v7` | 85.1% | 86 | 101 | 15 |  |
| 16 | `System-v8` | 85.1% | 86 | 101 | 15 |  |
| 17 | `System-v6` | 85.0% | 85 | 100 | 15 |  |
| 18 | `Rectangle-v8` | 84.3% | 140 | 166 | 26 |  |
| 19 | `Matrix-v8` | 82.7% | 139 | 168 | 29 |  |
| 20 | `array-v5` | 82.3% | 461 | 560 | 99 |  |
| 21 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 22 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 23 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 24 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 25 | `TextFormat-v5` | 78.9% | 101 | 128 | 27 |  |
| 26 | `TextFormat-v6` | 78.9% | 101 | 128 | 27 |  |
| 27 | `Global-v8` | 78.7% | 133 | 169 | 36 |  |
| 28 | `System-v5` | 77.6% | 52 | 67 | 15 |  |
| 29 | `Global-v7` | 76.4% | 139 | 182 | 43 |  |
| 30 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 31 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 32 | `Global-v6` | 73.3% | 154 | 210 | 56 |  |
| 33 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 34 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 35 | `String-v6` | 69.5% | 262 | 377 | 115 |  |
| 36 | `MovieClip-v5` | 68.9% | 250 | 363 | 113 |  |
| 37 | `String-v7` | 68.7% | 259 | 377 | 118 |  |
| 38 | `String-v8` | 68.7% | 259 | 377 | 118 |  |
| 39 | `String-v5` | 67.6% | 242 | 358 | 116 |  |
| 40 | `TextField-v5` | 66.7% | 8 | 12 | 4 |  |
| 41 | `toString_valueOf-v5` | 65.7% | 90 | 137 | 47 |  |
| 42 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 43 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 44 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 45 | `TextFormat-v7` | 62.6% | 109 | 174 | 65 |  |
| 46 | `BitmapData-v8` | 62.1% | 259 | 417 | 158 |  |
| 47 | `Transform-v6` | 57.1% | 4 | 7 | 3 |  |
| 48 | `Transform-v7` | 57.1% | 4 | 7 | 3 |  |
| 49 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 50 | `ExternalInterface-v6` | 50.9% | 28 | 55 | 27 |  |
| 51 | `ExternalInterface-v7` | 50.9% | 28 | 55 | 27 |  |
| 52 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**70 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `ExternalInterface-v8` | 95.8% | 113/118 | 118 | 118 |  |
| 2 | `Number-v7` | 95.4% | 226/237 | 237 | 237 |  |
| 3 | `Number-v8` | 95.4% | 226/237 | 237 | 237 |  |
| 4 | `Number-v6` | 93.7% | 224/239 | 239 | 239 |  |
| 5 | `Number-v5` | 91.4% | 223/244 | 244 | 244 |  |
| 6 | `Selection-v6` | 91.2% | 114/125 | 125 | 125 |  |
| 7 | `Selection-v7` | 91.2% | 114/125 | 125 | 125 |  |
| 8 | `Selection-v8` | 91.2% | 114/125 | 125 | 125 |  |
| 9 | `toString_valueOf-v6` | 90.3% | 140/155 | 155 | 155 |  |
| 10 | `toString_valueOf-v7` | 90.3% | 140/155 | 155 | 155 |  |
| 11 | `toString_valueOf-v8` | 90.3% | 140/155 | 155 | 155 |  |
| 12 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 13 | `TextFieldHTML-v7` | 86.5% | 32/37 | 37 | 37 |  |
| 14 | `TextFieldHTML-v8` | 86.5% | 32/37 | 37 | 37 |  |
| 15 | `System-v7` | 85.1% | 86/101 | 101 | 101 |  |
| 16 | `System-v8` | 85.1% | 86/101 | 101 | 101 |  |
| 17 | `System-v6` | 85.0% | 85/100 | 100 | 100 |  |
| 18 | `Rectangle-v8` | 84.3% | 140/166 | 166 | 166 |  |
| 19 | `Matrix-v8` | 82.7% | 139/168 | 168 | 168 |  |
| 20 | `array-v5` | 82.3% | 461/560 | 560 | 560 |  |
| 21 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 22 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 23 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 24 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 25 | `TextFormat-v5` | 78.9% | 101/128 | 128 | 128 |  |
| 26 | `TextFormat-v6` | 78.9% | 101/128 | 128 | 128 |  |
| 27 | `Global-v8` | 78.7% | 133/169 | 168 | 169 |  |
| 28 | `System-v5` | 77.6% | 52/67 | 67 | 67 |  |
| 29 | `Global-v7` | 76.4% | 139/182 | 181 | 182 |  |
| 30 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 31 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 32 | `Global-v6` | 73.3% | 154/210 | 209 | 210 |  |
| 33 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 34 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 35 | `String-v6` | 69.5% | 262/377 | 377 | 377 |  |
| 36 | `MovieClip-v5` | 68.9% | 250/363 | 350 | 363 |  |
| 37 | `String-v7` | 68.7% | 259/377 | 377 | 377 |  |
| 38 | `String-v8` | 68.7% | 259/377 | 377 | 377 |  |
| 39 | `String-v5` | 67.6% | 242/358 | 358 | 358 |  |
| 40 | `TextField-v5` | 66.7% | 8/12 | 12 | 12 |  |
| 41 | `toString_valueOf-v5` | 65.7% | 90/137 | 137 | 137 |  |
| 42 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 43 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 44 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 45 | `TextFormat-v7` | 62.6% | 109/174 | 174 | 174 |  |
| 46 | `BitmapData-v8` | 62.1% | 259/417 | 417 | 417 |  |
| 47 | `Transform-v6` | 57.1% | 4/7 | 7 | 7 |  |
| 48 | `Transform-v7` | 57.1% | 4/7 | 7 | 7 |  |
| 49 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 50 | `ExternalInterface-v6` | 50.9% | 28/55 | 55 | 55 |  |
| 51 | `ExternalInterface-v7` | 50.9% | 28/55 | 55 | 55 |  |
| 52 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 53 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 54 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 55 | `LoadVars-v6` | 44.1% | 67/152 | 117 | 152 |  |
| 56 | `LoadVars-v7` | 44.1% | 67/152 | 117 | 152 |  |
| 57 | `LoadVars-v8` | 44.1% | 67/152 | 117 | 152 |  |
| 58 | `with-v5` | 30.0% | 21/70 | 70 | 49 |  |
| 59 | `MovieClipLoader-v7` | 27.9% | 46/165 | 47 | 165 |  |
| 60 | `MovieClipLoader-v8` | 27.9% | 46/165 | 47 | 165 |  |
| 61 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 62 | `ASnative-v5` | 24.3% | 26/107 | 107 | 107 |  |
| 63 | `Matrix-v6` | 23.2% | 39/168 | 168 | 168 |  |
| 64 | `ASnative-v6` | 21.8% | 24/110 | 110 | 110 |  |
| 65 | `ASnative-v7` | 21.8% | 24/110 | 110 | 110 |  |
| 66 | `ASnative-v8` | 21.8% | 24/110 | 110 | 110 |  |
| 67 | `Matrix-v7` | 20.8% | 35/168 | 168 | 168 |  |
| 68 | `with-v6` | 19.3% | 23/119 | 119 | 107 |  |
| 69 | `with-v7` | 19.3% | 23/119 | 119 | 107 |  |
| 70 | `with-v8` | 19.3% | 23/119 | 119 | 107 |  |
