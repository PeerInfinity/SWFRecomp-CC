# Ruffle Test Results (Filtered)

**Date**: 2026-09-19 12:56 UTC

**Git SHA**: `53a188c38f`

**Run Duration**: 42m 58s

**Filtered**: 6 tests ignored out of 229 available

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 223 |
| Passing | **213** (95.5%) |
| Ruffle-matched | 7 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **220** (98.7%) |
| Failing | 3 |
| Total expected lines | 2409 |
| Matching lines | 2348 (97.5%) |
| Mismatched lines | 61 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 3 | 100.0% |

## Passing Tests

**213 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 21.9s |  |
| 2 | `MaskTest` | 0 | 5.9s |  |
| 3 | `MaskTest-2` | 0 | 6.1s |  |
| 4 | `ZeroClipboardTest` | 3 | 21.4s |  |
| 5 | `acid/acid` | 1 | 23.6s |  |
| 6 | `acid/acid-big` | 0 | 36.8s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 22.9s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 30.0s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 22.9s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 2.9s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 7.7s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 7.6s |  |
| 13 | `acid/acid-bitmaps` | 0 | 27.9s |  |
| 14 | `acid/acid-blend` | 0 | 39.7s |  |
| 15 | `acid/acid-blend-2` | 0 | 20.5s |  |
| 16 | `acid/acid-chars` | 0 | 1.1s |  |
| 17 | `acid/acid-child` | 0 | 19.4s |  |
| 18 | `acid/acid-clip` | 0 | 1.1s |  |
| 19 | `acid/acid-clip-2` | 0 | 1.1s |  |
| 20 | `acid/acid-clip-3` | 0 | 7.2s |  |
| 21 | `acid/acid-color` | 0 | 31.3s |  |
| 22 | `acid/acid-color-0` | 0 | 20.7s |  |
| 23 | `acid/acid-color-2` | 0 | 1.1s |  |
| 24 | `acid/acid-filter` | 2 | 7.9s |  |
| 25 | `acid/acid-filter-2` | 0 | 1.4s |  |
| 26 | `acid/acid-gc` | 0 | 1.5s |  |
| 27 | `acid/acid-gradient` | 0 | 1.4s |  |
| 28 | `acid/acid-gradient-0` | 0 | 22.5s |  |
| 29 | `acid/acid-gradient-1` | 0 | 1.4s |  |
| 30 | `acid/acid-gradient-2` | 0 | 1.4s |  |
| 31 | `acid/acid-image` | 0 | 31.0s |  |
| 32 | `acid/acid-large` | 0 | 62.7s |  |
| 33 | `acid/acid-mask` | 0 | 6.7s |  |
| 34 | `acid/acid-morph` | 6 | 22.1s |  |
| 35 | `acid/acid-scale` | 0 | 1.1s |  |
| 36 | `acid/acid-shapes` | 120 | 22.3s |  |
| 37 | `acid/acid-small` | 0 | 1.2s |  |
| 38 | `acid/acid-stroke-0` | 0 | 21.9s |  |
| 39 | `acid/acid-text` | 0 | 1.1s |  |
| 40 | `acid/acid-text-2` | 1 | 2.4s |  |
| 41 | `acid/acid-text-3` | 0 | 1.1s |  |
| 42 | `acid/acid-text-4` | 0 | 6.4s |  |
| 43 | `acid/acid-text-5` | 0 | 23.3s |  |
| 44 | `acid/acid-text-6` | 0 | 17.8s |  |
| 45 | `acid/acid-text-escape` | 0 | 1.1s |  |
| 46 | `acid/acid-textfield-scroll` | 5 | 6.1s |  |
| 47 | `acid/acid-video` | 0 | 18.5s |  |
| 48 | `add` | 11 | 1.0s |  |
| 49 | `as3-interfaces` | 6 | 21.7s |  |
| 50 | `as3-loader/LoaderLoadBytesTest2` | 3 | 6.2s |  |
| 51 | `as3-loader/LoaderTest2` | 7 | 27.2s |  |
| 52 | `as3-loader/bug1093712/loader` | 1 | 7.7s |  |
| 53 | `as3-loader/bug1157243/empty` | 1 | 7.5s |  |
| 54 | `as3-loader/bug1157243/invalid` | 1 | 7.3s |  |
| 55 | `as3-loader/loaderinfo/Preloader` | 1 | 7.4s |  |
| 56 | `as3-loader/loaderinfo/loaded-content-properties` | 48 | 7.6s |  |
| 57 | `avm1/array` | 7 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 58 | `avm1/bitmapdata/getPixel` | 2 | 0.9s |  |
| 59 | `avm1/bitmapdata/loadBitmap` | 3 | 0.9s |  |
| 60 | `avm1/callee` | 2 | 1.0s |  |
| 61 | `avm1/depth` | 6 | 1.0s |  |
| 62 | `avm1/doactionorder/doactionorder` | 7 | 1.1s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 63 | `avm1/doactionorder/symbolclass` | 4 | 1.0s |  |
| 64 | `avm1/duplicateMovieClip/dontremove` | 6 | 1.0s |  |
| 65 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 0.9s |  |
| 66 | `avm1/duplicateMovieClip/name-coercion` | 3 | 1.3s |  |
| 67 | `avm1/duplicateMovieClip/samedepth` | 6 | 1.4s |  |
| 68 | `avm1/externalinterface` | 4 | 1.2s |  |
| 69 | `avm1/filters` | 149 | 1.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 70 | `avm1/haxe/flocons1` | 2 | 1.3s |  |
| 71 | `avm1/haxe/flocons2` | 3 | 1.2s |  |
| 72 | `avm1/hitarea` | 4 | 21.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 73 | `avm1/label` | 4 | 1.1s |  |
| 74 | `avm1/levels` | 9 | 0.9s |  |
| 75 | `avm1/loadevent` | 9 | 1.4s |  |
| 76 | `avm1/loadvariables/loadvariables` | 7 | 1.2s |  |
| 77 | `avm1/loadvariables/loadvars` | 2 | 0.2s |  |
| 78 | `avm1/lookup` | 3 | 0.2s |  |
| 79 | `avm1/mouse-transparency` | 1 | 1.3s |  |
| 80 | `avm1/moviecliploader` | 7 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 81 | `avm1/nativeinheritance` | 6 | 1.2s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 82 | `avm1/nested-button` | 1 | 1.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/operations` | 13 | 1.3s |  |
| 84 | `avm1/property-paths/property-paths-6` | 6 | 1.2s |  |
| 85 | `avm1/property-paths/property-paths-7` | 7 | 0.9s |  |
| 86 | `avm1/propertycase/propertycase` | 7 | 1.3s |  |
| 87 | `avm1/propertycase/propertycase-preserving-6` | 2 | 1.2s |  |
| 88 | `avm1/propertycase/propertycase-preserving-7` | 5 | 0.9s |  |
| 89 | `avm1/rollover` | 4 | 1.4s |  |
| 90 | `avm1/scope` | 14 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 91 | `avm1/setinterval` | 20 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 92 | `avm1/settimeout` | 17 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 93 | `avm1/super` | 11 | 0.9s |  |
| 94 | `avm1/target` | 18 | 0.9s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 95 | `avm1/text-bind` | 0 | 1.1s |  |
| 96 | `avm1/textfield/textfield-html` | 4 | 1.0s |  |
| 97 | `avm1/textfield/textfield-text-setters` | 8 | 1.0s |  |
| 98 | `avm1/undefined/undefined-swf6` | 39 | 1.4s |  |
| 99 | `avm1/undefined/undefined-swf7` | 39 | 1.0s |  |
| 100 | `avm1/watch` | 2 | 0.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 101 | `avm1/xml/xmlbuild` | 1 | 1.3s |  |
| 102 | `avm1/xml/xmlload` | 4 | 1.5s |  |
| 103 | `avm1/xml/xmlstring` | 9 | 1.3s |  |
| 104 | `avm1timeline1` | 3 | 1.5s |  |
| 105 | `avm1timeline2` | 6 | 1.4s |  |
| 106 | `avm2/event-dispatching` | 5 | 7.5s |  |
| 107 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 7.7s |  |
| 108 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 27.8s |  |
| 109 | `avm2/flash/geom/matrix3d/TransformBasics` | 13 | 7.6s |  |
| 110 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 7.5s |  |
| 111 | `bitmapbuttons` | 0 | 29.2s |  |
| 112 | `bitmapdata/draw-and-read` | 1 | 7.6s |  |
| 113 | `blendmode/blendmode_1` | 2 | 27.1s |  |
| 114 | `blendmode/blendmode_2` | 4 | 7.5s |  |
| 115 | `blendmode/blendmode_3` | 2 | 7.5s |  |
| 116 | `button1` | 1 | 2.8s |  |
| 117 | `button2` | 1 | 7.7s |  |
| 118 | `button3` | 1 | 1.5s |  |
| 119 | `captions` | 8 | 7.8s |  |
| 120 | `clipping` | 0 | 1.3s |  |
| 121 | `doubleAndRegister` | 2 | 1.5s |  |
| 122 | `encoding1` | 31 | 7.4s |  |
| 123 | `flash_events_Event` | 3 | 26.8s |  |
| 124 | `flash_geom_ColorTransform` | 0 | 7.4s |  |
| 125 | `flash_net_URLLoader` | 7 | 26.8s |  |
| 126 | `flash_net_URLRequest` | 6 | 7.5s |  |
| 127 | `flash_net_classes` | 22 | 7.6s |  |
| 128 | `flash_utils_Timer` | 2 | 7.5s |  |
| 129 | `fscommand1` | 1 | 1.2s |  |
| 130 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 21.1s |  |
| 131 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 48 | 16.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 132 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 15.1s |  |
| 133 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.4s |  |
| 134 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 14.9s |  |
| 135 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 70 | 15.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 136 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 57 | 15.3s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 137 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 71 | 16.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 138 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 16 | 15.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 139 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 21.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 140 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 23 | 21.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 141 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 50 | 22.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 142 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 67 | 21.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 143 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 20.5s |  |
| 144 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 26 | 21.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 145 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 20.6s |  |
| 146 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 31 | 17.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 147 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 16.2s |  |
| 148 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 16.2s |  |
| 149 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 25 | 16.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 150 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 16.5s |  |
| 151 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 29 | 17.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 152 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 16.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 153 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 35 | 16.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 154 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 16.4s |  |
| 155 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 37 | 17.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 156 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 43 | 16.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 157 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 22 | 1.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 158 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 19 | 16.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 159 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 24 | 16.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 160 | `gradient` | 0 | 1.3s |  |
| 161 | `gradientTransform` | 0 | 20.5s |  |
| 162 | `hardwrap` | 1 | 7.7s |  |
| 163 | `hitTestStyleChange` | 1 | 26.7s |  |
| 164 | `hittesting/hittesting` | 18 | 7.5s |  |
| 165 | `hittesting/mask-hit-test` | 1 | 2.5s |  |
| 166 | `image-loading` | 4 | 7.5s |  |
| 167 | `invalidClipDepth` | 0 | 20.7s |  |
| 168 | `local2global` | 1 | 7.4s |  |
| 169 | `localconnection` | 12 | 8.0s |  |
| 170 | `lzma` | 5 | 7.3s |  |
| 171 | `lzma_bytes` | 2 | 26.8s |  |
| 172 | `mouse/mouse_coords` | 2 | 7.5s |  |
| 173 | `mouse/start_drag` | 3 | 27.5s |  |
| 174 | `mouse/start_drag_lock` | 3 | 7.6s |  |
| 175 | `movieclip` | 9 | 7.6s |  |
| 176 | `movieinfo1` | 3 | 1.3s |  |
| 177 | `slider_component` | 4 | 15.1s |  |
| 178 | `stream1` | 9 | 7.8s |  |
| 179 | `stroke1` | 1 | 7.7s |  |
| 180 | `stylesheet` | 3 | 7.5s |  |
| 181 | `targetPath1` | 8 | 1.3s |  |
| 182 | `timeline/Timeline3` | 5 | 27.1s |  |
| 183 | `timeline/Timeline4` | 5 | 26.9s |  |
| 184 | `timeline/Timeline8` | 5 | 7.7s |  |
| 185 | `timeline/Timeline9` | 11 | 7.6s |  |
| 186 | `timeline/events/timeline_events_fp10` | 67 | 7.9s |  |
| 187 | `timeline/events/timeline_events_fp9` | 48 | 26.6s |  |
| 188 | `timeline/nav/blendMode` | 8 | 6.3s |  |
| 189 | `timeline/nav/cacheAsBitmap` | 8 | 6.3s |  |
| 190 | `timeline/nav/colorTransform` | 8 | 6.4s |  |
| 191 | `timeline/nav/filters` | 8 | 6.4s |  |
| 192 | `timeline/nav/matrix` | 8 | 6.4s |  |
| 193 | `timeline/nav/morphShape` | 4 | 27.7s |  |
| 194 | `timeline/nav/name` | 8 | 27.3s |  |
| 195 | `timeline/nav/ratio` | 4 | 7.5s |  |
| 196 | `timeline/nav/ratio2` | 4 | 7.4s |  |
| 197 | `timeline/nav/ratio3` | 4 | 0.6s |  |
| 198 | `timeline/nav/shape` | 4 | 7.5s |  |
| 199 | `timeline/scene/EncodedU32` | 1 | 27.6s |  |
| 200 | `timeline/scene/Scene_1_MainTimeline` | 70 | 28.4s |  |
| 201 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 7.6s |  |
| 202 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 7.4s |  |
| 203 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 7.4s |  |
| 204 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 7.0s |  |
| 205 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 7.5s |  |
| 206 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 27.7s |  |
| 207 | `timeline/timeline_as2_1` | 3 | 21.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 208 | `timeline/timeline_as2_2` | 3 | 1.4s |  |
| 209 | `timeline/timeline_as2_3` | 3 | 21.2s |  |
| 210 | `timeline/timeline_as2_4` | 2 | 21.2s |  |
| 211 | `timeline/timeline_as2_5` | 4 | 1.8s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 212 | `timeline/timeline_loop` | 7 | 27.8s |  |
| 213 | `timeline/timeline_name_0` | 13 | 27.1s |  |

## Ruffle-Matched Tests

**7 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `acid/acid-shapes-testing` | 12 | 12 | 22.0s |  |
| 2 | `acid/acid-text-x` | 1 | 1 | 6.4s |  |
| 3 | `acid/acid-textfield` | 6 | 7 | 6.4s |  |
| 4 | `as3-loader/LoaderTest` | 2 | 2 | 22.4s |  |
| 5 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 7.3s |  |
| 6 | `flash_text_TextField` | 5 | 8 | 27.5s |  |
| 7 | `timeline/nav/clipDepth` | 4 | 4 | 6.4s |  |

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

**3 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `bitmapdata/getpixel-from-embedded` | 50.0% | 1/2 | 2 | 2 |  |
| 2 | `as3-loader/LoaderLoadBytesTest` | 25.0% | 1/4 | 3 | 4 |  |
| 3 | `as3-loader/events/loader-events` | 13.9% | 5/36 | 35 | 36 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 11 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 20 | 0 |
| | *(tests not in any document)* | 189 | 179 | 10 |
