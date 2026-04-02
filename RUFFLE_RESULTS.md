# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `b8938ab392b9`  
**Date:** 2026-04-02 20:20 UTC  
**Total duration:** 4h33m15s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 570 | 620 | 91.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 5 | 190 | 2.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **615** | **894** | **68.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 81,332 | 91,501 | 88.9% |
| from_gnash/actionscript.all | 1,726 | 16,957 | 10.2% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **83,236** | **109,054** | **76.3%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 48 | - | 1 | 1 |
| from_gnash/actionscript.all | 185 | - | - | - |
| from_gnash/misc-swfmill.all | 3 | - | - | - |
| from_shumway | 30 | - | - | - |
| from_shumway/avm1 | 10 | 1 | - | - |
| **Total** | **276** | **1** | **1** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | date | 99% |
| avm1 | bitmap_filters | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | mcl_replace_root_swf7_to_swf5 | 98% |
| avm1 | mcl_replace_root_swf7_to_swf6 | 98% |
| avm1 | movieclip_library_state_values | 97% |
| avm1 | movieclip_hittest_shapeflag | 96% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Key-v5 | 92% |
| from_gnash/actionscript.all | Selection-v7 | 88% |
| from_gnash/actionscript.all | Selection-v8 | 88% |
| from_gnash/actionscript.all | Selection-v6 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_shumway/avm1 | nativeinheritance | 83% |
| from_gnash/actionscript.all | System-v6 | 82% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | - | - | 186 |
| from_gnash/actionscript.all | - | - | 182 | 1093 |

*Comparing `868900bbb1a2` → `b8938ab392b9`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 3 | 3 | 100% |

## Per-Suite Details

### avm1

- **Pass:** 570/620 (91.9%)
- **Duration:** 3h03m33s across 30 shards
- **Lines:** 81,332/91,501 matching (88.9%)
- **Avg test duration:** 17.7s — slowest: `timeout` (47.4s)

### from_gnash/actionscript.all

- **Pass:** 5/190 (2.6%)
- **Duration:** 1h05m15s across 30 shards
- **Lines:** 1,726/16,957 matching (10.2%)
- **Avg test duration:** 20.5s — slowest: `array-v5` (42.8s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m03s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 17.3s — slowest: `jump_to_prev_block` (18.3s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 13m39s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 17.4s — slowest: `flash_events_Event` (18.8s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 6m43s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 17.5s — slowest: `watch` (19.9s)
