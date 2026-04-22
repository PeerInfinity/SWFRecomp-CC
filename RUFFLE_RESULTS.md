# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e77ecee49cad`  
**Date:** 2026-04-22 03:50 UTC  
**Total duration:** 2h00m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 641 | 93.1% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 110 | 190 | 57.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 20 | 102 | 19.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 3 | 16 | 18.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 61 | 92 | 66.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **858** | **1115** | **77.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,735 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,742 | 16,957 | 86.9% |
| from_gnash/misc-ming.all | 2,182 | 4,541 | 48.1% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 219 | 499 | 43.9% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,275** | **138,795** | **89.5%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 35 |
| from_gnash/actionscript.all | - | 31 |
| from_gnash/misc-ming.all | 1 | 70 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 10 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 30 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **180** |

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

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 7 | - |

**from_gnash/misc-ming.all — newly passing:** `DefineEditTextTest`

*Comparing `7155a7747bbf` → `e77ecee49cad`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/641 (93.1%)
- **Duration:** 55m16s across 30 shards
- **Lines:** 105,735/114,749 matching (92.1%)
- **Avg test duration:** 5.1s — slowest: `netstream_play_flv_screen` (32.7s)

### from_gnash/actionscript.all

- **Pass:** 110/190 (57.9%)
- **Duration:** 15m27s across 30 shards
- **Lines:** 14,742/16,957 matching (86.9%)
- **Avg test duration:** 4.8s — slowest: `String-v8` (32.0s)

### from_gnash/misc-ming.all

- **Pass:** 20/102 (19.6%)
- **Duration:** 23m57s across 30 shards
- **Lines:** 2,182/4,541 matching (48.1%)
- **Avg test duration:** 14.0s — slowest: `DefineEditTextTest` (27.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 12.0s — slowest: `TextFieldTest` (18.6s)

### from_gnash/misc-swfc.all

- **Pass:** 3/16 (18.8%)
- **Duration:** 3m52s across 30 shards
- **Lines:** 219/499 matching (43.9%)
- **Avg test duration:** 14.5s — slowest: `opcode_guard_test2` (19.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m54s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 16.3s — slowest: `jump_to_prev_block` (18.1s)

### from_shumway

- **Pass:** 61/92 (66.3%)
- **Duration:** 12m59s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 8.4s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (18.6s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m53s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.3s — slowest: `hitarea` (17.8s)
