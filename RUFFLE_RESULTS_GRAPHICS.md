# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6fe6fb1a2f62`  
**Date:** 2026-05-24 23:52 UTC  
**Total duration:** 25m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 614 | 671 | 91.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 126 | 243 | 51.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 66 | 110 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **959** | **1211** | **79.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,788 | 116,386 | 91.8% |
| from_gnash/actionscript.all | 29,560 | 38,787 | 76.2% |
| from_gnash/misc-ming.all | 3,392 | 5,239 | 64.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **141,839** | **163,062** | **87.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 45 | - | 1 |
| from_gnash/actionscript.all | 20 | 4 | - |
| from_gnash/misc-ming.all | 16 | - | 2 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **101** | **4** | **3** |

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
| avm1 | 2 | 1 | 188 | 2 |
| from_gnash/actionscript.all | 24 | 5 | 1862 | 16 |
| from_gnash/misc-ming.all | 7 | - | 60 | 4 |
| from_gnash/misc-swfc.all | 1 | - | 12 | - |

**avm1 — newly passing:** `sound_gettransform_props`, `swf5_xml_event_handler_context`

**avm1 — newly failing:** `with`

**from_gnash/actionscript.all — newly failing:** `case-v5`

**from_gnash/misc-ming.all — newly passing:** `loop/loop_test`, `loop/loop_test2`, `loop/loop_test3`

*Comparing `be9aafd78ec0` → `6fe6fb1a2f62`*

## Per-Suite Details

### avm1

- **Pass:** 614/671 (91.5%)
- **Duration:** 13m04s across 30 shards
- **Lines:** 106,788/116,386 matching (91.8%)
- **Avg test duration:** 1.1s — slowest: `tab_ordering_children` (32.9s)

### from_gnash/actionscript.all

- **Pass:** 126/243 (51.9%)
- **Duration:** 4m49s across 30 shards
- **Lines:** 29,560/38,787 matching (76.2%)
- **Avg test duration:** 1.1s — slowest: `delete-v5` (22.6s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 3m22s across 30 shards
- **Lines:** 3,392/5,239 matching (64.7%)
- **Avg test duration:** 1.8s — slowest: `register_class/registerClassTest` (24.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 17s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 0.8s — slowest: `action_execution_order_test10` (1.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 17s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 0.8s — slowest: `missing_bitmap` (1.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 1.5s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (22.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 41s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.8s — slowest: `undefined/undefined-swf7` (2.0s)
