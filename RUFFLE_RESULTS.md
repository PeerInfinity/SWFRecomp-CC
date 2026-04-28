# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `abf1b163b420`  
**Date:** 2026-04-28 02:14 UTC  
**Total duration:** 1h52m51s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 594 | 641 | 92.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 113 | 190 | 59.5% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 52 | 102 | 51.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 63 | 92 | 68.5% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 44 | 47 | 93.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **893** | **1115** | **80.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,638 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,758 | 16,957 | 87.0% |
| from_gnash/misc-ming.all | 2,682 | 4,541 | 59.1% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 283 | 499 | 56.7% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 659 | 1,276 | 51.6% |
| from_shumway/avm1 | 479 | 491 | 97.6% |
| **Total** | **124,758** | **138,795** | **89.9%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 38 |
| from_gnash/actionscript.all | - | 22 |
| from_gnash/misc-ming.all | 1 | 36 |
| from_gnash/misc-mtasc.all | - | - |
| from_gnash/misc-swfc.all | - | 9 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 27 |
| from_shumway/avm1 | - | 2 |
| **Total** | **1** | **136** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
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
| from_gnash/misc-ming.all | register_class/registerClassTest2 | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/actionscript.all | HitTest-v8 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v7 | 81% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 3 | - | 214 |
| from_gnash/misc-ming.all | 2 | - | 59 | - |
| from_gnash/misc-swfc.all | - | 1 | 21 | - |
| from_gnash/misc-swfmill.all | - | - | 1 | - |
| from_shumway | - | 1 | - | 4 |
| from_shumway/avm1 | - | 1 | - | 4 |

**avm1 — newly failing:** `on_construct`, `register_and_init_order`, `resolve_different_root`

**from_gnash/misc-ming.all — newly passing:** `register_class/RegisterClassTest3`, `register_class/registerClassTest`

**from_shumway — newly failing:** `avm1/doactionorder/symbolclass`

**from_shumway/avm1 — newly failing:** `doactionorder/symbolclass`

*Comparing `ccf8ac97313d` → `abf1b163b420`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 594/641 (92.7%)
- **Duration:** 54m02s across 30 shards
- **Lines:** 105,638/114,749 matching (92.1%)
- **Avg test duration:** 5.0s — slowest: `movieclip_invalid_get_bounds_6` (24.3s)

### from_gnash/actionscript.all

- **Pass:** 113/190 (59.5%)
- **Duration:** 11m25s across 30 shards
- **Lines:** 14,758/16,957 matching (87.0%)
- **Avg test duration:** 3.5s — slowest: `case-v7` (18.6s)

### from_gnash/misc-ming.all

- **Pass:** 52/102 (51.0%)
- **Duration:** 22m46s across 30 shards
- **Lines:** 2,682/4,541 matching (59.1%)
- **Avg test duration:** 13.3s — slowest: `matrix_test` (20.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m42s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.3s — slowest: `exception` (16.8s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 3m55s across 30 shards
- **Lines:** 283/499 matching (56.7%)
- **Avg test duration:** 14.6s — slowest: `swf4opcode` (18.0s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m00s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 16.7s — slowest: `func_dict` (17.4s)

### from_shumway

- **Pass:** 63/92 (68.5%)
- **Duration:** 12m22s across 30 shards
- **Lines:** 659/1,276 matching (51.6%)
- **Avg test duration:** 8.0s — slowest: `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` (18.6s)

### from_shumway/avm1

- **Pass:** 44/47 (93.6%)
- **Duration:** 1m37s across 30 shards
- **Lines:** 479/491 matching (97.6%)
- **Avg test duration:** 2.0s — slowest: `text-bind` (17.0s)
