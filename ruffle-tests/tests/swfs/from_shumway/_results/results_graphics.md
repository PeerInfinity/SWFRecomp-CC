# Ruffle Test Results (Unfiltered)

**Date**: 2026-07-27 04:25 UTC

**Git SHA**: `a9900a4786`

**Run Duration**: 45m 18s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 229 |
| Passing | **150** (65.5%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **162** (70.7%) |
| Failing | 67 |
| Total expected lines | 2484 |
| Matching lines | 1603 (64.5%) |
| Mismatched lines | 881 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 67 | 100.0% |

## Passing Tests

**150 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 24.5s |  |
| 2 | `MaskTest` | 0 | 5.9s |  |
| 3 | `MaskTest-2` | 0 | 6.0s |  |
| 4 | `ZeroClipboardTest` | 3 | 23.8s |  |
| 5 | `acid/acid` | 1 | 34.1s |  |
| 6 | `acid/acid-big` | 0 | 39.7s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 24.7s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 21.4s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 20.0s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 3.0s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 5.3s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 5.1s |  |
| 13 | `acid/acid-bitmaps` | 0 | 21.6s |  |
| 14 | `acid/acid-blend` | 0 | 34.4s |  |
| 15 | `acid/acid-blend-2` | 0 | 19.5s |  |
| 16 | `acid/acid-chars` | 0 | 1.5s |  |
| 17 | `acid/acid-child` | 0 | 15.4s |  |
| 18 | `acid/acid-clip` | 0 | 1.7s |  |
| 19 | `acid/acid-clip-2` | 0 | 1.5s |  |
| 20 | `acid/acid-clip-3` | 0 | 4.6s |  |
| 21 | `acid/acid-color` | 0 | 26.4s |  |
| 22 | `acid/acid-color-0` | 0 | 4.0s |  |
| 23 | `acid/acid-color-2` | 0 | 1.9s |  |
| 24 | `acid/acid-filter-2` | 0 | 2.6s |  |
| 25 | `acid/acid-gc` | 0 | 21.5s |  |
| 26 | `acid/acid-gradient` | 0 | 2.4s |  |
| 27 | `acid/acid-gradient-0` | 0 | 22.5s |  |
| 28 | `acid/acid-gradient-1` | 0 | 2.3s |  |
| 29 | `acid/acid-gradient-2` | 0 | 2.3s |  |
| 30 | `acid/acid-image` | 0 | 29.6s |  |
| 31 | `acid/acid-large` | 0 | 77.7s |  |
| 32 | `acid/acid-mask` | 0 | 7.7s |  |
| 33 | `acid/acid-scale` | 0 | 2.2s |  |
| 34 | `acid/acid-small` | 0 | 2.9s |  |
| 35 | `acid/acid-stroke-0` | 0 | 25.6s |  |
| 36 | `acid/acid-text` | 0 | 2.2s |  |
| 37 | `acid/acid-text-3` | 0 | 2.1s |  |
| 38 | `acid/acid-text-4` | 0 | 6.4s |  |
| 39 | `acid/acid-text-5` | 0 | 26.0s |  |
| 40 | `acid/acid-text-6` | 0 | 23.2s |  |
| 41 | `acid/acid-text-escape` | 0 | 2.2s |  |
| 42 | `acid/acid-textfield-scroll` | 5 | 6.7s |  |
| 43 | `acid/acid-video` | 0 | 23.1s |  |
| 44 | `add` | 11 | 1.9s |  |
| 45 | `as3-loader/loaderinfo/Preloader` | 1 | 6.4s |  |
| 46 | `avm1/array` | 7 | 1.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 47 | `avm1/bitmapdata/getPixel` | 2 | 1.3s |  |
| 48 | `avm1/bitmapdata/loadBitmap` | 3 | 1.6s |  |
| 49 | `avm1/callee` | 2 | 1.6s |  |
| 50 | `avm1/depth` | 6 | 1.7s |  |
| 51 | `avm1/doactionorder/doactionorder` | 7 | 1.9s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 52 | `avm1/doactionorder/symbolclass` | 4 | 1.7s |  |
| 53 | `avm1/duplicateMovieClip/dontremove` | 6 | 1.8s |  |
| 54 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 1.7s |  |
| 55 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.6s |  |
| 56 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.8s |  |
| 57 | `avm1/externalinterface` | 4 | 1.6s |  |
| 58 | `avm1/filters` | 149 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 59 | `avm1/haxe/flocons1` | 2 | 1.7s |  |
| 60 | `avm1/haxe/flocons2` | 3 | 1.6s |  |
| 61 | `avm1/label` | 4 | 1.9s |  |
| 62 | `avm1/levels` | 9 | 1.9s |  |
| 63 | `avm1/loadevent` | 9 | 2.1s |  |
| 64 | `avm1/loadvariables/loadvariables` | 7 | 2.0s |  |
| 65 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 66 | `avm1/lookup` | 3 | 0.8s |  |
| 67 | `avm1/mouse-transparency` | 1 | 2.0s |  |
| 68 | `avm1/moviecliploader` | 7 | 20.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 69 | `avm1/nativeinheritance` | 6 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 70 | `avm1/nested-button` | 1 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 71 | `avm1/operations` | 13 | 2.0s |  |
| 72 | `avm1/property-paths/property-paths-6` | 6 | 1.9s |  |
| 73 | `avm1/property-paths/property-paths-7` | 7 | 1.7s |  |
| 74 | `avm1/propertycase/propertycase` | 7 | 1.9s |  |
| 75 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.9s |  |
| 76 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.7s |  |
| 77 | `avm1/rollover` | 4 | 2.1s |  |
| 78 | `avm1/scope` | 14 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 79 | `avm1/setinterval` | 20 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 80 | `avm1/settimeout` | 17 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 81 | `avm1/super` | 11 | 1.9s |  |
| 82 | `avm1/target` | 18 | 1.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/text-bind` | 0 | 21.0s |  |
| 84 | `avm1/textfield/textfield-html` | 4 | 2.0s |  |
| 85 | `avm1/textfield/textfield-text-setters` | 8 | 2.0s |  |
| 86 | `avm1/undefined/undefined-swf6` | 39 | 2.1s |  |
| 87 | `avm1/undefined/undefined-swf7` | 39 | 1.8s |  |
| 88 | `avm1/watch` | 2 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 89 | `avm1/xml/xmlbuild` | 1 | 1.2s |  |
| 90 | `avm1/xml/xmlload` | 4 | 2.5s |  |
| 91 | `avm1/xml/xmlstring` | 9 | 2.0s |  |
| 92 | `avm1timeline1` | 3 | 2.2s |  |
| 93 | `avm1timeline2` | 6 | 2.0s |  |
| 94 | `avm2/event-dispatching` | 5 | 5.9s |  |
| 95 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 6.7s |  |
| 96 | `bitmapbuttons` | 0 | 27.0s |  |
| 97 | `bitmapdata/draw-and-read` | 1 | 5.5s |  |
| 98 | `blendmode/blendmode_3` | 2 | 5.2s |  |
| 99 | `button1` | 1 | 3.5s |  |
| 100 | `button2` | 1 | 6.3s |  |
| 101 | `button3` | 1 | 2.6s |  |
| 102 | `captions` | 8 | 7.0s |  |
| 103 | `clipping` | 0 | 2.4s |  |
| 104 | `doubleAndRegister` | 2 | 2.6s |  |
| 105 | `flash_geom_ColorTransform` | 0 | 27.4s |  |
| 106 | `flash_net_URLRequest` | 6 | 5.6s |  |
| 107 | `flash_net_classes` | 22 | 5.7s |  |
| 108 | `flash_utils_Timer` | 2 | 5.4s |  |
| 109 | `fscommand1` | 1 | 1.6s |  |
| 110 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 20.4s |  |
| 111 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 20.9s |  |
| 112 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 2.3s |  |
| 113 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 21.1s |  |
| 114 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 23.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 115 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 23.0s |  |
| 116 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 21.5s |  |
| 117 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 21.3s |  |
| 118 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 21.8s |  |
| 119 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 21.7s |  |
| 120 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 21.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 121 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 19.7s |  |
| 122 | `gradient` | 0 | 2.4s |  |
| 123 | `gradientTransform` | 0 | 20.9s |  |
| 124 | `hardwrap` | 1 | 6.7s |  |
| 125 | `invalidClipDepth` | 0 | 20.2s |  |
| 126 | `mouse/mouse_coords` | 2 | 5.5s |  |
| 127 | `mouse/start_drag` | 3 | 24.1s |  |
| 128 | `movieclip` | 9 | 5.8s |  |
| 129 | `movieinfo1` | 3 | 1.9s |  |
| 130 | `slider_component` | 4 | 11.3s |  |
| 131 | `stylesheet` | 3 | 6.3s |  |
| 132 | `targetPath1` | 8 | 1.9s |  |
| 133 | `timeline/Timeline3` | 5 | 24.4s |  |
| 134 | `timeline/Timeline4` | 5 | 24.6s |  |
| 135 | `timeline/Timeline8` | 5 | 6.1s |  |
| 136 | `timeline/Timeline9` | 11 | 6.1s |  |
| 137 | `timeline/events/timeline_events_fp10` | 67 | 6.5s |  |
| 138 | `timeline/events/timeline_events_fp9` | 48 | 25.8s |  |
| 139 | `timeline/nav/name` | 8 | 23.1s |  |
| 140 | `timeline/nav/ratio3` | 4 | 0.9s |  |
| 141 | `timeline/nav/shape` | 4 | 4.5s |  |
| 142 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 5.9s |  |
| 143 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 5.9s |  |
| 144 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 5.6s |  |
| 145 | `timeline/timeline_as2_1` | 3 | 20.0s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 146 | `timeline/timeline_as2_2` | 3 | 2.0s |  |
| 147 | `timeline/timeline_as2_3` | 3 | 19.9s |  |
| 148 | `timeline/timeline_as2_4` | 2 | 20.1s |  |
| 149 | `timeline/timeline_as2_5` | 4 | 4.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 150 | `timeline/timeline_name_0` | 13 | 24.2s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `MaskTest-3` | 1 | 1 | 24.4s |  |
| 2 | `acid/acid-text-x` | 1 | 1 | 6.3s |  |
| 3 | `acid/acid-textfield` | 6 | 7 | 6.9s |  |
| 4 | `avm1/hitarea` | 2 | 2 | 17.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 5 | `avm1movie` | 9 | 12 | 27.6s |  |
| 6 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 5.8s |  |
| 7 | `flash_net_SharedObject` | 1 | 1 | 6.6s |  |
| 8 | `flash_text_TextField` | 5 | 8 | 24.9s |  |
| 9 | `flash_text_TextField2` | 9 | 9 | 6.0s |  |
| 10 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 4 | 27 | 24.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 11 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 20 | 38 | 23.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 12 | `hittesting/mask-hit-test` | 1 | 1 | 2.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**30 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `timeline/scene/Scene_1_MainTimeline` | 97.2% | 70 | 72 | 2 |  |
| 2 | `timeline/scene/Scene_2_MovieClipTimeline` | 97.2% | 70 | 72 | 2 |  |
| 3 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 95.2% | 40 | 42 | 2 |  |
| 4 | `encoding1` | 93.9% | 31 | 33 | 2 |  |
| 5 | `timeline/nav/matrix` | 87.5% | 7 | 8 | 1 |  |
| 6 | `timeline/scene/Scene_7_NextPrevScene` | 77.8% | 7 | 9 | 2 |  |
| 7 | `timeline/timeline_loop` | 77.8% | 7 | 9 | 2 |  |
| 8 | `timeline/nav/blendMode` | 75.0% | 6 | 8 | 2 |  |
| 9 | `timeline/nav/cacheAsBitmap` | 75.0% | 6 | 8 | 2 |  |
| 10 | `timeline/nav/colorTransform` | 75.0% | 6 | 8 | 2 |  |
| 11 | `timeline/nav/filters` | 75.0% | 6 | 8 | 2 |  |
| 12 | `timeline/nav/morphShape` | 75.0% | 3 | 4 | 1 |  |
| 13 | `timeline/nav/ratio` | 75.0% | 3 | 4 | 1 |  |
| 14 | `timeline/nav/ratio2` | 75.0% | 3 | 4 | 1 |  |
| 15 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14 | 19 | 5 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 16 | `as3-loader/loaderinfo/loaded-content-properties` | 72.0% | 36 | 50 | 14 |  |
| 17 | `lzma` | 71.4% | 5 | 7 | 2 |  |
| 18 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 19 | `image-loading` | 66.7% | 4 | 6 | 2 |  |
| 20 | `mouse/start_drag_lock` | 66.7% | 2 | 3 | 1 |  |
| 21 | `flash_events_Event` | 60.0% | 3 | 5 | 2 |  |
| 22 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18 | 32 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 23 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10 | 18 | 8 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 24 | `as3-loader/LoaderTest` | 50.0% | 5 | 10 | 5 |  |
| 25 | `blendmode/blendmode_1` | 50.0% | 1 | 2 | 1 |  |
| 26 | `blendmode/blendmode_2` | 50.0% | 2 | 4 | 2 |  |
| 27 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14 | 28 | 14 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 28 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16 | 32 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 29 | `hittesting/hittesting` | 50.0% | 9 | 18 | 9 |  |
| 30 | `lzma_bytes` | 50.0% | 2 | 4 | 2 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**67 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `timeline/scene/Scene_1_MainTimeline` | 97.2% | 70/72 | 72 | 70 |  |
| 2 | `timeline/scene/Scene_2_MovieClipTimeline` | 97.2% | 70/72 | 72 | 70 |  |
| 3 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 95.2% | 40/42 | 42 | 40 |  |
| 4 | `encoding1` | 93.9% | 31/33 | 33 | 31 |  |
| 5 | `timeline/nav/matrix` | 87.5% | 7/8 | 8 | 8 |  |
| 6 | `timeline/scene/Scene_7_NextPrevScene` | 77.8% | 7/9 | 9 | 7 |  |
| 7 | `timeline/timeline_loop` | 77.8% | 7/9 | 9 | 7 |  |
| 8 | `timeline/nav/blendMode` | 75.0% | 6/8 | 8 | 8 |  |
| 9 | `timeline/nav/cacheAsBitmap` | 75.0% | 6/8 | 8 | 8 |  |
| 10 | `timeline/nav/colorTransform` | 75.0% | 6/8 | 8 | 8 |  |
| 11 | `timeline/nav/filters` | 75.0% | 6/8 | 8 | 8 |  |
| 12 | `timeline/nav/morphShape` | 75.0% | 3/4 | 4 | 4 |  |
| 13 | `timeline/nav/ratio` | 75.0% | 3/4 | 4 | 4 |  |
| 14 | `timeline/nav/ratio2` | 75.0% | 3/4 | 4 | 4 |  |
| 15 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 73.7% | 14/19 | 19 | 19 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 16 | `as3-loader/loaderinfo/loaded-content-properties` | 72.0% | 36/50 | 50 | 48 |  |
| 17 | `lzma` | 71.4% | 5/7 | 7 | 5 |  |
| 18 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 19 | `image-loading` | 66.7% | 4/6 | 6 | 4 |  |
| 20 | `mouse/start_drag_lock` | 66.7% | 2/3 | 3 | 3 |  |
| 21 | `flash_events_Event` | 60.0% | 3/5 | 5 | 3 |  |
| 22 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 56.2% | 18/32 | 32 | 26 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 23 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 55.6% | 10/18 | 18 | 16 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 24 | `as3-loader/LoaderTest` | 50.0% | 5/10 | 10 | 9 |  |
| 25 | `blendmode/blendmode_1` | 50.0% | 1/2 | 2 | 2 |  |
| 26 | `blendmode/blendmode_2` | 50.0% | 2/4 | 3 | 4 |  |
| 27 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 50.0% | 14/28 | 28 | 25 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 28 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 50.0% | 16/32 | 32 | 22 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 29 | `hittesting/hittesting` | 50.0% | 9/18 | 12 | 18 |  |
| 30 | `lzma_bytes` | 50.0% | 2/4 | 4 | 2 |  |
| 31 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 41.5% | 17/41 | 41 | 35 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 32 | `as3-loader/LoaderLoadBytesTest2` | 40.0% | 2/5 | 5 | 3 |  |
| 33 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 38.5% | 10/26 | 26 | 24 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 34 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 33.3% | 25/75 | 75 | 57 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 35 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 33.3% | 12/36 | 36 | 29 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 36 | `hitTestStyleChange` | 33.3% | 1/3 | 3 | 1 |  |
| 37 | `local2global` | 33.3% | 1/3 | 3 | 1 |  |
| 38 | `timeline/scene/EncodedU32` | 33.3% | 1/3 | 3 | 1 |  |
| 39 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 30.2% | 29/96 | 96 | 70 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 40 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 30.2% | 19/63 | 63 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 41 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 42 | `as3-loader/LoaderTest2` | 28.6% | 2/7 | 7 | 7 |  |
| 43 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 28.0% | 21/75 | 75 | 50 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 44 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 27.0% | 17/63 | 63 | 37 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 45 | `as3-loader/LoaderLoadBytesTest` | 20.0% | 1/5 | 5 | 4 |  |
| 46 | `as3-interfaces` | 16.7% | 1/6 | 6 | 6 |  |
| 47 | `avm2/flash/geom/matrix3d/TransformBasics` | 15.4% | 2/13 | 8 | 13 |  |
| 48 | `as3-loader/events/loader-events` | 13.9% | 5/36 | 31 | 36 |  |
| 49 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 12.0% | 13/108 | 108 | 67 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 50 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 12.0% | 11/92 | 92 | 48 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 51 | `timeline/nav/clipDepth` | 11.1% | 1/9 | 9 | 8 |  |
| 52 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 8.7% | 15/173 | 173 | 71 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 53 | `getobjectsunderpoint` | 2.9% | 1/34 | 3 | 34 |  |
| 54 | `acid/acid-filter` | 0.0% | 0/2 | 2 | 2 |  |
| 55 | `acid/acid-shapes` | 0.0% | 0/120 | 7 | 120 |  |
| 56 | `acid/acid-text-2` | 0.0% | 0/1 | 1 | 1 |  |
| 57 | `as3-loader/bug1093712/loader` | 0.0% | 0/1 | 0 | 1 |  |
| 58 | `as3-loader/bug1157243/empty` | 0.0% | 0/1 | 0 | 1 |  |
| 59 | `as3-loader/bug1157243/invalid` | 0.0% | 0/1 | 0 | 1 |  |
| 60 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 0.0% | 0/56 | 4 | 56 |  |
| 61 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 0.0% | 0/20 | 2 | 20 |  |
| 62 | `bitmapdata/getpixel-from-embedded` | 0.0% | 0/4 | 4 | 2 |  |
| 63 | `esc` | 0.0% | 0/13 | 13 | 2 |  |
| 64 | `flash_net_URLLoader` | 0.0% | 0/7 | 1 | 7 |  |
| 65 | `localconnection` | 0.0% | 0/12 | 2 | 12 |  |
| 66 | `stream1` | 0.0% | 0/9 | 2 | 9 |  |
| 67 | `stroke1` | 0.0% | 0/6 | 6 | 1 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 2 | 18 |
| | *(tests not in any document)* | 195 | 135 | 60 |
