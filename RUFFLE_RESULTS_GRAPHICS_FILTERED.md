# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `55d725fb0c25`  
**Date:** 2026-05-29 23:01 UTC  
**Total duration:** 2h53m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 614 | 632 | 97.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 127 | 237 | 53.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 108 | 60.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **957** | **1143** | **83.7%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,429 | 97,356 | 99.0% |
| from_gnash/actionscript.all | 29,486 | 31,918 | 92.4% |
| from_gnash/misc-ming.all | 4,003 | 5,179 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **131,730** | **136,428** | **96.6%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| avm1 | 12 | 6 | - |
| from_gnash/actionscript.all | 10 | 96 | 4 |
| from_gnash/misc-ming.all | 15 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 7 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **39** | **143** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
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

- **Pass:** 614/632 (97.2%)
- **Ignored:** 41 tests
- **Duration:** 1h18m30s across 30 shards
- **Lines:** 96,429/97,356 matching (99.0%)
- **Avg test duration:** 6.9s — slowest: `on_construct` (33.6s)

### from_gnash/actionscript.all

- **Pass:** 127/237 (53.6%)
- **Ignored:** 6 tests
- **Duration:** 29m32s across 30 shards
- **Lines:** 29,486/31,918 matching (92.4%)
- **Avg test duration:** 7.3s — slowest: `MovieClip-v8` (66.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/108 (60.2%)
- **Ignored:** 2 tests
- **Duration:** 33m13s across 30 shards
- **Lines:** 4,003/5,179 matching (77.3%)
- **Avg test duration:** 18.0s — slowest: `matrix_test` (100.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.3s — slowest: `implementsOpTest` (22.5s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 5m07s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 15.8s — slowest: `hello` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m36s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.8s — slowest: `dict_override` (21.8s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 15m44s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 8.1s — slowest: `avm1/text-bind` (22.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m23s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.2s — slowest: `label` (20.8s)
