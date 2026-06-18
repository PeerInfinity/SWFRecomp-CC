# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `fe0030e4fc7d`  
**Date:** 2026-06-18 21:40 UTC  
**Total duration:** 2h06m01s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 532 | 608 | 87.5% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 113 | 203 | 55.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 55 | 92 | 59.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 6 | 8 | 75.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 15 | 16 | 93.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 65 | 80 | 81.2% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 40 | 41 | 97.6% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **834** | **1064** | **78.4%** | |

### ⚠️ Incomplete Runs

- **avm1**: 26/30 shards produced results (4 missing)
- **from_gnash/actionscript.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-ming.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-mtasc.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-swfc.all**: 25/30 shards produced results (5 missing)
- **from_gnash/misc-swfmill.all**: 25/30 shards produced results (5 missing)
- **from_shumway**: 26/30 shards produced results (4 missing)
- **from_shumway/avm1**: 26/30 shards produced results (4 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 107,946 | 124,365 | 86.8% |
| from_gnash/actionscript.all | 23,302 | 31,325 | 74.4% |
| from_gnash/misc-ming.all | 3,753 | 4,771 | 78.7% |
| from_gnash/misc-mtasc.all | 203 | 223 | 91.0% |
| from_gnash/misc-swfc.all | 374 | 468 | 79.9% |
| from_gnash/misc-swfmill.all | 40 | 42 | 95.2% |
| from_shumway | 786 | 1,102 | 71.3% |
| from_shumway/avm1 | 419 | 421 | 99.5% |
| **Total** | **136,823** | **162,717** | **84.1%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 56 | 5 |
| from_gnash/actionscript.all | 6 | - |
| from_gnash/misc-ming.all | 15 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 13 | - |
| from_shumway/avm1 | - | - |
| **Total** | **94** | **5** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm1 | set_target_2_swf6 | 92% |
| avm1 | set_target_2_swf7 | 92% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 13 |

*Comparing `f9f0700382a1` → `fe0030e4fc7d`*

## Per-Suite Details

### avm1

- **Pass:** 532/608 (87.5%)
- **Duration:** 52m41s across 26 shards
- **Lines:** 107,946/124,365 matching (86.8%)
- **Avg test duration:** 5.1s — slowest: `focus_remove` (39.5s)

### from_gnash/actionscript.all

- **Pass:** 113/203 (55.7%)
- **Duration:** 22m55s across 25 shards
- **Lines:** 23,302/31,325 matching (74.4%)
- **Avg test duration:** 6.7s — slowest: `MovieClip-v8` (66.0s)

### from_gnash/misc-ming.all

- **Pass:** 55/92 (59.8%)
- **Duration:** 23m02s across 25 shards
- **Lines:** 3,753/4,771 matching (78.7%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (103.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m09s across 25 shards
- **Lines:** 203/223 matching (91.0%)
- **Avg test duration:** 16.1s — slowest: `exception` (22.9s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m20s across 25 shards
- **Lines:** 374/468 matching (79.9%)
- **Avg test duration:** 16.2s — slowest: `mouse_drag_test` (22.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/16 (93.8%)
- **Duration:** 5m23s across 25 shards
- **Lines:** 40/42 matching (95.2%)
- **Avg test duration:** 20.2s — slowest: `jump_after_end` (22.4s)

### from_shumway

- **Pass:** 65/80 (81.2%)
- **Duration:** 12m16s across 26 shards
- **Lines:** 786/1,102 matching (71.3%)
- **Avg test duration:** 9.1s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (23.4s)

### from_shumway/avm1

- **Pass:** 40/41 (97.6%)
- **Duration:** 3m12s across 26 shards
- **Lines:** 419/421 matching (99.5%)
- **Avg test duration:** 4.6s — slowest: `label` (22.3s)
