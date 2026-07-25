# Ruffle Test Results (Filtered)

**Date**: 2026-07-25 22:42 UTC

**Git SHA**: `7ad4e04194`

**Run Duration**: 37m 19s

**Filtered**: 46 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 183 |
| Passing | **144** (78.7%) |
| Ruffle-matched | 8 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **152** (83.1%) |
| Failing | 31 |
| Total expected lines | 1624 |
| Matching lines | 1168 (71.9%) |
| Mismatched lines | 456 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 31 | 100.0% |

## Passing Tests

**144 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `MaskTest` | 0 | 3.5s |  |
| 2 | `MaskTest-2` | 0 | 1.7s |  |
| 3 | `acid/acid` | 1 | 8.9s |  |
| 4 | `acid/acid-big` | 0 | 4.9s |  |
| 5 | `acid/acid-bitmap-draw_quality_high` | 0 | 3.5s |  |
| 6 | `acid/acid-bitmap-draw_quality_low` | 0 | 5.3s |  |
| 7 | `acid/acid-bitmap-fill` | 0 | 5.1s |  |
| 8 | `acid/acid-bitmap-fill-2` | 0 | 3.9s |  |
| 9 | `acid/acid-bitmapData-copyPixels` | 0 | 6.2s |  |
| 10 | `acid/acid-bitmapData-draw` | 0 | 6.0s |  |
| 11 | `acid/acid-bitmaps` | 0 | 25.5s |  |
| 12 | `acid/acid-blend` | 0 | 40.7s |  |
| 13 | `acid/acid-blend-2` | 0 | 23.9s |  |
| 14 | `acid/acid-chars` | 0 | 2.4s |  |
| 15 | `acid/acid-child` | 0 | 22.8s |  |
| 16 | `acid/acid-clip` | 0 | 2.6s |  |
| 17 | `acid/acid-clip-2` | 0 | 2.4s |  |
| 18 | `acid/acid-clip-3` | 0 | 7.0s |  |
| 19 | `acid/acid-color` | 0 | 35.5s |  |
| 20 | `acid/acid-color-0` | 0 | 5.6s |  |
| 21 | `acid/acid-color-2` | 0 | 2.4s |  |
| 22 | `acid/acid-filter-2` | 0 | 2.6s |  |
| 23 | `acid/acid-gc` | 0 | 2.4s |  |
| 24 | `acid/acid-gradient` | 0 | 2.4s |  |
| 25 | `acid/acid-gradient-0` | 0 | 22.5s |  |
| 26 | `acid/acid-gradient-1` | 0 | 2.3s |  |
| 27 | `acid/acid-gradient-2` | 0 | 2.3s |  |
| 28 | `acid/acid-image` | 0 | 29.0s |  |
| 29 | `acid/acid-large` | 0 | 77.0s |  |
| 30 | `acid/acid-mask` | 0 | 7.7s |  |
| 31 | `acid/acid-scale` | 0 | 2.3s |  |
| 32 | `acid/acid-small` | 0 | 2.9s |  |
| 33 | `acid/acid-stroke-0` | 0 | 25.6s |  |
| 34 | `acid/acid-text` | 0 | 1.8s |  |
| 35 | `acid/acid-text-3` | 0 | 1.7s |  |
| 36 | `acid/acid-text-4` | 0 | 5.0s |  |
| 37 | `acid/acid-text-5` | 0 | 20.6s |  |
| 38 | `acid/acid-text-6` | 0 | 18.7s |  |
| 39 | `acid/acid-text-escape` | 0 | 1.8s |  |
| 40 | `acid/acid-textfield-scroll` | 5 | 4.6s |  |
| 41 | `acid/acid-video` | 0 | 16.5s |  |
| 42 | `add` | 11 | 0.6s |  |
| 43 | `as3-loader/loaderinfo/Preloader` | 1 | 5.7s |  |
| 44 | `avm1/array` | 7 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 45 | `avm1/bitmapdata/getPixel` | 2 | 0.8s |  |
| 46 | `avm1/bitmapdata/loadBitmap` | 3 | 1.1s |  |
| 47 | `avm1/callee` | 2 | 1.9s |  |
| 48 | `avm1/depth` | 6 | 2.1s |  |
| 49 | `avm1/doactionorder/doactionorder` | 7 | 2.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 50 | `avm1/doactionorder/symbolclass` | 4 | 2.1s |  |
| 51 | `avm1/duplicateMovieClip/dontremove` | 6 | 2.2s |  |
| 52 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.1s |  |
| 53 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.9s |  |
| 54 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.1s |  |
| 55 | `avm1/externalinterface` | 4 | 1.9s |  |
| 56 | `avm1/filters` | 149 | 2.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 57 | `avm1/haxe/flocons1` | 2 | 2.0s |  |
| 58 | `avm1/haxe/flocons2` | 3 | 1.9s |  |
| 59 | `avm1/label` | 4 | 2.2s |  |
| 60 | `avm1/levels` | 9 | 1.9s |  |
| 61 | `avm1/loadevent` | 9 | 2.1s |  |
| 62 | `avm1/loadvariables/loadvariables` | 7 | 1.9s |  |
| 63 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 64 | `avm1/lookup` | 3 | 0.8s |  |
| 65 | `avm1/mouse-transparency` | 1 | 2.1s |  |
| 66 | `avm1/moviecliploader` | 7 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 67 | `avm1/nativeinheritance` | 6 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 68 | `avm1/nested-button` | 1 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 69 | `avm1/operations` | 13 | 2.0s |  |
| 70 | `avm1/property-paths/property-paths-6` | 6 | 1.9s |  |
| 71 | `avm1/property-paths/property-paths-7` | 7 | 1.8s |  |
| 72 | `avm1/propertycase/propertycase` | 7 | 2.0s |  |
| 73 | `avm1/propertycase/propertycase-preserving-6` | 2 | 2.0s |  |
| 74 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.8s |  |
| 75 | `avm1/rollover` | 4 | 2.2s |  |
| 76 | `avm1/scope` | 14 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 77 | `avm1/setinterval` | 20 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 78 | `avm1/settimeout` | 17 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 79 | `avm1/super` | 11 | 2.0s |  |
| 80 | `avm1/target` | 18 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 81 | `avm1/text-bind` | 0 | 21.4s |  |
| 82 | `avm1/textfield/textfield-html` | 4 | 2.2s |  |
| 83 | `avm1/textfield/textfield-text-setters` | 8 | 2.0s |  |
| 84 | `avm1/undefined/undefined-swf6` | 39 | 1.9s |  |
| 85 | `avm1/undefined/undefined-swf7` | 39 | 1.7s |  |
| 86 | `avm1/watch` | 2 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 87 | `avm1/xml/xmlbuild` | 1 | 0.8s |  |
| 88 | `avm1/xml/xmlload` | 4 | 2.4s |  |
| 89 | `avm1/xml/xmlstring` | 9 | 1.9s |  |
| 90 | `avm1timeline1` | 3 | 2.1s |  |
| 91 | `avm1timeline2` | 6 | 2.0s |  |
| 92 | `avm2/event-dispatching` | 5 | 5.7s |  |
| 93 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 6.6s |  |
| 94 | `bitmapbuttons` | 0 | 27.5s |  |
| 95 | `bitmapdata/draw-and-read` | 1 | 5.6s |  |
| 96 | `blendmode/blendmode_3` | 2 | 5.6s |  |
| 97 | `button3` | 1 | 3.2s |  |
| 98 | `clipping` | 0 | 2.1s |  |
| 99 | `doubleAndRegister` | 2 | 2.4s |  |
| 100 | `flash_geom_ColorTransform` | 0 | 24.9s |  |
| 101 | `fscommand1` | 1 | 1.9s |  |
| 102 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 20.9s |  |
| 103 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 21.8s |  |
| 104 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 2.4s |  |
| 105 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 22.1s |  |
| 106 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 22.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 107 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.9s |  |
| 108 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 20.9s |  |
| 109 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 20.2s |  |
| 110 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 20.1s |  |
| 111 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 20.8s |  |
| 112 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 21.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 113 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 22.3s |  |
| 114 | `gradient` | 0 | 2.5s |  |
| 115 | `gradientTransform` | 0 | 22.4s |  |
| 116 | `invalidClipDepth` | 0 | 21.1s |  |
| 117 | `mouse/mouse_coords` | 2 | 5.2s |  |
| 118 | `mouse/start_drag` | 3 | 5.6s |  |
| 119 | `movieinfo1` | 3 | 1.9s |  |
| 120 | `targetPath1` | 8 | 2.0s |  |
| 121 | `timeline/Timeline3` | 5 | 25.5s |  |
| 122 | `timeline/Timeline4` | 5 | 25.3s |  |
| 123 | `timeline/Timeline8` | 5 | 6.0s |  |
| 124 | `timeline/Timeline9` | 11 | 6.0s |  |
| 125 | `timeline/events/timeline_events_fp10` | 67 | 6.3s |  |
| 126 | `timeline/events/timeline_events_fp9` | 48 | 6.4s |  |
| 127 | `timeline/nav/name` | 8 | 0.9s |  |
| 128 | `timeline/nav/ratio3` | 4 | 0.8s |  |
| 129 | `timeline/nav/shape` | 4 | 0.9s |  |
| 130 | `timeline/scene/EncodedU32` | 1 | 0.9s |  |
| 131 | `timeline/scene/Scene_1_MainTimeline` | 70 | 24.2s |  |
| 132 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 5.7s |  |
| 133 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 5.8s |  |
| 134 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 5.6s |  |
| 135 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 5.3s |  |
| 136 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 5.5s |  |
| 137 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 21.3s |  |
| 138 | `timeline/timeline_as2_1` | 3 | 20.6s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 139 | `timeline/timeline_as2_2` | 3 | 1.8s |  |
| 140 | `timeline/timeline_as2_3` | 3 | 1.8s |  |
| 141 | `timeline/timeline_as2_4` | 2 | 1.8s |  |
| 142 | `timeline/timeline_as2_5` | 4 | 3.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 143 | `timeline/timeline_loop` | 7 | 7.5s |  |
| 144 | `timeline/timeline_name_0` | 13 | 5.4s |  |

## Ruffle-Matched Tests

**8 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-text-x` | 1 | 1 | 4.9s |  |
| 2 | `acid/acid-textfield` | 6 | 7 | 4.9s |  |
| 3 | `avm1/hitarea` | 2 | 2 | 21.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 4 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 5.6s |  |
| 5 | `flash_text_TextField` | 5 | 8 | 25.3s |  |
| 6 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 21.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 7 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 21.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `hittesting/mask-hit-test` | 1 | 1 | 3.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**13 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `timeline/nav/matrix` | 87.5% | 7 | 8 | 1 |  |
| 2 | `timeline/nav/blendMode` | 75.0% | 6 | 8 | 2 |  |
| 3 | `timeline/nav/cacheAsBitmap` | 75.0% | 6 | 8 | 2 |  |
| 4 | `timeline/nav/colorTransform` | 75.0% | 6 | 8 | 2 |  |
| 5 | `timeline/nav/filters` | 75.0% | 6 | 8 | 2 |  |
| 6 | `timeline/nav/morphShape` | 75.0% | 3 | 4 | 1 |  |
| 7 | `timeline/nav/ratio` | 75.0% | 3 | 4 | 1 |  |
| 8 | `timeline/nav/ratio2` | 75.0% | 3 | 4 | 1 |  |
| 9 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 10 | `mouse/start_drag_lock` | 66.7% | 2 | 3 | 1 |  |
| 11 | `blendmode/blendmode_1` | 50.0% | 1 | 2 | 1 |  |
| 12 | `blendmode/blendmode_2` | 50.0% | 2 | 4 | 2 |  |
| 13 | `hittesting/hittesting` | 50.0% | 9 | 18 | 9 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**31 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `timeline/nav/matrix` | 87.5% | 7/8 | 8 | 8 |  |
| 2 | `timeline/nav/blendMode` | 75.0% | 6/8 | 8 | 8 |  |
| 3 | `timeline/nav/cacheAsBitmap` | 75.0% | 6/8 | 8 | 8 |  |
| 4 | `timeline/nav/colorTransform` | 75.0% | 6/8 | 8 | 8 |  |
| 5 | `timeline/nav/filters` | 75.0% | 6/8 | 8 | 8 |  |
| 6 | `timeline/nav/morphShape` | 75.0% | 3/4 | 4 | 4 |  |
| 7 | `timeline/nav/ratio` | 75.0% | 3/4 | 4 | 4 |  |
| 8 | `timeline/nav/ratio2` | 75.0% | 3/4 | 4 | 4 |  |
| 9 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 10 | `mouse/start_drag_lock` | 66.7% | 2/3 | 3 | 3 |  |
| 11 | `blendmode/blendmode_1` | 50.0% | 1/2 | 2 | 2 |  |
| 12 | `blendmode/blendmode_2` | 50.0% | 2/4 | 3 | 4 |  |
| 13 | `hittesting/hittesting` | 50.0% | 9/18 | 10 | 18 |  |
| 14 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 15 | `avm2/flash/geom/matrix3d/TransformBasics` | 15.4% | 2/13 | 6 | 13 |  |
| 16 | `as3-loader/LoaderTest2` | 14.3% | 1/7 | 1 | 7 |  |
| 17 | `timeline/nav/clipDepth` | 12.5% | 1/8 | 3 | 8 |  |
| 18 | `as3-loader/LoaderTest` | 11.1% | 1/9 | 1 | 9 |  |
| 19 | `as3-loader/events/loader-events` | 11.1% | 4/36 | 14 | 36 |  |
| 20 | `as3-loader/loaderinfo/loaded-content-properties` | 6.2% | 3/48 | 23 | 48 |  |
| 21 | `acid/acid-filter` | 0.0% | 0/2 | 0 | 2 |  |
| 22 | `acid/acid-shapes` | 0.0% | 0/120 | 1 | 120 |  |
| 23 | `acid/acid-text-2` | 0.0% | 0/1 | 1 | 1 |  |
| 24 | `as3-loader/LoaderLoadBytesTest` | 0.0% | 0/4 | 0 | 4 |  |
| 25 | `as3-loader/LoaderLoadBytesTest2` | 0.0% | 0/3 | 0 | 3 |  |
| 26 | `as3-loader/bug1093712/loader` | 0.0% | 0/1 | 0 | 1 |  |
| 27 | `as3-loader/bug1157243/empty` | 0.0% | 0/1 | 0 | 1 |  |
| 28 | `as3-loader/bug1157243/invalid` | 0.0% | 0/1 | 0 | 1 |  |
| 29 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 0.0% | 0/56 | 0 | 56 |  |
| 30 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 0.0% | 0/20 | 0 | 20 |  |
| 31 | `bitmapdata/getpixel-from-embedded` | 0.0% | 0/2 | 2 | 2 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 2 | 2 |
| | *(tests not in any document)* | 165 | 129 | 36 |
