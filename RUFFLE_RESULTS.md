# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b8eef7a3e160`  
**Date:** 2026-05-15 17:55 UTC  
**Total duration:** 2h39m52s

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
| avm1 | 106,470 | 115,583 | 92.1% |
| from_gnash/actionscript.all | 27,676 | 38,787 | 71.4% |
| from_gnash/misc-ming.all | 3,987 | 5,239 | 76.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 412 | 557 | 74.0% |
| from_gnash/misc-swfmill.all | 87 | 95 | 91.6% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **140,214** | **162,259** | **86.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 39 |
| from_gnash/actionscript.all | 45 |
| from_gnash/misc-ming.all | 23 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | 1 |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **129** |

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
| from_gnash/actionscript.all | Object-v5 | 93% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/actionscript.all | flash-v8 | 88% |
| from_gnash/actionscript.all | Object-v7 | 88% |
| from_gnash/actionscript.all | Object-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | Stage-v6 | 84% |
| from_gnash/actionscript.all | Stage-v7 | 84% |
| from_gnash/actionscript.all | Stage-v8 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test | 84% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| from_gnash/actionscript.all | Object-v6 | 84% |
| from_gnash/misc-swfmill.all | registers | 83% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | 1 | 6 | 2 |
| from_gnash/actionscript.all | 4 | 3 | 10 | - |
| from_gnash/misc-ming.all | - | 3 | 12 | 74 |

**avm1 — newly passing:** `placeobject_occupied_depth`

**avm1 — newly failing:** `swf5_xml_event_handler_context`

**from_gnash/misc-ming.all — newly failing:** `loop/loop_test`, `loop/loop_test2`, `loop/loop_test3`

*Comparing `eb8206f8aa08` → `b8eef7a3e160`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/654 (92.4%)
- **Duration:** 1h07m48s across 30 shards
- **Lines:** 106,470/115,583 matching (92.1%)
- **Avg test duration:** 6.2s — slowest: `netstream_play_flv_screen` (35.7s)

### from_gnash/actionscript.all

- **Pass:** 127/243 (52.3%)
- **Duration:** 29m58s across 30 shards
- **Lines:** 27,676/38,787 matching (71.4%)
- **Avg test duration:** 7.3s — slowest: `array-v6` (52.5s)

### from_gnash/misc-ming.all

- **Pass:** 63/110 (57.3%)
- **Duration:** 31m23s across 30 shards
- **Lines:** 3,987/5,239 matching (76.1%)
- **Avg test duration:** 17.1s — slowest: `NetStream-SquareTest` (31.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m22s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.8s — slowest: `exception` (20.4s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m55s across 30 shards
- **Lines:** 412/557 matching (74.0%)
- **Avg test duration:** 15.5s — slowest: `edittext_test1` (20.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/20 (90.0%)
- **Duration:** 6m12s across 30 shards
- **Lines:** 87/95 matching (91.6%)
- **Avg test duration:** 18.6s — slowest: `registers` (20.0s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m56s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.7s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (21.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m15s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `label` (19.0s)
