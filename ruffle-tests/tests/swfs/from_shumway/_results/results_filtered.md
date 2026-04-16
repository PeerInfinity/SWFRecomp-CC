# Ruffle Test Results (Filtered)

**Date**: 2026-04-16 18:14 UTC

**Git SHA**: `fa59f33642`

**Run Duration**: 0m 21s

**Filtered**: 0 tests ignored out of 92 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 92 |
| Passing | **48** (52.2%) |
| Ruffle-matched | 1 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **49** (53.3%) |
| Failing | 43 |
| Total expected lines | 1276 |
| Matching lines | 628 (49.2%) |
| Mismatched lines | 648 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 43 | 100.0% |

## Passing Tests

**48 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `add` | 11 | 0.1s |  |
| 2 | `avm1/array` | 7 | 0.1s |  |
| 3 | `avm1/bitmapdata/getPixel` | 2 | 0.1s |  |
| 4 | `avm1/callee` | 2 | 0.1s |  |
| 5 | `avm1/depth` | 6 | 0.2s |  |
| 6 | `avm1/doactionorder/symbolclass` | 4 | 0.1s |  |
| 7 | `avm1/externalinterface` | 4 | 0.1s |  |
| 8 | `avm1/filters` | 149 | 0.1s |  |
| 9 | `avm1/haxe/flocons1` | 2 | 0.3s |  |
| 10 | `avm1/label` | 4 | 0.1s |  |
| 11 | `avm1/levels` | 9 | 0.1s |  |
| 12 | `avm1/loadevent` | 9 | 0.1s |  |
| 13 | `avm1/loadvariables/loadvariables` | 7 | 0.1s |  |
| 14 | `avm1/lookup` | 3 | 0.1s |  |
| 15 | `avm1/mouse-transparency` | 1 | 0.1s |  |
| 16 | `avm1/nativeinheritance` | 6 | 0.1s |  |
| 17 | `avm1/nested-button` | 1 | 0.3s |  |
| 18 | `avm1/operations` | 13 | 0.1s |  |
| 19 | `avm1/property-paths/property-paths-7` | 7 | 0.1s |  |
| 20 | `avm1/propertycase/propertycase` | 7 | 0.1s |  |
| 21 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.1s |  |
| 22 | `avm1/rollover` | 4 | 0.1s |  |
| 23 | `avm1/scope` | 14 | 0.1s |  |
| 24 | `avm1/setinterval` | 20 | 0.1s |  |
| 25 | `avm1/settimeout` | 17 | 0.1s |  |
| 26 | `avm1/super` | 11 | 0.1s |  |
| 27 | `avm1/target` | 18 | 0.1s |  |
| 28 | `avm1/text-bind` | 0 | 0.1s |  |
| 29 | `avm1/undefined/undefined-swf6` | 39 | 0.1s |  |
| 30 | `avm1/undefined/undefined-swf7` | 39 | 0.1s |  |
| 31 | `avm1/watch` | 2 | 0.1s |  |
| 32 | `avm1/xml/xmlbuild` | 1 | 0.1s |  |
| 33 | `avm1/xml/xmlstring` | 9 | 0.1s |  |
| 34 | `avm1timeline1` | 3 | 0.1s |  |
| 35 | `avm1timeline2` | 6 | 0.1s |  |
| 36 | `button3` | 1 | 0.1s |  |
| 37 | `doubleAndRegister` | 2 | 0.1s |  |
| 38 | `fscommand1` | 1 | 0.1s |  |
| 39 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 0.1s |  |
| 40 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 0.1s |  |
| 41 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 0.1s |  |
| 42 | `gradientTransform` | 0 | 0.1s |  |
| 43 | `invalidClipDepth` | 0 | 0.1s |  |
| 44 | `movieinfo1` | 3 | 0.1s |  |
| 45 | `targetPath1` | 8 | 0.1s |  |
| 46 | `timeline/timeline_as2_2` | 3 | 0.1s |  |
| 47 | `timeline/timeline_as2_3` | 3 | 0.1s |  |
| 48 | `timeline/timeline_as2_4` | 2 | 0.1s |  |

## Ruffle-Matched Tests

**1 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `avm1/hitarea` | 2 | 2 | 0.4s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**6 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm1/property-paths/property-paths-6` | 83.3% | 5 | 6 | 1 |  |
| 2 | `avm1/textfield/textfield-html` | 75.0% | 3 | 4 | 1 |  |
| 3 | `avm1/duplicateMovieClip/samedepth` | 66.7% | 4 | 6 | 2 |  |
| 4 | `avm1/haxe/flocons2` | 66.7% | 2 | 3 | 1 |  |
| 5 | `avm1/duplicateMovieClip/dontremove` | 50.0% | 3 | 6 | 3 |  |
| 6 | `avm1/textfield/textfield-text-setters` | 50.0% | 4 | 8 | 4 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**43 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm1/property-paths/property-paths-6` | 83.3% | 5/6 | 6 | 6 |  |
| 2 | `avm1/textfield/textfield-html` | 75.0% | 3/4 | 4 | 4 |  |
| 3 | `avm1/duplicateMovieClip/samedepth` | 66.7% | 4/6 | 6 | 6 |  |
| 4 | `avm1/haxe/flocons2` | 66.7% | 2/3 | 3 | 3 |  |
| 5 | `avm1/duplicateMovieClip/dontremove` | 50.0% | 3/6 | 6 | 6 |  |
| 6 | `avm1/textfield/textfield-text-setters` | 50.0% | 4/8 | 8 | 8 |  |
| 7 | `avm1/doactionorder/doactionorder` | 42.9% | 3/7 | 7 | 7 |  |
| 8 | `avm1/duplicateMovieClip/name-coercion` | 33.3% | 1/3 | 3 | 3 |  |
| 9 | `avm1/duplicateMovieClip/duplicateMovieClip` | 25.0% | 1/4 | 4 | 4 |  |
| 10 | `timeline/timeline_as2_5` | 25.0% | 1/4 | 3 | 4 |  |
| 11 | `avm1/moviecliploader` | 14.3% | 1/7 | 6 | 7 |  |
| 12 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 10.7% | 3/28 | 28 | 3 |  |
| 13 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 9.3% | 5/54 | 54 | 8 |  |
| 14 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 7.8% | 4/51 | 51 | 6 |  |
| 15 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 6.7% | 9/135 | 135 | 29 |  |
| 16 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 6.6% | 12/181 | 181 | 43 |  |
| 17 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6.2% | 3/48 | 48 | 6 |  |
| 18 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 5.2% | 6/115 | 115 | 16 |  |
| 19 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 5.0% | 7/141 | 141 | 24 |  |
| 20 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 4.2% | 9/213 | 213 | 35 |  |
| 21 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 4.0% | 1/25 | 25 | 1 |  |
| 22 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 3.7% | 11/296 | 296 | 48 |  |
| 23 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 3.2% | 7/220 | 220 | 31 |  |
| 24 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 3.1% | 8/261 | 261 | 57 |  |
| 25 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 2.7% | 6/222 | 222 | 50 |  |
| 26 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 2.6% | 12/462 | 462 | 71 |  |
| 27 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 2.3% | 1/44 | 44 | 3 |  |
| 28 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 2.2% | 3/139 | 139 | 23 |  |
| 29 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 1.9% | 3/157 | 157 | 19 |  |
| 30 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 1.7% | 3/181 | 181 | 25 |  |
| 31 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 1.6% | 3/184 | 184 | 22 |  |
| 32 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 1.6% | 5/310 | 310 | 67 |  |
| 33 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 1.4% | 6/435 | 435 | 70 |  |
| 34 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 1.3% | 2/157 | 157 | 26 |  |
| 35 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 1.1% | 3/278 | 278 | 37 |  |
| 36 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 0.6% | 1/180 | 180 | 5 |  |
| 37 | `avm1/bitmapdata/loadBitmap` | 0.0% | 0/3 | 3 | 3 |  |
| 38 | `avm1/loadvariables/loadvars` | 0.0% | 0/2 | 0 | 2 |  |
| 39 | `avm1/propertycase/propertycase-preserving-6` | 0.0% | 0/4 | 4 | 2 |  |
| 40 | `avm1/xml/xmlload` | 0.0% | 0/4 | 3 | 4 |  |
| 41 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 0.0% | 0/127 | 127 | 7 |  |
| 42 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 0.0% | 0/73 | 73 | 3 |  |
| 43 | `timeline/timeline_as2_1` | 0.0% | 0/3 | 0 | 3 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 0 | 0 | 0 |
| | *(tests not in any document)* | 92 | 48 | 44 |
