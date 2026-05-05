# Ruffle Test Results (Filtered)

**Date**: 2026-05-05 23:30 UTC

**Git SHA**: `08e560fe74`

**Run Duration**: 13m 48s

**Filtered**: 0 tests ignored out of 92 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **68** (73.9%) |
| Ruffle-matched | 3 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **71** (77.2%) |
| Failing | 21 |
| Total expected lines | 1276 |
| Matching lines | 687 (53.8%) |
| Mismatched lines | 589 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 21 | 100.0% |

## Passing Tests

**68 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 0.9s |  |
| 2 | `avm1/array` | 7 | 0.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.1s |  |
| 4 | `avm1/bitmapdata/loadBitmap` | 3 | 0.9s |  |
| 5 | `avm1/callee` | 2 | 0.1s |  |
| 6 | `avm1/depth` | 6 | 1.0s |  |
| 7 | `avm1/doactionorder/doactionorder` | 7 | 1.0s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 8 | `avm1/doactionorder/symbolclass` | 4 | 1.1s |  |
| 9 | `avm1/duplicateMovieClip/dontremove` | 6 | 17.4s |  |
| 10 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 0.3s |  |
| 11 | `avm1/duplicateMovieClip/name-coercion` | 3 | 0.3s |  |
| 12 | `avm1/duplicateMovieClip/samedepth` | 6 | 0.3s |  |
| 13 | `avm1/externalinterface` | 4 | 0.3s |  |
| 14 | `avm1/filters` | 149 | 0.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 15 | `avm1/haxe/flocons1` | 2 | 0.2s |  |
| 16 | `avm1/haxe/flocons2` | 3 | 0.2s |  |
| 17 | `avm1/label` | 4 | 18.0s |  |
| 18 | `avm1/levels` | 9 | 0.3s |  |
| 19 | `avm1/loadevent` | 9 | 0.3s |  |
| 20 | `avm1/loadvariables/loadvariables` | 7 | 0.9s |  |
| 21 | `avm1/loadvariables/loadvars` | 2 | 0.6s |  |
| 22 | `avm1/lookup` | 3 | 0.6s |  |
| 23 | `avm1/mouse-transparency` | 1 | 17.7s |  |
| 24 | `avm1/nativeinheritance` | 6 | 1.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 25 | `avm1/nested-button` | 1 | 0.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 26 | `avm1/operations` | 13 | 0.2s |  |
| 27 | `avm1/property-paths/property-paths-6` | 6 | 0.2s |  |
| 28 | `avm1/property-paths/property-paths-7` | 7 | 0.9s |  |
| 29 | `avm1/propertycase/propertycase` | 7 | 1.0s |  |
| 30 | `avm1/propertycase/propertycase-preserving-6` | 2 | 0.8s |  |
| 31 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.8s |  |
| 32 | `avm1/rollover` | 4 | 18.1s |  |
| 33 | `avm1/scope` | 14 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 34 | `avm1/setinterval` | 20 | 0.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 35 | `avm1/settimeout` | 17 | 0.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 36 | `avm1/super` | 11 | 0.3s |  |
| 37 | `avm1/target` | 18 | 0.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 38 | `avm1/text-bind` | 0 | 16.8s |  |
| 39 | `avm1/textfield/textfield-html` | 4 | 0.3s |  |
| 40 | `avm1/textfield/textfield-text-setters` | 8 | 0.9s |  |
| 41 | `avm1/undefined/undefined-swf6` | 39 | 0.9s |  |
| 42 | `avm1/undefined/undefined-swf7` | 39 | 0.3s |  |
| 43 | `avm1/watch` | 2 | 0.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 44 | `avm1/xml/xmlbuild` | 1 | 1.0s |  |
| 45 | `avm1/xml/xmlload` | 4 | 1.1s |  |
| 46 | `avm1/xml/xmlstring` | 9 | 1.0s |  |
| 47 | `avm1timeline1` | 3 | 18.3s |  |
| 48 | `avm1timeline2` | 6 | 1.2s |  |
| 49 | `button3` | 1 | 17.7s |  |
| 50 | `doubleAndRegister` | 2 | 0.3s |  |
| 51 | `fscommand1` | 1 | 0.3s |  |
| 52 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 17.1s |  |
| 53 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 17.4s |  |
| 54 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 17.3s |  |
| 55 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 18.3s |  |
| 56 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 18.2s |  |
| 57 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 18.1s |  |
| 58 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 17.7s |  |
| 59 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 18.0s |  |
| 60 | `gradientTransform` | 0 | 19.0s |  |
| 61 | `invalidClipDepth` | 0 | 19.3s |  |
| 62 | `movieinfo1` | 3 | 1.1s |  |
| 63 | `targetPath1` | 8 | 1.1s |  |
| 64 | `timeline/timeline_as2_1` | 3 | 18.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 65 | `timeline/timeline_as2_2` | 3 | 1.2s |  |
| 66 | `timeline/timeline_as2_3` | 3 | 17.7s |  |
| 67 | `timeline/timeline_as2_4` | 2 | 17.8s |  |
| 68 | `timeline/timeline_as2_5` | 4 | 1.5s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |

## Ruffle-Matched Tests

**3 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm1/hitarea` | 2 | 2 | 14.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 2 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 3 | 17.2s |  |
| 3 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 3 | 17.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10 | 18 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**21 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 2 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 38.5% | 10/26 | 26 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 3 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 33.3% | 12/36 | 36 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 30.2% | 19/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 5 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 21.1% | 8/38 | 38 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 6 | `avm1/moviecliploader` | 14.3% | 1/7 | 6 | 7 | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 7 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 14.3% | 7/49 | 49 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 12.0% | 11/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 9 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 11.1% | 3/27 | 27 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 10 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 10.9% | 6/55 | 55 | 31 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 8.3% | 9/109 | 109 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 7.8% | 10/128 | 128 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 13 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 5.7% | 2/35 | 35 | 23 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 14 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 3.8% | 1/26 | 26 | 5 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 15 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 3.5% | 9/257 | 257 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 16 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 3.3% | 3/92 | 92 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 17 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 3.2% | 5/155 | 155 | 70 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 18 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 2.0% | 1/50 | 50 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 19 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 1.6% | 1/61 | 61 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 20 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 1.0% | 1/100 | 100 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 21 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 0.0% | 0/19 | 19 | 7 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 9 | 2 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 2 | 1 | 1 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/incomplete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 0 | 20 |
| | *(tests not in any document)* | 58 | 56 | 2 |
