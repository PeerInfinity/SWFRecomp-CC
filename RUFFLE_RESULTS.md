# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `87465d1130f2`  
**Date:** 2026-06-18 23:41 UTC  
**Total duration:** 2h58m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 624 | 701 | 89.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 10 | 20 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **982** | **1243** | **79.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 114,522 | 130,944 | 87.5% |
| from_gnash/actionscript.all | 30,004 | 38,791 | 77.3% |
| from_gnash/misc-ming.all | 4,042 | 5,248 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **150,681** | **177,656** | **84.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 58 | 4 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 15 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **106** | **4** |

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
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 85% |
| from_gnash/actionscript.all | TextField-v8 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 2 | - |
| from_gnash/misc-swfc.all | 1 | - | 5 | - |

**avm1 — newly passing:** `set_target_2_swf6`, `set_target_2_swf7`

**from_gnash/misc-swfc.all — newly passing:** `opcode_guard_test2`

*Comparing `0e70f553f16a` → `87465d1130f2`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 624/701 (89.0%)
- **Duration:** 1h15m44s across 30 shards
- **Lines:** 114,522/130,944 matching (87.5%)
- **Avg test duration:** 6.4s — slowest: `netstream_play_flv_screen` (36.0s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 34m52s across 30 shards
- **Lines:** 30,004/38,791 matching (77.3%)
- **Avg test duration:** 8.5s — slowest: `MovieClip-v8` (72.4s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 34m51s across 30 shards
- **Lines:** 4,042/5,248 matching (77.0%)
- **Avg test duration:** 18.8s — slowest: `matrix_test` (112.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m29s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.6s — slowest: `exception` (22.5s)

### from_gnash/misc-swfc.all

- **Pass:** 10/20 (50.0%)
- **Duration:** 5m46s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 17.3s — slowest: `movieclip_destruction_test3` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m31s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.5s — slowest: `dict_callframe` (21.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m06s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.8s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (22.3s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m44s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.4s — slowest: `moviecliploader` (20.8s)
