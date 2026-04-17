# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `57761062335c`  
**Date:** 2026-04-17 03:35 UTC  
**Total duration:** 2h08m50s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 579 | 641 | 90.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 106 | 190 | 55.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 57 | 92 | 62.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 41 | 47 | 87.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **824** | **1115** | **73.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 84,173 | 114,746 | 73.4% |
| from_gnash/actionscript.all | 13,627 | 16,957 | 80.4% |
| from_gnash/misc-ming.all | 2,120 | 4,541 | 46.7% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 222 | 499 | 44.5% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 649 | 1,276 | 50.9% |
| from_shumway/avm1 | 472 | 491 | 96.1% |
| **Total** | **101,481** | **138,792** | **73.1%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_error |
|-------|--------------:|-----------------:|---------------:|
| avm1 | 1 | 56 | - |
| from_gnash/actionscript.all | - | 57 | - |
| from_gnash/misc-ming.all | 1 | 73 | - |
| from_gnash/misc-mtasc.all | - | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | - |
| from_shumway | - | 34 | - |
| from_shumway/avm1 | - | 5 | - |
| **Total** | **2** | **239** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | clone_sprite_edittext | 99% |
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
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | get_frame_number_test | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test11 | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 10 |
| from_gnash/actionscript.all | - | - | 3 | 18 |
| from_shumway | 9 | - | 21 | - |
| from_shumway/avm1 | 9 | - | 21 | - |

**avm1 — newly failing:** `clone_sprite_edittext`

**from_shumway — newly passing:** `avm1/bitmapdata/loadBitmap`, `avm1/duplicateMovieClip/name-coercion`, `avm1/haxe/flocons2`, `avm1/loadvariables/loadvars`, `avm1/property-paths/property-paths-6`, `avm1/propertycase/propertycase-preserving-6`, `avm1/textfield/textfield-html`, `avm1/textfield/textfield-text-setters`, `avm1/xml/xmlload`

**from_shumway/avm1 — newly passing:** `bitmapdata/loadBitmap`, `duplicateMovieClip/name-coercion`, `haxe/flocons2`, `loadvariables/loadvars`, `property-paths/property-paths-6`, `propertycase/propertycase-preserving-6`, `textfield/textfield-html`, `textfield/textfield-text-setters`, `xml/xmlload`

*Comparing `85b73541faf3` → `57761062335c`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 579/641 (90.3%)
- **Duration:** 57m27s across 30 shards
- **Lines:** 84,173/114,746 matching (73.4%)
- **Avg test duration:** 5.3s — slowest: `netstream_play_flv_screen` (31.1s)

### from_gnash/actionscript.all

- **Pass:** 106/190 (55.8%)
- **Duration:** 19m52s across 30 shards
- **Lines:** 13,627/16,957 matching (80.4%)
- **Avg test duration:** 6.2s — slowest: `String-v8` (30.6s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 26m15s across 30 shards
- **Lines:** 2,120/4,541 matching (46.7%)
- **Avg test duration:** 15.4s — slowest: `matrix_test` (103.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m47s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 11.9s — slowest: `implementsOpTest` (17.8s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m54s across 30 shards
- **Lines:** 222/499 matching (44.5%)
- **Avg test duration:** 14.6s — slowest: `registerclass_test3` (17.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m44s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 15.8s — slowest: `trace-as2/shortstack` (16.9s)

### from_shumway

- **Pass:** 57/92 (62.0%)
- **Duration:** 12m51s across 30 shards
- **Lines:** 649/1,276 matching (50.9%)
- **Avg test duration:** 8.3s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (19.5s)

### from_shumway/avm1

- **Pass:** 41/47 (87.2%)
- **Duration:** 1m55s across 30 shards
- **Lines:** 472/491 matching (96.1%)
- **Avg test duration:** 2.4s — slowest: `nested-button` (16.6s)
