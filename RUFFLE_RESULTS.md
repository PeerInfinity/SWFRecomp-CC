# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `60dfc4199eba`  
**Date:** 2026-04-19 03:19 UTC  
**Total duration:** 1h43m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 598 | 641 | 93.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 110 | 190 | 57.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 60 | 92 | 65.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **853** | **1115** | **76.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,628 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,031 | 16,957 | 82.7% |
| from_gnash/misc-ming.all | 2,121 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 215 | 499 | 43.1% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 656 | 1,276 | 51.4% |
| from_shumway/avm1 | 479 | 491 | 97.6% |
| **Total** | **123,348** | **138,795** | **88.9%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error |
|-------|--------------:|-----------------:|---------------:|
| avm1 | - | 35 | - |
| from_gnash/actionscript.all | - | 47 | - |
| from_gnash/misc-ming.all | 1 | 73 | - |
| from_gnash/misc-mtasc.all | - | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | - |
| from_shumway | - | 31 | - |
| from_shumway/avm1 | - | 2 | - |
| **Total** | **1** | **202** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 95% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 95% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/actionscript.all | Selection-v6 | 94% |
| from_gnash/actionscript.all | Selection-v7 | 94% |
| from_gnash/actionscript.all | Selection-v8 | 94% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 92% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/actionscript.all | BitmapData-v8 | 91% |
| from_gnash/misc-ming.all | get_frame_number_test | 87% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/actionscript.all | Matrix-v6 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test11 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/actionscript.all | 1 | - | 16 | - |
| from_gnash/misc-ming.all | - | - | 2 | - |

*Comparing `1f94cb88e1a5` → `60dfc4199eba`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 598/641 (93.3%)
- **Duration:** 48m43s across 30 shards
- **Lines:** 105,628/114,749 matching (92.1%)
- **Avg test duration:** 4.5s — slowest: `slash_syntax` (18.6s)

### from_gnash/actionscript.all

- **Pass:** 110/190 (57.9%)
- **Duration:** 10m29s across 30 shards
- **Lines:** 14,031/16,957 matching (82.7%)
- **Avg test duration:** 3.3s — slowest: `Transform-v6` (18.1s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 21m15s across 30 shards
- **Lines:** 2,121/4,541 matching (46.7%)
- **Avg test duration:** 12.4s — slowest: `matrix_test` (19.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 10.4s — slowest: `enum` (15.7s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m42s across 30 shards
- **Lines:** 215/499 matching (43.1%)
- **Avg test duration:** 13.8s — slowest: `opcode_guard_test2` (17.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m40s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 15.5s — slowest: `missing_bitmap` (16.2s)

### from_shumway

- **Pass:** 60/92 (65.2%)
- **Duration:** 11m27s across 30 shards
- **Lines:** 656/1,276 matching (51.4%)
- **Avg test duration:** 7.4s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (18.1s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 1m31s across 30 shards
- **Lines:** 479/491 matching (97.6%)
- **Avg test duration:** 1.9s — slowest: `nested-button` (16.1s)
