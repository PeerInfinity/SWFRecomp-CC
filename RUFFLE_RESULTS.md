# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `921eeb06c40f`  
**Date:** 2026-05-29 20:41 UTC  
**Total duration:** 2h11m52s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 615 | 673 | 91.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 132 | 243 | 54.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 66 | 110 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 7 | 19 | 36.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **965** | **1213** | **79.6%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,900 | 116,485 | 91.8% |
| from_gnash/actionscript.all | 29,818 | 38,791 | 76.9% |
| from_gnash/misc-ming.all | 4,022 | 5,239 | 76.8% |
| from_gnash/misc-mtasc.all | 209 | 231 | 90.5% |
| from_gnash/misc-swfc.all | 421 | 557 | 75.6% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,834** | **163,165** | **87.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 47 |
| from_gnash/actionscript.all | 14 |
| from_gnash/misc-ming.all | 16 |
| from_gnash/misc-mtasc.all | 1 |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **99** |

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
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| from_gnash/actionscript.all | MovieClip-v5 | 92% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/misc-swfc.all | button_test1 | 90% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | TextField-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| from_gnash/actionscript.all | TextField-v7 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 1 |
| from_gnash/actionscript.all | 3 | 1 | 12 | 21 |
| from_gnash/misc-mtasc.all | - | 1 | - | 2 |
| from_gnash/misc-swfc.all | - | 1 | - | 3 |

**avm1 — newly failing:** `stage_object_children`

**from_gnash/actionscript.all — newly passing:** `getvariable-v5`, `getvariable-v6`, `getvariable-v7`, `getvariable-v8`

**from_gnash/misc-swfc.all — newly failing:** `button_test1`

*Comparing `15eef2ba9087` → `921eeb06c40f`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 615/673 (91.4%)
- **Duration:** 1h00m06s across 30 shards
- **Lines:** 106,900/116,485 matching (91.8%)
- **Avg test duration:** 5.3s — slowest: `movieclip_hittest_shapeflag` (22.4s)

### from_gnash/actionscript.all

- **Pass:** 132/243 (54.3%)
- **Duration:** 16m21s across 30 shards
- **Lines:** 29,818/38,791 matching (76.9%)
- **Avg test duration:** 4.0s — slowest: `Stage-v6` (20.8s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 27m33s across 30 shards
- **Lines:** 4,022/5,239 matching (76.8%)
- **Avg test duration:** 15.0s — slowest: `matrix_test` (22.9s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m04s across 30 shards
- **Lines:** 209/231 matching (90.5%)
- **Avg test duration:** 13.7s — slowest: `TextFieldTest` (20.2s)

### from_gnash/misc-swfc.all

- **Pass:** 7/19 (36.8%)
- **Duration:** 4m36s across 30 shards
- **Lines:** 421/557 matching (75.6%)
- **Avg test duration:** 14.5s — slowest: `submoviegetvar` (19.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m03s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.1s — slowest: `trace-as2/super` (20.1s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m45s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.9s — slowest: `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` (20.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.7s — slowest: `text-bind` (18.9s)
