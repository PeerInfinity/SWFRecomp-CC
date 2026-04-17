# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `b3deda13c6a9`  
**Date:** 2026-04-17 16:55 UTC  
**Total duration:** 1h47m04s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 576 | 601 | 95.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 106 | 190 | 55.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 60 | 92 | 65.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 45 | 97.8% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **827** | **1073** | **77.1%** | |

*42 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 74,668 | 96,461 | 77.4% |
| from_gnash/actionscript.all | 13,631 | 16,957 | 80.4% |
| from_gnash/misc-ming.all | 2,120 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 222 | 499 | 44.5% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 661 | 1,276 | 51.8% |
| from_shumway/avm1 | 476 | 480 | 99.2% |
| **Total** | **91,996** | **120,496** | **76.3%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched | runtime_error |
|-------|--------------:|-----------------:|----------------:|---------------:|
| avm1 | 1 | 22 | - | 2 |
| from_gnash/actionscript.all | - | 57 | 27 | - |
| from_gnash/misc-ming.all | 1 | 73 | 10 | - |
| from_gnash/misc-mtasc.all | - | 1 | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 3 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | 1 | - |
| from_shumway | - | 31 | 1 | - |
| from_shumway/avm1 | - | 1 | - | - |
| **Total** | **2** | **198** | **43** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_gnash/actionscript.all | Number-v6 | 97% |
| from_gnash/actionscript.all | Number-v7 | 97% |
| from_gnash/actionscript.all | Number-v8 | 97% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v5 | 93% |
| from_gnash/actionscript.all | Selection-v6 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 91% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 90% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 90% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 89% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 89% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 89% |
| from_gnash/actionscript.all | array-v5 | 88% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_shumway | avm1/moviecliploader | 86% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| avm1 | bitmap_data_thorough/getColorBoundsRect | 84% |
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

- **Pass:** 576/601 (95.8%)
- **Ignored:** 40 tests
- **Duration:** 51m00s across 30 shards
- **Lines:** 74,668/96,461 matching (77.4%)
- **Avg test duration:** 4.7s — slowest: `as2_oop` (19.0s)

### from_gnash/actionscript.all

- **Pass:** 106/190 (55.8%)
- **Duration:** 11m04s across 30 shards
- **Lines:** 13,631/16,957 matching (80.4%)
- **Avg test duration:** 3.4s — slowest: `Accessibility-v8` (17.8s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 21m27s across 30 shards
- **Lines:** 2,120/4,541 matching (46.7%)
- **Avg test duration:** 12.6s — slowest: `matrix_test` (19.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m36s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 10.6s — slowest: `enum` (17.2s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m41s across 30 shards
- **Lines:** 222/499 matching (44.5%)
- **Avg test duration:** 13.8s — slowest: `soft_reference_test1` (16.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m44s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 15.8s — slowest: `background` (18.7s)

### from_shumway

- **Pass:** 60/92 (65.2%)
- **Duration:** 11m48s across 30 shards
- **Lines:** 661/1,276 matching (51.8%)
- **Avg test duration:** 7.6s — slowest: `avm1timeline1` (16.3s)

### from_shumway/avm1

- **Pass:** 44/45 (97.8%)
- **Ignored:** 2 tests
- **Duration:** 1m40s across 30 shards
- **Lines:** 476/480 matching (99.2%)
- **Avg test duration:** 1.8s — slowest: `text-bind` (16.3s)
