# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `eb280b751d6b`  
**Date:** 2026-06-11 16:10 UTC  
**Total duration:** 1h45m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 609 | 678 | 89.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 132 | 243 | 54.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 66 | 110 | 60.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 8 | 19 | 42.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 73 | 92 | 79.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 46 | 47 | 97.9% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **960** | **1218** | **78.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 107,022 | 119,003 | 89.9% |
| from_gnash/actionscript.all | 29,839 | 38,791 | 76.9% |
| from_gnash/misc-ming.all | 4,019 | 5,239 | 76.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 557 | 76.1% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 882 | 1,276 | 69.1% |
| from_shumway/avm1 | 489 | 491 | 99.6% |
| **Total** | **142,979** | **165,683** | **86.3%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 58 |
| from_gnash/actionscript.all | 19 |
| from_gnash/misc-ming.all | 17 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 16 |
| from_shumway/avm1 | - |
| **Total** | **114** |

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
| avm1 | - | 7 | 1 | 371 |
| from_gnash/actionscript.all | - | 6 | - | - |
| from_gnash/misc-ming.all | - | 1 | - | - |

**avm1 — newly failing:** `call`, `path_string`, `property_invalid_base_clip`, `swf4_actions_coercion_order`, `tell_target`, `tell_target_invalid`, `tell_target_invalid_swf6`

*Comparing `2a090d60ddf3` → `eb280b751d6b`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 609/678 (89.8%)
- **Duration:** 46m03s across 30 shards
- **Lines:** 107,022/119,003 matching (89.9%)
- **Avg test duration:** 4.0s — slowest: `hittest_morph_input` (29.7s)

### from_gnash/actionscript.all

- **Pass:** 132/243 (54.3%)
- **Duration:** 21m55s across 30 shards
- **Lines:** 29,839/38,791 matching (76.9%)
- **Avg test duration:** 5.4s — slowest: `MovieClip-v8` (68.5s)

### from_gnash/misc-ming.all

- **Pass:** 66/110 (60.0%)
- **Duration:** 19m15s across 30 shards
- **Lines:** 4,019/5,239 matching (76.7%)
- **Avg test duration:** 10.4s — slowest: `NetStream-SquareTest` (31.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 9.4s — slowest: `function_test` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 8/19 (42.1%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 424/557 matching (76.1%)
- **Avg test duration:** 10.1s — slowest: `submoviegetvar` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m39s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 10.9s — slowest: `dict_cross` (20.8s)

### from_shumway

- **Pass:** 73/92 (79.3%)
- **Duration:** 8m39s across 30 shards
- **Lines:** 882/1,276 matching (69.1%)
- **Avg test duration:** 5.6s — slowest: `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` (22.3s)

### from_shumway/avm1

- **Pass:** 46/47 (97.9%)
- **Duration:** 1m08s across 30 shards
- **Lines:** 489/491 matching (99.6%)
- **Avg test duration:** 1.4s — slowest: `duplicateMovieClip/dontremove` (21.7s)
