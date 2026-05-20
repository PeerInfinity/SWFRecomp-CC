# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `81af77a89acb`  
**Date:** 2026-05-20 00:56 UTC  
**Total duration:** 2h13m00s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 661 | 91.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **950** | **1201** | **79.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,625 | 115,804 | 92.1% |
| from_gnash/actionscript.all | 27,767 | 38,787 | 71.6% |
| from_gnash/misc-ming.all | 4,003 | 5,239 | 76.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **140,494** | **162,480** | **86.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 46 |
| from_gnash/actionscript.all | 41 |
| from_gnash/misc-ming.all | 19 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **126** |

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
| from_gnash/actionscript.all | - | - | 1 | 1 |
| from_gnash/misc-ming.all | 1 | - | 1 | - |

*Comparing `879a8566b213` → `81af77a89acb`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/661 (91.4%)
- **Duration:** 58m19s across 30 shards
- **Lines:** 106,625/115,804 matching (92.1%)
- **Avg test duration:** 5.2s — slowest: `focusrect_swf5` (26.4s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 19m42s across 30 shards
- **Lines:** 27,767/38,787 matching (71.6%)
- **Avg test duration:** 4.8s — slowest: `MovieClip-v8` (67.9s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 27m17s across 30 shards
- **Lines:** 4,003/5,239 matching (76.4%)
- **Avg test duration:** 14.8s — slowest: `displaylist_depths/displaylist_depths_test` (26.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m09s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.3s — slowest: `hello` (18.9s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m29s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 14.1s — slowest: `movieclip_destruction_test4` (19.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m58s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 17.9s — slowest: `dict_callframe` (19.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m33s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.8s — slowest: `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` (21.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m29s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.8s — slowest: `text-bind` (19.0s)
