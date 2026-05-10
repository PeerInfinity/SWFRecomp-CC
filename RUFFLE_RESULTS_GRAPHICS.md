# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e527f410660e`  
**Date:** 2026-05-10 23:40 UTC  
**Total duration:** 2h07m28s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 523 | 651 | 80.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 47 | 102 | 46.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 53 | 92 | 57.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 38 | 47 | 80.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **816** | **1125** | **72.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,409 | 114,995 | 90.8% |
| from_gnash/actionscript.all | 15,374 | 16,957 | 90.7% |
| from_gnash/misc-ming.all | 2,828 | 4,505 | 62.8% |
| from_gnash/misc-mtasc.all | 165 | 231 | 71.4% |
| from_gnash/misc-swfc.all | 332 | 499 | 66.5% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 750 | 1,276 | 58.8% |
| from_shumway/avm1 | 467 | 491 | 95.1% |
| **Total** | **124,374** | **139,005** | **89.5%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 117 | - | 1 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 36 | - | 3 | - |
| from_gnash/misc-mtasc.all | 1 | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 36 | - | - | - |
| from_shumway/avm1 | 8 | - | - | - |
| **Total** | **204** | **3** | **4** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | button_order | 100% |
| avm1 | click_block | 100% |
| avm1 | create_empty_movie_clip | 100% |
| avm1 | form_loader_encoding_1 | 100% |
| avm1 | issue_2084 | 100% |
| avm1 | issue_9885 | 100% |
| avm1 | loadmovie_replace_root | 100% |
| avm1 | movieclip_in_removed_button | 100% |
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
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | loop/loop_test8 | 92% |
| avm1 | unload | 90% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| avm1 | movieclip_library_state_values | 90% |
| avm1 | remove_movie_clip | 90% |
| avm1 | goto_frame2 | 89% |
| avm1 | transform | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| from_shumway | avm1/moviecliploader | 86% |
| from_shumway/avm1 | moviecliploader | 86% |
| avm1 | movieclip_getbounds | 85% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 84% |
| avm1 | local_to_global | 84% |
| avm1 | load_vars | 83% |
| from_shumway | avm1/settimeout | 82% |
| from_shumway/avm1 | settimeout | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| from_gnash/misc-ming.all | ResolveEventsTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 11 | 1 | 402 | - |
| from_gnash/actionscript.all | 1 | - | - | - |
| from_gnash/misc-ming.all | 6 | - | 46 | 4 |
| from_shumway | 1 | - | 3 | - |
| from_shumway/avm1 | 1 | - | 3 | - |

**avm1 — newly passing:** `button_keypress`, `call`, `execution_order1`, `execution_order2`, `execution_order4`, `function_base_clip`, `goto_frame`, `goto_label`, `target_clip_removed`, `tell_target_invalid`, `tell_target_invalid_swf6`

**avm1 — newly failing:** `issue_9885`

**from_gnash/actionscript.all — newly passing:** `case-v5`

**from_gnash/misc-ming.all — newly passing:** `action_order/action_execution_order_test2`, `consecutive_goto_frame_test`, `event_handler_scope_test`, `frame_label_test`

**from_shumway — newly passing:** `avm1/rollover`

**from_shumway/avm1 — newly passing:** `rollover`

*Comparing `ab614b80ddcf` → `e527f410660e`*

## Per-Suite Details

### avm1

- **Pass:** 523/651 (80.3%)
- **Duration:** 1h01m09s across 30 shards
- **Lines:** 104,409/114,995 matching (90.8%)
- **Avg test duration:** 5.6s — slowest: `timeout` (49.1s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m40s across 30 shards
- **Lines:** 15,374/16,957 matching (90.7%)
- **Avg test duration:** 4.3s — slowest: `LoadVars-v5` (19.6s)

### from_gnash/misc-ming.all

- **Pass:** 47/102 (46.1%)
- **Duration:** 25m11s across 30 shards
- **Lines:** 2,828/4,505 matching (62.8%)
- **Avg test duration:** 14.8s — slowest: `matrix_test` (22.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m05s across 30 shards
- **Lines:** 165/231 matching (71.4%)
- **Avg test duration:** 13.8s — slowest: `enum` (18.9s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m12s across 30 shards
- **Lines:** 332/499 matching (66.5%)
- **Avg test duration:** 15.7s — slowest: `movieclip_destruction_test4` (19.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m23s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.9s — slowest: `jump_after_end` (19.6s)

### from_shumway

- **Pass:** 53/92 (57.6%)
- **Duration:** 13m56s across 30 shards
- **Lines:** 750/1,276 matching (58.8%)
- **Avg test duration:** 9.0s — slowest: `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` (19.7s)

### from_shumway/avm1

- **Pass:** 38/47 (80.9%)
- **Duration:** 1m49s across 30 shards
- **Lines:** 467/491 matching (95.1%)
- **Avg test duration:** 2.3s — slowest: `label` (19.6s)
