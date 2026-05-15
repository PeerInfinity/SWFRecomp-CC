# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `86fc1408b1b0`  
**Date:** 2026-05-15 20:17 UTC  
**Total duration:** 2h10m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 654 | 92.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 127 | 243 | 52.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 63 | 110 | 57.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 18 | 20 | 90.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **946** | **1194** | **79.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,302 | 115,583 | 92.0% |
| from_gnash/actionscript.all | 27,720 | 38,787 | 71.5% |
| from_gnash/misc-ming.all | 3,987 | 5,239 | 76.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 412 | 557 | 74.0% |
| from_gnash/misc-swfmill.all | 87 | 95 | 91.6% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **140,090** | **162,259** | **86.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 39 |
| from_gnash/actionscript.all | 44 |
| from_gnash/misc-ming.all | 23 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | 1 |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **128** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | Object-v7 | 90% |
| from_gnash/actionscript.all | Object-v8 | 90% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/actionscript.all | flash-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Object-v6 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | Stage-v6 | 84% |
| from_gnash/actionscript.all | Stage-v7 | 84% |
| from_gnash/actionscript.all | Stage-v8 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test | 84% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| from_gnash/misc-swfmill.all | registers | 83% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 168 |
| from_gnash/actionscript.all | 1 | - | 41 | 3 |

*Comparing `a017c0f6a274` → `86fc1408b1b0`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/654 (92.4%)
- **Duration:** 58m23s across 30 shards
- **Lines:** 106,302/115,583 matching (92.0%)
- **Avg test duration:** 5.3s — slowest: `swf4_bool` (30.5s)

### from_gnash/actionscript.all

- **Pass:** 127/243 (52.3%)
- **Duration:** 16m07s across 30 shards
- **Lines:** 27,720/38,787 matching (71.5%)
- **Avg test duration:** 3.9s — slowest: `Inheritance-v5` (19.9s)

### from_gnash/misc-ming.all

- **Pass:** 63/110 (57.3%)
- **Duration:** 27m21s across 30 shards
- **Lines:** 3,987/5,239 matching (76.1%)
- **Avg test duration:** 14.9s — slowest: `matrix_test` (21.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m08s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.3s — slowest: `implementsOpTest` (18.5s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m33s across 30 shards
- **Lines:** 412/557 matching (74.0%)
- **Avg test duration:** 14.3s — slowest: `mouse_drag_test` (18.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/20 (90.0%)
- **Duration:** 6m04s across 30 shards
- **Lines:** 87/95 matching (91.6%)
- **Avg test duration:** 18.2s — slowest: `initaction_in_definesprite` (19.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m46s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.9s — slowest: `avm1/mouse-transparency` (19.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.2s — slowest: `hitarea` (19.0s)
