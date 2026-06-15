# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `efddd2eaf784`  
**Date:** 2026-06-15 19:58 UTC  
**Total duration:** 2h12m02s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 620 | 690 | 89.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 67 | 110 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 9 | 19 | 47.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **976** | **1230** | **79.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 113,395 | 125,905 | 90.1% |
| from_gnash/actionscript.all | 29,983 | 38,791 | 77.3% |
| from_gnash/misc-ming.all | 4,033 | 5,239 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 428 | 557 | 76.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **149,514** | **172,585** | **86.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 56 |
| from_gnash/actionscript.all | 13 |
| from_gnash/misc-ming.all | 15 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **105** |

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

*Comparing `3f8c0c1ec7c8` → `efddd2eaf784`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 620/690 (89.9%)
- **Duration:** 50m18s across 30 shards
- **Lines:** 113,395/125,905 matching (90.1%)
- **Avg test duration:** 4.3s — slowest: `netstream_play_flv_screen` (35.1s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 27m20s across 30 shards
- **Lines:** 29,983/38,791 matching (77.3%)
- **Avg test duration:** 6.7s — slowest: `MovieClip-v8` (62.7s)

### from_gnash/misc-ming.all

- **Pass:** 67/110 (60.9%)
- **Duration:** 28m58s across 30 shards
- **Lines:** 4,033/5,239 matching (77.0%)
- **Avg test duration:** 15.7s — slowest: `matrix_test` (104.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.2s — slowest: `inheritance` (21.6s)

### from_gnash/misc-swfc.all

- **Pass:** 9/19 (47.4%)
- **Duration:** 4m20s across 30 shards
- **Lines:** 428/557 matching (76.8%)
- **Avg test duration:** 13.6s — slowest: `soft_reference_test1` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m07s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 9.3s — slowest: `dict_callframe` (20.6s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m40s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.9s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (23.1s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m50s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.3s — slowest: `hitarea` (20.6s)
