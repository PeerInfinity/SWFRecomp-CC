# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `344c85a166c3`  
**Date:** 2026-11-08 08:30 UTC  
**Total duration:** 4h20m41s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 0 | 5 | 0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 0 | 734 | 0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 0 | 1278 | 0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
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
| **Total** | **0** | **4576** | **0%** | |

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
| avm1 | 734 |
| avm2 | 1278 |
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
| **Total** | **4576** |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 0/5 (0%)
- **Duration:** 58s across 30 shards
- **Avg test duration:** 11.5s — slowest: `g711_event_mulaw` (24.9s)

### avm1

- **Pass:** 0/734 (0%)
- **Ignored:** 18 tests
- **Duration:** 42m49s across 30 shards
- **Avg test duration:** 3.4s — slowest: `movieclip_line_gradient_style` (26.0s)

### avm2

- **Pass:** 0/1278 (0%)
- **Ignored:** 38 tests
- **Duration:** 1h12m34s across 30 shards
- **Avg test duration:** 3.2s — slowest: `away3d_advanced_shallow_water_demo` (52.4s)

### fonts

- **Pass:** 0/9 (0%)
- **Duration:** 1m50s across 30 shards
- **Avg test duration:** 12.2s — slowest: `device_font_glyph_fallback` (25.3s)

### from_avmplus

- **Pass:** 0/1572 (0%)
- **Ignored:** 2 tests
- **Duration:** 37m22s across 30 shards
- **Avg test duration:** 1.4s — slowest: `ecma3/Statements/eregress_74474_003` (50.7s)

### from_gnash/actionscript.all

- **Pass:** 0/240 (0%)
- **Ignored:** 3 tests
- **Duration:** 1m46s across 30 shards
- **Avg test duration:** 0.4s — slowest: `MovieClip-v8` (2.0s)

### from_gnash/misc-ming.all

- **Pass:** 0/110 (0%)
- **Ignored:** 1 tests
- **Duration:** 15m34s across 30 shards
- **Avg test duration:** 8.5s — slowest: `PlaceObject2Test` (25.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 0/9 (0%)
- **Duration:** 1m42s across 30 shards
- **Avg test duration:** 11.4s — slowest: `TextFieldTest` (25.7s)

### from_gnash/misc-swfc.all

- **Pass:** 0/18 (0%)
- **Ignored:** 2 tests
- **Duration:** 4m33s across 30 shards
- **Avg test duration:** 13.8s — slowest: `submoviegetvar` (25.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 0/20 (0%)
- **Duration:** 2m22s across 30 shards
- **Avg test duration:** 7.1s — slowest: `dict_cross` (24.5s)

### from_shumway

- **Pass:** 0/223 (0%)
- **Ignored:** 6 tests
- **Duration:** 29m19s across 30 shards
- **Avg test duration:** 7.2s — slowest: `acid/acid-bitmap-draw_quality_high` (28.4s)

### from_shumway/avm1

- **Pass:** 0/47 (0%)
- **Duration:** 1m22s across 30 shards
- **Avg test duration:** 1.7s — slowest: `text-bind` (24.5s)

### import_assets

- **Pass:** 0/3 (0%)
- **Duration:** 31s across 30 shards
- **Avg test duration:** 10.4s — slowest: `avm1_non_swf_import` (15.9s)

### mixed_avm

- **Pass:** 0/12 (0%)
- **Duration:** 31s across 30 shards
- **Avg test duration:** 2.5s — slowest: `avm1_sprite_sc_ignored` (24.4s)

### regression

- **Pass:** 0/104 (0%)
- **Duration:** 11m32s across 30 shards
- **Avg test duration:** 6.6s — slowest: `avm2_timeline_solid` (25.8s)

### stage3d

- **Pass:** 0/8 (0%)
- **Duration:** 42s across 30 shards
- **Avg test duration:** 5.2s — slowest: `draw_to_bitmap_data_unconfigured` (25.1s)

### swf

- **Pass:** 0/7 (0%)
- **Duration:** 42s across 30 shards
- **Avg test duration:** 6.0s — slowest: `convolution_filter_big_matrix` (25.2s)

### text

- **Pass:** 0/11 (0%)
- **Duration:** 2m46s across 30 shards
- **Avg test duration:** 15.1s — slowest: `auto_size/height` (25.8s)

### timeline

- **Pass:** 0/17 (0%)
- **Duration:** 4m31s across 30 shards
- **Avg test duration:** 15.9s — slowest: `frame_script_cleanup` (26.1s)

### visual

- **Pass:** 0/149 (0%)
- **Duration:** 27m10s across 30 shards
- **Avg test duration:** 10.9s — slowest: `definefont4` (88.5s)
