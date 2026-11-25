# Ruffle Test Results (Filtered)

**Date**: 2026-11-25 05:10 UTC

**Git SHA**: `7c3cfdcb7b`

**Run Duration**: 42m 13s

**Filtered**: 6 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 223 |
| Passing | **215** (96.4%) |
| Ruffle-matched | 8 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **223** (100.0%) |
| Failing | 0 |
| Total expected lines | 2409 |
| Matching lines | 2363 (98.1%) |
| Mismatched lines | 46 |

## Passing Tests

**215 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 26.6s |  |
| 2 | `MaskTest` | 0 | 7.3s |  |
| 3 | `MaskTest-2` | 0 | 7.6s |  |
| 4 | `ZeroClipboardTest` | 3 | 25.0s |  |
| 5 | `acid/acid` | 1 | 30.7s |  |
| 6 | `acid/acid-big` | 0 | 41.0s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 25.8s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 25.7s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 20.4s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 2.5s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 6.4s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 6.7s |  |
| 13 | `acid/acid-bitmaps` | 0 | 24.1s |  |
| 14 | `acid/acid-blend` | 0 | 34.9s |  |
| 15 | `acid/acid-blend-2` | 0 | 19.4s |  |
| 16 | `acid/acid-chars` | 0 | 1.8s |  |
| 17 | `acid/acid-child` | 0 | 16.9s |  |
| 18 | `acid/acid-clip` | 0 | 2.0s |  |
| 19 | `acid/acid-clip-2` | 0 | 1.9s |  |
| 20 | `acid/acid-clip-3` | 0 | 7.1s |  |
| 21 | `acid/acid-color` | 0 | 27.3s |  |
| 22 | `acid/acid-color-0` | 0 | 17.9s |  |
| 23 | `acid/acid-color-2` | 0 | 1.8s |  |
| 24 | `acid/acid-filter` | 2 | 9.7s |  |
| 25 | `acid/acid-filter-2` | 0 | 2.1s |  |
| 26 | `acid/acid-gc` | 0 | 1.9s |  |
| 27 | `acid/acid-gradient` | 0 | 1.8s |  |
| 28 | `acid/acid-gradient-0` | 0 | 19.6s |  |
| 29 | `acid/acid-gradient-1` | 0 | 1.8s |  |
| 30 | `acid/acid-gradient-2` | 0 | 1.7s |  |
| 31 | `acid/acid-image` | 0 | 27.8s |  |
| 32 | `acid/acid-large` | 0 | 67.5s |  |
| 33 | `acid/acid-mask` | 0 | 8.3s |  |
| 34 | `acid/acid-morph` | 6 | 25.4s |  |
| 35 | `acid/acid-scale` | 0 | 1.7s |  |
| 36 | `acid/acid-shapes` | 120 | 26.1s |  |
| 37 | `acid/acid-small` | 0 | 2.1s |  |
| 38 | `acid/acid-stroke-0` | 0 | 25.1s |  |
| 39 | `acid/acid-text` | 0 | 1.8s |  |
| 40 | `acid/acid-text-2` | 1 | 2.7s |  |
| 41 | `acid/acid-text-3` | 0 | 1.7s |  |
| 42 | `acid/acid-text-4` | 0 | 7.6s |  |
| 43 | `acid/acid-text-5` | 0 | 27.2s |  |
| 44 | `acid/acid-text-6` | 0 | 20.8s |  |
| 45 | `acid/acid-text-escape` | 0 | 1.8s |  |
| 46 | `acid/acid-textfield-scroll` | 5 | 10.4s |  |
| 47 | `acid/acid-video` | 0 | 29.5s |  |
| 48 | `add` | 11 | 2.5s |  |
| 49 | `as3-interfaces` | 6 | 32.7s |  |
| 50 | `as3-loader/LoaderLoadBytesTest` | 4 | 10.7s |  |
| 51 | `as3-loader/LoaderLoadBytesTest2` | 3 | 10.0s |  |
| 52 | `as3-loader/LoaderTest2` | 7 | 24.3s |  |
| 53 | `as3-loader/bug1093712/loader` | 1 | 7.1s |  |
| 54 | `as3-loader/bug1157243/empty` | 1 | 7.0s |  |
| 55 | `as3-loader/bug1157243/invalid` | 1 | 6.9s |  |
| 56 | `as3-loader/loaderinfo/Preloader` | 1 | 6.9s |  |
| 57 | `as3-loader/loaderinfo/loaded-content-properties` | 48 | 7.0s |  |
| 58 | `avm1/array` | 7 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 59 | `avm1/bitmapdata/getPixel` | 2 | 2.4s |  |
| 60 | `avm1/bitmapdata/loadBitmap` | 3 | 2.1s |  |
| 61 | `avm1/callee` | 2 | 2.1s |  |
| 62 | `avm1/depth` | 6 | 2.6s |  |
| 63 | `avm1/doactionorder/doactionorder` | 7 | 2.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 64 | `avm1/doactionorder/symbolclass` | 4 | 2.7s |  |
| 65 | `avm1/duplicateMovieClip/dontremove` | 6 | 24.9s |  |
| 66 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 2.6s |  |
| 67 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.6s |  |
| 68 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.7s |  |
| 69 | `avm1/externalinterface` | 4 | 1.6s |  |
| 70 | `avm1/filters` | 149 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 71 | `avm1/haxe/flocons1` | 2 | 1.6s |  |
| 72 | `avm1/haxe/flocons2` | 3 | 1.5s |  |
| 73 | `avm1/hitarea` | 4 | 19.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 74 | `avm1/label` | 4 | 1.8s |  |
| 75 | `avm1/levels` | 9 | 2.2s |  |
| 76 | `avm1/loadevent` | 9 | 2.4s |  |
| 77 | `avm1/loadvariables/loadvariables` | 7 | 2.1s |  |
| 78 | `avm1/loadvariables/loadvars` | 2 | 0.9s |  |
| 79 | `avm1/lookup` | 3 | 0.9s |  |
| 80 | `avm1/mouse-transparency` | 1 | 2.2s |  |
| 81 | `avm1/moviecliploader` | 7 | 2.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 82 | `avm1/nativeinheritance` | 6 | 2.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/nested-button` | 1 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 84 | `avm1/operations` | 13 | 1.6s |  |
| 85 | `avm1/property-paths/property-paths-6` | 6 | 1.6s |  |
| 86 | `avm1/property-paths/property-paths-7` | 7 | 1.4s |  |
| 87 | `avm1/propertycase/propertycase` | 7 | 1.6s |  |
| 88 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.6s |  |
| 89 | `avm1/propertycase/propertycase-preserving-7` | 5 | 1.4s |  |
| 90 | `avm1/rollover` | 4 | 1.7s |  |
| 91 | `avm1/scope` | 14 | 2.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 92 | `avm1/setinterval` | 20 | 2.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 93 | `avm1/settimeout` | 17 | 2.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 94 | `avm1/super` | 11 | 2.7s |  |
| 95 | `avm1/target` | 18 | 2.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 96 | `avm1/text-bind` | 0 | 3.2s |  |
| 97 | `avm1/textfield/textfield-html` | 4 | 2.8s |  |
| 98 | `avm1/textfield/textfield-text-setters` | 8 | 2.9s |  |
| 99 | `avm1/undefined/undefined-swf6` | 39 | 1.4s |  |
| 100 | `avm1/undefined/undefined-swf7` | 39 | 0.8s |  |
| 101 | `avm1/watch` | 2 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 102 | `avm1/xml/xmlbuild` | 1 | 1.6s |  |
| 103 | `avm1/xml/xmlload` | 4 | 1.8s |  |
| 104 | `avm1/xml/xmlstring` | 9 | 1.6s |  |
| 105 | `avm1timeline1` | 3 | 1.7s |  |
| 106 | `avm1timeline2` | 6 | 1.6s |  |
| 107 | `avm2/event-dispatching` | 5 | 7.0s |  |
| 108 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 7.6s |  |
| 109 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 25.0s |  |
| 110 | `avm2/flash/geom/matrix3d/TransformBasics` | 13 | 7.1s |  |
| 111 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 7.0s |  |
| 112 | `bitmapbuttons` | 0 | 26.4s |  |
| 113 | `bitmapdata/draw-and-read` | 1 | 9.4s |  |
| 114 | `bitmapdata/getpixel-from-embedded` | 2 | 7.2s |  |
| 115 | `blendmode/blendmode_1` | 2 | 24.8s |  |
| 116 | `blendmode/blendmode_2` | 4 | 7.2s |  |
| 117 | `blendmode/blendmode_3` | 2 | 7.1s |  |
| 118 | `button1` | 1 | 7.6s |  |
| 119 | `button2` | 1 | 7.6s |  |
| 120 | `button3` | 1 | 2.3s |  |
| 121 | `captions` | 8 | 7.5s |  |
| 122 | `clipping` | 0 | 1.8s |  |
| 123 | `doubleAndRegister` | 2 | 1.9s |  |
| 124 | `encoding1` | 31 | 7.1s |  |
| 125 | `flash_events_Event` | 3 | 24.7s |  |
| 126 | `flash_geom_ColorTransform` | 0 | 7.2s |  |
| 127 | `flash_net_URLLoader` | 7 | 24.7s |  |
| 128 | `flash_net_URLRequest` | 6 | 7.1s |  |
| 129 | `flash_net_classes` | 22 | 7.3s |  |
| 130 | `flash_utils_Timer` | 2 | 7.0s |  |
| 131 | `fscommand1` | 1 | 1.6s |  |
| 132 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 19.3s |  |
| 133 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 48 | 27.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 134 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 24.8s |  |
| 135 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 2.8s |  |
| 136 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 24.9s |  |
| 137 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 70 | 25.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 138 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 57 | 25.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 139 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 71 | 27.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 140 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 16 | 25.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 141 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 19.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 142 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 23 | 19.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 143 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 50 | 20.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 144 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 67 | 19.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 145 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 18.5s |  |
| 146 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 26 | 19.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 147 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 18.6s |  |
| 148 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 31 | 17.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 149 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 16.2s |  |
| 150 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 16.4s |  |
| 151 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 25 | 16.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 152 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 16.7s |  |
| 153 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 29 | 17.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 154 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 16.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 155 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 35 | 19.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 156 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 19.1s |  |
| 157 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 37 | 20.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 158 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 43 | 19.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 159 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 22 | 2.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 160 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 19 | 19.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 161 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 24 | 19.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 162 | `gradient` | 0 | 2.2s |  |
| 163 | `gradientTransform` | 0 | 19.8s |  |
| 164 | `hardwrap` | 1 | 7.6s |  |
| 165 | `hitTestStyleChange` | 1 | 25.3s |  |
| 166 | `hittesting/hittesting` | 18 | 7.2s |  |
| 167 | `hittesting/mask-hit-test` | 1 | 2.5s |  |
| 168 | `image-loading` | 4 | 10.2s |  |
| 169 | `invalidClipDepth` | 0 | 25.6s |  |
| 170 | `local2global` | 1 | 10.1s |  |
| 171 | `localconnection` | 12 | 10.4s |  |
| 172 | `lzma` | 5 | 10.0s |  |
| 173 | `lzma_bytes` | 2 | 33.4s |  |
| 174 | `mouse/mouse_coords` | 2 | 10.2s |  |
| 175 | `mouse/start_drag` | 3 | 25.7s |  |
| 176 | `mouse/start_drag_lock` | 3 | 7.3s |  |
| 177 | `movieclip` | 9 | 7.4s |  |
| 178 | `movieinfo1` | 3 | 1.8s |  |
| 179 | `slider_component` | 4 | 13.0s |  |
| 180 | `stream1` | 9 | 7.6s |  |
| 181 | `stroke1` | 1 | 7.6s |  |
| 182 | `stylesheet` | 3 | 1.4s |  |
| 183 | `targetPath1` | 8 | 0.8s |  |
| 184 | `timeline/Timeline3` | 5 | 1.0s |  |
| 185 | `timeline/Timeline4` | 5 | 1.0s |  |
| 186 | `timeline/Timeline8` | 5 | 0.9s |  |
| 187 | `timeline/Timeline9` | 11 | 0.9s |  |
| 188 | `timeline/events/timeline_events_fp10` | 67 | 0.9s |  |
| 189 | `timeline/events/timeline_events_fp9` | 48 | 10.1s |  |
| 190 | `timeline/nav/blendMode` | 8 | 10.0s |  |
| 191 | `timeline/nav/cacheAsBitmap` | 8 | 9.7s |  |
| 192 | `timeline/nav/colorTransform` | 8 | 9.8s |  |
| 193 | `timeline/nav/filters` | 8 | 9.9s |  |
| 194 | `timeline/nav/matrix` | 8 | 9.9s |  |
| 195 | `timeline/nav/morphShape` | 4 | 7.1s |  |
| 196 | `timeline/nav/name` | 8 | 7.2s |  |
| 197 | `timeline/nav/ratio` | 4 | 7.2s |  |
| 198 | `timeline/nav/ratio2` | 4 | 6.9s |  |
| 199 | `timeline/nav/ratio3` | 4 | 1.0s |  |
| 200 | `timeline/nav/shape` | 4 | 7.0s |  |
| 201 | `timeline/scene/EncodedU32` | 1 | 24.9s |  |
| 202 | `timeline/scene/Scene_1_MainTimeline` | 70 | 25.0s |  |
| 203 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 7.2s |  |
| 204 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 7.2s |  |
| 205 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 7.2s |  |
| 206 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 6.9s |  |
| 207 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 7.0s |  |
| 208 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 24.7s |  |
| 209 | `timeline/timeline_as2_1` | 3 | 1.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 210 | `timeline/timeline_as2_2` | 3 | 1.6s |  |
| 211 | `timeline/timeline_as2_3` | 3 | 18.8s |  |
| 212 | `timeline/timeline_as2_4` | 2 | 1.6s |  |
| 213 | `timeline/timeline_as2_5` | 4 | 2.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 214 | `timeline/timeline_loop` | 7 | 8.2s |  |
| 215 | `timeline/timeline_name_0` | 13 | 7.0s |  |

## Ruffle-Matched Tests

**8 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-shapes-testing` | 12 | 12 | 25.7s |  |
| 2 | `acid/acid-text-x` | 1 | 1 | 7.4s |  |
| 3 | `acid/acid-textfield` | 6 | 7 | 10.9s |  |
| 4 | `as3-loader/LoaderTest` | 2 | 2 | 33.0s |  |
| 5 | `as3-loader/events/loader-events` | 20 | 28 | 7.4s |  |
| 6 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 6.9s |  |
| 7 | `flash_text_TextField` | 5 | 8 | 25.4s |  |
| 8 | `timeline/nav/clipDepth` | 4 | 4 | 10.0s |  |

## Near-Passing Tests

Tests with output mismatch but >= 50% line match rate (low-hanging fruit).

**0 tests** within reach

No tests above 50% match threshold.

## Segfaults

No segfaults.

## Runtime Errors

No runtime errors.

## Timeouts

No timeouts.

## All Output Mismatches

**0 tests** with output mismatch, sorted by match rate (best first)

No output mismatches.

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 11 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 20 | 0 |
| | *(tests not in any document)* | 189 | 181 | 8 |
