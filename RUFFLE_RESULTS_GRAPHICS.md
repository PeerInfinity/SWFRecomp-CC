# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e6a7f4923011`  
**Date:** 2026-05-25 20:45 UTC  
**Total duration:** 2h27m53s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 614 | 672 | 91.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 126 | 243 | 51.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **958** | **1212** | **79.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,675 | 116,411 | 91.6% |
| from_gnash/actionscript.all | 29,560 | 38,787 | 76.2% |
| from_gnash/misc-ming.all | 3,379 | 5,239 | 64.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **141,713** | **163,087** | **86.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 45 | - | 2 |
| from_gnash/actionscript.all | 20 | 4 | - |
| from_gnash/misc-ming.all | 17 | - | 2 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **102** | **4** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
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
| avm1 | - | - | - | 113 |

*Comparing `d018fcc20f02` → `e6a7f4923011`*

## Per-Suite Details

### avm1

- **Pass:** 614/672 (91.4%)
- **Duration:** 1h09m44s across 30 shards
- **Lines:** 106,675/116,411 matching (91.6%)
- **Avg test duration:** 6.2s — slowest: `tab_ordering_children` (28.3s)

### from_gnash/actionscript.all

- **Pass:** 126/243 (51.9%)
- **Duration:** 19m23s across 30 shards
- **Lines:** 29,560/38,787 matching (76.2%)
- **Avg test duration:** 4.7s — slowest: `TextFormat-v8` (22.2s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 29m08s across 30 shards
- **Lines:** 3,379/5,239 matching (64.5%)
- **Avg test duration:** 15.8s — slowest: `matrix_test` (24.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.3s — slowest: `TextFieldTest` (19.1s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m49s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 15.2s — slowest: `matrix_accuracy_test1` (21.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m26s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.3s — slowest: `func_dict` (21.6s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m09s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.2s — slowest: `avm1/text-bind` (22.0s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m20s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.9s — slowest: `text-bind` (21.4s)
