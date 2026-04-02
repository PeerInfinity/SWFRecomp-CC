# Ruffle Test Results (Filtered)

**Date**: 2026-04-02 18:56 UTC

**Git SHA**: `4521f069f0`

**Run Duration**: 65m 37s

**Filtered**: 9 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 181 |
| Passing | **5** (2.8%) |
| Failing | 176 |
| Total expected lines | 15444 |
| Matching lines | 2645 (17.1%) |
| Mismatched lines | 12799 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 176 | 100.0% |

## Passing Tests

**5 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Stage-v5` | 38 | 18.3s |  |
| 2 | `Video-v6` | 85 | 19.1s |  |
| 3 | `XMLSocket-v5` | 35 | 18.8s |  |
| 4 | `XMLSocket-v6` | 35 | 18.1s |  |
| 5 | `case-v5` | 39 | 18.2s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**31 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `ExternalInterface-v8` | 95.8% | 113 | 118 | 5 |  |
| 2 | `NetStream-v7` | 95.0% | 76 | 80 | 4 |  |
| 3 | `NetStream-v8` | 95.0% | 76 | 80 | 4 |  |
| 4 | `Key-v5` | 92.2% | 47 | 51 | 4 |  |
| 5 | `Selection-v7` | 88.0% | 110 | 125 | 15 |  |
| 6 | `Selection-v8` | 88.0% | 110 | 125 | 15 |  |
| 7 | `Selection-v6` | 87.2% | 109 | 125 | 16 |  |
| 8 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 9 | `toString_valueOf-v7` | 85.8% | 133 | 155 | 22 |  |
| 10 | `toString_valueOf-v8` | 85.8% | 133 | 155 | 22 |  |
| 11 | `System-v7` | 82.2% | 83 | 101 | 18 |  |
| 12 | `System-v8` | 82.2% | 83 | 101 | 18 |  |
| 13 | `System-v6` | 82.0% | 82 | 100 | 18 |  |
| 14 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 15 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 16 | `argstest-v5` | 75.0% | 3 | 4 | 1 |  |
| 17 | `AsBroadcaster-v7` | 71.1% | 86 | 121 | 35 |  |
| 18 | `AsBroadcaster-v8` | 71.1% | 86 | 121 | 35 |  |
| 19 | `delete-v8` | 66.7% | 40 | 60 | 20 |  |
| 20 | `delete-v7` | 65.0% | 39 | 60 | 21 |  |
| 21 | `delete-v6` | 63.3% | 38 | 60 | 22 |  |
| 22 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 23 | `delete-v5` | 61.7% | 37 | 60 | 23 |  |
| 24 | `Microphone-v6` | 60.8% | 48 | 79 | 31 |  |
| 25 | `Instance-v5` | 59.6% | 31 | 52 | 21 |  |
| 26 | `Microphone-v5` | 50.0% | 3 | 6 | 3 |  |
| 27 | `MovieClipLoader-v5` | 50.0% | 3 | 6 | 3 |  |
| 28 | `MovieClipLoader-v6` | 50.0% | 3 | 6 | 3 |  |
| 29 | `NetStream-v5` | 50.0% | 3 | 6 | 3 |  |
| 30 | `TextFieldHTML-v5` | 50.0% | 3 | 6 | 3 |  |
| 31 | `enumerate-v5` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**176 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `ExternalInterface-v8` | 95.8% | 113/118 | 118 | 118 |  |
| 2 | `NetStream-v7` | 95.0% | 76/80 | 80 | 80 |  |
| 3 | `NetStream-v8` | 95.0% | 76/80 | 80 | 80 |  |
| 4 | `Key-v5` | 92.2% | 47/51 | 51 | 51 |  |
| 5 | `Selection-v7` | 88.0% | 110/125 | 125 | 125 |  |
| 6 | `Selection-v8` | 88.0% | 110/125 | 125 | 125 |  |
| 7 | `Selection-v6` | 87.2% | 109/125 | 125 | 125 |  |
| 8 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 9 | `toString_valueOf-v7` | 85.8% | 133/155 | 155 | 155 |  |
| 10 | `toString_valueOf-v8` | 85.8% | 133/155 | 155 | 155 |  |
| 11 | `System-v7` | 82.2% | 83/101 | 101 | 101 |  |
| 12 | `System-v8` | 82.2% | 83/101 | 101 | 101 |  |
| 13 | `System-v6` | 82.0% | 82/100 | 100 | 100 |  |
| 14 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 15 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 16 | `argstest-v5` | 75.0% | 3/4 | 3 | 4 |  |
| 17 | `AsBroadcaster-v7` | 71.1% | 86/121 | 121 | 121 |  |
| 18 | `AsBroadcaster-v8` | 71.1% | 86/121 | 121 | 121 |  |
| 19 | `delete-v8` | 66.7% | 40/60 | 60 | 60 |  |
| 20 | `delete-v7` | 65.0% | 39/60 | 60 | 60 |  |
| 21 | `delete-v6` | 63.3% | 38/60 | 60 | 60 |  |
| 22 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 23 | `delete-v5` | 61.7% | 37/60 | 60 | 60 |  |
| 24 | `Microphone-v6` | 60.8% | 48/79 | 79 | 79 |  |
| 25 | `Instance-v5` | 59.6% | 31/52 | 52 | 52 |  |
| 26 | `Microphone-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 27 | `MovieClipLoader-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 28 | `MovieClipLoader-v6` | 50.0% | 3/6 | 3 | 6 |  |
| 29 | `NetStream-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 30 | `TextFieldHTML-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 31 | `enumerate-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 32 | `AsBroadcaster-v5` | 45.5% | 5/11 | 5 | 11 |  |
| 33 | `enumerate-v6` | 44.9% | 22/49 | 49 | 49 |  |
| 34 | `BitmapData-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 35 | `BitmapData-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 36 | `BitmapData-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 37 | `Camera-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 38 | `ColorTransform-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 39 | `ColorTransform-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 40 | `ColorTransform-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 41 | `ContextMenu-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 42 | `ContextMenu-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 43 | `ExternalInterface-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 44 | `LocalConnection-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 45 | `Matrix-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 46 | `NetConnection-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 47 | `Point-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 48 | `Point-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 49 | `Point-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 50 | `Rectangle-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 51 | `Rectangle-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 52 | `Rectangle-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 53 | `TextSnapshot-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 54 | `Transform-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 55 | `Transform-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 56 | `Transform-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 57 | `Video-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 58 | `swap-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 59 | `swap-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 60 | `swap-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 61 | `swap-v8` | 42.9% | 3/7 | 3 | 7 |  |
| 62 | `LocalConnection-v6` | 41.4% | 24/58 | 58 | 58 |  |
| 63 | `LocalConnection-v7` | 41.4% | 24/58 | 58 | 58 |  |
| 64 | `LocalConnection-v8` | 41.4% | 24/58 | 58 | 58 |  |
| 65 | `LoadVars-v5` | 37.5% | 3/8 | 3 | 8 |  |
| 66 | `Camera-v6` | 36.7% | 33/90 | 90 | 90 |  |
| 67 | `flash-v5` | 30.0% | 3/10 | 3 | 10 |  |
| 68 | `flash-v6` | 30.0% | 3/10 | 3 | 10 |  |
| 69 | `flash-v7` | 30.0% | 3/10 | 3 | 10 |  |
| 70 | `with-v5` | 30.0% | 21/70 | 70 | 49 |  |
| 71 | `TextField-v5` | 25.0% | 3/12 | 3 | 12 |  |
| 72 | `targetPath-v5` | 25.0% | 3/12 | 3 | 12 |  |
| 73 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 74 | `Mouse-v5` | 23.1% | 3/13 | 3 | 13 |  |
| 75 | `Accessibility-v5` | 20.0% | 3/15 | 3 | 15 |  |
| 76 | `Selection-v5` | 19.0% | 4/21 | 4 | 21 |  |
| 77 | `Accessibility-v6` | 15.8% | 3/19 | 3 | 19 |  |
| 78 | `Accessibility-v7` | 15.8% | 3/19 | 3 | 19 |  |
| 79 | `Accessibility-v8` | 15.8% | 3/19 | 3 | 19 |  |
| 80 | `Try-v5` | 15.0% | 3/20 | 4 | 20 |  |
| 81 | `Try-v6` | 15.0% | 3/20 | 4 | 20 |  |
| 82 | `Try-v7` | 15.0% | 3/20 | 4 | 20 |  |
| 83 | `Try-v8` | 15.0% | 3/20 | 4 | 20 |  |
| 84 | `Mouse-v6` | 14.3% | 3/21 | 3 | 21 |  |
| 85 | `Mouse-v7` | 14.3% | 3/21 | 3 | 21 |  |
| 86 | `Mouse-v8` | 14.3% | 3/21 | 3 | 21 |  |
| 87 | `targetPath-v6` | 13.0% | 3/23 | 8 | 23 |  |
| 88 | `targetPath-v7` | 13.0% | 3/23 | 8 | 23 |  |
| 89 | `targetPath-v8` | 13.0% | 3/23 | 8 | 23 |  |
| 90 | `Random-v5` | 10.0% | 3/30 | 3 | 30 |  |
| 91 | `Random-v6` | 10.0% | 3/30 | 3 | 30 |  |
| 92 | `Random-v7` | 10.0% | 3/30 | 3 | 30 |  |
| 93 | `Random-v8` | 10.0% | 3/30 | 3 | 30 |  |
| 94 | `XMLSocket-v7` | 8.6% | 3/35 | 3 | 35 |  |
| 95 | `XMLSocket-v8` | 8.6% | 3/35 | 3 | 35 |  |
| 96 | `TextFieldHTML-v7` | 8.1% | 3/37 | 3 | 37 |  |
| 97 | `TextFieldHTML-v8` | 8.1% | 3/37 | 3 | 37 |  |
| 98 | `Boolean-v5` | 7.9% | 3/38 | 3 | 38 |  |
| 99 | `Boolean-v6` | 7.9% | 3/38 | 3 | 38 |  |
| 100 | `Boolean-v7` | 7.9% | 3/38 | 3 | 38 |  |
| 101 | `Boolean-v8` | 7.9% | 3/38 | 3 | 38 |  |
| 102 | `enumerate-v7` | 6.1% | 3/49 | 3 | 49 |  |
| 103 | `enumerate-v8` | 6.1% | 3/49 | 3 | 49 |  |
| 104 | `Instance-v6` | 5.8% | 3/52 | 3 | 52 |  |
| 105 | `Instance-v7` | 5.8% | 3/52 | 3 | 52 |  |
| 106 | `Instance-v8` | 5.8% | 3/52 | 3 | 52 |  |
| 107 | `ColorTransform-v8` | 5.5% | 3/55 | 3 | 55 |  |
| 108 | `ExternalInterface-v6` | 5.5% | 3/55 | 3 | 55 |  |
| 109 | `ExternalInterface-v7` | 5.5% | 3/55 | 3 | 55 |  |
| 110 | `Key-v6` | 5.5% | 3/55 | 3 | 55 |  |
| 111 | `Key-v7` | 5.5% | 3/55 | 3 | 55 |  |
| 112 | `Key-v8` | 5.5% | 3/55 | 3 | 55 |  |
| 113 | `System-v5` | 4.5% | 3/67 | 5 | 67 |  |
| 114 | `case-v7` | 4.5% | 3/67 | 6 | 67 |  |
| 115 | `case-v8` | 4.5% | 3/67 | 6 | 67 |  |
| 116 | `Microphone-v7` | 3.8% | 3/79 | 3 | 79 |  |
| 117 | `Microphone-v8` | 3.8% | 3/79 | 3 | 79 |  |
| 118 | `NetStream-v6` | 3.8% | 3/80 | 3 | 80 |  |
| 119 | `Video-v7` | 3.5% | 3/85 | 3 | 85 |  |
| 120 | `Video-v8` | 3.5% | 3/85 | 3 | 85 |  |
| 121 | `HitTest-v6` | 3.4% | 3/88 | 3 | 88 |  |
| 122 | `Camera-v7` | 3.3% | 3/90 | 4 | 90 |  |
| 123 | `Camera-v8` | 3.3% | 3/90 | 4 | 90 |  |
| 124 | `Sound-v5` | 3.0% | 3/100 | 3 | 100 |  |
| 125 | `ASnative-v5` | 2.8% | 3/107 | 3 | 107 |  |
| 126 | `with-v6` | 2.8% | 3/107 | 22 | 107 |  |
| 127 | `with-v7` | 2.8% | 3/107 | 22 | 107 |  |
| 128 | `with-v8` | 2.8% | 3/107 | 22 | 107 |  |
| 129 | `ASnative-v6` | 2.7% | 3/110 | 3 | 110 |  |
| 130 | `ASnative-v7` | 2.7% | 3/110 | 3 | 110 |  |
| 131 | `ASnative-v8` | 2.7% | 3/110 | 3 | 110 |  |
| 132 | `Inheritance-v5` | 2.6% | 3/114 | 5 | 114 |  |
| 133 | `AsBroadcaster-v6` | 2.5% | 3/121 | 3 | 121 |  |
| 134 | `Sound-v7` | 2.5% | 3/121 | 4 | 121 |  |
| 135 | `Sound-v8` | 2.5% | 3/121 | 4 | 121 |  |
| 136 | `TextFormat-v5` | 2.3% | 3/128 | 3 | 128 |  |
| 137 | `TextFormat-v6` | 2.3% | 3/128 | 3 | 128 |  |
| 138 | `ContextMenu-v7` | 2.3% | 3/131 | 4 | 131 |  |
| 139 | `ContextMenu-v8` | 2.3% | 3/131 | 4 | 131 |  |
| 140 | `toString_valueOf-v5` | 2.2% | 3/137 | 3 | 137 |  |
| 141 | `Color-v5` | 2.1% | 3/140 | 3 | 140 |  |
| 142 | `LoadVars-v6` | 2.0% | 3/152 | 3 | 152 |  |
| 143 | `LoadVars-v7` | 2.0% | 3/152 | 3 | 152 |  |
| 144 | `LoadVars-v8` | 2.0% | 3/152 | 3 | 152 |  |
| 145 | `toString_valueOf-v6` | 1.9% | 3/155 | 3 | 155 |  |
| 146 | `Color-v7` | 1.9% | 3/161 | 3 | 161 |  |
| 147 | `Color-v8` | 1.9% | 3/161 | 3 | 161 |  |
| 148 | `MovieClipLoader-v7` | 1.8% | 3/165 | 3 | 165 |  |
| 149 | `MovieClipLoader-v8` | 1.8% | 3/165 | 3 | 165 |  |
| 150 | `Rectangle-v8` | 1.8% | 3/166 | 3 | 166 |  |
| 151 | `Matrix-v6` | 1.8% | 3/168 | 3 | 168 |  |
| 152 | `Matrix-v7` | 1.8% | 3/168 | 3 | 168 |  |
| 153 | `Matrix-v8` | 1.8% | 3/168 | 3 | 168 |  |
| 154 | `Global-v8` | 1.8% | 3/169 | 3 | 169 |  |
| 155 | `Color-v6` | 1.8% | 3/171 | 3 | 171 |  |
| 156 | `TextSnapshot-v6` | 1.7% | 3/173 | 3 | 173 |  |
| 157 | `TextSnapshot-v7` | 1.7% | 3/173 | 3 | 173 |  |
| 158 | `TextSnapshot-v8` | 1.7% | 3/173 | 3 | 173 |  |
| 159 | `TextFormat-v7` | 1.7% | 3/174 | 3 | 174 |  |
| 160 | `Inheritance-v6` | 1.7% | 3/181 | 5 | 181 |  |
| 161 | `Inheritance-v7` | 1.7% | 3/181 | 5 | 181 |  |
| 162 | `Inheritance-v8` | 1.7% | 3/181 | 5 | 181 |  |
| 163 | `Global-v7` | 1.6% | 3/182 | 3 | 182 |  |
| 164 | `Point-v8` | 1.6% | 3/193 | 3 | 193 |  |
| 165 | `Global-v6` | 1.4% | 3/210 | 3 | 210 |  |
| 166 | `Number-v7` | 1.3% | 3/237 | 3 | 237 |  |
| 167 | `Number-v8` | 1.3% | 3/237 | 3 | 237 |  |
| 168 | `Number-v6` | 1.3% | 3/239 | 3 | 239 |  |
| 169 | `Number-v5` | 1.2% | 3/244 | 3 | 244 |  |
| 170 | `String-v5` | 0.8% | 3/358 | 3 | 358 |  |
| 171 | `MovieClip-v5` | 0.8% | 3/363 | 3 | 363 |  |
| 172 | `String-v6` | 0.8% | 3/377 | 3 | 377 |  |
| 173 | `String-v7` | 0.8% | 3/377 | 3 | 377 |  |
| 174 | `String-v8` | 0.8% | 3/377 | 3 | 377 |  |
| 175 | `BitmapData-v8` | 0.7% | 3/417 | 4 | 417 |  |
| 176 | `array-v5` | 0.5% | 3/560 | 5 | 560 |  |
