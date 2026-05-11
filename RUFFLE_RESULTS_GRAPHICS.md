# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `be795aae226b`  
**Date:** 2026-05-11 03:59 UTC  
**Total duration:** 2h07m31s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 578 | 651 | 88.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 52 | 102 | 51.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 59 | 92 | 64.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 42 | 47 | 89.4% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **887** | **1125** | **78.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,627 | 114,995 | 91.9% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 2,963 | 4,577 | 64.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 373 | 499 | 74.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 768 | 1,276 | 60.2% |
| from_shumway/avm1 | 482 | 491 | 98.2% |
| **Total** | **125,866** | **139,077** | **90.5%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 60 | - | 1 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 31 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 4 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 30 | - | - | - |
| from_shumway/avm1 | 4 | - | - | - |
| **Total** | **130** | **3** | **3** | **1** |

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
| avm1 | remove_movie_clip | 90% |
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
| avm1 | 8 | - | 59 | - |
| from_gnash/misc-ming.all | 4 | - | 31 | - |
| from_gnash/misc-swfc.all | 1 | - | 41 | - |
| from_shumway | 1 | - | 2 | - |

**avm1 — newly passing:** `focusrect_property_swf6`, `get_bytes_total`, `local_to_global`, `movieclip_getbounds`, `string_paths_hidden`, `swf6_case_insensitive`, `transform`, `unload`

**from_gnash/misc-ming.all — newly passing:** `DefineEditTextVariableNameTest`, `loop/loop_test8`, `replace_shapes1test`, `shape_test`

**from_gnash/misc-swfc.all — newly passing:** `movieclip_destruction_test2`

**from_shumway — newly passing:** `movieinfo1`

*Comparing `947b8351af9a` → `be795aae226b`*

## Per-Suite Details

### avm1

- **Pass:** 578/651 (88.8%)
- **Duration:** 1h01m45s across 30 shards
- **Lines:** 105,627/114,995 matching (91.9%)
- **Avg test duration:** 5.6s — slowest: `timeout` (47.7s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 13m44s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 4.3s — slowest: `NetConnection-v5` (22.8s)

### from_gnash/misc-ming.all

- **Pass:** 52/102 (51.0%)
- **Duration:** 24m40s across 30 shards
- **Lines:** 2,963/4,577 matching (64.7%)
- **Avg test duration:** 14.5s — slowest: `matrix_test` (21.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.0s — slowest: `TextFieldTest` (19.1s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 4m13s across 30 shards
- **Lines:** 373/499 matching (74.7%)
- **Avg test duration:** 15.8s — slowest: `swf4opcode` (20.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m23s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.9s — slowest: `trace-as2/root_onload` (22.2s)

### from_shumway

- **Pass:** 59/92 (64.1%)
- **Duration:** 13m48s across 30 shards
- **Lines:** 768/1,276 matching (60.2%)
- **Avg test duration:** 8.9s — slowest: `avm1timeline1` (20.6s)

### from_shumway/avm1

- **Pass:** 42/47 (89.4%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 482/491 matching (98.2%)
- **Avg test duration:** 2.3s — slowest: `label` (18.3s)
