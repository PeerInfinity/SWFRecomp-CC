# Ruffle Test Results (Filtered)

**Date**: 2026-05-08 03:11 UTC

**Git SHA**: `b85626d2fc`

**Run Duration**: 0m 24s

**Filtered**: 16 tests ignored out of 92 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 76 |
| Passing | **72** (94.7%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **75** (98.7%) |
| Failing | 1 |
| Total expected lines | 637 |
| Matching lines | 615 (96.5%) |
| Mismatched lines | 22 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**72 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 0.2s |  |
| 2 | `avm1/array` | 7 | 0.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.1s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 0.2s |  |
| 5 | `avm1/callee` | 2 | 0.2s |  |
| 6 | `avm1/depth` | 6 | 0.3s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 0.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 0.2s |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 6 | 0.2s |  |
| 10 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 0.2s |  |
| 11 | `avm1/duplicateMovieClip/name-coercion` | 3 | 0.2s |  |
| 12 | `avm1/duplicateMovieClip/samedepth` | 6 | 0.2s |  |
| 13 | `avm1/externalinterface` | 4 | 0.2s |  |
| 14 | `avm1/filters` | 149 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 15 | `avm1/haxe/flocons1` | 2 | 0.2s |  |
| 16 | `avm1/haxe/flocons2` | 3 | 0.2s |  |
| 17 | `avm1/label` | 4 | 0.2s |  |
| 18 | `avm1/levels` | 9 | 0.2s |  |
| 19 | `avm1/loadevent` | 9 | 0.2s |  |
| 20 | `avm1/loadvariables/loadvariables` | 7 | 0.2s |  |
| 21 | `avm1/loadvariables/loadvars` | 2 | 0.2s |  |
| 22 | `avm1/lookup` | 3 | 0.2s |  |
| 23 | `avm1/mouse-transparency` | 1 | 0.2s |  |
| 24 | `avm1/nativeinheritance` | 6 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 25 | `avm1/nested-button` | 1 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 26 | `avm1/operations` | 13 | 0.2s |  |
| 27 | `avm1/property-paths/property-paths-6` | 6 | 0.2s |  |
| 28 | `avm1/property-paths/property-paths-7` | 7 | 0.2s |  |
| 29 | `avm1/propertycase/propertycase` | 7 | 0.2s |  |
| 30 | `avm1/propertycase/propertycase-preserving-6` | 2 | 0.2s |  |
| 31 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.2s |  |
| 32 | `avm1/rollover` | 4 | 0.2s |  |
| 33 | `avm1/scope` | 14 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 34 | `avm1/setinterval` | 20 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 35 | `avm1/settimeout` | 17 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 36 | `avm1/super` | 11 | 0.2s |  |
| 37 | `avm1/target` | 18 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 38 | `avm1/text-bind` | 0 | 0.2s |  |
| 39 | `avm1/textfield/textfield-html` | 4 | 0.2s |  |
| 40 | `avm1/textfield/textfield-text-setters` | 8 | 0.2s |  |
| 41 | `avm1/undefined/undefined-swf6` | 39 | 0.2s |  |
| 42 | `avm1/undefined/undefined-swf7` | 39 | 0.1s |  |
| 43 | `avm1/watch` | 2 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 44 | `avm1/xml/xmlbuild` | 1 | 0.2s |  |
| 45 | `avm1/xml/xmlload` | 4 | 0.2s |  |
| 46 | `avm1/xml/xmlstring` | 9 | 0.1s |  |
| 47 | `avm1timeline1` | 3 | 0.1s |  |
| 48 | `avm1timeline2` | 6 | 0.1s |  |
| 49 | `button3` | 1 | 0.2s |  |
| 50 | `doubleAndRegister` | 2 | 0.1s |  |
| 51 | `fscommand1` | 1 | 0.1s |  |
| 52 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 0.2s |  |
| 53 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 0.2s |  |
| 54 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 0.2s |  |
| 55 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 0.2s |  |
| 56 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 0.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 57 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 0.2s |  |
| 58 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 0.2s |  |
| 59 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 0.2s |  |
| 60 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 0.2s |  |
| 61 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 0.2s |  |
| 62 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 0.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 63 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 0.2s |  |
| 64 | `gradientTransform` | 0 | 0.1s |  |
| 65 | `invalidClipDepth` | 0 | 0.1s |  |
| 66 | `movieinfo1` | 3 | 0.1s |  |
| 67 | `targetPath1` | 8 | 0.1s |  |
| 68 | `timeline/timeline_as2_1` | 3 | 0.1s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 69 | `timeline/timeline_as2_2` | 3 | 0.1s |  |
| 70 | `timeline/timeline_as2_3` | 3 | 0.2s |  |
| 71 | `timeline/timeline_as2_4` | 2 | 0.2s |  |
| 72 | `timeline/timeline_as2_5` | 4 | 0.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm1/hitarea` | 2 | 2 | 0.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 2 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 0.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 3 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 0.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

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

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm1/moviecliploader` | 14.3% | 1/7 | 6 | 7 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 9 | 2 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 0 | 1 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 2 | 2 |
| | *(tests not in any document)* | 58 | 58 | 0 |
