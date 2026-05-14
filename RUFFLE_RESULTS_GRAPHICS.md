# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `50f5aa00c13c`  
**Date:** 2026-05-14 03:41 UTC  
**Total duration:** 2h44m26s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 605 | 654 | 92.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 124 | 190 | 65.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 65 | 102 | 63.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 16 | 50.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **945** | **1128** | **83.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,295 | 115,583 | 92.0% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,131 | 4,577 | 68.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 388 | 499 | 77.8% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **126,838** | **139,665** | **90.8%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 36 | - | 2 |
| from_gnash/actionscript.all | 1 | 4 | - |
| from_gnash/misc-ming.all | 13 | - | 2 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 2 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **68** | **4** | **4** |

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
| from_gnash/actionscript.all | - | 1 | - | - |

**from_gnash/actionscript.all — newly failing:** `case-v5`

*Comparing `2f1a3c582522` → `50f5aa00c13c`*

## Per-Suite Details

### avm1

- **Pass:** 605/654 (92.5%)
- **Duration:** 1h16m52s across 30 shards
- **Lines:** 106,295/115,583 matching (92.0%)
- **Avg test duration:** 7.0s — slowest: `netstream_play_flv_screen` (36.2s)

### from_gnash/actionscript.all

- **Pass:** 124/190 (65.3%)
- **Duration:** 24m09s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 7.6s — slowest: `String-v8` (35.6s)

### from_gnash/misc-ming.all

- **Pass:** 65/102 (63.7%)
- **Duration:** 31m28s across 30 shards
- **Lines:** 3,131/4,577 matching (68.4%)
- **Avg test duration:** 18.4s — slowest: `matrix_test` (94.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m28s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 16.4s — slowest: `implementsOpTest` (21.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/16 (50.0%)
- **Duration:** 4m49s across 30 shards
- **Lines:** 388/499 matching (77.8%)
- **Avg test duration:** 18.1s — slowest: `swf4opcode` (21.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m55s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 19.7s — slowest: `background` (23.5s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m52s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 10.3s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (22.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m50s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.6s — slowest: `hitarea` (21.9s)
