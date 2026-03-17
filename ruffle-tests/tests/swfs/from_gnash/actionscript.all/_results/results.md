# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-17 03:26 UTC

**Git SHA**: `2fced9201c`

**Run Duration**: 57m 11s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **17** (8.9%) |
| Failing | 173 |
| Total expected lines | 9439 |
| Matching lines | 5619 (59.5%) |
| Mismatched lines | 3820 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 129 | 74.6% |
| Compile Fail | 31 | 17.9% |
| Runtime Segfault | 13 | 7.5% |

## Passing Tests

**17 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `BitmapData-v6` | 7 | 16.1s |  |
| 2 | `BitmapData-v7` | 7 | 16.5s |  |
| 3 | `ColorTransform-v6` | 7 | 16.3s |  |
| 4 | `ColorTransform-v7` | 7 | 16.3s |  |
| 5 | `ContextMenu-v6` | 7 | 16.5s |  |
| 6 | `MovieClipLoader-v6` | 6 | 16.2s |  |
| 7 | `Point-v6` | 7 | 16.4s |  |
| 8 | `Point-v7` | 7 | 16.2s |  |
| 9 | `Random-v6` | 30 | 16.6s |  |
| 10 | `Random-v7` | 30 | 17.5s |  |
| 11 | `Random-v8` | 30 | 16.8s |  |
| 12 | `Rectangle-v6` | 7 | 16.2s |  |
| 13 | `Rectangle-v7` | 7 | 16.2s |  |
| 14 | `argstest-v5` | 4 | 17.0s |  |
| 15 | `swap-v6` | 7 | 16.6s |  |
| 16 | `swap-v7` | 7 | 16.6s |  |
| 17 | `swap-v8` | 7 | 16.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**93 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Video-v6` | 95.3% | 81 | 85 | 4 |  |
| 2 | `Video-v7` | 95.3% | 81 | 85 | 4 |  |
| 3 | `Video-v8` | 95.3% | 81 | 85 | 4 |  |
| 4 | `Boolean-v6` | 92.1% | 35 | 38 | 3 |  |
| 5 | `Boolean-v7` | 92.1% | 35 | 38 | 3 |  |
| 6 | `Boolean-v8` | 92.1% | 35 | 38 | 3 |  |
| 7 | `NetStream-v6` | 91.2% | 73 | 80 | 7 |  |
| 8 | `NetStream-v7` | 91.2% | 73 | 80 | 7 |  |
| 9 | `NetStream-v8` | 91.2% | 73 | 80 | 7 |  |
| 10 | `Boolean-v5` | 89.7% | 35 | 39 | 4 |  |
| 11 | `Random-v5` | 87.1% | 27 | 31 | 4 |  |
| 12 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 13 | `TextFieldHTML-v7` | 86.5% | 32 | 37 | 5 |  |
| 14 | `TextFieldHTML-v8` | 86.5% | 32 | 37 | 5 |  |
| 15 | `Selection-v7` | 86.4% | 108 | 125 | 17 |  |
| 16 | `Selection-v8` | 86.4% | 108 | 125 | 17 |  |
| 17 | `Camera-v5` | 85.7% | 6 | 7 | 1 |  |
| 18 | `swap-v5` | 85.7% | 6 | 7 | 1 |  |
| 19 | `Selection-v6` | 85.6% | 107 | 125 | 18 |  |
| 20 | `Microphone-v5` | 83.3% | 5 | 6 | 1 |  |
| 21 | `MovieClipLoader-v5` | 83.3% | 5 | 6 | 1 |  |
| 22 | `Color-v7` | 82.6% | 133 | 161 | 28 |  |
| 23 | `Color-v8` | 82.6% | 133 | 161 | 28 |  |
| 24 | `Stage-v5` | 82.1% | 32 | 39 | 7 |  |
| 25 | `Color-v5` | 81.6% | 115 | 141 | 26 |  |
| 26 | `Inheritance-v6` | 81.3% | 148 | 182 | 34 |  |
| 27 | `Color-v6` | 81.3% | 139 | 171 | 32 |  |
| 28 | `Selection-v5` | 81.0% | 17 | 21 | 4 |  |
| 29 | `TextFormat-v6` | 78.9% | 101 | 128 | 27 |  |
| 30 | `Inheritance-v5` | 77.6% | 90 | 116 | 26 |  |
| 31 | `TextFormat-v5` | 77.5% | 100 | 129 | 29 |  |
| 32 | `XMLSocket-v6` | 77.1% | 27 | 35 | 8 |  |
| 33 | `XMLSocket-v7` | 77.1% | 27 | 35 | 8 |  |
| 34 | `XMLSocket-v8` | 77.1% | 27 | 35 | 8 |  |
| 35 | `AsBroadcaster-v6` | 76.9% | 93 | 121 | 28 |  |
| 36 | `Global-v8` | 75.7% | 128 | 169 | 41 |  |
| 37 | `Sound-v5` | 75.2% | 76 | 101 | 25 |  |
| 38 | `Accessibility-v5` | 75.0% | 12 | 16 | 4 |  |
| 39 | `XMLSocket-v5` | 72.2% | 26 | 36 | 10 |  |
| 40 | `Error-v5` | 71.4% | 20 | 28 | 8 |  |
| 41 | `toString_valueOf-v7` | 71.0% | 110 | 155 | 45 |  |
| 42 | `toString_valueOf-v8` | 70.3% | 109 | 155 | 46 |  |
| 43 | `flash-v6` | 70.0% | 7 | 10 | 3 |  |
| 44 | `flash-v7` | 70.0% | 7 | 10 | 3 |  |
| 45 | `ExternalInterface-v8` | 69.5% | 82 | 118 | 36 |  |
| 46 | `targetPath-v5` | 69.2% | 9 | 13 | 4 |  |
| 47 | `AsBroadcaster-v7` | 67.8% | 82 | 121 | 39 |  |
| 48 | `Error-v6` | 67.7% | 21 | 31 | 10 |  |
| 49 | `Error-v7` | 67.7% | 21 | 31 | 10 |  |
| 50 | `Error-v8` | 67.7% | 21 | 31 | 10 |  |
| 51 | `AsBroadcaster-v8` | 66.9% | 81 | 121 | 40 |  |
| 52 | `delete-v8` | 66.7% | 40 | 60 | 20 |  |
| 53 | `Rectangle-v8` | 65.7% | 109 | 166 | 57 |  |
| 54 | `delete-v7` | 65.0% | 39 | 60 | 21 |  |
| 55 | `ContextMenu-v7` | 64.1% | 84 | 131 | 47 |  |
| 56 | `ContextMenu-v8` | 64.1% | 84 | 131 | 47 |  |
| 57 | `Instance-v6` | 63.5% | 33 | 52 | 19 |  |
| 58 | `delete-v6` | 63.3% | 38 | 60 | 22 |  |
| 59 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 60 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 61 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 62 | `ColorTransform-v8` | 61.8% | 34 | 55 | 21 |  |
| 63 | `Instance-v7` | 61.5% | 32 | 52 | 20 |  |
| 64 | `TextFormat-v7` | 61.5% | 107 | 174 | 67 |  |
| 65 | `delete-v5` | 59.0% | 36 | 61 | 25 |  |
| 66 | `Instance-v5` | 58.5% | 31 | 53 | 22 |  |
| 67 | `AsBroadcaster-v5` | 58.3% | 7 | 12 | 5 |  |
| 68 | `TextField-v5` | 58.3% | 7 | 12 | 5 |  |
| 69 | `Mouse-v6` | 57.1% | 12 | 21 | 9 |  |
| 70 | `Mouse-v7` | 57.1% | 12 | 21 | 9 |  |
| 71 | `Transform-v6` | 57.1% | 4 | 7 | 3 |  |
| 72 | `Transform-v7` | 57.1% | 4 | 7 | 3 |  |
| 73 | `LoadVars-v5` | 55.6% | 5 | 9 | 4 |  |
| 74 | `flash-v5` | 54.5% | 6 | 11 | 5 |  |
| 75 | `Microphone-v6` | 54.4% | 43 | 79 | 36 |  |
| 76 | `Microphone-v7` | 54.4% | 43 | 79 | 36 |  |
| 77 | `Microphone-v8` | 54.4% | 43 | 79 | 36 |  |
| 78 | `Accessibility-v6` | 52.6% | 10 | 19 | 9 |  |
| 79 | `Accessibility-v7` | 52.6% | 10 | 19 | 9 |  |
| 80 | `Mouse-v8` | 52.4% | 11 | 21 | 10 |  |
| 81 | `Instance-v8` | 51.9% | 27 | 52 | 25 |  |
| 82 | `ExternalInterface-v6` | 50.9% | 28 | 55 | 27 |  |
| 83 | `ExternalInterface-v7` | 50.9% | 28 | 55 | 27 |  |
| 84 | `BitmapData-v5` | 50.0% | 4 | 8 | 4 |  |
| 85 | `ColorTransform-v5` | 50.0% | 4 | 8 | 4 |  |
| 86 | `ContextMenu-v5` | 50.0% | 4 | 8 | 4 |  |
| 87 | `ExternalInterface-v5` | 50.0% | 4 | 8 | 4 |  |
| 88 | `Matrix-v5` | 50.0% | 4 | 8 | 4 |  |
| 89 | `Mouse-v5` | 50.0% | 7 | 14 | 7 |  |
| 90 | `Point-v5` | 50.0% | 4 | 8 | 4 |  |
| 91 | `Rectangle-v5` | 50.0% | 4 | 8 | 4 |  |
| 92 | `TextSnapshot-v5` | 50.0% | 4 | 8 | 4 |  |
| 93 | `Transform-v5` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

**13 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `HitTest-v6` | 20.8s |  |
| 2 | `HitTest-v7` | 21.2s |  |
| 3 | `HitTest-v8` | 21.7s |  |
| 4 | `Try-v5` | 19.3s |  |
| 5 | `Try-v6` | 19.4s |  |
| 6 | `Try-v7` | 19.5s |  |
| 7 | `Try-v8` | 19.7s |  |
| 8 | `case-v5` | 19.2s |  |
| 9 | `case-v6` | 20.5s |  |
| 10 | `case-v7` | 20.4s |  |
| 11 | `case-v8` | 20.0s |  |
| 12 | `toString_valueOf-v5` | 22.0s |  |
| 13 | `toString_valueOf-v6` | 23.1s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**129 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Video-v6` | 95.3% | 81/85 | 85 | 85 |  |
| 2 | `Video-v7` | 95.3% | 81/85 | 85 | 85 |  |
| 3 | `Video-v8` | 95.3% | 81/85 | 85 | 85 |  |
| 4 | `Boolean-v6` | 92.1% | 35/38 | 38 | 38 |  |
| 5 | `Boolean-v7` | 92.1% | 35/38 | 38 | 38 |  |
| 6 | `Boolean-v8` | 92.1% | 35/38 | 38 | 38 |  |
| 7 | `NetStream-v6` | 91.2% | 73/80 | 80 | 80 |  |
| 8 | `NetStream-v7` | 91.2% | 73/80 | 80 | 80 |  |
| 9 | `NetStream-v8` | 91.2% | 73/80 | 80 | 80 |  |
| 10 | `Boolean-v5` | 89.7% | 35/39 | 39 | 38 |  |
| 11 | `Random-v5` | 87.1% | 27/31 | 31 | 30 |  |
| 12 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 13 | `TextFieldHTML-v7` | 86.5% | 32/37 | 37 | 37 |  |
| 14 | `TextFieldHTML-v8` | 86.5% | 32/37 | 37 | 37 |  |
| 15 | `Selection-v7` | 86.4% | 108/125 | 125 | 125 |  |
| 16 | `Selection-v8` | 86.4% | 108/125 | 125 | 125 |  |
| 17 | `Camera-v5` | 85.7% | 6/7 | 7 | 7 |  |
| 18 | `swap-v5` | 85.7% | 6/7 | 7 | 7 |  |
| 19 | `Selection-v6` | 85.6% | 107/125 | 125 | 125 |  |
| 20 | `Microphone-v5` | 83.3% | 5/6 | 6 | 6 |  |
| 21 | `MovieClipLoader-v5` | 83.3% | 5/6 | 6 | 6 |  |
| 22 | `Color-v7` | 82.6% | 133/161 | 161 | 161 |  |
| 23 | `Color-v8` | 82.6% | 133/161 | 161 | 161 |  |
| 24 | `Stage-v5` | 82.1% | 32/39 | 39 | 38 |  |
| 25 | `Color-v5` | 81.6% | 115/141 | 141 | 140 |  |
| 26 | `Inheritance-v6` | 81.3% | 148/182 | 182 | 181 |  |
| 27 | `Color-v6` | 81.3% | 139/171 | 171 | 171 |  |
| 28 | `Selection-v5` | 81.0% | 17/21 | 21 | 21 |  |
| 29 | `TextFormat-v6` | 78.9% | 101/128 | 128 | 128 |  |
| 30 | `Inheritance-v5` | 77.6% | 90/116 | 116 | 114 |  |
| 31 | `TextFormat-v5` | 77.5% | 100/129 | 129 | 128 |  |
| 32 | `XMLSocket-v6` | 77.1% | 27/35 | 35 | 35 |  |
| 33 | `XMLSocket-v7` | 77.1% | 27/35 | 35 | 35 |  |
| 34 | `XMLSocket-v8` | 77.1% | 27/35 | 35 | 35 |  |
| 35 | `AsBroadcaster-v6` | 76.9% | 93/121 | 121 | 121 |  |
| 36 | `Global-v8` | 75.7% | 128/169 | 168 | 169 |  |
| 37 | `Sound-v5` | 75.2% | 76/101 | 101 | 100 |  |
| 38 | `Accessibility-v5` | 75.0% | 12/16 | 16 | 15 |  |
| 39 | `XMLSocket-v5` | 72.2% | 26/36 | 36 | 35 |  |
| 40 | `Error-v5` | 71.4% | 20/28 | 28 | 28 |  |
| 41 | `toString_valueOf-v7` | 71.0% | 110/155 | 155 | 155 |  |
| 42 | `toString_valueOf-v8` | 70.3% | 109/155 | 155 | 155 |  |
| 43 | `flash-v6` | 70.0% | 7/10 | 10 | 10 |  |
| 44 | `flash-v7` | 70.0% | 7/10 | 10 | 10 |  |
| 45 | `ExternalInterface-v8` | 69.5% | 82/118 | 118 | 118 |  |
| 46 | `targetPath-v5` | 69.2% | 9/13 | 13 | 12 |  |
| 47 | `AsBroadcaster-v7` | 67.8% | 82/121 | 121 | 121 |  |
| 48 | `Error-v6` | 67.7% | 21/31 | 31 | 31 |  |
| 49 | `Error-v7` | 67.7% | 21/31 | 31 | 31 |  |
| 50 | `Error-v8` | 67.7% | 21/31 | 31 | 31 |  |
| 51 | `AsBroadcaster-v8` | 66.9% | 81/121 | 121 | 121 |  |
| 52 | `delete-v8` | 66.7% | 40/60 | 60 | 60 |  |
| 53 | `Rectangle-v8` | 65.7% | 109/166 | 166 | 166 |  |
| 54 | `delete-v7` | 65.0% | 39/60 | 60 | 60 |  |
| 55 | `ContextMenu-v7` | 64.1% | 84/131 | 130 | 131 |  |
| 56 | `ContextMenu-v8` | 64.1% | 84/131 | 130 | 131 |  |
| 57 | `Instance-v6` | 63.5% | 33/52 | 52 | 52 |  |
| 58 | `delete-v6` | 63.3% | 38/60 | 60 | 60 |  |
| 59 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 60 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 61 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 62 | `ColorTransform-v8` | 61.8% | 34/55 | 55 | 55 |  |
| 63 | `Instance-v7` | 61.5% | 32/52 | 52 | 52 |  |
| 64 | `TextFormat-v7` | 61.5% | 107/174 | 174 | 174 |  |
| 65 | `delete-v5` | 59.0% | 36/61 | 61 | 60 |  |
| 66 | `Instance-v5` | 58.5% | 31/53 | 53 | 52 |  |
| 67 | `AsBroadcaster-v5` | 58.3% | 7/12 | 12 | 11 |  |
| 68 | `TextField-v5` | 58.3% | 7/12 | 12 | 12 |  |
| 69 | `Mouse-v6` | 57.1% | 12/21 | 21 | 21 |  |
| 70 | `Mouse-v7` | 57.1% | 12/21 | 21 | 21 |  |
| 71 | `Transform-v6` | 57.1% | 4/7 | 7 | 7 |  |
| 72 | `Transform-v7` | 57.1% | 4/7 | 7 | 7 |  |
| 73 | `LoadVars-v5` | 55.6% | 5/9 | 9 | 8 |  |
| 74 | `flash-v5` | 54.5% | 6/11 | 11 | 10 |  |
| 75 | `Microphone-v6` | 54.4% | 43/79 | 79 | 79 |  |
| 76 | `Microphone-v7` | 54.4% | 43/79 | 79 | 79 |  |
| 77 | `Microphone-v8` | 54.4% | 43/79 | 79 | 79 |  |
| 78 | `Accessibility-v6` | 52.6% | 10/19 | 19 | 19 |  |
| 79 | `Accessibility-v7` | 52.6% | 10/19 | 19 | 19 |  |
| 80 | `Mouse-v8` | 52.4% | 11/21 | 21 | 21 |  |
| 81 | `Instance-v8` | 51.9% | 27/52 | 52 | 52 |  |
| 82 | `ExternalInterface-v6` | 50.9% | 28/55 | 55 | 55 |  |
| 83 | `ExternalInterface-v7` | 50.9% | 28/55 | 55 | 55 |  |
| 84 | `BitmapData-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 85 | `ColorTransform-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 86 | `ContextMenu-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 87 | `ExternalInterface-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 88 | `Matrix-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 89 | `Mouse-v5` | 50.0% | 7/14 | 14 | 13 |  |
| 90 | `Point-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 91 | `Rectangle-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 92 | `TextSnapshot-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 93 | `Transform-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 94 | `Accessibility-v8` | 47.4% | 9/19 | 19 | 19 |  |
| 95 | `NetStream-v5` | 42.9% | 3/7 | 7 | 6 |  |
| 96 | `TextFieldHTML-v5` | 42.9% | 3/7 | 7 | 6 |  |
| 97 | `enumerate-v5` | 42.9% | 3/7 | 7 | 6 |  |
| 98 | `enumerate-v6` | 38.8% | 19/49 | 49 | 49 |  |
| 99 | `enumerate-v7` | 38.8% | 19/49 | 49 | 49 |  |
| 100 | `enumerate-v8` | 38.8% | 19/49 | 49 | 49 |  |
| 101 | `LoadVars-v6` | 37.5% | 57/152 | 117 | 152 |  |
| 102 | `LoadVars-v7` | 37.5% | 57/152 | 117 | 152 |  |
| 103 | `LoadVars-v8` | 37.5% | 57/152 | 117 | 152 |  |
| 104 | `LocalConnection-v5` | 37.5% | 3/8 | 8 | 7 |  |
| 105 | `NetConnection-v5` | 37.5% | 3/8 | 8 | 7 |  |
| 106 | `Video-v5` | 37.5% | 3/8 | 8 | 7 |  |
| 107 | `System-v5` | 36.8% | 25/68 | 68 | 67 |  |
| 108 | `Camera-v6` | 36.7% | 33/90 | 90 | 90 |  |
| 109 | `Camera-v7` | 36.7% | 33/90 | 90 | 90 |  |
| 110 | `Camera-v8` | 36.7% | 33/90 | 90 | 90 |  |
| 111 | `LocalConnection-v6` | 34.5% | 20/58 | 58 | 58 |  |
| 112 | `LocalConnection-v7` | 34.5% | 20/58 | 58 | 58 |  |
| 113 | `LocalConnection-v8` | 34.5% | 20/58 | 58 | 58 |  |
| 114 | `targetPath-v6` | 32.1% | 9/28 | 28 | 23 |  |
| 115 | `targetPath-v7` | 32.1% | 9/28 | 28 | 23 |  |
| 116 | `targetPath-v8` | 32.1% | 9/28 | 28 | 23 |  |
| 117 | `System-v6` | 28.0% | 28/100 | 100 | 100 |  |
| 118 | `System-v7` | 27.7% | 28/101 | 101 | 101 |  |
| 119 | `System-v8` | 27.7% | 28/101 | 101 | 101 |  |
| 120 | `ASnative-v5` | 26.9% | 29/108 | 108 | 107 |  |
| 121 | `ASnative-v8` | 26.4% | 29/110 | 110 | 110 |  |
| 122 | `ASnative-v6` | 25.5% | 28/110 | 110 | 110 |  |
| 123 | `ASnative-v7` | 25.5% | 28/110 | 110 | 110 |  |
| 124 | `Key-v6` | 25.5% | 14/55 | 55 | 55 |  |
| 125 | `Key-v7` | 25.5% | 14/55 | 55 | 55 |  |
| 126 | `Key-v8` | 25.5% | 14/55 | 55 | 55 |  |
| 127 | `MovieClipLoader-v7` | 23.6% | 39/165 | 47 | 165 |  |
| 128 | `MovieClipLoader-v8` | 23.6% | 39/165 | 47 | 165 |  |
| 129 | `Key-v5` | 17.6% | 9/51 | 51 | 51 |  |
