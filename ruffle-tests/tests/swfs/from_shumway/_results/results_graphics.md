# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-10 21:29 UTC

**Git SHA**: `7767c2657e`

**Run Duration**: 1m 7s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **52** (56.5%) |
| Ruffle-matched | 5 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **57** (62.0%) |
| Failing | 35 |
| Total expected lines | 1276 |
| Matching lines | 747 (58.5%) |
| Mismatched lines | 529 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 35 | 100.0% |

## Passing Tests

**52 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 0.6s |  |
| 2 | `avm1/array` | 7 | 0.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.6s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 0.6s |  |
| 5 | `avm1/callee` | 2 | 0.7s |  |
| 6 | `avm1/depth` | 6 | 0.8s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 0.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 0.7s |  |
| 9 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 0.6s |  |
| 10 | `avm1/duplicateMovieClip/name-coercion` | 3 | 0.6s |  |
| 11 | `avm1/externalinterface` | 4 | 0.7s |  |
| 12 | `avm1/filters` | 149 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 13 | `avm1/haxe/flocons1` | 2 | 0.5s |  |
| 14 | `avm1/haxe/flocons2` | 3 | 0.5s |  |
| 15 | `avm1/label` | 4 | 0.7s |  |
| 16 | `avm1/loadevent` | 9 | 0.7s |  |
| 17 | `avm1/loadvariables/loadvariables` | 7 | 0.6s |  |
| 18 | `avm1/loadvariables/loadvars` | 2 | 0.6s |  |
| 19 | `avm1/lookup` | 3 | 0.6s |  |
| 20 | `avm1/nativeinheritance` | 6 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 21 | `avm1/operations` | 13 | 0.6s |  |
| 22 | `avm1/property-paths/property-paths-6` | 6 | 0.7s |  |
| 23 | `avm1/property-paths/property-paths-7` | 7 | 0.6s |  |
| 24 | `avm1/propertycase/propertycase` | 7 | 0.6s |  |
| 25 | `avm1/propertycase/propertycase-preserving-6` | 2 | 0.6s |  |
| 26 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.6s |  |
| 27 | `avm1/scope` | 14 | 0.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 28 | `avm1/super` | 11 | 0.8s |  |
| 29 | `avm1/target` | 18 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 30 | `avm1/text-bind` | 0 | 0.7s |  |
| 31 | `avm1/textfield/textfield-html` | 4 | 0.7s |  |
| 32 | `avm1/textfield/textfield-text-setters` | 8 | 0.6s |  |
| 33 | `avm1/undefined/undefined-swf6` | 39 | 0.6s |  |
| 34 | `avm1/undefined/undefined-swf7` | 39 | 0.6s |  |
| 35 | `avm1/watch` | 2 | 0.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 36 | `avm1/xml/xmlbuild` | 1 | 0.7s |  |
| 37 | `avm1/xml/xmlload` | 4 | 0.6s |  |
| 38 | `avm1/xml/xmlstring` | 9 | 0.6s |  |
| 39 | `avm1timeline1` | 3 | 0.6s |  |
| 40 | `avm1timeline2` | 6 | 0.6s |  |
| 41 | `doubleAndRegister` | 2 | 0.7s |  |
| 42 | `fscommand1` | 1 | 0.6s |  |
| 43 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 0.5s |  |
| 44 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 0.6s |  |
| 45 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 0.5s |  |
| 46 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 0.6s |  |
| 47 | `gradientTransform` | 0 | 0.8s |  |
| 48 | `invalidClipDepth` | 0 | 0.7s |  |
| 49 | `targetPath1` | 8 | 0.6s |  |
| 50 | `timeline/timeline_as2_2` | 3 | 0.6s |  |
| 51 | `timeline/timeline_as2_3` | 3 | 0.9s |  |
| 52 | `timeline/timeline_as2_4` | 2 | 0.7s |  |

## Ruffle-Matched Tests

**5 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm1/hitarea` | 2 | 2 | 0.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 2 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 2 | 3 | 0.7s |  |
| 3 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 3 | 13 | 0.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 24 | 38 | 0.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 5 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 4 | 22 | 0.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**12 tests** within reach

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
| 9 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 57.9% | 11 | 19 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 10 | `avm1/duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |
| 11 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 50.0% | 4 | 8 | 4 |  |
| 12 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 50.0% | 3 | 6 | 3 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**35 tests** with output mismatch, sorted by match rate (best first)

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
| 9 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 57.9% | 11/19 | 19 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 10 | `avm1/duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 11 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 50.0% | 4/8 | 8 | 8 |  |
| 12 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 50.0% | 3/6 | 6 | 6 |  |
| 13 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 46.2% | 12/26 | 26 | 23 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 14 | `avm1/levels` | 44.4% | 4/9 | 4 | 9 |  |
| 15 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 40.6% | 13/32 | 32 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 16 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 39.3% | 11/28 | 28 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 17 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 34.4% | 11/32 | 32 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 18 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 33.3% | 6/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 19 | `movieinfo1` | 33.3% | 1/3 | 3 | 3 |  |
| 20 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 30.8% | 8/26 | 26 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 21 | `timeline/timeline_as2_1` | 30.0% | 3/10 | 10 | 3 | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 22 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 27.0% | 17/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 23 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 26.8% | 11/41 | 41 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 24 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 26.7% | 20/75 | 75 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 25 | `avm1/rollover` | 25.0% | 1/4 | 3 | 4 |  |
| 26 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 22.2% | 8/36 | 36 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 27 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 20.8% | 20/96 | 96 | 70 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 28 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 13.3% | 10/75 | 75 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 29 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 12.7% | 8/63 | 63 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 30 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 10.2% | 11/108 | 108 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 31 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 9.8% | 9/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 32 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 8.7% | 15/173 | 173 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 33 | `avm1/mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 34 | `avm1/nested-button` | 0.0% | 0/1 | 0 | 1 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 35 | `button3` | 0.0% | 0/1 | 0 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 1 | 2 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 6 | 5 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 0 | 1 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 0 | 20 |
| | *(tests not in any document)* | 58 | 45 | 13 |
