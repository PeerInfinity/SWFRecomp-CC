# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `5f25304460d4`  
**Date:** 2026-06-18 05:42 UTC  
**Total duration:** 3h13m44s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 601 | 678 | 88.6% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 134 | 235 | 57.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 106 | 61.3% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 18 | 44.4% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 70 | 89 | 78.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 44 | 45 | 97.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **947** | **1199** | **79.0%** | |

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
| avm1 | 112,191 | 128,649 | 87.2% |
| from_gnash/actionscript.all | 29,185 | 37,932 | 76.9% |
| from_gnash/misc-ming.all | 3,946 | 5,122 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 417 | 546 | 76.4% |
| from_gnash/misc-swfmill.all | 91 | 93 | 97.8% |
| from_shumway | 878 | 1,272 | 69.0% |
| from_shumway/avm1 | 471 | 473 | 99.6% |
| **Total** | **147,390** | **174,318** | **84.6%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_segfault |
|-------|-----------------:|------------------:|
| avm1 | 59 | 5 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 16 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 5 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 16 | - |
| from_shumway/avm1 | - | - |
| **Total** | **109** | **5** |

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

*Comparing `5bd16324c89f` → `5f25304460d4`*

## Per-Suite Details

### avm1

- **Pass:** 601/678 (88.6%)
- **Duration:** 1h26m11s across 29 shards
- **Lines:** 112,191/128,649 matching (87.2%)
- **Avg test duration:** 7.6s — slowest: `extends_chain` (38.7s)

### from_gnash/actionscript.all

- **Pass:** 134/235 (57.0%)
- **Duration:** 38m01s across 29 shards
- **Lines:** 29,185/37,932 matching (76.9%)
- **Avg test duration:** 9.6s — slowest: `MovieClip-v8` (68.2s)

### from_gnash/misc-ming.all

- **Pass:** 65/106 (61.3%)
- **Duration:** 35m30s across 29 shards
- **Lines:** 3,946/5,122 matching (77.0%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (101.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m34s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.1s — slowest: `implementsOpTest` (22.6s)

### from_gnash/misc-swfc.all

- **Pass:** 8/18 (44.4%)
- **Duration:** 5m32s across 29 shards
- **Lines:** 417/546 matching (76.4%)
- **Avg test duration:** 18.4s — slowest: `mouse_drag_test` (22.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m34s across 29 shards
- **Lines:** 91/93 matching (97.8%)
- **Avg test duration:** 20.7s — slowest: `background` (23.2s)

### from_shumway

- **Pass:** 70/89 (78.7%)
- **Duration:** 16m12s across 29 shards
- **Lines:** 878/1,272 matching (69.0%)
- **Avg test duration:** 10.9s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (25.3s)

### from_shumway/avm1

- **Pass:** 44/45 (97.8%)
- **Duration:** 3m05s across 29 shards
- **Lines:** 471/473 matching (99.6%)
- **Avg test duration:** 4.1s — slowest: `text-bind` (22.4s)
