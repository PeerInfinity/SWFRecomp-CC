# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `8b69f982f7ab`  
**Date:** 2026-10-04 10:43 UTC  
**Total duration:** 9h33m14s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 701 | 725 | 96.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 1220 | 1245 | 98.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 1529 | 1572 | 97.3% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 141 | 240 | 58.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 214 | 223 | 96.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 101 | 101 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 11 | 11 | 100% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 14 | 17 | 82.4% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **4263** | **4527** | **94.2%** | |

*71 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 110,888 | 114,780 | 96.6% |
| avm2 | 151,095 | 152,536 | 99.1% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,548 | 85,970 | 99.5% |
| from_gnash/actionscript.all | 30,193 | 32,104 | 94.0% |
| from_gnash/misc-ming.all | 4,220 | 5,206 | 81.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,351 | 2,409 | 97.6% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 54 | 79 | 68.4% |
| regression | 838 | 838 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 973 | 973 | 100% |
| timeline | 365 | 371 | 98.4% |
| visual | 301 | 350 | 86.0% |
| **Total** | **388,544** | **397,692** | **97.7%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 9 | 15 | - |
| avm2 | 8 | 17 | - |
| fonts | 1 | 1 | - |
| from_avmplus | 1 | 41 | 1 |
| from_gnash/actionscript.all | 5 | 94 | - |
| from_gnash/misc-ming.all | 9 | 32 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 2 | 7 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | - | - | - |
| mixed_avm | 2 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 2 | - |
| text | - | - | - |
| timeline | - | 3 | - |
| visual | - | 2 | - |
| **Total** | **41** | **222** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | MovieClip-v8 | 95% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | Rectangle-v8 | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | html_text_img_parsing_swf6 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m14s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.9s — slowest: `g711_event_mulaw` (21.6s)

### avm1

- **Pass:** 701/725 (96.7%)
- **Ignored:** 18 tests
- **Duration:** 38m30s across 30 shards
- **Lines:** 110,888/114,780 matching (96.6%)
- **Avg test duration:** 3.0s — slowest: `movieclip_invalid_get_bounds_7` (27.6s)

### avm2

- **Pass:** 1220/1245 (98.0%)
- **Ignored:** 39 tests
- **Duration:** 3h12m37s across 30 shards
- **Lines:** 151,095/152,536 matching (99.1%)
- **Avg test duration:** 8.9s — slowest: `away3d_advanced_shallow_water_demo` (61.5s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m36s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 19.5s — slowest: `device_font_no_ink` (29.7s)

### from_avmplus

- **Pass:** 1529/1572 (97.3%)
- **Ignored:** 2 tests
- **Duration:** 3h05m54s across 30 shards
- **Lines:** 85,548/85,970 matching (99.5%)
- **Avg test duration:** 7.0s — slowest: `ecma3/Statements/eregress_74474_003` (55.4s)

### from_gnash/actionscript.all

- **Pass:** 141/240 (58.8%)
- **Ignored:** 3 tests
- **Duration:** 18m22s across 30 shards
- **Lines:** 30,193/32,104 matching (94.0%)
- **Avg test duration:** 4.5s — slowest: `array-v7` (34.3s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 20m55s across 30 shards
- **Lines:** 4,220/5,206 matching (81.1%)
- **Avg test duration:** 11.3s — slowest: `matrix_test` (108.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.5s — slowest: `implementsOpTest` (22.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 4m27s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 13.5s — slowest: `edittext_test1` (22.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m13s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.6s — slowest: `dict_event` (22.2s)

### from_shumway

- **Pass:** 214/223 (96.0%)
- **Ignored:** 6 tests
- **Duration:** 42m44s across 30 shards
- **Lines:** 2,351/2,409 matching (97.6%)
- **Avg test duration:** 10.8s — slowest: `acid/acid-large` (75.6s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 2.1s — slowest: `text-bind` (21.2s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 34s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 11.3s — slowest: `avm1_non_swf_import` (18.2s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 58s across 30 shards
- **Lines:** 54/79 matching (68.4%)
- **Avg test duration:** 4.8s — slowest: `avm2_loads_avm1_loads_into_root` (7.8s)

### regression

- **Pass:** 101/101 (100%)
- **Duration:** 20m51s across 30 shards
- **Lines:** 838/838 matching (100%)
- **Avg test duration:** 12.3s — slowest: `avm2_morph` (37.4s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 1m01s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 8.8s — slowest: `scissor_rectangle` (10.8s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 10s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 1.3s — slowest: `swf_length_too_long` (1.5s)

### text

- **Pass:** 11/11 (100%)
- **Duration:** 2m53s across 30 shards
- **Lines:** 973/973 matching (100%)
- **Avg test duration:** 15.7s — slowest: `text_caret_placement_leading` (28.4s)

### timeline

- **Pass:** 14/17 (82.4%)
- **Duration:** 1m44s across 30 shards
- **Lines:** 365/371 matching (98.4%)
- **Avg test duration:** 6.1s — slowest: `frame_script_cleanup` (8.4s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 27m58s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 11.4s — slowest: `definefont4` (108.7s)
