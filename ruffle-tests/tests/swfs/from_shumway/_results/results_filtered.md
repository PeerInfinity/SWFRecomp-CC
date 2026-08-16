# Ruffle Test Results (Filtered)

**Date**: 2026-08-16 08:44 UTC

**Git SHA**: `88ebde6653`

**Run Duration**: 44m 0s

**Filtered**: 22 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 207 |
| Passing | **194** (93.7%) |
| Ruffle-matched | 7 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **201** (97.1%) |
| Failing | 6 |
| Total expected lines | 1770 |
| Matching lines | 1507 (85.1%) |
| Mismatched lines | 263 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 6 | 100.0% |

## Passing Tests

**194 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 26.4s |  |
| 2 | `MaskTest` | 0 | 6.9s |  |
| 3 | `MaskTest-2` | 0 | 7.1s |  |
| 4 | `ZeroClipboardTest` | 3 | 26.1s |  |
| 5 | `acid/acid` | 1 | 27.7s |  |
| 6 | `acid/acid-big` | 0 | 43.5s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 26.2s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 25.9s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 21.9s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 2.9s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 6.7s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 6.5s |  |
| 13 | `acid/acid-bitmaps` | 0 | 25.6s |  |
| 14 | `acid/acid-blend` | 0 | 37.9s |  |
| 15 | `acid/acid-blend-2` | 0 | 19.8s |  |
| 16 | `acid/acid-chars` | 0 | 1.3s |  |
| 17 | `acid/acid-child` | 0 | 20.6s |  |
| 18 | `acid/acid-clip` | 0 | 1.3s |  |
| 19 | `acid/acid-clip-2` | 0 | 1.3s |  |
| 20 | `acid/acid-clip-3` | 0 | 7.0s |  |
| 21 | `acid/acid-color` | 0 | 33.7s |  |
| 22 | `acid/acid-color-0` | 0 | 21.7s |  |
| 23 | `acid/acid-color-2` | 0 | 1.3s |  |
| 24 | `acid/acid-filter` | 2 | 4.3s |  |
| 25 | `acid/acid-filter-2` | 0 | 0.8s |  |
| 26 | `acid/acid-gc` | 0 | 13.2s |  |
| 27 | `acid/acid-gradient` | 0 | 0.9s |  |
| 28 | `acid/acid-gradient-0` | 0 | 12.9s |  |
| 29 | `acid/acid-gradient-1` | 0 | 0.8s |  |
| 30 | `acid/acid-gradient-2` | 0 | 0.9s |  |
| 31 | `acid/acid-image` | 0 | 19.0s |  |
| 32 | `acid/acid-large` | 0 | 60.2s |  |
| 33 | `acid/acid-mask` | 0 | 5.6s |  |
| 34 | `acid/acid-morph` | 6 | 19.7s |  |
| 35 | `acid/acid-scale` | 0 | 0.9s |  |
| 36 | `acid/acid-small` | 0 | 1.0s |  |
| 37 | `acid/acid-stroke-0` | 0 | 20.0s |  |
| 38 | `acid/acid-text` | 0 | 1.4s |  |
| 39 | `acid/acid-text-2` | 1 | 2.7s |  |
| 40 | `acid/acid-text-3` | 0 | 1.4s |  |
| 41 | `acid/acid-text-4` | 0 | 7.1s |  |
| 42 | `acid/acid-text-5` | 0 | 27.2s |  |
| 43 | `acid/acid-text-6` | 0 | 21.4s |  |
| 44 | `acid/acid-text-escape` | 0 | 1.4s |  |
| 45 | `acid/acid-textfield-scroll` | 5 | 7.1s |  |
| 46 | `acid/acid-video` | 0 | 22.5s |  |
| 47 | `add` | 11 | 1.3s |  |
| 48 | `as3-interfaces` | 6 | 27.8s |  |
| 49 | `as3-loader/LoaderLoadBytesTest2` | 3 | 7.0s |  |
| 50 | `as3-loader/LoaderTest2` | 7 | 25.6s |  |
| 51 | `as3-loader/bug1093712/loader` | 1 | 6.7s |  |
| 52 | `as3-loader/bug1157243/empty` | 1 | 6.6s |  |
| 53 | `as3-loader/bug1157243/invalid` | 1 | 6.5s |  |
| 54 | `as3-loader/loaderinfo/Preloader` | 1 | 6.6s |  |
| 55 | `avm1/array` | 7 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 56 | `avm1/bitmapdata/getPixel` | 2 | 1.2s |  |
| 57 | `avm1/bitmapdata/loadBitmap` | 3 | 1.3s |  |
| 58 | `avm1/callee` | 2 | 1.2s |  |
| 59 | `avm1/depth` | 6 | 1.4s |  |
| 60 | `avm1/doactionorder/doactionorder` | 7 | 1.6s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 61 | `avm1/doactionorder/symbolclass` | 4 | 1.5s |  |
| 62 | `avm1/duplicateMovieClip/dontremove` | 6 | 20.2s |  |
| 63 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 1.3s |  |
| 64 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.3s |  |
| 65 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.4s |  |
| 66 | `avm1/externalinterface` | 4 | 1.2s |  |
| 67 | `avm1/filters` | 149 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 68 | `avm1/haxe/flocons1` | 2 | 1.3s |  |
| 69 | `avm1/haxe/flocons2` | 3 | 1.2s |  |
| 70 | `avm1/label` | 4 | 1.5s |  |
| 71 | `avm1/levels` | 9 | 1.3s |  |
| 72 | `avm1/loadevent` | 9 | 1.5s |  |
| 73 | `avm1/loadvariables/loadvariables` | 7 | 1.3s |  |
| 74 | `avm1/loadvariables/loadvars` | 2 | 0.2s |  |
| 75 | `avm1/lookup` | 3 | 0.2s |  |
| 76 | `avm1/mouse-transparency` | 1 | 1.4s |  |
| 77 | `avm1/moviecliploader` | 7 | 20.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 78 | `avm1/nativeinheritance` | 6 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 79 | `avm1/nested-button` | 1 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 80 | `avm1/operations` | 13 | 1.3s |  |
| 81 | `avm1/property-paths/property-paths-6` | 6 | 1.2s |  |
| 82 | `avm1/property-paths/property-paths-7` | 7 | 0.9s |  |
| 83 | `avm1/propertycase/propertycase` | 7 | 1.2s |  |
| 84 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.2s |  |
| 85 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.0s |  |
| 86 | `avm1/rollover` | 4 | 1.4s |  |
| 87 | `avm1/scope` | 14 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 88 | `avm1/setinterval` | 20 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 89 | `avm1/settimeout` | 17 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 90 | `avm1/super` | 11 | 1.3s |  |
| 91 | `avm1/target` | 18 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 92 | `avm1/text-bind` | 0 | 20.6s |  |
| 93 | `avm1/textfield/textfield-html` | 4 | 1.4s |  |
| 94 | `avm1/textfield/textfield-text-setters` | 8 | 1.4s |  |
| 95 | `avm1/undefined/undefined-swf6` | 39 | 1.2s |  |
| 96 | `avm1/undefined/undefined-swf7` | 39 | 0.9s |  |
| 97 | `avm1/watch` | 2 | 1.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 98 | `avm1/xml/xmlbuild` | 1 | 1.0s |  |
| 99 | `avm1/xml/xmlload` | 4 | 1.5s |  |
| 100 | `avm1/xml/xmlstring` | 9 | 1.2s |  |
| 101 | `avm1timeline1` | 3 | 1.3s |  |
| 102 | `avm1timeline2` | 6 | 1.4s |  |
| 103 | `avm2/event-dispatching` | 5 | 6.8s |  |
| 104 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 7.2s |  |
| 105 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 27.1s |  |
| 106 | `avm2/flash/geom/matrix3d/TransformBasics` | 13 | 7.0s |  |
| 107 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 6.8s |  |
| 108 | `bitmapbuttons` | 0 | 28.4s |  |
| 109 | `bitmapdata/draw-and-read` | 1 | 6.6s |  |
| 110 | `blendmode/blendmode_1` | 2 | 25.1s |  |
| 111 | `blendmode/blendmode_2` | 4 | 6.6s |  |
| 112 | `blendmode/blendmode_3` | 2 | 6.6s |  |
| 113 | `button1` | 1 | 2.8s |  |
| 114 | `button2` | 1 | 6.8s |  |
| 115 | `button3` | 1 | 1.5s |  |
| 116 | `captions` | 8 | 5.6s |  |
| 117 | `clipping` | 0 | 16.9s |  |
| 118 | `doubleAndRegister` | 2 | 1.1s |  |
| 119 | `encoding1` | 31 | 5.4s |  |
| 120 | `flash_events_Event` | 3 | 21.8s |  |
| 121 | `flash_geom_ColorTransform` | 0 | 5.5s |  |
| 122 | `flash_net_URLLoader` | 7 | 25.7s |  |
| 123 | `flash_net_URLRequest` | 6 | 6.7s |  |
| 124 | `flash_net_classes` | 22 | 6.8s |  |
| 125 | `flash_utils_Timer` | 2 | 6.6s |  |
| 126 | `fscommand1` | 1 | 1.2s |  |
| 127 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 20.4s |  |
| 128 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 19.4s |  |
| 129 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.4s |  |
| 130 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 19.5s |  |
| 131 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 132 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 23 | 21.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 133 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.3s |  |
| 134 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 20.2s |  |
| 135 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 31 | 21.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 136 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 20.3s |  |
| 137 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 20.3s |  |
| 138 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 20.5s |  |
| 139 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 20.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 140 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 19.9s |  |
| 141 | `gradient` | 0 | 1.3s |  |
| 142 | `gradientTransform` | 0 | 20.5s |  |
| 143 | `hardwrap` | 1 | 7.2s |  |
| 144 | `hitTestStyleChange` | 1 | 26.0s |  |
| 145 | `hittesting/hittesting` | 18 | 6.9s |  |
| 146 | `hittesting/mask-hit-test` | 1 | 2.5s |  |
| 147 | `image-loading` | 4 | 6.7s |  |
| 148 | `invalidClipDepth` | 0 | 20.2s |  |
| 149 | `local2global` | 1 | 6.6s |  |
| 150 | `localconnection` | 12 | 7.0s |  |
| 151 | `lzma` | 5 | 6.5s |  |
| 152 | `lzma_bytes` | 2 | 25.2s |  |
| 153 | `mouse/mouse_coords` | 2 | 6.7s |  |
| 154 | `mouse/start_drag` | 3 | 25.6s |  |
| 155 | `mouse/start_drag_lock` | 3 | 6.4s |  |
| 156 | `movieclip` | 9 | 6.2s |  |
| 157 | `movieinfo1` | 3 | 1.1s |  |
| 158 | `slider_component` | 4 | 11.7s |  |
| 159 | `stream1` | 9 | 6.5s |  |
| 160 | `stroke1` | 1 | 6.3s |  |
| 161 | `stylesheet` | 3 | 4.2s |  |
| 162 | `targetPath1` | 8 | 0.8s |  |
| 163 | `timeline/Timeline3` | 5 | 15.5s |  |
| 164 | `timeline/Timeline4` | 5 | 15.6s |  |
| 165 | `timeline/Timeline8` | 5 | 4.3s |  |
| 166 | `timeline/Timeline9` | 11 | 4.2s |  |
| 167 | `timeline/events/timeline_events_fp10` | 67 | 4.5s |  |
| 168 | `timeline/events/timeline_events_fp9` | 48 | 25.7s |  |
| 169 | `timeline/nav/blendMode` | 8 | 25.1s |  |
| 170 | `timeline/nav/cacheAsBitmap` | 8 | 6.3s |  |
| 171 | `timeline/nav/colorTransform` | 8 | 6.5s |  |
| 172 | `timeline/nav/filters` | 8 | 6.3s |  |
| 173 | `timeline/nav/matrix` | 8 | 6.5s |  |
| 174 | `timeline/nav/morphShape` | 4 | 26.9s |  |
| 175 | `timeline/nav/name` | 8 | 26.2s |  |
| 176 | `timeline/nav/ratio` | 4 | 6.6s |  |
| 177 | `timeline/nav/ratio2` | 4 | 6.4s |  |
| 178 | `timeline/nav/ratio3` | 4 | 0.6s |  |
| 179 | `timeline/nav/shape` | 4 | 6.5s |  |
| 180 | `timeline/scene/EncodedU32` | 1 | 26.1s |  |
| 181 | `timeline/scene/Scene_1_MainTimeline` | 70 | 25.1s |  |
| 182 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 6.6s |  |
| 183 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 6.6s |  |
| 184 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 6.5s |  |
| 185 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 6.2s |  |
| 186 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 6.6s |  |
| 187 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 24.9s |  |
| 188 | `timeline/timeline_as2_1` | 3 | 20.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 189 | `timeline/timeline_as2_2` | 3 | 1.4s |  |
| 190 | `timeline/timeline_as2_3` | 3 | 20.4s |  |
| 191 | `timeline/timeline_as2_4` | 2 | 20.5s |  |
| 192 | `timeline/timeline_as2_5` | 4 | 1.9s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 193 | `timeline/timeline_loop` | 7 | 26.8s |  |
| 194 | `timeline/timeline_name_0` | 13 | 26.1s |  |

## Ruffle-Matched Tests

**7 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-text-x` | 1 | 1 | 7.0s |  |
| 2 | `acid/acid-textfield` | 6 | 7 | 7.5s |  |
| 3 | `as3-loader/LoaderTest` | 2 | 2 | 27.5s |  |
| 4 | `avm1/hitarea` | 2 | 2 | 20.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 6.7s |  |
| 6 | `flash_text_TextField` | 5 | 8 | 25.9s |  |
| 7 | `timeline/nav/clipDepth` | 4 | 4 | 6.5s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**2 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36 | 48 | 12 |  |
| 2 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**6 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36/48 | 48 | 48 |  |
| 2 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1/2 | 2 | 2 |  |
| 3 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 4 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 5 | `as3-loader/events/loader-events` | 24.3% | 9/37 | 37 | 36 |  |
| 6 | `acid/acid-shapes` | 0.0% | 0/120 | 7 | 120 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 4 | 4 | 0 |
| | *(tests not in any document)* | 189 | 177 | 12 |
