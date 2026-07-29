# Ruffle Test Results (Filtered)

**Date**: 2026-07-29 03:45 UTC

**Git SHA**: `72fdc5e933`

**Run Duration**: 39m 51s

**Filtered**: 46 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 183 |
| Passing | **148** (80.9%) |
| Ruffle-matched | 8 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **156** (85.2%) |
| Failing | 27 |
| Total expected lines | 1624 |
| Matching lines | 1220 (75.1%) |
| Mismatched lines | 404 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 27 | 100.0% |

## Passing Tests

**148 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `MaskTest` | 0 | 5.4s |  |
| 2 | `MaskTest-2` | 0 | 5.7s |  |
| 3 | `acid/acid` | 1 | 25.4s |  |
| 4 | `acid/acid-big` | 0 | 38.0s |  |
| 5 | `acid/acid-bitmap-draw_quality_high` | 0 | 24.1s |  |
| 6 | `acid/acid-bitmap-draw_quality_low` | 0 | 26.4s |  |
| 7 | `acid/acid-bitmap-fill` | 0 | 22.7s |  |
| 8 | `acid/acid-bitmap-fill-2` | 0 | 3.0s |  |
| 9 | `acid/acid-bitmapData-copyPixels` | 0 | 5.8s |  |
| 10 | `acid/acid-bitmapData-draw` | 0 | 5.7s |  |
| 11 | `acid/acid-bitmaps` | 0 | 25.6s |  |
| 12 | `acid/acid-blend` | 0 | 39.4s |  |
| 13 | `acid/acid-blend-2` | 0 | 20.3s |  |
| 14 | `acid/acid-chars` | 0 | 1.2s |  |
| 15 | `acid/acid-child` | 0 | 20.4s |  |
| 16 | `acid/acid-clip` | 0 | 1.3s |  |
| 17 | `acid/acid-clip-2` | 0 | 1.2s |  |
| 18 | `acid/acid-clip-3` | 0 | 6.0s |  |
| 19 | `acid/acid-color` | 0 | 32.7s |  |
| 20 | `acid/acid-color-0` | 0 | 2.9s |  |
| 21 | `acid/acid-color-2` | 0 | 1.3s |  |
| 22 | `acid/acid-filter-2` | 0 | 1.0s |  |
| 23 | `acid/acid-gc` | 0 | 15.7s |  |
| 24 | `acid/acid-gradient` | 0 | 1.0s |  |
| 25 | `acid/acid-gradient-0` | 0 | 15.8s |  |
| 26 | `acid/acid-gradient-1` | 0 | 1.1s |  |
| 27 | `acid/acid-gradient-2` | 0 | 1.0s |  |
| 28 | `acid/acid-image` | 0 | 21.9s |  |
| 29 | `acid/acid-large` | 0 | 77.2s |  |
| 30 | `acid/acid-mask` | 0 | 6.5s |  |
| 31 | `acid/acid-scale` | 0 | 1.2s |  |
| 32 | `acid/acid-small` | 0 | 1.4s |  |
| 33 | `acid/acid-stroke-0` | 0 | 25.1s |  |
| 34 | `acid/acid-text` | 0 | 1.2s |  |
| 35 | `acid/acid-text-3` | 0 | 1.2s |  |
| 36 | `acid/acid-text-4` | 0 | 5.6s |  |
| 37 | `acid/acid-text-5` | 0 | 24.2s |  |
| 38 | `acid/acid-text-6` | 0 | 19.9s |  |
| 39 | `acid/acid-text-escape` | 0 | 1.2s |  |
| 40 | `acid/acid-textfield-scroll` | 5 | 5.7s |  |
| 41 | `acid/acid-video` | 0 | 20.9s |  |
| 42 | `add` | 11 | 1.2s |  |
| 43 | `as3-loader/LoaderLoadBytesTest2` | 3 | 5.6s |  |
| 44 | `as3-loader/bug1093712/loader` | 1 | 5.7s |  |
| 45 | `as3-loader/loaderinfo/Preloader` | 1 | 5.5s |  |
| 46 | `avm1/array` | 7 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 47 | `avm1/bitmapdata/getPixel` | 2 | 1.2s |  |
| 48 | `avm1/bitmapdata/loadBitmap` | 3 | 1.2s |  |
| 49 | `avm1/callee` | 2 | 1.2s |  |
| 50 | `avm1/depth` | 6 | 1.3s |  |
| 51 | `avm1/doactionorder/doactionorder` | 7 | 1.5s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 52 | `avm1/doactionorder/symbolclass` | 4 | 1.4s |  |
| 53 | `avm1/duplicateMovieClip/dontremove` | 6 | 1.4s |  |
| 54 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 1.3s |  |
| 55 | `avm1/duplicateMovieClip/name-coercion` | 3 | 0.9s |  |
| 56 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.1s |  |
| 57 | `avm1/externalinterface` | 4 | 0.9s |  |
| 58 | `avm1/filters` | 149 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 59 | `avm1/haxe/flocons1` | 2 | 1.0s |  |
| 60 | `avm1/haxe/flocons2` | 3 | 0.9s |  |
| 61 | `avm1/label` | 4 | 1.2s |  |
| 62 | `avm1/levels` | 9 | 1.3s |  |
| 63 | `avm1/loadevent` | 9 | 1.5s |  |
| 64 | `avm1/loadvariables/loadvariables` | 7 | 1.3s |  |
| 65 | `avm1/loadvariables/loadvars` | 2 | 0.2s |  |
| 66 | `avm1/lookup` | 3 | 0.2s |  |
| 67 | `avm1/mouse-transparency` | 1 | 1.4s |  |
| 68 | `avm1/moviecliploader` | 7 | 20.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 69 | `avm1/nativeinheritance` | 6 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 70 | `avm1/nested-button` | 1 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 71 | `avm1/operations` | 13 | 1.2s |  |
| 72 | `avm1/property-paths/property-paths-6` | 6 | 1.1s |  |
| 73 | `avm1/property-paths/property-paths-7` | 7 | 0.9s |  |
| 74 | `avm1/propertycase/propertycase` | 7 | 1.1s |  |
| 75 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.1s |  |
| 76 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.8s |  |
| 77 | `avm1/rollover` | 4 | 1.3s |  |
| 78 | `avm1/scope` | 14 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 79 | `avm1/setinterval` | 20 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 80 | `avm1/settimeout` | 17 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 81 | `avm1/super` | 11 | 1.2s |  |
| 82 | `avm1/target` | 18 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/text-bind` | 0 | 19.9s |  |
| 84 | `avm1/textfield/textfield-html` | 4 | 1.3s |  |
| 85 | `avm1/textfield/textfield-text-setters` | 8 | 1.3s |  |
| 86 | `avm1/undefined/undefined-swf6` | 39 | 1.2s |  |
| 87 | `avm1/undefined/undefined-swf7` | 39 | 0.8s |  |
| 88 | `avm1/watch` | 2 | 1.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 89 | `avm1/xml/xmlbuild` | 1 | 0.5s |  |
| 90 | `avm1/xml/xmlload` | 4 | 1.4s |  |
| 91 | `avm1/xml/xmlstring` | 9 | 1.1s |  |
| 92 | `avm1timeline1` | 3 | 1.3s |  |
| 93 | `avm1timeline2` | 6 | 1.2s |  |
| 94 | `avm2/event-dispatching` | 5 | 5.4s |  |
| 95 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 5.6s |  |
| 96 | `bitmapbuttons` | 0 | 26.3s |  |
| 97 | `bitmapdata/draw-and-read` | 1 | 5.7s |  |
| 98 | `blendmode/blendmode_3` | 2 | 5.4s |  |
| 99 | `button3` | 1 | 1.4s |  |
| 100 | `clipping` | 0 | 0.9s |  |
| 101 | `doubleAndRegister` | 2 | 1.1s |  |
| 102 | `flash_geom_ColorTransform` | 0 | 20.9s |  |
| 103 | `fscommand1` | 1 | 1.0s |  |
| 104 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 19.2s |  |
| 105 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 19.6s |  |
| 106 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.5s |  |
| 107 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 19.6s |  |
| 108 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 17.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 109 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 16.8s |  |
| 110 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 16.6s |  |
| 111 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 16.7s |  |
| 112 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 16.7s |  |
| 113 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 17.0s |  |
| 114 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 17.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 115 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 16.3s |  |
| 116 | `gradient` | 0 | 1.2s |  |
| 117 | `gradientTransform` | 0 | 19.6s |  |
| 118 | `hittesting/mask-hit-test` | 1 | 2.2s |  |
| 119 | `invalidClipDepth` | 0 | 20.6s |  |
| 120 | `mouse/mouse_coords` | 2 | 5.7s |  |
| 121 | `mouse/start_drag` | 3 | 19.2s |  |
| 122 | `mouse/start_drag_lock` | 3 | 4.6s |  |
| 123 | `movieinfo1` | 3 | 1.0s |  |
| 124 | `targetPath1` | 8 | 1.1s |  |
| 125 | `timeline/Timeline3` | 5 | 24.6s |  |
| 126 | `timeline/Timeline4` | 5 | 24.3s |  |
| 127 | `timeline/Timeline8` | 5 | 5.5s |  |
| 128 | `timeline/Timeline9` | 11 | 5.5s |  |
| 129 | `timeline/events/timeline_events_fp10` | 67 | 5.8s |  |
| 130 | `timeline/events/timeline_events_fp9` | 48 | 24.2s |  |
| 131 | `timeline/nav/name` | 8 | 22.8s |  |
| 132 | `timeline/nav/ratio3` | 4 | 0.4s |  |
| 133 | `timeline/nav/shape` | 4 | 4.1s |  |
| 134 | `timeline/scene/EncodedU32` | 1 | 22.6s |  |
| 135 | `timeline/scene/Scene_1_MainTimeline` | 70 | 18.1s |  |
| 136 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 3.9s |  |
| 137 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 4.0s |  |
| 138 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 3.9s |  |
| 139 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 3.6s |  |
| 140 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 4.1s |  |
| 141 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 17.4s |  |
| 142 | `timeline/timeline_as2_1` | 3 | 15.9s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 143 | `timeline/timeline_as2_2` | 3 | 1.0s |  |
| 144 | `timeline/timeline_as2_3` | 3 | 15.9s |  |
| 145 | `timeline/timeline_as2_4` | 2 | 15.7s |  |
| 146 | `timeline/timeline_as2_5` | 4 | 1.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 147 | `timeline/timeline_loop` | 7 | 19.9s |  |
| 148 | `timeline/timeline_name_0` | 13 | 19.3s |  |

## Ruffle-Matched Tests

**8 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-text-x` | 1 | 1 | 5.6s |  |
| 2 | `acid/acid-textfield` | 6 | 7 | 6.0s |  |
| 3 | `as3-loader/LoaderTest` | 2 | 2 | 25.0s |  |
| 4 | `avm1/hitarea` | 2 | 2 | 15.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 5.3s |  |
| 6 | `flash_text_TextField` | 5 | 8 | 23.5s |  |
| 7 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 17.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 18.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**14 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `timeline/nav/matrix` | 87.5% | 7 | 8 | 1 |  |
| 2 | `as3-loader/LoaderTest2` | 85.7% | 6 | 7 | 1 |  |
| 3 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36 | 48 | 12 |  |
| 4 | `timeline/nav/blendMode` | 75.0% | 6 | 8 | 2 |  |
| 5 | `timeline/nav/cacheAsBitmap` | 75.0% | 6 | 8 | 2 |  |
| 6 | `timeline/nav/colorTransform` | 75.0% | 6 | 8 | 2 |  |
| 7 | `timeline/nav/filters` | 75.0% | 6 | 8 | 2 |  |
| 8 | `timeline/nav/morphShape` | 75.0% | 3 | 4 | 1 |  |
| 9 | `timeline/nav/ratio` | 75.0% | 3 | 4 | 1 |  |
| 10 | `timeline/nav/ratio2` | 75.0% | 3 | 4 | 1 |  |
| 11 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 12 | `blendmode/blendmode_1` | 50.0% | 1 | 2 | 1 |  |
| 13 | `blendmode/blendmode_2` | 50.0% | 2 | 4 | 2 |  |
| 14 | `hittesting/hittesting` | 50.0% | 9 | 18 | 9 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**27 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `timeline/nav/matrix` | 87.5% | 7/8 | 8 | 8 |  |
| 2 | `as3-loader/LoaderTest2` | 85.7% | 6/7 | 7 | 7 |  |
| 3 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36/48 | 48 | 48 |  |
| 4 | `timeline/nav/blendMode` | 75.0% | 6/8 | 8 | 8 |  |
| 5 | `timeline/nav/cacheAsBitmap` | 75.0% | 6/8 | 8 | 8 |  |
| 6 | `timeline/nav/colorTransform` | 75.0% | 6/8 | 8 | 8 |  |
| 7 | `timeline/nav/filters` | 75.0% | 6/8 | 8 | 8 |  |
| 8 | `timeline/nav/morphShape` | 75.0% | 3/4 | 4 | 4 |  |
| 9 | `timeline/nav/ratio` | 75.0% | 3/4 | 4 | 4 |  |
| 10 | `timeline/nav/ratio2` | 75.0% | 3/4 | 4 | 4 |  |
| 11 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 12 | `blendmode/blendmode_1` | 50.0% | 1/2 | 2 | 2 |  |
| 13 | `blendmode/blendmode_2` | 50.0% | 2/4 | 3 | 4 |  |
| 14 | `hittesting/hittesting` | 50.0% | 9/18 | 10 | 18 |  |
| 15 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 16 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 17 | `avm2/flash/geom/matrix3d/TransformBasics` | 15.4% | 2/13 | 6 | 13 |  |
| 18 | `as3-loader/events/loader-events` | 13.5% | 5/37 | 37 | 36 |  |
| 19 | `timeline/nav/clipDepth` | 12.5% | 1/8 | 3 | 8 |  |
| 20 | `acid/acid-filter` | 0.0% | 0/2 | 0 | 2 |  |
| 21 | `acid/acid-shapes` | 0.0% | 0/120 | 1 | 120 |  |
| 22 | `acid/acid-text-2` | 0.0% | 0/1 | 1 | 1 |  |
| 23 | `as3-loader/bug1157243/empty` | 0.0% | 0/1 | 0 | 1 |  |
| 24 | `as3-loader/bug1157243/invalid` | 0.0% | 0/1 | 0 | 1 |  |
| 25 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 0.0% | 0/56 | 0 | 56 |  |
| 26 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 0.0% | 0/20 | 0 | 20 |  |
| 27 | `bitmapdata/getpixel-from-embedded` | 0.0% | 0/2 | 2 | 2 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 2 | 2 |
| | *(tests not in any document)* | 165 | 133 | 32 |
