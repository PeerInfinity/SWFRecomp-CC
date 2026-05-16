# Ruffle Test Results (Graphics)

*See [RUFFLE_RESULTS_GRAPHICS_FILTERED.md](RUFFLE_RESULTS_GRAPHICS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `ef6584787e7e`  
**Date:** 2026-05-16 20:55 UTC  
**Total duration:** 2h37m43s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 601 | 655 | 91.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics.md) |
| from_gnash/actionscript.all | 127 | 243 | 52.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics.md) |
| from_gnash/misc-ming.all | 63 | 110 | 57.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics.md) |
| **Total** | **944** | **1195** | **79.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,142 | 115,434 | 92.0% |
| from_gnash/actionscript.all | 27,714 | 38,787 | 71.5% |
| from_gnash/misc-ming.all | 3,336 | 5,239 | 63.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 412 | 557 | 74.0% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **139,279** | **162,110** | **85.9%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault |
|-------|-----------------:|---------------:|------------------:|
| avm1 | 38 | 3 | 2 |
| from_gnash/actionscript.all | 40 | 3 | - |
| from_gnash/misc-ming.all | 23 | - | 2 |
| from_gnash/misc-mtasc.all | - | - | - |
| from_gnash/misc-swfc.all | 5 | - | - |
| from_gnash/misc-swfmill.all | - | - | - |
| from_shumway | 16 | - | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **122** | **6** | **4** |

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
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | Object-v7 | 90% |
| from_gnash/actionscript.all | Object-v8 | 90% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Object-v6 | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 3 | - | - |
| from_gnash/actionscript.all | 9 | 3 | 62 | 14 |
| from_gnash/misc-ming.all | 1 | - | 4 | 12 |
| from_gnash/misc-swfmill.all | 1 | - | 6 | - |

**avm1 — newly failing:** `action_to_integer`, `as2_super_and_this_v8`, `as2_super_via_manual_prototype`

**from_gnash/actionscript.all — newly passing:** `flash-v8`

**from_gnash/misc-ming.all — newly passing:** `action_order/action_execution_order_test`

**from_gnash/misc-swfmill.all — newly passing:** `registers`

*Comparing `45164a5b0854` → `ef6584787e7e`*

## Per-Suite Details

### avm1

- **Pass:** 601/655 (91.8%)
- **Duration:** 1h11m26s across 30 shards
- **Lines:** 106,142/115,434 matching (92.0%)
- **Avg test duration:** 6.5s — slowest: `movieclip_hittest` (43.7s)

### from_gnash/actionscript.all

- **Pass:** 127/243 (52.3%)
- **Duration:** 24m26s across 30 shards
- **Lines:** 27,714/38,787 matching (71.5%)
- **Avg test duration:** 6.0s — slowest: `MovieClip-v8` (68.6s)

### from_gnash/misc-ming.all

- **Pass:** 63/110 (57.3%)
- **Duration:** 30m56s across 30 shards
- **Lines:** 3,336/5,239 matching (63.7%)
- **Avg test duration:** 16.8s — slowest: `matrix_test` (108.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.4s — slowest: `TextFieldTest` (19.0s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 4m49s across 30 shards
- **Lines:** 412/557 matching (74.0%)
- **Avg test duration:** 15.2s — slowest: `movieclip_destruction_test4` (20.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m15s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.7s — slowest: `background` (20.6s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m14s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.9s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (22.4s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m24s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 3.0s — slowest: `text-bind` (21.9s)
