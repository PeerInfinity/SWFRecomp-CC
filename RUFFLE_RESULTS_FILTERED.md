# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `eb8206f8aa08`  
**Date:** 2026-05-15 02:10 UTC  
**Total duration:** 2h48m49s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 613 | 98.2% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 127 | 243 | 52.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 66 | 108 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 8 | 18 | 44.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 18 | 20 | 90.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **946** | **1132** | **83.6%** | |

*62 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 96,046 | 96,454 | 99.6% |
| from_gnash/actionscript.all | 27,666 | 38,787 | 71.3% |
| from_gnash/misc-ming.all | 4,031 | 5,179 | 77.8% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 405 | 550 | 73.6% |
| from_gnash/misc-swfmill.all | 87 | 95 | 91.6% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **129,547** | **142,413** | **91.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | 5 | 6 |
| from_gnash/actionscript.all | 46 | 70 |
| from_gnash/misc-ming.all | 18 | 24 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 4 | 6 |
| from_gnash/misc-swfmill.all | 1 | 1 |
| from_shumway | - | 3 |
| from_shumway/avm1 | - | - |
| **Total** | **74** | **112** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | Date-v7 | 98% |
| from_gnash/actionscript.all | Date-v8 | 98% |
| from_gnash/actionscript.all | Date-v6 | 97% |
| from_gnash/actionscript.all | Date-v5 | 97% |
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
| from_gnash/actionscript.all | MovieClip-v7 | 82% |
| from_gnash/actionscript.all | MovieClip-v8 | 81% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 602/613 (98.2%)
- **Ignored:** 41 tests
- **Duration:** 1h09m30s across 30 shards
- **Lines:** 96,046/96,454 matching (99.6%)
- **Avg test duration:** 6.3s — slowest: `register_class` (26.1s)

### from_gnash/actionscript.all

- **Pass:** 127/243 (52.3%)
- **Duration:** 35m00s across 30 shards
- **Lines:** 27,666/38,787 matching (71.3%)
- **Avg test duration:** 8.6s — slowest: `MovieClip-v8` (66.2s)

### from_gnash/misc-ming.all

- **Pass:** 66/108 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 33m13s across 30 shards
- **Lines:** 4,031/5,179 matching (77.8%)
- **Avg test duration:** 18.0s — slowest: `matrix_test` (98.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m21s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 15.6s — slowest: `hello` (19.8s)

### from_gnash/misc-swfc.all

- **Pass:** 8/18 (44.4%)
- **Ignored:** 1 tests
- **Duration:** 5m03s across 30 shards
- **Lines:** 405/550 matching (73.6%)
- **Avg test duration:** 15.8s — slowest: `mouse_drag_test` (21.6s)

### from_gnash/misc-swfmill.all

- **Pass:** 18/20 (90.0%)
- **Duration:** 6m17s across 30 shards
- **Lines:** 87/95 matching (91.6%)
- **Avg test duration:** 18.8s — slowest: `initaction_in_definesprite` (22.1s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 15m01s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 7.7s — slowest: `avm1/moviecliploader` (22.6s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 2m20s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.6s — slowest: `loadvariables/loadvars` (18.8s)
