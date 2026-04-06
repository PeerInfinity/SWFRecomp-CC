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
    name: "Video codec (Screen Video or Sorenson H.263)"
    status: not_started
  - id: 6
    name: "Video rendering"
    status: not_started
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
  - blocker: 7
    reason: "netstream_play_flv_screen requires video codec + rendering"
-->

Last updated: 2026-04-06

## Status: INCOMPLETE — 2/3 trace tests PASS, 1 image test blocked on video decoding

### Test Summary

| Test | Lines | Current | Status | Notes |
|------|-------|---------|--------|-------|
| netstream_play_flv | 21 | 21/21 (100%) | **PASS** | FLV play + onStatus events |
| netstream_seek_flv | 25 | 25/25 (100%) | **PASS** | FLV seek + pause + onStatus events |
| netstream_play_flv_screen | 0 | segfault | blocked | Image comparison only — needs video decoder |

### Completed Work (2026-04-06)

#### Phase 1: FLV Container Demuxer
- `flv_parse_duration()` in `action.c` — parses FLV header (9 bytes), locates script data tag (type 18/0x12), decodes AMF ECMA array to extract `duration`, `width`, `height`, `framerate`
- Handles AMF types: Number (0x00), Boolean (0x01), String (0x02)
- Big-endian double conversion for metadata values

#### Phase 2: NetStream onStatus Dispatch
- `ns_dispatch_onStatus()` — reuses NetConnection's dispatch pattern
- Creates event object with `code`/`level` properties + Object.prototype (`setObjectProto`) for `hasOwnProperty` support
- Handles both type-1 (DefineFunction) and type-2 (DefineFunction2) handlers
- Type-1 path pushes local scope for parameter binding via `setVariableByName`

#### Phase 3: NetStream State Machine
- `ActiveNetStream` struct with `MAX_ACTIVE_NETSTREAMS=8` global array
- `builtin_ns_play()` — loads FLV from data registry, parses duration, marks `pending_start`
- `builtin_ns_seek()` — fires `NetStream.Seek.Notify` synchronously
- `builtin_ns_pause()` — returns undefined (Flash behavior)
- `processNetStreams()` — per-tick event dispatch:
  - Tick after play(): fires `Play.Start`, `Buffer.Full`, dispatches `onMetaData`
  - Subsequent ticks: accumulates `elapsed_ms`
  - When `elapsed_ms >= duration`: fires `Buffer.Flush`, `Play.Stop`, `Buffer.Empty`
- `hasActiveNetStreams()` — frame loop exit condition (added to both early-exit check and past-end-of-frames check)

#### Phase 4: onMetaData Dispatch
- `ns_dispatch_onMetaData()` — creates ASObject with duration/width/height/framerate properties
- Dispatched from `processNetStreams` on the first tick after play (same tick as Buffer.Full)

#### Frame Loop Integration
- `processNetStreams(app_context, frame_duration_ms)` called from `swf_core.c` after `processSoundPlayback`
- Two exit condition sites updated to check `hasActiveNetStreams()`:
  1. The main quit_swf early-exit check (line ~813)
  2. The past-end-of-frames continue/break block (line ~1069)

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| ActiveNetStream struct + FLV parser | `action.c` | ~1974-2070 |
| ns_dispatch_onStatus | `action.c` | ~2074-2162 |
| ns_dispatch_onMetaData | `action.c` | ~2164-2262 |
| builtin_ns_play/seek/pause | `action.c` | ~2266-2350 |
| processNetStreams + hasActiveNetStreams | `action.c` | ~2364-2420 |
| initNetStreamPrototype (real methods) | `action.c` | ~25905-25945 |
| Frame loop integration | `swf_core.c` | ~1030, ~1078 |
| Frame loop exit conditions | `swf_core.c` | ~813, ~1077 |

### Remaining Work (Phase 5-6)

**netstream_play_flv_screen** requires full video decoding and rendering:

1. **FLV video tag parsing** — decode video tags (type 9), detect codec ID
2. **Video codec** — decode video frames:
   - Screen Video (codec 3): block-based, ~200 lines
   - Sorenson H.263 (codec 2): DCT-based, ~500+ lines
3. **Video rendering** — display decoded frames as GPU textures (similar to BitmapData)

Estimated: 800-1500 lines depending on codec complexity. Not worthwhile now since it only affects 1 image-only test.

### Dependencies (all satisfied)

- **NETCONNECTION_PLAN Phase 2**: onStatus dispatch helper — pattern reused
- **SOUND_LOADING_PLAN Phase 1**: Data file embedding via `findDataFile()` — working
- **BitmapData rendering**: Only needed for Phase 6 (video frame display)
