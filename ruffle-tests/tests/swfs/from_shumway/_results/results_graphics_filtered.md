# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 12m 16s

**Filtered**: 13 tests ignored out of 92 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 67 |
| Passing | **65** (97.0%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **67** (100.0%) |
| Failing | 0 |
| Total expected lines | 597 |
| Matching lines | 583 (97.7%) |
| Mismatched lines | 14 |

## Passing Tests

**65 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 1.8s |  |
| 2 | `avm1/array` | 7 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.7s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 1.8s |  |
| 5 | `avm1/callee` | 2 | 0.5s |  |
| 6 | `avm1/depth` | 6 | 1.3s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 1.5s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 1.6s |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 6 | 20.9s |  |
| 10 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.0s |  |
| 11 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.9s |  |
| 12 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.0s |  |
| 13 | `avm1/externalinterface` | 4 | 1.8s |  |
| 14 | `avm1/filters` | 149 | 2.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 15 | `avm1/label` | 4 | 20.3s |  |
| 16 | `avm1/levels` | 9 | 1.9s |  |
| 17 | `avm1/loadevent` | 9 | 1.9s |  |
| 18 | `avm1/loadvariables/loadvariables` | 7 | 1.8s |  |
| 19 | `avm1/loadvariables/loadvars` | 2 | 2.0s |  |
| 20 | `avm1/lookup` | 3 | 2.1s |  |
| 21 | `avm1/mouse-transparency` | 1 | 2.0s |  |
| 22 | `avm1/moviecliploader` | 7 | 20.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 23 | `avm1/nativeinheritance` | 6 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 24 | `avm1/nested-button` | 1 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 25 | `avm1/operations` | 13 | 2.1s |  |
| 26 | `avm1/property-paths/property-paths-6` | 6 | 1.9s |  |
| 27 | `avm1/property-paths/property-paths-7` | 7 | 1.3s |  |
| 28 | `avm1/propertycase/propertycase` | 7 | 1.3s |  |
| 29 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.3s |  |
| 30 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.7s |  |
| 31 | `avm1/rollover` | 4 | 2.0s |  |
| 32 | `avm1/scope` | 14 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 33 | `avm1/setinterval` | 20 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 34 | `avm1/settimeout` | 17 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 35 | `avm1/super` | 11 | 1.9s |  |
| 36 | `avm1/textfield/textfield-text-setters` | 8 | 1.9s |  |
| 37 | `avm1/undefined/undefined-swf6` | 39 | 1.6s |  |
| 38 | `avm1/undefined/undefined-swf7` | 39 | 0.9s |  |
| 39 | `avm1/watch` | 2 | 1.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 40 | `avm1/xml/xmlbuild` | 1 | 1.6s |  |
| 41 | `avm1/xml/xmlload` | 4 | 0.8s |  |
| 42 | `avm1/xml/xmlstring` | 9 | 1.7s |  |
| 43 | `avm1timeline1` | 3 | 2.0s |  |
| 44 | `avm1timeline2` | 6 | 2.1s |  |
| 45 | `button3` | 1 | 3.3s |  |
| 46 | `doubleAndRegister` | 2 | 2.5s |  |
| 47 | `fscommand1` | 1 | 1.9s |  |
| 48 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 21.8s |  |
| 49 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 21.2s |  |
| 50 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 51 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.2s |  |
| 52 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 16.0s |  |
| 53 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 16.0s |  |
| 54 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 20.8s |  |
| 55 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 20.9s |  |
| 56 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 20.9s |  |
| 57 | `gradientTransform` | 0 | 22.1s |  |
| 58 | `invalidClipDepth` | 0 | 22.2s |  |
| 59 | `movieinfo1` | 3 | 1.9s |  |
| 60 | `targetPath1` | 8 | 0.8s |  |
| 61 | `timeline/timeline_as2_1` | 3 | 0.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 62 | `timeline/timeline_as2_2` | 3 | 0.8s |  |
| 63 | `timeline/timeline_as2_3` | 3 | 17.3s |  |
| 64 | `timeline/timeline_as2_4` | 2 | 17.4s |  |
| 65 | `timeline/timeline_as2_5` | 4 | 3.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |

## Ruffle-Matched Tests

**2 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 21.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 2 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 17.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 9 | 9 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 3 | 1 | 2 |
| | *(tests not in any document)* | 52 | 52 | 0 |
