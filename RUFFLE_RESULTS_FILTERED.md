# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `344c85a166c3`  
**Date:** 2026-11-15 08:31 UTC  
**Total duration:** 4h32m35s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 0 | 5 | 0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 0 | 746 | 0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 0 | 1283 | 0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| fonts | 0 | 9 | 0% | [details](ruffle-tests/tests/swfs/fonts/_results/results_filtered.md) |
| from_avmplus | 0 | 1572 | 0% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results_filtered.md) |
| from_gnash/actionscript.all | 0 | 240 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 0 | 110 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 0 | 9 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 0 | 18 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 0 | 20 | 0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 0 | 223 | 0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 0 | 47 | 0% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| import_assets | 0 | 3 | 0% | [details](ruffle-tests/tests/swfs/import_assets/_results/results_filtered.md) |
| mixed_avm | 0 | 12 | 0% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results_filtered.md) |
| regression | 0 | 104 | 0% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| stage3d | 0 | 8 | 0% | [details](ruffle-tests/tests/swfs/stage3d/_results/results_filtered.md) |
| swf | 0 | 7 | 0% | [details](ruffle-tests/tests/swfs/swf/_results/results_filtered.md) |
| text | 0 | 11 | 0% | [details](ruffle-tests/tests/swfs/text/_results/results_filtered.md) |
| timeline | 0 | 17 | 0% | [details](ruffle-tests/tests/swfs/timeline/_results/results_filtered.md) |
| visual | 0 | 149 | 0% | [details](ruffle-tests/tests/swfs/visual/_results/results_filtered.md) |
| **Total** | **0** | **4593** | **0%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 0 | 0 | 0% |
| avm1 | 0 | 0 | 0% |
| avm2 | 0 | 0 | 0% |
| fonts | 0 | 0 | 0% |
| from_avmplus | 0 | 0 | 0% |
| from_gnash/actionscript.all | 0 | 0 | 0% |
| from_gnash/misc-ming.all | 0 | 0 | 0% |
| from_gnash/misc-mtasc.all | 0 | 0 | 0% |
| from_gnash/misc-swfc.all | 0 | 0 | 0% |
| from_gnash/misc-swfmill.all | 0 | 0 | 0% |
| from_shumway | 0 | 0 | 0% |
| from_shumway/avm1 | 0 | 0 | 0% |
| import_assets | 0 | 0 | 0% |
| mixed_avm | 0 | 0 | 0% |
| regression | 0 | 0 | 0% |
| stage3d | 0 | 0 | 0% |
| swf | 0 | 0 | 0% |
| text | 0 | 0 | 0% |
| timeline | 0 | 0 | 0% |
| visual | 0 | 0 | 0% |
| **Total** | **0** | **0** | **0%** |

## Failure Breakdown

| Suite | compile_fail |
|-------|--------------:|
| audio | 5 |
| avm1 | 746 |
| avm2 | 1283 |
| fonts | 9 |
| from_avmplus | 1572 |
| from_gnash/actionscript.all | 240 |
| from_gnash/misc-ming.all | 110 |
| from_gnash/misc-mtasc.all | 9 |
| from_gnash/misc-swfc.all | 18 |
| from_gnash/misc-swfmill.all | 20 |
| from_shumway | 223 |
| from_shumway/avm1 | 47 |
| import_assets | 3 |
| mixed_avm | 12 |
| regression | 104 |
| stage3d | 8 |
| swf | 7 |
| text | 11 |
| timeline | 17 |
| visual | 149 |
| **Total** | **4593** |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 0/5 (0%)
- **Duration:** 1m09s across 30 shards
- **Avg test duration:** 13.8s — slowest: `g711_event_mulaw` (23.1s)

### avm1

- **Pass:** 0/746 (0%)
- **Ignored:** 18 tests
- **Duration:** 46m16s across 30 shards
- **Avg test duration:** 3.6s — slowest: `edittext_paste_empty` (26.0s)

### avm2

- **Pass:** 0/1283 (0%)
- **Ignored:** 38 tests
- **Duration:** 1h15m53s across 30 shards
- **Avg test duration:** 3.4s — slowest: `away3d_advanced_shallow_water_demo` (78.7s)

### fonts

- **Pass:** 0/9 (0%)
- **Duration:** 2m14s across 30 shards
- **Avg test duration:** 14.9s — slowest: `embed_name_lookup` (25.7s)

### from_avmplus

- **Pass:** 0/1572 (0%)
- **Ignored:** 2 tests
- **Duration:** 38m34s across 30 shards
- **Avg test duration:** 1.4s — slowest: `ecma3/Statements/eregress_74474_003` (64.2s)

### from_gnash/actionscript.all

- **Pass:** 0/240 (0%)
- **Ignored:** 3 tests
- **Duration:** 1m48s across 30 shards
- **Avg test duration:** 0.4s — slowest: `MovieClip-v8` (1.9s)

### from_gnash/misc-ming.all

- **Pass:** 0/110 (0%)
- **Ignored:** 1 tests
- **Duration:** 16m11s across 30 shards
- **Avg test duration:** 8.8s — slowest: `action_order/action_execution_order_test6` (25.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 0/9 (0%)
- **Duration:** 1m43s across 30 shards
- **Avg test duration:** 11.5s — slowest: `exception` (23.6s)

### from_gnash/misc-swfc.all

- **Pass:** 0/18 (0%)
- **Ignored:** 2 tests
- **Duration:** 4m38s across 30 shards
- **Avg test duration:** 14.1s — slowest: `mouse_drag_test` (24.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 0/20 (0%)
- **Duration:** 2m40s across 30 shards
- **Avg test duration:** 8.0s — slowest: `zeroframe_definesprite` (23.2s)

### from_shumway

- **Pass:** 0/223 (0%)
- **Ignored:** 6 tests
- **Duration:** 29m59s across 30 shards
- **Avg test duration:** 7.5s — slowest: `acid/acid-large` (27.1s)

### from_shumway/avm1

- **Pass:** 0/47 (0%)
- **Duration:** 2m05s across 30 shards
- **Avg test duration:** 2.6s — slowest: `label` (25.8s)

### import_assets

- **Pass:** 0/3 (0%)
- **Duration:** 46s across 30 shards
- **Avg test duration:** 15.2s — slowest: `avm1_non_swf_import` (23.4s)

### mixed_avm

- **Pass:** 0/12 (0%)
- **Duration:** 30s across 30 shards
- **Avg test duration:** 2.5s — slowest: `avm1_sprite_sc_ignored` (23.1s)

### regression

- **Pass:** 0/104 (0%)
- **Duration:** 11m36s across 30 shards
- **Avg test duration:** 6.7s — slowest: `avm2_graphics_runtime` (25.1s)

### stage3d

- **Pass:** 0/8 (0%)
- **Duration:** 37s across 30 shards
- **Avg test duration:** 4.6s — slowest: `draw_to_bitmap_data_unconfigured` (18.9s)

### swf

- **Pass:** 0/7 (0%)
- **Duration:** 44s across 30 shards
- **Avg test duration:** 6.2s — slowest: `lzma_length_too_long` (22.8s)

### text

- **Pass:** 0/11 (0%)
- **Duration:** 2m47s across 30 shards
- **Avg test duration:** 15.2s — slowest: `text_caret_placement_leading` (26.3s)

### timeline

- **Pass:** 0/17 (0%)
- **Duration:** 4m44s across 30 shards
- **Avg test duration:** 16.7s — slowest: `frame_script_construct` (26.4s)

### visual

- **Pass:** 0/149 (0%)
- **Duration:** 27m34s across 30 shards
- **Avg test duration:** 11.1s — slowest: `definefont4` (90.1s)
