# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `756d4cbcac21`  
**Date:** 2026-04-19 01:30 UTC  
**Total duration:** 1h43m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 600 | 99.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 107 | 190 | 56.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 60 | 92 | 65.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 45 | 97.8% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **849** | **1072** | **79.2%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,917 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 13,993 | 16,957 | 82.5% |
| from_gnash/misc-ming.all | 2,119 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 215 | 499 | 43.1% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 656 | 1,276 | 51.4% |
| from_shumway/avm1 | 476 | 480 | 99.2% |
| **Total** | **112,594** | **119,128** | **94.5%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched | runtime_error |
|-------|--------------:|-----------------:|----------------:|---------------:|
| avm1 | - | - | 3 | - |
| from_gnash/actionscript.all | - | 51 | 32 | - |
| from_gnash/misc-ming.all | 1 | 73 | 10 | - |
| from_gnash/misc-mtasc.all | - | 1 | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 3 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | 1 | - |
| from_shumway | - | 31 | 1 | - |
| from_shumway/avm1 | - | 1 | - | - |
| **Total** | **1** | **170** | **51** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_gnash/actionscript.all | Number-v6 | 97% |
| from_gnash/actionscript.all | Number-v7 | 97% |
| from_gnash/actionscript.all | Number-v8 | 97% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 95% |
| from_gnash/actionscript.all | Selection-v6 | 94% |
| from_gnash/actionscript.all | Selection-v7 | 94% |
| from_gnash/actionscript.all | Selection-v8 | 94% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 94% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 94% |
| from_gnash/actionscript.all | Number-v5 | 93% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 92% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/actionscript.all | BitmapData-v8 | 91% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/actionscript.all | Matrix-v6 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | get_frame_number_test | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test11 | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/600 (99.5%)
- **Ignored:** 41 tests
- **Duration:** 48m30s across 30 shards
- **Lines:** 94,917/95,093 matching (99.8%)
- **Avg test duration:** 4.5s — slowest: `swf4_actions_coercion_order` (17.6s)

### from_gnash/actionscript.all

- **Pass:** 107/190 (56.3%)
- **Duration:** 10m28s across 30 shards
- **Lines:** 13,993/16,957 matching (82.5%)
- **Avg test duration:** 3.3s — slowest: `targetPath-v5` (16.9s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 21m19s across 30 shards
- **Lines:** 2,119/4,541 matching (46.7%)
- **Avg test duration:** 12.5s — slowest: `matrix_test` (20.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m36s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 10.7s — slowest: `TextFieldTest` (16.6s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m36s across 30 shards
- **Lines:** 215/499 matching (43.1%)
- **Avg test duration:** 13.5s — slowest: `opcode_guard_test2` (16.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m39s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 15.5s — slowest: `tags_after_last_showframe` (16.4s)

### from_shumway

- **Pass:** 60/92 (65.2%)
- **Duration:** 11m37s across 30 shards
- **Lines:** 656/1,276 matching (51.4%)
- **Avg test duration:** 7.5s — slowest: `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` (16.8s)

### from_shumway/avm1

- **Pass:** 44/45 (97.8%)
- **Ignored:** 2 tests
- **Duration:** 1m33s across 30 shards
- **Lines:** 476/480 matching (99.2%)
- **Avg test duration:** 1.7s — slowest: `nested-button` (16.6s)
