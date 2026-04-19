# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `15b930bf53d2`  
**Date:** 2026-04-19 21:24 UTC  
**Total duration:** 1h48m24s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 600 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 109 | 190 | 57.4% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 18 | 102 | 17.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 14 | 18 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 60 | 92 | 65.2% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 44 | 45 | 97.8% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **850** | **1072** | **79.3%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,320 | 16,957 | 84.4% |
| from_gnash/misc-ming.all | 2,118 | 4,541 | 46.6% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 215 | 499 | 43.1% |
| from_gnash/misc-swfmill.all | 45 | 51 | 88.2% |
| from_shumway | 656 | 1,276 | 51.4% |
| from_shumway/avm1 | 476 | 480 | 99.2% |
| **Total** | **112,950** | **119,128** | **94.8%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched | runtime_error |
|-------|--------------:|-----------------:|----------------:|---------------:|
| avm1 | - | - | 4 | - |
| from_gnash/actionscript.all | - | 39 | 42 | - |
| from_gnash/misc-ming.all | 1 | 73 | 10 | - |
| from_gnash/misc-mtasc.all | - | 1 | 1 | - |
| from_gnash/misc-swfc.all | - | 10 | 3 | 1 |
| from_gnash/misc-swfmill.all | - | 3 | 1 | - |
| from_shumway | - | 31 | 1 | - |
| from_shumway/avm1 | - | 1 | - | - |
| **Total** | **1** | **158** | **62** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_gnash/actionscript.all | BitmapData-v8 | 97% |
| from_gnash/actionscript.all | LoadVars-v6 | 96% |
| from_gnash/actionscript.all | LoadVars-v7 | 96% |
| from_gnash/actionscript.all | LoadVars-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| from_gnash/actionscript.all | Number-v5 | 95% |
| from_gnash/actionscript.all | Selection-v6 | 94% |
| from_gnash/actionscript.all | Selection-v7 | 94% |
| from_gnash/actionscript.all | Selection-v8 | 94% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 92% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 92% |
| from_gnash/actionscript.all | array-v5 | 91% |
| from_gnash/misc-ming.all | get_frame_number_test | 87% |
| from_gnash/actionscript.all | Global-v8 | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |
| from_gnash/misc-ming.all | displaylist_depths/displaylist_depths_test11 | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/600 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 51m03s across 30 shards
- **Lines:** 94,915/95,093 matching (99.8%)
- **Avg test duration:** 4.7s — slowest: `movieclip_invalid_get_bounds_1` (19.5s)

### from_gnash/actionscript.all

- **Pass:** 109/190 (57.4%)
- **Duration:** 11m02s across 30 shards
- **Lines:** 14,320/16,957 matching (84.4%)
- **Avg test duration:** 3.4s — slowest: `Sound-v7` (18.9s)

### from_gnash/misc-ming.all

- **Pass:** 18/102 (17.6%)
- **Duration:** 22m13s across 30 shards
- **Lines:** 2,118/4,541 matching (46.6%)
- **Avg test duration:** 13.0s — slowest: `matrix_test` (19.8s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m36s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 10.6s — slowest: `TextFieldTest` (16.1s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 3m47s across 30 shards
- **Lines:** 215/499 matching (43.1%)
- **Avg test duration:** 14.2s — slowest: `opcode_guard_test2` (17.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 14/18 (77.8%)
- **Duration:** 4m49s across 30 shards
- **Lines:** 45/51 matching (88.2%)
- **Avg test duration:** 16.0s — slowest: `initaction_in_definesprite` (16.8s)

### from_shumway

- **Pass:** 60/92 (65.2%)
- **Duration:** 12m16s across 30 shards
- **Lines:** 656/1,276 matching (51.4%)
- **Avg test duration:** 7.9s — slowest: `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` (18.6s)

### from_shumway/avm1

- **Pass:** 44/45 (97.8%)
- **Ignored:** 2 tests
- **Duration:** 1m34s across 30 shards
- **Lines:** 476/480 matching (99.2%)
- **Avg test duration:** 1.7s — slowest: `nested-button` (16.8s)
