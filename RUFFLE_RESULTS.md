# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `431a14a0d250`  
**Date:** 2026-04-28 17:26 UTC  
**Total duration:** 2h23m07s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 595 | 641 | 92.8% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 54 | 102 | 52.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 62 | 92 | 67.4% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **896** | **1115** | **80.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,844 | 114,749 | 92.2% |
| from_gnash/actionscript.all | 14,758 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,699 | 4,541 | 59.4% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 281 | 499 | 56.3% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,987** | **138,795** | **90.1%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 37 |
| from_gnash/actionscript.all | - | 22 |
| from_gnash/misc-ming.all | 1 | 34 |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | - | 8 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 29 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **133** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | looping | 100% |
| avm1 | register_globals_across_frames | 100% |
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | HitTest-v8 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v7 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 2 | - | 8 |
| from_gnash/misc-ming.all | 2 | - | 22 | 1 |
| from_shumway | - | 3 | - | - |

**avm1 — newly failing:** `looping`, `register_globals_across_frames`

**from_gnash/misc-ming.all — newly passing:** `loop/loop_test`, `place_and_remove_object_insane_test`

**from_shumway — newly failing:** `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229`, `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0`

*Comparing `cdc61ecbd34e` → `431a14a0d250`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 595/641 (92.8%)
- **Duration:** 1h04m58s across 30 shards
- **Lines:** 105,844/114,749 matching (92.2%)
- **Avg test duration:** 6.0s — slowest: `netstream_play_flv_screen` (33.7s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 21m42s across 30 shards
- **Lines:** 14,758/16,957 matching (87.0%)
- **Avg test duration:** 6.8s — slowest: `String-v8` (33.2s)

### from_gnash/misc-ming.all

- **Pass:** 54/102 (52.9%)
- **Duration:** 28m30s across 30 shards
- **Lines:** 2,699/4,541 matching (59.4%)
- **Avg test duration:** 16.7s — slowest: `matrix_test` (102.7s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m54s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 12.7s — slowest: `exception` (19.2s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 4m20s across 30 shards
- **Lines:** 281/499 matching (56.3%)
- **Avg test duration:** 16.2s — slowest: `movieclip_destruction_test4` (19.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m14s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 17.4s — slowest: `initaction_in_definesprite` (18.3s)

### from_shumway

- **Pass:** 62/92 (67.4%)
- **Duration:** 14m12s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 9.2s — slowest: `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` (21.5s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 2m13s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.8s — slowest: `label` (19.2s)
