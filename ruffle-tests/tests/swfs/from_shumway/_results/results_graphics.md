# Ruffle Test Results (Unfiltered)

**Date**: 2026-09-22 21:18 UTC

**Git SHA**: `19ba533729`

**Run Duration**: 49m 54s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 229 |
| Passing | **213** (93.0%) |
| Ruffle-matched | 12 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **225** (98.3%) |
| Failing | 4 |
| Total expected lines | 2484 |
| Matching lines | 2393 (96.3%) |
| Mismatched lines | 91 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 4 | 100.0% |

## Passing Tests

**213 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 30.2s |  |
| 2 | `MaskTest` | 0 | 9.0s |  |
| 3 | `MaskTest-2` | 0 | 9.4s |  |
| 4 | `ZeroClipboardTest` | 3 | 29.7s |  |
| 5 | `acid/acid` | 1 | 39.8s |  |
| 6 | `acid/acid-big` | 0 | 50.5s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 30.6s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 30.1s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 24.1s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 4.0s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 9.2s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 9.2s |  |
| 13 | `acid/acid-bitmaps` | 0 | 29.9s |  |
| 14 | `acid/acid-blend` | 0 | 42.8s |  |
| 15 | `acid/acid-blend-2` | 0 | 25.3s |  |
| 16 | `acid/acid-chars` | 0 | 1.8s |  |
| 17 | `acid/acid-child` | 0 | 19.8s |  |
| 18 | `acid/acid-clip` | 0 | 1.9s |  |
| 19 | `acid/acid-clip-2` | 0 | 1.9s |  |
| 20 | `acid/acid-clip-3` | 0 | 7.8s |  |
| 21 | `acid/acid-color` | 0 | 32.2s |  |
| 22 | `acid/acid-color-0` | 0 | 22.0s |  |
| 23 | `acid/acid-color-2` | 0 | 2.1s |  |
| 24 | `acid/acid-filter` | 2 | 10.2s |  |
| 25 | `acid/acid-filter-2` | 0 | 2.5s |  |
| 26 | `acid/acid-gc` | 0 | 2.4s |  |
| 27 | `acid/acid-gradient` | 0 | 2.3s |  |
| 28 | `acid/acid-gradient-0` | 0 | 24.0s |  |
| 29 | `acid/acid-gradient-1` | 0 | 2.2s |  |
| 30 | `acid/acid-gradient-2` | 0 | 2.2s |  |
| 31 | `acid/acid-image` | 0 | 33.9s |  |
| 32 | `acid/acid-large` | 0 | 79.6s |  |
| 33 | `acid/acid-mask` | 0 | 10.6s |  |
| 34 | `acid/acid-morph` | 6 | 29.6s |  |
| 35 | `acid/acid-scale` | 0 | 2.5s |  |
| 36 | `acid/acid-shapes` | 120 | 31.3s |  |
| 37 | `acid/acid-small` | 0 | 3.1s |  |
| 38 | `acid/acid-stroke-0` | 0 | 30.2s |  |
| 39 | `acid/acid-text` | 0 | 2.1s |  |
| 40 | `acid/acid-text-2` | 1 | 3.3s |  |
| 41 | `acid/acid-text-3` | 0 | 2.0s |  |
| 42 | `acid/acid-text-4` | 0 | 8.6s |  |
| 43 | `acid/acid-text-5` | 0 | 29.7s |  |
| 44 | `acid/acid-text-6` | 0 | 23.4s |  |
| 45 | `acid/acid-text-escape` | 0 | 2.0s |  |
| 46 | `acid/acid-textfield-scroll` | 5 | 9.5s |  |
| 47 | `acid/acid-video` | 0 | 27.9s |  |
| 48 | `add` | 11 | 2.2s |  |
| 49 | `as3-interfaces` | 6 | 30.1s |  |
| 50 | `as3-loader/LoaderLoadBytesTest2` | 3 | 9.1s |  |
| 51 | `as3-loader/LoaderTest2` | 7 | 28.5s |  |
| 52 | `as3-loader/bug1093712/loader` | 1 | 8.9s |  |
| 53 | `as3-loader/bug1157243/empty` | 1 | 8.6s |  |
| 54 | `as3-loader/bug1157243/invalid` | 1 | 8.5s |  |
| 55 | `as3-loader/loaderinfo/Preloader` | 1 | 8.8s |  |
| 56 | `as3-loader/loaderinfo/loaded-content-properties` | 48 | 8.9s |  |
| 57 | `avm1/array` | 7 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 58 | `avm1/bitmapdata/getPixel` | 2 | 2.1s |  |
| 59 | `avm1/bitmapdata/loadBitmap` | 3 | 2.1s |  |
| 60 | `avm1/callee` | 2 | 2.0s |  |
| 61 | `avm1/depth` | 6 | 2.2s |  |
| 62 | `avm1/doactionorder/doactionorder` | 7 | 2.4s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 63 | `avm1/doactionorder/symbolclass` | 4 | 2.3s |  |
| 64 | `avm1/duplicateMovieClip/dontremove` | 6 | 2.2s |  |
| 65 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.2s |  |
| 66 | `avm1/duplicateMovieClip/name-coercion` | 3 | 2.1s |  |
| 67 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.3s |  |
| 68 | `avm1/externalinterface` | 4 | 2.1s |  |
| 69 | `avm1/filters` | 149 | 2.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 70 | `avm1/haxe/flocons1` | 2 | 2.2s |  |
| 71 | `avm1/haxe/flocons2` | 3 | 2.0s |  |
| 72 | `avm1/hitarea` | 4 | 22.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 73 | `avm1/label` | 4 | 2.4s |  |
| 74 | `avm1/levels` | 9 | 2.0s |  |
| 75 | `avm1/loadevent` | 9 | 2.1s |  |
| 76 | `avm1/loadvariables/loadvariables` | 7 | 1.9s |  |
| 77 | `avm1/loadvariables/loadvars` | 2 | 0.8s |  |
| 78 | `avm1/lookup` | 3 | 0.8s |  |
| 79 | `avm1/mouse-transparency` | 1 | 2.1s |  |
| 80 | `avm1/moviecliploader` | 7 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 81 | `avm1/nativeinheritance` | 6 | 2.0s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 82 | `avm1/nested-button` | 1 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/operations` | 13 | 2.2s |  |
| 84 | `avm1/property-paths/property-paths-6` | 6 | 2.2s |  |
| 85 | `avm1/property-paths/property-paths-7` | 7 | 1.9s |  |
| 86 | `avm1/propertycase/propertycase` | 7 | 2.1s |  |
| 87 | `avm1/propertycase/propertycase-preserving-6` | 2 | 2.2s |  |
| 88 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.9s |  |
| 89 | `avm1/rollover` | 4 | 2.4s |  |
| 90 | `avm1/scope` | 14 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 91 | `avm1/setinterval` | 20 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 92 | `avm1/settimeout` | 17 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 93 | `avm1/super` | 11 | 2.1s |  |
| 94 | `avm1/target` | 18 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 95 | `avm1/text-bind` | 0 | 2.7s |  |
| 96 | `avm1/textfield/textfield-html` | 4 | 2.3s |  |
| 97 | `avm1/textfield/textfield-text-setters` | 8 | 2.2s |  |
| 98 | `avm1/undefined/undefined-swf6` | 39 | 2.1s |  |
| 99 | `avm1/undefined/undefined-swf7` | 39 | 1.8s |  |
| 100 | `avm1/watch` | 2 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 101 | `avm1/xml/xmlbuild` | 1 | 1.8s |  |
| 102 | `avm1/xml/xmlload` | 4 | 2.3s |  |
| 103 | `avm1/xml/xmlstring` | 9 | 2.0s |  |
| 104 | `avm1timeline1` | 3 | 2.1s |  |
| 105 | `avm1timeline2` | 6 | 1.7s |  |
| 106 | `avm2/event-dispatching` | 5 | 7.0s |  |
| 107 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 7.8s |  |
| 108 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 24.4s |  |
| 109 | `avm2/flash/geom/matrix3d/TransformBasics` | 13 | 7.2s |  |
| 110 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 7.0s |  |
| 111 | `bitmapbuttons` | 0 | 26.1s |  |
| 112 | `bitmapdata/draw-and-read` | 1 | 10.5s |  |
| 113 | `blendmode/blendmode_1` | 2 | 28.0s |  |
| 114 | `blendmode/blendmode_2` | 4 | 8.7s |  |
| 115 | `blendmode/blendmode_3` | 2 | 8.7s |  |
| 116 | `button1` | 1 | 9.5s |  |
| 117 | `button2` | 1 | 9.5s |  |
| 118 | `button3` | 1 | 3.3s |  |
| 119 | `captions` | 8 | 7.8s |  |
| 120 | `clipping` | 0 | 2.0s |  |
| 121 | `doubleAndRegister` | 2 | 2.1s |  |
| 122 | `encoding1` | 31 | 7.1s |  |
| 123 | `flash_events_Event` | 3 | 23.1s |  |
| 124 | `flash_geom_ColorTransform` | 0 | 7.8s |  |
| 125 | `flash_net_URLLoader` | 7 | 29.1s |  |
| 126 | `flash_net_URLRequest` | 6 | 8.8s |  |
| 127 | `flash_net_classes` | 22 | 8.9s |  |
| 128 | `flash_utils_Timer` | 2 | 8.8s |  |
| 129 | `fscommand1` | 1 | 2.1s |  |
| 130 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 23.8s |  |
| 131 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 48 | 27.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 132 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 20.2s |  |
| 133 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 2.6s |  |
| 134 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 31.6s |  |
| 135 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 70 | 30.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 136 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 57 | 31.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 137 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 71 | 33.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 138 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 16 | 22.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 139 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 23.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 140 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 23 | 22.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 141 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 50 | 24.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 142 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 67 | 22.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 143 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 21.8s |  |
| 144 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 26 | 22.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 145 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 22.0s |  |
| 146 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 31 | 19.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 147 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 17.8s |  |
| 148 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 17.8s |  |
| 149 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 25 | 18.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 150 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 18.2s |  |
| 151 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 29 | 19.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 152 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 18.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 153 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 35 | 18.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 154 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 17.8s |  |
| 155 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 37 | 18.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 156 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 43 | 17.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 157 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 22 | 2.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 158 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 19 | 18.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 159 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 24 | 18.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 160 | `gradient` | 0 | 2.6s |  |
| 161 | `gradientTransform` | 0 | 22.4s |  |
| 162 | `hardwrap` | 1 | 9.4s |  |
| 163 | `hitTestStyleChange` | 1 | 29.6s |  |
| 164 | `hittesting/hittesting` | 18 | 8.9s |  |
| 165 | `hittesting/mask-hit-test` | 1 | 3.5s |  |
| 166 | `image-loading` | 4 | 9.3s |  |
| 167 | `invalidClipDepth` | 0 | 23.9s |  |
| 168 | `local2global` | 1 | 9.2s |  |
| 169 | `localconnection` | 12 | 9.6s |  |
| 170 | `lzma` | 5 | 9.1s |  |
| 171 | `lzma_bytes` | 2 | 30.0s |  |
| 172 | `mouse/mouse_coords` | 2 | 9.4s |  |
| 173 | `mouse/start_drag` | 3 | 29.9s |  |
| 174 | `mouse/start_drag_lock` | 3 | 9.0s |  |
| 175 | `movieclip` | 9 | 8.8s |  |
| 176 | `movieinfo1` | 3 | 2.1s |  |
| 177 | `slider_component` | 4 | 16.5s |  |
| 178 | `stream1` | 9 | 8.8s |  |
| 179 | `stroke1` | 1 | 8.8s |  |
| 180 | `stylesheet` | 3 | 9.5s |  |
| 181 | `targetPath1` | 8 | 2.1s |  |
| 182 | `timeline/Timeline3` | 5 | 32.1s |  |
| 183 | `timeline/Timeline4` | 5 | 29.6s |  |
| 184 | `timeline/Timeline8` | 5 | 9.3s |  |
| 185 | `timeline/Timeline9` | 11 | 9.2s |  |
| 186 | `timeline/events/timeline_events_fp10` | 67 | 9.4s |  |
| 187 | `timeline/events/timeline_events_fp9` | 48 | 19.1s |  |
| 188 | `timeline/nav/blendMode` | 8 | 2.6s |  |
| 189 | `timeline/nav/cacheAsBitmap` | 8 | 2.5s |  |
| 190 | `timeline/nav/colorTransform` | 8 | 2.5s |  |
| 191 | `timeline/nav/filters` | 8 | 2.7s |  |
| 192 | `timeline/nav/matrix` | 8 | 2.6s |  |
| 193 | `timeline/nav/morphShape` | 4 | 23.3s |  |
| 194 | `timeline/nav/name` | 8 | 23.3s |  |
| 195 | `timeline/nav/ratio` | 4 | 6.8s |  |
| 196 | `timeline/nav/ratio2` | 4 | 6.8s |  |
| 197 | `timeline/nav/ratio3` | 4 | 0.8s |  |
| 198 | `timeline/nav/shape` | 4 | 6.8s |  |
| 199 | `timeline/scene/EncodedU32` | 1 | 23.2s |  |
| 200 | `timeline/scene/Scene_1_MainTimeline` | 70 | 23.7s |  |
| 201 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 7.2s |  |
| 202 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 7.5s |  |
| 203 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 7.1s |  |
| 204 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 6.8s |  |
| 205 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 6.9s |  |
| 206 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 23.2s |  |
| 207 | `timeline/timeline_as2_1` | 3 | 21.9s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 208 | `timeline/timeline_as2_2` | 3 | 2.2s |  |
| 209 | `timeline/timeline_as2_3` | 3 | 21.3s |  |
| 210 | `timeline/timeline_as2_4` | 2 | 21.3s |  |
| 211 | `timeline/timeline_as2_5` | 4 | 6.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 212 | `timeline/timeline_loop` | 7 | 30.8s |  |
| 213 | `timeline/timeline_name_0` | 13 | 28.3s |  |

## Ruffle-Matched Tests

**12 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `MaskTest-3` | 1 | 1 | 29.4s |  |
| 2 | `acid/acid-shapes-testing` | 12 | 12 | 31.0s |  |
| 3 | `acid/acid-text-x` | 1 | 1 | 8.4s |  |
| 4 | `acid/acid-textfield` | 6 | 7 | 9.9s |  |
| 5 | `as3-loader/LoaderTest` | 2 | 2 | 29.3s |  |
| 6 | `avm1movie` | 12 | 12 | 28.6s |  |
| 7 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 6.9s |  |
| 8 | `flash_net_SharedObject` | 1 | 1 | 7.3s |  |
| 9 | `flash_text_TextField` | 5 | 8 | 32.8s |  |
| 10 | `flash_text_TextField2` | 9 | 9 | 11.4s |  |
| 11 | `getobjectsunderpoint` | 9 | 15 | 9.5s |  |
| 12 | `timeline/nav/clipDepth` | 4 | 4 | 2.6s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**1 tests** within reach

| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |
|---|------|------------|----------|-------|------------|-------|
| 1 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1 | 2 | 1 |  |

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**4 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1/2 | 2 | 2 |  |
| 2 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 3 | `as3-loader/events/loader-events` | 13.9% | 5/36 | 35 | 36 |  |
| 4 | `esc` | 0.0% | 0/13 | 13 | 2 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 11 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 20 | 0 |
| | *(tests not in any document)* | 195 | 179 | 16 |
