# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `fe0030e4fc7d`  
**Date:** 2026-06-18 22:05 UTC  
**Total duration:** 1h49m19s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 450 | 514 | 87.5% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 101 | 179 | 56.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 49 | 82 | 59.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 4 | 6 | 66.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 6 | 15 | 40.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 14 | 15 | 93.3% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 56 | 68 | 82.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 34 | 35 | 97.1% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **714** | **914** | **78.1%** | |

### ⚠️ Incomplete Runs

- **avm1**: 22/30 shards produced results (8 missing)
- **from_gnash/actionscript.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-ming.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-mtasc.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-swfc.all**: 22/30 shards produced results (8 missing)
- **from_gnash/misc-swfmill.all**: 22/30 shards produced results (8 missing)
- **from_shumway**: 22/30 shards produced results (8 missing)
- **from_shumway/avm1**: 22/30 shards produced results (8 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 90,620 | 106,882 | 84.8% |
| from_gnash/actionscript.all | 20,395 | 22,246 | 91.7% |
| from_gnash/misc-ming.all | 3,594 | 4,525 | 79.4% |
| from_gnash/misc-mtasc.all | 158 | 178 | 88.8% |
| from_gnash/misc-swfc.all | 391 | 508 | 77.0% |
| from_gnash/misc-swfmill.all | 67 | 69 | 97.1% |
| from_shumway | 707 | 1,009 | 70.1% |
| from_shumway/avm1 | 414 | 416 | 99.5% |
| **Total** | **116,346** | **135,833** | **85.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault | timeout |
|-------|-----------------:|------------------:|---------:|
| avm1 | 48 | 5 | - |
| from_gnash/actionscript.all | 7 | - | - |
| from_gnash/misc-ming.all | 11 | - | 1 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 11 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **82** | **5** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
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
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 13 | - |

## Per-Suite Details

### avm1

- **Pass:** 450/514 (87.5%)
- **Duration:** 43m18s across 22 shards
- **Lines:** 90,620/106,882 matching (84.8%)
- **Avg test duration:** 5.0s — slowest: `target_paths/swf4` (29.3s)

### from_gnash/actionscript.all

- **Pass:** 101/179 (56.4%)
- **Duration:** 20m01s across 22 shards
- **Lines:** 20,395/22,246 matching (91.7%)
- **Avg test duration:** 6.6s — slowest: `MovieClip-v8` (53.4s)

### from_gnash/misc-ming.all

- **Pass:** 49/82 (59.8%)
- **Duration:** 22m04s across 22 shards
- **Lines:** 3,594/4,525 matching (79.4%)
- **Avg test duration:** 16.1s — slowest: `matrix_test` (109.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 4/6 (66.7%)
- **Duration:** 1m30s across 22 shards
- **Lines:** 158/178 matching (88.8%)
- **Avg test duration:** 15.0s — slowest: `exception` (23.5s)

### from_gnash/misc-swfc.all

- **Pass:** 6/15 (40.0%)
- **Duration:** 4m15s across 22 shards
- **Lines:** 391/508 matching (77.0%)
- **Avg test duration:** 17.0s — slowest: `movieclip_destruction_test1` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/15 (93.3%)
- **Duration:** 5m00s across 22 shards
- **Lines:** 67/69 matching (97.1%)
- **Avg test duration:** 20.0s — slowest: `dict_callframe` (22.8s)

### from_shumway

- **Pass:** 56/68 (82.4%)
- **Duration:** 10m31s across 22 shards
- **Lines:** 707/1,009 matching (70.1%)
- **Avg test duration:** 9.2s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (27.9s)

### from_shumway/avm1

- **Pass:** 34/35 (97.1%)
- **Duration:** 2m37s across 22 shards
- **Lines:** 414/416 matching (99.5%)
- **Avg test duration:** 4.4s — slowest: `rollover` (21.6s)
