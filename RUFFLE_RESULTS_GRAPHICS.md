# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `dbbac2761e17`  
**Date:** 2026-05-28 22:50 UTC  
**Total duration:** 3h11m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 614 | 673 | 91.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 122 | 243 | 50.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **954** | **1213** | **78.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,819 | 116,485 | 91.7% |
| from_gnash/actionscript.all | 29,488 | 38,791 | 76.0% |
| from_gnash/misc-ming.all | 4,016 | 5,239 | 76.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,422** | **163,165** | **87.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 47 | - | 1 |
| from_gnash/actionscript.all | 24 | 4 | - |
| from_gnash/misc-ming.all | 17 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **108** | **4** | **1** |

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
| avm1 | with | 96% |
| from_gnash/actionscript.all | getvariable-v7 | 95% |
| from_gnash/actionscript.all | getvariable-v8 | 95% |
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v7 | 89% |
| from_gnash/actionscript.all | MovieClip-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 114 | - |
| from_gnash/actionscript.all | - | 4 | - | 76 |
| from_gnash/misc-ming.all | 2 | - | 637 | - |

**from_gnash/actionscript.all — newly failing:** `delete-v5`, `delete-v6`, `delete-v7`, `delete-v8`

*Comparing `e6a7f4923011` → `dbbac2761e17`*

## Per-Suite Details

### avm1

- **Pass:** 614/673 (91.2%)
- **Duration:** 1h24m08s across 30 shards
- **Lines:** 106,819/116,485 matching (91.7%)
- **Avg test duration:** 7.4s — slowest: `globals_swf7` (37.5s)

### from_gnash/actionscript.all

- **Pass:** 122/243 (50.2%)
- **Duration:** 38m16s across 30 shards
- **Lines:** 29,488/38,791 matching (76.0%)
- **Avg test duration:** 9.4s — slowest: `MovieClip-v8` (63.9s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 35m20s across 30 shards
- **Lines:** 4,016/5,239 matching (76.7%)
- **Avg test duration:** 19.2s — slowest: `matrix_test` (102.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.0s — slowest: `inheritance` (21.1s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5m17s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 16.6s — slowest: `movieclip_destruction_test3` (23.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m34s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.7s — slowest: `missing_bitmap` (22.8s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 16m35s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.8s — slowest: `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` (23.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m31s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.2s — slowest: `text-bind` (22.3s)
