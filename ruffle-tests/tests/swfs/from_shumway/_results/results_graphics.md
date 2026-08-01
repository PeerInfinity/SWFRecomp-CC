# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-01 07:44 UTC

**Git SHA**: `07c119c505`

**Run Duration**: 46m 47s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 229 |
| Passing | **184** (80.3%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **197** (86.0%) |
| Failing | 32 |
| Total expected lines | 2484 |
| Matching lines | 1762 (70.9%) |
| Mismatched lines | 722 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 32 | 100.0% |

## Passing Tests

**184 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 28.0s |  |
| 2 | `MaskTest` | 0 | 7.9s |  |
| 3 | `MaskTest-2` | 0 | 8.2s |  |
| 4 | `ZeroClipboardTest` | 3 | 27.0s |  |
| 5 | `acid/acid` | 1 | 38.0s |  |
| 6 | `acid/acid-big` | 0 | 46.2s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 28.2s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 28.0s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 24.8s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 4.0s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 8.0s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 7.7s |  |
| 13 | `acid/acid-bitmaps` | 0 | 27.7s |  |
| 14 | `acid/acid-blend` | 0 | 41.2s |  |
| 15 | `acid/acid-blend-2` | 0 | 23.8s |  |
| 16 | `acid/acid-chars` | 0 | 2.4s |  |
| 17 | `acid/acid-child` | 0 | 21.8s |  |
| 18 | `acid/acid-clip` | 0 | 2.6s |  |
| 19 | `acid/acid-clip-2` | 0 | 2.4s |  |
| 20 | `acid/acid-clip-3` | 0 | 8.4s |  |
| 21 | `acid/acid-color` | 0 | 36.4s |  |
| 22 | `acid/acid-color-0` | 0 | 5.4s |  |
| 23 | `acid/acid-color-2` | 0 | 2.4s |  |
| 24 | `acid/acid-filter` | 2 | 5.5s |  |
| 25 | `acid/acid-filter-2` | 0 | 1.7s |  |
| 26 | `acid/acid-gc` | 0 | 2.2s |  |
| 27 | `acid/acid-gradient` | 0 | 1.6s |  |
| 28 | `acid/acid-gradient-0` | 0 | 15.9s |  |
| 29 | `acid/acid-gradient-1` | 0 | 1.5s |  |
| 30 | `acid/acid-gradient-2` | 0 | 1.5s |  |
| 31 | `acid/acid-image` | 0 | 21.7s |  |
| 32 | `acid/acid-large` | 0 | 77.3s |  |
| 33 | `acid/acid-mask` | 0 | 8.9s |  |
| 34 | `acid/acid-scale` | 0 | 2.3s |  |
| 35 | `acid/acid-small` | 0 | 2.9s |  |
| 36 | `acid/acid-stroke-0` | 0 | 28.1s |  |
| 37 | `acid/acid-text` | 0 | 2.4s |  |
| 38 | `acid/acid-text-3` | 0 | 2.4s |  |
| 39 | `acid/acid-text-4` | 0 | 8.2s |  |
| 40 | `acid/acid-text-5` | 0 | 29.7s |  |
| 41 | `acid/acid-text-6` | 0 | 25.3s |  |
| 42 | `acid/acid-text-escape` | 0 | 2.4s |  |
| 43 | `acid/acid-textfield-scroll` | 5 | 7.5s |  |
| 44 | `acid/acid-video` | 0 | 21.8s |  |
| 45 | `add` | 11 | 1.9s |  |
| 46 | `as3-interfaces` | 6 | 25.4s |  |
| 47 | `as3-loader/LoaderLoadBytesTest2` | 3 | 7.2s |  |
| 48 | `as3-loader/bug1093712/loader` | 1 | 6.2s |  |
| 49 | `as3-loader/loaderinfo/Preloader` | 1 | 6.0s |  |
| 50 | `avm1/array` | 7 | 1.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 51 | `avm1/bitmapdata/getPixel` | 2 | 2.0s |  |
| 52 | `avm1/bitmapdata/loadBitmap` | 3 | 2.0s |  |
| 53 | `avm1/callee` | 2 | 2.0s |  |
| 54 | `avm1/depth` | 6 | 2.1s |  |
| 55 | `avm1/doactionorder/doactionorder` | 7 | 2.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 56 | `avm1/doactionorder/symbolclass` | 4 | 2.2s |  |
| 57 | `avm1/duplicateMovieClip/dontremove` | 6 | 22.0s |  |
| 58 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.1s |  |
| 59 | `avm1/duplicateMovieClip/name-coercion` | 3 | 2.0s |  |
| 60 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.2s |  |
| 61 | `avm1/externalinterface` | 4 | 2.0s |  |
| 62 | `avm1/filters` | 149 | 2.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 63 | `avm1/haxe/flocons1` | 2 | 2.1s |  |
| 64 | `avm1/haxe/flocons2` | 3 | 2.0s |  |
| 65 | `avm1/label` | 4 | 2.5s |  |
| 66 | `avm1/levels` | 9 | 2.1s |  |
| 67 | `avm1/loadevent` | 9 | 2.3s |  |
| 68 | `avm1/loadvariables/loadvariables` | 7 | 2.0s |  |
| 69 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 70 | `avm1/lookup` | 3 | 0.8s |  |
| 71 | `avm1/mouse-transparency` | 1 | 2.2s |  |
| 72 | `avm1/moviecliploader` | 7 | 22.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 73 | `avm1/nativeinheritance` | 6 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 74 | `avm1/nested-button` | 1 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 75 | `avm1/operations` | 13 | 2.0s |  |
| 76 | `avm1/property-paths/property-paths-6` | 6 | 1.9s |  |
| 77 | `avm1/property-paths/property-paths-7` | 7 | 1.7s |  |
| 78 | `avm1/propertycase/propertycase` | 7 | 1.9s |  |
| 79 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.9s |  |
| 80 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.7s |  |
| 81 | `avm1/rollover` | 4 | 2.1s |  |
| 82 | `avm1/scope` | 14 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/setinterval` | 20 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 84 | `avm1/settimeout` | 17 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 85 | `avm1/super` | 11 | 1.9s |  |
| 86 | `avm1/target` | 18 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 87 | `avm1/text-bind` | 0 | 21.6s |  |
| 88 | `avm1/textfield/textfield-html` | 4 | 2.1s |  |
| 89 | `avm1/textfield/textfield-text-setters` | 8 | 2.1s |  |
| 90 | `avm1/undefined/undefined-swf6` | 39 | 2.0s |  |
| 91 | `avm1/undefined/undefined-swf7` | 39 | 1.7s |  |
| 92 | `avm1/watch` | 2 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 93 | `avm1/xml/xmlbuild` | 1 | 1.8s |  |
| 94 | `avm1/xml/xmlload` | 4 | 2.4s |  |
| 95 | `avm1/xml/xmlstring` | 9 | 2.0s |  |
| 96 | `avm1timeline1` | 3 | 2.1s |  |
| 97 | `avm1timeline2` | 6 | 1.5s |  |
| 98 | `avm2/event-dispatching` | 5 | 5.5s |  |
| 99 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 5.8s |  |
| 100 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 20.4s |  |
| 101 | `bitmapbuttons` | 0 | 20.8s |  |
| 102 | `bitmapdata/draw-and-read` | 1 | 7.2s |  |
| 103 | `blendmode/blendmode_1` | 2 | 25.7s |  |
| 104 | `blendmode/blendmode_2` | 4 | 7.3s |  |
| 105 | `blendmode/blendmode_3` | 2 | 7.2s |  |
| 106 | `button1` | 1 | 4.4s |  |
| 107 | `button2` | 1 | 8.4s |  |
| 108 | `button3` | 1 | 3.2s |  |
| 109 | `captions` | 8 | 6.3s |  |
| 110 | `clipping` | 0 | 1.8s |  |
| 111 | `doubleAndRegister` | 2 | 2.0s |  |
| 112 | `encoding1` | 31 | 5.8s |  |
| 113 | `flash_events_Event` | 3 | 20.7s |  |
| 114 | `flash_geom_ColorTransform` | 0 | 5.8s |  |
| 115 | `flash_net_URLLoader` | 7 | 5.9s |  |
| 116 | `flash_net_URLRequest` | 6 | 5.9s |  |
| 117 | `flash_net_classes` | 22 | 6.0s |  |
| 118 | `flash_utils_Timer` | 2 | 5.8s |  |
| 119 | `fscommand1` | 1 | 1.4s |  |
| 120 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 18.1s |  |
| 121 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 23.7s |  |
| 122 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 2.5s |  |
| 123 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 23.7s |  |
| 124 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 125 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.8s |  |
| 126 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 20.6s |  |
| 127 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 17.5s |  |
| 128 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 17.9s |  |
| 129 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 18.0s |  |
| 130 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 18.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 131 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 20.4s |  |
| 132 | `gradient` | 0 | 2.7s |  |
| 133 | `gradientTransform` | 0 | 24.5s |  |
| 134 | `hardwrap` | 1 | 8.8s |  |
| 135 | `hitTestStyleChange` | 1 | 30.0s |  |
| 136 | `hittesting/mask-hit-test` | 1 | 3.7s |  |
| 137 | `image-loading` | 4 | 7.5s |  |
| 138 | `invalidClipDepth` | 0 | 21.1s |  |
| 139 | `local2global` | 1 | 7.2s |  |
| 140 | `localconnection` | 12 | 7.5s |  |
| 141 | `lzma` | 5 | 7.1s |  |
| 142 | `lzma_bytes` | 2 | 25.9s |  |
| 143 | `mouse/mouse_coords` | 2 | 7.3s |  |
| 144 | `mouse/start_drag` | 3 | 27.0s |  |
| 145 | `mouse/start_drag_lock` | 3 | 7.5s |  |
| 146 | `movieclip` | 9 | 7.5s |  |
| 147 | `movieinfo1` | 3 | 2.1s |  |
| 148 | `slider_component` | 4 | 13.2s |  |
| 149 | `stream1` | 9 | 7.7s |  |
| 150 | `stroke1` | 1 | 7.6s |  |
| 151 | `stylesheet` | 3 | 8.3s |  |
| 152 | `targetPath1` | 8 | 2.2s |  |
| 153 | `timeline/Timeline3` | 5 | 28.5s |  |
| 154 | `timeline/Timeline4` | 5 | 28.8s |  |
| 155 | `timeline/Timeline8` | 5 | 8.3s |  |
| 156 | `timeline/Timeline9` | 11 | 8.3s |  |
| 157 | `timeline/events/timeline_events_fp10` | 67 | 8.4s |  |
| 158 | `timeline/events/timeline_events_fp9` | 48 | 21.6s |  |
| 159 | `timeline/nav/blendMode` | 8 | 21.7s |  |
| 160 | `timeline/nav/cacheAsBitmap` | 8 | 1.3s |  |
| 161 | `timeline/nav/colorTransform` | 8 | 1.3s |  |
| 162 | `timeline/nav/filters` | 8 | 1.3s |  |
| 163 | `timeline/nav/matrix` | 8 | 1.3s |  |
| 164 | `timeline/nav/morphShape` | 4 | 29.9s |  |
| 165 | `timeline/nav/name` | 8 | 29.4s |  |
| 166 | `timeline/nav/ratio` | 4 | 8.0s |  |
| 167 | `timeline/nav/ratio2` | 4 | 7.8s |  |
| 168 | `timeline/nav/ratio3` | 4 | 1.4s |  |
| 169 | `timeline/nav/shape` | 4 | 7.9s |  |
| 170 | `timeline/scene/EncodedU32` | 1 | 30.0s |  |
| 171 | `timeline/scene/Scene_1_MainTimeline` | 70 | 27.6s |  |
| 172 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 7.9s |  |
| 173 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 7.9s |  |
| 174 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 7.8s |  |
| 175 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 7.4s |  |
| 176 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 7.6s |  |
| 177 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 27.5s |  |
| 178 | `timeline/timeline_as2_1` | 3 | 21.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 179 | `timeline/timeline_as2_2` | 3 | 2.1s |  |
| 180 | `timeline/timeline_as2_3` | 3 | 21.5s |  |
| 181 | `timeline/timeline_as2_4` | 2 | 21.5s |  |
| 182 | `timeline/timeline_as2_5` | 4 | 4.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 183 | `timeline/timeline_loop` | 7 | 29.3s |  |
| 184 | `timeline/timeline_name_0` | 13 | 26.6s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `MaskTest-3` | 1 | 1 | 27.5s |  |
| 2 | `acid/acid-text-x` | 1 | 1 | 8.0s |  |
| 3 | `acid/acid-textfield` | 6 | 7 | 7.8s |  |
| 4 | `as3-loader/LoaderTest` | 2 | 2 | 25.5s |  |
| 5 | `avm1/hitarea` | 2 | 2 | 21.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 6 | `avm1movie` | 8 | 12 | 26.7s |  |
| 7 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 5.0s |  |
| 8 | `flash_net_SharedObject` | 1 | 1 | 5.8s |  |
| 9 | `flash_text_TextField` | 5 | 8 | 22.9s |  |
| 10 | `flash_text_TextField2` | 9 | 9 | 6.3s |  |
| 11 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 21.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 19.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 13 | `timeline/nav/clipDepth` | 4 | 4 | 1.3s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**11 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `hittesting/hittesting` | 88.9% | 16 | 18 | 2 |  |
| 2 | `as3-loader/LoaderTest2` | 85.7% | 6 | 7 | 1 |  |
| 3 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 80.0% | 16 | 20 | 4 |  |
| 4 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36 | 48 | 12 |  |
| 5 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14 | 19 | 5 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 6 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 7 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18 | 32 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10 | 18 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 9 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1 | 2 | 1 |  |
| 10 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14 | 28 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16 | 32 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**32 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `hittesting/hittesting` | 88.9% | 16/18 | 18 | 18 |  |
| 2 | `as3-loader/LoaderTest2` | 85.7% | 6/7 | 7 | 7 |  |
| 3 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 80.0% | 16/20 | 20 | 20 |  |
| 4 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36/48 | 48 | 48 |  |
| 5 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14/19 | 19 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 6 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 7 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18/32 | 32 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 8 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 9 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1/2 | 2 | 2 |  |
| 10 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14/28 | 28 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16/32 | 32 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 41.5% | 17/41 | 41 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 13 | `avm2/flash/geom/matrix3d/TransformBasics` | 38.5% | 5/13 | 11 | 13 |  |
| 14 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 38.5% | 10/26 | 26 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 15 | `getobjectsunderpoint` | 35.3% | 12/34 | 28 | 34 |  |
| 16 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 33.3% | 25/75 | 75 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 17 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 33.3% | 12/36 | 36 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 18 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 30.2% | 29/96 | 96 | 70 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 19 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 30.2% | 19/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 20 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 21 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 28.0% | 21/75 | 75 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 22 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 27.0% | 17/63 | 63 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 23 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 24 | `as3-loader/events/loader-events` | 13.5% | 5/37 | 37 | 36 |  |
| 25 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 12.0% | 13/108 | 108 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 26 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 12.0% | 11/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 27 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 8.7% | 15/173 | 173 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 28 | `acid/acid-shapes` | 0.0% | 0/120 | 7 | 120 |  |
| 29 | `acid/acid-text-2` | 0.0% | 0/1 | 1 | 1 |  |
| 30 | `as3-loader/bug1157243/empty` | 0.0% | 0/1 | 0 | 1 |  |
| 31 | `as3-loader/bug1157243/invalid` | 0.0% | 0/1 | 0 | 1 |  |
| 32 | `esc` | 0.0% | 0/13 | 13 | 2 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 2 | 18 |
| | *(tests not in any document)* | 195 | 169 | 26 |
