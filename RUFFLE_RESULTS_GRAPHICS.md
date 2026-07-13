# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `8c4e8518e97f`  
**Date:** 2026-07-13 02:38 UTC  
**Total duration:** 4h01m52s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 634 | 706 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| avm2 | 819 | 1204 | 68.0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 68 | 111 | 61.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics.md) |
| **Total** | **1853** | **2493** | **74.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 115,797 | 130,978 | 88.4% |
| avm2 | 102,030 | 149,868 | 68.1% |
| from_gnash/actionscript.all | 30,356 | 38,791 | 78.3% |
| from_gnash/misc-ming.all | 4,048 | 5,248 | 77.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 438 | 580 | 75.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| regression | 260 | 260 | 100% |
| **Total** | **254,604** | **327,818** | **77.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 54 | - | 1 | - |
| avm2 | 356 | 4 | - | 1 |
| from_gnash/actionscript.all | 13 | - | - | - |
| from_gnash/misc-ming.all | 15 | - | - | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 16 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| regression | - | - | - | - |
| **Total** | **459** | **4** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| avm2 | stylesheet | 100% |
| avm1 | watch_recursion_swf7 | 99% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | stylesheet_transform | 99% |
| avm2 | soundmixer_soundtransform | 99% |
| from_gnash/actionscript.all | array-v5 | 99% |
| avm2 | parse_int | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | displayobject_hittestpoint | 96% |
| avm2 | selection | 96% |
| avm2 | tab_ordering_tabbable | 96% |
| avm2 | property_is_enumerable_reset | 96% |
| avm2 | focusrect_property | 95% |
| avm2 | stylesheet_parse_color | 94% |
| avm2 | mouseevent_constr | 94% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | simplebutton_soundtransform | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm2 | json_stringify | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | unescape | 89% |
| avm2 | perspective_projection_basic | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | bounds_mode | 87% |
| avm2 | bitmap_subclass | 86% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| avm2 | displayobject_opaque_background | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | number_tostring | 83% |
| avm1 | load_vars | 83% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm2 | 20 | - | 4125 | - |

**avm2 — newly passing:** `agal_compiler`, `get_timer`, `movieclip_soundtransform`, `shared_object_no_root`, `sound_embeddedprops`, `sound_play`, `sound_valueof`, `soundchannel_soundtransform`, `soundchannel_soundtransform_exists`, `soundchannel_stop`, `soundmixer_buffertime`, `soundmixer_stopall`, `soundtransform`, `timer`, `timer_events`, `timer_finished`, `timer_reset`, `timer_setdelay`

*Comparing `bf93755e0cc9` → `8c4e8518e97f`*

## Per-Suite Details

### avm1

- **Pass:** 634/706 (89.8%)
- **Duration:** 59m59s across 30 shards
- **Lines:** 115,797/130,978 matching (88.4%)
- **Avg test duration:** 5.0s — slowest: `netstream_play_flv_screen` (36.4s)

### avm2

- **Pass:** 819/1204 (68.0%)
- **Duration:** 1h41m49s across 30 shards
- **Lines:** 102,030/149,868 matching (68.1%)
- **Avg test duration:** 5.0s — slowest: `away3d_advanced_shallow_water_demo` (63.1s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 27m25s across 30 shards
- **Lines:** 30,356/38,791 matching (78.3%)
- **Avg test duration:** 6.7s — slowest: `array-v6` (57.5s)

### from_gnash/misc-ming.all

- **Pass:** 68/111 (61.3%)
- **Duration:** 20m37s across 30 shards
- **Lines:** 4,048/5,248 matching (77.1%)
- **Avg test duration:** 11.1s — slowest: `matrix_test` (106.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.0s — slowest: `enum` (21.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m32s across 30 shards
- **Lines:** 438/580 matching (75.5%)
- **Avg test duration:** 13.6s — slowest: `movieclip_destruction_test4` (23.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m04s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 9.2s — slowest: `zeroframe_definesprite` (22.5s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 14m51s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.6s — slowest: `avm1/text-bind` (24.0s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m14s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.8s — slowest: `text-bind` (21.3s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 5m29s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 8.0s — slowest: `nc_onstatus_closure` (23.4s)
