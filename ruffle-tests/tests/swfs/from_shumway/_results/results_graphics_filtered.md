# Ruffle Test Results (Filtered)

**Date**: 2026-06-16 19:39 UTC

**Git SHA**: `886c8b0e4f`

**Run Duration**: 15m 22s

**Filtered**: 16 tests ignored out of 92 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 76 |
| Passing | **73** (96.1%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **76** (100.0%) |
| Failing | 0 |
| Total expected lines | 637 |
| Matching lines | 621 (97.5%) |
| Mismatched lines | 16 |

## Passing Tests

**73 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 2.1s |  |
| 2 | `avm1/array` | 7 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.8s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 2.1s |  |
| 5 | `avm1/callee` | 2 | 0.7s |  |
| 6 | `avm1/depth` | 6 | 1.9s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 2.1s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 1.9s |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 6 | 20.6s |  |
| 10 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.0s |  |
| 11 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.9s |  |
| 12 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.1s |  |
| 13 | `avm1/externalinterface` | 4 | 1.9s |  |
| 14 | `avm1/filters` | 149 | 2.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 15 | `avm1/haxe/flocons1` | 2 | 1.9s |  |
| 16 | `avm1/haxe/flocons2` | 3 | 1.8s |  |
| 17 | `avm1/label` | 4 | 21.4s |  |
| 18 | `avm1/levels` | 9 | 2.0s |  |
| 19 | `avm1/loadevent` | 9 | 0.9s |  |
| 20 | `avm1/loadvariables/loadvariables` | 7 | 1.0s |  |
| 21 | `avm1/loadvariables/loadvars` | 2 | 2.0s |  |
| 22 | `avm1/lookup` | 3 | 2.1s |  |
| 23 | `avm1/mouse-transparency` | 1 | 2.2s |  |
| 24 | `avm1/moviecliploader` | 7 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 25 | `avm1/nativeinheritance` | 6 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 26 | `avm1/nested-button` | 1 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 27 | `avm1/operations` | 13 | 1.9s |  |
| 28 | `avm1/property-paths/property-paths-6` | 6 | 0.9s |  |
| 29 | `avm1/property-paths/property-paths-7` | 7 | 1.0s |  |
| 30 | `avm1/propertycase/propertycase` | 7 | 1.1s |  |
| 31 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.1s |  |
| 32 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.9s |  |
| 33 | `avm1/rollover` | 4 | 1.9s |  |
| 34 | `avm1/scope` | 14 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 35 | `avm1/setinterval` | 20 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 36 | `avm1/settimeout` | 17 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 37 | `avm1/super` | 11 | 2.0s |  |
| 38 | `avm1/target` | 18 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 39 | `avm1/text-bind` | 0 | 21.5s |  |
| 40 | `avm1/textfield/textfield-html` | 4 | 2.0s |  |
| 41 | `avm1/textfield/textfield-text-setters` | 8 | 2.0s |  |
| 42 | `avm1/undefined/undefined-swf6` | 39 | 1.7s |  |
| 43 | `avm1/undefined/undefined-swf7` | 39 | 0.9s |  |
| 44 | `avm1/watch` | 2 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 45 | `avm1/xml/xmlbuild` | 1 | 1.8s |  |
| 46 | `avm1/xml/xmlload` | 4 | 0.9s |  |
| 47 | `avm1/xml/xmlstring` | 9 | 1.8s |  |
| 48 | `avm1timeline1` | 3 | 2.2s |  |
| 49 | `avm1timeline2` | 6 | 2.2s |  |
| 50 | `button3` | 1 | 3.2s |  |
| 51 | `doubleAndRegister` | 2 | 2.4s |  |
| 52 | `fscommand1` | 1 | 1.8s |  |
| 53 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 21.8s |  |
| 54 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 21.5s |  |
| 55 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 20.4s |  |
| 56 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 19.9s |  |
| 57 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 58 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.2s |  |
| 59 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 20.7s |  |
| 60 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 20.5s |  |
| 61 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 21.5s |  |
| 62 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 21.4s |  |
| 63 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 22.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 64 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 21.4s |  |
| 65 | `gradientTransform` | 0 | 21.0s |  |
| 66 | `invalidClipDepth` | 0 | 21.0s |  |
| 67 | `movieinfo1` | 3 | 1.9s |  |
| 68 | `targetPath1` | 8 | 0.7s |  |
| 69 | `timeline/timeline_as2_1` | 3 | 0.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 70 | `timeline/timeline_as2_2` | 3 | 0.7s |  |
| 71 | `timeline/timeline_as2_3` | 3 | 22.6s |  |
| 72 | `timeline/timeline_as2_4` | 2 | 22.1s |  |
| 73 | `timeline/timeline_as2_5` | 4 | 4.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm1/hitarea` | 2 | 2 | 21.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 2 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 21.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 3 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 22.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

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
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 2 | 2 |
| | *(tests not in any document)* | 58 | 58 | 0 |
