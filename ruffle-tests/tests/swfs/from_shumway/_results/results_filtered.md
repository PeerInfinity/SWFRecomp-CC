# Ruffle Test Results (Filtered)

**Date**: 2026-08-09 08:51 UTC

**Git SHA**: `0a99be1a92`

**Run Duration**: 43m 22s

**Filtered**: 22 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 207 |
| Passing | **189** (91.3%) |
| Ruffle-matched | 9 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **198** (95.7%) |
| Failing | 9 |
| Total expected lines | 1770 |
| Matching lines | 1478 (83.5%) |
| Mismatched lines | 292 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**189 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 26.4s |  |
| 2 | `MaskTest` | 0 | 6.6s |  |
| 3 | `MaskTest-2` | 0 | 6.9s |  |
| 4 | `ZeroClipboardTest` | 3 | 26.5s |  |
| 5 | `acid/acid` | 1 | 29.0s |  |
| 6 | `acid/acid-big` | 0 | 44.8s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 26.5s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 26.2s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 22.0s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 2.9s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 6.7s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 6.6s |  |
| 13 | `acid/acid-bitmaps` | 0 | 25.9s |  |
| 14 | `acid/acid-blend` | 0 | 38.9s |  |
| 15 | `acid/acid-blend-2` | 0 | 20.7s |  |
| 16 | `acid/acid-chars` | 0 | 1.3s |  |
| 17 | `acid/acid-child` | 0 | 20.1s |  |
| 18 | `acid/acid-clip` | 0 | 1.3s |  |
| 19 | `acid/acid-clip-2` | 0 | 1.2s |  |
| 20 | `acid/acid-clip-3` | 0 | 6.7s |  |
| 21 | `acid/acid-color` | 0 | 33.4s |  |
| 22 | `acid/acid-color-0` | 0 | 2.9s |  |
| 23 | `acid/acid-color-2` | 0 | 1.3s |  |
| 24 | `acid/acid-filter` | 2 | 6.6s |  |
| 25 | `acid/acid-filter-2` | 0 | 1.3s |  |
| 26 | `acid/acid-gc` | 0 | 1.5s |  |
| 27 | `acid/acid-gradient` | 0 | 1.3s |  |
| 28 | `acid/acid-gradient-0` | 0 | 19.9s |  |
| 29 | `acid/acid-gradient-1` | 0 | 1.2s |  |
| 30 | `acid/acid-gradient-2` | 0 | 1.3s |  |
| 31 | `acid/acid-image` | 0 | 28.7s |  |
| 32 | `acid/acid-large` | 0 | 76.0s |  |
| 33 | `acid/acid-mask` | 0 | 7.3s |  |
| 34 | `acid/acid-scale` | 0 | 1.3s |  |
| 35 | `acid/acid-small` | 0 | 1.5s |  |
| 36 | `acid/acid-stroke-0` | 0 | 24.9s |  |
| 37 | `acid/acid-text` | 0 | 1.3s |  |
| 38 | `acid/acid-text-2` | 1 | 2.5s |  |
| 39 | `acid/acid-text-3` | 0 | 1.3s |  |
| 40 | `acid/acid-text-4` | 0 | 6.7s |  |
| 41 | `acid/acid-text-5` | 0 | 25.6s |  |
| 42 | `acid/acid-text-6` | 0 | 20.3s |  |
| 43 | `acid/acid-text-escape` | 0 | 1.3s |  |
| 44 | `acid/acid-textfield-scroll` | 5 | 5.3s |  |
| 45 | `acid/acid-video` | 0 | 16.1s |  |
| 46 | `add` | 11 | 1.0s |  |
| 47 | `as3-interfaces` | 6 | 20.0s |  |
| 48 | `as3-loader/LoaderLoadBytesTest2` | 3 | 5.2s |  |
| 49 | `as3-loader/bug1093712/loader` | 1 | 7.0s |  |
| 50 | `as3-loader/bug1157243/empty` | 1 | 6.9s |  |
| 51 | `as3-loader/bug1157243/invalid` | 1 | 6.7s |  |
| 52 | `as3-loader/loaderinfo/Preloader` | 1 | 6.8s |  |
| 53 | `avm1/array` | 7 | 1.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 54 | `avm1/bitmapdata/getPixel` | 2 | 1.2s |  |
| 55 | `avm1/bitmapdata/loadBitmap` | 3 | 1.2s |  |
| 56 | `avm1/callee` | 2 | 1.2s |  |
| 57 | `avm1/depth` | 6 | 1.4s |  |
| 58 | `avm1/doactionorder/doactionorder` | 7 | 1.6s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 59 | `avm1/doactionorder/symbolclass` | 4 | 1.4s |  |
| 60 | `avm1/duplicateMovieClip/dontremove` | 6 | 20.8s |  |
| 61 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 1.4s |  |
| 62 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.0s |  |
| 63 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.3s |  |
| 64 | `avm1/externalinterface` | 4 | 1.1s |  |
| 65 | `avm1/filters` | 149 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 66 | `avm1/haxe/flocons1` | 2 | 1.0s |  |
| 67 | `avm1/haxe/flocons2` | 3 | 1.0s |  |
| 68 | `avm1/label` | 4 | 1.2s |  |
| 69 | `avm1/levels` | 9 | 1.3s |  |
| 70 | `avm1/loadevent` | 9 | 1.4s |  |
| 71 | `avm1/loadvariables/loadvariables` | 7 | 1.2s |  |
| 72 | `avm1/loadvariables/loadvars` | 2 | 0.2s |  |
| 73 | `avm1/lookup` | 3 | 0.2s |  |
| 74 | `avm1/mouse-transparency` | 1 | 1.3s |  |
| 75 | `avm1/moviecliploader` | 7 | 19.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 76 | `avm1/nativeinheritance` | 6 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 77 | `avm1/nested-button` | 1 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 78 | `avm1/operations` | 13 | 1.3s |  |
| 79 | `avm1/property-paths/property-paths-6` | 6 | 1.2s |  |
| 80 | `avm1/property-paths/property-paths-7` | 7 | 0.9s |  |
| 81 | `avm1/propertycase/propertycase` | 7 | 1.2s |  |
| 82 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.2s |  |
| 83 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.9s |  |
| 84 | `avm1/rollover` | 4 | 1.4s |  |
| 85 | `avm1/scope` | 14 | 1.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 86 | `avm1/setinterval` | 20 | 1.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 87 | `avm1/settimeout` | 17 | 1.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 88 | `avm1/super` | 11 | 1.1s |  |
| 89 | `avm1/target` | 18 | 1.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 90 | `avm1/text-bind` | 0 | 19.9s |  |
| 91 | `avm1/textfield/textfield-html` | 4 | 1.2s |  |
| 92 | `avm1/textfield/textfield-text-setters` | 8 | 1.2s |  |
| 93 | `avm1/undefined/undefined-swf6` | 39 | 1.1s |  |
| 94 | `avm1/undefined/undefined-swf7` | 39 | 0.8s |  |
| 95 | `avm1/watch` | 2 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 96 | `avm1/xml/xmlbuild` | 1 | 1.0s |  |
| 97 | `avm1/xml/xmlload` | 4 | 1.3s |  |
| 98 | `avm1/xml/xmlstring` | 9 | 1.1s |  |
| 99 | `avm1timeline1` | 3 | 1.2s |  |
| 100 | `avm1timeline2` | 6 | 1.0s |  |
| 101 | `avm2/event-dispatching` | 5 | 5.2s |  |
| 102 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 5.5s |  |
| 103 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 22.3s |  |
| 104 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 5.3s |  |
| 105 | `bitmapbuttons` | 0 | 25.9s |  |
| 106 | `bitmapdata/draw-and-read` | 1 | 6.6s |  |
| 107 | `blendmode/blendmode_1` | 2 | 25.4s |  |
| 108 | `blendmode/blendmode_2` | 4 | 6.7s |  |
| 109 | `blendmode/blendmode_3` | 2 | 6.6s |  |
| 110 | `button1` | 1 | 2.7s |  |
| 111 | `button2` | 1 | 6.8s |  |
| 112 | `button3` | 1 | 1.5s |  |
| 113 | `captions` | 8 | 6.8s |  |
| 114 | `clipping` | 0 | 1.3s |  |
| 115 | `doubleAndRegister` | 2 | 1.5s |  |
| 116 | `encoding1` | 31 | 6.6s |  |
| 117 | `flash_events_Event` | 3 | 25.4s |  |
| 118 | `flash_geom_ColorTransform` | 0 | 6.5s |  |
| 119 | `flash_net_URLLoader` | 7 | 7.0s |  |
| 120 | `flash_net_URLRequest` | 6 | 6.8s |  |
| 121 | `flash_net_classes` | 22 | 7.1s |  |
| 122 | `flash_utils_Timer` | 2 | 6.7s |  |
| 123 | `fscommand1` | 1 | 1.3s |  |
| 124 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 21.0s |  |
| 125 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 15.5s |  |
| 126 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.2s |  |
| 127 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 15.5s |  |
| 128 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 129 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.1s |  |
| 130 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 20.0s |  |
| 131 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 19.4s |  |
| 132 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 19.5s |  |
| 133 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 19.6s |  |
| 134 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 19.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 135 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 20.2s |  |
| 136 | `gradient` | 0 | 1.3s |  |
| 137 | `gradientTransform` | 0 | 20.4s |  |
| 138 | `hardwrap` | 1 | 6.8s |  |
| 139 | `hitTestStyleChange` | 1 | 25.3s |  |
| 140 | `hittesting/hittesting` | 18 | 6.6s |  |
| 141 | `hittesting/mask-hit-test` | 1 | 2.5s |  |
| 142 | `image-loading` | 4 | 6.6s |  |
| 143 | `invalidClipDepth` | 0 | 21.2s |  |
| 144 | `local2global` | 1 | 6.6s |  |
| 145 | `localconnection` | 12 | 7.2s |  |
| 146 | `lzma` | 5 | 6.5s |  |
| 147 | `lzma_bytes` | 2 | 25.5s |  |
| 148 | `mouse/mouse_coords` | 2 | 6.6s |  |
| 149 | `mouse/start_drag` | 3 | 26.1s |  |
| 150 | `mouse/start_drag_lock` | 3 | 6.5s |  |
| 151 | `movieclip` | 9 | 6.5s |  |
| 152 | `movieinfo1` | 3 | 1.3s |  |
| 153 | `slider_component` | 4 | 12.2s |  |
| 154 | `stream1` | 9 | 6.6s |  |
| 155 | `stroke1` | 1 | 6.6s |  |
| 156 | `stylesheet` | 3 | 6.8s |  |
| 157 | `targetPath1` | 8 | 1.3s |  |
| 158 | `timeline/Timeline3` | 5 | 26.3s |  |
| 159 | `timeline/Timeline4` | 5 | 25.8s |  |
| 160 | `timeline/Timeline8` | 5 | 6.9s |  |
| 161 | `timeline/Timeline9` | 11 | 6.9s |  |
| 162 | `timeline/events/timeline_events_fp10` | 67 | 7.1s |  |
| 163 | `timeline/events/timeline_events_fp9` | 48 | 26.2s |  |
| 164 | `timeline/nav/blendMode` | 8 | 25.7s |  |
| 165 | `timeline/nav/cacheAsBitmap` | 8 | 6.4s |  |
| 166 | `timeline/nav/colorTransform` | 8 | 6.6s |  |
| 167 | `timeline/nav/filters` | 8 | 6.3s |  |
| 168 | `timeline/nav/matrix` | 8 | 6.4s |  |
| 169 | `timeline/nav/morphShape` | 4 | 25.3s |  |
| 170 | `timeline/nav/name` | 8 | 25.1s |  |
| 171 | `timeline/nav/ratio` | 4 | 6.3s |  |
| 172 | `timeline/nav/ratio2` | 4 | 6.2s |  |
| 173 | `timeline/nav/ratio3` | 4 | 0.5s |  |
| 174 | `timeline/nav/shape` | 4 | 6.2s |  |
| 175 | `timeline/scene/EncodedU32` | 1 | 25.2s |  |
| 176 | `timeline/scene/Scene_1_MainTimeline` | 70 | 25.1s |  |
| 177 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 6.6s |  |
| 178 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 6.5s |  |
| 179 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 6.4s |  |
| 180 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 6.0s |  |
| 181 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 6.4s |  |
| 182 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 24.7s |  |
| 183 | `timeline/timeline_as2_1` | 3 | 20.1s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 184 | `timeline/timeline_as2_2` | 3 | 1.3s |  |
| 185 | `timeline/timeline_as2_3` | 3 | 20.2s |  |
| 186 | `timeline/timeline_as2_4` | 2 | 20.1s |  |
| 187 | `timeline/timeline_as2_5` | 4 | 1.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 188 | `timeline/timeline_loop` | 7 | 26.1s |  |
| 189 | `timeline/timeline_name_0` | 13 | 25.2s |  |

## Ruffle-Matched Tests

**9 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-text-x` | 1 | 1 | 6.6s |  |
| 2 | `acid/acid-textfield` | 6 | 7 | 5.5s |  |
| 3 | `as3-loader/LoaderTest` | 2 | 2 | 20.1s |  |
| 4 | `avm1/hitarea` | 2 | 2 | 16.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 5.2s |  |
| 6 | `flash_text_TextField` | 5 | 8 | 26.6s |  |
| 7 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 20.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 21.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 9 | `timeline/nav/clipDepth` | 4 | 4 | 6.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**4 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `as3-loader/LoaderTest2` | 85.7% | 6 | 7 | 1 |  |
| 2 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36 | 48 | 12 |  |
| 3 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 4 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**9 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `as3-loader/LoaderTest2` | 85.7% | 6/7 | 7 | 7 |  |
| 2 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36/48 | 48 | 48 |  |
| 3 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 4 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1/2 | 2 | 2 |  |
| 5 | `avm2/flash/geom/matrix3d/TransformBasics` | 38.5% | 5/13 | 11 | 13 |  |
| 6 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 7 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 8 | `as3-loader/events/loader-events` | 13.5% | 5/37 | 37 | 36 |  |
| 9 | `acid/acid-shapes` | 0.0% | 0/120 | 7 | 120 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 2 | 2 |
| | *(tests not in any document)* | 189 | 174 | 15 |
