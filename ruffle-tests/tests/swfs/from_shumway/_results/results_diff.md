# Ruffle Test Results Diff

**Previous:** `38e495669a30` (2026-07-23T18:38:00.303892+00:00)
**Current:** `f0e6fb25d672` (2026-07-24T19:31:35.378126+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 73 | 159 | +86 |
| Total | 92 | 229 | +137 |
| Pass rate | 79.3% | 69.4% | -9.9% |
| Mismatched lines | 394 | 943 | +549 |

## Added Tests (137)

| Test | Status | Lines |
|------|--------|-------|
| `3_joystick` | pass | 4/4 |
| `MaskTest` | pass | 0/0 |
| `MaskTest-2` | pass | 0/0 |
| `MaskTest-3` | ruffle_matched | 3/4 |
| `ZeroClipboardTest` | pass | 3/3 |
| `acid/acid` | pass | 1/1 |
| `acid/acid-big` | pass | 0/0 |
| `acid/acid-bitmap-draw_quality_high` | pass | 0/0 |
| `acid/acid-bitmap-draw_quality_low` | pass | 0/0 |
| `acid/acid-bitmap-fill` | pass | 0/0 |
| `acid/acid-bitmap-fill-2` | pass | 0/0 |
| `acid/acid-bitmapData-copyPixels` | pass | 0/0 |
| `acid/acid-bitmapData-draw` | pass | 0/0 |
| `acid/acid-bitmaps` | pass | 0/0 |
| `acid/acid-blend` | pass | 0/0 |
| `acid/acid-blend-2` | pass | 0/0 |
| `acid/acid-chars` | pass | 0/0 |
| `acid/acid-child` | pass | 0/0 |
| `acid/acid-clip` | pass | 0/0 |
| `acid/acid-clip-2` | pass | 0/0 |
| `acid/acid-clip-3` | pass | 0/0 |
| `acid/acid-color` | pass | 0/0 |
| `acid/acid-color-0` | pass | 0/0 |
| `acid/acid-color-2` | pass | 0/0 |
| `acid/acid-filter` | output_mismatch | 0/2 |
| `acid/acid-filter-2` | pass | 0/0 |
| `acid/acid-gc` | pass | 0/0 |
| `acid/acid-gradient` | pass | 0/0 |
| `acid/acid-gradient-0` | pass | 0/0 |
| `acid/acid-gradient-1` | pass | 0/0 |
| `acid/acid-gradient-2` | pass | 0/0 |
| `acid/acid-image` | pass | 0/0 |
| `acid/acid-large` | pass | 0/0 |
| `acid/acid-mask` | pass | 0/0 |
| `acid/acid-morph` | output_mismatch | 4/6 |
| `acid/acid-scale` | pass | 0/0 |
| `acid/acid-shapes` | output_mismatch | 0/120 |
| `acid/acid-shapes-testing` | output_mismatch | 36/120 |
| `acid/acid-small` | pass | 0/0 |
| `acid/acid-stroke-0` | pass | 0/0 |
| `acid/acid-text` | pass | 0/0 |
| `acid/acid-text-2` | output_mismatch | 0/1 |
| `acid/acid-text-3` | pass | 0/0 |
| `acid/acid-text-4` | pass | 0/0 |
| `acid/acid-text-5` | pass | 0/0 |
| `acid/acid-text-6` | pass | 0/0 |
| `acid/acid-text-escape` | pass | 0/0 |
| `acid/acid-text-x` | ruffle_matched | 0/1 |
| `acid/acid-textfield` | ruffle_matched | 9/15 |
| `acid/acid-textfield-scroll` | pass | 5/5 |
| `acid/acid-video` | pass | 0/0 |
| `as3-interfaces` | output_mismatch | 1/6 |
| `as3-loader/LoaderLoadBytesTest` | output_mismatch | 0/4 |
| `as3-loader/LoaderLoadBytesTest2` | output_mismatch | 0/3 |
| `as3-loader/LoaderTest` | output_mismatch | 1/9 |
| `as3-loader/LoaderTest2` | output_mismatch | 1/7 |
| `as3-loader/bug1093712/loader` | output_mismatch | 0/1 |
| `as3-loader/bug1157243/empty` | output_mismatch | 0/1 |
| `as3-loader/bug1157243/invalid` | output_mismatch | 0/1 |
| `as3-loader/events/loader-events` | output_mismatch | 4/36 |
| `as3-loader/loaderinfo/Preloader` | pass | 1/1 |
| `as3-loader/loaderinfo/loaded-content-properties` | output_mismatch | 3/48 |
| `avm1movie` | output_mismatch | 0/13 |
| `avm2/event-dispatching` | pass | 5/5 |
| `avm2/flash/display/bitmapdata/bitmapdata-clone` | pass | 0/0 |
| `avm2/flash/geom/matrix3d/Matrix3DClass` | output_mismatch | 0/56 |
| `avm2/flash/geom/matrix3d/TransformBasics` | output_mismatch | 2/13 |
| `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | output_mismatch | 0/20 |
| `avm2/flash/geom/transform/pixelBounds` | ruffle_matched | 2/3 |
| `bitmapbuttons` | pass | 0/0 |
| `bitmapdata/draw-and-read` | pass | 1/1 |
| `bitmapdata/getpixel-from-embedded` | output_mismatch | 0/2 |
| `blendmode/blendmode_1` | output_mismatch | 1/2 |
| `blendmode/blendmode_2` | output_mismatch | 2/4 |
| `blendmode/blendmode_3` | pass | 2/2 |
| `button1` | pass | 1/1 |
| `button2` | pass | 1/1 |
| `captions` | pass | 8/8 |
| `clipping` | pass | 0/0 |
| `encoding1` | pass | 31/31 |
| `esc` | output_mismatch | 0/2 |
| `flash_events_Event` | pass | 3/3 |
| `flash_geom_ColorTransform` | pass | 0/0 |
| `flash_net_SharedObject` | ruffle_matched | 3/4 |
| `flash_net_URLLoader` | output_mismatch | 0/7 |
| `flash_net_URLRequest` | output_mismatch | 0/6 |
| `flash_net_classes` | ruffle_matched | 18/22 |
| `flash_text_TextField` | ruffle_matched | 0/0 |
| `flash_text_TextField2` | ruffle_matched | 9/18 |
| `flash_utils_Timer` | pass | 2/2 |
| `getobjectsunderpoint` | output_mismatch | 1/34 |
| `gradient` | pass | 0/0 |
| `hardwrap` | pass | 1/1 |
| `hitTestStyleChange` | pass | 1/1 |
| `hittesting/hittesting` | output_mismatch | 9/18 |
| `hittesting/mask-hit-test` | ruffle_matched | 0/1 |
| `image-loading` | output_mismatch | 0/4 |
| `local2global` | pass | 1/1 |
| `localconnection` | output_mismatch | 0/12 |
| `lzma` | pass | 5/5 |
| `lzma_bytes` | output_mismatch | 0/2 |
| `mouse/mouse_coords` | pass | 2/2 |
| `mouse/start_drag` | pass | 3/3 |
| `mouse/start_drag_lock` | output_mismatch | 2/3 |
| `movieclip` | pass | 9/9 |
| `slider_component` | pass | 4/4 |
| `stream1` | output_mismatch | 0/9 |
| `stroke1` | output_mismatch | 0/1 |
| `stylesheet` | pass | 3/3 |
| `timeline/Timeline3` | pass | 5/5 |
| `timeline/Timeline4` | pass | 5/5 |
| `timeline/Timeline8` | pass | 5/5 |
| `timeline/Timeline9` | pass | 11/11 |
| `timeline/events/timeline_events_fp10` | pass | 67/67 |
| `timeline/events/timeline_events_fp9` | pass | 48/48 |
| `timeline/nav/blendMode` | output_mismatch | 6/8 |
| `timeline/nav/cacheAsBitmap` | output_mismatch | 6/8 |
| `timeline/nav/clipDepth` | output_mismatch | 1/8 |
| `timeline/nav/colorTransform` | output_mismatch | 6/8 |
| `timeline/nav/filters` | output_mismatch | 6/8 |
| `timeline/nav/matrix` | output_mismatch | 7/8 |
| `timeline/nav/morphShape` | output_mismatch | 3/4 |
| `timeline/nav/name` | pass | 8/8 |
| `timeline/nav/ratio` | output_mismatch | 3/4 |
| `timeline/nav/ratio2` | output_mismatch | 3/4 |
| `timeline/nav/ratio3` | pass | 4/4 |
| `timeline/nav/shape` | pass | 4/4 |
| `timeline/scene/EncodedU32` | pass | 1/1 |
| `timeline/scene/Scene_1_MainTimeline` | pass | 70/70 |
| `timeline/scene/Scene_2_MovieClipTimeline` | pass | 70/70 |
| `timeline/scene/Scene_3_GotoAndStop_LabelScene` | pass | 15/15 |
| `timeline/scene/Scene_4_GotoAndStop_FrameScene` | pass | 15/15 |
| `timeline/scene/Scene_5_GotoAndPlay_LabelScene` | pass | 15/15 |
| `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | pass | 40/40 |
| `timeline/scene/Scene_7_NextPrevScene` | pass | 7/7 |
| `timeline/timeline_loop` | pass | 7/7 |
| `timeline/timeline_name_0` | pass | 13/13 |
