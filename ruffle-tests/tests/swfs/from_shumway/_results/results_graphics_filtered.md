# Ruffle Test Results (Filtered)

**Date**: 2026-08-13 22:38 UTC

**Git SHA**: `3db858cbc1`

**Run Duration**: 46m 54s

**Filtered**: 22 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 207 |
| Passing | **191** (92.3%) |
| Ruffle-matched | 7 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **198** (95.7%) |
| Failing | 9 |
| Total expected lines | 1770 |
| Matching lines | 1492 (84.3%) |
| Mismatched lines | 278 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 9 | 100.0% |

## Passing Tests

**191 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 20.2s |  |
| 2 | `MaskTest` | 0 | 5.7s |  |
| 3 | `MaskTest-2` | 0 | 6.0s |  |
| 4 | `ZeroClipboardTest` | 3 | 19.9s |  |
| 5 | `acid/acid` | 1 | 26.2s |  |
| 6 | `acid/acid-big` | 0 | 34.0s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 20.6s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 28.8s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 23.1s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 4.0s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 8.0s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 7.9s |  |
| 13 | `acid/acid-bitmaps` | 0 | 26.8s |  |
| 14 | `acid/acid-blend` | 0 | 39.9s |  |
| 15 | `acid/acid-blend-2` | 0 | 24.0s |  |
| 16 | `acid/acid-chars` | 0 | 2.3s |  |
| 17 | `acid/acid-child` | 0 | 21.3s |  |
| 18 | `acid/acid-clip` | 0 | 2.5s |  |
| 19 | `acid/acid-clip-2` | 0 | 2.3s |  |
| 20 | `acid/acid-clip-3` | 0 | 8.3s |  |
| 21 | `acid/acid-color` | 0 | 35.5s |  |
| 22 | `acid/acid-color-0` | 0 | 24.0s |  |
| 23 | `acid/acid-color-2` | 0 | 2.3s |  |
| 24 | `acid/acid-filter` | 2 | 8.7s |  |
| 25 | `acid/acid-filter-2` | 0 | 2.9s |  |
| 26 | `acid/acid-gc` | 0 | 22.0s |  |
| 27 | `acid/acid-gradient` | 0 | 2.6s |  |
| 28 | `acid/acid-gradient-0` | 0 | 23.4s |  |
| 29 | `acid/acid-gradient-1` | 0 | 2.5s |  |
| 30 | `acid/acid-gradient-2` | 0 | 2.5s |  |
| 31 | `acid/acid-image` | 0 | 31.4s |  |
| 32 | `acid/acid-large` | 0 | 74.9s |  |
| 33 | `acid/acid-mask` | 0 | 9.2s |  |
| 34 | `acid/acid-scale` | 0 | 2.3s |  |
| 35 | `acid/acid-small` | 0 | 2.9s |  |
| 36 | `acid/acid-stroke-0` | 0 | 26.9s |  |
| 37 | `acid/acid-text` | 0 | 2.0s |  |
| 38 | `acid/acid-text-2` | 1 | 2.8s |  |
| 39 | `acid/acid-text-3` | 0 | 1.7s |  |
| 40 | `acid/acid-text-4` | 0 | 7.4s |  |
| 41 | `acid/acid-text-5` | 0 | 24.5s |  |
| 42 | `acid/acid-text-6` | 0 | 19.8s |  |
| 43 | `acid/acid-text-escape` | 0 | 2.0s |  |
| 44 | `acid/acid-textfield-scroll` | 5 | 6.8s |  |
| 45 | `acid/acid-video` | 0 | 20.7s |  |
| 46 | `add` | 11 | 1.7s |  |
| 47 | `as3-interfaces` | 6 | 23.1s |  |
| 48 | `as3-loader/LoaderLoadBytesTest2` | 3 | 6.4s |  |
| 49 | `as3-loader/bug1093712/loader` | 1 | 6.5s |  |
| 50 | `as3-loader/bug1157243/empty` | 1 | 6.5s |  |
| 51 | `as3-loader/bug1157243/invalid` | 1 | 6.3s |  |
| 52 | `as3-loader/loaderinfo/Preloader` | 1 | 6.3s |  |
| 53 | `avm1/array` | 7 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 54 | `avm1/bitmapdata/getPixel` | 2 | 2.1s |  |
| 55 | `avm1/bitmapdata/loadBitmap` | 3 | 2.2s |  |
| 56 | `avm1/callee` | 2 | 2.1s |  |
| 57 | `avm1/depth` | 6 | 2.2s |  |
| 58 | `avm1/doactionorder/doactionorder` | 7 | 2.5s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 59 | `avm1/doactionorder/symbolclass` | 4 | 2.4s |  |
| 60 | `avm1/duplicateMovieClip/dontremove` | 6 | 21.9s |  |
| 61 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.2s |  |
| 62 | `avm1/duplicateMovieClip/name-coercion` | 3 | 2.1s |  |
| 63 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.2s |  |
| 64 | `avm1/externalinterface` | 4 | 2.0s |  |
| 65 | `avm1/filters` | 149 | 2.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 66 | `avm1/haxe/flocons1` | 2 | 2.1s |  |
| 67 | `avm1/haxe/flocons2` | 3 | 2.0s |  |
| 68 | `avm1/label` | 4 | 2.4s |  |
| 69 | `avm1/levels` | 9 | 2.2s |  |
| 70 | `avm1/loadevent` | 9 | 2.3s |  |
| 71 | `avm1/loadvariables/loadvariables` | 7 | 2.1s |  |
| 72 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 73 | `avm1/lookup` | 3 | 0.8s |  |
| 74 | `avm1/mouse-transparency` | 1 | 2.2s |  |
| 75 | `avm1/moviecliploader` | 7 | 21.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 76 | `avm1/nativeinheritance` | 6 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 77 | `avm1/nested-button` | 1 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 78 | `avm1/operations` | 13 | 1.6s |  |
| 79 | `avm1/property-paths/property-paths-6` | 6 | 1.5s |  |
| 80 | `avm1/property-paths/property-paths-7` | 7 | 1.3s |  |
| 81 | `avm1/propertycase/propertycase` | 7 | 1.6s |  |
| 82 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.8s |  |
| 83 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.4s |  |
| 84 | `avm1/rollover` | 4 | 1.6s |  |
| 85 | `avm1/scope` | 14 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 86 | `avm1/setinterval` | 20 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 87 | `avm1/settimeout` | 17 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 88 | `avm1/super` | 11 | 2.2s |  |
| 89 | `avm1/target` | 18 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 90 | `avm1/text-bind` | 0 | 22.4s |  |
| 91 | `avm1/textfield/textfield-html` | 4 | 2.3s |  |
| 92 | `avm1/textfield/textfield-text-setters` | 8 | 2.2s |  |
| 93 | `avm1/undefined/undefined-swf6` | 39 | 1.8s |  |
| 94 | `avm1/undefined/undefined-swf7` | 39 | 1.6s |  |
| 95 | `avm1/watch` | 2 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 96 | `avm1/xml/xmlbuild` | 1 | 1.6s |  |
| 97 | `avm1/xml/xmlload` | 4 | 2.0s |  |
| 98 | `avm1/xml/xmlstring` | 9 | 1.8s |  |
| 99 | `avm1timeline1` | 3 | 1.9s |  |
| 100 | `avm1timeline2` | 6 | 2.1s |  |
| 101 | `avm2/event-dispatching` | 5 | 7.6s |  |
| 102 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 9.3s |  |
| 103 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 27.2s |  |
| 104 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 7.6s |  |
| 105 | `bitmapbuttons` | 0 | 29.3s |  |
| 106 | `bitmapdata/draw-and-read` | 1 | 6.2s |  |
| 107 | `blendmode/blendmode_1` | 2 | 20.4s |  |
| 108 | `blendmode/blendmode_2` | 4 | 5.7s |  |
| 109 | `blendmode/blendmode_3` | 2 | 5.6s |  |
| 110 | `button1` | 1 | 6.2s |  |
| 111 | `button2` | 1 | 6.0s |  |
| 112 | `button3` | 1 | 2.4s |  |
| 113 | `captions` | 8 | 8.2s |  |
| 114 | `clipping` | 0 | 21.6s |  |
| 115 | `doubleAndRegister` | 2 | 2.6s |  |
| 116 | `encoding1` | 31 | 7.7s |  |
| 117 | `flash_events_Event` | 3 | 26.6s |  |
| 118 | `flash_geom_ColorTransform` | 0 | 7.7s |  |
| 119 | `flash_net_URLLoader` | 7 | 21.1s |  |
| 120 | `flash_net_URLRequest` | 6 | 6.1s |  |
| 121 | `flash_net_classes` | 22 | 6.2s |  |
| 122 | `flash_utils_Timer` | 2 | 6.0s |  |
| 123 | `fscommand1` | 1 | 1.6s |  |
| 124 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 17.1s |  |
| 125 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 19.7s |  |
| 126 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.9s |  |
| 127 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 19.8s |  |
| 128 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 18.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 129 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 23 | 18.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 130 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 17.1s |  |
| 131 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 17.2s |  |
| 132 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 31 | 22.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 133 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 20.8s |  |
| 134 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 21.2s |  |
| 135 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 22.8s |  |
| 136 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 22.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 137 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 22.2s |  |
| 138 | `gradient` | 0 | 2.6s |  |
| 139 | `gradientTransform` | 0 | 21.4s |  |
| 140 | `hardwrap` | 1 | 8.4s |  |
| 141 | `hitTestStyleChange` | 1 | 26.8s |  |
| 142 | `hittesting/hittesting` | 18 | 8.0s |  |
| 143 | `hittesting/mask-hit-test` | 1 | 3.4s |  |
| 144 | `image-loading` | 4 | 8.1s |  |
| 145 | `invalidClipDepth` | 0 | 21.5s |  |
| 146 | `local2global` | 1 | 7.9s |  |
| 147 | `localconnection` | 12 | 8.4s |  |
| 148 | `lzma` | 5 | 7.7s |  |
| 149 | `lzma_bytes` | 2 | 26.9s |  |
| 150 | `mouse/mouse_coords` | 2 | 8.0s |  |
| 151 | `mouse/start_drag` | 3 | 26.6s |  |
| 152 | `mouse/start_drag_lock` | 3 | 7.7s |  |
| 153 | `movieclip` | 9 | 7.7s |  |
| 154 | `movieinfo1` | 3 | 2.0s |  |
| 155 | `slider_component` | 4 | 13.4s |  |
| 156 | `stream1` | 9 | 7.8s |  |
| 157 | `stroke1` | 1 | 7.7s |  |
| 158 | `stylesheet` | 3 | 6.5s |  |
| 159 | `targetPath1` | 8 | 1.6s |  |
| 160 | `timeline/Timeline3` | 5 | 21.5s |  |
| 161 | `timeline/Timeline4` | 5 | 21.3s |  |
| 162 | `timeline/Timeline8` | 5 | 6.3s |  |
| 163 | `timeline/Timeline9` | 11 | 6.3s |  |
| 164 | `timeline/events/timeline_events_fp10` | 67 | 6.5s |  |
| 165 | `timeline/events/timeline_events_fp9` | 48 | 25.5s |  |
| 166 | `timeline/nav/blendMode` | 8 | 25.6s |  |
| 167 | `timeline/nav/cacheAsBitmap` | 8 | 6.4s |  |
| 168 | `timeline/nav/colorTransform` | 8 | 6.5s |  |
| 169 | `timeline/nav/filters` | 8 | 6.4s |  |
| 170 | `timeline/nav/matrix` | 8 | 6.4s |  |
| 171 | `timeline/nav/morphShape` | 4 | 26.9s |  |
| 172 | `timeline/nav/name` | 8 | 26.8s |  |
| 173 | `timeline/nav/ratio` | 4 | 7.7s |  |
| 174 | `timeline/nav/ratio2` | 4 | 7.5s |  |
| 175 | `timeline/nav/ratio3` | 4 | 1.3s |  |
| 176 | `timeline/nav/shape` | 4 | 7.6s |  |
| 177 | `timeline/scene/EncodedU32` | 1 | 27.0s |  |
| 178 | `timeline/scene/Scene_1_MainTimeline` | 70 | 19.1s |  |
| 179 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 5.2s |  |
| 180 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 5.3s |  |
| 181 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 5.3s |  |
| 182 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 5.1s |  |
| 183 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 5.5s |  |
| 184 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 19.3s |  |
| 185 | `timeline/timeline_as2_1` | 3 | 21.1s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 186 | `timeline/timeline_as2_2` | 3 | 2.2s |  |
| 187 | `timeline/timeline_as2_3` | 3 | 21.3s |  |
| 188 | `timeline/timeline_as2_4` | 2 | 21.3s |  |
| 189 | `timeline/timeline_as2_5` | 4 | 4.6s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 190 | `timeline/timeline_loop` | 7 | 29.7s |  |
| 191 | `timeline/timeline_name_0` | 13 | 27.6s |  |

## Ruffle-Matched Tests

**7 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-text-x` | 1 | 1 | 6.4s |  |
| 2 | `acid/acid-textfield` | 6 | 7 | 7.1s |  |
| 3 | `as3-loader/LoaderTest` | 2 | 2 | 22.8s |  |
| 4 | `avm1/hitarea` | 2 | 2 | 21.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 7.5s |  |
| 6 | `flash_text_TextField` | 5 | 8 | 22.3s |  |
| 7 | `timeline/nav/clipDepth` | 4 | 4 | 6.5s |  |

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
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 4 | 0 |
| | *(tests not in any document)* | 189 | 174 | 15 |
