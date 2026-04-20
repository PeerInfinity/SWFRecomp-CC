# Ruffle Test Results (Filtered)

**Date**: 2026-04-20 20:43 UTC

**Git SHA**: `a427f5fc2d`

**Run Duration**: 19m 6s

**Filtered**: 0 tests ignored out of 190 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 184 |
| Passing | **104** (56.5%) |
| Ruffle-matched | 43 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **147** (79.9%) |
| Failing | 37 |
| Total expected lines | 15840 |
| Matching lines | 13220 (83.5%) |
| Mismatched lines | 2620 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 37 | 100.0% |

## Passing Tests

**104 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `Accessibility-v5` | 15 | 1.3s |  |
| 2 | `Accessibility-v6` | 19 | 1.4s |  |
| 3 | `Accessibility-v7` | 19 | 1.1s |  |
| 4 | `Accessibility-v8` | 19 | 14.1s |  |
| 5 | `AsBroadcaster-v5` | 11 | 1.2s |  |
| 6 | `BitmapData-v5` | 7 | 1.1s |  |
| 7 | `BitmapData-v6` | 7 | 0.4s |  |
| 8 | `BitmapData-v7` | 7 | 16.6s |  |
| 9 | `Boolean-v5` | 38 | 1.8s |  |
| 10 | `Boolean-v6` | 38 | 1.3s |  |
| 11 | `Boolean-v7` | 38 | 1.8s |  |
| 12 | `Boolean-v8` | 38 | 0.7s |  |
| 13 | `Camera-v5` | 7 | 1.3s |  |
| 14 | `Color-v5` | 140 | 4.8s |  |
| 15 | `Color-v6` | 171 | 5.8s |  |
| 16 | `Color-v7` | 161 | 5.5s |  |
| 17 | `Color-v8` | 161 | 0.8s |  |
| 18 | `ColorTransform-v5` | 7 | 16.7s |  |
| 19 | `ColorTransform-v6` | 7 | 0.5s |  |
| 20 | `ColorTransform-v7` | 7 | 0.9s |  |
| 21 | `ColorTransform-v8` | 55 | 2.5s |  |
| 22 | `ContextMenu-v5` | 7 | 1.3s |  |
| 23 | `ContextMenu-v6` | 7 | 0.5s |  |
| 24 | `Error-v5` | 28 | 1.8s |  |
| 25 | `Error-v6` | 31 | 1.8s |  |
| 26 | `Error-v7` | 31 | 1.5s |  |
| 27 | `Error-v8` | 31 | 0.8s |  |
| 28 | `ExternalInterface-v5` | 7 | 1.4s |  |
| 29 | `Key-v5` | 51 | 2.5s |  |
| 30 | `Key-v6` | 55 | 2.5s |  |
| 31 | `Key-v7` | 55 | 2.0s |  |
| 32 | `Key-v8` | 55 | 0.8s |  |
| 33 | `LoadVars-v5` | 8 | 19.9s |  |
| 34 | `LocalConnection-v5` | 7 | 17.0s |  |
| 35 | `LocalConnection-v6` | 58 | 2.4s |  |
| 36 | `LocalConnection-v7` | 58 | 2.0s |  |
| 37 | `LocalConnection-v8` | 58 | 0.8s |  |
| 38 | `Matrix-v5` | 7 | 1.3s |  |
| 39 | `Microphone-v5` | 6 | 1.3s |  |
| 40 | `Mouse-v5` | 13 | 17.2s |  |
| 41 | `Mouse-v6` | 21 | 1.6s |  |
| 42 | `Mouse-v7` | 21 | 1.2s |  |
| 43 | `Mouse-v8` | 21 | 0.8s |  |
| 44 | `MovieClipLoader-v5` | 6 | 1.3s |  |
| 45 | `MovieClipLoader-v6` | 6 | 17.5s |  |
| 46 | `NetConnection-v5` | 7 | 17.1s |  |
| 47 | `NetStream-v5` | 6 | 1.3s |  |
| 48 | `NetStream-v6` | 80 | 2.9s |  |
| 49 | `Point-v5` | 7 | 17.8s |  |
| 50 | `Point-v6` | 7 | 0.6s |  |
| 51 | `Point-v7` | 7 | 1.0s |  |
| 52 | `Random-v5` | 30 | 1.9s |  |
| 53 | `Random-v6` | 30 | 0.6s |  |
| 54 | `Random-v7` | 30 | 17.7s |  |
| 55 | `Random-v8` | 30 | 0.8s |  |
| 56 | `Rectangle-v5` | 7 | 1.3s |  |
| 57 | `Rectangle-v6` | 7 | 0.5s |  |
| 58 | `Rectangle-v7` | 7 | 0.9s |  |
| 59 | `Selection-v5` | 21 | 17.0s |  |
| 60 | `Stage-v5` | 38 | 17.7s |  |
| 61 | `System-v5` | 67 | 2.6s |  |
| 62 | `System-v6` | 100 | 3.4s |  |
| 63 | `System-v7` | 101 | 3.4s |  |
| 64 | `System-v8` | 101 | 0.8s |  |
| 65 | `TextFieldHTML-v5` | 6 | 17.2s |  |
| 66 | `TextFormat-v5` | 128 | 4.4s |  |
| 67 | `TextFormat-v6` | 128 | 0.6s |  |
| 68 | `TextSnapshot-v5` | 7 | 1.4s |  |
| 69 | `TextSnapshot-v6` | 173 | 7.6s |  |
| 70 | `TextSnapshot-v7` | 173 | 7.3s |  |
| 71 | `TextSnapshot-v8` | 173 | 0.9s |  |
| 72 | `Transform-v5` | 7 | 1.4s |  |
| 73 | `Transform-v6` | 7 | 17.1s |  |
| 74 | `Transform-v7` | 7 | 1.0s |  |
| 75 | `Try-v5` | 20 | 2.4s |  |
| 76 | `Try-v6` | 20 | 0.5s |  |
| 77 | `Try-v7` | 20 | 2.0s |  |
| 78 | `Try-v8` | 20 | 0.8s |  |
| 79 | `Video-v5` | 7 | 17.0s |  |
| 80 | `Video-v6` | 85 | 2.8s |  |
| 81 | `Video-v7` | 85 | 2.4s |  |
| 82 | `Video-v8` | 85 | 0.8s |  |
| 83 | `XMLSocket-v5` | 35 | 17.3s |  |
| 84 | `XMLSocket-v6` | 35 | 1.9s |  |
| 85 | `XMLSocket-v7` | 35 | 18.3s |  |
| 86 | `XMLSocket-v8` | 35 | 0.9s |  |
| 87 | `argstest-v5` | 4 | 1.6s |  |
| 88 | `case-v5` | 39 | 2.0s |  |
| 89 | `delete-v5` | 60 | 1.9s |  |
| 90 | `delete-v6` | 60 | 1.5s |  |
| 91 | `delete-v7` | 60 | 1.6s |  |
| 92 | `delete-v8` | 60 | 0.7s |  |
| 93 | `enumerate-v5` | 6 | 17.2s |  |
| 94 | `enumerate-v6` | 49 | 2.5s |  |
| 95 | `enumerate-v7` | 49 | 2.0s |  |
| 96 | `enumerate-v8` | 49 | 0.8s |  |
| 97 | `flash-v5` | 10 | 1.3s |  |
| 98 | `flash-v6` | 10 | 1.4s |  |
| 99 | `flash-v7` | 10 | 18.2s |  |
| 100 | `swap-v5` | 7 | 1.4s |  |
| 101 | `swap-v6` | 7 | 0.6s |  |
| 102 | `swap-v7` | 7 | 1.0s |  |
| 103 | `swap-v8` | 7 | 0.8s |  |
| 104 | `targetPath-v5` | 12 | 17.5s |  |

## Ruffle-Matched Tests

**43 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `ASnative-v5` | 35 | 35 | 20.6s |  |
| 2 | `ASnative-v6` | 40 | 40 | 4.6s |  |
| 3 | `ASnative-v7` | 40 | 40 | 4.3s |  |
| 4 | `ASnative-v8` | 40 | 40 | 0.8s |  |
| 5 | `BitmapData-v8` | 8 | 13 | 22.0s |  |
| 6 | `Camera-v6` | 57 | 57 | 19.1s |  |
| 7 | `Camera-v7` | 57 | 57 | 3.0s |  |
| 8 | `Camera-v8` | 57 | 57 | 0.8s |  |
| 9 | `ExternalInterface-v8` | 4 | 4 | 4.4s |  |
| 10 | `Inheritance-v5` | 1 | 17 | 4.0s |  |
| 11 | `Inheritance-v6` | 9 | 16 | 5.8s |  |
| 12 | `Inheritance-v7` | 5 | 10 | 6.0s |  |
| 13 | `Inheritance-v8` | 5 | 10 | 1.3s |  |
| 14 | `Math-v5` | 5 | 5 | 29.4s |  |
| 15 | `Math-v6` | 5 | 5 | 0.6s |  |
| 16 | `Math-v7` | 5 | 5 | 13.8s |  |
| 17 | `Math-v8` | 5 | 5 | 0.9s |  |
| 18 | `Matrix-v6` | 29 | 71 | 6.9s |  |
| 19 | `Matrix-v7` | 28 | 70 | 22.6s |  |
| 20 | `Matrix-v8` | 28 | 70 | 0.9s |  |
| 21 | `Microphone-v6` | 31 | 31 | 2.8s |  |
| 22 | `Microphone-v7` | 31 | 31 | 2.4s |  |
| 23 | `Microphone-v8` | 31 | 31 | 0.8s |  |
| 24 | `MovieClipLoader-v7` | 118 | 118 | 3.3s |  |
| 25 | `MovieClipLoader-v8` | 118 | 118 | 1.9s |  |
| 26 | `Point-v8` | 3 | 20 | 7.5s |  |
| 27 | `Rectangle-v8` | 21 | 21 | 6.0s |  |
| 28 | `Sound-v5` | 27 | 27 | 19.6s |  |
| 29 | `Sound-v6` | 30 | 51 | 4.4s |  |
| 30 | `Sound-v7` | 28 | 51 | 20.2s |  |
| 31 | `Sound-v8` | 28 | 51 | 1.1s |  |
| 32 | `TextField-v5` | 3 | 3 | 1.4s |  |
| 33 | `case-v7` | 54 | 54 | 15.2s |  |
| 34 | `case-v8` | 54 | 54 | 0.7s |  |
| 35 | `ops-v8` | 7 | 11 | 9.5s |  |
| 36 | `targetPath-v6` | 17 | 17 | 1.6s |  |
| 37 | `targetPath-v7` | 17 | 17 | 1.3s |  |
| 38 | `targetPath-v8` | 17 | 17 | 0.8s |  |
| 39 | `toString_valueOf-v5` | 34 | 34 | 4.5s |  |
| 40 | `toString_valueOf-v6` | 5 | 5 | 5.0s |  |
| 41 | `toString_valueOf-v7` | 5 | 5 | 21.1s |  |
| 42 | `toString_valueOf-v8` | 5 | 5 | 0.9s |  |
| 43 | `with-v5` | 42 | 42 | 3.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**31 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `LoadVars-v6` | 95.4% | 146 | 153 | 7 |  |
| 2 | `LoadVars-v7` | 95.4% | 146 | 153 | 7 |  |
| 3 | `LoadVars-v8` | 95.4% | 146 | 153 | 7 |  |
| 4 | `Selection-v6` | 93.6% | 117 | 125 | 8 |  |
| 5 | `Selection-v7` | 93.6% | 117 | 125 | 8 |  |
| 6 | `Selection-v8` | 93.6% | 117 | 125 | 8 |  |
| 7 | `TextFieldHTML-v6` | 91.9% | 34 | 37 | 3 |  |
| 8 | `TextFieldHTML-v7` | 91.9% | 34 | 37 | 3 |  |
| 9 | `TextFieldHTML-v8` | 91.9% | 34 | 37 | 3 |  |
| 10 | `array-v5` | 91.4% | 512 | 560 | 48 |  |
| 11 | `Global-v8` | 85.8% | 145 | 169 | 24 |  |
| 12 | `Global-v7` | 83.0% | 151 | 182 | 31 |  |
| 13 | `AsBroadcaster-v6` | 81.0% | 98 | 121 | 23 |  |
| 14 | `HitTest-v8` | 80.7% | 71 | 88 | 17 |  |
| 15 | `HitTest-v6` | 79.5% | 70 | 88 | 18 |  |
| 16 | `HitTest-v7` | 79.5% | 70 | 88 | 18 |  |
| 17 | `Global-v6` | 79.0% | 166 | 210 | 44 |  |
| 18 | `MovieClip-v5` | 76.0% | 276 | 363 | 87 |  |
| 19 | `TextFormat-v7` | 75.9% | 132 | 174 | 42 |  |
| 20 | `AsBroadcaster-v7` | 74.4% | 90 | 121 | 31 |  |
| 21 | `AsBroadcaster-v8` | 74.4% | 90 | 121 | 31 |  |
| 22 | `ContextMenu-v7` | 73.3% | 96 | 131 | 35 |  |
| 23 | `ContextMenu-v8` | 73.3% | 96 | 131 | 35 |  |
| 24 | `String-v6` | 69.8% | 263 | 377 | 114 |  |
| 25 | `String-v7` | 69.0% | 260 | 377 | 117 |  |
| 26 | `String-v8` | 69.0% | 260 | 377 | 117 |  |
| 27 | `String-v5` | 67.9% | 243 | 358 | 115 |  |
| 28 | `ExternalInterface-v6` | 58.2% | 32 | 55 | 23 |  |
| 29 | `ExternalInterface-v7` | 58.2% | 32 | 55 | 23 |  |
| 30 | `Instance-v6` | 51.9% | 27 | 52 | 25 |  |
| 31 | `Instance-v5` | 50.0% | 26 | 52 | 26 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**37 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `LoadVars-v6` | 95.4% | 146/153 | 153 | 152 |  |
| 2 | `LoadVars-v7` | 95.4% | 146/153 | 153 | 152 |  |
| 3 | `LoadVars-v8` | 95.4% | 146/153 | 153 | 152 |  |
| 4 | `Selection-v6` | 93.6% | 117/125 | 125 | 125 |  |
| 5 | `Selection-v7` | 93.6% | 117/125 | 125 | 125 |  |
| 6 | `Selection-v8` | 93.6% | 117/125 | 125 | 125 |  |
| 7 | `TextFieldHTML-v6` | 91.9% | 34/37 | 37 | 37 |  |
| 8 | `TextFieldHTML-v7` | 91.9% | 34/37 | 37 | 37 |  |
| 9 | `TextFieldHTML-v8` | 91.9% | 34/37 | 37 | 37 |  |
| 10 | `array-v5` | 91.4% | 512/560 | 560 | 560 |  |
| 11 | `Global-v8` | 85.8% | 145/169 | 168 | 169 |  |
| 12 | `Global-v7` | 83.0% | 151/182 | 181 | 182 |  |
| 13 | `AsBroadcaster-v6` | 81.0% | 98/121 | 121 | 121 |  |
| 14 | `HitTest-v8` | 80.7% | 71/88 | 88 | 88 |  |
| 15 | `HitTest-v6` | 79.5% | 70/88 | 88 | 88 |  |
| 16 | `HitTest-v7` | 79.5% | 70/88 | 88 | 88 |  |
| 17 | `Global-v6` | 79.0% | 166/210 | 209 | 210 |  |
| 18 | `MovieClip-v5` | 76.0% | 276/363 | 350 | 363 |  |
| 19 | `TextFormat-v7` | 75.9% | 132/174 | 174 | 174 |  |
| 20 | `AsBroadcaster-v7` | 74.4% | 90/121 | 121 | 121 |  |
| 21 | `AsBroadcaster-v8` | 74.4% | 90/121 | 121 | 121 |  |
| 22 | `ContextMenu-v7` | 73.3% | 96/131 | 130 | 131 |  |
| 23 | `ContextMenu-v8` | 73.3% | 96/131 | 130 | 131 |  |
| 24 | `String-v6` | 69.8% | 263/377 | 377 | 377 |  |
| 25 | `String-v7` | 69.0% | 260/377 | 377 | 377 |  |
| 26 | `String-v8` | 69.0% | 260/377 | 377 | 377 |  |
| 27 | `String-v5` | 67.9% | 243/358 | 358 | 358 |  |
| 28 | `ExternalInterface-v6` | 58.2% | 32/55 | 55 | 55 |  |
| 29 | `ExternalInterface-v7` | 58.2% | 32/55 | 55 | 55 |  |
| 30 | `Instance-v6` | 51.9% | 27/52 | 52 | 52 |  |
| 31 | `Instance-v5` | 50.0% | 26/52 | 52 | 52 |  |
| 32 | `Instance-v7` | 46.2% | 24/52 | 52 | 52 |  |
| 33 | `Instance-v8` | 46.2% | 24/52 | 52 | 52 |  |
| 34 | `case-v6` | 24.7% | 18/73 | 72 | 73 |  |
| 35 | `with-v6` | 19.3% | 23/119 | 119 | 107 |  |
| 36 | `with-v7` | 19.3% | 23/119 | 119 | 107 |  |
| 37 | `with-v8` | 19.3% | 23/119 | 119 | 107 |  |
