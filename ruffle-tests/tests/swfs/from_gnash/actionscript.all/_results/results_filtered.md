# Ruffle Test Results (Filtered)

**Date**: 2026-04-02 22:23 UTC

**Git SHA**: `2fd884d606`

**Run Duration**: 64m 45s

**Filtered**: 9 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 181 |
| Passing | **62** (34.3%) |
| Failing | 119 |
| Total expected lines | 15444 |
| Matching lines | 10826 (70.1%) |
| Mismatched lines | 4618 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 119 | 100.0% |

## Passing Tests

**62 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 18.4s |  |
| 2 | `Accessibility-v6` | 19 | 18.2s |  |
| 3 | `Accessibility-v7` | 19 | 18.1s |  |
| 4 | `Accessibility-v8` | 19 | 18.4s |  |
| 5 | `BitmapData-v5` | 7 | 18.0s |  |
| 6 | `BitmapData-v6` | 7 | 18.0s |  |
| 7 | `BitmapData-v7` | 7 | 18.5s |  |
| 8 | `Boolean-v5` | 38 | 18.9s |  |
| 9 | `Boolean-v6` | 38 | 18.9s |  |
| 10 | `Boolean-v7` | 38 | 18.0s |  |
| 11 | `Boolean-v8` | 38 | 18.3s |  |
| 12 | `Camera-v5` | 7 | 17.5s |  |
| 13 | `Color-v5` | 140 | 20.7s |  |
| 14 | `Color-v7` | 161 | 21.2s |  |
| 15 | `Color-v8` | 161 | 21.2s |  |
| 16 | `ColorTransform-v5` | 7 | 17.6s |  |
| 17 | `ColorTransform-v6` | 7 | 17.6s |  |
| 18 | `ColorTransform-v7` | 7 | 17.7s |  |
| 19 | `ContextMenu-v5` | 7 | 17.8s |  |
| 20 | `ContextMenu-v6` | 7 | 17.7s |  |
| 21 | `ExternalInterface-v5` | 7 | 17.9s |  |
| 22 | `LoadVars-v5` | 8 | 17.9s |  |
| 23 | `Matrix-v5` | 7 | 17.9s |  |
| 24 | `Microphone-v5` | 6 | 17.4s |  |
| 25 | `Mouse-v5` | 13 | 18.9s |  |
| 26 | `MovieClipLoader-v5` | 6 | 19.1s |  |
| 27 | `MovieClipLoader-v6` | 6 | 17.5s |  |
| 28 | `NetStream-v5` | 6 | 17.4s |  |
| 29 | `Point-v5` | 7 | 17.6s |  |
| 30 | `Point-v6` | 7 | 17.6s |  |
| 31 | `Point-v7` | 7 | 17.6s |  |
| 32 | `Random-v5` | 30 | 18.3s |  |
| 33 | `Random-v6` | 30 | 18.3s |  |
| 34 | `Random-v7` | 30 | 18.1s |  |
| 35 | `Random-v8` | 30 | 18.1s |  |
| 36 | `Rectangle-v5` | 7 | 17.7s |  |
| 37 | `Rectangle-v6` | 7 | 17.6s |  |
| 38 | `Rectangle-v7` | 7 | 17.6s |  |
| 39 | `Selection-v5` | 21 | 18.1s |  |
| 40 | `Stage-v5` | 38 | 18.4s |  |
| 41 | `TextFieldHTML-v5` | 6 | 17.7s |  |
| 42 | `TextSnapshot-v5` | 7 | 17.9s |  |
| 43 | `Transform-v5` | 7 | 18.0s |  |
| 44 | `Try-v5` | 20 | 18.1s |  |
| 45 | `Try-v6` | 20 | 18.3s |  |
| 46 | `Try-v7` | 20 | 18.3s |  |
| 47 | `Try-v8` | 20 | 18.3s |  |
| 48 | `Video-v6` | 85 | 21.0s |  |
| 49 | `Video-v7` | 85 | 20.9s |  |
| 50 | `Video-v8` | 85 | 21.1s |  |
| 51 | `XMLSocket-v5` | 35 | 19.3s |  |
| 52 | `XMLSocket-v6` | 35 | 19.2s |  |
| 53 | `XMLSocket-v7` | 35 | 17.9s |  |
| 54 | `XMLSocket-v8` | 35 | 18.0s |  |
| 55 | `argstest-v5` | 4 | 17.5s |  |
| 56 | `case-v5` | 39 | 18.1s |  |
| 57 | `enumerate-v5` | 6 | 19.3s |  |
| 58 | `swap-v5` | 7 | 17.5s |  |
| 59 | `swap-v6` | 7 | 17.4s |  |
| 60 | `swap-v7` | 7 | 17.5s |  |
| 61 | `swap-v8` | 7 | 17.6s |  |
| 62 | `targetPath-v5` | 12 | 17.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**88 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Inheritance-v8` | 97.3% | 177 | 182 | 5 |  |
| 2 | `Inheritance-v7` | 96.7% | 176 | 182 | 6 |  |
| 3 | `Color-v6` | 96.5% | 165 | 171 | 6 |  |
| 4 | `ExternalInterface-v8` | 95.8% | 113 | 118 | 5 |  |
| 5 | `NetStream-v6` | 95.0% | 76 | 80 | 4 |  |
| 6 | `NetStream-v7` | 95.0% | 76 | 80 | 4 |  |
| 7 | `NetStream-v8` | 95.0% | 76 | 80 | 4 |  |
| 8 | `Key-v6` | 94.5% | 52 | 55 | 3 |  |
| 9 | `Key-v7` | 94.5% | 52 | 55 | 3 |  |
| 10 | `Key-v8` | 94.5% | 52 | 55 | 3 |  |
| 11 | `Key-v5` | 92.2% | 47 | 51 | 4 |  |
| 12 | `Inheritance-v6` | 90.1% | 164 | 182 | 18 |  |
| 13 | `Selection-v7` | 88.0% | 110 | 125 | 15 |  |
| 14 | `Selection-v8` | 88.0% | 110 | 125 | 15 |  |
| 15 | `Point-v8` | 87.6% | 169 | 193 | 24 |  |
| 16 | `Selection-v6` | 87.2% | 109 | 125 | 16 |  |
| 17 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 18 | `TextFieldHTML-v7` | 86.5% | 32 | 37 | 5 |  |
| 19 | `TextFieldHTML-v8` | 86.5% | 32 | 37 | 5 |  |
| 20 | `toString_valueOf-v7` | 85.8% | 133 | 155 | 22 |  |
| 21 | `toString_valueOf-v8` | 85.8% | 133 | 155 | 22 |  |
| 22 | `Mouse-v6` | 85.7% | 18 | 21 | 3 |  |
| 23 | `Mouse-v7` | 85.7% | 18 | 21 | 3 |  |
| 24 | `Mouse-v8` | 85.7% | 18 | 21 | 3 |  |
| 25 | `toString_valueOf-v6` | 85.2% | 132 | 155 | 23 |  |
| 26 | `Rectangle-v8` | 84.3% | 140 | 166 | 26 |  |
| 27 | `ColorTransform-v8` | 83.6% | 46 | 55 | 9 |  |
| 28 | `Inheritance-v5` | 83.5% | 96 | 115 | 19 |  |
| 29 | `Matrix-v8` | 82.7% | 139 | 168 | 29 |  |
| 30 | `System-v7` | 82.2% | 83 | 101 | 18 |  |
| 31 | `System-v8` | 82.2% | 83 | 101 | 18 |  |
| 32 | `System-v6` | 82.0% | 82 | 100 | 18 |  |
| 33 | `Number-v7` | 81.0% | 192 | 237 | 45 |  |
| 34 | `Number-v8` | 81.0% | 192 | 237 | 45 |  |
| 35 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 36 | `AsBroadcaster-v6` | 80.2% | 97 | 121 | 24 |  |
| 37 | `array-v5` | 79.6% | 446 | 560 | 114 |  |
| 38 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 39 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 40 | `Number-v5` | 79.1% | 193 | 244 | 51 |  |
| 41 | `TextFormat-v5` | 78.9% | 101 | 128 | 27 |  |
| 42 | `TextFormat-v6` | 78.9% | 101 | 128 | 27 |  |
| 43 | `Number-v6` | 77.8% | 186 | 239 | 53 |  |
| 44 | `Global-v8` | 77.5% | 131 | 169 | 38 |  |
| 45 | `Sound-v5` | 77.0% | 77 | 100 | 23 |  |
| 46 | `TextSnapshot-v6` | 76.3% | 132 | 173 | 41 |  |
| 47 | `TextSnapshot-v7` | 76.3% | 132 | 173 | 41 |  |
| 48 | `TextSnapshot-v8` | 76.3% | 132 | 173 | 41 |  |
| 49 | `Global-v7` | 75.3% | 137 | 182 | 45 |  |
| 50 | `System-v5` | 74.6% | 50 | 67 | 17 |  |
| 51 | `AsBroadcaster-v5` | 72.7% | 8 | 11 | 3 |  |
| 52 | `ContextMenu-v7` | 72.5% | 95 | 131 | 36 |  |
| 53 | `ContextMenu-v8` | 72.5% | 95 | 131 | 36 |  |
| 54 | `AsBroadcaster-v7` | 71.1% | 86 | 121 | 35 |  |
| 55 | `AsBroadcaster-v8` | 71.1% | 86 | 121 | 35 |  |
| 56 | `Global-v6` | 71.0% | 149 | 210 | 61 |  |
| 57 | `flash-v5` | 70.0% | 7 | 10 | 3 |  |
| 58 | `flash-v6` | 70.0% | 7 | 10 | 3 |  |
| 59 | `flash-v7` | 70.0% | 7 | 10 | 3 |  |
| 60 | `TextField-v5` | 66.7% | 8 | 12 | 4 |  |
| 61 | `delete-v8` | 66.7% | 40 | 60 | 20 |  |
| 62 | `MovieClip-v5` | 65.3% | 237 | 363 | 126 |  |
| 63 | `delete-v7` | 65.0% | 39 | 60 | 21 |  |
| 64 | `TextFormat-v7` | 64.9% | 113 | 174 | 61 |  |
| 65 | `delete-v6` | 63.3% | 38 | 60 | 22 |  |
| 66 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 67 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 68 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 69 | `String-v7` | 62.3% | 235 | 377 | 142 |  |
| 70 | `String-v8` | 62.3% | 235 | 377 | 142 |  |
| 71 | `BitmapData-v8` | 62.1% | 259 | 417 | 158 |  |
| 72 | `String-v6` | 62.1% | 234 | 377 | 143 |  |
| 73 | `delete-v5` | 61.7% | 37 | 60 | 23 |  |
| 74 | `Instance-v6` | 61.5% | 32 | 52 | 20 |  |
| 75 | `Microphone-v6` | 60.8% | 48 | 79 | 31 |  |
| 76 | `Microphone-v7` | 60.8% | 48 | 79 | 31 |  |
| 77 | `Microphone-v8` | 60.8% | 48 | 79 | 31 |  |
| 78 | `String-v5` | 60.6% | 217 | 358 | 141 |  |
| 79 | `toString_valueOf-v5` | 59.9% | 82 | 137 | 55 |  |
| 80 | `Instance-v5` | 59.6% | 31 | 52 | 21 |  |
| 81 | `LocalConnection-v5` | 57.1% | 4 | 7 | 3 |  |
| 82 | `NetConnection-v5` | 57.1% | 4 | 7 | 3 |  |
| 83 | `Transform-v6` | 57.1% | 4 | 7 | 3 |  |
| 84 | `Transform-v7` | 57.1% | 4 | 7 | 3 |  |
| 85 | `Video-v5` | 57.1% | 4 | 7 | 3 |  |
| 86 | `Instance-v7` | 55.8% | 29 | 52 | 23 |  |
| 87 | `ExternalInterface-v6` | 50.9% | 28 | 55 | 27 |  |
| 88 | `ExternalInterface-v7` | 50.9% | 28 | 55 | 27 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**119 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Inheritance-v8` | 97.3% | 177/182 | 182 | 181 |  |
| 2 | `Inheritance-v7` | 96.7% | 176/182 | 182 | 181 |  |
| 3 | `Color-v6` | 96.5% | 165/171 | 171 | 171 |  |
| 4 | `ExternalInterface-v8` | 95.8% | 113/118 | 118 | 118 |  |
| 5 | `NetStream-v6` | 95.0% | 76/80 | 80 | 80 |  |
| 6 | `NetStream-v7` | 95.0% | 76/80 | 80 | 80 |  |
| 7 | `NetStream-v8` | 95.0% | 76/80 | 80 | 80 |  |
| 8 | `Key-v6` | 94.5% | 52/55 | 55 | 55 |  |
| 9 | `Key-v7` | 94.5% | 52/55 | 55 | 55 |  |
| 10 | `Key-v8` | 94.5% | 52/55 | 55 | 55 |  |
| 11 | `Key-v5` | 92.2% | 47/51 | 51 | 51 |  |
| 12 | `Inheritance-v6` | 90.1% | 164/182 | 182 | 181 |  |
| 13 | `Selection-v7` | 88.0% | 110/125 | 125 | 125 |  |
| 14 | `Selection-v8` | 88.0% | 110/125 | 125 | 125 |  |
| 15 | `Point-v8` | 87.6% | 169/193 | 193 | 193 |  |
| 16 | `Selection-v6` | 87.2% | 109/125 | 125 | 125 |  |
| 17 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 18 | `TextFieldHTML-v7` | 86.5% | 32/37 | 37 | 37 |  |
| 19 | `TextFieldHTML-v8` | 86.5% | 32/37 | 37 | 37 |  |
| 20 | `toString_valueOf-v7` | 85.8% | 133/155 | 155 | 155 |  |
| 21 | `toString_valueOf-v8` | 85.8% | 133/155 | 155 | 155 |  |
| 22 | `Mouse-v6` | 85.7% | 18/21 | 21 | 21 |  |
| 23 | `Mouse-v7` | 85.7% | 18/21 | 21 | 21 |  |
| 24 | `Mouse-v8` | 85.7% | 18/21 | 21 | 21 |  |
| 25 | `toString_valueOf-v6` | 85.2% | 132/155 | 155 | 155 |  |
| 26 | `Rectangle-v8` | 84.3% | 140/166 | 166 | 166 |  |
| 27 | `ColorTransform-v8` | 83.6% | 46/55 | 55 | 55 |  |
| 28 | `Inheritance-v5` | 83.5% | 96/115 | 115 | 114 |  |
| 29 | `Matrix-v8` | 82.7% | 139/168 | 168 | 168 |  |
| 30 | `System-v7` | 82.2% | 83/101 | 101 | 101 |  |
| 31 | `System-v8` | 82.2% | 83/101 | 101 | 101 |  |
| 32 | `System-v6` | 82.0% | 82/100 | 100 | 100 |  |
| 33 | `Number-v7` | 81.0% | 192/237 | 237 | 237 |  |
| 34 | `Number-v8` | 81.0% | 192/237 | 237 | 237 |  |
| 35 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 36 | `AsBroadcaster-v6` | 80.2% | 97/121 | 121 | 121 |  |
| 37 | `array-v5` | 79.6% | 446/560 | 560 | 560 |  |
| 38 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 39 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 40 | `Number-v5` | 79.1% | 193/244 | 244 | 244 |  |
| 41 | `TextFormat-v5` | 78.9% | 101/128 | 128 | 128 |  |
| 42 | `TextFormat-v6` | 78.9% | 101/128 | 128 | 128 |  |
| 43 | `Number-v6` | 77.8% | 186/239 | 239 | 239 |  |
| 44 | `Global-v8` | 77.5% | 131/169 | 168 | 169 |  |
| 45 | `Sound-v5` | 77.0% | 77/100 | 100 | 100 |  |
| 46 | `TextSnapshot-v6` | 76.3% | 132/173 | 173 | 173 |  |
| 47 | `TextSnapshot-v7` | 76.3% | 132/173 | 173 | 173 |  |
| 48 | `TextSnapshot-v8` | 76.3% | 132/173 | 173 | 173 |  |
| 49 | `Global-v7` | 75.3% | 137/182 | 181 | 182 |  |
| 50 | `System-v5` | 74.6% | 50/67 | 67 | 67 |  |
| 51 | `AsBroadcaster-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 52 | `ContextMenu-v7` | 72.5% | 95/131 | 130 | 131 |  |
| 53 | `ContextMenu-v8` | 72.5% | 95/131 | 130 | 131 |  |
| 54 | `AsBroadcaster-v7` | 71.1% | 86/121 | 121 | 121 |  |
| 55 | `AsBroadcaster-v8` | 71.1% | 86/121 | 121 | 121 |  |
| 56 | `Global-v6` | 71.0% | 149/210 | 209 | 210 |  |
| 57 | `flash-v5` | 70.0% | 7/10 | 10 | 10 |  |
| 58 | `flash-v6` | 70.0% | 7/10 | 10 | 10 |  |
| 59 | `flash-v7` | 70.0% | 7/10 | 10 | 10 |  |
| 60 | `TextField-v5` | 66.7% | 8/12 | 12 | 12 |  |
| 61 | `delete-v8` | 66.7% | 40/60 | 60 | 60 |  |
| 62 | `MovieClip-v5` | 65.3% | 237/363 | 350 | 363 |  |
| 63 | `delete-v7` | 65.0% | 39/60 | 60 | 60 |  |
| 64 | `TextFormat-v7` | 64.9% | 113/174 | 174 | 174 |  |
| 65 | `delete-v6` | 63.3% | 38/60 | 60 | 60 |  |
| 66 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 67 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 68 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 69 | `String-v7` | 62.3% | 235/377 | 377 | 377 |  |
| 70 | `String-v8` | 62.3% | 235/377 | 377 | 377 |  |
| 71 | `BitmapData-v8` | 62.1% | 259/417 | 417 | 417 |  |
| 72 | `String-v6` | 62.1% | 234/377 | 377 | 377 |  |
| 73 | `delete-v5` | 61.7% | 37/60 | 60 | 60 |  |
| 74 | `Instance-v6` | 61.5% | 32/52 | 52 | 52 |  |
| 75 | `Microphone-v6` | 60.8% | 48/79 | 79 | 79 |  |
| 76 | `Microphone-v7` | 60.8% | 48/79 | 79 | 79 |  |
| 77 | `Microphone-v8` | 60.8% | 48/79 | 79 | 79 |  |
| 78 | `String-v5` | 60.6% | 217/358 | 358 | 358 |  |
| 79 | `toString_valueOf-v5` | 59.9% | 82/137 | 137 | 137 |  |
| 80 | `Instance-v5` | 59.6% | 31/52 | 52 | 52 |  |
| 81 | `LocalConnection-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 82 | `NetConnection-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 83 | `Transform-v6` | 57.1% | 4/7 | 7 | 7 |  |
| 84 | `Transform-v7` | 57.1% | 4/7 | 7 | 7 |  |
| 85 | `Video-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 86 | `Instance-v7` | 55.8% | 29/52 | 52 | 52 |  |
| 87 | `ExternalInterface-v6` | 50.9% | 28/55 | 55 | 55 |  |
| 88 | `ExternalInterface-v7` | 50.9% | 28/55 | 55 | 55 |  |
| 89 | `enumerate-v6` | 44.9% | 22/49 | 49 | 49 |  |
| 90 | `enumerate-v7` | 44.9% | 22/49 | 49 | 49 |  |
| 91 | `enumerate-v8` | 44.9% | 22/49 | 49 | 49 |  |
| 92 | `Instance-v8` | 44.2% | 23/52 | 52 | 52 |  |
| 93 | `LoadVars-v6` | 44.1% | 67/152 | 117 | 152 |  |
| 94 | `LoadVars-v7` | 44.1% | 67/152 | 117 | 152 |  |
| 95 | `LoadVars-v8` | 44.1% | 67/152 | 117 | 152 |  |
| 96 | `LocalConnection-v6` | 41.4% | 24/58 | 58 | 58 |  |
| 97 | `LocalConnection-v7` | 41.4% | 24/58 | 58 | 58 |  |
| 98 | `LocalConnection-v8` | 41.4% | 24/58 | 58 | 58 |  |
| 99 | `Camera-v6` | 36.7% | 33/90 | 90 | 90 |  |
| 100 | `Camera-v7` | 36.7% | 33/90 | 90 | 90 |  |
| 101 | `Camera-v8` | 36.7% | 33/90 | 90 | 90 |  |
| 102 | `targetPath-v6` | 32.1% | 9/28 | 28 | 23 |  |
| 103 | `targetPath-v7` | 32.1% | 9/28 | 28 | 23 |  |
| 104 | `targetPath-v8` | 32.1% | 9/28 | 28 | 23 |  |
| 105 | `with-v5` | 30.0% | 21/70 | 70 | 49 |  |
| 106 | `ASnative-v5` | 28.0% | 30/107 | 107 | 107 |  |
| 107 | `MovieClipLoader-v7` | 27.9% | 46/165 | 47 | 165 |  |
| 108 | `MovieClipLoader-v8` | 27.9% | 46/165 | 47 | 165 |  |
| 109 | `ASnative-v6` | 25.5% | 28/110 | 110 | 110 |  |
| 110 | `ASnative-v7` | 25.5% | 28/110 | 110 | 110 |  |
| 111 | `ASnative-v8` | 25.5% | 28/110 | 110 | 110 |  |
| 112 | `Matrix-v6` | 25.0% | 42/168 | 168 | 168 |  |
| 113 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 114 | `Matrix-v7` | 22.6% | 38/168 | 168 | 168 |  |
| 115 | `case-v7` | 19.4% | 13/67 | 66 | 67 |  |
| 116 | `case-v8` | 19.4% | 13/67 | 66 | 67 |  |
| 117 | `with-v6` | 18.3% | 23/126 | 126 | 107 |  |
| 118 | `with-v7` | 18.3% | 23/126 | 126 | 107 |  |
| 119 | `with-v8` | 18.3% | 23/126 | 126 | 107 |  |
