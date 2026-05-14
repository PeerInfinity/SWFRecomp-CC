# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `17a60dbb6837`  
**Date:** 2026-05-14 21:43 UTC  
**Total duration:** 23m33s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 603 | 613 | 98.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 243 | 51.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 108 | 60.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 18 | 44.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 18 | 20 | 90.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **944** | **1132** | **83.4%** | |

*62 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,052 | 96,454 | 99.6% |
| from_gnash/actionscript.all | 27,666 | 38,787 | 71.3% |
| from_gnash/misc-ming.all | 3,355 | 5,179 | 64.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 405 | 550 | 73.6% |
| from_gnash/misc-swfmill.all | 87 | 95 | 91.6% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **128,877** | **142,413** | **90.5%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault |
|-------|-----------------:|----------------:|---------------:|----------:|
| avm1 | 4 | 6 | - | - |
| from_gnash/actionscript.all | 46 | 68 | 4 | - |
| from_gnash/misc-ming.all | 18 | 23 | - | 2 |
| from_gnash/misc-mtasc.all | - | 2 | - | - |
| from_gnash/misc-swfc.all | 4 | 6 | - | - |
| from_gnash/misc-swfmill.all | 1 | 1 | - | - |
| from_shumway | - | 3 | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **73** | **109** | **4** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | Date-v7 | 98% |
| from_gnash/actionscript.all | Date-v8 | 98% |
| from_gnash/actionscript.all | Date-v6 | 97% |
| from_gnash/actionscript.all | Date-v5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | Object-v5 | 93% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/actionscript.all | flash-v8 | 88% |
| from_gnash/actionscript.all | Object-v7 | 88% |
| from_gnash/actionscript.all | Object-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | Stage-v6 | 84% |
| from_gnash/actionscript.all | Stage-v7 | 84% |
| from_gnash/actionscript.all | Stage-v8 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test | 84% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| from_gnash/actionscript.all | Object-v6 | 84% |
| from_gnash/misc-swfmill.all | registers | 83% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 603/613 (98.4%)
- **Ignored:** 41 tests
- **Duration:** 12m42s across 30 shards
- **Lines:** 96,052/96,454 matching (99.6%)
- **Avg test duration:** 1.1s — slowest: `local_to_global` (18.9s)

### from_gnash/actionscript.all

- **Pass:** 125/243 (51.4%)
- **Duration:** 5m01s across 30 shards
- **Lines:** 27,666/38,787 matching (71.3%)
- **Avg test duration:** 1.2s — slowest: `argstest-v7` (2.6s)

### from_gnash/misc-ming.all

- **Pass:** 65/108 (60.2%)
- **Ignored:** 2 tests
- **Duration:** 2m50s across 30 shards
- **Lines:** 3,355/5,179 matching (64.8%)
- **Avg test duration:** 1.5s — slowest: `matrix_test` (6.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/18 (44.4%)
- **Ignored:** 1 tests
- **Duration:** 19s across 30 shards
- **Lines:** 405/550 matching (73.6%)
- **Avg test duration:** 0.9s — slowest: `action_execution_order_test10` (1.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/20 (90.0%)
- **Duration:** 19s across 30 shards
- **Lines:** 87/95 matching (91.6%)
- **Avg test duration:** 0.9s — slowest: `background` (2.4s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 1m31s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 0.9s — slowest: `timeline/timeline_as2_5` (4.0s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 42s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.8s — slowest: `text-bind` (2.4s)
