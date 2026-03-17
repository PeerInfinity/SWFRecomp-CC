# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-17 02:29 UTC

**Git SHA**: `be80957869`

**Run Duration**: 56m 53s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **1** (0.5%) |
| Failing | 189 |
| Total expected lines | 9439 |
| Matching lines | 5531 (58.6%) |
| Mismatched lines | 3908 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 145 | 76.7% |
| Compile Fail | 31 | 16.4% |
| Runtime Segfault | 13 | 6.9% |

## Passing Tests

**1 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `argstest-v5` | 4 | 17.1s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**104 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Random-v6` | 96.7% | 29 | 30 | 1 |  |
| 2 | `Video-v6` | 95.3% | 81 | 85 | 4 |  |
| 3 | `Video-v7` | 93.0% | 80 | 86 | 6 |  |
| 4 | `Video-v8` | 93.0% | 80 | 86 | 6 |  |
| 5 | `Boolean-v6` | 92.1% | 35 | 38 | 3 |  |
| 6 | `NetStream-v6` | 91.2% | 73 | 80 | 7 |  |
| 7 | `Boolean-v5` | 89.7% | 35 | 39 | 4 |  |
| 8 | `NetStream-v7` | 88.9% | 72 | 81 | 9 |  |
| 9 | `NetStream-v8` | 88.9% | 72 | 81 | 9 |  |
| 10 | `Boolean-v7` | 87.2% | 34 | 39 | 5 |  |
| 11 | `Boolean-v8` | 87.2% | 34 | 39 | 5 |  |
| 12 | `Random-v5` | 87.1% | 27 | 31 | 4 |  |
| 13 | `Random-v7` | 87.1% | 27 | 31 | 4 |  |
| 14 | `Random-v8` | 87.1% | 27 | 31 | 4 |  |
| 15 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 16 | `BitmapData-v6` | 85.7% | 6 | 7 | 1 |  |
| 17 | `ColorTransform-v6` | 85.7% | 6 | 7 | 1 |  |
| 18 | `ContextMenu-v6` | 85.7% | 6 | 7 | 1 |  |
| 19 | `Point-v6` | 85.7% | 6 | 7 | 1 |  |
| 20 | `Rectangle-v6` | 85.7% | 6 | 7 | 1 |  |
| 21 | `swap-v6` | 85.7% | 6 | 7 | 1 |  |
| 22 | `Selection-v6` | 85.6% | 107 | 125 | 18 |  |
| 23 | `Selection-v7` | 85.6% | 107 | 125 | 18 |  |
| 24 | `Selection-v8` | 85.6% | 107 | 125 | 18 |  |
| 25 | `Stage-v5` | 82.1% | 32 | 39 | 7 |  |
| 26 | `TextFieldHTML-v7` | 81.6% | 31 | 38 | 7 |  |
| 27 | `TextFieldHTML-v8` | 81.6% | 31 | 38 | 7 |  |
| 28 | `Color-v5` | 81.6% | 115 | 141 | 26 |  |
| 29 | `Color-v7` | 81.5% | 132 | 162 | 30 |  |
| 30 | `Color-v8` | 81.5% | 132 | 162 | 30 |  |
| 31 | `Inheritance-v6` | 81.3% | 148 | 182 | 34 |  |
| 32 | `Color-v6` | 81.3% | 139 | 171 | 32 |  |
| 33 | `Selection-v5` | 81.0% | 17 | 21 | 4 |  |
| 34 | `TextFormat-v6` | 78.9% | 101 | 128 | 27 |  |
| 35 | `Inheritance-v5` | 77.6% | 90 | 116 | 26 |  |
| 36 | `TextFormat-v5` | 77.5% | 100 | 129 | 29 |  |
| 37 | `XMLSocket-v6` | 77.1% | 27 | 35 | 8 |  |
| 38 | `AsBroadcaster-v6` | 76.9% | 93 | 121 | 28 |  |
| 39 | `Global-v8` | 75.7% | 128 | 169 | 41 |  |
| 40 | `Sound-v5` | 75.2% | 76 | 101 | 25 |  |
| 41 | `Accessibility-v5` | 75.0% | 12 | 16 | 4 |  |
| 42 | `XMLSocket-v5` | 72.2% | 26 | 36 | 10 |  |
| 43 | `XMLSocket-v7` | 72.2% | 26 | 36 | 10 |  |
| 44 | `XMLSocket-v8` | 72.2% | 26 | 36 | 10 |  |
| 45 | `Camera-v5` | 71.4% | 5 | 7 | 2 |  |
| 46 | `Error-v5` | 71.4% | 20 | 28 | 8 |  |
| 47 | `swap-v5` | 71.4% | 5 | 7 | 2 |  |
| 48 | `flash-v6` | 70.0% | 7 | 10 | 3 |  |
| 49 | `toString_valueOf-v7` | 69.9% | 109 | 156 | 47 |  |
| 50 | `targetPath-v5` | 69.2% | 9 | 13 | 4 |  |
| 51 | `toString_valueOf-v8` | 69.2% | 108 | 156 | 48 |  |
| 52 | `ExternalInterface-v8` | 68.1% | 81 | 119 | 38 |  |
| 53 | `Error-v6` | 67.7% | 21 | 31 | 10 |  |
| 54 | `MovieClipLoader-v6` | 66.7% | 4 | 6 | 2 |  |
| 55 | `AsBroadcaster-v7` | 66.4% | 81 | 122 | 41 |  |
| 56 | `AsBroadcaster-v8` | 65.6% | 80 | 122 | 42 |  |
| 57 | `Rectangle-v8` | 64.7% | 108 | 167 | 59 |  |
| 58 | `Error-v7` | 64.5% | 20 | 31 | 11 |  |
| 59 | `Error-v8` | 64.5% | 20 | 31 | 11 |  |
| 60 | `ContextMenu-v7` | 64.1% | 84 | 131 | 47 |  |
| 61 | `ContextMenu-v8` | 64.1% | 84 | 131 | 47 |  |
| 62 | `delete-v8` | 63.9% | 39 | 61 | 22 |  |
| 63 | `Instance-v6` | 63.5% | 33 | 52 | 19 |  |
| 64 | `delete-v6` | 63.3% | 38 | 60 | 22 |  |
| 65 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 66 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 67 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 68 | `delete-v7` | 62.3% | 38 | 61 | 23 |  |
| 69 | `TextFormat-v7` | 60.6% | 106 | 175 | 69 |  |
| 70 | `delete-v5` | 59.0% | 36 | 61 | 25 |  |
| 71 | `ColorTransform-v8` | 58.9% | 33 | 56 | 23 |  |
| 72 | `Instance-v5` | 58.5% | 31 | 53 | 22 |  |
| 73 | `Instance-v7` | 58.5% | 31 | 53 | 22 |  |
| 74 | `AsBroadcaster-v5` | 58.3% | 7 | 12 | 5 |  |
| 75 | `TextField-v5` | 58.3% | 7 | 12 | 5 |  |
| 76 | `Mouse-v6` | 57.1% | 12 | 21 | 9 |  |
| 77 | `Transform-v6` | 57.1% | 4 | 7 | 3 |  |
| 78 | `swap-v7` | 57.1% | 4 | 7 | 3 |  |
| 79 | `swap-v8` | 57.1% | 4 | 7 | 3 |  |
| 80 | `LoadVars-v5` | 55.6% | 5 | 9 | 4 |  |
| 81 | `flash-v5` | 54.5% | 6 | 11 | 5 |  |
| 82 | `flash-v7` | 54.5% | 6 | 11 | 5 |  |
| 83 | `Microphone-v6` | 54.4% | 43 | 79 | 36 |  |
| 84 | `Microphone-v7` | 53.2% | 42 | 79 | 37 |  |
| 85 | `Microphone-v8` | 53.2% | 42 | 79 | 37 |  |
| 86 | `Accessibility-v6` | 52.6% | 10 | 19 | 9 |  |
| 87 | `ExternalInterface-v6` | 50.9% | 28 | 55 | 27 |  |
| 88 | `BitmapData-v5` | 50.0% | 4 | 8 | 4 |  |
| 89 | `BitmapData-v7` | 50.0% | 4 | 8 | 4 |  |
| 90 | `ColorTransform-v5` | 50.0% | 4 | 8 | 4 |  |
| 91 | `ColorTransform-v7` | 50.0% | 4 | 8 | 4 |  |
| 92 | `ContextMenu-v5` | 50.0% | 4 | 8 | 4 |  |
| 93 | `ExternalInterface-v5` | 50.0% | 4 | 8 | 4 |  |
| 94 | `Matrix-v5` | 50.0% | 4 | 8 | 4 |  |
| 95 | `Microphone-v5` | 50.0% | 3 | 6 | 3 |  |
| 96 | `Mouse-v5` | 50.0% | 7 | 14 | 7 |  |
| 97 | `Mouse-v7` | 50.0% | 11 | 22 | 11 |  |
| 98 | `MovieClipLoader-v5` | 50.0% | 3 | 6 | 3 |  |
| 99 | `Point-v5` | 50.0% | 4 | 8 | 4 |  |
| 100 | `Point-v7` | 50.0% | 4 | 8 | 4 |  |
| 101 | `Rectangle-v5` | 50.0% | 4 | 8 | 4 |  |
| 102 | `Rectangle-v7` | 50.0% | 4 | 8 | 4 |  |
| 103 | `TextSnapshot-v5` | 50.0% | 4 | 8 | 4 |  |
| 104 | `Transform-v5` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

**13 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `HitTest-v6` | 23.3s |  |
| 2 | `HitTest-v7` | 23.2s |  |
| 3 | `HitTest-v8` | 22.1s |  |
| 4 | `Try-v5` | 19.1s |  |
| 5 | `Try-v6` | 19.2s |  |
| 6 | `Try-v7` | 19.2s |  |
| 7 | `Try-v8` | 19.0s |  |
| 8 | `case-v5` | 19.7s |  |
| 9 | `case-v6` | 21.7s |  |
| 10 | `case-v7` | 21.8s |  |
| 11 | `case-v8` | 20.2s |  |
| 12 | `toString_valueOf-v5` | 21.0s |  |
| 13 | `toString_valueOf-v6` | 21.8s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**145 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `Random-v6` | 96.7% | 29/30 | 30 | 30 |  |
| 2 | `Video-v6` | 95.3% | 81/85 | 85 | 85 |  |
| 3 | `Video-v7` | 93.0% | 80/86 | 86 | 85 |  |
| 4 | `Video-v8` | 93.0% | 80/86 | 86 | 85 |  |
| 5 | `Boolean-v6` | 92.1% | 35/38 | 38 | 38 |  |
| 6 | `NetStream-v6` | 91.2% | 73/80 | 80 | 80 |  |
| 7 | `Boolean-v5` | 89.7% | 35/39 | 39 | 38 |  |
| 8 | `NetStream-v7` | 88.9% | 72/81 | 81 | 80 |  |
| 9 | `NetStream-v8` | 88.9% | 72/81 | 81 | 80 |  |
| 10 | `Boolean-v7` | 87.2% | 34/39 | 39 | 38 |  |
| 11 | `Boolean-v8` | 87.2% | 34/39 | 39 | 38 |  |
| 12 | `Random-v5` | 87.1% | 27/31 | 31 | 30 |  |
| 13 | `Random-v7` | 87.1% | 27/31 | 31 | 30 |  |
| 14 | `Random-v8` | 87.1% | 27/31 | 31 | 30 |  |
| 15 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 16 | `BitmapData-v6` | 85.7% | 6/7 | 7 | 7 |  |
| 17 | `ColorTransform-v6` | 85.7% | 6/7 | 7 | 7 |  |
| 18 | `ContextMenu-v6` | 85.7% | 6/7 | 7 | 7 |  |
| 19 | `Point-v6` | 85.7% | 6/7 | 7 | 7 |  |
| 20 | `Rectangle-v6` | 85.7% | 6/7 | 7 | 7 |  |
| 21 | `swap-v6` | 85.7% | 6/7 | 7 | 7 |  |
| 22 | `Selection-v6` | 85.6% | 107/125 | 125 | 125 |  |
| 23 | `Selection-v7` | 85.6% | 107/125 | 125 | 125 |  |
| 24 | `Selection-v8` | 85.6% | 107/125 | 125 | 125 |  |
| 25 | `Stage-v5` | 82.1% | 32/39 | 39 | 38 |  |
| 26 | `TextFieldHTML-v7` | 81.6% | 31/38 | 38 | 37 |  |
| 27 | `TextFieldHTML-v8` | 81.6% | 31/38 | 38 | 37 |  |
| 28 | `Color-v5` | 81.6% | 115/141 | 141 | 140 |  |
| 29 | `Color-v7` | 81.5% | 132/162 | 162 | 161 |  |
| 30 | `Color-v8` | 81.5% | 132/162 | 162 | 161 |  |
| 31 | `Inheritance-v6` | 81.3% | 148/182 | 182 | 181 |  |
| 32 | `Color-v6` | 81.3% | 139/171 | 171 | 171 |  |
| 33 | `Selection-v5` | 81.0% | 17/21 | 21 | 21 |  |
| 34 | `TextFormat-v6` | 78.9% | 101/128 | 128 | 128 |  |
| 35 | `Inheritance-v5` | 77.6% | 90/116 | 116 | 114 |  |
| 36 | `TextFormat-v5` | 77.5% | 100/129 | 129 | 128 |  |
| 37 | `XMLSocket-v6` | 77.1% | 27/35 | 35 | 35 |  |
| 38 | `AsBroadcaster-v6` | 76.9% | 93/121 | 121 | 121 |  |
| 39 | `Global-v8` | 75.7% | 128/169 | 169 | 169 |  |
| 40 | `Sound-v5` | 75.2% | 76/101 | 101 | 100 |  |
| 41 | `Accessibility-v5` | 75.0% | 12/16 | 16 | 15 |  |
| 42 | `XMLSocket-v5` | 72.2% | 26/36 | 36 | 35 |  |
| 43 | `XMLSocket-v7` | 72.2% | 26/36 | 36 | 35 |  |
| 44 | `XMLSocket-v8` | 72.2% | 26/36 | 36 | 35 |  |
| 45 | `Camera-v5` | 71.4% | 5/7 | 7 | 7 |  |
| 46 | `Error-v5` | 71.4% | 20/28 | 28 | 28 |  |
| 47 | `swap-v5` | 71.4% | 5/7 | 7 | 7 |  |
| 48 | `flash-v6` | 70.0% | 7/10 | 10 | 10 |  |
| 49 | `toString_valueOf-v7` | 69.9% | 109/156 | 156 | 155 |  |
| 50 | `targetPath-v5` | 69.2% | 9/13 | 13 | 12 |  |
| 51 | `toString_valueOf-v8` | 69.2% | 108/156 | 156 | 155 |  |
| 52 | `ExternalInterface-v8` | 68.1% | 81/119 | 119 | 118 |  |
| 53 | `Error-v6` | 67.7% | 21/31 | 31 | 31 |  |
| 54 | `MovieClipLoader-v6` | 66.7% | 4/6 | 6 | 6 |  |
| 55 | `AsBroadcaster-v7` | 66.4% | 81/122 | 122 | 121 |  |
| 56 | `AsBroadcaster-v8` | 65.6% | 80/122 | 122 | 121 |  |
| 57 | `Rectangle-v8` | 64.7% | 108/167 | 167 | 166 |  |
| 58 | `Error-v7` | 64.5% | 20/31 | 31 | 31 |  |
| 59 | `Error-v8` | 64.5% | 20/31 | 31 | 31 |  |
| 60 | `ContextMenu-v7` | 64.1% | 84/131 | 131 | 131 |  |
| 61 | `ContextMenu-v8` | 64.1% | 84/131 | 131 | 131 |  |
| 62 | `delete-v8` | 63.9% | 39/61 | 61 | 60 |  |
| 63 | `Instance-v6` | 63.5% | 33/52 | 52 | 52 |  |
| 64 | `delete-v6` | 63.3% | 38/60 | 60 | 60 |  |
| 65 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 66 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 67 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 68 | `delete-v7` | 62.3% | 38/61 | 61 | 60 |  |
| 69 | `TextFormat-v7` | 60.6% | 106/175 | 175 | 174 |  |
| 70 | `delete-v5` | 59.0% | 36/61 | 61 | 60 |  |
| 71 | `ColorTransform-v8` | 58.9% | 33/56 | 56 | 55 |  |
| 72 | `Instance-v5` | 58.5% | 31/53 | 53 | 52 |  |
| 73 | `Instance-v7` | 58.5% | 31/53 | 53 | 52 |  |
| 74 | `AsBroadcaster-v5` | 58.3% | 7/12 | 12 | 11 |  |
| 75 | `TextField-v5` | 58.3% | 7/12 | 12 | 12 |  |
| 76 | `Mouse-v6` | 57.1% | 12/21 | 21 | 21 |  |
| 77 | `Transform-v6` | 57.1% | 4/7 | 7 | 7 |  |
| 78 | `swap-v7` | 57.1% | 4/7 | 7 | 7 |  |
| 79 | `swap-v8` | 57.1% | 4/7 | 7 | 7 |  |
| 80 | `LoadVars-v5` | 55.6% | 5/9 | 9 | 8 |  |
| 81 | `flash-v5` | 54.5% | 6/11 | 11 | 10 |  |
| 82 | `flash-v7` | 54.5% | 6/11 | 11 | 10 |  |
| 83 | `Microphone-v6` | 54.4% | 43/79 | 79 | 79 |  |
| 84 | `Microphone-v7` | 53.2% | 42/79 | 79 | 79 |  |
| 85 | `Microphone-v8` | 53.2% | 42/79 | 79 | 79 |  |
| 86 | `Accessibility-v6` | 52.6% | 10/19 | 19 | 19 |  |
| 87 | `ExternalInterface-v6` | 50.9% | 28/55 | 55 | 55 |  |
| 88 | `BitmapData-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 89 | `BitmapData-v7` | 50.0% | 4/8 | 8 | 7 |  |
| 90 | `ColorTransform-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 91 | `ColorTransform-v7` | 50.0% | 4/8 | 8 | 7 |  |
| 92 | `ContextMenu-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 93 | `ExternalInterface-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 94 | `Matrix-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 95 | `Microphone-v5` | 50.0% | 3/6 | 6 | 6 |  |
| 96 | `Mouse-v5` | 50.0% | 7/14 | 14 | 13 |  |
| 97 | `Mouse-v7` | 50.0% | 11/22 | 22 | 21 |  |
| 98 | `MovieClipLoader-v5` | 50.0% | 3/6 | 6 | 6 |  |
| 99 | `Point-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 100 | `Point-v7` | 50.0% | 4/8 | 8 | 7 |  |
| 101 | `Rectangle-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 102 | `Rectangle-v7` | 50.0% | 4/8 | 8 | 7 |  |
| 103 | `TextSnapshot-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 104 | `Transform-v5` | 50.0% | 4/8 | 8 | 7 |  |
| 105 | `Instance-v8` | 49.1% | 26/53 | 53 | 52 |  |
| 106 | `ExternalInterface-v7` | 48.2% | 27/56 | 56 | 55 |  |
| 107 | `Mouse-v8` | 45.5% | 10/22 | 22 | 21 |  |
| 108 | `Accessibility-v7` | 45.0% | 9/20 | 20 | 19 |  |
| 109 | `NetStream-v5` | 42.9% | 3/7 | 7 | 6 |  |
| 110 | `TextFieldHTML-v5` | 42.9% | 3/7 | 7 | 6 |  |
| 111 | `enumerate-v5` | 42.9% | 3/7 | 7 | 6 |  |
| 112 | `Accessibility-v8` | 40.0% | 8/20 | 20 | 19 |  |
| 113 | `enumerate-v6` | 38.8% | 19/49 | 49 | 49 |  |
| 114 | `LoadVars-v6` | 37.5% | 57/152 | 117 | 152 |  |
| 115 | `LoadVars-v7` | 37.5% | 57/152 | 117 | 152 |  |
| 116 | `LoadVars-v8` | 37.5% | 57/152 | 117 | 152 |  |
| 117 | `LocalConnection-v5` | 37.5% | 3/8 | 8 | 7 |  |
| 118 | `NetConnection-v5` | 37.5% | 3/8 | 8 | 7 |  |
| 119 | `Transform-v7` | 37.5% | 3/8 | 8 | 7 |  |
| 120 | `Video-v5` | 37.5% | 3/8 | 8 | 7 |  |
| 121 | `System-v5` | 36.8% | 25/68 | 68 | 67 |  |
| 122 | `Camera-v6` | 36.7% | 33/90 | 90 | 90 |  |
| 123 | `enumerate-v7` | 36.0% | 18/50 | 50 | 49 |  |
| 124 | `enumerate-v8` | 36.0% | 18/50 | 50 | 49 |  |
| 125 | `Camera-v7` | 35.6% | 32/90 | 90 | 90 |  |
| 126 | `Camera-v8` | 35.6% | 32/90 | 90 | 90 |  |
| 127 | `LocalConnection-v6` | 34.5% | 20/58 | 58 | 58 |  |
| 128 | `LocalConnection-v7` | 32.2% | 19/59 | 59 | 58 |  |
| 129 | `LocalConnection-v8` | 32.2% | 19/59 | 59 | 58 |  |
| 130 | `targetPath-v6` | 32.1% | 9/28 | 28 | 23 |  |
| 131 | `targetPath-v7` | 31.0% | 9/29 | 29 | 23 |  |
| 132 | `targetPath-v8` | 31.0% | 9/29 | 29 | 23 |  |
| 133 | `System-v6` | 28.0% | 28/100 | 100 | 100 |  |
| 134 | `ASnative-v5` | 26.9% | 29/108 | 108 | 107 |  |
| 135 | `System-v7` | 26.5% | 27/102 | 102 | 101 |  |
| 136 | `System-v8` | 26.5% | 27/102 | 102 | 101 |  |
| 137 | `ASnative-v6` | 25.5% | 28/110 | 110 | 110 |  |
| 138 | `Key-v6` | 25.5% | 14/55 | 55 | 55 |  |
| 139 | `ASnative-v8` | 25.2% | 28/111 | 111 | 110 |  |
| 140 | `ASnative-v7` | 24.3% | 27/111 | 111 | 110 |  |
| 141 | `Key-v7` | 23.6% | 13/55 | 55 | 55 |  |
| 142 | `Key-v8` | 23.6% | 13/55 | 55 | 55 |  |
| 143 | `MovieClipLoader-v7` | 23.6% | 39/165 | 47 | 165 |  |
| 144 | `MovieClipLoader-v8` | 23.6% | 39/165 | 47 | 165 |  |
| 145 | `Key-v5` | 17.6% | 9/51 | 51 | 51 |  |
