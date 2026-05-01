# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `2e50fd7e454e`  
**Date:** 2026-05-01 23:05 UTC  
**Total duration:** 2h05m27s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 600 | 647 | 92.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 122 | 190 | 64.2% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 62 | 102 | 60.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 6 | 16 | 37.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **924** | **1121** | **82.4%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,002 | 114,967 | 92.2% |
| from_gnash/actionscript.all | 15,243 | 16,957 | 89.9% |
| from_gnash/misc-ming.all | 2,825 | 4,577 | 61.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 308 | 499 | 61.7% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **125,787** | **139,049** | **90.5%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 38 |
| from_gnash/actionscript.all | 8 |
| from_gnash/misc-ming.all | 26 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 7 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **105** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
| from_gnash/actionscript.all | Global-v7 | 96% |
| from_gnash/actionscript.all | Global-v8 | 96% |
| from_gnash/actionscript.all | Global-v6 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 91% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 10 | - |

**from_gnash/misc-ming.all — newly passing:** `duplicate_movie_clip_test2`

*Comparing `d48ebaec6db3` → `2e50fd7e454e`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 600/647 (92.7%)
- **Duration:** 57m47s across 30 shards
- **Lines:** 106,002/114,967 matching (92.2%)
- **Avg test duration:** 5.3s — slowest: `form_loader_encoding_1` (19.8s)

### from_gnash/actionscript.all

- **Pass:** 122/190 (64.2%)
- **Duration:** 16m15s across 30 shards
- **Lines:** 15,243/16,957 matching (89.9%)
- **Avg test duration:** 5.1s — slowest: `Math-v5` (29.3s)

### from_gnash/misc-ming.all

- **Pass:** 62/102 (60.8%)
- **Duration:** 25m11s across 30 shards
- **Lines:** 2,825/4,577 matching (61.7%)
- **Avg test duration:** 14.8s — slowest: `NetStream-SquareTest` (27.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m06s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.0s — slowest: `enum` (18.4s)

### from_gnash/misc-swfc.all

- **Pass:** 6/16 (37.5%)
- **Duration:** 4m10s across 30 shards
- **Lines:** 308/499 matching (61.7%)
- **Avg test duration:** 15.6s — slowest: `swf4opcode` (19.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m08s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.1s — slowest: `mixed-bytecode-as2` (18.3s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 13m16s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 8.6s — slowest: `invalidClipDepth` (19.7s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m31s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 1.9s — slowest: `hitarea` (17.1s)
