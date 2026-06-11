# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `192e8317bebd`  
**Date:** 2026-06-11 21:24 UTC  
**Total duration:** 2h08m31s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 618 | 678 | 91.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 135 | 243 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 67 | 110 | 60.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 9 | 19 | 47.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **974** | **1218** | **80.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 108,122 | 119,001 | 90.9% |
| from_gnash/actionscript.all | 29,983 | 38,791 | 77.3% |
| from_gnash/misc-ming.all | 4,033 | 5,239 | 77.0% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 428 | 557 | 76.8% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **144,241** | **165,681** | **87.1%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | 1 | 45 |
| from_gnash/actionscript.all | - | 13 |
| from_gnash/misc-ming.all | - | 15 |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | - | 4 |
| from_gnash/misc-swfmill.all | - | - |
| from_shumway | - | 16 |
| from_shumway/avm1 | - | - |
| **Total** | **1** | **93** |

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

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 618/678 (91.2%)
- **Duration:** 57m52s across 30 shards
- **Lines:** 108,122/119,001 matching (90.9%)
- **Avg test duration:** 5.1s — slowest: `edittext_drag_select` (23.7s)

### from_gnash/actionscript.all

- **Pass:** 135/243 (55.6%)
- **Duration:** 16m08s across 30 shards
- **Lines:** 29,983/38,791 matching (77.3%)
- **Avg test duration:** 3.9s — slowest: `Inheritance-v5` (24.1s)

### from_gnash/misc-ming.all

- **Pass:** 67/110 (60.9%)
- **Duration:** 27m29s across 30 shards
- **Lines:** 4,033/5,239 matching (77.0%)
- **Avg test duration:** 14.9s — slowest: `ButtonEventsTest` (22.3s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.3s — slowest: `TextFieldTest` (20.4s)

### from_gnash/misc-swfc.all

- **Pass:** 9/19 (47.4%)
- **Duration:** 4m21s across 30 shards
- **Lines:** 428/557 matching (76.8%)
- **Avg test duration:** 13.7s — slowest: `mouse_drag_test` (20.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 5m49s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 17.4s — slowest: `afunc_dict` (20.8s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 13m03s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 8.5s — slowest: `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` (21.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m28s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.8s — slowest: `hitarea` (20.2s)
