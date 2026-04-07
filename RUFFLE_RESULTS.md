# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `37a9f630eea8`  
**Date:** 2026-04-07 21:46 UTC  
**Total duration:** 5h26m36s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 579 | 620 | 93.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 76 | 190 | 40.0% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 9 | 58 | 15.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **713** | **977** | **73.0%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 82,651 | 91,594 | 90.2% |
| from_gnash/actionscript.all | 12,534 | 16,957 | 73.9% |
| from_gnash/misc-ming.all | 1,665 | 3,388 | 49.1% |
| from_gnash/misc-mtasc.all | 173 | 231 | 74.9% |
| from_gnash/misc-swfc.all | 223 | 499 | 44.7% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **97,424** | **113,265** | **86.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 41 | - |
| from_gnash/actionscript.all | 114 | - |
| from_gnash/misc-ming.all | 49 | - |
| from_gnash/misc-mtasc.all | 2 | - |
| from_gnash/misc-swfc.all | 13 | 1 |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | 30 | - |
| from_shumway/avm1 | 10 | 1 |
| **Total** | **262** | **2** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| from_gnash/actionscript.all | Math-v7 | 98% |
| from_gnash/actionscript.all | Math-v8 | 98% |
| avm1 | mcl_replace_root_swf7_to_swf5 | 98% |
| avm1 | mcl_replace_root_swf7_to_swf6 | 98% |
| from_gnash/actionscript.all | Math-v5 | 98% |
| from_gnash/actionscript.all | Math-v6 | 98% |
| from_gnash/actionscript.all | Inheritance-v8 | 98% |
| from_gnash/actionscript.all | Color-v6 | 98% |
| avm1 | movieclip_library_state_values | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| from_gnash/actionscript.all | ops-v8 | 97% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| avm1 | native_objects_swf6 | 90% |
| avm1 | native_objects_swf7 | 90% |
| from_gnash/actionscript.all | Selection-v6 | 90% |
| avm1 | native_objects_swf8 | 89% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | Error-v6 | 87% |
| from_gnash/actionscript.all | Error-v7 | 87% |
| from_gnash/actionscript.all | Error-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | LocalConnection-v6 | 86% |
| from_gnash/actionscript.all | LocalConnection-v7 | 86% |
| from_gnash/actionscript.all | LocalConnection-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | Error-v5 | 86% |
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

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | 2 | - | 746 | - |

**avm1 — newly passing:** `sound_id3`, `sound_id3_prop`

*Comparing `81f9ea28cc82` → `37a9f630eea8`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 579/620 (93.4%)
- **Duration:** 3h20m40s across 30 shards
- **Lines:** 82,651/91,594 matching (90.2%)
- **Avg test duration:** 19.4s — slowest: `movieclip_invalid_get_bounds_6` (44.2s)

### from_gnash/actionscript.all

- **Pass:** 76/190 (40.0%)
- **Duration:** 1h10m23s across 30 shards
- **Lines:** 12,534/16,957 matching (73.9%)
- **Avg test duration:** 22.2s — slowest: `array-v5` (47.6s)

### from_gnash/misc-ming.all

- **Pass:** 9/58 (15.5%)
- **Duration:** 20m40s across 30 shards
- **Lines:** 1,665/3,388 matching (49.1%)
- **Avg test duration:** 21.3s — slowest: `matrix_test` (67.5s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m57s across 30 shards
- **Lines:** 173/231 matching (74.9%)
- **Avg test duration:** 19.7s — slowest: `levels` (20.6s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m13s across 30 shards
- **Lines:** 223/499 matching (44.7%)
- **Avg test duration:** 19.5s — slowest: `opcode_guard_test2` (20.9s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m25s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 18.9s — slowest: `tags_after_last_showframe` (19.7s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 14m57s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 19.0s — slowest: `lzma_bytes` (20.8s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m18s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 19.0s — slowest: `watch` (22.1s)
