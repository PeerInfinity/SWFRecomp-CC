# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `ce31587cf186`  
**Date:** 2026-05-11 20:09 UTC  
**Total duration:** 18m02s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 651 | 92.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 63 | 102 | 61.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 72 | 92 | 78.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **940** | **1125** | **83.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,932 | 114,995 | 92.1% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,120 | 4,577 | 68.2% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 387 | 499 | 77.6% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **126,463** | **139,077** | **90.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 35 | - | 2 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 15 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 2 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 17 | - | - | - |
| from_shumway/avm1 | - | - | - | - |
| **Total** | **70** | **3** | **4** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | netstream_seek_flv | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 10 | - | 168 | - |
| from_gnash/misc-ming.all | 1 | - | 5 | - |
| from_gnash/misc-swfc.all | 1 | - | 11 | - |
| from_shumway | 11 | - | 3 | - |
| from_shumway/avm1 | 2 | - | 2 | - |

**avm1 — newly passing:** `clip_event_propagation_order`, `default_names`, `focusrect_swf6`, `hittest_morph_input`, `key_isToggled`, `root_button_mode`, `selection_handlers`, `tab_ordering_events`, `tab_ordering_events_mouse`, `text_blocks_clicks`

**from_gnash/misc-ming.all — newly passing:** `place_and_remove_object_test`

**from_gnash/misc-swfc.all — newly passing:** `button_test1`

**from_shumway — newly passing:** `avm1/mouse-transparency`, `avm1/nested-button`, `button3`, `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da`, `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26`, `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0`, `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883`, `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732`, `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69`

**from_shumway/avm1 — newly passing:** `mouse-transparency`, `nested-button`

*Comparing `3589c6bcc859` → `ce31587cf186`*

## Per-Suite Details

### avm1

- **Pass:** 602/651 (92.5%)
- **Duration:** 10m42s across 30 shards
- **Lines:** 105,932/114,995 matching (92.1%)
- **Avg test duration:** 0.9s — slowest: `timeout` (30.6s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 2m58s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 0.9s — slowest: `Selection-v6` (1.9s)

### from_gnash/misc-ming.all

- **Pass:** 63/102 (61.8%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 3,120/4,577 matching (68.2%)
- **Avg test duration:** 1.0s — slowest: `matrix_test` (5.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `TextFieldTest` (1.1s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 14s across 30 shards
- **Lines:** 387/499 matching (77.6%)
- **Avg test duration:** 0.8s — slowest: `action_execution_order_test10` (1.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 16s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 0.8s — slowest: `zeroframe_definesprite` (1.4s)

### from_shumway

- **Pass:** 72/92 (78.3%)
- **Duration:** 1m18s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 0.8s — slowest: `timeline/timeline_as2_3` (1.0s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 39s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.8s — slowest: `bitmapdata/loadBitmap` (0.9s)
