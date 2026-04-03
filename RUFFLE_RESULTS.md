# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `dc2748b675fb`  
**Date:** 2026-04-03 22:14 UTC  
**Total duration:** 4h45m20s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 570 | 620 | 91.9% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 68 | 190 | 35.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 17 | 47 | 36.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 12 | 23 | 52.2% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **678** | **894** | **75.8%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 81,311 | 91,594 | 88.8% |
| from_gnash/actionscript.all | 12,423 | 16,957 | 73.3% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 256 | 13.7% |
| from_shumway/avm1 | 118 | 311 | 37.9% |
| **Total** | **93,912** | **109,147** | **86.0%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error | runtime_segfault | timeout |
|-------|-----------------:|---------------:|------------------:|---------:|
| avm1 | 47 | - | 2 | 1 |
| from_gnash/actionscript.all | 122 | - | - | - |
| from_gnash/misc-swfmill.all | 3 | - | - | - |
| from_shumway | 30 | - | - | - |
| from_shumway/avm1 | 10 | 1 | - | - |
| **Total** | **212** | **1** | **2** | **1** |

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
| avm1 | movieclip_library_state_values | 97% |
| from_gnash/actionscript.all | ops-v8 | 97% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| from_gnash/actionscript.all | Color-v6 | 96% |
| avm1 | movieclip_hittest_shapeflag | 96% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/actionscript.all | NetStream-v6 | 95% |
| from_gnash/actionscript.all | NetStream-v7 | 95% |
| from_gnash/actionscript.all | NetStream-v8 | 95% |
| from_shumway/avm1 | scope | 93% |
| from_gnash/actionscript.all | Key-v5 | 92% |
| avm1 | native_objects_swf7 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| avm1 | native_objects_swf8 | 90% |
| from_gnash/actionscript.all | Selection-v7 | 89% |
| from_gnash/actionscript.all | Selection-v8 | 89% |
| from_gnash/actionscript.all | Selection-v6 | 88% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/actionscript.all | Error-v6 | 87% |
| from_gnash/actionscript.all | Error-v7 | 87% |
| from_gnash/actionscript.all | Error-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 86% |
| from_gnash/actionscript.all | Error-v5 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | Inheritance-v5 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_shumway/avm1 | nativeinheritance | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | System-v7 | 82% |
| from_gnash/actionscript.all | System-v8 | 82% |
| from_gnash/actionscript.all | System-v6 | 82% |
| from_gnash/actionscript.all | Number-v7 | 81% |
| from_gnash/actionscript.all | Number-v8 | 81% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 2 | 1 | 135 |
| from_gnash/actionscript.all | - | - | 6 | 2 |

**avm1 — newly failing:** `native_objects_swf7`, `native_objects_swf8`

*Comparing `bbe171d20f4f` → `dc2748b675fb`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 1 | 3 | 33.3% |

## Per-Suite Details

### avm1

- **Pass:** 570/620 (91.9%)
- **Duration:** 3h12m11s across 30 shards
- **Lines:** 81,311/91,594 matching (88.8%)
- **Avg test duration:** 18.5s — slowest: `timeout` (48.2s)

### from_gnash/actionscript.all

- **Pass:** 68/190 (35.8%)
- **Duration:** 1h07m38s across 30 shards
- **Lines:** 12,423/16,957 matching (73.3%)
- **Avg test duration:** 21.3s — slowest: `array-v5` (43.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m15s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 18.2s — slowest: `dict_event` (18.7s)

### from_shumway

- **Pass:** 17/47 (36.2%)
- **Duration:** 14m14s across 30 shards
- **Lines:** 35/256 matching (13.7%)
- **Avg test duration:** 18.1s — slowest: `as3-interfaces` (19.2s)

### from_shumway/avm1

- **Pass:** 12/23 (52.2%)
- **Duration:** 7m01s across 30 shards
- **Lines:** 118/311 matching (37.9%)
- **Avg test duration:** 18.3s — slowest: `watch` (19.5s)
