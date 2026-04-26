# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `1f111219fa91`  
**Date:** 2026-04-26 22:53 UTC  
**Total duration:** 5m47s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 547 | 641 | 85.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 0 | 190 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 46 | 102 | 45.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **727** | **1115** | **65.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 99,064 | 107,951 | 91.8% |
| from_gnash/actionscript.all | 0 | 0 | 0% |
| from_gnash/misc-ming.all | 2,434 | 4,402 | 55.3% |
| from_gnash/misc-mtasc.all | 162 | 163 | 99.4% |
| from_gnash/misc-swfc.all | 262 | 499 | 52.5% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 653 | 1,260 | 51.8% |
| from_shumway/avm1 | 473 | 475 | 99.6% |
| **Total** | **103,095** | **114,801** | **89.8%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | 53 | 34 |
| from_gnash/actionscript.all | 190 | - |
| from_gnash/misc-ming.all | 6 | 39 |
| from_gnash/misc-mtasc.all | 1 | - |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | 2 | 25 |
| from_shumway/avm1 | 2 | - |
| **Total** | **254** | **108** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 83% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 52 | 11 | - |
| from_gnash/actionscript.all | - | 168 | 2200 | - |
| from_gnash/misc-ming.all | - | 1 | 105 | - |
| from_gnash/misc-mtasc.all | - | - | 25 | - |
| from_shumway | - | 1 | 6 | - |
| from_shumway/avm1 | - | 1 | 6 | - |

**avm1 — newly failing:** `cross_movie_root`, `depth_replacement_audio_unloading`, `do_init_action_child`, `focusrect_property_swf5`, `focusrect_property_swf6`, `focusrect_property_swf7`, `global_swf5_6_7_8_9`, `global_swf6_7_8`, `hittest_winding_rule`, `instanceof_coercions`, `interface_implements_op`, `issue_2870`, `loadmovie`, `loadmovie_flashvars`, `loadmovie_method`, `loadmovie_registerclass`, `loadmovie_replace_root`, `loadmovie_var_persistence`, `loadmovienum`, `loadmovienum_cross_version_prototype`, `lock_root`, `mcl_events_swf_version`, `mcl_getprogress`, `mcl_loadclip`, `mcl_loadclip_properties`, `mcl_loadclip_replace_root`, `mcl_unloadclip`, `movieclip_blend_mode_property`, `movieclip_invalid_get_bounds_1`, `movieclip_invalid_get_bounds_2`, `movieclip_invalid_get_bounds_3`, `movieclip_invalid_get_bounds_4`, `movieclip_invalid_get_bounds_5`, `movieclip_invalid_get_bounds_6`, `movieclip_invalid_get_bounds_7`, `movieclip_invalid_get_bounds_8`, `movieclip_lockroot`, `movieclip_state_values`, `moviecliploader_flashvars`, `register_class`, `register_class_swf6`, `register_class_with_sound`, `resolve_different_root`, `string_paths_eval2`, `swf5_to_6_cross_call`, `swf5_xml_event_handler_context`, `swf6_to_5_cross_call`, `unloadmovie`, `unloadmovie_method`, `unloadmovienum`

**from_gnash/actionscript.all — newly failing:** `Accessibility-v5`, `Accessibility-v6`, `Accessibility-v7`, `Accessibility-v8`, `AsBroadcaster-v5`, `BitmapData-v5`, `BitmapData-v6`, `BitmapData-v7`, `Boolean-v5`, `Boolean-v6`, `Boolean-v7`, `Boolean-v8`, `Camera-v5`, `Color-v5`, `Color-v6`, `Color-v7`, `Color-v8`, `ColorTransform-v5`, `ColorTransform-v6`, `ColorTransform-v7`, `ColorTransform-v8`, `ContextMenu-v5`, `ContextMenu-v6`, `Error-v5`, `Error-v6`, `Error-v7`, `Error-v8`, `ExternalInterface-v5`, `Key-v5`, `Key-v6`, `Key-v7`, `Key-v8`, `LoadVars-v5`, `LocalConnection-v5`, `LocalConnection-v6`, `LocalConnection-v7`, `LocalConnection-v8`, `Matrix-v5`, `Microphone-v5`, `Mouse-v5`, `Mouse-v6`, `Mouse-v7`, `Mouse-v8`, `MovieClipLoader-v5`, `MovieClipLoader-v6`, `NetConnection-v5`, `NetStream-v5`, `NetStream-v6`, `NetStream-v7`, `NetStream-v8`, `Number-v6`, `Number-v7`, `Number-v8`, `Point-v5`, `Point-v6`, `Point-v7`, `Point-v8`, `Random-v5`, `Random-v6`, `Random-v7`, `Random-v8`, `Rectangle-v5`, `Rectangle-v6`, `Rectangle-v7`, `Selection-v5`, `Stage-v5`, `System-v5`, `System-v6`, `System-v7`, `System-v8`, `TextFieldHTML-v5`, `TextFieldHTML-v6`, `TextFieldHTML-v7`, `TextFieldHTML-v8`, `TextFormat-v5`, `TextFormat-v6`, `TextSnapshot-v5`, `TextSnapshot-v6`, `TextSnapshot-v7`, `TextSnapshot-v8`, `Transform-v5`, `Transform-v6`, `Transform-v7`, `Try-v5`, `Try-v6`, `Try-v7`, `Try-v8`, `Video-v5`, `Video-v6`, `Video-v7`, `Video-v8`, `XMLSocket-v5`, `XMLSocket-v6`, `XMLSocket-v7`, `XMLSocket-v8`, `argstest-v5`, `case-v5`, `delete-v5`, `delete-v6`, `delete-v7`, `delete-v8`, `enumerate-v5`, `enumerate-v6`, `enumerate-v7`, `enumerate-v8`, `flash-v5`, `flash-v6`, `flash-v7`, `swap-v5`, `swap-v6`, `swap-v7`, `swap-v8`, `targetPath-v5`

**from_shumway — newly failing:** `avm1/levels`

**from_shumway/avm1 — newly failing:** `levels`

*Comparing `8ec3f4779e37` → `1f111219fa91`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 547/641 (85.3%)
- **Duration:** 3m15s across 30 shards
- **Lines:** 99,064/107,951 matching (91.8%)
- **Avg test duration:** 0.2s — slowest: `edittext_newline_stripping` (6.2s)

### from_gnash/actionscript.all

- **Pass:** 0/190 (0%)
- **Duration:** 55s across 30 shards
- **Avg test duration:** 0.2s — slowest: `String-v8` (0.5s)

### from_gnash/misc-ming.all

- **Pass:** 46/102 (45.1%)
- **Duration:** 43s across 30 shards
- **Lines:** 2,434/4,402 matching (55.3%)
- **Avg test duration:** 0.4s — slowest: `matrix_test` (4.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2s across 30 shards
- **Lines:** 162/163 matching (99.4%)
- **Avg test duration:** 0.2s — slowest: `function_test` (0.2s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 5s across 30 shards
- **Lines:** 262/499 matching (52.5%)
- **Avg test duration:** 0.3s — slowest: `sound` (0.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 0.2s — slowest: `dict_cross` (0.2s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 29s across 30 shards
- **Lines:** 653/1,260 matching (51.8%)
- **Avg test duration:** 0.3s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (0.6s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 12s across 30 shards
- **Lines:** 473/475 matching (99.6%)
- **Avg test duration:** 0.2s — slowest: `depth` (0.3s)
