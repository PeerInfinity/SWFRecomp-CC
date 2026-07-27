# Ruffle Test Results Diff

**Previous:** `28577da2aa5c` (2026-07-27T02:18:25.435785+00:00)
**Current:** `a9900a478651` (2026-07-27T04:25:43.338962+00:00)

## Summary

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| Passing | 163 | 150 | -13 |
| Total | 229 | 229 | 0 |
| Pass rate | 71.2% | 65.5% | -5.7% |
| Mismatched lines | 881 | 881 | 0 |

## Newly Failing (13)

| Test | New Status | Lines (prev) | Lines (now) |
|------|-----------|--------------|-------------|
| `encoding1` | output_mismatch | 31/31 | 31/31 |
| `flash_events_Event` | output_mismatch | 3/3 | 3/3 |
| `hitTestStyleChange` | output_mismatch | 1/1 | 1/1 |
| `image-loading` | output_mismatch | 4/4 | 4/4 |
| `local2global` | output_mismatch | 1/1 | 1/1 |
| `lzma` | output_mismatch | 5/5 | 5/5 |
| `lzma_bytes` | output_mismatch | 2/2 | 2/2 |
| `timeline/scene/EncodedU32` | output_mismatch | 1/1 | 1/1 |
| `timeline/scene/Scene_1_MainTimeline` | output_mismatch | 70/70 | 70/70 |
| `timeline/scene/Scene_2_MovieClipTimeline` | output_mismatch | 70/70 | 70/70 |
| `timeline/scene/Scene_6_GotoAndPlay_FrameScene` | output_mismatch | 40/40 | 40/40 |
| `timeline/scene/Scene_7_NextPrevScene` | output_mismatch | 7/7 | 7/7 |
| `timeline/timeline_loop` | output_mismatch | 7/7 | 7/7 |

## Line Count Changed (20)

| Test | Status | Lines (prev) | Lines (now) | Diff |
|------|--------|--------------|-------------|------|
| `acid/acid-filter` | output_mismatch | 0/2 | 0/2 | 0 |
| `acid/acid-shapes` | output_mismatch | 0/120 | 0/120 | 0 |
| `as3-interfaces` | output_mismatch | 1/6 | 1/6 | 0 |
| `as3-loader/LoaderLoadBytesTest` | output_mismatch | 1/4 | 1/4 | 0 |
| `as3-loader/LoaderLoadBytesTest2` | output_mismatch | 2/3 | 2/3 | 0 |
| `as3-loader/LoaderTest` | output_mismatch | 5/9 | 5/9 | 0 |
| `as3-loader/LoaderTest2` | output_mismatch | 2/7 | 2/7 | 0 |
| `as3-loader/events/loader-events` | output_mismatch | 5/36 | 5/36 | 0 |
| `as3-loader/loaderinfo/loaded-content-properties` | output_mismatch | 36/48 | 36/48 | 0 |
| `avm1movie` | ruffle_matched | 4/13 | 4/13 | 0 |
| `avm2/flash/geom/matrix3d/Matrix3DClass` | output_mismatch | 0/56 | 0/56 | 0 |
| `avm2/flash/geom/matrix3d/TransformBasics` | output_mismatch | 2/13 | 2/13 | 0 |
| `avm2/flash/geom/perspectiveprojection/PerspectiveProjectionClass` | output_mismatch | 0/20 | 0/20 | 0 |
| `bitmapdata/getpixel-from-embedded` | output_mismatch | 0/2 | 0/2 | 0 |
| `esc` | output_mismatch | 0/2 | 0/2 | 0 |
| `getobjectsunderpoint` | output_mismatch | 1/34 | 1/34 | 0 |
| `hittesting/hittesting` | output_mismatch | 9/18 | 9/18 | 0 |
| `stream1` | output_mismatch | 0/9 | 0/9 | 0 |
| `stroke1` | output_mismatch | 0/1 | 0/1 | 0 |
| `timeline/nav/clipDepth` | output_mismatch | 1/8 | 1/8 | 0 |
