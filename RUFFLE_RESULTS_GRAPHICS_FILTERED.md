# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `5f25304460d4`  
**Date:** 2026-06-18 05:42 UTC  
**Total duration:** 3h13m44s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 599 | 639 | 93.7% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 131 | 229 | 57.2% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 64 | 104 | 61.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 70 | 73 | 95.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 42 | 42 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **939** | **1131** | **83.0%** | |

*68 tests ignored.*

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
| avm1 | 101,866 | 109,624 | 92.9% |
| from_gnash/actionscript.all | 28,832 | 31,059 | 92.8% |
| from_gnash/misc-ming.all | 3,925 | 5,062 | 77.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 400 | 521 | 76.8% |
| from_gnash/misc-swfmill.all | 91 | 93 | 97.8% |
| from_shumway | 617 | 633 | 97.5% |
| from_shumway/avm1 | 462 | 462 | 100% |
| **Total** | **136,404** | **147,685** | **92.4%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | segfault |
|-------|-----------------:|----------------:|----------:|
| avm1 | 26 | 10 | 4 |
| from_gnash/actionscript.all | 10 | 88 | - |
| from_gnash/misc-ming.all | 15 | 25 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **54** | **134** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
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
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 599/639 (93.7%)
- **Ignored:** 39 tests
- **Duration:** 1h26m11s across 29 shards
- **Lines:** 101,866/109,624 matching (92.9%)
- **Avg test duration:** 7.6s — slowest: `extends_chain` (38.7s)

### from_gnash/actionscript.all

- **Pass:** 131/229 (57.2%)
- **Ignored:** 6 tests
- **Duration:** 38m01s across 29 shards
- **Lines:** 28,832/31,059 matching (92.8%)
- **Avg test duration:** 9.7s — slowest: `MovieClip-v8` (68.2s)

### from_gnash/misc-ming.all

- **Pass:** 64/104 (61.5%)
- **Ignored:** 2 tests
- **Duration:** 35m30s across 29 shards
- **Lines:** 3,925/5,062 matching (77.5%)
- **Avg test duration:** 20.0s — slowest: `matrix_test` (101.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m34s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 17.1s — slowest: `implementsOpTest` (22.6s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Ignored:** 2 tests
- **Duration:** 5m32s across 29 shards
- **Lines:** 400/521 matching (76.8%)
- **Avg test duration:** 18.1s — slowest: `mouse_drag_test` (22.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m34s across 29 shards
- **Lines:** 91/93 matching (97.8%)
- **Avg test duration:** 20.7s — slowest: `background` (23.2s)

### from_shumway

- **Pass:** 70/73 (95.9%)
- **Ignored:** 16 tests
- **Duration:** 16m12s across 29 shards
- **Lines:** 617/633 matching (97.5%)
- **Avg test duration:** 8.4s — slowest: `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` (23.6s)

### from_shumway/avm1

- **Pass:** 42/42 (100%)
- **Ignored:** 3 tests
- **Duration:** 3m05s across 29 shards
- **Lines:** 462/462 matching (100%)
- **Avg test duration:** 2.8s — slowest: `label` (21.0s)
