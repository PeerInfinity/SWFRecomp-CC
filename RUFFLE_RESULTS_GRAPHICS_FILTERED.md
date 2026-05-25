# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `e6a7f4923011`  
**Date:** 2026-05-25 20:45 UTC  
**Total duration:** 2h27m53s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 612 | 631 | 97.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 126 | 237 | 53.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 108 | 60.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **954** | **1142** | **83.5%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,353 | 97,282 | 99.0% |
| from_gnash/actionscript.all | 29,216 | 31,914 | 91.5% |
| from_gnash/misc-ming.all | 3,365 | 5,179 | 65.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **130,746** | **136,350** | **95.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault |
|-------|-----------------:|----------------:|---------------:|----------:|
| avm1 | 13 | 6 | - | - |
| from_gnash/actionscript.all | 14 | 93 | 4 | - |
| from_gnash/misc-ming.all | 15 | 26 | - | 2 |
| from_gnash/misc-mtasc.all | - | 2 | - | - |
| from_gnash/misc-swfc.all | 2 | 7 | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - |
| from_shumway | - | 3 | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **44** | **138** | **4** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| avm1 | with | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v7 | 89% |
| from_gnash/actionscript.all | MovieClip-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 612/631 (97.0%)
- **Ignored:** 41 tests
- **Duration:** 1h09m44s across 30 shards
- **Lines:** 96,353/97,282 matching (99.0%)
- **Avg test duration:** 6.2s — slowest: `tab_ordering_children` (28.3s)

### from_gnash/actionscript.all

- **Pass:** 126/237 (53.2%)
- **Ignored:** 6 tests
- **Duration:** 19m23s across 30 shards
- **Lines:** 29,216/31,914 matching (91.5%)
- **Avg test duration:** 4.8s — slowest: `TextFormat-v8` (22.2s)

### from_gnash/misc-ming.all

- **Pass:** 65/108 (60.2%)
- **Ignored:** 2 tests
- **Duration:** 29m08s across 30 shards
- **Lines:** 3,365/5,179 matching (65.0%)
- **Avg test duration:** 15.8s — slowest: `matrix_test` (24.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m51s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.3s — slowest: `TextFieldTest` (19.1s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 4m49s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 14.6s — slowest: `opcode_guard_test2` (19.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m26s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.3s — slowest: `func_dict` (21.6s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m09s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.0s — slowest: `avm1/text-bind` (22.0s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m20s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.8s — slowest: `label` (20.8s)
