# Sound ID3 Tag Parsing Plan
<!-- TESTS: sound_id3, sound_id3_prop -->

<!-- PLAN_META
id: SOUND_ID3
status: complete
phases:
  - id: 1
    name: "ID3v2 parser"
    status: complete
  - id: 2
    name: "ID3 object construction"
    status: complete
  - id: 3
    name: "onID3 callback dispatch"
    status: complete
  - id: 4
    name: "Integration with loadSound"
    status: complete
  - id: 5
    name: "id3 property getter + Place pattern"
    status: complete
dependencies:
  - plan: SOUND_LOADING
    phases: [1]
    type: requires
    reason: "loadSound implementation needed for ID3 parsing"
blockers: []
-->

Last updated: 2026-04-07

## Status: COMPLETE

### Test Results

| Test | Lines | Result | Status |
|------|-------|--------|--------|
| sound_id3 | 633 | 633/633 (100%) | PASS |
| sound_id3_prop | 138 | 138/138 (100%) | PASS |

### Implementation Summary

All phases implemented in a single session (2026-04-07):

1. **ID3v2 parser** (`parseID3v2Tags` in action.c): Parses ID3v2.3 frame headers, handles Latin1 (encoding 0), UTF-16 with BOM (encoding 1), and UTF-8 (encoding 3). Special handling for COMM frames (language + short description + text). Skips URL frames (WOAR etc.).

2. **ID3 object construction**: Creates ASObject with text frame properties (TCON, TYER, etc.) and friendly-name aliases (genre, year, songname, artist, album, track). COMM frames collected into ASArray. Properties added in file order with aliases before frame codes, matching Flash/Ruffle LIFO for-in enumeration (last-added = first-iterated).

3. **valueOf override**: Static `g_id3_valueof_func` returns UNDEFINED, making `id3 == undefined` true, `typeof id3 = "object"`, and `trace(id3) = "undefined"` — matching Flash's ID3 object behavior.

4. **onID3 callback**: Fires only when ID3v2 tags are found (not for noid3.mp3). Both onID3 and onLoad now receive `success=true` as first argument. `soundFireCallback` updated to accept args.

5. **id3 property getter**: Added to Sound native property section. Returns `__id3__` internal object when available. Supports Place 0 pattern (pre-loadSound string override via `__id3_override__`).

### Key Code Locations

| Component | File | Function/Section |
|-----------|------|-----------------|
| ID3v2 parser | action.c | `parseID3v2Tags()` |
| Text decoder | action.c | `id3_decode_text()`, `id3_decode_comm()` |
| valueOf func | action.c | `builtin_id3_valueOf()` |
| loadSound integration | action.c | `builtin_sound_loadSound()` |
| id3 getter | action.c | Sound native property section (NATIVE_SOUND) |
| Callback dispatcher | action.c | `soundFireCallback()` (updated with args) |
