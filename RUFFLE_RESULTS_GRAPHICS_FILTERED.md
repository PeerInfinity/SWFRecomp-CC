# Ruffle Test Results (Graphics) (Filtered)

*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  
*See [RUFFLE_RESULTS_GRAPHICS.md](RUFFLE_RESULTS_GRAPHICS.md) for unfiltered results.*

**Commit:** `3589c6bcc859`  
**Date:** 2026-05-11 19:20 UTC  
**Total duration:** 48m13s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 591 | 611 | 96.7% | [details](ruffle-tests/tests/swfs/avm1/_results/results_graphics_filtered.md) |
| from_gnash/actionscript.all | 125 | 190 | 65.8% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-ming.all | 62 | 100 | 62.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfc.all | 7 | 15 | 46.7% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results_graphics_filtered.md) |
| from_gnash/misc-swfmill.all | 17 | 18 | 94.4% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results_graphics_filtered.md) |
| from_shumway | 63 | 76 | 82.9% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results_graphics_filtered.md) |
| from_shumway/avm1 | 43 | 45 | 95.6% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results_graphics_filtered.md) |
| **Total** | **915** | **1064** | **86.0%** | |

*61 tests ignored.*

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 95,535 | 95,887 | 99.6% |
| from_gnash/actionscript.all | 15,393 | 16,957 | 90.8% |
| from_gnash/misc-ming.all | 3,087 | 4,517 | 68.3% |
| from_gnash/misc-mtasc.all | 211 | 231 | 91.3% |
| from_gnash/misc-swfc.all | 370 | 492 | 75.2% |
| from_gnash/misc-swfmill.all | 49 | 51 | 96.1% |
| from_shumway | 618 | 637 | 97.0% |
| from_shumway/avm1 | 478 | 480 | 99.6% |
| **Total** | **115,741** | **119,252** | **97.1%** |

## Failure Breakdown

| Suite | output_mismatch | ruffle_matched | runtime_error | segfault | timeout |
|-------|-----------------:|----------------:|---------------:|----------:|---------:|
| avm1 | 13 | 6 | - | - | 1 |
| from_gnash/actionscript.all | 1 | 61 | 3 | - | - |
| from_gnash/misc-ming.all | 14 | 22 | - | 2 | - |
| from_gnash/misc-mtasc.all | - | 2 | - | - | - |
| from_gnash/misc-swfc.all | 2 | 6 | - | - | - |
| from_gnash/misc-swfmill.all | - | 1 | - | - | - |
| from_shumway | 12 | 1 | - | - | - |
| from_shumway/avm1 | 2 | - | - | - | - |
| **Total** | **44** | **99** | **3** | **2** | **1** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| avm1 | netstream_seek_flv | 100% |
| from_shumway | fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da | 100% |
| from_shumway | fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| from_shumway | fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883 | 100% |
| from_shumway | fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732 | 100% |
| from_shumway | fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69 | 100% |
| from_shumway | timeline/timeline_as2_1 | 100% |
| avm1 | sound | 99% |
| from_gnash/actionscript.all | array-v5 | 96% |
| from_shumway | fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822 | 96% |
| avm1 | tab_ordering_events | 87% |
| from_gnash/misc-ming.all | DrawingApiTest | 86% |
| from_gnash/misc-ming.all | action_order/action_execution_order_test11 | 81% |
| avm1 | default_names | 81% |

## Per-Suite Details

### avm1

- **Pass:** 591/611 (96.7%)
- **Ignored:** 40 tests
- **Duration:** 27m12s across 30 shards
- **Lines:** 95,535/95,887 matching (99.6%)
- **Avg test duration:** 2.5s — slowest: `timeout` (30.6s)

### from_gnash/actionscript.all

- **Pass:** 125/190 (65.8%)
- **Duration:** 5m41s across 30 shards
- **Lines:** 15,393/16,957 matching (90.8%)
- **Avg test duration:** 1.7s — slowest: `Sound-v5` (19.4s)

### from_gnash/misc-ming.all

- **Pass:** 62/100 (62.0%)
- **Ignored:** 2 tests
- **Duration:** 6m30s across 30 shards
- **Lines:** 3,087/4,517 matching (68.3%)
- **Avg test duration:** 3.8s — slowest: `loop/loop_test` (19.4s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 26s across 30 shards
- **Lines:** 211/231 matching (91.3%)
- **Avg test duration:** 2.8s — slowest: `hello` (18.5s)

### from_gnash/misc-swfc.all

- **Pass:** 7/15 (46.7%)
- **Ignored:** 1 tests
- **Duration:** 1m42s across 30 shards
- **Lines:** 370/492 matching (75.2%)
- **Avg test duration:** 6.7s — slowest: `registerclass_test3` (19.5s)

### from_gnash/misc-swfmill.all

- **Pass:** 17/18 (94.4%)
- **Duration:** 2m18s across 30 shards
- **Lines:** 49/51 matching (96.1%)
- **Avg test duration:** 7.7s — slowest: `zeroframe_definesprite` (19.1s)

### from_shumway

- **Pass:** 63/76 (82.9%)
- **Ignored:** 16 tests
- **Duration:** 3m23s across 30 shards
- **Lines:** 618/637 matching (97.0%)
- **Avg test duration:** 2.2s — slowest: `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` (19.3s)

### from_shumway/avm1

- **Pass:** 43/45 (95.6%)
- **Ignored:** 2 tests
- **Duration:** 57s across 30 shards
- **Lines:** 478/480 matching (99.6%)
- **Avg test duration:** 1.2s — slowest: `label` (18.6s)
