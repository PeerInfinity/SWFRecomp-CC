# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `192e8317bebd`  
**Date:** 2026-06-11 21:50 UTC  
**Total duration:** 21m39s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 618 | 678 | 91.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 66 | 110 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 9 | 19 | 47.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **973** | **1218** | **79.9%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 108,086 | 119,001 | 90.8% |
| from_gnash/actionscript.all | 29,983 | 38,791 | 77.3% |
| from_gnash/misc-ming.all | 4,028 | 5,239 | 76.9% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 428 | 557 | 76.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **144,200** | **165,681** | **87.0%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | runtime_segfault |
|-------|--------------:|-----------------:|------------------:|
| avm1 | 1 | 44 | 1 |
| from_gnash/actionscript.all | - | 13 | - |
| from_gnash/misc-ming.all | - | 16 | - |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | - | 4 | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | - | 16 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **93** | **1** |

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
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 1 | 1 | 3 | - |

**avm1 — newly passing:** `placeobject_all_event_flags`

**avm1 — newly failing:** `bad_placeobject_clipaction`

*Comparing `7da45e290085` → `192e8317bebd`*

## Per-Suite Details

### avm1

- **Pass:** 618/678 (91.2%)
- **Duration:** 12m37s across 30 shards
- **Lines:** 108,086/119,001 matching (90.8%)
- **Avg test duration:** 1.1s — slowest: `bad_placeobject_clipaction` (19.2s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 4m05s across 30 shards
- **Lines:** 29,983/38,791 matching (77.3%)
- **Avg test duration:** 0.9s — slowest: `MovieClip-v8` (2.4s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 4,028/5,239 matching (76.9%)
- **Avg test duration:** 1.1s — slowest: `matrix_test` (6.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 8s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 0.8s — slowest: `implementsOpTest` (1.2s)

### from_gnash/misc-swfc.all

- **Pass:** 9/19 (47.4%)
- **Duration:** 17s across 30 shards
- **Lines:** 428/557 matching (76.8%)
- **Avg test duration:** 0.8s — slowest: `edittext_test1` (0.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 17s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 0.8s — slowest: `missing_bitmap` (1.4s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 0.9s — slowest: `timeline/timeline_as2_5` (2.5s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 40s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.8s — slowest: `text-bind` (1.2s)
