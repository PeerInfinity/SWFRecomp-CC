# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `2ed995cc460f`  
**Date:** 2026-06-28 20:18 UTC  
**Total duration:** 3h20m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 627 | 661 | 94.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 228 | 54.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 62 | 105 | 59.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 10 | 17 | 58.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **966** | **1159** | **83.3%** | |

*73 tests ignored.*

### ⚠️ Incomplete Runs

- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,044 | 111,695 | 94.0% |
| from_gnash/actionscript.all | 28,910 | 31,051 | 93.1% |
| from_gnash/misc-ming.all | 3,951 | 5,123 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 376 | 510 | 73.7% |
| from_gnash/misc-swfmill.all | 89 | 91 | 97.8% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **139,682** | **149,818** | **93.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 22 | 12 |
| from_gnash/actionscript.all | 9 | 94 |
| from_gnash/misc-ming.all | 15 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 4 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **49** | **144** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | watch_recursion_swf7 | 99% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 95% |
| from_gnash/actionscript.all | MovieClip-v6 | 95% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 85% |
| avm1 | bitmapdata_hittest_threshold | 83% |
| from_gnash/actionscript.all | TextField-v8 | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 627/661 (94.9%)
- **Ignored:** 43 tests
- **Duration:** 1h29m57s across 30 shards
- **Lines:** 105,044/111,695 matching (94.0%)
- **Avg test duration:** 7.6s — slowest: `init_object_invalid` (44.2s)

### from_gnash/actionscript.all

- **Pass:** 125/228 (54.8%)
- **Ignored:** 7 tests
- **Duration:** 38m30s across 29 shards
- **Lines:** 28,910/31,051 matching (93.1%)
- **Avg test duration:** 9.7s — slowest: `MovieClip-v8` (67.5s)

### from_gnash/misc-ming.all

- **Pass:** 62/105 (59.0%)
- **Ignored:** 2 tests
- **Duration:** 36m31s across 29 shards
- **Lines:** 3,951/5,123 matching (77.1%)
- **Avg test duration:** 20.4s — slowest: `matrix_test` (107.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m23s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.9s — slowest: `implementsOpTest` (23.5s)

### from_gnash/misc-swfc.all

- **Pass:** 10/17 (58.8%)
- **Ignored:** 2 tests
- **Duration:** 6m00s across 29 shards
- **Lines:** 376/510 matching (73.7%)
- **Avg test duration:** 19.7s — slowest: `movieclip_destruction_test3` (23.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m45s across 29 shards
- **Lines:** 89/91 matching (97.8%)
- **Avg test duration:** 21.3s — slowest: `background` (23.1s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 16m48s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 8.5s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (23.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 3m23s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 3.1s — slowest: `duplicateMovieClip/dontremove` (21.4s)
