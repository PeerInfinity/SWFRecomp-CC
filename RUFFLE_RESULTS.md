# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `427f0abb18b3`  
**Date:** 2026-07-04 23:54 UTC  
**Total duration:** 2h33m55s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 638 | 710 | 89.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **997** | **1252** | **79.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,817 | 130,993 | 88.4% |
| from_gnash/actionscript.all | 30,158 | 38,791 | 77.7% |
| from_gnash/misc-ming.all | 4,042 | 5,248 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **152,133** | **177,705** | **85.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 54 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 15 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **102** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `bac8b31e81fc` → `427f0abb18b3`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 638/710 (89.9%)
- **Duration:** 1h03m56s across 30 shards
- **Lines:** 115,817/130,993 matching (88.4%)
- **Avg test duration:** 5.3s — slowest: `netstream_play_flv_screen` (36.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 30m09s across 30 shards
- **Lines:** 30,158/38,791 matching (77.7%)
- **Avg test duration:** 7.4s — slowest: `MovieClip-v8` (67.4s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 30m51s across 30 shards
- **Lines:** 4,042/5,248 matching (77.0%)
- **Avg test duration:** 16.6s — slowest: `matrix_test` (96.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m14s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `function_test` (21.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 5m11s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 15.5s — slowest: `movieclip_destruction_test1` (22.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 4m36s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 13.7s — slowest: `dict_cross` (21.1s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m30s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.4s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (23.3s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m25s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.0s — slowest: `moviecliploader` (20.8s)
