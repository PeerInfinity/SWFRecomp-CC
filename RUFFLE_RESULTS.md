# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e6170c519572`  
**Date:** 2026-05-01 00:38 UTC  
**Total duration:** 55m41s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 642 | 93.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 118 | 190 | 62.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 59 | 102 | 57.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **912** | **1116** | **81.7%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,872 | 114,769 | 92.2% |
| from_gnash/actionscript.all | 15,065 | 16,957 | 88.8% |
| from_gnash/misc-ming.all | 2,805 | 4,577 | 61.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,457** | **138,851** | **90.4%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 36 |
| from_gnash/actionscript.all | 12 |
| from_gnash/misc-ming.all | 29 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | 2 |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **112** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 1 |
| from_gnash/misc-ming.all | - | - | 3 | - |
| from_gnash/misc-swfmill.all | - | - | - | 1 |
| from_shumway | 1 | - | 3 | - |

**avm1 — newly failing:** `goto_frame_number`

**from_shumway — newly passing:** `timeline/timeline_as2_1`

*Comparing `67c4dc02d379` → `e6170c519572`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/642 (93.0%)
- **Duration:** 19m35s across 30 shards
- **Lines:** 105,872/114,769 matching (92.2%)
- **Avg test duration:** 1.8s — slowest: `bitmap_data_perlinnoise` (18.8s)

### from_gnash/actionscript.all

- **Pass:** 118/190 (62.1%)
- **Duration:** 7m48s across 30 shards
- **Lines:** 15,065/16,957 matching (88.8%)
- **Avg test duration:** 2.4s — slowest: `array-v5` (28.4s)

### from_gnash/misc-ming.all

- **Pass:** 59/102 (57.8%)
- **Duration:** 15m36s across 30 shards
- **Lines:** 2,805/4,577 matching (61.3%)
- **Avg test duration:** 9.1s — slowest: `NetStream-SquareTest` (28.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 24s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 2.6s — slowest: `TextFieldTest` (15.4s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 3m04s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 11.5s — slowest: `swf4opcode` (19.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 3m12s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 10.6s — slowest: `jump_to_prev_block` (17.6s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 5m04s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 3.2s — slowest: `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` (18.8s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 55s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.1s — slowest: `label` (17.7s)
