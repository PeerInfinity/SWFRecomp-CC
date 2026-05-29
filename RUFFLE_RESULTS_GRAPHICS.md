# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `55d725fb0c25`  
**Date:** 2026-05-29 23:01 UTC  
**Total duration:** 2h53m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 616 | 673 | 91.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 130 | 243 | 53.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **964** | **1213** | **79.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,760 | 116,485 | 91.7% |
| from_gnash/actionscript.all | 29,839 | 38,791 | 76.9% |
| from_gnash/misc-ming.all | 4,017 | 5,239 | 76.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,715** | **163,165** | **87.5%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 44 | - | 2 |
| from_gnash/actionscript.all | 13 | 4 | - |
| from_gnash/misc-ming.all | 17 | - | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **94** | **4** | **2** |

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
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 2 | 105 |
| from_gnash/actionscript.all | 7 | - | 275 | - |
| from_gnash/misc-ming.all | - | - | 1 | - |

**avm1 — newly passing:** `with`

**from_gnash/actionscript.all — newly passing:** `getvariable-v5`, `getvariable-v6`, `getvariable-v7`, `getvariable-v8`

*Comparing `611d2674d88f` → `55d725fb0c25`*

## Per-Suite Details

### avm1

- **Pass:** 616/673 (91.5%)
- **Duration:** 1h18m30s across 30 shards
- **Lines:** 106,760/116,485 matching (91.7%)
- **Avg test duration:** 6.9s — slowest: `on_construct` (33.6s)

### from_gnash/actionscript.all

- **Pass:** 130/243 (53.5%)
- **Duration:** 29m32s across 30 shards
- **Lines:** 29,839/38,791 matching (76.9%)
- **Avg test duration:** 7.2s — slowest: `MovieClip-v8` (66.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 33m13s across 30 shards
- **Lines:** 4,017/5,239 matching (76.7%)
- **Avg test duration:** 18.1s — slowest: `matrix_test` (100.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.3s — slowest: `implementsOpTest` (22.5s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5m07s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 16.2s — slowest: `hello` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m36s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.8s — slowest: `dict_override` (21.8s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m44s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.2s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (23.3s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m23s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.0s — slowest: `text-bind` (21.9s)
