# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `8a8ff17c73a3`  
**Date:** 2026-07-10 22:53 UTC  
**Total duration:** 3h14m55s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 607 | 637 | 95.3% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 228 | 54.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 63 | 105 | 60.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 10 | 17 | 58.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 70 | 73 | 95.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 42 | 42 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| regression | 20 | 20 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| **Total** | **962** | **1150** | **83.7%** | |

*75 tests ignored.*

### ⚠️ Incomplete Runs

- **avm1**: 29/30 shards produced results (1 missing)
- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)
- **from_shumway**: 29/30 shards produced results (1 missing)
- **from_shumway/avm1**: 29/30 shards produced results (1 missing)
- **regression**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 103,623 | 107,132 | 96.7% |
| from_gnash/actionscript.all | 28,058 | 30,155 | 93.0% |
| from_gnash/misc-ming.all | 3,957 | 5,121 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 397 | 531 | 74.8% |
| from_gnash/misc-swfmill.all | 92 | 94 | 97.9% |
| from_shumway | 535 | 551 | 97.1% |
| from_shumway/avm1 | 461 | 461 | 100% |
| regression | 149 | 149 | 100% |
| **Total** | **137,483** | **144,425** | **95.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 18 | 12 |
| from_gnash/actionscript.all | 9 | 94 |
| from_gnash/misc-ming.all | 14 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 4 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| regression | - | - |
| **Total** | **44** | **144** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 607/637 (95.3%)
- **Ignored:** 45 tests
- **Duration:** 1h23m14s across 29 shards
- **Lines:** 103,623/107,132 matching (96.7%)
- **Avg test duration:** 7.4s — slowest: `try_catch_stack` (36.1s)

### from_gnash/actionscript.all

- **Pass:** 125/228 (54.8%)
- **Ignored:** 7 tests
- **Duration:** 36m18s across 29 shards
- **Lines:** 28,058/30,155 matching (93.0%)
- **Avg test duration:** 9.2s — slowest: `MovieClip-v8` (70.5s)

### from_gnash/misc-ming.all

- **Pass:** 63/105 (60.0%)
- **Ignored:** 2 tests
- **Duration:** 35m34s across 29 shards
- **Lines:** 3,957/5,121 matching (77.3%)
- **Avg test duration:** 19.9s — slowest: `matrix_test` (104.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m14s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.8s — slowest: `exception` (22.1s)

### from_gnash/misc-swfc.all

- **Pass:** 10/17 (58.8%)
- **Ignored:** 2 tests
- **Duration:** 5m42s across 29 shards
- **Lines:** 397/531 matching (74.8%)
- **Avg test duration:** 18.7s — slowest: `movieclip_destruction_test3` (23.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m24s across 29 shards
- **Lines:** 92/94 matching (97.9%)
- **Avg test duration:** 20.2s — slowest: `missing_bitmap` (23.0s)

### from_shumway

- **Pass:** 70/73 (95.9%)
- **Ignored:** 16 tests
- **Duration:** 15m35s across 29 shards
- **Lines:** 535/551 matching (97.1%)
- **Avg test duration:** 8.2s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (22.5s)

### from_shumway/avm1

- **Pass:** 42/42 (100%)
- **Ignored:** 3 tests
- **Duration:** 3m09s across 29 shards
- **Lines:** 461/461 matching (100%)
- **Avg test duration:** 3.0s — slowest: `label` (20.6s)

### regression

- **Pass:** 20/20 (100%)
- **Duration:** 6m40s across 29 shards
- **Lines:** 149/149 matching (100%)
- **Avg test duration:** 20.0s — slowest: `fn_empty_method_type1_args` (21.8s)
