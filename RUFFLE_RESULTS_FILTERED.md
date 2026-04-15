# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `9d17e1098f88`  
**Date:** 2026-04-15 03:25 UTC  
**Total duration:** 6h18m25s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 578 | 601 | 96.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 102 | 190 | 53.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 48 | 92 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 32 | 45 | 71.1% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **801** | **1073** | **74.7%** | |

*42 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 74,803 | 96,461 | 77.5% |
| from_gnash/actionscript.all | 13,309 | 16,957 | 78.5% |
| from_gnash/misc-ming.all | 2,120 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 222 | 499 | 44.5% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 628 | 1,276 | 49.2% |
| from_shumway/avm1 | 448 | 480 | 93.3% |
| **Total** | **91,748** | **120,496** | **76.1%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched | runtime_error |
|-------|--------------:|-----------------:|----------------:|---------------:|
| avm1 | 1 | 22 | - | - |
| from_gnash/actionscript.all | - | 62 | 26 | - |
| from_gnash/misc-ming.all | 1 | 73 | 10 | - |
| from_gnash/misc-mtasc.all | - | 1 | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 3 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | 1 | - |
| from_shumway | - | 43 | 1 | - |
| from_shumway/avm1 | - | 13 | - | - |
| **Total** | **2** | **227** | **42** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | Number-v7 | 95% |
| from_gnash/actionscript.all | Number-v8 | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v6 | 94% |
| avm1 | funky_function_calls | 93% |
| from_gnash/actionscript.all | TextFormat-v5 | 92% |
| from_gnash/actionscript.all | TextFormat-v6 | 92% |
| from_gnash/actionscript.all | Number-v5 | 91% |
| from_gnash/actionscript.all | Selection-v6 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 90% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 90% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 90% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| avm1 | bitmap_data_thorough/getColorBoundsRect | 84% |
| from_shumway | avm1/property-paths/property-paths-6 | 83% |
| from_shumway/avm1 | property-paths/property-paths-6 | 83% |
| from_gnash/actionscript.all | array-v5 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
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

- **Pass:** 578/601 (96.2%)
- **Ignored:** 40 tests
- **Duration:** 3h31m27s across 30 shards
- **Lines:** 74,803/96,461 matching (77.5%)
- **Avg test duration:** 19.7s — slowest: `movieclip_invalid_get_bounds_7` (43.5s)

### from_gnash/actionscript.all

- **Pass:** 102/190 (53.7%)
- **Duration:** 1h11m17s across 30 shards
- **Lines:** 13,309/16,957 matching (78.5%)
- **Avg test duration:** 22.5s — slowest: `BitmapData-v8` (44.5s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 35m59s across 30 shards
- **Lines:** 2,120/4,541 matching (46.7%)
- **Avg test duration:** 21.1s — slowest: `matrix_test` (71.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m05s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 20.5s — slowest: `levels` (21.7s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m25s across 30 shards
- **Lines:** 222/499 matching (44.5%)
- **Avg test duration:** 20.3s — slowest: `edittext_test1` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 5m48s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 19.3s — slowest: `dict_callframe` (21.3s)

### from_shumway

- **Pass:** 48/92 (52.2%)
- **Duration:** 30m04s across 30 shards
- **Lines:** 628/1,276 matching (49.2%)
- **Avg test duration:** 19.6s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (24.0s)

### from_shumway/avm1

- **Pass:** 32/45 (71.1%)
- **Ignored:** 2 tests
- **Duration:** 15m17s across 30 shards
- **Lines:** 448/480 matching (93.3%)
- **Avg test duration:** 19.5s — slowest: `super` (22.3s)
