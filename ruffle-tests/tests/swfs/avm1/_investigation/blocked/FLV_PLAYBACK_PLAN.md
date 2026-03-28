# FLV Playback Plan
<!-- TESTS: netstream_play_flv, netstream_seek_flv, netstream_play_flv_screen -->

Last updated: 2026-03-27

## Status: BLOCKED — Needs FLV demuxer + video codec + NetStream event infrastructure

### Test Summary

| Test | Lines | Current | Status | Notes |
|------|-------|---------|--------|-------|
| netstream_play_flv | 21 | 1/21 (5%) | ignored | FLV play + onStatus events |
| netstream_seek_flv | 25 | 0/25 (0%) | ignored | FLV seek + pause + onStatus events |
| netstream_play_flv_screen | 0 | segfault | ignored | Image comparison only (0 trace lines) |

### Expected Output

**netstream_play_flv** (21 lines, 60 ticks, `with_renderer`, `with_video`):
```
// nc.isConnected:false
// nc.isConnected:true
onStatus update
level: status
code: NetStream.Play.Start

onStatus update
level: status
code: NetStream.Buffer.Full

onStatus update
level: status
code: NetStream.Buffer.Flush

onStatus update
level: status
code: NetStream.Play.Stop

onStatus update
level: status
code: NetStream.Buffer.Empty
```

The test creates a NetConnection, connects(null), creates a NetStream, calls
`ns.play("test_video.flv")`, and expects 5 status events across 60 frames as the
video plays to completion.

**netstream_seek_flv** (25 lines, 60 ticks, `with_renderer`, `with_video`):
```
onStatus: NetStream.Play.Start
onStatus: NetStream.Buffer.Full
netStatusOnMetaData
//ns.seek(0.5);
onStatus: NetStream.Seek.Notify
//ns.seek(1.5);
onStatus: NetStream.Seek.Notify
//ns.pause();
undefined
//ns.seek(0.5);
onStatus: NetStream.Seek.Notify
```

Tests seek during playback and after pause.

**netstream_play_flv_screen** (0 trace lines, 60 ticks):
Image comparison only. Tests that decoded video frames render correctly.

### What Would Be Needed

#### 1. FLV Container Demuxer (~300 lines)

FLV format:
- Header: 9 bytes (signature "FLV", version, flags, header size)
- Tags: each tag has type (audio=8, video=9, script=18), size, timestamp, data
- Script data tag contains onMetaData (AMF-encoded key-value pairs: duration, width,
  height, framerate, etc.)
- Video tags contain codec-specific data (Sorenson H.263, VP6, H.264, Screen Video)
- Audio tags contain codec-specific data (MP3, AAC, etc.)

The test FLV (`test_video.flv`, 15K) is likely a short video with Screen Video or
Sorenson codec.

#### 2. Video Codec (~500+ lines)

Depending on the test FLV's codec:
- **Screen Video** (codec 3): Simple block-based codec, relatively easy to implement
- **Sorenson H.263** (codec 2): Moderate complexity, DCT-based
- **VP6** (codec 4/5): Complex, would need a VP6 decoder library
- **H.264** (codec 7): Very complex, would need libavcodec or similar

The `test_video.flv` name and the `_screen` variant suggest Screen Video codec, which
is the simplest option (~200 lines for a basic decoder).

#### 3. NetStream State Machine (~100 lines)

Implement play/pause/seek/close with state tracking:
- `play(url)`: Start FLV demuxing, fire `NetStream.Play.Start`
- Buffer management: fire `Buffer.Full` when buffer has enough data
- Frame advance: decode video frames, advance playback position
- `seek(time)`: Jump to keyframe, fire `NetStream.Seek.Notify`
- `pause()`: Pause playback (returns undefined in Flash)
- End of stream: fire `Buffer.Flush`, `Play.Stop`, `Buffer.Empty`

#### 4. onStatus Dispatch (~30 lines)

Same pattern as NetConnection (see NETCONNECTION_PLAN.md Phase 2):
- Look up `onStatus` on the NetStream instance
- Create event object with `code` and `level`
- Call handler with event argument

#### 5. onMetaData Dispatch (~20 lines)

When the script data tag is parsed:
- Create ASObject with metadata properties (duration, width, height, etc.)
- Look up `onMetaData` on the NetStream client object
- Call with metadata argument

#### 6. Video Rendering (for netstream_play_flv_screen) (~200 lines)

Display decoded video frames:
- Decode frame to RGBA pixel buffer
- Upload to GPU texture (similar to BitmapData rendering)
- Render as textured quad at the Video display object's position

### Why Blocked

Multiple heavy infrastructure components needed:
1. **FLV demuxer**: Binary container format parser (~300 lines)
2. **Video codec**: At minimum Screen Video decoder (~200 lines), potentially more
3. **AMF parser**: For onMetaData script data tag (could be minimal subset)
4. **Playback state machine**: Frame-based advancement, buffering simulation
5. **verify_output.py changes**: Handle `with_renderer` and `with_video` test.toml flags
6. **Data file loading**: FLV files need to be accessible to NetStream.play()

Total estimated: ~800-1500 lines depending on video codec complexity.

### Partial Approach (onStatus Events Only)

A lighter-weight approach could pass `netstream_play_flv` without actual video decoding:

1. Implement `NetStream.play(url)` to load the FLV header + script tag only
2. Parse FLV duration from onMetaData
3. Fire status events at appropriate frame intervals:
   - Frame 1: `Play.Start`
   - Frame 2: `Buffer.Full`
   - Near end: `Buffer.Flush`, `Play.Stop`, `Buffer.Empty`
4. Skip actual video frame decoding

This would pass the trace test (21 lines) but NOT the image comparison test.
Estimated: ~200 lines (FLV header/script parsing + state machine).

### Key Code Locations

| Component | File | Lines |
|-----------|------|-------|
| NetStream prototype | `action.c` | 23278-23312 |
| NetStream constructor | `action.c` | 38559 (returns undefined) |
| play/seek/pause stubs | `action.c` | 23285-23295 |
| Test FLV file | `ruffle-tests/tests/swfs/avm1/netstream_play_flv/` | test_video.flv (15K) |
| Test audio file | Same directory | noise.mp3 (8.3K) |

### Dependencies

- NETCONNECTION_PLAN.md Phase 2 (onStatus dispatch helper — shared infrastructure)
- SOUND_LOADING_PLAN.md Phase 1 (data file embedding — shared pattern)
- BitmapData rendering infrastructure (for video frame display — netstream_play_flv_screen only)

### Estimated Complexity

- **Trace-only (partial, onStatus events)**: Medium (~200 lines) — passes netstream_play_flv
- **Full video playback**: Very high (~800-1500 lines) — passes all 3 tests
- **Seek support**: Additional ~100 lines on top of either approach
