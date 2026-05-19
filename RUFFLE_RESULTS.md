# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2dd16744ffd2`  
**Date:** 2026-05-19 22:53 UTC  
**Total duration:** 7m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 661 | 91.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 64 | 110 | 58.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **949** | **1201** | **79.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,625 | 115,804 | 92.1% |
| from_gnash/actionscript.all | 27,767 | 38,787 | 71.6% |
| from_gnash/misc-ming.all | 3,980 | 5,239 | 76.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **140,471** | **162,480** | **86.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 46 |
| from_gnash/actionscript.all | 41 |
| from_gnash/misc-ming.all | 22 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
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
| from_gnash/actionscript.all | getvariable-v7 | 92% |
| from_gnash/actionscript.all | getvariable-v8 | 92% |
| from_gnash/actionscript.all | getvariable-v6 | 91% |
| from_gnash/actionscript.all | Object-v7 | 90% |
| from_gnash/actionscript.all | Object-v8 | 90% |
| from_gnash/actionscript.all | getvariable-v5 | 90% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Object-v6 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | Transform-v8 | 85% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| avm1 | sound_getters | 84% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | - | - | - | 1 |
| from_gnash/misc-ming.all | - | - | 4 | 3 |
| from_gnash/misc-swfc.all | 1 | - | 12 | - |

*Comparing `80e4118e5538` → `2dd16744ffd2`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/661 (91.4%)
- **Duration:** 4m10s across 30 shards
- **Lines:** 106,625/115,804 matching (92.1%)
- **Avg test duration:** 0.3s — slowest: `timeout` (5.2s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 27,767/38,787 matching (71.6%)
- **Avg test duration:** 0.4s — slowest: `MovieClip-v8` (2.1s)

### from_gnash/misc-ming.all

- **Pass:** 64/110 (58.2%)
- **Duration:** 44s across 30 shards
- **Lines:** 3,980/5,239 matching (76.0%)
- **Avg test duration:** 0.3s — slowest: `matrix_test` (3.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.2s — slowest: `levels` (0.3s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 0.2s — slowest: `movieclip_destruction_test1` (0.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 0.2s — slowest: `dict_callframe` (0.7s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 28s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 0.2s — slowest: `avm1/duplicateMovieClip/duplicateMovieClip` (0.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 14s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.2s — slowest: `doactionorder/doactionorder` (1.6s)
