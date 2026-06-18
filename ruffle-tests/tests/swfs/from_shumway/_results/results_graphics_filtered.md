# Ruffle Test Results (Filtered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 10m 32s

**Filtered**: 11 tests ignored out of 92 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 57 |
| Passing | **56** (98.2%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **57** (100.0%) |
| Failing | 0 |
| Total expected lines | 530 |
| Matching lines | 529 (99.8%) |
| Mismatched lines | 1 |

## Passing Tests

**56 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 1.9s |  |
| 2 | `avm1/array` | 7 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.7s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 1.9s |  |
| 5 | `avm1/callee` | 2 | 0.6s |  |
| 6 | `avm1/depth` | 6 | 1.6s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 1.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 1.6s |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 6 | 22.6s |  |
| 10 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.2s |  |
| 11 | `avm1/duplicateMovieClip/name-coercion` | 3 | 2.0s |  |
| 12 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.9s |  |
| 13 | `avm1/externalinterface` | 4 | 1.8s |  |
| 14 | `avm1/filters` | 149 | 2.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 15 | `avm1/loadvariables/loadvariables` | 7 | 1.8s |  |
| 16 | `avm1/loadvariables/loadvars` | 2 | 2.0s |  |
| 17 | `avm1/lookup` | 3 | 2.1s |  |
| 18 | `avm1/mouse-transparency` | 1 | 2.1s |  |
| 19 | `avm1/moviecliploader` | 7 | 20.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 20 | `avm1/nativeinheritance` | 6 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 21 | `avm1/property-paths/property-paths-7` | 7 | 1.8s |  |
| 22 | `avm1/propertycase/propertycase` | 7 | 1.8s |  |
| 23 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.8s |  |
| 24 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.7s |  |
| 25 | `avm1/rollover` | 4 | 2.0s |  |
| 26 | `avm1/scope` | 14 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 27 | `avm1/setinterval` | 20 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 28 | `avm1/settimeout` | 17 | 1.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 29 | `avm1/super` | 11 | 1.6s |  |
| 30 | `avm1/target` | 18 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 31 | `avm1/text-bind` | 0 | 20.7s |  |
| 32 | `avm1/textfield/textfield-html` | 4 | 1.9s |  |
| 33 | `avm1/textfield/textfield-text-setters` | 8 | 1.5s |  |
| 34 | `avm1/undefined/undefined-swf6` | 39 | 1.4s |  |
| 35 | `avm1/undefined/undefined-swf7` | 39 | 0.7s |  |
| 36 | `avm1/xml/xmlstring` | 9 | 1.7s |  |
| 37 | `avm1timeline1` | 3 | 2.1s |  |
| 38 | `avm1timeline2` | 6 | 2.1s |  |
| 39 | `button3` | 1 | 3.4s |  |
| 40 | `doubleAndRegister` | 2 | 2.6s |  |
| 41 | `fscommand1` | 1 | 2.0s |  |
| 42 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 20.9s |  |
| 43 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 20.1s |  |
| 44 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 45 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.9s |  |
| 46 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 20.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 47 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 27.3s |  |
| 48 | `gradientTransform` | 0 | 20.7s |  |
| 49 | `invalidClipDepth` | 0 | 20.9s |  |
| 50 | `movieinfo1` | 3 | 1.8s |  |
| 51 | `targetPath1` | 8 | 0.7s |  |
| 52 | `timeline/timeline_as2_1` | 3 | 0.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 53 | `timeline/timeline_as2_2` | 3 | 0.7s |  |
| 54 | `timeline/timeline_as2_3` | 3 | 20.6s |  |
| 55 | `timeline/timeline_as2_4` | 2 | 20.4s |  |
| 56 | `timeline/timeline_as2_5` | 4 | 4.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 21.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

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
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 8 | 8 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 3 | 2 | 1 |
| | *(tests not in any document)* | 43 | 43 | 0 |
