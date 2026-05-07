# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8fdf331148d6`  
**Date:** 2026-05-07 17:29 UTC  
**Total duration:** 4m59s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 648 | 93.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 64 | 102 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 72 | 92 | 78.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **944** | **1122** | **84.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,095 | 114,983 | 92.3% |
| from_gnash/actionscript.all | 15,374 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 3,583 | 4,577 | 78.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 371 | 499 | 74.3% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 876 | 1,276 | 68.7% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **127,042** | **139,065** | **91.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 34 |
| from_gnash/actionscript.all | 1 |
| from_gnash/misc-ming.all | 16 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 3 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 17 |
| from_shumway/avm1 | 1 |
| **Total** | **72** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 87% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 13 | - |
| from_gnash/actionscript.all | 189 | - | 15374 | - |

**avm1 — newly passing:** `placeobject_occupied_depth`, `textsnapshot_available_text`

**from_gnash/actionscript.all — newly passing:** `Accessibility-v5`, `Accessibility-v6`, `Accessibility-v7`, `Accessibility-v8`, `AsBroadcaster-v5`, `BitmapData-v5`, `BitmapData-v6`, `BitmapData-v7`, `Boolean-v5`, `Boolean-v6`, `Boolean-v7`, `Boolean-v8`, `Camera-v5`, `Color-v5`, `Color-v6`, `Color-v7`, `Color-v8`, `ColorTransform-v5`, `ColorTransform-v6`, `ColorTransform-v7`, `ColorTransform-v8`, `ContextMenu-v5`, `ContextMenu-v6`, `ContextMenu-v7`, `ContextMenu-v8`, `Error-v5`, `Error-v6`, `Error-v7`, `Error-v8`, `ExternalInterface-v5`, `ExternalInterface-v6`, `ExternalInterface-v7`, `Global-v7`, `Global-v8`, `Instance-v5`, `Instance-v6`, `Instance-v7`, `Instance-v8`, `Key-v5`, `Key-v6`, `Key-v7`, `Key-v8`, `LoadVars-v5`, `LocalConnection-v5`, `LocalConnection-v6`, `LocalConnection-v7`, `LocalConnection-v8`, `Matrix-v5`, `Microphone-v5`, `Mouse-v5`, `Mouse-v6`, `Mouse-v7`, `Mouse-v8`, `MovieClipLoader-v5`, `MovieClipLoader-v6`, `NetConnection-v5`, `NetStream-v5`, `NetStream-v6`, `NetStream-v7`, `NetStream-v8`, `Number-v6`, `Number-v7`, `Number-v8`, `Point-v5`, `Point-v6`, `Point-v7`, `Point-v8`, `Random-v5`, `Random-v6`, `Random-v7`, `Random-v8`, `Rectangle-v5`, `Rectangle-v6`, `Rectangle-v7`, `Selection-v5`, `Stage-v5`, `System-v5`, `System-v6`, `System-v7`, `System-v8`, `TextFieldHTML-v5`, `TextFieldHTML-v6`, `TextFieldHTML-v7`, `TextFieldHTML-v8`, `TextFormat-v5`, `TextFormat-v6`, `TextSnapshot-v5`, `TextSnapshot-v6`, `TextSnapshot-v7`, `TextSnapshot-v8`, `Transform-v5`, `Transform-v6`, `Transform-v7`, `Try-v5`, `Try-v6`, `Try-v7`, `Try-v8`, `Video-v5`, `Video-v6`, `Video-v7`, `Video-v8`, `XMLSocket-v5`, `XMLSocket-v6`, `XMLSocket-v7`, `XMLSocket-v8`, `argstest-v5`, `case-v5`, `case-v6`, `case-v7`, `case-v8`, `delete-v5`, `delete-v6`, `delete-v7`, `delete-v8`, `enumerate-v5`, `enumerate-v6`, `enumerate-v7`, `enumerate-v8`, `flash-v5`, `flash-v6`, `flash-v7`, `swap-v5`, `swap-v6`, `swap-v7`, `swap-v8`, `targetPath-v5`

*Comparing `873e520ed49f` → `8fdf331148d6`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 605/648 (93.4%)
- **Duration:** 2m47s across 30 shards
- **Lines:** 106,095/114,983 matching (92.3%)
- **Avg test duration:** 0.2s — slowest: `edittext_newline_stripping` (6.2s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 54s across 30 shards
- **Lines:** 15,374/16,957 matching (90.7%)
- **Avg test duration:** 0.2s — slowest: `NetStream-v8` (0.7s)

### from_gnash/misc-ming.all

- **Pass:** 64/102 (62.7%)
- **Duration:** 35s across 30 shards
- **Lines:** 3,583/4,577 matching (78.3%)
- **Avg test duration:** 0.3s — slowest: `matrix_test` (4.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.2s — slowest: `levels` (0.2s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4s across 30 shards
- **Lines:** 371/499 matching (74.3%)
- **Avg test duration:** 0.2s — slowest: `action_execution_order_test10` (0.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 4s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.2s — slowest: `trace-as2/shortstack` (0.5s)

### from_shumway

- **Pass:** 72/92 (78.3%)
- **Duration:** 22s across 30 shards
- **Lines:** 876/1,276 matching (68.7%)
- **Avg test duration:** 0.2s — slowest: `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` (0.5s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 10s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 0.2s — slowest: `depth` (0.2s)
