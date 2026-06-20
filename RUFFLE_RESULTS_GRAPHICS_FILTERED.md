# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `6dcffb0b490f`  
**Date:** 2026-06-20 21:16 UTC  
**Total duration:** 2h22m38s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 627 | 656 | 95.6% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 228 | 54.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 62 | 105 | 59.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 10 | 17 | 58.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 18 | 19 | 94.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **966** | **1154** | **83.7%** | |

*75 tests ignored.*

### ⚠️ Incomplete Runs

- **from_gnash/actionscript.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-ming.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-mtasc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfc.all**: 29/30 shards produced results (1 missing)
- **from_gnash/misc-swfmill.all**: 29/30 shards produced results (1 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 103,587 | 107,511 | 96.4% |
| from_gnash/actionscript.all | 28,910 | 31,051 | 93.1% |
| from_gnash/misc-ming.all | 3,951 | 5,123 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 376 | 510 | 73.7% |
| from_gnash/misc-swfmill.all | 89 | 91 | 97.8% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **138,225** | **145,634** | **94.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 16 | 13 |
| from_gnash/actionscript.all | 9 | 94 |
| from_gnash/misc-ming.all | 15 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 4 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **43** | **145** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
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
| from_gnash/actionscript.all | TextField-v8 | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 627/656 (95.6%)
- **Ignored:** 45 tests
- **Duration:** 51m39s across 30 shards
- **Lines:** 103,587/107,511 matching (96.4%)
- **Avg test duration:** 4.3s — slowest: `movieclip_begin_gradient_fill` (28.5s)

### from_gnash/actionscript.all

- **Pass:** 125/228 (54.8%)
- **Ignored:** 7 tests
- **Duration:** 29m17s across 29 shards
- **Lines:** 28,910/31,051 matching (93.1%)
- **Avg test duration:** 7.3s — slowest: `MovieClip-v8` (64.8s)

### from_gnash/misc-ming.all

- **Pass:** 62/105 (59.0%)
- **Ignored:** 2 tests
- **Duration:** 32m40s across 29 shards
- **Lines:** 3,951/5,123 matching (77.1%)
- **Avg test duration:** 18.2s — slowest: `matrix_test` (108.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 45s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 4.9s — slowest: `TextFieldTest` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 10/17 (58.8%)
- **Ignored:** 2 tests
- **Duration:** 4m50s across 29 shards
- **Lines:** 376/510 matching (73.7%)
- **Avg test duration:** 15.6s — slowest: `movieclip_destruction_test2` (23.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/19 (94.7%)
- **Duration:** 6m16s across 29 shards
- **Lines:** 89/91 matching (97.8%)
- **Avg test duration:** 19.8s — slowest: `background` (23.9s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m44s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 6.9s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (23.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m23s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.2s — slowest: `label` (21.6s)
