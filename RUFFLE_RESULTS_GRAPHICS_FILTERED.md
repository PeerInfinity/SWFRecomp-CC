# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `c4496a4c8f4b`  
**Date:** 2026-08-01 19:38 UTC  
**Total duration:** 12h05m33s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results_graphics_filtered.md) |
| avm1 | 670 | 694 | 96.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 1082 | 1171 | 92.4% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| fonts | 3 | 6 | 50.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_graphics_filtered.md) |
| from_avmplus | 1510 | 1572 | 96.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 135 | 239 | 56.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 69 | 110 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 186 | 207 | 89.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 46 | 46 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| import_assets | 1 | 3 | 33.3% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_graphics_filtered.md) |
| mixed_avm | 4 | 11 | 36.4% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_graphics_filtered.md) |
| regression | 70 | 70 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| stage3d | 5 | 5 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_graphics_filtered.md) |
| swf | 4 | 5 | 80.0% | [details](ruffle-tests/tests/swfs/swf/_results/results_graphics_filtered.md) |
| text | 9 | 11 | 81.8% | [details](ruffle-tests/tests/swfs/text/_results/results_graphics_filtered.md) |
| timeline | 12 | 17 | 70.6% | [details](ruffle-tests/tests/swfs/timeline/_results/results_graphics_filtered.md) |
| visual | 138 | 143 | 96.5% | [details](ruffle-tests/tests/swfs/visual/_results/results_graphics_filtered.md) |
| **Total** | **3984** | **4362** | **91.3%** | |

*109 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 105,272 | 108,744 | 96.8% |
| avm2 | 111,320 | 133,312 | 83.5% |
| fonts | 35 | 104 | 33.7% |
| from_avmplus | 85,379 | 85,970 | 99.3% |
| from_gnash/actionscript.all | 29,443 | 31,544 | 93.3% |
| from_gnash/misc-ming.all | 4,047 | 5,206 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 1,472 | 1,770 | 83.2% |
| from_shumway/avm1 | 487 | 487 | 100% |
| import_assets | 2 | 14 | 14.3% |
| mixed_avm | 19 | 53 | 35.8% |
| regression | 481 | 481 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 51 | 57 | 89.5% |
| text | 858 | 973 | 88.2% |
| timeline | 333 | 371 | 89.8% |
| visual | 252 | 350 | 72.0% |
| **Total** | **340,389** | **370,549** | **91.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| audio | 2 | - | - |
| avm1 | 11 | 13 | - |
| avm2 | 86 | 3 | - |
| fonts | 3 | - | - |
| from_avmplus | 8 | 53 | 1 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 13 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | 12 | 9 | - |
| from_shumway/avm1 | - | - | - |
| import_assets | 2 | - | - |
| mixed_avm | 7 | - | - |
| regression | - | - | - |
| stage3d | - | - | - |
| swf | - | 1 | - |
| text | 2 | - | - |
| timeline | 2 | 3 | - |
| visual | 5 | - | - |
| **Total** | **165** | **212** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_avmplus | as3/Array/insertremove | 100% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| avm2 | perspective_projection | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | cross_api_version_call_newer | 92% |
| from_avmplus | ecma3/String/e15_5_4_8_2 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_shumway | as3-loader/LoaderTest2 | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_stack_trace | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm2 | matrix | 83% |
| avm2 | number_convert_edge_cases | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| fonts | device_font_glyph_fallback | 81% |
| from_shumway | avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass | 80% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 16.2s — slowest: `stream_incomplete_loop` (22.4s)

### avm1

- **Pass:** 670/694 (96.5%)
- **Ignored:** 24 tests
- **Duration:** 1h34m41s across 30 shards
- **Lines:** 105,272/108,744 matching (96.8%)
- **Avg test duration:** 7.8s — slowest: `movieclip_invalid_get_bounds_6` (56.4s)

### avm2

- **Pass:** 1082/1171 (92.4%)
- **Ignored:** 53 tests
- **Duration:** 3h39m22s across 30 shards
- **Lines:** 111,320/133,312 matching (83.5%)
- **Avg test duration:** 10.6s — slowest: `away3d_advanced_shallow_water_demo` (88.3s)

### fonts

- **Pass:** 3/6 (50.0%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 35/104 matching (33.7%)
- **Avg test duration:** 20.8s — slowest: `device_font_kerning` (29.0s)

### from_avmplus

- **Pass:** 1510/1572 (96.1%)
- **Ignored:** 2 tests
- **Duration:** 3h17m53s across 30 shards
- **Lines:** 85,379/85,970 matching (99.3%)
- **Avg test duration:** 7.5s — slowest: `ecma3/Statements/eregress_74474_003` (55.7s)

### from_gnash/actionscript.all

- **Pass:** 135/239 (56.5%)
- **Ignored:** 4 tests
- **Duration:** 40m01s across 30 shards
- **Lines:** 29,443/31,544 matching (93.3%)
- **Avg test duration:** 9.7s — slowest: `MovieClip-v8` (69.0s)

### from_gnash/misc-ming.all

- **Pass:** 69/110 (62.7%)
- **Ignored:** 1 tests
- **Duration:** 37m17s across 30 shards
- **Lines:** 4,047/5,206 matching (77.7%)
- **Avg test duration:** 20.1s — slowest: `matrix_test` (106.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 21.6s — slowest: `levels` (25.4s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 6m20s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 19.6s — slowest: `swf4opcode` (24.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 7m01s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 21.0s — slowest: `background` (23.4s)

### from_shumway

- **Pass:** 186/207 (89.9%)
- **Ignored:** 22 tests
- **Duration:** 48m19s across 30 shards
- **Lines:** 1,472/1,770 matching (83.2%)
- **Avg test duration:** 11.6s — slowest: `acid/acid-large` (80.0s)

### from_shumway/avm1

- **Pass:** 46/46 (100%)
- **Ignored:** 1 tests
- **Duration:** 2m15s across 30 shards
- **Lines:** 487/487 matching (100%)
- **Avg test duration:** 2.8s — slowest: `label` (21.1s)

### import_assets

- **Pass:** 1/3 (33.3%)
- **Duration:** 49s across 30 shards
- **Lines:** 2/14 matching (14.3%)
- **Avg test duration:** 16.1s — slowest: `avm1_non_swf_import` (24.0s)

### mixed_avm

- **Pass:** 4/11 (36.4%)
- **Duration:** 1m20s across 30 shards
- **Lines:** 19/53 matching (35.8%)
- **Avg test duration:** 7.3s — slowest: `avm1_sprite_sc_ignored` (20.4s)

### regression

- **Pass:** 70/70 (100%)
- **Duration:** 19m30s across 30 shards
- **Lines:** 481/481 matching (100%)
- **Avg test duration:** 16.7s — slowest: `avm2_timeline_gradients` (50.6s)

### stage3d

- **Pass:** 5/5 (100%)
- **Duration:** 47s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 9.4s — slowest: `scissor_rectangle_invalid` (10.8s)

### swf

- **Pass:** 4/5 (80.0%)
- **Duration:** 49s across 30 shards
- **Lines:** 51/57 matching (89.5%)
- **Avg test duration:** 9.6s — slowest: `swf_length_too_short_no_second_frame` (21.1s)

### text

- **Pass:** 9/11 (81.8%)
- **Duration:** 3m47s across 30 shards
- **Lines:** 858/973 matching (88.2%)
- **Avg test duration:** 20.7s — slowest: `auto_size/return` (31.6s)

### timeline

- **Pass:** 12/17 (70.6%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 333/371 matching (89.8%)
- **Avg test duration:** 21.2s — slowest: `frame_script_cleanup_goto2` (29.0s)

### visual

- **Pass:** 138/143 (96.5%)
- **Duration:** 32m33s across 30 shards
- **Lines:** 252/350 matching (72.0%)
- **Avg test duration:** 13.6s — slowest: `definefont4` (94.9s)
