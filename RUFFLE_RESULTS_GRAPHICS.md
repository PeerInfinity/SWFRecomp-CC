# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `ce10ee674ed6`  
**Date:** 2026-05-12 20:35 UTC  
**Total duration:** 2h41m58s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 651 | 92.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 102 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **945** | **1125** | **84.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,042 | 114,995 | 92.2% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,131 | 4,577 | 68.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **126,585** | **139,077** | **91.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 34 | - | 1 |
| from_gnash/actionscript.all | 1 | 4 | - |
| from_gnash/misc-ming.all | 13 | - | 2 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 2 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **66** | **4** | **3** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | 1 | - |
| from_gnash/actionscript.all | - | 1 | - | - |

**from_gnash/actionscript.all — newly failing:** `case-v5`

*Comparing `c0def42f9429` → `ce10ee674ed6`*

## Per-Suite Details

### avm1

- **Pass:** 605/651 (92.9%)
- **Duration:** 1h15m10s across 30 shards
- **Lines:** 106,042/114,995 matching (92.2%)
- **Avg test duration:** 6.9s — slowest: `netstream_play_flv_screen` (35.2s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 24m12s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 7.6s — slowest: `String-v8` (34.6s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 31m23s across 30 shards
- **Lines:** 3,131/4,577 matching (68.4%)
- **Avg test duration:** 18.4s — slowest: `matrix_test` (112.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.2s — slowest: `implementsOpTest` (21.2s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m46s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 17.8s — slowest: `movieclip_destruction_test4` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m44s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 19.1s — slowest: `jump_after_end` (20.9s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m47s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.2s — slowest: `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` (23.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m27s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.1s — slowest: `text-bind` (21.4s)
