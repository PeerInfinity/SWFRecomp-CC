# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `7e3a3a01481a`  
**Date:** 2026-07-11 13:16 UTC  
**Total duration:** 3h23m16s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 631 | 661 | 95.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| avm2 | 293 | 972 | 30.1% | [details](ruffle-tests/tests/swfs/avm2/_results/results_filtered.md) |
| from_gnash/actionscript.all | 132 | 236 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 68 | 109 | 62.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 11 | 18 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 19 | 20 | 95.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 73 | 76 | 96.1% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 44 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| regression | 41 | 41 | 100% | [details](ruffle-tests/tests/swfs/regression/_results/results_filtered.md) |
| **Total** | **1319** | **2186** | **60.3%** | |

*302 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 104,035 | 107,545 | 96.7% |
| avm2 | 39,242 | 124,452 | 31.5% |
| from_gnash/actionscript.all | 29,253 | 31,358 | 93.3% |
| from_gnash/misc-ming.all | 4,029 | 5,188 | 77.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 424 | 555 | 76.4% |
| from_gnash/misc-swfmill.all | 93 | 95 | 97.9% |
| from_shumway | 621 | 637 | 97.5% |
| from_shumway/avm1 | 480 | 480 | 100% |
| regression | 260 | 260 | 100% |
| **Total** | **178,648** | **270,801** | **66.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error |
|-------|-----------------:|----------------:|---------------:|
| avm1 | 18 | 12 | - |
| avm2 | 635 | - | 44 |
| from_gnash/actionscript.all | 9 | 95 | - |
| from_gnash/misc-ming.all | 13 | 28 | - |
| from_gnash/misc-mtasc.all | - | 2 | - |
| from_gnash/misc-swfc.all | 2 | 5 | - |
| from_gnash/misc-swfmill.all | - | 1 | - |
| from_shumway | - | 3 | - |
| from_shumway/avm1 | - | - | - |
| regression | - | - | - |
| **Total** | **677** | **146** | **44** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | load_cancel_via_removemovieclip | 100% |
| avm2 | place_object_same_depth_frame | 100% |
| avm2 | displayobject_rotation | 100% |
| avm2 | displayobject_alpha | 100% |
| avm2 | parse_int | 99% |
| avm2 | parse_float_swf10 | 98% |
| from_gnash/actionscript.all | array-v6 | 97% |
| from_gnash/actionscript.all | MovieClip-v7 | 96% |
| from_gnash/actionscript.all | MovieClip-v6 | 96% |
| from_gnash/actionscript.all | MovieClip-v8 | 94% |
| avm2 | error_tostring | 93% |
| avm1 | set_property_values/swf5 | 93% |
| avm1 | set_property_values/swf6 | 93% |
| avm1 | set_property_values/swf7 | 93% |
| avm2 | json_stringify | 93% |
| from_gnash/actionscript.all | array-v7 | 92% |
| from_gnash/actionscript.all | array-v8 | 92% |
| avm2 | unescape | 89% |
| avm2 | xml_has_property_via_in | 88% |
| avm2 | interactiveobject_enabled | 88% |
| from_gnash/misc-ming.all | DrawingApiTest | 87% |
| from_gnash/actionscript.all | TextField-v6 | 86% |
| avm2 | error_tostring_more | 84% |
| from_gnash/actionscript.all | TextField-v8 | 84% |
| from_gnash/actionscript.all | TextField-v7 | 83% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm2 | eventdispatcher_tostring | 80% |
| avm2 | issue_5292 | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 631/661 (95.5%)
- **Ignored:** 45 tests
- **Duration:** 49m53s across 30 shards
- **Lines:** 104,035/107,545 matching (96.7%)
- **Avg test duration:** 4.2s — slowest: `movieclip_invalid_get_bounds_6` (25.6s)

### avm2

- **Pass:** 293/972 (30.1%)
- **Ignored:** 227 tests
- **Duration:** 1h19m31s across 30 shards
- **Lines:** 39,242/124,452 matching (31.5%)
- **Avg test duration:** 3.2s — slowest: `bitmapdata_accuracy` (38.3s)

### from_gnash/actionscript.all

- **Pass:** 132/236 (55.9%)
- **Ignored:** 7 tests
- **Duration:** 26m05s across 30 shards
- **Lines:** 29,253/31,358 matching (93.3%)
- **Avg test duration:** 6.3s — slowest: `MovieClip-v8` (65.8s)

### from_gnash/misc-ming.all

- **Pass:** 68/109 (62.4%)
- **Ignored:** 2 tests
- **Duration:** 18m50s across 30 shards
- **Lines:** 4,029/5,188 matching (77.7%)
- **Avg test duration:** 10.1s — slowest: `matrix_test` (97.2s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m46s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.8s — slowest: `exception` (20.8s)

### from_gnash/misc-swfc.all

- **Pass:** 11/18 (61.1%)
- **Ignored:** 2 tests
- **Duration:** 4m11s across 30 shards
- **Lines:** 424/555 matching (76.4%)
- **Avg test duration:** 12.7s — slowest: `movieclip_destruction_test1` (21.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 19/20 (95.0%)
- **Duration:** 2m41s across 30 shards
- **Lines:** 93/95 matching (97.9%)
- **Avg test duration:** 8.0s — slowest: `registers` (20.6s)

### from_shumway

- **Pass:** 73/76 (96.1%)
- **Ignored:** 16 tests
- **Duration:** 13m47s across 30 shards
- **Lines:** 621/637 matching (97.5%)
- **Avg test duration:** 6.6s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (21.1s)

### from_shumway/avm1

- **Pass:** 44/44 (100%)
- **Ignored:** 3 tests
- **Duration:** 1m39s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 1.7s — slowest: `duplicateMovieClip/dontremove` (17.6s)

### regression

- **Pass:** 41/41 (100%)
- **Duration:** 4m48s across 30 shards
- **Lines:** 260/260 matching (100%)
- **Avg test duration:** 7.0s — slowest: `coerce_cross_swf_version` (20.2s)
