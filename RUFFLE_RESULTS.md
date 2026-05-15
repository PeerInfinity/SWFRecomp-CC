# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `eb8206f8aa08`  
**Date:** 2026-05-15 02:10 UTC  
**Total duration:** 2h48m49s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 604 | 654 | 92.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 127 | 243 | 52.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 66 | 110 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 18 | 20 | 90.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **949** | **1194** | **79.5%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,466 | 115,583 | 92.1% |
| from_gnash/actionscript.all | 27,666 | 38,787 | 71.3% |
| from_gnash/misc-ming.all | 4,049 | 5,239 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 412 | 557 | 74.0% |
| from_gnash/misc-swfmill.all | 87 | 95 | 91.6% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **140,262** | **162,259** | **86.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 39 |
| from_gnash/actionscript.all | 46 |
| from_gnash/misc-ming.all | 20 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 5 |
| from_gnash/misc-swfmill.all | 1 |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **127** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| from_gnash/actionscript.all | Date-v7 | 98% |
| from_gnash/actionscript.all | Date-v8 | 98% |
| avm1 | movieclip_hittest_shapeflag | 98% |
| from_gnash/actionscript.all | Date-v6 | 97% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| from_gnash/actionscript.all | Date-v5 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | Object-v5 | 93% |
| from_gnash/actionscript.all | array-v7 | 89% |
| from_gnash/actionscript.all | array-v8 | 89% |
| from_gnash/actionscript.all | flash-v8 | 88% |
| from_gnash/actionscript.all | Object-v7 | 88% |
| from_gnash/actionscript.all | Object-v8 | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/actionscript.all | Function-v5 | 85% |
| from_gnash/actionscript.all | Stage-v6 | 84% |
| from_gnash/actionscript.all | Stage-v7 | 84% |
| from_gnash/actionscript.all | Stage-v8 | 84% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test | 84% |
| from_gnash/actionscript.all | XMLNode-v5 | 84% |
| from_gnash/actionscript.all | XMLNode-v6 | 84% |
| from_gnash/actionscript.all | XMLNode-v7 | 84% |
| from_gnash/actionscript.all | XMLNode-v8 | 84% |
| from_gnash/actionscript.all | Object-v6 | 84% |
| from_gnash/misc-swfmill.all | registers | 83% |
| from_gnash/actionscript.all | MovieClip-v6 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 6 |
| from_gnash/misc-ming.all | - | 1 | 37 | 14 |

**avm1 — newly failing:** `placeobject_occupied_depth`

*Comparing `b20ee46207a4` → `eb8206f8aa08`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 604/654 (92.4%)
- **Duration:** 1h09m30s across 30 shards
- **Lines:** 106,466/115,583 matching (92.1%)
- **Avg test duration:** 6.3s — slowest: `netstream_play_flv_screen` (33.6s)

### from_gnash/actionscript.all

- **Pass:** 127/243 (52.3%)
- **Duration:** 35m00s across 30 shards
- **Lines:** 27,666/38,787 matching (71.3%)
- **Avg test duration:** 8.6s — slowest: `MovieClip-v8` (66.2s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 33m13s across 30 shards
- **Lines:** 4,049/5,239 matching (77.3%)
- **Avg test duration:** 18.1s — slowest: `matrix_test` (98.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m21s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.6s — slowest: `hello` (19.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 5m03s across 30 shards
- **Lines:** 412/557 matching (74.0%)
- **Avg test duration:** 15.9s — slowest: `mouse_drag_test` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/20 (90.0%)
- **Duration:** 6m17s across 30 shards
- **Lines:** 87/95 matching (91.6%)
- **Avg test duration:** 18.8s — slowest: `initaction_in_definesprite` (22.1s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 15m01s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 9.7s — slowest: `avm1/moviecliploader` (22.6s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 2m20s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 2.9s — slowest: `hitarea` (21.8s)
