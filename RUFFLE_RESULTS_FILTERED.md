# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `eb280b751d6b`  
**Date:** 2026-06-11 16:10 UTC  
**Total duration:** 1h45m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 607 | 637 | 95.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 129 | 237 | 54.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 66 | 108 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 17 | 47.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **953** | **1148** | **83.0%** | |

*70 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,550 | 99,875 | 96.7% |
| from_gnash/actionscript.all | 29,486 | 31,918 | 92.4% |
| from_gnash/misc-ming.all | 4,005 | 5,179 | 77.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 407 | 532 | 76.5% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **131,853** | **138,947** | **94.9%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 24 | 6 |
| from_gnash/actionscript.all | 16 | 92 |
| from_gnash/misc-ming.all | 15 | 27 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 2 | 7 |
| from_gnash/misc-swfmill.all | - | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **57** | **138** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | array-v5 | 96% |
| from_gnash/actionscript.all | array-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v6 | 94% |
| from_gnash/actionscript.all | MovieClip-v7 | 93% |
| from_gnash/actionscript.all | MovieClip-v8 | 91% |
| from_gnash/actionscript.all | array-v7 | 90% |
| from_gnash/actionscript.all | array-v8 | 90% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 84% |
| from_gnash/actionscript.all | TextField-v8 | 82% |
| from_gnash/actionscript.all | TextField-v7 | 82% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 607/637 (95.3%)
- **Ignored:** 41 tests
- **Duration:** 46m03s across 30 shards
- **Lines:** 96,550/99,875 matching (96.7%)
- **Avg test duration:** 4.1s — slowest: `hittest_morph_input` (29.7s)

### from_gnash/actionscript.all

- **Pass:** 129/237 (54.4%)
- **Ignored:** 6 tests
- **Duration:** 21m55s across 30 shards
- **Lines:** 29,486/31,918 matching (92.4%)
- **Avg test duration:** 5.4s — slowest: `MovieClip-v8` (68.5s)

### from_gnash/misc-ming.all

- **Pass:** 66/108 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 19m15s across 30 shards
- **Lines:** 4,005/5,179 matching (77.3%)
- **Avg test duration:** 10.4s — slowest: `NetStream-SquareTest` (31.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m25s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 9.4s — slowest: `function_test` (20.9s)

### from_gnash/misc-swfc.all

- **Pass:** 8/17 (47.1%)
- **Ignored:** 2 tests
- **Duration:** 3m12s across 30 shards
- **Lines:** 407/532 matching (76.5%)
- **Avg test duration:** 8.9s — slowest: `submoviegetvar` (22.2s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 3m39s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 10.9s — slowest: `dict_cross` (20.8s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 8m39s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 4.8s — slowest: `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` (20.8s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m08s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.0s — slowest: `duplicateMovieClip/dontremove` (21.7s)
