# Ruffle Test Results (Filtered)

**Date**: 2026-05-10 18:18 UTC

**Git SHA**: `ebaa7506c1`

**Run Duration**: 9m 51s

**Filtered**: 16 tests ignored out of 92 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 76 |
| Passing | **52** (68.4%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **57** (75.0%) |
| Failing | 19 |
| Total expected lines | 637 |
| Matching lines | 558 (87.6%) |
| Mismatched lines | 79 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 19 | 100.0% |

## Passing Tests

**52 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 0.6s |  |
| 2 | `avm1/array` | 7 | 0.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.6s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 5 | `avm1/callee` | 2 | 0.7s |  |
| 6 | `avm1/depth` | 6 | 1.8s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 0.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 0.7s |  |
| 9 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 1.6s |  |
| 10 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.5s |  |
| 11 | `avm1/externalinterface` | 4 | 1.2s |  |
| 12 | `avm1/filters` | 149 | 1.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 13 | `avm1/haxe/flocons1` | 2 | 1.5s |  |
| 14 | `avm1/haxe/flocons2` | 3 | 1.4s |  |
| 15 | `avm1/label` | 4 | 19.2s |  |
| 16 | `avm1/loadevent` | 9 | 1.9s |  |
| 17 | `avm1/loadvariables/loadvariables` | 7 | 1.7s |  |
| 18 | `avm1/loadvariables/loadvars` | 2 | 1.7s |  |
| 19 | `avm1/lookup` | 3 | 1.7s |  |
| 20 | `avm1/nativeinheritance` | 6 | 1.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 21 | `avm1/operations` | 13 | 1.6s |  |
| 22 | `avm1/property-paths/property-paths-6` | 6 | 1.5s |  |
| 23 | `avm1/property-paths/property-paths-7` | 7 | 1.7s |  |
| 24 | `avm1/propertycase/propertycase` | 7 | 1.6s |  |
| 25 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.6s |  |
| 26 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.6s |  |
| 27 | `avm1/scope` | 14 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 28 | `avm1/super` | 11 | 0.7s |  |
| 29 | `avm1/target` | 18 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 30 | `avm1/text-bind` | 0 | 0.8s |  |
| 31 | `avm1/textfield/textfield-html` | 4 | 1.5s |  |
| 32 | `avm1/textfield/textfield-text-setters` | 8 | 1.6s |  |
| 33 | `avm1/undefined/undefined-swf6` | 39 | 1.6s |  |
| 34 | `avm1/undefined/undefined-swf7` | 39 | 0.9s |  |
| 35 | `avm1/watch` | 2 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 36 | `avm1/xml/xmlbuild` | 1 | 1.6s |  |
| 37 | `avm1/xml/xmlload` | 4 | 1.7s |  |
| 38 | `avm1/xml/xmlstring` | 9 | 1.4s |  |
| 39 | `avm1timeline1` | 3 | 1.7s |  |
| 40 | `avm1timeline2` | 6 | 1.5s |  |
| 41 | `doubleAndRegister` | 2 | 2.4s |  |
| 42 | `fscommand1` | 1 | 1.5s |  |
| 43 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 19.2s |  |
| 44 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 18.6s |  |
| 45 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 19.7s |  |
| 46 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 0.5s |  |
| 47 | `gradientTransform` | 0 | 19.2s |  |
| 48 | `invalidClipDepth` | 0 | 19.3s |  |
| 49 | `targetPath1` | 8 | 1.3s |  |
| 50 | `timeline/timeline_as2_2` | 3 | 1.4s |  |
| 51 | `timeline/timeline_as2_3` | 3 | 1.9s |  |
| 52 | `timeline/timeline_as2_4` | 2 | 1.7s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm1/hitarea` | 2 | 2 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 2 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 2 | 3 | 18.8s |  |
| 3 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 3 | 13 | 19.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 24 | 38 | 0.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 5 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 4 | 22 | 19.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm1/moviecliploader` | 85.7% | 6 | 7 | 1 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 2 | `avm1/settimeout` | 82.4% | 14 | 17 | 3 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `timeline/timeline_as2_5` | 75.0% | 3 | 4 | 1 | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 4 | `avm1/setinterval` | 70.0% | 14 | 20 | 6 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm1/duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 6 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 66.7% | 4 | 6 | 2 |  |
| 7 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 66.7% | 2 | 3 | 1 |  |
| 8 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 66.7% | 2 | 3 | 1 |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |
| 10 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 50.0% | 4 | 8 | 4 |  |
| 11 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**19 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm1/moviecliploader` | 85.7% | 6/7 | 6 | 7 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 2 | `avm1/settimeout` | 82.4% | 14/17 | 14 | 17 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `timeline/timeline_as2_5` | 75.0% | 3/4 | 3 | 4 | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 4 | `avm1/setinterval` | 70.0% | 14/20 | 14 | 20 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm1/duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 6 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 66.7% | 4/6 | 6 | 6 |  |
| 7 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 66.7% | 2/3 | 3 | 3 |  |
| 8 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 66.7% | 2/3 | 3 | 3 |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 10 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 50.0% | 4/8 | 8 | 8 |  |
| 11 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 50.0% | 3/6 | 6 | 6 |  |
| 12 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 46.2% | 12/26 | 26 | 23 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 13 | `avm1/levels` | 44.4% | 4/9 | 4 | 9 |  |
| 14 | `movieinfo1` | 33.3% | 1/3 | 3 | 3 |  |
| 15 | `timeline/timeline_as2_1` | 30.0% | 3/10 | 10 | 3 | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 16 | `avm1/rollover` | 25.0% | 1/4 | 3 | 4 |  |
| 17 | `avm1/mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 18 | `avm1/nested-button` | 0.0% | 0/1 | 0 | 1 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 19 | `button3` | 0.0% | 0/1 | 0 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 1 | 2 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 6 | 5 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 0 | 1 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 0 | 4 |
| | *(tests not in any document)* | 58 | 45 | 13 |
