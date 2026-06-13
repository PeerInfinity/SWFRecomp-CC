# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `eb3bc573d2da`  
**Date:** 2026-06-13 20:01 UTC  
**Total duration:** 2h48m46s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 664 | 90.4% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 127 | 235 | 54.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 65 | 107 | 60.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 9 | 19 | 47.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 72 | 89 | 80.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 46 | 97.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **944** | **1189** | **79.4%** | |

### ⚠️ Incomplete Runs

- **avm1**: 29/30 shards produced results (1 missing)
- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)
- **from_shumway**: 29/30 shards produced results (1 missing)
- **from_shumway/avm1**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 109,788 | 120,960 | 90.8% |
| from_gnash/actionscript.all | 29,586 | 38,394 | 77.1% |
| from_gnash/misc-ming.all | 3,967 | 5,134 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 428 | 557 | 76.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 840 | 1,190 | 70.6% |
| from_shumway/avm1 | 450 | 452 | 99.6% |
| **Total** | **145,363** | **167,013** | **87.0%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 53 |
| from_gnash/actionscript.all | 13 |
| from_gnash/misc-ming.all | 14 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 14 |
| from_shumway/avm1 | - |
| **Total** | **99** |

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

*Comparing `c764b605aa9a` → `eb3bc573d2da`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/664 (90.4%)
- **Duration:** 1h10m57s across 29 shards
- **Lines:** 109,788/120,960 matching (90.8%)
- **Avg test duration:** 6.3s — slowest: `netstream_play_flv_screen` (35.6s)

### from_gnash/actionscript.all

- **Pass:** 127/235 (54.0%)
- **Duration:** 34m35s across 29 shards
- **Lines:** 29,586/38,394 matching (77.1%)
- **Avg test duration:** 8.8s — slowest: `MovieClip-v8` (64.3s)

### from_gnash/misc-ming.all

- **Pass:** 65/107 (60.7%)
- **Duration:** 32m58s across 29 shards
- **Lines:** 3,967/5,134 matching (77.3%)
- **Avg test duration:** 18.4s — slowest: `matrix_test` (102.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m28s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.5s — slowest: `exception` (21.5s)

### from_gnash/misc-swfc.all

- **Pass:** 9/19 (47.4%)
- **Duration:** 5m05s across 29 shards
- **Lines:** 428/557 matching (76.8%)
- **Avg test duration:** 16.0s — slowest: `movieclip_destruction_test4` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m24s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.2s — slowest: `mixed-bytecode-as2` (20.5s)

### from_shumway

- **Pass:** 72/89 (80.9%)
- **Duration:** 14m14s across 29 shards
- **Lines:** 840/1,190 matching (70.6%)
- **Avg test duration:** 9.5s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (22.0s)

### from_shumway/avm1

- **Pass:** 45/46 (97.8%)
- **Duration:** 2m03s across 29 shards
- **Lines:** 450/452 matching (99.6%)
- **Avg test duration:** 2.6s — slowest: `text-bind` (20.2s)
