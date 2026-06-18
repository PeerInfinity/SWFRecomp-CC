# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 22:05 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 10m 32s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 68 |
| Passing | **56** (82.4%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **57** (83.8%) |
| Failing | 11 |
| Total expected lines | 1009 |
| Matching lines | 707 (70.1%) |
| Mismatched lines | 302 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 100.0% |

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

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18 | 32 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 2 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10 | 18 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**11 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18/32 | 32 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 2 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 3 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 41.5% | 17/41 | 41 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 33.3% | 25/75 | 75 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 5 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 33.3% | 12/36 | 36 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 6 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 30.2% | 19/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 7 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 28.0% | 21/75 | 75 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 27.0% | 17/63 | 63 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 9 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 12.0% | 13/108 | 108 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 10 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 12.0% | 11/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 8.7% | 15/173 | 173 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 8 | 8 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 14 | 2 | 12 |
| | *(tests not in any document)* | 43 | 43 | 0 |
