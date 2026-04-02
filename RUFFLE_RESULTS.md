# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2fd884d606d4`  
**Date:** 2026-04-02 22:23 UTC  
**Total duration:** 4h32m19s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 570 | 620 | 91.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 62 | 190 | 32.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **672** | **894** | **75.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 81,332 | 91,501 | 88.9% |
| from_gnash/actionscript.all | 12,296 | 16,957 | 72.5% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **93,806** | **109,054** | **86.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 48 | - | 1 | 1 |
| from_gnash/actionscript.all | 128 | - | - | - |
| from_gnash/misc-swfmill.all | 3 | - | - | - |
| from_shumway | 30 | - | - | - |
| from_shumway/avm1 | 10 | 1 | - | - |
| **Total** | **219** | **1** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_filters | 99% |
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
| from_gnash/actionscript.all | Key-v6 | 95% |
| from_gnash/actionscript.all | Key-v7 | 95% |
| from_gnash/actionscript.all | Key-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Key-v5 | 92% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 88% |
| from_gnash/actionscript.all | Selection-v8 | 88% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/actionscript.all | Selection-v6 | 87% |
| from_gnash/actionscript.all | Error-v6 | 87% |
| from_gnash/actionscript.all | Error-v7 | 87% |
| from_gnash/actionscript.all | Error-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | Error-v5 | 86% |
| from_gnash/actionscript.all | Mouse-v6 | 86% |
| from_gnash/actionscript.all | Mouse-v7 | 86% |
| from_gnash/actionscript.all | Mouse-v8 | 86% |
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
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 186 |
| from_gnash/actionscript.all | 57 | - | 9660 | 1 |

**from_gnash/actionscript.all — newly passing:** `Accessibility-v5`, `Accessibility-v6`, `Accessibility-v7`, `Accessibility-v8`, `BitmapData-v5`, `BitmapData-v6`, `BitmapData-v7`, `Boolean-v5`, `Boolean-v6`, `Boolean-v7`, `Boolean-v8`, `Camera-v5`, `Color-v5`, `Color-v7`, `Color-v8`, `ColorTransform-v5`, `ColorTransform-v6`, `ColorTransform-v7`, `ContextMenu-v5`, `ContextMenu-v6`, `ExternalInterface-v5`, `LoadVars-v5`, `Matrix-v5`, `Microphone-v5`, `Mouse-v5`, `MovieClipLoader-v5`, `MovieClipLoader-v6`, `NetStream-v5`, `Point-v5`, `Point-v6`, `Point-v7`, `Random-v5`, `Random-v6`, `Random-v7`, `Random-v8`, `Rectangle-v5`, `Rectangle-v6`, `Rectangle-v7`, `Selection-v5`, `TextFieldHTML-v5`, `TextSnapshot-v5`, `Transform-v5`, `Try-v5`, `Try-v6`, `Try-v7`, `Try-v8`, `Video-v7`, `Video-v8`, `XMLSocket-v7`, `XMLSocket-v8`, `argstest-v5`, `enumerate-v5`, `swap-v5`, `swap-v6`, `swap-v7`, `swap-v8`, `targetPath-v5`

*Comparing `868900bbb1a2` → `2fd884d606d4`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 3 | 3 | 100% |

## Per-Suite Details

### avm1

- **Pass:** 570/620 (91.9%)
- **Duration:** 3h03m17s across 30 shards
- **Lines:** 81,332/91,501 matching (88.9%)
- **Avg test duration:** 17.7s — slowest: `timeout` (48.0s)

### from_gnash/actionscript.all

- **Pass:** 62/190 (32.6%)
- **Duration:** 1h04m45s across 30 shards
- **Lines:** 12,296/16,957 matching (72.5%)
- **Avg test duration:** 20.4s — slowest: `array-v5` (42.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m02s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 17.3s — slowest: `dict_callframe` (17.8s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 13m33s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 17.2s — slowest: `local2global` (18.9s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 6m40s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 17.4s — slowest: `super` (19.2s)
