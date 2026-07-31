# Ruffle Test Results (Filtered)

**Date**: 2026-07-31 20:48 UTC

**Git SHA**: `16343c6e1b`

**Run Duration**: 42m 23s

**Filtered**: 46 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 183 |
| Passing | **159** (86.9%) |
| Ruffle-matched | 9 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **168** (91.8%) |
| Failing | 15 |
| Total expected lines | 1624 |
| Matching lines | 1318 (81.2%) |
| Mismatched lines | 306 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 15 | 100.0% |

## Passing Tests

**159 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `MaskTest` | 0 | 6.9s |  |
| 2 | `MaskTest-2` | 0 | 3.2s |  |
| 3 | `acid/acid` | 1 | 35.8s |  |
| 4 | `acid/acid-big` | 0 | 44.3s |  |
| 5 | `acid/acid-bitmap-draw_quality_high` | 0 | 26.3s |  |
| 6 | `acid/acid-bitmap-draw_quality_low` | 0 | 27.1s |  |
| 7 | `acid/acid-bitmap-fill` | 0 | 24.7s |  |
| 8 | `acid/acid-bitmap-fill-2` | 0 | 4.3s |  |
| 9 | `acid/acid-bitmapData-copyPixels` | 0 | 8.0s |  |
| 10 | `acid/acid-bitmapData-draw` | 0 | 7.7s |  |
| 11 | `acid/acid-bitmaps` | 0 | 27.1s |  |
| 12 | `acid/acid-blend` | 0 | 40.9s |  |
| 13 | `acid/acid-blend-2` | 0 | 24.3s |  |
| 14 | `acid/acid-chars` | 0 | 1.6s |  |
| 15 | `acid/acid-child` | 0 | 15.8s |  |
| 16 | `acid/acid-clip` | 0 | 1.6s |  |
| 17 | `acid/acid-clip-2` | 0 | 1.5s |  |
| 18 | `acid/acid-clip-3` | 0 | 5.6s |  |
| 19 | `acid/acid-color` | 0 | 27.4s |  |
| 20 | `acid/acid-color-0` | 0 | 3.4s |  |
| 21 | `acid/acid-color-2` | 0 | 1.9s |  |
| 22 | `acid/acid-filter` | 2 | 8.0s |  |
| 23 | `acid/acid-filter-2` | 0 | 2.7s |  |
| 24 | `acid/acid-gc` | 0 | 2.5s |  |
| 25 | `acid/acid-gradient` | 0 | 2.5s |  |
| 26 | `acid/acid-gradient-0` | 0 | 22.8s |  |
| 27 | `acid/acid-gradient-1` | 0 | 2.4s |  |
| 28 | `acid/acid-gradient-2` | 0 | 2.4s |  |
| 29 | `acid/acid-image` | 0 | 30.8s |  |
| 30 | `acid/acid-large` | 0 | 76.7s |  |
| 31 | `acid/acid-mask` | 0 | 9.2s |  |
| 32 | `acid/acid-scale` | 0 | 2.4s |  |
| 33 | `acid/acid-small` | 0 | 3.0s |  |
| 34 | `acid/acid-stroke-0` | 0 | 27.2s |  |
| 35 | `acid/acid-text` | 0 | 2.2s |  |
| 36 | `acid/acid-text-3` | 0 | 2.1s |  |
| 37 | `acid/acid-text-4` | 0 | 7.6s |  |
| 38 | `acid/acid-text-5` | 0 | 27.6s |  |
| 39 | `acid/acid-text-6` | 0 | 23.7s |  |
| 40 | `acid/acid-text-escape` | 0 | 2.2s |  |
| 41 | `acid/acid-textfield-scroll` | 5 | 7.5s |  |
| 42 | `acid/acid-video` | 0 | 24.3s |  |
| 43 | `add` | 11 | 1.9s |  |
| 44 | `as3-loader/LoaderLoadBytesTest2` | 3 | 7.2s |  |
| 45 | `as3-loader/bug1093712/loader` | 1 | 5.8s |  |
| 46 | `as3-loader/loaderinfo/Preloader` | 1 | 5.6s |  |
| 47 | `avm1/array` | 7 | 1.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 48 | `avm1/bitmapdata/getPixel` | 2 | 2.0s |  |
| 49 | `avm1/bitmapdata/loadBitmap` | 3 | 2.1s |  |
| 50 | `avm1/callee` | 2 | 1.9s |  |
| 51 | `avm1/depth` | 6 | 2.1s |  |
| 52 | `avm1/doactionorder/doactionorder` | 7 | 2.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 53 | `avm1/doactionorder/symbolclass` | 4 | 2.2s |  |
| 54 | `avm1/duplicateMovieClip/dontremove` | 6 | 2.2s |  |
| 55 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.2s |  |
| 56 | `avm1/duplicateMovieClip/name-coercion` | 3 | 2.0s |  |
| 57 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.1s |  |
| 58 | `avm1/externalinterface` | 4 | 2.0s |  |
| 59 | `avm1/filters` | 149 | 2.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 60 | `avm1/haxe/flocons1` | 2 | 2.1s |  |
| 61 | `avm1/haxe/flocons2` | 3 | 2.0s |  |
| 62 | `avm1/label` | 4 | 2.3s |  |
| 63 | `avm1/levels` | 9 | 1.6s |  |
| 64 | `avm1/loadevent` | 9 | 1.8s |  |
| 65 | `avm1/loadvariables/loadvariables` | 7 | 1.6s |  |
| 66 | `avm1/loadvariables/loadvars` | 2 | 0.7s |  |
| 67 | `avm1/lookup` | 3 | 0.7s |  |
| 68 | `avm1/mouse-transparency` | 1 | 1.7s |  |
| 69 | `avm1/moviecliploader` | 7 | 1.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 70 | `avm1/nativeinheritance` | 6 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 71 | `avm1/nested-button` | 1 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 72 | `avm1/operations` | 13 | 2.1s |  |
| 73 | `avm1/property-paths/property-paths-6` | 6 | 2.0s |  |
| 74 | `avm1/property-paths/property-paths-7` | 7 | 1.8s |  |
| 75 | `avm1/propertycase/propertycase` | 7 | 2.0s |  |
| 76 | `avm1/propertycase/propertycase-preserving-6` | 2 | 2.0s |  |
| 77 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.8s |  |
| 78 | `avm1/rollover` | 4 | 2.2s |  |
| 79 | `avm1/scope` | 14 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 80 | `avm1/setinterval` | 20 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 81 | `avm1/settimeout` | 17 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 82 | `avm1/super` | 11 | 2.1s |  |
| 83 | `avm1/target` | 18 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 84 | `avm1/text-bind` | 0 | 23.4s |  |
| 85 | `avm1/textfield/textfield-html` | 4 | 2.2s |  |
| 86 | `avm1/textfield/textfield-text-setters` | 8 | 2.2s |  |
| 87 | `avm1/undefined/undefined-swf6` | 39 | 2.1s |  |
| 88 | `avm1/undefined/undefined-swf7` | 39 | 1.8s |  |
| 89 | `avm1/watch` | 2 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 90 | `avm1/xml/xmlbuild` | 1 | 0.8s |  |
| 91 | `avm1/xml/xmlload` | 4 | 2.4s |  |
| 92 | `avm1/xml/xmlstring` | 9 | 2.0s |  |
| 93 | `avm1timeline1` | 3 | 2.1s |  |
| 94 | `avm1timeline2` | 6 | 2.2s |  |
| 95 | `avm2/event-dispatching` | 5 | 7.6s |  |
| 96 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 8.4s |  |
| 97 | `bitmapbuttons` | 0 | 29.8s |  |
| 98 | `bitmapdata/draw-and-read` | 1 | 7.2s |  |
| 99 | `blendmode/blendmode_1` | 2 | 25.9s |  |
| 100 | `blendmode/blendmode_2` | 4 | 7.3s |  |
| 101 | `blendmode/blendmode_3` | 2 | 7.2s |  |
| 102 | `button3` | 1 | 3.2s |  |
| 103 | `clipping` | 0 | 1.9s |  |
| 104 | `doubleAndRegister` | 2 | 2.0s |  |
| 105 | `flash_geom_ColorTransform` | 0 | 6.5s |  |
| 106 | `fscommand1` | 1 | 1.9s |  |
| 107 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 20.8s |  |
| 108 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 16.3s |  |
| 109 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.8s |  |
| 110 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 16.4s |  |
| 111 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 23.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 112 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 22.4s |  |
| 113 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 22.3s |  |
| 114 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 20.9s |  |
| 115 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 21.3s |  |
| 116 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 21.1s |  |
| 117 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 21.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 118 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 20.7s |  |
| 119 | `gradient` | 0 | 2.4s |  |
| 120 | `gradientTransform` | 0 | 21.6s |  |
| 121 | `hittesting/mask-hit-test` | 1 | 3.3s |  |
| 122 | `invalidClipDepth` | 0 | 21.5s |  |
| 123 | `mouse/mouse_coords` | 2 | 7.0s |  |
| 124 | `mouse/start_drag` | 3 | 26.6s |  |
| 125 | `mouse/start_drag_lock` | 3 | 7.5s |  |
| 126 | `movieinfo1` | 3 | 2.1s |  |
| 127 | `targetPath1` | 8 | 2.0s |  |
| 128 | `timeline/Timeline3` | 5 | 26.6s |  |
| 129 | `timeline/Timeline4` | 5 | 26.6s |  |
| 130 | `timeline/Timeline8` | 5 | 7.6s |  |
| 131 | `timeline/Timeline9` | 11 | 7.6s |  |
| 132 | `timeline/events/timeline_events_fp10` | 67 | 7.9s |  |
| 133 | `timeline/events/timeline_events_fp9` | 48 | 7.6s |  |
| 134 | `timeline/nav/blendMode` | 8 | 7.2s |  |
| 135 | `timeline/nav/cacheAsBitmap` | 8 | 7.2s |  |
| 136 | `timeline/nav/colorTransform` | 8 | 7.1s |  |
| 137 | `timeline/nav/filters` | 8 | 7.0s |  |
| 138 | `timeline/nav/matrix` | 8 | 7.0s |  |
| 139 | `timeline/nav/morphShape` | 4 | 1.0s |  |
| 140 | `timeline/nav/name` | 8 | 1.0s |  |
| 141 | `timeline/nav/ratio` | 4 | 1.0s |  |
| 142 | `timeline/nav/ratio2` | 4 | 1.0s |  |
| 143 | `timeline/nav/ratio3` | 4 | 1.0s |  |
| 144 | `timeline/nav/shape` | 4 | 1.0s |  |
| 145 | `timeline/scene/EncodedU32` | 1 | 1.0s |  |
| 146 | `timeline/scene/Scene_1_MainTimeline` | 70 | 27.6s |  |
| 147 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 7.7s |  |
| 148 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 7.8s |  |
| 149 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 7.6s |  |
| 150 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 7.4s |  |
| 151 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 7.7s |  |
| 152 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 22.6s |  |
| 153 | `timeline/timeline_as2_1` | 3 | 20.5s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 154 | `timeline/timeline_as2_2` | 3 | 2.0s |  |
| 155 | `timeline/timeline_as2_3` | 3 | 2.0s |  |
| 156 | `timeline/timeline_as2_4` | 2 | 2.0s |  |
| 157 | `timeline/timeline_as2_5` | 4 | 4.1s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 158 | `timeline/timeline_loop` | 7 | 9.4s |  |
| 159 | `timeline/timeline_name_0` | 13 | 7.2s |  |

## Ruffle-Matched Tests

**9 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-text-x` | 1 | 1 | 7.5s |  |
| 2 | `acid/acid-textfield` | 6 | 7 | 7.8s |  |
| 3 | `as3-loader/LoaderTest` | 2 | 2 | 26.2s |  |
| 4 | `avm1/hitarea` | 2 | 2 | 21.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 7.3s |  |
| 6 | `flash_text_TextField` | 5 | 8 | 26.6s |  |
| 7 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 23.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 23.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 9 | `timeline/nav/clipDepth` | 4 | 4 | 7.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**7 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 91.1% | 51 | 56 | 5 |  |
| 2 | `hittesting/hittesting` | 88.9% | 16 | 18 | 2 |  |
| 3 | `as3-loader/LoaderTest2` | 85.7% | 6 | 7 | 1 |  |
| 4 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 80.0% | 16 | 20 | 4 |  |
| 5 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36 | 48 | 12 |  |
| 6 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 7 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**15 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 91.1% | 51/56 | 56 | 56 |  |
| 2 | `hittesting/hittesting` | 88.9% | 16/18 | 18 | 18 |  |
| 3 | `as3-loader/LoaderTest2` | 85.7% | 6/7 | 7 | 7 |  |
| 4 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 80.0% | 16/20 | 20 | 20 |  |
| 5 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36/48 | 48 | 48 |  |
| 6 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 7 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1/2 | 2 | 2 |  |
| 8 | `avm2/flash/geom/matrix3d/TransformBasics` | 38.5% | 5/13 | 9 | 13 |  |
| 9 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 10 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 11 | `as3-loader/events/loader-events` | 13.5% | 5/37 | 37 | 36 |  |
| 12 | `acid/acid-shapes` | 0.0% | 0/120 | 1 | 120 |  |
| 13 | `acid/acid-text-2` | 0.0% | 0/1 | 1 | 1 |  |
| 14 | `as3-loader/bug1157243/empty` | 0.0% | 0/1 | 0 | 1 |  |
| 15 | `as3-loader/bug1157243/invalid` | 0.0% | 0/1 | 0 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 2 | 2 |
| | *(tests not in any document)* | 165 | 144 | 21 |
