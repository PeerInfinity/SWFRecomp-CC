# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `d26475209e73`  
**Date:** 2026-04-30 19:11 UTC  
**Total duration:** 1h52m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 597 | 601 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 116 | 190 | 61.1% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 57 | 102 | 55.9% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 5 | 16 | 31.2% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 64 | 92 | 69.6% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **906** | **1073** | **84.4%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,935 | 95,113 | 99.8% |
| from_gnash/actionscript.all | 15,019 | 16,957 | 88.6% |
| from_gnash/misc-ming.all | 2,776 | 4,577 | 60.7% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 304 | 499 | 60.9% |
| from_gnash/misc-swfmill.all | 48 | 51 | 94.1% |
| from_shumway | 663 | 1,276 | 52.0% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **114,436** | **119,184** | **96.0%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched |
|-------|-----------------:|----------------:|
| avm1 | - | 4 |
| from_gnash/actionscript.all | 14 | 60 |
| from_gnash/misc-ming.all | 32 | 13 |
| from_gnash/misc-mtasc.all | - | 2 |
| from_gnash/misc-swfc.all | 8 | 3 |
| from_gnash/misc-swfmill.all | 2 | 1 |
| from_shumway | 26 | 2 |
| from_shumway/avm1 | - | - |
| **Total** | **82** | **85** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_gnash/misc-swfc.all | sound | 100% |
| from_gnash/misc-swfmill.all | tags_after_last_showframe | 100% |
| from_gnash/misc-swfc.all | movieclip_destruction_test2 | 93% |
| from_gnash/actionscript.all | array-v5 | 92% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test | 89% |
| from_gnash/misc-ming.all | loading/LoadVarsTest | 86% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 85% |
| from_gnash/actionscript.all | Global-v7 | 83% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 597/601 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 53m12s across 30 shards
- **Lines:** 94,935/95,113 matching (99.8%)
- **Avg test duration:** 4.9s — slowest: `button_key_events` (19.1s)

### from_gnash/actionscript.all

- **Pass:** 116/190 (61.1%)
- **Duration:** 11m24s across 30 shards
- **Lines:** 15,019/16,957 matching (88.6%)
- **Avg test duration:** 3.5s — slowest: `Matrix-v7` (18.8s)

### from_gnash/misc-ming.all

- **Pass:** 57/102 (55.9%)
- **Duration:** 22m59s across 30 shards
- **Lines:** 2,776/4,577 matching (60.7%)
- **Avg test duration:** 13.5s — slowest: `displaylist_depths/displaylist_depths_test4` (20.1s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m40s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 11.1s — slowest: `exception` (18.0s)

### from_gnash/misc-swfc.all

- **Pass:** 5/16 (31.2%)
- **Duration:** 3m56s across 30 shards
- **Lines:** 304/499 matching (60.9%)
- **Avg test duration:** 14.7s — slowest: `edittext_test1` (18.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 5m03s across 30 shards
- **Lines:** 48/51 matching (94.1%)
- **Avg test duration:** 16.8s — slowest: `dict_event` (17.9s)

### from_shumway

- **Pass:** 64/92 (69.6%)
- **Duration:** 12m17s across 30 shards
- **Lines:** 663/1,276 matching (52.0%)
- **Avg test duration:** 8.0s — slowest: `avm1/duplicateMovieClip/dontremove` (17.9s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m49s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.0s — slowest: `label` (17.2s)
