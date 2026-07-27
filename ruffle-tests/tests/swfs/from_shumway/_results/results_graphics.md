# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 05:37 UTC

**Git SHA**: `dfef7a9d69`

**Run Duration**: 39m 46s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 229 |
| Passing | **163** (71.2%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **175** (76.4%) |
| Failing | 54 |
| Total expected lines | 2484 |
| Matching lines | 1603 (64.5%) |
| Mismatched lines | 881 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 54 | 100.0% |

## Passing Tests

**163 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 18.7s |  |
| 2 | `MaskTest` | 0 | 4.1s |  |
| 3 | `MaskTest-2` | 0 | 2.0s |  |
| 4 | `ZeroClipboardTest` | 3 | 18.6s |  |
| 5 | `acid/acid` | 1 | 25.4s |  |
| 6 | `acid/acid-big` | 0 | 30.9s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 19.0s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 26.6s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 25.4s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 4.3s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 7.1s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 6.7s |  |
| 13 | `acid/acid-bitmaps` | 0 | 27.3s |  |
| 14 | `acid/acid-blend` | 0 | 43.7s |  |
| 15 | `acid/acid-blend-2` | 0 | 25.6s |  |
| 16 | `acid/acid-chars` | 0 | 1.4s |  |
| 17 | `acid/acid-child` | 0 | 15.7s |  |
| 18 | `acid/acid-clip` | 0 | 1.8s |  |
| 19 | `acid/acid-clip-2` | 0 | 1.4s |  |
| 20 | `acid/acid-clip-3` | 0 | 4.7s |  |
| 21 | `acid/acid-color` | 0 | 25.2s |  |
| 22 | `acid/acid-color-0` | 0 | 3.7s |  |
| 23 | `acid/acid-color-2` | 0 | 1.5s |  |
| 24 | `acid/acid-filter-2` | 0 | 2.5s |  |
| 25 | `acid/acid-gc` | 0 | 2.3s |  |
| 26 | `acid/acid-gradient` | 0 | 2.3s |  |
| 27 | `acid/acid-gradient-0` | 0 | 21.6s |  |
| 28 | `acid/acid-gradient-1` | 0 | 2.2s |  |
| 29 | `acid/acid-gradient-2` | 0 | 2.2s |  |
| 30 | `acid/acid-image` | 0 | 28.0s |  |
| 31 | `acid/acid-large` | 0 | 81.5s |  |
| 32 | `acid/acid-mask` | 0 | 8.3s |  |
| 33 | `acid/acid-scale` | 0 | 2.5s |  |
| 34 | `acid/acid-small` | 0 | 3.1s |  |
| 35 | `acid/acid-stroke-0` | 0 | 28.1s |  |
| 36 | `acid/acid-text` | 0 | 2.3s |  |
| 37 | `acid/acid-text-3` | 0 | 2.2s |  |
| 38 | `acid/acid-text-4` | 0 | 6.6s |  |
| 39 | `acid/acid-text-5` | 0 | 26.8s |  |
| 40 | `acid/acid-text-6` | 0 | 23.7s |  |
| 41 | `acid/acid-text-escape` | 0 | 2.2s |  |
| 42 | `acid/acid-textfield-scroll` | 5 | 6.3s |  |
| 43 | `acid/acid-video` | 0 | 21.7s |  |
| 44 | `add` | 11 | 1.8s |  |
| 45 | `as3-loader/loaderinfo/Preloader` | 1 | 6.5s |  |
| 46 | `avm1/array` | 7 | 1.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 47 | `avm1/bitmapdata/getPixel` | 2 | 1.5s |  |
| 48 | `avm1/bitmapdata/loadBitmap` | 3 | 1.9s |  |
| 49 | `avm1/callee` | 2 | 1.8s |  |
| 50 | `avm1/depth` | 6 | 2.0s |  |
| 51 | `avm1/doactionorder/doactionorder` | 7 | 2.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 52 | `avm1/doactionorder/symbolclass` | 4 | 2.2s |  |
| 53 | `avm1/duplicateMovieClip/dontremove` | 6 | 2.0s |  |
| 54 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.0s |  |
| 55 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.9s |  |
| 56 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.0s |  |
| 57 | `avm1/externalinterface` | 4 | 1.9s |  |
| 58 | `avm1/filters` | 149 | 2.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 59 | `avm1/haxe/flocons1` | 2 | 1.9s |  |
| 60 | `avm1/haxe/flocons2` | 3 | 1.9s |  |
| 61 | `avm1/label` | 4 | 2.2s |  |
| 62 | `avm1/levels` | 9 | 2.1s |  |
| 63 | `avm1/loadevent` | 9 | 2.2s |  |
| 64 | `avm1/loadvariables/loadvariables` | 7 | 2.0s |  |
| 65 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 66 | `avm1/lookup` | 3 | 0.8s |  |
| 67 | `avm1/mouse-transparency` | 1 | 2.2s |  |
| 68 | `avm1/moviecliploader` | 7 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 69 | `avm1/nativeinheritance` | 6 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 70 | `avm1/nested-button` | 1 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 71 | `avm1/operations` | 13 | 1.8s |  |
| 72 | `avm1/property-paths/property-paths-6` | 6 | 1.7s |  |
| 73 | `avm1/property-paths/property-paths-7` | 7 | 1.5s |  |
| 74 | `avm1/propertycase/propertycase` | 7 | 1.7s |  |
| 75 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.7s |  |
| 76 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.5s |  |
| 77 | `avm1/rollover` | 4 | 1.8s |  |
| 78 | `avm1/scope` | 14 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 79 | `avm1/setinterval` | 20 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 80 | `avm1/settimeout` | 17 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 81 | `avm1/super` | 11 | 1.9s |  |
| 82 | `avm1/target` | 18 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/text-bind` | 0 | 21.0s |  |
| 84 | `avm1/textfield/textfield-html` | 4 | 2.0s |  |
| 85 | `avm1/textfield/textfield-text-setters` | 8 | 2.0s |  |
| 86 | `avm1/undefined/undefined-swf6` | 39 | 1.9s |  |
| 87 | `avm1/undefined/undefined-swf7` | 39 | 1.6s |  |
| 88 | `avm1/watch` | 2 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 89 | `avm1/xml/xmlbuild` | 1 | 0.7s |  |
| 90 | `avm1/xml/xmlload` | 4 | 2.2s |  |
| 91 | `avm1/xml/xmlstring` | 9 | 1.8s |  |
| 92 | `avm1timeline1` | 3 | 1.9s |  |
| 93 | `avm1timeline2` | 6 | 2.0s |  |
| 94 | `avm2/event-dispatching` | 5 | 5.9s |  |
| 95 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 7.0s |  |
| 96 | `bitmapbuttons` | 0 | 28.0s |  |
| 97 | `bitmapdata/draw-and-read` | 1 | 6.3s |  |
| 98 | `blendmode/blendmode_3` | 2 | 6.3s |  |
| 99 | `button1` | 1 | 4.6s |  |
| 100 | `button2` | 1 | 7.8s |  |
| 101 | `button3` | 1 | 3.5s |  |
| 102 | `captions` | 8 | 6.4s |  |
| 103 | `clipping` | 0 | 2.2s |  |
| 104 | `doubleAndRegister` | 2 | 2.4s |  |
| 105 | `encoding1` | 31 | 5.9s |  |
| 106 | `flash_events_Event` | 3 | 23.8s |  |
| 107 | `flash_geom_ColorTransform` | 0 | 24.1s |  |
| 108 | `flash_net_URLRequest` | 6 | 4.7s |  |
| 109 | `flash_net_classes` | 22 | 4.8s |  |
| 110 | `flash_utils_Timer` | 2 | 4.7s |  |
| 111 | `fscommand1` | 1 | 1.4s |  |
| 112 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 17.2s |  |
| 113 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 20.8s |  |
| 114 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 2.2s |  |
| 115 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 20.8s |  |
| 116 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 20.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 117 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 19.6s |  |
| 118 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 19.6s |  |
| 119 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 16.6s |  |
| 120 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 16.8s |  |
| 121 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 16.8s |  |
| 122 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 16.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 123 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 20.4s |  |
| 124 | `gradient` | 0 | 2.3s |  |
| 125 | `gradientTransform` | 0 | 20.1s |  |
| 126 | `hardwrap` | 1 | 6.5s |  |
| 127 | `hitTestStyleChange` | 1 | 23.9s |  |
| 128 | `image-loading` | 4 | 6.0s |  |
| 129 | `invalidClipDepth` | 0 | 20.8s |  |
| 130 | `local2global` | 1 | 6.0s |  |
| 131 | `lzma` | 5 | 5.8s |  |
| 132 | `lzma_bytes` | 2 | 24.1s |  |
| 133 | `mouse/mouse_coords` | 2 | 5.9s |  |
| 134 | `mouse/start_drag` | 3 | 24.1s |  |
| 135 | `movieclip` | 9 | 5.9s |  |
| 136 | `movieinfo1` | 3 | 1.9s |  |
| 137 | `slider_component` | 4 | 11.6s |  |
| 138 | `stylesheet` | 3 | 6.5s |  |
| 139 | `targetPath1` | 8 | 2.0s |  |
| 140 | `timeline/Timeline3` | 5 | 25.7s |  |
| 141 | `timeline/Timeline4` | 5 | 25.6s |  |
| 142 | `timeline/Timeline8` | 5 | 6.3s |  |
| 143 | `timeline/Timeline9` | 11 | 6.4s |  |
| 144 | `timeline/events/timeline_events_fp10` | 67 | 6.7s |  |
| 145 | `timeline/events/timeline_events_fp9` | 48 | 6.4s |  |
| 146 | `timeline/nav/name` | 8 | 0.9s |  |
| 147 | `timeline/nav/ratio3` | 4 | 0.9s |  |
| 148 | `timeline/nav/shape` | 4 | 0.9s |  |
| 149 | `timeline/scene/EncodedU32` | 1 | 0.9s |  |
| 150 | `timeline/scene/Scene_1_MainTimeline` | 70 | 24.1s |  |
| 151 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 5.9s |  |
| 152 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 5.9s |  |
| 153 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 5.8s |  |
| 154 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 5.6s |  |
| 155 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 5.8s |  |
| 156 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 20.7s |  |
| 157 | `timeline/timeline_as2_1` | 3 | 20.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 158 | `timeline/timeline_as2_2` | 3 | 2.0s |  |
| 159 | `timeline/timeline_as2_3` | 3 | 2.0s |  |
| 160 | `timeline/timeline_as2_4` | 2 | 2.0s |  |
| 161 | `timeline/timeline_as2_5` | 4 | 4.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 162 | `timeline/timeline_loop` | 7 | 8.3s |  |
| 163 | `timeline/timeline_name_0` | 13 | 6.0s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `MaskTest-3` | 1 | 1 | 4.2s |  |
| 2 | `acid/acid-text-x` | 1 | 1 | 6.4s |  |
| 3 | `acid/acid-textfield` | 6 | 7 | 6.5s |  |
| 4 | `avm1/hitarea` | 2 | 2 | 20.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm1movie` | 9 | 12 | 23.9s |  |
| 6 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 5.9s |  |
| 7 | `flash_net_SharedObject` | 1 | 1 | 5.9s |  |
| 8 | `flash_text_TextField` | 5 | 8 | 21.0s |  |
| 9 | `flash_text_TextField2` | 9 | 9 | 5.1s |  |
| 10 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 20.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 17.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `hittesting/mask-hit-test` | 1 | 1 | 2.8s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**21 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `timeline/nav/matrix` | 87.5% | 7 | 8 | 1 |  |
| 2 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36 | 48 | 12 |  |
| 3 | `timeline/nav/blendMode` | 75.0% | 6 | 8 | 2 |  |
| 4 | `timeline/nav/cacheAsBitmap` | 75.0% | 6 | 8 | 2 |  |
| 5 | `timeline/nav/colorTransform` | 75.0% | 6 | 8 | 2 |  |
| 6 | `timeline/nav/filters` | 75.0% | 6 | 8 | 2 |  |
| 7 | `timeline/nav/morphShape` | 75.0% | 3 | 4 | 1 |  |
| 8 | `timeline/nav/ratio` | 75.0% | 3 | 4 | 1 |  |
| 9 | `timeline/nav/ratio2` | 75.0% | 3 | 4 | 1 |  |
| 10 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14 | 19 | 5 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 12 | `as3-loader/LoaderLoadBytesTest2` | 66.7% | 2 | 3 | 1 |  |
| 13 | `mouse/start_drag_lock` | 66.7% | 2 | 3 | 1 |  |
| 14 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18 | 32 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 15 | `as3-loader/LoaderTest` | 55.6% | 5 | 9 | 4 |  |
| 16 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10 | 18 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 17 | `blendmode/blendmode_1` | 50.0% | 1 | 2 | 1 |  |
| 18 | `blendmode/blendmode_2` | 50.0% | 2 | 4 | 2 |  |
| 19 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14 | 28 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 20 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16 | 32 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 21 | `hittesting/hittesting` | 50.0% | 9 | 18 | 9 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**54 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `timeline/nav/matrix` | 87.5% | 7/8 | 8 | 8 |  |
| 2 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36/48 | 48 | 48 |  |
| 3 | `timeline/nav/blendMode` | 75.0% | 6/8 | 8 | 8 |  |
| 4 | `timeline/nav/cacheAsBitmap` | 75.0% | 6/8 | 8 | 8 |  |
| 5 | `timeline/nav/colorTransform` | 75.0% | 6/8 | 8 | 8 |  |
| 6 | `timeline/nav/filters` | 75.0% | 6/8 | 8 | 8 |  |
| 7 | `timeline/nav/morphShape` | 75.0% | 3/4 | 4 | 4 |  |
| 8 | `timeline/nav/ratio` | 75.0% | 3/4 | 4 | 4 |  |
| 9 | `timeline/nav/ratio2` | 75.0% | 3/4 | 4 | 4 |  |
| 10 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14/19 | 19 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 12 | `as3-loader/LoaderLoadBytesTest2` | 66.7% | 2/3 | 3 | 3 |  |
| 13 | `mouse/start_drag_lock` | 66.7% | 2/3 | 3 | 3 |  |
| 14 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18/32 | 32 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 15 | `as3-loader/LoaderTest` | 55.6% | 5/9 | 8 | 9 |  |
| 16 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 17 | `blendmode/blendmode_1` | 50.0% | 1/2 | 2 | 2 |  |
| 18 | `blendmode/blendmode_2` | 50.0% | 2/4 | 3 | 4 |  |
| 19 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14/28 | 28 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 20 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16/32 | 32 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 21 | `hittesting/hittesting` | 50.0% | 9/18 | 10 | 18 |  |
| 22 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 41.5% | 17/41 | 41 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 23 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 38.5% | 10/26 | 26 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 24 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 33.3% | 25/75 | 75 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 25 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 33.3% | 12/36 | 36 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 26 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 30.2% | 29/96 | 96 | 70 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 27 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 30.2% | 19/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 28 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 29 | `as3-loader/LoaderTest2` | 28.6% | 2/7 | 4 | 7 |  |
| 30 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 28.0% | 21/75 | 75 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 31 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 27.0% | 17/63 | 63 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 32 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 33 | `as3-interfaces` | 16.7% | 1/6 | 4 | 6 |  |
| 34 | `avm2/flash/geom/matrix3d/TransformBasics` | 15.4% | 2/13 | 6 | 13 |  |
| 35 | `as3-loader/events/loader-events` | 13.9% | 5/36 | 26 | 36 |  |
| 36 | `timeline/nav/clipDepth` | 12.5% | 1/8 | 3 | 8 |  |
| 37 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 12.0% | 13/108 | 108 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 38 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 12.0% | 11/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 39 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 8.7% | 15/173 | 173 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 40 | `getobjectsunderpoint` | 2.9% | 1/34 | 1 | 34 |  |
| 41 | `acid/acid-filter` | 0.0% | 0/2 | 0 | 2 |  |
| 42 | `acid/acid-shapes` | 0.0% | 0/120 | 1 | 120 |  |
| 43 | `acid/acid-text-2` | 0.0% | 0/1 | 1 | 1 |  |
| 44 | `as3-loader/bug1093712/loader` | 0.0% | 0/1 | 0 | 1 |  |
| 45 | `as3-loader/bug1157243/empty` | 0.0% | 0/1 | 0 | 1 |  |
| 46 | `as3-loader/bug1157243/invalid` | 0.0% | 0/1 | 0 | 1 |  |
| 47 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 0.0% | 0/56 | 0 | 56 |  |
| 48 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 0.0% | 0/20 | 0 | 20 |  |
| 49 | `bitmapdata/getpixel-from-embedded` | 0.0% | 0/2 | 2 | 2 |  |
| 50 | `esc` | 0.0% | 0/2 | 0 | 2 |  |
| 51 | `flash_net_URLLoader` | 0.0% | 0/7 | 1 | 7 |  |
| 52 | `localconnection` | 0.0% | 0/12 | 2 | 12 |  |
| 53 | `stream1` | 0.0% | 0/9 | 0 | 9 |  |
| 54 | `stroke1` | 0.0% | 0/4 | 4 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 2 | 18 |
| | *(tests not in any document)* | 195 | 148 | 47 |
