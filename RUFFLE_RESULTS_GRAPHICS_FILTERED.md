# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `6fe6fb1a2f62`  
**Date:** 2026-05-24 23:52 UTC  
**Total duration:** 25m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 612 | 630 | 97.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 126 | 237 | 53.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 66 | 108 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **955** | **1141** | **83.7%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,353 | 97,257 | 99.1% |
| from_gnash/actionscript.all | 29,216 | 31,914 | 91.5% |
| from_gnash/misc-ming.all | 3,378 | 5,179 | 65.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **130,759** | **136,325** | **95.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault |
|-------|-----------------:|----------------:|---------------:|----------:|
| avm1 | 12 | 6 | - | - |
| from_gnash/actionscript.all | 14 | 93 | 4 | - |
| from_gnash/misc-ming.all | 14 | 26 | - | 2 |
| from_gnash/misc-mtasc.all | - | 2 | - | - |
| from_gnash/misc-swfc.all | 2 | 7 | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - |
| from_shumway | - | 3 | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **42** | **138** | **4** | **2** |

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

- **Pass:** 612/630 (97.1%)
- **Ignored:** 41 tests
- **Duration:** 13m04s across 30 shards
- **Lines:** 96,353/97,257 matching (99.1%)
- **Avg test duration:** 1.1s — slowest: `tab_ordering_children` (32.9s)

### from_gnash/actionscript.all

- **Pass:** 126/237 (53.2%)
- **Ignored:** 6 tests
- **Duration:** 4m49s across 30 shards
- **Lines:** 29,216/31,914 matching (91.5%)
- **Avg test duration:** 1.1s — slowest: `delete-v5` (22.6s)

### from_gnash/misc-ming.all

- **Pass:** 66/108 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 3m22s across 30 shards
- **Lines:** 3,378/5,179 matching (65.2%)
- **Avg test duration:** 1.6s — slowest: `register_class/registerClassTest` (24.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 17s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 0.8s — slowest: `action_execution_order_test10` (1.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 17s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 0.8s — slowest: `missing_bitmap` (1.4s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 2m24s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 1.1s — slowest: `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` (20.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 41s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 0.8s — slowest: `undefined/undefined-swf7` (2.0s)
