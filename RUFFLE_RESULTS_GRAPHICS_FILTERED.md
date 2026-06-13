# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `716d0f7787b7`  
**Date:** 2026-06-13 03:47 UTC  
**Total duration:** 2h31m08s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 617 | 643 | 96.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 132 | 237 | 55.7% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 65 | 108 | 60.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 9 | 17 | 52.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **966** | **1154** | **83.7%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 102,885 | 106,690 | 96.4% |
| from_gnash/actionscript.all | 29,630 | 31,918 | 92.8% |
| from_gnash/misc-ming.all | 4,007 | 5,179 | 77.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 411 | 532 | 77.3% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **138,338** | **145,762** | **94.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 17 | 9 |
| from_gnash/actionscript.all | 10 | 95 |
| from_gnash/misc-ming.all | 15 | 28 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 3 | 5 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **45** | **143** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm1 | set_target_2_swf6 | 92% |
| avm1 | set_target_2_swf7 | 92% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Per-Suite Details

### avm1

- **Pass:** 617/643 (96.0%)
- **Ignored:** 41 tests
- **Duration:** 1h11m53s across 30 shards
- **Lines:** 102,885/106,690 matching (96.4%)
- **Avg test duration:** 6.3s — slowest: `clone_sprite_edittext_dynamic` (44.2s)

### from_gnash/actionscript.all

- **Pass:** 132/237 (55.7%)
- **Ignored:** 6 tests
- **Duration:** 19m27s across 30 shards
- **Lines:** 29,630/31,918 matching (92.8%)
- **Avg test duration:** 4.7s — slowest: `Transform-v8` (21.9s)

### from_gnash/misc-ming.all

- **Pass:** 65/108 (60.2%)
- **Ignored:** 2 tests
- **Duration:** 29m43s across 30 shards
- **Lines:** 4,007/5,179 matching (77.4%)
- **Avg test duration:** 16.1s — slowest: `loop/simple_loop_test` (27.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m21s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.7s — slowest: `hello` (21.0s)

### from_gnash/misc-swfc.all

- **Pass:** 9/17 (52.9%)
- **Ignored:** 2 tests
- **Duration:** 4m45s across 30 shards
- **Lines:** 411/532 matching (77.3%)
- **Avg test duration:** 14.4s — slowest: `movieclip_destruction_test4` (21.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 6m22s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 19.1s — slowest: `background` (22.4s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 14m22s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.4s — slowest: `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` (23.5s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 2m11s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.9s — slowest: `label` (19.7s)
