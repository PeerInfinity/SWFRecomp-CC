# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `bf47589e067e`  
**Date:** 2026-05-13 23:16 UTC  
**Total duration:** 2h51m16s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 654 | 92.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 102 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **946** | **1128** | **83.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,303 | 115,583 | 92.0% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,131 | 4,577 | 68.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **126,846** | **139,665** | **90.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 36 | - | 2 |
| from_gnash/actionscript.all | 1 | 3 | - |
| from_gnash/misc-ming.all | 13 | - | 2 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 2 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **68** | **3** | **4** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
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
| avm1 | 5 | - | - | 105 |

**avm1 — newly passing:** `button_children`, `button_order`, `button_v5`, `button_v6`, `nested_textfields_in_buttons`

*Comparing `fe491ef7b556` → `bf47589e067e`*

## Per-Suite Details

### avm1

- **Pass:** 605/654 (92.5%)
- **Duration:** 1h21m22s across 30 shards
- **Lines:** 106,303/115,583 matching (92.0%)
- **Avg test duration:** 7.4s — slowest: `netstream_play_flv_screen` (35.4s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 25m18s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 7.9s — slowest: `String-v8` (34.9s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 32m04s across 30 shards
- **Lines:** 3,131/4,577 matching (68.4%)
- **Avg test duration:** 18.8s — slowest: `matrix_test` (95.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m27s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.3s — slowest: `implementsOpTest` (21.4s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m51s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 18.1s — slowest: `movieclip_destruction_test1` (23.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m55s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 19.7s — slowest: `background` (21.1s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 16m17s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.6s — slowest: `avm1/text-bind` (22.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 3m00s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.8s — slowest: `text-bind` (20.1s)
