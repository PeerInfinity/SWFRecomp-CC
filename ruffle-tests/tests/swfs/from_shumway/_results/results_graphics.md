# Ruffle Test Results (Unfiltered)

**Date**: 2026-06-18 21:40 UTC

**Git SHA**: `fe0030e4fc`

**Run Duration**: 12m 16s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 80 |
| Passing | **65** (81.2%) |
| Ruffle-matched | 2 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **67** (83.8%) |
| Failing | 13 |
| Total expected lines | 1102 |
| Matching lines | 786 (71.3%) |
| Mismatched lines | 316 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 13 | 100.0% |

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

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14 | 19 | 5 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 2 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18 | 32 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 3 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10 | 18 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14 | 28 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 5 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16 | 32 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**13 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14/19 | 19 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 2 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18/32 | 32 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 3 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14/28 | 28 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 5 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16/32 | 32 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 6 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 38.5% | 10/26 | 26 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 7 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 33.3% | 25/75 | 75 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 30.2% | 19/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 9 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 28.0% | 21/75 | 75 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 10 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 27.0% | 17/63 | 63 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 12.0% | 13/108 | 108 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 12.0% | 11/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 13 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 8.7% | 15/173 | 173 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 9 | 9 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 16 | 1 | 15 |
| | *(tests not in any document)* | 52 | 52 | 0 |
