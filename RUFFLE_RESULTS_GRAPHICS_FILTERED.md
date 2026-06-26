# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `769d0a02274f`  
**Date:** 2026-06-26 21:31 UTC  
**Total duration:** 3h08m56s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 627 | 661 | 94.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 109 | 59.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 10 | 18 | 55.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **977** | **1173** | **83.3%** | |

*73 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,044 | 111,695 | 94.0% |
| from_gnash/actionscript.all | 29,196 | 31,358 | 93.1% |
| from_gnash/misc-ming.all | 4,007 | 5,179 | 77.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 418 | 555 | 75.3% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **140,070** | **150,230** | **93.2%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | timeout |
|-------|-----------------:|----------------:|---------:|
| avm1 | 22 | 12 | - |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 15 | 28 | 1 |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 3 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| **Total** | **49** | **146** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | watch_recursion_swf7 | 99% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 95% |
| from_gnash/actionscript.all | MovieClip-v6 | 95% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 92% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 85% |
| avm1 | bitmapdata_hittest_threshold | 83% |
| from_gnash/actionscript.all | TextField-v8 | 83% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 627/661 (94.9%)
- **Ignored:** 43 tests
- **Duration:** 1h22m06s across 30 shards
- **Lines:** 105,044/111,695 matching (94.0%)
- **Avg test duration:** 6.9s — slowest: `device_font_spacing` (31.9s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 35m34s across 30 shards
- **Lines:** 29,196/31,358 matching (93.1%)
- **Avg test duration:** 8.7s — slowest: `MovieClip-v8` (68.2s)

### from_gnash/misc-ming.all

- **Pass:** 65/109 (59.6%)
- **Ignored:** 2 tests
- **Duration:** 36m34s across 30 shards
- **Lines:** 4,007/5,179 matching (77.4%)
- **Avg test duration:** 19.6s — slowest: `matrix_test` (108.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.3s — slowest: `implementsOpTest` (22.0s)

### from_gnash/misc-swfc.all

- **Pass:** 10/18 (55.6%)
- **Ignored:** 2 tests
- **Duration:** 6m19s across 30 shards
- **Lines:** 418/555 matching (75.3%)
- **Avg test duration:** 19.6s — slowest: `soft_reference_test1` (22.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m01s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 18.0s — slowest: `background` (22.9s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 16m42s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 8.4s — slowest: `avm1/text-bind` (23.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 3m19s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 3.0s — slowest: `rollover` (21.0s)
