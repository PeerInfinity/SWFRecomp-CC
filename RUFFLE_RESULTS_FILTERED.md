# Ruffle Test Results (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*

**Commit:** `7b73007a454e`  
**Date:** 2026-04-11 20:21 UTC  
**Total duration:** 5h30m00s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 559 | 580 | 96.4% | [details](ruffle-tests/tests/swfs/avm1/_results/results_filtered.md) |
| from_gnash/actionscript.all | 88 | 185 | 47.6% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_filtered.md) |
| from_gnash/misc-ming.all | 8 | 58 | 13.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.md) |
| from_gnash/misc-swfc.all | 2 | 16 | 12.5% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_filtered.md) |
| from_gnash/misc-swfmill.all | 11 | 14 | 78.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_filtered.md) |
| from_shumway | 17 | 17 | 100% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_filtered.md) |
| from_shumway/avm1 | 19 | 22 | 86.4% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_filtered.md) |
| **Total** | **711** | **901** | **78.9%** | |

*76 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 72,487 | 73,309 | 98.9% |
| from_gnash/actionscript.all | 11,472 | 15,565 | 73.7% |
| from_gnash/misc-ming.all | 1,657 | 3,388 | 48.9% |
| from_gnash/misc-mtasc.all | 172 | 231 | 74.5% |
| from_gnash/misc-swfc.all | 224 | 499 | 44.9% |
| from_gnash/misc-swfmill.all | 25 | 29 | 86.2% |
| from_shumway | 35 | 35 | 100% |
| from_shumway/avm1 | 153 | 307 | 49.8% |
| **Total** | **86,225** | **93,363** | **92.4%** |

## Failure Breakdown

| Suite | output_mismatch | runtime_error |
|-------|-----------------:|---------------:|
| avm1 | 21 | - |
| from_gnash/actionscript.all | 97 | - |
| from_gnash/misc-ming.all | 50 | - |
| from_gnash/misc-mtasc.all | 2 | - |
| from_gnash/misc-swfc.all | 13 | 1 |
| from_gnash/misc-swfmill.all | 3 | - |
| from_shumway | - | - |
| from_shumway/avm1 | 3 | - |
| **Total** | **189** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | interface_implements_op | 98% |
| from_gnash/actionscript.all | Inheritance-v8 | 98% |
| from_gnash/actionscript.all | Inheritance-v7 | 97% |
| avm1 | on_construct | 96% |
| from_gnash/actionscript.all | ExternalInterface-v8 | 96% |
| from_gnash/misc-ming.all | DefineEditTextTest | 95% |
| avm1 | call | 95% |
| from_gnash/actionscript.all | delete-v7 | 95% |
| avm1 | function_as_function | 94% |
| from_gnash/actionscript.all | Number-v7 | 94% |
| from_gnash/actionscript.all | Number-v8 | 94% |
| from_gnash/actionscript.all | delete-v5 | 92% |
| from_gnash/actionscript.all | Selection-v7 | 91% |
| from_gnash/actionscript.all | Selection-v8 | 91% |
| from_gnash/actionscript.all | Inheritance-v6 | 91% |
| from_gnash/actionscript.all | Selection-v6 | 90% |
| from_gnash/actionscript.all | Number-v6 | 90% |
| from_gnash/actionscript.all | Number-v5 | 89% |
| from_gnash/actionscript.all | delete-v6 | 88% |
| from_gnash/actionscript.all | Point-v8 | 88% |
| from_gnash/misc-mtasc.all | TextFieldTest | 88% |
| from_gnash/actionscript.all | toString_valueOf-v7 | 87% |
| from_gnash/actionscript.all | toString_valueOf-v8 | 87% |
| from_gnash/actionscript.all | TextFieldHTML-v6 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v7 | 86% |
| from_gnash/actionscript.all | TextFieldHTML-v8 | 86% |
| from_gnash/actionscript.all | toString_valueOf-v6 | 86% |
| from_gnash/actionscript.all | LocalConnection-v6 | 86% |
| from_gnash/actionscript.all | LocalConnection-v7 | 86% |
| from_gnash/actionscript.all | LocalConnection-v8 | 86% |
| from_gnash/actionscript.all | Inheritance-v5 | 85% |
| from_gnash/actionscript.all | Rectangle-v8 | 84% |
| from_gnash/actionscript.all | ColorTransform-v8 | 84% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/actionscript.all | System-v7 | 83% |
| from_gnash/actionscript.all | System-v8 | 83% |
| from_gnash/actionscript.all | System-v6 | 83% |
| from_gnash/actionscript.all | Matrix-v8 | 83% |
| from_gnash/actionscript.all | array-v5 | 81% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/misc-ming.all | shape_test | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| avm1 | string_paths_variable_scopes | 80% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 559/580 (96.4%)
- **Ignored:** 40 tests
- **Duration:** 3h22m34s across 30 shards
- **Lines:** 72,487/73,309 matching (98.9%)
- **Avg test duration:** 19.5s — slowest: `movieclip_invalid_get_bounds_6` (44.4s)

### from_gnash/actionscript.all

- **Pass:** 88/185 (47.6%)
- **Ignored:** 5 tests
- **Duration:** 1h11m06s across 30 shards
- **Lines:** 11,472/15,565 matching (73.7%)
- **Avg test duration:** 22.2s — slowest: `array-v5` (46.6s)

### from_gnash/misc-ming.all

- **Pass:** 8/58 (13.8%)
- **Duration:** 20m56s across 30 shards
- **Lines:** 1,657/3,388 matching (48.9%)
- **Avg test duration:** 21.6s — slowest: `matrix_test` (72.0s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 3m00s across 30 shards
- **Lines:** 172/231 matching (74.5%)
- **Avg test duration:** 20.0s — slowest: `levels` (21.8s)

### from_gnash/misc-swfc.all

- **Pass:** 2/16 (12.5%)
- **Duration:** 5m19s across 30 shards
- **Lines:** 224/499 matching (44.9%)
- **Avg test duration:** 19.9s — slowest: `opcode_guard_test2` (21.4s)

### from_gnash/misc-swfmill.all

- **Pass:** 11/14 (78.6%)
- **Duration:** 4m30s across 30 shards
- **Lines:** 25/29 matching (86.2%)
- **Avg test duration:** 19.2s — slowest: `jump_to_prev_block` (19.9s)

### from_shumway

- **Pass:** 17/17 (100%)
- **Ignored:** 30 tests
- **Duration:** 15m08s across 30 shards
- **Lines:** 35/35 matching (100%)
- **Avg test duration:** 19.3s — slowest: `bitmapbuttons` (20.0s)

### from_shumway/avm1

- **Pass:** 19/22 (86.4%)
- **Ignored:** 1 tests
- **Duration:** 7m25s across 30 shards
- **Lines:** 153/307 matching (49.8%)
- **Avg test duration:** 19.3s — slowest: `watch` (20.1s)
