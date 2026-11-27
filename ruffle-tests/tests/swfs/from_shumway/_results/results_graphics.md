# Ruffle Test Results (Unfiltered)

**Date**: 2026-11-27 18:08 UTC

**Git SHA**: `f4edebdcec`

**Run Duration**: 41m 48s

## Summary

| Metric | Value |
|--------|-------|
| Total tests | 229 |
| Passing | **215** (93.9%) |
| Ruffle-matched | 13 (diffs ⊆ Ruffle's against Flash) |
| Effective pass | **228** (99.6%) |
| Failing | 1 |
| Total expected lines | 2484 |
| Matching lines | 2408 (96.9%) |
| Mismatched lines | 76 |

### Failure Breakdown

| Category | Count | % of Failures |
|----------|-------|---------------|
| Output Mismatch | 1 | 100.0% |

## Passing Tests

**215 tests passing**

| # | Test | Lines | Duration | Notes |
|---|------|-------|----------|-------|
| 1 | `3_joystick` | 4 | 25.6s |  |
| 2 | `MaskTest` | 0 | 7.5s |  |
| 3 | `MaskTest-2` | 0 | 7.3s |  |
| 4 | `ZeroClipboardTest` | 3 | 24.7s |  |
| 5 | `acid/acid` | 1 | 29.9s |  |
| 6 | `acid/acid-big` | 0 | 40.9s |  |
| 7 | `acid/acid-bitmap-draw_quality_high` | 0 | 25.5s |  |
| 8 | `acid/acid-bitmap-draw_quality_low` | 0 | 27.4s |  |
| 9 | `acid/acid-bitmap-fill` | 0 | 21.6s |  |
| 10 | `acid/acid-bitmap-fill-2` | 0 | 3.0s |  |
| 11 | `acid/acid-bitmapData-copyPixels` | 0 | 7.5s |  |
| 12 | `acid/acid-bitmapData-draw` | 0 | 7.7s |  |
| 13 | `acid/acid-bitmaps` | 0 | 26.1s |  |
| 14 | `acid/acid-blend` | 0 | 35.9s |  |
| 15 | `acid/acid-blend-2` | 0 | 19.7s |  |
| 16 | `acid/acid-chars` | 0 | 2.4s |  |
| 17 | `acid/acid-child` | 0 | 22.5s |  |
| 18 | `acid/acid-clip` | 0 | 2.5s |  |
| 19 | `acid/acid-clip-2` | 0 | 2.3s |  |
| 20 | `acid/acid-clip-3` | 0 | 9.1s |  |
| 21 | `acid/acid-color` | 0 | 35.3s |  |
| 22 | `acid/acid-color-0` | 0 | 23.3s |  |
| 23 | `acid/acid-color-2` | 0 | 2.3s |  |
| 24 | `acid/acid-filter` | 2 | 9.8s |  |
| 25 | `acid/acid-filter-2` | 0 | 2.0s |  |
| 26 | `acid/acid-gc` | 0 | 1.8s |  |
| 27 | `acid/acid-gradient` | 0 | 1.8s |  |
| 28 | `acid/acid-gradient-0` | 0 | 19.9s |  |
| 29 | `acid/acid-gradient-1` | 0 | 1.8s |  |
| 30 | `acid/acid-gradient-2` | 0 | 1.8s |  |
| 31 | `acid/acid-image` | 0 | 28.1s |  |
| 32 | `acid/acid-large` | 0 | 69.5s |  |
| 33 | `acid/acid-mask` | 0 | 8.6s |  |
| 34 | `acid/acid-morph` | 6 | 25.9s |  |
| 35 | `acid/acid-scale` | 0 | 1.8s |  |
| 36 | `acid/acid-shapes` | 120 | 26.7s |  |
| 37 | `acid/acid-small` | 0 | 2.1s |  |
| 38 | `acid/acid-stroke-0` | 0 | 25.6s |  |
| 39 | `acid/acid-text` | 0 | 1.9s |  |
| 40 | `acid/acid-text-2` | 1 | 2.8s |  |
| 41 | `acid/acid-text-3` | 0 | 1.8s |  |
| 42 | `acid/acid-text-4` | 0 | 7.8s |  |
| 43 | `acid/acid-text-5` | 0 | 27.9s |  |
| 44 | `acid/acid-text-6` | 0 | 21.4s |  |
| 45 | `acid/acid-text-escape` | 0 | 1.8s |  |
| 46 | `acid/acid-textfield-scroll` | 5 | 10.6s |  |
| 47 | `acid/acid-video` | 0 | 30.4s |  |
| 48 | `add` | 11 | 2.5s |  |
| 49 | `as3-interfaces` | 6 | 10.4s |  |
| 50 | `as3-loader/LoaderLoadBytesTest` | 4 | 11.0s |  |
| 51 | `as3-loader/LoaderLoadBytesTest2` | 3 | 10.3s |  |
| 52 | `as3-loader/LoaderTest2` | 7 | 25.4s |  |
| 53 | `as3-loader/bug1093712/loader` | 1 | 7.3s |  |
| 54 | `as3-loader/bug1157243/empty` | 1 | 7.2s |  |
| 55 | `as3-loader/bug1157243/invalid` | 1 | 7.1s |  |
| 56 | `as3-loader/loaderinfo/Preloader` | 1 | 7.1s |  |
| 57 | `as3-loader/loaderinfo/loaded-content-properties` | 48 | 7.2s |  |
| 58 | `avm1/array` | 7 | 1.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 59 | `avm1/bitmapdata/getPixel` | 2 | 1.9s |  |
| 60 | `avm1/bitmapdata/loadBitmap` | 3 | 1.8s |  |
| 61 | `avm1/callee` | 2 | 1.7s |  |
| 62 | `avm1/depth` | 6 | 1.8s |  |
| 63 | `avm1/doactionorder/doactionorder` | 7 | 2.0s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 64 | `avm1/doactionorder/symbolclass` | 4 | 1.9s |  |
| 65 | `avm1/duplicateMovieClip/dontremove` | 6 | 2.0s |  |
| 66 | `avm1/duplicateMovieClip/duplicateMovieClip` | 4 | 1.8s |  |
| 67 | `avm1/duplicateMovieClip/name-coercion` | 3 | 2.0s |  |
| 68 | `avm1/duplicateMovieClip/samedepth` | 6 | 2.2s |  |
| 69 | `avm1/externalinterface` | 4 | 2.0s |  |
| 70 | `avm1/filters` | 149 | 2.6s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 71 | `avm1/haxe/flocons1` | 2 | 2.0s |  |
| 72 | `avm1/haxe/flocons2` | 3 | 2.0s |  |
| 73 | `avm1/hitarea` | 4 | 20.3s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 74 | `avm1/label` | 4 | 2.3s |  |
| 75 | `avm1/levels` | 9 | 1.7s |  |
| 76 | `avm1/loadevent` | 9 | 1.8s |  |
| 77 | `avm1/loadvariables/loadvariables` | 7 | 1.6s |  |
| 78 | `avm1/loadvariables/loadvars` | 2 | 0.7s |  |
| 79 | `avm1/lookup` | 3 | 0.9s |  |
| 80 | `avm1/mouse-transparency` | 1 | 1.8s |  |
| 81 | `avm1/moviecliploader` | 7 | 1.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) [3](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) |
| 82 | `avm1/nativeinheritance` | 6 | 1.7s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 83 | `avm1/nested-button` | 1 | 2.4s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 84 | `avm1/operations` | 13 | 2.3s |  |
| 85 | `avm1/property-paths/property-paths-6` | 6 | 2.3s |  |
| 86 | `avm1/property-paths/property-paths-7` | 7 | 2.0s |  |
| 87 | `avm1/propertycase/propertycase` | 7 | 2.2s |  |
| 88 | `avm1/propertycase/propertycase-preserving-6` | 2 | 2.2s |  |
| 89 | `avm1/propertycase/propertycase-preserving-7` | 5 | 2.0s |  |
| 90 | `avm1/rollover` | 4 | 2.4s |  |
| 91 | `avm1/scope` | 14 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 92 | `avm1/setinterval` | 20 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 93 | `avm1/settimeout` | 17 | 2.1s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 94 | `avm1/super` | 11 | 2.1s |  |
| 95 | `avm1/target` | 18 | 2.5s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 96 | `avm1/text-bind` | 0 | 3.4s |  |
| 97 | `avm1/textfield/textfield-html` | 4 | 2.3s |  |
| 98 | `avm1/textfield/textfield-text-setters` | 8 | 2.3s |  |
| 99 | `avm1/undefined/undefined-swf6` | 39 | 1.7s |  |
| 100 | `avm1/undefined/undefined-swf7` | 39 | 1.4s |  |
| 101 | `avm1/watch` | 2 | 0.8s | [2](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) |
| 102 | `avm1/xml/xmlbuild` | 1 | 1.4s |  |
| 103 | `avm1/xml/xmlload` | 4 | 1.7s |  |
| 104 | `avm1/xml/xmlstring` | 9 | 1.6s |  |
| 105 | `avm1timeline1` | 3 | 1.7s |  |
| 106 | `avm1timeline2` | 6 | 1.7s |  |
| 107 | `avm2/event-dispatching` | 5 | 7.3s |  |
| 108 | `avm2/flash/display/bitmapdata/bitmapdata-clone` | 0 | 7.7s |  |
| 109 | `avm2/flash/geom/matrix3d/Matrix3DClass` | 56 | 8.2s |  |
| 110 | `avm2/flash/geom/matrix3d/TransformBasics` | 13 | 7.4s |  |
| 111 | `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | 20 | 7.3s |  |
| 112 | `bitmapbuttons` | 0 | 27.4s |  |
| 113 | `bitmapdata/draw-and-read` | 1 | 11.3s |  |
| 114 | `bitmapdata/getpixel-from-embedded` | 2 | 8.6s |  |
| 115 | `blendmode/blendmode_1` | 2 | 27.3s |  |
| 116 | `blendmode/blendmode_2` | 4 | 8.5s |  |
| 117 | `blendmode/blendmode_3` | 2 | 8.4s |  |
| 118 | `button1` | 1 | 9.3s |  |
| 119 | `button2` | 1 | 9.7s |  |
| 120 | `button3` | 1 | 3.1s |  |
| 121 | `captions` | 8 | 7.8s |  |
| 122 | `clipping` | 0 | 1.8s |  |
| 123 | `doubleAndRegister` | 2 | 1.9s |  |
| 124 | `encoding1` | 31 | 7.2s |  |
| 125 | `flash_events_Event` | 3 | 7.2s |  |
| 126 | `flash_geom_ColorTransform` | 0 | 7.2s |  |
| 127 | `flash_net_URLLoader` | 7 | 2.6s |  |
| 128 | `flash_net_URLRequest` | 6 | 7.3s |  |
| 129 | `flash_net_classes` | 22 | 7.5s |  |
| 130 | `flash_utils_Timer` | 2 | 7.2s |  |
| 131 | `fscommand1` | 1 | 1.6s |  |
| 132 | `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | 6 | 20.3s |  |
| 133 | `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | 48 | 20.0s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 134 | `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | 0 | 18.5s |  |
| 135 | `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | 3 | 1.8s |  |
| 136 | `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | 1 | 18.6s |  |
| 137 | `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | 70 | 18.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 138 | `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | 57 | 19.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 139 | `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | 71 | 19.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 140 | `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | 16 | 19.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 141 | `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | 7 | 20.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 142 | `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | 23 | 20.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 143 | `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | 50 | 20.9s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 144 | `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | 67 | 20.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 145 | `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | 0 | 19.6s |  |
| 146 | `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | 26 | 20.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 147 | `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | 3 | 19.4s |  |
| 148 | `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | 31 | 21.5s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 149 | `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | 0 | 19.9s |  |
| 150 | `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | 3 | 19.7s |  |
| 151 | `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | 25 | 20.1s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 152 | `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | 8 | 19.9s |  |
| 153 | `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | 29 | 20.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 154 | `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | 5 | 19.8s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 155 | `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | 35 | 20.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 156 | `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | 6 | 20.3s |  |
| 157 | `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | 37 | 21.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 158 | `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | 43 | 20.7s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 159 | `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | 22 | 2.2s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 160 | `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | 19 | 20.6s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 161 | `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | 24 | 20.4s | [4](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) |
| 162 | `gradient` | 0 | 3.6s |  |
| 163 | `gradientTransform` | 0 | 29.4s |  |
| 164 | `hardwrap` | 1 | 10.9s |  |
| 165 | `hitTestStyleChange` | 1 | 38.2s |  |
| 166 | `hittesting/hittesting` | 18 | 10.5s |  |
| 167 | `hittesting/mask-hit-test` | 1 | 3.5s |  |
| 168 | `image-loading` | 4 | 7.2s |  |
| 169 | `invalidClipDepth` | 0 | 19.4s |  |
| 170 | `local2global` | 1 | 7.2s |  |
| 171 | `localconnection` | 12 | 7.4s |  |
| 172 | `lzma` | 5 | 7.0s |  |
| 173 | `lzma_bytes` | 2 | 24.7s |  |
| 174 | `mouse/mouse_coords` | 2 | 7.2s |  |
| 175 | `mouse/start_drag` | 3 | 25.1s |  |
| 176 | `mouse/start_drag_lock` | 3 | 7.1s |  |
| 177 | `movieclip` | 9 | 7.1s |  |
| 178 | `movieinfo1` | 3 | 1.6s |  |
| 179 | `slider_component` | 4 | 12.7s |  |
| 180 | `stream1` | 9 | 7.2s |  |
| 181 | `stroke1` | 1 | 7.2s |  |
| 182 | `stylesheet` | 3 | 7.8s |  |
| 183 | `targetPath1` | 8 | 1.6s |  |
| 184 | `timeline/Timeline3` | 5 | 25.8s |  |
| 185 | `timeline/Timeline4` | 5 | 25.7s |  |
| 186 | `timeline/Timeline8` | 5 | 7.5s |  |
| 187 | `timeline/Timeline9` | 11 | 7.5s |  |
| 188 | `timeline/events/timeline_events_fp10` | 67 | 7.6s |  |
| 189 | `timeline/events/timeline_events_fp9` | 48 | 0.9s |  |
| 190 | `timeline/nav/blendMode` | 8 | 1.0s |  |
| 191 | `timeline/nav/cacheAsBitmap` | 8 | 0.9s |  |
| 192 | `timeline/nav/colorTransform` | 8 | 0.9s |  |
| 193 | `timeline/nav/filters` | 8 | 1.0s |  |
| 194 | `timeline/nav/matrix` | 8 | 0.9s |  |
| 195 | `timeline/nav/morphShape` | 4 | 6.2s |  |
| 196 | `timeline/nav/name` | 8 | 6.2s |  |
| 197 | `timeline/nav/ratio` | 4 | 6.2s |  |
| 198 | `timeline/nav/ratio2` | 4 | 6.2s |  |
| 199 | `timeline/nav/ratio3` | 4 | 0.9s |  |
| 200 | `timeline/nav/shape` | 4 | 6.3s |  |
| 201 | `timeline/scene/EncodedU32` | 1 | 24.8s |  |
| 202 | `timeline/scene/Scene_1_MainTimeline` | 70 | 25.9s |  |
| 203 | `timeline/scene/Scene_2_MovieClipTimeline` | 70 | 7.3s |  |
| 204 | `timeline/scene/Scene_3_GotoAndStop_LabelScene` | 15 | 7.4s |  |
| 205 | `timeline/scene/Scene_4_GotoAndStop_FrameScene` | 15 | 7.3s |  |
| 206 | `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | 15 | 7.0s |  |
| 207 | `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | 40 | 7.1s |  |
| 208 | `timeline/scene/Scene_7_NextPrevScene` | 7 | 25.8s |  |
| 209 | `timeline/timeline_as2_1` | 3 | 20.3s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 210 | `timeline/timeline_as2_2` | 3 | 1.8s |  |
| 211 | `timeline/timeline_as2_3` | 3 | 1.7s |  |
| 212 | `timeline/timeline_as2_4` | 2 | 1.8s |  |
| 213 | `timeline/timeline_as2_5` | 4 | 5.7s | [1](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) |
| 214 | `timeline/timeline_loop` | 7 | 8.9s |  |
| 215 | `timeline/timeline_name_0` | 13 | 7.5s |  |

## Ruffle-Matched Tests

**13 tests promoted** — our diffs against Flash's `output.txt` are a proper subset of Ruffle's diffs against the same file (i.e. we are at least as good as Ruffle on every line of these tests). Each carries `known_failure = true` upstream with a sidecar `output.ruffle.txt`.

| # | Test | Our diffs | Ruffle diffs | Duration | Notes |
|---|------|-----------|--------------|----------|-------|
| 1 | `MaskTest-3` | 1 | 1 | 7.1s |  |
| 2 | `acid/acid-shapes-testing` | 12 | 12 | 26.3s |  |
| 3 | `acid/acid-text-x` | 1 | 1 | 7.5s |  |
| 4 | `acid/acid-textfield` | 6 | 7 | 11.1s |  |
| 5 | `as3-loader/LoaderTest` | 2 | 2 | 34.0s |  |
| 6 | `as3-loader/events/loader-events` | 20 | 28 | 7.6s |  |
| 7 | `avm1movie` | 12 | 12 | 25.9s |  |
| 8 | `avm2/flash/geom/transform/pixelBounds` | 1 | 1 | 7.2s |  |
| 9 | `flash_net_SharedObject` | 1 | 1 | 7.2s |  |
| 10 | `flash_text_TextField` | 5 | 8 | 26.8s |  |
| 11 | `flash_text_TextField2` | 9 | 9 | 10.2s |  |
| 12 | `getobjectsunderpoint` | 9 | 15 | 13.2s |  |
| 13 | `timeline/nav/clipDepth` | 4 | 4 | 0.9s |  |

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

**1 tests** with output mismatch, sorted by match rate (best first)

| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |
|---|------|------------|----------------|--------|----------|-------|
| 1 | `esc` | 0.0% | 0/13 | 13 | 2 |  |

## Investigation Documents

| # | Document | Tests | Passing | Failing |
|---|----------|-------|---------|---------|
| 1 | [ACTION_QUEUE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/ACTION_QUEUE_PLAN.md) | 3 | 3 | 0 |
| 2 | [SHUMWAY_AVM1_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_PLAN.md) | 11 | 11 | 0 |
| 3 | [SHUMWAY_AVM1_SUBTREES_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_AVM1_SUBTREES_PLAN.md) | 1 | 1 | 0 |
| 4 | [SHUMWAY_FUZZ_TIMELINE_PLAN.md](ruffle-tests/tests/swfs/from_shumway/_investigation/complete/SHUMWAY_FUZZ_TIMELINE_PLAN.md) | 20 | 20 | 0 |
| | *(tests not in any document)* | 195 | 181 | 14 |
