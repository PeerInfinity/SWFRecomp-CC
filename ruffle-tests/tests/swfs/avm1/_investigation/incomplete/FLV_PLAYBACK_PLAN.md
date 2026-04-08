# FLV Playback Plan
<!-- TESTS: netstream_play_flv, netstream_seek_flv, netstream_play_flv_screen -->

<!-- PLAN_META
id: FLV_PLAYBACK
status: incomplete
phases:
  - id: 1
    name: "FLV container demuxer (header + script tag)"
    status: complete
  - id: 2
    name: "NetStream onStatus event dispatch"
    status: complete
  - id: 3
    name: "NetStream state machine (play/seek/pause)"
    status: complete
  - id: 4
    name: "onMetaData dispatch"
    status: complete
  - id: 5
    name: "FLVPlayback component crash fix"
    status: complete
  - id: 6
    name: "ScreenVideo decoder + frame delivery"
    status: complete
  - id: 7
    name: "Video display object rendering infrastructure"
    status: complete
  - id: 8
    name: "Video rendering (headless only)"
    status: blocked
dependencies:
  - plan: NETCONNECTION
    phases: [2]
    type: requires
    reason: "onStatus dispatch infrastructure"
  - plan: SOUND_LOADING
    phases: [1]
    type: requires
    reason: "Data file embedding pattern"
blockers:
  - "FLVPlayback component parameter ordering: clip action variables set BEFORE registerClass constructor, so contentPath setter fires when VideoPlayer is undefined"
-->

Last updated: 2026-04-07

## Status: INCOMPLETE — All 3 trace tests PASS, image rendering blocked by FLVPlayback component

### Test Summary

| Test | Lines | Current | Status | Notes |
|------|-------|---------|--------|-------|
| netstream_play_flv | 21 | 21/21 (100%) | **PASS** | FLV play + onStatus events |
| netstream_seek_flv | 25 | 25/25 (100%) | **PASS** | FLV seek + pause + onStatus events |
| netstream_play_flv_screen | 0 | 0/0 (100%) | **PASS** | Trace pass; image comparison needs headless rendering |

### Completed Work

#### Phase 1: FLV Container Demuxer (2026-04-06)
- `flv_parse_duration()` in `action.c` — parses FLV header (9 bytes), locates script data tag (type 18/0x12), decodes AMF ECMA array to extract `duration`, `width`, `height`, `framerate`
- Handles AMF types: Number (0x00), Boolean (0x01), String (0x02)
- Big-endian double conversion for metadata values

#### Phase 2: NetStream onStatus Dispatch (2026-04-06)
- `ns_dispatch_onStatus()` — reuses NetConnection's dispatch pattern
- Creates event object with `code`/`level` properties + Object.prototype (`setObjectProto`) for `hasOwnProperty` support
- Handles both type-1 (DefineFunction) and type-2 (DefineFunction2) handlers
- Type-1 path pushes local scope for parameter binding via `setVariableByName`

#### Phase 3: NetStream State Machine (2026-04-06)
- `ActiveNetStream` struct with `MAX_ACTIVE_NETSTREAMS=8` global array
- `builtin_ns_play()` — loads FLV from data registry, parses duration, marks `pending_start`
- `builtin_ns_seek()` — fires `NetStream.Seek.Notify` synchronously
- `builtin_ns_pause()` — returns undefined (Flash behavior)
- `processNetStreams()` — per-tick event dispatch:
  - Tick after play(): fires `Play.Start`, `Buffer.Full`, dispatches `onMetaData`
  - Subsequent ticks: accumulates `elapsed_ms`
  - When `elapsed_ms >= duration`: fires `Buffer.Flush`, `Play.Stop`, `Buffer.Empty`
- `hasActiveNetStreams()` — frame loop exit condition (added to both early-exit check and past-end-of-frames check)

#### Phase 4: onMetaData Dispatch (2026-04-06)
- `ns_dispatch_onMetaData()` — creates ASObject with duration/width/height/framerate properties
- Dispatched from `processNetStreams` on the first tick after play (same tick as Buffer.Full)

#### Phase 5: FLVPlayback Component Crash Fix (2026-04-06)

The `netstream_play_flv_screen` test uses Adobe's FLVPlayback component (`mx.video.*`), a ~93K-line AS2 class hierarchy. It crashed during initialization:

```
#0 getProperty(obj=CORRUPT, "__proto__") → SIGSEGV
#1 isTextFieldInstance(obj=CORRUPT)
#2 actionSetMember()
#7 func2_anonymous_0() — FLVPlayback constructor
#8 actionInvokeRegisteredClassConstructor("FLVPlayback")
```

Root cause: `createVideoPlayer` called with `this_obj=NULL`, leading to corrupt pointer dereference (float data misinterpreted as ASObject: `num_used=0x42C80000`, `properties=0x42c8000000000000`).

Fix: Safety checks in `object.c` — `getProperty`, `getPropertyWithPrototype`, `findPropertyRaw`, `setProperty` reject corrupt objects (`num_used > 16384` or invalid property name pointers `< 4096`).

#### Phase 6: ScreenVideo Decoder + Frame Delivery (2026-04-06)

`screenvideo_decode_frame()` in action.c (~80 lines):
- Parses ScreenVideo header (block dimensions, image dimensions)
- Iterates blocks in row-major bottom-to-top order
- Each block: reads 2-byte data size, then zlib-decompresses BGR pixel data
- Converts BGR bottom-to-top → RGBA top-to-bottom in output buffer

`flv_decode_first_frame()` in action.c (~30 lines):
- Scans FLV tags for first video tag (type 9)
- Checks codec ID (only ScreenVideo/codec 3 supported)
- Calls screenvideo_decode_frame for keyframes

`g_video_frames[MAX_VIDEO_FRAMES]` global frame storage:
- Links decoded RGBA pixels to the source NetStream object
- `ns_store_decoded_frame()` stores/replaces frames per-NetStream
- Called from `builtin_ns_play()` after FLV parsing
- Added `-lz` to verify_output.py link flags for zlib

#### Frame Loop Integration
- `processNetStreams(app_context, frame_duration_ms)` called from `swf_core.c` after `processSoundPlayback`
- Two exit condition sites updated to check `hasActiveNetStreams()`:
  1. The main quit_swf early-exit check
  2. The past-end-of-frames continue/break block

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| ActiveNetStream struct + FLV parser | `action.c` | ~1974-2070 |
| ScreenVideo decoder | `action.c` | ~2073-2170 |
| actionGetVideoFramePixels | `action.c` | ~2968-2997 |
| ns_dispatch_onStatus | `action.c` | ~2230-2320 |
| ns_dispatch_onMetaData | `action.c` | ~2320-2420 |
| builtin_ns_play/seek/pause | `action.c` | ~2420-2500 |
| processNetStreams + hasActiveNetStreams | `action.c` | ~2520-2580 |
| initNetStreamPrototype (real methods) | `action.c` | ~26060-26100 |
| Corrupt object safety checks | `object.c` | getProperty, findPropertyRaw, setProperty |
| Frame loop integration | `swf_core.c` | ~1030, ~1078, ~813, ~1077 |
| ng_isVideoChar | `tag_stubs.c` | after ng_record_video |
| Video rendering (render_single_object) | `tag.c` | ~1126-1141 |
| Video rendering (render_display_list) | `tag.c` | ~1180-1192 |

### Completed Work (2026-04-07)

#### Phase 7: Video display object rendering infrastructure
- `ng_isVideoChar(char_id)` — public function in tag_stubs.c, declared in tag.h
- `actionGetVideoFramePixels(out_argb, out_w, out_h)` — converts RGBA u8 → ARGB u32 for renderer
- `render_single_object` and `render_display_list` in tag.c — check `ng_isVideoChar` BEFORE the switch (video char_ids have type=0=CHAR_TYPE_SHAPE in dictionary since tagDefineVideoStream doesn't set a type)
- Calls `renderer_draw_bitmap_quad()` with decoded frame, using display object's transform_id/cxform_id
- Guarded by `#ifdef HEADLESS_GRAPHICS` — only active in headless image rendering mode
- Verified: `ng_isVideoChar(4)` correctly finds the video char_id in the display list

#### Phase 8: Video rendering — BLOCKED
The rendering infrastructure is complete but cannot be tested end-to-end because:

**Blocker: Component parameter execution ordering**

Two `this` type mismatch bugs have been fixed:
1. `actionSetVariable` non-root MC path — now invokes addProperty setters via `g_event_this_mc` (previous commit)
2. `actionSetMember` MOVIECLIP type-2 setter — was passing `(void*)mc` as `this_obj` (stored as OBJECT type), now uses `g_event_this_mc` pattern (this commit)

With both fixes, the `__set__contentPath` setter fires correctly with MOVIECLIP-type `this`. However, tracing shows component parameters (autoPlay, contentPath, etc.) are set BEFORE the constructor's `createVideoPlayer` call. The `contentPath` setter checks `_vp[_activeVP] != undefined` and bails because VideoPlayer doesn't exist yet.

**Next step**: Fix clip action variable ordering — parameters should be set AFTER the registerClass constructor finishes, not before. See `FLVPLAYBACK_COMPONENT_INVESTIGATION.md` for full trace analysis.

### ScreenVideo Format Reference

```
FLV Video Tag (type 9):
  byte 0: [frameType:4][codecID:4]
    frameType: 1=keyframe, 2=inter
    codecID: 3=ScreenVideo

ScreenVideo Header (bytes 1-4):
  [blockWidth:4][imageWidth:12][blockHeight:4][imageHeight:12]
  blockWidth = (nibble + 1) * 16
  blockHeight = (nibble + 1) * 16

Block Data (row-major, bottom-to-top):
  For each block in grid (cols × rows):
    [dataSize:16] — 0 means skip (unchanged from previous frame)
    if dataSize > 0: zlib-compressed BGR pixel data (row-major, bottom-to-top within block)
```

For rufflelogo.flv: 128×128, blocks 16×16, grid 8×8 = 64 blocks, single keyframe.

### FLVPlayback Component Architecture (netstream_play_flv_screen)

The test uses Adobe's full FLVPlayback component, not raw NetStream:

| Component | Script | Lines | Purpose |
|-----------|--------|-------|---------|
| FLVPlayback | script_2 | 2744 | Main component + VideoPlayer |
| NCManager | script_3 | 1767 | NetConnection management |
| VideoPlayer | script_7 | 1091 | NetStream + Video management |
| UIManager | script_8 | 204 | UI controls |
| Others | scripts 4-14 | ~2000 | EventDispatcher, Delegate, etc. |
| Total | script_defs.c | 93029 | All function definitions |

### Dependencies (all satisfied)

- **NETCONNECTION_PLAN Phase 2**: onStatus dispatch helper — pattern reused
- **SOUND_LOADING_PLAN Phase 1**: Data file embedding via `findDataFile()` — working
- **BitmapData rendering**: Only needed for Phase 8 (video frame display)
