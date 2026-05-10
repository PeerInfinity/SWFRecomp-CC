# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `ab614b80ddcf`  
**Date:** 2026-05-10 22:54 UTC  
**Total duration:** 17m00s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 513 | 651 | 78.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 43 | 102 | 42.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 52 | 92 | 56.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 37 | 47 | 78.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **799** | **1125** | **71.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,007 | 114,995 | 90.4% |
| from_gnash/actionscript.all | 15,374 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 2,786 | 4,505 | 61.8% |
| from_gnash/misc-mtasc.all | 165 | 231 | 71.4% |
| from_gnash/misc-swfc.all | 332 | 499 | 66.5% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 747 | 1,276 | 58.5% |
| from_shumway/avm1 | 464 | 491 | 94.5% |
| **Total** | **123,924** | **139,005** | **89.2%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 125 | 2 | 1 | 1 |
| from_gnash/actionscript.all | 1 | 3 | 1 | - |
| from_gnash/misc-ming.all | 42 | - | 3 | - |
| from_gnash/misc-mtasc.all | 1 | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 37 | - | - | - |
| from_shumway/avm1 | 9 | - | - | - |
| **Total** | **220** | **5** | **5** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | button_order | 100% |
| avm1 | click_block | 100% |
| avm1 | create_empty_movie_clip | 100% |
| avm1 | execution_order2 | 100% |
| avm1 | execution_order4 | 100% |
| avm1 | form_loader_encoding_1 | 100% |
| avm1 | issue_2084 | 100% |
| avm1 | loadmovie_replace_root | 100% |
| avm1 | movieclip_in_removed_button | 100% |
| avm1 | target_clip_removed | 100% |
| avm1 | textfield_cache_as_bitmap | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | focusrect_property_swf5 | 100% |
| avm1 | focusrect_property_swf7 | 100% |
| avm1 | focusrect_property_swf6 | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | string_paths_hidden | 98% |
| avm1 | swf6_case_insensitive | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | loop/loop_test8 | 92% |
| avm1 | unload | 90% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| avm1 | movieclip_library_state_values | 90% |
| avm1 | remove_movie_clip | 90% |
| avm1 | transform | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| from_shumway | avm1/moviecliploader | 86% |
| from_shumway/avm1 | moviecliploader | 86% |
| avm1 | movieclip_getbounds | 85% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 84% |
| avm1 | local_to_global | 84% |
| avm1 | tell_target_invalid | 83% |
| avm1 | load_vars | 83% |
| from_shumway | avm1/settimeout | 82% |
| from_shumway/avm1 | settimeout | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| avm1 | execution_order1 | 80% |
| avm1 | tell_target_invalid_swf6 | 80% |
| from_gnash/misc-ming.all | ResolveEventsTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 8 | 7 | 1153 | 155 |
| from_gnash/actionscript.all | - | 1 | - | - |
| from_shumway | - | 2 | - | - |

**avm1 — newly passing:** `bad_placeobject_clipaction`, `drag_drop`, `mouse_pos`, `mouse_pos_with_scale_factor`, `slash_syntax`, `target_clip_swf5`, `target_clip_swf6`, `tell_target`

**avm1 — newly failing:** `create_empty_movie_clip`, `form_loader_encoding_1`, `issue_2084`, `loadmovie_replace_root`, `textfield_cache_as_bitmap`

**from_gnash/actionscript.all — newly failing:** `case-v5`

*Comparing `7767c2657e47` → `ab614b80ddcf`*

## Per-Suite Details

### avm1

- **Pass:** 513/651 (78.8%)
- **Duration:** 9m55s across 30 shards
- **Lines:** 104,007/114,995 matching (90.4%)
- **Avg test duration:** 0.9s — slowest: `timeout` (30.6s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 2m48s across 30 shards
- **Lines:** 15,374/16,957 matching (90.7%)
- **Avg test duration:** 0.8s — slowest: `case-v6` (1.5s)

### from_gnash/misc-ming.all

- **Pass:** 43/102 (42.2%)
- **Duration:** 1m52s across 30 shards
- **Lines:** 2,786/4,505 matching (61.8%)
- **Avg test duration:** 1.0s — slowest: `matrix_test` (5.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 165/231 matching (71.4%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.2s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 14s across 30 shards
- **Lines:** 332/499 matching (66.5%)
- **Avg test duration:** 0.8s — slowest: `action_execution_order_test10` (0.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 16s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.8s — slowest: `missing_bitmap` (1.0s)

### from_shumway

- **Pass:** 52/92 (56.5%)
- **Duration:** 1m12s across 30 shards
- **Lines:** 747/1,276 matching (58.5%)
- **Avg test duration:** 0.7s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (1.7s)

### from_shumway/avm1

- **Pass:** 37/47 (78.7%)
- **Duration:** 35s across 30 shards
- **Lines:** 464/491 matching (94.5%)
- **Avg test duration:** 0.7s — slowest: `setinterval` (0.9s)
