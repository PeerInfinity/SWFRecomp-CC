# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `13fe9441a428`  
**Date:** 2026-05-20 03:45 UTC  
**Total duration:** 2h10m06s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 603 | 661 | 91.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 132 | 243 | 54.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 7 | 19 | 36.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **952** | **1201** | **79.3%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,624 | 115,804 | 92.1% |
| from_gnash/actionscript.all | 27,915 | 38,787 | 72.0% |
| from_gnash/misc-ming.all | 3,999 | 5,239 | 76.3% |
| from_gnash/misc-mtasc.all | 209 | 231 | 90.5% |
| from_gnash/misc-swfc.all | 421 | 557 | 75.6% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **140,632** | **162,480** | **86.6%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 47 |
| from_gnash/actionscript.all | 35 |
| from_gnash/misc-ming.all | 20 |
| from_gnash/misc-mtasc.all | 1 |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **124** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | stage_object_children | 99% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/misc-swfc.all | button_test1 | 90% |
| from_gnash/actionscript.all | Object-v7 | 90% |
| from_gnash/actionscript.all | Object-v8 | 90% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Object-v6 | 86% |
| from_gnash/actionscript.all | MovieClip-v5 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | Transform-v8 | 85% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| avm1 | sound_getters | 84% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 1 |
| from_gnash/actionscript.all | 4 | 1 | 23 | 18 |
| from_gnash/misc-ming.all | - | 1 | - | 4 |
| from_gnash/misc-mtasc.all | - | 1 | - | 2 |
| from_gnash/misc-swfc.all | - | 1 | - | 3 |

**avm1 — newly failing:** `stage_object_children`

**from_gnash/actionscript.all — newly passing:** `getvariable-v5`, `getvariable-v6`, `getvariable-v7`, `getvariable-v8`

**from_gnash/misc-swfc.all — newly failing:** `button_test1`

*Comparing `747c91f86fe7` → `13fe9441a428`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 603/661 (91.2%)
- **Duration:** 58m29s across 30 shards
- **Lines:** 106,624/115,804 matching (92.1%)
- **Avg test duration:** 5.2s — slowest: `edittext_autosize_setter` (23.4s)

### from_gnash/actionscript.all

- **Pass:** 132/243 (54.3%)
- **Duration:** 16m11s across 30 shards
- **Lines:** 27,915/38,787 matching (72.0%)
- **Avg test duration:** 3.9s — slowest: `argstest-v6` (19.8s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 27m20s across 30 shards
- **Lines:** 3,999/5,239 matching (76.3%)
- **Avg test duration:** 14.9s — slowest: `matrix_test` (22.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m09s across 30 shards
- **Lines:** 209/231 matching (90.5%)
- **Avg test duration:** 14.4s — slowest: `enum` (18.7s)

### from_gnash/misc-swfc.all

- **Pass:** 7/19 (36.8%)
- **Duration:** 4m37s across 30 shards
- **Lines:** 421/557 matching (75.6%)
- **Avg test duration:** 14.5s — slowest: `edittext_test1` (19.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m07s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.3s — slowest: `background` (19.2s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m40s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.9s — slowest: `avm1/mouse-transparency` (19.9s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m30s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.9s — slowest: `hitarea` (19.8s)
