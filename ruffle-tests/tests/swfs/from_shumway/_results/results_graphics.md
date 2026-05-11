# Ruffle Test Results (Unfiltered)

**Date**: 2026-05-11 19:20 UTC

**Git SHA**: `3589c6bcc8`

**Run Duration**: 3m 24s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **63** (68.5%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **64** (69.6%) |
| Failing | 28 |
| Total expected lines | 1276 |
| Matching lines | 879 (68.9%) |
| Mismatched lines | 397 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 28 | 100.0% |

## Passing Tests

**63 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 0.7s |  |
| 2 | `avm1/array` | 7 | 0.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.6s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 0.7s |  |
| 5 | `avm1/callee` | 2 | 0.5s |  |
| 6 | `avm1/depth` | 6 | 0.7s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 0.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 0.6s |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 6 | 0.7s |  |
| 10 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 0.6s |  |
| 11 | `avm1/duplicateMovieClip/name-coercion` | 3 | 0.7s |  |
| 12 | `avm1/duplicateMovieClip/samedepth` | 6 | 0.7s |  |
| 13 | `avm1/externalinterface` | 4 | 0.7s |  |
| 14 | `avm1/filters` | 149 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 15 | `avm1/haxe/flocons1` | 2 | 0.8s |  |
| 16 | `avm1/haxe/flocons2` | 3 | 0.8s |  |
| 17 | `avm1/label` | 4 | 0.8s |  |
| 18 | `avm1/levels` | 9 | 0.9s |  |
| 19 | `avm1/loadevent` | 9 | 0.8s |  |
| 20 | `avm1/loadvariables/loadvariables` | 7 | 0.7s |  |
| 21 | `avm1/loadvariables/loadvars` | 2 | 0.7s |  |
| 22 | `avm1/lookup` | 3 | 0.7s |  |
| 23 | `avm1/moviecliploader` | 7 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 24 | `avm1/nativeinheritance` | 6 | 1.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 25 | `avm1/operations` | 13 | 0.9s |  |
| 26 | `avm1/property-paths/property-paths-6` | 6 | 0.9s |  |
| 27 | `avm1/property-paths/property-paths-7` | 7 | 0.7s |  |
| 28 | `avm1/propertycase/propertycase` | 7 | 0.7s |  |
| 29 | `avm1/propertycase/propertycase-preserving-6` | 2 | 0.7s |  |
| 30 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.8s |  |
| 31 | `avm1/rollover` | 4 | 18.2s |  |
| 32 | `avm1/scope` | 14 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 33 | `avm1/setinterval` | 20 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 34 | `avm1/settimeout` | 17 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 35 | `avm1/super` | 11 | 0.8s |  |
| 36 | `avm1/target` | 18 | 0.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 37 | `avm1/text-bind` | 0 | 0.8s |  |
| 38 | `avm1/textfield/textfield-html` | 4 | 0.7s |  |
| 39 | `avm1/textfield/textfield-text-setters` | 8 | 0.7s |  |
| 40 | `avm1/undefined/undefined-swf6` | 39 | 0.7s |  |
| 41 | `avm1/undefined/undefined-swf7` | 39 | 0.6s |  |
| 42 | `avm1/watch` | 2 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 43 | `avm1/xml/xmlbuild` | 1 | 0.8s |  |
| 44 | `avm1/xml/xmlload` | 4 | 0.8s |  |
| 45 | `avm1/xml/xmlstring` | 9 | 0.9s |  |
| 46 | `avm1timeline1` | 3 | 18.5s |  |
| 47 | `avm1timeline2` | 6 | 0.9s |  |
| 48 | `doubleAndRegister` | 2 | 0.9s |  |
| 49 | `fscommand1` | 1 | 0.8s |  |
| 50 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 19.1s |  |
| 51 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 0.8s |  |
| 52 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 0.7s |  |
| 53 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 0.7s |  |
| 54 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 0.8s |  |
| 55 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 0.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 56 | `gradientTransform` | 0 | 0.8s |  |
| 57 | `invalidClipDepth` | 0 | 0.7s |  |
| 58 | `movieinfo1` | 3 | 0.7s |  |
| 59 | `targetPath1` | 8 | 0.8s |  |
| 60 | `timeline/timeline_as2_2` | 3 | 0.8s |  |
| 61 | `timeline/timeline_as2_3` | 3 | 1.0s |  |
| 62 | `timeline/timeline_as2_4` | 2 | 0.8s |  |
| 63 | `timeline/timeline_as2_5` | 4 | 0.9s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm1/hitarea` | 2 | 2 | 18.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |

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

**28 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `timeline/timeline_as2_1` | 33.3% | 3/9 | 9 | 3 | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 2 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 20.2% | 22/109 | 109 | 23 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 3 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 14.8% | 8/54 | 54 | 8 |  |
| 4 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 13.7% | 7/51 | 51 | 7 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 5 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 12.8% | 18/141 | 141 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 6 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 12.6% | 16/127 | 127 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 7 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 12.5% | 6/48 | 48 | 6 |  |
| 8 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 11.8% | 6/51 | 51 | 6 |  |
| 9 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 11.7% | 21/179 | 179 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 10 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 11.5% | 14/122 | 122 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 11.5% | 14/122 | 122 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 10.7% | 3/28 | 28 | 3 |  |
| 13 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 10.6% | 25/236 | 236 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 14 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 10.6% | 18/170 | 170 | 31 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 15 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 10.5% | 19/181 | 181 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 16 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 9.5% | 29/305 | 305 | 70 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 17 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 9.2% | 17/185 | 185 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 18 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 9.0% | 17/189 | 189 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 19 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 8.9% | 12/135 | 135 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 20 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 8.7% | 10/115 | 115 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 21 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 7.1% | 10/141 | 141 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 22 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 5.3% | 3/57 | 57 | 3 |  |
| 23 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 4.7% | 13/277 | 277 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 24 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 4.5% | 15/333 | 333 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 25 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 3.7% | 11/296 | 296 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 26 | `avm1/mouse-transparency` | 0.0% | 0/1 | 0 | 1 |  |
| 27 | `avm1/nested-button` | 0.0% | 0/1 | 0 | 1 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 28 | `button3` | 0.0% | 0/1 | 0 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 2 | 1 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 9 | 2 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 1 | 19 |
| | *(tests not in any document)* | 58 | 51 | 7 |
