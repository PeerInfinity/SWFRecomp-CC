# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `6ddedca895ed`  
**Date:** 2026-04-17 04:43 UTC  
**Total duration:** 1h45m33s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 580 | 641 | 90.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 106 | 190 | 55.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 58 | 92 | 63.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 42 | 47 | 89.4% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **827** | **1115** | **74.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 84,174 | 114,746 | 73.4% |
| from_gnash/actionscript.all | 13,631 | 16,957 | 80.4% |
| from_gnash/misc-ming.all | 2,119 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 222 | 499 | 44.5% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 649 | 1,276 | 50.9% |
| from_shumway/avm1 | 472 | 491 | 96.1% |
| **Total** | **101,485** | **138,792** | **73.1%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error |
|-------|--------------:|-----------------:|---------------:|
| avm1 | 1 | 55 | - |
| from_gnash/actionscript.all | - | 57 | - |
| from_gnash/misc-ming.all | 1 | 73 | - |
| from_gnash/misc-mtasc.all | - | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | - |
| from_shumway | - | 33 | - |
| from_shumway/avm1 | - | 4 | - |
| **Total** | **2** | **236** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| from_gnash/actionscript.all | Number-v6 | 97% |
| from_gnash/actionscript.all | Number-v7 | 97% |
| from_gnash/actionscript.all | Number-v8 | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
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

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | - | 1 | - |
| from_gnash/actionscript.all | - | - | 4 | - |
| from_gnash/misc-ming.all | - | - | 1 | 2 |
| from_shumway | 2 | 1 | 4 | 4 |
| from_shumway/avm1 | 2 | 1 | 4 | 4 |

**avm1 — newly passing:** `clone_sprite_edittext`

**from_shumway — newly passing:** `avm1/duplicateMovieClip/duplicateMovieClip`, `avm1/duplicateMovieClip/samedepth`

**from_shumway — newly failing:** `avm1/depth`

**from_shumway/avm1 — newly passing:** `duplicateMovieClip/duplicateMovieClip`, `duplicateMovieClip/samedepth`

**from_shumway/avm1 — newly failing:** `depth`

*Comparing `57761062335c` → `6ddedca895ed`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 580/641 (90.5%)
- **Duration:** 49m53s across 30 shards
- **Lines:** 84,174/114,746 matching (73.4%)
- **Avg test duration:** 4.6s — slowest: `swf4_actions_coercion_order` (18.2s)

### from_gnash/actionscript.all

- **Pass:** 106/190 (55.8%)
- **Duration:** 10m42s across 30 shards
- **Lines:** 13,631/16,957 matching (80.4%)
- **Avg test duration:** 3.3s — slowest: `Random-v7` (17.4s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 21m35s across 30 shards
- **Lines:** 2,119/4,541 matching (46.7%)
- **Avg test duration:** 12.6s — slowest: `matrix_test` (18.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m34s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 10.5s — slowest: `enum` (16.0s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m41s across 30 shards
- **Lines:** 222/499 matching (44.5%)
- **Avg test duration:** 13.8s — slowest: `opcode_guard_test2` (17.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m45s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 15.8s — slowest: `func_dict` (17.2s)

### from_shumway

- **Pass:** 58/92 (63.0%)
- **Duration:** 11m48s across 30 shards
- **Lines:** 649/1,276 matching (50.9%)
- **Avg test duration:** 7.6s — slowest: `gradientTransform` (17.5s)

### from_shumway/avm1

- **Pass:** 42/47 (89.4%)
- **Duration:** 1m32s across 30 shards
- **Lines:** 472/491 matching (96.1%)
- **Avg test duration:** 1.9s — slowest: `hitarea` (16.7s)
