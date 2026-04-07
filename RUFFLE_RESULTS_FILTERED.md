# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `81f9ea28cc82`  
**Date:** 2026-04-07 20:00 UTC  
**Total duration:** 5h27m21s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 564 | 567 | 99.5% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 76 | 181 | 42.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 9 | 58 | 15.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 17 | 17 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **698** | **885** | **78.9%** | |

*92 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 71,278 | 71,311 | 99.95% |
| from_gnash/actionscript.all | 11,064 | 15,444 | 71.6% |
| from_gnash/misc-ming.all | 1,665 | 3,388 | 49.1% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 223 | 499 | 44.7% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 35 | 100% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **84,581** | **91,248** | **92.7%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 3 | - |
| from_gnash/actionscript.all | 105 | - |
| from_gnash/misc-ming.all | 49 | - |
| from_gnash/misc-mtasc.all | 2 | - |
| from_gnash/misc-swfc.all | 13 | 1 |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | - | - |
| from_shumway/avm1 | 10 | 1 |
| **Total** | **185** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/actionscript.all | Inheritance-v8 | 98% |
| from_gnash/actionscript.all | Color-v6 | 98% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| avm1 | native_objects_swf7 | 90% |
| from_gnash/actionscript.all | Selection-v6 | 90% |
| avm1 | native_objects_swf8 | 89% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | LocalConnection-v6 | 86% |
| from_gnash/actionscript.all | LocalConnection-v7 | 86% |
| from_gnash/actionscript.all | LocalConnection-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 85% |
| from_gnash/actionscript.all | Inheritance-v5 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_shumway/avm1 | nativeinheritance | 83% |
| from_gnash/actionscript.all | System-v7 | 83% |
| from_gnash/actionscript.all | System-v8 | 83% |
| from_gnash/actionscript.all | System-v6 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | Number-v7 | 81% |
| from_gnash/actionscript.all | Number-v8 | 81% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/actionscript.all | array-v5 | 80% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 564/567 (99.5%)
- **Ignored:** 53 tests
- **Duration:** 3h21m17s across 30 shards
- **Lines:** 71,278/71,311 matching (99.95%)
- **Avg test duration:** 19.4s — slowest: `movieclip_invalid_get_bounds_7` (43.6s)

### from_gnash/actionscript.all

- **Pass:** 76/181 (42.0%)
- **Ignored:** 9 tests
- **Duration:** 1h10m11s across 30 shards
- **Lines:** 11,064/15,444 matching (71.6%)
- **Avg test duration:** 21.9s — slowest: `array-v5` (46.0s)

### from_gnash/misc-ming.all

- **Pass:** 9/58 (15.5%)
- **Duration:** 20m48s across 30 shards
- **Lines:** 1,665/3,388 matching (49.1%)
- **Avg test duration:** 21.5s — slowest: `matrix_test` (71.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m59s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 19.9s — slowest: `levels` (21.2s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m18s across 30 shards
- **Lines:** 223/499 matching (44.7%)
- **Avg test duration:** 19.8s — slowest: `edittext_test1` (21.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m25s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 18.9s — slowest: `tags_after_last_showframe` (19.5s)

### from_shumway

- **Pass:** 17/17 (100%)
- **Ignored:** 30 tests
- **Duration:** 14m58s across 30 shards
- **Lines:** 35/35 matching (100%)
- **Avg test duration:** 19.1s — slowest: `bitmapbuttons` (20.1s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m22s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 19.2s — slowest: `watch` (21.6s)
