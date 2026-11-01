# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `344c85a166c3`  
**Date:** 2026-11-01 08:33 UTC  
**Total duration:** 4h39m01s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 0 | 5 | 0% | [details](ruffle-tests/tests/swfs/audio/_results/results_filtered.md) |
| avm1 | 0 | 731 | 0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 0 | 1274 | 0% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
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
| **Total** | **0** | **4569** | **0%** | |

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
| avm1 | 731 |
| avm2 | 1274 |
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
| **Total** | **4569** |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 0/5 (0%)
- **Duration:** 1m13s across 30 shards
- **Avg test duration:** 14.7s — slowest: `g711_event_mulaw` (25.2s)

### avm1

- **Pass:** 0/731 (0%)
- **Ignored:** 18 tests
- **Duration:** 48m14s across 30 shards
- **Avg test duration:** 3.8s — slowest: `netconnection_serialize_arrays` (31.5s)

### avm2

- **Pass:** 0/1274 (0%)
- **Ignored:** 38 tests
- **Duration:** 1h16m59s across 30 shards
- **Avg test duration:** 3.4s — slowest: `away3d_advanced_shallow_water_demo` (84.8s)

### fonts

- **Pass:** 0/9 (0%)
- **Duration:** 2m14s across 30 shards
- **Avg test duration:** 14.9s — slowest: `embed_matching/fallback_preferences` (24.8s)

### from_avmplus

- **Pass:** 0/1572 (0%)
- **Ignored:** 2 tests
- **Duration:** 39m15s across 30 shards
- **Avg test duration:** 1.4s — slowest: `ecma3/Statements/eregress_74474_003` (52.3s)

### from_gnash/actionscript.all

- **Pass:** 0/240 (0%)
- **Ignored:** 3 tests
- **Duration:** 1m53s across 30 shards
- **Avg test duration:** 0.4s — slowest: `MovieClip-v8` (2.0s)

### from_gnash/misc-ming.all

- **Pass:** 0/110 (0%)
- **Ignored:** 1 tests
- **Duration:** 16m33s across 30 shards
- **Avg test duration:** 9.0s — slowest: `duplicate_movie_clip_test` (27.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 0/9 (0%)
- **Duration:** 1m52s across 30 shards
- **Avg test duration:** 12.5s — slowest: `function_test` (24.9s)

### from_gnash/misc-swfc.all

- **Pass:** 0/18 (0%)
- **Ignored:** 2 tests
- **Duration:** 4m33s across 30 shards
- **Avg test duration:** 13.8s — slowest: `edittext_test1` (25.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 0/20 (0%)
- **Duration:** 2m34s across 30 shards
- **Avg test duration:** 7.7s — slowest: `zeroframe_definesprite` (26.4s)

### from_shumway

- **Pass:** 0/223 (0%)
- **Ignored:** 6 tests
- **Duration:** 30m33s across 30 shards
- **Avg test duration:** 7.6s — slowest: `acid/acid-large` (27.5s)

### from_shumway/avm1

- **Pass:** 0/47 (0%)
- **Duration:** 1m15s across 30 shards
- **Avg test duration:** 1.6s — slowest: `text-bind` (23.0s)

### import_assets

- **Pass:** 0/3 (0%)
- **Duration:** 41s across 30 shards
- **Avg test duration:** 13.6s — slowest: `empty_url` (23.5s)

### mixed_avm

- **Pass:** 0/12 (0%)
- **Duration:** 32s across 30 shards
- **Avg test duration:** 2.6s — slowest: `avm1_sprite_sc_ignored` (25.0s)

### regression

- **Pass:** 0/104 (0%)
- **Duration:** 12m11s across 30 shards
- **Avg test duration:** 7.0s — slowest: `avm1_parent_child_bitmap_fill` (25.1s)

### stage3d

- **Pass:** 0/8 (0%)
- **Duration:** 38s across 30 shards
- **Avg test duration:** 4.7s — slowest: `draw_to_bitmap_data_unconfigured` (18.9s)

### swf

- **Pass:** 0/7 (0%)
- **Duration:** 60s across 30 shards
- **Avg test duration:** 8.5s — slowest: `swf_length_too_short_no_second_frame` (23.1s)

### text

- **Pass:** 0/11 (0%)
- **Duration:** 2m50s across 30 shards
- **Avg test duration:** 15.5s — slowest: `text_caret_placement_scroll` (24.5s)

### timeline

- **Pass:** 0/17 (0%)
- **Duration:** 5m03s across 30 shards
- **Avg test duration:** 17.8s — slowest: `swf_9_frame_script_cleanup_goto2` (27.6s)

### visual

- **Pass:** 0/149 (0%)
- **Duration:** 28m48s across 30 shards
- **Avg test duration:** 11.6s — slowest: `definefont4` (110.2s)
