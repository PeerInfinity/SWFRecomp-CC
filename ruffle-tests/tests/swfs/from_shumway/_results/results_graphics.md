# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-30 00:01 UTC

**Git SHA**: `6a07045c44`

**Run Duration**: 41m 27s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 229 |
| Passing | **170** (74.2%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **182** (79.5%) |
| Failing | 47 |
| Total expected lines | 2484 |
| Matching lines | 1637 (65.9%) |
| Mismatched lines | 847 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 47 | 100.0% |

## Passing Tests

**170 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 29.4s |  |
| 2 | `MaskTest` | 0 | 7.2s |  |
| 3 | `MaskTest-2` | 0 | 3.9s |  |
| 4 | `ZeroClipboardTest` | 3 | 27.4s |  |
| 5 | `acid/acid` | 1 | 37.6s |  |
| 6 | `acid/acid-big` | 0 | 43.1s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 27.1s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 20.8s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 18.9s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 3.3s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 5.6s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 5.4s |  |
| 13 | `acid/acid-bitmaps` | 0 | 20.8s |  |
| 14 | `acid/acid-blend` | 0 | 33.6s |  |
| 15 | `acid/acid-blend-2` | 0 | 19.9s |  |
| 16 | `acid/acid-chars` | 0 | 2.2s |  |
| 17 | `acid/acid-child` | 0 | 21.1s |  |
| 18 | `acid/acid-clip` | 0 | 2.5s |  |
| 19 | `acid/acid-clip-2` | 0 | 2.3s |  |
| 20 | `acid/acid-clip-3` | 0 | 7.3s |  |
| 21 | `acid/acid-color` | 0 | 34.5s |  |
| 22 | `acid/acid-color-0` | 0 | 5.1s |  |
| 23 | `acid/acid-color-2` | 0 | 2.2s |  |
| 24 | `acid/acid-filter-2` | 0 | 2.2s |  |
| 25 | `acid/acid-gc` | 0 | 2.0s |  |
| 26 | `acid/acid-gradient` | 0 | 2.0s |  |
| 27 | `acid/acid-gradient-0` | 0 | 17.9s |  |
| 28 | `acid/acid-gradient-1` | 0 | 1.9s |  |
| 29 | `acid/acid-gradient-2` | 0 | 1.9s |  |
| 30 | `acid/acid-image` | 0 | 23.8s |  |
| 31 | `acid/acid-large` | 0 | 82.7s |  |
| 32 | `acid/acid-mask` | 0 | 9.0s |  |
| 33 | `acid/acid-scale` | 0 | 2.6s |  |
| 34 | `acid/acid-small` | 0 | 3.1s |  |
| 35 | `acid/acid-stroke-0` | 0 | 27.2s |  |
| 36 | `acid/acid-text` | 0 | 2.1s |  |
| 37 | `acid/acid-text-3` | 0 | 1.9s |  |
| 38 | `acid/acid-text-4` | 0 | 5.8s |  |
| 39 | `acid/acid-text-5` | 0 | 22.3s |  |
| 40 | `acid/acid-text-6` | 0 | 20.5s |  |
| 41 | `acid/acid-text-escape` | 0 | 2.0s |  |
| 42 | `acid/acid-textfield-scroll` | 5 | 7.2s |  |
| 43 | `acid/acid-video` | 0 | 23.7s |  |
| 44 | `add` | 11 | 2.1s |  |
| 45 | `as3-interfaces` | 6 | 27.1s |  |
| 46 | `as3-loader/LoaderLoadBytesTest2` | 3 | 6.6s |  |
| 47 | `as3-loader/bug1093712/loader` | 1 | 6.9s |  |
| 48 | `as3-loader/loaderinfo/Preloader` | 1 | 6.8s |  |
| 49 | `avm1/array` | 7 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 50 | `avm1/bitmapdata/getPixel` | 2 | 1.9s |  |
| 51 | `avm1/bitmapdata/loadBitmap` | 3 | 1.9s |  |
| 52 | `avm1/callee` | 2 | 1.8s |  |
| 53 | `avm1/depth` | 6 | 2.0s |  |
| 54 | `avm1/doactionorder/doactionorder` | 7 | 2.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 55 | `avm1/doactionorder/symbolclass` | 4 | 2.1s |  |
| 56 | `avm1/duplicateMovieClip/dontremove` | 6 | 2.0s |  |
| 57 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.0s |  |
| 58 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.4s |  |
| 59 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.5s |  |
| 60 | `avm1/externalinterface` | 4 | 1.4s |  |
| 61 | `avm1/filters` | 149 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 62 | `avm1/haxe/flocons1` | 2 | 1.4s |  |
| 63 | `avm1/haxe/flocons2` | 3 | 1.4s |  |
| 64 | `avm1/label` | 4 | 1.6s |  |
| 65 | `avm1/levels` | 9 | 2.2s |  |
| 66 | `avm1/loadevent` | 9 | 2.4s |  |
| 67 | `avm1/loadvariables/loadvariables` | 7 | 2.1s |  |
| 68 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 69 | `avm1/lookup` | 3 | 0.8s |  |
| 70 | `avm1/mouse-transparency` | 1 | 2.2s |  |
| 71 | `avm1/moviecliploader` | 7 | 2.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 72 | `avm1/nativeinheritance` | 6 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 73 | `avm1/nested-button` | 1 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 74 | `avm1/operations` | 13 | 2.0s |  |
| 75 | `avm1/property-paths/property-paths-6` | 6 | 2.0s |  |
| 76 | `avm1/property-paths/property-paths-7` | 7 | 1.8s |  |
| 77 | `avm1/propertycase/propertycase` | 7 | 2.0s |  |
| 78 | `avm1/propertycase/propertycase-preserving-6` | 2 | 2.0s |  |
| 79 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.8s |  |
| 80 | `avm1/rollover` | 4 | 2.1s |  |
| 81 | `avm1/scope` | 14 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 82 | `avm1/setinterval` | 20 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/settimeout` | 17 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 84 | `avm1/super` | 11 | 2.0s |  |
| 85 | `avm1/target` | 18 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 86 | `avm1/text-bind` | 0 | 22.4s |  |
| 87 | `avm1/textfield/textfield-html` | 4 | 2.2s |  |
| 88 | `avm1/textfield/textfield-text-setters` | 8 | 2.2s |  |
| 89 | `avm1/undefined/undefined-swf6` | 39 | 2.0s |  |
| 90 | `avm1/undefined/undefined-swf7` | 39 | 1.7s |  |
| 91 | `avm1/watch` | 2 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 92 | `avm1/xml/xmlbuild` | 1 | 0.8s |  |
| 93 | `avm1/xml/xmlload` | 4 | 2.4s |  |
| 94 | `avm1/xml/xmlstring` | 9 | 1.9s |  |
| 95 | `avm1timeline1` | 3 | 2.1s |  |
| 96 | `avm1timeline2` | 6 | 2.2s |  |
| 97 | `avm2/event-dispatching` | 5 | 6.8s |  |
| 98 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 7.6s |  |
| 99 | `bitmapbuttons` | 0 | 28.9s |  |
| 100 | `bitmapdata/draw-and-read` | 1 | 6.1s |  |
| 101 | `blendmode/blendmode_3` | 2 | 6.2s |  |
| 102 | `button1` | 1 | 3.9s |  |
| 103 | `button2` | 1 | 7.2s |  |
| 104 | `button3` | 1 | 2.9s |  |
| 105 | `captions` | 8 | 7.3s |  |
| 106 | `clipping` | 0 | 2.3s |  |
| 107 | `doubleAndRegister` | 2 | 2.5s |  |
| 108 | `encoding1` | 31 | 6.7s |  |
| 109 | `flash_events_Event` | 3 | 26.3s |  |
| 110 | `flash_geom_ColorTransform` | 0 | 6.7s |  |
| 111 | `flash_net_URLLoader` | 7 | 6.0s |  |
| 112 | `flash_net_URLRequest` | 6 | 5.9s |  |
| 113 | `flash_net_classes` | 22 | 6.1s |  |
| 114 | `flash_utils_Timer` | 2 | 5.8s |  |
| 115 | `fscommand1` | 1 | 1.7s |  |
| 116 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 20.2s |  |
| 117 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 20.9s |  |
| 118 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 2.3s |  |
| 119 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 21.4s |  |
| 120 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 121 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.7s |  |
| 122 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 20.7s |  |
| 123 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 20.4s |  |
| 124 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 20.6s |  |
| 125 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 20.7s |  |
| 126 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 20.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 127 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 21.3s |  |
| 128 | `gradient` | 0 | 2.6s |  |
| 129 | `gradientTransform` | 0 | 21.7s |  |
| 130 | `hardwrap` | 1 | 7.4s |  |
| 131 | `hitTestStyleChange` | 1 | 26.2s |  |
| 132 | `hittesting/mask-hit-test` | 1 | 3.5s |  |
| 133 | `image-loading` | 4 | 6.8s |  |
| 134 | `invalidClipDepth` | 0 | 21.1s |  |
| 135 | `local2global` | 1 | 6.5s |  |
| 136 | `lzma` | 5 | 6.4s |  |
| 137 | `lzma_bytes` | 2 | 25.4s |  |
| 138 | `mouse/mouse_coords` | 2 | 6.6s |  |
| 139 | `mouse/start_drag` | 3 | 27.3s |  |
| 140 | `mouse/start_drag_lock` | 3 | 6.9s |  |
| 141 | `movieclip` | 9 | 6.7s |  |
| 142 | `movieinfo1` | 3 | 2.0s |  |
| 143 | `slider_component` | 4 | 12.3s |  |
| 144 | `stream1` | 9 | 6.7s |  |
| 145 | `stylesheet` | 3 | 6.8s |  |
| 146 | `targetPath1` | 8 | 1.9s |  |
| 147 | `timeline/Timeline3` | 5 | 25.1s |  |
| 148 | `timeline/Timeline4` | 5 | 24.8s |  |
| 149 | `timeline/Timeline8` | 5 | 6.6s |  |
| 150 | `timeline/Timeline9` | 11 | 6.6s |  |
| 151 | `timeline/events/timeline_events_fp10` | 67 | 6.8s |  |
| 152 | `timeline/events/timeline_events_fp9` | 48 | 4.7s |  |
| 153 | `timeline/nav/name` | 8 | 1.1s |  |
| 154 | `timeline/nav/ratio3` | 4 | 1.0s |  |
| 155 | `timeline/nav/shape` | 4 | 1.1s |  |
| 156 | `timeline/scene/EncodedU32` | 1 | 1.1s |  |
| 157 | `timeline/scene/Scene_1_MainTimeline` | 70 | 25.4s |  |
| 158 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 6.8s |  |
| 159 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 6.8s |  |
| 160 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 6.7s |  |
| 161 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 6.4s |  |
| 162 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 6.7s |  |
| 163 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 21.8s |  |
| 164 | `timeline/timeline_as2_1` | 3 | 20.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 165 | `timeline/timeline_as2_2` | 3 | 2.1s |  |
| 166 | `timeline/timeline_as2_3` | 3 | 2.1s |  |
| 167 | `timeline/timeline_as2_4` | 2 | 2.1s |  |
| 168 | `timeline/timeline_as2_5` | 4 | 4.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 169 | `timeline/timeline_loop` | 7 | 9.2s |  |
| 170 | `timeline/timeline_name_0` | 13 | 6.8s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `MaskTest-3` | 1 | 1 | 7.2s |  |
| 2 | `acid/acid-text-x` | 1 | 1 | 5.8s |  |
| 3 | `acid/acid-textfield` | 6 | 7 | 7.1s |  |
| 4 | `as3-loader/LoaderTest` | 2 | 2 | 26.4s |  |
| 5 | `avm1/hitarea` | 2 | 2 | 17.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 6 | `avm1movie` | 9 | 12 | 25.8s |  |
| 7 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 6.7s |  |
| 8 | `flash_net_SharedObject` | 1 | 1 | 6.7s |  |
| 9 | `flash_text_TextField` | 5 | 8 | 25.2s |  |
| 10 | `flash_text_TextField2` | 9 | 9 | 6.4s |  |
| 11 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 21.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 22.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**19 tests** within reach

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
| 11 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14 | 19 | 5 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 13 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18 | 32 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 14 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10 | 18 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 15 | `blendmode/blendmode_1` | 50.0% | 1 | 2 | 1 |  |
| 16 | `blendmode/blendmode_2` | 50.0% | 2 | 4 | 2 |  |
| 17 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14 | 28 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 18 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16 | 32 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 19 | `hittesting/hittesting` | 50.0% | 9 | 18 | 9 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**47 tests** with output mismatch, sorted by match rate (best first)

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
| 11 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14/19 | 19 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 13 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18/32 | 32 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 14 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 15 | `blendmode/blendmode_1` | 50.0% | 1/2 | 2 | 2 |  |
| 16 | `blendmode/blendmode_2` | 50.0% | 2/4 | 3 | 4 |  |
| 17 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14/28 | 28 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 18 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16/32 | 32 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 19 | `hittesting/hittesting` | 50.0% | 9/18 | 10 | 18 |  |
| 20 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 41.5% | 17/41 | 41 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 21 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 38.5% | 10/26 | 26 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 22 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 33.3% | 25/75 | 75 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 23 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 33.3% | 12/36 | 36 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 24 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 30.2% | 29/96 | 96 | 70 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 25 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 30.2% | 19/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 26 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 27 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 28.0% | 21/75 | 75 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 28 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 27.0% | 17/63 | 63 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 29 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 30 | `localconnection` | 25.0% | 3/12 | 5 | 12 |  |
| 31 | `avm2/flash/geom/matrix3d/TransformBasics` | 15.4% | 2/13 | 6 | 13 |  |
| 32 | `as3-loader/events/loader-events` | 13.5% | 5/37 | 37 | 36 |  |
| 33 | `timeline/nav/clipDepth` | 12.5% | 1/8 | 3 | 8 |  |
| 34 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 12.0% | 13/108 | 108 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 35 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 12.0% | 11/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 36 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 8.7% | 15/173 | 173 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 37 | `getobjectsunderpoint` | 2.9% | 1/34 | 1 | 34 |  |
| 38 | `acid/acid-filter` | 0.0% | 0/2 | 0 | 2 |  |
| 39 | `acid/acid-shapes` | 0.0% | 0/120 | 1 | 120 |  |
| 40 | `acid/acid-text-2` | 0.0% | 0/1 | 1 | 1 |  |
| 41 | `as3-loader/bug1157243/empty` | 0.0% | 0/1 | 0 | 1 |  |
| 42 | `as3-loader/bug1157243/invalid` | 0.0% | 0/1 | 0 | 1 |  |
| 43 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 0.0% | 0/56 | 0 | 56 |  |
| 44 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 0.0% | 0/20 | 0 | 20 |  |
| 45 | `bitmapdata/getpixel-from-embedded` | 0.0% | 0/2 | 2 | 2 |  |
| 46 | `esc` | 0.0% | 0/2 | 0 | 2 |  |
| 47 | `stroke1` | 0.0% | 0/4 | 4 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 2 | 18 |
| | *(tests not in any document)* | 195 | 155 | 40 |
