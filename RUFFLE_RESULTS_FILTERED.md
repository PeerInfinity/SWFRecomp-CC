# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `e77ecee49cad`  
**Date:** 2026-04-22 03:50 UTC  
**Total duration:** 2h00m09s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 600 | 99.3% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 110 | 190 | 57.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 20 | 102 | 19.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 3 | 16 | 18.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 61 | 92 | 66.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 45 | 45 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **857** | **1072** | **79.9%** | |

*43 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 94,915 | 95,093 | 99.8% |
| from_gnash/actionscript.all | 14,742 | 16,957 | 86.9% |
| from_gnash/misc-ming.all | 2,182 | 4,541 | 48.1% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 219 | 499 | 43.9% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 480 | 480 | 100% |
| **Total** | **113,452** | **119,128** | **95.2%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch | ruffle_matched |
|-------|--------------:|-----------------:|----------------:|
| avm1 | - | - | 4 |
| from_gnash/actionscript.all | - | 31 | 49 |
| from_gnash/misc-ming.all | 1 | 70 | 11 |
| from_gnash/misc-mtasc.all | - | 1 | 1 |
| from_gnash/misc-swfc.all | - | 10 | 3 |
| from_gnash/misc-swfmill.all | - | 2 | 1 |
| from_shumway | - | 30 | 1 |
| from_shumway/avm1 | - | - | - |
| **Total** | **1** | **144** | **70** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_gnash/actionscript.all | LoadVars-v6 | 96% |
| from_gnash/actionscript.all | LoadVars-v7 | 96% |
| from_gnash/actionscript.all | LoadVars-v8 | 96% |
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
| from_gnash/misc-ming.all | loop/loop_test4 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/600 (99.3%)
- **Ignored:** 41 tests
- **Duration:** 55m16s across 30 shards
- **Lines:** 94,915/95,093 matching (99.8%)
- **Avg test duration:** 5.1s — slowest: `bitand` (21.6s)

### from_gnash/actionscript.all

- **Pass:** 110/190 (57.9%)
- **Duration:** 15m27s across 30 shards
- **Lines:** 14,742/16,957 matching (86.9%)
- **Avg test duration:** 4.8s — slowest: `String-v8` (32.0s)

### from_gnash/misc-ming.all

- **Pass:** 20/102 (19.6%)
- **Duration:** 23m57s across 30 shards
- **Lines:** 2,182/4,541 matching (48.1%)
- **Avg test duration:** 14.0s — slowest: `DefineEditTextTest` (27.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m48s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 12.0s — slowest: `TextFieldTest` (18.6s)

### from_gnash/misc-swfc.all

- **Pass:** 3/16 (18.8%)
- **Duration:** 3m52s across 30 shards
- **Lines:** 219/499 matching (43.9%)
- **Avg test duration:** 14.5s — slowest: `opcode_guard_test2` (19.1s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m54s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 16.3s — slowest: `jump_to_prev_block` (18.1s)

### from_shumway

- **Pass:** 61/92 (66.3%)
- **Duration:** 12m59s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 8.4s — slowest: `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` (18.6s)

### from_shumway/avm1

- **Pass:** 45/45 (100%)
- **Ignored:** 2 tests
- **Duration:** 1m53s across 30 shards
- **Lines:** 480/480 matching (100%)
- **Avg test duration:** 2.1s — slowest: `duplicateMovieClip/dontremove` (16.2s)
