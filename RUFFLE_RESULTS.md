# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e707c6896265`  
**Date:** 2026-05-05 02:00 UTC  
**Total duration:** 2h19m40s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 602 | 647 | 93.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 126 | 190 | 66.3% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 64 | 102 | 62.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 7 | 16 | 43.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 65 | 92 | 70.7% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **933** | **1121** | **83.2%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 106,034 | 114,967 | 92.2% |
| from_gnash/actionscript.all | 15,370 | 16,957 | 90.6% |
| from_gnash/misc-ming.all | 2,907 | 4,577 | 63.5% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 360 | 499 | 72.1% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 666 | 1,276 | 52.2% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **126,080** | **139,049** | **90.7%** |

## Failure Breakdown

| Suite | output_mismatch |
|-------|-----------------:|
| avm1 | 36 |
| from_gnash/actionscript.all | 2 |
| from_gnash/misc-ming.all | 20 |
| from_gnash/misc-mtasc.all | - |
| from_gnash/misc-swfc.all | 4 |
| from_gnash/misc-swfmill.all | - |
| from_shumway | 25 |
| from_shumway/avm1 | 1 |
| **Total** | **88** |

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
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | matrix_test | 87% |
| avm1 | load_vars | 83% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| from_gnash/misc-ming.all | 1 | - | 5 | - |

**from_gnash/misc-ming.all — newly passing:** `frame_label_test`

*Comparing `3a0a423d4ec7` → `e707c6896265`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 602/647 (93.0%)
- **Duration:** 1h02m24s across 30 shards
- **Lines:** 106,034/114,967 matching (92.2%)
- **Avg test duration:** 5.7s — slowest: `netstream_play_flv_screen` (32.4s)

### from_gnash/actionscript.all

- **Pass:** 126/190 (66.3%)
- **Duration:** 21m04s across 30 shards
- **Lines:** 15,370/16,957 matching (90.6%)
- **Avg test duration:** 6.6s — slowest: `MovieClip-v5` (33.5s)

### from_gnash/misc-ming.all

- **Pass:** 64/102 (62.7%)
- **Duration:** 28m41s across 30 shards
- **Lines:** 2,907/4,577 matching (63.5%)
- **Avg test duration:** 16.8s — slowest: `matrix_test` (100.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 2m10s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 14.5s — slowest: `hello` (18.8s)

### from_gnash/misc-swfc.all

- **Pass:** 7/16 (43.8%)
- **Duration:** 4m17s across 30 shards
- **Lines:** 360/499 matching (72.1%)
- **Avg test duration:** 16.0s — slowest: `sound` (19.7s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 5m14s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 17.4s — slowest: `tags_after_last_showframe` (19.3s)

### from_shumway

- **Pass:** 65/92 (70.7%)
- **Duration:** 14m02s across 30 shards
- **Lines:** 666/1,276 matching (52.2%)
- **Avg test duration:** 9.1s — slowest: `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` (20.3s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m45s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.2s — slowest: `label` (17.6s)
