# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `82bf8b804cb6`  
**Date:** 2026-04-03 16:28 UTC  
**Total duration:** 4h37m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 572 | 620 | 92.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 68 | 190 | 35.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **680** | **894** | **76.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 81,352 | 91,501 | 88.9% |
| from_gnash/actionscript.all | 12,419 | 16,957 | 73.2% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **93,949** | **109,054** | **86.1%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 46 | - | 1 | 1 |
| from_gnash/actionscript.all | 122 | - | - | - |
| from_gnash/misc-swfmill.all | 3 | - | - | - |
| from_shumway | 30 | - | - | - |
| from_shumway/avm1 | 10 | 1 | - | - |
| **Total** | **211** | **1** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | Math-v7 | 98% |
| from_gnash/actionscript.all | Math-v8 | 98% |
| avm1 | mcl_replace_root_swf7_to_swf5 | 98% |
| avm1 | mcl_replace_root_swf7_to_swf6 | 98% |
| from_gnash/actionscript.all | Math-v5 | 98% |
| from_gnash/actionscript.all | Math-v6 | 98% |
| from_gnash/actionscript.all | Inheritance-v8 | 98% |
| avm1 | movieclip_library_state_values | 97% |
| from_gnash/actionscript.all | ops-v8 | 97% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| from_gnash/actionscript.all | Color-v6 | 96% |
| avm1 | movieclip_hittest_shapeflag | 96% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Key-v5 | 92% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 89% |
| from_gnash/actionscript.all | Selection-v8 | 89% |
| from_gnash/actionscript.all | Selection-v6 | 88% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/actionscript.all | Error-v6 | 87% |
| from_gnash/actionscript.all | Error-v7 | 87% |
| from_gnash/actionscript.all | Error-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | Error-v5 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | Inheritance-v5 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_shumway/avm1 | nativeinheritance | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | System-v7 | 82% |
| from_gnash/actionscript.all | System-v8 | 82% |
| from_gnash/actionscript.all | System-v6 | 82% |
| from_gnash/actionscript.all | Number-v7 | 81% |
| from_gnash/actionscript.all | Number-v8 | 81% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/actionscript.all | array-v5 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 11 | 177 |
| from_gnash/actionscript.all | 63 | - | 9783 | 1 |

**avm1 — newly passing:** `bitmap_filters`, `displacementmapfilter_mappoint_throw_error`

**from_gnash/actionscript.all — newly passing:** `Accessibility-v5`, `Accessibility-v6`, `Accessibility-v7`, `Accessibility-v8`, `BitmapData-v5`, `BitmapData-v6`, `BitmapData-v7`, `Boolean-v5`, `Boolean-v6`, `Boolean-v7`, `Boolean-v8`, `Camera-v5`, `Color-v5`, `Color-v7`, `Color-v8`, `ColorTransform-v5`, `ColorTransform-v6`, `ColorTransform-v7`, `ContextMenu-v5`, `ContextMenu-v6`, `ExternalInterface-v5`, `Key-v6`, `Key-v7`, `Key-v8`, `LoadVars-v5`, `Matrix-v5`, `Microphone-v5`, `Mouse-v5`, `Mouse-v6`, `Mouse-v7`, `Mouse-v8`, `MovieClipLoader-v5`, `MovieClipLoader-v6`, `NetStream-v5`, `Point-v5`, `Point-v6`, `Point-v7`, `Random-v5`, `Random-v6`, `Random-v7`, `Random-v8`, `Rectangle-v5`, `Rectangle-v6`, `Rectangle-v7`, `Selection-v5`, `TextFieldHTML-v5`, `TextSnapshot-v5`, `Transform-v5`, `Try-v5`, `Try-v6`, `Try-v7`, `Try-v8`, `Video-v7`, `Video-v8`, `XMLSocket-v7`, `XMLSocket-v8`, `argstest-v5`, `enumerate-v5`, `swap-v5`, `swap-v6`, `swap-v7`, `swap-v8`, `targetPath-v5`

*Comparing `868900bbb1a2` → `82bf8b804cb6`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 1 | 3 | 33.3% |

## Per-Suite Details

### avm1

- **Pass:** 572/620 (92.3%)
- **Duration:** 3h06m16s across 30 shards
- **Lines:** 81,352/91,501 matching (88.9%)
- **Avg test duration:** 18.0s — slowest: `timeout` (47.1s)

### from_gnash/actionscript.all

- **Pass:** 68/190 (35.8%)
- **Duration:** 1h06m12s across 30 shards
- **Lines:** 12,419/16,957 matching (73.2%)
- **Avg test duration:** 20.8s — slowest: `array-v5` (45.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m08s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 17.7s — slowest: `func_dict` (18.8s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 13m54s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 17.7s — slowest: `button3` (19.0s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 6m52s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 17.9s — slowest: `watch` (19.3s)
