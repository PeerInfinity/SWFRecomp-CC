# Ruffle Test Results

*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) for results with ignored tests excluded.*

**Commit:** `e3dd02d46bee`  
**Date:** 2026-04-22 19:39 UTC  
**Total duration:** 1h50m22s

## Results by Suite

| Suite | Pass | Total | Rate | Report |
|-------|-----:|------:|-----:|--------|
| avm1 | 596 | 641 | 93.0% | [details](ruffle-tests/tests/swfs/avm1/_results/results.md) |
| from_gnash/actionscript.all | 110 | 190 | 57.9% | [details](ruffle-tests/tests/swfs/from_gnash/actionscript.all/_results/results.md) |
| from_gnash/misc-ming.all | 22 | 102 | 21.6% | [details](ruffle-tests/tests/swfs/from_gnash/misc-ming.all/_results/results.md) |
| from_gnash/misc-mtasc.all | 7 | 9 | 77.8% | [details](ruffle-tests/tests/swfs/from_gnash/misc-mtasc.all/_results/results.md) |
| from_gnash/misc-swfc.all | 4 | 16 | 25.0% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfc.all/_results/results.md) |
| from_gnash/misc-swfmill.all | 15 | 18 | 83.3% | [details](ruffle-tests/tests/swfs/from_gnash/misc-swfmill.all/_results/results.md) |
| from_shumway | 61 | 92 | 66.3% | [details](ruffle-tests/tests/swfs/from_shumway/_results/results.md) |
| from_shumway/avm1 | 45 | 47 | 95.7% | [details](ruffle-tests/tests/swfs/from_shumway/avm1/_results/results.md) |
| **Total** | **860** | **1115** | **77.1%** | |

## Line-Level Accuracy

| Suite | Matching | Expected | Accuracy |
|-------|--------:|---------:|---------:|
| avm1 | 105,731 | 114,749 | 92.1% |
| from_gnash/actionscript.all | 14,742 | 16,957 | 86.9% |
| from_gnash/misc-ming.all | 2,201 | 4,541 | 48.5% |
| from_gnash/misc-mtasc.all | 205 | 231 | 88.7% |
| from_gnash/misc-swfc.all | 230 | 499 | 46.1% |
| from_gnash/misc-swfmill.all | 47 | 51 | 92.2% |
| from_shumway | 662 | 1,276 | 51.9% |
| from_shumway/avm1 | 483 | 491 | 98.4% |
| **Total** | **124,301** | **138,795** | **89.6%** |

## Failure Breakdown

| Suite | compile_fail | output_mismatch |
|-------|--------------:|-----------------:|
| avm1 | - | 36 |
| from_gnash/actionscript.all | - | 31 |
| from_gnash/misc-ming.all | 1 | 68 |
| from_gnash/misc-mtasc.all | - | 1 |
| from_gnash/misc-swfc.all | - | 9 |
| from_gnash/misc-swfmill.all | - | 2 |
| from_shumway | - | 30 |
| from_shumway/avm1 | - | 1 |
| **Total** | **1** | **178** |

## Near-Passing Tests (≥80% line match)

Tests with `output_mismatch` status but ≥80% of expected lines matching.

| Suite | Test | Match Rate |
|-------|------|----------:|
| from_shumway | fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229 | 100% |
| from_shumway | fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0 | 100% |
| avm1 | date | 99% |
| avm1 | native_objects_swf6 | 99% |
| avm1 | bitmap_filters | 98% |
| avm1 | bitmap_data_thorough/pixelDissolve | 97% |
| avm1 | movieclip_hittest_shapeflag | 97% |
| avm1 | globals_swf5 | 97% |
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
| from_gnash/actionscript.all | Global-v8 | 86% |
| avm1 | movieclip_get_instance_at_depth | 86% |
| from_gnash/misc-ming.all | matrix_test | 84% |
| from_gnash/misc-ming.all | static_vs_dynamic2 | 83% |
| from_gnash/actionscript.all | Global-v7 | 83% |
| avm1 | load_vars | 83% |
| from_gnash/misc-ming.all | loop/loop_test4 | 82% |
| from_gnash/actionscript.all | AsBroadcaster-v6 | 81% |
| from_gnash/actionscript.all | HitTest-v8 | 81% |
| from_gnash/misc-ming.all | RollOverOutTest | 80% |

## Changes Since Last Run

| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |
|-------|-------------:|-------------:|--------------:|----------------:|
| avm1 | - | 1 | - | 4 |
| from_gnash/misc-ming.all | 1 | - | 6 | - |

**avm1 — newly failing:** `movieclip_get_instance_at_depth`

**from_gnash/misc-ming.all — newly passing:** `shape_test`

*Comparing `41d96d87d28f` → `e3dd02d46bee`*

## Flash-Spec Results

Tests verified against Flash's actual output (`output.flash.txt`).

| Suite | Pass | Total | Rate |
|-------|-----:|------:|-----:|
| avm1 | 0 | 3 | 0% |

## Per-Suite Details

### avm1

- **Pass:** 596/641 (93.0%)
- **Duration:** 52m02s across 30 shards
- **Lines:** 105,731/114,749 matching (92.1%)
- **Avg test duration:** 4.8s — slowest: `mcl_unloadclip` (21.1s)

### from_gnash/actionscript.all

- **Pass:** 110/190 (57.9%)
- **Duration:** 11m17s across 30 shards
- **Lines:** 14,742/16,957 matching (86.9%)
- **Avg test duration:** 3.5s — slowest: `Video-v5` (18.7s)

### from_gnash/misc-ming.all

- **Pass:** 22/102 (21.6%)
- **Duration:** 22m30s across 30 shards
- **Lines:** 2,201/4,541 matching (48.5%)
- **Avg test duration:** 13.2s — slowest: `matrix_test` (19.6s)

### from_gnash/misc-mtasc.all

- **Pass:** 7/9 (77.8%)
- **Duration:** 1m37s across 30 shards
- **Lines:** 205/231 matching (88.7%)
- **Avg test duration:** 10.8s — slowest: `exception` (17.6s)

### from_gnash/misc-swfc.all

- **Pass:** 4/16 (25.0%)
- **Duration:** 3m52s across 30 shards
- **Lines:** 230/499 matching (46.1%)
- **Avg test duration:** 14.5s — slowest: `stackscope` (18.3s)

### from_gnash/misc-swfmill.all

- **Pass:** 15/18 (83.3%)
- **Duration:** 4m56s across 30 shards
- **Lines:** 47/51 matching (92.2%)
- **Avg test duration:** 16.4s — slowest: `trace-as2/root_onload` (18.1s)

### from_shumway

- **Pass:** 61/92 (66.3%)
- **Duration:** 12m27s across 30 shards
- **Lines:** 662/1,276 matching (51.9%)
- **Avg test duration:** 8.1s — slowest: `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` (18.4s)

### from_shumway/avm1

- **Pass:** 45/47 (95.7%)
- **Duration:** 1m37s across 30 shards
- **Lines:** 483/491 matching (98.4%)
- **Avg test duration:** 2.0s — slowest: `text-bind` (18.2s)
