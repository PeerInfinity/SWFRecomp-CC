# Ruffle Test Results (Unfiltered)

**Date**: 2026-08-12 23:11 UTC

**Git SHA**: `bf585e4486`

**Run Duration**: 48m 20s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 229 |
| Passing | **206** (90.0%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **218** (95.2%) |
| Failing | 11 |
| Total expected lines | 2484 |
| Matching lines | 2169 (87.3%) |
| Mismatched lines | 315 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 11 | 100.0% |

## Passing Tests

**206 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 27.9s |  |
| 2 | `MaskTest` | 0 | 8.0s |  |
| 3 | `MaskTest-2` | 0 | 8.3s |  |
| 4 | `ZeroClipboardTest` | 3 | 26.9s |  |
| 5 | `acid/acid` | 1 | 36.2s |  |
| 6 | `acid/acid-big` | 0 | 47.6s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 27.6s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 28.5s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 25.4s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 4.3s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 8.5s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 8.4s |  |
| 13 | `acid/acid-bitmaps` | 0 | 28.1s |  |
| 14 | `acid/acid-blend` | 0 | 41.7s |  |
| 15 | `acid/acid-blend-2` | 0 | 26.0s |  |
| 16 | `acid/acid-chars` | 0 | 2.2s |  |
| 17 | `acid/acid-child` | 0 | 21.1s |  |
| 18 | `acid/acid-clip` | 0 | 2.4s |  |
| 19 | `acid/acid-clip-2` | 0 | 2.3s |  |
| 20 | `acid/acid-clip-3` | 0 | 8.2s |  |
| 21 | `acid/acid-color` | 0 | 35.9s |  |
| 22 | `acid/acid-color-0` | 0 | 5.2s |  |
| 23 | `acid/acid-color-2` | 0 | 2.3s |  |
| 24 | `acid/acid-filter` | 2 | 7.8s |  |
| 25 | `acid/acid-filter-2` | 0 | 2.4s |  |
| 26 | `acid/acid-gc` | 0 | 2.1s |  |
| 27 | `acid/acid-gradient` | 0 | 2.4s |  |
| 28 | `acid/acid-gradient-0` | 0 | 22.5s |  |
| 29 | `acid/acid-gradient-1` | 0 | 2.6s |  |
| 30 | `acid/acid-gradient-2` | 0 | 2.0s |  |
| 31 | `acid/acid-image` | 0 | 30.8s |  |
| 32 | `acid/acid-large` | 0 | 76.8s |  |
| 33 | `acid/acid-mask` | 0 | 9.4s |  |
| 34 | `acid/acid-scale` | 0 | 2.3s |  |
| 35 | `acid/acid-small` | 0 | 2.9s |  |
| 36 | `acid/acid-stroke-0` | 0 | 27.4s |  |
| 37 | `acid/acid-text` | 0 | 2.6s |  |
| 38 | `acid/acid-text-2` | 1 | 3.8s |  |
| 39 | `acid/acid-text-3` | 0 | 2.3s |  |
| 40 | `acid/acid-text-4` | 0 | 8.4s |  |
| 41 | `acid/acid-text-5` | 0 | 30.2s |  |
| 42 | `acid/acid-text-6` | 0 | 24.8s |  |
| 43 | `acid/acid-text-escape` | 0 | 2.5s |  |
| 44 | `acid/acid-textfield-scroll` | 5 | 8.2s |  |
| 45 | `acid/acid-video` | 0 | 23.2s |  |
| 46 | `add` | 11 | 2.1s |  |
| 47 | `as3-interfaces` | 6 | 27.3s |  |
| 48 | `as3-loader/LoaderLoadBytesTest2` | 3 | 7.9s |  |
| 49 | `as3-loader/bug1093712/loader` | 1 | 8.0s |  |
| 50 | `as3-loader/bug1157243/empty` | 1 | 7.8s |  |
| 51 | `as3-loader/bug1157243/invalid` | 1 | 7.7s |  |
| 52 | `as3-loader/loaderinfo/Preloader` | 1 | 7.9s |  |
| 53 | `avm1/array` | 7 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 54 | `avm1/bitmapdata/getPixel` | 2 | 1.4s |  |
| 55 | `avm1/bitmapdata/loadBitmap` | 3 | 1.4s |  |
| 56 | `avm1/callee` | 2 | 1.4s |  |
| 57 | `avm1/depth` | 6 | 1.5s |  |
| 58 | `avm1/doactionorder/doactionorder` | 7 | 1.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 59 | `avm1/doactionorder/symbolclass` | 4 | 1.5s |  |
| 60 | `avm1/duplicateMovieClip/dontremove` | 6 | 17.1s |  |
| 61 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 1.6s |  |
| 62 | `avm1/duplicateMovieClip/name-coercion` | 3 | 2.1s |  |
| 63 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.2s |  |
| 64 | `avm1/externalinterface` | 4 | 2.0s |  |
| 65 | `avm1/filters` | 149 | 2.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 66 | `avm1/haxe/flocons1` | 2 | 2.1s |  |
| 67 | `avm1/haxe/flocons2` | 3 | 2.0s |  |
| 68 | `avm1/label` | 4 | 2.3s |  |
| 69 | `avm1/levels` | 9 | 2.2s |  |
| 70 | `avm1/loadevent` | 9 | 2.3s |  |
| 71 | `avm1/loadvariables/loadvariables` | 7 | 2.2s |  |
| 72 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 73 | `avm1/lookup` | 3 | 0.8s |  |
| 74 | `avm1/mouse-transparency` | 1 | 2.3s |  |
| 75 | `avm1/moviecliploader` | 7 | 21.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 76 | `avm1/nativeinheritance` | 6 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 77 | `avm1/nested-button` | 1 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 78 | `avm1/operations` | 13 | 2.2s |  |
| 79 | `avm1/property-paths/property-paths-6` | 6 | 2.1s |  |
| 80 | `avm1/property-paths/property-paths-7` | 7 | 1.8s |  |
| 81 | `avm1/propertycase/propertycase` | 7 | 2.1s |  |
| 82 | `avm1/propertycase/propertycase-preserving-6` | 2 | 2.1s |  |
| 83 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.9s |  |
| 84 | `avm1/rollover` | 4 | 2.2s |  |
| 85 | `avm1/scope` | 14 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 86 | `avm1/setinterval` | 20 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 87 | `avm1/settimeout` | 17 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 88 | `avm1/super` | 11 | 2.1s |  |
| 89 | `avm1/target` | 18 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 90 | `avm1/text-bind` | 0 | 22.5s |  |
| 91 | `avm1/textfield/textfield-html` | 4 | 2.3s |  |
| 92 | `avm1/textfield/textfield-text-setters` | 8 | 2.3s |  |
| 93 | `avm1/undefined/undefined-swf6` | 39 | 2.1s |  |
| 94 | `avm1/undefined/undefined-swf7` | 39 | 1.8s |  |
| 95 | `avm1/watch` | 2 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 96 | `avm1/xml/xmlbuild` | 1 | 1.8s |  |
| 97 | `avm1/xml/xmlload` | 4 | 2.3s |  |
| 98 | `avm1/xml/xmlstring` | 9 | 2.0s |  |
| 99 | `avm1timeline1` | 3 | 2.2s |  |
| 100 | `avm1timeline2` | 6 | 2.2s |  |
| 101 | `avm2/event-dispatching` | 5 | 7.9s |  |
| 102 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 9.8s |  |
| 103 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 28.0s |  |
| 104 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 7.8s |  |
| 105 | `bitmapbuttons` | 0 | 30.0s |  |
| 106 | `bitmapdata/draw-and-read` | 1 | 7.7s |  |
| 107 | `blendmode/blendmode_1` | 2 | 26.5s |  |
| 108 | `blendmode/blendmode_2` | 4 | 7.8s |  |
| 109 | `blendmode/blendmode_3` | 2 | 7.7s |  |
| 110 | `button1` | 1 | 8.7s |  |
| 111 | `button2` | 1 | 8.7s |  |
| 112 | `button3` | 1 | 3.4s |  |
| 113 | `captions` | 8 | 8.5s |  |
| 114 | `clipping` | 0 | 2.5s |  |
| 115 | `doubleAndRegister` | 2 | 2.7s |  |
| 116 | `encoding1` | 31 | 8.0s |  |
| 117 | `flash_events_Event` | 3 | 27.3s |  |
| 118 | `flash_geom_ColorTransform` | 0 | 7.9s |  |
| 119 | `flash_net_URLLoader` | 7 | 7.6s |  |
| 120 | `flash_net_URLRequest` | 6 | 7.5s |  |
| 121 | `flash_net_classes` | 22 | 7.7s |  |
| 122 | `flash_utils_Timer` | 2 | 7.5s |  |
| 123 | `fscommand1` | 1 | 1.9s |  |
| 124 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 21.4s |  |
| 125 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 48 | 18.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 126 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 16.4s |  |
| 127 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.8s |  |
| 128 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 16.6s |  |
| 129 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 70 | 17.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 130 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 57 | 17.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 131 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 71 | 17.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 132 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 16 | 17.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 133 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 22.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 134 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 23 | 21.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 135 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 50 | 22.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 136 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 67 | 22.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 137 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.9s |  |
| 138 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 26 | 21.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 139 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 21.1s |  |
| 140 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 31 | 23.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 141 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 22.1s |  |
| 142 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 21.6s |  |
| 143 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 25 | 22.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 144 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 21.7s |  |
| 145 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 29 | 22.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 146 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 22.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 147 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 35 | 23.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 148 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 22.9s |  |
| 149 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 37 | 24.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 150 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 22 | 3.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 151 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 19 | 22.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 152 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 24 | 22.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 153 | `gradient` | 0 | 2.6s |  |
| 154 | `gradientTransform` | 0 | 21.2s |  |
| 155 | `hardwrap` | 1 | 8.3s |  |
| 156 | `hitTestStyleChange` | 1 | 26.4s |  |
| 157 | `hittesting/hittesting` | 18 | 7.8s |  |
| 158 | `hittesting/mask-hit-test` | 1 | 3.4s |  |
| 159 | `image-loading` | 4 | 7.9s |  |
| 160 | `invalidClipDepth` | 0 | 21.7s |  |
| 161 | `local2global` | 1 | 7.7s |  |
| 162 | `localconnection` | 12 | 8.3s |  |
| 163 | `lzma` | 5 | 7.7s |  |
| 164 | `lzma_bytes` | 2 | 27.5s |  |
| 165 | `mouse/mouse_coords` | 2 | 7.9s |  |
| 166 | `mouse/start_drag` | 3 | 24.8s |  |
| 167 | `mouse/start_drag_lock` | 3 | 7.1s |  |
| 168 | `movieclip` | 9 | 6.6s |  |
| 169 | `movieinfo1` | 3 | 1.9s |  |
| 170 | `slider_component` | 4 | 11.5s |  |
| 171 | `stream1` | 9 | 6.6s |  |
| 172 | `stroke1` | 1 | 6.6s |  |
| 173 | `stylesheet` | 3 | 5.9s |  |
| 174 | `targetPath1` | 8 | 1.5s |  |
| 175 | `timeline/Timeline3` | 5 | 20.8s |  |
| 176 | `timeline/Timeline4` | 5 | 20.9s |  |
| 177 | `timeline/Timeline8` | 5 | 6.1s |  |
| 178 | `timeline/Timeline9` | 11 | 6.0s |  |
| 179 | `timeline/events/timeline_events_fp10` | 67 | 6.3s |  |
| 180 | `timeline/events/timeline_events_fp9` | 48 | 22.1s |  |
| 181 | `timeline/nav/blendMode` | 8 | 21.6s |  |
| 182 | `timeline/nav/cacheAsBitmap` | 8 | 5.8s |  |
| 183 | `timeline/nav/colorTransform` | 8 | 5.8s |  |
| 184 | `timeline/nav/filters` | 8 | 5.8s |  |
| 185 | `timeline/nav/matrix` | 8 | 5.9s |  |
| 186 | `timeline/nav/morphShape` | 4 | 25.9s |  |
| 187 | `timeline/nav/name` | 8 | 25.9s |  |
| 188 | `timeline/nav/ratio` | 4 | 7.3s |  |
| 189 | `timeline/nav/ratio2` | 4 | 7.1s |  |
| 190 | `timeline/nav/ratio3` | 4 | 1.2s |  |
| 191 | `timeline/nav/shape` | 4 | 7.2s |  |
| 192 | `timeline/scene/EncodedU32` | 1 | 25.9s |  |
| 193 | `timeline/scene/Scene_1_MainTimeline` | 70 | 26.9s |  |
| 194 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 7.8s |  |
| 195 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 7.8s |  |
| 196 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 7.7s |  |
| 197 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 7.4s |  |
| 198 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 7.7s |  |
| 199 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 26.6s |  |
| 200 | `timeline/timeline_as2_1` | 3 | 20.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 201 | `timeline/timeline_as2_2` | 3 | 2.0s |  |
| 202 | `timeline/timeline_as2_3` | 3 | 20.5s |  |
| 203 | `timeline/timeline_as2_4` | 2 | 20.5s |  |
| 204 | `timeline/timeline_as2_5` | 4 | 4.2s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 205 | `timeline/timeline_loop` | 7 | 28.7s |  |
| 206 | `timeline/timeline_name_0` | 13 | 26.4s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `MaskTest-3` | 1 | 1 | 27.2s |  |
| 2 | `acid/acid-text-x` | 1 | 1 | 8.2s |  |
| 3 | `acid/acid-textfield` | 6 | 7 | 8.6s |  |
| 4 | `as3-loader/LoaderTest` | 2 | 2 | 27.3s |  |
| 5 | `avm1/hitarea` | 2 | 2 | 21.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 6 | `avm1movie` | 7 | 12 | 27.9s |  |
| 7 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 7.7s |  |
| 8 | `flash_net_SharedObject` | 1 | 1 | 7.9s |  |
| 9 | `flash_text_TextField` | 5 | 8 | 27.5s |  |
| 10 | `flash_text_TextField2` | 9 | 9 | 8.1s |  |
| 11 | `getobjectsunderpoint` | 9 | 15 | 8.1s |  |
| 12 | `timeline/nav/clipDepth` | 4 | 4 | 5.9s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**5 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `as3-loader/LoaderTest2` | 85.7% | 6 | 7 | 1 |  |
| 2 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36 | 48 | 12 |  |
| 3 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 72.1% | 31 | 43 | 12 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `acid/acid-morph` | 66.7% | 4 | 6 | 2 |  |
| 5 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**11 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `as3-loader/LoaderTest2` | 85.7% | 6/7 | 7 | 7 |  |
| 2 | `as3-loader/loaderinfo/loaded-content-properties` | 75.0% | 36/48 | 48 | 48 |  |
| 3 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 72.1% | 31/43 | 42 | 43 | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 4 | `acid/acid-morph` | 66.7% | 4/6 | 6 | 6 |  |
| 5 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1/2 | 2 | 2 |  |
| 6 | `avm2/flash/geom/matrix3d/TransformBasics` | 38.5% | 5/13 | 11 | 13 |  |
| 7 | `acid/acid-shapes-testing` | 30.0% | 36/120 | 120 | 120 |  |
| 8 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 9 | `as3-loader/events/loader-events` | 13.5% | 5/37 | 37 | 36 |  |
| 10 | `acid/acid-shapes` | 0.0% | 0/120 | 7 | 120 |  |
| 11 | `esc` | 0.0% | 0/13 | 13 | 2 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 10 | 1 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 19 | 1 |
| | *(tests not in any document)* | 195 | 174 | 21 |
