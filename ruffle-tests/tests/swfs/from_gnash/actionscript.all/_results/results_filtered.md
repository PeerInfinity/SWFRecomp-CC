# Ruffle Test Results (Filtered)

**Date**: 2026-04-02 20:20 UTC

**Git SHA**: `b8938ab392`

**Run Duration**: 65m 15s

**Filtered**: 9 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 181 |
| Passing | **5** (2.8%) |
| Failing | 176 |
| Total expected lines | 15444 |
| Matching lines | 1699 (11.0%) |
| Mismatched lines | 13745 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 176 | 100.0% |

## Passing Tests

**5 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Stage-v5` | 38 | 18.2s |  |
| 2 | `Video-v6` | 85 | 19.7s |  |
| 3 | `XMLSocket-v5` | 35 | 18.8s |  |
| 4 | `XMLSocket-v6` | 35 | 18.9s |  |
| 5 | `case-v5` | 39 | 18.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**20 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `Key-v5` | 92.2% | 47 | 51 | 4 |  |
| 2 | `Selection-v7` | 88.0% | 110 | 125 | 15 |  |
| 3 | `Selection-v8` | 88.0% | 110 | 125 | 15 |  |
| 4 | `Selection-v6` | 87.2% | 109 | 125 | 16 |  |
| 5 | `TextFieldHTML-v6` | 86.5% | 32 | 37 | 5 |  |
| 6 | `System-v6` | 82.0% | 82 | 100 | 18 |  |
| 7 | `argstest-v5` | 75.0% | 3 | 4 | 1 |  |
| 8 | `delete-v6` | 63.3% | 38 | 60 | 22 |  |
| 9 | `Sound-v6` | 62.8% | 76 | 121 | 45 |  |
| 10 | `Sound-v7` | 62.8% | 76 | 121 | 45 |  |
| 11 | `Sound-v8` | 62.8% | 76 | 121 | 45 |  |
| 12 | `delete-v5` | 61.7% | 37 | 60 | 23 |  |
| 13 | `Microphone-v6` | 60.8% | 48 | 79 | 31 |  |
| 14 | `Instance-v5` | 59.6% | 31 | 52 | 21 |  |
| 15 | `Microphone-v5` | 50.0% | 3 | 6 | 3 |  |
| 16 | `MovieClipLoader-v5` | 50.0% | 3 | 6 | 3 |  |
| 17 | `MovieClipLoader-v6` | 50.0% | 3 | 6 | 3 |  |
| 18 | `NetStream-v5` | 50.0% | 3 | 6 | 3 |  |
| 19 | `TextFieldHTML-v5` | 50.0% | 3 | 6 | 3 |  |
| 20 | `enumerate-v5` | 50.0% | 3 | 6 | 3 |  |

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
| 1 | `Key-v5` | 92.2% | 47/51 | 51 | 51 |  |
| 2 | `Selection-v7` | 88.0% | 110/125 | 125 | 125 |  |
| 3 | `Selection-v8` | 88.0% | 110/125 | 125 | 125 |  |
| 4 | `Selection-v6` | 87.2% | 109/125 | 125 | 125 |  |
| 5 | `TextFieldHTML-v6` | 86.5% | 32/37 | 37 | 37 |  |
| 6 | `System-v6` | 82.0% | 82/100 | 100 | 100 |  |
| 7 | `argstest-v5` | 75.0% | 3/4 | 3 | 4 |  |
| 8 | `delete-v6` | 63.3% | 38/60 | 60 | 60 |  |
| 9 | `Sound-v6` | 62.8% | 76/121 | 113 | 121 |  |
| 10 | `Sound-v7` | 62.8% | 76/121 | 113 | 121 |  |
| 11 | `Sound-v8` | 62.8% | 76/121 | 113 | 121 |  |
| 12 | `delete-v5` | 61.7% | 37/60 | 60 | 60 |  |
| 13 | `Microphone-v6` | 60.8% | 48/79 | 79 | 79 |  |
| 14 | `Instance-v5` | 59.6% | 31/52 | 52 | 52 |  |
| 15 | `Microphone-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 16 | `MovieClipLoader-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 17 | `MovieClipLoader-v6` | 50.0% | 3/6 | 3 | 6 |  |
| 18 | `NetStream-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 19 | `TextFieldHTML-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 20 | `enumerate-v5` | 50.0% | 3/6 | 3 | 6 |  |
| 21 | `AsBroadcaster-v5` | 45.5% | 5/11 | 5 | 11 |  |
| 22 | `enumerate-v6` | 44.9% | 22/49 | 49 | 49 |  |
| 23 | `BitmapData-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 24 | `BitmapData-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 25 | `BitmapData-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 26 | `Camera-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 27 | `ColorTransform-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 28 | `ColorTransform-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 29 | `ColorTransform-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 30 | `ContextMenu-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 31 | `ContextMenu-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 32 | `ExternalInterface-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 33 | `LocalConnection-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 34 | `Matrix-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 35 | `NetConnection-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 36 | `Point-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 37 | `Point-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 38 | `Point-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 39 | `Rectangle-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 40 | `Rectangle-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 41 | `Rectangle-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 42 | `TextSnapshot-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 43 | `Transform-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 44 | `Transform-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 45 | `Transform-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 46 | `Video-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 47 | `swap-v5` | 42.9% | 3/7 | 3 | 7 |  |
| 48 | `swap-v6` | 42.9% | 3/7 | 3 | 7 |  |
| 49 | `swap-v7` | 42.9% | 3/7 | 3 | 7 |  |
| 50 | `swap-v8` | 42.9% | 3/7 | 3 | 7 |  |
| 51 | `LocalConnection-v6` | 41.4% | 24/58 | 58 | 58 |  |
| 52 | `LoadVars-v5` | 37.5% | 3/8 | 3 | 8 |  |
| 53 | `Camera-v6` | 36.7% | 33/90 | 90 | 90 |  |
| 54 | `flash-v5` | 30.0% | 3/10 | 3 | 10 |  |
| 55 | `flash-v6` | 30.0% | 3/10 | 3 | 10 |  |
| 56 | `flash-v7` | 30.0% | 3/10 | 3 | 10 |  |
| 57 | `with-v5` | 30.0% | 21/70 | 70 | 49 |  |
| 58 | `TextField-v5` | 25.0% | 3/12 | 3 | 12 |  |
| 59 | `targetPath-v5` | 25.0% | 3/12 | 3 | 12 |  |
| 60 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 61 | `Mouse-v5` | 23.1% | 3/13 | 3 | 13 |  |
| 62 | `Accessibility-v5` | 20.0% | 3/15 | 3 | 15 |  |
| 63 | `Selection-v5` | 19.0% | 4/21 | 4 | 21 |  |
| 64 | `Accessibility-v6` | 15.8% | 3/19 | 3 | 19 |  |
| 65 | `Accessibility-v7` | 15.8% | 3/19 | 3 | 19 |  |
| 66 | `Accessibility-v8` | 15.8% | 3/19 | 3 | 19 |  |
| 67 | `Try-v5` | 15.0% | 3/20 | 4 | 20 |  |
| 68 | `Try-v6` | 15.0% | 3/20 | 4 | 20 |  |
| 69 | `Try-v7` | 15.0% | 3/20 | 4 | 20 |  |
| 70 | `Try-v8` | 15.0% | 3/20 | 4 | 20 |  |
| 71 | `Mouse-v6` | 14.3% | 3/21 | 3 | 21 |  |
| 72 | `Mouse-v7` | 14.3% | 3/21 | 3 | 21 |  |
| 73 | `Mouse-v8` | 14.3% | 3/21 | 3 | 21 |  |
| 74 | `targetPath-v6` | 13.0% | 3/23 | 8 | 23 |  |
| 75 | `targetPath-v7` | 13.0% | 3/23 | 8 | 23 |  |
| 76 | `targetPath-v8` | 13.0% | 3/23 | 8 | 23 |  |
| 77 | `Random-v5` | 10.0% | 3/30 | 3 | 30 |  |
| 78 | `Random-v6` | 10.0% | 3/30 | 3 | 30 |  |
| 79 | `Random-v7` | 10.0% | 3/30 | 3 | 30 |  |
| 80 | `Random-v8` | 10.0% | 3/30 | 3 | 30 |  |
| 81 | `XMLSocket-v7` | 8.6% | 3/35 | 3 | 35 |  |
| 82 | `XMLSocket-v8` | 8.6% | 3/35 | 3 | 35 |  |
| 83 | `TextFieldHTML-v7` | 8.1% | 3/37 | 3 | 37 |  |
| 84 | `TextFieldHTML-v8` | 8.1% | 3/37 | 3 | 37 |  |
| 85 | `Boolean-v5` | 7.9% | 3/38 | 3 | 38 |  |
| 86 | `Boolean-v6` | 7.9% | 3/38 | 3 | 38 |  |
| 87 | `Boolean-v7` | 7.9% | 3/38 | 3 | 38 |  |
| 88 | `Boolean-v8` | 7.9% | 3/38 | 3 | 38 |  |
| 89 | `enumerate-v7` | 6.1% | 3/49 | 3 | 49 |  |
| 90 | `enumerate-v8` | 6.1% | 3/49 | 3 | 49 |  |
| 91 | `Instance-v6` | 5.8% | 3/52 | 3 | 52 |  |
| 92 | `Instance-v7` | 5.8% | 3/52 | 3 | 52 |  |
| 93 | `Instance-v8` | 5.8% | 3/52 | 3 | 52 |  |
| 94 | `ColorTransform-v8` | 5.5% | 3/55 | 3 | 55 |  |
| 95 | `ExternalInterface-v6` | 5.5% | 3/55 | 3 | 55 |  |
| 96 | `ExternalInterface-v7` | 5.5% | 3/55 | 3 | 55 |  |
| 97 | `Key-v6` | 5.5% | 3/55 | 3 | 55 |  |
| 98 | `Key-v7` | 5.5% | 3/55 | 3 | 55 |  |
| 99 | `Key-v8` | 5.5% | 3/55 | 3 | 55 |  |
| 100 | `LocalConnection-v7` | 5.2% | 3/58 | 3 | 58 |  |
| 101 | `LocalConnection-v8` | 5.2% | 3/58 | 3 | 58 |  |
| 102 | `delete-v7` | 5.0% | 3/60 | 3 | 60 |  |
| 103 | `delete-v8` | 5.0% | 3/60 | 3 | 60 |  |
| 104 | `System-v5` | 4.5% | 3/67 | 5 | 67 |  |
| 105 | `case-v7` | 4.5% | 3/67 | 6 | 67 |  |
| 106 | `case-v8` | 4.5% | 3/67 | 6 | 67 |  |
| 107 | `Microphone-v7` | 3.8% | 3/79 | 3 | 79 |  |
| 108 | `Microphone-v8` | 3.8% | 3/79 | 3 | 79 |  |
| 109 | `NetStream-v6` | 3.8% | 3/80 | 3 | 80 |  |
| 110 | `NetStream-v7` | 3.8% | 3/80 | 3 | 80 |  |
| 111 | `NetStream-v8` | 3.8% | 3/80 | 3 | 80 |  |
| 112 | `Video-v7` | 3.5% | 3/85 | 3 | 85 |  |
| 113 | `Video-v8` | 3.5% | 3/85 | 3 | 85 |  |
| 114 | `HitTest-v6` | 3.4% | 3/88 | 3 | 88 |  |
| 115 | `HitTest-v7` | 3.4% | 3/88 | 3 | 88 |  |
| 116 | `HitTest-v8` | 3.4% | 3/88 | 3 | 88 |  |
| 117 | `Camera-v7` | 3.3% | 3/90 | 4 | 90 |  |
| 118 | `Camera-v8` | 3.3% | 3/90 | 4 | 90 |  |
| 119 | `Sound-v5` | 3.0% | 3/100 | 3 | 100 |  |
| 120 | `System-v7` | 3.0% | 3/101 | 5 | 101 |  |
| 121 | `System-v8` | 3.0% | 3/101 | 5 | 101 |  |
| 122 | `ASnative-v5` | 2.8% | 3/107 | 3 | 107 |  |
| 123 | `with-v6` | 2.8% | 3/107 | 22 | 107 |  |
| 124 | `with-v7` | 2.8% | 3/107 | 22 | 107 |  |
| 125 | `with-v8` | 2.8% | 3/107 | 22 | 107 |  |
| 126 | `ASnative-v6` | 2.7% | 3/110 | 3 | 110 |  |
| 127 | `ASnative-v7` | 2.7% | 3/110 | 3 | 110 |  |
| 128 | `ASnative-v8` | 2.7% | 3/110 | 3 | 110 |  |
| 129 | `Inheritance-v5` | 2.6% | 3/114 | 5 | 114 |  |
| 130 | `ExternalInterface-v8` | 2.5% | 3/118 | 3 | 118 |  |
| 131 | `AsBroadcaster-v6` | 2.5% | 3/121 | 3 | 121 |  |
| 132 | `AsBroadcaster-v7` | 2.5% | 3/121 | 3 | 121 |  |
| 133 | `AsBroadcaster-v8` | 2.5% | 3/121 | 3 | 121 |  |
| 134 | `TextFormat-v5` | 2.3% | 3/128 | 3 | 128 |  |
| 135 | `TextFormat-v6` | 2.3% | 3/128 | 3 | 128 |  |
| 136 | `ContextMenu-v7` | 2.3% | 3/131 | 4 | 131 |  |
| 137 | `ContextMenu-v8` | 2.3% | 3/131 | 4 | 131 |  |
| 138 | `toString_valueOf-v5` | 2.2% | 3/137 | 3 | 137 |  |
| 139 | `Color-v5` | 2.1% | 3/140 | 3 | 140 |  |
| 140 | `LoadVars-v6` | 2.0% | 3/152 | 3 | 152 |  |
| 141 | `LoadVars-v7` | 2.0% | 3/152 | 3 | 152 |  |
| 142 | `LoadVars-v8` | 2.0% | 3/152 | 3 | 152 |  |
| 143 | `toString_valueOf-v6` | 1.9% | 3/155 | 3 | 155 |  |
| 144 | `toString_valueOf-v7` | 1.9% | 3/155 | 3 | 155 |  |
| 145 | `toString_valueOf-v8` | 1.9% | 3/155 | 3 | 155 |  |
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
