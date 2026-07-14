# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `4a3b0bdb22af`  
**Date:** 2026-07-14 18:18 UTC  
**Total duration:** 4h08m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 631 | 661 | 95.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| avm2 | 734 | 978 | 75.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 67 | 109 | 61.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| regression | 42 | 42 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_graphics_filtered.md) |
| **Total** | **1760** | **2193** | **80.3%** | |

*302 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,035 | 107,545 | 96.7% |
| avm2 | 94,656 | 125,366 | 75.5% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,024 | 5,188 | 77.6% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 421 | 555 | 75.9% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| regression | 262 | 262 | 100% |
| **Total** | **234,056** | **271,717** | **86.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| avm1 | 18 | 12 | - |
| avm2 | 239 | 1 | 4 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 14 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 4 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **283** | **146** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | button_nested_frame_simple | 100% |
| avm2 | stylesheet | 100% |
| avm2 | stylesheet_transform | 99% |
| avm2 | parse_int | 99% |
| avm2 | error_tostring_more | 98% |
| avm2 | parse_float_swf10 | 98% |
| avm2 | movieclip_hittest | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
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
| avm2 | stage_loaderinfo_properties | 92% |
| avm2 | unescape | 89% |
| avm2 | perspective_projection_basic | 88% |
| avm2 | core_exceptions | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| avm2 | displayobjectcontainer_getobjectsunderpoint | 87% |
| avm2 | issue_8630_placeremoveplace | 87% |
| avm2 | mouseevent_valueof_tostring | 86% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| avm2 | matrix | 83% |
| avm2 | issue_8630_placeremoveplace_scriptremove | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | mouse_wheel_events | 81% |
| avm2 | indexing_delete | 80% |

## Per-Suite Details

### avm1

- **Pass:** 631/661 (95.5%)
- **Ignored:** 45 tests
- **Duration:** 46m57s across 30 shards
- **Lines:** 104,035/107,545 matching (96.7%)
- **Avg test duration:** 3.9s — slowest: `init_object_invalid` (29.8s)

### avm2

- **Pass:** 734/978 (75.1%)
- **Ignored:** 227 tests
- **Duration:** 2h11m34s across 30 shards
- **Lines:** 94,656/125,366 matching (75.5%)
- **Avg test duration:** 5.8s — slowest: `bitmapdata_accuracy` (41.6s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 26m51s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 6.5s — slowest: `MovieClip-v8` (52.7s)

### from_gnash/misc-ming.all

- **Pass:** 67/109 (61.5%)
- **Ignored:** 2 tests
- **Duration:** 16m46s across 30 shards
- **Lines:** 4,024/5,188 matching (77.6%)
- **Avg test duration:** 9.0s — slowest: `matrix_test` (100.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m43s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.5s — slowest: `function_test` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 3m21s across 30 shards
- **Lines:** 421/555 matching (75.9%)
- **Avg test duration:** 9.9s — slowest: `soft_reference_test1` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m57s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.8s — slowest: `zeroframe_definesprite` (21.2s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 12m04s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 5.8s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (21.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m56s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.0s — slowest: `label` (16.2s)

### regression

- **Pass:** 42/42 (100%)
- **Duration:** 4m43s across 30 shards
- **Lines:** 262/262 matching (100%)
- **Avg test duration:** 6.7s — slowest: `onconstruct_cross_swf_version` (21.2s)
