# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `42774a946a7e`  
**Date:** 2026-05-23 18:44 UTC  
**Total duration:** 12m49s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 608 | 661 | 92.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 128 | 243 | 52.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 65 | 110 | 59.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **954** | **1201** | **79.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,702 | 115,804 | 92.1% |
| from_gnash/actionscript.all | 29,383 | 38,787 | 75.8% |
| from_gnash/misc-ming.all | 4,010 | 5,239 | 76.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,194** | **162,480** | **87.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 42 |
| from_gnash/actionscript.all | 19 |
| from_gnash/misc-ming.all | 18 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
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
| avm1 | movieclip_hittest_shapeflag | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | getvariable-v7 | 95% |
| from_gnash/actionscript.all | getvariable-v8 | 95% |
| from_gnash/actionscript.all | getvariable-v5 | 95% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | Sound-v6 | 92% |
| from_gnash/actionscript.all | Sound-v7 | 92% |
| from_gnash/actionscript.all | Sound-v8 | 92% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/actionscript.all | MovieClip-v6 | 87% |
| from_gnash/actionscript.all | MovieClip-v7 | 86% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | MovieClip-v8 | 85% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| from_gnash/actionscript.all | TextField-v6 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 4 | - | 37 | 19 |
| from_gnash/actionscript.all | - | 3 | 12 | - |
| from_gnash/misc-ming.all | - | - | 6 | - |

**avm1 — newly passing:** `sound_getters`, `sound_nested_clips`, `sound_owner_reference`, `sound_start_stop`

*Comparing `d2da911ca124` → `42774a946a7e`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 608/661 (92.0%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 106,702/115,804 matching (92.1%)
- **Avg test duration:** 0.5s — slowest: `bitmap_data_copypixels` (19.2s)

### from_gnash/actionscript.all

- **Pass:** 128/243 (52.7%)
- **Duration:** 3m00s across 30 shards
- **Lines:** 29,383/38,787 matching (75.8%)
- **Avg test duration:** 0.7s — slowest: `TextSnapshot-v5` (19.3s)

### from_gnash/misc-ming.all

- **Pass:** 65/110 (59.1%)
- **Duration:** 1m24s across 30 shards
- **Lines:** 4,010/5,239 matching (76.5%)
- **Avg test duration:** 0.7s — slowest: `EmbeddedFontTest` (19.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 21s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 2.3s — slowest: `exception` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 0.2s — slowest: `button_test1` (0.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 24s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 1.1s — slowest: `dict_callframe` (18.9s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 1m21s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 0.8s — slowest: `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` (18.7s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 12s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 0.2s — slowest: `xml/xmlbuild` (0.6s)
