# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `112f7a9df78d`  
**Date:** 2026-04-04 02:19 UTC  
**Total duration:** 5h08m11s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 563 | 566 | 99.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 60 | 168 | 35.7% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 8 | 55 | 14.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 4 | 8 | 50.0% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 10 | 13 | 76.9% ⚠️ | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 17 | 17 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **676** | **866** | **78.1%** | |

*93 tests ignored.*

### ⚠️ Incomplete Runs

- **from_gnash/actionscript.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-ming.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-mtasc.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-swfc.all**: 28/30 shards produced results (2 missing)
- **from_gnash/misc-swfmill.all**: 28/30 shards produced results (2 missing)

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 71,463 | 71,497 | 99.95% |
| from_gnash/actionscript.all | 9,979 | 14,267 | 69.9% |
| from_gnash/misc-ming.all | 1,601 | 3,321 | 48.2% |
| from_gnash/misc-mtasc.all | 140 | 205 | 68.3% |
| from_gnash/misc-swfc.all | 216 | 511 | 42.3% |
| from_gnash/misc-swfmill.all | 22 | 26 | 84.6% |
| from_shumway | 35 | 35 | 100% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **83,574** | **90,173** | **92.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | segfault |
|-------|-----------------:|---------------:|----------:|
| avm1 | 3 | - | - |
| from_gnash/actionscript.all | 108 | - | - |
| from_gnash/misc-ming.all | 46 | - | 1 |
| from_gnash/misc-mtasc.all | 4 | - | - |
| from_gnash/misc-swfc.all | 13 | 1 | - |
| from_gnash/misc-swfmill.all | 3 | - | - |
| from_shumway | - | - | - |
| from_shumway/avm1 | 10 | 1 | - |
| **Total** | **187** | **2** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | Inheritance-v8 | 98% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| avm1 | movieclip_hittest_shapeflag | 96% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Key-v5 | 92% |
| avm1 | native_objects_swf7 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| avm1 | native_objects_swf8 | 90% |
| from_gnash/actionscript.all | Selection-v7 | 89% |
| from_gnash/actionscript.all | Selection-v8 | 89% |
| from_gnash/actionscript.all | Selection-v6 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/misc-mtasc.all | inheritance | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | Inheritance-v5 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_shumway/avm1 | nativeinheritance | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | System-v7 | 82% |
| from_gnash/actionscript.all | System-v8 | 82% |
| from_gnash/actionscript.all | System-v6 | 82% |
| from_gnash/actionscript.all | Number-v7 | 81% |
| from_gnash/actionscript.all | Number-v8 | 81% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/actionscript.all | array-v5 | 80% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 1 | 3 | 33.3% |

## Per-Suite Details

### avm1

- **Pass:** 563/566 (99.5%)
- **Ignored:** 54 tests
- **Duration:** 3h13m03s across 30 shards
- **Lines:** 71,463/71,497 matching (99.95%)
- **Avg test duration:** 18.5s — slowest: `movieclip_invalid_get_bounds_7` (42.0s)

### from_gnash/actionscript.all

- **Pass:** 60/168 (35.7%)
- **Ignored:** 9 tests
- **Duration:** 1h03m09s across 28 shards
- **Lines:** 9,979/14,267 matching (69.9%)
- **Avg test duration:** 21.2s — slowest: `array-v5` (45.5s)

### from_gnash/misc-ming.all

- **Pass:** 8/55 (14.5%)
- **Duration:** 18m57s across 28 shards
- **Lines:** 1,601/3,321 matching (48.2%)
- **Avg test duration:** 20.6s — slowest: `matrix_test` (71.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 4/8 (50.0%)
- **Duration:** 2m33s across 28 shards
- **Lines:** 140/205 matching (68.3%)
- **Avg test duration:** 19.2s — slowest: `levels` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m04s across 28 shards
- **Lines:** 216/511 matching (42.3%)
- **Avg test duration:** 19.0s — slowest: `opcode_guard_test2` (20.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 10/13 (76.9%)
- **Duration:** 3m58s across 28 shards
- **Lines:** 22/26 matching (84.6%)
- **Avg test duration:** 18.3s — slowest: `dict_callframe` (19.6s)

### from_shumway

- **Pass:** 17/17 (100%)
- **Ignored:** 30 tests
- **Duration:** 14m20s across 30 shards
- **Lines:** 35/35 matching (100%)
- **Avg test duration:** 18.4s — slowest: `add` (19.8s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m03s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 18.4s — slowest: `watch` (19.9s)
