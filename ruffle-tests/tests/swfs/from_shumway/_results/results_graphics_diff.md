# Ruffle Test Results Diff

**Previous:** `16314e63feaa` (2026-08-13T21:54:57.588885+00:00)
**Current:** `3db858cbc157` (2026-08-13T22:38:36.742862+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 0 | 207 | +207 |
| Total | 229 | 229 | 0 |
| Pass rate | 0.0% | 90.4% | +90.4% |
| Mismatched lines | 0 | 308 | +308 |
|   Increased | | | +308 |

## Newly Passing (207)

| Test | Previous Status | Lines (prev) | Lines (now) |
|------|----------------|--------------|-------------|
| `3_joystick` | compile_fail | - | 4/4 |
| `MaskTest` | compile_fail | - | 0/0 |
| `MaskTest-2` | compile_fail | - | 0/0 |
| `ZeroClipboardTest` | compile_fail | - | 3/3 |
| `acid/acid` | compile_fail | - | 1/1 |
| `acid/acid-big` | compile_fail | - | 0/0 |
| `acid/acid-bitmap-draw_quality_high` | compile_fail | - | 0/0 |
| `acid/acid-bitmap-draw_quality_low` | compile_fail | - | 0/0 |
| `acid/acid-bitmap-fill` | compile_fail | - | 0/0 |
| `acid/acid-bitmap-fill-2` | compile_fail | - | 0/0 |
| `acid/acid-bitmapData-copyPixels` | compile_fail | - | 0/0 |
| `acid/acid-bitmapData-draw` | compile_fail | - | 0/0 |
| `acid/acid-bitmaps` | compile_fail | - | 0/0 |
| `acid/acid-blend` | compile_fail | - | 0/0 |
| `acid/acid-blend-2` | compile_fail | - | 0/0 |
| `acid/acid-chars` | compile_fail | - | 0/0 |
| `acid/acid-child` | compile_fail | - | 0/0 |
| `acid/acid-clip` | compile_fail | - | 0/0 |
| `acid/acid-clip-2` | compile_fail | - | 0/0 |
| `acid/acid-clip-3` | compile_fail | - | 0/0 |
| `acid/acid-color` | compile_fail | - | 0/0 |
| `acid/acid-color-0` | compile_fail | - | 0/0 |
| `acid/acid-color-2` | compile_fail | - | 0/0 |
| `acid/acid-filter` | compile_fail | - | 2/2 |
| `acid/acid-filter-2` | compile_fail | - | 0/0 |
| `acid/acid-gc` | compile_fail | - | 0/0 |
| `acid/acid-gradient` | compile_fail | - | 0/0 |
| `acid/acid-gradient-0` | compile_fail | - | 0/0 |
| `acid/acid-gradient-1` | compile_fail | - | 0/0 |
| `acid/acid-gradient-2` | compile_fail | - | 0/0 |
| `acid/acid-image` | compile_fail | - | 0/0 |
| `acid/acid-large` | compile_fail | - | 0/0 |
| `acid/acid-mask` | compile_fail | - | 0/0 |
| `acid/acid-scale` | compile_fail | - | 0/0 |
| `acid/acid-small` | compile_fail | - | 0/0 |
| `acid/acid-stroke-0` | compile_fail | - | 0/0 |
| `acid/acid-text` | compile_fail | - | 0/0 |
| `acid/acid-text-2` | compile_fail | - | 1/1 |
| `acid/acid-text-3` | compile_fail | - | 0/0 |
| `acid/acid-text-4` | compile_fail | - | 0/0 |
| `acid/acid-text-5` | compile_fail | - | 0/0 |
| `acid/acid-text-6` | compile_fail | - | 0/0 |
| `acid/acid-text-escape` | compile_fail | - | 0/0 |
| `acid/acid-textfield-scroll` | compile_fail | - | 5/5 |
| `acid/acid-video` | compile_fail | - | 0/0 |
| `add` | compile_fail | - | 11/11 |
| `as3-interfaces` | compile_fail | - | 6/6 |
| `as3-loader/LoaderLoadBytesTest2` | compile_fail | - | 3/3 |
| `as3-loader/bug1093712/loader` | compile_fail | - | 1/1 |
| `as3-loader/bug1157243/empty` | compile_fail | - | 1/1 |
| `as3-loader/bug1157243/invalid` | compile_fail | - | 1/1 |
| `as3-loader/loaderinfo/Preloader` | compile_fail | - | 1/1 |
| `avm1/array` | compile_fail | - | 7/7 |
| `avm1/bitmapdata/getPixel` | compile_fail | - | 2/2 |
| `avm1/bitmapdata/loadBitmap` | compile_fail | - | 3/3 |
| `avm1/callee` | compile_fail | - | 2/2 |
| `avm1/depth` | compile_fail | - | 6/6 |
| `avm1/doactionorder/doactionorder` | compile_fail | - | 7/7 |
| `avm1/doactionorder/symbolclass` | compile_fail | - | 4/4 |
| `avm1/duplicateMovieClip/dontremove` | compile_fail | - | 6/6 |
| `avm1/duplicateMovieClip/duplicateMovieClip` | compile_fail | - | 4/4 |
| `avm1/duplicateMovieClip/name-coercion` | compile_fail | - | 3/3 |
| `avm1/duplicateMovieClip/samedepth` | compile_fail | - | 6/6 |
| `avm1/externalinterface` | compile_fail | - | 4/4 |
| `avm1/filters` | compile_fail | - | 149/149 |
| `avm1/haxe/flocons1` | compile_fail | - | 2/2 |
| `avm1/haxe/flocons2` | compile_fail | - | 3/3 |
| `avm1/label` | compile_fail | - | 4/4 |
| `avm1/levels` | compile_fail | - | 9/9 |
| `avm1/loadevent` | compile_fail | - | 9/9 |
| `avm1/loadvariables/loadvariables` | compile_fail | - | 7/7 |
| `avm1/loadvariables/loadvars` | compile_fail | - | 2/2 |
| `avm1/lookup` | compile_fail | - | 3/3 |
| `avm1/mouse-transparency` | compile_fail | - | 1/1 |
| `avm1/moviecliploader` | compile_fail | - | 7/7 |
| `avm1/nativeinheritance` | compile_fail | - | 6/6 |
| `avm1/nested-button` | compile_fail | - | 1/1 |
| `avm1/operations` | compile_fail | - | 13/13 |
| `avm1/property-paths/property-paths-6` | compile_fail | - | 6/6 |
| `avm1/property-paths/property-paths-7` | compile_fail | - | 7/7 |
| `avm1/propertycase/propertycase` | compile_fail | - | 7/7 |
| `avm1/propertycase/propertycase-preserving-6` | compile_fail | - | 2/2 |
| `avm1/propertycase/propertycase-preserving-7` | compile_fail | - | 5/5 |
| `avm1/rollover` | compile_fail | - | 4/4 |
| `avm1/scope` | compile_fail | - | 14/14 |
| `avm1/setinterval` | compile_fail | - | 20/20 |
| `avm1/settimeout` | compile_fail | - | 17/17 |
| `avm1/super` | compile_fail | - | 11/11 |
| `avm1/target` | compile_fail | - | 18/18 |
| `avm1/text-bind` | compile_fail | - | 0/0 |
| `avm1/textfield/textfield-html` | compile_fail | - | 4/4 |
| `avm1/textfield/textfield-text-setters` | compile_fail | - | 8/8 |
| `avm1/undefined/undefined-swf6` | compile_fail | - | 39/39 |
| `avm1/undefined/undefined-swf7` | compile_fail | - | 39/39 |
| `avm1/watch` | compile_fail | - | 2/2 |
| `avm1/xml/xmlbuild` | compile_fail | - | 1/1 |
| `avm1/xml/xmlload` | compile_fail | - | 4/4 |
| `avm1/xml/xmlstring` | compile_fail | - | 9/9 |
| `avm1timeline1` | compile_fail | - | 3/3 |
| `avm1timeline2` | compile_fail | - | 6/6 |
| `avm2/event-dispatching` | compile_fail | - | 5/5 |
| `avm2/flash/display/bitmapdata/bitmapdata-clone` | compile_fail | - | 0/0 |
| `avm2/flash/geom/matrix3d/Matrix3DClass` | compile_fail | - | 56/56 |
| `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | compile_fail | - | 20/20 |
| `bitmapbuttons` | compile_fail | - | 0/0 |
| `bitmapdata/draw-and-read` | compile_fail | - | 1/1 |
| `blendmode/blendmode_1` | compile_fail | - | 2/2 |
| `blendmode/blendmode_2` | compile_fail | - | 4/4 |
| `blendmode/blendmode_3` | compile_fail | - | 2/2 |
| `button1` | compile_fail | - | 1/1 |
| `button2` | compile_fail | - | 1/1 |
| `button3` | compile_fail | - | 1/1 |
| `captions` | compile_fail | - | 8/8 |
| `clipping` | compile_fail | - | 0/0 |
| `doubleAndRegister` | compile_fail | - | 2/2 |
| `encoding1` | compile_fail | - | 31/31 |
| `flash_events_Event` | compile_fail | - | 3/3 |
| `flash_geom_ColorTransform` | compile_fail | - | 0/0 |
| `flash_net_URLLoader` | compile_fail | - | 7/7 |
| `flash_net_URLRequest` | compile_fail | - | 6/6 |
| `flash_net_classes` | compile_fail | - | 22/22 |
| `flash_utils_Timer` | compile_fail | - | 2/2 |
| `fscommand1` | compile_fail | - | 1/1 |
| `fuzz/07580c34e05cda7bd4c976c459f0a667ca3c2602110e34186bca676f311e84da` | compile_fail | - | 6/6 |
| `fuzz/0cde3acaa5116dac19bf73b0b76556223ad9328a367e04ec9cab733bc6765d82` | compile_fail | - | 48/48 |
| `fuzz/0db0a01a92ae6ad0d2805dcfbac2ddf9a9689e77cd007924adfac57b543b1ed2` | compile_fail | - | 0/0 |
| `fuzz/1276557624e197ee764676c0aa9cb8ee52156dc7269956ee9b3e131a6f7b6dd0` | compile_fail | - | 3/3 |
| `fuzz/2f4f46bf21d6cd33a751b090ad97552e8cdd8f7a606e7f0796deba04abb2e229` | compile_fail | - | 1/1 |
| `fuzz/33c31f96f8d026037b9024c497870471636f0c31dccb624be67775662b37b096` | compile_fail | - | 70/70 |
| `fuzz/356bf4ddf127739c3a1e3ea06b5cee9261dfc55a5ea4755013927647455e7c77` | compile_fail | - | 57/57 |
| `fuzz/42f71d860e22e456a9bd61c2d9e8c8da9536152b879a131dd7a400ff61a4a3e3` | compile_fail | - | 71/71 |
| `fuzz/438789f3e93da74855898cceed80e21291c6ab14cf36314a856c6f2716606a49` | compile_fail | - | 16/16 |
| `fuzz/4935e4aed5e63f07d9e6cc76e97d080f042b029a838630fb2b276b5da0affd26` | compile_fail | - | 7/7 |
| `fuzz/4949de464f5408bc3eaaa543d2e2346e01961965a6aa057dba9a6903fcf1c822` | compile_fail | - | 23/23 |
| `fuzz/5d828b99311b51073db245c0c3468e9f12d9cc8226ecbf00916cb725c02528cd` | compile_fail | - | 50/50 |
| `fuzz/65f0c0a49528b4350e0521d10c632e475a5670010f817d406246b9771a1c2121` | compile_fail | - | 67/67 |
| `fuzz/6f3b6cbd618b5b816edbf27e14f631aef42da1a4bcc467fb1aa2951d6c85ee48` | compile_fail | - | 0/0 |
| `fuzz/7318344161196391b369e91217937687ebc437e42fdcc10c4c456bde55e0db61` | compile_fail | - | 26/26 |
| `fuzz/81004241e3a9278ee3c26c5d7d04a3677e7a28618dd0dd2ad041a98374a280f0` | compile_fail | - | 3/3 |
| `fuzz/887c02ab98dbdd3ae22b2363b212dba005565738a572a2156e703dd3bf9b40af` | compile_fail | - | 31/31 |
| `fuzz/9cad44804736a4fbd806d349c97b81d33c3f09ed4d9278acc4ef5cfbab147f3c` | compile_fail | - | 0/0 |
| `fuzz/a86fee6d68f77c63cd83f33d136be2c48f0ab7ab0414a93a0b711ec2a19c6883` | compile_fail | - | 3/3 |
| `fuzz/ac649dcf28572cc8250759cc0f8571a4111361fb6923db34ff02901095cdc580` | compile_fail | - | 25/25 |
| `fuzz/ac93c8c9a3efe3e9a0421d6163158827696b5e4d0ac4fa1262f32e8c5bb7f732` | compile_fail | - | 8/8 |
| `fuzz/b29624af5fa348d05b0772ca3b4552c45c90f4515a1ab901e3c754688e35be1b` | compile_fail | - | 29/29 |
| `fuzz/b480790b84c3a62fe6fa3486d26fd23988a5acd038261c04349ad4368107e6ca` | compile_fail | - | 5/5 |
| `fuzz/c24e6e559fd66b092283a3bdcd925792e8dd7ca55ce1c7729d44d5b315ad8f75` | compile_fail | - | 35/35 |
| `fuzz/c8b8069c2ba2a93e50b8d8410ed73191c3bb39b75ba0749309f9e580e0525d69` | compile_fail | - | 6/6 |
| `fuzz/cf67270dbe5367af59f1bf029f413b8b7b0fb7000cbd0ee534d369087d20601b` | compile_fail | - | 37/37 |
| `fuzz/e152812e2cfc0971237321dfadc37e3484631c355cb2e4b86344ff90bb89c75e` | compile_fail | - | 43/43 |
| `fuzz/e5b0ab65b5f16ff7117db5cb636de47c5132352253497256c2abcdec7e785897` | compile_fail | - | 22/22 |
| `fuzz/f40458686ee60b6b4bd4fe59188ccadc6aeb4094f38536977c11e02430143052` | compile_fail | - | 19/19 |
| `fuzz/f5398dd73a3a38472dda7422831414d087af37bee1bb3119071526a55da8d09b` | compile_fail | - | 24/24 |
| `gradient` | compile_fail | - | 0/0 |
| `gradientTransform` | compile_fail | - | 0/0 |
| `hardwrap` | compile_fail | - | 1/1 |
| `hitTestStyleChange` | compile_fail | - | 1/1 |
| `hittesting/hittesting` | compile_fail | - | 18/18 |
| `hittesting/mask-hit-test` | compile_fail | - | 1/1 |
| `image-loading` | compile_fail | - | 4/4 |
| `invalidClipDepth` | compile_fail | - | 0/0 |
| `local2global` | compile_fail | - | 1/1 |
| `localconnection` | compile_fail | - | 12/12 |
| `lzma` | compile_fail | - | 5/5 |
| `lzma_bytes` | compile_fail | - | 2/2 |
| `mouse/mouse_coords` | compile_fail | - | 2/2 |
| `mouse/start_drag` | compile_fail | - | 3/3 |
| `mouse/start_drag_lock` | compile_fail | - | 3/3 |
| `movieclip` | compile_fail | - | 9/9 |
| `movieinfo1` | compile_fail | - | 3/3 |
| `slider_component` | compile_fail | - | 4/4 |
| `stream1` | compile_fail | - | 9/9 |
| `stroke1` | compile_fail | - | 1/1 |
| `stylesheet` | compile_fail | - | 3/3 |
| `targetPath1` | compile_fail | - | 8/8 |
| `timeline/Timeline3` | compile_fail | - | 5/5 |
| `timeline/Timeline4` | compile_fail | - | 5/5 |
| `timeline/Timeline8` | compile_fail | - | 5/5 |
| `timeline/Timeline9` | compile_fail | - | 11/11 |
| `timeline/events/timeline_events_fp10` | compile_fail | - | 67/67 |
| `timeline/events/timeline_events_fp9` | compile_fail | - | 48/48 |
| `timeline/nav/blendMode` | compile_fail | - | 8/8 |
| `timeline/nav/cacheAsBitmap` | compile_fail | - | 8/8 |
| `timeline/nav/colorTransform` | compile_fail | - | 8/8 |
| `timeline/nav/filters` | compile_fail | - | 8/8 |
| `timeline/nav/matrix` | compile_fail | - | 8/8 |
| `timeline/nav/morphShape` | compile_fail | - | 4/4 |
| `timeline/nav/name` | compile_fail | - | 8/8 |
| `timeline/nav/ratio` | compile_fail | - | 4/4 |
| `timeline/nav/ratio2` | compile_fail | - | 4/4 |
| `timeline/nav/ratio3` | compile_fail | - | 4/4 |
| `timeline/nav/shape` | compile_fail | - | 4/4 |
| `timeline/scene/EncodedU32` | compile_fail | - | 1/1 |
| `timeline/scene/Scene_1_MainTimeline` | compile_fail | - | 70/70 |
| `timeline/scene/Scene_2_MovieClipTimeline` | compile_fail | - | 70/70 |
| `timeline/scene/Scene_3_GotoAndStop_LabelScene` | compile_fail | - | 15/15 |
| `timeline/scene/Scene_4_GotoAndStop_FrameScene` | compile_fail | - | 15/15 |
| `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | compile_fail | - | 15/15 |
| `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | compile_fail | - | 40/40 |
| `timeline/scene/Scene_7_NextPrevScene` | compile_fail | - | 7/7 |
| `timeline/timeline_as2_1` | compile_fail | - | 3/3 |
| `timeline/timeline_as2_2` | compile_fail | - | 3/3 |
| `timeline/timeline_as2_3` | compile_fail | - | 3/3 |
| `timeline/timeline_as2_4` | compile_fail | - | 2/2 |
| `timeline/timeline_as2_5` | compile_fail | - | 4/4 |
| `timeline/timeline_loop` | compile_fail | - | 7/7 |
| `timeline/timeline_name_0` | compile_fail | - | 13/13 |

## Status Changed (22)

| Test | Previous | Current | Lines (prev) | Lines (now) |
|------|----------|---------|--------------|-------------|
| `MaskTest-3` | compile_fail | ruffle_matched | - | 3/4 |
| `acid/acid-morph` | compile_fail | output_mismatch | - | 4/6 |
| `acid/acid-shapes` | compile_fail | output_mismatch | - | 0/120 |
| `acid/acid-shapes-testing` | compile_fail | output_mismatch | - | 36/120 |
| `acid/acid-text-x` | compile_fail | ruffle_matched | - | 0/1 |
| `acid/acid-textfield` | compile_fail | ruffle_matched | - | 9/15 |
| `as3-loader/LoaderLoadBytesTest` | compile_fail | output_mismatch | - | 1/4 |
| `as3-loader/LoaderTest` | compile_fail | ruffle_matched | - | 7/9 |
| `as3-loader/LoaderTest2` | compile_fail | output_mismatch | - | 6/7 |
| `as3-loader/events/loader-events` | compile_fail | output_mismatch | - | 5/36 |
| `as3-loader/loaderinfo/loaded-content-properties` | compile_fail | output_mismatch | - | 36/48 |
| `avm1/hitarea` | compile_fail | ruffle_matched | - | 2/4 |
| `avm1movie` | compile_fail | ruffle_matched | - | 1/13 |
| `avm2/flash/geom/matrix3d/TransformBasics` | compile_fail | output_mismatch | - | 5/13 |
| `avm2/flash/geom/transform/pixelBounds` | compile_fail | ruffle_matched | - | 2/3 |
| `bitmapdata/getpixel-from-embedded` | compile_fail | output_mismatch | - | 1/2 |
| `esc` | compile_fail | output_mismatch | - | 0/2 |
| `flash_net_SharedObject` | compile_fail | ruffle_matched | - | 3/4 |
| `flash_text_TextField` | compile_fail | ruffle_matched | - | 0/0 |
| `flash_text_TextField2` | compile_fail | ruffle_matched | - | 9/18 |
| `getobjectsunderpoint` | compile_fail | ruffle_matched | - | 29/34 |
| `timeline/nav/clipDepth` | compile_fail | ruffle_matched | - | 4/8 |
