# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `61ba7bd8558d`  
**Date:** 2026-04-21 18:09 UTC  
**Total duration:** 7m59s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 109 | 190 | 57.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 19 | 102 | 18.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 3 | 16 | 18.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 61 | 92 | 66.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **856** | **1115** | **76.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,645 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,325 | 16,957 | 84.5% |
| from_gnash/misc-ming.all | 2,175 | 4,541 | 47.9% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 219 | 499 | 43.9% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **123,761** | **138,795** | **89.2%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 35 |
| from_gnash/actionscript.all | - | 38 |
| from_gnash/misc-ming.all | 1 | 71 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 10 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 30 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **188** |

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
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/misc-ming.all | get_frame_number_test | 87% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | loop/loop_test4 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Changes Since Last Run

*No changes since last run.*

*Comparing `22a3317db4d7` → `61ba7bd8558d`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 4m06s across 30 shards
- **Lines:** 105,645/114,749 matching (92.1%)
- **Avg test duration:** 0.3s — slowest: `bitmap_data_copypixels` (15.5s)

### from_gnash/actionscript.all

- **Pass:** 109/190 (57.4%)
- **Duration:** 1m22s across 30 shards
- **Lines:** 14,325/16,957 matching (84.5%)
- **Avg test duration:** 0.4s — slowest: `BitmapData-v8` (20.4s)

### from_gnash/misc-ming.all

- **Pass:** 19/102 (18.6%)
- **Duration:** 1m15s across 30 shards
- **Lines:** 2,175/4,541 matching (47.9%)
- **Avg test duration:** 0.7s — slowest: `EmbeddedFontTest` (18.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 0.3s — slowest: `exception` (1.6s)

### from_gnash/misc-swfc.all

- **Pass:** 3/16 (18.8%)
- **Duration:** 18s across 30 shards
- **Lines:** 219/499 matching (43.9%)
- **Avg test duration:** 1.1s — slowest: `edittext_test1` (14.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 18s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 0.9s — slowest: `dict_callframe` (13.7s)

### from_shumway

- **Pass:** 61/92 (66.3%)
- **Duration:** 24s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 0.2s — slowest: `avm1/duplicateMovieClip/dontremove` (0.9s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 12s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 0.2s — slowest: `depth` (0.9s)
