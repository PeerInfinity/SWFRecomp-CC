# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `716d0f7787b7`  
**Date:** 2026-06-13 03:47 UTC  
**Total duration:** 2h31m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 619 | 684 | 90.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 66 | 110 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 9 | 19 | 47.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **974** | **1224** | **79.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 113,322 | 125,829 | 90.1% |
| from_gnash/actionscript.all | 29,983 | 38,791 | 77.3% |
| from_gnash/misc-ming.all | 4,028 | 5,239 | 76.9% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 428 | 557 | 76.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **149,436** | **172,509** | **86.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 50 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 16 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **100** | **1** |

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
| avm1 | set_target_2_swf6 | 92% |
| avm1 | set_target_2_swf7 | 92% |
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

*No changes since last run.*

*Comparing `6dae4def3994` → `716d0f7787b7`*

## Per-Suite Details

### avm1

- **Pass:** 619/684 (90.5%)
- **Duration:** 1h11m53s across 30 shards
- **Lines:** 113,322/125,829 matching (90.1%)
- **Avg test duration:** 6.2s — slowest: `clone_sprite_edittext_dynamic` (44.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 19m27s across 30 shards
- **Lines:** 29,983/38,791 matching (77.3%)
- **Avg test duration:** 4.7s — slowest: `Transform-v8` (21.9s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 29m43s across 30 shards
- **Lines:** 4,028/5,239 matching (76.9%)
- **Avg test duration:** 16.1s — slowest: `loop/simple_loop_test` (27.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m21s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.7s — slowest: `hello` (21.0s)

### from_gnash/misc-swfc.all

- **Pass:** 9/19 (47.4%)
- **Duration:** 4m45s across 30 shards
- **Lines:** 428/557 matching (76.8%)
- **Avg test duration:** 15.0s — slowest: `movieclip_destruction_test4` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m22s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.1s — slowest: `background` (22.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m22s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.3s — slowest: `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` (23.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m11s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.7s — slowest: `text-bind` (22.1s)
