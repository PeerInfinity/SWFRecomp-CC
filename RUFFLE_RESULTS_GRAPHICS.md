# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `3589c6bcc859`  
**Date:** 2026-05-11 19:20 UTC  
**Total duration:** 48m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 592 | 651 | 90.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 62 | 102 | 60.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **917** | **1125** | **81.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,764 | 114,995 | 92.0% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,115 | 4,577 | 68.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 376 | 499 | 75.4% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 879 | 1,276 | 68.9% |
| from_shumway/avm1 | 487 | 491 | 99.2% |
| **Total** | **126,274** | **139,077** | **90.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 45 | - | 2 | 1 |
| from_gnash/actionscript.all | 1 | 3 | - | - |
| from_gnash/misc-ming.all | 16 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | - | - | - |
| from_gnash/misc-swfc.all | 3 | - | - | - |
| from_gnash/misc-swfmill.all | - | - | - | - |
| from_shumway | 28 | - | - | - |
| from_shumway/avm1 | 2 | - | - | - |
| **Total** | **95** | **3** | **4** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | netstream_seek_flv | 100% |
| from_shumway | fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da | 100% |
| from_shumway | fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_shumway | fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883 | 100% |
| from_shumway | fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732 | 100% |
| from_shumway | fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69 | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | sound | 99% |
| avm1 | date | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_shumway | fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822 | 96% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-swfc.all | sound | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 3 | - | 15 | 105 |
| from_gnash/misc-ming.all | 7 | - | 61 | 35 |
| from_shumway | - | - | 106 | - |

**avm1 — newly passing:** `click_block`, `goto_frame2`, `removed_clip_halts_script`

**from_gnash/misc-ming.all — newly passing:** `ResolveEventsTest`, `action_order/action_execution_order_test8-v5`, `action_order/action_execution_order_test8-v6`, `get_frame_number_test`, `goto_frame_test`

**from_shumway — newly passing:** `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0`, `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca`

*Comparing `65b80680126b` → `3589c6bcc859`*

## Per-Suite Details

### avm1

- **Pass:** 592/651 (90.9%)
- **Duration:** 27m12s across 30 shards
- **Lines:** 105,764/114,995 matching (92.0%)
- **Avg test duration:** 2.4s — slowest: `timeout` (30.6s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 5m41s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 1.7s — slowest: `Sound-v5` (19.4s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 6m30s across 30 shards
- **Lines:** 3,115/4,577 matching (68.1%)
- **Avg test duration:** 3.8s — slowest: `loop/loop_test` (19.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 2.8s — slowest: `hello` (18.5s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 376/499 matching (75.4%)
- **Avg test duration:** 6.3s — slowest: `registerclass_test3` (19.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 7.7s — slowest: `zeroframe_definesprite` (19.1s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 3m23s across 30 shards
- **Lines:** 879/1,276 matching (68.9%)
- **Avg test duration:** 2.2s — slowest: `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` (19.3s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 57s across 30 shards
- **Lines:** 487/491 matching (99.2%)
- **Avg test duration:** 1.2s — slowest: `label` (18.6s)
