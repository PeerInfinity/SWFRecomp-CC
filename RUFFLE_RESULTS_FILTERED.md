# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `491435c0ec1e`  
**Date:** 2026-04-21 17:04 UTC  
**Total duration:** 1h56m22s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 595 | 600 | 99.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 109 | 190 | 57.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 19 | 102 | 18.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 3 | 16 | 18.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 61 | 92 | 66.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **854** | **1072** | **79.7%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,896 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,325 | 16,957 | 84.5% |
| from_gnash/misc-ming.all | 2,175 | 4,541 | 47.9% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 219 | 499 | 43.9% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **113,009** | **119,128** | **94.9%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | - | 1 | 4 |
| from_gnash/actionscript.all | - | 38 | 43 |
| from_gnash/misc-ming.all | 1 | 71 | 11 |
| from_gnash/misc-mtasc.all | - | 1 | 1 |
| from_gnash/misc-swfc.all | - | 10 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | - | 30 | 1 |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **153** | **64** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_gnash/actionscript.all | LoadVars-v6 | 96% |
| from_gnash/actionscript.all | LoadVars-v7 | 96% |
| from_gnash/actionscript.all | LoadVars-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/actionscript.all | Selection-v6 | 94% |
| from_gnash/actionscript.all | Selection-v7 | 94% |
| from_gnash/actionscript.all | Selection-v8 | 94% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 92% |
| avm1 | register_and_init_order | 92% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/misc-ming.all | get_frame_number_test | 87% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/misc-ming.all | loop/loop_test4 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 595/600 (99.2%)
- **Ignored:** 41 tests
- **Duration:** 54m10s across 30 shards
- **Lines:** 94,896/95,093 matching (99.8%)
- **Avg test duration:** 5.0s — slowest: `mcl_unloadclip` (22.1s)

### from_gnash/actionscript.all

- **Pass:** 109/190 (57.4%)
- **Duration:** 13m21s across 30 shards
- **Lines:** 14,325/16,957 matching (84.5%)
- **Avg test duration:** 4.2s — slowest: `array-v5` (27.7s)

### from_gnash/misc-ming.all

- **Pass:** 19/102 (18.6%)
- **Duration:** 23m45s across 30 shards
- **Lines:** 2,175/4,541 matching (47.9%)
- **Avg test duration:** 13.9s — slowest: `DefineEditTextTest` (28.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 11.6s — slowest: `TextFieldTest` (19.2s)

### from_gnash/misc-swfc.all

- **Pass:** 3/16 (18.8%)
- **Duration:** 3m53s across 30 shards
- **Lines:** 219/499 matching (43.9%)
- **Avg test duration:** 14.5s — slowest: `action_execution_order_test10` (19.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m56s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 16.4s — slowest: `background` (18.4s)

### from_shumway

- **Pass:** 61/92 (66.3%)
- **Duration:** 12m42s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 8.2s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (18.0s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m47s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.9s — slowest: `label` (18.1s)
