# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `9e3e903e0754`  
**Date:** 2026-05-04 04:30 UTC  
**Total duration:** 2h23m48s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 586 | 647 | 90.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 0 | 190 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 61 | 102 | 59.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **788** | **1121** | **70.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,091 | 114,057 | 92.1% |
| from_gnash/actionscript.all | 0 | 0 | 0% |
| from_gnash/misc-ming.all | 2,784 | 4,493 | 62.0% |
| from_gnash/misc-mtasc.all | 162 | 163 | 99.4% |
| from_gnash/misc-swfc.all | 339 | 499 | 67.9% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **109,574** | **121,030** | **90.5%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | 14 | 38 |
| from_gnash/actionscript.all | 190 | - |
| from_gnash/misc-ming.all | 3 | 21 |
| from_gnash/misc-mtasc.all | 1 | - |
| from_gnash/misc-swfc.all | - | 5 |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | - | 25 |
| from_shumway/avm1 | - | 1 |
| **Total** | **208** | **90** |

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
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 14 | - | - |
| from_gnash/actionscript.all | - | 185 | 1606 | - |
| from_gnash/misc-ming.all | - | 3 | 9 | - |
| from_gnash/misc-mtasc.all | - | 1 | 19 | - |

**avm1 — newly failing:** `bitmap_filters`, `do_init_action_child`, `global_swf6_7_8`, `instanceof_coercions`, `interface_implements_op`, `loadmovie_registerclass`, `loadmovie_replace_root`, `loadmovienum_cross_version_prototype`, `mcl_loadclip_properties`, `mcl_loadclip_replace_root`, `movieclip_blend_mode_property`, `register_class`, `register_class_swf6`, `register_class_with_sound`

**from_gnash/actionscript.all — newly failing:** `Accessibility-v5`, `Accessibility-v6`, `Accessibility-v7`, `Accessibility-v8`, `AsBroadcaster-v5`, `BitmapData-v5`, `BitmapData-v6`, `BitmapData-v7`, `Boolean-v5`, `Boolean-v6`, `Boolean-v7`, `Boolean-v8`, `Camera-v5`, `Color-v5`, `Color-v6`, `Color-v7`, `Color-v8`, `ColorTransform-v5`, `ColorTransform-v6`, `ColorTransform-v7`, `ColorTransform-v8`, `ContextMenu-v5`, `ContextMenu-v6`, `ContextMenu-v7`, `ContextMenu-v8`, `Error-v5`, `Error-v6`, `Error-v7`, `Error-v8`, `ExternalInterface-v5`, `ExternalInterface-v6`, `ExternalInterface-v7`, `Instance-v5`, `Instance-v6`, `Instance-v7`, `Instance-v8`, `Key-v5`, `Key-v6`, `Key-v7`, `Key-v8`, `LoadVars-v5`, `LocalConnection-v5`, `LocalConnection-v6`, `LocalConnection-v7`, `LocalConnection-v8`, `Matrix-v5`, `Microphone-v5`, `Mouse-v5`, `Mouse-v6`, `Mouse-v7`, `Mouse-v8`, `MovieClipLoader-v5`, `MovieClipLoader-v6`, `NetConnection-v5`, `NetStream-v5`, `NetStream-v6`, `NetStream-v7`, `NetStream-v8`, `Number-v6`, `Number-v7`, `Number-v8`, `Point-v5`, `Point-v6`, `Point-v7`, `Point-v8`, `Random-v5`, `Random-v6`, `Random-v7`, `Random-v8`, `Rectangle-v5`, `Rectangle-v6`, `Rectangle-v7`, `Selection-v5`, `Stage-v5`, `System-v5`, `System-v6`, `System-v7`, `System-v8`, `TextFieldHTML-v5`, `TextFieldHTML-v6`, `TextFieldHTML-v7`, `TextFieldHTML-v8`, `TextFormat-v5`, `TextFormat-v6`, `TextSnapshot-v5`, `TextSnapshot-v6`, `TextSnapshot-v7`, `TextSnapshot-v8`, `Transform-v5`, `Transform-v6`, `Transform-v7`, `Try-v5`, `Try-v6`, `Try-v7`, `Try-v8`, `Video-v5`, `Video-v6`, `Video-v7`, `Video-v8`, `XMLSocket-v5`, `XMLSocket-v6`, `XMLSocket-v7`, `XMLSocket-v8`, `argstest-v5`, `case-v5`, `case-v6`, `case-v7`, `case-v8`, `delete-v5`, `delete-v6`, `delete-v7`, `delete-v8`, `enumerate-v5`, `enumerate-v6`, `enumerate-v7`, `enumerate-v8`, `flash-v5`, `flash-v6`, `flash-v7`, `swap-v5`, `swap-v6`, `swap-v7`, `swap-v8`, `targetPath-v5`

**from_gnash/misc-ming.all — newly failing:** `attachExtImported`, `attachImported`

*Comparing `c955f1046396` → `9e3e903e0754`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 586/647 (90.6%)
- **Duration:** 1h04m37s across 30 shards
- **Lines:** 105,091/114,057 matching (92.1%)
- **Avg test duration:** 5.9s — slowest: `netstream_play_flv_screen` (35.7s)

### from_gnash/actionscript.all

- **Pass:** 0/190 (0%)
- **Duration:** 21m45s across 30 shards
- **Avg test duration:** 6.8s — slowest: `String-v8` (35.8s)

### from_gnash/misc-ming.all

- **Pass:** 61/102 (59.8%)
- **Duration:** 29m05s across 30 shards
- **Lines:** 2,784/4,493 matching (62.0%)
- **Avg test duration:** 17.1s — slowest: `matrix_test` (99.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m16s across 30 shards
- **Lines:** 162/163 matching (99.4%)
- **Avg test duration:** 15.1s — slowest: `implementsOpTest` (20.0s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 4m22s across 30 shards
- **Lines:** 339/499 matching (67.9%)
- **Avg test duration:** 16.3s — slowest: `opcode_guard_test2` (19.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m19s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.7s — slowest: `dict_override` (18.9s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m32s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.4s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (21.7s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.2s — slowest: `hitarea` (17.8s)
