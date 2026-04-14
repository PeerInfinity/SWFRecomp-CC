# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `1d207c167423`  
**Date:** 2026-04-13 23:00 UTC  
**Total duration:** 6h15m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 579 | 601 | 96.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 95 | 181 | 52.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 17 | 102 | 16.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 48 | 92 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 32 | 45 | 71.1% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **794** | **1064** | **74.6%** | |

*51 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 74,807 | 96,461 | 77.6% |
| from_gnash/actionscript.all | 11,000 | 14,908 | 73.8% |
| from_gnash/misc-ming.all | 2,114 | 4,541 | 46.6% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 222 | 499 | 44.5% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 628 | 1,276 | 49.2% |
| from_shumway/avm1 | 448 | 480 | 93.3% |
| **Total** | **89,437** | **118,447** | **75.5%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error |
|-------|--------------:|-----------------:|---------------:|
| avm1 | 1 | 21 | - |
| from_gnash/actionscript.all | - | 86 | - |
| from_gnash/misc-ming.all | 1 | 84 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | - | 13 | 1 |
| from_gnash/misc-swfmill.all | - | 4 | - |
| from_shumway | - | 44 | - |
| from_shumway/avm1 | - | 13 | - |
| **Total** | **2** | **267** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v7 | 94% |
| from_gnash/actionscript.all | Number-v8 | 94% |
| from_gnash/actionscript.all | TextSnapshot-v6 | 92% |
| from_gnash/actionscript.all | TextSnapshot-v7 | 92% |
| from_gnash/actionscript.all | TextSnapshot-v8 | 92% |
| from_gnash/actionscript.all | Number-v6 | 92% |
| from_gnash/actionscript.all | Selection-v6 | 91% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Number-v5 | 89% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 87% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 86% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| avm1 | bitmap_data_thorough/getColorBoundsRect | 84% |
| from_shumway | avm1/property-paths/property-paths-6 | 83% |
| from_shumway/avm1 | property-paths/property-paths-6 | 83% |
| from_gnash/actionscript.all | System-v7 | 83% |
| from_gnash/actionscript.all | System-v8 | 83% |
| from_gnash/actionscript.all | System-v6 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | array-v5 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test11 | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 579/601 (96.3%)
- **Ignored:** 40 tests
- **Duration:** 3h29m55s across 30 shards
- **Lines:** 74,807/96,461 matching (77.6%)
- **Avg test duration:** 19.6s — slowest: `movieclip_invalid_get_bounds_6` (44.0s)

### from_gnash/actionscript.all

- **Pass:** 95/181 (52.5%)
- **Ignored:** 9 tests
- **Duration:** 1h10m42s across 30 shards
- **Lines:** 11,000/14,908 matching (73.8%)
- **Avg test duration:** 22.0s — slowest: `BitmapData-v8` (43.2s)

### from_gnash/misc-ming.all

- **Pass:** 17/102 (16.7%)
- **Duration:** 35m46s across 30 shards
- **Lines:** 2,114/4,541 matching (46.6%)
- **Avg test duration:** 21.0s — slowest: `matrix_test` (71.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m01s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 20.1s — slowest: `levels` (21.2s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m19s across 30 shards
- **Lines:** 222/499 matching (44.5%)
- **Avg test duration:** 19.9s — slowest: `movieclip_destruction_test4` (21.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 5m46s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 19.2s — slowest: `dict_callframe` (20.9s)

### from_shumway

- **Pass:** 48/92 (52.2%)
- **Duration:** 29m56s across 30 shards
- **Lines:** 628/1,276 matching (49.2%)
- **Avg test duration:** 19.5s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (21.5s)

### from_shumway/avm1

- **Pass:** 32/45 (71.1%)
- **Ignored:** 2 tests
- **Duration:** 15m09s across 30 shards
- **Lines:** 448/480 matching (93.3%)
- **Avg test duration:** 19.3s — slowest: `xml/xmlbuild` (20.5s)
