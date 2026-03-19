# Ruffle Test Results (Unfiltered)

**Date**: 2026-03-18 04:04 UTC

**Git SHA**: `ef1e80b3a4`

**Run Duration**: 56m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 190 |
| Passing | **38** (20.0%) |
| Failing | 152 |
| Total expected lines | 9439 |
| Matching lines | 5696 (60.3%) |
| Mismatched lines | 3743 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 108 | 71.1% |
| Compile Fail | 31 | 20.4% |
| Runtime Segfault | 13 | 8.6% |

## Passing Tests

**38 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 16.2s |  |
| 2 | `BitmapData-v5` | 7 | 16.1s |  |
| 3 | `BitmapData-v6` | 7 | 16.1s |  |
| 4 | `BitmapData-v7` | 7 | 16.1s |  |
| 5 | `Boolean-v5` | 38 | 16.5s |  |
| 6 | `Camera-v5` | 7 | 16.5s |  |
| 7 | `ColorTransform-v5` | 7 | 16.8s |  |
| 8 | `ColorTransform-v6` | 7 | 17.0s |  |
| 9 | `ColorTransform-v7` | 7 | 16.9s |  |
| 10 | `ContextMenu-v5` | 7 | 16.7s |  |
| 11 | `ContextMenu-v6` | 7 | 16.7s |  |
| 12 | `ExternalInterface-v5` | 7 | 16.1s |  |
| 13 | `LoadVars-v5` | 8 | 16.2s |  |
| 14 | `Matrix-v5` | 7 | 16.3s |  |
| 15 | `Microphone-v5` | 6 | 15.8s |  |
| 16 | `MovieClipLoader-v5` | 6 | 16.0s |  |
| 17 | `MovieClipLoader-v6` | 6 | 15.9s |  |
| 18 | `NetStream-v5` | 6 | 15.9s |  |
| 19 | `Point-v5` | 7 | 16.0s |  |
| 20 | `Point-v6` | 7 | 16.0s |  |
| 21 | `Point-v7` | 7 | 16.0s |  |
| 22 | `Random-v5` | 30 | 16.5s |  |
| 23 | `Random-v6` | 30 | 16.4s |  |
| 24 | `Random-v7` | 30 | 16.3s |  |
| 25 | `Random-v8` | 30 | 16.4s |  |
| 26 | `Rectangle-v5` | 7 | 15.9s |  |
| 27 | `Rectangle-v6` | 7 | 16.0s |  |
| 28 | `Rectangle-v7` | 7 | 16.0s |  |
| 29 | `TextFieldHTML-v5` | 6 | 17.3s |  |
| 30 | `TextSnapshot-v5` | 7 | 16.0s |  |
| 31 | `Transform-v5` | 7 | 16.1s |  |
| 32 | `argstest-v5` | 4 | 16.3s |  |
| 33 | `enumerate-v5` | 6 | 16.2s |  |
| 34 | `swap-v5` | 7 | 17.4s |  |
| 35 | `swap-v6` | 7 | 17.4s |  |
| 36 | `swap-v7` | 7 | 17.2s |  |
| 37 | `swap-v8` | 7 | 17.3s |  |
| 38 | `targetPath-v5` | 12 | 17.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**78 tests** within reach

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
| 10 | `Stage-v5` | 86.8% | 33 | 38 | 5 |  |
| 11 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 12 | `TextFieldHTML-v7` | 86.5% | 32 | 37 | 5 |  |
| 13 | `TextFieldHTML-v8` | 86.5% | 32 | 37 | 5 |  |
| 14 | `Selection-v7` | 86.4% | 108 | 125 | 17 |  |
| 15 | `Selection-v8` | 86.4% | 108 | 125 | 17 |  |
| 16 | `Selection-v5` | 85.7% | 18 | 21 | 3 |  |
| 17 | `Selection-v6` | 85.6% | 107 | 125 | 18 |  |
| 18 | `Color-v5` | 82.9% | 116 | 140 | 24 |  |
| 19 | `Color-v7` | 82.6% | 133 | 161 | 28 |  |
| 20 | `Color-v8` | 82.6% | 133 | 161 | 28 |  |
| 21 | `Inheritance-v6` | 81.3% | 148 | 182 | 34 |  |
| 22 | `Color-v6` | 81.3% | 139 | 171 | 32 |  |
| 23 | `Inheritance-v5` | 80.9% | 93 | 115 | 22 |  |
| 24 | `TextFormat-v5` | 78.9% | 101 | 128 | 27 |  |
| 25 | `TextFormat-v6` | 78.9% | 101 | 128 | 27 |  |
| 26 | `XMLSocket-v5` | 77.1% | 27 | 35 | 8 |  |
| 27 | `XMLSocket-v6` | 77.1% | 27 | 35 | 8 |  |
| 28 | `XMLSocket-v7` | 77.1% | 27 | 35 | 8 |  |
| 29 | `XMLSocket-v8` | 77.1% | 27 | 35 | 8 |  |
| 30 | `Sound-v5` | 77.0% | 77 | 100 | 23 |  |
| 31 | `AsBroadcaster-v6` | 76.9% | 93 | 121 | 28 |  |
| 32 | `Global-v8` | 75.7% | 128 | 169 | 41 |  |
| 33 | `Error-v5` | 75.0% | 21 | 28 | 7 |  |
| 34 | `AsBroadcaster-v5` | 72.7% | 8 | 11 | 3 |  |
| 35 | `toString_valueOf-v7` | 71.0% | 110 | 155 | 45 |  |
| 36 | `toString_valueOf-v8` | 70.3% | 109 | 155 | 46 |  |
| 37 | `flash-v5` | 70.0% | 7 | 10 | 3 |  |
| 38 | `flash-v6` | 70.0% | 7 | 10 | 3 |  |
| 39 | `flash-v7` | 70.0% | 7 | 10 | 3 |  |
| 40 | `ExternalInterface-v8` | 69.5% | 82 | 118 | 36 |  |
| 41 | `AsBroadcaster-v7` | 67.8% | 82 | 121 | 39 |  |
| 42 | `Error-v6` | 67.7% | 21 | 31 | 10 |  |
| 43 | `Error-v7` | 67.7% | 21 | 31 | 10 |  |
| 44 | `Error-v8` | 67.7% | 21 | 31 | 10 |  |
| 45 | `AsBroadcaster-v8` | 66.9% | 81 | 121 | 40 |  |
| 46 | `TextField-v5` | 66.7% | 8 | 12 | 4 |  |
| 47 | `delete-v8` | 66.7% | 40 | 60 | 20 |  |
| 48 | `Rectangle-v8` | 65.7% | 109 | 166 | 57 |  |
| 49 | `delete-v7` | 65.0% | 39 | 60 | 21 |  |
| 50 | `ContextMenu-v7` | 64.1% | 84 | 131 | 47 |  |
| 51 | `ContextMenu-v8` | 64.1% | 84 | 131 | 47 |  |
| 52 | `Instance-v6` | 63.5% | 33 | 52 | 19 |  |
| 53 | `delete-v6` | 63.3% | 38 | 60 | 22 |  |
| 54 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 55 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 56 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 57 | `ColorTransform-v8` | 61.8% | 34 | 55 | 21 |  |
| 58 | `delete-v5` | 61.7% | 37 | 60 | 23 |  |
| 59 | `Instance-v5` | 61.5% | 32 | 52 | 20 |  |
| 60 | `Instance-v7` | 61.5% | 32 | 52 | 20 |  |
| 61 | `Mouse-v5` | 61.5% | 8 | 13 | 5 |  |
| 62 | `TextFormat-v7` | 61.5% | 107 | 174 | 67 |  |
| 63 | `LocalConnection-v5` | 57.1% | 4 | 7 | 3 |  |
| 64 | `Mouse-v6` | 57.1% | 12 | 21 | 9 |  |
| 65 | `Mouse-v7` | 57.1% | 12 | 21 | 9 |  |
| 66 | `NetConnection-v5` | 57.1% | 4 | 7 | 3 |  |
| 67 | `Transform-v6` | 57.1% | 4 | 7 | 3 |  |
| 68 | `Transform-v7` | 57.1% | 4 | 7 | 3 |  |
| 69 | `Video-v5` | 57.1% | 4 | 7 | 3 |  |
| 70 | `Microphone-v6` | 54.4% | 43 | 79 | 36 |  |
| 71 | `Microphone-v7` | 54.4% | 43 | 79 | 36 |  |
| 72 | `Microphone-v8` | 54.4% | 43 | 79 | 36 |  |
| 73 | `Accessibility-v6` | 52.6% | 10 | 19 | 9 |  |
| 74 | `Accessibility-v7` | 52.6% | 10 | 19 | 9 |  |
| 75 | `Mouse-v8` | 52.4% | 11 | 21 | 10 |  |
| 76 | `Instance-v8` | 51.9% | 27 | 52 | 25 |  |
| 77 | `ExternalInterface-v6` | 50.9% | 28 | 55 | 27 |  |
| 78 | `ExternalInterface-v7` | 50.9% | 28 | 55 | 27 |  |

## Segfaults

**13 tests** crash with SIGSEGV

| # | Test | Duration | Notes |
|---|------|----------|-------|
| 1 | `HitTest-v6` | 21.0s |  |
| 2 | `HitTest-v7` | 21.3s |  |
| 3 | `HitTest-v8` | 21.0s |  |
| 4 | `Try-v5` | 19.3s |  |
| 5 | `Try-v6` | 19.6s |  |
| 6 | `Try-v7` | 19.4s |  |
| 7 | `Try-v8` | 19.4s |  |
| 8 | `case-v5` | 18.8s |  |
| 9 | `case-v6` | 19.9s |  |
| 10 | `case-v7` | 19.5s |  |
| 11 | `case-v8` | 19.5s |  |
| 12 | `toString_valueOf-v5` | 22.0s |  |
| 13 | `toString_valueOf-v6` | 22.6s |  |

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**108 tests** with output mismatch, sorted by match rate (best first)

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
| 10 | `Stage-v5` | 86.8% | 33/38 | 38 | 38 |  |
| 11 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 12 | `TextFieldHTML-v7` | 86.5% | 32/37 | 37 | 37 |  |
| 13 | `TextFieldHTML-v8` | 86.5% | 32/37 | 37 | 37 |  |
| 14 | `Selection-v7` | 86.4% | 108/125 | 125 | 125 |  |
| 15 | `Selection-v8` | 86.4% | 108/125 | 125 | 125 |  |
| 16 | `Selection-v5` | 85.7% | 18/21 | 21 | 21 |  |
| 17 | `Selection-v6` | 85.6% | 107/125 | 125 | 125 |  |
| 18 | `Color-v5` | 82.9% | 116/140 | 140 | 140 |  |
| 19 | `Color-v7` | 82.6% | 133/161 | 161 | 161 |  |
| 20 | `Color-v8` | 82.6% | 133/161 | 161 | 161 |  |
| 21 | `Inheritance-v6` | 81.3% | 148/182 | 182 | 181 |  |
| 22 | `Color-v6` | 81.3% | 139/171 | 171 | 171 |  |
| 23 | `Inheritance-v5` | 80.9% | 93/115 | 115 | 114 |  |
| 24 | `TextFormat-v5` | 78.9% | 101/128 | 128 | 128 |  |
| 25 | `TextFormat-v6` | 78.9% | 101/128 | 128 | 128 |  |
| 26 | `XMLSocket-v5` | 77.1% | 27/35 | 35 | 35 |  |
| 27 | `XMLSocket-v6` | 77.1% | 27/35 | 35 | 35 |  |
| 28 | `XMLSocket-v7` | 77.1% | 27/35 | 35 | 35 |  |
| 29 | `XMLSocket-v8` | 77.1% | 27/35 | 35 | 35 |  |
| 30 | `Sound-v5` | 77.0% | 77/100 | 100 | 100 |  |
| 31 | `AsBroadcaster-v6` | 76.9% | 93/121 | 121 | 121 |  |
| 32 | `Global-v8` | 75.7% | 128/169 | 168 | 169 |  |
| 33 | `Error-v5` | 75.0% | 21/28 | 28 | 28 |  |
| 34 | `AsBroadcaster-v5` | 72.7% | 8/11 | 11 | 11 |  |
| 35 | `toString_valueOf-v7` | 71.0% | 110/155 | 155 | 155 |  |
| 36 | `toString_valueOf-v8` | 70.3% | 109/155 | 155 | 155 |  |
| 37 | `flash-v5` | 70.0% | 7/10 | 10 | 10 |  |
| 38 | `flash-v6` | 70.0% | 7/10 | 10 | 10 |  |
| 39 | `flash-v7` | 70.0% | 7/10 | 10 | 10 |  |
| 40 | `ExternalInterface-v8` | 69.5% | 82/118 | 118 | 118 |  |
| 41 | `AsBroadcaster-v7` | 67.8% | 82/121 | 121 | 121 |  |
| 42 | `Error-v6` | 67.7% | 21/31 | 31 | 31 |  |
| 43 | `Error-v7` | 67.7% | 21/31 | 31 | 31 |  |
| 44 | `Error-v8` | 67.7% | 21/31 | 31 | 31 |  |
| 45 | `AsBroadcaster-v8` | 66.9% | 81/121 | 121 | 121 |  |
| 46 | `TextField-v5` | 66.7% | 8/12 | 12 | 12 |  |
| 47 | `delete-v8` | 66.7% | 40/60 | 60 | 60 |  |
| 48 | `Rectangle-v8` | 65.7% | 109/166 | 166 | 166 |  |
| 49 | `delete-v7` | 65.0% | 39/60 | 60 | 60 |  |
| 50 | `ContextMenu-v7` | 64.1% | 84/131 | 130 | 131 |  |
| 51 | `ContextMenu-v8` | 64.1% | 84/131 | 130 | 131 |  |
| 52 | `Instance-v6` | 63.5% | 33/52 | 52 | 52 |  |
| 53 | `delete-v6` | 63.3% | 38/60 | 60 | 60 |  |
| 54 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 55 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 56 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 57 | `ColorTransform-v8` | 61.8% | 34/55 | 55 | 55 |  |
| 58 | `delete-v5` | 61.7% | 37/60 | 60 | 60 |  |
| 59 | `Instance-v5` | 61.5% | 32/52 | 52 | 52 |  |
| 60 | `Instance-v7` | 61.5% | 32/52 | 52 | 52 |  |
| 61 | `Mouse-v5` | 61.5% | 8/13 | 13 | 13 |  |
| 62 | `TextFormat-v7` | 61.5% | 107/174 | 174 | 174 |  |
| 63 | `LocalConnection-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 64 | `Mouse-v6` | 57.1% | 12/21 | 21 | 21 |  |
| 65 | `Mouse-v7` | 57.1% | 12/21 | 21 | 21 |  |
| 66 | `NetConnection-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 67 | `Transform-v6` | 57.1% | 4/7 | 7 | 7 |  |
| 68 | `Transform-v7` | 57.1% | 4/7 | 7 | 7 |  |
| 69 | `Video-v5` | 57.1% | 4/7 | 7 | 7 |  |
| 70 | `Microphone-v6` | 54.4% | 43/79 | 79 | 79 |  |
| 71 | `Microphone-v7` | 54.4% | 43/79 | 79 | 79 |  |
| 72 | `Microphone-v8` | 54.4% | 43/79 | 79 | 79 |  |
| 73 | `Accessibility-v6` | 52.6% | 10/19 | 19 | 19 |  |
| 74 | `Accessibility-v7` | 52.6% | 10/19 | 19 | 19 |  |
| 75 | `Mouse-v8` | 52.4% | 11/21 | 21 | 21 |  |
| 76 | `Instance-v8` | 51.9% | 27/52 | 52 | 52 |  |
| 77 | `ExternalInterface-v6` | 50.9% | 28/55 | 55 | 55 |  |
| 78 | `ExternalInterface-v7` | 50.9% | 28/55 | 55 | 55 |  |
| 79 | `Accessibility-v8` | 47.4% | 9/19 | 19 | 19 |  |
| 80 | `System-v5` | 38.8% | 26/67 | 67 | 67 |  |
| 81 | `enumerate-v6` | 38.8% | 19/49 | 49 | 49 |  |
| 82 | `enumerate-v7` | 38.8% | 19/49 | 49 | 49 |  |
| 83 | `enumerate-v8` | 38.8% | 19/49 | 49 | 49 |  |
| 84 | `LoadVars-v6` | 37.5% | 57/152 | 117 | 152 |  |
| 85 | `LoadVars-v7` | 37.5% | 57/152 | 117 | 152 |  |
| 86 | `LoadVars-v8` | 37.5% | 57/152 | 117 | 152 |  |
| 87 | `Camera-v6` | 36.7% | 33/90 | 90 | 90 |  |
| 88 | `Camera-v7` | 36.7% | 33/90 | 90 | 90 |  |
| 89 | `Camera-v8` | 36.7% | 33/90 | 90 | 90 |  |
| 90 | `LocalConnection-v6` | 34.5% | 20/58 | 58 | 58 |  |
| 91 | `LocalConnection-v7` | 34.5% | 20/58 | 58 | 58 |  |
| 92 | `LocalConnection-v8` | 34.5% | 20/58 | 58 | 58 |  |
| 93 | `targetPath-v6` | 32.1% | 9/28 | 28 | 23 |  |
| 94 | `targetPath-v7` | 32.1% | 9/28 | 28 | 23 |  |
| 95 | `targetPath-v8` | 32.1% | 9/28 | 28 | 23 |  |
| 96 | `ASnative-v5` | 28.0% | 30/107 | 107 | 107 |  |
| 97 | `System-v6` | 28.0% | 28/100 | 100 | 100 |  |
| 98 | `System-v7` | 27.7% | 28/101 | 101 | 101 |  |
| 99 | `System-v8` | 27.7% | 28/101 | 101 | 101 |  |
| 100 | `ASnative-v8` | 26.4% | 29/110 | 110 | 110 |  |
| 101 | `ASnative-v6` | 25.5% | 28/110 | 110 | 110 |  |
| 102 | `ASnative-v7` | 25.5% | 28/110 | 110 | 110 |  |
| 103 | `Key-v6` | 25.5% | 14/55 | 55 | 55 |  |
| 104 | `Key-v7` | 25.5% | 14/55 | 55 | 55 |  |
| 105 | `Key-v8` | 25.5% | 14/55 | 55 | 55 |  |
| 106 | `MovieClipLoader-v7` | 23.6% | 39/165 | 47 | 165 |  |
| 107 | `MovieClipLoader-v8` | 23.6% | 39/165 | 47 | 165 |  |
| 108 | `Key-v5` | 19.6% | 10/51 | 51 | 51 |  |
