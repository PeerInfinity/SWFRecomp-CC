# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e0568fe7e53f`  
**Date:** 2026-05-11 17:30 UTC  
**Total duration:** 2h08m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 587 | 651 | 90.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 57 | 102 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 61 | 92 | 66.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **905** | **1125** | **80.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,852 | 114,995 | 92.0% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,087 | 4,577 | 67.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 376 | 499 | 75.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 773 | 1,276 | 60.6% |
| from_shumway/avm1 | 487 | 491 | 99.2% |
| **Total** | **126,228** | **139,077** | **90.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 51 | - | 1 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 24 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 3 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 28 | - | - | - |
| from_shumway/avm1 | 2 | - | - | - |
| **Total** | **109** | **3** | **3** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | click_block | 100% |
| avm1 | netstream_seek_flv | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | get_frame_number_test | 90% |
| from_gnash/misc-ming.all | loading/loadMovieTest | 89% |
| avm1 | goto_frame2 | 89% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | ResolveEventsTest | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v5 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test8-v6 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |
| avm1 | unload_nested_child | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 9 | - | 225 | - |
| from_gnash/misc-ming.all | 7 | - | 124 | - |
| from_gnash/misc-swfc.all | 1 | - | 3 | - |
| from_shumway | 2 | - | 5 | - |
| from_shumway/avm1 | 2 | - | 5 | - |

**avm1 — newly passing:** `clone_sprite_edittext`, `clone_sprite_edittext_dynamic`, `clone_sprite_types`, `duplicate_movie_clip`, `duplicate_movie_clip_drawing`, `remove_movie_clip`, `removed_target_clip_scope`, `string_paths_variable_scopes`, `textsnapshot_available_text`

**from_gnash/misc-ming.all — newly passing:** `DepthLimitsTest`, `displaylist_depths/displaylist_depths_test9`, `duplicate_movie_clip_test2`, `static_vs_dynamic1`, `static_vs_dynamic2`

**from_shumway — newly passing:** `avm1/duplicateMovieClip/dontremove`, `avm1/duplicateMovieClip/samedepth`

**from_shumway/avm1 — newly passing:** `duplicateMovieClip/dontremove`, `duplicateMovieClip/samedepth`

*Comparing `b232f7e6facb` → `e0568fe7e53f`*

## Per-Suite Details

### avm1

- **Pass:** 587/651 (90.2%)
- **Duration:** 1h01m33s across 30 shards
- **Lines:** 105,852/114,995 matching (92.0%)
- **Avg test duration:** 5.6s — slowest: `timeout` (47.8s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m35s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 4.2s — slowest: `NetStream-v7` (19.9s)

### from_gnash/misc-ming.all

- **Pass:** 57/102 (55.9%)
- **Duration:** 25m23s across 30 shards
- **Lines:** 3,087/4,577 matching (67.4%)
- **Avg test duration:** 14.9s — slowest: `displaylist_depths/displaylist_depths_test8` (27.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.4s — slowest: `enum` (19.0s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 4m27s across 30 shards
- **Lines:** 376/499 matching (75.4%)
- **Avg test duration:** 16.7s — slowest: `sound` (24.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m33s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 18.5s — slowest: `missing_bitmap` (20.1s)

### from_shumway

- **Pass:** 61/92 (66.3%)
- **Duration:** 13m51s across 30 shards
- **Lines:** 773/1,276 matching (60.6%)
- **Avg test duration:** 9.0s — slowest: `avm1/rollover` (19.4s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 487/491 matching (99.2%)
- **Avg test duration:** 2.2s — slowest: `label` (18.7s)
