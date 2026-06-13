# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `828b69b82dfb`  
**Date:** 2026-06-13 23:44 UTC  
**Total duration:** 2h47m39s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 624 | 95.5% ⚠️ | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 132 | 229 | 57.6% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 62 | 105 | 59.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 9 | 17 | 52.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 70 | 73 | 95.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 43 | 43 | 100% ⚠️ | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **938** | **1120** | **83.8%** | |

*70 tests ignored.*

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
| avm1 | 102,408 | 106,225 | 96.4% |
| from_gnash/actionscript.all | 28,602 | 30,666 | 93.3% |
| from_gnash/misc-ming.all | 3,968 | 5,140 | 77.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 411 | 532 | 77.3% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 618 | 634 | 97.5% |
| from_shumway/avm1 | 479 | 479 | 100% |
| **Total** | **136,790** | **144,002** | **95.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 19 | 9 |
| from_gnash/actionscript.all | 10 | 87 |
| from_gnash/misc-ming.all | 15 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **47** | **135** |

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

- **Pass:** 596/624 (95.5%)
- **Ignored:** 41 tests
- **Duration:** 1h09m26s across 29 shards
- **Lines:** 102,408/106,225 matching (96.4%)
- **Avg test duration:** 6.3s — slowest: `biturshift_swf8` (36.0s)

### from_gnash/actionscript.all

- **Pass:** 132/229 (57.6%)
- **Ignored:** 6 tests
- **Duration:** 33m28s across 29 shards
- **Lines:** 28,602/30,666 matching (93.3%)
- **Avg test duration:** 8.6s — slowest: `MovieClip-v8` (64.0s)

### from_gnash/misc-ming.all

- **Pass:** 62/105 (59.0%)
- **Ignored:** 2 tests
- **Duration:** 32m53s across 29 shards
- **Lines:** 3,968/5,140 matching (77.2%)
- **Avg test duration:** 18.6s — slowest: `matrix_test` (107.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m31s across 29 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.8s — slowest: `TextFieldTest` (21.7s)

### from_gnash/misc-swfc.all

- **Pass:** 9/17 (52.9%)
- **Ignored:** 2 tests
- **Duration:** 5m11s across 29 shards
- **Lines:** 411/532 matching (77.3%)
- **Avg test duration:** 15.7s — slowest: `movieclip_destruction_test1` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m53s across 29 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 20.6s — slowest: `background` (22.6s)

### from_shumway

- **Pass:** 70/73 (95.9%)
- **Ignored:** 16 tests
- **Duration:** 14m28s across 29 shards
- **Lines:** 618/634 matching (97.5%)
- **Avg test duration:** 7.1s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (23.5s)

### from_shumway/avm1

- **Pass:** 43/43 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m46s across 29 shards
- **Lines:** 479/479 matching (100%)
- **Avg test duration:** 2.8s — slowest: `label` (21.3s)
