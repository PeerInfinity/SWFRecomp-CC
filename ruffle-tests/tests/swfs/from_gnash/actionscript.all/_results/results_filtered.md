# Ruffle Test Results (Filtered)

**Date**: 2026-04-03 22:14 UTC

**Git SHA**: `dc2748b675`

**Run Duration**: 67m 39s

**Filtered**: 9 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 181 |
| Passing | **68** (37.6%) |
| Failing | 113 |
| Total expected lines | 15444 |
| Matching lines | 10953 (70.9%) |
| Mismatched lines | 4491 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 113 | 100.0% |

## Passing Tests

**68 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 19.2s |  |
| 2 | `Accessibility-v6` | 19 | 19.4s |  |
| 3 | `Accessibility-v7` | 19 | 19.4s |  |
| 4 | `Accessibility-v8` | 19 | 18.9s |  |
| 5 | `BitmapData-v5` | 7 | 18.2s |  |
| 6 | `BitmapData-v6` | 7 | 18.7s |  |
| 7 | `BitmapData-v7` | 7 | 19.6s |  |
| 8 | `Boolean-v5` | 38 | 19.6s |  |
| 9 | `Boolean-v6` | 38 | 20.2s |  |
| 10 | `Boolean-v7` | 38 | 19.9s |  |
| 11 | `Boolean-v8` | 38 | 19.9s |  |
| 12 | `Camera-v5` | 7 | 19.2s |  |
| 13 | `Color-v5` | 140 | 22.6s |  |
| 14 | `Color-v7` | 161 | 23.1s |  |
| 15 | `Color-v8` | 161 | 23.2s |  |
| 16 | `ColorTransform-v5` | 7 | 19.3s |  |
| 17 | `ColorTransform-v6` | 7 | 19.0s |  |
| 18 | `ColorTransform-v7` | 7 | 19.1s |  |
| 19 | `ContextMenu-v5` | 7 | 19.1s |  |
| 20 | `ContextMenu-v6` | 7 | 18.9s |  |
| 21 | `ExternalInterface-v5` | 7 | 19.1s |  |
| 22 | `Key-v6` | 55 | 20.5s |  |
| 23 | `Key-v7` | 55 | 20.2s |  |
| 24 | `Key-v8` | 55 | 20.5s |  |
| 25 | `LoadVars-v5` | 8 | 20.1s |  |
| 26 | `Matrix-v5` | 7 | 18.6s |  |
| 27 | `Microphone-v5` | 6 | 18.7s |  |
| 28 | `Mouse-v5` | 13 | 18.3s |  |
| 29 | `Mouse-v6` | 21 | 18.4s |  |
| 30 | `Mouse-v7` | 21 | 18.4s |  |
| 31 | `Mouse-v8` | 21 | 18.6s |  |
| 32 | `MovieClipLoader-v5` | 6 | 18.2s |  |
| 33 | `MovieClipLoader-v6` | 6 | 18.6s |  |
| 34 | `NetStream-v5` | 6 | 18.5s |  |
| 35 | `Point-v5` | 7 | 18.3s |  |
| 36 | `Point-v6` | 7 | 18.3s |  |
| 37 | `Point-v7` | 7 | 18.3s |  |
| 38 | `Random-v5` | 30 | 18.9s |  |
| 39 | `Random-v6` | 30 | 18.9s |  |
| 40 | `Random-v7` | 30 | 19.1s |  |
| 41 | `Random-v8` | 30 | 19.1s |  |
| 42 | `Rectangle-v5` | 7 | 18.6s |  |
| 43 | `Rectangle-v6` | 7 | 18.5s |  |
| 44 | `Rectangle-v7` | 7 | 18.7s |  |
| 45 | `Selection-v5` | 21 | 19.2s |  |
| 46 | `Stage-v5` | 38 | 19.6s |  |
| 47 | `TextFieldHTML-v5` | 6 | 19.1s |  |
| 48 | `TextSnapshot-v5` | 7 | 18.2s |  |
| 49 | `Transform-v5` | 7 | 18.3s |  |
| 50 | `Try-v5` | 20 | 20.2s |  |
| 51 | `Try-v6` | 20 | 20.1s |  |
| 52 | `Try-v7` | 20 | 20.1s |  |
| 53 | `Try-v8` | 20 | 19.7s |  |
| 54 | `Video-v6` | 85 | 20.4s |  |
| 55 | `Video-v7` | 85 | 20.5s |  |
| 56 | `Video-v8` | 85 | 20.5s |  |
| 57 | `XMLSocket-v5` | 35 | 19.4s |  |
| 58 | `XMLSocket-v6` | 35 | 19.4s |  |
| 59 | `XMLSocket-v7` | 35 | 19.0s |  |
| 60 | `XMLSocket-v8` | 35 | 19.0s |  |
| 61 | `argstest-v5` | 4 | 18.6s |  |
| 62 | `case-v5` | 39 | 19.1s |  |
| 63 | `enumerate-v5` | 6 | 18.8s |  |
| 64 | `swap-v5` | 7 | 18.7s |  |
| 65 | `swap-v6` | 7 | 18.5s |  |
| 66 | `swap-v7` | 7 | 18.8s |  |
| 67 | `swap-v8` | 7 | 18.6s |  |
| 68 | `targetPath-v5` | 12 | 19.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**82 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Inheritance-v8` | 97.3% | 177 | 182 | 5 |  |
| 2 | `Inheritance-v7` | 96.7% | 176 | 182 | 6 |  |
| 3 | `Color-v6` | 96.5% | 165 | 171 | 6 |  |
| 4 | `ExternalInterface-v8` | 95.8% | 113 | 118 | 5 |  |
| 5 | `NetStream-v6` | 95.0% | 76 | 80 | 4 |  |
| 6 | `NetStream-v7` | 95.0% | 76 | 80 | 4 |  |
| 7 | `NetStream-v8` | 95.0% | 76 | 80 | 4 |  |
| 8 | `Key-v5` | 92.2% | 47 | 51 | 4 |  |
| 9 | `Inheritance-v6` | 90.1% | 164 | 182 | 18 |  |
| 10 | `Selection-v7` | 88.8% | 111 | 125 | 14 |  |
| 11 | `Selection-v8` | 88.8% | 111 | 125 | 14 |  |
| 12 | `Selection-v6` | 88.0% | 110 | 125 | 15 |  |
| 13 | `Point-v8` | 87.6% | 169 | 193 | 24 |  |
| 14 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 15 | `TextFieldHTML-v7` | 86.5% | 32 | 37 | 5 |  |
| 16 | `TextFieldHTML-v8` | 86.5% | 32 | 37 | 5 |  |
| 17 | `toString_valueOf-v7` | 85.8% | 133 | 155 | 22 |  |
| 18 | `toString_valueOf-v8` | 85.8% | 133 | 155 | 22 |  |
| 19 | `toString_valueOf-v6` | 85.2% | 132 | 155 | 23 |  |
| 20 | `Rectangle-v8` | 84.3% | 140 | 166 | 26 |  |
| 21 | `ColorTransform-v8` | 83.6% | 46 | 55 | 9 |  |
| 22 | `Inheritance-v5` | 83.5% | 96 | 115 | 19 |  |
| 23 | `Matrix-v8` | 82.7% | 139 | 168 | 29 |  |
| 24 | `System-v7` | 82.2% | 83 | 101 | 18 |  |
| 25 | `System-v8` | 82.2% | 83 | 101 | 18 |  |
| 26 | `System-v6` | 82.0% | 82 | 100 | 18 |  |
| 27 | `Number-v7` | 81.0% | 192 | 237 | 45 |  |
| 28 | `Number-v8` | 81.0% | 192 | 237 | 45 |  |
| 29 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 30 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 31 | `array-v5` | 79.6% | 446 | 560 | 114 |  |
| 32 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 33 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 34 | `Number-v5` | 79.1% | 193 | 244 | 51 |  |
| 35 | `TextFormat-v5` | 78.9% | 101 | 128 | 27 |  |
| 36 | `TextFormat-v6` | 78.9% | 101 | 128 | 27 |  |
| 37 | `Number-v6` | 77.8% | 186 | 239 | 53 |  |
| 38 | `Global-v8` | 77.5% | 131 | 169 | 38 |  |
| 39 | `Sound-v5` | 77.0% | 77 | 100 | 23 |  |
| 40 | `TextSnapshot-v6` | 76.3% | 132 | 173 | 41 |  |
| 41 | `TextSnapshot-v7` | 76.3% | 132 | 173 | 41 |  |
| 42 | `TextSnapshot-v8` | 76.3% | 132 | 173 | 41 |  |
| 43 | `Global-v7` | 75.3% | 137 | 182 | 45 |  |
| 44 | `System-v5` | 74.6% | 50 | 67 | 17 |  |
| 45 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 46 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 47 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 48 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 49 | `AsBroadcaster-v5` | 72.7% | 8 | 11 | 3 |  |
| 50 | `Global-v6` | 71.0% | 149 | 210 | 61 |  |
| 51 | `flash-v5` | 70.0% | 7 | 10 | 3 |  |
| 52 | `flash-v6` | 70.0% | 7 | 10 | 3 |  |
| 53 | `flash-v7` | 70.0% | 7 | 10 | 3 |  |
| 54 | `String-v7` | 68.7% | 259 | 377 | 118 |  |
| 55 | `String-v8` | 68.7% | 259 | 377 | 118 |  |
| 56 | `String-v6` | 68.4% | 258 | 377 | 119 |  |
| 57 | `String-v5` | 67.0% | 240 | 358 | 118 |  |
| 58 | `TextField-v5` | 66.7% | 8 | 12 | 4 |  |
| 59 | `delete-v8` | 66.7% | 40 | 60 | 20 |  |
| 60 | `MovieClip-v5` | 65.3% | 237 | 363 | 126 |  |
| 61 | `delete-v7` | 65.0% | 39 | 60 | 21 |  |
| 62 | `TextFormat-v7` | 64.9% | 113 | 174 | 61 |  |
| 63 | `delete-v6` | 63.3% | 38 | 60 | 22 |  |
| 64 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 65 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 66 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 67 | `BitmapData-v8` | 62.1% | 259 | 417 | 158 |  |
| 68 | `delete-v5` | 61.7% | 37 | 60 | 23 |  |
| 69 | `Instance-v6` | 61.5% | 32 | 52 | 20 |  |
| 70 | `Microphone-v6` | 60.8% | 48 | 79 | 31 |  |
| 71 | `Microphone-v7` | 60.8% | 48 | 79 | 31 |  |
| 72 | `Microphone-v8` | 60.8% | 48 | 79 | 31 |  |
| 73 | `toString_valueOf-v5` | 59.9% | 82 | 137 | 55 |  |
| 74 | `Instance-v5` | 59.6% | 31 | 52 | 21 |  |
| 75 | `LocalConnection-v5` | 57.1% | 4 | 7 | 3 |  |
| 76 | `NetConnection-v5` | 57.1% | 4 | 7 | 3 |  |
| 77 | `Transform-v6` | 57.1% | 4 | 7 | 3 |  |
| 78 | `Transform-v7` | 57.1% | 4 | 7 | 3 |  |
| 79 | `Video-v5` | 57.1% | 4 | 7 | 3 |  |
| 80 | `Instance-v7` | 55.8% | 29 | 52 | 23 |  |
| 81 | `ExternalInterface-v6` | 50.9% | 28 | 55 | 27 |  |
| 82 | `ExternalInterface-v7` | 50.9% | 28 | 55 | 27 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**113 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Inheritance-v8` | 97.3% | 177/182 | 182 | 181 |  |
| 2 | `Inheritance-v7` | 96.7% | 176/182 | 182 | 181 |  |
| 3 | `Color-v6` | 96.5% | 165/171 | 171 | 171 |  |
| 4 | `ExternalInterface-v8` | 95.8% | 113/118 | 118 | 118 |  |
| 5 | `NetStream-v6` | 95.0% | 76/80 | 80 | 80 |  |
| 6 | `NetStream-v7` | 95.0% | 76/80 | 80 | 80 |  |
| 7 | `NetStream-v8` | 95.0% | 76/80 | 80 | 80 |  |
| 8 | `Key-v5` | 92.2% | 47/51 | 51 | 51 |  |
| 9 | `Inheritance-v6` | 90.1% | 164/182 | 182 | 181 |  |
| 10 | `Selection-v7` | 88.8% | 111/125 | 125 | 125 |  |
| 11 | `Selection-v8` | 88.8% | 111/125 | 125 | 125 |  |
| 12 | `Selection-v6` | 88.0% | 110/125 | 125 | 125 |  |
| 13 | `Point-v8` | 87.6% | 169/193 | 193 | 193 |  |
| 14 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 15 | `TextFieldHTML-v7` | 86.5% | 32/37 | 37 | 37 |  |
| 16 | `TextFieldHTML-v8` | 86.5% | 32/37 | 37 | 37 |  |
| 17 | `toString_valueOf-v7` | 85.8% | 133/155 | 155 | 155 |  |
| 18 | `toString_valueOf-v8` | 85.8% | 133/155 | 155 | 155 |  |
| 19 | `toString_valueOf-v6` | 85.2% | 132/155 | 155 | 155 |  |
| 20 | `Rectangle-v8` | 84.3% | 140/166 | 166 | 166 |  |
| 21 | `ColorTransform-v8` | 83.6% | 46/55 | 55 | 55 |  |
| 22 | `Inheritance-v5` | 83.5% | 96/115 | 115 | 114 |  |
| 23 | `Matrix-v8` | 82.7% | 139/168 | 168 | 168 |  |
| 24 | `System-v7` | 82.2% | 83/101 | 101 | 101 |  |
| 25 | `System-v8` | 82.2% | 83/101 | 101 | 101 |  |
| 26 | `System-v6` | 82.0% | 82/100 | 100 | 100 |  |
| 27 | `Number-v7` | 81.0% | 192/237 | 237 | 237 |  |
| 28 | `Number-v8` | 81.0% | 192/237 | 237 | 237 |  |
| 29 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 30 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 31 | `array-v5` | 79.6% | 446/560 | 560 | 560 |  |
| 32 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 33 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 34 | `Number-v5` | 79.1% | 193/244 | 244 | 244 |  |
| 35 | `TextFormat-v5` | 78.9% | 101/128 | 128 | 128 |  |
| 36 | `TextFormat-v6` | 78.9% | 101/128 | 128 | 128 |  |
| 37 | `Number-v6` | 77.8% | 186/239 | 239 | 239 |  |
| 38 | `Global-v8` | 77.5% | 131/169 | 168 | 169 |  |
| 39 | `Sound-v5` | 77.0% | 77/100 | 100 | 100 |  |
| 40 | `TextSnapshot-v6` | 76.3% | 132/173 | 173 | 173 |  |
| 41 | `TextSnapshot-v7` | 76.3% | 132/173 | 173 | 173 |  |
| 42 | `TextSnapshot-v8` | 76.3% | 132/173 | 173 | 173 |  |
| 43 | `Global-v7` | 75.3% | 137/182 | 181 | 182 |  |
| 44 | `System-v5` | 74.6% | 50/67 | 67 | 67 |  |
| 45 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 46 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 47 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 48 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 49 | `AsBroadcaster-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 50 | `Global-v6` | 71.0% | 149/210 | 209 | 210 |  |
| 51 | `flash-v5` | 70.0% | 7/10 | 10 | 10 |  |
| 52 | `flash-v6` | 70.0% | 7/10 | 10 | 10 |  |
| 53 | `flash-v7` | 70.0% | 7/10 | 10 | 10 |  |
| 54 | `String-v7` | 68.7% | 259/377 | 377 | 377 |  |
| 55 | `String-v8` | 68.7% | 259/377 | 377 | 377 |  |
| 56 | `String-v6` | 68.4% | 258/377 | 377 | 377 |  |
| 57 | `String-v5` | 67.0% | 240/358 | 358 | 358 |  |
| 58 | `TextField-v5` | 66.7% | 8/12 | 12 | 12 |  |
| 59 | `delete-v8` | 66.7% | 40/60 | 60 | 60 |  |
| 60 | `MovieClip-v5` | 65.3% | 237/363 | 350 | 363 |  |
| 61 | `delete-v7` | 65.0% | 39/60 | 60 | 60 |  |
| 62 | `TextFormat-v7` | 64.9% | 113/174 | 174 | 174 |  |
| 63 | `delete-v6` | 63.3% | 38/60 | 60 | 60 |  |
| 64 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 65 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 66 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 67 | `BitmapData-v8` | 62.1% | 259/417 | 417 | 417 |  |
| 68 | `delete-v5` | 61.7% | 37/60 | 60 | 60 |  |
| 69 | `Instance-v6` | 61.5% | 32/52 | 52 | 52 |  |
| 70 | `Microphone-v6` | 60.8% | 48/79 | 79 | 79 |  |
| 71 | `Microphone-v7` | 60.8% | 48/79 | 79 | 79 |  |
| 72 | `Microphone-v8` | 60.8% | 48/79 | 79 | 79 |  |
| 73 | `toString_valueOf-v5` | 59.9% | 82/137 | 137 | 137 |  |
| 74 | `Instance-v5` | 59.6% | 31/52 | 52 | 52 |  |
| 75 | `LocalConnection-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 76 | `NetConnection-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 77 | `Transform-v6` | 57.1% | 4/7 | 7 | 7 |  |
| 78 | `Transform-v7` | 57.1% | 4/7 | 7 | 7 |  |
| 79 | `Video-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 80 | `Instance-v7` | 55.8% | 29/52 | 52 | 52 |  |
| 81 | `ExternalInterface-v6` | 50.9% | 28/55 | 55 | 55 |  |
| 82 | `ExternalInterface-v7` | 50.9% | 28/55 | 55 | 55 |  |
| 83 | `enumerate-v6` | 44.9% | 22/49 | 49 | 49 |  |
| 84 | `enumerate-v7` | 44.9% | 22/49 | 49 | 49 |  |
| 85 | `enumerate-v8` | 44.9% | 22/49 | 49 | 49 |  |
| 86 | `Instance-v8` | 44.2% | 23/52 | 52 | 52 |  |
| 87 | `LoadVars-v6` | 44.1% | 67/152 | 117 | 152 |  |
| 88 | `LoadVars-v7` | 44.1% | 67/152 | 117 | 152 |  |
| 89 | `LoadVars-v8` | 44.1% | 67/152 | 117 | 152 |  |
| 90 | `LocalConnection-v6` | 41.4% | 24/58 | 58 | 58 |  |
| 91 | `LocalConnection-v7` | 41.4% | 24/58 | 58 | 58 |  |
| 92 | `LocalConnection-v8` | 41.4% | 24/58 | 58 | 58 |  |
| 93 | `Camera-v6` | 36.7% | 33/90 | 90 | 90 |  |
| 94 | `Camera-v7` | 36.7% | 33/90 | 90 | 90 |  |
| 95 | `Camera-v8` | 36.7% | 33/90 | 90 | 90 |  |
| 96 | `targetPath-v6` | 32.1% | 9/28 | 28 | 23 |  |
| 97 | `targetPath-v7` | 32.1% | 9/28 | 28 | 23 |  |
| 98 | `targetPath-v8` | 32.1% | 9/28 | 28 | 23 |  |
| 99 | `with-v5` | 30.0% | 21/70 | 70 | 49 |  |
| 100 | `ASnative-v5` | 28.0% | 30/107 | 107 | 107 |  |
| 101 | `MovieClipLoader-v7` | 27.9% | 46/165 | 47 | 165 |  |
| 102 | `MovieClipLoader-v8` | 27.9% | 46/165 | 47 | 165 |  |
| 103 | `ASnative-v6` | 25.5% | 28/110 | 110 | 110 |  |
| 104 | `ASnative-v7` | 25.5% | 28/110 | 110 | 110 |  |
| 105 | `ASnative-v8` | 25.5% | 28/110 | 110 | 110 |  |
| 106 | `Matrix-v6` | 25.0% | 42/168 | 168 | 168 |  |
| 107 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 108 | `Matrix-v7` | 22.6% | 38/168 | 168 | 168 |  |
| 109 | `case-v7` | 19.4% | 13/67 | 66 | 67 |  |
| 110 | `case-v8` | 19.4% | 13/67 | 66 | 67 |  |
| 111 | `with-v6` | 18.3% | 23/126 | 126 | 107 |  |
| 112 | `with-v7` | 18.3% | 23/126 | 126 | 107 |  |
| 113 | `with-v8` | 18.3% | 23/126 | 126 | 107 |  |
