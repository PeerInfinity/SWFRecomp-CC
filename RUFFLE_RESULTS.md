# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `924dce10a243`  
**Date:** 2026-04-18 18:58 UTC  
**Total duration:** 1h43m55s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 107 | 190 | 56.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 60 | 92 | 65.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **849** | **1115** | **76.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,614 | 114,749 | 92.0% |
| from_gnash/actionscript.all | 13,870 | 16,957 | 81.8% |
| from_gnash/misc-ming.all | 2,119 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 215 | 499 | 43.1% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 656 | 1,276 | 51.4% |
| from_shumway/avm1 | 479 | 491 | 97.6% |
| **Total** | **123,171** | **138,795** | **88.7%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error |
|-------|--------------:|-----------------:|---------------:|
| avm1 | - | 36 | - |
| from_gnash/actionscript.all | - | 51 | - |
| from_gnash/misc-ming.all | 1 | 73 | - |
| from_gnash/misc-mtasc.all | - | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | - |
| from_shumway | - | 31 | - |
| from_shumway/avm1 | - | 2 | - |
| **Total** | **1** | **207** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | edittext_stylesheet | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| from_gnash/actionscript.all | Number-v6 | 97% |
| from_gnash/actionscript.all | Number-v7 | 97% |
| from_gnash/actionscript.all | Number-v8 | 97% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
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
| from_gnash/actionscript.all | array-v5 | 89% |
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

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 2 |
| from_gnash/actionscript.all | 1 | - | 15 | 4 |

**avm1 — newly failing:** `edittext_stylesheet`

**from_gnash/actionscript.all — newly passing:** `TextField-v5`

*Comparing `d6d009974a92` → `924dce10a243`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 49m01s across 30 shards
- **Lines:** 105,614/114,749 matching (92.0%)
- **Avg test duration:** 4.5s — slowest: `xml_ignore_comments` (17.4s)

### from_gnash/actionscript.all

- **Pass:** 107/190 (56.3%)
- **Duration:** 10m32s across 30 shards
- **Lines:** 13,870/16,957 matching (81.8%)
- **Avg test duration:** 3.3s — slowest: `TextFormat-v7` (16.8s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 21m09s across 30 shards
- **Lines:** 2,119/4,541 matching (46.7%)
- **Avg test duration:** 12.4s — slowest: `matrix_test` (20.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m35s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 10.6s — slowest: `hello` (16.1s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m39s across 30 shards
- **Lines:** 215/499 matching (43.1%)
- **Avg test duration:** 13.6s — slowest: `hello` (16.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m38s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 15.4s — slowest: `tags_after_last_showframe` (16.0s)

### from_shumway

- **Pass:** 60/92 (65.2%)
- **Duration:** 11m44s across 30 shards
- **Lines:** 656/1,276 matching (51.4%)
- **Avg test duration:** 7.6s — slowest: `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` (17.2s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 1m33s across 30 shards
- **Lines:** 479/491 matching (97.6%)
- **Avg test duration:** 1.9s — slowest: `text-bind` (17.1s)
