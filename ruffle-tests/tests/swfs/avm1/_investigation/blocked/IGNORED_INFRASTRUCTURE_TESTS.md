# Ignored Infrastructure-Dependent Tests
<!-- TESTS: file_reference_browse_cancel, file_reference_download_cancel, file_reference_download_httperror_dns_error, file_reference_download_httperror_status_code, file_reference_download_success, file_reference_upload_httperror_dns_error, file_reference_upload_httperror_status_code, file_reference_upload_success, form_loader_encoding_2, form_loader_encoding_3, form_loader_encoding_4, load_vars, netconnection_close, netconnection_send_remote, netstream_play_flv, netstream_play_flv_screen, netstream_seek_flv, sound_duration_position_props, sound_id3, sound_id3_prop, sound_load_start, sound_multiple_load, stylesheet_load -->

Last updated: 2026-03-14

## Status: IGNORED — 23 tests, all in `ignored_tests.txt`

These 23 tests are excluded from filtered results because they require runtime infrastructure unavailable in our trace-only NO_GRAPHICS mode (network I/O, audio file loading, OS file dialogs, or video streaming). They are not actionable without major infrastructure additions.

**Note (2026-03-14):** 6 BitmapData tests previously tracked here have been moved to BITMAP_DATA_PLAN (now in `incomplete/`). Most of those tests now pass (12/17 BitmapData tests passing) thanks to the software pixel buffer implementation.

---

## Group 1: FileReference (8 tests)

| Test | Expected | Match | Summary |
|------|----------|-------|---------|
| `file_reference_browse_cancel` | 21 | 10 (48%) | FileReference properties, browse() call, cancel event |
| `file_reference_download_cancel` | 7 | 1 (14%) | download() then cancel |
| `file_reference_download_httperror_dns_error` | 13 | 1 (8%) | download() with DNS failure |
| `file_reference_download_httperror_status_code` | 23 | 1 (4%) | download() with HTTP error status |
| `file_reference_download_success` | 34 | 7 (21%) | browse() + download() success flow |
| `file_reference_upload_httperror_dns_error` | 18 | 1 (6%) | upload() with DNS failure |
| `file_reference_upload_httperror_status_code` | 23 | 1 (4%) | upload() with HTTP error status |
| `file_reference_upload_success` | 23 | 1 (4%) | browse() + upload() success flow |

**Why blocked**: FileReference requires OS-level file picker dialogs (`browse()`), HTTP upload/download (`upload()`/`download()`), and async event callbacks (`onSelect`, `onCancel`, `onComplete`, `onHTTPError`). The Ruffle test harness simulates these via test infrastructure (mock file picker, mock HTTP server). We have no equivalent.

**What would be needed**: FileReference constructor + property stubs (some already work — 10/21 match on browse_cancel), plus a mock file picker and mock HTTP layer for the test harness. Very large effort with low ROI.

---

## Group 2: Sound Loading/Streaming (5 tests)

| Test | Expected | Match | Summary |
|------|----------|-------|---------|
| `sound_duration_position_props` | 290 | 2 (1%) | Sound.getDuration(), Sound.getPosition() during playback, onSoundComplete |
| `sound_id3` | 633 | 11 (2%) | Sound.loadSound() + ID3 tag reading (artist, album, title, etc.) |
| `sound_id3_prop` | 138 | 1 (1%) | Sound.id3 property access patterns during async load |
| `sound_load_start` | 3 | 0 (0%) | Sound.loadSound() + onLoad callback |
| `sound_multiple_load` | 1 | 0 (0%) | Multiple Sound.loadSound() calls, onLoad ordering |

**Why blocked**: These tests call `Sound.loadSound()` to load external MP3 files and then read duration/position/ID3 properties during playback. Requires audio file parsing (MP3 headers, ID3 tags) and async load event dispatch. Our Sound object has basic constructor/method stubs but no actual audio loading.

**What would be needed**: MP3 header parsing (for duration), ID3v1/v2 tag parsing, async load simulation with onLoad/onID3/onSoundComplete callbacks. Medium-to-large effort.

---

## Group 3: NetConnection/NetStream Video (5 tests)

| Test | Expected | Match | Summary |
|------|----------|-------|---------|
| `netconnection_close` | 39 | 3 (8%) | NetConnection.connect(null)/close(), isConnected property, onStatus events |
| `netconnection_send_remote` | 50 | 1 (2%) | NetConnection.send() to remote AMF endpoint, onResult/onStatus |
| `netstream_play_flv` | 21 | 1 (5%) | NetStream.play() with local FLV, onStatus/onMetaData events |
| `netstream_play_flv_screen` | 1 | 0 (segfault) | NetStream FLV playback (image comparison, 0 trace lines) |
| `netstream_seek_flv` | 25 | 0 (0%) | NetStream.seek() during FLV playback, onStatus events |

**Why blocked**: NetConnection/NetStream require network socket handling (AMF protocol for send_remote), FLV container parsing (for play/seek), and video codec support. These are deep multimedia infrastructure features.

**What would be needed**: NetConnection stub with connect/close/isConnected (partially present), FLV demuxer, AMF serialization. Very large effort.

---

## Group 4: Network/Form Loading (5 tests)

| Test | Expected | Match | Summary |
|------|----------|-------|---------|
| `form_loader_encoding_2` | 3 | 0 (0%) | HTTP form POST with ISO-8859-1 encoding, response text decoding |
| `form_loader_encoding_3` | 3 | 1 (33%) | HTTP form POST with Shift_JIS encoding |
| `form_loader_encoding_4` | 3 | 1 (33%) | HTTP form POST with mixed encodings |
| `load_vars` | 35 | 13 (37%) | LoadVars.load() / LoadVars.send() — HTTP GET/POST with URL-encoded variables |
| `stylesheet_load` | 49 | 1 (2%) | TextField.StyleSheet.load() — HTTP load of CSS stylesheet, onLoad callback |

**Why blocked**: These require HTTP request/response infrastructure. The Ruffle test harness includes a built-in HTTP mock server. Our test harness has no network layer.

**What would be needed**: HTTP mock in test harness (or hardcoded responses), LoadVars URL encoding/decoding, StyleSheet CSS parsing with async load. The `load_vars` test partially matches (13/35) because LoadVars constructor/property access works — only the actual HTTP load calls fail.
