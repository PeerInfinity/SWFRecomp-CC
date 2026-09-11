# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `13dfc5b483e9`  
**Date:** 2026-09-11 16:55 UTC  
**Total duration:** 9h56m37s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| audio | 3 | 5 | 60.0% | [details](ruffle-tests/tests/swfs/audio/_results/results.md) |
| avm1 | 691 | 733 | 94.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| avm2 | 1200 | 1270 | 94.5% | [details](ruffle-tests/tests/swfs/avm2/_results/results.md) |
| fonts | 6 | 8 | 75.0% | [details](ruffle-tests/tests/swfs/fonts/_results/results.md) |
| from_avmplus | 1529 | 1574 | 97.1% | [details](ruffle-tests/tests/swfs/from_avmplus/_results/results.md) |
| from_gnash/actionscript.all | 141 | 243 | 58.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 69 | 111 | 62.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 11 | 20 | 55.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 213 | 229 | 93.0% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 47 | 47 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| import_assets | 3 | 3 | 100% | [details](ruffle-tests/tests/swfs/import_assets/_results/results.md) |
| mixed_avm | 10 | 12 | 83.3% | [details](ruffle-tests/tests/swfs/mixed_avm/_results/results.md) |
| regression | 90 | 90 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results.md) |
| stage3d | 7 | 7 | 100% | [details](ruffle-tests/tests/swfs/stage3d/_results/results.md) |
| swf | 5 | 7 | 71.4% | [details](ruffle-tests/tests/swfs/swf/_results/results.md) |
| text | 10 | 11 | 90.9% | [details](ruffle-tests/tests/swfs/text/_results/results.md) |
| timeline | 13 | 17 | 76.5% | [details](ruffle-tests/tests/swfs/timeline/_results/results.md) |
| visual | 145 | 147 | 98.6% | [details](ruffle-tests/tests/swfs/visual/_results/results.md) |
| **Total** | **4219** | **4563** | **92.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| audio | 5 | 24 | 20.8% |
| avm1 | 120,011 | 131,677 | 91.1% |
| avm2 | 152,229 | 155,348 | 98.0% |
| fonts | 194 | 364 | 53.3% |
| from_avmplus | 85,558 | 85,996 | 99.5% |
| from_gnash/actionscript.all | 30,418 | 38,791 | 78.4% |
| from_gnash/misc-ming.all | 4,058 | 5,248 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 441 | 580 | 76.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 2,321 | 2,484 | 93.4% |
| from_shumway/avm1 | 491 | 491 | 100% |
| import_assets | 14 | 14 | 100% |
| mixed_avm | 56 | 79 | 70.9% |
| regression | 693 | 693 | 100% |
| stage3d | 208 | 208 | 100% |
| swf | 78 | 94 | 83.0% |
| text | 972 | 973 | 99.9% |
| timeline | 355 | 371 | 95.7% |
| visual | 301 | 350 | 86.0% |
| **Total** | **398,707** | **424,111** | **94.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| audio | 2 | - |
| avm1 | 24 | - |
| avm2 | 34 | - |
| fonts | 1 | - |
| from_avmplus | 4 | 1 |
| from_gnash/actionscript.all | 13 | - |
| from_gnash/misc-ming.all | 13 | - |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | 4 | - |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | 5 | - |
| from_shumway/avm1 | - | - |
| import_assets | - | - |
| mixed_avm | 2 | - |
| regression | - | - |
| stage3d | - | - |
| swf | - | - |
| text | 1 | - |
| timeline | 1 | - |
| visual | - | - |
| **Total** | **104** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm2 | loader_load | 98% |
| from_gnash/actionscript.all | array-v5 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | array-v6 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| avm2 | geom_transform | 96% |
| from_avmplus | recursion/pcre_find_fixedlength | 95% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | number_tostring | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 84% |
| avm1 | load_vars | 83% |
| from_avmplus | ecma3/JSON/adhoc | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 132 |
| avm2 | 1 | 1 | 16 | 3 |
| from_avmplus | - | 1 | - | - |

**avm2 — newly passing:** `loader_duplicate_class`

**avm2 — newly failing:** `geom_transform`

*Comparing `bf907d0023cc` → `13dfc5b483e9`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### audio

- **Pass:** 3/5 (60.0%)
- **Duration:** 1m11s across 30 shards
- **Lines:** 5/24 matching (20.8%)
- **Avg test duration:** 14.2s — slowest: `stream_incomplete_loop` (22.3s)

### avm1

- **Pass:** 691/733 (94.3%)
- **Duration:** 56m14s across 30 shards
- **Lines:** 120,011/131,677 matching (91.1%)
- **Avg test duration:** 4.5s — slowest: `define_font_glyph_table_order` (45.4s)

### avm2

- **Pass:** 1200/1270 (94.5%)
- **Duration:** 3h22m11s across 30 shards
- **Lines:** 152,229/155,348 matching (98.0%)
- **Avg test duration:** 9.5s — slowest: `away3d_advanced_shallow_water_demo` (90.1s)

### fonts

- **Pass:** 6/8 (75.0%)
- **Duration:** 2m34s across 30 shards
- **Lines:** 194/364 matching (53.3%)
- **Avg test duration:** 19.2s — slowest: `embed_matching/fallback_preferences` (29.7s)

### from_avmplus

- **Pass:** 1529/1574 (97.1%)
- **Duration:** 3h01m25s across 30 shards
- **Lines:** 85,558/85,996 matching (99.5%)
- **Avg test duration:** 6.9s — slowest: `ecma3/Statements/eregress_74474_002` (54.4s)

### from_gnash/actionscript.all

- **Pass:** 141/243 (58.0%)
- **Duration:** 21m02s across 30 shards
- **Lines:** 30,418/38,791 matching (78.4%)
- **Avg test duration:** 5.1s — slowest: `MovieClip-v8` (64.1s)

### from_gnash/misc-ming.all

- **Pass:** 69/111 (62.2%)
- **Duration:** 20m34s across 30 shards
- **Lines:** 4,058/5,248 matching (77.3%)
- **Avg test duration:** 11.1s — slowest: `matrix_test` (86.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 9.7s — slowest: `exception` (23.1s)

### from_gnash/misc-swfc.all

- **Pass:** 11/20 (55.0%)
- **Duration:** 4m35s across 30 shards
- **Lines:** 441/580 matching (76.0%)
- **Avg test duration:** 13.7s — slowest: `movieclip_destruction_test1` (22.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m29s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 7.4s — slowest: `dict_callframe` (22.5s)

### from_shumway

- **Pass:** 213/229 (93.0%)
- **Duration:** 41m09s across 30 shards
- **Lines:** 2,321/2,484 matching (93.4%)
- **Avg test duration:** 10.7s — slowest: `acid/acid-large` (77.6s)

### from_shumway/avm1

- **Pass:** 47/47 (100%)
- **Duration:** 2m32s across 30 shards
- **Lines:** 491/491 matching (100%)
- **Avg test duration:** 3.2s — slowest: `moviecliploader` (21.0s)

### import_assets

- **Pass:** 3/3 (100%)
- **Duration:** 41s across 30 shards
- **Lines:** 14/14 matching (100%)
- **Avg test duration:** 13.7s — slowest: `empty_url` (23.0s)

### mixed_avm

- **Pass:** 10/12 (83.3%)
- **Duration:** 1m17s across 30 shards
- **Lines:** 56/79 matching (70.9%)
- **Avg test duration:** 6.4s — slowest: `avm1_sprite_sc_ignored` (15.4s)

### regression

- **Pass:** 90/90 (100%)
- **Duration:** 15m25s across 30 shards
- **Lines:** 693/693 matching (100%)
- **Avg test duration:** 10.2s — slowest: `avm2_parent_child_static_text` (44.8s)

### stage3d

- **Pass:** 7/7 (100%)
- **Duration:** 56s across 30 shards
- **Lines:** 208/208 matching (100%)
- **Avg test duration:** 7.9s — slowest: `sampler_odd_size` (10.3s)

### swf

- **Pass:** 5/7 (71.4%)
- **Duration:** 38s across 30 shards
- **Lines:** 78/94 matching (83.0%)
- **Avg test duration:** 5.4s — slowest: `lzma_length_too_long` (16.4s)

### text

- **Pass:** 10/11 (90.9%)
- **Duration:** 3m20s across 30 shards
- **Lines:** 972/973 matching (99.9%)
- **Avg test duration:** 18.1s — slowest: `auto_size/width` (28.7s)

### timeline

- **Pass:** 13/17 (76.5%)
- **Duration:** 5m34s across 30 shards
- **Lines:** 355/371 matching (95.7%)
- **Avg test duration:** 19.6s — slowest: `swf_9_frame_script_cleanup_goto2` (29.6s)

### visual

- **Pass:** 145/147 (98.6%)
- **Duration:** 31m15s across 30 shards
- **Lines:** 301/350 matching (86.0%)
- **Avg test duration:** 12.7s — slowest: `definefont4` (89.8s)
